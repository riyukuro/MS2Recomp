// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIVIPGoodsShopDialog: the VIP membership goods list. See
// uivipgoodsshopdialog.h.
// MS2-UNIT: ?\uivipgoodsshopdialog.cpp
// MS2-GUESS-LOOKALIKES (the vector / sort / CAtlArray glue of the goods rows is byte-identical to other instances)
// MS2-RANGE: 0x140fb9ac0-0x140fc07a0 .text$mn
// MS2-RANGE: 0x1400e2570-0x1400e28a0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0PEAVUIVIPGoodsShopDialog@@P80@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z$0A@@?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@QEAA@AEBQEAVUIVIPGoodsShopDialog@@AEBQ82@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@Z 0x140fbd670 ; order
// MS2-PIN: ??$?0PEAVUIVIPGoodsShopDialog@@P80@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z$0A@@?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@QEAA@AEBQEAVUIVIPGoodsShopDialog@@AEBQ82@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@Z 0x140fbd740 ; order
// MS2-PIN: ??$?8PEAVUIVIPGoodsShopDialog@@P80@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@YA_NAEBU?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@0@0@Z 0x140fbd850 ; order
// MS2-PIN: ??$?8PEAVUIVIPGoodsShopDialog@@P80@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@YA_NAEBU?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@0@0@Z 0x140fbd8c0 ; order
// MS2-PIN: ??$forward@AEBQ8UIVIPGoodsShopDialog@@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@YAAEBQ8UIVIPGoodsShopDialog@@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@ZAEBQ81@EAA_N012@Z@Z 0x140fbf210 ; order
// MS2-PIN: ??$forward@AEBQEAVUIVIPGoodsShopDialog@@@std@@YAAEBQEAVUIVIPGoodsShopDialog@@AEBQEAV1@@Z 0x140fbf230 ; prop
// MS2-PIN: ??$make_pair@AEBQEAVUIVIPGoodsShopDialog@@AEBQ81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@YA?AU?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@0@AEBQEAVUIVIPGoodsShopDialog@@AEBQ82@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@Z 0x140fbf290 ; order
// MS2-PIN: ??$make_pair@AEBQEAVUIVIPGoodsShopDialog@@AEBQ81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@YA?AU?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@0@AEBQEAVUIVIPGoodsShopDialog@@AEBQ82@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@Z 0x140fbf2e0 ; order
// MS2-PIN: ??0?$MS2Ptr@VTVIPGoodsBillDataParam@@@@QEAA@PEAVTVIPGoodsBillDataParam@@@Z 0x140fbf570 ; unique
// MS2-PIN: ?vfunc_2@?$DelegateImpl@U?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@UEAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z 0x140fc0410 ; unique
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@UEAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z 0x140fc0490 ; unique
// MS2-PIN: ??$Call@VUIVIPGoodsShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@?$DelegateImpl@U?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@CA_NAEAU?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@PEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z 0x140fc0500 ; unique
// MS2-PIN: ??$Call@VUIVIPGoodsShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@?$DelegateImpl@U?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@CA_NAEAU?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@V?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z 0x140fc0590 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140fc0610 ; order
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140fc0670 ; order
// MS2-PIN: ??RUnk_VgGoodsOrder@@QEBA_NAEBV?$MS2Ptr@VCVIPGoods@@@@0@Z 0x140fbf980
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@std@@@?$Delegate@$$A6A_NV?$MS2Ptr@VTMarketBillDataParam@@@@AEBV?$CAtlMap@W4ePayType@@_JV?$CElementTraits@W4ePayType@@@ATL@@V?$CElementTraits@_J@3@@ATL@@@Z@@6B@ 0x142e913c0
// MS2-PIN: ??_7?$DelegateImpl@U?$pair@PEAVUIVIPGoodsShopDialog@@P81@EAA_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@std@@@?$Delegate@$$A6A_NPEAVValue@GFx@Scaleform@@AEAVASData@@V?$MS2Ptr@VTMarketBillDataParam@@@@@Z@@6B@ 0x142e913e8
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uivipgoodsshopdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uivipgoodsshopdialog.h"
#include "uimarketbilldialog.h"
#include "uimessageboxdata.h"
#include "mypc.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/commonfiles/vipgoods.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/placeholder/asbilldata.h"
#include "ms2/placeholder/asslot.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>
#include <vector>

