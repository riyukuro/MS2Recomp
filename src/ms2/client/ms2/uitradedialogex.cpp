// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Player-to-player trade window ("TradeDialogEx").
// MS2-UNIT: ?\uitradedialogex.cpp
// MS2-RANGE: 0x14011e350-0x14011e550 .text$di
// MS2-RANGE: 0x141b26de0-0x141b29f20 .text$mn
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uitradedialogex.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uitradedialogex.h"
#include "trademanagerex.h"

#include <algorithm>

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local placeholders (names invented; promote to src/ms2/placeholder/ when shared) ----

class ASDialog : public ASDisplayObject { };

// The inventory dialog (UI id 0x4e2d): the trade window is placed next to it.
class UIInventoryDialog : public UIDialog
{
public:
    void FUN_141999e00();
};
UIInventoryDialog* FUN_1405344f0(int nUiId);

// The UI message ("openWindowPos"): an ActionScript call (ASData + type, 0x50 bytes).
class Unk_TdUIMsg : public UIMsg
{
public:
    Unk_TdUIMsg();                                          // 0x1422e4490
    ~Unk_TdUIMsg();                                         // 0x140c30570
    void FUN_1422b82b0(const char* pszMethod);
    void FUN_1422b7f70(int n);
    void* m_pad[10];
};

// The status-listener registry (singleton 0x140aa6d40).
class Unk_TdStatusMgr
{
public:
    void FUN_141b0cd00(UIStatusEventListener* pListener);   // register
    void FUN_141b0cd90(UIStatusEventListener* pListener);   // unregister
};
Unk_TdStatusMgr* FUN_140aa6d40();

// The movie root (m_30) with the child lookup of the trade controls.
class Unk_TdRoot : public AScript
{
public:
    template <class T> MS2Ptr<T> FUN_140bbe880(const CString& strName);
};
#define TD_ROOT static_cast<Unk_TdRoot*>(m_30.operator->())

class Unk_TdEquipSet { public: float FUN_1411e1110(int nStat); };

bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released
int FUN_1418fc760(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs, UIDialog* pDialog);

// The trade slot bags (trademanagerex_2.cpp) and the registry of bound slot bags.
void FUN_14185e850(const CString& strName, int nCount, bool bMine);
void FUN_14185e920(const CString& strName);
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
TradeSlotBag* FUN_14185edc0(NotifyContext::BindData* p);
DragSlot* FUN_1422cd070(DragSlotBag* pBag, int nIndex);        // the slot of the bag by index
TradeSlot* FUN_14140e720(DragSlot* p);                         // the trade slot behind a drag source (null: not one)

// The meso limits and the trade checks.
__int64 FUN_14087d0c0();                                       // the smallest meso offer
__int64 FUN_14087d0f0();                                       // the largest meso offer
bool FUN_14087d200(__int64 nMeso);                             // 0 or within the limits
__int64 FUN_14087d150(__int64 nMeso, float fReduce);           // the fee of an offer
CStringW FUN_141275860(__int64 nMeso);                         // the meso number text

// Text helpers.
CStringW FUN_1409404f0(__int64 nValue);                        // number with separators
CStringW FUN_14083cf10(const CStringW& str);                   // the digits of a number text
__int64 FUN_140718320(const CStringW& str);                    // parse a number text
CStringW FUN_14062b4f0(CStringW strKey, const int& nArg);      // string table format
CStringW FUN_140c160b0(CStringW strKey, const __int64& nArg);  // string table format
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);   // string table format
CStringW FUN_14028b8e0(const CStringW& strKey);                // string table text
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a1, const CStringW& a2);   // string table format
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);   // message box
void FUN_141276180(const CString& strEvent, const CString& strArg);   // sound event
CString FUN_14038f6d0(const CString& str, const char* sz);     // str + sz

// The local player.
unsigned int FUN_141662de0(PC* pPlayer);                        // the player has the vip bonus
void* FUN_1403ed2d0();                                         // the session
void* FUN_141bd0cc0(void* pSession);                           // the local player
CString FUN_141028be0(__int64 nCharId, const CString& strKey, int nFlag, CString strEmpty);   // the profile image key

