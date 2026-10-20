// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\messengerdata.h (name assumed: the exe has
// no __FILE__ string for this unit).
//
// The messenger's per-tab data. MessengerData::PanelSetting is a tab's XML "PanelSetting" block: which kinds of chat
// lines the tab shows (Notice / System / Subject / Require groups of 0/1 switches, each with an "all" master switch) and the
// Screen look (font size, background alpha, damage lines). MessengerData::TalkTab keeps one tab (name, close / detach /
// additive flags, its PanelSetting); TalkLog / ReportLog are chat log lines; GroupMessengerData::TalkLog is a group chat
// line. All are CPtred values. Namespaces for MessengerData / GroupMessengerData are assumed (the RTTI only names the
// nested classes). Names: FUN_<va> are non-virtual members, member names invented from use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class Unk_MdXml;

namespace MessengerData {

// "Notice" group of a PanelSetting (10 switches).
struct NoticeSetting
{
    NoticeSetting();                                // 0x141480c70 all on
    int FUN_141480d00(Unk_MdXml* pXml);             // 0x141480d00 load
    bool FUN_141480ef0(Unk_MdXml* pXml);            // 0x141480ef0 save
    int FUN_141481040(int nType);                  // 0x141481040 the line type is switched off
    int m_nAll;                                     // +0x00 "all"
    int m_nUser;                                    // +0x04 "user"
    int m_nTrade;                                   // +0x08 "trade"
    int m_nCommunity;                               // +0x0c "community"
    int m_nFriend;                                  // +0x10 "friend"
    int m_nGuild;                                   // +0x14 "guild"
    int m_nClub;                                    // +0x18 "club"
    int m_nParty;                                   // +0x1c "party"
    int m_nMentoring;                               // +0x20 "mentoring"
    int m_nEtc;                                     // +0x24 "etc"
};
MS2_CHECK_SIZE(NoticeSetting, 0x28);

// "System" group (3 switches).
struct SystemSetting
{
    SystemSetting();                                // 0x141481210
    int FUN_141481250(Unk_MdXml* pXml);             // 0x141481250 load
    bool FUN_141481320(Unk_MdXml* pXml);            // 0x141481320 save
    int FUN_1414813b0(int nType);                  // 0x1414813b0
    int m_nAll;                                     // +0x00 "all"
    int m_nEvent;                                   // +0x04 "event"
    int m_nNotice;                                  // +0x08 "notice"
    int m_pad_0c;                                   // +0x0c (never written)
};
MS2_CHECK_SIZE(SystemSetting, 0x10);

// "Screen" look (font size, background alpha, damage lines).
struct ScreenSetting
{
    ScreenSetting();                                // 0x141481440 17, 50, 1
    bool FUN_141481480(Unk_MdXml* pXml);            // 0x141481480 load
    bool FUN_141481540(Unk_MdXml* pXml);            // 0x141481540 save
    int m_nFontSize;                                // +0x00 "fontSize"
    int m_nBackgroundAlpha;                         // +0x04 "backgroundAlpha"
    int m_nShowDamage;                              // +0x08 "showDamage"
};
MS2_CHECK_SIZE(ScreenSetting, 0xc);

// "Require" group (7 switches).
struct RequireSetting
{
    RequireSetting();                               // 0x1414815d0
    int FUN_141481640(Unk_MdXml* pXml);             // 0x141481640 load
    bool FUN_1414817b0(Unk_MdXml* pXml);            // 0x1414817b0 save
    int FUN_1414818b0(int nType);                  // 0x1414818b0
    int m_nAll;                                     // +0x00 "all"
    int m_nMeso;                                    // +0x04 "meso"
    int m_nMerat;                                   // +0x08 "merat"
    int m_nToken;                                   // +0x0c "token"
    int m_nItem;                                    // +0x10 "item"
    int m_nExperience;                              // +0x14 "experience"
    int m_nAuth;                                    // +0x18 "auth"
};

// "Subject" group (11 switches).
struct SubjectSetting
{
    SubjectSetting();                               // 0x141481a10
    int FUN_141481ab0(Unk_MdXml* pXml);             // 0x141481ab0 load
    int FUN_141481cf0(Unk_MdXml* pXml);             // 0x141481cf0 save
    int FUN_141481e90(int nType);                  // 0x141481e90
    int m_nAll;                                     // +0x00 "all"
    int m_nSuper;                                   // +0x04 "super"
    int m_nWorld;                                   // +0x08 "world"
    int m_nChannel;                                 // +0x0c "channel"
    int m_nSocial;                                  // +0x10 "social"
    int m_nParty;                                   // +0x14 "party"
    int m_nGuild;                                   // +0x18 "guild"
    int m_nWhisper;                                 // +0x1c "whisper"
    int m_nClub;                                    // +0x20 "club" (feature 0x56)
    int m_nPartyInvite;                             // +0x24 "partyInvite"
    int m_nDungeonHelp;                             // +0x28 "dungeonHelp" (feature 0x93)
};

// A tab's chat filter (XML "PanelSetting").
class PanelSetting
{
public:
    PanelSetting();                                 // 0x1414820e0
    int FUN_141482150();                            // 0x141482150 "global": all tabs share one screen look
    NoticeSetting* FUN_141482170();                 // 0x141482170
    SystemSetting* FUN_141482190();                 // 0x141482190
    ScreenSetting* FUN_1414821b0();                 // 0x1414821b0 the shared screen look when "global" is set
    RequireSetting* FUN_1414821e0();                // 0x1414821e0
    SubjectSetting* FUN_141482200();                // 0x141482200
    int FUN_141482220(Unk_MdXml* pXml);             // 0x141482220 load
    int FUN_141482340(Unk_MdXml* pXml);             // 0x141482340 save
    int FUN_141482460(int nType);                   // 0x141482460 the line type is switched off in any group
    NoticeSetting m_notice;                         // +0x00
    SystemSetting m_system;                         // +0x28
    ScreenSetting m_screen;                         // +0x38
    RequireSetting m_require;                       // +0x44
    SubjectSetting m_subject;                       // +0x60
};
MS2_CHECK_SIZE(PanelSetting, 0x8c);

class TalkLog : public CPtred
{
public:
    TalkLog();                                      // 0x141482500
    TalkLog(CStringW strMsg, int nKind);            // 0x141482570
    // implicit virtual dtor                        //  0 0x1414845c0 (??_G 0x1414846a0); none declared, so the implicit move
    //                                                 ctor exists (CAtlList::RemoveHead returns by move, 0x141a2bb30)
    CStringW m_strMsg;                              // +0x18
    int m_nKind;                                    // +0x20
};
MS2_CHECK_SIZE(TalkLog, 0x28);

class ReportLog : public CPtred
{
public:
    ReportLog(CStringW strName, CStringW strMsg);   // 0x1414825f0
    // implicit virtual dtor                        //  0 0x141484520 (??_G 0x141484620); none declared, so the implicit move
    //                                                 ctor exists (CAtlList::RemoveHead returns by move, 0x141a2ba30)
    CStringW m_strName;                             // +0x18
    CStringW m_strMsg;                              // +0x20
};
MS2_CHECK_SIZE(ReportLog, 0x28);

class TalkTab : public CPtred
{
public:
    TalkTab();                                      // 0x141482680
    TalkTab(CStringW strName, int nClose, int nDetach, int nAdditive);   // 0x141482710
    virtual ~TalkTab() = default;                   //  0 0x1414845f0 (??_G 0x1414846e0)
    int FUN_1414827c0(Unk_MdXml* pXml);             // 0x1414827c0 load
    int FUN_141482880(Unk_MdXml* pXml);             // 0x141482880 save
    CStringW FUN_141482940();                       // 0x141482940 the tab name
    int m_nClose;                                   // +0x18 "close"
    int m_nDetach;                                  // +0x1c "detach"
    int m_nAdditive;                                // +0x20 "additive"
    CStringW m_strName;                             // +0x28 "tabName"
    PanelSetting m_panel;                           // +0x30
};
MS2_CHECK_SIZE(TalkTab, 0xc0);

}   // namespace MessengerData

namespace GroupMessengerData {

class TalkLog : public CPtred
{
public:
    TalkLog();                                      // 0x141483eb0
    TalkLog(int nKind, CStringW strName, CStringW strMsg);   // 0x141483f50
    TalkLog(int nKind, CStringW strName, CStringW strMsg, int nA, int nB);   // 0x141484010
    virtual ~TalkLog() = default;                   //  0 0x141484580 (??_G 0x141484660)
    CStringW m_strName;                             // +0x18
    CStringW m_strMsg;                              // +0x20
    int m_nKind;                                    // +0x28
    int m_nA;                                       // +0x2c
    int m_nB;                                       // +0x30
};
MS2_CHECK_SIZE(TalkLog, 0x38);

}   // namespace GroupMessengerData
