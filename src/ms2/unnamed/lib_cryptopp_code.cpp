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
union CppStrInit { std::string s; CppStrInit(const char* p); ~CppStrInit() {} }; __pragma(inline_depth(0)) __forceinline CppStrInit::CppStrInit(const char* p) : s(p) {} __pragma(inline_depth()) static __forceinline std::string* CppNewString(std::string* d, const char* p) { return &(new (d) CppStrInit(p))->s; }   // std::string(const char*) 0x1401d2620 stays out of line, as in the exe
extern const char DAT_14311c1e0[];
extern const char DAT_14311c638[];
extern const char DAT_14312d8d8[];
extern const char DAT_143130c28[];

// @0x1423056e0
std::string* FUN_1423056e0(void* self, std::string* out)
{
    CppNewString(out, DAT_14311c1e0);
    return out;
}

// @0x142305710
std::string* FUN_142305710(void* self, std::string* out)
{
    CppNewString(out, DAT_14311c638);
    return out;
}

// CryptoPP::AlgorithmParametersTemplate<int-sized T>: base (AlgorithmParametersBase) + m_value at +0x20
struct CppParamBase { void* vptr; char pad[0x18]; };
struct CppIntParam : CppParamBase { int m_value; };
typedef bool (*AssignIntFn)(const std::type_info&, void*, const void*);
namespace CryptoPP   // C3: member view of the CryptoPP names this unit calls
{
extern AssignIntFn g_pAssignIntToInteger;
void UnalignedDeallocate(void* p);
class NameValuePairs { public: static void ThrowIfTypeMismatch(const char* name, const std::type_info& stored, const std::type_info& retrieving); };
class DL_GroupParameters_IntegerBased { public: virtual void AssignFrom(const NameValuePairs& source); };
class AlgorithmParametersBase { public: AlgorithmParametersBase(const AlgorithmParametersBase& x); };
template <class T> class DL_PrivateKey { public: void AssignFrom(const NameValuePairs& source); };
template <class T> class DL_PublicKey { public: void AssignFrom(const NameValuePairs& source); };
class RandomNumberGenerator;
class Integer
{
public:
    enum RandomNumberType { ANY, PRIME };
    Integer();
    Integer(const Integer& t);
    Integer(const char* str);
    Integer(RandomNumberGenerator& rng, const Integer& min, const Integer& max, RandomNumberType rnType, const Integer& equiv, const Integer& mod);
    Integer& operator=(const Integer& t);
    static void Divide(unsigned long long& remainder, Integer& quotient, const Integer& dividend, unsigned long long divisor);
    static const Integer& Zero();
    static const Integer& One();
};
}
#ifdef MS2_HOOK_DLL
extern const std::type_info DAT_143a57d68;        // typeid(int)
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const std::type_info __identifier("??_R0H@8");        // typeid(int)
#define DAT_143a57d68 __identifier("??_R0H@8")
#endif
#ifdef MS2_HOOK_DLL
extern const std::type_info DAT_143aa1220;        // typeid(T) of the first instantiation
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const std::type_info __identifier("??_R0?AW4BlockPaddingScheme@BlockPaddingSchemeDef@CryptoPP@@@8");        // typeid(T) of the first instantiation
#define DAT_143aa1220 __identifier("??_R0?AW4BlockPaddingScheme@BlockPaddingSchemeDef@CryptoPP@@@8")
#endif
#ifdef MS2_HOOK_DLL
extern const std::type_info DAT_143aa7a80;        // typeid(T) of the second instantiation
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const std::type_info __identifier("??_R0?AW4RandomNumberType@Integer@CryptoPP@@@8");        // typeid(T) of the second instantiation
#define DAT_143aa7a80 __identifier("??_R0?AW4RandomNumberType@Integer@CryptoPP@@@8")
#endif
#ifdef MS2_HOOK_DLL
extern char DAT_14311ee90[];                      // vftable of the first instantiation
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" char __identifier("??_7?$AlgorithmParametersTemplate@W4BlockPaddingScheme@BlockPaddingSchemeDef@CryptoPP@@@CryptoPP@@6B@")[];                      // vftable of the first instantiation
#define DAT_14311ee90 __identifier("??_7?$AlgorithmParametersTemplate@W4BlockPaddingScheme@BlockPaddingSchemeDef@CryptoPP@@@CryptoPP@@6B@")
#endif
#ifdef MS2_HOOK_DLL
extern char DAT_14312dbf8[];                      // vftable of the second instantiation
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" char __identifier("??_7?$AlgorithmParametersTemplate@W4RandomNumberType@Integer@CryptoPP@@@CryptoPP@@6B@")[];                      // vftable of the second instantiation
#define DAT_14312dbf8 __identifier("??_7?$AlgorithmParametersTemplate@W4RandomNumberType@Integer@CryptoPP@@@CryptoPP@@6B@")
#endif

