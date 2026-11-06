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
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/ascorelist.h"
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
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"
#include "ms2/commonfiles/timeutil.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/creservedwordtable.h"
#include "ms2/client/ms2/uiquesteventlistener.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/cgameeventvaluemanager.h"   // C3: TSingleton<> needs the class
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/contentshutdown.h"  // C3: CContentShutdown::Get
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/uipopupmenu.h"
#include "ms2/placeholder/mentoringdatatable.h"
#include "ms2/placeholder/cquestmanagercommon.h"
#include "ms2/placeholder/wcformat.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
#include "ms2/client/ms2/mentoringmanager.h"   // CMentoringManager::GetMentee, CMentor (were local entry / info views)
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
struct Unk_NametagFlags* FUN_1406c7610();   // C3: was FUN_1406c7610
//
class Unk_MentorFlag { public: int FUN_1402c4c90(int); };
class Unk_MentorFlags { public: void* p0; Unk_MentorFlag flags; };
struct Unk_BanConfig* FUN_14025e7b0();   // C3: was FUN_14025e7b0
class UIInviteMentoringDialog { public: void FUN_140c2f010(); };   // C3: member view (uiinvitementoringdialog.h)
UIInviteMentoringDialog* FUN_140b6f4c0(int nId);
void FUN_141275260(int, int, int);
unsigned __int64 FUN_140718350(const CString& str);
CStringW GetStringCommonByKey(const CStringW& strId);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
// AS helpers on the page's script and the clips it hands out.
class Unk_MentorScript : public AScript
{
public:
};
CString FUN_141028be0(__int64 nSerial, const CString& strPath, int n, CString strExtra);   // profile image url
CString FUN_14016a600(const wchar_t* sz, int n);                         // wide to narrow
CString FUN_140719530(unsigned __int64 n);                               // number to string
      // localized names
// FUN_14052b9d0 = FUN_14028dfa0<unsigned short, CStringW> (wcformat.h, instantiated in item.cpp)

// @0x140c70240 (mentee unit)
//

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
    if (!((class MentoringDataTable*)FUN_1406c7610())) return;
    int nMentor = TSingleton<CMentoringManager>::GetInstance()->FUN_140b71650();
    int nReward = ((class MentoringDataTable*)FUN_1406c7610())->GetMaxMentorDailyRewardCoin();
    m_coin->SetTextW(FUN_14028dfa0(L"s_mentoring_coin_info", reinterpret_cast<const unsigned&>(nMentor), reinterpret_cast<const unsigned&>(nReward)));
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
        if (reinterpret_cast<CContentShutdown&>(((class Unk_MentorFlags*)FUN_14025e7b0())->flags).Get((CContentShutdown::Content)(0x41)) != 0)
        {
            FUN_141275260(0x2f7, 1, 1);
            return 1;
        }
        UIInviteMentoringDialog* pDlg = FUN_140b6f4c0(0x4f4c);
        if (pDlg) pDlg->FUN_140c2f010();
        return 1;
    }
    else if (_stricmp(szMethod, "onPartyRequest") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
            TSingleton<CPartyManager>::GetInstance()->SendPartyMode1(data.FUN_1422b8f40());
    }
    else if (_stricmp(szMethod, "OnPopupMenu") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            float x = data.PopFloat();
            float y = data.PopFloat();
            CStringW strName = data.FUN_1422b8f40();
            unsigned __int64 nSerial = FUN_140718350(data.FUN_1422b8d30());
            Unk_PopupMenu* pMenu = FUN_140c30140(0x4e39);
            if (pMenu)
            {
                Unk_PopupMenuInfo info(x, y, 3, 10, 0, "", NULL);
                reinterpret_cast<UIPopUpMenu*>(pMenu)->FUN_141a7f090(info, strName, nSerial, NULL, 0, 1);
            }
        }
        return 1;
    }
    return 0;
}

// @0x140c71bd0
CString UIMentoringMentorPage::vfunc_6() { return "MentorPage"; }

// @0x140c71c20
CStringW UIMentoringMentorPage::vfunc_7() { return GetStringCommonByKey(L"s_mentoring_tab_mentor"); }

// @0x140c71c90
void UIMentoringMentorPage::vfunc_9() { if (m_mentor.get()) m_mentor->Refresh(); }

