// aslabel.h - PLACEHOLDER for ASLabel (RTTI .?AVASLabel@@): the C++ wrapper of a GFx label component (a text clip
// created from a linkage name). NOT an original header. The exe allocates 0x88 bytes (0x1412a9644, uidungeonroomdialog:
// `new ASLabel("UIDungeonRoomLimitLabel", 2)`), so it adds no members to ASUIComponent. Declarations only.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"

class ASLabel : public ASUIComponent
{
public:
    ASLabel(CString strLinkage, int nMovieId);                      // 0x1422e4950 (the callee destroys the name)
    void FUN_1422e4b80(const CStringW& strText);                    // set the label text
    void FUN_1422c6eb0();                                           // ASDisplayObject: remove from the parent clip
    void FUN_1422e4c60(const CString& strAutoSize);                 // set "autoSize" ("none", ...)
};
MS2_CHECK_SIZE(ASLabel, 0x88);
