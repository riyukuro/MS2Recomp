// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Merat market UI helpers (UIMeratMarketCommon / UIMeratMarketDialogUtil).
// MS2-UNIT: ?\uimeratmarketcommon.cpp
// MS2-RANGE: 0x1400dc300-0x1400dc420 .text$di
// MS2-RANGE: 0x140ebb6c0-0x140ec41e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VASMeratMarketBuyBillData@@@@QEAA@AEBV0@@Z 0x140ec3350 ; prop
// MS2-PIN: ??C?$MS2Ptr@VASArray@@@@QEBAPEAVASArray@@XZ 0x140ec3660 ; unique
// MS2-PIN: ??_GASClickOutData@UIMeratMarketDialogUtil@@UEAAPEAXI@Z 0x140ec36b0 ; unique
// MS2-PIN: ??_GASOutData@UIMeratMarketDialogUtil@@UEAAPEAXI@Z 0x140ec36f0 ; unique
// MS2-PIN: ??_GWeaponType@UIMeratMarketCommon@@UEAAPEAXI@Z 0x140ec3730 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VASMeratMarketBuyBillData@@@@V?$CElementTraits@V?$MS2Ptr@VASMeratMarketBuyBillData@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VASMeratMarketBuyBillData@@@@@Z 0x140ec3770 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$CAtlArray@V?$MS2Ptr@VASMeratMarketBuyBillData@@@@V?$CElementTraits@V?$MS2Ptr@VASMeratMarketBuyBillData@@@@@ATL@@@ATL@@QEAA@XZ 0x140ec3460 ; merge-bind
// MS2-PIN: ??1?$MS2Ptr@VASArray@@@@QEAA@XZ 0x140ec34d0 ; merge-bind
// MS2-PIN: ??4?$MS2Ptr@VASMeratMarketProductBase@@@@QEAAAEAV0@AEBV0@@Z 0x140ec3520 ; merge-bind
// MS2-PIN: ?Reference@?$MS2Ptr@VASArray@@@@CAXPEAVASArray@@@Z 0x140ec3f20 ; merge-bind
// MS2-PIN: ?Release@?$MS2Ptr@VASArray@@@@AEAAXXZ 0x140ec3fe0 ; merge-bind
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VASArray@@@@AEAAXPEAX@Z 0x140ec4070 ; merge-bind
// MS2-PIN: ??0?$MS2Ptr@VCUserReportData@@@@QEAA@AEBV0@@Z 0x140ec33f0 ; merge-bind
// MS2-PIN: ??0?$MS2Ptr@VCUserReportData@@@@QEAA@PEAVCUserReportData@@@Z 0x140ec3430 ; merge-bind
// MS2-PIN: ?AddRef@?$MS2Ptr@VCUserReportData@@@@AEBAXXZ 0x140ec3ed0 ; merge-bind
// MS2-PIN: ?AddRefImpl@?$MS2Ptr@VCUserReportData@@@@AEBAXPEAX@Z 0x140ec3f70 ; merge-bind
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimeratmarketcommon.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "asclickoutdata.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uimeratmarketweapontype.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
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


// The click data of a product button (UIMeratMarketDialogUtil), see asclickoutdata.h.
void* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(void* pWorld);
int FUN_140ec2ab0();
int* FUN_1401d7c10(void* pValue);
AScript& FUN_1409edaf0(AScript& dst, const AScript& src);          // AScript::operator=
int FUN_140ec04b0(CMeratMarketPremiumProduct* pProduct);

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
UIMeratMarketCommon::WeaponType::WeaponType(PC* pOwner)
    : m_n18(0), m_n1c(0)
{
    FUN_140ebb730(pOwner);
}

// @0x140ec3500
UIMeratMarketCommon::WeaponType::~WeaponType()
{
}

// @0x140ebb730
bool UIMeratMarketCommon::WeaponType::FUN_140ebb730(PC* pOwner)
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
    return spData->limit.FUN_140545da0(nJob) && spData->FUN_14053c940(nGender);
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
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/ms2clientplatformbase.h"

struct Unk_McOid                                            // the AS form of a market product key
{
    CStringW FUN_1409b0470() const;
    int m_nPremiumId;
    __int64 m_nUgcId;
};
class Unk_McMarket { public: int FUN_140d56160(); };
Unk_McMarket* FUN_140939a00();
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);
class Unk_McUi { public: void FUN_141add210(); void FUN_141adc530(int nUiId); };
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
    if (FUN_1418ff110(FUN_14069c3e0(nPayType), nPrice, 1) != 0)
        return true;
    return false;
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
        // exe reads the ids through the CAtlArray<UINT>::GetAt instance (0x1401c0c80)
        int nItemId = reinterpret_cast<ATL::CAtlArray<unsigned int>&>(arrItemIds).GetAt(i);
        if (nItemId == 0)
            continue;
        MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
        if (spData == 0)
            continue;
        int nTab = FUN_140ec2ac0(spData);
        if (0 <= nTab && nTab < 15)
            counts.SetAt(nTab, counts.GetAt(nTab) + 1);
    }
    for (int nTab = 0; nTab < 15; ++nTab)
    {
        int nNeed = counts.GetAt(nTab);
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
    CDBPremiumProduct* pText = 0;
    if (nSubId == 0)
        pText = pProduct;
    else
        pText = pProduct->GetSubProduct(nSubId).operator->();
    if (pText != 0)
        strResult = FUN_140ebd020(bDay, pText);
    return strResult;
}

