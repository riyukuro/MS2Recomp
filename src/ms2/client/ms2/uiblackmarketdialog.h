// uiblackmarketdialog.h - UIBlackMarketDialog (RTTI .?AVUIBlackMarketDialog@@, UIDialog, ui id 0x4e97): the black market
// window. Owning unit: ?\uiblackmarketdialog.cpp (0x1418cf080-0x1418d3050; header name assumed from the unit path).
//
// The window hosts five pages (BlackMarketPage, placeholder/blackmarketpage.h): the item search and item register
// pages, and the meso search, meso register and single-range meso search pages. m_pages lists them in tab order; the
// "OnChangeTab" call from the movie selects m_pCurPage. Every page-specific entry point (the FUN_ forwarders below) runs
// the page call only while its page is alive (and, for the second group, the selected one).
#pragma once

#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/blackmarketpage.h"

class CItem;
class Unk_140acd6e0;

class UIBlackMarketDialog : public UIDialog
{
public:
    UIBlackMarketDialog();                                          // 0x1418cf080
    virtual ~UIBlackMarketDialog();                                 //  0 0x1418cf500 (??_G 0x1418d21d0)
    virtual CString vfunc_1();                                      //  1 0x1418cf5d0 "BlackMarketDialog"
    virtual int vfunc_13();                                         // 13 0x1418d00a0 enter / tab key -> "onProcessKey"
    virtual void vfunc_15();                                        // 15 0x1418d0010 per frame: the page's slot 5
    virtual void OnLoadInit();                                      // 20 0x1418cfb10
    virtual void OnLoadComplete();                                  // 22 0x1418cfb50
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1418cfee0 "OnChangeTab"
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x1418d0270 item tooltips / clicks
    // @0x1418d2210
    virtual int vfunc_48() { return 0x4e97; }                       // 48
    virtual int vfunc_65();                                         // 65 0x1418cf620 open: reload the table, request the lists
    virtual void vfunc_67();                                        // 67 0x1418cf680 close
    virtual void vfunc_72();                                        // 72 0x1418cf860
    virtual int vfunc_73();                                         // 73 0x1418cf770
    virtual int vfunc_74(int nMsg, void* p2, void* p3);             // 74 0x1418cfa40
    virtual void vfunc_79(void* p);                                 // 79 0x1418cf920

    void FUN_1418d0b60(int nA, int nB, void* p);                    // item search page: 0x140f0de60
    bool FUN_1418d0be0();                                           // the register page is selected
    void FUN_1418d0c20(int nIndex);                                 // select a tab
    bool FUN_1418d0da0(BlackMarketPage* pPage);                     // pPage is the selected page
    void FUN_1418d0de0(void* p);                                    // register page: "buildOwnerItemList"
    void FUN_1418d0e40(MS2Ptr<Unk_BlackMarketEntry> spEntry);       // register page: 0x140f12d40
    void FUN_1418d0f00(MS2Ptr<Unk_BlackMarketEntry> spEntry, int n);   // register page: 0x140f13030
    void FUN_1418d0fc0(void* p2, void* p3);                         // register page (selected): 0x140f13420
    void FUN_1418d1080(MS2Ptr<Unk_BlackMarketEntry> spEntry, int n);   // item search page: show an entry
    void FUN_1418d1330(int nA, int nB, void* p);                    // item search page: 0x140f0d990
    void FUN_1418d13a0(int nA, int nB, void* p);                    // register page (selected): 0x140f137a0
    void FUN_1418d1430(const Scaleform::GFx::FunctionHandler::Params& params);   // detail button: open the market web page

private:
    MS2_LAYOUT_FRIEND;
    BlackMarketPage* m_pCurPage;                                    // +0x178 the selected page
    MS2Ptr<BlackMarketPageItemSearch> m_spItemSearch;               // +0x180
    MS2Ptr<BlackMarketPageItemRegister> m_spItemRegister;           // +0x190
    MS2Ptr<BlackMarketPageMesoSearch> m_spMesoSearch;               // +0x1a0
    MS2Ptr<BlackMarketPageMesoRegister> m_spMesoRegister;           // +0x1b0
    MS2Ptr<BlackMarketPageMesoSearch> m_spMesoSearchSingle;         // +0x1c0 "m_mesoSearchPageSingleRange"
    std::vector<BlackMarketPage*> m_pages;                          // +0x1d0
    MS2Ptr<Unk_140acd6e0> m_spDetailButton;                         // +0x1e8 "m_mesoMarketDetailButton"
};
MS2_CHECK_SIZE(UIBlackMarketDialog, 0x1f8);
MS2_CHECK_OFFSET(UIBlackMarketDialog, m_pCurPage, 0x178);
MS2_CHECK_OFFSET(UIBlackMarketDialog, m_spItemSearch, 0x180);
MS2_CHECK_OFFSET(UIBlackMarketDialog, m_spMesoSearchSingle, 0x1c0);
MS2_CHECK_OFFSET(UIBlackMarketDialog, m_pages, 0x1d0);
MS2_CHECK_OFFSET(UIBlackMarketDialog, m_spDetailButton, 0x1e8);