MS2_EMIT_CRT_MEMMOVE_S();

// ---- statics of the market's shared headers (init order: the two sort name tables, skill / stun / the condition map, the
// key controller, then the attribute names and the buy sound) ----

static CString s_strSortTypeNamesBuy[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal", "EnumEnd"};
#include "ms2/placeholder/header_statics_a.h"
static UICommon::CMyPCKeyInputController s_keyInputController;
static CString s_strJobCode = "jobCode";
static CString s_strSortValue = "sortValue";
static CString s_strTabIndex = "tabIndex";
static CString s_sndCashBuy = "cash_Buy";

// ---- unit-local views of exe objects ----

// The list control of the movie (the AS list with clear / append).
class Unk_VgList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                       // clear
    void FUN_1422dd230(const ASObj& row);                       // append a row
    void FUN_1422cf4f0(int n);
};
template <> MS2Ptr<Unk_VgList> UISwfEntity::GetChild<Unk_VgList>(const CString&);    // 0x140ba4b70

// The message box with its sound slot (the record is a CMsgBoxData).
class Unk_VgMsgBox : public CMsgBoxData { public: void FUN_141a01c30(const CString&); };

// The VIP effect of the first benefit: a 16-byte skill reference released by 0x1401836a0.
void FUN_1401836a0(Unk_VipEffectRef*);
struct Unk_VgEffectHold
{
    Unk_VipEffectRef m_ref;
    Unk_VgEffectHold(const Unk_VipEffectRef& r) : m_ref(r) {}
    ~Unk_VgEffectHold() { FUN_1401836a0(&m_ref); }
    bool IsNull() const { return m_ref.m_p == 0; }
    void* get() const { return m_ref.m_p; }
};

// The server config constants (the buy limit window in days).
struct Unk_VgConstUInt;
unsigned* FUN_1401d7c10(Unk_VgConstUInt* p);
unsigned char* FUN_1401d3200();

CVIPTable* FUN_140fb9980();                                     // CVIPTable::GetInstance
void* FUN_1403ed2d0();                                          // the world
PCBase* FUN_141bd0cc0(void* pWorld);                            // the local player
int FUN_141662de0(PCBase* pPC);                                 // the player has VIP
__int64 FUN_141662e90(PCBase* pPC);                             // the VIP end time
__int64 FUN_140869440();                                        // the server time

class Unk_VgStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_VgStrings* FUN_1401a9d70();
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_14028de60(int nId);
CStringW FUN_140938ae0(CStringW strKey, const unsigned& nValue);
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& strA, const CStringW& strB);
CStringW FUN_140632a60(int nId, const CStringW& strA, const CStringW& strB);
CStringW FUN_1409e8ca0(CStringW strKey, const int& a1, const int& a2, const int& a3, const int& a4, const int& a5);
CStringW FUN_140ed0b00(CStringW strKey, const unsigned& nValue, const CStringW& strTime);
CStringW FUN_1418fec00(int nPayType, __int64 nAmount, int n);
CString FUN_140513200(const char* szFormat, const unsigned& n);
bool FUN_140841300(const CStringW& str, const char* sz);        // the string equals sz
void FUN_140d73aa0(CStringW strText, int a, void* b, CStringW strTag);                          // message box
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, IMessageListener* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);                  // show

void FUN_141415450(const CString& strBindId, MS2Ptr<CItem> spItem, int a, int b, int c);   // bind the item to the id
void FUN_141415600(const CString& strBindId);                                              // release the bind
int FUN_1405276c0(CItem* pItem);                                // the item id
int FUN_1409e13a0(ASTooltip* pTip, CItem* pCompare, CItem* pItem);   // item tooltip (the member in astooltip.h is declared void)
void FUN_1409d6a40(ASTooltip* pTip, int nItemId, __int64 nPeriod);    // the period line of the tooltip
void FUN_1407cd930(Scaleform::GFx::Value* pObject, const char* szName, const Scaleform::GFx::Value& v);   // set a member
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);    // pRetVal = v

class Unk_VgUiMgr { public: void FUN_141adc530(int uiId); };
Unk_VgUiMgr* FUN_1403ed2b0();
UIMarketBillDialog* FUN_140b09580(int uiId);                    // the open dialog of a UI id
bool FUN_140ebc590(const TMarketBillDataParam::PaymentMap& mapPay);    // the payment map is the VIP price

