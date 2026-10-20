// pcgemequip.h - PLACEHOLDER for the actor's gem equipment (not polymorphic, 0x70 bytes; no RTTI, name invented; v2525
// calls it PC::Object1078). The actor (PC +0x1078) keeps one MS2Ptr<CItem> per gem type; the unit holding its code
// (0x14126fce0-0x141272630, 4 KB of it called by gemslot.cpp) is a separate original TU. FUN_14165f460(pPC) hands it out.
// Gem type -> array index: type 0 = -1, otherwise type - 1 (FUN_141271290); the count of the array is FUN_140222f50().
// NOT an original header.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class PC;
class CGemBase;
class CGemTransparency;
class CInputStream;

class PCGemEquip
{
public:
    PCGemEquip();                                           // 0x14126fce0
    ~PCGemEquip();                                          // 0x14126fd70 takes the gems of types 10, 7, 11, 12 off
    void FUN_14126fea0(CInputStream& stream, int nOwner);   // 0x14126fea0 read the worn gem items of a packet
    void FUN_141270030(int nGemType, MS2Ptr<CItem> spItem); // 0x141270030 store the item at the index of the type
    unsigned FUN_1412700b0();                               // 0x1412700b0 number of slots
    int FUN_1412700e0(ATL::CAtlArray<MS2Ptr<CItem> >& out);   // 0x1412700e0 copy of the items; nonempty
    MS2Ptr<CItem> FUN_141270140(int nGemType);              // 0x141270140 the item worn for a gem type (checks its type)
    bool FUN_141270290(int nItemId);                        // 0x141270290 an item with this item id is worn
    CGemTransparency* FUN_141270360(unsigned char nIndex);  // 0x141270360 the transparency gem (type 1) of slot nIndex
    CGemTransparency* FUN_141270460();                      // 0x141270460 the first transparency gem
    void FUN_1412704d0();                                   // 0x1412704d0 apply the worn gems (CItemGem::vfunc_5)
    void FUN_141270610();                                   // 0x141270610 CItemGem::vfunc_6 of every slot
    void FUN_141270680();                                   // 0x141270680 CItemGem::vfunc_7 of every slot
    int FUN_1412706f0(int nSlot);                           // 0x1412706f0 the transparency gem's hidden flag of an equip slot
    MS2Ptr<CGemBase> FUN_141270740(int nGemType);           // 0x141270740 the gem worn for a type
    MS2Ptr<CItem> FUN_1412709d0(MS2Ptr<CItem> spItem);      // 0x1412709d0 take the gem item off
    MS2Ptr<CItem> FUN_141270ab0(int nGemType);              // 0x141270ab0 take the item of a type off
    bool FUN_141270bf0(MS2Ptr<CItem> spItem);               // 0x141270bf0 put the gem item on
    bool FUN_141270cd0(int nGemType, MS2Ptr<CItem> spItem); // 0x141270cd0 put the item on at a type
    void FUN_141270e00(PCGemEquip& other);                  // 0x141270e00 copy the items of another equipment
    void FUN_141270f10(ATL::CAtlArray<MS2Ptr<CItem> >& items, int n);   // 0x141270f10 take the worn items from a list
    bool FUN_141271090(MS2Ptr<CItem> spItem, const CString& strEffect);   // 0x141271090 start the effect of a gem item
    void FUN_1412711e0(MS2Ptr<CItem> spItem);               // 0x1412711e0 stop it
    int FUN_141271290(int nGemType);                        // 0x141271290 the array index of a gem type
    MS2Ptr<CItem> FUN_1412712e0(int nIndex);                // 0x1412712e0 the item at an index (calls CItemGem::vfunc_6)
    MS2Ptr<CItem> FUN_141271500(int nIndex);                // 0x141271500 the item at an index (calls CItemGem::vfunc_7)
    MS2Ptr<CItem> FUN_141271630(int nIndex);                // 0x141271630 the item at an index
    void FUN_1412716d0(int nIndex, MS2Ptr<CItem> spItem);   // 0x1412716d0 set the item at an index
    bool FUN_141271750(int nGemType);                       // 0x141271750 types 5 and 6
    void FUN_141271780(int nGemType, MS2Ptr<CItem> spItem); // 0x141271780 register a skin gem item
    void FUN_141271870(int nGemType, MS2Ptr<CItem> spItem); // 0x141271870 unregister it

    void FUN_141668230(PC* pOwner) { m_pOwner = pOwner; }   // set the owner (inline; first emitted by the PC ctor)

    PC* m_pOwner;                                           // +0x00
    ATL::CAtlArray<MS2Ptr<CItem> > m_items;                 // +0x08 one per gem type
    ATL::CAtlMap<__int64, int> m_mapEffect;                 // +0x28 item uid -> effect handle
};
MS2_CHECK_SIZE(PCGemEquip, 0x70);
MS2_CHECK_OFFSET(PCGemEquip, m_items, 0x08);
MS2_CHECK_OFFSET(PCGemEquip, m_mapEffect, 0x28);

// The equip request payloads of packet 0x47 (gem equip / unequip).
struct Unk_GemEquipReq
{
    __int64 m_nItemUid;
    unsigned char m_nSlot;
    Unk_GemEquipReq();                                      // 0x1412722b0
};
struct Unk_GemUnequipReq
{
    unsigned char m_nSlot;
    Unk_GemUnequipReq();                                    // 0x141272290
};
