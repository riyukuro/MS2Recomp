// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The gemstone swap page of the item socket dialog
// ("GemStoneSwapPage_*" bags; packet 0x88 operations 8 / 0xa), its socket record CGemStoneItem and the COMDAT glue of
// its callbacks.
// MS2-UNIT: unit_140c47c80
// MS2-RANGE: 0x140c47c80-0x140c4ffa0 .text$mn
// MS2-RANGE: 0x1400cd660-0x1400cd7d0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400cd720 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400cd750 ; probe
// MS2-PIN: ??$?8PEAVItemSocketSystemPageGemstoneSwap@@P80@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@0@0@Z 0x140c4b800 ; prop
// MS2-PIN: ??$?8PEAVItemSocketSystemPageGemstoneSwap@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140c4b850 ; prop
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_GsCostTag@@H@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_GsCostTag@@H@std@@@std@@@std@@@0@AEAV10@@Z 0x140c4d7c0 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@QEAA@AEBV01@@Z 0x140c4d920 ; unique
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@W4Unk_GsCostTag@@HU?$less@W4Unk_GsCostTag@@@std@@V?$allocator@U?$pair@$$CBW4Unk_GsCostTag@@H@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBW4Unk_GsCostTag@@H@std@@PEAX@2@@Z 0x140c4f1b0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c4f8e0 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c4f940 ; unique
// MS2-PIN: ?deallocate@?$_Default_allocator_traits@V?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_GsCostTag@@H@std@@PEAX@std@@@std@@@std@@SAXAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_GsCostTag@@H@std@@PEAX@std@@@2@QEAU?$_Tree_node@U?$pair@$$CBW4Unk_GsCostTag@@H@std@@PEAX@2@_K@Z 0x140c4f9a0 ; unique
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBW4Unk_GsCostTag@@H@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBW4Unk_GsCostTag@@H@std@@PEAX@2@_K@Z 0x140c4f9d0 ; prop
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z 0x140c4fc00 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140c4fc40 ; unique
// MS2-PIN: ??$Call@VItemSocketSystemPageGemstoneSwap@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@CAXAEAU?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@AEAVItemInfoSlot@@AEAVASSlot@@@Z 0x140c4fc80 ; unique
// MS2-PIN: ??$Call@VItemSocketSystemPageGemstoneSwap@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140c4fcc0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAAXAEAVItemInfoSlot@@AEAVASSlot@@@Z@std@@@?$Delegate@$$A6AXAEAVItemInfoSlot@@AEAVASSlot@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c4fcf0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageGemstoneSwap@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c4fd50 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemsocketsystempagegemstoneswap.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/itemsocketsystempagegemstoneswap.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cgemstoneitem.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/asmultiselecttilecachelist.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/equipment.h"
#include <map>

// The header statics of the original TU (the same set as the other pages of the family).
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);

class Unk_ItemEquipData : public CItemData {};   // CItem::FUN_140527840's record (as commonfiles\item.cpp)
class Unk_GsWorld;
class Unk_GsPlayer;
class Unk_GsInventory;
class PC   // C3: member view for the former free stand-ins
{
public:
    struct Unk_PCEquipSet* GetEquipment();
};
// The player's inventory (global 0x143ab2a90).
class Unk_Inventory
{
public:
    int GetItemCountByTag(int nTag, int nRarity);
    MS2Ptr<CItem> FindItemByUid(__int64 uid);
    void GetItemsInCategory(int tab, CAtlArray<MS2Ptr<CItem>>& out);
};
extern Unk_Inventory g_143ab2a90;   // C3: the real global (0x143ab2a90)
extern __int64 DAT_143ab2898;                   // the meso the ingredient fee may cost

