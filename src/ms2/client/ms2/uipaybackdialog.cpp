// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The merat payback window ("PaybackDialog"); see
// uipaybackdialog.h. One of the five TUs of the queue unit ?\uiotherpetsystemdialog.cpp (UIOtherPetSystemDialog,
// UIOxQuizDialog, UIPaybackDialog, UIPetExtractionScrollDialog, UIPetSystemDialog). The obj also keeps the inline
// ctor / dtor of ASMeratMarketBuyBillData (its bill row) and the CAtlArray<MS2Ptr<ASBillData> >::Add glue.
// MS2-UNIT: ?\uiotherpetsystemdialog.cpp
// MS2-RANGE: 0x140e6ec50-0x140e70a90 .text$mn
// MS2-RANGE: 0x1400d98b0-0x1400d9b80 .text$di
// MS2-PIN: ??C?$MS2Ptr@VASSlot@@@@QEBAPEAVASSlot@@XZ 0x140e703a0
// MS2-PIN: ?get@?$MS2Ptr@VASSlot@@@@QEBAPEAVASSlot@@XZ 0x140e703b0
// MS2-PIN: ?get@?$MS2Ptr@VTMeratMarketBillDataParam@@@@QEBAPEAVTMeratMarketBillDataParam@@XZ 0x140e70540
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uipaybackdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uipaybackdialog.h"
#include "uimarketbilldialog.h"
#include "tmeratmarketbilldataparam.h"

#include "ms2/placeholder/asmeratmarketbuybilldata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/paybacktable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/paybackmanagerclient.h"
#include "ms2/commonfiles/meratmarketbasketinfo.h"
#include "ms2/ms2format.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics of the unit's headers ----

static CString s_strPremiumSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal",
                                          "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
static CStringA s_strJobCode = "jobCode";
static CStringA s_strSortValue = "sortValue";
static CStringA s_strTabIndex = "tabIndex";

// ---- out-of-unit callees (names describe uses) ----

// The packet handler table (0x10b: the payback status).
class Unk_PbPackets
{
public:
    void FUN_140da5180(int nOp, Delegate<void(CInPacket&)> dg);    // add a handler
    void FUN_140da51e0(int nOp, Delegate<void(CInPacket&)> dg);    // remove it
};
Unk_PbPackets* FUN_140bccd50();

// The status-listener registry.
class Unk_PbStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);           // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);           // unregister
};
Unk_PbStatusMgr* FUN_140aa6d40();

// The world service: the player.
class Unk_PbWorld { public: void* FUN_141bd0cc0(); };
Unk_PbWorld* FUN_1403ed2d0();

// The UI manager.
class Unk_PbUiMgr
{
public:
    void FUN_141adc530(int nId);                                    // open a dialog
    void FUN_141adc5d0(int nId);                                    // close a dialog (if open)
};
Unk_PbUiMgr* FUN_1403ed2b0();

PaybackTable* FUN_14071d7d0();                                      // the payback table
PaybackManagerClient* FUN_1409c1740();                              // the payback manager
UIMarketBillDialog* FUN_140b09580(int nUiId);                       // the bill dialog of a UI id
__int64 FUN_140869440();                                            // the server clock
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);   // notice by string id
void FUN_141275260(int nStringId, int nA, int nB);                  // notice by string id
MS2Ptr<CItem> FUN_140ebc360(int nItemId, int nGrade);               // a preview item
int FUN_14069c3e0(int nType);                                       // the bill currency of a pay currency
void FUN_1409ac360(ASMeratMarketBuyBillData* pBill, MS2Ptr<CMeratMarketProduct> spProduct, int n, int nCur);
int FUN_140291d90(float f);                                         // round a percent
CStringW FUN_1409404f0(__int64 nMoney);                             // money text
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a1, const CStringW& a2);   // string table text, two args
CStringW FUN_140719900(CStringW str);
CStringW FUN_14083cb20(const CStringW& str);

// The merat market's bill callbacks (UIMeratMarketCommon).
bool FUN_140ebded0(MS2Ptr<TMarketBillDataParam> spParam, const TMarketBillDataParam::PaymentMap& mapPay);
bool FUN_140ebef60(MS2Ptr<TMarketBillDataParam> spParam, const TMarketBillDataParam::PaymentMap& mapPay,
                   const CStringW& strTo, const CStringW& strMessage);
