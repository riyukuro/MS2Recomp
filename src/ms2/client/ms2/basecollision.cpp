// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CBaseCollision, the base of the debug-visible collision
// shapes (box 1, cylinder 2, frustum 3, hole cylinder 4), and CDetectContext, the shape-based target search: the world
// query, the per-object shape-vs-box test, the buff/party/guild filters and the sort orders. Also the template glue of
// the containers it uses (CAtlArray of efd::SmartPointer<GameObject> / MS2Ptr<CBoxCollision>, CAtlMap<unsigned,
// NiPoint3>, ...). Names other than the RTTI class names are invented.
// MS2-UNIT: ?\basecollision.cpp
// MS2-RANGE: 0x1409fbb80-0x140a02ac0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CAtlArray@V?$MS2Ptr@VCBoxCollision@@@@V?$CElementTraits@V?$MS2Ptr@VCBoxCollision@@@@@ATL@@@ATL@@QEAA@XZ 0x1409fff70 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCBoxCollision@@@@QEAA@AEBV0@@Z 0x140a00180 ; prop
// MS2-PIN: ??0?$MS2Ptr@VCDetectContext@@@@QEAA@AEBV0@@Z 0x140a001c0 ; prop
// MS2-PIN: ??0Unk_DetectHit@@QEAA@XZ 0x140a00200 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@IVNiPoint3@@V?$CElementTraits@I@ATL@@V?$CElementTraits@VNiPoint3@@@3@@ATL@@IEAA@I@Z 0x140a00270 ; unique
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@VCBoxCollision@@@@V?$CElementTraits@V?$MS2Ptr@VCBoxCollision@@@@@ATL@@@ATL@@QEAA@XZ 0x140a003f0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VCDetectContext@@@@QEBAPEAVCDetectContext@@XZ 0x140a00710 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCBoxCollision@@@@V?$CElementTraits@V?$MS2Ptr@VCBoxCollision@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCBoxCollision@@@@_K@Z 0x140a010d0 ; unique
// MS2-PIN: ?GetCount@?$CAtlList@V?$SmartPointer@VUnk_WsC_GameObj@@@efd@@V?$CElementTraits@V?$SmartPointer@VUnk_WsC_GameObj@@@efd@@@ATL@@@ATL@@QEBA_KXZ 0x140a01240 ; unique
// MS2-PIN: ?IsEmpty@?$CAtlArray@V?$SmartPointer@VGameObject@@@efd@@V?$CElementTraits@V?$SmartPointer@VGameObject@@@efd@@@ATL@@@ATL@@QEBA_NXZ 0x140a018d0 ; prop
// MS2-PIN: ?IsEmpty@?$CAtlArray@V?$MS2Ptr@VCBoxCollision@@@@V?$CElementTraits@V?$MS2Ptr@VCBoxCollision@@@@@ATL@@@ATL@@QEBA_NXZ 0x140a01900 ; prop
// MS2-PIN: ?Lookup@?$CAtlMap@IVNiPoint3@@V?$CElementTraits@I@ATL@@V?$CElementTraits@VNiPoint3@@@3@@ATL@@QEBA_NIAEAVNiPoint3@@@Z 0x140a01a00 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@IVNiPoint3@@V?$CElementTraits@I@ATL@@V?$CElementTraits@VNiPoint3@@@3@@ATL@@QEAAPEAU__POSITION@@IAEBVNiPoint3@@@Z 0x140a024b0 ; unique
// MS2-PIN: ?AddRef@?$MS2Ptr@VCBoxCollision@@@@AEBAXXZ 0x140a02880 ; prop
// MS2-PIN: ?AddRef@?$MS2Ptr@VCDetectContext@@@@AEBAXXZ 0x140a028b0 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCBoxCollision@@@@AEBAXPEAX@Z 0x140a02920 ; prop
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCDetectContext@@@@AEBAXPEAX@Z 0x140a02950 ; prop
// MS2-PIN: ?Release@?$MS2Ptr@VCDetectContext@@@@AEAAXXZ 0x140a029c0 ; unique
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VCDetectContext@@@@AEAAXPEAX@Z 0x140a02a50 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??$addressof@V?$SmartPointer@VGameObject@@@efd@@@std@@YAPEAV?$SmartPointer@VGameObject@@@efd@@AEAV12@@Z 0x1409ffe70
#define NOMINMAX
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\basecollision.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <stdlib.h>
#include <algorithm>
#include <memory>
#include <atlcoll.h>
#include <NiMesh.h>
#include <NiRenderer.h>
#include <NiPlane.h>
#include <NiVertexColorProperty.h>
#include <NxPhysics.h>
#include <NxIntersectionBoxBox.h>
#include <NxSegment.h>
#include <efd/Matrix3.h>
#include "ms2/placeholder/cbasecollision.h"
#include "ms2/placeholder/cboxcollision.h"
#include "ms2/placeholder/ccylindercollision.h"
#include "ms2/placeholder/cdetectcontext.h"
#include "ms2/client/ms2/frustumcollision.h"
#include "ms2/client/ms2/holecylindercollision.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/ridee.h"
#include "ms2/placeholder/cpet.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "ms2/client/ms2/additionalclilist.h"
#include "ms2/placeholder/fittingdollpc.h"  // C3: PC (efd::DynamicCast<PC, PCBase>)
#include "ms2/placeholder/cnpc.h"  // C3: CNpc (efd::DynamicCast<CNpc, PCBase>)

