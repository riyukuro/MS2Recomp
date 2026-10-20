// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: commonfiles\localepath.cpp
// MS2-RANGE: 0x14064ead0-0x1406525e0 .text$mn
// MS2-RANGE: 0x1400baec0-0x1400bafe0 .text$di
// MS2-PIN: memmove_s 0x140650680
// MS2-PIN: ?AddRefImpl@?$MS2SvrPtr@VCLocaleLanguageData@@@@AEBAXPEAX@Z 0x1406505c0
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2SvrPtr@VCLocaleLanguageData@@@@V?$CElementTraits@V?$MS2SvrPtr@VCLocaleLanguageData@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2SvrPtr@VCLocaleLanguageData@@@@@Z 0x14064fa50
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\localepath.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "localepath.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <locale.h>

// Unrecovered helpers.
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140168650 { public: Unk_140168650* FUN_140168650(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
int FUN_1408733e0(void*, const char*, CString&);
void FUN_14015f050(CString&, ATL::CAtlArray<CString>&, const char* delimiter);
void FUN_1402c2890(ATL::CAtlArray<CString>&);                       // RemoveAll
void FUN_140165270(ATL::CAtlArray<CString>&, CString&);              // Add
unsigned __int64 FUN_1401662c0(ATL::CAtlArray<CString>&);            // GetCount
void* FUN_140164930(ATL::CAtlArray<CString>&, unsigned __int64);     // GetAt
void FUN_1402be480(CString&, const char*);
CString FUN_140298360(const char*, const CString&);
CString FUN_140188f50(const char*, int);
char FUN_1401c0090(const CString&, const CString&);
class Unk_14025e7c0 { };
Unk_14025e7c0* FUN_14025e7c0();
unsigned char FUN_14116d720(Unk_14025e7c0*);

extern int DAT_1439f4840;
extern _locale_t DAT_143aad168;
extern int DAT_143ab0560;
extern CString DAT_143ab0568;
extern CString DAT_143ab0588;

CString FUN_140651c00(int nLanguage);                 // language enum -> "KR"/"JP"/...
int FUN_140651920(CString strCode);                   // language code -> enum
CString FUN_1406504c0(CString& s);
CString FUN_140650500(CString& s);
void FUN_140650090(CString& s);
int FUN_1406500b0(CString& s);
CString FUN_140651350();
CString FUN_140651390();
CString FUN_1406522f0(int);
CString FUN_140652330(int);
void FUN_140650b30(int);
int FUN_1406516c0();
void FUN_1406507a0(int);
void FUN_1406509e0(int);
void FUN_140650ac0(int);

static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
int DAT_143ab0240;
int DAT_143ab0244;
int DAT_143ab0248;
CString DAT_143ab0250("KR");
CString DAT_143ab0258("KR");

// @0x14064ead0
CLocaleLanguageData::CLocaleLanguageData()
{
    FUN_14064ef60();
}

// @0x14064eb60
CLocaleLanguageData::~CLocaleLanguageData()
{
    FUN_14064ef60();
}

// @0x14064ebf0
int CLocaleLanguageData::FUN_14064ebf0(int nLanguage)
{
    CString strCode = FUN_140651c00(nLanguage);
    return FUN_14064ec70(strCode);
}

// @0x14064ec70
int CLocaleLanguageData::FUN_14064ec70(CString strCode)
{
    int result = 0;
    int nCount = (int)FUN_1401662c0(m_languages);
    for (int i = 0; i < nCount; ++i)
    {
        CString s = *(CString*)FUN_140164930(m_languages, i);
        if (s.CompareNoCase(strCode) == 0)
        {
            result = 1;
            break;
        }
    }
    return result;
}

// @0x14064ed50
int CLocaleLanguageData::FUN_14064ed50()
{
    if (FUN_1401662c0(m_languages) <= 0)
        return 0;
    CString s = *(CString*)FUN_140164930(m_languages, 0);
    return FUN_140651920(s);
}

// @0x14064edf0
void CLocaleLanguageData::FUN_14064edf0(ATL::CAtlArray<int, ATL::CDefaultElementTraits<int>>& out)
{
    out.RemoveAll();
    for (unsigned __int64 i = 0; i < FUN_1401662c0(m_languages); ++i)
    {
        CString s = *(CString*)FUN_140164930(m_languages, i);
        int e = FUN_140651920(s);
        out.Add(e);
    }
}

// @0x14064eec0
void CLocaleLanguageData::FUN_14064eec0(ATL::CAtlArray<CString>& out)
{
    FUN_1402c2890(out);
    for (unsigned __int64 i = 0; i < FUN_1401662c0(m_languages); ++i)
    {
        CString s = FUN_1406504c0(*(CString*)FUN_140164930(m_languages, i));
        FUN_140165270(out, s);
    }
}

// @0x14064ef60
void CLocaleLanguageData::FUN_14064ef60()
{
    m_strLocale.Empty();
    FUN_1402c2890(m_languages);
    FUN_1402c2890(m_regions);
    FUN_1402c2890(m_voices);
}

// @0x14064efc0
CLocaleLanguage::CLocaleLanguage()
{
    FUN_14064f390();
}

// @0x14064f020
CLocaleLanguage::~CLocaleLanguage()
{
    m_rows.RemoveAll();
}

// @0x14064f070
// MS2-FUNCTIONAL: smart-pointer return temps / branch layout differ
LocaleLanguageDataPtr CLocaleLanguage::FUN_14064f070(unsigned int nLocale)
{
    unsigned int nSel = FUN_14116d720(FUN_14025e7c0());
    if (nLocale != 0)
        nSel = nLocale;
    int nCount = (int)m_rows.GetCount();
    int nIdx = nCount - 1;
    if (nSel == 0)
        nIdx = DAT_143ab0248;
    if (nIdx == -1)
        return LocaleLanguageDataPtr(0);
    else if (nCount - 1 < nIdx)
        return LocaleLanguageDataPtr(0);
    else
        return static_cast<const LocaleLanguageDataPtr&>(m_rows[nIdx]);
}

// @0x14064f180
int CLocaleLanguage::FUN_14064f180(int nLanguage)
{
    LocaleLanguageDataPtr p = FUN_14064f070(0);
    if (p == 0)
        return 0;
    return p->FUN_14064ebf0(nLanguage);
}

// @0x14064f210
int CLocaleLanguage::FUN_14064f210()
{
    LocaleLanguageDataPtr p = FUN_14064f070(0);
    if (p == 0)
        return 0;
    return p->FUN_14064ed50();
}

// @0x14064f290
void CLocaleLanguage::FUN_14064f290(ATL::CAtlArray<int, ATL::CDefaultElementTraits<int>>& out)
{
    LocaleLanguageDataPtr p = FUN_14064f070(0);
    if (p == 0)
        return;
    p->FUN_14064edf0(out);
}

// @0x14064f310
void CLocaleLanguage::FUN_14064f310(ATL::CAtlArray<CString>& out)
{
    LocaleLanguageDataPtr p = FUN_14064f070(0);
    if (p == 0)
        return;
    p->FUN_14064eec0(out);
}

// @0x14064f390
// MS2-FUNCTIONAL: xml load loop: EH state numbering and temp slots differ
int CLocaleLanguage::FUN_14064f390()
{
    CString strPath = FUN_14071a5b0("Table", "gameOptionLocale.xml");
    TiXmlDocument doc;
    const char* pszPath = strPath;
    if (FUN_140166420()->FUN_1403974b0(&doc, pszPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("gameoptionlocale"); pNode != 0;
         pNode = reinterpret_cast<Unk_140165cf0*>(reinterpret_cast<Unk_140168650*>(pNode)->FUN_140168650("gameoptionlocale")))
    {
        LocaleLanguageDataPtr data(new CLocaleLanguageData);
        CString strLanguage;
        CString strRegion;
        CString strVoice;
        FUN_1408733e0(pNode, "locale", data->m_strLocale);
        FUN_1408733e0(pNode, "language", strLanguage);
        FUN_1408733e0(pNode, "region", strRegion);
        FUN_1408733e0(pNode, "voice", strVoice);
        FUN_14015f050(strLanguage, data->m_languages, ",");
        FUN_14015f050(strRegion, data->m_regions, ",");
        FUN_14015f050(strVoice, data->m_voices, ",");
        m_rows.Add(data);
    }
    return 1;
}

// @0x1406504c0
CString FUN_1406504c0(CString& s)
{
    return FUN_140650500(s);
}

// @0x140650500
CString FUN_140650500(CString& s)
{
    CString t(s);
    FUN_140650090(t);
    return t;
}

// @0x140650b30
void FUN_140650b30(int n)
{
    DAT_143ab0244 = n;
}

// @0x140650b50
// MS2-FUNCTIONAL: CString temp-slot idiom (return-by-value assigned to global) differs
void FUN_140650b50(CString strCode)
{
    strCode.MakeUpper();
    if (FUN_1401c0090(FUN_1406522f0(FUN_1406516c0()), strCode)) {}
    else if (FUN_1401c0090(strCode, FUN_1406522f0(0))) FUN_140650b30(0);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(1))) FUN_140650b30(1);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(2))) FUN_140650b30(2);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(3))) FUN_140650b30(3);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(4))) FUN_140650b30(4);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(5))) FUN_140650b30(5);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(6))) FUN_140650b30(6);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(7))) FUN_140650b30(7);
}

