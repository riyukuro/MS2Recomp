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
class WorldService   // C3: member view for the former free stand-ins
{
public:
    void* FUN_141bd0cc0();
    static class WorldService* GetInstance();
};
int FUN_140ec2ab0();
int* FUN_1401d7c10(void* pValue);
AScript& FUN_1409edaf0(AScript& dst, const AScript& src);          // AScript::operator=
int FUN_140ec04b0(CMeratMarketPremiumProduct* pProduct);

CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW FUN_1408116a0(int nId, const int& nArg);
CStringW FUN_14083dc40(const wchar_t* szFormat, const int& a, const int& b);
CStringW FUN_14093bd40(int nAchieve, int nGrade, CStringW strDefault);
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
bool FUN_1418ff110(int nType, __int64 nValue, bool bFlag);
void FUN_1418ff710(int nCurrency, __int64 nAmount, int nItemId, int nOpt);
int FUN_1406a6140();
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
class Unk_McBlind { public: bool FUN_140a259b0(int nKind, __int64 nId); };
class Unk_MeratBlindManager* FUN_1409c1730();   // C3: was FUN_1409c1730

// @0x140ebb6c0
UIMeratMarketCommon::WeaponType::WeaponType(PC* pOwner)
    : m_n18(0), m_n1c(0)
{
    FUN_140ebb730(pOwner);
}

// ~WeaponType (0x140ec3500) is implicit: an explicit empty body keeps a dead vptr store the exe does not have.

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
    if (m_n18 == 0 && m_n1c == 0)
    {
        bool bResult = spData->limit.FUN_140545da0(nJob) && spData->FUN_14053c940(nGender);
        return bResult;
    }
    bool bRet = false;
    if (0 < m_n18)
        bRet = bRet | (spData->FUN_14053cae0(nGender, m_n18) == 1);
    if (0 < m_n1c)
        bRet = bRet | (spData->FUN_14053cae0(nGender, m_n1c) == 1);
    return bRet;
}

// ---- more unit-local declarations ----
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cmeratmarketman.h"
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
#include "ms2/client/ms2/paybackmanagerclient.h"
#include "ms2/placeholder/cugcgetcosttable.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/commonfiles/shopcategorytable.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/asbilldata.h"
#include "ms2/placeholder/cugcitemlook.h"
#include "ms2/client/ms2/uimarketbilldialog.h"

struct Unk_McOid                                            // the AS form of a market product key
{
    CStringW FUN_1409b0470() const;
    int m_nPremiumId;
    __int64 m_nUgcId;
};
class Unk_McMarket : public CMeratMarketMan { };
class Unk_SingletonObj* FUN_140939a00();   // C3: was FUN_140939a00
class Unk_McUi : public CUIService { public: void FUN_141adc530(int nUiId); };
void* FUN_140d86260();   // C3: was FUN_140d86260
class CItemCustomMusicScore   // C3: member view for the former free stand-ins
{
public:
    void FUN_1406327c0(struct Unk_MusicScoreInfo const&);
};
class Unk_McConfig;
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was FUN_1401d3200
int FUN_140ec2b60(void* pValue);
__int64 FUN_14028d0e0();
extern Unk_Inventory g_143ab2a90;
CStringTable* GetStringTable();
int FUN_140ec2ac0(MS2Ptr<CItemData> spData);
MS2Ptr<CItem> FUN_140ebc360(int nItemId, int nGrade);
CStringW FUN_14093fa20(int nStringId, const CStringW& strName, const int& nCount);
CStringW FUN_141277dd0(const Scaleform::GFx::Value* pValue);
int FUN_140718200(const CStringW& str);
bool FUN_140ec3b90(const Scaleform::GFx::Value* pValue);
void FUN_141349210(MS2Ptr<CItem> spItem, Scaleform::GFx::Value& root, bool b, ASTooltip* pLhs, ASTooltip* pRhs);
AScript* FUN_140ec3560(AScript* pDst, ASTooltip* pSrc);
CStringW FUN_140ebd020(bool bDay, CDBPremiumProduct* pProduct);

// @0x140ebb920
bool FUN_140ebb920(ASObj* pRow, MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0)
        return false;
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return false;
    pRow->FUN_1407cbb20("productOID", ((Unk_McOid*)&spProduct->m_key)->FUN_1409b0470());
    bool bSoldOut = false;
    if (spProduct->IsUgc() != 0)
    {
        int nSaleState = spProduct->m_ugc.m_n28;
        pRow->FUN_1407cb9c0("saleState", nSaleState);
        pRow->FUN_1407cbb20("tooltipSellcount", FUN_1408116a0(0x9dc, spProduct->m_ugc.m_n44));
        if (((class Unk_McBlind*)FUN_1409c1730())->FUN_140a259b0(3, spProduct->m_ugc.m_n20))
            pRow->FUN_1407cbbe0("isBlind", true);
    }
    else
    {
        bSoldOut = spProduct->m_premium.IsBuyLimitReached();
    }
    pRow->FUN_1407cbbe0("soldOut", bSoldOut);
    return true;
}

