// citemservice.h - PLACEHOLDER for CItemService (RTTI .?AVCItemService@@, 0x68 bytes). NOT an original header.
// Bases: efd::ISystemService at +0x0, TSingleton<CItemService> at +0x18. The client item efd system service (class id
// 0x0610000a): it builds the CEquipItem of an item (the KFM / NIF models of its model groups) and keeps the KFM models
// whose actor is loading, keyed by the model entity id, to finish them when the PhysX prop / actor-added messages come.
// Owning unit ?\itemservice.cpp (src/ms2/client/ms2/itemservice.cpp). Member names are invented from their use.
#pragma once

#include <atlcoll.h>
#include <efd/ISystemService.h>
#include <efd/ReferenceCounting.h>
#include <efd/Category.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class CEquipItem;
class CKfmModel;
class PC;
namespace efd { class MessageService; class AssetLoadResponse; }
namespace ecrPhysX { class PhysXPropMessage; }
namespace egmAnimation { class ActorAddedMessage; }

class CItemService : public efd::ISystemService, public TSingleton<CItemService>
{
    EE_DECLARE_CLASS1(CItemService, 0x0610000a, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CItemService();                                                 // 0x141419df0
    virtual ~CItemService();                                        // 0x141419ea0
    virtual const char* GetDisplayName() const;                     // 0x141419f30
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x14141b360
    virtual efd::AsyncResult OnInit();                              // 0x14141b3e0
    virtual efd::AsyncResult OnTick();                              // 0x14141b660
    virtual efd::AsyncResult OnShutdown();                          // 0x14141b680

    int FUN_141419f50(CKfmModel* pModel);                           // 0x141419f50 keep a loading KFM model (by entity id)
    int FUN_14141a000(CKfmModel* pModel);                           // 0x14141a000 forget it
    // 0x14141a060 create the equip item. nCache is a std::map<std::string, std::list<NiAVObjectPtr> >* of already
    // loaded NIF roots (by path) to take from, or 0 (equipment.cpp passes 0 or its own cache).
    MS2Ptr<CEquipItem> FUN_14141a060(CItem* pItem, PC* pPC, __int64 nCache);
    void FUN_14141ac60(const efd::AssetLoadResponse* pMsg, efd::Category cat);           // 0x14141ac60
    void FUN_14141acc0(const ecrPhysX::PhysXPropMessage* pMsg, efd::Category cat);       // 0x14141acc0
    void FUN_14141ae10(const egmAnimation::ActorAddedMessage* pMsg, efd::Category cat);  // 0x14141ae10
    int FUN_14141b000(CItem* pItem, PC* pPC);                       // 0x14141b000 every worn part is a KFM part
    void FUN_14141b250(CItem* pItem, PC* pPC, ATL::CAtlList<MS2Ptr<CEquipItem> >* pList);   // 0x14141b250 items it replaces

    efd::Category m_catGlobal;                                      // +0x28 the message service's unique category
    efd::SmartPointer<efd::MessageService> m_spMessages;            // +0x30
    ATL::CRBMap<unsigned __int64, MS2Ptr<CKfmModel> > m_mapModels;  // +0x38 entity id -> loading KFM model
};
MS2_CHECK_SIZE(CItemService, 0x68);
MS2_CHECK_OFFSET(CItemService, m_catGlobal, 0x28);
MS2_CHECK_OFFSET(CItemService, m_spMessages, 0x30);
MS2_CHECK_OFFSET(CItemService, m_mapModels, 0x38);
