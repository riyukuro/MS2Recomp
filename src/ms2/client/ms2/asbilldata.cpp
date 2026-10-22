// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ASBillData: one row of a purchase bill (merat market, cash
// shop, VIP goods, mail ads): the AS object the bill dialogs show, with its C++ side pay type / payback members, the
// price readers of the selected option and the option drop down of a premium product. ASMeratMarketBuyBillData: the
// merat market's row (product, basket line or UGC option). Names of the FUN_ helpers are not known; the AS member
// names come from the strings. See placeholder/asbilldata.h and placeholder/asmeratmarketbuybilldata.h.
// MS2-UNIT: ?\asbilldata.cpp
// MS2-RANGE: 0x1409ab7c0-0x1409b0fd0 .text$mn
// MS2-RANGE: 0x1400c0170-0x1400c03c0 .text$di
// MS2-RANGE: 0x142c9d8d0-0x142c9d9b0 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\asbilldata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/asbilldata.h"
#include "ms2/placeholder/asmeratmarketbuybilldata.h"
#include "ms2/placeholder/cmeratmarketman.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/gfxvalue.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/commonfiles/commonstruct.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <vector>

// ---- statics of the market's shared headers (the two sort name tables, the key controller, three attribute names) ----

// @0x1400c0170
static CStringA s_marketSortNames[8] = { "None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd" };
// @0x1400c0240
static CStringA s_ugcMarketSortNames[7] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
// @0x1400c0300
static UICommon::CMyPCKeyInputController s_keyInput;
// @0x1400c0330
static CStringA s_strJobCode = "jobCode";
// @0x1400c0360
static CStringA s_strSortValue = "sortValue";
// @0x1400c0390
static CStringA s_strTabIndex = "tabIndex";

// ---- exe functions called here ----

CString FUN_1407194b0(__int64 n);                               // a number as text (unit_1407186f0)
CString FUN_140719190(unsigned int n);                          // an unsigned number as text
__int64 FUN_1407182f0(const CString& s);                        // text -> __int64
int FUN_140718170(const CString& s);                            // text -> int
CStringW FUN_1418fec00(int nMoneyType, __int64 nAmount, bool bIcon);   // a money text (uicommon.cpp)
CStringW FUN_14028b8e0(const CStringW& strKey);                 // the string-table text of a key (commonutil.cpp)
CStringW FUN_1409404f0(__int64 nValue);                         // a number with separators (achievemanager.cpp)
MS2Ptr<CItemData> FUN_14053f870(unsigned nItemId);              // the item data of an id
bool FUN_1406a5930();                                           // star points are enabled (meratmarketbasketinfo.cpp)
CStringW FUN_140ebd020(bool bDay, CDBPremiumProduct* pProduct); // the option label (uimeratmarketcommon.cpp)
CStringW FUN_140ebd520(CMeratMarketPremiumProduct* pProduct, int nSubId);   // the chosen option's text
CStringW FUN_140ebd870(CMeratMarketPremiumProduct* pProduct);   // the option text of a UGC option
CStringW FUN_140ec05f0(CDBPremiumProduct* pProduct);            // the star point text
void FUN_1407cd930(Scaleform::GFx::Value* pObj, const char* szName, const Scaleform::GFx::Value& v);   // set a member of an AS object

// defined below
void FUN_1409ad9c0(ASObj& obj, const CStringW& strPoint, __int64 nPoint);   // "strStarPoint" / "starPoint"
int FUN_1409ada50(const Scaleform::GFx::Value& vData);          // the "marketSN" of a row object

extern __int64 DAT_143ab2820;                                   // the own account id
extern unsigned DAT_143ab2830;                                  // the own character type
extern int DAT_143ab2834;
extern __int64 DAT_143ab2838;                                   // the own character id

// The owner of a UGC listing as the gift check wants it (0x20 bytes; astooltip's Unk_TooltipItemOwner).
struct Unk_BillOwner
{
    // @0x1409aff60
    Unk_BillOwner() { id = 0; kind = 0; alternate = 0; m_n18 = 0; }
    __int64 id;
    unsigned kind;
    void* alternate;
    __int64 m_n18;
};
MS2_CHECK_SIZE(Unk_BillOwner, 0x20);

