// notifyswfentity.h - NotifySwfEntity (RTTI .?AVNotifySwfEntity@@, 0x48 bytes, base NotifyHandler): the callbacks an
// SWF entity's ActionScript calls back into ("getUserData": forward an ExternalInterface call to the named
// UISwfEntity, "playSound": play a UI sound). vftable 0x14311b628 (??_G 0x1423033e0, Call inherited).
// Code in ?\notifyswfentity.cpp (0x142302df0-0x142303440); header name and directory assumed.
#pragma once

#include "ms2/gfxui/notifyhandler.h"

class NotifySwfEntity : public NotifyHandler
{
public:
    explicit NotifySwfEntity(Unk_NotifyContext* pContext);         // 0x142302df0
    // ~NotifySwfEntity is implicit (0x1423033c0; ??_G 0x1423033e0)

    void getUserData(const Params& params);                         // 0x142302ed0 args: entity, method, call args...
    void playSound(const Params& params);                           // 0x142303260 args: sound[, arg]

    // The table entries (NotifyHandler::Callback): forward to the members above.
    static void getUserDataImpl(NotifyHandler* pHandler, const Params& params);  // 0x142303340
    static void playSoundImpl(NotifyHandler* pHandler, const Params& params);    // 0x142303380
};
MS2_CHECK_SIZE(NotifySwfEntity, 0x48);
