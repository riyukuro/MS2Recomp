// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Crypto++ 5.6.2 functions that the engine-stage gb:CryptoPP/*
// TUs leave as stubs because the exe's copy was folded or compiled with different codegen than the in-tree source.
// MS2-UNIT: lib_cryptopp_code
// MS2-RANGE: 0x1423056e0-0x142305701 .text$mn
// MS2-RANGE: 0x142305710-0x142305731 .text$mn
// MS2-RANGE: 0x142311c70-0x142311cf1 .text$mn
// MS2-RANGE: 0x1423140b0-0x1423140e6 .text$mn
// MS2-RANGE: 0x14235bce0-0x14235bda1 .text$mn
// MS2-RANGE: 0x14235df70-0x14235dff1 .text$mn
// MS2-RANGE: 0x1423697c0-0x1423697f6 .text$mn
// MS2-RANGE: 0x14237b650-0x14237b711 .text$mn
// MS2-RANGE: 0x1423729e0-0x142372b90 .text$mn
// MS2-RANGE: 0x142372d60-0x142372f10 .text$mn
// MS2-RANGE: 0x142372f20-0x1423730d1 .text$mn
// MS2-RANGE: 0x14235a130-0x14235a27d .text$mn
// MS2-RANGE: 0x14235c730-0x14235ca92 .text$mn
// MS2-RANGE: 0x1423537e0-0x14235382a .text$mn
// MS2-RANGE: 0x142353830-0x14235387a .text$mn
// MS2-RANGE: 0x14235c2d0-0x14235c6a9 .text$mn
// MS2-RANGE: 0x14237bef0-0x14237c166 .text$mn
// MS2-RANGE: 0x1423770a0-0x1423772e3 .text$mn
// MS2-RANGE: 0x1423772f0-0x142377533 .text$mn
// MS2-RANGE: 0x1423798d0-0x142379af4 .text$mn
// MS2-RANGE: 0x142353790-0x142353796 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include <new>

#include <string>
#include <istream>
#include <ostream>
std::string* FUN_1401d2620(std::string* dst, const char* src);   // std::string(const char*)
extern const char DAT_14311c1e0[];
extern const char DAT_14311c638[];
extern const char DAT_14312d8d8[];
extern const char DAT_143130c28[];

// @0x1423056e0
std::string* FUN_1423056e0(void* self, std::string* out)
{
    FUN_1401d2620(out, DAT_14311c1e0);
    return out;
}

// @0x142305710
std::string* FUN_142305710(void* self, std::string* out)
{
    FUN_1401d2620(out, DAT_14311c638);
    return out;
}

// CryptoPP::AlgorithmParametersTemplate<int-sized T>: base (AlgorithmParametersBase) + m_value at +0x20
struct CppParamBase { void* vptr; char pad[0x18]; };
struct CppIntParam : CppParamBase { int m_value; };
typedef bool (*AssignIntFn)(const std::type_info&, void*, const void*);
extern AssignIntFn DAT_143b0dc90;                 // CryptoPP::g_pAssignIntToInteger
extern const std::type_info DAT_143a57d68;        // typeid(int)
extern const std::type_info DAT_143aa1220;        // typeid(T) of the first instantiation
extern const std::type_info DAT_143aa7a80;        // typeid(T) of the second instantiation
void FUN_140390ef0(const char* name, const std::type_info& t1, const std::type_info& t2);   // ThrowIfTypeMismatch
void FUN_14038dff0(void* dst, const void* src);   // AlgorithmParametersBase copy ctor
extern char DAT_14311ee90[];                      // vftable of the first instantiation
extern char DAT_14312dbf8[];                      // vftable of the second instantiation

// @0x142311c70
void FUN_142311c70(CppIntParam* self, const char* name, const std::type_info& valueType, void* pValue)
{
    if (!(DAT_143b0dc90 != 0 && DAT_143aa1220 == DAT_143a57d68 && DAT_143b0dc90(valueType, pValue, &self->m_value)))
    {
        FUN_140390ef0(name, DAT_143aa1220, valueType);
        *(int*)pValue = self->m_value;
    }
}