// The product tooltip: the item tooltip (or, in the second mode, the plain item tooltip) and the right hand side line.
// @0x140ebbb30
int FUN_140ebbb30(ASTooltip* pTip, MS2Ptr<CItem> spItem, MS2Ptr<CMeratMarketProduct> spProduct, bool bPlain, bool bNoCompare)
{
    if (spItem == 0)
        return 0;
    if (bPlain)
    {
        ASTooltip tip(((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0()), FUN_140ec2ab0(), 2);
        if (tip.FUN_1409e0d40(spItem.get()) != 0)
        {
            ASTooltip tipCopy(tip.FUN_1422bb870(), 2);
            FUN_140ec3560(pTip, &tipCopy);
        }
    }
    else
    {
        PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
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
    if (spProduct->IsUgc() != 0)
    {
        Scaleform::GFx::Value vRhs = pTip->FUN_1422baa20("rhsTooltip");
        if (vRhs.IsUndefined() == 0)
        {
            ASTooltip tip(vRhs, 2);
            ((ASTooltip*)&tip)->FUN_1409ddc40(spProduct.get());
        }
        else
            ((ASTooltip*)pTip)->FUN_1409ddc40(spProduct.get());
    }
    else
    {
        if (spProduct->HasLimit() != 0)
        {
            CMeratMarketPremiumProduct* pPremium = &spProduct->m_premium;
            Scaleform::GFx::Value vRhs = pTip->FUN_1422baa20("rhsTooltip");
            if (vRhs.IsUndefined() == 0)
            {
                ASTooltip tip(vRhs, 2);
                ((ASTooltip*)&tip)->FUN_1409de020(pPremium);
            }
            else
                ((ASTooltip*)pTip)->FUN_1409de020(pPremium);
        }
    }
    return 1;
}

// The item a product shows (a premium product's item, or a UGC product's blank item with the look filled in).
// @0x140ebc070
MS2Ptr<CItem> FUN_140ebc070(CMeratMarketProduct* pProduct)
{
    if (pProduct->m_nKind == 1)
    {
        auto& ugc = pProduct->m_ugc;
        int nItemId = ugc.m_n2c;
        if (ugc.FUN_140896310() != 0)
            nItemId = FUN_140ec2b60((char*)((class Unk_McConfig*)FUN_1401d3200()) + 0x8ff0);
        MS2Ptr<CItem> spItem = FUN_140ebc360(nItemId, ugc.m_n1f8);
        if (spItem.get() != 0)
        {
            if (pProduct->m_ugc.FUN_140896310() != 0)
            {
                CItemCustomMusicScore* pScore = spItem->FUN_140527990();
                if (pScore != 0)
                    ((class CItemCustomMusicScore*)(class CItemCustomMusicScore*)(pScore))->FUN_1406327c0(*(struct Unk_MusicScoreInfo const*)(&ugc.m_music));
            }
            Unk_ItemUgcInfo* pUgc = spItem->FUN_1405278d0();
            if (pUgc != 0)
            {
                ((CUgcItemLook*)((char*)pUgc + 0x18))->CopyFrom(&ugc.m_look);
                if (spItem->FUN_140526010() != 0)
                    ((CBlueprintItemData*)((char*)pUgc + 0x80))->CopyFrom(ugc.m_blueprint);
            }
            return spItem;
        }
    }
    else if (pProduct->m_nKind == 0)
    {
        auto& premium = pProduct->m_premium;
        int nPremiumItemId = premium.m_nItemId;
        int nGrade = premium.GetGrade();
        return FUN_140ebc360(nPremiumItemId, nGrade);
    }
    return MS2Ptr<CItem>(0);
}

// @0x140ebc2b0
MS2Ptr<CItem> FUN_140ebc2b0(MS2Ptr<CItemData> spData, int nGrade)
{
    if (spData == 0)
        return MS2Ptr<CItem>(0);
    int nItemId = spData->FUN_14053c510();
    return FUN_140ebc360(nItemId, nGrade);
}

// @0x140ebc360
MS2Ptr<CItem> FUN_140ebc360(int nItemId, int nGrade)
{
    {
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem.get() != 0 && spItem->FUN_14052b130(nItemId, nGrade, 0) != 0)
        {
            spItem->FUN_14052b420(0);
            spItem->FUN_140526a70(FUN_14028d0e0());
            return spItem;
        }
    }
    return MS2Ptr<CItem>(0);
}

// The basket holds at most 100 products.
// @0x140ebc4a0
int FUN_140ebc4a0()
{
    if (((class Unk_McMarket*)FUN_140939a00())->FUN_140d56160() >= 100)
    {
        FUN_140d73aa0(FUN_1408116a0(0xa29, 100), 0, 0, CStringW(L""));
        return 0;
    }
    return 1;
}

// @0x140ebc540
bool FUN_140ebc540(__int64 nPrice)
{
    if (((class IClientPlatform*)FUN_140d86260())->vfunc_40(nPrice) == 0)
    {
        reinterpret_cast<Unk_McUi*>(TSingleton<CUIService>::GetInstance())->FUN_141add210();
        return false;
    }
    return true;
}

// ---- payment / capacity checks ----
// The Value<> readers and singletons used by the buy flow.
class Unk_McPendingBuyBase;
typedef TMarketBillDataParam::PaymentMap Unk_McPaymentMap;
void FUN_1409abfa0(ATL::CAtlArray<int>& out, ATL::CAtlArray<MS2Ptr<ASBillData> >& bills);
void FUN_140710590(COutPacket& pkt);
void FUN_1412751f0(const CStringW& strText, int a, int b);
__int64 GetServerTime();
int FUN_140ec3900(TMeratMarketBillDataParam* pParam);

// Every amount of the payment map must be payable.
// @0x140ebc590
bool FUN_140ebc590(const TMarketBillDataParam::PaymentMap& mapPay)
{
    for (POSITION pos = mapPay.GetStartPosition(); pos != NULL; mapPay.GetNext(pos))
    {
        __int64 nAmount = mapPay.GetValueAt(pos);
        if (nAmount == 0)
            continue;
        int nType = mapPay.GetKeyAt(pos);
        if (!FUN_1418ff110(nType, nAmount, true))
            return false;
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
        if (((class IClientPlatform*)FUN_140d86260())->vfunc_39(nPrice, nGrade) == 0)
        {
            int nAnyGrade = -1;
            if (((class IClientPlatform*)FUN_140d86260())->vfunc_39(nPrice, nAnyGrade) == 1)
                FUN_140d73aa0(GetStringCommonByKey(L"s_meratmarket_buy_fail_music_score_by_merat_grade"), 0, 0, CStringW(L""));
            else
                FUN_1418ff710(FUN_14069c3e0(nPayType), nPrice, 0, 1);
            return false;
        }
        return true;
    }
    if (FUN_1418ff110(FUN_14069c3e0(nPayType), nPrice, true) == 0)
        return false;
    return true;
}

// The bag space the items of the bill need (per inventory tab).
// @0x140ebc850
int FUN_140ebc850(MS2Ptr<ASArray> spItems)
{
    ATL::CAtlArray<int> counts;
    for (int i = 0; i < 15; ++i)
        counts.Add(0);
    Scaleform::GFx::Value& vItems = spItems->FUN_1422bb870();
    unsigned nItems = spItems->FUN_1422bc5d0();
    for (unsigned i = 0; i < nItems; ++i)
    {
        Scaleform::GFx::Value vElem;
        vItems.GetElement(i, &vElem);
        ASObj row(vElem, 2);
        Scaleform::GFx::Value vId = row.FUN_1422baa20("itemID");
        int nItemId = 0;
        if (FUN_140ec3b90(&vId) == 0)
            nItemId = FUN_140718200(FUN_141277dd0(&vId));
        else
            nItemId = vId.GetUInt();
        if (nItemId == 0)
            continue;
        int nTab = FUN_140ec2ac0(FUN_14053f870(nItemId));
        if (nTab >= 0 && nTab < 15)
            counts.SetAt(nTab, counts[nTab] + 1);
    }
    for (int nTab = 0; nTab < 15; ++nTab)
    {
        int nNeed = counts[nTab];
        if (0 < nNeed && g_143ab2a90.FUN_140a615d0(nTab) < nNeed)
        {
            FUN_140d73aa0(FUN_14093fa20(0xa01, GetStringTable()->FUN_141813300(nTab), nNeed), 0, 0, CStringW(L""));
            return 0;
        }
    }
    return 1;
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
        if (0 < nNeed && g_143ab2a90.FUN_140a615d0(nTab) < nNeed)
        {
            FUN_140d73aa0(FUN_14093fa20(0xa01, GetStringTable()->FUN_141813300(nTab), nNeed), 0, 0, CStringW(L""));
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
    if (bDay)
        strFormat = nBonus == 0 ? GetStringCommonByKey(L"s_common_day") : GetStringCommonByKey(L"s_common_day_bonus");
    else
        strFormat = nBonus == 0 ? GetStringCommonByKey(L"s_common_count") : GetStringCommonByKey(L"s_common_count_bonus");
    CStringW strResult;
    if (bDay)
    {
        if (pProduct->m_nb4 == 0)
            strResult = GetStringCommonByKey(L"s_common_day_limitless");
        else
            strResult = FUN_14083dc40(strFormat, pProduct->m_nb4, nBonus);
    }
    else
        strResult = FUN_14083dc40(strFormat, pProduct->m_nb0, nBonus);
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
        CStringW strFormat = nBonus == 0 ? GetStringCommonByKey(L"s_common_count") : GetStringCommonByKey(L"s_common_count_bonus");
        int nCount = pProduct->GetB0(0);
        strResult = FUN_14083dc40(strFormat, nCount, nBonus);
    }
    return strResult;
}

// @0x140ebd870
CStringW FUN_140ebd870(CMeratMarketPremiumProduct* pProduct)
{
    CStringW strResult;
    unsigned nItemId = pProduct->m_nItemId;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return strResult;
    if (*(unsigned*)((char*)spData.get() + 0x88) <= 1 && pProduct->m_nb4 == 0)
        return strResult;
    bool bSub = pProduct->m_nb4 > 0 ? 1 : 0;
    return FUN_140ebd020(bSub, pProduct);
}

// ---- the buy / tooltip callbacks of the bill dialog ----
class Unk_McMan : public CMeratMarketMan                                             // CMeratMarketMan (placeholder/cmeratmarketman.h): members not recovered
{
};
int FUN_140ec3950(ASMeratMarketBuyBillData* pBill);
void FUN_1409e3190(AScript* pTip, CMeratMarketPremiumProduct* pProduct, int n);
int FUN_14069c3e0(int nPayType);
void* FUN_140b09580(int nId);
void FUN_140899a40(MS2Ptr<CPtred>* pDst, const MS2Ptr<CMeratMarketProduct>& spProduct);
bool FUN_1406a5930();

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
        CMsTime tNow((__time64_t)GetServerTime());
        CMeratMarketPremiumProduct& prem = spProduct->m_premium;
        __int64 nRemain = 0;
        if (prem.m_time188 > tNow)
            nRemain = (prem.m_time188 - tNow).GetTotalSeconds();
        COutPacket pkt(static_cast<int>(SendOp::MeretMarket), 0);
        pkt.WriteUInt8(0x70);
        pkt.WriteInt32(prem.m_n2c);
        pkt.WriteUInt8((char)prem.m_n16c);
        pkt.WriteUInt8((char)prem.m_n170);
        pkt.WriteInt32(prem.GetRemainCount());
        pkt.WriteInt64(nRemain);
        pkt.WriteInt64(prem.m_nSalePrice);
        FUN_140710590(pkt);
    }
    if (pParam->m_sp108 != 0)
    {
        MS2Ptr<CMeratMarketProduct> spProduct = *(MS2Ptr<CMeratMarketProduct>*)&pParam->m_sp108;
        CMeratMarketPremiumProduct& prem = spProduct->m_premium;
        if (prem.FUN_1406a0090())
        {
            FUN_1412751f0(GetStringCommonByKey(CStringW(L"s_meratmarket_error_random_expired")), 1, 1);
            return false;
        }
        COutPacket pkt(static_cast<int>(SendOp::MeretMarket), 0);
        pkt.WriteUInt8(0x74);
        pkt.WriteInt32(prem.m_nId);
        pkt.WriteInt32(prem.m_n1b0);
        pkt.WriteInt32(prem.m_nType == 7 ? 0xd68 : 0xd72);
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
    Unk_McMan* pMan = (Unk_McMan*)((class Unk_McMarket*)FUN_140939a00());
    if (spBase->FUN_140eacfc0())
    {
        MS2Ptr<CMeratMarketBuy> spBuy = new CMeratMarketBuy();
        if (spBuy == 0 || spBuy->m_spPacket == 0)
            return false;
        spBuy.get()->FUN_140d60a80(*(MS2Ptr<CMeratMarketProduct>*)&pParam->m_spE8, nSrc, pParam->m_nCurrency, 1);
        spBuy->FUN_140d60d60(0, 1);
        ((class CMeratMarketBuy*)(class CMeratMarketBuy*)(spBuy.get()))->FUN_140d60ea0(*(int const*)(&nShop));
        pMan->FUN_140d59810(MS2Ptr<CPendingBuyBase>(spBuy.get()), nSrc);
    }
    else
    {
        size_t nCount = pParam->m_bills.GetCount();
        for (size_t i = 0; i < nCount; ++i)
        {
            MS2Ptr<ASMeratMarketBuyBillData> spBill = dynamic_cast<ASMeratMarketBuyBillData*>(pParam->m_bills[i].get());
            if (spBill == 0)
                continue;
            MS2Ptr<CMeratMarketBuy> spBuy = new CMeratMarketBuy();
            if (spBuy == 0 || spBuy->m_spPacket == 0)
                continue;
            spBuy.get()->FUN_140d604c0(spBill, nSrc, 1);
            spBuy->FUN_140d60d60((int)i, (int)nCount);
            ((class CMeratMarketBuy*)(class CMeratMarketBuy*)(spBuy.get()))->FUN_140d60ea0(*(int const*)(&nShop));
            pMan->FUN_140d59810(MS2Ptr<CPendingBuyBase>(spBuy.get()), nSrc);
        }
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
    if (((class Unk_McMarket*)FUN_140939a00()) == 0)
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
    *pOut = tip.FUN_1422bb870();
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
    Unk_McMan* pMan = (Unk_McMan*)((class Unk_McMarket*)FUN_140939a00());
    size_t nCount = arrBuy.GetCount();
    for (size_t i = 0; i < nCount; ++i)
    {
        MS2Ptr<CMeratMarketBuy> spBuy = new CMeratMarketBuy();
        if (spBuy == 0 || spBuy->m_spPacket == 0)   // exe: CMeratMarketBuy +0x38
            continue;
        spBuy.get()->FUN_140d604c0(arrBuy[i], nSrc, 1);
        spBuy->FUN_140d60d60((int)i, (int)nCount);
        ((class CMeratMarketBuy*)(class CMeratMarketBuy*)(spBuy.get()))->FUN_140d60dd0(strA, strB);
        ((class CMeratMarketBuy*)(class CMeratMarketBuy*)(spBuy.get()))->FUN_140d60ea0(*(int const*)(&nShop));
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
            nType = pRow->FUN_1422baa20("priceType").GetInt();
        else
            nType = 1;
    }
    return nType;
}

// Open the bill dialog for a limited product.
// @0x140ebf610
void FUN_140ebf610(const CStringA& /*strMovie*/, MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<TMeratMarketBillDataParam> spParam, int nPayType)
{
    if (spProduct == 0 || spParam == 0)
        return;
    if (!((CMeratMarketMan*)((class Unk_McMarket*)FUN_140939a00()))->FUN_140d5b1f0(spProduct, true))
        return;
    CMeratMarketPremiumProduct* pPrem = &spProduct->m_premium;
    int nCur = FUN_14069c3e0(nPayType);
    __int64 nPrice = spProduct->GetSalePrice();
    if (!FUN_1418ff110(nCur, nPrice, true))
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
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = spParam->m_bills;
    CRBMap<int, MS2Ptr<CDBPremiumProduct> >& mapLimit = pPrem->m_mapLimit;
    for (POSITION pos = mapLimit.GetHeadPosition(); pos != 0; mapLimit.GetNext(pos))
    {
        MS2Ptr<CDBPremiumProduct> spSub = mapLimit.GetValueAt(pos);
        if (spSub == 0)
            continue;
        MS2Ptr<ASMeratMarketBuyBillData> spBill = new ASMeratMarketBuyBillData();
        if (spBill == 0)
            return;
        spBill.get()->FUN_1409ab990(FUN_14053f870(spSub->m_nItemId), spSub->m_nGrade);
        ((class ASMeratMarketBuyBillData*)(class ASMeratMarketBuyBillData*)(spBill.get()))->FUN_1409aca00((class CMeratMarketPremiumProduct*)(((void const*)((MS2Ptr<CDBPremiumProduct>*)&static_cast<class MS2Ptr<class CDBPremiumProduct>&>(spSub))->get())), spProduct);
        MS2Ptr<ASBillData> spBase(spBill);
        bills.Add(spBase);
    }
    MS2Ptr<TMarketBillDataParam> spShow(spParam);
    ((UIMarketBillDialog*)pDialog)->FUN_140ea7770(spShow);
    ((Unk_McUi*)reinterpret_cast<Unk_McUi*>(TSingleton<CUIService>::GetInstance()))->FUN_141adc530(0x4f17);
}

// ---- purchase condition checks ----
class Unk_McPayback : public CUgcGetCostTable { };
extern Unk_McPayback* DAT_143ab22a8;
Unk_McPayback* FUN_140ec3940();
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_1418fec00(int nType, __int64 nAmount, int n);
CStringW FUN_140bfa7f0(CStringW strKey, const CStringW& strArg, const int& nArg);   // FUN_14028dfa0<CStringW, int>
bool FUN_140ebb1e0(const Scaleform::GFx::Value* pValue);
class Unk_McAchieve : public CPtred { public: __int64 FUN_140159040(int nGrade); };
class Unk_McAchieveMgr { public: MS2Ptr<Unk_McAchieve> FUN_140935e60(int nId); };
class Unk_NametagTrophy* FUN_1406c7600();   // C3: was FUN_1406c7600
class CAchieveManager   // C3: member view for the former free stand-ins
{
public:
    int IsBeforeStartGrade(unsigned int, int);
};
CStringW FUN_14093b9c0(int nAchieve, int nGrade);
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);
__int64 FUN_140166410();
unsigned short FUN_14036db20(__int64 p);
CStringW FUN_140ec01e0(CDBPremiumProduct* pProduct, const CStringW& strKey);
CStringW FUN_14061ad70(const CStringW& strKey, const wchar_t* szSuffix);
CStringW FUN_1409e8820(CStringW strFormat, const unsigned short& n);   // FUN_14028dfa0<unsigned short>
CStringW FUN_14028dfa0(const CStringW& key, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)
class PC   // C3: member view for the former free stand-ins
{
public:
    int FUN_141654700();
    unsigned char FUN_141658f10();
};
int FUN_1406a59f0(struct Unk_MeratJobLimit*, int);   // C3: was FUN_1406a59f0
void FUN_140222a70(int nMask, ATL::CAtlArray<int>& out);
int FUN_140644bb0(void* p, int nJob);
void* FUN_1401d7a50();