// @0x142311c70
void FUN_142311c70(CppIntParam* self, const char* name, const std::type_info& valueType, void* pValue)
{
    if (!(CryptoPP::g_pAssignIntToInteger != 0 && DAT_143aa1220 == DAT_143a57d68 && CryptoPP::g_pAssignIntToInteger(valueType, pValue, &self->m_value)))
    {
        CryptoPP::NameValuePairs::ThrowIfTypeMismatch(name, DAT_143aa1220, valueType);
        *(int*)pValue = self->m_value;
    }
}

// @0x14235df70
void FUN_14235df70(CppIntParam* self, const char* name, const std::type_info& valueType, void* pValue)
{
    if (!(CryptoPP::g_pAssignIntToInteger != 0 && DAT_143aa7a80 == DAT_143a57d68 && CryptoPP::g_pAssignIntToInteger(valueType, pValue, &self->m_value)))
    {
        CryptoPP::NameValuePairs::ThrowIfTypeMismatch(name, DAT_143aa7a80, valueType);
        *(int*)pValue = self->m_value;
    }
}

// @0x1423140b0
void FUN_1423140b0(CppIntParam* self, CppIntParam* dst)
{
    new (dst) CryptoPP::AlgorithmParametersBase(*reinterpret_cast<const CryptoPP::AlgorithmParametersBase*>(self));
    dst->vptr = DAT_14311ee90;
    dst->m_value = self->m_value;
}

// @0x1423697c0
void FUN_1423697c0(CppIntParam* self, CppIntParam* dst)
{
    new (dst) CryptoPP::AlgorithmParametersBase(*reinterpret_cast<const CryptoPP::AlgorithmParametersBase*>(self));
    dst->vptr = DAT_14312dbf8;
    dst->m_value = self->m_value;
}

#include <string>
#include <exception>

#ifdef MS2_HOOK_DLL
extern char DAT_14312d848[];   // vftable of Integer::OpenPGPDecodeErr
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" char __identifier("??_7OpenPGPDecodeErr@Integer@CryptoPP@@6B@")[];   // vftable of Integer::OpenPGPDecodeErr
#define DAT_14312d848 __identifier("??_7OpenPGPDecodeErr@Integer@CryptoPP@@6B@")
#endif
#ifdef MS2_HOOK_DLL
extern char DAT_143130c18[];   // vftable of PolynomialMod2::DivideByZero
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" char __identifier("??_7DivideByZero@PolynomialMod2@CryptoPP@@6B@")[];   // vftable of PolynomialMod2::DivideByZero
#define DAT_143130c18 __identifier("??_7DivideByZero@PolynomialMod2@CryptoPP@@6B@")
#endif

