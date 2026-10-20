// shoptabinfo.h - the shop tab / banner helper types of the merat market, the NPC shops and the beauty shops, and the shared
// shop helper functions of unit_141347b10 (0x141347b10-0x14134c9d0). Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); class names from RTTI (.?AVShopTabInfo@@, .?AVNpcShopTabInfo@@, .?AVMeratMarketShopBannerInfo@@,
// .?AVShopBanner@@), layouts confirmed by the v2525 snapshot (ShopTabInfo.h, NpcShopTabInfo.h, ShopBanner.h). Header name
// assumed, member and function names invented (the free functions keep their FUN_ names: other units bind to them).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/client/ms2/shopbannerinfo.h"
#include "ms2/commonfiles/shopcategorytable.h"

class ASObj;
class ASArray;
class ASTooltip;
class CItem;
class CNpcShopProductBase;
namespace Scaleform { namespace GFx { class Value; } }

// One tab of a shop's tab bar: the category table row and its depth in the tree (RTTI ShopTabInfo, base CPtred, 0x30).
class ShopTabInfo : public CPtred
{
public:
    ShopTabInfo(MS2Ptr<CShopCategoryTable::TabInfo> spTab);         // 0x14134aa80 (by value: the callee destroys it)
    // ~ShopTabInfo() is implicit (0x14134ac00, ??_G 0x14134b080: no vftable store)
    virtual void vfunc_1() {}                                       //  1 0x14134c030

    MS2Ptr<CShopCategoryTable::TabInfo> m_spTab;                    // +0x18
    int m_nDepth;                                                   // +0x28
};
MS2_CHECK_SIZE(ShopTabInfo, 0x30);
MS2_CHECK_OFFSET(ShopTabInfo, m_spTab, 0x18);
MS2_CHECK_OFFSET(ShopTabInfo, m_nDepth, 0x28);

// A tab of an NPC shop with the products listed under it (RTTI NpcShopTabInfo, 0x50).
class NpcShopTabInfo : public ShopTabInfo
{
public:
    NpcShopTabInfo(MS2Ptr<CShopCategoryTable::TabInfo> spTab);      // 0x14134aa00
    // ~NpcShopTabInfo() is implicit (0x14134abd0, ??_G 0x14134b000)
    virtual void vfunc_1() {}                                       //  1 0x14134c020

    ATL::CAtlArray<MS2Ptr<CNpcShopProductBase> > m_products;        // +0x30
};
MS2_CHECK_SIZE(NpcShopTabInfo, 0x50);
MS2_CHECK_OFFSET(NpcShopTabInfo, m_products, 0x30);

// The product key of a merat market banner: the layout and default ctor (0x1402038a0) of Unk_MeratProductKey
// (meratmarketbasketinfo.h). That header models CShopCategoryTable with its own placeholder, so it cannot be included
// next to shopcategorytable.h; the banner keeps a layout-equal copy.
struct Unk_ShopBannerProductKey
{
    Unk_ShopBannerProductKey() { m_nPremiumId = 0; m_nUgcId = 0; }

    int m_nPremiumId;                                               // +0x00
    __int64 m_nUgcId;                                               // +0x08
};
MS2_CHECK_SIZE(Unk_ShopBannerProductKey, 0x10);

// A merat market banner with the product it links to (RTTI MeratMarketShopBannerInfo, 0x58).
class MeratMarketShopBannerInfo : public ShopBannerInfo
{
public:
    MeratMarketShopBannerInfo();                                    // 0x141347e70
    // ~MeratMarketShopBannerInfo() is implicit (0x14134abb0, ??_G 0x14134afc0)

    int m_nProduct;                                                 // +0x40 (-1: none)
    Unk_ShopBannerProductKey m_key;                                      // +0x48
};
MS2_CHECK_SIZE(MeratMarketShopBannerInfo, 0x58);
MS2_CHECK_OFFSET(MeratMarketShopBannerInfo, m_nProduct, 0x40);
MS2_CHECK_OFFSET(MeratMarketShopBannerInfo, m_key, 0x48);

