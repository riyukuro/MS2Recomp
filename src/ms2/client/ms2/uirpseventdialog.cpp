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
#include "uirpseventdialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uimessagebox.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

static const CStringW s_bannerClose(L"bannerClose");

// Unit-local declarations of unrecovered objects; scalar pads preserve /GS behavior.
class ASData : public CPtred {
public:
    ASData();
    virtual ~ASData();
    int FUN_1422b8b10();
    int FUN_1422b9620(const Scaleform::GFx::Value*, unsigned int);
    void FUN_1422b8370(size_t);
    Scaleform::GFx::Value FUN_1422b9260();
private:
    void* p18; void* p20; void* p28; void* p30; void* p38; void* p40;
};
// 0x48, not 0x50 (UIMsg adds an int at +0x48): /Od orders frame slots by size, see RECOVERY.md §8.
MS2_CHECK_SIZE(ASData, 0x48);
class Unk_RpsASObj : public CPtred {
public:
    Unk_RpsASObj(int);
    Scaleform::GFx::Value& FUN_1422bb870();
    virtual ~Unk_RpsASObj();
    void FUN_1407cb9c0(const char*, int);
    void FUN_1407cbbe0(const char*, bool);
    void FUN_1409c0d20(const char*, int);
    void FUN_1409adc90(const char*, int);
    void FUN_1407cba60(const char*, CString);
    void FUN_1409adbe0(const char*, Scaleform::GFx::Value);
    template<class T> void Set(const char* name, T value) {
        ASData args;
        args.FUN_1422b8370(value);
        SetValue(m_value, name, args.FUN_1422b9260());
    }
private:
    void* p18;
    Scaleform::GFx::Value m_value;
    static void SetValue(Scaleform::GFx::Value&, const char*, const Scaleform::GFx::Value&);
};
class Unk_RpsASArray : public Unk_RpsASObj {
public:
    Unk_RpsASArray(int);
    virtual ~Unk_RpsASArray();
    bool FUN_1422bc050(Scaleform::GFx::Value);
};
MS2_CHECK_SIZE(Unk_RpsASObj, 0x40);
MS2_CHECK_SIZE(Unk_RpsASArray, 0x40);
class Unk_RpsInts {
public:
    Unk_RpsInts();
    ~Unk_RpsInts();
    size_t GetCount() const;
    int& operator[](size_t);
private:
    void* p0; size_t p8; size_t p10; size_t p18;
};
MS2_CHECK_SIZE(Unk_RpsInts, 0x20);
template<class T> bool Contains(T& values, int n) {
    if (values.GetCount() == 0) return false;
    {
        for (unsigned int i = 0; i < values.GetCount(); ++i) {
            if (values[i] == n) return true;
        }
    }
    return false;
}
class Unk_RpsItemRank { public: virtual int vfunc_0(); virtual int vfunc_1(); };
struct Unk_RpsRewardItem {
    void* p0; void* p8; void* p10;
    Unk_RpsItemRank rank;
    int itemId; int count;
};
MS2_CHECK_SIZE(Unk_RpsRewardItem, 0x28);
MS2_CHECK_OFFSET(Unk_RpsRewardItem, itemId, 0x20);
class Unk_RpsItems {
public: size_t size() const; Unk_RpsRewardItem& operator[](size_t);
private: void* p0; void* p8; void* p10;
};
struct Unk_RpsReward {
    void* p0; void* p8; void* p10;
    int playCount; int p1c;
    Unk_RpsItems items;
};
MS2_CHECK_SIZE(Unk_RpsReward, 0x38);
MS2_CHECK_OFFSET(Unk_RpsReward, items, 0x20);
class Unk_RpsRewards {
public: size_t size() const; const MS2Ptr<Unk_RpsReward>& operator[](size_t);
private: void* p0; void* p8; void* p10;
};
class Unk_RpsEvent {
public:
    void* p0; void* p8; void* p10; void* p18; void* p20;
    Unk_RpsRewards rewards;
    void* p40;
    int eventId;
};
MS2_CHECK_OFFSET(Unk_RpsEvent, rewards, 0x28);
MS2_CHECK_OFFSET(Unk_RpsEvent, eventId, 0x48);
class Unk_1401c0d90 { public: MS2Ptr<Unk_RpsEvent> FUN_14047d140(); };
Unk_1401c0d90* FUN_1401c0d90();
class Unk_RpsStringTable {
public:
    CStringW FUN_140c6d980(int, int, const CStringW&);
    int FUN_1409617d0(int, int, const int&);
};
extern Unk_RpsStringTable g_rpsStrings;
void FUN_1401d9a30(const CStringW&, Unk_RpsInts&, const wchar_t*);
class Unk_RpsItem { public: CString FUN_14053fdd0(); bool FUN_14053d990(); };
MS2Ptr<Unk_RpsItem> FUN_14053f870(int);
class Unk_RpsBanner { public: int FUN_140f48d40(); };
class Unk_RpsMode { public: int FUN_140953530(); };
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
    virtual MS2Ptr<Unk_RpsBanner> vfunc_87();
    bool FUN_140b7f400();
    Unk_RpsMode* FUN_140a7b810();
    int FUN_14166c930();
};
class Unk_RpsAvatarManager { public: Unk_RpsAvatar* FUN_141bd0cc0(); };
Unk_RpsAvatarManager* FUN_1403ed2d0();
class Unk_RpsPacketManager {
public:
    void FUN_140da5180(int, Delegate<void(CInPacket&)>);
    void FUN_140da51e0(int, Delegate<void(CInPacket&)>);
};
Unk_RpsPacketManager* FUN_140bccd50();
class Unk_RpsEventManager {
public:
    void FUN_140da5430(int, Delegate<void(GameEventVariable*)>);
    void FUN_140da5490(int, Delegate<void(GameEventVariable*)>);
};
Unk_RpsEventManager* FUN_140933220();
class Unk_RpsTooltip : public AScript {
public:
    Unk_RpsTooltip(Unk_RpsAvatar*, int, int);
    virtual ~Unk_RpsTooltip();
    int FUN_1409e1770(int, int);
private: void* p40; void* p48; void* p50; void* p58;
};
MS2_CHECK_SIZE(Unk_RpsTooltip, 0x60);
bool FUN_140184310(const CString&, const char*);
bool FUN_140b883c0();
void FUN_141275260(int, int, int);
class Unk_RpsMsgBoxData { public: void FUN_141a01660(const CStringW&); void FUN_141a024a0(int); };
MS2Ptr<Unk_RpsMsgBoxData> FUN_140d73f20(CStringW, int);
void FUN_140d73c60(MS2Ptr<Unk_RpsMsgBoxData>);
void FUN_140d73aa0(CStringW, int, IMessageListener*, CStringW);
CStringW FUN_1409eec40(int);
CStringW GetStringCommonByKey(const CStringW&);
void FUN_14151f200();

