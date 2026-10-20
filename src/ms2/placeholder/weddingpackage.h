// weddingpackage.h - PLACEHOLDER for WeddingPackage (RTTI .?AVWeddingPackage@@, 0x30 bytes), WeddingHallData (RTTI
// .?AVWeddingHallData@@, 0x78 bytes) and the hall's reward rows WeddingRewardItem (0x48) / WeddingCompleteRewardItem
// (0x50), the rows of WeddingTable (weddingPackage.xml: a package, its halls and their items). NOT an original header.
// Layouts follow the v2525 reference decomp (work/ext/v2525, include/ms2/commonfiles/WeddingPackage.h /
// WeddingHallData.h: ctors 0x140906ed0 / 0x1409065e0, Read 0x140906f80 / 0x140906740); member names are the XML keys.
// All of them are defined in ?\weddingrewarditem.cpp (0x1409063b0-0x140920690).
#pragma once

#include <afx.h>
#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"                // MS2Ptr<T>
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/itemgift.h"               // ItemEntity

class Unk_140165cf0;                                // game TinyXML element (xmlattr.h)

// <weddingItem>: an item the hall hands out on reservation.
class WeddingRewardItem : public CPtred
{
public:
    WeddingRewardItem();                                    // 0x1409063b0
    virtual ~WeddingRewardItem();                           // 0x140906400
    bool Read(Unk_140165cf0* pNode);                        // 0x140906440
    void CopyFrom(MS2Ptr<WeddingRewardItem> spOther);       // 0x140906490 (name invented; no callers)

    ItemEntity m_item;                                      // +0x18
};
MS2_CHECK_SIZE(WeddingRewardItem, 0x48);

// <weddingCompleteItem>: an item the couple gets when the wedding completes (nightReward: night halls only).
class WeddingCompleteRewardItem : public CPtred
{
public:
    WeddingCompleteRewardItem();                            // 0x1409064e0
    virtual ~WeddingCompleteRewardItem();                   // 0x140906540
    bool Read(Unk_140165cf0* pNode);                        // 0x140906580

    ItemEntity m_item;                                      // +0x18
    bool m_bNightReward;                                    // +0x48 "nightReward"
};
MS2_CHECK_SIZE(WeddingCompleteRewardItem, 0x50);

class WeddingHallData : public CPtred
{
public:
    WeddingHallData();                                      // 0x1409065e0
    virtual ~WeddingHallData();
    bool Read(Unk_140165cf0* pNode);                        // 0x140906740

    int m_nId;                                              // +0x18 "id"
    int m_nGrade;                                           // +0x1c "grade"
    __int64 m_nMerat;                                       // +0x20 "merat" (the price)
    CString m_strVideoPath;                                 // +0x28 "videoPath"
    CStringW m_strDesc;                                     // +0x30 "desc"
    CStringW m_strIllust;                                   // +0x38 "mcillust"
    std::vector<MS2Ptr<WeddingRewardItem> > m_items;                    // +0x40 <weddingItem> (merged by item and rank)
    std::vector<MS2Ptr<WeddingCompleteRewardItem> > m_completeItems;    // +0x58 <weddingCompleteItem>
    unsigned int m_nFieldId;                                // +0x70 "fieldID"
    unsigned int m_nNightFieldId;                           // +0x74 "nightFieldID"

    unsigned int FUN_140906e40(bool bNight);                // the field id (the night field when set and nonzero)
    int FUN_140906e80();                                    // the reservation coupon of the grade (grade 1-3: 0xd4-0xd6, else 0)
};
MS2_CHECK_OFFSET(WeddingHallData, m_nMerat, 0x20);
MS2_CHECK_OFFSET(WeddingHallData, m_items, 0x40);
MS2_CHECK_OFFSET(WeddingHallData, m_completeItems, 0x58);
MS2_CHECK_OFFSET(WeddingHallData, m_nFieldId, 0x70);
MS2_CHECK_SIZE(WeddingHallData, 0x78);

class WeddingPackage : public CPtred
{
public:
    WeddingPackage();                                       // 0x140906ed0
    virtual ~WeddingPackage();
    bool Read(Unk_140165cf0* pNode);                        // 0x140906f80

    MS2Ptr<WeddingHallData> FUN_140907110(int nHallId);     // the hall of an id (null: none)

    int m_nId;                                              // +0x18 "id"
    unsigned int m_nPlanner;                                // +0x1c "planner"
    std::map<int, MS2Ptr<WeddingHallData>> m_halls;         // +0x20
};
MS2_CHECK_OFFSET(WeddingPackage, m_nId, 0x18);
MS2_CHECK_SIZE(WeddingPackage, 0x30);