// The goods rows are shown by the sale display order (a stateless functor; 0x140fbf980).
struct Unk_VgGoodsOrder
{
    bool operator()(const MS2Ptr<CVIPGoods>& a, const MS2Ptr<CVIPGoods>& b) const
    {
        // MS2-FUNCTIONAL: exe evaluates b->() before a->() and branches ja; same compare result
        return (unsigned)b->m_nDisplayOrder <= (unsigned)a->m_nDisplayOrder;
    }
};

// @0x140fb9ac0
UIVIPGoodsShopDialog::UIVIPGoodsShopDialog()
    : m_mapBought(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_nGoodsCount = 0;
    m_bReady = 0;
    FUN_141924170(1);
    m_timer.FUN_140268840();
}

// @0x140fb9bc0
UIVIPGoodsShopDialog::~UIVIPGoodsShopDialog()
{
}

// @0x140fb9c30
CString UIVIPGoodsShopDialog::vfunc_1()
{
    return CString("VIPGoodsShopDialog");
}

// @0x140fb9c80
int UIVIPGoodsShopDialog::vfunc_65()
{
    return UIDialog::vfunc_65() != 0;
}

// @0x140fb9cb0
void UIVIPGoodsShopDialog::vfunc_67()
{
    for (size_t i = 0; i < m_bindIds.GetCount(); i++)
        FUN_141415600(m_bindIds[i]);
    m_bindIds.RemoveAll();
    m_bReady = 0;
    UIDialog::vfunc_67();
}

// @0x140fb9d50
void UIVIPGoodsShopDialog::vfunc_72()
{
    if (vfunc_55() != 1 && m_bReady != 0 && m_timer.FUN_140268870(1000) != 0) {
        std::vector<MS2Ptr<CVIPGoods> > goods;
        FUN_140fbb940(goods);
        if (m_nGoodsCount != goods.size())
            FUN_140fbaca0();
    }
}

// @0x140fb9e10
void UIVIPGoodsShopDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer != 0) {
        COutPacket packet(0x8e, 0);
        packet.Encode1(3);
        FUN_140710590(packet);
    }
}

// @0x140fb9e90
int UIVIPGoodsShopDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onClickBuyGoods") != 0)
        return 0;
    ASData data;
    if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        FUN_140fbbae0(data.FUN_1422b8b10());
    return 1;
}

// @0x140fb9f70
void UIVIPGoodsShopDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    UIObject::vfunc_49(pRetVal, pArgs);
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    CStringW strType = pArgs->FUN_1422b8f40();
    if (FUN_140841300(strType, "bonusItem")) {
        unsigned nGoodsId = pArgs->FUN_1422b8b10();
        unsigned nIndex = pArgs->FUN_1422b8b10() - 1;
        MS2Ptr<CVIPGoods> spGoods = FUN_140fb9980()->GetGoods(nGoodsId);
        if (spGoods == 0)
            return;
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b130(spGoods->m_bonusItemIds[nIndex], spGoods->m_bonusItemRanks[nIndex], 0) != 0) {
            spItem->FUN_140526c70(spGoods->m_bonusItemCounts[nIndex]);
            MS2Ptr<CItem> spWorn = static_cast<MyPC*>(pPlayer)->FUN_14152e2f0(spItem);
            ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 4, 2);
            if (FUN_1409e13a0(&tip, spWorn.get(), spItem.get()) != 0) {
                if (spGoods->m_bonusItemPeriods[nIndex] > 0)
                    FUN_1409d6a40(&tip, FUN_1405276c0(spItem.get()), spGoods->m_bonusItemPeriods[nIndex]);
                FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
            }
        }
    }
    else if (FUN_140841300(strType, "effectIcon")) {
        Unk_VgEffectHold effect(FUN_140fb9980()->GetFirstEffect());
        if (effect.IsNull())
            return;
        ASTooltip tip(*pRetVal, 2);
        tip.FUN_1409e2750(effect.get(), 3, 0);
    }
    else if (FUN_140841300(strType, "buyLimit")) {
        unsigned nGoodsId = pArgs->FUN_1422b8b10();
        MS2Ptr<CVIPGoods> spGoods = FUN_140fb9980()->GetGoods(nGoodsId);
        if (spGoods == 0)
            return;
        if (spGoods->HasBuyLimit() == 0)
            return;
        unsigned nCount = 0;
        m_mapBought.Lookup(nGoodsId, nCount);
        if (nCount != 0)
            return;
        CStringW strText;
        int nResetType = spGoods->m_nBuyLimitResetType;
        if (nResetType == 0)
            return;
        if (nResetType == 1)
            strText = FUN_14028b8e0(CStringW(L"s_vip_dialog_goods_sales_tooltip_day_limit"));
        else if (nResetType == 2)
            strText = FUN_14028b8e0(CStringW(L"s_vip_dialog_goods_sales_tooltip_week_limit"));
        else if (nResetType == 3)
            strText = FUN_14028b8e0(CStringW(L"s_vip_dialog_goods_sales_tooltip_month_limit"));
        ASTooltip tip(1, 2);
        if (tip.FUN_1409e26b0(strText) != 0) {
            tip.FUN_1409c6dc0(5);
            FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
        }
    }
}