// The achievement the product requires.
// @0x140ebfb90
bool FUN_140ebfb90(CDBPremiumProduct* pProduct, bool bShowError)
{
    int nAchieve = pProduct->m_nf8;
    if (nAchieve == 0)
        return true;
    int nGrade = pProduct->m_nfc;
    if (((class CAchieveManager*)(class Unk_McAchieveMgr*)(((class Unk_McAchieveMgr*)FUN_1406c7600())))->IsBeforeStartGrade(nAchieve, nGrade) != 0)
        return true;
    if (bShowError)
    {
        CStringW strMsg = FUN_14052bd00(0x5c, FUN_14093b9c0(nAchieve, nGrade));
        FUN_1412751f0(strMsg, 1, 1);
    }
    return false;
}

// The player level against the buy limit of the product.
// @0x140ebfc70
bool FUN_140ebfc70(unsigned short nLevel, CDBPremiumProduct* pProduct, bool bShowError)
{
    if (nLevel == 0)
        return true;
    // The exe reads the level limits unsigned.
    if ((unsigned short)pProduct->m_n94 == 0 && (unsigned short)pProduct->m_n96 == 0)
        return true;
    unsigned short nMin = pProduct->m_n94;
    unsigned short nMax = pProduct->m_n96;
    nMin = nMin == 0 ? 1 : nMin;
    nMax = nMax == 0 ? FUN_14036db20(FUN_140166410()) : nMax;
    if (nLevel < nMin || nMax < nLevel)
    {
        if (bShowError)
        {
            CStringW strMsg = FUN_140ec01e0(pProduct, L"s_meratmarket_error_buy_limit_");
            FUN_1412751f0(strMsg, 1, 1);
        }
        return false;
    }
    return true;
}

