// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Merat market UI helpers (UIMeratMarketCommon / UIMeratMarketDialogUtil).
// MS2-UNIT: ?\uimeratmarketcommon.cpp
// MS2-RANGE: 0x1400dc300-0x1400dc420 .text$di
// MS2-RANGE: 0x140ebb6c0-0x140ec41e0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimeratmarketcommon.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "asclickoutdata.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- header statics (the shared list of the merat market units) ----
#ifndef MS2_HOOK_DLL
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill = "skill";
static CString s_stun = "stun";
#endif

// ---- unit-local declarations ----
class PCBase;

namespace UIMeratMarketCommon {

// The weapon filter of the market tabs: two weapon categories (0 = none, then the job/gender filter applies).
class WeaponType : public CPtred
{
public:
    WeaponType();                                           // 0x140ebb6c0
    virtual ~WeaponType();                                  // ??_G 0x140ec3730
    virtual void vfunc_1() = 0;                             // _purecall in the exe vftable
    void FUN_140ebb750();                                   // reset the filter
    bool FUN_140ebb780(int nGender, int nJob, MS2Ptr<CItemData> spData);

    int m_n18;
    int m_n1c;
};
MS2_CHECK_SIZE(WeaponType, 0x20);

}   // namespace UIMeratMarketCommon

// The click data of a product button (UIMeratMarketDialogUtil), see asclickoutdata.h.
void* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(void* pWorld);
int FUN_140ec2ab0();
int FUN_140ec04b0(CMeratMarketPremiumProduct* pProduct);
bool FUN_140ebb730();

CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_1408116a0(int nId, const int& nArg);
CStringW FUN_14083dc40(const wchar_t* szFormat, const int& a, const int& b);
CStringW FUN_14093bd40(int nAchieve, int nGrade, CStringW strDefault);
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
bool FUN_1418ff110(int nType, __int64 nValue, int n);
void FUN_1418ff710(int nCurrency, __int64 nAmount, int nItemId, int nOpt);
int FUN_1406a6140();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
class Unk_McBlind { public: bool FUN_140a259b0(int nKind, __int64 nId); };
Unk_McBlind* FUN_1409c1730();

// @0x140ebb6c0
UIMeratMarketCommon::WeaponType::WeaponType()
    : m_n18(0), m_n1c(0)
{
}

// @0x140ebb730
bool FUN_140ebb730()
{
    return true;
}

// @0x140ebb750
void UIMeratMarketCommon::WeaponType::FUN_140ebb750()
{
    m_n18 = 0;
    m_n1c = 0;
}

// @0x140ebb780
bool UIMeratMarketCommon::WeaponType::FUN_140ebb780(int nGender, int nJob, MS2Ptr<CItemData> spData)
{
    if (spData == 0)
        return false;
    if (m_n18 != 0 || m_n1c != 0)
    {
        bool bRet = false;
        if (0 < m_n18)
            bRet = spData->FUN_14053cae0(nGender, m_n18) == 1;
        if (0 < m_n1c)
            bRet = bRet | (spData->FUN_14053cae0(nGender, m_n1c) == 1);
        return bRet;
    }
    if (spData->limit.FUN_140545da0(nJob) && spData->FUN_14053c940(nGender))
        return true;
    return false;
}

// ---- more unit-local declarations ----
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/client/ms2/cmeratmarketbuy.h"
#include "ms2/client/ms2/tmeratmarketbilldataparam.h"
#include "ms2/placeholder/asmeratmarketbuybilldata.h"
#include "inventory.h"
#include "ms2/commonfiles/ugcdef.h"
#include "ms2/placeholder/iclientplatform.h"

