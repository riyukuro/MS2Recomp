// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Scene-graph render-state helpers of the client: per-model
// shadow / DOF / fog / shimmer markers (string tags "NoShadow", "NoDOF", "nofog", "shimmer" on the nodes), the MS2 render
// flag bits of NiAVObject (GetMS2Flags: 1 shimmer, 2 outline, 4 / 8 / 0x10 / 0x40 shell kinds, 0x20 shadow caster,
// 0x80 no DOF), material swaps, tints and the light / fog strip helpers. The tagged-extra-data variants are used when
// DAT_143ae2b34 (instanced rendering) is 0, the flag bits otherwise.
// MS2-UNIT: unit_141567000
// MS2-RANGE: 0x141567000-0x141569a00 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ?GetDefault@NiMaterialProperty@@SAPEAV1@XZ 0x141569730
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <NiNode.h>
#include <NiRenderObject.h>
#include <NiMesh.h>
#include <NiMaterial.h>
#include <NiMaterialLibrary.h>
#include <NiStringExtraData.h>
#include <NiFloatExtraData.h>
#include <NiIntegerExtraData.h>
#include <NiAlphaProperty.h>
#include <NiMaterialProperty.h>
#include <NiFogProperty.h>
#include <NiStencilProperty.h>
#include <NiCloningProcess.h>
#include <NiLight.h>
#include <NiAlphaController.h>
#include <NiKeyBasedInterpolator.h>
#include <NiFloatKey.h>
#include <NiPSMeshParticleSystem.h>
#include <efd/Color.h>
#include <egf/Entity.h>
#include <egf/FlatModel.h>
#include <ecr/SceneGraphService.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/effectservice.h"

// ---- unit-local views of exe objects ----

// Depth-first walker over a scene graph (0x30 bytes; unrecovered class, ?\util.cpp declares it 0x38).
class Unk_SceneWalker
{
public:
    Unk_SceneWalker(NiObject* pkRoot);              // 0x14098cb80
    ~Unk_SceneWalker();                             // 0x14098cf00
    NiAVObject* Next(bool bDescend);                // 0x14098e0d0
    void FUN_14098d6d0(NiNode* pNode);              // queue the children of a node
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28;
};
MS2_CHECK_SIZE(Unk_SceneWalker, 0x30);

// Breadth-first walk over a node's subtree (0x30 bytes, as in uichaoslightdialog.h).
class Unk_NodeWalker
{
public:
    Unk_NodeWalker(NiAVObject* pRoot);                              // 0x141043760
    ~Unk_NodeWalker();                                              // 0x1410439e0
    NiAVObject* FUN_1410446c0(bool bChildren);                      // 0x1410446c0 next node, NULL at the end
    void FUN_141044210(NiNode* pNode);                              // 0x141044210 queue the children
private:
    ATL::CAtlList<NiAVObject*> m_list;
};
MS2_CHECK_SIZE(Unk_NodeWalker, 0x30);

extern int DAT_143ae2b34;                       // 1: the markers are MS2 flag bits instead of extra data (instancing)
extern NiFixedString DAT_143ae51b8;             // key of the NiStringExtraData tag of a node
extern NiFixedString DAT_143ae51a8;             // marker key: casts shadows
extern NiFixedString DAT_143ae51b0;             // marker key: no DOF (also the tag text)
extern NiFixedString DAT_143ae51c8;             // marker key: shimmer
extern NiFixedString DAT_143ae5140;             // float extra-data key (fog factor)
extern NiFixedString DAT_143ae50a0;             // integer extra-data key (face part code)
extern NiFixedString DAT_143ae50f0;             // colour extra-data key (ICMED tint)
extern NiFixedString DAT_143ae51d8;             // the first face part name
extern NiFixedString DAT_143ae5230;             // name of the alpha-blended material
extern const efd::Color g_143a09660;          // white

bool FUN_14098dfc0(NiAVObject* pkObject);                                               // 0x14098dfc0 flag 0x400 set
bool FUN_1409943d0(NiAVObject* pkObject);                                               // 0x1409943d0 flag 0x20 set
class Unk_EffectNodeView   // C3: member view for the former free stand-ins
{
public:
    int FUN_1410444a0();
};
void FUN_1410865e0(class NiObjectNET*, class NiFixedString const&, bool);   // C3: was FUN_1410865e0
void FUN_1410479a0(NiObjectNET* pkObject, const NiFixedString& kName, const NiColor& kColor);   // set colour extra data
NiAVObject* FUN_141b6efc0(egf::Entity* pEntity);                                         // the entity's scene graph
ecr::SceneGraphService* FUN_1413f98b0();                                                 // the scene graph service
efd::Color FUN_1413fa320(egf::Entity* pEntity);                                          // the entity's tint

