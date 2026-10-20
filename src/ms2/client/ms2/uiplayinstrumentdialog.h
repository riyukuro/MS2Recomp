// uiplayinstrumentdialog.h - UIPlayInstrumentDialog (RTTI .?AVUIPlayInstrumentDialog@@, 0x288 bytes: UIDialog + the
// instrument play page, the score page and the key tables), the instrument playing window ("PlayInstrumentDialog", UI type
// 0x4eec). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\uiplayinstrumentdialog.cpp` (dir
// client\ms2). Header/unit name assumed. Member names are invented from use.
//
// Bases: UIDialog (src/ms2/client/ms2/uidialog.h) with the IMessageListener at +0x18. Overridden slots: 1 (movie name),
// 22 (OnLoadComplete: bind the play page / score page / tab bar), 26 (release the bound children), 28 (AS -> C++ commands),
// 45 (ExternalInterface: item tooltip), 48 (UI type 0x4eec), 53/54 (save / load the last tab), 67 (close: reset the
// instrument mode), 71 (ask before closing while a score plays), 72 (per frame: key input), IMessageListener 0 ("askClose"
// answer).
#pragma once

#include <afx.h>

#include <map>
#include <utility>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CItem;
class ASMovieClip;
class ASTextField;
class Unk_140acd6e0;
class Unk_PiTabBar;

class UIPlayInstrumentDialog : public UIDialog
{
public:
    typedef std::pair<int, MS2Ptr<Unk_140acd6e0> > KeyButton;              // note index, the key button
    typedef std::map<int, KeyButton> KeyButtonMap;                         // keyboard key -> button
    typedef std::map<int, unsigned long> PressedMap;                           // keyboard key -> the note being played

    UIPlayInstrumentDialog();                                               // 0x14100a030
    virtual ~UIPlayInstrumentDialog();                                      //  0 0x14100a280 (??_G 0x141014af0)
    virtual CString vfunc_1();                                              //  1 0x14100a420 "PlayInstrumentDialog"
    virtual void OnLoadComplete();                                          // 22 0x14100a470
    virtual void vfunc_26();                                                // 26 0x14100ac50
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14100b8d0
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);       // 45 0x14100afc0
    virtual int vfunc_48();                                                 // 48 0x141014b30: 0x4eec
    virtual int vfunc_53(void* pCfg);                                       // 53 0x14100af20
    virtual int vfunc_54(void* pCfg);                                       // 54 0x14100aec0
    virtual void vfunc_67();                                                // 67 0x14100ad90
    virtual int vfunc_71();                                                 // 71 0x14100b0f0
    virtual void vfunc_72();                                                // 72 0x14100b1e0
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);               // IMessageListener 0 0x14100b7c0

    void FUN_14100c1e0();                                                   // 0x14100c1e0 UIDialog::vfunc_67
    void FUN_14100c200(int nPage);                                          // 0x14100c200 the play page / score page tab
    void FUN_14100c2c0();                                                   // 0x14100c2c0 the mastery bar
    int FUN_14100c750();                                                    // 0x14100c750 start the first score
    int FUN_14100c890();                                                    // 0x14100c890 the selected tab
    bool FUN_14100c8f0();                                                   // 0x14100c8f0 the score page is shown
    void FUN_14100c910(MS2Ptr<CItem> spItem);                               // 0x14100c910 put a score into a free slot
    void FUN_14100ca90(int nIndex, MS2Ptr<CItem> spItem);                   // 0x14100ca90 set one score slot
    void FUN_14100d260(int nStart, int nEnd);                               // 0x14100d260 a score starts to play
    void FUN_14100d600();                                                   // 0x14100d600 a score ended
    bool FUN_14100d8c0();                                                   // 0x14100d8c0 any score chosen
    void FUN_14100d920();                                                   // 0x14100d920 auto start
    int FUN_14100d9f0();                                                    // 0x14100d9f0 m_nAutoPlay
    void FUN_14100da10();                                                   // 0x14100da10 the play timer text
    void FUN_14100e060();                                                   // 0x14100e060 bind the key buttons
    void FUN_14100e880(int nKey, MS2Ptr<Unk_140acd6e0> spButton, int nIndex);   // 0x14100e880
    void FUN_14100e910();                                                   // 0x14100e910 apply the octave
    void FUN_14100e9a0(int nMode);                                          // 0x14100e9a0 the play / stop buttons
    int FUN_140d13c50();                                                    // inline: m_nMode (instrumentmanager.cpp)
    void FUN_140d13d80(int nInstrument);                                    // inline: set m_nInstrument (instrumentmanager.cpp)
    void FUN_14100f1f0();                                                   // 0x14100f1f0 the slot count
    unsigned char FUN_14100f2e0();                                          // 0x14100f2e0 play the chosen score

    MS2Ptr<ASMovieClip> FUN_140c02990(const CString& strName);              // 0x140c02990 bind a movie clip child
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);              // 0x140bb4cf0 bind a text field child

private:
    MS2_LAYOUT_FRIEND;
    int m_nMode;                                                            // +0x178 1 stop, 2 playing ready, 3 playing
    int m_nTab;                                                             // +0x17c
    int m_nOctave;                                                          // +0x180
    MS2Ptr<CItem> m_spItem;                                                 // +0x188
    int m_nInstrument;                                                      // +0x198
    MS2Ptr<CItem> m_spScores[3];                                            // +0x1a0
    int m_nCurrent;                                                         // +0x1d0
    bool m_bStop;                                                           // +0x1d4
    int m_nSlotCount;                                                       // +0x1d8
    unsigned m_nIdleTick;                                                   // +0x1dc
    unsigned m_nStartTick;                                                  // +0x1e0
    unsigned m_nEndTick;                                                    // +0x1e4
    int m_nKind;                                                            // +0x1e8 0 solo, 1 ensemble
    int m_nAutoPlay;                                                        // +0x1ec
    MS2Ptr<ASMovieClip> m_spPlayPage;                                       // +0x1f0 "m_playDirectPage"
    MS2Ptr<ASMovieClip> m_spScorePage;                                      // +0x200 "m_playScorePage"
    MS2Ptr<Unk_140acd6e0> m_spLowerOctave;                                  // +0x210 "m_lowerOctave"
    MS2Ptr<Unk_140acd6e0> m_spUpperOctave;                                  // +0x220 "m_upperOctave"
    MS2Ptr<ASTextField> m_spFold;                                           // +0x230 "m_foldText"
    MS2Ptr<Unk_PiTabBar> m_spTab;                                           // +0x240 "m_tab"
    std::vector<std::pair<int, int> > m_octaveKeys;                         // +0x250 (key, octave code)
    KeyButtonMap m_keyButtons;                                              // +0x268
    PressedMap m_pressed;                                                   // +0x278
};
MS2_CHECK_SIZE(UIPlayInstrumentDialog, 0x288);
MS2_CHECK_OFFSET(UIPlayInstrumentDialog, m_spItem, 0x188);
MS2_CHECK_OFFSET(UIPlayInstrumentDialog, m_spScores, 0x1a0);
MS2_CHECK_OFFSET(UIPlayInstrumentDialog, m_spPlayPage, 0x1f0);
MS2_CHECK_OFFSET(UIPlayInstrumentDialog, m_spTab, 0x240);
MS2_CHECK_OFFSET(UIPlayInstrumentDialog, m_octaveKeys, 0x250);
MS2_CHECK_OFFSET(UIPlayInstrumentDialog, m_keyButtons, 0x268);
MS2_CHECK_OFFSET(UIPlayInstrumentDialog, m_pressed, 0x278);
