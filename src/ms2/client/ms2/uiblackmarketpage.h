// uiblackmarketpage.h - the pages of the black market window (UIBlackMarketDialog): the BlackMarketPage base and the
// item search / item register pages (client\ms2\uiblackmarketpage.cpp, 0x140f0be80-0x140f18620), plus the layouts of the
// two meso pages (client\ms2\uiblackmarketpagemeso.cpp, 0x140f18620-0x140f21590). Header name assumed from the unit path.
// Layouts proved by the ctors (0x140f0bfe0 base 0x60, 0x140f0c7e0 search 0x100, 0x140f11850 register 0xd0, 0x140f18620
// meso search 0xc8, 0x140f1add0 meso register 0xe0) and the operator new sizes in the dialog ctor. Member and method
// names are invented from their use (the AS method / member strings).
//
// BlackMarketPage vftable 0x142e6fc00 (7 slots): 0 ~ (??_G 0x140f0c680), 1 OnInit 0x140f0c1c0 (binds "m_itemList"),
// 2 reset 0x140f0c340, 3 and 4 pure (page selected / AS -> C++ call), 5 empty 0x140f0c3a0 (per frame), 6 0x140f0c3b0
// (the market product of an id; null here). The search (0x142e711f8) and register (0x142e71238) tables add no slots.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/commonfiles/blackmarketitemoption.h"
#include "ms2/placeholder/cblackmarketman.h"

class CInPacket;
class CItem;
class CMsgBoxData;
class ASTextField;
class ASTileList;
class ASObj;
class ASArray;
class ASData;
namespace NotifyContext { class BindData; }

// The market record of a listed item (CBlackMarketProduct, the item at +0x38). The old placeholder name is kept for the
// dialog's declarations.
typedef CBlackMarketProduct Unk_BlackMarketEntry;

class BlackMarketPage : public CPtred
{
public:
    explicit BlackMarketPage(const CString& strName);               // 0x140f0bfe0
    virtual ~BlackMarketPage();                                     //  0 0x140f0c090 (??_G 0x140f0c680)
    virtual void vfunc_1();                                         //  1 0x140f0c1c0 OnInit: bind the page root and its "m_itemList"
    virtual void vfunc_2();                                         //  2 0x140f0c340 reset
    virtual void vfunc_3() = 0;                                     //  3 the page was selected
    virtual int vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs) = 0;   //  4 AS -> C++ call
    virtual void vfunc_5();                                         //  5 0x140f0c3a0 empty (per frame)
    virtual MS2Ptr<CBlackMarketProduct> vfunc_6(unsigned __int64 nId);   //  6 0x140f0c3b0 product of an id

    void FUN_140f0c150(MS2Ptr<AScript> spRoot);                     // m_20 = spRoot (the callee destroys it)
    void FUN_140f0c1a0(int nMovieId);                               // m_50 = nMovieId
    void FUN_140f0c400(const CString& strState);                    // "updateNoticeSymbolFrom" with the page object

    MS2_LAYOUT_FRIEND;
    bool m_bShown;                                                  // +0x18 the page was filled once (slot 3)
    MS2Ptr<AScript> m_20;                                           // +0x20 the dialog's root object
    MS2Ptr<ASMovieClip> m_30;                                       // +0x30 the page's display object
    MS2Ptr<ASTileList> m_itemList;                                  // +0x40 "m_itemList"
    int m_50;                                                       // +0x50 movie id (2)
    CString m_58;                                                   // +0x58 child name
};
MS2_CHECK_SIZE(BlackMarketPage, 0x60);
MS2_CHECK_OFFSET(BlackMarketPage, m_20, 0x20);
MS2_CHECK_OFFSET(BlackMarketPage, m_50, 0x50);

// The request the page waits a reply for (0x20 bytes; ctor 0x140f0be80, reset 0x140f0bf40).
struct BlackMarketRequest
{
    BlackMarketRequest();                                           // 0x140f0be80
    void SetProduct(int nAction, unsigned __int64 nKey, int nCount);   // 0x140f0bec0
    void SetKeyword(int nAction, const CStringW& strKeyword);       // 0x140f0bf00
    void Reset();                                                   // 0x140f0bf40
    int Done(int nAction);                                          // 0x140f0bfa0 resets when nAction is the pending one

    int m_nAction;                                                  // +0x00 (3 cancel, 5 buy, ...)
    unsigned __int64 m_nKey;                                        // +0x08 product id
    int m_nCount;                                                   // +0x10
    CStringW m_strKeyword;                                          // +0x18
};
MS2_CHECK_SIZE(BlackMarketRequest, 0x20);

