// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIDungeonRoomDialog: the dungeon list window and its info
// panel (UIDungeonRoomInfo) with the mission rank, season rank reward and limit text sub panels.
// MS2-UNIT: client\ms2\uidungeonroomdialog.cpp
// MS2-RANGE: 0x1400ed270-0x1400ed3e0 .text$di
// MS2-RANGE: 0x1412a74a0-0x1412c2020 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uidungeonroomdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/header_statics_a.h"
#include "uidungeonroomdialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/astilelist.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asitemslot.h"
#include "ms2/placeholder/aslabel.h"
#include "ms2/placeholder/asscrollpanel.h"
#include "ms2/placeholder/asgaugecontrol.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/cmycharacter.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/commonfiles/dungeonmissiondata.h"
#include "ms2/commonfiles/dungeonmissiondatatable.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/dungeonrecordcli.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/placeholder/cpartymember.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/uiachievedialog.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#define MS2_ASCRIPT_INL_ASSERT(line, expression) \
    (void)((!!(expression)) || (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\ascript.inl", (unsigned)(line)), 0))

// ---- out-of-unit callees ----
CMyCharacter* FUN_140931510();                                                          // the local character state
CFeatureManager* FUN_140166410();                                                       // TSingleton<CFeatureManager>::GetInstance
DungeonRoomTable* FUN_14031c2a0();                                                      // TSingleton<DungeonRoomTable>::GetInstance
DungeonMissionDataTable* FUN_140b20590();                                               // TSingleton<DungeonMissionDataTable>::GetInstance
CPartyManager* FUN_1409670d0();                                                         // TSingleton<CPartyManager>::GetInstance
CStringTable* FUN_1401a9d70();                                                          // TSingleton<CStringTable>::GetInstance
class Unk_DrWorld { public: void* FUN_141bd0cc0(); };                                   // WorldService (worldservice.h): the local player
Unk_DrWorld* FUN_1403ed2d0();
void* FUN_140bd09d0(unsigned n);                                                        // a callback user value
CStringW FUN_14016a730(const char* sz, int nCodePage);                                  // widen
CStringW FUN_140e14bd0(MS2Ptr<DungeonRoom> spRoom, bool bShowLimit);                    // the room's list text
void FUN_140d011c0(MS2Ptr<ASLoader> spLoader, CStringW strUrl, bool bFlag);             // load an image into a loader
COutputStream& FUN_14070f9a0(COutputStream& out, int n);                               // encode an unsigned (commonstruct.cpp)
int FUN_1402178b0(int nGroupType);
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW strText);   // yes / no box
MS2Ptr<CMsgBoxData> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW strText);   // ok box with a callback
MS2Ptr<CMsgBoxData> FUN_140d73f20(CStringW strText, int nType);                         // a box to fill in
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);                                            // show a box
void FUN_140f73320(CMsgBoxData* box, bool b);                                          // set the box's bool flag (unit_140f6c680)
void FUN_140d73aa0(CStringW strText, int nA, int nB, CStringW strTitle);                // simple notice box
void FUN_1412751f0(const CStringW& strText, int nA, int nB);                            // system chat notice
void FUN_1412b9870(int nRoomId, int nCount);
bool FUN_140930b40();                                                                   // the local player is in a dungeon
// CUIService (uiservice.h) as this unit calls it.
class Unk_DrUIService
{
public:
    MS2Ptr<UIObject> FUN_141adcea0(int nId);                                            // the dialog of a ui id
    void FUN_141adc530(int nId);                                                        // open a dialog
};
Unk_DrUIService* FUN_1403ed2b0();                                            // the "clear count exceeded" notice (this unit)
class Unk_DrLog { public: void FUN_140177a80(int nLevel, int nCategory, const wchar_t* szFormat, const unsigned& arg); };
Unk_DrLog* FUN_140166440();                                                             // the common log
CStringW FUN_14028b8e0(const CStringW& strKey);                                         // localized string by key
CStringW FUN_140298ea0(CStringW strKey);                                                // localized string by key (by value)
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& arg);                   // StringFormat<CStringW>
CStringW FUN_140719d20(const wchar_t* szFormat, const short& arg);                      // StringFormat<short>
CStringW FUN_140719b50(short nScore);                                                   // a score as text
CStringA FUN_1402bb1c0(const char* szFormat, const int& arg);                           // StringFormat<int>
CStringW FUN_14183e930(const CStringW& str, int nColor);                                // color-tagged text
int FUN_14053feb0(int nItemId);                                                         // default rarity of an item
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
void FUN_140cff840(const Scaleform::GFx::Value& root, CString strName, int nValue);     // set a child's int member
void FUN_140d01420(const Scaleform::GFx::Value& root, CString strName, int nMovieId);    // set a child's mode
void FUN_140d00640(const Scaleform::GFx::Value& root, CString strName, int nId);        // set a child's state
void FUN_140d01340(const Scaleform::GFx::Value& target, unsigned nParam, int nMovieId);
void FUN_1422c63f0(Scaleform::GFx::Value& value, int nGroup);                           // unbind
bool FUN_140bc7c10(const Scaleform::GFx::Value& root, CString strName, int nCount, std::vector<MS2Ptr<ASMovieClip> >& out, int nStart);
bool FUN_140e1cc40(const Scaleform::GFx::Value& root, CString strName, int nCount, std::vector<MS2Ptr<ASButton> >& out, int nStart);

// ASUIComponent slots 16-24 (0x1422c7ec0..0x1422c80c0; every ASUIComponent-derived vftable has them, astriggerstate.cpp).
class Unk_ASComponentSlots : public ASUIComponent
{
public:
    virtual void vfunc_16();                                    // 16
    virtual void vfunc_17();                                    // 17
    virtual void vfunc_18();                                    // 18 0x1422c7f40
    virtual void vfunc_19();                                    // 19
    virtual void vfunc_20();                                    // 20
    virtual void vfunc_21();                                    // 21
    virtual void vfunc_22();                                    // 22
    virtual void vfunc_23();                                    // 23
    virtual void vfunc_24(bool bRefresh);                       // 24
};

// ---- the bind / create templates (ascript.inl; this unit instantiates them for its own wrapper types) ----
template<class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v)
{
    MS2Ptr<T> sp(new T(v, nMovieId));
    return sp;
}
template<class T> MS2Ptr<T> AScript::FUN_140e159f0(const CString& strName)
{
    Scaleform::GFx::Value v = FUN_1422baa20(strName);
    if (v.IsObject())
        return Unk_ASCreate<T>(m_nMovieId, v);
    return MS2Ptr<T>(0);
}
template<class T> MS2Ptr<T> AScript::FUN_140bc7340(const CString& strName, MS2Ptr<T>& outChild)
{
    MS2_ASCRIPT_INL_ASSERT(0xd5, outChild == NULL);
    outChild = FUN_140e159f0<T>(strName);
    return outChild;
}

