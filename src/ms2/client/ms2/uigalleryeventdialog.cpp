// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Gallery event cards and rewards.
// MS2-UNIT: client\ms2\uigalleryeventdialog.cpp
// MS2-RANGE: 0x140c165e0-0x140c193f0 .text$mn
// MS2-RANGE: 0x1400cc000-0x1400cc300 .text$di
// MS2-RANGE: 0x142ca24c0-0x142ca25f5 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigalleryeventdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uigalleryeventdialog.h"
static CString s_sortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/client/ms2/uirewardnotify.h"
#include "ms2/client/ms2/itempreview.h"
#include "ms2/placeholder/cquestmanagercommon.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/commonfiles/gameeventuservalue.h"
#include "ms2/placeholder/cinputkeyhandler.h"
static CString s_jobCode = "jobCode";
static CString s_sortValue = "sortValue";
static CString s_tabIndex = "tabIndex";
static UICommon::CMyPCKeyInputController s_keyInputController;

class AScript;
void FUN_1422bccb0(Scaleform::GFx::Value*, int);
void FUN_1422bce00(Scaleform::GFx::Value*, size_t);
void FUN_1422bce40(Scaleform::GFx::Value*, const AScript&);
class Unk_GalleryAS
{
public:
    template<class A, class B> Scaleform::GFx::Value Invoke2(const char* method, A a, B b);
    Unk_GalleryAS(int);
    ~Unk_GalleryAS();
    Scaleform::GFx::Value& FUN_1422bb870();
    void FUN_1409c0d20(const char*, unsigned int);
    void FUN_1409adc90(const char*, int);
    void FUN_1409eb270(const char*, const Unk_GalleryAS&);
private:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38;
};
MS2_CHECK_SIZE(Unk_GalleryAS, 0x40);
template<> inline Scaleform::GFx::Value Unk_GalleryAS::Invoke2<int, int>(const char* method, int a, int b)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bccb0(args.FUN_1409b1f70(0), a);
    FUN_1422bccb0(args.FUN_1409b1f70(1), b);
    return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(method, args);
}
template<> inline Scaleform::GFx::Value Unk_GalleryAS::Invoke2<size_t, int>(const char* method, size_t a, int b)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce00(args.FUN_1409b1f70(0), a);
    FUN_1422bccb0(args.FUN_1409b1f70(1), b);
    return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(method, args);
}
template<> inline Scaleform::GFx::Value Unk_GalleryAS::Invoke2<const Unk_GalleryAS&, const Unk_GalleryAS&>(const char* method, const Unk_GalleryAS& a, const Unk_GalleryAS& b)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce40(args.FUN_1409b1f70(0), reinterpret_cast<const AScript&>(a));
    FUN_1422bce40(args.FUN_1409b1f70(1), reinterpret_cast<const AScript&>(b));
    return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(method, args);
}
void* FUN_1401c0d90();
template <> inline bool MS2Ptr<GalleryContext>::operator==(GalleryContext* p) const { return m_p == p; }   // 0x140c19220
template <> inline MS2Ptr<GalleryContext>::operator GalleryContext*() const { return m_p; }        // 0x140c19260
UIQuestEventDispatcher* FUN_140bfc4b0();
class Unk_GalleryQuestState
{
public:
    int FUN_140745630(int);
    int FUN_140745590(int);
    int FUN_1407456d0(int);
    int FUN_140746ba0(int, int, bool);
};
class Unk_GalleryQuestGlobal { public: void* m_0; void* m_8; Unk_GalleryQuestState state; };
void* FUN_140764020();
class Unk_AttendTable { public: int FUN_1409617d0(int nKind, unsigned nId, const int& nDefault); };
extern GameEventUserValue DAT_143ab2fc0;
MS2Ptr<CItemData> FUN_14053f870(int);
CStringW FUN_1416e5660(int);
CStringW FUN_1416e4df0(int);
CStringW GetStringCommonByKey(const CStringW&);
void FUN_1412751f0(const CStringW&, int, int);
CStringW BlockFormat(int);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void FUN_140d432d0(ItemSlotBinder*, int);
MS2Ptr<CQuestData> FUN_14074bc40(int);
class Unk_GalleryQuestView { public: virtual MS2Ptr<CQuestData> vfunc_0(); };
class Unk_GalleryQuest
{
public:
    int FUN_140bfc580();
    void* m_0; void* m_8; void* m_10;
    void* data; // polymorphic subobject
};
MS2_CHECK_OFFSET(Unk_GalleryQuest, data, 0x18);
class Unk_GalleryInput
{
public:
    virtual void vfunc_0();
    virtual unsigned char vfunc_1();
    virtual unsigned short vfunc_2();
    virtual int vfunc_3();
};
class Unk_GalleryPacket { public: void* m_0; void* stream; };
UIRewardNotify* FUN_140938cd0(int);
MS2Ptr<CItem> FUN_140ebc360(int, int);
class Unk_ItemPreview* FUN_1409bb9e0();
void* FUN_14025e7c0();

