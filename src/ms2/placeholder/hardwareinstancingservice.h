// Heap-only service view. Base offsets from1413d42a0; delete size0xb0 at1413eb610.
#pragma once
#include <efd/ISystemService.h>
#include <egf/IPropertyCallback.h>
#include <egf/EntityID.h>
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/ms2layout.h"
class HardwareInstancingService : public efd::ISystemService, public egf::IPropertyCallback, public IWorldServiceCallback {
public:
    virtual ~HardwareInstancingService();
    void FUN_1413d7d10(const egf::EntityID&);
    int FUN_1413d7e30();                    // the grid instance count
    unsigned FUN_1413d7eb0();               // the group instance count
private:
    unsigned char unknown30[0x80];
};
MS2_CHECK_SIZE(HardwareInstancingService,0xb0);