// The container lookups (asdisplayobjectcontainer.h; the deep search is defined in unit_140cff310).
class Unk_Finder : public ASDisplayObjectContainer
{
public:
    MS2Ptr<ASTextField> FUN_140d02c80(const Scaleform::GFx::Value& root, const CString& strName);
    // @0x1412bc730 (text field): bind the child into outControl
    template <class T> MS2Ptr<T> FUN_1412bc730(const CString& strName, MS2Ptr<T>& outControl);
};

#define MS2_ASDOC_ASSERT(line, expression) \
    (void)((expression) || (_wassert(L"outControl", L"e:\\build\\kr\\22_04\\ms2code\\client\\gfxlib\\asdisplayobjectcontainer.h", (unsigned)(line)), 0))

template <class T> MS2Ptr<T> Unk_Finder::FUN_1412bc730(const CString& strName, MS2Ptr<T>& outControl)
{
    outControl = FUN_140d02c80(m_value, strName);
    MS2_ASDOC_ASSERT(0x5a, !outControl.IsNull());
    return outControl;
}

#define DR_SWF_ERROR(line) new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(line), __FUNCTION__))

// ======== UIDungeonRoomRankPanel ========

// @0x1412a74a0
UIDungeonRoomRankPanel::UIDungeonRoomRankPanel(MS2Ptr<ASMovieClip> spPanel)
    : m_spPanel(spPanel)
{
    do { m_spPanel->FUN_140bc71c0("m_missionRankIcon", m_missionRankIcon); if (m_missionRankIcon == 0) throw DR_SWF_ERROR(42); } while (0);
    do { m_spPanel->FUN_140bc71c0("m_summaryScore", m_summaryScore); if (m_summaryScore == 0) throw DR_SWF_ERROR(43); } while (0);
}

// @0x1412a78a0
void UIDungeonRoomRankPanel::Refresh(MS2Ptr<DungeonRoom> spRoom)
{
    if (!FUN_140166410()->FUN_14036d570(0x71))
        return;
    Reset();
    std::vector<unsigned> missions;
    spRoom->GetMissions(missions);
    if (missions.empty())
    {
        AddMissionLabels(1);
        SetLayout(1);
        m_missions[0]->vfunc_4(true);
        FUN_140cfee80((*m_missions[0]).FUN_1422bb890(), "titleText", FUN_14028b8e0(L"s_room_dungeon_empty_mission"));
        return;
    }
    AddMissionLabels(missions.size());
    SetLayout(missions.size());
    for (unsigned i = 0; i < m_missions.size(); i++)
    {
        if (i < missions.size())
        {
            m_missions[i]->vfunc_4(true);
            m_missions[i]->FUN_1422bffe0(0x88, i * 0x18 + 5);
            MS2Ptr<DungeonMissionData> spMission = FUN_140b20590()->GetMission(missions[i]);
            if (spMission == 0)
            {
                FUN_140166440()->FUN_140177a80(1, 0x13, L"UIDungeonRoomRankPanel Not Found DungeonMission:{0}", missions[i]);
                return;
            }
            FUN_140cfee80((*m_missions[i]).FUN_1422bb890(), "titleText", FUN_1401e8510(L"{0}", spMission->GetName()));
            FUN_140cfee80((*m_missions[i]).FUN_1422bb890(), "scoreText", FUN_140719d20(L"{0}", spMission->m_maxScore));
        }
        else
        {
            m_missions[i]->vfunc_4(false);
            m_missions[i]->FUN_1422bffe0(0x88, 5);
        }
    }
    short nHighScore = FUN_140931510()->FUN_140d9f2c0()->GetRoomScore60(spRoom->GetDungeonRoomID());
    if (nHighScore >= 0)
    {
        m_missionRankIcon->vfunc_15(GetRankName(spRoom->GetRank(nHighScore)));
        FUN_140cfee80((*m_summaryScore).FUN_1422bb890(), "highScore", FUN_140719b50(nHighScore));
    }
    short nSeasonScore = FUN_140931510()->FUN_140d9f2c0()->GetRoomScore68(spRoom->GetDungeonRoomID());
    if (nSeasonScore >= 0)
        FUN_140cfee80((*m_summaryScore).FUN_1422bb890(), "seasonScore", FUN_140719b50(nSeasonScore));
}
MS2_REPLACE_METHOD(0x1412A78A0, UIDungeonRoomRankPanel, Refresh, 2332, 0x87E2B82B);

// @0x1412a81d0
void UIDungeonRoomRankPanel::Reset()
{
    m_missionRankIcon->vfunc_15("rank_unknown");
    for (size_t i = 0; i < m_missions.size(); i++)
        m_missions[i]->vfunc_4(false);
    FUN_140cfee80((*m_summaryScore).FUN_1422bb890(), "highScore", L"0");
    FUN_140cfee80((*m_summaryScore).FUN_1422bb890(), "seasonScore", L"0");
}
MS2_REPLACE_METHOD(0x1412A81D0, UIDungeonRoomRankPanel, Reset, 520, 0xDDC5F7EB);

// @0x1412a83e0
void UIDungeonRoomRankPanel::AddMissionLabels(size_t nCount)
{
    if (m_missions.size() < nCount && m_spPanel != 0)
    {
        CString strLinkage("UIDungeonRoom_MissionLabel");
        for (size_t i = m_missions.size(); i < nCount; i++)
        {
            MS2Ptr<ASMovieClip> spLabel(new ASMovieClip(strLinkage, 2));
            m_spPanel->FUN_1422c6900((*spLabel).FUN_1422bb890());
            FUN_140cfee80((*spLabel).FUN_1422bb890(), "titleText", L"");
            FUN_140d01420((*spLabel).FUN_1422bb890(), "titleText", 2);
            FUN_140cfee80((*spLabel).FUN_1422bb890(), "scoreText", L"");
            m_missions.push_back(spLabel);
        }
    }
}
MS2_REPLACE_METHOD(0x1412A83E0, UIDungeonRoomRankPanel, AddMissionLabels, 902, 0x8CC3EDF3);

