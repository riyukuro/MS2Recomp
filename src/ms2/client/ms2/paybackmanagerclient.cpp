// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). PaybackManagerClient: the client side of the merat payback
// event (level / merat of the 0x12d packet, the sorted product list, the payback button and the period text), followed by
// the template glue of its std::vector<MS2Ptr<CMeratMarketProduct> > and std::sort. See paybackmanagerclient.h.
// MS2-UNIT: ?\paybackmanagerclient.cpp
// MS2-RANGE: 0x140a8af50-0x140a8f1d0 .text$mn
// MS2-RANGE: 0x1400c4c50-0x1400c4e10 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?GetSize@?$CSimpleArray@GV?$CSimpleArrayEqualHelper@G@ATL@@@ATL@@QEBAHXZ 0x140a8b320 ; unique
// MS2-PIN: ??0?$MS2Ptr@VASMeratMarketBuyBillData@@@@QEAA@PEAVASMeratMarketBuyBillData@@@Z 0x140a8df50 ; unique
// MS2-PIN: ??0?$MS2Ptr@VCMeratMarketProduct@@@@QEAA@PEAVCMeratMarketProduct@@@Z 0x140a8df80 ; prop
// MS2-PIN: ??1?$MS2Ptr@VASMeratMarketBuyBillData@@@@QEAA@XZ 0x140a8e180 ; unique
// MS2-PIN: ??8?$MS2Ptr@VASMeratMarketBuyBillData@@@@QEBA_NPEAVASMeratMarketBuyBillData@@@Z 0x140a8e2b0 ; unique
// MS2-PIN: ??C?$MS2Ptr@VTMarketBillDataParam@@@@QEBAPEAVTMarketBillDataParam@@XZ 0x140a8e380 ; unique
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VASBillData@@@@V?$CElementTraits@V?$MS2Ptr@VASBillData@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VASBillData@@@@_K@Z 0x140a8e4a0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VCMeratMarketProduct@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VCMeratMarketProduct@@@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$MS2Ptr@VCMeratMarketProduct@@@@@2@XZ 0x140a8e810 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\paybackmanagerclient.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "paybackmanagerclient.h"
#include "ms2/placeholder/asmeratmarketbuybilldata.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/paybacktable.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <vector>

MS2_EMIT_CRT_MEMMOVE_S();

// ---- statics of the market's shared headers (the two sort name tables, then the key controller) ----

static CString s_strSortTypeNamesBuy[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static UICommon::CMyPCKeyInputController s_keyInputController;

// ---- unit-local views of exe objects ----

// The payback dialog (UI id 0x4f93); only its payback-changed hook is called here.
class UIPaybackDialog : public UIDialog
{
public:
    void FUN_140e6f820(int nOldLevel, unsigned nOldMerat);          // 0x140e6f820 the level / merat changed
};

// The reference the UI manager hands out for a dialog (16 bytes, object at +8).
class Unk_PbUIRef
{
public:
    ~Unk_PbUIRef();                                                 // 0x1403e5630
    UIObject* FUN_1403e8a70() const;
private:
    void* unknown;
    UIObject* object;
};
MS2_CHECK_SIZE(Unk_PbUIRef, 0x10);
UIObject* FUN_1403ed9e0(Unk_PbUIRef& rRef);

// The UI manager.
class Unk_PbUiMgr
{
public:
    void FUN_141adc5d0(int nId);                                    // close a dialog (if open)
    void FUN_141adc750(int nId);                                    // toggle a dialog
    Unk_PbUIRef FUN_141adcea0(int nId);                             // object by class id
};
Unk_PbUiMgr* FUN_1403ed2b0();

// The events of the game (a closed event is not running).
class Unk_PbEventMgr { public: bool FUN_140cead80(CStringW strEvent); };
Unk_PbEventMgr* FUN_14015a050();

// The blocked-action flags of the client config.
class Unk_PbFlagSet { public: int FUN_1402c4c90(int nFlag); };
struct Unk_PbConfig
{
    void* m_p00;
    Unk_PbFlagSet m_flags;                                          // +0x08
};
Unk_PbConfig* FUN_14025e7b0();

// What the 0x12d packet starts with: the level and the merat.
struct Unk_1407a9690
{
    Unk_1407a9690();
    int m_00;
    unsigned __int64 m_08;
};
void FUN_1407a9710(Unk_1407a9690& v, CInPacket& in);

CFeatureManager* FUN_140166410();                                   // the game settings (feature switches)
PaybackTable* FUN_14071d7d0();                                      // the payback table
PaybackManagerClient* FUN_1409c1740();                              // the payback manager
CStringW FUN_140298ea0(CStringW strKey);                            // string table text
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);   // notice by string id
void FUN_141275260(int nStringId, int nA, int nB);                  // notice by string id
__int64 FUN_140869440();                                            // the server clock
__int64 FUN_14086b380(__int64 nTime);                               // midnight of the day
int FUN_14086b490(int year, int month);                             // days of the month
struct Unk_PbMember { Scaleform::GFx::Value FUN_1422baa20(const char* szMember); }; // child member by name
unsigned char FUN_1409b0390(Scaleform::GFx::Value* pValue);         // value is undefined
int FUN_1409c17e0(const Scaleform::GFx::Value& v);

