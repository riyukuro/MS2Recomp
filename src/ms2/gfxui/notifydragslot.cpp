// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NotifyDragSlot, the notify handler of the drag & drop
// slots' ActionScript callbacks. See notifydragslot.h.
// MS2-UNIT: ?\notifydragslot.cpp
// MS2-RANGE: 0x142301ff0-0x142302df0 .text$mn
//
// The unit name and directory are assumed (the GFx UI library has no __FILE__ strings). The tail is the implicit dtor
// and the efd::SmartPointer<DragSlot> / <DragSlotBag> members the handlers instantiate.
// MS2-PIN: ??_GNotifyDragSlot@@UEAAPEAXI@Z 0x142302d90
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/gfxui/notifydragslot.h"
#include "ms2/gfxui/dragslot.h"
#include "ms2/placeholder/gfxmanager.h"
#include "hook/ms2hook.h"

using Scaleform::GFx::Value;

DragSlot* FUN_1422cd480(NotifyContext::BindData* pData);         // efd::DynamicCast<DragSlot> (TypeCast 0x06202735)
DragSlotBag* FUN_140c544d0(NotifyContext::BindData* pData);      // efd::DynamicCast<DragSlotBag>

// @0x142301ff0
NotifyDragSlot::NotifyDragSlot(Unk_NotifyContext* pContext)
    : NotifyHandler(pContext)
{
    m_callbacks.SetAt("notifySlotUse", &NotifyDragSlot::OnSlotUse);
    m_callbacks.SetAt("notifySlotShiftClick", &NotifyDragSlot::OnSlotShiftClick);
    m_callbacks.SetAt("notifySlotDragStart", &NotifyDragSlot::OnSlotDragStart);
    m_callbacks.SetAt("notifySlotDragEnd", &NotifyDragSlot::OnSlotDragEnd);
    m_callbacks.SetAt("getSlotTooltip", &NotifyDragSlot::OnGetSlotTooltip);
    m_callbacks.SetAt("getBagSlotBindings", &NotifyDragSlot::OnGetBagSlotBindings);
}

// @0x142302210
void NotifyDragSlot::SlotUse(const Params& params)
{
    if (params.ArgCount < 1)
        return;
    const Value& vName = params.pArgs[0];
    if (vName.IsUndefined() || vName.IsNull())
        return;
    int bShift = GetKeyState(VK_SHIFT) & 0x8000;
    CString strName(vName.GetString());
    int nButton = params.ArgCount == 1 ? 0 : params.pArgs[1].GetInt();
    efd::SmartPointer<DragSlot> spSlot = FUN_1422cd480(Unk_NotifyContext::FUN_1422c8e90(strName));
    if (spSlot)
    {
        if (nButton == 0)
        {
            if (bShift == 0)
                spSlot->vfunc_13();
        }
        else if (nButton == 1)
        {
            if (spSlot->vfunc_19() != 0)
                spSlot->vfunc_16();
            else
                spSlot->vfunc_14();
        }
    }
}
MS2_REPLACE_METHOD(0x142302210, NotifyDragSlot, SlotUse, 456, 0xD753F605);

// @0x1423023e0
void NotifyDragSlot::SlotShiftClick(const Params& params)
{
    if (params.ArgCount < 1)
        return;
    const Value& vName = params.pArgs[0];
    if (vName.IsUndefined() || vName.IsNull())
        return;
    CString strName(vName.GetString());
    efd::SmartPointer<DragSlot> spSlot = FUN_1422cd480(Unk_NotifyContext::FUN_1422c8e90(strName));
    if (spSlot)
        spSlot->vfunc_15();
}
MS2_REPLACE_METHOD(0x1423023e0, NotifyDragSlot, SlotShiftClick, 229, 0x6310FF27);

// @0x1423024d0
void NotifyDragSlot::SlotDragStart(const Params& params)
{
    if (params.ArgCount < 1)
        return;
    const Value& vName = params.pArgs[0];
    if (vName.IsUndefined() || vName.IsNull())
        return;
    CString strName(vName.GetString());
    efd::SmartPointer<DragSlot> spSlot = FUN_1422cd480(Unk_NotifyContext::FUN_1422c8e90(strName));
    if (spSlot)
        spSlot->vfunc_20();
}
MS2_REPLACE_METHOD(0x1423024d0, NotifyDragSlot, SlotDragStart, 235, 0x0FCB4296);