// @0x1412a8770
void UIDungeonRoomRankPanel::SetLayout(int nLines)
{
    if (m_summaryScore != 0)
        m_summaryScore->FUN_1422bffe0(0x88, nLines * 0x18 + 5);
}
MS2_REPLACE_METHOD(0x1412A8770, UIDungeonRoomRankPanel, SetLayout, 93, 0x9F469BB4);

// ======== UIDungeonRoomSeasonRankReward ========

// @0x1412a87e0
UIDungeonRoomSeasonRankReward::UIDungeonRoomSeasonRankReward(MS2Ptr<ASMovieClip> spPanel)
    : m_spPanel(spPanel)
{
    if (!FUN_140bc7c10((*m_spPanel).FUN_1422bb890(), "m_seasonRankReward", 5, m_seasonRankReward, 0))
        throw DR_SWF_ERROR(159);
    if (!FUN_140bc7c10((*m_spPanel).FUN_1422bb890(), "m_seasonRank", 5, m_seasonRank, 0))
        throw DR_SWF_ERROR(162);
    for (unsigned i = 0; i < m_seasonRankReward.size(); i++)
    {
        Scaleform::GFx::Value slot = m_seasonRankReward[i]->FUN_1422c6b00("m_slot");
        m_slots.push_back(MS2Ptr<ASItemSlot>(new ASItemSlot(slot, 2)));
    }
}

// @0x1412a8d30
UIDungeonRoomSeasonRankReward::~UIDungeonRoomSeasonRankReward()
{
    for (size_t i = 0; i < m_seasonRankReward.size(); i++)
        FUN_1422c63f0((*m_seasonRankReward[i]).FUN_1422bb890(), 2);
}

// @0x1412a8e20
void UIDungeonRoomSeasonRankReward::Refresh(MS2Ptr<DungeonRoom> spRoom)
{
    if (!FUN_140166410()->FUN_14036d570(0x71))
        return;
    if (spRoom->GetSeasonRankRewardID() == 0)
        return;
    MS2Ptr<DungeonRankRewardBase> spReward = FUN_14031c2a0()->GetRankReward(spRoom->GetSeasonRankRewardID());
    if (spReward == 0)
        return;
    if (m_seasonRankReward.empty() || m_seasonRank.empty())
        return;
    unsigned nMaxRank = spReward->GetMaxRank();
    if ((int)nMaxRank < 1)
        return;
    size_t nLast = (int)(nMaxRank - 1);
    size_t nSlots = 5;
    int nLeft = nMaxRank < 5 ? 0x21 : 0x13;
    int nStep = nMaxRank < 5 ? 0x72 : 0x5f;
    int nGap = 0xe;
    int nRewardY = (int)m_seasonRankReward[0]->FUN_1422c1110();
    int nRankY = (int)m_seasonRank[0]->FUN_1422c1110();
    int nCount = FUN_140931510()->FUN_140d9f2c0()->GetRankRewardCount(spRoom->GetSeasonRankRewardID());
    for (size_t i = 0; i < 5; i++)
    {
        if (i > nLast)
        {
            m_seasonRankReward[i]->vfunc_4(false);
            m_seasonRank[i]->vfunc_4(false);
            continue;
        }
        m_seasonRankReward[i]->vfunc_4(true);
        m_seasonRank[i]->vfunc_4(true);
        m_seasonRankReward[i]->FUN_1422c0060((int)(nLeft + nStep * i), nRewardY);
        m_seasonRank[i]->FUN_1422c0060((int)(nLeft + 0xe + nStep * i), nRankY);
        int nRank = (int)i + 1;
        unsigned nItemId = spReward->GetItemId(nRank);
        int nRarity = FUN_14053feb0(nItemId);
        bool bComplete = nRank <= nCount;
        m_slots[i]->FUN_1409ba5d0(nItemId, nRarity, 0);
        CString strState(bComplete ? "complete" : "normal");
        m_seasonRankReward[i]->vfunc_15(strState);
        CString strEnable = FUN_1402bb1c0("enable{0}", nRank);
        m_seasonRank[i]->vfunc_15(strEnable);
        FUN_140cff840((*m_seasonRank[i]).FUN_1422bb890(), "isComplete", bComplete);
    }
}
MS2_REPLACE_METHOD(0x1412A8E20, UIDungeonRoomSeasonRankReward, Refresh, 1720, 0x18F02251);

// ======== UIDungeonRoomLimitTextGroup ========

// @0x1412a94e0
UIDungeonRoomLimitTextGroup::UIDungeonRoomLimitTextGroup(MS2Ptr<ASMovieClip> spPanel)
    : m_spPanel(spPanel), m_x(0), m_y(0)
{
}

// @0x1412a9570
UIDungeonRoomLimitTextGroup::~UIDungeonRoomLimitTextGroup()
{
    Clear();
}

// @0x1412a95e0
void UIDungeonRoomLimitTextGroup::SetPosition(int x, int y)
{
    m_x = x;
    m_y = y;
}
MS2_REPLACE_METHOD(0x1412A95E0, UIDungeonRoomLimitTextGroup, SetPosition, 39, 0xCFCBD77D);

// @0x1412a9610
int UIDungeonRoomLimitTextGroup::GetBottom()
{
    return m_y;
}
MS2_REPLACE_METHOD(0x1412A9610, UIDungeonRoomLimitTextGroup, GetBottom, 14, 0x7A15C443);

// @0x1412a9630
void UIDungeonRoomLimitTextGroup::AddText(const CStringW& strText, int nColor, const CStringW& strTooltip)
{
    MS2Ptr<ASLabel> spLabel(new ASLabel("UIDungeonRoomLimitLabel", 2));
    spLabel->FUN_1422e4c60("none");
    m_labels.push_back(spLabel);
    m_spPanel->FUN_1422c6900((*spLabel).FUN_1422bb890());
    spLabel->FUN_1422e4b80(FUN_14183e930(strText, nColor));
    spLabel->FUN_1422bffe0(m_x, m_y);
    if (!strTooltip.IsEmpty())
        spLabel->FUN_1422c7b40(strTooltip);
    m_y += spLabel->FUN_1422c13b0();
}
MS2_REPLACE_METHOD(0x1412A9630, UIDungeonRoomLimitTextGroup, AddText, 651, 0x109A083B);

