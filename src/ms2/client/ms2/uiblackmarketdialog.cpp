// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIBlackMarketDialog: see uiblackmarketdialog.h.
// MS2-UNIT: ?\uiblackmarketdialog.cpp
// MS2-RANGE: 0x140110a70-0x140110b20 .text$di
// MS2-RANGE: 0x1418cf080-0x1418d3050 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VBlackMarketPageItemRegister@@@@QEAA@PEAVBlackMarketPageItemRegister@@@Z 0x1418d1e00 ; prop
// MS2-PIN: ??0?$MS2Ptr@VBlackMarketPageItemSearch@@@@QEAA@PEAVBlackMarketPageItemSearch@@@Z 0x1418d1e30 ; prop
// MS2-PIN: ??0?$MS2Ptr@VBlackMarketPageMesoRegister@@@@QEAA@PEAVBlackMarketPageMesoRegister@@@Z 0x1418d1e60 ; prop
// MS2-PIN: ??8?$MS2Ptr@VBlackMarketPageItemRegister@@@@QEBA_NPEAVBlackMarketPageItemRegister@@@Z 0x1418d2080 ; unique
// MS2-PIN: ??8?$MS2Ptr@VBlackMarketPageItemSearch@@@@QEBA_NPEAVBlackMarketPageItemSearch@@@Z 0x1418d20c0 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VBlackMarketPageItemRegister@@@@QEBAPEAVBlackMarketPageItemRegister@@XZ 0x1418d2130 ; unique
// MS2-PIN: ??C?$MS2Ptr@VAScript@@@@QEBAPEAVAScript@@XZ 0x1418d2140 ; probe
// MS2-PIN: ?get@?$MS2Ptr@VBlackMarketPageMesoRegister@@@@QEBAPEAVBlackMarketPageMesoRegister@@XZ 0x1418d2160 ; unique
// MS2-PIN: ??C?$MS2Ptr@VBlackMarketPageItemSearch@@@@QEBAPEAVBlackMarketPageItemSearch@@XZ 0x1418d2180 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIBlackMarketDialog@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x1418d2d00 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiblackmarketdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiblackmarketdialog.h"
#include "ms2/commonfiles/blackmarketitemoption.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/unnamed/unit_1406125d0.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"