bool FUN_140a8c0c0(const MS2Ptr<CMeratMarketProduct>& lhs, const MS2Ptr<CMeratMarketProduct>& rhs);
UIPaybackDialog* FUN_140a8c5f0(int nId);

// @0x140a8af50
PaybackManagerClient::PaybackManagerClient()
    : m_nLevel(0), m_nMerat(0)
{
}

// MS2-FUNCTIONAL: frame layout differs (status local at a different stack slot); behaviour equivalent
// @0x140a8afb0
void PaybackManagerClient::FUN_140a8afb0(CInPacket& packet)
{
    if (!FUN_140166410()->FUN_14036d570(0x109))
        return;
    {
        unsigned char nKind = packet.vfunc_o8_1();
        switch (nKind)
        {
        case 0:
        {
            int nOldLevel = m_nLevel;
            unsigned nOldMerat = m_nMerat;
            Unk_1407a9690 status;
            FUN_1407a9710(status, packet);
            m_nLevel = status.m_00;
            m_nMerat = (unsigned)status.m_08;
            if (!FUN_1409c1740()->FUN_140a8be20(0))
                FUN_1403ed2b0()->FUN_141adc5d0(0x4f93);
            else
            {
                UIPaybackDialog* pDialog = FUN_140a8c5f0(0x4f93);
                if (pDialog != 0)
                    pDialog->FUN_140e6f820(nOldLevel, nOldMerat);
            }
            break;
        }
        case 1:
        {
            m_products.clear();
            unsigned nCount = packet.vfunc_o8_3();
            for (unsigned i = 0; i < nCount; ++i)
            {
                m_products.push_back(MS2Ptr<CMeratMarketProduct>(new CMeratMarketProduct(packet)));
            }
            std::sort(m_products.begin(), m_products.end(), FUN_140a8c0c0);
            break;
        }
        }
    }
}

// @0x140a8b240
void PaybackManagerClient::FUN_140a8b240(CStringW& strButton, bool& bShow)
{
    if (!FUN_140a8be20(0))
        return;
    strButton = L"$s_meratmarket_btn_payback";
    bShow = true;
}

// @0x140a8b290
void PaybackManagerClient::FUN_140a8b290()
{
    if (!FUN_140a8be20(1))
        return;
    if (FUN_14071d7d0()->IsResetWindow() == 1)
        FUN_140d73bc0(0xd4f, 0, 0, CStringW(L""));
    else
        FUN_1403ed2b0()->FUN_141adc750(0x4f93);
}

// @0x140a8b340
unsigned PaybackManagerClient::GetMerat() const
{
    return m_nMerat;
}

