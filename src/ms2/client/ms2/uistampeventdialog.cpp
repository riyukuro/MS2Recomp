// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Stamp event board dialog.
// MS2-UNIT: ?\uistampeventdialog.cpp
// MS2-RANGE: 0x140ed74c0-0x140ed9b80 .text$mn
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uistampeventdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uistampeventdialog.h"
#include "uiquesteventlistener.h"                       // UIQuestEventDispatcher
#include "ms2/commonfiles/gamerule.h"
#include "ms2/commonfiles/gameevent.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The list control of the movie (the AS list with clear / append).
class Unk_StampList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                               // clear
    void FUN_1422dd230(const ASObj& row);               // append a row
};

// The event counter / string tables (two objects 0x50 apart; the first is g_attendTable).
class Unk_AttendTable
{
public:
    int FUN_1409617d0(int nKind, unsigned nId, const int& nDefault);
    CStringW FUN_140c6d980(int nStringId, int nEventId, const CStringW& strDefault);
};
extern Unk_AttendTable g_attendTable;                   // 0x143ab2fc0
extern Unk_AttendTable g_stampTable;                    // 0x143ab3010

// The world manager (singleton accessor 0x1403ed2d0).
class Unk_StampWorld
{
public:
    bool FUN_141bcb0a0();
    void* FUN_141bd0cc0();
};
Unk_StampWorld* FUN_1403ed2d0();
class Unk_StampUIMgr { public: void FUN_141adc530(int nClass); };
Unk_StampUIMgr* FUN_1403ed2b0();
class Unk_StampNames { public: CStringW FUN_141811980(int nKind, int nId); };
Unk_StampNames* FUN_1401a9d70();
class Unk_StampItem { public: CString FUN_14053fdd0(); };
class Unk_StampNotices { public: void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> handler); };
Unk_StampNotices* FUN_140939a10();

// A quest as handed to the listener: the CQuestCommon base sits at +0x18 (after CPtred).
class Unk_StampQuestData
{
public:
    char m_pad[0x350];
    int type;
};
MS2_CHECK_OFFSET(Unk_StampQuestData, type, 0x350);
class Unk_StampQuestView { public: virtual Unk_GalleryPtr<Unk_StampQuestData> vfunc_0(); };
class Unk_StampQuest
{
public:
    int FUN_140bfc580();
    int FUN_1407476d0();
    void* m_0; void* m_8; void* m_10;
    void* data;                                          // polymorphic subobject
};
MS2_CHECK_OFFSET(Unk_StampQuest, data, 0x18);

CGameRule* FUN_1401c0d90();
CQuestManager* FUN_140764020();
UIQuestEventDispatcher* FUN_140bfc4b0();
bool FUN_140184310(const CString&, const char*);
CStringW FUN_1416e5660(int);
CStringW FUN_1416e4df0(int);
CStringW GetStringCommonByKey(const CStringW&);
CStringW FUN_1409e8970(CStringW, const int&, const int&);
void FUN_1401d9a30(const CStringW&, ATL::CAtlArray<int>&, const wchar_t*);
int FUN_1402bacf0(ATL::CAtlArray<int>&, const int&);
CString FUN_14016a600(const wchar_t*, int);
Unk_GalleryPtr<Unk_StampItem> FUN_14053f870(int);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140ed74c0
UIStampEventDialog::UIStampEventDialog()
{
    FUN_141924170(1);
    FUN_140939a10()->FUN_140da4e40(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UIStampEventDialog::FUN_140ed7f90));
}

// @0x140ed7610
UIStampEventDialog::~UIStampEventDialog() {}

// @0x140ed7680
CString UIStampEventDialog::GetTypeName() { return "StampEventDialog"; }
MS2_REPLACE_METHOD(0x140ED7680, UIStampEventDialog, GetTypeName, 61, 0x64489ED9);

// @0x140ed76d0
int UIStampEventDialog::vfunc_65()
{
    if (!UIDialog::vfunc_65()) return 0;
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    return 1;
}
MS2_REPLACE_METHOD(0x140ED76D0, UIStampEventDialog, vfunc_65, 90, 0xE3027E9F);

