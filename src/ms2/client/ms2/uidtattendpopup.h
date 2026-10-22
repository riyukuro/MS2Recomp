// DT attendance popup; supporting field and helper names are inferred.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"
#include <map>
class CInPacket; class GameEventVariable; class NotifyObject;
void FUN_14015b020(CPtred*); int FUN_140159bc0(CPtred*); void FUN_140159ba0(CPtred*);
template<class T> class Unk_DTPtr {
public:
 Unk_DTPtr(int):p(0){} Unk_DTPtr(const Unk_DTPtr& q):p(q.p){AddRef();}
 Unk_DTPtr(Unk_DTPtr&& q):p(q.p){q.p=0;} ~Unk_DTPtr(){Release();}
 T* get()const{return p;} T* operator->()const{return p;} bool operator==(T* q)const{return p==q;}
private:
 void AddRef()const{if(p)ReferenceImpl((void*)0);} static void Reference(T* q){FUN_14015b020(q);}
 void ReferenceImpl(void*)const{Reference(p);} void Release(){if(p){ReleaseImpl((void*)0);p=0;}}
 void ReleaseImpl(void*){if(FUN_140159bc0(p)==0){Reference(p);FUN_140159ba0(p);}}
 void* m_0;T* p;
};
class Unk_DTItemData;
class Unk_DTReward:public CPtred {};
class Unk_DTEntry:public CPtred {public:
 bool FUN_140ce3510();bool FUN_140ce35c0();unsigned FUN_140ce3690();unsigned FUN_140ce3660();unsigned FUN_140ce3a20();unsigned long FUN_1402e1d00();
 MS2Ptr<Unk_DTReward> FUN_140ce3710(unsigned);
};
class Unk_DTText:public ASDisplayObject {public:void FUN_1422c4cd0(const CStringW&);};
class Unk_DTIcon:public ASDisplayObject {public:void FUN_1409ba630(const Unk_DTItemData&);};
class Unk_DTTick {public:Unk_DTTick();int FUN_140268870(unsigned);private:unsigned __int64 m_tick;};
class UIDTAttendPopup:public UIDialog {
public:
 UIDTAttendPopup();virtual ~UIDTAttendPopup();virtual CString GetTypeName();virtual int vfunc_65();virtual void OnLoadComplete();virtual void vfunc_26();virtual void vfunc_72();
 // @0x140c07060
 virtual int vfunc_48(){return 0x4eba;}
 void AddEntry(Unk_DTPtr<Unk_DTEntry>);void RemoveEntry(Unk_DTPtr<Unk_DTEntry>);void RefreshVisibility();void UpdateIcon();void SetTime(unsigned);void Request();bool CanShow();
 void OnPacket(CInPacket&);void OnClick(const Scaleform::GFx::FunctionHandler::Params&);void OnEvent(GameEventVariable*);void OnNotify(NotifyObject*);Unk_DTPtr<Unk_DTEntry> GetCurrent();
private:
 MS2_LAYOUT_FRIEND;
 MS2Ptr<ASMovieClip> m_item;MS2Ptr<Unk_DTText> m_time;MS2Ptr<Unk_DTIcon> m_icon;
 std::map<unsigned long,Unk_DTPtr<Unk_DTEntry>> m_entries;Unk_DTTick m_tick,m_requestTick;
};
MS2_CHECK_SIZE(UIDTAttendPopup,0x1c8);
MS2_CHECK_OFFSET(UIDTAttendPopup,m_item,0x178);
MS2_CHECK_OFFSET(UIDTAttendPopup,m_entries,0x1a8);
MS2_CHECK_OFFSET(UIDTAttendPopup,m_tick,0x1b8);
