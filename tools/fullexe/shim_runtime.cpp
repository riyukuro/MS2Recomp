// Full-exe shim runtime (tools/fullexe): what the hook-DLL runtime provides to the unit objs, for a standalone link.
//   ms2::g_imageDelta = 0 and a no-op ms2::hook::Register (the MS2_REPLACE registration statics call it at static init)
//   ms2_fullexe_trap: target of the generated stubs (shim.py) for every symbol no obj defines. It logs the symbol, its
//     exe VA and the caller to fullexe-trap.log next to the exe, plus a short backtrace, then terminates the process.
//   a vectored exception logger: the first few fatal exceptions (access violation, int3, illegal instruction, stack
//     overflow...) with their address and backtrace, to the same log. It only logs; handling is left to the program.
//   an "UNHANDLED" line when an exception reaches the exe's top-level filter (its crash dialog), see unhandled_logger.
//   boot milestones: ms2_fullexe_mark(name) appends a line (called from the init_seg(compiler) static and the TLS-free
//     CRT phases the shim can see).
// Built by shim.py with the toolchain cl (/O2 /MD); no SDK or game headers beyond <windows.h>.
#include <windows.h>
#include <stdio.h>
#include <stdint.h>
#include <intrin.h>

namespace ms2 {
uintptr_t g_imageDelta = 0;
namespace hook {
struct Replacement;
bool Register(Replacement*) { return false; }
}  // namespace hook
}  // namespace ms2

static HANDLE g_log = INVALID_HANDLE_VALUE;
static volatile LONG g_fatal = 0;

static void open_log() {
    if (g_log != INVALID_HANDLE_VALUE) return;
    char path[MAX_PATH];
    DWORD n = GetModuleFileNameA(nullptr, path, MAX_PATH);
    while (n && path[n - 1] != '\\' && path[n - 1] != '/') --n;
    lstrcpyA(path + n, "fullexe-trap.log");
    g_log = CreateFileA(path, FILE_APPEND_DATA, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_ALWAYS,
                        FILE_ATTRIBUTE_NORMAL, nullptr);
}

static void out(const char* fmt, ...) {
    char buf[1024];
    va_list a;
    va_start(a, fmt);
    int n = _vsnprintf_s(buf, sizeof buf, _TRUNCATE, fmt, a);
    va_end(a);
    if (n < 0) n = (int)strlen(buf);
    open_log();
    DWORD w;
    if (g_log != INVALID_HANDLE_VALUE) WriteFile(g_log, buf, (DWORD)n, &w, nullptr);
    OutputDebugStringA(buf);
    HANDLE e = GetStdHandle(STD_ERROR_HANDLE);
    if (e && e != INVALID_HANDLE_VALUE) WriteFile(e, buf, (DWORD)n, &w, nullptr);
}

static void backtrace(const char* tag) {
    void* frames[24];
    USHORT n = RtlCaptureStackBackTrace(1, 24, frames, nullptr);
    uintptr_t base = (uintptr_t)GetModuleHandleA(nullptr);
    for (USHORT i = 0; i < n; i++) {
        HMODULE m = nullptr;
        char name[MAX_PATH] = "?";
        if (GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                               (LPCSTR)frames[i], &m) && m) {
            GetModuleFileNameA(m, name, MAX_PATH);
        }
        const char* b = strrchr(name, '\\');
        out("%s   #%u %p %s+0x%llx\n", tag, i, frames[i], b ? b + 1 : name,
            (unsigned long long)((uintptr_t)frames[i] - (m ? (uintptr_t)m : base)));
    }
}

extern "C" void ms2_fullexe_mark(const char* what) {
    out("MARK %s tid=%lu tick=%lu\n", what, GetCurrentThreadId(), GetTickCount());
}

