// recodemgr.h - RecodeMgr (RTTI .?AVRecodeMgr@@, 0x78 bytes): the screen-recording service of the client. NOT an original
// header. Bases: CThread at +0x0, TSingleton<RecodeMgr> at +0x18. CGameApp::InitInstance (?\ms2.cpp) creates it. The
// recording itself runs inside the MS2RenderContext (recode surface); this class starts / stops it and launches the
// external MS2Media recorder. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\recodemgr.cpp`.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cthread.h"

class RecodeMgr : public CThread, public TSingleton<RecodeMgr>
{
public:
    RecodeMgr();                                            // 0x140c9ba20
    virtual ~RecodeMgr();                                   // 0x140c9bac0 (deleting 0x140c9c160)
    void FUN_140c9bb20();                                   // stops the recording (also on device loss)
    int FUN_140c9bb40();                                    // 1 while recording
    int FUN_140c9bb60();                                    // start recording with the default text
    int FUN_140c9bc00();                                    // stop the recording
    int FUN_140c9bc70(CString strText);                     // start recording with a text line (callee destroys it)
    void FUN_140c9bda0();                                   // graphic option call (ignores this)
    void FUN_140c9bdd0();                                   // graphic option call (ignores this)
    int FUN_140c9be00();                                    // launch the MS2Media recorder once (a named mutex guards it)

private:
    MS2_LAYOUT_FRIEND;
    char m_pad_20[0x18];                                    // +0x20 not touched by the ctor
    CLockCriticalSection m_lock;                            // +0x38
    int m_bRecording;                                       // +0x68
    int m_6c;                                               // +0x6c
    int m_70;                                               // +0x70
    int m_74;                                               // +0x74
};
MS2_CHECK_SIZE(RecodeMgr, 0x78);
