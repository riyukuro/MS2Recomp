// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIItemMergeRevertDialog: see uiitemmergerevertdialog.h.
// MS2-UNIT: ?\uiitemmergerevertdialog.cpp
// MS2-RANGE: 0x1400d84b0-0x1400d8630 .text$di
// MS2-RANGE: 0x140e4c050-0x140e4df70 .text$mn
// MS2-RANGE: 0x142ca6a90-0x142ca6af0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSortTypeNames2@@YAXXZ 0x1400d84b0 ; probe
// MS2-PIN: ??__Es_strSortTypeNames@@YAXXZ 0x1400d8570 ; probe
// MS2-PIN: ??$?8PEAVUIItemMergeRevertDialog@@P80@EAAXAEAVItemScrollSlot@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@@Z@0@0@Z 0x140e4d6c0 ; prop
// MS2-PIN: ??$?8PEAVUIItemMergeRevertDialog@@P80@EAAXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@std@@YA_NAEBU?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@0@0@Z 0x140e4d730 ; prop
// MS2-PIN: ??1?$DelegateImpl@U?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@@UEAA@XZ 0x140e4da10 ; order
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemScrollSlot@@@Z@@UEAAPEAXI@Z 0x140e4da90 ; order
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@@UEAAPEAXI@Z 0x140e4dad0 ; order
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemScrollSlot@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e4dbe0 ; unique
// MS2-PIN: ?GetTypeName@?$DelegateImpl@U?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e4dc40 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemScrollSlot@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e4dd90 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140e4ddf0 ; unique
// MS2-PIN: ??__Fs_strSortTypeNames2@@YAXXZ 0x142ca6a90 ; probe
// MS2-PIN: ??__Fs_strSortTypeNames@@YAXXZ 0x142ca6ac0 ; probe
// MS2-PINS-END tplpin
// MS2-PIN: ??1UIItemMergeRevertDialog@@UEAA@XZ 0x140e4da70
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemScrollSlot@@@Z@@QEAA@AEBV01@@Z 0x140e4d870
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIItemMergeRevertDialog@@P81@EAAXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemScrollSlot@@PEAVDragSlot@@@Z@@QEAA@AEBV01@@Z 0x140e4d910
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiitemmergerevertdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "uiitemmergerevertdialog.h"
#include "itemscrollslot.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di): the sort-name table of the shared item header, twice (two headers of the unit pull it in) ----
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of exe objects ----

typedef Delegate<void(ItemScrollSlot&)> Unk_MrRemoveFn;
typedef Delegate<void(ItemScrollSlot&, DragSlot*)> Unk_MrDropFn;
template<> Unk_MrRemoveFn::DelegateImplBase::DelegateImplBase();
template<> Unk_MrDropFn::DelegateImplBase::DelegateImplBase();
template<> Unk_MrRemoveFn::DelegateImplBase::~DelegateImplBase();
template<> Unk_MrDropFn::DelegateImplBase::~DelegateImplBase();

// The inventory's bag of items by uid.
class Unk_MrInventory { public: MS2Ptr<CItem> FUN_140a5d680(__int64 nUid); };
extern Unk_MrInventory DAT_143ab2a90;

// The inventory slot (invenslot.cpp) a slot can be dropped on: id 0x6200023.
class Unk_MrInvenSlot : public DragSlot
{
public:
    __int64 FUN_141405a10();                            // the uid of the item in the slot
};
Unk_MrInvenSlot* FUN_140a50b50(DragSlot* pSlot);        // pSlot->TypeCast(0x6200023), 0 on failure

// The item price table (global of the lua state, FUN_1401c0db0).
class Unk_MrPrice { public: __int64 FUN_140679790(int nRank, int nType); };
Unk_MrPrice* FUN_1401c0db0();

// The item option text builder (FUN_1409eecf0).
class Unk_MrOptionText { public: CStringW FUN_1405c1090(MS2Ptr<CItem> spItem, int nFlags); };
Unk_MrOptionText* FUN_1409eecf0();

// The slot registry (see unit_1400d2c20.cpp / itemexchangeslot.cpp).
void FUN_140d42540(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem);
void FUN_140d42630(const CString& strName);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
ItemScrollSlot* FUN_140d42c30(NotifyContext::BindData* p);
void FUN_140d42b70(ItemScrollSlot* pSlot, Unk_MrDropFn fn);        // SetDropFn (the exe's delegate takes ItemScrollSlot&)
void FUN_140d42bc0(ItemScrollSlot* pSlot, Unk_MrRemoveFn fn);      // SetRemoveFn

