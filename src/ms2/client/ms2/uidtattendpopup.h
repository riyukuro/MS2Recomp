// DT attendance popup; supporting field and helper names are inferred.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/intervaltimer.h"
#include <map>
class CInPacket; class GameEventVariable; class NotifyObject;
template<class T> class Unk_DTPtr {
public:
 Unk_DTPtr(int):p(0){} Unk_DTPtr(const Unk_DTPtr& q):p(q.p){AddRef();}
 Unk_DTPtr(Unk_DTPtr&& q):p(q.p){q.p=0;} ~Unk_DTPtr(){Release();}
 T* get()const{return p;} T* operator->()const{return p;} bool operator==(T* q)const{return p==q;}
private:
 void AddRef()const{if(p)ReferenceImpl((void*)0);} static void Reference(T* q){CPtred::AddRefPtred(q);}
 void ReferenceImpl(void*)const{Reference(p);} void Release(){if(p){ReleaseImpl((void*)0);p=0;}}
 void ReleaseImpl(void*){if(CPtred::ReleasePtred(p)==0){Reference(p);CPtred::DeletePtred(p);}}
 void* m_0;T* p;
};
class Unk_DTEntry;class ASItemSlot;
class UIDTAttendPopup:public UIDialog {
public:
 UIDTAttendPopup();virtual ~UIDTAttendPopup();virtual CString GetTypeName();virtual int vfunc_65();virtual void OnLoadComplete();virtual void vfunc_26();virtual void vfunc_72();
 // @0x140c07060
 virtual int vfunc_48(){return 0x4eba;}
 void AddEntry(Unk_DTPtr<Unk_DTEntry>);void RemoveEntry(Unk_DTPtr<Unk_DTEntry>);void RefreshVisibility();void UpdateIcon();void SetTime(unsigned);void Request();bool CanShow();
 void OnPacket(CInPacket&);void OnClick(const Scaleform::GFx::FunctionHandler::Params&);void OnEvent(GameEventVariable*);void OnNotify(NotifyObject*);Unk_DTPtr<Unk_DTEntry> GetCurrent();
private:
 MS2_LAYOUT_FRIEND;
 MS2Ptr<ASMovieClip> m_item;MS2Ptr<ASTextField> m_time;MS2Ptr<ASItemSlot> m_icon;
 std::map<unsigned long,Unk_DTPtr<Unk_DTEntry>> m_entries;Unk_IntervalTimer m_tick,m_requestTick;
};
MS2_CHECK_SIZE(UIDTAttendPopup,0x1c8);
MS2_CHECK_OFFSET(UIDTAttendPopup,m_item,0x178);
MS2_CHECK_OFFSET(UIDTAttendPopup,m_entries,0x1a8);
MS2_CHECK_OFFSET(UIDTAttendPopup,m_tick,0x1b8);
