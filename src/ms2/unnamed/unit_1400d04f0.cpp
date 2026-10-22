// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). EnchantScrollSlot (the scroll slot of the item enchant scroll
// window), with the .text$di initializer of EnchantScrollSlot::ms_ClassInfo. See enchantscrollslot.h.
// (units.tsv lists the mn range as 0x140cd73b0-0x140cd7e40; the fishing-guide TU (cubecraft_1: Unk_FishLine ctor 0x140cd7d80)
// and the two string-table inlines 0x140cd7ce0 / 0x140cd7d20 start at 0x140cd7ce0, so the range ends there.)
// MS2-UNIT: ?\enchantscrollslot.cpp
// MS2-RANGE: 0x140cd73b0-0x140cd7ce0 .text$mn
// MS2-RANGE: 0x1400d04f0-0x1400d0510 .text$di
// MS2-PIN: ??_7EnchantScrollSlot@@6BBindData@NotifyContext@@@ 0x142e1dd70 ; hand: primary vftable
// MS2-PIN: ?GetClassDesc@EnchantScrollSlot@@UEBAPEBVClassInfo@efd@@XZ 0x140cd7bd0 ; hand
// MS2-PIN: ?TypeCast@EnchantScrollSlot@@UEBA_NIPEAPEAX@Z 0x140cd7c40 ; hand
// MS2-PIN: ?TypeCast@EnchantScrollSlot@@UEBA_NIPEAPEBX@Z 0x140cd7c90 ; hand
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\enchantscrollslot.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/enchantscrollslot.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/inventory.h"
#include "hook/ms2hook.h"
#include <efd/MemHint.h>
#include <efd/MemObject.h>

// ---- out-of-unit callees ----
class Unk_GameCtx
{
public:
    void* FUN_141bd0cc0();
};
Unk_GameCtx* FUN_1403ed2d0();

extern Unk_Inventory DAT_143ab2a90;                     // the player's inventory

// The item enchant scroll dialog (id 0x4ee0).
class UIEnchantScrollDialog : public UIDialog
{
public:
    void FUN_140f3cb10();                               // refresh after the scroll slot was cleared
};

// UI service: handle to a registered UI object.
class Unk_EnchantUIManager { public: MS2Ptr<UIObject> FUN_141adcea0(int nClass); };
Unk_EnchantUIManager* FUN_1403ed2b0();

void* FUN_140a50b50(DragSlot* pSlot);                   // the item slot behind a drag source
__int64 FUN_141405a10(void* pItemSlot);                 // its item uid
int FUN_141902660(MS2Ptr<CItem> spItem);                // asks whether to refund the enchant experience (nonzero: handled)
void FUN_140710590(COutPacket& packet);                 // send the packet

// Registry of named bags/slots (GFx bind data).
void FUN_1422c8f10(const CString& strName, NotifyContext::BindData* pBag);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
void FUN_1422c8f70(const CString& strName);

EnchantScrollSlot* FUN_140cd7a50(NotifyContext::BindData* p);
UIEnchantScrollDialog* FUN_140cd7aa0(int nClass);

EE_IMPLEMENT_CONCRETE_CLASS_INFO(EnchantScrollSlot);

// @0x140cd73b0
void FUN_140cd73b0(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem)
{
    EnchantScrollSlot* pSlot = new (efd::MemHint(efd::MemHint::NONE)) EnchantScrollSlot(strName, nOwner, spItem);
    if (pSlot)
        FUN_1422c8f10(strName, pSlot);
}

// @0x140cd74a0
void FUN_140cd74a0(const CString& strName)
{
    EnchantScrollSlot* pSlot = FUN_140cd7a50(FUN_1422c8e90(strName));
    if (pSlot)
        FUN_1422c8f70(strName);
}

// @0x140cd74e0
EnchantScrollSlot::EnchantScrollSlot(const CString& strName, unsigned __int64 nOwner, MS2Ptr<CItem> spItem)
    : MS2DragSlot(strName, 0), m_nOwner(nOwner), m_spItem(spItem)
{
}

