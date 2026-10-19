// citemmergeoptionproxy.h - the item merge option records (commonfiles\itemmergeoptiontable.cpp, owner). NOT an original
// header: the class names are the RTTI ones, the member names are by use.
//   CItemMergeOptionVariation (0x28)  a value range of an option (and the index of its step)
//   CItemMergeOption          (0xb0)  one mergeable option of a slot: normal or special stat, three ranges, a weighted pool
//   CItemMergeOptionData      (0x80)  one <slot> of Table/itemMergeOptionBase.xml
//   CItemMergeOptionProxy     (0x100) the packet record of the item merge option dialog -- the meso price, the needed
//                                     ingredients and, per option kind, the value range the merge can roll
// The dialog (?\uiitemmergeoptiondialog.cpp) reaches the two CAtlMaps through their exe COMDATs (FUN_ members), so the
// map classes derive from the real CAtlMap and keep those declarations.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/commonstruct_wa.h"

// The key kinds of the two maps: a normal stat id and a special-ability id (distinct template arguments in the exe).
enum MergeNormalOption : int {};
enum MergeSpecialOption : int {};

// Inclusive value range of a variation (ctor 0x1405c38a0).
struct Unk_MergeRange
{
    Unk_MergeRange() : m_nMin(0), m_nMax(0) {}
    void Set(int nMin, int nMax);                   // 0x1405c6380
    int m_nMin;
    int m_nMax;
};
MS2_CHECK_SIZE(Unk_MergeRange, 8);

// A value range of one option (ctor 0x1405bea40).
class CItemMergeOptionVariation : public CPtred
{
public:
    CItemMergeOptionVariation();                    // 0x1405bea40
    virtual ~CItemMergeOptionVariation();           // 0x1405c4590
    CItemMergeOptionVariation& operator=(const CItemMergeOptionVariation& o);   // 0x1405c4670 (not the pad)
    int FUN_1405beaa0();                            // the number of values of the range
    int FUN_1405beac0();                            // the minimum, as an integer
    int FUN_1405beae0();                            // the maximum, as an integer
    float FUN_1405beb00();                          // the minimum, as a rate
    float FUN_1405beb20();                          // the maximum, as a rate

    Unk_MergeRange m_range;                         // +0x18
    int m_nIndex;                                   // +0x20 the step of the <slot> the range belongs to
    int m_pad_24;
};
MS2_CHECK_SIZE(CItemMergeOptionVariation, 0x28);

// The weighted pool of rolls of an option / a slot: a tree followed by the total weight (ctor 0x1405c3840 / 0x1405c3870).
// One roll of a pool (0x18 bytes: the exe's tree node is 0x40, and ~pair -> ~entry -> ~MS2Ptr is three calls deep).
template <class T> struct MergePoolEntry
{
    MS2Ptr<T> m_spOption;
    int m_nWeight;
};

template <class T> struct MergePoolRecord
{
    MergePoolRecord();
    ~MergePoolRecord();
    std::map<unsigned, MergePoolEntry<T> > m_pool;
    int m_nTotal;
};

// ATL::CAtlMap<MergeNormalOption, CItemMergeOptionVariation> (0x48 bytes). A node is {key, value, next, hash}: the
// value sits at node + 8.
class Unk_MergeNormalMap : public ATL::CAtlMap<MergeNormalOption, CItemMergeOptionVariation>
{
public:
    __forceinline Unk_MergeNormalMap() {}           // inlined into CItemMergeOptionProxy's ctor (no copy of its own in the exe)
    POSITION FUN_1405c5e80();                       // GetStartPosition
    void FUN_1405c5be0(POSITION& pos);              // GetNext
    const int& FUN_1405c5ad0(POSITION pos);         // GetKeyAt
    void* Lookup(const int& key);                   // 0x1419d7660 (the node, or 0)
};
MS2_CHECK_SIZE(Unk_MergeNormalMap, 0x48);

// ATL::CAtlMap<MergeSpecialOption, CItemMergeOptionVariation> (0x48 bytes).
class Unk_MergeSpecialMap : public ATL::CAtlMap<MergeSpecialOption, CItemMergeOptionVariation>
{
public:
    __forceinline Unk_MergeSpecialMap() {}          // inlined into CItemMergeOptionProxy's ctor
    POSITION FUN_1405c5e10();                       // GetStartPosition
    void FUN_1405c5b90(POSITION& pos);              // GetNext
    const int& FUN_1405c5a60(POSITION pos);         // GetKeyAt
    void* Lookup(const int& key);                   // 0x1419d7620 (the node, or 0)
};
MS2_CHECK_SIZE(Unk_MergeSpecialMap, 0x48);

class CItemMergeOption : public CPtred
{
public:
    CItemMergeOption();                             // 0x1405bf2e0
    virtual ~CItemMergeOption();                    // 0x1405c44d0

    int m_nNormal;                                  // +0x18 the stat id of a normal option, -1 for a special one
    int m_nSpecial;                                 // +0x1c the special ability id (0 for a normal option)
    CItemMergeOptionVariation m_kFirst;             // +0x20 the whole range (first min .. last max)
    CItemMergeOptionVariation m_kSecond;            // +0x48 the range of the rolled step (see Data::LoadXml)
    CItemMergeOptionVariation m_kThird;             // +0x70 the last step
    MergePoolRecord<CItemMergeOptionVariation> m_pool;   // +0x98
};
MS2_CHECK_SIZE(CItemMergeOption, 0xb0);

class CItemMergeOptionData : public CPtred
{
public:
    CItemMergeOptionData();                         // 0x1405bf380
    virtual ~CItemMergeOptionData();                // 0x1405bf410
    int FUN_1405bf470(Unk_140165cf0* pSlot);        // loads a <slot> of itemMergeOptionBase.xml (1 on success)
    int FUN_1405bfb80();                            // the probability version

    int m_nId;                                      // +0x18 the part id of the slot
    ATL::CAtlArray<unsigned> m_aPartLimit;          // +0x20 "partLimit"
    MergePoolRecord<CItemMergeOption> m_pool;       // +0x40
    ATL::CAtlArray<MS2Ptr<CItemMergeOption> > m_aOptions;   // +0x58 the <slot>'s <option>s
    int m_nProbVer;                                 // +0x78 "probVer"
    int m_pad_7c;
};
MS2_CHECK_SIZE(CItemMergeOptionData, 0x80);

class CItemMergeOptionProxy : public CPtred
{
public:
    CItemMergeOptionProxy();                        // 0x1405beb40
    virtual ~CItemMergeOptionProxy();               // 0x1405c4530
    void FUN_1405bec30(COutputStream& stream);      // write the record
    void FUN_1405bef60(CInPacket& packet);          // read the record from the packet

    __int64 m_nMeso;                                // +0x18 the price
    CIngredientContainer m_ingredients;             // +0x20 the needed ingredients
    ATL::CAtlArray<int> m_values;                   // +0x50
    Unk_MergeNormalMap m_normal;                    // +0x70 normal stat ranges
    Unk_MergeSpecialMap m_special;                  // +0xb8 special ability ranges
};
MS2_CHECK_SIZE(CItemMergeOptionProxy, 0x100);
MS2_CHECK_OFFSET(CItemMergeOptionProxy, m_nMeso, 0x18);
MS2_CHECK_OFFSET(CItemMergeOptionProxy, m_ingredients, 0x20);
MS2_CHECK_OFFSET(CItemMergeOptionProxy, m_normal, 0x70);
MS2_CHECK_OFFSET(CItemMergeOptionProxy, m_special, 0xb8);
