// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMarketBillDialog: the purchase bill of the merat market /
// cash shop. See uimarketbilldialog.h.
// MS2-UNIT: ?\uimarketbilldialog.cpp
// MS2-GUESS-LOOKALIKES (CAtlArray::GetAt / operator[] of the bill rows are byte-identical)
// MS2-RANGE: 0x140ea6ee0-0x140eadd70 .text$mn
// MS2-RANGE: 0x1400dbd70-0x1400dc070 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ?get@?$MS2Ptr@VTMarketBillDataParam@@@@QEBAPEAVTMarketBillDataParam@@XZ 0x140eac460 ; unique
// MS2-PIN: ?FUN_140eacad0@UIMarketBillDialog@@QEAAHXZ 0x140eacad0 ; unique
// MS2-PIN: ?FUN_140eacf20@ASBillData@@QEBA_NXZ 0x140eacf20 ; unique
// MS2-PIN: ?FUN_140eacf60@ASBillData@@QEBA_NXZ 0x140eacf60 ; unique
// MS2-PIN: ?FUN_140eacf70@TMeratMarketBillDataParam@@QEBA_NXZ 0x140eacf70 ; unique
// MS2-PIN: ?FUN_140eacfc0@TMarketBillDataParam@@QEBA_NXZ 0x140eacfc0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIMarketBillDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140eadab0 ; unique
// MS2-PIN: ??$Call@VUIMarketBillDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIMarketBillDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIMarketBillDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140eadaf0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimarketbilldialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uimarketbilldialog.h"
#include "tmeratmarketbilldataparam.h"
#include "uimessageboxdata.h"
#include "mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/asbilldata.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <vector>

MS2_EMIT_CRT_MEMMOVE_S();

// ---- statics of the market's shared headers (init order: the two sort name tables, skill / stun / the condition map, the
// key controller, then three attribute names) ----

static CString s_strSortTypeNamesBuy[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";

// ---- unit-local views of exe objects ----

// The movie root of the dialog (RTTI .?AVASDialog@@; the type of UIDialog::m_90). Only the "height" accessors and slot 24
// (re-layout) are called here.
class ASDialog : public ASDisplayObject
{
public:
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24(bool b);                          // 24 0xc0 re-layout
    float FUN_1422c1490();                                  // height
    void FUN_1422c0f20(float fHeight);                      // set the height
};

// The AS array of the bill rows (ctor 0x1422deec0, dtor 0x1422df070).
class Unk_MbRows : public AScript
{
public:
    Unk_MbRows(int nType);
    virtual ~Unk_MbRows();
    bool FUN_1422bc050(Scaleform::GFx::Value v);            // push
};

// An item reference (16 bytes; released by 0x1401b50d0).
class Unk_MbItemRef;
void FUN_1401b50d0(Unk_MbItemRef*);
class Unk_MbItemRef
{
public:
    ~Unk_MbItemRef() { FUN_1401b50d0(this); }
    void* FUN_140203c60() const;                            // the item is known
    CItemData* FUN_1401b52a0() const;                       // the item's table row
private:
    void* m_00;
    void* m_08;
};
MS2_CHECK_SIZE(Unk_MbItemRef, 0x10);
Unk_MbItemRef FUN_14053f870(int nItemId);

// The locked-item view of an item reference (24 bytes).
struct Unk_MbLockView
{
    void* m_p[3];
};
Unk_MbLockView FUN_1403bb3b0(const Unk_MbItemRef& ref);
int FUN_1418ffba0(const Unk_MbLockView& view);                  // the item is locked

// The purchase block notice (the state manager answers whether buying is blocked right now).
struct Unk_MbBlockRef;
void FUN_1401cb250(Unk_MbBlockRef*);
struct Unk_MbBlockRef
{
    void* m_00;
    void* m_08;
    ~Unk_MbBlockRef() { FUN_1401cb250(this); }
};
MS2_CHECK_SIZE(Unk_MbBlockRef, 0x10);
class Unk_MbStateMgr;
Unk_MbStateMgr* FUN_140a6a830();
void FUN_140a2f620(Unk_MbStateMgr* pMgr, Unk_MbBlockRef* pOut, int nKind);
void* FUN_1401cb3d0(Unk_MbBlockRef* pRef);
void FUN_140a2ff20(Unk_MbBlockRef* pRef, int nKind, __int64 n);

class Unk_MbUiMgr { public: void FUN_141adc5d0(int uiId); };
Unk_MbUiMgr* FUN_1403ed2b0();
class Unk_MbKeys { public: bool FUN_14116d9c0(int nKey, int a, int b); };
Unk_MbKeys* FUN_14025e7c0();
class Unk_MbFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_MbFeatures* FUN_140166410();
class Unk_MbBlockList { public: unsigned FUN_140ae5240(const CStringW& strName); };
Unk_MbBlockList* FUN_14097a780();
class Unk_MbBillMgr { public: void FUN_140a8b490(MS2Ptr<TMarketBillDataParam> spParam); };
Unk_MbBillMgr* FUN_1409c1740();
void* FUN_1403ed2d0();
void* FUN_141bd0cc0(void* pWorld);                              // the local player

bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released
const float& FUN_140805fc0(const float& a, const float& b);     // max
bool FUN_1403b3c40(const CStringW& str, const wchar_t* sz);   // string equals (no case)
void FUN_1405625e0();                                           // throws: the delegate is empty

CStringW FUN_1418fe5d0(unsigned int nPayType);                  // pay type name
CStringW FUN_1418fe6c0(int nPayType, int nFlag);                // pay type name (flag -1 / 0)
CStringW FUN_1418fec00(int nType, __int64 nValue, int);         // money text by pay type
CStringW FUN_1418fec00(int nType, __int64 nValue, int, int);
CStringW FUN_1409404f0(__int64 n);
CStringW FUN_1409e97f0(int nId, const unsigned& nArg);          // string table entry, one argument
CStringW FUN_14028b8e0(const CStringW& strKey);                 // string table text
CStringW FUN_14028de60(int nStringId);
CStringW FUN_14052bd00(int nId, const CStringW& strArg);
CStringW FUN_140632a60(int nId, const CStringW& strArg0, const CStringW& strArg1);
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);
int FUN_1406a6140();                                            // the pay type of the blueprint rows
void FUN_140930590(__int64 nId, std::vector<std::pair<int, __int64> >& vecOut);
void FUN_140930750(const std::vector<std::pair<int, __int64> >& vecIn, std::vector<std::pair<int, __int64> >& vecOut);

MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStrId, void* pListener, CStringW strExtra);
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW strText);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_140d73bc0(int nTable, int nId, void* pListener, CStringW strExtra);    // pop the system message nTable
void FUN_140d73aa0(CStringW strText, int n, void* pListener, CStringW strExtra);

// ---- the pay type text helpers ----

// One pay type row of a vector of (pay type, amount): the name and the amount text.
// @0x140eabae0
bool FUN_140eabae0(const std::pair<int, __int64>* pEntry, CStringW* pstrName, CStringW* pstrAmount)
{
    int nPayType = pEntry->first;
    __int64 nAmount = pEntry->second;
    *pstrName = FUN_1418fe5d0(nPayType);
    *pstrAmount = FUN_14052bd00(0x987, FUN_1409404f0(nAmount));
    return !pstrName->IsEmpty();
}

// The rows of a pay type pool (the pay type 3 entries), one per line.
// @0x140eabc00
bool FUN_140eabc00(CStringW* pstrNames, CStringW* pstrAmounts, __int64 nPoolId)
{
    std::vector<std::pair<int, __int64> > vecRows;
    FUN_140930590(nPoolId, vecRows);
    size_t nCount = vecRows.size();
    CStringW strNames;
    CStringW strAmounts;
    for (size_t i = 0; i < nCount; ++i)
    {
        const std::pair<int, __int64>* pRow = &vecRows[i];
        CStringW strName;
        CStringW strAmount;
        if (FUN_140eabae0(pRow, &strName, &strAmount))
        {
            if (!strNames.IsEmpty())
                strNames.Append(L"\n");
            strNames.Append(strName);
            if (!strAmounts.IsEmpty())
                strAmounts.Append(L"\n");
            strAmounts.Append(strAmount);
        }
    }
    *pstrNames = strNames;
    *pstrAmounts = strAmounts;
    return true;
}

// The same for a given list of rows (the blueprint pay types).
// @0x140eabdc0
bool FUN_140eabdc0(CStringW* pstrNames, CStringW* pstrAmounts, const std::vector<std::pair<int, __int64> >& vecIn)
{
    std::vector<std::pair<int, __int64> > vecRows;
    FUN_140930750(vecIn, vecRows);
    size_t nCount = vecRows.size();
    CStringW strNames;
    CStringW strAmounts;
    for (size_t i = 0; i < nCount; ++i)
    {
        const std::pair<int, __int64>* pRow = &vecRows[i];
        CStringW strName;
        CStringW strAmount;
        if (FUN_140eabae0(pRow, &strName, &strAmount))
        {
            if (!strNames.IsEmpty())
                strNames.Append(L"\n");
            strNames.Append(strName);
            if (!strAmounts.IsEmpty())
                strAmounts.Append(L"\n");
            strAmounts.Append(strAmount);
        }
    }
    *pstrNames = strNames;
    *pstrAmounts = strAmounts;
    return true;
}

// ---- Delegate call operators (the null check throws) ----

// @0x140eac510
template <>
bool Delegate<bool(MS2Ptr<TMarketBillDataParam>)>::operator()(MS2Ptr<TMarketBillDataParam> a1) const
{
    if (!m_pImpl)
        FUN_1405625e0();
    return m_pImpl->vfunc_2(a1);
}

// @0x140eac590 (the generic two-argument operator() has no null check)
template <>
bool Delegate<bool(MS2Ptr<TMarketBillDataParam>, const ATL::CAtlMap<ePayType, __int64>&)>::operator()(
    MS2Ptr<TMarketBillDataParam> a1, const ATL::CAtlMap<ePayType, __int64>& a2) const
{
    if (!m_pImpl)
        FUN_1405625e0();
    return m_pImpl->Invoke(a1, a2);
}

