// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). FusionSlotBag (the fusion windows' item bag).
// MS2-UNIT: ?\fusionslotbag.cpp
// MS2-RANGE: 0x14123a080-0x14123b2b0 .text$mn
// MS2-RANGE: 0x1400ea080-0x1400ea210 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400ea160 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400ea190 ; probe
// MS2-PIN: ??$?8PEAVFusionSlotBag@@P80@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@YA_NAEBU?$pair@PEAVFusionSlotBag@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@0@0@Z 0x14123a880 ; prop
// MS2-PIN: ??$?8PEAVUIItemMergeOptionDialog@@P80@EAAHAEAVItemInfoSlot@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemMergeOptionDialog@@P81@EAAHAEAVItemInfoSlot@@@Z@0@0@Z 0x14123a8f0 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVFusionSlotBag@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@QEAA@AEBV01@@Z 0x14123ab30 ; prop
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIItemMergeOptionDialog@@P81@EAAHAEAVItemInfoSlot@@@Z@std@@@?$Delegate@$$A6AHAEAVItemInfoSlot@@@Z@@QEAA@AEBV01@@Z 0x14123abd0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVFusionSlotBag@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEAAPEAXI@Z 0x14123acf0 ; prop
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIItemMergeOptionDialog@@P81@EAAHAEAVItemInfoSlot@@@Z@std@@@?$Delegate@$$A6AHAEAVItemInfoSlot@@@Z@@UEAAPEAXI@Z 0x14123ad30 ; prop
// MS2-PIN: ?TypeCast@FusionSlotBag@@UEBA_NIPEAPEAX@Z 0x14123ae80 ; unique
// MS2-PIN: ?TypeCast@FusionSlotBag@@UEBA_NIPEAPEBX@Z 0x14123aed0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVFusionSlotBag@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14123af20 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIItemMergeOptionDialog@@P81@EAAHAEAVItemInfoSlot@@@Z@std@@@?$Delegate@$$A6AHAEAVItemInfoSlot@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x14123af80 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVFusionSlotBag@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14123b0d0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemMergeOptionDialog@@P81@EAAHAEAVItemInfoSlot@@@Z@std@@@?$Delegate@$$A6AHAEAVItemInfoSlot@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x14123b130 ; unique
// MS2-PINS-END tplpin
// (units.tsv lists 0x1400ea080-0x1400ea350; 0x1400ea210-0x1400ea350 starts with GameObject's ClassInfo initializer, which
// belongs to client\ms2\gameobject.cpp, so it is not claimed here.)
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\fusionslotbag.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "fusionslotbag.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
// The item merge option dialog (id 0x4e68); only the slot callback is used here.
class UIItemMergeOptionDialog : public UIDialog
{
public:
    int FUN_1419d27e0(ItemInfoSlot& slot);              // may the slot's tooltip be shown
};

// The enchant data object of an item (a CItemStatus).
class Unk_ItemEnchantData
{
public:
    bool FUN_140630810();                               // the item is merged
};

// UI service: handle to a registered UI object.
class Unk_FusionUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nClass); };
Unk_FusionUIManager* FUN_1403ed2b0();

// The ItemInfoSlot setters take Delegates over references here (the exe's signature); same entries as
// ItemInfoSlot::SetSlotFn / SetCanFn.
typedef Delegate<void(ItemInfoSlot&, ASSlot&)> FusionSlotFn;
typedef Delegate<int(ItemInfoSlot&)> FusionCanFn;
void FUN_141416650(ItemInfoSlot* pSlot, FusionSlotFn fn);
void FUN_1414166f0(ItemInfoSlot* pSlot, FusionCanFn fn);

MS2Ptr<CItem> FUN_1419be700(unsigned __int64 uid);      // find an item by uid
float FUN_140bf4fd0(float f);

void FUN_14123a190(const CString& strName);
FusionSlotBag* FUN_14123a960(NotifyContext::BindData* p);
UIItemMergeOptionDialog* FUN_14123a9b0(int nClass);

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);
void FUN_1422cc9e0(DragSlotBag* pBag);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(FusionSlotBag);

// Header-defined statics (same in every obj that includes the shared item header).
#include "ms2/placeholder/header_statics_a.h"

