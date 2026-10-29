// vipgoods.h - the VIP (premium membership) tables: CVIPGoods / CVIPBenefitItem / CVIPBenefitEffect (RTTI names) and the
// CVIPTable that loads them from Table/vipGoodsTable.xml, vipBenefitItemTable.xml and vipBenefitEffectTable.xml.
// Header name assumed from the unit path; member and method names are invented from the xml attributes and use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/commonfiles/os.h"

class Unk_140165cf0;    // xml element (declared where the loaders are)

class AdditionalLevelData;  // the VIP effect (skill) found for an effect id / level

// The rank of a bonus item (ranks are read apart from the other numbers, so their array is a type of its own).
// "priceType" attribute (0 = pay code 3, 1 = pay code 9).
enum Unk_VipPriceType { VIP_PRICE_TYPE_0 };
enum Unk_VipItemRank { VIP_RANK_NONE };

// One <goods> row of vipGoodsTable.xml (a purchasable VIP period), 0xf0 bytes.
class CVIPGoods : public CPtred
{
public:
    CVIPGoods();                            // 0x1408f50a0
    virtual ~CVIPGoods();                   // 0x1408f51c0 (scalar deleting 0x1408f8170)

    CStringW GetPriceText(int bShort);      // 0x1408f5240 the shown (sale) price, by pay type
    CStringW GetSalesPeriodText();          // 0x1408f53c0 "sales start ~ end" or empty
    int HasSalesPeriod();                   // 0x1408f5510 both sale dates set
    int HasBuyLimit();                     // 0x1408f5590

    unsigned m_nId;                         // +0x18 "id"
    int m_n1c;                              // +0x1c
    CMsTime m_salesStartDate;               // +0x20 "salesStartDate"
    CMsTime m_salesEndDate;                 // +0x30 "salesEndDate"
    __int64 m_nVipPeriod;                   // +0x40 "vipPeriod" (hours in the xml, seconds after the load)
    int m_nDisplayOrder;                    // +0x48 "displayOrder"
    __int64 m_nPrice;                       // +0x50 "price"
    __int64 m_nSalePrice;                   // +0x58 "salePrice"
    int m_nSaleTag;                         // +0x60 "saleTag"
    Unk_VipPriceType m_nPriceType;                       // +0x64 "priceType" (0 / 1)
    int m_nBuyLimit;                        // +0x68 "buyLimit"
    int m_nBuyLimitResetType;               // +0x6c "buyLimitResetType"
    ATL::CAtlArray<unsigned> m_bonusItemIds;    // +0x70 "bonusItemID"
    ATL::CAtlArray<Unk_VipItemRank> m_bonusItemRanks;  // +0x90 "bonusItemRank"
    ATL::CAtlArray<unsigned> m_bonusItemCounts; // +0xb0 "bonusItemCount"
    ATL::CAtlArray<__int64> m_bonusItemPeriods; // +0xd0 "bonusItemPeriod"
};
MS2_CHECK_SIZE(CVIPGoods, 0xf0);
MS2_CHECK_OFFSET(CVIPGoods, m_salesStartDate, 0x20);
MS2_CHECK_OFFSET(CVIPGoods, m_nPrice, 0x50);
MS2_CHECK_OFFSET(CVIPGoods, m_bonusItemIds, 0x70);
MS2_CHECK_OFFSET(CVIPGoods, m_bonusItemPeriods, 0xd0);

// One <benefit> row of vipBenefitItemTable.xml, 0x30 bytes.
class CVIPBenefitItem : public CPtred
{
public:
    CVIPBenefitItem();                      // 0x1408f55d0
    virtual ~CVIPBenefitItem();             // 0x1408f5640 (scalar deleting 0x1408f8130)

