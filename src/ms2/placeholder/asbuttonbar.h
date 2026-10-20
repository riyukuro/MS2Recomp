// asbuttonbar.h - PLACEHOLDER for ASButtonBar (RTTI .?AVASButtonBar@@, an ASUIComponent; ctor 0x1422e2cd0, vftable
// 0x143115210 with 25 slots, 0x88 bytes): the CLIK ButtonBar (tab strip) wrapper. NOT an original header; the code is the
// ?\asbuttonbar.cpp unit (src/ms2/gfxui/asbuttonbar.cpp, 0x1422e2cd0-0x1422e4490). The tab dialogs bind it as "m_tab"
// (UIDialog child lookup COMDAT 0x140c02870). Older units carry unit-local views of the same object (Unk_WdTab,
// Unk_GsTab, Unk_TrTab, Unk_LsTabBar, ...); new code should use this class. Only the dtor is overridden: slots 16-24
// are ASUIComponent's, redeclared here for the units that do not opt in to its slot list (MS2_ASUICOMPONENT_SLOTS).
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
    virtual ~ASButtonBar();                                             // 0x1422e2d20 (scalar deleting 0x1422e4450)
#ifndef MS2_ASUICOMPONENT_SLOTS
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);                               // 24 0x1422c80c0 validateNow
#endif

    void FUN_1422e2d50(MS2Ptr<ASDataProvider> spProvider);              // set the data provider (by value: the callee destroys it)
    void FUN_1422e2db0(const Scaleform::GFx::Value& v);                 // set "dataProvider"
    MS2Ptr<ASDataProvider> FUN_1422e2e00();                             // the data provider (uiclosetdialog.cpp)
    void FUN_1422e2e70(const CString& strName);                         // set "itemRendererName"
    void FUN_1422e2ec0(float f);                                        // set "spacing"
    float FUN_1422e2f00();                                              // "spacing"
    void FUN_1422e2f70(const CString& strDirection);                    // set "direction"
    CString FUN_1422e2fc0();                                            // "direction"
    void FUN_1422e3050(const CString& strAutoSize);                     // set "autoSize"
    CString FUN_1422e30a0();                                            // "autoSize"
    void FUN_1422e3130(float f);                                        // set "buttonWidth"
    float FUN_1422e3170();                                              // "buttonWidth"
    void FUN_1422e31e0(int nIndex);                                     // select a button ("selectedIndex")
    int FUN_1422e3210();                                                // the selected button (uiguilddialog.cpp)
    void FUN_1422e3270();                                               // invalidateSettings()
    MS2Ptr<ASButton> FUN_1422e32b0(int nIndex);                         // the button of an entry (getButtonAt)
    unsigned FUN_1422e3380();                                           // 0x1422e3380 the button count
    void FUN_1422e3400();                                               // clear the data provider
    void FUN_1422e3460(const ASObj& item);                              // append a button (pushed to the data provider)
    void FUN_1422e34d0(const CStringW& strLabel);                       // append a button { label }
    void FUN_1422e3590(const CStringW& strLabel);                       // 0x1422e3590 select the button of a label (uimessenger.cpp)
    CStringW FUN_1422e3790();                                           // 0x1422e3790 the selected label
    CStringW FUN_1422e37e0(int nIndex);                                 // 0x1422e37e0 the label of a button
    void FUN_1422e3a00(int nIndex);                                     // remove a button
    void FUN_1422e3a70(const CStringW& strLabel);                       // 0x1422e3a70 remove the button of a label
    void FUN_1422e3c70(const CStringW& strOld, const CStringW& strNew); // 0x1422e3c70 relabel a button
    int FUN_1422e3ee0(const CString& strField, Scaleform::GFx::Value& vOut);   // a field of the selected entry (0: none / null)
    void FUN_1422e4060(int nIndex);                                     // refresh an entry's button from the data provider
    void FUN_1422e4190(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange, void* pUser);  // add "clikIndexChange"
    void FUN_1422e4210(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange);               // remove "clikIndexChange"
    void FUN_1422e4270(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onMenu, void* pUser);    // add "listIndexChange"
    void FUN_1422e42f0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onMenu);                 // remove "listIndexChange"

private:
    MS2Ptr<ASDataProvider> FUN_1422de460(const CString& strName);       // a child as an ASDataProvider (ascorelist.cpp COMDAT)
};
MS2_CHECK_SIZE(ASButtonBar, 0x88);
