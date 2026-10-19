// ms2outerglowmaterialswapprocessor.h - MS2OuterGlowMaterialSwapProcessor: render-list processor that draws the
// objects of the outer-glow materials again with the glow material (z write off) after the normal list.
// Owning unit: unit_1414d2460 (0x1414d2460-0x1414d3120). Only the members this unit touches are declared; the class
// size is not recovered (the ctor lives in another unit).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/ms2renderlistprocessor.h"
#include <NiMaterial.h>

class MS2OuterGlowMaterialSwapProcessor : public MS2RenderListProcessor
{
public:
    static const NiRTTI ms_RTTI;                                                        // 0x143ae0ad8
    virtual const NiRTTI* GetRTTI() const;                                              // 0x1409a8c70
    MS2OuterGlowMaterialSwapProcessor(NiMaterialPtr spMaterial);                        // 0x1409a78e0 (?\applyeffect.cpp)
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x1414d2460

    NiMaterialPtr m_spGlowMaterial;                         // +0xe8 the material the glowing objects are drawn with
};
MS2_CHECK_OFFSET(MS2OuterGlowMaterialSwapProcessor, m_spGlowMaterial, 0xe8);
