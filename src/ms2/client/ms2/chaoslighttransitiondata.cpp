// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The "ChaosLight" effect keyframe and param loader, and the
// layer pair (ChaosLightEffectLayer / ChaosLightEffectLayerManager) that tints a mesh's glow map and chaos material.
// Unit ?\chaoslighttransitiondata.cpp (0x1410459c0-0x141049240): the real functions first, then the std::map /
// std::vector / CAtlArray / NiPointer COMDATs the layer manager and the keyframe loader instantiate.
// MS2-UNIT: ?\chaoslighttransitiondata.cpp
// MS2-RANGE: 0x1410459c0-0x141049240 .text$mn
// MS2-PIN: memcpy_s 0x141048fd0
// w26-manual-pins-begin (identical-body COMDATs tplpin cannot tell apart)
// MS2-PIN: ?GetRTTI@NiObject@@UEBAPEBVNiRTTI@@XZ 0x141047bb0
// MS2-PIN: ??_GLayerManager@@UEAAPEAXI@Z 0x141047790
// MS2-PIN: ??1ChaosLightEffectLayerManager@@UEAA@XZ 0x141047320
// MS2-PIN: ??1Layer@@UEAA@XZ 0x141047370
// MS2-PIN: ??1LayerManager@@UEAA@XZ 0x1410473c0
// MS2-PIN: ??B?$SmartPointer@VChaosLightTransitionData@@@efd@@QEBAPEAVChaosLightTransitionData@@XZ 0x141047490
// MS2-PIN: ??CChaosPixelRef@@QEBAPEAVNiPixelData@@XZ 0x1410474c0
// w26-manual-pins-end
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1?$pair@$$CBV?$SmartPointer@VNiObjectNET@@@efd@@ULayerEntry@@@std@@QEAA@XZ 0x141047270 ; unique
// MS2-PIN: ??1LayerEntry@@QEAA@XZ 0x141047390 ; prop
// MS2-PIN: ??C?$SmartPointer@VChaosLightTransitionData@@@efd@@QEBAPEAVChaosLightTransitionData@@XZ 0x1410474a0 ; unique
// MS2-PIN: ??_GTransitionData@@UEAAPEAXI@Z 0x1410477f0 ; prop
// MS2-PINS-END tplpin
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\chaoslighttransitiondata.cpp"
// The exe's memcpy_s copy calls memset/memcpy (no /Oi expansion): the pragma must precede its inline definition.
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"
#include "chaoslighteffect.h"
#include "worldservice.h"
#include <efd/MemObject.h>
#include <efd/MemHint.h>
#include <NiMaterialLibrary.h>
#include <NiMesh.h>
#include <NiPixelData.h>
#include <NiSourceTexture.h>
#include <NiTexturingProperty.h>
#include <NiColorExtraData.h>
#include <NiFloatExtraData.h>
#include <NiFixedString.h>
#include <NiMaterialInstance.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit types and callees (bound to the exe by their FUN_<va> names / symbols) ----
class Unk_140165cf0                                                     // game TinyXML element
{
public:
    Unk_140165cf0* FUN_140165cf0(const char* pszName);                  // FirstChildElement(name)
    Unk_140165cf0* FUN_140168650(const char* pszName);                  // NextSiblingElement(name)
};
const char* FUN_14086f4b0(Unk_140165cf0* pNode, const char* pszName);
int FUN_140873360(Unk_140165cf0* pNode, const char* pszName, float& fOut);
int FUN_1408730a0(Unk_140165cf0* pNode, const char* pszName, bool& bOut);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int* pnOut);
int FUN_1408733e0(Unk_140165cf0* pNode, const char* pszName, CString& strOut);
CString FUN_140188f50(const char* psz, int n);                          // null-safe CString
void FUN_14185f0b0(TransitionData* pData, Unk_140165cf0* pNode, float* pfTime);    // type / duration / start time
void FUN_1402bd040(float* pVec3);                                       // zero a 3-vector
void FUN_141b6ed40(const CString& str, float* pVec3);                   // parse "x,y,z"

const NiMaterial* FUN_140a17cd0(NiMesh* pMesh);                         // the mesh's active material
// Out-of-line colour constructor (0x140a56db0), shared with other units' views.
struct Unk_Colc : NiColor { Unk_Colc(float r, float g, float b); };

