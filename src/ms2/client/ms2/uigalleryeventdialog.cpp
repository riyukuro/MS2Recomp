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
static CString s_jobCode = "jobCode";
static CString s_sortValue = "sortValue";
static CString s_tabIndex = "tabIndex";
static UICommon::CMyPCKeyInputController s_keyInputController;

class Unk_GalleryAS;
void GallerySet(Scaleform::GFx::Value*, int);
void GallerySet(Scaleform::GFx::Value*, size_t);
void GallerySet(Scaleform::GFx::Value*, const Unk_GalleryAS&);
class Unk_GalleryAS
{
public:
    template<class A, class B> Scaleform::GFx::Value Invoke2(const char* method, A a, B b)
    {
        ASArgList args;
        args.FUN_1409b2800(2);
        GallerySet(args.FUN_1409b1f70(0), a);
        GallerySet(args.FUN_1409b1f70(1), b);
        return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(method, args);
    }
    Unk_GalleryAS(int);
    ~Unk_GalleryAS();
    Scaleform::GFx::Value& FUN_1422bb870();
    void FUN_1407cb9c0(const char*, int);
    void FUN_1409c0d20(const char*, unsigned int);
    void FUN_1409adc90(const char*, int);
    void FUN_1407cba60(const char*, CString);
    void FUN_1407cbb20(const char*, CStringW);
    void FUN_1409eb270(const char*, const Unk_GalleryAS&);
    Scaleform::GFx::Value FUN_140acd130(const char*, CStringW);
    Scaleform::GFx::Value FUN_140ba4cc0(const char*, const Unk_GalleryAS&);
    Scaleform::GFx::Value FUN_1409ba030(const char*, int);
    Scaleform::GFx::Value FUN_1409ba0d0(const char*, int, int);
private:
    void* m_0; void* m_8; void* m_10; void* m_18; void* m_20; void* m_28; void* m_30; void* m_38;
};
MS2_CHECK_SIZE(Unk_GalleryAS, 0x40);
class Unk_GalleryCard
{
public:
    void* m_0; void* m_8; void* m_10;
    int quest;
};
MS2_CHECK_OFFSET(Unk_GalleryCard, quest, 0x18);
class Unk_GalleryCards
{
public:
    size_t FUN_140412e70() const;
    const Unk_GalleryPtr<Unk_GalleryCard>& FUN_140410e70(size_t) const;
private:
    void* m_0; void* m_8; void* m_10; void* m_18;
};
MS2_CHECK_SIZE(Unk_GalleryCards, 0x20);
class Unk_GalleryRewardRank
{
public:
    virtual void vfunc_0();
    virtual int vfunc_1();
};
class Unk_GalleryReward
{
public:
    void* m_0; void* m_8; void* m_10;
    void* rank; // polymorphic subobject; accessed through its interface below
    int id, count;
};
MS2_CHECK_OFFSET(Unk_GalleryReward, id, 0x20);
class Unk_GalleryRewards
{
public:
    size_t FUN_140412e50() const;
    Unk_GalleryReward& FUN_140410df0(size_t);
private:
    void* m_0; void* m_8; void* m_10; void* m_18;
};
MS2_CHECK_SIZE(Unk_GalleryRewards, 0x20);
class Unk_GalleryContext
{
public:
    Unk_GalleryPtr<Unk_GalleryCard> FUN_1403ff3e0(int);
    void* m_0; void* m_8; void* m_10;
    int id, pad1c;
    Unk_GalleryCards cards;
    Unk_GalleryRewards rewards;
    int maxOpen, pad64;
    void* m_68;
    CStringW illust;
};
MS2_CHECK_OFFSET(Unk_GalleryContext, cards, 0x20);
MS2_CHECK_OFFSET(Unk_GalleryContext, maxOpen, 0x60);
MS2_CHECK_OFFSET(Unk_GalleryContext, illust, 0x70);
class Unk_GalleryManager { public: Unk_GalleryPtr<Unk_GalleryContext> FUN_14047cf60(); };
Unk_GalleryManager* FUN_1401c0d90();
class Unk_GalleryQuestManager
{
public:
    void FUN_141aa87c0(UIQuestEventListener*);
    void FUN_141aa8850(UIQuestEventListener*);
};
Unk_GalleryQuestManager* FUN_140bfc4b0();
class Unk_GalleryQuestState
{
public:
    int FUN_140745630(int);
    int FUN_140745590(int);
    int FUN_1407456d0(int);
    int FUN_140746ba0(int, int, bool);
};
class Unk_GalleryQuestGlobal { public: void* m_0; void* m_8; Unk_GalleryQuestState state; };
Unk_GalleryQuestGlobal* FUN_140764020();
class Unk_GalleryCounters { public: int FUN_1409617d0(int, int, int*); };
extern Unk_GalleryCounters g_galleryCounters;
class Unk_GalleryItem { public: CString FUN_14053fdd0(); };
Unk_GalleryPtr<Unk_GalleryItem> FUN_14053f870(int);
class Unk_GalleryPlayer { public: void* FUN_141bd0cc0(); };
Unk_GalleryPlayer* FUN_1403ed2d0();
bool FUN_140184310(const CString&, const char*);
CStringW FUN_1416e5660(int);
CStringW FUN_1416e4df0(int);
CStringW GetStringCommonByKey(const CStringW&);
void FUN_1412751f0(const CStringW&, int, int);
CStringW FUN_1409eec40(int);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void FUN_140d432d0(ItemSlotBinder*, int);
class Unk_GalleryQuestReward
{
public:
    void* m_0; void* m_8; void* m_10;
    int id, rank, count;
};
class Unk_GalleryQuestRewards
{
public:
    size_t FUN_14075ae60();
    Unk_GalleryQuestReward& FUN_1407591d0(size_t);
};
class Unk_GalleryQuestData
{
public:
    void* m_0;
    void* m_8;
    void* m_10;
    void* m_18;
    void* m_20;
    void* m_28;
    void* m_30;
    void* m_38;
    void* m_40;
    void* m_48;
    void* m_50;
    void* m_58;
    void* m_60;
    void* m_68;
    void* m_70;
    void* m_78;
    void* m_80;
    void* m_88;
    void* m_90;
    void* m_98;
    void* m_a0;
    void* m_a8;
    void* m_b0;
    void* m_b8;
    void* m_c0;
    void* m_c8;
    void* m_d0;
    void* m_d8;
    void* m_e0;
    void* m_e8;
    void* m_f0;
    void* m_f8;
    void* m_100;
    void* m_108;
    void* m_110;
    void* m_118;
    void* m_120;
    void* m_128;
    void* m_130;
    void* m_138;
    void* m_140;
    void* m_148;
    void* m_150;
    void* m_158;
    void* m_160;
    void* m_168;
    void* m_170;
    void* m_178;
    void* m_180;
    void* m_188;
    void* m_190;
    void* m_198;
    void* m_1a0;
    void* m_1a8;
    void* m_1b0;
    void* m_1b8;
    void* m_1c0;
    void* m_1c8;
    void* m_1d0;
    void* m_1d8;
    void* m_1e0;
    void* m_1e8;
    void* m_1f0;
    void* m_1f8;
    void* m_200;
    void* m_208;
    void* m_210;
    void* m_218;
    void* m_220;
    void* m_228;
    void* m_230;
    void* m_238;
    void* m_240;
    void* m_248;
    void* m_250;
    void* m_258;
    void* m_260;
    void* m_268;
    void* m_270;
    void* m_278;
    void* m_280;
    void* m_288;
    void* m_290;
    Unk_GalleryQuestRewards rewards;
    // Only the reward-list address and type field are used; intervening storage is opaque.
    void* m_2a0;
    void* m_2a8;
    void* m_2b0;
    void* m_2b8;
    void* m_2c0;
    void* m_2c8;
    void* m_2d0;
    void* m_2d8;
    void* m_2e0;
    void* m_2e8;
    void* m_2f0;
    void* m_2f8;
    void* m_300;
    void* m_308;
    void* m_310;
    void* m_318;
    void* m_320;
    void* m_328;
    void* m_330;
    void* m_338;
    void* m_340;
    void* m_348;
    int type;
};
MS2_CHECK_OFFSET(Unk_GalleryQuestData, rewards, 0x298);
MS2_CHECK_OFFSET(Unk_GalleryQuestData, type, 0x350);
Unk_GalleryPtr<Unk_GalleryQuestData> FUN_14074bc40(int);
class Unk_GalleryQuestView { public: virtual Unk_GalleryPtr<Unk_GalleryQuestData> vfunc_0(); };
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
class Unk_GalleryRewardDialog { public: void FUN_141abf6e0(int, int); };
Unk_GalleryRewardDialog* FUN_140938cd0(int);
class Unk_GalleryItemNames { public: CStringW FUN_141811980(int, int); };
Unk_GalleryItemNames* FUN_1401a9d70();
class Unk_GalleryItemInstance {};
Unk_GalleryPtr<Unk_GalleryItemInstance> FUN_140ebc360(int, int);
class Unk_GalleryPreview
{
public:
    int FUN_140d40670();
    void FUN_140d40120(Unk_GalleryPtr<Unk_GalleryItemInstance>, int);
};
Unk_GalleryPreview* FUN_1409bb9e0();
class Unk_GalleryAccess { public: bool FUN_14116dcb0(int, int, int); };
Unk_GalleryAccess* FUN_14025e7c0();

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
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) return;
    FUN_140c176f0(context);
    FUN_140c17d20(context);
    FUN_140c18330();
}
MS2_REPLACE_METHOD(0x140C16850, UIGalleryEventDialog, OnLoadComplete, 212, 0x3BFE8DD6);

