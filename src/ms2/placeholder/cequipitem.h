// cequipitem.h - PLACEHOLDER for CEquipItem (RTTI .?AVCEquipItem@@, CPtred-derived, 0xb0 bytes; owning unit
// ?\equipitem.cpp, not recovered): the worn item of an actor's equip slot. NOT an original header; only the members
// that done units call are declared.
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class CItem;
class CItemUgcMeshContainer;

class CEquipItem : public CPtred
{
public:
    MS2Ptr<CItem> FUN_1411dc7a0();                                  // 0x1411dc7a0 the item the slot shows
    void FUN_1411dd1c0();                                           // 0x1411dd1c0 (scenestategame, w86)
    struct Unk_EquipItemData* FUN_1411dc7f0();                      // 0x1411dc7f0 the item's table data (mypc)
    int FUN_1411dc820();                                            // 0x1411dc820 the item id (mypc)
    MS2Ptr<CItemUgcMeshContainer> FUN_1411dd950();                  // 0x1411dd950 the UGC meshes of the item (ugcmanager.cpp#4)
    void FUN_1411dce60(const CString& strTag);                      // 0x1411dce60 add a tag ("Customize", "Undo"; customize.cpp)
    void FUN_1411dcf10(const CString& strTag);                      // 0x1411dcf10 remove a tag (customize.cpp)
    void FUN_1411dd280();                                           // 0x1411dd280 apply the tags (customize.cpp)
private:
    char m_pad_18[0xb0 - 0x18];                                     // unrecovered members
};
MS2_CHECK_SIZE(CEquipItem, 0xb0);
