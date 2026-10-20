// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uimessenger.h (name assumed: the
// class name; the exe's assert path is e:\build\kr\22_04\ms2code\client\ms2\uimessenger.cpp).
//
// UIMessenger ("MessengerDialog", RTTI .?AVUIMessenger@@, 0x308 bytes, vftable 0x142fc6180, 99 slots): one chat window
// of the messenger. It owns the chat input (m_textInput), the chat lines (m_textOutput), the tab bar (m_buttonBar), the
// subject (chat channel) drop-down and the emoticon preview, plus the tabs (MessengerData::TalkTab) shown in the bar.
// Every window's settings are saved to <name>.xml in the UI settings directory; the debug chat commands are read from
// DebugChatCommand.xml.
// UIMessengerBrowser ("MessengerBrowser", 0x310 bytes = UIDialog + UIItemEventListener at +0x178): the owner of every
// messenger window and of the chat log.
// TDebugCommand (RTTI .?AUTDebugCommand@@, 0x38 bytes): one <cmd> of DebugChatCommand.xml.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members, member names invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/messengerdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/uiitemeventlistener.h"

class ASTextInput;
class ASTextArea;
class ASButtonBar;
class ASDropdownMenu;
class ASMovieClip;
class ASUIComponent;
class NotifyObject;
class CMsgBoxData;
class CItem;
class UIMessengerBrowser;
class ChatEmoticonData;

// An input history entry of the browser (0x28): the line and the keys of its item links.
struct Unk_MsgHistory
{
    CStringW m_strText;                                                     // +0x00
    ATL::CAtlArray<CStringW> m_keys;                                        // +0x08
};

// One debug chat command (DebugChatCommand.xml <ms2><CommandSet><cmd .../>): the help shown by the chat input.
struct TDebugCommand : public CPtred
{
    TDebugCommand() {}                                              // 0x141a1b730
    virtual ~TDebugCommand() = default;                             //  0 0x141a1bb40
    CStringW m_strDesc;                                             // +0x18 "desc"
    CStringW m_strArg;                                              // +0x20 "arg"
    CStringW m_strName;                                             // +0x28 "cmd"
    CStringW m_strEx;                                               // +0x30 "ex"
};
MS2_CHECK_SIZE(TDebugCommand, 0x38);

class UIMessenger : public UIDialog
{
public:
    UIMessenger(UIMessengerBrowser* pBrowser, const TiXmlDocument& doc, CStringW strName, int bFirst);   // 0x141a08af0
    virtual ~UIMessenger();                                                 //  0 0x141a08d60 (??_G 0x141a1c6d0)
    virtual CString vfunc_1();                                              //  1 0x141a08eb0 "MessengerDialog"
    virtual int vfunc_4();                                                  //  4 0x141a09320 save the window settings
    virtual int vfunc_5();                                                  //  5 0x141a095d0 load the window settings
    virtual int vfunc_13();                                                 // 13 0x141a0a4a0 key input
    virtual void vfunc_15();                                                // 15 0x141a0a810 scroll the lines to the end
    virtual void OnLoadComplete();                                          // 22 0x141a09e90
    virtual void vfunc_26();                                                // 26 0x141a0a3a0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x141a0bfd0
    virtual void vfunc_43();                                                // 43 0x141a0a3f0 alignment
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
                                                                            // 45 0x141a0a900
    virtual int vfunc_46();                                                 // 46 0x141a0c9f0
    virtual int vfunc_48();                                                 // 48 0x141a1caf0 UI type id
    virtual int vfunc_53(void* pCfg);                                       // 53 0x141a098b0 save
    virtual int vfunc_54(void* pCfg);                                       // 54 0x141a09af0 load
    virtual int vfunc_65();                                                 // 65 0x141a08f00 Open
    virtual void vfunc_67();                                                // 67 0x141a090d0 Close
    virtual int vfunc_74(int a1, void* p2, void* p3);                       // 74 0x141a0cab0 window message
    virtual int vfunc_84();                                                 // 84 0x141a09db0 deletes the settings file
    virtual void vfunc_85(int bActive);                                     // 85 0x141a0efa0
    virtual int vfunc_86(MessengerData::TalkTab* pExcept, const CStringW& strName);              // 86 0x141a0f040 the tab name is free
    virtual void vfunc_87();                                                // 87 0x141a15ae0
    virtual int vfunc_88(const CStringW& strText, int nType);               // 88 0x141a15dc0 adds a chat line
    virtual void vfunc_89(const CStringW& strText, int nChannel);           // 89 0x141a15d70 adds a line of a channel
    virtual void vfunc_90();                                                // 90 0x141a15e80 focus in: the current window
    virtual void vfunc_91();                                                // 91 0x141a15ef0 focus out
    virtual void vfunc_92();                                                // 92 0x141a15f60 a new tab
    virtual void vfunc_93();                                                // 93 0x141a16030
    virtual void vfunc_94(const CStringW& strText);                         // 94 0x141a162a0 the input text changed
    virtual void vfunc_95(const CStringW& strTarget);                       // 95 0x141a162e0 the whisper target
    virtual void vfunc_96(int nMenu);                                       // 96 0x141a16310 the tab menu
    virtual void vfunc_97(const CStringW& strName);                         // 97 0x141a16400 select a tab
    virtual void vfunc_98(const CStringW& strName, const CString& strWindow);   // 98 0x141a165c0 moves a tab to a window

