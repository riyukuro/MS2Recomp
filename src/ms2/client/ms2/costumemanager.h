// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\costumemanager.h (name assumed: the
// class name; the exe has no assert path for it).
//
// CostumeManager (RTTI .?AVCostumeManager@@, 0x58 bytes, CPtred-derived, one vftable slot): puts the items of a
// costume set on a preview avatar. FUN_140b1d360 looks the set up in the (unrecovered) costume table, takes down the set
// worn before, then creates one CItem per table entry (both item lists of the row), stamps it with the avatar's
// customize id / owner id / the current time and equips it through the avatar's slot 127; FUN_140b1d890 takes them off
// again through slot 128 and empties the list. Members are invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class AvatarPC;
class CItem;

// One row of the costume table: the item ids of the two parts (+0x20 / +0x68, item id -> item id).
class Unk_CostumeRow : public CPtred
{
public:
    typedef ATL::CAtlMap<int, int> IdMap;

    char m_pad_18[8];
    IdMap m_mapPart1;                                       // +0x20
    IdMap m_mapPart2;                                       // +0x68
};

// The costume table (the singleton at 0x143aaf318); only the row lookup is used here.
class Unk_CostumeTable
{
public:
    MS2Ptr<Unk_CostumeRow> FUN_1405360b0(unsigned int nId, unsigned int nKind);    // 0x1405360b0
};

class CostumeManager : public CPtred
{
public:
    CostumeManager(AvatarPC* pOwner);                       // 0x140b1d2b0
    virtual ~CostumeManager();                              //  0 0x140b1d320 (??_G 0x140b1d9f0)

    void FUN_140b1d360(int nCostumeId);                     // 0x140b1d360 put the set on
    void FUN_140b1d890(int nCostumeId);                     // 0x140b1d890 take the set off

private:
    MS2_LAYOUT_FRIEND;
    AvatarPC* m_pOwner;                                     // +0x18
    int m_nCostumeId;                                       // +0x20 the set worn now
    ATL::CAtlList<MS2Ptr<CItem> > m_items;                  // +0x28 the created items
};
MS2_CHECK_SIZE(CostumeManager, 0x58);
MS2_CHECK_OFFSET(CostumeManager, m_pOwner, 0x18);
MS2_CHECK_OFFSET(CostumeManager, m_items, 0x28);
MS2_CHECK_OFFSET(Unk_CostumeRow, m_mapPart1, 0x20);
MS2_CHECK_OFFSET(Unk_CostumeRow, m_mapPart2, 0x68);
