// uipvpteamresultdialog.h - UIPvPTeamResultDialog (RTTI .?AVUIPvPTeamResultDialog@@, 0x198 bytes, UIDialog, UI id 0x4ed2,
// swf "PvPTeamResultDialog"): the result of a team PvP match (battlefield): the two teams' members (kill / death / steal /
// job rows, "AddOrUpdateTeamMember"), the team scores ("UpdateScore"), the own team ("SetMyTeam") and the last result with
// the reward ("showLastResult"). Teams are the ids 0xc9 and 0xca. Owning unit: ?\uipvpteamresultdialog.cpp. Header name
// assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include <set>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class ASObj;
class Unk_PtMember;

class UIPvPTeamResultDialog : public UIDialog
{
public:
    UIPvPTeamResultDialog();                                    // 0x1413450d0
    virtual ~UIPvPTeamResultDialog();                           //  0 0x141345160 (??_G 0x141346590)
    virtual CString GetTypeName();                                  //  1 0x1413451b0 "PvPTeamResultDialog"
    virtual void OnLoadComplete();                              // 22 0x141345290
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1413461d0 "OnClose"
    virtual void vfunc_43();                                    // 43 0x141346270
    virtual int vfunc_48() { return 0x4ed2; }                   // 48 0x141346640
    virtual void vfunc_67();                                    // 67 0x141345200 tell the server the result was seen

    void FUN_1413452c0();                                       // reset the result
    void FUN_141345310();                                       // find the own team
    void FUN_1413454b0();                                       // push all team members
    void FUN_1413456a0();                                       // push the scores
    void FUN_141345740(int nTeam, int nCount);                  // set the result: winning team, reward count
    void FUN_1413457f0();                                       // push the last result
    int FUN_141345c60(ASObj& obj, int nIndex, Unk_PtMember* pMember);   // one member row
    void FUN_141345de0();                                       // push everything
    void FUN_141345e40();                                       // push the own team
    CString FUN_141345eb0(unsigned int nItemId, int nAmount);   // bind the reward item, returns its slot name
    void FUN_141346140();                                       // unbind the reward slots

private:
    MS2_LAYOUT_FRIEND;
    int m_nCount;                                               // +0x178 reward amount, -1 = no result yet
    int m_nUnk17c;                                              // +0x17c
    int m_nWinTeam;                                             // +0x180 1 = team 0xc9, 2 = team 0xca, 0 = none
    int m_nMyTeam;                                              // +0x184 the same codes for the own team
    std::set<CString> m_slots;                                  // +0x188 names of the bound reward slots
};
MS2_CHECK_SIZE(UIPvPTeamResultDialog, 0x198);
MS2_CHECK_OFFSET(UIPvPTeamResultDialog, m_nCount, 0x178);
MS2_CHECK_OFFSET(UIPvPTeamResultDialog, m_nMyTeam, 0x184);
MS2_CHECK_OFFSET(UIPvPTeamResultDialog, m_slots, 0x188);
