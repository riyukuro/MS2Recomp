// bgtransparencymgr.h - BGTransparencyMgr: fades background objects (props / walls between camera and player) by
// toggling their transparency. A TSingleton that is also an IWorldServiceCallback (slot 3 clears the tracked
// objects). Layout proved by the constructor 0x140a0cd30 and the allocation (0x98) in FUN_141498f10.
// Also holds TransparencyElement (the per-entity fade state, 0x60 bytes). The containers are the efd ones
// (efd::CustomAllocator: the node/array allocations go through efd::_Malloc/_Free): efd::map for the fading entities
// (ctor 0x140a15d30 wraps the std::map ctor 0x140a15d50), efd::set for the hit set of the scan (0x140a15d80),
// efd::vector for the pick and sort lists (allocate 0x140a1d300 takes a MemHint). TransparencyElement::m_materials is a plain std::list (std::allocator:
// _Deallocate of 0x18-byte nodes, max_size SIZE_MAX/24).
#pragma once
#include <list>
#include <map>
#include <set>
#include <vector>
#include <efd/SmartPointer.h>
#include <efd/IBase.h>
#include <efd/customalloc.h>
#include <efd/StdContainers.h>
#include <egf/Entity.h>
#include <egf/EntityID.h>
#include <ecr/PickService.h>
#include <ecr/SceneGraphService.h>
#include <NiRefObject.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/placeholder/transparencymaterial.h"

class NiAVObject;
class NiNode;

// Per-entity fade state (vftable 0x142dc3ac0, ctor 0x140a15fe0, dtor 0x140a166f0). m_fAlpha is the entity's
// target alpha (property 0x188f01c1, default 0.3).
class TransparencyElement : public NiRefObject
{
public:
    TransparencyElement();                                          // 0x140a15fe0
    // implicit virtual dtor 0x140a166f0 (stores no vptr; deleting 0x140a17880)

    std::list<TransparencyStandardMaterial*> m_materials;   // 0x10
    Timer m_timer;                                                  // 0x20
    float m_fAlpha;                                                 // 0x58
};
MS2_CHECK_SIZE(TransparencyElement, 0x60);
MS2_CHECK_OFFSET(TransparencyElement, m_materials, 0x10);
MS2_CHECK_OFFSET(TransparencyElement, m_timer, 0x20);
MS2_CHECK_OFFSET(TransparencyElement, m_fAlpha, 0x58);

// A tracked scene-graph entity as WorldService::FUN_141bc7920 collects it (same layout as Unk_WsV1d8).
struct Unk_BGTRegion
{
    NiAVObject* m_pNode;                                            // +0x00 scene node
    int m_nKind;                                                    // +0x08 0: always, 1: only with the world flag
    int m_pad_0c;
    egf::EntityID m_id;                                             // +0x10
    int m_nGroup;                                                   // +0x18 key of the linked-entity groups (> 0)
    int m_pad_1c;
    bool operator<(const Unk_BGTRegion& o) const { return m_id < o.m_id; }
};
MS2_CHECK_SIZE(Unk_BGTRegion, 0x20);

typedef efd::SmartPointer<egf::Entity> Unk_BGTEntityPtr;
typedef efd::map<Unk_BGTEntityPtr, TransparencyElement*> Unk_BGTElementMap;
typedef efd::set<egf::Entity*> Unk_BGTEntitySet;
typedef efd::vector<egf::Entity*> Unk_BGTEntityList;

class BGTransparencyMgr;
template <class T> class TSingleton;
template <> class TSingleton<BGTransparencyMgr>
{
public:
    TSingleton();                                   // 0x140a15390 (inline, below)
    virtual ~TSingleton() { s_instance = 0; }       // 0x140a17780
    static BGTransparencyMgr* s_instance;
    static BGTransparencyMgr* GetInstance();            // 0x14123ee80
};

class BGTransparencyMgr : public TSingleton<BGTransparencyMgr>, public IWorldServiceCallback
{
public:
    BGTransparencyMgr();                            // 0x140a0cd30
    virtual ~BGTransparencyMgr();                   // 0x140a17800 (deleting) / 0x140a0ce30
    virtual void vfunc_1();                         // 0x140a0db00 scan: pick the objects hiding the players
    virtual void vfunc_3(int);                      // 0x140a0d230 (IWorldServiceCallback slot 3: world torn down)

    int Init();                                     // 0x140a0cee0 register with the world, grab the services
    void Shutdown();                                // 0x140a0cf90
    void Tick();                                    // 0x140a0d000 per frame: fade, rescan every 300 ms
    void SetUserFlags(int nFlags);                  // 0x140a0d0c0
    void AddObject(GameObject* pObject);            // 0x140a0d130
    void RemoveObject(GameObject* pObject);         // 0x140a0d190
    void EraseEntity(egf::Entity* pEntity);         // 0x140a0d450 forget a destroyed entity
    bool IsTarget(egf::Entity* pEntity);            // 0x140a0d670 may this entity be faded
    bool RayHits(efd::Point3 ptOrigin, efd::Point3 ptDir, NiAVObject* pNode);   // 0x140a0d7a0
    bool PickEntities(efd::Point3 ptOrigin, efd::Point3 ptDir, Unk_BGTEntityList& kOut, egf::Entity* pSkip);   // 0x140a0d880
    void Apply(Unk_BGTEntitySet& kHit);       // 0x140a0e330 start fading the entities in kHit
    void SortEntities();                            // 0x140a0e860 tag the faded meshes with their camera-distance rank
    void UpdateFadeOut();                           // 0x140a0ebf0
    void UpdateFadeIn();                            // 0x140a0ed80
    void ReleaseMaterials(egf::Entity* pEntity, TransparencyElement* pElement);   // 0x140a0f020
    void MoveAllToFadeIn();                         // 0x140a0f200
    void MoveMissingToFadeIn(Unk_BGTEntitySet& kHit);   // 0x140a0f2d0
    void DeleteMaterials(TransparencyElement* pElement);   // 0x140a0f140 (member: rcx = this, rdx = pElement)
    static bool CompareDistance(egf::Entity* pA, egf::Entity* pB);   // 0x140a0f460 farther first

    efd::SmartPointer<ecr::PickService> m_spService;                // 0x10
    efd::SmartPointer<ecr::SceneGraphService> m_spSceneGraph;       // 0x18
    std::set<efd::SmartPointer<GameObject> > m_set20;               // 0x20 the players that must stay visible
    Unk_BGTElementMap m_map30;                                      // 0x30 fading out
    Unk_BGTElementMap m_map40;                                      // 0x40 fading back in
    Timer m_timer;                                                  // 0x50
    int m_nFlags;                                                   // 0x88
    int m_nUserFlags;                                               // 0x8c
    int m_nWorldFlags;                                              // 0x90
};
MS2_CHECK_SIZE(BGTransparencyMgr, 0x98);
MS2_CHECK_OFFSET(BGTransparencyMgr, m_spService, 0x10);
MS2_CHECK_OFFSET(BGTransparencyMgr, m_set20, 0x20);
MS2_CHECK_OFFSET(BGTransparencyMgr, m_timer, 0x50);
MS2_CHECK_OFFSET(BGTransparencyMgr, m_nWorldFlags, 0x90);
