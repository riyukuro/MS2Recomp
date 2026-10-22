// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Mentoring: the mentor tab page, the mentor register page, the mission page and the common page base. Field/helper names are inferred.
// MS2-UNIT: client\ms2\uimentoringmentorpage.cpp
// MS2-RANGE: 0x1400ce910-0x1400cecb0 .text$di
// MS2-RANGE: 0x140c71310-0x140c74e70 .text$mn
// MS2-RANGE: 0x142ca3540-0x142ca3690 .text$yd
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVUIMentoringMentorRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140c73200 ; prop
// MS2-PIN: ??_GUIMentoringPage@@UEAAPEAXI@Z 0x140c74e30 ; prop
// MS2-PIN: memmove_s 0x140c728a0 ; unique
// MS2-PIN: ms2_memmove_s_copy2 0x140c733b0 ; unique
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$?0PEAVUIMentoringMentorRegisterPage@@P80@EAA_NHAEBVCMsgBoxData@@@Z$0A@@?$pair@PEAVUIMentoringMentorRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@QEAA@AEBQEAVUIMentoringMentorRegisterPage@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140c72f90 ; unique
// MS2-PIN: ??$?0VUIMentoringMentorRegisterPage@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBQEAVUIMentoringMentorRegisterPage@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140c72fd0 ; unique
// MS2-PIN: ??$?8PEAVUIMentoringMentorRegisterPage@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVUIMentoringMentorRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140c73060 ; unique
// MS2-PIN: ??$forward@AEBQ8UIMentoringMentorRegisterPage@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8UIMentoringMentorRegisterPage@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x140c730b0 ; prop
// MS2-PIN: ??$make_pair@AEBQEAVUIMentoringMentorRegisterPage@@AEBQ81@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA?AU?$pair@PEAVUIMentoringMentorRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@AEBQEAVUIMentoringMentorRegisterPage@@AEBQ82@EAA_NHAEBVCMsgBoxData@@@Z@Z 0x140c730d0 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMentoringMentorRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140c73120 ; unique
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVUIMentoringMentorRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBU?$pair@PEAVUIMentoringMentorRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@Z 0x140c73170 ; unique
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVUIMentoringMentorRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c73280 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVUIMentoringMentorRegisterPage@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c73350 ; unique
// MS2-PIN: ??_EUIMentoringMissionPage@@WDA@EAAPEAXI@Z 0x140c749fc ; unique
// MS2-PIN: ??_GUIMentoringMissionPage@@UEAAPEAXI@Z 0x140c74a10 ; unique
// MS2-PIN: ??4?$MS2Ptr@VAScript@@@@QEAAAEAV0@AEBV0@@Z 0x140c74dd0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimentoringmentorpage.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uimentoringrewardpage.h"
#include "ms2/placeholder/header_statics_a.h"
// Additional original translation-unit header statics in the recovered initializer range.
static CString s_mentorSortNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_mentorSkill2 = "skill";
static CString s_mentorStun2 = "stun";
static Unk_1402a9d70 s_mentorCondition2(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_mentorSortNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
// The mentee/mentor record of one user (a CPtred; +0x30 serial number, names at +0x38/+0x40, icon url at +0x48).
class Unk_MentorEntry : public CPtred
{
public:
    unsigned char m_pad_18[0x18];
    unsigned __int64 m_30;
    CStringW m_38;
    CStringW m_40;
    CStringW m_48;
    int m_50;
    int m_54;
    bool m_58;
};
// The mentoring state kept by the client (singleton DAT_143abb6d8).
class Unk_MentorInfo
{
public:
    int FUN_140b71650();
    MS2Ptr<Unk_MentorEntry> FUN_140b71680(int n);
    int FUN_140b71720();
    int FUN_140b71750();
};
class Unk_MentorRewards { public: int FUN_14069c140(); };
Unk_MentorRewards* FUN_1406c7610();
extern Unk_MentorInfo* DAT_143abb6d8;
class Unk_MentorFlag { public: int FUN_1402c4c90(int); };
class Unk_MentorFlags { public: void* p0; Unk_MentorFlag flags; };
Unk_MentorFlags* FUN_14025e7b0();
class Unk_MentorInviteDialog { public: void FUN_140c2f010(); };
Unk_MentorInviteDialog* FUN_140b6f4c0(int nId);
void FUN_141275260(int, int, int);
class Unk_PartyService { public: void FUN_14162ba50(CStringW strName); };
Unk_PartyService* FUN_1409670d0();
// The popup-menu request (0x80 bytes), built by the ctor at 0x140c302f0 and released by the dtor at 0x140c304c0.
class Unk_PopupMenuInfo
{
public:
    Unk_PopupMenuInfo(float x, float y, int a, int b, int c, CString str, void* p);
    ~Unk_PopupMenuInfo();
private:
    void* m_pad_00; void* m_pad_08; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30;
    void* m_pad_38; void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58; void* m_pad_60; void* m_pad_68;
    void* m_pad_70; void* m_pad_78;
};
class Unk_PopupMenu { public: void FUN_141a7f090(const Unk_PopupMenuInfo& info, const CStringW& strName, unsigned __int64 nSerial, void* p, int b, int c); };
Unk_PopupMenu* FUN_140c30140(int nId);
unsigned __int64 FUN_140718350(const CString& str);
CStringW FUN_14028b8e0(const CStringW& strId);
CStringW FUN_1409e9890(CStringW strFormat, const int& a, const int& b);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
// AS helpers on the page's script and the clips it hands out.
class Unk_MentorScript : public AScript
{
public:
    MS2Ptr<ASMovieClip> FUN_1409b4560(const CString& strName);          // bind a movie clip child
    MS2Ptr<ASMovieClip> FUN_140accfb0(const CString& strName);          // bind a movie clip child (list clip)
};
void FUN_140bf2260(Scaleform::GFx::Value& v);                            // clear an AS object
CString FUN_141028be0(unsigned __int64 nSerial, const CString& strPath, int n, CString strExtra);   // profile image url
CString FUN_14016a600(const wchar_t* sz, int n);                         // wide to narrow
CString FUN_140719530(unsigned __int64 n);                               // number to string
class Unk_1401a9d70 { public: CStringW FUN_141811980(int nCategory, int nId); };      // localized names
Unk_1401a9d70* FUN_1401a9d70();
CStringW FUN_14052b9d0(CStringW strFormat, const CStringW& a, const CStringW& b);

// @0x140c70240 (mentee unit)
Unk_MentorInfo* FUN_140c70240();

// ============================================================================
// ASMentoringMentorPage / UIMentoringMentorPage
// ============================================================================

// @0x140c71310
ASMentoringMentorPage::ASMentoringMentorPage(UIMentoringPage* p) : m_owner(p) {}
// @0x140c71390
ASMentoringMentorPage::~ASMentoringMentorPage() {}

// @0x140c713e0
void ASMentoringMentorPage::OnInit()
{
    if (!m_owner) return;
    m_script = m_owner->GetScript();
    do
    {
        m_script->FUN_140beaf20("m_coin", m_coin);
        if (m_coin == 0)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError", MS2_THIS_FILE, MS2_LINE(30), __FUNCTION__));
    } while (0);
    Refresh();
}

// @0x140c71610
void ASMentoringMentorPage::Refresh()
{
    if (!FUN_1406c7610()) return;
    int nMentor = FUN_140c70240()->FUN_140b71650();
    int nReward = FUN_1406c7610()->FUN_14069c140();
    m_coin->FUN_1422c4cd0(FUN_1409e9890(L"s_mentoring_coin_info", nMentor, nReward));
}

// @0x140c716e0
UIMentoringMentorPage::UIMentoringMentorPage(UIMentoringDialog* p) : UIMentoringPage(p) {}
// @0x140c71740
UIMentoringMentorPage::~UIMentoringMentorPage() {}

// @0x140c71780
int UIMentoringMentorPage::vfunc_1()
{
    if (!UIMentoringPage::vfunc_1()) return 0;
    m_mentor = new ASMentoringMentorPage(this);
    m_mentor->OnInit();
    FUN_140c71ce0();
    return 1;
}

// @0x140c71830
void UIMentoringMentorPage::vfunc_2()
{
    UIMentoringPage::vfunc_2();
    m_mentor = 0;
}

// @0x140c71870
int UIMentoringMentorPage::vfunc_5(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (UIMentoringPage::vfunc_5(szMethod, pArgs, nArgs)) return 1;
    if (_stricmp(szMethod, "onOpenInviteMentoPage") == 0)
    {
        if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x41) != 0)
        {
            FUN_141275260(0x2f7, 1, 1);
            return 1;
        }
        Unk_MentorInviteDialog* pDlg = FUN_140b6f4c0(0x4f4c);
        if (pDlg) pDlg->FUN_140c2f010();
        return 1;
    }
    else if (_stricmp(szMethod, "onPartyRequest") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1409670d0()->FUN_14162ba50(data.FUN_1422b8f40());
    }
    else if (_stricmp(szMethod, "OnPopupMenu") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            float x = data.FUN_1422b8c10();
            float y = data.FUN_1422b8c10();
            CStringW strName = data.FUN_1422b8f40();
            unsigned __int64 nSerial = FUN_140718350(data.FUN_1422b8d30());
            Unk_PopupMenu* pMenu = FUN_140c30140(0x4e39);
            if (pMenu)
            {
                Unk_PopupMenuInfo info(x, y, 3, 10, 0, "", NULL);
                pMenu->FUN_141a7f090(info, strName, nSerial, NULL, 0, 1);
            }
        }
        return 1;
    }
    return 0;
}

