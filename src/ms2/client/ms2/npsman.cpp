// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNPSMan: the Nexon NPS survey helper singleton (ctor/dtor,
// setters, the exit-survey opener), the "platform" survey parameter, the "r, g, b" / "r, g, b, a" colour parsers and the
// TSingleton<CNPSMan> instantiation. See npsman.h.
// MS2-UNIT: ?\npsman.cpp
// MS2-RANGE: 0x140db8d80-0x140db9610 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\npsman.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "npsman.h"

#include "networkservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- nps64.dll imports (the exe calls through their IAT slots, 0x142cd1488 / 0x142cd1480) ----
extern "C" __declspec(dllimport) void __cdecl OpenSurveyWindowA(const char* pszUrl, int nFlags, const char* pszParam, const char* pszExtra);
extern "C" void (__cdecl* __imp_AddSurveyParameterA)(const char* pszName, const char* pszValue);

// ---- unit-local colour types (names invented) ----
struct Unk_NpColor3 { float r, g, b; Unk_NpColor3(); };   // ctor 0x1409f72f0
struct Unk_NpColor4 { float r, g, b, a; Unk_NpColor4(); };   // ctor 0x14097f220

// ---- exe callees ----
#include "ms2/ms2format.h"   // C3: StringFormat<unsigned __int64> (was FUN_1401d9af0)
CStringW FUN_14016a730(const char* pszAnsi, int nCodePage);
void FUN_14028f060(void* pOut, CStringA kText);
void FUN_14028f190(void* pOut, CStringW kText);
Unk_NpColor3 FUN_140a56db0(float r, float g, float b);
Unk_NpColor4 FUN_14097f1d0(float r, float g, float b, float a);
int FUN_140db9ca0(const char* pszBuf, size_t nCount, const char* pszFormat, ...);

extern const char DAT_142e36cd4[];                              // "{0}"
extern const char DAT_142e36cfc[];                              // "PC"
extern const char* DAT_1439f5dd0;

CNPSMan* TSingleton<CNPSMan>::s_instance = 0;                   // 0x143abf520

// @0x140db8d80
CNPSMan::CNPSMan()
    : m_hPlayer(0), m_nMode(0), m_str18(L""), m_str20(L""), m_bArmed(false), m_bShown(false)
{
}

// @0x140db8e30
CNPSMan::~CNPSMan()
{
    ShowSurvey();
}

// @0x140db8eb0
void CNPSMan::ArmSurvey()
{
    m_bArmed = true;
    m_strSurveyUrl = FUN_140d86260()->vfunc_75();
}

// @0x140db8f30
void CNPSMan::ShowSurvey()
{
    if (!HasPlayerHandle())
        return;
    if (!IsArmed())
        return;
    if (IsShown())
        return;
    OpenSurveyWindowA((const char*)m_strSurveyUrl, 1, (const char*)StringFormat(DAT_142e36cd4, *reinterpret_cast<const unsigned __int64*>(&m_hPlayer)), DAT_1439f5dd0);
    m_bShown = true;
}

// @0x140db9000
void CNPSMan::SetMode(int nMode)
{
    m_nMode = nMode;
}

// @0x140db9020
void CNPSMan::SetPlayer(__int64 hPlayer)
{
    m_hPlayer = hPlayer;
}

// @0x140db9040
void CNPSMan::FUN_140db9040(CStringW& strText)
{
    m_str18 = strText;
}

// @0x140db9070
void CNPSMan::FUN_140db9070(CStringA& strText)
{
    m_str20 = FUN_14016a730((const char*)strText, 0);
}

// @0x140db90e0
void CNPSMan::FUN_140db90e0(CStringW& strText)
{
    m_str20 = strText;
}

// @0x140db9110
bool CNPSMan::HasPlayerHandle()
{
    if (m_hPlayer == 0)
        return false;
    return true;
}

// @0x140db9130
bool CNPSMan::IsArmed()
{
    return m_bArmed;
}

// @0x140db9150
bool CNPSMan::IsShown()
{
    return m_bShown;
}

// @0x140db9170
void CNPSMan::FUN_140db9170()
{
    __imp_AddSurveyParameterA("platform", DAT_142e36cfc);
}

// @0x140db91a0
TSingleton<CNPSMan>::TSingleton()
{
    s_instance = static_cast<CNPSMan*>(this);
}

// @0x140db91d0
TSingleton<CNPSMan>::~TSingleton()
{
    s_instance = 0;
}

// @0x140db9270
// The exe evaluates the stack args (&kColor.r + 2, + 1) into pointer temps before the CStringA conversion: the
// components are addressed off r with pointer arithmetic (`&kColor.g` is a simple arg that cl evaluates after the call).
Unk_NpColor3 FUN_140db9270(CStringA& strText)
{
    static Unk_NpColor3 kDefault = FUN_140a56db0(1.0f, 0.0f, 1.0f);
    if (strText.IsEmpty())
        return kDefault;
    Unk_NpColor3 kColor;
    int nParsed = FUN_140db9ca0((const char*)strText, 0x80, "%f, %f, %f", &kColor.r, &kColor.r + 1, &kColor.r + 2);
    if (nParsed != 3)
        return Unk_NpColor3();
    return kColor;
}

// @0x140db93e0
// The components are addressed off r with pointer arithmetic, as in FUN_140db9270.
Unk_NpColor4 FUN_140db93e0(CStringA& strText)
{
    static Unk_NpColor4 kDefault = FUN_14097f1d0(1.0f, 0.0f, 1.0f, 1.0f);
    if (strText.IsEmpty())
        return kDefault;
    Unk_NpColor4 kColor;
    int nParsed = FUN_140db9ca0((const char*)strText, 0x80, "%f, %f, %f, %f", &kColor.r, &kColor.r + 1, &kColor.r + 2, &kColor.r + 3);
    if (nParsed != 4)
        return Unk_NpColor4();
    return kColor;
}

// @0x140db9570
void* FUN_140db9570(void* pOut, CStringA& strText)
{
    FUN_14028f060(pOut, CStringA(strText));
    return pOut;
}

// @0x140db95c0
void* FUN_140db95c0(void* pOut, CStringW& strText)
{
    FUN_14028f190(pOut, CStringW(strText));
    return pOut;
}
