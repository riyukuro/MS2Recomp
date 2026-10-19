// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDailyMissionDialog: see uidailymissiondialog.h.
// MS2-UNIT: ?\uidailymissiondialog.cpp
// MS2-RANGE: 0x1400cba40-0x1400cbbb0 .text$di
// MS2-RANGE: 0x140bff060-0x140c032b0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-FUNCTIONAL: written from the decompile; the quest/handle null-test forms, temporaries and EH unwind maps differ from the exe
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidailymissiondialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uidailymissiondialog.h"
#include "ms2/client/ms2/questmanager_2.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/commonfiles/questdatatable.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cconditioncommon.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <stdlib.h>

MS2_EMIT_CRT_MEMMOVE_S();

// The header statics of this unit (same shape as header_statics_a.h).
#include "ms2/placeholder/header_statics_a.h"

// ---- unit-local views of exe types ----

// The group tab bar of the movie (add a tab / select a tab). ctor 0x1422e2cd0.
class Unk_DmTabBar : public ASDisplayObject
{
public:
    Unk_DmTabBar(const Scaleform::GFx::Value& v, int nMovieId);
    virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bVisible);
    void FUN_1422e3460(const ASObj& row);                       // add a tab
    void FUN_1422e31e0(int nIndex);                             // select a tab
};

// The recommended list of the movie (clear / append). ctor 0x1422e1720.
class Unk_DmList : public AScript
{
public:
    Unk_DmList(const Scaleform::GFx::Value& v, int nMovieId);
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                       // clear
    void FUN_1422dd230(const ASObj& row);                       // append a row
private:
    void* m_unrecovered_40[9];
};
MS2_CHECK_SIZE(Unk_DmList, 0x88);

// The level guide bar of the movie (an ASUIComponent in the exe). ctor 0x1422c7100.
class Unk_DmGuideBar : public AScript
{
public:
    Unk_DmGuideBar(const Scaleform::GFx::Value& v, int nMovieId);
private:
    void* m_unrecovered_40[9];
};

template<class T> MS2Ptr<T> Unk_DmCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}

// @0x140be23c0
template<class T> MS2Ptr<T> AScript::FUN_140be23c0(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return Unk_DmCreate<T>(m_nMovieId, v);
    return MS2Ptr<T>(0);
}

// @0x140bc7280
template<class T> MS2Ptr<T> AScript::FUN_140bc7280(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return Unk_DmCreate<T>(m_nMovieId, v);
    return MS2Ptr<T>(0);
}

// The local player: only the level (slot 78) is used.
typedef unsigned short (*Unk_DmLevelFn)(void*);
inline unsigned short Unk_DmActorLevel(void* pActor) { return reinterpret_cast<Unk_DmLevelFn>((*reinterpret_cast<void***>(pActor))[78])(pActor); }

class Unk_DmFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_DmFeatures* FUN_140166410();

class Unk_DmSceneMgr;
Unk_DmSceneMgr* FUN_1408e57f0();
int FUN_1422b9e00(Unk_DmSceneMgr* pMgr);                                    // the current scene id
class Unk_DmUIMgr { public: void FUN_141adc530(int nUiId); };
Unk_DmUIMgr* FUN_1403ed2b0();
WorldService* FUN_1403ed2d0();
bool FUN_140930b40();
class Unk_DmStatusMgr { public: void FUN_141b0cd00(UIStatusEventListener* p); void FUN_141b0cd90(UIStatusEventListener* p); };
Unk_DmStatusMgr* FUN_140aa6d40();
NotifySystem* FUN_140939a10();
PacketHandlerManager* FUN_140bccd50();
UIQuestEventDispatcher* FUN_140bfc4b0();
CQuestManager* FUN_140764020();
AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);                  // has the AS object been released
QuestDataTable* FUN_1407476c0();
MS2Ptr<CQuestData> FUN_14074bc40(int nQuestId);
int FUN_14074b030(CQuestData* pData);                                       // the quest id
CStringW FUN_1416e5350(int nQuestId, int nIndex);                           // the description text of a quest
__int64 FUN_140761ba0(int nQuestId, int nReward);                           // the experience reward
CStringW FUN_140763e10(int nValue);                                         // the text of a mission point
CStringW FUN_1409404f0(__int64 n);                                          // number with thousands separators
bool FUN_140841300(const CStringW& str, const char* psz);                   // equal ignoring case
CStringW FUN_14062b4f0(CStringW strKey, const int& n);                      // localized text with one number
CStringW FUN_14028b8e0(const CStringW& strKey);                             // string table text
CString FUN_14021a8b0(int n);                                               // int to text
void FUN_1412751f0(const CStringW& text, int nA, int nB);                   // the warning bar
void FUN_140710590(COutPacket& packet);                                     // send
void FUN_141415450(const CString& strBindId, MS2Ptr<CItem> spItem, int a, int b, int c);   // bind the item to the id
void FUN_141415600(const CString& strBindId);                               // release the bind
class Unk_DmStrings { public: CStringW FUN_141811980(int nKind, int nId); };
Unk_DmStrings* FUN_1401a9d70();
void FUN_141924170(UIDialog* p, int n);
extern int DAT_143abdf50;                                              // refresh flags: 1 guide bar / point, 2 list, 4 counts