// @0x140c165e0
UIGalleryEventDialog::UIGalleryEventDialog() : m_binder("UIGalleryEvent_QuestReward")
{
    FUN_141924170(1);
    FUN_140d432d0(&m_binder, 17);
}
// @0x140c166c0
UIGalleryEventDialog::~UIGalleryEventDialog() {}
// @0x140c16740
CString UIGalleryEventDialog::GetTypeName() { return "GalleryEventDialog"; }
MS2_REPLACE_METHOD(0x140C16740, UIGalleryEventDialog, GetTypeName, 61, 0x68C7FDA7);

// @0x140c16790
int UIGalleryEventDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65()) return 0;
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    return 1;
}
MS2_REPLACE_METHOD(0x140C16790, UIGalleryEventDialog, vfunc_65, 90, 0x84166C06);

// @0x140c167f0
void UIGalleryEventDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140bfc4b0()->FUN_141aa8850(this);
}
MS2_REPLACE_METHOD(0x140C167F0, UIGalleryEventDialog, vfunc_67, 77, 0xD6C3B993);

// @0x140c16850
void UIGalleryEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) return;
    FUN_140c176f0(context);
    FUN_140c17d20(context);
    UpdateOpenCount();
}
MS2_REPLACE_METHOD(0x140C16850, UIGalleryEventDialog, OnLoadComplete, 212, 0x3BFE8DD6);

// @0x140c16930
int UIGalleryEventDialog::vfunc_13() { return UIDialog::vfunc_13(); }
MS2_REPLACE_METHOD(0x140C16930, UIGalleryEventDialog, vfunc_13, 24, 0x9377B5EC);

// @0x140c16950
void UIGalleryEventDialog::vfunc_45(Scaleform::GFx::Value* out, const CString& method, ASData* args)
{
    UIObject::vfunc_45(out, method, args);
    if ((method == "getTooltipQuest")) {
        int quest = args->FUN_1422b8b10();
        if (!((CQuestManagerCommon*)&((Unk_GalleryQuestGlobal*)FUN_140764020())->state)->IsQuestActive(quest) && !((CQuestManagerCommon*)&((Unk_GalleryQuestGlobal*)FUN_140764020())->state)->FUN_140745590(quest)) return;
        CStringW text = FUN_1416e5660(quest);
        ASTooltip tip(1, 2);
        if (tip.ApplyTextTooltip(text)) {
            tip.SetTooltipAlign(1);
            *out = tip.FUN_1422bb870();
        }
    } else if ((method == "getTooltipItem")) {
        int id = args->FUN_1422b8b10();
        int rank = args->FUN_1422b8b10();
        do {
        void* actor = WorldService::GetInstance()->FUN_141bd0cc0();
        if (!actor) return;
        ASTooltip tip(actor, 32, 2);
        if (!tip.FUN_1409e1770(id, rank)) return;
        auto item = FUN_14053f870(id);
        if (item.IsNull()) return;
        tip.FUN_1409db870(reinterpret_cast<Unk_GalleryPtr<Unk_GalleryItem>&>(item));
        *out = tip.FUN_1422bb870();
        } while (0);
    }
}
MS2_REPLACE_METHOD(0x140C16950, UIGalleryEventDialog, vfunc_45, 647, 0x8F6B65D8);