// The order of the premium options: by the "day" column or by the plain order column.
struct Unk_PremiumOptionLess
{
    // @0x1409aff40
    Unk_PremiumOptionLess(bool bDay) : m_bDay(bDay) {}
    // @0x1409b0150
    bool operator()(MS2Ptr<CDBPremiumProduct> a, MS2Ptr<CDBPremiumProduct> b)
    {
        if (m_bDay)
            return a->m_nb4 < b->m_nb4;
        return a->m_nb0 < b->m_nb0;
    }
    bool m_bDay;
};

// ======== ASBillData ========

// @0x1409ab7c0
ASBillData::ASBillData(int nMovieId)
    : ASObj(nMovieId)
{
    FUN_1409ab900();
}

// @0x1409ab810
ASBillData::ASBillData(const Scaleform::GFx::Value& v, int nMovieId)
    : ASObj(v, nMovieId)
{
    FUN_1409ab900();
}

// @0x1409ab870
ASBillData::ASBillData(Scaleform::GFx::Value& v, int nMovieId)
    : ASObj(v, nMovieId)
{
    FUN_1409ab900();
}

// @0x1409ab8d0
ASBillData::~ASBillData()
{
}

// @0x1409ab900
void ASBillData::FUN_1409ab900()
{
    m_b40 = false;
    m_n44 = 1;
    m_b48 = false;
    m_n4c = 0x11;
}

// @0x1409ab940
void ASBillData::FUN_1409ab940(Scaleform::GFx::Value& vSlot)
{
    FUN_1409adbe0("iconData", vSlot);
}
MS2_REPLACE_METHOD(0x1409AB940, ASBillData, FUN_1409ab940, 71, 0x73D0CD34);

// @0x1409ab990
void ASBillData::FUN_1409ab990(MS2Ptr<CItemData> spItem, int nRank)
{
    if (spItem == 0)
        return;
    ASObj icon(2);
    icon.FUN_1407cba60("iconPath", spItem->FUN_14053fdd0());
    icon.FUN_1409adc90("itemGrade", nRank);
    FUN_1409ab940(icon.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409AB990, ASBillData, FUN_1409ab990, 234, 0x5F038C27);

// @0x1409aba80
void ASBillData::FUN_1409aba80(const CStringW& strName)
{
    FUN_1407cbb20("itemName", strName);
}
MS2_REPLACE_METHOD(0x1409ABA80, ASBillData, FUN_1409aba80, 72, 0x1A28C6D2);

// @0x1409abad0
void ASBillData::FUN_1409abad0(const CStringW& strPrice, __int64 nPrice)
{
    FUN_1407cbb20("strSalePrice", strPrice);
    FUN_1407cba60("salePrice", FUN_1407194b0(nPrice));
}
MS2_REPLACE_METHOD(0x1409ABAD0, ASBillData, FUN_1409abad0, 129, 0x76980772);

// @0x1409abb60
void ASBillData::FUN_1409abb60(const CStringW& strPrice, __int64 nPrice)
{
    FUN_1407cbb20("strRandomPaybackPrice", strPrice);
    FUN_1407cba60("randomPaybackPrice", FUN_1407194b0(nPrice));
}
MS2_REPLACE_METHOD(0x1409ABB60, ASBillData, FUN_1409abb60, 129, 0x0E42B535);

// @0x1409abbf0
void ASBillData::FUN_1409abbf0(const CStringW& strExtra)
{
    FUN_1407cbb20("selectedOption", strExtra);
}
MS2_REPLACE_METHOD(0x1409ABBF0, ASBillData, FUN_1409abbf0, 72, 0x365E5D36);

// @0x1409abc40
void ASBillData::FUN_1409abc40(Scaleform::GFx::Value& vOptions)
{
    FUN_1409adbe0("arrOption", vOptions);
}
MS2_REPLACE_METHOD(0x1409ABC40, ASBillData, FUN_1409abc40, 71, 0xC2269486);

// @0x1409abc90
void ASBillData::FUN_1409abc90(bool b)
{
    m_b40 = b;
    FUN_1407cbbe0("enableGift", b);
}
MS2_REPLACE_METHOD(0x1409ABC90, ASBillData, FUN_1409abc90, 54, 0xB0F6926C);

// @0x1409abcd0
void ASBillData::FUN_1409abcd0(int nPayType)
{
    m_n44 = nPayType;
}
MS2_REPLACE_METHOD(0x1409ABCD0, ASBillData, FUN_1409abcd0, 22, 0x1DE9BE0F);

// @0x1409abcf0
void ASBillData::FUN_1409abcf0(bool b)
{
    FUN_1407cbbe0("useDropDown", b);
}
MS2_REPLACE_METHOD(0x1409ABCF0, ASBillData, FUN_1409abcf0, 41, 0xFD21E71E);

// @0x1409abd20
void ASBillData::FUN_1409abd20(bool b)
{
    m_b48 = b;
}
MS2_REPLACE_METHOD(0x1409ABD20, ASBillData, FUN_1409abd20, 23, 0x5A918555);

// @0x1409abd40
void ASBillData::FUN_1409abd40(int n)
{
    m_n4c = n;
}
MS2_REPLACE_METHOD(0x1409ABD40, ASBillData, FUN_1409abd40, 22, 0x4DFF2457);

// @0x1409abd60
int ASBillData::vfunc_1()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1409ABD60, ASBillData, vfunc_1, 8, 0x7F371472);

