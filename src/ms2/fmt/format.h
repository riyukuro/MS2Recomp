// fmt/format.h - RECREATED subset of the C++ Format library (cppformat / fmt 2.x era) as the game links it.
// NOT the original header: only what the game's template instances need, written so that cl 19.16 /Od emits the
// same per-unit COMDATs. Evidence (KMS2_DEV x64):
//   - RTTI fmt::FormatError, fmt::SystemError, fmt::WindowsError, fmt::internal::RuntimeError; fmt's messages
//     ("cannot switch from manual to automatic argument indexing", "missing '}' in format string", ...).
//   - The non-variadic FMT_VARIADIC emulation is in use (FMT_USE_VARIADIC_TEMPLATES 0): make_type takes 15
//     by-value ArgType parameters (0x14016d660), ArgType() 0x140163e80, ArgList(types, values) 0x140163e50.
//   - Arg::Type values (from the static MakeValue::type overloads): INT 1 (0x14016d950), UINT 2 (0x14016d960,
//     unsigned short 0x14020c260), ULONG_LONG 4 (0x1401df3c0), CSTRING 9 (0x1401d49f0), STRING 10 (CString,
//     0x14016d940). The other enumerators' positions are inferred (one extra type between ULONG_LONG and CSTRING;
//     taken as BOOL like fmt 3.0, but without fmt 3.0's NAMED_ARG).
//   - Value is 16 bytes and MakeValue<F> derives from Value directly (16-byte temporaries in the wrappers).
//   - Nexon additions: MakeValue(const CString&) / MakeValue(const CStringW&) (string.value/size from the CString).
// Template instances per unit: see ms2/ms2format.h.
#pragma once
#include <wchar.h>
// MS2: set_string(const wchar_t*) 0x14020c220 calls the imported wcslen (`call [__imp_wcslen]`, no /Oi inline loop).
// The static-CRT headers declare wcslen without dllimport, so the IAT slot is reached through its own symbol.
extern "C" size_t (__cdecl* __imp_wcslen)(const wchar_t*);

#include <cstddef>
#include <memory>
#include <string>
#include <type_traits>

namespace fmt {

typedef __int64 LongLong;
typedef unsigned __int64 ULongLong;

template <typename Char>
class BasicFormatter;
template <typename Char>
class BasicStringRef;
template<class Char, class T>
void format_arg(BasicFormatter<Char>&, const Char*&, const T&);

namespace internal {

template <typename Char>
struct StringValue
{
    const Char* value;
    std::size_t size;
};

typedef void (*FormatFunc)(void* formatter, const void* arg, void* format_str_ptr);

struct CustomValue
{
    const void* value;
    FormatFunc format;
};

// A formatting argument value.
struct Value
{
    union {
        int int_value;
        unsigned uint_value;
        LongLong long_long_value;
        ULongLong ulong_long_value;
        double double_value;
        long double long_double_value;
        const void* pointer;
        StringValue<char> string;
        StringValue<signed char> sstring;
        StringValue<unsigned char> ustring;
        StringValue<wchar_t> wstring;
        CustomValue custom;
    };
};

// A formatting argument. It is a POD type to allow storage in internal::MemoryBuffer.
struct Arg : Value
{
    enum Type {
        NONE,
        // Integer types should go first,
        INT, UINT, LONG_LONG, ULONG_LONG, BOOL, CHAR, LAST_INTEGER_TYPE = CHAR,
        // followed by floating-point types.
        DOUBLE, LONG_DOUBLE, LAST_NUMERIC_TYPE = LONG_DOUBLE,
        CSTRING, STRING, WSTRING, POINTER, CUSTOM
    };
    Type type;
};

// Makes a Value object from any type.
template <typename Formatter>
class MakeValue : public Value
{
public:
    typedef typename Formatter::Char Char;

    void set_string(const CString& str)
    {
        string.value = str;
        string.size = str.GetLength();
    }

    MakeValue() {}

    void set_string(const CStringW& str)
    {
        Convert(0);                                                 // MS2: 0x1401d0dd0 (wide instance) calls Convert(0)
        wstring.value = str;
        wstring.size = str.GetLength();
    }

#define FMT_MAKE_VALUE_(Type, field, TYPE, rhs) \
    MakeValue(Type value) { field = rhs; } \
    static ULongLong type(Type) { return Arg::TYPE; }

#define FMT_MAKE_VALUE(Type, field, TYPE) \
    FMT_MAKE_VALUE_(Type, field, TYPE, value)

