// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIWeddingGuestDialog and its pages: see uiweddingguestdialog.h.
// MS2-UNIT: ?\uiweddingguestdialog.cpp
// MS2-PIN: ??$FUN_14028dfa0@_KH@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V01@AEB_KAEBH@Z 0x140fce540
// MS2-PIN: ??A?$CAtlArray@V?$MS2Ptr@VCGuildMember@@@@V?$CElementTraits@V?$MS2Ptr@VCGuildMember@@@@@ATL@@@ATL@@QEAAAEAV?$MS2Ptr@VCGuildMember@@@@_K@Z 0x140fd8c00
// MS2-RANGE: 0x1400e2d10-0x1400e2f40 .text$di
// MS2-RANGE: 0x140fcc860-0x140fd8df0 .text$mn
// MS2-RANGE: 0x142caad10-0x142caadd0 .text$yd
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$MS2Ptr@VWeddingGuest@@@@QEBAPEAVWeddingGuest@@XZ 0x140fd3440 ; unique
// MS2-PIN: ?vfunc_48@UIWeddingGuestDialog@@UEAAHXZ 0x140fd3a80 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VWeddingGuest@@@@V?$allocator@V?$MS2Ptr@VWeddingGuest@@@@@std@@@std@@@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingGuest@@@@@std@@@2@XZ 0x140fd5050 ; unique
// MS2-PIN: ?_Get_data@?$_Vector_alloc@U?$_Vec_base_types@V?$MS2Ptr@VWeddingGuest@@@@V?$allocator@V?$MS2Ptr@VWeddingGuest@@@@@std@@@std@@@std@@QEBAAEBV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingGuest@@@@@std@@@2@XZ 0x140fd5070 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$MS2Ptr@VWeddingGuest@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$MS2Ptr@VWeddingGuest@@@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x140fd50b0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$MS2Ptr@VWeddingGuest@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$MS2Ptr@VWeddingGuest@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x140fd50c0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VWeddingGuest@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingGuest@@@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$MS2Ptr@VWeddingGuest@@@@@2@XZ 0x140fd5110 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VWeddingGuest@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingGuest@@@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$MS2Ptr@VWeddingGuest@@@@@2@XZ 0x140fd5120 ; unique
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$MS2Ptr@VWeddingGuest@@@@@std@@V?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingGuest@@@@@std@@@2@$00@std@@QEAAAEAV?$_Vector_val@U?$_Simple_types@V?$MS2Ptr@VWeddingGuest@@@@@std@@@2@XZ 0x140fd51b0 ; prop
// MS2-PIN: ?ms2_memmove_s_copy1@@YAHQEAX_KQEBX1@Z 0x140fd6aa0 ; unique
// MS2-PINS-END tplpin
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiweddingguestdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uiweddingguestdialog.h"
#include "uiweddinginvitationdialog.h"
#include "uiservice.h"
#include "buddymanager.h"
#include "guildmanager.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/weddingmanager.h"
#include "ms2/placeholder/weddingproxy.h"
#include "ms2/fmt/format.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The second copy of the notice board sort names (this unit's own static table).
static CString s_sortNames[] = { "None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd" };

// ---- unit-local views of exe objects ----

class ASDialog : public ASDisplayObject
{
public:
    virtual void vfunc_2(int, int, int);                        // place the movie
    int FUN_1422c13b0();                                        // width
};

// The tab strip of the movie.
class Unk_GsTab : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422e3400();                                       // clear
    void FUN_1422e3460(const ASObj& row);                       // append a tab
    void FUN_1422e31e0(unsigned int nIndex);                    // select a tab
};

// The guest list of a page.
class Unk_GsList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                       // clear
    void FUN_1422dd230(const ASObj& row);                       // append a row
    void FUN_1422dcca0(int nIndex);                             // select a row
};

// The page movie clip (looks up its list).
class Unk_GsPageScript : public AScript
{
public:
    MS2Ptr<Unk_GsList> FUN_140bc7280(const CString& strName);   // 0x140bc7280 list child lookup
};

class Unk_UiDock
{
public:
    int FUN_141b1d3d0();                                        // x
    int FUN_141b1d460();                                        // y
};

