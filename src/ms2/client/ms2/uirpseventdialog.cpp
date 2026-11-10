// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Rock-paper-scissors event dialog.
// MS2-UNIT: client\ms2\uirpseventdialog.cpp
// MS2-RANGE: 0x1400da6a0-0x1400da6d0 .text$di
// MS2-RANGE: 0x140e82350-0x140e84cd0 .text$mn
// MS2-RANGE: 0x142ca77e0-0x142ca77f6 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIRpsEventDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@QEAA@AEBV01@@Z 0x140e84820 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIRpsEventDialog@@P81@EAAXAEAVCInPacket@@@Z@std@@@?$Delegate@$$A6AXAEAVCInPacket@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140e84a70 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uirpseventdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/gameeventuservaluemanager.h"
#include "uirpseventdialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uimessagebox.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/client/ms2/actionkeyobject.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"  // C3: ASTooltip::FUN_1409e1770
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/gamerule.h"   // C3: CGameRule::GetRps, RpsContext
#include "ms2/commonfiles/itemgift.h"   // C3: ItemEntity
#include "ms2/commonfiles/gameeventuservalue.h"   // C3: GameEventUserValue (DAT_143ab2fc0)
#include "ms2/client/ms2/uihudentity.h"   // C3: UIHudEntity::Entity::FUN_140f48d40

static const CStringW s_bannerClose(L"bannerClose");

// The size_t setter (a Set<unsigned __int64> COMDAT; asobj.h declares it).
// @0x140e846b0
void ASObj::FUN_140e846b0(const char* szName, size_t n)
{
    ASData args;
    args.AddSize(n);
    m_value.SetMember(szName, args.PopValue());
}
template<class T> bool Contains(T& values, int n) {
    if (values.GetCount() == 0) return false;
    {
        for (unsigned int i = 0; i < values.GetCount(); ++i) {
            if (values[i] == n) return true;
        }
    }
    return false;
}
void* FUN_1401c0d90();   // C3: was FUN_1401c0d90
class Unk_AttendTable { public: int GetValue(int nKind, unsigned nId, const int& nDefault); };
class Unk_LtaTable {
public:
    CStringW FUN_140c6d980(int, int, const CStringW&);
};
extern GameEventUserValue DAT_143ab2fc0;   // the event user values
void FUN_1401d9a30(CStringW&, ATL::CAtlArray<int>&, const wchar_t*);
MS2Ptr<CItemData> FUN_14053f870(int);
class Unk_PCBaseComp_ac8 : public CPtred { };
class Unk_RpsMode : public Unk_ActionKeyManager { };
class PCBase   // C3: member view for 0x14166c930
{
public:
    int GetCurStateId();                                    // 0x14166c930 current state id
};
class Unk_RpsAvatar {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59(int, int, int, int);
    virtual void vfunc_60();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual void vfunc_75();
    virtual void vfunc_76();
    virtual void vfunc_77();
    virtual void vfunc_78();
    virtual void vfunc_79();
    virtual void vfunc_80();
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_83();
    virtual void vfunc_84();
    virtual void vfunc_85();
    virtual void vfunc_86();
    virtual MS2Ptr<Unk_PCBaseComp_ac8> vfunc_87();
};
bool FUN_140b7f400(class MyPC*);
struct Unk_MiActionState* Unk_PlayerActionState(struct Unk_MiPlayer*);
class Unk_140bccd50* FUN_140bccd50();   // C3: was FUN_140bccd50
class Unk_BonusBar* FUN_140933220();   // C3: was FUN_140933220
bool FUN_140b883c0();
void FUN_141275260(int, int, int);
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW, int);
void FUN_140d73c60(MS2Ptr<CMsgBoxData>);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
CStringW BlockFormat(int);
CStringW GetStringCommonByKey(const CStringW&);
void FUN_14151f200();

