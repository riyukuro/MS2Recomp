// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIStanceBar (RTTI .?AVUIStanceBar@@, 0x88 bytes), the HUD
// widget that shows the current combat stance. The unit has no __FILE__ string (the name "uistancebar.cpp" was rejected
// by the unit map), so it lives under unnamed/. Primary vftable 0x142ec55b8-ish (pinned by progress.py), IMessageListener
// at +0x18. Member names are invented where the exe has none (FUN_<va> otherwise).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/asdisplayobject.h"

// The (never dereferenced in this unit) AS child held at +0x70.
class Unk_StanceClip : public ASDisplayObject {};

// The pair handed to the start-stance AS call: members are passed to the movie in the order (m_b, m_a).
struct Unk_StanceInfo
{
    unsigned long m_a;                  // +0 (second AS argument)
    unsigned long m_b;                  // +4 (first AS argument)
};

class UIStanceBar : public UIHeadUpDisplay
{
public:
    UIStanceBar();                                                  // 0x140ba2180
    virtual ~UIStanceBar();                                         //  0 0x140ba2220 (??_G 0x140ba2910)
    virtual CString GetTypeName();                                      //  1 0x140ba2290 "StanceBar"
    virtual void vfunc_3();                                         //  3 0x140ba22e0 hide: reset the step
    virtual void vfunc_15();                                        // 15 0x140ba2380 empty
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ba2330
    virtual int vfunc_48() { return 20378; }                        // 48 0x140ba2950 UI type id

    void FUN_140ba2390(const Unk_StanceInfo* pInfo);                // start the stance
    void FUN_140ba23c0(const Unk_StanceInfo* pInfo);                // stop, then start
    void FUN_140ba2400();                                           // stop
    void FUN_140ba2420(unsigned long nTime);                        // updateTime
    void FUN_140ba2490(int nStep);                                  // updateStep
    void FUN_140ba2520(const Unk_StanceInfo* pInfo);                // startStance
    void FUN_140ba25c0();                                           // stopStance + mark stopped
    void FUN_140ba25f0();                                           // call stopStance when running
    void FUN_140ba2670();                                           // mark stopped
    void FUN_140ba26b0() {}                                         // empty
    void FUN_140ba26c0();                                           // empty (no caller; emitted as a COMDAT in the exe)

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_StanceClip> m_70;        // +0x70 (reset only)
    int m_80;                           // +0x80 current step (1 = first)
    bool m_84;                          // +0x84 stopped
};
MS2_CHECK_SIZE(UIStanceBar, 0x88);
MS2_CHECK_OFFSET(UIStanceBar, m_70, 0x70);
MS2_CHECK_OFFSET(UIStanceBar, m_80, 0x80);
MS2_CHECK_OFFSET(UIStanceBar, m_84, 0x84);