// A found stranger as the search result hands it over: a sub-object at +8 describes the character.
class Unk_GsFoundInfo
{
public:
    virtual void vfunc_0() = 0; virtual void vfunc_1() = 0; virtual void vfunc_2() = 0; virtual void vfunc_3() = 0;
    virtual __int64 vfunc_4() = 0;                              // 4 (+0x20) the account / character serial
    virtual void vfunc_5() = 0; virtual void vfunc_6() = 0; virtual void vfunc_7() = 0;
    virtual CStringW vfunc_8() = 0;                             // 8 (+0x40) the name
};
struct Unk_GsFound
{
    __int64 m_unk_00;
    void* m_info;                                               // +0x8 the info sub-object (an Unk_GsFoundInfo; its vfptr)
};
MS2_CHECK_OFFSET(Unk_GsFound, m_info, 0x8);

void* FUN_1409eed90();                                          // the singleton of the own character
CStringTable* FUN_1401a9d70();
CStringW FUN_14028b8e0(const CStringW& strKey);                 // string table text
void FUN_1412751f0(const CStringW& text, int nA, int nB);       // message popup
void FUN_140710590(COutPacket& packet);                         // send the packet
unsigned __int64 FUN_140718370(const CStringW& text);           // text -> number
CStringW FUN_141b71910(__int64 nValue);                         // the number as text
CString FUN_14016a5c0(const char* psz, int n);
CString FUN_141028be0(__int64 nCharSN, const CString& strProfile, int nA, CString strB);   // the profile picture url
int FUN_140900f00();                                            // max invitations
CStringW FUN_1409e94c0(CStringW strKey, const int& nLevel, const CStringW& strJob);
CStringW FUN_14052b9d0(CStringW strKey, const unsigned short& nLevel, const CStringW& strJob);
void FUN_142575b00(void* pMovie, const Scaleform::GFx::Value& v);   // hand a value to the movie
void* FUN_1422bb8b0(int nMovieId);                              // the movie of a UI layer
bool FUN_140a467d0(const MS2Ptr<AScript>& kScript);             // has the AS object been released
unsigned char FUN_1409b0350(Scaleform::GFx::Value* pValue);     // Value::IsNull
MS2Ptr<AScript> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);
Unk_UiDock* FUN_140a7b2b0(int nId);                             // a dialog's position record

CStringW FUN_14028dfa0(CStringW strKey, const fmt::ArgList& args);        // the string table formatter
FMT_VARIADIC_W(CStringW, FUN_14028dfa0, CStringW)

typedef ATL::CAtlArray<CBuddyManager::Ptr> BuddyArray;
typedef ATL::CAtlArray<MS2Ptr<CGuildMember> > GuildArray;

// @0x140fcc860
UIWeddingGuestDialog::UIWeddingGuestDialog()
{
    m_2c = 0x1b;
    FUN_1422dc3b0(1);
    FUN_141924170(1);
    FUN_140fcdc50(PagePtr(new UIWeddingGuestPageFriend(this)));
    FUN_140fcdc50(PagePtr(new UIWeddingGuestPageGuild(this)));
    FUN_140fcdc50(PagePtr(new UIWeddingGuestPageStranger(this)));
}

// @0x140fccab0
UIWeddingGuestDialog::~UIWeddingGuestDialog()
{
}

// @0x140fccb30
CString UIWeddingGuestDialog::vfunc_1()
{
    return "WeddingGuestDialog";
}

// @0x140fccb80
int UIWeddingGuestDialog::vfunc_65()
{
    if (WeddingManager::GetInstance()->FUN_140d295d0()->m_nState == 1)
        return UIDialog::vfunc_65();
    return 0;
}

// @0x140fccbe0
void UIWeddingGuestDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x140fccc00
void UIWeddingGuestDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140fcdcf0();
    if (MS2Ptr<ASTextField> spCounter = FUN_140bb4cf0("m_counter"))
    {
        int nMax = FUN_140fce0a0();
        size_t nCount = m_guests.size();
        spCounter->FUN_1422c4cd0(FUN_14028dfa0(CStringW(L"s_wedding_guest_counter"), nCount, nMax));
    }
}