// @0x140ed7730
void UIStampEventDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140bfc4b0()->FUN_141aa8850(this);
}
MS2_REPLACE_METHOD(0x140ED7730, UIStampEventDialog, vfunc_67, 77, 0x039209C9);

// @0x140ed7790
void UIStampEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    MS2Ptr<StampEventContext> spContext = FUN_1401c0d90()->FUN_14047ca40(g_attendTable);
    if (spContext.IsNull()) return;
    FUN_140ed81a0(spContext);
    FUN_140ed8590(spContext);
    FUN_140ed89f0(spContext);
    FUN_140ed8c70();
    if (MS2Ptr<ASMovieClip> spBg = GetChild<ASMovieClip>("m_eventBg")) {
        spBg->vfunc_13(FUN_140ed9560());
    }
}
MS2_REPLACE_METHOD(0x140ED7790, UIStampEventDialog, OnLoadComplete, 498, 0xBDD26460);

// @0x140ed7990
int UIStampEventDialog::vfunc_13() { return UIDialog::vfunc_13(); }
MS2_REPLACE_METHOD(0x140ED7990, UIStampEventDialog, vfunc_13, 24, 0x0BD12988);

// @0x140ed79b0
void UIStampEventDialog::vfunc_45(Scaleform::GFx::Value* pOut, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pOut, strMethod, pArgs);
    if (FUN_140184310(strMethod, "getTooltipQuest")) {
        int nQuest = pArgs->FUN_1422b8b10();
        if (!FUN_140764020()->FUN_140745630(nQuest) && !FUN_140764020()->FUN_140745590(nQuest)) return;
        CStringW strText = FUN_1416e5660(nQuest);
        ASTooltip tip(1, 2);
        if (tip.FUN_1409e26b0(strText)) {
            tip.FUN_1409c6dc0(1);
            *pOut = tip.FUN_1422bb870();
        }
    } else if (FUN_140184310(strMethod, "getTooltipItem")) {
        int nItem = pArgs->FUN_1422b8b10();
        int nRank = pArgs->FUN_1422b8b10();
        void* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pActor) {
            ASTooltip tip(pActor, 32, 2);
            if (tip.FUN_1409e1770(nItem, nRank)) *pOut = tip.FUN_1422bb870();
        }
    }
}
MS2_REPLACE_METHOD(0x140ED79B0, UIStampEventDialog, vfunc_45, 500, 0x51B89149);

// @0x140ed7bb0
int UIStampEventDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs)) return 1;
    if (!_stricmp(szMethod, "onClickCompleteReward")) {
        SendEventRewardMode1();
        return 1;
    } else {
        if (!_stricmp(szMethod, "onClickReward")) {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs)) {
                int nCount = data.FUN_1422b8a10();
                int nSpecial = data.FUN_1422b8a90();
                SendEventRewardMode0(nCount, nSpecial);
                return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140ED7BB0, UIStampEventDialog, vfunc_28, 300, 0xBCEE9D23);

// @0x140ed7cf0
void UIStampEventDialog::vfunc_o178_10(void* pQuest)
{
    if (m_30.IsNull()) return;
    MS2Ptr<StampEventContext> spContext = FUN_1401c0d90()->FUN_14047ca40(g_attendTable);
    if (spContext.IsNull()) return;
    if (reinterpret_cast<Unk_StampQuestView*>(&static_cast<Unk_StampQuest*>(pQuest)->data)->vfunc_0()->type != 2) return;
    if (static_cast<Unk_StampQuest*>(pQuest)->FUN_1407476d0() != 2) return;
    FUN_140ed8c20(static_cast<Unk_StampQuest*>(pQuest)->FUN_140bfc580());
    FUN_140ed8c70();
    FUN_140ed8590(spContext);
}
MS2_REPLACE_METHOD_VIA(0x140ED7CF0, UIStampEventDialog, UIQuestEventListener, vfunc_o178_10, 420, 0xBE2D08E4);