// @0x140ebd520
CStringW FUN_140ebd520(CMeratMarketPremiumProduct* pProduct, int nSubId)
{
    CStringW strResult;
    if (pProduct->HasSubProducts() != 0)
        strResult = FUN_140ebced0(pProduct, nSubId);
    else
    {
        MS2Ptr<CItemData> spData = FUN_14053f870(pProduct->m_nItemId);
        if (spData == 0 || !(1 < *(unsigned*)((char*)spData.operator->() + 0x88)))
            return strResult;
        int nBonus = pProduct->GetB8(0);
        CStringW strFormat = nBonus == 0 ? FUN_14028b8e0(CStringW(L"s_common_count")) : FUN_14028b8e0(CStringW(L"s_common_count_bonus"));
        int nCount = pProduct->GetB0(0);
        strResult = FUN_14083dc40(strFormat, nCount, nBonus);
    }
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

// ---- the buy / tooltip callbacks of the bill dialog ----
class Unk_McMan                                             // CMeratMarketMan (placeholder/cmeratmarketman.h): members not recovered
{
public:
    void FUN_140d59810(MS2Ptr<CPendingBuyBase> spBuy, int nSourceKind);
    void FUN_140d58650(int nSourceKind);
};
bool FUN_140d5b1f0(Unk_McMan* pMan, MS2Ptr<CMeratMarketProduct> spProduct, int n);
void FUN_140d60dd0(CMeratMarketBuy* pBuy, const CStringW& strA, const CStringW& strB);   // the strings by reference
int FUN_140ec3950(ASMeratMarketBuyBillData* pBill);
void FUN_1409e3190(AScript* pTip, CMeratMarketPremiumProduct* pProduct, int n);
void FUN_1409b4bc0(Scaleform::GFx::Value* pOut, Scaleform::GFx::Value& v);
int FUN_1409c1750(const Scaleform::GFx::Value& v);
int FUN_14069c3e0(int nPayType);
void* FUN_140b09580(int nId);
void FUN_140899a40(MS2Ptr<CPtred>* pDst, MS2Ptr<CMeratMarketProduct> spProduct);
void FUN_1409ab990(ASMeratMarketBuyBillData* pBill, MS2Ptr<CItemData> spData, int nGrade);
void FUN_1409aca00(ASMeratMarketBuyBillData* pBill, const void* pKey, MS2Ptr<CMeratMarketProduct> spProduct);
const void* FUN_1409b0140(MS2Ptr<CDBPremiumProduct>& spSub);
bool FUN_1406a5930();
void FUN_140e6ff60(ATL::CAtlArray<MS2Ptr<ASBillData> >& arr, MS2Ptr<ASBillData> sp);
void FUN_140ea7770(void* pDialog, MS2Ptr<TMarketBillDataParam> spParam);

// The buy callback of the merat market bill dialog: one buy request per bill row, answered by the server.
// MS2-FUNCTIONAL: not byte-matched (unrecovered callee signatures, temporaries)
// @0x140ebded0
bool FUN_140ebded0(MS2Ptr<TMarketBillDataParam> spBase, const TMarketBillDataParam::PaymentMap& mapPay)
{
    if (spBase == 0)
        return false;
    TMeratMarketBillDataParam* pParam = dynamic_cast<TMeratMarketBillDataParam*>(spBase.get());
    if (pParam == 0)
        return false;
    if (pParam->m_bills.GetCount() == 0)
        return false;
    if (pParam->m_spF8 != 0)
    {
        MS2Ptr<CMeratMarketProduct> spProduct = *(MS2Ptr<CMeratMarketProduct>*)&pParam->m_spF8;
        CMsTime tNow((__time64_t)FUN_140869440());
        CMeratMarketPremiumProduct& prem = spProduct->m_premium;
        __int64 nRemain = 0;
        if (prem.m_time188 > tNow)
            nRemain = (prem.m_time188 - tNow).GetTotalSeconds();
        COutPacket pkt(0x39, 0);
        pkt.vfunc_o10_1(0x70);
        pkt.vfunc_o10_3(prem.m_n2c);
        pkt.vfunc_o10_1((char)prem.m_n16c);
        pkt.vfunc_o10_1((char)prem.m_n170);
        pkt.vfunc_o10_3(prem.GetRemainCount());
        pkt.vfunc_o10_4(nRemain);
        pkt.vfunc_o10_4(prem.m_nSalePrice);
        FUN_140710590(pkt);
    }
    if (pParam->m_sp108 != 0)
    {
        MS2Ptr<CMeratMarketProduct> spProduct = *(MS2Ptr<CMeratMarketProduct>*)&pParam->m_sp108;
        CMeratMarketPremiumProduct& prem = spProduct->m_premium;
        if (prem.FUN_1406a0090())
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_meratmarket_error_random_expired")), 1, 1);
            return false;
        }
        COutPacket pkt(0x39, 0);
        pkt.vfunc_o10_1(0x74);
        pkt.vfunc_o10_3(prem.m_nId);
        pkt.vfunc_o10_3(prem.m_n1b0);
        pkt.vfunc_o10_3(prem.m_nType == 7 ? 0xd68 : 0xd72);
        FUN_140710590(pkt);
    }
    if (!FUN_140ebc590(mapPay))
        return false;
    ATL::CAtlArray<int> arrIds;
    FUN_1409abfa0(arrIds, pParam->m_bills);
    if (!FUN_140ebcc20(arrIds))
        return false;
    int nSrc = FUN_140ec3900(pParam);
    int nShop = pParam->m_nShopId;
    Unk_McMan* pMan = (Unk_McMan*)FUN_140939a00();
    if (!spBase->FUN_140eacfc0())
    {
        size_t nCount = pParam->m_bills.GetCount();
        for (size_t i = 0; i < nCount; ++i)
        {
            MS2Ptr<ASMeratMarketBuyBillData> spBill = dynamic_cast<ASMeratMarketBuyBillData*>(pParam->m_bills[i].get());
            if (spBill == 0)
                continue;
            MS2Ptr<CMeratMarketBuy> spBuy = new CMeratMarketBuy();
            FUN_140d604c0(spBuy.get(), spBill, nSrc, 1);
            spBuy->FUN_140d60d60((int)i, (int)nCount);
            FUN_140d60ea0(spBuy.get(), &nShop);
            pMan->FUN_140d59810(MS2Ptr<CPendingBuyBase>(spBuy.get()), nSrc);
        }
    }
    else
    {
        MS2Ptr<CMeratMarketBuy> spBuy = new CMeratMarketBuy();
        FUN_140d60a80(spBuy.get(), *(MS2Ptr<CMeratMarketProduct>*)&pParam->m_spE8, nSrc, pParam->m_nCurrency, 1);
        spBuy->FUN_140d60d60(0, 1);
        FUN_140d60ea0(spBuy.get(), &nShop);
        pMan->FUN_140d59810(MS2Ptr<CPendingBuyBase>(spBuy.get()), nSrc);
    }
    pMan->FUN_140d58650(nSrc);
    return true;
}

