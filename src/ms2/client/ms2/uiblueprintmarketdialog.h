// uiblueprintmarketdialog.h - UIBlueprintMarketDialog (RTTI .?AVUIBlueprintMarketDialog@@, 0x1e8 bytes, swf
// "BlueprintMarketDialog", UI type 0x4f7f): the market of UGC house blueprints. A paged search over the merat market's
// blueprint list (CMeratMarketMan +0x150), a search box with a sort menu, buying a blueprint through the market bill and
// a model house preview (UIHomeInfoDialog + packet 0x37/0x44).
// Bases: UIDialog (+0x0; IMessageListener at +0x18) and UIUGCEventListener (+0x178). Ctor 0x140bb9cf0, dtor 0x140bb9e30
// (??_G 0x140bc08c0). Owning unit: client\ms2\uiblueprintmarketdialog.cpp (path seen in the exe's SwfLoadError text).
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); member and method names are invented from use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/uiugceventlistener.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cmeratmarketschcond.h"
#include "ms2/client/ms2/tmeratmarketbilldataparam.h"
#include "ms2/commonfiles/meratproductkey.h"
#include "ms2/placeholder/intervaltimer.h"

class ASButton;
class ASData;
class ASDropdownMenu;
class ASMeratMarketProduct;
class ASTextInput;
class CMeratMarketProduct;
class NotifyObject;
class Unk_MmViewScope;

typedef ATL::CAtlArray<MS2Ptr<CMeratMarketProduct> > Unk_MeratProductArray;

// A pending "open at this product" request (+0x1d8): the search text and the product's UGC serial.
struct Unk_BpSavedQuery
{
    Unk_BpSavedQuery() : m_nId(0) {}                                // 0x140bbfae0
    ~Unk_BpSavedQuery() {}                                          // 0x140bbffc0
    void Clear() { m_nId = 0; m_strText.Empty(); }                  // 0x140bc0960
    bool IsEmpty() { return m_nId == 0; }                           // 0x140bc0a40

    CStringW m_strText;                                             // +0x0
    __int64 m_nId;                                                  // +0x8
};
MS2_CHECK_SIZE(Unk_BpSavedQuery, 0x10);

class UIBlueprintMarketDialog : public UIDialog, public UIUGCEventListener
{
public:
    UIBlueprintMarketDialog();                                      // 0x140bb9cf0
    virtual ~UIBlueprintMarketDialog();                             //  0 0x140bb9e30 (??_G 0x140bc08c0)
    virtual CString vfunc_1();                                      //  1 0x140bb9f00 "BlueprintMarketDialog"
    virtual int vfunc_13();                                         // 13 0x140bbad70 Enter in the search box searches
    virtual void OnLoadComplete();                                  // 22 0x140bb9f50 bind the controls, send initData
    virtual void vfunc_26();                                        // 26 0x140bbab60 unbind and reset
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140bba870
    virtual void vfunc_43();                                        // 43 0x140bbae80 keep below the top bars
    virtual int vfunc_48();                                         // 48 0x140bc0a00 returns 0x4f7f
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140bbaf20 getTooltip (a product)
    virtual void vfunc_67();                                        // 67 0x140bbb130 Close
    virtual void vfunc_72();                                        // 72 0x140bbb190 send the pending search
    virtual bool vfunc_75();                                        // 75 0x140bbb150 feature 0xec
    virtual void vfunc_ugc_3(void* pCallBack, void* pstrPath);      // UIUGCEventListener 3 0x140bbb2c0 a product icon arrived

    void ShowSearchResult(int nPage, int nFirst, int nLast, int nTotal, bool bEndPage);   // 0x140bbb440
    void FUN_140bbbc70(MS2Ptr<CMeratMarketProduct> spProduct);      // 0x140bbbc70 a product changed (CMeratMarketMan)
    void ClearSearchInput();                                        // 0x140bbbcf0 a search was refused
    void SetSavedQuery(const __int64& nId, const CStringW& strText);   // 0x140bbbd70 open at a product (the merat dialog's link)
    bool FillRow(ASMeratMarketProduct& row, MS2Ptr<CMeratMarketProduct> spProduct, Unk_MmViewScope* pScope);   // 0x140bbbe00
    MS2Ptr<TMeratMarketBillDataParam> CreateBillParam(const CStringA& strMovie, int nType, int nSourceKind);   // 0x140bbc280
    void BuildPage(int nFirst, int nLast);                          // 0x140bbc510
    int FillPage(int nFirst, int nLast, ASArray& rows, Unk_MeratProductArray& list, Unk_MmViewScope* pScope);   // 0x140bbc620
    void Preview(const Unk_MeratProductKey& key);                        // 0x140bbc870 show the model house
    bool ChangeList(ASData& data, bool bReset);                     // 0x140bbcb20
    void ApplySearchData(MS2Ptr<CMeratMarketSchCond> spCond, AScript& data);   // 0x140bbcc60
    void SearchText(MS2Ptr<CMeratMarketSchCond> spCond, CStringW& strText);    // 0x140bbcef0
    void UpdateItem(MS2Ptr<CMeratMarketProduct> spProduct);         // 0x140bbd360
    void OnChangePageRequest(ASData& data);                         // 0x140bbd4b0
    void OnChangePage(ASData& data);                                // 0x140bbd580
    void OnSearch(const Scaleform::GFx::FunctionHandler::Params& params);         // 0x140bbd5e0
    void OnClickCalculate(const Scaleform::GFx::FunctionHandler::Params& params); // 0x140bbd6e0
    void OnClickModelHouse(const Scaleform::GFx::FunctionHandler::Params& params);    // 0x140bbd860
    void OnClickBuy(const CStringA& strMovie, ASData& data);        // 0x140bbd990
    MS2Ptr<CMeratMarketSchCond> GetSearchCond();                    // 0x140bbdc80 (created on first use)
    void OnBlindTarget(NotifyObject* pNotify);                      // 0x140bbdd50

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CMeratMarketSchCond> m_spCond;                           // +0x180 the current search
    int m_nFlags;                                                   // +0x190 bit 1: a search request is pending
    MS2Ptr<ASButton> m_search;                                      // +0x198
    MS2Ptr<ASTextInput> m_inputSearch;                              // +0x1a8
    MS2Ptr<ASDropdownMenu> m_sort;                                  // +0x1b8
    __int64 m_nPreviewId;                                           // +0x1c8 the blueprint of the last preview
    Unk_IntervalTimer m_previewTimer;                               // +0x1d0 the preview cool-down
    Unk_BpSavedQuery m_saved;                                       // +0x1d8
};
MS2_CHECK_SIZE(UIBlueprintMarketDialog, 0x1e8);
MS2_CHECK_OFFSET(UIBlueprintMarketDialog, m_spCond, 0x180);
MS2_CHECK_OFFSET(UIBlueprintMarketDialog, m_nFlags, 0x190);
MS2_CHECK_OFFSET(UIBlueprintMarketDialog, m_search, 0x198);
MS2_CHECK_OFFSET(UIBlueprintMarketDialog, m_inputSearch, 0x1a8);
MS2_CHECK_OFFSET(UIBlueprintMarketDialog, m_sort, 0x1b8);
MS2_CHECK_OFFSET(UIBlueprintMarketDialog, m_nPreviewId, 0x1c8);
MS2_CHECK_OFFSET(UIBlueprintMarketDialog, m_previewTimer, 0x1d0);
MS2_CHECK_OFFSET(UIBlueprintMarketDialog, m_saved, 0x1d8);
