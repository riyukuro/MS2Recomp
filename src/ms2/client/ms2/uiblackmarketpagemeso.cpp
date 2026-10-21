// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The meso market pages of the black market window: the search
// page (BlackMarketPageMesoSearch, buy merat-for-meso listings) and the register page (BlackMarketPageMesoRegister, list
// own mesos for merat). Classes in uiblackmarketpage.h; method names are invented (FUN_<va> where the use is unclear).
// MS2-UNIT: client\ms2\uiblackmarketpagemeso.cpp
// MS2-RANGE: 0x1400de240-0x1400de300 .text$di
// MS2-RANGE: 0x140f18620-0x140f21590 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiblackmarketpagemeso.cpp"
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list / dropdown calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "uiblackmarketpage.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astilelist.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/cmesomarketman.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/notifychangedtokenmoney.h"
#include "ms2/placeholder/packethandlermanager.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/blockmanager.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// wcformat.h stops at 6 args (uimessenger.cpp adds its own WC_WRAP(7)); the price/fee notices need up to 10.
WC_WRAP(7)
WC_WRAP(8)
WC_WRAP(9)
WC_WRAP(10)

// ---- statics of the included headers (internal linkage, one copy per unit) ------------------------------------------

// The sort orders of the market lists (the same header table uiblackmarketpage.cpp has; name invented).
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};   // 0x143ac96b0

// ---- callees outside the unit ------------------------------------------------------------------------------------

extern __int64 DAT_143ab2898;                                       // the own mesos
extern char DAT_143ab2943;                                          // the own account state (7: verified)

unsigned __int64 FUN_140718350(const CString& str);                 // a decimal string as a 64-bit number
__int64 FUN_140718320(const CStringW& str);                         // _wtoi64
CStringW FUN_14083cf10(const CStringW& str);                        // a number text without its separators
CStringW FUN_14083cf50(int nCurrency, char bLocalized);             // the name of a currency
CStringW FUN_1409404f0(__int64 n);                                  // a money amount as text
CStringW FUN_1412757d0(__int64 n);                                  // a meso amount as text
CStringW FUN_140763e10(int nPrice);                                 // a price as text
CStringW FUN_140719630(int n);                                      // a number as text
CStringW FUN_140d6e230(int nCurrency);                              // the icon html of a currency
CStringW FUN_140298ea0(CStringW strKey);                            // string table text of a key
__int64 FUN_140930300();                                            // the own merat
__int64 FUN_140930490();                                            // the own meso market tokens
__int64 FUN_1401bcde0();                                            // the black market fee base
int FUN_1401bce00();                                                // the black market fee rate
int FUN_1401bcd30();                                                // default currency
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's text
void FUN_140cff1b0(const Scaleform::GFx::Value& root, CString strName, CStringW strText);   // set a text clip's html text
void FUN_140d01340(const Scaleform::GFx::Value& target, unsigned nParam, int nMovieId);  // a tooltip on the target
CBlockManager* FUN_140a6a830();                                     // the block manager
void FUN_1422bcd10(Scaleform::GFx::Value* pValue, unsigned int n);   // set a UInt
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);          // set a Boolean
void FUN_1422bcc70(Scaleform::GFx::Value* pValue, Scaleform::GFx::Value v);   // assign a value
int FUN_140bb9640(void* p);                                         // delegate user data -> int
void FUN_140a2ff20(const BlockPtr& spBlock, int nAction, int n);    // notice of a blocked action
void FUN_140d73bc0(int nStringId, int nA, int nB, CStringW strTitle);   // message box of a string id
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW strText);   // ask yes / no
MS2Ptr<CMsgBoxData> FUN_140d74390(CStringW strText, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);   // notice
MS2Ptr<CMsgBoxData> FUN_140d748b0(int nBit, const CStringW& strTitle, const CStringW& strText,
                                  Delegate<bool(int, const CMsgBoxData&)> cb);   // terms box (nBit: do not show again)
Delegate<bool(int, const CMsgBoxData&)> FUN_140b240b0();            // the do-nothing callback
void FUN_140d74e50(int nBit);                                       // the terms box was accepted
int FUN_140f1ffe0(const int& n, int nMin, int nMax);                // clamp (inline COMDAT below; uishadowexpeditionbossbar.cpp calls it)

// ---- BlackMarketPageMesoSearch -----------------------------------------------------------------------------------

// @0x140f18620
BlackMarketPageMesoSearch::BlackMarketPageMesoSearch(const CString& strName)
    : BlackMarketPage(strName), m_bSearched(false), m_nPage(0), m_nLastPage(0)
{
}

