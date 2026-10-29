// SSAORenderStep (RTTI name): screen-space ambient occlusion post-process step. 0xc8 bytes, 24 vftable slots.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/postprocesseffect.h"

class SSAORenderStep : public ReloadablePostProcess {
public:
    SSAORenderStep(unsigned __int64 a, const NiFixedString& name, unsigned int b);   // 0x1416ba7f0
    virtual ~SSAORenderStep();                                  // 0x1416ba920
    virtual const NiRTTI* GetRTTI() const;                      // 0x1416bacf0
    virtual bool vfunc_15(unsigned int a, void* b);             // 0x1416ba980
    virtual void vfunc_16();                                    // 0x1416baab0
    virtual bool vfunc_23();                                    // 0x1416baaf0

    static const NiRTTI ms_RTTI;                                // 0x143ae5078

    Unk_PPSmartC m_b8;      // shader
    Unk_PPSmartA m_c0;
};
MS2_CHECK_SIZE(SSAORenderStep, 0xc8);
