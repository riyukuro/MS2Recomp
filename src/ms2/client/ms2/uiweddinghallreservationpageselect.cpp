// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingHallReservationPageSelect: the hall select page of the
// wedding hall reservation dialog (see uiweddinghallreservationpage.h).
// MS2-UNIT: ?\uiweddinghallreservationpageselect.cpp
// MS2-RANGE: 0x140fe4650-0x140fe5780 .text$mn
// MS2-PIN: ??_GUIWeddingHallReservationPageSelect@@UEAAPEAXI@Z 0x140fe5600
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddinghallreservationpageselect.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiweddinghallreservationpage.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"

// ---- handles: a smart reference whose destructor is the exe function REL ----
template <void (*REL)(void*)>
struct Unk_Ref
{
    void* m_0;
    void* m_p;
    Unk_Ref() : m_0(0), m_p(0) {}
    ~Unk_Ref() { REL(this); }
};

void FUN_140901e60(void*);
void FUN_140901e30(void*);
void FUN_140916440(void*);
void FUN_140bcbb50(void*);
void FUN_140902250(void*);

typedef Unk_Ref<FUN_140901e60> RHall;          // reservation hall table row
typedef Unk_Ref<FUN_140901e30> RSlot;          // hall slot (a time slot / package)
typedef Unk_Ref<FUN_140916440> RReward;        // reward item
typedef Unk_Ref<FUN_140bcbb50> RList;          // the swf list control

// ---- records behind the handles ----
struct Unk_RewardEntry { void* m_0; void* m_8; };
class Unk_RewardArray;
struct Unk_RewardInfo { char m_pad_00[0x30]; char m_item; };    // m_item: the item part at +0x30

struct Unk_SlotRec
{
    char m_pad_00[0x18];
    int m_nId;                                  // +0x18
    int m_nGrade;                               // +0x1c
    char m_pad_20[8];
    CString m_strVideo;                         // +0x28
    CStringW m_strDesc;                         // +0x30
    char m_pad_38[8];
    char m_rewards;                             // +0x40 (the reward array)
};

class Unk_SlotIter
{
public:
    ~Unk_SlotIter() { FUN_140902250(this); }
    void* m_p;
};
struct Unk_SlotElem { void* m_0; char m_slot; };    // m_slot: the slot handle source at +8

class Unk_SlotMap
{
public:
    Unk_SlotIter FUN_140902b40();               // begin
    Unk_SlotIter FUN_140902db0();               // end
};

class Unk_HallRec
{
public:
    RSlot FUN_140907110(int nSlotId);           // find a slot by id
    char m_pad_00[0x18];
    int m_nId;                                  // +0x18
    int m_pad_1c;
    Unk_SlotMap m_slots;                        // +0x20
};

class Unk_HallTable
{
public:
    RHall FUN_140908b80(int nHallId);
    int FUN_140909130(int nHallId, int nSlot);
    __int64 FUN_140909220(int nHallId, int nSlot);
    int FUN_140908d50(int nHallId, int nSlotId, unsigned char bPrivate);
};
Unk_HallTable* FUN_1409023c0();

class Unk_RListCtl : public CPtred
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8();
    virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12();
    virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16();
    virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
    virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                       // clear
    void FUN_1422dd230(const ASObj& obj);       // add an item
    void FUN_1422dcca0(int nIndex);             // select
};
class Unk_StrTable { public: CStringW FUN_141811980(int nTable, int nIndex); };

// ---- exe callees ----
void* FUN_1409eed90();                                                      // the singleton of the own character
Unk_WeddingTicketView* FUN_141b87160(void* pCharacter);                     // the character's current wedding hall ticket
bool FUN_140900f90(int nId, Unk_WeddingTicketView* pTicket);                // can the ticket be changed to this hall
int FUN_140fe2d20(UIDialog* pDialog);                                       // the selected hall id of the dialog
int FUN_140fdca80(UIDialog* pDialog);                                       // reservation mode (1 = change)
void* FUN_140fdca40(UIDialog* pDialog);                                     // the reservation target
int FUN_140fdca20(UIDialog* pDialog);
void FUN_140fdc030(UIDialog* pDialog);
void FUN_140fdbf70(UIDialog* pDialog);
void FUN_140fdc110(UIDialog* pDialog, int nSlotId);
unsigned char FUN_140900f30(void* pTarget);
unsigned char FUN_140901fa0(RHall* p, int n);                               // handle is null
Unk_HallRec* FUN_1409020f0(RHall* p);
unsigned char FUN_140916aa0(RSlot* p, int n);
unsigned char FUN_1409020a0(Unk_SlotIter* a, Unk_SlotIter* b);              // iterators differ
void* FUN_140902100(Unk_SlotIter* p);                                       // the element of the iterator
void FUN_140901b60(RSlot* pDst, void* pElem);                               // copy a slot handle
Unk_SlotRec* FUN_1409020e0(RSlot* p);
int FUN_140906e40(Unk_SlotRec* p, unsigned char bFlag);
unsigned char FUN_140bcc0c0(RList* p, int n);                               // handle is null
Unk_RListCtl* FUN_140bcc3f0(RList* p);
unsigned char FUN_140ba28d0(MS2Ptr<AScript>* p, int n);
Unk_StrTable* FUN_1401a9d70();
CStringW FUN_14028b8e0(const CStringW& strKey);                             // string table text
void FUN_1412751f0(const CStringW& strText, int a, int b);                  // notice
CStringW FUN_1409404f0(__int64 n);                                          // number to text
CStringW FUN_14052bd00(int nId, const CStringW& strArg);                    // string with one argument
CString FUN_1401d9af0(const char* szFormat, __int64* pArg);                 // "reward{0}"
size_t FUN_1409203a0(void* pArray);
__int64* FUN_14091cea0(void* pArray);
void FUN_140915430(RReward* pDst, Unk_RewardEntry* pElem);
Unk_RewardInfo* FUN_140917000(RReward* p);
struct Unk_WhGetChild { RList FUN_140bc7280(const CString& strName); }; // GetChild (member of AScript)

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
Unk_RewardEntry* FUN_140fe55d0(void* pArray, __int64 nIndex);
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

