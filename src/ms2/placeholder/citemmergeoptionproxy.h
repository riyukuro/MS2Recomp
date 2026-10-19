// citemmergeoptionproxy.h - PLACEHOLDER for CItemMergeOptionProxy (RTTI .?AVCItemMergeOptionProxy@@, 0x100 bytes, a
// CPtred) and CItemMergeOptionVariation (RTTI, 0x28 bytes): the packet record of the item merge option dialog -- the
// meso price, the needed ingredients and, per option kind, the value range the merge can roll. NOT an original header.
// Owning unit commonfiles\itemmergeoptiontable.cpp (the ctor 0x1405beb40, the packet reader 0x1405bef60 and the two
// CAtlMap instantiations live in its range); only what ?\uiitemmergeoptiondialog.cpp calls is declared. Members are
// named after the ATL calls the dialog makes; the CAtlMap<key, CItemMergeOptionVariation> bodies are out-of-line COMDATs
// of the owning unit, so the two maps are opaque 0x48-byte views with their exe member functions declared.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/commonstruct_wa.h"

// The key kinds of the two maps: a normal stat id and a special-ability id (distinct template arguments in the exe).
enum MergeNormalOption : int {};
enum MergeSpecialOption : int {};

// A value range of one option (ctor 0x1405bea40).
class CItemMergeOptionVariation : public CPtred
{
public:
    CItemMergeOptionVariation();                    // 0x1405bea40
    int FUN_1405beac0();                            // the minimum, as an integer
    int FUN_1405beae0();                            // the maximum, as an integer
    float FUN_1405beb00();                          // the minimum, as a rate
    float FUN_1405beb20();                          // the maximum, as a rate
private:
    MS2_LAYOUT_FRIEND;
    int m_nMin;                                     // +0x18
    int m_nMax;                                     // +0x1c
    int m_nIndex;                                   // +0x20
    int m_pad_24;
};
MS2_CHECK_SIZE(CItemMergeOptionVariation, 0x28);

// ATL::CAtlMap<MergeNormalOption, CItemMergeOptionVariation> (0x48 bytes). A node is {key, value, next, hash}: the
// value sits at node + 8.
class Unk_MergeNormalMap
{
public:
    POSITION FUN_1405c5e80();                       // GetStartPosition
    void FUN_1405c5be0(POSITION& pos);              // GetNext
    const int& FUN_1405c5ad0(POSITION pos);         // GetKeyAt
    void* Lookup(const int& key);                   // 0x1419d7660 (the node, or 0)
private:
    void* m_pad[9];
};
MS2_CHECK_SIZE(Unk_MergeNormalMap, 0x48);

// ATL::CAtlMap<MergeSpecialOption, CItemMergeOptionVariation> (0x48 bytes).
class Unk_MergeSpecialMap
{
public:
    POSITION FUN_1405c5e10();                       // GetStartPosition
    void FUN_1405c5b90(POSITION& pos);              // GetNext
    const int& FUN_1405c5a60(POSITION pos);         // GetKeyAt
    void* Lookup(const int& key);                   // 0x1419d7620 (the node, or 0)
private:
    void* m_pad[9];
};
MS2_CHECK_SIZE(Unk_MergeSpecialMap, 0x48);

class CItemMergeOptionProxy : public CPtred
{
public:
    CItemMergeOptionProxy();                        // 0x1405beb40
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