// @0x140bff060
UIDailyMissionDialog::UIDailyMissionDialog()
{
    FUN_141924170(1);
    m_1b0 = 0;
    FUN_140939a10()->RegisterNotify(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UIDailyMissionDialog::FUN_140bffee0));
    FUN_140939a10()->RegisterNotify(L"NotifyChangeMyPC", Delegate<void(NotifyObject*)>(this, &UIDailyMissionDialog::FUN_140bfff70));
    FUN_140bccd50()->RegisterHandler(0x10b, Delegate<void(CInPacket&)>(this, &UIDailyMissionDialog::FUN_140bfff90));
}

// @0x140bff390
UIDailyMissionDialog::~UIDailyMissionDialog()
{
    FUN_140939a10()->UnregisterNotify(L"NotifyGameStart", Delegate<void(NotifyObject*)>(this, &UIDailyMissionDialog::FUN_140bffee0));
    FUN_140939a10()->UnregisterNotify(L"NotifyChangeMyPC", Delegate<void(NotifyObject*)>(this, &UIDailyMissionDialog::FUN_140bfff70));
    FUN_140bccd50()->UnregisterHandler(0x10b, Delegate<void(CInPacket&)>(this, &UIDailyMissionDialog::FUN_140bfff90));
}

// @0x140bff660
CString UIDailyMissionDialog::vfunc_1() { return "DailyMissionDialog"; }

// @0x140bff6b0
int UIDailyMissionDialog::vfunc_65()
{
    if (!FUN_140bffff0())
    {
        FUN_1412751f0(FUN_14028b8e0(L"s_daily_mission_lack_level_warn"), 1, 1);
        return 0;
    }
    if (UIDialog::vfunc_65() == 0)
        return 0;
    FUN_140bfc4b0()->FUN_141aa87c0(this ? static_cast<UIQuestEventListener*>(this) : 0);
    FUN_140aa6d40()->FUN_141b0cd00(this ? static_cast<UIStatusEventListener*>(this) : 0);
    m_1b0 = 0;
    return 1;
}

// @0x140bff7d0
void UIDailyMissionDialog::vfunc_67()
{
    FUN_140bfc4b0()->FUN_141aa8850(this ? static_cast<UIQuestEventListener*>(this) : 0);
    FUN_140aa6d40()->FUN_141b0cd90(this ? static_cast<UIStatusEventListener*>(this) : 0);
    for (size_t i = 0; i < m_188.GetCount(); i++)
        FUN_141415600(m_188[i]);
    m_188.RemoveAll();
    UIDialog::vfunc_67();
}

// @0x140bff8c0
void UIDailyMissionDialog::vfunc_72()
{
    if (vfunc_55() != 1 && DAT_143abdf50 != 0)
    {
        if (DAT_143abdf50 & 1)
            FUN_140c00500();
        if (DAT_143abdf50 & 2)
            FUN_140c001d0();
        if (DAT_143abdf50 & 4)
            FUN_140c00cd0();
        DAT_143abdf50 = 0;
    }
}

// @0x140bff950
void UIDailyMissionDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140c009b0();
    FUN_140c001d0();
    FUN_140c00500();
}

// @0x140bff990
int UIDailyMissionDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onReceiveItem") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140c00070(data.FUN_1422b8b10());
    }
    else if (_stricmp(szMethod, "onChangeIndex") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nIndex = data.FUN_1422b8a10();
            if (m_1b0 > -1 && m_1b0 < 6)
            {
                m_1b0 = nIndex;
                FUN_140c001d0();
            }
        }
    }
    return 0;
}

