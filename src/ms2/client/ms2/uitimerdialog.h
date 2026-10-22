// Recovered timer dialog (the countdown dialog with the low-time effect). UITimerBase lives in
// uitimergaugedialog.h. Unk_ names are local reconstruction names.
#pragma once
#include "uitimergaugedialog.h"
class UITimerDialog : public UITimerBase {
public:UITimerDialog();
 virtual ~UITimerDialog();
 virtual CString GetTypeName();
 virtual void vfunc_72();
 virtual void OnLoadComplete();
 virtual void vfunc_26();
 virtual void vfunc_84(unsigned int,unsigned int,int);
 virtual void vfunc_85();
 virtual void vfunc_86();
 virtual int vfunc_48();
 void FUN_141b26bf0();
 bool FUN_141b26c50(int& nMin,int& nSec);
private:MS2_LAYOUT_FRIEND;
 int m_nEffectRunning;          // +0x188 effect request is live
 unsigned int m_nEffect;        // +0x18c the effect id (0 = none)
 Unk_TimerTick m_tick;          // +0x190 100ms tick
 unsigned int m_nMin;           // +0x198 last shown minutes
 unsigned int m_nSec;           // +0x19c last shown seconds
 bool m_bReset;                 // +0x1a0 the next update must reset the swf clock
};
MS2_CHECK_SIZE(UITimerDialog,0x1a8);
MS2_CHECK_OFFSET(UITimerDialog,m_nEffect,0x18c);
MS2_CHECK_OFFSET(UITimerDialog,m_tick,0x190);
MS2_CHECK_OFFSET(UITimerDialog,m_nMin,0x198);
MS2_CHECK_OFFSET(UITimerDialog,m_bReset,0x1a0);
