// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Timer gauge and lap icons.
// MS2-UNIT: client\ms2\uitimergaugedialog.cpp
// MS2-RANGE: 0x140edea60-0x140ee2190 .text$mn
// MS2-PIN: ??_GUITimerBase@@UEAAPEAXI@Z 0x140edebf0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitimergaugedialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uitimergaugedialog.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
class Unk_TimerGauge {public:void FUN_1409b9f60(unsigned int,unsigned int);};
class Unk_TimerClip : public AScript {
public:Unk_TimerClip(CString,int);
 void FUN_1422c0060(int,int);const Scaleform::GFx::Value& FUN_1422bb890()const;
private:void* m_40;void* m_48;void* m_50;void* m_58;void* m_60;void* m_68;void* m_70;void* m_78;
};
MS2_CHECK_SIZE(Unk_TimerClip,0x80);
class Unk_TimerAS {public:Unk_TimerPtr<Unk_TimerGauge> FUN_140bc6e60(const CString&,Unk_TimerPtr<Unk_TimerGauge>&);Scaleform::GFx::Value FUN_1422c6900(Scaleform::GFx::Value);};
CString FUN_140bc6280(const char*,const char*,const char*,const int&,const char*);
void FUN_140cff840(const Scaleform::GFx::Value&,CString,int);
extern void* g_timerPlayer;
class Unk_TimerPlayer {public:static void* Get(){return g_timerPlayer;}};
unsigned int FUN_141472bc0();
// The leaf was recovered first, before implementing this base.
// @0x140edea60
UITimerBase::UITimerBase():m_start(0),m_duration(0),m_offset(0){}
// @0x140edead0
UITimerBase::~UITimerBase(){}
// @0x140edeb10
void UITimerBase::vfunc_84(unsigned int start,unsigned int duration,int offset){m_start=start;m_duration=duration;m_offset=offset;}
MS2_REPLACE_METHOD(0x140EDEB10, UITimerBase, vfunc_84, 65, 0x6AE83F70);

// @0x140edeb60
void UITimerBase::vfunc_85(){}
MS2_REPLACE_METHOD(0x140EDEB60, UITimerBase, vfunc_85, 6, 0xA9AF6E37);

// @0x140edeb70
void UITimerBase::vfunc_86(){}
MS2_REPLACE_METHOD(0x140EDEB70, UITimerBase, vfunc_86, 6, 0xA9AF6E37);

// @0x140edeb80
void UITimerBase::vfunc_87(unsigned long,unsigned int){}
MS2_REPLACE_METHOD(0x140EDEB80, UITimerBase, vfunc_87, 15, 0xA92F4169);

// @0x140edeba0
unsigned int UITimerBase::FUN_140edeba0(){unsigned int now=FUN_141472bc0();if(m_offset>0)now+=m_offset*1000;return now;}
MS2_REPLACE_METHOD(0x140EDEBA0, UITimerBase, FUN_140edeba0, 68, 0x45EC88D5);

// @0x140edec30
UITimerGaugeDialog::UITimerGaugeDialog(){m_2c=19;m_80=0;FUN_141925e70(0,1);}
// @0x140eded00
UITimerGaugeDialog::~UITimerGaugeDialog(){}
// @0x140eded70
CString UITimerGaugeDialog::GetTypeName(){return "TimerGaugeDialog";}
MS2_REPLACE_METHOD(0x140EDED70, UITimerGaugeDialog, GetTypeName, 61, 0x19138386);

// @0x140ededc0
void UITimerGaugeDialog::vfunc_72(){UIDialog::vfunc_72();if(!Unk_TimerPlayer::Get())return;if(m_tick1.FUN_140268870(500))FUN_140edf200();if(m_tick2.FUN_140268870(1000))FUN_140edf2b0();}
MS2_REPLACE_METHOD(0x140EDEDC0, UITimerGaugeDialog, vfunc_72, 112, 0x2BE0909E);

// @0x140edee40
void UITimerGaugeDialog::OnLoadComplete(){UIDialog::OnLoadComplete();do { reinterpret_cast<Unk_TimerAS*>(m_30.operator->())->FUN_140bc6e60("m_gauge",m_gauge);
 if(m_gauge==0)throw new GfxExceptionSwfLoad(FUN_140bc6280("GfxError:{0} {1}({2}) function:{3}","SwfLoadError",MS2_THIS_FILE,43,__FUNCTION__)); } while(0);
 FUN_140edf530();}