// @0x140a8b360
MS2Ptr<CMeratMarketProduct> PaybackManagerClient::FUN_140a8b360() const
{
    if (!FUN_140166410()->FUN_14036d570(0x109))
        return MS2Ptr<CMeratMarketProduct>(0);
    for (ProductVector::const_iterator it = m_products.begin(); it != m_products.end(); it++)
    {
        if ((*it)->m_premium.IsNotSelling(0))
            continue;
        return *it;
    }
    return MS2Ptr<CMeratMarketProduct>(0);
}

// MS2-FUNCTIONAL: temp/frame layout and smart-pointer temp order differ; behaviour equivalent
// @0x140a8b490
void PaybackManagerClient::FUN_140a8b490(MS2Ptr<TMarketBillDataParam> spParam)
{
    if (!FUN_140a8be20(0))
        return;
    if (m_products.empty())
        return;
    MS2Ptr<CMeratMarketProduct> spFirst = FUN_140a8b360();
    if (spFirst == 0)
        return;
    if (spParam == 0)
        return;
    if (spParam->m_bills.IsEmpty())
        return;
    for (size_t i = 0; i < spParam->m_bills.GetCount(); i++)
    {
        MS2Ptr<ASBillData> spBill = spParam->m_bills[i];
        if (spBill == 0)
            continue;
        MS2Ptr<ASMeratMarketBuyBillData> spBuy(dynamic_cast<ASMeratMarketBuyBillData*>(spBill.get()));
        if (spBuy == 0)
            continue;
        Scaleform::GFx::Value serial = reinterpret_cast<Unk_PbMember*>(spBill.operator->())->FUN_1422baa20("serialID");
        if (FUN_1409b0390(&serial) == 0)
        {
            int nSerial = FUN_1409c17e0(serial);
            if (nSerial == spFirst->m_premium.m_nId)
            {
                if (spBuy->vfunc_4() == 3)
                {
                    spParam->m_str70 = FUN_140298ea0(CStringW(L"s_payback_bill_bottom_detail_text"));
                    break;
                }
            }
        }
        if (spBuy->FUN_140a8e4e0() == 0)
            continue;
        MS2Ptr<CMeratMarketProduct> spProduct = spBuy->FUN_140a8e4e0();
        if (spProduct->m_premium.m_nId == spFirst->m_premium.m_nId)
        {
            if (spBuy->vfunc_4() == 3)
            {
                spParam->m_str70 = FUN_140298ea0(CStringW(L"s_payback_bill_bottom_detail_text"));
                break;
            }
        }
    }
}

// @0x140a8ba00
CStringW PaybackManagerClient::FUN_140a8ba00()
{
    CMsTime now(FUN_140869440());
    int nYear = now.GetYear();
    int nMonth = now.GetMonth();
    int nDay = 1;
    int nEndYear = now.GetYear();
    int nEndMonth = now.GetMonth();
    int nEndDay = FUN_14086b490(now.GetYear(), now.GetMonth());
    if (FUN_14071d7d0()->GetStartTime() != 0)
    {
        CMsTime start(FUN_14071d7d0()->GetStartTime());
        CMsTime end(FUN_14086b380(FUN_14071d7d0()->GetStartTime()));
        if (now.GetYear() == start.GetYear() && now.GetMonth() == start.GetMonth())
        {
            nDay = start.GetDay();
            nEndYear = end.GetYear();
            nEndMonth = end.GetMonth();
            nEndDay = FUN_14086b490(end.GetYear(), end.GetMonth());
        }
        else if (now.GetYear() == end.GetYear() && now.GetMonth() == end.GetMonth())
        {
            nYear = start.GetYear();
            nMonth = start.GetMonth();
            nDay = start.GetDay();
        }
    }
    return FUN_14028dfa0(CStringW(L"s_payback_dialog_period"), nYear, nMonth, nDay, nEndYear, nEndMonth, nEndDay);
}

// @0x140a8bcc0
bool PaybackManagerClient::FUN_140a8bcc0(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (!FUN_140166410()->FUN_14036d570(0x109))
        return false;
    if (spProduct == 0)
        return false;
    if (!FUN_140a8bf50(spProduct))
        return false;
    if (!FUN_14071d7d0()->IsResetWindow())
        return false;
    FUN_140d73bc0(0xd4f, 0, 0, CStringW(L""));
    return true;
}