// @0x140fba7a0
void UIVIPGoodsShopDialog::vfunc_79(void* pPacket)
{
#define VIPGOODS_PKT static_cast<CInPacket*>(pPacket)
    UIDialog::vfunc_79(pPacket);
    if (VIPGOODS_PKT->FUN_14070fe80() != 0xeb)
        return;
    unsigned char nMode = VIPGOODS_PKT->vfunc_o8_1();
    if (nMode == 3) {
        m_mapBought.RemoveAll();
        unsigned nCount = VIPGOODS_PKT->vfunc_o8_3();
        for (unsigned i = 0; i < nCount; i++) {
            unsigned nGoodsId = VIPGOODS_PKT->vfunc_o8_3();
            unsigned nBought = VIPGOODS_PKT->vfunc_o8_3();
            m_mapBought.SetAt(nGoodsId, nBought);
        }
        FUN_140fbaca0();
        m_bReady = 1;
    }
    else if (nMode == 4) {
        int nGoodsId = VIPGOODS_PKT->vfunc_o8_3();
        MS2Ptr<CVIPGoods> spGoods = FUN_140fb9980()->GetGoods(nGoodsId);
        if (spGoods == 0)
            return;
        CStringW strMsg = FUN_140656190(FUN_14028de60(0x9f6), FUN_1401a9d70()->FUN_141811980(0x2e, nGoodsId), spGoods->GetPriceText(0));
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x10, FUN_140632a60(0x9f4, FUN_14028de60(0x9f8), strMsg), 0, CStringW(L""));
        if (spBox.get() != 0) {
            spBox->SetTitle(FUN_14028de60(0x9f5));
            static_cast<Unk_VgMsgBox*>(spBox.operator->())->FUN_141a01c30(s_sndCashBuy);
            spBox->FUN_141a02770(0x1e0, 300);
            FUN_140d73c60(spBox);
        }
    }
#undef VIPGOODS_PKT
}

