// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CRegionSkillObject: a skill area on the ground (the effect files
// spawned at every point of the area, the re-spawn of the culled ones, the collision shapes) and the std::list / ATL::CAtlList
// glue over its Vector3 points. The unit name is a guess (queue row ?\regionskillobject.cpp).
// MS2-UNIT: ?\regionskillobject.cpp
// MS2-FUNCTIONAL: CRegionSkillObject::FUN_1416f5a20 (Init) is behaviour-equivalent; the frame temp layout of the collision-shape loops is not reproduced
// MS2-RANGE: 0x1416f57c0-0x1416f8f46 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0AEAUUnk_StreamPoint@@AEAI$0A@@?$pair@UUnk_StreamPoint@@I@std@@QEAA@AEAUUnk_StreamPoint@@AEAI@Z 0x1416f7a10 ; unique
// MS2-PIN: ??$make_pair@AEAUUnk_StreamPoint@@AEAI@std@@YA?AU?$pair@UUnk_StreamPoint@@I@0@AEAUUnk_StreamPoint@@AEAI@Z 0x1416f7d00 ; unique
// MS2-PIN: ??4?$MS2Ptr@VCEffectData@@@@QEAAAEAV0@H@Z 0x1416f8070 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/guess/regionskillobject.h"
#include "ms2/placeholder/cbasecollision.h"
#include "ms2/client/ms2/skillcollisionmanager.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects and unrecovered callees --------------------------------------------------------------
class Unk_RsSkillTable { public: MS2Ptr<Unk_SkillRow> FUN_1407ee1d0(int nSkillId); };
Unk_RsSkillTable* FUN_1401958b0();

// The world service (0x1403ed2d0): the entity kind of an id, the actor of an id.
class Unk_RsActor;
class Unk_RsWorld
{
public:
    int FUN_141bd19d0(int nId);
    Unk_RsActor* FUN_141bd1200(int nId);
};
Unk_RsWorld* FUN_1403ed2d0();
// The local session (0x1409f7c90): zero when the id is a local player.
class Unk_RsSession { public: int FUN_14161ce60(int nId); };
Unk_RsSession* FUN_1409f7c90();
unsigned FUN_141472bc0();                                       // the tick counter

// The game settings (0x1401d3200); the fade time of a region effect.
class Unk_RsFloatVar { public: float FUN_1402bac70(); };
class Unk_RsConfig
{
public:
    char m_pad_00[0x1ce8];
    Unk_RsFloatVar m_fFade;                                     // +0x1ce8
};
Unk_RsConfig* FUN_1401d3200();

CEffectService* FUN_1403ed280();                                // the effect service
EffectDataManager* FUN_1411b1dd0();                             // the effect file cache

// The effect culler (0x14119f490): is this effect visible at a transform? (the data pointer is passed by value)
class Unk_RsCuller { public: int FUN_1411b8870(CEffectDataPtr spData, int nOwnerType, NiTransform* pXform); };
Unk_RsCuller* FUN_14119f490();

// The skill collision manager singleton (0x141469a90).
CSkillCollisionManager* FUN_141469a90();
extern bool DAT_143ae95e0;
extern bool DAT_143ae95e1;
extern Vector3 DAT_143b01a60;                           // the zero point

// efd::Point3 / NiPoint3 helpers called out of line.
struct Unk_RsNiPoint3 : public Vector3
{
    Unk_RsNiPoint3(const Vector3& pt);                  // 0x14027dcf0
};
void FUN_14097faa0(NiPoint3* pDst, const Unk_RsNiPoint3* pSrc); // NiPoint3::operator=
struct Unk_RsRot : public Vector3 { Unk_RsRot(float x, float y, float z); };   // 0x14097f250

// The skill source of a skill level, as the collision manager takes it (0x140932d90).
class Unk_SkillSrc;
Unk_SkillSrc* FUN_140932d90(MS2Ptr<Unk_InventorySkillLevel>* pLevel);

// ---- CRegionSkillObject ---------------------------------------------------------------------------------------------------
// @0x1416f57c0
CRegionSkillObject::CRegionSkillObject() : m_pAttr(0), m_waiting(10), m_bLateDone(0), m_nStartTick(0), m_collisions(10)
{
    m_spEffect = 0;
    m_spEffect2 = 0;
    m_bLocal = 1;
}

// @0x1416f5930
CRegionSkillObject::~CRegionSkillObject()
{
}

