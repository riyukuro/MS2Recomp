// gameoptionstatus.h - CGameOptionStatus (RTTI .?AVCGameOptionStatus@@, base CBaseOption, 0x50 bytes): the status tab.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the methods live in unit `client\ms2\gameoptionstruct.cpp`. Header and member names are
// assumed. Built by UIGameOptionDialog's ctor as tab id 3. State-block ctors are FUN_s in client\ms2\gameoptionstruct.cpp.
#pragma once
#include "ms2/client/ms2/baseoption.h"

struct Unk_StatusState
{
    bool m_b[0x16];                                                 // +0x00..+0x15 (mostly default 1; +5,+9,+0xa,+0xc,+0xe,+0x12..+0x15 default 0; +6 = FUN_14036e4c0(FUN_140166410()))
    short m_pad16;
    int m_n18;                                                      // +0x18 (default 0)
};
MS2_CHECK_SIZE(Unk_StatusState, 0x1c);

struct Unk_StatusFlag
{
    bool m_b;                                                       // +0x00 (default 0)
};

class CGameOptionStatus : public CBaseOption
{
public:
    CGameOptionStatus(int nId, int nType);                        // 0x1412589a0
    virtual ~CGameOptionStatus();                             // 0x141258a20
    virtual CString vfunc_1();                                     // 0x14125b060
    virtual void vfunc_3(int n);                                   // 0x141258a50
    virtual void vfunc_4(int n);                                   // 0x141258ac0
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg);// 0x141258af0
    virtual void vfunc_6();                                        // 0x141258b10
    virtual void vfunc_7();                                        // 0x141259c40
    virtual void vfunc_10();                                       // 0x14125ae50
    virtual void vfunc_12();                                       // 0x14125afe0
    virtual int vfunc_14();                                       // 0x14125b0b0

    Unk_StatusState m_state;                                        // +0x30 (ctor 0x14125bda0)
    Unk_StatusFlag m_flag;                                          // +0x4c (ctor 0x14125c880)
};
MS2_CHECK_SIZE(CGameOptionStatus, 0x50);
