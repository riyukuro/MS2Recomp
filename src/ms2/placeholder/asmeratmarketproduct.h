// asmeratmarketproduct.h - PLACEHOLDER for the merat market product AS objects. NOT an original header.
// The C++ side of one product row of the merat market (premium / limited / home shop products and UGC listings).
// RTTI: ASMeratMarketHomeProduct : ASMeratMarketLimitedProduct : ASMeratMarketProductBase : AScript : CPtred;
// ASMeratMarketProduct : ASMeratMarketProductBase. Here the base derives from the ASObj placeholder (no members of its
// own; it carries the member setter COMDATs). Code in ?\asitemslot.cpp (0x1409bbc30-0x1409c1ad0). vftables:
// base 0x142db92a0, product 0x142db92e0, limited 0x142db9320, home 0x142db9370. Member names are invented.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/asobj.h"

class Unk_MeratEquipEntry;      // the market product record (asequipicon.h forward declares it)
class Unk_MeratPremium;         // its premium (coin shop) part, +0x30
class Unk_MeratBanner;          // a banner of the market (a CString background at +0x18)
class Unk_MeratFilter;          // the market's job / level filter
struct Unk_MeratOid;            // the product id ("P<n>" / "U<n>" on the AS side)

// The view options of a product row: the debug flag (a GM view) and the filter.
struct Unk_MeratViewOpt
{
    bool m_bDebug;                                                          // +0x00
    MS2Ptr<Unk_MeratFilter> m_spFilter;                                     // +0x08
};

class ASMeratMarketProductBase : public ASObj
{
public:
    ASMeratMarketProductBase(int nMovieId);                                 // 0x1409bc150
    ASMeratMarketProductBase(const Scaleform::GFx::Value& v, int nMovieId); // 0x1409bc1c0
    ASMeratMarketProductBase(Scaleform::GFx::Value& v, int nMovieId);       // 0x1409bc240
    //  0 the implicit dtor 0x1409c13b0 (??_G 0x1409c1600)
    virtual bool vfunc_1(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt);  // 1 fill from a record
    virtual bool vfunc_2(MS2Ptr<Unk_MeratEquipEntry> spEntry);              //  2 refresh from a record
    virtual bool vfunc_3(MS2Ptr<Unk_MeratEquipEntry> spEntry, const CString& strBg);   // 3 id + background
    virtual bool vfunc_4();                                                 //  4 sold out
    virtual bool vfunc_5();                                                 //  5 expired
    virtual void vfunc_6(bool bSoldOut);                                    //  6 set sold out

    // Creates the product object of an AS value / of a product type (2 home, 1 limited, else plain).
    static MS2Ptr<ASMeratMarketProductBase> FUN_1409bbc30(Scaleform::GFx::Value& v, const int& nMovieId);
    static MS2Ptr<ASMeratMarketProductBase> FUN_1409bbf30(const int& nType, const int& nMovieId);

    void SetIndex(int nIndex);                                         // m_nIndex = nIndex
    void FUN_1409bc4a0(const CString& strBg);                               // "bgPath"
    void SetBanner(MS2Ptr<Unk_MeratBanner> spBanner);                   // m_spBanner = spBanner
    void FUN_1409bc540(const int& nIndex);                                  // "index"
    void FUN_1409bc580(MS2Ptr<Unk_MeratEquipEntry> spEntry);                // "productOID" of a record
    void FUN_1409bc630(const Unk_MeratOid& oid);                            // "productOID"
    int GetIndex();                                                    // m_nIndex
    void FUN_1409bc6a0(Unk_MeratOid* pOid);                                 // parses "productOID"
    unsigned int FUN_1409bc720();                                           // "index"
    int GetProductType();                                                    // m_nProductType

    // Member setters (one COMDAT per enum type of the original).
    void FUN_1409c0f00(const char* szName, int n);                          // product type
    void FUN_1409c0fa0(const char* szName, int n);                          // product UI type
    void FUN_1409c1040(const char* szName, int n);                          // price type
    void FUN_1409c10e0(const char* szName, int n);                          // sale state

protected:
    MS2_LAYOUT_FRIEND;
    int m_nIndex;                                                           // +0x40
    MS2Ptr<Unk_MeratBanner> m_spBanner;                                     // +0x48
    int m_nProductType;                                                     // +0x58 0 plain, 1 limited, 2 home
};
MS2_CHECK_SIZE(ASMeratMarketProductBase, 0x60);
MS2_CHECK_OFFSET(ASMeratMarketProductBase, m_nIndex, 0x40);
MS2_CHECK_OFFSET(ASMeratMarketProductBase, m_spBanner, 0x48);
MS2_CHECK_OFFSET(ASMeratMarketProductBase, m_nProductType, 0x58);

