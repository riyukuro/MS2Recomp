// worldservice_tail.h - the container types of WorldService as its COMDAT tail shows them (w530, 2026-10-20).
// NOT an original header. worldservice.h keeps per-member Unk_WsV<off> stand-ins (the methods in worldservice_1.cpp use
// them); the tail units (?\worldservice.cpp#6 ..) instantiate the containers over the key/value types recovered here, so
// that the COMDAT bodies (key compare traits, value copy/assign/dtor calls) are the exe's.
//
// Evidence, per family (exe VAs; the tail is sorted by mangled name, so each member function kind is one run of
// look-alikes, ordered by the instantiation's template arguments):
// - CRBTree families: InsertImpl (0x141c03e70 ..) -> CompareElementsOrdered (key type) and NewNode -> CNode ctor ->
//   CPair ctor (key + value copy ctors); Lookup(key, value&) (0x141c06fa0 ..) -> the value operator=.
// - CAtlMap families: GetNode (0x141bff390 ..) <- Lookup(key, value&) (0x141c06aa0 ..) -> the value operator=.
// Run order of the CRBTree families (int < unsigned < pointer < CStringA < EntityID < enum < unsigned __int64, then by
// value) matches the TPtr (MS2Ptr) / efd::SmartPointer spelling of the values below.
#pragma once                                    // needs NOMINMAX before ms2stdafx.h (interactobject.h -> NxPhysics.h)
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cproxygameobject.h"
#include "ms2/placeholder/cnpc.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/gameobject.h"
#include "ms2/client/ms2/portal.h"
#include "ms2/client/ms2/interactobject.h"
#include "ms2/client/ms2/liftableobject.h"
#include "ms2/client/ms2/liftabletarget.h"
#include "ms2/client/ms2/reactor.h"
#include "ms2/client/ms2/proxyobject.h"
#include <egf/Entity.h>
#include <egf/EntityID.h>

// Pointee classes first used by WorldService (their TPtr copy/assign/AddRef COMDATs are in this CU's tail); real names
// unknown.
class Unk_WsMarker : public CPtred {};      // F9/F12 value: copy ctor 0x141bf1330, assign 0x14167e950 (FUN_141bc4ca0/4e70/4f10)
class Unk_WsTargetF7 : public CPtred {};    // F7 value: copy ctor 0x141bf1900, assign 0x141bf7020 (FUN_141bd0220); sorts after PC
class Unk_WsMapV2 : public CPtred {};       // M2 value: dtor 0x141bf54a0 (no Lookup(key, value&) instance)
class Unk_WsMapV3 : public CPtred {};       // M3 value: assign 0x141bf6bc0
class Unk_WsMapV4 : public CPtred {};       // M4 value: assign 0x141bf6c70
class Unk_WsMapV6 : public CPtred {};       // M6 value: assign 0x141bf6e80
class Unk_WsMapV7 : public CPtred {};       // M7 value: assign 0x141bf6f60
class Unk_WsMapV9 : public CPtred {};       // M9 value: assign 0x14109a050 (shared with 0x14109a640's unit)
class Unk_WsMapV10 : public CPtred {};      // M10 value: assign 0x14123ecb0 (GameObject::vfunc_17 uses the same TPtr)
class Unk_WsMapV11 : public CPtred {};      // M11 value: assign 0x141bf6d20 (the vibrators, FUN_141c06ed0)
// M8 value: an efd::SmartPointer whose pointee has IncRefCount / DecRefCount at vftable slots 1 / 2 (assign 0x141bf69d0).
class Unk_WsMapV8
{
public:
    virtual void DeleteThis();
    virtual void IncRefCount();
    virtual void DecRefCount();
};
// F16 key: an enum whose CDefaultCompareTraits::CompareElementsOrdered (0x140ef0890) is first instantiated by
// ?\uiugccubepalettedialog.cpp (called CDefaultCompareTraits<int> there; <int> itself is 0x140212de0).
enum Unk_WsKindKey : int {};
// F3 value (m_1a8): the object and its entity id; copy ctor 0x141bf4860, operator= 0x141bf7180 (worldservice#5).
struct Unk_WsObjectEntry
{
    efd::SmartPointer<GameObject> m_obj;
    egf::EntityID m_id;
};

