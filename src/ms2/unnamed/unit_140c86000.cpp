// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The player's four-slot item holder (ctor, clear, read from
// a stream, find by uid, get slot, put, remove by uid), followed by the TU's two CRT copies (memcpy_s, memmove_s).
// The class name is the one scenestategame.cpp already uses (Unk_PCItemCooldowns); method names are invented.
// MS2-UNIT: unit_140c86000
// MS2-RANGE: 0x140c86000-0x140c86860 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/citem.h"
#include "ms2/commonfiles/stream.h"
#include "hook/ms2hook.h"
#include <errno.h>
#include <string.h>

class Unk_PCItemCooldowns
{
public:
    Unk_PCItemCooldowns();                                  // 0x140c86000
    void FUN_140c86060();                                   // clear all four slots
    void FUN_140c860b0(CInputStream& stream, int nObjId);   // read the slots from a stream
    MS2Ptr<CItem> FUN_140c862c0(__int64 nItemUid);          // find by uid
    MS2Ptr<CItem> FUN_140c863c0(int nSlot);                 // get a slot
    bool FUN_140c86450(MS2Ptr<CItem> spItem);               // put at the item's own slot
    bool FUN_140c86510(__int64 nItemUid);                   // clear the slot holding the uid
private:
    MS2Ptr<CItem> m_items[4];
};
MS2_CHECK_SIZE(Unk_PCItemCooldowns, 0x40);

// @0x140c86000
Unk_PCItemCooldowns::Unk_PCItemCooldowns()
{
    FUN_140c86060();
}

// @0x140c86060
void Unk_PCItemCooldowns::FUN_140c86060()
{
    for (int i = 0; i < 4; i++)
        m_items[i] = 0;
}
MS2_REPLACE_METHOD(0x140C86060, Unk_PCItemCooldowns, FUN_140c86060, 73, 0xCCA14FC7);

// @0x140c860b0
// MS2-FUNCTIONAL: the slot index reaches CItem::FUN_140526b70 via ecx->edx and a trailing nop after the assign; no source form found
void Unk_PCItemCooldowns::FUN_140c860b0(CInputStream& stream, int nObjId)
{
    FUN_140c86060();
    unsigned nCount = stream.ReadUInt8();
    for (int i = 0; i < (int)nCount; i++)
    {
        int nItemId = stream.ReadInt32();
        __int64 nItemUid = stream.ReadInt64();
        short nSlot = stream.ReadInt16();
        int nRarity = stream.ReadInt32();
        if (nSlot >= 4)
            break;
        MS2Ptr<CItem> spItem(new CItem);
        if (!spItem->FUN_140523c40(nItemId, nRarity, 0))
            return;
        int nSlotIdx = nSlot;
        spItem->FUN_140526b70(nSlotIdx);
        spItem->FUN_140526a70(nItemUid);
        spItem->FUN_140526b30(nObjId);
        spItem->FUN_140524eb0(stream);
        m_items[nSlot] = spItem;
    }
}
MS2_REPLACE_METHOD(0x140C860B0, Unk_PCItemCooldowns, FUN_140c860b0, 517, 0x254F634E);

// @0x140c862c0
MS2Ptr<CItem> Unk_PCItemCooldowns::FUN_140c862c0(__int64 nItemUid)
{
    for (int i = 0; i < 4; i++)
    {
        MS2Ptr<CItem> spItem = m_items[i];
        if (spItem == 0)
            continue;
        if (spItem->FUN_140526a50() == nItemUid)
            return spItem;
    }
    return MS2Ptr<CItem>(0);
}
MS2_REPLACE_METHOD(0x140C862C0, Unk_PCItemCooldowns, FUN_140c862c0, 248, 0xC0FC3870);

// @0x140c863c0
MS2Ptr<CItem> Unk_PCItemCooldowns::FUN_140c863c0(int nSlot)
{
    if (nSlot >= 4 || nSlot < 0)
        return MS2Ptr<CItem>(0);
    return m_items[nSlot];
}
MS2_REPLACE_METHOD(0x140C863C0, Unk_PCItemCooldowns, FUN_140c863c0, 125, 0xB4758069);

// @0x140c86450
bool Unk_PCItemCooldowns::FUN_140c86450(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return false;
    int nSlot = spItem->FUN_140526b50();
    if (nSlot >= 4 || nSlot < 0)
        return false;
    m_items[nSlot] = spItem;
    return true;
}
MS2_REPLACE_METHOD(0x140C86450, Unk_PCItemCooldowns, FUN_140c86450, 180, 0xD90BCC37);

// @0x140c86510
bool Unk_PCItemCooldowns::FUN_140c86510(__int64 nItemUid)
{
    for (int i = 0; i < 4; i++)
    {
        MS2Ptr<CItem> spItem = m_items[i];
        if (spItem == 0)
            continue;
        if (spItem->FUN_140526a50() == nItemUid)
        {
            m_items[i] = 0;
            return true;
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x140C86510, Unk_PCItemCooldowns, FUN_140c86510, 218, 0xE9ECD27E);

// @0x140c865f0
// memcpy_s (the CRT's _VALIDATE_RETURN_ERRCODE form, per-TU static __inline copy).
#pragma function(memset, memcpy)
static __inline errno_t ms2_memcpy_s_copy1(void* const d, size_t const dsz, void const* const s, size_t const ssz)
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
__declspec(selectany) extern errno_t(__cdecl* const ms2_pfnMemcpySCopy1)(void*, size_t, const void*, size_t) = &ms2_memcpy_s_copy1;

// @0x140c86740
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
