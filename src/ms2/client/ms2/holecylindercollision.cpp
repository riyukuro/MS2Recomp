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

extern "C" float (__cdecl* __imp_sinf)(float);                      // the exe calls the CRT imports
extern "C" float (__cdecl* __imp_cosf)(float);

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
void CHoleCylinderCollision::vfunc_3(NiPoint3 ptPos, NiPoint3 ptDir, float fScale)
{
    m_ptCenter = reinterpret_cast<const Vector3&>(ptPos);
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
void CHoleCylinderCollision::vfunc_5()
{
    m_bBuilt = 1;
    if (!m_spOuterTop)
    {
        NiVertexColorProperty* pProp = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
        pProp->SetSourceMode(NiVertexColorProperty::SOURCE_EMISSIVE);
        pProp->SetLightingMode(NiVertexColorProperty::LIGHTING_E);
        m_spInnerTop = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
        m_spInnerTop->AttachProperty(pProp);
        m_spInnerBottom = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
        m_spInnerBottom->AttachProperty(pProp);
        m_spOuterTop = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
        m_spOuterTop->AttachProperty(pProp);
        m_spOuterBottom = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
        m_spOuterBottom->AttachProperty(pProp);
        m_spLines = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
        m_spLines->AttachProperty(pProp);
    }

    const int nPoints = 360;
    Vector3 aPts[nPoints];
    for (int i = 0; i < 360; i++)
    {
        aPts[i] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(__imp_cosf((float)i * 3.1415927f / 180.0f) * m_fOuterRadius, __imp_sinf((float)i * 3.1415927f / 180.0f) * m_fOuterRadius, 0.0f)))));
    }
    m_spMesh->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    BuildWire(m_spMesh, aPts, 360);
    float fTop = GetTop() - m_ptCenter.z;
    float fBottom = GetBottom() - m_ptCenter.z;

    for (int i = 0; i < 360; i++)
    {
        aPts[i] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(__imp_cosf((float)i * 3.1415927f / 180.0f) * m_fInnerRadius, __imp_sinf((float)i * 3.1415927f / 180.0f) * m_fInnerRadius, fTop)))));
    }
    m_spInnerTop->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    BuildWire(m_spInnerTop, aPts, 360);

    for (int i = 0; i < 360; i++)
    {
        aPts[i] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(__imp_cosf((float)i * 3.1415927f / 180.0f) * m_fInnerRadius, __imp_sinf((float)i * 3.1415927f / 180.0f) * m_fInnerRadius, fBottom)))));
    }
    m_spInnerBottom->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    BuildWire(m_spInnerBottom, aPts, 360);

    for (int i = 0; i < 360; i++)
    {
        aPts[i] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(__imp_cosf((float)i * 3.1415927f / 180.0f) * m_fOuterRadius, __imp_sinf((float)i * 3.1415927f / 180.0f) * m_fOuterRadius, fTop)))));
    }
    m_spOuterTop->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    BuildWire(m_spOuterTop, aPts, 360);

    for (int i = 0; i < 360; i++)
    {
        aPts[i] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(__imp_cosf((float)i * 3.1415927f / 180.0f) * m_fOuterRadius, __imp_sinf((float)i * 3.1415927f / 180.0f) * m_fOuterRadius, fBottom)))));
    }
    m_spOuterBottom->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    BuildWire(m_spOuterBottom, aPts, 360);

    // Radial edges: on the bottom ring, then the top ring, a short segment across the wall at each of the four
    // axis points; then the vertical lines joining the bottom and top rings at the same points.
    int n = 0;
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(-m_fOuterRadius, 0.0f, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(-m_fInnerRadius, 0.0f, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(m_fOuterRadius, 0.0f, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(m_fInnerRadius, 0.0f, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, -m_fOuterRadius, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, -m_fInnerRadius, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, m_fOuterRadius, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, m_fInnerRadius, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(-m_fOuterRadius, 0.0f, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(-m_fInnerRadius, 0.0f, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(m_fOuterRadius, 0.0f, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(m_fInnerRadius, 0.0f, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, -m_fOuterRadius, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, -m_fInnerRadius, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, m_fOuterRadius, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, m_fInnerRadius, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(-m_fOuterRadius, 0.0f, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(-m_fOuterRadius, 0.0f, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(m_fOuterRadius, 0.0f, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(m_fOuterRadius, 0.0f, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, -m_fOuterRadius, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, -m_fOuterRadius, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, m_fOuterRadius, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, m_fOuterRadius, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(-m_fInnerRadius, 0.0f, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(-m_fInnerRadius, 0.0f, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(m_fInnerRadius, 0.0f, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(m_fInnerRadius, 0.0f, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, -m_fInnerRadius, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, -m_fInnerRadius, fTop)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, m_fInnerRadius, fBottom)))));
    aPts[n++] = reinterpret_cast<const Vector3&>(static_cast<const efd::Point3&>(reinterpret_cast<const efd::Point3&>(m_ptCenter) + reinterpret_cast<const efd::Point3&>(static_cast<const Vector3&>(Vector3(0.0f, m_fInnerRadius, fTop)))));
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
