// uiweddinghallreservationdialog.h - UIWeddingHallReservationDialog (RTTI .?AVUIWeddingHallReservationDialog@@, 0x1d0
// bytes, UIDialog, UI id 0x4f8d, swf "WeddingHallReservationDialog"): the wedding hall reservation wizard. A tab strip
// ("m_tab") walks the pages (select, schedule, confirm; change; cancel - see uiweddinghallreservationpage.h) chosen by the
// mode; the pages fill in the package / hall / time / night choice, and the confirm page opens the bill dialog whose
// answer sends the reservation. Owning unit: ?\uiweddinghallreservationdialog.cpp (dir client\ms2). Header name assumed
// from the unit path; member and method names are invented from use.
#pragma once
#include <afx.h>
#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/imessagelistener.h"
#include "uiweddinghallreservationpage.h"

class UIWeddingHallReservationDialog : public UIDialog
{
public:
    typedef MS2Ptr<UIWeddingHallReservationPage> PagePtr;
    typedef std::map<CString, PagePtr> PageMap;

    UIWeddingHallReservationDialog();                           // 0x140fdb090
    virtual ~UIWeddingHallReservationDialog();                  //  0 0x140fdb460 (??_G 0x140fe0530)
    virtual CString vfunc_1();                                  //  1 0x140fdb4f0 "WeddingHallReservationDialog"
    virtual void OnLoadComplete();                              // 22 0x140fdb620 the tabs of the mode
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140fdb990 onAddPage / onRemovePage / ...
    virtual void vfunc_43();                                    // 43 0x140fdb860 placed beside the talk cinematic
    virtual int vfunc_48() { return 0x4f8d; }                   // 48 0x140fe0570
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x140fdbe20 the bill answer
    virtual int vfunc_65();                                     // 65 0x140fdb540
    virtual void vfunc_67();                                    // 67 0x140fdb5f0 also ends the npc talk

    void FUN_140fdbf50(int nPackage);                           // set the package
    void FUN_140fdbf70();                                       // previous tab
    void FUN_140fdc030();                                       // next tab
    void FUN_140fdc110(int nHall);                              // set the hall
    void FUN_140fdc130(__int64 nTime);                          // set the time
    void FUN_140fdc160(unsigned char bNight);                   // set the night flag
    void FUN_140fdc180();                                       // open the bill of the reservation
    void FUN_140fdc970();                                       // send the reservation change
    void FUN_140fdc9f0();                                       // send the reservation cancel
    int FUN_140fdca20();                                        // the hall
    __int64 FUN_140fdca40();                                    // the time
    unsigned char FUN_140fdca60();                              // the night flag
    int FUN_140fdca80();                                        // the mode (0 reserve, 1 change, 2 cancel)
    void FUN_140fdcaa0(const CString& strMode);                 // set the mode by name
    __int64 FUN_140fdcb30();                                    // the price of the hall
    void FUN_140fdcc30(PagePtr spPage);                         // register a page under its name
    void FUN_140fdccd0(const std::vector<CString>& names);      // fill the tab strip
    void FUN_140fdcfc0();                                       // the left / right button labels of the tab
    void FUN_140fdd2d0();                                       // "setTabEnable" of every tab
    PagePtr FUN_140fdd3f0(const CString& strName);              // the page of a name (null: none)

private:
    MS2_LAYOUT_FRIEND;
    int m_nPackage;                                             // +0x178 the wedding package id
    int m_nTab;                                                 // +0x17c the selected tab
    std::vector<PagePtr> m_tabs;                                // +0x180 the pages of the tabs
    PagePtr m_spPage;                                           // +0x198 the shown page
    PageMap m_pages;                                            // +0x1a8 page name -> page
    int m_nHall;                                                // +0x1b8 the hall id
    __int64 m_nTime;                                            // +0x1c0 the reserved time
    unsigned char m_bNight;                                     // +0x1c8
    int m_nMode;                                                // +0x1cc 0 reserve, 1 change, 2 cancel
};
MS2_CHECK_SIZE(UIWeddingHallReservationDialog, 0x1d0);
MS2_CHECK_OFFSET(UIWeddingHallReservationDialog, m_nPackage, 0x178);
MS2_CHECK_OFFSET(UIWeddingHallReservationDialog, m_tabs, 0x180);
MS2_CHECK_OFFSET(UIWeddingHallReservationDialog, m_spPage, 0x198);
MS2_CHECK_OFFSET(UIWeddingHallReservationDialog, m_pages, 0x1a8);
MS2_CHECK_OFFSET(UIWeddingHallReservationDialog, m_nHall, 0x1b8);
MS2_CHECK_OFFSET(UIWeddingHallReservationDialog, m_nTime, 0x1c0);
MS2_CHECK_OFFSET(UIWeddingHallReservationDialog, m_bNight, 0x1c8);
MS2_CHECK_OFFSET(UIWeddingHallReservationDialog, m_nMode, 0x1cc);
