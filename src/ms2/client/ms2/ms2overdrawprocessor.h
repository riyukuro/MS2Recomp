// ms2overdrawprocessor.h - MS2OverdrawProcessor: debug render-list processor (0x100 bytes) that draws every object
// with the overdraw material, no z-buffer test/write and additive-style blending, then restores the saved state.
// Owning unit: ?\ms2overdrawprocessor.cpp (0x1414d4e20-0x1414d6c20, dir client\ms2). Field names inferred.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/ms2renderlistprocessor.h"
#include <NiMaterial.h>
#include <NiZBufferProperty.h>
#include <NiAlphaProperty.h>

class MS2OverdrawProcessor : public MS2RenderListProcessor
{
public:
    static const NiRTTI ms_RTTI;                            // 0x143ae0bc0
    virtual const NiRTTI* GetRTTI() const;                  // 0x1414d6400

public:
    MS2OverdrawProcessor();                                 // 0x1414d4e20
    // ~MS2OverdrawProcessor() is implicit (0x1414d61d0, ??_G 0x1414d6360): the exe dtor has no vftable store.
    virtual void PreRenderProcessList(const NiVisibleArray* pkInput, NiVisibleArray& kOutput, void* pvExtraData);   // 0x1414d5070

public:
    NiMaterialPtr m_spOverdrawMaterial;                     // +0xe8
    NiZBufferPropertyPtr m_spZBuffer;                       // +0xf0
    NiAlphaPropertyPtr m_spAlpha;                           // +0xf8
};
MS2_CHECK_SIZE(MS2OverdrawProcessor, 0x100);
MS2_CHECK_OFFSET(MS2OverdrawProcessor, m_spOverdrawMaterial, 0xe8);