// The level check against the local player.
// @0x140ebfdd0
bool FUN_140ebfdd0(CDBPremiumProduct* pProduct, bool bShowError)
{
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer != 0)
        return FUN_140ebfc70((unsigned short)pPlayer->vfunc_78(), pProduct, bShowError);
    return true;
}

// The PC bang level of the product.
// @0x140ebfe30
bool FUN_140ebfe30(CDBPremiumProduct* pProduct, bool bShowError)
{
    if (pProduct->FUN_14069fee0() == 0)
        return true;
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer != 0)
    {
        int nLevel = ((class PC*)(class PCBase*)(pPlayer))->FUN_141658f10();
        if (nLevel == 0)
        {
            if (bShowError)
            {
                CStringW strMsg = GetStringCommonByKey(L"s_meratmarket_error_buy_not_pcbang");
                FUN_1412751f0(strMsg, 1, 1);
            }
            return false;
        }
        int nRequired = pProduct->FUN_14069fee0();
        if (nRequired > nLevel)
        {
            if (bShowError)
            {
                CStringW strMsg = GetStringCommonByKey(L"s_meratmarket_error_buy_low_pcbang_level");
                FUN_1412751f0(strMsg, 1, 1);
            }
            return false;
        }
    }
    return true;
}

// The job limit of the product.
// @0x140ebff70
bool FUN_140ebff70(CDBPremiumProduct* pProduct, bool bShowError)
{
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
    if (pPlayer == 0)
        return false;
    int nResult = FUN_1406a59f0((struct Unk_MeratJobLimit*)(pProduct), ((class PC*)(class PCBase*)(pPlayer))->FUN_141654700());
    if (bShowError && nResult == 0xb5)
    {
    const CStringW& strSep = L", ";
    CStringW strJobs;
    ATL::CAtlArray<int> arrJobs;
    FUN_140222a70(pProduct->m_n98, arrJobs);
    for (size_t i = 0; i < arrJobs.GetCount(); ++i)
    {
        CStringW strName = GetStringTable()->FUN_141811980(6, FUN_140644bb0(FUN_1401d7a50(), arrJobs[i]));
        if (strName.IsEmpty())
            continue;
        if (!strJobs.IsEmpty())
            strJobs.Append(strSep);
        strJobs.Append(strName);
    }
    CStringW strMsg = FUN_1405c2690(CStringW(L"s_meratmarket_error_buy_limit_job_detail"), strJobs);
    FUN_1412751f0(strMsg, 1, 1);
    return false;
    }
    return nResult == 0;
}

