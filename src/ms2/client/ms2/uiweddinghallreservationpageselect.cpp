// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingHallReservationPageSelect: the hall select page of the
// wedding hall reservation dialog (see uiweddinghallreservationpage.h).
// MS2-UNIT: ?\uiweddinghallreservationpageselect.cpp
// MS2-RANGE: 0x140fe4650-0x140fe5780 .text$mn
// MS2-PIN: ??_GUIWeddingHallReservationPageSelect@@UEAAPEAXI@Z 0x140fe5600
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddinghallreservationpageselect.cpp"    // assumed
#define MS2_ASUICOMPONENT_SLOTS

#include "ms2/placeholder/ms2stdafx.h"

#include "uiweddinghallreservationpage.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/weddingpackage.h"     // WeddingRewardItem
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/placeholder/ascorelist.h"   // C3: ASCoreList::SetSelectedIndex
#include "ms2/placeholder/formatstringid.h"
#include "ms2/ms2format.h"
#include "ms2/commonfiles/os.h"

// ---- exe callees ----
class WeddingManager;
class WeddingManager   // C3: member view for the former free stand-ins
{
public:
    class WeddingHallTicket const& GetTicket();
};
bool FUN_140900f90(int, class WeddingHallTicket*);   // C3: was FUN_140900f90
int FUN_140fe2d20(UIDialog* pDialog);                                       // the selected hall id of the dialog
class UIWeddingHallReservationDialog   // C3: member view for the former free stand-ins
{
public:
    void SelectPreviousTab();
    void SelectNextTab();
    int GetHall();
    int GetMode();
    void SetHall(int);
    __int64 GetTime();
};
bool FUN_140900f30(__int64 nTime);                                          // the time is at night
CStringW GetStringCommonByKey(const CStringW& strKey);                             // string table text
void ShowSystemNotice(const CStringW& strText, int a, int b);                  // notice
CStringW FUN_1409404f0(__int64 n);                                          // number to text

class UIWeddingHallReservationPageSelect : public UIWeddingHallReservationPage
{
public:
    UIWeddingHallReservationPageSelect(UIDialog* pDialog);          // 0x140fe4650
    virtual ~UIWeddingHallReservationPageSelect();                  // 0x140fe46e0 (deleting dtor 0x140fe5600)

    virtual bool vfunc_1();                                         // 0x140fe4720 fills the hall list
    virtual void vfunc_2();                                         // 0x140fe4b60
    virtual bool vfunc_4(__int64 a1, __int64 a2, int a3);           // 0x140fe4b90 onSelectWeddingHall
    virtual void vfunc_5();                                         // 0x140fe4ca0
    virtual void vfunc_6();                                         // 0x140fe4cd0
    virtual void vfunc_7();                                         // 0x140fe4d70
    virtual CString vfunc_8();                                      // 0x140fe4d90
    virtual CStringW vfunc_9();                                     // 0x140fe4de0
    virtual CStringW vfunc_10(bool bStart);                         // 0x140fe4e50
    virtual bool vfunc_11(bool a1);                                 // 0x140fe4f10
    virtual bool vfunc_12();                                        // 0x140fe4f50

    ItemSlotBinder m_binder;                                        // +0x30
    int m_nSelectedSlot;                                            // +0x70
    int m_pad_74;
};
MS2_CHECK_SIZE(UIWeddingHallReservationPageSelect, 0x78);

__int64 FUN_140fe5520(UIWeddingHallReservationPageSelect* pPage, int nHallId, int nSlot);
void FUN_140fe4fb0(UIWeddingHallReservationPageSelect* pPage, int nSlotId);
MS2Ptr<WeddingRewardItem>* FUN_140fe55d0(void* pArray, __int64 nIndex);
int FUN_140fe5640(UIDialog* pDialog);
struct Unk_ReservationDialogView2 : UIDialog
{
    int m_nSelectedHallId;                                                  // +0x178
    int m_nSelectedPackage;                                                 // +0x17c
};

// @0x140fe4650
UIWeddingHallReservationPageSelect::UIWeddingHallReservationPageSelect(UIDialog* pDialog) : UIWeddingHallReservationPage(pDialog), m_binder(vfunc_8())
{
    m_nSelectedSlot = 0;
}

// @0x140fe46e0
UIWeddingHallReservationPageSelect::~UIWeddingHallReservationPageSelect()
{
}