namespace CryptoPP   // C3: cryptlib.h's Exception, verbatim (the full header clashes with this unit's other CryptoPP
{                    // views); its vftable COMDAT is the exe's ??_7Exception@CryptoPP@@6B@ (0x142d30650)
class Exception : public std::exception
{
public:
	enum ErrorType { NOT_IMPLEMENTED, INVALID_ARGUMENT, CANNOT_FLUSH, DATA_INTEGRITY_CHECK_FAILED, INVALID_DATA_FORMAT, IO_ERROR, OTHER_ERROR };
	explicit Exception(ErrorType errorType, const std::string &s) : m_errorType(errorType), m_what(s) {}
	virtual ~Exception() throw() {}
	const char *what() const throw() {return (m_what.c_str());}
	const std::string &GetWhat() const {return m_what;}
	void SetWhat(const std::string &s) {m_what = s;}
	ErrorType GetErrorType() const {return m_errorType;}
	void SetErrorType(ErrorType errorType) {m_errorType = errorType;}

private:
	ErrorType m_errorType;
	std::string m_what;
};
}
// a std::string temporary whose constructor is the out-of-line one
struct CppTempString
{
    union { std::string s; };
    CppTempString() {}
    CppTempString(const char* p) { CppNewString(&s, p); }
    ~CppTempString() { s.~basic_string(); }
};
// the same temporary, with the string's small buffer visible so /GS counts it as a buffer
struct CppTempStringBuf
{
    __declspec(align(8)) char m_raw[sizeof(std::string)];
    std::string& s() { return *reinterpret_cast<std::string*>(m_raw); }
    CppTempStringBuf(const char* p) { CppNewString(&s(), p); }
    ~CppTempStringBuf() { s().~basic_string(); }
};
// Integer::OpenPGPDecodeErr and PolynomialMod2::DivideByZero (integer.h / gf2n.h, not built here): the Exception base
// is constructed in place, then the derived vftable is stored
struct CppCryptoExceptionA;
struct CppCryptoExceptionB;

// @0x14235bce0
CppCryptoExceptionA* FUN_14235bce0(CppCryptoExceptionA* self)
{
    CryptoPP::Exception* e = new (self) CryptoPP::Exception(CryptoPP::Exception::INVALID_DATA_FORMAT, CppTempStringBuf(DAT_14312d8d8).s());
    *reinterpret_cast<void**>(e) = DAT_14312d848;
    return reinterpret_cast<CppCryptoExceptionA*>(e);
}

