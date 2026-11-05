// pricetable.h - CPriceTable (RTTI name, 0xc8 bytes): the shop price tables read from Table/shop_Maid.xml and
// Table/shop_UGCAll.xml (ugc housing prices, keyed by item id) and Table/MaidSalary.xml (maid salaries). A cached data
// record (CCacheData +0, TSingleton +0x28, CValidData +0x30). Header name assumed from the unit path; member and helper
// names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"

class TiXmlElement;    // xml element (declared where the loaders are)

// One <key> row of MaidSalary.xml: salary type and amount (8 bytes).
struct Unk_PriceSalary
{
    Unk_PriceSalary();                  // 0x140738a70
    int m_nType;                        // "SalaryType"
    int m_nAmount;                      // "SalaryAmount"
};
MS2_CHECK_SIZE(Unk_PriceSalary, 8);

// One <key> row of shop_UGCAll.xml / shop_Maid.xml (0x18 bytes).
struct Unk_PriceHousing
{
    Unk_PriceHousing();                 // 0x140738a30
    bool m_bBuy;                        // "ugcHousingBuy"
    __int64 m_nDefaultPrice;            // "ugcHousingDefaultPrice"
    int m_nMoneyType;                   // "ugcHousingMoneyType"
};
MS2_CHECK_SIZE(Unk_PriceHousing, 0x18);

class CPriceTable : public CCacheData, public TSingleton<CPriceTable>, public CValidData<CPriceTable>
{
public:
    typedef ATL::CAtlMap<int, Unk_PriceSalary> SalaryMap;
    typedef ATL::CAtlMap<unsigned, Unk_PriceHousing> HousingMap;

    CPriceTable();                      // 0x140738aa0
    // implicit virtual dtor: 0x1407396f0 (??_G 0x1407397f0)

    int Load();                         // 0x140738ba0 shop_Maid.xml, shop_UGCAll.xml, MaidSalary.xml; stops at the first failure
    void GetSalary(int nId, int* pnType, int* pnAmount);                                   // 0x140738cd0
    void GetHousing(unsigned nId, bool* pbBuy, __int64* pnPrice, int* pnMoneyType);          // 0x140738d40
    int HasHousing(unsigned nId);       // 0x140738dc0
    int IsHousingBuyable(unsigned nId); // 0x140738e00
    int LoadHousing(const CString& strFile);    // 0x140738e60
    int LoadSalary(const CString& strFile);     // 0x1407390e0

private:
    MS2_LAYOUT_FRIEND;
    SalaryMap m_salaries;               // +0x38 maid id -> salary
    HousingMap m_housing;               // +0x80 item id -> housing price
};
MS2_CHECK_SIZE(CPriceTable, 0xc8);
MS2_CHECK_OFFSET(CPriceTable, m_salaries, 0x38);
MS2_CHECK_OFFSET(CPriceTable, m_housing, 0x80);