class BlackMarketPageItemSearch : public BlackMarketPage
{
public:
    BlackMarketPageItemSearch();                                    // 0x140f0c7e0
    virtual ~BlackMarketPageItemSearch() = default;                 //  0 0x140f17860 (??_G 0x140f17b90; implicit: no vptr store)
    virtual void vfunc_1();                                         //  1 0x140f0c900 "initData"
    virtual void vfunc_2();                                         //  2 0x140f0caa0
    virtual void vfunc_3();                                         //  3 0x140f0cb50
    virtual int vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 4 0x140f0cb90
    virtual void vfunc_5();                                         //  5 0x140f0d550 send a pending search
    virtual MS2Ptr<CBlackMarketProduct> vfunc_6(unsigned __int64 nId);   //  6 0x140f0d500 product of the search result

    void FUN_140f0d630(int nMsg, void* p2, void* p3);               // key input: the item name candidates
    void FUN_140f0d990(int nA, int nB, void* p);                    // rebuild "buildItemList"
    void FUN_140f0db00(MS2Ptr<CBlackMarketProduct> spEntry, int nState);   // "updateItem" (the callee destroys the entry)
    void FUN_140f0de60(int nA, int nB, void* p);                    // server notice
    void FUN_140f0dfe0(int nAction);                                // reply received
    void FUN_140f0e050();                                           // "buildSearchOptionList"
    void FUN_140f0e7b0(ASArray& out, ATL::CAtlList<Unk_BmPtr<CBlackMarketTable::TabInfo> >* pTabs);   // the tab tree
    void FUN_140f0e940(ASObj& out, int nTabId);                     // the option lists of a low category
    void FUN_140f0efe0(ASObj& out, int nTabId);                     // the low categories of a tab
    void FUN_140f0f0f0(int nFirst, int nEnd, POSITION pos);         // "buildPage" from the search list position
    void FUN_140f0f1d0();                                           // clear the name input
    void FUN_140f0f250();                                           // "errorSearchFromDelay"
    int FUN_140f0f2c0();                                            // the search delay is over
    int FUN_140f0f310(ASData* pArgs, int n);                        // read the search condition
    void FUN_140f103c0(unsigned __int64 nId, const CString& strState);   // "OnClickBuy"
    int FUN_140f10720(ASObj& obj, const CStringW& strLabel, const CString& strKey, int nValue);   // dropdown entry
    void FUN_140f107a0(unsigned __int64 nId, int nCount);           // send the purchase
    void FUN_140f108e0(MS2Ptr<CBlackMarketProduct> spEntry);        // ask the count
    void FUN_140f10d90(MS2Ptr<CBlackMarketProduct> spEntry, int nCount);   // ask the purchase
    bool FUN_140f113e0(int nResult, const CMsgBoxData& box);        // count box result
    bool FUN_140f115b0(int nResult, const CMsgBoxData& box);        // purchase box result

    MS2_LAYOUT_FRIEND;
    int m_nOptionId;                                                // +0x60 option id of the shown option lists (-1)
    int m_nCategory;                                                // +0x64 category of the last search
    unsigned int m_dwSearchTick;                                    // +0x68 tick of the last sent search
    bool m_bAutoCompleteName;                                       // +0x6c the category completes item names
    int m_nPending;                                                 // +0x70 category of the pending search
    bool m_bSendPending;                                            // +0x74
    BlackMarketRequest m_request;                                   // +0x78
    MS2Ptr<ASTextInput> m_spInputName;                              // +0x98 "m_inputName"
    MS2Ptr<CBlackMarketSchCond> m_spCond;                           // +0xa8
    CBlackMarketTable::TabMap m_tabs;                               // +0xb8 every shown tab by its id
};
MS2_CHECK_SIZE(BlackMarketPageItemSearch, 0x100);
MS2_CHECK_OFFSET(BlackMarketPageItemSearch, m_request, 0x78);
MS2_CHECK_OFFSET(BlackMarketPageItemSearch, m_tabs, 0xb8);

// The item chosen for registering (0x18 bytes; ctor 0x140f11620, reset 0x140f11680).
struct BlackMarketRegisterItem
{
    BlackMarketRegisterItem();                                      // 0x140f11620
    void Reset();                                                   // 0x140f11680
    int IsSame(int nId, int nRank);                                 // 0x140f116d0
    int Set(MS2Ptr<CItem> spItem);                                  // 0x140f11710 (the callee destroys the item)
    void SetPrice(unsigned __int64 nPrice);                         // 0x140f11810
    unsigned __int64 GetPrice();                                    // 0x140f11830

