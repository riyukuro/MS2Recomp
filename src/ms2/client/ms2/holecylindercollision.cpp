// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CHoleCylinderCollision: a hollow-cylinder collision
// volume (inner/outer radius) with six debug wire meshes.
// MS2-UNIT: ?\holecylindercollision.cpp
// MS2-RANGE: 0x140d03650-0x140d05a90 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\holecylindercollision.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "holecylindercollision.h"
#include <math.h>
#include <efd/MemoryDefines.h>
#include <NiMesh.h>
#include <NiDataStreamElementLock.h>
#include <NiCommonSemantics.h>
#include <NiVertexColorProperty.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

NiRenderer* GetNiRenderer();   // NiRenderer::GetRenderer()
void FUN_140980200(NiAVObject* pObj, NiProperty* pProp);            // NiAVObject::AttachProperty
void FUN_140980f20(NiVertexColorProperty* pProp, int n);            // SetSourceMode
void FUN_140980e60(NiVertexColorProperty* pProp, int n);            // SetLightingMode

static const int kRingPoints = 360;

// @0x140d03650
CHoleCylinderCollision::CHoleCylinderCollision()
{
    m_nShape = 4;
    m_fInnerRadius = 0;
    m_fOuterRadius = 0;
    m_fHeight = 0;
}

// @0x140d03780
CHoleCylinderCollision::~CHoleCylinderCollision()
{
}

// @0x140d03840
void CHoleCylinderCollision::vfunc_3(Vector3 ptPos, Vector3 ptDir, float fScale)
{
    m_ptCenter = ptPos;
    CBaseCollision::vfunc_3(ptPos, ptDir, fScale);
}

// @0x140d038d0
float CHoleCylinderCollision::vfunc_6()
{
    return m_fHeight;
}

// @0x140d038f0
float CHoleCylinderCollision::GetTop() const
{
    return m_ptCenter.z + m_fHeight;
}

// @0x140d03920
float CHoleCylinderCollision::GetBottom() const
{
    return m_ptCenter.z - m_ptSize.z;
}

// @0x140d03950
int CHoleCylinderCollision::Contains(const Vector3& pt) const
{
    return ContainsPoint(Vector3(pt.x, pt.y, pt.z));
}

// @0x140d039a0
int CHoleCylinderCollision::ContainsPoint(const Vector3& pt) const
{
    if (GetBottom() > pt.z || GetTop() < pt.z)
        return 0;
    float fDist = FUN_140966ea0(pt, m_ptCenter);
    if (fDist < m_fInnerRadius || fDist > m_fOuterRadius)
        return 0;
    return 1;
}

// @0x140d056f0
void CHoleCylinderCollision::BuildWire(NiMesh* pMesh, const Vector3* pPoints, unsigned int nCount)
{
    pMesh->RemoveAllStreamRefs();
    pMesh->AddStream(NiCommonSemantics::POSITION(), 0, NiDataStreamElement::F_FLOAT32_3, nCount, 0x13,
                     NiDataStream::USAGE_VERTEX, pPoints, false, true);
    NiDataStreamElementLock kLock = pMesh->AddStreamGetLock(NiCommonSemantics::COLOR(), 0,
        NiDataStreamElement::F_FLOAT32_4, nCount, 0x12, NiDataStream::USAGE_VERTEX, false, true, 2);
    NiTStridedRandomAccessIterator<NiColorA> it = kLock.begin<NiColorA>(0);
    for (int i = 0; i < (int)nCount; i++)
        it[i] = m_kColor;
    kLock.Unlock();
    pMesh->Update(0.0f, true);
    pMesh->UpdateProperties();
    pMesh->UpdateEffects();
    pMesh->UpdateNodeBound();
    pMesh->SetSelectiveUpdate(true);
}

// @0x140d05650
void CHoleCylinderCollision::vfunc_1()
{
    if (m_bBuilt == 0)
        vfunc_5();
    NiRenderer* pRenderer = GetNiRenderer();
    for (int i = 0; i < 6; i++)
    {
        NiMesh* pMesh = m_aspDraw[i];
        if (pMesh)
            pMesh->RenderImmediate(pRenderer);
    }
}