// @0x14235df70
void FUN_14235df70(CppIntParam* self, const char* name, const std::type_info& valueType, void* pValue)
{
    if (!(DAT_143b0dc90 != 0 && DAT_143aa7a80 == DAT_143a57d68 && DAT_143b0dc90(valueType, pValue, &self->m_value)))
    {
        FUN_140390ef0(name, DAT_143aa7a80, valueType);
        *(int*)pValue = self->m_value;
    }
}

// @0x1423140b0
void FUN_1423140b0(CppIntParam* self, CppIntParam* dst)
{
    FUN_14038dff0(dst, self);
    dst->vptr = DAT_14311ee90;
    dst->m_value = self->m_value;
}

// @0x1423697c0
void FUN_1423697c0(CppIntParam* self, CppIntParam* dst)
{
    FUN_14038dff0(dst, self);
    dst->vptr = DAT_14312dbf8;
    dst->m_value = self->m_value;
}

#include <string>
#include <exception>

extern char DAT_142d30650[];   // vftable of the exe's CryptoPP::Exception base
extern char DAT_14312d848[];   // vftable of the first Exception subclass
extern char DAT_143130c18[];   // vftable of the second Exception subclass

// CryptoPP::Exception: vptr + two zeroed words + m_errorType + m_what, as the exe's copy lays it out
struct CppCryptoException
{
    void* vptr;
    void* m_whatPtr;
    void* m_doFree;
    int m_errorType;
    std::string m_what;
    CppCryptoException(int type, const std::string& s) : vptr(DAT_142d30650), m_whatPtr(0), m_doFree(0), m_errorType(type), m_what(s) {}
};
// a std::string temporary whose constructor is the out-of-line one
struct CppTempString
{
    union { std::string s; };
    CppTempString() {}
    CppTempString(const char* p) { FUN_1401d2620(&s, p); }
    ~CppTempString() { s.~basic_string(); }
};
// Crypto++ exception subclasses; the derived vftable is stored last
struct CppCryptoExceptionA : CppCryptoException
{
    CppCryptoExceptionA() : CppCryptoException(4, CppTempString(DAT_14312d8d8).s) { vptr = DAT_14312d848; }
};
struct CppCryptoExceptionB : CppCryptoException
{
    CppCryptoExceptionB() : CppCryptoException(6, CppTempString(DAT_143130c28).s) { vptr = DAT_143130c18; }
};

// MS2-FUNCTIONAL: identical but for the exe's /GS cookie (its string temporary is a GS buffer; our union temporary is not)
// @0x14235bce0
CppCryptoExceptionA* FUN_14235bce0(CppCryptoExceptionA* self)
{
    return new (self) CppCryptoExceptionA();
}

// MS2-FUNCTIONAL: identical but for the exe's /GS cookie (its string temporary is a GS buffer; our union temporary is not)
// @0x14237b650
CppCryptoExceptionB* FUN_14237b650(CppCryptoExceptionB* self)
{
    return new (self) CppCryptoExceptionB();
}

// CryptoPP::AssignFromHelperClass<T, BASE>: if the source holds "ThisObject:<T>" copy it, else let BASE assign
struct CppNameValuePairs
{
    virtual void v0();
    virtual bool GetVoidValue(const char* name, const std::type_info& valueType, void* pValue) const;
};
struct CppAssignHelper
{
    void* m_pObject;
    const CppNameValuePairs* m_source;
    bool m_done;
};
extern const char DAT_14312b860[];
extern const std::type_info DAT_143aa7e90;
extern const std::type_info DAT_143aa1e90;
extern const std::type_info DAT_143aa7e20;
extern const std::type_info DAT_143aa1de0;
extern const std::type_info DAT_143aa1d00;
void FUN_14232fe10(void* pObject, const CppNameValuePairs* source);
void FUN_1423306d0(void* pObject, const CppNameValuePairs* source);
void FUN_142375640(void* pObject, const CppNameValuePairs* source);

