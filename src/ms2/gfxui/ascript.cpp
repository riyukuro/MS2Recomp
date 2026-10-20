// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). AScript, the C++ handle of an ActionScript object.
// MS2-UNIT: ?\ascript.cpp
// MS2-RANGE: 0x1422ba6e0-0x1422bbb50 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings).
// Function names are Ghidra's (FUN_<va>). The obj ends with the SDK inlines Value::HasMember (0x1422bbac0) and
// Value::InvokeSelf(Value*) (0x1422bbb20). ??_GAScript (0x1409bb9a0) was first emitted by an earlier obj.
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/gfxmovie.h"

#include "hook/ms2hook.h"

CStringW FUN_1408767c0(const char* sz);                  // UTF-8 -> wide
CString FUN_14016a600(const wchar_t* wsz, int nCodePage); // wide -> narrow

extern Scaleform::GFx::Value DAT_143b0ae18;              // the undefined value returned by failed invokes
extern CString DAT_143b0ae38;                            // the method FUN_1422bb7e0 calls

Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);

// @0x1422ba6e0
AScript::AScript(int nMovieId)
    : m_nMovieId(nMovieId)
{
    if (Scaleform::GFx::Movie* pMovie = FUN_1422bb8b0(m_nMovieId))
        pMovie->CreateObject(&m_value);
}

// @0x1422ba780
AScript::AScript(const Scaleform::GFx::Value& v, int nMovieId)
    : m_nMovieId(nMovieId), m_value(v)
{
}

// @0x1422ba7f0
AScript::AScript(Scaleform::GFx::Value& v, int nMovieId)
    : m_nMovieId(nMovieId), m_value(v)
{
}

// @0x1422ba860
AScript::~AScript()
{
    m_value.SetNull();
}

// @0x1422ba8c0
CString AScript::FUN_1422ba8c0()
{
    return CString(FUN_1422baa20("name").GetString());
}
MS2_REPLACE_METHOD(0x1422BA8C0, AScript, FUN_1422ba8c0, 123, 0x6F33CC11);

// @0x1422ba950
CString AScript::FUN_1422ba950()
{
    return CString("AScript");
}
MS2_REPLACE_METHOD(0x1422BA950, AScript, FUN_1422ba950, 61, 0x74F3E331);

// @0x1422ba9a0
bool AScript::FUN_1422ba9a0()
{
    if (m_value.IsUndefined())
        return true;
    if (m_value.IsNull())
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x1422BA9A0, AScript, FUN_1422ba9a0, 72, 0xBA2549F5);

// @0x1422ba9f0
bool AScript::FUN_1422ba9f0(const char* szMember)
{
    return m_value.HasMember(szMember);
}
MS2_REPLACE_METHOD(0x1422BA9F0, AScript, FUN_1422ba9f0, 41, 0x0C97A0D4);

// @0x1422baa20
Scaleform::GFx::Value AScript::FUN_1422baa20(const char* szMember)
{
    Scaleform::GFx::Value v;
    if (m_value.GetMember(szMember, &v))
        return v;
    return v;
}
MS2_REPLACE_METHOD(0x1422BAA20, AScript, FUN_1422baa20, 170, 0x765E9129);