// @0x140c71bd0
CString UIMentoringMentorPage::vfunc_6() { return "MentorPage"; }

// @0x140c71c20
CStringW UIMentoringMentorPage::vfunc_7() { return FUN_14028b8e0(L"s_mentoring_tab_mentor"); }

// @0x140c71c90
void UIMentoringMentorPage::vfunc_9() { if (m_mentor.get()) m_mentor->Refresh(); }

// @0x140c71ce0
void UIMentoringPage::FUN_140c71ce0()
{
    int nShown = FUN_140c70240()->FUN_140b71720();
    FUN_140c71ee0("m_mentee1", FUN_140c70240()->FUN_140b71680(0), nShown ? 1 : 0);
    FUN_140c71ee0("m_mentee2", FUN_140c70240()->FUN_140b71680(1), nShown ? 1 : 0);
    FUN_140c71ee0("m_mentee3", FUN_140c70240()->FUN_140b71680(2), nShown ? 1 : 0);
}

// @0x140c71ee0
// MS2-FUNCTIONAL: m_searchMovie lookup temp order / frame layout differs from exe
void UIMentoringPage::FUN_140c71ee0(CString strName, MS2Ptr<Unk_MentorEntry> pEntry, int bVisible)
{
    Unk_MentorScript* pScript = reinterpret_cast<Unk_MentorScript*>(m_script.operator->());
    MS2Ptr<ASMovieClip> pClip = pScript->FUN_140accfb0(strName);
    if (pClip.get())
    {
        ASObj obj(2);
        if (pEntry.get() != 0)
        {
            obj.FUN_1407cba60("iconPath", FUN_141028be0(pEntry->m_30, FUN_14016a600(pEntry->m_48, 0), 1, ""));
            obj.FUN_1407cbbe0("isOnline", pEntry->m_58);
            obj.FUN_1407cbb20("name", pEntry->m_38);
            obj.FUN_1407cbb20("extra", FUN_14052b9d0(L"s_mentoring_user_info", pEntry->m_40, FUN_1401a9d70()->FUN_141811980(6, pEntry->m_54)));
            obj.FUN_1407cbb20("charName", pEntry->m_38);
            obj.FUN_1407cba60("charSN", FUN_140719530(pEntry->m_30));
        }
        else
        {
            FUN_140bf2260(obj.FUN_1422bb870());
        }
        pClip->Invoke("setData", obj);
        pClip->vfunc_3(bVisible);
    }
    MS2Ptr<ASMovieClip> pSearchMovie = pScript->FUN_1409b4560("m_searchMovie");
    if (pSearchMovie.get())
    {
        int nHidden = FUN_140c70240()->FUN_140b71720();
        pSearchMovie->vfunc_4(nHidden == 0);
        FUN_140cfee80((*pSearchMovie).FUN_1422bb890(), "m_desc", FUN_14028b8e0(L"s_mentoring_tab_mentor_search_desc"));
    }
    MS2Ptr<ASMovieClip> pSearch = pScript->FUN_1409b4560("m_search");
    if (pSearch.get())
    {
        int nHidden = FUN_140c70240()->FUN_140b71720();
        pSearch->vfunc_4(nHidden < 3);
    }
}

