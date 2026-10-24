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