MS2Ptr<CItem> FUN_141425750(__int64 uid, bool* pbEquipped);
bool FUN_1414258e0(__int64 uid);
void FUN_140cfd800(const CString& name);
void CreateGemStoneSlot(const CString& name, MS2Ptr<CGemStoneItem> gem, int index, int iconType, int flags);
void DestroyItemSlotBag(const CString& name);
int FUN_140222ce0(MS2Ptr<CItemData>);
unsigned short FUN_140626f20(unsigned gemId);
void FUN_1406284f0(unsigned short gemInfo, int recipe, int* tag, int* amount);
struct Unk_GsIngTable;
int FUN_14053feb0(int itemId);
template <class A, class B> CStringW FUN_14028dfa0(CStringW key, const A& a1, const B& a2);
template <class A> CStringW FUN_14028dfa0(CStringW key, const A& a1);
CStringW GetStringCommonByKey(const CStringW& key);
CStringW FUN_1409404f0(__int64 meso);
MS2Ptr<CMsgBoxData> ShowYesNoMessageBox(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW text);
MS2Ptr<CMsgBoxData> ShowMessageBoxWithCallback(CStringW text, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
void FUN_140710590(COutPacket&);
void FUN_1422bcce0(Scaleform::GFx::Value* pv, bool b);
void SetValue(Scaleform::GFx::Value* pv, Scaleform::GFx::Value v);

// The socket-system packets (layouts as commonfiles\itemsocketsystemutil.cpp; the first two have their inline
// constructors here).
struct Unk_SSGGemEquip {
    Unk_SSGGemEquip() : m_nItemUid(0), m_nSlot(0), m_spGem(0) {}   // 0x140c4de50
    ~Unk_SSGGemEquip() {}                                           // 0x140c4e0b0
    __int64 m_nItemUid;
    int m_nSlot;
    MS2Ptr<TSocketGemStoneInfo> m_spGem;
};
struct Unk_SSGGemUnequip {
    Unk_SSGGemUnequip() : m_nItemUid(0), m_nGemUid(0), m_nSlot(0) {}    // 0x140c4de20
    __int64 m_nItemUid;
    __int64 m_nGemUid;
    int m_nSlot;
};
struct Unk_SockUidCountSlot {
    Unk_SockUidCountSlot() : m_nUid(0), m_nCount(0), m_nSlot(0) {}      // 0x14062c130
    __int64 m_nUid;
    __int64 m_nCount;
    int m_nSlot;
};
void FUN_140628a00(Unk_SSGGemEquip&, CInPacket&);
void FUN_140628be0(Unk_SSGGemUnequip&, CInPacket&);
void FUN_140628b70(Unk_SSGGemUnequip&, COutputStream&);
void FUN_140628840(Unk_SockUidCountSlot&, COutputStream&);

// The swap price table: ingredient tag -> amount. A std::map of its own (the less<> COMDAT 0x140c4e5a0 is not
// std::less<int>), so the key is an int-sized enum.
enum Unk_GsCostTag { Unk_GsCostTag_Meso = 0x60 };
typedef std::map<Unk_GsCostTag, int> Unk_GsCosts;

// The AS helpers of the page instantiated in this unit.
class Unk_GsClip : public AScript {
public:
    MS2Ptr<Unk_SocketPageBag> GetItemBag(const CString& strName);                        // "m_itemBag" child
    // C3: FUN_140c4bd20 is AScript::Invoke(const char*, bool, Value) (ascript.h)
};

// The slot callback delegate's out-of-line members (delegate.h declares them only).
template <> inline Delegate<void(ItemInfoSlot&, ASSlot&)>::DelegateImplBase::DelegateImplBase() {}     // 0x140c4de00
template <> inline Delegate<void(ItemInfoSlot&, ASSlot&)>::DelegateImplBase::~DelegateImplBase() {}    // 0x140c4e090

template <> inline Delegate<void(ItemInfoSlot&, ASSlot&)>::~Delegate()                                 // 0x140c4de90
{
    if (m_pImpl != 0)
        delete m_pImpl;
}

template <> inline Delegate<void(ItemInfoSlot&, ASSlot&)>& Delegate<void(ItemInfoSlot&, ASSlot&)>::operator=(const Delegate& o)   // 0x140c4e0d0
{
    if (this == &o)
        return *this;
    if (m_pImpl != 0)
        delete m_pImpl;
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
    return *this;
}

// CGemStoneItem's inline members (COMDATs of this unit).
inline CGemStoneItem::CGemStoneItem() : m_equipment(0), m_gemstone(0), m_locked(false) {}   // 0x140c4dd90
inline CGemStoneItem::~CGemStoneItem()                                                       // 0x140c4e010
{
    m_equipment = 0;
    m_gemstone = 0;
}
inline void CGemStoneItem::FUN_140c4e720(MS2Ptr<CItem> equipment, MS2Ptr<CItem> gemstone, bool locked)   // 0x140c4e720
{
    m_equipment = equipment;
    m_gemstone = gemstone;
    m_locked = locked;
}

// @0x140c4b8a0
inline MS2Ptr<Unk_SocketPageBag> CreateItemBag(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<Unk_SocketPageBag> sp(reinterpret_cast<Unk_SocketPageBag*>(new ASItemBag(v, nMovieId)));
    return sp;
}

// @0x140c4bc60
inline MS2Ptr<Unk_SocketPageBag> Unk_GsClip::GetItemBag(const CString& strName)
{
    Scaleform::GFx::Value v = GetMember(strName);
    if (((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value const&>(v))->IsObject())
        return CreateItemBag(m_nMovieId, v);
    return MS2Ptr<Unk_SocketPageBag>(0);
}

// @0x140c4bd20
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, bool a1, Scaleform::GFx::Value a2)
{
    ASArgList args;
    args.resize(2);
    FUN_1422bcce0(&args[0], a1);
    SetValue(&args[1], a2);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140c47c80
ItemSocketSystemPageGemstoneSwap::ItemSocketSystemPageGemstoneSwap()
    : m_binder(CString("GemStoneSwapPage_slots0")), m_sourceUid(0), m_targetUid(0), m_refresh(0)
{
    m_slots0Name = "GemStoneSwapPage_slots0";
    m_slots1Name = "GemStoneSwapPage_slots1";
}

// @0x140c47dd0
ItemSocketSystemPageGemstoneSwap::~ItemSocketSystemPageGemstoneSwap()
{
}

// @0x140c47e80
void ItemSocketSystemPageGemstoneSwap::vfunc_1()
{
    ItemSocketSystemPageBase::vfunc_1();
    FUN_140c49110();
}

// @0x140c47eb0
// Each slot clip is declared in an if condition.
void ItemSocketSystemPageGemstoneSwap::vfunc_7(MS2Ptr<AScript> root)
{
    ItemSocketSystemPageBase::vfunc_7(root);
    if (root == 0)
        return;
    if (m_root == 0)
        m_root = root->FUN_1409b4560("m_gemStoneSwapPage");
    if (m_root == 0)
        return;
    if (MS2Ptr<ASMovieClip> slots = m_root->FUN_1409b4560("m_slots0"))
    {
        m_sourceControl =
            reinterpret_cast<Unk_GsClip*>(slots.operator->())->GetItemBag("m_itemBag");
    }
    if (MS2Ptr<ASMovieClip> slots = m_root->FUN_1409b4560("m_slots1"))
    {
        m_targetControl =
            reinterpret_cast<Unk_GsClip*>(slots.operator->())->GetItemBag("m_itemBag");
    }
    RefreshSourceItems();
    ASObj data(2);
    data.SetStringMember("bagId0", m_slots0Name);
    data.SetStringMember("bagId1", m_slots1Name);
    m_root->Invoke("initData", data.GetValue());
}

// @0x140c48380
void ItemSocketSystemPageGemstoneSwap::vfunc_2()
{
    ItemSocketSystemPageBase::vfunc_2();
    FUN_140c49110();
}

// @0x140c483b0
void ItemSocketSystemPageGemstoneSwap::vfunc_5(CInPacket* packet)
{
    ItemSocketSystemPageBase::vfunc_5(packet);
    int operation = packet->ReadUInt8();
    if (operation == 9)
        FUN_140c48c70(packet);
    else if (operation == 11)
        SendItemSocketSystemMode8(packet);
}

// @0x140c48430
int ItemSocketSystemPageGemstoneSwap::vfunc_3(const char* event, const Scaleform::GFx::Value* args, int count)
{
    if (ItemSocketSystemPageBase::vfunc_3(event, args, count) != 0)
        return 1;
    if (_stricmp("onIndexChangeSlot0", event) == 0) {
        ASData data;
        if (data.SetArgsIfAny(args, count) != 0) {
            int nIndex = data.PopInt();
            SelectSourceItem(nIndex);
        }
        return 1;
    } else if (_stricmp("onIndexChangeSlot1", event) == 0) {
        ASData data;
        if (data.SetArgsIfAny(args, count) != 0) {
            int nIndex = data.PopInt();
            SelectTargetItem(nIndex);
        }
        return 1;
    } else if (_stricmp("onGemstoneSwap", event) == 0) {
        MS2Ptr<CItem> source = FUN_141425750(m_sourceUid, 0);
        if (source.get() != 0) {
            CStringW text;
            if (GetSwapPriceText(source, text))
                ShowYesNoMessageBox(Delegate<bool(int, const CMsgBoxData&)>(this, &ItemSocketSystemPageGemstoneSwap::FUN_140c48df0), CStringW(text));
            else
                ShowMessageBoxWithCallback(FUN_14028dfa0<CStringW>(CStringW(L"s_itemsocketsystem_error_swap_lack_price"), text), 0, Delegate<bool(int, const CMsgBoxData&)>());
        }
        return 1;
    } else if (_stricmp("onRetry", event) == 0) {
        OnRetry();
        return 1;
    }
    return 1;
}

// @0x140c48820
void ItemSocketSystemPageGemstoneSwap::vfunc_6()
{
    if (m_refresh != 0) {
        m_refresh = 0;
        m_binder.FUN_140d43990();
        MS2Ptr<CItem> source = FUN_141425750(m_sourceUid, 0);
        MS2Ptr<CItem> target = FUN_141425750(m_targetUid, 0);
        ASObj data(2);
        {
            ASObj obj(2);
            obj.SetStringMember("binding", m_binder.BindItem(source.get()));
            obj.SetWStringMember("itemName", static_cast<CItem*>(source)->FUN_140527b10());
            ASArray gems(2);
            FUN_140c49990(source, "GemStoneSwapPage_source_gemstone", &gems);
            obj.FUN_1409eb1d0("gemstones", gems);
            data.FUN_1409eb270("source", obj);
        }
        {
            ASObj obj(2);
            obj.SetStringMember("binding", m_binder.BindItem(target.get()));
            obj.SetWStringMember("itemName", static_cast<CItem*>(target)->FUN_140527b10());
            ASArray gems(2);
            FUN_140c49990(target, "GemStoneSwapPage_dest_gemstone", &gems);
            obj.FUN_1409eb1d0("gemstones", gems);
            data.FUN_1409eb270("dest", obj);
        }
        reinterpret_cast<AScript*>(reinterpret_cast<Unk_GsClip*>(m_root.operator->()))->Invoke("update", data);
    }
}

// @0x140c48c70
void ItemSocketSystemPageGemstoneSwap::FUN_140c48c70(CInPacket* packet)
{
    Unk_SSGGemEquip result;
    FUN_140628a00(result, *packet);
    if (result.m_nItemUid == m_targetUid)
        m_refresh = 1;
}

// @0x140c48ce0
void ItemSocketSystemPageGemstoneSwap::SendItemSocketSystemMode8(CInPacket* packet)
{
    Unk_SSGGemUnequip result;
    FUN_140628be0(result, *packet);
    if (result.m_nItemUid == m_sourceUid) {
        MS2Ptr<CItem> gem = g_143ab2a90.FindItemByUid(result.m_nGemUid);
        if (gem.get() != 0) {
            Unk_SockUidCountSlot request;
            request.m_nCount = result.m_nGemUid;
            request.m_nUid = m_targetUid;
            request.m_nSlot = result.m_nSlot;
            COutPacket out(static_cast<int>(SendOp::ItemSocketSystem), 0);
            out.Encode1(8);
            FUN_140628840(request, out);
            FUN_140710590(out);
        }
    }
}

// @0x140c48df0
bool ItemSocketSystemPageGemstoneSwap::FUN_140c48df0(int result, const CMsgBoxData&)
{
    if (result != 0)
        return true;
    MS2Ptr<CItem> source = FUN_141425750(m_sourceUid, 0);
    MS2Ptr<CItem> target = FUN_141425750(m_targetUid, 0);
    if (!FUN_140c4a760(MS2Ptr<CItem>(source), MS2Ptr<CItem>(target)))
        return true;
    CItemSocket* socket = static_cast<CItem*>(source)->GetSocket();
    for (unsigned i = 0; i < socket->GetOpenSlotCount(); ++i) {
        if (socket->IsSlotEmpty(i) == true)
            continue;
        Unk_SSGGemUnequip request;
        request.m_nItemUid = static_cast<CItem*>(source)->GetItemUid();
        request.m_nSlot = i;
        COutPacket out(static_cast<int>(SendOp::ItemSocketSystem), 0);
        out.Encode1(0xa);
        FUN_140628b70(request, out);
        FUN_140710590(out);
    }
    return true;
}

// @0x140c49000
void ItemSocketSystemPageGemstoneSwap::FUN_140c49000(ItemInfoSlot& slot, ASSlot& asSlot)
{
    int seal = 0;
    {
        MS2Ptr<CItem> item = slot.vfunc_25();
        if (item.get() != 0) {
            seal = static_cast<CItem*>(item)->GetSocket() ? (static_cast<CItem*>(item)->GetSocket()->GetOpenSlotCount() == 0 ? 1 : 0) : 0;
            if (!FUN_1414258e0(static_cast<CItem*>(item)->GetItemUid()))
                asSlot.SetItemEquip(1);
        }
    }
    asSlot.SetItemSeal(seal);
}

// @0x140c49110
void ItemSocketSystemPageGemstoneSwap::FUN_140c49110()
{
    DestroyItemSlotBag(m_slots0Name);
    DestroyItemSlotBag(m_slots1Name);
    m_binder.FUN_140d43990();
    m_sourceControl = 0;
    m_targetControl = 0;
    m_sourceUid = 0;
    m_targetUid = 0;
    for (unsigned __int64 i = 0; i < 4; ++i) {
        FUN_140cfd800(Unk_SocketFormat("GemStoneSwapPage_source_gemstone{0}", i));
        FUN_140cfd800(Unk_SocketFormat("GemStoneSwapPage_dest_gemstone{0}", i));
    }
}

// @0x140c49250
void ItemSocketSystemPageGemstoneSwap::SelectSourceItem(int index)
{
    if (index < 0 || index >= (int)m_sourceItems.GetCount())
        return;
    MS2Ptr<CItem> item(m_sourceItems[index]);
    if (item == 0)
        return;
    m_sourceUid = static_cast<CItem*>(item)->GetItemUid();
    m_targetUid = 0;
    m_binder.FUN_140d43990();
    FUN_140c4a2b0(MS2Ptr<CItem>(item));
    ASObj data(2);
    data.SetStringMember("binding", m_binder.BindItem(item.get()));
    data.SetWStringMember("itemName", static_cast<CItem*>(item)->FUN_140527b10());
    ASArray gems(2);
    FUN_140c49990(item, "GemStoneSwapPage_source_gemstone", &gems);
    data.FUN_1409eb1d0("gemstones", gems);
    reinterpret_cast<Unk_GsClip*>(m_root.operator->())->Invoke("select", true, data.GetValue());
}

// @0x140c49580
void ItemSocketSystemPageGemstoneSwap::SelectTargetItem(int index)
{
    if (index < 0 || index >= (int)m_targetItems.GetCount())
        return;
    MS2Ptr<CItem> item(m_targetItems[index]);
    if (item == 0)
        return;
    m_targetUid = static_cast<CItem*>(item)->GetItemUid();
    ASObj data(2);
    data.SetStringMember("binding", m_binder.BindItem(item.get()));
    data.SetWStringMember("itemName", static_cast<CItem*>(item)->FUN_140527b10());
    ASArray gems(2);
    FUN_140c49990(item, "GemStoneSwapPage_dest_gemstone", &gems);
    data.FUN_1409eb1d0("gemstones", gems);
    reinterpret_cast<Unk_GsClip*>(m_root.operator->())->Invoke("select", false, data.GetValue());
}

// @0x140c49850
void ItemSocketSystemPageGemstoneSwap::OnRetry()
{
    RefreshSourceItems();
    m_binder.FUN_140d43990();
    m_sourceUid = 0;
    m_targetUid = 0;
    for (unsigned __int64 i = 0; i < 4; ++i) {
        FUN_140cfd800(Unk_SocketFormat("GemStoneSwapPage_source_gemstone{0}", i));
        FUN_140cfd800(Unk_SocketFormat("GemStoneSwapPage_dest_gemstone{0}", i));
    }
    m_root->Invoke("retry");
}

// @0x140c49990
void ItemSocketSystemPageGemstoneSwap::FUN_140c49990(MS2Ptr<CItem> item, CString strPrefix, ASArray* pGems)
{
    CItemSocket* socket = static_cast<CItem*>(item)->GetSocket();
    if (socket == 0)
        return;
    for (unsigned __int64 k = 0; k < 4; ++k)
        FUN_140cfd800(Unk_SocketFormat("{0}{1}", strPrefix, k));
    unsigned open = socket->GetOpenSlotCount();
    for (unsigned i = 0; i < open; ++i) {
        MS2Ptr<CGemStoneItem> gem(new CGemStoneItem);
        if (gem == 0)
            continue;
        MS2Ptr<CItem> gemItem(0);
        MS2Ptr<TSocketGemStoneInfo> info = socket->GetGemInfo(i);
        if ((info.get() != 0 ? true : false) && !info->IsEmpty())
            gemItem = CreateGemStoneItem(MS2Ptr<TSocketGemStoneInfo>(info), 0, false);
        gem->FUN_140c4e720(MS2Ptr<CItem>(item), MS2Ptr<CItem>(gemItem), false);
        CString strName = Unk_SocketFormat("{0}{1}", strPrefix, i);
        CreateGemStoneSlot(strName, MS2Ptr<CGemStoneItem>(gem), i, 0x415, 0x20);
        pGems->PushString(strName);
    }
    unsigned locked = socket->GetLockedSlotCount();
    for (unsigned j = 0; j < locked; ++j) {
        MS2Ptr<CGemStoneItem> gem(new CGemStoneItem);
        if (gem == 0)
            continue;
        gem->FUN_140c4e720(MS2Ptr<CItem>(item), MS2Ptr<CItem>(0), true);
        unsigned index = j + open;
        CString strName = Unk_SocketFormat("{0}{1}", strPrefix, index);
        CreateGemStoneSlot(strName, MS2Ptr<CGemStoneItem>(gem), j, 0x415, 0x20);
        pGems->PushString(strName);
    }
}

// @0x140c49fc0
void ItemSocketSystemPageGemstoneSwap::RefreshSourceItems()
{
    m_sourceItems.RemoveAll();
    m_targetItems.RemoveAll();
    CAtlArray<MS2Ptr<CItem>> items;
    FUN_140c4a9a0(items);
    for (size_t i = 0; i < items.GetCount(); ++i) {
        MS2Ptr<CItem> item(items.GetAt(i));
        if (!CanBeSource(MS2Ptr<CItem>(item)))
            continue;
        m_sourceItems.Add(item);
    }
    MS2Ptr<ItemSlotBag::CreateParam> param(new ItemSlotBag::CreateParam);
    param->m_nIconType = 0x415;
    param->m_nFlags = 0x20;
    // The exe's slot callback is a Delegate<void(ItemInfoSlot&, ASSlot&)> handle at +0x28 (iteminfoslot.h types it
    // as a pointer to the pointer-signature delegate).
    reinterpret_cast<Delegate<void(ItemInfoSlot&, ASSlot&)>&>(param->m_pfnSlot) =
        Delegate<void(ItemInfoSlot&, ASSlot&)>(this, &ItemSocketSystemPageGemstoneSwap::FUN_140c49000);
    FUN_140f6d4c0(m_slots0Name, m_sourceItems, param);
    FUN_140f6d4c0(m_slots1Name, m_targetItems, param);
}

// @0x140c4a2b0
void ItemSocketSystemPageGemstoneSwap::FUN_140c4a2b0(MS2Ptr<CItem> source)
{
    CItemSocket* socket = static_cast<CItem*>(source)->GetSocket();
    if (socket == 0)
        return;
    m_targetItems.RemoveAll();
    CAtlArray<MS2Ptr<CItem>> items;
    FUN_140c4a9a0(items);
    for (size_t i = 0; i < items.GetCount(); ++i) {
        MS2Ptr<CItem> item(items[i]);
        CItemSocket* itemSocket = static_cast<CItem*>(item)->GetSocket();
        if (itemSocket == 0)
            continue;
        if (source == item.get())
            continue;
        if (!FUN_140c4a760(MS2Ptr<CItem>(source), MS2Ptr<CItem>(item)))
            continue;
        m_targetItems.Add(item);
    }
    MS2Ptr<ItemSlotBag::CreateParam> param(new ItemSlotBag::CreateParam);
    param->m_nIconType = 0x415;
    param->m_nFlags = 0x20;
    reinterpret_cast<Delegate<void(ItemInfoSlot&, ASSlot&)>&>(param->m_pfnSlot) =
        Delegate<void(ItemInfoSlot&, ASSlot&)>(this, &ItemSocketSystemPageGemstoneSwap::FUN_140c49000);
    FUN_140f6d4c0(m_slots1Name, m_targetItems, param);
}

// @0x140c4a620
bool ItemSocketSystemPageGemstoneSwap::CanBeSource(MS2Ptr<CItem> item)
{
    if (item == 0)
        return false;
    if (static_cast<CItem*>(item)->FUN_140529560() == 0)
        return false;
    CItemSocket* socket = static_cast<CItem*>(item)->GetSocket();
    if (socket == 0)
        return false;
    if (socket->GetMaxSlot() == 0)
        return false;
    if (socket->GetOpenSlotCount() == 0)
        return false;
    if (!socket->HasAnyGem())
        return false;
    return true;
}

// @0x140c4a760
bool ItemSocketSystemPageGemstoneSwap::FUN_140c4a760(MS2Ptr<CItem> source, MS2Ptr<CItem> target)
{
    int sourceKind = FUN_140222ce0(MS2Ptr<CItemData>(static_cast<CItem*>(source)->FUN_140527840()));
    int targetKind = FUN_140222ce0(MS2Ptr<CItemData>(static_cast<CItem*>(target)->FUN_140527840()));
    if (sourceKind != targetKind)
        return false;
    CItemSocket* sourceSocket = static_cast<CItem*>(source)->GetSocket();
    CItemSocket* targetSocket = static_cast<CItem*>(target)->GetSocket();
    if (sourceSocket == 0 || targetSocket == 0)
        return false;
    if (sourceSocket->GetMaxSlot() != targetSocket->GetMaxSlot())
        return false;
    if (sourceSocket->GetOpenSlotCount() != targetSocket->GetOpenSlotCount())
        return false;
    if (targetSocket->GetFilledSlotCount() != 0)
        return false;
    return true;
}

// @0x140c4a9a0
void ItemSocketSystemPageGemstoneSwap::FUN_140c4a9a0(CAtlArray<MS2Ptr<CItem>>& out)
{
    g_143ab2a90.GetItemsInCategory(0, out);
    g_143ab2a90.GetItemsInCategory(1, out);
    Unk_GsPlayer* player = ((class Unk_GsPlayer*)((class WorldService*)(class Unk_GsWorld*)(reinterpret_cast<Unk_GsWorld*>(WorldService::GetInstance())))->FUN_141bd0cc0());
    if (player == 0)
        return;
    CAtlList<MS2Ptr<CEquipItem>> equipped(10);
    Unk_GsInventory* inventory = ((class Unk_GsInventory*)((class PC*)(class Unk_GsPlayer*)(player))->GetEquipment());
    reinterpret_cast<CEquipment*>(inventory)->CollectShownItemsInLayer(equipped, 0);
    reinterpret_cast<CEquipment*>(inventory)->CollectShownItemsInLayer(equipped, 1);
    for (POSITION pos = equipped.GetHeadPosition(); pos != 0; equipped.GetNext(pos)) {
        MS2Ptr<CEquipItem> equip(equipped.GetAt(pos));
        MS2Ptr<CItem> item = equip->GetItem();
        if (item == 0)
            continue;
        out.Add(item);
    }
}

// @0x140c4ab30
bool ItemSocketSystemPageGemstoneSwap::GetSwapPriceText(MS2Ptr<CItem> item, CStringW& text)
{
    CItemSocket* socket = static_cast<CItem*>(item)->GetSocket();
    if (socket == 0)
        return false;
    if (socket->GetMaxSlot() == 0)
        return false;
    int open = socket->GetOpenSlotCount();
    if (open == 0)
        return false;
    Unk_GsCosts costs;
    for (unsigned i = 0; i < socket->GetOpenSlotCount(); ++i) {
        if (socket->IsSlotEmpty(i) == true)
            continue;
        Unk_GsCostTag tag = (Unk_GsCostTag)0;
        int amount = 0;
        FUN_1406284f0(FUN_140626f20(socket->GetGemId(i)), static_cast<CItem*>(item)->FUN_140527840()->GetSkinType(),
            reinterpret_cast<int*>(&tag), &amount);
        if (amount > 0)
            costs[tag] += amount;
    }
    Unk_GsCosts::iterator it = costs.begin();
    Unk_GsCosts::iterator last = costs.end();
    CStringW list;
    __int64 fee = 0;
    for (; it != last; ++it) {
        int itemId = reinterpret_cast<CItemDataTable*>(reinterpret_cast<Unk_GsIngTable*>(TSingleton<CItemDataTable>::GetInstance()))->GetTagItemId((ItemTagKey)it->first);
        int grade = FUN_14053feb0(itemId);
        int have = g_143ab2a90.GetItemCountByTag(it->first, grade);
        if (have < it->second) {
            if (it->first != Unk_GsCostTag_Meso) {
                int lack = it->second - have;
                text = FUN_14028dfa0<CStringW, int>(CStringW(L"s_itemsocketsystem_socket_swap_price"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, itemId), lack);
                return false;
            }
            int lack = it->second - have;
            fee += (unsigned)(lack * 1000);
            if (DAT_143ab2898 < fee) {
                int lackFee = it->second - have;
                text = FUN_14028dfa0<CStringW, int>(CStringW(L"s_itemsocketsystem_socket_swap_price"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, itemId), lackFee);
                return false;
            }
        }
        if (!list.IsEmpty())
            list += L",";
        list = FUN_14028dfa0<CStringW, int>(CStringW(L"s_itemsocketsystem_socket_swap_price"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, itemId), it->second);
    }
    if (costs.size() > 0) {
        text = FUN_14028dfa0<CStringW>(CStringW(L"s_itemsocketsystem_socket_swap_confirm"), list);
        if (fee != 0)
            text.Append(L"\n" + FUN_14028dfa0<CStringW>(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(fee)));
    } else {
        CStringW key(L"s_itemsocketsystem_socket_swap_confirm_free");
        text = GetStringCommonByKey(key);
    }
    return true;
}
// MS2-RANGE: 0x142ca2db0-0x142ca2e40 .text$yd