// @0x140d03a60
// MS2-FUNCTIONAL: the exe builds the ring points with 30 separately unrolled temporaries; this loops over a table.
void CHoleCylinderCollision::vfunc_5()
{
    m_bBuilt = 1;
    if (!m_spOuterTop)
    {
        NiVertexColorProperty* pProp = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
        FUN_140980f20(pProp, 1);
        FUN_140980e60(pProp, 0);
        NiMeshPtr* apTarget[5] = { &m_spInnerTop, &m_spInnerBottom, &m_spOuterTop, &m_spOuterBottom, &m_spLines };
        for (int i = 0; i < 5; i++)
        {
            *apTarget[i] = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
            FUN_140980200(*apTarget[i], pProp);
        }
    }

    Vector3 aPts[kRingPoints];
    struct Ring { NiMeshPtr* pMesh; float fRadius; float fZ; };
    float fTop = GetTop() - m_ptCenter.z;
    float fBottom = GetBottom() - m_ptCenter.z;
    Ring aRings[5] = {
        { &m_spMesh,        m_fOuterRadius, 0.0f },
        { &m_spInnerTop,    m_fInnerRadius, fTop },
        { &m_spInnerBottom, m_fInnerRadius, fBottom },
        { &m_spOuterTop,    m_fOuterRadius, fTop },
        { &m_spOuterBottom, m_fOuterRadius, fBottom },
    };
    for (int r = 0; r < 5; r++)
    {
        for (int i = 0; i < kRingPoints; i++)
        {
            float fSin = sinf((float)i * 3.1415927f / 180.0f) * aRings[r].fRadius;
            float fCos = cosf((float)i * 3.1415927f / 180.0f);
            aPts[i] = m_ptCenter.FUN_14097fd50(Vector3(fCos * aRings[r].fRadius, fSin, aRings[r].fZ));
        }
        (*aRings[r].pMesh)->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
        BuildWire(*aRings[r].pMesh, aPts, kRingPoints);
    }

    // Radial edges: the four axis points at both radii on the bottom ring, the same on the top ring, then the
    // vertical lines joining them.
    int n = 0;
    const float aZ[2] = { fBottom, fTop };
    const float aR[2] = { m_fOuterRadius, m_fInnerRadius };
    for (int z = 0; z < 2; z++)
    {
        for (int axis = 0; axis < 2; axis++)
        {
            for (int ri = 0; ri < 2; ri++)
            {
                float fR = aR[ri];
                float fX = axis == 0 ? -fR : 0.0f;
                float fY = axis == 0 ? 0.0f : -fR;
                aPts[n++] = m_ptCenter.FUN_14097fd50(Vector3(fX, fY, aZ[z]));
                aPts[n++] = m_ptCenter.FUN_14097fd50(Vector3(-fX, -fY, aZ[z]));
            }
        }
    }
    for (int ri = 0; ri < 2; ri++)
    {
        float fR = aR[ri];
        const float aX[4] = { -fR, fR, 0.0f, 0.0f };
        const float aY[4] = { 0.0f, 0.0f, -fR, fR };
        for (int k = 0; k < 4; k++)
        {
            aPts[n++] = m_ptCenter.FUN_14097fd50(Vector3(aX[k], aY[k], fBottom));
            aPts[n++] = m_ptCenter.FUN_14097fd50(Vector3(aX[k], aY[k], fTop));
        }
    }
    m_spLines->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINES);
    BuildWire(m_spLines, aPts, n);

    m_aspDraw[0] = m_spMesh;
    m_aspDraw[1] = m_spOuterTop;
    m_aspDraw[2] = m_spOuterBottom;
    m_aspDraw[3] = m_spLines;
    m_aspDraw[4] = m_spInnerTop;
    m_aspDraw[5] = m_spInnerBottom;
}

// @0x140d05970
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
