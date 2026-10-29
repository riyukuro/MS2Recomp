// ItemUtilTransfer::TOutBindingParam: RTTI name; ctor 0x140a69c70.
#pragma once
#include <afx.h>
#include "ms2/placeholder/cptred.h"
namespace ItemUtilTransfer {
struct TOutBindingParam : CPtred {
    TOutBindingParam();
    // implicit virtual ~TOutBindingParam (0x140a69eb0; the exe dtor never resets the vptr)
    int kind;
    CStringW name;
    __int64 characterId;
};
}
MS2_CHECK_SIZE(ItemUtilTransfer::TOutBindingParam, 0x30);
MS2_CHECK_OFFSET(ItemUtilTransfer::TOutBindingParam, kind, 0x18);
MS2_CHECK_OFFSET(ItemUtilTransfer::TOutBindingParam, name, 0x20);
MS2_CHECK_OFFSET(ItemUtilTransfer::TOutBindingParam, characterId, 0x28);