// The tooltip of a bill row.
// MS2-FUNCTIONAL: not byte-matched (temporaries / EH state layout)
// @0x140ebe990
bool FUN_140ebe990(Scaleform::GFx::Value* pOut, ASData& data, MS2Ptr<TMarketBillDataParam> spParam)
{
    if (spParam == 0)
        return false;
    if (FUN_140939a00() == 0)
        return false;
    Scaleform::GFx::Value valRow = data.FUN_1422b9260();
    ASObj objRow(valRow, 2);
    if (objRow.FUN_1422ba9a0())
        return false;
    int nIndex = data.FUN_1422b8b10();
    MS2Ptr<ASBillData> spBill = spParam->FUN_140eaba00(nIndex);
    if (spBill == 0)
        return false;
    MS2Ptr<ASMeratMarketBuyBillData> spBuy = dynamic_cast<ASMeratMarketBuyBillData*>(spBill.get());
    if (spBuy == 0)
        return false;
    MS2Ptr<CMeratMarketProduct> spProduct = spBuy->FUN_140a8e4e0();
    if (spProduct == 0)
        return false;
    ASTooltip tip(4, 2);
    if (spProduct->IsPremium() == 0 || spProduct->m_premium.m_nType != 3)
    {
        MS2Ptr<CItem> spItem = FUN_140ebc070(spProduct.get());
        if (spItem != 0)
            FUN_140ebbb30(&tip, spItem, spProduct, false, true);
    }
    else
    {
        int nSub = FUN_140ec3950(spBuy.get());
        if (nSub == 0)
            FUN_1409e3190(&tip, &spProduct->m_premium, 0);
        else
        {
            MS2Ptr<CDBPremiumProduct> spSub = spProduct->m_premium.GetLimitProduct(nSub);
            if (spSub != 0)
            {
                MS2Ptr<CItem> spItem = FUN_140ebc360(spSub->m_nItemId, spSub->m_nGrade);
                if (spItem != 0)
                    FUN_140ebbb30(&tip, spItem, spProduct, true, false);
            }
        }
    }
    FUN_1409b4bc0(pOut, tip.FUN_1422bb870());
    return true;
}

// The gift / basket buy callback: one buy request per marked bill row.
// MS2-FUNCTIONAL: not byte-matched (unrecovered callee signatures, temporaries)
// @0x140ebef60
bool FUN_140ebef60(MS2Ptr<TMarketBillDataParam> spBase, const TMarketBillDataParam::PaymentMap& mapPay, const CStringW& strA,
                   const CStringW& strB)
{
    if (spBase == 0)
        return false;
    TMeratMarketBillDataParam* pParam = dynamic_cast<TMeratMarketBillDataParam*>(spBase.get());
    if (pParam == 0)
        return false;
    if (pParam->m_bills.GetCount() == 0)
        return false;
    if (!FUN_140ebc590(mapPay))
        return false;
    int nSrc = FUN_140ec3900(pParam);
    int nShop = pParam->m_nShopId;
    ATL::CAtlArray<MS2Ptr<ASMeratMarketBuyBillData> > arrBuy;
    for (size_t i = 0; i < pParam->m_bills.GetCount(); ++i)
    {
        MS2Ptr<ASMeratMarketBuyBillData> spBill = dynamic_cast<ASMeratMarketBuyBillData*>(pParam->m_bills[i].get());
        if (spBill != 0 && spBill->m_b40)
            arrBuy.Add(spBill);
    }
    Unk_McMan* pMan = (Unk_McMan*)FUN_140939a00();
    size_t nCount = arrBuy.GetCount();
    for (size_t i = 0; i < nCount; ++i)
    {
        MS2Ptr<CMeratMarketBuy> spBuy = new CMeratMarketBuy();
        FUN_140d604c0(spBuy.get(), arrBuy[i], nSrc, 1);
        spBuy->FUN_140d60d60((int)i, (int)nCount);
        FUN_140d60dd0(spBuy.get(), strA, strB);
        FUN_140d60ea0(spBuy.get(), &nShop);
        pMan->FUN_140d59810(MS2Ptr<CPendingBuyBase>(spBuy.get()), nSrc);
    }
    pMan->FUN_140d58650(nSrc);
    return true;
}

// The price type of a product row (3 = currency chosen by the row).
// @0x140ebf520
int FUN_140ebf520(MS2Ptr<CMeratMarketProduct> spProduct, AScript* pRow)
{
    if (spProduct == 0)
        return 0;
    int nType = spProduct->GetCurrency();
    if (nType == 3)
    {
        if (!pRow->FUN_1422ba9a0())
            nType = FUN_1409c1750(pRow->FUN_1422baa20("priceType"));
        else
            nType = 1;
    }
    return nType;
}

// Open the bill dialog for a limited product.
// MS2-FUNCTIONAL: not byte-matched (unrecovered callee signatures, temporaries)
// @0x140ebf610
void FUN_140ebf610(MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<TMeratMarketBillDataParam> spParam, int nPayType)
{
    if (spProduct == 0 || spParam == 0)
        return;
    if (!FUN_140d5b1f0((Unk_McMan*)FUN_140939a00(), spProduct, 1))
        return;
    CMeratMarketPremiumProduct* pPrem = &spProduct->m_premium;
    int nCur = FUN_14069c3e0(nPayType);
    __int64 nPrice = spProduct->GetSalePrice();
    if (!FUN_1418ff110(nCur, nPrice, 1))
        return;
    void* pDialog = FUN_140b09580(0x4f17);
    if (pDialog == 0)
        return;
    spParam->m_b2c = false;
    spParam->FUN_140eab9a0(nPrice);
    if (FUN_1406a5930() && pPrem->FUN_14069ff00())
        spParam->FUN_140eab9d0(0xf, spProduct->GetPoint());
    spParam->m_nCurrency = nCur;
    FUN_140899a40(&spParam->m_spE8, spProduct);
    for (POSITION pos = pPrem->m_mapSub.GetHeadPosition(); pos != 0; )
    {
        MS2Ptr<CDBPremiumProduct> spSub = pPrem->m_mapSub.GetNextValue(pos);
        if (spSub == 0)
            continue;
        MS2Ptr<ASMeratMarketBuyBillData> spBill = new ASMeratMarketBuyBillData();
        if (spBill == 0)
            return;
        FUN_1409ab990(spBill.get(), FUN_14053f870(spSub->m_nItemId), spSub->m_nGrade);
        FUN_1409aca00(spBill.get(), FUN_1409b0140(spSub), spProduct);
        FUN_140e6ff60(spParam->m_bills, MS2Ptr<ASBillData>(spBill.get()));
    }
    MS2Ptr<TMeratMarketBillDataParam> spShow(spParam);
    FUN_140ea7770(pDialog, MS2Ptr<TMarketBillDataParam>(spShow));
    ((Unk_McUi*)FUN_1403ed2b0())->FUN_141adc530(0x4f17);
}