// @0x1412a98d0
void UIDungeonRoomLimitTextGroup::Clear()
{
    std::vector<MS2Ptr<ASLabel> >& labels = m_labels;
    std::vector<MS2Ptr<ASLabel> >::const_iterator end = labels.end();
    for (std::vector<MS2Ptr<ASLabel> >::const_iterator it = labels.begin(); it != end; ++it)
    {
        MS2Ptr<ASLabel> spLabel = *it;
        spLabel->FUN_1422c6eb0();
    }
    m_labels.clear();
}
MS2_REPLACE_METHOD(0x1412A98D0, UIDungeonRoomLimitTextGroup, Clear, 189, 0x141DEC1D);

// ======== UIDungeonRoomInfo ========

// @0x1412a99a0
UIDungeonRoomInfo::UIDungeonRoomInfo(UIDungeonRoomDialog* pOwner, MS2Ptr<ASMovieClip> spPanel)
    : m_pOwner(pOwner), m_spPanel(spPanel), m_slotBinder("DungeonRoomDialog")
{
    FUN_140d432d0(&m_slotBinder, 0x403);
    FUN_140d00640((*m_spPanel).FUN_1422bb890(), "m_partyMembers", 2);
    FUN_140d00640((*m_spPanel).FUN_1422bb890(), "m_cooldownIcon", 2);
    FUN_140d00640((*m_spPanel).FUN_1422bb890(), "m_requireCondition", 2);
    do { m_spPanel->FUN_140bbe640("m_enterSoloButton", m_enterSoloButton); if (m_enterSoloButton == 0) throw DR_SWF_ERROR(303); } while (0);
    do { m_spPanel->FUN_140bbe640("m_enterPartyButton", m_enterPartyButton); if (m_enterPartyButton == 0) throw DR_SWF_ERROR(304); } while (0);
    do { m_spPanel->FUN_140bbe640("m_partySearchButton", m_partySearchButton); if (m_partySearchButton == 0) throw DR_SWF_ERROR(305); } while (0);
    do { m_spPanel->FUN_140bbe640("m_resetButton", m_resetButton); if (m_resetButton == 0) throw DR_SWF_ERROR(306); } while (0);
    do { m_spPanel->FUN_140bbe640("m_addExtraRewardCount", m_addExtraRewardCount); if (m_addExtraRewardCount == 0) throw DR_SWF_ERROR(307); } while (0);
    do { m_spPanel->FUN_141009c70("m_rewardIcon1", m_rewardIcon1); if (m_rewardIcon1 == 0) throw DR_SWF_ERROR(308); } while (0);
    do { m_spPanel->FUN_141009c70("m_rewardIcon2", m_rewardIcon2); if (m_rewardIcon2 == 0) throw DR_SWF_ERROR(309); } while (0);
    do { m_spPanel->FUN_140bc71c0("m_dungeonBanner", m_dungeonBanner); if (m_dungeonBanner == 0) throw DR_SWF_ERROR(310); } while (0);
    do { m_spPanel->FUN_140bc7340("m_dungeonScrollInfo", m_dungeonScrollInfo); if (m_dungeonScrollInfo == 0) throw DR_SWF_ERROR(311); } while (0);
    do { m_spPanel->FUN_140beaf20("m_enterStatusText", m_enterStatusText); if (m_enterStatusText == 0) throw DR_SWF_ERROR(312); } while (0);
    do { m_spPanel->FUN_140bbe640("m_findHelperButton", m_findHelperButton); if (m_findHelperButton == 0) throw DR_SWF_ERROR(313); } while (0);
    do { m_spPanel->FUN_140bbe640("m_findMemberButton", m_findMemberButton); if (m_findMemberButton == 0) throw DR_SWF_ERROR(314); } while (0);
    do { m_spPanel->FUN_140bbe640("m_changeExpertButton", m_changeExpertButton); if (m_changeExpertButton == 0) throw DR_SWF_ERROR(315); } while (0);
    do { m_spPanel->FUN_140bc71c0("m_clearCount", m_clearCount); if (m_clearCount == 0) throw DR_SWF_ERROR(316); } while (0);
    do { m_spPanel->FUN_140bc71c0("m_helpCoinInfo", m_helpCoinInfo); if (m_helpCoinInfo == 0) throw DR_SWF_ERROR(317); } while (0);
    do { m_spPanel->FUN_140bc71c0("m_dungeonHelpEvent", m_dungeonHelpEvent); if (m_dungeonHelpEvent == 0) throw DR_SWF_ERROR(318); } while (0);
    do { m_spPanel->FUN_140bc71c0("m_dungeonSearching", m_dungeonSearching); if (m_dungeonSearching == 0) throw DR_SWF_ERROR(319); } while (0);
    do { m_spPanel->FUN_140bbe640("m_favoriteMark", m_favoriteMark); if (m_favoriteMark == 0) throw DR_SWF_ERROR(320); } while (0);
    FUN_140bc7c10((*m_spPanel).FUN_1422bb890(), "m_partyMember", 10, m_partyMembers, 0);
    FUN_140d01420((*m_spPanel).FUN_1422bb890(), "m_rewardText1", 2);
    FUN_140d01420((*m_spPanel).FUN_1422bb890(), "m_rewardText2", 2);
    m_addExtraRewardCount->FUN_1422ce1f0(2);
    static_cast<Unk_ASComponentSlots*>((ASUIComponent*)m_addExtraRewardCount.operator->())->vfunc_18();
    m_dungeonHelpEvent->vfunc_4(false);
    {
        MS2Ptr<ASMovieClip> spContents;
        if (m_dungeonScrollInfo->FUN_140bc71c0("m_contents", spContents) == 0)
            throw DR_SWF_ERROR(334);
        if (!FUN_140e1cc40((*spContents).FUN_1422bb890(), "m_subTabButton", 5, m_subTabButtons, 0))
            throw DR_SWF_ERROR(337);
        if (!FUN_140bc7c10((*spContents).FUN_1422bb890(), "m_subPanel", 5, m_subPanels, 0))
            throw DR_SWF_ERROR(340);
        do { m_subPanels[0]->FUN_140beaf20("m_dungeonDesc", m_dungeonDesc); if (m_dungeonDesc == 0) throw DR_SWF_ERROR(342); } while (0);
        do { m_subPanels[1]->FUN_140beaf20("m_limitText", m_limitText); if (m_limitText == 0) throw DR_SWF_ERROR(343); } while (0);
        do { m_subPanels[1]->FUN_140bc71c0("m_requireCondition", m_requireCondition); if (m_requireCondition == 0) throw DR_SWF_ERROR(344); } while (0);
        FUN_140bc7c10((*m_subPanels[2]).FUN_1422bb890(), "m_rewardItem", 0x1c, m_rewardItems, 0);
        m_spRankPanel = new UIDungeonRoomRankPanel(m_subPanels[3]);
        m_spSeasonRankReward = new UIDungeonRoomSeasonRankReward(m_subPanels[4]);
        m_spLimitTextGroup = new UIDungeonRoomLimitTextGroup(m_subPanels[1]);
    }
    if (MS2Ptr<ASTextField> spText = m_requireCondition->FUN_1409b4620("textField"))
        FUN_140d01340((*spText).FUN_1422bb890(), 2, 2);
    for (unsigned i = 0; i < m_subTabButtons.size(); i++)
        m_subTabButtons[i]->FUN_1422ce240(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnSubTab), FUN_140bd09d0(i));
    m_subTabButtons[3]->FUN_1422c7d30(300, 0);
    m_enterSoloButton->FUN_1422ce240(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnEnterSolo), 0);
    m_enterPartyButton->FUN_1422ce240(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnEnterParty), 0);
    m_partySearchButton->FUN_1422ce240(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnPartySearch), 0);
    m_addExtraRewardCount->FUN_1422ce240(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnAddExtraRewardCount), 0);
    m_changeExpertButton->FUN_1422c2a70(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnChangeExpert), 0);
    m_findHelperButton->FUN_1422ce240(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnFindHelper), 0);
    m_findHelperButton->FUN_1422cdfb0(FUN_140298ea0(L"s_dungeonRoom_find_helper_button"));
    m_findMemberButton->FUN_1422ce240(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnFindMember), 0);
    m_requireCondition->FUN_1422c2a70(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnRequireCondition), 0);
    m_resetButton->FUN_1422ce240(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnReset), 0);
    m_favoriteMark->FUN_1422ce240(Delegate<void(const ASParams&)>(this, &UIDungeonRoomInfo::OnFavoriteMark), 0);
    m_spBannerLoader = new ASLoader(2);
    m_dungeonBanner->FUN_1422c6900((*m_spBannerLoader).FUN_1422bb890());
}