    int m_nItemId;                                                  // +0x00
    int m_nRank;                                                    // +0x04
    unsigned __int64 m_nPrice;                                      // +0x08
    int m_nDefault;                                                 // +0x10 FUN_1401bcd30()
};
MS2_CHECK_SIZE(BlackMarketRegisterItem, 0x18);

class BlackMarketPageItemRegister : public BlackMarketPage
{
public:
    BlackMarketPageItemRegister();                                  // 0x140f11850
    virtual ~BlackMarketPageItemRegister() = default;               //  0 0x140f177f0 (??_G 0x140f17b50; implicit: no vptr store)
    virtual void vfunc_1();                                         //  1 0x140f11910 "initData"
    virtual void vfunc_2();                                         //  2 0x140f12090
    virtual void vfunc_3();                                         //  3 0x140f12120
    virtual int vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 4 0x140f12170
    virtual void vfunc_5();                                         //  5 0x140f12c60
    virtual MS2Ptr<CBlackMarketProduct> vfunc_6(unsigned __int64 nId);   //  6 0x140f12c10 product of the own list

    void FUN_140f12d40(MS2Ptr<CBlackMarketProduct> spEntry);        // a product was registered (the callee destroys the entry)
    void FUN_140f13030(MS2Ptr<CBlackMarketProduct> spEntry, int nReason);   // a product was removed (0: by the owner)
    void FUN_140f132c0(CBlackMarketMan::ProductMap& own);           // "buildOwnerItemList"
    void FUN_140f133b0(int nAction);                                // reply received
    void FUN_140f13420(NotifyContext::BindData* pSlot, CItem& item);   // an item was dropped on the register slot
    void FUN_140f13610(const Scaleform::GFx::FunctionHandler::Params& params);   // "changeTotalPrice"
    void FUN_140f137a0(int nItemId, int nRank, unsigned __int64 nPrice);   // the reference price arrived
    bool FUN_140f13950(int nResult, const CMsgBoxData& box);        // stop-sale confirmation
    bool FUN_140f139e0(int nResult, const CMsgBoxData& box);        // fee notice closed: register
    bool FUN_140f13a10(int nResult, const CMsgBoxData& box);        // register confirmation
    void FUN_140f13ce0(MS2Ptr<CItem> spItem);                       // put an item on the slot: ask its reference price
    void FUN_140f13d80();                                           // send the pending register request
    void FUN_140f13e70(unsigned __int64 nUid, __int64 nPrice, int nCount);   // "OnClickRegister"
    int FUN_140f14650(ASObj& obj, CItem& item, BlackMarketRegisterItem& reg);   // the slot data of an item
    CStringW FUN_140f14900(int nRank);                              // the fee notice

    MS2_LAYOUT_FRIEND;
    bool m_bFilled;                                                 // +0x60
    BlackMarketRegisterItem m_item;                                 // +0x68
    BlackMarketRequest m_request;                                   // +0x80
    MS2Ptr<ASTextField> m_spCounter;                                // +0xa0 "m_counter"
    MS2Ptr<ASTextField> m_spTotalPrice;                             // +0xb0 "m_totalprice"
    MS2Ptr<ASTextField> m_spTotalPriceNumber;                       // +0xc0 "m_totalpriceNumberString"
};
MS2_CHECK_SIZE(BlackMarketPageItemRegister, 0xd0);
MS2_CHECK_OFFSET(BlackMarketPageItemRegister, m_item, 0x68);
MS2_CHECK_OFFSET(BlackMarketPageItemRegister, m_request, 0x80);
MS2_CHECK_OFFSET(BlackMarketPageItemRegister, m_spCounter, 0xa0);

class BlackMarketPageMesoSearch : public BlackMarketPage
{
public:
    virtual ~BlackMarketPageMesoSearch();
    virtual void vfunc_3();
    virtual int vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    explicit BlackMarketPageMesoSearch(const CString& strName);     // 0x140f18620
    char m_pad_60[0xc8 - 0x60];
};
MS2_CHECK_SIZE(BlackMarketPageMesoSearch, 0xc8);

class BlackMarketPageMesoRegister : public BlackMarketPage
{
public:
    virtual ~BlackMarketPageMesoRegister();
    virtual void vfunc_3();
    virtual int vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    BlackMarketPageMesoRegister();                                  // 0x140f1add0
    char m_pad_60[0xe0 - 0x60];
};
MS2_CHECK_SIZE(BlackMarketPageMesoRegister, 0xe0);
