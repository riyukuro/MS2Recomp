// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CostumeSet / CostumeSetTable: Table/CostumeSet.xml, the
// costume sets (by set id and gender) with their slot items and transparency slots.
// MS2-UNIT: unit_140535bc0
// MS2-RANGE: 0x1400b9690-0x1400b97a0 .text$di
// MS2-RANGE: 0x140535bc0-0x140539370 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?Read@?$Value@H@Constants@Common@@QEAAHXZ 0x140536a30 ; unique
// MS2-PIN: ??0CNode@?$CAtlMap@IV?$MS2SvrPtr@VCostumeSet@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2SvrPtr@VCostumeSet@@@@@3@@ATL@@QEAA@II@Z 0x140536df0 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@IV?$MS2SvrPtr@VCostumeSet@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2SvrPtr@VCostumeSet@@@@@3@@ATL@@IEAA@I@Z 0x140536e70 ; unique
// MS2-PIN: ?CreateNode@?$CAtlMap@IV?$MS2SvrPtr@VCostumeSet@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2SvrPtr@VCostumeSet@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x1405372d0 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HHV?$CDefaultElementTraits@H@ATL@@V?$CElementTraits@H@2@@ATL@@AEBAPEAVCNode@12@AEBHAEAI1AEAPEAV312@@Z 0x140537800 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@IV?$MS2SvrPtr@VCostumeSet@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2SvrPtr@VCostumeSet@@@@@3@@ATL@@AEAAPEAVCNode@12@III@Z 0x140537cb0 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@IV?$MS2SvrPtr@VCostumeSet@@@@V?$CElementTraits@I@ATL@@V?$CElementTraits@V?$MS2SvrPtr@VCostumeSet@@@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBV?$MS2SvrPtr@VCostumeSet@@@@@Z 0x140538c90 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@H@ATL@@SA_NAEBH0@Z 0x140537280
// MS2-PIN: ?Hash@?$CDefaultHashTraits@H@ATL@@SAKAEBH@Z 0x1405378f0
// MS2-PIN: ??_7CostumeSetTable@@6B?$TSingleton@VCostumeSetTable@@@@@ 0x142d589d0
// MS2-PIN: ??_7CostumeSetTable@@6B?$CValidData@VCostumeSetTable@@@@@ 0x142d589e0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/costumesettable.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include <typeinfo>
#include "hook/ms2hook.h"

// Header statics of this unit: the slot-type -> Transparency constant map (filled by the first CostumeSetTable),
// constructed before the sort names.
static CostumeSlotMap s_mapSlotType(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// Unrecovered helpers (the xml loader helpers the other table units use).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); Unk_140165cf0* FUN_140168650(const char*); };
class Unk_140166420 { public: int FUN_1403974b0(TiXmlDocument* doc, const char* path, int a, bool b, bool c); };
Unk_140166420* FUN_140166420();
void* FUN_140166440();
void FUN_14015eb90(void*, int, int, const wchar_t*, const CString&);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
CString FUN_14016a5c0(const char* psz, int n);                           // undecorated class name
bool FUN_14028f710(Unk_140165cf0* pElem);                                // element is enabled
int FUN_140873220(Unk_140165cf0* pElem, const char* pszName, unsigned& nOut);
int FUN_1408731e0(Unk_140165cf0* pElem, const char* pszName, int& nOut);
int FUN_1408733e0(Unk_140165cf0* pElem, const char* pszName, CString& strOut);
void FUN_14015f050(CString& str, ATL::CAtlArray<CString>& rOut, const char* pszSep);   // split into strings
int FUN_1405451c0(const CString& str);                                   // text -> number
CString FUN_1405451e0(unsigned n);                                       // number -> text
void* FUN_1406aeee0();
bool FUN_1406af060(void* p);
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
extern unsigned FUN_14054b400(ItemModelData*);
unsigned char FUN_1401d1320(CCacheData*);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's singleton and init flag (symbols-manual.tsv)
CostumeSetTable* TSingleton<CostumeSetTable>::s_instance;
bool CostumeSetTable::s_bInit;
#endif

// @0x140535bc0
CostumeSet::CostumeSet()
    : m_nSetId(0)
{
}

// @0x140535c80
CostumeSet::~CostumeSet()
{
}

// @0x140535cd0
CostumeSetTable::CostumeSetTable()
{
    if (s_mapSlotType.GetCount() == 0)
    {
        int nSlot1 = 6;
        s_mapSlotType.SetAt(nSlot1, FUN_1401d3200()->TransparencyCP.Read());
        int nSlot2 = 0xd;
        s_mapSlotType.SetAt(nSlot2, FUN_1401d3200()->TransparencyEY.Read());
        int nSlot3 = 8;
        s_mapSlotType.SetAt(nSlot3, FUN_1401d3200()->TransparencyCL.Read());
        int nSlot4 = 9;
        s_mapSlotType.SetAt(nSlot4, FUN_1401d3200()->TransparencyPA.Read());
        int nSlot5 = 7;
        s_mapSlotType.SetAt(nSlot5, FUN_1401d3200()->TransparencyMT.Read());
        int nSlot6 = 0xe;
        s_mapSlotType.SetAt(nSlot6, FUN_1401d3200()->TransparencyEA.Read());
        int nSlot7 = 0xc;
        s_mapSlotType.SetAt(nSlot7, FUN_1401d3200()->TransparencyFH.Read());
        int nSlot8 = 10;
        s_mapSlotType.SetAt(nSlot8, FUN_1401d3200()->TransparencyGL.Read());
        int nSlot9 = 0x10;
        s_mapSlotType.SetAt(nSlot9, FUN_1401d3200()->TransparencyRI.Read());
        int nSlot10 = 0xb;
        s_mapSlotType.SetAt(nSlot10, FUN_1401d3200()->TransparencySH.Read());
    }
    Load();
}

// @0x140535f80
CostumeSetTable::~CostumeSetTable()
{
}

// @0x140536030
int CostumeSetTable::Load()
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (LoadXml() == 0)
            return 0;
    }
    SetInit(true);
    return 1;
}

