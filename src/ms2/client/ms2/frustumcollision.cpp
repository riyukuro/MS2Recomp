// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CFrustumCollision: a view-frustum shaped collision volume
// (near/far half widths, height, depth) with a 16-point wire outline.
// MS2-UNIT: ?\frustumcollision.cpp
// MS2-RANGE: 0x141222df0-0x141225080 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\frustumcollision.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "frustumcollision.h"
#pragma push_macro("min")
#pragma push_macro("max")
#undef min
#undef max
#include <NxVec3.h>       // C3: the box corners
#pragma pop_macro("max")
#pragma pop_macro("min")
#include <math.h>
#include <cmath>
#include <float.h>
#include <efd/MemoryDefines.h>
#include <NiMesh.h>
#include <NiDataStreamElementLock.h>
#include <NiCommonSemantics.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

float FUN_141224f30(float fY, float fX);   // atan2 wrapper
extern "C" float (__cdecl* __imp_cosf)(float);

// The efd::Point2 length getter 0x140affe70 is defined on the Unk_Point2 view (cameratargetboundingbox.cpp).
struct Unk_Point2
{
    float FUN_140affe70() const;                                // length
    float x, y;
};

void FUN_140a01250(efd::Point3 ptRot, efd::Point3* pForward, efd::Point3* pRight);   // basis from a z rotation (degrees; C3: the definer types it on efd::Point3)
bool NxComputeBoxPoints(class NxBox const&, class NxVec3*);   // C3: was FUN_140adc650

// Free reinterpretations: the exe calls the efd::Point2 / NiPoint3 helpers on the members directly.
#define AsPoint2(pt) static_cast<const efd::Point2&>(pt)
#define AsLen2(pt) reinterpret_cast<const Unk_Point2&>(static_cast<const efd::Point2&>(pt))
#define AsPoint3(pt) reinterpret_cast<const Vector3&>(pt)

// @0x141222df0
CFrustumCollision::CFrustumCollision()
{
    m_nShape = 3;
}

// @0x141222f20
CFrustumCollision::~CFrustumCollision()
{
}