// NameValuePairs::GetThisObject: GetValue("ThisObject:" + typeid(T).name(), object)
static __forceinline bool CppGetThisObject(const CppNameValuePairs* source, const std::type_info& t, void* pObject)
{
    CppTempString base;
    std::string& b = *FUN_1401d2620(&base.s, DAT_14312b860);
    return source->GetVoidValue((std::move(b) + t.name()).c_str(), t, pObject);
}

// MS2-FUNCTIONAL: same calls and logic; the string temporaries sit in swapped stack slots and are destroyed in a different order (the exe puts the operator+ result below the base string)
// @0x1423729e0
CppAssignHelper* FUN_1423729e0(CppAssignHelper* self, void* pObject, const CppNameValuePairs* source)
{
    self->m_pObject = pObject;
    self->m_source = source;
    self->m_done = false;
    if (CppGetThisObject(source, DAT_143aa7e90, pObject))
        self->m_done = true;
    else if (DAT_143aa1e90 != DAT_143aa7e90)
        FUN_14232fe10(pObject, source);
    return self;
}

// MS2-FUNCTIONAL: same calls and logic; the string temporaries sit in swapped stack slots and are destroyed in a different order (the exe puts the operator+ result below the base string)
// @0x142372d60
CppAssignHelper* FUN_142372d60(CppAssignHelper* self, void* pObject, const CppNameValuePairs* source)
{
    self->m_pObject = pObject;
    self->m_source = source;
    self->m_done = false;
    if (CppGetThisObject(source, DAT_143aa7e20, pObject))
        self->m_done = true;
    else if (DAT_143aa1de0 != DAT_143aa7e20)
        FUN_1423306d0(pObject, source);
    return self;
}

// MS2-FUNCTIONAL: same calls and logic; the string temporaries sit in swapped stack slots and are destroyed in a different order (the exe puts the operator+ result below the base string)
// @0x142372f20
CppAssignHelper* FUN_142372f20(CppAssignHelper* self, char* pObject, const CppNameValuePairs* source)
{
    self->m_pObject = pObject;
    self->m_source = source;
    self->m_done = false;
    if (CppGetThisObject(source, DAT_143aa1d00, pObject))
        self->m_done = true;
    else if (DAT_143aa1d00 != DAT_143aa1d00)
        FUN_142375640(pObject + 0x50, source);
    return self;
}

// CryptoPP::Integer, as far as DL_PrivateKeyImpl<...>::GenerateRandom needs it: ASN1Object vptr + SecBlock + sign
void FUN_142308be0(void* p);   // CryptoPP::UnalignedDeallocate
struct CppInteger
{
    void* vptr;
    char alloc[8];
    size_t m_size;
    unsigned long long* m_ptr;
    int sign;
    ~CppInteger()
    {
        for (size_t i = 0; i < m_size; ++i)
            m_ptr[i] = 0;
        FUN_142308be0(m_ptr);
    }
};
CppInteger* FUN_14235a970(CppInteger* out, void* rng, const CppInteger* min, const CppInteger* max, int type, const CppInteger* equiv, const CppInteger* mod); // Integer(rng, min, max, type, equiv, mod)
const CppInteger* FUN_14236a270();   // Integer::One()
const CppInteger* FUN_14236cea0();   // Integer::Zero()

struct CppGroupParams
{
    virtual void GenerateRandom(void* rng, const CppNameValuePairs* params) {}
};
struct CppAbstractGroupParams
{
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual CppInteger* GetMaxExponent(CppInteger* out) const;   // vtable +0x48
};
struct CppKeyObj
{
    virtual CppAbstractGroupParams* GetAbstractGroupParameters();
    virtual void v1();
    virtual void v2();
    virtual void SetPrivateExponent(const CppInteger* x);   // vtable +0x18
    char pad[8];
};
struct CppKeyGroupPart
{
    char pad[0x60];
    void* groupObject;
    CppGroupParams group;
};
struct CppDLPrivateKey : CppKeyObj, CppKeyGroupPart {};
extern const std::type_info DAT_143aa1768;
extern const std::type_info DAT_143aa3860;

