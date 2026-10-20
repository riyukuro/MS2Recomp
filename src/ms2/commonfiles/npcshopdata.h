// npcshopdata.h - the NPC / beauty shop tables (commonfiles\npcshopdata.cpp), recovered from MapleStory2.exe KMS2_DEV
// x64 (2022-04-13). NOT an original header (name assumed). Class names are RTTI names; member names are invented from
// the xml attributes the loaders read (shop_game_info.xml, shop_game.xml, shop_specialRandom_new.xml, shop_meratGroup.xml,
// shop_beautyCoupon.xml). FUN_<va> are non-virtual members whose real names are unknown. CNpcShopBuyPeriod,
// CNpcShopItemNew and CNpcShopMeratItemBase are declared in their placeholder headers (the client units use them).
//
// Every class derives CPtred (vftable: slot 0 = deleting dtor); the destructors are implicit unless noted (their
// COMDATs sort at 0x1406ef450-0x1406ef940).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cnpcshopbuyperiod.h"
#include "ms2/placeholder/cnpcshopitemnew.h"
#include "ms2/placeholder/cnpcshopmeratitembase.h"
#include "ms2/commonfiles/commonstruct_wa.h"         // NpcShopItemLife, Unk_ShopLifeRef
#include "ms2/commonfiles/itemdroptable.h"           // ItemDropPicker<T>

class CInPacket;
class COutputStream;
class Unk_140165cf0;                                 // TinyXML element (xmlattr.h)

// The enum attributes read through tinyxmlhelper.h's XmlValue<E> (one instantiation per enum; names invented).
enum eItemFrameType {};                              // <item frameType>
enum ePaymentType {};                                // paymentType / resetPaymentType (4: none; 9, 10: feature gated)
enum eShopFrameType {};                              // <shop uiFrameType>
enum eShopResetType {};                              // <shop resetType> (99: fixed time)
enum eShopSaleTag {};                                // <item saleTag>

// A price: payment type, item, icon tag and amount (RTTI .?AVTShopPaymentAttr@@, 0x38 bytes, ctor 0x1406dc170).
class TShopPaymentAttr : public CPtred
{
public:
    TShopPaymentAttr();                              // 0x1406dc170
    void FUN_1406dc1e0();                            // reset
    void FUN_1406dc230(COutputStream& out);          // write
    void FUN_1406dc2c0(CInPacket& in);               // read
    void FUN_1406dc3c0(Unk_140165cf0* pElem, const CString& strType, const CString& strItem, const CString& strIcon,
                       const CString& strPrice);     // read the four attributes (names given by the caller)
    const CString& FUN_1406dc4b0() const;            // icon tag
    unsigned FUN_1406dc4d0() const;                  // payment item id
    __int64 FUN_1406dc4f0() const;                   // amount
    ePaymentType FUN_1406dc510() const;              // payment type (a gated type falls back to 4 while its feature is off)
    void FUN_1406dc580(int nFeature);                // the feature that gates types 9 and 10

    CString m_strIconTag;                            // +0x18
    ePaymentType m_eType;                            // +0x20
    unsigned m_nItemId;                              // +0x24
    __int64 m_nAmount;                               // +0x28
    int m_nFeature;                                  // +0x30 (1: not gated)
};
MS2_CHECK_SIZE(TShopPaymentAttr, 0x38);

// One <item> of shop_game.xml (RTTI .?AVCNpcShopItem@@, 0xb8 bytes, ctor 0x1406ddd10).
class CNpcShopItem : public CPtred
{
public:
    CNpcShopItem();                                  // 0x1406ddd10
    bool operator!=(const CNpcShopItem& o) const;    // 0x1406dded0
    bool FUN_1406de350();                            // visible now (period and item life)
    bool FUN_1406de410();                            // buyable now