struct Unk_McOid                                            // the AS form of a market product key
{
    CStringW FUN_1409b0470() const;
    int m_nPremiumId;
    __int64 m_nUgcId;
};
class Unk_McMarket { public: int FUN_140d56160(); };
Unk_McMarket* FUN_140939a00();
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
class Unk_McUi { public: void FUN_141add210(); };
Unk_McUi* FUN_1403ed2b0();
IClientPlatform* FUN_140d86260();
void FUN_1406327c0(CItemCustomMusicScore* pScore, const CUgcItemMusicNote* pNote);   // CItemCustomMusicScore::FUN_1406327c0
class Unk_McConfig;
Unk_McConfig* FUN_1401d3200();
int FUN_140ec2b60(void* pValue);
__int64 FUN_14028d0e0();
void FUN_140892da0(CUgcItemLook* pDest, const CUgcItemLook* pSource);
extern Unk_Inventory DAT_143ab2a90;
CStringTable* FUN_1401a9d70();
int FUN_140ec2ac0(MS2Ptr<CItemData> spData);
MS2Ptr<CItem> FUN_140ebc360(int nItemId, int nGrade);
CStringW FUN_14093fa20(int nStringId, const CStringW& strName, const int& nCount);
int FUN_1409c17e0(const Scaleform::GFx::Value& v);
CStringW FUN_141277dd0(const Scaleform::GFx::Value* pValue);
int FUN_140718200(CStringW* text);
bool FUN_140ec3b90(const Scaleform::GFx::Value* pValue);
void FUN_140ebaf70(Scaleform::GFx::Value& arr, unsigned nIndex, Scaleform::GFx::Value& out);
void FUN_141349210(MS2Ptr<CItem> spItem, Scaleform::GFx::Value& root, bool b, ASTooltip* pLhs, ASTooltip* pRhs);
void FUN_140ec3560(AScript* pDst, ASTooltip* pSrc);
void FUN_1409de020(AScript* pTip, CMeratMarketPremiumProduct* pProduct);
void FUN_1409ddc40(AScript* pTip, CMeratMarketProduct* pProduct);
CStringW FUN_140ebd020(bool bDay, CDBPremiumProduct* pProduct);

// @0x140ebb920
bool FUN_140ebb920(ASObj* pRow, MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0)
        return false;
    if (FUN_141bd0cc0(FUN_1403ed2d0()) == 0)
        return false;
    pRow->FUN_1407cbb20("productOID", ((Unk_McOid*)&spProduct->m_key)->FUN_1409b0470());
    bool bSoldOut = false;
    if (spProduct->IsUgc() == 0)
    {
        bSoldOut = spProduct->m_premium.IsBuyLimitReached();
    }
    else
    {
        pRow->FUN_1407cb9c0("saleState", spProduct->m_ugc.m_n28);
        pRow->FUN_1407cbb20("tooltipSellcount", FUN_1408116a0(0x9dc, spProduct->m_ugc.m_n44));
        if (FUN_1409c1730()->FUN_140a259b0(3, spProduct->m_ugc.m_n20))
            pRow->FUN_1407cbbe0("isBlind", true);
    }
    pRow->FUN_1407cbbe0("soldOut", bSoldOut);
    return true;
}

// The product tooltip: the item tooltip (or, in the second mode, the plain item tooltip) and the right hand side line.
// MS2-FUNCTIONAL: not byte-matched (temporaries / EH state layout)
// @0x140ebbb30
int FUN_140ebbb30(ASTooltip* pTip, MS2Ptr<CItem> spItem, MS2Ptr<CMeratMarketProduct> spProduct, bool bPlain, bool bNoCompare)
{
    if (spItem == 0)
        return 0;
    if (!bPlain)
    {
        PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
        int nType = FUN_140ec2ab0();
        ASTooltip tipLhs(pPlayer, nType, 2);
        ASTooltip tipRhs(pPlayer, nType, 2);
        if (spProduct->IsPremium() != 0)
        {
            if (FUN_140ec04b0(&spProduct->m_premium) != 0)
            {
                CStringW strAchieve = FUN_14093bd40(spProduct->m_premium.m_nf8, spProduct->m_premium.m_nfc, CStringW(L""));
                if (!strAchieve.IsEmpty())
                    tipRhs.FUN_1409dbc30(FUN_1405c2690(CStringW(L"s_shop_tooltip_require_achieve"), strAchieve));
            }
        }
        FUN_141349210(spItem, pTip->FUN_1422bb870(), !bNoCompare, &tipLhs, &tipRhs);
    }
    else
    {
        int nType = FUN_140ec2ab0();
        ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), nType, 2);
        if (tip.FUN_1409e0d40(spItem.get()) != 0)
        {
            ASTooltip tipCopy(tip.FUN_1422bb870(), 2);
            FUN_140ec3560(pTip, &tipCopy);
        }
    }
    if (spProduct->IsUgc() == 0)
    {
        if (spProduct->HasLimit() != 0)
        {
            CMeratMarketPremiumProduct* pPremium = &spProduct->m_premium;
            Scaleform::GFx::Value vRhs = pTip->FUN_1422baa20("rhsTooltip");
            if (FUN_1409b0390(&vRhs) == 0)
            {
                ASTooltip tip(vRhs, 2);
                FUN_1409de020(&tip, pPremium);
            }
            else
                FUN_1409de020(pTip, pPremium);
        }
    }
    else
    {
        Scaleform::GFx::Value vRhs = pTip->FUN_1422baa20("rhsTooltip");
        if (FUN_1409b0390(&vRhs) == 0)
        {
            ASTooltip tip(vRhs, 2);
            FUN_1409ddc40(&tip, spProduct.operator->());
        }
        else
            FUN_1409ddc40(pTip, spProduct.operator->());
    }
    return 1;
}