// @0x140ed7ea0
void UIStampEventDialog::FUN_140ed7ea0()
{
    if (m_30.IsNull()) return;
    MS2Ptr<StampEventContext> spContext = FUN_1401c0d90()->FUN_14047ca40(g_attendTable);
    if (spContext.IsNull()) return;
    FUN_140ed8590(spContext);
    FUN_140ed89f0(spContext);
}
MS2_REPLACE_METHOD(0x140ED7EA0, UIStampEventDialog, FUN_140ed7ea0, 223, 0xB0ED8947);

// @0x140ed7f90
void UIStampEventDialog::FUN_140ed7f90(NotifyObject*)
{
    if (FUN_1403ed2d0()->FUN_141bcb0a0()) return;
    MS2Ptr<StampEventContext> spContext = FUN_1401c0d90()->FUN_14047ca40(g_attendTable);
    if (spContext == 0) return;
    if (spContext->m_98 == 0) return;
    FUN_1403ed2b0()->FUN_141adc530(0x4f33);
}
MS2_REPLACE_METHOD(0x140ED7F90, UIStampEventDialog, FUN_140ed7f90, 167, 0xF65B920C);

// @0x140ed8040
int UIStampEventDialog::FUN_140ed8040()
{
    MS2Ptr<StampEventContext> spContext = FUN_1401c0d90()->FUN_14047ca40(g_attendTable);
    if (spContext.IsNull()) return 0;
    int nCount = 0;
    for (size_t i = 0; i < spContext->m_rewards.GetCount(); ++i) {
        MS2Ptr<StampEventContext::Reward> spReward = spContext->m_rewards[i];
        if (FUN_140ed9180(spReward->m_count, spReward->m_bReceived) != 1) continue;
        ++nCount;
    }
    if (FUN_140ed8fc0()) ++nCount;
    return nCount;
}
MS2_REPLACE_METHOD(0x140ED8040, UIStampEventDialog, FUN_140ed8040, 343, 0x1695FC8F);

// @0x140ed81a0
void UIStampEventDialog::FUN_140ed81a0(MS2Ptr<StampEventContext> spContext)
{
    if (m_30.IsNull()) return;
    CString strTag = FUN_140ed9560();
    for (size_t i = 0; i < spContext->m_stamps.GetCount(); ++i) {
        MS2Ptr<StampEventContext::Stamp> spStamp = spContext->m_stamps[i];
        CStringW strIcon;
        if (FUN_140764020()->FUN_140745630(spStamp->m_id) || FUN_140764020()->FUN_140745590(spStamp->m_id)) {
            strIcon = FUN_1416e4df0(spStamp->m_id);
        } else {
            strIcon = GetStringCommonByKey(L"s_stampevent_closed_stamp");
        }
        ASObj row(2);
        row.FUN_1407cb9c0("x", spStamp->m_20);
        row.FUN_1407cb9c0("y", spStamp->m_24);
        row.FUN_1409c0d20("id", spStamp->m_id);
        row.FUN_1407cbb20("text", CStringW(strIcon));
        row.FUN_1407cb9c0("isSpecial", spStamp->m_bStamped);
        row.FUN_1407cb9c0("isNew", 0);
        row.FUN_1407cb9c0("isComplete", FUN_140764020()->FUN_140745590(spStamp->m_id));
        row.FUN_1407cba60("eventTag", CString(strTag));
        m_30->Invoke("addStamp", row);
    }
}
MS2_REPLACE_METHOD(0x140ED81A0, UIStampEventDialog, FUN_140ed81a0, 994, 0x3AF2850B);

