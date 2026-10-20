// notifyhandler.h - NotifyHandler (RTTI .?AVNotifyHandler@@, 0x48 bytes, base Scaleform::GFx::FunctionHandler): a GFx
// function handler that exposes a table of named C++ callbacks to ActionScript. FUN_1423008f0 creates one AS function
// per table entry (Movie::CreateFunction with the callback as user data) and stores it as a member of an AS object;
// Call() dispatches to the callback in Params::pUserData. Derived handlers (NotifyBinding, NotifyDragSlot,
// NotifySwfEntity) fill the table in their ctors. vftable 0x14311b2b8 (2 slots: ??_G 0x142300be0, Call 0x142300a00).
// The ctor/Bind/Call are in ?\notifyhandler.cpp (0x142300880-0x142301060); header name and directory assumed.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <set>
#include <efd/SmartPointer.h>
#include <NiRefObject.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"

// The real class is NotifyContext (RTTI .?AVNotifyContext@@, 0x10 bytes, base NiRefObject, vftable 0x1431095a0, ctor
// 0x1422b34a0); GFxManager owns one (+0x98, accessor FUN_1422b0260). The name NotifyContext is taken by the namespace
// dragslot.h declares around NotifyContext::BindData, so this stand-in is used until ?\notifycontext.cpp turns it
// into the class.
namespace NotifyContext { class BindData; }
class Unk_NotifyContext : public NiRefObject
{
public:
    // The bind data registered under a name (null if none). Static: NotifyDragSlot calls it through m_spContext->.
    static NotifyContext::BindData* FUN_1422c8e90(const CString& strName);    // 0x1422c8e90
    static void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pData);   // 0x1422c8f10 bind pData under strName
    static void FUN_1422c8f70(const CString& strName);                         // 0x1422c8f70 clear the binding and unregister it
    void FUN_1422c8de0();                                                      // 0x1422c8de0 log the bindings left, then FUN_1422c9010
    static void FUN_1422c9010();                                               // 0x1422c9010 clear and unregister every binding
    static void FUN_1422c90d0();                                               // 0x1422c90d0 notify the bindings that depend on a changed name
    static void FUN_1422c9380(const CString& strName);                         // 0x1422c9380 strName changed (keytable.cpp)
    static void FUN_1422c93e0(const CString& strName);                         // 0x1422c93e0 strName pushed its own data

    // The registry (?\notifycontext.cpp). The exe's dynamic initializers are in unit_140135ac0.cpp (0x140135b60-0x140135bc0).
    static std::set<CString> ms_setChanged;                                    // 0x143b0b258 names changed since the last FUN_1422c90d0
    static std::set<CString> ms_setPushed;                                     // 0x143b0b268 names that pushed their own data meanwhile
    static CRBMap<CString, efd::SmartPointer<NotifyContext::BindData> > ms_mapBindings;   // 0x143b0b278 name -> binding
};

class NotifyHandler : public Scaleform::GFx::FunctionHandler
{
public:
    // The callback type of the table (stored as the AS function's user data).
    typedef void (*Callback)(NotifyHandler* pHandler, const Params& params);

    explicit NotifyHandler(Unk_NotifyContext* pContext);           // 0x142300880
    // ~NotifyHandler is implicit (0x142300b60; ??_G 0x142300be0)
    virtual void Call(const Params& params);                       // 1 0x142300a00

    // Defines every callback of the table as a function member of obj (an AS object of movie nMovieId).
    void FUN_1423008f0(int nMovieId, Scaleform::GFx::Value& obj);  // 0x1423008f0

public:
    MS2_LAYOUT_FRIEND;
    efd::SmartPointer<Unk_NotifyContext> m_spContext;              // +0x10
    CRBMap<CString, Callback> m_callbacks;                          // +0x18 AS name -> callback
};
MS2_CHECK_SIZE(NotifyHandler, 0x48);
MS2_CHECK_OFFSET(NotifyHandler, m_spContext, 0x10);
MS2_CHECK_OFFSET(NotifyHandler, m_callbacks, 0x18);
