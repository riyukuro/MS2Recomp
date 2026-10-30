// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Merat market register dialog. See uimeratmarketregisterdialog.h.
// MS2-UNIT: client\ms2\uimeratmarketregisterdialog.cpp
// MS2-RANGE: 0x1400eed20-0x1400ef050 .text$di
// MS2-RANGE: 0x141317690-0x14131d910 .text$mn
// MS2-RANGE: 0x142cafbd0-0x142cafd30 .text$yd
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIMeratMarketRegisterDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x14131d2b0
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GUIMeratMarketRegisterDialog@@UEAAPEAXI@Z 0x14131d2f0 ; unique
// MS2-PIN: ??_GUgcAddProduct@CMeratMarketPacket@@UEAAPEAXI@Z 0x14131d330 ; prop
// MS2-PIN: ??_GUgcAddProductBase@CMeratMarketPacket@@UEAAPEAXI@Z 0x14131d370 ; unique
// MS2-PIN: ??_GUgcResaleProduct@CMeratMarketPacket@@UEAAPEAXI@Z 0x14131d3b0 ; prop
// MS2-PIN: ?Append@?$CAtlArray@V?$MS2Ptr@VCItem@@@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@ATL@@@ATL@@QEAA_KAEBV12@@Z 0x14131d3f0 ; unique
// MS2-PIN: ?vfunc_48@UIMeratMarketRegisterDialog@@UEAAHXZ 0x14131d490 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@_JV?$MS2Ptr@VCItem@@@@V?$CElementTraits@_J@ATL@@V?$CElementTraits@V?$MS2Ptr@VCItem@@@@@3@@ATL@@QEAAPEAVCPair@12@_J@Z 0x14131d4a0 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIMeratMarketRegisterDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x14131d710 ; unique
// MS2-PIN: ??$Call@VUIMeratMarketRegisterDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVUIMeratMarketRegisterDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVUIMeratMarketRegisterDialog@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x14131d750 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimeratmarketregisterdialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uimeratmarketregisterdialog.h"
#include "inventory.h"
#include "warehouseitem.h"
#include "ms2/gfxui/dragslot.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmeratmarketpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- header statics (the shared list of the merat market units) ----
#ifndef MS2_HOOK_DLL
static CString s_marketSort[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_skill = "skill";
static CString s_stun = "stun";
static Unk_1402a9d70 s_unk1402a9d70(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyController;
static CString s_jobCode = "jobCode";
static CString s_sortValue = "sortValue";
static CString s_tabIndex = "tabIndex";
#endif
static CString s_marketItemChoice = "Market_ItemChoice";

// ---- unit-local declarations (names describe uses, not original class names) ----

class PCBase;
class CMeratMarketMan;
class CUgcItemLook;

// The text input child (m_inputTag1..3).
class Unk_MrdInput : public CPtred
{
public:
    void FUN_1422e0ab0(const CStringW& strText);    // set the text
    void FUN_1422e0d60(int nMaxChars);              // limit the length
};

// The product registry singleton (a record of the market, found by key / by the offered item's uid).
class Unk_MrdListing : public CPtred
{
};
class Unk_MrdMarket
{
public:
    MS2Ptr<CMeratMarketProduct> FUN_140d55800(Unk_MeratProductKey key);     // product by key
    MS2Ptr<Unk_MrdListing> FUN_140d55a10(__int64 nUgcUid);                  // the offer of a UGC design
    MS2Ptr<Unk_MrdListing> FUN_140d55b60(__int64 nMusicUid);                // the offer of a music score
    void FUN_140d54560(MS2Ptr<CMeratMarketPacket::UgcAddProduct> spRequest);        // send "add"
    void FUN_140d547f0(MS2Ptr<CMeratMarketPacket::UgcResaleProduct> spRequest);     // send "sell again"
    int FUN_140d5b170();                                                    // the fee item id
};
Unk_MrdMarket* FUN_140939a00();

// The 16-byte product key as the AS side writes it ("P<n>" / "U<n>").
struct Unk_MrdOid
{
    void FUN_1409c1640(CStringW strOid);            // parse
    CStringW FUN_1409b0470() const;                 // the AS form
    int m_nPremiumId;
    __int64 m_nUgcId;
};
MS2_CHECK_SIZE(Unk_MrdOid, 0x10);

// The constants singleton: the register-fee block.
struct Unk_MrdConfig { void* m_p; };
struct Unk_MrdValueInt { void* m_p; };
struct Unk_MrdValueI64 { void* m_p; };
struct Unk_MrdValueMoney { void* m_p; };
Unk_MrdConfig* FUN_1401d3200();
__int64 FUN_1402bac90(Unk_MrdValueI64* pValue);     // Value<__int64>::Read
int FUN_14025a620(Unk_MrdValueInt* pValue);         // Value<int>::Read
__int64 FUN_1406a6d50(Unk_MrdValueMoney* pValue);   // the limit
__int64* FUN_1402c05b0(Unk_MrdValueI64* pValue);    // the constant block's record

// The owner of the items (account and character ids of the player; 0x20 bytes).
struct Unk_MrdOwner
{
    void FUN_1409aff60();
    __int64 m_nAccount;
    unsigned m_nType;
    void* m_pCharacter;                                 // the own character id (stored as a pointer-size value)
    __int64 m_n18;
};
MS2_CHECK_SIZE(Unk_MrdOwner, 0x20);
extern __int64 DAT_143ab2820;
extern unsigned DAT_143ab2830;
extern __int64 DAT_143ab2838;
extern int DAT_143ab2834;

// The equip list of the player.
class Unk_MrdPlayer
{
};
void* FUN_1403ed2d0();
PCBase* FUN_141bd0cc0(void* pWorld);
Unk_PCEquipSet* FUN_1416561a0(PCBase* pPlayer);
void FUN_1411e1ce0(Unk_PCEquipSet* pSet, ATL::CAtlList<MS2Ptr<CEquipItem> >& list, int n);
int FUN_141658e60(PCBase* pPlayer);                 // the gender of the player

class Unk_MrdFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_MrdFeatures* FUN_140166410();

// The inventories (globals).
extern Unk_Inventory DAT_143ab2a90;
class Unk_MrdStockItem : public CPtred
{
};
class Unk_MrdCubeStock
{
public:
    MS2Ptr<Unk_MrdStockItem> FUN_140dfc8f0(unsigned __int64 nUid);          // by uid
    void FUN_140dfcd00(void* pFilter, ATL::CAtlArray<MS2Ptr<CItem> >& out); // the stock as items
};
extern Unk_MrdCubeStock DAT_143ab2e50;

CItemData* FUN_140527840(CItem* pItem);             // the item's table row
MS2Ptr<CItemData> FUN_14053f870(int nItemId);
bool FUN_140633d50(MS2Ptr<CItem> spItem);           // the item can be traded
bool FUN_1406a5a50(MS2Ptr<CItem> spItem, const __int64* pOwner);
void FUN_1406a5480(MS2Ptr<CItemData> spItem, __int64* pMin, __int64* pMax);
__int64 FUN_1406a5240(int nItemId);
__int64 FUN_141b71960(const char* sz);
MS2Ptr<CItem> FUN_140ebc070(CMeratMarketProduct* pProduct);   // the item a product shows
int FUN_140ebc4a0();
int FUN_140ebbb30(ASTooltip* pTip, MS2Ptr<CItem> spItem, MS2Ptr<CMeratMarketProduct> spProduct, bool bMyShop, bool bFlag);

// UI helpers.
bool FUN_140ba28d0(const MS2Ptr<AScript>* pAS, int n);          // has the AS object been released
bool FUN_1418ffe80(int nFlags, int nBit);
void FUN_1418ffec0(int* pFlags, int nBit);
void FUN_1418ffef0(int* pFlags, int nBit);
bool FUN_1418ff110(int nType, __int64 nValue, bool b);          // the player can pay
CStringW FUN_1418fec00(int nType, __int64 nValue, int n);       // money text by pay type
CStringW GetStringCommonByKey(const CStringW& strKey);
CStringW GetStringCommon(int nStringId);
CStringW FUN_1408116a0(int nId, const int& nArg);
CStringW FUN_14086d060(int nId, const __int64& nArg);
CStringW FUN_1409404f0(__int64 nValue);
CStringW FUN_140632a60(int nId, const CStringW& strArg0, const CStringW& strArg1);
CStringW FUN_14016a730(const char* sz, int n);
void FUN_140d73aa0(CStringW strText, int nType, void* p, CStringW strTag);
void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW strTag);
class Unk_MrdMsgBox : public CPtred
{
};
MS2Ptr<Unk_MrdMsgBox> FUN_140d74390(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
MS2Ptr<Unk_MrdMsgBox> FUN_140d748b0(int nType, const CStringW& strTitle, const CStringW& strBody, Delegate<bool(int, const CMsgBoxData&)> cb);
void FUN_141276180(const CString& strName, const CString& strValue);
void FUN_14141f970(CString& str);
void FUN_14141f770(CString& strOut, unsigned int nSlots, const UIMeratMarketRegisterDialog::ItemArray& arrItems,
                   MS2Ptr<CItem> (*pfnGet)(const UIMeratMarketRegisterDialog::ItemArray&, int), int a, int b);
MS2Ptr<CItem> FUN_141420330(const UIMeratMarketRegisterDialog::ItemArray& arrItems, int nIndex);
int FUN_1406516a0();
void FUN_1409b4bc0(Scaleform::GFx::Value* pOut, Scaleform::GFx::Value& v);
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);
void FUN_1422bce70(Scaleform::GFx::Value* pValue, const char* sz);
class Unk_MrdUiMgr { public: void FUN_141adc5d0(int nUiId); };
Unk_MrdUiMgr* FUN_1403ed2b0();
int FUN_1409c17e0(const Scaleform::GFx::Value& v);
void* FUN_1409331e0();
void FUN_14138bf00(void* pMgr, int a, int b, int c);

// The "fee changed" notice answer / purchase block notice.
struct Unk_MrdBlockRef;
void FUN_1401cb250(Unk_MrdBlockRef*);
struct Unk_MrdBlockRef
{
    void* m_00;
    void* m_08;
    ~Unk_MrdBlockRef() { FUN_1401cb250(this); }
};
MS2_CHECK_SIZE(Unk_MrdBlockRef, 0x10);
class Unk_MrdBlockMgr { public: Unk_MrdBlockRef FUN_140a2f620(int nKind); };
Unk_MrdBlockMgr* FUN_140a6a830();
void* FUN_1401cb3d0(Unk_MrdBlockRef* pRef);
void FUN_140a2ff20(Unk_MrdBlockRef* pRef, int nKind, __int64 n);

// The text filter (bad words).
class Unk_MrdFilter : public CPtred
{
public:
    int FUN_140226100(const CStringW& str, CStringW& strMessage);
    int FUN_140226160(const CStringW& str, CStringW& strMessage);
};
class Unk_MrdFilterMgr
{
public:
    MS2Ptr<Unk_MrdFilter> FUN_140229a50();
};
Unk_MrdFilterMgr* FUN_14025e7d0();

// The key state.
class Unk_MrdKeys { public: bool FUN_14116d9c0(int nKey, int a, int b); };
Unk_MrdKeys* FUN_14025e7c0();

// Dialog manager: the top dialog of a layer.
class Unk_MrdDialogMgr { public: UISwfEntity* FUN_1422d4980(int nLayer); };
Unk_MrdDialogMgr* FUN_140b632f0();

// The royalty list (charge info) and the singleton that fills it.
struct Unk_MrdPaybackList
{
    Unk_MrdPaybackList(int nBlockSize) { FUN_140898ff0(nBlockSize); }
    ~Unk_MrdPaybackList() { FUN_1408996f0(); }
    void FUN_140898ff0(int nBlockSize);
    void FUN_1408996f0();
    bool FUN_140ec3b20();
    void* m_p[7];
};
MS2_CHECK_SIZE(Unk_MrdPaybackList, 0x38);
class Unk_MrdPayback { public: void FUN_1408981a0(Unk_MrdPaybackList* pList); };
Unk_MrdPayback* FUN_140ec3940();
CStringW FUN_140ebd9d0(int a, int b);
CStringW FUN_1405c2690(CStringW strFormat, const CStringW& strArg);

// The slot bag of the movie.
NotifyContext::BindData* FUN_1422c8e90(const CString& strName);
DragSlotBag* FUN_140c54520(NotifyContext::BindData* pBind);
DragSlot* FUN_1422cd070(DragSlotBag* pBag, int nIndex);
DragSlot* FUN_140cfe6c0(DragSlot* pSlot);

// Items of the dialog as the base UI knows them.
class Unk_MrdEquipOut { public: };

// Constant blocks of the config singleton (offsets proven by the callers below).
#define MrdFeeValue() (((Unk_MrdValueI64*)((char*)FUN_1401d3200() + 0x4710)))
#define MrdSaleDayValue() (((Unk_MrdValueInt*)((char*)FUN_1401d3200() + 0x4770)))
#define MrdMinPriceValue() (((Unk_MrdValueMoney*)((char*)FUN_1401d3200() + 0x4608)))
#define MrdMaxPriceValue() (((Unk_MrdValueMoney*)((char*)FUN_1401d3200() + 0x4660)))
#define MrdTagLimitValue() (((Unk_MrdValueInt*)((char*)FUN_1401d3200() + 0x9f70)))

// The "initData" call: key, a flag and the two AS objects.
// @0x14131cc10
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, CString a1, bool a2, Scaleform::GFx::Value a3, Scaleform::GFx::Value a4)
{
    ASArgList args;
    args.FUN_1409b2800(4);
    FUN_1422bce70(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcc70(args.FUN_1409b1f70(2), a3);
    FUN_1422bcc70(args.FUN_1409b1f70(3), a4);
    return FUN_1422bb8f0(szMethod, args);
}

// ---- UIMeratMarketRegisterDialog ----

// @0x141317690
UIMeratMarketRegisterDialog::UIMeratMarketRegisterDialog()
    : m_nMode(0), m_nAlreadyIndex(-1), m_keyResale(0, 0), m_bOnlyEnabled(false), m_spRequest(0), m_nFlags(0), m_nFee(0)
{
    FUN_141924170(1);
    FUN_1422dc3b0(1);
}

// @0x1413177f0
UIMeratMarketRegisterDialog::~UIMeratMarketRegisterDialog()
{
    m_spRequest = 0;
    m_items.RemoveAll();
    m_mapUgc.RemoveAll();
}

// @0x1413178e0
CString UIMeratMarketRegisterDialog::GetTypeName()
{
    return CString("MeratMarketRegisterDialog");
}

// @0x141317930
void UIMeratMarketRegisterDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
    m_nMode = 0;
    m_nAlreadyIndex = -1;
    m_keyResale.Reset();
    m_spRequest = 0;
    FUN_14141f970(m_strKey);
    m_items.RemoveAll();
    m_mapUgc.RemoveAll();
    m_nFee = 0;
    m_nFlags = 0;
    m_spSelected = 0;
}