// @0x14237b650
CppCryptoExceptionB* FUN_14237b650(CppCryptoExceptionB* self)
{
    CryptoPP::Exception* e = new (self) CryptoPP::Exception(CryptoPP::Exception::OTHER_ERROR, CppTempStringBuf(DAT_143130c28).s());
    *reinterpret_cast<void**>(e) = DAT_143130c18;
    return reinterpret_cast<CppCryptoExceptionB*>(e);
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
#ifdef MS2_HOOK_DLL
extern const std::type_info DAT_143aa7e90;
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const std::type_info __identifier("??_R0?AV?$DL_PrivateKeyImpl@VDL_GroupParameters_GFP_DefaultSafePrime@CryptoPP@@@CryptoPP@@@8");
#define DAT_143aa7e90 __identifier("??_R0?AV?$DL_PrivateKeyImpl@VDL_GroupParameters_GFP_DefaultSafePrime@CryptoPP@@@CryptoPP@@@8")
#endif
#ifdef MS2_HOOK_DLL
extern const std::type_info DAT_143aa1e90;
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const std::type_info __identifier("??_R0?AV?$DL_PrivateKey@VInteger@CryptoPP@@@CryptoPP@@@8");
#define DAT_143aa1e90 __identifier("??_R0?AV?$DL_PrivateKey@VInteger@CryptoPP@@@CryptoPP@@@8")
#endif
#ifdef MS2_HOOK_DLL
extern const std::type_info DAT_143aa7e20;
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const std::type_info __identifier("??_R0?AV?$DL_PublicKeyImpl@VDL_GroupParameters_GFP_DefaultSafePrime@CryptoPP@@@CryptoPP@@@8");
#define DAT_143aa7e20 __identifier("??_R0?AV?$DL_PublicKeyImpl@VDL_GroupParameters_GFP_DefaultSafePrime@CryptoPP@@@CryptoPP@@@8")
#endif
#ifdef MS2_HOOK_DLL
extern const std::type_info DAT_143aa1de0;
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const std::type_info __identifier("??_R0?AV?$DL_PublicKey@VInteger@CryptoPP@@@CryptoPP@@@8");
#define DAT_143aa1de0 __identifier("??_R0?AV?$DL_PublicKey@VInteger@CryptoPP@@@CryptoPP@@@8")
#endif
#ifdef MS2_HOOK_DLL
extern const std::type_info DAT_143aa1d00;
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const std::type_info __identifier("??_R0?AVDL_GroupParameters_IntegerBased@CryptoPP@@@8");
#define DAT_143aa1d00 __identifier("??_R0?AVDL_GroupParameters_IntegerBased@CryptoPP@@@8")
#endif

// NameValuePairs::GetThisObject: GetValue("ThisObject:" + typeid(T).name(), object)
static __forceinline std::string CppCat(std::string&& a, const std::type_info& t) { return std::move(a) + t.name(); }
static __forceinline bool CppGetThisObject(const CppNameValuePairs* source, const std::type_info& t, void* pObject)
{
    return source->GetVoidValue(CppCat(std::move(CppTempString(DAT_14312b860).s), t).c_str(), t, pObject);
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
        static_cast<CryptoPP::DL_PrivateKey<CryptoPP::Integer>*>(pObject)->AssignFrom(*reinterpret_cast<const CryptoPP::NameValuePairs*>(source));
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
        static_cast<CryptoPP::DL_PublicKey<CryptoPP::Integer>*>(pObject)->AssignFrom(*reinterpret_cast<const CryptoPP::NameValuePairs*>(source));
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
        reinterpret_cast<CryptoPP::DL_GroupParameters_IntegerBased*>(pObject + 0x50)->CryptoPP::DL_GroupParameters_IntegerBased::AssignFrom(*reinterpret_cast<const CryptoPP::NameValuePairs*>(source));
    return self;
}

// CryptoPP::Integer, as far as DL_PrivateKeyImpl<...>::GenerateRandom needs it: ASN1Object vptr + SecBlock + sign
struct CppInteger
{
    void* vptr;
    struct Alloc {} alloc;
    size_t m_size;
    unsigned long long* m_ptr;
    int sign;
    bool IsNegative() const { return sign == 1; }
    unsigned WordCount() const
    {
        size_t n = m_size;
        while (n && m_ptr[n - 1] == 0)
            n--;
        return (unsigned)n;
    }
    bool operator!() const { return IsNegative() ? false : (m_ptr[0] == 0 && WordCount() == 0); }
    void Negate() { if (!!(*this)) sign = 1 - sign; }
    unsigned BitCount() const;
    void swap(CppInteger& b)
    {
        std::swap(m_size, b.m_size);
        std::swap(m_ptr, b.m_ptr);
        std::swap(sign, b.sign);
    }
    ~CppInteger()
    {
        __stosq(m_ptr, 0, m_size);
        CryptoPP::UnalignedDeallocate(m_ptr);
    }
};

template <class T> static __forceinline unsigned CppBitPrecision(const T& value)
{
    if (!value)
        return 0;
    unsigned l = 0, h = 8 * sizeof(value);
    while (h - l > 1)
    {
        unsigned t = (l + h) / 2;
        if (value >> t)
            l = t;
        else
            h = t;
    }
    return h;
}
inline unsigned CppInteger::BitCount() const
{
    unsigned wordCount = WordCount();
    if (wordCount)
        return (wordCount - 1) * 64 + CppBitPrecision(m_ptr[wordCount - 1]);
    else
        return 0;
}
struct CppGroupParams
{
    virtual void GenerateRandom(void* rng, const CppNameValuePairs* params) {}
};
struct CppAbstractGroupParams
{
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual CppInteger GetMaxExponent() const;   // vtable +0x48
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
#ifdef MS2_HOOK_DLL
extern const std::type_info DAT_143aa1768;
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const std::type_info __identifier("??_R0?AVDL_GroupParameters_GFP@CryptoPP@@@8");
#define DAT_143aa1768 __identifier("??_R0?AVDL_GroupParameters_GFP@CryptoPP@@@8")
#endif
#ifdef MS2_HOOK_DLL
extern const std::type_info DAT_143aa3860;
#else
#pragma warning(disable : 4483)   // __identifier("<mangled name>")
extern "C" const std::type_info __identifier("??_R0?AVDL_GroupParameters_GFP_DefaultSafePrime@CryptoPP@@@8");
#define DAT_143aa3860 __identifier("??_R0?AVDL_GroupParameters_GFP_DefaultSafePrime@CryptoPP@@@8")
#endif

// DL_PrivateKeyImpl<GP>::GenerateRandom: take the group parameters from the source if it carries them, else generate them; x = random in [1, max exponent]
// the key (CppKeyObj base at -0x10) is reached from the group part with raw offsets, like the exe ([rcx-0x10] each time, no adjusted pointer kept)
static __forceinline CppKeyObj* CppKeyOf(CppKeyGroupPart* sub) { return reinterpret_cast<CppKeyObj*>(reinterpret_cast<char*>(sub) - 0x10); }
static __forceinline void CppDLGenerateRandom(CppKeyGroupPart* sub, void* rng, const CppNameValuePairs* params, const std::type_info& gpType)
{
    if (!CppGetThisObject(params, gpType, &sub->groupObject))
        sub->group.GenerateRandom(rng, params);
    CppInteger x;
    new (&x) CryptoPP::Integer(*static_cast<CryptoPP::RandomNumberGenerator*>(rng), CryptoPP::Integer::One(), reinterpret_cast<const CryptoPP::Integer&>(static_cast<const CppInteger&>(CppKeyOf(sub)->GetAbstractGroupParameters()->GetMaxExponent())), CryptoPP::Integer::ANY, CryptoPP::Integer::Zero(), CryptoPP::Integer::One());
    CppKeyOf(sub)->SetPrivateExponent(&x);
}

// MS2-FUNCTIONAL: same calls, frame and registers; the string temporaries sit in other stack slots (exe: name +0x90, moved temp +0x70) and the exe keeps the out-of-line string ctor result in rbx for the append, one more EH state
// @0x1423770a0
void FUN_1423770a0(CppKeyGroupPart* sub, void* rng, const CppNameValuePairs* params)
{
    CppDLGenerateRandom(sub, rng, params, DAT_143aa1768);
}

// MS2-FUNCTIONAL: same calls, frame and registers; the string temporaries sit in other stack slots (exe: name +0x90, moved temp +0x70) and the exe keeps the out-of-line string ctor result in rbx for the append, one more EH state
// @0x1423772f0
void FUN_1423772f0(CppKeyGroupPart* sub, void* rng, const CppNameValuePairs* params)
{
    CppDLGenerateRandom(sub, rng, params, DAT_143aa3860);
}

// HMAC<SHA1>::StaticAlgorithmName: "HMAC(" + SHA1::StaticAlgorithmName() + ")"
// MS2-FUNCTIONAL: same string building; the exe constructs "HMAC(" with an out-of-line ctor call, so its EH state for the string starts at the first throwing call, ours right away
// @0x1423798d0
std::string* FUN_1423798d0(std::string* out)
{
    CppTempString head;
    std::string& h = *CppNewString(&head.s, "HMAC(");
    return new (out) std::string(std::move(std::move(h) + "SHA-1") + ")");
}

namespace CryptoPP { enum PowerUpSelfTestStatus : int; extern PowerUpSelfTestStatus g_powerUpSelfTestStatus; }   // 0x143b10184 (fips140.h)

// @0x142353790
int GetPowerUpSelfTestStatus()
{
    return CryptoPP::g_powerUpSelfTestStatus;
}

// std::ws<char>(std::istream&): the STL's own instantiation (skip leading whitespace; used by Crypto++ Integer text parsing)
// The library's STL is newer than 14.16's <istream>: it skips the sentry at end of file and sets the state outside it.
// MS2-FUNCTIONAL: the exe calls ctype<char>::is through the msvcp140 import and keeps the facet in r14; ours inlines is()
// MS2-PIN: ??$ws@DU?$char_traits@D@std@@@std@@YAAEAV?$basic_istream@DU?$char_traits@D@std@@@0@AEAV10@@Z 0x14235a130
template <>
inline std::istream& std::ws<char, std::char_traits<char> >(std::istream& _Istr)
{
    bool (std::ios_base::*pfnEof)() const = &std::ios_base::eof;
    const std::ios_base& _Base = _Istr;
    if (!(_Base.*pfnEof)())
    {
        std::ios_base::iostate _State = std::ios_base::goodbit;
        const std::istream::sentry _Ok(_Istr, true);
        if (_Ok)
        {
            const std::ctype<char>& _Ctype_fac = std::use_facet<std::ctype<char> >(_Istr.getloc());
            _TRY_IO_BEGIN
            for (std::char_traits<char>::int_type _Meta = _Istr.rdbuf()->sgetc();; _Meta = _Istr.rdbuf()->snextc())
            {
                if (std::char_traits<char>::eq_int_type(std::char_traits<char>::eof(), _Meta))
                {
                    _State |= std::ios_base::eofbit;
                    break;
                }
                else if (!_Ctype_fac.is(std::ctype_base::space, std::char_traits<char>::to_char_type(_Meta)))
                {
                    break;
                }
            }
            _CATCH_IO_(_Istr)
        }
        _Istr.setstate(_State);
    }
    return _Istr;
}

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
    // operator! with an unsigned index, inlined as in the exe (the out-of-line ??7 lives in cryptopp__gf2n)
    __forceinline bool NotInline() const
    {
        for (unsigned i = 0; i < m_size; i++)
            if (m_ptr[i])
                return false;
        return true;
    }
    int GetCoefficient(size_t i) const { return (i / 64 < m_size) ? int(m_ptr[i / 64] >> (i % 64)) & 1 : 0; }
    int operator[](unsigned int i) const { return GetCoefficient(i); }
    static __forceinline unsigned BitPrecision(unsigned long long value)
    {
        if (!value)
            return 0;
        unsigned l = 0, h = 64;
        while (h - l > 1)
        {
            unsigned t = (l + h) / 2;
            if (value >> t)
                l = t;
            else
                h = t;
        }
        return h;
    }
    __forceinline unsigned BitCountInline() const
    {
        size_t n = m_size;
        while (n && m_ptr[n - 1] == 0)
            n--;
        unsigned wordCount = (unsigned)n;
        if (wordCount)
            return (wordCount - 1) * 64 + BitPrecision(m_ptr[wordCount - 1]);
        else
            return 0;
    }
};
struct CppSecByteBlock
{
    struct Alloc {} alloc;
    size_t m_size;
    char* m_ptr;
    explicit CppSecByteBlock(size_t n) : m_size(n) { m_ptr = allocate(n); }
    static __forceinline char* allocate(size_t n)
    {
        if (n == 0)
            return 0;
        return static_cast<char*>(UnalignedAllocate(n * sizeof(char)));
    }
    ~CppSecByteBlock() { __stosb(reinterpret_cast<unsigned char*>(m_ptr), 0, m_size); UnalignedDeallocate(m_ptr); }
};
}