// @0x140eac620
template <>
bool Delegate<bool(MS2Ptr<TMarketBillDataParam>, const ATL::CAtlMap<ePayType, __int64>&, const CStringW&, const CStringW&)>::operator()(
    MS2Ptr<TMarketBillDataParam> a1, const ATL::CAtlMap<ePayType, __int64>& a2, const CStringW& a3, const CStringW& a4) const
{
    if (!m_pImpl)
        FUN_1405625e0();
    return m_pImpl->vfunc_2(a1, a2, a3, a4);
}

// @0x140eac480
bool Delegate<bool(Scaleform::GFx::Value*, ASData&, MS2Ptr<TMarketBillDataParam>)>::operator()(
    Scaleform::GFx::Value* a1, ASData& a2, MS2Ptr<TMarketBillDataParam> a3) const
{
    if (!m_pImpl)
        FUN_1405625e0();
    return m_pImpl->vfunc_2(a1, a2, a3);
}

// ---- TMarketBillDataParam (the members whose definitions sit in this unit) ----

// @0x140eab940
void TMarketBillDataParam::FUN_140eab940(bool b)
{
    m_b2c = FUN_140166410()->FUN_14036d570(0x45) && b;
}

// @0x140eab9a0
void TMarketBillDataParam::FUN_140eab9a0(unsigned __int64 n)
{
    m_b2d = true;
    m_n30 = n;
}

// @0x140eab9d0
void TMarketBillDataParam::FUN_140eab9d0(int n, unsigned __int64 v)
{
    m_n38 = n;
    m_n40 = v;
}

// @0x140eaba00
MS2Ptr<ASBillData> TMarketBillDataParam::FUN_140eaba00(int nIndex)
{
    if (m_bills.IsEmpty())
        return MS2Ptr<ASBillData>(0);
    int nCount = (int)m_bills.GetCount();
    if (nIndex < 0 || nIndex >= nCount)
        return MS2Ptr<ASBillData>(0);
    return m_bills.GetAt(nIndex);
}

// ---- UIMarketBillDialog ----

// @0x140ea6ee0
UIMarketBillDialog::UIMarketBillDialog()
    : m_nMode(0)
    , m_mapPrice(17, 0.75f, 0.25f, 2.25f, 10)
    , m_mapPayback(17, 0.75f, 0.25f, 2.25f, 10)
    , m_mapRandomPayback(17, 0.75f, 0.25f, 2.25f, 10)
    , m_nTotal(0)
    , m_bBlueprint(false)
{
    FUN_141924170(1);
    FUN_1422dc3b0(1);
}

// @0x140ea7050
UIMarketBillDialog::~UIMarketBillDialog()
{
    m_spParam = 0;
}

// @0x140ea7100
CString UIMarketBillDialog::GetTypeName()
{
    return CString("MarketBillDialog");
}

// @0x140ea7150
void UIMarketBillDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
    m_nMode = 0;
    m_spParam = 0;
    m_nTotal = 0;
    m_mapPrice.RemoveAll();
    m_mapPayback.RemoveAll();
    m_mapRandomPayback.RemoveAll();
    m_bBlueprint = false;
}

// @0x140ea71f0
int UIMarketBillDialog::vfunc_65()
{
    return UIDialog::vfunc_65();
}

// @0x140ea7210
void UIMarketBillDialog::vfunc_26()
{
    UIDialog::vfunc_26();
}

// @0x140ea7230
void UIMarketBillDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    UIObject::vfunc_45(pRetVal, strMethod, pArgs);
}

// @0x140ea7270
int UIMarketBillDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (FUN_140ba28d0(&m_30, 0))
        return 0;
    if (!FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0))
        return 0;
    m_30->Invoke("onTabKey");
    return 1;
}

// @0x140ea7310
void UIMarketBillDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    if (m_spParam == 0)
        vfunc_67();
    SetMode(m_spParam->m_nType);
    FUN_140ea8df0();
}

// @0x140ea7390
int UIMarketBillDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("onClickBuy", szMethod) == 0)
    {
        if (FUN_140eacad0() == 4)
        {
            FUN_140ea9fc0();
        }
        else
        {
            {
                Unk_MbBlockRef block;
                FUN_140a2f620(FUN_140a6a830(), &block, 0x26);
                if (FUN_1401cb3d0(&block))
                {
                    FUN_140a2ff20(&block, 0x26, 0);
                    return 1;
                }
            }
            FUN_140eaa0b0(szMethod);
        }
        return 1;
    }
    if (_stricmp("onClickGiftOk", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140eaa1e0(szMethod, &data);
        return 1;
    }
    if (_stricmp("onUpdateTotalPrice", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140eaa5e0(&data);
        return 1;
    }
    if (_stricmp("onChangeMode", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140eaa860(&data);
        return 1;
    }
    return 0;
}

// @0x140ea7630
void UIMarketBillDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    if (!(!FUN_140ba28d0(&m_30, 0) && !(m_spParam == 0)))
        return;
    if (!m_spParam->m_dgTooltip.IsNull())
        m_spParam->m_dgTooltip(pRetVal, *pArgs, m_spParam);
}

// @0x140eacd00
int UIMarketBillDialog::vfunc_48()
{
    return 0x4f17;
}

// @0x140ea7730
void UIMarketBillDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    if (m_bDirty)
        FUN_140ea7900();
}

