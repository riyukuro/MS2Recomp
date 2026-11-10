// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Third translation unit of the client UGC code (the queue
// entry client\ms2\ugcmanager.cpp spans four TUs; see ugcmanager.h): UGCItemSlot, the drag slot of a UGC item list.
// MS2-UNIT: client\ms2\ugcmanager.cpp#3
// MS2-RANGE: 0x14187d7e0-0x14187e3d0 .text$mn
// MS2-RANGE: 0x14010f100-0x14010f2d0 .text$di
// MS2-RANGE: 0x142cbc410-0x142cbc530 .text$yd
// MS2-PIN: ??_7UGCItemSlot@@6BBindData@NotifyContext@@@ 0x142f8b450
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ugcmanager.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/worldservice.h"

// Game context: FUN_141bd0cc0 returns the local player (the tooltip owner).

MS2Ptr<CItemData> FUN_14053f870(int nItemId);           // item template data by id
int GetItemUsableState(CItem* pItem);                         // the usable state of an item (1 locked, 2 disabled, 3 condition)
CStringW FUN_14016a730(const char* sz, int nCodePage);   // multi-byte to wide

// Registry of named bags/slots (GFx bind data).
#include "ms2/gfxui/notifyhandler.h"   // C3: Unk_NotifyContext::FUN_1422c8e90/f10/f70

EE_IMPLEMENT_CONCRETE_CLASS_INFO(UGCItemSlot);

// The AS member names of the slot data.
static CString s_strDisable = "disable";
static CString s_strIconPath = "iconPath";
static CString s_strIndex = "index";
static CString s_strItemCash = "itemCash";
static CString s_strItemCount = "itemCount";
static CString s_strItemGrade = "itemGrade";
static CString s_strItemLock = "itemLock";
static CString s_strItemNew = "itemNew";
static CString s_strItemConditionLock = "itemConditionLock";

// @0x14187d7e0
UGCItemSlot::UGCItemSlot(const CString& strName, MS2Ptr<CItem> spItem)
    : MS2DragSlot(strName, 0), m_spItem(spItem)
{
}

// @0x14187d870
int UGCItemSlot::GetItemTemplateId()
{
    if (m_spItem == 0)
        return 0;
    return m_spItem->GetItemId();
}
MS2_REPLACE_METHOD(0x14187d870, UGCItemSlot, GetItemTemplateId, 73, 0xC60F55F1);

// @0x14187d8c0
void UGCItemSlot::SetItem(MS2Ptr<CItem> spItem)
{
    m_spItem = spItem;
}
MS2_REPLACE_METHOD(0x14187d8c0, UGCItemSlot, SetItem, 63, 0x6996C064);

// @0x14187d910
MS2Ptr<CItem> UGCItemSlot::vfunc_25()
{
    return m_spItem;
}
MS2_REPLACE_METHOD(0x14187d910, UGCItemSlot, vfunc_25, 67, 0x3FBB1857);

// @0x14187d960
int UGCItemSlot::vfunc_11()
{
    m_spItem = 0;
    return DragSlot::vfunc_11();
}
MS2_REPLACE_METHOD(0x14187d960, UGCItemSlot, vfunc_11, 45, 0x1293AB82);

// @0x14187d9a0
int UGCItemSlot::vfunc_26(ASObj& obj)
{
    if (m_spItem == 0)
        return 0;
    MS2Ptr<CItemData> spData = FUN_14053f870(m_spItem->GetItemId());
    if (!spData)
        return 0;
    obj.SetBoolMember(s_strItemCash, spData->IsCashItem());
    int nState = GetItemUsableState(m_spItem.get());
    if (nState == 1)
        obj.SetBoolMember(s_strItemLock, true);
    else if (nState == 2)
        obj.SetBoolMember(s_strDisable, true);
    else if (nState == 3)
        obj.SetBoolMember(s_strItemConditionLock, true);
    obj.SetIntMember(s_strIndex, m_nIndex);
    obj.SetIntMember(s_strItemCount, 0);
    obj.FUN_1409adc90(s_strItemGrade, m_spItem->GetRarity());
    obj.SetWStringMember(s_strIconPath, FUN_14016a730(m_spItem->GetIconPath(), 0));
    obj.SetIntMember(s_strItemNew, 0);
    return 1;
}
MS2_REPLACE_METHOD(0x14187d9a0, UGCItemSlot, vfunc_26, 712, 0x8A7B3C34);

// @0x14187dc70 (ITooltip::vfunc_0)
int UGCItemSlot::vfunc_0(void* p)
{
    if (m_spItem == 0)
        return 0;
    ASTooltip tip(WorldService::GetInstance()->FUN_141bd0cc0(), 0x20, 2);
    if (tip.FUN_1409e0d40(m_spItem.get()))
    {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.GetValue();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD_VIA(0x14187dc70, UGCItemSlot, ITooltip, vfunc_0, 218, 0x404A021E);

// @0x14187dd50
int UGCItemSlot::vfunc_8(void* p)
{
    if (m_spItem == 0)
        return 0;
    ASObj obj(2);
    vfunc_26(obj);
    *static_cast<Scaleform::GFx::Value*>(p) = obj.GetValue();
    return 1;
}
MS2_REPLACE_METHOD(0x14187dd50, UGCItemSlot, vfunc_8, 157, 0xDF8915C2);

// @0x14187de00
void FUN_14187de00(const CString& strName, MS2Ptr<CItem> spItem)
{
    UGCItemSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) UGCItemSlot(strName, spItem);
    if (pSlot)
        Unk_NotifyContext::RegisterBinding(strName, pSlot);
}
MS2_REPLACE(0x14187de00, FUN_14187de00, 213, 0x341DE3D3);

// @0x14187dee0
void UnbindItemSlot(const CString& strName)
{
    UGCItemSlot* pSlot = efd::DynamicCast<UGCItemSlot>(Unk_NotifyContext::FindBinding(strName));
    if (pSlot)
        Unk_NotifyContext::UnregisterBinding(strName);
}
MS2_REPLACE(0x14187dee0, UnbindItemSlot, 55, 0xE2F5333B);

// The UCRT's `static __inline memcpy_s` (corecrt_memcpy_s.h), emitted because the original TU kept an unreferenced copy.
#pragma function(memcpy, memset)
// @0x14187e110
static __inline errno_t ms2_memcpy_s_copy(void* const d, size_t const dsz, void const* const s, size_t const ssz)
{
    if (ssz == 0) { return 0; }
    { int e = !!(d != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
    if (s == NULL || dsz < ssz)
    {
        memset(d, 0, dsz);
        { int e = !!(s != NULL); if (!e) { errno = EINVAL; _invalid_parameter_noinfo(); return EINVAL; } }
        { int e = !!(dsz >= ssz); if (!e) { errno = ERANGE; _invalid_parameter_noinfo(); return ERANGE; } }
        return EINVAL;
    }
    memcpy(d, s, ssz);
    return 0;
}
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy;
// @0x14187e260
MS2_EMIT_CRT_MEMMOVE_S();