    unsigned m_nId;                         // +0x18 "id"
    unsigned m_nItemId;                     // +0x1c "itemID"
    unsigned m_nItemCount;                  // +0x20 "itemCount"
    int m_nItemRank;                        // +0x24 "itemRank" (ctor 1)
    __int64 m_nItemPeriod;                  // +0x28 "itemPeriod"
};
MS2_CHECK_SIZE(CVIPBenefitItem, 0x30);
MS2_CHECK_OFFSET(CVIPBenefitItem, m_nItemPeriod, 0x28);

// One <benefit> row of vipBenefitEffectTable.xml, 0x20 bytes.
class CVIPBenefitEffect : public CPtred
{
public:
    CVIPBenefitEffect();                    // 0x1408f5670
    virtual ~CVIPBenefitEffect();           // 0x1408f56c0 (scalar deleting 0x1408f80f0)

    unsigned m_nEffectId;                   // +0x18 "effectID"
    unsigned short m_nEffectLevel;          // +0x1c "effectLevel" (ctor 1)
};
MS2_CHECK_SIZE(CVIPBenefitEffect, 0x20);

typedef MS2Ptr<CVIPGoods> CVIPGoodsPtr;
typedef MS2Ptr<CVIPBenefitItem> CVIPBenefitItemPtr;
typedef MS2Ptr<CVIPBenefitEffect> CVIPBenefitEffectPtr;
typedef MS2Ptr<CCacheData> CVIPCachePtr;

// RTTI CVIPTable (TSingleton at +0, CValidData at +8), 0x140 bytes. The three tables reload themselves when the xml
// changed on disk (m_cache* keep the loaded files).
class CVIPTable : public TSingleton<CVIPTable>, public CValidData<CVIPTable>
{
public:
    CVIPTable();                            // 0x1408f56f0
    virtual ~CVIPTable();                   // 0x1408f5850 (scalar deleting 0x1408f81b0)

    int Load();                             // 0x1408f5930 all three tables
    int LoadGoods();                        // 0x1408f5a00
    int LoadBenefitItems();                 // 0x1408f6460
    int LoadBenefitEffects();               // 0x1408f68b0
    CVIPGoodsPtr GetGoods(unsigned nId);    // 0x1408f6c90
    CVIPBenefitItemPtr GetBenefitItem(unsigned nId);    // 0x1408f6d80
    void GetBenefitEffects(ATL::CAtlArray<CVIPBenefitEffectPtr>& rOut);     // 0x1408f6e80
    void GetBenefitItems(ATL::CAtlArray<CVIPBenefitItemPtr>& rOut);         // 0x1408f6f20
    void GetGoodsList(ATL::CAtlArray<CVIPGoodsPtr>& rOut);                  // 0x1408f7010
    MS2Ptr<AdditionalLevelData> GetFirstEffect();      // 0x1408f70b0 the skill of the first effect
    static void CheckInit();                       // 0x1408f86b0
    static void SetInit(bool bInit) { s_bInit = bInit; }    // 0x1408fb2a0
    static bool s_bInit;                    // DAT_143ab2630

    CLockCriticalSection m_lock;            // +0x10
    CVIPCachePtr m_cacheGoods;              // +0x40
    CVIPCachePtr m_cacheBenefitItems;       // +0x50
    CVIPCachePtr m_cacheBenefitEffects;     // +0x60
    ATL::CAtlMap<unsigned, CVIPGoodsPtr> m_goods;               // +0x70
    ATL::CAtlArray<CVIPGoodsPtr> m_goodsList;                   // +0xb8
    ATL::CAtlMap<unsigned, CVIPBenefitItemPtr> m_benefitItems;  // +0xd8
    ATL::CAtlArray<CVIPBenefitEffectPtr> m_benefitEffects;      // +0x120
};
MS2_CHECK_SIZE(CVIPTable, 0x140);
MS2_CHECK_OFFSET(CVIPTable, m_lock, 0x10);
MS2_CHECK_OFFSET(CVIPTable, m_goods, 0x70);
MS2_CHECK_OFFSET(CVIPTable, m_benefitItems, 0xd8);
MS2_CHECK_OFFSET(CVIPTable, m_benefitEffects, 0x120);