// The item a product shows (a premium product's item, or a UGC product's blank item with the look filled in).
// @0x140ebc070
MS2Ptr<CItem> FUN_140ebc070(CMeratMarketProduct* pProduct)
{
    if (pProduct->m_nKind == 1)
    {
        int nItemId = pProduct->m_ugc.m_n2c;
        if (pProduct->m_ugc.FUN_140896310() != 0)
            nItemId = FUN_140ec2b60((char*)FUN_1401d3200() + 0x8ff0);
        MS2Ptr<CItem> spItem = FUN_140ebc360(nItemId, pProduct->m_ugc.m_n1f8);
        if (spItem.get() != 0)
        {
            if (pProduct->m_ugc.FUN_140896310() != 0)
            {
                CItemCustomMusicScore* pScore = spItem->FUN_140527990();
                if (pScore != 0)
                    FUN_1406327c0(pScore, &pProduct->m_ugc.m_music);
            }
            Unk_ItemUgcInfo* pUgc = spItem->FUN_1405278d0();
            if (pUgc != 0)
            {
                FUN_140892da0((CUgcItemLook*)((char*)pUgc + 0x18), &pProduct->m_ugc.m_look);
                if (spItem->FUN_140526010() != 0)
                    ((CBlueprintItemData*)((char*)pUgc + 0x80))->CopyFrom(pProduct->m_ugc.m_blueprint);
            }
            return spItem;
        }
    }
    else if (pProduct->m_nKind == 0)
    {
        return FUN_140ebc360(pProduct->m_premium.m_nItemId, pProduct->m_premium.GetGrade());
    }
    return MS2Ptr<CItem>(0);
}

// @0x140ebc2b0
MS2Ptr<CItem> FUN_140ebc2b0(MS2Ptr<CItemData> spData, unsigned __int64 nGrade)
{
    if (spData == 0)
        return MS2Ptr<CItem>(0);
    return FUN_140ebc360(spData->FUN_14053c510(), (int)nGrade);
}

// @0x140ebc360
MS2Ptr<CItem> FUN_140ebc360(int nItemId, int nGrade)
{
    MS2Ptr<CItem> spItem(new CItem);
    if (spItem.get() != 0 && spItem->FUN_14052b130(nItemId, nGrade, 0) != 0)
    {
        spItem->FUN_14052b420(0);
        spItem->FUN_140526a70(FUN_14028d0e0());
        return spItem;
    }
    return MS2Ptr<CItem>(0);
}

// The basket holds at most 100 products.
// @0x140ebc4a0
bool FUN_140ebc4a0()
{
    int nCount = FUN_140939a00()->FUN_140d56160();
    if (nCount >= 100)
    {
        int nMax = 100;
        FUN_140d73aa0(FUN_1408116a0(0xa29, nMax), 0, 0, CStringW(L""));
    }
    return nCount < 100;
}

// @0x140ebc540
bool FUN_140ebc540(__int64 nPrice)
{
    if (FUN_140d86260()->vfunc_40(nPrice) == 0)
    {
        FUN_1403ed2b0()->FUN_141add210();
        return false;
    }
    return true;
}