    // ---- child lookups (UISwfEntity::GetChild<T> COMDATs, ICF'd with other classes' copies) ----
    MS2Ptr<ASTextInput> FUN_140e35bd0(const CString& strName);             // 0x140e35bd0
    MS2Ptr<ASTextArea> FUN_140c26f60(const CString& strName);              // 0x140c26f60
    MS2Ptr<ASButtonBar> FUN_140c02870(const CString& strName);             // 0x140c02870
    MS2Ptr<ASDropdownMenu> FUN_140c28560(const CString& strName);          // 0x140c28560
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);             // 0x140ba7930

    // ---- non-virtual members (exe order) ----
    void FUN_141a0d880(bool bVisible);                                      // 0x141a0d880 shows the two extra components
    static bool FUN_141a0d930();                                            // 0x141a0d930 loads DebugChatCommand.xml
    static int FUN_141a0df10();                                             // 0x141a0df10 reloads it when it changed
    CStringW FUN_141a0df70();                                               // 0x141a0df70 the window name
    CStringW FUN_141a0dfc0();                                               // 0x141a0dfc0 the default tab name
    MessengerData::TalkTab* FUN_141a0e050();                                // 0x141a0e050 the selected tab
    MessengerData::TalkTab* FUN_141a0e0f0(const CStringW& strName);         // 0x141a0e0f0 a tab by name
    int FUN_141a0e1f0(int nIndex);                                          // 0x141a0e1f0 selects a tab by index
    int FUN_141a0e2a0(const CStringW& strName);                             // 0x141a0e2a0 selects a tab
    int FUN_141a0e350(const CStringW& strName);                             // 0x141a0e350 removes a tab
    int FUN_141a0e4d0(MessengerData::TalkTab* pTab);                        // 0x141a0e4d0 adds a tab
    int FUN_141a0e650(MessengerData::TalkTab* pTab);                        // 0x141a0e650 inserts a tab (refreshes the bar)
    int FUN_141a0e810(const CStringW& strName, int nClose, int nDetach, int nAdditive);   // 0x141a0e810 creates a tab
    size_t FUN_141a0e900(ATL::CAtlArray<MS2Ptr<MessengerData::TalkTab> >& tabs);   // 0x141a0e900 copies the tabs
    void FUN_141a0e990();                                                   // 0x141a0e990 selects the default tab
    void FUN_141a0e9f0(const CStringW& strOld, const CStringW& strNew);     // 0x141a0e9f0 renames a tab
    void FUN_141a0ead0(unsigned nFontSize, CStringW& strHtml);              // 0x141a0ead0 sets the html font size
    void FUN_141a0ebb0(unsigned nAlpha);                                       // 0x141a0ebb0 the background alpha
    void FUN_141a0ec30(const CStringW& strText);                            // 0x141a0ec30 appends to the input
    void FUN_141a0f180();                                                   // 0x141a0f180 reads the alignment
    void FUN_141a0f1d0(CStringW strText, CStringW strHtml, bool bHistory);  // 0x141a0f1d0 submits a line
    void FUN_141a0f430(CStringW strText, bool bHistory);                    // 0x141a0f430 submits a command
    void FUN_141a0f550(NotifyObject* pNotify);                              // 0x141a0f550 NotifyGameEventChanged
    void FUN_141a0f5d0(NotifyObject* pNotify);                              // 0x141a0f5d0 NotifyChatEmoticonSelected
    void FUN_141a0f7b0();                                                   // 0x141a0f7b0 the default subject
    void FUN_141a0f870();                                                   // 0x141a0f870 restores the subject
    bool FUN_141a0f900(int nButton, const CMsgBoxData& box);                // 0x141a0f900 report confirm
    bool FUN_141a0f980(int nButton, const CMsgBoxData& box);                // 0x141a0f980 block confirm
    bool FUN_141a0f9d0(int nButton, const CMsgBoxData& box);                // 0x141a0f9d0 super chat confirm
    bool FUN_141a0fb40(int nButton, const CMsgBoxData& box);                // 0x141a0fb40 world chat confirm
    bool FUN_141a0fcb0(int nButton, const CMsgBoxData& box);                // 0x141a0fcb0 channel chat confirm
    int FUN_141a0fe20(int nEmoticonId);                                     // 0x141a0fe20 sends an emoticon
    void FUN_141a10010(int nType, int nEmoticonId);                         // 0x141a10010 types an emoticon
    int FUN_141a10490(int nEmoticonId, bool bFavorite);                     // 0x141a10490 the emoticon favorite
    void FUN_141a10660(int nType, CStringW strText, CStringW strTarget, int nItem);   // 0x141a10660 sends a chat line
    int FUN_141a10fd0(CStringW strText, CStringW strHtml, bool bLinks);     // 0x141a10fd0 runs a command
    void FUN_141a11be0(int nType, const CStringW& strText);                 // 0x141a11be0 sends a chat line to the server
    bool FUN_141a11c60(const CStringW& strCommand, CStringW strText, int* pType);   // 0x141a11c60 a chat command
    void FUN_141a11e30();                                                   // 0x141a11e30 enter: submits or focuses the input
    void FUN_141a0e940(const Scaleform::GFx::FunctionHandler::Params& params);   // the input text changed
    void FUN_141a0f520(const Scaleform::GFx::FunctionHandler::Params& params);   // the dialog was moved
    int FUN_141a12260();                                                    // 0x141a12260 escape: leaves the input
    bool FUN_141a12380(int nType, CStringW strText);                        // 0x141a12380 the chat actions
    void FUN_141a12e40(int nType, CStringW strText, bool bHistory);         // 0x141a12e40 sends a chat line
    int FUN_141a12f30();                                                    // 0x141a12f30 has the key focus
    bool FUN_141a13030(CStringW& strText);                                  // 0x141a13030 blank
    bool FUN_141a13070(const CStringW& strName);                            // 0x141a13070 a tab exists
    int FUN_141a13160(MessengerData::TalkTab* pTab, int nChannel);          // 0x141a13160 the tab hides a channel
    int FUN_141a131a0(MessengerData::TalkTab* pTab, int nType);             // 0x141a131a0 the tab hides a line type
    void FUN_141a13210();                                                   // 0x141a13210 the emoticon aliases
    void FUN_141a13510(std::list<MS2Ptr<ChatEmoticonData> >& emoticons);    // 0x141a13510 the emoticon preview
    void FUN_141a13940();                                                   // 0x141a13940 closes the preview
    void FUN_141a139c0(const CStringW& strText, int bClear);                // 0x141a139c0 writes the output lines
    void FUN_141a13ac0();                                                   // 0x141a13ac0 refreshes the tab bar
    void FUN_141a13c20(int bUp);                                            // 0x141a13c20 input history
    CStringW FUN_141a13d20();                                               // 0x141a13d20 a free tab name
    void FUN_141a13e00();                                                   // 0x141a13e00 the subject list's chat types
    int FUN_141a14110();                                                    // 0x141a14110 the default chat type index
    int FUN_141a141c0(int nType);                                           // 0x141a141c0 the subject index of a chat type
    int FUN_141a14250();                                                    // 0x141a14250 the chat type of the input
    int FUN_141a144a0();                                                    // 0x141a144a0 the selected chat type
    int FUN_141a14500();                                                    // 0x141a14500 the default subject
    int FUN_141a14580(int nIndex);                                          // 0x141a14580 the chat type of a subject index
    void FUN_141a14600();
    void FUN_141a146d0(int nType);                                          // 0x141a146d0 selects a subject
    void FUN_141a14760();
    int FUN_141a148b0(const CStringW& strText);                             // 0x141a148b0 an emotion command
    void FUN_141a14bb0(const CStringW& strTarget);                          // 0x141a14bb0 whispers anyone but oneself
    bool FUN_141a14c40(CStringW& strText, CStringW strPart);                // 0x141a14c40 cuts a part out
    bool FUN_141a14ce0(CStringW strText, int nMax);                         // 0x141a14ce0 fits without the markup
    void FUN_141a14dc0();                                                   // 0x141a14dc0 rebuilds the subject list
    void FUN_141a15890();                                                   // 0x141a15890 the super world chat effect
    void FUN_141a15970();                                                   // 0x141a15970 orders the tabs as the bar
    void FUN_141a131f0();                                                   // 0x141a131f0 shows the whisper list (empty)
    void FUN_141a13200();                                                   // 0x141a13200 hides the whisper list (empty)
    void FUN_141a16730(const CStringW& strName, int nX, int nY, int nWidth, int nHeight, int nTarget);
                                                                            // 0x141a16730 detaches a tab to a new window
    void FUN_141a168a0(const ATL::CAtlArray<CStringW>& args);               // 0x141a168a0 a party link of a chat line
    void FUN_141a16bb0(int nProductId);                                     // 0x141a16bb0 opens the user bill
    void FUN_141a16c50(int nRoomId);                                        // 0x141a16c50 opens a dungeon room
    void FUN_141a16cc0(int nPartyId, CStringW strLeader, int nRoomId);      // 0x141a16cc0 joins as a dungeon helper
    void FUN_141a172a0(int nPartyId, CStringW strLeader, int nRoomId);      // 0x141a172a0 joins as a dungeon member
    void FUN_141a17690(CStringW strName);                                   // 0x141a17690 invites to the party
    void FUN_141a17700();                                                   // 0x141a17700 Enter: an emoticon or the chat
    void FUN_141a17830(const CStringW& strText, int bSelectEnd);            // 0x141a17830 sets the input text
    void FUN_141a17900(const CStringW& strTarget);                          // 0x141a17900 begins a whisper
    void FUN_141a17a60(const CStringW& strTarget);                          // 0x141a17a60 begins a talk
    bool FUN_141a17bc0(int nButton, const CMsgBoxData& box);                // 0x141a17bc0 the dungeon helper prompt
    bool FUN_141a17c90(int nButton, const CMsgBoxData& box);                // 0x141a17c90 the dungeon member prompt

    MS2_LAYOUT_FRIEND;
    int m_178;                                                              // +0x178
    int m_bFirst;                                                           // +0x17c the first window: default tab/target
    int m_bScrollEnd;                                                       // +0x180 scroll the lines to the end (vfunc_15)
    float m_fOffsetX;                                                       // +0x184
    float m_fOffsetY;                                                       // +0x188
    int m_nAlignType;                                                       // +0x18c
    MS2Ptr<ASTextInput> m_textInput;                                        // +0x190 "m_textInput"
    MS2Ptr<ASTextArea> m_textOutput;                                        // +0x1a0 "m_textOutput"
    MS2Ptr<ASButtonBar> m_buttonBar;                                        // +0x1b0 "m_buttonBar"
    MS2Ptr<ASDropdownMenu> m_subject;                                       // +0x1c0 "m_subject"
    MS2Ptr<ASMovieClip> m_chatEmoticonPreview;                              // +0x1d0 "m_chatEmoticonPreview"
    int m_nTabSelectedIndex;                                                // +0x1e0 "tabSelectedIndex"
    int m_nTargetSelectedIndex;                                             // +0x1e4 "targetSelectedIndex"
    int m_nHistoryIndex;                                                    // +0x1e8 (-1)
    CStringW m_strName;                                                     // +0x1f0 the window name (settings file)
    ATL::CAtlArray<CStringW> m_inputHistory;                                // +0x1f8
    ATL::CAtlArray<MS2Ptr<MessengerData::TalkTab> > m_tabs;                 // +0x218
    int m_238;                                                              // +0x238
    TiXmlDocument m_doc;                                                    // +0x240 the settings handed by the browser
    UIMessengerBrowser* m_pBrowser;                                         // +0x2b0
    std::vector<int> m_subjects;                                            // +0x2b8 the subject list's chat types
    std::map<int, int> m_subjectIndex;                                      // +0x2d0 chat type -> subject index
    MS2Ptr<ASUIComponent> m_2e0;                                            // +0x2e0
    MS2Ptr<ASUIComponent> m_2f0;                                            // +0x2f0
    CStringW m_strLastWhisper;                                              // +0x300
};
MS2_CHECK_SIZE(UIMessenger, 0x308);