MS2_REPLACE_METHOD(0x140EDEE40, UITimerGaugeDialog, OnLoadComplete, 421, 0xE564040C);

// @0x140edf010
void UITimerGaugeDialog::vfunc_26(){UIDialog::vfunc_26();m_gauge=0;m_laps.clear();}
MS2_REPLACE_METHOD(0x140EDF010, UITimerGaugeDialog, vfunc_26, 64, 0x6A541429);

// @0x140edf060
void UITimerGaugeDialog::vfunc_87(unsigned long id,unsigned int time){
 Laps::iterator it=m_laps.find(id);
 if(it!=m_laps.end()) {Lap& lap=it->second;lap.second=time;if(lap.first.get())FUN_140edf480(lap.first,lap.second);}
 else {Lap lap(0,time);m_laps.insert(std::make_pair(id,lap));FUN_140edf530();}
}
MS2_REPLACE_METHOD(0x140EDF060, UITimerGaugeDialog, vfunc_87, 386, 0xA1776F12);

// @0x140edf1f0
void UITimerGaugeDialog::FUN_140edf1f0(){}
MS2_REPLACE_METHOD(0x140EDF1F0, UITimerGaugeDialog, FUN_140edf1f0, 6, 0xA9AF6E37);

// @0x140edf200
void UITimerGaugeDialog::FUN_140edf200(){if(m_gauge==0)return;unsigned int elapsed=0;unsigned int duration=m_duration;unsigned int now=FUN_140edeba0();if(now>m_start)elapsed=now-m_start;m_gauge->FUN_1409b9f60(elapsed,duration);}
MS2_REPLACE_METHOD(0x140EDF200, UITimerGaugeDialog, FUN_140edf200, 157, 0x3724050C);

// @0x140edf2b0
void UITimerGaugeDialog::FUN_140edf2b0(){
 if(m_30==0)return;if(m_laps.empty())return;unsigned int now=FUN_140edeba0();if(m_start>now)return;unsigned int elapsed=now-m_start;
 for(Laps::iterator it=m_laps.begin();it!=m_laps.end();it++) {
 Lap& lap=it->second;if(lap.first==0)continue;
 bool active=false;if(elapsed<lap.second&&lap.second-elapsed<30000)active=true;
 FUN_140cff840((*lap.first).FUN_1422bb890(),"m_activateEffect",active);
 }
}
MS2_REPLACE_METHOD(0x140EDF2B0, UITimerGaugeDialog, FUN_140edf2b0, 450, 0xF7B3D086);

// @0x140edf480
void UITimerGaugeDialog::FUN_140edf480(Unk_TimerPtr<Unk_TimerClip> clip,unsigned int time){if(m_duration==0)return;double ratio=static_cast<double>(time)/static_cast<double>(m_duration);double x=678.0*ratio;clip->FUN_1422c0060(static_cast<unsigned int>(x),0);}
MS2_REPLACE_METHOD(0x140EDF480, UITimerGaugeDialog, FUN_140edf480, 163, 0x31FC9BEF);

// @0x140edf530
void UITimerGaugeDialog::FUN_140edf530(){
 if(*reinterpret_cast<Unk_TimerPtr<Unk_TimerAS>*>(&m_90)==0)return;CString symbol="UITimerGaugeLapIcon";
 for(Laps::iterator it=m_laps.begin();it!=m_laps.end();it++) {
 Lap& lap=it->second;if(lap.first.get())continue;
 lap.first=new Unk_TimerClip(symbol,2);reinterpret_cast<Unk_TimerPtr<Unk_TimerAS>*>(&m_90)->operator->()->FUN_1422c6900((*lap.first).FUN_1422bb890());
 FUN_140cff840((*lap.first).FUN_1422bb890(),"m_activateEffect",false);FUN_140edf480(lap.first,lap.second);
 }
}
MS2_REPLACE_METHOD(0x140EDF530, UITimerGaugeDialog, FUN_140edf530, 658, 0x4E9FAE33);

// @0x140ee0d20
inline int UITimerGaugeDialog::vfunc_48(){return 20321;}

MS2_EMIT_CRT_MEMMOVE_S();
