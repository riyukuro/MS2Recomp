// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Crypto++ 5.6.2 functions that the engine-stage gb:CryptoPP/*
// TUs leave as stubs because the exe's copy was folded or compiled with different codegen than the in-tree source.
// MS2-UNIT: lib_cryptopp_code
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
extern const std::type_info DAT_143a57d70;        // typeid(int)
extern const std::type_info DAT_143aa1220;        // typeid(T) of the first instantiation
extern const std::type_info DAT_143aa7a80;        // typeid(T) of the second instantiation
void FUN_140390ef0(const char* name, const std::type_info& t1, const std::type_info& t2);   // ThrowIfTypeMismatch
void FUN_14038dff0(void* dst, const void* src);   // AlgorithmParametersBase copy ctor
extern char DAT_14311ee90[];                      // vftable of the first instantiation
extern char DAT_14312dbf8[];                      // vftable of the second instantiation

// @0x142311c70
void FUN_142311c70(CppIntParam* self, const char* name, const std::type_info& valueType, void* pValue)
{
    if (!(DAT_143b0dc90 != 0 && DAT_143aa1220 == DAT_143a57d70 && DAT_143b0dc90(valueType, pValue, &self->m_value)))
    {
        FUN_140390ef0(name, DAT_143aa1220, valueType);
        *(int*)pValue = self->m_value;
    }
}

// @0x14235df70
void FUN_14235df70(CppIntParam* self, const char* name, const std::type_info& valueType, void* pValue)
{
    if (!(DAT_143b0dc90 != 0 && DAT_143aa7a80 == DAT_143a57d70 && DAT_143b0dc90(valueType, pValue, &self->m_value)))
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

// CryptoPP::Exception: std::exception + m_errorType + m_what, as the exe's copy lays it out
struct CppCryptoException : std::exception
{
    int m_errorType;
    std::string m_what;
    CppCryptoException(int type, const std::string& s) : m_errorType(type), m_what(s) {}
};
// a std::string temporary whose constructor is the out-of-line one
struct CppTempString
{
    union { std::string s; };
    CppTempString(const char* p) { FUN_1401d2620(&s, p); }
    ~CppTempString() { s.~basic_string(); }
};
// a Crypto++ exception subclass with its own vftable (the vtable stored last is the derived one)
struct CppCryptoExceptionA : CppCryptoException
{
    CppCryptoExceptionA() : CppCryptoException(4, CppTempString(DAT_14312d8d8).s) {}
    virtual ~CppCryptoExceptionA() throw();
};
struct CppCryptoExceptionB : CppCryptoException
{
    CppCryptoExceptionB() : CppCryptoException(6, CppTempString(DAT_143130c28).s) {}
    virtual ~CppCryptoExceptionB() throw();
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
