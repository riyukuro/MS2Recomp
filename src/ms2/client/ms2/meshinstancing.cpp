// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\meshinstancing.cpp
// MS2-RANGE: 0x14147be60-0x14147e6e0 .text$mn
#define MS2_THIS_FILE
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "entityworldmanager.h"
#include "entityinstancing.h"
#include <NiInstancingUtilities.h>
#include <ecr/RenderService.h>
#include "hook/ms2hook.h"

EntityWorldManager* FUN_1409670f0();
NiAVObject* FUN_141b6efc0(egf::Entity*);
void FUN_14098c6e0(egf::Entity*, unsigned, const bool&);
void FUN_1408a20a0(egf::Entity*, unsigned, bool*);
efd::IBase* FUN_14098c5b0(void* framework);
extern char DAT_143b059e8;
efd::Point3* FUN_1413fa320(efd::Point3* ret, egf::Entity*);
void FUN_141568ac0(egf::Entity*, const efd::Point3*);
bool FUN_1413fa390(egf::Entity*);
void FUN_1413fa4c0(egf::Entity*);
void FUN_141567330(NiAVObject*, bool);
void FUN_141851f90(NiNode*, float fTime);   // seek the animations (exe: xorps xmm1)
void FUN_1410865e0(NiObjectNET*, const NiFixedString&, bool);
void FUN_1415690f0(NiMesh*);
extern NiFixedString DAT_143ae51d0;
extern int DAT_143ae2b34;
void* FUN_1403ed2d0();
bool FUN_141bc7b20(void*, const egf::EntityID&);
void FUN_141bc7100(void*, NiNode*);
void* FUN_1413ebb60();
void FUN_1414c0bb0(void*, egf::Entity*, NiNode*);
ecr::RenderService* FUN_1413f9890();
void* FUN_1409478c0();
bool FUN_140af0aa0(void* cam, const NiPoint3& center, float radius);
bool FUN_1413d3370(const Unk_MeshInstancingConfig&, const Unk_MeshInstancingConfig&);
bool FUN_1413d33c0(const Unk_MeshInstancingConfig&, const Unk_MeshInstancingConfig&);
void FUN_14147dae0(NiNode*, bool);
egf::Entity* FUN_1408a9090(const void* smartPointer);
const efd::utf8string& FUN_14112e120(egf::Entity*);
void* FUN_1409a0f10(void* out, const efd::utf8string& name, void* a, void* b, unsigned flags);

// @0x14147be60
MeshInstancing::MeshInstancing(const Unk_MeshInstancingConfig& cfg, int m)
    : source(NULL), flag26(false), flag27(false), flag28(false), ready(false), flag2a(false), flag2b(false),
      root(NULL), config(cfg), mode(m) {}