// @0x140fbaca0
void UIVIPGoodsShopDialog::FUN_140fbaca0()
{
    if (!m_30)
        return;
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    MS2Ptr<Unk_VgList> spList = GetChild<Unk_VgList>(CString("m_goodsList"));
    if (spList == 0)
        return;
    spList->Invoke("resetRenderer");
    spList->FUN_1422dd1d0();
    spList->FUN_1422cf4f0(0);
    std::vector<MS2Ptr<CVIPGoods> > goods;
    FUN_140fbb940(goods);
    std::sort(goods.begin(), goods.end(), Unk_VgGoodsOrder());
    m_nGoodsCount = goods.size();
    for (unsigned i = 0; i < goods.size(); i++) {
        MS2Ptr<CVIPGoods> spGoods = goods[i];
        if (spGoods == 0)
            continue;
        int nDisableType = 0;
        if (spGoods->HasSalesPeriod() != 0) {
            CMsTime now(FUN_140869440());
            if (spGoods->m_salesStartDate > now)
                nDisableType = 1;
        }
        unsigned nLimit = 0;
        if (spGoods->HasBuyLimit() != 0)
            m_mapBought.Lookup(spGoods->m_nId, nLimit);
        ASObj row(2);
        row.FUN_1409c0d20("id", spGoods->m_nId);
        row.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141811980(0x2e, spGoods->m_nId));
        row.FUN_1407cb9c0("disableType", nDisableType);
        row.FUN_1409c1180("originalPrice", spGoods->m_nSalePrice == spGoods->m_nPrice ? 0 : spGoods->m_nPrice);
        row.FUN_1407cbb20("salePriceText", spGoods->GetPriceText(1));
        row.FUN_1409c1180("salePrice", spGoods->m_nSalePrice);
        row.FUN_140fbd930("saleTag", spGoods->m_nSaleTag);
        if (spGoods->HasSalesPeriod() != 0)
            row.FUN_1407cbb20("salesDuration", spGoods->GetSalesPeriodText());
        if (spGoods->HasBuyLimit() != 0 && nLimit != 0) {
            CStringW strLimit;
            int nResetType = spGoods->m_nBuyLimitResetType;
            if (nResetType == 0)
                strLimit = FUN_140938ae0(CStringW(L"s_vip_dialog_goods_sales_limit"), nLimit);
            else if (nResetType == 1)
                strLimit = FUN_140938ae0(CStringW(L"s_vip_dialog_goods_sales_day_limit"), nLimit);
            else if (nResetType == 2)
                strLimit = FUN_140938ae0(CStringW(L"s_vip_dialog_goods_sales_week_limit"), nLimit);
            else if (nResetType == 3)
                strLimit = FUN_140938ae0(CStringW(L"s_vip_dialog_goods_sales_month_limit"), nLimit);
            row.FUN_1407cbb20("buyLimit", strLimit);
        }
        for (unsigned j = 0; j < spGoods->m_bonusItemIds.GetCount(); j++) {
            CString strBindId;
            MS2Ptr<CItem> spItem(new CItem());
            if (spItem->FUN_14052b130(spGoods->m_bonusItemIds[j], spGoods->m_bonusItemRanks[j], 0) != 0) {
                spItem->FUN_140526c70(spGoods->m_bonusItemCounts[j]);
                strBindId.Format("%s_%d", (LPCSTR)vfunc_1(), (int)m_bindIds.GetCount() + 1);
                FUN_141415450(strBindId, spItem, 0, 0x415, 0);
                m_bindIds.Add(strBindId);
                unsigned nNumber = j + 1;
                CString strKey = FUN_140513200("bonusItemBindID{0}", nNumber);
                row.FUN_1407cba60(strKey, strBindId);
                nNumber = j + 1;
                strKey = FUN_140513200("bonusItemName{0}", nNumber);
                row.FUN_1407cbb20(strKey, spItem->FUN_140527b10());   // CItem member: this=rcx, hidden return=rdx
            }
        }
        spList->FUN_1422dd230(row);
    }
    spList->vfunc_24(true);
    m_30->Invoke("initCurPage");
}

// @0x140fbb940
void UIVIPGoodsShopDialog::FUN_140fbb940(std::vector<MS2Ptr<CVIPGoods> >& rOut)
{
    ATL::CAtlArray<MS2Ptr<CVIPGoods> > list;
    FUN_140fb9980()->GetGoodsList(list);
    for (unsigned i = 0; i < list.GetCount(); i++) {
        MS2Ptr<CVIPGoods> spGoods = list[i];
        if (spGoods == 0)
            continue;
        if (spGoods->HasSalesPeriod() != 0) {
            CMsTime now(FUN_140869440());
            if (spGoods->m_salesEndDate < now)
                continue;
        }
        if (spGoods->HasBuyLimit() != 0) {
            unsigned nLimit = 0;
            m_mapBought.Lookup(spGoods->m_nId, nLimit);
            if (nLimit == 0)
                continue;
        }
        rOut.push_back(spGoods);
    }
}

// @0x140fbbae0
void UIVIPGoodsShopDialog::FUN_140fbbae0(int nGoodsId)
{
    MS2Ptr<CVIPGoods> spGoods = FUN_140fb9980()->GetGoods(nGoodsId);
    if (spGoods == 0)
        return;
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    if (FUN_141662de0(pPlayer) != 0) {
        unsigned nDays = *FUN_1401d7c10((Unk_VgConstUInt*)(FUN_1401d3200() + 0x6f40));
        __int64 nWindow = (unsigned)((int)*FUN_1401d7c10((Unk_VgConstUInt*)(FUN_1401d3200() + 0x6f40)) * 0x15180);
        __int64 nEnd = FUN_141662e90(pPlayer);
        if (nWindow < nEnd - FUN_140869440()) {
            CMsTime until(nEnd - nWindow);
            int nMinute = until.GetMinute();
            int nHour = until.GetHour();
            int nDay = until.GetDay();
            int nMonth = until.GetMonth();
            int nYear = until.GetYear();
            CStringW strTime = FUN_1409e8ca0(CStringW(L"s_vip_dialog_goods_buy_limit_time_string"), nYear, nMonth, nDay, nHour, nMinute);
            FUN_140d73aa0(FUN_140ed0b00(CStringW(L"s_vip_dialog_goods_buy_limit"), nDays, strTime), 0, 0, CStringW(L""));
            return;
        }
    }
    FUN_140fbbe40(spGoods);
}

