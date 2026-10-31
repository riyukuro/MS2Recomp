// reconnectionstructs.h - PLACEHOLDER for the reconnection value classes defined in commonfiles\clientreconnectionstructs.cpp
// (0x140208340-0x14020c3a0, not recovered yet). Sizes/fields proved from CReconnectionManagerCli's use of them
// (client\ms2\reconnectionmanagercli.cpp). All three derive CPtred (the exe's ctors call the CPtred ctor first).
// Only declarations: ctors/dtors/methods are defined in the real unit.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/coutpacket.h"
class CInputStream;

// 0x48: eleven ints at +0x18 (indexed accessor 0x140aadf90, inline in clientreconnectionstructs.h line 0xa4).
class ReconnectionOptions : public CPtred {
public:
    ReconnectionOptions();                                  // 0x1402083b0
    virtual ~ReconnectionOptions();
    ReconnectionOptions* FUN_140208460(const ReconnectionOptions* src);   // copies the 0x2c payload bytes at +0x18
    void FUN_140208500(CInputStream& in);                   // 11 x Decode4
    int FUN_140aadf90(int index);                           // inline COMDAT: bounds-asserts 0..10, returns m_values[index]
    int m_values[11];                                       // +0x18 (0x2c payload bytes); an array, so a local is a /GS buffer as in the exe
};
MS2_CHECK_SIZE(ReconnectionOptions, 0x48);

// 0x30: server-side description of the target (set from the 0x140aada20 packet).
class ReconnectionContext : public CPtred {
public:
    ReconnectionContext();                                  // 0x140208560
    virtual ~ReconnectionContext();
    void FUN_1402085c0();                                   // reset
    void FUN_140208610(COutPacket& packet);
    int m_18; CString m_20; int m_28;
};
MS2_CHECK_SIZE(ReconnectionContext, 0x30);

// 0x50: client-side reconnect state.
class ReconnectionContextCli : public CPtred {
public:
    ReconnectionContextCli();                               // 0x140208720
    virtual ~ReconnectionContextCli();
    void FUN_140208780();                                   // reset
    int m_attempt;          // +0x18
    int m_maxAttempts;      // +0x1c
    int m_postParam;        // +0x20
    int m_session;          // +0x24
    bool m_pending;         // +0x28
    int m_lastError;        // +0x2c
    bool m_disabled;        // +0x30
    int m_startTick;        // +0x34
    int m_lastTick;         // +0x38
    int m_3c;
    CString m_host;         // +0x40
    int m_port;             // +0x48
    int m_deadline;         // +0x4c
};
MS2_CHECK_SIZE(ReconnectionContextCli, 0x50);