// @0x140c02f10
int UIDailyMissionDialog::vfunc_48() { return 0x4f53; }

// @0x140bffb20
void UIDailyMissionDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return;
    CStringW strType = pArgs->FUN_1422b8f40();
    int nId = pArgs->FUN_1422b8b10();
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nId);
    if (spData.IsNull())
        return;
    if (FUN_140841300(strType, "point") == 0)
    {
        ASTooltip tip(2);
        if (tip.FUN_1409e26b0(FUN_1409404f0(FUN_140761ba0(nId, 1))))
        {
            tip.FUN_1409c6dc0(1);
            *pRetVal = tip.FUN_1422bb870();
        }
    }
    else
    {
        ASTooltip tip(2);
        if (tip.FUN_1409e26b0(FUN_140763e10(spData->m_complete.m_missionPoint)))
        {
            tip.FUN_1409c6dc0(1);
            *pRetVal = tip.FUN_1422bb870();
        }
    }
}

// A daily mission quest changed: update its row and queue the point / count refresh.
// @0x140bffd70
void UIDailyMissionDialog::vfunc_o178_8(void* pQuestPtr)
{
    CQuest* pQuest = (CQuest*)pQuestPtr;
    if (FUN_141924630() != 0 && pQuest)
    {
        if (!pQuest->GetData().IsNull())
        {
            MS2Ptr<CQuestData> spData = pQuest->GetData();
            int nKind = spData->m_338.m_value;
            if (nKind > 2)
            {
                if (nKind < 5)
                {
                    DAT_143abdf50 |= 4;
                    if (spData->m_338.m_4 == m_1b0)
                        FUN_140c00c10(pQuest);
                }
                else if (nKind == 5)
                    DAT_143abdf50 |= 1;
            }
        }
    }
}

// "NotifyGameStart": open the window once in the lobby.
// @0x140bffee0
void UIDailyMissionDialog::FUN_140bffee0(NotifyObject* pNotify)
{
    if (!FUN_1403ed2d0()->FUN_141bcb0a0())
    {
        if (FUN_1422b9e00(FUN_1408e57f0()) == 0x620001d && FUN_140bffff0() && m_1a8 == 0)
        {
            FUN_1403ed2b0()->FUN_141adc530(0x4f53);
            m_1a8 = 1;
        }
    }
}

// "NotifyChangeMyPC": allow the auto open again.
// @0x140bfff70
void UIDailyMissionDialog::FUN_140bfff70(NotifyObject* pNotify)
{
    m_1a8 = 0;
}

// packet 0x10b: show the window.
// @0x140bfff90
void UIDailyMissionDialog::FUN_140bfff90(CInPacket& rPacket)
{
    if (!FUN_140930b40() && FUN_140bffff0() && vfunc_55())
        FUN_141924680();
}

// @0x140bffff0
bool UIDailyMissionDialog::FUN_140bffff0()
{
    if (!FUN_140166410()->FUN_14036d570(0x92))
        return false;
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return false;
    return Unk_DmActorLevel(pPlayer) != 0;
}

// Request the reward of a finished quest.
// @0x140c00070
void UIDailyMissionDialog::FUN_140c00070(int nQuestId)
{
    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuestId);
    if (!spQuest.IsNull())
    {
        if (spQuest->IsComplete() != 0)
        {
            if (!spQuest->GetData().IsNull())
            {
                COutPacket packet(0x29, 0);
                packet.vfunc_o10_1(0x18);
                packet.vfunc_o10_3(nQuestId);
                FUN_140710590(packet);
            }
        }
    }
}

// Fill the recommended list with the quests of the selected group.
// @0x140c001d0
void UIDailyMissionDialog::FUN_140c001d0()
{
    MS2Ptr<Unk_DmList> spList = FUN_140c02900("m_recommendList");
    if (spList.operator->() != 0)
    {
        spList->FUN_1422dd1d0();
        ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
        FUN_140764020()->FUN_1416cfc70(quests, 1, 0);
        FUN_140764020()->FUN_1416cfc70(quests, 2, 0);
        for (size_t i = 0; i < quests.GetCount(); i++)
        {
            Unk_PayloadPtr<CQuest> spQuest = quests[i];
            int nKind = spQuest->GetData()->m_338.m_value;
            if (nKind < 1 || (nKind > 2 && nKind != 5))
            {
                if (spQuest->GetData()->m_338.m_4 == m_1b0)
                {
                    ASObj row(2);
                    FUN_140c01040(row, spQuest.get());
                    spList->FUN_1422dd230(row);
                }
            }
        }
        spList->vfunc_24(true);
    }
}

