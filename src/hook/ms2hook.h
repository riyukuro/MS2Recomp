// ms2hook.h - glue between recovered game code (src/ms2/...) and the original MapleStory2.exe.
//
// Recovered code includes this header and uses four macros:
//
//   MS2_REPLACE(va, function, guardLen, guardHash)
//       Redirect the original function at `va` (KMS2_DEV x64 VA, ImageBase 0x140000000) to `function`
//       (free function or static member). Namespace scope, directly after the definition.
//   MS2_REPLACE_METHOD(va, Class, Method, guardLen, guardHash)
//       Same for a (virtual or non-virtual) member function. A member-function thunk with Method's exact
//       signature that calls `this->Class::Method(args...)` non-virtually is generated, so virtual methods work
//       too, and the member ABI is kept (a class returned by value: hidden return pointer after `this`).
//       Method must not be overloaded and must be accessible from a derived class.
//   MS2_REPLACE_METHOD_VIA(va, Class, Base, Method, guardLen, guardHash)
//       Override of a virtual of a secondary base `Base` (the exe function receives `this` = the Base subobject,
//       e.g. UICutSceneMovie::OnMessage via IMessageListener at +0x18): the thunk derives from Base and adjusts.
//   MS2_REPLACE_OVERLOAD(va, Signature, function, guardLen, guardHash)
//       MS2_REPLACE for an overloaded free function / static member: Signature picks the overload,
//       e.g. MS2_REPLACE_OVERLOAD(0x140696e00, CString(BYTE*, UINT), CMD5Checksum::GetMD5, 190, 0x...).
//   MS2_REPLACE_CTOR(va, Class, guardLen, guardHash) / MS2_REPLACE_DTOR(va, Class, guardLen, guardHash)
//       Default constructor / destructor (thunks `Class* R(Class*)` doing placement-new resp. a qualified,
//       non-virtual `self->Class::~Class()`). A replaced constructor installs the DLL's vftable: only do this when
//       the vftable check (tools/progress.py) passes, i.e. every slot resolves to the exe's slot target.
//   guardLen/guardHash: FNV-1a-32 of the first guardLen bytes of the original function (normally the whole
//       function). Generate with `tools/ms2hook_sig.py <va>...`. The hook is refused (and logged) if the bytes in
//       memory differ, i.e. the exe is not the one the code was recovered from. guardLen 0 = unguarded (logged).
//
//   MS2_EXTERN(va, Signature, name)      typed callable for a not-yet-recovered original function:
//       MS2_EXTERN(0x140768210, void(CRandom* self, UINT seed), CRandom_Seed);  CRandom_Seed(&rnd, 5);
//       Member functions are declared with an explicit `self` first parameter (x64 has one calling
//       convention). Caveat: MSVC member functions returning a class by value use a hidden return pointer
//       *after* `this`; declare those as `Ret* (Self*, Ret* out, args...)`.
//   MS2_GLOBAL(va, Type, name)           reference to an original global:
//       MS2_GLOBAL(0x143aac528, CBufferCryptManager*, g_pBufferCryptManager);
//       g_pBufferCryptManager = p;  Type* p = &g_pBufferCryptManager;  name.get(), name->field, name[i].
//
//   MS2_ORIGINAL(va, Signature)          pointer to the original code (Detours trampoline if `va` is hooked,
//       the original address otherwise) - for calling the original from a replacement or a diff test.
//
// When everything is recovered the same sources are built into a standalone exe with MS2_STANDALONE defined:
// MS2_REPLACE* then expand to nothing and any remaining MS2_EXTERN / MS2_GLOBAL is a compile error
// (= an unrecovered dependency).
//
// Only standard C++ + MSVC extensions: must build with cl 19.16 and clang-cl. Keep it C++14: under cl 19.16 the game
// sources (src/ms2) compile with /std:c++14 (Nexon's flags, cmake/ms2-game-flags.cmake); the hook runtime uses C++17.
#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <new>
#include <type_traits>
#include <utility>

#define MS2_CAT2(a, b) a##b
#define MS2_CAT(a, b) MS2_CAT2(a, b)

