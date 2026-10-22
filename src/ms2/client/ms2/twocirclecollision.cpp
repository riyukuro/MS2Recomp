// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CTwoCircleCollision: the two-circle (inner/outer radius)
// debug volume of a sound event, drawn as two wire rings. Radius setters live in unit_1416c2c00.
// MS2-UNIT: ?\twocirclecollision.cpp
// MS2-RANGE: 0x141868af0-0x1418694d0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\twocirclecollision.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ctwocirclecollision.h"
#include <math.h>
#include <efd/MemoryDefines.h>
#include <NiMesh.h>
#include <NiDataStreamElementLock.h>
#include <NiCommonSemantics.h>
#include <NiVertexColorProperty.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

NiRenderer* GetNiRenderer();                                        // NiRenderer::GetRenderer()
void FUN_140980f20(NiVertexColorProperty* pProp, int n);            // SetSourceMode
void FUN_140980e60(NiVertexColorProperty* pProp, int n);            // SetLightingMode

static const int kRingPoints = 360;

// @0x141868af0
CTwoCircleCollision::CTwoCircleCollision()
{
    m_nShape = 2;
    m_fInnerRadius = 0.0f;
    m_fOuterRadius = 100.0f;
}

// @0x141868bd0
CTwoCircleCollision::~CTwoCircleCollision()
{
}

// @0x141868c60
void CTwoCircleCollision::vfunc_3(Vector3 ptPos, Vector3 ptDir, float fScale)
{
    if (m_ptCenter.FUN_140552700(ptPos))
    {
        m_ptCenter = ptPos;
        CBaseCollision::vfunc_3(ptPos, ptDir, fScale);
    }
}
MS2_REPLACE_METHOD(0x141868C60, CTwoCircleCollision, vfunc_3, 155, 0xCBA2897D);

// @0x141868d10
void CTwoCircleCollision::vfunc_1()
{
    if (m_bBuilt == 0)
        vfunc_5();
    NiRenderer* pRenderer = GetNiRenderer();
    for (int i = 0; i < 2; i++)
    {
        NiMesh* pMesh = m_aspDraw[i];
        if (pMesh)
            pMesh->RenderImmediate(pRenderer);
    }
}
MS2_REPLACE_METHOD(0x141868D10, CTwoCircleCollision, vfunc_1, 143, 0xC5D47FB4);

// @0x141868db0
// MS2-FUNCTIONAL: identical code/order; pProp and the loop floats take swapped frame slots (exe pProp 0x28,
// fSin 0x30/0x34; ours 0x30, 0x28/0x2c) and the exe also dead-stores 360 to a local before the array ctor.
void CTwoCircleCollision::vfunc_5()
{
    if (!m_spInner)
    {
        m_spInner = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
        NiVertexColorProperty* pProp = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
        FUN_140980f20(pProp, 1);
        FUN_140980e60(pProp, 0);
        m_spInner->AttachProperty(pProp);
        m_spOuter = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
        m_spOuter->AttachProperty(pProp);
    }

    Vector3 aPts[kRingPoints];
    for (int i = 0; i < kRingPoints; i++)
    {
        float fSin = sinf((float)i * 3.1415927f / 180.0f);
        fSin = fSin * m_fInnerRadius;
        aPts[i] = m_ptCenter.FUN_14097fd50(
            Vector3(cosf((float)i * 3.1415927f / 180.0f) * m_fInnerRadius, fSin, 0.0f));
    }
    m_spInner->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    BuildWire(m_spInner, aPts, kRingPoints);
    for (int i = 0; i < kRingPoints; i++)
    {
        float fSin = sinf((float)i * 3.1415927f / 180.0f);
        fSin = fSin * m_fOuterRadius;
        aPts[i] = m_ptCenter.FUN_14097fd50(
            Vector3(cosf((float)i * 3.1415927f / 180.0f) * m_fOuterRadius, fSin, 0.0f));
    }
    m_spOuter->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    BuildWire(m_spOuter, aPts, kRingPoints);
    m_aspDraw[0] = m_spInner;
    m_aspDraw[1] = m_spOuter;
    m_bBuilt = 1;
}
MS2_REPLACE_METHOD(0x141868DB0, CTwoCircleCollision, vfunc_5, 1293, 0x3C30EDE8);

// @0x1418692d0
void CTwoCircleCollision::BuildWire(NiMesh* pMesh, const Vector3* pPoints, unsigned int nCount)
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

// @0x1418694c0
float CTwoCircleCollision::vfunc_6()
{
    return 0.0f;
}
MS2_REPLACE_METHOD(0x1418694C0, CTwoCircleCollision, vfunc_6, 9, 0x4FE1E1A5);