// @0x141222f50
void CFrustumCollision::vfunc_3(Vector3 ptPos, Vector3 ptDir, float fScale)
{
    Vector3 ptRot = ptDir;
    FUN_140a01250(reinterpret_cast<efd::Point3&>(ptRot), reinterpret_cast<efd::Point3*>(&m_ptForward), reinterpret_cast<efd::Point3*>(&m_ptRight));
    m_ptForward.FUN_140968990();
    m_ptRight.FUN_140968990();

    m_ptOrigin = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>((reinterpret_cast<const efd::Point3&>(ptPos) + reinterpret_cast<const efd::Point3&>(m_ptForward) * (-m_ptSize.y)) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, -m_ptSize.z)))));
    m_ptApex = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptOrigin) + reinterpret_cast<const efd::Point3&>(m_ptForward) * (-m_fApexDist)));

    m_spMesh->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    m_spMesh->RemoveAllStreamRefs();
    m_aCorners[0] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>((reinterpret_cast<const efd::Point3&>(m_ptOrigin) + reinterpret_cast<const efd::Point3&>(m_ptRight) * (-m_fNearHalfWidth)) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, m_fHeight * 2.0f)))));
    m_aCorners[1] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>((reinterpret_cast<const efd::Point3&>(m_ptOrigin) + reinterpret_cast<const efd::Point3&>(m_ptRight) * (-m_fNearHalfWidth)) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, 0.0f)))));
    m_aCorners[2] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>((reinterpret_cast<const efd::Point3&>(m_ptOrigin) + reinterpret_cast<const efd::Point3&>(m_ptRight) * m_fNearHalfWidth) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, 0.0f)))));
    m_aCorners[3] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>((reinterpret_cast<const efd::Point3&>(m_ptOrigin) + reinterpret_cast<const efd::Point3&>(m_ptRight) * m_fNearHalfWidth) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, m_fHeight * 2.0f)))));

    m_aCorners[4] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(((reinterpret_cast<const efd::Point3&>(m_ptOrigin) + reinterpret_cast<const efd::Point3&>(m_ptForward) * m_fDepth) + reinterpret_cast<const efd::Point3&>(m_ptRight) * (-m_fFarHalfWidth)) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, m_fHeight * 2.0f)))));
    m_aCorners[5] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(((reinterpret_cast<const efd::Point3&>(m_ptOrigin) + reinterpret_cast<const efd::Point3&>(m_ptForward) * m_fDepth) + reinterpret_cast<const efd::Point3&>(m_ptRight) * (-m_fFarHalfWidth)) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, 0.0f)))));
    m_aCorners[6] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(((reinterpret_cast<const efd::Point3&>(m_ptOrigin) + reinterpret_cast<const efd::Point3&>(m_ptForward) * m_fDepth) + reinterpret_cast<const efd::Point3&>(m_ptRight) * m_fFarHalfWidth) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, 0.0f)))));
    m_aCorners[7] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(((reinterpret_cast<const efd::Point3&>(m_ptOrigin) + reinterpret_cast<const efd::Point3&>(m_ptForward) * m_fDepth) + reinterpret_cast<const efd::Point3&>(m_ptRight) * m_fFarHalfWidth) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, 0.0f, m_fHeight * 2.0f)))));

    m_aEdgeA[0] = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(m_ptApex))));
    m_aEdgeA[1] = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(m_aCorners[4]))));
    m_aEdgeA[2] = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(m_aCorners[7]))));
    m_aEdgeB[0] = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(m_ptApex))));
    m_aEdgeB[1] = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(m_aCorners[5]))));
    m_aEdgeB[2] = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(m_aCorners[6]))));

    m_akEdge2[0] = NiPoint2(m_aEdgeA[0].x, m_aEdgeA[0].y);
    m_akEdge2[1] = NiPoint2(m_aEdgeA[1].x, m_aEdgeA[1].y);
    m_akEdge2[2] = NiPoint2(m_aEdgeA[0].x, m_aEdgeA[0].y);
    m_akEdge2[3] = NiPoint2(m_aEdgeA[2].x, m_aEdgeA[2].y);

    CBaseCollision::vfunc_3(ptPos, ptDir, fScale);
}

// @0x141223bc0
void CFrustumCollision::vfunc_4()
{
    m_fDepth = m_fDepth + m_ptSize.y;
    m_fHeight = m_fHeight + m_ptSize.z / 2.0f;
    m_fApexDist = (m_fDepth * m_fNearHalfWidth) / (m_fFarHalfWidth - m_fNearHalfWidth);
    m_fTan = (m_fHeight * (m_fDepth + m_fApexDist)) / m_fApexDist;
    m_fVertAngle = FUN_141224f30(m_fTan, m_fDepth + m_fApexDist);
    m_fHalfAngle = FUN_141224f30(m_fFarHalfWidth, m_fDepth + m_fApexDist);
}

// @0x141223d30
int CFrustumCollision::Contains(const Vector3& pt) const
{
    return ContainsPoint(Vector3(pt.x, pt.y, pt.z));
}

// @0x141223d80
int CFrustumCollision::ContainsPoint(const Vector3& pt) const
{
    Vector3 kRel = pt.FUN_140965c40(m_ptOrigin);
    float fDepth = reinterpret_cast<const efd::Point3&>(m_ptForward).Dot(reinterpret_cast<const efd::Point3&>(kRel));
    if (fDepth <= 0.0f || m_fDepth <= fDepth)
        return 0;
    Vector3 kDir = pt.FUN_140965c40(m_ptApex);
    kDir.z = 0.0f;
    kDir.FUN_140968990();
    float fDot = reinterpret_cast<const efd::Point3&>(m_ptForward).Dot(reinterpret_cast<const efd::Point3&>(kDir));
    if (fDot > __imp_cosf(m_fHalfAngle))
        return 1;
    return 0;
}