bool FUN_140ebe990(Scaleform::GFx::Value* pRetVal, ASData& data, MS2Ptr<TMarketBillDataParam> spParam);
// The free-function Delegate ctors (COMDATs of an earlier obj).
TMarketBillDataParam::BuyCallback FUN_140bbefb0(bool (*pfn)(MS2Ptr<TMarketBillDataParam>,
                                                            const TMarketBillDataParam::PaymentMap&));
TMarketBillDataParam::GiftCallback FUN_140bbf040(bool (*pfn)(MS2Ptr<TMarketBillDataParam>,
                                                             const TMarketBillDataParam::PaymentMap&,
                                                             const CStringW&, const CStringW&));
TMarketBillDataParam::TooltipCallback FUN_140bbef00(bool (*pfn)(Scaleform::GFx::Value*, ASData&,
                                                                MS2Ptr<TMarketBillDataParam>));

static CStringW FUN_140e70010(CStringW str);

// @0x140e6ec50
UIPaybackDialog::UIPaybackDialog()
{
    FUN_141924170(1);
    FUN_140bccd50()->FUN_140da5180(0x10b, Delegate<void(CInPacket&)>(this, &UIPaybackDialog::FUN_140e6f7c0));
}

// @0x140e6ed70
UIPaybackDialog::~UIPaybackDialog()
{
    FUN_140bccd50()->FUN_140da51e0(0x10b, Delegate<void(CInPacket&)>(this, &UIPaybackDialog::FUN_140e6f7c0));
}

// @0x140e6ee70
CString UIPaybackDialog::vfunc_1()
{
    return "PaybackDialog";
}

// @0x140e6eec0
void UIPaybackDialog::vfunc_67()
{
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    UIDialog::vfunc_67();
}

// @0x140e6ef20
void UIPaybackDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (!FUN_1409c1740()->FUN_140a8be20(0))
    {
        vfunc_67();
    }
    else
    {
        FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
        FUN_140e6f8c0();
        FUN_140e6fba0();
        FUN_140e6fdf0();
    }
}

// @0x140e6efe0
int UIPaybackDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) == 1)
        return 1;
    if (_stricmp(szMethod, "OnBuy") == 0)
    {
        if (FUN_14071d7d0()->IsResetWindow())
        {
            FUN_1403ed2b0()->FUN_141adc5d0(0x4f93);
            FUN_140d73bc0(0xd4f, 0, 0, CStringW(L""));
            return 1;
        }
        void* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer == 0)
            return 0;
        MS2Ptr<CMeratMarketProduct> spProduct = FUN_1409c1740()->FUN_140a8b360();
        if (spProduct == 0)
        {
            FUN_141275260(0xa0f, 1, 1);
            return 0;
        }
        UIMarketBillDialog* pDialog = FUN_140b09580(0x4f17);
        if (pDialog == 0)
            return 0;
        MS2Ptr<TMeratMarketBillDataParam> spParam(new TMeratMarketBillDataParam());
        if (spParam == 0)
            return 0;
        spParam->m_nDialogId = vfunc_48();
        spParam->m_strMovie = vfunc_1();
        int nPay = spProduct->GetPayCurrency();
        int nCurrency = FUN_14069c3e0(nPay);
        spParam->m_nCurrency = nCurrency;
        spParam->SetSourceKind(1);
        spParam->m_dgBuy = FUN_140bbefb0(&FUN_140ebded0);
        spParam->m_dgGift = FUN_140bbf040(&FUN_140ebef60);
        spParam->m_dgTooltip = FUN_140bbef00(&FUN_140ebe990);
        spParam->SetGift(false);
        {
            MS2Ptr<CItem> spItem = FUN_140ebc360(spProduct->m_premium.m_nItemId, spProduct->m_premium.GetGrade());
            if (spItem == 0)
                return 0;
            MS2Ptr<ASSlot> spSlot(new ASSlot(2));
            if (spSlot.get()->FUN_1409c3860(spItem.get(), pPlayer, 0x1c03f) == 0)
                return 0;
            MS2Ptr<ASMeratMarketBuyBillData> spBill(new ASMeratMarketBuyBillData());
            spBill->FUN_1409ab940(spSlot->FUN_1422bb870());
            FUN_1409ac360(spBill.operator->(), spProduct, 0, nCurrency);
            spBill->FUN_1407cb9c0("serialID", spProduct->m_premium.m_nId);
            MS2Ptr<ASBillData> spRow(spBill);
            spParam->m_bills.Add(spRow);
        }
        pDialog->FUN_140ea7770(spParam.get());
        FUN_1403ed2b0()->FUN_141adc530(0x4f17);
        return 1;
    }
    return 0;
}

