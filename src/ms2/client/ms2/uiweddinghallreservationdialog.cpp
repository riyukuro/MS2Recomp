// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingHallReservationDialog: see
// uiweddinghallreservationdialog.h.
// MS2-UNIT: ?\uiweddinghallreservationdialog.cpp
// MS2-RANGE: 0x1400e2f40-0x1400e3170 .text$di
// MS2-RANGE: 0x140fdb090-0x140fe2150 .text$mn
// MS2-RANGE: 0x142caadd0-0x142caae90 .text$yd
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddinghallreservationdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiweddinghallreservationdialog.h"
#include "uibeautyshopstyledialog.h"
#include "uitalkcinematic.h"

#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asbutton.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/placeholder/weddingmanager.h"
#include "ms2/placeholder/weddingpackage.h"
#include "ms2/placeholder/weddingtable.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- statics (.text$di): the sort type names a second time (another header of the unit pulls them in) ----
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- unit-local views of exe objects ----

// The pages (their units declare them; only the ctor and the size matter here).
class UIWeddingHallReservationPageSelect : public UIWeddingHallReservationPage
{
public:
    UIWeddingHallReservationPageSelect(UIDialog* pDialog);      // 0x140fe4650
    virtual CString vfunc_8(); virtual CStringW vfunc_9(); virtual CStringW vfunc_10(bool bStart);
    void* m_unrecovered_30[9];
};
class UIWeddingHallReservationPageSchedule : public UIWeddingHallReservationPage
{
public:
    UIWeddingHallReservationPageSchedule(UIDialog* pDialog);    // 0x140fe33a0
    virtual CString vfunc_8(); virtual CStringW vfunc_9(); virtual CStringW vfunc_10(bool bStart);
    void* m_unrecovered_30[4];
};
class UIWeddingHallReservationPageConfirm : public UIWeddingHallReservationPage
{
public:
    UIWeddingHallReservationPageConfirm(UIDialog* pDialog);     // 0x140fe2d40
    virtual CString vfunc_8(); virtual CStringW vfunc_9(); virtual CStringW vfunc_10(bool bStart);
};
class UIWeddingHallReservationPageChange : public UIWeddingHallReservationPage
{
public:
    UIWeddingHallReservationPageChange(UIDialog* pDialog);      // 0x140fe2880
    virtual CString vfunc_8(); virtual CStringW vfunc_9(); virtual CStringW vfunc_10(bool bStart);
};
class UIWeddingHallReservationPageCancel : public UIWeddingHallReservationPage
{
public:
    UIWeddingHallReservationPageCancel(UIDialog* pDialog);      // 0x140fe24d0
    virtual CString vfunc_8(); virtual CStringW vfunc_9(); virtual CStringW vfunc_10(bool bStart);
};
MS2_CHECK_SIZE(UIWeddingHallReservationPageSelect, 0x78);
MS2_CHECK_SIZE(UIWeddingHallReservationPageSchedule, 0x50);
MS2_CHECK_SIZE(UIWeddingHallReservationPageConfirm, 0x30);

class ASDialog : public ASDisplayObjectContainer {};

class Unk_WrInventory { public: MS2Ptr<CItem> FUN_140a5e040(int nItemId); };   // the first item of an id
extern Unk_WrInventory DAT_143ab2a90;                           // the local player's inventory

UITalkCinematic* FUN_140a7b2b0(int nUiId);                      // an open dialog of an id
UIBillDialog* FUN_140f0a350(int nUiId);
class Unk_WrUIManager { public: void FUN_141adc530(int nUiId); };   // open a dialog
Unk_WrUIManager* FUN_1403ed2b0();
bool FUN_140900f30(__int64 nTime);                              // the time is at night
CStringW FUN_1409404f0(__int64 n);                              // a number with digit grouping
CStringW FUN_14052bd00(int nStringId, const CStringW& strArg);  // string table text with one argument
CStringW FUN_14028b8e0(const CStringW& strKey);                 // the localized string

void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned long long n);
void FUN_1422bcce0(Scaleform::GFx::Value* pValue, bool b);

// ---- the dialog ----