// @0x1409abd70
__int64 ASBillData::vfunc_2()
{
    Scaleform::GFx::Value vData = FUN_1409ac0b0();
    if (!vData.IsUndefined())
    {
        ASObj data(vData, 2);
        return FUN_1409ac2c0(&data);
    }
    return FUN_1409ac2c0(this);
}
MS2_REPLACE_METHOD(0x1409ABD70, ASBillData, vfunc_2, 179, 0xFEAC3D06);

// @0x1409abe30
__int64 ASBillData::vfunc_3()
{
    Scaleform::GFx::Value vData = FUN_1409ac190();
    if (!vData.IsUndefined())
    {
        ASObj data(vData, 2);
        return FUN_1409ac2c0(&data);
    }
    return FUN_1409ac2c0(this);
}
MS2_REPLACE_METHOD(0x1409ABE30, ASBillData, vfunc_3, 179, 0xA6435739);

// @0x1409abef0
int ASBillData::vfunc_4()
{
    return m_n44;
}
MS2_REPLACE_METHOD(0x1409ABEF0, ASBillData, vfunc_4, 14, 0x7A15C443);

// @0x1409abf10
int ASBillData::vfunc_5()
{
    int nIndex = -1;
    FUN_1422bae10("index", nIndex);
    return nIndex;
}
MS2_REPLACE_METHOD(0x1409ABF10, ASBillData, vfunc_5, 48, 0x488E5FE8);

// @0x1409abf50
__int64 ASBillData::vfunc_6()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1409ABF50, ASBillData, vfunc_6, 8, 0x7F371472);

// @0x1409abf60
__int64 ASBillData::vfunc_7()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1409ABF60, ASBillData, vfunc_7, 8, 0x7F371472);

// @0x1409abf70
int ASBillData::vfunc_8()
{
    return m_n4c;
}
MS2_REPLACE_METHOD(0x1409ABF70, ASBillData, vfunc_8, 14, 0xAA28048B);

// @0x1409abf90
__int64 ASBillData::vfunc_9()
{
    return 0;
}
MS2_REPLACE_METHOD(0x1409ABF90, ASBillData, vfunc_9, 8, 0x7F371472);

// The item ids of the bill rows (rows without an item are skipped).
// @0x1409abfa0
void FUN_1409abfa0(CAtlArray<int>& arrIds, CAtlArray<MS2Ptr<ASBillData> >& arrBills)
{
    arrIds.RemoveAll();
    if (arrBills.IsEmpty())
        return;
    size_t nCount = arrBills.GetCount();
    for (size_t i = 0; i < nCount; ++i)
    {
        MS2Ptr<ASBillData> spBill = arrBills[i];
        if (spBill == 0)
            continue;
        int nId = spBill->vfunc_1();
        if (nId == 0)
            continue;
        arrIds.Add(nId);
    }
}
MS2_REPLACE(0x1409ABFA0, FUN_1409abfa0, 262, 0x2A82FF5F);

// @0x1409ac0b0
Scaleform::GFx::Value ASBillData::FUN_1409ac0b0()
{
    Scaleform::GFx::Value vSelect = FUN_1409ac270();
    if (!vSelect.IsUndefined())
    {
        ASObj select(vSelect, 2);
        return select.FUN_1422baa20("curData");
    }
    return Scaleform::GFx::Value();
}
MS2_REPLACE_METHOD(0x1409AC0B0, ASBillData, FUN_1409ac0b0, 209, 0xE5BA6A3E);

