// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The guide-condition classes EquipSkill, Constructable, IsMyHome,
// AchieveTab, EquipItem, UgcManagementTab, DesignItem, ExistItem and the head of CountItem / CountInDoorInstallItem
// (factories, names, loaders and checks). See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: unit_1413a8370
// MS2-RANGE: 0x1413a8370-0x1413a9a50 .text$mn
// MS2-RANGE: 0x1400f4460-0x1400f47fc .text$di
// MS2-RANGE: 0x1413b47c0-0x1413b4800 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// The world manager (FUN_1403ed2d0): only the local player.
class Unk_GcWorld { public: void* FUN_141bd0cc0(); };
Unk_GcWorld* FUN_1403ed2d0();

// The player inventory (global 0x143ab2a90).
class Unk_GuideInvMgr
{
public:
    void FUN_140a60790(ATL::CAtlArray<MS2Ptr<CItem> >& arrOut);   // every item
    int FUN_140a5ece0(int nItemId, int nCount);                   // has nCount of the item
    int FUN_140a60ad0(int nType);
    int FUN_140a60c20(int nType);                                 // the count of an item type
    int FUN_140a60d70(int nIconType);
};
extern Unk_GuideInvMgr DAT_143ab2a90;

// CItem::FUN_140527840's record (item.cpp owns the real one).
class Unk_ItemEquipData : public CItemData { };

// The equip holder of the player (PC::FUN_1416561a0).
class Unk_GcEquipSet { public: MS2Ptr<CEquipItem> FUN_1411e1780(int nSlot, int nKind); };
Unk_GcEquipSet* FUN_1416561a0(void* pPC);
int FUN_1405451c0(const CStringA& strSlotName);             // the equip slot of a slot name

class Unk_GcKeyBinds { };                                   // the key / skill-slot binding table
Unk_GcKeyBinds* FUN_1409331f0();
int FUN_14142e090(Unk_GcKeyBinds* pBinds, int nSkill, int nFlag);   // the skill's slot, -1 = none

class Unk_GcHome { public: bool FUN_1410d5640(); };         // the home state
Unk_GcHome* FUN_1409670e0();
int FUN_141527f60(void* pPC);                               // the cube-construct permission

void* FUN_1412bcec0(unsigned nUIId);                        // the dialog of a ui id
void* FUN_140d61d50(unsigned nUIId);                        // the dialog of a ui id
int FUN_1413b5610(void* pDialog);                           // the page / tab the dialog shows
int FUN_14086f500(Unk_140165cf0* pElem, const char* pszName, int* pOut);

// The slot-55 dialog query (is the dialog hidden).
// A dialog: only slot 55 (is the dialog hidden).
class Unk_GcDialog
{
public:
    virtual void Unk_Slot0(); virtual void Unk_Slot1(); virtual void Unk_Slot2(); virtual void Unk_Slot3(); virtual void Unk_Slot4(); virtual void Unk_Slot5(); 
    virtual void Unk_Slot6(); virtual void Unk_Slot7(); virtual void Unk_Slot8(); virtual void Unk_Slot9(); virtual void Unk_Slot10(); virtual void Unk_Slot11(); 
    virtual void Unk_Slot12(); virtual void Unk_Slot13(); virtual void Unk_Slot14(); virtual void Unk_Slot15(); virtual void Unk_Slot16(); virtual void Unk_Slot17(); 
    virtual void Unk_Slot18(); virtual void Unk_Slot19(); virtual void Unk_Slot20(); virtual void Unk_Slot21(); virtual void Unk_Slot22(); virtual void Unk_Slot23(); 
    virtual void Unk_Slot24(); virtual void Unk_Slot25(); virtual void Unk_Slot26(); virtual void Unk_Slot27(); virtual void Unk_Slot28(); virtual void Unk_Slot29(); 
    virtual void Unk_Slot30(); virtual void Unk_Slot31(); virtual void Unk_Slot32(); virtual void Unk_Slot33(); virtual void Unk_Slot34(); virtual void Unk_Slot35(); 
    virtual void Unk_Slot36(); virtual void Unk_Slot37(); virtual void Unk_Slot38(); virtual void Unk_Slot39(); virtual void Unk_Slot40(); virtual void Unk_Slot41(); 
    virtual void Unk_Slot42(); virtual void Unk_Slot43(); virtual void Unk_Slot44(); virtual void Unk_Slot45(); virtual void Unk_Slot46(); virtual void Unk_Slot47(); 
    virtual void Unk_Slot48(); virtual void Unk_Slot49(); virtual void Unk_Slot50(); virtual void Unk_Slot51(); virtual void Unk_Slot52(); virtual void Unk_Slot53(); 
    virtual void Unk_Slot54(); 
    virtual int vfunc_55();
};
#define DialogSlot55(pDialog) (((Unk_GcDialog*)(pDialog))->vfunc_55())