// The game objects the world query returns (worldservice.h names them by this stand-in).
class Unk_WsC_GameObj : public GameObject { };

// The buff container of an actor (PCBase::FUN_1416749a0).
class Unk_PCBaseBuffs : public AdditionalCliList
{
};


struct Unk_UtilFloat3;
Vector3 FUN_141b6e150(const Unk_UtilFloat3* pVec);   // C3: util.cpp's definition (0x141b6e150), NxVec3 -> point
NxVec3 FUN_141b6e0e0(const efd::Point3& v);                         // efd::Point3 -> NxVec3
float FUN_14059d930(float f);                                       // fabsf
float GetPlanarDistance(Vector3 kA, Vector3 kB);   // C3: the definer's signature (0x140966ea0), planar distance

static int FilterTarget(GameObject* pSelf, GameObject* pTarget, unsigned int nFlags, unsigned int nNpcKinds);
static void ShuffleTargets(ATL::CAtlArray<efd::SmartPointer<GameObject> >& arr);
static void SwapTargets(efd::SmartPointer<GameObject>& a, efd::SmartPointer<GameObject>& b);
inline void FUN_140a01250(efd::Point3 kRot, efd::Point3* pForward, efd::Point3* pRight);

// The target filter the world query calls per object (a .data function pointer).
static int (*s_pfnTargetFilter)(GameObject*, GameObject*, unsigned int, unsigned int) = FilterTarget;
typedef int (*Unk_WsFilter)(void*, Unk_WsC_GameObj*, int, int);

// Slot 2 of the box shape takes the rotation as a matrix by reference (the shared header keeps the point form).
struct Unk_BcRotSetter
{
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(NiPoint3 kPos, const NiMatrix3& kRot, float fScale);   // MS2: slot 2
    virtual void vfunc_3(NiPoint3 kPos, NiPoint3 kRot, float fScale);           // MS2: slot 3
};

// GameObject slots 18 and 20 return efd::Point3 (the shared header declares NiPoint3).
struct Unk_BcGoPlace
{
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17();
    virtual efd::Point3 vfunc_18();   // MS2: slot 18 (position)
    virtual void vfunc_19();
    virtual efd::Point3 vfunc_20();   // MS2: slot 20 (rotation)
};

// @0x1409fbb80
CDetectContext::CDetectContext()
    : m_pOwner(NULL), m_pRange(NULL), m_kPos(efd::Point3::ZERO), m_kRight(efd::Point3::ZERO),
      m_kDir(efd::Point3::ZERO), m_nTargetKind(0), m_nSortMode(0), m_n78(0), m_bRideToRider(0), m_pExclude(NULL),
      m_bUseAllAnchors(0)
{
}

// The exe builds m_kColor with NiColorA(float x4) 0x14097f1d0 (the inline Gamebryo ctor forwarding to efd::ColorA's
// 0x14097f050).
//
// @0x1409fbc80
//
CBaseCollision::CBaseCollision()
    : m_n18(0), m_ptPos(0, 0, 0), m_ptSize(0, 0, 0), m_ptDir(0, 0, 0), m_nShape(0), m_kColor(1.0f, 0, 0, 1.0f),
      m_b54(true), m_n58(0), m_spMesh(NULL), m_bBuilt(0)
{
    m_spMesh = NiNew NiMesh;
    NiVertexColorProperty* pkVertexColor = NiNew NiVertexColorProperty;
    pkVertexColor->SetSourceMode(NiVertexColorProperty::SOURCE_EMISSIVE);
    pkVertexColor->SetLightingMode(NiVertexColorProperty::LIGHTING_E);
    m_spMesh->AttachProperty(pkVertexColor);
}

// @0x1409fbed0
CBaseCollision::~CBaseCollision()
{
}

// @0x1409fbf20
void CBaseCollision::vfunc_1()
{
    if (m_bBuilt == 0)
        vfunc_5();
    if (m_spMesh)
        m_spMesh->RenderImmediate(NiRenderer::GetRenderer());
}

// @0x1409fbfa0
void CBaseCollision::vfunc_3(NiPoint3 ptPos, NiPoint3 ptDir, float fScale)
{
    m_ptPos = reinterpret_cast<const Vector3&>(ptPos);
    Invalidate();
}

// @0x1409fbff0
void CBaseCollision::vfunc_2(NiPoint3 ptPos, const NiMatrix3& kRot, float fScale)
{
    m_ptPos = reinterpret_cast<const Vector3&>(ptPos);
    Invalidate();
}

// @0x1409fc040
void CBaseCollision::vfunc_4()
{
}

// @0x1409fc050
int CBaseCollision::vfunc_7(efd::SmartPointer<GameObject> spSelf, efd::SmartPointer<GameObject> spTarget)
{
    if (!spSelf || !spTarget)
        return 0;
    NiPoint3 kPos(reinterpret_cast<Unk_BcGoPlace*>(spSelf.operator->())->vfunc_18());
    NiPoint3 kRot(reinterpret_cast<Unk_BcGoPlace*>(spSelf.operator->())->vfunc_20());
    vfunc_3(kPos, kRot, 1.0f);
    efd::Point3 kRight;
    efd::Point3 kDir;
    FUN_140a01250(kRot, &kDir, &kRight);
    kDir.Unitize();
    kRight.Unitize();
    CBoxCollision* pBox = reinterpret_cast<CBoxCollision*>(spTarget->vfunc_26());
    if (pBox == NULL)
        return 0;
    Unk_DetectHit kHit;
    kHit.m_nMode = 3;
    static_cast<efd::Point3&>(kHit.m_kMetric) = efd::Point3::ZERO;
    return TestShape(kPos, kRight, kDir, this, pBox, &kHit);
}

