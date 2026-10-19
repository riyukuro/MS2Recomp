// Hook runtime: registry of MS2_REPLACE entries, validation, installation via Microsoft Detours, call counting,
// ms2hook.log. See ms2hook.h and NOTES.md "Recompiled source layout & hook DLL".
#include <string>
#include "hook_runtime.h"

#include "ms2hook.h"

#include <windows.h>

#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

#include "detours/detours.h"

namespace ms2 {
uintptr_t g_imageDelta = 0;
}

namespace ms2::hook {
namespace {

// Identity of the exe the code was recovered from: Game Versions/KMS2_DEV/x64/MapleStory2.exe (2022-04-13).
constexpr DWORD kExpectedTimeDateStamp = 0x62568c46;
constexpr DWORD kExpectedSizeOfImage = 0x4456000;

Replacement* g_head = nullptr;  // constant-initialized: safe to use from any dynamic initializer
HANDLE g_log = INVALID_HANDLE_VALUE;
CRITICAL_SECTION g_logLock;
ULONGLONG g_t0 = 0;
std::vector<Replacement*> g_installed;

uint32_t Fnv1a(const uint8_t* p, size_t n) {
    uint32_t h = 0x811c9dc5u;
    for (size_t i = 0; i < n; ++i) {
        h ^= p[i];
        h *= 0x01000193u;
    }
    return h;
}

bool EnvFlag(const char* name, bool def) {
    char buf[16];
    DWORD n = GetEnvironmentVariableA(name, buf, sizeof(buf));
    if (n == 0 || n >= sizeof(buf)) return def;
    return !(buf[0] == '0' || buf[0] == 'n' || buf[0] == 'N' || buf[0] == 'f' || buf[0] == 'F');
}

// MS2HOOK_DISABLE: "*" = no hooks, or comma-separated names / hex VAs / "file:<substring of the source path>".
// A value starting with '@' names a list file (Wine path, e.g. Z:\\home\\...) read instead of the env text, so
// bisecting is not limited by the 32 KB environment value; entries may be separated by commas or newlines.
// MS2HOOK_ONLY (same syntax): when set, hooks matching NO entry are disabled (allow list).
static const char* LoadList(const char* var, char** storage, bool* isSet) {
    static char envbuf[4096];
    DWORD n = GetEnvironmentVariableA(var, envbuf, sizeof(envbuf));
    *isSet = n != 0 && n < sizeof(envbuf);
    if (!*isSet) return "";
    if (envbuf[0] != '@') {
        // own copy: envbuf is shared, so the next LoadList (MS2HOOK_ONLY after MS2HOOK_DISABLE) would overwrite it
        *storage = static_cast<char*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, n + 1));
        memcpy(*storage, envbuf, n);
        return *storage;
    }
    HANDLE h = CreateFileA(envbuf + 1, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
    if (h == INVALID_HANDLE_VALUE) return "";
    DWORD sz = GetFileSize(h, nullptr), got = 0;
    *storage = static_cast<char*>(HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sz + 2));
    ReadFile(h, *storage, sz, &got, nullptr);
    CloseHandle(h);
    for (char* c = *storage; *c; ++c) if (*c == '\n' || *c == '\r' || *c == ' ') *c = ',';
    return *storage;
}

static bool ListMatches(const char* list, const Replacement* r) {
    char va[32];
    snprintf(va, sizeof(va), "0x%llx", static_cast<unsigned long long>(r->va));
    const char* p = list;
    while (*p) {
        const char* e = strchr(p, ',');
        size_t len = e ? static_cast<size_t>(e - p) : strlen(p);
        if (len == 0) { p += e ? 1 : 0; if (!e) break; continue; }
        if ((len == 1 && *p == '*') || (len == strlen(r->name) && _strnicmp(p, r->name, len) == 0) ||
            (len == strlen(va) && _strnicmp(p, va, len) == 0))
            return true;
        if (len > 5 && _strnicmp(p, "file:", 5) == 0 && r->file) {
            std::string sub(p + 5, len - 5), f(r->file);
            for (char& c : f) if (c == '\\') c = '/';
            if (f.find(sub) != std::string::npos) return true;
        }
        p += len + (e ? 1 : 0);
    }
    return false;
}

bool IsDisabled(const Replacement* r) {
    static char* store1 = nullptr; static char* store2 = nullptr;
    static bool dis = false, only = false;
    static const char* disList = LoadList("MS2HOOK_DISABLE", &store1, &dis);
    static const char* onlyList = LoadList("MS2HOOK_ONLY", &store2, &only);
    if (dis && ListMatches(disList, r)) return true;
    if (only && !ListMatches(onlyList, r)) return true;
    return false;
}

