// cguidemanager.h - PLACEHOLDER for CGuideManager (RTTI .?AVCGuideManager@@, 0x1d0 bytes). NOT an original header.
// Bases: TSingleton<CGuideManager> at +0x0, UIItemEventListener at +0x8, UIUGCEventListener at +0x10, UIStatusEventListener at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Members proven from the ctor 0x14138a4d0 / dtor 0x14138ab80
// and the std/ATL glue of client\ms2\guideentity.cpp (the max_size constants and node sizes pick the element types).
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/guideoccurcontainer.h"
#include "ms2/placeholder/partybits.h"

#include <atlcoll.h>
#include <list>
#include <map>
#include <set>
#include <vector>

class CGuideEntity;
class NotifyObject;
class GuideTriggerEventGroup;
class CInPacket;
struct Unk_GcOptInt;
struct Unk_GameEventIntRange;

class CGuideManager : public TSingleton<CGuideManager>,
                      public UIItemEventListener,
                      public UIUGCEventListener,
                      public UIStatusEventListener
{
public:
    enum Occurrence { OccurrenceNone = 0 };                 // the guide event kinds (key of m_byOccur, element of the sets)
    enum TriggerType { TriggerNone = 0 };                   // key of m_triggers

    CGuideManager();                                        // 0x14138a4d0
    virtual ~CGuideManager();

    // The notify callbacks the ctor registers (names invented).
    void OnLearnEmotion(NotifyObject* pNotify);             // 0x14138eb90 NotifyLearnEmotion
    void OnUseSkill(NotifyObject* pNotify);                 // 0x14138ebd0 NotifyUseSKill
    void OnChangeMyLevel(NotifyObject* pNotify);            // 0x14138ec10 NotifyChangeMyLevel
    void OnDungeonEnterState(NotifyObject* pNotify);        // 0x14138ec40 NotifyDungeonEnterState

    // The listener slots the manager overrides (names invented).
    void vfunc_2(void* pItem) override;                     // 0x14138e940 item added: raises the item triggers
    void vfunc_3(void* pItem, bool bFlag) override;         // 0x14138ea00
    void vfunc_4(void* pItem, int nCount) override;         // 0x14138ead0
    void vfunc_5(void* pItem, int nCount) override;         // 0x14138ea70
    void vfunc_ugc_5() override;                            // 0x14138eb30
    void vfunc_ugc_6() override;                            // 0x14138eb60
    void vfunc_oa0_7(int nMode, CStringW strText) override; // 0x14138ec70

    // The guide state machine (names invented; callers in other units reach these through FUN_ addresses).
    void StopAndUpdate();                                   // 0x14138b140
    int SendStates();                                       // 0x14138b170: packet 0x57, the cleared steps
    void ReceiveStates(CInPacket& kPacket);                 // 0x14138b280
    void ClearStates();                                     // 0x14138b3a0
    void Load();                                            // 0x14138b3e0: guide.xml and everything it imports
    void LoadFile(const CStringA& strPath);                 // 0x14138b4d0
    MS2Ptr<CGuideEntity> FindEntity(int nId);               // 0x14138b990
    void ClearEntities();                                   // 0x14138ba40
    void Tick();                                            // 0x14138baf0
    void UpdateEntities();                                  // 0x14138bb50
    void ProcessOccurrences();                              // 0x14138be90
    void AddTrigger(TriggerType eType, int nValue, int nSubValue);  // 0x14138bf00
    bool CheckTrigger(TriggerType eType, Unk_GcOptInt oValue, Unk_GcOptInt oSubValue);   // 0x14138c0d0
    bool CheckTriggerRange(TriggerType eType, const Unk_GameEventIntRange& range);              // 0x14138c210
    bool ProcessEntity(MS2Ptr<CGuideEntity> spEntity, int nMode);                // 0x14138c2d0
    void FinishById(int nId);                               // 0x14138c680
    void FinishEntity(MS2Ptr<CGuideEntity> spEntity);       // 0x14138c710
    void ResetEntity(MS2Ptr<CGuideEntity> spEntity);        // 0x14138c850
    int IsRestricted(int nType);                            // 0x14138c900
    int IsSkillRestricted(int nSkillId);                    // 0x14138c930
    int IsActionRestricted(int nType);                      // 0x14138c9c0
    bool IsCleared(int nId);                                // 0x14138caa0
    int GetStateChanged();                                  // 0x14138cc20
    void ResetClearState();                                 // 0x14138cc40
    void TestEntity(int nMode, int nId);                    // 0x14138cce0
    void TestCondition(CStringA strName);                   // 0x14138d090
    void ShowEntityState(int nId);                          // 0x14138d160
    void ToggleDebug();                                     // 0x14138d460
    void ChangeEntityState(int nId);                        // 0x14138d520
    void SetInitialState();                                 // 0x14138d790
    void QueueOccurrence(Occurrence eOccurrence, int nSubValue);   // 0x14138d7e0
    int InternOccurrence(const CStringA& strName);          // 0x14138d870
    void PrepareEntities();                                 // 0x14138d980
    void NotifyEntitiesLoaded();                            // 0x14138da20
    void QueueAllEntities();                                // 0x14138dac0
    void RefreshEntities();                                 // 0x14138dbb0
    void BuildOccurIndex();                                 // 0x14138dc50
    void QueueSubkeyEntities();                             // 0x14138e0c0
    void QueueWholeSubkeyEntities();                        // 0x14138e400
    void QueueBaseEntities();                               // 0x14138e6d0

    int m_n20;                                              // +0x20
    int m_n24;                                              // +0x24
    int m_nDebug;                                           // +0x28: nonzero logs every trigger
    char m_pad_2c;                                          // +0x2c
    Unk_PartyBits m_bits;                                   // +0x2d (a 1-byte bitset, ctor 0x1402e49d0; ReceiveStates reads it)
    char m_pad_2e[2];                                       // +0x2e
    ATL::CRBMap<unsigned, MS2Ptr<CGuideEntity> > m_entities;     // +0x30 guide id -> entity
    ATL::CRBMap<unsigned, unsigned> m_map60;                          // +0x60
    ATL::CRBMap<unsigned, unsigned> m_map90;                          // +0x90
    ATL::CAtlArray<MS2Ptr<CCacheData> > m_caches;           // +0xc0 the loaded guide xml files
    ATL::CAtlMap<TriggerType, MS2Ptr<GuideTriggerEventGroup> > m_triggers;   // +0xe0
    ATL::CAtlArray<CStringW> m_names;                       // +0x128
    std::set<Occurrence> m_setPending;                      // +0x148 occurrences raised since the last update
    std::set<Occurrence> m_setPlain;                        // +0x158 raised without a sub value
    std::set<Occurrence> m_setIndexed;                      // +0x168 occurrences with a sub-value index
    std::vector<std::pair<Occurrence, int> > m_vecSub;      // +0x178 raised (occurrence, sub value) pairs
    std::map<Occurrence, GuideOccurContainer> m_byOccur;    // +0x190
    std::set<unsigned int> m_setQueued;                     // +0x1a0 ids of the queued entities
    std::list<MS2Ptr<CGuideEntity> > m_listQueued;          // +0x1b0
    std::map<CStringA, int> m_mapNames;                     // +0x1c0 interned occurrence names
};
MS2_CHECK_SIZE(CGuideManager, 0x1d0);
MS2_CHECK_OFFSET(CGuideManager, m_entities, 0x30);
MS2_CHECK_OFFSET(CGuideManager, m_n20, 0x20);
MS2_CHECK_OFFSET(CGuideManager, m_nDebug, 0x28);
MS2_CHECK_OFFSET(CGuideManager, m_bits, 0x2d);
MS2_CHECK_OFFSET(CGuideManager, m_map60, 0x60);
MS2_CHECK_OFFSET(CGuideManager, m_map90, 0x90);
MS2_CHECK_OFFSET(CGuideManager, m_caches, 0xc0);
MS2_CHECK_OFFSET(CGuideManager, m_triggers, 0xe0);
MS2_CHECK_OFFSET(CGuideManager, m_names, 0x128);
MS2_CHECK_OFFSET(CGuideManager, m_setPending, 0x148);
MS2_CHECK_OFFSET(CGuideManager, m_setPlain, 0x158);
MS2_CHECK_OFFSET(CGuideManager, m_setIndexed, 0x168);
MS2_CHECK_OFFSET(CGuideManager, m_vecSub, 0x178);
MS2_CHECK_OFFSET(CGuideManager, m_byOccur, 0x190);
MS2_CHECK_OFFSET(CGuideManager, m_setQueued, 0x1a0);
MS2_CHECK_OFFSET(CGuideManager, m_listQueued, 0x1b0);
MS2_CHECK_OFFSET(CGuideManager, m_mapNames, 0x1c0);
