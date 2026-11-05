// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Mentoring: the mentee tab page. Field/helper names are inferred.
// MS2-UNIT: client\ms2\uimentoringmenteepage.cpp
// MS2-RANGE: 0x140c6e790-0x140c70480 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimentoringmenteepage.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uimentoringrewardpage.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/commonfiles/contentshutdown.h"  // C3: CContentShutdown::Get
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/wcformat.h"

// ---- out-of-unit callees (bound to the exe by their FUN_<va> names) ----
// The mentee/mentor record of one user (a CPtred; +0x30 serial number, name at +0x38, a ushort at +0x40 (s_mentoring_user_info arg 1), icon url at +0x48).
class Unk_MentorEntry : public CPtred
{
public:
    unsigned char m_pad_18[0x18];
    unsigned __int64 m_30;
    CStringW m_38;
    unsigned short m_40;
    CStringW m_48;
    int m_50;
    int m_54;
    bool m_58;
};
// The mentoring state kept by the client (singleton DAT_143abb6d8).
class CMentoringManager   // C3: view of the real class (the counts 0x140b71720 / 0x140b71750 return int)
{
public:
    int FUN_140b71650(); int GetMenteeCount(); int GetMentorCount();
};
class Unk_MentorInfo : public CMentoringManager { public: MS2Ptr<Unk_MentorEntry> FUN_140b71680(int n); };
class MentoringDataTable { public: unsigned int GetMaxMenteeDailyRewardCoin(); };   // C3: view of the real class
struct Unk_NametagFlags* FUN_1406c7610();   // C3: was FUN_1406c7610
class CMentoringManager;
class Unk_MentorFlag { public: int FUN_1402c4c90(int); };
class Unk_MentorFlags { public: void* p0; Unk_MentorFlag flags; };
struct Unk_BanConfig* FUN_14025e7b0();   // C3: was FUN_14025e7b0
class UIInviteMentoringDialog { public: void FUN_140c2f040(); };   // C3: view of the real class
UIInviteMentoringDialog* FUN_140b6f4c0(int nId);
void FUN_141275260(int, int, int);
class CPartyManager;
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
class UIPopUpMenu { public: void FUN_141a7f090(class Unk_PopupMenuInfo const &, class ATL::CStringT<wchar_t, class StrTraitMFC_DLL<wchar_t, class ATL::ChTraitsCRT<wchar_t>>> const &, unsigned __int64, void *, int, int); }; class Unk_PopupMenu : public UIPopUpMenu { };
Unk_PopupMenu* FUN_140c30140(int nId);
unsigned __int64 FUN_140718350(const CString& str);
CStringW GetStringCommonByKey(const CStringW& strId);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
// AS helpers on the page's script and the clips it hands out.
class Unk_MentorClip : public ASMovieClip {};
class Unk_MentorScript : public AScript
{
public:
};
CString FUN_141028be0(__int64 nSerial, const CString& strPath, int n, CString strExtra);   // profile image url
CString FUN_14016a600(const wchar_t* sz, int n);                         // wide to narrow
CString FUN_140719530(unsigned __int64 n);                               // number to string
// FUN_14052b9d0 = FUN_14028dfa0<unsigned short, CStringW> (wcformat.h, instantiated in item.cpp)

// @0x140c70240
static Unk_MentorInfo* FUN_140c70240()
{
    return reinterpret_cast<Unk_MentorInfo*>(TSingleton<CMentoringManager>::s_instance);
}

// @0x140c6e790
ASMentoringMenteePage::ASMentoringMenteePage(UIMentoringPage* p) : m_owner(p) {}
// @0x140c6e810
ASMentoringMenteePage::~ASMentoringMenteePage() {}

// @0x140c6e860
void ASMentoringMenteePage::OnInit()
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
MS2_REPLACE_METHOD(0x140C6E860, ASMentoringMenteePage, OnInit, 515, 0x4AC55F75);