// Layout view of the NiPixelData smart pointer: this unit carries its own operator-> COMDAT copy (0x1410474c0),
// distinct from the one in the shared symbol table, so it needs its own mangled name.
struct ChaosPixelRef
{
    NiPixelData* m_p;
    NiPixelData* operator->() const { return m_p; }
};

struct Unk_MaterialTable;                                               // DAT_143d69198
struct Unk_MaterialEntry;
extern Unk_MaterialTable DAT_143d69198;
Unk_MaterialEntry* FUN_140a17af0(Unk_MaterialTable* pTable, const NiMaterial* pMaterial);   // table lookup, NULL-safe
int FUN_140ef4dd0(Unk_MaterialEntry* pEntry);                           // the entry's material kind (1..3: chaos kinds)
WorldService* FUN_1403ed2d0();

extern NiFixedString DAT_143ae5158;                                     // "ChaosFresnelBoost"
extern NiFixedString DAT_143ae5160;                                     // "ChaosFresnelExponent"
extern NiFixedString DAT_143ae5168;                                     // "ChaosDimmer"
extern NiFixedString DAT_143ae5170;                                     // "ChaosLightColor"
extern NiFixedString DAT_143ae5240;                                     // "MS2ChaosMaterial"
extern NiFixedString DAT_143ae5248;                                     // "MS2ChaosSkinMaterial"
extern NiFixedString DAT_143ae5250;                                     // "MS2ChaosHairMaterial"
extern const NiPixelFormat DAT_1439fb040;                               // RGBA32

// @0x141047100
TransitionData::TransitionData()
    : m_nInterpolation(0), m_fDuration(0.0f), m_fStartTime(0.0f)
{
}

// @0x1410459c0
ChaosLightTransitionData::ChaosLightTransitionData()
    : m_fFresnelBoost(26.09f), m_fFresnelExponent(5.36f), m_fDimmer(0.0f), m_fRed(0.95f), m_fGreen(0.57f), m_fBlue(0.22f)
{
}

// @0x141045a60
// MS2-FUNCTIONAL: xml parse locals/GS cookie and symbol resolution differ from exe (frame/unwind); behavior equivalent
void ChaosLightEffectParam::vfunc_1(Unk_140165cf0* pNode)
{
    CEffectParam::vfunc_1(pNode);
    FUN_1408733e0(pNode, "node", m_strNode);
    FUN_140873360(pNode, "fresnelBoost", m_fFresnelBoost);
    FUN_140873360(pNode, "fresnelExponent", m_fFresnelExponent);
    FUN_140873360(pNode, "dimmer", m_fDimmer);
    FUN_1408730a0(pNode, "blink", m_bBlink);
    FUN_1408731e0(pNode, "blinkBoostStart", &m_nBlinkBoostStart);
    FUN_1408731e0(pNode, "layer", &m_nLayer);
    const char* pszRgb = FUN_14086f4b0(pNode, "rgb");
    if (pszRgb != 0)
    {
        float afRgb[3];
        FUN_1402bd040(afRgb);
        FUN_141b6ed40(CString(pszRgb), afRgb);
        m_fRed = afRgb[0];
        m_fGreen = afRgb[1];
        m_fBlue = afRgb[2];
    }

    // The first key carries the param's own values; every <transition> starts from the previous key.
    NiPointer<ChaosLightTransitionData> spFirst(new (efd::MemHint(efd::MemHint::NONE)) ChaosLightTransitionData);
    spFirst->m_fFresnelBoost = m_fFresnelBoost;
    spFirst->m_fFresnelExponent = m_fFresnelExponent;
    spFirst->m_fDimmer = m_fDimmer;
    spFirst->m_fRed = m_fRed;
    spFirst->m_fGreen = m_fGreen;
    spFirst->m_fBlue = m_fBlue;
    ChaosLightTransitionData* pPrev = spFirst;
    float fTime = m_fStartDelay;
    for (Unk_140165cf0* pKey = pNode->FUN_140165cf0("transition"); pKey != 0; pKey = pKey->FUN_140168650("transition"))
    {
        NiPointer<ChaosLightTransitionData> spData(new (efd::MemHint(efd::MemHint::NONE)) ChaosLightTransitionData);
        FUN_14185f0b0(spData.operator->(), pKey, &fTime);
        CString strLoop = FUN_140188f50(FUN_14086f4b0(pNode, "loop"), 0);
        if (strLoop.CompareNoCase("true") == 0 && m_nLoopIndex == -1)
            m_nLoopIndex = (int)m_arrData.GetCount();
        spData.operator->()->m_fFresnelBoost = pPrev->m_fFresnelBoost;
        spData.operator->()->m_fFresnelExponent = pPrev->m_fFresnelExponent;
        spData.operator->()->m_fDimmer = pPrev->m_fDimmer;
        spData.operator->()->m_fRed = pPrev->m_fRed;
        spData.operator->()->m_fGreen = pPrev->m_fGreen;
        spData.operator->()->m_fBlue = pPrev->m_fBlue;
        FUN_140873360(pKey, "fresnelBoost", spData.operator->()->m_fFresnelBoost);
        FUN_140873360(pKey, "fresnelExponent", spData.operator->()->m_fFresnelExponent);
        FUN_140873360(pKey, "dimmer", spData.operator->()->m_fDimmer);
        const char* pszKeyRgb = FUN_14086f4b0(pKey, "rgb");
        if (pszKeyRgb != 0)
        {
            float afRgb[3];
            FUN_1402bd040(afRgb);
            FUN_141b6ed40(CString(pszKeyRgb), afRgb);
            spData.operator->()->m_fRed = afRgb[0];
            spData.operator->()->m_fGreen = afRgb[1];
            spData.operator->()->m_fBlue = afRgb[2];
        }
        m_arrData.Add(NiPointer<TransitionData>(spData));
        pPrev = spData;
    }
}

