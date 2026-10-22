// dungeonmissiondata.h - the dungeon missions (DungeonMission.xml): one ClassObject-derived class per mission type,
// created by name ("DungeonMissionData" + the type attribute) through the ClassObject factory registry. Owning unit:
// commonfiles\dungeonmissiondata.cpp (0x140314830-0x140318c80). Class names from RTTI and the registered names; field
// names from the xml attributes the loaders read; method names invented. NOT an original header.
#pragma once
#include <afx.h>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/classobject.h"

class Unk_140165cf0;     // game TinyXML element
class DungeonMissionCli;  // the client side missions (?\dungeonmissioncli.cpp) read the base fields
class DungeonMissionEvent;

// Base mission: a score of maxScore split into applyCount steps (vftable 0x142d25af0, 4 slots). 0x30 bytes.
class DungeonMissionData : public ClassObject
{
public:
    static ClassObject* CreateObject();                     // 0x140314830
    DungeonMissionData();                                   // 0x1403148e0
    virtual CStringW GetTypeName();                             // 0x140314890 L"DungeonMissionData"
    virtual bool Load(Unk_140165cf0* pElem);                // 0x140314960 id/type/maxScore/applyCount/isPenaltyType
    virtual bool vfunc_3();                                 // 0x140314bf0 false (PlayTime: true)
    unsigned GetId();                                       // 0x140314c00
    short GetScore(short nCount);                           // 0x140314c20 score for nCount applied steps
    CStringW GetName();                                     // 0x140314d00 string table 0x3c
    static MS2Ptr<DungeonMissionData> Create(Unk_140165cf0* pElem);   // 0x140314d60

protected:
    MS2_LAYOUT_FRIEND;
    friend class DungeonMissionCli;
    friend class DungeonMissionEvent;
    friend class UIDungeonRoomRankPanel;                    // reads m_maxScore (uidungeonroomdialog.cpp)
    unsigned m_id;                                          // +0x18 "id"
    CStringW m_type;                                        // +0x20 "type"
    short m_maxScore;                                       // +0x28 "maxScore"
    short m_applyCount;                                     // +0x2a "applyCount"
    bool m_isPenaltyType;                                   // +0x2c "isPenaltyType"
};
MS2_CHECK_SIZE(DungeonMissionData, 0x30);
MS2_CHECK_OFFSET(DungeonMissionData, m_id, 0x18);
MS2_CHECK_OFFSET(DungeonMissionData, m_type, 0x20);
MS2_CHECK_OFFSET(DungeonMissionData, m_maxScore, 0x28);
MS2_CHECK_OFFSET(DungeonMissionData, m_applyCount, 0x2a);
MS2_CHECK_OFFSET(DungeonMissionData, m_isPenaltyType, 0x2c);

class DungeonMissionDataPlayTime : public DungeonMissionData
{
public:
    static ClassObject* CreateObject();                     // 0x140314f20
    virtual CStringW GetTypeName();                             // 0x140314f80
    virtual bool Load(Unk_140165cf0* pElem);                // 0x140314fd0
    virtual bool vfunc_3();                                 // 0x140315050 true

protected:
    int m_value1;                                           // +0x30
    int m_value2;                                           // +0x34
};
MS2_CHECK_SIZE(DungeonMissionDataPlayTime, 0x38);

class DungeonMissionDataLimitUserCount : public DungeonMissionData
{
public:
    static ClassObject* CreateObject();                     // 0x140315060
    virtual CStringW GetTypeName();                             // 0x1403150c0
    virtual bool Load(Unk_140165cf0* pElem);                // 0x140315110

protected:
    unsigned m_value1;                                      // +0x30 the user count
};
MS2_CHECK_SIZE(DungeonMissionDataLimitUserCount, 0x38);

class DungeonMissionDataKillNpc : public DungeonMissionData
{
public:
    static ClassObject* CreateObject();                     // 0x140315170
    virtual CStringW GetTypeName();                             // 0x1403151d0
    virtual bool Load(Unk_140165cf0* pElem);                // 0x140315220 fails if value2 is 0

protected:
    MS2_LAYOUT_FRIEND;
    std::set<unsigned> m_value1;                            // +0x30 npc ids
    unsigned m_value2;                                      // +0x40 kill count
};
MS2_CHECK_SIZE(DungeonMissionDataKillNpc, 0x48);
MS2_CHECK_OFFSET(DungeonMissionDataKillNpc, m_value2, 0x40);

