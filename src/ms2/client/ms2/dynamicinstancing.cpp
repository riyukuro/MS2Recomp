// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\dynamicinstancing.cpp
// MS2-RANGE: 0x141194290-0x141197280 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#include "dynamicinstancing.h"
#include "hook/ms2hook.h"

NiAVObject* FUN_141b6efc0(egf::Entity*);

// @0x141194290
DynamicInstancing::DynamicInstancing(const Unk_MeshInstancingConfig& config) : MeshInstancing(config, 1) {}
// @0x1411942e0
DynamicInstancing::~DynamicInstancing() { vfunc_1(); }
// @0x141194330
bool DynamicInstancing::AddEntity(egf::Entity* entity, unsigned count, unsigned flags, NiTransform* transform) {
    NiAVObject* original = FUN_141b6efc0(entity);
    if (original != NULL) {
        Init(entity, count, flags, transform, false);
        entries[entity->GetEntityID()].entity = entity;
        entries[entity->GetEntityID()].clone = NULL;
        entries[entity->GetEntityID()].original = NiDynamicCast(NiNode, original);
        return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x141194330, DynamicInstancing, AddEntity, 256, 0x845091AC);