// ============================================================================
// UIMentoringMentorRegisterPage
// ============================================================================

// The player actor (RTTI unknown): slot 77 returns the character name.
class Unk_MentorActorV
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4();
    virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24();
    virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29();
    virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34();
    virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40(); virtual void vfunc_41(); virtual void vfunc_42(); virtual void vfunc_43(); virtual void vfunc_44();
    virtual void vfunc_45(); virtual void vfunc_46(); virtual void vfunc_47(); virtual void vfunc_48(); virtual void vfunc_49();
    virtual void vfunc_50(); virtual void vfunc_51(); virtual void vfunc_52(); virtual void vfunc_53(); virtual void vfunc_54();
    virtual void vfunc_55(); virtual void vfunc_56(); virtual void vfunc_57(); virtual void vfunc_58(); virtual void vfunc_59();
    virtual void vfunc_60(); virtual void vfunc_61(); virtual void vfunc_62(); virtual void vfunc_63(); virtual void vfunc_64();
    virtual void vfunc_65(); virtual void vfunc_66(); virtual void vfunc_67(); virtual void vfunc_68(); virtual void vfunc_69();
    virtual void vfunc_70(); virtual void vfunc_71(); virtual void vfunc_72(); virtual void vfunc_73(); virtual void vfunc_74();
    virtual void vfunc_75(); virtual void vfunc_76();
    virtual CStringW GetName();     // 77 (+0x268)
};
class Unk_MentorWorldV { public: Unk_MentorActorV* FUN_141bd0cc0(); };
Unk_MentorWorldV* FUN_1403ed2d0();
// The event schedule (singleton chain 0x140302b00 -> 0x14041d160): start/end of the registration period.
class Unk_MentorIdArray;
class Unk_MentorSchedule { public: __int64 FUN_140424e60(); __int64 FUN_140424e20(); void FUN_140424ed0(Unk_MentorIdArray& ids); };
class Unk_MentorScheduleHolder { public: Unk_MentorSchedule* FUN_14041d160(); };
Unk_MentorScheduleHolder* FUN_140302b00();

CStringW FUN_140c70b70(CStringW strFormat, const int& nStartYear, const int& nStartMonth, const int& nStartDay, const int& nEndYear, const int& nEndMonth, const int& nEndDay, const CStringW& strName);
class Unk_MentorChat { public: void FUN_1416fb340(CStringW& strText); };
Unk_MentorChat* FUN_1403b4750();
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
void FUN_140710590(COutPacket& pkt);
void FUN_141a024a0(CMsgBoxData* pBox, bool b);
// The register role byte (ctor 0x140c731c0 always stores 8).
class Unk_MentorRole
{
public:
    Unk_MentorRole() { m_nRole = 8; }       // @0x140c731c0
    void FUN_14069a4e0(COutPacket& pkt);
private:
    char m_nRole;
};

