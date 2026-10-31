// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). TransparencyMaterial: the base of the materials that fade a
// mesh out (BGTransparencyMgr); it saves the mesh's alpha / material / vertex-colour / z-buffer properties and swaps in
// clones it can fade. TransparencyStandardMaterial (vftable owned by ?\bgtransparencymgr.cpp) overrides slots 2-4.
// MS2-UNIT: ?\transparencymaterial.cpp
// MS2-RANGE: 0x14185ff70-0x141860bf0 .text$mn
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\transparencymaterial.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/transparencymaterial.h"
#include <NiAVObject.h>
#include <NiCloningProcess.h>
#include <NiRenderObject.h>
#include "ms2/ms2recover.h"

extern int DAT_143ae2b34;                                       // flag-based mesh cull mode
extern NiFixedString DAT_143ae5190;                             // extra-data key of the culled meshes
void FUN_1410865e0(NiObjectNET* pObj, const NiFixedString& kKey, bool bValue);
unsigned int FUN_141568f60(class NiAVObject*);   // C3: was FUN_141568f60
void FUN_141568f90(NiAVObject* pObj);                           // flags |= 0x10

// @0x14185ff70
TransparencyMaterial::TransparencyMaterial(NiRenderObject* pGeometry)
    : m_pGeometry(pGeometry), m_spAlpha(0), m_spVertexColor(0), m_spMaterial(0), m_spZBuffer(0)
{
    m_spAlpha = 0;
    m_spVertexColor = 0;
    m_spMaterial = 0;
    m_spZBuffer = 0;
}

// @0x141860060
TransparencyMaterial::~TransparencyMaterial()
{
    m_pGeometry = 0;
    m_spAlpha = 0;
    m_spVertexColor = 0;
    m_spMaterial = 0;
    m_spZBuffer = 0;
}

// @0x141860140
void TransparencyMaterial::FUN_141860140()
{
    NiCloningProcess kClone(0x25);
    kClone.m_eCopyType = NiObjectNET::COPY_NONE;
    kClone.m_eDynamicEffectRelationBehavior = NiCloningProcess::CLONE_RELATION_NONE;
    kClone.m_eAffectedNodeRelationBehavior = NiCloningProcess::CLONE_RELATION_NONE;

    efd::SmartPointer<NiAlphaProperty> spOldAlpha(NiDynamicCast(NiAlphaProperty, m_pGeometry->GetProperty(0)));
    if ((NiAlphaProperty*)spOldAlpha != 0)
    {
        m_pGeometry->DetachProperty(spOldAlpha);
        m_spAlpha = spOldAlpha;
    }
    NiAlphaProperty* pAlpha;
    if ((NiAlphaProperty*)m_spAlpha != 0)
        pAlpha = (NiAlphaProperty*)m_spAlpha->Clone(kClone);
    else
        pAlpha = NiNew NiAlphaProperty;
    pAlpha->SetAlphaBlending(true);
    m_pGeometry->AttachProperty(pAlpha);
    if (DAT_143ae2b34 != 0)
    {
        if (FUN_141568f60(m_pGeometry) == 0)
            FUN_141568f90(m_pGeometry);
    }
    else
    {
        FUN_1410865e0(m_pGeometry, DAT_143ae5190, true);
    }

    efd::SmartPointer<NiMaterialProperty> spOldMat(NiDynamicCast(NiMaterialProperty, m_pGeometry->GetProperty(3)));
    NiMaterialProperty* pMat;
    if ((NiMaterialProperty*)spOldMat != 0)
    {
        m_pGeometry->DetachProperty(spOldMat);
        m_spMaterial = spOldMat;
        pMat = (NiMaterialProperty*)spOldMat->Clone(kClone);
    }
    else
    {
        pMat = NiNew NiMaterialProperty;
    }
    pMat->SetAlpha(1.0f);
    m_pGeometry->AttachProperty(pMat);

    efd::SmartPointer<NiVertexColorProperty> spOldColor(NiDynamicCast(NiVertexColorProperty, m_pGeometry->GetProperty(9)));
    if ((NiVertexColorProperty*)spOldColor != 0)
    {
        m_pGeometry->DetachProperty(spOldColor);
        m_spVertexColor = spOldColor;
        NiVertexColorProperty* pColor = NiNew NiVertexColorProperty;
        m_pGeometry->AttachProperty(pColor);
    }

    m_spZBuffer = (NiZBufferProperty*)m_pGeometry->GetProperty(11);
    efd::SmartPointer<NiZBufferProperty> spZ(0);
    if ((NiZBufferProperty*)m_spZBuffer != 0)
    {
        m_pGeometry->DetachProperty(m_spZBuffer);
        spZ = (NiZBufferProperty*)m_spZBuffer->Clone(kClone);
    }
    else
    {
        spZ = NiNew NiZBufferProperty;
    }
    spZ->SetZBufferWrite(true);
    m_pGeometry->AttachProperty(spZ);
}

// @0x141860700
void TransparencyMaterial::FUN_141860700()
{
    NiAlphaProperty* pAlpha = NiDynamicCast(NiAlphaProperty, m_pGeometry->GetProperty(0));
    if (pAlpha != 0)
    {
        m_pGeometry->DetachProperty(pAlpha);
        if ((NiAlphaProperty*)m_spAlpha != 0)
            m_pGeometry->AttachProperty(m_spAlpha);
    }
    NiMaterialProperty* pMat = NiDynamicCast(NiMaterialProperty, m_pGeometry->GetProperty(3));
    if (pMat != 0)
    {
        m_pGeometry->DetachProperty(pMat);
        if ((NiMaterialProperty*)m_spMaterial != 0)
            m_pGeometry->AttachProperty(m_spMaterial);
    }
    if ((NiVertexColorProperty*)m_spVertexColor != 0)
    {
        NiVertexColorProperty* pColor = NiDynamicCast(NiVertexColorProperty, m_pGeometry->GetProperty(9));
        if (pColor != 0)
            m_pGeometry->DetachProperty(pColor);
        m_pGeometry->AttachProperty(m_spVertexColor);
    }
    NiProperty* pZ = m_pGeometry->GetProperty(11);
    if (pZ != 0)
        m_pGeometry->DetachProperty(pZ);
    if ((NiZBufferProperty*)m_spZBuffer != 0)
        m_pGeometry->AttachProperty(m_spZBuffer);
    m_spZBuffer = 0;
}

// @0x141860b20
void TransparencyStandardMaterial::vfunc_2(const NiBound&)
{
    FUN_141860140();
    efd::SmartPointer<NiVertexColorProperty> spColor(NiDynamicCast(NiVertexColorProperty, m_pGeometry->GetProperty(9)));
    if ((NiVertexColorProperty*)spColor != 0)
    {
        spColor->SetSourceMode((NiVertexColorProperty::SourceVertexMode)3);
        spColor->SetLightingMode(NiVertexColorProperty::LIGHTING_E_A_D);
    }
}

// @0x141860bd0
void TransparencyStandardMaterial::vfunc_3()
{
    FUN_141860700();
}