static CString s_strStun = "stun";
static Unk_1402a9d70 s_cond(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyController;

typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> ParamsDelegate;

// ---- out-of-unit callees (names describe uses) ----
class Unk_140acd6e0 : public ASDisplayObject
{
public:
    void FUN_1422ce240(const ParamsDelegate& cb, void* pUser);
};
CBlackMarketTable* FUN_1401c0d80();
class Unk_NetSend1 { public: void FUN_140a20940(); };
class Unk_NetSend2 { public: void FUN_140d6e400(); };
Unk_NetSend1* FUN_140f17d40();
Unk_NetSend2* FUN_140f17d50();
void FUN_141b1feb0(void* p);
void* FUN_140967100();
class Unk_BanFlags { public: int FUN_1402c4c90(int n); };
class Unk_14025e7b0 { public: char m_pad[8]; Unk_BanFlags m_8; };
Unk_14025e7b0* FUN_14025e7b0();
class Unk_LocalPlayer { public: int FUN_14166ce30(); };
class Unk_WorldSvc { public: Unk_LocalPlayer* FUN_141bd0cc0(); };
Unk_WorldSvc* FUN_1403ed2d0();
CStringW FUN_14028b8e0(const CStringW& str);
void FUN_1412751f0(const CStringW& str, int a, int b);
void FUN_141275260(int nId, int a, int b);
bool FUN_140ba28d0(const MS2Ptr<AScript>* p, int n);
class Unk_Features { public: bool FUN_14036d570(int n); };
Unk_Features* FUN_140166410();
void FUN_140cff840(const Scaleform::GFx::Value& root, const char* szName, int nVisible);
class Unk_MesoCfg { public: int FUN_140f20b90(); };
class Unk_Cfg6198 { public: CString FUN_1409f6f30(); };
class Unk_Cfg { public: char m_pad[0x6078]; Unk_MesoCfg m_6078; char m_pad2[0x6198 - 0x6078 - 1]; Unk_Cfg6198 m_6198; };
Unk_Cfg* FUN_1401d3200();
void FUN_1418fe1c0(const CString& str);
class Unk_GmKeys { public: bool FUN_14116d9c0(int nKey, int a, int b); };
Unk_GmKeys* FUN_14025e7c0();
class Unk_SwfMgr { public: UISwfEntity* FUN_1422d4980(int nLayer); };
Unk_SwfMgr* FUN_140b632f0();
__int64 FUN_141b71960(const char* sz);
unsigned __int64 FUN_140718350(const CString& str);
void FUN_1409b4bc0(Scaleform::GFx::Value* pOut, Scaleform::GFx::Value& v);
bool FUN_140184310(const CString& str, const char* sz);
class Unk_Hotbar { public: int FUN_140d40670(); };
Unk_Hotbar* FUN_1409bb9e0();
int FUN_140d40670(Unk_Hotbar* p);
void FUN_140d40120(Unk_Hotbar* p, MS2Ptr<CItem> spItem, int n);
void FUN_140d2cfc0(MS2Ptr<CItem> spItem);
void FUN_140d2cf00(unsigned __int64 nUid, MS2Ptr<CItem> spItem);
void FUN_1413490b0(MS2Ptr<CItem> spItem, Scaleform::GFx::Value* pOut, bool b, unsigned n1, unsigned n2);
void FUN_141349ae0(MS2Ptr<CItem> spItem, int n, const CString& str);
int FUN_1405276c0(CItem* p);
int FUN_140526bd0(CItem* p);
bool FUN_140a467d0(const MS2Ptr<AScript>* p);
Scaleform::GFx::Value& FUN_1422dbc00();

// @0x1418cf080
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
UIBlackMarketDialog::UIBlackMarketDialog()
{
    m_spItemSearch = new BlackMarketPageItemSearch();
    m_spItemRegister = new BlackMarketPageItemRegister();
    m_spMesoSearch = new BlackMarketPageMesoSearch(CString("m_mesoSearchPage"));
    m_spMesoRegister = new BlackMarketPageMesoRegister();
    m_spMesoSearchSingle = new BlackMarketPageMesoSearch(CString("m_mesoSearchPageSingleRange"));
    m_pages.clear();
    m_pages.push_back(m_spItemSearch.get());
    m_pages.push_back(m_spItemRegister.get());
    m_pages.push_back(m_spMesoSearch.get());
    m_pages.push_back(m_spMesoRegister.get());
    m_pages.push_back(m_spMesoSearchSingle.get());
    FUN_141924170(1);
    FUN_1422dc3b0(1);
    m_164 = 1;
    m_pCurPage = 0;
}

// @0x1418cf500
UIBlackMarketDialog::~UIBlackMarketDialog()
{
}

// @0x1418cf5d0
CString UIBlackMarketDialog::vfunc_1()
{
    return "BlackMarketDialog";
}

// @0x1418cf620
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
int UIBlackMarketDialog::vfunc_65()
{
    FUN_1401c0d80()->Load();
    int nOpened = UIDialog::vfunc_65();
    if (nOpened != 0)
    {
        FUN_140f17d40()->FUN_140a20940();
        FUN_140f17d50()->FUN_140d6e400();
    }
    return nOpened != 0;
}

// @0x1418cf680
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_pCurPage = 0;
    for (size_t i = 0; i < m_pages.size(); i++)
    {
        if (m_pages[i])
            m_pages[i]->vfunc_2();
    }
    if (m_spDetailButton.get())
        m_spDetailButton = 0;
    FUN_141b1feb0(FUN_140967100());
    vfunc_47(1);
}

// @0x1418cf770
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
int UIBlackMarketDialog::vfunc_73()
{
    if (FUN_14025e7b0()->m_8.FUN_1402c4c90(7) == 0)
    {
        Unk_LocalPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPlayer && pPlayer->FUN_14166ce30() != 0)
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_blackmarket_error_not_useable_by_dead")), 1, 1);
            return 0;
        }
        return UIDialog::vfunc_73();
    }
    FUN_141275260(0x2f7, 1, 1);
    return 0;
}

// @0x1418cf860
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::vfunc_72()
{
    UIDialog::vfunc_72();
    Unk_LocalPlayer* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer && pPlayer->FUN_14166ce30() != 0 && m_68 == 0)
    {
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_blackmarket_error_not_useable_by_dead")), 1, 1);
        vfunc_67();
    }
}

// @0x1418cf920
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::vfunc_79(void* p)
{
    UIDialog::vfunc_79(p);
    CInPacket* pIn = static_cast<CInPacket*>(p);
    if (pIn->FUN_14070fe80() == 0x98)
    {
        char c = pIn->vfunc_o8_1();
        if (c == 0)
            c = pIn->vfunc_o8_1();
        if (m_spItemRegister.get())
            m_spItemRegister->FUN_140f133b0(c);
        if (m_spItemSearch.get())
            m_spItemSearch->FUN_140f0dfe0(c);
    }
}

// @0x1418cfa40
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
int UIBlackMarketDialog::vfunc_74(int nMsg, void* p2, void* p3)
{
    if ((nMsg == 0x10f || nMsg == 0x102) && !FUN_140ba28d0(&m_30, 0) && m_spItemSearch.get() && FUN_1418d0da0(m_spItemSearch.get()))
        m_spItemSearch->FUN_140f0d630(nMsg, p2, p3);
    return 0;
}