// @0x141317a10
int UIMeratMarketRegisterDialog::vfunc_65()
{
    if (vfunc_55() == 0)
        FUN_1419235d0();
    return UIDialog::vfunc_65();
}

// The tooltips of the royalty button and of the selected item.
// @0x141317a50
void UIMeratMarketRegisterDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    CString strName = pArgs->FUN_1422b8d30();
    if (strName.IsEmpty())
        return;
    if (_stricmp("m_btnRoyaltyInfo", strName) == 0)
    {
        Unk_MrdPaybackList list(10);
        FUN_140ec3940()->FUN_1408981a0(&list);
        if (list.FUN_140ec3b20() != 0)
            return;
        CStringW strCharge = FUN_140ebd9d0(0, 0);
        ASTooltip tip(1, 2);
        int nOk = tip.FUN_1409e26b0(FUN_1405c2690(CStringW(L"s_meratmarket_tooltip_charge"), strCharge));
        if (nOk != 0)
        {
            tip.FUN_1409c6dc0(5);
            FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
        }
    }
    else if (_stricmp("m_selectedItem", strName) == 0)
    {
        int nIndex = pArgs->FUN_1422b8a10();
        if (nIndex < 0)
            return;
        MS2Ptr<CItem> spItem = FUN_1413191f0(nIndex);
        if (spItem == 0)
            return;
        DragSlotBag* pBag = FUN_140c54520(FUN_1422c8e90(m_strKey));
        if (pBag != 0)
        {
            DragSlot* pSlot = FUN_140cfe6c0(FUN_1422cd070(pBag, nIndex));
            if (pSlot != 0)
                pSlot->vfunc_0(pRetVal);
        }
    }
}

