// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Stamp event board dialog.
// MS2-UNIT: ?\uistampeventdialog.cpp
// MS2-RANGE: 0x140ed74c0-0x140ed9b80 .text$mn
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uistampeventdialog.cpp"    // assumed
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"
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
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
#include "ms2/commonfiles/gameeventuservalue.h"
#include "ms2/client/ms2/questmanager_1.h"
#include "ms2/placeholder/questdata.h"

template <> MS2Ptr<ASScrollingList> UISwfEntity::GetChild<ASScrollingList>(const CString& strName);   // 0x140c02900, owned by uiinventorydialog

template <> MS2Ptr<ASMovieClip> UISwfEntity::GetChild<ASMovieClip>(const CString& strName);

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The event counter / string tables (two objects 0x50 apart; the first is g_attendTable).
class Unk_AttendTable
{
public:
    int GetValue(int nKind, unsigned nId, const int& nDefault);
};
class Unk_LtaTable { public: CStringW GetStringValue(int nStringId, int nEventId, const CStringW& strDefault); };
extern GameEventUserValue DAT_143ab2fc0;
extern GameEventUserValue DAT_143ab3010;

// The world manager (singleton accessor 0x1403ed2d0).
class Unk_StampUIMgr { public: void FUN_141adc530(int nClass); };
class Unk_SingletonObj* FUN_140939a10();

void* GetGameRule();
void* FUN_140764020();   // C3: was FUN_140764020
UIQuestEventDispatcher* FUN_140bfc4b0();
CStringW FUN_1416e5660(int);
CStringW GetQuestName(int);
CStringW GetStringCommonByKey(const CStringW&);
void ParseIntArray(CStringW&, ATL::CAtlArray<int>&, const wchar_t*);
namespace Common { template <class T> int FindElement(const ATL::CAtlArray<T>& arr, const T& value); }
CString FUN_14016a600(const wchar_t*, int);
MS2Ptr<CItemData> FUN_14053f870(int);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140ed74c0
UIStampEventDialog::UIStampEventDialog()
{
    SetTweenEnabled(1);
    reinterpret_cast<NotifySystem*>(FUN_140939a10())->RegisterNotify(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UIStampEventDialog::FUN_140ed7f90));
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
    FUN_140bfc4b0()->AddListener(this);
    return 1;
}
MS2_REPLACE_METHOD(0x140ED76D0, UIStampEventDialog, vfunc_65, 90, 0xE3027E9F);

// @0x140ed7730
void UIStampEventDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140bfc4b0()->RemoveListener(this);
}
MS2_REPLACE_METHOD(0x140ED7730, UIStampEventDialog, vfunc_67, 77, 0x039209C9);