// @0x140fbbe00
int UIVIPGoodsShopDialog::FUN_140fbbe00(int nPriceType)
{
    if (nPriceType == 0)
        return 3;
    if (nPriceType == 1)
        return 9;
    return 3;
}

// @0x140fbbe40
void UIVIPGoodsShopDialog::FUN_140fbbe40(MS2Ptr<CVIPGoods> spGoods)
{
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return;
    if (spGoods == 0)
        return;
    MS2Ptr<TVIPGoodsBillDataParam> spParam(new TVIPGoodsBillDataParam());
    if (spParam == 0)
        return;
    int nPayType = FUN_140fbbe00(spGoods->m_nPriceType);
    spParam->m_nDialogId = vfunc_48();
    spParam->m_strMovie = vfunc_1();
    spParam->m_nCurrency = nPayType;
    spParam->m_nType = 3;
    spParam->m_nGoodsId = spGoods->m_nId;
    spParam->m_dgBuy = TMarketBillDataParam::BuyCallback(this, &UIVIPGoodsShopDialog::SendPremiumClubMode4);
    spParam->m_dgTooltip = TMarketBillDataParam::TooltipCallback(this, &UIVIPGoodsShopDialog::FUN_140fbce80);
    ATL::CAtlArray<MS2Ptr<ASBillData> >& bills = spParam->m_bills;
    Unk_VgEffectHold effect(FUN_140fb9980()->GetFirstEffect());
    if (effect.IsNull())
        return;
    MS2Ptr<ASSlot> spSlot(new ASSlot(2));
    if (spSlot.get()->FUN_1409c4860((Unk_SlotIconSource*)effect.get()) == 0)
        return;
    MS2Ptr<ASBillData> spBill(new ASBillData(2));
    spBill->FUN_1409ab940(spSlot->FUN_1422bb870());
    spBill->FUN_1409aba80(FUN_1401a9d70()->FUN_141811980(0x2e, spGoods->m_nId));
    spBill->FUN_1409abad0(FUN_1418fec00(nPayType, spGoods->m_nSalePrice, 0), spGoods->m_nSalePrice);
    spBill->FUN_1409abc90(0);
    spBill->FUN_1409abcd0(nPayType);
    bills.Add(spBill);
    for (unsigned i = 0; i < spGoods->m_bonusItemIds.GetCount(); i++) {
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b130(spGoods->m_bonusItemIds[i], spGoods->m_bonusItemRanks[i], 0) == 0)
            return;
        spItem->FUN_140526c70(spGoods->m_bonusItemCounts[i]);
        MS2Ptr<ASSlot> spItemSlot(new ASSlot(2));
        if (spItemSlot.get()->FUN_1409c3860(spItem.get(), pPlayer, 0x415) == 0)
            return;
        spItemSlot->FUN_1409c2190(spGoods->m_bonusItemCounts[i]);
        MS2Ptr<ASBillData> spItemBill(new ASBillData(2));
        spItemBill->FUN_1409ab940(spItemSlot->FUN_1422bb870());
        spItemBill->FUN_1409aba80(FUN_1401a9d70()->FUN_141811980(1, FUN_1405276c0(spItem.get())));
        spItemBill->FUN_1409abc90(0);
        spItemBill->FUN_1409abad0(CStringW(), 0);
        spItemBill->FUN_1409abcd0(nPayType);
        spItemBill->FUN_1409abd20(1);
        CStringW strExtra;
        if (spGoods->m_bonusItemPeriods[i] < 1)
            strExtra = FUN_140938ae0(CStringW(L"s_common_count"), spGoods->m_bonusItemCounts[i]);
        else
            strExtra = FormatTimeSpan(ATL::CTimeSpan(spGoods->m_bonusItemPeriods[i] * 60), true, true, false, false);
        spItemBill->FUN_1409abbf0(strExtra);
        bills.Add(spItemBill);
    }
    UIMarketBillDialog* pBillDialog = FUN_140b09580(0x4f17);
    if (pBillDialog == 0)
        return;
    MS2Ptr<TMarketBillDataParam> spBase(spParam);
    pBillDialog->FUN_140ea7770(spBase);
    FUN_1403ed2b0()->FUN_141adc530(0x4f17);
}