// CRBTree families, in exe order (InsertImpl VA).
typedef ATL::CRBMultiMap<int, MS2Ptr<CLiftableTargetBox> > Unk_WsF1;              // 0x141c03e70 m_540 (Insert 0x141c03e10)
typedef ATL::CRBMultiMap<int, MS2Ptr<CLiftableTargetGuide> > Unk_WsF2;            // 0x141c03f70 m_570 (Insert 0x141c03e40)
typedef ATL::CRBMap<unsigned, Unk_WsObjectEntry> Unk_WsF3;                        // 0x141c04070 m_1a8 (SetAt 0x141c1b490)
typedef ATL::CRBMap<unsigned, efd::SmartPointer<CNpc> > Unk_WsF4;                  // 0x141c04170 (copy 0x140a7b390)
typedef ATL::CRBMap<unsigned, efd::SmartPointer<GameObject> > Unk_WsF5;            // 0x141c04270 (copy 0x140a000a0)
typedef ATL::CRBMap<unsigned, efd::SmartPointer<PC> > Unk_WsF6;                    // 0x141c04370 (copy 0x140c20410)
typedef ATL::CRBMap<unsigned, MS2Ptr<Unk_WsTargetF7> > Unk_WsF7;                  // 0x141c04470
typedef ATL::CRBMap<egf::Entity*, egf::Entity*> Unk_WsF8;                          // 0x141c04570 m_6d8 (SetAt 0x141c1b6c0)
typedef ATL::CRBMap<egf::Entity*, MS2Ptr<Unk_WsMarker> > Unk_WsF9;                 // 0x141c04670 m_4e0 (FUN_141bc4f10)
typedef ATL::CRBMap<CStringA, efd::SmartPointer<CReactor> > Unk_WsF10;             // 0x141c04770 (copy 0x140963d50)
typedef ATL::CRBMap<CStringA, efd::SmartPointer<egf::Entity> > Unk_WsF11;          // 0x141c04870 (copy 0x1408a7ed0)
typedef ATL::CRBMap<CStringA, MS2Ptr<Unk_WsMarker> > Unk_WsF12;                    // 0x141c04970 (FUN_141bc4e70)
typedef ATL::CRBMap<CStringA, MS2Ptr<CInteractObject> > Unk_WsF13;                 // 0x141c04a70 (copy 0x140a7b410)
typedef ATL::CRBMap<CStringA, MS2Ptr<CLiftableObject> > Unk_WsF14;                 // 0x141c04b70 (FUN_141bc5a20)
typedef ATL::CRBMap<egf::EntityID, MS2Ptr<CInteractObject> > Unk_WsF15;            // 0x141c04c70 (CPair 0x141bf45a0)
typedef ATL::CRBMap<Unk_WsKindKey, int> Unk_WsF16;                                // 0x141c04d70 m_9d0 (SetAt 0x141c1ba40)
typedef ATL::CRBMap<unsigned __int64, efd::SmartPointer<GameObject> > Unk_WsF17;   // 0x141c04e70

