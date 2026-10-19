// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The loading screen tips: CLoadingDescription rows,
// CLoadingDescriptionCache and the CLoadingDescriptionTable methods that load Table/loadingDescription.xml
// (<tip id startTime endTime text/>) and pick a tip valid right now, plus the template glue of the row array.
// MS2-UNIT: ?\loadingdescription.cpp
// MS2-RANGE: 0x14144e400-0x14144fd30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$Unk_LdRowPtr@VCLoadingDescription@@@@QEBAPEAVCLoadingDescription@@XZ 0x14144f330 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCLoadingDescriptionCache@@@@QEBAPEAVCLoadingDescriptionCache@@XZ 0x14144f340 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VCLoadingDescriptionCache@@@@AEBAXXZ 0x14144fb40 ; unique
// MS2-PIN: ?Reference@?$MS2Ptr@VCLoadingDescriptionCache@@@@CAXPEAVCLoadingDescriptionCache@@@Z 0x14144fb90 ; prop
// MS2-PIN: ?AddRefImpl@?$Unk_LdRowPtr@VCLoadingDescription@@@@AEBAXPEAX@Z 0x14144fbb0 ; unique
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCLoadingDescriptionCache@@@@AEBAXPEAX@Z 0x14144fbe0 ; prop
// MS2-PIN: ?Release@?$Unk_LdRowPtr@VCLoadingDescription@@@@AEAAXXZ 0x14144fc10 ; unique
// MS2-PIN: ?Release@?$MS2Ptr@VCLoadingDescriptionCache@@@@AEAAXXZ 0x14144fc50 ; unique
// MS2-PIN: ?ReleaseImpl@?$Unk_LdRowPtr@VCLoadingDescription@@@@AEAAXPEAX@Z 0x14144fc90 ; prop
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCLoadingDescriptionCache@@@@AEAAXPEAX@Z 0x14144fce0 ; prop
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\loadingdescription.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/cloadingdescriptiontable.h"

#include <typeinfo>
#include <vector>

#include "ms2/commonfiles/logstring.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of callees emitted in other units ----

class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
CLogString* FUN_140166440();
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
CString FUN_14071ae20(const CString& strFile);                              // path of a table file
CString FUN_14016a5c0(const char* psz, int nCodePage);                      // narrows a string (the RTTI name in CheckInit)
void FUN_140177e10(const CString& str, ATL::CAtlArray<int>& arr, const char* pszDelim);   // split into ints
void FUN_14028faa0(Unk_140165cf0* pParent, const char* pszName, const char* pszAttr, std::vector<Unk_140165cf0*>* pOut);
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);       // attribute text
CStringW FUN_1401bf530(Unk_140165cf0* pNode, const char* pszName, CStringW strDefault);   // wide attribute with default
class Unk_TextFilter { public: void FUN_1416fb380(CStringW& strText); };
Unk_TextFilter* FUN_1403b4750();
unsigned char FUN_1401d1320(CCacheData* pCache);                            // file changed since load

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag (symbols-manual.tsv)
bool CLoadingDescriptionTable::s_bInit;
#endif

// @0x14144fa40
static CMsTime FUN_14144fa40(ATL::CAtlArray<int>& aTime)
{
    return CMsTime(aTime[0], aTime[1], aTime[2], aTime[3], aTime[4], aTime[5]);
}

// @0x14144e400
int CLoadingDescriptionTable::FUN_14144e400()
{
    m_spData.AssignRaw(new CLoadingDescriptionCache);
    CString strFile("loadingDescription.xml");
    CString strPath = FUN_14071ae20(strFile);
    int bOk = LoadXml(CString(strPath));
    if (bOk != 0)
        SetInit(true);
    return bOk;
}

// @0x14144e500
int CLoadingDescriptionTable::FUN_14144e500(CString strUnused)
{
    return 1;
}

// @0x14144e530
void CLoadingDescriptionTable::Clear()
{
    Unk_LockGuard guard(m_spData->m_lock);
    if (guard == 0)
        m_spData->m_descs.RemoveAll();
}

// @0x14144e5b0
void CLoadingDescriptionTable::Add(CLoadingDescriptionCache::DescPtr spDesc)
{
    Unk_LockGuard guard(m_spData->m_lock);
    if (guard == 0)
        m_spData->m_descs.Add(spDesc);
}

// @0x14144e640
CStringW CLoadingDescriptionTable::GetRandomTip()
{
    CheckInit();
    Unk_LockGuard guard(m_spData->m_lock);
    if (guard == 0)
    {
        if (FUN_1401d1320(m_spData) != 0)
        {
            if (LoadXml(CString(*m_spData->FUN_1401d1140())) == 0)
                return CStringW(L"");
        }
        CMsTime now(_time64(0));
        ATL::CAtlArray<CStringW*> aTexts;
        for (unsigned i = 0; i < m_spData->m_descs.GetCount(); i++)
        {
            CLoadingDescriptionCache::DescPtr spDesc(m_spData->m_descs.GetAt(i));
            ATL::CAtlArray<int> aStart;
            FUN_140177e10(spDesc->m_strStart, aStart, "-");
            ATL::CAtlArray<int> aEnd;
            FUN_140177e10(spDesc->m_strEnd, aEnd, "-");
            if (aStart.GetCount() == 6 && aEnd.GetCount() == 6)
            {
                CMsTime tStart = FUN_14144fa40(aStart);
                CMsTime tEnd = FUN_14144fa40(aEnd);
                if (tStart.GetTime() == 0 || !(now < tStart))
                {
                    if (tEnd.GetTime() == 0 || !(now > tEnd))
                        aTexts.Add(&spDesc->m_strText);
                }
            }
        }
        if (aTexts.GetCount() != 0)
        {
            size_t nIndex = (size_t)rand() % aTexts.GetCount();
            return CStringW(*aTexts.GetAt(nIndex));
        }
    }
    return CStringW(L"");
}

// @0x14144eab0
int CLoadingDescriptionTable::LoadXml(CString strPath)
{
    Unk_LockGuard guard(m_spData->m_lock);
    if (guard != 0)
        return 0;
    m_spData->m_descs.RemoveAll();
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    m_spData->FUN_1401d1160(CString(strPath));
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return 0;
    }
    std::vector<Unk_140165cf0*> nodes;
    FUN_14028faa0(pRoot, "tip", "id", &nodes);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        Unk_140165cf0* pNode = nodes[i];
        CLoadingDescriptionCache::DescPtr spDesc(new CLoadingDescription);
        spDesc->m_strId = FUN_14086f4b0(pNode, "id");
        spDesc->m_strStart = FUN_14086f4b0(pNode, "startTime");
        spDesc->m_strEnd = FUN_14086f4b0(pNode, "endTime");
        spDesc->m_strText = FUN_1401bf530(pNode, "text", CStringW(L""));
        spDesc->m_strText.Replace(L"\\n", L"\n");
        FUN_1403b4750()->FUN_1416fb380(spDesc->m_strText);
        m_spData->m_descs.Add(spDesc);
    }
    return 1;
}

// @0x14144f0a0
CLoadingDescription::CLoadingDescription()
{
}

// @0x14144f120
CLoadingDescriptionCache::CLoadingDescriptionCache()
{
}

// @0x14144f220
CLoadingDescription::~CLoadingDescription()
{
}

// @0x14144f280
CLoadingDescriptionCache::~CLoadingDescriptionCache()
{
}

// @0x14144f5a0
void CLoadingDescriptionTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CLoadingDescriptionTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}
