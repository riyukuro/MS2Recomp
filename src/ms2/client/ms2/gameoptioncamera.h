// gameoptioncamera.h - CGameOptionCamera (RTTI .?AVCGameOptionCamera@@, base CBaseOption, 0x40 bytes): the camera tab (field of view/zoom settings).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the methods live in unit `client\ms2\gameoption.cpp`. Header and member names are
// assumed. Built by UIGameOptionDialog's ctor as tab id 1. The state block's ctor is a FUN_ in client\ms2\gameoptionstruct.cpp.
#pragma once
#include "ms2/client/ms2/baseoption.h"

struct Unk_CameraState
{
    bool m_b00;                                                     // +0x00 (default 1)
    bool m_b01;                                                     // +0x01 (default 1)
    int m_n04;                                                      // +0x04 (default 100)
    int m_n08;                                                      // +0x08 (default 100)
    int m_n0c;                                                      // +0x0c (default 0x82)
};
MS2_CHECK_SIZE(Unk_CameraState, 0x10);

class CGameOptionCamera : public CBaseOption
{
public:
    CGameOptionCamera(int nId, int nType);                             // 0x141248830
    virtual ~CGameOptionCamera();                                       // 0x141248890
    virtual CString GetTypeName();                                      // 0x141249220
    virtual void vfunc_3(int n);                                    // 0x1412488c0
    virtual void vfunc_4(int n);                                    // 0x141248910
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg); // 0x141248940
    virtual void vfunc_6();                                         // 0x141248960 write the state into the UI
    virtual void vfunc_7();                                         // 0x141248c40 read the state back from the UI
    virtual void vfunc_10();                                        // 0x141248f10
    virtual void vfunc_12();                                        // 0x1412491c0
    virtual int vfunc_14();                                        // 0x141249270 differs from the saved settings

    Unk_CameraState m_state;                                       // +0x30 (ctor 0x14125b400)
};
MS2_CHECK_SIZE(CGameOptionCamera, 0x40);