// @0x1418cfb10
void UIBlackMarketDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    vfunc_47(0);
}

// @0x1418cfb50
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (FUN_140ba28d0(&m_30, 0))
        return;
    if (!FUN_140166410()->FUN_14036d570(0x15))
        FUN_140cff840(m_30->FUN_1422bb890(), "m_radioMeso", 0);
    if (FUN_140166410()->FUN_14036d570(0xf4))
    {
        m_30->Invoke("SetIsSingleRangeMesoMarketProductUnit", FUN_1401d3200()->m_6078.FUN_140f20b90() == 1);
        m_30->FUN_140bbe640<Unk_140acd6e0>("m_mesoMarketDetailButton", m_spDetailButton);
        if (m_spDetailButton.get())
            m_spDetailButton->FUN_1422ce240(ParamsDelegate(this, &UIBlackMarketDialog::FUN_1418d1430), 0);
    }
    for (size_t i = 0; i < m_pages.size(); i++)
    {
        BlackMarketPage* pPage = m_pages[i];
        pPage->FUN_140f0c150(m_30);
        pPage->FUN_140f0c1a0(m_28);
        pPage->vfunc_1();
    }
    m_30->Invoke("initData");
}

// @0x1418cfee0
int UIBlackMarketDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnChangeTab", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1418d0c20(data.FUN_1422b8a10());
        return 1;
    }
    if (m_pCurPage)
        m_pCurPage->vfunc_4(szMethod, pArgs, nArgs);
    return 0;
}

// @0x1418d0010
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (vfunc_55() == 0 && m_30.get() && m_pCurPage)
        m_pCurPage->vfunc_5();
}

// @0x1418d00a0
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
int UIBlackMarketDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (vfunc_55() == 0 && m_30.get() && FUN_140b632f0()->FUN_1422d4980(m_e0) == this)
    {
        CString strKey;
        if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
            strKey = "onEnterKey";
        else if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0))
            strKey = "onTabKey";
        if (!strKey.IsEmpty())
        {
            m_30->Invoke("onProcessKey", strKey);
            return 1;
        }
    }
    return 0;
}

// @0x1418d0270
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    if (m_pCurPage == 0)
        return;
    if (strMethod.CompareNoCase("getRegisterItemTooltip") == 0)
    {
        __int64 nUid = FUN_141b71960(pArgs->FUN_1422b8d30());
        ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), 0x80, 2);
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
        if (spItem.get())
        {
            if (tip.FUN_1409e0d40(spItem.get()))
            {
                tip.FUN_1409db7b0(spItem);
                FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
            }
        }
    }
    else if (strMethod.CompareNoCase("getEquipmentItemTooltip") == 0)
    {
        unsigned __int64 nUid = FUN_140718350(pArgs->FUN_1422b8d30());
        MS2Ptr<Unk_BlackMarketEntry> spEntry = m_pCurPage->vfunc_6(nUid);
        if (spEntry.get())
        {
            MS2Ptr<CItem> spItem = spEntry->m_item;
            bool bRegister = FUN_1418d0da0(m_spItemRegister.get());
            FUN_1413490b0(spItem, pRetVal, bRegister, 0x400, 0);
            ASTooltip tip(*pRetVal, 2);
            if (!tip.FUN_1422ba9a0())
                tip.FUN_1409db930(MS2Ptr<CItem>(0), spItem);
        }
    }
    else if (strMethod.CompareNoCase("OnRightClick") == 0)
    {
        if (FUN_140d40670(FUN_1409bb9e0()) == 0)
        {
            if (m_30.get())
                m_30->Invoke("clearRegisterPageSlot");
        }
        else
        {
            CString strArg = pArgs->FUN_1422b8d30();
            if (FUN_140184310(strArg, "ItemGUID"))
            {
                __int64 nUid = FUN_141b71960(pArgs->FUN_1422b8d30());
                MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
                FUN_140d40120(FUN_1409bb9e0(), spItem, 0);
            }
            else if (FUN_140184310(strArg, "MarketSN"))
            {
                unsigned __int64 nUid = FUN_140718350(pArgs->FUN_1422b8d30());
                MS2Ptr<Unk_BlackMarketEntry> spEntry = m_pCurPage->vfunc_6(nUid);
                if (spEntry.get())
                    FUN_140d40120(FUN_1409bb9e0(), spEntry->m_item, 0);
            }
        }
    }
    else if (strMethod.CompareNoCase("OnSlotShiftClick") == 0)
    {
        CString strArg = pArgs->FUN_1422b8d30();
        if (FUN_140184310(strArg, "ItemGUID"))
        {
            __int64 nUid = FUN_141b71960(pArgs->FUN_1422b8d30());
            MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nUid);
            if (spItem.get())
                FUN_140d2cfc0(spItem);
        }
        else if (FUN_140184310(strArg, "MarketSN"))
        {
            unsigned __int64 nUid = FUN_140718350(pArgs->FUN_1422b8d30());
            MS2Ptr<Unk_BlackMarketEntry> spEntry = m_pCurPage->vfunc_6(nUid);
            if (spEntry.get())
                FUN_140d2cf00(nUid, spEntry->m_item);
        }
    }
}

