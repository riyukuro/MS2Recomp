// gameoptionsounddefault.h - CGameOptionSoundDefault (RTTI .?AVCGameOptionSoundDefault@@, base CBaseOption, 0x68 bytes): the sound tab.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the methods live in unit `client\ms2\gameoptionstruct.cpp`. Header and member names are
// assumed. Built by UIGameOptionDialog's ctor as tab id 7. State-block ctors are FUN_s in client\ms2\gameoptionstruct.cpp.
#pragma once
#include "ms2/client/ms2/baseoption.h"

struct Unk_SoundState
{
    bool m_b00, m_b01;                                              // +0x00/+0x01 (default 0)
    int m_n[9];                                                     // +0x04..+0x27 (default 0)
    int m_n28;                                                      // +0x28 (default 7)
    int m_n2c;                                                      // +0x2c (default 10)
    bool m_b30;                                                     // +0x30 (default 1)
    float FUN_1412602e0();                                          // the effective volume (0x1412602e0; UISidePopupTalk "volume")
};
MS2_CHECK_SIZE(Unk_SoundState, 0x34);

struct Unk_SoundFlag
{
    bool m_b;                                                       // +0x00 (default 0)
};

class CGameOptionSoundDefault : public CBaseOption
{
public:
    CGameOptionSoundDefault(int nId, int nType);                  // 0x141256d20
    virtual ~CGameOptionSoundDefault();                       // 0x141256da0
    virtual CString vfunc_1();                                     // 0x1412586e0
    virtual void vfunc_3(int n);                                   // 0x141256dd0
    virtual void vfunc_4(int n);                                   // 0x141256e40
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg);// 0x141256e70
    virtual void vfunc_6();                                        // 0x141256e90
    virtual void vfunc_7();                                        // 0x141257a90
    virtual void vfunc_10();                                       // 0x1412585a0
    virtual void vfunc_12();                                       // 0x141258650
    virtual int vfunc_14();                                       // 0x141258730

    Unk_SoundState m_state;                                         // +0x30 (ctor 0x14125f710)
    Unk_SoundFlag m_flag;                                           // +0x64 (ctor 0x141260380)
};
MS2_CHECK_SIZE(CGameOptionSoundDefault, 0x68);