// ---- CGuideConditionEquipSkill --------------------------------------------------------------------------------------------

// @0x1413a8370
ClassObject* CGuideConditionEquipSkill::CreateObject()
{
    return new CGuideConditionEquipSkill;
}

// @0x1413a83d0
CStringW CGuideConditionEquipSkill::vfunc_1()
{
    return L"CGuideConditionEquipSkill";
}
MS2_REPLACE_METHOD(0x1413A83D0, CGuideConditionEquipSkill, vfunc_1, 61, 0x2B5A5407);

// @0x1413a8420
CGuideConditionEquipSkill::CGuideConditionEquipSkill()
{
    m_nIsEquip = 1;
}

// @0x1413a8460
void CGuideConditionEquipSkill::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    FUN_14086f500(pElem, "isEquip", &m_nIsEquip);
}
MS2_REPLACE_METHOD(0x1413A8460, CGuideConditionEquipSkill, vfunc_2, 63, 0x7F9BBE26);

// @0x1413a84b0
int CGuideConditionEquipSkill::vfunc_3()
{
    unsigned nEquipped = (FUN_14142e090(FUN_1409331f0(), m_n20, 0) != -1);
    return FUN_1413a5600(nEquipped == (unsigned)m_nIsEquip);
}
MS2_REPLACE_METHOD(0x1413A84B0, CGuideConditionEquipSkill, vfunc_3, 110, 0x37B43B46);

// @0x1413a8530
CStringW CGuideConditionEquipSkill::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"value({0}), isEquip({1}))", m_n20, m_nIsEquip));
    return str;
}
MS2_REPLACE_METHOD(0x1413A8530, CGuideConditionEquipSkill, vfunc_7, 179, 0xF55F10F5);

// ---- CGuideConditionConstructable -----------------------------------------------------------------------------------------

// @0x1413a85f0
ClassObject* CGuideConditionConstructable::CreateObject()
{
    return new CGuideConditionConstructable;
}

// @0x1413a8650
CStringW CGuideConditionConstructable::vfunc_1()
{
    return L"CGuideConditionConstructable";
}
MS2_REPLACE_METHOD(0x1413A8650, CGuideConditionConstructable, vfunc_1, 61, 0x849E3953);

// @0x1413a86a0
int CGuideConditionConstructable::vfunc_3()
{
    void* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    return FUN_1413a55a0(FUN_141527f60(pPC));
}
MS2_REPLACE_METHOD(0x1413A86A0, CGuideConditionConstructable, vfunc_3, 66, 0x5819452E);

// ---- CGuideConditionIsMyHome ----------------------------------------------------------------------------------------------

// @0x1413a86f0
ClassObject* CGuideConditionIsMyHome::CreateObject()
{
    return new CGuideConditionIsMyHome;
}

// @0x1413a8750
CStringW CGuideConditionIsMyHome::vfunc_1()
{
    return L"CGuideConditionIsMyHome";
}
MS2_REPLACE_METHOD(0x1413A8750, CGuideConditionIsMyHome, vfunc_1, 61, 0x3B53949D);