// @0x140650e70
// MS2-FUNCTIONAL: CString temp-slot idiom (return-by-value assigned to global) differs
void FUN_140650e70(CString strCode)
{
    strCode.MakeUpper();
    if (FUN_1401c0090(FUN_140651350(), strCode)) {}
    else if (FUN_1401c0090(strCode, FUN_1406522f0(0))) FUN_1406507a0(0);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(1))) FUN_1406507a0(1);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(2))) FUN_1406507a0(2);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(3))) FUN_1406507a0(3);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(4))) FUN_1406507a0(4);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(5))) FUN_1406507a0(5);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(6))) FUN_1406507a0(6);
    else if (FUN_1401c0090(strCode, FUN_1406522f0(7))) FUN_1406507a0(7);
}

// @0x140651190
// MS2-FUNCTIONAL: CString temp-slot idiom (return-by-value assigned to global) differs
void FUN_140651190(CString strCode)
{
    strCode.MakeUpper();
    if (FUN_1401c0090(FUN_140651390(), strCode)) {}
    else if (FUN_1401c0090(strCode, FUN_140652330(0))) FUN_1406509e0(0);
    else if (FUN_1401c0090(strCode, FUN_140652330(1))) FUN_1406509e0(1);
    else if (FUN_1401c0090(strCode, FUN_140652330(2))) FUN_1406509e0(2);
    else if (FUN_1401c0090(strCode, FUN_140652330(3))) FUN_1406509e0(3);
}