// ---- payment / capacity checks ----
// The Value<> readers and singletons used by the buy flow.
class Unk_McPendingBuyBase;
typedef TMarketBillDataParam::PaymentMap Unk_McPaymentMap;
void FUN_140d604c0(CMeratMarketBuy* pBuy, MS2Ptr<ASMeratMarketBuyBillData> spBill, int nSourceKind, int n);
void FUN_140d60a80(CMeratMarketBuy* pBuy, MS2Ptr<CMeratMarketProduct> spProduct, int nCount, int nPriceKind, int nFlag);
void FUN_140d60ea0(CMeratMarketBuy* pBuy, const int* pShopId);
void FUN_1409abfa0(ATL::CAtlArray<int>& out, ATL::CAtlArray<MS2Ptr<ASBillData> >& bills);
void FUN_140710590(COutPacket& pkt);
void FUN_1412751f0(const CStringW& strText, int a, int b);
__int64 FUN_140869440();
int FUN_140ec3900(TMeratMarketBillDataParam* pParam);

// Every amount of the payment map must be payable.
// @0x140ebc590
bool FUN_140ebc590(const TMarketBillDataParam::PaymentMap& mapPay)
{
    POSITION pos = mapPay.GetStartPosition();
    while (pos != NULL)
    {
        __int64 nAmount = mapPay.GetValueAt(pos);
        if (nAmount != 0)
        {
            int nType = mapPay.GetKeyAt(pos);
            if (!FUN_1418ff110(nType, nAmount, 1))
                return false;
        }
        mapPay.GetNext(pos);
    }
    return true;
}

// @0x140ebc630
bool FUN_140ebc630(MS2Ptr<CMeratMarketProduct> spProduct, int nPayType)
{
    __int64 nPrice = spProduct->GetSalePrice();
    if (spProduct->IsUgc() != 0 && spProduct->m_ugc.FUN_140896310() != 0)
    {
        int nGrade = FUN_1406a6140();
        IClientPlatform* pPlatform = FUN_140d86260();
        if (pPlatform->vfunc_39(nPrice, nGrade) == 0)
        {
            pPlatform = FUN_140d86260();
            if (pPlatform->vfunc_39(nPrice, -1) == 1)
                FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_meratmarket_buy_fail_music_score_by_merat_grade")), 0, 0, CStringW(L""));
            else
                FUN_1418ff710(FUN_14069c3e0(nPayType), nPrice, 0, 1);
            return false;
        }
        return true;
    }
    return FUN_1418ff110(FUN_14069c3e0(nPayType), nPrice, 1) != 0;
}

// The bag space the items of the bill need (per inventory tab).
// @0x140ebc850
bool FUN_140ebc850(MS2Ptr<ASArray> spItems)
{
    ATL::CAtlArray<int> counts;
    for (int i = 0; i < 15; ++i)
        counts.Add(0);
    Scaleform::GFx::Value& vItems = spItems->FUN_1422bb870();
    unsigned nItems = spItems->FUN_1422bc5d0();
    for (unsigned i = 0; i < nItems; ++i)
    {
        Scaleform::GFx::Value vElem;
        FUN_140ebaf70(vItems, i, vElem);
        ASObj row(vElem, 2);
        Scaleform::GFx::Value vId = row.FUN_1422baa20("itemID");
        int nItemId;
        if (FUN_140ec3b90(&vId) == 0)
        {
            CStringW strId = FUN_141277dd0(&vId);
            nItemId = FUN_140718200(&strId);
        }
        else
            nItemId = FUN_1409c17e0(vId);
        if (nItemId == 0)
            continue;
        int nTab = FUN_140ec2ac0(FUN_14053f870(nItemId));
        if (-1 < nTab && nTab < 15)
            counts[nTab] = counts[nTab] + 1;
    }
    for (int nTab = 0; nTab < 15; ++nTab)
    {
        int nNeed = counts[nTab];
        if (0 < nNeed && DAT_143ab2a90.FUN_140a615d0(nTab) < nNeed)
        {
            FUN_140d73aa0(FUN_14093fa20(0xa01, FUN_1401a9d70()->FUN_141813300(nTab), nNeed), 0, 0, CStringW(L""));
            return false;
        }
    }
    return true;
}

