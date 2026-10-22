// gameoptioninterface.h - CGameOptionInterface (RTTI .?AVCGameOptionInterface@@, base CBaseOption, 0x58 bytes): the interface tab. Second base IMessageListener (+0x30), OnMessage = vfunc_o30_0 0x141255b50.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the methods live in unit `client\ms2\gameoptionstruct.cpp`. Header and member names are
// assumed. Built by UIGameOptionDialog's ctor as tab id 2. The state block's ctor is a FUN_ in client\ms2\gameoptionstruct.cpp.
#pragma once
#include "ms2/client/ms2/baseoption.h"
#include "ms2/placeholder/imessagelistener.h"

struct Unk_InterfaceState
{
    bool m_b00;                                                     // +0x00 (default 0)
    bool m_b01;                                                     // +0x01 (default 1)
    bool m_b02;                                                     // +0x02 (default 1)
    bool m_b03;                                                     // +0x03
    bool m_b04;                                                     // +0x04
    float m_f08;                                                    // +0x08 (default 1.0)
    int m_n0c;                                                      // +0x0c (default 100)
    int m_n10;                                                      // +0x10 (default 100)
    bool m_b14;                                                     // +0x14 (default 1)
    bool m_b15;                                                     // +0x15 (default 1)
};
MS2_CHECK_SIZE(Unk_InterfaceState, 0x18);

struct Unk_InterfaceFlag
{
    bool m_b;                                                       // +0x00 (default 0)
};

class CGameOptionInterface : public CBaseOption, public IMessageListener
{
public:
    CGameOptionInterface(int nId, int nType);                          // 0x1412558c0
    virtual ~CGameOptionInterface();                                    // 0x141255960
    virtual CString GetTypeName();                                      // 0x141256c50
    virtual void vfunc_3(int n);                                    // 0x1412559a0
    virtual void vfunc_4(int n);                                    // 0x141255a10
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg); // 0x141255a40
    virtual void vfunc_6();                                         // 0x141255c10 write the state into the UI
    virtual void vfunc_7();                                         // 0x1412562f0 read the state back from the UI
    virtual void vfunc_10();                                        // 0x1412569a0
    virtual void vfunc_11();                                        // 0x141256b50
    virtual void vfunc_12();                                        // 0x141256bb0
    virtual int vfunc_14();                                        // 0x141256ca0 differs from the saved settings
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);       // 0x141255b50 (vfunc_o30_0)

    Unk_InterfaceState m_state;                                    // +0x38 (ctor 0x14125b770)
    Unk_InterfaceFlag m_flag;                                      // +0x50 (ctor 0x14125bc30)
};
MS2_CHECK_SIZE(CGameOptionInterface, 0x58);
