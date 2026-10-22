// CQuestManager object (questmanager.cpp#2). Field names are inferred.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/cquestmanagercommon.h"
class CInPacket;
class NotifyObject;
class PCBase;
// Original counter constructor 0x140517b00; zeroes both 32-bit fields.
struct Unk_QuestCounter { Unk_QuestCounter(); int FUN_140268870(int interval); int first, second; };
MS2_CHECK_SIZE(Unk_QuestCounter, 8);
class CItem;
template <class T> class MS2Ptr;
// A quest an item starts or advances (ctor 0x1416dbb20; the 0x1416ce860 list, ranked by 0x1416ce6a0).
struct Unk_QuestItemLink
{
    unsigned m_questId = 0;
    int m_state = 4;           // 4 = not offered
    int m_kind = 2;            // 0 start item, 1 progress item
};
MS2_CHECK_SIZE(Unk_QuestItemLink, 0xc);
// Quest progress state as filtered by FUN_1416cb4d0 (values of CQuest FUN_1407476d0; 4/5 select every quest). It is
// an enum, not int: the exe's vector of it (0x1416d91c0.. 0x1416e3510) is a separate copy from vector<int>/<unsigned>.
// Names invented.
enum Unk_QmQuestState { QmQuestState0 = 0, QmQuestState1 = 1, QmQuestState2 = 2, QmQuestState3 = 3, QmQuestState4 = 4,
                        QmQuestState5 = 5 };
// Quest marker state of an npc (ctor 0x140964630 calls Reset 0x1409669c0; dtor 0x140964e40). Filled by
// FUN_1416d12d0. cproxygameobject.h's Unk_ProxyValue88 (CProxyGameObject+0x88) is this record with +0x10..+0x1c opaque.
struct Unk_QmNpcQuestState
{
    Unk_QmNpcQuestState();
    ~Unk_QmNpcQuestState();
    void FUN_1409669c0();               // Reset: icon 11, state 4, quest 0, text "", npc 0
    int m_icon;                         // +0x00 quest kind of the best quest (FUN_14074bc90)
    int m_state;                        // +0x04 0 completable, 1 in progress, 2 acceptable, 4 none
    unsigned m_questId;                 // +0x08
    CStringW m_text;                    // +0x10 tooltip list of the npc's quests
    int m_npcId;                        // +0x18
    int m_wantText;                     // +0x1c build m_text
};
MS2_CHECK_SIZE(Unk_QmNpcQuestState, 0x20);
MS2_CHECK_OFFSET(Unk_QmNpcQuestState, m_text, 0x10);
MS2_CHECK_OFFSET(Unk_QmNpcQuestState, m_wantText, 0x1c);
// One quest of an npc while FUN_1416d12d0 builds the tooltip list (12 bytes, ctor 0x1416dbba0).
struct Unk_QmNpcQuestEntry
{
    int m_score = 0;                    // FUN_1416d1100 flags
    unsigned m_questId = 0;
    int m_state = 4;
};
MS2_CHECK_SIZE(Unk_QmNpcQuestEntry, 0xc);