// Fill the level guide bar and the mission point gauge.
// @0x140c00500
void UIDailyMissionDialog::FUN_140c00500()
{
    if (m_30.IsNull())
        return;
    MS2Ptr<Unk_DmGuideBar> spBar = FUN_140c02990("m_guideBar");
    if (spBar.operator->() != 0)
        spBar->Invoke("removeAll");
    ATL::CAtlArray<MS2Ptr<CQuestData>> datas;
    FUN_1407476c0()->FUN_14074cca0(datas, 5);
    for (size_t i = 0; i < datas.GetCount(); i++)
    {
        MS2Ptr<CQuestData> spData = datas[i];
        if (spData->m_conditions.GetCount() != 0)
        {
            ASObj row(2);
            if (FUN_140c012d0(row, FUN_14074b030(spData.operator->())) != 0)
                FUN_1409ee290(&m_30)->Invoke("addLevelGuide", row);
        }
    }
    if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0)
    {
        int nCur = FUN_140c01f50();
        int nMax = FUN_140c020d0();
        FUN_1409ee290(&m_30)->Invoke("setPC", nCur);
        MS2Ptr<ASMovieClip> spPoint = FUN_140ba7930("m_missionPoint");
        if (spPoint.operator->() != 0)
        {
            spPoint->vfunc_13(CString(spPoint == 0 ? "off" : "on"));
            MS2Ptr<ASTextField> spText = spPoint->FUN_1409b4620("textField");
            if (spText.operator->() != 0)
                spText->FUN_1422c4cd0(StringFormat(L"{0} / {1}", nCur, nMax));
        }
    }
}

// Fill the group tabs.
// @0x140c009b0
void UIDailyMissionDialog::FUN_140c009b0()
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0)
    {
        MS2Ptr<Unk_DmTabBar> spTab = FUN_140c02870("m_groupTab");
        if (spTab.operator->() != 0)
        {
            for (size_t i = 0; i < 6; i++)
            {
                CString strKey = FUN_14021a8b0((int)i);
                if ((int)i == 2 && Unk_DmActorLevel(pPlayer) < 0x32)
                    strKey = "newbee";
                ASObj row(2);
                row.FUN_1407cbb20("label", FUN_14028b8e0(StringFormat(L"s_daily_mission_{0}", strKey)));
                row.FUN_1407cb9c0("enabled", FUN_140c02320((int)i));
                spTab.operator->()->FUN_1422e3460(row);
            }
            spTab.operator->()->FUN_1422e31e0(0);
            spTab.operator->()->vfunc_24(true);
        }
        FUN_140c00cd0();
    }
}

// Update one quest row.
// @0x140c00c10
void UIDailyMissionDialog::FUN_140c00c10(CQuest* pQuest)
{
    if (m_30.IsNull())
        return;
    ASObj row(2);
    FUN_140c01040(row, pQuest);
    FUN_1409ee290(&m_30)->Invoke("updateQuest", row);
}

// Refresh the clear / satisfied counts and the point gauge.
// @0x140c00cd0
void UIDailyMissionDialog::FUN_140c00cd0()
{
    ASArray clear(2);
    for (size_t i = 0; i < 6; i++)
        clear.FUN_1422bbc60(FUN_140c01b50((int)i));
    FUN_1409ee290(&m_30)->FUN_140bd2cb0("refreshClearCount", clear);
    ASArray satisfied(2);
    for (size_t i = 0; i < 6; i++)
        satisfied.FUN_1422bbc60(FUN_140c01d30((int)i));
    FUN_1409ee290(&m_30)->FUN_140bd2cb0("refreshSatisfiedCount", satisfied);
    MS2Ptr<ASMovieClip> spPoint = FUN_140ba7930("m_missionPoint");
    if (spPoint.operator->() != 0)
    {
        spPoint->vfunc_13(CString(spPoint == 0 ? "off" : "on"));
        MS2Ptr<ASTextField> spText = spPoint->FUN_1409b4620("textField");
        if (spText.operator->() != 0)
        {
            int nMax = FUN_140c020d0();
            int nCur = FUN_140c01f50();
            spText->FUN_1422c4cd0(StringFormat(L"{0} / {1}", nCur, nMax));
        }
    }
}

