// EntityWorldManager: RTTI bases +0/+0x18/+0x20; deleting destructor allocates 0x118.
#pragma once
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/commonfiles/os.h"
#include "ms2entityloaderservice.h"
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include <efd/MessageService.h>
#include <efd/AssetID.h>
#include <efd/Point3.h>
#include <egf/Entity.h>
#include <egf/EntityManager.h>
#include <egf/FlatModelManager.h>
#include <egf/BlockIdentification.h>
#include <egf/EntityChangeMessage.h>
#include <egf/Scheduler.h>
#include <egfPhysX/SceneService.h>
#include <ecrPhysX/PropService.h>
#include <ecr/SceneGraphService.h>
#include <ecr/RenderService.h>
#include <ecr/ShaderService.h>
#include <ecr/LightService.h>
#include <egmAnimation/AnimationService.h>
#include <map>
#include <set>
#include <list>

typedef std::map<egf::EntityID, egf::Entity*> Unk_WorldEntityMap;
struct Unk_EntityWorldRecord {
    Unk_EntityWorldRecord();
    bool unloaded;
    double time;
    egf::BlockIdentification block;
    Unk_WorldEntityMap allEntities;
    Unk_WorldEntityMap loadedEntities;
    Unk_WorldEntityMap createdEntities;
};
MS2_CHECK_SIZE(Unk_EntityWorldRecord, 0x78);
MS2_CHECK_OFFSET(Unk_EntityWorldRecord, time, 8);
MS2_CHECK_OFFSET(Unk_EntityWorldRecord, block, 0x10);
MS2_CHECK_OFFSET(Unk_EntityWorldRecord, allEntities, 0x48);
MS2_CHECK_OFFSET(Unk_EntityWorldRecord, loadedEntities, 0x58);
MS2_CHECK_OFFSET(Unk_EntityWorldRecord, createdEntities, 0x68);

// The exe instantiates GetSystemServiceAs/DynamicCast twice for CLASS_ID 0x07001008 (no ICF): once for
// egfPhysX::SceneService (FUN_1411cf630) and once for the type of the 'scenes' member (OnInit, 0xd8). The latter
// is modelled as a subclass that inherits CLASS_ID; it is never instantiated.
class Unk_PhysXSceneView : public egfPhysX::SceneService {};
class EntityWorldManager;
// Explicit specialization (as WorldService): the exe's constructor converts this to the EntityWorldManager
// base (this - 0x20, null-checked) before storing it in s_instance (0x143ab3910).
template <> class TSingleton<EntityWorldManager> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    // @0x1409670f0
    static EntityWorldManager* GetInstance() { return s_instance; }   // COMDAT in actionkeyobject.cpp's range
    static EntityWorldManager* s_instance;
};

