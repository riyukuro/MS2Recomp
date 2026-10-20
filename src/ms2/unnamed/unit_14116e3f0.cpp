// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The customised skin decal of an equipped mesh: FUN_14116e3f0 clones the
// mesh's texturing property and adds the decal / tint shader maps plus their extra data (the four decal parameters and the three
// tint colours); FUN_14116e7f0 bakes them back into one composed base texture through CCustomizedTextureManager, remembering the
// original base / control texture paths as string extra data. Types as in charactermeshmerger.cpp (which reads the same keys).
// MS2-UNIT: unit_14116e3f0
// MS2-RANGE: 0x14116e3f0-0x14116f6a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <NiMesh.h>
#include <NiTexture.h>
#include <NiSourceTexture.h>
#include <NiTexturingProperty.h>
#include <NiCloningProcess.h>
#include <NiColorExtraData.h>
#include <NiFloatsExtraData.h>
#include <NiStringExtraData.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"                             // TSingleton<T>
#include "ms2/client/ms2/nifeffectparam.h"                  // CNifLoadingService
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- shared with charactermeshmerger.cpp / customizedtexinfo.cpp (same layout, defined there too) -------------------------------------------------

// The dye parameters of one customised character texture.
class CCustomizedTexInfo : public NiRefObject
{
public:
    CCustomizedTexInfo();                                   // 0x141165f00

    efd::SmartPointer<NiTexture> m_spBase;                  // +0x10
    efd::SmartPointer<NiTexture> m_spDecal;                 // +0x18
    NiColorA m_akColor[3];                                  // +0x20 (indexed, as customizedtexinfo.cpp)
    float m_fParam0;                                        // +0x50 the four decal parameters (named fields, not an array:
    float m_fParam1;                                        // +0x54  the exe stores them without index arithmetic)
    float m_fParam2;                                        // +0x58
    float m_fParam3;                                        // +0x5c
};
MS2_CHECK_SIZE(CCustomizedTexInfo, 0x60);
// Composes the customized character textures (header-inline singleton, 8 bytes: the vptr only).
class CCustomizedTextureManager : public TSingleton<CCustomizedTextureManager>
{
public:
    CCustomizedTextureManager() {}
    static CCustomizedTextureManager* CreateInstance() { return GetInstance() != 0 ? GetInstance() : new CCustomizedTextureManager; }
};
MS2_CHECK_SIZE(CCustomizedTextureManager, 0x8);
CCustomizedTexInfo* FUN_1411660b0(CCustomizedTextureManager* pManager, CCustomizedTexInfo* pInfoA, CCustomizedTexInfo* pInfoB);

// ---- exe callees and data -------------------------------------------------------------------------------------------------

CNifLoadingService* FUN_140a0afd0();
void FUN_1410479a0(NiObjectNET* pObject, const NiFixedString& kKey, const NiColor& kColor);   // set colour extra data
extern const NiFixedString DAT_143ae50c8;                   // customised texture extra data keys
extern const NiFixedString DAT_143ae50d0;
extern const NiFixedString DAT_143ae50d8;
extern const NiFixedString DAT_143ae50f8;
extern const NiFixedString DAT_143ae5100;
extern const NiFixedString DAT_143ae5108;
extern const NiFixedString DAT_143ae5110;

void FUN_14116f480(NiObjectNET* pObject, const NiFixedString& kKey, unsigned int uiSize, const float* pfValues);

// Applies the skin decal: a private copy of the texturing property gets the decal parameters, the decal texture as shader map 1
// and (bTint) the tint mask as shader map 2 with its three colours.
// @0x14116e3f0
bool FUN_14116e3f0(NiMesh* pMesh, float fA, float fB, float fC, float fD, int bTint, const CString& strTexture,
    const NiColor& kColor0, const NiColor& kColor1, const NiColor& kColor2)
{
    NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(8));
    if (pTexturing == 0)
        return false;
    NiCloningProcess kCloning;
    pTexturing = static_cast<NiTexturingProperty*>(pTexturing->Clone(kCloning));
    pMesh->RemoveProperty(8);
    pMesh->AttachProperty(pTexturing);
    float afParams[4] = { fA, fB, fC, fD };
    FUN_14116f480(pMesh, DAT_143ae50f8, 4, afParams);
    NiTexturePtr spDecal = FUN_140a0afd0()->GetTexture(strTexture, 5);
    NiTexturingProperty::ShaderMap* pMap = NiNew NiTexturingProperty::ShaderMap(spDecal, 0,
        NiTexturingProperty::CLAMP_S_CLAMP_T, NiTexturingProperty::FILTER_TRILERP, 1);
    pTexturing->SetShaderMap(1, pMap);
    if (bTint)
    {
        NiTexturePtr spTint = FUN_140a0afd0()->GetTexture(strTexture, 5);
        pMap = NiNew NiTexturingProperty::ShaderMap(spTint, 0,
            NiTexturingProperty::CLAMP_S_CLAMP_T, NiTexturingProperty::FILTER_TRILERP, 2);
        pTexturing->SetShaderMap(2, pMap);
        FUN_1410479a0(pMesh, DAT_143ae5100, kColor0);
        FUN_1410479a0(pMesh, DAT_143ae5108, kColor1);
        FUN_1410479a0(pMesh, DAT_143ae5110, kColor2);
    }
    pMesh->UpdateProperties();
    return true;
}
MS2_REPLACE(0x14116E3F0, FUN_14116e3f0, 1011, 0xA177358B);

