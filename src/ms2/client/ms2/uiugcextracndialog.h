// uiugcextracndialog.h - UIUGCExtraCNDialog (RTTI .?AVUIUGCExtraCNDialog@@, 0x180 bytes = UIDialog + the camera mode flag,
// UI id 0x4f30, swf "UGCExtraCNDialog"): the extra buttons of the UGC home build screen: switch the camera mode (free
// camera / default camera, "onCameraMode") and take a screenshot ("onScreenShot", asks for confirmation first). Owning
// unit: ?\uiugcextracndialog.cpp. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the header name is assumed
// from the unit path, member names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CMsgBoxData;
class Unk_UgcCameraButton;

class UIUGCExtraCNDialog : public UIDialog
{
public:
    UIUGCExtraCNDialog();                                       // 0x140facb20
    virtual ~UIUGCExtraCNDialog();                              //  0 0x140facba0 (??_G 0x140fad850)
    virtual CString GetTypeName();                                  //  1 0x140facc10 "UGCExtraCNDialog"
    virtual void OnLoadComplete();                              // 22 0x140facbe0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140faccb0
    virtual int vfunc_48() { return 0x4f30; }                   // 48 0x140fad890
    virtual int vfunc_52();                                     // 52 0x140facc60
    virtual void vfunc_67();                                    // 67 0x140facc80

    void FUN_140facfa0(bool bCameraMode);                       // 0x140facfa0 enable / disable the camera mode button
    void FUN_140fad070(bool bCameraMode);                       // 0x140fad070 forwards to FUN_140facfa0
    bool FUN_140fad0a0(int nResult, const CMsgBoxData& box);    // 0x140fad0a0 screenshot confirm answered
    void FUN_140fad2b0();                                       // 0x140fad2b0 the camera mode button's label and icon
    void FUN_140fad4f0(bool bCameraMode);                       // 0x140fad4f0 switch the camera mode
    MS2Ptr<Unk_UgcCameraButton> FUN_140bb4b10(const CString& strName);   // 0x140bb4b10 bind a button child
private:
    MS2_LAYOUT_FRIEND;
    bool m_bCameraMode;                                         // +0x178 the free camera is on
};
MS2_CHECK_SIZE(UIUGCExtraCNDialog, 0x180);
MS2_CHECK_OFFSET(UIUGCExtraCNDialog, m_bCameraMode, 0x178);
