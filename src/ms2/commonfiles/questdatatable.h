// questdatatable.h - QuestDataTable (RTTI name): the quest table read from Table/QuestData.xml; one CQuestData row per
// quest id plus the lookup indices built while loading. Header name assumed. Member names are invented from use.
// Singleton instance: DAT_143ab0c70 (FUN_1407476c0).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/famealliance.h"
#include "ms2/commonfiles/blackmarketitemoption.h"
#include <map>
#include <set>
#include <vector>

class QuestDataTable : public TSingleton<QuestDataTable>, public CValidData<QuestDataTable>
{
public:
    typedef Unk_BmBoxPtr<ATL::CAtlArray<unsigned> > IdsPtr;

    QuestDataTable();                                       // 0x14074bd90
    virtual ~QuestDataTable();                              // 0x14074c130

    // queries used by CQuestManagerCommon (questdata.cpp)
    int FUN_14074e390(int nGroupId);                        // the group's pick kind (0 none, 1 per-selector, 2 per-day)
    void FUN_14074e6c0(int nGroupId, int nSelector, int nSeed, ATL::CAtlArray<unsigned>& out);   // the group's quest pick
    int FUN_14074e450(int nGroupId);                        // how many quests a group hands out (1 when unknown)

    static bool s_bInit;
    static void CheckInit();
    static void SetInit(bool bInit) { s_bInit = bInit; }       // 0x14075ebe0
    void LoadQuestData();                                   // loads QuestData.xml and builds the indices                                // 0x14075a3f0 (message box when the table was never created)
    void FUN_1407511e0();                                   // drops every row and index
    MS2Ptr<CQuestData> FUN_14074c9d0(int nQuestId);                         // by id (null when missing)
    void FUN_14074cad0(ATL::CAtlArray<MS2Ptr<CQuestData> >& out, int nType);       // rows of the type (11 = all)
    void FUN_14074cbf0(int nMapId, ATL::CAtlArray<unsigned>& out);
    void FUN_14074cca0(ATL::CAtlArray<MS2Ptr<CQuestData> >& out, int nGrade);      // type 3 rows of the grade (0 = all)
    void FUN_14074cde0(ATL::CAtlArray<MS2Ptr<CQuestData> >& out, int nFlag);       // type 5 rows with the flag value (0 = all)
    void FUN_14074cf20(ATL::CAtlArray<unsigned>& out);                           // chapter ids
    void FUN_14074cfd0(int nChapter, ATL::CAtlArray<unsigned>& out);
    void FUN_14074d080(int nMapId, ATL::CAtlArray<unsigned>& out);
    void FUN_14074d140(unsigned short nLevel, int nJob, std::vector<unsigned>& out);
    void FUN_14074d2b0(Unk_FameAlliance nAlliance, ATL::CAtlArray<unsigned>& out);
    void FUN_14074d360(unsigned nKey, ATL::CAtlArray<unsigned>& out);
    void FUN_14074d410(ATL::CAtlArray<unsigned>& out);
    IdsPtr FUN_14074df70(unsigned nKey, int nIndex);
    bool FUN_14074e030(int nNpcId);
    std::vector<unsigned>& FUN_14074e0d0();
    std::vector<unsigned>* FUN_14074e0f0(int nNpcId);
    unsigned FUN_14074e1c0(int nKey);
    unsigned FUN_14074e240(int nKey);
    unsigned FUN_14074e2c0(int nKey);
    int FUN_14074e510(int nQuestId);
    bool FUN_14074e560(unsigned nFirst, unsigned nLast);        // a quest with an id in the range and m_30 == 0
    void FUN_14074eac0(int nQuestId, ATL::CAtlMap<unsigned, int>& visited);
    void FUN_14074ebc0(int nChain, IdsPtr spIds, MS2Ptr<CQuestData> spData, int nDepth);   // collects the chain of following quests
    void FUN_14074d480();                                   // sorts m_378 by level
    void FUN_14074fee0();                                   // chapter -> field values
    void LoadQuestGroupTable();                                   // loads QuestGroupTable.xml
    void FUN_1407503f0();                                   // reverse require links and chapter order
    void FUN_140750d90();                                   // sorts the npc quest lists
    void FUN_140750ea0();                                   // sorts m_1d8
    void FUN_140750f30();
    void FUN_14074f160();                                   // builds every index from m_quests
    void FUN_14074ee30();                                   // scales every reward by the level rate   // the quest and every quest that requires it

    CLockCriticalSection m_lock;                                            // +0x10
    std::map<unsigned, MS2Ptr<CQuestData> > m_quests;                            // +0x40 by quest id
    ATL::CAtlMap<int, IdsPtr> m_chapter;                                    // +0x50 chapter -> quest ids
    ATL::CAtlMap<int, unsigned> m_98;                                           // +0x98 chapter -> value
    ATL::CAtlMap<int, unsigned> m_e0;                                           // +0xe0 chapter -> value
    ATL::CAtlArray<unsigned> m_128;                                         // +0x128 auto-start quests
    ATL::CAtlMap<unsigned, IdsPtr> m_148[2];                                // +0x148 item id -> quest ids (0 accept, 1 complete)
    ATL::CAtlArray<unsigned> m_1d8;                                         // +0x1d8
    ATL::CAtlMap<unsigned, IdsPtr> m_1f8;                                   // +0x1f8
    ATL::CAtlMap<unsigned, IdsPtr> m_240;                                   // +0x240
    ATL::CAtlMap<unsigned, unsigned> m_288;                                 // +0x288
    ATL::CAtlMap<unsigned, int> m_2d0;                                          // +0x2d0 quest id -> 0/1 (finished-dependency cache)
    ATL::CAtlMap<Unk_FameAlliance, IdsPtr> m_318;                           // +0x318 alliance -> quest ids
    std::vector<unsigned> m_360;                                            // +0x360
    std::vector<MS2Ptr<CQuestData> > m_378;                                 // +0x378 sorted by level
    ATL::CAtlMap<int, IdsPtr> m_390;                                        // +0x390 group id -> quest ids
    ATL::CAtlMap<int, Unk_SocketPtr<CQuestData::GroupPickData> > m_3d8;     // +0x3d8 group id -> pick data
    std::map<int, unsigned> m_420;                                              // +0x420
    std::map<unsigned, std::vector<unsigned> > m_430;                              // +0x430 npc id -> quest ids
};
MS2_CHECK_SIZE(QuestDataTable, 0x440);
