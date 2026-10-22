// uipartysearchdialog.h - UIPartySearchDialog (RTTI .?AVUIPartySearchDialog@@, 0x190 bytes, UI id 0x4eda, swf
// "PartySearchDialog"): the party search window. It lists the party recruitments received from the server
// (CPartyManager results), searches by dungeon / sort / text and shows the member-search registration state.
// Owning unit: ?\uipartysearchdialog.cpp (0x140f8c480-0x140f90780). Header name assumed from the unit path (w52).
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/cmatchpartyrecruit.h"
#include <atlcoll.h>

class ASObj;
class ASArray;
class Unk_PsdInput;

class UIPartySearchDialog : public UIDialog
{
public:
    UIPartySearchDialog();                                      // 0x140f8c480
    virtual ~UIPartySearchDialog();                             //  0 0x140f8c530 (??_G 0x140f8fda0)
    virtual CString GetTypeName();                                  //  1 0x140f8c580 "PartySearchDialog"
    virtual int vfunc_13();                                     // 13 0x140f8ca80 enter key: "onProcessKey"
    virtual void vfunc_15();                                    // 15 0x140f8c9c0 re-send the pending search (throttled)
    virtual void OnLoadComplete();                              // 22 0x140f8c740 bind the controls, send the sort lists
    virtual void vfunc_26();                                    // 26 0x140f8c970 unbind
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140f8cdf0
    virtual int vfunc_48() { return 0x4eda; }                   // 48 0x140f900f0
    virtual int vfunc_65();                                     // 65 0x140f8c5d0 open: top most layer
    virtual int vfunc_73();                                     // 73 0x140f8c650 can open (flag 0x1b blocks)
    virtual void vfunc_79(void* pEvent);                        // 79 0x140f8c6b0 key event: F5 refresh
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140f8cc10 join answers

    MS2Ptr<Unk_PsdInput> FUN_140e35bd0(const CString& strName);  // find a child control by name (exe member)
    void FUN_140f8dde0();                                     // clear the search text and the condition text
    void FUN_140f8ded0();                                       // m_178 = 0
    int FUN_140f8def0(int nStart, int nCount, ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit>>& list);   // send the list page + notice
    int FUN_140f8e220(int nStart, int nCount, ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit>>& list);  // send a list page
    int FUN_140f8e340(int nStart, int nCount);                  // page of the manager's results
    int FUN_140f8e3a0();                                        // the last search is older than 500 ms
    int FUN_140f8e3f0(int nPage);                               // queue a search (page = nPage)
    int FUN_140f8e480(const CStringW& strText);                 // validate the search text; 1 = stored
    void FUN_140f8e610();                                       // "forceClickRefresh"
    void FUN_140f8e670();                                       // make sure the condition exists (page 1)
    void FUN_140f8e790(float x, float y, unsigned __int64 nAccount, __int64 nChar, CStringW* pName, int nFlag);   // right click menu
    void OnClickRegisterMemeberSearch();                                       // register the member search
    void OnClickRegisterMemeberSearchModify();                                       // modify the member search registration
    void FUN_140f8ed40(ATL::CAtlArray<MS2Ptr<CMatchPartyRecruit>>& list, int nStart);   // show a received page
    void FUN_140f8edb0();                                       // refresh the member search state
    void FUN_140f8ee00(CMatchPartyRecruit* pRecruit);           // refresh and force the refresh click
    void FUN_140f8ee50(CMatchPartyRecruit* pRecruit);           // "updateDataTo"

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                                  // +0x178 a search is queued
    unsigned int m_17c;                                         // +0x17c tick of the last search
    MS2Ptr<CMatchPartyRecruitSchCond> m_180;                    // +0x180 the search condition
};
MS2_CHECK_SIZE(UIPartySearchDialog, 0x190);
MS2_CHECK_OFFSET(UIPartySearchDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIPartySearchDialog, m_180, 0x180);