extern "C" __declspec(noreturn) void ms2_fullexe_trap(const char* name, uint64_t va, void* ret) {
    out("TRAP %s exe_va=0x%llx caller=%p tid=%lu\n", name, (unsigned long long)va, ret, GetCurrentThreadId());
    backtrace("TRAP");
    if (g_log != INVALID_HANDLE_VALUE) FlushFileBuffers(g_log);
    TerminateProcess(GetCurrentProcess(), 0xDEAD);
    for (;;) {}
}

static void log_image_words(const uintptr_t* sp, const uintptr_t* top, int max) {
    uintptr_t base = (uintptr_t)GetModuleHandleA(nullptr);
    auto* nt = (IMAGE_NT_HEADERS*)(base + ((IMAGE_DOS_HEADER*)base)->e_lfanew);
    uintptr_t end = base + nt->OptionalHeader.SizeOfImage;
    int shown = 0;
    for (const uintptr_t* p = sp; p < top && shown < max; p++) {
        if (*p > base + 0x1000 && *p < end) {
            out("EXC   [rsp+0x%llx] image+0x%llx\n", (unsigned long long)((p - sp) * 8),
                (unsigned long long)(*p - base));
            shown++;
        }
    }
}

// a stack overflow leaves the handler about a page of stack, too little for out(): the handler only hands the
// faulting rsp to this thread (made at shim init, so it has its own stack), which logs the overflowed stack's image
// return addresses (the recursion shows as a repeating cycle) and ends the process
static volatile uintptr_t g_ovf_rsp = 0;
static HANDLE g_ovf_event = nullptr;
static DWORD WINAPI overflow_reporter(void*) {
    WaitForSingleObject(g_ovf_event, INFINITE);
    const uintptr_t* sp = (const uintptr_t*)g_ovf_rsp;
    MEMORY_BASIC_INFORMATION mbi;
    const uintptr_t* top = sp;
    if (VirtualQuery(sp, &mbi, sizeof mbi)) top = (const uintptr_t*)((uintptr_t)mbi.BaseAddress + mbi.RegionSize);
    out("EXC 0xc00000fd stack overflow rsp=%p (stack region top %p): innermost image words\n", (void*)sp, (void*)top);
    log_image_words(sp, top, 64);
    // the outermost frames: the last image words below the region top
    const uintptr_t* q = top;
    int n = 0;
    uintptr_t base = (uintptr_t)GetModuleHandleA(nullptr);
    while (q > sp && n < 48) {
        --q;
        if (*q > base + 0x1000 && *q < base + 0x8000000) n++;
    }
    out("EXC   ... outermost image words:\n");
    log_image_words(q, top, 48);
    if (g_log != INVALID_HANDLE_VALUE) FlushFileBuffers(g_log);
    TerminateProcess(GetCurrentProcess(), 0xFD);
    return 0;
}

// a /GS cookie mismatch ends in __fastfail (int 29h), which wine raises past the vectored handlers: __report_gsfailure
// (entered by a jmp from __security_check_cookie, so [rsp] is the return address into the overrunning function) is
// patched at shim init to jump here instead
extern "C" void __report_gsfailure(uintptr_t);
static void gs_logger(uintptr_t cookie) {
    const uintptr_t* sp = (const uintptr_t*)_AddressOfReturnAddress();
    uintptr_t base = (uintptr_t)GetModuleHandleA(nullptr);
    MEMORY_BASIC_INFORMATION mbi;
    const uintptr_t* top = sp;
    if (VirtualQuery(sp, &mbi, sizeof mbi)) top = (const uintptr_t*)((uintptr_t)mbi.BaseAddress + mbi.RegionSize);
    out("EXC 0xc0000409 /GS cookie check failed in the function returning to image+0x%llx (cookie %llx) tid=%lu\n",
        (unsigned long long)(*sp - base), (unsigned long long)cookie, GetCurrentThreadId());
    log_image_words(sp, top, 48);
    if (g_log != INVALID_HANDLE_VALUE) FlushFileBuffers(g_log);
    TerminateProcess(GetCurrentProcess(), 0x409);
}

