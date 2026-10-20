// asbuttongroup.h - PLACEHOLDER for ASButtonGroup (RTTI .?AVASButtonGroup@@, vftable 0x1431165f8 with the scalar
// deleting destructor 0x1422e92a0 as its only slot): the ActionScript button-group (tab bar) wrapper of the GFx UI
// library. NOT an original header. An ASEventDispatcher that adds no virtuals; the exe allocates 0x80 bytes for it
// (AScript child factory, e.g. 0x140fe42c0). Older units carry unit-local views of the same object (Unk_SchedGroup).
// Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"

class ASButton;

class ASButtonGroup : public ASEventDispatcher
{
public:
    ASButtonGroup(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422e8920
    virtual ~ASButtonGroup();                                       // 0 0x1422e8970 (scalar deleting 0x1422e92a0)
    // recovered with ?\asbuttongroup.cpp (src/ms2/gfxui/asbuttongroup.cpp)
    unsigned int FUN_1422e89a0();                                   // "length"
    int FUN_1422e8a00();                                            // "selectedIndex"
    void FUN_1422e8a60(MS2Ptr<ASButton> spButton);                  // addButton (spButton by value: the callee destroys it)
    void FUN_1422e8b20(MS2Ptr<ASButton> spButton);                  // removeButton
    MS2Ptr<ASButton> FUN_1422e8be0(int nIndex);                     // getButtonAt
    bool FUN_1422e8ce0(int nIndex, bool bForce);                    // setSelectedButtonByIndex
    bool FUN_1422e8d60(MS2Ptr<ASButton> spButton);                  // hasButton
    // the "buttonClick" / "change" callbacks; pUser comes back in Params::pUserData (uimeratmarketdialog.cpp)
    void FUN_1422e8e50(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onClick, void* pUser);
    void FUN_1422e8ed0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange, void* pUser);
    // ButtonGroup.getGroup(strName, scope): the CLIK button group of that name in the scope's movie (null without a movie)
    static MS2Ptr<ASButtonGroup> FUN_1422e8f50(const CStringW& strName, AScript* pScope);
};
MS2_CHECK_SIZE(ASButtonGroup, 0x80);