// Take a new parameter and its fixed sums.
// @0x140ea7770
void UIMarketBillDialog::FUN_140ea7770(MS2Ptr<TMarketBillDataParam> spParam)
{
    m_spParam = spParam;
    m_nTotal = 0;
    m_mapPrice.RemoveAll();
    m_mapRandomPayback.RemoveAll();
    if (!(m_spParam.get()))
        return;
    if (!(m_spParam->FUN_140eacfc0()))
        return;
    m_mapPrice.SetAt((ePayType)m_spParam->m_nCurrency, m_spParam->m_n30);
    m_nTotal = m_spParam->m_n30;
    m_mapPayback.SetAt((ePayType)m_spParam->m_n38, m_spParam->m_n40);
}

// Write the fee / payback texts and grow the movie by the lines they gained.
// @0x140ea7900
void UIMarketBillDialog::FUN_140ea7900()
{
    if (FUN_140ba28d0(&m_30, 0))
        return;
    int nMode = FUN_140eacad0();
    if (nMode == 4 || nMode == 0)
    {
        m_bDirty = false;
        return;
    }
    float fGrow = 0.0f;
    MS2Ptr<ASTextField> spFee = m_30->FUN_1409b4620(CString("m_totalFee"));
    MS2Ptr<ASTextField> spFeeText = m_30->FUN_1409b4620(CString("m_totalFeeText"));
    if (spFee.get() && spFeeText.get())
        fGrow = FUN_140ea7e70(spFee, spFeeText, m_mapPrice);
    MS2Ptr<ASTextField> spPayback = m_30->FUN_1409b4620(CString("m_totalPayback"));
    MS2Ptr<ASTextField> spPaybackText = m_30->FUN_1409b4620(CString("m_totalPaybackText"));
    if (spPayback.get() && spPaybackText.get())
    {
        bool bAny = false;
        for (POSITION pos = m_mapRandomPayback.GetStartPosition(); pos; m_mapRandomPayback.GetNext(pos))
        {
            if (m_mapRandomPayback.GetValueAt(pos) != 0)
            {
                bAny = true;
                break;
            }
        }
        spPayback->vfunc_4(bAny);
        spPaybackText->vfunc_4(bAny);
        if (bAny)
        {
            float fGrowPayback = FUN_140ea8ab0(spPayback, spPaybackText, m_mapRandomPayback);
            fGrow = FUN_140805fc0(fGrow, fGrowPayback);
        }
    }
    if (m_90.get() && fGrow != 0.0f)
    {
        float fHeight = m_90->FUN_1422c1490();
        m_90->FUN_1422c0f20(fHeight + fGrow);
        m_90->vfunc_24(true);
    }
    m_bDirty = false;
}

// Fill the fee texts (names and amounts, one pay type per line); the height they gained.
// @0x140ea7e70
float UIMarketBillDialog::FUN_140ea7e70(MS2Ptr<ASTextField> spFee, MS2Ptr<ASTextField> spFeeText, const PaymentMap& mapPay)
{
    int nOldHeight = spFee->FUN_1422c13b0();
    CStringW strNames;
    CStringW strAmounts;
    CStringW strTotals;
    int nLines = 0;
    CStringW strLf(L"\n");
    for (POSITION pos = mapPay.GetStartPosition(); pos; mapPay.GetNext(pos))
    {
        int nPayType = mapPay.GetKeyAt(pos);
        __int64 nValue = mapPay.GetValueAt(pos);
        if (nPayType == 3)
        {
            CStringW strPoolNames;
            CStringW strPoolAmounts;
            if (!m_bBlueprint)
            {
                FUN_140eabc00(&strPoolNames, &strPoolAmounts, nValue);
            }
            else
            {
                int nKey = FUN_1406a6140();
                std::vector<std::pair<int, __int64> > vecRows;
                vecRows.push_back(std::make_pair(nKey, nValue));
                FUN_140eabdc0(&strPoolNames, &strPoolAmounts, vecRows);
            }
            strNames.Append(strPoolNames);
            strAmounts.Append(strPoolAmounts);
        }
        else
        {
            if (!strNames.IsEmpty())
                strNames.Append(strLf);
            strNames.Append(FUN_1418fe6c0(nPayType, -1));
            if (!strAmounts.IsEmpty())
                strAmounts.Append(strLf);
            strAmounts.Append(FUN_1418fec00(nPayType, nValue, 0));
        }
        if (!strTotals.IsEmpty())
            strTotals.Append(strLf);
        strTotals.Append(FUN_1418fec00(nPayType, nValue, 0));
        ++nLines;
    }
    if (strTotals.IsEmpty())
    {
        int nCurrency = m_spParam.get() ? m_spParam->m_nCurrency : 1;
        strNames.Append(FUN_1418fe6c0(nCurrency, -1));
        strAmounts.Append(FUN_1418fec00(nCurrency, 0, 0));
        strTotals = FUN_1418fec00(nCurrency, 0, 0);
        ++nLines;
    }
    CStringW strNameText = FUN_14052bd00(0x998, strNames);
    CStringW strAmountText = FUN_140632a60(0x999, strAmounts, strTotals);
    for (int i = 0; i < nLines - 1; ++i)
        strNameText.Append(strLf);
    CStringW strGiveNames;
    CStringW strGiveAmounts;
    if (!m_mapPayback.IsEmpty())
    {
        for (POSITION pos = m_mapPayback.GetStartPosition(); pos; m_mapPayback.GetNext(pos))
        {
            int nPayType = m_mapPayback.GetKeyAt(pos);
            __int64 nValue = m_mapPayback.GetValueAt(pos);
            if (nValue > 0)
            {
                if (!strGiveNames.IsEmpty())
                    strGiveNames.Append(strLf);
                strGiveNames.Append(FUN_1418fe6c0(nPayType, -1));
                if (!strGiveAmounts.IsEmpty())
                    strGiveAmounts.Append(strLf);
                strGiveAmounts.Append(FUN_1418fec00(nPayType, nValue, 0));
            }
        }
        if (!strGiveAmounts.IsEmpty())
        {
            strNameText.Append(strLf);
            strAmountText.Append(strLf);
            strNameText.Append(FUN_1405c2690(CStringW(L"s_bill_givename_total"), strGiveNames));
            strAmountText.Append(FUN_1405c2690(CStringW(L"s_bill_givepoint_total"), strGiveAmounts));
        }
    }
    spFeeText->FUN_1422c4f00(strNameText);
    spFee->FUN_1422c4f00(strAmountText);
    float fX = spFee->FUN_1422c10a0();
    spFeeText->FUN_1422c0420(fX);
    int nNewHeight = spFee->FUN_1422c13b0();
    return (float)(nNewHeight - nOldHeight);
}

