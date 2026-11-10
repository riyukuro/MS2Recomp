// csadventurelevelmission.h - PLACEHOLDER for CSAdventureLevelMission (RTTI .?AVCSAdventureLevelMission@@, 0x20 bytes,
// vftable 0x142d8c5c0, one slot: the deleting dtor 0x1407ab500) and CAdventureLevelMissionData (RTTI
// .?AVCAdventureLevelMissionData@@, 0x28 bytes, base CPtred, vftable 0x142ceae90). NOT original headers.
// The packet body is a mission-kind byte (6 or 7) and a map of mission id -> progress record (unit_1407a4f20).
#pragma once
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"

class CInPacket;
class CAdventureLevelMissionData : public CPtred {
public:
    CAdventureLevelMissionData();                 // 0x140195660
    // implicit virtual dtor 0x140195700 (??_G 0x140195820): the exe has both an implicit copy ctor (0x141745bd0) and an
    // implicit move ctor (0x141745b60), so no destructor is user-declared
    unsigned m_progress;                          // +0x18
    bool m_complete;                              // +0x1c
    __int64 m_20;                                 // +0x20
};
MS2_CHECK_SIZE(CAdventureLevelMissionData, 0x28);

class CSAdventureLevelMission {
public:
    CSAdventureLevelMission();                    // 0x1407a8d50
    virtual ~CSAdventureLevelMission();           // 0x1407a8db0
    void FUN_1407a8e00(COutputStream& out) const;
    void FUN_1407a90e0(CInputStream& in);
    void SetMission(unsigned id, const CAdventureLevelMissionData& data);
    void ClearMissions();                         // deletes every record, then clears the map
    std::map<unsigned int, CAdventureLevelMissionData*>& GetMissions() { return m_missions; }   // inline (name invented; scenestategame.cpp 0x141748090)
    int m_kind;                                   // +0x08 (8 = none)
    int m_0c;
    std::map<unsigned int, CAdventureLevelMissionData*> m_missions; // +0x10
};
MS2_CHECK_SIZE(CSAdventureLevelMission, 0x20);
MS2_CHECK_OFFSET(CSAdventureLevelMission, m_missions, 0x10);
