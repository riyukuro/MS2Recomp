// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CDrawDebugString: one line of the in-game debug overlay
// (label + changing value, drawn twice: a black shadow one pixel down-right and the colored text). See cdrawdebugstring.h.
// MS2-UNIT: ?\drawdebugstring.cpp
// MS2-RANGE: 0x14118b420-0x14118c730 .text$mn
// MS2-PIN: ??_GCDrawDebugString@@UEAAPEAXI@Z 0x14118c3d0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\drawdebugstring.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include <string>
#include <new>
#include <NiRenderer.h>
#include <efd/StringUtilities.h>
#include "ms2/placeholder/cdrawdebugstring.h"
#include "ms2/ms2recover.h"

// ---- exe callees ----
extern const NiColorA DAT_143a09680;                                                    // black
extern const NiPoint3 DAT_143b01a60;                                                    // the zero point
NiPoint3* FUN_140194470(NiPoint3* pDst, const NiPoint3* pSrc);                          // NiPoint3 assign
bool FUN_140552690(const NiPoint3* pA, const NiPoint3* pB);                             // NiPoint3 ==
void* FUN_140a44830();                                                                  // the debug log singleton
void FUN_1401ce2f0(void* pLog, const char* pszFormat, const char* pszText);
CString FUN_14016a5c0(const char* psz, int nCodePage);                                  // narrows a string
CString FUN_140298360(const char* psz, const CString& str);                             // operator+(const char*, const CString&)

#ifdef __clang__
// Bind the exe's operator+(char, const CString&); clang would import an unavailable MFC CopyChars.
CString FUN_14118c310(char ch, const CString& str);
inline CString Unk_DbgPrepend(char ch, const CString& str) { return FUN_14118c310(ch, str); }
#else
inline CString Unk_DbgPrepend(char ch, const CString& str) { return ch + str; }
#endif

// @0x14118b420
CDrawDebugString::CDrawDebugString(const char* pcName, NiColorA kColor) : NiVisualTrackerBase(NiRect<float>(0, 5.0f, 400.0f, 0), false, pcName)
{
    m_pText = NiNew NiVisualTrackerBase::ScreenText(0x20, &m_kScreenTextures, kColor);
    m_pShadow = NiNew NiVisualTrackerBase::ScreenText(0x20, &m_kScreenTextures, (const efd::ColorA&)DAT_143a09680);    // implicit NiColorA(const efd::ColorA&) temp
    m_pShadow->SetTextOrigin(1, 1);
    m_nValue = 0;
    FUN_140194470(&m_kPoint, &DAT_143b01a60);
}

// @0x14118b670
CDrawDebugString::~CDrawDebugString()
{
    if (m_pText)
    {
        delete m_pText;
        m_pText = 0;
    }
    if (m_pShadow)
    {
        delete m_pShadow;
        m_pShadow = 0;
    }
}

// @0x14118b780
void CDrawDebugString::Draw()
{
    if (m_bShow)
    {
        for (unsigned i = 0; i < m_kScreenTextures.GetSize(); ++i)
            m_kScreenTextures.GetAt(i)->RenderImmediate(NiRenderer::GetRenderer());
    }
}

// @0x14118b820
void CDrawDebugString::FUN_14118b820(int nValue, bool bForce, const char* pszSuffix)
{
    if (m_bShow || bForce)
    {
        if (m_nValue == nValue && !bForce)
            return;
        m_nValue = nValue;
        std::string strNum = FUN_14118c120(nValue);
        if (pszSuffix != 0)
            efd::Sprintf(m_acName, 0xff, "%s %s%s", (const char*)m_strLabel, strNum.c_str(), pszSuffix);
        else
            efd::Sprintf(m_acName, 0xff, "%s %s", (const char*)m_strLabel, strNum.c_str());
        FUN_14118c0d0();
    }
}

// @0x14118b9b0
void CDrawDebugString::FUN_14118b9b0(unsigned nValue, bool bForce, const char* pszSuffix)
{
    if (m_bShow || bForce)
    {
        if ((unsigned)m_nValue == nValue && !bForce)
            return;
        m_nValue = nValue;
        std::string strNum = FUN_14118c120(nValue);
        if (pszSuffix != 0)
            efd::Sprintf(m_acName, 0xff, "%s %s%s", (const char*)m_strLabel, strNum.c_str(), pszSuffix);
        else
            efd::Sprintf(m_acName, 0xff, "%s %s", (const char*)m_strLabel, strNum.c_str());
        FUN_14118c0d0();
    }
}