#ifndef MS2_HOOK_DLL
// @0x141046110
// Not hooked: constructs ChaosLightEffect with its (DLL) constructor and vftable.
CEffectPtr ChaosLightEffectParam::vfunc_6()
{
    return new (efd::MemHint(efd::MemHint::NONE)) ChaosLightEffect;
}
#endif

// @0x141046540
// The chaos material (by kind: 1 normal, 2 skin, 3 hair) that matches the mesh's current material, or null.
NiMaterial* FUN_141046540(NiMesh* pMesh)
{
    Unk_MaterialEntry* pEntry = FUN_140a17af0(&DAT_143d69198, FUN_140a17cd0(pMesh));
    if (pEntry == 0)
        return 0;
    int anKinds[3] = { 1, 2, 3 };
    NiFixedString akNames[3] = { DAT_143ae5240, DAT_143ae5248, DAT_143ae5250 };
    int nKind = FUN_140ef4dd0(pEntry);
    for (unsigned int i = 0; i < 3; i++)
    {
        if (nKind != anKinds[i])
            continue;
        NiMaterial* pMaterial = NiMaterialLibrary::CreateMaterial(akNames[i]);
        return pMaterial;
    }
    return 0;
}

// @0x1410479a0
// Set (or add) the colour extra data under a key.
void FUN_1410479a0(NiObjectNET* pObject, const NiFixedString& kKey, const NiColor& kColor)
{
    NiColorExtraData* pExtra = NiDynamicCast(NiColorExtraData, pObject->GetExtraData(kKey));
    if (pExtra == 0)
    {
        pExtra = NiNew NiColorExtraData(kColor);
        pObject->AddExtraData(kKey, pExtra);
    }
    else
    {
        pExtra->SetValue(kColor);
    }
}

// @0x141047ac0
// Set (or add) the float extra data under a key.
void FUN_141047ac0(NiObjectNET* pObject, const NiFixedString& kKey, float fValue)
{
    NiFloatExtraData* pExtra = NiDynamicCast(NiFloatExtraData, pObject->GetExtraData(kKey));
    if (pExtra == 0)
    {
        pExtra = NiNew NiFloatExtraData(fValue);
        pObject->AddExtraData(kKey, pExtra);
    }
    else
    {
        pExtra->SetValue(fValue);
    }
}

