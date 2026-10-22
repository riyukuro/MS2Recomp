// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CFrustumCollision: a view-frustum shaped collision volume
// (near/far half widths, height, depth) with a 16-point wire outline.
// MS2-UNIT: ?\frustumcollision.cpp
// MS2-RANGE: 0x141222df0-0x141225080 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\frustumcollision.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "frustumcollision.h"
#include <math.h>
#include <float.h>
#include <efd/MemoryDefines.h>
#include <NiMesh.h>
#include <NiDataStreamElementLock.h>
#include <NiCommonSemantics.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

float FUN_141224f30(float fY, float fX);   // atan2 wrapper
extern "C" float (__cdecl* __imp_cosf)(float);

// efd::Point2 (x, y) as used by the 2D edge tests; operator- and Length live in another obj.
struct Unk_FcPoint2 : public NiPoint2
{
    Unk_FcPoint2(float fX, float fY);                           // 0x140a0a4c0
    Unk_FcPoint2 FUN_140a4e500(const Unk_FcPoint2& pt) const;   // operator-
    float FUN_140affe70() const;                                // Length
};

void FUN_140a01250(Vector3 ptRot, Vector3* pForward, Vector3* pRight);   // basis from a z rotation (degrees)
void FUN_140adc650(const void* pBox, Unk_FcNxVec3* pCorners);   // NxUtilLib::NxComputeBoxPoints

static const Unk_FcPoint2& AsPoint2(const NiPoint2& pt)
{
    return reinterpret_cast<const Unk_FcPoint2&>(pt);
}

static const Vector3& AsPoint3(const Unk_FcPoint3& pt)
{
    return reinterpret_cast<const Vector3&>(pt);
}

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
// MS2-FUNCTIONAL: the exe expands the corner arithmetic with one set of Point3 temporaries per term
void CFrustumCollision::vfunc_3(Vector3 ptPos, Vector3 ptDir, float fScale)
{
    FUN_140a01250(ptDir, &m_ptForward, &m_ptRight);
    m_ptForward.FUN_140968990();
    m_ptRight.FUN_140968990();

    m_ptOrigin = ptPos.FUN_14097fd50(m_ptForward.FUN_14097fc90(-m_ptSize.y)).FUN_14097fd50(Vector3(0.0f, 0.0f, -m_ptSize.z));
    m_ptApex = m_ptOrigin.FUN_14097fd50(m_ptForward.FUN_14097fc90(-m_fApexDist));

    float fTwiceH = m_fHeight * 2.0f;
    m_aCorners[0] = m_ptOrigin.FUN_14097fd50(m_ptRight.FUN_14097fc90(-m_fNearHalfWidth)).FUN_14097fd50(Vector3(0.0f, 0.0f, fTwiceH));
    m_aCorners[1] = m_ptOrigin.FUN_14097fd50(m_ptRight.FUN_14097fc90(-m_fNearHalfWidth)).FUN_14097fd50(Vector3(0.0f, 0.0f, 0.0f));
    m_aCorners[2] = m_ptOrigin.FUN_14097fd50(m_ptRight.FUN_14097fc90(m_fNearHalfWidth)).FUN_14097fd50(Vector3(0.0f, 0.0f, 0.0f));
    m_aCorners[3] = m_ptOrigin.FUN_14097fd50(m_ptRight.FUN_14097fc90(m_fNearHalfWidth)).FUN_14097fd50(Vector3(0.0f, 0.0f, fTwiceH));

    Vector3 ptFar = m_ptOrigin.FUN_14097fd50(m_ptForward.FUN_14097fc90(m_fDepth));
    m_aCorners[4] = ptFar.FUN_14097fd50(m_ptRight.FUN_14097fc90(-m_fFarHalfWidth)).FUN_14097fd50(Vector3(0.0f, 0.0f, fTwiceH));
    m_aCorners[5] = ptFar.FUN_14097fd50(m_ptRight.FUN_14097fc90(-m_fFarHalfWidth)).FUN_14097fd50(Vector3(0.0f, 0.0f, 0.0f));
    m_aCorners[6] = ptFar.FUN_14097fd50(m_ptRight.FUN_14097fc90(m_fFarHalfWidth)).FUN_14097fd50(Vector3(0.0f, 0.0f, 0.0f));
    m_aCorners[7] = ptFar.FUN_14097fd50(m_ptRight.FUN_14097fc90(m_fFarHalfWidth)).FUN_14097fd50(Vector3(0.0f, 0.0f, fTwiceH));

    m_aEdgeA[0] = Unk_NiPoint3(m_ptApex);
    m_aEdgeA[1] = Unk_NiPoint3(m_aCorners[4]);
    m_aEdgeA[2] = Unk_NiPoint3(m_aCorners[7]);
    m_aEdgeB[0] = Unk_NiPoint3(m_ptApex);
    m_aEdgeB[1] = Unk_NiPoint3(m_aCorners[5]);
    m_aEdgeB[2] = Unk_NiPoint3(m_aCorners[6]);

    m_akEdge2[0] = Unk_FcPoint2(m_aEdgeA[0].x, m_aEdgeA[0].y);
    m_akEdge2[1] = Unk_FcPoint2(m_aEdgeA[1].x, m_aEdgeA[1].y);
    m_akEdge2[2] = Unk_FcPoint2(m_aEdgeA[0].x, m_aEdgeA[0].y);
    m_akEdge2[3] = Unk_FcPoint2(m_aEdgeA[2].x, m_aEdgeA[2].y);

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
    float fDepth = m_ptForward.FUN_140a00f20(kRel);
    if (fDepth <= 0.0f || m_fDepth <= fDepth)
        return 0;
    Vector3 kDir = pt.FUN_140965c40(m_ptApex);
    kDir.z = 0.0f;
    kDir.FUN_140968990();
    float fDot = m_ptForward.FUN_140a00f20(kDir);
    if (fDot > __imp_cosf(m_fHalfAngle))
        return 1;
    return 0;
}