// @0x140c16930
int UIGalleryEventDialog::vfunc_13() { return UIDialog::vfunc_13(); }
MS2_REPLACE_METHOD(0x140C16930, UIGalleryEventDialog, vfunc_13, 24, 0x9377B5EC);

// @0x140c16950
void UIGalleryEventDialog::vfunc_45(Scaleform::GFx::Value* out, const CString& method, ASData* args)
{
    UIObject::vfunc_45(out, method, args);
    if (FUN_140184310(method, "getTooltipQuest")) {
        int quest = args->FUN_1422b8b10();
        if (!FUN_140764020()->state.FUN_140745630(quest) && !FUN_140764020()->state.FUN_140745590(quest)) return;
        CStringW text = FUN_1416e5660(quest);
        ASTooltip tip(1, 2);
        if (tip.FUN_1409e26b0(text)) {
            tip.FUN_1409c6dc0(1);
            *out = tip.FUN_1422bb870();
        }
    } else if (FUN_140184310(method, "getTooltipItem")) {
        int id = args->FUN_1422b8b10();
        int rank = args->FUN_1422b8b10();
        do {
        void* actor = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (!actor) return;
        ASTooltip tip(actor, 32, 2);
        if (!tip.FUN_1409e1770(id, rank)) return;
        auto item = FUN_14053f870(id);
        if (!item) return;
        tip.FUN_1409db870(item);
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
        if (!FUN_140c18f10()) return 1;
        auto context = FUN_1401c0d90()->FUN_14047cf60();
        if ((Unk_GalleryContext*)context) {
            int dummy = 0;
            int opened = g_galleryCounters.FUN_1409617d0(1600, context->id, &dummy);
            if (opened >= context->maxOpen) {
                FUN_140d73aa0(FUN_1409eec40(3323), 0, 0, CStringW(L""));
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
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) return;
    if (reinterpret_cast<Unk_GalleryQuestView*>(&static_cast<Unk_GalleryQuest*>(p)->data)->vfunc_0()->type != 4) return;
    FUN_140c181a0(static_cast<Unk_GalleryQuest*>(p)->FUN_140bfc580());
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
        reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->FUN_1409ba030("openCard", index);
        FUN_140c18330();
        break;
    }
    case 8: {
        int index = reinterpret_cast<Unk_GalleryInput*>(&packet->stream)->vfunc_1();
        reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->Invoke2<int, int>("setQuestState", index, 2);
        if (FUN_140c187e0() == 1) m_30->Invoke("playComplete");
        break;
    }
    case 9: {
        auto context = FUN_1401c0d90()->FUN_14047cf60();
        if (context == 0) return;
        Unk_GalleryRewardDialog* dialog = FUN_140938cd0(20061);
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
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) return 0;
    int count = 0;
    for (size_t i = 0; i < context->cards.FUN_140412e70(); ++i) {
        auto card = context->cards.FUN_140410e70(i);
        if (!card) { MS2_ASSERT_AT(515, "pCard" && 0); return 0; }
        if (FUN_140764020()->state.FUN_1407456d0(card->quest)) ++count;
    }
    return count;
}
MS2_REPLACE_METHOD(0x140C17560, UIGalleryEventDialog, FUN_140c17560, 383, 0x8A7AB2B7);

// @0x140c176f0
void UIGalleryEventDialog::FUN_140c176f0(Unk_GalleryPtr<Unk_GalleryContext> context)
{
    if (!context) { MS2_ASSERT_AT(269, "pContext" && 0); return; }
    if (m_30.IsNull()) return;
    reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->FUN_140acd130("loadIllust", context->illust);
    int dummy = 0;
    int received = g_galleryCounters.FUN_1409617d0(1601, context->id, &dummy);
    if (FUN_140c187e0() == 1 || received == 1) { m_30->Invoke("completed"); return; }
    for (size_t i = 0; i < context->cards.FUN_140412e70(); ++i) {
        auto card = context->cards.FUN_140410e70(i);
        if (!card) { MS2_ASSERT_AT(288, "pCard" && 0); return; }
        auto quest = FUN_14074bc40(card->quest);
        if (!quest) { MS2_ASSERT_AT(291, "pQuestData" && 0); return; }
        if (!quest->rewards.FUN_14075ae60()) {
            MS2_ASSERT_AT(292, "pQuestData->m_rewardComplete.essentialItems.GetCount()" && 0);
            return;
        }
        const auto& item = quest->rewards.FUN_1407591d0(0);
        Unk_GalleryAS cardInfo(2);
        cardInfo.FUN_1407cb9c0("state", FUN_140c18ab0((int)i));
        Unk_GalleryAS questInfo(2);
        questInfo.FUN_1409c0d20("id", card->quest);
        questInfo.FUN_1407cb9c0("state", FUN_140c18c60((int)i));
        questInfo.FUN_1407cba60("binding", m_binder.FUN_140d43310(item.id, item.rank, item.count));
        questInfo.FUN_1407cbb20("desc", FUN_1416e4df0(card->quest));
        questInfo.FUN_1409c0d20("itemID", item.id);
        questInfo.FUN_1409adc90("itemRank", item.rank);
        questInfo.FUN_1407cb9c0("itemCount", item.count);
        questInfo.FUN_1407cba60("iconPath", FUN_140c189d0(item.id));
        cardInfo.FUN_1409eb270("questInfo", questInfo);
        reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->FUN_140ba4cc0("addCard", cardInfo);
    }
}
MS2_REPLACE_METHOD(0x140C176F0, UIGalleryEventDialog, FUN_140c176f0, 1578, 0x076F0802);

// @0x140c17d20
void UIGalleryEventDialog::FUN_140c17d20(Unk_GalleryPtr<Unk_GalleryContext> context)
{
    if (!context) { MS2_ASSERT_AT(318, "pContext" && 0); return; }
    if (m_30.IsNull()) { MS2_ASSERT_AT(319, "m_ascript" && 0); return; }
    if (context->rewards.FUN_140412e50() < 2) { MS2_ASSERT_AT(323, 0); return; }
    int active = FUN_140c187e0();
    auto& first = context->rewards.FUN_140410df0(0);
    auto& second = context->rewards.FUN_140410df0(1);
    Unk_GalleryAS firstInfo(2);
    firstInfo.FUN_1409c0d20("id", first.id);
    firstInfo.FUN_1409adc90("rank", reinterpret_cast<Unk_GalleryRewardRank*>(&first.rank)->vfunc_1());
    firstInfo.FUN_1407cb9c0("active", active);
    firstInfo.FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, first.id));
    firstInfo.FUN_1407cba60("icon", FUN_140c189d0(first.id));
    firstInfo.FUN_1409c0d20("itemCount", first.count);
    Unk_GalleryAS secondInfo(2);
    secondInfo.FUN_1409c0d20("id", second.id);
    secondInfo.FUN_1409adc90("rank", reinterpret_cast<Unk_GalleryRewardRank*>(&second.rank)->vfunc_1());
    secondInfo.FUN_1407cb9c0("active", active);
    secondInfo.FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, second.id));
    secondInfo.FUN_1407cba60("icon", FUN_140c189d0(second.id));
    secondInfo.FUN_1409c0d20("itemCount", second.count);
    reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->Invoke2<const Unk_GalleryAS&, const Unk_GalleryAS&>("setRewardItem", firstInfo, secondInfo);
    FUN_140c18460();
}
MS2_REPLACE_METHOD(0x140C17D20, UIGalleryEventDialog, FUN_140c17d20, 1139, 0x035C4B59);

