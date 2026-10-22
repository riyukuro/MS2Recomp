// uiglobalportaldialog.h - UIGlobalPortalDialog (RTTI .?AVUIGlobalPortalDialog@@, 0x1e8 bytes, UIDialog, UI id 0x4ed7,
// swf "GlobalPortalDialog"): the "massive event" entrance notice. A server packet carries the event id, the notice
// text, a sound name and three enter-button captions; the three enter buttons ("m_enterButton1..3") send the enter
// request and the dialog closes itself when nothing is left to show. Owning unit: ?\uiglobalportaldialog.cpp
// (0x1412c2020-0x1412c3ac0, dir client\ms2); header name assumed from the unit path, member names invented.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"

class Unk_GpButton;
class CInPacket;

class UIGlobalPortalDialog : public UIDialog
{
public:
    UIGlobalPortalDialog();                                     // 0x1412c2020
    virtual ~UIGlobalPortalDialog();                            //  0 0x1412c2180 (??_G 0x1412c3940)
    virtual CString vfunc_1();                                  //  1 0x1412c22b0 "GlobalPortalDialog"
    virtual void OnLoadComplete();                              // 22 0x1412c2300 hook the buttons
    virtual void vfunc_43();                                    // 43 0x1412c2730 anchor the swf window
    virtual int vfunc_48() { return 0x4ed7; }                   // 48 0x1412c3980
    virtual void vfunc_67();                                    // 67 0x1412c27d0
    virtual void vfunc_72();                                    // 72 0x1412c2880 retry the delayed refresh

    void FUN_1412c2980();                                       // show the texts and the enter buttons
    void FUN_1412c3020(CInPacket& packet);                      // the server packet
    void SendGlobalPortal(const Scaleform::GFx::FunctionHandler::Params& params);   // an enter button was clicked
    void FUN_1412c3240(CInPacket& packet);                                    // the delayed refresh fired
    void FUN_1412c32a0(CInPacket& packet);                      // packet case 0: read the notice
    void FUN_1412c3640(CInPacket& packet);                      // packet case 1: the event is over

    MS2Ptr<Unk_GpButton> FUN_140bc6d10(const CString& strName, MS2Ptr<Unk_GpButton>& out);   // bind a button

private:
    MS2_LAYOUT_FRIEND;
    int m_nEventId;                                             // +0x178
    int m_nParam;                                               // +0x17c
    CStringW m_strText;                                         // +0x180
    CStringW m_strSound;                                        // +0x188
    CStringW m_strCaption1;                                     // +0x190
    CStringW m_strCaption2;                                     // +0x198
    CStringW m_strCaption3;                                     // +0x1a0
    MS2Ptr<Unk_GpButton> m_enterButton1;                        // +0x1a8
    MS2Ptr<Unk_GpButton> m_enterButton2;                        // +0x1b8
    MS2Ptr<Unk_GpButton> m_enterButton3;                        // +0x1c8
    int m_nShownEventId;                                        // +0x1d8
    int m_nShownParam;                                          // +0x1dc
    unsigned int m_nRetryTime;                                  // +0x1e0
};
MS2_CHECK_OFFSET(UIGlobalPortalDialog, m_nEventId, 0x178);
MS2_CHECK_OFFSET(UIGlobalPortalDialog, m_strText, 0x180);
MS2_CHECK_OFFSET(UIGlobalPortalDialog, m_enterButton1, 0x1a8);
MS2_CHECK_OFFSET(UIGlobalPortalDialog, m_nRetryTime, 0x1e0);
MS2_CHECK_SIZE(UIGlobalPortalDialog, 0x1e8);