// @0x140fccd50
void UIWeddingGuestDialog::vfunc_43()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        Unk_UiDock* pRef = FUN_140a7b2b0(0x4e40);
        if (pRef != 0)
        {
            int nX = pRef->FUN_141b1d3d0();
            int nY = pRef->FUN_141b1d460() - 0x50;
            if (nX != -1 && nY != -1)
            {
                pDialog->vfunc_2(5, nY, nX - pDialog->FUN_1422c13b0());
                return;
            }
        }
    }
    ASDialog* pDefault = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDefault != 0)
        pDefault->vfunc_2(1, 0, 0);
}

// @0x140fcce80
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
int UIWeddingGuestDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onAddPage") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            std::map<CString, PagePtr>::iterator it = m_pages.find(data.FUN_1422b8d30());
            if (it != m_pages.end())
            {
                m_spPage = it->second;
                m_spPage->vfunc_1();
            }
        }
        return 1;
    }
    if (_stricmp(szMethod, "onRemovePage") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            std::map<CString, PagePtr>::iterator it = m_pages.find(data.FUN_1422b8d30());
            if (it != m_pages.end())
            {
                m_spPage->vfunc_2();
                m_spPage = 0;
            }
        }
    }
    else
    {
        if (_stricmp(szMethod, "onAdd") == 0)
        {
            UIWeddingInvitationDialog* pInvitation = FUN_140fce870(0x4f8e);
            if (pInvitation != 0)
            {
                std::vector<GuestPtr> guests;
                for (std::map<CStringW, GuestPtr>::iterator it = m_guests.begin(); it != m_guests.end(); ++it)
                    guests.push_back(it->second);
                pInvitation->FUN_140fe5f20(reinterpret_cast<const std::vector<UIWeddingInvitationDialog::GuestPtr>&>(guests));
            }
            vfunc_67();
            return 1;
        }
        if (_stricmp(szMethod, "CanAdd") == 0)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                CStringW strName = data.FUN_1422b8f40();
                unsigned __int64 nFirst = FUN_140718370(data.FUN_1422b8f40());
                unsigned __int64 nSecond = FUN_140718370(data.FUN_1422b8f40());
                int nError = WeddingManager::GetInstance()->CanInvite(nFirst, nSecond, (int)(m_guests.size() + 1));
                if (nError != 0)
                {
                    WeddingManager::GetInstance()->ShowError(nError);
                    FUN_142575b00(FUN_1422bb8b0(m_28), Scaleform::GFx::Value(false));
                    return 1;
                }
                if (!FUN_140fcdf30(strName))
                {
                    FUN_142575b00(FUN_1422bb8b0(m_28), Scaleform::GFx::Value(false));
                    return 1;
                }
                FUN_142575b00(FUN_1422bb8b0(m_28), Scaleform::GFx::Value(true));
            }
            return 1;
        }
    }
    if (m_spPage.get() != 0)
    {
        if (m_spPage->vfunc_4(szMethod, pArgs, nArgs) == true)
            return 1;
    }
    return 0;
}

// @0x140fcd5b0
void UIWeddingGuestDialog::FUN_140fcd5b0(Unk_GsFound* pFound)
{
    GuestPtr spGuest(new WeddingGuest());
    spGuest->m_n20 = ((Unk_GsFoundInfo*)&pFound->m_info)->vfunc_4();
    spGuest->m_n28 = ((Unk_GsFoundInfo*)&pFound->m_info)->vfunc_4();
    spGuest->m_strName = ((Unk_GsFoundInfo*)&pFound->m_info)->vfunc_8();
    spGuest->m_nKind = 2;
    if (spGuest->m_n28 == 0)
    {
        FUN_1412751f0(FUN_14028b8e0(L"s_wedding_result_err_not_find_character"), 1, 1);
    }
    else
    {
        UIWeddingGuestPageStranger* pStranger =
            dynamic_cast<UIWeddingGuestPageStranger*>((UIWeddingGuestPage*)m_spPage);
        if (pStranger != 0)
            pStranger->FUN_140fd88e0(spGuest);
    }
}