// @0x141317d60
void UIMeratMarketRegisterDialog::OnLoadComplete()
{
    UIModalDialog::OnLoadComplete();
    if (FUN_140ba28d0(&m_30, 0))
        return;
    if (m_strKey.IsEmpty())
        m_strKey = GetTypeName();
    if (m_nMode == 0)
        m_spRequest.AssignRaw(new CMeratMarketPacket::UgcAddProduct());
    else
        m_spRequest.AssignRaw(new CMeratMarketPacket::UgcResaleProduct());
    bool bNew = m_nMode == 0 && m_keyResale.m_nPremiumId == 0 && m_keyResale.m_nUgcId == 0;
    __int64 nAdFee = FUN_1402bac90(MrdFeeValue());
    int nSaleDay = FUN_14025a620(MrdSaleDayValue());
    FUN_14131ac80(0, MS2Ptr<CItem>(0), 1);
    ASObj objData(2);
    objData.FUN_1407cbb20("saleDay", FUN_1408116a0(0xa39, nSaleDay));
    objData.FUN_1407cbb20("ad", FUN_14086d060(0xa3a, nAdFee));
    objData.FUN_1407cbb20("royalty", GetStringCommon(0xa3b));
    objData.FUN_1407cbbe0("onlyShowEnableDesigns", m_bOnlyEnabled);
    unsigned __int64 nMinPrice = FUN_1406a6d50(MrdMinPriceValue());
    unsigned __int64 nMaxPrice = FUN_1406a6d50(MrdMaxPriceValue());
    objData.FUN_1409c0d20("defaultSaleDay", nSaleDay);
    objData.FUN_1409c0d20("defaultMinPrice", (unsigned int)nMinPrice);
    objData.FUN_1409c0d20("defaultMaxPrice", (unsigned int)nMaxPrice);
    FUN_14131b4e0(objData, 0);
    objData.FUN_1407cbb20("errPriceMsg", FUN_14131b420(nMinPrice, nMaxPrice));
    ASObj objGrid(2);
    m_30->Invoke("initData", m_strKey, bNew, Scaleform::GFx::Value(objData.FUN_1422bb870()),
                 Scaleform::GFx::Value(objGrid.FUN_1422bb870()));
    FUN_141318ef0(FUN_14131ca80());
    if (bNew)
    {
        int nRows = FUN_1409c17e0(objGrid.FUN_1422baa20("slotRowCount"));
        int nColumns = FUN_1409c17e0(objGrid.FUN_1422baa20("slotColumnCount"));
        FUN_14131a880(m_strKey, nColumns, nRows);
    }
    else
    {
        if (FUN_14131a100(m_keyResale) == 0)
            FUN_1403ed2b0()->FUN_141adc5d0(0x4ec5);
    }
}