static void patch_gsfailure() {
    unsigned char* p = (unsigned char*)&__report_gsfailure;
    unsigned char code[12] = {0x48, 0xb8, 0, 0, 0, 0, 0, 0, 0, 0, 0xff, 0xe0};  // mov rax, imm64; jmp rax
    void* target = (void*)&gs_logger;
    memcpy(code + 2, &target, 8);
    DWORD old;
    if (VirtualProtect(p, sizeof code, PAGE_EXECUTE_READWRITE, &old)) {
        memcpy(p, code, sizeof code);
        VirtualProtect(p, sizeof code, old, &old);
        FlushInstructionCache(GetCurrentProcess(), p, sizeof code);
    }
}

// a run that neither faults nor reaches its next MARK: from 20 s on, every 10 s, log the main thread's rip and the
// image words on its stack (suspended for the walk), so a hang or a busy loop shows where it sits
static HANDLE g_main_thread = nullptr;
static DWORD WINAPI hang_sampler(void*) {
    uintptr_t base = (uintptr_t)GetModuleHandleA(nullptr);
    for (int n = 0;; n++) {
        Sleep(n ? 10000 : 20000);
        if (SuspendThread(g_main_thread) == (DWORD)-1) return 0;
        CONTEXT c = {};
        c.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
        if (GetThreadContext(g_main_thread, &c)) {
            const uintptr_t* sp = (const uintptr_t*)c.Rsp;
            MEMORY_BASIC_INFORMATION mbi;
            const uintptr_t* top = sp;
            if (VirtualQuery(sp, &mbi, sizeof mbi)) top = (const uintptr_t*)((uintptr_t)mbi.BaseAddress + mbi.RegionSize);
            out("SAMPLE %d main thread rip=%p (image+0x%llx) rsp=%p tick=%lu\n", n, (void*)c.Rip,
                (unsigned long long)(c.Rip - base), (void*)c.Rsp, GetTickCount());
            log_image_words(sp, top, 40);
            if (g_log != INVALID_HANDLE_VALUE) FlushFileBuffers(g_log);
        }
        ResumeThread(g_main_thread);
    }
}