// @0x1416f5a20
int CRegionSkillObject::FUN_1416f5a20(int nId, int nOwnerId, const ATL::CAtlArray<Vector3>& kPoints, int nSkillId, short nLevel, float fRotX, float fRotY, int nTick)
{
    m_nId = nId;
    m_nOwnerId = nOwnerId;
    m_fRotX = fRotX;
    m_fRotY = fRotY;
    m_points.Copy(kPoints);
    m_nStartTick = nTick;
    m_spRow = FUN_1401958b0()->FUN_1407ee1d0(nSkillId);
    if (m_spRow.IsNull())
        return 0;
    m_spSkill = m_spRow->FUN_1407e90a0(nLevel);
    if (m_spSkill.IsNull())
        return 0;
    m_pAttr = m_spSkill->FUN_140803f00(0);
    if (m_pAttr == 0)
        return 0;

    int nEffect2;
    int nEffect;
    m_nOwnerType = FUN_1403ed2d0()->FUN_141bd19d0(m_nOwnerId);
    m_bLocal = (FUN_1409f7c90()->FUN_14161ce60(m_nOwnerId) == 0);
    if (!m_pAttr->m_strEffect.IsEmpty())
    {
        m_spEffect = FUN_1411b1dd0()->FUN_14119f870(m_pAttr->m_strEffect);
        if (m_spEffect.get() != 0)
        {
            for (unsigned i = 0; i < m_points.GetCount(); i++)
            {
                NiTransform xf;
                xf.MakeIdentity();
                Unk_RsNiPoint3 niPt(m_points[i]);
                FUN_14097faa0(&xf.m_Translate, &niPt);
                xf.m_Rotate.FromEulerAnglesXYZ(m_fRotX, 0.0f, (-m_fRotY * 3.1415927f) / 180.0f);
                Unk_EffectTarget kTarget;
                kTarget.m_strName = m_pAttr->m_strEffect;
                kTarget.m_nKind = m_nOwnerType;
                kTarget.m_pXform = &xf;
                kTarget.m_b31 = m_pAttr->m_bAlways;
                kTarget.m_nRandomIndex = m_nId;
                nEffect = 0;
                if ((m_bLocal != 0 || kTarget.m_b31) && !m_pAttr->m_bNoSpawn)
                    nEffect = FUN_1403ed280()->FUN_1411a49c0(kTarget);
                if (nEffect != 0)
                {
                    m_effects.Add(nEffect);
                }
                else
                {
                    unsigned nTime = FUN_141472bc0();
                    if (m_pAttr->m_bNoSpawn)
                        nTime = nTick;
                    m_pending.push_back(std::make_pair(m_points[i], nTime));
                }
            }
        }
    }
    if (!m_pAttr->m_strEndEffect.IsEmpty())
    {
        m_spEffect2 = FUN_1411b1dd0()->FUN_14119f870(m_pAttr->m_strEndEffect);
        if (m_spEffect2.get() != 0)
        {
            for (unsigned i = 0; i < m_points.GetCount(); i++)
            {
                NiTransform xf;
                xf.MakeIdentity();
                Unk_RsNiPoint3 niPt(m_points[i]);
                FUN_14097faa0(&xf.m_Translate, &niPt);
                xf.m_Rotate.FromEulerAnglesXYZ(m_fRotX, 0.0f, (-m_fRotY * 3.1415927f) / 180.0f);
                Unk_EffectTarget kTarget;
                kTarget.m_strName = m_pAttr->m_strEndEffect;
                kTarget.m_nKind = m_nOwnerType;
                kTarget.m_pXform = &xf;
                kTarget.m_nRandomIndex = m_nId;
                nEffect2 = 0;
                if (m_bLocal != 0)
                    nEffect2 = FUN_1403ed280()->FUN_1411a49c0(kTarget);
                if (nEffect2 != 0)
                {
                    m_effects.Add(nEffect2);
                    m_loopEffects.Add(nEffect2);
                    FUN_1403ed280()->FUN_1411a68f0(nEffect2, false);
                }
                else
                {
                    m_waiting.AddTail(m_points[i]);
                }
            }
        }
    }
    FUN_1416f6e40();
    FUN_1416f7790();
    if (DAT_143ae95e1 || DAT_143ae95e0)
    {
        Unk_RsActor* pActor = FUN_1403ed2d0()->FUN_141bd1200(m_nOwnerId);
        if (pActor != 0)
        {
            CSkillCollisionManager::CollisionPtr spShape;
            for (unsigned i = 0; i < m_points.GetCount(); i++)
            {
                Unk_RsNiPoint3 niPt(m_points[i]);
                Unk_RsRot rot(m_fRotX, 0.0f, m_fRotY);
                spShape = FUN_141469a90()->Create(FUN_140932d90(&m_spSkill), 0, 0, pActor, 0.0f);
                spShape->vfunc_3(niPt, rot, 1.0f);
                m_collisions.AddTail(FUN_141469a90()->Add(spShape));
            }
        }
        else
        {
            if (DAT_143ae95e1)
            {
                CSkillCollisionManager::CollisionPtr spShape;
                for (unsigned i = 0; i < m_points.GetCount(); i++)
                {
                    Unk_RsNiPoint3 niPt(m_points[i]);
                    Unk_RsRot rot(m_fRotX, 0.0f, m_fRotY);
                    spShape = FUN_141469a90()->Create(FUN_140932d90(&m_spSkill), 0, 0, 0, 0.0f);
                    spShape->vfunc_3(niPt, rot, 1.0f);
                    m_collisions.AddTail(FUN_141469a90()->Add(spShape));
                }
            }
        }
    }
    return 1;
}