// @0x140f18720
void BlackMarketPageMesoSearch::vfunc_1()
{
    BlackMarketPage::vfunc_1();
    m_bSearched = false;
    m_30->FUN_140bbe7c0("m_searchBegin", m_spSearchBegin);
    m_30->FUN_140bbe7c0("m_searchEnd", m_spSearchEnd);
    m_30->FUN_140bbe640("m_searchButton", m_spSearchButton);
    if (m_30->FUN_140bbe640("m_prevPage", m_spPrevPage))
        m_spPrevPage->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageMesoSearch::FUN_140f19eb0), (void*)-1);
    if (m_30->FUN_140bbe640("m_nextPage", m_spNextPage))
        m_spNextPage->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageMesoSearch::FUN_140f19eb0), 1);
    if (m_spSearchBegin && m_spSearchEnd)
    {
        ASDataProvider list(2);
        unsigned int nCount = FUN_1401d3200()->MesoMarketProductUnit.FUN_140f20b90();
        for (unsigned int i = 0; i < nCount; i++)
        {
            __int64 nUnit = FUN_1401d3200()->MesoMarketProductUnit.FUN_140f20bb0(i);
            CStringW strLabel = FUN_14028dfa0(CStringW(L"s_mesoMarket_sellMesoText"), FUN_1412757d0(nUnit));
            ASObj row(2);
            row.FUN_1407cbb20("label", strLabel);
            row.FUN_1409c1180("meso", nUnit);
            list.FUN_1422bc050(row.FUN_1422bb890());
        }
        m_spSearchBegin->FUN_1422df720(list.FUN_1422bb870());
        m_spSearchBegin->FUN_1422df690(0);
        m_spSearchBegin->FUN_1422df9a0(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageMesoSearch::FUN_140f19b80), (ASDropdownMenu*)m_spSearchBegin);
        m_spSearchBegin->vfunc_24(true);
        m_spSearchEnd->FUN_1422df720(list.FUN_1422bb870());
        m_spSearchEnd->FUN_1422df690(list.FUN_1422bc5d0() - 1);
        m_spSearchEnd->FUN_1422df9a0(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageMesoSearch::FUN_140f19b80), (ASDropdownMenu*)m_spSearchEnd);
        m_spSearchEnd->vfunc_24(true);
    }
    if (m_spSearchButton)
        m_spSearchButton->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageMesoSearch::FUN_140f19d00), 0);
    PacketHandlerManager::GetInstance()->RegisterHandler(0x99, Delegate<void(CInPacket&)>(this, &BlackMarketPageMesoSearch::FUN_140f19ae0));
    UIStatusEventDispatcher::GetInstance()->FUN_141b0cd00(this);
    NotifySystem::GetInstance()->RegisterNotify(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &BlackMarketPageMesoSearch::vfunc_7));
}
MS2_REPLACE_METHOD(0x140F18720, BlackMarketPageMesoSearch, vfunc_1, 3063, 0x486679E1);

// @0x140f19320
void BlackMarketPageMesoSearch::vfunc_2()
{
    BlackMarketPage::vfunc_2();
    PacketHandlerManager::GetInstance()->UnregisterHandler(0x99, Delegate<void(CInPacket&)>(this, &BlackMarketPageMesoSearch::FUN_140f19ae0));
    UIStatusEventDispatcher::GetInstance()->FUN_141b0cd90(this);
    NotifySystem::GetInstance()->UnregisterNotify(L"NotifyChangedTokenMoney", Delegate<void(NotifyObject*)>(this, &BlackMarketPageMesoSearch::vfunc_7));
    m_spSearchBegin = 0;
    m_spSearchEnd = 0;
    m_spSearchButton = 0;
    m_spPrevPage = 0;
    m_spNextPage = 0;
}
MS2_REPLACE_METHOD(0x140F19320, BlackMarketPageMesoSearch, vfunc_2, 554, 0x0EC3824E);

// @0x140f19550
void BlackMarketPageMesoSearch::vfunc_3()
{
    if (m_58.CompareNoCase("m_mesoSearchPageSingleRange") == 0)
        FUN_140f1ad40(FUN_1401d3200()->MesoMarketProductUnit.FUN_140f20bb0(0), FUN_1401d3200()->MesoMarketProductUnit.FUN_140f20bb0(0));
    RefreshPage();
}
MS2_REPLACE_METHOD(0x140F19550, BlackMarketPageMesoSearch, vfunc_3, 121, 0x80E83548);

// @0x140f195d0
int BlackMarketPageMesoSearch::vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnClickListItem", szMethod) == 0)
    {
        ASData data;
        if (!data.FUN_1422b9620(pArgs, nArgs))
            return 1;
        unsigned __int64 nId = FUN_140718350(data.FUN_1422b8d30());
        if (!CMesoMarketMan::GetInstance()->FUN_140d6ea50(nId))
            return 1;
        MS2Ptr<CMesoMarketProductCli> spProduct = CMesoMarketMan::GetInstance()->FUN_140d6e890(nId);
        if (spProduct == 0)
            return 1;
        {
            BlockPtr spBlock = FUN_140a6a830()->FindBlockedAction(0x26);
            if (spBlock.get())
            {
                FUN_140a2ff20(spBlock, 0x26, 0);
                return 1;
            }
        }
        if (CFeatureManager::GetInstance()->FUN_14036d570(0x111) == true && (unsigned char)DAT_143ab2943 != 7)
        {
            FUN_140d73bc0(0xd56, 0, 0, L"");
            return 0;
        }
        CStringW strMsg = FUN_14028dfa0(CStringW(L"s_mesoMarket_ask_buy_text"), FUN_1409404f0(spProduct->m_n20), FUN_1409404f0(spProduct->m_n28));
        MS2Ptr<CMsgBoxData> spBox = FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &BlackMarketPageMesoSearch::FUN_140f19ef0), strMsg);
        if (spBox)
            spBox->FUN_1405340b0(nId);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140F195D0, BlackMarketPageMesoSearch, vfunc_4, 1145, 0xA02FB525);

// @0x140f19a50
void BlackMarketPageMesoSearch::vfunc_oa0_14(void* a1, int a2)
{
    FUN_140f1a420();
}
MS2_REPLACE_METHOD_VIA(0x140F19A50, BlackMarketPageMesoSearch, UIStatusEventListener, vfunc_oa0_14, 41, 0xAA3B38A7);

