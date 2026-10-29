#pragma once
#include <list>
#include <map>
#include <vector>
#include <NiNode.h>
#include <efd/AssetID.h>
#include <NiMesh.h>
#include <NiMeshHWInstance.h>
#include <egf/Entity.h>
#include "ms2/ms2layout.h"

MS2_CHECK_SIZE(NiMeshHWInstance, 0xf8);

// The grid cell of an instanced entity: its position property 0xfd95ca52 divided by the cell size of the map (the
// methods are in ?\hardwareinstancingservice.cpp).
struct Unk_InstancingCell {
    Unk_InstancingCell(egf::Entity* pEntity, int nSize);                // 0x1413d37f0
    Unk_InstancingCell& operator=(const Unk_InstancingCell& other);     // 0x1413d38c0
    bool operator==(const Unk_InstancingCell& other) const;             // 0x1413d3920
    bool operator!=(const Unk_InstancingCell& other) const;             // 0x1413d3990
    bool operator>=(const Unk_InstancingCell& other) const;             // 0x1413d39e0
    int x, y, z;
    int size;
};
MS2_CHECK_SIZE(Unk_InstancingCell, 0x10);
// The scale triple of an instanced entity (property 0x213f5f94, default 180).
struct Unk_InstancingScale { Unk_InstancingScale(float x, float y, float z); float x, y, z; };   // ctor 0x1406c4340
// The entity ids an instancing covers; compared as sets (methods in ?\hardwareinstancingservice.cpp).
class Unk_InstanceIdList {
public:
    Unk_InstanceIdList();                                               // 0x1413d34b0
    ~Unk_InstanceIdList();                                              // 0x1413d34d0
    Unk_InstanceIdList& operator=(const Unk_InstanceIdList& other);     // 0x1413d34f0
    bool operator==(const Unk_InstanceIdList& other) const;             // 0x1413d3520
    bool operator!=(const Unk_InstanceIdList& other) const;             // 0x1413d3650
    bool operator<(const Unk_InstanceIdList& other) const;              // 0x1413d36a0
    std::list<egf::EntityID> m_list;
};
MS2_CHECK_SIZE(Unk_InstanceIdList, 0x10);
// Heap-only configuration view, copied by 14147d4b0; trailing count at +0x68.
struct Unk_MeshInstancingConfig {
    Unk_MeshInstancingConfig(egf::Entity* pEntity, int nCellSize, int nId);   // 0x1413d3000
    Unk_MeshInstancingConfig(const Unk_MeshInstancingConfig&);  // 0x14147d4b0
    ~Unk_MeshInstancingConfig();                                // 0x1413d3250
    Unk_MeshInstancingConfig& operator=(const Unk_MeshInstancingConfig& other);   // 0x1413d3290
    bool operator==(const Unk_MeshInstancingConfig& other) const;               // 0x1413d3370
    bool FUN_1413d33c0(const Unk_MeshInstancingConfig& other) const;            // the fields after the asset
    void FUN_1413eb720();                                       // ++activeCount
    efd::AssetID asset;
    bool flags30, flags31, flags32;
    unsigned unknown34;
    Unk_InstanceIdList ids;
    Unk_InstancingCell unknown48;
    Unk_InstancingScale unknown58;
    unsigned unknown64;
    int activeCount;
};
MS2_CHECK_SIZE(Unk_MeshInstancingConfig, 0x70);
struct Unk_MeshInstanceEntry {
    Unk_MeshInstanceEntry() : entity(NULL), clone(NULL), original(NULL) {}   // 0x141196260
    egf::Entity* entity;
    NiPointer<NiNode> clone;
    NiPointer<NiNode> original;
    efd::vector<NiPointer<NiMeshHWInstance>> instances;
};
MS2_CHECK_SIZE(Unk_MeshInstanceEntry, 0x30);

// Constructor 14147be60, destructor 14147bf70. The constructor's last field
// is the mode at +0xd0; EntityInstancing begins its own list at +0xd8.
class MeshInstancing {
public:
    MeshInstancing(const Unk_MeshInstancingConfig&, int);
    virtual ~MeshInstancing();
    virtual void vfunc_1();
    void FUN_14147c010(egf::Entity*, unsigned, unsigned, NiTransform*, bool);
    void FUN_14147c730(double);
    void FUN_14147c830();
    void FUN_14147c910(double);
    void FUN_14147ca20(bool);
    void FUN_14147caa0();
    void FUN_14147cbc0();
    void FUN_14147ccf0();
    bool FUN_14147cde0(egf::EntityID id);       // by value: callers copy the id
    NiMesh* FUN_14147ce70(const NiFixedString&);
    unsigned FUN_14147cf40();
    int FUN_14147cf90(const Unk_MeshInstancingConfig&);
    int FUN_14147cfd0(const Unk_MeshInstancingConfig&);
    int FUN_14147d010(egf::Entity*);
    void FUN_14147d0c0(bool);
    void FUN_14147d180(bool);
    NiNode* FUN_14147d200(egf::Entity*);
    void FUN_14147d290();
    // Accessors emitted in ?\hardwareinstancingservice.cpp's COMDAT run (0x1413eb740-0x1413ed300).
    int FUN_140ad4bb0() const;                  // mode
    void FUN_1413eb740();                       // ++config.activeCount
    egf::EntityID FUN_1413ebb00() const;        // id18
    unsigned FUN_1413ebb30() const;             // config.activeCount
    NiNode* FUN_1413ebb70() const;              // root
    unsigned FUN_1413ebb90() const;             // capacity
    bool FUN_1413ec820() const;                 // !config.ids.empty()
    bool FUN_1413ec890() const;                 // flag28
    void FUN_1413ed2f0();                       // dirty = true
    void FUN_1413ed300(int nCount);             // config.activeCount = nCount
    efd::utf8string FUN_14147d2f0();            // the source entity's model name
    efd::SmartPointer<egf::Entity> source;
    egf::EntityID id10, id18;
    unsigned capacity;
    bool unknown24, dirty, flag26, flag27, flag28, ready, flag2a, flag2b;
    NiPointer<NiNode> root;
    Unk_MeshInstancingConfig config;
    efd::vector<NiMesh*> meshes;
    std::map<egf::EntityID, Unk_MeshInstanceEntry> entries;
    int mode;
};
MS2_CHECK_SIZE(MeshInstancing, 0xd8);
MS2_CHECK_OFFSET(MeshInstancing, dirty, 0x25);
MS2_CHECK_OFFSET(MeshInstancing, root, 0x30);
MS2_CHECK_OFFSET(MeshInstancing, config, 0x38);
MS2_CHECK_OFFSET(MeshInstancing, meshes, 0xa8);
MS2_CHECK_OFFSET(MeshInstancing, entries, 0xc0);
