// gameoptiongraphicdefault.h - CGameOptionGraphicDefault (RTTI .?AVCGameOptionGraphicDefault@@, base CBaseOption, 0x78 bytes): the graphic tab (resolution, quality, effects).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the methods live in unit `client\ms2\gameoption.cpp`. Header and member names are
// assumed. Built by UIGameOptionDialog's ctor as tab id 6. State-block ctors are FUN_s in client\ms2\gameoptionstruct.cpp.
#pragma once
#include "ms2/client/ms2/baseoption.h"

struct Unk_GraphicState
{
    int m_nQuality;                                                 // +0x00 (default 3)
    int m_nResIdx;                                                  // +0x04 (default 0) the resolution row
    int m_nScreenMode;                                              // +0x08 (default 1) 1 window, 2 full window
    int m_n0c;                                                      // +0x0c (default 1)
    int m_nEffectStep;                                              // +0x10 (default 3)
    bool m_bShowFrameRate;                                          // +0x14 (default 0)
    bool m_b15;                                                     // +0x15 (default 0)
    bool m_bVsync;                                                  // +0x16 (default 1)
    bool m_bEnchantEffect;                                          // +0x17 (default 1)
    bool m_b18;                                                     // +0x18 (default 1)
    bool m_bHdr;                                                    // +0x19 (default 0)
    bool m_b1a;                                                     // +0x1a (default 0)
    bool m_b1b;                                                     // +0x1b (default 0)
    bool m_bShimmer;                                                // +0x1c (default 0)
    bool m_b1d;                                                     // +0x1d (default 1)
    bool m_b1e;                                                     // +0x1e (default 1)
    bool m_b1f;                                                     // +0x1f (default 1); see ctor 0x14125d8c0
    int m_nShadow;                                                  // +0x20 (default 2)
    int m_nWidth;                                                   // +0x24 (default 0x400)
    int m_nHeight;                                                  // +0x28 (default 0x300)
    int m_nMultisampling;                                           // +0x2c (default 0)
};
MS2_CHECK_SIZE(Unk_GraphicState, 0x30);

struct Unk_GraphicState2
{
    int m_nOptimalHide;                                             // +0x00 (default 0)
    bool m_bHideAlways;                                             // +0x04 (default 1)
    bool m_bHideBossBattle;                                         // +0x05 (default 0)
    bool m_bShowGuild;                                              // +0x06 (default 0)
    bool m_bShowParty;                                              // +0x07 (default 0)
    bool m_bShowCustom;                                             // +0x08 (default 0)
    int m_nCustomInput;                                             // +0x0c (default 0)
    bool m_b10;                                                     // +0x10 (default 1)
    bool m_bShowPhysx;                                              // +0x11 (default 0)
};
MS2_CHECK_SIZE(Unk_GraphicState2, 0x14);

class CGameOptionGraphicDefault : public CBaseOption
{
public:
    CGameOptionGraphicDefault(int nId, int nType);                // 0x14124ab30
    virtual ~CGameOptionGraphicDefault();                     // 0x14124abb0
    virtual CString GetTypeName();                                     // 0x14124d840
    virtual void vfunc_3(int n);                                   // 0x14124abe0
    virtual void vfunc_4(int n);                                   // 0x14124ac60
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg);// 0x14124ac90
    virtual void vfunc_6();                                        // 0x14124aff0
    virtual void vfunc_7();                                        // 0x14124bf20
    virtual void vfunc_10();                                       // 0x14124d6a0
    virtual void vfunc_12();                                       // 0x14124d7a0
    virtual int vfunc_14();                                       // 0x14124d890

    void FUN_14124ce20();                                           // apply the page to the live graphic options
    void FUN_14124d080();                                           // fill the m_resolution combo
    void FUN_14124d5f0(int nIndex, int* pnWidth, int* pnHeight);   // the size of the nIndex-th display mode

    Unk_GraphicState m_state;                                       // +0x30 (ctor 0x14125d890)
    Unk_GraphicState2 m_state2;                                     // +0x60 (ctor 0x14125ec20)
    int m_n74;                                                      // +0x74 (default 0)
};
MS2_CHECK_SIZE(CGameOptionGraphicDefault, 0x78);