// keyed case-insensitively (the exe tree compares with _mbsicmp)
typedef ATL::CRBMap<CStringA, MS2Ptr<ShopBannerInfo>, ATL::CStringElementTraitsI<CStringA> > Unk_ShopBannerMap;

// The banners of a shop by name (RTTI ShopBanner, base CPtred, 0x48). The ctor / dtor live in uimeratmarketdialog.cpp.
class ShopBanner : public CPtred
{
public:
    ShopBanner();                                                   // 0x141314210
    virtual ~ShopBanner();                                          // 0x1413147c0

    void FUN_141347ed0(MS2Ptr<ShopBannerInfo> spInfo);                                  // add (keyed by its name)
    MS2Ptr<ShopBannerInfo> FUN_141347f50(const Unk_AdBannerPtr& spBanner, int nType);   // add one from an ad banner
    MS2Ptr<ShopBannerInfo> FUN_1413480a0(const CString& strName);                       // find by name
    void FUN_141348160(const CString& strUrl);                                          // open a banner link
    void FUN_141348190(ASArray& arr);                                                   // write all banners
    void Clear();                                                                       // 0x1413154e0 inline: m_banners.RemoveAll()

    Unk_ShopBannerMap m_banners;                                    // +0x18
};
MS2_CHECK_SIZE(ShopBanner, 0x48);
MS2_CHECK_OFFSET(ShopBanner, m_banners, 0x18);

typedef ATL::CAtlArray<MS2Ptr<ShopTabInfo> > Unk_ShopTabArray;

// Tab list builders.
int FUN_1413482e0(const Unk_ShopTabArray& arr, MS2Ptr<CShopCategoryTable::TabInfo> spTab);   // index of the tab, -1
int FUN_1413483c0(const CString& strCategory, const CString& strList);                       // category in a "a,b,c" list
void FUN_141348530(int nShop, Unk_ShopTabArray& arr);
void FUN_141348610(int nShop, Unk_ShopTabArray& arr, std::map<int, MS2Ptr<CNpcShopProductBase> >& products);
void FUN_1413487e0(Unk_ShopTabArray& arr, CShopCategoryTable::TabList& list, MS2Ptr<CNpcShopProductBase> spProduct,
                   int nDepth);
void FUN_141348cf0(const Unk_ShopTabArray& arr, MS2Ptr<AScript> spRoot, int nSale, Delegate<void(AScript&)>* pfnEach);   // exe RTTI: Delegate<void(AScript&)>
void FUN_141348dd0(const Unk_ShopTabArray& arr, ASArray& out, int* pMaxDepth, int nSale, Delegate<void(AScript&)>* pfnEach);

// Item tooltips compared with the equipped item.
void FUN_1413490b0(MS2Ptr<CItem> spItem, Scaleform::GFx::Value* pOut, bool bCaption, int nLhsFlags, int nRhsFlags);
void FUN_141349210(MS2Ptr<CItem> spItem, Scaleform::GFx::Value* pOut, bool bCaption, ASTooltip* pLhs, ASTooltip* pRhs);

int FUN_1413499b0(int nTab);                                                    // open the shop on a tab
void FUN_141349ae0(MS2Ptr<CItem> spItem, int nStringId, const CString& strUrl); // item message box
void FUN_141349ba0(MS2Ptr<CItem> spItem, CStringW strText, const CString& strUrl);
int FUN_141349e30(const CString& strKind);                                      // banner link kind (link=1 .. searchBySN=5)

// Currency helpers (nKind: the shop currency kind, mapped by FUN_14134a170).
__int64 FUN_141349ef0(int nKind, int nItemId, unsigned int nAmount);
void FUN_141349f30(CStringW& strOut, int nKind, int nArg, unsigned int nAmount, const CString& strCurrency);
bool FUN_14134a030(int nKind, int nItemId, unsigned int nAmount);
CStringW FUN_14134a070(int nKind, int nArg, unsigned int nAmount);
void FUN_14134a120(int nKind, int nItemId, unsigned int nAmount);
int FUN_14134a170(int nKind);
