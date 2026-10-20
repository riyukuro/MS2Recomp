// asbuttonbar.h - PLACEHOLDER for ASButtonBar (RTTI .?AVASButtonBar@@, an ASUIComponent; ctor 0x1422e2cd0, vftable
// 0x143115210 with 25 slots, 0x88 bytes): the GFx tab strip / button bar wrapper. NOT an original header. The tab
// dialogs bind it as "m_tab" (UIDialog child lookup COMDAT 0x140c02870). Older units carry unit-local views of the same
// object (Unk_WdTab, Unk_GsTab, Unk_TrTab, Unk_LsTabBar, ...); new code should use this class. Only what recovered code
// calls is declared.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"

class ASObj;
class ASButton;
class ASDataProvider;

class ASButtonBar : public ASUIComponent
{
public:
    ASButtonBar(const Scaleform::GFx::Value& v, int nMovieId);         // 0x1422e2cd0
    virtual ~ASButtonBar();
    // ASUIComponent slots 16-23 (not recovered) and the bar's refresh.
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);                               // 24 0x1422c80c0 validateNow

    void FUN_1422e31e0(int nIndex);                                     // select a button ("selectedIndex")
    int FUN_1422e3210();                                                // the selected button (uiguilddialog.cpp)
    void FUN_1422e3400();                                               // clear the data provider
    void FUN_1422e3460(const ASObj& item);                              // append a button (pushed to the data provider)
    void FUN_1422e3590(const CStringW& strLabel);                       // 0x1422e3590 select the button of a label (uimessenger.cpp)
    CStringW FUN_1422e3790();                                           // 0x1422e3790 the selected label
    void FUN_1422e3a70(const CStringW& strLabel);                       // 0x1422e3a70 remove the button of a label
    void FUN_1422e3c70(const CStringW& strOld, const CStringW& strNew); // 0x1422e3c70 relabel a button
    MS2Ptr<ASDataProvider> FUN_1422e2e00();                             // the data provider (uiclosetdialog.cpp)
    MS2Ptr<ASButton> FUN_1422e32b0(int nIndex);                         // the button of an entry
    void FUN_1422e4060(int nIndex);                                     // refresh an entry from the data provider
    void FUN_1422e4190(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange, int nUser);    // selection change listener
    void FUN_1422e4270(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onMenu, int nUser);      // entry menu listener
};
MS2_CHECK_SIZE(ASButtonBar, 0x88);