// DL_PrivateKeyImpl<GP>::GenerateRandom: take the group parameters from the source if it carries them, else generate them; x = random in [1, max exponent]
static __forceinline void CppDLGenerateRandom(CppDLPrivateKey& key, void* rng, const CppNameValuePairs* params, const std::type_info& gpType)
{
    if (!CppGetThisObject(params, gpType, &key.groupObject))
        key.group.GenerateRandom(rng, params);
    CppInteger maxExp;
    key.GetAbstractGroupParameters()->GetMaxExponent(&maxExp);
    CppInteger x;
    FUN_14235a970(&x, rng, FUN_14236a270(), &maxExp, 0, FUN_14236cea0(), FUN_14236a270());
    key.SetPrivateExponent(&x);
}

// MS2-FUNCTIONAL: same calls and logic; the temporaries are laid out differently (/GS cookie, string/Integer slot sharing)
// @0x1423770a0
void FUN_1423770a0(CppKeyGroupPart* sub, void* rng, const CppNameValuePairs* params)
{
    __assume(sub != nullptr);
    CppDLGenerateRandom(*static_cast<CppDLPrivateKey*>(sub), rng, params, DAT_143aa1768);
}

// MS2-FUNCTIONAL: same calls and logic; the temporaries are laid out differently (/GS cookie, string/Integer slot sharing)
// @0x1423772f0
void FUN_1423772f0(CppKeyGroupPart* sub, void* rng, const CppNameValuePairs* params)
{
    __assume(sub != nullptr);
    CppDLGenerateRandom(*static_cast<CppDLPrivateKey*>(sub), rng, params, DAT_143aa3860);
}

// HMAC<SHA1>::StaticAlgorithmName: "HMAC(" + SHA1::StaticAlgorithmName() + ")"
// MS2-FUNCTIONAL: same string building; the /GS cookie differs (our string temporaries are not GS buffers)
// @0x1423798d0
std::string* FUN_1423798d0(std::string* out)
{
    CppTempString head("HMAC(");
    return new (out) std::string(std::move(std::move(head.s) + "SHA-1") + ")");
}

extern int DAT_143b10184;   // CryptoPP cached CPU feature value (cache line size)

// @0x142353790
int FUN_142353790()
{
    return DAT_143b10184;
}

// std::ws<char>(std::istream&): the STL's own instantiation (skip leading whitespace; used by Crypto++ Integer text parsing)
// MS2-FUNCTIONAL: inlined STL stream code calls dllimported msvcp140 functions, so the instantiation cannot byte-match
// MS2-PIN: ??$ws@DU?$char_traits@D@std@@@std@@YAAEAV?$basic_istream@DU?$char_traits@D@std@@@0@AEAV10@@Z 0x14235a130
template std::istream& std::ws<char, std::char_traits<char> >(std::istream&);

namespace CryptoPP
{
void* UnalignedAllocate(size_t size);
void UnalignedDeallocate(void* p);
struct PolynomialMod2
{
    void* vptr;
    size_t m_size;       // 64-bit words
    unsigned long long* m_ptr;
    unsigned BitCount() const;
    bool GetBit(unsigned n) const { return (n >> 6) < m_size ? ((m_ptr[n >> 6] >> (n & 63)) & 1) != 0 : false; }
    bool IsZero() const
    {
        for (size_t i = 0; i < m_size; ++i)
            if (m_ptr[i])
                return false;
        return true;
    }
};
}