// @0x1423025d0
void NotifyDragSlot::SlotDragEnd(const Params& params)
{
    if (params.ArgCount < 2)
        return;
    const Value& vSrc = params.pArgs[0];
    if (vSrc.IsUndefined() || vSrc.IsNull())
        return;
    CString strSrc(vSrc.GetString());
    CString strDst(params.pArgs[1].IsString() ? params.pArgs[1].GetString() : NULL);
    efd::SmartPointer<DragSlot> spSrc = FUN_1422cd480(Unk_NotifyContext::FUN_1422c8e90(strSrc));
    if (spSrc)
    {
        efd::SmartPointer<DragSlot> spDst = FUN_1422cd480(Unk_NotifyContext::FUN_1422c8e90(strDst));
        if (spDst)
        {
            if (spSrc == spDst)
                spDst->vfunc_12();
            else
                spDst->vfunc_18(spSrc);
        }
        else
        {
            int nState = FUN_14025e7a0()->FUN_1422aeed0(2);
            if (nState != 0)
                spSrc->vfunc_12();
            else
                spSrc->vfunc_17();
        }
        spSrc->vfunc_21();
    }
}
MS2_REPLACE_METHOD(0x1423025d0, NotifyDragSlot, SlotDragEnd, 638, 0x60D7BF4B);

// @0x142302860
void NotifyDragSlot::GetSlotTooltip(const Params& params)
{
    if (params.ArgCount < 1)
        return;
    const Value& vName = params.pArgs[0];
    if (vName.IsUndefined() || vName.IsNull())
        return;
    CString strName(vName.GetString());
    efd::SmartPointer<DragSlot> spSlot = FUN_1422cd480(Unk_NotifyContext::FUN_1422c8e90(strName));
    if (spSlot)
    {
        Scaleform::GFx::Movie* pMovie = params.pMovie;
        if (pMovie != NULL)
        {
            pMovie->CreateObject(params.pRetVal);
            spSlot->vfunc_0(params.pRetVal);
        }
    }
}
MS2_REPLACE_METHOD(0x142302860, NotifyDragSlot, GetSlotTooltip, 297, 0x96D4F4A3);

// @0x142302990
void NotifyDragSlot::GetBagSlotBindings(const Params& params)
{
    if (params.ArgCount < 1)
        return;
    const Value& vName = params.pArgs[0];
    if (vName.IsUndefined() || vName.IsNull())
        return;
    CString strName(vName.GetString());
    efd::SmartPointer<DragSlotBag> spBag = FUN_140c544d0(m_spContext->FUN_1422c8e90(strName));
    if (spBag)
        spBag->FUN_1422cd1c0(params);
}
MS2_REPLACE_METHOD(0x142302990, NotifyDragSlot, GetBagSlotBindings, 241, 0xF8699F9E);

// @0x142302a90
void NotifyDragSlot::OnSlotUse(NotifyHandler* pHandler, const Params& params)
{
    NotifyDragSlot* pThis = static_cast<NotifyDragSlot*>(pHandler);
    if (pThis != NULL)
        pThis->SlotUse(params);
}
MS2_REPLACE(0x142302a90, NotifyDragSlot::OnSlotUse, 52, 0x8FB44118);

// @0x142302ad0
void NotifyDragSlot::OnSlotShiftClick(NotifyHandler* pHandler, const Params& params)
{
    NotifyDragSlot* pThis = static_cast<NotifyDragSlot*>(pHandler);
    if (pThis != NULL)
        pThis->SlotShiftClick(params);
}
MS2_REPLACE(0x142302ad0, NotifyDragSlot::OnSlotShiftClick, 52, 0x102CBA7F);

// @0x142302b10
void NotifyDragSlot::OnSlotDragStart(NotifyHandler* pHandler, const Params& params)
{
    NotifyDragSlot* pThis = static_cast<NotifyDragSlot*>(pHandler);
    if (pThis != NULL)
        pThis->SlotDragStart(params);
}
MS2_REPLACE(0x142302b10, NotifyDragSlot::OnSlotDragStart, 52, 0x83EED7CE);

// @0x142302b50
void NotifyDragSlot::OnSlotDragEnd(NotifyHandler* pHandler, const Params& params)
{
    NotifyDragSlot* pThis = static_cast<NotifyDragSlot*>(pHandler);
    if (pThis != NULL)
        pThis->SlotDragEnd(params);
}
MS2_REPLACE(0x142302b50, NotifyDragSlot::OnSlotDragEnd, 52, 0x6C357405);

// @0x142302b90
void NotifyDragSlot::OnGetSlotTooltip(NotifyHandler* pHandler, const Params& params)
{
    NotifyDragSlot* pThis = static_cast<NotifyDragSlot*>(pHandler);
    if (pThis != NULL)
        pThis->GetSlotTooltip(params);
}
MS2_REPLACE(0x142302b90, NotifyDragSlot::OnGetSlotTooltip, 52, 0x1459F65B);

// @0x142302bd0
void NotifyDragSlot::OnGetBagSlotBindings(NotifyHandler* pHandler, const Params& params)
{
    NotifyDragSlot* pThis = static_cast<NotifyDragSlot*>(pHandler);
    if (pThis != NULL)
        pThis->GetBagSlotBindings(params);
}
MS2_REPLACE(0x142302bd0, NotifyDragSlot::OnGetBagSlotBindings, 52, 0xABFC483A);
