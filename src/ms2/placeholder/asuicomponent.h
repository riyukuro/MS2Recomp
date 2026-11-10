// asuicomponent.h - PLACEHOLDER for ASUIComponent (RTTI .?AVASUIComponent@@, an ASMovieClip with UI hooks; the base of
// ASAdditionalEffectSlot and friends). NOT an original header. uiobject.cpp still carries a unit-local copy (as an AScript);
// new units include this one. Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"

class ASUIComponent : public ASMovieClip
{
public:
    ASUIComponent(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422c7100 (the exe allocates 0x88 bytes)
    ASUIComponent(int nMovieId);                                    // 0x1422c70b0 (a fresh component; ASButton() passes 2)
    ASUIComponent(CString strName, int nMovieId);                   // 0x1422c7170 (by name; asitemslot.cpp)
    virtual ~ASUIComponent();                                       // 0x1422c7200 (asitemslot.cpp: the derived dtors call it)
    // The component's own override: the exe fills slot 4 of every ASUIComponent vftable with 0x1422c7230, not with
    // the ASDisplayObject slot the inherited symbol would name (asgaugecontrol.cpp's vftable).
    virtual void vfunc_4(bool b);                                   // 0x1422c7230 (overrides ASDisplayObject::vfunc_4)
    // Registers a (callback, id) pair on the component (Delegate passed by value: the callee destroys it).
    void SetGetTooltipFunction(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> callback, long long n);
    // The component's size, measured from its ActionScript object (the exe folds these three with ASDialog's and
    // ASGameEntity's copies; screenmask.cpp calls them on an ASUIComponent).
    // width: ASDisplayObject::FUN_1422c1500 (inherited)
    int FUN_1422c1530();                                            // 0x1422c1530 height
    void SetSizeInt(int nWidth, int nHeight);                    // 0x1422c79e0 resize
    // mouse / focus members (uinoticedialog.cpp: the hit area of the notice dialog)
    void SetFocusable(int n);                                      // 0x1422c7840
    void SetFocused(int n);                                      // 0x1422c7630 focus
    int GetFocused();                                            // 0x1422c76c0
    void AddFocusInListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n1, int n2);   // 0x1422de700 mouse over listener
    void AddFocusOutListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n1, int n2);   // 0x1422de780 mouse out listener
    void RemoveFocusOutListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n);   // 0x1422de960 remove the mouse out listener (uiclosetdialog.cpp)
    bool SetTooltipText(CStringW strTooltip);                        // 0x1422c7b40 set the tooltip text (by value: the callee destroys it)
    void SetTooltipOffset(int nWidth, int n2);                         // 0x1422c7d30 (uidungeonroomdialog: sub tab 3 gets 300, 0)

    // ---- recovered with ?\asuicomponent.cpp (src/ms2/gfxui/asuicomponent.cpp, 0x1422c70b0-0x1422c8390) ----
    void AddShowHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser);   // add a "show" listener
    void AddHideHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser);   // add a "hide" listener
    void AddKeyFocusChangeHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser);   // add a "keyFocusChange" listener
    void AddDragStartHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser);   // add a "dragStart" listener
    void AddDragEndHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, __int64 nUser);   // add a "dragEnd" listener
    void RemoveKeyFocusChangeHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // remove the "keyFocusChange" listener
    void RemoveDragStartHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // remove the "dragStart" listener
    void RemoveDragEndHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);   // remove the "dragEnd" listener
    void SetDisplayFocus(int n);                                      // set "displayFocus"
    int GetDisplayFocus();                                            // "displayFocus"
    int HasFocus();                                            // "hasFocus"
    int GetFocusable();                                            // "focusable"
    int GetActualWidth();                                            // "actualWidth"
    int GetActualHeight();                                            // "actualHeight"
    void SetSizeFloat(float fWidth, float fHeight);                // setSize (float)
    void SetTooltipData(const Scaleform::GFx::Value& data);          // set "_tooltipData"
    void RegisterTooltip();                                           // register the tooltip (m_bTooltip; FUN_1422c6380)
    void UnregisterTooltip();                                           // unregister the tooltip (FUN_1422c63f0)
    void DispatchShowHideEvent(bool bShow);                                 // dispatch a "show" / "hide" ASEvent

    // Slots 3 and 16-24. Opt-in (define MS2_ASUICOMPONENT_SLOTS before including): many units derive local classes
    // from ASUIComponent and redeclare these slots themselves (asgameentity.h, asitemslot.h, local copies with other
    // signatures), which would turn into new slots if the base declared them for everyone.
#ifdef MS2_ASUICOMPONENT_SLOTS
    virtual void vfunc_3(int nVisible);                             // 3 0x1422c7260 (calls ASDisplayObject::vfunc_3)
    virtual void vfunc_16();                                        // 16 0x1422c7ec0 invalidate()
    virtual void vfunc_17();                                        // 17 0x1422c7f00 invalidate("size")
    virtual void vfunc_18();                                        // 18 0x1422c7f40 invalidate("data")
    virtual void vfunc_19();                                        // 19 0x1422c7f80 invalidate("state")
    virtual void vfunc_20();                                        // 20 0x1422c7fc0 invalidate("settings")
    virtual void vfunc_21();                                        // 21 0x1422c8000 invalidate("renderers")
    virtual void vfunc_22();                                        // 22 0x1422c8040 invalidate("scrollBar")
    virtual void vfunc_23();                                        // 23 0x1422c8080 invalidate("selectedIndex")
    virtual void vfunc_24(bool bInvalidate);                        // 24 0x1422c80c0 validateNow (slot 16 first if bInvalidate)
#endif

private:
    bool m_bTooltip;                                                // +0x80 the tooltip is registered (RegisterTooltip/7e70)
};
MS2_CHECK_SIZE(ASUIComponent, 0x88);
