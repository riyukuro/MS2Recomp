// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CGraphicOptionTable: the graphics quality levels from
// Table/graphicOption.xml (which levels allow hdr / mirror / shimmer / multisample, the shadow quality names).
// MS2-UNIT: ?\graphicoptiontable.cpp
// MS2-RANGE: 0x141375cb0-0x141376d00 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\graphicoptiontable.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cgraphicoptiontable.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);              // FirstChildElement
    Unk_140165cf0* FUN_140168650(const char* pszName);              // NextSiblingElement
};
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* GetLogString();
void FUN_14036e770(CLogString* log, int level, int category, const wchar_t* format, const CStringW& arg);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CStringW FUN_14016a730(const char* psz, int n);                         // narrow -> wide
CString FUN_14015f710(Unk_140165cf0* pElem, const char* pszName, CString strDefault);   // string attribute
void* FUN_14086f500(Unk_140165cf0* pElem, const char* pszName, int* pnValue);           // int attribute
bool FUN_140184310(const CString& str, const char* psz);                // str == psz

// @0x141375cb0
CGraphicOptionTable::CGraphicOptionTable()
    : m_mapLevel(17, 0.75f, 0.25f, 2.25f, 10), m_mapShadow1(17, 0.75f, 0.25f, 2.25f, 10),
      m_mapShadow2(17, 0.75f, 0.25f, 2.25f, 10)
{
    Load();
}

// @0x141375dd0
CGraphicOptionTable::~CGraphicOptionTable()
{
}

// @0x141375e50
// MS2-FUNCTIONAL: frame is 0x60 larger and the EH state layout differs (temp CString placement in the error paths)
void CGraphicOptionTable::Load()
{
    if (FUN_140166420()->FUN_1403974b0(&m_doc, FUN_14071a5b0(CString("Table"), CString("graphicOption.xml")), 0, true, false) == 0)
    {
        FUN_14036e770(GetLogString(), 1, 0x13, L"파일을 읽을 수 없습니다[{0}]",
                      FUN_14016a730(FUN_14071a5b0(CString("Table"), CString("graphicOption.xml")), 0));
    }
    else
    {
        Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&m_doc)->FUN_140165cf0("ms2");
        if (pRoot == 0)
        {
            FUN_14036e770(GetLogString(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]",
                          FUN_14016a730(FUN_14071a5b0(CString("Table"), CString("graphicOption.xml")), 0));
        }
        else
        {
            CString strKey;
            int nValue;
            for (Unk_140165cf0* pOption = pRoot->FUN_140165cf0("option"); pOption != 0; pOption = pOption->FUN_140168650("option"))
            {
                CString strName = FUN_14015f710(pOption, "name", CString(""));
                for (unsigned int i = 1; i < 6; i++)
                {
                    strKey.Format("option%d", i);
                    FUN_14086f500(pOption, strKey, &nValue);
                    if (!FUN_140184310(strName, "multisample"))
                    {
                        if (nValue != 0)
                        {
                            int nLevel = i - 1;
                            m_mapLevel.SetAt(strName, nLevel);
                            break;
                        }
                    }
                    else
                    {
                        m_multisample[i - 1] = nValue;
                    }
                }
            }
            for (Unk_140165cf0* pShadow = pRoot->FUN_140165cf0("shadow"); pShadow != 0; pShadow = pShadow->FUN_140168650("shadow"))
            {
                CString strName = FUN_14015f710(pShadow, "name", CString(""));
                int bSet1 = 0;
                int bSet2 = 0;
                for (unsigned int i = 1; i < 6; i++)
                {
                    strKey.Format("option%d", i);
                    FUN_14086f500(pShadow, strKey, &nValue);
                    if (nValue == 1 && bSet1 == 0)
                    {
                        int nLevel1 = i - 1;
                        m_mapShadow1.SetAt(strName, nLevel1);
                        bSet1 = 1;
                    }
                    if (nValue == 2 && bSet2 == 0)
                    {
                        int nLevel2 = i - 1;
                        m_mapShadow2.SetAt(strName, nLevel2);
                        bSet2 = 1;
                    }
                }
            }
        }
    }
}