// @0x1412ad760
UIDungeonRoomInfo::~UIDungeonRoomInfo()
{
    if (m_dungeonBanner)
    {
        if (m_spBannerLoader.get() != 0)
            m_dungeonBanner->FUN_1422c6b70((*m_spBannerLoader).FUN_1422bb890());
    }
}

// @0x1412bcec0
template <class T> T* Unk_DrGetDialog(int nId)
{
    if (FUN_1403ed2b0())
    {
        MS2Ptr<UIObject> p = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (p.get())
            return dynamic_cast<T*>((UIObject*)p);
    }
    return 0;
}

// @0x1412adb40
void UIDungeonRoomInfo::Refresh()
{
    FUN_140d011c0(m_spBannerLoader, FUN_14016a730(m_spRoom->m_dungeonBanner, 0), true);
    FUN_140cfee80((*m_spPanel).FUN_1422bb890(), "m_title", FUN_140e14bd0(m_spRoom, false));
    m_dungeonDesc->FUN_1422c4f00(FUN_1401a9d70()->FUN_141811980(0x15, m_spRoom->GetDungeonRoomID()));
    m_dungeonDesc->FUN_1422c0ec0((int)m_dungeonDesc->FUN_1422c59e0() + 0x14);
    FUN_140cff840((*m_spPanel).FUN_1422bb890(), "m_cooldownIcon", IsCooldown());
    m_favoriteMark->FUN_1422ce090(FUN_140931510()->FUN_140d9f2c0()->IsSeasonRoom(m_spRoom->GetDungeonRoomID()));
    RefreshSubTabVisibility();
    RefreshLimits();
    FUN_1412b0110();
    RefreshEnterButtons();
    RefreshReward();
    FUN_1412b2250();
    FUN_1412b2e70();
    RefreshResetButton();
    RefreshHelper();
    m_spSeasonRankReward->Refresh(m_spRoom);
    LayoutSubPanels();
}
MS2_REPLACE_METHOD(0x1412ADB40, UIDungeonRoomInfo, Refresh, 1134, 0x415FF5E5);

// @0x1412adfc0
void UIDungeonRoomInfo::RefreshSubTabVisibility()
{
    if (FUN_140166410()->FUN_14036d570(0x71) && m_spRoom->HasMissions())
    {
        m_subPanels[3]->vfunc_4(true);
        m_subTabButtons[3]->vfunc_4(true);
    }
    else
    {
        m_subPanels[3]->vfunc_4(false);
        m_subTabButtons[3]->vfunc_4(false);
    }
    if (m_spRoom->GetSeasonRankRewardID() == 0)
    {
        m_subPanels[4]->vfunc_4(false);
        m_subTabButtons[4]->vfunc_4(false);
    }
    else
    {
        m_subPanels[4]->vfunc_4(true);
        m_subTabButtons[4]->vfunc_4(true);
        m_subTabButtons[4]->FUN_1422c7b40(FUN_140298ea0(L"s_dungeonRoom_seasonRankBar_tooltip"));
    }
}
MS2_REPLACE_METHOD(0x1412ADFC0, UIDungeonRoomInfo, RefreshSubTabVisibility, 733, 0x403F334A);

// @0x1412b0d30
void UIDungeonRoomInfo::RefreshReward()
{
    if (m_spRoom == 0)
        return;
    if (m_spRoom->HasRoundGroup())
        RefreshRoundReward();
    else
        RefreshNormalReward();
}
MS2_REPLACE_METHOD(0x1412B0D30, UIDungeonRoomInfo, RefreshReward, 100, 0xA1D75F60);

// @0x1412b3120
void UIDungeonRoomInfo::RefreshEnterButtons()
{
    if (m_spRoom == 0)
        return;
    if (FUN_1409670d0()->FUN_14162ab20())
        FUN_1412b3430();
    else
        FUN_1412b3180();
}
MS2_REPLACE_METHOD(0x1412B3120, UIDungeonRoomInfo, RefreshEnterButtons, 86, 0x7B9AA351);

// @0x1412b3720
void UIDungeonRoomInfo::RefreshResetButton()
{
    if (m_spRoom == 0)
        return;
    m_resetButton->vfunc_3(0);
    if (FUN_140930b40())
        return;
    if (FUN_1409670d0()->FUN_14162ab20() && m_spRoom->m_maxUserCount > 1 && FUN_1409670d0()->FUN_14162abe0()
        && FUN_1409670d0()->FUN_14162c090() == m_spRoom->GetDungeonRoomID() && FUN_1409670d0()->FUN_14162ab60())
        m_resetButton->vfunc_3(1);
}
MS2_REPLACE_METHOD(0x1412B3720, UIDungeonRoomInfo, RefreshResetButton, 293, 0x9D2A6F74);