static void log_unwind(CONTEXT ctx, const char* tag);
static LONG CALLBACK fatal_logger(EXCEPTION_POINTERS* ep) {
    DWORD c = ep->ExceptionRecord->ExceptionCode;
    if (c == EXCEPTION_STACK_OVERFLOW && g_ovf_event) {
        g_ovf_rsp = ep->ContextRecord->Rsp;
        SetEvent(g_ovf_event);
        Sleep(INFINITE);
    }
    if (c != EXCEPTION_ACCESS_VIOLATION && c != EXCEPTION_BREAKPOINT && c != EXCEPTION_ILLEGAL_INSTRUCTION &&
        c != EXCEPTION_STACK_OVERFLOW && c != EXCEPTION_PRIV_INSTRUCTION && c != EXCEPTION_INT_DIVIDE_BY_ZERO &&
        c != STATUS_HEAP_CORRUPTION && c != STATUS_STACK_BUFFER_OVERRUN && c != STATUS_INVALID_PARAMETER)
        return EXCEPTION_CONTINUE_SEARCH;
    if (InterlockedIncrement(&g_fatal) > 8) return EXCEPTION_CONTINUE_SEARCH;
    const EXCEPTION_RECORD* r = ep->ExceptionRecord;
    out("EXC 0x%08lx at %p (image+0x%llx) info %llx %llx tid=%lu rsp=%p\n", c, r->ExceptionAddress,
        (unsigned long long)((uintptr_t)r->ExceptionAddress - (uintptr_t)GetModuleHandleA(nullptr)),
        r->NumberParameters > 0 ? (unsigned long long)r->ExceptionInformation[0] : 0ull,
        r->NumberParameters > 1 ? (unsigned long long)r->ExceptionInformation[1] : 0ull, GetCurrentThreadId(),
        (void*)ep->ContextRecord->Rsp);
    if (c == EXCEPTION_ACCESS_VIOLATION) {
        // F7: wine reports info 0 0 for a non-canonical address, so the operands are only visible in the registers
        const CONTEXT* x = ep->ContextRecord;
        out("EXC   rax=%016llx rbx=%016llx rcx=%016llx rdx=%016llx\n", x->Rax, x->Rbx, x->Rcx, x->Rdx);
        out("EXC   rsi=%016llx rdi=%016llx rbp=%016llx r8 =%016llx\n", x->Rsi, x->Rdi, x->Rbp, x->R8);
        out("EXC   r9 =%016llx r10=%016llx r11=%016llx r12=%016llx\n", x->R9, x->R10, x->R11, x->R12);
        out("EXC   r13=%016llx r14=%016llx r15=%016llx\n", x->R13, x->R14, x->R15);
        MEMORY_BASIC_INFORMATION mi;
        const unsigned char* ip = (const unsigned char*)x->Rip;
        if (VirtualQuery(ip, &mi, sizeof mi) && mi.State == MEM_COMMIT &&
            (uintptr_t)ip + 16 <= (uintptr_t)mi.BaseAddress + mi.RegionSize) {
            char hex[16 * 3 + 1];
            for (int i = 0; i < 16; i++) sprintf_s(hex + i * 3, 4, " %02x", ip[i]);
            out("EXC   code at rip:%s\n", hex);
        }
    }
    // the faulting frame's return chain: RtlCaptureStackBackTrace from here walks the handler's own frames first, so
    // log the context's rsp words that look like image code addresses instead
    uintptr_t base = (uintptr_t)GetModuleHandleA(nullptr);
    auto* nt = (IMAGE_NT_HEADERS*)(base + ((IMAGE_DOS_HEADER*)base)->e_lfanew);
    uintptr_t end = base + nt->OptionalHeader.SizeOfImage;
    uintptr_t* sp = (uintptr_t*)ep->ContextRecord->Rsp;
    // every hit in the first 0x800 bytes, then up to 16 more out to 0x1000: a 16-hit cap alone ended inside the
    // recursive MS2Ptr release thunks at rsp+0x100 (F6, image+0x4451ef), before the frame that started the release
    int beyond = 0;
    for (int i = 0; i < 512 && beyond < 16; i++) {
        MEMORY_BASIC_INFORMATION mbi;
        if (!VirtualQuery(sp + i, &mbi, sizeof mbi) || mbi.State != MEM_COMMIT) break;
        if (sp[i] > base + 0x1000 && sp[i] < end) {
            out("EXC   [rsp+0x%x] image+0x%llx\n", i * 8, (unsigned long long)(sp[i] - base));
            if (i >= 0x800 / 8) beyond++;
        }
    }
    // then the real return chain, unwound with the image's .pdata: the word scan is bounded, and stale slots
    // hide which frame owns the faulting one (a leaf without .pdata returns through [rsp])
    log_unwind(*ep->ContextRecord, "EXC");
    if (g_log != INVALID_HANDLE_VALUE) FlushFileBuffers(g_log);
    return EXCEPTION_CONTINUE_SEARCH;
}