// Bakes the customised texture: composes the base (+ control map and colours) and the decal (+ tint map and colours) into one
// texture, keeps the original paths as extra data, and leaves only the composed base texture on the property.
// @0x14116e7f0
bool FUN_14116e7f0(NiAVObject* pMesh)
{
    NiTexturingProperty* pTexturing = NiDynamicCast(NiTexturingProperty, pMesh->GetProperty(8));
    if (pTexturing == 0)
        return false;

    efd::SmartPointer<CCustomizedTexInfo> spInfoA = NiNew CCustomizedTexInfo;
    spInfoA->m_spBase = pTexturing->GetBaseTexture();
    if (pTexturing->GetShaderMap(0) != 0)
    {
        NiColorExtraData* pColor = 0;
        spInfoA->m_spDecal = pTexturing->GetShaderMap(0)->GetTexture();
        pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae50c8));
        spInfoA->m_akColor[0] = pColor != 0 ? pColor->GetValue() : NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
        pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae50d0));
        spInfoA->m_akColor[1] = pColor != 0 ? pColor->GetValue() : NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
        pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae50d8));
        spInfoA->m_akColor[2] = pColor != 0 ? pColor->GetValue() : NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
    }

    efd::SmartPointer<CCustomizedTexInfo> spInfoB = NiNew CCustomizedTexInfo;
    NiTexture* pDecal = pTexturing->GetShaderMap(1)->GetTexture();
    NiTexture* pTint = pTexturing->GetShaderMap(2) != 0 ? pTexturing->GetShaderMap(2)->GetTexture() : 0;
    spInfoB->m_spBase = pDecal;
    NiFloatsExtraData* pParams = NiDynamicCast(NiFloatsExtraData, pMesh->GetExtraData(DAT_143ae50f8));
    spInfoB->m_fParam0 = pParams->GetValue(0);
    spInfoB->m_fParam1 = pParams->GetValue(1);
    spInfoB->m_fParam2 = pParams->GetValue(2);
    spInfoB->m_fParam3 = pParams->GetValue(3);
    if (pTint != 0)
    {
        spInfoB->m_spDecal = pTint;
        NiColorExtraData* pColor = 0;
        pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae5100));
        spInfoB->m_akColor[0] = pColor != 0 ? pColor->GetValue() : NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
        pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae5108));
        spInfoB->m_akColor[1] = pColor != 0 ? pColor->GetValue() : NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
        pColor = NiDynamicCast(NiColorExtraData, pMesh->GetExtraData(DAT_143ae5110));
        spInfoB->m_akColor[2] = pColor != 0 ? pColor->GetValue() : NiColorA(1.0f, 1.0f, 1.0f, 1.0f);
    }

    if (CCustomizedTextureManager::GetInstance() == 0)
        CCustomizedTextureManager::CreateInstance();
    efd::SmartPointer<CCustomizedTexInfo> spComposed = FUN_1411660b0(CCustomizedTextureManager::GetInstance(), spInfoA, spInfoB);

    NiSourceTexture* pBase = NiDynamicCast(NiSourceTexture, pTexturing->GetBaseTexture());
    if (pBase != 0)
    {
        CString strPath((const char*)pBase->GetPlatformSpecificFilename());
        if (pMesh->GetExtraData("OriginalBaseTexturePath") == 0)
            pMesh->AddExtraData("OriginalBaseTexturePath", NiNew NiStringExtraData((const char*)strPath));
    }
    if (pTexturing->GetShaderMap(0) != 0)
    {
        NiSourceTexture* pControl = NiDynamicCast(NiSourceTexture, pTexturing->GetShaderMap(0)->GetTexture());
        if (pControl != 0)
        {
            CString strPath((const char*)pControl->GetPlatformSpecificFilename());
            if (pMesh->GetExtraData("OriginalControlTexturePath") == 0)
                pMesh->AddExtraData("OriginalControlTexturePath", NiNew NiStringExtraData((const char*)strPath));
        }
    }

    pTexturing->SetBaseTexture(spComposed->m_spBase);
    pTexturing->SetShaderMap(0, 0);
    pMesh->UpdateProperties();
    return true;
}
MS2_REPLACE(0x14116E7F0, FUN_14116e7f0, 3207, 0xE73A253A);

// Sets (or adds) the float array extra data kKey of the object.
// @0x14116f480
void FUN_14116f480(NiObjectNET* pObject, const NiFixedString& kKey, unsigned int uiSize, const float* pfValues)
{
    NiFloatsExtraData* pData = NiDynamicCast(NiFloatsExtraData, pObject->GetExtraData(kKey));
    if (pData == 0)
    {
        pData = NiNew NiFloatsExtraData(uiSize, pfValues);
        pObject->AddExtraData(kKey, pData);
    }
    else
    {
        pData->SetArray(uiSize, pfValues);
    }
}
MS2_REPLACE(0x14116F480, FUN_14116f480, 240, 0x8D7192A7);

// 0x14116f570 is NiSourceTexture::GetPlatformSpecificFilename (inline SDK COMDAT, emitted by FUN_14116e7f0).

// @0x14116f580 - the CRT's bounds-checked memmove_s (UCRT static-inline copy, unreferenced in this TU).
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
