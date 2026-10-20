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
#include "ms2/guess/menteesearch.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/wcformat.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

MS2_EMIT_CRT_MEMMOVE_S();

// ---- unit-local views of exe objects ----

// The outgoing mentoring packets (0xa1; first byte = the protocol). Their layouts are the CMentoringManager ones.
struct Unk_MMListPacket2
{
    unsigned char protocol;
    ATL::CAtlArray<Unk_MentorPtr<CMentor> > entries;
    Unk_MMListPacket2();                                            // 0x140b730b0
    ~Unk_MMListPacket2();                                           // 0x140b73320
    void FUN_14069a010(COutPacket& pkt);                            // protocol only
};
struct Unk_MMNamePacket5
{
    unsigned char protocol;
    __int64 id;
    CStringW name;
    Unk_MMNamePacket5();                                            // 0x140b73110
    ~Unk_MMNamePacket5();                                           // 0x140b73360
    void FUN_14069a540(COutPacket& pkt);                            // protocol, id, name
};
struct Unk_MMIdPacket6
{
    unsigned char protocol;
    __int64 id;
    Unk_MMIdPacket6();                                              // 0x140b73010
    void FUN_14069a630(COutPacket& pkt);
};
struct Unk_MMIdPacket7
{
    unsigned char protocol;
    __int64 id;
    Unk_MMIdPacket7();                                              // 0x140b73030
    void FUN_14069a6c0(COutPacket& pkt);
};

// The event schedule (singleton chain 0x140302b00 -> 0x14041d160).
class Unk_MentorSchedule { public: __int64 FUN_140424e20(); int FUN_140424de0(); };
class Unk_MentorScheduleHolder { public: Unk_MentorSchedule* FUN_14041d160(); };
Unk_MentorScheduleHolder* FUN_140302b00();

// The blocked-action flags.
class Unk_MentorFlag { public: int FUN_1402c4c90(int); };
class Unk_MentorFlags { public: void* p0; Unk_MentorFlag flags; };
Unk_MentorFlags* FUN_14025e7b0();
void FUN_141275260(int, int, int);
void FUN_1412751f0(const CStringW&, int, int);

// The text filter (banned words) of the invited name.
class Unk_TextFilter { public: };
int FUN_140225210(Unk_TextFilter*, const CStringW& str, CStringW& strOut, int nMode);
class Unk_TextFilterPtr {
public:
    ~Unk_TextFilterPtr();                                        // 0x14025c670
    Unk_TextFilter* FUN_14025cea0() const;
    void* m_00; void* m_08;
};
class Unk_TextFilterMgr { public: Unk_TextFilterPtr FUN_140229a50(); };
Unk_TextFilterMgr* FUN_14025e7d0();

// The buddy list entry of a character (see buddymanager.cpp).
class Unk_GuildBuddyRef {
public:
    ~Unk_GuildBuddyRef();                                   // 0x140979fc0
    void* FUN_14097a170();                                  // get()
    CBuddy* FUN_14097a1e0();                                // operator->
private:
    void* m_00;
    void* m_p;
};
MS2_CHECK_SIZE(Unk_GuildBuddyRef, 0x10);
class Unk_GuildBuddyMgr { public: Unk_GuildBuddyRef FUN_140ae4950(const CStringW& name); };
Unk_GuildBuddyMgr* FUN_14097a780();
class UICommunityQueryDialog : public UIDialog {};
UICommunityQueryDialog* FUN_140ae5a30(int);

// The UI message ("setData"-like ActionScript call, 0x50 bytes); dtor 0x140c30570 is in this unit.
class Unk_InvUIMsg
{
public:
    Unk_InvUIMsg();                                                 // 0x1422e4490
    ~Unk_InvUIMsg() { reinterpret_cast<ASData*>(this)->ASData::~ASData(); }   // @0x140c30570
private:
    unsigned char m_data[0x50];
};
static __forceinline ASData& Unk_InvArgs(Unk_InvUIMsg& msg) { return *reinterpret_cast<ASData*>(&msg); }