// The feature manager and the status registry.
void* FUN_140166410();
bool FUN_14036d570(void* pFeatures, int nFeature);

// The meso the player owns, the zero offset and the trade table.
extern __int64 DAT_143ab2898;
struct Unk_TdXY { float x, y; };                                // dialog offset
extern Unk_TdXY DAT_143b02320;                                  // zero offset
void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, Unk_TdXY offLeft, Unk_TdXY offRight);

// ---- statics of the unit's header (the sort name list, skill, stun, a condition object) and the trade sounds ----

static CString s_sortNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill("skill");
static CString s_stun("stun");
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput;
static CString s_strTradeLock("trade_lock");
static CString s_strTradeUnlock("trade_unlock");

// @0x141b26de0
UITradeDialogEx::UITradeDialogEx()
    : m_uidTarget(0)
    , m_bDockedOnInventory(0)
    , m_spMyInput(0)
    , m_spMyInputText(0)
    , m_spTargetInput(0)
    , m_spMyFee(0)
    , m_spTargetFee(0)
    , m_spMyMeso(0)
    , m_spTargetMeso(0)
    , m_nMyMeso(0)
{
    FUN_141924170(1);
    m_164 = 1;
    CString strName = vfunc_1();
    m_strMyBagId = FUN_14038f6d0(strName, "_my");
    m_strTargetBagId = FUN_14038f6d0(strName, "_target");
}

// @0x141b27070
UITradeDialogEx::~UITradeDialogEx()
{
}

// @0x141b271d0
CString UITradeDialogEx::vfunc_1()
{
    return "TradeDialogEx";
}

// @0x141b27220
int UITradeDialogEx::vfunc_65()
{
    return UIDialog::vfunc_65() != 0;
}

// @0x141b27250
void UITradeDialogEx::vfunc_67()
{
    FUN_140aa6d40()->FUN_141b0cd90(static_cast<UIStatusEventListener*>(this));
    FUN_14140ea30()->FUN_14185b970();
    FUN_14140ea30()->FUN_14185d7b0();
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0)
    {
        if (pInv->vfunc_55() == 0)
            pInv->FUN_141999e00();
    }
    FUN_141b27d50();
    vfunc_47(1);
    UIDialog::vfunc_67();
    m_spMyInput = 0;
    m_spMyInputText = 0;
    m_spTargetInput = 0;
    m_spMyFee = 0;
    m_spTargetFee = 0;
    m_spMyMeso = 0;
    m_spTargetMeso = 0;
}

// @0x141b273b0
void UITradeDialogEx::vfunc_66()
{
    UIDialog::vfunc_66();
    UIInventoryDialog* pInv = FUN_1405344f0(0x4e2d);
    if (pInv != 0)
    {
        m_bDockedOnInventory = pInv->vfunc_55() == 0;
        if (m_bDockedOnInventory == 0)
        {
            Unk_TdUIMsg msg;
            msg.FUN_1422b82b0("openWindowPos");
            msg.FUN_1422b7f70(vfunc_48());
            pInv->OnMessage(this, &msg);
        }
        else
        {
            FUN_141275c30(this, pInv, DAT_143b02320, DAT_143b02320);
        }
    }
}

// @0x141b274f0
void UITradeDialogEx::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_141b27580();
    FUN_140aa6d40()->FUN_141b0cd00(static_cast<UIStatusEventListener*>(this));
}

// @0x141b27550
void UITradeDialogEx::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
}

// @0x141b27580
void UITradeDialogEx::FUN_141b27580()
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        m_uidTarget = FUN_14140ea30()->FUN_141b29c10();
        m_strTargetName = FUN_14140ea30()->FUN_141b29c20();
        m_strTargetChar = FUN_14140ea30()->FUN_141b29c70();
        PC* pPlayer = static_cast<PC*>(FUN_141bd0cc0(FUN_1403ed2d0()));
        if (pPlayer != 0)
        {
            ASObj data(2);
            data.FUN_1407cbb20("myName", pPlayer->vfunc_77());
            data.FUN_1407cbb20("targetName", m_strTargetName);
            CString strMyProfile = FUN_141028be0(pPlayer->FUN_141656a80(), pPlayer->FUN_1416612e0(), 1, CString(""));
            CString strTargetProfile = FUN_141028be0(m_uidTarget, m_strTargetChar, 1, CString(""));
            data.FUN_1407cba60("myProfile", strMyProfile);
            data.FUN_1407cba60("targetProfile", strTargetProfile);
            data.FUN_1407cb9c0("slotCount", 5);
            data.FUN_1407cba60("mySlotBagId", m_strMyBagId);
            data.FUN_1407cba60("targetSlotBagId", m_strTargetBagId);
            m_30->Invoke("initData", data.FUN_1422bb870());
            FUN_141b284b0();
        }
    }
}