static void log_unwind(CONTEXT ctx, const char* tag) {
    uintptr_t base = (uintptr_t)GetModuleHandleA(nullptr);
    auto* nt = (IMAGE_NT_HEADERS*)(base + ((IMAGE_DOS_HEADER*)base)->e_lfanew);
    uintptr_t end = base + nt->OptionalHeader.SizeOfImage;
    for (int f = 0; f < 40; f++) {
        DWORD64 ib = 0;
        PRUNTIME_FUNCTION fe = RtlLookupFunctionEntry(ctx.Rip, &ib, nullptr);
        if (fe) {
            void* hd = nullptr;
            DWORD64 ef = 0;
            RtlVirtualUnwind(UNW_FLAG_NHANDLER, ib, ctx.Rip, fe, &ctx, &hd, &ef, nullptr);
        } else {
            MEMORY_BASIC_INFORMATION mbi;
            if (!VirtualQuery((void*)ctx.Rsp, &mbi, sizeof mbi) || mbi.State != MEM_COMMIT) break;
            ctx.Rip = *(DWORD64*)ctx.Rsp;
            ctx.Rsp += 8;
        }
        if (!ctx.Rip) break;
        if (ctx.Rip > base + 0x1000 && ctx.Rip < end)
            out("%s   unwind #%d image+0x%llx rsp=%p\n", tag, f, (unsigned long long)(ctx.Rip - base), (void*)ctx.Rsp);
        else
            out("%s   unwind #%d %p rsp=%p\n", tag, f, (void*)ctx.Rip, (void*)ctx.Rsp);
    }
}

// the crash dialog (2026-10-29, cri9 h3): an exception nobody handles reaches the top-level filter, the exe's crash
// manager's FUN_140a43fa0, whose CrashReporter AfterDump callback opens g_dlgCrash.DoModal() (the empty 확인 box). The
// dialog keeps the process alive, so the run looked like a hang. Every filter the image installs (SetUnhandledExceptionFilter
// through its IAT) is wrapped: the wrapper logs one "UNHANDLED" line with the fatal exception and its unwound return chain,
// then calls the exe's filter as before. smoke.sh/boot.sh end the run on that line (tools/fullexe/smoke_report.py: crash dialog).
static decltype(&SetUnhandledExceptionFilter) r_SetUnhandledExceptionFilter;
static LPTOP_LEVEL_EXCEPTION_FILTER g_app_filter;
static LONG WINAPI unhandled_logger(EXCEPTION_POINTERS* ep) {
    const EXCEPTION_RECORD* r = ep->ExceptionRecord;
    out("UNHANDLED 0x%08lx at %p (image+0x%llx) info %llx %llx tid=%lu rsp=%p: the exe's top-level filter (crash dialog) runs next\n",
        r->ExceptionCode, r->ExceptionAddress,
        (unsigned long long)((uintptr_t)r->ExceptionAddress - (uintptr_t)GetModuleHandleA(nullptr)),
        r->NumberParameters > 0 ? (unsigned long long)r->ExceptionInformation[0] : 0ull,
        r->NumberParameters > 1 ? (unsigned long long)r->ExceptionInformation[1] : 0ull, GetCurrentThreadId(),
        (void*)ep->ContextRecord->Rsp);
    log_unwind(*ep->ContextRecord, "UNHANDLED");
    if (g_log != INVALID_HANDLE_VALUE) FlushFileBuffers(g_log);
    LPTOP_LEVEL_EXCEPTION_FILTER f = g_app_filter;
    return f ? f(ep) : EXCEPTION_CONTINUE_SEARCH;
}
static LPTOP_LEVEL_EXCEPTION_FILTER WINAPI w_SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER f) {
    LPTOP_LEVEL_EXCEPTION_FILTER prev = r_SetUnhandledExceptionFilter(f ? unhandled_logger : nullptr);
    if (prev == unhandled_logger) prev = g_app_filter;       // the caller sees the filter it replaced, not the wrapper
    g_app_filter = f;
    return prev;
}