// ---- purchase condition checks ----
class Unk_McPayback { public: void FUN_1408981a0(CRBMap<__int64, int>& map); };
extern Unk_McPayback* DAT_143ab22a8;
Unk_McPayback* FUN_140ec3940();
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_1418fec00(int nType, __int64 nAmount, int n);
CStringW FUN_140bfa7f0(CStringW strKey, const CStringW& strArg);
int FUN_1407cccd0(const Scaleform::GFx::Value* pValue);
bool FUN_140ebb1e0(const Scaleform::GFx::Value* pValue);
class Unk_McAchieveMgr;
Unk_McAchieveMgr* FUN_1406c7600();
int FUN_140936900(Unk_McAchieveMgr* pMgr, int nAchieve, int nGrade);
class Unk_McAchieve : public CPtred { public: void* FUN_1409393c0(); };
void FUN_140935e60(Unk_McAchieveMgr* pMgr, MS2Ptr<Unk_McAchieve>* pOut, int nId);
__int64 FUN_140159040(void* pTable, int nGrade);
CStringW FUN_14093b9c0(int nAchieve, int nGrade);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
__int64 FUN_140166410();
unsigned short FUN_14036db20(__int64 p);
CStringW FUN_140ec01e0(CDBPremiumProduct* pProduct, const CStringW& strKey);
CStringW FUN_14061ad70(const CStringW& strKey, const wchar_t* szSuffix);
CStringW FUN_1409e8820(CStringW strFormat, const short& n);
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
unsigned char FUN_141658f10(PCBase* pPlayer);
int FUN_141654700(PCBase* pPlayer);
int FUN_1406a59f0(CDBPremiumProduct* pProduct, int nJob);
void FUN_140222a70(int nMask, ATL::CAtlArray<int>& out);
int FUN_140644bb0(void* p, int nJob);
void* FUN_1401d7a50();
CStringW FUN_141811980(CStringTable* pTable, int nType, int nId);
Unk_McAchieveMgr* FUN_1406c7600();

// The achievement the product requires.
// @0x140ebfb90
bool FUN_140ebfb90(CDBPremiumProduct* pProduct, bool bShowError)
{
    int nAchieve = pProduct->m_nf8;
    if (nAchieve == 0)
        return true;
    int nGrade = pProduct->m_nfc;
    if (FUN_140936900(FUN_1406c7600(), nAchieve, nGrade) != 0)
        return true;
    if (bShowError)
        FUN_1412751f0(FUN_14052bd00(0x5c, FUN_14093b9c0(nAchieve, nGrade)), 1, 1);
    return false;
}

// The player level against the buy limit of the product.
// @0x140ebfc70
bool FUN_140ebfc70(unsigned short nLevel, CDBPremiumProduct* pProduct, bool bShowError)
{
    if (nLevel == 0)
        return true;
    if (pProduct->m_n94 == 0 && pProduct->m_n96 == 0)
        return true;
    unsigned short nMin = pProduct->m_n94;
    unsigned short nMax = pProduct->m_n96;
    if (nMin == 0)
        nMin = 1;
    if (nMax == 0)
        nMax = FUN_14036db20(FUN_140166410());
    if (nLevel < nMin || nMax < nLevel)
    {
        if (bShowError)
            FUN_1412751f0(FUN_140ec01e0(pProduct, CStringW(L"s_meratmarket_error_buy_limit_")), 1, 1);
        return false;
    }
    return true;
}

// The level check against the local player.
// @0x140ebfdd0
bool FUN_140ebfdd0(CDBPremiumProduct* pProduct, bool bShowError)
{
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return true;
    unsigned short nLevel = (unsigned short)pPlayer->vfunc_78();
    return FUN_140ebfc70(nLevel, pProduct, bShowError);
}

// The PC bang level of the product.
// @0x140ebfe30
bool FUN_140ebfe30(CDBPremiumProduct* pProduct, bool bShowError)
{
    if (pProduct->FUN_14069fee0() == 0)
        return true;
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0)
    {
        unsigned char nLevel = FUN_141658f10(pPlayer);
        if (nLevel == 0)
        {
            if (bShowError)
                FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_meratmarket_error_buy_not_pcbang")), 1, 1);
            return false;
        }
        if ((int)nLevel < pProduct->FUN_14069fee0())
        {
            if (bShowError)
                FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_meratmarket_error_buy_low_pcbang_level")), 1, 1);
            return false;
        }
    }
    return true;
}

// The job limit of the product.
// MS2-FUNCTIONAL: not byte-matched (temporaries / EH state layout)
// @0x140ebff70
bool FUN_140ebff70(CDBPremiumProduct* pProduct, bool bShowError)
{
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return false;
    int nResult = FUN_1406a59f0(pProduct, FUN_141654700(pPlayer));
    if (!bShowError || nResult != 0xb5)
        return nResult == 0;
    CStringW strSep(L", ");
    CStringW strJobs;
    ATL::CAtlArray<int> arrJobs;
    FUN_140222a70(pProduct->m_n98, arrJobs);
    for (size_t i = 0; i < arrJobs.GetCount(); ++i)
    {
        int nName = FUN_140644bb0(FUN_1401d7a50(), arrJobs[i]);
        CStringW strName = FUN_141811980(FUN_1401a9d70(), 6, nName);
        if (strName.IsEmpty())
            continue;
        if (!strJobs.IsEmpty())
            strJobs.Append(strSep);
        strJobs.Append(strName);
    }
    FUN_1412751f0(FUN_1405c2690(CStringW(L"s_meratmarket_error_buy_limit_job_detail"), strJobs), 1, 1);
    return false;
}

// The level limit text of a product.
// MS2-FUNCTIONAL: not byte-matched (temporaries / EH state layout)
// @0x140ec01e0
CStringW FUN_140ec01e0(CDBPremiumProduct* pProduct, const CStringW& strKey)
{
    CStringW strResult;
    short nMin = pProduct->m_n94;
    short nMax = pProduct->m_n96;
    if (nMin == 0 || nMax == 0)
    {
        if (nMin == 0)
            strResult = FUN_1409e8820(FUN_14061ad70(strKey, L"level_max"), nMax);
        else
            strResult = FUN_1409e8820(FUN_14061ad70(strKey, L"level_min"), nMin);
    }
    else if (nMin == nMax)
        strResult = FUN_1409e8820(FUN_14061ad70(strKey, L"level_only"), nMin);
    else
        strResult = FUN_14028dfa0(FUN_14061ad70(strKey, L"level_range"), (unsigned short)nMin, (unsigned short)nMax);
    return strResult;
}

