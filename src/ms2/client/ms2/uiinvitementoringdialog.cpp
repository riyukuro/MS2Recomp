// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIInviteMentoringDialog: the mentoring invitation window. See uiinvitementoringdialog.h.
// MS2-UNIT: ?\uiinvitementoringdialog.cpp
// MS2-GUESS-LOOKALIKES (the MS2Ptr / CAtlArray / Delegate accessor glue is byte-identical to other instances)
// MS2-RANGE: 0x1400ccb40-0x1400cccb0 .text$di
// MS2-RANGE: 0x140c2dea0-0x140c308c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1Unk_PopupMenuInfo@@QEAA@XZ 0x140c304c0 ; unique
// MS2-PIN: ??1Unk_PmB@Unk_PopupMenuInfo@@QEAA@XZ 0x140c30510 ; unique
// MS2-PIN: ??1Unk_PmA@Unk_PopupMenuInfo@@QEAA@XZ 0x140c30550 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiinvitementoringdialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "uiinvitementoringdialog.h"
#include "ms2/placeholder/header_statics_a.h"
#include "uimessageboxdata.h"
#include "buddymanager.h"
#include "ms2/client/ms2/menteesearch.h"
#include "ms2/client/ms2/mentoringmanager.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/gfxui/uimsg.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uimessenger.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/commonfiles/gameeventvalue.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/commonfiles/contentshutdown.h"  // C3: CContentShutdown::Get
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/commonfiles/os.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

// The event schedule (singleton chain 0x140302b00 -> 0x14041d160).
class Unk_MentorSchedule : public CGameEventValueMentoring { };
class Unk_RuManager { public: class Unk_RuMentoring* GetMentoring(); };   // C3: was Unk_MentorScheduleHolder::FUN_14041d160 (gameeventreturnuser.cpp)
class CGameEventValueManager;

// The blocked-action flags.
class Unk_MentorFlag { public: int FUN_1402c4c90(int); };
class Unk_MentorFlags { public: void* p0; Unk_MentorFlag flags; };
struct Unk_BanConfig* FUN_14025e7b0();   // C3: was FUN_14025e7b0
void FUN_141275260(int, int, int);
void ShowSystemNotice(const CStringW&, int, int);


class UICommunityQueryDialog : public UIDialog {};
UICommunityQueryDialog* FUN_140ae5a30(int);

#define Unk_InvArgs(msg) (*reinterpret_cast<ASData*>(&(msg)))      // the message args (no call at /Od)

void FUN_140d73bc0(int nStrId, int nType, void* pListener, CStringW tag);
void FUN_140710590(COutPacket& packet);
MS2Ptr<CMsgBoxData> CreateMessageBox(int nType, CStringW strText, void* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
unsigned __int64 FUN_140718350(const CString& str);             // string -> id
CString FUN_140719530(unsigned __int64 n);                      // number to string
class Unk_InvChat { public: unsigned char m_pad_0[0x48]; class UIMessengerBrowser* m_48; };
struct Unk_MdState* GetState();   // C3: was GetState

void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, efd::Point2 offLeft, efd::Point2 offRight);

class Unk_InvUiMgr { public: };


// The popup-menu request (0x78 bytes), built by the ctor at 0x140c302f0 and released by the dtor at 0x140c304c0.
class Unk_PopupMenuInfo
{
public:
    Unk_PopupMenuInfo(float x, float y, int a, int b, int c, CString str, void* p);   // 0x140c302f0
    ~Unk_PopupMenuInfo() {}                                         // 0x140c304c0
private:
    struct Unk_PmA                                                  // ctor 0x140c30440, dtor 0x140c30550
    {
        Unk_PmA() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(0) {}
        void* m_00; void* m_08; CStringW m_10; int m_18; void* m_20;
    };
    struct Unk_PmB                                                  // ctor 0x140c303c0, dtor 0x140c30510
    {
        Unk_PmB() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(L"") {}
        void* m_00; int m_08; CStringW m_10; void* m_18; CStringW m_20;
    };
    float m_x, m_y;
    int m_a, m_b, m_c;
    CString m_str;
    void* m_p;
    Unk_PmA m_infoA;
    Unk_PmB m_infoB;
};
class Unk_PopupMenu {};
// The cast target only: the exe casts to .?AVUIPopUpMenu@@ (0x143a71720). Casting to Unk_PopupMenu emitted a type
// descriptor no object carries, so the right click menu lookup always returned NULL.
class UIPopUpMenu { public: virtual ~UIPopUpMenu(); void FUN_141a7f090(const Unk_PopupMenuInfo& info, const CStringW& strName, unsigned __int64 nSerial, void* p, int b, int c); };