// @0x1409fc390
void CBaseCollision::DetectWithEulerRotation(MS2Ptr<CDetectContext> spCtx, const NiPoint3& kRot)
{
    reinterpret_cast<Unk_BcRotSetter*>(this)->vfunc_3(spCtx->m_kPos, kRot, 1.0f);
    NiPoint3 kDir;
    NiPoint3 kRight;
    efd::Point3 kRotCopy = kRot;
    FUN_140a01250(kRotCopy, &spCtx->m_kDir, &spCtx->m_kRight);
    spCtx->m_kDir.Unitize();
    spCtx->m_kRight.Unitize();
    Detect(spCtx);
}

// @0x1409fc540
void CBaseCollision::DetectWithMatrixRotation(MS2Ptr<CDetectContext> spCtx, const NiMatrix3& kRot)
{
    reinterpret_cast<Unk_BcRotSetter*>(this)->vfunc_2(spCtx->m_kPos, kRot, 1.0f);
    kRot.GetCol(0, spCtx->m_kDir);
    spCtx->m_kDir.Unitize();
    spCtx->m_kRight = spCtx->m_kDir.Cross(efd::Point3::UNIT_Z);
    spCtx->m_kRight.Unitize();
    Detect(spCtx);
}

// @0x1409fc6c0
void CBaseCollision::Detect(MS2Ptr<CDetectContext> spCtx)
{
    ATL::CAtlList<efd::SmartPointer<Unk_WsC_GameObj> > kObjects(10);
    if (spCtx->m_pOwner == NULL)
        return;
    int nQueryFlags = 0;
    if (spCtx->m_pRange != NULL)
        nQueryFlags = spCtx->m_pRange->m_nQueryFlags;
    WorldService::GetInstance()->FUN_141bd2ea0(spCtx->m_pOwner, &kObjects, spCtx->m_nTargetKind, nQueryFlags,
                                               (Unk_WsFilter)s_pfnTargetFilter);
    if (kObjects.GetCount() <= 0)
        return;

    int bFacing = (spCtx->m_nSortMode == 5 || spCtx->m_nSortMode == 6) ? 1 : 0;
    GameObject* pFirst = NULL;
    ATL::CAtlMap<unsigned int, NiPoint3> kMetrics(17, 0.75f, 0.25f, 2.25f, 10);
    ATL::CAtlMap<unsigned int, float> kFacing(17, 0.75f, 0.25f, 2.25f, 10);
    for (POSITION pos = kObjects.GetHeadPosition(); pos != NULL; kObjects.GetNext(pos))
    {
        GameObject* pObj = kObjects.GetAt(pos);
        if (pObj->GetClassID() == Ridee::CLASS_ID)
            continue;
        if (spCtx->m_pExclude != NULL)
        {
            if (spCtx->m_pExclude->Lookup(pObj->GetObjectId()) != NULL)
                continue;
        }
        if (!TSingleton<CFeatureManager>::GetInstance()->IsFeatureEnabled(0xd7))
        {
            if (pObj->GetObjectId() == spCtx->m_pOwner->GetObjectId())
            {
                if (spCtx->m_bRideToRider != 0)
                {
                    efd::SmartPointer<Ridee> spRidee = efd::DynamicCast<Ridee>(pObj);
                    if (spRidee)
                        pFirst = spRidee->GetRider();
                    else
                        pFirst = pObj;
                }
                continue;
            }
        }
        {
            Unk_DetectHit kHit;
            kHit.m_nMode = spCtx->m_nSortMode;
            static_cast<efd::Point3&>(kHit.m_kMetric) = efd::Point3::ZERO;
            ATL::CAtlArray<MS2Ptr<CBoxCollision> > kBoxes;
            if (spCtx->m_bUseAllAnchors != 0)
                pObj->vfunc_28(&kBoxes);
            if (kBoxes.IsEmpty())
                pObj->vfunc_27(kBoxes);
            if (!kBoxes.IsEmpty())
            {
                int bHit = 0;
                for (unsigned int i = 0; i < kBoxes.GetCount(); i++)
                {
                    MS2Ptr<CBoxCollision> spBox(kBoxes[i]);
                    if (spBox == NULL)
                        continue;
                    bHit = TestShape(spCtx->m_kPos, spCtx->m_kRight, spCtx->m_kDir, this, spBox.get(), &kHit);
                    if (bHit)
                        break;
                }
                if (bHit == 0)
                    continue;
            }
            else
            {
                CBoxCollision* pBox = reinterpret_cast<CBoxCollision*>(pObj->vfunc_26());
                if (pBox == NULL)
                    continue;
                int bHit = TestShape(spCtx->m_kPos, spCtx->m_kRight, spCtx->m_kDir, this, pBox, &kHit);
                if (bHit == 0)
                    continue;
            }
            if (TSingleton<CFeatureManager>::GetInstance()->IsFeatureEnabled(0xd7))
            {
                if (pObj->GetObjectId() == spCtx->m_pOwner->GetObjectId())
                {
                    if (spCtx->m_bRideToRider != 0)
                    {
                        efd::SmartPointer<Ridee> spRidee = efd::DynamicCast<Ridee>(pObj);
                        if (spRidee)
                            pFirst = spRidee->GetRider();
                        else
                            pFirst = pObj;
                    }
                    continue;
                }
            }
            spCtx->m_arrTargets.Add(pObj);
            kMetrics.SetAt(pObj->GetObjectId(), kHit.m_kMetric);
            if (bFacing)
            {
                efd::Point3 kTo = pObj->vfunc_18() - spCtx->m_kPos;
                kTo.z = 0.0f;
                kTo.Unitize();
                float fDot = spCtx->m_kDir.Dot(kTo);
                kFacing.SetAt(pObj->GetObjectId(), fDot);
            }
        }
    }

    ATL::CAtlArray<efd::SmartPointer<GameObject> > kFiltered;
    if (spCtx->m_pRange != NULL && spCtx->m_pRange->m_nFilterMode != 0)
    {
        const int& nBuff = spCtx->m_pRange->m_nBuffFilter;
        const int& bFromOwner = spCtx->m_pRange->m_bBuffFromOwner;
        const int& bSameParty = spCtx->m_pRange->m_bSameParty;
        const int& bSameGuild = spCtx->m_pRange->m_bSameGuild;
        const int& nMode = spCtx->m_pRange->m_nFilterMode;
        for (unsigned int i = 0; i < spCtx->m_arrTargets.GetCount(); i++)
        {
            PCBase* pTarget = efd::DynamicCast<PCBase>(spCtx->m_arrTargets[i]);
            if (pTarget == NULL)
                continue;
            if (nBuff != 0)
            {
                if (bFromOwner != 0)
                {
                    if (!pTarget->FUN_1416749a0()->HasEnabledWithIdAndCaster(nBuff, spCtx->m_pOwner->GetObjectId()))
                        continue;
                }
                else if (!pTarget->FUN_1416749a0()->HasEnabledWithId(nBuff))
                    continue;
            }
            PCBase* pTargetPC = efd::DynamicCast<PC, PCBase>(reinterpret_cast<PCBase*>(pTarget));
            PCBase* pOwnerPC = efd::DynamicCast<PC, PCBase>(reinterpret_cast<PCBase*>(spCtx->m_pOwner));
            if (pTargetPC != NULL && pOwnerPC != NULL)
            {
                if (bSameParty != 0)
                {
                    if (((PC*)pOwnerPC)->FUN_141661bc0() == 0 || ((PC*)pOwnerPC)->FUN_141661bc0() != ((PC*)pTargetPC)->FUN_141661bc0())
                        continue;
                }
                if (bSameGuild != 0)
                {
                    if (reinterpret_cast<PC*>(pOwnerPC)->GetGuildName().IsEmpty() || reinterpret_cast<PC*>(pOwnerPC)->GetGuildName() != reinterpret_cast<PC*>(pTargetPC)->GetGuildName())
                        continue;
                }
            }
            kFiltered.Add(pTarget);
        }
        if (nMode == 2)
        {
            spCtx->m_arrTargets.RemoveAll();
            spCtx->m_arrTargets.Copy(kFiltered);
            kFiltered.RemoveAll();
        }
        else if (nMode == 3)
        {
            if (!kFiltered.IsEmpty())
            {
                spCtx->m_arrTargets.RemoveAll();
                spCtx->m_arrTargets.Copy(kFiltered);
                kFiltered.RemoveAll();
            }
        }
        else if (nMode == 4)
        {
        }
    }

    int nStatSort = 0;
    if (spCtx->m_pRange != NULL)
        nStatSort = spCtx->m_pRange->m_nStatSort;
    if (nStatSort != 0)
    {
        int nStat = spCtx->m_pRange->m_nStatKind;
        for (unsigned int i = 0; i < spCtx->m_arrTargets.GetCount(); i++)
        {
            PCBase* pA = efd::DynamicCast<PCBase>(spCtx->m_arrTargets[i]);
            if (pA == NULL)
                continue;
            for (unsigned int j = i + 1; j < spCtx->m_arrTargets.GetCount(); j++)
            {
                PCBase* pB = efd::DynamicCast<PCBase>(spCtx->m_arrTargets[j]);
                if (pB == NULL)
                    continue;
                if (nStatSort == 1)
                {
                    if (pA->GetStat(2, nStat) > pB->GetStat(2, nStat))
                        SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                }
                else if (nStatSort == 2)
                {
                    if (pA->GetStat(2, nStat) < pB->GetStat(2, nStat))
                        SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                }
                else if (nStatSort == 3)
                {
                    float fCurA = (float)pA->GetStat(2, nStat);
                    float fRateA = fCurA / (float)pA->GetStat(0, nStat);
                    float fCurB = (float)pB->GetStat(2, nStat);
                    float fRateB = fCurB / (float)pB->GetStat(0, nStat);
                    if (fRateA > fRateB)
                        SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                }
                else if (nStatSort == 4)
                {
                    float fCurA = (float)pA->GetStat(2, nStat);
                    float fRateA = fCurA / (float)pA->GetStat(0, nStat);
                    float fCurB = (float)pB->GetStat(2, nStat);
                    float fRateB = fCurB / (float)pB->GetStat(0, nStat);
                    if (fRateA < fRateB)
                        SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                }
            }
        }
    }
    else
    {
        if (spCtx->m_nSortMode == 0)
        {
            ShuffleTargets(spCtx->m_arrTargets);
        }
        else
        {
            for (unsigned int i = 0; i < spCtx->m_arrTargets.GetCount(); i++)
            {
                for (unsigned int j = i + 1; j < spCtx->m_arrTargets.GetCount(); j++)
                {
                    NiPoint3 kA;
                    NiPoint3 kB;
                    kMetrics.Lookup(spCtx->m_arrTargets[i]->GetObjectId(), kA);
                    kMetrics.Lookup(spCtx->m_arrTargets[j]->GetObjectId(), kB);
                    float fA = 0.0f;
                    float fB = 0.0f;
                    kFacing.Lookup(spCtx->m_arrTargets[i]->GetObjectId(), fA);
                    kFacing.Lookup(spCtx->m_arrTargets[j]->GetObjectId(), fB);
                    if (spCtx->m_nSortMode == 2)
                    {
                        if (kA.x < kB.x)
                            SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                    }
                    else if (spCtx->m_nSortMode == 1)
                    {
                        if (kA.x > kB.x)
                            SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                    }
                    else if (spCtx->m_nSortMode == 3)
                    {
                        if ((m_nShape == 2 || m_nShape == 4) && kA.z > kB.z)
                            SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                        else if (kA.y > kB.y)
                            SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                    }
                    else if (spCtx->m_nSortMode == 4)
                    {
                        if ((m_nShape == 2 || m_nShape == 4) && kA.z < kB.z)
                            SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                        else if (kA.y < kB.y)
                            SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                    }
                    else if (spCtx->m_nSortMode == 5)
                    {
                        if (fA < fB)
                            SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                    }
                    else if (spCtx->m_nSortMode == 6 && fA > fB)
                    {
                        SwapTargets(spCtx->m_arrTargets[i], spCtx->m_arrTargets[j]);
                    }
                }
            }
        }
    }

    if (!kFiltered.IsEmpty())
    {
        ATL::CAtlArray<efd::SmartPointer<GameObject> > kFront;
        ATL::CAtlArray<efd::SmartPointer<GameObject> > kBack;
        for (unsigned int i = 0; i < spCtx->m_arrTargets.GetCount(); i++)
        {
            int bFound = 0;
            for (unsigned int j = 0; j < kFiltered.GetCount(); j++)
            {
                if (spCtx->m_arrTargets[i] == kFiltered[j])
                {
                    bFound = 1;
                    kFront.Add(kFiltered[j]);
                    kFiltered.RemoveAt(j, 1);
                    break;
                }
            }
            if (bFound == 0)
                kBack.Add(spCtx->m_arrTargets[i]);
        }
        spCtx->m_arrTargets.RemoveAll();
        spCtx->m_arrTargets.Append(kFront);
        spCtx->m_arrTargets.Append(kBack);
    }
    if (pFirst != NULL)
        spCtx->m_arrTargets.InsertAt(0, pFirst, 1);
}

