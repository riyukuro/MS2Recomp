// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CDebugHelper: singleton that draws debug points and lines as
// small NiMesh objects attached under the "Scene Root" node (the meshes are also kept alive in a CAtlList).
// Original source file name unknown (assumed from the class name).
// MS2-UNIT: ?\debughelper.cpp
// MS2-RANGE: 0x14116bdc0-0x14116d540 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\debughelper.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <NiVertexColorProperty.h>
#include <NiMaterialProperty.h>
#include <NiZBufferProperty.h>
#include <NiWireframeProperty.h>
#include <NiCommonSemantics.h>
#include <NiDataStreamElementLock.h>
#include "ms2/placeholder/cdebughelper.h"

NiNode* FUN_1413f9f90();                                            // the node named "Scene Root"
void FUN_140ddcca0(void* obj, const void* m);                       // NiAVObject::SetRotate(NiMatrix3)
void FUN_140a33240(void* dst, const void* src);                     // NiMatrix3(efd::Matrix3)

// @0x14116bdc0
CDebugHelper::CDebugHelper() : m_pRoot(0), m_meshes(10)
{
}

// @0x14116be20
CDebugHelper::~CDebugHelper()
{
    ClearMeshes();
}

// @0x14116be80
void CDebugHelper::FUN_14116be80()
{
    m_pRoot = FUN_1413f9f90();
}

// The properties every debug mesh gets: vertex colours as emissive, a white material, no z test / write, wireframe.
static void AttachDebugProperties(NiMesh* pkMesh)
{
    NiMaterialProperty* pkMat = new (efd::MemHint(efd::MemHint::NONE)) NiMaterialProperty;
    pkMat->SetEmittance(NiColor(1.0f, 1.0f, 1.0f));
    NiVertexColorProperty* pkVC = new (efd::MemHint(efd::MemHint::NONE)) NiVertexColorProperty;
    pkVC->SetSourceMode(NiVertexColorProperty::SOURCE_EMISSIVE);
    pkVC->SetLightingMode(NiVertexColorProperty::LIGHTING_E);
    pkMesh->AttachProperty(pkVC);
    pkMesh->AttachProperty(pkMat);
    NiZBufferProperty* pkZ = new (efd::MemHint(efd::MemHint::NONE)) NiZBufferProperty;
    pkZ->SetZBufferTest(false);
    pkZ->SetZBufferWrite(false);
    pkMesh->AttachProperty(pkZ);
    NiWireframeProperty* pkWire = new (efd::MemHint(efd::MemHint::NONE)) NiWireframeProperty;
    pkWire->SetWireframe(true);
    pkMesh->AttachProperty(pkWire);
}

// @0x14116beb0
// MS2-FUNCTIONAL: Gamebryo debug-mesh builder; the exe's inline stream/lock temporaries are laid out differently
void CDebugHelper::FUN_14116beb0(const NiPoint3* pPos, const NiColorA* pColor)
{
    if (m_pRoot == 0)
        FUN_14116be80();
    NiMeshPtr spMesh = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
    spMesh->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_POINTS);
    NiDataStreamElementLock kPos = spMesh->AddStreamGetLock(NiCommonSemantics::POSITION(), 0,
        NiDataStreamElement::F_FLOAT32_3, 1, 0x12, NiDataStream::USAGE_VERTEX, false, true, 2);
    NiDataStreamElementLock kColor = spMesh->AddStreamGetLock(NiCommonSemantics::COLOR(), 0,
        NiDataStreamElement::F_FLOAT32_4, 1, 0x12, NiDataStream::USAGE_VERTEX, false, true, 2);
    kColor.begin<NiColorA>(0)[0] = *pColor;
    kPos.begin<NiPoint3>(0)[0] = NiPoint3(0.0f, 0.0f, 0.0f);
    kPos.Unlock();
    kColor.Unlock();
    AttachDebugProperties(spMesh);
    spMesh->SetTranslate(*pPos);
    spMesh->SetScale(100.0f);
    spMesh->Update(0.0f, true);
    spMesh->UpdateProperties();
    spMesh->UpdateEffects();
    spMesh->UpdateNodeBound();
    spMesh->SetSelectiveUpdate(true);
    if (m_pRoot)
    {
        m_pRoot->AttachChild(spMesh, true);
        m_pRoot->UpdateNodeBound();
        m_pRoot->Update(0.0f, true);
        m_meshes.AddTail(spMesh);
    }
}

// @0x14116c580
// MS2-FUNCTIONAL: Gamebryo debug-mesh builder; the exe's inline stream/lock temporaries are laid out differently
void CDebugHelper::FUN_14116c580(const NiPoint3* pPos, const NiPoint3* pTarget, const void* pRot, const NiColorA* pColor)
{
    if (m_pRoot == 0)
        FUN_14116be80();
    NiMeshPtr spMesh = new (efd::MemHint(efd::MemHint::NONE)) NiMesh;
    spMesh->SetPrimitiveType(NiPrimitiveType::PRIMITIVE_LINES);
    NiDataStreamElementLock kPos = spMesh->AddStreamGetLock(NiCommonSemantics::POSITION(), 0,
        NiDataStreamElement::F_FLOAT32_3, 2, 0x12, NiDataStream::USAGE_VERTEX, false, true, 2);
    NiDataStreamElementLock kColor = spMesh->AddStreamGetLock(NiCommonSemantics::COLOR(), 0,
        NiDataStreamElement::F_FLOAT32_4, 2, 0x12, NiDataStream::USAGE_VERTEX, false, true, 2);
    NiTStridedRandomAccessIterator<NiColorA> kColors = kColor.begin<NiColorA>(0);
    kColors[0] = *pColor;
    kColors[1] = *pColor;
    Vector3 kDir = ((const Vector3*)pTarget)->FUN_140965c40(*(const Vector3*)pPos);
    kDir.FUN_140968990();
    NiTStridedRandomAccessIterator<NiPoint3> kPts = kPos.begin<NiPoint3>(0);
    kPts[0] = NiPoint3(0.0f, 0.0f, 0.0f);
    kPts[1] = NiPoint3(kDir.x, kDir.y, kDir.z);
    kPos.Unlock();
    kColor.Unlock();
    AttachDebugProperties(spMesh);
    spMesh->SetTranslate(*pPos);
    NiMatrix3 kRot;
    FUN_140a33240(&kRot, pRot);
    FUN_140ddcca0(spMesh, &kRot);
    spMesh->SetScale(100.0f);
    spMesh->Update(0.0f, true);
    spMesh->UpdateProperties();
    spMesh->UpdateEffects();
    spMesh->UpdateNodeBound();
    spMesh->SetSelectiveUpdate(true);
    if (m_pRoot)
    {
        m_pRoot->AttachChild(spMesh, true);
        m_pRoot->UpdateProperties();
        m_pRoot->UpdateEffects();
        m_pRoot->UpdateNodeBound();
        m_pRoot->Update(0.0f, true);
        m_meshes.AddTail(spMesh);
    }
}

// Detaches every kept mesh from the scene root and empties the list.
// @0x14116cd50
void CDebugHelper::ClearMeshes()
{
    POSITION pos = m_meshes.GetHeadPosition();
    while (pos)
    {
        NiMeshPtr spMesh = m_meshes.GetNext(pos);
        NiAVObjectPtr spOut = m_pRoot->DetachChild(spMesh);
    }
    m_meshes.RemoveAll();
}