void FUN_1415672e0(NiAVObject* pRoot, bool bShadow);
void FUN_141567330(NiAVObject* pRoot, bool bShadow);
void FUN_141567760(NiAVObject* pRoot);
void FUN_141567b60(NiAVObject* pRoot);
void FUN_1415681c0(NiAVObject* pRoot);
void FUN_1415682b0(NiAVObject* pRoot);
void FUN_141568650(NiAVObject* pRoot, CStringA strFrom, CStringA strTo);
void FUN_141568ac0(egf::Entity* pEntity, const efd::Color& kTint);
unsigned int FUN_141568d50(NiAVObject* pkObject);
unsigned int FUN_141569010(NiAVObject* pkObject);
void FUN_141569040(NiAVObject* pkObject);
void FUN_141569080(NiAVObject* pkObject);
bool FUN_141569170(NiObjectNET* pkProperty);
void FUN_141569280(NiRenderObject* pkObject);
int FUN_141569310(NiRenderObject* pkObject);
void FUN_141569620(NiAVObject* pRoot, NiProperty* pkProperty);

// @0x141567000
// The ICMED markers of a model: the shadow setup of its scene graph and the tint of the IC-medal meshes.
void FUN_141567000(egf::Entity* pEntity, NiAVObject* pRoot, bool bShadow)
{
    if (pEntity != 0 && pRoot != 0)
    {
        bool bCastShadow = false;
        pEntity->GetPropertyValue(0xd89e9b12, bCastShadow);
        if (bShadow)
            bCastShadow = bShadow;
        const egf::FlatModel* pModel = pEntity->GetModel();
        if (pModel->ContainsModel(0xbd4f8e8e))
            FUN_1415672e0(pRoot, bCastShadow);
        if (pModel->ContainsModel(0x48ccc02d))
            FUN_1415672e0(pRoot, bCastShadow);
        bool bICMed = pModel->ContainsModel(0xb8d7c226);
        if (!bICMed && pModel->ContainsProperty(0x4c54402f))
            pEntity->GetPropertyValue(0x4c54402f, bICMed);
        if (bICMed)
        {
            Unk_SceneWalker kWalker(pRoot);
            NiAVObject* pObject;
            while ((pObject = kWalker.Next(true)) != 0)
            {
                NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObject);
                if (pRender)
                {
                    FUN_1410865e0((class NiObjectNET*)(pRender), "ICMED", true);
                    FUN_1410479a0(pRender, DAT_143ae50f0, g_143a09660);
                }
            }
        }
    }
}
MS2_REPLACE(0x141567000, FUN_141567000, 480, 0xC41F2FE3);

// @0x1415671f0
// The object's alpha property blends additively (destination ONE).
bool FUN_1415671f0(NiAVObject* pkObject)
{
    NiAlphaProperty* pAlpha = NiDynamicCast(NiAlphaProperty, pkObject->GetProperty(NiProperty::ALPHA));
    if (pAlpha && pAlpha->GetAlphaBlending() && pAlpha->GetDestBlendMode() == NiAlphaProperty::ALPHA_ONE)
        return true;
    return false;
}
MS2_REPLACE(0x1415671F0, FUN_1415671f0, 91, 0x335B5ACA);

// @0x141567260
// The object's alpha property blends, other than the plain SRCALPHA / INVSRCALPHA mode.
bool FUN_141567260(NiAVObject* pkObject)
{
    NiAlphaProperty* pAlpha = NiDynamicCast(NiAlphaProperty, pkObject->GetProperty(NiProperty::ALPHA));
    if (pAlpha && pAlpha->GetAlphaBlending()
        && (pAlpha->GetSrcBlendMode() != NiAlphaProperty::ALPHA_SRCALPHA
            || pAlpha->GetDestBlendMode() != NiAlphaProperty::ALPHA_INVSRCALPHA))
        return true;
    return false;
}
MS2_REPLACE(0x141567260, FUN_141567260, 107, 0x65B28B4E);