// @0x140c6ea90
void ASMentoringMenteePage::Refresh()
{
    if (!((class MentoringDataTable*)FUN_1406c7610())) return;
    int nMentee = reinterpret_cast<CMentoringManager*>(FUN_140c70240())->FUN_140b71650();
    int nReward = ((class MentoringDataTable*)FUN_1406c7610())->GetMaxMenteeDailyRewardCoin();
    m_coin->SetTextW(FUN_14028dfa0<unsigned, unsigned>(L"s_mentoring_coin_info", reinterpret_cast<const unsigned&>(nMentee), reinterpret_cast<const unsigned&>(nReward)));
}
MS2_REPLACE_METHOD(0x140C6EA90, ASMentoringMenteePage, Refresh, 187, 0x8A4892D4);

// @0x140c6eb60
UIMentoringMenteePage::UIMentoringMenteePage(UIMentoringDialog* p) : UIMentoringPage(p) {}
// @0x140c6ebc0
UIMentoringMenteePage::~UIMentoringMenteePage() {}

// @0x140c6ec00
int UIMentoringMenteePage::vfunc_1()
{
    if (!UIMentoringPage::vfunc_1()) return 0;
    m_mentee = new ASMentoringMenteePage(this);
    m_mentee->OnInit();
    FUN_140c6f190();
    return 1;
}
MS2_REPLACE_METHOD(0x140C6EC00, UIMentoringMenteePage, vfunc_1, 167, 0x7C55F081);

// @0x140c6ecb0
void UIMentoringMenteePage::vfunc_2()
{
    UIMentoringPage::vfunc_2();
    m_mentee = 0;
}
MS2_REPLACE_METHOD(0x140C6ECB0, UIMentoringMenteePage, vfunc_2, 43, 0x75E62814);

// @0x140c6ecf0
int UIMentoringMenteePage::vfunc_5(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned nArgs)
{
    if (UIMentoringPage::vfunc_5(szMethod, pArgs, nArgs)) return 1;
    if (_stricmp(szMethod, "onOpenInviteMenteePage") == 0)
    {
        if (reinterpret_cast<CContentShutdown&>(((class Unk_MentorFlags*)FUN_14025e7b0())->flags).Get((CContentShutdown::Content)(0x42)) != 0)
        {
            FUN_141275260(0x2f7, 1, 1);
            return 1;
        }
        UIInviteMentoringDialog* pDlg = FUN_140b6f4c0(0x4f4c);
        if (pDlg) ((class UIInviteMentoringDialog*)(pDlg))->FUN_140c2f040();
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
                ((class UIPopUpMenu*)(pMenu))->FUN_141a7f090(info, strName, nSerial, NULL, 0, 1);
            }
        }
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140C6ECF0, UIMentoringMenteePage, vfunc_5, 850, 0x73DA3059);

// @0x140c6f050
CString UIMentoringMenteePage::vfunc_6() { return "MenteePage"; }
MS2_REPLACE_METHOD(0x140C6F050, UIMentoringMenteePage, vfunc_6, 61, 0xBC8DA6F7);

// @0x140c6f0a0
CStringW UIMentoringMenteePage::vfunc_7() { return GetStringCommonByKey(L"s_mentoring_tab_mentee"); }
MS2_REPLACE_METHOD(0x140C6F0A0, UIMentoringMenteePage, vfunc_7, 97, 0x91462F07);

// @0x140c6f110
void UIMentoringMenteePage::vfunc_9() { if (m_mentee.get()) m_mentee->Refresh(); }
MS2_REPLACE_METHOD(0x140C6F110, UIMentoringMenteePage, vfunc_9, 61, 0xE6D9F15D);

// @0x140c6f160
int UIMentoringMenteePage::vfunc_8() { return FUN_140c70240()->GetMentorCount(); }
MS2_REPLACE_METHOD(0x140C6F160, UIMentoringMenteePage, vfunc_8, 27, 0x39E6850C);