// @0x1418d0b60
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::FUN_1418d0b60(int nA, int nB, void* p)
{
    if (vfunc_55() == 0 && !(m_spItemSearch == 0))
        m_spItemSearch->FUN_140f0de60(nA, nB, p);
}

// @0x1418d0be0
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
bool UIBlackMarketDialog::FUN_1418d0be0()
{
    return m_pCurPage == m_spItemRegister.get();
}

// @0x1418d0c20
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::FUN_1418d0c20(int nIndex)
{
    if (nIndex < 0 || nIndex >= (int)m_pages.size())
        return;
    m_pCurPage = m_pages[nIndex];
    m_pCurPage->vfunc_3();
    if (FUN_140166410()->FUN_14036d570(0xf4))
    {
        if (m_pCurPage == m_spMesoRegister.get() || m_pCurPage == m_spMesoSearch.get() || m_pCurPage == m_spMesoSearchSingle.get())
            FUN_140cff840(FUN_1422dbc00(), "m_mesoMarketDetailButton", 1);
    }
}

// @0x1418d0da0
bool UIBlackMarketDialog::FUN_1418d0da0(BlackMarketPage* pPage)
{
    return m_pCurPage == pPage;
}

// @0x1418d0de0
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::FUN_1418d0de0(void* p)
{
    if (!(m_spItemRegister == 0))
        m_spItemRegister->FUN_140f132c0(*static_cast<CBlackMarketMan::ProductMap*>(p));
}

// @0x1418d0e40
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::FUN_1418d0e40(MS2Ptr<Unk_BlackMarketEntry> spEntry)
{
    if (vfunc_55() == 0 && !(m_spItemRegister == 0))
        m_spItemRegister->FUN_140f12d40(spEntry);
}

// @0x1418d0f00
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::FUN_1418d0f00(MS2Ptr<Unk_BlackMarketEntry> spEntry, int n)
{
    if (vfunc_55() == 0 && !(m_spItemRegister == 0))
        m_spItemRegister->FUN_140f13030(spEntry, n);
}

// @0x1418d0fc0
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::FUN_1418d0fc0(void* p2, void* p3)
{
    if (vfunc_55() == 0 && !FUN_140a467d0(&m_30) && !(m_spItemRegister == 0) && m_pCurPage == m_spItemRegister.get())
        m_spItemRegister->FUN_140f13420(static_cast<NotifyContext::BindData*>(p2), *static_cast<CItem*>(p3));
}

// @0x1418d1080
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::FUN_1418d1080(MS2Ptr<Unk_BlackMarketEntry> spEntry, int n)
{
    if (vfunc_55() != 0 || m_spItemSearch == 0)
        return;
    if (spEntry.get() && spEntry->m_item.get())
    {
        MS2Ptr<CItem> spNew = new CItem();
        spNew->FUN_14052b2e0(FUN_1405276c0(spEntry->m_item.get()), FUN_140526bd0(spEntry->m_item.get()), 0, n);
        FUN_141349ae0(spNew, 0x945, CString(""));
    }
    m_spItemSearch->FUN_140f0db00(spEntry, (int)spEntry->GetState(false));
}

// @0x1418d1330
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::FUN_1418d1330(int nA, int nB, void* p)
{
    if (!(m_spItemSearch == 0))
        m_spItemSearch->FUN_140f0d990(nA, nB, p);
}

// @0x1418d13a0
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::FUN_1418d13a0(int nA, int nB, void* p)
{
    if (!(m_spItemRegister == 0) && m_pCurPage == m_spItemRegister.get())
        m_spItemRegister->FUN_140f137a0(nA, nB, (unsigned __int64)p);
}

// @0x1418d1430
// MS2-FUNCTIONAL: not byte-exact yet (registers / call order differ)
void UIBlackMarketDialog::FUN_1418d1430(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_pCurPage == m_spMesoRegister.get() || m_pCurPage == m_spMesoSearch.get() || m_pCurPage == m_spMesoSearchSingle.get())
    {
        CString strUrl = FUN_1401d3200()->m_6198.FUN_1409f6f30();
        if (!strUrl.IsEmpty())
            FUN_1418fe1c0(strUrl);
    }
}

// Anchor for the UCRT header-inline memmove_s COMDAT used by the page vector's copy.
void Unk_BlackMarketAnchor(void* pDst, const void* pSrc)
{
    memmove_s(pDst, 8, pSrc, 8);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbce90-0x142cbcef0 .text$yd