// @0x140f19a80
void BlackMarketPageMesoSearch::vfunc_7(NotifyObject* pNotify)
{
    NotifyChangedTokenMoney* pMoney = dynamic_cast<NotifyChangedTokenMoney*>(pNotify);
    if (pMoney->m_nType == 13)
        FUN_140f1a5a0();
}
MS2_REPLACE_METHOD(0x140F19A80, BlackMarketPageMesoSearch, vfunc_7, 79, 0x44A78D5C);

// @0x140f19ae0
void BlackMarketPageMesoSearch::FUN_140f19ae0(CInPacket& packet)
{
    int nType = packet.vfunc_o8_1();
    switch (nType)
    {
    case 7:
        FUN_140f1a230();
        break;
    case 8:
        FUN_140f1a690();
        FUN_140f1a230();
        FUN_140f1a8f0();
        break;
    case 2:
        FUN_140f1a8f0();
        break;
    }
}
MS2_REPLACE_METHOD(0x140F19AE0, BlackMarketPageMesoSearch, FUN_140f19ae0, 145, 0xCBB38DF1);

// @0x140f19b80
void BlackMarketPageMesoSearch::FUN_140f19b80(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_spSearchBegin == 0 || m_spSearchEnd == 0)
        return;
    if (params.pUserData == (ASDropdownMenu*)m_spSearchBegin)
    {
        if (m_spSearchBegin->FUN_1422df6c0() > m_spSearchEnd->FUN_1422df6c0())
            m_spSearchEnd->FUN_1422df690(m_spSearchBegin->FUN_1422df6c0());
    }
    else if (params.pUserData == (ASDropdownMenu*)m_spSearchEnd)
    {
        if (m_spSearchEnd->FUN_1422df6c0() < m_spSearchBegin->FUN_1422df6c0())
            m_spSearchBegin->FUN_1422df690(m_spSearchEnd->FUN_1422df6c0());
    }
}
MS2_REPLACE_METHOD(0x140F19B80, BlackMarketPageMesoSearch, FUN_140f19b80, 369, 0x2DEEC7B3);

// @0x140f19d00
void BlackMarketPageMesoSearch::FUN_140f19d00(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_58.CompareNoCase("m_mesoSearchPageSingleRange") == 0)
    {
        FUN_140f1ad40(FUN_1401d3200()->MesoMarketProductUnit.FUN_140f20bb0(0), FUN_1401d3200()->MesoMarketProductUnit.FUN_140f20bb0(0));
        return;
    }
    if (m_spSearchBegin == 0 || m_spSearchEnd == 0)
        return;
    __int64 nBegin = 0;
    __int64 nEnd = 0;
    m_spSearchBegin->FUN_140f1fe00("meso", &nBegin);
    m_spSearchEnd->FUN_140f1fe00("meso", &nEnd);
    if (nBegin == 0 || nBegin > nEnd)
    {
        MS2_ASSERT_AT(MS2_LINE(209), 0);
        return;
    }
    FUN_140f1ad40(nBegin, nEnd);
}
MS2_REPLACE_METHOD(0x140F19D00, BlackMarketPageMesoSearch, FUN_140f19d00, 413, 0x7650FCCF);

// @0x140f19eb0
void BlackMarketPageMesoSearch::FUN_140f19eb0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_140f1ac40(FUN_140bb9640(params.pUserData));
}
MS2_REPLACE_METHOD(0x140F19EB0, BlackMarketPageMesoSearch, FUN_140f19eb0, 45, 0xB3A2B662);

// @0x140f19ef0
bool BlackMarketPageMesoSearch::FUN_140f19ef0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        COutPacket packet(0x81);
        packet.vfunc_o10_1(8);
        packet.vfunc_o10_4(box.FUN_141a02ed0(0, 0));
        FUN_140710590(packet);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140F19EF0, BlackMarketPageMesoSearch, FUN_140f19ef0, 124, 0xF5FE63A9);

// @0x140f19f80
void BlackMarketPageMesoSearch::RefreshPage()
{
    FUN_140f1a230();
    FUN_140f1a420();
    FUN_140f1a5a0();
    FUN_140f1a690();
    FUN_140f1a8f0();
    if (m_58.CompareNoCase("m_mesoSearchPageSingleRange") == 0)
    {
        MS2Ptr<ASTextInput> spToken;
        do { m_30->FUN_140bbe940("m_myToken", spToken); if (spToken == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(245), __FUNCTION__)); } while (0);
        if (spToken)
            spToken->Invoke("setIconHtmlStr", FUN_140d6e230(*FUN_1401d3200()->MesoMarketBuyPayType.Get()));
    }
}
MS2_REPLACE_METHOD(0x140F19F80, BlackMarketPageMesoSearch, RefreshPage, 641, 0xE39D1BDF);

// @0x140f1a230
void BlackMarketPageMesoSearch::FUN_140f1a230()
{
    if (m_20 == 0 || m_itemList == 0)
        return;
    ASDataProvider list(2);
    CMesoMarketMan::GetInstance()->FUN_140d6e6d0(list);
    m_itemList->vfunc_25(list.FUN_1422bb870());
    m_itemList->vfunc_24(true);
    m_20->Invoke("updateNoticeSymbol", m_itemList->FUN_1422dd150(), m_bSearched, m_30->FUN_1422bb870());
    m_nPage = 0;
    FUN_140f1ac40(0);
}
MS2_REPLACE_METHOD(0x140F1A230, BlackMarketPageMesoSearch, FUN_140f1a230, 480, 0x46848B10);