// @0x140ebcc20
bool FUN_140ebcc20(ATL::CAtlArray<int>& arrItemIds)
{
    ATL::CAtlArray<int> counts;
    for (int i = 0; i < 15; ++i)
        counts.Add(0);
    unsigned nItems = (unsigned)arrItemIds.GetCount();
    for (unsigned i = 0; i < nItems; ++i)
    {
        int nItemId = arrItemIds[i];
        if (nItemId != 0)
        {
            MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
            if (spData == 0)
                continue;
            int nTab = FUN_140ec2ac0(spData);
            if (-1 < nTab && nTab < 15)
                counts[nTab] = counts[nTab] + 1;
        }
    }
    for (int nTab = 0; nTab < 15; ++nTab)
    {
        int nNeed = counts[nTab];
        if (0 < nNeed && DAT_143ab2a90.FUN_140a615d0(nTab) < nNeed)
        {
            FUN_140d73aa0(FUN_14093fa20(0xa01, FUN_1401a9d70()->FUN_141813300(nTab), nNeed), 0, 0, CStringW(L""));
            return false;
        }
    }
    return true;
}

// ---- count / day texts ----
// "N pieces (+bonus)" / "N days (+bonus)" of a premium product.
// @0x140ebd020
CStringW FUN_140ebd020(bool bDay, CDBPremiumProduct* pProduct)
{
    CStringW strFormat;
    int nBonus = pProduct->m_nb8;
    if (!bDay)
    {
        if (nBonus == 0)
            strFormat = FUN_14028b8e0(CStringW(L"s_common_count"));
        else
            strFormat = FUN_14028b8e0(CStringW(L"s_common_count_bonus"));
    }
    else
    {
        if (nBonus == 0)
            strFormat = FUN_14028b8e0(CStringW(L"s_common_day"));
        else
            strFormat = FUN_14028b8e0(CStringW(L"s_common_day_bonus"));
    }
    CStringW strResult;
    if (!bDay)
        strResult = FUN_14083dc40(strFormat, pProduct->m_nb0, nBonus);
    else if (pProduct->m_nb4 == 0)
        strResult = FUN_14028b8e0(CStringW(L"s_common_day_limitless"));
    else
        strResult = FUN_14083dc40(strFormat, pProduct->m_nb4, nBonus);
    return strResult;
}

// @0x140ebced0
CStringW FUN_140ebced0(CMeratMarketPremiumProduct* pProduct, int nSubId)
{
    bool bDay = pProduct->FUN_14069fe40() == 2;
    CStringW strResult;
    CDBPremiumProduct* pText = pProduct;
    if (nSubId != 0)
        pText = pProduct->GetSubProduct(nSubId).operator->();
    if (pText != 0)
        strResult = FUN_140ebd020(bDay, pText);
    return strResult;
}

// @0x140ebd520
CStringW FUN_140ebd520(CMeratMarketPremiumProduct* pProduct, int nSubId)
{
    CStringW strResult;
    if (pProduct->HasSubProducts() == 0)
    {
        MS2Ptr<CItemData> spData = FUN_14053f870(pProduct->m_nItemId);
        if (spData == 0 || !(1 < *(unsigned*)((char*)spData.get() + 0x88)))
            return strResult;
        int nBonus = pProduct->GetB8(0);
        CStringW strFormat;
        if (nBonus == 0)
            strFormat = FUN_14028b8e0(CStringW(L"s_common_count"));
        else
            strFormat = FUN_14028b8e0(CStringW(L"s_common_count_bonus"));
        int nCount = pProduct->GetB0(0);
        strResult = FUN_14083dc40(strFormat, nCount, nBonus);
    }
    else
        strResult = FUN_140ebced0(pProduct, nSubId);
    return strResult;
}

// @0x140ebd870
CStringW FUN_140ebd870(CMeratMarketPremiumProduct* pProduct)
{
    CStringW strResult;
    MS2Ptr<CItemData> spData = FUN_14053f870(pProduct->m_nItemId);
    if (spData == 0)
        return strResult;
    if (*(unsigned*)((char*)spData.get() + 0x88) < 2 && pProduct->m_nb4 == 0)
        return strResult;
    return FUN_140ebd020(0 < pProduct->m_nb4, pProduct);
}
