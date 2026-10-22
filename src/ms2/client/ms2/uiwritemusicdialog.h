// uiwritemusicdialog.h - UIWriteMusicDialog (RTTI .?AVUIWriteMusicDialog@@, 0x270 bytes: UIDialog + the score editor),
// the music score writing window ("WriteMusicDialog", UI type 0x4eed): a blank score item is filled with MML text in up
// to ten tabs (one melody and nine chords), previewed through the instrument manager with a piano roll, saved to / loaded
// from ./Custom/Music/*.ms2mml and finally sent to the server (the terms box, then CInstrumentManager::SendCompose). It
// also shows a written score read-only (mode 2). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is
// `?\uiwritemusicdialog.cpp`. Header/unit name assumed; member names are invented from use. The v2525 snapshot only
// gives the size (0x270) and the base.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h) with the IMessageListener at +0x18. Overridden slots: 1 (movie name),
// 22 (OnLoadComplete: instrument list, tab bar, piano roll), 26, 28 (AS -> C++ commands), 48 (UI type 0x4eed),
// 67 (close: stop and reset), 71 (ask before closing a dirty score), 72 (per frame: the play timer), IMessageListener 0
// (the message box answers "completeMakeScore", "askClose", "askRemoveTabMusic", "askLoadFile").
#pragma once

#include <afx.h>

#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class ASArray;
class ASData;
class ASDataProvider;
class ASMovieClip;
class ASTextField;
class ASButtonBar;
class ASUIComponent;
class ASDropdownMenu;
class MMLToken;
class Unk_WmSlider;
class Unk_140165cf0;
class UISwfEntity;
class UIMsg;

// The score being sent (0x28 bytes; the payload of CInstrumentManager::SendCompose, reset by FUN_1401ffd60). The
// implicit ctor / dtor are COMDATs of this unit (0x141000240 / 0x1410006c0).
struct Unk_WmScore
{
    unsigned __int64 m_nItemUid;                                               // +0x00 the blank score item
    unsigned m_nLength;                                                     // +0x08 the play time (ms)
    int m_nInstrument;                                                      // +0x0c the instrument category
    CStringW m_strTitle;                                                    // +0x10
    CString m_strMml;                                                       // +0x18 the tabs joined by ":"
    int m_nType;                                                            // +0x20 10

    Unk_WmScore() : m_nItemUid(0), m_nLength(0), m_nInstrument(0), m_nType(10) {}
};
MS2_CHECK_SIZE(Unk_WmScore, 0x28);

class UIWriteMusicDialog : public UIDialog
{
public:
    typedef std::multimap<unsigned, MS2Ptr<MMLToken> > NoteMap;             // start time (ms) -> note
    typedef std::map<int, NoteMap> TabNotes;                                // tab -> its notes in the page
    typedef std::map<int, TabNotes> PageNotes;                              // piano roll page (12 s) -> tabs

    UIWriteMusicDialog();                                                   // 0x140fed9c0
    virtual ~UIWriteMusicDialog();                                          //  0 0x140fedbb0 (??_G 0x141001a40)
    virtual CString vfunc_1();                                              //  1 0x140fedd90 "WriteMusicDialog"
    virtual void OnLoadComplete();                                          // 22 0x140fedde0
    virtual void vfunc_26();                                                // 26 0x140fee700
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140fee900
    virtual int vfunc_48() { return 0x4eed; }                               // 48 0x141001c20
    virtual void vfunc_67();                                                // 67 0x140fee720
    virtual int vfunc_71();                                                 // 71 0x140fef5d0
    virtual void vfunc_72();                                                // 72 0x140fef6c0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);               // IMessageListener 0 0x140fef2f0

