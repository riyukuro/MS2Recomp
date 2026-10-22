// Recovered UIPhotoStudioMenuDialog (the menu bar of the photo studio, UI type 0x4f8f, 0x180 bytes). A cut-down sibling of
// UIHomeMenuDialog: it only has the screenshot and free-camera buttons. Original header name assumed.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class UIPhotoStudioMenuDialog : public UIDialog
{
public:
    UIPhotoStudioMenuDialog();                                             // 0x140e75ea0
    virtual ~UIPhotoStudioMenuDialog();                                    //  0 0x140e75f40 (??_G 0x140e762f0)
    virtual CString vfunc_1();                                             //  1 0x140e75f80
    virtual void OnLoadComplete();                                         // 22 0x140e76000
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140e76090
    virtual int vfunc_48();                                                // 48 0x140e76330
    virtual void vfunc_67();                                               // 67 0x140e75fd0

    void OnScreenshot();                                                  // "OnScreenshot"
    void OnFreeCamera();                                                  // "OnFreeCamera": toggle the free camera
    void FUN_140e761b0();                                                  // sync the free-camera check box
    void FUN_140e76270(bool bFreeCamera);                                  // switch the free camera

private:
    MS2_LAYOUT_FRIEND;
    bool m_bFreeCamera;                                                    // +0x178 (the 7 bytes up to +0x180 are padding)
};
MS2_CHECK_SIZE(UIPhotoStudioMenuDialog, 0x180);
MS2_CHECK_OFFSET(UIPhotoStudioMenuDialog, m_bFreeCamera, 0x178);
