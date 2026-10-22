// uipvpguildteamresultdialog.h - UIPvPGuildTeamResultDialog (RTTI .?AVUIPvPGuildTeamResultDialog@@, 0x210 bytes,
// UIDialog, UI id 0x4ec7, swf "PvPGuildTeamResultDialog"): the result of a guild battle - the two guilds (name, mark,
// score, result, time) and the reward text / icon. The server feeds it with a packet: mode 0 = the guild battle result
// (FUN_141340d70), mode 1 = the vs-game result (FUN_141341220). Owning unit: ?\uipvpguildteamresultdialog.cpp. Header
// name assumed from the unit path; member names are invented from use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"

class CInPacket;

// One guild of the result (read from the packet).
struct Unk_PgtrGuild
{
    Unk_PgtrGuild();                                            // 0x1413405b0 (dtor 0x1413424c0)

    void FUN_141340650(CInPacket* pIn);                         // read the guild battle form
    void FUN_141340810(CInPacket* pIn);                         // read the vs-game form

    __int64 m_nGuildId;                                         // +0x00
    int m_nScore;                                               // +0x08
    int m_nMin;                                                 // +0x0c
    int m_nSec;                                                 // +0x10
    CStringW m_strName;                                         // +0x18
    CStringW m_strMark;                                         // +0x20 the guild mark file
    CStringW m_strResult;                                       // +0x28 "win" / "lose" / "draw"
    CStringW m_strTime;                                         // +0x30 the time text
};
MS2_CHECK_SIZE(Unk_PgtrGuild, 0x38);

class UIPvPGuildTeamResultDialog : public UIDialog
{
public:
    UIPvPGuildTeamResultDialog();                               // 0x1413409a0
    virtual ~UIPvPGuildTeamResultDialog();                      //  0 0x141340aa0 (??_G 0x141342520)
    virtual CString GetTypeName();                                  //  1 0x141340b30 "PvPGuildTeamResultDialog"
    virtual void OnLoadComplete();                              // 22 0x141340b80
    virtual void vfunc_26();                                    // 26 0x141340bb0 tell the server the result was seen
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141340c20 "OnClose"
    virtual void vfunc_43();                                    // 43 0x141340cc0
    virtual int vfunc_48() { return 0x4ec7; }                   // 48 0x141342560

    void FUN_141340d70(CInPacket* pIn);                         // the guild battle result packet
    void FUN_141341220(CInPacket* pIn);                         // the vs-game result packet
    void FUN_1413415e0(__int64 nGuildId, const CStringW& strMark);   // a guild's mark
    void FUN_1413418a0();                                       // push everything to the movie
    void FUN_141341e70();                                       // play the result sounds
    Unk_PgtrGuild* FUN_141342040(bool bLeft);                   // the guild shown on the left / right
    Unk_PgtrGuild* FUN_1413420e0(__int64 nGuildId, bool bOther);   // the given guild, or the other one
    void FUN_141342190();                                       // win / lose / draw from the scores

private:
    MS2_LAYOUT_FRIEND;
    int m_nMode;                                                // +0x178 0 = guild battle, 1 = vs-game
    int m_pad_17c;
    Unk_PgtrGuild m_guildA;                                     // +0x180
    Unk_PgtrGuild m_guildB;                                     // +0x1b8
    bool m_bOwnA;                                               // +0x1f0 the own guild is guild A
    bool m_bSound;                                              // +0x1f1 play the result sounds
    bool m_bSwap;                                               // +0x1f2 guild A is shown on the left
    CStringW m_strTitle;                                        // +0x1f8
    CStringW m_strReward;                                       // +0x200
    int m_nRewardItem;                                          // +0x208
};
MS2_CHECK_SIZE(UIPvPGuildTeamResultDialog, 0x210);
MS2_CHECK_OFFSET(UIPvPGuildTeamResultDialog, m_nMode, 0x178);
MS2_CHECK_OFFSET(UIPvPGuildTeamResultDialog, m_guildA, 0x180);
MS2_CHECK_OFFSET(UIPvPGuildTeamResultDialog, m_guildB, 0x1b8);
MS2_CHECK_OFFSET(UIPvPGuildTeamResultDialog, m_bOwnA, 0x1f0);
MS2_CHECK_OFFSET(UIPvPGuildTeamResultDialog, m_strTitle, 0x1f8);
MS2_CHECK_OFFSET(UIPvPGuildTeamResultDialog, m_nRewardItem, 0x208);
