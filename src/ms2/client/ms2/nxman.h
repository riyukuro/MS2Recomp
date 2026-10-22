// nxman.h - CNXMan (RTTI .?AVCNXMan@@, 0xc8 bytes): the Nexon platform session singleton (game code, UGC/login/stage
// settings and the HTTP result of the last game-log request), plus the event-handler chain its window messages go
// through. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); unit `?\nxman.cpp`
// (0x14160d520-0x14160fb10, dir client\ms2). Member names are invented from their use.
#pragma once

#include "ms2/commonfiles/os.h"
#include <atlstr.h>
#include <atlcoll.h>
#include <string>

// 0x8 bytes, vftable 0x142f43bc0 (3 slots). The virtuals are defined by unit_1415c44c0; nxman.cpp contributes this
// unit's ctor and the CPlatformEventHandler override of vfunc_2.
class CNMEventHandler
{
public:
    CNMEventHandler();                                  // 0x14160f8d0
    virtual void vfunc_0(void* pMsg);                   // 0x1415cba80
    virtual void vfunc_1(void* pParam);                 // 0x1415cc350
    virtual void vfunc_2(void* pParam);                 // 0x1415cc370
};

// 0x8 bytes, vftable 0x142f43d18 (3 slots).
class CPlatformEventHandler : public CNMEventHandler
{
public:
    CPlatformEventHandler();                            // 0x14160f8f0
    virtual void vfunc_2(void* pParam);                 // 0x14160d520
};

// 0xc8 bytes, vftable 0x142f43e80 (only the deleting dtor), ctor 0x14160d540, dtor 0x14160d710.
class CNXMan : public TSingleton<CNXMan>
{
public:
    CNXMan();
    virtual ~CNXMan();

    unsigned FUN_14160d820();                           // 0x14160d820 platform connect
    void FUN_14160da80();                               // 0x14160da80 shutdown
    static bool FUN_14160dac0();                        // 0x14160dac0
    void FUN_14160db10();                               // 0x14160db10
    void FUN_14160db40(void* p1, void* p2);             // 0x14160db40
    int  FUN_14160db80();                               // 0x14160db80
    void FUN_14160dd20();                               // 0x14160dd20
    int  FUN_14160dd50(CStringW& rResult);              // 0x14160dd50
    int  FUN_14160e260();                               // 0x14160e260
    void FUN_14160e410();                               // 0x14160e410
    CString FUN_14160e500();                            // 0x14160e500
    CString FUN_14160e550();                            // 0x14160e550
    CString FUN_14160e5a0();                            // 0x14160e5a0
    int FUN_14160e5f0();                                // 0x14160e5f0
    int  FUN_14160e630();                               // 0x14160e630
    void FUN_14160e870();                               // 0x14160e870
    void FUN_14160e9b0();                               // 0x14160e9b0
    CString FUN_14160e9e0(CString& rHost);              // 0x14160e9e0
    CString FUN_14160eb70();                            // 0x14160eb70
    CString FUN_14160ebf0();                            // 0x14160ebf0

    int m_08;                                           // +0x08
    int m_0c;                                           // +0x0c
    int m_10;                                           // +0x10
    int m_nGameCode;                                    // +0x14
    CString m_str18;                                    // +0x18 game-log URL
    HWND m_hWnd;                                        // +0x20
    CPlatformEventHandler m_eventHandler;               // +0x28
    int m_30;                                           // +0x30 connected
    CString m_38;                                       // +0x38
    CString m_40;                                       // +0x40
    CString m_48;                                       // +0x48
    CString m_50;                                       // +0x50
    CString m_58;                                       // +0x58
    std::wstring m_60;                                   // +0x60
    CString m_80;                                       // +0x80
    int m_88;                                           // +0x88 last HTTP status
    CString m_90;                                       // +0x90
    CString m_98;                                       // +0x98
    ATL::CAtlArray<void*> m_a0;                         // +0xa0
    CString m_c0;                                       // +0xc0
};
MS2_CHECK_SIZE(CNXMan, 0xc8);
MS2_CHECK_OFFSET(CNXMan, m_str18, 0x18);
MS2_CHECK_OFFSET(CNXMan, m_hWnd, 0x20);
MS2_CHECK_OFFSET(CNXMan, m_eventHandler, 0x28);
MS2_CHECK_OFFSET(CNXMan, m_60, 0x60);
MS2_CHECK_OFFSET(CNXMan, m_88, 0x88);
MS2_CHECK_OFFSET(CNXMan, m_a0, 0xa0);
MS2_CHECK_OFFSET(CNXMan, m_c0, 0xc0);

// Error text of the platform error table created by the CNXMan platform helpers (index -> localized string).
CStringW FUN_14160ed00(int nErrorCode);                 // 0x14160ed00
CStringW FUN_14160f680(const wchar_t* psz, const int* pCode); // 0x14160f680
int FUN_14160f9c0(void* pDst, size_t nDstSize, const void* pSrc, size_t nCount); // 0x14160f9c0