// CAtlMap families, in exe order (GetNode VA). Keys from the CDefaultHashTraits / CDefaultCompareTraits callees:
// int (M1), unsigned (M2-M6), an enum first used here (M7), __int64 (M8-M11; CompareElements<__int64> 0x140212d80).
enum Unk_WsMapKey7 : int {};
typedef ATL::CAtlMap<int, MS2Ptr<CPortal> > Unk_WsM1;                              // 0x141bff390 Hash<int> 0x14015a330 (assign 0x140964fb0; FindPortal)
typedef ATL::CAtlMap<unsigned, MS2Ptr<Unk_WsMapV2> > Unk_WsM2;                     // 0x141bff480
typedef ATL::CAtlMap<unsigned, MS2Ptr<Unk_WsMapV3> > Unk_WsM3;                     // 0x141bff570
typedef ATL::CAtlMap<unsigned, MS2Ptr<Unk_WsMapV4> > Unk_WsM4;                     // 0x141bff660
typedef ATL::CAtlMap<unsigned, MS2Ptr<CProxyGameObject> > Unk_WsM5;                // 0x141bff750 (assign 0x140ac5a20; ProxyObjects)
typedef ATL::CAtlMap<unsigned, MS2Ptr<Unk_WsMapV6> > Unk_WsM6;                     // 0x141bff840
typedef ATL::CAtlMap<Unk_WsMapKey7, MS2Ptr<Unk_WsMapV7> > Unk_WsM7;                // 0x141bff930 enum Hash 0x141c03180, CompareElements 0x141bfaf20
typedef ATL::CAtlMap<__int64, efd::SmartPointer<Unk_WsMapV8> > Unk_WsM8;  // 0x141bffa20
typedef ATL::CAtlMap<__int64, MS2Ptr<Unk_WsMapV9> > Unk_WsM9;             // 0x141bffb10
typedef ATL::CAtlMap<__int64, MS2Ptr<Unk_WsMapV10> > Unk_WsM10;           // 0x141bffc00
typedef ATL::CAtlMap<__int64, MS2Ptr<Unk_WsMapV11> > Unk_WsM11;           // 0x141bffcf0
// m_738: the movers by id (SetAt 0x141c1adb0 -> CreateNode 0x141bfb070 -> NewNode 0x141c08480 -> CPair(key) 0x141bf3ef0,
// whose value is default-constructed by efd::SmartPointer(T* = 0) 0x141bf0fd0: IncRefCount is the pointee's slot 1).
class Unk_WsMover
{
public:
    virtual void DeleteThis();
    virtual void IncRefCount();
    virtual void DecRefCount();
};
typedef ATL::CAtlMap<unsigned, efd::SmartPointer<Unk_WsMover> > Unk_WsM12;

// m_890 (+0x890, 0x38 bytes): the proxy manager of proxyobject.cpp (Unk_ProxyMgr there: ctor 0x1416c3150, dtor
// 0x1416c3190; its class is local to that unit). This view adds the inline enabled getter WorldService 0x141bc12b0 /
// 0x141bda9f0 call; the layout is the same.
class Unk_WsProxyMgr
{
public:
    // @0x141c05780
    int FUN_141c05780() { return m_nEnabled; }

    ATL::CRBMap<egf::EntityID, efd::SmartPointer<CProxyObject> > m_proxies;   // +0x00
    int m_nEnabled;                                                 // +0x30
};
MS2_CHECK_OFFSET(Unk_WsProxyMgr, m_nEnabled, 0x30);

// CAtlList families (NewNode 0x141c08030 ..; CNode 0x18 bytes, so 8-byte smart pointer elements).
// m_058: the PhysX prop records (AddTail 0x141bfad40 from FUN_141bc0530); element copy 0x141bf10a0 -> the pointee's
// non-virtual IncRefCount 0x140ae1dd0 (atomic increment at +8: an NiRefObject).
class Unk_WsProp058 : public NiRefObject {};
typedef ATL::CAtlList<NiPointer<Unk_WsProp058> > Unk_WsL1;                    // m_058 NewNode 0x141c08030
typedef ATL::CAtlList<efd::SmartPointer<GameObject> > Unk_WsL2;               // m_178 NewNode 0x141c080f0 (AddTail 0x141bfadc0)
typedef ATL::CAtlList<efd::SmartPointer<PC> > Unk_WsL3;                       // NewNode 0x141c081b0 (AddTail 0x141bfae40, FUN_141bd1750)