// @0x140f1a420
void BlackMarketPageMesoSearch::FUN_140f1a420()
{
    if (m_30 == 0)
        return;
    if (m_58.CompareNoCase("m_mesoSearchPage") != 0)
        return;
    CStringW strText = StringFormat(L"{0}  {1}", FUN_14025e7a0()->FUN_1422b0570("$s_mesoMarket_myMerat"), FUN_1409404f0(FUN_140930300()));
    m_20->Invoke("UpdateMerat", strText);
}
MS2_REPLACE_METHOD(0x140F1A420, BlackMarketPageMesoSearch, FUN_140f1a420, 371, 0x964E65C5);

// @0x140f1a5a0
void BlackMarketPageMesoSearch::FUN_140f1a5a0()
{
    if (m_30 == 0)
        return;
    if (m_58.CompareNoCase("m_mesoSearchPageSingleRange") != 0)
        return;
    FUN_140cff1b0(m_20->FUN_1422bb870(), "m_myToken", FUN_1409404f0(FUN_140930490()));
}
MS2_REPLACE_METHOD(0x140F1A5A0, BlackMarketPageMesoSearch, FUN_140f1a5a0, 227, 0xDE11AA7B);

// @0x140f1a690
void BlackMarketPageMesoSearch::FUN_140f1a690()
{
    if (m_30 == 0)
        return;
    Unk_MesoLimits& limits = CMesoMarketMan::GetInstance()->FUN_140d6e940();
    CStringW strBase = FUN_1412757d0(*FUN_1401d3200()->MesoMarketBasePrice.Get());
    FUN_140cff1b0(m_30->FUN_1422bb870(), "m_explainText", FUN_14028dfa0(CStringW(L"s_mesoMarket_search_explain"), limits.m_n20, limits.m_n28));
    FUN_140cff1b0(m_30->FUN_1422bb870(), "m_marketPrice", FUN_14028dfa0(CStringW(L"s_mesoMarket_market_price"), strBase, limits.m_nBase));
}
MS2_REPLACE_METHOD(0x140F1A690, BlackMarketPageMesoSearch, FUN_140f1a690, 598, 0xA6C322F3);

// @0x140f1a8f0
void BlackMarketPageMesoSearch::FUN_140f1a8f0()
{
    if (m_30 == 0)
        return;
    Unk_MesoLimits& limits = CMesoMarketMan::GetInstance()->FUN_140d6e940();
    int nCount = CMesoMarketMan::GetInstance()->FUN_140d6eb70();
    FUN_140cff1b0(m_30->FUN_1422bb870(), "m_buyCount", FUN_14028dfa0(CStringW(L"s_mesoMarket_buy_count"), nCount, limits.m_n20));
}
MS2_REPLACE_METHOD(0x140F1A8F0, BlackMarketPageMesoSearch, FUN_140f1a8f0, 297, 0xCEBD89B5);

// @0x140f1aa20
void BlackMarketPageMesoSearch::FUN_140f1aa20()
{
    if (m_30 == 0 || m_itemList == 0 || m_spPrevPage == 0 || m_spNextPage == 0)
        return;
    m_itemList->FUN_1422cf4f0(m_nPage * m_itemList->FUN_1422dd030());
    m_spPrevPage->FUN_1422c1fe0(0 < m_nPage);
    m_spNextPage->FUN_1422c1fe0(m_nPage < m_nLastPage);
    FUN_140cfee80((*m_30).FUN_1422bb890(), "m_page", FUN_140719630(m_nPage + 1));
}
MS2_REPLACE_METHOD(0x140F1AA20, BlackMarketPageMesoSearch, FUN_140f1aa20, 530, 0xDF77AD80);

// @0x140f1ac40
void BlackMarketPageMesoSearch::FUN_140f1ac40(int nDelta)
{
    if (m_itemList == 0)
        return;
    int nCount = m_itemList->FUN_1422dd150();
    if (nCount == 0)
    {
        m_nPage = 0;
        FUN_140f1aa20();
    }
    else
    {
        m_nLastPage = (nCount - 1) / (int)m_itemList->FUN_1422dd030();
        m_nPage = FUN_140f1ffe0(m_nPage + nDelta, 0, m_nLastPage);
        FUN_140f1aa20();
    }
}
MS2_REPLACE_METHOD(0x140F1AC40, BlackMarketPageMesoSearch, FUN_140f1ac40, 236, 0xD1903D62);

// @0x140f1ad40
void BlackMarketPageMesoSearch::FUN_140f1ad40(__int64 nBegin, __int64 nEnd)
{
    COutPacket packet(0x81);
    packet.vfunc_o10_1(7);
    packet.vfunc_o10_4(nBegin);
    packet.vfunc_o10_4(nEnd);
    FUN_140710590(packet);
    m_bSearched = true;
}
MS2_REPLACE_METHOD(0x140F1AD40, BlackMarketPageMesoSearch, FUN_140f1ad40, 129, 0x3488AA7C);

// ---- BlackMarketPageMesoRegister ---------------------------------------------------------------------------------

// @0x140f1add0
BlackMarketPageMesoRegister::BlackMarketPageMesoRegister()
    : BlackMarketPage("m_mesoRegisterPage"), m_nPage(0), m_nLastPage(0)
{
}

// @0x140f1af00
BlackMarketPageMesoRegister::~BlackMarketPageMesoRegister()
{
}

