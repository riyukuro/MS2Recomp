// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's observer managers: PacketHandlerManager (opcode ->
// Delegate<void(CInPacket&)> list), GameEventUserValueManager (event id -> Delegate<void(GameEventVariable*)> list) and the
// container / Delegate glue shared with NotifySystem's name -> Delegate<void(NotifyObject*)> map (owned by ?\notifysystem.cpp,
// instantiated here by an anchor), plus the Notify* name virtuals.
// MS2-UNIT: unit_140da50e0
// MS2-RANGE: 0x140da4da0-0x140db46d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$_Vector_alloc@U?$_Vec_base_types@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@QEAA@XZ 0x140dad570 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x140db1400 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x140db1410 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@V?$_Vector_val@U?$_Simple_types@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@2@XZ 0x140db1460 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@V?$_Vector_val@U?$_Simple_types@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@2@XZ 0x140db1470 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x140db14c0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@2@$00@std@@QEBAAEBV?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@2@XZ 0x140db14d0 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@2@$00@2@XZ 0x140db1520 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@@std@@@2@$00@2@XZ 0x140db1530 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBIV?$vector@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@V?$allocator@V?$Delegate@$$A6AXAEAVCInPacket@@@Z@@@std@@@std@@@std@@PEAX@2@_K@Z 0x140db3310
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBIV?$vector@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVGameEventVariable@@@Z@@@std@@@std@@@std@@PEAX@2@_K@Z 0x140db3340
// MS2-PIN: ?deallocate@?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@std@@@std@@QEAAXQEAU?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$vector@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@V?$allocator@V?$Delegate@$$A6AXPEAVNotifyObject@@@Z@@@std@@@std@@@std@@PEAX@2@_K@Z 0x140db3370
#ifndef NOMINMAX
#define NOMINMAX
#endif
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/gameeventuservaluemanager.h"
#include "ms2/placeholder/notifyobject.h"
#include "ms2/placeholder/notifygameeventchanged.h"

// ---- Delegate comparison / invocation (the out-of-line COMDATs of the three handler signatures) ----------------------

// @0x140dae000
template<> bool Delegate<void(CInPacket&)>::operator==(const Delegate& o) const
{
    if (m_pImpl == 0 && o.m_pImpl == 0)
        return true;
    if (m_pImpl == 0 || o.m_pImpl == 0)
        return false;
    return m_pImpl->vfunc_3(o.m_pImpl);
}

// @0x140dae070
template<> bool Delegate<void(GameEventVariable*)>::operator==(const Delegate& o) const
{
    if (m_pImpl == 0 && o.m_pImpl == 0)
        return true;
    if (m_pImpl == 0 || o.m_pImpl == 0)
        return false;
    return m_pImpl->vfunc_3(o.m_pImpl);
}

// @0x140dae0e0
template<> bool Delegate<void(NotifyObject*)>::operator==(const Delegate& o) const
{
    if (m_pImpl == 0 && o.m_pImpl == 0)
        return true;
    if (m_pImpl == 0 || o.m_pImpl == 0)
        return false;
    return m_pImpl->vfunc_3(o.m_pImpl);
}

void FUN_140657820();                                           // invalid call of an empty Delegate (shared)

// @0x140daec00
template<> void Delegate<void(CInPacket&)>::operator()(CInPacket& a1) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->vfunc_2(a1);
}

// @0x140daec40
template<> void Delegate<void(GameEventVariable*)>::operator()(GameEventVariable* a1) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->vfunc_2(a1);
}

// @0x140daec80
template<> void Delegate<void(NotifyObject*)>::operator()(NotifyObject* a1) const
{
    if (m_pImpl == 0)
        FUN_140657820();
    m_pImpl->vfunc_2(a1);
}

// ---- Delegate copy / assignment (clone through slot 1) --------------------------------------------------------------

// @0x140dacdf0
template<> Delegate<void(CInPacket&)>::Delegate(const Delegate& o)
{
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
}

