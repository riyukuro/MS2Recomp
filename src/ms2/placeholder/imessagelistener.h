// imessagelistener.h - PLACEHOLDER for IMessageListener and UIMsg. NOT an original header.
// IMessageListener: RTTI .?AVIMessageListener@@, vftable 0x142ea6a48 = { _purecall }: an interface with one pure
// virtual and no virtual destructor. UISwfEntity has it at +0x18; the slot is overridden by UISwfEntity
// (0x1422dc790) and UICutSceneMovie (0x14190f980). The name OnMessage is invented (the only slot of a listener).
// UIMsg: RTTI .?AVUIMsg@@ (80 bytes, bases ASData, CPtred, vftable 0x1431152e0, ddtor 0x1422e4530).
#pragma once

#include <afx.h>

class UISwfEntity;

// UIMsg is the real class (base ASData, ctors) from gfxui/uimsg.h; its argument getters are ASData members.
#include "ms2/gfxui/uimsg.h"

class IMessageListener
{
public:
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg) = 0;   // slot 0
};