// @0x141b27a60
void UITradeDialogEx::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_141b27cf0();
    vfunc_47(0);
}

// @0x141b27aa0
int UITradeDialogEx::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (FUN_1418fc760(szMethod, pArgs, nArgs, 0) != 0)
        return 1;
    if (_stricmp("OnClose", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    if (_stricmp("OnCancel", szMethod) == 0)
    {
        vfunc_67();
        return 1;
    }
    if (_stricmp("OnLock", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            __int64 nMeso = FUN_1407182f0(data.FUN_1422b8d30());
            if (FUN_141b295a0(nMeso))
                FUN_14140ea30()->FUN_14185bb80();
        }
        return 1;
    }
    if (_stricmp("OnConfirm", szMethod) == 0)
    {
        FUN_14140ea30()->FUN_14185bbe0();
        return 1;
    }
    return 0;
}

// @0x141b27ca0
int UITradeDialogEx::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    return UIDialog::OnMessage(pSender, pMsg) != 0;
}

// @0x141b27cf0
void UITradeDialogEx::FUN_141b27cf0()
{
    FUN_141b27d50();
    FUN_14185e850(m_strMyBagId, 5, 1);
    FUN_14185e850(m_strTargetBagId, 5, 0);
}

// @0x141b27d50
void UITradeDialogEx::FUN_141b27d50()
{
    FUN_14185e920(m_strMyBagId);
    FUN_14185e920(m_strTargetBagId);
}

// @0x141b27d90
void UITradeDialogEx::FUN_141b27d90(__int64 nMeso)
{
    m_nMyMeso = std::min<__int64>(nMeso, FUN_14087d0f0());
}

// @0x141b27de0
void UITradeDialogEx::FUN_141b27de0(int nSide, int nIndex, MS2Ptr<CItem> spItem)
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        CString strBagId = nSide == 0 ? m_strTargetBagId : m_strMyBagId;
        TradeSlotBag* pBag = FUN_14185edc0(FUN_1422c8e90(strBagId));
        if (pBag != 0)
        {
            efd::SmartPointer<TradeSlot> spSlot(FUN_14140e720(FUN_1422cd070(pBag, nIndex)));
            if (spSlot == 0)
                return;
            spSlot->FUN_14185e4e0(spItem);
            spSlot->vfunc_10();
        }
    }
}

// @0x141b27fa0
void UITradeDialogEx::FUN_141b27fa0(int nSide, int nIndex)
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        CString strBagId = nSide == 0 ? m_strTargetBagId : m_strMyBagId;
        TradeSlotBag* pBag = FUN_14185edc0(FUN_1422c8e90(strBagId));
        if (pBag != 0)
        {
            efd::SmartPointer<TradeSlot> spSlot(FUN_14140e720(FUN_1422cd070(pBag, nIndex)));
            if (spSlot == 0)
                return;
            spSlot->FUN_14185e4e0(MS2Ptr<CItem>(0));
            spSlot->vfunc_10();
        }
    }
}

// @0x141b28130
void UITradeDialogEx::FUN_141b28130(int nSide, __int64 nMeso)
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        MS2Ptr<ASTextInput> spInput = nSide == 1 ? m_spMyInput : m_spTargetInput;
        if (spInput == 0)
            return;
        spInput->FUN_1422e0ab0(FUN_1409404f0(nMeso));
        spInput->vfunc_24(1);
        FUN_141b28f40(nMeso, nSide == 1);
    }
}