// @0x1409fe440
void CBaseCollision::Invalidate()
{
    m_bBuilt = 0;
}

// Fills pHit for the sort modes: x the signed lateral offset (modes 1/2) or its size, y the forward distance, z the
// planar distance of a cylinder test.
// @0x1409fe460
int CBaseCollision::TestShape(efd::Point3 kPos, efd::Point3 kRight, efd::Point3 kDir, CBaseCollision* pShape,
                               CBoxCollision* pBox, Unk_DetectHit* pHit)
{
    bool bHit = false;
    if (pShape->m_nShape == 1 && pBox->m_nShape == 1)
    {
        CBoxCollision* pShapeBox = static_cast<CBoxCollision*>(pShape);
        CBoxCollision* pTargetBox = pBox;
        bHit = NxBoxBoxIntersect(pShapeBox->m_kBox, pTargetBox->m_kBox, true);
        if (bHit)
        {
            NxVec3 kCenter(pTargetBox->m_kBox.GetCenter());
            efd::Point3 kPt(kCenter.x, kCenter.y, kCenter.z);
            NiPlane kFront(kDir, kPos);
            NiPlane kSide(kRight, kPos);
            float fForward = kFront.Distance(kPt);
            float fLateral = kSide.Distance(kPt);
            if (pHit->m_nMode == 2 || pHit->m_nMode == 1)
            {
                pHit->m_kMetric.x = fLateral;
                pHit->m_kMetric.y = FUN_14059d930(fForward);
            }
            else if (pHit->m_nMode == 4 || pHit->m_nMode == 3)
            {
                pHit->m_kMetric.x = FUN_14059d930(fLateral);
                pHit->m_kMetric.y = FUN_14059d930(fForward);
            }
        }
    }
    else if (pShape->m_nShape == 2 && pBox->m_nShape == 1)
    {
        CCylinderCollision* pCyl = static_cast<CCylinderCollision*>(pShape);
        CBoxCollision* pTargetBox = pBox;
        NxVec3 kPoint(pCyl->m_center.x, pCyl->m_center.y, pCyl->m_center.z);
        NxVec3 kParams;
        NxVec3 kBoxCenter(pTargetBox->m_kBox.GetCenter());
        kBoxCenter.setz(pCyl->m_center.z);
        float fDistSq = NxGetUtilLib()->NxPointOBBSqrDist(kPoint, kBoxCenter, pTargetBox->m_kBox.GetExtents(),
                                                          pTargetBox->m_kBox.GetRot(), &kParams);
        if (fDistSq <= pCyl->m_radius * pCyl->m_radius)
        {
            if (pCyl->GetTopZ() > pTargetBox->FUN_140adad80() && pCyl->GetBottomZ() < pTargetBox->FUN_140adad00())
                bHit = true;
            else
                bHit = false;
        }
        if (bHit)
            pHit->m_kMetric.z = fDistSq;
    }
    else if (pShape->m_nShape == 4 && pBox->m_nShape == 1)
    {
        CHoleCylinderCollision* pRing = static_cast<CHoleCylinderCollision*>(pShape);
        CBoxCollision* pTargetBox = pBox;
        if (pRing->Contains(*(const Vector3*)&pTargetBox->m_kBox.center))
        {
            bHit = true;
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                if (pRing->Contains(reinterpret_cast<const Vector3&>(pTargetBox->m_akCorners[i])))
                {
                    bHit = true;
                    break;
                }
            }
        }
        if (!bHit && pTargetBox->FUN_140adad80() < pRing->GetTop() && pTargetBox->FUN_140adad00() > pRing->GetBottom())
        {
            NiPoint3 kBoxCenter(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(FUN_141b6e150(reinterpret_cast<const Unk_UtilFloat3*>(&pTargetBox->m_kBox.center)))));
            kBoxCenter.z = 0.0f;
            NiPoint3 kRingCenter(*(const efd::Point3*)&pRing->m_ptCenter);
            kRingCenter.z = 0.0f;
            NiPoint3 kAxis(kBoxCenter - kRingCenter);
            kAxis.Unitize();
            NxVec3 kInner = FUN_141b6e0e0(kRingCenter + kAxis * pRing->m_fInnerRadius);
            NxVec3 kOuter = FUN_141b6e0e0(kRingCenter + kAxis * pRing->m_fOuterRadius);
            NxSegment kSegment(kInner, kOuter);
            float fDistSq = NxGetUtilLib()->NxSegmentOBBSqrDist(kSegment, FUN_141b6e0e0(kBoxCenter),
                                                                pTargetBox->m_kBox.GetExtents(), pTargetBox->m_kBox.GetRot(),
                                                                NULL, NULL);
            float fLimit = std::min(150.0f, pRing->m_fOuterRadius - pRing->m_fInnerRadius);
            bHit = fLimit > fDistSq;
        }
        if (bHit)
            pHit->m_kMetric.z = GetPlanarDistance(*(const Vector3*)&pRing->m_ptCenter,
                                              FUN_141b6e150(reinterpret_cast<const Unk_UtilFloat3*>(&pTargetBox->m_kBox.center)));
    }
    else if (pShape->m_nShape == 3 && pBox->m_nShape == 1)
    {
        CFrustumCollision* pFrustum = static_cast<CFrustumCollision*>(pShape);
        CBoxCollision* pTargetBox = pBox;
        if (pFrustum->GetMaxZ() > pTargetBox->FUN_140adad80())
        {
            if (pFrustum->GetMinZ() < pTargetBox->FUN_140adad00())
            {
                if (pFrustum->Contains(*(const Vector3*)&pTargetBox->m_kBox.center))
                {
                    bHit = true;
                }
                else
                {
                    for (int i = 0; i < 8; i++)
                    {
                        if (pFrustum->Contains(reinterpret_cast<const Vector3&>(pTargetBox->m_akCorners[i])))
                        {
                            bHit = true;
                            break;
                        }
                    }
                    if (!bHit)
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            if (pTargetBox->FUN_140adacb0(pFrustum->m_aCorners[i]))
                            {
                                bHit = true;
                                break;
                            }
                        }
                        if (!bHit && pFrustum->IntersectsBox(&pTargetBox->m_kBox))
                            bHit = true;
                    }
                }
            }
        }
        if (bHit)
        {
            NxVec3 kCenter(pTargetBox->m_kBox.GetCenter());
            efd::Point3 kPt(kCenter.x, kCenter.y, kCenter.z);
            NiPlane kFront(kDir, kPos);
            NiPlane kSide(kRight, kPos);
            float fForward = kFront.Distance(kPt);
            float fLateral = kSide.Distance(kPt);
            if (pHit->m_nMode == 2 || pHit->m_nMode == 1)
            {
                pHit->m_kMetric.x = fLateral;
                pHit->m_kMetric.y = FUN_14059d930(fForward);
            }
            else if (pHit->m_nMode == 4 || pHit->m_nMode == 3)
            {
                pHit->m_kMetric.x = FUN_14059d930(fLateral);
                pHit->m_kMetric.y = FUN_14059d930(fForward);
            }
        }
    }
    return bHit;
}

