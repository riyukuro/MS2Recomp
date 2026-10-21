// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See bosstargetcamera.h.
// MS2-UNIT: ?\bosstargetcamera.cpp
// MS2-RANGE: 0x140a376e0-0x140a38fa0 .text$mn
// MS2-PIN: memmove_s 0x140a38e40
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\bosstargetcamera.cpp"
// The exe's memmove_s copy is a plain call (no /Oi expansion): the pragma must precede the inline definitions.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include "bosstargetcamera.h"

#include <egf/Entity.h>

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// ---- unit-local placeholders ----

extern const Unk_StreamPoint g_143a08cf8;   // NiPoint3::UNIT_Z

float FUN_14029d220(float f);                       // fabs
float FUN_14059d930(float f);                       // fabs
float FUN_140a17940(float f, float fMin, float fMax);   // clamp
float FUN_140a0fda0(float a, float b);              // max
float FUN_1409f25a0(float f);                       // cos
float FUN_1409f2310(float f);                       // sin
bool FUN_14028d470(float a, float b);               // nearly equal
float FUN_141b6fdb0(float fRatio, int nKind);       // easing curve

// @0x140a38cd0
inline float FUN_140a38cd0(float f)
{
    return FUN_14029d220(f);
}

// A game object that answers property queries (slot 5: value of a property by hash).
class Unk_BossObject
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(unsigned nHash, Unk_CameraTargetEntity** ppValue);
};

// The game context (FUN_1403ed2d0): object lookup by id.
class Unk_BossGameContext
{
public:
    Unk_BossObject* FUN_141bd1180(int nObjectId);
};
Unk_BossGameContext* FUN_1403ed2d0();

// The view of the camera manager (0x143ab3700) that the inline accessors use.
struct Unk_CameraManagerView
{
    char m_pad_000[0x138];
    Unk_StreamPoint m_138;                              // pending move input
    char m_pad_144[0x1c0 - 0x144];
    Unk_CameraTargetEntity* m_1c0;                      // the camera target
};
MS2_CHECK_OFFSET(Unk_CameraManagerView, m_138, 0x138);
MS2_CHECK_OFFSET(Unk_CameraManagerView, m_1c0, 0x1c0);

// The property cache of a client entity (egf::Entity subclass: +0xc8 caching enabled, +0xd0 map property id -> entry).
struct Unk_PropertyCacheEntry
{
    // 0x140947490 (another obj)
    Unk_PropertyCacheEntry(unsigned nId, void* pValue, unsigned nType) : m_id(nId), m_pValue(pValue), m_type(nType) {}

    unsigned m_id;
    void* m_pValue;
    unsigned m_type;
};
MS2_CHECK_SIZE(Unk_PropertyCacheEntry, 0x18);

class Unk_PropertyCacheIter
{
public:
    Unk_PropertyCacheIter();
    bool FUN_140947540(const Unk_PropertyCacheIter& other) const;     // operator==

    void* m_p;
};

class Unk_PropertyCacheMap
{
public:
    Unk_PropertyCacheIter FUN_1409481f0();                          // end()
    Unk_PropertyCacheIter FUN_140948250(const unsigned& nId);       // find
    Unk_PropertyCacheEntry& FUN_140947580(const unsigned& nId);     // operator[]

    void* m_pHead;                                                  // std::map: head node and size
    size_t m_nSize;
};

class Unk_CachedEntity : public egf::Entity
{
public:
    using egf::Entity::GetPropertyValueUnsafe;
    using egf::Entity::SetPropertyValueUnsafe;

    bool m_c8;
    Unk_PropertyCacheMap m_d0;
};
MS2_CHECK_OFFSET(Unk_CachedEntity, m_c8, 0xc8);
MS2_CHECK_OFFSET(Unk_CachedEntity, m_d0, 0xd0);

// A float table value of the client configuration (FUN_1401d3200).
struct Unk_ConfigFloat
{
    float FUN_1402bac70();
    char m_pad[0x58];
};
struct Unk_ClientConfig
{
    char m_pad_0000[0x1a80];
    Unk_ConfigFloat m_1a80;
    Unk_ConfigFloat m_1ad8;
    Unk_ConfigFloat m_1b30;
};
Unk_ClientConfig* FUN_1401d3200();

unsigned FUN_1409614a0();                                           // property type id of NiPoint3 (0xf000000f)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140a376e0
CBossTargetCamera::CBossTargetCamera(Unk_CameraOwner* pOwner, MS2Ptr<CCameraMode> pPrev)
    : CTargetCameraMode(pOwner, pPrev)
    , m_108(0)
{
    m_6c = 1.3089969f;
    m_68 = 3.1415927f;
}

// @0x140a377a0
CBossTargetCamera::~CBossTargetCamera()
{
}