// @0x1412b3850
void UIDungeonRoomInfo::RefreshHelper()
{
    FUN_1412b3890();
    FUN_1412b3b40();
    FUN_1412b3fe0();
}
MS2_REPLACE_METHOD(0x1412B3850, UIDungeonRoomInfo, RefreshHelper, 44, 0x0F775C7C);

// @0x1412b41a0
void UIDungeonRoomInfo::OnEnterSolo(const ASParams& params)
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() != 0 && !(m_spRoom == 0) && !AskExtraTicketEnter(false))
        RequestEntry(false, false);
}
MS2_REPLACE_METHOD(0x1412B41A0, UIDungeonRoomInfo, OnEnterSolo, 113, 0x819F8DAA);

// @0x1412b4220
void UIDungeonRoomInfo::OnEnterParty(const ASParams& params)
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0 || m_spRoom == 0)
        return;
    if (FUN_1409670d0()->FUN_14162abe0() && m_spRoom->GetDungeonRoomID() == FUN_1409670d0()->FUN_14162c090())
    {
        FUN_1409670d0()->FUN_14162bd40(m_spRoom->GetDungeonID());
        return;
    }
    if (FUN_1409670d0()->FUN_14162ab60() && !AskExtraTicketEnter(true))
        RequestEntry(true, false);
}
MS2_REPLACE_METHOD(0x1412B4220, UIDungeonRoomInfo, OnEnterParty, 265, 0x8187852C);

// @0x1412b4330
void UIDungeonRoomInfo::OnPartySearch(const ASParams& params)
{
    if (m_spRoom == 0 || m_partySearchButton == 0)
        return;
    if (!m_partySearchButton->FUN_1422ce0e0())
    {
        COutPacket packet(0x2c);
        packet.Encode1(0x21);
        FUN_14070f9a0(packet, m_spRoom->GetDungeonRoomID());
        FUN_140710590(packet);
    }
    else
    {
        COutPacket packet(0x2c);
        packet.Encode1(0x22);
        packet.Encode1(FUN_1402178b0(m_spRoom->m_groupType));
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x1412B4330, UIDungeonRoomInfo, OnPartySearch, 330, 0x0DB95DF9);

// @0x1412b4480
void UIDungeonRoomInfo::OnAddExtraRewardCount(const ASParams& params)
{
    if (m_spRoom == 0)
        return;
    MS2Ptr<DungeonRoom> spRewardRoom = FUN_14031c2a0()->GetRewardRoom(m_spRoom->GetDungeonRoomID());
    if (spRewardRoom == 0)
        return;
    if (!spRewardRoom->HasExtraRewardTicket())
    {
        FUN_140d73aa0(FUN_14028b8e0(L"s_room_dungeon_reward_CantUseExtraReward"), 0, 0, L"");
        return;
    }
    MS2Ptr<CItem> spItem;
    unsigned nCost = FUN_140931510()->FUN_140d9f2c0()->GetExtraTicketCost(spRewardRoom);
    if (nCost == 0)
        return;
    CStringW strItem = FUN_1401a9d70()->FUN_141811980(1, spRewardRoom->GetCouponBaseItemID());
    CStringW strRoom = FUN_1401a9d70()->FUN_141811980(0x14, spRewardRoom->GetDungeonRoomID());
    CStringW strMsg = FUN_14028dfa0(CStringW(L"s_dungeonRoom_use_extra_count_item"), strItem, nCost, strRoom);
    if (spRewardRoom->GetCooldownType() == 1)
        strMsg = FUN_14028dfa0(CStringW(L"s_dungeonRoom_use_extra_count_item_week"), strItem, nCost, strRoom);
    MS2Ptr<CMsgBoxData> box = FUN_140d73f20(strMsg, 1);
    if (box)
    {
        box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIDungeonRoomInfo::OnUseExtraRewardItem));
        box->FUN_141a01800(1);
        box->FUN_140534050(spRewardRoom->GetDungeonRoomID());
        FUN_140d73c60(box);
    }
}
MS2_REPLACE_METHOD(0x1412B4480, UIDungeonRoomInfo, OnAddExtraRewardCount, 1354, 0x745AEE53);

// @0x1412b49d0
void UIDungeonRoomInfo::OnChangeExpert(const ASParams& params)
{
    if (m_spRoom == 0)
        return;
    CStringW strMsg = FUN_140298ea0(L"s_dungeonRoom_change_expert_message");
    MS2Ptr<CMsgBoxData> box = FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &UIDungeonRoomInfo::OnChangeExpertConfirm), strMsg);
    if (box)
        box->FUN_140534050(m_spRoom->GetDungeonRoomID());
}
MS2_REPLACE_METHOD(0x1412B49D0, UIDungeonRoomInfo, OnChangeExpert, 349, 0x41F82966);

// @0x1412b4b40
void UIDungeonRoomInfo::OnSubTab(const ASParams& params)
{
    size_t nTab = (size_t)params.pUserData;
    if (nTab < m_subTabButtons.size())
    {
        bool bSelected = m_subTabButtons[nTab]->FUN_1422ce0e0();
        m_subTabButtons[nTab]->FUN_1422ce090(!bSelected);
        LayoutSubPanels();
    }
}
MS2_REPLACE_METHOD(0x1412B4B40, UIDungeonRoomInfo, OnSubTab, 180, 0xEDC7DF57);

// @0x1412b4c00
void UIDungeonRoomInfo::OnFindHelper(const ASParams& params)
{
    if (m_spRoom == 0 || !CanAskHelp())
        return;
    int nPartyRoom = FUN_1409670d0()->FUN_14162c090();
    if (FUN_1409670d0()->FUN_14162ab20() && nPartyRoom != 0 && m_spRoom->GetDungeonRoomID() != nPartyRoom)
    {
        CStringW strMsg = FUN_14028dfa0(CStringW(L"s_dungeonRoom_change_help_dungeon"),
            FUN_1401a9d70()->FUN_141811980(0x14, m_spRoom->GetDungeonRoomID()), FUN_1401a9d70()->FUN_141811980(0x14, nPartyRoom));
        MS2Ptr<CMsgBoxData> box = FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &UIDungeonRoomInfo::OnChangeHelpDungeon), strMsg);
        if (box)
            box->FUN_140534050(m_spRoom->GetDungeonRoomID());
        return;
    }
    RequestFindHelper(m_spRoom->GetDungeonRoomID());
}
MS2_REPLACE_METHOD(0x1412B4C00, UIDungeonRoomInfo, OnFindHelper, 718, 0x2EBC70DB);