// @0x140cd7580
int EnchantScrollSlot::vfunc_17()
{
    SetItem(MS2Ptr<CItem>(0));
    UIEnchantScrollDialog* pDlg = FUN_140cd7aa0(0x4ee0);
    if (pDlg != 0)
        pDlg->FUN_140f3cb10();
    return vfunc_10();
}

// @0x140cd75f0
int EnchantScrollSlot::vfunc_18(void* p)
{
    void* pItemSlot = FUN_140a50b50(static_cast<DragSlot*>(p));
    if (pItemSlot != 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(FUN_141405a10(pItemSlot));
        if (spItem.get() != 0)
        {
            if (FUN_141902660(spItem) != 0)
                return static_cast<DragSlot*>(p)->vfunc_10();
            COutPacket packet(static_cast<int>(SendOp::EnchantScroll), 0);
            packet.vfunc_o10_1(1);
            packet.vfunc_o10_4(m_nOwner);
            packet.vfunc_o10_4(((CItem*)spItem)->FUN_140526a50());
            FUN_140710590(packet);
        }
    }
    return static_cast<DragSlot*>(p)->vfunc_10();
}

// @0x140cd7760
int EnchantScrollSlot::vfunc_14()
{
    vfunc_17();
    return 1;
}

// @0x140cd7790
MS2Ptr<CItem> EnchantScrollSlot::vfunc_25()
{
    return m_spItem;
}

// @0x140cd77e0
void EnchantScrollSlot::SetItem(MS2Ptr<CItem> spItem)
{
    m_spItem = spItem;
}

// @0x140cd7830 (ITooltip::vfunc_0)
int EnchantScrollSlot::vfunc_0(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASTooltip tip(pPlayer, 0x20, 2);
    int nOk = tip.FUN_1409e0d40(vfunc_25().get());
    if (nOk != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = tip.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140cd7950
int EnchantScrollSlot::vfunc_8(void* p)
{
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ASSlot slot(2);
    int nOk = slot.FUN_1409c3860(vfunc_25().get(), pPlayer, 1);
    if (nOk != 0)
    {
        *static_cast<Scaleform::GFx::Value*>(p) = slot.FUN_1422bb870();
        return 1;
    }
    return 0;
}

// @0x140cd7a50
EnchantScrollSlot* FUN_140cd7a50(NotifyContext::BindData* p)
{
    EnchantScrollSlot* pSlot = 0;
    if (p != 0 && p->TypeCast(0x6200063, (void**)&pSlot))
        return pSlot;
    else
        return 0;
}

// @0x140cd7aa0
UIEnchantScrollDialog* FUN_140cd7aa0(int nClass)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObj = FUN_1403ed2b0()->FUN_141adcea0(nClass);
        if (spObj.get() != 0)
            return dynamic_cast<UIEnchantScrollDialog*>(spObj.operator->());
    }
    return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();

// ---- hooks ----
MS2_REPLACE(0x140CD74A0, FUN_140cd74a0, 55, 0x09F947E0);
MS2_REPLACE_METHOD(0x140CD7580, EnchantScrollSlot, vfunc_17, 105, 0x88ECC05A);
MS2_REPLACE_METHOD(0x140CD75F0, EnchantScrollSlot, vfunc_18, 347, 0xC8B80028);
MS2_REPLACE_METHOD(0x140CD7760, EnchantScrollSlot, vfunc_14, 38, 0xF4633F56);
MS2_REPLACE_METHOD(0x140CD7790, EnchantScrollSlot, vfunc_25, 67, 0xCDBE6222);
MS2_REPLACE_METHOD(0x140CD7950, EnchantScrollSlot, vfunc_8, 255, 0xC984E3D5);
MS2_REPLACE(0x140CD7A50, FUN_140cd7a50, 73, 0xCE611679);
MS2_REPLACE(0x140CD7AA0, FUN_140cd7aa0, 147, 0xCF4161F7);
