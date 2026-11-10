// cinputkeyhandler.h - PLACEHOLDER for CInputKeyHandler (RTTI .?AVCInputKeyHandler@@, 0x10 bytes, TSingleton<CInputKeyHandler>
// at +0x0): the gate every game-side key / mouse query goes through (debug mode, modifier flags, the key-binding table,
// the input service). Unit unit_14116d540 (ctor 0x14116d540, dtor 0x14116d5a0); the singleton is created in ?\mainsystem.cpp.
// NOT an original header; member names invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CInputKeyHandler : public TSingleton<CInputKeyHandler>
{
public:
    CInputKeyHandler();                                     // 0x14116d540
    virtual ~CInputKeyHandler();                            // 0x14116d5a0

    void SetDebugMode(bool bOn);                            // 0x14116d5d0 toggles + posts NotifyDebugMode (needs the GM level)
    bool IsDebugMode();                                     // 0x14116d720
    void SetModifier1(bool b);                              // 0x14116d760
    void SetModifier2(bool b);                              // 0x14116d780
    bool FUN_14116d7a0(unsigned nMask);                      // 0x14116d7a0 bit mask of the modifier states in effect
    bool FUN_14116d840();                                    // 0x14116d840
    bool FUN_14116d890(bool bAlt);                           // 0x14116d890
    bool IsKeyDown(int nKey, bool bDebugOnly, int nLevel);   // 0x14116d950 key held (group-aware)
    bool WasKeyPressed(int nKey, bool bDebugOnly, int nLevel);   // 0x14116d9c0 key pressed this frame
    bool WasKeyReleased(int nKey, bool bDebugOnly, int nLevel);   // 0x14116da30 key released this frame
    bool IsMouseButtonDown(int nKey, bool bDebugOnly, int nLevel);   // 0x14116daa0 mouse button held
    bool WasMouseButtonPressed(int nKey, bool bDebugOnly, int nLevel);   // 0x14116db10 mouse button pressed
    bool WasMouseButtonReleased(int nKey, bool bDebugOnly, int nLevel);   // 0x14116db80 mouse button released
    bool GetMouseDelta(int* pnX, int* pnY, int* pnZ, bool bDebugOnly, int nLevel);   // 0x14116dbf0 mouse movement deltas
    bool IsActionKeyDown(int nSetting, bool bDebugOnly, int nLevel);   // 0x14116dcb0 key-binding table query
    bool FUN_14116dd30(int nSetting, bool bDebugOnly, int nLevel);   // 0x14116dd30
    bool FUN_14116ddb0(int nSetting, bool bDebugOnly, int nLevel);   // 0x14116ddb0
    bool InjectKeyPress(int nKey);                           // 0x14116de30 inject a key press (input enabled)
    bool InjectKeyRelease(int nKey);                           // 0x14116de70 inject a key release

private:
    MS2_LAYOUT_FRIEND;
    bool m_bDebugMode;                                      // +0x08
    bool m_bModifier1;                                      // +0x09
    bool m_bModifier2;                                      // +0x0a
    bool m_b0b;                                             // +0x0b
    bool m_b0c;                                             // +0x0c
};
MS2_CHECK_SIZE(CInputKeyHandler, 0x10);
