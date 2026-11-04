// itementityless.h - the ItemEntity set ordering shared by the gacha, pet and lullu box dialogs (Unk_GachaLess), split
// out of uiitemgachaboxdialog.h so the three dialogs' std::set<ItemEntity> are one instantiation, as in the exe.
// NOT an original header.
#pragma once
#include "ms2/commonfiles/commonstruct_wa.h"

// Orders a set of items (the comparator is the ItemEntity ordering of commonfiles\commonstruct).
struct Unk_GachaLess
{
    bool operator()(const ItemEntity& a, const ItemEntity& b) const { return FUN_14026aeb0(a, b); }
};