// @0x140fdb090
UIWeddingHallReservationDialog::UIWeddingHallReservationDialog()
    : m_nPackage(0), m_nHall(0), m_nTime(0), m_bNight(0), m_nMode(0)
{
    m_2c = 0x1b;
    FUN_1422dc3b0(1);
    FUN_141924170(1);
    FUN_140fdcc30(PagePtr(new UIWeddingHallReservationPageSelect(this)));
    FUN_140fdcc30(PagePtr(new UIWeddingHallReservationPageSchedule(this)));
    FUN_140fdcc30(PagePtr(new UIWeddingHallReservationPageConfirm(this)));
    FUN_140fdcc30(PagePtr(new UIWeddingHallReservationPageChange(this)));
    FUN_140fdcc30(PagePtr(new UIWeddingHallReservationPageCancel(this)));
}

// @0x140fdb460
UIWeddingHallReservationDialog::~UIWeddingHallReservationDialog()
{
    m_pages.clear();
}

// @0x140fdb4f0
CString UIWeddingHallReservationDialog::GetTypeName()
{
    return "WeddingHallReservationDialog";
}
MS2_REPLACE_METHOD(0x140fdb4f0, UIWeddingHallReservationDialog, GetTypeName, 61, 0x39A4E0B9);

// @0x140fdb540
int UIWeddingHallReservationDialog::vfunc_65()
{
    if (UIDialog::vfunc_65() == 0)
        return 0;
    for (PageMap::iterator it = m_pages.begin(), itEnd = m_pages.end(); it != itEnd; ++it)
        it->second->vfunc_7();
    return 1;
}
MS2_REPLACE_METHOD(0x140fdb540, UIWeddingHallReservationDialog, vfunc_65, 167, 0xAAD89E48);

// @0x140fdb5f0
void UIWeddingHallReservationDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    UITalkManager::GetInstance()->SendNpcTalkMode0();
}
MS2_REPLACE_METHOD(0x140fdb5f0, UIWeddingHallReservationDialog, vfunc_67, 37, 0x15862B02);

// @0x140fdb620
void UIWeddingHallReservationDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_nHall = 0;
    m_nTime = 0;
    std::vector<CString> names;
    switch (m_nMode)
    {
    case 0:
        names.push_back("PageSelect");
        names.push_back("PageSchedule");
        names.push_back("PageConfirm");
        break;
    case 2:
        names.push_back("PageCancel");
        break;
    case 1:
        names.push_back("PageChange");
        names.push_back("PageSelect");
        names.push_back("PageSchedule");
        names.push_back("PageConfirm");
        break;
    }
    FUN_140fdccd0(names);
    FUN_140fdd2d0();
}
MS2_REPLACE_METHOD(0x140fdb620, UIWeddingHallReservationDialog, OnLoadComplete, 565, 0x74A7AD99);

// @0x140fdb860
void UIWeddingHallReservationDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    UITalkCinematic* pTalk;
    if (pDialog != 0 && (pTalk = FUN_140a7b2b0(0x4e40)) != 0)
    {
        int nX = pTalk->FUN_141b1d3d0();
        int nY = pTalk->FUN_141b1d460() - 0x50;
        if (nX != -1 && nY != -1)
        {
            pDialog->vfunc_2(5, nY, nX - pDialog->FUN_1422c13b0());
            return;
        }
    }
    if (ASDialog* pCentered = dynamic_cast<ASDialog*>((AScript*)m_30))
        pCentered->vfunc_2(1, 0, 0);
}
MS2_REPLACE_METHOD(0x140fdb860, UIWeddingHallReservationDialog, vfunc_43, 292, 0xB16E01A7);

// @0x140fdb990
int UIWeddingHallReservationDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onAddPage") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CString strPage = data.FUN_1422b8d30();
            PageMap::iterator it = m_pages.find(strPage);
            if (it != m_pages.end())
            {
                m_spPage = it->second;
                it->second->vfunc_1();
            }
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onRemovePage") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CString strPage = data.FUN_1422b8d30();
            PageMap::iterator it = m_pages.find(strPage);
            if (it != m_pages.end())
            {
                m_spPage = 0;
                it->second->vfunc_2();
            }
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onChangeTab") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            m_nTab = data.FUN_1422b8a10();
            FUN_140fdcfc0();
        }
    }
    else if (_stricmp(szMethod, "onButtonLeft") == 0)
    {
        if (m_spPage.get() != 0)
            m_spPage->vfunc_5();
        return 1;
    }
    else if (_stricmp(szMethod, "onButtonRight") == 0)
    {
        if (m_spPage.get() != 0)
            m_spPage->vfunc_6();
        FUN_140fdd2d0();
        return 1;
    }
    if (m_spPage.get() != 0)
    {
        if (m_spPage->vfunc_4(reinterpret_cast<__int64>(szMethod), reinterpret_cast<__int64>(pArgs), nArgs) == true)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140fdb990, UIWeddingHallReservationDialog, vfunc_28, 1142, 0xEC17815D);