// The achievement requirement state: 0 ok, 0xb0 no achievement, 0xb1 not achieved, 0xb2 expired.
// MS2-FUNCTIONAL: not byte-matched (unrecovered callee signatures)
// @0x140ec04b0
int FUN_140ec04b0(CMeratMarketPremiumProduct* pProduct)
{
    if (pProduct->m_nf8 == 0)
        return 0;
    int nAchieve = pProduct->m_nf8;
    int nGrade = pProduct->m_nfc;
    MS2Ptr<Unk_McAchieve> spAchieve;
    FUN_140935e60(FUN_1406c7600(), &spAchieve, nAchieve);
    if (spAchieve == 0)
        return 0xb0;
    __int64 nTime = FUN_140159040(spAchieve->FUN_1409393c0(), nGrade);
    if (nTime == 0)
        return 0xb1;
    if (0 < pProduct->m_n100)
    {
        if (nTime + pProduct->m_n100 < FUN_140869440())
            return 0xb2;
    }
    return 0;
}

// ---- sort drop downs, UGC checks and the bill dialog start ----
CStringW FUN_140c160b0(CStringW strFormat, const __int64& nValue);
void FUN_140d73ff0(CStringW strText);
void FUN_140d73bc0(int nId, int a, int b, CStringW strTag);
void FUN_141275260(int nStringId, int a, int b);
int FUN_140896350(CUgcMarketProduct* pUgc);
void SendRequestCubeMode66(void* pBlueprint);
struct Unk_McTimeKey { __int64 a; __int64 b; __int64 c; __int64 d; };
extern int DAT_143ab2820;
bool FUN_140896230(CUgcMarketProduct* pUgc, Unk_McTimeKey* pKey);
class Unk_McBlindMan { public: bool FUN_140a8bcc0(MS2Ptr<CMeratMarketProduct> spProduct); };
Unk_McBlindMan* FUN_1409c1740();
void FUN_1409ab940(ASMeratMarketBuyBillData* pBill, __int64 n);
void FUN_1409b03d0(ASMeratMarketBuyBillData* pBill, __int64 n);
void FUN_1409ac360(ASMeratMarketBuyBillData* pBill, MS2Ptr<CMeratMarketProduct> spProduct, int n, int nCur);
bool FUN_140ebc630(MS2Ptr<CMeratMarketProduct> spProduct, int nPayType);
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
void FUN_140ec07b0(ASArray* pArr, const CStringW& strLabel, int nSort, bool bUgc);
void FUN_140ec0990(ASArray* pArr, int nTab);
int FUN_1406ab1d0(CMeratMarketProduct* pProduct);
int FUN_1406a4370(CMeratMarketProduct* pProduct);
bool FUN_1406a0cc0(CMeratMarketPremiumProduct* pProduct);

// The payback table text of the tooltip: one row per charge step, the step holding the current amount is marked.
// MS2-FUNCTIONAL: not byte-matched (temporaries / EH state layout)
// @0x140ebd9d0
CStringW FUN_140ebd9d0(bool bSelect, __int64 nCur)
{
    CRBMap<__int64, int> mapPayback(10);
    FUN_140ec3940()->FUN_1408981a0(mapPayback);
    if (mapPayback.IsEmpty())
        return CStringW(L"");
    CStringW strResult;
    CStringW strRowFormat;
    POSITION posNext = mapPayback.GetHeadPosition();
    while (posNext != 0)
    {
        POSITION pos = posNext;
        mapPayback.GetNext(posNext);
        __int64 nStep = mapPayback.GetKeyAt(pos) + 1;
        int nPercent = 100 - mapPayback.GetValueAt(pos);
        if (!strResult.IsEmpty())
            strResult.Append(L"\n");
        if (pos == mapPayback.GetTailPosition())
        {
            CStringW strRow = FUN_140bfa7f0(CStringW(L"s_meratmarket_tooltip_table_charge_row_max"), FUN_1418fec00(3, nStep, 0));
            if (!bSelect || nCur < nStep)
                strResult.Append(strRow);
            else
                strResult.Append(FUN_1405c2690(CStringW(L"s_meratmarket_tooltip_table_charge_select"), strRow));
        }
        else
        {
            if (strRowFormat.IsEmpty())
                strRowFormat = FUN_14028b8e0(CStringW(L"s_meratmarket_tooltip_table_charge_row"));
            __int64 nNextStep = mapPayback.GetKeyAt(posNext);
            CStringW strRow = StringFormat((const wchar_t*)strRowFormat, FUN_1409404f0(nStep), FUN_1418fec00(3, nNextStep, 0), nPercent);
            if (!bSelect || nCur < nStep || nNextStep <= nCur)
                strResult.Append(strRow);
            else
                strResult.Append(FUN_1405c2690(CStringW(L"s_meratmarket_tooltip_table_charge_select"), strRow));
        }
    }
    return strResult;
}

// The star point text of a product.
// @0x140ec05f0
CStringW FUN_140ec05f0(CMeratMarketPremiumProduct* pProduct)
{
    if (!FUN_1406a5930())
        return CStringW(L"");
    if (!pProduct->FUN_14069ff00())
        return CStringW(L"");
    __int64 nPoint = pProduct->GetPoint();
    CStringW strText = FUN_140c160b0(CStringW(L"s_meratmarket_text_add_star_point"), nPoint);
    return strText;
}
MS2_REPLACE(0x140EC05F0, FUN_140ec05f0, 258, 0x533F6FAB);

// The data provider as this unit creates it (ctor 0x1422deec0, dtor 0x1422df070: a second copy of ASDataProvider's).
class Unk_McDataProvider : public ASArray
{
public:
    Unk_McDataProvider(int nType);
    virtual ~Unk_McDataProvider();
};

// Fill the sort drop down of a tab.
// @0x140ec0700
void FUN_140ec0700(ASObj* pDialog, int nTab)
{
    Unk_McDataProvider dp(2);
    FUN_140ec0990(&dp, nTab);
    pDialog->FUN_1409adbe0("dpDropDownSort", dp.FUN_1422bb870());
    pDialog->FUN_1407cb9c0("dpDropDownSortSelectedIndex", 0);
}