// @0x1415672e0
void FUN_1415672e0(NiAVObject* pRoot, bool bShadow)
{
    if (pRoot)
    {
        FUN_141567b60(pRoot);
        FUN_141567330(pRoot, bShadow);
        FUN_141567760(pRoot);
        FUN_1415681c0(pRoot);
    }
}
MS2_REPLACE(0x1415672E0, FUN_1415672e0, 71, 0x250EEDF7);

// @0x141567330
// Marks (or unmarks) the render objects of a subtree as shadow casters, skipping "NoShadow" tagged subtrees.
void FUN_141567330(NiAVObject* pRoot, bool bShadow)
{
    if (pRoot == 0)
        return;
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(false)) != 0)
    {
        if (FUN_14098dfc0(pObject))
            continue;
        NiStringExtraData* pTag = NiDynamicCast(NiStringExtraData, pObject->GetExtraData(DAT_143ae51b8));
        if (pTag && pTag->GetValue().ContainsNoCase("NoShadow"))
            continue;
        NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObject);
        if (pRender)
        {
            if (DAT_143ae2b34)
            {
                if (bShadow)
                {
                    if (FUN_141569010(pRender) == 0)
                        FUN_141569040(pRender);
                }
                else
                    FUN_141569080(pRender);
            }
            else if (bShadow)
            {
                if (pRender->GetExtraData(DAT_143ae51a8) == 0)
                    pRender->AddExtraData(DAT_143ae51a8, NiNew NiExtraData);
            }
            else
                pRender->RemoveExtraData(DAT_143ae51a8);
        }
        NiNode* pNode = NiDynamicCast(NiNode, pObject);
        if (pNode)
            kWalker.FUN_14098d6d0(pNode);
    }
}
MS2_REPLACE(0x141567330, FUN_141567330, 513, 0x2F0822AD);

// @0x141567540
// FUN_141567330 over a breadth-first walk that does not enter effect nodes of mode 1.
void FUN_141567540(NiAVObject* pRoot, bool bShadow)
{
    if (pRoot == 0)
        return;
    Unk_NodeWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.FUN_1410446c0(false)) != 0)
    {
        NiStringExtraData* pTag = NiDynamicCast(NiStringExtraData, pObject->GetExtraData(DAT_143ae51b8));
        if (pTag && pTag->GetValue().ContainsNoCase("NoShadow"))
            continue;
        NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObject);
        if (pRender)
        {
            if (DAT_143ae2b34)
            {
                if (bShadow)
                {
                    if (FUN_141569010(pRender) == 0)
                        FUN_141569040(pRender);
                }
                else
                    FUN_141569080(pRender);
            }
            else if (bShadow)
            {
                if (pRender->GetExtraData(DAT_143ae51a8) == 0)
                    pRender->AddExtraData(DAT_143ae51a8, NiNew NiExtraData);
            }
            else
                pRender->RemoveExtraData(DAT_143ae51a8);
        }
        NiNode* pNode = NiDynamicCast(NiNode, pObject);
        if (pNode)
        {
            if (NiObject::DynamicCast(&EffectNode::ms_RTTI, pObject) && ((class Unk_EffectNodeView*)(class NiAVObject*)(pObject))->FUN_1410444a0() == 1)
                continue;
            kWalker.FUN_141044210(pNode);
        }
    }
}
MS2_REPLACE(0x141567540, FUN_141567540, 536, 0xCF54B6CD);

// @0x141567760
// The "NoDOF" tagged subtrees: their render objects get the no-DOF marker.
void FUN_141567760(NiAVObject* pRoot)
{
    if (pRoot == 0)
        return;
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(true)) != 0)
    {
        NiStringExtraData* pTag = NiDynamicCast(NiStringExtraData, pObject->GetExtraData(DAT_143ae51b8));
        if (pTag == 0)
            continue;
        if (DAT_143ae2b34 != 0)
        {
            if (pTag && !pTag->GetValue().ContainsNoCase("NoDOF"))
                continue;
            Unk_SceneWalker kSub(pObject);
            NiAVObject* pChild;
            while ((pChild = kSub.Next(true)) != 0)
            {
                NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pChild);
                if (pRender && FUN_141568d50(pRender) == 0)
                {
                    unsigned int uiFlags = pRender->GetMS2Flags() | 0x80;
                    pRender->SetMS2Flags(uiFlags);
                }
            }
        }
        else
        {
            if (pTag && !pTag->GetValue().ContainsNoCase(DAT_143ae51b0))
                continue;
            Unk_SceneWalker kSub(pObject);
            NiAVObject* pChild;
            while ((pChild = kSub.Next(true)) != 0)
            {
                NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pChild);
                if (pRender && pRender->GetExtraData(DAT_143ae51b0) == 0)
                    pRender->AddExtraData(DAT_143ae51b0, NiNew NiExtraData);
            }
        }
    }
}
MS2_REPLACE(0x141567760, FUN_141567760, 667, 0xA8A94E09);