// @0x141223e70
// MS2-FUNCTIONAL: tests the box's four ground-plane edges against the two side edges of the frustum
int CFrustumCollision::IntersectsBox(const void* pBox) const
{
    Unk_FcNxVec3 aBoxCorners[8];
    FUN_140adc650(pBox, aBoxCorners);

    NiPoint2 akBoxEdge[8];
    akBoxEdge[0] = Unk_FcPoint2(aBoxCorners[0].x, aBoxCorners[0].y);
    akBoxEdge[1] = Unk_FcPoint2(aBoxCorners[1].x, aBoxCorners[1].y);
    akBoxEdge[2] = Unk_FcPoint2(aBoxCorners[1].x, aBoxCorners[1].y);
    akBoxEdge[3] = Unk_FcPoint2(aBoxCorners[2].x, aBoxCorners[2].y);
    akBoxEdge[4] = Unk_FcPoint2(aBoxCorners[2].x, aBoxCorners[2].y);
    akBoxEdge[5] = Unk_FcPoint2(aBoxCorners[3].x, aBoxCorners[3].y);
    akBoxEdge[6] = Unk_FcPoint2(aBoxCorners[3].x, aBoxCorners[3].y);
    akBoxEdge[7] = Unk_FcPoint2(aBoxCorners[0].x, aBoxCorners[0].y);

    NiPoint2 kHit;
    Unk_FcPoint3 kDirA, kDirB, kPtA, kPtB;
    kDirA = Unk_NiPoint3(AsPoint3(m_aEdgeA[1]).FUN_140965c40(AsPoint3(m_aEdgeA[0])));
    float fLenA = kDirA.FUN_140968990();
    kDirB = Unk_NiPoint3(AsPoint3(m_aEdgeB[1]).FUN_140965c40(AsPoint3(m_aEdgeB[0])));
    float fLenB = kDirB.FUN_140968990();

    for (int nSide = 0; nSide < 2; nSide++)
    {
        int nFirst = nSide * 2;
        float fSideLen = AsPoint2(m_akEdge2[nFirst + 1]).FUN_140a4e500(AsPoint2(m_akEdge2[nFirst])).FUN_140affe70();
        for (int nEdge = 0; nEdge < 4; nEdge++)
        {
            int nBox = nEdge * 2;
            if (!SegmentIntersect(&m_akEdge2[nFirst], &m_akEdge2[nFirst + 1], &akBoxEdge[nBox], &akBoxEdge[nBox + 1], &kHit))
                continue;
            float fHitLen = AsPoint2(kHit).FUN_140a4e500(AsPoint2(m_akEdge2[nFirst])).FUN_140affe70();
            if (m_fApexDist < fHitLen)
            {
                float fT = fHitLen / fSideLen;
                kPtA = Unk_NiPoint3(AsPoint3(m_aEdgeA[0]).FUN_14097fd50(AsPoint3(kDirA).FUN_14097fc90(fLenA * fT)));
                kPtB = Unk_NiPoint3(AsPoint3(m_aEdgeB[0]).FUN_14097fd50(AsPoint3(kDirB).FUN_14097fc90(fLenB * fT)));
                bool bBelow = kPtA.z < aBoxCorners[0].z;
                bool bAbove = aBoxCorners[4].z < kPtB.z;
                if (!bBelow && !bAbove)
                    return 1;
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
    return atan2f(fY, fX);
}

// @0x141224f60
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