// @0x1413a87a0
int CGuideConditionIsMyHome::vfunc_3()
{
    return FUN_1413a5600(FUN_1409670e0()->FUN_1410d5640());
}
MS2_REPLACE_METHOD(0x1413A87A0, CGuideConditionIsMyHome, vfunc_3, 40, 0xA195356B);

// ---- CGuideConditionAchieveTab --------------------------------------------------------------------------------------------

// @0x1413a87d0
ClassObject* CGuideConditionAchieveTab::CreateObject()
{
    return new CGuideConditionAchieveTab;
}

// @0x1413a8830
CStringW CGuideConditionAchieveTab::vfunc_1()
{
    return L"CGuideConditionAchieveTab";
}
MS2_REPLACE_METHOD(0x1413A8830, CGuideConditionAchieveTab, vfunc_1, 61, 0xAB9433D3);

// @0x1413a8880
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionAchieveTab::vfunc_3()
{
    void* pDialog = FUN_1412bcec0(0x4e73);
    int nResult;
    if (pDialog == 0 || DialogSlot55(pDialog) != 0)
        nResult = 0;
    else
        nResult = FUN_1413a5600(m_n20 == FUN_1413b5610(pDialog));
    return nResult;
}
MS2_REPLACE_METHOD(0x1413A8880, CGuideConditionAchieveTab, vfunc_3, 111, 0xAD3B536C);

// ---- CGuideConditionEquipItem ---------------------------------------------------------------------------------------------

// @0x1413a8900
ClassObject* CGuideConditionEquipItem::CreateObject()
{
    return new CGuideConditionEquipItem;
}

// @0x1413a8960
CStringW CGuideConditionEquipItem::vfunc_1()
{
    return L"CGuideConditionEquipItem";
}
MS2_REPLACE_METHOD(0x1413A8960, CGuideConditionEquipItem, vfunc_1, 61, 0x769C1354);

// @0x1413a89b0
void CGuideConditionEquipItem::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nSlotType = 0;
    m_nItemID = 0;
    m_nItemRangeBegin = 0;
    m_nItemRangeLast = 0;
    FUN_140873220(pElem, "slotType", m_nSlotType);
    FUN_1408733e0(pElem, "slotName", m_strSlotName);
    FUN_140873220(pElem, "itemID", m_nItemID);
    FUN_140873220(pElem, "itemRangeBeginID", m_nItemRangeBegin);
    FUN_140873220(pElem, "itemRangeLastID", m_nItemRangeLast);
}
MS2_REPLACE_METHOD(0x1413A89B0, CGuideConditionEquipItem, vfunc_2, 227, 0xCCAFD1BD);

// @0x1413a8aa0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionEquipItem::vfunc_3()
{
    void* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(pPC)->FUN_1411e1780(FUN_1405451c0(m_strSlotName), m_nSlotType);
    if (spEquip == 0)
        return FUN_1413a55a0(0);
    if (m_nItemID != 0 && spEquip->FUN_1411dc820() != (int)m_nItemID)
        return FUN_1413a55a0(0);
    bool bNoItem;
    if (spEquip->FUN_1411dc7a0() == 0)
        bNoItem = true;
    else
        bNoItem = !spEquip->FUN_1411dc7a0()->FUN_140528980();
    if (!bNoItem)
    {
        if (m_nItemRangeBegin != 0 && (unsigned)spEquip->FUN_1411dc820() < m_nItemRangeBegin)
            return FUN_1413a55a0(0);
        if (m_nItemRangeLast != 0 && m_nItemRangeLast < (unsigned)spEquip->FUN_1411dc820())
            return FUN_1413a55a0(0);
        return FUN_1413a55a0(1);
    }
    return FUN_1413a55a0(0);
}
MS2_REPLACE_METHOD(0x1413A8AA0, CGuideConditionEquipItem, vfunc_3, 757, 0x78B4A17E);

// @0x1413a8da0
CStringW CGuideConditionEquipItem::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"slotType({0}), slotName({1}), itemID({2}), itemRange({3}-{4})", m_nSlotType, m_strSlotName, m_nItemID,
                            m_nItemRangeBegin, m_nItemRangeLast));
    return str;
}
MS2_REPLACE_METHOD(0x1413A8DA0, CGuideConditionEquipItem, vfunc_7, 261, 0x4F887A03);