// @0x141b28290
void UITradeDialogEx::FUN_141b28290(int nSlotIndex, int bLock)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        if (bLock == 0)
        {
            FUN_141276180(s_strTradeUnlock, CString(""));
            m_30->Invoke("unlatch", nSlotIndex);
        }
        else
        {
            FUN_141276180(s_strTradeLock, CString(""));
            m_30->Invoke("latch", nSlotIndex);
        }
    }
}

// @0x141b283f0
int UITradeDialogEx::FUN_141b283f0(int* pnSlot)
{
    int nSlot = -1;
    nSlot = DAT_143ab2e80.FUN_14185b5c0();
    if (nSlot < 0)
        return 0;
    *pnSlot = nSlot;
    return 1;
}

// @0x141b28440
void UITradeDialogEx::vfunc_oa0_11(void* a1)
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
        FUN_141b27d90(FUN_14140ea30()->FUN_14185d920() + DAT_143ab2898);
}

// @0x141b284b0
void UITradeDialogEx::FUN_141b284b0()
{
    FUN_141b27d90(DAT_143ab2898);
    if ((m_spMyInput = TD_ROOT->FUN_140bbe880<ASTextInput>("m_myInputMeso")).get() != 0)
    {
        m_spMyInput->FUN_1422e0920(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UITradeDialogEx::FUN_141b291a0));
        if ((m_spMyInputText = m_spMyInput->FUN_1422e1490()).get() != 0)
        {
            int nMaxChars = FUN_1409404f0(FUN_14087d0f0()).GetLength();
            static_cast<ASTextField*>(m_spMyInputText.operator->())->FUN_1422c5170(nMaxChars);
            m_spMyInputText->FUN_1422de780(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UITradeDialogEx::FUN_141b29330), 0, 0);
        }
    }
    m_spTargetInput = TD_ROOT->FUN_140bbe880<ASTextInput>("m_targetInputMeso");
    m_spMyFee = m_30->FUN_1409b4620("m_myTradeFee");
    m_spTargetFee = m_30->FUN_1409b4620("m_targetTradeFee");
    FUN_141b28e30(1, 0);
    FUN_141b28e30(0, 0);
    m_spMyMeso = m_30->FUN_1409b4620("m_myMesoNumberString");
    m_spTargetMeso = m_30->FUN_1409b4620("m_targetMesoNumberString");
    FUN_141b28d10(1, 0);
    FUN_141b28d10(0, 0);
    if (FUN_14036d570(FUN_140166410(), 0xc5) == 0)
    {
        m_spMyMeso->vfunc_4(false);
        float fMyY = m_spMyMeso->FUN_1422c1110();
        m_spMyFee->FUN_1422c05a0(fMyY);
        m_spTargetMeso->vfunc_4(false);
        float fTargetY = m_spTargetMeso->FUN_1422c1110();
        m_spTargetFee->FUN_1422c05a0(fTargetY);
    }
    int nFeePercent = Client::Constants::GetInstance()->TradeFeePercent.Read();
    CStringW strNotice = FUN_14062b4f0(CStringW(L"s_trade_notice_fee"), nFeePercent);
    MS2Ptr<ASTextField> spNotice = m_30->FUN_1409b4620("m_feeNotice");
    if (spNotice.get() != 0)
        spNotice->FUN_1422c4f00(strNotice);
}

// @0x141b28d10
void UITradeDialogEx::FUN_141b28d10(char bMine, __int64 nMeso)
{
    MS2Ptr<ASTextField> spText = bMine == 0 ? m_spTargetMeso : m_spMyMeso;
    if (spText == 0)
        return;
    if (FUN_14036d570(FUN_140166410(), 0xc5) == 0)
    {
        spText->FUN_1422c4f00(CStringW(L""));
    }
    else
    {
        spText->FUN_1422c4f00(FUN_141275860(nMeso));
    }
}

// @0x141b28e30
void UITradeDialogEx::FUN_141b28e30(char bMine, __int64 nFee)
{
    CStringW strFee = FUN_140c160b0(CStringW(L"s_trade_fee"), nFee);
    MS2Ptr<ASTextField> spText = bMine == 0 ? m_spTargetFee : m_spMyFee;
    if (spText == 0)
        return;
    spText->FUN_1422c4f00(strFee);
}

