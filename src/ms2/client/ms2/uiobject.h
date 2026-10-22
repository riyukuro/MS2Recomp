// uiobject.h - UIObject (RTTI .?AVUIObject@@, 0x68 bytes, no fields of its own), the base of every game UI object
// (UIDialog, UIHeadUpDisplay, ...). Recovered with ?\uiobject.cpp (src/ms2/client/ms2/uiobject.cpp). Header name and
// directory assumed (the unit has no __FILE__ string; units.tsv places it among client\ms2).
//
// Base UISwfEntity (src/ms2/gfxui/uiswfentity.h). Primary vftable 0x142ee9d58 (52 slots: UISwfEntity's 47 + 47..51),
// IMessageListener-in-UIObject 0x142ee9f00. Ctor 0x14131e150, dtor 0x14131e1a0 (??_G 0x14131f400).
//
// Complete slot list (signatures from the prologues of all 385 derived classes' implementations); slots 0-46 are
// declared in uiswfentity.h, only UIObject's overrides are repeated here. Names follow Ghidra (vfunc_<slot>) so the
// decompile of derived classes maps 1:1. Ownership: wave-1 foundation; the slot list and layout are fixed.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/gfxui/uiswfentity.h"

class UIObject : public UISwfEntity
{
public:
    UIObject();                                                             // 0x14131e150
    virtual ~UIObject();                                                    //  0 0x14131e1a0 (??_G 0x14131f400)
    virtual CString GetTypeName();                                              //  1 0x14131e1e0 "Object"
    virtual void OnLoadInit();                                              // 20 0x14131eae0 debug: "Swf Name : %s" system message
    virtual void OnLoadComplete();                                          // 22 0x14131ec00 bind vfunc_51 as the ASUIComponent tooltip callback
    virtual void vfunc_26();                                                // 26 0x14131ed10 unbind it (FUN_1422c63f0)
    virtual void vfunc_42(GfxException* pException);                        // 42 0x14131ee90 MessageBox(e->what()); unload
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
                                                                            // 45 0x14131e230 ExternalInterface: "getTooltip", "webPage", ...
    virtual void vfunc_47(int n);                                           // 47 0x14131edb0 FUN_141901420(n, vfunc_48())
    virtual int vfunc_48() = 0;                                             // 48 _purecall: UI type id (e.g. 20094)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x14131edf0 "getTooltip" (empty)
    virtual void vfunc_50(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 50 0x14131ee10 "playSystemSound": FUN_141276180(name, "")
    // 51 0x14131eee0 AS tooltip callback (bound in OnLoadComplete as a Delegate<void(const Params&)>): debug builds
    // show "[Debug SWF Name]\nUI{0}.swf" in *params.pRetVal. No class overrides it.
    virtual void vfunc_51(const Scaleform::GFx::FunctionHandler::Params& params);
};
MS2_CHECK_SIZE(UIObject, 0x68);
