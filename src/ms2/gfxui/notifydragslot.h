// notifydragslot.h - NotifyDragSlot (RTTI .?AVNotifyDragSlot@@, 0x48 bytes, base NotifyHandler): the notify handler of
// the drag & drop slots' ActionScript callbacks ("notifySlotUse", "notifySlotShiftClick", "notifySlotDragStart",
// "notifySlotDragEnd", "getSlotTooltip", "getBagSlotBindings"). Each looks up the DragSlot / DragSlotBag bound under the
// name in args[0] and forwards to its slot virtuals. vftable at ??_G 0x142302d90 (Call inherited).
// Code in ?\notifydragslot.cpp (0x142301ff0-0x142302df0); header name and directory assumed, the method names are
// invented after the AS names.
#pragma once

#include "ms2/gfxui/notifyhandler.h"

class NotifyDragSlot : public NotifyHandler
{
public:
    explicit NotifyDragSlot(Unk_NotifyContext* pContext);           // 0x142301ff0
    // ~NotifyDragSlot is implicit (0x142302cf0; ??_G 0x142302d90)

    void SlotUse(const Params& params);                             // 0x142302210 args: slot[, button]
    void SlotShiftClick(const Params& params);                      // 0x1423023e0 args: slot
    void SlotDragStart(const Params& params);                       // 0x1423024d0 args: slot
    void SlotDragEnd(const Params& params);                         // 0x1423025d0 args: source slot, target slot
    void GetSlotTooltip(const Params& params);                      // 0x142302860 args: slot; returns the tooltip object
    void GetBagSlotBindings(const Params& params);                  // 0x142302990 args: bag

    // The table entries (NotifyHandler::Callback): forward to the members above.
    static void OnSlotUse(NotifyHandler* pHandler, const Params& params);             // 0x142302a90
    static void OnSlotShiftClick(NotifyHandler* pHandler, const Params& params);      // 0x142302ad0
    static void OnSlotDragStart(NotifyHandler* pHandler, const Params& params);       // 0x142302b10
    static void OnSlotDragEnd(NotifyHandler* pHandler, const Params& params);         // 0x142302b50
    static void OnGetSlotTooltip(NotifyHandler* pHandler, const Params& params);      // 0x142302b90
    static void OnGetBagSlotBindings(NotifyHandler* pHandler, const Params& params);  // 0x142302bd0
};
MS2_CHECK_SIZE(NotifyDragSlot, 0x48);