// MS2-FUNCTIONAL: handle/iterator temporaries and frame layout differ
// @0x140fe4720
bool UIWeddingHallReservationPageSelect::vfunc_1()
{
    if (!UIWeddingHallReservationPage::vfunc_1())
        return false;
    RHall hall = FUN_1409023c0()->FUN_140908b80(FUN_140fe2d20(m_pDialog));
    if (FUN_140901fa0(&hall, 0))
        return false;
    RList list = reinterpret_cast<Unk_WhGetChild*>(m_pScript.operator->())->FUN_140bc7280(CString("m_list"));
    if (FUN_140bcc0c0(&list, 0))
        return false;
    int nPackageSlot = -1;
    if (FUN_140fdca80(m_pDialog) == 1)
    {
        Unk_WeddingTicketView* pTicket = FUN_141b87160(FUN_1409eed90());
        nPackageSlot = FUN_1409023c0()->FUN_140909130(pTicket->m_nHallId, pTicket->m_nSlot);
    }
    FUN_140bcc3f0(&list)->FUN_1422dd1d0();
    unsigned char bFlag = 0;
    void* pTarget = FUN_140fdca40(m_pDialog);
    if (pTarget != 0)
        bFlag = FUN_140900f30(pTarget);
    Unk_SlotIter it = FUN_1409020f0(&hall)->m_slots.FUN_140902b40();
    Unk_SlotIter end = FUN_1409020f0(&hall)->m_slots.FUN_140902db0();
    int nIndex = 0;
    int nSelect = -1;
    while (FUN_1409020a0(&it, &end))
    {
        RSlot slot;
        FUN_140901b60(&slot, &static_cast<Unk_SlotElem*>(FUN_140902100(&it))->m_slot);
        bool bEnabled = true;
        if (nPackageSlot != -1)
            bEnabled = nPackageSlot <= FUN_1409020e0(&slot)->m_nGrade;
        ASObj row(2);
        row.FUN_1407cb9c0("id", FUN_1409020e0(&slot)->m_nId);
        row.FUN_1407cbb20("label", FUN_1401a9d70()->FUN_141811980(3, FUN_140906e40(FUN_1409020e0(&slot), bFlag)));
        row.FUN_1407cbbe0("enabled", bEnabled);
        FUN_140bcc3f0(&list)->FUN_1422dd230(row);
        if (m_nSelectedSlot == 0)
        {
            if (bEnabled && nSelect == -1)
                nSelect = nIndex;
        }
        else if (FUN_1409020e0(&slot)->m_nId == m_nSelectedSlot)
        {
            nSelect = nIndex;
        }
        nIndex = nIndex + 1;
        FUN_140902250(&it);
    }
    if (nSelect != -1)
        FUN_140bcc3f0(&list)->FUN_1422dcca0(nSelect);
    FUN_140bcc3f0(&list)->vfunc_24(true);
    return true;
}

// @0x140fe4b60
void UIWeddingHallReservationPageSelect::vfunc_2()
{
    UIWeddingHallReservationPage::vfunc_2();
    m_binder.FUN_140d43990();
}

// MS2-FUNCTIONAL: early-return/jump layout differs
// @0x140fe4b90
bool UIWeddingHallReservationPageSelect::vfunc_4(__int64 a1, __int64 a2, int a3)
{
    if (UIWeddingHallReservationPage::vfunc_4(a1, a2, a3) == 1)
        return true;
    int n = _stricmp((const char*)a1, "onSelectWeddingHall");
    if (n == 0)
    {
        ASData data;
        if (data.FUN_1422b9620((const Scaleform::GFx::Value*)a2, a3))
        {
            m_nSelectedSlot = data.FUN_1422b8a10();
            FUN_140fe4fb0(this, m_nSelectedSlot);
            FUN_140fdc110(m_pDialog, m_nSelectedSlot);
        }
        return true;
    }
    return false;
}

