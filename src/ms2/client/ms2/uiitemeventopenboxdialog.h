// uiitemeventopenboxdialog.h - UIItemEventOpenBoxDialog (RTTI .?AVUIItemEventOpenBoxDialog@@, 0x1f0 bytes, UIDialog, UI
// id 0x4f42, swf "ItemEventOpenBoxDialog"): the dialog of the item box event (GameEventItemBox). It shows the event's
// title / name / description and the reward box item for the field the player stands in, and its request button sends
// packet 0x97 (rate limited) to open the box; the server answers with packet 0xf7. Owning unit:
// ?\uiitemeventopenboxdialog.cpp. Header name assumed from the unit path; member names are inferred.
// gameevent.cpp carries a unit-local stub of this class (only FUN_140e48050 declared).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"

class ASTextField;
class ASUIComponent;
class CInPacket;
class NotifyObject;
class Unk_140acd6e0;

class UIItemEventOpenBoxDialog : public UIDialog
{
public:
    UIItemEventOpenBoxDialog();                                 // 0x140e47540
    virtual ~UIItemEventOpenBoxDialog();                        //  0 0x140e477f0 (??_G 0x140e492d0)
    virtual CString GetTypeName();                                  //  1 0x140e47a50 "ItemEventOpenBoxDialog"
    virtual void OnLoadComplete();                              // 22 0x140e47b40 bind the children and the request button
    virtual int vfunc_48() { return 0x4f42; }                   // 48 0x140e49310
    virtual void vfunc_67();                                    // 67 0x140e47aa0 Close: drop the bound item and the children

    void FUN_140e47f10(CInPacket& iPacket);                     // 0x140e47f10 handler of packet 0xf7 (the open request answer)
    void FUN_140e48020(NotifyObject* pNotify);                  // 0x140e48020 "NotifyCompleteMyPC": refresh
    void FUN_140e48050();                                       // 0x140e48050 reload the event of the current field (GameEventItemBox::vfunc_5)
    void FUN_140e483b0();                                       // 0x140e483b0 show the event texts and the box item
    void SendEventReward(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x140e48600 request button: send packet 0x97
    CString FUN_140e48770(unsigned nItemId);                    // 0x140e48770 bind the box item under "<class>_<id>"; "" when it is unknown
    void FUN_140e48990();                                       // 0x140e48990 drop the bound item
    MS2Ptr<Unk_140acd6e0> FUN_140bc6d10(const CString& strName, MS2Ptr<Unk_140acd6e0>& out);   // 0x140bc6d10 bind a button child

private:
    MS2_LAYOUT_FRIEND;
    // The "child lookup, remember, return a copy" helpers of OnLoadComplete (inline COMDATs 0x140e48d80 / 0x140e48e10).
    template <class T> MS2Ptr<T> GetChildInto(const CString& strName, MS2Ptr<T>& out) { out = GetChild<T>(strName); return out; }

    int m_178;                          // +0x178 the box item id of the event (ItemBoxEventContext::m_boxItemID)
    CStringW m_180;                     // +0x180 event title
    CStringW m_188;                     // +0x188 event description
    CString m_190;                      // +0x190 banner path ("LoadImage")
    MS2Ptr<ASTextField> m_198;          // +0x198 "m_title"
    MS2Ptr<ASTextField> m_1a8;          // +0x1a8 "m_eventName"
    MS2Ptr<ASTextField> m_1b8;          // +0x1b8 "m_eventDesc"
    MS2Ptr<Unk_140acd6e0> m_1c8;        // +0x1c8 "m_requestButton"
    MS2Ptr<ASUIComponent> m_1d8;        // +0x1d8 "m_slot" (the box item slot)
    CString m_1e8;                      // +0x1e8 the name the box item is bound under
};
MS2_CHECK_SIZE(UIItemEventOpenBoxDialog, 0x1f0);
MS2_CHECK_OFFSET(UIItemEventOpenBoxDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIItemEventOpenBoxDialog, m_180, 0x180);
MS2_CHECK_OFFSET(UIItemEventOpenBoxDialog, m_198, 0x198);
MS2_CHECK_OFFSET(UIItemEventOpenBoxDialog, m_1c8, 0x1c8);
MS2_CHECK_OFFSET(UIItemEventOpenBoxDialog, m_1d8, 0x1d8);
MS2_CHECK_OFFSET(UIItemEventOpenBoxDialog, m_1e8, 0x1e8);
