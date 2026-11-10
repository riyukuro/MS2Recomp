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
    void FUN_1413d78e0(egf::Entity* pEntity);   // refresh the entity's instancing
    int GetCellSize();                    // the grid instance count
    unsigned GetInstancingCount();               // the group instance count
    int FUN_1413d6890(egf::Entity* pEntity);    // is the entity excluded
    void ClearMap(unsigned nMap);          // unload a map
    int FUN_1413d7d90(const egf::EntityID& id);  // is the entity instanced
private:
    unsigned char unknown30[0x80];
};
MS2_CHECK_SIZE(HardwareInstancingService,0xb0);