// @0x141318480
int UIMeratMarketRegisterDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnChangeSelectedIndex", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14131c570(data);
        return 1;
    }
    else if (_stricmp("GetAlreadyRegistIndex", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14131c9d0(data);
        return 1;
    }
    else if (_stricmp("OnClickRegister", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14131b810(data);
        return 1;
    }
    else if (_stricmp("OnClickReRegister", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14131c010(data);
        return 1;
    }
    else if (_stricmp("OnGetFee", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14131c4e0(data);
        return 1;
    }
    else if (_stricmp("OnGetTotalFee", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14131c4e0(data);
        return 1;
    }
    return 0;
}

// @0x1413187d0
int UIMeratMarketRegisterDialog::vfunc_13()
{
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (vfunc_55() == 1 || FUN_140ba28d0(&m_30, 0))
        return 0;
    if (FUN_140b632f0()->FUN_1422d4980(m_e0) == this)
    {
        CString strKey("");
        if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0) != 0)
            strKey = "onTabKey";
        if (!strKey.IsEmpty())
        {
            m_30->Invoke("onProcessKey", strKey);
            return 1;
        }
        return 0;
    }
    return 0;
}

// @0x141318970
void UIMeratMarketRegisterDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (FUN_140ba28d0(&m_30, 0))
        return;
    if (FUN_1418ffe80(m_nFlags, 1) != 0)
    {
        FUN_14131ac80(0, m_spSelected, 1);
        FUN_1418ffef0(&m_nFlags, 1);
    }
}

// @0x141318a20
void UIMeratMarketRegisterDialog::FUN_141318a20(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (FUN_140ba28d0(&m_30, 0) || spProduct == 0)
        return;
    FUN_1418ffec0(&m_nFlags, 1);
}

// @0x141318aa0
void UIMeratMarketRegisterDialog::FUN_141318aa0(MS2Ptr<CMeratMarketProduct> spProduct)
{
    if (FUN_140ba28d0(&m_30, 0) || spProduct == 0)
        return;
    int nIndex = FUN_1413197a0(&spProduct->m_ugc);
    if (nIndex == -1)
        return;
    int nNewIndex = -1;
    if (0 < m_nAlreadyIndex)
    {
        int nAlready;
        m_nAlreadyIndex = m_nAlreadyIndex - 1;
        if (m_nAlreadyIndex < 0)
            nAlready = 0;
        else
            nAlready = m_nAlreadyIndex;
        m_nAlreadyIndex = nAlready;
        MS2Ptr<CItem> spMoved = m_items[nIndex];
        m_items.RemoveAt(nIndex, 1);
        nNewIndex = (int)m_items.GetCount();
        m_items.Add(spMoved);
    }
    FUN_1418ffec0(&m_nFlags, 2);
    m_30->FUN_1409ba0d0("registerItemComplete", nIndex, nNewIndex);
}

// @0x141318cc0
void UIMeratMarketRegisterDialog::FUN_141318cc0()
{
    if (MS2Ptr<Unk_MrdInput> spTag = FUN_140e35bd0("m_inputTag1"))
        spTag->FUN_1422e0ab0(L"");
    if (MS2Ptr<Unk_MrdInput> spTag = FUN_140e35bd0("m_inputTag2"))
        spTag->FUN_1422e0ab0(L"");
    if (MS2Ptr<Unk_MrdInput> spTag = FUN_140e35bd0("m_inputTag3"))
        spTag->FUN_1422e0ab0(L"");
}

// @0x141318ef0
void UIMeratMarketRegisterDialog::FUN_141318ef0(int nMaxChars)
{
    if (MS2Ptr<Unk_MrdInput> spTag = FUN_140e35bd0("m_inputTag1"))
        spTag->FUN_1422e0d60(nMaxChars);
    if (MS2Ptr<Unk_MrdInput> spTag = FUN_140e35bd0("m_inputTag2"))
        spTag->FUN_1422e0d60(nMaxChars);
    if (MS2Ptr<Unk_MrdInput> spTag = FUN_140e35bd0("m_inputTag3"))
        spTag->FUN_1422e0d60(nMaxChars);
}

// @0x1413190c0
void UIMeratMarketRegisterDialog::FUN_1413190c0(int nMode, Unk_MeratProductKey key)
{
    m_nMode = nMode;
    m_keyResale = key;
}

// @0x141319100
bool UIMeratMarketRegisterDialog::FUN_141319100(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        if (m_spRequest.get() != 0)
            FUN_14131aa90(m_spRequest);
    }
    return true;
}

// @0x141319180
bool UIMeratMarketRegisterDialog::FUN_141319180(int nButton, const CMsgBoxData& data)
{
    if (nButton == 0)
    {
        if (m_30.get() != 0)
            m_30->Invoke("forceUpdateFee");
    }
    return true;
}

// @0x1413191f0
MS2Ptr<CItem> UIMeratMarketRegisterDialog::FUN_1413191f0(int nIndex)
{
    if (nIndex < 0 || nIndex >= (int)m_items.GetCount())
        return MS2Ptr<CItem>(0);
    if (m_items.IsEmpty())
        return MS2Ptr<CItem>(0);
    return m_items[nIndex];
}

// The item can still be found where the player keeps it: the bag and the worn items, or the warehouse and the cube stock.
// @0x1413192d0
bool UIMeratMarketRegisterDialog::FUN_1413192d0(__int64 nItemUid, MS2Ptr<CItem> spHint)
{
    MS2Ptr<CItem> spItem(0);
    if (spHint.get() != 0)
    {
        if (FUN_140527840(spHint.operator->())->FUN_14053cb80())
        {
            spItem = DAT_143ab2e20.FUN_1408fbf90(nItemUid);
            if (spItem == 0)
            {
                MS2Ptr<Unk_MrdStockItem> spMapItem = DAT_143ab2e50.FUN_140dfc8f0(nItemUid);
                return spMapItem.get() != 0;
            }
        }
        else
        {
            spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
            if (spItem == 0)
            {
                PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
                if (pPlayer != 0)
                {
                    MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(pPlayer)->FUN_1411e1580(nItemUid);
                    if (spEquip.get() != 0)
                        spItem = spEquip->GetItem();
                }
            }
        }
    }
    else
    {
        spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
        if (spItem == 0)
        {
            PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
            if (pPlayer != 0)
            {
                MS2Ptr<CEquipItem> spEquip = FUN_1416561a0(pPlayer)->FUN_1411e1580(nItemUid);
                if (spEquip.get() != 0)
                    spItem = spEquip->GetItem();
            }
        }
        if (spItem == 0)
        {
            spItem = DAT_143ab2e20.FUN_1408fbf90(nItemUid);
            if (spItem == 0)
            {
                MS2Ptr<Unk_MrdStockItem> spMapItem = DAT_143ab2e50.FUN_140dfc8f0(nItemUid);
                return spMapItem.get() != 0;
            }
        }
    }
    return spItem.get() != 0;
}