// @0x141567a10
// Marks every render object of a subtree as no-DOF.
void FUN_141567a10(NiAVObject* pRoot)
{
    if (pRoot == 0)
        return;
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(true)) != 0)
    {
        NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObject);
        if (pRender)
        {
            if (DAT_143ae2b34)
            {
                if (FUN_141568d50(pRender) == 0)
                {
                    unsigned int uiFlags = pRender->GetMS2Flags() | 0x80;
                    pRender->SetMS2Flags(uiFlags);
                }
            }
            else if (pRender->GetExtraData(DAT_143ae51b0) == 0)
                pRender->AddExtraData(DAT_143ae51b0, NiNew NiExtraData);
        }
    }
}
MS2_REPLACE(0x141567A10, FUN_141567a10, 326, 0x29C65FF6);

// @0x141567b60
// The render setup of a model: fog factors, face part codes, the fog-off property on "nofog" tagged and additive
// subtrees, and a default material / stencil property at the root.
void FUN_141567b60(NiAVObject* pRoot)
{
    if (pRoot == 0)
        return;
    NiFogPropertyPtr spFog = NiNew NiFogProperty;
    spFog->SetFog(false);
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(false)) != 0)
    {
        NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObject);
        if (pRender)
        {
            FUN_141569280(pRender);
            NiFloatExtraData* pFactor = NiDynamicCast(NiFloatExtraData, pRender->GetExtraData(DAT_143ae5140));
            if (pFactor == 0)
            {
                pFactor = NiNew NiFloatExtraData(1.0f);
                pRender->AddExtraData(DAT_143ae5140, pFactor);
            }
            else
                pFactor->SetValue(1.0f);
        }
        NiPSMeshParticleSystem* pParticles = NiDynamicCast(NiPSMeshParticleSystem, pObject);
        if (pParticles)
        {
            NiUInt16 usCount = pParticles->GetNumGenerations();
            for (NiUInt16 us = 0; us < usCount; us++)
                FUN_141567b60(pParticles->GetMasterParticle(us));
        }
        NiStringExtraData* pTag = NiDynamicCast(NiStringExtraData, pObject->GetExtraData(DAT_143ae51b8));
        if (pTag && pTag->GetValue().ContainsNoCase("nofog"))
            FUN_141569620(pObject, spFog);
        if (FUN_14098dfc0(pObject))
        {
            FUN_141569620(pObject, spFog);
            continue;
        }
        if (FUN_1415671f0(pObject))
            FUN_141569620(pObject, spFog);
        NiNode* pNode = NiDynamicCast(NiNode, pObject);
        if (pNode)
            kWalker.FUN_14098d6d0(pNode);
    }
    Unk_SceneWalker kParts(pRoot);
    NiAVObject* pPart;
    while ((pPart = kParts.Next(true)) != 0)
    {
        NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pPart);
        int iCode;
        if (pRender && (iCode = FUN_141569310(pRender)) != 0)
        {
            NiIntegerExtraData* pCode = NiDynamicCast(NiIntegerExtraData, pRender->GetExtraData(DAT_143ae50a0));
            if (pCode == 0)
            {
                pCode = NiNew NiIntegerExtraData(iCode);
                pRender->AddExtraData(DAT_143ae50a0, pCode);
            }
            else
                pCode->SetValue(iCode);
        }
    }
    if (pRoot->GetProperty(NiProperty::MATERIAL) == 0)
    {
        NiCloningProcess kCloning(0x25);
        kCloning.m_eCopyType = NiObjectNET::COPY_EXACT;
        NiMaterialPropertyPtr spMaterial =
            NiDynamicCast(NiMaterialProperty, NiMaterialProperty::GetDefault()->Clone(kCloning));
        spMaterial->SetAlpha(1.0f);
        pRoot->AttachProperty(spMaterial);
    }
    if (pRoot->GetProperty(NiProperty::STENCIL) == 0)
        pRoot->AttachProperty(NiNew NiStencilProperty);
    pRoot->UpdateProperties();
}
MS2_REPLACE(0x141567B60, FUN_141567b60, 1617, 0x60A39AC0);