// MS2-FUNCTIONAL: same text output and code as the Crypto++ source; the exe keeps suffix, vec and the stream in frame locals (frame 0x60) where ours spills them to the parameter home slots (frame 0x40)
// operator<<(std::ostream&, const PolynomialMod2&): bit string in binary/octal/hex groups with a b/o/h suffix
// @0x14237bef0
std::ostream& FUN_14237bef0(std::ostream& out, const CryptoPP::PolynomialMod2& a)
{
    long f = (static_cast<std::ios_base&>(out).*static_cast<std::ios_base::fmtflags (std::ios_base::*)() const>(&std::ios_base::flags))() & std::ios::basefield;
    int bits, block;
    char suffix;
    switch (f)
    {
    case std::ios::oct: bits = 3; block = 4; suffix = 'o'; break;
    case std::ios::hex: bits = 4; block = 2; suffix = 'h'; break;
    default:            bits = 1; block = 8; suffix = 'b';
    }
    if (a.NotInline())
        return out << '0' << suffix;
    CryptoPP::CppSecByteBlock s(a.BitCountInline() / bits + 1);
    unsigned i;
    const char* vec = ((static_cast<std::ios_base&>(out).*static_cast<std::ios_base::fmtflags (std::ios_base::*)() const>(&std::ios_base::flags))() & std::ios::uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";
    for (i = 0; i * bits < a.BitCount(); i++)
    {
        int digit = 0;
        for (int j = 0; j < bits; j++)
            digit |= a[i * bits + j] << j;
        s.m_ptr[i] = vec[digit];
    }
    while (i--)
    {
        out << s.m_ptr[i];
        if (i && (i % block) == 0)
            out << ',';
    }
    return out << suffix;
}


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
    size_t sz = x.m_size; x.m_size = y.m_size; y.m_size = sz;
    unsigned long long* p = x.m_ptr; x.m_ptr = y.m_ptr; y.m_ptr = p;
    int sg = x.sign; x.sign = y.sign; y.sign = sg;
}