    unsigned m_nSn;                                  // +0x18 sn
    unsigned m_nItemId;                              // +0x1c id
    ePaymentType m_ePaymentType;                     // +0x20 paymentType
    unsigned m_nPaymentItemId;                       // +0x24 paymentItemID (before ':')
    unsigned m_nPaymentItemSub;                      // +0x28 paymentItemID (after ':')
    CString m_strPaymentIconTag;                     // +0x30 paymentIconTag
    unsigned m_nPrice;                               // +0x38 price
    unsigned m_nOriginalPrice;                       // +0x3c OriginalPrice
    unsigned m_nGrade;                               // +0x40 grade
    unsigned m_nSellCount;                           // +0x44 sellCount
    unsigned m_nRequireGuildTrophy;                  // +0x48 requireGuildTrophy
    unsigned m_nRequireAchieveId;                    // +0x4c requireAchieve (id)
    unsigned m_nRequireAchieveGrade;                 // +0x50 requireAchieve (grade)
    unsigned m_nRequireChampionship;                 // +0x54 requireChampionshipInfo (1)
    unsigned m_nRequireChampionshipRank;             // +0x58 requireChampionshipInfo (2)
    unsigned m_nRequireGuildNpcType;                 // +0x5c requireGuildNpc (type)
    unsigned m_nRequireGuildNpcLevel;                // +0x60 requireGuildNpc (level)
    unsigned m_nRequireAlliance;                     // +0x64 requireAlliance
    unsigned m_nRequireAllianceGrade;                // +0x68 requireAllianceGrade
    CString m_strCategory;                           // +0x70 category
    int m_nPremiumItem;                              // +0x78 premiumItem
    unsigned m_nSellUnit;                            // +0x7c sellUnit (1)
    eItemFrameType m_eFrameType;                     // +0x80 frameType
    eShopSaleTag m_eSaleTag;                         // +0x84 saleTag
    bool m_bWearForPreview;                          // +0x88 wearForPreview
    MS2SvrPtr<CNpcShopBuyPeriod> m_spPeriod;         // +0x90
    Unk_ShopLifeRef m_spLife;                        // +0xa0
    unsigned m_nProb;                                // +0xb0 prob
    bool m_bCheckGameEvent;                          // +0xb4 checkGameEvent
};
MS2_CHECK_SIZE(CNpcShopItem, 0xb8);
MS2_CHECK_OFFSET(CNpcShopItem, m_spPeriod, 0x90);

// One <shop> of shop_game_info.xml with its items (RTTI .?AVCNpcShopData@@, 0x138 bytes, ctor 0x1406deb50).
class CNpcShopData : public CPtred
{
public:
    CNpcShopData();                                  // 0x1406deb50
    bool operator!=(const CNpcShopData& o) const;    // 0x1406ded80
    int FUN_1406df190();                             // three server-side checks (always TRUE here)
    int FUN_1406df1b0();
    int FUN_1406df1d0();
    int FUN_1406e2600(CString& strError, Unk_140165cf0* pElem);   // validate after reading
    void FUN_1406e2bc0(MS2Ptr<CNpcShopItemNew> spItem);           // add a "new" item

    unsigned m_nShopId;                              // +0x18 shopID
    unsigned m_nShopVersion;                         // +0x1c shopVersion
    int m_nCategoryId;                               // +0x20 categoryID
    int m_nOpenTokenPocket;                          // +0x24 isOpenTokenPocket
    int m_nMeratItemGroupId;                         // +0x28 meratItemGroupID
    bool m_bOnlySell;                                // +0x2c isOnlySell
    int m_nResetEnable;                              // +0x30 resetEnable
    bool m_bResettable;                              // +0x34 resetEnable == 1 (or an item has a sell count)
    ePaymentType m_eResetPaymentType;                // +0x38 resetPaymentType
    unsigned m_nResetPaymentItemId;                  // +0x3c resetPaymentItemID
    CString m_str40;                                 // +0x40 (not read here)
    unsigned m_nResetPrice;                          // +0x48 resetPrice
    int m_nResetListMax;                             // +0x4c resetListMax (1)
    int m_nResetListMin;                             // +0x50 resetListMin (1)
    int m_nDisableDisplayOrderSort;                  // +0x54 disableDisplayOrderSort
    int m_nSmartShopItemList;                        // +0x58 isSmartShopItemList
    int m_nResetByAccount;                           // +0x5c resetByAccount
    eShopResetType m_eResetType;                     // +0x60 resetType
    bool m_bResetButtonHide;                         // +0x64 resetButtonHide
    eShopFrameType m_eUIFrameType;                   // +0x68 uiFrameType
    CString m_strIconName;                           // +0x70 iconName
    CMsTime m_tmResetFixed;                          // +0x78 resetFixedTime
    unsigned m_nTotalProb;                           // +0x88 the sum of the items' prob
    ATL::CAtlArray<MS2Ptr<CNpcShopItem> > m_aItems;          // +0x90
    ATL::CAtlArray<MS2Ptr<CNpcShopItem> > m_aEventItems;     // +0xb0 checkGameEvent items
    int m_nUseLuaResetPayment;                       // +0xd0 useLuaResetPayment
    int m_nUseLuaPremiumItemRandomCount;             // +0xd4 useLuaPremiumItemRandomCount
    unsigned m_nResetIntervalTime;                   // +0xd8 resetIntervalTime
    bool m_bShowOnlyUsableItem;                      // +0xdc showOnlyUsableItem
    bool m_bHideOptionInfo;                          // +0xdd hideOptionInfo
    bool m_bShowProbInfo;                            // +0xde showProbInfo
    int m_nNewCategoryId;                            // +0xe0 categoryID (shop_specialRandom_new.xml)
    ATL::CAtlArray<MS2Ptr<CNpcShopItemNew> > m_aNewItems;    // +0xe8
    ItemDropPicker<int> m_normalPicker;              // +0x108 item index by prob (normal items)
    ItemDropPicker<int> m_premiumPicker;             // +0x120 (premium items)
};
MS2_CHECK_SIZE(CNpcShopData, 0x138);
MS2_CHECK_OFFSET(CNpcShopData, m_tmResetFixed, 0x78);
MS2_CHECK_OFFSET(CNpcShopData, m_aNewItems, 0xe8);

