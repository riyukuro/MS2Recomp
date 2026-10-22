// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingHallReservationPageChange: see uiweddinghallreservationpage.h.
// MS2-UNIT: ?\uiweddinghallreservationpagechange.cpp
// MS2-RANGE: 0x140fe2880-0x140fe2d40 .text$mn
// MS2-PIN: ??_GUIWeddingHallReservationPageChange@@UEAAPEAXI@Z 0x140fe2ce0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddinghallreservationpagechange.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiweddinghallreservationpage.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// ---- exe callees ----
void* FUN_1409eed90();                                                      // the singleton of the own character
Unk_WeddingTicketView* FUN_141b87160(void* pCharacter);                     // the character's current wedding hall ticket
void FUN_140fdac50(int nHallId, int nSlot, __int64 nTime, unsigned char bPrivate, ASObj* pData);   // fills the page data object
bool FUN_140900f90(int nId, Unk_WeddingTicketView* pTicket);                // can the ticket be changed to this hall
int FUN_1409008e0(void* pManager, Unk_WeddingTicketView* pTicket, __int64 nCharacterId);
void* FUN_140d295d0(void* pCharacter);
void FUN_141b87760(void* pCharacter, int n);
void FUN_1412751f0(const CStringW& strText, int a, int b);                  // notice
void FUN_140fdc030(UIDialog* pDialog);
int FUN_140fe2d20(UIDialog* pDialog);
void* FUN_140967100();
void FUN_141b1feb0(void* pSingleton);
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
extern __int64 DAT_143ab2828;                                               // the own character id

// the reservation dialog's selected hall id lives right behind the UIDialog base
struct Unk_ReservationDialogView : UIDialog
{
    int m_nSelectedHallId;                                                  // +0x178
};

class UIWeddingHallReservationPageChange : public UIWeddingHallReservationPage
{
public:
    UIWeddingHallReservationPageChange(UIDialog* pDialog);          // 0x140fe2880
    virtual ~UIWeddingHallReservationPageChange();                  // 0x140fe28c0 (deleting dtor 0x140fe2ce0)

    virtual bool vfunc_1();                                         // 0x140fe28f0
    virtual void vfunc_2();                                         // 0x140fe29d0
    virtual void vfunc_5();                                         // 0x140fe29f0
    virtual void vfunc_6();                                         // 0x140fe2b30
    virtual CString vfunc_8();                                      // 0x140fe2b70
    virtual CStringW vfunc_9();                                     // 0x140fe2bc0
    virtual CStringW vfunc_10(bool bStart);                         // 0x140fe2c30
};
MS2_CHECK_SIZE(UIWeddingHallReservationPageChange, 0x30);

// @0x140fe2880
UIWeddingHallReservationPageChange::UIWeddingHallReservationPageChange(UIDialog* pDialog) : UIWeddingHallReservationPage(pDialog)
{
}

// @0x140fe28c0
UIWeddingHallReservationPageChange::~UIWeddingHallReservationPageChange()
{
}

// @0x140fe28f0
bool UIWeddingHallReservationPageChange::vfunc_1()
{
    if (!UIWeddingHallReservationPage::vfunc_1())
        return false;
    Unk_WeddingTicketView* pTicket = FUN_141b87160(FUN_1409eed90());
    ASObj kData(2);
    FUN_140fdac50(pTicket->m_nHallId, pTicket->m_nSlot, pTicket->m_nTime, pTicket->m_bPrivate, &kData);
    m_pScript->Invoke("setData", kData);
    return true;
}

// @0x140fe29d0
void UIWeddingHallReservationPageChange::vfunc_2()
{
    UIWeddingHallReservationPage::vfunc_2();
}

// MS2-FUNCTIONAL: epilogue/branch layout of the early returns is 3 bytes longer
// @0x140fe29f0
void UIWeddingHallReservationPageChange::vfunc_5()
{
    Unk_WeddingTicketView* pTicket = FUN_141b87160(FUN_1409eed90());
    int nId = FUN_140fe2d20(m_pDialog);
    if (!FUN_140900f90(nId, pTicket))
    {
        CStringW strKey(L"s_wedding_hall_reservation_paclkage_err");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
        return;
    }
    int n = FUN_1409008e0(FUN_140d295d0(FUN_1409eed90()), FUN_141b87160(FUN_1409eed90()), DAT_143ab2828);
    if (n == 0)
    {
        FUN_140fdc030(m_pDialog);
        return;
    }
    FUN_141b87760(FUN_1409eed90(), n);
    m_pDialog->vfunc_67();
    FUN_141b1feb0(FUN_140967100());
}

// @0x140fe2b30
void UIWeddingHallReservationPageChange::vfunc_6()
{
    m_pDialog->vfunc_67();
    FUN_141b1feb0(FUN_140967100());
}

// @0x140fe2b70
CString UIWeddingHallReservationPageChange::vfunc_8()
{
    return CString("PageChange");
}

// @0x140fe2bc0
CStringW UIWeddingHallReservationPageChange::vfunc_9()
{
    CStringW strKey(L"s_wedding_reservation_change_page");
    return GetStringCommonByKey(strKey);
}

// MS2-FUNCTIONAL: one byte differs in else-less/else branch layout
// @0x140fe2c30
CStringW UIWeddingHallReservationPageChange::vfunc_10(bool bStart)
{
    if (bStart == 0)
    {
        CStringW strEnd(L"s_wedding_reservation_change_end");
        return GetStringCommonByKey(strEnd);
    }
    CStringW strStart(L"s_wedding_reservation_change_start");
    return GetStringCommonByKey(strStart);
}

// @0x140fe2d20
int FUN_140fe2d20(UIDialog* pDialog)
{
    return static_cast<Unk_ReservationDialogView*>(pDialog)->m_nSelectedHallId;
}
