// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed (no __FILE__ for the unit).
//
// UIUGCHousingPointDialog (UI type 0x4f28, "UGCHousingPointDialog"; RTTI .?AVUIUGCHousingPointDialog@@): the housing
// point window of the player's home. A UIHomeResizeDialog (the area / height extension buttons, "buildInteriorExtension")
// plus the interior grade info ("buildInteriorInfo": grade, exp, housing points, the next point reward) and the bonus
// interior list ("buildInteriorList": per cube category the installed count against the bonus count). Listens to item
// events through UIItemEventListener at +0x178 (registered in OnLoadComplete, removed in vfunc_67 and the dtor).
// 0x180 bytes (??_G deletes 0x180): no members of its own. Method names are invented.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/client/ms2/uihomeresizedialog.h"

class UIUGCHousingPointDialog : public UIHomeResizeDialog, public UIItemEventListener
{
public:
    UIUGCHousingPointDialog();                                  // 0x140fadb00
    virtual ~UIUGCHousingPointDialog();                         //  0 0x140fadb80 (??_G 0x140faf220)
    virtual CString GetTypeName();                                  //  1 0x140fadc30 "UGCHousingPointDialog"
    virtual void OnLoadComplete();                              // 22 0x140fadea0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140fadfd0
    virtual int vfunc_48() { return 0x4f28; }                   // 48 0x140faf260
    virtual int vfunc_52();                                     // 52 0x140fadd00 "m_interiorInfo" has an "m_dragBar"
    virtual void vfunc_67();                                    // 67 0x140fade40
    virtual void vfunc_84();                                    // 84 0x140fae9e0 "buildInteriorExtension"
    virtual int vfunc_il1();                                    // o178 1 0x140fadc80
    virtual void vfunc_34();                                    // o178 34 0x140fadf60 refresh everything

    void FUN_140fae0d0();                                       // 0x140fae0d0 = RefreshInfo
    int RefreshFoldButton();                                    // 0x140fae0f0 "m_fold" selected while not at home
    void RefreshInfo();                                         // 0x140fae1d0 "buildInteriorInfo"
    void RefreshList();                                         // 0x140fae5d0 "buildInteriorList"
    void OnRewardItem();                                        // 0x140faefe0 packet 0x37 / 0x28
    bool IsInMyHome();                                          // 0x140faf060
    bool CanReceiveReward();                                    // 0x140faf0c0 a point reward box is due
};
MS2_CHECK_SIZE(UIUGCHousingPointDialog, 0x180);