class CQuestManager : public TSingleton<CQuestManager>, public UIItemEventListener,
                      public CQuestManagerCommon {
public:
    CQuestManager();
    virtual ~CQuestManager();
    virtual int vfunc_1(int, int);
    void vfunc_2(void*) override;
    void vfunc_3(void*, bool) override;
    void vfunc_4(void*, int) override;
    void vfunc_21(void*) override;
    void vfunc_22(void*) override;
    void vfunc_33(int, int) override;
    int vfunc_o10_0(int, int) override;
    int vfunc_o10_1(int) override;
    int vfunc_o10_2(int) override;
    Unk_PayloadPtr<CQuest> vfunc_o10_3(int) override;
    int vfunc_o10_4() override;
    int vfunc_o10_5() override;
    int vfunc_o10_6() override;
    int vfunc_o10_7() override;
    __int64 vfunc_o10_8() override;
    int vfunc_o10_9() override;
    int vfunc_o10_10() override;
    int vfunc_o10_11() override;
    __int64 vfunc_o10_12() override;
    int vfunc_o10_13(int) override;
    int vfunc_o10_14(int) override;
    int vfunc_o10_15(int) override;
    int vfunc_o10_16(int) override;
    int vfunc_o10_17(int) override;
    int vfunc_o10_18() override;
    int vfunc_o10_19() override;
    int vfunc_o10_20(const ATL::CAtlArray<unsigned>&) override;
    __int64 vfunc_o10_22() override;
    unsigned vfunc_o10_23(const Unk_QuestCondition&) override;

    void FUN_1416ca2f0();
    void FUN_1416ca730(NotifyObject*);
    void FUN_1416ca760(NotifyObject*);
    void FUN_1416ca780(NotifyObject*);
    void FUN_1416ca7a0(NotifyObject*);
    void FUN_1416ca7c0(NotifyObject*);
    void FUN_1416ca830(CInPacket&);
    void FUN_1416ca440();
    void FUN_1416ca670();
    CQuest* FUN_1416ca9d0(int questId);
    void FUN_1416cb0d0(int questId, int force);
    int FUN_1416d0610();
    int FUN_1416d0e20();
    void SendQuestMode14();
    void FUN_1416d0920(ATL::CAtlArray<unsigned>& out);
    int FUN_1416d09d0(int mapId, int warn);
    void FUN_1416d1d00(PCBase* pc);
    void FUN_1416d3010();
    void FUN_1416d3250();
    void FUN_1416ca850(NotifyObject*);
    int FUN_1416cae20(int);
    void FUN_1416caec0(Unk_PayloadPtr<CQuest>);
    void FUN_1416cb260(ATL::CAtlArray<unsigned>&, int, int, int);
    void FUN_1416cb4d0(std::vector<unsigned>&, std::vector<Unk_QmQuestState>, int, int);
    void FUN_1416cb8b0(ATL::CAtlArray<Unk_PayloadPtr<CQuest>>&, int, int, int);
    void FUN_1416cbb20(std::vector<Unk_PayloadPtr<CQuest>>&, int, int, int);
    void FUN_1416cde50(int);
    void FUN_1416ce140(int, int);
    int FUN_1416ce170(MS2Ptr<CItem>);
    int FUN_1416ce260(int);
    int FUN_1416ce3d0(int);
    int FUN_1416ce5a0();
    int FUN_1416ce6a0(MS2Ptr<CItem>);
    void FUN_1416ce860(MS2Ptr<CItem>, ATL::CAtlArray<Unk_QuestItemLink>&);
    int FUN_1416ce340(int);
    int FUN_1416cebf0(int);
    int FUN_1416cede0(int, unsigned*);
    void FUN_1416cef90(int);
    void SendQuestMode12(int);
    void SendQuestMode13(int);
    void SendQuestMode19(int);
    void FUN_1416cf870(int);
    void FUN_1416cf980(int, int);
    int FUN_1416cfc10(int);
    void FUN_1416cfc60(int);
    void FUN_1416cfc70(ATL::CAtlArray<Unk_PayloadPtr<CQuest>>&, int, int);
    int FUN_1416cfe20();
    int FUN_1416cff70();
    int FUN_1416d0260(MS2Ptr<class CLearningQuestData>, int);
    int FUN_1416d0530();
    struct Vector3 FUN_1416d0690();
    void SendQuestMode15(int);
    int FUN_1416d0f60(int);
    unsigned FUN_1416d1100(int, int, int*);
    int FUN_1416d12d0(int npcId, Unk_QmNpcQuestState* state, int all);
    void FUN_1416d16c0(int group, ATL::CAtlList<unsigned>& out);
    void FUN_1416d1800(int group, Unk_QmNpcQuestState* best);
    void FUN_1416d1a30(unsigned questId);
    std::pair<unsigned, __int64> FUN_1416d1e90();   // nearest live user of a tracked quest (quest id, user id)
    const std::set<unsigned __int64>& FUN_1416d2510(unsigned questId);   // users found for the quest (empty set if none)
    unsigned FUN_1416d2600(int questId, int checkAccept);   // first available follow-up quest
    int FUN_1416d26c0(int questId, std::list<unsigned>& out, int checkAccept);
    int FUN_1416d2910(unsigned toQuestId, std::list<std::list<unsigned>>& paths, int verbose);
    void OnQuest(CInPacket& packet);                 // the quest packet
    int FUN_1416d2f30(int chapter, std::list<std::list<unsigned>>& paths, int verbose);
    void FUN_1416d37c0();                                   // refresh the quest guide, close the quest/world map dialogs
    void FUN_1416d38a0(int type, int state, int skipGrouped);   // drop the matching quests from the active map
    int FUN_1416d40a0(int depth, unsigned fromQuestId, unsigned toQuestId, std::list<unsigned>& path,
        std::list<std::list<unsigned>>& reached, std::list<std::list<unsigned>>* notReached);
    int FUN_1416d3ed0(MS2Ptr<class CQuestData> data, int checkAccept, int job);   // job 200 = the player's
    int FUN_1416d00c0();
    int FUN_1416d0100();
    int FUN_1416d0150();
    int FUN_1416d0210();
    void FUN_1416d0740();
    int FUN_1416d0760();
    int FUN_1416d0780(int);
    int FUN_1416d07c0(int);
    int FUN_1416d0800(int);
    int FUN_1416d0e60(int);
    bool SendQuestMode20(int, const class CMsgBoxData&);
    void FUN_1416d1060(ATL::CAtlArray<Unk_PayloadPtr<CQuest>>&);
    void FUN_1416d3220();
    int FUN_1416d3430();
    int FUN_1416d3510();
    int FUN_1416d3af0(const ATL::CAtlArray<unsigned>&);
    void FUN_1416d3d50(Unk_PayloadPtr<CQuest>);

    using QuestMap = ATL::CRBMap<unsigned, Unk_PayloadPtr<CQuest>>;
    QuestMap m_quests20, m_quests50, m_quests80, m_questsb0;
    QuestMap m_questse0, m_quests110, m_quests140;
    int m_levelDirty;          // +170
    int m_availableDirty;      // +174
    int m_field178;
    int m_itemsDirty;          // +17c
    int m_field180;
    int m_group;               // +184
    int m_refreshCount;        // +188
    int m_targetObject;        // +18c
    int m_field190;
    unsigned m_requestTick;    // +194
    Unk_QuestCounter m_counter198;
    ATL::CAtlArray<unsigned> m_pinnedQuests; // +1a0
    ATL::CAtlMap<int, int> m_dailyCounts; // +1c0
    ATL::CAtlMap<int, int> m_weeklyCounts; // +208
    std::map<unsigned, std::set<unsigned __int64>> m_targets250;   // key unsigned: the exe tree calls less<unsigned>
    // +260: only the ctor and dtor reach it. Its tree nodes are 0x38 bytes and the element dtor releases an
    // Unk_PayloadPtr<CQuest> at +8 (0x1416dbfa0), so the element is pair<const int, Unk_PayloadPtr<CQuest>>; the
    // mangled-name order of its deallocate COMDATs (0x1416e2840 before the map<int, set> one at 0x1416e2870) fixes
    // the key as int.
    std::map<int, Unk_PayloadPtr<CQuest>> m_quests260;
};
MS2_CHECK_SIZE(CQuestManager, 0x270);
MS2_CHECK_OFFSET(CQuestManager, m_quests20, 0x20);
MS2_CHECK_OFFSET(CQuestManager, m_quests140, 0x140);
MS2_CHECK_OFFSET(CQuestManager, m_levelDirty, 0x170);
MS2_CHECK_OFFSET(CQuestManager, m_requestTick, 0x194);
MS2_CHECK_OFFSET(CQuestManager, m_pinnedQuests, 0x1a0);
MS2_CHECK_OFFSET(CQuestManager, m_dailyCounts, 0x1c0);
MS2_CHECK_OFFSET(CQuestManager, m_weeklyCounts, 0x208);
MS2_CHECK_OFFSET(CQuestManager, m_targets250, 0x250);
MS2_CHECK_OFFSET(CQuestManager, m_quests260, 0x260);
