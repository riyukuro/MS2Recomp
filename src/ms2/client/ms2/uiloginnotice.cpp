// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Login notice dialog.
// MS2-UNIT: client\ms2\uiloginnotice.cpp
// MS2-RANGE: 0x140ea60c0-0x140ea6ee0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiloginnotice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiloginnotice.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

class Unk_LoginNoticeManager
{
public:
    void FUN_141adc530(int id);
};
Unk_LoginNoticeManager* FUN_1403ed2b0();

// @0x140ea60c0
UILoginNotice::UILoginNotice()
{
    m_80 = 0;
}

// @0x140ea6130
UILoginNotice::~UILoginNotice()
{
}

// @0x140ea6180
CString UILoginNotice::GetTypeName()
{
    return "LoginNotice";
}
MS2_REPLACE_METHOD(0x140EA6180, UILoginNotice, GetTypeName, 61, 0xEBD8DB21);

// @0x140ea61d0
void UILoginNotice::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141925ec0("m_closeButton");
    do {
        m_30->FUN_140bbe640("m_createButton", m_createButton);
        if (m_createButton == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                      MS2_THIS_FILE, MS2_LINE(26), __FUNCTION__));
    } while (0);
    if (m_createButton.get())
        m_createButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UILoginNotice::FUN_140ea6540), 0);
    SendNoticeDialog();
}
MS2_REPLACE_METHOD(0x140EA61D0, UILoginNotice, OnLoadComplete, 701, 0x7ECEAA69);

// @0x140ea64c0
void UILoginNotice::vfunc_26()
{
    UIDialog::vfunc_26();
}
MS2_REPLACE_METHOD(0x140EA64C0, UILoginNotice, vfunc_26, 24, 0x7B77F63F);

// @0x140ea64e0
void UILoginNotice::SendNoticeDialog()
{
    COutPacket packet(static_cast<int>(SendOp::NoticeDialog), 0);
    packet.Encode1(1);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140EA64E0, UILoginNotice, SendNoticeDialog, 75, 0x259671C9);

// @0x140ea6540
void UILoginNotice::FUN_140ea6540(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_1403ed2b0()->FUN_141adc530(0x4eea);
    vfunc_67();
}
MS2_REPLACE_METHOD(0x140EA6540, UILoginNotice, FUN_140ea6540, 56, 0xEDADAC40);

MS2_EMIT_CRT_MEMMOVE_S();