// @0x140ed8590
void UIStampEventDialog::FUN_140ed8590(MS2Ptr<StampEventContext> spContext)
{
    if (MS2Ptr<Unk_StampList> spList = FUN_140c02900("m_reward")) {
        spList->FUN_1422dd1d0();
        CString strTag = FUN_140ed9560();
        for (size_t i = 0; i < spContext->m_rewards.GetCount(); ++i) {
            MS2Ptr<StampEventContext::Reward> spReward = spContext->m_rewards[i];
            ASObj row(2);
            row.FUN_1407cb9c0("count", spReward->m_count);
            row.FUN_1407cb9c0("isSpecial", spReward->m_bReceived);
            row.FUN_1407cb9c0("state", FUN_140ed9180(spReward->m_count, spReward->m_bReceived));
            row.FUN_1409c0d20("slotID01", spReward->m_item.m_itemId);
            row.FUN_1409c0d20("slotID02", spReward->m_item2.m_itemId);
            row.FUN_1409adc90("slotRank01", static_cast<ItemAble&>(spReward->m_item).vfunc_o18_1());
            row.FUN_1409adc90("slotRank02", static_cast<ItemAble&>(spReward->m_item2).vfunc_o18_1());
            row.FUN_1409c0d20("slotID02", spReward->m_item2.m_itemId);
            row.FUN_1407cba60("slotIcon01", FUN_140ed9480(spReward->m_item.m_itemId));
            row.FUN_1407cba60("slotIcon02", FUN_140ed9480(spReward->m_item2.m_itemId));
            row.FUN_1409c0d20("slotItemCount01", spReward->m_item.m_count);
            row.FUN_1409c0d20("slotItemCount02", spReward->m_item2.m_count);
            row.FUN_1407cba60("eventTag", FUN_140ed9560());
            spList->FUN_1422dd230(row);
        }
        spList->vfunc_24(true);
    }
}
MS2_REPLACE_METHOD(0x140ED8590, UIStampEventDialog, FUN_140ed8590, 1106, 0xBAE78B89);

// @0x140ed89f0
void UIStampEventDialog::FUN_140ed89f0(MS2Ptr<StampEventContext> spContext)
{
    if (m_30.IsNull()) return;
    ASObj row(2);
    row.FUN_1409c0d20("id", spContext->m_item.m_itemId);
    row.FUN_1409adc90("rank", static_cast<ItemAble&>(spContext->m_item).vfunc_o18_1());
    row.FUN_1407cb9c0("active", FUN_140ed8fc0());
    row.FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, spContext->m_item.m_itemId));
    row.FUN_1407cba60("icon", FUN_140ed9480(spContext->m_item.m_itemId));
    row.FUN_1409c0d20("itemCount", static_cast<ItemAble&>(spContext->m_item).vfunc_o18_2());
    m_30->Invoke("setCompleteReward", row);
}
MS2_REPLACE_METHOD(0x140ED89F0, UIStampEventDialog, FUN_140ed89f0, 542, 0xCE1AF92F);

// @0x140ed8c20
void UIStampEventDialog::FUN_140ed8c20(unsigned nQuest)
{
    m_30->Invoke("updateStamp", nQuest);
}
MS2_REPLACE_METHOD(0x140ED8C20, UIStampEventDialog, FUN_140ed8c20, 70, 0x63E446D4);

// @0x140ed8c70
void UIStampEventDialog::FUN_140ed8c70()
{
    MS2Ptr<StampEventContext> spContext = FUN_1401c0d90()->FUN_14047ca40(g_attendTable);
    if (spContext.IsNull()) return;
    int nDone = 0;
    int nTotal = spContext->m_stamps.GetCount();
    for (int i = 0; i < nTotal; ++i) {
        if (FUN_140764020()->FUN_140745590(spContext->m_stamps[i]->m_id)) ++nDone;
    }
    CStringW strText = FUN_1409e8970(CStringW(L"s_stampevent_count"), nDone, nTotal);
    if (MS2Ptr<ASTextField> spCount = FUN_140bb4cf0("m_count")) {
        spCount->FUN_1422c4cd0(strText);
    }
}
MS2_REPLACE_METHOD(0x140ED8C70, UIStampEventDialog, FUN_140ed8c70, 475, 0x07A666E2);