// @0x1410461b0
ChaosLightEffectLayer::ChaosLightEffectLayer(NiMesh* pMesh, void* pTexture, const ChaosLightEffectParam* pParam)
    : Layer(pParam != 0 ? pParam->m_nLayer : 0xffffffff), m_spMesh(0), m_spTexture(0), m_bActive(false)
{
    m_spMesh = pMesh;
    m_spTexture.Assign(pTexture);
    if (pParam != 0)
    {
        m_pMaterial = FUN_141046540(pMesh);
        m_param.FUN_141043a30(*pParam);
    }
    else
    {
        m_pMaterial = const_cast<NiMaterial*>(FUN_140a17cd0(pMesh));
        m_param.m_fBlue = 0.0f;
        m_param.m_fGreen = 0.0f;
        m_param.m_fRed = 0.0f;
        m_param.m_fDimmer = 1.0f;
        m_param.m_fFresnelBoost = 0.0f;
        m_param.m_fFresnelExponent = 0.0f;
        m_param.m_nLayer = -1;
        NiProperty* pProp = pMesh->GetProperty(NiProperty::TEXTURING);
        if (pProp != 0)
        {
            NiTexturingProperty::Map* pMap = static_cast<NiTexturingProperty*>(pProp)->GetGlowMap();
            if (pMap != 0)
            {
                ChaosLightEffectLayerManager* pManager = FUN_1403ed2d0()->FUN_141bd3680();
                if (((__int64)pManager->FUN_1410469c0()) != (__int64)pMap->GetTexture())
                    m_spTexture.Assign(pMap->GetTexture());
            }
        }
    }
}

// @0x1410463e0
NiMesh* ChaosLightEffectLayer::vfunc_18()
{
    return m_spMesh;
}

// @0x141046410
void ChaosLightEffectLayer::FUN_141046410(const ChaosLightEffectParam& rParam)
{
    m_param.FUN_141043a30(rParam);
    if (!m_bActive)
        return;
    Unk_Colc kColor(m_param.m_fRed, m_param.m_fGreen, m_param.m_fBlue);
    FUN_1410479a0(m_spMesh, DAT_143ae5170, kColor);
    FUN_141047ac0(m_spMesh, DAT_143ae5158, m_param.m_fFresnelBoost);
    FUN_141047ac0(m_spMesh, DAT_143ae5160, m_param.m_fFresnelExponent);
    FUN_141047ac0(m_spMesh, DAT_143ae5168, m_param.m_fDimmer);
}

// @0x1410466b0
void ChaosLightEffectLayer::vfunc_19()
{
    m_bActive = true;
    FUN_141046410(m_param);
    NiProperty* pProp = m_spMesh->GetProperty(NiProperty::TEXTURING);
    if (pProp != 0)
    {
        NiTexturingProperty::Map* pMap = NiNew NiTexturingProperty::Map;
        pMap->SetTexture((NiTexture*)m_spTexture.Get());
        static_cast<NiTexturingProperty*>(pProp)->SetGlowMap(pMap);
    }
    m_spMesh->ApplyAndSetActiveMaterial(m_pMaterial, 0xffffffff);
    const NiMaterialInstance* pInstance = m_spMesh->GetActiveMaterialInstance();
    if (pInstance != 0)
        const_cast<NiMaterialInstance*>(pInstance)->ClearCachedShader();
}

// @0x141046820
void ChaosLightEffectLayer::vfunc_20()
{
    Layer::vfunc_20();
    m_bActive = false;
}

// @0x141046850
// MS2-FUNCTIONAL: temp/local slot order differs from exe (frame 0x88 vs 0x78); behavior equivalent
ChaosLightEffectLayerManager::ChaosLightEffectLayerManager()
    : m_spTexture(0)
{
    NiPointer<NiPixelData> spPixels(NiNew NiPixelData(1, 1, DAT_1439fb040, 1, 1));
    efd::ColorA_UInt8 kWhite = efd::ColorA_UInt8(255, 255, 255, 255);
    *(efd::ColorA_UInt8*)reinterpret_cast<ChaosPixelRef&>(spPixels)->operator()(0, 0, 0, 0) = kWhite;
    m_spTexture.Assign(NiSourceTexture::Create((NiPixelData*)spPixels, *(NiTexture::FormatPrefs*)&DAT_1439fc800, true));
}

// @0x1410469c0
void* ChaosLightEffectLayerManager::FUN_1410469c0()
{
    return m_spTexture.Get();
}

// @0x1410469f0
NiPointer<Layer> ChaosLightEffectLayerManager::vfunc_18(NiAVObject* pObject)
{
    NiMesh* pMesh = NiDynamicCast(NiMesh, pObject);
    if (pMesh == 0)
        return NiPointer<Layer>((Layer*)0);
    return NiPointer<Layer>(new (efd::MemHint(efd::MemHint::NONE)) ChaosLightEffectLayer(pMesh, 0, 0));
}

// @0x1410470b0
LayerManager::LayerManager()
{
}

// Trailing unreferenced CRT memcpy_s COMDAT 0x141048fd0.
__declspec(selectany) extern errno_t(__cdecl* const ms2_chaosMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
