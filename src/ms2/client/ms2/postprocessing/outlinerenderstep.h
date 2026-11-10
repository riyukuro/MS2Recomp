// OutlineRenderStep (RTTI name): outline post-process step. 0xc8 bytes, 24 vftable slots.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/postprocesseffect.h"
#include <NiRenderer.h>
#include <NiRenderTargetGroup.h>
#include <NiRenderedTexture.h>

NiRenderer* GetNiRenderer();   // NiRenderer::GetRenderer()
void FUN_141475e60(void* p);
void ClearRenderClicks(void* p);

class OutlineRenderStep : public ReloadablePostProcess {
public:
    OutlineRenderStep(unsigned __int64 a, unsigned int b);      // 0x1416263e0
    // implicit: virtual ~OutlineRenderStep();                             // 0x1416269c0
    virtual const NiRTTI* GetRTTI() const;                      // 0x141626a90
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416264b0
    virtual void vfunc_16();                                    // 0x141626970
    virtual bool vfunc_23();                                    // 0x141626650

    static const NiRTTI ms_RTTI;                                // 0x143ae2c00

    efd::SmartPointer<NiRenderedTexture> m_b8;
    efd::SmartPointer<NiRenderedTexture> m_c0;
};
MS2_CHECK_SIZE(OutlineRenderStep, 0xc8);