// MS2-FUNCTIONAL: same text output (base from ios flags, digit grouping, suffix); register allocation and the inlined STL flag reads differ
// operator<<(std::ostream&, const PolynomialMod2&): bit string in binary/octal/hex groups with a b/o/h suffix
// @0x14237bef0
std::ostream& FUN_14237bef0(std::ostream& out, const CryptoPP::PolynomialMod2& a)
{
    unsigned bits, block;
    char suffix;
    switch (out.flags() & std::ios::basefield)
    {
    case std::ios::oct: bits = 3; block = 4; suffix = 'o'; break;
    case std::ios::hex: bits = 4; block = 2; suffix = 'h'; break;
    default:            bits = 1; block = 8; suffix = 'b'; break;
    }
    if (a.IsZero())
        return out << '0' << suffix;
    size_t n = a.BitCount() / bits + 1;
    char* s = static_cast<char*>(CryptoPP::UnalignedAllocate(n));
    const char* vec = (out.flags() & std::ios::uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";
    unsigned i = 0;
    for (; i * bits < a.BitCount(); i++)
    {
        unsigned digit = 0;
        for (unsigned j = 0; j < bits; j++)
            digit |= static_cast<unsigned>(a.GetBit(i * bits + j)) << j;
        s[i] = vec[digit];
    }
    while (i--)
    {
        out << s[i];
        if (i && (i % block) == 0)
            out << ',';
    }
    std::ostream& r = out << suffix;
    for (size_t k = 0; k < n; ++k)
        s[k] = 0;
    CryptoPP::UnalignedDeallocate(s);
    return r;
}

CppInteger* FUN_14235adf0(CppInteger* self, const CppInteger* t);                       // Integer(const Integer&)
CppInteger* FUN_14235b7f0(CppInteger* self);                                            // Integer()
unsigned long long FUN_142366480(unsigned long long* remainder, CppInteger* quotient, const CppInteger* dividend, unsigned long long divisor);  // Integer::Divide(word&, Integer&, const Integer&, word)

static size_t CppIntegerWords(const CppInteger& v)
{
    size_t n = v.m_size;
    while (n && v.m_ptr[n - 1] == 0)
        --n;
    return n;
}

static unsigned CppIntegerBitCount(const CppInteger& v)
{
    size_t n = CppIntegerWords(v);
    if (!n)
        return 0;
    unsigned bits = 0;
    for (unsigned long long top = v.m_ptr[n - 1]; top; top >>= 1)
        ++bits;
    return static_cast<unsigned>((n - 1) * 64) + bits;
}

static void CppIntegerSwap(CppInteger& x, CppInteger& y)
{
    char tmp[sizeof(x.alloc)];
    for (size_t i = 0; i < sizeof(tmp); ++i) { tmp[i] = x.alloc[i]; x.alloc[i] = y.alloc[i]; y.alloc[i] = tmp[i]; }
    size_t sz = x.m_size; x.m_size = y.m_size; y.m_size = sz;
    unsigned long long* p = x.m_ptr; x.m_ptr = y.m_ptr; y.m_ptr = p;
    int sg = x.sign; x.sign = y.sign; y.sign = sg;
}

// MS2-FUNCTIONAL: same text output (base from ios flags, repeated word division, digit buffer); our member layout/inlining of the Integer helpers differs
// operator<<(std::ostream&, const Integer&): decimal ('.' suffix), octal ('o') or hex ('h') digits
// @0x14235c730
std::ostream& FUN_14235c730(std::ostream& out, const CppInteger& a)
{
    unsigned base;
    char suffix;
    switch (out.flags() & std::ios::basefield)
    {
    case std::ios::oct: base = 8; suffix = 'o'; break;
    case std::ios::hex: base = 16; suffix = 'h'; break;
    default:            base = 10; suffix = '.'; break;
    }
    CppInteger temp1;
    FUN_14235adf0(&temp1, &a);
    CppInteger temp2;
    FUN_14235b7f0(&temp2);
    if (a.sign == 1)
    {
        out << '-';
        if (temp1.sign == 1 || CppIntegerWords(temp1) != 0)    // temp1.Negate(): flips unless !temp1
            temp1.sign = 1 - temp1.sign;
    }
    if (a.sign != 1 && CppIntegerWords(a) == 0)
        out << '0';
    unsigned bitsPerDigit = 0;
    for (unsigned b = base; b; b >>= 1)
        ++bitsPerDigit;
    size_t n = CppIntegerBitCount(a) / (bitsPerDigit - 1) + 1;
    char* s = static_cast<char*>(CryptoPP::UnalignedAllocate(n));
    const char* vec = (out.flags() & std::ios::uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";
    unsigned i = 0;
    while (temp1.sign == 1 || CppIntegerWords(temp1) != 0)
    {
        unsigned long long digit;
        FUN_142366480(&digit, &temp2, &temp1, base);
        s[i++] = vec[digit];
        CppIntegerSwap(temp1, temp2);
    }
    while (i--)
        out << s[i];
    std::ostream& r = out << suffix;
    for (size_t k = 0; k < n; ++k)
        s[k] = 0;
    CryptoPP::UnalignedDeallocate(s);
    return r;
}

CppInteger* FUN_142359280(CppInteger* out, const char* str);                            // Integer(const char*)
CppInteger* FUN_14235c230(CppInteger* self, const CppInteger* t);                       // Integer::operator=

static bool CppIsIntegerTextChar(char c)
{
    return c == '-' || c == 'x' || (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || c == 'h' || c == 'H' ||
           c == 'o' || c == 'O' || c == ',' || c == '.';
}

// MS2-FUNCTIONAL: same token scan and parse; the exe inlines the Integer constructor's one-time multiply-function-pointer setup and the SecBlock growth
// operator>>(std::istream&, Integer&): read a run of integer-text characters, parse them and assign
// @0x14235c2d0
std::istream& FUN_14235c2d0(std::istream& in, CppInteger& a)
{
    size_t cap = 16;
    char* str = static_cast<char*>(CryptoPP::UnalignedAllocate(cap));
    unsigned length = 0;
    char c;
    std::ws(in);
    do
    {
        in.read(&c, 1);
        str[length++] = c;
        if (length >= cap)
        {
            size_t newCap = length + 16;
            char* grown = static_cast<char*>(CryptoPP::UnalignedAllocate(newCap));
            for (size_t i = 0; i < cap; ++i)
                grown[i] = str[i];
            for (size_t i = 0; i < cap; ++i)
                str[i] = 0;
            CryptoPP::UnalignedDeallocate(str);
            str = grown;
            cap = newCap;
        }
    } while (in.good() && CppIsIntegerTextChar(c));
    if (in.gcount())
        in.putback(c);
    str[length - 1] = '\0';
    CppInteger value;
    FUN_142359280(&value, str);
    FUN_14235c230(&a, &value);
    for (size_t i = 0; i < cap; ++i)
        str[i] = 0;
    CryptoPP::UnalignedDeallocate(str);
    return in;
}

// @0x1423537e0
// MS2-FUNCTIONAL: masm Baseline_Add (adc chain with jrcxz); the same word-wise add with carry out through _addcarry_u64
unsigned long long FUN_1423537e0(size_t n, unsigned long long* c, const unsigned long long* a, const unsigned long long* b)
{
    unsigned char carry = 0;
    for (size_t i = 0; i < n; i++)
        carry = _addcarry_u64(carry, a[i], b[i], &c[i]);
    return carry;
}
// @0x142353830
// MS2-FUNCTIONAL: masm Baseline_Sub (sbb chain with jrcxz); the borrow out through _subborrow_u64
unsigned long long FUN_142353830(size_t n, unsigned long long* c, const unsigned long long* a, const unsigned long long* b)
{
    unsigned char borrow = 0;
    for (size_t i = 0; i < n; i++)
        borrow = _subborrow_u64(borrow, a[i], b[i], &c[i]);
    return borrow;
}