// @0x1415681c0
// The "shimmer" tagged subtrees get the shimmer marker.
void FUN_1415681c0(NiAVObject* pRoot)
{
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(false)) != 0)
    {
        NiStringExtraData* pTag = NiDynamicCast(NiStringExtraData, pObject->GetExtraData(DAT_143ae51b8));
        if (pTag && pTag->GetValue().ContainsNoCase("shimmer"))
        {
            FUN_1415682b0(pObject);
            continue;
        }
        NiNode* pNode = NiDynamicCast(NiNode, pObject);
        if (pNode)
            kWalker.FUN_14098d6d0(pNode);
    }
}
MS2_REPLACE(0x1415681C0, FUN_1415681c0, 220, 0x21181327);

// @0x1415682b0
void FUN_1415682b0(NiAVObject* pRoot)
{
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(true)) != 0)
    {
        if (DAT_143ae2b34)
        {
            NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObject);
            if (pRender)
            {
                unsigned int uiFlags = pRender->GetMS2Flags() | 1;
                pRender->SetMS2Flags(uiFlags);
            }
        }
        else if (FUN_1409943d0(pObject))
            FUN_1410865e0((class NiObjectNET*)(pObject), DAT_143ae51c8, true);
    }
}
MS2_REPLACE(0x1415682B0, FUN_1415682b0, 191, 0xB31DE793);

// @0x141568380
// Clears the shimmer marker of a subtree.
void FUN_141568380(NiAVObject* pRoot)
{
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(true)) != 0)
    {
        if (DAT_143ae2b34)
        {
            NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObject);
            if (pRender)
            {
                unsigned int uiFlags = pRender->GetMS2Flags();
                if (uiFlags & 1)
                {
                    uiFlags &= ~1u;
                    pRender->SetMS2Flags(uiFlags);
                }
            }
        }
        else if (FUN_1409943d0(pObject))
        {
            if (pObject->GetExtraData(DAT_143ae51c8))
                pObject->RemoveExtraData(DAT_143ae51c8);
        }
    }
}
MS2_REPLACE(0x141568380, FUN_141568380, 233, 0x453C180A);

// @0x141568470
// Swaps the materials named strFrom (all if empty) of an entity's scene graphs to strTo.
void FUN_141568470(egf::Entity* pEntity, CStringA strFrom, CStringA strTo)
{
    if (pEntity == 0)
        return;
    const egf::FlatModel* pModel = pEntity->GetModel();
    if (pModel->ContainsModel(0xbd4f8e8e))
    {
        ecr::SceneGraphService* pService = FUN_1413f98b0();
        FUN_141568650(pService->GetSceneGraphFromEntity(pEntity), strFrom, strTo);
    }
    if (pModel->ContainsModel(0x48ccc02d))
        FUN_141568650(FUN_141b6efc0(pEntity), strFrom, strTo);
}
MS2_REPLACE(0x141568470, FUN_141568470, 466, 0xD30E4AFB);

// @0x141568650
void FUN_141568650(NiAVObject* pRoot, CStringA strFrom, CStringA strTo)
{
    if (pRoot)
    {
        Unk_SceneWalker kWalker(pRoot);
        NiAVObject* pObject;
        while ((pObject = kWalker.Next(false)) != 0)
        {
            NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
            if (pMesh)
            {
                const NiMaterial* pMaterial = ((class NiRenderObject*)(class NiMesh*)(pMesh))->GetActiveMaterial();
                if (strFrom.IsEmpty() || (pMaterial && pMaterial->GetName() == (const char*)strFrom))
                    pMesh->ApplyAndSetActiveMaterial(NiMaterialLibrary::CreateMaterial((const char*)strTo));
                continue;
            }
            NiNode* pNode = NiDynamicCast(NiNode, pObject);
            if (pNode)
                kWalker.FUN_14098d6d0(pNode);
        }
    }
}
MS2_REPLACE(0x141568650, FUN_141568650, 395, 0xD0697876);