template CStringW FUN_14028dfa0<int, int, int, CStringW>(CStringW, const int&, const int&, const int&, const CStringW&);   // @0x140c2fcc0

// @0x140c2dea0
UIInviteMentoringDialog::UIInviteMentoringDialog() : UIDialog()
{
    m_bMentorPage = true;
}

// @0x140c2df20
UIInviteMentoringDialog::~UIInviteMentoringDialog() {}

// @0x140c2df90
CString UIInviteMentoringDialog::GetTypeName() { return "InviteMentoringDialog"; }

// @0x140c2dfe0
void UIInviteMentoringDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_bMentorPage = true;
    m_spPage = 0;
}

// @0x140c2e020
void UIInviteMentoringDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_bMentorPage)
    {
        ((MS2Ptr<AScript>*)(&m_30))->operator->()->GetValue().GotoAndStop("mentor");
        {
            CString strPage("mentorPage");
            m_spPage = GetChild<ASMovieClip>(strPage);
        }
        BindDragBar(CString("m_mentorDragBar"));
        CMenteeSearchParam param;
        param.m_nOption30 = reinterpret_cast<Unk_MentorSchedule*>(reinterpret_cast<Unk_RuManager*>(TSingleton<CGameEventValueManager>::GetInstance())->GetMentoring())->GetId();
        CMenteeSearchManager::GetInstance()->RequestSearch(&param);
    }
    else
    {
        ((MS2Ptr<AScript>*)(&m_30))->operator->()->GetValue().GotoAndStop("mentee");
        {
            CString strPage("menteePage");
            m_spPage = GetChild<ASMovieClip>(strPage);
        }
        BindDragBar(CString("m_menteeDragBar"));
        COutPacket pkt(static_cast<int>(SendOp::Mentor), 0);
        Unk_MMListPacket2 req;
        reinterpret_cast<Unk_MentorListPacket*>(&req)->Write(reinterpret_cast<Unk_MentorWriter&>(pkt));
        FUN_140710590(pkt);
    }
}

// @0x140c30140
Unk_PopupMenu* FindPopupMenu(int nId)
{
    if (reinterpret_cast<Unk_InvUiMgr*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spObj = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (spObj.get() != 0)
            return reinterpret_cast<Unk_PopupMenu*>(dynamic_cast<UIPopUpMenu*>(spObj.operator->()));
    }
    return 0;
}

// @0x140c300a0
UIDialog* FindDialog(int nId)
{
    if (reinterpret_cast<Unk_InvUiMgr*>(TSingleton<CUIService>::GetInstance()) != 0)
    {
        MS2Ptr<UIObject> spObj = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)nId);
        if (spObj.get() != 0)
            return dynamic_cast<UIDialog*>(spObj.operator->());
    }
    return 0;
}

// @0x140c2e2c0
void UIInviteMentoringDialog::vfunc_66()
{
    UIDialog::vfunc_66();
    UIDialog* pMentor = FindDialog(0x4f4b);
    if (pMentor != 0)
    {
        if (pMentor->vfunc_55() == 0)
        {
            if (pMentor->FUN_1422dc430() != 0)
                FUN_141275c30(pMentor, this, efd::Point2::ZERO, efd::Point2::ZERO);
        }
    }
}