// @0x1416f67e0
void CRegionSkillObject::FUN_1416f67e0()
{
    for (unsigned i = 0; i < m_effects.GetCount(); i++)
        FUN_1403ed280()->FUN_1411a6060(m_effects[i]);
}

// @0x1416f6860
void CRegionSkillObject::FUN_1416f6860()
{
    for (unsigned i = 0; i < m_effects.GetCount(); i++)
        FUN_1403ed280()->FUN_1411a67f0(m_effects[i], FUN_1401d3200()->m_fFade.FUN_1402bac70());
}

// @0x1416f6900
void CRegionSkillObject::FUN_1416f6900()
{
    Unk_RsAttr* pAttr = m_spSkill->FUN_140803f00(0);
    if (pAttr == 0)
        return;
    for (unsigned i = 0; i < m_loopEffects.GetCount(); i++)
        FUN_1403ed280()->FUN_1411a68f0(m_loopEffects[i], false);
    if (pAttr->m_strHitEffect.IsEmpty())
        return;
    bool bAlways = pAttr->m_bAlways;
    if (m_bLocal != 0 || bAlways)
    {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = pAttr->m_strHitEffect;
        kTarget.m_nKind = m_nOwnerType;
        kTarget.m_b31 = bAlways;
        kTarget.m_nRandomIndex = m_nId;
        for (unsigned i = 0; i < m_points.GetCount(); i++)
        {
            NiTransform xf;
            xf.MakeIdentity();
            Unk_RsNiPoint3 niPt(m_points[i]);
            FUN_14097faa0(&xf.m_Translate, &niPt);
            xf.m_Rotate.FromEulerAnglesXYZ(m_fRotX, 0.0f, (-m_fRotY * 3.1415927f) / 180.0f);
            kTarget.m_pXform = &xf;
            FUN_1403ed280()->FUN_1411a4a00(kTarget);
        }
    }
}

// @0x1416f6b90
void CRegionSkillObject::FUN_1416f6b90()
{
    for (POSITION pos = m_collisions.GetHeadPosition(); pos != 0; m_collisions.GetNext(pos))
    {
        __int64* pHandle = &m_collisions.GetAt(pos);
        FUN_141469a90()->Touch(*pHandle);
    }
    Unk_RsAttr* pAttr = m_spSkill->FUN_140803f00(0);
    if (pAttr == 0)
        return;
    if (pAttr->m_strResetEffect.IsEmpty())
        return;
    if (m_bLocal != 0 || pAttr->m_bAlways)
    {
        Unk_EffectTarget kTarget;
        kTarget.m_strName = pAttr->m_strResetEffect;
        kTarget.m_nKind = m_nOwnerType;
        kTarget.m_b31 = pAttr->m_bAlways;
        kTarget.m_nRandomIndex = m_nId;
        for (unsigned i = 0; i < m_points.GetCount(); i++)
        {
            NiTransform xf;
            xf.MakeIdentity();
            Unk_RsNiPoint3 niPt(m_points[i]);
            FUN_14097faa0(&xf.m_Translate, &niPt);
            xf.m_Rotate.FromEulerAnglesXYZ(m_fRotX, 0.0f, (-m_fRotY * 3.1415927f) / 180.0f);
            kTarget.m_pXform = &xf;
            FUN_1403ed280()->FUN_1411a4a00(kTarget);
        }
    }
}

// @0x1416f6e20
int CRegionSkillObject::FUN_1416f6e20()
{
    return m_nId;
}

// @0x1416f6e40
void CRegionSkillObject::FUN_1416f6e40()
{
    for (unsigned i = 0; i < m_loopEffects.GetCount(); i++)
        FUN_1403ed280()->FUN_1411a68f0(m_loopEffects[i], true);
}

// @0x1416f6ed0
Vector3 CRegionSkillObject::FUN_1416f6ed0()
{
    if (m_points.IsEmpty())
        return DAT_143b01a60;
    return m_points[0];
}