// @0x1409ac190
Scaleform::GFx::Value ASBillData::FUN_1409ac190()
{
    Scaleform::GFx::Value vSelect = FUN_1409ac270();
    if (!vSelect.IsUndefined())
    {
        ASObj select(vSelect, 2);
        return select.FUN_1422baa20("prevData");
    }
    return Scaleform::GFx::Value();
}
MS2_REPLACE_METHOD(0x1409AC190, ASBillData, FUN_1409ac190, 209, 0x0D3D0055);

// @0x1409ac270
Scaleform::GFx::Value ASBillData::FUN_1409ac270()
{
    return FUN_1422baa20("selectData");
}
MS2_REPLACE_METHOD(0x1409AC270, ASBillData, FUN_1409ac270, 65, 0xA5AB95CF);

// @0x1409ac2c0
__int64 ASBillData::FUN_1409ac2c0(ASObj* pData)
{
    const CString& strName = CString("salePrice");
    CString strValue;
    pData->FUN_1422bac00(strName, strValue);
    return FUN_1407182f0(strValue);
}
MS2_REPLACE_METHOD(0x1409AC2C0, ASBillData, FUN_1409ac2c0, 141, 0x06C8075C);

// ======== ASMeratMarketBuyBillData ========

// @0x1409ac360
void ASMeratMarketBuyBillData::FUN_1409ac360(MS2Ptr<CMeratMarketProduct> spProduct, int nOption, int nCurrency)
{
    SetProduct(spProduct);
    if (spProduct == 0)
        return;
    FUN_1407cbb20("productOID", spProduct->m_key.FUN_1409b0470());
    if (spProduct->IsPremium())
    {
        FUN_1409ac6f0(&spProduct->m_premium, nOption, nCurrency);
    }
    else if (spProduct->IsUgc())
    {
        FUN_1409aba80(spProduct->GetName());
        __int64 nPrice = spProduct->GetSalePrice();
        CStringW strPrice = FUN_1418fec00(nCurrency, nPrice, false);
        FUN_1409abad0(strPrice, nPrice);
        Unk_BillOwner owner;
        owner.id = DAT_143ab2820;
        owner.kind = DAT_143ab2830;
        owner.alternate = (void*)DAT_143ab2838;
        owner.m_n18 = DAT_143ab2834;
        // ugcdef.h types the owner as the 0x18-byte Unk_CommonOwner
        bool bGift = spProduct->m_ugc.FUN_1408963f0(reinterpret_cast<Unk_CommonOwner&>(owner));
        FUN_1409abc90(bGift);
        FUN_1409abcd0(nCurrency);
    }
}
MS2_REPLACE_METHOD(0x1409AC360, ASMeratMarketBuyBillData, FUN_1409ac360, 630, 0x118941BF);

// @0x1409ac5e0
void ASMeratMarketBuyBillData::FUN_1409ac5e0(MS2Ptr<CMeratMarketBasket> spBasket)
{
    if (spBasket == 0 || spBasket->m_spProduct == 0)
        return;
    int nCurrency = FUN_14069c3e0(spBasket->m_spProduct->GetPayCurrency());
    FUN_1409ac360(spBasket->m_spProduct, spBasket->m_n30, nCurrency);
    FUN_1409b03d0(spBasket->m_n28);
}
MS2_REPLACE_METHOD(0x1409AC5E0, ASMeratMarketBuyBillData, FUN_1409ac5e0, 255, 0xCADAF70F);

// @0x1409ac6f0
void ASMeratMarketBuyBillData::FUN_1409ac6f0(CMeratMarketPremiumProduct* pProduct, int nOption, int nCurrency)
{
    FUN_1409aba80(pProduct->GetName());
    __int64 nPrice = pProduct->GetSalePriceOf(nOption);
    CStringW strPrice = FUN_1418fec00(nCurrency, nPrice, false);
    FUN_1409abad0(strPrice, nPrice);
    if (pProduct->m_nType == 7)
    {
        __int64 nRandom = pProduct->FUN_1406a0270();
        CStringW strRandom = FUN_1418fec00(nCurrency, nRandom, false);
        FUN_1409abb60(strRandom, nRandom);
    }
    if (FUN_1409acfe0(pProduct, nOption, nCurrency))
        FUN_1409abcf0(true);
    bool bGift = pProduct->FUN_1406a1c70(0);
    FUN_1409abc90(bGift);
    MS2Ptr<CItemData> spItem = FUN_14053f870(pProduct->m_nItemId);
    if (spItem.get() != 0)
    {
        CStringW strOption = FUN_140ebd520(pProduct, nOption);
        FUN_1407cbb20("selectedOption", strOption);
    }
    FUN_1409abcd0(nCurrency);
    FUN_1409b0430(nOption);
    bool bPoint = FUN_1406a5930() && pProduct->FUN_14069ff00();
    if (bPoint)
    {
        FUN_1409b0450(true);
        FUN_1409abd40(0xf);
        __int64 nPoint = pProduct->GetPointOf(nOption);
        CStringW strPoint = FUN_140ec05f0(pProduct);
        FUN_1409ad9c0(*this, strPoint, nPoint);
    }
}
MS2_REPLACE_METHOD(0x1409AC6F0, ASMeratMarketBuyBillData, FUN_1409ac6f0, 769, 0x871ECC57);