// @0x140fbcca0
bool UIVIPGoodsShopDialog::SendPremiumClubMode4(MS2Ptr<TMarketBillDataParam> spParam, const PaymentMap& mapPay)
{
    if (spParam == 0)
        return false;
    MS2Ptr<TVIPGoodsBillDataParam> spVip(dynamic_cast<TVIPGoodsBillDataParam*>(spParam.get()));
    if (spVip == 0)
        return false;
    if (spParam->m_bills.GetCount() == 0)
        return false;
    if (FUN_140ebc590(mapPay) == 0)
        return false;
    COutPacket packet(0x8e, 0);
    packet.Encode1(4);
    packet.Encode4(spVip->m_nGoodsId);
    FUN_140710590(packet);
    return true;
}

// @0x140fbce80
bool UIVIPGoodsShopDialog::FUN_140fbce80(Scaleform::GFx::Value* pRetVal, ASData& rData, MS2Ptr<TMarketBillDataParam> spParam)
{
    PCBase* pPlayer = FUN_141bd0cc0(FUN_1403ed2d0());
    if (pPlayer == 0)
        return false;
    if (m_30 == 0)
        return false;
    if (spParam == 0)
        return false;
    MS2Ptr<TVIPGoodsBillDataParam> spVip(dynamic_cast<TVIPGoodsBillDataParam*>(spParam.get()));
    if (spVip == 0)
        return false;
    unsigned nGoodsId = spVip->m_nGoodsId;
    MS2Ptr<CVIPGoods> spGoods = FUN_140fb9980()->GetGoods(nGoodsId);
    if (spGoods == 0)
        return false;
    ASObj obj(rData.FUN_1422b9260(), 2);
    if (obj.FUN_1422ba9a0())
        return false;
    int nIndex = rData.FUN_1422b8b10();
    if (nIndex == 0) {
        Unk_VgEffectHold effect(FUN_140fb9980()->GetFirstEffect());
        if (effect.IsNull())
            return false;
        ASTooltip tip(*pRetVal, 2);
        tip.FUN_1409e2750(effect.get(), 3, 0);
    }
    else {
        unsigned nItem = nIndex - 1;
        if (nItem >= spGoods->m_bonusItemIds.GetCount())
            return false;
        MS2Ptr<CItem> spItem(new CItem());
        if (spItem->FUN_14052b130(spGoods->m_bonusItemIds[nItem], spGoods->m_bonusItemRanks[nItem], 0) == 0)
            return false;
        spItem->FUN_140526c70(spGoods->m_bonusItemCounts[nItem]);
        MS2Ptr<CItem> spWorn = static_cast<MyPC*>(pPlayer)->FUN_14152e2f0(spItem);
        ASTooltip tip(FUN_141bd0cc0(FUN_1403ed2d0()), 4, 2);
        if (FUN_1409e13a0(&tip, spWorn.get(), spItem.get()) != 0) {
            if (spGoods->m_bonusItemPeriods[nItem] > 0)
                FUN_1409d6a40(&tip, FUN_1405276c0(spItem.get()), spGoods->m_bonusItemPeriods[nItem]);
            FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
        }
    }
    return true;
}

// @0x140fbd930
void ASObj::FUN_140fbd930(const char* szName, int n)
{
    ASData data;
    data.FUN_1422b7f70(n);
    FUN_1407cd930(&m_value, szName, data.FUN_1422b9260());
}

// @0x140fbf740
TVIPGoodsBillDataParam::TVIPGoodsBillDataParam()
{
    m_nGoodsId = 0;
}

// @0x140fbf860
TVIPGoodsBillDataParam::~TVIPGoodsBillDataParam()
{
}

// @0x140fbfaf0
int UIVIPGoodsShopDialog::vfunc_48()
{
    return 0x4f1d;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caaa00-0x142caab60 .text$yd
