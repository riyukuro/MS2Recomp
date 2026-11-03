// WorldFadeOutRenderStep (RTTI name): fades the world out/in via the "FadeInOut" technique. 0xa8 bytes (PostProcessEffect + 1 helper).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/postprocesseffect.h"

class WorldFadeOutRenderStep : public PostProcessEffect {
public:
    WorldFadeOutRenderStep(unsigned __int64 a, unsigned int b);    // 0x1416bad00
    virtual ~WorldFadeOutRenderStep();                             // 0x1416bada0
    virtual const NiRTTI* GetRTTI() const;                         // 0x1416bb2b0
    virtual bool vfunc_13();                                       // 0x1416bb2d0
    virtual bool vfunc_14();                                       // 0x1416bb2c0
    virtual bool vfunc_15(unsigned int a, void* b);                // 0x1416bae20
    virtual void vfunc_19();                                       // 0x1416bb0a0

    static const NiRTTI ms_RTTI;                                   // 0x143ae5090

    efd::SmartPointer<NiRenderedTexture> m_a0;
};
MS2_CHECK_SIZE(WorldFadeOutRenderStep, 0xa8);