// @0x140f1afd0
void BlackMarketPageMesoRegister::vfunc_1()
{
    BlackMarketPage::vfunc_1();
    do { m_30->FUN_140bbe940("m_afterTaxMerat", m_spAfterTaxMerat); if (m_spAfterTaxMerat == 0) throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(381), __FUNCTION__)); } while (0);
    if (m_30->FUN_140bbe7c0("m_mesoDropdown", m_spMesoDropdown))
        m_spMesoDropdown->FUN_1422df9a0(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageMesoRegister::FUN_140f1c900), 0);
    m_30->FUN_140bbe940("m_mesoSingleRange", m_spSingleRange);
    if (m_30->FUN_140bbe940("m_buyMerat", m_spBuyMerat))
        m_spBuyMerat->FUN_1422e0920(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageMesoRegister::FUN_140f1c930));
    if (m_30->FUN_140bbe640("m_register", m_spRegister))
        m_spRegister->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageMesoRegister::FUN_140f1c3b0), 0);
    if (m_30->FUN_140bbe640("m_prevPage", m_spPrevPage))
        m_spPrevPage->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageMesoRegister::FUN_140f1ca80), (void*)-1);
    if (m_30->FUN_140bbe640("m_nextPage", m_spNextPage))
        m_spNextPage->FUN_1422ce240(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &BlackMarketPageMesoRegister::FUN_140f1ca80), 1);
    if (m_spMesoDropdown)
    {
        ASDataProvider list(2);
        int nCount = FUN_1401d3200()->MesoMarketProductUnit.FUN_140f20b90();
        for (unsigned int i = 0; i < nCount; i++)
        {
            __int64 nUnit = FUN_1401d3200()->MesoMarketProductUnit.FUN_140f20bb0(i);
            CStringW strLabel = FUN_14028dfa0(CStringW(L"s_mesoMarket_sellMeso_dropdownItem"), FUN_1412757d0(nUnit));
            ASObj row(2);
            row.FUN_1407cbb20("label", strLabel);
            row.FUN_1409c1180("meso", nUnit);
            list.FUN_1422bc050(row.FUN_1422bb890());
        }
        m_spMesoDropdown->FUN_1422df720(list.FUN_1422bb870());
        m_spMesoDropdown->FUN_1422df690(0);
        m_spMesoDropdown->vfunc_24(true);
    }
    PacketHandlerManager::GetInstance()->RegisterHandler(0x99, Delegate<void(CInPacket&)>(this, &BlackMarketPageMesoRegister::FUN_140f1c300));
    UIStatusEventDispatcher::GetInstance()->FUN_141b0cd00(this);
    CStringW strBase = FUN_1412757d0(*FUN_1401d3200()->MesoMarketBasePrice.Get());
    FUN_140cff1b0(m_30->FUN_1422bb870(), "m_unitPriceTitle", FUN_14028dfa0(CStringW(L"s_mesoMarket_sale_per_price"), strBase));
    FUN_140f1cc00();
}
MS2_REPLACE_METHOD(0x140F1AFD0, BlackMarketPageMesoRegister, vfunc_1, 3520, 0x454F273C);

// @0x140f1bdc0
void BlackMarketPageMesoRegister::vfunc_2()
{
    PacketHandlerManager::GetInstance()->UnregisterHandler(0x99, Delegate<void(CInPacket&)>(this, &BlackMarketPageMesoRegister::FUN_140f1c300));
    UIStatusEventDispatcher::GetInstance()->FUN_141b0cd90(this);
    BlackMarketPage::vfunc_2();
    m_spMesoDropdown = 0;
    m_spSingleRange = 0;
    m_spBuyMerat = 0;
    m_spAfterTaxMerat = 0;
    m_spRegister = 0;
    m_spPrevPage = 0;
    m_spNextPage = 0;
    m_spPrevPage = 0;
    m_spNextPage = 0;
}
MS2_REPLACE_METHOD(0x140F1BDC0, BlackMarketPageMesoRegister, vfunc_2, 440, 0xFFA9B89B);

// @0x140f1bf80
void BlackMarketPageMesoRegister::vfunc_3()
{
    FUN_140f1d020();
}
MS2_REPLACE_METHOD(0x140F1BF80, BlackMarketPageMesoRegister, vfunc_3, 24, 0x7BEB15BF);

// @0x140f1bfa0
int BlackMarketPageMesoRegister::vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp("OnClickListItem", szMethod) == 0)
    {
        ASData data;
        if (!data.FUN_1422b9620(pArgs, nArgs))
            return 1;
        unsigned __int64 nId = FUN_140718350(data.FUN_1422b8d30());
        MS2Ptr<CMesoMarketProductCli> spProduct = CMesoMarketMan::GetInstance()->FUN_140d6e7e0(nId);
        if (spProduct == 0)
            return 1;
        CStringW strKey = L"s_mesoMarket_ask_stopsale";
        if (spProduct->FUN_140d6d900())
            strKey = L"s_mesoMarket_ask_stopsale_expire";
        CStringW strMsg = FUN_14028dfa0(strKey, FUN_1409404f0(spProduct->m_n20));
        MS2Ptr<CMsgBoxData> spBox = FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)>(this, &BlackMarketPageMesoRegister::FUN_140f1cb70), strMsg);
        if (spBox)
            spBox->FUN_1405340b0(nId);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x140F1BFA0, BlackMarketPageMesoRegister, vfunc_4, 803, 0x88F6241B);

// @0x140f1c2d0
void BlackMarketPageMesoRegister::vfunc_oa0_11(void* a1)
{
    FUN_140f1d4e0();
}
MS2_REPLACE_METHOD_VIA(0x140F1C2D0, BlackMarketPageMesoRegister, UIStatusEventListener, vfunc_oa0_11, 36, 0x2E9E092F);

