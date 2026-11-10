// dynamicinstancing.h - DynamicInstancing (vftable 0x142eb8f78): MeshInstancing that instances an entity's own scene
// graph without cloning it (mode 1). Header name assumed.
#pragma once
#include "ms2/placeholder/meshinstancing.h"

class DynamicInstancing : public MeshInstancing {
public:
    DynamicInstancing(const Unk_MeshInstancingConfig& config);          // 0x141194290
    virtual ~DynamicInstancing();                                       // 0x1411942e0
    bool AddEntity(egf::Entity*, unsigned, unsigned, NiTransform*); // 0x141194330
};
MS2_CHECK_SIZE(DynamicInstancing, 0xd8);
