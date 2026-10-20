// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See bonerotateinterpolator.h.
// MS2-UNIT: client\ms2\bonerotateinterpolator.cpp
// MS2-RANGE: 0x1400c2ff0-0x1400c3320 .text$di
// MS2-RANGE: 0x140a31af0-0x140a365c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??DNiTransform@@QEBA?AV0@AEBV0@@Z 0x140a33de0 ; unique
// MS2-PIN: ?IsRotateValid@NiQuatTransform@@QEBA_NXZ 0x140a340d0 ; unique
// MS2-PIN: ?IsScaleValid@NiQuatTransform@@QEBA_NXZ 0x140a34110 ; unique
// MS2-PIN: ?IsTranslateValid@NiQuatTransform@@QEBA_NXZ 0x140a34150 ; unique
// MS2-PIN: ?SetRotate@NiQuatTransform@@QEAAXAEBVNiMatrix3@@@Z 0x140a342a0 ; unique
// MS2-PIN: ?SetRotate@NiQuatTransform@@QEAAXAEBVNiQuaternion@@@Z 0x140a342e0 ; unique
// MS2-PIN: ?SetRotateValid@NiQuatTransform@@IEAAX_N@Z 0x140a34320 ; unique
// MS2-PIN: ??4NiTransform@@QEAAAEAV0@$$QEAV0@@Z 0x140a35bd0 ; unique
// MS2-PIN: ?CompareElementsOrdered@?$CDefaultCompareTraits@W4Unk_BrMode@@@ATL@@SAHAEBW4Unk_BrMode@@0@Z 0x140a35d90 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GBoneRotateInterpolator@@UEAAPEAXI@Z 0x140a33f30
// MS2-PIN: ??_GCBoneRotateManager@@UEAAPEAXI@Z 0x140a35cc0
// MS2-PIN: ??0NiQuaternion@@QEAA@XZ 0x140a332b0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\bonerotateinterpolator.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include "bonerotateinterpolator.h"

#include <efd/ILogger.h>
#include <efd/Helpers.h>
#include <NiActorManager.h>
#include <NiFixedString.h>
#include <math.h>
#include <float.h>
#include "gameobject.h"
#include "worldservice.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140a31af0
// MS2-FUNCTIONAL: unreferenced CRT memcpy_s copy: source spelling differs
static __inline errno_t ms2_memcpy_s_copy1(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy1)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy1;
// @0x140a34670
// MS2-FUNCTIONAL: unreferenced CRT memcpy_s copy: source spelling differs
static __inline errno_t ms2_memcpy_s_copy2(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy2)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy2;

// ---- out-of-unit callees (unit-local views) ----
extern unsigned char DAT_143afc898;                              // assertions throw when set
extern "C" float(__cdecl* __imp_acosf)(float);       // acosf through the CRT import table (the exe calls it indirectly)
extern const efd::Matrix3 DAT_143a09600;                // efd::Matrix3::IDENTITY
class Unk_BrAnimSvc { public: NiActorManager* FUN_140999440(const egf::EntityID& kId); };   // the animation service
Unk_BrAnimSvc* FUN_141b6f910();
NiAVObject* FUN_141b6ef70(egf::EntityID kId);           // the scene node of an entity
GameObject* FUN_141bd0fa0(WorldService* p, const egf::EntityID& kId);
int FUN_1409a8f90(float* pValue);                       // the float is a finite number
void FUN_140a01250(efd::Point3 kEuler, efd::Point3* pForward, efd::Point3* pRight);   // the axes of the euler rotation

// ---- header statics of neighbouring TUs (.text$di) ----
// @0x1400c2ff0
const NiRTTI BoneRotateInterpolator::ms_RTTI("BoneRotateInterpolator", &NiTransformInterpolator::ms_RTTI);