// @0x1409aca00
void ASMeratMarketBuyBillData::FUN_1409aca00(CMeratMarketPremiumProduct* pOption, MS2Ptr<CMeratMarketProduct> spProduct)
{
    SetProduct(spProduct);
    FUN_1409aba80(pOption->GetName());
    CStringW strOption = FUN_140ebd870(pOption);
    FUN_1407cbb20("selectedOption", strOption);
    {
        CStringW strEmpty(L"");
        FUN_1409abad0(strEmpty, 0);
    }
    FUN_1409b0430(pOption->m_nId);
}
MS2_REPLACE_METHOD(0x1409ACA00, ASMeratMarketBuyBillData, FUN_1409aca00, 330, 0x02AA3BC7);

// @0x1409acb50
int ASMeratMarketBuyBillData::FUN_1409acb50()
{
    Scaleform::GFx::Value vData = FUN_1409ac0b0();
    if (vData.IsUndefined() || vData.IsNull())
        return m_n78;
    return FUN_1409ada50(vData);
}
MS2_REPLACE_METHOD(0x1409ACB50, ASMeratMarketBuyBillData, FUN_1409acb50, 129, 0x83D2A031);

// @0x1409acbe0
int ASMeratMarketBuyBillData::FUN_1409acbe0(int nCurrency)
{
    int nPayType = 0x11;
    if (nCurrency == 3)
        nPayType = m_n44;
    else
        nPayType = FUN_14069c3e0(nCurrency);
    return nPayType;
}
MS2_REPLACE_METHOD(0x1409ACBE0, ASMeratMarketBuyBillData, FUN_1409acbe0, 64, 0xD4BFF5FE);

// @0x1409acc30
int ASMeratMarketBuyBillData::vfunc_1()
{
    if (m_spPremium.get() != 0)
        return m_spPremium->m_nItemId;
    if (m_spProduct.get() != 0)
        return m_spProduct->GetItemId();
    return 0;
}
MS2_REPLACE_METHOD(0x1409ACC30, ASMeratMarketBuyBillData, vfunc_1, 116, 0xE748005E);

// @0x1409accb0
__int64 ASMeratMarketBuyBillData::vfunc_6()
{
    Scaleform::GFx::Value vData = FUN_1409ac0b0();
    if (!vData.IsUndefined())
    {
        ASObj data(vData, 2);
        return FUN_1409adb70("starPoint", &data);
    }
    return FUN_1409adb70("starPoint", this);
}
MS2_REPLACE_METHOD(0x1409ACCB0, ASMeratMarketBuyBillData, vfunc_6, 251, 0xAC39F239);

// @0x1409acdc0
__int64 ASMeratMarketBuyBillData::vfunc_7()
{
    Scaleform::GFx::Value vData = FUN_1409ac190();
    if (!vData.IsUndefined())
    {
        ASObj data(vData, 2);
        return FUN_1409adb70("starPoint", &data);
    }
    return FUN_1409adb70("starPoint", this);
}
MS2_REPLACE_METHOD(0x1409ACDC0, ASMeratMarketBuyBillData, vfunc_7, 251, 0x7F30790C);

// @0x1409aced0
__int64 ASMeratMarketBuyBillData::vfunc_9()
{
    Scaleform::GFx::Value vData = FUN_1409ac0b0();
    if (!vData.IsUndefined())
    {
        ASObj data(vData, 2);
        return FUN_1409adb70("randomPaybackPrice", &data);
    }
    return FUN_1409adb70("randomPaybackPrice", this);
}
MS2_REPLACE_METHOD(0x1409ACED0, ASMeratMarketBuyBillData, vfunc_9, 251, 0x99716318);