// @0x140fe4ca0
void UIWeddingHallReservationPageSelect::vfunc_5()
{
    FUN_140fdbf70(m_pDialog);
}

// @0x140fe4cd0
void UIWeddingHallReservationPageSelect::vfunc_6()
{
    if (FUN_140fdca20(m_pDialog) == 0)
    {
        CStringW strKey(L"s_wedding_hall_reservation_select_hall");
        FUN_1412751f0(FUN_14028b8e0(strKey), 1, 1);
    }
    else
    {
        FUN_140fdc030(m_pDialog);
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
    return FUN_14028b8e0(strKey);
}

// @0x140fe4e50
CStringW UIWeddingHallReservationPageSelect::vfunc_10(bool bStart)
{
    if (bStart)
    {
        CStringW strPrev(L"s_wedding_reservation_prev");
        return FUN_14028b8e0(strPrev);
    }
    CStringW strNext(L"s_wedding_reservation_next");
    return FUN_14028b8e0(strNext);
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
    if (FUN_140fdca80(m_pDialog) == 1)
        return FUN_140900f90(FUN_140fe2d20(m_pDialog), FUN_141b87160(FUN_1409eed90()));
    return true;
}

// MS2-FUNCTIONAL: handle/temporary layout differs
// @0x140fe4fb0
void FUN_140fe4fb0(UIWeddingHallReservationPageSelect* pPage, int nSlotId)
{
    if (FUN_140ba28d0(&pPage->m_pScript, 0))
        return;
    int nHallId = FUN_140fe2d20(pPage->m_pDialog);
    RHall hall = FUN_1409023c0()->FUN_140908b80(nHallId);
    if (FUN_140901fa0(&hall, 0))
        return;
    RSlot slot = FUN_1409020f0(&hall)->FUN_140907110(nSlotId);
    if (FUN_140916aa0(&slot, 0))
        return;
    pPage->m_binder.FUN_140d43990();
    unsigned char bFlag = 0;
    void* pTarget = FUN_140fdca40(pPage->m_pDialog);
    if (pTarget != 0)
        bFlag = FUN_140900f30(pTarget);
    ASObj data(2);
    int nNameId = FUN_1409023c0()->FUN_140908d50(FUN_1409020f0(&hall)->m_nId, FUN_1409020e0(&slot)->m_nId, bFlag);
    data.FUN_1407cbb20("name", FUN_1401a9d70()->FUN_141811980(3, nNameId));
    data.FUN_1407cba60("video", CString(FUN_1409020e0(&slot)->m_strVideo));
    data.FUN_1407cbb20("desc", FUN_14028b8e0(FUN_1409020e0(&slot)->m_strDesc));
    data.FUN_1407cb9c0("grade", FUN_1409020e0(&slot)->m_nGrade);
    __int64 nPrice = FUN_140fe5520(pPage, nHallId, nSlotId);
    ASObj item(2);
    item.FUN_1407cbb20("price", FUN_14052bd00(0x987, FUN_1409404f0(nPrice)));
    __int64 nReward = 0;
    for (size_t i = 0; i < FUN_1409203a0(&FUN_1409020e0(&slot)->m_rewards); i++)
    {
        RReward reward;
        FUN_140915430(&reward, FUN_140fe55d0(&FUN_1409020e0(&slot)->m_rewards, i));
        Unk_RewardInfo* pInfo = FUN_140917000(&reward);
        void* pItem = pInfo ? &pInfo->m_item : 0;
        item.FUN_1407cba60(FUN_1401d9af0("reward{0}", &nReward), pPage->m_binder.FUN_140d43510(pItem));
        nReward++;
    }
    data.FUN_1409eb270("item", item);
    pPage->m_pScript->Invoke("setData", data);
}

// MS2-FUNCTIONAL: single-return temp layout differs
// @0x140fe5520
__int64 FUN_140fe5520(UIWeddingHallReservationPageSelect* pPage, int nHallId, int nSlot)
{
    __int64 nPrice;
    if (FUN_140fdca80(pPage->m_pDialog) == 0)
    {
        nPrice = FUN_1409023c0()->FUN_140909220(nHallId, nSlot);
    }
    else
    {
        Unk_WeddingTicketView* pTicket = FUN_141b87160(FUN_1409eed90());
        __int64 nOld = FUN_1409023c0()->FUN_140909220(pTicket->m_nHallId, pTicket->m_nSlot);
        nPrice = FUN_1409023c0()->FUN_140909220(nHallId, nSlot);
        nPrice = nPrice - nOld;
    }
    return nPrice;
}

// MS2-FUNCTIONAL: address temp differs
// @0x140fe55d0
Unk_RewardEntry* FUN_140fe55d0(void* pArray, __int64 nIndex)
{
    return (Unk_RewardEntry*)(nIndex * 0x10 + *FUN_14091cea0(pArray));
}

// @0x140fe5640
int FUN_140fe5640(UIDialog* pDialog)
{
    return static_cast<Unk_ReservationDialogView2*>(pDialog)->m_nSelectedPackage;
}

#include "ms2/ms2recover.h"

MS2_EMIT_CRT_MEMMOVE_S();