class EntityWorldManager : public efd::ISystemService, public IWorldServiceCallback,
                           public TSingleton<EntityWorldManager> {
    EE_DECLARE_CLASS1(EntityWorldManager, 0x0610001a, efd::ISystemService);
    EE_DECLARE_CONCRETE_REFCOUNT;
public:
    EntityWorldManager();
    virtual ~EntityWorldManager();
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar*);
    virtual efd::AsyncResult OnInit();
    virtual efd::AsyncResult OnTick();
    virtual efd::AsyncResult OnShutdown();
    virtual const char* GetDisplayName() const;
    virtual void vfunc_1(int);
    virtual void vfunc_3(int);
    virtual void vfunc_4(int);
    Unk_WorldEntityMap::iterator FUN_1411ce4c0();
    bool FUN_1411ce510(Unk_WorldEntityMap::iterator&, egf::Entity*&);
    Unk_WorldEntityMap::iterator FUN_1411ce5a0();
    bool FUN_1411ce5f0(Unk_WorldEntityMap::iterator&, egf::Entity*&);
    Unk_WorldEntityMap::iterator FUN_1411ce680();
    bool FUN_1411ce6d0(Unk_WorldEntityMap::iterator&, egf::Entity*&);
    egf::EntityID FUN_1411ce760(const efd::utf8string&, efd::AssetID&, bool);
    egf::EntityPtr FUN_1411cec80(const efd::utf8string&, egf::EntityID, bool);
    egf::EntityPtr FUN_1411cedd0(egf::FlatModelID, egf::EntityID, bool);
    egf::EntityID FUN_1411cef50(const efd::utf8string&, const efd::Category&,
        efd::ParameterList*, efd::ParameterList*, egf::EntityID, bool);
    egf::EntityPtr FUN_1411ce7c0(efd::utf8string, efd::utf8string, efd::Point3, efd::Point3, float, int, int);
    bool FUN_1411cf0b0(efd::utf8string, efd::AssetID&, bool&);
    void FUN_1411cf2d0(egf::Entity*, efd::ParameterList*);
    egf::EntityPtr FUN_1411cf3d0(const egf::EntityID&);
    egf::Entity* FUN_1411cf440(const egf::EntityID&);
    void FUN_1411cf540(const egf::EntityID&);
    void FUN_1411cf570(egf::Entity*);
    void FUN_1411cf5a0(const egf::EntityID&, egf::Entity*);
    bool FUN_1411cf630(int, const egf::BlockIdentification&);
    void FUN_1411cf980(int, const egf::BlockIdentification&);
    bool FUN_1411cfb80(unsigned*, int*);
    int FUN_1411cfbe0();
    void FUN_1411cfce0();
    void FUN_1411cfd40(const egf::EntityChangeMessage*, efd::Category);
    void FUN_1411cffa0(const egf::EntityChangeMessage*, efd::Category);
    void FUN_1411d0a60(unsigned, int);
    size_t FUN_1411d0ab0();
    size_t FUN_1411d0af0();
    efd::UInt32 FUN_1411d0b30();
public:
    unsigned currentMap;
    std::map<unsigned, Unk_EntityWorldRecord> worlds;
    egf::BlockIdentification currentBlock;
    unsigned unknown78;
    bool loaded;
    double lastLoadTime;
    efd::SmartPointer<efd::MessageService> messages;
    efd::SmartPointer<egf::EntityManager> entities;
    efd::SmartPointer<MS2EntityLoaderService> loader;
    efd::SmartPointer<ecr::SceneGraphService> sceneGraphs;
    efd::SmartPointer<egf::FlatModelManager> models;
    std::map<unsigned, std::set<unsigned>> mapGroups;  // set<unsigned>: FUN_1411d0a60 calls the less<unsigned> insert 0x1403455f0
    unsigned __int64 unknownC0;
    std::list<efd::AssetID> unusedAssets;
    efd::SmartPointer<Unk_PhysXSceneView> scenes;
    efd::SmartPointer<ecrPhysX::PropService> props;
    efd::SmartPointer<egf::Scheduler> scheduler;
    efd::SmartPointer<ecr::RenderService> renderer;
    efd::SmartPointer<ecr::ShaderService> shaders;
    efd::SmartPointer<ecr::LightService> lights;
    efd::SmartPointer<egmAnimation::AnimationService> animation;
    efd::SmartPointer<efd::ServiceManager> services;
};
inline TSingleton<EntityWorldManager>::TSingleton() { s_instance = static_cast<EntityWorldManager*>(this); }
MS2_CHECK_SIZE(EntityWorldManager, 0x118);
MS2_CHECK_OFFSET(EntityWorldManager, currentMap, 0x2c);
MS2_CHECK_OFFSET(EntityWorldManager, worlds, 0x30);
MS2_CHECK_OFFSET(EntityWorldManager, currentBlock, 0x40);
MS2_CHECK_OFFSET(EntityWorldManager, loaded, 0x7c);
MS2_CHECK_OFFSET(EntityWorldManager, lastLoadTime, 0x80);
MS2_CHECK_OFFSET(EntityWorldManager, messages, 0x88);
MS2_CHECK_OFFSET(EntityWorldManager, loader, 0x98);
MS2_CHECK_OFFSET(EntityWorldManager, mapGroups, 0xb0);
MS2_CHECK_OFFSET(EntityWorldManager, unusedAssets, 0xc8);
MS2_CHECK_OFFSET(EntityWorldManager, services, 0x110);
