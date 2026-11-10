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
    unsigned int GetLength();                                   // "length"
    int GetSelectedIndex();                                            // "selectedIndex"
    void AddButton(MS2Ptr<ASButton> spButton);                  // addButton (spButton by value: the callee destroys it)
    void RemoveButton(MS2Ptr<ASButton> spButton);                  // removeButton
    MS2Ptr<ASButton> GetButtonAt(int nIndex);                     // getButtonAt
    bool SetSelectedButtonByIndex(int nIndex, bool bForce);                    // setSelectedButtonByIndex
    bool HasButton(MS2Ptr<ASButton> spButton);                  // hasButton
    // the "buttonClick" / "change" callbacks; pUser comes back in Params::pUserData (uimeratmarketdialog.cpp)
    void FUN_1422e8e50(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onClick, void* pUser);
    void AddChangeHandler(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange, void* pUser);
    // ButtonGroup.getGroup(strName, scope): the CLIK button group of that name in the scope's movie (null without a movie)
    static MS2Ptr<ASButtonGroup> FUN_1422e8f50(const CStringW& strName, AScript* pScope);
};
MS2_CHECK_SIZE(ASButtonGroup, 0x80);
