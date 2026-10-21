// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Texture-density visualisation render-list processor.
// MS2-UNIT: ?\ms2texturedensityprocessor.cpp
// MS2-RANGE: 0x14150cd00-0x1415154d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$forward@AEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiTexturingProperty@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiTexturingProperty@@@std@@@std@@@0@AEAV10@@Z 0x141510f80 ; unique
// MS2-PIN: ??$forward@AEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBUUnk_TexSizeKey@@VUnk_PPSmartC@@@std@@@std@@@std@@@std@@@std@@YAAEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBUUnk_TexSizeKey@@VUnk_PPSmartC@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141510f90 ; unique
// MS2-PIN: ??$forward@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiTexturingProperty@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiTexturingProperty@@@std@@@std@@@0@AEAV10@@Z 0x141511010 ; unique
// MS2-PIN: ??$forward@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBUUnk_TexSizeKey@@VUnk_PPSmartC@@@std@@@std@@@std@@@std@@@std@@YA$$QEAV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBUUnk_TexSizeKey@@VUnk_PPSmartC@@@std@@@std@@@std@@@0@AEAV10@@Z 0x141511020 ; unique
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAVNiTexturingProperty@@@std@@@std@@@std@@QEBAAEBQEAVNiTexturingProperty@@XZ 0x141511ae0 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBUUnk_TexSizeKey@@VUnk_PPSmartC@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBUUnk_TexSizeKey@@VUnk_PPSmartC@@@1@XZ 0x141511b00 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@PEBVNiMaterial@@@std@@V?$_Vector_val@U?$_Simple_types@PEBVNiMaterial@@@std@@@2@$00@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@PEBVNiMaterial@@@std@@@2@XZ 0x1415138e0 ; unique
// MS2-PINS-END tplpin
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2texturedensityprocessor.h"
#include "hook/ms2hook.h"
#include <set>
#include <vector>
#include <algorithm>
#include <NiRenderObject.h>
#include <NiAVObject.h>
#include <NiVisibleArray.h>
#include <NiTexturingProperty.h>
#include <NiSourceTexture.h>
#include <NiPixelData.h>
#include <NiPixelFormat.h>
#include <NiMaterialLibrary.h>

// ---- out-of-unit callees ----
extern NiFixedString DAT_143ae5218;                                         // density material name
unsigned FUN_140d89680(const NiVisibleArray* arr);                          // NiVisibleArray count
NiRenderObject* FUN_1414d1830(const NiVisibleArray* arr, unsigned i);       // NiVisibleArray::GetAt
NiTexturingProperty::Map* FUN_14121cde0(NiTexturingProperty* pProp);        // parallax map accessor
class NiPropertyState;
NiPropertyState* FUN_140994420(NiRenderObject* pObj);                       // obj->GetPropertyState()
NiTexturingProperty* FUN_140d8a020(NiPropertyState* pState);                // state's texturing property

// @0x1415116d0
Unk_TexSlot::Unk_TexSlot() : m_spTexture(0)
{
}

// @0x141511690
Unk_TexSlot::Unk_TexSlot(const Unk_TexSlot& rhs) : m_spTexture(rhs.m_spTexture)
{
    m_nClampMode = rhs.m_nClampMode;
}

// @0x141511650
Unk_TexSlot::Unk_TexSlot(Unk_TexSlot&& rhs) : m_spTexture(rhs.m_spTexture)
{
    m_nClampMode = rhs.m_nClampMode;
}

// @0x14150cd00
MS2TextureDensityProcessor::MS2TextureDensityProcessor()
    : NiShaderSortProcessor(0x20, 0x25, 0x200, 0x80)
{
    m_spMaterial = NiMaterialLibrary::CreateMaterial(DAT_143ae5218);
    m_nMode = 0;
}

// @0x14150cdb0
// MS2-FUNCTIONAL: same calls and control flow as the exe; the exe keeps 0x10 more stack temporaries (iterator results)
void MS2TextureDensityProcessor::PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData)
{
    if (pkInput == NULL)
        return;

    unsigned count = FUN_140d89680(pkInput);
    std::set<NiTexturingProperty*> props;
    std::vector<const NiMaterial*> savedMaterials;
    for (unsigned i = 0; i < count; ++i) {
        NiRenderObject* obj = FUN_1414d1830(pkInput, i);
        NiTexturingProperty* tp = FUN_140d8a020(FUN_140994420(obj));
        if (tp) {
            if (props.find(tp) == props.end())
                props.insert(tp);
        }
        const NiMaterial* pActive = obj->GetActiveMaterial();
        savedMaterials.push_back(pActive);
        obj->ApplyAndSetActiveMaterial(m_spMaterial, 0xffffffff);
    }

    std::vector<Unk_TexSlot> savedMaps;
    for (std::set<NiTexturingProperty*>::iterator it = props.begin(); it != props.end(); ++it) {
        NiTexturingProperty* tp = *it;
        NiTexturingProperty::Map* pBase = tp->GetBaseMap();
        Unk_TexSlot saved;
        if (pBase == NULL) {
            saved.m_spTexture.Assign(0);
            saved.m_nClampMode = 0;
        } else {
            saved.m_spTexture.Assign(pBase->GetTexture());
            saved.m_nClampMode = pBase->GetClampMode();
        }
        savedMaps.push_back(saved);

        NiTexturingProperty::Map* pMap = NULL;
        if (m_nMode == 0)
            pMap = pBase;
        else if (m_nMode == 1)
            pMap = tp->GetNormalMap();
        else if (m_nMode == 2)
            pMap = FUN_14121cde0(tp);
        if (pMap && pMap->GetTexture()) {
            NiTexture* pSrc = pMap->GetTexture();
            tp->SetBaseTexture(FUN_14150d3a0(pSrc->GetWidth(), pSrc->GetHeight()));
            tp->SetBaseClampMode(NiTexturingProperty::ClampMode(3));
        }
    }

    for (unsigned i = 0; i < count; ++i)
        FUN_1414d1830(pkInput, i)->UpdateProperties();

    NiShaderSortProcessor::PreRenderProcessList(pkInput, kOutput, pvExtraData);

    int idx = 0;
    for (std::set<NiTexturingProperty*>::iterator it = props.begin(); it != props.end(); ++it) {
        Unk_TexSlot& saved = savedMaps[idx++];
        if (saved.m_spTexture.Get()) {
            (*it)->SetBaseTexture(static_cast<NiTexture*>(saved.m_spTexture.Get()));
            (*it)->SetBaseClampMode(NiTexturingProperty::ClampMode(saved.m_nClampMode));
        }
    }

    for (unsigned i = 0; i < count; ++i) {
        NiRenderObject* obj = FUN_1414d1830(pkInput, i);
        obj->SetActiveMaterial(savedMaterials[i]);
        obj->UpdateProperties();
    }
}