// @0x140c16be0
int UIGalleryEventDialog::vfunc_28(const char* method, const Scaleform::GFx::Value* args, unsigned int count)
{
    if (UIDialog::vfunc_28(method, args, count)) return 1;
    if (!_stricmp(method, "onCardOpen")) {
        if (!CheckEventContext()) return 1;
        auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
        if ((GalleryContext*)context) {
            int dummy = 0;
            int opened = reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0).FUN_1409617d0(1600, context->m_eventId, dummy);
            if (opened >= context->m_60) {
                FUN_140d73aa0(BlockFormat(3323), 0, 0, CStringW(L""));
                return 1;
            }
            ASData data;
            if (!data.FUN_1422b9620(args, count)) {
                MS2_ASSERT_AT(146, "data.Parsing(args, argCount)" && 0);
                return 0;
            }
            int index = data.FUN_1422b8b10();
            SendEventRewardMode7(index);
        }
        return 1;
    } else if (!_stricmp(method, "onBoardReward")) {
        SendEventRewardMode9();
        return 1;
    } else if (!_stricmp(method, "onQuestReward")) {
        ASData data;
        if (!data.FUN_1422b9620(args, count)) {
            MS2_ASSERT_AT(163, "data.Parsing(args, argCount)" && 0);
            return 0;
        }
        int index = data.FUN_1422b8b10();
        SendEventRewardMode8(index);
        return 1;
    } else if (!_stricmp(method, "OnPreviewItem")) {
        ASData data;
        if (!data.FUN_1422b9620(args, count)) return 0;
        int id = data.FUN_1422b8b10();
        int rank = data.FUN_1422b8b10();
        FUN_140c18e10(id, rank);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140C16BE0, UIGalleryEventDialog, vfunc_28, 1061, 0x775D01C1);

// @0x140c17020
void UIGalleryEventDialog::vfunc_o178_10(void* p)
{
    if (!p) { MS2_ASSERT_AT(204, "quest" && 0); return; }
    if (m_30.IsNull()) { MS2_ASSERT_AT(205, "m_ascript" && 0); return; }
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) return;
    if (reinterpret_cast<Unk_GalleryQuestView*>(&static_cast<Unk_GalleryQuest*>(p)->data)->vfunc_0()->m_350.m_value != 4) return;
    UpdateQuestState(((CQuest*)static_cast<Unk_GalleryQuest*>(p))->FUN_140bfc580());
    FUN_140c17d20(context);
}
MS2_REPLACE_METHOD_VIA(0x140C17020, UIGalleryEventDialog, UIQuestEventListener, vfunc_o178_10, 468, 0x8B363119);

// @0x140c17200
void UIGalleryEventDialog::FUN_140c17200(unsigned int type, Unk_GalleryPacket* packet)
{
    if (m_30.IsNull()) { MS2_ASSERT_AT(220, "m_ascript" && 0); return; }
    switch (type) {
    case 7: {
        int index = reinterpret_cast<Unk_GalleryInput*>(&packet->stream)->vfunc_1();
        m_30->Invoke("openCard", index);
        UpdateOpenCount();
        break;
    }
    case 8: {
        int index = reinterpret_cast<Unk_GalleryInput*>(&packet->stream)->vfunc_1();
        reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->Invoke2<int, int>("setQuestState", index, 2);
        if (FUN_140c187e0() == 1) m_30->Invoke("playComplete");
        break;
    }
    case 9: {
        auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
        if (context == 0) return;
        UIRewardNotify* dialog = FUN_140938cd0(20061);
        if (!dialog) return;
        int count = reinterpret_cast<Unk_GalleryInput*>(&packet->stream)->vfunc_3();
        for (int i = 0; i < count; ++i) {
            int id = reinterpret_cast<Unk_GalleryInput*>(&packet->stream)->vfunc_3();
            int amount = reinterpret_cast<Unk_GalleryInput*>(&packet->stream)->vfunc_2();
            dialog->FUN_141abf6e0(id, amount);
        }
        FUN_140c17d20(context);
        return;
    }
    }
}
MS2_REPLACE_METHOD(0x140C17200, UIGalleryEventDialog, FUN_140c17200, 851, 0x9227AB1E);

