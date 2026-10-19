// uifittingdolldialog.h - UIFittingDollDialog (RTTI .?AVUIFittingDollDialog@@, 0x190 bytes, UIDialog +
// UIDialogEventListener + UIItemEventListener, UI id 0x4e77, swf "FittingDollDialog"): the window of a cube fitting doll
// (a FittingDollPC the owner dresses up). It shows the doll's name / description / character / equip / emblem frames,
// lets the player put the worn equipment on the doll ("OnTransform": checks that the doll can wear every worn item, then
// sends packet 0x42 / 3 with the doll id) and keeps the "m_transform" button disabled while the request is pending.
// DAT_143af25f0 is the id of the doll shown, DAT_143af25f8 is set when a fitting doll's equipment changed.
// Owning unit: ?\uifittingdolldialog.cpp. Header name assumed from the unit path; member names invented.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uidialogeventlistener.h"
#include "ms2/placeholder/uiitemeventlistener.h"

class CMsgBoxData;

class UIFittingDollDialog : public UIDialog, public UIDialogEventListener, public UIItemEventListener
{
public:
    UIFittingDollDialog();                                      // 0x141933270
    virtual ~UIFittingDollDialog();                             //  0 0x141934eb0 (??_G 0x141934f50)
    virtual CString vfunc_1();                                  //  1 0x141933340 "FittingDollDialog"
    virtual void vfunc_15();                                    // 15 0x141933a90
    virtual void OnLoadComplete();                              // 22 0x141933910
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419339d0
    virtual int vfunc_48() { return 0x4e77; }                   // 48 0x141934f90
    virtual int vfunc_65();                                     // 65 0x1419334b0
    virtual void vfunc_66();                                    // 66 0x1419337c0
    virtual void vfunc_67();                                    // 67 0x141933510
    virtual void vfunc_72();                                    // 72 0x1419335f0
    virtual void vfunc_dl_3(void* pSlot);                       // UIDialogEventListener 3 0x141933620 "onDragStart"
    virtual void vfunc_dl_4(void* p);                           // UIDialogEventListener 4 0x141933740 "onDragEnd"
    virtual void vfunc_33(int nClassId, int n);                 // UIItemEventListener 33 0x141933ad0

    void FUN_141933390();                                       // ask the server to transform the doll
    void FUN_141933b00();                                       // show the doll's name / description / frames
    void FUN_141934070();                                       // tell the bag id / ownership to the movie
    void FUN_1419342e0();                                       // FUN_14121e760(vfunc_1())
    void FUN_141934340();                                       // enable the "m_transform" button again
    int FUN_141934430();                                        // can the doll wear the equipment (0 yes, else error code)
    bool FUN_141934c10(int nResult, const CMsgBoxData& box);    // confirm box callback: 0 sends the request

private:
    MS2_LAYOUT_FRIEND;
    int m_nTransforming;                                        // +0x188 the "m_transform" button is disabled
};
MS2_CHECK_SIZE(UIFittingDollDialog, 0x190);
MS2_CHECK_OFFSET(UIFittingDollDialog, m_nTransforming, 0x188);