    MS2Ptr<CItem> FUN_140fef760();                                          // 0x140fef760 the score item
    bool FUN_140fef7b0(MS2Ptr<CItem> spItem);                               // 0x140fef7b0 write a blank score
    bool FUN_140fef8f0(MS2Ptr<CItem> spItem);                               // 0x140fef8f0 view a written score
    void FUN_140fefd00(MS2Ptr<CItem> spItem);                               // 0x140fefd00 the score was made (server answer)
    void FUN_140ff0090(int nResult);                                        // 0x140ff0090 the make request failed / ended
    void FUN_140ff0260(unsigned __int64 nItemUid, const CString& strMml);            // 0x140ff0260 the score text arrived
    void FUN_140ff03b0(ASData* pArgs);                                      // 0x140ff03b0 "onClickMake"
    void OnClickPlayGoFirstAndPause();                                                   // 0x140ff12a0 rewind and pause
    void FUN_140ff12d0(ASData* pArgs);                                      // 0x140ff12d0 "onClickPlayStart"
    void FUN_140ff1a20();                                                   // 0x140ff1a20 stop
    void FUN_140ff1aa0();                                                   // 0x140ff1aa0 pause
    void FUN_140ff1b10(int nPage);                                          // 0x140ff1b10 rebuild the piano roll
    void OnClickSaveFile();                                                   // 0x140ff1e40 save to a file
    void OnClickLoadFile();                                                   // 0x140ff2060 load from a file (ask while dirty)
    void FUN_140ff21a0(ASData* pArgs);                                      // 0x140ff21a0 the play bar moved
    void FUN_140ff23b0(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x140ff23b0 the play bar tooltip
    void FUN_140ff2500(unsigned __int64 nItemUid);                                // 0x140ff2500 the score text (cache or request)
    void FUN_140ff2600();                                                   // 0x140ff2600 the open file box
    void FUN_140ff2700(const CStringW& strPath);                            // 0x140ff2700 load an .ms2mml file
    void FUN_140ff2cf0(const CStringW& strPath);                            // 0x140ff2cf0 save an .ms2mml file
    bool FUN_140ff3230(Unk_140165cf0* pElem, int nMax, CString& strOut, int* pnTotal);   // 0x140ff3230 one tab of the file
    void FUN_140ff3350(bool bVisible);                                      // 0x140ff3350 "setPlayStartButtonVisible"
    bool FUN_140ff33c0();                                                   // 0x140ff33c0 "m_dirtyMusicScore"
    void FUN_140ff3450(bool bDirty);                                        // 0x140ff3450 set "m_dirtyMusicScore"
    int FUN_140ff34b0();                                                    // 0x140ff34b0 "m_totalLength"
    void FUN_140ff3540();                                                   // 0x140ff3540 reset the play state
    void FUN_140ff35a0();                                                   // 0x140ff35a0 m_bPlaying = false
    void FUN_140ff35c0(int nOffset, int nLength);                           // 0x140ff35c0 the play window
    void FUN_140ff3610(int nTime);                                          // 0x140ff3610 the current time text / play bar
    void FUN_140ff38f0(int nLength);                                        // 0x140ff38f0 the total time text / play bar
    void FUN_140ff3d10(unsigned nTime);                                     // 0x140ff3d10 the playing line
    bool FUN_140ff3e50(MS2Ptr<ASDataProvider> spTabs, CString& strOut);     // 0x140ff3e50 the tabs as one MML text (unused result)
    int FUN_140ff40b0();                                                    // 0x140ff40b0 the score's max length
    void FUN_140ff41a0();                                                   // 0x140ff41a0 fill the tabs from m_strText
    void FUN_140ff43a0(const CString& strMelody, ASArray& chords, const CStringW& strTitle, int nInstrument);   // 0x140ff43a0
    void FUN_140ff4500(MS2Ptr<CItem> spItem);                               // 0x140ff4500 m_spItem = spItem
    bool FUN_140ff4550();                                                   // 0x140ff4550 roll type 0 (per time)
    void FUN_140ff4610(std::map<int, CString>& tabs);                       // 0x140ff4610 parse the tabs into m_pages
    void FUN_140ff4a80();                                                   // 0x140ff4a80 draw the piano roll page
    void FUN_140ff57e0();                                                   // 0x140ff57e0 lock the roll controls
    void FUN_140ff59a0();                                                   // 0x140ff59a0 unlock the roll controls
    CStringW FUN_140ff5be0(int nPitch, int nTab, unsigned long nColor);     // 0x140ff5be0 the note tooltip

    MS2Ptr<ASDropdownMenu> FUN_140c28560(const CString& strName);           // 0x140c28560 bind the dropdown child

private:
    MS2_LAYOUT_FRIEND;
    bool m_bPlaying;                                                        // +0x178
    unsigned m_nEndTick;                                                    // +0x17c
    int m_nStartTick;                                                       // +0x180
    int m_nRemoveTab;                                                       // +0x184 the tab asked to be removed (-1)
    MS2Ptr<CItem> m_spItem;                                                 // +0x188 the score item
    MS2Ptr<ASTextField> m_spTimer;                                          // +0x198 "m_playingMusic.m_timer"
    MS2Ptr<ASTextField> m_spTotalTimer;                                     // +0x1a8 "m_playingMusic.m_totalTimer"
    MS2Ptr<Unk_WmSlider> m_spPlayBar;                                       // +0x1b8 "m_playBar"
    MS2Ptr<ASButtonBar> m_spTabs;                                           // +0x1c8 "m_tabMusic"
    MS2Ptr<ASMovieClip> m_spPlayLine;                                       // +0x1d8 "m_playLine"
    int m_nMode;                                                            // +0x1e8 0 none, 1 write, 2 view
    CStringW m_strTimerFormat;                                              // +0x1f0
    CString m_strPlayMml;                                                   // +0x1f8 the MML being previewed
    CString m_strText;                                                      // +0x200 the viewed score's MML
    Unk_WmScore m_score;                                                    // +0x208
    std::map<unsigned __int64, CString> m_texts;                                   // +0x230 score item uid -> MML
    int m_nPage;                                                            // +0x240 the piano roll page
    PageNotes m_pages;                                                      // +0x248
    std::vector<MS2Ptr<ASUIComponent> > m_notes;                            // +0x258 the note clips of the page
};
MS2_CHECK_SIZE(UIWriteMusicDialog, 0x270);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_bPlaying, 0x178);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_spItem, 0x188);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_spPlayBar, 0x1b8);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_spPlayLine, 0x1d8);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_nMode, 0x1e8);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_strText, 0x200);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_score, 0x208);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_texts, 0x230);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_nPage, 0x240);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_pages, 0x248);
MS2_CHECK_OFFSET(UIWriteMusicDialog, m_notes, 0x258);
