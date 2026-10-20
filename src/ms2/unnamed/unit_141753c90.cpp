// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A flat textured blob-shadow quad: FUN_141753e30 builds a centred
// fSize x fSize screen-elements quad textured with strTexture (plus an optional detail map), alpha blended with emissive vertex
// colours; FUN_141753c90 lays it flat (rotated -90 degrees about x) under a billboard node that turns about the up axis.
// Follows shadowcullingprocess.cpp in the exe; no recovered callers yet.
// MS2-UNIT: unit_141753c90
// MS2-RANGE: 0x141753c90-0x141754490 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <NiBillboardNode.h>
#include <NiMeshScreenElements.h>
#include <NiTexturingProperty.h>
#include <NiAlphaProperty.h>
#include <NiVertexColorProperty.h>
#include <NiMath.h>
#include "ms2/client/ms2/nifeffectparam.h"                  // CNifLoadingService
#include "hook/ms2hook.h"

CNifLoadingService* FUN_140a0afd0();

// @0x141753e30
efd::SmartPointer<NiMeshScreenElements> FUN_141753e30(const CString& strTexture, float fSize, const char* szDetail)
{
    efd::SmartPointer<NiMeshScreenElements> spMesh = NiNew NiMeshScreenElements(false, false, 1, 1, 1, 4, 1, 2, 1,
        NiDataStream::ACCESS_GPU_READ | NiDataStream::ACCESS_CPU_READ | NiDataStream::ACCESS_CPU_WRITE_MUTABLE, false);
    spMesh->Insert(4);
    spMesh->SetRectangle(0, -fSize / 2.0f, fSize / 2.0f, fSize, -fSize);
    spMesh->UpdateBound();
    spMesh->SetTextures(0, 0, 0.0f, 0.0f, 1.0f, 1.0f);

    NiTexturingProperty* pTexturing = NiNew NiTexturingProperty;
    pTexturing->SetBaseFilterMode(NiTexturingProperty::FILTER_NEAREST);
    pTexturing->SetApplyMode(NiTexturingProperty::APPLY_REPLACE);
    pTexturing->SetBaseClampMode(NiTexturingProperty::CLAMP_S_CLAMP_T);
    efd::SmartPointer<NiTexture> spTexture = FUN_140a0afd0()->GetTexture((const char*)strTexture, 5);
    pTexturing->SetBaseTexture(spTexture);
    if (szDetail != 0)
    {
        efd::SmartPointer<NiTexture> spDetail = FUN_140a0afd0()->GetTexture(szDetail, 5);
        NiTexturingProperty::Map* pDetail = NiNew NiTexturingProperty::Map;
        pDetail->SetTexture(spDetail);
        pTexturing->SetDetailMap(pDetail);
    }

    NiAlphaProperty* pAlpha = NiNew NiAlphaProperty;
    pAlpha->SetAlphaBlending(true);
    NiVertexColorProperty* pVertexColor = NiNew NiVertexColorProperty;
    pVertexColor->SetSourceMode(NiVertexColorProperty::SOURCE_EMISSIVE);
    pVertexColor->SetLightingMode(NiVertexColorProperty::LIGHTING_E);

    spMesh->AttachProperty(pTexturing);
    spMesh->AttachProperty(pAlpha);
    spMesh->AttachProperty(pVertexColor);
    spMesh->UpdateProperties();
    return spMesh;
}
MS2_REPLACE(0x141753E30, FUN_141753e30, 1565, 0x98E5E3BE);

// @0x141753c90
efd::SmartPointer<NiBillboardNode> FUN_141753c90(const CString& strTexture, float fSize, const char* szDetail)
{
    efd::SmartPointer<NiBillboardNode> spNode = NiNew NiBillboardNode;
    spNode->SetMode(NiBillboardNode::ROTATE_ABOUT_UP);
    spNode->SetRotate(-NI_HALF_PI, 1.0f, 0.0f, 0.0f);
    spNode->AttachChild(FUN_141753e30(strTexture, fSize, szDetail), false);
    return spNode;
}
MS2_REPLACE(0x141753C90, FUN_141753c90, 404, 0x7D2BE206);

// 0x141754450 is efd::SmartPointer<NiBillboardNode>'s copy constructor (COMDAT, the return of FUN_141753c90).