// TestShape without the sort metrics (0x140ded420, 0x141231730).
// @0x1409ff0d0
// MS2-FUNCTIONAL: 1 byte off: the exe returns the null early-out as xor eax,eax (cl emits xor al,al for every spelling tried)
int CBaseCollision::Intersect(CBaseCollision* pShape, CBaseCollision* pTarget)
{
    if (pShape == NULL || pTarget == NULL)
        return false;
    {
        bool bHit = false;
        if (pShape->m_nShape == 1 && pTarget->m_nShape == 1)
        {
            CBoxCollision* pShapeBox = static_cast<CBoxCollision*>(pShape);
            CBoxCollision* pTargetBox = static_cast<CBoxCollision*>(pTarget);
            bHit = NxBoxBoxIntersect(pShapeBox->m_kBox, pTargetBox->m_kBox, true);
        }
        else if (pShape->m_nShape == 2 && pTarget->m_nShape == 1)
        {
            CCylinderCollision* pCyl = static_cast<CCylinderCollision*>(pShape);
            CBoxCollision* pBox = static_cast<CBoxCollision*>(pTarget);
            NxVec3 kPoint(pCyl->m_center.x, pCyl->m_center.y, pCyl->m_center.z);
            NxVec3 kParams;
            NxVec3 kBoxCenter(pBox->m_kBox.GetCenter());
            kBoxCenter.setz(pCyl->m_center.z);
            float fDistSq = NxGetUtilLib()->NxPointOBBSqrDist(kPoint, kBoxCenter, pBox->m_kBox.GetExtents(),
                                                              pBox->m_kBox.GetRot(), &kParams);
            if (fDistSq <= pCyl->m_radius * pCyl->m_radius)
            {
                if (pCyl->GetTopZ() > pBox->FUN_140adad80() && pCyl->GetBottomZ() < pBox->FUN_140adad00())
                    bHit = true;
                else
                    bHit = false;
            }
        }
        else if (pShape->m_nShape == 4 && pTarget->m_nShape == 1)
        {
            CHoleCylinderCollision* pRing = static_cast<CHoleCylinderCollision*>(pShape);
            CBoxCollision* pBox = static_cast<CBoxCollision*>(pTarget);
            if (pRing->Contains(*(const Vector3*)&pBox->m_kBox.center))
            {
                bHit = true;
            }
            else
            {
                for (int i = 0; i < 8; i++)
                {
                    if (pRing->Contains(reinterpret_cast<const Vector3&>(pBox->m_akCorners[i])))
                    {
                        bHit = true;
                        break;
                    }
                }
            }
            if (!bHit && pBox->FUN_140adad80() < pRing->GetTop() && pBox->FUN_140adad00() > pRing->GetBottom())
            {
                NiPoint3 kBoxCenter(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(FUN_141b6e150(reinterpret_cast<const Unk_UtilFloat3*>(&pBox->m_kBox.center)))));
                kBoxCenter.z = 0.0f;
                NiPoint3 kRingCenter(*(const efd::Point3*)&pRing->m_ptCenter);
                kRingCenter.z = 0.0f;
                NiPoint3 kAxis(kBoxCenter - kRingCenter);
                kAxis.Unitize();
                NxVec3 kInner = FUN_141b6e0e0(kRingCenter + kAxis * pRing->m_fInnerRadius);
                NxVec3 kOuter = FUN_141b6e0e0(kRingCenter + kAxis * pRing->m_fOuterRadius);
                NxSegment kSegment(kInner, kOuter);
                float fDistSq = NxGetUtilLib()->NxSegmentOBBSqrDist(kSegment, FUN_141b6e0e0(kBoxCenter),
                                                                    pBox->m_kBox.GetExtents(),
                                                                    pBox->m_kBox.GetRot(), NULL, NULL);
                float fLimit = std::min(150.0f, pRing->m_fOuterRadius - pRing->m_fInnerRadius);
                bHit = fLimit > fDistSq;
            }
        }
        else if (pShape->m_nShape == 3 && pTarget->m_nShape == 1)
        {
            CFrustumCollision* pFrustum = static_cast<CFrustumCollision*>(pShape);
            CBoxCollision* pBox = static_cast<CBoxCollision*>(pTarget);
            if (pFrustum->GetMaxZ() > pBox->FUN_140adad80())
            {
                if (pFrustum->GetMinZ() < pBox->FUN_140adad00())
                {
                    if (pFrustum->Contains(*(const Vector3*)&pBox->m_kBox.center))
                    {
                        bHit = true;
                    }
                    else
                    {
                        for (int i = 0; i < 8; i++)
                        {
                            if (pFrustum->Contains(reinterpret_cast<const Vector3&>(pBox->m_akCorners[i])))
                            {
                                bHit = true;
                                break;
                            }
                        }
                        if (!bHit)
                        {
                            for (int i = 0; i < 8; i++)
                            {
                                if (pBox->FUN_140adacb0(pFrustum->m_aCorners[i]))
                                {
                                    bHit = true;
                                    break;
                                }
                            }
                            if (!bHit && pFrustum->IntersectsBox(&pBox->m_kBox))
                                bHit = true;
                        }
                    }
                }
            }
        }
        return bHit;
    }
}

