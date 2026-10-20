// asbuttongroup.h - PLACEHOLDER for ASButtonGroup (RTTI .?AVASButtonGroup@@, vftable 0x1431165f8 with the scalar
// deleting destructor 0x1422e92a0 as its only slot): the ActionScript button-group (tab bar) wrapper of the GFx UI
// library. NOT an original header. An ASEventDispatcher that adds no virtuals; the exe allocates 0x80 bytes for it
// (AScript child factory, e.g. 0x140fe42c0). Older units carry unit-local views of the same object (Unk_SchedGroup).
// Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"

class ASButtonGroup : public ASEventDispatcher
{
public:
    ASButtonGroup(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422e8920
    virtual ~ASButtonGroup();
    void FUN_1422e8e50(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& onChange, int nUser);   // the change callback (uimeratmarketdialog.cpp)
};
MS2_CHECK_SIZE(ASButtonGroup, 0x80);
