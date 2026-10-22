// dungeonmissioncli.h - the client side of a dungeon mission (the progress of one DungeonMissionData of
// Table/DungeonMission.xml): DungeonMissionCli (RTTI .?AVDungeonMissionCli@@) and one subclass per mission type, created
// by name ("DungeonMission" + the data's type attribute) through the ClassObject factory registry. Owning unit:
// ?\dungeonmissioncli.cpp (0x140b1dcf0-0x140b206b0). Class names from RTTI and the registered names; member names are
// invented. NOT an original header.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/commonfiles/dungeonmissiondata.h"

class CInputStream;

// Base: the mission data it tracks plus the score earned so far (read from the server's progress packet). 0x28 bytes.
class DungeonMissionCli : public ClassObject
{
public:
    static MS2Ptr<DungeonMissionCli> Create(unsigned nId);  // 0x140b1dd30 NULL if the id / class is unknown
    DungeonMissionCli();                                    // 0x140b1dcf0 (the implicit dtor is 0x140b1fed0)
    virtual void vfunc_2(CInputStream& in);                 // 0x140b1df30 reads the score
    virtual void vfunc_3();                                 // 0x140b1df60
    virtual CStringW vfunc_4();                             // 0x140b1df70 the in game line "<name>"
    short GetScore();                                       // 0x140b1e010
    short GetMaxScore();                                    // 0x140b1e030 0 without data
    CStringW GetName();                                     // 0x140b1e060
    unsigned GetId();                                       // 0x140b1e0e0
    bool IsMaxScore();                                      // 0x140b1e110 not for penalty missions
    bool IsPenaltyCleared();                                // 0x140b1e180

protected:
    MS2_LAYOUT_FRIEND;
    DungeonMissionData* m_data;                             // +0x18 (not ref counted)
    short m_score;                                          // +0x20
};
MS2_CHECK_SIZE(DungeonMissionCli, 0x28);
MS2_CHECK_OFFSET(DungeonMissionCli, m_data, 0x18);
MS2_CHECK_OFFSET(DungeonMissionCli, m_score, 0x20);

class DungeonMissionPlayTime : public DungeonMissionCli
{
public:
    static ClassObject* CreateObject();                     // 0x140b1e1e0
    DungeonMissionPlayTime();                               // 0x140b1e290
    virtual CStringW GetTypeName();                             // 0x140b1e240
    virtual void vfunc_2(CInputStream& in);                 // 0x140b1e2e0

protected:
    MS2_LAYOUT_FRIEND;
    __int64 m_time1;                                        // +0x28
    __int64 m_time2;                                        // +0x30
};
MS2_CHECK_SIZE(DungeonMissionPlayTime, 0x38);
MS2_CHECK_OFFSET(DungeonMissionPlayTime, m_time1, 0x28);

class DungeonMissionLimitUserCount : public DungeonMissionCli
{
public:
    static ClassObject* CreateObject();                     // 0x140b1e340
    DungeonMissionLimitUserCount();                         // 0x140b1e3f0
    virtual CStringW GetTypeName();                             // 0x140b1e3a0
};
MS2_CHECK_SIZE(DungeonMissionLimitUserCount, 0x28);

// The counted missions: m_count of the data's applyCount steps are done. The subclasses below only add their name
// (GetTypeName) and the factory; addresses are on the function tags in the cpp.
class DungeonMissionEvent : public DungeonMissionCli
{
public:
    static ClassObject* CreateObject();                     // 0x140b1e430
    DungeonMissionEvent();                                  // 0x140b1e4e0
    virtual CStringW GetTypeName();                             // 0x140b1e490
    virtual void vfunc_2(CInputStream& in);                 // 0x140b1e520
    virtual CStringW vfunc_4();                             // 0x140b1e560 "<name> (count/total)"

protected:
    MS2_LAYOUT_FRIEND;
    short m_count;                                          // +0x28
};
MS2_CHECK_SIZE(DungeonMissionEvent, 0x30);
MS2_CHECK_OFFSET(DungeonMissionEvent, m_count, 0x28);

#define MS2_DUNGEON_MISSION_EVENT_CLASS(Name) \
class DungeonMission##Name : public DungeonMissionEvent \
{ \
public: \
    static ClassObject* CreateObject(); \
    DungeonMission##Name(); \
    virtual CStringW GetTypeName(); \
}; \
MS2_CHECK_SIZE(DungeonMission##Name, 0x30);

MS2_DUNGEON_MISSION_EVENT_CLASS(DeathCount)
MS2_DUNGEON_MISSION_EVENT_CLASS(KillNpc)
MS2_DUNGEON_MISSION_EVENT_CLASS(HealingPotion)
MS2_DUNGEON_MISSION_EVENT_CLASS(DamageBySkill)
MS2_DUNGEON_MISSION_EVENT_CLASS(UseEp)
MS2_DUNGEON_MISSION_EVENT_CLASS(UseSp)
MS2_DUNGEON_MISSION_EVENT_CLASS(UseSkill)
MS2_DUNGEON_MISSION_EVENT_CLASS(GainBuff)
MS2_DUNGEON_MISSION_EVENT_CLASS(LastHitNpc)
MS2_DUNGEON_MISSION_EVENT_CLASS(UseInteractObject)
MS2_DUNGEON_MISSION_EVENT_CLASS(DamageCount)
MS2_DUNGEON_MISSION_EVENT_CLASS(DamageToNpc)
MS2_DUNGEON_MISSION_EVENT_CLASS(Trigger)