// @0x140f1c300
void BlackMarketPageMesoRegister::FUN_140f1c300(CInPacket& packet)
{
    int nType = packet.vfunc_o8_1();
    switch (nType)
    {
    case 5:
        FUN_140f1cf70();
        FUN_140f1d1c0();
        FUN_140f1dab0();
        break;
    case 4:
        FUN_140f1d1c0();
        break;
    case 6:
        FUN_140f1d1c0();
        break;
    case 2:
        FUN_140f1dab0();
        break;
    }
}
MS2_REPLACE_METHOD(0x140F1C300, BlackMarketPageMesoRegister, FUN_140f1c300, 164, 0x16F7DE12);

// @0x140f1c3b0
void BlackMarketPageMesoRegister::FUN_140f1c3b0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_spMesoDropdown == 0)
        return;
    __int64 nMeso = 0;
    m_spMesoDropdown->FUN_140f1fe00("meso", &nMeso);
    if (nMeso == 0)
    {
        FUN_140d74390(FUN_140298ea0(L"s_mesoMarket_error_invalidSaleMoney"), 0, FUN_140b240b0());
        return;
    }
    {
        BlockPtr spBlock = FUN_140a6a830()->FindBlockedAction(0x25);
        if (spBlock.get())
        {
            FUN_140a2ff20(spBlock, 0x25, 0);
            return;
        }
    }
    if (!CMesoMarketMan::GetInstance()->FUN_140d6e960(nMeso, FUN_140f1de00()))
        return;
    Unk_MesoLimits& limits = CMesoMarketMan::GetInstance()->FUN_140d6e940();
    CStringW strTitle = FUN_14028dfa0(CStringW(L"s_mesoMarket_register_terms_title"), limits.m_n1C);
    float fRateB = limits.FUN_140d6e210();
    float fRateA = limits.FUN_140d6e1f0();
    __int64 nFeeBase = FUN_1401bcde0();
    int nFeeRate = FUN_1401bce00();
    CStringW strText = FUN_14028dfa0(CStringW(L"s_mesoMarket_register_terms_content"), *FUN_1401d3200()->BlackMarketSellEndDay.Get(),
                                     nFeeRate, nFeeBase, FUN_14083cf50(FUN_1401bcd30(), 0), *FUN_1401d3200()->MailExpiryDays.Get(),
                                     limits.m_n24, fRateA, fRateB, limits.m_n1C, limits.m_n20);
    MS2Ptr<CMsgBoxData> spBox = FUN_140d748b0(7, strTitle, strText, Delegate<bool(int, const CMsgBoxData&)>(this, &BlackMarketPageMesoRegister::FUN_140f1cac0));
    spBox->FUN_140e01830(nMeso);
    spBox->FUN_140e01830(FUN_140f1dec0());
}
MS2_REPLACE_METHOD(0x140F1C3B0, BlackMarketPageMesoRegister, FUN_140f1c3b0, 1353, 0x34ADC973);

// @0x140f1c900
void BlackMarketPageMesoRegister::FUN_140f1c900(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_140f1d5b0();
}
MS2_REPLACE_METHOD(0x140F1C900, BlackMarketPageMesoRegister, FUN_140f1c900, 29, 0x6AAFE4D3);

// @0x140f1c930
void BlackMarketPageMesoRegister::FUN_140f1c930(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (m_spBuyMerat == 0)
        return;
    Unk_MesoLimits& limits = CMesoMarketMan::GetInstance()->FUN_140d6e940();
    __int64 nValue = FUN_140718320(FUN_14083cf10(m_spBuyMerat->FUN_1422e0b00()));
    if (nValue > limits.m_nMax)
        m_spBuyMerat->FUN_1422e0ab0(FUN_140763e10(limits.m_nMax));
    FUN_140f1d5b0();
}
MS2_REPLACE_METHOD(0x140F1C930, BlackMarketPageMesoRegister, FUN_140f1c930, 315, 0x4D803DB7);

// @0x140f1ca80
void BlackMarketPageMesoRegister::FUN_140f1ca80(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_140f1dfa0(FUN_140bb9640(params.pUserData));
}
MS2_REPLACE_METHOD(0x140F1CA80, BlackMarketPageMesoRegister, FUN_140f1ca80, 45, 0x38408087);

// @0x140f1cac0
bool BlackMarketPageMesoRegister::FUN_140f1cac0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        FUN_140d74e50(7);
        COutPacket packet(0x81);
        packet.vfunc_o10_1(5);
        packet.vfunc_o10_4(box.FUN_141a02ed0(0, 0));
        packet.vfunc_o10_4(box.FUN_141a02ed0(1, 0));
        FUN_140710590(packet);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140F1CAC0, BlackMarketPageMesoRegister, FUN_140f1cac0, 168, 0xDF4567AF);

// @0x140f1cb70
bool BlackMarketPageMesoRegister::FUN_140f1cb70(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
    {
        COutPacket packet(0x81);
        packet.vfunc_o10_1(6);
        packet.vfunc_o10_4(box.FUN_141a02ed0(0, 0));
        FUN_140710590(packet);
    }
    return true;
}
MS2_REPLACE_METHOD(0x140F1CB70, BlackMarketPageMesoRegister, FUN_140f1cb70, 124, 0x39853F19);