// @0x14123a080
void FUN_14123a080(const CString& strName, const ATL::CAtlArray<unsigned __int64>& items)
{
    FusionSlotBag* pBag = new (efd::MemHint(efd::MemHint::NONE)) FusionSlotBag(strName, 0, items);
    if (pBag)
    {
        int nCount = (int)(FUN_140bf4fd0((float)items.GetCount() / 4.0f) * 4.0f);
        static_cast<DragSlotBag*>(pBag)->vfunc_10(nCount > 12 ? nCount : 12);
        FUN_1422c8f10(strName, pBag);
    }
}

// @0x14123a190
void FUN_14123a190(const CString& strName)
{
    FusionSlotBag* pBag = FUN_14123a960(FUN_1422c8e90(strName));
    if (pBag)
    {
        FUN_1422cc9e0(pBag);
        FUN_1422c8f70(strName);
    }
}

// @0x14123a1e0
FusionSlotBag::FusionSlotBag(const CString& strName, int nType, const ATL::CAtlArray<unsigned __int64>& items)
    : DragSlotBag(strName), m_nType(nType)
{
    m_uids.Copy(items);
}

// @0x14123a270
FusionSlotBag::~FusionSlotBag()
{
}

// @0x14123a2b0
CString FusionSlotBag::vfunc_15(int nIndex)
{
    return DragSlotBag::vfunc_15(nIndex);
}

// @0x14123a300
DragSlot* FusionSlotBag::vfunc_16(int nIndex)
{
    int nIconType = 0x3b3;
    MS2Ptr<CItem> spItem(0);
    if (m_uids.GetCount() > (size_t)nIndex)
        spItem = FUN_1419be700(m_uids.GetAt(nIndex));
    ItemInfoSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) ItemInfoSlot(vfunc_15(nIndex), spItem, nIndex, nIconType, 0);
    UIItemMergeOptionDialog* pDlg = FUN_14123a9b0(0x4e68);
    if (pDlg)
    {
        FUN_1414166f0(pSlot, FusionCanFn(pDlg, &UIItemMergeOptionDialog::FUN_1419d27e0));
        FUN_141416650(pSlot, FusionSlotFn(this, &FusionSlotBag::FUN_14123a650));
    }
    return pSlot;
}

// @0x14123a650
void FusionSlotBag::FUN_14123a650(ItemInfoSlot& slot, ASSlot& as)
{
    MS2Ptr<CItem> spItem = slot.vfunc_25();
    if (spItem.get() != 0)
        as.FUN_1407cbbe0("mergeStep", ((Unk_ItemEnchantData*)((CItem*)spItem)->FUN_1405278a0())->FUN_140630810());
}

// @0x14123a960
FusionSlotBag* FUN_14123a960(NotifyContext::BindData* p)
{
    FusionSlotBag* pBag = 0;
    if (p != 0 && p->TypeCast(0x6200043, (void**)&pBag))
        return pBag;
    else
        return 0;
}

// @0x14123a9b0
UIItemMergeOptionDialog* FUN_14123a9b0(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObj = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObj.get() != 0)
            return dynamic_cast<UIItemMergeOptionDialog*>(spObj.operator->());
    }
    return 0;
}

template<> Delegate<int(ItemInfoSlot&)>::DelegateImplBase::DelegateImplBase() {}
template<> Delegate<int(ItemInfoSlot&)>::DelegateImplBase::~DelegateImplBase() {}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE(0x14123A080, FUN_14123a080, 259, 0x8838E096);
MS2_REPLACE(0x14123A190, FUN_14123a190, 65, 0x50282A7F);
MS2_REPLACE_METHOD(0x14123A2B0, FusionSlotBag, vfunc_15, 68, 0x46698DDD);
MS2_REPLACE_METHOD(0x14123A300, FusionSlotBag, vfunc_16, 828, 0x4AC84617);
MS2_REPLACE_METHOD(0x14123A650, FusionSlotBag, FUN_14123a650, 131, 0xDF09E79C);
MS2_REPLACE(0x14123A960, FUN_14123a960, 73, 0xA87B8FD9);
MS2_REPLACE(0x14123A9B0, FUN_14123a9b0, 147, 0x2FD00ACC);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cadd80-0x142cade10 .text$yd
