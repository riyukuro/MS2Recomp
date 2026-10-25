// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CCylinderCollision: cylinder outline visualiser (three NiMesh
// line sets: the base ring, top ring and bottom ring plus the vertical/cross lines). Source file name unknown (the unit
// is "?\cylindercollision.cpp" in the harvest, rejected); named after its only class.
// MS2-UNIT: unit_141083230
// MS2-RANGE: 0x141083230-0x141084ad0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\cylindercollision.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <math.h>
#include <NiMesh.h>
#include <NiVertexColorProperty.h>
#include <NiCommonSemantics.h>
#include <NiDataStreamElementLock.h>
#include <NiRenderer.h>
#include "ms2/placeholder/cbasecollision.h"

class CCylinderCollision : public CBaseCollision
{
public:
    CCylinderCollision();                                                   // 0x141083230
    virtual ~CCylinderCollision();                                          // 0x141083320
    virtual void vfunc_1();                                                 // 0x1410846a0
    virtual void vfunc_3(Vector3 pos, Vector3 rot, float scale);   // 0x1410833c0
    virtual void vfunc_5();                                                 // 0x1410834d0
    virtual float vfunc_6();                                                // 0x141083450

    float GetTopZ() const { return m_center.z + m_height; }                 // 0x141083470
    float GetBottomZ() const { return m_center.z - m_ptSize.z; }                // 0x1410834a0
    void BuildLines(NiMesh* pkMesh, Vector3* pkPoints, unsigned int uiCount);   // 0x141084740
    void FUN_1410848f0();

    NiMeshPtr m_spTopMesh;                                                  // +0x78
    NiMeshPtr m_spBottomMesh;                                               // +0x80
    NiMeshPtr m_spLineMesh;                                                 // +0x88
    NiMeshPtr m_aspMeshes[4];                                               // +0x90 (base, top, bottom, lines)
    float m_radius;                                                         // +0xb0
    Vector3 m_center;                                               // +0xb4
    float m_height;                                                         // +0xc0
};
MS2_CHECK_SIZE(CCylinderCollision, 0xc8);
MS2_CHECK_OFFSET(CCylinderCollision, m_spTopMesh, 0x78);
MS2_CHECK_OFFSET(CCylinderCollision, m_aspMeshes, 0x90);
MS2_CHECK_OFFSET(CCylinderCollision, m_radius, 0xb0);
MS2_CHECK_OFFSET(CCylinderCollision, m_center, 0xb4);
MS2_CHECK_OFFSET(CCylinderCollision, m_height, 0xc0);

// @0x141083230
CCylinderCollision::CCylinderCollision()
{
    m_nShape = 2;
    m_radius = 0.0f;
    m_height = 0.0f;
}

// @0x141083320
CCylinderCollision::~CCylinderCollision()
{
}

// @0x1410833c0
void CCylinderCollision::vfunc_3(Vector3 pos, Vector3 rot, float scale)
{
    m_center = pos;
    CBaseCollision::vfunc_3(pos, rot, scale);
}

// @0x141083450
float CCylinderCollision::vfunc_6()
{
    return m_height;
}

// @0x141083470 GetTopZ and 0x1410834a0 GetBottomZ are the in-class inline members above

