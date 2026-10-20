// notifybinding.h - NotifyBinding (RTTI .?AVNotifyBinding@@, 0x48 bytes, base NotifyHandler): the notify handler that
// exposes "createBindingImpl" / "deleteBindingImpl" to ActionScript. Both look up a NotifyContext::BindData by name
// (args[0]) and attach / detach the AS objects args[1] / args[2] to it. vftable 0x14311b378 (??_G 0x142301470, Call
// inherited). Recovered with ?\notifybinding.cpp (0x142301060-0x142301ff0); header name and directory assumed, the
// method names are invented after the AS names.
#pragma once

#include "ms2/gfxui/notifyhandler.h"

class NotifyBinding : public NotifyHandler
{
public:
    explicit NotifyBinding(Unk_NotifyContext* pContext);           // 0x142301060
    // ~NotifyBinding is implicit (0x142301450; ??_G 0x142301470)

    void CreateBindingImpl(const Params& params);                  // 0x142301140 "createBindingImpl"
    void DeleteBindingImpl(const Params& params);                  // 0x142301210 "deleteBindingImpl"
    static void OnCreateBindingImpl(NotifyHandler* pHandler, const Params& params);   // 0x142301330 (table entry)
    static void OnDeleteBindingImpl(NotifyHandler* pHandler, const Params& params);   // 0x142301370 (table entry)
};
MS2_CHECK_SIZE(NotifyBinding, 0x48);