void FUN_140710590(COutPacket&);                                    // send
__int64 FUN_140718370(const CStringW& str);                         // the uid in the text
bool FUN_140630810(void* pEnchantData);                             // the item has merge options
CStringW FUN_14028b8e0(const CStringW& strKey);                     // string table text
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);    // string table text with one argument
CStringW FUN_140656190(const wchar_t* pszFormat, const CStringW& strArg0, const CStringW& strArg1);
void FUN_14083d2b0(CStringW& str);
CStringW FUN_141b71910(__int64 nUid);                               // the uid as text
void FUN_1412751f0(const CStringW& text, int nA, int nB);           // notice

// @0x1400d84b0 / @0x1400d8570: the two sort-name tables above (see MS2-RANGE .text$di)

// @0x140e4c050
UIItemMergeRevertDialog::UIItemMergeRevertDialog()
{
    FUN_141924170(1);
    m_164 = 1;
    m_nItemUid = 0;
}

// @0x140e4c0d0
CString UIItemMergeRevertDialog::GetTypeName()
{
    return "ItemMergeRevertDialog";
}

// @0x140e4c120
int UIItemMergeRevertDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    return 1;
}

// @0x140e4c150
void UIItemMergeRevertDialog::vfunc_67()
{
    m_nItemUid = 0;
    FUN_140d42630(GetTypeName());
    UIDialog::vfunc_67();
}

// @0x140e4c1d0
void UIItemMergeRevertDialog::vfunc_72()
{
    vfunc_55();
}

// @0x140e4c200
void UIItemMergeRevertDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140e4c440();
}

// @0x140e4c230
int UIItemMergeRevertDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onOk") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            __int64 nUid = FUN_140718370(data.FUN_1422b8f40());
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
            if (spItem.IsNull())
                return 1;
            if (FUN_140e4d330(spItem.get()) != 0)
                return 1;
            COutPacket packet(0x3f, 0);
            packet.vfunc_o10_1(6);
            packet.vfunc_o10_4(m_nItemUid);
            packet.vfunc_o10_4(spItem->FUN_140526a50());
            FUN_140710590(packet);
        }
    }
    return 0;
}

// @0x140e4c440
void UIItemMergeRevertDialog::FUN_140e4c440()
{
    FUN_140d42630(GetTypeName());
    FUN_140d42540(GetTypeName(), m_nItemUid, MS2Ptr<CItem>(0));
    if (ItemScrollSlot* pSlot = FUN_140d42c30(FUN_1422c8e90(GetTypeName())))
    {
        FUN_140d42bc0(pSlot, Unk_MrRemoveFn(this, &UIItemMergeRevertDialog::FUN_140e4ce70));
        FUN_140d42b70(pSlot, Unk_MrDropFn(this, &UIItemMergeRevertDialog::FUN_140e4cea0));
    }
    ASObj obj(2);
    obj.FUN_1407cb9c0("isReady", 1);
    obj.FUN_1407cba60("binding", GetTypeName());
    obj.FUN_1407cb9c0("price", 0);
    m_30->Invoke("setData", obj);
}

// @0x140e4c7a0
void UIItemMergeRevertDialog::FUN_140e4c7a0(CItem* pItem)
{
    m_nItemUid = pItem->FUN_140526a50();
}

// @0x140e4c7d0
// MS2-FUNCTIONAL: call-result temporaries / frame-slot order differ (source form not found)
void UIItemMergeRevertDialog::FUN_140e4c7d0(CItem* pItem)
{
    FUN_140d42630(GetTypeName());
    FUN_140d42540(GetTypeName(), m_nItemUid, MS2Ptr<CItem>(pItem));
    if (ItemScrollSlot* pSlot = FUN_140d42c30(FUN_1422c8e90(GetTypeName())))
    {
        FUN_140d42bc0(pSlot, Unk_MrRemoveFn(this, &UIItemMergeRevertDialog::FUN_140e4ce70));
        FUN_140d42b70(pSlot, Unk_MrDropFn(this, &UIItemMergeRevertDialog::FUN_140e4cea0));
    }
    CStringW strOption = FUN_1409eecf0()->FUN_1405c1090(MS2Ptr<CItem>(pItem), 1);
    CStringW strText = FUN_140656190(L"{0}{1}", FUN_14028b8e0(CStringW(L"s_tooltip_itemoption_kinds_merge")), strOption);
    CItemData* pData = reinterpret_cast<CItemData*>(pItem->FUN_140527840());
    int nType = pData->FUN_14053c620();
    FUN_14083d2b0(strText);
    ASObj obj(2);
    obj.FUN_1407cb9c0("isReady", 0);
    obj.FUN_1407cba60("binding", GetTypeName());
    obj.FUN_1407cbb20("name", pItem->FUN_140528160());
    obj.FUN_1407cbb20("optionStr", CStringW(strText));
    obj.FUN_1407cbbe0("enabled", FUN_140e4d330(pItem) == 0);
    obj.FUN_1407cbb20("itemGUID", FUN_141b71910(pItem->FUN_140526a50()));
    obj.FUN_1409c1180("price", FUN_1401c0db0()->FUN_140679790(pItem->FUN_140526bd0(), nType));
    m_30->Invoke("setData", obj);
}

