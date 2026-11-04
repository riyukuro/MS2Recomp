// asitemslot.h - PLACEHOLDER for ASItemSlot (RTTI .?AVASItemSlot@@, 0x98 bytes, base ASUIComponent, vftable 0x142db7e38,
// 26 slots): the AS item slot icon with an item tooltip. NOT an original header (the code is in ?\asitemslot.cpp).
// Ctor 0x1409ba310, dtor 0x1409ba410 (deleting 0x1409bb920), vfunc_25 (the item tooltip value) 0x1409ba800.
//
// ASUIComponent declares slots 3 and 16-24 only under MS2_ASUICOMPONENT_SLOTS (its derived classes elsewhere would all
// need the slot symbols), so without the macro they are declared here as ASItemSlot members; they are really
// ASUIComponent's (0x1422c7260, 0x1422c7ec0-0x1422c80c0 in steps of 0x40/0x3c; slot 24 is validateNow). The vftable
// layout is the same either way. Slot 4 (0x1422c7230) the base always declares.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asuicomponent.h"

class Unk_ItemSlotSource;

class ASItemSlot : public ASUIComponent
{
public:
    ASItemSlot(CString strName, int nUnused);// 0x1409ba1d0 (the base gets movie 2)
    ASItemSlot(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1409ba310
    virtual ~ASItemSlot();                                      // 0 (0x1409ba410)
#ifndef MS2_ASUICOMPONENT_SLOTS   // else ASUIComponent declares slots 3 and 16-24 (same vftable layout)
    virtual void vfunc_3(int nVisible);                         // 3 0x1422c7260
    virtual void vfunc_16();                                    // 16 0x1422c7ec0
    virtual void vfunc_17();                                    // 17 0x1422c7f00
    virtual void vfunc_18();                                    // 18 0x1422c7f40
    virtual void vfunc_19();                                    // 19 0x1422c7f80
    virtual void vfunc_20();                                    // 20 0x1422c7fc0
    virtual void vfunc_21();                                    // 21 0x1422c8000
    virtual void vfunc_22();                                    // 22 0x1422c8040
    virtual void vfunc_23();                                    // 23 0x1422c8080
    virtual void vfunc_24(bool bRefresh);                       // 24 0x1422c80c0
#else
    using SlotsCheck = decltype(&ASUIComponent::vfunc_24);      // fails to compile if the macro came after asuicomponent.h
#endif
    // Builds the item tooltip and returns its value through *ppOut (slot 25, 0x1409ba800). ppOut is really the
    // tooltip callback's Params (its first member is pRetVal).
    virtual void vfunc_25(Scaleform::GFx::Value** ppOut);
    void UpdateSlotData();                                       // push the slot data (item id/rarity/count) to AS
    void SetItem(int nItemId, int nRarity, int nCount);   // set the item and refresh
    void FUN_1409ba630(const Unk_ItemSlotSource& item);         // set the item from a reward record (its slots 0-2)
    void FUN_1409ba6d0();                                       // enable the click preview (registers FUN_1409baa60)
    void SetTooltipFunction(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> callback, __int64 nUser);   // setTooltipFunction
    void FUN_1409baa20(const Scaleform::GFx::FunctionHandler::Params& params);   // the tooltip callback: vfunc_25
    void FUN_1409baa60(const Scaleform::GFx::FunctionHandler::Params& params);   // the click callback: item preview

protected:
    MS2_LAYOUT_FRIEND;
    int m_itemId;                                               // +0x88
    int m_rarity;                                               // +0x8c
    int m_nCount;                                               // +0x90
    bool m_bLocked;                                             // +0x94 shown with the lock icon
    bool m_bPreview;                                            // +0x95 click preview on; the tooltip compares
};
MS2_CHECK_SIZE(ASItemSlot, 0x98);
MS2_CHECK_OFFSET(ASItemSlot, m_itemId, 0x88);
MS2_CHECK_OFFSET(ASItemSlot, m_bPreview, 0x95);