// One entry of the sort drop down.
// @0x140ec07b0
void FUN_140ec07b0(ASArray* pArr, const CStringW& strLabel, int nSort, bool bUgc)
{
    ASObj obj(2);
    obj.FUN_1407cbb20("label", strLabel);
    obj.FUN_140ec3230("sortValue", nSort);
    if (bUgc)
    {
        CString strName;
        unsigned nOpt = 2;
        if (nSort == 4)
            strName = "createtime";
        else if (nSort == 1)
        {
            strName = "saleCount";
            nOpt |= 0x10;
        }
        else if (nSort == 6)
        {
            strName = "saleCountTotal";
            nOpt |= 0x10;
        }
        obj.FUN_1407cba60("sortDataName", strName);
        obj.FUN_1409c0d20("sortOpt", nOpt);
    }
    pArr->FUN_1422bc050(obj.FUN_1422bb870());
}

// The entries of the sort drop down: tab 0 = premium products, tab 1 = UGC products.
// @0x140ec0990
void FUN_140ec0990(ASArray* pArr, int nTab)
{
    if (nTab == 0)
    {
        FUN_140ec07b0(pArr, CStringW(L"$s_meratmarket_dropdown_premium_sort_chartorder"), 5, false);
        FUN_140ec07b0(pArr, CStringW(L"$s_meratmarket_dropdown_premium_sort_price_low"), 2, false);
        FUN_140ec07b0(pArr, CStringW(L"$s_meratmarket_dropdown_premium_sort_price_high"), 3, false);
        FUN_140ec07b0(pArr, CStringW(L"$s_meratmarket_dropdown_premium_sort_create"), 4, false);
    }
    else if (nTab == 1)
    {
        FUN_140ec07b0(pArr, CStringW(L"$s_meratmarket_dropdown_ugc_sort_create"), 4, true);
        FUN_140ec07b0(pArr, CStringW(L"$s_meratmarket_dropdown_ugc_sort_buy"), 1, true);
        FUN_140ec07b0(pArr, CStringW(L"$s_meratmarket_dropdown_ugc_sort_buy_total"), 6, true);
    }
}

// Open the blueprint of an UGC product.
// @0x140ec0b50
void FUN_140ec0b50(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0 || FUN_1406ab1d0(spProduct.operator->()) == 0)
        return;
    if (FUN_140896350(&spProduct->m_ugc) == 0)
    {
        FUN_140d73ff0(CStringW(L"s_meratmarket_error_ugc_calculate_invalid_blueprint_item"));
        return;
    }
    void** ppBlueprint = (void**)((char*)spProduct.operator->() + 0x418);
    if (*ppBlueprint == 0)
    {
        FUN_140d73ff0(CStringW(L"s_meratmarket_error_ugc_calculate_invalid_blueprint_item"));
        return;
    }
    SendRequestCubeMode66(ppBlueprint);
}

// Open the bill dialog for a single product after the checks.
// MS2-FUNCTIONAL: not byte-matched (unrecovered callee signatures, temporaries)
// @0x140ec0c70
void FUN_140ec0c70(const CStringA& strMovie, MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<TMeratMarketBillDataParam> spParam, __int64 n4, __int64 n5, int nPayType)
{
    if (spProduct == 0)
        return;
    if (FUN_1406ab1d0(spProduct.get()) == 0)
    {
        if (FUN_1406a4370(spProduct.get()) != 0 && FUN_1406a0cc0(&spProduct->m_premium))
        {
            FUN_141275260(0xa17, 1, 1);
            return;
        }
    }
    else
    {
        if (spProduct->m_ugc.m_n28 == 4)
        {
            FUN_140d73bc0(0xa15, 0, 0, CStringW(L""));
            return;
        }
        if (spProduct->m_ugc.m_n28 == 3)
        {
            FUN_140d73bc0(0xa0e, 0, 0, CStringW(L""));
            return;
        }
        Unk_McTimeKey key = *(Unk_McTimeKey*)&DAT_143ab2820;
        if (FUN_140896230(&spProduct->m_ugc, &key))
        {
            FUN_140d73bc0(0xa14, 0, 0, CStringW(L""));
            return;
        }
    }
    if (!FUN_140d5b1f0((Unk_McMan*)FUN_140939a00(), spProduct, 1))
        return;
    if (!FUN_140ebc630(spProduct, nPayType))
        return;
    if (FUN_1409c1740()->FUN_140a8bcc0(spProduct) == true)
        return;
    void* pDialog = FUN_140b09580(0x4f17);
    if (pDialog == 0)
        return;
    if (spParam == 0)
        return;
    int nCur = FUN_14069c3e0(nPayType);
    int bUgc = FUN_1406ab1d0(spProduct.get());
    MS2Ptr<ASMeratMarketBuyBillData> spBill = new ASMeratMarketBuyBillData();
    FUN_1409ab940(spBill.get(), n4);
    FUN_1409b03d0(spBill.get(), n5);
    FUN_1409ac360(spBill.get(), spProduct, 0, nCur);
    FUN_140e6ff60(spParam->m_bills, MS2Ptr<ASBillData>(spBill.get()));
    spParam->FUN_140eab940(spBill->FUN_140eacf60());
    spParam->SetGift(bUgc != 0);
    MS2Ptr<TMeratMarketBillDataParam> spShow(spParam);
    FUN_140ea7770(pDialog, MS2Ptr<TMarketBillDataParam>(spShow));
    ((Unk_McUi*)FUN_1403ed2b0())->FUN_141adc530(0x4f17);
}