// @0x140c728a0
MS2_EMIT_CRT_MEMMOVE_S();

// @0x140c729c0
UIMentoringMentorRegisterPage::UIMentoringMentorRegisterPage(UIMentoringDialog* p) : UIMentoringPage(p) {}
// @0x140c72a00
UIMentoringMentorRegisterPage::~UIMentoringMentorRegisterPage() {}

// @0x140c72a30
int UIMentoringMentorRegisterPage::vfunc_1()
{
    if (UIMentoringPage::vfunc_1() == 0) return 0;
    return 1;
}

// @0x140c72a60
void UIMentoringMentorRegisterPage::vfunc_2()
{
    UIMentoringPage::vfunc_2();
}

// @0x140c72a80
// MS2-FUNCTIONAL: temp spill layout differs from exe
int UIMentoringMentorRegisterPage::vfunc_5(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (UIMentoringPage::vfunc_5(szMethod, pArgs, nArgs)) return 1;
    if (_stricmp(szMethod, "onRegister") == 0)
    {
        Unk_MentorActorV* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pActor == 0) return 1;
        CMsTime tStart(FUN_140302b00()->FUN_14041d160()->FUN_140424e60());
        CMsTime tEnd(FUN_140302b00()->FUN_14041d160()->FUN_140424e20());
        int nStartYear, nStartMonth, nStartDay, nEndYear, nEndMonth, nEndDay;
        nEndDay = tEnd.GetDay();
        nEndMonth = tEnd.GetMonth();
        nEndYear = tEnd.GetYear();
        nStartDay = tStart.GetDay();
        nStartMonth = tStart.GetMonth();
        nStartYear = tStart.GetYear();
        CStringW strMsg = FUN_140c70b70(L"s_mentoring_mentor_register_warn", nStartYear, nStartMonth, nStartDay, nEndYear, nEndMonth, nEndDay, pActor->GetName());
        FUN_1403b4750()->FUN_1416fb340(strMsg);
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, CStringW(strMsg), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                FUN_141a024a0(spBox.get(), false);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMentoringMentorRegisterPage::SendMentor));
                FUN_140d73c60(spBox);
            }
        }
        return 1;
    }
    return 0;
}

// @0x140c72e50
CString UIMentoringMentorRegisterPage::vfunc_6() { return "MentorRegisterPage"; }

// @0x140c72ea0
CStringW UIMentoringMentorRegisterPage::vfunc_7() { return FUN_14028b8e0(L"s_mentoring_tab_register_mentor"); }

// @0x140c72f10
bool UIMentoringMentorRegisterPage::SendMentor(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0) return true;
    COutPacket pkt(0xa1, 0);
    Unk_MentorRole role;
    role.FUN_14069a4e0(pkt);
    FUN_140710590(pkt);
    return true;
}


// ============================================================================
// UIMentoringMissionPage
// ============================================================================