    FMT_MAKE_VALUE(bool, int_value, BOOL)
    FMT_MAKE_VALUE(short, int_value, INT)
    FMT_MAKE_VALUE(unsigned short, uint_value, UINT)
    FMT_MAKE_VALUE(int, int_value, INT)
    FMT_MAKE_VALUE(unsigned, uint_value, UINT)
    FMT_MAKE_VALUE(LongLong, long_long_value, LONG_LONG)
    FMT_MAKE_VALUE(ULongLong, ulong_long_value, ULONG_LONG)
    FMT_MAKE_VALUE(float, double_value, DOUBLE)
    FMT_MAKE_VALUE(double, double_value, DOUBLE)
    FMT_MAKE_VALUE(long double, long_double_value, LONG_DOUBLE)
    FMT_MAKE_VALUE(signed char, int_value, CHAR)
    FMT_MAKE_VALUE(unsigned char, uint_value, CHAR)
    FMT_MAKE_VALUE(char, int_value, CHAR)

    // MS2: long / unsigned long are distinct types on MSVC; sizeof(long) is checked at run time (/Od).
    // Proven by timeutil.cpp: MakeValue(long) 0x14086d170 (type INT), MakeValue(unsigned long) 0x1402e1a20 (type UINT).
    MakeValue(long value) { if(sizeof(long) == sizeof(int)) int_value = value; else long_long_value = value; }
    static ULongLong type(long) { return Arg::INT; }
    MakeValue(unsigned long value) { if(sizeof(unsigned long) == sizeof(unsigned)) uint_value = value; else ulong_long_value = value; }
    static ULongLong type(unsigned long) { return Arg::UINT; }

    // MS2: wide log severity letters use CHAR, not integral formatting.
    static wchar_t Convert(wchar_t value) { return value; }
    MakeValue(wchar_t value) { int_value = Convert(value); }
    // Proven by logstring 0x14065b030: wide character tag is 5. The older shared
    // BOOL/CHAR enum names are inferred; leave existing users unchanged for now.
    static ULongLong type(wchar_t) { return 5; }

    FMT_MAKE_VALUE(char*, string.value, CSTRING)
    FMT_MAKE_VALUE(const char*, string.value, CSTRING)
    // MS2: wide literal arguments. MakeValue(const wchar_t*) 0x14020a410 calls set_string 0x14020c220, which is
    // Convert(0) (result unused), value = s, size = wcslen(s). The tags below keep the window logic of progress.py
    // from claiming the neighbouring one-liners.
    static ULongLong type(const wchar_t*) { return Arg::WSTRING; }
    // @0x14020a410
    MakeValue(const wchar_t* value) { set_string(value); }
    // @0x14020c220
    void set_string(const wchar_t* str) { Convert(0); wstring.value = str; wstring.size = __imp_wcslen(str); }
    //
    //
    //
    //
    //
    //

#define FMT_MAKE_STR_VALUE(Type, TYPE) \
    MakeValue(Type value) { set_string(value); } \
    static ULongLong type(Type) { return Arg::TYPE; }

    FMT_MAKE_STR_VALUE(const CString&, STRING)
    FMT_MAKE_STR_VALUE(const CStringW&, WSTRING)    // MS2: type 11, 0x1401d0e90 (uiworldchampionrewarddialog.cpp)

    // MS2: std::wstring arguments (the ostream path of format_arg, additionalactionadditional.cpp): MakeValue
    // 0x140182090 builds a WStringRef temporary and calls set_string(WStringRef) 0x140190fe0.
    void set_string(BasicStringRef<wchar_t> str)
    {
        Convert(0);
        wstring.value = str.c_str();
        wstring.size = str.size();
    }
    MakeValue(const std::basic_string<wchar_t>& value) { set_string(value); }

    // MS2: std::string arguments (commonfiles\imagehttpclient.cpp, wide formatter): MakeValue 0x140517490 builds a
    // BasicStringRef<char> (0x1402d8580) and calls set_string 0x14051a110 (value, size; no Convert). make_type returns
    // STRING (10) / WSTRING (11) through the one-line functions 0x14051a150 / 0x14051a160.
    // @0x14051a110
    void set_string(BasicStringRef<char> str) { string.value = str.c_str(); string.size = str.size(); }
    // @0x140517490
    MakeValue(const std::string& value) { set_string(value); }
    // @0x14051a150
    static ULongLong type(const std::string&) { return Arg::STRING; }
    // @0x14051a160
    static ULongLong type(const std::basic_string<wchar_t>&) { return Arg::WSTRING; }

    FMT_MAKE_VALUE(void*, pointer, POINTER)
    FMT_MAKE_VALUE(const void*, pointer, POINTER)