// The level limit text of a product.
// @0x140ec01e0
CStringW FUN_140ec01e0(CDBPremiumProduct* pProduct, const CStringW& strKey)
{
    CStringW strResult;
    unsigned short nMin = pProduct->m_n94;
    unsigned short nMax = pProduct->m_n96;
    if (nMin > 0 && nMax > 0)
    {
        if (nMin == nMax)
            strResult = FUN_1409e8820(FUN_14061ad70(strKey, L"level_only"), nMin);
        else
            strResult = FUN_14028dfa0(FUN_14061ad70(strKey, L"level_range"), nMin, nMax);
    }
    else if (nMin > 0)
        strResult = FUN_1409e8820(FUN_14061ad70(strKey, L"level_min"), nMin);
    else
        strResult = FUN_1409e8820(FUN_14061ad70(strKey, L"level_max"), nMax);
    return strResult;
}

// The achievement requirement state: 0 ok, 0xb0 no achievement, 0xb1 not achieved, 0xb2 expired.
// @0x140ec04b0
int FUN_140ec04b0(CMeratMarketPremiumProduct* pProduct)
{
    // The exe tests the achieve id unsigned.
    if ((unsigned int)pProduct->m_nf8 > 0)
    {
        int nAchieve = pProduct->m_nf8;
        int nGrade = pProduct->m_nfc;
        MS2Ptr<Unk_McAchieve> spAchieve = ((class Unk_McAchieveMgr*)FUN_1406c7600())->FUN_140935e60(nAchieve);
        if (spAchieve == 0)
            return 0xb0;
        if (spAchieve->FUN_140159040(nGrade) == 0)
            return 0xb1;
        if (pProduct->m_n100 > 0)
        {
            __int64 nNow = GetServerTime();
            __int64 nExpire = spAchieve->FUN_140159040(nGrade) + pProduct->m_n100;
            if (nNow > nExpire)
                return 0xb2;
        }
    }
    return 0;
}