// @0x140c2e340
int UIInviteMentoringDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onCloseDialog") == 0)
    {
        vfunc_67();
        return 1;
    }
    else if (_stricmp(szMethod, "onInviteMenteeBySN") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            unsigned __int64 nSerial = FUN_140718350(data.FUN_1422b8d30());
            CStringW strName = data.FUN_1422b8f40();
            InviteMentor(nSerial, strName);
        }
    }
    else if (_stricmp(szMethod, "onInviteMentee") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            CStringW strName = data.FUN_1422b8f40();
            InviteMentor(0, strName);
        }
        return 1;
    }
    else if (_stricmp(szMethod, "OnAcceptMentoring") == 0)
    {
        if (reinterpret_cast<CContentShutdown&>(((class Unk_MentorFlags*)FUN_14025e7b0())->flags).Get((CContentShutdown::Content)(0x42)) != 0)
        {
            FUN_141275260(0x2f7, 1, 1);
            return 1;
        }
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            unsigned __int64 nSerial = FUN_140718350(data.FUN_1422b8d30());
            CStringW strName = data.FUN_1422b8f40();
            CMsTime tEnd(reinterpret_cast<Unk_MentorSchedule*>(reinterpret_cast<Unk_RuManager*>(TSingleton<CGameEventValueManager>::GetInstance())->GetMentoring())->GetEndTime());
            int nDay = tEnd.GetDay();
            int nMonth = tEnd.GetMonth();
            int nYear = tEnd.GetYear();
            CStringW strMsg = FUN_14028dfa0(CStringW(L"s_mentoring_mentor_accept_warn"), nYear, nMonth, nDay, strName);
            MS2Ptr<CMsgBoxData> spBox = CreateMessageBox(1, CStringW(strMsg), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->FUN_141a024a0(0);
                spBox->Append<__int64>(nSerial);
                spBox->SetCallback(Delegate<bool(int, const CMsgBoxData&)>(this, &UIInviteMentoringDialog::FUN_140c2fae0));
                FUN_140d73c60(spBox);
                return 1;
            }
        }
        return 1;
    }
    else if (_stricmp(szMethod, "OnRejectMentoring") == 0)
    {
        if (reinterpret_cast<CContentShutdown&>(((class Unk_MentorFlags*)FUN_14025e7b0())->flags).Get((CContentShutdown::Content)(0x42)) != 0)
        {
            FUN_141275260(0x2f7, 1, 1);
            return 1;
        }
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            unsigned __int64 nSerial = FUN_140718350(data.FUN_1422b8d30());
            COutPacket pkt(static_cast<int>(SendOp::Mentor), 0);
            Unk_MMIdPacket7 req;
            req.id = nSerial;
            reinterpret_cast<Unk_MentorIdPacket*>(&req)->FUN_14069a6c0(reinterpret_cast<Unk_MentorWriter&>(pkt));
            FUN_140710590(pkt);
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onBuddy") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            CStringW strName = data.FUN_1422b8f40();
            unsigned __int64 nChar = 0;
            CBuddyManager::Ptr buddy = TSingleton<CBuddyManager>::GetInstance()->FindByName(strName);
            if (buddy.get() != 0)
            {
                nChar = buddy.operator->()->GetId();
                if (buddy.operator->()->FUN_1401cc5d0() != 0)
                {
                    FUN_140d73bc0(0x623, 0, 0, CStringW(L""));
                    return 1;
                }
            }
            CString strChar = FUN_140719530(nChar);
            UIMsg msg;
            Unk_InvArgs(msg).AddInt(0);
            Unk_InvArgs(msg).AddInt(1);
            Unk_InvArgs(msg).AddWString(strName);
            Unk_InvArgs(msg).AddString(strChar);
            UICommunityQueryDialog* pQuery = FUN_140ae5a30(0x4e4e);
            if (pQuery != 0)
                pQuery->OnMessage(this, reinterpret_cast<UIMsg*>(&msg));
        }
        return 1;
    }
    else if (_stricmp(szMethod, "onWhisper") == 0)
    {
        ASData data;
        if (data.SetArgsIfAny(pArgs, nArgs))
        {
            CStringW strName = data.FUN_1422b8f40();
            if (((class Unk_InvChat*)GetState())->m_48 != 0)
                ((class Unk_InvChat*)GetState())->m_48->FUN_141a252a0(strName);
        }
        return 1;
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
            Unk_PopupMenu* pMenu = FindPopupMenu(0x4e39);
            if (pMenu != 0)
            {
                Unk_PopupMenuInfo info(x, y, 3, 10, 0, "", NULL);
                reinterpret_cast<UIPopUpMenu*>(pMenu)->FUN_141a7f090(info, strName, nSerial, NULL, 0, 1);
            }
        }
        return 1;
    }
    return 0;
}

// @0x140c2f010
void UIInviteMentoringDialog::ShowMentorPage()
{
    m_bMentorPage = true;
    FUN_1419246f0();
}

// @0x140c2f040
void UIInviteMentoringDialog::ShowMenteePage()
{
    m_bMentorPage = false;
    FUN_1419246f0();
}