// @0x1412b4ee0
void UIDungeonRoomInfo::OnFindMember(const ASParams& params)
{
    if (m_spRoom == 0 || !CanAskHelp())
        return;
    int nPartyRoom = FUN_1409670d0()->FUN_14162c090();
    if (FUN_1409670d0()->FUN_14162ab20() && nPartyRoom != 0 && m_spRoom->GetDungeonRoomID() != nPartyRoom)
    {
        CStringW strMsg = FUN_14028dfa0(CStringW(L"s_dungeonRoom_change_help_dungeon"),
            FUN_1401a9d70()->FUN_141811980(0x14, m_spRoom->GetDungeonRoomID()), FUN_1401a9d70()->FUN_141811980(0x14, nPartyRoom));
        MS2Ptr<CMsgBoxData> box = FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &UIDungeonRoomInfo::OnChangeMemberDungeon), strMsg);
        if (box)
            box->FUN_140534050(m_spRoom->GetDungeonRoomID());
        return;
    }
    RequestFindMember(m_spRoom->GetDungeonRoomID());
}
MS2_REPLACE_METHOD(0x1412B4EE0, UIDungeonRoomInfo, OnFindMember, 718, 0x84E13C9C);

// @0x1412b51c0
void UIDungeonRoomInfo::OnRequireCondition(const ASParams& params)
{
    if (m_spRoom == 0)
        return;
    if (m_spRoom->m_limitAchieveID == 0)
    {
        if (m_spRoom->m_limitVIP)
            FUN_1403ed2b0()->FUN_141adc530(0x4f1b);
    }
    else
    {
        if (UIAchieveDialog* pDialog = Unk_DrGetDialog<UIAchieveDialog>(0x4e73))
            pDialog->FUN_1418aa9b0(m_spRoom->m_limitAchieveID);
    }
}
MS2_REPLACE_METHOD(0x1412B51C0, UIDungeonRoomInfo, OnRequireCondition, 188, 0xDB6CE811);

// @0x1412b5290
void UIDungeonRoomInfo::OnReset(const ASParams& params)
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return;
    if (m_spRoom == 0)
        return;
    if (!FUN_1409670d0()->FUN_14162ab60())
        return;
    if (AskExtraTicketEnter(true))
        return;
    RequestEntry(true, false);
}
MS2_REPLACE_METHOD(0x1412B5290, UIDungeonRoomInfo, OnReset, 135, 0x0D56CD86);

// @0x1412b5320
void UIDungeonRoomInfo::OnFavoriteMark(const ASParams& params)
{
    if (m_spRoom == 0 || m_favoriteMark == 0)
        return;
    COutPacket packet(0x2b);
    packet.Encode1(0x18);
    packet.Encode4(m_spRoom->GetDungeonRoomID());
    packet.COutPacket::vfunc_o10_0(m_favoriteMark->FUN_1422ce0e0());
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1412B5320, UIDungeonRoomInfo, OnFavoriteMark, 225, 0x27A70454);

// @0x1412b5410
bool UIDungeonRoomInfo::OnUseExtraRewardItem(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        COutPacket packet(0x2b);
        packet.Encode1(8);
        packet.Encode4(box.FUN_141a02e90(0, 0));
        FUN_140710590(packet);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1412B5410, UIDungeonRoomInfo, OnUseExtraRewardItem, 123, 0x088A2D9F);

// @0x1412b54a0
bool UIDungeonRoomInfo::OnUseExtraTicketEnter(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        RequestEntry(box.FUN_141a02e10(0, false), true);
    return true;
}
MS2_REPLACE_METHOD(0x1412B54A0, UIDungeonRoomInfo, OnUseExtraTicketEnter, 63, 0x093E855F);

// @0x1412b54f0
bool UIDungeonRoomInfo::OnChangeHelpDungeon(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        RequestFindHelper(box.FUN_141a02e90(0, 0));
    return true;
}
MS2_REPLACE_METHOD(0x1412B54F0, UIDungeonRoomInfo, OnChangeHelpDungeon, 59, 0x5971FAFA);

// @0x1412b5540
bool UIDungeonRoomInfo::OnChangeMemberDungeon(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        RequestFindMember(box.FUN_141a02e90(0, 0));
    return true;
}
MS2_REPLACE_METHOD(0x1412B5540, UIDungeonRoomInfo, OnChangeMemberDungeon, 59, 0xD0537A83);

// @0x1412b5590
bool UIDungeonRoomInfo::OnLeaveDungeonForHelp(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        RequestLeaveDungeon();
    return true;
}
MS2_REPLACE_METHOD(0x1412B5590, UIDungeonRoomInfo, OnLeaveDungeonForHelp, 42, 0x54DE79B5);

// @0x1412b55c0
bool UIDungeonRoomInfo::OnChangeExpertConfirm(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        RequestChangeExpert(box.FUN_141a02e90(0, 0));
    return true;
}
MS2_REPLACE_METHOD(0x1412B55C0, UIDungeonRoomInfo, OnChangeExpertConfirm, 59, 0x59874E33);

