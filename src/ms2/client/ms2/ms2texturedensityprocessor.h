// ms2texturedensityprocessor.h - MS2TextureDensityProcessor: debug render-list processor (0xd0 bytes) that replaces
// the textures of every visible object's NiTexturingProperty with a generated per-mip-level colour ramp (one cached
// texture per source texture size) so texel density can be judged visually, then restores the originals.
// Owning unit: ?\ms2texturedensityprocessor.cpp (0x14150cd00-0x1415154d0, dir client\ms2). Field names inferred.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/postprocesseffect.h"      // Unk_PPSmartC
#include <map>
#include <NiShaderSortProcessor.h>
#include <NiMaterial.h>

// Cache key: source texture size. operator< is the exe's (it only orders by width when the sizes differ).
struct Unk_TexSizeKey
{
    int m_nWidth;
    int m_nHeight;
    bool operator<(const Unk_TexSizeKey& rhs) const;        // 0x14150d710
};

// A saved texture slot (smart pointer + clamp mode) per distinct texturing property.
struct Unk_TexSlot
{
    Unk_PPSmartC m_spTexture;
    unsigned m_nClampMode;
    Unk_TexSlot();                                          // 0x1415116d0
    Unk_TexSlot(const Unk_TexSlot& rhs);                    // 0x141511690
    Unk_TexSlot(Unk_TexSlot&& rhs);                         // 0x141511650 (same body)
};

typedef std::map<Unk_TexSizeKey, Unk_PPSmartC> Unk_DensityTextureMap;

class MS2TextureDensityProcessor : public NiShaderSortProcessor
{
public:
    static const NiRTTI ms_RTTI;                            // 0x143ae0e78
    virtual const NiRTTI* GetRTTI() const;                  // 0x1415120e0

public:
    MS2TextureDensityProcessor();                           // 0x14150cd00
    virtual ~MS2TextureDensityProcessor();                  // 0x1415118c0, ??_G 0x141511ff0
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x14150cdb0

    void SetMode(int nMode);                          // 0 = base map, 1 = normal map, 2 = parallax map
    int GetMode() const;
    NiTexture* FUN_14150d3a0(int nWidth, int nHeight);      // cached density texture for a source texture size

public:
    Unk_DensityTextureMap m_textures;                       // +0xb0
    NiMaterialPtr m_spMaterial;                             // +0xc0
    int m_nMode;                                            // +0xc8
};
MS2_CHECK_SIZE(MS2TextureDensityProcessor, 0xd0);
MS2_CHECK_OFFSET(MS2TextureDensityProcessor, m_textures, 0xb0);
MS2_CHECK_OFFSET(MS2TextureDensityProcessor, m_nMode, 0xc8);