// @0x1413197a0
int UIMeratMarketRegisterDialog::FUN_1413197a0(const CUgcMarketProduct* pProduct)
{
    if (pProduct == 0)
        return -1;
    if (m_items.IsEmpty())
        return -1;
    size_t nCount = m_items.GetCount();
    for (size_t i = 0; i < nCount; i = i + 1)
    {
        MS2Ptr<CItem> spItem = m_items[i];
        if (spItem == 0)
            continue;
        if (pProduct->FUN_140896310() == 0)
        {
            if (spItem->FUN_140528380()->m_n18 == pProduct->m_look.m_n18)
                return (int)i;
        }
        else
        {
            if (spItem->FUN_140526a50() == pProduct->m_music.m_n18)
                return (int)i;
        }
    }
    return -1;
}

// Collect the items that can be listed: the bag, the worn items, the warehouse and the cube stock; the ones that are
// already on the market go last.
// @0x141319920
void UIMeratMarketRegisterDialog::FUN_141319920(ItemArray& arrItems)
{
    arrItems.RemoveAll();
    m_nAlreadyIndex = -1;
    Unk_MrdMarket* pMarket = FUN_140939a00();
    if (pMarket == 0)
        return;
    Unk_MrdOwner owner;
    owner.FUN_1409aff60();
    owner.m_nAccount = DAT_143ab2820;
    owner.m_nType = DAT_143ab2830;
    owner.m_pCharacter = (void*)DAT_143ab2838;
    owner.m_n18 = DAT_143ab2834;
    ItemArray arrCandidates;
    DAT_143ab2a90.FUN_140a61010(0, &owner.m_nAccount, arrCandidates);
    DAT_143ab2a90.FUN_140a61010(1, &owner.m_nAccount, arrCandidates);
    DAT_143ab2a90.FUN_140a61010(2, &owner.m_nAccount, arrCandidates);
    if (FUN_140166410()->FUN_14036d570(0xe9) && FUN_140166410()->FUN_14036d570(0xec))
        DAT_143ab2a90.FUN_140a61010(7, &owner.m_nAccount, arrCandidates);
    DAT_143ab2e20.FUN_1408fbd30(&owner, arrCandidates);
    DAT_143ab2e50.FUN_140dfcd00(&owner, arrCandidates);
    if (FUN_140166410()->FUN_14036d570(0xa9))
        DAT_143ab2a90.FUN_140a61010(4, &owner.m_nAccount, arrCandidates);
    ATL::CAtlList<MS2Ptr<CEquipItem> > listEquip(10);
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0)
        FUN_1411e1ce0(FUN_1416561a0(pPlayer), listEquip, 1);
    if (!listEquip.IsEmpty())
    {
        for (POSITION pos = listEquip.GetHeadPosition(); pos != 0; listEquip.GetNext(pos))
        {
            MS2Ptr<CItem> spWorn = listEquip.GetAt(pos)->GetItem();
            if (spWorn.get() != 0 && FUN_1406a5a50(spWorn, &owner.m_nAccount))
                arrCandidates.Add(spWorn);
        }
    }
    if (arrCandidates.IsEmpty())
        return;
    size_t nCount = arrCandidates.GetCount();
    __int64 nLastUnlisted = nCount - 1;
    ItemArray arrListed;
    for (size_t i = 0; i < nCount; ++i)
    {
        MS2Ptr<CItem> spItem = arrCandidates[i];
        if (spItem.get() != 0)
        {
            if (spItem->FUN_140525f10() != 0 || spItem->FUN_140526010() != 0)
            {
                Unk_ItemUgcInfo* pUgc = spItem->FUN_1405278d0();
                __int64 nUgcUid = pUgc->m_nUgcUid;
                if (nUgcUid != 0 && m_mapUgc.Lookup(nUgcUid) == 0)
                {
                    m_mapUgc.SetAt(nUgcUid, spItem);
                    if (FUN_141319f10(spItem))
                    {
                        arrListed.Add(spItem);
                        --nLastUnlisted;
                    }
                    else
                        arrItems.Add(spItem);
                }
            }
            else if (spItem->FUN_140525790())
            {
                if (FUN_141319f10(spItem))
                {
                    arrListed.Add(spItem);
                    --nLastUnlisted;
                }
                else
                    arrItems.Add(spItem);
            }
        }
    }
    m_nAlreadyIndex = (int)arrItems.GetCount();
    if (!arrListed.IsEmpty())
        arrItems.Append(arrListed);
}

// The item is already offered on the market.
// @0x141319f10
bool UIMeratMarketRegisterDialog::FUN_141319f10(MS2Ptr<CItem> spItem)
{
    if (spItem == 0)
        return false;
    if (spItem->FUN_140525f10() != 0 || spItem->FUN_140526010() != 0)
    {
        Unk_ItemUgcInfo* pUgc = spItem->FUN_1405278d0();
        return FUN_140939a00()->FUN_140d55a10(pUgc->m_nUgcUid).get() != 0;
    }
    else if (spItem->FUN_140525790())
    {
        return FUN_140939a00()->FUN_140d55b60(spItem->FUN_140526a50()).get() != 0;
    }
    return false;
}

