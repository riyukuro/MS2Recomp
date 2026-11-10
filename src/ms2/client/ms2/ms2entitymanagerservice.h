#pragma once
#include <egf/EntityManager.h>
#include <efd/AssetID.h>
#include "ms2/ms2layout.h"
class MS2EntityManagerService : public egf::EntityManager {
public:
    MS2EntityManagerService();
    virtual ~MS2EntityManagerService();
    egf::EntityID CreateEntity(const efd::utf8string&,efd::AssetID&,bool);
    virtual void SendEntityUpdateNotification(egf::Entity*);
    bool IsEntityDirty(const egf::Entity*);
};
MS2_CHECK_SIZE(MS2EntityManagerService,0x1b0);