// MS2-FUNCTIONAL: the exe's UIMsg::FUN_1422b8a90 returns bool (the shared imessagelistener.h declares int, used by done
// units), so the coupon flag gets a conversion here and the frame is 0x10 larger; calls and logic identical
// @0x140fdbe20
int UIWeddingHallReservationDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() == 0)
    {
        if (dynamic_cast<UIBillDialog*>(pSender) != 0)
        {
            int nResult = pMsg->FUN_1422b8a10();
            bool bCoupon = pMsg->FUN_1422b8a90() != 0;
            if (nResult == 0)
            {
                WeddingManager::GetInstance()->SendReservation(m_nPackage, m_nHall, m_nTime, m_bNight, bCoupon);
                vfunc_67();
                UITalkManager::GetInstance()->SendNpcTalkMode0();
            }
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD_VIA(0x140fdbe20, UIWeddingHallReservationDialog, IMessageListener, OnMessage, 289, 0x68FA4A79);

// @0x140fdbf50
void UIWeddingHallReservationDialog::SetPackage(int nPackage)
{
    m_nPackage = nPackage;
}
MS2_REPLACE_METHOD(0x140fdbf50, UIWeddingHallReservationDialog, SetPackage, 25, 0x11D24FAE);

// @0x140fdbf70
void UIWeddingHallReservationDialog::FUN_140fdbf70()
{
    if (m_nTab == 0)
        return;
    if (MS2Ptr<ASButtonBar> spTab = GetChild<ASButtonBar>("m_tab"))
        spTab->FUN_1422e31e0(m_nTab - 1);
}
MS2_REPLACE_METHOD(0x140fdbf70, UIWeddingHallReservationDialog, FUN_140fdbf70, 184, 0x3EFA11E0);

// @0x140fdc030
void UIWeddingHallReservationDialog::FUN_140fdc030()
{
    if (m_nTab >= (int)(m_tabs.size() - 1))
        return;
    if (MS2Ptr<ASButtonBar> spTab = GetChild<ASButtonBar>("m_tab"))
        spTab->FUN_1422e31e0(m_nTab + 1);
}
MS2_REPLACE_METHOD(0x140fdc030, UIWeddingHallReservationDialog, FUN_140fdc030, 205, 0xFF3DDA98);

// @0x140fdc110
void UIWeddingHallReservationDialog::SetHall(int nHall)
{
    m_nHall = nHall;
}
MS2_REPLACE_METHOD(0x140fdc110, UIWeddingHallReservationDialog, SetHall, 25, 0x3BA376EE);

// @0x140fdc130
void UIWeddingHallReservationDialog::SetTime(__int64 nTime)
{
    m_nTime = nTime;
}
MS2_REPLACE_METHOD(0x140fdc130, UIWeddingHallReservationDialog, SetTime, 28, 0x9BD0B3F6);

// @0x140fdc160
void UIWeddingHallReservationDialog::SetNight(unsigned char bNight)
{
    m_bNight = bNight;
}
MS2_REPLACE_METHOD(0x140fdc160, UIWeddingHallReservationDialog, SetNight, 26, 0x1076974C);

// MS2-FUNCTIONAL: frame 0x20 larger (slot order of the bill / string temporaries); calls and logic identical
// @0x140fdc180
void UIWeddingHallReservationDialog::FUN_140fdc180()
{
    MS2Ptr<WeddingPackage> spPackage = WeddingTable::GetInstance()->FUN_140908b80(m_nPackage);
    if (spPackage == 0)
        return;
    MS2Ptr<WeddingHallData> spHall = spPackage->FUN_140907110(m_nHall);
    if (spHall == 0)
        return;
    if (!WeddingManager::GetInstance()->FUN_141b89a10(m_nPackage, m_nHall, m_nTime, m_bNight))
        return;
    MS2Ptr<CItem> spCoupon(0);
    if (spHall->FUN_140906e80() != 0)
        spCoupon = DAT_143ab2a90.FUN_140a5e040(spHall->FUN_140906e80());
    MS2Ptr<UIBillDialog::TData> spBill(new UIBillDialog::TData());
    MS2Ptr<AScript> spData(new ASObj(2));
    static_cast<ASObj*>(spData.operator->())->FUN_1407cbb20("category",
        FUN_14028b8e0(StringFormat(L"s_wedding_reservation_hall_bill_category_grade_{0}", spHall->m_nGrade)));
    unsigned nFieldId = spHall->FUN_140906e40(FUN_140900f30(m_nTime));
    CStringW strDetail = CStringTable::GetInstance()->FUN_141811980(3, nFieldId);
    CStringW strPrice = FUN_14052bd00(0x987, FUN_1409404f0(spHall->m_nMerat));
    ASArray rows(2);
    ASObj row(2);
    row.FUN_1407cbb20("detail", strDetail);
    row.FUN_1407cbb20("strPrice", strPrice);
    rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
    static_cast<ASObj*>(spData.operator->())->FUN_1409adbe0("list", Scaleform::GFx::Value(rows.FUN_1422bb870()));
    spBill->m_18 = static_cast<IMessageListener*>(this);
    spBill->m_30 = 3;
    spBill->m_20 = spData;
    if (spCoupon.get() != 0)
    {
        spBill->m_60 = 1;
        spBill->m_50 = FUN_14028b8e0(CStringW(L"s_wedding_reservation_coupon_checkbox"));
        spBill->m_58 = FUN_14028b8e0(CStringW(L"s_wedding_reservation_coupon_warn"));
    }
    spBill->m_34 = 4;
    spBill->m_48 = (int)spHall->m_nMerat;
    FUN_140f0a350(0x4e7b)->FUN_1418cda20(spBill);
    FUN_1403ed2b0()->FUN_141adc530(0x4e7b);
}
// (not hooked: the inline UIBillDialog::TData ctor stores a DLL-local vftable)

// @0x140fdc970
void UIWeddingHallReservationDialog::FUN_140fdc970()
{
    WeddingManager::GetInstance()->SendReservationChange(m_nPackage, m_nHall, m_nTime, m_bNight);
    vfunc_67();
    UITalkManager::GetInstance()->SendNpcTalkMode0();
}
MS2_REPLACE_METHOD(0x140fdc970, UIWeddingHallReservationDialog, FUN_140fdc970, 110, 0x5F93CD48);

// @0x140fdc9f0
void UIWeddingHallReservationDialog::FUN_140fdc9f0()
{
    WeddingManager::GetInstance()->SendReservationCancel();
}
MS2_REPLACE_METHOD(0x140fdc9f0, UIWeddingHallReservationDialog, FUN_140fdc9f0, 27, 0x68E3290C);

// @0x140fdca20
int UIWeddingHallReservationDialog::GetHall()
{
    return m_nHall;
}
MS2_REPLACE_METHOD(0x140fdca20, UIWeddingHallReservationDialog, GetHall, 17, 0xA6F3F9B2);

// @0x140fdca40
__int64 UIWeddingHallReservationDialog::GetTime()
{
    return m_nTime;
}
MS2_REPLACE_METHOD(0x140fdca40, UIWeddingHallReservationDialog, GetTime, 18, 0x7817FBF0);

// @0x140fdca60
unsigned char UIWeddingHallReservationDialog::GetNight()
{
    return m_bNight;
}
MS2_REPLACE_METHOD(0x140fdca60, UIWeddingHallReservationDialog, GetNight, 18, 0x21FB4E4C);

// @0x140fdca80
int UIWeddingHallReservationDialog::GetMode()
{
    return m_nMode;
}
MS2_REPLACE_METHOD(0x140fdca80, UIWeddingHallReservationDialog, GetMode, 17, 0xD5D5F2AE);

// @0x140fdcaa0
void UIWeddingHallReservationDialog::FUN_140fdcaa0(const CString& strMode)
{
    if (strMode.CompareNoCase("reservation") == 0)
        m_nMode = 0;
    else if (strMode.CompareNoCase("reservationChange") == 0)
        m_nMode = 1;
    else if (strMode.CompareNoCase("reservationCancel") == 0)
        m_nMode = 2;
}
MS2_REPLACE_METHOD(0x140fdcaa0, UIWeddingHallReservationDialog, FUN_140fdcaa0, 134, 0x7115E4B7);

// @0x140fdcb30
__int64 UIWeddingHallReservationDialog::FUN_140fdcb30()
{
    MS2Ptr<WeddingPackage> spPackage = WeddingTable::GetInstance()->FUN_140908b80(m_nPackage);
    if (spPackage == 0)
        return 0;
    MS2Ptr<WeddingHallData> spHall = spPackage->FUN_140907110(m_nHall);
    if (spHall == 0)
        return 0;
    return spHall->m_nMerat;
}
MS2_REPLACE_METHOD(0x140fdcb30, UIWeddingHallReservationDialog, FUN_140fdcb30, 239, 0x0A256752);

// @0x140fdcc30
void UIWeddingHallReservationDialog::FUN_140fdcc30(PagePtr spPage)
{
    m_pages[spPage->vfunc_8()] = spPage;
}
MS2_REPLACE_METHOD(0x140fdcc30, UIWeddingHallReservationDialog, FUN_140fdcc30, 139, 0x80C34F37);

// @0x140fdccd0
void UIWeddingHallReservationDialog::FUN_140fdccd0(const std::vector<CString>& names)
{
    if (MS2Ptr<ASButtonBar> spTab = GetChild<ASButtonBar>("m_tab"))
    {
        m_30->FUN_140c1c8c0("setupTabSize", names.size());
        m_tabs.clear();
        m_nTab = 0;
        spTab->FUN_1422e3400();
        for (size_t i = 0; i < names.size(); ++i)
        {
            PagePtr spPage = FUN_140fdd3f0(names[i]);
            if (spPage.get() != 0)
            {
                ASObj item(2);
                item.FUN_1407cba60("page", spPage->vfunc_8());
                item.FUN_1407cbb20("label", spPage->vfunc_9());
                spTab->FUN_1422e3460(item);
                m_tabs.push_back(spPage);
            }
        }
        spTab->FUN_1422e31e0(0);
        spTab->vfunc_24(true);
    }
}
MS2_REPLACE_METHOD(0x140fdccd0, UIWeddingHallReservationDialog, FUN_140fdccd0, 732, 0xE82E44DD);

// @0x140fdcfc0
void UIWeddingHallReservationDialog::FUN_140fdcfc0()
{
    if (m_nTab < 0 || m_nTab >= (int)m_tabs.size())
        return;
    PagePtr spPage = m_tabs[m_nTab];
    if (spPage == 0)
        return;
    if (MS2Ptr<ASButton> spLeft = GetChild<ASButton>("m_leftButton"))
    {
        spLeft->FUN_1422cdfb0(spPage->vfunc_10(true));
        spLeft->FUN_1422c1fe0(spPage->vfunc_11(true));
    }
    if (MS2Ptr<ASButton> spRight = GetChild<ASButton>("m_rightButton"))
    {
        spRight->FUN_1422cdfb0(spPage->vfunc_10(false));
        spRight->FUN_1422c1fe0(spPage->vfunc_11(false));
    }
}
MS2_REPLACE_METHOD(0x140fdcfc0, UIWeddingHallReservationDialog, FUN_140fdcfc0, 777, 0xC85CC01E);

// @0x140fdd2d0
void UIWeddingHallReservationDialog::FUN_140fdd2d0()
{
    if (m_30 == 0)
        return;
    for (size_t i = 0; i < m_tabs.size(); ++i)
    {
        PagePtr spPage = m_tabs[i];
        m_30->FUN_140fdd6b0("setTabEnable", i, spPage->vfunc_12());
    }
}
MS2_REPLACE_METHOD(0x140fdd2d0, UIWeddingHallReservationDialog, FUN_140fdd2d0, 273, 0x47AE7618);

// @0x140fdd3f0
UIWeddingHallReservationDialog::PagePtr UIWeddingHallReservationDialog::FUN_140fdd3f0(const CString& strName)
{
    PageMap::iterator it = m_pages.find(strName);
    if (it == m_pages.end())
        return PagePtr(0);
    return it->second;
}
MS2_REPLACE_METHOD(0x140fdd3f0, UIWeddingHallReservationDialog, FUN_140fdd3f0, 178, 0x06AD05E1);

// @0x140fdd6b0
Scaleform::GFx::Value AScript::FUN_140fdd6b0(const char* szMethod, unsigned __int64 a1, bool a2)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce00(args.FUN_1409b1f70(0), a1);
    FUN_1422bcce0(args.FUN_1409b1f70(1), a2);
    return FUN_1422bb8f0(szMethod, args);
}