// The quest event manager: registers the listener that is told about quest changes.
class Unk_MentorQuestManager
{
public:
    void FUN_141aa87c0(UIQuestEventListener*);
    void FUN_141aa8850(UIQuestEventListener*);
};
Unk_MentorQuestManager* FUN_140bfc4b0();
// The quest record (a CPtred-like object; +0x358 the mission day, +0x360 the icon name).
class Unk_MentorQuest
{
public:
    unsigned char m_pad_00[0x358];
    int m_nDay;
    CString m_strIcon;
};
MS2_CHECK_OFFSET(Unk_MentorQuest, m_nDay, 0x358);
MS2_CHECK_OFFSET(Unk_MentorQuest, m_strIcon, 0x360);
// The 16-byte smart pointer to a quest record.
class Unk_MentorQuestPtr
{
public:
    ~Unk_MentorQuestPtr();                  // 0x14064d3e0
    bool IsNull() const;                    // 0x14064d4e0
    Unk_MentorQuest* operator->() const;    // 0x14064d520
    Unk_MentorQuest* get() const;           // 0x1407476a0
private:
    void* m_0; void* m_8;
};
MS2_CHECK_SIZE(Unk_MentorQuestPtr, 0x10);
Unk_MentorQuestPtr FUN_14074bc40(int nQuest);
int FUN_14074b030(Unk_MentorQuest* pQuest);
// The quest progress sub-object of an instance (slot table at +0x18 of the instance).
class Unk_MentorProgress
{
public:
    virtual Unk_MentorQuestPtr vfunc_0();   // the quest record
    virtual int vfunc_1();                  // satisfied
    virtual void vfunc_2();
    virtual int vfunc_3();                  // completed
    virtual __int64 vfunc_4();              // the start time
};
// A running quest instance.
class Unk_MentorInstance
{
public:
    unsigned char m_pad_00[0x18];
    Unk_MentorProgress m_progress;
};
MS2_CHECK_OFFSET(Unk_MentorInstance, m_progress, 0x18);
int FUN_140bfc580(Unk_MentorInstance* pInst);
// The 16-byte smart pointer to a quest instance.
class Unk_MentorInstPtr
{
public:
    ~Unk_MentorInstPtr();                   // 0x140747580
    bool IsNull() const;                    // 0x1407475b0
    Unk_MentorInstance* get() const;        // 0x140747690
    Unk_MentorInstance* operator->() const; // 0x1407476b0
private:
    void* m_0; void* m_8;
};
MS2_CHECK_SIZE(Unk_MentorInstPtr, 0x10);
// The quest state (member +0x10 of the global at FUN_140764020).
class Unk_MentorQuestState
{
public:
    virtual Unk_MentorInstPtr vfunc_0(int nQuest);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual Unk_MentorInstPtr vfunc_3(int nQuest);      // the instance of a quest
    int FUN_1407456d0(int nQuest);
};
class Unk_MentorQuestGlobal { public: void* m_0; void* m_8; Unk_MentorQuestState state; };
Unk_MentorQuestGlobal* FUN_140764020();
// A CAtlArray<int> of quest ids.
class Unk_MentorIdArray
{
public:
    Unk_MentorIdArray();                    // 0x140181d30
    ~Unk_MentorIdArray();                   // 0x140183460
    size_t FUN_140186270() const;           // the count
    int* FUN_140184510(size_t n);           // element
    void FUN_1401855a0(int n);              // add
private:
    void* m_pad[4];
};
// The list control of the mission swf (the AS list with clear / append and a slot table).
class Unk_MentorList : public AScript
{
public:
    virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(bool bRefresh);
    void FUN_1422dd1d0();                                           // clear
    void FUN_1422dd230(const ASObj& row);                           // append a row
};
// The tab control of the mission swf.
class Unk_MentorTab : public AScript { public: int FUN_1422e3210(); };      // the selected tab index
// The page script (a movie clip root) with the children it hands out.
class Unk_MentorMissionScript : public AScript
{
public:
    MS2Ptr<Unk_MentorList> FUN_140bc7280(const CString& strName);
    MS2Ptr<Unk_MentorTab> FUN_140be23c0(const CString& strName);
    Scaleform::GFx::Value FUN_1409ba0d0(const char* szMethod, int a1, int a2);
};
unsigned char FUN_1409b0350(Scaleform::GFx::Value* pValue);
MS2Ptr<AScript> FUN_140acca70(int nMovieId, const Scaleform::GFx::Value& v);
bool FUN_140184310(const CString& strText, const char* szCompare);
bool FUN_140841300(const CStringW& strText, const char* szCompare);
int FUN_140718170(const CString& str);
CStringW FUN_1405c2690(CStringW strKey, const CStringW& strArg);
CStringW FUN_1416e5350(int nQuest, int n);
CStringW FUN_1409404f0(__int64 n);
__int64 FUN_140761ba0(int nQuest, int n);
int FUN_140761e40(int nQuest, int n);
CStringW FUN_140763e10(int n);
__int64 FUN_140869440();
void FUN_140e5ec30(UIMentoringDialog* pDlg);

// @0x140c733b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);

// @0x140c734d0
UIMentoringMissionPage::UIMentoringMissionPage(UIMentoringDialog* p) : UIMentoringPage(p) {}
// @0x140c73540
UIMentoringMissionPage::~UIMentoringMissionPage() {}

// @0x140c73590
int UIMentoringMissionPage::vfunc_1()
{
    if (!UIMentoringPage::vfunc_1()) return 0;
    if (!m_script) return 0;
    FUN_140bfc4b0()->FUN_141aa87c0(this);
    int nDay = -1;
    __int64 nStart = FUN_140c74720();
    if (nStart != 0)
    {
        CMsTime now(FUN_140869440());
        for (int i = 0; i < 7; i++)
        {
            CMsTime tDay(nStart);
            AddDays(tDay, i + 1);
            TruncateToDay(tDay);
            if (now.Get() < tDay.Get())
            {
                nDay = i;
                break;
            }
        }
        if (nDay == -1) nDay = 6;
        m_script->Invoke("setDay", nDay + 1);
    }
    FUN_140c74970();
    return 1;
}

// @0x140c73730
void UIMentoringMissionPage::vfunc_2()
{
    UIMentoringPage::vfunc_2();
    FUN_140bfc4b0()->FUN_141aa8850(this);
}

// @0x140c73790
void UIMentoringMissionPage::vfunc_3(Scaleform::GFx::Value* pOut, const CString& strMethod, ASData* pArgs)
{
    UIMentoringPage::vfunc_3(pOut, strMethod, pArgs);
    if (FUN_140184310(strMethod, "getTabTooltip"))
    {
        int nDay = FUN_140718170(pArgs->FUN_1422b8d30());
        CMsTime now(FUN_140869440());
        CMsTime tDay(FUN_140c74720());
        AddDays(tDay, nDay);
        TruncateToDay(tDay);
        if (tDay.Get() > now.Get())
        {
            ATL::CTimeSpan span = tDay - now;
            CStringW strRemain = FormatTimeSpan(span, true, true, true, true);
            ASTooltip tip(2);
            if (tip.FUN_1409e26b0(FUN_1405c2690(CStringW(L"s_mentoring_remain_time_from_day"), strRemain)))
                *pOut = tip.FUN_1422bb870();
        }
    }
}

