// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\ms2dragslot.cpp
// MS2-RANGE: 0x140a7bb20-0x140a7beb0 .text$mn
// MS2-RANGE: 0x1400c4a80-0x1400c4b60 .text$di
// MS2-PIN: ??_7MS2DragSlot@@6BBindData@NotifyContext@@@ 0x142dcc930
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2dragslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2dragslot.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Item preview window (?\itempreview.cpp): singleton getter 0x1409bb9e0 (asitemslot.cpp COMDAT).
class Unk_ItemPreview
{
public:
    int FUN_140d40670();                                // non-zero while the preview can be shown
    void FUN_140d40120(MS2Ptr<CItem> spItem, int n);    // show spItem
};
Unk_ItemPreview* FUN_1409bb9e0();

// Key/permission state (commonstringtable.cpp singleton 0x14025e7c0, test 0x14116dcb0).
class Unk_KeyState
{
public:
    bool FUN_14116dcb0(int nKey, int a, int b);
};
Unk_KeyState* FUN_14025e7c0();

EE_IMPLEMENT_CONCRETE_CLASS_INFO(MS2DragSlot);

// Header-defined sort-name table (same 7 strings in client\ms2\scenestatemove.cpp's initializers).
static CString s_sortNames[] = {"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};

// @0x140a7bb20
MS2DragSlot::MS2DragSlot(const CString& strName, int nIndex)
    : DragSlot(strName, nIndex)
{
    m_bEnabled = 0;
}

// @0x140a7bb90
MS2DragSlot::~MS2DragSlot()
{
}

// @0x140a7bbd0
int MS2DragSlot::vfunc_16()
{
    if (!FUN_140a7bd60())
        return 0;
    MS2Ptr<CItem> spItem = vfunc_25();
    if (spItem == NULL)
        return 0;
    if (FUN_1409bb9e0()->FUN_140d40670())
        FUN_1409bb9e0()->FUN_140d40120(spItem, 0);
    return 1;
}
MS2_REPLACE_METHOD(0x140a7bbd0, MS2DragSlot, vfunc_16, 225, 0xF2650599);

// @0x140a7bcc0
int MS2DragSlot::vfunc_19()
{
    if (!FUN_140a7bd60())
        return 0;
    if (FUN_14025e7c0()->FUN_14116dcb0(0x49406, 0, 0))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x140a7bcc0, MS2DragSlot, vfunc_19, 75, 0xC28B5EF0);

// @0x140a7bd20
MS2Ptr<CItem> MS2DragSlot::vfunc_25()
{
    return MS2Ptr<CItem>(0);
}
MS2_REPLACE_METHOD(0x140a7bd20, MS2DragSlot, vfunc_25, 55, 0xCCB7CA10);

// @0x140a7bd60
bool MS2DragSlot::FUN_140a7bd60()
{
    return m_bEnabled;
}
MS2_REPLACE_METHOD(0x140a7bd60, MS2DragSlot, FUN_140a7bd60, 18, 0x01A1D2ED);

// @0x140a7bd80
void MS2DragSlot::FUN_140a7bd80(bool b)
{
    m_bEnabled = b;
}
MS2_REPLACE_METHOD(0x140a7bd80, MS2DragSlot, FUN_140a7bd80, 26, 0xF01D1BED);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9f8e0-0x142c9f910 .text$yd
