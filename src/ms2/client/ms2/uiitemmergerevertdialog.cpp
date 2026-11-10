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
#include "ms2/client/ms2/inventory.h"
#include "ms2/placeholder/citemmergeoptiontable.h"
#include "ms2/commonfiles/luautil.h"
#include "ms2/client/ms2/invenslot.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/ms2format.h"   // C3: StringFormat<CStringW, CStringW> (was FUN_140656190)
#include "ms2/gfxui/notifyhandler.h"   // C3: Unk_NotifyContext::FUN_1422c8e90/f10/f70

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
extern Unk_Inventory g_143ab2a90;

// The inventory slot (invenslot.cpp) a slot can be dropped on: id 0x6200023.
class Unk_MrInvenSlot : public InvenSlot
{
};
namespace NotifyContext { class BindData; }
class MS2DragSlot;
MS2DragSlot* AsDragSlot(NotifyContext::BindData* p);   // C3: the real def (displayslot.cpp), TypeCast(0x6200023)

// The item price table (global of the lua state, GetLuaClient).
class Unk_BmPriceMgr* GetLuaClient();   // C3: was GetLuaClient

// The item option text builder (TSingleton<CItemMergeOptionTable>::GetInstance).

// The slot registry (see unit_1400d2c20.cpp / itemexchangeslot.cpp).
void FUN_140d42540(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem);
void FUN_140d42630(const CString& strName);
ItemScrollSlot* FUN_140d42c30(NotifyContext::BindData* p);

void FUN_140710590(COutPacket&);                                    // send
unsigned __int64 ParseUInt64W(const CStringW& str);                         // the uid in the text
class CItemStatus   // C3: member view for the former free stand-ins
{
public:
    bool HasGroup4Options();
};
CStringW GetStringCommonByKey(const CStringW& strKey);                     // string table text
void StripTags(CStringW& str);
CStringW FUN_141b71910(__int64 nUid);                               // the uid as text
void ShowSystemNotice(const CStringW& text, int nA, int nB);           // notice

// @0x1400d84b0 / @0x1400d8570: the two sort-name tables above (see MS2-RANGE .text$di)