namespace ms2 {

constexpr uintptr_t kImageBase = 0x140000000;  // preferred (and, without DYNAMIC_BASE, actual) ImageBase

#ifndef MS2_STANDALONE

// Actual load address minus kImageBase. Set by the hook runtime before any hook is installed.
extern uintptr_t g_imageDelta;

inline void* VaToPtr(uintptr_t va) { return reinterpret_cast<void*>(va + g_imageDelta); }

namespace hook {

// One registered replacement. Static storage, linked into a list at static-init time (before DllMain).
struct Replacement {
    uintptr_t va;           // original function VA (ImageBase 0x140000000)
    void* fn;               // replacement
    const char* name;       // for the log
    const char* file;
    int line;
    uint32_t guardLen;      // 0 = unguarded
    uint32_t guardHash;     // FNV-1a-32 of guardLen original bytes at va
    // filled by the runtime
    Replacement* next;
    void* original;         // trampoline after install, else VaToPtr(va)
    volatile uint64_t* counter;  // call counter (counting stub), may be null
    bool installed;
};

bool Register(Replacement* r);
void* Original(uintptr_t va);         // trampoline if installed, else VaToPtr(va)
void* ReplacementFn(uintptr_t va);    // the registered replacement (bypassing the counting stub) or null
bool IsInstalled(uintptr_t va);
void Log(const char* fmt, ...);       // ms2hook.log next to the exe

namespace detail {
template <class T> struct MethodSig;
template <class C, class R, class... A> struct MethodSig<R (C::*)(A...)> { using Free = R (*)(C*, A...); };
template <class C, class R, class... A> struct MethodSig<R (C::*)(A...) const> { using Free = R (*)(const C*, A...); };
template <class F> inline void* FnToVoid(F f) { return reinterpret_cast<void*>(f); }
inline void* FnToVoid(void* p) { return p; }
// Code address of a pointer to a non-virtual member function of the thunk itself (MS ABI: the first pointer-size
// bytes; multiple-inheritance PMFs append a this-adjustment, which is 0 for a function of the most derived class).
template <class F> inline void* MemberToVoid(F f) {
    static_assert(sizeof(F) >= sizeof(void*), "member function pointer");
    void* p;
    std::memcpy(&p, &f, sizeof p);
    return p;
}
// How a method thunk takes and forwards one by-value argument. A class the callee destroys (non-trivial copy or dtor)
// must reach the method without a copy: copying through the copy ctor and destroying the thunk's own parameter
// released handles twice whose implicit copy adds no reference (Unk_WsR3f0Val, Unk_GaugeRef). The thunk takes the
// object's bytes instead (same Win64 slot: a register for 1/2/4/8 bytes, else a pointer to the caller's object) and
// moves them bitwise into the method's parameter through a prvalue (C++17 elision), so only the method destroys it,
// as the exe's caller expects. Returning a non-trivial class always uses a hidden pointer (rcx for a free function),
// so BitMove(dst, src) has the ABI of T(RawArg<T>*).
template <class T> struct alignas(T) RawArg { unsigned char b[sizeof(T)]; };
template <class T, bool = std::is_class<T>::value &&
                          !(std::is_trivially_copy_constructible<T>::value && std::is_trivially_destructible<T>::value)>
struct ArgPass {
    using Type = T;
    static T&& Get(T& a) { return static_cast<T&&>(a); }
};
template <class T> struct ArgPass<T, true> {
    using Type = RawArg<T>;
    static void* BitMove(void* dst, const void* src) { return std::memcpy(dst, src, sizeof(T)); }
    static T Get(RawArg<T>& a) { return reinterpret_cast<T (*)(RawArg<T>*)>(&BitMove)(&a); }
};
template <class Thunk, class Sig> struct MemberThunk;
template <class Thunk, class C, class R, class... A> struct MemberThunk<Thunk, R (C::*)(A...)> {
    static void* Get() {
        R (Thunk::*p)(typename ArgPass<A>::Type...) = &Thunk::template Call<R, A...>;
        return MemberToVoid(p);
    }
};
template <class Thunk, class C, class R, class... A> struct MemberThunk<Thunk, R (C::*)(A...) const> {
    static void* Get() {
        R (Thunk::*p)(typename ArgPass<A>::Type...) const = &Thunk::template CallC<R, A...>;
        return MemberToVoid(p);
    }
};
}  // namespace detail
}  // namespace hook

template <uintptr_t VA, class Sig> struct Extern;
template <uintptr_t VA, class R, class... A> struct Extern<VA, R(A...)> {
    using Fn = R (*)(A...);
    Fn get() const { return reinterpret_cast<Fn>(VaToPtr(VA)); }
    R operator()(A... a) const { return get()(std::forward<A>(a)...); }
};

template <uintptr_t VA, class T> struct Global {
    T& get() const { return *reinterpret_cast<T*>(VaToPtr(VA)); }
    operator T&() const { return get(); }
    T* operator&() const { return &get(); }
    T* operator->() const { return &get(); }
    template <class U> T& operator=(U&& v) const { return get() = std::forward<U>(v); }
    template <class I> decltype(auto) operator[](I i) const { return get()[i]; }
};

#endif  // !MS2_STANDALONE
}  // namespace ms2

#ifndef MS2_STANDALONE