// The merat (premium) item of a merat group (RTTI .?AVCNpcShopMeratItemSvr@@, 0x40 bytes, ctor 0x1406eebb0).
class CNpcShopMeratItemSvr : public CNpcShopMeratItemBase
{
public:
    CNpcShopMeratItemSvr() : m_nSn(0), m_34(0), m_38(0) {}   // 0x1406eebb0
    virtual ~CNpcShopMeratItemSvr() {}                       // 0x1406ef840
    virtual void vfunc_1(COutputStream* pOut);               // 1 0x1406f1a00 write
    virtual void vfunc_2(CInPacket* pIn);                    // 2 0x1406f1930 read (nothing)
    virtual unsigned vfunc_3();                              // 3 0x1406f24b0 sn

    unsigned m_nSn;                                  // +0x30 sn
    int m_34;                                        // +0x34
    int m_38;                                        // +0x38
};
MS2_CHECK_SIZE(CNpcShopMeratItemSvr, 0x40);

// One beauty shop product (RTTI .?AVCBeautyShopItem@@, 0x68 bytes, ctor 0x1406e3690).
class CBeautyShopItem : public CPtred
{
public:
    CBeautyShopItem();                               // 0x1406e3690
    void FUN_1406e3740(COutputStream& out);
    void FUN_1406e37f0(CInPacket& in);
    int FUN_1406e3900(CString& strError);            // validate the price against the item
    __int64 FUN_1406e3bc0();                         // price
    ePaymentType FUN_1406e3bf0();                    // payment type
    unsigned FUN_1406e3c20();                        // payment item id

    unsigned m_nItemId;                              // +0x18 id
    unsigned m_nWeight;                              // +0x1c weight
    int m_nSaleTag;                                  // +0x20 saleTag
    unsigned short m_nRequireLevel;                  // +0x24 requireLevel
    unsigned m_nAchieveId;                           // +0x28 achieveID
    int m_nAchieveGrade;                             // +0x2c achieveGrade
    TShopPaymentAttr m_payment;                      // +0x30
};
MS2_CHECK_SIZE(CBeautyShopItem, 0x68);

// The beauty shop data both sides share (RTTI .?AVCBeautyShopDataCommon@@, 0xa8 bytes, ctor 0x1406e3c50).
class CBeautyShopDataCommon : public CPtred
{
public:
    CBeautyShopDataCommon();                         // 0x1406e3c50
    virtual ~CBeautyShopDataCommon() {}              // 0x1406ef4a0
    void FUN_1406e3d30();                            // reset
    TShopPaymentAttr& FUN_1406e3dc0();               // the price
    TShopPaymentAttr& FUN_1406e3de0();               // the recolor price
    const TShopPaymentAttr& FUN_1406e3e00() const;
    const TShopPaymentAttr& FUN_1406e3e20() const;