// @0x1422baad0
bool AScript::FUN_1422baad0(const char* szMember, CStringW& strOut)
{
    Scaleform::GFx::Value v;
    if (m_value.GetMember(szMember, &v))
    {
        strOut = v.IsStringW() ? v.GetStringW() : (LPCWSTR)FUN_1408767c0(v.GetString());
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422BAAD0, AScript, FUN_1422baad0, 284, 0xA82C4D84);

// @0x1422bac00
bool AScript::FUN_1422bac00(const char* szMember, CString& strOut)
{
    Scaleform::GFx::Value v;
    if (m_value.GetMember(szMember, &v))
    {
        strOut = v.IsStringW() ? FUN_14016a600(v.GetStringW(), 0) : CString(v.GetString());
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422BAC00, AScript, FUN_1422bac00, 373, 0x0DE5285B);

// @0x1422bad80
bool AScript::FUN_1422bad80(const char* szMember, unsigned int* pOut)
{
    Scaleform::GFx::Value v;
    if (m_value.GetMember(szMember, &v))
    {
        *pOut = v.GetUInt();
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422BAD80, AScript, FUN_1422bad80, 137, 0xA0009A9E);

// @0x1422bae10
bool AScript::FUN_1422bae10(const char* szMember, int* pOut)
{
    Scaleform::GFx::Value v;
    if (m_value.GetMember(szMember, &v))
    {
        *pOut = v.GetInt();
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422BAE10, AScript, FUN_1422bae10, 137, 0x49E908C4);

// @0x1422baea0
bool AScript::FUN_1422baea0(const char* szMember, float* pOut)
{
    Scaleform::GFx::Value v;
    if (m_value.GetMember(szMember, &v))
    {
        *pOut = (float)v.GetNumber();
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422BAEA0, AScript, FUN_1422baea0, 143, 0xA4B08A10);

// @0x1422baf40
bool AScript::FUN_1422baf40(const char* szMember, double* pOut)
{
    Scaleform::GFx::Value v;
    if (m_value.GetMember(szMember, &v))
    {
        *pOut = v.GetNumber();
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422BAF40, AScript, FUN_1422baf40, 139, 0xE85EDDB9);

// @0x1422bafe0
bool AScript::FUN_1422bafe0(const char* szMember, bool* pOut)
{
    Scaleform::GFx::Value v;
    if (m_value.GetMember(szMember, &v))
    {
        *pOut = v.GetBool();
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422BAFE0, AScript, FUN_1422bafe0, 137, 0x5269F125);

// @0x1422bb070
bool AScript::FUN_1422bb070(const char* szMember, __int64* pOut)
{
    Scaleform::GFx::Value v;
    if (m_value.GetMember(szMember, &v))
    {
        if (v.IsInt())
            *pOut = v.GetInt();
        else if (v.IsNumber())
            *pOut = (__int64)v.GetNumber();
        else if (v.IsString())
            *pOut = _atoi64(v.GetString());
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422BB070, AScript, FUN_1422bb070, 249, 0x0E7B9106);

// @0x1422bb170
bool AScript::FUN_1422bb170(const char* szMember, unsigned __int64* pOut)
{
    Scaleform::GFx::Value v;
    if (m_value.GetMember(szMember, &v))
    {
        if (v.IsUInt())
            *pOut = v.GetUInt();
        else if (v.IsNumber())
            *pOut = (unsigned __int64)v.GetNumber();
        else if (v.IsString())
            *pOut = _atoi64(v.GetString());
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422BB170, AScript, FUN_1422bb170, 301, 0x3A69F21D);

// @0x1422bb2b0
CStringW AScript::FUN_1422bb2b0(const char* szName)
{
    CStringW str;
    FUN_1422baad0(szName, str);
    return str;
}
MS2_REPLACE_METHOD(0x1422BB2B0, AScript, FUN_1422bb2b0, 116, 0x91D7A63A);

// @0x1422bb330
Scaleform::GFx::Value AScript::Invoke(const char* szMethod)
{
    Scaleform::GFx::Value result;
    if (m_value.Invoke(szMethod, &result))
    {
    }
    return result;
}

// @0x1422bb3c0
Scaleform::GFx::Value AScript::FUN_1422bb3c0()
{
    Scaleform::GFx::Value result;
    if (m_value.InvokeSelf(&result))
    {
    }
    return result;
}
MS2_REPLACE_METHOD(0x1422BB3C0, AScript, FUN_1422bb3c0, 113, 0x24A94901);

// @0x1422bb440
CString AScript::FUN_1422bb440()
{
    return CString(Invoke("toString").GetString());
}
MS2_REPLACE_METHOD(0x1422BB440, AScript, FUN_1422bb440, 123, 0x969EBA78);

// @0x1422bb4d0
CString AScript::FUN_1422bb4d0()
{
    return CString(Invoke("toLocaleString").GetString());
}
MS2_REPLACE_METHOD(0x1422BB4D0, AScript, FUN_1422bb4d0, 123, 0x61D516CA);

// @0x1422bb560
int AScript::FUN_1422bb560(Scaleform::GFx::Value v)
{
    return Invoke("IsPrototypeOf", v).GetBool();
}
MS2_REPLACE_METHOD(0x1422BB560, AScript, FUN_1422bb560, 157, 0x00299AD6);

// @0x1422bb610
int AScript::FUN_1422bb610(const CString& strName)
{
    return Invoke("hasOwnProperty", strName).GetBool();
}
MS2_REPLACE_METHOD(0x1422BB610, AScript, FUN_1422bb610, 144, 0x37F991C7);

// @0x1422bb6b0
int AScript::FUN_1422bb6b0(const CString& strName)
{
    return Invoke("PropertyIsEnumerable", strName).GetBool();
}
MS2_REPLACE_METHOD(0x1422BB6B0, AScript, FUN_1422bb6b0, 144, 0xC12A777A);

// @0x1422bb750
void AScript::FUN_1422bb750(const CString& strName, int bEnum)
{
    FUN_140ee5060("setPropertyIsEnumerable", strName, bEnum != 0);
}
MS2_REPLACE_METHOD(0x1422BB750, AScript, FUN_1422bb750, 129, 0x9AEFC7E4);

// @0x1422bb7e0
bool AScript::FUN_1422bb7e0(const AScript& obj)
{
    if (FUN_1422bb610(DAT_143b0ae38))
    {
        FUN_140acd1f0(DAT_143b0ae38, obj);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x1422BB7E0, AScript, FUN_1422bb7e0, 137, 0x80CEE5CA);

// @0x1422bb870
Scaleform::GFx::Value& AScript::FUN_1422bb870()
{
    return m_value;
}
MS2_REPLACE_METHOD(0x1422BB870, AScript, FUN_1422bb870, 15, 0x5731F599);

// @0x1422bb890
Scaleform::GFx::Value& AScript::FUN_1422bb890()
{
    return FUN_1422bb870();
}
MS2_REPLACE_METHOD(0x1422BB890, AScript, FUN_1422bb890, 24, 0x797F65C6);

// @0x1422bb8b0
Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId)
{
    GFxMovie* pMovie = FUN_14025e7a0()->FUN_1422b01a0(nMovieId);
    if (pMovie)
        return pMovie->FUN_1422bd0f0();
    return 0;
}
MS2_REPLACE(0x1422BB8B0, FUN_1422bb8b0, 57, 0x7765765F);

// @0x1422bb8f0
Scaleform::GFx::Value AScript::FUN_1422bb8f0(const char* szMethod, ASArgList& args)
{
    Scaleform::GFx::Value result;
    if (!m_value.Invoke(szMethod, &result, args.FUN_1409b1f70(0), args.FUN_1409b2840()))
        return DAT_143b0ae18;
    return result;
}
MS2_REPLACE_METHOD(0x1422BB8F0, AScript, FUN_1422bb8f0, 238, 0xA6647238);

// @0x1422bb9f0
Scaleform::GFx::Value AScript::FUN_1422bb9f0(ASArgList& args)
{
    Scaleform::GFx::Value result;
    if (!m_value.InvokeSelf(&result, args.FUN_1409b1f70(0), args.FUN_1409b2840()))
        return DAT_143b0ae18;
    return result;
}
MS2_REPLACE_METHOD(0x1422BB9F0, AScript, FUN_1422bb9f0, 208, 0xA54D30AA);
