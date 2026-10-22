// uiweddinginvitationdialog.h - UIWeddingInvitationDialog (RTTI .?AVUIWeddingInvitationDialog@@, 0x190 bytes, UIDialog,
// UI id 0x4f8e, swf "WeddingInvitationDialog"): the invitation card of the own wedding. It shows the couple, the hall and
// the date, takes the guests picked in the guest dialog (0x4f94) and sends the invitations after a confirm box.
// Owning unit: ?\uiweddinginvitationdialog.cpp. Header name assumed from the unit path; member names are invented.
#pragma once
#include <afx.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class Unk_WiGuest;
class CMsgBoxData;

class UIWeddingInvitationDialog : public UIDialog
{
public:
    typedef MS2Ptr<Unk_WiGuest> GuestPtr;

    UIWeddingInvitationDialog();                                // 0x140fe5780
    virtual ~UIWeddingInvitationDialog();                       //  0 0x140fe5810 (??_G 0x140fe6f40)
    virtual CString GetTypeName();                                  //  1 0x140fe5860 "WeddingInvitationDialog"
    virtual void OnLoadComplete();                              // 22 0x140fe5a70 "setData": couple, hall, date
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140fe5ce0 onClickPopup / onClickSend
    virtual void vfunc_43();                                    // 43 0x140fe5940 dock beside the character window
    virtual int vfunc_48() { return 0x4f8e; }                   // 48 0x140fe6f80
    virtual int vfunc_65();                                     // 65 0x140fe58b0
    virtual void vfunc_67();                                    // 67 0x140fe58e0 close: forget the guests

    void FUN_140fe5f20(const std::vector<GuestPtr>& guests);    // 0x140fe5f20 take the guests, "setReceiver"
    size_t FUN_140fe60a0();                                     // 0x140fe60a0 number of guests
    bool FUN_140fe60d0(int nResult, const CMsgBoxData& box);    // 0x140fe60d0 send confirmed

private:
    MS2_LAYOUT_FRIEND;
    std::vector<GuestPtr> m_guests;                             // +0x178
};
MS2_CHECK_SIZE(UIWeddingInvitationDialog, 0x190);
MS2_CHECK_OFFSET(UIWeddingInvitationDialog, m_guests, 0x178);