    unsigned m_nShopId;                              // +0x18
    unsigned m_nCategory;                            // +0x1c
    unsigned m_nDisplayCouponId;                     // +0x20
    bool m_b24;                                      // +0x24
    unsigned m_nReturnCouponId;                      // +0x28
    unsigned m_n2c;                                  // +0x2c
    bool m_b30;                                      // +0x30
    TShopPaymentAttr m_payment;                      // +0x38
    TShopPaymentAttr m_recolorPayment;               // +0x70
};
MS2_CHECK_SIZE(CBeautyShopDataCommon, 0xa8);

// Products of one sale period, per gender (RTTI .?AVCBeautyShopItemGroup@@, 0x78 bytes, ctor 0x1406e3e40).
class CBeautyShopItemGroup : public CPtred
{
public:
    CBeautyShopItemGroup(__int64 nKey, const CString& strName, unsigned nValue);  // 0x1406e3e40
    ATL::CAtlArray<MS2Ptr<CBeautyShopItem> >& FUN_1406e3f10(int nGender);
    unsigned FUN_1406e3fe0(int nGender);             // the gender's weight sum
    __int64 FUN_1406e4040();                         // key (start time yyyymmddhhmmss)
    const CString& FUN_1406e4060();
    unsigned FUN_1406e4080();
    void FUN_1406e40a0(MS2Ptr<CBeautyShopItem> spItem, int nGender);

    __int64 m_nKey;                                  // +0x18
    CString m_strName;                               // +0x20
    unsigned m_nValue;                               // +0x28
    unsigned m_aWeight[2];                           // +0x2c
    ATL::CAtlArray<MS2Ptr<CBeautyShopItem> > m_aItems[2];    // +0x38
};
MS2_CHECK_SIZE(CBeautyShopItemGroup, 0x78);

// The item groups by start time (RTTI .?AVCBeautyShopItemGroups@@, 0x28 bytes, ctor 0x1406eea20).
class CBeautyShopItemGroups : public CPtred
{
public:
    CBeautyShopItemGroups() {}                       // 0x1406eea20
    MS2Ptr<CBeautyShopItemGroup> FUN_1406e4170() const;      // the group on sale now
    void FUN_1406e4260(std::vector<MS2Ptr<CBeautyShopItemGroup> >& out) const;  // the groups from now on
    bool FUN_1406e4350(MS2Ptr<CBeautyShopItemGroup> spGroup);  // add (false: the key exists)

    std::map<__int64, MS2Ptr<CBeautyShopItemGroup> > m_groups;    // +0x18
};
MS2_CHECK_SIZE(CBeautyShopItemGroups, 0x28);

// A beauty shop (RTTI .?AVCBeautyShopData@@, 0xb8 bytes, ctor 0x1406e4500).
class CBeautyShopData : public CBeautyShopDataCommon
{
public:
    CBeautyShopData();                               // 0x1406e4500
    int FUN_1406e45b0(CString& strError);            // validate the coupons
    void FUN_1406e4770(COutputStream& out);
    MS2Ptr<CBeautyShopItem> FUN_1406e4860(int nItemId, unsigned nGender);
    void AddShopItemGroup(MS2Ptr<CBeautyShopItemGroup> spGroup);  // 0x1406e4a70 (name from its log text)
    MS2Ptr<CBeautyShopItemGroup> GetShopItemGroup();              // 0x1406e4b80
    std::vector<MS2Ptr<CBeautyShopItemGroup> >* GetShopItemGroupList(std::vector<MS2Ptr<CBeautyShopItemGroup> >& out);  // 0x1406e4ce0

    MS2Ptr<CBeautyShopItemGroups> m_spGroups;        // +0xa8
};
MS2_CHECK_SIZE(CBeautyShopData, 0xb8);

// The client's copy (RTTI .?AVCBeautyShopDataCli@@, 0xa8 bytes, ctor 0x1406e53e0).
class CBeautyShopDataCli : public CBeautyShopDataCommon
{
public:
    CBeautyShopDataCli();                            // 0x1406e53e0
    void FUN_1406e5420(CInPacket& in);               // read the shop
};
MS2_CHECK_SIZE(CBeautyShopDataCli, 0xa8);