    // MS2: enum arguments use the formatter customization path (log categories).
    template<class T> static void FormatCustomArg(void* formatter, const void* value, void* format) {
        format_arg(*static_cast<Formatter*>(formatter), *static_cast<const Char**>(format), *static_cast<const T*>(value));
    }
    template<class T, typename std::enable_if<std::is_enum<T>::value, int>::type = 0>
    MakeValue(const T& value) { custom.value = &value; custom.format = &FormatCustomArg<T>; }
    template<class T, typename std::enable_if<std::is_enum<T>::value, int>::type = 0>
    static ULongLong type(const T&) { return Arg::CUSTOM; }
};

}  // namespace internal

// An argument list.
class ArgList
{
private:
    // To reduce compiled code size per formatting function call, types of first
    // MAX_PACKED_ARGS arguments are passed in the types_ field.
    ULongLong types_;
    const internal::Value* values_;

public:
    // Maximum number of arguments with packed types.
    enum { MAX_PACKED_ARGS = 16 };

    ArgList() : types_(0) {}
    ArgList(ULongLong types, const internal::Value* values) : types_(types), values_(values) {}
};

template <typename Char, typename Allocator>
class BasicWriter;

// A string reference: a pointer and a length (0 = not computed yet), as in cppformat 1.x.
template <typename Char>
class BasicStringRef
{
public:
    BasicStringRef(const Char* s, std::size_t size = 0) : data_(s), size_(size) {}   // 0x1401cfc90 (wide)
    BasicStringRef(const std::basic_string<Char>& s) : data_(s.c_str()), size_(s.size()) {}   // 0x140181c70 (wide)
    const Char* c_str() const { return data_; }
    // The size is computed on first use (0x140191020, wide).
    std::size_t size() const
    {
        if (size_ == 0 && data_)
            size_ = std::char_traits<Char>::length(data_);
        return size_;
    }
    const Char* data_;
    mutable std::size_t size_;
};
typedef BasicStringRef<wchar_t> WStringRef;

namespace internal {

// MS2: base of BasicFormatter, 0x18 bytes (the argument list and the next automatic argument index);
// the default constructor 0x1401cff40 only default-constructs the ArgList (0x140183290 stores types_ = 0).
class FormatterBase
{
public:
    FormatterBase() : args_() {}
    ArgList args_;
    int next_arg_index_;
};

}  // namespace internal

template <typename Char>
class BasicFormatter : private internal::FormatterBase
{
public:
    typedef Char Char;
    explicit BasicFormatter(BasicWriter<Char, std::allocator<Char> >& w) : writer_(w) {}   // 0x1401cfc60 (wide)
    const Char* format(const Char*&, const internal::Arg&);
    // MS2: BasicFormatter<wchar_t>::format(WStringRef, const ArgList&) 0x1402daa70, not recovered.
    void FUN_1402daa70(BasicStringRef<Char> format, const ArgList& args);
private:
    BasicWriter<Char, std::allocator<Char> >& writer_;              // +0x18
    const Char* start_;                                             // +0x20
};

// MS2-FUNCTIONAL: enum customization preserves numeric rendering without unused scratch storage.
// Verified for the wide log-category instance at 0x140657f80.
template<class Char, class T>
inline void format_arg(BasicFormatter<Char>& formatter, const Char*& format, const T& value)
{
    internal::Arg arg;
    arg.int_value = static_cast<int>(value);
    arg.type = internal::Arg::INT;
    format = formatter.format(format, arg);
}

namespace internal {

template <typename T>
inline ULongLong make_type(const T& arg)
{
    return MakeValue< BasicFormatter<char> >::type(arg);
}

template <std::size_t N>
struct ArgArray
{
    typedef Value Type[N > 0 ? N : 1];
};

struct ArgType
{
    ULongLong type;

    ArgType() : type(0) {}

    template <typename T>
    ArgType(const T& arg) : type(make_type(arg)) {}
};

#define FMT_ARG_TYPE_DEFAULT(n) ArgType t##n = ArgType()

inline ULongLong make_type(ArgType t0 = ArgType(), ArgType t1 = ArgType(), ArgType t2 = ArgType(),
                           ArgType t3 = ArgType(), ArgType t4 = ArgType(), ArgType t5 = ArgType(),
                           ArgType t6 = ArgType(), ArgType t7 = ArgType(), ArgType t8 = ArgType(),
                           ArgType t9 = ArgType(), ArgType t10 = ArgType(), ArgType t11 = ArgType(),
                           ArgType t12 = ArgType(), ArgType t13 = ArgType(), ArgType t14 = ArgType())
{
    return t0.type | (t1.type << 4) | (t2.type << 8) | (t3.type << 12) | (t4.type << 16) | (t5.type << 20) |
           (t6.type << 24) | (t7.type << 28) | (t8.type << 32) | (t9.type << 36) | (t10.type << 40) |
           (t11.type << 44) | (t12.type << 48) | (t13.type << 52) | (t14.type << 56);
}

}  // namespace internal
}  // namespace fmt