// @0x140651350
CString FUN_140651350()
{
    return DAT_143ab0250;
}

// @0x140651390
CString FUN_140651390()
{
    return DAT_143ab0258;
}

// @0x1406513d0
// MS2-FUNCTIONAL: return-by-value CString temp passed as const ref: exe saves call rax
CString FUN_1406513d0(CString strFile)
{
    CString strPath = FUN_140298360("./ServerConfig/", strFile);
    const CString& rTmp = FUN_140188f50((const char*)DAT_143ab0258, 0);
    const CString& rTmp2 = rTmp;
    CString strSuffix = FUN_140298360("_", rTmp2);
    const char* pszSuffix = strSuffix;
    strPath.Insert(strPath.Find(".xml", 0), pszSuffix);
    return strPath;
}

// @0x1406514e0
int FUN_1406514e0(int nRegion, ATL::CAtlArray<int, ATL::CDefaultElementTraits<int>>& out)
{
    switch (nRegion)
    {
    case 0:
    {
        int a = 0;
        return (int)out.Add(a);
    }
    case 1:
    {
        int a = 1;
        return (int)out.Add(a);
    }
    case 2:
    {
        int a = 2;
        out.Add(a);
        int b = 5;
        out.Add(b);
        int c = 6;
        return (int)out.Add(c);
    }
    case 3:
    {
        int a = 3;
        return (int)out.Add(a);
    }
    default:
        MS2_ASSERT_AT(0x17b, FALSE);
        break;
    }
}