const char* ShortFile(const char* f) {
    const char* s = strstr(f, "src/");
    if (!s) s = strstr(f, "src\\");
    return s ? s : f;
}

// Counting stub (32 bytes):  inc qword ptr [rip+count] ; jmp qword ptr [rip+target] ; dq target ; dq count
// Not lock-prefixed: counts are approximate under heavy multithreaded use, but cost ~1 cycle.
struct CountStub {
    uint8_t code[16];
    void* target;
    uint64_t count;
};
static_assert(sizeof(CountStub) == 32, "stub layout");

CountStub* g_stubs = nullptr;
size_t g_stubCap = 0, g_stubUsed = 0;

CountStub* MakeStub(void* target) {
    if (g_stubUsed == g_stubCap) {
        // One RWX block per 2048 hooks; the stub only uses rip-relative/absolute addressing, so any address works.
        g_stubCap = 2048;
        g_stubUsed = 0;
        g_stubs = static_cast<CountStub*>(
            VirtualAlloc(nullptr, g_stubCap * sizeof(CountStub), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));
        if (!g_stubs) return nullptr;
    }
    CountStub* s = &g_stubs[g_stubUsed++];
    static const uint8_t code[16] = {
        0x48, 0xff, 0x05, 0, 0, 0, 0,        // inc qword ptr [rip+disp32]  (disp patched below)
        0xff, 0x25, 0, 0, 0, 0,              // jmp qword ptr [rip+disp32]  (disp patched below)
        0xcc, 0xcc, 0xcc};
    memcpy(s->code, code, sizeof(code));
    // inc: next ip = code+7, counter at offsetof(count)
    int32_t dInc = static_cast<int32_t>(offsetof(CountStub, count) - 7);
    memcpy(s->code + 3, &dInc, 4);
    // jmp: next ip = code+13, target at offsetof(target)
    int32_t dJmp = static_cast<int32_t>(offsetof(CountStub, target) - 13);
    memcpy(s->code + 9, &dJmp, 4);
    s->target = target;
    s->count = 0;
    FlushInstructionCache(GetCurrentProcess(), s, sizeof(*s));
    return s;
}

bool ExecutableRange(uintptr_t addr, size_t len) {
    auto* base = reinterpret_cast<uint8_t*>(GetModuleHandleW(nullptr));
    auto* dos = reinterpret_cast<IMAGE_DOS_HEADER*>(base);
    auto* nt = reinterpret_cast<IMAGE_NT_HEADERS*>(base + dos->e_lfanew);
    auto* sec = IMAGE_FIRST_SECTION(nt);
    uintptr_t rva = addr - reinterpret_cast<uintptr_t>(base);
    for (WORD i = 0; i < nt->FileHeader.NumberOfSections; ++i, ++sec) {
        if (!(sec->Characteristics & IMAGE_SCN_MEM_EXECUTE)) continue;
        uintptr_t lo = sec->VirtualAddress, hi = lo + std::max(sec->Misc.VirtualSize, sec->SizeOfRawData);
        if (rva >= lo && rva + len <= hi) return true;
    }
    return false;
}

DWORD WINAPI StatsThread(void*) {
    std::vector<uint64_t> last(g_installed.size(), 0);
    for (;;) {
        Sleep(5000);
        char line[65536];
        int pos = 0;
        bool changed = false;
        for (size_t i = 0; i < g_installed.size(); ++i) {
            Replacement* r = g_installed[i];
            if (!r->counter) continue;
            uint64_t c = *r->counter;
            if (c != last[i]) changed = true;
            last[i] = c;
            if (c != 0 && pos < static_cast<int>(sizeof(line)) - 128)   // only counters that moved: the 64 KB line is no longer cut off by thousands of zeros
                pos += snprintf(line + pos, sizeof(line) - pos, " %s=%llu", r->name, static_cast<unsigned long long>(c));
        }
        if (changed) Log("calls:%s", line);
    }
}

}  // namespace

void Log(const char* fmt, ...) {
    if (g_log == INVALID_HANDLE_VALUE) return;
    char buf[65536];
    ULONGLONG t = GetTickCount64() - g_t0;
    int n = snprintf(buf, sizeof(buf), "[%6llu.%03llu] ", t / 1000, t % 1000);
    va_list ap;
    va_start(ap, fmt);
    int m = vsnprintf(buf + n, sizeof(buf) - n - 2, fmt, ap);
    va_end(ap);
    if (m < 0) m = 0;
    n += std::min(m, static_cast<int>(sizeof(buf)) - n - 3);
    buf[n++] = '\r';
    buf[n++] = '\n';
    EnterCriticalSection(&g_logLock);
    DWORD w;
    WriteFile(g_log, buf, n, &w, nullptr);
    LeaveCriticalSection(&g_logLock);
}

