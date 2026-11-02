#pragma once
#include <list>
#include <algorithm>
#include "ms2/placeholder/meshinstancing.h"

namespace EntityHelper {
template<class T> class SceneGraphMeshFunctor {
public:
    explicit SceneGraphMeshFunctor(efd::vector<T*>& output) : meshes(output) {}
    virtual void vfunc_0(NiAVObject* object) {
        T* mesh = static_cast<T*>(NiObject::DynamicCast(&T::ms_RTTI, object));
        if (mesh != NULL) {
            if (meshes.find(mesh) == meshes.end()) meshes.push_back(mesh);
        }
    }
    efd::vector<T*>& meshes;
};
template<class Functor> void Traverse(NiAVObject* object, Functor& functor) {
    if (object == NULL) return;
    {
        if (object != NULL) functor.vfunc_0(object);
        if (object->IsNode()) {
            NiNode* node = static_cast<NiNode*>(object);
            unsigned count = node->GetArrayCount();
            for (unsigned i = 0; i < count; ++i) {
                NiAVObject* child = node->GetAt(i);
                Traverse(child, functor);
            }
        }
    }
}
}
class DetachAllPropertiesFunctor {
public:
    DetachAllPropertiesFunctor() {}
    virtual void vfunc_0(NiAVObject* object) { object->DetachAllProperties(); }
};
MS2_CHECK_SIZE(DetachAllPropertiesFunctor, 8);
MS2_CHECK_SIZE(EntityHelper::SceneGraphMeshFunctor<NiMesh>, 0x10);
MS2_CHECK_SIZE(EntityHelper::SceneGraphMeshFunctor<NiMeshHWInstance>, 0x10);

class EntityInstancing : public MeshInstancing {
public:
    EntityInstancing(const Unk_MeshInstancingConfig&);
    virtual ~EntityInstancing();
    void vfunc_1() override;
    bool FUN_1411c5880(egf::Entity*, unsigned);
    int FUN_1411c58d0(egf::Entity*);
    void FUN_1411c5e30(egf::Entity*, bool);
    void FUN_1411c5f40(egf::Entity*);
    void FUN_1411c6030(egf::Entity*);
    int FUN_1411c6390(egf::Entity*, bool);
    void FUN_1411c66e0();
    void FUN_1411c67f0(const egf::EntityID&);
    void FUN_1411c68d0();
    bool FUN_1411c6a50(egf::EntityID id);   // by value: the exe callers copy
    void FUN_1411c6ae0(unsigned);
    std::list<egf::EntityID> hidden;
};
MS2_CHECK_SIZE(EntityInstancing, 0xe8);
MS2_CHECK_OFFSET(EntityInstancing, hidden, 0xd8);