// @0x140c739c0
void UIMentoringMissionPage::vfunc_4(Scaleform::GFx::Value* pOut, ASData* pArgs)
{
    UIMentoringPage::vfunc_4(pOut, pArgs);
    CStringW strName = pArgs->FUN_1422b8f40();
    if (FUN_140841300(strName, "guide"))
    {
        int nQuest = pArgs->FUN_1422b8b10();
        Unk_MentorQuestPtr spQuest = FUN_14074bc40(nQuest);
        if (spQuest.get() != 0)
        {
            Unk_MentorActorV* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pActor == 0) return;
            ASTooltip tip(2);
            if (tip.FUN_1409e26b0(FUN_1409404f0(FUN_140761ba0(nQuest, 1))))
            {
                tip.FUN_1409c6dc0(1);
                *pOut = tip.FUN_1422bb870();
            }
        }
    }
    else if (FUN_140841300(strName, "menteeCoin"))
    {
        int nQuest = pArgs->FUN_1422b8b10();
        Unk_MentorQuestPtr spQuest = FUN_14074bc40(nQuest);
        if (spQuest.get() != 0)
        {
            Unk_MentorActorV* pActor = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pActor == 0) return;
            ASTooltip tip(2);
            if (tip.FUN_1409e26b0(FUN_140763e10(FUN_140761e40(nQuest, 1))))
            {
                tip.FUN_1409c6dc0(1);
                *pOut = tip.FUN_1422bb870();
            }
        }
    }
}

// @0x140c73ca0
int UIMentoringMissionPage::vfunc_5(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (UIMentoringPage::vfunc_5(szMethod, pArgs, nArgs)) return 1;
    if (_stricmp(szMethod, "onChangeOpeningDay") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nDay = data.FUN_1422b8a10();
            FUN_140c74450(nDay + 1);
        }
    }
    else if (_stricmp(szMethod, "onReceiveItem") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            int nQuest = data.FUN_1422b8b10();
            COutPacket pkt(0x29, 0);
            pkt.Encode1(0x1d);
            pkt.Encode4(nQuest);
            FUN_140710590(pkt);
        }
    }
    return 0;
}

// @0x140c73e30
CString UIMentoringMissionPage::vfunc_6() { return "MissionPage"; }

// @0x140c73e80
CStringW UIMentoringMissionPage::vfunc_7() { return FUN_14028b8e0(L"s_mentoring_tab_mission"); }

// @0x140c73ef0
void UIMentoringMissionPage::vfunc_o178_11(void* p)
{
    if (p == 0) return;
    Unk_MentorQuestPtr spQuest = (&static_cast<Unk_MentorInstance*>(p)->m_progress)->vfunc_0();
    if (spQuest.IsNull()) return;
    int nDay = spQuest->m_nDay;
    if (nDay != FUN_140c74660()) return;
    FUN_140c74450(nDay);
    FUN_140e5ec30(m_owner);
    FUN_140c74970();
}

// @0x140c73fe0
int UIMentoringMissionPage::vfunc_8()
{
    int nCount = 0;
    Unk_MentorIdArray ids;
    FUN_140c74850(ids, -1);
    for (size_t i = 0; i < ids.FUN_140186270(); i++)
    {
        if (FUN_140764020()->state.FUN_1407456d0(*ids.FUN_140184510(i)) != 0) nCount++;
    }
    return nCount;
}

// @0x140c740a0
int UIMentoringMissionPage::vfunc_10(int nDay)
{
    int nCount = 0;
    Unk_MentorIdArray ids;
    FUN_140c74850(ids, nDay);
    for (size_t i = 0; i < ids.FUN_140186270(); i++)
    {
        if (FUN_140764020()->state.FUN_1407456d0(*ids.FUN_140184510(i)) != 0) nCount++;
    }
    return nCount;
}

// @0x140c74170
// MS2-FUNCTIONAL: temp spill layout differs from exe
void UIMentoringMissionPage::FUN_140c74170(ASObj& obj, Unk_MentorInstance* pInst)
{
    if (pInst == 0) return;
    Unk_MentorQuestPtr spQuest = (&pInst->m_progress)->vfunc_0();
    if (spQuest.IsNull()) return;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0) return;
    CString strIcon = (&pInst->m_progress)->vfunc_0()->m_strIcon;
    CStringW strDesc = FUN_1416e5350(FUN_140bfc580(pInst), 0);
    strDesc.Replace(L"#5c2b00", L"#000000");
    obj.FUN_1409c0d20("id", FUN_140bfc580(pInst));
    obj.FUN_1407cba60("icon", strIcon);
    obj.FUN_1407cbb20("desc", strDesc);
    obj.FUN_1407cb9c0("satisfied", (&pInst->m_progress)->vfunc_1());
    obj.FUN_1407cb9c0("completed", (&pInst->m_progress)->vfunc_3());
    obj.FUN_1409c1180("exp", FUN_140761ba0(FUN_140bfc580(pInst), 1));
}