// @0x140c181a0
void UIGalleryEventDialog::FUN_140c181a0(int quest)
{
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) return;
    for (size_t i = 0; i < context->cards.FUN_140412e70(); ++i) {
        auto card = context->cards.FUN_140410e70(i);
        if (!card) { MS2_ASSERT_AT(362, "pCard" && 0); break; }
        if (card->quest == quest)
            reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->Invoke2<size_t, int>("setQuestState", i, FUN_140c18c60((int)i));
    }
}
MS2_REPLACE_METHOD(0x140C181A0, UIGalleryEventDialog, FUN_140c181a0, 388, 0xF352F41A);

// @0x140c18330
void UIGalleryEventDialog::FUN_140c18330()
{
    if (m_30.IsNull()) { MS2_ASSERT_AT(373, "m_ascript" && 0); return; }
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) return;
    int dummy = 0;
    int opened = g_galleryCounters.FUN_1409617d0(1600, context->id, &dummy);
    reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->FUN_1409ba0d0("setOpenCount", opened, context->maxOpen);
}
MS2_REPLACE_METHOD(0x140C18330, UIGalleryEventDialog, FUN_140c18330, 298, 0x6A2711D5);

// @0x140c18460
void UIGalleryEventDialog::FUN_140c18460()
{
    reinterpret_cast<Unk_GalleryAS*>(m_30.operator->())->FUN_1409ba030("enableBoardRewardButton", FUN_140c187e0());
}
MS2_REPLACE_METHOD(0x140C18460, UIGalleryEventDialog, FUN_140c18460, 79, 0x4C57278E);