// @0x140e82350
UIRpsEventDialog::UIRpsEventDialog() : m_178(false) {
    FUN_141924170(1);
    FUN_140bccd50()->FUN_140da5180(0x10b, Delegate<void(CInPacket&)>(this, &UIRpsEventDialog::FUN_140e84380));
}
// @0x140e82450
UIRpsEventDialog::~UIRpsEventDialog() {
    FUN_140bccd50()->FUN_140da51e0(0x10b, Delegate<void(CInPacket&)>(this, &UIRpsEventDialog::FUN_140e84380));
}
// @0x140e82520
CString UIRpsEventDialog::GetTypeName() { return "RpsEventDialog"; }
MS2_REPLACE_METHOD(0x140e82520, UIRpsEventDialog, GetTypeName, 61, 0x51A22B9E);
// @0x140e82570
void UIRpsEventDialog::vfunc_72() {
    UIDialog::vfunc_72();
    FUN_140e83e40();
}
MS2_REPLACE_METHOD(0x140e82570, UIRpsEventDialog, vfunc_72, 34, 0x702E0955);
// @0x140e825a0
void UIRpsEventDialog::vfunc_67() {
    UIDialog::vfunc_67();
    FUN_140933220()->FUN_140da5490(0x708, Delegate<void(GameEventVariable*)>(this, &UIRpsEventDialog::FUN_140e84350));
    FUN_140933220()->FUN_140da5490(0x709, Delegate<void(GameEventVariable*)>(this, &UIRpsEventDialog::FUN_140e84350));
    Unk_RpsAvatar* avatar = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (avatar) {
        if (avatar->FUN_14166c930() == 0x3b) avatar->vfunc_59(1, 0, 0, 0);
    }
}
MS2_REPLACE_METHOD(0x140e825a0, UIRpsEventDialog, vfunc_67, 408, 0x3669444F);
// @0x140e82740
void UIRpsEventDialog::OnLoadComplete() {
    UIDialog::OnLoadComplete();
    FUN_140933220()->FUN_140da5430(0x708, Delegate<void(GameEventVariable*)>(this, &UIRpsEventDialog::FUN_140e84350));
    FUN_140933220()->FUN_140da5430(0x709, Delegate<void(GameEventVariable*)>(this, &UIRpsEventDialog::FUN_140e84350));
    MS2Ptr<Unk_RpsEvent> event = FUN_1401c0d90()->FUN_14047d140();
    if (event == NULL) return;
    m_178 = false;
    FUN_140e83370(event);
}
MS2_REPLACE_METHOD(0x140e82740, UIRpsEventDialog, OnLoadComplete, 462, 0x921991B2);
// @0x140e82920
void UIRpsEventDialog::vfunc_45(Scaleform::GFx::Value* result, const CString& method, ASData* args) {
    UIObject::vfunc_45(result, method, args);
    if (FUN_140184310(method, "getTooltipItem")) {
        int item = args->FUN_1422b8b10();
        int rank = args->FUN_1422b8b10();
        Unk_RpsAvatar* avatar = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (avatar) {
            Unk_RpsTooltip tooltip(avatar, 0x20, 2);
            if (tooltip.FUN_1409e1770(item, rank)) *result = tooltip.FUN_1422bb870();
        }
    }
}
MS2_REPLACE_METHOD(0x140e82920, UIRpsEventDialog, vfunc_45, 260, 0xB4209A71);
// @0x140e82a30
int UIRpsEventDialog::vfunc_28(const char* method, const Scaleform::GFx::Value* args, unsigned int count) {
    if (UIDialog::vfunc_28(method, args, count)) return 1;
    Unk_RpsAvatar* avatar = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!avatar) { MS2_ASSERT_AT(244, 0); return 0; }
    if (_stricmp("onOpenBanner", method) == 0) {
        if (!FUN_140b883c0()) { FUN_141275260(0xcfd, 1, 1); return 1; }
        if (!avatar->FUN_140b7f400()) { FUN_141275260(0xcff, 1, 1); return 1; }
        if (avatar->FUN_140a7b810()->FUN_140953530() != 0x1e) { FUN_141275260(0xcfe, 1, 1); return 1; }
        COutPacket packet(0xa8, 0);
        packet.Encode2(0);
        FUN_140710590(packet);
        return 1;
    }
    if (_stricmp("onCloseBanner", method) == 0) {
        MS2Ptr<Unk_RpsBanner> banner = avatar->vfunc_87();
        if (banner == NULL) { MS2_ASSERT_AT(280, 0); return 0; }
        if (!banner->FUN_140f48d40()) return 0;
        {
        CStringW text = FUN_1409eec40(0xd0c);
        MS2Ptr<Unk_RpsMsgBoxData> box = FUN_140d73f20(text, 1);
        box->FUN_141a01660(s_bannerClose);
        box->FUN_141a024a0(0);
        FUN_140d73c60(box);
        }
        return 1;
    }
    if (_stricmp("onReward", method) == 0) {
        ASData data;
        if (!data.FUN_1422b9620(args, count)) { MS2_ASSERT_AT(304, 0); return 0; }
        int index = data.FUN_1422b8b10();
        FUN_140e83fa0(index);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E82A30, UIRpsEventDialog, vfunc_28, 1021, 0x1C4478B1);