// @0x140c17560
int UIGalleryEventDialog::FUN_140c17560()
{
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) return 0;
    int count = 0;
    for (size_t i = 0; i < context->m_cards.GetCount(); ++i) {
        auto card = context->m_cards[i];
        if (!card) { MS2_ASSERT_AT(515, "pCard" && 0); return 0; }
        if (((CQuestManagerCommon*)&((Unk_GalleryQuestGlobal*)FUN_140764020())->state)->IsQuestComplete(card->m_id)) ++count;
    }
    return count;
}
MS2_REPLACE_METHOD(0x140C17560, UIGalleryEventDialog, FUN_140c17560, 383, 0x8A7AB2B7);

// @0x140c176f0
void UIGalleryEventDialog::FUN_140c176f0(MS2Ptr<GalleryContext> context)
{
    if (!context) { MS2_ASSERT_AT(269, "pContext" && 0); return; }
    if (m_30.IsNull()) return;
    m_30->Invoke("loadIllust", context->m_strTitle);
    int dummy = 0;
    int received = reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0).FUN_1409617d0(1601, context->m_eventId, dummy);
    if (FUN_140c187e0() == 1 || received == 1) { m_30->Invoke("completed"); return; }
    for (size_t i = 0; i < context->m_cards.GetCount(); ++i) {
        auto card = context->m_cards[i];
        if (!card) { MS2_ASSERT_AT(288, "pCard" && 0); return; }
        auto quest = FUN_14074bc40(card->m_id);
        if (!quest) { MS2_ASSERT_AT(291, "pQuestData" && 0); return; }
        if (!quest->m_complete.m_choiceRewards.GetCount()) {
            MS2_ASSERT_AT(292, "pQuestData->m_rewardComplete.essentialItems.GetCount()" && 0);
            return;
        }
        const auto& item = ((const ATL::CAtlArray<CQuestData::QuestRewardItem>&)quest->m_complete.m_choiceRewards)[0];
        Unk_GalleryAS cardInfo(2);
        reinterpret_cast<AScript*>(&cardInfo)->FUN_1407cb9c0("state", FUN_140c18ab0((int)i));
        Unk_GalleryAS questInfo(2);
        questInfo.FUN_1409c0d20("id", card->m_id);
        reinterpret_cast<AScript*>(&questInfo)->FUN_1407cb9c0("state", FUN_140c18c60((int)i));
        reinterpret_cast<AScript*>(&questInfo)->FUN_1407cba60("binding", m_binder.BindNewItem(item.m_itemId, item.m_count, item.m_job));
        reinterpret_cast<AScript*>(&questInfo)->FUN_1407cbb20("desc", FUN_1416e4df0(card->m_id));
        questInfo.FUN_1409c0d20("itemID", item.m_itemId);
        questInfo.FUN_1409adc90("itemRank", item.m_count);
        reinterpret_cast<AScript*>(&questInfo)->FUN_1407cb9c0("itemCount", item.m_job);
        reinterpret_cast<AScript*>(&questInfo)->FUN_1407cba60("iconPath", FUN_140c189d0(item.m_itemId));
        cardInfo.FUN_1409eb270("questInfo", questInfo);
        m_30->Invoke("addCard", reinterpret_cast<const AScript&>(cardInfo));
    }
}
MS2_REPLACE_METHOD(0x140C176F0, UIGalleryEventDialog, FUN_140c176f0, 1578, 0x076F0802);

