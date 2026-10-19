// gameoptiongamepad.h - CGameOptionGamePad (RTTI .?AVCGameOptionGamePad@@, base CBaseOption, 0x40 bytes): the gamepad
// row of the game options (use gamepad, show skill names, vibration, stick sensitivities). Recovered from
// MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\gameoptiongamepad.cpp`. Header name and member names are
// assumed.
// vftable: 15 slots; its own are 0 (deleting dtor), 1, 3, 4, 5, 6, 7, 10, 12 and 14.
#pragma once
#include "ms2/client/ms2/baseoption.h"

// The gamepad settings block (0x10 bytes): the copy that lives in the option row (+0x30) and the one inside the game
// settings object (+0x1a0). Its methods live in another unit (0x14125f290...), declared here as FUN_ free functions.
struct Unk_GpState
{
    bool m_bUse;                    // +0x00 use the gamepad
    bool m_bShowSkillName;          // +0x01
    bool m_bVibration;              // +0x02
    float m_fSensitivityH;          // +0x04 0.01..  (shown x100)
    float m_fSensitivityV;          // +0x08
    int m_nLStickSensitivity;       // +0x0c
};
MS2_CHECK_SIZE(Unk_GpState, 0x10);

class CGameOptionGamePad : public CBaseOption
{
public:
    CGameOptionGamePad(int nId, int nType);                         // 0x140a571b0
    virtual ~CGameOptionGamePad();                                  // 0x140a57210 (deleting dtor 0x140a584c0)

    virtual CString vfunc_1();                                      // 0x140a57d60 (returns "GameOptionLanguage": copy-paste in the original)
    virtual void vfunc_3(int n);                                    // 0x140a57240
    virtual void vfunc_4(int n);                                    // 0x140a57290
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg); // 0x140a572c0 (not handled)
    virtual void vfunc_6();                                         // 0x140a572e0 write the state into the UI
    virtual void vfunc_7();                                         // 0x140a57730 read the state back from the UI
    virtual void vfunc_10();                                        // 0x140a57c20
    virtual void vfunc_12();                                        // 0x140a57d00
    virtual int vfunc_14();                                        // 0x140a57db0 differs from the saved settings

    Unk_GpState m_state;                                            // +0x30
};
MS2_CHECK_SIZE(CGameOptionGamePad, 0x40);