// @0x1415687f0
// Strips the fog properties of a subtree.
void FUN_1415687f0(NiAVObject* pRoot)
{
    if (pRoot == 0)
        return;
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(true)) != 0)
        pObject->RemoveProperty(NiProperty::FOG);
    pRoot->UpdateProperties();
}
MS2_REPLACE(0x1415687F0, FUN_1415687f0, 137, 0x3C094854);

// @0x141568880
// Detaches the lights attached anywhere in a subtree.
void FUN_141568880(NiAVObject* pRoot)
{
    if (pRoot == 0)
        return;
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(true)) != 0)
    {
        NiNode* pNode = NiDynamicCast(NiNode, pObject);
        if (pNode)
        {
            const NiDynamicEffectList* pEffects = &pNode->GetEffectList();
            CAtlArray<NiDynamicEffect*> kLights;
            NiTListIterator kPos = pEffects->GetHeadPos();
            while (pEffects && !pEffects->IsEmpty() && kPos)
            {
                NiLight* pLight = NiDynamicCast(NiLight, pEffects->GetNext(kPos));
                if (pLight)
                    kLights.Add(pLight);
            }
            for (size_t i = 0; i < kLights.GetCount(); i++)
                pNode->DetachEffect(kLights[i]);
        }
    }
    pRoot->UpdateEffects();
}
MS2_REPLACE(0x141568880, FUN_141568880, 390, 0x9068B09E);

// @0x141568a10
// Detaches all children of a node, last first.
void FUN_141568a10(NiNode* pNode)
{
    if (pNode == 0)
        return;
    unsigned int uiCount = pNode->GetArrayCount();
    if (uiCount == 0)
        return;
    for (int i = uiCount - 1; i >= 0; --i)
        pNode->DetachChildAt(i);
}
MS2_REPLACE(0x141568A10, FUN_141568a10, 117, 0x35CD2DD1);

// @0x141568a90
void FUN_141568a90(egf::Entity* pEntity)
{
    FUN_141568ac0(pEntity, FUN_1413fa320(pEntity));
}
MS2_REPLACE(0x141568A90, FUN_141568a90, 42, 0x731A1C00);

// @0x141568ac0
// Tints the materials of a tintable entity (any colour but the default grey 180/255).
void FUN_141568ac0(egf::Entity* pEntity, const efd::Color& kTint)
{
    if (pEntity == 0)
        return;
    const float fGrey = 180.0f / 255.0f;
    if (kTint.m_r == fGrey && kTint.m_g == fGrey && kTint.m_b == fGrey)
        return;
    const egf::FlatModel* pModel = pEntity->GetModel();
    if (pModel->ContainsModel(0x2ea80520))
    {
        NiColor kColor(kTint);
        NiAVObject* pScene = FUN_141b6efc0(pEntity);
        if (pScene == 0)
            return;
        Unk_SceneWalker kWalker(pScene);
        NiAVObject* pObject;
        while ((pObject = kWalker.Next(true)) != 0)
        {
            NiMaterialProperty* pMaterial = (NiMaterialProperty*)pObject->GetProperty(NiProperty::MATERIAL);
            if (pMaterial)
            {
                pMaterial->SetDiffuseColor(kColor);
                pMaterial->SetAmbientColor(kColor);
            }
        }
        pScene->UpdateProperties();
    }
}
MS2_REPLACE(0x141568AC0, FUN_141568ac0, 346, 0x1A3C283F);

// @0x141568c20
// The object has the shimmer marker.
bool FUN_141568c20(NiRenderObject* pkObject)
{
    if (DAT_143ae2b34)
        return (pkObject->GetMS2Flags() & 1) ? true : false;
    else
        return pkObject->GetExtraData(DAT_143ae51c8) != 0;
}
MS2_REPLACE(0x141568C20, FUN_141568c20, 104, 0xB83ECA4C);

extern NiFixedString DAT_143ae51c0;             // marker key: outline

// @0x141568c90
// The object has the outline marker.
bool FUN_141568c90(NiRenderObject* pkObject)
{
    if (DAT_143ae2b34)
        return (pkObject->GetMS2Flags() & 2) ? true : false;
    else
        return pkObject->GetExtraData(DAT_143ae51c0) != 0;
}
MS2_REPLACE(0x141568C90, FUN_141568c90, 104, 0xF9C879BB);