// Fills the hall list; the selected slot wins over the first enabled row.
// @0x140fe4720
bool UIWeddingHallReservationPageSelect::vfunc_1()
{
    if (!UIWeddingHallReservationPage::vfunc_1())
        return false;
    MS2Ptr<WeddingPackage> hall = TSingleton<WeddingTable>::GetInstance()->FindPackage(FUN_140fe2d20(m_pDialog));
    if (hall == 0)
        return false;
    MS2Ptr<ASScrollingList> list = m_pScript->FUN_140bc7280<ASScrollingList>("m_list");
    if (list == 0)
        return false;
    int nPackageSlot = -1;
    if (((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetMode() == 1)
    {
        Unk_WeddingTicketView* pTicket = ((struct Unk_WeddingTicketView*)&TSingleton<WeddingManager>::GetInstance()->GetTicket());
        nPackageSlot = TSingleton<WeddingTable>::GetInstance()->GetHallGrade(pTicket->m_nHallId, pTicket->m_nSlot);
    }
    list->FUN_1422dd1d0();
    bool bFlag = false;
    __int64 nTime = ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetTime();
    if (nTime != 0)
        bFlag = FUN_140900f30(nTime);
    std::map<int, MS2Ptr<WeddingHallData> >::iterator it = hall->m_halls.begin();
    std::map<int, MS2Ptr<WeddingHallData> >::iterator end = hall->m_halls.end();
    int nIndex = 0;
    int nSelect = -1;
    for (; it != end; ++it)
    {
        MS2Ptr<WeddingHallData> slot(it->second);
        bool bEnabled = true;
        if (nPackageSlot != -1)
            bEnabled = slot->m_nGrade >= nPackageSlot;
        ASObj row(2);
        row.SetIntMember("id", slot->m_nId);
        row.SetWStringMember("label", TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, slot->GetFieldId(bFlag)));
        row.SetBoolMember("enabled", bEnabled);
        list->AddItem(row);
        if (m_nSelectedSlot != 0)
        {
            if (slot->m_nId == m_nSelectedSlot)
                nSelect = nIndex;
        }
        else if (bEnabled && nSelect == -1)
        {
            nSelect = nIndex;
        }
        nIndex = nIndex + 1;

    }
    if (nSelect != -1)
        list->SetSelectedIndex(nSelect);
    list->vfunc_24(true);
    return true;
}

// @0x140fe4b60
void UIWeddingHallReservationPageSelect::vfunc_2()
{
    UIWeddingHallReservationPage::vfunc_2();
    m_binder.FUN_140d43990();
}

// @0x140fe4b90
bool UIWeddingHallReservationPageSelect::vfunc_4(__int64 a1, __int64 a2, int a3)
{
    if (UIWeddingHallReservationPage::vfunc_4(a1, a2, a3) == 1)
        return true;
    if (_stricmp((const char*)a1, "onSelectWeddingHall") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny((const Scaleform::GFx::Value*)a2, a3))
        {
            m_nSelectedSlot = data.PopInt();
            FUN_140fe4fb0(this, m_nSelectedSlot);
            ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->SetHall(m_nSelectedSlot);
        }
        return true;
    }
    return false;
}

// @0x140fe4ca0
void UIWeddingHallReservationPageSelect::vfunc_5()
{
    ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->SelectPreviousTab();
}