// @0x1406515e0
bool FUN_1406515e0(unsigned int nRegion, int nLanguage)
{
    switch (nRegion)
    {
    case 0:
        if (nLanguage == 0)
            return true;
        break;
    case 1:
        if (nLanguage == 1)
            return true;
        break;
    case 2:
        if (nLanguage == 2 || nLanguage == 4 || nLanguage == 5 || nLanguage == 6 || nLanguage == 7)
            return true;
        break;
    case 3:
        if (nLanguage == 3)
            return true;
        break;
    default:
        MS2_ASSERT_AT(0x199, FALSE);
        break;
    }
    return false;
}

// @0x1406516a0
int FUN_1406516a0()
{
    return DAT_143ab0240;
}

// @0x1406516b0
int FUN_1406516b0()
{
    return DAT_143ab0248;
}

// @0x1406516c0
int FUN_1406516c0()
{
    return DAT_143ab0244;
}

// @0x1406516d0
int FUN_1406516d0(int n)
{
    switch (n)
    {
    case 0: case 1: case 3: return 4;
    default: return 3;
    }
}

// @0x140651710
CString FUN_140651710(int n)
{
    switch (n)
    {
    case 0: return CString("kor");
    case 1: return CString("jpn");
    case 2: return CString("en");
    case 3: return CString("chi");
    case 4: return CString("fra");
    case 5: return CString("deu");
    case 6: return CString("por");
    case 7: return CString("spa");
    default: return CString("");
    }
}

// @0x1406518d0
int FUN_1406518d0(short langid)
{
    int id = (unsigned short)langid;
    switch (id)
    {
    case 0x407: return 5;
    case 0x416: return 6;
    default: return 2;
    }
}

// @0x140651920
int FUN_140651920(CString strCode)
{
    if (strCode.CompareNoCase("KR") == 0) return 0;
    else if (strCode.CompareNoCase("JP") == 0) return 1;
    else if (strCode.CompareNoCase("EN") == 0) return 2;
    else if (strCode.CompareNoCase("CN") == 0) return 3;
    else if (strCode.CompareNoCase("FR)") == 0) return 4;
    else if (strCode.CompareNoCase("DE") == 0) return 5;
    else if (strCode.CompareNoCase("PT") == 0) return 6;
    else if (strCode.CompareNoCase("ES") == 0) return 7;
    return 0;
}

// @0x140651b00
int FUN_140651b00(CString strCode)
{
    if (strCode.CompareNoCase("KR") == 0) return 0;
    else if (strCode.CompareNoCase("JP") == 0) return 1;
    else if (strCode.CompareNoCase("NA") == 0) return 2;
    else if (strCode.CompareNoCase("CN") == 0) return 3;
    return 0;
}

// @0x140651c00
CString FUN_140651c00(int n)
{
    CString s("");
    switch (n)
    {
    case 0: s = "KR"; break;
    case 1: s = "JP"; break;
    case 2: s = "EN"; break;
    case 3: s = "CN"; break;
    case 4: s = "FR"; break;
    case 5: s = "DE"; break;
    case 6: s = "PT"; break;
    case 7: s = "ES"; break;
    default: s = "KR"; break;
    }
    return s;
}

// @0x140651d70
CStringW FUN_140651d70(int n)
{
    switch (n)
    {
    case 0: return CStringW(L"KR");
    case 1: return CStringW(L"JP");
    case 2: return CStringW(L"EN");
    case 3: return CStringW(L"CN");
    case 4: return CStringW(L"FR");
    case 5: return CStringW(L"DE");
    case 6: return CStringW(L"PT");
    case 7: return CStringW(L"ES");
    default: return CStringW(L"");
    }
}

// @0x140651f30
// MS2-FUNCTIONAL: CStringW formatting temp slots differ
CStringW FUN_140651f30(int n)
{
    if (n == 0) return CStringW(L"KR");
    else if (n == 1) return CStringW(L"JP");
    else if (n == 2) return CStringW(L"NA");
    else if (n == 3) return CStringW(L"CN");
    else return CStringW(L"");
}