void FUN_140d73bc0(int nStrId, int nType, void* p, CStringW tag);
void FUN_140710590(COutPacket& packet);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, int nUnk, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
unsigned __int64 FUN_140718350(const CString& str);             // string -> id
CString FUN_140719530(unsigned __int64 n);                      // number to string
class Unk_InvStrings { public: CStringW FUN_141811980(int nTable, int nId); };
Unk_InvStrings* FUN_1401a9d70();
CStringW FUN_1409e9ed0(CStringW strKey, const CStringW& a1, const unsigned short& a2);
class Unk_InvChat { public: unsigned char m_pad_0[0x48]; class Unk_InvChatInput* m_48; };
class Unk_InvChatInput { public: void FUN_141a252a0(const CStringW& strName); };
Unk_InvChat* FUN_141482e80();

struct Unk_PickXY { float x, y; };                              // dialog offset
extern Unk_PickXY DAT_143b02320;                                // zero offset
void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, Unk_PickXY offLeft, Unk_PickXY offRight);

class Unk_InvUiMgr { public: MS2Ptr<UIObject> FUN_141adcea0(int nId); };
Unk_InvUiMgr* FUN_1403ed2b0();

AScript* FUN_1409ee290(MS2Ptr<AScript>* p);

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
class Unk_PopupMenu { public: void FUN_141a7f090(const Unk_PopupMenuInfo& info, const CStringW& strName, unsigned __int64 nSerial, void* p, int b, int c); };

template CStringW FUN_14028dfa0<int, int, int, CStringW>(CStringW, const int&, const int&, const int&, const CStringW&);   // @0x140c2fcc0

// @0x140c2dea0
UIInviteMentoringDialog::UIInviteMentoringDialog() : UIDialog()
{
    m_bMentorPage = true;
}

// @0x140c2df20
UIInviteMentoringDialog::~UIInviteMentoringDialog() {}

// @0x140c2df90
CString UIInviteMentoringDialog::vfunc_1() { return "InviteMentoringDialog"; }

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
        FUN_1409ee290(&m_30)->FUN_1422bb870().GotoAndStop("mentor");
        {
            CString strPage("mentorPage");
            m_spPage = FUN_140ba7930(strPage);
        }
        FUN_141925fa0(CString("m_mentorDragBar"));
        CMenteeSearchParam param;
        param.m_nOption30 = FUN_140302b00()->FUN_14041d160()->FUN_140424de0();
        CMenteeSearchManager::GetInstance()->RequestSearch(&param);
    }
    else
    {
        FUN_1409ee290(&m_30)->FUN_1422bb870().GotoAndStop("mentee");
        {
            CString strPage("menteePage");
            m_spPage = FUN_140ba7930(strPage);
        }
        FUN_141925fa0(CString("m_menteeDragBar"));
        COutPacket pkt(0xa1, 0);
        Unk_MMListPacket2 req;
        req.FUN_14069a010(pkt);
        FUN_140710590(pkt);
    }
}

// @0x140c30140
static Unk_PopupMenu* FUN_140c30140(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObj = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (spObj.get() != 0)
            return dynamic_cast<Unk_PopupMenu*>(spObj.operator->());
    }
    return 0;
}

// @0x140c300a0
static UIDialog* FUN_140c300a0(int nId)
{
    if (FUN_1403ed2b0() != 0)
    {
        MS2Ptr<UIObject> spObj = FUN_1403ed2b0()->FUN_141adcea0(nId);
        if (spObj.get() != 0)
            return dynamic_cast<UIDialog*>(spObj.operator->());
    }
    return 0;
}

// @0x140c2e2c0
void UIInviteMentoringDialog::vfunc_66()
{
    UIDialog::vfunc_66();
    UIDialog* pMentor = FUN_140c300a0(0x4f4b);
    if (pMentor != 0)
    {
        if (pMentor->vfunc_55() == 0)
        {
            if (pMentor->FUN_1422dc430() != 0)
                FUN_141275c30(pMentor, this, DAT_143b02320, DAT_143b02320);
        }
    }
}

