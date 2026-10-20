// uiwritemusicdialog.h - PLACEHOLDER for UIWriteMusicDialog (RTTI .?AVUIWriteMusicDialog@@, UI class id 0x4eed): the
// score composing window of the instrument play mode. NOT an original header. Only the members that
// ?\instrumentmanager.cpp calls are declared (its server replies, packet 0x74 types 8 / 10 / 17).
#pragma once
#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CItem;

class UIWriteMusicDialog : public UIDialog
{
public:
    void FUN_140fefd00(MS2Ptr<CItem> spScore);                      // the composed score item was updated
    void FUN_140ff0260(__int64 nItemUid, const CString& strScore);   // the score text of an item
    void FUN_140ff0090(unsigned char nResult);                      // the compose result
};