// ---- user report, category lookups, texts ----
class Unk_McCategoryEntry : public CPtred { public: MS2Ptr<CPtred> m_sp18; };
CStringW FUN_14016a730(const char* sz, int n);
void FUN_1409c1640(void* pId, CStringW str);
__int64 FUN_140718350(const CString& str);
bool FUN_141b70f50(const CStringW& strA, const CStringW& strB);
MS2Ptr<CMeratMarketProduct> FUN_140d57150(Unk_McMarket* pMan, const Unk_MeratProductKey& key, int n);
MS2Ptr<CMeratMarketProduct> FUN_140d57d80(Unk_McMarket* pMan, const Unk_MeratProductKey& key);
MS2Ptr<CMeratMarketProduct> FUN_140d57f70(Unk_McMarket* pMan, const Unk_MeratProductKey& key);
MS2Ptr<CMeratMarketProduct> FUN_140d576a0(Unk_McMarket* pMan, const Unk_MeratProductKey& key);
int FUN_140896310(CUgcMarketProduct* pUgc);
int FUN_140d5a2e0(Unk_McMarket* pMan);
__int64 FUN_140d5a1d0(Unk_McMarket* pMan);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_140a228f0(int nId, const int& nMonth, const CStringW& strArg);
CStringW FUN_14028de60(int nId);
void FUN_141b70f90(const CMsTime& tm, const CStringW& strFormat, CStringW& strOut);
CString FUN_140719210(int n);
void FUN_1409c23e0(ASObj* pRow, int n);
void FUN_1409c2750(ASObj* pRow, const CString& str);
void FUN_1409c3860(ASObj* pRow, CItem* pItem, int n, int nId);
void FUN_140692c90(MS2Ptr<CItem>& sp, MS2Ptr<CItem> spNew);
Unk_McMarket* FUN_140939a00();
class Unk_McCategoryTable
{
public:
    MS2Ptr<CPtred> FUN_1407cb520(int nCategory, int nTab);   // CShopCategoryTable::FindTab
};
Unk_McCategoryTable* FUN_1406aa4b0();
CItemData* FUN_140527840(CItem* pItem);
bool FUN_141b49b50(MS2Ptr<CItemData> spData);
class Unk_McSortTabInfo : public CPtred { public: char m_pad[0x78 - 0x18]; bool m_b78; bool m_b79; };   // CShopCategoryTable::SortTabInfo

// File a user report about the seller from the market (data: report id, target id, reason, name).
// MS2-FUNCTIONAL: not byte-matched (unrecovered callee signatures, temporaries)
// @0x140ec1340
void FUN_140ec1340(ASData& data)
{
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    Unk_ReportId id;
    FUN_1409c1640(&id, FUN_14016a730(data.FUN_1422b8d30(), 0));
    __int64 nTarget = FUN_140718350(data.FUN_1422b8d30());
    CStringW strReason = data.FUN_1422b8f40();
    CStringW strName = data.FUN_1422b8f40();
    if (FUN_141b70f50(pPlayer->vfunc_77(), strName))
    {
        FUN_141275260(0x8ae, 1, 1);
        return;
    }
    MS2Ptr<CUserReportData> spReport = new CUserReportData(3);
    spReport->SetField28(3);
    spReport->m_id.Copy(id);
    spReport->SetField60(nTarget);
    spReport->SetField38(strReason);
    spReport->SetTitle(strName);
    spReport->SetFieldb0(strName);
    spReport->SetFieldd8(nTarget);
    spReport->SetFieldb8(strReason);
    if (MS2Ptr<CMeratMarketProduct> spProduct = FUN_140d57150(FUN_140939a00(), *(Unk_MeratProductKey*)&id, 0))
    {
        spReport->SetFielda0(*(__int64*)((char*)spProduct.get() + 0x318));
        spReport->SetFielda8(*(__int64*)((char*)spProduct.get() + 0x320));
        spReport->SetFieldc0(*(__int64*)((char*)spProduct.get() + 0x350));
        spReport->SetFieldc8(*(CStringA*)((char*)spProduct.get() + 0x390));
        spReport->m_n110 = FUN_140896310(&spProduct->m_ugc);
    }
    FUN_140d86260()->vfunc_48(spReport);
}

// The item class of an item as a report/category code.
// @0x140ec1950
int FUN_140ec1950(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return 0;
    MS2Ptr<CItemData> spData = FUN_140527840(spItem.operator->());
    if (spData == 0)
        return 0;
    if (FUN_141b49b50(spData))
        return 0x79;
    if (spData->FUN_14053ce40())
        return 0x7b;
    if (spData->FUN_14053cb40())
        return 0x7b;
    if (spData->FUN_14053cd50())
        return 0x7b;
    if (spData->FUN_14053cb80())
        return 0x7f;
    if (spData->FUN_14053cc80())
        return 0x7b;
    if (spData->FUN_14053cd10())
        return 0x7c;
    if (spData->FUN_14053d900())
        return 0x7d;
    return 0;
}

// The index of the category entry with this tab id, or -1.
// @0x140ec1c70
int FUN_140ec1c70(ATL::CAtlArray<MS2Ptr<Unk_McCategoryEntry> >& arrEntries, int nTabId)
{
    int nCount = (int)arrEntries.GetCount();
    for (int i = 0; i < nCount; ++i)
    {
        MS2Ptr<Unk_McCategoryEntry> spEntry = arrEntries[i];
        if (spEntry == 0)
            continue;
        MS2Ptr<CPtred> spTab = spEntry->m_sp18;
        if (spTab == 0)
            continue;
        if (*(int*)((char*)spTab.get() + 0x3c) == nTabId)
            return i;
    }
    return -1;
}

// The sort flags of a category tab.
// @0x140ec1da0
void FUN_140ec1da0(int nCategory, int nTab, bool* pbSortA, bool* pbSortB)
{
    *pbSortA = false;
    *pbSortB = false;
    if (nCategory == 0)
        return;
    MS2Ptr<CPtred> spTab = FUN_1406aa4b0()->FUN_1407cb520(nCategory, nTab);
    if (spTab == 0)
        return;
    MS2Ptr<Unk_McSortTabInfo> spSort(dynamic_cast<Unk_McSortTabInfo*>(spTab.operator->()));
    if (spSort == 0)
        return;
    *pbSortA = spSort->m_b78;
    *pbSortB = spSort->m_b79;
}

// Round down to a whole hundred.
// @0x140ec1ee0
int FUN_140ec1ee0(int nValue)
{
    int nResult = 0;
    if (nValue != 0)
        nResult = nValue - nValue % 100;
    return nResult;
}

// The month text of the sale period.
// @0x140ec1f20
CStringW FUN_140ec1f20()
{
    if (FUN_140d5a2e0(FUN_140939a00()) != 0)
    {
        CMsTime tNow((__time64_t)FUN_140869440());
        int nMonth = tNow.GetMonth();
        __int64 nArg = FUN_140d5a1d0(FUN_140939a00());
        return FUN_140a228f0(0xa24, nMonth, FUN_1409404f0(nArg));
    }
    return CStringW(L"");
}

