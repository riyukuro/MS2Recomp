// asbilldata.h - PLACEHOLDER for ASBillData (RTTI .?AVASBillData@@, 0x50 bytes), the C++ side of one row of the merat
// market's purchase dialog (what is bought, for which currency, the payback). NOT an original header. Code in
// ?\asbilldata.cpp: ctors 0x1409ab7c0 (movie id) / 0x1409ab810 (const Value&) / 0x1409ab870 (Value&), dtor 0x1409ab8d0,
// vftable 0x142db6708. The getters are plain virtuals; the base returns the defaults and the merat market rows
// (derived classes elsewhere) override them. Member names are invented.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asobj.h"

class CItemData;

class ASBillData : public ASObj
{
public:
    ASBillData(int nMovieId);                                       // 0x1409ab7c0
    ASBillData(const Scaleform::GFx::Value& v, int nMovieId);       // 0x1409ab810
    ASBillData(Scaleform::GFx::Value& v, int nMovieId);             // 0x1409ab870
    virtual ~ASBillData();                                          //  0 0x1409ab8d0 (??_G 0x1409b0290)
    virtual int vfunc_1();                                          //  1 0x1409abd60 the item id (0)
    virtual __int64 vfunc_2();                                      //  2 0x1409abd70 the price
    virtual __int64 vfunc_3();                                      //  3 0x1409abe30 the discount
    virtual int vfunc_4();                                          //  4 0x1409abef0 the pay type (m_44)
    virtual int vfunc_5();                                          //  5 0x1409abf10 the "index" member
    virtual __int64 vfunc_6();                                      //  6 0x1409abf50 the payback (0)
    virtual __int64 vfunc_7();                                      //  7 0x1409abf60 the payback discount (0)
    virtual int vfunc_8();                                          //  8 0x1409abf70 the payback type (m_4c)
    virtual __int64 vfunc_9();                                      //  9 0x1409abf90 the random payback (0)

    // Setters of the row's AS members (uivipgoodsshopdialog.cpp fills a VIP row with them; the names follow the AS members).
    void ResetDefaults();                                           // 0x1409ab900 the defaults of the C++ side members
    void SetIconData(Scaleform::GFx::Value& vSlot);               // 0x1409ab940 "iconData"
    void SetIconFromItem(MS2Ptr<CItemData> spItem, int nRank);        // 0x1409ab990 the item (icon slot) of the row
    void SetItemName(const CStringW& strName);                    // 0x1409aba80 "itemName"
    void SetSalePrice(const CStringW& strPrice, __int64 nPrice);   // 0x1409abad0 "strSalePrice" / "salePrice"
    void SetRandomPaybackPrice(const CStringW& strPrice, __int64 nPrice);   // 0x1409abb60 "strRandomPaybackPrice" / "randomPaybackPrice"
    void SetSelectedOption(const CStringW& strExtra);                   // 0x1409abbf0 "selectedOption"
    void SetOptionArray(Scaleform::GFx::Value& vOptions);            // 0x1409abc40 "arrOption"
    void SetEnableGift(bool b);                                     // 0x1409abc90 "enableGift" (also kept in m_b40; callers pass a byte)
    void SetPayType(int nPayType);                               // 0x1409abcd0 the pay type
    void SetUseDropDown(bool b);                                     // 0x1409abcf0 "useDropDown"
    void FUN_1409abd20(bool b);                                     // 0x1409abd20 m_b48 (callers: mov dl, 1)
    void FUN_1409abd40(int n);                                      // 0x1409abd40 the payback type (m_n4c)
    Scaleform::GFx::Value GetSelectCurData();                          // 0x1409ac0b0 "selectData"."curData"
    Scaleform::GFx::Value GetSelectPrevData();                          // 0x1409ac190 "selectData"."prevData"
    Scaleform::GFx::Value GetSelectData();                          // 0x1409ac270 "selectData"
    __int64 GetSalePriceFromData(ASObj* pData);                            // 0x1409ac2c0 the "salePrice" of a row object
    bool SetOptionDropDown(class CMeratMarketPremiumProduct* pProduct, int nOption, int nCurrency);   // 0x1409acfe0 the option drop down
    void AddOptionRow(class ASArray& arr, int nCurrency, class CDBPremiumProduct* pSub, bool bDay,
                       class CDBPremiumProduct* pBase);             // 0x1409ad420 one option row
    bool IsChecked() const { return m_b40; }                    // 0x140eacf60 (inline COMDAT, uimarketbilldialog.cpp)
    bool FUN_140eacf20() const { return m_b48; }                    // 0x140eacf20 (same)
    bool m_b40;                                                     // +0x40
    int m_n44;                                                      // +0x44 1
    bool m_b48;                                                     // +0x48
    int m_n4c;                                                      // +0x4c 0x11
};
MS2_CHECK_SIZE(ASBillData, 0x50);