// @0x140e6f7c0
void UIPaybackDialog::FUN_140e6f7c0(CInPacket& packet)
{
    if (FUN_141924630() == 0)
        return;
    if (!FUN_14071d7d0()->IsResetWindow())
        return;
    vfunc_67();
}

// @0x140e6f820
void UIPaybackDialog::FUN_140e6f820(int nOldLevel, unsigned nOldMerat)
{
    if (vfunc_55())
        return;
    if (m_30 == 0)
        return;
    FUN_140e6f8c0();
    FUN_140e6fba0();
}

// @0x140e6f890
int UIPaybackDialog::FUN_140e6f890()
{
    return FUN_1409c1740()->FUN_140a8be20(0);
}

// @0x140e6f8c0
void UIPaybackDialog::FUN_140e6f8c0()
{
    if (m_30 == 0)
        return;
    int nIndex = 0;
    __int64 nNow = FUN_140869440();
    std::vector<PaybackTable::LevelEntry>& levels = FUN_14071d7d0()->GetLevels(nNow);
    for (std::vector<PaybackTable::LevelEntry>::iterator it = levels.begin(); it != levels.end(); ++it)
    {
        const PaybackTable::LevelEntry* pEntry = &*it;
        ASObj row(2);
        row.FUN_1407cb9c0("index", nIndex++);
        row.FUN_1409c0d20("level", pEntry->m_nLevel);
        row.FUN_1407cbb20("merat", FUN_140e70010(StringFormat(L"{0}", FUN_14071d7d0()->GetLevelMerat(
                                                     pEntry, FUN_1409c1740()->GetMerat(), nNow))));
        row.FUN_1407cbb20("percent", StringFormat(L"{0}", FUN_140291d90(FUN_14071d7d0()->GetLevelPercent(pEntry, nNow))));
        row.FUN_1409c0d20("targetLevel", FUN_1409c1740()->FUN_140a8b320());
        row.FUN_1407cbbe0("isRed", FUN_14071d7d0()->IsLocaleEnabled());
        m_30->Invoke("setEntity", row);
    }
}

// @0x140e6fba0
void UIPaybackDialog::FUN_140e6fba0()
{
    if (m_30 == 0)
        return;
    __int64 nNow = FUN_140869440();
    CStringW strTotal = FUN_1409404f0(FUN_14071d7d0()->GetMeratTotal(FUN_1409c1740()->GetMerat(), nNow));
    CStringW strCurrent = FUN_1409404f0(
        FUN_14071d7d0()->GetMeratUpTo(FUN_1409c1740()->FUN_140a8b320(), FUN_1409c1740()->GetMerat(), nNow));
    CStringW strText = FUN_1408f71a0(CStringW(L"s_payback_dialog_maret"), strCurrent, strTotal);
    if (FUN_14071d7d0()->IsLocaleEnabled())
        strText = FUN_1408f71a0(CStringW(L"s_payback_dialog_merat_text_red_merat"), strCurrent, strTotal);
    m_30->Invoke("setPaybackMerat", strText);
}

// @0x140e6fdf0
void UIPaybackDialog::FUN_140e6fdf0()
{
    if (m_30 == 0)
        return;
    m_30->Invoke("setPeriod", FUN_1409c1740()->FUN_140a8ba00());
}

// @0x140e70010
static CStringW FUN_140e70010(CStringW str)
{
    return FUN_14083cb20(FUN_140719900(str));
}

// @0x140e70220
ASMeratMarketBuyBillData::ASMeratMarketBuyBillData()
    : ASBillData(2), m_n50(0), m_n58(0), m_b70(0), m_n74(-1), m_n78(0)
{
}

// @0x140e70310
ASMeratMarketBuyBillData::~ASMeratMarketBuyBillData()
{
    m_spProduct = 0;
    m_spPremium = 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142ca72a0-0x142ca73c0 .text$yd