// @0x140e4cda0
void UIItemMergeRevertDialog::FUN_140e4cda0(CItem* pItem)
{
    FUN_1412751f0(FUN_1405c2690(CStringW(L"s_item_merge_option_revert"), pItem->FUN_140527b10()), 3, 1);
    vfunc_67();
}

// @0x140e4ce70
void UIItemMergeRevertDialog::FUN_140e4ce70(ItemScrollSlot& slot)
{
    FUN_140e4c440();
}

// @0x140e4cea0
// MS2-FUNCTIONAL: exe nests the item test differently (frame and block order differ)
void UIItemMergeRevertDialog::FUN_140e4cea0(ItemScrollSlot& slot, DragSlot* pDrag)
{
    Unk_MrInvenSlot* pInven;
    if (!(m_30 == 0) && (pInven = FUN_140a50b50(pDrag)) != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(pInven->FUN_141405a10());
        if (!spItem.IsNull())
        {
            int nError = FUN_140e4d330(spItem.get());
            if (nError == 0)
                FUN_140e4c7d0(spItem.get());
            else
                FUN_140e4d010(nError);
        }
        else
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_item_merge_option_error_invalid_mergeitem")), 1, 1);
        }
    }
}

// @0x140e4d010
// MS2-FUNCTIONAL: message CStringW temporaries: the exe keeps extra pointer copies per case
void UIItemMergeRevertDialog::FUN_140e4d010(int nError)
{
    switch (nError)
    {
    case 3:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_item_merge_option_error_invalid_mergeitem")), 1, 1);
        break;
    case 4:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_item_merge_option_error_invalid_material")), 1, 1);
        break;
    case 5:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_item_merge_option_error_invalid_merge_scroll")), 1, 1);
        break;
    case 6:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_item_merge_option_error_invalid_revert_rank")), 1, 1);
        break;
    case 7:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_item_merge_option_error_invalid_revert_option")), 1, 1);
        break;
    case 8:
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_item_merge_option_error_invalid_revert_slot")), 1, 1);
        break;
    }
}

// @0x140e4d330
// MS2-FUNCTIONAL: exe is nested if/else with return-value temporaries per branch; mine is linear
int UIItemMergeRevertDialog::FUN_140e4d330(CItem* pItem)
{
    if (pItem == 0)
        return 3;
    if (pItem->FUN_140527840() == 0)
        return 3;
    if (reinterpret_cast<CItemData*>(pItem->FUN_140527840())->fusion.fusionable == 0)
        return 3;
    MS2Ptr<CItem> spBase = DAT_143ab2a90.FUN_140a5d680(m_nItemUid);
    if (spBase.IsNull())
        return 5;
    int nBaseId = spBase->FUN_140526bd0();
    if (nBaseId != pItem->FUN_140526bd0())
        return 6;
    if (!FUN_140630810(pItem->FUN_1405278a0()))
        return 7;
    CItemData* pBaseData = reinterpret_cast<CItemData*>(spBase->FUN_140527840());
    if (pBaseData == 0)
        return 5;
    int nBaseOption = pBaseData->function.parameter.FUN_1408d1f60(0, 0);
    if (nBaseOption == 0)
        return 5;
    if (nBaseOption == reinterpret_cast<CItemData*>(pItem->FUN_140527840())->FUN_14053e410())
        return 0;
    return 8;
}

// @0x140e4d9b0
template<> Unk_MrRemoveFn::DelegateImplBase::DelegateImplBase() {}

// @0x140e4d9d0
template<> Unk_MrDropFn::DelegateImplBase::DelegateImplBase() {}

// @0x140e4da30
template<> Unk_MrRemoveFn::DelegateImplBase::~DelegateImplBase() {}

// @0x140e4da50
template<> Unk_MrDropFn::DelegateImplBase::~DelegateImplBase() {}

MS2_EMIT_CRT_MEMMOVE_S();