// @0x140fe4cd0
void UIWeddingHallReservationPageSelect::vfunc_6()
{
    if (((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetHall() == 0)
    {
        CStringW strKey(L"s_wedding_hall_reservation_select_hall");
        ShowSystemNotice(GetStringCommonByKey(strKey), 1, 1);
    }
    else
    {
        ((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->SelectNextTab();
    }
}

// @0x140fe4d70
void UIWeddingHallReservationPageSelect::vfunc_7()
{
    m_nSelectedSlot = 0;
}

// @0x140fe4d90
CString UIWeddingHallReservationPageSelect::vfunc_8()
{
    return CString("PageSelect");
}

// @0x140fe4de0
CStringW UIWeddingHallReservationPageSelect::vfunc_9()
{
    CStringW strKey(L"s_wedding_reservation_select_page");
    return GetStringCommonByKey(strKey);
}

// @0x140fe4e50
CStringW UIWeddingHallReservationPageSelect::vfunc_10(bool bStart)
{
    if (bStart)
    {
        CStringW strPrev(L"s_wedding_reservation_prev");
        return GetStringCommonByKey(strPrev);
    }
    CStringW strNext(L"s_wedding_reservation_next");
    return GetStringCommonByKey(strNext);
}

// @0x140fe4f10
bool UIWeddingHallReservationPageSelect::vfunc_11(bool a1)
{
    if (a1 && FUN_140fe5640(m_pDialog) == 0)
        return false;
    return true;
}

// @0x140fe4f50
bool UIWeddingHallReservationPageSelect::vfunc_12()
{
    if (((class UIWeddingHallReservationDialog*)(class UIDialog*)(m_pDialog))->GetMode() == 1)
        return FUN_140900f90(FUN_140fe2d20(m_pDialog), (class WeddingHallTicket*)(((struct Unk_WeddingTicketView*)&TSingleton<WeddingManager>::GetInstance()->GetTicket())));
    return true;
}

// @0x140fe4fb0
void FUN_140fe4fb0(UIWeddingHallReservationPageSelect* pPage, int nSlotId)
{
    if ((*(const MS2Ptr<AScript>*)(&pPage->m_pScript) == 0))
        return;
    int nHallId = FUN_140fe2d20(pPage->m_pDialog);
    MS2Ptr<WeddingPackage> hall = TSingleton<WeddingTable>::GetInstance()->FindPackage(nHallId);
    if (hall == 0)
        return;
    MS2Ptr<WeddingHallData> slot = hall->FindHall(nSlotId);
    if (slot == 0)
        return;
    pPage->m_binder.FUN_140d43990();
    bool bFlag = false;
    __int64 nTime = ((class UIWeddingHallReservationDialog*)(class UIDialog*)(pPage->m_pDialog))->GetTime();
    if (nTime != 0)
        bFlag = FUN_140900f30(nTime);
    ASObj data(2);
    data.SetWStringMember("name", TSingleton<CStringTable>::GetInstance()->FUN_141811980(3, TSingleton<WeddingTable>::GetInstance()->FUN_140908d50(hall->m_nId, slot->m_nId, bFlag)));
    data.SetStringMember("video", CString(slot->m_strVideoPath));
    data.SetWStringMember("desc", GetStringCommonByKey(slot->m_strDesc));
    data.SetIntMember("grade", slot->m_nGrade);
    __int64 nPrice = FUN_140fe5520(pPage, nHallId, nSlotId);
    ASObj item(2);
    item.SetWStringMember("price", FormatStringId<CStringW>(0x987, FUN_1409404f0(nPrice)));
    unsigned __int64 nReward = 0;
    for (size_t i = 0; i < slot->m_items.size(); i++)
    {
        MS2Ptr<WeddingRewardItem> spReward = *FUN_140fe55d0(&slot->m_items, i);
        item.SetStringMember(StringFormat("reward{0}", nReward), pPage->m_binder.FUN_140d43510(static_cast<ItemAble*>(&spReward->m_item)));
        nReward++;
    }
    data.FUN_1409eb270("item", item);
    pPage->m_pScript->Invoke("setData", data);
}

// @0x140fe5520
__int64 FUN_140fe5520(UIWeddingHallReservationPageSelect* pPage, int nHallId, int nSlot)
{
    if (((class UIWeddingHallReservationDialog*)(class UIDialog*)(pPage->m_pDialog))->GetMode() == 0)
    {
        return TSingleton<WeddingTable>::GetInstance()->FUN_140909220(nHallId, nSlot);
    }
    else
    {
        Unk_WeddingTicketView* pTicket = ((struct Unk_WeddingTicketView*)&TSingleton<WeddingManager>::GetInstance()->GetTicket());
        __int64 nOld = TSingleton<WeddingTable>::GetInstance()->FUN_140909220(pTicket->m_nHallId, pTicket->m_nSlot);
        __int64 nNew = TSingleton<WeddingTable>::GetInstance()->FUN_140909220(nHallId, nSlot);
        return nNew - nOld;
    }
}

// @0x140fe55d0
MS2Ptr<WeddingRewardItem>* FUN_140fe55d0(void* pArray, __int64 nIndex)
{
    return &static_cast<std::vector<MS2Ptr<WeddingRewardItem> >*>(pArray)->_Myfirst()[nIndex];
}

// @0x140fe5640
int FUN_140fe5640(UIDialog* pDialog)
{
    return static_cast<Unk_ReservationDialogView2*>(pDialog)->m_nSelectedPackage;
}

#include "ms2/ms2recover.h"

MS2_EMIT_CRT_MEMMOVE_S();