// @0x1416f6f50
void CRegionSkillObject::FUN_1416f6f50()
{
    if (m_spEffect.get() != 0)
    {
        ATL::CAtlArray<Vector3> kSpawned;
        std::list<std::pair<Vector3, unsigned> >::iterator it = m_pending.begin();
        for (; it != m_pending.end(); ++it)
        {
            unsigned nTime = it->second;
            if (FUN_141472bc0() < nTime)
                continue;
            {
                Vector3 pt = it->first;
                NiTransform xf;
                xf.MakeIdentity();
                Unk_RsNiPoint3 niPt(pt);
                FUN_14097faa0(&xf.m_Translate, &niPt);
                xf.m_Rotate.FromEulerAnglesXYZ(m_fRotX, 0.0f, (-m_fRotY * 3.1415927f) / 180.0f);
                bool bAlways = m_pAttr->m_bAlways;
                if (FUN_14119f490()->FUN_1411b8870(m_spEffect, m_nOwnerType, &xf) == 0 && (m_bLocal != 0 || bAlways))
                {
                    Unk_EffectTarget kTarget;
                    kTarget.m_strName = m_pAttr->m_strEffect;
                    kTarget.m_nKind = m_nOwnerType;
                    kTarget.m_pXform = &xf;
                    kTarget.m_b31 = bAlways;
                    kTarget.m_nRandomIndex = m_nId;
                    int nEffect = FUN_1403ed280()->FUN_1411a49c0(kTarget);
                    if (nEffect != 0)
                    {
                        m_effects.Add(nEffect);
                        kSpawned.Add(pt);
                    }
                }
            }
        }
        for (unsigned i = 0; i < kSpawned.GetCount(); i++)
        {
            Vector3 ptDone = kSpawned[i];
            for (it = m_pending.begin(); it != m_pending.end(); ++it)
            {
                Vector3 ptCur = it->first;
                if (ptDone.FUN_140552690(ptCur))
                {
                    m_pending.erase(it);
                    break;
                }
            }
        }
    }
    if (m_spEffect2.get() != 0)
    {
        ATL::CAtlArray<Vector3> kSpawned;
        for (POSITION pos = m_waiting.GetHeadPosition(); pos != 0; m_waiting.GetNext(pos))
        {
            Vector3 pt = m_waiting.GetAt(pos);
            NiTransform xf;
            xf.MakeIdentity();
            Unk_RsNiPoint3 niPt(pt);
            FUN_14097faa0(&xf.m_Translate, &niPt);
            xf.m_Rotate.FromEulerAnglesXYZ(m_fRotX, 0.0f, (-m_fRotY * 3.1415927f) / 180.0f);
            if (FUN_14119f490()->FUN_1411b8870(m_spEffect2, m_nOwnerType, &xf) == 0 && m_bLocal != 0)
            {
                Unk_EffectTarget kTarget;
                kTarget.m_strName = m_pAttr->m_strEndEffect;
                kTarget.m_nKind = m_nOwnerType;
                kTarget.m_pXform = &xf;
                kTarget.m_nRandomIndex = m_nId;
                int nEffect = FUN_1403ed280()->FUN_1411a49c0(kTarget);
                if (nEffect != 0)
                {
                    m_effects.Add(nEffect);
                    m_loopEffects.Add(nEffect);
                    FUN_1403ed280()->FUN_1411a68f0(nEffect, true);
                    kSpawned.Add(pt);
                }
            }
        }
        for (unsigned i = 0; i < kSpawned.GetCount(); i++)
        {
            Vector3 ptDone = kSpawned[i];
            for (POSITION posCur = m_waiting.GetHeadPosition(); posCur != 0; m_waiting.GetNext(posCur))
            {
                Vector3 ptCur = m_waiting.GetAt(posCur);
                if (ptDone.FUN_140552690(ptCur))
                {
                    m_waiting.RemoveAt(posCur);
                    break;
                }
            }
        }
    }
    FUN_1416f7790();
}

// @0x1416f7790
void CRegionSkillObject::FUN_1416f7790()
{
    if (m_bLateDone != 0)
        return;
    if (m_pAttr->m_strLateEffect.IsEmpty())
        return;
    unsigned nNow = FUN_141472bc0();
    if (m_nStartTick > nNow)
        return;
    {
        bool bAlways = m_pAttr->m_bAlways;
        if (m_bLocal != 0 || bAlways)
        {
            Unk_EffectTarget kTarget;
            kTarget.m_strName = m_pAttr->m_strLateEffect;
            kTarget.m_nKind = m_nOwnerType;
            kTarget.m_b31 = bAlways;
            kTarget.m_nRandomIndex = m_nId;
            for (unsigned i = 0; i < m_points.GetCount(); i++)
            {
                NiTransform xf;
                xf.MakeIdentity();
                Unk_RsNiPoint3 niPt(m_points[i]);
                FUN_14097faa0(&xf.m_Translate, &niPt);
                xf.m_Rotate.FromEulerAnglesXYZ(m_fRotX, 0.0f, (-m_fRotY * 3.1415927f) / 180.0f);
                kTarget.m_pXform = &xf;
                FUN_1403ed280()->FUN_1411a4a00(kTarget);
            }
        }
        m_bLateDone = 1;
    }
}