// @0x140c2f070
void UIInviteMentoringDialog::FUN_140c2f070(const ATL::CAtlArray<Unk_MentorPtr<CMentor> >& arrMentors)
{
    if (m_bMentorPage == true)
        return;
    if (m_spPage == 0)
        return;
    ASArray rows(2);
    for (unsigned i = 0; i < arrMentors.GetCount(); i++)
    {
        Unk_MentorPtr<CMentor> spMentor = arrMentors[i];
        if (spMentor == 0)
            continue;
        CStringW strInfo = FUN_14028dfa0<CStringW, unsigned short>(CStringW(L"s_mentoring_invite_info"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(6, spMentor->y), spMentor->level);
        ASObj row(2);
        row.SetBoolMember("isOnline", spMentor->online);
        row.SetWStringMember("charName", CStringW(spMentor->name));
        row.SetStringMember("mentorSN", FUN_140719530(spMentor->a));
        row.SetStringMember("charSN", FUN_140719530(spMentor->c));
        row.SetWStringMember("charInfo", CStringW(strInfo));
        rows.PushValue(Scaleform::GFx::Value(row.GetValue()));
    }
    m_spPage->InvokeWithArray("buildCandidate", rows);
}

// @0x140c2f440
void UIInviteMentoringDialog::SetMentorList(const ATL::CAtlArray<Unk_MentorPtr<CMentor> >& arrMentors)
{
    m_mentors.RemoveAll();
    m_mentors.Copy(arrMentors);
    FUN_140c2f490();
}

// @0x140c2f490
void UIInviteMentoringDialog::FUN_140c2f490()
{
    if (m_bMentorPage == false)
        return;
    if (m_spPage == 0)
        return;
    ASArray rows(2);
    for (unsigned i = 0; i < m_mentors.GetCount(); i++)
    {
        Unk_MentorPtr<CMentor> spMentor = m_mentors[i];
        if (spMentor == 0)
            continue;
        CStringW strInfo = FUN_14028dfa0<CStringW, unsigned short>(CStringW(L"s_mentoring_invite_info"), TSingleton<CStringTable>::GetInstance()->FUN_141811980(6, spMentor->y), spMentor->level);
        ASObj row(2);
        row.SetBoolMember("isOnline", spMentor->online);
        row.SetWStringMember("charName", CStringW(spMentor->name));
        row.SetStringMember("mentorSN", FUN_140719530(spMentor->a));
        row.SetStringMember("charSN", FUN_140719530(spMentor->c));
        row.SetWStringMember("charInfo", CStringW(strInfo));
        rows.PushValue(Scaleform::GFx::Value(row.GetValue()));
    }
    m_spPage->InvokeWithArray("buildCandidate", rows);
}

// @0x140c2f860
void UIInviteMentoringDialog::InviteMentor(__int64 nMentor, const CStringW& strName)
{
    if (reinterpret_cast<CContentShutdown&>(((class Unk_MentorFlags*)FUN_14025e7b0())->flags).Get((CContentShutdown::Content)(0x41)) != 0)
    {
        FUN_141275260(0x2f7, 1, 1);
        return;
    }
    if (CBanTextChecker* pFilter = TSingleton<CommonString>::GetInstance()->GetChecker().operator CBanTextChecker*())
    {
        CStringW strBad;
        if (pFilter->FUN_140225210(strName, strBad, 0) != 0)
        {
            ShowSystemNotice(strBad, 1, 1);
            return;
        }
    }
    COutPacket pkt(static_cast<int>(SendOp::Mentor), 0);
    Unk_MMNamePacket5 req;
    req.name = strName;
    req.id = nMentor;
    reinterpret_cast<Unk_MentorNamePacket*>(&req)->Write(reinterpret_cast<Unk_MentorWriter&>(pkt));
    FUN_140710590(pkt);
    if (nMentor != 0)
    {
        for (unsigned i = 0; i < m_mentors.GetCount(); i++)
        {
            Unk_MentorPtr<CMentor> spMentor = m_mentors[i];
            if (spMentor == 0)
                continue;
            if (spMentor->a == nMentor)
            {
                m_mentors.RemoveAt(i, 1);
                break;
            }
        }
        FUN_140c2f490();
    }
}

// @0x140c2fae0
bool UIInviteMentoringDialog::FUN_140c2fae0(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    __int64 nSerial = data.FUN_141a02f10(0, 0);
    COutPacket pkt(static_cast<int>(SendOp::Mentor), 0);
    Unk_MMIdPacket6 req;
    req.id = nSerial;
    reinterpret_cast<Unk_MentorIdPacket*>(&req)->FUN_14069a630(reinterpret_cast<Unk_MentorWriter&>(pkt));
    FUN_140710590(pkt);
    return true;
}

// @0x140c302f0
Unk_PopupMenuInfo::Unk_PopupMenuInfo(float x, float y, int a, int b, int c, CString str, void* p)
    : m_x(x), m_y(y), m_a(a), m_b(b), m_c(c), m_str(str), m_p(p)
{
}

// @0x140c30610
int UIInviteMentoringDialog::vfunc_48() { return 0x4f4c; }
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca2950-0x142ca29e0 .text$yd