// @0x140dadd00
template<> Delegate<void(CInPacket&)>& Delegate<void(CInPacket&)>::operator=(const Delegate& o)
{
    if (this == &o)
        return *this;
    if (m_pImpl)
        delete m_pImpl;
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
    return *this;
}

// @0x140dace40
template<> Delegate<void(GameEventVariable*)>::Delegate(const Delegate& o)
{
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
}

// @0x140daddc0
template<> Delegate<void(GameEventVariable*)>& Delegate<void(GameEventVariable*)>::operator=(const Delegate& o)
{
    if (this == &o)
        return *this;
    if (m_pImpl)
        delete m_pImpl;
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
    return *this;
}

// @0x140dace90
template<> Delegate<void(NotifyObject*)>::Delegate(const Delegate& o)
{
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
}

// @0x140dade80
template<> Delegate<void(NotifyObject*)>& Delegate<void(NotifyObject*)>::operator=(const Delegate& o)
{
    if (this == &o)
        return *this;
    if (m_pImpl)
        delete m_pImpl;
    if (o.m_pImpl == 0)
        m_pImpl = 0;
    else
        m_pImpl = o.m_pImpl->vfunc_1();
    return *this;
}

// ---- NotifySystem ------------------------------------------------------------------------------------------------------

// @0x140da4da0
NotifySystem::NotifySystem() {}

// @0x140da4df0
NotifySystem::~NotifySystem()
{
    m_handlers.clear();
}

// @0x140da4e40
void NotifySystem::RegisterNotify(CStringW strName, Delegate<void(NotifyObject*)> handler)
{
    std::vector<Delegate<void(NotifyObject*)> >& list = m_handlers[strName];
    list.push_back(handler);
}

// @0x140da4eb0
void NotifySystem::UnregisterNotify(CStringW strName, Delegate<void(NotifyObject*)> handler)
{
    std::vector<Delegate<void(NotifyObject*)> >& list = m_handlers[strName];
    for (unsigned i = 0; i < list.size(); ++i)
    {
        if (list[i] == handler)
        {
            list.erase(list.begin() + i);
            return;
        }
    }
}

// @0x140da4fe0
void NotifySystem::Post(MS2Ptr<NotifyObject> spNotify)
{
    std::vector<Delegate<void(NotifyObject*)> >& list = m_handlers[spNotify->GetTypeName()];
    for (unsigned i = 0; i < list.size(); ++i)
        list[i](spNotify.get());
}

// ---- PacketHandlerManager ---------------------------------------------------------------------------------------------

// @0x140da50e0
PacketHandlerManager::PacketHandlerManager() {}

// @0x140da5130
PacketHandlerManager::~PacketHandlerManager()
{
    m_handlers.clear();
}

// @0x140da5180
void PacketHandlerManager::RegisterHandler(unsigned nOpcode, Delegate<void(CInPacket&)> handler)
{
    std::vector<Delegate<void(CInPacket&)> >& list = m_handlers[nOpcode];
    list.push_back(handler);
}

// @0x140da51e0
void PacketHandlerManager::UnregisterHandler(unsigned nOpcode, Delegate<void(CInPacket&)> handler)
{
    std::vector<Delegate<void(CInPacket&)> >& list = m_handlers[nOpcode];
    for (unsigned i = 0; i < list.size(); ++i)
    {
        if (list[i] == handler)
        {
            list.erase(list.begin() + i);
            return;
        }
    }
}

// @0x140da52f0
void PacketHandlerManager::Dispatch(unsigned nOpcode, CInPacket& iPacket)
{
    std::vector<Delegate<void(CInPacket&)> >& list = m_handlers[nOpcode];
    for (unsigned i = 0; i < list.size(); ++i)
    {
        iPacket.FUN_14070fe80();
        list[i](iPacket);
    }
}

// ---- GameEventUserValueManager ----------------------------------------------------------------------------------------

// @0x140da5390
GameEventUserValueManager::GameEventUserValueManager() {}

// @0x140da53e0
GameEventUserValueManager::~GameEventUserValueManager()
{
    m_listeners.clear();
}

