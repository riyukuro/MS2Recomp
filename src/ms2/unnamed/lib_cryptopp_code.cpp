// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Crypto++ 5.6.2 functions that the engine-stage gb:CryptoPP/*
// TUs leave as stubs because the exe's copy was folded or compiled with different codegen than the in-tree source.
// MS2-UNIT: lib_cryptopp_code
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <typeinfo>

struct CppString;
CppString* FUN_1401d2620(CppString* dst, const char* src);   // std::string(const char*)
extern const char DAT_14311c1e0[];
extern const char DAT_14311c638[];

// @0x1423056e0
CppString* FUN_1423056e0(void* self, CppString* out)
{
    FUN_1401d2620(out, DAT_14311c1e0);
    return out;
}

// @0x142305710
CppString* FUN_142305710(void* self, CppString* out)
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