// @0x140c17d20
void UIGalleryEventDialog::FUN_140c17d20(MS2Ptr<GalleryContext> context)
{
    if (!context) { MS2_ASSERT_AT(318, "pContext" && 0); return; }
    if (m_30.IsNull()) { MS2_ASSERT_AT(319, "m_ascript" && 0); return; }
    if (context->m_items.GetCount() < 2) { MS2_ASSERT_AT(323, 0); return; }
    int active = FUN_140c187e0();
    auto& first = context->m_items[0];
    auto& second = context->m_items[1];
    Unk_GalleryAS firstInfo(2);
    firstInfo.FUN_1409c0d20("id", first.m_itemId);
    firstInfo.FUN_1409adc90("rank", static_cast<ItemAble&>(first).vfunc_o18_1());
    reinterpret_cast<AScript*>(&firstInfo)->FUN_1407cb9c0("active", active);
    reinterpret_cast<AScript*>(&firstInfo)->FUN_1407cbb20("itemName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, first.m_itemId));
    reinterpret_cast<AScript*>(&firstInfo)->FUN_1407cba60("icon", FUN_140c189d0(first.m_itemId));
    firstInfo.FUN_1409c0d20("itemCount", first.m_count);
    Unk_GalleryAS secondInfo(2);
    secondInfo.FUN_1409c0d20("id", second.m_itemId);
    secondInfo.FUN_1409adc90("rank", static_cast<ItemAble&>(second).vfunc_o18_1());
    reinterpret_cast<AScript*>(&secondInfo)->FUN_1407cb9c0("active", active);
    reinterpret_cast<AScript*>(&secondInfo)->FUN_1407cbb20("itemName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, second.m_itemId));
    reinterpret_cast<AScript*>(&secondInfo)->FUN_1407cba60("icon", FUN_140c189d0(second.m_itemId));
    secondInfo.FUN_1409c0d20("itemCount", second.m_count);
    reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->Invoke2<const Unk_GalleryAS&, const Unk_GalleryAS&>("setRewardItem", firstInfo, secondInfo);
    UpdateBoardRewardButton();
}
MS2_REPLACE_METHOD(0x140C17D20, UIGalleryEventDialog, FUN_140c17d20, 1139, 0x035C4B59);

// @0x140c181a0
void UIGalleryEventDialog::UpdateQuestState(int quest)
{
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) return;
    for (size_t i = 0; i < context->m_cards.GetCount(); ++i) {
        auto card = context->m_cards[i];
        if (!card) { MS2_ASSERT_AT(362, "pCard" && 0); break; }
        if (card->m_id == quest)
            reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->Invoke2<size_t, int>("setQuestState", i, FUN_140c18c60((int)i));
    }
}
MS2_REPLACE_METHOD(0x140C181A0, UIGalleryEventDialog, UpdateQuestState, 388, 0xF352F41A);

// @0x140c18330
void UIGalleryEventDialog::UpdateOpenCount()
{
    if (m_30.IsNull()) { MS2_ASSERT_AT(373, "m_ascript" && 0); return; }
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) return;
    int dummy = 0;
    int opened = reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0).FUN_1409617d0(1600, context->m_eventId, dummy);
    reinterpret_cast<AScript*>(m_30.operator->())->FUN_1409ba0d0("setOpenCount", opened, context->m_60);
}
MS2_REPLACE_METHOD(0x140C18330, UIGalleryEventDialog, UpdateOpenCount, 298, 0x6A2711D5);

// @0x140c18460
void UIGalleryEventDialog::UpdateBoardRewardButton()
{
    m_30->Invoke("enableBoardRewardButton", FUN_140c187e0());
}
MS2_REPLACE_METHOD(0x140C18460, UIGalleryEventDialog, UpdateBoardRewardButton, 79, 0x4C57278E);

// @0x140c184c0
void UIGalleryEventDialog::SendEventRewardMode7(int index)
{
    if (!CheckEventContext()) return;
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) return;
    auto card = context->GetCard(index);
    if (!card) { MS2_ASSERT_AT(398, "pCard" && 0); return; }
    COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
    packet.Encode1(7);
    packet.Encode1((unsigned char)index);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140C184C0, UIGalleryEventDialog, SendEventRewardMode7, 321, 0x3E2C0F07);

// @0x140c18610
void UIGalleryEventDialog::SendEventRewardMode8(int index)
{
    if (!CheckEventContext()) return;
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) return;
    auto card = context->GetCard(index);
    if (!card) { MS2_ASSERT_AT(416, "pCard" && 0); return; }
    COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
    packet.Encode1(8);
    packet.Encode1((unsigned char)index);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140C18610, UIGalleryEventDialog, SendEventRewardMode8, 321, 0x682700B4);