// @0x140c6f190
void UIMentoringPage::FUN_140c6f190()
{
    FUN_140c6f7a0("m_mentor", FUN_140c70240()->FUN_140b71680(0));
    if (MS2Ptr<ASMovieClip> pSearchMovie = reinterpret_cast<Unk_MentorScript*>(m_script.operator->())->FUN_1409b4560("m_searchMovie"))
    {
        pSearchMovie->vfunc_4(FUN_140c70240()->GetMenteeCount() == 0);
        FUN_140cfee80((*pSearchMovie).FUN_1422bb890(), "m_desc", GetStringCommonByKey(L"s_mentoring_tab_mentee_search_desc"));
    }
    if (MS2Ptr<ASMovieClip> pSearch = reinterpret_cast<Unk_MentorScript*>(m_script.operator->())->FUN_1409b4560("m_search"))
    {
        pSearch->vfunc_4(FUN_140c70240()->GetMenteeCount() == 0);
    }
    if (MS2Ptr<ASMovieClip> pNotify = reinterpret_cast<Unk_MentorScript*>(m_script.operator->())->FUN_1409b4560("m_notifyMovie"))
    {
        pNotify->vfunc_4(FUN_140c70240()->GetMenteeCount() != 0);
    }
    if (MS2Ptr<ASUIComponent> pMentor = reinterpret_cast<Unk_MentorScript*>(m_script.operator->())->FUN_140accfb0<ASUIComponent>("m_mentor"))
    {
        pMentor->vfunc_4(FUN_140c70240()->GetMenteeCount() != 0);
    }
    if (MS2Ptr<ASMovieClip> pEffect = reinterpret_cast<Unk_MentorScript*>(m_script.operator->())->FUN_1409b4560("m_effect"))
    {
        pEffect->vfunc_4(FUN_140c70240()->GetMentorCount() != 0);
    }
    if (m_script.get())
    {
        m_script->Invoke("setCount", FUN_140c70240()->GetMentorCount());
    }
}
MS2_REPLACE_METHOD(0x140C6F190, UIMentoringPage, FUN_140c6f190, 1536, 0xA2D1B5E6);

// @0x140c6f7a0
void UIMentoringPage::FUN_140c6f7a0(CString strName, MS2Ptr<Unk_MentorEntry> pEntry)
{
    MS2Ptr<ASUIComponent> pClip = reinterpret_cast<Unk_MentorScript*>(m_script.operator->())->FUN_140accfb0<ASUIComponent>(strName);
    if (pClip.get())
    {
        ASObj obj(2);
        pEntry = FUN_140c70240()->FUN_140b71680(0);
        if (pEntry.get())
        {
            obj.FUN_1407cba60("iconPath", FUN_141028be0(pEntry->m_30, FUN_14016a600(pEntry->m_48, 0), 1, ""));
            obj.FUN_1407cbbe0("isOnline", pEntry->m_58);
            ((class AScript&)(obj)).FUN_1407cbb20("name", pEntry->m_38);
            ((class AScript&)(obj)).FUN_1407cbb20("extra", FUN_14028dfa0(CStringW(L"s_mentoring_user_info"), pEntry->m_40, TSingleton<CStringTable>::GetInstance()->FUN_141811980(6, pEntry->m_54)));
            ((class AScript&)(obj)).FUN_1407cbb20("charName", pEntry->m_38);
            obj.FUN_1407cba60("charSN", FUN_140719530(pEntry->m_30));
        }
        else
        {
            ((Scaleform::GFx::Value*)&(obj.FUN_1422bb870()))->SetNull();
        }
        pClip->Invoke("setData", obj);
    }
}
MS2_REPLACE_METHOD(0x140C6F7A0, UIMentoringPage, FUN_140c6f7a0, 1150, 0xF09790F1);

MS2_EMIT_CRT_MEMMOVE_S();
