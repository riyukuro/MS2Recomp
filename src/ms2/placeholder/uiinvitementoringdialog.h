// uiinvitementoringdialog.h - PLACEHOLDER for UIInviteMentoringDialog (RTTI .?AVUIInviteMentoringDialog@@, vftable
// 0x142e03170). NOT an original header; only what guess\menteesearch.cpp calls is declared.
#pragma once

#include "ms2/client/ms2/uidialog.h"
#include "ms2/commonfiles/mentor.h"

class UIInviteMentoringDialog : public UIDialog
{
public:
    UIInviteMentoringDialog();
    void FUN_140c2f070(const ATL::CAtlArray<Unk_MentorPtr<CMentor> >& arrMentors);  // 0x140c2f070
    void FUN_140c2f440(const ATL::CAtlArray<Unk_MentorPtr<CMentor> >& arrMentors);  // 0x140c2f440 shows the list
};