// @0x140c18760
void UIGalleryEventDialog::SendEventRewardMode9()
{
    if (!CheckEventContext()) return;
    if (!FUN_140c187e0()) return;
    COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
    packet.Encode1(9);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140C18760, UIGalleryEventDialog, SendEventRewardMode9, 110, 0xCEE06F2A);

// @0x140c187e0
int UIGalleryEventDialog::FUN_140c187e0()
{
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) return 0;
    int dummy = 0;
    if (reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0).FUN_1409617d0(1601, context->m_eventId, dummy)) return 0;
    for (size_t i = 0; i < context->m_cards.GetCount(); ++i) {
        auto card = context->m_cards[i];
        if (!card) { MS2_ASSERT_AT(449, "pCard" && 0); return 0; }
        if (!((CQuestManagerCommon*)&((Unk_GalleryQuestGlobal*)FUN_140764020())->state)->FUN_140745590(card->m_id)) return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140C187E0, UIGalleryEventDialog, FUN_140c187e0, 475, 0xCC0A58C4);

// @0x140c189d0
CString UIGalleryEventDialog::FUN_140c189d0(int id)
{
    if (!id) return "";
    auto item = FUN_14053f870(id);
    if (item.IsNull()) return "";
    return item->GetIconPath();
}
MS2_REPLACE_METHOD(0x140C189D0, UIGalleryEventDialog, FUN_140c189d0, 211, 0x632BB788);

// @0x140c18ab0
int UIGalleryEventDialog::FUN_140c18ab0(int index)
{
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) return 0;
    auto card = context->GetCard(index);
    if (!card) { MS2_ASSERT_AT(477, "pCard" && 0); return 0; }
    if (((CQuestManagerCommon*)&((Unk_GalleryQuestGlobal*)FUN_140764020())->state)->IsQuestActive(card->m_id)) return 1;
    if (((CQuestManagerCommon*)&((Unk_GalleryQuestGlobal*)FUN_140764020())->state)->FUN_140745590(card->m_id)) return 2;
    return 0;
}
MS2_REPLACE_METHOD(0x140C18AB0, UIGalleryEventDialog, FUN_140c18ab0, 416, 0xC5CC6671);

// @0x140c18c60
int UIGalleryEventDialog::FUN_140c18c60(int index)
{
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) return 0;
    auto card = context->GetCard(index);
    if (!card) { MS2_ASSERT_AT(495, "pCard" && 0); return 0; }
    if (((CQuestManagerCommon*)&((Unk_GalleryQuestGlobal*)FUN_140764020())->state)->FUN_140745590(card->m_id)) return 2;
    else if (!((CQuestManagerCommon*)&((Unk_GalleryQuestGlobal*)FUN_140764020())->state)->FUN_140746ba0(card->m_id, 0, 0)) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140C18C60, UIGalleryEventDialog, FUN_140c18c60, 422, 0xC1D54FAC);

// @0x140c18e10
void UIGalleryEventDialog::FUN_140c18e10(int id, int rank)
{
    if (m_30.IsNull()) return;
    if (!((CInputKeyHandler*)FUN_14025e7c0())->FUN_14116dcb0(300038, 0, 0)) return;
    auto item = FUN_140ebc360(id, rank);
    if (!item) return;
    if (((ItemPreviewMgr*)FUN_1409bb9e0())->IsHudOn()) ((ItemPreviewMgr*)FUN_1409bb9e0())->OpenPreview(item, 0);
}
MS2_REPLACE_METHOD(0x140C18E10, UIGalleryEventDialog, FUN_140c18e10, 239, 0x33B18A12);

// @0x140c18f10
bool UIGalleryEventDialog::CheckEventContext()
{
    auto context = ((CGameRule*)FUN_1401c0d90())->GetGallery();
    if (context == 0) {
        FUN_1412751f0(GetStringCommonByKey(L"s_galleryevent_invalid_event"), 1, 1);
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140C18F10, UIGalleryEventDialog, CheckEventContext, 197, 0x726D60DF);

MS2_EMIT_CRT_MEMMOVE_S();