// @0x140c74450
// MS2-FUNCTIONAL: literal CString temp is built after operator-> in ours, before it in exe
void UIMentoringMissionPage::FUN_140c74450(int nDay)
{
    MS2Ptr<Unk_MentorList> spList = reinterpret_cast<Unk_MentorMissionScript*>(m_script.operator->())->FUN_140bc7280("m_missionList");
    if (spList.get() != 0)
    {
        spList->FUN_1422dd1d0();
        Unk_MentorIdArray ids;
        FUN_140c74850(ids, nDay);
        for (size_t i = 0; i < ids.FUN_140186270(); i++)
        {
            Unk_MentorInstPtr spInst = (&FUN_140764020()->state)->vfunc_3(*ids.FUN_140184510(i));
            if (!spInst.IsNull())
            {
                ASObj obj(2);
                FUN_140c74170(obj, spInst.get());
                spList->FUN_1422dd230(obj);
            }
        }
        spList->vfunc_24(true);
    }
}

// @0x140c74660
// MS2-FUNCTIONAL: literal CString temp is built after operator-> in ours, before it in exe
int UIMentoringMissionPage::FUN_140c74660()
{
    MS2Ptr<Unk_MentorTab> spTab = reinterpret_cast<Unk_MentorMissionScript*>(m_script.operator->())->FUN_140be23c0("m_tab");
    if (spTab.get() == 0) return 0;
    return spTab->FUN_1422e3210() + 1;
}

// @0x140c74720
__int64 UIMentoringMissionPage::FUN_140c74720()
{
    Unk_MentorIdArray ids;
    FUN_140c74850(ids, -1);
    for (size_t i = 0; i < ids.FUN_140186270(); i++)
    {
        Unk_MentorInstPtr spInst = (&FUN_140764020()->state)->vfunc_3(*ids.FUN_140184510(i));
        if (spInst.get() != 0) return (&spInst->m_progress)->vfunc_4();
    }
    return 0;
}

// @0x140c74850
// MS2-FUNCTIONAL: loop branch shape differs from exe
void UIMentoringMissionPage::FUN_140c74850(Unk_MentorIdArray& ids, int nDay)
{
    Unk_MentorIdArray all;
    FUN_140302b00()->FUN_14041d160()->FUN_140424ed0(all);
    for (size_t i = 0; i < all.FUN_140186270(); i++)
    {
        Unk_MentorQuestPtr spQuest = FUN_14074bc40(*all.FUN_140184510(i));
        if (!spQuest.IsNull())
        {
            if (nDay != -1 && spQuest->m_nDay != nDay) continue;
            ids.FUN_1401855a0(FUN_14074b030(spQuest.operator->()));
        }
    }
}

// @0x140c74970
// MS2-FUNCTIONAL: register choice for m_script operator-> differs
void UIMentoringMissionPage::FUN_140c74970()
{
    for (int i = 0; i < 7; i++)
    {
        int nCount = vfunc_10(i + 1);
        reinterpret_cast<Unk_MentorMissionScript*>(m_script.operator->())->FUN_1409ba0d0("setCount", i, nCount);
    }
}

// ============================================================================
// UIMentoringPage (the common base)
// ============================================================================

// @0x140c74a50
UIMentoringPage::UIMentoringPage(UIMentoringDialog* p) : m_script(0), m_owner(p) {}
// @0x140c74ac0
UIMentoringPage::~UIMentoringPage() {}

// @0x140c74b00
// MS2-FUNCTIONAL: temp/branch layout differs from exe
int UIMentoringPage::vfunc_1()
{
    if (m_owner->FUN_1422dba00().IsNull()) return 0;
    Scaleform::GFx::Value tab = m_owner->FUN_1422dba00()->FUN_1422baa20("m_currentTab");
    if (FUN_1409b0350(&tab)) return 0;
    m_script = FUN_140acca70(m_owner->FUN_1422db730(), tab);
    return 1;
}

// @0x140c74c70
void UIMentoringPage::vfunc_2() { m_script = 0; }
// @0x140c74ca0
void UIMentoringPage::vfunc_3(Scaleform::GFx::Value*, const CString&, ASData*) {}
// @0x140c74cc0
void UIMentoringPage::vfunc_4(Scaleform::GFx::Value*, ASData*) {}
// @0x140c74ce0
int UIMentoringPage::vfunc_5(const char*, const Scaleform::GFx::Value*, unsigned) { return 0; }
// @0x140c74d00
CStringW UIMentoringPage::vfunc_7() { return L""; }
// @0x140c74d50
int UIMentoringPage::vfunc_8() { return 0; }
// @0x140c74d60
void UIMentoringPage::vfunc_9() {}
// @0x140c74d70
MS2Ptr<AScript> UIMentoringPage::GetScript() { return m_script; }
// @0x140c74dc0
UIMentoringDialog* UIMentoringPage::GetOwner() { return m_owner; }