bool Register(Replacement* r) {
    r->next = g_head;
    r->original = nullptr;
    r->counter = nullptr;
    r->installed = false;
    g_head = r;
    return true;
}

void* Original(uintptr_t va) {
    for (Replacement* r = g_head; r; r = r->next)
        if (r->va == va && r->installed) return r->original;
    return VaToPtr(va);
}

void* ReplacementFn(uintptr_t va) {
    for (Replacement* r = g_head; r; r = r->next)
        if (r->va == va) return r->fn;
    return nullptr;
}

bool IsInstalled(uintptr_t va) {
    for (Replacement* r = g_head; r; r = r->next)
        if (r->va == va) return r->installed;
    return false;
}

extern "C" IMAGE_DOS_HEADER __ImageBase;

// MS2HOOK_AVLOG=1: log the first access violations (rip, module+offset, fault address, a few stack qwords).
static LONG CALLBACK AvLogHandler(EXCEPTION_POINTERS* ep) {
    static volatile LONG count = 0;
    if (ep->ExceptionRecord->ExceptionCode == 0x406D1388 || ep->ExceptionRecord->ExceptionCode == 0x40010006 || ep->ExceptionRecord->ExceptionCode == 0x4001000A || InterlockedIncrement(&count) > 60) return EXCEPTION_CONTINUE_SEARCH;
    auto describe = [](uintptr_t a, char* out, size_t n) {
        HMODULE m = nullptr;
        char nm[MAX_PATH] = "?";
        if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                               reinterpret_cast<LPCSTR>(a), &m)) {
            GetModuleFileNameA(m, nm, MAX_PATH);
            const char* b = strrchr(nm, '\\');
            snprintf(out, n, "%s+0x%llx", b ? b + 1 : nm, (unsigned long long)(a - reinterpret_cast<uintptr_t>(m)));
        } else snprintf(out, n, "%p", reinterpret_cast<void*>(a));
    };
    char d[320];
    describe(ep->ContextRecord->Rip, d, sizeof d);
    Log("EXC code=%08lx rip=%s addr=%p rw=%llu", ep->ExceptionRecord->ExceptionCode, d, reinterpret_cast<void*>(ep->ExceptionRecord->ExceptionInformation[1]),
        (unsigned long long)ep->ExceptionRecord->ExceptionInformation[0]);
    const CONTEXT* c = ep->ContextRecord;
    Log("   rax=%llx rbx=%llx rcx=%llx rdx=%llx rsi=%llx rdi=%llx rbp=%llx rsp=%llx", c->Rax, c->Rbx, c->Rcx, c->Rdx,
        c->Rsi, c->Rdi, c->Rbp, c->Rsp);
    Log("   r8=%llx r9=%llx r10=%llx r11=%llx r12=%llx r13=%llx r14=%llx r15=%llx", c->R8, c->R9, c->R10, c->R11,
        c->R12, c->R13, c->R14, c->R15);
    // the hook DLL's whole image (its .text is larger than 4 MB, a fixed window dropped the upper frames)
    const uintptr_t dllLo = reinterpret_cast<uintptr_t>(&__ImageBase);
    const uintptr_t dllHi = dllLo + reinterpret_cast<const IMAGE_NT_HEADERS*>(
        reinterpret_cast<const char*>(&__ImageBase) + __ImageBase.e_lfanew)->OptionalHeader.SizeOfImage;
    auto* sp = reinterpret_cast<uintptr_t*>(c->Rsp);
    for (int i = 0; i < 700; ++i) {
        uintptr_t v = 0;
        __try { v = sp[i]; } __except (EXCEPTION_EXECUTE_HANDLER) { break; }
        if (v >= 0x140000000ull && v < 0x143c00000ull) { Log("   stack[%d] exe 0x%llx", i, (unsigned long long)v); }
        else if (v >= dllLo + 0x1000 && v < dllHi) { describe(v, d, sizeof d); Log("   stack[%d] %s", i, d); }
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

void OpenLog() {
    InitializeCriticalSection(&g_logLock);
    g_t0 = GetTickCount64();
    wchar_t path[MAX_PATH];
    DWORD n = GetModuleFileNameW(nullptr, path, MAX_PATH);
    wchar_t* slash = wcsrchr(path, L'\\');
    if (n == 0 || !slash) return;
    wcscpy_s(slash + 1, MAX_PATH - (slash + 1 - path), L"ms2hook.log");
    g_log = CreateFileW(path, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, CREATE_ALWAYS,
                        FILE_ATTRIBUTE_NORMAL, nullptr);
    if (getenv("MS2HOOK_AVLOG")) AddVectoredExceptionHandler(1, AvLogHandler);
}

int InstallAll() {
    auto* base = reinterpret_cast<uint8_t*>(GetModuleHandleW(nullptr));
    g_imageDelta = reinterpret_cast<uintptr_t>(base) - kImageBase;
    auto* nt = reinterpret_cast<IMAGE_NT_HEADERS*>(base + reinterpret_cast<IMAGE_DOS_HEADER*>(base)->e_lfanew);

    char exe[MAX_PATH];
    GetModuleFileNameA(nullptr, exe, MAX_PATH);
    Log("ms2hook: exe %s base=%p TimeDateStamp=0x%08lx SizeOfImage=0x%lx", exe, base,
        nt->FileHeader.TimeDateStamp, nt->OptionalHeader.SizeOfImage);

    std::vector<Replacement*> all;
    for (Replacement* r = g_head; r; r = r->next) {
        r->original = VaToPtr(r->va);
        all.push_back(r);
    }
    std::sort(all.begin(), all.end(), [](Replacement* a, Replacement* b) { return a->va < b->va; });
    Log("ms2hook: %zu registered replacement(s)", all.size());

    bool exeOk = nt->FileHeader.TimeDateStamp == kExpectedTimeDateStamp &&
                 nt->OptionalHeader.SizeOfImage == kExpectedSizeOfImage;
    if (!exeOk)
        Log("ms2hook: WRONG EXE (expected KMS2_DEV x64 2022-04-13, TimeDateStamp 0x%08lx SizeOfImage 0x%lx) - "
            "refusing all hooks", kExpectedTimeDateStamp, kExpectedSizeOfImage);
    const bool counting = EnvFlag("MS2HOOK_COUNT", true);

    int installed = 0, refused = 0;
    for (size_t i = 0; i < all.size(); ++i) {
        Replacement* r = all[i];
        auto* target = static_cast<uint8_t*>(VaToPtr(r->va));
        const char* reason = nullptr;
        char why[256] = "";
        if (!exeOk) {
            reason = "wrong exe";
        } else if (i > 0 && all[i - 1]->va == r->va) {
            reason = "duplicate VA";
        } else if (IsDisabled(r)) {
            reason = "disabled by MS2HOOK_DISABLE";
        } else if (!ExecutableRange(reinterpret_cast<uintptr_t>(target), std::max<uint32_t>(r->guardLen, 5))) {
            reason = "VA not in an executable section";
        } else if (r->guardLen) {
            uint32_t h = Fnv1a(target, r->guardLen);
            if (h != r->guardHash) {
                snprintf(why, sizeof(why), "guard mismatch: fnv1a(%u bytes)=0x%08x expected 0x%08x", r->guardLen, h,
                         r->guardHash);
                reason = why;
            }
        }
        if (!reason) {
            void* detour = r->fn;
            CountStub* stub = nullptr;
            if (counting) {
                stub = MakeStub(r->fn);
                if (stub) detour = stub;
            }
            void* orig = target;
            LONG e = DetourTransactionBegin();
            if (e == NO_ERROR) e = DetourAttach(&orig, detour);
            if (e == NO_ERROR) {
                e = DetourTransactionCommit();
            } else {
                DetourTransactionAbort();
            }
            if (e != NO_ERROR) {
                snprintf(why, sizeof(why), "Detours error %ld", e);
                reason = why;
            } else {
                r->original = orig;
                r->counter = stub ? &stub->count : nullptr;
                r->installed = true;
            }
        }
        if (reason) {
            ++refused;
            Log("REFUSED   0x%llx %-40s %s:%d  (%s)", static_cast<unsigned long long>(r->va), r->name,
                ShortFile(r->file), r->line, reason);
        } else {
            ++installed;
            g_installed.push_back(r);
            Log("INSTALLED 0x%llx %-40s %s:%d  guard=%s%u trampoline=%p", static_cast<unsigned long long>(r->va),
                r->name, ShortFile(r->file), r->line, r->guardLen ? "fnv1a/" : "NONE/", r->guardLen, r->original);
        }
    }
    Log("ms2hook: %d installed, %d refused, call counting %s", installed, refused, counting ? "on" : "off");
    return installed;
}

void StartStatsThread() {
    if (g_installed.empty()) return;
    HANDLE h = CreateThread(nullptr, 0, StatsThread, nullptr, 0, nullptr);
    if (h) CloseHandle(h);
}

void LogFinalStats() {
    for (Replacement* r : g_installed)
        if (r->counter) Log("final calls: %s=%llu", r->name, static_cast<unsigned long long>(*r->counter));
}

}  // namespace ms2::hook
