// reactordata.h - reactor table types (RTTI names ReactorCondition, ReactorConditionItem, ReactorStateData,
// ReactorData, CReactorDataTable): Table/reactor.xml (<reactor id createAnimation reactAnimation reactTimeMSec
// reactDistance reactorStateList connectedEffect gameEventId rewardItemListXml/>) and Table/reactorState.xml
// (<reactorState id type nextTimeSec expireTimeSec kfmName startAni idleAni actionStringKey><condItem/>).
// Header name assumed; member names are invented from use. Shared with client\ms2\reactor.cpp.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/os.h"

class Unk_140165cf0;    // game TinyXML element (declared where the loaders are)

// Condition of a reactor state (0x20 bytes, vftable: deleting dtor only). m_nType is the condition kind (the only
// subclass in this unit, ReactorConditionItem, uses 0).
class ReactorCondition : public CPtred
{
public:
    ReactorCondition(long nType);           // 0x14076ca80
    virtual ~ReactorCondition() = default;  // 0x14076cda0

    long m_nType;                           // +0x18
};
MS2_CHECK_SIZE(ReactorCondition, 0x20);

// <condItem code= rank= consume= checkCount=/> (0x30 bytes).
class ReactorConditionItem : public ReactorCondition
{
public:
    ReactorConditionItem();                 // 0x14076cac0
    virtual ~ReactorConditionItem() = default;   // 0x14076cdc0

    int m_nCode;                            // +0x20 "code" (item id)
    int m_nRank;                            // +0x24 "rank" (default 1)
    int m_nConsume;                         // +0x28 "consume"
    int m_nCheckCount;                      // +0x2c "checkCount"
};
MS2_CHECK_SIZE(ReactorConditionItem, 0x30);
MS2_CHECK_OFFSET(ReactorConditionItem, m_nCheckCount, 0x2c);

// One <reactorState> row of reactorState.xml (0x80 bytes).
class ReactorStateData : public CPtred
{
public:
    typedef MS2Ptr<ReactorCondition> ConditionPtr;
    typedef ATL::CAtlList<ConditionPtr> ConditionList;

    ReactorStateData();                     // 0x14076a3b0
    virtual ~ReactorStateData();            // 0x14076a4b0

    int m_nType;                            // +0x18 "type" (1 connect, 2 sleep, 3 reward)
    int m_nId;                              // +0x1c "id"
    int m_nNextTimeSec;                     // +0x20 "nextTimeSec"
    int m_nExpireTimeSec;                   // +0x24 "expireTimeSec"
    CStringA m_strKfmName;                  // +0x28 "kfmName"
    CStringA m_strStartAni;                 // +0x30 "startAni"
    CStringA m_strIdleAni;                  // +0x38 "idleAni"
    CStringA m_str40;                       // +0x40 (not loaded here)
    CStringW m_strActionStringKey;          // +0x48 "actionStringKey"
    ConditionList m_conditions;             // +0x50 <condItem> children

    bool Load(Unk_140165cf0* pNode);        // 0x14076a550
};
MS2_CHECK_SIZE(ReactorStateData, 0x80);
MS2_CHECK_OFFSET(ReactorStateData, m_strKfmName, 0x28);
MS2_CHECK_OFFSET(ReactorStateData, m_strActionStringKey, 0x48);
MS2_CHECK_OFFSET(ReactorStateData, m_conditions, 0x50);

// One <reactor> row of reactor.xml (0xb8 bytes).
class ReactorData : public CPtred
{
public:
    typedef MS2Ptr<ReactorStateData> StatePtr;

    ReactorData();                          // 0x14076a9e0
    virtual ~ReactorData();                 // 0x14076aab0

    bool Load(Unk_140165cf0* pNode);        // 0x14076ab40
    CStringA GetCreateAnimation();          // 0x14076b060 a random entry (empty when none)
    CStringA GetReactAnimation();           // 0x14076b110

    ATL::CAtlArray<CStringA> m_createAnims; // +0x18 "createAnimation"
    ATL::CAtlArray<CStringA> m_reactAnims;  // +0x38 "reactAnimation"
    int m_nId;                              // +0x58 "id"
    float m_fReactDistance;                 // +0x5c "reactDistance"
    int m_nReactTimeMSec;                   // +0x60 "reactTimeMSec" (15000)
    CStringA m_strConnectedEffect;          // +0x68 "connectedEffect"
    int m_nGameEventId;                     // +0x70 "gameEventId"
    ATL::CAtlArray<StatePtr> m_states;      // +0x78 "reactorStateList" (ids resolved through the state table)
    ATL::CAtlArray<ItemEntity> m_rewards;   // +0x98 "rewardItemListXml"
};
MS2_CHECK_SIZE(ReactorData, 0xb8);
MS2_CHECK_OFFSET(ReactorData, m_nId, 0x58);
MS2_CHECK_OFFSET(ReactorData, m_strConnectedEffect, 0x68);
MS2_CHECK_OFFSET(ReactorData, m_states, 0x78);
MS2_CHECK_OFFSET(ReactorData, m_rewards, 0x98);

// RTTI CReactorDataTable: TSingleton at +0, CValidData at +8. Its ctor/dtor are outside this unit's range.
class CReactorDataTable : public TSingleton<CReactorDataTable>, public CValidData<ReactorData>
{
public:
    typedef MS2Ptr<ReactorData> DataPtr;
    typedef MS2Ptr<ReactorStateData> StatePtr;
    typedef MS2Ptr<CCacheData> CachePtr;
    typedef ATL::CAtlMap<int, DataPtr> DataMap;
    typedef ATL::CAtlMap<int, StatePtr> StateMap;
    typedef ATL::CAtlList<CachePtr> CacheList;

    CReactorDataTable();
    // implicit dtor @0x1414974d0 (?\ms2.cpp; the exe's stores no vftable pointers)

    bool Reload();                          // 0x14076b7d0 (always true)
    bool Load();                            // 0x14076b7f0 reactor.xml + reactorState.xml
    DataPtr GetReactorData(int nId);        // 0x14076bbd0 reloads first when the cache is stale
    StatePtr GetStateData(int nId);       // 0x14076bd00

    static void CheckInit();                // 0x14076d540
    static void SetInit(bool b);            // 0x14076f700

    static bool s_bInit;                    // 0x143ab0e70

private:
    bool IsCacheStale();                    // 0x14076b1c0
    bool LoadReactors();                    // 0x14076b2e0
    bool LoadStates();                      // 0x14076b560

    MS2_LAYOUT_FRIEND;
    CStringA m_strReactorXml;               // +0x10 Table/reactor.xml
    CStringA m_strStateXml;                 // +0x18 Table/reactorState.xml
    CacheList m_cacheFiles;                 // +0x20
    CLockCriticalSection m_lock;            // +0x50
    DataMap m_reactors;                     // +0x80
    StateMap m_states;                      // +0xc8
};
MS2_CHECK_OFFSET(CReactorDataTable, m_strReactorXml, 0x10);
MS2_CHECK_OFFSET(CReactorDataTable, m_cacheFiles, 0x20);
MS2_CHECK_OFFSET(CReactorDataTable, m_lock, 0x50);
MS2_CHECK_OFFSET(CReactorDataTable, m_reactors, 0x80);
MS2_CHECK_OFFSET(CReactorDataTable, m_states, 0xc8);