// @0x1412b5610
void UIDungeonRoomInfo::RequestFindHelper(unsigned nRoomId)
{
    COutPacket packet(0x2b);
    packet.Encode1(0xf);
    packet.Encode4(nRoomId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1412B5610, UIDungeonRoomInfo, RequestFindHelper, 93, 0xA787B433);

// @0x1412b5680
void UIDungeonRoomInfo::RequestFindMember(unsigned nRoomId)
{
    COutPacket packet(0x2b);
    packet.Encode1(0x10);
    packet.Encode4(nRoomId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1412B5680, UIDungeonRoomInfo, RequestFindMember, 93, 0x6272AFDF);

// @0x1412b56f0
void UIDungeonRoomInfo::RequestChangeExpert(unsigned nRoomId)
{
    COutPacket packet(0x2b);
    packet.Encode1(0x11);
    packet.Encode4(nRoomId);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1412B56F0, UIDungeonRoomInfo, RequestChangeExpert, 93, 0x115374B2);

// @0x1412b5760
void UIDungeonRoomInfo::RequestLeaveDungeon()
{
    COutPacket packet(0x2b);
    packet.Encode1(1);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1412B5760, UIDungeonRoomInfo, RequestLeaveDungeon, 75, 0x6B5017CF);

// @0x1412b57c0
void UIDungeonRoomInfo::LayoutSubPanels()
{
    int y = 0;
    for (size_t i = 0; i < 5; i++)
    {
        m_subTabButtons[i]->FUN_1422c0060(0, y);
        y += 0x22;
        if (!m_subTabButtons[i]->FUN_1422bfca0())
            continue;
        if (!m_subTabButtons[i]->FUN_1422ce0e0())
        {
            m_subPanels[i]->vfunc_3(1);
            m_subPanels[i]->FUN_1422c0060(0, y);
            y += m_subPanels[i]->FUN_1422c13b0();
        }
        else
        {
            m_subPanels[i]->vfunc_3(0);
        }
    }
    m_dungeonScrollInfo->FUN_1409c1ba0(y);
}
MS2_REPLACE_METHOD(0x1412B57C0, UIDungeonRoomInfo, LayoutSubPanels, 469, 0xBB377534);

// @0x1412b59a0
void UIDungeonRoomInfo::LayoutSearching()
{
    if (m_dungeonSearching == 0)
        return;
    MS2Ptr<ASMovieClip> spIcon;
    MS2Ptr<ASMovieClip> spText;
    MS2Ptr<ASTextField> spField;
    m_dungeonSearching->FUN_140bc71c0("searchIcon", spIcon);
    m_dungeonSearching->FUN_140bc71c0("textArea", spText);
    if (spIcon == 0 || spText == 0)
        return;
    if (static_cast<Unk_Finder*>((ASDisplayObjectContainer*)spText.operator->())->FUN_1412bc730("textField", spField) == 0)
        return;
    double dWidth = spField->FUN_1422c5970();
    spIcon->FUN_1422bffe0(spText->FUN_1422c1340() / 2 - (int)(dWidth / 2.0) - 0x30, 8);
}
MS2_REPLACE_METHOD(0x1412B59A0, UIDungeonRoomInfo, LayoutSearching, 652, 0xED16F777);

// @0x1412b5c40
bool UIDungeonRoomInfo::CanAskHelp()
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return false;
    if (FUN_1409670d0()->FUN_14162ab20())
    {
        if (!FUN_1409670d0()->FUN_14162ab60())
        {
            FUN_1412751f0(FUN_140298ea0(L"s_party_err_not_chief"), 1, 1);
            return false;
        }
        if (FUN_1409670d0()->FUN_14162af00() >= (int)m_spRoom->m_maxUserCount)
        {
            FUN_1412751f0(FUN_140298ea0(L"s_dungeonRoom_cant_ask_help_full_members"), 1, 1);
            return false;
        }
        if (FUN_1409670d0()->FUN_14162abe0())
        {
            FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)>(this, &UIDungeonRoomInfo::OnLeaveDungeonForHelp), L"s_dungeonRoom_cant_ask_help_has_dungeon");
            return false;
        }
    }
    int nCount = GetClearCount();
    if (nCount >= 10)
        FUN_1412b9870(m_spRoom->GetDungeonRoomID(), nCount);
    return nCount < 10;
}
MS2_REPLACE_METHOD(0x1412B5C40, UIDungeonRoomInfo, CanAskHelp, 656, 0x74CC40D5);

// @0x1412b5ee0
bool UIDungeonRoomInfo::AskExtraTicketEnter(bool bParty)
{
    if (m_spRoom == 0)
        return false;
    if (m_spRoom->m_extraRewardTicketTableID == 0)
        return false;
    if (!IsCooldown())
        return false;
    unsigned nCost = FUN_140931510()->FUN_140d9f2c0()->GetExtraTicketCost(m_spRoom);
    CStringW strItem = FUN_1401a9d70()->FUN_141811980(1, m_spRoom->GetCouponBaseItemID());
    CStringW strRoom = FUN_1401a9d70()->FUN_141811980(0x14, m_spRoom->GetDungeonRoomID());
    CStringW strMsg = FUN_14028dfa0(CStringW(L"s_dungeonRoom_use_extra_count_item_enter"), strItem, nCost, strRoom);
    MS2Ptr<CMsgBoxData> box = FUN_140d73f20(strMsg, 1);
    if (box)
    {
        box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIDungeonRoomInfo::OnUseExtraTicketEnter));
        box->FUN_141a01800(1);
        FUN_140f73320(box.operator->(), bParty);
        FUN_140d73c60(box);
    }
    return true;
}
MS2_REPLACE_METHOD(0x1412B5EE0, UIDungeonRoomInfo, AskExtraTicketEnter, 870, 0x2EBE632F);

// @0x1412b6250
void UIDungeonRoomInfo::RequestEntry(bool bParty, bool bUseTicket)
{
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0 || m_spRoom == 0)
        return;
    COutPacket packet(0x2b);
    packet.Encode1(2);
    packet.Encode4(m_spRoom->GetDungeonRoomID());
    packet.COutPacket::vfunc_o10_0(bParty);
    packet.Encode4(m_pOwner->FUN_1412b9850());
    packet.COutPacket::vfunc_o10_0(bUseTicket);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x1412B6250, UIDungeonRoomInfo, RequestEntry, 258, 0xDE037DFC);

// @0x1412b6360
int UIDungeonRoomInfo::GetClearCount()
{
    if (m_spRoom == 0)
        return 0xb;
    return FUN_140931510()->FUN_140d9f880(m_spRoom->GetDungeonRoomID());
}
MS2_REPLACE_METHOD(0x1412B6360, UIDungeonRoomInfo, GetClearCount, 99, 0x80C0E990);

// @0x1412b63d0
int UIDungeonRoomInfo::GetMemberClearCount(MS2Ptr<CPartyMember> spMember)
{
    if (m_spRoom == 0)
        return 0xb;
    return spMember->counters.FUN_140268570(m_spRoom->GetDungeonRoomID());
}

// @0x1412b6480
CString UIDungeonRoomInfo::GetCountColor(int nState)
{
    if (nState == 0)
        return "green";
    if (nState == 1)
        return "blue";
    return "red";
}
MS2_REPLACE_METHOD(0x1412B6480, UIDungeonRoomInfo, GetCountColor, 162, 0x90B2E79D);

// @0x1412b6bb0
int UIDungeonRoomInfo::IsCooldown()
{
    if (m_spRoom == 0)
        return 0;
    if (m_spRoom->GetLimitType() != 2)
        return 0;
    if (FUN_140931510()->FUN_140d9f2c0()->CanEnter(m_spRoom->GetRewardRoomID()))
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x1412B6BB0, UIDungeonRoomInfo, IsCooldown, 214, 0xE7D9E1CC);