// @0x141223e70
int CFrustumCollision::IntersectsBox(const void* pBox) const
{
    NxVec3 aBoxCorners[8];
    NxComputeBoxPoints(*(class NxBox const*)(pBox), (class NxVec3*)(aBoxCorners));

    NiPoint2 akBoxEdge[8];
    akBoxEdge[0] = NiPoint2(aBoxCorners[0].x, aBoxCorners[0].y);
    akBoxEdge[1] = NiPoint2(aBoxCorners[1].x, aBoxCorners[1].y);
    akBoxEdge[2] = NiPoint2(aBoxCorners[1].x, aBoxCorners[1].y);
    akBoxEdge[3] = NiPoint2(aBoxCorners[2].x, aBoxCorners[2].y);
    akBoxEdge[4] = NiPoint2(aBoxCorners[2].x, aBoxCorners[2].y);
    akBoxEdge[5] = NiPoint2(aBoxCorners[3].x, aBoxCorners[3].y);
    akBoxEdge[6] = NiPoint2(aBoxCorners[3].x, aBoxCorners[3].y);
    akBoxEdge[7] = NiPoint2(aBoxCorners[0].x, aBoxCorners[0].y);

    NiPoint2 kHit;
    NiPoint3 kDirA, kDirB, kPtA, kPtB;
    kDirA = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(AsPoint3(m_aEdgeA[1]).FUN_140965c40(AsPoint3(m_aEdgeA[0]))))));
    float fLenA = reinterpret_cast<Vector3&>(kDirA).FUN_140968990();
    kDirB = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(AsPoint3(m_aEdgeB[1]).FUN_140965c40(AsPoint3(m_aEdgeB[0]))))));
    float fLenB = reinterpret_cast<Vector3&>(kDirB).FUN_140968990();

    for (unsigned nSide = 0; nSide < 2; nSide++)
    {
        unsigned nFirst = nSide * 2;
        float fSideLen = AsLen2(AsPoint2(m_akEdge2[nFirst + 1]) - AsPoint2(m_akEdge2[nFirst])).FUN_140affe70();
        for (unsigned nEdge = 0; nEdge < 4; nEdge++)
        {
            unsigned nBox = nEdge * 2;
            NiPoint2 kSideDir(AsPoint2(m_akEdge2[nFirst + 1]) - AsPoint2(m_akEdge2[nFirst]));   // computed and never read
            if (SegmentIntersect(&m_akEdge2[nFirst], &m_akEdge2[nFirst + 1], &akBoxEdge[nBox], &akBoxEdge[nBox + 1], &kHit))
            {
                float fHitLen = AsLen2(AsPoint2(kHit) - AsPoint2(m_akEdge2[nFirst])).FUN_140affe70();
                if (fHitLen > m_fApexDist)
                {
                    float fT = fHitLen / fSideLen;
                    kPtA = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(AsPoint3(m_aEdgeA[0]))) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(AsPoint3(kDirA))) * (fLenA * fT)))))));
                    kPtB = static_cast<NiPoint3&&>(const_cast<NiPoint3&>(reinterpret_cast<const NiPoint3&>(static_cast<const Unk_NiPoint3&>(reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(AsPoint3(m_aEdgeB[0]))) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(AsPoint3(kDirB))) * (fLenB * fT)))))));
                    BOOL bBelow = kPtA.z < aBoxCorners[0].z;
                    BOOL bAbove = kPtB.z > aBoxCorners[4].z;
                    if (!bBelow && !bAbove)
                        return 1;
                }
            }
        }
    }
    return 0;
}