// Fill the row of a quest.
// @0x140c01040
void UIDailyMissionDialog::FUN_140c01040(ASObj& rRow, CQuest* pQuest)
{
    if (pQuest != 0)
    {
        if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0)
        {
            CString strIcon = pQuest->GetData()->m_338.m_8;
            CStringW strDesc = FUN_1416e5350(pQuest->FUN_140bfc580(), 0);
            strDesc.Replace(L"#5c2b00", L"#000000");
            rRow.FUN_1409c0d20("id", pQuest->FUN_140bfc580());
            rRow.FUN_1407cba60("icon", strIcon);
            rRow.FUN_1407cbb20("desc", strDesc);
            rRow.FUN_1407cb9c0("satisfied", pQuest->IsComplete());
            rRow.FUN_1407cb9c0("completed", pQuest->IsRewarded());
            rRow.FUN_1409c1180("exp", FUN_140761ba0(pQuest->FUN_140bfc580(), 1));
            FUN_140c01790(rRow, pQuest->FUN_140bfc580(), 1);
        }
    }
}

// Fill the row of a level guide entry; 0 when the quest is not shown.
// @0x140c012d0
int UIDailyMissionDialog::FUN_140c012d0(ASObj& rRow, unsigned nQuestId)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.IsNull())
        return 0;
    if (m_30.IsNull())
        return 0;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 0;
    Unk_PayloadPtr<CQuest> spQuest = FUN_140764020()->vfunc_o10_3(nQuestId);
    if (spQuest.IsNull())
        return 0;
    if (spQuest->FUN_1407476d0() == 3)
        return 0;
    CString strState;
    if (spQuest.get() != 0 && spQuest->IsComplete() != 0)
        strState = "active";
    else if (spQuest.get() != 0 && spQuest->IsRewarded() != 0)
        strState = "inactive";
    else
        strState = "lock";
    if (spData->m_conditions.GetCount() == 0)
        return 0;
    int nLevel = (int)spData->m_conditions[0]->m_nGoal;
    CStringW strLevel;
    strLevel = FUN_14062b4f0(CStringW(L"s_daily_mission_mission_point"), nLevel);
    rRow.FUN_1409c0d20("id", FUN_14074b030(spData.operator->()));
    rRow.FUN_1407cba60("state", strState);
    rRow.FUN_1407cb9c0("level", nLevel);
    rRow.FUN_1407cbb20("levelStr", strLevel);
    FUN_140c01790(rRow, FUN_14074b030(spData.operator->()), 0);
    return 1;
}

// Bind the reward item to the row.
// @0x140c01790
void UIDailyMissionDialog::FUN_140c01790(ASObj& rRow, unsigned nQuestId, int bName)
{
    MS2Ptr<CQuestData> spData = FUN_14074bc40(nQuestId);
    if (spData.IsNull())
        return;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return;
    CQuestData::QuestRewardItem* pReward = 0;
    if (spData->m_338.m_value > 2 && spData->m_338.m_value < 6)
    {
        if (spData->m_complete.m_choiceRewards.GetCount() == 0)
            return;
        pReward = &spData->m_complete.m_choiceRewards[0];
    }
    if (pReward == 0)
        return;
    MS2Ptr<CItem> spItem(new CItem);
    if (spItem->FUN_14052b130(pReward->m_itemId, pReward->m_count, 0) == 0)
        return;
    spItem->FUN_140526c70(pReward->m_job);
    int nFlags = 0x415;
    CString strBind;
    size_t nSlot = m_188.GetCount() + 1;
    strBind.Format("%s.%d", (const char*)vfunc_1(), nSlot);
    FUN_141415450(strBind, spItem, 0, nFlags, 0x800);
    rRow.FUN_1407cba60("binding", strBind);
    if (bName != 0)
        rRow.FUN_1407cbb20("itemName", FUN_1401a9d70()->FUN_141811980(1, pReward->m_itemId));
    m_188.Add(strBind);
}

// The number of quests of the group.
// @0x140c01b50
int UIDailyMissionDialog::FUN_140c01b50(int nGroup)
{
    ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
    FUN_140764020()->FUN_1416cfc70(quests, 2, 0);
    int nCount = 0;
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        Unk_PayloadPtr<CQuest> spQuest = quests[i];
        if (!spQuest->GetData().IsNull())
        {
            if (spQuest->GetData()->m_338.m_4 == nGroup)
                nCount = nCount + 1;
        }
    }
    return nCount;
}

