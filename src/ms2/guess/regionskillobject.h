// CRegionSkillObject (RTTI name): a skill area dropped on the ground by a region skill (the 0x4c packet handler of
// CSceneStateGame creates it). It spawns the skill's effect files at every point of the area, keeps the spawned effect ids,
// re-spawns the ones the culler dropped, and shows the area's collision shapes. Member names are inferred from use. w175.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <list>
#include <utility>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/client/ms2/effectservice.h"

// The attributes of one skill level (the pointee of CRegionSkillObject::m_pAttr); only the effect files are named.
class Unk_RsAttr
{
public:
    char m_pad_00[0x28];
    CString m_strEffect;                // +0x28 spawned for every point when the skill is dropped
    CString m_strHitEffect;             // +0x30 spawned when the area is hit
    CString m_strEndEffect;             // +0x38 second looping effect (kept in m_spEffect2)
    char m_pad_40[8];
    CString m_strResetEffect;           // +0x48 spawned when the area is reset
    char m_pad_50[0x98 - 0x50];
    CString m_strLateEffect;            // +0x98 spawned once after the start tick
    bool m_bAlways;                     // +0xa0 show the effects also when the owner is not local
    bool m_bNoSpawn;                    // +0xa1 do not spawn at once, only list the points
};
MS2_CHECK_OFFSET(Unk_RsAttr, m_strEffect, 0x28);
MS2_CHECK_OFFSET(Unk_RsAttr, m_strLateEffect, 0x98);
MS2_CHECK_OFFSET(Unk_RsAttr, m_bAlways, 0xa0);

// A skill level (id, level, attributes) and its row, as handed out by the skill table.
class Unk_InventorySkillLevel : public CPtred
{
public:
    unsigned FUN_140803dc0();
    unsigned short FUN_140803df0();
    Unk_RsAttr* FUN_140803f00(int nIndex);              // attributes of one entry
};
class Unk_SkillRow : public CPtred
{
public:
    MS2Ptr<Unk_InventorySkillLevel> FUN_1407e90a0(unsigned short nLevel);
};

class CRegionSkillObject : public CPtred
{
public:
    CRegionSkillObject();                                   // 0x1416f57c0
    virtual ~CRegionSkillObject();                          // 0x1416f5930
    int FUN_1416f5a20(int nId, int nSkillId, const ATL::CAtlArray<Vector3>& kPoints, int nOwnerId, short nLevel, float fB, float fA, int nTick);
    void FUN_1416f67e0();                                   // stop every spawned effect
    void FUN_1416f6860();                                   // fade out every spawned effect
    void FUN_1416f6900();                                   // a tick hit
    void FUN_1416f6b90();                                   // reset
    int FUN_1416f6e20();                                    // the id
    void FUN_1416f6e40();                                   // end the region skill
    Vector3 FUN_1416f6ed0();                        // the first point
    void FUN_1416f6f50();                                   // per frame: respawn the culled effects
    void FUN_1416f7790();                                   // the late effect
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_SkillRow> m_spRow;                           // +0x18
    MS2Ptr<Unk_InventorySkillLevel> m_spSkill;              // +0x28 the skill (id, level)
    Unk_RsAttr* m_pAttr;                                    // +0x38
    int m_nId;                                              // +0x40
    int m_nOwnerId;                                         // +0x44
    ATL::CAtlArray<Vector3> m_points;               // +0x48 the area's points
    ATL::CAtlArray<unsigned> m_effects;                     // +0x68 the spawned effect ids
    ATL::CAtlArray<unsigned> m_loopEffects;                 // +0x88 the ones that loop
    int m_nOwnerType;                                       // +0xa8 world entity kind of the owner
    CEffectDataPtr m_spEffect;                              // +0xb0
    CEffectDataPtr m_spEffect2;                             // +0xc0
    std::list<std::pair<Vector3, unsigned> > m_pending;   // +0xd0 points waiting for their tick
    ATL::CAtlList<Vector3> m_waiting;               // +0xe0
    float m_fRotX;                                          // +0x110
    float m_fRotY;                                          // +0x114
    int m_bLocal;                                           // +0x118 the owner is a local player
    int m_bLateDone;                                        // +0x11c
    unsigned m_nStartTick;                                  // +0x120
    ATL::CAtlList<__int64> m_collisions;                    // +0x128 collision shape handles
};
MS2_CHECK_SIZE(CRegionSkillObject, 0x158);
MS2_CHECK_OFFSET(CRegionSkillObject, m_spSkill, 0x28);
MS2_CHECK_OFFSET(CRegionSkillObject, m_points, 0x48);
MS2_CHECK_OFFSET(CRegionSkillObject, m_spEffect, 0xb0);
MS2_CHECK_OFFSET(CRegionSkillObject, m_pending, 0xd0);
MS2_CHECK_OFFSET(CRegionSkillObject, m_fRotX, 0x110);
MS2_CHECK_OFFSET(CRegionSkillObject, m_collisions, 0x128);
