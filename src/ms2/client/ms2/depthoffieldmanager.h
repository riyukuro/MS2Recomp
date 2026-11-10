// CDepthOfFieldManager: toggles the depth-of-field post effect (render-step slot 4) and its shader constants. 0x58 bytes.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/nirefobject.h"
#include "ms2/placeholder/timer.h"

class CDepthOfFieldManager : public NiRefObject {
public:
    CDepthOfFieldManager();                 // 0x141177ee0
    virtual ~CDepthOfFieldManager();        // 0x141177f50 (deleting dtor 0x141178250)

    void Initialize();                   // fetch the render step and apply the saved enable flag
    void SetEnabled(unsigned char on);   // enable / disable
    unsigned char IsEnabled();          // m_50
    void FUN_141178000(double dDelta);      // advance the focus fade (PostProcessingService::OnTick)

    void* m_10;                             // render step (slot 4)
    Timer m_18;
    unsigned char m_50;
};
MS2_CHECK_SIZE(CDepthOfFieldManager, 0x58);
