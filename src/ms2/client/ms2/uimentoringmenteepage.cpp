// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Mentoring: the mentee tab page. Field/helper names are inferred.
// MS2-UNIT: client\ms2\uimentoringmenteepage.cpp
// MS2-RANGE: 0x140c6e790-0x140c70480 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimentoringmenteepage.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uimentoringrewardpage.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/gfxexception.h"
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
class Unk_MentorRewards { public: int FUN_14069c120(); };
Unk_MentorRewards* FUN_1406c7610();
extern Unk_MentorInfo* DAT_143abb6d8;
class Unk_MentorFlag { public: int FUN_1402c4c90(int); };
class Unk_MentorFlags { public: void* p0; Unk_MentorFlag flags; };
Unk_MentorFlags* FUN_14025e7b0();
class Unk_MentorInviteDialog { public: void FUN_140c2f040(); };
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
CStringW GetStringCommonByKey(const CStringW& strId);
CStringW FUN_1409e9890(CStringW strFormat, const int& a, const int& b);
void FUN_140cfee80(const Scaleform::GFx::Value& root, CString strName, CStringW strText);
// AS helpers on the page's script and the clips it hands out.
class Unk_MentorClip : public ASMovieClip {};
class Unk_MentorScript : public AScript
{
public:
    MS2Ptr<ASMovieClip> FUN_1409b4560(const CString& strName);          // bind a movie clip child
    MS2Ptr<ASMovieClip> FUN_140accfb0(const CString& strName);          // bind a movie clip child (list clip)
};
void FUN_140bf2260(Scaleform::GFx::Value& v);                            // clear an AS object
CString FUN_141028be0(unsigned __int64 nSerial, CString strPath, int n, CString strExtra);   // profile image url
CString FUN_14016a600(const wchar_t* sz, int n);                         // wide to narrow
CString FUN_140719530(unsigned __int64 n);                               // number to string
class Unk_Localizer
{
public:
    CStringW FUN_141811980(int nCategory, int nId);   // localized name (exe member: this=rcx, hidden return=rdx)
};
Unk_Localizer* FUN_1401a9d70();
CStringW FUN_14052b9d0(CStringW strFormat, const CStringW& a, const CStringW& b);

// @0x140c70240
static Unk_MentorInfo* FUN_140c70240()
{
    return DAT_143abb6d8;
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
    if (!FUN_1406c7610()) return;
    int nMentee = FUN_140c70240()->FUN_140b71650();
    int nReward = FUN_1406c7610()->FUN_14069c120();
    m_coin->FUN_1422c4cd0(FUN_1409e9890(L"s_mentoring_coin_info", nMentee, nReward));
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
        if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x42) != 0)
        {
            FUN_141275260(0x2f7, 1, 1);
            return 1;
        }
        Unk_MentorInviteDialog* pDlg = FUN_140b6f4c0(0x4f4c);
        if (pDlg) pDlg->FUN_140c2f040();
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
int UIMentoringMenteePage::vfunc_8() { return FUN_140c70240()->FUN_140b71750(); }
MS2_REPLACE_METHOD(0x140C6F160, UIMentoringMenteePage, vfunc_8, 27, 0x39E6850C);

// @0x140c6f190
// MS2-FUNCTIONAL: temp-spill/unwind layout of MS2Ptr<ASMovieClip> chain differs (frame 0x1a8 vs 0x208)
void UIMentoringPage::FUN_140c6f190()
{
    FUN_140c6f7a0("m_mentor", FUN_140c70240()->FUN_140b71680(0));
    Unk_MentorScript* pScript = reinterpret_cast<Unk_MentorScript*>(m_script.operator->());
    MS2Ptr<ASMovieClip> pSearchMovie = pScript->FUN_1409b4560("m_searchMovie");
    if (pSearchMovie.get())
    {
        int nHidden = FUN_140c70240()->FUN_140b71720();
        pSearchMovie->vfunc_4(nHidden == 0);
        FUN_140cfee80((*pSearchMovie).FUN_1422bb890(), "m_desc", GetStringCommonByKey(L"s_mentoring_tab_mentee_search_desc"));
    }
    MS2Ptr<ASMovieClip> pSearch = pScript->FUN_1409b4560("m_search");
    if (pSearch.get())
    {
        int nHidden = FUN_140c70240()->FUN_140b71720();
        pSearch->vfunc_4(nHidden == 0);
    }
    MS2Ptr<ASMovieClip> pNotify = pScript->FUN_1409b4560("m_notifyMovie");
    if (pNotify.get())
    {
        int nShown = FUN_140c70240()->FUN_140b71720();
        pNotify->vfunc_4(nShown != 0);
    }
    MS2Ptr<ASMovieClip> pMentor = pScript->FUN_140accfb0("m_mentor");
    if (pMentor.get())
    {
        int nShown = FUN_140c70240()->FUN_140b71720();
        pMentor->vfunc_4(nShown != 0);
    }
    MS2Ptr<ASMovieClip> pEffect = pScript->FUN_1409b4560("m_effect");
    if (pEffect.get())
    {
        int nCount = FUN_140c70240()->FUN_140b71750();
        pEffect->vfunc_4(nCount != 0);
    }
    if (m_script.get())
    {
        int nCount = FUN_140c70240()->FUN_140b71750();
        m_script->Invoke("setCount", nCount);
    }
}
MS2_REPLACE_METHOD(0x140C6F190, UIMentoringPage, FUN_140c6f190, 1536, 0xA2D1B5E6);

// @0x140c6f7a0
// MS2-FUNCTIONAL: ASObj/CString temp layout differs from exe
void UIMentoringPage::FUN_140c6f7a0(CString strName, MS2Ptr<Unk_MentorEntry> pEntry)
{
    Unk_MentorScript* pScript = reinterpret_cast<Unk_MentorScript*>(m_script.operator->());
    MS2Ptr<ASMovieClip> pClip = pScript->FUN_140accfb0(strName);
    if (pClip.get())
    {
        ASObj obj(2);
        pEntry = FUN_140c70240()->FUN_140b71680(0);
        if (pEntry.IsNull())
        {
            FUN_140bf2260(obj.FUN_1422bb870());
        }
        else
        {
            obj.FUN_1407cba60("iconPath", FUN_141028be0(pEntry->m_30, FUN_14016a600(pEntry->m_48, 0), 1, ""));
            obj.FUN_1407cbbe0("isOnline", pEntry->m_58);
            obj.FUN_1407cbb20("name", pEntry->m_38);
            obj.FUN_1407cbb20("extra", FUN_14052b9d0(L"s_mentoring_user_info", pEntry->m_40, FUN_1401a9d70()->FUN_141811980(6, pEntry->m_54)));
            obj.FUN_1407cbb20("charName", pEntry->m_38);
            obj.FUN_1407cba60("charSN", FUN_140719530(pEntry->m_30));
        }
        pClip->Invoke("setData", obj);
    }
}
MS2_REPLACE_METHOD(0x140C6F7A0, UIMentoringPage, FUN_140c6f7a0, 1150, 0xF09790F1);

MS2_EMIT_CRT_MEMMOVE_S();