// ---- CGuideConditionUgcManagementTab --------------------------------------------------------------------------------------

// @0x1413a8eb0
ClassObject* CGuideConditionUgcManagementTab::CreateObject()
{
    return new CGuideConditionUgcManagementTab;
}

// @0x1413a8f10
CStringW CGuideConditionUgcManagementTab::vfunc_1()
{
    return L"CGuideConditionUgcManagementTab";
}
MS2_REPLACE_METHOD(0x1413A8F10, CGuideConditionUgcManagementTab, vfunc_1, 61, 0xA7946A55);

// @0x1413a8f60
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionUgcManagementTab::vfunc_3()
{
    void* pDialog = FUN_140d61d50(0x4ec5);
    if (pDialog == 0)
        return 0;
    if (DialogSlot55(pDialog) == 0)
        return FUN_1413a55a0(1);
    return 0;
}
MS2_REPLACE_METHOD(0x1413A8F60, CGuideConditionUgcManagementTab, vfunc_3, 83, 0x25D67B3A);

// ---- CGuideConditionDesignItem --------------------------------------------------------------------------------------------

// @0x1413a8fc0
ClassObject* CGuideConditionDesignItem::CreateObject()
{
    return new CGuideConditionDesignItem;
}

// @0x1413a9020
CStringW CGuideConditionDesignItem::vfunc_1()
{
    return L"CGuideConditionDesignItem";
}
MS2_REPLACE_METHOD(0x1413A9020, CGuideConditionDesignItem, vfunc_1, 61, 0x192C9BF3);

// @0x1413a9070
void CGuideConditionDesignItem::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nItemType = 0;
    m_n18 = 6;
    FUN_1408731e0(pElem, "itemType", m_nItemType);
}
MS2_REPLACE_METHOD(0x1413A9070, CGuideConditionDesignItem, vfunc_2, 87, 0xE90182AD);

// @0x1413a90d0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionDesignItem::vfunc_3()
{
    ATL::CAtlArray<MS2Ptr<CItem> > arrItems;
    DAT_143ab2a90.FUN_140a60790(arrItems);
    for (size_t i = 0; i < arrItems.GetCount(); i++)
    {
        MS2Ptr<CItem> spItem = arrItems.GetAt(i);
        if (!spItem->FUN_140528980())
            continue;
        if (spItem->FUN_140525f10() == 0)
            continue;
        if (spItem->FUN_140525f60() != 0)
            continue;
        if (m_nItemType == 0 || ((Unk_ItemEquipData*)spItem->FUN_140527840())->FUN_14053c5c0() == m_nItemType)
            return FUN_1413a55a0(1);
    }
    return FUN_1413a55a0(0);
}
MS2_REPLACE_METHOD(0x1413A90D0, CGuideConditionDesignItem, vfunc_3, 386, 0xD184D0EF);

// @0x1413a9260
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionDesignItem::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"itemType({0})", GC_ENUM(Unk_GcItemType, m_nItemType)));
    return str;
}
MS2_REPLACE_METHOD(0x1413A9260, CGuideConditionDesignItem, vfunc_7, 167, 0x9A48A0DC);

// @0x1413a9310
int CGuideConditionDesignItem::vfunc_8()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1413A9310, CGuideConditionDesignItem, vfunc_8, 8, 0x7F371472);

// ---- CGuideConditionExistItem ---------------------------------------------------------------------------------------------

// @0x1413a9320
ClassObject* CGuideConditionExistItem::CreateObject()
{
    return new CGuideConditionExistItem;
}

// @0x1413a9380
CStringW CGuideConditionExistItem::vfunc_1()
{
    return L"CGuideConditionExistItem";
}
MS2_REPLACE_METHOD(0x1413A9380, CGuideConditionExistItem, vfunc_1, 61, 0x322D3F81);

