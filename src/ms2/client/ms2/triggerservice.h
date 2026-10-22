// CTriggerService (RTTI name): efd system service (class id 0x06100015) of the client side of the cube-trigger system.
// It keeps the trigger world objects (TriggerObject, created for every entity whose FlatModel contains the trigger
// model 0xe8dd99d, keyed by the trigger id property 0x6c37a861) and executes the trigger events the server sends:
// the dispatcher FUN_141861840 reads a type byte from the event and forwards to the handler of that type (objects,
// camera, UI popups, emotion, ...). It is also an IWorldServiceCallback (slot 3 drops the objects on a map change).
// Member and helper names are invented from their use.
// Owning unit: ?\triggerservice.cpp (0x141860e60-0x141868af0, .text$di 0x14010e910-0x14010eca0; dir client\ms2).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>
#include <vector>
#include <efd/ISystemService.h>
#include <efd/Category.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/iworldservicecallback.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/client/ms2/triggeractioncli.h"

namespace efd { class MessageService; class IMessage; }
namespace egf { class EntityChangeMessage; class Entity; }
class CByteBuffer;

class CTriggerService;
template <class T> class TSingleton;
template <> class TSingleton<CTriggerService>
{
public:
    TSingleton();                                   // 0x141864920 (inline, below)
    virtual ~TSingleton() { s_instance = 0; }       // 0x141864d70
    static CTriggerService* s_instance;             // 0x143ab9510
};

// One queued camera step (AddTail 0x141865180): trigger object id and whether the step starts (nonzero) or ends it.
struct Unk_TrigCamStep
{
    Unk_TrigCamStep() = default;                                                        // trivial (filled field by field)
    Unk_TrigCamStep(int nObject, int bStart) : m_nObject(nObject), m_bStart(bStart) {}   // 0x141864a40
    int m_nObject;
    int m_bStart;
};

// An effect handle; a look-alike of int so that the CRBMap instance of this unit does not share a COMDAT with the
// CRBMap<int, int> of worldservice.cpp (the exe has a separate copy in each).
struct Unk_TrigHandle
{
    Unk_TrigHandle() : m_n(0) {}
    Unk_TrigHandle(int n) : m_n(n) {}
    operator int() const { return m_n; }
    int m_n;
};
// The exe's map passes the handle by value like an int (CNode 0x1418649a0 -> CPair(int, int) 0x141864a40).
namespace ATL {
template <> class CElementTraits<Unk_TrigHandle> : public CPrimitiveElementTraits<Unk_TrigHandle> {};
}

class CTriggerService : public efd::ISystemService, public IWorldServiceCallback, public TSingleton<CTriggerService>
{
    EE_DECLARE_CLASS1(CTriggerService, 0x06100015, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CTriggerService();                              // 0x141860e60
    virtual ~CTriggerService();                     // 0x141860f50
    virtual const char* GetDisplayName() const;     // 0x141861000
    virtual void vfunc_3(int nMap);                 // 0x141861020 (IWorldServiceCallback slot 3: map left)
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x1418610d0
    virtual efd::AsyncResult OnInit();              // 0x141861110
    virtual efd::AsyncResult OnTick();              // 0x1418613f0
    virtual efd::AsyncResult OnShutdown();          // 0x141861410

    // EntityChangeMessage handlers (EE_HANDLER_WRAP ids 8253 / 8254 = entity added / removed)
    void FUN_141861620(const egf::EntityChangeMessage* pMsg, efd::Category cat);
    void FUN_141861760(const egf::EntityChangeMessage* pMsg, efd::Category cat);
    void FUN_141861810(const efd::IMessage* pMsg, efd::Category cat);

    // trigger event dispatcher and the per-type handlers (the event is the received CInPacket)
    void FUN_141861840(CInPacket* pEvent);
    void FUN_141861a50(CInPacket* pEvent);   // type 2: n objects
    void FUN_141861ad0(CInPacket* pEvent);   // type 3: one object
    void FUN_141861b00(CInPacket* pEvent);   // type 5: camera step list
    void FUN_141861c20(CInPacket* pEvent);   // type 6: look-at-centre camera
    void FUN_141861f30(CInPacket* pEvent);   // type 7: camera fade off
    void FUN_141861f60(CInPacket* pEvent);   // camera fade on
    void FUN_141861fc0(CInPacket* pEvent);   // type 0xc: show a text file
    void FUN_141862110(CInPacket* pEvent);   // type 0xf: UI popups
    void FUN_1418627c0(CInPacket* pEvent);   // type 9: sub-dispatcher (player/UI actions)
    void FUN_141862930(CInPacket* pEvent);   // type 0x16
    void FUN_1418629b0(CInPacket* pEvent);   // type 0x13: side popup talk
    void FUN_141862d30(CInPacket* pEvent);   // type 0x14: set the state of named UI objects
    void FUN_141862ec0(CInPacket* pEvent);   // type 0x15
    void FUN_141862ff0(int nType, CInPacket* pEvent);    // types 0x17-0x19
    void FUN_141863030(CInPacket* pEvent);   // type 9 sub 0xc: typing game dialog
    bool FUN_141863100(int nObject, Vector3 pt);        // is the point inside the object
    void FUN_1418631a0();
    void FUN_1418631c0();                           // clear the camera step list
    void FUN_1418631f0(int nObject, int bStart);    // queue a camera step
    void FUN_141863260();                           // run the next camera step
    void FUN_141863340(const ATL::CAtlArray<int>& aObjects, int bEnd);
    void FUN_141863460(float fFade);
    void FUN_141863630(int nId, char bAdd, CStringA strName);
    bool FUN_1418637a0(const unsigned& rModel, std::vector<int>& rIds);
    bool FUN_1418638d0(egf::Entity* pEntity);   // is the entity inside a mesh trigger object
    void FUN_141863a90(CInPacket* pEvent, bool bSkipFx);
    void FUN_141863b70(CInPacket* pEvent);
    void FUN_141863c50(CInPacket* pEvent);
    void FUN_141863cc0(CInPacket* pEvent);
    void FUN_141863d80(CInPacket* pEvent);
    void FUN_141863df0(CInPacket* pEvent);
    void FUN_141863e50(CInPacket* pEvent);
    void FUN_141864010(CInPacket* pEvent);
    void FUN_1418641e0(CInPacket* pEvent);
    void FUN_1418642e0(CInPacket* pEvent);
    void FUN_1418643c0(CInPacket* pEvent);

    efd::Category m_catGlobal;                                      // +0x30 the message service's unique category
    ATL::CRBMap<int, MS2Ptr<TriggerObject> > m_mapObjects;          // +0x38 trigger id -> world object
    ATL::CRBMap<int, Unk_TrigHandle> m_mapHandles;                             // +0x68 trigger id -> effect handle
    ATL::CAtlList<Unk_TrigCamStep> m_listCamera;                    // +0x98 queued camera steps
};
MS2_CHECK_SIZE(CTriggerService, 0xc8);
MS2_CHECK_OFFSET(CTriggerService, m_catGlobal, 0x30);
MS2_CHECK_OFFSET(CTriggerService, m_mapObjects, 0x38);
MS2_CHECK_OFFSET(CTriggerService, m_mapHandles, 0x68);
MS2_CHECK_OFFSET(CTriggerService, m_listCamera, 0x98);
