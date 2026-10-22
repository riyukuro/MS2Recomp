// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicastingbar.h (name assumed: the
// class name; the exe has no assert path for it).
//
// UICastingBar is the cast gauge HUD (UI type 0x4e72, "CastingBar"): it shows up to two caption lines and two time
// lines while a cast runs, and calls back the caster when the movie reports "OnCastingComplete" (or the cast is
// replaced). RTTI .?AVUICastingBar@@, 0x108 bytes, vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; members are invented from their use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiheadupdisplay.h"

class ASTextField;

// What the caster implements: slot 0 runs when the gauge completes, slot 1 when the cast is replaced.
class Unk_CastingListener
{
public:
    virtual void vfunc_0() = 0;
    virtual void vfunc_1() = 0;
};

// The arguments of one cast (0x38 bytes; ctor 0x140ac2eb0, dtor 0x140ac3070).
struct Unk_CastingParam
{
    Unk_CastingParam() : m_nDuration(0), m_bShowTime(false), m_bActive(true), m_fStart(0.0f), m_fScale(1.0f), m_n10(0) {}
    int m_nDuration;                                                // +0x00 gauge time in ms
    bool m_bShowTime;                                               // +0x04 show the two time lines
    bool m_bActive;                                                 // +0x05
    float m_fStart;                                                 // +0x08
    float m_fScale;                                                 // +0x0c
    int m_n10;                                                      // +0x10
    CStringW m_str18;                                               // +0x18 caption 1
    CStringW m_str20;                                               // +0x20 caption 2
    CStringW m_str28;                                               // +0x28
    CStringW m_str30;                                               // +0x30 text shown when the cast ends
};
MS2_CHECK_SIZE(Unk_CastingParam, 0x38);

class UICastingBar : public UIHeadUpDisplay
{
public:
    UICastingBar();                                                 // 0x1418e0f10
    virtual ~UICastingBar();                                        //  0 0x1418e1030 (??_G 0x1418e1f30)
    virtual CString GetTypeName();                                      //  1 0x1418e1100 "CastingBar"
    virtual void vfunc_3();                                         //  3 0x1418e1150 hide: drop the cast
    virtual void vfunc_15();                                        // 15 0x1418e1260 per-frame: timer expired -> stop
    virtual void OnLoadComplete();                                  // 22 0x1418e11d0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                    // 28 0x1418e11f0 "OnCastingComplete"
    virtual int vfunc_48();                                         // 48 0x1418e1f70

    void FUN_1418e12b0(Unk_CastingListener* pListener, const Unk_CastingParam* pParam);   // 0x1418e12b0 start a cast
    void FUN_1418e12f0(Unk_CastingListener* pListener, const CStringW& strText, int nDuration, bool bShowTime,
        bool bActive, const CStringW& strEnd);                      // 0x1418e12f0 start a cast from loose arguments
    void FUN_1418e1390();                                           // 0x1418e1390 stop with the end text
    void FUN_1418e13c0(Unk_CastingListener* pListener, const Unk_CastingParam* pParam);   // 0x1418e13c0 stop, start a new cast
    void FUN_1418e1400(const CStringW& strText);                    // 0x1418e1400 set both caption lines
    void FUN_1418e14b0(const CStringW& strText);                    // 0x1418e14b0 set both time lines
    void FUN_1418e1560(float fValue);                               // 0x1418e1560 movie "updateValue"
    void FUN_1418e15d0(Unk_CastingListener* pListener, const Unk_CastingParam* pParam);   // 0x1418e15d0 start the cast
    void FUN_1418e18a0(const CStringW& strText);                    // 0x1418e18a0 stopCasting + reset
    void FUN_1418e18e0(const CStringW& strText);                    // 0x1418e18e0 movie "stopCasting"
    void FUN_1418e19c0(const CStringW& strText);                    // 0x1418e19c0 stopCasting + completed callback
    void OnCastingComplete();                                           // 0x1418e1a00 completed callback + reset
    void FUN_1418e1a50();                                           // 0x1418e1a50 reset
    void FUN_1418e1ab0();                                           // 0x1418e1ab0 drop the text fields
    void FUN_1418e1b20(bool bShowTime);                             // 0x1418e1b20 bind the text fields
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);      // 0x140bb4cf0 text field child lookup
    Unk_CastingListener* FUN_1417f5e90() { return m_pListener; }   // 0x1417f5e90 (COMDAT in stateskill.obj)
    // @0x1417f5f90
    int FUN_1417f5f90() { return m_timer.FUN_140868ba0(); }          // a cast is running (COMDAT in stateskill.obj)

    Unk_CastingListener* m_pListener;                               // +0x70 the caster
    MS2Ptr<ASTextField> m_spText1;                                  // +0x78 "m_text1"
    MS2Ptr<ASTextField> m_spText2;                                  // +0x88 "m_text2"
    MS2Ptr<ASTextField> m_spTime1;                                  // +0x98 "m_timetext1"
    MS2Ptr<ASTextField> m_spTime2;                                  // +0xa8 "m_timetext2"
    bool m_bActive;                                                 // +0xb8
    CStringW m_strEnd;                                              // +0xc0 text shown when the cast ends
    bool m_bFinished;                                               // +0xc8
    Timer m_timer;                                                  // +0xd0
};
MS2_CHECK_SIZE(UICastingBar, 0x108);