// @0x1413a93d0
void CGuideConditionExistItem::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_nItemId = 0;
    m_nItemType = 0;
    m_nIconType = 0;
    FUN_1408731e0(pElem, "itemId", m_nItemId);
    FUN_1408731e0(pElem, "itemType", m_nItemType);
    FUN_1408731e0(pElem, "iconType", m_nIconType);
}
MS2_REPLACE_METHOD(0x1413A93D0, CGuideConditionExistItem, vfunc_2, 157, 0x5F8A74AD);

// @0x1413a9480
int CGuideConditionExistItem::vfunc_3()
{
    if (m_nItemId != 0 && DAT_143ab2a90.FUN_140a5ece0(m_nItemId, 1) == 0)
        return FUN_1413a55a0(0);
    if (m_nItemType != 0 && DAT_143ab2a90.FUN_140a60ad0(m_nItemType) == 0)
        return FUN_1413a55a0(0);
    if (m_nIconType != 0 && DAT_143ab2a90.FUN_140a60d70(m_nIconType) == 0)
        return FUN_1413a55a0(0);
    return FUN_1413a55a0(1);
}
MS2_REPLACE_METHOD(0x1413A9480, CGuideConditionExistItem, vfunc_3, 182, 0x3855BA85);

// @0x1413a9540
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionExistItem::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"itemid({0}), itemType({1}), iconType({2})", GC_ENUM(unsigned, m_nItemId), GC_ENUM(Unk_GcItemType, m_nItemType), GC_ENUM(Unk_GcIconType, m_nIconType)));
    return str;
}
MS2_REPLACE_METHOD(0x1413A9540, CGuideConditionExistItem, vfunc_7, 193, 0x3B640C0B);

// ---- CGuideConditionCountItem ---------------------------------------------------------------------------------------------

// @0x1413a9610
ClassObject* CGuideConditionCountItem::CreateObject()
{
    return new CGuideConditionCountItem;
}

// @0x1413a9670
CStringW CGuideConditionCountItem::vfunc_1()
{
    return L"CGuideConditionCountItem";
}
MS2_REPLACE_METHOD(0x1413A9670, CGuideConditionCountItem, vfunc_1, 61, 0x10E998EE);

// @0x1413a96c0
void CGuideConditionCountItem::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 12;
    m_nItemType = 0;
    m_nMin = -1;
    m_nMax = -1;
    FUN_1408731e0(pElem, "itemType", m_nItemType);
    FUN_1408731e0(pElem, "minValue", m_nMin);
    FUN_1408731e0(pElem, "maxValue", m_nMax);
}
MS2_REPLACE_METHOD(0x1413A96C0, CGuideConditionCountItem, vfunc_2, 169, 0x72FECE38);

// @0x1413a9770
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionCountItem::vfunc_3()
{
    void* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    int nCount = DAT_143ab2a90.FUN_140a60c20(m_nItemType);
    int nResult;
    if (m_nMin == -1 || m_nMin <= nCount)
    {
        if (m_nMax == -1 || nCount <= m_nMax)
            nResult = FUN_1413a55a0(1);
        else
            nResult = FUN_1413a55a0(0);
    }
    else
        nResult = FUN_1413a55a0(0);
    return nResult;
}
MS2_REPLACE_METHOD(0x1413A9770, CGuideConditionCountItem, vfunc_3, 161, 0x33243481);

// @0x1413a9820
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
CStringW CGuideConditionCountItem::vfunc_7()
{
    CStringW str = FUN_1413a5820();
    str.Append(StringFormat(L"itemType({0}), minValue({1}), maxValue({2})", GC_ENUM(Unk_GcItemType, m_nItemType), m_nMin, m_nMax));
    return str;
}
MS2_REPLACE_METHOD(0x1413A9820, CGuideConditionCountItem, vfunc_7, 193, 0xB3E1E02E);

// @0x1413a98f0
int CGuideConditionCountItem::vfunc_8()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1413A98F0, CGuideConditionCountItem, vfunc_8, 8, 0x7F371472);

