// itemremakeoption.h - PLACEHOLDER for the item option remake helpers (?\itemremakescrolldata.cpp, 0x140616b60..0x14061ac50,
// unrecovered) and the option-lock record of the 0x75 (item remake option) packets. NOT an original header (w475).
// The same Unk_RemakeStat is still declared locally in uiitemremakescrolldialog.cpp and unit_14129cfa0.cpp (identical
// layout); new units should include this header instead.
#pragma once

#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/commonstruct_wa.h"

// A locked option of a remake request: the option index and its value, 8 bytes. The ctor 0x140b98d30 (an inline COMDAT,
// first emitted by ?\tabcontentspetremakeoption.cpp) zeroes both ints. It is the element of the option list of
// CCItemRemakeOptionPacket::RemakeOption (citemremakeoptionpacket.h: Unk_RemakeOptionList50 is this std::vector, 0x18
// bytes; push_back(const&) 0x140b9b410 and its emplace_back glue 0x140b99c40..0x140b9a170 are in the same unit).
// citemremakeoptionpacket.h's 4-byte Unk_LockOpt is the same record seen through its first int only.
struct Unk_RemakeLockOpt
{
    Unk_RemakeLockOpt() : m_nIndex(0), m_nValue(0) {}   // 0x140b98d30
    int m_nIndex;                                       // +0x0 the option index
    int m_nValue;                                       // +0x4 its value
};
MS2_CHECK_SIZE(Unk_RemakeLockOpt, 8);
typedef std::vector<Unk_RemakeLockOpt> Unk_RemakeLockOptList;
MS2_CHECK_SIZE(Unk_RemakeLockOptList, 0x18);

// The remake stat view of an item (the 0x20 byte record the option texts are built from; ctor 0x140617de0, dtor
// 0x14061ac50). nMode is the remake kind (2 = pet / option remake); bFinal selects the item's current options.
class Unk_RemakeStat
{
public:
    Unk_RemakeStat(unsigned nMode, MS2Ptr<CItem> item, bool bFinal);   // 0x140617de0
    ~Unk_RemakeStat();                                                  // 0x14061ac50
    bool FUN_140619290(int nOption, int& nIndex, int& nValue);          // the nOption-th option as a lock record
    unsigned m_nMode;                                                   // +0x00
    int m_pad4;
    MS2Ptr<CItem> m_item;                                               // +0x08
    void* m_pad18;
};
MS2_CHECK_SIZE(Unk_RemakeStat, 0x20);

int FUN_140616dd0(MS2Ptr<CItem> item);                      // the lock item id of an item (0 = no lock possible)
unsigned FUN_140616f10(MS2Ptr<CItem> item);                 // the lock item's level
bool FUN_140616fd0(MS2Ptr<CItem> item);                     // options may be locked
int FUN_140616b60(MS2Ptr<CItemData> data, unsigned* pDiscount, unsigned nRate);   // item remake sale (0 none, 1, 2 = sa)
int FUN_140616c50(MS2Ptr<CItemData> data, unsigned* pDiscount, unsigned nRate);   // pet remake sale (0 none, 1, 2 = sa)
int FUN_140616d40(int nCount, unsigned nDiscount);          // the discounted ingredient count
unsigned FUN_1406191e0(unsigned nMode, MS2Ptr<CItem> item); // the number of options of an item
CStringW FUN_140619760(int nItemId, unsigned nLevel);       // the lock item's name
CStringW FUN_140617e50(const CStringW& strKey, Unk_RemakeStat& stat, unsigned* pCount);   // the option text under strKey
CStringW FUN_140617ef0(Unk_RemakeStat& stat, unsigned* pCount);                     // the option text
CStringW FUN_140619070(Unk_RemakeStat& stat, const ATL::CAtlArray<int>& aLocked);   // the locked options' text

// RTTI CItemRemakeOptionIngredient (0x28 bytes, vftable 0x142de9a48): the cost box of an option remake, filled by
// CItemOptionTable::FUN_1405f4bb0. The ctor 0x140b9a3c0 / dtor 0x140b9a580 are inline COMDATs of
// ?\tabcontentspetremakeoption.cpp (itemoptiondata_3.cpp declares the same layout locally).
class CItemRemakeOptionIngredient : public CPtred
{
public:
    CItemRemakeOptionIngredient();                      // 0x140b9a3c0 m_spContainer = new CIngredientContainer(3)
    virtual ~CItemRemakeOptionIngredient();             // 0x140b9a580 (??_G 0x140b9a870)
    MS2SvrPtr<CIngredientContainer> m_spContainer;      // +0x18
};
MS2_CHECK_SIZE(CItemRemakeOptionIngredient, 0x28);