// @0x141568d00
bool FUN_141568d00(NiAVObject* pkObject)
{
    if (pkObject)
        return (pkObject->GetMS2Flags() & 2) ? true : false;
    return false;
}
MS2_REPLACE(0x141568D00, FUN_141568d00, 60, 0x8F0C3E2A);

// @0x141568d50
unsigned int FUN_141568d50(NiAVObject* pkObject)
{
    return pkObject->GetMS2Flags() & 0x80;
}
MS2_REPLACE(0x141568D50, FUN_141568d50, 29, 0xC890DF37);

// @0x141568d80
void FUN_141568d80(NiAVObject* pkObject)
{
    if (pkObject)
    {
        unsigned int uiFlags = pkObject->GetMS2Flags() | 2;
        pkObject->SetMS2Flags(uiFlags);
    }
}
MS2_REPLACE(0x141568D80, FUN_141568d80, 53, 0x1FB57C3D);

// @0x141568dc0
unsigned int FUN_141568dc0(NiAVObject* pkObject)
{
    return pkObject->GetMS2Flags() & 4;
}
MS2_REPLACE(0x141568DC0, FUN_141568dc0, 27, 0x8B23BDF1);

// @0x141568df0
void FUN_141568df0(NiAVObject* pRoot)
{
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(true)) != 0)
    {
        NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObject);
        if (pRender)
        {
            unsigned int uiFlags = pRender->GetMS2Flags() | 4;
            pRender->SetMS2Flags(uiFlags);
        }
    }
}
MS2_REPLACE(0x141568DF0, FUN_141568df0, 140, 0xE302A75B);

// @0x141568e90
unsigned int FUN_141568e90(NiAVObject* pkObject)
{
    return pkObject->GetMS2Flags() & 8;
}
MS2_REPLACE(0x141568E90, FUN_141568e90, 27, 0xF49272D4);

// @0x141568ec0
void FUN_141568ec0(NiAVObject* pRoot)
{
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(true)) != 0)
    {
        NiRenderObject* pRender = NiDynamicCast(NiRenderObject, pObject);
        if (pRender)
        {
            unsigned int uiFlags = pRender->GetMS2Flags() | 8;
            pRender->SetMS2Flags(uiFlags);
        }
    }
}
MS2_REPLACE(0x141568EC0, FUN_141568ec0, 140, 0x0A9B243B);

// @0x141568f60
unsigned int FUN_141568f60(NiAVObject* pkObject)
{
    return pkObject->GetMS2Flags() & 0x10;
}
MS2_REPLACE(0x141568F60, FUN_141568f60, 27, 0xEBD261CB);

// @0x141568f90
void FUN_141568f90(NiAVObject* pkObject)
{
    if (pkObject)
    {
        unsigned int uiFlags = pkObject->GetMS2Flags() | 0x10;
        pkObject->SetMS2Flags(uiFlags);
    }
}
MS2_REPLACE(0x141568F90, FUN_141568f90, 53, 0x024135C3);

// @0x141568fd0
void FUN_141568fd0(NiAVObject* pkObject)
{
    if (pkObject)
    {
        unsigned int uiFlags = pkObject->GetMS2Flags() & ~0x10u;
        pkObject->SetMS2Flags(uiFlags);
    }
}
MS2_REPLACE(0x141568FD0, FUN_141568fd0, 53, 0x804CC0F8);

// @0x141569010
unsigned int FUN_141569010(NiAVObject* pkObject)
{
    if (pkObject)
        return pkObject->GetMS2Flags() & 0x20;
    return 0;
}
MS2_REPLACE(0x141569010, FUN_141569010, 39, 0x41AFDF71);

// @0x141569040
void FUN_141569040(NiAVObject* pkObject)
{
    if (pkObject)
    {
        unsigned int uiFlags = pkObject->GetMS2Flags() | 0x20;
        pkObject->SetMS2Flags(uiFlags);
    }
}
MS2_REPLACE(0x141569040, FUN_141569040, 53, 0xC3A95AFA);

// @0x141569080
void FUN_141569080(NiAVObject* pkObject)
{
    if (pkObject)
    {
        unsigned int uiFlags = pkObject->GetMS2Flags() & ~0x20u;
        pkObject->SetMS2Flags(uiFlags);
    }
}
MS2_REPLACE(0x141569080, FUN_141569080, 53, 0x8F30FDBE);