// @0x140a8be20
bool PaybackManagerClient::FUN_140a8be20(unsigned char bNotify)
{
    if (!FUN_140a8be80(bNotify))
        return false;
    if (!FUN_14071d7d0()->InPeriod(FUN_140869440()))
        return false;
    return true;
}

// @0x140a8be80
bool PaybackManagerClient::FUN_140a8be80(unsigned char bNotify)
{
    if (!FUN_140166410()->FUN_14036d570(0x109))
        return false;
    if (!FUN_14015a050()->FUN_140cead80(CStringW(L"FinishPayback")))
        return false;
    if (FUN_14025e7b0()->m_flags.FUN_1402c4c90(0x6f) != 0)
    {
        if (bNotify != 0)
            FUN_141275260(0x2f7, 1, 1);
        return false;
    }
    return true;
}

// @0x140a8bf50
bool PaybackManagerClient::FUN_140a8bf50(MS2Ptr<CMeratMarketProduct> spProduct) const
{
    if (!FUN_140166410()->FUN_14036d570(0x109))
        return false;
    if (spProduct == 0)
        return false;
    if (spProduct->m_premium.IsNotSelling(0))
        return false;
    for (ProductVector::const_iterator it = m_products.begin(); it != m_products.end(); it++)
    {
        if ((*it)->m_premium.m_nId == spProduct->m_premium.m_nId)
            return true;
    }
    return false;
}

// @0x140a8c0c0 the products by their start date
bool FUN_140a8c0c0(const MS2Ptr<CMeratMarketProduct>& lhs, const MS2Ptr<CMeratMarketProduct>& rhs)
{
    return lhs->m_premium.m_startDate < rhs->m_premium.m_startDate;
}

// @0x140a8c5f0 the payback dialog, if it is open
UIPaybackDialog* FUN_140a8c5f0(int nId)
{
    if (FUN_1403ed2b0())
    {
        Unk_PbUIRef ref = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (ref.FUN_1403e8a70())
            return dynamic_cast<UIPaybackDialog*>(FUN_1403ed9e0(ref));
    }
    return 0;
}

MS2_REPLACE_METHOD(0x140A8AFB0, PaybackManagerClient, FUN_140a8afb0, 640, 0x6AD27234);
MS2_REPLACE_METHOD(0x140A8B490, PaybackManagerClient, FUN_140a8b490, 1382, 0xA2727696);
MS2_REPLACE_METHOD(0x140A8B240, PaybackManagerClient, FUN_140a8b240, 71, 0x9AE2BB34);
MS2_REPLACE_METHOD(0x140A8B290, PaybackManagerClient, FUN_140a8b290, 129, 0x0F49EC32);
MS2_REPLACE_METHOD(0x140A8B340, PaybackManagerClient, GetMerat, 14, 0xAAC7684B);
MS2_REPLACE_METHOD(0x140A8B360, PaybackManagerClient, FUN_140a8b360, 279, 0x2D2911F8);
MS2_REPLACE_METHOD(0x140A8BA00, PaybackManagerClient, FUN_140a8ba00, 689, 0x75A28861);
MS2_REPLACE_METHOD(0x140A8BCC0, PaybackManagerClient, FUN_140a8bcc0, 335, 0x0FAD4756);
MS2_REPLACE_METHOD(0x140A8BE20, PaybackManagerClient, FUN_140a8be20, 88, 0x4E7C3E13);
MS2_REPLACE_METHOD(0x140A8BE80, PaybackManagerClient, FUN_140a8be80, 194, 0x56B32531);
MS2_REPLACE_METHOD(0x140A8BF50, PaybackManagerClient, FUN_140a8bf50, 355, 0x5EDCF4BB);
MS2_REPLACE(0x140A8C0C0, FUN_140a8c0c0, 72, 0x310D5C05);
MS2_REPLACE(0x140A8C5F0, FUN_140a8c5f0, 147, 0xB8E36C24);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9f980-0x142c9fa00 .text$yd