// The same for the random payback (one line per pay type).
// @0x140ea8ab0
float UIMarketBillDialog::FUN_140ea8ab0(MS2Ptr<ASTextField> spPayback, MS2Ptr<ASTextField> spPaybackText, const PaymentMap& mapPay)
{
    int nOldHeight = spPayback->FUN_1422c13b0();
    CStringW strNames;
    CStringW strAmounts;
    CStringW strLf(L"\n");
    for (POSITION pos = mapPay.GetStartPosition(); pos; mapPay.GetNext(pos))
    {
        int nPayType = mapPay.GetKeyAt(pos);
        __int64 nValue = mapPay.GetValueAt(pos);
        if (!strNames.IsEmpty())
            strNames.Append(strLf);
        strNames.Append(FUN_1405c2690(CStringW(L"s_meratmarket_random_payback"), FUN_1418fe6c0(nPayType, 0)));
        if (!strAmounts.IsEmpty())
            strAmounts.Append(strLf);
        strAmounts.Append(FUN_1418fec00(nPayType, nValue, 0));
    }
    spPaybackText->FUN_1422c4f00(strNames);
    spPayback->FUN_1422c4f00(strAmounts);
    int nNewHeight = spPayback->FUN_1422c13b0();
    return (float)(nNewHeight - nOldHeight);
}

// A copy of the parameter.
// @0x140ea8da0
MS2Ptr<TMarketBillDataParam> UIMarketBillDialog::GetParam()
{
    return m_spParam;
}

// "initData": hand the bill rows and the texts to the movie.
// @0x140ea8df0
void UIMarketBillDialog::FUN_140ea8df0()
{
    int nMode = FUN_140eacad0();
    ASObj objData(2);
    Unk_MbRows rows(2);
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = m_spParam->m_bills;
    if (nMode == 4)
    {
        for (size_t i = 0; i < bills.GetCount(); ++i)
        {
            MS2Ptr<ASBillData> spBill = bills[i];
            if (!spBill.IsNull())
                rows.FUN_1422bc050(Scaleform::GFx::Value(spBill->FUN_1422bb870()));
        }
        objData.FUN_1409c0e60("noticeKey", L"$s_marketbill_notice_meratmarket_basket");
    }
    else
    {
        unsigned nCount = 0;
        for (size_t i = 0; i < bills.GetCount(); ++i)
        {
            MS2Ptr<ASBillData> spBill = bills[i];
            if (!spBill.IsNull())
            {
                rows.FUN_1422bc050(Scaleform::GFx::Value(spBill->FUN_1422bb870()));
                int nPayType = spBill->vfunc_4();
                FUN_140ea9770(nPayType, spBill->vfunc_2());
                FUN_140ea9880(nPayType, spBill->vfunc_9());
                int nPaybackType = spBill->vfunc_8();
                FUN_140ea9970(nPaybackType, spBill->vfunc_6());
                if (nPayType == 3)
                {
                    int nItemId = spBill->vfunc_1();
                    Unk_MbItemRef ref = FUN_14053f870(nItemId);
                    if (ref.FUN_140203c60())
                    {
                        if (ref.FUN_1401b52a0()->FUN_14053cd10())
                            m_bBlueprint = true;
                    }
                }
                if (!spBill->FUN_140eacf20())
                    ++nCount;
            }
        }
        CStringW strTotal = FUN_1409e97f0(0xa40, nCount);
        objData.FUN_1407cbb20("totalText", strTotal);
        CStringW strNotice;
        CStringW strNoticeGift;
        if (m_spParam->m_nDialogId != 0)
        {
            int nDialogId = m_spParam->m_nDialogId;
            if (nDialogId == 0x4ec1)
            {
                bool bGift = false;
                if (MS2Ptr<TMeratMarketBillDataParam> spMerat = dynamic_cast<TMeratMarketBillDataParam*>(m_spParam.get()))
                    bGift = spMerat->FUN_140eacf70();
                const wchar_t* szNotice = bGift ? L"$s_marketbill_notice_meratmarket" : L"$s_marketbill_notice_meratmarket_only_premium";
                strNotice = szNotice;
                strNoticeGift = strNotice;
            }
            else if (nDialogId == 0x4ebc)
            {
                strNotice = L"$s_marketbill_notice_cashshop";
                strNoticeGift = L"$s_marketbill_notice_cashshop_gift";
            }
        }
        objData.FUN_1407cbb20("noticeKey", strNotice);
        objData.FUN_1407cbb20("noticeGiftKey", strNoticeGift);
        objData.FUN_1407cbbe0("gift", m_spParam->m_b2c);
        FUN_1409c1740()->FUN_140a8b490(m_spParam);
        if (!m_spParam->m_str70.IsEmpty())
            objData.FUN_1407cbb20("additionalInfoDescText", m_spParam->m_str70);
    }
    objData.FUN_1409adbe0("dp", Scaleform::GFx::Value(rows.FUN_1422bb870()));
    objData.FUN_1407cba60("mode", FUN_140eaac50(m_spParam->m_nType));
    m_30->Invoke("initData", Scaleform::GFx::Value(objData.FUN_1422bb870()));
    FUN_140ea7900();
}