// @0x1415690c0
unsigned int FUN_1415690c0(NiAVObject* pkObject)
{
    return pkObject->GetMS2Flags() & 0x40;
}
MS2_REPLACE(0x1415690C0, FUN_1415690c0, 27, 0x94D9AD2A);

// @0x1415690f0
void FUN_1415690f0(NiAVObject* pkObject)
{
    if (pkObject)
    {
        unsigned int uiFlags = pkObject->GetMS2Flags() | 0x40;
        pkObject->SetMS2Flags(uiFlags);
    }
}
MS2_REPLACE(0x1415690F0, FUN_1415690f0, 53, 0x82DD73C5);

// @0x141569130
void FUN_141569130(NiAVObject* pkObject)
{
    if (pkObject)
    {
        unsigned int uiFlags = pkObject->GetMS2Flags() & ~0x40u;
        pkObject->SetMS2Flags(uiFlags);
    }
}
MS2_REPLACE(0x141569130, FUN_141569130, 53, 0x57932F35);

// @0x141569170
// The property has an alpha controller whose float keys go above 1.
bool FUN_141569170(NiObjectNET* pkProperty)
{
    if (pkProperty == 0)
        return false;
    NiAlphaController* pController = NiDynamicCast(NiAlphaController, pkProperty->GetControllers());
    if (pController == 0)
        return false;
    NiKeyBasedInterpolator* pInterp = NiDynamicCast(NiKeyBasedInterpolator, pController->GetInterpolator(0));
    if (pInterp == 0)
        return false;
    if (pInterp->GetKeyContent(0) != NiAnimationKey::FLOATKEY)
        return false;
    unsigned int uiCount = pInterp->GetKeyCount(0);
    for (unsigned int ui = 0; ui < uiCount; ui++)
    {
        NiFloatKey* pKey = (NiFloatKey*)pInterp->GetKeyAt(ui, 0);
        if (pKey->GetValue() > 1.0f)
            return true;
    }
    return false;
}
MS2_REPLACE(0x141569170, FUN_141569170, 263, 0x38826B16);

// @0x141569280
// Render objects with an over-bright (or animated over-bright) material alpha use the alpha-blended material.
void FUN_141569280(NiRenderObject* pkObject)
{
    if (pkObject == 0)
        return;
    NiMaterialProperty* pMaterial = (NiMaterialProperty*)pkObject->GetProperty(NiProperty::MATERIAL);
    if (pMaterial == 0)
        return;
    if (pMaterial->GetAlpha() > 1.0f || FUN_141569170(pMaterial))
    {
        NiMaterial* pkMaterial = NiMaterialLibrary::CreateMaterial(DAT_143ae5230);
        pkObject->ApplyAndSetActiveMaterial(pkMaterial);
    }
}
MS2_REPLACE(0x141569280, FUN_141569280, 128, 0xAA69ACAF);

// @0x141569310
// The face part code of a render object, from its name.
int FUN_141569310(NiRenderObject* pkObject)
{
    if (pkObject)
    {
        const NiFixedString& kName = pkObject->GetName();
        if (kName == DAT_143ae51d8)
            return 1;
        else if (kName == "HR:0")
            return 2;
        else if (kName == "HR1:1")
            return 3;
        else if (kName == "HR0:0")
            return 4;
        else if (kName == "CPA:0")
            return 5;
        else if (kName == "EYA:0")
            return 6;
        else if (kName == "FHA:0")
            return 7;
        else if (kName == "PAA:0")
            return 8;
        else if (kName == "CLA:0")
            return 9;
        else if (kName == "MTA:0")
            return 10;
    }
    return 0;
}
MS2_REPLACE(0x141569310, FUN_141569310, 371, 0x56AF6C66);

// @0x141569620
// Moves the properties of pkProperty's type out of a subtree onto its root.
void FUN_141569620(NiAVObject* pRoot, NiProperty* pkProperty)
{
    int iType = pkProperty->Type();
    Unk_SceneWalker kWalker(pRoot);
    NiAVObject* pObject;
    while ((pObject = kWalker.Next(true)) != 0)
    {
        NiProperty* pOld = pObject->GetProperty(iType);
        if (pOld)
            pObject->DetachProperty(pOld);
    }
    pRoot->AttachProperty(pkProperty);
}
MS2_REPLACE(0x141569620, FUN_141569620, 177, 0x067C5D12);