// Open the "list again" form of a sold product.
// @0x14131a100
bool UIMeratMarketRegisterDialog::FUN_14131a100(Unk_MeratProductKey key)
{
    if (FUN_140ba28d0(&m_30, 0))
        return false;
    m_spSelected = 0;
    MS2Ptr<CMeratMarketProduct> spProduct = FUN_140939a00()->FUN_140d55800(key);
    if (spProduct == 0)
        return false;
    if (spProduct->IsUgc() == 0)
        return false;
    int nItemId = spProduct->GetItemId();
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return false;
    ASSlot slot(2);
    CUgcMarketProduct* pUgc = &spProduct->m_ugc;
    int nGender = 2;
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0)
        nGender = FUN_141658e60(pPlayer);
    slot.FUN_1407cbbe0("disable", spData->FUN_14053c940(nGender) == 0);
    CStringW strWarning;
    if (spData->FUN_14053cd10())
        strWarning = L"$s_meratmarket_text_register_notice_warning_music_score";
    slot.FUN_1407cbb20("warningMsg", CStringW(strWarning));
    slot.FUN_1407cbb20("productOID", reinterpret_cast<const Unk_MrdOid*>(&spProduct->m_key)->FUN_1409b0470());
    slot.FUN_1409c1180("salePrice", pUgc->m_n50);
    slot.FUN_1407cbb20("itemName", spProduct->GetName());
    MS2Ptr<CItem> spShown = FUN_140ebc070(spProduct.get());
    if (spShown == 0)
        return false;
    m_spSelected = spShown;
    slot.FUN_1409c3860(spShown.get(), pPlayer, 0x415);
    ASTooltip tip(pPlayer, 4, 2);
    if (FUN_140ebbb30(&tip, spShown, spProduct, false, false) != 0)
        slot.FUN_1409adbe0("tooltip", Scaleform::GFx::Value(tip.FUN_1422bb870()));
    slot.FUN_1407cbb20("desc", pUgc->GetStr208());
    slot.FUN_1407cbb20("saleTags", pUgc->GetStr200Head());
    __int64 nMaxPrice = 0;
    __int64 nMinPrice = 0;
    FUN_1406a5480(spData, &nMinPrice, &nMaxPrice);
    slot.FUN_1409c0d20("minPrice", (unsigned int)nMinPrice);
    slot.FUN_1409c0d20("maxPrice", (unsigned int)nMaxPrice);
    slot.FUN_1407cbb20("errPriceMsg", FUN_14131b420(nMinPrice, nMaxPrice));
    FUN_1418ffec0(&m_nFlags, 1);
    FUN_14131b4e0(slot, 0);
    m_30->Invoke("buildReSaleProduct", Scaleform::GFx::Value(slot.FUN_1422bb870()));
    return true;
}

// Build the item grid.
// @0x14131a880
bool UIMeratMarketRegisterDialog::FUN_14131a880(CString& strItems, unsigned int nColumns, unsigned int nRows)
{
    if (FUN_140ba28d0(&m_30, 0))
        return false;
    if (nColumns <= 0 || nRows <= 0)
        return false;
    m_items.RemoveAll();
    m_mapUgc.RemoveAll();
    FUN_141319920(m_items);
    MS2Ptr<CItem> (*pfnGet)(const ItemArray&, int) = FUN_141420330;
    FUN_14141f970(strItems);
    size_t nCount = m_items.GetCount();
    unsigned int nSlots = nRows * nColumns;
    unsigned int nCols = nColumns;
    if (nCount <= nSlots)
        nCount = nSlots;
    else
    {
        div_t dv = div((int)nCount, nCols);
        int nLines = dv.quot;
        if (dv.rem > 1)
            ++nLines;
        nCount = nCols * nLines;
    }
    FUN_14141f770(strItems, (unsigned int)nCount, m_items, pfnGet, 0x1d15, 0);
    m_30->Invoke("buildUGCItems", strItems);
    return true;
}

// Send the request: the fee is checked once more.
// @0x14131aa90
void UIMeratMarketRegisterDialog::FUN_14131aa90(MS2Ptr<CMeratMarketPacket::UgcAddProductBase> spRequest)
{
    if (spRequest == 0)
        return;
    __int64 nFee = 0;
    if (!FUN_14131ae60(spRequest->enabled, true, &nFee))
        return;
    spRequest->price = nFee;
    if (m_nMode == 0)
    {
        FUN_140939a00()->FUN_140d54560(MS2Ptr<CMeratMarketPacket::UgcAddProduct>(dynamic_cast<CMeratMarketPacket::UgcAddProduct*>(spRequest.get())));
        FUN_14138bf00(FUN_1409331e0(), 5, 0, 0);
    }
    else
        FUN_140939a00()->FUN_140d547f0(MS2Ptr<CMeratMarketPacket::UgcResaleProduct>(dynamic_cast<CMeratMarketPacket::UgcResaleProduct*>(spRequest.get())));
}

// @0x14131ac50
__int64 UIMeratMarketRegisterDialog::FUN_14131ac50()
{
    return *FUN_1402c05b0(MrdFeeValue());
}

// The register fee of an item; bRecalc refreshes the cached fee.
// @0x14131ac80
__int64 UIMeratMarketRegisterDialog::FUN_14131ac80(bool bAddBase, MS2Ptr<CItem> spItem, bool bRecalc)
{
    __int64 nFee = 0;
    if (bRecalc)
    {
        if (spItem.get() != 0 ? true : false)
        {
            if (FUN_140527840(spItem.operator->())->FUN_14053cd10() == false)
            {
                int nLevel = FUN_140939a00()->FUN_140d5b170();
                nFee = FUN_1406a5240(nLevel);
            }
        }
        __int64 nOldFee = m_nFee;
        m_nFee = nFee;
        if (FUN_1418ffe80(m_nFlags, 2) != 0 && nOldFee != nFee)
        {
            m_30->Invoke("invalidateFee");
            FUN_1418ffef0(&m_nFlags, 2);
        }
        FUN_1418ffef0(&m_nFlags, 1);
    }
    else
        nFee = m_nFee;
    return bAddBase ? nFee + FUN_14131ac50() : nFee;
}

// @0x14131ae60
bool UIMeratMarketRegisterDialog::FUN_14131ae60(bool bAddBase, bool bCheckStale, __int64* pFee)
{
    __int64 nFee = 0;
    if (bCheckStale)
    {
        __int64 nCached = FUN_14131ac80(bAddBase, m_spSelected, false);
        nFee = FUN_14131ac80(bAddBase, m_spSelected, true);
        if (nCached != nFee)
        {
            FUN_140d74390(GetStringCommonByKey(L"s_ugc_itemedit_error_check_register_fee"), 0,
                Delegate<bool(int, const CMsgBoxData&)>(this, &UIMeratMarketRegisterDialog::FUN_141319180));
            return false;
        }
    }
    else
        nFee = FUN_14131ac80(bAddBase, m_spSelected, false);
    if (pFee != 0)
        *pFee = nFee;
    return FUN_1418ff110(3, nFee, true);
}

// @0x14131b0e0
bool UIMeratMarketRegisterDialog::FUN_14131b0e0(const CStringW& strDescription, const CStringW& strName)
{
    int nKind = 0x21;
    {
        Unk_MrdBlockRef block = FUN_140a6a830()->FUN_140a2f620(nKind);
        if (FUN_1401cb3d0(&block) != 0)
        {
            FUN_140a2ff20(&block, nKind, 0);
            return false;
        }
    }
    if (Unk_MrdFilter* pFilter = FUN_14025e7d0()->FUN_140229a50().get())
    {
        CStringW strBad;
        if (pFilter->FUN_140226100(strDescription, strBad) != 0)
        {
            FUN_140d73aa0(strBad, 0, 0, L"");
            return false;
        }
        if (pFilter->FUN_140226160(strName, strBad) != 0)
        {
            FUN_140d73aa0(strBad, 0, 0, L"");
            return false;
        }
    }
    if (strDescription.GetLength() > 200)
    {
        int nLimit = 200;
        CStringW strText = FUN_1408116a0(0xa38, nLimit);
        FUN_140d73aa0(strText, 0, 0, L"");
        return false;
    }
    return true;
}