// The option drop down of a premium product: the product itself, then its sub products in their option order.
// @0x1409acfe0
bool ASBillData::FUN_1409acfe0(CMeratMarketPremiumProduct* pProduct, int nOption, int nCurrency)
{
    CStringW strUnused;
    CRBMap<int, MS2Ptr<CDBPremiumProduct> >& mapSub = pProduct->m_mapSub;
    if (mapSub.IsEmpty())
        return false;
    ASArray arrOptions(2);
    bool bDay = pProduct->FUN_14069fe40() == 2;
    CDBPremiumProduct* pBase = pProduct;
    int nSelected = 0;
    FUN_1409ad420(arrOptions, nCurrency, pProduct, bDay, pBase);
    int nIndex = 1;
    std::vector<MS2Ptr<CDBPremiumProduct> > vecSub;
    for (POSITION pos = mapSub.GetHeadPosition(); pos != NULL; mapSub.GetNext(pos))
    {
        MS2Ptr<CDBPremiumProduct> spSub = mapSub.GetValueAt(pos);
        if (spSub == 0)
            continue;
        vecSub.push_back(spSub);
    }
    std::sort(vecSub.begin(), vecSub.end(), Unk_PremiumOptionLess(bDay));
    for (size_t i = 0; i < vecSub.size(); ++i, ++nIndex)
    {
        MS2Ptr<CDBPremiumProduct> spSub = vecSub.at(i);
        if (spSub == 0)
            continue;
        int nId = spSub->m_nId;
        if (nId == nOption)
            nSelected = nIndex;
        FUN_1409ad420(arrOptions, nCurrency, spSub.get(), bDay, pBase);
    }
    FUN_1407cb9c0("selectedOptionIndex", nSelected);
    FUN_1409abc40(arrOptions.FUN_1422bb870());
    return true;
}
MS2_REPLACE_METHOD(0x1409ACFE0, ASBillData, FUN_1409acfe0, 876, 0x736BBBD2);

// @0x1409ad360
bool ASMeratMarketBuyBillData::FUN_1409ad360(MS2Ptr<CMeratMarketProduct> spProduct, int nOption, int nCurrency)
{
    if ((bool)spProduct.get() && spProduct->IsPremium())
        return FUN_1409acfe0(&spProduct->m_premium, nOption, nCurrency);
    return false;
}
MS2_REPLACE_METHOD(0x1409AD360, ASMeratMarketBuyBillData, FUN_1409ad360, 174, 0x47C46A7A);

static void FUN_1409ad7b0(ASObj& obj, const CStringW& strSale);
static void FUN_1409ad800(ASObj& obj, const CStringW& strLabel);
static void FUN_1409ad850(ASObj& obj, const CStringW& strPrice, __int64 nPrice);
static void FUN_1409ad8e0(ASObj& obj, const CStringW& strPrice, __int64 nPrice);
static void FUN_1409ad970(ASObj& obj, const unsigned& nMarketSN);