// @0x140a377e0
void CBossTargetCamera::vfunc_6(int n)
{
    CCameraMode::vfunc_6(n);
    m_f0 = 0;
    Unk_StreamPoint ptEye = m_d8.m_pos;
    Unk_StreamPoint ptRot = g_143b01a60;
    Unk_StreamPoint ptTarget = FUN_140a38570();
    m_50 = m_data.m_zoomOut;
    ptEye.x = m_50 * FUN_1409f25a0(m_68) + ptTarget.x;
    ptEye.y = m_50 * FUN_1409f2310(m_68) + ptTarget.y;
    ptEye.z = m_50 * FUN_1409f2310(m_6c) + ptTarget.z;
    m_d8.m_pos = ptEye;
    ptRot = CCameraMode::FUN_140afdd40(ptTarget, ptEye, g_143a08cf8);
    m_d8.m_rot = ptRot;
    m_c0 = m_d8;
    m_setting.m_c = m_c0.m_pos;
    m_setting.m_18 = m_c0.m_rot;
    m_pOwner->FUN_140a38dc0(m_c0.m_pos);
    m_pOwner->FUN_140a38e00(m_c0.m_rot);
    m_9c = FUN_1401d3200()->m_1a80.FUN_1402bac70();
    m_a0 = FUN_1401d3200()->m_1ad8.FUN_1402bac70();
    m_a4 = FUN_1401d3200()->m_1b30.FUN_1402bac70();
}
MS2_REPLACE_METHOD(0x140a377e0, CBossTargetCamera, vfunc_6, 726, 0xE9751F50);

// @0x140a37ac0
void CBossTargetCamera::vfunc_8(double fTime)
{
    Unk_StreamPoint ptEye = m_d8.m_pos;
    Unk_StreamPoint ptRot = g_143b01a60;
    Unk_StreamPoint ptTarget = FUN_140a38570();
    Unk_StreamPoint ptMove = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d00();
    if (ptMove.FUN_140552700(g_143b01a60))
    {
        Unk_StreamPoint ptInput = ptMove;
        float fRate = 15.0f;
        float fStep = FUN_140a17940((float)fTime, 0.0f, 1.0f / fRate);
        float fMax = FUN_140a0fda0(FUN_140a38cd0(ptInput.x),
                                   FUN_140a0fda0(FUN_140a38cd0(ptInput.y), FUN_140a38cd0(ptInput.z)));
        float fScale = fStep * fMax;
        m_50 = m_50 + ptInput.y * fScale;
        if (m_50 > m_data.m_detachDistance)
            m_50 = m_data.m_zoomOut;
    }
    ptEye.x = m_50 * FUN_1409f25a0(m_68) + ptTarget.x;
    ptEye.y = m_50 * FUN_1409f2310(m_68) + ptTarget.y;
    ptEye.z = m_50 * FUN_1409f2310(m_6c) + ptTarget.z;
    m_d8.m_pos = ptEye;
    ptRot = CCameraMode::FUN_140afdd40(ptTarget, ptEye, g_143a08cf8);
    m_d8.m_rot = ptRot;
    vfunc_39(fTime);
    Unk_CameraManager::FUN_1409478c0()->FUN_140a38d90(g_143b01a60);
}
MS2_REPLACE_METHOD(0x140a37ac0, CBossTargetCamera, vfunc_8, 772, 0xEFDF51B9);