// @0x140e82e40
int UIRpsEventDialog::vfunc_71() {
    Unk_RpsAvatar* avatar = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!avatar) { MS2_ASSERT_AT(321, 0); return 0; }
    MS2Ptr<Unk_RpsBanner> banner = avatar->vfunc_87();
    if (banner == NULL) { MS2_ASSERT_AT(328, 0); return 0; }
    if (banner->FUN_140f48d40() == 1) {
        FUN_140d73aa0(GetStringCommonByKey(L"s_rpsevent_ask_close"), 1, this, L"askClose");
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140e82e40, UIRpsEventDialog, vfunc_71, 451, 0x5752C4F7);
// @0x140e83010
int UIRpsEventDialog::OnMessage(UISwfEntity* sender, UIMsg* msg) {
    if (UIDialog::OnMessage(sender, msg)) return 1;
    if (msg->FUN_1422e4520() == 0 && dynamic_cast<UIMessageBox*>(sender)) {
        int result = msg->FUN_1422b8a10();
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
    MS2Ptr<Unk_RpsItem> item = FUN_14053f870(itemId);
    if (item.IsNull()) return "";
    return item->FUN_14053fdd0();
}
MS2_REPLACE_METHOD(0x140e83120, UIRpsEventDialog, FUN_140e83120, 211, 0x281900C9);
// @0x140e83200
void UIRpsEventDialog::FUN_140e83200(Unk_RpsInts& received) {
    MS2Ptr<Unk_RpsEvent> event = FUN_1401c0d90()->FUN_14047d140();
    if (event == NULL) return;
    CStringW values = g_rpsStrings.FUN_140c6d980(0x709, event->eventId, L"");
    FUN_1401d9a30(values, received, L",");
}
MS2_REPLACE_METHOD(0x140e83200, UIRpsEventDialog, FUN_140e83200, 201, 0xDA46B974);
// @0x140e832d0
int UIRpsEventDialog::FUN_140e832d0() {
    MS2Ptr<Unk_RpsEvent> event = FUN_1401c0d90()->FUN_14047d140();
    if (event == NULL) return 0;
    return g_rpsStrings.FUN_1409617d0(0x708, event->eventId, 0);
}
MS2_REPLACE_METHOD(0x140e832d0, UIRpsEventDialog, FUN_140e832d0, 147, 0x667F9F28);
// @0x140e83370
void UIRpsEventDialog::FUN_140e83370(MS2Ptr<Unk_RpsEvent> event) {
    Unk_RpsAvatar* avatar = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!avatar) { MS2_ASSERT_AT(167, 0); return; }
    if (m_30 == NULL) { MS2_ASSERT_AT(173, 0); return; }
    if (event == NULL) { MS2_ASSERT_AT(179, 0); return; }
    Unk_RpsInts received;
    FUN_140e83200(received);
    Unk_RpsASObj info(2);
    Unk_RpsASArray rewards(2);
    for (size_t i = 0; i < event->rewards.size(); ++i) {
        MS2Ptr<Unk_RpsReward> reward = event->rewards[i];
        if (reward == NULL) { MS2_ASSERT_AT(193, 0); continue; }
        Unk_RpsASObj row(2);
        row.Set("index", i);
        row.FUN_1407cb9c0("cond", reward->playCount);
        row.FUN_1407cbbe0("received", Contains(received, static_cast<int>(i)));
        Unk_RpsASArray items(2);
        for (size_t j = 0; j < reward->items.size(); ++j) {
            Unk_RpsRewardItem& entry = reward->items[j];
            MS2Ptr<Unk_RpsItem> item = FUN_14053f870(entry.itemId);
            if (item == NULL) { MS2_ASSERT_AT(210, 0); break; }
            Unk_RpsASObj obj(2);
            obj.FUN_1409c0d20("itemID", entry.itemId);
            obj.FUN_1409adc90("itemRank", (&entry.rank)->vfunc_1());
            obj.FUN_1409c0d20("itemCount", entry.count);
            obj.FUN_1407cbbe0("itemPiece", item->FUN_14053d990());
            obj.FUN_1407cba60("iconPath", FUN_140e83120(entry.itemId));
            items.FUN_1422bc050(obj.FUN_1422bb870());
        }
        row.FUN_1409adbe0("items", items.FUN_1422bb870());
        rewards.FUN_1422bc050(row.FUN_1422bb870());
    }
    info.FUN_1409adbe0("rewardInfos", rewards.FUN_1422bb870());
    info.FUN_1407cbbe0("isOpenBanner", m_178);
    info.FUN_1407cb9c0("currentPlayCount", FUN_140e832d0());
    m_30->Invoke("init", info.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x140e83370, UIRpsEventDialog, FUN_140e83370, 1715, 0x6169698E);
// @0x140e83a30
void UIRpsEventDialog::FUN_140e83a30() {
    MS2Ptr<Unk_RpsEvent> event = FUN_1401c0d90()->FUN_14047d140();
    if (event == NULL) return;
    Unk_RpsAvatar* avatar = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!avatar) { MS2_ASSERT_AT(72, 0); return; }
    if (m_30 == NULL) { MS2_ASSERT_AT(78, 0); return; }
    if (event == NULL) { MS2_ASSERT_AT(84, 0); return; }
    Unk_RpsInts received;
    FUN_140e83200(received);
    Unk_RpsASObj info(2);
    Unk_RpsASArray rewards(2);
    for (size_t i = 0; i < event->rewards.size(); ++i) {
        MS2Ptr<Unk_RpsReward> reward = event->rewards[i];
        if (reward == NULL) { MS2_ASSERT_AT(98, 0); continue; }
        Unk_RpsASObj row(2);
        row.Set("index", i);
        row.FUN_1407cbbe0("received", Contains(received, static_cast<int>(i)));
        rewards.FUN_1422bc050(row.FUN_1422bb870());
    }
    info.FUN_1409adbe0("rewardInfos", rewards.FUN_1422bb870());
    info.FUN_1407cbbe0("isOpenBanner", m_178);
    info.FUN_1407cb9c0("currentPlayCount", FUN_140e832d0());
    m_30->Invoke("updateInfo", info.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x140e83a30, UIRpsEventDialog, FUN_140e83a30, 1032, 0xFB5B37EC);
// @0x140e83e40
void UIRpsEventDialog::FUN_140e83e40() {
    if (m_30 == NULL) return;
    if (!FUN_141924630()) return;
    Unk_RpsAvatar* avatar = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!avatar) return;
    MS2Ptr<Unk_RpsBanner> banner = avatar->vfunc_87();
    if (banner == NULL) return;
    bool open = banner->FUN_140f48d40() ? true : false;
    if (m_178 == open) return;
    m_178 = open;
    m_30->Invoke("refreshBannerButton", m_178);
}
MS2_REPLACE_METHOD(0x140e83e40, UIRpsEventDialog, FUN_140e83e40, 344, 0x1DFD9EF8);
// @0x140e83fa0
void UIRpsEventDialog::FUN_140e83fa0(int index) {
    MS2Ptr<Unk_RpsEvent> event = FUN_1401c0d90()->FUN_14047d140();
    if (event == NULL) return;
    if ((index >= 0 && index <= static_cast<int>(event->rewards.size()) - 1) == false) { MS2_ASSERT_AT(457, 0); return; }
    MS2Ptr<Unk_RpsReward> reward = event->rewards[index];
    if (reward == NULL) { MS2_ASSERT_AT(464, 0); return; }
    int count = FUN_140e832d0();
    if (reward->playCount > count) return;
    COutPacket packet(0xa8, 0);
    packet.Encode2(10);
    packet.Encode4(index);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140e83fa0, UIRpsEventDialog, FUN_140e83fa0, 491, 0xE201910B);