// One row of the option drop down.
// @0x1409ad420
void ASBillData::FUN_1409ad420(ASArray& arr, int nCurrency, CDBPremiumProduct* pSub, bool bDay, CDBPremiumProduct* pBase)
{
    int nBaseId = pBase != NULL ? pBase->m_nId : pSub->m_nId;
    CStringW strLabel = FUN_140ebd020(bDay, pSub);
    CStringW strSale;
    __int64 nSalePrice = pSub->GetSalePrice(pBase);
    __int64 nPrice = pSub->m_nPrice;
    CStringW strPrice;
    if (nPrice > nSalePrice && 0 < nPrice)
    {
        CStringW strFormat = FUN_14028b8e0(L"s_meratmarket_bill_sale_off");
        int nPercent = (int)((nPrice - nSalePrice) * 100 / nPrice);
        if (0 < nPercent)
        {
            strSale = StringFormat((const wchar_t*)strFormat, nPercent);
            strPrice = FUN_1409404f0(nPrice);
        }
    }
    CStringW strSalePrice = FUN_1418fec00(nCurrency, nSalePrice, false);
    __int64 nPoint = pSub->GetPoint();
    CStringW strPoint = FUN_140ec05f0(pSub);
    ASObj row(2);
    FUN_1409ad800(row, strLabel);
    FUN_1409ad7b0(row, strSale);
    FUN_1409ad850(row, strSalePrice, nSalePrice);
    FUN_1409ad8e0(row, strPrice, nPrice);
    FUN_1409ad9c0(row, strPoint, nPoint);
    unsigned nMarketSN = 0;
    if (nBaseId != pSub->m_nId)
        nMarketSN = pSub->m_nId;
    FUN_1409ad970(row, nMarketSN);
    arr.FUN_1422bc050(row.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x1409AD420, ASBillData, FUN_1409ad420, 903, 0xADC38BEA);

// @0x1409ad7b0
static void FUN_1409ad7b0(ASObj& obj, const CStringW& strSale)
{
    obj.FUN_1407cbb20("saleText", strSale);
}

// @0x1409ad800
static void FUN_1409ad800(ASObj& obj, const CStringW& strLabel)
{
    obj.FUN_1407cbb20("label", strLabel);
}

// @0x1409ad850
static void FUN_1409ad850(ASObj& obj, const CStringW& strPrice, __int64 nPrice)
{
    obj.FUN_1407cbb20("strSalePrice", strPrice);
    obj.FUN_1407cba60("salePrice", FUN_1407194b0(nPrice));
}

// @0x1409ad8e0
static void FUN_1409ad8e0(ASObj& obj, const CStringW& strPrice, __int64 nPrice)
{
    obj.FUN_1407cbb20("strPrice", strPrice);
    obj.FUN_1407cba60("price", FUN_1407194b0(nPrice));
}

// @0x1409ad970
static void FUN_1409ad970(ASObj& obj, const unsigned& nMarketSN)
{
    obj.FUN_1407cba60("marketSN", FUN_140719190(nMarketSN));
}

// @0x1409ad9c0
void FUN_1409ad9c0(ASObj& obj, const CStringW& strPoint, __int64 nPoint)
{
    obj.FUN_1407cbb20("strStarPoint", strPoint);
    obj.FUN_1407cba60("starPoint", FUN_1407194b0(nPoint));
}
MS2_REPLACE(0x1409AD9C0, FUN_1409ad9c0, 129, 0xE44F0A15);

// The "marketSN" of a row object (0 without one).
// @0x1409ada50
int FUN_1409ada50(const Scaleform::GFx::Value& vData)
{
    if (vData.IsUndefined())
        return 0;
    ASObj data(vData, 2);
    CString strValue;
    data.FUN_1422bac00("marketSN", strValue);
    return FUN_140718170(strValue);
}
MS2_REPLACE(0x1409ADA50, FUN_1409ada50, 152, 0xDC2CABB0);

// @0x1409adb70
__int64 ASMeratMarketBuyBillData::FUN_1409adb70(const CString& strName, ASObj* pData)
{
    CString strValue;
    pData->FUN_1422bac00(strName, strValue);
    return FUN_1407182f0(strValue);
}

// @0x1409adbe0
void ASObj::FUN_1409adbe0(const char* szName, Scaleform::GFx::Value v)
{
    ASData data;
    data.FUN_1422b83f0(v);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409adc90
void ASObj::FUN_1409adc90(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x1409b03d0
void ASMeratMarketBuyBillData::FUN_1409b03d0(unsigned __int64 n)
{
    m_n58 = n;
}

// @0x1409b03f0
void ASMeratMarketBuyBillData::SetProduct(MS2Ptr<CMeratMarketProduct> spProduct)
{
    m_spProduct = spProduct;
}

// @0x1409b0430
void ASMeratMarketBuyBillData::FUN_1409b0430(int n)
{
    m_n78 = n;
}

// @0x1409b0450
void ASMeratMarketBuyBillData::FUN_1409b0450(bool b)
{
    m_b70 = b;
}

// The key as text: "P_<premium id>", "U_<ugc id>" or "0_0".
// @0x1409b0470
CStringW Unk_MeratProductKey::FUN_1409b0470() const
{
    CStringW strKey(L"");
    if (m_nPremiumId > 0)
        strKey = StringFormat(L"P_{0}", m_nPremiumId);
    else if (m_nUgcId > 0)
        strKey = StringFormat(L"U_{0}", m_nUgcId);
    else
        strKey = L"0_0";
    return strKey;
}

// MS2-PIN: ??_GASBillData@@UEAAPEAXI@Z 0x1409b0290