// @0x140fcd850
void UIWeddingGuestDialog::FUN_140fcd850(GuestPtr spGuest)
{
    m_guests[spGuest->m_strName] = spGuest;
    if (MS2Ptr<ASTextField> spCounter = FUN_140bb4cf0("m_counter"))
    {
        int nMax = FUN_140fce0a0();
        size_t nCount = m_guests.size();
        spCounter->FUN_1422c4cd0(FUN_14028dfa0(CStringW(L"s_wedding_guest_counter"), nCount, nMax));
    }
}

// @0x140fcd9d0
void UIWeddingGuestDialog::FUN_140fcd9d0(const CStringW& strName)
{
    m_guests.erase(strName);
    if (MS2Ptr<ASTextField> spCounter = FUN_140bb4cf0("m_counter"))
    {
        int nMax = FUN_140fce0a0();
        size_t nCount = m_guests.size();
        spCounter->FUN_1422c4cd0(FUN_14028dfa0(CStringW(L"s_wedding_guest_counter"), nCount, nMax));
    }
}

// @0x140fcdb30
bool UIWeddingGuestDialog::FUN_140fcdb30(const CStringW& strName)
{
    return m_guests.find(strName) != m_guests.end();
}

// @0x140fcdba0
void UIWeddingGuestDialog::FUN_140fcdba0()
{
    m_guests.clear();
    for (std::map<CString, PagePtr>::iterator it = m_pages.begin(); it != m_pages.end(); ++it)
        it->second->vfunc_3();
}

// @0x140fcdc50
void UIWeddingGuestDialog::FUN_140fcdc50(PagePtr spPage)
{
    m_pages[spPage->vfunc_6()] = spPage;
}

// @0x140fcdcf0
void UIWeddingGuestDialog::FUN_140fcdcf0()
{
    if (MS2Ptr<Unk_GsTab> spTab = FUN_140c02870("m_tab"))
    {
        spTab->FUN_1422e3400();
        for (std::map<CString, PagePtr>::iterator it = m_pages.begin(); it != m_pages.end(); ++it)
        {
            ASObj row(2);
            row.FUN_1407cba60("page", it->second->vfunc_6());
            row.FUN_1407cbb20("label", it->second->vfunc_7());
            spTab->FUN_1422e3460(row);
        }
        spTab->FUN_1422e31e0(0);
        spTab->vfunc_24(true);
    }
}

// @0x140fcdf30
bool UIWeddingGuestDialog::FUN_140fcdf30(const CStringW& strName)
{
    int nGuests;                                    // declared first: the exe gives it the first frame slot
    WeddingProxy* pProxy = WeddingManager::GetInstance()->FUN_140d295d0();
    if (strName == pProxy->m_groom.m_strName || strName == pProxy->m_bride.m_strName)
    {
        FUN_1412751f0(FUN_14028b8e0(L"s_wedding_invitation_error_user"), 1, 1);
        return false;
    }
    nGuests = (int)m_guests.size();
    if (nGuests > FUN_140900f00())
    {
        FUN_1412751f0(FUN_14028b8e0(L"s_wedding_invitation_error_max_user"), 1, 1);
        return false;
    }
    return true;
}

// @0x140fce0a0
int UIWeddingGuestDialog::FUN_140fce0a0()
{
    return FUN_140900f00() - WeddingManager::GetInstance()->GetInvitedCount();
}

// @0x140fce870
UIWeddingInvitationDialog* FUN_140fce870(int nId)
{
    if (CUIService::GetInstance() != 0)
    {
        MS2Ptr<UIObject> spObj = CUIService::GetInstance()->FUN_141adcea0((eUIClassID)nId);
        if (spObj.get() != 0)
            return dynamic_cast<UIWeddingInvitationDialog*>((UIObject*)spObj);
    }
    return 0;
}

// ---- the pages ----

// @0x140fd6bc0
UIWeddingGuestPage::UIWeddingGuestPage(UIWeddingGuestDialog* pDialog) : m_pScript(0)
{
    m_pDialog = pDialog;
}

// @0x140fd6c30
UIWeddingGuestPage::~UIWeddingGuestPage()
{
}

