// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingHallReservationPageConfirm: see uiweddinghallreservationpage.h.
// MS2-UNIT: ?\uiweddinghallreservationpageconfirm.cpp
// MS2-RANGE: 0x140fe2d40-0x140fe33a0 .text$mn
// MS2-RANGE: 0x1400e3170-0x1400e33a0 .text$di
// MS2-PIN: ??_GUIWeddingHallReservationPageConfirm@@UEAAPEAXI@Z 0x140fe3360
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddinghallreservationpageconfirm.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiweddinghallreservationpage.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// ---- header statics (.text$di): the market sort names, condition keys, the condition table, the sort names again ----
// @0x1400e3170
static CString s_sort7a[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };
// @0x1400e3230
static CString s_skill("skill");
// @0x1400e3260
static CString s_stun("stun");
// @0x1400e3290
static Unk_1402a9d70 s_table(17, 0.75f, 0.25f, 2.25f, 10);
// @0x1400e32e0
static CString s_sort7b[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

// ---- exe callees ----
void* FUN_1409eed90();                                                      // the singleton of the own character
class WeddingManager   // C3: member view for the former free stand-ins
{
public:
    class WeddingHallTicket const& GetTicket();
};
void FUN_140fdac50(int nHallId, int nSlot, __int64 nTime, unsigned char bPrivate, ASObj* pData);
void FUN_1412751f0(const CStringW& strText, int a, int b);                  // notice
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
int FUN_140fe2d20(UIDialog* pDialog);                                       // the selected hall id (uiweddinghallreservationpagechange.cpp)
class UIWeddingHallReservationDialog   // C3: member view for the former free stand-ins
{
public:
    void FUN_140fdbf70();
    void FUN_140fdc180();
    void FUN_140fdc970();
    int GetHall();
    int GetMode();
    unsigned char GetNight();
    __int64 GetTime();
};
void* FUN_1409023c0();                                                      // the hall price manager
class WeddingTable   // C3: member view for the former free stand-ins
{
public:
    __int64 FUN_140909220(int, int);
};
CStringW FUN_1409404f0(__int64 n);                                          // a number as text
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);

class UIWeddingHallReservationPageConfirm : public UIWeddingHallReservationPage
{
public:
    UIWeddingHallReservationPageConfirm(UIDialog* pDialog);         // 0x140fe2d40
    virtual ~UIWeddingHallReservationPageConfirm();                 // 0x140fe2d80 (deleting dtor 0x140fe3360)

    virtual bool vfunc_1();                                         // 0x140fe2db0
    virtual void vfunc_2();                                         // 0x140fe2ff0
    virtual void vfunc_5();                                         // 0x140fe3010
    virtual void vfunc_6();                                         // 0x140fe3040
    virtual CString vfunc_8();                                      // 0x140fe31a0
    virtual CStringW vfunc_9();                                     // 0x140fe31f0
    virtual CStringW vfunc_10(bool bStart);                         // 0x140fe3260
    virtual bool vfunc_12();                                        // 0x140fe3320
};
MS2_CHECK_SIZE(UIWeddingHallReservationPageConfirm, 0x30);

// @0x140fe2d40
UIWeddingHallReservationPageConfirm::UIWeddingHallReservationPageConfirm(UIDialog* pDialog) : UIWeddingHallReservationPage(pDialog)
{
}

// @0x140fe2d80
UIWeddingHallReservationPageConfirm::~UIWeddingHallReservationPageConfirm()
{
}

// @0x140fe2db0
bool UIWeddingHallReservationPageConfirm::vfunc_1()
{
    if (!UIWeddingHallReservationPage::vfunc_1())
        return false;
    ASObj kData(2);
    FUN_140fdac50(FUN_140fe2d20(m_pDialog), ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetHall(), ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetTime(), ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetNight(), &kData);
    if (((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetMode() == 1)
    {
        Unk_WeddingTicketView* pTicket = ((struct Unk_WeddingTicketView*)&((class WeddingManager*)(void*)(FUN_1409eed90()))->GetTicket());
        __int64 nOld = ((class WeddingTable*)(void*)(FUN_1409023c0()))->FUN_140909220(pTicket->m_nHallId, pTicket->m_nSlot);
        __int64 nNew = ((class WeddingTable*)(void*)(FUN_1409023c0()))->FUN_140909220(FUN_140fe2d20(m_pDialog), ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetHall());
        kData.FUN_1407cbb20("price", FUN_14052bd00(0x987, FUN_1409404f0(nNew - nOld)));
    }
    m_pScript->Invoke("setData", kData);
    return true;
}

// @0x140fe2ff0
void UIWeddingHallReservationPageConfirm::vfunc_2()
{
    UIWeddingHallReservationPage::vfunc_2();
}

// @0x140fe3010
void UIWeddingHallReservationPageConfirm::vfunc_5()
{
    ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->FUN_140fdbf70();
}

// @0x140fe3040
void UIWeddingHallReservationPageConfirm::vfunc_6()
{
    if (((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetTime() == 0)
    {
        CStringW strKey(L"s_wedding_hall_reservation_select_time");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
    }
    else if (((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetHall() == 0)
    {
        CStringW strKey(L"s_wedding_hall_reservation_select_hall");
        FUN_1412751f0(GetStringCommonByKey(strKey), 1, 1);
    }
    else
    {
        switch (((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetMode())
        {
        case 0:
            ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->FUN_140fdc180();
            break;
        case 1:
            ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->FUN_140fdc970();
            break;
        }
    }
}

// @0x140fe31a0
CString UIWeddingHallReservationPageConfirm::vfunc_8()
{
    return CString("PageConfirm");
}

// @0x140fe31f0
CStringW UIWeddingHallReservationPageConfirm::vfunc_9()
{
    CStringW strKey(L"s_wedding_reservation_confirm_page");
    return GetStringCommonByKey(strKey);
}

// @0x140fe3260
CStringW UIWeddingHallReservationPageConfirm::vfunc_10(bool bStart)
{
    if (bStart != 0)
    {
        CStringW strStart(L"s_wedding_reservation_prev");
        return GetStringCommonByKey(strStart);
    }
    CStringW strEnd(L"s_wedding_reservation_reservation");
    return GetStringCommonByKey(strEnd);
}

// @0x140fe3320
bool UIWeddingHallReservationPageConfirm::vfunc_12()
{
    if (((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetHall() == 0)
        return false;
    if (((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetTime() == 0)
        return false;
    return true;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142caae90-0x142caaf50 .text$yd