// The amount as text.
// @0x140ea9710
CStringW UIMarketBillDialog::FUN_140ea9710(int nPayType, __int64 nAmount)
{
    return FUN_1418fec00(nPayType, nAmount, 0, 0);
}

// Add to the price of a pay type (and the total).
// @0x140ea9770
void UIMarketBillDialog::FUN_140ea9770(int nPayType, __int64 nAmount)
{
    if (m_spParam.get() ? true : false)
    {
        if (m_spParam->FUN_140eacfc0())
            return;
    }
    __int64 nCurrent = 0;
    m_mapPrice.Lookup(reinterpret_cast<const ePayType&>(nPayType), nCurrent);
    nCurrent += nAmount;
    nCurrent = nCurrent > 0 ? nCurrent : 0;
    m_mapPrice.SetAt(reinterpret_cast<const ePayType&>(nPayType), nCurrent);
    m_nTotal += nAmount;
}

// Add to the random payback of a pay type.
// @0x140ea9880
void UIMarketBillDialog::FUN_140ea9880(int nPayType, __int64 nAmount)
{
    if (m_spParam.get() ? true : false)
    {
        if (m_spParam->FUN_140eacfc0())
            return;
    }
    __int64 nCurrent = 0;
    m_mapRandomPayback.Lookup(reinterpret_cast<const ePayType&>(nPayType), nCurrent);
    nCurrent += nAmount;
    nCurrent = nCurrent > 0 ? nCurrent : 0;
    m_mapRandomPayback.SetAt(reinterpret_cast<const ePayType&>(nPayType), nCurrent);
}

// Add to the payback of a pay type.
// @0x140ea9970
void UIMarketBillDialog::FUN_140ea9970(int nPayType, __int64 nAmount)
{
    if (m_spParam.get() ? true : false)
    {
        if (m_spParam->FUN_140eacfc0())
            return;
    }
    if (nPayType == 0x11)
        return;
    __int64 nCurrent = 0;
    m_mapPayback.Lookup(reinterpret_cast<const ePayType&>(nPayType), nCurrent);
    nCurrent += nAmount;
    nCurrent = nCurrent > 0 ? nCurrent : 0;
    m_mapPayback.SetAt(reinterpret_cast<const ePayType&>(nPayType), nCurrent);
}

// A row is a UGC map package.
// @0x140ea9a70
bool UIMarketBillDialog::FUN_140ea9a70()
{
    if (m_spParam == 0 || m_spParam->m_bills.IsEmpty())
        return false;
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = m_spParam->m_bills;
    size_t nCount = bills.GetCount();
    for (size_t i = 0; i < nCount; ++i)
    {
        MS2Ptr<ASBillData> spBill = bills.GetAt(i);
        if (spBill == 0)
            continue;
        int nItemId = spBill->vfunc_1();
        if (nItemId == 0)
            continue;
        Unk_MbItemRef ref = FUN_14053f870(nItemId);
        if (ref.FUN_140203c60())
        {
            CItemData* pItem = ref.FUN_1401b52a0();
            if (FUN_1403b3c40(pItem->function.name, L"UGCMapPackage"))
                return true;
        }
    }
    return false;
}

