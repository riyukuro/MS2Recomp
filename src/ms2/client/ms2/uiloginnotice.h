// Recovered UILoginNotice; header name and member names are inferred.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"

class ASButton;

class UILoginNotice : public UIDialog
{
public:
    UILoginNotice();
    virtual ~UILoginNotice();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    void SendNoticeDialog();
    void OnClickCreateButton(const Scaleform::GFx::FunctionHandler::Params& params);
    virtual int vfunc_48() { return 20266; }
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASButton> m_createButton;
};
MS2_CHECK_SIZE(UILoginNotice, 0x188);
MS2_CHECK_OFFSET(UILoginNotice, m_createButton, 0x178);