// The FMT_VARIADIC emulation (fmt's FMT_GEN/FMT_WRAP macros, non-variadic branch).
#define FMT_GEN(n, f) FMT_GEN##n(f)
#define FMT_GEN1(f)  f(0)
#define FMT_GEN2(f)  FMT_GEN1(f),  f(1)
#define FMT_GEN3(f)  FMT_GEN2(f),  f(2)
#define FMT_GEN4(f)  FMT_GEN3(f),  f(3)
#define FMT_GEN5(f)  FMT_GEN4(f),  f(4)
#define FMT_GEN6(f)  FMT_GEN5(f),  f(5)
#define FMT_GEN7(f)  FMT_GEN6(f),  f(6)
#define FMT_GEN8(f)  FMT_GEN7(f),  f(7)
#define FMT_GEN9(f)  FMT_GEN8(f),  f(8)
#define FMT_GEN10(f) FMT_GEN9(f),  f(9)
#define FMT_GEN11(f) FMT_GEN10(f), f(10)
#define FMT_GEN12(f) FMT_GEN11(f), f(11)
#define FMT_GEN13(f) FMT_GEN12(f), f(12)
#define FMT_GEN14(f) FMT_GEN13(f), f(13)
#define FMT_GEN15(f) FMT_GEN14(f), f(14)

#define FMT_MAKE_TEMPLATE_ARG(n) typename T##n
#define FMT_MAKE_ARG(n) const T##n& v##n
#define FMT_MAKE_REF2(n) v##n
#define FMT_MAKE_REF_char(n) fmt::internal::MakeValue< fmt::BasicFormatter<char> >(v##n)
#define FMT_MAKE_REF_wchar_t(n) fmt::internal::MakeValue< fmt::BasicFormatter<wchar_t> >(v##n)

// A wrapper for `ReturnType func(Arg1 arg1, fmt::ArgList)` taking n further arguments of arbitrary types.
#define FMT_WRAP1(Char, ReturnType, func, Arg1, n) \
    template <FMT_GEN(n, FMT_MAKE_TEMPLATE_ARG)> \
    inline ReturnType func(Arg1 arg1, FMT_GEN(n, FMT_MAKE_ARG)) \
    { \
        const fmt::internal::ArgArray<n>::Type array = {FMT_GEN(n, FMT_MAKE_REF_##Char)}; \
        return func(arg1, fmt::ArgList(fmt::internal::make_type(FMT_GEN(n, FMT_MAKE_REF2)), array)); \
    }

#define FMT_VARIADIC_(Char, ReturnType, func, Arg1) \
    FMT_WRAP1(Char, ReturnType, func, Arg1, 1) FMT_WRAP1(Char, ReturnType, func, Arg1, 2) \
    FMT_WRAP1(Char, ReturnType, func, Arg1, 3) FMT_WRAP1(Char, ReturnType, func, Arg1, 4) \
    FMT_WRAP1(Char, ReturnType, func, Arg1, 5) FMT_WRAP1(Char, ReturnType, func, Arg1, 6) \
    FMT_WRAP1(Char, ReturnType, func, Arg1, 7) FMT_WRAP1(Char, ReturnType, func, Arg1, 8) \
    FMT_WRAP1(Char, ReturnType, func, Arg1, 9) FMT_WRAP1(Char, ReturnType, func, Arg1, 10) \
    FMT_WRAP1(Char, ReturnType, func, Arg1, 11) FMT_WRAP1(Char, ReturnType, func, Arg1, 12) \
    FMT_WRAP1(Char, ReturnType, func, Arg1, 13) FMT_WRAP1(Char, ReturnType, func, Arg1, 14) \
    FMT_WRAP1(Char, ReturnType, func, Arg1, 15)

#define FMT_VARIADIC(ReturnType, func, Arg1) FMT_VARIADIC_(char, ReturnType, func, Arg1)
#define FMT_VARIADIC_W(ReturnType, func, Arg1) FMT_VARIADIC_(wchar_t, ReturnType, func, Arg1)