// A row is an item of the type.
// @0x140ea9c30
bool UIMarketBillDialog::FUN_140ea9c30(const int& nItemType)
{
    if (m_spParam == 0 || m_spParam->m_bills.IsEmpty())
        return false;
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = m_spParam->m_bills;
    size_t nCount = bills.GetCount();
    for (size_t i = 0; i < nCount; ++i)
    {
        MS2Ptr<ASBillData> spBill = bills.GetAt(i);
        if (spBill == 0)
            continue;
        int nItemId = spBill->vfunc_1();
        if (nItemId == 0)
            continue;
        Unk_MbItemRef ref = FUN_14053f870(nItemId);
        if (ref.FUN_140203c60())
        {
            if (ref.FUN_1401b52a0()->FUN_14053c5c0() == nItemType)
                return true;
        }
    }
    return false;
}

// A row is a locked item.
// @0x140ea9df0
bool UIMarketBillDialog::FUN_140ea9df0()
{
    if (m_spParam == 0 || m_spParam->m_bills.IsEmpty())
        return false;
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = m_spParam->m_bills;
    size_t nCount = bills.GetCount();
    for (size_t i = 0; i < nCount; ++i)
    {
        MS2Ptr<ASBillData> spBill = bills.GetAt(i);
        if (spBill == 0)
            continue;
        int nItemId = spBill->vfunc_1();
        if (nItemId == 0)
            continue;
        Unk_MbItemRef ref = FUN_14053f870(nItemId);
        if (ref.FUN_140203c60())
        {
            if (FUN_1418ffba0(FUN_1403bb3b0(ref)) != 0)
                return true;
        }
    }
    return false;
}

// "onClickBuy" in the basket mode.
// @0x140ea9fc0
void UIMarketBillDialog::FUN_140ea9fc0()
{
    if (m_spParam == 0)
        return;
    if (!m_spParam->m_dgCancel.IsNull())
        m_spParam->m_dgCancel(m_spParam);
    FUN_1403ed2b0()->FUN_141adc5d0(vfunc_48());
}

// "onClickBuy".
// @0x140eaa0b0
void UIMarketBillDialog::FUN_140eaa0b0(const char* szMethod)
{
    if (m_spParam == 0)
        return;
    bool bClose = true;
    if (!FUN_140eaad30(&bClose))
    {
        if (!m_spParam->m_dgBuy.IsNull())
            m_spParam->m_dgBuy(m_spParam, m_mapPrice);
    }
    if (bClose)
        FUN_1403ed2b0()->FUN_141adc5d0(vfunc_48());
}

// "onClickGiftOk".
// @0x140eaa1e0
void UIMarketBillDialog::FUN_140eaa1e0(const char* szMethod, ASData* pData)
{
    if (m_spParam == 0)
        return;
    CStringW strName = pData->FUN_1422b8f40();
    if (strName.GetLength() == 0)
    {
        FUN_140d73bc0(0xa6d, 0, 0, CStringW(L""));
        return;
    }
    MyPC* pPlayer = static_cast<MyPC*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (pPlayer)
    {
        bool bSelf = strName.CompareNoCase(pPlayer->vfunc_77()) == 0;
        if (bSelf)
        {
            FUN_140d73bc0(0xa6e, 0, 0, CStringW(L""));
            return;
        }
        if (m_spParam->m_nDialogId != 0x4ebc)
        {
            if (FUN_14097a780()->FUN_140ae5240(strName) == 1)
            {
                FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_cashshop_err_fail_gift_block")), 0, 0, CStringW(L""));
                return;
            }
        }
    }
    CStringW strMessage = pData->FUN_1422b8f40();
    bool bClose = true;
    if (!FUN_140eab330(&bClose, strName, strMessage))
    {
        if (!m_spParam->m_dgGift.IsNull())
            m_spParam->m_dgGift(m_spParam, m_mapPrice, strName, strMessage);
    }
    if (bClose)
        FUN_1403ed2b0()->FUN_141adc5d0(vfunc_48());
}

// "onUpdateTotalPrice": a bill row changed its numbers.
// @0x140eaa5e0
void UIMarketBillDialog::FUN_140eaa5e0(ASData* pData)
{
    if (FUN_140ba28d0(&m_30, 0) || m_spParam == 0)
        return;
    Scaleform::GFx::Value value = pData->FUN_1422b9260();
    int nIndex = pData->FUN_1422b8b10();
    if (nIndex < 0)
        return;
    ASBillData bill(value, 2);
    MS2Ptr<ASBillData> spBill = m_spParam->FUN_140eaba00(nIndex);
    if (!spBill.IsNull())
    {
        int nPayType = spBill->vfunc_4();
        __int64 nPrice = spBill->vfunc_2() - spBill->vfunc_3();
        FUN_140ea9770(nPayType, nPrice);
        int nPaybackType = spBill->vfunc_8();
        __int64 nPayback = spBill->vfunc_6() - spBill->vfunc_7();
        FUN_140ea9970(nPaybackType, nPayback);
        m_bDirty = true;
    }
}

// "onChangeMode".
// @0x140eaa860
void UIMarketBillDialog::FUN_140eaa860(ASData* pData)
{
    if (!pData->FUN_1422b8a90())
        SetMode(1);
    else
        SetMode(2);
    FUN_140eaa8d0();
}

