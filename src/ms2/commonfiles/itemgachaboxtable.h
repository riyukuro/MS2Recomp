// itemgachaboxtable.h - GachaBoxData / ItemGachaBoxTable (RTTI names): the random ("gacha") box table read from
// Table/gacha_info.xml (<randomBox randomBoxID randomBoxGroup randomBoxSeasonKR/JP/NA/CN saleEndDate ui individualDropBoxID
// shopID coinItemID coinItemAmount seasonNumberOnIcon paymentIconTag/>; loader FUN_14059dea0). Header name assumed (unit
// 0x14059dcd0-0x1405a3940 is ?\itemgachaboxtable.cpp, not yet recovered); member names come from the xml attributes.
// Shared by the gacha UI units (UIItemGachaBoxDialog, unit_140c3ff80).
#pragma once
#include <afx.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/os.h"

// One box (<randomBox>). RTTI GachaBoxData, 0x60 bytes, base CPtred; vftable 0x142d61df0 (1 slot: dtor).
class GachaBoxData : public CPtred
{
public:
    GachaBoxData();                         // 0x14059dcd0
    virtual ~GachaBoxData();                // 0x14059ddc0 (scalar deleting 0x1405a1f50)

    int GetSeason() const;                  // 0x14059ddf0: m_nSeason[DAT_143ab0248] (the region index)

    int m_nRandomBoxID;                     // +0x18 "randomBoxID"
    int m_nRandomBoxGroup;                  // +0x1c "randomBoxGroup"
    int m_nSeason[4];                       // +0x20 "randomBoxSeasonKR", "...JP", "...NA", "...CN"
    bool m_bSeasonNumberOnIcon;             // +0x30 "seasonNumberOnIcon" (ctor: byte 0)
    CMsTime m_saleEndDate;                  // +0x38 "saleEndDate" (ctor 0x1406c47a0 with 0)
    int m_nUi;                              // +0x48 attribute "ui"
    int m_nIndividualDropBoxID;             // +0x4c "individualDropBoxID"
    int m_nShopID;                          // +0x50 "shopID"
    int m_nCoinItemID;                      // +0x54 "coinItemID"
    int m_nCoinItemAmount;                  // +0x58 "coinItemAmount" (ctor 1)
    int m_nPaymentIconTag;                  // +0x5c "paymentIconTag"
};
MS2_CHECK_SIZE(GachaBoxData, 0x60);
MS2_CHECK_OFFSET(GachaBoxData, m_nSeason, 0x20);
MS2_CHECK_OFFSET(GachaBoxData, m_saleEndDate, 0x38);
MS2_CHECK_OFFSET(GachaBoxData, m_nPaymentIconTag, 0x5c);

typedef MS2SvrPtr<GachaBoxData> GachaBoxDataPtr;

class ItemGachaBoxTable;

// This instantiation stores the complete object pointer; DAT_143aaf1d0 (getter FUN_14052d230).
template <> class TSingleton<ItemGachaBoxTable>
{
public:
    TSingleton();                           // 0x1405a1600
    virtual ~TSingleton() { s_instance = 0; }   // 0x1405a1940 (scalar deleting 0x1405a1ed0)
    static ItemGachaBoxTable* s_instance;
    static ItemGachaBoxTable* GetInstance();     // 0x14052d230
};

// The table. RTTI ItemGachaBoxTable, 0x18 bytes; vftable 0x142d61e10; the map is cleared and refilled by the loader.
class ItemGachaBoxTable : public TSingleton<ItemGachaBoxTable>
{
public:
    ItemGachaBoxTable();                    // 0x14059de10
    virtual ~ItemGachaBoxTable();           // 0x14059de60 (scalar deleting 0x1405a1f90)

    void Load();                            // 0x14059dea0 (name invented)
    GachaBoxDataPtr FUN_14059e340(int nRandomBoxID);    // find by id, returned by value (null pointer when missing; hidden return slot)
    int GetIndividualDropBoxID(int nRandomBoxID);       // 0x14059e400 (+0x4c; 0 when missing)
    int FUN_14059e490(int nShopID);                     // 0x14059e490 first box of that shop: ui (+0x48)
    int FUN_14059e550(int nShopID);                     // 0x14059e550 first box of that shop: coinItemID
    int GetCoinItemID(int nRandomBoxID);                // 0x14059e610 (+0x54; 0 when missing)
    int FUN_14059e6a0(int nItemID);                     // 0x14059e6a0 coin item of the box an item opens (or of the first drop that has one)
    int FUN_14059ebb0(int nCoinItemID);                 // 0x14059ebb0 randomBoxID of the first box paid with that coin item
    void FUN_14059ec70(std::vector<GachaBoxDataPtr>& out);   // 0x14059ec70 every box
    int FUN_14059ed00(int nId);                         // 0x14059ed00 GetSeason() of the box whose randomBoxID or coinItemID is nId
    int FUN_14059ee00(int nShopID);                     // 0x14059ee00 first box of that shop: paymentIconTag
    bool FUN_14059eec0(int nCoinItemID);                // 0x14059eec0 a box is paid with that coin item
    bool FUN_14059ef70(int nRandomBoxID);               // 0x14059ef70 seasonNumberOnIcon

    std::map<int, GachaBoxDataPtr> m_map;   // +0x08 randomBoxID -> box
};
MS2_CHECK_SIZE(ItemGachaBoxTable, 0x18);
MS2_CHECK_OFFSET(ItemGachaBoxTable, m_map, 0x08);