// @0x140e4c050
UIItemMergeRevertDialog::UIItemMergeRevertDialog()
{
    SetTweenEnabled(1);
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
        if (data.SetArgsIfAny(pArgs, nArgs) != 0)
        {
            __int64 nUid = ParseUInt64W(data.FUN_1422b8f40());
            MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(nUid);
            if (spItem.IsNull())
                return 1;
            if (CheckItem(spItem.get()) != 0)
                return 1;
            COutPacket packet(static_cast<int>(SendOp::ItemMerge), 0);
            packet.WriteUInt8(6);
            packet.WriteInt64(m_nItemUid);
            packet.WriteInt64(spItem->GetItemUid());
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
    if (ItemScrollSlot* pSlot = FUN_140d42c30(Unk_NotifyContext::FindBinding(GetTypeName())))
    {
        pSlot->SetRemoveFn(Unk_MrRemoveFn(this, &UIItemMergeRevertDialog::OnItemRemoved));
        pSlot->SetDropFn(Unk_MrDropFn(this, &UIItemMergeRevertDialog::OnItemDropped));
    }
    ASObj obj(2);
    ((class AScript&)(obj)).SetIntMember("isReady", 1);
    obj.SetStringMember("binding", GetTypeName());
    ((class AScript&)(obj)).SetIntMember("price", 0);
    m_30->Invoke("setData", obj);
}

// @0x140e4c7a0
void UIItemMergeRevertDialog::SetItemUid(CItem* pItem)
{
    m_nItemUid = pItem->GetItemUid();
}

// @0x140e4c7d0
void UIItemMergeRevertDialog::FUN_140e4c7d0(CItem* pItem)
{
    FUN_140d42630(GetTypeName());
    FUN_140d42540(GetTypeName(), m_nItemUid, MS2Ptr<CItem>(pItem));
    if (ItemScrollSlot* pSlot = FUN_140d42c30(Unk_NotifyContext::FindBinding(GetTypeName())))
    {
        pSlot->SetRemoveFn(Unk_MrRemoveFn(this, &UIItemMergeRevertDialog::OnItemRemoved));
        pSlot->SetDropFn(Unk_MrDropFn(this, &UIItemMergeRevertDialog::OnItemDropped));
    }
    CStringW strOption = TSingleton<CItemMergeOptionTable>::GetInstance()->GetMergeOptionDescription(MS2Ptr<CItem>(pItem), 1);
    CStringW strText = StringFormat<CStringW, CStringW>(L"{0}{1}", GetStringCommonByKey(L"s_tooltip_itemoption_kinds_merge"), strOption);
    int nType = reinterpret_cast<CItemData*>(pItem->GetData())->GetEquipSubtype();
    StripTags(strText);
    ASObj obj(2);
    ((class AScript&)(obj)).SetIntMember("isReady", 0);
    obj.SetStringMember("binding", GetTypeName());
    ((class AScript&)(obj)).SetWStringMember("name", pItem->FUN_140528160());
    ((class AScript&)(obj)).SetWStringMember("optionStr", CStringW(strText));
    obj.SetBoolMember("enabled", CheckItem(pItem) == 0);
    ((class AScript&)(obj)).SetWStringMember("itemGUID", FUN_141b71910(pItem->GetItemUid()));
    obj.FUN_1409c1180("price", ((class CLua*)GetLuaClient())->CalcItemMergeRevertMeso(pItem->GetRarity(), nType));
    m_30->Invoke("setData", obj);
}

// @0x140e4cda0
void UIItemMergeRevertDialog::FUN_140e4cda0(CItem* pItem)
{
    ShowSystemNotice(FUN_14028dfa0<CStringW>(CStringW(L"s_item_merge_option_revert"), pItem->FUN_140527b10()), 3, 1);
    vfunc_67();
}

// @0x140e4ce70
void UIItemMergeRevertDialog::OnItemRemoved(ItemScrollSlot& slot)
{
    FUN_140e4c440();
}

// @0x140e4cea0
void UIItemMergeRevertDialog::OnItemDropped(ItemScrollSlot& slot, DragSlot* pDrag)
{
    if (m_30 == 0)
        return;
    Unk_MrInvenSlot* pInven = reinterpret_cast<Unk_MrInvenSlot*>(AsDragSlot(reinterpret_cast<NotifyContext::BindData*>(pDrag)));
    if (pInven != 0)
    {
        MS2Ptr<CItem> spItem = g_143ab2a90.FindItemByUid(pInven->GetItemUid());
        if (spItem.IsNull())
        {
            ShowSystemNotice(GetStringCommonByKey(L"s_item_merge_option_error_invalid_mergeitem"), 1, 1);
            return;
        }
        int nError = CheckItem(spItem.get());
        if (nError != 0)
        {
            ShowErrorMessage(nError);
            return;
        }
        FUN_140e4c7d0(spItem.get());
    }
}

// @0x140e4d010
void UIItemMergeRevertDialog::ShowErrorMessage(int nError)
{
    switch (nError)
    {
    case 5:
        ShowSystemNotice(GetStringCommonByKey(L"s_item_merge_option_error_invalid_merge_scroll"), 1, 1);
        break;
    case 6:
        ShowSystemNotice(GetStringCommonByKey(L"s_item_merge_option_error_invalid_revert_rank"), 1, 1);
        break;
    case 7:
        ShowSystemNotice(GetStringCommonByKey(L"s_item_merge_option_error_invalid_revert_option"), 1, 1);
        break;
    case 4:
        ShowSystemNotice(GetStringCommonByKey(L"s_item_merge_option_error_invalid_material"), 1, 1);
        break;
    case 8:
        ShowSystemNotice(GetStringCommonByKey(L"s_item_merge_option_error_invalid_revert_slot"), 1, 1);
        break;
    case 3:
        ShowSystemNotice(GetStringCommonByKey(L"s_item_merge_option_error_invalid_mergeitem"), 1, 1);
        break;
    }
}

// @0x140e4d330
int UIItemMergeRevertDialog::CheckItem(CItem* pItem)
{
    if (pItem == 0)
        return 3;
    if (pItem->GetData() == 0)
        return 3;
    if (reinterpret_cast<CItemData*>(pItem->GetData())->fusion.fusionable == 0)
        return 3;
    MS2Ptr<CItem> spBase = g_143ab2a90.FindItemByUid(m_nItemUid);
    if (spBase.IsNull())
        return 5;
    if (spBase->GetRarity() != pItem->GetRarity())
        return 6;
    if (!((class CItemStatus*)(void*)(pItem->GetStatus()))->HasGroup4Options())
        return 7;
    if (spBase->GetData() == 0)
        return 5;
    int nBaseOption = reinterpret_cast<CItemData*>(spBase->GetData())->function.parameter.FUN_1408d1f60(0, 0);
    if (nBaseOption == 0)
        return 5;
    if (nBaseOption != reinterpret_cast<CItemData*>(pItem->GetData())->FUN_14053e410())
        return 8;
    return 0;
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