// Rebuild the sums from the rows.
// @0x140eaa8d0
void UIMarketBillDialog::FUN_140eaa8d0()
{
    MS2Ptr<TMarketBillDataParam> spParam = m_spParam;
    if (spParam.IsNull())
        return;
    if ((__int64)spParam->m_n30 >= 1)
        return;
    m_nTotal = 0;
    m_mapPrice.RemoveAll();
    m_mapPayback.RemoveAll();
    m_mapRandomPayback.RemoveAll();
    int nMode = FUN_140eacad0();
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = spParam->m_bills;
    if (!bills.IsEmpty())
    {
        size_t nCount = bills.GetCount();
        for (size_t i = 0; i < nCount; ++i)
        {
            MS2Ptr<ASBillData> spBill = bills.GetAt(i);
            if (spBill.IsNull())
                continue;
            if (nMode == 2 && !spBill->FUN_140eacf60())
                continue;
            FUN_140ea9770(spBill->vfunc_4(), spBill->vfunc_2());
            FUN_140ea9970(spBill->vfunc_8(), spBill->vfunc_6());
            FUN_140ea9880(spBill->vfunc_8(), spBill->vfunc_9());
        }
    }
    m_bDirty = true;
}

// @0x140eaac30
void UIMarketBillDialog::SetMode(int nMode)
{
    m_nMode = nMode;
}

// The mode as the movie names it.
// @0x140eaac50
CString UIMarketBillDialog::FUN_140eaac50(int nMode)
{
    if (nMode == 1)
        return CString("buyGift");
    if (nMode == 3)
        return CString("buy");
    if (nMode == 4)
        return CString("basket");
    return CString("");
}

// Ask before the buy (blueprint / UGC warnings). True when a box was opened.
// @0x140eaad30
bool UIMarketBillDialog::FUN_140eaad30(bool* pbClose)
{
    *pbClose = true;
    if (FUN_140166410()->FUN_14036d570(0xec))
    {
        int nBlueprint = 0x16;
        if (FUN_140ea9c30(nBlueprint))
        {
            CStringW strKey(L"s_meratmarket_buy_notice_blueprint");
            MS2Ptr<CMsgBoxData> spBox = FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMarketBillDialog::FUN_140eab6b0), FUN_14028b8e0(strKey));
            *pbClose = false;
            return true;
        }
    }
    MyPC* pPlayer = static_cast<MyPC*>(FUN_141bd0cc0(FUN_1403ed2d0()));
    if (pPlayer)
    {
        if (pPlayer->FUN_141527e00() == 0)
        {
            if (FUN_140ea9df0())
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x1f, 0x6ec, 0, CStringW(L""));
                if (spBox.get())
                {
                    spBox->FUN_141a01800(2);
                    spBox->FUN_141a024e0(FUN_14028de60(0x9d1), 0);
                    spBox->SetAgreement(false);
                    spBox->FUN_141a02770(0x1c0, 400);
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMarketBillDialog::FUN_140eab6b0));
                    FUN_140d73c60(spBox);
                    return true;
                }
            }
        }
        else
        {
            if (FUN_140ea9a70())
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0x1f, 0x6eb, 0, CStringW(L""));
                if (spBox.get())
                {
                    spBox->FUN_141a01800(2);
                    spBox->FUN_141a024e0(FUN_14028de60(0x9d1), 0);
                    spBox->SetAgreement(false);
                    spBox->FUN_141a02770(0x1c0, 400);
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMarketBillDialog::FUN_140eab6b0));
                    FUN_140d73c60(spBox);
                    return true;
                }
            }
        }
    }
    return false;
}

// Ask before the gift. True when the question box was opened.
// @0x140eab330
bool UIMarketBillDialog::FUN_140eab330(bool* pbClose, const CStringW& strName, const CStringW& strMessage)
{
    CStringW strText;
    int nBlueprint = 0x16;
    if (FUN_140ea9c30(nBlueprint) && FUN_140166410()->FUN_14036d570(0xec))
        strText = FUN_1405c2690(CStringW(L"s_meratmarket_gift_ask_confirm_blueprint"), strName);
    else if (m_spParam->m_nDialogId == 0x4ec1)
        strText = FUN_1405c2690(CStringW(L"s_meratmarket_gift_ask_confirm"), strName);
    if (strText.IsEmpty())
        return false;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMarketBillDialog::FUN_140eab7b0), strText);
    if (spBox.get())
    {
        spBox->FUN_140b76940(strName);
        spBox->FUN_140b76940(strMessage);
    }
    *pbClose = false;
    return true;
}

// The answer of the buy warning.
// @0x140eab6b0
bool UIMarketBillDialog::FUN_140eab6b0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0 && (m_spParam.get() ? true : false))
    {
        if (!m_spParam->m_dgBuy.IsNull())
            m_spParam->m_dgBuy(m_spParam, m_mapPrice);
    }
    return true;
}

// The answer of the gift question.
// @0x140eab7b0
bool UIMarketBillDialog::FUN_140eab7b0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        CStringW strName;
        CStringW strMessage;
        box.FUN_140b76a70(0, strName);
        box.FUN_140b76a70(1, strMessage);
        if (m_spParam.get() ? true : false)
        {
            if (!m_spParam->m_dgGift.IsNull())
                m_spParam->m_dgGift(m_spParam, m_mapPrice, strName, strMessage);
        }
    }
    return true;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca8080-0x142ca81c0 .text$yd