class ASMeratMarketProduct : public ASMeratMarketProductBase
{
public:
    ASMeratMarketProduct(int nMovieId);                                     // 0x1409bc7a0
    ASMeratMarketProduct(const Scaleform::GFx::Value& v, int nMovieId);     // 0x1409bc7f0
    ASMeratMarketProduct(Scaleform::GFx::Value& v, int nMovieId);           // 0x1409bc850
    //  0 the implicit dtor 0x1409c1390 (??_G 0x1409c15c0)
    virtual bool vfunc_1(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt);  // 1 0x1409bc8b0
    virtual bool vfunc_4();                                                 //  4 0x1409bd8e0

    void FUN_1409bd940(MS2Ptr<Unk_MeratEquipEntry> spEntry);                // "price" / "salePrice"
};
MS2_CHECK_SIZE(ASMeratMarketProduct, 0x60);

class ASMeratMarketLimitedProduct : public ASMeratMarketProductBase
{
public:
    ASMeratMarketLimitedProduct(int nMovieId);                              // 0x1409bdd60
    ASMeratMarketLimitedProduct(const Scaleform::GFx::Value& v, int nMovieId);  // 0x1409bddb0
    ASMeratMarketLimitedProduct(Scaleform::GFx::Value& v, int nMovieId);    // 0x1409bde10
    virtual ~ASMeratMarketLimitedProduct();                                 //  0 0x1409bde70 (??_G 0x1409c1580)
    virtual bool vfunc_1(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt);  // 1 0x1409bdea0
    virtual bool vfunc_2(MS2Ptr<Unk_MeratEquipEntry> spEntry);              //  2 0x1409be1f0
    virtual bool vfunc_4();                                                 //  4 0x1409be390
    virtual bool vfunc_5();                                                 //  5 0x1409be4a0
    virtual void vfunc_7(MS2Ptr<Unk_MeratEquipEntry> spEntry);              //  7 0x1409be500 "itemName" / "desc"
    virtual void vfunc_8(Unk_MeratPremium& premium);                        //  8 0x1409bfc20 "expired"

    void FUN_1409be940(Unk_MeratPremium& premium);                          // prices by sale kind
    void FUN_1409be9b0(Unk_MeratPremium& premium);                          // plain prices
    void FUN_1409bef00(Unk_MeratPremium& premium);                          // random payback prices
    void FUN_1409bf300(Unk_MeratPremium& premium);                          // random coupon prices
    void FUN_1409bf780(Unk_MeratPremium& premium);                          // "remain" / "soldOut"
};
MS2_CHECK_SIZE(ASMeratMarketLimitedProduct, 0x60);

class ASMeratMarketHomeProduct : public ASMeratMarketLimitedProduct
{
public:
    ASMeratMarketHomeProduct(int nMovieId);                                 // 0x1409bfc60
    ASMeratMarketHomeProduct(const Scaleform::GFx::Value& v, int nMovieId); // 0x1409bfcb0
    ASMeratMarketHomeProduct(Scaleform::GFx::Value& v, int nMovieId);       // 0x1409bfd10
    //  0 the implicit dtor 0x1409c1370 (??_G 0x1409c1540)
    virtual bool vfunc_1(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt);  // 1 0x1409bfd70
    virtual bool vfunc_4();                                                 //  4 0x1409c00e0
    virtual void vfunc_6(bool bSoldOut);                                    //  6 0x1409c0140
    virtual void vfunc_7(MS2Ptr<Unk_MeratEquipEntry> spEntry);              //  7 0x1409c0170
    virtual void vfunc_8(Unk_MeratPremium& premium);                        //  8 0x1409c0430

    void FUN_1409c05d0(MS2Ptr<Unk_MeratEquipEntry> spEntry, const Unk_MeratViewOpt* pOpt);   // item fields
};
MS2_CHECK_SIZE(ASMeratMarketHomeProduct, 0x60);