// The world query's per-object filter: can pSelf target pTarget. nFlags: 1 hostile, 2 friendly, 4 ignore the
// untargetable states, 8 pets (only owner-less ones); nNpcKinds: npc kinds (bit = kind) that are never targets.
// @0x1409ff8d0
static int FilterTarget(GameObject* pSelf, GameObject* pTarget, unsigned int nFlags, unsigned int nNpcKinds)
{
    PCBase* pActor = efd::DynamicCast<PCBase>(pSelf);
    if (pActor == NULL)
        return 0;
    PCBase* pOther = efd::DynamicCast<PCBase>(pTarget);
    if (pOther == NULL)
        return 0;
    unsigned int nExtra = pActor->FUN_1416749a0()->GetForceApplyTarget();
    if (nExtra != 0)
        nFlags |= nExtra;
    if (pOther->vfunc_116() == 2)
        return 0;
    if ((nFlags & 4) == 0)
    {
        if (pOther->FUN_1416749a0()->IsHidden() != 0)
            return 0;
        if (pOther->FUN_14166cb00(6) == true)
            return 0;
        if (pOther->FUN_14166cb00(7) == true)
            return 0;
    }
    PCBase* pActorPC = efd::DynamicCast<PC, PCBase>(reinterpret_cast<PCBase*>(pActor));
    PCBase* pOtherPC = efd::DynamicCast<PC, PCBase>(reinterpret_cast<PCBase*>(pOther));
    CPet* pPet = efd::DynamicCast<CPet>(pOther);
    if ((nFlags & 8) != 0)
    {
        if (pPet != NULL)
            return pPet->GetOwner() == NULL;
    }
    else if (pPet != NULL)
    {
        return 0;
    }
    if (pActorPC != NULL && pOtherPC != NULL && (reinterpret_cast<PC*>(pActorPC)->HasPvPPoint() ^ reinterpret_cast<PC*>(pOtherPC)->HasPvPPoint()) != 0)
        return 0;
    if (nNpcKinds != 0)
    {
        CNpc* pNpc = efd::DynamicCast<CNpc, PCBase>(pOther);
        if (pNpc != NULL)
        {
            int nKind = pNpc->GetNpcClass();
            if ((nNpcKinds & (1 << nKind)) != 0)
                return 0;
        }
    }
    if ((nFlags & 1) != 0)
    {
        int bHostile = 0;
        bHostile = pActor->vfunc_116() == 2 || pActor->vfunc_122(pOther) != 0;
        if (bHostile)
        {
            if (pOtherPC != NULL)
            {
                if (pOtherPC->FUN_141670a00(4) > 0)
                    return 1;
            }
            else
            {
                CNpc* pOtherNpc = efd::DynamicCast<CNpc, PCBase>(pOther);
                if (pOtherNpc != NULL)
                {
                    if (pOtherNpc->FUN_141670a00(4) > 0)
                        return 1;
                    if (pOtherNpc->FUN_141670a00(4) == 0 && pOtherNpc->FUN_1410930a0() != 0)
                        return 1;
                }
            }
        }
    }
    if ((nFlags & 2) != 0 && (pActor->vfunc_116() == 2 || pActor->vfunc_122(pOther) == 0) &&
        pOther->FUN_141670a00(4) > 0)
        return 1;
    return 0;
}