// @0x140ed7790
void UIStampEventDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    MS2Ptr<StampEventContext> spContext = reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
    if (spContext.IsNull()) return;
    AddStamps(spContext);
    FUN_140ed8590(spContext);
    SetCompleteReward(spContext);
    FUN_140ed8c70();
    if (MS2Ptr<ASMovieClip> spBg = GetChild<ASMovieClip>("m_eventBg")) {
        spBg->vfunc_13(GetEventTag());
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
    if ((strMethod == "getTooltipQuest")) {
        int nQuest = pArgs->PopUInt();
        if (!((class CQuestManager*)FUN_140764020())->IsQuestActive(nQuest) && !((class CQuestManager*)FUN_140764020())->IsQuestRewarded(nQuest)) return;
        CStringW strText = FUN_1416e5660(nQuest);
        ASTooltip tip(1, 2);
        if (tip.ApplyTextTooltip(strText)) {
            tip.SetTooltipAlign(1);
            *pOut = tip.GetValue();
        }
    } else if ((strMethod == "getTooltipItem")) {
        int nItem = pArgs->PopUInt();
        int nRank = pArgs->PopUInt();
        void* pActor = WorldService::GetInstance()->FUN_141bd0cc0();
        if (pActor) {
            ASTooltip tip(pActor, 32, 2);
            if (tip.FUN_1409e1770(nItem, nRank)) *pOut = tip.GetValue();
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
            if (data.SetArgsIfAny(pArgs, nArgs)) {
                int nCount = data.PopInt();
                int nSpecial = data.PopBool();
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
    MS2Ptr<StampEventContext> spContext = reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
    if (spContext.IsNull()) return;
    if (reinterpret_cast<CQuest*>(pQuest)->GetData()->m_350.m_value != 2) return;
    if (reinterpret_cast<CQuest*>(pQuest)->GetState() != 2) return;
    UpdateStamp(reinterpret_cast<CQuest*>(pQuest)->GetQuestId());
    FUN_140ed8c70();
    FUN_140ed8590(spContext);
}
MS2_REPLACE_METHOD_VIA(0x140ED7CF0, UIStampEventDialog, UIQuestEventListener, vfunc_o178_10, 420, 0xBE2D08E4);

// @0x140ed7ea0
void UIStampEventDialog::FUN_140ed7ea0()
{
    if (m_30.IsNull()) return;
    MS2Ptr<StampEventContext> spContext = reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
    if (spContext.IsNull()) return;
    FUN_140ed8590(spContext);
    SetCompleteReward(spContext);
}
MS2_REPLACE_METHOD(0x140ED7EA0, UIStampEventDialog, FUN_140ed7ea0, 223, 0xB0ED8947);

// @0x140ed7f90
void UIStampEventDialog::FUN_140ed7f90(NotifyObject*)
{
    if (WorldService::GetInstance()->HasTutorial()) return;
    MS2Ptr<StampEventContext> spContext = reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
    if (spContext == 0) return;
    if (spContext->m_98 == 0) return;
    (((CUIService*)(TSingleton<CUIService>::GetInstance()))->OpenDialog((eUIClassID)(0x4f33)));
}
MS2_REPLACE_METHOD(0x140ED7F90, UIStampEventDialog, FUN_140ed7f90, 167, 0xF65B920C);

// @0x140ed8040
int UIStampEventDialog::GetClaimableRewardCount()
{
    MS2Ptr<StampEventContext> spContext = reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
    if (spContext.IsNull()) return 0;
    int nCount = 0;
    for (size_t i = 0; i < spContext->m_rewards.GetCount(); ++i) {
        MS2Ptr<StampEventContext::Reward> spReward = spContext->m_rewards[i];
        if (GetRewardState(spReward->m_count, spReward->m_bReceived) != 1) continue;
        ++nCount;
    }
    if (CanClaimCompleteReward()) ++nCount;
    return nCount;
}
MS2_REPLACE_METHOD(0x140ED8040, UIStampEventDialog, GetClaimableRewardCount, 343, 0x1695FC8F);

// @0x140ed81a0
void UIStampEventDialog::AddStamps(MS2Ptr<StampEventContext> spContext)
{
    if (m_30.IsNull()) return;
    CString strTag = GetEventTag();
    for (size_t i = 0; i < spContext->m_stamps.GetCount(); ++i) {
        MS2Ptr<StampEventContext::Stamp> spStamp = spContext->m_stamps[i];
        CStringW strIcon;
        if (((class CQuestManager*)FUN_140764020())->IsQuestActive(spStamp->m_id) || ((class CQuestManager*)FUN_140764020())->IsQuestRewarded(spStamp->m_id)) {
            strIcon = GetQuestName(spStamp->m_id);
        } else {
            strIcon = GetStringCommonByKey(L"s_stampevent_closed_stamp");
        }
        ASObj row(2);
        row.SetIntMember("x", spStamp->m_20);
        row.SetIntMember("y", spStamp->m_24);
        row.SetMemberUInt("id", spStamp->m_id);
        row.SetWStringMember("text", CStringW(strIcon));
        row.SetIntMember("isSpecial", spStamp->m_bStamped);
        row.SetIntMember("isNew", 0);
        row.SetIntMember("isComplete", ((class CQuestManager*)FUN_140764020())->IsQuestRewarded(spStamp->m_id));
        row.SetStringMember("eventTag", CString(strTag));
        m_30->Invoke("addStamp", row);
    }
}
MS2_REPLACE_METHOD(0x140ED81A0, UIStampEventDialog, AddStamps, 994, 0x3AF2850B);

// @0x140ed8590
void UIStampEventDialog::FUN_140ed8590(MS2Ptr<StampEventContext> spContext)
{
    if (MS2Ptr<ASScrollingList> spList = GetChild<ASScrollingList>("m_reward")) {
        spList->FUN_1422dd1d0();
        CString strTag = GetEventTag();
        for (size_t i = 0; i < spContext->m_rewards.GetCount(); ++i) {
            MS2Ptr<StampEventContext::Reward> spReward = spContext->m_rewards[i];
            ASObj row(2);
            row.SetIntMember("count", spReward->m_count);
            row.SetIntMember("isSpecial", spReward->m_bReceived);
            row.SetIntMember("state", GetRewardState(spReward->m_count, spReward->m_bReceived));
            row.SetMemberUInt("slotID01", spReward->m_item.m_itemId);
            row.SetMemberUInt("slotID02", spReward->m_item2.m_itemId);
            row.FUN_1409adc90("slotRank01", static_cast<ItemAble&>(spReward->m_item).vfunc_o18_1());
            row.FUN_1409adc90("slotRank02", static_cast<ItemAble&>(spReward->m_item2).vfunc_o18_1());
            row.SetMemberUInt("slotID02", spReward->m_item2.m_itemId);
            row.SetStringMember("slotIcon01", GetItemIconPath(spReward->m_item.m_itemId));
            row.SetStringMember("slotIcon02", GetItemIconPath(spReward->m_item2.m_itemId));
            row.SetMemberUInt("slotItemCount01", spReward->m_item.m_count);
            row.SetMemberUInt("slotItemCount02", spReward->m_item2.m_count);
            row.SetStringMember("eventTag", GetEventTag());
            spList->AddItem(row);
        }
        spList->vfunc_24(true);
    }
}
MS2_REPLACE_METHOD(0x140ED8590, UIStampEventDialog, FUN_140ed8590, 1106, 0xBAE78B89);

// @0x140ed89f0
void UIStampEventDialog::SetCompleteReward(MS2Ptr<StampEventContext> spContext)
{
    if (m_30.IsNull()) return;
    ASObj row(2);
    row.SetMemberUInt("id", spContext->m_item.m_itemId);
    row.FUN_1409adc90("rank", static_cast<ItemAble&>(spContext->m_item).vfunc_o18_1());
    row.SetIntMember("active", CanClaimCompleteReward());
    row.SetWStringMember("itemName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, spContext->m_item.m_itemId));
    row.SetStringMember("icon", GetItemIconPath(spContext->m_item.m_itemId));
    row.SetMemberUInt("itemCount", static_cast<ItemAble&>(spContext->m_item).vfunc_o18_2());
    m_30->Invoke("setCompleteReward", row);
}
MS2_REPLACE_METHOD(0x140ED89F0, UIStampEventDialog, SetCompleteReward, 542, 0xCE1AF92F);

// @0x140ed8c20
void UIStampEventDialog::UpdateStamp(unsigned nQuest)
{
    m_30->Invoke("updateStamp", nQuest);
}
MS2_REPLACE_METHOD(0x140ED8C20, UIStampEventDialog, UpdateStamp, 70, 0x63E446D4);

// @0x140ed8c70
void UIStampEventDialog::FUN_140ed8c70()
{
    MS2Ptr<StampEventContext> spContext = reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
    if (spContext.IsNull()) return;
    int nDone = 0;
    int nTotal = spContext->m_stamps.GetCount();
    for (int i = 0; i < nTotal; ++i) {
        if (((class CQuestManager*)FUN_140764020())->IsQuestRewarded(spContext->m_stamps[i]->m_id)) ++nDone;
    }
    CStringW strText = FUN_14028dfa0<int, int>(CStringW(L"s_stampevent_count"), nDone, nTotal);
    if (MS2Ptr<ASTextField> spCount = GetChild<ASTextField>("m_count")) {
        spCount->SetTextW(strText);
    }
}
MS2_REPLACE_METHOD(0x140ED8C70, UIStampEventDialog, FUN_140ed8c70, 475, 0x07A666E2);

// @0x140ed8e60
void UIStampEventDialog::SendEventRewardMode0(int nCount, int nSpecial)
{
    MS2Ptr<StampEventContext> spContext = reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
    if (spContext.IsNull()) return;
    if (GetRewardState(nCount, nSpecial) != 1) return;
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
    if (CanClaimCompleteReward() == 0) return;
    COutPacket packet(static_cast<int>(SendOp::EventReward), 0);
    packet.Encode1(1);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140ED8F50, UIStampEventDialog, SendEventRewardMode1, 91, 0x4FD356E1);

// @0x140ed8fc0
int UIStampEventDialog::CanClaimCompleteReward()
{
    MS2Ptr<StampEventContext> spContext = reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
    if (spContext.IsNull()) return 0;
    Unk_AttendTable* pTable = 0;
    if (spContext->m_b9c) pTable = reinterpret_cast<Unk_AttendTable*>(&DAT_143ab2fc0);
    else pTable = reinterpret_cast<Unk_AttendTable*>(&DAT_143ab3010);
    int nDefault = 0;
    if (pTable->GetValue(0x4b0, spContext->m_eventId, nDefault) != 0) return 0;
    for (size_t i = 0; i < spContext->m_stamps.GetCount(); ++i) {
        MS2Ptr<StampEventContext::Stamp> spStamp = spContext->m_stamps[i];
        if (((class CQuestManager*)FUN_140764020())->IsQuestRewarded(spStamp->m_id) == 0) return 0;
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140ED8FC0, UIStampEventDialog, CanClaimCompleteReward, 442, 0xBA274BFD);

// @0x140ed9180
int UIStampEventDialog::GetRewardState(int nCount, int nSpecial)
{
    MS2Ptr<StampEventContext> spContext = reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
    if (spContext.IsNull()) return 0;
    Unk_AttendTable* pTable = 0;
    if (spContext->m_b9c) pTable = reinterpret_cast<Unk_AttendTable*>(&DAT_143ab2fc0);
    else pTable = reinterpret_cast<Unk_AttendTable*>(&DAT_143ab3010);
    int nKey;
    if (nSpecial) nKey = 0x4b2;
    else nKey = 0x4b1;
    int nStringId = nKey;
    CStringW strList = reinterpret_cast<Unk_LtaTable*>(pTable)->GetStringValue(nStringId, spContext->m_eventId, (const wchar_t*)0);
    ATL::CAtlArray<int> counts;
    ParseIntArray(strList, counts, L",");
    if (Common::FindElement<int>(counts, nCount) != -1) return 2;
    int nStamped = 0;
    for (size_t i = 0; i < spContext->m_stamps.GetCount(); ++i) {
        MS2Ptr<StampEventContext::Stamp> spStamp = spContext->m_stamps[i];
        if (spStamp->m_bStamped != nSpecial) continue;
        if (((class CQuestManager*)FUN_140764020())->IsQuestRewarded(spStamp->m_id) == 0) continue;
        ++nStamped;
    }
    if (nStamped < nCount) return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x140ED9180, UIStampEventDialog, GetRewardState, 753, 0x2729A456);

// @0x140ed9480
CString UIStampEventDialog::GetItemIconPath(int nItemId)
{
    if (nItemId == 0) return "";
    MS2Ptr<CItemData> spItem = FUN_14053f870(nItemId);
    if (!spItem) return "";
    return spItem->GetIconPath();
}
MS2_REPLACE_METHOD(0x140ED9480, UIStampEventDialog, GetItemIconPath, 211, 0x4478F50B);

// @0x140ed9560
CString UIStampEventDialog::GetEventTag()
{
    MS2Ptr<StampEventContext> spContext = reinterpret_cast<CGameRule*>(GetGameRule())->FUN_14047ca40(reinterpret_cast<Unk_AttendTable&>(DAT_143ab2fc0));
    if (spContext.IsNull()) return "";
    return FUN_14016a600(spContext->m_strTitle, 0);
}
MS2_REPLACE_METHOD(0x140ED9560, UIStampEventDialog, GetEventTag, 192, 0x6C24E849);

MS2_EMIT_CRT_MEMMOVE_S();