// @0x140652030
CString FUN_140652030(int n)
{
    switch (n)
    {
    case 0: return CString("KR");
    case 1: return CString("JP");
    case 2: return CString("EN");
    case 3: return CString("CN");
    case 4: return CString("FR");
    case 5: return CString("DE");
    case 6: return CString("PT");
    case 7: return CString("ES");
    default: return CString("");
    }
}

// @0x1406521f0
// MS2-FUNCTIONAL: CString formatting temp slots differ
CString FUN_1406521f0(int n)
{
    if (n == 0) return CString("KR");
    else if (n == 1) return CString("JP");
    else if (n == 2) return CString("NA");
    else if (n == 3) return CString("CN");
    else return CString("");
}

// @0x1406522f0
CString FUN_1406522f0(int n)
{
    return FUN_140652030(n);
}

// @0x140652330
CString FUN_140652330(int n)
{
    return FUN_1406521f0(n);
}

// @0x140650090
void FUN_140650090(CString& s)
{
    FUN_1406500b0(s);
}

// @0x1406500b0
// MS2-FUNCTIONAL: exe has EH-state wrapper (inlined helper) around MakeUpper
int FUN_1406500b0(CString& s)
{
    s.MakeUpper();
    return 1;
}

// @0x1406507a0
// MS2-FUNCTIONAL: CString temp-slot idiom of return-by-value assigned to global differs; switch layout
void FUN_1406507a0(int n)
{
    DAT_143ab0240 = n;
    {
        CString code = FUN_1406522f0(n);
        DAT_143ab0250 = code;
    }
    FUN_140650ac0(n);
    switch (n)
    {
    case 1: FUN_1402be480(DAT_143ab0568, "jp/"); DAT_143aad168 = _create_locale(4, "japanese"); break;
    case 2: FUN_1402be480(DAT_143ab0568, "en/"); DAT_143aad168 = _create_locale(4, "english"); break;
    case 3: FUN_1402be480(DAT_143ab0568, "cn/"); DAT_143aad168 = _create_locale(4, "chinese"); break;
    case 4: FUN_1402be480(DAT_143ab0568, "fr/"); DAT_143aad168 = _create_locale(4, "french"); break;
    case 5: FUN_1402be480(DAT_143ab0568, "de/"); DAT_143aad168 = _create_locale(4, "german"); break;
    case 6: FUN_1402be480(DAT_143ab0568, "pt/"); DAT_143aad168 = _create_locale(4, "portuguese"); break;
    case 7: FUN_1402be480(DAT_143ab0568, "es/"); DAT_143aad168 = _create_locale(4, "spanish"); break;
    default: FUN_1402be480(DAT_143ab0568, "kr/"); DAT_143aad168 = _create_locale(4, "korean");
    }
}

// @0x1406509e0
// MS2-FUNCTIONAL: return-by-value CString temp: exe saves call rax twice, cl emits lea
void FUN_1406509e0(int n)
{
    DAT_143ab0248 = n;
    {
        const CString& code = FUN_140652330(n);
        const CString& code2 = code;
        DAT_143ab0258 = code2;
    }
    DAT_143ab0560 = n;
    if (n == 1) FUN_1402be480(DAT_143ab0588, "jp/");
    else if (n == 2) FUN_1402be480(DAT_143ab0588, "na/");
    else if (n == 3) FUN_1402be480(DAT_143ab0588, "cn/");
    else FUN_1402be480(DAT_143ab0588, "kr/");
}

// @0x140650ac0
// MS2-FUNCTIONAL: switch with 4..7 range check; case ordering not reproduced
void FUN_140650ac0(int n)
{
    switch (n)
    {
    case 1:
        DAT_1439f4840 = 0x3a4;
        break;
    case 2:
        DAT_1439f4840 = 0x4e4;
        break;
    case 3:
        DAT_1439f4840 = 0x3a8;
        break;
    default:
        if (n > 3 && n <= 7)
            DAT_1439f4840 = 0x4e4;
        else
            DAT_1439f4840 = 0x3b5;
        break;
    }
}

MS2_EMIT_CRT_MEMMOVE_S();

// The UCRT's `static __inline memcpy_s` of this TU (unreferenced copy, like memmove_s).
// @0x140652370
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

// @0x1406524c0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9b4b0-0x142c9b520 .text$yd
