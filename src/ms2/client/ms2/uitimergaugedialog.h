// Recovered timer gauge and its base. Unk_ names are local reconstruction names.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include <map>
#include <utility>
class UITimerBase : public UIDialog {
public:UITimerBase();
 virtual ~UITimerBase();
 virtual void vfunc_84(unsigned int,unsigned int,int);virtual void vfunc_85();virtual void vfunc_86();virtual void vfunc_87(unsigned long,unsigned int);
 unsigned int FUN_140edeba0();
protected:MS2_LAYOUT_FRIEND;unsigned int m_start,m_duration;int m_offset;
};
MS2_CHECK_SIZE(UITimerBase,0x188);
MS2_CHECK_OFFSET(UITimerBase,m_start,0x178);
class Unk_TimerTick {public:Unk_TimerTick();int FUN_140268870(int);private:__int64 m_tick;};
class Unk_TimerGauge;class Unk_TimerClip;
template<class T>class Unk_TimerPtr {
public:Unk_TimerPtr();Unk_TimerPtr(int);Unk_TimerPtr(T*);Unk_TimerPtr(const Unk_TimerPtr&);Unk_TimerPtr(Unk_TimerPtr&&);~Unk_TimerPtr();
 Unk_TimerPtr& operator=(int);
 Unk_TimerPtr& operator=(T* p){Unk_TimerPtr tmp(p);T* old=m_p;m_p=tmp.m_p;tmp.m_p=old;return *this;}
 bool operator==(T*)const;T* get()const;T* operator->()const;T& operator*()const;
private:void* m_0;T* m_p;
};
class UITimerGaugeDialog : public UITimerBase {
public:UITimerGaugeDialog();virtual ~UITimerGaugeDialog();virtual CString GetTypeName();virtual void vfunc_72();virtual void OnLoadComplete();virtual void vfunc_26();virtual void vfunc_87(unsigned long,unsigned int);
 virtual int vfunc_48();
 void FUN_140edf1f0();void FUN_140edf200();void FUN_140edf2b0();void FUN_140edf480(Unk_TimerPtr<Unk_TimerClip>,unsigned int);void FUN_140edf530();
private:MS2_LAYOUT_FRIEND;
 Unk_TimerTick m_tick1,m_tick2;Unk_TimerPtr<Unk_TimerGauge> m_gauge;
 typedef std::pair<Unk_TimerPtr<Unk_TimerClip>,unsigned int> Lap;
 typedef std::map<unsigned long,Lap> Laps;
 Laps m_laps;
};
MS2_CHECK_SIZE(UITimerGaugeDialog,0x1b8);
MS2_CHECK_OFFSET(UITimerGaugeDialog,m_gauge,0x198);
MS2_CHECK_OFFSET(UITimerGaugeDialog,m_laps,0x1a8);