class UIMessengerBrowser : public UIDialog, public UIItemEventListener
{
public:
    UIMessengerBrowser();                                                   // 0x141a20f90
    virtual ~UIMessengerBrowser();                                          //  0 0x141a215a0

    // ---- non-virtual members (exe order) ----
    void FUN_141a24160(const ATL::CAtlArray<MS2Ptr<MessengerData::TalkTab> >& tabs, int nX, int nY, int nWidth,
                       int nHeight, int nTarget);                           // 0x141a24160 a new window with the tabs
    void FUN_141a245d0(const CStringW& strName);                            // 0x141a245d0 closes an empty window
    void FUN_141a25f70(const CStringW& strText, ATL::CAtlArray<CStringW>& history);   // 0x141a25f70 records a command
    int FUN_141a25410(int nKind, const CStringW& strName);                  // 0x141a25410 the window name is free
    int FUN_141a261b0(int bUp, Unk_MsgHistory& entry);                      // 0x141a261b0 the input history
    bool FUN_141a26480();                                                   // 0x141a26480
    bool FUN_141a264c0(int nType);                                          // 0x141a264c0 the chat type is hidden

    MS2_LAYOUT_FRIEND;
    int m_180;                                                              // +0x180 (1) the windows take key input
    int m_184;                                                              // +0x184 (1)
    int m_188;                                                              // +0x188 (1)
    int m_18c;                                                              // +0x18c (500)
    int m_190;                                                              // +0x190 (600)
    int m_194;                                                              // +0x194 (0)
    int m_198;                                                              // +0x198 (10)
    CStringW m_strWhisperTarget;                                            // +0x1a0 the last whisper target
    CStringW m_1a8;                                                         // +0x1a8
    int m_1b0;                                                              // +0x1b0
    ATL::CAtlArray<UIMessenger*> m_windows;                                 // +0x1b8 every messenger window
    ATL::CAtlList<MessengerData::TalkLog> m_logs;                           // +0x1d8 the chat lines (at most m_18c)
    ATL::CAtlList<MessengerData::TalkLog> m_pendingLogs;                    // +0x208 lines not shown yet
    ATL::CAtlList<MessengerData::ReportLog> m_reports;                      // +0x238
    ATL::CAtlMap<unsigned __int64, MS2Ptr<CItem>> m_linkedItems;            // +0x268 the items linked in chat, by uid
    std::deque<Unk_MsgHistory> m_history;                                   // +0x2b0 the input history (at most 10)
    std::deque<Unk_MsgHistory>::iterator m_itHistory;                       // +0x2d8 the history browse position
    std::map<__int64, CStringW> m_timedLogs;                                // +0x2f0 lines by time
    std::set<int> m_hiddenTypes;                                            // +0x300 the chat types hidden
};
MS2_CHECK_SIZE(UIMessengerBrowser, 0x310);
