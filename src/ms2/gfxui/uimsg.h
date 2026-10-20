// uimsg.h - UIMsg (RTTI .?AVUIMsg@@, bases ASData, CPtred; vftable 0x1431152e0, 0x50 bytes: ??_G deletes 0x50), the
// message a UISwfEntity sends to its IMessageListener: the ASData argument list of the AS callback plus a message id
// at +0x48. Recovered with ?\uimsg.cpp (src/ms2/gfxui/uimsg.cpp). The name of the header is assumed.
//
// placeholder/imessagelistener.h has an older declaration-only view of this class (no base, same FUN_ members, so the
// same mangled names); it is skipped when this header comes first. Include this header before imessagelistener.h.
#pragma once

#ifdef MS2_UIMSG_VIEW_DEFINED
#error "include gfxui/uimsg.h before placeholder/imessagelistener.h"
#endif
#define MS2_UIMSG_DEFINED

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asdata.h"

class UIMsg : public ASData
{
public:
    UIMsg();                            // 0x1422e4490 (message 0)
    explicit UIMsg(int nMessage);       // 0x1422e44d0
    // ~UIMsg is implicit (0x140c30570, a COMDAT of an earlier unit: it only calls ~ASData)
    int FUN_1422e4520();                // the message id (UICutSceneMovie::OnMessage: nonzero = handled/cancelled?)

private:
    MS2_LAYOUT_FRIEND;
    int m_nMessage;                     // +0x48
};
MS2_CHECK_SIZE(UIMsg, 0x50);
MS2_CHECK_OFFSET(UIMsg, m_nMessage, 0x48);