// @0x141b28f40
void UITradeDialogEx::FUN_141b28f40(__int64 nMeso, char bMine)
{
    MS2Ptr<ASTextField> spText = bMine == 0 ? m_spTargetFee : m_spMyFee;
    if (spText == 0)
        return;
    float fReduce = 0;
    bool bVip = false;
    if (bMine == 0)
    {
        PC* pPlayer = static_cast<PC*>(FUN_141bd0cc0(FUN_1403ed2d0()));
        if (pPlayer == 0)
            return;
        fReduce = reinterpret_cast<Unk_TdEquipSet*>(pPlayer->FUN_1416561a0())->FUN_1411e1110(0x40);
        if (FUN_141662de0(pPlayer) != 0)
            bVip = true;
    }
    __int64 nFee = FUN_14087d150(nMeso, fReduce);
    CStringW strFee = FUN_1405c2690(CStringW(L"s_trade_fee"), FUN_1409404f0(nFee));
    if (bVip)
        strFee += FUN_14028b8e0(CStringW(L"s_vip_reduce_fee"));
    spText->FUN_1422c4f00(strFee);
    FUN_141b28d10(bMine, nMeso);
}

// @0x141b291a0
void UITradeDialogEx::FUN_141b291a0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    AScript evt(*params.pArgs, 2);
    Scaleform::GFx::Value target = evt.FUN_1422baa20("target");
    ASTextInput input(target, m_28);
    CStringW strDigits = FUN_14083cf10(input.FUN_1422e0b00());
    __int64 nMeso = FUN_140718320(strDigits);
    if (m_nMyMeso < nMeso)
    {
        nMeso = m_nMyMeso;
        input.FUN_1422e0ab0(FUN_1409404f0(nMeso));
    }
    FUN_141b28f40(nMeso, 1);
}

// @0x141b29330
void UITradeDialogEx::FUN_141b29330(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (!(m_spMyInput == 0))
    {
        AScript evt(*params.pArgs, 2);
        Scaleform::GFx::Value target = evt.FUN_1422baa20("target");
        ASTextField text(target, m_28);
        CStringW strDigits = FUN_14083cf10(m_spMyInput->FUN_1422e0b00());
        __int64 nParsed = FUN_140718320(strDigits);
        __int64 nMeso = nParsed;
        if (nMeso < 0)
            nMeso = 0;
        if (m_nMyMeso < nMeso)
            nMeso = m_nMyMeso;
        if (nParsed != nMeso)
            FUN_141b28f40(nMeso, 1);
        FUN_141b295a0(nMeso);
    }
}

// @0x141b294f0
void UITradeDialogEx::FUN_141b294f0(__int64 nMeso)
{
    m_spMyInput->FUN_1422e0ab0(FUN_1409404f0(nMeso));
    m_spMyInput->vfunc_24(1);
    FUN_141b28f40(nMeso, 1);
}

// @0x141b295a0
bool UITradeDialogEx::FUN_141b295a0(__int64 nMeso)
{
    bool bInRange = FUN_14087d200(nMeso);
    if (!bInRange)
    {
        FUN_141b294f0(0);
        nMeso = 0;
        CStringW strMin = FUN_1409404f0(FUN_14087d0c0());
        CStringW strMax = FUN_1409404f0(FUN_14087d0f0());
        FUN_140d73aa0(FUN_1408f71a0(CStringW(L"s_trade_error_invalid_meso_range"), strMin, strMax), 0, 0, CStringW(L""));
    }
    bool bValid = bInRange != 0;
    if (m_nMyMeso < nMeso)
    {
        FUN_141b294f0(0);
        nMeso = 0;
        FUN_140d73aa0(FUN_14028b8e0(CStringW(L"s_trade_error_lack_meso_2")), 0, 0, CStringW(L""));
        bValid = false;
    }
    FUN_14140ea30()->FUN_14185baf0(nMeso);
    return bValid;
}

// @0x141b297e0
void UITradeDialogEx::FUN_141b297e0(int nCode)
{
    if (FUN_140ba28d0(&m_30, 0) == 0)
    {
        if (nCode == 0xe || nCode == 0xd || nCode == 0x11 || nCode == 0x12 || nCode == 0x13)
            FUN_141b294f0(0);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cc2d80-0x142cc2e70 .text$yd