// @0x140da5430
void GameEventUserValueManager::RegisterListener(unsigned nEvent, Delegate<void(GameEventVariable*)> listener)
{
    std::vector<Delegate<void(GameEventVariable*)> >& list = m_listeners[nEvent];
    list.push_back(listener);
}

// @0x140da5490
void GameEventUserValueManager::UnregisterListener(unsigned nEvent, Delegate<void(GameEventVariable*)> listener)
{
    std::vector<Delegate<void(GameEventVariable*)> >& list = m_listeners[nEvent];
    for (unsigned i = 0; i < list.size(); ++i)
    {
        if (list[i] == listener)
        {
            list.erase(list.begin() + i);
            return;
        }
    }
}

// @0x140da55a0
void GameEventUserValueManager::Dispatch(unsigned nEvent, GameEventVariable* pVariable)
{
    std::vector<Delegate<void(GameEventVariable*)> >& list = m_listeners[nEvent];
    for (unsigned i = 0; i < list.size(); ++i)
        list[i](pVariable);
}

// ---- Notify* names (the inline GetTypeName COMDATs of the notice classes, emitted here) -----------------------------------------
// The classes are declared by their users; only the name virtual is defined here, so these stand-ins carry no members.
class NotifyCompleteMyPC : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyUseSKill : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyUgcDownloadComplete : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyLearnEmotion : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyPcBang : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyGameStart : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyChangeServer : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyChangeMyJob : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyChangeMyLevel : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyRemoveGameObject : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyCutSceneCinematicSkip : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyCreateMyPC : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyChangeMyPC : public NotifyObject { public: virtual CStringW GetTypeName(); };
class NotifyChangedTokenMoney : public NotifyObject { public: virtual CStringW GetTypeName(); };

// @0x140db40d0
CStringW NotifyObject::GetTypeName()
{
    return L"NotifyObject";
}

// @0x140db4130
CStringW NotifyGameEventChanged::GetTypeName()
{
    return L"NotifyGameEventChanged";
}

// @0x140db4190
CStringW NotifyLearnEmotion::GetTypeName()
{
    return L"NotifyLearnEmotion";
}

// @0x140db41f0
CStringW NotifyPcBang::GetTypeName()
{
    return L"NotifyPcBang";
}

// @0x140db4250
CStringW NotifyUgcDownloadComplete::GetTypeName()
{
    return L"NotifyUgcDownloadComplete";
}

// @0x140db42b0
CStringW NotifyGameStart::GetTypeName()
{
    return L"NotifyGameStart";
}

// @0x140db4310
CStringW NotifyChangeServer::GetTypeName()
{
    return L"NotifyChangeServer";
}

// @0x140db4370
CStringW NotifyChangeMyJob::GetTypeName()
{
    return L"NotifyChangeMyJob";
}

// @0x140db43d0
CStringW NotifyChangeMyLevel::GetTypeName()
{
    return L"NotifyChangeMyLevel";
}

// @0x140db4430
CStringW NotifyRemoveGameObject::GetTypeName()
{
    return L"NotifyRemoveGameObject";
}

// @0x140db4490
CStringW NotifyCutSceneCinematicSkip::GetTypeName()
{
    return L"NotifyCutSceneCinematicSkip";
}

// @0x140db44f0
CStringW NotifyCreateMyPC::GetTypeName()
{
    return L"NotifyCreateMyPC";
}

// @0x140db4550
CStringW NotifyCompleteMyPC::GetTypeName()
{
    return L"NotifyCompleteMyPC";
}

// @0x140db45b0
CStringW NotifyChangeMyPC::GetTypeName()
{
    return L"NotifyChangeMyPC";
}

// @0x140db4610
CStringW NotifyChangedTokenMoney::GetTypeName()
{
    return L"NotifyChangedTokenMoney";
}

// @0x140db4670
CStringW NotifyUseSKill::GetTypeName()
{
    return L"NotifyUseSKill";
}