// @0x14118bb40
void CDrawDebugString::FUN_14118bb40(float fValue, bool bForce, const char* pszSuffix)
{
    if (m_bShow || bForce)
    {
        if (fValue == m_fValue && !bForce)
            return;
        m_fValue = fValue;
        if (pszSuffix != 0)
            efd::Sprintf(m_acName, 0xff, "%s %.2f%s", (const char*)m_strLabel, (double)fValue, pszSuffix);
        else
            efd::Sprintf(m_acName, 0xff, "%s %.2f", (const char*)m_strLabel, (double)fValue);
        FUN_14118c0d0();
    }
}

// @0x14118bc70
void CDrawDebugString::FUN_14118bc70(bool bValue, bool bForce, const char* pszSuffix)
{
    if (m_bShow || bForce)
    {
        if (m_cValue == (unsigned char)bValue && !bForce)
            return;
        m_cValue = bValue;
        if (pszSuffix != 0)
        {
            const char* pszValue;
            if (bValue != 0)
                pszValue = "True";
            else
                pszValue = "False";
            efd::Sprintf(m_acName, 0xff, "%s %s%s", (const char*)m_strLabel, pszValue, pszSuffix);
        }
        else
        {
            const char* pszValue;
            if (bValue != 0)
                pszValue = "True";
            else
                pszValue = "False";
            efd::Sprintf(m_acName, 0xff, "%s %s", (const char*)m_strLabel, pszValue);
        }
        FUN_14118c0d0();
    }
}

// @0x14118bdc0
void CDrawDebugString::FUN_14118bdc0(const NiPoint3& kValue, bool bForce)
{
    if (m_bShow || bForce)
    {
        if (FUN_140552690(&m_kPoint, &kValue) && !bForce)
            return;
        FUN_140194470(&m_kPoint, &kValue);
        efd::Sprintf(m_acName, 0xff, "%s %.2f %.2f %.2f", (const char*)m_strLabel, (double)kValue.x, (double)kValue.y, (double)kValue.z);
        FUN_14118c0d0();
    }
}

// @0x14118bee0
void CDrawDebugString::FUN_14118bee0(efd::utf8string strValue, bool bForce)
{
    if (m_bShow || bForce)
    {
        efd::Sprintf(m_acName, 0xff, "%s %s", (const char*)m_strLabel, strValue.c_str());
        FUN_14118c0d0();
    }
}

// @0x14118bf80
void CDrawDebugString::FUN_14118bf80(const char* pszLabel, unsigned x, unsigned y)
{
    m_strLabel = pszLabel;
    m_pShadow->SetTextOrigin(x + 1, y + 1);
    m_pShadow->SetVisible(true);
    m_pText->SetTextOrigin(x, y);
    m_pText->SetVisible(true);
    efd::Sprintf(m_acName, 0xff, "%s", (const char*)m_strLabel);
    FUN_14118c0d0();
}

// @0x14118c060
void CDrawDebugString::FUN_14118c060()
{
    FUN_1401ce2f0(FUN_140a44830(), "%s", m_acName);
}

// @0x14118c0a0
void CDrawDebugString::FUN_14118c0a0(NiColorA* pColor)
{
    m_pText->SetColor(*pColor);
}

// @0x14118c0d0
void CDrawDebugString::FUN_14118c0d0()
{
    m_pShadow->SetString(m_acName);
    m_pText->SetString(m_acName);
}

// MS2-FUNCTIONAL: loop temp layout differs (3 bytes)
// @0x14118c120
std::string CDrawDebugString::FUN_14118c120(unsigned nValue)
{
    CString strOut;
    CString strNum;
    strNum.Format("%u", nValue);
    int nDigits = 0;
    for (int i = strNum.GetLength(); 0 < i; --i)
    {
        strOut = Unk_DbgPrepend(strNum[i - 1], strOut);
        ++nDigits;
        if (i != 1 && nDigits == 3)
        {
            strOut = FUN_140298360(",", strOut);
            nDigits = 0;
        }
    }
    return std::string((const char*)FUN_14016a5c0((const char*)strOut, 0));
}

// @0x14118c300
const char* CDrawDebugString::GetText()
{
    return m_acName;
}

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, like memmove_s).
// @0x14118c4c0
// MS2-FUNCTIONAL: unreferenced CRT memcpy_s copy: frame saves rsi/rdi, source spelling differs
static __inline errno_t ms2_memcpy_s_copy(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy;

MS2_EMIT_CRT_MEMMOVE_S();