// @0x140c184c0
void UIGalleryEventDialog::SendEventRewardMode7(int index)
{
    if (!FUN_140c18f10()) return;
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) return;
    auto card = context->FUN_1403ff3e0(index);
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
    if (!FUN_140c18f10()) return;
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) return;
    auto card = context->FUN_1403ff3e0(index);
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
    if (!FUN_140c18f10()) return;
    if (!FUN_140c187e0()) return;
    COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
    packet.Encode1(9);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140C18760, UIGalleryEventDialog, SendEventRewardMode9, 110, 0xCEE06F2A);

// @0x140c187e0
int UIGalleryEventDialog::FUN_140c187e0()
{
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) return 0;
    int dummy = 0;
    if (g_galleryCounters.FUN_1409617d0(1601, context->id, &dummy)) return 0;
    for (size_t i = 0; i < context->cards.FUN_140412e70(); ++i) {
        auto card = context->cards.FUN_140410e70(i);
        if (!card) { MS2_ASSERT_AT(449, "pCard" && 0); return 0; }
        if (!FUN_140764020()->state.FUN_140745590(card->quest)) return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140C187E0, UIGalleryEventDialog, FUN_140c187e0, 475, 0xCC0A58C4);

// @0x140c189d0
CString UIGalleryEventDialog::FUN_140c189d0(int id)
{
    if (!id) return "";
    auto item = FUN_14053f870(id);
    if (!item) return "";
    return item->FUN_14053fdd0();
}
MS2_REPLACE_METHOD(0x140C189D0, UIGalleryEventDialog, FUN_140c189d0, 211, 0x632BB788);