// ---- boot milestones: first calls of a few imports, by patching this image's IAT slots (we own the image) ----
static void patch_iat(void* real, void* wrapper) {
    if (!real) return;
    uintptr_t base = (uintptr_t)GetModuleHandleA(nullptr);
    auto* nt = (IMAGE_NT_HEADERS*)(base + ((IMAGE_DOS_HEADER*)base)->e_lfanew);
    const IMAGE_DATA_DIRECTORY& d = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IAT];
    void** iat = (void**)(base + d.VirtualAddress);
    for (DWORD i = 0; i < d.Size / sizeof(void*); i++) {
        if (iat[i] != real) continue;
        DWORD old;
        VirtualProtect(&iat[i], sizeof(void*), PAGE_READWRITE, &old);
        iat[i] = wrapper;
        VirtualProtect(&iat[i], sizeof(void*), old, &old);
    }
}

#define MS2_FIRST(n, ...)                     \
    do {                                      \
        static volatile LONG seen = 0;        \
        if (InterlockedIncrement(&seen) <= (n)) out(__VA_ARGS__); \
    } while (0)

typedef int(__cdecl* AfxWinMainFn)(HINSTANCE, HINSTANCE, LPSTR, int);
static AfxWinMainFn r_AfxWinMain;
static int __cdecl w_AfxWinMain(HINSTANCE a, HINSTANCE b, LPSTR c, int d) {
    ms2_fullexe_mark("WinMain -> AfxWinMain (mfc140)");
    int r = r_AfxWinMain(a, b, c, d);
    out("MARK AfxWinMain returned %d\n", r);
    return r;
}
static decltype(&CreateWindowExA) r_CreateWindowExA;
static HWND WINAPI w_CreateWindowExA(DWORD x, LPCSTR c, LPCSTR t, DWORD s, int X, int Y, int W, int H, HWND p, HMENU m,
                                     HINSTANCE i, LPVOID l) {
    HWND h = r_CreateWindowExA(x, c, t, s, X, Y, W, H, p, m, i, l);
    MS2_FIRST(12, "MARK CreateWindowExA class=%s title=%s %dx%d -> %p\n", IS_INTRESOURCE(c) ? "#atom" : c,
              t ? t : "", W, H, (void*)h);
    return h;
}
static decltype(&CreateWindowExW) r_CreateWindowExW;
static HWND WINAPI w_CreateWindowExW(DWORD x, LPCWSTR c, LPCWSTR t, DWORD s, int X, int Y, int W, int H, HWND p,
                                     HMENU m, HINSTANCE i, LPVOID l) {
    HWND h = r_CreateWindowExW(x, c, t, s, X, Y, W, H, p, m, i, l);
    MS2_FIRST(12, "MARK CreateWindowExW class=%ls title=%ls %dx%d -> %p\n", IS_INTRESOURCE(c) ? L"#atom" : c,
              t ? t : L"", W, H, (void*)h);
    return h;
}
static decltype(&ShowWindow) r_ShowWindow;
static BOOL WINAPI w_ShowWindow(HWND h, int n) {
    MS2_FIRST(4, "MARK ShowWindow %p %d\n", (void*)h, n);
    return r_ShowWindow(h, n);
}
static decltype(&PeekMessageA) r_PeekMessageA;
static BOOL WINAPI w_PeekMessageA(LPMSG m, HWND h, UINT a, UINT b, UINT r) {
    MS2_FIRST(1, "MARK message loop (first PeekMessageA)\n");
    return r_PeekMessageA(m, h, a, b, r);
}
static decltype(&PeekMessageW) r_PeekMessageW;
static BOOL WINAPI w_PeekMessageW(LPMSG m, HWND h, UINT a, UINT b, UINT r) {
    MS2_FIRST(1, "MARK message loop (first PeekMessageW)\n");
    return r_PeekMessageW(m, h, a, b, r);
}
static decltype(&GetMessageA) r_GetMessageA;
static BOOL WINAPI w_GetMessageA(LPMSG m, HWND h, UINT a, UINT b) {
    MS2_FIRST(1, "MARK message loop (first GetMessageA)\n");
    return r_GetMessageA(m, h, a, b);
}
static decltype(&GetMessageW) r_GetMessageW;
static BOOL WINAPI w_GetMessageW(LPMSG m, HWND h, UINT a, UINT b) {
    MS2_FIRST(1, "MARK message loop (first GetMessageW)\n");
    return r_GetMessageW(m, h, a, b);
}
typedef HMODULE(WINAPI* LoadLibraryAFn)(LPCSTR);
static LoadLibraryAFn r_LoadLibraryA;
static HMODULE WINAPI w_LoadLibraryA(LPCSTR n) {
    HMODULE h = r_LoadLibraryA(n);
    MS2_FIRST(64, "MARK LoadLibraryA %s -> %p\n", n ? n : "", (void*)h);
    return h;
}
typedef HMODULE(WINAPI* LoadLibraryWFn)(LPCWSTR);
static LoadLibraryWFn r_LoadLibraryW;
static HMODULE WINAPI w_LoadLibraryW(LPCWSTR n) {
    HMODULE h = r_LoadLibraryW(n);
    MS2_FIRST(64, "MARK LoadLibraryW %ls -> %p\n", n ? n : L"", (void*)h);
    return h;
}