// MS2-FUNCTIONAL: same text output, written as the Crypto++ source; the exe keeps temp1's size and pointer in registers across the stream calls and puts the stream and base in frame locals; ours reloads them (smaller frame)
// operator<<(std::ostream&, const Integer&): decimal ('.' suffix), octal ('o') or hex ('h') digits
// @0x14235c730
std::ostream& FUN_14235c730(std::ostream& out, const CppInteger& a)
{
    long f = (static_cast<std::ios_base&>(out).*static_cast<std::ios_base::fmtflags (std::ios_base::*)() const>(&std::ios_base::flags))() & std::ios::basefield;
    int base, block;
    char suffix;
    switch (f)
    {
    case std::ios::oct: base = 8; block = 8; suffix = 'o'; break;
    case std::ios::hex: base = 16; block = 4; suffix = 'h'; break;
    default:            base = 10; block = 3; suffix = '.';
    }
    CppInteger temp1;
    new (&temp1) CryptoPP::Integer(reinterpret_cast<const CryptoPP::Integer&>(a));
    CppInteger temp2;
    new (&temp2) CryptoPP::Integer;
    if (a.IsNegative())
    {
        out << '-';
        temp1.Negate();
    }
    if (!a)
        out << '0';
    const char* vec = ((static_cast<std::ios_base&>(out).*static_cast<std::ios_base::fmtflags (std::ios_base::*)() const>(&std::ios_base::flags))() & std::ios::uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";
    unsigned i = 0;
    CryptoPP::CppSecByteBlock s(a.BitCount() / (CppBitPrecision(base) - 1) + 1);
    while (!!temp1)
    {
        unsigned long long digit;
        CryptoPP::Integer::Divide(digit, reinterpret_cast<CryptoPP::Integer&>(temp2), reinterpret_cast<const CryptoPP::Integer&>(temp1), base);
        s.m_ptr[i++] = vec[digit];
        temp1.swap(temp2);
    }
    while (i--)
    {
        out << s.m_ptr[i];
    }
    return out << suffix;
}


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
    new (&value) CryptoPP::Integer(str);
    *(CryptoPP::Integer*)&a = *(const CryptoPP::Integer*)&value;
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