// @0x140e82350
UIRpsEventDialog::UIRpsEventDialog() : m_178(false) {
    FUN_141924170(1);
    ((class PacketHandlerManager*)FUN_140bccd50())->RegisterHandler(0x10b, Delegate<void(CInPacket&)>(this, &UIRpsEventDialog::OnPacketRefresh));
}
// @0x140e82450
UIRpsEventDialog::~UIRpsEventDialog() {
    ((class PacketHandlerManager*)FUN_140bccd50())->UnregisterHandler(0x10b, Delegate<void(CInPacket&)>(this, &UIRpsEventDialog::OnPacketRefresh));
}
// @0x140e82520
CString UIRpsEventDialog::GetTypeName() { return "RpsEventDialog"; }
MS2_REPLACE_METHOD(0x140e82520, UIRpsEventDialog, GetTypeName, 61, 0x51A22B9E);
// @0x140e82570
void UIRpsEventDialog::vfunc_72() {
    UIDialog::vfunc_72();
    RefreshBannerButton();
}
MS2_REPLACE_METHOD(0x140e82570, UIRpsEventDialog, vfunc_72, 34, 0x702E0955);
// @0x140e825a0
void UIRpsEventDialog::vfunc_67() {
    UIDialog::vfunc_67();
    reinterpret_cast<GameEventUserValueManager*>(FUN_140933220())->UnregisterListener(0x708, Delegate<void(GameEventVariable*)>(this, &UIRpsEventDialog::FUN_140e84350));
    reinterpret_cast<GameEventUserValueManager*>(FUN_140933220())->UnregisterListener(0x709, Delegate<void(GameEventVariable*)>(this, &UIRpsEventDialog::FUN_140e84350));
    Unk_RpsAvatar* avatar = static_cast<Unk_RpsAvatar*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (avatar) {
        if (reinterpret_cast<PCBase*>(avatar)->GetCurStateId() == 0x3b) avatar->vfunc_59(1, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x140e825a0, UIRpsEventDialog, vfunc_67, 408, 0x3669444F);
// @0x140e82740
void UIRpsEventDialog::OnLoadComplete() {
    UIDialog::OnLoadComplete();
    reinterpret_cast<GameEventUserValueManager*>(FUN_140933220())->RegisterListener(0x708, Delegate<void(GameEventVariable*)>(this, &UIRpsEventDialog::FUN_140e84350));
    reinterpret_cast<GameEventUserValueManager*>(FUN_140933220())->RegisterListener(0x709, Delegate<void(GameEventVariable*)>(this, &UIRpsEventDialog::FUN_140e84350));
    MS2Ptr<RpsContext> event = ((class CGameRule*)FUN_1401c0d90())->GetRps();
    if (event == NULL) return;
    m_178 = false;
    FUN_140e83370(event);
}
MS2_REPLACE_METHOD(0x140e82740, UIRpsEventDialog, OnLoadComplete, 462, 0x921991B2);
// @0x140e82920
void UIRpsEventDialog::vfunc_45(Scaleform::GFx::Value* result, const CString& method, ASData* args) {
    UIObject::vfunc_45(result, method, args);
    if (method == "getTooltipItem") {
        int item = args->PopUInt();
        int rank = args->PopUInt();
        Unk_RpsAvatar* avatar = static_cast<Unk_RpsAvatar*>(WorldService::GetInstance()->FUN_141bd0cc0());
        if (avatar) {
            ASTooltip tooltip((void*)avatar, 0x20, 2);
            if (tooltip.FUN_1409e1770(item, rank)) *result = tooltip.FUN_1422bb870();
        }
    }
}
MS2_REPLACE_METHOD(0x140e82920, UIRpsEventDialog, vfunc_45, 260, 0xB4209A71);
// @0x140e82a30
int UIRpsEventDialog::vfunc_28(const char* method, const Scaleform::GFx::Value* args, unsigned int count) {
    if (UIDialog::vfunc_28(method, args, count)) return 1;
    Unk_RpsAvatar* avatar = static_cast<Unk_RpsAvatar*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!avatar) { MS2_ASSERT_AT(244, 0); return 0; }
    if (_stricmp("onOpenBanner", method) == 0) {
        if (!FUN_140b883c0()) { FUN_141275260(0xcfd, 1, 1); return 1; }
        if (!FUN_140b7f400(reinterpret_cast<MyPC*>(avatar))) { FUN_141275260(0xcff, 1, 1); return 1; }
        if (reinterpret_cast<Unk_RpsMode*>(Unk_PlayerActionState(reinterpret_cast<Unk_MiPlayer*>(avatar)))->GetCur() != 0x1e) { FUN_141275260(0xcfe, 1, 1); return 1; }
        COutPacket packet(static_cast<int>(SendOp::Microgame), 0);
        packet.Encode2(0);
        FUN_140710590(packet);
        return 1;
    }
    if (_stricmp("onCloseBanner", method) == 0) {
        MS2Ptr<Unk_PCBaseComp_ac8> banner = avatar->vfunc_87();
        if (banner == NULL) { MS2_ASSERT_AT(280, 0); return 0; }
        if (!reinterpret_cast<UIHudEntity::Entity*>(banner.operator->())->FUN_140f48d40()) return 0;
        {
        CStringW text = BlockFormat(0xd0c);
        MS2Ptr<CMsgBoxData> box = FUN_140d73f20(text, 1);
        box->SetExtra(s_bannerClose);
        box->FUN_141a024a0(0);
        FUN_140d73c60(box);
        }
        return 1;
    }
    if (_stricmp("onReward", method) == 0) {
        ASData data;
        if (!data.SetArgsIfAny(args, count)) { MS2_ASSERT_AT(304, 0); return 0; }
        int index = data.PopUInt();
        FUN_140e83fa0(index);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E82A30, UIRpsEventDialog, vfunc_28, 1021, 0x1C4478B1);
// @0x140e82e40
int UIRpsEventDialog::vfunc_71() {
    Unk_RpsAvatar* avatar = static_cast<Unk_RpsAvatar*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!avatar) { MS2_ASSERT_AT(321, 0); return 0; }
    MS2Ptr<Unk_PCBaseComp_ac8> banner = avatar->vfunc_87();
    if (banner == NULL) { MS2_ASSERT_AT(328, 0); return 0; }
    if (reinterpret_cast<UIHudEntity::Entity*>(banner.operator->())->FUN_140f48d40() == 1) {
        FUN_140d73aa0(GetStringCommonByKey(L"s_rpsevent_ask_close"), 1, static_cast<IMessageListener*>(this), L"askClose");
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140e82e40, UIRpsEventDialog, vfunc_71, 451, 0x5752C4F7);
// @0x140e83010
int UIRpsEventDialog::OnMessage(UISwfEntity* sender, UIMsg* msg) {
    if (UIDialog::OnMessage(sender, msg)) return 1;
    if (msg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(sender)) {
        int result = msg->PopInt();
        CStringW tag = msg->FUN_1422b8f40();
        FUN_14151f200();
        if (tag.CompareNoCase(L"askClose") == 0 && result == 0) vfunc_67();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD_VIA(0x140e83010, UIRpsEventDialog, IMessageListener, OnMessage, 255, 0xD04003C7);
// @0x140e83120
CString UIRpsEventDialog::FUN_140e83120(int itemId) {
    if (!itemId) return "";
    MS2Ptr<CItemData> item = FUN_14053f870(itemId);
    if (item.IsNull()) return "";
    return item->GetIconPath();
}
MS2_REPLACE_METHOD(0x140e83120, UIRpsEventDialog, FUN_140e83120, 211, 0x281900C9);
// @0x140e83200
void UIRpsEventDialog::FUN_140e83200(ATL::CAtlArray<int>& received) {
    MS2Ptr<RpsContext> event = ((class CGameRule*)FUN_1401c0d90())->GetRps();
    if (event == NULL) return;
    CStringW values = reinterpret_cast<Unk_LtaTable&>(DAT_143ab2fc0).FUN_140c6d980(0x709, event->m_48, L"");
    FUN_1401d9a30(values, received, L",");
}
MS2_REPLACE_METHOD(0x140e83200, UIRpsEventDialog, FUN_140e83200, 201, 0xDA46B974);
// @0x140e832d0
int UIRpsEventDialog::FUN_140e832d0() {
    MS2Ptr<RpsContext> event = ((class CGameRule*)FUN_1401c0d90())->GetRps();
    if (event == NULL) return 0;
    return reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0).GetValue(0x708, event->m_48, 0);
}
MS2_REPLACE_METHOD(0x140e832d0, UIRpsEventDialog, FUN_140e832d0, 147, 0x667F9F28);
// @0x140e83370
void UIRpsEventDialog::FUN_140e83370(MS2Ptr<RpsContext> event) {
    Unk_RpsAvatar* avatar = static_cast<Unk_RpsAvatar*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!avatar) { MS2_ASSERT_AT(167, 0); return; }
    if (m_30 == NULL) { MS2_ASSERT_AT(173, 0); return; }
    if (event == NULL) { MS2_ASSERT_AT(179, 0); return; }
    ATL::CAtlArray<int> received;
    FUN_140e83200(received);
    ASObj info(2);
    ASArray rewards(2);
    for (size_t i = 0; i < event->m_rewards.GetCount(); ++i) {
        MS2Ptr<RpsContext::RewardData> reward = event->m_rewards[i];
        if (reward == NULL) { MS2_ASSERT_AT(193, 0); continue; }
        ASObj row(2);
        row.FUN_140e846b0("index", i);
        row.FUN_1407cb9c0("cond", reward->m_count);
        row.FUN_1407cbbe0("received", Contains(received, static_cast<int>(i)));
        ASArray items(2);
        for (size_t j = 0; j < reward->m_items.GetCount(); ++j) {
            ItemEntity& entry = reward->m_items[j];
            MS2Ptr<CItemData> item = FUN_14053f870(entry.m_itemId);
            if (item == NULL) { MS2_ASSERT_AT(210, 0); break; }
            ASObj obj(2);
            obj.SetMemberUInt("itemID", entry.m_itemId);
            obj.FUN_1409adc90("itemRank", static_cast<ItemAble&>(entry).vfunc_o18_1());
            obj.SetMemberUInt("itemCount", entry.m_count);
            obj.FUN_1407cbbe0("itemPiece", item->IsPieceItem());
            obj.FUN_1407cba60("iconPath", FUN_140e83120(entry.m_itemId));
            items.PushValue(obj.FUN_1422bb870());
        }
        row.FUN_1409adbe0("items", items.FUN_1422bb870());
        rewards.PushValue(row.FUN_1422bb870());
    }
    info.FUN_1409adbe0("rewardInfos", rewards.FUN_1422bb870());
    info.FUN_1407cbbe0("isOpenBanner", m_178);
    info.FUN_1407cb9c0("currentPlayCount", FUN_140e832d0());
    m_30->Invoke("init", info.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x140e83370, UIRpsEventDialog, FUN_140e83370, 1715, 0x6169698E);
// @0x140e83a30
void UIRpsEventDialog::FUN_140e83a30() {
    MS2Ptr<RpsContext> event = ((class CGameRule*)FUN_1401c0d90())->GetRps();
    if (event == NULL) return;
    Unk_RpsAvatar* avatar = static_cast<Unk_RpsAvatar*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!avatar) { MS2_ASSERT_AT(72, 0); return; }
    if (m_30 == NULL) { MS2_ASSERT_AT(78, 0); return; }
    if (event == NULL) { MS2_ASSERT_AT(84, 0); return; }
    ATL::CAtlArray<int> received;
    FUN_140e83200(received);
    ASObj info(2);
    ASArray rewards(2);
    for (size_t i = 0; i < event->m_rewards.GetCount(); ++i) {
        MS2Ptr<RpsContext::RewardData> reward = event->m_rewards[i];
        if (reward == NULL) { MS2_ASSERT_AT(98, 0); continue; }
        ASObj row(2);
        row.FUN_140e846b0("index", i);
        row.FUN_1407cbbe0("received", Contains(received, static_cast<int>(i)));
        rewards.PushValue(row.FUN_1422bb870());
    }
    info.FUN_1409adbe0("rewardInfos", rewards.FUN_1422bb870());
    info.FUN_1407cbbe0("isOpenBanner", m_178);
    info.FUN_1407cb9c0("currentPlayCount", FUN_140e832d0());
    m_30->Invoke("updateInfo", info.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x140e83a30, UIRpsEventDialog, FUN_140e83a30, 1032, 0xFB5B37EC);
// @0x140e83e40
void UIRpsEventDialog::RefreshBannerButton() {
    if (m_30 == NULL) return;
    if (!FUN_141924630()) return;
    Unk_RpsAvatar* avatar = static_cast<Unk_RpsAvatar*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (!avatar) return;
    MS2Ptr<Unk_PCBaseComp_ac8> banner = avatar->vfunc_87();
    if (banner == NULL) return;
    bool open = reinterpret_cast<UIHudEntity::Entity*>(banner.operator->())->FUN_140f48d40() ? true : false;
    if (m_178 == open) return;
    m_178 = open;
    m_30->Invoke("refreshBannerButton", m_178);
}
MS2_REPLACE_METHOD(0x140e83e40, UIRpsEventDialog, RefreshBannerButton, 344, 0x1DFD9EF8);
// @0x140e83fa0
void UIRpsEventDialog::FUN_140e83fa0(int index) {
    MS2Ptr<RpsContext> event = ((class CGameRule*)FUN_1401c0d90())->GetRps();
    if (event == NULL) return;
    if ((index >= 0 && index <= static_cast<int>(event->m_rewards.GetCount()) - 1) == false) { MS2_ASSERT_AT(457, 0); return; }
    MS2Ptr<RpsContext::RewardData> reward = event->m_rewards[index];
    if (reward == NULL) { MS2_ASSERT_AT(464, 0); return; }
    int count = FUN_140e832d0();
    if (reward->m_count > count) return;
    COutPacket packet(static_cast<int>(SendOp::Microgame), 0);
    packet.Encode2(10);
    packet.Encode4(index);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140e83fa0, UIRpsEventDialog, FUN_140e83fa0, 491, 0xE201910B);
// @0x140e841a0
int UIRpsEventDialog::FUN_140e841a0() {
    MS2Ptr<RpsContext> event = ((class CGameRule*)FUN_1401c0d90())->GetRps();
    if (event == NULL) return 0;
    int played = FUN_140e832d0();
    ATL::CAtlArray<int> received;
    FUN_140e83200(received);
    int count = 0;
    for (size_t i = 0; i < event->m_rewards.GetCount(); ++i) {
        if (Contains(received, static_cast<int>(i)) == true) continue;
        MS2Ptr<RpsContext::RewardData> reward = event->m_rewards[i];
        if (reward == NULL) { MS2_ASSERT_AT(419, 0); break; }
        if (played >= reward->m_count) ++count;
    }
    return count;
}
MS2_REPLACE_METHOD(0x140e841a0, UIRpsEventDialog, FUN_140e841a0, 412, 0x05B04C1D);
// @0x140e84350
void UIRpsEventDialog::FUN_140e84350(GameEventVariable*) { FUN_140e83a30(); }
MS2_REPLACE_METHOD(0x140e84350, UIRpsEventDialog, FUN_140e84350, 29, 0xB2FF4CA7);
// @0x140e84380
void UIRpsEventDialog::OnPacketRefresh(CInPacket&) {
    if (FUN_141924630()) FUN_140e83a30();
}
MS2_REPLACE_METHOD(0x140e84380, UIRpsEventDialog, OnPacketRefresh, 43, 0x27F8372B);
// @0x140e84a60
int UIRpsEventDialog::vfunc_48() { return 0x4f5f; }
MS2_REPLACE_METHOD(0x140e84a60, UIRpsEventDialog, vfunc_48, 11, 0x51EC8AA1);