template <class F> static void wrap(F& real, const char* dll, const char* name, F wrapper) {
    HMODULE m = GetModuleHandleA(dll);
    real = m ? (F)GetProcAddress(m, name) : nullptr;
    patch_iat((void*)real, (void*)wrapper);
}

__declspec(dllimport) int AfxWinMain(HINSTANCE, HINSTANCE, LPSTR, int);

extern "C" int WinMainCRTStartup();
// linked as /entry: marks the loader hand-off, then the real CRT entry
extern "C" int ms2_fullexe_entry() {
    ms2_fullexe_mark("entry (loader done, before CRT init)");
    return WinMainCRTStartup();
}

// runs before the units' dynamic initializers (.CRT$XCC < .CRT$XCU)
#pragma warning(disable : 4073)
#pragma init_seg(compiler)
static struct ShimInit {
    ShimInit() {
        g_ovf_event = CreateEventA(nullptr, TRUE, FALSE, nullptr);
        CloseHandle(CreateThread(nullptr, 0x10000, overflow_reporter, nullptr, 0, nullptr));
        AddVectoredExceptionHandler(0, fatal_logger);
        patch_gsfailure();
        DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &g_main_thread, 0, FALSE,
                        DUPLICATE_SAME_ACCESS);
        CloseHandle(CreateThread(nullptr, 0x10000, hang_sampler, nullptr, 0, nullptr));
        ms2_fullexe_mark("crt-init (shim static, before unit initializers)");
        r_AfxWinMain = &AfxWinMain;
        patch_iat((void*)r_AfxWinMain, (void*)w_AfxWinMain);
        wrap(r_CreateWindowExA, "user32.dll", "CreateWindowExA", w_CreateWindowExA);
        wrap(r_CreateWindowExW, "user32.dll", "CreateWindowExW", w_CreateWindowExW);
        wrap(r_ShowWindow, "user32.dll", "ShowWindow", w_ShowWindow);
        wrap(r_PeekMessageA, "user32.dll", "PeekMessageA", w_PeekMessageA);
        wrap(r_PeekMessageW, "user32.dll", "PeekMessageW", w_PeekMessageW);
        wrap(r_GetMessageA, "user32.dll", "GetMessageA", w_GetMessageA);
        wrap(r_GetMessageW, "user32.dll", "GetMessageW", w_GetMessageW);
        wrap(r_LoadLibraryA, "kernel32.dll", "LoadLibraryA", w_LoadLibraryA);
        wrap(r_LoadLibraryW, "kernel32.dll", "LoadLibraryW", w_LoadLibraryW);
        wrap(r_SetUnhandledExceptionFilter, "kernel32.dll", "SetUnhandledExceptionFilter", w_SetUnhandledExceptionFilter);
    }
    ~ShimInit() { ms2_fullexe_mark("crt-exit (static destructors)"); }
} g_shimInit;