#define MS2_REPLACE_IMPL(va, fnptr, nameStr, glen, ghash)                                                   \
    static ::ms2::hook::Replacement MS2_CAT(ms2_replacement_, __LINE__){                                   \
        (va), ::ms2::hook::detail::FnToVoid(fnptr), nameStr, __FILE__, __LINE__, (glen), (ghash),          \
        nullptr, nullptr, nullptr, false};                                                                  \
    static const bool MS2_CAT(ms2_registered_, __LINE__) =                                                  \
        ::ms2::hook::Register(&MS2_CAT(ms2_replacement_, __LINE__))

#define MS2_REPLACE(va, function, glen, ghash) MS2_REPLACE_IMPL(va, &function, #function, glen, ghash)

#define MS2_REPLACE_METHOD(va, Class, Method, glen, ghash) MS2_REPLACE_METHOD_VIA(va, Class, Class, Method, glen, ghash)

#define MS2_REPLACE_METHOD_VIA(va, Class, Base, Method, glen, ghash)                                        \
    /* Anonymous namespace: the thunk's template members must have internal linkage. Named only by __LINE__, \
       two units with a registration on the same line and the same signature produced identical COMDAT      \
       symbols and the linker folded them (a hook ran another unit's method: client crash). */              \
    namespace {                                                                                             \
    struct MS2_CAT(ms2_thunk_, __LINE__) : Base {                                                           \
        template <class R, class... A> R Call(typename ::ms2::hook::detail::ArgPass<A>::Type... a) {         \
            return static_cast<Class*>(static_cast<Base*>(this))->Class::Method(                            \
                ::ms2::hook::detail::ArgPass<A>::Get(a)...);                                                \
        }                                                                                                   \
        template <class R, class... A> R CallC(typename ::ms2::hook::detail::ArgPass<A>::Type... a) const { \
            return static_cast<const Class*>(static_cast<const Base*>(this))->Class::Method(                \
                ::ms2::hook::detail::ArgPass<A>::Get(a)...);                                                \
        }                                                                                                   \
    };                                                                                                      \
    }                                                                                                       \
    MS2_REPLACE_IMPL(va,                                                                                    \
        (::ms2::hook::detail::MemberThunk<MS2_CAT(ms2_thunk_, __LINE__), decltype(&Class::Method)>::Get()), \
        #Class "::" #Method, glen, ghash)

#define MS2_REPLACE_OVERLOAD(va, Sig, function, glen, ghash)                                                \
    MS2_REPLACE_IMPL(va, static_cast<::std::add_pointer_t<Sig>>(&function), #function, glen, ghash)

#define MS2_REPLACE_CTOR(va, Class, glen, ghash)                                                            \
    MS2_REPLACE_IMPL(va,                                                                                    \
        static_cast<Class* (*)(Class*)>(                                                                    \
            [](Class* self) -> Class* { return ::new (static_cast<void*>(self)) Class(); }),                \
        #Class "::" #Class, glen, ghash)

#define MS2_REPLACE_DTOR(va, Class, glen, ghash)                                                            \
    MS2_REPLACE_IMPL(va, static_cast<void (*)(Class*)>([](Class* self) { self->Class::~Class(); }),          \
        #Class "::~" #Class, glen, ghash)

#define MS2_EXTERN(va, Sig, name) static constexpr ::ms2::Extern<(va), Sig> name {}
#define MS2_GLOBAL(va, Type, name) static constexpr ::ms2::Global<(va), Type> name {}

#define MS2_ORIGINAL(va, Sig)                                                                               \
    ([]() -> Sig* {                                                                                         \
        static Sig* const p = reinterpret_cast<Sig*>(::ms2::hook::Original(va));                           \
        return p;                                                                                           \
    }())

#else  // MS2_STANDALONE

#define MS2_REPLACE(va, function, glen, ghash) static_assert(true, "")
#define MS2_REPLACE_METHOD(va, Class, Method, glen, ghash) static_assert(true, "")
#define MS2_REPLACE_METHOD_VIA(va, Class, Base, Method, glen, ghash) static_assert(true, "")
#define MS2_REPLACE_OVERLOAD(va, Sig, function, glen, ghash) static_assert(true, "")
#define MS2_REPLACE_CTOR(va, Class, glen, ghash) static_assert(true, "")
#define MS2_REPLACE_DTOR(va, Class, glen, ghash) static_assert(true, "")
#define MS2_EXTERN(va, Sig, name) static_assert(false, "unrecovered function " #va " (" #name ")")
#define MS2_GLOBAL(va, Type, name) static_assert(false, "unrecovered global " #va " (" #name ")")
#define MS2_ORIGINAL(va, Sig) static_assert(false, "MS2_ORIGINAL is hook-DLL only")

#endif  // MS2_STANDALONE
