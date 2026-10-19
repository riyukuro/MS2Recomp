// pendingkeyinput.h - PLACEHOLDER for CGameOptionCommon::PendingKeyInput (RTTI .?AUPendingKeyInput@CGameOptionCommon@@,
// CPtred, 0x20 bytes, vftable 0x142df50f8). NOT an original header.
// A key press the option pages wait for. The ctor (0x141253060) and Clear (0x1412530b0) are defined in
// ?\gameoptioninputdefault.cpp; the inline dtor (0x140be3680, stores the vptr) and Ready (0x140be4cb0) are COMDATs
// first used by client\ms2\uiclosetdialog.cpp, which derives UICloset::PendingKeyInput (0x30) from it. Names follow the
// v2525 snapshot (inferred there too).
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

namespace CGameOptionCommon {

struct PendingKeyInput : public CPtred
{
    PendingKeyInput();                                      // 0x141253060
    virtual ~PendingKeyInput() {}                           // slot 0 (??_G 0x140be3f60)
    virtual void Clear();                                   // slot 1 0x1412530b0
    virtual bool Ready() { return false; }                  // slot 2 0x140be4cb0

    bool m_bBusy;                                           // +0x18
    unsigned m_nKey;                                        // +0x1c
};
MS2_CHECK_SIZE(PendingKeyInput, 0x20);

}