// @0x140e841a0
int UIRpsEventDialog::FUN_140e841a0() {
    MS2Ptr<Unk_RpsEvent> event = FUN_1401c0d90()->FUN_14047d140();
    if (event == NULL) return 0;
    int played = FUN_140e832d0();
    Unk_RpsInts received;
    FUN_140e83200(received);
    int count = 0;
    for (size_t i = 0; i < event->rewards.size(); ++i) {
        if (Contains(received, static_cast<int>(i)) == true) continue;
        MS2Ptr<Unk_RpsReward> reward = event->rewards[i];
        if (reward == NULL) { MS2_ASSERT_AT(419, 0); break; }
        if (played >= reward->playCount) ++count;
    }
    return count;
}
MS2_REPLACE_METHOD(0x140e841a0, UIRpsEventDialog, FUN_140e841a0, 412, 0x05B04C1D);
// @0x140e84350
void UIRpsEventDialog::FUN_140e84350(GameEventVariable*) { FUN_140e83a30(); }
MS2_REPLACE_METHOD(0x140e84350, UIRpsEventDialog, FUN_140e84350, 29, 0xB2FF4CA7);
// @0x140e84380
void UIRpsEventDialog::FUN_140e84380(CInPacket&) {
    if (FUN_141924630()) FUN_140e83a30();
}
MS2_REPLACE_METHOD(0x140e84380, UIRpsEventDialog, FUN_140e84380, 43, 0x27F8372B);
// @0x140e84a60
int UIRpsEventDialog::vfunc_48() { return 0x4f5f; }
MS2_REPLACE_METHOD(0x140e84a60, UIRpsEventDialog, vfunc_48, 11, 0x51EC8AA1);