// @0x140fd6c70
// MS2-FUNCTIONAL: EH state layout and bool branch codegen differ
bool UIWeddingGuestPage::vfunc_1()
{
    if (FUN_140a467d0(m_pDialog->FUN_1422dba00()))
        return false;
    Scaleform::GFx::Value kPage = m_pDialog->FUN_1422dba00()->FUN_1422baa20("m_currentPage");
    if (FUN_1409b0350(&kPage) != 0)
        return false;
    m_pScript = FUN_140acca70(m_pDialog->FUN_1422db730(), kPage);
    return true;
}

// @0x140fd6dd0
void UIWeddingGuestPage::vfunc_2()
{
    m_pScript = 0;
}

// @0x140fd6e00
void UIWeddingGuestPage::vfunc_3()
{
}

// @0x140fd6e10
bool UIWeddingGuestPage::vfunc_4(const char*, const Scaleform::GFx::Value*, unsigned int)
{
    return false;
}

// @0x140fd6e30
void UIWeddingGuestPage::vfunc_5()
{
}

// @0x140fd6e40
MS2Ptr<AScript> UIWeddingGuestPage::GetScript()
{
    return m_pScript;
}

// @0x140fd6e90
UIWeddingGuestDialog* UIWeddingGuestPage::GetDialog()
{
    return m_pDialog;
}

// ---- friends ----

// @0x140fd6eb0
UIWeddingGuestPageFriend::UIWeddingGuestPageFriend(UIWeddingGuestDialog* pDialog) : UIWeddingGuestPage(pDialog)
{
}

// @0x140fd6ef0
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
bool UIWeddingGuestPageFriend::vfunc_1()
{
    if (!UIWeddingGuestPage::vfunc_1())
        return false;
    BuddyArray buddies;
    CBuddyManager::GetInstance()->FUN_140ae4df0(buddies);
    if (buddies.GetCount() == 0)
        return true;
    if (MS2Ptr<Unk_GsList> spList = static_cast<Unk_GsPageScript*>(m_pScript.operator->())->FUN_140bc7280("m_list"))
    {
        spList->FUN_1422dd1d0();
        for (size_t i = 0; i < buddies.GetCount(); i++)
        {
            CBuddyManager::Ptr spBuddy = buddies[i];
            if (spBuddy->FUN_1401cc5f0() == 0)
                continue;
            ASObj row(2);
            row.FUN_1407cbb20("name", spBuddy->FUN_1401cc1c0());
            row.FUN_1407cbb20("accSN", FUN_141b71910(spBuddy->FUN_1401cc250()));
            row.FUN_1407cbb20("charSN", FUN_141b71910(spBuddy->FUN_1401cc230()));
            row.FUN_1407cbbe0("selected", m_pDialog->FUN_140fcdb30(spBuddy->FUN_1401cc1c0()));
            int nLevel = spBuddy->FUN_1401cc210();
            int nJob = spBuddy->FUN_1401cc2b0();
            row.FUN_1407cbb20("extra", FUN_1409e94c0(CStringW(L"s_wedding_guest_user"), nLevel,
                                                      FUN_1401a9d70()->FUN_141811980(6, nJob)));
            row.FUN_1407cba60("profile", FUN_141028be0(spBuddy->FUN_1401cc230(),
                                                       FUN_14016a5c0((const char*)*spBuddy->FUN_1401cc530(), 0), 1, CString("")));
            spList->FUN_1422dd230(row);
        }
        spList->FUN_1422dcca0(0);
        spList->vfunc_24(true);
    }
    return true;
}

// @0x140fd74b0
CString UIWeddingGuestPageFriend::vfunc_6()
{
    return "PageFriend";
}

// @0x140fd7500
CStringW UIWeddingGuestPageFriend::vfunc_7()
{
    return FUN_14028b8e0(L"s_wedding_guest_tab_friend");
}

