// uiweddinghallreservationpage.h - UIWeddingHallReservationPage (RTTI .?AVUIWeddingHallReservationPage@@): the base of
// the pages of the wedding hall reservation dialog (cancel, change, confirm, schedule, select). A page is a CPtred that
// owns the AS object of its page movie clip and points back at the dialog. Recovered from MapleStory2.exe KMS2_DEV x64
// (2022-04-13); units `?\uiweddinghallreservationpage.cpp` (0x140fe2150-0x140fe2880) and the page-specific
// `?\uiweddinghallreservationpage{change,confirm,schedule,select}.cpp`. Header name assumed; member names invented
// from use, vfunc_N are vftable slots.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "uidialog.h"

// The fields of the player's wedding hall ticket that the pages read (the real class is WeddingHallTicket, weddingproxy.cpp).
struct Unk_WeddingTicketView
{
    __int64 m_unk00[4];             // +0x00
    int m_nHallId;                  // +0x20
    int m_nSlot;                    // +0x24
    bool m_bPrivate;                // +0x28
    unsigned char m_pad29[7];       // +0x29
    __int64 m_unk30;                // +0x30
    __int64 m_nOwnerId;             // +0x38
    __int64 m_nTime;                // +0x40
};

class UIWeddingHallReservationPage : public CPtred
{
public:
    UIWeddingHallReservationPage(UIDialog* pDialog);                // 0x140fe2150
    virtual ~UIWeddingHallReservationPage();                        // 0x140fe21c0 (deleting dtor 0x140fe2490)

    virtual bool vfunc_1();                                         // 1 0x140fe2200 binds the page movie clip ("m_currentPage")
    virtual void vfunc_2();                                         // 2 0x140fe2360 drops the page AS object
    virtual void vfunc_3(__int64 a1, __int64 a2, __int64 a3);                                      // 3 0x140fe2390
    virtual bool vfunc_4(__int64 a1, __int64 a2, int a3);                                         // 4 0x140fe23b0 false
    virtual void vfunc_5();                                         // 5 0x140fe23d0 confirm button
    virtual void vfunc_6();                                         // 6 0x140fe23e0 cancel button
    virtual void vfunc_7();                                         // 7 0x140fe23f0
    virtual CString vfunc_8() = 0;                                  // 8 page name
    virtual CStringW vfunc_9() = 0;                                 // 9 title text
    virtual CStringW vfunc_10(bool bStart) = 0;                     // 10 button text
    virtual bool vfunc_11(bool a1);                                        // 11 0x140fe2400 true
    virtual bool vfunc_12();                                        // 12 0x140fe2420 true

    MS2Ptr<AScript> GetScript() const;                              // 0x140fe2430
    UIDialog* GetDialog() const;                                    // 0x140fe2480

    MS2Ptr<AScript> m_pScript;                                      // +0x18
    UIDialog* m_pDialog;                                            // +0x28
};
MS2_CHECK_SIZE(UIWeddingHallReservationPage, 0x30);