// Fisher-Yates shuffle of the hits (sort mode 0); the swap moves the raw pointers.
// @0x1409ffdd0
static void ShuffleTargets(ATL::CAtlArray<efd::SmartPointer<GameObject> >& arr)
{
    int nCount = (int)arr.GetCount();
    for (int i = nCount - 1; i >= 1; i--)
    {
        int j = rand() % (i + 1);
        if (i != j)
            SwapTargets(arr[i], arr[j]);
    }
}

// @0x1409ffeb0
static void SwapTargets(efd::SmartPointer<GameObject>& a, efd::SmartPointer<GameObject>& b)
{
    // Moves the raw pointers (no reference count traffic).
    unsigned char abTemp[sizeof(efd::SmartPointer<GameObject>)];
    memcpy(abTemp, std::addressof(a), sizeof(abTemp));
    memcpy(std::addressof(a), std::addressof(b), sizeof(abTemp));
    memcpy(std::addressof(b), abTemp, sizeof(abTemp));
}

// The forward and right axes of a z rotation in degrees.
// @0x140a01250
inline void FUN_140a01250(efd::Point3 kRot, efd::Point3* pForward, efd::Point3* pRight)
{
    efd::Point3 kForward = -efd::Point3::UNIT_Y;
    efd::Point3 kRight = -efd::Point3::UNIT_X;
    efd::Matrix3 kMat;
    kMat.MakeZRotation(-kRot.z * 3.1415927f / 180.0f);
    *pForward = kMat * kForward;
    *pRight = kMat * kRight;
}

// Full-executable aliases for CBaseCollision::Intersect's free-function spellings.
// MS2-PIN: ?Intersect@CBaseCollision@@SAHPEAV1@0@Z 0x1409ff0d0
// MS2-PIN: ?FUN_1409ff0d0@@YADPEAVUnk_FcArea@@PEAVCBoxCollision@@@Z 0x1409ff0d0
// MS2-PIN: ?FUN_1409ff0d0@@YADPEAXPEAVCBoxCollision@@@Z 0x1409ff0d0
// MS2-PIN: ?FUN_1409ff0d0@@YA_NPEAX0@Z 0x1409ff0d0