// @0x140fd7570
bool UIWeddingGuestPageFriend::vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp(szMethod, "onSelectCheckbox") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            bool bSelected = data.FUN_1422b8a90();
            CStringW strName = data.FUN_1422b8f40();
            CBuddyManager::Ptr spBuddy = CBuddyManager::GetInstance()->FUN_140ae4950(strName);
            if (spBuddy.get() != 0)
            {
                if (!bSelected)
                {
                    m_pDialog->FUN_140fcd9d0(strName);
                }
                else
                {
                    UIWeddingGuestDialog::GuestPtr spGuest(new WeddingGuest());
                    spGuest->m_nKind = 1;
                    spGuest->m_strName = strName;
                    spGuest->m_n28 = spBuddy->FUN_1401cc230();
                    spGuest->m_n20 = spBuddy->FUN_1401cc250();
                    m_pDialog->FUN_140fcd850(spGuest);
                }
            }
            return true;
        }
    }
    return false;
}

// ---- guild ----

// @0x140fd77c0
UIWeddingGuestPageGuild::UIWeddingGuestPageGuild(UIWeddingGuestDialog* pDialog) : UIWeddingGuestPage(pDialog)
{
}

// @0x140fd7800
// MS2-FUNCTIONAL: exe call-result temporaries / frame-slot order differ (source form not found)
bool UIWeddingGuestPageGuild::vfunc_1()
{
    if (!UIWeddingGuestPage::vfunc_1())
        return false;
    GuildArray members;
    CGuildManager::GetInstance()->FUN_1404d0420(&members);
    if (members.GetCount() == 0)
        return true;
    if (MS2Ptr<Unk_GsList> spList = static_cast<Unk_GsPageScript*>(m_pScript.operator->())->FUN_140bc7280("m_list"))
    {
        spList->FUN_1422dd1d0();
        for (size_t i = 0; i < members.GetCount(); i++)
        {
            MS2Ptr<CGuildMember> spMember = members[i];
            ASObj row(2);
            row.FUN_1407cbb20("name", spMember->data.FUN_1404ca890());
            row.FUN_1407cbb20("accSN", FUN_141b71910(spMember->data.f00));
            row.FUN_1407cbb20("charSN", FUN_141b71910(spMember->data.f08));
            row.FUN_1407cbbe0("selected", m_pDialog->FUN_140fcdb30(spMember->data.FUN_1404ca890()));
            row.FUN_1407cbb20("extra", FUN_14052b9d0(CStringW(L"s_wedding_guest_user"), spMember->data.f1c,
                                                      FUN_1401a9d70()->FUN_141811980(6, spMember->data.f18)));
            row.FUN_1407cba60("profile", FUN_141028be0(spMember->data.f08,
                                                       FUN_14016a5c0(spMember->data.FUN_1404ca980(), 0), 1, CString("")));
            spList->FUN_1422dd230(row);
        }
        spList->FUN_1422dcca0(0);
        spList->vfunc_24(true);
    }
    return true;
}

// @0x140fd7dd0
CString UIWeddingGuestPageGuild::vfunc_6()
{
    return "PageGuild";
}

// @0x140fd7e20
CStringW UIWeddingGuestPageGuild::vfunc_7()
{
    return FUN_14028b8e0(L"s_wedding_guest_tab_guild");
}

// @0x140fd7e90
bool UIWeddingGuestPageGuild::vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp(szMethod, "onSelectCheckbox") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            bool bSelected = data.FUN_1422b8a90();
            CStringW strName = data.FUN_1422b8f40();
            MS2Ptr<CGuildMember> spMember = FUN_140fd80e0(strName);
            if (spMember.get() != 0)
            {
                if (!bSelected)
                {
                    m_pDialog->FUN_140fcd9d0(strName);
                }
                else
                {
                    UIWeddingGuestDialog::GuestPtr spGuest(new WeddingGuest());
                    spGuest->m_nKind = 0;
                    spGuest->m_strName = strName;
                    spGuest->m_n28 = spMember->data.f08;
                    spGuest->m_n20 = spMember->data.f00;
                    m_pDialog->FUN_140fcd850(spGuest);
                }
            }
            return true;
        }
    }
    return false;
}

// @0x140fd80e0
MS2Ptr<CGuildMember> UIWeddingGuestPageGuild::FUN_140fd80e0(const CStringW& strName)
{
    GuildArray members;
    CGuildManager::GetInstance()->FUN_1404d0420(&members);
    for (size_t i = 0; i < members.GetCount(); i++)
    {
        if (members[i]->data.FUN_1404ca890() == strName)
            return MS2Ptr<CGuildMember>(members[i]);
    }
    return MS2Ptr<CGuildMember>(0);
}