class DungeonMissionDataDamageBySkill : public DungeonMissionData
{
public:
    static ClassObject* CreateObject();                     // 0x140315310
    virtual CStringW GetTypeName();                             // 0x140315370
    virtual bool Load(Unk_140165cf0* pElem);                // 0x1403153c0

protected:
    MS2_LAYOUT_FRIEND;
    std::set<unsigned> m_value1;                            // +0x30 skill ids
    std::set<unsigned short> m_value2;                      // +0x40 skill levels
};
MS2_CHECK_SIZE(DungeonMissionDataDamageBySkill, 0x50);
MS2_CHECK_OFFSET(DungeonMissionDataDamageBySkill, m_value2, 0x40);

class DungeonMissionDataUseSkill : public DungeonMissionData
{
public:
    static ClassObject* CreateObject();                     // 0x140315430
    virtual CStringW GetTypeName();                             // 0x140315490
    virtual bool Load(Unk_140165cf0* pElem);                // 0x1403154e0

protected:
    unsigned m_value1;                                      // +0x30 skill id
};
MS2_CHECK_SIZE(DungeonMissionDataUseSkill, 0x38);

class DungeonMissionDataGainBuff : public DungeonMissionData
{
public:
    static ClassObject* CreateObject();                     // 0x140315540
    virtual CStringW GetTypeName();                             // 0x1403155a0
    virtual bool Load(Unk_140165cf0* pElem);                // 0x1403155f0

protected:
    std::set<unsigned> m_value1;                            // +0x30 buff ids
};
MS2_CHECK_SIZE(DungeonMissionDataGainBuff, 0x40);

class DungeonMissionDataLastHitNpc : public DungeonMissionData
{
public:
    static ClassObject* CreateObject();                     // 0x140315640
    virtual CStringW GetTypeName();                             // 0x1403156a0
    virtual bool Load(Unk_140165cf0* pElem);                // 0x1403156f0

protected:
    std::set<unsigned> m_value1;                            // +0x30 npc ids
};
MS2_CHECK_SIZE(DungeonMissionDataLastHitNpc, 0x40);

class DungeonMissionDataUseInteractObject : public DungeonMissionData
{
public:
    static ClassObject* CreateObject();                     // 0x140315740
    virtual CStringW GetTypeName();                             // 0x1403157a0
    virtual bool Load(Unk_140165cf0* pElem);                // 0x1403157f0

protected:
    int m_value1;                                           // +0x30
};
MS2_CHECK_SIZE(DungeonMissionDataUseInteractObject, 0x38);

class DungeonMissionDataDamageToNpc : public DungeonMissionData
{
public:
    static ClassObject* CreateObject();                     // 0x140315850
    virtual CStringW GetTypeName();                             // 0x1403158b0
    virtual bool Load(Unk_140165cf0* pElem);                // 0x140315900
    bool IsTargetNpc(unsigned nNpcId);                      // 0x140315990 (an empty list matches every npc)

protected:
    MS2_LAYOUT_FRIEND;
    __int64 m_value1;                                       // +0x30 total damage
    __int64 m_damagePerApply;                               // +0x38 value1 / applyCount
    std::set<unsigned> m_value2;                            // +0x40 npc ids
};
MS2_CHECK_SIZE(DungeonMissionDataDamageToNpc, 0x50);
MS2_CHECK_OFFSET(DungeonMissionDataDamageToNpc, m_value2, 0x40);

class DungeonMissionDataTrigger : public DungeonMissionData
{
public:
    static ClassObject* CreateObject();                     // 0x140315a10
    virtual CStringW GetTypeName();                             // 0x140315a70
    virtual bool Load(Unk_140165cf0* pElem);                // 0x140315ac0
};
MS2_CHECK_SIZE(DungeonMissionDataTrigger, 0x30);