// @0x140f1cc00
void BlackMarketPageMesoRegister::FUN_140f1cc00()
{
    if (m_30 == 0)
        return;
    if (!CFeatureManager::GetInstance()->FUN_14036d570(0xf4))
        return;
    if (FUN_1401d3200()->MesoMarketProductUnit.FUN_140f20b90() == 1)
    {
        if (m_spMesoDropdown)
            m_spMesoDropdown->vfunc_3(0);
        if (m_spSingleRange)
        {
            m_spSingleRange->vfunc_3(1);
            m_spSingleRange->FUN_1422e0ab0(FUN_1409404f0(FUN_1401d3200()->MesoMarketProductUnit.FUN_140f20bb0(0)));
        }
    }
    MS2Ptr<ASTextField> spFee;
    m_30->FUN_140beaf20("m_noticeFee", spFee);
    if (spFee)
        FUN_140d01340((*spFee).FUN_1422bb890(), 3, 2);
    MS2Ptr<ASTextField> spTotal;
    m_30->FUN_140beaf20("m_totalPrice", spTotal);
    if (spTotal)
        spTotal->vfunc_3(0);
    MS2Ptr<ASTextField> spTotalTitle;
    m_30->FUN_140beaf20("m_saleTotalPriceTitle", spTotalTitle);
    if (spTotalTitle)
        spTotalTitle->vfunc_3(0);
}
MS2_REPLACE_METHOD(0x140F1CC00, BlackMarketPageMesoRegister, FUN_140f1cc00, 863, 0x95F8AD8B);

// @0x140f1cf70
void BlackMarketPageMesoRegister::FUN_140f1cf70()
{
    if (m_spMesoDropdown)
        m_spMesoDropdown->FUN_1422df690(0);
    if (m_spBuyMerat)
        m_spBuyMerat->FUN_1422e0ab0(L"0");
}
MS2_REPLACE_METHOD(0x140F1CF70, BlackMarketPageMesoRegister, FUN_140f1cf70, 159, 0x3467551F);

// @0x140f1d020
void BlackMarketPageMesoRegister::FUN_140f1d020()
{
    FUN_140f1d1c0();
    FUN_140f1d4e0();
    FUN_140f1d5b0();
    FUN_140f1d730();
    FUN_140f1dab0();
    m_spBuyMerat->Invoke("setIconHtmlStr", FUN_140d6e230(*FUN_1401d3200()->MesoMarketBuyPayType.Get()));
    int nCurrency = 3;
    switch (*FUN_1401d3200()->MesoMarketIconType.Get())
    {
    case 0:
        nCurrency = 3;
        break;
    case 1:
        nCurrency = 10;
        break;
    case 2:
        nCurrency = 9;
        break;
    }
    m_spAfterTaxMerat->Invoke("setIconHtmlStr", FUN_140d6e230(nCurrency));
}
MS2_REPLACE_METHOD(0x140F1D020, BlackMarketPageMesoRegister, FUN_140f1d020, 395, 0x7F78303C);

// @0x140f1d1c0
void BlackMarketPageMesoRegister::FUN_140f1d1c0()
{
    if (m_20 == 0 || m_30 == 0 || m_itemList == 0)
        return;
    ASDataProvider list(2);
    CMesoMarketMan::GetInstance()->FUN_140d6e5b0(list);
    m_itemList->vfunc_25(list.FUN_1422bb870());
    m_itemList->vfunc_24(true);
    Unk_MesoLimits& limits = CMesoMarketMan::GetInstance()->FUN_140d6e940();
    FUN_140cfee80(m_30->FUN_1422bb870(), "m_listCount", FUN_14028dfa0(CStringW(L"s_mesoMarket_register_count"), list.FUN_1422bc5d0(), limits.m_n18));
    m_20->Invoke("updateNoticeSymbol", m_itemList->FUN_1422dd150(), false, m_30->FUN_1422bb870());
    m_nPage = 0;
    FUN_140f1dfa0(0);
}
MS2_REPLACE_METHOD(0x140F1D1C0, BlackMarketPageMesoRegister, FUN_140f1d1c0, 780, 0xC9DACC43);

// @0x140f1d4e0
void BlackMarketPageMesoRegister::FUN_140f1d4e0()
{
    if (m_30 == 0)
        return;
    FUN_140cfee80(m_30->FUN_1422bb870(), "m_currentMeso", FUN_1409404f0(DAT_143ab2898));
}
MS2_REPLACE_METHOD(0x140F1D4E0, BlackMarketPageMesoRegister, FUN_140f1d4e0, 189, 0x4A022BA8);

// @0x140f1d5b0
void BlackMarketPageMesoRegister::FUN_140f1d5b0()
{
    if (m_30 == 0)
        return;
    Unk_MesoLimits& limits = CMesoMarketMan::GetInstance()->FUN_140d6e940();
    __int64 nTotal = FUN_140f1dec0();
    FUN_140cfee80(m_30->FUN_1422bb870(), "m_totalPrice", FUN_1409404f0(nTotal));
    __int64 nFee = (__int64)((float)nTotal * limits.m_fRateA);
    __int64 nAfterTax = nTotal - nFee;
    m_spAfterTaxMerat->FUN_1422e0ab0(FUN_1409404f0(nAfterTax));
}
MS2_REPLACE_METHOD(0x140F1D5B0, BlackMarketPageMesoRegister, FUN_140f1d5b0, 369, 0x7D0D3B99);

// @0x140f1d730
void BlackMarketPageMesoRegister::FUN_140f1d730()
{
    if (m_30 == 0)
        return;
    Unk_MesoLimits& limits = CMesoMarketMan::GetInstance()->FUN_140d6e940();
    int nDays = limits.m_n24;
    float fRateA = limits.m_fRateA * 100.0f;
    float fRateB = limits.m_fRateB * 100.0f;
    int nCount = limits.m_n1C;
    CStringW strBase = FUN_1412757d0(*FUN_1401d3200()->MesoMarketBasePrice.Get());
    FUN_140cff1b0(m_30->FUN_1422bb870(), "m_saleRangeRate", FUN_14028dfa0(CStringW(L"s_mesoMarket_sale_range_rate"), fRateB));
    FUN_140cff1b0(m_30->FUN_1422bb870(), "m_marketPrice", FUN_14028dfa0(CStringW(L"s_mesoMarket_market_price"), strBase, limits.m_nBase));
    FUN_140cff1b0(m_30->FUN_1422bb870(), "m_noticeFee", FUN_14028dfa0(CStringW(L"s_mesoMarket_register_notice"), nDays, fRateA, nCount));
}
MS2_REPLACE_METHOD(0x140F1D730, BlackMarketPageMesoRegister, FUN_140f1d730, 883, 0x257628E0);