// @0x140fd8b90
UIWeddingGuestPageFriend::~UIWeddingGuestPageFriend()
{
}

// @0x140fd8bb0
UIWeddingGuestPageGuild::~UIWeddingGuestPageGuild()
{
}

// @0x140fd8bd0
UIWeddingGuestPageStranger::~UIWeddingGuestPageStranger()
{
}

// ---- strangers ----

// @0x140fd8230
UIWeddingGuestPageStranger::UIWeddingGuestPageStranger(UIWeddingGuestDialog* pDialog) : UIWeddingGuestPage(pDialog)
{
}

// @0x140fd8290
bool UIWeddingGuestPageStranger::vfunc_1()
{
    if (!UIWeddingGuestPage::vfunc_1())
        return false;
    if (MS2Ptr<Unk_GsList> spList = static_cast<Unk_GsPageScript*>(m_pScript.operator->())->FUN_140bc7280("m_list"))
    {
        spList->FUN_1422dd1d0();
        for (std::map<CStringW, GuestPtr>::iterator it = m_strangers.begin(); it != m_strangers.end(); ++it)
        {
            GuestPtr spGuest = it->second;
            ASObj row(2);
            row.FUN_1407cbb20("name", CStringW(spGuest->m_strName));
            row.FUN_1407cbb20("accSN", FUN_141b71910(spGuest->m_n20));
            row.FUN_1407cbb20("charSN", FUN_141b71910(spGuest->m_n28));
            row.FUN_1407cbbe0("selected", m_pDialog->FUN_140fcdb30(spGuest->m_strName));
            spList->FUN_1422dd230(row);
        }
        spList->FUN_1422dcca0(0);
        spList->vfunc_24(true);
    }
    return true;
}

// @0x140fd8580
CString UIWeddingGuestPageStranger::vfunc_6()
{
    return "PageStranger";
}

// @0x140fd85d0
CStringW UIWeddingGuestPageStranger::vfunc_7()
{
    return FUN_14028b8e0(L"s_wedding_guest_tab_stranger");
}

// @0x140fd8640
void UIWeddingGuestPageStranger::vfunc_3()
{
    m_strangers.clear();
}

// @0x140fd8670
bool UIWeddingGuestPageStranger::vfunc_4(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (_stricmp(szMethod, "onFind") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strName = data.FUN_1422b8f40();
            COutPacket packet(0xba, 0);
            packet.vfunc_o10_1(0x1b);
            packet.vfunc_o10_8(strName);
            FUN_140710590(packet);
        }
    }
    else if (_stricmp(szMethod, "onSelectCheckbox") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            bool bSelected = data.FUN_1422b8a90();
            CStringW strName = data.FUN_1422b8f40();
            std::map<CStringW, GuestPtr>::iterator it = m_strangers.find(strName);
            if (it != m_strangers.end())
            {
                GuestPtr spGuest = it->second;
                if (bSelected)
                    m_pDialog->FUN_140fcd850(spGuest);
                else
                    m_pDialog->FUN_140fcd9d0(strName);
            }
            return true;
        }
    }
    return true;
}

// @0x140fd88e0
void UIWeddingGuestPageStranger::FUN_140fd88e0(GuestPtr spGuest)
{
    std::map<CStringW, GuestPtr>::iterator it = m_strangers.find(spGuest->m_strName);
    if (it == m_strangers.end())
    {
        m_strangers[spGuest->m_strName] = spGuest;
        ASObj row(2);
        row.FUN_1407cbb20("name", CStringW(spGuest->m_strName));
        row.FUN_1407cbb20("accSN", FUN_141b71910(spGuest->m_n20));
        row.FUN_1407cbb20("charSN", FUN_141b71910(spGuest->m_n28));
        row.FUN_1407cbbe0("selected", m_pDialog->FUN_140fcdb30(spGuest->m_strName));
        m_pScript->Invoke("addUser", row);
    }
}

MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
