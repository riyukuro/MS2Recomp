// uiugccubenoticedialog.h - UIUGCCubeNoticeDialog (RTTI .?AVUIUGCCubeNoticeDialog@@, 0x190 bytes: UIDialog + the cube
// id, its message and the notice distance), the dialog where the owner of an UGC notice cube edits the message the
// cube shows and the distance at which it shows ("UGCCubeNoticeDialog", UI type 0x4f51). The server opens it with a
// packet (FUN_140faf900); "OnApply" reads the "m_textMessage" input and the "m_sliderDistance" slider, checks the
// message against the ban-text list and sends it. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit
// is `unit_140faf840` (0x140faf840-0x140fb0190 .text$mn). The class name is from RTTI; the header name is assumed.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h). Primary vftable plus the IMessageListener-in-UIUGCCubeNoticeDialog
// one at +0x18. Overridden slots: 1 (class name), 22 (OnLoadComplete: bind the drag bar / close button, push the
// data), 28 ("OnApply"), 48 (UI type 0x4f51).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class CInPacket;
struct Unk_NcInputRef;

class UIUGCCubeNoticeDialog : public UIDialog
{
public:
    UIUGCCubeNoticeDialog();                                        // 0x140faf840
    virtual ~UIUGCCubeNoticeDialog();                               //  0 0x140faf8a0 (??_G 0x140fb0020)
    virtual CString GetTypeName();                                      //  1 0x140faf9f0 "UGCCubeNoticeDialog"
    virtual void OnLoadComplete();                                  // 22 0x140fafa40
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140fafb60 "OnApply"
    virtual int vfunc_48();                                         // 48 0x140fb0060 UI type id
    void FUN_140faf900(CInPacket& packet);                          // 0x140faf900 open with the cube's data
    void OnApply();                                           // 0x140fafbd0 apply: check the message, send it, close
    Unk_NcInputRef FUN_140e35bd0(const CString& strName);           // 0x140e35bd0 the child input by name (a shared GetChild instance)
private:
    MS2_LAYOUT_FRIEND;
    int m_nCubeId;                  // +0x178 the cube the notice belongs to
    CStringW m_strMessage;          // +0x180 the notice text
    int m_nDistance;                // +0x188 the distance the notice shows at
};
MS2_CHECK_SIZE(UIUGCCubeNoticeDialog, 0x190);
MS2_CHECK_OFFSET(UIUGCCubeNoticeDialog, m_nCubeId, 0x178);
MS2_CHECK_OFFSET(UIUGCCubeNoticeDialog, m_strMessage, 0x180);
MS2_CHECK_OFFSET(UIUGCCubeNoticeDialog, m_nDistance, 0x188);