// @0x1413764c0
void CGraphicOptionTable::Clear()
{
    m_mapLevel.RemoveAll();
    m_mapShadow1.RemoveAll();
    m_mapShadow2.RemoveAll();
}

// @0x141376510
int CGraphicOptionTable::IsHdrSupported(unsigned int nLevel)
{
    unsigned int nMin = 0;
    if (m_mapLevel.Lookup("hdr", nMin))
        return nLevel >= nMin;
    return 0;
}

// @0x141376580
int CGraphicOptionTable::IsMirrorSupported(unsigned int nLevel)
{
    unsigned int nMin = 0;
    if (m_mapLevel.Lookup("mirror", nMin))
        return nLevel >= nMin;
    return 0;
}

// @0x1413765f0
int CGraphicOptionTable::IsShimmerSupported(unsigned int nLevel)
{
    unsigned int nMin = 0;
    if (m_mapLevel.Lookup("shimmer", nMin))
        return nLevel >= nMin;
    return 0;
}

// @0x141376660
int CGraphicOptionTable::GetMultisample(unsigned int nLevel)
{
    int aSamples[9] = {0, 0, 0x10000, 0x20000, 0x30000, 0x40000, 0x50000, 0x60000, 0x70000};
    unsigned int nIndex = m_multisample[nLevel];
    unsigned int nCount = 9;
    if (nIndex >= nCount || nIndex < 0)
        nIndex = 0;
    return aSamples[nIndex];
}

// @0x141376720
int CGraphicOptionTable::GetMultisampleIndex(unsigned int nLevel)
{
    int nResult = 0;
    switch (GetMultisample(nLevel))
    {
    case 0:
        nResult = 0;
        break;
    case 0x10000:
        nResult = 1;
        break;
    case 0x30000:
        nResult = 2;
    }
    return nResult;
}

// @0x141376790
int CGraphicOptionTable::GetMultisampleValue(int nIndex)
{
    int nResult = 0;
    switch (nIndex)
    {
    case 0:
        nResult = 0;
        break;
    case 1:
        nResult = 0x10000;
        break;
    case 2:
        nResult = 0x30000;
    }
    return nResult;
}

// @0x1413767f0
unsigned int CGraphicOptionTable::FindLevel(int nHdr, int nMirror, int nShimmer)
{
    for (unsigned int nLevel = 0; nLevel < 5; nLevel++)
    {
        if (IsHdrSupported(nLevel) != nHdr)
            continue;
        if (IsMirrorSupported(nLevel) != nMirror)
            continue;
        if (IsShimmerSupported(nLevel) != nShimmer)
            continue;
        return nLevel;
    }
    return 0;
}

// @0x141376880
int CGraphicOptionTable::GetShadowOption(int nKind)
{
    CString strName;
    switch (nKind)
    {
    case 0:
        strName = "myPC";
        break;
    case 1:
        strName = "PC";
        break;
    case 2:
        strName = "monster";
        break;
    case 3:
        strName = "bossMonster";
        break;
    case 4:
        strName = "dropItem";
        break;
    case 5:
        strName = "mapObject";
    }
    int nValue = -1;
    m_mapShadow2.Lookup(strName, nValue);
    int nResult;
    if (nValue == -1)
        nResult = 5;
    else
        nResult = nValue;
    return nResult;
}

// @0x1413769d0
int CGraphicOptionTable::GetShadowOptionOffset(int nKind)
{
    CString strName;
    switch (nKind)
    {
    case 0:
        strName = "myPC";
        break;
    case 1:
        strName = "PC";
        break;
    case 2:
        strName = "monster";
        break;
    case 3:
        strName = "bossMonster";
        break;
    case 4:
        strName = "dropItem";
        break;
    case 5:
        strName = "mapObject";
    }
    int nValue = -1;
    m_mapShadow1.Lookup(strName, nValue);
    int nResult;
    if (nValue == -1)
        nResult = 0;
    else
        nResult = nValue;
    return nResult;
}

MS2_EMIT_CRT_MEMMOVE_S();