// @0x140a37dd0
void CBossTargetCamera::vfunc_39(double fTime)
{
    if (m_f0 != 0)
    {
        Unk_NiPoint3 ptDelta(m_d8.m_pos.FUN_140965c40(m_c0.m_pos));
        float fDist = ptDelta.FUN_140967ac0();
        float fBlend = 0.0f;
        if (m_fc != 0)
        {
            if (fDist >= 10.0f)
            {
                m_fc = 0;
            }
            else
            {
                m_100 = (float)((double)m_100 + fTime);
                if (m_100 >= 3.0f)
                {
                    fBlend = 1.0f;
                    m_fc = 0;
                }
                else
                {
                    fBlend = FUN_141b6fdb0(m_100 / 3.0f, 3);
                }
            }
        }
        else
        {
            if (!FUN_14028d470(fDist, 0) && fDist <= 10.0f)
            {
                m_fc = 1;
                m_100 = 0;
                fBlend = 0.0f;
            }
        }
        if (FUN_14028d470(fDist, 0))
        {
            m_c0 = m_d8;
        }
        else
        {
            float fSpeed = FUN_14059d930(m_a4) * (float)fTime;
            if (m_a0 != m_9c)
            {
                if (FUN_14059d930(m_a0 - m_9c) < fSpeed)
                {
                    m_a0 = m_9c;
                }
                else
                {
                    if (m_a0 > m_9c)
                        m_a0 = m_a0 - fSpeed;
                    else
                        m_a0 = m_a0 + fSpeed;
                }
            }
            float fLerp = m_data.m_lerpSpeedMax;
            if (fDist >= m_data.m_lerpDelayDistanceMax)
            {
                fLerp = m_data.m_lerpSpeedMin;
            }
            else
            {
                if (m_data.m_lerpDelayDistanceMin <= fDist)
                {
                    float fRange = m_data.m_lerpDelayDistanceMax - m_data.m_lerpDelayDistanceMin;
                    if (!FUN_14028d470(fRange, 0))
                    {
                        float fRatio = (fDist - m_data.m_lerpDelayDistanceMin) / fRange;
                        fLerp = fRatio * m_data.m_lerpSpeedMin + (1.0f - fRatio) * m_data.m_lerpSpeedMax;
                    }
                }
            }
            float fT = (float)fTime * fDist * fLerp + fBlend;
            if (fT > 1.0f)
            {
                m_c0 = m_d8;
            }
            else
            {
                m_c0.m_pos = m_c0.m_pos.FUN_14097fd50(FUN_1409ab5c0(fT, m_d8.m_pos.FUN_140965c40(m_c0.m_pos)));
                if (m_c0.m_rot.FUN_140552700(m_d8.m_rot))
                    m_c0.m_rot = CCameraMode::FUN_140afdec0(fT, m_c0.m_rot, m_d8.m_rot);
            }
        }
    }
    else
    {
        m_c0 = m_d8;
        m_f0 = 1;
        m_f4 = 0;
    }
    m_setting.m_c = m_c0.m_pos;
    m_setting.m_18 = m_c0.m_rot;
    m_pOwner->FUN_140a38dc0(m_c0.m_pos);
    m_pOwner->FUN_140a38e00(m_c0.m_rot);
}
MS2_REPLACE_METHOD(0x140a37dd0, CBossTargetCamera, vfunc_39, 1577, 0xE3FFB635);

// @0x140a38400
void CBossTargetCamera::vfunc_24(Unk_CameraTargetEntity* p, int n)
{
    Unk_CameraTargetEntity* pCur = Unk_CameraManager::FUN_1409478c0()->FUN_140a38d60();
    if (pCur != NULL && n != 0)
        vfunc_6(0);
}
MS2_REPLACE_METHOD(0x140a38400, CBossTargetCamera, vfunc_24, 75, 0x8ECD44B9);

// @0x140a38460
float CBossTargetCamera::vfunc_27()
{
    return m_data.m_viewOffsetZ;
}
MS2_REPLACE_METHOD(0x140a38460, CBossTargetCamera, vfunc_27, 19, 0xFEFAD5C5);

// @0x140a38480
void CBossTargetCamera::vfunc_36(Unk_CameraPreset* pPreset)
{
    if (pPreset != NULL)
    {
        CCameraMode::vfunc_36(pPreset);
        CBossTargetCameraData* pData = dynamic_cast<CBossTargetCameraData*>(reinterpret_cast<CMapCameraData*>(pPreset));
        if (pData != NULL)
        {
            m_data = *pData;
            m_6c = (pData->m_vAngle * 3.1415927f) / 180.0f;
            m_68 = (pData->m_hAngle * 3.1415927f) / 180.0f;
        }
    }
}
MS2_REPLACE_METHOD(0x140a38480, CBossTargetCamera, vfunc_36, 189, 0xAF6BDD8D);

// ---- the target point: the boss, nudged towards the player when both are within reach ----

// @0x140a38a00
static Unk_CameraTargetEntity* FUN_140a38a00(Unk_BossObject* pObject)
{
    Unk_CameraTargetEntity* pValue = NULL;
    if (pObject != NULL && pObject->vfunc_5(0x6200028, &pValue))
        return pValue;
    else
        return NULL;
}

// @0x140a38570
Unk_StreamPoint CBossTargetCamera::FUN_140a38570()
{
    Unk_StreamPoint ptRet(0.0f, 0.0f, 0.0f);
    Unk_StreamPoint ptOther(0.0f, 0.0f, 0.0f);
    Unk_CameraTargetEntity* pTarget = vfunc_25();
    if (pTarget != NULL)
    {
        ptOther = ptRet = pTarget->vfunc_18().FUN_14097fd50(Unk_StreamPoint(0.0f, 0.0f, m_data.m_viewOffsetZ));
        m_50 = m_data.m_zoomOut;
    }
    Unk_BossObject* pObject = FUN_1403ed2d0()->FUN_141bd1180(m_108);
    if (pObject != NULL)
    {
        Unk_CameraTargetEntity* pBoss = FUN_140a38a00(pObject);
        if (pBoss != NULL)
        {
            float fDist = 0.0f;
            ptOther = pBoss->vfunc_18().FUN_14097fd50(Unk_StreamPoint(0.0f, 0.0f, m_data.m_viewOffsetZ));
            fDist = ptOther.FUN_140965c40(ptRet).FUN_140967ac0() + m_data.m_distanceOffset;
            if (fDist > m_data.m_detachDistance)
            {
                fDist = m_data.m_zoomOut;
                return ptRet;
            }
            m_50 = fDist;
        }
        else
        {
            return ptRet;
        }
    }
    else
    {
        return ptRet;
    }
    Unk_StreamPoint ptDir = ptOther.FUN_140965c40(ptRet);
    float fLen = ptDir.FUN_140968990();
    Unk_StreamPoint ptHalf = ptDir.FUN_14097fc90(fLen);
    ptHalf.z = ptHalf.z * 0.5f;
    return ptRet.FUN_14097fd50(ptHalf);
}
MS2_REPLACE_METHOD(0x140a38570, CBossTargetCamera, FUN_140a38570, 822, 0xD000EB82);

