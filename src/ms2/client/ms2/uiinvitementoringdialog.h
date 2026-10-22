// uiinvitementoringdialog.h - UIInviteMentoringDialog (RTTI .?AVUIInviteMentoringDialog@@, base UIDialog; 0x1b0 bytes):
// the mentoring invitation window (UI id 0x4f4c, "InviteMentoringDialog"). Page 0 ("mentee") lists the mentors that asked
// the player (mentor list packet 0xa1/2), page 1 ("mentor") lists the mentee candidates the search service found; both
// rows are built into the movie with "buildCandidate". It also answers the accept / reject / invite buttons and the
// buddy / whisper / popup-menu buttons of a row. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name
// assumed, member names invented. Ctor 0x140c2dea0, dtor 0x140c2df20 (deleting 0x140c305d0).
// Replaces placeholder/uiinvitementoringdialog.h (kept as a forwarding include).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/mentor.h"

class ASMovieClip;
class CMsgBoxData;

class UIInviteMentoringDialog : public UIDialog
{
public:
    UIInviteMentoringDialog();                                      // 0x140c2dea0
    virtual ~UIInviteMentoringDialog();                             //  0 0x140c2df20 (??_G 0x140c305d0)
    virtual CString GetTypeName();                                      //  1 0x140c2df90 "InviteMentoringDialog"
    virtual void OnLoadComplete();                                  // 22 0x140c2e020 picks the page and asks for its list
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c2e340 the movie's buttons
    virtual int vfunc_48();                                         // 48 0x140c30610 0x4f4c
    virtual void vfunc_66();                                        // 66 0x140c2e2c0 docks beside the mentor dialog
    virtual void vfunc_67();                                        // 67 0x140c2dfe0 Close: back to the mentor page, drops the clip

    void FUN_140c2f010();                                           // 0x140c2f010 show the mentor page
    void FUN_140c2f040();                                           // 0x140c2f040 show the mentee page
    void FUN_140c2f070(const ATL::CAtlArray<Unk_MentorPtr<CMentor> >& arrMentors);   // 0x140c2f070 rows of the mentee page from the packet list
    void FUN_140c2f440(const ATL::CAtlArray<Unk_MentorPtr<CMentor> >& arrMentors);   // 0x140c2f440 keep the search list and show it
    void FUN_140c2f490();                                           // 0x140c2f490 rows of the mentor page from the kept list
    void FUN_140c2f860(__int64 nMentor, const CStringW& strName);         // 0x140c2f860 invite one (packet 0xa1 / 5)
    bool FUN_140c2fae0(int nResult, const CMsgBoxData& data);       // 0x140c2fae0 accept answer (packet 0xa1 / 6)

    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);      // movie clip child lookup (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    bool m_bMentorPage;                                             // +0x178 1 = mentor page (search list), 0 = mentee page
    MS2Ptr<ASMovieClip> m_spPage;                                   // +0x180 "menteePage" / "mentorPage"
    ATL::CAtlArray<Unk_MentorPtr<CMentor> > m_mentors;              // +0x190 the kept search list
};
MS2_CHECK_SIZE(UIInviteMentoringDialog, 0x1b0);
MS2_CHECK_OFFSET(UIInviteMentoringDialog, m_bMentorPage, 0x178);
MS2_CHECK_OFFSET(UIInviteMentoringDialog, m_spPage, 0x180);
MS2_CHECK_OFFSET(UIInviteMentoringDialog, m_mentors, 0x190);