// @0x140ed8e60
void UIStampEventDialog::SendEventRewardMode0(int nCount, int nSpecial)
{
    MS2Ptr<StampEventContext> spContext = FUN_1401c0d90()->FUN_14047ca40(g_attendTable);
    if (spContext.IsNull()) return;
    if (FUN_140ed9180(nCount, nSpecial) != 1) return;
    COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
    packet.Encode1(0);
    packet.Encode4(nCount);
    packet.Encode1((unsigned char)nSpecial);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140ED8E60, UIStampEventDialog, SendEventRewardMode0, 233, 0x8AB083DE);

// @0x140ed8f50
void UIStampEventDialog::SendEventRewardMode1()
{
    if (FUN_140ed8fc0() == 0) return;
    COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
    packet.Encode1(1);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140ED8F50, UIStampEventDialog, SendEventRewardMode1, 91, 0x4FD356E1);

// @0x140ed8fc0
int UIStampEventDialog::FUN_140ed8fc0()
{
    MS2Ptr<StampEventContext> spContext = FUN_1401c0d90()->FUN_14047ca40(g_attendTable);
    if (spContext.IsNull()) return 0;
    Unk_AttendTable* pTable = 0;
    if (spContext->m_b9c) pTable = &g_attendTable;
    else pTable = &g_stampTable;
    int nDefault = 0;
    if (pTable->FUN_1409617d0(0x4b0, spContext->m_eventId, nDefault) != 0) return 0;
    for (size_t i = 0; i < spContext->m_stamps.GetCount(); ++i) {
        MS2Ptr<StampEventContext::Stamp> spStamp = spContext->m_stamps[i];
        if (FUN_140764020()->FUN_140745590(spStamp->m_id) == 0) return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140ED8FC0, UIStampEventDialog, FUN_140ed8fc0, 442, 0xBA274BFD);

// @0x140ed9180
int UIStampEventDialog::FUN_140ed9180(int nCount, int nSpecial)
{
    MS2Ptr<StampEventContext> spContext = FUN_1401c0d90()->FUN_14047ca40(g_attendTable);
    if (spContext.IsNull()) return 0;
    Unk_AttendTable* pTable = 0;
    if (spContext->m_b9c) pTable = &g_attendTable;
    else pTable = &g_stampTable;
    int nKey;
    if (nSpecial) nKey = 0x4b2;
    else nKey = 0x4b1;
    int nStringId = nKey;
    CStringW strList = pTable->FUN_140c6d980(nStringId, spContext->m_eventId, (const wchar_t*)0);
    ATL::CAtlArray<int> counts;
    FUN_1401d9a30(strList, counts, L",");
    if (FUN_1402bacf0(counts, nCount) != -1) return 2;
    int nStamped = 0;
    for (size_t i = 0; i < spContext->m_stamps.GetCount(); ++i) {
        MS2Ptr<StampEventContext::Stamp> spStamp = spContext->m_stamps[i];
        if (spStamp->m_bStamped != nSpecial) continue;
        if (FUN_140764020()->FUN_140745590(spStamp->m_id) == 0) continue;
        ++nStamped;
    }
    if (nStamped < nCount) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140ED9180, UIStampEventDialog, FUN_140ed9180, 753, 0x2729A456);

// @0x140ed9480
CString UIStampEventDialog::FUN_140ed9480(int nItemId)
{
    if (nItemId == 0) return "";
    Unk_GalleryPtr<Unk_StampItem> spItem = FUN_14053f870(nItemId);
    if (!spItem) return "";
    return spItem->FUN_14053fdd0();
}
MS2_REPLACE_METHOD(0x140ED9480, UIStampEventDialog, FUN_140ed9480, 211, 0x4478F50B);

// @0x140ed9560
CString UIStampEventDialog::FUN_140ed9560()
{
    MS2Ptr<StampEventContext> spContext = FUN_1401c0d90()->FUN_14047ca40(g_attendTable);
    if (spContext.IsNull()) return "";
    return FUN_14016a600(spContext->m_strTitle, 0);
}
MS2_REPLACE_METHOD(0x140ED9560, UIStampEventDialog, FUN_140ed9560, 192, 0x6C24E849);

MS2_EMIT_CRT_MEMMOVE_S();