// @0x140f1dab0
void BlackMarketPageMesoRegister::FUN_140f1dab0()
{
    if (m_30 == 0)
        return;
    Unk_MesoLimits& limits = CMesoMarketMan::GetInstance()->FUN_140d6e940();
    int nCount = CMesoMarketMan::GetInstance()->FUN_140d6eb50();
    FUN_140cff1b0(m_30->FUN_1422bb870(), "m_registerCount", FUN_14028dfa0(CStringW(L"s_mesoMarket_register_count_per_day"), nCount, limits.m_n1C));
}
MS2_REPLACE_METHOD(0x140F1DAB0, BlackMarketPageMesoRegister, FUN_140f1dab0, 297, 0xF3F7FEAD);

// @0x140f1dbe0
void BlackMarketPageMesoRegister::FUN_140f1dbe0()
{
    if (m_30 == 0 || m_itemList == 0 || m_spPrevPage == 0 || m_spNextPage == 0)
        return;
    m_itemList->FUN_1422cf4f0(m_nPage * m_itemList->FUN_1422dd030());
    m_spPrevPage->FUN_1422c1fe0(0 < m_nPage);
    m_spNextPage->FUN_1422c1fe0(m_nPage < m_nLastPage);
    FUN_140cfee80((*m_30).FUN_1422bb890(), "m_page", FUN_140719630(m_nPage + 1));
}
MS2_REPLACE_METHOD(0x140F1DBE0, BlackMarketPageMesoRegister, FUN_140f1dbe0, 530, 0x01AE3145);

// @0x140f1de00
__int64 BlackMarketPageMesoRegister::FUN_140f1de00()
{
    if (m_spBuyMerat == 0)
        return 0;
    return FUN_140718320(FUN_14083cf10(m_spBuyMerat->FUN_1422e0b00()));
}
MS2_REPLACE_METHOD(0x140F1DE00, BlackMarketPageMesoRegister, FUN_140f1de00, 175, 0xE96C0C54);

// @0x140f1dec0
__int64 BlackMarketPageMesoRegister::FUN_140f1dec0()
{
    __int64 nBase = *FUN_1401d3200()->MesoMarketBasePrice.Get();
    __int64 nMeso = 0;
    if (m_spMesoDropdown)
        m_spMesoDropdown->FUN_140f1fe00("meso", &nMeso);
    if (nMeso == 0 || nBase == 0)
        return 0;
    __int64 nTotal = FUN_140f1de00() * (nMeso / nBase);
    return nTotal;
}
MS2_REPLACE_METHOD(0x140F1DEC0, BlackMarketPageMesoRegister, FUN_140f1dec0, 216, 0xB30A45C9);

// @0x140f1dfa0
void BlackMarketPageMesoRegister::FUN_140f1dfa0(int nDelta)
{
    if (m_itemList == 0)
        return;
    int nCount = m_itemList->FUN_1422dd150();
    if (nCount == 0)
    {
        m_nPage = 0;
        FUN_140f1dbe0();
    }
    else
    {
        m_nLastPage = (nCount - 1) / (int)m_itemList->FUN_1422dd030();
        m_nPage = FUN_140f1ffe0(m_nPage + nDelta, 0, m_nLastPage);
        FUN_140f1dbe0();
    }
}
MS2_REPLACE_METHOD(0x140F1DFA0, BlackMarketPageMesoRegister, FUN_140f1dfa0, 236, 0x1ECCD4FA);

// ---- inline COMDATs first emitted here ---------------------------------------------------------------------------

// @0x140f1fd70
inline void ASDataProvider::FUN_140f1fd70(unsigned nIndex, const CString& strMember, __int64* pOut)
{
    AScript row = FUN_1422df140(nIndex);
    if (row.FUN_1422ba9a0())
        return;
    row.FUN_1422bb070(strMember, pOut);
}

// @0x140f1fe00
inline void ASDropdownMenu::FUN_140f1fe00(const CString& strMember, __int64* pOut)
{
    int nIndex = FUN_1422df6c0();
    if (nIndex < 0)
        return;
    MS2Ptr<ASDataProvider> spList = FUN_1422df770();
    if (spList == 0)
        return;
    if ((unsigned)nIndex >= spList->FUN_1422bc5d0())
        return;
    spList->FUN_140f1fd70(nIndex, strMember, pOut);
}

// @0x140f1fec0
inline Scaleform::GFx::Value AScript::Invoke(const char* szMethod, unsigned int a1, bool a2, Scaleform::GFx::Value a3)
{
    ASArgList args;
    args.FUN_1409b2800(3);
    FUN_1422bcd10(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    FUN_1422bcc70(args.FUN_1409b1f70(2), a3);
    return FUN_1422bb8f0(szMethod, args);
}

// @0x140f1ffe0
inline int FUN_140f1ffe0(const int& n, int nMin, int nMax)
{
    if (n < nMin)
        return nMin;
    if (n > nMax)
        return nMax;
    return n;
}

MS2_EMIT_CRT_MEMMOVE_S();
// MS2-RANGE: 0x142ca8f40-0x142ca8f70 .text$yd