// @0x140c18ab0
int UIGalleryEventDialog::FUN_140c18ab0(int index)
{
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) return 0;
    auto card = context->FUN_1403ff3e0(index);
    if (!card) { MS2_ASSERT_AT(477, "pCard" && 0); return 0; }
    if (FUN_140764020()->state.FUN_140745630(card->quest)) return 1;
    if (FUN_140764020()->state.FUN_140745590(card->quest)) return 2;
    return 0;
}
MS2_REPLACE_METHOD(0x140C18AB0, UIGalleryEventDialog, FUN_140c18ab0, 416, 0xC5CC6671);

// @0x140c18c60
int UIGalleryEventDialog::FUN_140c18c60(int index)
{
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) return 0;
    auto card = context->FUN_1403ff3e0(index);
    if (!card) { MS2_ASSERT_AT(495, "pCard" && 0); return 0; }
    if (FUN_140764020()->state.FUN_140745590(card->quest)) return 2;
    else if (!FUN_140764020()->state.FUN_140746ba0(card->quest, 0, 0)) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140C18C60, UIGalleryEventDialog, FUN_140c18c60, 422, 0xC1D54FAC);

// @0x140c18e10
void UIGalleryEventDialog::FUN_140c18e10(int id, int rank)
{
    if (m_30.IsNull()) return;
    if (!FUN_14025e7c0()->FUN_14116dcb0(300038, 0, 0)) return;
    auto item = FUN_140ebc360(id, rank);
    if (!item) return;
    if (FUN_1409bb9e0()->FUN_140d40670()) FUN_1409bb9e0()->FUN_140d40120(item, 0);
}
MS2_REPLACE_METHOD(0x140C18E10, UIGalleryEventDialog, FUN_140c18e10, 239, 0x33B18A12);

// @0x140c18f10
bool UIGalleryEventDialog::FUN_140c18f10()
{
    auto context = FUN_1401c0d90()->FUN_14047cf60();
    if (context == 0) {
        FUN_1412751f0(GetStringCommonByKey(L"s_galleryevent_invalid_event"), 1, 1);
        return false;
    }
    return true;
}
MS2_REPLACE_METHOD(0x140C18F10, UIGalleryEventDialog, FUN_140c18f10, 197, 0x726D60DF);

MS2_EMIT_CRT_MEMMOVE_S();