// @0x140c71ce0
void UIMentoringPage::FUN_140c71ce0()
{
    int nShown = TSingleton<CMentoringManager>::GetInstance()->GetMenteeCount();
    FUN_140c71ee0("m_mentee1", TSingleton<CMentoringManager>::GetInstance()->GetMentee(0), nShown ? 1 : 0);
    FUN_140c71ee0("m_mentee2", TSingleton<CMentoringManager>::GetInstance()->GetMentee(1), nShown ? 1 : 0);
    FUN_140c71ee0("m_mentee3", TSingleton<CMentoringManager>::GetInstance()->GetMentee(2), nShown ? 1 : 0);
}

// @0x140c71ee0
void UIMentoringPage::FUN_140c71ee0(CString strName, Unk_MentorPtr<CMentor> pEntry, int bVisible)
{
    {
        MS2Ptr<ASUIComponent> pClip = reinterpret_cast<Unk_MentorScript*>(m_script.operator->())->FUN_140accfb0<ASUIComponent>(strName);
        if (pClip.get())
        {
            ASObj obj(2);
            if (pEntry.get() != 0)
            {
                obj.FUN_1407cba60("iconPath", FUN_141028be0(pEntry->c, FUN_14016a600(pEntry->guild, 0), 1, ""));
                obj.FUN_1407cbbe0("isOnline", pEntry->online);
                obj.FUN_1407cbb20("name", pEntry->name);
                obj.FUN_1407cbb20("extra", FUN_14028dfa0(CStringW(L"s_mentoring_user_info"), pEntry->level, TSingleton<CStringTable>::GetInstance()->FUN_141811980(6, pEntry->y)));
                obj.FUN_1407cbb20("charName", pEntry->name);
                obj.FUN_1407cba60("charSN", FUN_140719530(pEntry->c));
            }
            else
            {
                ((Scaleform::GFx::Value*)&static_cast<class Scaleform::GFx::Value&>(obj.FUN_1422bb870()))->SetNull();
            }
            pClip->Invoke("setData", obj);
            pClip->vfunc_3(bVisible);
        }
    }
    if (MS2Ptr<ASMovieClip> pSearchMovie = reinterpret_cast<Unk_MentorScript*>(m_script.operator->())->FUN_1409b4560("m_searchMovie"))
    {
        pSearchMovie->vfunc_4(TSingleton<CMentoringManager>::GetInstance()->GetMenteeCount() == 0);
        FUN_140cfee80((*pSearchMovie).FUN_1422bb890(), "m_desc", GetStringCommonByKey(L"s_mentoring_tab_mentor_search_desc"));
    }
    if (MS2Ptr<ASMovieClip> pSearch = reinterpret_cast<Unk_MentorScript*>(m_script.operator->())->FUN_1409b4560("m_search"))
        pSearch->vfunc_4(TSingleton<CMentoringManager>::GetInstance()->GetMenteeCount() < 3);
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
// The event schedule (singleton chain 0x140302b00 -> 0x14041d160): start/end of the registration period.
class Unk_RuMentoring : public CGameEventValueMentoring { };
class Unk_RuManager { public: Unk_RuMentoring* GetMentoring(); };

template <class A1, class A2, class A3, class A4, class A5, class A6, class A7> CStringW FUN_14028dfa0(CStringW strFormat, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
void FUN_140710590(COutPacket& pkt);
// Unk_MentorEmptyPacket: mentor.h (via uimentoringrewardpage.h)
// The register role byte (ctor 0x140c731c0 always stores 8).
class Unk_MentorRole
{
public:
    Unk_MentorRole() { m_nRole = 8; }       // @0x140c731c0
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
int UIMentoringMentorRegisterPage::vfunc_5(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (UIMentoringPage::vfunc_5(szMethod, pArgs, nArgs)) return 1;
    if (_stricmp(szMethod, "onRegister") == 0)
    {
        Unk_MentorActorV* pActor = ((Unk_MentorActorV*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
        if (pActor == 0) return 1;
        CMsTime tStart(reinterpret_cast<Unk_RuManager*>(TSingleton<CGameEventValueManager>::GetInstance())->GetMentoring()->GetBeginTime());
        CMsTime tEnd(reinterpret_cast<Unk_RuManager*>(TSingleton<CGameEventValueManager>::GetInstance())->GetMentoring()->GetEndTime());
        int nStartYear, nStartMonth, nStartDay, nEndYear, nEndMonth, nEndDay;
        nEndDay = tEnd.GetDay();
        nEndMonth = tEnd.GetMonth();
        nEndYear = tEnd.GetYear();
        nStartDay = tStart.GetDay();
        nStartMonth = tStart.GetMonth();
        nStartYear = tStart.GetYear();
        CStringW strMsg = FUN_14028dfa0<int, int, int, int, int, int, CStringW>(L"s_mentoring_mentor_register_warn", nStartYear, nStartMonth, nStartDay, nEndYear, nEndMonth, nEndDay, pActor->GetName());
        TSingleton<CReservedWordTable>::GetInstance()->ReplaceValueWords(strMsg);
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, CStringW(strMsg), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->FUN_141a024a0(0);
                spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIMentoringMentorRegisterPage::SendMentor));
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
CStringW UIMentoringMentorRegisterPage::vfunc_7() { return GetStringCommonByKey(L"s_mentoring_tab_register_mentor"); }

// @0x140c72f10
bool UIMentoringMentorRegisterPage::SendMentor(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0) return true;
    COutPacket pkt(static_cast<int>(SendOp::Mentor), 0);
    Unk_MentorRole role;
    reinterpret_cast<Unk_MentorEmptyPacket&>(role).FUN_14069a4e0(reinterpret_cast<Unk_MentorWriter&>(pkt));
    FUN_140710590(pkt);
    return true;
}


// ============================================================================
// UIMentoringMissionPage
// ============================================================================

// The quest event manager: registers the listener that is told about quest changes.
UIQuestEventDispatcher* FUN_140bfc4b0();
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
MS2Ptr<class CQuestData> FUN_14074bc40(int nQuest);
int FUN_14074b030(class CQuestData*);   // C3: was FUN_14074b030
// The quest progress sub-object of an instance (slot table at +0x18 of the instance).
class Unk_MentorProgress
{
public:
    virtual MS2Ptr<class CQuestData> vfunc_0();   // the quest record
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
#include "ms2/client/ms2/questmanager_1.h"   // CQuest
// The quest instance is a CQuest: CPtred (0x18) then CQuestCommon at +0x18, whose slots (GetData, IsComplete,
// IsActive, IsRewarded, GetStartTime) are Unk_MentorProgress above. CQuestManagerCommon (CQuestManager+0x10)
// slot 3 returns MS2Ptr<CQuest>: ~ 0x140747580, IsNull 0x1407475b0, get 0x140747690, operator-> 0x1407476b0.
//
//
//
//
//
//
//
//
//
//
//
//
//
// The quest state (member +0x10 of the global at FUN_140764020).
class Unk_MentorQuestState
{
public:
    virtual MS2Ptr<CQuest> vfunc_0(int nQuest);
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual MS2Ptr<CQuest> vfunc_3(int nQuest);      // the instance of a quest
};
class Unk_MentorQuestGlobal { public: void* m_0; void* m_8; Unk_MentorQuestState state; };
void* FUN_140764020();   // C3: was FUN_140764020
// The page script (a movie clip root) with the children it hands out.
class Unk_MentorMissionScript : public AScript
{
public:
};
template <class T> MS2Ptr<T> Unk_ASCreate(int nMovieId, const Scaleform::GFx::Value& v);
int FUN_140718170(const CString& str);
template <class A1> CStringW FUN_14028dfa0(CStringW strKey, const A1& a1);
CStringW FUN_1416e5350(int nQuest, int n);
CStringW FUN_1409404f0(__int64 n);
__int64 FUN_140761ba0(int nQuest, int n);
int FUN_140761e40(int nQuest, int n);
CStringW FUN_140763e10(int n);
__int64 GetServerTime();

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
        CMsTime now(GetServerTime());
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
    if ((strMethod == "getTabTooltip"))
    {
        int nDay = FUN_140718170(pArgs->FUN_1422b8d30());
        CMsTime now(GetServerTime());
        CMsTime tDay(FUN_140c74720());
        AddDays(tDay, nDay);
        TruncateToDay(tDay);
        if (tDay.Get() > now.Get())
        {
            ATL::CTimeSpan span = tDay - now;
            CStringW strRemain = FormatTimeSpan(span, true, true, true, true);
            ASTooltip tip(2);
            if (tip.ApplyTextTooltip(FUN_14028dfa0<CStringW>(CStringW(L"s_mentoring_remain_time_from_day"), strRemain)))
                *pOut = tip.FUN_1422bb870();
        }
    }
}

// @0x140c739c0
void UIMentoringMissionPage::vfunc_4(Scaleform::GFx::Value* pOut, ASData* pArgs)
{
    UIMentoringPage::vfunc_4(pOut, pArgs);
    CStringW strName = pArgs->FUN_1422b8f40();
    if (operator==(strName, "guide"))
    {
        int nQuest = pArgs->PopUInt();
        MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuest);
        if (spQuest.get() != 0)
        {
            Unk_MentorActorV* pActor = ((Unk_MentorActorV*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
            if (pActor == 0) return;
            ASTooltip tip(2);
            if (tip.ApplyTextTooltip(FUN_1409404f0(FUN_140761ba0(nQuest, 1))))
            {
                tip.SetTooltipAlign(1);
                *pOut = tip.FUN_1422bb870();
            }
        }
    }
    else if (operator==(strName, "menteeCoin"))
    {
        int nQuest = pArgs->PopUInt();
        MS2Ptr<CQuestData> spQuest = FUN_14074bc40(nQuest);
        if (spQuest.get() != 0)
        {
            Unk_MentorActorV* pActor = ((Unk_MentorActorV*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
            if (pActor == 0) return;
            ASTooltip tip(2);
            if (tip.ApplyTextTooltip(FUN_140763e10(FUN_140761e40(nQuest, 1))))
            {
                tip.SetTooltipAlign(1);
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
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            int nDay = data.PopInt();
            FUN_140c74450(nDay + 1);
        }
    }
    else if (_stricmp(szMethod, "onReceiveItem") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            int nQuest = data.PopUInt();
            COutPacket pkt(static_cast<int>(SendOp::Quest), 0);
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
CStringW UIMentoringMissionPage::vfunc_7() { return GetStringCommonByKey(L"s_mentoring_tab_mission"); }

// @0x140c73ef0
void UIMentoringMissionPage::vfunc_o178_11(void* p)
{
    if (p == 0) return;
    MS2Ptr<CQuestData> spQuest = (&static_cast<Unk_MentorInstance*>(p)->m_progress)->vfunc_0();
    if (!spQuest) return;
    int nDay = reinterpret_cast<Unk_MentorQuest*>(spQuest.operator->())->m_nDay;
    if (nDay != FUN_140c74660()) return;
    FUN_140c74450(nDay);
    ((class UIMentoringDialog*)(class UIMentoringDialog*)(m_owner))->UpdateCounts();
    FUN_140c74970();
}

// @0x140c73fe0
int UIMentoringMissionPage::vfunc_8()
{
    int nCount = 0;
    ATL::CAtlArray<unsigned> ids;
    FUN_140c74850(reinterpret_cast<Unk_MentorIdArray&>(ids), -1);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        if (reinterpret_cast<CQuestManagerCommon*>(&((class Unk_MentorQuestGlobal*)FUN_140764020())->state)->IsQuestComplete(ids[i]) != 0) nCount++;
    }
    return nCount;
}

// @0x140c740a0
int UIMentoringMissionPage::vfunc_10(int nDay)
{
    int nCount = 0;
    ATL::CAtlArray<unsigned> ids;
    FUN_140c74850(reinterpret_cast<Unk_MentorIdArray&>(ids), nDay);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        if (reinterpret_cast<CQuestManagerCommon*>(&((class Unk_MentorQuestGlobal*)FUN_140764020())->state)->IsQuestComplete(ids[i]) != 0) nCount++;
    }
    return nCount;
}

// @0x140c74170
void UIMentoringMissionPage::FUN_140c74170(ASObj& obj, Unk_MentorInstance* pInst)
{
    if (pInst == 0) return;
    MS2Ptr<CQuestData> spQuest = (&pInst->m_progress)->vfunc_0();
    if (!spQuest) return;
    Unk_MentorActorV* pUser = ((Unk_MentorActorV*)((WorldService*)(WorldService::GetInstance()))->FUN_141bd0cc0());
    if (pUser == 0) return;
    CString strIcon = reinterpret_cast<Unk_MentorQuest*>((&pInst->m_progress)->vfunc_0().operator->())->m_strIcon;
    CStringW strDesc = FUN_1416e5350(((class CQuest*)(class Unk_MentorInstance*)(pInst))->FUN_140bfc580(), 0);
    strDesc.Replace(L"#5c2b00", L"#000000");
    obj.FUN_1409c0d20("id", ((class CQuest*)(class Unk_MentorInstance*)(pInst))->FUN_140bfc580());
    obj.FUN_1407cba60("icon", strIcon);
    obj.FUN_1407cbb20("desc", strDesc);
    obj.FUN_1407cb9c0("satisfied", (&pInst->m_progress)->vfunc_1());
    obj.FUN_1407cb9c0("completed", (&pInst->m_progress)->vfunc_3());
    obj.FUN_1409c1180("exp", FUN_140761ba0(((class CQuest*)(class Unk_MentorInstance*)(pInst))->FUN_140bfc580(), 1));
}

// @0x140c74450
void UIMentoringMissionPage::FUN_140c74450(int nDay)
{
    if (MS2Ptr<ASScrollingList> spList = reinterpret_cast<Unk_MentorMissionScript*>(m_script.operator->())->FUN_140bc7280<ASScrollingList>("m_missionList"))
    {
        spList->FUN_1422dd1d0();
        ATL::CAtlArray<unsigned> ids;
        FUN_140c74850(reinterpret_cast<Unk_MentorIdArray&>(ids), nDay);
        for (size_t i = 0; i < ids.GetCount(); i++)
        {
            MS2Ptr<CQuest> spInst = (&((class Unk_MentorQuestGlobal*)FUN_140764020())->state)->vfunc_3(ids[i]);
            if (spInst.IsNull()) continue;
            ASObj obj(2);
            FUN_140c74170(obj, (Unk_MentorInstance*)spInst.get());
            spList->AddItem(obj);
        }
        spList->vfunc_24(true);
    }
}

// @0x140c74660
int UIMentoringMissionPage::FUN_140c74660()
{
    if (MS2Ptr<ASButtonBar> spTab = reinterpret_cast<Unk_MentorMissionScript*>(m_script.operator->())->FUN_140be23c0<ASButtonBar>("m_tab"))
        return spTab->GetSelectedIndex() + 1;
    return 0;
}

// @0x140c74720
__int64 UIMentoringMissionPage::FUN_140c74720()
{
    ATL::CAtlArray<unsigned> ids;
    FUN_140c74850(reinterpret_cast<Unk_MentorIdArray&>(ids), -1);
    for (size_t i = 0; i < ids.GetCount(); i++)
    {
        MS2Ptr<CQuest> spInst = (&((class Unk_MentorQuestGlobal*)FUN_140764020())->state)->vfunc_3(ids[i]);
        if (spInst.get() != 0) return spInst->GetStartTime();
    }
    return 0;
}

// @0x140c74850
void UIMentoringMissionPage::FUN_140c74850(Unk_MentorIdArray& ids, int nDay)
{
    ATL::CAtlArray<unsigned> all;
    reinterpret_cast<Unk_RuManager*>(TSingleton<CGameEventValueManager>::GetInstance())->GetMentoring()->GetIds(all);
    for (size_t i = 0; i < all.GetCount(); i++)
    {
        MS2Ptr<CQuestData> spQuest = FUN_14074bc40(all[i]);
        if (!spQuest) continue;
        if (nDay != -1 && reinterpret_cast<Unk_MentorQuest*>(spQuest.operator->())->m_nDay != nDay) continue;
        reinterpret_cast<ATL::CAtlArray<unsigned int>*>(&ids)->Add((unsigned int)FUN_14074b030((class CQuestData*)(spQuest.operator->())));
    }
}

// @0x140c74970
void UIMentoringMissionPage::FUN_140c74970()
{
    for (int i = 0; i < 7; i++)
    {
        reinterpret_cast<Unk_MentorMissionScript*>(m_script.operator->())->FUN_1409ba0d0("setCount", i, vfunc_10(i + 1));
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
int UIMentoringPage::vfunc_1()
{
    if (m_owner->FUN_1422dba00().IsNull()) return 0;
    Scaleform::GFx::Value tab = m_owner->FUN_1422dba00()->GetMember("m_currentTab");
    if (tab.IsNull()) return 0;
    m_script = Unk_ASCreate<ASUIComponent>(m_owner->FUN_1422db730(), tab);
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