// @0x14147bf70
MeshInstancing::~MeshInstancing() { vfunc_1(); }
// @0x14147c010
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
void MeshInstancing::FUN_14147c010(egf::Entity* entity, unsigned cap, unsigned count, NiTransform* transform, bool) {
    if (!ready) {
        flag28 = false;
        id10 = entity->GetEntityID();
        unknown24 = false;
        flag26 = false;
        FUN_1408a20a0(entity, 0x2a7fd9f4, &flag2a);
        FUN_1408a20a0(entity, 0xd9f313f2, &flag26);
        FUN_1408a20a0(entity, 0x861681cb, &flag28);
        efd::SmartPointer<efd::IBase> guard(FUN_14098c5b0(&DAT_143b059e8));
        capacity = cap;
        flag27 = entity->GetModel()->ContainsModel(0xd8dea70d);
        NiTransform identity;
        identity.MakeIdentity();
        NiNode* node = NiNew NiNode(0);
        root = node;
        root->GrowChildArray(cap);
        root->SetLocalTransform(identity);
        egf::EntityID created = FUN_1409670f0()->FUN_1411ce760(FUN_14112e120(entity), config.asset, false);
        id18 = created;
        source = FUN_1409670f0()->FUN_1411cf440(id18);
        efd::Point3 tint;
        FUN_141568ac0(source, FUN_1413fa320(&tint, entity));
        FUN_14098c6e0((egf::Entity*)source, 0x2a7fd9f4, flag2a);
        FUN_14098c6e0((egf::Entity*)source, 0xd89e9b12, config.flags30);
        FUN_14098c6e0((egf::Entity*)source, 0x90d6d437, config.flags31);
        NiAVObject* scene = FUN_141b6efc0(source);
        flag2b = FUN_1413fa390(entity);
        if (scene != NULL) {
            EntityHelper::SceneGraphMeshFunctor<NiMesh> collect(meshes);
            EntityHelper::Traverse(scene, collect);
            for (efd::vector<NiMesh*>::iterator end = meshes.end(), it = meshes.begin(); it != end; ++it) {
        NiMesh* mesh = *it;
                NiInstancingUtilities::EnableMeshInstancing(mesh, capacity, transform, count, 0x10000,
                    transform != NULL, false, false, NULL, 0, NiDataStreamElement::F_UINT32_1);
                if (flag2b) {
                    if (DAT_143ae2b34 == 0) FUN_1410865e0(mesh, DAT_143ae51d0, true);
                    else FUN_1415690f0(mesh);
                }
            }
        }
        ready = true;
    }
}
// @0x14147c600
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
void MeshInstancing::vfunc_1() {
    for (efd::vector<NiMesh*>::iterator end = meshes.end(), it = meshes.begin(); it != end; ++it) {
        NiMesh* mesh = *it;
        NiInstancingUtilities::DisableMeshInstancing(mesh);
    }
    if (FUN_1408a9090(&source) != NULL) {
        FUN_1409670f0()->FUN_1411cf570(source);
        source = NULL;
    }
    entries.clear();
    capacity = 0;
    root = NULL;
    meshes.clear();
}
// @0x14147c730
void MeshInstancing::FUN_14147c730(double dt) {
    if (!unknown24 && root && (flag26 || dirty)) {
        if (FUN_140af0aa0(FUN_1409478c0(), root->GetWorldBound().GetCenter(), root->GetWorldBound().GetRadius()))
            FUN_14147c910(dt);
    }
}
MS2_REPLACE_METHOD(0x14147c730, MeshInstancing, FUN_14147c730, 244, 0x6D8D9B6A);
// @0x14147c830
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
void MeshInstancing::FUN_14147c830() {
    if ((NiNode*)root != NULL) {
        NiNode* node = root;
        FUN_14147dae0(node, true);
        FUN_141851f90((NiNode*)root, 0.0f);
        root->UpdateEffects();
        root->UpdateProperties();
        root->Update(0.0f, true);
    }
    if (flag28) FUN_1413fa4c0(source);
}
// @0x14147c910
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
void MeshInstancing::FUN_14147c910(double dt) {
    if (flag26 || dirty) root->Update((float)dt, true);
    if (dirty) {
        for (efd::vector<NiMesh*>::iterator end = meshes.end(), it = meshes.begin(); it != end; ++it) {
        NiMesh* mesh = *it;
            mesh->Update((float)dt, true);
        }
        dirty = false;
    }
}
// @0x14147ca20
void MeshInstancing::FUN_14147ca20(bool enabled) {
    if (FUN_1408a9090(&source)) {
        FUN_14098c6e0((egf::Entity*)source, 0xa0b6b179, enabled);
        unknown24 = !enabled;
    }
}
MS2_REPLACE_METHOD(0x14147ca20, MeshInstancing, FUN_14147ca20, 115, 0xCDBED009);
// @0x14147caa0
void MeshInstancing::FUN_14147caa0() {
    ecr::RenderService* renderer = FUN_1413f9890();
    for (std::map<egf::EntityID, Unk_MeshInstanceEntry>::iterator it = entries.begin(); it != entries.end(); ++it) {
        egf::Entity* entity = it->second.entity;
        if (entity != NULL) {
            FUN_14098c6e0(entity, 0xa0b6b179, false);
            if (!FUN_141bc7b20(FUN_1403ed2d0(), it->first)) renderer->RemoveRenderedEntity(entity, it->second.original);
        }
    }
}
// @0x14147cbc0
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
void MeshInstancing::FUN_14147cbc0() {
    ecr::RenderService* renderer = FUN_1413f9890();
    for (std::map<egf::EntityID, Unk_MeshInstanceEntry>::iterator it = entries.begin(); it != entries.end(); ++it) {
        egf::Entity* entity = it->second.entity;
        if (entity != NULL) {
            FUN_14098c6e0(entity, 0xa0b6b179, false);
            FUN_14098c6e0(entity, 0x2a7fd9f4, true);
            if (!FUN_141bc7b20(FUN_1403ed2d0(), entity->GetEntityID()))
                renderer->RemoveRenderedEntity(entity, it->second.original);
        }
    }
}
// @0x14147ccf0
void MeshInstancing::FUN_14147ccf0() {
    for (std::map<egf::EntityID, Unk_MeshInstanceEntry>::iterator it = entries.begin(); it != entries.end(); ++it) {
        egf::Entity* entity = it->second.entity;
        if (entity != NULL) {
            if (!FUN_141bc7b20(FUN_1403ed2d0(), it->first)) FUN_1414c0bb0(FUN_1413ebb60(), entity, it->second.original);
        }
    }
}
MS2_REPLACE_METHOD(0x14147ccf0, MeshInstancing, FUN_14147ccf0, 226, 0x553DF4FC);
// @0x14147cde0
bool MeshInstancing::FUN_14147cde0(egf::EntityID id) {
    for (std::list<egf::EntityID>::iterator it = config.ids.m_list.begin(); it != config.ids.m_list.end(); ++it) {
        if (*it == id) return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x14147cde0, MeshInstancing, FUN_14147cde0, 133, 0x2F0348E7);
// @0x14147ce70
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
NiMesh* MeshInstancing::FUN_14147ce70(const NiFixedString& name) {
    for (efd::vector<NiMesh*>::iterator end = meshes.end(), it = meshes.begin(); it != end; ++it) {
        NiMesh* mesh = *it;
        if (mesh->GetName() == name) return mesh;
    }
    return NULL;
}
// @0x14147cf40
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
unsigned MeshInstancing::FUN_14147cf40() {
    return meshes.empty() ? 0 : NiInstancingUtilities::GetVisibleInstanceCount(meshes[0]);
}
// @0x14147cf90
int MeshInstancing::FUN_14147cf90(const Unk_MeshInstancingConfig& other) { return FUN_1413d3370(config, other); }
// @0x14147cfd0
int MeshInstancing::FUN_14147cfd0(const Unk_MeshInstancingConfig& other) { return FUN_1413d33c0(config, other); }
// @0x14147d010
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
bool MeshInstancing::FUN_14147d010(egf::Entity* entity) {
    if (entity != NULL) {
        std::map<egf::EntityID, Unk_MeshInstanceEntry>::iterator it = entries.find(entity->GetEntityID());
        if (it != entries.end()) return !((NiNode*)it->second.clone == NULL);
    }
    return false;
}
MS2_REPLACE_METHOD(0x14147cfd0, MeshInstancing, FUN_14147cfd0, 44, 0x02E3B8F4);
MS2_REPLACE_METHOD(0x14147cf90, MeshInstancing, FUN_14147cf90, 44, 0xBBAC2F44);
// @0x14147d0c0
// MS2-FUNCTIONAL: exe tests the SmartPointer via a bool temp; FUN_1408a9090 (symbol-table conflict) yields a plain test
void MeshInstancing::FUN_14147d0c0(bool enabled) {
    if (FUN_1408a9090(&source)) {
        if (!config.flags30) enabled = false;
        FUN_14098c6e0((egf::Entity*)source, 0xd89e9b12, enabled);
        NiAVObject* object = FUN_141b6efc0(source);
        if (object != NULL) {
            FUN_141567330(object, enabled);
            object->UpdateEffects();
            object->UpdateProperties();
            object->Update(0.0f, true);
        }
    }
}
// @0x14147d180
void MeshInstancing::FUN_14147d180(bool value) {
    if ((bool)(FUN_1408a9090(&source)))
    {
        if (config.flags31)
            FUN_14098c6e0((egf::Entity*)source, 0x90d6d437, value);
    }
}
// @0x14147d200
NiNode* MeshInstancing::FUN_14147d200(egf::Entity* entity) {
    if (entity != NULL) {
        std::map<egf::EntityID, Unk_MeshInstanceEntry>::iterator it = entries.find(entity->GetEntityID());
        if (it != entries.end()) return it->second.clone;
    }
    return NULL;
}
MS2_REPLACE_METHOD(0x14147d200, MeshInstancing, FUN_14147d200, 132, 0x3AF20654);
// @0x14147d290
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
void MeshInstancing::FUN_14147d290() {
    NiAVObject* object = FUN_141b6efc0(source);
    NiNode* node = NiDynamicCast(NiNode, object);
    FUN_141bc7100(FUN_1403ed2d0(), node);
}
// @0x14147d2f0
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
void* MeshInstancing::FUN_14147d2f0(void* out, void* a, void* b) {
    unsigned flags = 0;
    FUN_1409a0f10(out, FUN_14112e120(source), a, b, flags);
    return out;
}
// @0x14147d4b0
Unk_MeshInstancingConfig::Unk_MeshInstancingConfig(const Unk_MeshInstancingConfig& other)
    : asset(other.asset), flags30(other.flags30), flags31(other.flags31), flags32(other.flags32), ids(other.ids),
      unknown48(other.unknown48), unknown58(other.unknown58), unknown64(other.unknown64),
      activeCount(other.activeCount) {}
// Protected member access for the child array (the exe reads it inline at +0xe8).
struct Unk_NiNodeChildren : NiNode {
    static NiTObjectArray<NiAVObjectPtr>& Get(NiNode* node) { return node->*(&Unk_NiNodeChildren::m_kChildren); }
};
// @0x14147dae0
// MS2-FUNCTIONAL: codegen shape differs (frame/temp layout) from exe; behaviour equivalent
void FUN_14147dae0(NiNode* node, bool recursive) {
    NiTObjectArray<NiAVObjectPtr>& children = Unk_NiNodeChildren::Get(node);
    children.Compact();
    children.UpdateSize();
    if (recursive) {
        for (unsigned i = 0; i < children.GetSize(); ++i) {
            NiNode* child = NiDynamicCast(NiNode, children.GetAt(i));
            if (child != NULL) FUN_14147dae0(child, recursive);
        }
    }
}