// ---- sort drop downs, UGC checks and the bill dialog start ----
CStringW FUN_140c160b0(CStringW strFormat, const __int64& nValue);
void FUN_140d73ff0(CStringW strText);
void FUN_140d73bc0(int nId, int a, int b, CStringW strTag);
void FUN_141275260(int nStringId, int a, int b);
void SendRequestCubeMode66(void* pBlueprint);
// The owner key of the local player (account id, kind, character id); the exe builds it field by field.
struct Unk_McTimeKey
{
    void FUN_1409aff60();
    __int64 a;
    int b;
    __int64 c;
    __int64 d;
};
extern __int64 DAT_143ab2820;
extern int DAT_143ab2830;
extern __int64 DAT_143ab2838;
extern int DAT_143ab2834;
PaybackManagerClient* FUN_1409c1740();
void FUN_1409ab940(ASMeratMarketBuyBillData* pBill, __int64 n);
void FUN_1409b03d0(ASMeratMarketBuyBillData* pBill, __int64 n);
bool FUN_140ebc630(MS2Ptr<CMeratMarketProduct> spProduct, int nPayType);
void FUN_140ec07b0(ASArray* pArr, const CStringW& strLabel, int nSort, bool bUgc);
void FUN_140ec0990(ASArray* pArr, int nTab);

// The payback table text of the tooltip: one row per charge step, the step holding the current amount is marked.
// @0x140ebd9d0
CStringW FUN_140ebd9d0(bool bSelect, __int64 nCur)
{
    CRBMap<__int64, int> mapPayback(10);
    FUN_140ec3940()->GetTable(mapPayback);
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
            CStringW strRow = FUN_140bfa7f0(CStringW(L"s_meratmarket_tooltip_table_charge_row_max"), FUN_1418fec00(3, nStep, 0), nPercent);
            if (bSelect && nStep <= nCur)
            {
                CStringW strSelect = FUN_1405c2690(CStringW(L"s_meratmarket_tooltip_table_charge_select"), strRow);
                strResult.Append(strSelect);
            }
            else
                strResult.Append(strRow);
        }
        else
        {
            if (strRowFormat.IsEmpty())
                strRowFormat = GetStringCommonByKey(L"s_meratmarket_tooltip_table_charge_row");
            __int64 nNextStep = mapPayback.GetKeyAt(posNext);
            CStringW strRow = StringFormat((const wchar_t*)strRowFormat, FUN_1409404f0(nStep), FUN_1418fec00(3, nNextStep, 0), nPercent);
            if (bSelect && nCur >= nStep && nCur < nNextStep)
            {
                CStringW strSelect = FUN_1405c2690(CStringW(L"s_meratmarket_tooltip_table_charge_select"), strRow);
                strResult.Append(strSelect);
            }
            else
                strResult.Append(strRow);
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
        FUN_140ec07b0(pArr, L"$s_meratmarket_dropdown_premium_sort_chartorder", 5, false);
        FUN_140ec07b0(pArr, L"$s_meratmarket_dropdown_premium_sort_price_low", 2, false);
        FUN_140ec07b0(pArr, L"$s_meratmarket_dropdown_premium_sort_price_high", 3, false);
        FUN_140ec07b0(pArr, L"$s_meratmarket_dropdown_premium_sort_create", 4, false);
    }
    else if (nTab == 1)
    {
        FUN_140ec07b0(pArr, L"$s_meratmarket_dropdown_ugc_sort_create", 4, true);
        FUN_140ec07b0(pArr, L"$s_meratmarket_dropdown_ugc_sort_buy", 1, true);
        FUN_140ec07b0(pArr, L"$s_meratmarket_dropdown_ugc_sort_buy_total", 6, true);
    }
}

