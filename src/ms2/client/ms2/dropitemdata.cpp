// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CDropItemData: the dropped item shadow rows (Table/DropIcon.xml) and
// the id -> row cache with its lock (ATL::CAtlMap<int, MS2Ptr<CDropItemData>> instantiations).
// MS2-UNIT: ?\dropitemdata.cpp
// MS2-RANGE: 0x1400e74f0-0x1400e7570 .text$di
// MS2-RANGE: 0x141192960-0x141194290 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@H@ATL@@SA_NAEBH0@Z 0x141193220 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VCDropItemData@@@@UUnk_DropKeyTraits@@V?$CElementTraits@V?$MS2Ptr@VCDropItemData@@@@@ATL@@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x141193490 ; unique
// MS2-PIN: ?Hash@?$CDefaultHashTraits@H@ATL@@SAKAEBH@Z 0x141193580 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\dropitemdata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "dropitemdata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unrecovered helpers (the same ones the other table units use) ----

class Unk_DiLoader { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_DiLoader* FUN_140166420();
class Unk_DiLog { public: void FUN_14015eb90(int level, int flags, const wchar_t* format, const CString& arg); };
Unk_DiLog* FUN_140166440();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);        // Table/<file>
Unk_140165cf0* FUN_140165cf0(TiXmlDocument* pDoc, const char* pszName);       // FirstChildElement of the document
extern int DAT_1439ed00c;                                                     // the table cache is enabled

// The id -> row cache and its lock (the exe constructs them in .text$di, the map first).
struct Unk_DropKeyTraits : ATL::CElementTraits<int> { typedef const int& INARGTYPE; };
static ATL::CAtlMap<int, MS2Ptr<CDropItemData>, Unk_DropKeyTraits> s_mapDropItem(17, 0.75f, 0.25f, 2.25f, 10);
static CLockCriticalSection s_lockDropItem;

// @0x141192960
CDropItemData::CDropItemData()
{
}

// @0x1411929b0
CDropItemData::~CDropItemData()
{
}

// @0x1411929e0
MS2Ptr<CDropItemData> CDropItemData::Get(int nId)
{
    MS2Ptr<CDropItemData> spData(0);
    {
        Unk_LockGuard guard(s_lockDropItem);
        if (guard == 0 && DAT_1439ed00c != 0 && s_mapDropItem.Lookup(nId, spData))
            return spData;
    }
    CString strPath = FUN_14071a5b0(CString("Table"), CString("DropIcon.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return MS2Ptr<CDropItemData>(0);
    Unk_140165cf0* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
    {
        FUN_140166440()->FUN_14015eb90(1, 0x13, L"xml 형식이 잘못 되었습니다[<ms2> {0}]", strPath);
        return MS2Ptr<CDropItemData>(0);
    }
    for (Unk_140165cf0* pNode = pRoot->FUN_140165cf0("dropitem"); pNode != 0; pNode = pNode->FUN_140168650("dropitem"))
    {
        MS2Ptr<CDropItemData> spNew(0);
        spNew.AssignRaw(new CDropItemData);
        int nRowId;
        FUN_1408731e0(pNode, "id", nRowId);
        spNew->m_nId = nRowId;
        FUN_140873360(pNode, "shadowscale", spNew->m_shadow.m_fScale);
        FUN_140873360(pNode, "shadowbias", spNew->m_shadow.m_fBias);
        Unk_LockGuard guard(s_lockDropItem);
        if (guard == 0)
            s_mapDropItem.SetAt(spNew->m_nId, spNew);
    }
    s_mapDropItem.Lookup(nId, spData);
    return spData;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cacb40-0x142cacb80 .text$yd
