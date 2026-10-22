// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingHallReservationPage and its first page class,
// UIWeddingHallReservationPageCancel: see uiweddinghallreservationpage.h.
// MS2-UNIT: ?\uiweddinghallreservationpage.cpp
// MS2-RANGE: 0x140fe2150-0x140fe2880 .text$mn
// MS2-PIN: ??_GUIWeddingHallReservationPage@@UEAAPEAXI@Z 0x140fe2490
// MS2-PIN: ??_GUIWeddingHallReservationPageCancel@@UEAAPEAXI@Z 0x140fe2840
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddinghallreservationpage.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiweddinghallreservationpage.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// ---- exe callees ----
void* FUN_1409eed90();                                                      // the singleton of the own character
Unk_WeddingTicketView* FUN_141b87160(void* pCharacter);                     // the character's current wedding hall ticket
void FUN_140fdac50(int nHallId, int nSlot, __int64 nTime, unsigned char bPrivate, ASObj* pData);   // fills the page data object
bool FUN_140a467d0(const MS2Ptr<AScript>& kScript);                         // has the AS object been released
unsigned char FUN_1409b0350(Scaleform::GFx::Value* pValue);                 // Value::IsNull
MS2Ptr<AScript> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);
void FUN_140fdc9f0(UIDialog* pDialog);                                      // reservation dialog: go back to the list
void* FUN_140967100();
void FUN_141b1feb0(void* pSingleton);
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text

// @0x140fe2150
UIWeddingHallReservationPage::UIWeddingHallReservationPage(UIDialog* pDialog) : m_pScript(0)
{
    m_pDialog = pDialog;
}

// @0x140fe21c0
UIWeddingHallReservationPage::~UIWeddingHallReservationPage()
{
}

// MS2-FUNCTIONAL: EH state layout and bool branch codegen differ
// @0x140fe2200
bool UIWeddingHallReservationPage::vfunc_1()
{
    if (FUN_140a467d0(m_pDialog->FUN_1422dba00()))
        return false;
    Scaleform::GFx::Value kPage = m_pDialog->FUN_1422dba00()->FUN_1422baa20("m_currentPage");
    if (FUN_1409b0350(&kPage) == 0)
    {
        m_pScript = FUN_140acca70(m_pDialog->FUN_1422db730(), kPage);
        return true;
    }
    return false;
}

// @0x140fe2360
void UIWeddingHallReservationPage::vfunc_2()
{
    m_pScript = 0;
}

// @0x140fe2390
void UIWeddingHallReservationPage::vfunc_3(__int64 a1, __int64 a2, __int64 a3)
{
}

// @0x140fe23b0
bool UIWeddingHallReservationPage::vfunc_4(__int64 a1, __int64 a2, int a3)
{
    return false;
}

// @0x140fe23d0
void UIWeddingHallReservationPage::vfunc_5()
{
}

// @0x140fe23e0
void UIWeddingHallReservationPage::vfunc_6()
{
}

// @0x140fe23f0
void UIWeddingHallReservationPage::vfunc_7()
{
}

// @0x140fe2400
bool UIWeddingHallReservationPage::vfunc_11(bool a1)
{
    return true;
}

// @0x140fe2420
bool UIWeddingHallReservationPage::vfunc_12()
{
    return true;
}

// @0x140fe2430
MS2Ptr<AScript> UIWeddingHallReservationPage::GetScript() const
{
    return m_pScript;
}

// @0x140fe2480
UIDialog* UIWeddingHallReservationPage::GetDialog() const
{
    return m_pDialog;
}

// ---- the cancel page ----
class UIWeddingHallReservationPageCancel : public UIWeddingHallReservationPage
{
public:
    UIWeddingHallReservationPageCancel(UIDialog* pDialog);          // 0x140fe24d0
    virtual ~UIWeddingHallReservationPageCancel();                  // 0x140fe2510 (deleting dtor 0x140fe2840)

    virtual bool vfunc_1();                                         // 0x140fe2540 sends the ticket data to the movie
    virtual void vfunc_2();                                         // 0x140fe2620
    virtual void vfunc_5();                                         // 0x140fe2640
    virtual void vfunc_6();                                         // 0x140fe2690
    virtual CString vfunc_8();                                      // 0x140fe26d0
    virtual CStringW vfunc_9();                                     // 0x140fe2720
    virtual CStringW vfunc_10(bool bStart);                         // 0x140fe2790
};
MS2_CHECK_SIZE(UIWeddingHallReservationPageCancel, 0x30);

// @0x140fe24d0
UIWeddingHallReservationPageCancel::UIWeddingHallReservationPageCancel(UIDialog* pDialog) : UIWeddingHallReservationPage(pDialog)
{
}

// @0x140fe2510
UIWeddingHallReservationPageCancel::~UIWeddingHallReservationPageCancel()
{
}

// @0x140fe2540
bool UIWeddingHallReservationPageCancel::vfunc_1()
{
    if (!UIWeddingHallReservationPage::vfunc_1())
        return false;
    Unk_WeddingTicketView* pTicket = FUN_141b87160(FUN_1409eed90());
    ASObj kData(2);
    FUN_140fdac50(pTicket->m_nHallId, pTicket->m_nSlot, pTicket->m_nTime, pTicket->m_bPrivate, &kData);
    m_pScript->Invoke("setData", kData);
    return true;
}

// @0x140fe2620
void UIWeddingHallReservationPageCancel::vfunc_2()
{
    UIWeddingHallReservationPage::vfunc_2();
}

// @0x140fe2640
void UIWeddingHallReservationPageCancel::vfunc_5()
{
    FUN_140fdc9f0(m_pDialog);
    m_pDialog->vfunc_67();
    FUN_141b1feb0(FUN_140967100());
}

// @0x140fe2690
void UIWeddingHallReservationPageCancel::vfunc_6()
{
    m_pDialog->vfunc_67();
    FUN_141b1feb0(FUN_140967100());
}

// @0x140fe26d0
CString UIWeddingHallReservationPageCancel::vfunc_8()
{
    return CString("PageCancel");
}

// @0x140fe2720
CStringW UIWeddingHallReservationPageCancel::vfunc_9()
{
    CStringW strKey(L"s_wedding_reservation_cancel_page");
    return GetStringCommonByKey(strKey);
}

// MS2-FUNCTIONAL: one byte differs in else-less/else branch layout
// @0x140fe2790
CStringW UIWeddingHallReservationPageCancel::vfunc_10(bool bStart)
{
    if (bStart == 0)
    {
        CStringW strEnd(L"s_wedding_reservation_cancel_end");
        return GetStringCommonByKey(strEnd);
    }
    CStringW strStart(L"s_wedding_reservation_cancel");
    return GetStringCommonByKey(strStart);
}