// ---- CGuideConditionCountInDoorInstallItem --------------------------------------------------------------------------------

// @0x1413a9900
ClassObject* CGuideConditionCountInDoorInstallItem::CreateObject()
{
    return new CGuideConditionCountInDoorInstallItem;
}

// @0x1413a9960
CStringW CGuideConditionCountInDoorInstallItem::vfunc_1()
{
    return L"CGuideConditionCountInDoorInstallItem";
}
MS2_REPLACE_METHOD(0x1413A9960, CGuideConditionCountInDoorInstallItem, vfunc_1, 61, 0x73F62C34);

// @0x1413a99b0
// MS2-FUNCTIONAL: branch layout / instruction order differs from the exe (same calls and conditions)
int CGuideConditionCountInDoorInstallItem::vfunc_3()
{
    void* pPC = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPC == 0)
        return 0;
    int nCount = FUN_1413a9ac0();
    int nResult;
    if (m_nMin == -1 || m_nMin <= nCount)
    {
        if (m_nMax == -1 || nCount <= m_nMax)
            nResult = FUN_1413a55a0(1);
        else
            nResult = FUN_1413a55a0(0);
    }
    else
        nResult = FUN_1413a55a0(0);
    return nResult;
}
MS2_REPLACE_METHOD(0x1413A99B0, CGuideConditionCountInDoorInstallItem, vfunc_3, 151, 0x15929663);

// ---- dynamic initializers (.text$di) -------------------------------------------------------------------------------------

#ifndef MS2_HOOK_DLL
ClassObject* FUN_1413a59a0();

ClassObject* FUN_1413aaed0();
ClassObject* FUN_1413ad660();
void FUN_140316aa0(void* pSlot, CStringW strName, ClassObject* (*pfnFactory)());
void FUN_1401cd100(void*, int);
void FUN_142cb1260();   // the exe's atexit destructor of the map
void FUN_1402a9d70(void*, int, float, float, float, int);
struct Unk_RegMarker {};

// @0x1400f4460
static char s_regTrigger;
static Unk_RegMarker s_initTrigger =
    (FUN_140316aa0(&s_regTrigger, CStringW(L"CGuideConditionTrigger"), FUN_1413a59a0), Unk_RegMarker());

// @0x1400f44b0
static char s_regUgcCollectMoney;
static Unk_RegMarker s_initUgcCollectMoney =
    (FUN_140316aa0(&s_regUgcCollectMoney, CStringW(L"CGuideConditionUgcCollectMoney"), FUN_1413aaed0), Unk_RegMarker());

// @0x1400f4500
static char s_regUgcManagementTab;
static Unk_RegMarker s_initUgcManagementTab =
    (FUN_140316aa0(&s_regUgcManagementTab, CStringW(L"CGuideConditionUgcManagementTab"), CGuideConditionUgcManagementTab::CreateObject), Unk_RegMarker());

// @0x1400f4550
static char s_regUgcProductExpireDays;
static Unk_RegMarker s_initUgcProductExpireDays =
    (FUN_140316aa0(&s_regUgcProductExpireDays, CStringW(L"CGuideConditionUgcProductExpireDays"), FUN_1413ad660), Unk_RegMarker());

// @0x1400f45a0
static CStringA s_EnumNamesA[8] = { "None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd" };

// @0x1400f4670
static CStringA s_EnumNamesB[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

// @0x1400f4730
static CStringA s_strSkill("skill");

// @0x1400f4760
static CStringA s_strStun("stun");

// @0x1400f4790
static char s_8f78[8];
static Unk_RegMarker s_init8f78 = (FUN_1401cd100(&s_8f78, 0), Unk_RegMarker());

// @0x1400f47b0
static char s_8f80[0x30];
static Unk_RegMarker s_init8f80 = (FUN_1402a9d70(&s_8f80, 0x11, 0.75f, 0.25f, 2.25f, 10), atexit(FUN_142cb1260), Unk_RegMarker());
#endif
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cb11c0-0x142cb1260 .text$yd