// destructor body of a class with two containers at +0x18/+0x38 (no caller in the exe, so the owner is unknown)
class Unk_ListA { public: void FUN_140a3f3c0(); };
class Unk_ListB { public: void FUN_140a3f320(); };
class Unk_TwoLists
{
public:
    void FUN_140a38f60();
    char m_pad[0x18];
    Unk_ListA m_18;
    char m_pad2[0x1f];
    Unk_ListB m_38;
};

// ---- inline helpers of the entity property cache ----

// @0x140a388b0
static void FUN_140a388b0(Unk_CachedEntity* pEntity, unsigned nId, const Unk_StreamPoint& pt)
{
    if (pEntity->m_c8)
    {
        if (pEntity->m_d0.FUN_140948250(nId).FUN_140947540(pEntity->m_d0.FUN_1409481f0()))
        {
            Unk_StreamPoint ptOld;
            pEntity->GetPropertyValueUnsafe(nId, &ptOld, FUN_1409614a0());
            pEntity->m_d0.FUN_140947580(nId) = Unk_PropertyCacheEntry(nId, new Unk_StreamPoint(ptOld), FUN_1409614a0());
        }
    }
}

// @0x140a38a50
static void FUN_140a38a50(Unk_CachedEntity* pEntity, unsigned nId, const Unk_StreamPoint& pt)
{
    FUN_140a388b0(pEntity, nId, pt);
    pEntity->SetPropertyValueUnsafe(nId, const_cast<Unk_StreamPoint*>(&pt), FUN_1409614a0());
}

// ---- inline accessors of the camera owner and the camera manager ----

// @0x140a38d00
Unk_StreamPoint Unk_CameraManager::FUN_140a38d00()
{
    return reinterpret_cast<Unk_CameraManagerView*>(this)->m_138;
}

// @0x140a38d60
Unk_CameraTargetEntity* Unk_CameraManager::FUN_140a38d60()
{
    return reinterpret_cast<Unk_CameraManagerView*>(this)->m_1c0;
}

// @0x140a38d90
void Unk_CameraManager::FUN_140a38d90(Unk_StreamPoint pt)
{
    reinterpret_cast<Unk_CameraManagerView*>(this)->m_138 = pt;
}

// @0x140a38dc0
void Unk_CameraOwner::FUN_140a38dc0(Unk_StreamPoint pt)
{
    if (m_10)
        FUN_140a38a50(reinterpret_cast<Unk_CachedEntity*>(m_10), 0xfd95ca52, pt);
}

// @0x140a38e00
void Unk_CameraOwner::FUN_140a38e00(Unk_StreamPoint pt)
{
    if (m_10)
        FUN_140a38a50(reinterpret_cast<Unk_CachedEntity*>(m_10), 0x68c7c29d, pt);
}

// ---- inline functions of the exe that nothing in this unit calls ----

// @0x140a38550
void CBossTargetCamera::FUN_140a38550(int nObjectId)
{
    m_108 = nObjectId;
}

MS2_EMIT_CRT_MEMMOVE_S();

// @0x140a38f60
void Unk_TwoLists::FUN_140a38f60()
{
    m_18.FUN_140a3f3c0();
    m_38.FUN_140a3f320();
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x140a38cd0, FUN_140a38cd0, 26, 0x621EDF76);
MS2_REPLACE(0x140a38a00, FUN_140a38a00, 73, 0x90816278);
MS2_REPLACE(0x140a38a50, FUN_140a38a50, 69, 0x42B5A958);
MS2_REPLACE_METHOD(0x140a38d60, Unk_CameraManager, FUN_140a38d60, 18, 0x7817FBF0);
MS2_REPLACE_METHOD(0x140a38550, CBossTargetCamera, FUN_140a38550, 25, 0x7D8CAC3E);
MS2_REPLACE_METHOD(0x140a38f60, Unk_TwoLists, FUN_140a38f60, 48, 0x024294FF);

