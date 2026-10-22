// Cash attendance dialog (UICashAttendDialog) and its per-day gift list rows (UICashAttendGifList). RTTI names; member
// names are inferred from the AS child names and the event getters.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include <atlcoll.h>
#include <vector>
#include <map>
class CInPacket;
class CMsgBoxData;
class GameEventVariable;
class GameEventCashAttendCli;
class Unk_140acd6e0;
class ASMovieClip;
class Unk_CadCheck;
class ASItemSlot;
class ASGaugeControl;
class Unk_CadGiftClip;
class Unk_CadGiftList;
class UICashAttendDialog;

// One day row of the gift list ("m_giftList1".."m_giftList5"); 0x90 bytes.
class UICashAttendGifList : public CPtred {
public:
    UICashAttendGifList(UICashAttendDialog* pDialog, MS2Ptr<Unk_CadGiftClip> spClip);
    virtual ~UICashAttendGifList();
    void FUN_140bc2620(const Scaleform::GFx::FunctionHandler::Params& params);   // row clicked: show the day's rewards
    void FUN_140bc2b10();                                                        // clear the row
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_CadGiftClip> m_clip;                     // +0x18
    MS2Ptr<ASMovieClip> m_bg1;                          // +0x28
    MS2Ptr<ASMovieClip> m_bg2;                          // +0x38
    MS2Ptr<ASMovieClip> m_disabled;                     // +0x48
    UICashAttendDialog* m_pDialog;                      // +0x58
    std::vector<MS2Ptr<ASItemSlot> > m_rewardItems;     // +0x60
    std::vector<MS2Ptr<Unk_CadCheck> > m_checks;        // +0x78
};
MS2_CHECK_SIZE(UICashAttendGifList, 0x90);
MS2_CHECK_OFFSET(UICashAttendGifList, m_pDialog, 0x58);
MS2_CHECK_OFFSET(UICashAttendGifList, m_checks, 0x78);

class UICashAttendDialog : public UIDialog {
public:
    UICashAttendDialog();
    virtual ~UICashAttendDialog();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    // @0x140bccd60
    virtual int vfunc_48() { return 0x4eb9; }
    void FUN_140bc3db0(MS2Ptr<GameEventCashAttendCli> spEvent);     // add an event
    void FUN_140bc3eb0(MS2Ptr<GameEventCashAttendCli> spEvent);     // remove an event
    bool FUN_140bc4030();                                           // any active event
    int FUN_140bc4080();                                            // usable points summed over the events
    void FUN_140bc4150(const Scaleform::GFx::FunctionHandler::Params& params);   // event button clicked
    void FUN_140bc4230(const Scaleform::GFx::FunctionHandler::Params& params);   // use-point button clicked
    bool FUN_140bc4260(int nButton, const CMsgBoxData& data);
    void FUN_140bc4340(int nEventId);                               // select an event by id
    void FUN_140bc4390(GameEventVariable* pVar);
    void FUN_140bc43d0(GameEventVariable* pVar);
    MS2Ptr<GameEventCashAttendCli> GetSelected();                 // the selected event
    void FUN_140bc4460();                                           // refresh
    void FUN_140bc44b0();                                           // refresh the event buttons
    void FUN_140bc4980();                                           // refresh the gauge, list and period text
    void FUN_140bc4d40();                                           // refresh the use-point button
    void FUN_140bc4f00();                                           // rebuild the active events
    void FUN_140bc4ff0();                                           // pick the selected event
    void FUN_140bc5170(CInPacket& packet);
    void FUN_140bc5220(CInPacket& packet);
    void FUN_140bc5250(CInPacket& packet);
    void FUN_140bc5280(CInPacket& packet);
    void FUN_140bc5350(CInPacket& packet);
    void FUN_140bc5640();
    void FUN_140bc56a0();
    template<class T> MS2Ptr<T> FUN_140bc7070(const CString& strName, MS2Ptr<T>& out);
    template<class T> MS2Ptr<T> FUN_140bc6d10(const CString& strName, MS2Ptr<T>& out);
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_140acd6e0> m_usePointButton;                         // +0x178
    MS2Ptr<Unk_CadGiftList> m_giftList;                             // +0x188
    MS2Ptr<ASGaugeControl> m_progressGauge;                         // +0x198
    std::vector<MS2Ptr<UICashAttendGifList> > m_rows;               // +0x1a8
    std::map<unsigned long, MS2Ptr<GameEventCashAttendCli> > m_events;      // +0x1c0
    ATL::CAtlArray<MS2Ptr<GameEventCashAttendCli> > m_activeEvents; // +0x1d0
    ATL::CAtlArray<MS2Ptr<Unk_140acd6e0> > m_eventButtons;          // +0x1f0
    MS2Ptr<GameEventCashAttendCli> m_selected;                      // +0x210
    MS2Ptr<GameEventCashAttendCli> m_requested;                     // +0x220
    int m_eventId;                                                  // +0x230
};
MS2_CHECK_SIZE(UICashAttendDialog, 0x238);
MS2_CHECK_OFFSET(UICashAttendDialog, m_usePointButton, 0x178);
MS2_CHECK_OFFSET(UICashAttendDialog, m_events, 0x1c0);
MS2_CHECK_OFFSET(UICashAttendDialog, m_eventButtons, 0x1f0);
MS2_CHECK_OFFSET(UICashAttendDialog, m_eventId, 0x230);
