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
// C3: the event holder is MS2Ptr<GameEventAttendGiftCli> (was the stand-in Unk_DTPtr(Unk_DTEntry); the same COMDATs as
// uiattendgiftdialog's former Unk_14102fe10<Unk_140ce3510>: 0x140c06790.. and AddRef 0x140c07070). The generic MS2Ptr
// bodies (ms2ptr_impl.h) are the stand-in's: AddRef -> AddRefImpl -> Reference -> CPtred::AddRefPtred, Release -> ReleaseImpl.
//
//
//
//
//
//
//
//
class GameEventAttendGiftCli;class ASItemSlot;
class UIDTAttendPopup:public UIDialog {
public:
 UIDTAttendPopup();virtual ~UIDTAttendPopup();virtual CString GetTypeName();virtual int vfunc_65();virtual void OnLoadComplete();virtual void vfunc_26();virtual void vfunc_72();
 // @0x140c07060
 virtual int vfunc_48(){return 0x4eba;}
 void AddEntry(MS2Ptr<GameEventAttendGiftCli>);void RemoveEntry(MS2Ptr<GameEventAttendGiftCli>);void RefreshVisibility();void UpdateIcon();void SetTime(unsigned);void Request();bool CanShow();
 void OnPacket(CInPacket&);void OnClick(const Scaleform::GFx::FunctionHandler::Params&);void OnEvent(GameEventVariable*);void OnNotify(NotifyObject*);MS2Ptr<GameEventAttendGiftCli> GetCurrent();
private:
 MS2_LAYOUT_FRIEND;
 MS2Ptr<ASMovieClip> m_item;MS2Ptr<ASTextField> m_time;MS2Ptr<ASItemSlot> m_icon;
 std::map<unsigned long,MS2Ptr<GameEventAttendGiftCli>> m_entries;Unk_IntervalTimer m_tick,m_requestTick;
};
MS2_CHECK_SIZE(UIDTAttendPopup,0x1c8);
MS2_CHECK_OFFSET(UIDTAttendPopup,m_item,0x178);
MS2_CHECK_OFFSET(UIDTAttendPopup,m_entries,0x1a8);
MS2_CHECK_OFFSET(UIDTAttendPopup,m_tick,0x1b8);