// Open the blueprint of an UGC product.
// @0x140ec0b50
void FUN_140ec0b50(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (spProduct == 0 || spProduct->IsUgc() == 0)
        return;
    if (spProduct->m_ugc.FUN_140896350() == 0)
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
    if (spProduct->IsUgc())
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
        Unk_McTimeKey key;
        key.FUN_1409aff60();
        key.a = DAT_143ab2820;
        key.b = DAT_143ab2830;
        key.c = DAT_143ab2838;
        key.d = DAT_143ab2834;
        if (((class CUgcMarketProduct*)(class CUgcMarketProduct*)(&spProduct->m_ugc))->FUN_140896230(*(class Unk_CommonOwner*)(&key)))
        {
            FUN_140d73bc0(0xa14, 0, 0, CStringW(L""));
            return;
        }
    }
    else
    {
        if (spProduct->HasLimit() != 0 && spProduct->m_premium.IsSoldOut())
        {
            FUN_141275260(0xa17, 1, 1);
            return;
        }
    }
    if (!((CMeratMarketMan*)((class Unk_McMarket*)FUN_140939a00()))->FUN_140d5b1f0(spProduct, true))
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
    int bUgc = spProduct->IsUgc();
    ATL::CAtlArray<MS2Ptr<ASBillData> >& arrBills = spParam->m_bills;
    {
        MS2Ptr<ASMeratMarketBuyBillData> spBill = new ASMeratMarketBuyBillData();
        FUN_1409ab940(spBill.get(), n4);
        FUN_1409b03d0(spBill.get(), n5);
        spBill.get()->FUN_1409ac360(spProduct, 0, nCur);
        MS2Ptr<ASBillData> spRow(spBill);
        arrBills.Add(spRow);
        spParam->FUN_140eab940(spBill->FUN_140eacf60());
    }
    spParam->SetGift(bUgc != 0);
    MS2Ptr<TMarketBillDataParam> spShow(spParam);
    ((UIMarketBillDialog*)pDialog)->FUN_140ea7770(spShow);
    ((Unk_McUi*)reinterpret_cast<Unk_McUi*>(TSingleton<CUIService>::GetInstance()))->FUN_141adc530(0x4f17);
}

// ---- user report, category lookups, texts ----
class Unk_McCategoryEntry : public CPtred { public: MS2Ptr<CPtred> m_sp18; };
CStringW FUN_14016a730(const char* sz, int n);
void FUN_1409c1640(void* pId, CStringW str);
__int64 FUN_140718350(const CString& str);
bool FUN_141b70f50(const CStringW& strA, const CStringW& strB);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_140a228f0(int nId, const int& nMonth, const CStringW& strArg);
CStringW GetStringCommon(int nId);
void FUN_141b70f90(const CMsTime& tm, const CStringW& strFormat, CStringW& strOut);
CString FUN_140719210(int n);
void FUN_140692c90(MS2Ptr<CItem>& sp, const MS2Ptr<CItem>& spNew);
class Unk_McCategoryTable
{
public:
    MS2Ptr<CPtred> FUN_1407cb520(int nCategory, int nTab);   // CShopCategoryTable::FindTab
};
bool FUN_141b49b50(MS2Ptr<CItemData> spData);
class Unk_McSortTabInfo : public CPtred { public: char m_pad[0x78 - 0x18]; bool m_b78; bool m_b79; };   // CShopCategoryTable::SortTabInfo

// File a user report about the seller from the market (data: report id, target id, reason, name).
// MS2-FUNCTIONAL: not byte-matched (unrecovered callee signatures, temporaries)
// @0x140ec1340
void FUN_140ec1340(ASData& data)
{
    PCBase* pPlayer = ((class PCBase*)((class WorldService*)(void*)(((void*)WorldService::GetInstance())))->FUN_141bd0cc0());
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
    if (MS2Ptr<CMeratMarketProduct> spProduct = ((CMeratMarketMan*)((class Unk_McMarket*)FUN_140939a00()))->FUN_140d57150(*(Unk_MeratProductKey*)&id, 0))
    {
        spReport->SetFielda0(*(__int64*)((char*)spProduct.get() + 0x318));
        spReport->SetFielda8(*(__int64*)((char*)spProduct.get() + 0x320));
        spReport->SetFieldc0(*(__int64*)((char*)spProduct.get() + 0x350));
        spReport->SetFieldc8(*(CStringA*)((char*)spProduct.get() + 0x390));
        spReport->m_n110 = spProduct->m_ugc.FUN_140896310();
    }
    ((class IClientPlatform*)FUN_140d86260())->vfunc_48(spReport);
}

// The item class of an item as a report/category code.
// @0x140ec1950
int FUN_140ec1950(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return 0;
    MS2Ptr<CItemData> spData = ((class CItemData*)((class CItem*)(class CItem*)(spItem.operator->()))->FUN_140527840());
    if (spData == 0)
        return 0;
    if (FUN_141b49b50(spData))
        return 0x79;
    else if (spData->FUN_14053ce40())
        return 0x7b;
    else if (spData->FUN_14053cb40())
        return 0x7b;
    else if (spData->FUN_14053cd50())
        return 0x7b;
    else if (spData->FUN_14053cb80())
        return 0x7f;
    else if (spData->FUN_14053cc80())
        return 0x7b;
    else if (spData->FUN_14053cd10())
        return 0x7c;
    else if (spData->FUN_14053d900())
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
    MS2Ptr<CPtred> spTab = reinterpret_cast<Unk_McCategoryTable*>(TSingleton<CShopCategoryTable>::GetInstance())->FUN_1407cb520(nCategory, nTab);
    if (spTab == 0)
        return;
    // The cast must name the exe's classes: a dynamic_cast to Unk_McSortTabInfo found no TypeDescriptor and was always NULL.
    MS2Ptr<Unk_McSortTabInfo> spSort(reinterpret_cast<Unk_McSortTabInfo*>(dynamic_cast<CShopCategoryTable::SortTabInfo*>(
        reinterpret_cast<CShopCategoryTable::TabInfo*>(spTab.operator->()))));
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
    if (((class Unk_McMarket*)FUN_140939a00())->FUN_140d5a2e0() != 0)
    {
        CMsTime tNow((__time64_t)GetServerTime());
        int nMonth = tNow.GetMonth();
        __int64 nArg = ((class Unk_McMarket*)FUN_140939a00())->FUN_140d5a1d0();
        return FUN_140a228f0(0xa24, nMonth, FUN_1409404f0(nArg));
    }
    return CStringW(L"");
}