// @0x1400c3020
static CString s_sortTypeNames1[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400c30e0
static CString s_strSkill1 = "skill";
// @0x1400c3110
static CString s_strStun1 = "stun";
// @0x1400c3140
static Unk_1402a9d70 s_condition1(17, 0.75f, 0.25f, 2.25f, 10);

// @0x1400c3190
static CString s_sortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
// @0x1400c3250
static CString s_strSkill2 = "skill";
// @0x1400c3280
static CString s_strStun2 = "stun";
// @0x1400c32b0
static egf::EntityID s_kNullId(0);
// @0x1400c32d0
static Unk_1402a9d70 s_condition2(17, 0.75f, 0.25f, 2.25f, 10);

// ---- .text$mn ----

// @0x140a33ff0
static inline bool Unk_IsFinite(const efd::Point3& kPoint)
{
    if ((_fpclass((double)kPoint.x) & 0x207) != 0 || (_fpclass((double)kPoint.y) & 0x207) != 0 ||
        (_fpclass((double)kPoint.z) & 0x207) != 0)
        return false;
    else
        return true;
}

// @0x140a34050
static inline int Unk_IsFiniteQuat(const efd::Quaternion& kQuat)
{
    if ((_fpclass((double)kQuat.m_x) & 0x207) != 0 || (_fpclass((double)kQuat.m_y) & 0x207) != 0 ||
        (_fpclass((double)kQuat.m_z) & 0x207) != 0 || (_fpclass((double)kQuat.m_w) & 0x207) != 0)
        return 0;
    else
        return 1;
}

// @0x140a34650
static inline float Unk_Acos(float fValue)
{
    return __imp_acosf(fValue);
}

// Common::Constants::Value<T>::Get, header-inline in the original (the Value<MS2Tick> instance 0x140a36020 is in this unit's
// COMDAT tail).
template<class T> T* Common::Constants::Value<T>::Get()
{
    if (!m_defined)
        Error("constants is not set");
    return &m_value;
}

// @0x140a35ca0
static inline unsigned FUN_140a35ca0(MS2Tick* pTick)
{
    return pTick->value;
}

// @0x140a31c40
BoneRotateInterpolator::BoneRotateInterpolator()
    : NiTransformInterpolator(), m_kEye(efd::Point3::ZERO), m_kBone(efd::Point3::ZERO), m_kEuler(efd::Point3::ZERO),
      m_bAlwaysUpdate(false), m_bActive(true), m_fLastYaw(0), m_fLastPitch(0), m_b80(true), m_f84(0.5f), m_bSmooth(true), m_pTarget(0), m_fPitchBias(0), m_fYawBias(0),
      m_nObjectId(0)
{
    m_kLastRotate.MakeIdentity();
    m_bHasValue = false;
}

// @0x140a31de0
BoneRotateInterpolator::BoneRotateInterpolator(NiTransformData* pkData)
    : NiTransformInterpolator(pkData), m_kEye(efd::Point3::ZERO), m_kBone(efd::Point3::ZERO), m_kEuler(efd::Point3::ZERO),
      m_bAlwaysUpdate(true), m_bActive(true), m_fLastYaw(0), m_fLastPitch(0), m_b80(true), m_f84(0.5f), m_bSmooth(true), m_pTarget(0), m_fPitchBias(0), m_fYawBias(0),
      m_nObjectId(0)
{
    m_kLastRotate.MakeIdentity();
    m_bHasValue = false;
}

// @0x140a31f80
// MS2-FUNCTIONAL: stack temporaries of the inlined engine math differ
bool BoneRotateInterpolator::Update(float fTime, NiObjectNET* pkInterpTarget, NiQuatTransform& kValue)
{
    if (m_nObjectId == 0)
        return false;
    GameObject* pObject = (GameObject*)WorldService::GetInstance()->FUN_141bd1200(m_nObjectId);
    if (pObject == 0)
        return false;
    m_pTarget = NiDynamicCast(NiAVObject, pkInterpTarget);
    if (m_pTarget != 0)
    {
        int nBad = 0;
        NiTransform kWorld = m_pTarget->GetWorldTransform();
        efd::Point3 kCol;
        kWorld.m_Rotate.GetCol(0, kCol);
        if (!Unk_IsFinite(kCol))
            nBad = 1;
        kWorld.m_Rotate.GetCol(1, kCol);
        if (!Unk_IsFinite(kCol))
            nBad = 1;
        kWorld.m_Rotate.GetCol(2, kCol);
        if (!Unk_IsFinite(kCol))
            nBad = 1;
        if (nBad != 0)
        {
            EE_LOG_AT(0x12, efd::ILogger::kERR1, ("BoneRotateInterpolator::Update invalid target world transform"), MS2_THIS_FILE, 0x55);
            if (DAT_143afc898 != 0)
                throw 13;
            return false;
        }
    }
    if (m_tmLookOut.FUN_140868ba0() != 0)
    {
        if (m_bHasValue == false)
            return false;
        NiTransform kLocal = m_pTarget->GetLocalTransform();
        if (kLocal.m_Rotate != DAT_143a09600)
        {
            efd::Matrix3 kLast = m_kLastRotate;
            efd::Quaternion kBlend;
            efd::Quaternion kTarget;
            kTarget.FromRotation(kLocal.m_Rotate);
            efd::Quaternion kCurrent;
            kCurrent.FromRotation(kLast);
            float fT = m_tmLookOut.FUN_140868940();
            fT = fT * fT;
            efd::Quaternion::Slerp(fT, kCurrent, kTarget, &kBlend);
            NiQuaternion kOut(kBlend);
            m_kTransformValue.SetRotate(kOut);
            NiActorManager* pActor = FUN_141b6f910()->FUN_140999440(pObject->FUN_14123c460());
            if (pActor != 0)
            {
                NiActorManager::SequenceID eSeq = pActor->GetCurAnimation();
                NiControllerSequence* pSeq = pActor->GetActiveSequence(eSeq, true, true);
                if (pSeq == 0)
                    m_kTransformValue.SetRotate(kLocal.m_Rotate);
            }
            int nBadValue = 0;
            if (!Unk_IsFinite(m_kTransformValue.GetTranslate()))
                nBadValue = 1;
            if (Unk_IsFiniteQuat(m_kTransformValue.GetRotate()) == 0)
                nBadValue = 1;
            float fScale = m_kTransformValue.GetScale();
            if (FUN_1409a8f90(&fScale) == 0)
                nBadValue = 1;
            if (nBadValue != 0)
            {
                EE_LOG_AT(0x12, efd::ILogger::kERR1, ("BoneRotateInterpolator::Update End"), MS2_THIS_FILE, 0x8d);
                if (DAT_143afc898 != 0)
                    throw 13;
                return false;
            }
            kValue = m_kTransformValue;
        }
    }
    else
    {
        if (m_bActive == false && m_pTarget != 0)
        {
            m_bHasValue = true;
            efd::Point3 kDir = m_kEye - m_kBone;
            kDir.Unitize();
            efd::Point3 kForward;
            efd::Point3 kRight;
            efd::Point3 kEuler = m_kEuler;
            FUN_140a01250(kEuler, &kForward, &kRight);
            kForward.Unitize();
            float fDot = kForward.Dot(kDir);
            fDot = efd::Clamp(fDot, -1.0f, 1.0f);
            float fYaw = Unk_Acos(fDot);
            efd::Point3 kCross = kForward.Cross(kDir);
            if (0.0f <= kCross.z)
                fYaw = fYaw * -1.0f;
            float fDotZ = kDir.Dot(efd::Point3::UNIT_Z);
            fDotZ = efd::Clamp(fDotZ, -1.0f, 1.0f);
            float fPitch = Unk_Acos(fDotZ);
            fPitch = 1.5707964f - fPitch;
            NiTransform kLocal = m_pTarget->GetLocalTransform();
            if (fYaw > 0.0f && fYaw > 0.7853982f)
                fYaw = 0.7853982f;
            else if (fYaw < 0.0f && fYaw < -0.7853982f)
                fYaw = -0.7853982f;
            fPitch = fPitch + m_fPitchBias;
            if (fPitch > 0.0f && fPitch >= 0.5235988f)
                fPitch = 0.5235988f;
            else if (fPitch < 0.0f && fPitch <= -0.5235988f)
                fPitch = -0.5235988f;
            efd::Matrix3 kRot;
            kRot.FromEulerAnglesXYZ(fYaw, 0.0f, fPitch);
            if (m_bSmooth != false && ((fYaw != m_fLastYaw || fPitch != m_fLastPitch) && m_tmAim.FUN_140868ba0() == 0))
                m_tmAim.FUN_140868750(300);
            m_fLastYaw = fYaw;
            m_fLastPitch = fPitch;
            if (kLocal.m_Rotate != DAT_143a09600)
            {
                NiMatrix3 kMul(kLocal.m_Rotate * kRot);
                efd::Quaternion kBlend;
                efd::Quaternion kTarget;
                kTarget.FromRotation(kMul);
                efd::Quaternion kCurrent;
                kCurrent.FromRotation(kLocal.m_Rotate);
                if (m_tmLookIn.FUN_140868ba0() == 0)
                {
                    if (m_tmAim.FUN_140868ba0() == 0)
                    {
                        efd::Quaternion::Slerp(1.0f, kCurrent, kTarget, &kBlend);
                    }
                    else
                    {
                        float fT = m_tmAim.FUN_140868940();
                        fT = fT * fT;
                        kCurrent.FromRotation(m_kLastRotate);
                        efd::Quaternion::Slerp(fT, kCurrent, kTarget, &kBlend);
                    }
                }
                else
                {
                    float fT = m_tmLookIn.FUN_140868940();
                    fT = fT * fT;
                    efd::Quaternion::Slerp(fT, kCurrent, kTarget, &kBlend);
                }
                NiQuaternion kOut(kBlend);
                m_kTransformValue.SetRotate(kOut);
                kBlend.ToRotation(m_kLastRotate);
                NiActorManager* pActor = FUN_141b6f910()->FUN_140999440(pObject->FUN_14123c460());
                if (pActor != 0)
                {
                    NiActorManager::SequenceID eSeq = pActor->GetCurAnimation();
                    NiControllerSequence* pSeq = pActor->GetActiveSequence(eSeq, true, true);
                    if (pSeq == 0)
                        m_kTransformValue.SetRotate(kLocal.m_Rotate);
                }
                int nBadValue = 0;
                if (!Unk_IsFinite(m_kTransformValue.GetTranslate()))
                    nBadValue = 1;
                if (Unk_IsFiniteQuat(m_kTransformValue.GetRotate()) == 0)
                    nBadValue = 1;
                float fScale = m_kTransformValue.GetScale();
                if (FUN_1409a8f90(&fScale) == 0)
                    nBadValue = 1;
                if (nBadValue != 0)
                {
                    EE_LOG_AT(0x12, efd::ILogger::kERR1, ("BoneRotateInterpolator::Update Start"), MS2_THIS_FILE, 0x10b);
                    if (DAT_143afc898 != 0)
                        throw 13;
                    return false;
                }
                kValue = m_kTransformValue;
            }
        }
        else
        {
            FUN_140a33100();
        }
    }
    if (!m_kTransformValue.IsScaleValid() || !m_kTransformValue.IsTranslateValid() || !m_kTransformValue.IsRotateValid())
        return false;
    m_fLastTime = fTime;
    return true;
}

// @0x140a32e50
bool BoneRotateInterpolator::AlwaysUpdate() const
{
    return m_bAlwaysUpdate;
}

// @0x140a32e90
void BoneRotateInterpolator::FUN_140a32e90(bool bActive, unsigned int uiBlendMs)
{
    if (m_bActive == true && bActive == false)
    {
        m_bHasValue = false;
        m_tmLookIn.FUN_140868750(uiBlendMs);
        m_tmLookOut.FUN_1408687f0();
        FUN_140a33100();
    }
    else if (m_bActive == false && bActive == true)
    {
        m_tmLookOut.FUN_140868750(uiBlendMs);
        m_tmLookIn.FUN_1408687f0();
        m_fPitchBias = 0;
        m_fYawBias = 0;
        FUN_140a33100();
    }
    m_bActive = bActive;
}

// @0x140a32fb0
void BoneRotateInterpolator::FUN_140a32fb0(efd::Point3 kPos)
{
    m_kEye = kPos;
}

// @0x140a32fe0
void BoneRotateInterpolator::FUN_140a32fe0(efd::Point3 kPos)
{
    m_kBone = kPos;
}

// @0x140a33010
void BoneRotateInterpolator::FUN_140a33010(efd::Point3 kPos)
{
    m_kEuler = kPos;
}

// @0x140a33060
void BoneRotateInterpolator::FUN_140a33060(float fValue)
{
    m_fYawBias = fValue;
}

// @0x140a33090
void BoneRotateInterpolator::FUN_140a33090(float fValue)
{
    m_fPitchBias = fValue;
}

// @0x140a330c0
void BoneRotateInterpolator::FUN_140a330c0(bool bValue)
{
    m_bSmooth = bValue;
}

// @0x140a330e0
bool BoneRotateInterpolator::FUN_140a330e0() const
{
    return m_bSmooth;
}

// @0x140a33100
void BoneRotateInterpolator::FUN_140a33100()
{
    if (m_pTarget == 0)
        return;
    NiNode* pParent = m_pTarget->GetParent();
    if (pParent == 0)
        return;
    NiTransform kParentWorld = pParent->GetWorldTransform();
    NiTransform kTargetWorld = m_pTarget->GetWorldTransform();
    NiTransform kInverse;
    kParentWorld.Invert(kInverse);
    NiTransform kLocal = kInverse * kTargetWorld;
    m_kTransformValue.SetTranslate(kLocal.m_Translate);
    m_kTransformValue.SetRotate(kLocal.m_Rotate);
    m_kTransformValue.SetScale(kLocal.m_fScale);
}

// ---- CBoneRotateManager ----

// @0x140a347c0
CBoneRotateManager::CBoneRotateManager()
    : m_bEnabled(false), m_kLookPos(efd::Point3::ZERO), m_strBone("Bip01 Head"), m_fIdleMs(0), m_pInterp(0), m_pOwner(0),
      m_kTargetId(s_kNullId), m_pRootNode(0), m_actions(10)
{
    m_tmLook.FUN_1408687f0();
    m_tmApply.FUN_1408687f0();
    m_fIdleMs = (float)FUN_140a35ca0(Client::Constants::GetInstance()->LookAtInterval.Get());
    m_fIdleMs = m_fIdleMs + (float)(rand() % 5);
    for (int i = 0; i < 2; i = i + 1)
    {
        m_tmReserved1[i].FUN_140868750((int)m_fIdleMs);
        m_tmReserved2[i].FUN_140868750((int)m_fIdleMs);
    }
    m_tmIdle.FUN_140868750((int)m_fIdleMs);
}

// @0x140a34a70
CBoneRotateManager::~CBoneRotateManager()
{
    FUN_140a35900();
}

// @0x140a34b80
void CBoneRotateManager::FUN_140a34b80(GameObject* pOwner, CString strBone)
{
    m_pOwner = pOwner;
    m_actions.RemoveAll();
    m_nCurrent = Unk_BrMode_None;
}

// @0x140a34be0
void CBoneRotateManager::FUN_140a34be0(Unk_BrMode nMode, GameObject* pTarget, int nParam)
{
    if (m_bEnabled == false)
        return;
    Unk_BrActionPtr spAction(0);
    if (m_nCurrent != 0)
        return;
    m_nCurrent = nMode;
    if (m_actions.Lookup(m_nCurrent, spAction))
    {
        Unk_BrAction* pAction = spAction.operator->();
        if (pAction->vfunc_1(m_pOwner->FUN_14123c580(), pTarget->FUN_14123c580(), nParam) == false)
            FUN_140a34f00();
    }
}

// @0x140a34d00
void CBoneRotateManager::FUN_140a34d00(const efd::Point3& kPos, int nStart, int nEnd, int nDuration)
{
    if (m_bEnabled == false)
        return;
    if (m_pInterp == 0)
        return;
    m_kLookPos = kPos;
    if (nDuration == 0)
        m_tmLook.FUN_1408687c0();
    else
        m_tmLook.FUN_140868750(nDuration);
    m_nStart = nStart;
    m_nEnd = nEnd;
    m_tmApply.FUN_140868750(1);
    m_pInterp->FUN_140a330c0(true);
}

// @0x140a34de0
void CBoneRotateManager::FUN_140a34de0(const egf::EntityID& kId, CString strBone, int nStart, int nEnd, int nDuration)
{
    if (m_bEnabled == false)
        return;
    if (m_pInterp == 0)
        return;
    m_kTargetId = kId;
    if (nDuration == 0)
        m_tmLook.FUN_1408687c0();
    else
        m_tmLook.FUN_140868750(nDuration);
    m_nStart = nStart;
    m_nEnd = nEnd;
    m_strBone = strBone;
    m_tmApply.FUN_140868750(1);
    m_pInterp->FUN_140a330c0(true);
}

// @0x140a34f00
void CBoneRotateManager::FUN_140a34f00()
{
    m_tmLook.FUN_1408687f0();
    m_tmApply.FUN_1408687f0();
    m_kTargetId = s_kNullId;
    if (m_pInterp == 0)
        return;
    m_pInterp->FUN_140a32e90(true, m_nEnd);
    m_pInterp->FUN_140a330c0(false);
    Unk_BrActionPtr spAction(0);
    if (m_actions.Lookup(m_nCurrent, spAction))
    {
        Unk_BrAction* pAction = spAction.operator->();
        pAction->vfunc_2();
        m_tmIdle.FUN_140868750((int)m_fIdleMs);
        m_nCurrent = Unk_BrMode_None;
    }
    else
    {
        m_tmIdle.FUN_140868750((int)m_fIdleMs);
    }
}

// @0x140a35060
// MS2-FUNCTIONAL: stack temporaries of the inlined engine math differ
void CBoneRotateManager::FUN_140a35060()
{
    if (m_bEnabled == false)
        return;
    if (m_tmLook.FUN_140868ba0() == 0)
    {
        if (m_tmLook.FUN_140868c00() != 0)
            FUN_140a34f00();
    }
    else if (m_tmApply.FUN_140868c00() != 0)
    {
        m_pInterp->FUN_140a32e90(false, m_nStart);
        efd::Point3 kBase = m_kLookPos;
        if (m_kTargetId != s_kNullId)
        {
            egf::EntityID kId(m_kTargetId);
            GameObject* pTarget = FUN_141bd0fa0(WorldService::GetInstance(), kId);
            if (pTarget != 0)
            {
                kBase = pTarget->vfunc_18();
                NiTransform kXform;
                egf::EntityID kId2(m_kTargetId);
                NiAVObject* pModel = FUN_141b6ef70(kId2);
                if (pModel != 0)
                {
                    NiFixedString kName((const char*)m_strBone);
                    NiAVObject* pBone = (NiAVObject*)pModel->GetObjectByName(kName);
                    if (pBone != 0)
                    {
                        kXform = pBone->GetLocalTransform();
                        if (pBone->GetParent() != 0)
                        {
                            NiTransform kParentWorld = pBone->GetParent()->GetWorldTransform();
                            kXform = kParentWorld * kXform;
                        }
                        float fBoneZ = kXform.m_Translate.z;
                    }
                }
            }
        }
        m_pInterp->FUN_140a32fb0(kBase);
        NiTransform kRoot;
        if (m_pRootNode != 0)
        {
            kRoot = m_pRootNode->GetLocalTransform();
            if (m_pRootNode->GetParent() != 0)
            {
                NiTransform kParentWorld = m_pRootNode->GetParent()->GetWorldTransform();
                kRoot = kParentWorld * kRoot;
            }
        }
        efd::Point3 kRootPos = kRoot.m_Translate;
        m_pInterp->FUN_140a32fe0(kRootPos);
        m_pInterp->FUN_140a33010(m_pOwner->vfunc_20());
        m_tmApply.FUN_140868750(500);
    }
}

// @0x140a35500
// MS2-FUNCTIONAL: stack temporaries differ
void CBoneRotateManager::FUN_140a35500(void* pArg)
{
    if (m_bEnabled == false)
        return;
    FUN_140a35060();
    if (m_nCurrent != 0)
    {
        Unk_BrActionPtr spAction(0);
        if (m_actions.Lookup(m_nCurrent, spAction))
        {
            Unk_BrAction* pAction = spAction.operator->();
            pAction->vfunc_6(pArg);
            FUN_140a35060();
        }
    }
    if (m_tmIdle.FUN_140868c00() != 0 && m_nCurrent == 0)
    {
        POSITION pos = m_actions.GetHeadPosition();
        while (pos != 0)
        {
            Unk_BrMode nMode = m_actions.GetKeyAt(pos);
            Unk_BrActionPtr spAction = m_actions.GetValueAt(pos);
            if (spAction.get() != 0)
            {
                Unk_BrAction* pAction = spAction.operator->();
                if (pAction->vfunc_3() != false)
                {
                    pAction = spAction.operator->();
                    int nOwnerId = m_pOwner->FUN_14123c580();
                    if (pAction->vfunc_1(nOwnerId, 0, 5000) != false)
                    {
                        m_nCurrent = nMode;
                        return;
                    }
                    FUN_140a34f00();
                }
            }
            m_actions.GetNext(pos);
        }
    }
}

// @0x140a35780
int CBoneRotateManager::FUN_140a35780()
{
    if (m_bEnabled == false)
        return 0;
    return m_tmLook.FUN_140868ba0();
}

// @0x140a357c0
Unk_BrMode CBoneRotateManager::FUN_140a357c0()
{
    return m_nCurrent;
}

// @0x140a357e0
void CBoneRotateManager::FUN_140a357e0(float fValue)
{
    if (m_pInterp != 0)
        m_pInterp->FUN_140a33060(fValue);
}

// @0x140a35820
void CBoneRotateManager::FUN_140a35820(float fValue)
{
    if (m_pInterp != 0)
        m_pInterp->FUN_140a33090(fValue);
}

// @0x140a35860
void CBoneRotateManager::FUN_140a35860(bool bValue)
{
    if (m_pInterp != 0)
        m_pInterp->FUN_140a330c0(bValue);
}

// @0x140a358a0
bool CBoneRotateManager::FUN_140a358a0()
{
    if (m_pInterp != 0)
        return m_pInterp->FUN_140a330e0();
    return false;
}

// @0x140a358e0
GameObject* CBoneRotateManager::FUN_140a358e0()
{
    return m_pOwner;
}

// @0x140a35900
void CBoneRotateManager::FUN_140a35900()
{
    POSITION pos = m_actions.GetHeadPosition();
    while (pos != 0)
    {
        Unk_BrActionPtr spAction = m_actions.GetNext(pos)->m_value;
        if (spAction.get() != 0)
            spAction = 0;
    }
    m_actions.RemoveAll();
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9ef20-0x142c9f040 .text$yd
