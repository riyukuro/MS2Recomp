// Recovered timer gauge and its base. Unk_ names are local reconstruction names.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/intervaltimer.h"
#include <map>
#include <utility>
class UITimerBase : public UIDialog {
public:UITimerBase();
 virtual ~UITimerBase();
 virtual CString GetTypeName()=0;   // _purecall in the exe vftable (0x142e691d8)
 virtual void vfunc_84(unsigned int,unsigned int,int);virtual void vfunc_85();virtual void vfunc_86();virtual void vfunc_87(unsigned long,unsigned int);
 unsigned int FUN_140edeba0();
protected:MS2_LAYOUT_FRIEND;unsigned int m_start,m_duration;int m_offset;
};
MS2_CHECK_SIZE(UITimerBase,0x188);
MS2_CHECK_OFFSET(UITimerBase,m_start,0x178);
class ASGaugeControl;class ASMovieClip;
class UITimerGaugeDialog : public UITimerBase {
public:UITimerGaugeDialog();virtual ~UITimerGaugeDialog();virtual CString GetTypeName();virtual void vfunc_72();virtual void OnLoadComplete();virtual void vfunc_26();virtual void vfunc_87(unsigned long,unsigned int);
 virtual int vfunc_48();
 void FUN_140edf1f0();void UpdateGauge();void UpdateLapEffects();void SetLapIconPosition(MS2Ptr<ASMovieClip>,unsigned int);void CreateLapIcons();
private:MS2_LAYOUT_FRIEND;
 Unk_IntervalTimer m_tick1,m_tick2;MS2Ptr<ASGaugeControl> m_gauge;
 typedef std::pair<MS2Ptr<ASMovieClip>,unsigned int> Lap;
 typedef std::map<unsigned long,Lap> Laps;
 Laps m_laps;
};
MS2_CHECK_SIZE(UITimerGaugeDialog,0x1b8);
MS2_CHECK_OFFSET(UITimerGaugeDialog,m_gauge,0x198);
MS2_CHECK_OFFSET(UITimerGaugeDialog,m_laps,0x1a8);