// @0x140c2e340
// MS2-FUNCTIONAL: behaviour-equivalent; temp slots / MS2Ptr glue pairing and EH unwind map differ from the exe
int UIInviteMentoringDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp(szMethod, "onCloseDialog") == 0)
    {
        vfunc_67();
        return 1;
    }
    if (_stricmp(szMethod, "onInviteMenteeBySN") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            unsigned __int64 nSerial = FUN_140718350(data.FUN_1422b8d30());
            FUN_140c2f860(nSerial, data.FUN_1422b8f40());
        }
        return 1;
    }
    if (_stricmp(szMethod, "onInviteMentee") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_140c2f860(0, data.FUN_1422b8f40());
        return 1;
    }
    if (_stricmp(szMethod, "OnAcceptMentoring") == 0)
    {
        if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x42) != 0)
        {
            FUN_141275260(0x2f7, 1, 1);
            return 1;
        }
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            unsigned __int64 nSerial = FUN_140718350(data.FUN_1422b8d30());
            CStringW strName = data.FUN_1422b8f40();
            CMsTime tEnd(FUN_140302b00()->FUN_14041d160()->FUN_140424e20());
            int nDay = tEnd.GetDay();
            int nMonth = tEnd.GetMonth();
            int nYear = tEnd.GetYear();
            CStringW strMsg = FUN_14028dfa0(CStringW(L"s_mentoring_mentor_accept_warn"), nYear, nMonth, nDay, strName);
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, CStringW(strMsg), 0, CStringW(L""));
            if (spBox.get() != 0)
            {
                spBox->FUN_141a024a0(0);
                spBox->FUN_1405340b0(nSerial);
                spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIInviteMentoringDialog::FUN_140c2fae0));
                FUN_140d73c60(spBox);
                return 1;
            }
        }
        return 1;
    }
    if (_stricmp(szMethod, "OnRejectMentoring") == 0)
    {
        if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x42) != 0)
        {
            FUN_141275260(0x2f7, 1, 1);
            return 1;
        }
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            unsigned __int64 nSerial = FUN_140718350(data.FUN_1422b8d30());
            COutPacket pkt(0xa1, 0);
            Unk_MMIdPacket7 req;
            req.id = nSerial;
            req.FUN_14069a6c0(pkt);
            FUN_140710590(pkt);
        }
        return 1;
    }
    if (_stricmp(szMethod, "onBuddy") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strName = data.FUN_1422b8f40();
            unsigned __int64 nChar = 0;
            Unk_GuildBuddyRef buddy = FUN_14097a780()->FUN_140ae4950(strName);
            if (buddy.FUN_14097a170() != 0)
            {
                nChar = buddy.FUN_14097a1e0()->FUN_1401cc2f0();
                if (buddy.FUN_14097a1e0()->FUN_1401cc5d0() != 0)
                {
                    FUN_140d73bc0(0x623, 0, 0, CStringW(L""));
                    return 1;
                }
            }
            CString strChar = FUN_140719530(nChar);
            Unk_InvUIMsg msg;
            Unk_InvArgs(msg).FUN_1422b7f70(0);
            Unk_InvArgs(msg).FUN_1422b7f70(1);
            Unk_InvArgs(msg).FUN_1422b8310(strName);
            Unk_InvArgs(msg).FUN_1422b82b0(strChar);
            UICommunityQueryDialog* pQuery = FUN_140ae5a30(0x4e4e);
            if (pQuery != 0)
                pQuery->OnMessage(this, reinterpret_cast<UIMsg*>(&msg));
        }
        return 1;
    }
    if (_stricmp(szMethod, "onWhisper") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strName = data.FUN_1422b8f40();
            if (FUN_141482e80()->m_48 != 0)
                FUN_141482e80()->m_48->FUN_141a252a0(strName);
        }
        return 1;
    }
    if (_stricmp(szMethod, "OnPopupMenu") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
        {
            float x = data.FUN_1422b8c10();
            float y = data.FUN_1422b8c10();
            CStringW strName = data.FUN_1422b8f40();
            unsigned __int64 nSerial = FUN_140718350(data.FUN_1422b8d30());
            Unk_PopupMenu* pMenu = FUN_140c30140(0x4e39);
            if (pMenu != 0)
            {
                Unk_PopupMenuInfo info(x, y, 3, 10, 0, "", NULL);
                pMenu->FUN_141a7f090(info, strName, nSerial, NULL, 0, 1);
            }
        }
        return 1;
    }
    return 0;
}

// @0x140c2f010
void UIInviteMentoringDialog::FUN_140c2f010()
{
    m_bMentorPage = true;
    FUN_1419246f0();
}

// @0x140c2f040
void UIInviteMentoringDialog::FUN_140c2f040()
{
    m_bMentorPage = false;
    FUN_1419246f0();
}

