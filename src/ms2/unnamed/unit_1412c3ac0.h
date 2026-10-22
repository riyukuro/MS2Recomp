// unit_1412c3ac0.h - UIIGuideMovieDialog (RTTI .?AUIIGuideMovieDialog / swf "GuideMovieDialog", 0x180 bytes, UIModalDialog,
// UI id 0x4ea7): the modal tutorial-movie dialog. It sends the movie path from the game config to the swf ("initData") and
// forwards the escape key ("onEscapeKey"). No members of its own. Owning unit: unit_1412c3ac0 (0x1412c3ac0-0x1412c3e60);
// the original header name is unknown (a guess "uiiguidemoviedialog" was rejected by the unit order).
#pragma once
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/placeholder/gfxvalue.h"

class UIIGuideMovieDialog : public UIModalDialog
{
public:
    UIIGuideMovieDialog();                                      // 0x1412c3ac0
    virtual ~UIIGuideMovieDialog();                             //  0 0x1412c3b50 (??_G 0x1412c3e10)
    virtual CString GetTypeName();                                  //  1 0x1412c3b90 "GuideMovieDialog"
    virtual int vfunc_13();                                     // 13 0x1412c3d60 UIDialog::vfunc_13() || key 0x1c
    virtual void OnLoadComplete();                              // 22 0x1412c3c80 send the movie path ("initData")
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1412c3dc0
    virtual int vfunc_48() { return 0x4ea7; }                   // 48 0x1412c3e50
    virtual int vfunc_65();                                     // 65 0x1412c3be0 Open (UIDialog::vfunc_65)
    virtual void vfunc_67();                                    // 67 0x1412c3c00 Close (UIModalDialog::vfunc_67)
    virtual void vfunc_69();                                    // 69 0x1412c3c20 escape: the swf's "onEscapeKey"
};
MS2_CHECK_SIZE(UIIGuideMovieDialog, 0x180);
