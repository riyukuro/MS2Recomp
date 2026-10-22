// Recovered UILoginNotice; header name and member names are inferred.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"

class Unk_LoginNoticeButton : public CPtred
{
public:
    void FUN_1422ce240(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& callback, int flags);
};

class UILoginNotice : public UIDialog
{
public:
    UILoginNotice();
    virtual ~UILoginNotice();
    virtual CString vfunc_1();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    void SendNoticeDialog();
    void FUN_140ea6540(const Scaleform::GFx::FunctionHandler::Params& params);
    virtual int vfunc_48() { return 20266; }
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_LoginNoticeButton> m_createButton;
};
MS2_CHECK_SIZE(UILoginNotice, 0x188);
MS2_CHECK_OFFSET(UILoginNotice, m_createButton, 0x178);