// @0x140c2f070
// MS2-FUNCTIONAL: behaviour-equivalent; frame slots / EH unwind map differ from the exe
void UIInviteMentoringDialog::FUN_140c2f070(const ATL::CAtlArray<Unk_MentorPtr<CMentor> >& arrMentors)
{
    if (m_bMentorPage != true && !(m_spPage == 0))
    {
        ASArray rows(2);
        for (unsigned i = 0; i < arrMentors.GetCount(); i++)
        {
            Unk_MentorPtr<CMentor> spMentor = arrMentors[i];
            if (!(spMentor == 0))
            {
                CStringW strInfo = FUN_1409e9ed0(CStringW(L"s_mentoring_invite_info"), FUN_1401a9d70()->FUN_141811980(6, spMentor->y), spMentor->level);
                ASObj row(2);
                row.FUN_1407cbbe0("isOnline", spMentor->online);
                row.FUN_1407cbb20("charName", CStringW(spMentor->name));
                row.FUN_1407cba60("mentorSN", FUN_140719530(spMentor->a));
                row.FUN_1407cba60("charSN", FUN_140719530(spMentor->c));
                row.FUN_1407cbb20("charInfo", CStringW(strInfo));
                rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
            }
        }
        m_spPage->FUN_140bd2cb0("buildCandidate", rows);
    }
}

// @0x140c2f440
void UIInviteMentoringDialog::FUN_140c2f440(const ATL::CAtlArray<Unk_MentorPtr<CMentor> >& arrMentors)
{
    m_mentors.RemoveAll();
    m_mentors.Copy(arrMentors);
    FUN_140c2f490();
}

// @0x140c2f490
// MS2-FUNCTIONAL: behaviour-equivalent; frame slots / EH unwind map differ from the exe
void UIInviteMentoringDialog::FUN_140c2f490()
{
    if (m_bMentorPage != false && !(m_spPage == 0))
    {
        ASArray rows(2);
        for (unsigned i = 0; i < m_mentors.GetCount(); i++)
        {
            Unk_MentorPtr<CMentor> spMentor = m_mentors[i];
            if (!(spMentor == 0))
            {
                CStringW strInfo = FUN_1409e9ed0(CStringW(L"s_mentoring_invite_info"), FUN_1401a9d70()->FUN_141811980(6, spMentor->y), spMentor->level);
                ASObj row(2);
                row.FUN_1407cbbe0("isOnline", spMentor->online);
                row.FUN_1407cbb20("charName", CStringW(spMentor->name));
                row.FUN_1407cba60("mentorSN", FUN_140719530(spMentor->a));
                row.FUN_1407cba60("charSN", FUN_140719530(spMentor->c));
                row.FUN_1407cbb20("charInfo", CStringW(strInfo));
                rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
            }
        }
        m_spPage->FUN_140bd2cb0("buildCandidate", rows);
    }
}

// @0x140c2f860
// MS2-FUNCTIONAL: behaviour-equivalent; frame slots / EH unwind map differ from the exe
void UIInviteMentoringDialog::FUN_140c2f860(__int64 nMentor, const CStringW& strName)
{
    if (FUN_14025e7b0()->flags.FUN_1402c4c90(0x41) == 0)
    {
        {
            Unk_TextFilterPtr filter = FUN_14025e7d0()->FUN_140229a50();
            Unk_TextFilter* pFilter = filter.FUN_14025cea0();
            if (pFilter != 0)
            {
                CStringW strBad;
                if (FUN_140225210(pFilter, strName, strBad, 0) != 0)
                {
                    FUN_1412751f0(strBad, 1, 1);
                    return;
                }
            }
        }
        COutPacket pkt(0xa1, 0);
        Unk_MMNamePacket5 req;
        req.name = strName;
        req.id = nMentor;
        req.FUN_14069a540(pkt);
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
    else
        FUN_141275260(0x2f7, 1, 1);
}

// @0x140c2fae0
bool UIInviteMentoringDialog::FUN_140c2fae0(int nResult, const CMsgBoxData& data)
{
    if (nResult != 0)
        return true;
    __int64 nSerial = data.FUN_141a02f10(0, 0);
    COutPacket pkt(0xa1, 0);
    Unk_MMIdPacket6 req;
    req.id = nSerial;
    req.FUN_14069a630(pkt);
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