// @0x1412245a0
int CFrustumCollision::SegmentIntersect(const NiPoint2* pA1, const NiPoint2* pA2, const NiPoint2* pB1,
                                        const NiPoint2* pB2, NiPoint2* pOut) const
{
    float fDet = (pB2->y - pB1->y) * (pA2->x - pA1->x) - (pB2->x - pB1->x) * (pA2->y - pA1->y);
    if (fDet == 0.0f)
        return 0;
    float fNumT = (pB2->x - pB1->x) * (pA1->y - pB1->y) - (pB2->y - pB1->y) * (pA1->x - pB1->x);
    float fNumU = (pA2->x - pA1->x) * (pA1->y - pB1->y) - (pA2->y - pA1->y) * (pA1->x - pB1->x);
    float fT = fNumT / fDet;
    float fU = fNumU / fDet;
    if (fT < 0.0 || 1.0 < fT || fU < 0.0 || 1.0 < fU)
        return 0;
    if (fNumT == 0.0f && fNumU == 0.0f)
        return 0;
    pOut->x = pA1->x + fT * (pA2->x - pA1->x);
    pOut->y = pA1->y + fT * (pA2->y - pA1->y);
    return 1;
}

// @0x141224800
float CFrustumCollision::vfunc_6()
{
    return m_fHeight * 2.0f;
}

// @0x141224820
float CFrustumCollision::GetMaxZ() const
{
    float fMax = FLT_MIN;
    for (int i = 0; i < 8; i++)
    {
        if (fMax < m_aCorners[i].z)
            fMax = m_aCorners[i].z;
    }
    return fMax;
}

// @0x1412248a0
float CFrustumCollision::GetMinZ() const
{
    float fMin = FLT_MAX;
    for (int i = 0; i < 8; i++)
    {
        if (m_aCorners[i].z < fMin)
            fMin = m_aCorners[i].z;
    }
    return fMin;
}

// @0x141224920
void CFrustumCollision::vfunc_5()
{
    m_bBuilt = 1;
    m_spMesh->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    m_spMesh->RemoveAllStreamRefs();

    int nPoints = 16;
    Vector3 aPts[16];
    aPts[0] = m_aCorners[0];
    aPts[1] = m_aCorners[3];
    aPts[2] = m_aCorners[2];
    aPts[3] = m_aCorners[1];
    aPts[4] = m_aCorners[0];
    aPts[5] = m_aCorners[4];
    aPts[6] = m_aCorners[7];
    aPts[7] = m_aCorners[6];
    aPts[8] = m_aCorners[5];
    aPts[9] = m_aCorners[4];
    aPts[10] = m_aCorners[5];
    aPts[11] = m_aCorners[1];
    aPts[12] = m_aCorners[2];
    aPts[13] = m_aCorners[6];
    aPts[14] = m_aCorners[7];
    aPts[15] = m_aCorners[3];

    m_spMesh->AddStream(NiCommonSemantics::POSITION(), 0, NiDataStreamElement::F_FLOAT32_3, 16, 0x13,
                        NiDataStream::USAGE_VERTEX, aPts, false, true);
    {
        NiDataStreamElementLock kLock = m_spMesh->AddStreamGetLock(NiCommonSemantics::COLOR(), 0,
            NiDataStreamElement::F_FLOAT32_4, 16, 0x12, NiDataStream::USAGE_VERTEX, false, true, 2);
        NiTStridedRandomAccessIterator<NiColorA> it = kLock.begin<NiColorA>(0);
        for (int i = 0; i < 16; i++)
            it[i] = m_kColor;
        kLock.Unlock();
    }
    m_spMesh->Update(0.0f, true);
    m_spMesh->UpdateProperties();
    m_spMesh->UpdateEffects();
    m_spMesh->UpdateNodeBound();
    m_spMesh->SetSelectiveUpdate(true);
}

// @0x141224f30
float FUN_141224f30(float fY, float fX)
{
    return atan2(fY, fX);      // <cmath>'s float overload (0x140a4e660, one folded copy)
}

// @0x141224f60
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