// @0x1405360b0
// MS2-FUNCTIONAL: one trailing nop in the lock-held path (the exe returns the unfilled result there)
CostumeSetPtr CostumeSetTable::GetSet(unsigned nSetId, int nGender)
{
    if (nGender < 0 && 2 < nGender)
        return CostumeSetPtr(0);
    CheckInit();
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (FUN_1401d1320(m_cache.get()) != 0)
            Load();
        CostumeSetPtr spSet(0);
        m_sets[nGender].Lookup(nSetId, spSet);
        return spSet;
    }
}

#ifndef MS2_HOOK_DLL
// @0x1405361e0
// MS2-FUNCTIONAL: EH-state/temp-CString layout of the XML loader differs from the exe (precedent vipgoods.cpp, banktable.cpp)
int CostumeSetTable::LoadXml()
{
    for (unsigned i = 0; i < 2; i++)
        m_sets[i].RemoveAll();
    CString strPath = FUN_14071a5b0(CString("Table"), CString("CostumeSet.xml"));
    m_cache.AssignRaw(new CCacheData);
    m_cache.get()->FUN_1401d1160(CString(strPath));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return 0;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return 0;
    }
    for (Unk_140165cf0* pSet = pRoot->FUN_140165cf0("costumeSet"); pSet != 0; pSet = pSet->FUN_140168650("costumeSet"))
    {
        if (!FUN_14028f710(pSet))
            continue;
        unsigned nSetId = 0;
        FUN_140873220(pSet, "id", nSetId);
        for (Unk_140165cf0* pNode = pSet->FUN_140165cf0("set"); pNode != 0; pNode = pNode->FUN_140168650("set"))
        {
            CostumeSetPtr spSet(new CostumeSet);
            spSet->m_nSetId = nSetId;
            int nGender = 0;
            FUN_1408731e0(pNode, "gender", nGender);
            if (nGender < 0 && 2 < nGender)
                continue;
            CString strSlots;
            ATL::CAtlArray<CString> arrSlots;
            FUN_1408733e0(pNode, "transparencySlots", strSlots);
            FUN_14015f050(strSlots, arrSlots, ",");
            for (unsigned i = 0; i < arrSlots.GetCount(); i++)
            {
                int nSlot = FUN_1405451c0(arrSlots[i]);
                if (nSlot != 0)
                {
                    int nValue = 0;
                    if (s_mapSlotType.Lookup(nSlot, nValue))
                        spSet->m_mapTransparency.SetAt(nSlot, nValue);
                }
            }
            for (unsigned nIndex = 0; nIndex < 0x14; nIndex++)
            {
                unsigned nKey = nIndex;
                if (spSet->m_mapTransparency.Lookup(nKey) == 0)
                {
                    CString strNumber = FUN_1405451e0(nKey);
                    CString strAttr = Unk_SocketFormat("slot_{0}", strNumber);
                    unsigned nItemId = 0;
                    FUN_140873220(pNode, strAttr, nItemId);
                    if (nItemId != 0)
                    {
                        if (!FUN_1406af060(FUN_1406aeee0()))
                        {
                            MS2Ptr<CItemData> item = FUN_14053f870(nItemId);
                            if (item == 0)
                            {
                                FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
                                return 0;
                            }
                            if (FUN_14054b400(item->FUN_14053eba0()) != nKey)
                            {
                                FUN_14015eb90(FUN_140166440(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
                                return 0;
                            }
                        }
                        spSet->m_mapSlotItems.SetAt(nKey, nItemId);
                    }
                }
            }
            m_sets[nGender].SetAt(spSet->m_nSetId, spSet);
        }
    }
    return 1;
}
#endif

// @0x1405371d0
void CostumeSetTable::CheckInit()
{
    if (!s_bInit)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CostumeSetTable).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}

// @0x140539250
MS2_EMIT_CRT_MEMMOVE_S();