// @0x1410834d0
// MS2-FUNCTIONAL: ring-point arg evaluation order differs (exe copies sin*r through xmm1/xmm2; no source form found)
void CCylinderCollision::vfunc_5()
{
    m_bBuilt = 1;
    if (!(NiMesh*)m_spTopMesh)
    {
        m_spTopMesh = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
        NiVertexColorProperty* pkVCProp = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
        pkVCProp->SetSourceMode(NiVertexColorProperty::SOURCE_EMISSIVE);
        pkVCProp->SetLightingMode(NiVertexColorProperty::LIGHTING_E);
        m_spTopMesh->AttachProperty(pkVCProp);
        m_spBottomMesh = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
        m_spBottomMesh->AttachProperty(pkVCProp);
        m_spLineMesh = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
        m_spLineMesh->AttachProperty(pkVCProp);
    }
    const int kSegments = 0x168;
    Vector3 akPoints[0x168];
    for (int i = 0; i < kSegments; i++)
    {
        float fSin = sinf((float)i * 3.1415927f / 180.0f) * m_radius;
        akPoints[i] = m_center.FUN_14097fd50(Vector3(cosf((float)i * 3.1415927f / 180.0f) * m_radius, fSin, 0));
    }
    m_spMesh->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    BuildLines(m_spMesh, akPoints, kSegments);
    float fTop = GetTopZ() - m_center.z;
    float fBottom = GetBottomZ() - m_center.z;
    for (int j = 0; j < kSegments; j++)
    {
        float fSin = sinf((float)j * 3.1415927f / 180.0f) * m_radius;
        akPoints[j] = m_center.FUN_14097fd50(Vector3(cosf((float)j * 3.1415927f / 180.0f) * m_radius, fSin, fTop));
    }
    m_spTopMesh->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    BuildLines(m_spTopMesh, akPoints, kSegments);
    for (int k = 0; k < kSegments; k++)
    {
        float fSin = sinf((float)k * 3.1415927f / 180.0f) * m_radius;
        akPoints[k] = m_center.FUN_14097fd50(Vector3(cosf((float)k * 3.1415927f / 180.0f) * m_radius, fSin, fBottom));
    }
    m_spBottomMesh->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINESTRIPS);
    BuildLines(m_spBottomMesh, akPoints, kSegments);

    akPoints[0] = m_center.FUN_14097fd50(Vector3(-m_radius, 0, fBottom));
    int nCount = 1;
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(m_radius, 0, fBottom));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(0, -m_radius, fBottom));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(0, m_radius, fBottom));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(-m_radius, 0, 0));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(m_radius, 0, 0));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(0, -m_radius, 0));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(0, m_radius, 0));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(-m_radius, 0, fTop));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(m_radius, 0, fTop));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(0, -m_radius, fTop));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(0, m_radius, fTop));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(-m_radius, 0, fBottom));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(-m_radius, 0, fTop));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(m_radius, 0, fBottom));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(m_radius, 0, fTop));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(0, -m_radius, fBottom));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(0, -m_radius, fTop));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(0, m_radius, fBottom));
    akPoints[nCount++] = m_center.FUN_14097fd50(Vector3(0, m_radius, fTop));
    m_spLineMesh->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINES);
    BuildLines(m_spLineMesh, akPoints, nCount);
    m_aspMeshes[0] = m_spMesh;
    m_aspMeshes[1] = m_spTopMesh;
    m_aspMeshes[2] = m_spBottomMesh;
    m_aspMeshes[3] = m_spLineMesh;
}

// @0x1410846a0
void CCylinderCollision::vfunc_1()
{
    if (m_bBuilt == 0)
        vfunc_5();
    NiRenderer* pkRenderer = NiRenderer::GetRenderer();
    for (int i = 0; i < 4; i++)
    {
        NiMesh* pkMesh = m_aspMeshes[i];
        if (pkMesh != 0)
            pkMesh->RenderImmediate(pkRenderer);
    }
}

// Uploads the points as the position stream and a constant-colour stream (the shape colour), then refreshes the mesh.
// @0x141084740
void CCylinderCollision::BuildLines(NiMesh* pkMesh, Vector3* pkPoints, unsigned int uiCount)
{
    pkMesh->RemoveAllStreamRefs();
    pkMesh->AddStream(NiCommonSemantics::POSITION(), 0, NiDataStreamElement::F_FLOAT32_3, uiCount,
        NiDataStream::ACCESS_GPU_READ | NiDataStream::ACCESS_CPU_READ | NiDataStream::ACCESS_CPU_WRITE_STATIC, NiDataStream::USAGE_VERTEX, pkPoints, false, true);
    NiDataStreamElementLock kLock = pkMesh->AddStreamGetLock(NiCommonSemantics::COLOR(), 0,
        NiDataStreamElement::F_FLOAT32_4, uiCount, NiDataStream::ACCESS_GPU_READ | NiDataStream::ACCESS_CPU_WRITE_STATIC,
        NiDataStream::USAGE_VERTEX, false, true, NiDataStream::LOCK_WRITE);
    NiTStridedRandomAccessIterator<NiColorA> kIter = kLock.begin<NiColorA>(0);
    for (int i = 0; i < (int)uiCount; i++)
        kIter[i] = m_kColor;
    kLock.Unlock();
    pkMesh->Update(0.0f, true);
    pkMesh->UpdateProperties();
    pkMesh->UpdateEffects();
    pkMesh->UpdateNodeBound();
    pkMesh->SetSelectiveUpdate(true);
}

// @0x1410848f0
void CCylinderCollision::FUN_1410848f0()
{
    if (m_bBuilt == 0)
        vfunc_5();
    if ((NiMesh*)m_spBottomMesh)
        m_spBottomMesh->RenderImmediate(NiRenderer::GetRenderer());
}

// @0x1410849b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