// ---- hooks ----
MS2_REPLACE_METHOD(0x140C713E0, ASMentoringMentorPage, OnInit, 515, 0xC15AD1B1);
MS2_REPLACE_METHOD(0x140C71610, ASMentoringMentorPage, Refresh, 187, 0x5BE2EEEE);
MS2_REPLACE_METHOD(0x140C71780, UIMentoringMentorPage, vfunc_1, 167, 0x13F8728B);
MS2_REPLACE_METHOD(0x140C71830, UIMentoringMentorPage, vfunc_2, 43, 0x131686CC);
MS2_REPLACE_METHOD(0x140C71870, UIMentoringMentorPage, vfunc_5, 850, 0x27B2D9DF);
MS2_REPLACE_METHOD(0x140C71BD0, UIMentoringMentorPage, vfunc_6, 61, 0xBA8CE2A8);
MS2_REPLACE_METHOD(0x140C71C20, UIMentoringMentorPage, vfunc_7, 97, 0xBF7ACFA2);
MS2_REPLACE_METHOD(0x140C71C90, UIMentoringMentorPage, vfunc_9, 61, 0x5C6182CD);
MS2_REPLACE_METHOD(0x140C71CE0, UIMentoringPage, FUN_140c71ce0, 499, 0x7B6F697B);
MS2_REPLACE_METHOD(0x140C71EE0, UIMentoringPage, FUN_140c71ee0, 1766, 0xAFD58377);
MS2_REPLACE_METHOD(0x140C72A30, UIMentoringMentorRegisterPage, vfunc_1, 37, 0x784BBF91);
MS2_REPLACE_METHOD(0x140C72A60, UIMentoringMentorRegisterPage, vfunc_2, 24, 0xF6A3D77E);
MS2_REPLACE_METHOD(0x140C72A80, UIMentoringMentorRegisterPage, vfunc_5, 969, 0xEE03CA94);
MS2_REPLACE_METHOD(0x140C72E50, UIMentoringMentorRegisterPage, vfunc_6, 61, 0x94AF945E);
MS2_REPLACE_METHOD(0x140C72EA0, UIMentoringMentorRegisterPage, vfunc_7, 97, 0xB74C2263);
MS2_REPLACE_METHOD(0x140C72F10, UIMentoringMentorRegisterPage, SendMentor, 120, 0x23D6C3AB);
MS2_REPLACE_METHOD(0x140C73590, UIMentoringMissionPage, vfunc_1, 405, 0x6054B35C);
MS2_REPLACE_METHOD(0x140C73730, UIMentoringMissionPage, vfunc_2, 75, 0x4A8190D1);
MS2_REPLACE_METHOD(0x140C73790, UIMentoringMissionPage, vfunc_3, 550, 0x33441F61);
MS2_REPLACE_METHOD(0x140C739C0, UIMentoringMissionPage, vfunc_4, 728, 0xC836224B);
MS2_REPLACE_METHOD(0x140C73CA0, UIMentoringMissionPage, vfunc_5, 385, 0xB2806B63);
MS2_REPLACE_METHOD(0x140C73E30, UIMentoringMissionPage, vfunc_6, 61, 0x7533E969);
MS2_REPLACE_METHOD(0x140C73E80, UIMentoringMissionPage, vfunc_7, 97, 0xAACFA5D3);
MS2_REPLACE_METHOD_VIA(0x140C73EF0, UIMentoringMissionPage, UIQuestEventListener, vfunc_o178_11, 227, 0xD2C1B5C3);
MS2_REPLACE_METHOD(0x140C73FE0, UIMentoringMissionPage, vfunc_8, 186, 0x3DE0CA34);
MS2_REPLACE_METHOD(0x140C740A0, UIMentoringMissionPage, vfunc_10, 189, 0x4B027290);
MS2_REPLACE_METHOD(0x140C74170, UIMentoringMissionPage, FUN_140c74170, 717, 0xEFCF1A02);
MS2_REPLACE_METHOD(0x140C74450, UIMentoringMissionPage, FUN_140c74450, 511, 0x752DAA43);
MS2_REPLACE_METHOD(0x140C74660, UIMentoringMissionPage, FUN_140c74660, 180, 0x1F04C68F);
MS2_REPLACE_METHOD(0x140C74720, UIMentoringMissionPage, FUN_140c74720, 298, 0x5716421C);
MS2_REPLACE_METHOD(0x140C74850, UIMentoringMissionPage, FUN_140c74850, 278, 0x34DC19D5);
MS2_REPLACE_METHOD(0x140C74970, UIMentoringMissionPage, FUN_140c74970, 138, 0x5E946BD8);
MS2_REPLACE_METHOD(0x140C74B00, UIMentoringPage, vfunc_1, 353, 0xA183C836);
MS2_REPLACE_METHOD(0x140C74C70, UIMentoringPage, vfunc_2, 33, 0x3667108A);
MS2_REPLACE_METHOD(0x140C74CA0, UIMentoringPage, vfunc_3, 21, 0x3C2C5B86);
MS2_REPLACE_METHOD(0x140C74CC0, UIMentoringPage, vfunc_4, 16, 0xB7F2802D);
MS2_REPLACE_METHOD(0x140C74CE0, UIMentoringPage, vfunc_5, 23, 0x192A1B0B);
MS2_REPLACE_METHOD(0x140C74D00, UIMentoringPage, vfunc_7, 61, 0xF1E0C4FD);
MS2_REPLACE_METHOD(0x140C74D50, UIMentoringPage, vfunc_8, 8, 0x7F371472);
MS2_REPLACE_METHOD(0x140C74D60, UIMentoringPage, vfunc_9, 6, 0xA9AF6E37);
MS2_REPLACE_METHOD(0x140C74D70, UIMentoringPage, GetScript, 65, 0x6FC2F2E2);
MS2_REPLACE_METHOD(0x140C74DC0, UIMentoringPage, GetOwner, 15, 0x9BD8F6D9);
