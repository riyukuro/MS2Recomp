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
    ASUIComponent(CString strName, int nMovieId);                   // 0x1422c7170 (by name; asitemslot.cpp)
    virtual ~ASUIComponent();                                       // 0x1422c7200 (asitemslot.cpp: the derived dtors call it)
    // The component's own override: the exe fills slot 4 of every ASUIComponent vftable with 0x1422c7230, not with
    // the ASDisplayObject slot the inherited symbol would name (asgaugecontrol.cpp's vftable).
    virtual void vfunc_4(bool b);                                   // 0x1422c7230 (overrides ASDisplayObject::vfunc_4)
    // Registers a (callback, id) pair on the component (Delegate passed by value: the callee destroys it).
    void FUN_1422c7a90(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> callback, long long n);
    // The component's size, measured from its ActionScript object (the exe folds these three with ASDialog's and
    // ASGameEntity's copies; screenmask.cpp calls them on an ASUIComponent).
    int FUN_1422c1500();                                            // 0x1422c1500 width
    int FUN_1422c1530();                                            // 0x1422c1530 height
    void FUN_1422c79e0(int nWidth, int nHeight);                    // 0x1422c79e0 resize
    // mouse / focus members (uinoticedialog.cpp: the hit area of the notice dialog)
    void FUN_1422c7840(int n);                                      // 0x1422c7840
    void FUN_1422c7630(int n);                                      // 0x1422c7630 focus
    int FUN_1422c76c0();                                            // 0x1422c76c0
    void FUN_1422de700(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n1, int n2);   // 0x1422de700 mouse over listener
    void FUN_1422de780(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n1, int n2);   // 0x1422de780 mouse out listener
    bool FUN_1422c7b40(CStringW strTooltip);                        // 0x1422c7b40 set the tooltip text (by value: the callee destroys it)
    void FUN_1422c7d30(int nWidth, int n2);                         // 0x1422c7d30 (uidungeonroomdialog: sub tab 3 gets 300, 0)

private:
    void* m_pad_80;
};
MS2_CHECK_SIZE(ASUIComponent, 0x88);
