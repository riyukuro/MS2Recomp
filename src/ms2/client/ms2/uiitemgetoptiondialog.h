// uiitemgetoptiondialog.h - UIItemGetOptionDialog (RTTI .?AVUIItemGetOptionDialog@@, 0x198 bytes, UIModalDialog, UI id
// 0x4e6c, swf "ItemGetOptionDialog"): the auto-loot options window. One check box per item group (m_equip m_consume
// m_etc m_meso m_merat m_token m_other m_gemstone m_pet) and the lowest equip grade (combo m_equipRank). Mode 0 edits
// the account's auto-loot options and sends them to the server (packet 0x78 / 6); any other mode edits the local copy
// in the game options (FUN_141261310). Owning unit: unit_1419d95c0 (?\uiitemgetoptiondialog.cpp). Header name assumed.
#pragma once
#include "ms2/client/ms2/uimodaldialog.h"
#include "ms2/placeholder/gfxvalue.h"

// The auto-loot options (0x10 bytes, also +0x14c of the account settings): one flag per item group and the grade.
class Unk_GoOpt
{
public:
    Unk_GoOpt* FUN_141260ea0();                                 // reset, returns this
    void FUN_141260ed0();                                       // reset to the defaults
    void FUN_141260f40(void* pConfig);                          // read the "autoLooting" section
    void FUN_141261530(bool b);                                 // set equip
    void FUN_141261550(int n);                                  // set the grade
    void FUN_141261570(bool b);                                 // set consume
    void FUN_141261590(bool b);                                 // set etc
    void FUN_1412615b0(bool b);                                 // set meso
    void FUN_1412615d0(bool b);                                 // set merat
    void FUN_1412615f0(bool b);                                 // set token
    void FUN_141261610(bool b);                                 // set other
    void FUN_141261630(bool b);                                 // set gemstone
    void FUN_141261650(bool b);                                 // set pet

    // @0x1419dae30
    int FUN_1419dae30() { return m_nGrade; }
    // @0x1419dae50
    bool FUN_1419dae50() { return m_bConsume; }
    // @0x1419dae60
    bool FUN_1419dae60() { return m_bEtc; }
    // @0x1419dae70
    bool FUN_1419dae70() { return m_bEquip; }
    // @0x1419dae80
    bool FUN_1419dae80() { return m_bGemstone; }
    // @0x1419dae90
    bool FUN_1419dae90() { return m_bMerat; }
    // @0x1419daea0
    bool FUN_1419daea0() { return m_bMeso; }
    // @0x1419daeb0
    bool FUN_1419daeb0() { return m_bOther; }
    // @0x1419daec0
    bool FUN_1419daec0() { return m_bPet; }
    // @0x1419daed0
    bool FUN_1419daed0() { return m_bToken; }

private:
    bool m_bEquip;                                              // +0x00
    bool m_bConsume;                                            // +0x01
    bool m_bEtc;                                                // +0x02
    bool m_bMeso;                                               // +0x03
    bool m_bMerat;                                              // +0x04
    bool m_bToken;                                              // +0x05
    bool m_bOther;                                              // +0x06
    bool m_bGemstone;                                           // +0x07
    bool m_bPet;                                                // +0x08
    int m_nGrade;                                               // +0x0c lowest equip grade (1..6)
};
MS2_CHECK_SIZE(Unk_GoOpt, 0x10);

class UIItemGetOptionDialog : public UIModalDialog
{
public:
    UIItemGetOptionDialog();                                    // 0x1419d95c0
    virtual ~UIItemGetOptionDialog();                           //  0 0x1419d9640 (??_G 0x1419dadf0)
    virtual CString GetTypeName();                                  //  1 0x1419d9680 "ItemGetOptionDialog"
    virtual void OnLoadInit();                                  // 20 0x1419d96d0 load the options
    virtual void OnLoadComplete();                              // 22 0x1419d9720 fill the controls
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1419d9f30
    virtual int vfunc_46();                                     // 46 0x1419da640 hide the groups the features lack
    virtual int vfunc_48() { return 0x4e6c; }                   // 48 0x1419dae40
    virtual void vfunc_67();                                    // 67 0x1419d9700 UIModalDialog::vfunc_67

    void SetMode(int nMode);                              // set the mode
    void FUN_1419da8f0();                                       // load the options (account or local copy)
    void FUN_1419dabc0();                                       // apply: send the options / store the copy

private:
    MS2_LAYOUT_FRIEND;
    int m_nMode;                                                // +0x180 0: edit the account options
    Unk_GoOpt m_opt;                                            // +0x184
};
MS2_CHECK_SIZE(UIItemGetOptionDialog, 0x198);
MS2_CHECK_OFFSET(UIItemGetOptionDialog, m_nMode, 0x180);
MS2_CHECK_OFFSET(UIItemGetOptionDialog, m_opt, 0x184);
