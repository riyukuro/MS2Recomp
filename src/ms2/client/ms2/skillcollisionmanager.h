// skillcollisionmanager.h - CSkillCollisionManager (RTTI name): owns the debug collision shapes of skill areas.
// Header name assumed; method names are invented from use. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
//   +0x08 m_mapCache  CRBMap<CStringA, CollisionPtr>: shapes cached by "<skill>,<id>,<level>,<a>,<b>" (CRBMap(10))
//   +0x38 m_mapActive CAtlMap<__int64, CollisionPtr>: the shapes currently shown, keyed by a generated handle
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cbasecollision.h"
#include "ms2/commonfiles/os.h"

class PCBase;
class Unk_SkillSrc;
class Unk_ColInfo;
class AdditionalLevelData;
namespace efd { class Point3; } typedef efd::Point3 Vector3;

class CSkillCollisionManager : public TSingleton<CSkillCollisionManager>
{
public:
    typedef MS2Ptr<CBaseCollision> CollisionPtr;
    typedef ATL::CRBMap<CStringA, CollisionPtr> CacheMap;
    typedef ATL::CAtlMap<__int64, CollisionPtr> ActiveMap;

    CSkillCollisionManager();                           // 0x141754490
    virtual ~CSkillCollisionManager();                  // 0x141754520

    // 0x141754580: the cached shape of a skill attribute (rebuilt when the shape kind changed). `this` is used.
    CollisionPtr GetCached(Unk_SkillSrc* pSrc, int nLevel, int nIndex, void* pUnused, float fZOffset);
    void Tick();                                        // 0x141755010: draws the active shapes, drops the expired ones
    // 0x1417551b0 / 0x141755670: build an uncached shape (`this` unused).
    CollisionPtr Create(Unk_SkillSrc* pSrc, int nLevel, int nIndex, void* pUnused, float fZOffset);
    CollisionPtr CreateFromInfo(Unk_ColInfo* pInfo, float fZOffset);
    __int64 Add(CollisionPtr spShape);                  // 0x141755ac0: activates a shape, returns its handle (0 = none)
    void Remove(__int64 nHandle);                       // 0x141755b50
    void Touch(__int64 nHandle);                        // 0x141755bd0: restarts the shape's display time
    CollisionPtr Get(__int64 nHandle);                  // 0x141755c50
    // 0x141755cd0: shows the skill's shape at a position / direction (`this` unused).
    void Show(PCBase* pActor, MS2Ptr<AdditionalLevelData> spSkill, const Vector3& kPos, const Vector3& kDir);

    MS2_LAYOUT_FRIEND;
    CacheMap m_mapCache;                                // +0x08
    ActiveMap m_mapActive;                              // +0x38
};
MS2_CHECK_SIZE(CSkillCollisionManager, 0x80);
MS2_CHECK_OFFSET(CSkillCollisionManager, m_mapCache, 0x08);
MS2_CHECK_OFFSET(CSkillCollisionManager, m_mapActive, 0x38);
