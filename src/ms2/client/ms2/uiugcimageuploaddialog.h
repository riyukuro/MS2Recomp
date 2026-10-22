// uiugcimageuploaddialog.h - UIUGCImageUploadDialog (RTTI .?AVUIUGCImageUploadDialog@@, 0x190 bytes, UI id 0x4e56, swf
// "UGCImageUploadDialog"): the picker of the local UGC image files (banner, profile, guild mark / poster, blueprint,
// wedding profile). It lists the files of the upload directory, previews one in the viewer of the running upload
// (CUgcUploadCtrl) and starts the upload. Bases: UIDialog, UIStatusEventListener (+0x178) and UIUGCEventListener (+0x180).
// Owning unit: ?\uiugcimageuploaddialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"

class ASData;
class UIMsg;
class UISwfEntity;

// The upload kinds the dialog serves (the CUgcUpload kind): 3 banner, 5 profile, 6 guild mark, 8 guild poster, 9 / 0xd1
// blueprint image, 10 wedding profile.
enum Unk_UgcOpenType : int
{
    Unk_UgcOpenType_None = 0
};

class UIUGCImageUploadDialog : public UIDialog, public UIStatusEventListener, public UIUGCEventListener
{
public:
    UIUGCImageUploadDialog();                                   // 0x141b39900
    virtual ~UIUGCImageUploadDialog();                          //  0 0x141b399c0 (??_G 0x141b3b6c0)
    virtual CString GetTypeName();                                  //  1 0x141b39a50 "UGCImageUploadDialog"
    virtual void OnLoadInit();                                  // 20 0x141b39c50
    virtual void OnLoadComplete();                              // 22 0x141b39c70 show the running upload
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b3a020
    virtual int vfunc_48() { return 0x4e56; }                   // 48 0x141b3b700
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x141b3a3d0 "getTooltip" of a file
    virtual int vfunc_65();                                     // 65 0x141b39aa0 Open: listen for status / UGC events
    virtual void vfunc_67();                                    // 67 0x141b39b40 Close
    virtual void vfunc_72();                                    // 72 0x141b39c10 refresh the thumbnail when asked
    virtual int vfunc_82();                                     // 82 0x141b3a5e0 the upload kind
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141b39e30 the message boxes
    // UIUGCEventListener (+0x180)
    virtual void vfunc_ugc_4(int nDialog);                      // 4 0x141b3a630 the upload moved to this dialog

    void FUN_141b3a600();                                       // rebuild the list and unselect
    void FUN_141b3a690(int nResult);                            // the server answered the upload
    bool FUN_141b3a780(const int* pnKind);                      // the running upload is one of this kind
    void FUN_141b3ab90();                                       // rebuild the file list
    void OnOpenFolder();                                       // open the upload directory
    int  FUN_141b3acb0(int nIndex);                             // preview a file
    int  FUN_141b3adc0(int nIndex);                             // upload a file
    int  OnNewTemplate();                                       // OnNewTemplate: clear the upload
    int  OnAddImage();                                       // OnAddImage: pick an image file
    int FUN_141b3b0e0(int nIndex);                              // scroll the list
    void FUN_141b3b1d0();                                       // update the thumbnail image
    void FUN_141b3b2c0();                                       // show the banner price
    __int64 FUN_141b3b390();                                    // the price of the banner
    void FUN_141b3b4e0(int nIndex);                             // select the thumbnail
    int FUN_140c39820() { return m_188; }                       // 0x140c39820 the upload kind

private:
    MS2_LAYOUT_FRIEND;
    Unk_UgcOpenType m_188;                                      // +0x188 the upload kind
    int m_18c;                                                  // +0x18c the thumbnail needs a refresh
};
MS2_CHECK_SIZE(UIUGCImageUploadDialog, 0x190);
MS2_CHECK_OFFSET(UIUGCImageUploadDialog, m_188, 0x188);
