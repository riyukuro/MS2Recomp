// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uipvpguildteamdialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UIPvPGuildTeamDialog is the guild battle (guild vs guild PvP) HUD ("PvPGuildTeamDialog", UI type 0x4ec4): the two
// guild names and marks, the round number, the round timer, the scores and three player slots per side (name, job
// level, hp bar, an observe button). The server feeds it with packet 0x9a ('s' round state, 't' round result).
// RTTI .?AVUIPvPGuildTeamDialog@@, 0x288 bytes, vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset> or invented.
#pragma once

#include <afx.h>
#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"

class ASUIComponent;
class CInPacket;
class PCBase;

// The two guilds of the match (packet order: id, name and mark of the first guild, then of the second).
struct Unk_PvPGuildTeamInfo
{
    Unk_PvPGuildTeamInfo() : m_nGuildIdA(0), m_nGuildIdB(0) {}      // 0x14133ea00 (dtor 0x14133eb80)

    __int64 m_nGuildIdA;                // +0x00
    __int64 m_nGuildIdB;                // +0x08
    CStringW m_strNameA;                // +0x10
    CStringW m_strNameB;                // +0x18
    CStringW m_strMarkA;                // +0x20 the guild mark file (turned into a URL)
    CStringW m_strMarkB;                // +0x28
};
MS2_CHECK_SIZE(Unk_PvPGuildTeamInfo, 0x30);

// A guild's score in the round.
struct Unk_PvPGuildScore
{
    Unk_PvPGuildScore() : m_nGuildId(0), m_nScore(0) {}             // 0x14133c400
    Unk_PvPGuildScore& operator=(const Unk_PvPGuildScore& o)        // 0x14133c430
    {
        m_nGuildId = o.m_nGuildId;
        m_nScore = o.m_nScore;
        return *this;
    }

    __int64 m_nGuildId;                 // +0x00
    int m_nScore;                       // +0x08
};
MS2_CHECK_SIZE(Unk_PvPGuildScore, 0x10);

// The round state ('s' of packet 0x9a). Copy assignment 0x14133ec00, dtor 0x14133ebe0.
struct Unk_PvPGuildRoundInfo
{
    Unk_PvPGuildRoundInfo() { FUN_14133f100(); }                    // 0x14133ea80
    void FUN_14133f100()                                            // 0x14133f100 reset
    {
        m_nRound = 0;
        m_nEndTime = 0;
        m_n8 = 0;
        m_nC = 0;
        m_characters.clear();
        m_scoreA.m_nGuildId = 0;
        m_scoreA.m_nScore = 0;
        m_scoreB.m_nGuildId = 0;
        m_scoreB.m_nScore = 0;
    }

    int m_nRound;                       // +0x00 0 = no round yet
    unsigned m_nEndTime;                // +0x04 the tick the round ends at; 0 = no timer
    int m_n8;                           // +0x08
    int m_nC;                           // +0x0c
    std::vector<__int64> m_characters;  // +0x10 the fighting characters of both guilds
    Unk_PvPGuildScore m_scoreA;         // +0x28
    Unk_PvPGuildScore m_scoreB;         // +0x38
};
MS2_CHECK_SIZE(Unk_PvPGuildRoundInfo, 0x48);

class UIPvPGuildTeamDialog : public UIDialog
{
public:
    UIPvPGuildTeamDialog();                                                                         // 0x141339640
    virtual ~UIPvPGuildTeamDialog();                                                                //  0 0x141339780
    virtual CString GetTypeName();                                                                      //  1 0x141339880
    virtual void OnLoadComplete();                                                                  // 22 0x1413399a0
    virtual void vfunc_26();                                                                        // 26 0x141339c50
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x14133b3f0
    virtual void vfunc_43();                                                                        // 43 0x14133b780
    virtual int vfunc_48() { return 0x4ec4; }                                                       // 48 (COMDAT 0x14133f180)
    virtual int vfunc_65();                                                                         // 65 0x1413398d0
    virtual void vfunc_67();                                                                        // 67 0x141339900
    virtual void vfunc_72();                                                                        // 72 0x141339950 per-frame: the timer
    virtual void vfunc_79(void* pData);                                                             // 79 0x141339d00 packet 0x9a

    void FUN_14133a210(CInPacket* pPacket);                         // read the two guilds
    void FUN_14133a4a0(const Unk_PvPGuildTeamInfo& info);           // show the guild names and marks (own guild left)
    void FUN_14133a7a0(const Unk_PvPGuildRoundInfo& info);          // show a round (kept for OnLoadComplete if not loaded)
    void FUN_14133afb0(__int64 nCharId, __int64 nHp, __int64 nMaxHp);    // a player's hp bar
    void FUN_14133b0b0();                                           // forget the observed player
    void FUN_14133b0f0(__int64 nGuildId, const CStringW& strMark);  // a guild's mark
    bool FUN_14133b830(CStringW strGuildName);                      // the name is the own guild's
    bool FUN_14133b8c0(__int64 nGuildId);                           // the id is the own guild's
    void FUN_14133b900(unsigned nEndTime);                          // the remaining time ("mmss")
    void FUN_14133bab0(MS2Ptr<ASUIComponent> spSlot, PCBase* pPC, bool bPlaying);    // fill a player slot
    void FUN_14133bd80(CStringW strName);                           // observe a player
    void FUN_14133bec0();                                           // stop observing
    void FUN_14133bf60(PCBase* pTarget);                            // check the observe button of the observed player

private:
    MS2_LAYOUT_FRIEND;
    Unk_PvPGuildTeamInfo m_info;                                    // +0x178
    Unk_PvPGuildRoundInfo m_round;                                  // +0x1a8 the round received before the movie loaded
    __int64 m_1f0;                                                  // +0x1f0
    unsigned m_nEndTime;                                            // +0x1f8 the round's end tick
    CStringW m_strObserved;                                         // +0x200 the observed player's name
    MS2Ptr<ASUIComponent> m_spComponent;                            // +0x208 "m_pvpGuildTeamComponent"
    MS2Ptr<ASUIComponent> m_spLeftPlayers[3];                       // +0x218 own guild
    MS2Ptr<ASUIComponent> m_spRightPlayers[3];                      // +0x248
    std::map<unsigned __int64, MS2Ptr<ASUIComponent> > m_slots;     // +0x278 the slot of each shown character (unsigned key: less<unsigned __int64> 0x14044a540)
};
MS2_CHECK_SIZE(UIPvPGuildTeamDialog, 0x288);
MS2_CHECK_OFFSET(UIPvPGuildTeamDialog, m_info, 0x178);
MS2_CHECK_OFFSET(UIPvPGuildTeamDialog, m_round, 0x1a8);
MS2_CHECK_OFFSET(UIPvPGuildTeamDialog, m_1f0, 0x1f0);
MS2_CHECK_OFFSET(UIPvPGuildTeamDialog, m_strObserved, 0x200);
MS2_CHECK_OFFSET(UIPvPGuildTeamDialog, m_spComponent, 0x208);
MS2_CHECK_OFFSET(UIPvPGuildTeamDialog, m_slots, 0x278);
