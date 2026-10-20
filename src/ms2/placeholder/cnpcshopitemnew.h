// cnpcshopitemnew.h - PLACEHOLDER for CNpcShopItemNew (RTTI .?AVCNpcShopItemNew@@, CPtred-derived, 0x48 bytes: ctor
// 0x1406de4d0, dtor 0x1406ef7a0 (??_G 0x1406f10c0)): the item record of a "new" NPC shop product. NOT an original
// header; the class is defined by commonfiles\npcshopdata.cpp (w514, the <item> of shop_specialRandom_new.xml).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/cnpcshopbuyperiod.h"

class CInPacket;
class COutputStream;
class CNpcShopBuyPeriod;

class CNpcShopItemNew : public CPtred
{
public:
    CNpcShopItemNew();                                      // 0x1406de4d0
    // implicit dtor (COMDAT 0x1406ef7a0, ??_G 0x1406f10c0)
    bool operator!=(const CNpcShopItemNew& o) const;        // 0x1406de540
    void FUN_1406de6b0();                                   // reset
    void FUN_1406de710(COutputStream& out);                 // write the record
    void FUN_1406de840(CInPacket& in);                      // read the record from a packet
    bool FUN_1406dea90();                                   // visible now (no period: always)
    bool FUN_1406deaf0();                                   // buyable now (no period: always)

    unsigned m_nItemId;                                     // +0x18 id
    bool m_bFlag;                                           // +0x1c premiumItem
    unsigned m_nRarity;                                     // +0x20 grade
    CString m_strName;                                      // +0x28 category
    int m_nProductType;                                     // +0x30 frameType (the product's "property 1")
    int m_nProductKind;                                     // +0x34 (the product's "property 2")
    MS2SvrPtr<CNpcShopBuyPeriod> m_spPeriod;                // +0x38
};
MS2_CHECK_SIZE(CNpcShopItemNew, 0x48);
MS2_CHECK_OFFSET(CNpcShopItemNew, m_nProductType, 0x30);