// @0x140ec2010
CStringW FUN_140ec2010()
{
    if (FUN_140d5a2e0(FUN_140939a00()) == 0)
        return CStringW(L"");
    return FUN_14052bd00(0xa25, FUN_1409404f0(FUN_140d5a1d0(FUN_140939a00())));
}

// The product row of the click out data: icon, name and ids.
// MS2-FUNCTIONAL: not byte-matched (unrecovered callee signatures, temporaries)
// @0x140ec20d0
bool FUN_140ec20d0(ASObj* pRow, MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItem> spItem, int nParam)
{
    if (spProduct == 0)
        return false;
    if (spProduct->GetType() == 3)
    {
        CStringA strIcon = spProduct->m_premium.GetIconPath();
        FUN_1409c23e0(pRow, spProduct->m_premium.GetGrade());
        FUN_1409c2750(pRow, strIcon);
    }
    else
    {
        if (spItem == 0)
            FUN_140692c90(spItem, FUN_140ebc070(spProduct.get()));
        FUN_1409c3860(pRow, spItem.get(), nParam, 0xd01);
    }
    pRow->FUN_1407cba60("itemID", FUN_140719210(spProduct->GetItemId()));
    pRow->FUN_1407cbb20("productOID", ((Unk_McOid*)&spProduct->m_key)->FUN_1409b0470());
    return true;
}

// Find a product by the key kind: 1 = by id, 2, 3 and 4 = the other lookups, else the generic lookup.
// @0x140ec2300
MS2Ptr<CMeratMarketProduct> FUN_140ec2300(const Unk_MeratProductKey& key, int* pnKind, int nParam)
{
    MS2Ptr<CMeratMarketProduct> spProduct(0);
    Unk_McMarket* pMan;
    switch (*pnKind)
    {
    case 1:
        spProduct = FUN_140d57d80(FUN_140939a00(), key);
        break;
    case 2:
        spProduct = FUN_140d57d80(FUN_140939a00(), key);
        break;
    case 3:
        spProduct = FUN_140d57f70(FUN_140939a00(), key);
        break;
    case 4:
        spProduct = FUN_140d576a0(FUN_140939a00(), key);
        break;
    }
    pMan = FUN_140939a00();
    if (spProduct == 0)
        spProduct = FUN_140d57150(pMan, key, nParam);
    return spProduct;
}

// The sale end time text.
// @0x140ec25e0
CStringW FUN_140ec25e0(__int64 nTime)
{
    CMsTime tm(nTime);
    CStringW strOut;
    FUN_141b70f90(tm, FUN_14028de60(0xa28), strOut);
    return strOut;
}

// ---- the click data of the product buttons ----
// @0x140ec2690
UIMeratMarketDialogUtil::ASOutData::ASOutData(Scaleform::GFx::Value& v, int nMovieId)
    : AScript(v, nMovieId)
{
    {
        Scaleform::GFx::Value valData = FUN_1422baa20("data");
        m_spProduct = ASMeratMarketProductBase::FUN_1409bbc30(valData, nMovieId);
    }
    Scaleform::GFx::Value valRenderer = FUN_1422baa20("renderer");
    m_spRenderer.AssignRaw(new AScript(valRenderer, nMovieId));
}

// @0x140ec2860
UIMeratMarketDialogUtil::ASOutData::~ASOutData()
{
}

// @0x140ec28b0
MS2Ptr<ASMeratMarketProductBase> UIMeratMarketDialogUtil::ASOutData::FUN_140ec28b0()
{
    return m_spProduct;
}

// @0x140ec2900
MS2Ptr<AScript> UIMeratMarketDialogUtil::ASOutData::FUN_140ec2900()
{
    return m_spRenderer;
}

// @0x140ec2950
UIMeratMarketDialogUtil::ASClickOutData::ASClickOutData(Scaleform::GFx::Value& v, int nMovieId)
    : ASOutData(v, nMovieId), m_buyBtnData(2)
{
    Scaleform::GFx::Value valBtn = FUN_1422baa20("buyBtnData");
    AScript tmp(valBtn, nMovieId);
    FUN_1409edaf0(m_buyBtnData, tmp);
}

// @0x140ec2a50
UIMeratMarketDialogUtil::ASClickOutData::~ASClickOutData()
{
}

// @0x140ec2a90
AScript* UIMeratMarketDialogUtil::ASClickOutData::FUN_140ec2a90()
{
    return &m_buyBtnData;
}

// @0x140ec2ab0
int FUN_140ec2ab0()
{
    return 4;
}

// @0x140ec3940
Unk_McPayback* FUN_140ec3940()
{
    return DAT_143ab22a8;
}

// @0x140ec3b50
bool FUN_140ec3b50(const Scaleform::GFx::Value* pValue)
{
    return FUN_1407cccd0(pValue) == 5;
}

// @0x140ec3bf0
bool FUN_140ec3bf0(const Scaleform::GFx::Value* pValue)
{
    return FUN_1407cccd0(pValue) == 4;
}

// @0x140ec3b90
bool FUN_140ec3b90(const Scaleform::GFx::Value* pValue)
{
    if (!FUN_140ebb1e0(pValue) && !FUN_140ec3bf0(pValue) && !FUN_140ec3b50(pValue))
        return false;
    return true;
}

// The inventory tab of an item.
// @0x140ec2ac0
int FUN_140ec2ac0(MS2Ptr<CItemData> spData)
{
    return DAT_143ab2a90.FUN_140a61870(spData);
}

// @0x140ec2b60
int FUN_140ec2b60(void* pValue)
{
    return *FUN_1401d7c10(pValue);
}

// @0x140ec3230
void ASObj::FUN_140ec3230(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140ec3560
void FUN_140ec3560(AScript* pDst, ASTooltip* pSrc)
{
    FUN_1409edaf0(*pDst, *pSrc);
    *(__int64*)((char*)pDst + 0x40) = *(__int64*)((char*)pSrc + 0x40);
    *(int*)((char*)pDst + 0x48) = *(int*)((char*)pSrc + 0x48);
    *(CStringW*)((char*)pDst + 0x50) = *(CStringW*)((char*)pSrc + 0x50);
}

// @0x140ec3900
int FUN_140ec3900(TMeratMarketBillDataParam* pParam)
{
    return pParam->m_nSourceKind;
}

// @0x140ec3950
int FUN_140ec3950(ASMeratMarketBuyBillData* pBill)
{
    return pBill->m_n78;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca82a0-0x142ca8310 .text$yd