// @0x14131b420
CStringW UIMeratMarketRegisterDialog::FUN_14131b420(__int64 nMin, __int64 nMax)
{
    return FUN_140632a60(0xa3c, FUN_1409404f0(nMin), FUN_1409404f0(nMax));
}

// Put the fee texts into obj.
// @0x14131b4e0
void UIMeratMarketRegisterDialog::FUN_14131b4e0(ASObj& obj, bool bAddBase)
{
    CStringW strFee;
    CStringW strTotalFee;
    if (m_spSelected.get() != 0)
    {
        __int64 nTotal = FUN_14131ac80(bAddBase, m_spSelected, FUN_1418ffe80(m_nFlags, 1));
        strFee = FUN_1418fec00(3, m_nFee, 0);
        strTotalFee = FUN_1418fec00(3, nTotal, 0);
    }
    else
    {
        strFee = GetStringCommonByKey(L"s_meratmarket_register_fee_default");
        strTotalFee = GetStringCommonByKey(L"s_meratmarket_register_total_fee_default");
    }
    obj.FUN_1407cbb20("strRegistFee", CStringW(strFee));
    obj.FUN_1407cbb20("strTotalFee", CStringW(strTotalFee));
}

// @0x14131b7e0
void UIMeratMarketRegisterDialog::FUN_14131b7e0()
{
    m_spSelected = 0;
}

// "OnClickRegister"
// @0x14131b810
void UIMeratMarketRegisterDialog::FUN_14131b810(ASData& data)
{
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    ASObj obj(value, 2);
    if (obj.FUN_1422ba9a0())
        return;
    CString strGuid;
    obj.FUN_1422bac00("itemGUID", strGuid);
    int nIndex = data.FUN_1422b8a10();
    unsigned int nSaleDay = data.FUN_1422b8b10();
    CStringW strName = data.FUN_1422b8f40();
    CStringW strDescription = data.FUN_1422b8f40();
    bool bAdvertise = data.FUN_1422b8a90();
    __int64 nItemUid = FUN_141b71960(strGuid);
    MS2Ptr<CItem> spItem = FUN_1413191f0(nIndex);
    if (spItem.get() != 0 ? true : false)
    {
        if (spItem->FUN_140526a50() != nItemUid)
            spItem = 0;
    }
    bool bValid = FUN_1413192d0(nItemUid, spItem);
    if (!bValid)
    {
        FUN_140d73bc0(0xa3e, 0, 0, L"");
        return;
    }
    if (FUN_141319f10(spItem))
    {
        FUN_140d73bc0(0xa3f, 0, 0, L"");
        return;
    }
    if (!FUN_140633d50(spItem))
    {
        FUN_140d73bc0(0xa07, 0, 0, L"");
        return;
    }
    if (FUN_140ebc4a0() == 0)
        return;
    if (!FUN_14131ae60(bAdvertise, false, 0))
        return;
    if (!FUN_14131b0e0(strDescription, strName))
        return;
    if (m_spRequest)
    {
        {
            MS2Ptr<CMeratMarketPacket::UgcAddProduct> spAdd(dynamic_cast<CMeratMarketPacket::UgcAddProduct*>(m_spRequest.get()));
            if (spAdd.get() != 0)
                spAdd->product = nItemUid;
        }
        m_spRequest->id = nSaleDay;
        m_spRequest->enabled = bAdvertise;
        m_spRequest->name = strName;
        m_spRequest->description = strDescription;
    }
    MS2Ptr<Unk_MrdMsgBox> spBox = FUN_140d748b0(0, GetStringCommon(0x9da), GetStringCommon(0x9db),
        Delegate<bool(int, const CMsgBoxData&)>(this, &UIMeratMarketRegisterDialog::FUN_141319100));
}

// "OnClickReRegister"
// @0x14131c010
void UIMeratMarketRegisterDialog::FUN_14131c010(ASData& data)
{
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    ASObj obj(value, 2);
    if (obj.FUN_1422ba9a0())
        return;
    CString strOid;
    obj.FUN_1422bac00("productOID", strOid);
    int nIndex = data.FUN_1422b8a10();
    unsigned int nSaleDay = data.FUN_1422b8b10();
    CStringW strName = data.FUN_1422b8f40();
    CStringW strDescription = data.FUN_1422b8f40();
    bool bAdvertise = data.FUN_1422b8a90();
    Unk_MeratProductKey key;
    reinterpret_cast<Unk_MrdOid*>(&key)->FUN_1409c1640(FUN_14016a730(strOid, 0));
    if (!FUN_14131ae60(bAdvertise, false, 0))
        return;
    if (!FUN_14131b0e0(strDescription, strName))
        return;
    if (m_spRequest)
    {
        {
            MS2Ptr<CMeratMarketPacket::UgcResaleProduct> spResale(dynamic_cast<CMeratMarketPacket::UgcResaleProduct*>(m_spRequest.get()));
            if (spResale.get() != 0)
                spResale->product = key.m_nUgcId;
        }
        m_spRequest->id = nSaleDay;
        m_spRequest->enabled = bAdvertise;
        m_spRequest->name = strName;
        m_spRequest->description = strDescription;
    }
    MS2Ptr<Unk_MrdMsgBox> spBox = FUN_140d748b0(0, GetStringCommon(0x9da), GetStringCommon(0x9db),
        Delegate<bool(int, const CMsgBoxData&)>(this, &UIMeratMarketRegisterDialog::FUN_141319100));
}

// "OnGetFee" / "OnGetTotalFee"
// @0x14131c4e0
void UIMeratMarketRegisterDialog::FUN_14131c4e0(ASData& data)
{
    bool bAddBase = data.FUN_1422b8a90();
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    ASObj obj(value, 2);
    FUN_14131b4e0(obj, bAddBase);
}

