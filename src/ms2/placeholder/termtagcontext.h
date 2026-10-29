// termtagcontext.h - TermTagContext (?\termtagcontext.cpp, 0x1408665e0-0x140866b00; RTTI .?AVTermTagContext@@, 0x50 bytes,
// CPtred). Header name assumed; the member names are invented. A named, timed tag of the game events (CGameRule keeps them
// by name at +0x650): an id, the tag name, a [start, end) time range and a flag, read from a packet.
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"

class CInPacket;

class TermTagContext : public CPtred
{
public:
    TermTagContext();                                       // 0x1408665e0
    virtual ~TermTagContext() = default;                    //  0 0x140866a90 (??_G 0x140866ac0; the exe body stores no vftable)

    int FUN_140866670();                                    // the id (m_18)
    CStringW FUN_140866690();                               // the name (m_20)
    CMsTime FUN_1408666e0();                                // the start time
    CMsTime FUN_140866720();                                // the end time
    bool FUN_140866760();                                   // the flag (m_48)
    void FUN_140866780();                                   // register in CGameRule
    void FUN_1408667e0();                                   // unregister from CGameRule
    bool FUN_140866820(const CMsTime& kTime);               // start <= time < end
    bool FUN_140866880(const __time64_t* pTime);            // the same for a raw time
    void FUN_140866900(CInPacket& packet);                  // read from the packet

    int m_18;
    CStringW m_20;                                          // +0x20 name
    CMsTime m_28;
    CMsTime m_38;
    bool m_48;
};