// @0x140ec2010
CStringW FUN_140ec2010()
{
    if (((class Unk_McMarket*)FUN_140939a00())->FUN_140d5a2e0() != 0)
    {
        __int64 nArg = ((class Unk_McMarket*)FUN_140939a00())->FUN_140d5a1d0();
        return FUN_14052bd00(0xa25, FUN_1409404f0(nArg));
    }
    return CStringW(L"");
}

// The product row of the click out data: icon, name and ids.
// @0x140ec20d0
int FUN_140ec20d0(ASObj* pRow, MS2Ptr<CMeratMarketProduct> spProduct, MS2Ptr<CItem> spItem, PC* pPlayer)
{
    if (spProduct.get())
    {
        if (spProduct->GetType() == 3)
        {
            auto& premium = spProduct->m_premium;
            CStringA strIcon = premium.GetIconPath();
            ((ASSlot*)pRow)->FUN_1409c23e0(premium.GetGrade());
            ((ASSlot*)pRow)->FUN_1409c2750(strIcon);
        }
        else
        {
            if (spItem.IsNull())
                FUN_140692c90(spItem, FUN_140ebc070(spProduct));
            ((class ASSlot*)(class ASObj*)(pRow))->FUN_1409c3860(spItem.get(), (void*)(pPlayer), 0xd01);
        }
        pRow->FUN_1407cba60("itemID", FUN_140719210(spProduct->GetItemId()));
        pRow->FUN_1407cbb20("productOID", ((Unk_McOid*)&spProduct->m_key)->FUN_1409b0470());
        return true;
    }
    return false;
}

// Find a product by the key kind: 1 = by id, 2, 3 and 4 = the other lookups, else the generic lookup.
// @0x140ec2300
MS2Ptr<CMeratMarketProduct> FUN_140ec2300(const Unk_MeratProductKey& key, const int& nKind, __int64 nId)
{
    MS2Ptr<CMeratMarketProduct> spProduct(0);
    switch (nKind)
    {
    case 1:
        spProduct = ((CMeratMarketMan*)((class Unk_McMarket*)FUN_140939a00()))->FUN_140d57d80(key);
        break;
    case 2:
        spProduct = ((CMeratMarketMan*)((class Unk_McMarket*)FUN_140939a00()))->FUN_140d57d80(key);
        break;
    case 3:
        spProduct = ((CMeratMarketMan*)((class Unk_McMarket*)FUN_140939a00()))->FUN_140d57f70(key);
        break;
    case 4:
        spProduct = ((CMeratMarketMan*)((class Unk_McMarket*)FUN_140939a00()))->FUN_140d576a0(key);
        break;
    }
    if (spProduct == 0)
        spProduct = ((CMeratMarketMan*)((class Unk_McMarket*)FUN_140939a00()))->FUN_140d57150(key, nId);
    return spProduct;
}

// The sale end time text.
// @0x140ec25e0
CStringW FUN_140ec25e0(__int64 nTime)
{
    CMsTime tm(nTime);
    CStringW strOut;
    FUN_141b70f90(tm, GetStringCommon(0xa28), strOut);
    return strOut;
}

// ---- the click data of the product buttons ----
// @0x140ec2690
UIMeratMarketDialogUtil::ASOutData::ASOutData(Scaleform::GFx::Value& v, int nMovieId)
    : AScript(v, nMovieId)
{
#ifdef __clang__
    // clang-cl will not bind the temporary to Value& (a cl extension); same call through a named copy.
    Scaleform::GFx::Value valData = FUN_1422baa20("data");
    m_spProduct = ASMeratMarketProductBase::FUN_1409bbc30(valData, nMovieId);
#else
    m_spProduct = ASMeratMarketProductBase::FUN_1409bbc30(FUN_1422baa20("data"), nMovieId);
#endif
    m_spRenderer.AssignRaw(new AScript(FUN_1422baa20("renderer"), nMovieId));
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
    FUN_1409edaf0(m_buyBtnData, AScript(FUN_1422baa20("buyBtnData"), nMovieId));
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
    return pValue->GetType() == 5;
}

// @0x140ec3bf0
bool FUN_140ec3bf0(const Scaleform::GFx::Value* pValue)
{
    return pValue->GetType() == 4;
}

// @0x140ec3b90
bool FUN_140ec3b90(const Scaleform::GFx::Value* pValue)
{
    return FUN_140ebb1e0(pValue) || FUN_140ec3bf0(pValue) || FUN_140ec3b50(pValue);
}

// The inventory tab of an item.
// @0x140ec2ac0
int FUN_140ec2ac0(MS2Ptr<CItemData> spData)
{
    return g_143ab2a90.FUN_140a61870(spData);
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
    m_value.SetMember(szName, data.FUN_1422b9260());
}

// @0x140ec3560
AScript* FUN_140ec3560(AScript* pDst, ASTooltip* pSrc)
{
    FUN_1409edaf0(*pDst, *pSrc);
    *(__int64*)((char*)pDst + 0x40) = *(__int64*)((char*)pSrc + 0x40);
    *(int*)((char*)pDst + 0x48) = *(int*)((char*)pSrc + 0x48);
    *(CStringW*)((char*)pDst + 0x50) = *(CStringW*)((char*)pSrc + 0x50);
    return pDst;
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