MS2_REPLACE_METHOD(0x14150CDB0, MS2TextureDensityProcessor, PreRenderProcessList, 1440, 0x5375FCE8);

// @0x14150d360
void MS2TextureDensityProcessor::FUN_14150d360(int nMode)
{
    m_nMode = nMode;
}

// @0x14150d380
int MS2TextureDensityProcessor::FUN_14150d380() const
{
    return m_nMode;
}

// @0x14150d3a0
// MS2-FUNCTIONAL: identical except register choice when forming &m_textures and an extra 0x10 of stack temporaries
NiTexture* MS2TextureDensityProcessor::FUN_14150d3a0(int nWidth, int nHeight)
{
    Unk_TexSizeKey key;
    key.m_nWidth = nWidth;
    key.m_nHeight = nHeight;
    Unk_DensityTextureMap::iterator it = m_textures.find(key);
    if (it != m_textures.end())
        return static_cast<NiTexture*>(it->second.Get());

    NiPointer<NiPixelData> spPixels = NiNew NiPixelData(nWidth * 3, nHeight * 3, NiPixelFormat::RGBA32, 0, 1);
    unsigned nLevels = spPixels->GetNumMipmapLevels();
    unsigned colors[5] = { 0xff0000ff, 0xffff00ff, 0xff00ff, 0xffffff, 0xffff };
    for (unsigned mip = 0; mip < nLevels; ++mip) {
        unsigned color = colors[(std::min)(mip, 4u)];
        for (unsigned x = 0; x < spPixels->GetWidth(mip, 0); ++x) {
            for (unsigned y = 0; y < spPixels->GetHeight(mip, 0); ++y) {
                unsigned* pPixel = reinterpret_cast<unsigned*>((*spPixels)(x, y, mip, 0));
                *pPixel = color;
            }
        }
    }
    NiTexture::FormatPrefs prefs;
    prefs.m_ePixelLayout = NiTexture::FormatPrefs::TRUE_COLOR_32;
    prefs.m_eMipMapped = NiTexture::FormatPrefs::YES;
    prefs.m_eAlphaFmt = NiTexture::FormatPrefs::NONE;
    NiTexture* pTex = NiSourceTexture::Create(spPixels, prefs, true);
    m_textures[key].Assign(pTex);
    return FUN_14150d3a0(nWidth, nHeight);
}

// @0x14150d710
bool Unk_TexSizeKey::operator<(const Unk_TexSizeKey& rhs) const
{
    if (m_nWidth == rhs.m_nWidth && m_nHeight == rhs.m_nHeight)
        return false;
    else if (m_nWidth < rhs.m_nWidth)
        return true;
    else
        return false;
}

// @0x1415118c0
// MS2-FUNCTIONAL: the exe dtor does not store the class vftable before destroying members; cl always does here
MS2TextureDensityProcessor::~MS2TextureDensityProcessor()
{
}

// @0x1415120e0
const NiRTTI* MS2TextureDensityProcessor::GetRTTI() const { return &ms_RTTI; }

// Shared header statics and class metadata of this TU (.text$di + atexit thunks; gap2 orphan di sweep).
// MS2-RANGE: 0x1400f9730-0x1400f98d0 .text$di
// MS2-RANGE: 0x142cb32c0-0x142cb3350 .text$yd
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/client/ms2/ms2renderlistprocessor.h"
#ifndef MS2_HOOK_DLL
const NiRTTI MS2TextureDensityProcessor::ms_RTTI("MS2TextureDensityProcessor", &MS2RenderListProcessor::ms_RTTI);
#endif

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE_METHOD(0x14150d360, MS2TextureDensityProcessor, FUN_14150d360, 25, 0xA8D572C7);
MS2_REPLACE_METHOD(0x14150d380, MS2TextureDensityProcessor, FUN_14150d380, 17, 0x690E246B);
MS2_REPLACE_METHOD(0x1415120e0, MS2TextureDensityProcessor, GetRTTI, 13, 0xB0C3BA1A);