// The number of satisfied quests of the group.
// @0x140c01d30
int UIDailyMissionDialog::FUN_140c01d30(int nGroup)
{
    ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
    FUN_140764020()->FUN_1416cfc70(quests, 1, 0);
    int nCount = 0;
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        Unk_PayloadPtr<CQuest> spQuest = quests[i];
        if (!spQuest->GetData().IsNull())
        {
            if (spQuest->GetData()->m_338.m_4 == nGroup)
            {
                if (spQuest->IsComplete() != 0)
                    nCount = nCount + 1;
            }
        }
    }
    return nCount;
}

// The highest progress of the finished point quests.
// @0x140c01f50
int UIDailyMissionDialog::FUN_140c01f50()
{
    ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
    FUN_140764020()->FUN_1416cfc70(quests, 4, 0);
    int nBest = 0;
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        Unk_PayloadPtr<CQuest> spQuest = quests[i];
        MS2Ptr<CQuestData> spData = spQuest->GetData();
        if (!spData.IsNull())
        {
            if (spData->m_338.m_value == 5)
            {
                int nProgress = spQuest->GetProgress(0);
                if (nBest < nProgress)
                    nBest = nProgress;
            }
        }
    }
    return nBest;
}

// The largest mission point of the open quests.
// @0x140c020d0
int UIDailyMissionDialog::FUN_140c020d0()
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return 0;
    ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
    FUN_140764020()->FUN_1416cfc70(quests, 4, 5);
    int nBest = 0;
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        Unk_PayloadPtr<CQuest> spQuest = quests[i];
        if (spQuest->IsActive() != 0 || spQuest->IsRewarded() != 0)
        {
            MS2Ptr<CQuestData> spData = spQuest->GetData();
            if (!spData.IsNull())
            {
                if (spData->m_conditions.GetCount() == 1)
                {
                    if ((__int64)nBest < spData->m_conditions[0]->m_nGoal)
                        nBest = (int)spData->m_conditions[0]->m_nGoal;
                }
            }
        }
    }
    return nBest;
}

// The group has a quest that can be received.
// @0x140c02320
int UIDailyMissionDialog::FUN_140c02320(int nGroup)
{
    ATL::CAtlArray<Unk_PayloadPtr<CQuest>> quests;
    FUN_140764020()->FUN_1416cfc70(quests, 4, 0);
    for (size_t i = 0; i < quests.GetCount(); i++)
    {
        Unk_PayloadPtr<CQuest> spQuest = quests[i];
        if (!spQuest->GetData().IsNull())
        {
            MS2Ptr<CQuestData> spData = spQuest->GetData();
            if (!spData.IsNull())
            {
                if (spData->m_338.m_value == 4 || spData->m_338.m_value == 3)
                {
                    if (spData->m_338.m_4 == nGroup)
                    {
                        if (spQuest->IsActive() != 0)
                            return 1;
                        if (spQuest->IsRewarded() != 0)
                            return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// The group tab / list / guide bar child lookups (one COMDAT per wrapper class).
// @0x140c02870
MS2Ptr<Unk_DmTabBar> UIDailyMissionDialog::FUN_140c02870(const CString& strName)
{
    if (FUN_140ba28d0(&m_30, 0))
        return MS2Ptr<Unk_DmTabBar>(0);
    return FUN_1409ee290(&m_30)->FUN_140be23c0<Unk_DmTabBar>(strName);
}

// @0x140c02900
MS2Ptr<Unk_DmList> UIDailyMissionDialog::FUN_140c02900(const CString& strName)
{
    if (FUN_140ba28d0(&m_30, 0))
        return MS2Ptr<Unk_DmList>(0);
    return FUN_1409ee290(&m_30)->FUN_140bc7280<Unk_DmList>(strName);
}

// @0x140c02990
MS2Ptr<Unk_DmGuideBar> UIDailyMissionDialog::FUN_140c02990(const CString& strName)
{
    if (FUN_140ba28d0(&m_30, 0))
        return MS2Ptr<Unk_DmGuideBar>(0);
    return FUN_1409ee290(&m_30)->FUN_140accfb0<Unk_DmGuideBar>(strName);
}

// The default slot of the quest event listener (shared by every listener without an override).
// @0x140c02f20
void UIQuestEventListener::vfunc_o178_2(void*) {}