// "OnChangeSelectedIndex"
// @0x14131c570
void UIMeratMarketRegisterDialog::FUN_14131c570(ASData& data)
{
    int nIndex = data.FUN_1422b8a10();
    bool bAddBase = data.FUN_1422b8a90();
    MS2Ptr<CItem> spOld(m_spSelected);
    m_spSelected = 0;
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    ASObj obj(value, 2);
    if (nIndex >= 0)
        m_spSelected = FUN_1413191f0(nIndex);
    bool bChanged = false;
    if (m_spSelected)
    {
        bool bListed = FUN_141319f10(m_spSelected);
        CStringW strWarning;
        if (bListed)
            strWarning = L"$s_meratmarket_text_register_notice_already";
        else if (m_spSelected->FUN_140525790())
            strWarning = L"$s_meratmarket_text_register_notice_warning_music_score";
        obj.FUN_1407cbb20("warningMsg", CStringW(strWarning));
        __int64 nMaxPrice = 0;
        __int64 nMinPrice = 0;
        FUN_1406a5480(MS2Ptr<CItemData>(FUN_140527840(m_spSelected.operator->())), &nMinPrice, &nMaxPrice);
        obj.FUN_1409c0d20("minPrice", (int)nMinPrice);
        obj.FUN_1409c0d20("maxPrice", (int)nMaxPrice);
        obj.FUN_1407cbb20("errPriceMsg", FUN_14131b420(nMinPrice, nMaxPrice));
        FUN_141276180(s_marketItemChoice, "");
        if (spOld)
        {
            bChanged = FUN_140527840(spOld.operator->())->FUN_14053c620() != FUN_140527840(m_spSelected.operator->())->FUN_14053c620();
        }
        else
            bChanged = true;
    }
    else
        bChanged = spOld ? 1 : 0;
    if (bChanged)
        FUN_1418ffec0(&m_nFlags, 1);
    FUN_14131b4e0(obj, bAddBase);
}

// "GetAlreadyRegistIndex"
// @0x14131c9d0
void UIMeratMarketRegisterDialog::FUN_14131c9d0(ASData& data)
{
    Scaleform::GFx::Value value = data.FUN_1422b9260();
    bool bOnlyEnabled = data.FUN_1422b8a90();
    ASObj obj(value, 2);
    obj.FUN_1407cb9c0("startIndex", m_nAlreadyIndex);
    m_bOnlyEnabled = bOnlyEnabled;
}

// @0x14131ca80
int UIMeratMarketRegisterDialog::FUN_14131ca80()
{
    int nLimit = FUN_14025a620(MrdTagLimitValue());
    int nLanguage = FUN_1406516a0();
    if (nLanguage >= 0)
    {
        if (nLanguage > 7)
        {
        }
        else
        {
            return nLimit;
        }
    }
    return nLimit;
}

// ---- CMeratMarketPacket::UgcAddProduct and friends ----

// @0x14131cfb0
CMeratMarketPacket::UgcAddProduct::UgcAddProduct()
    : product(0)
{
}

// @0x14131cff0
CMeratMarketPacket::UgcAddProductBase::UgcAddProductBase()
    : id(0), enabled(false), price(0)
{
}

// @0x14131d070
CMeratMarketPacket::UgcResaleProduct::UgcResaleProduct()
    : product(0)
{
}


// @0x14131d120
CMeratMarketPacket::UgcAddProductBase::~UgcAddProductBase()
{
}

// @0x14131d100 ~UgcAddProduct and @0x14131d170 ~UgcResaleProduct are implicit: the exe dtors never reset the vptr.

MS2_REPLACE_METHOD(0x141317A50, UIMeratMarketRegisterDialog, vfunc_49, 778, 0xBDCED211);
MS2_REPLACE_METHOD(0x141317D60, UIMeratMarketRegisterDialog, OnLoadComplete, 1809, 0x1158A427);
MS2_REPLACE_METHOD(0x141318480, UIMeratMarketRegisterDialog, vfunc_28, 811, 0x70921477);
MS2_REPLACE_METHOD(0x1413187D0, UIMeratMarketRegisterDialog, vfunc_13, 398, 0x429B90DE);
MS2_REPLACE_METHOD(0x141318970, UIMeratMarketRegisterDialog, vfunc_15, 163, 0xB59734C4);
MS2_REPLACE_METHOD(0x141318CC0, UIMeratMarketRegisterDialog, FUN_141318cc0, 551, 0x321E93F0);
MS2_REPLACE_METHOD(0x141318EF0, UIMeratMarketRegisterDialog, FUN_141318ef0, 444, 0x3E58C313);
MS2_REPLACE_METHOD(0x1413191F0, UIMeratMarketRegisterDialog, FUN_1413191f0, 204, 0x53827808);
MS2_REPLACE_METHOD(0x1413197A0, UIMeratMarketRegisterDialog, FUN_1413197a0, 367, 0x9A68B28B);
MS2_REPLACE_METHOD(0x141319920, UIMeratMarketRegisterDialog, FUN_141319920, 1500, 0x674985B1);
MS2_REPLACE_METHOD(0x14131A100, UIMeratMarketRegisterDialog, FUN_14131a100, 1905, 0xE12EBD40);
MS2_REPLACE_METHOD(0x14131A880, UIMeratMarketRegisterDialog, FUN_14131a880, 521, 0xFC154478);
MS2_REPLACE_METHOD(0x14131AC50, UIMeratMarketRegisterDialog, FUN_14131ac50, 36, 0xF68D1F5E);
MS2_REPLACE_METHOD(0x14131AE60, UIMeratMarketRegisterDialog, FUN_14131ae60, 622, 0x51D73AE5);
MS2_REPLACE_METHOD(0x14131B0E0, UIMeratMarketRegisterDialog, FUN_14131b0e0, 824, 0xDC690F8B);
MS2_REPLACE_METHOD(0x14131B420, UIMeratMarketRegisterDialog, FUN_14131b420, 176, 0x3FAE4D71);
MS2_REPLACE_METHOD(0x14131B4E0, UIMeratMarketRegisterDialog, FUN_14131b4e0, 750, 0x148F6202);
MS2_REPLACE_METHOD(0x14131B810, UIMeratMarketRegisterDialog, FUN_14131b810, 2031, 0x46D6FC81);
MS2_REPLACE_METHOD(0x14131C010, UIMeratMarketRegisterDialog, FUN_14131c010, 1211, 0x57776BC0);
MS2_REPLACE_METHOD(0x14131C4E0, UIMeratMarketRegisterDialog, FUN_14131c4e0, 138, 0x2A2D8A17);
MS2_REPLACE_METHOD(0x14131C570, UIMeratMarketRegisterDialog, FUN_14131c570, 1110, 0x151B536B);
MS2_REPLACE_METHOD(0x14131C9D0, UIMeratMarketRegisterDialog, FUN_14131c9d0, 164, 0xD1550D59);
MS2_REPLACE_METHOD(0x14131CA80, UIMeratMarketRegisterDialog, FUN_14131ca80, 72, 0x0B2CCBCE);
