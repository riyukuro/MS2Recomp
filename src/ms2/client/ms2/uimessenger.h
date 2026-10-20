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
#include <map>
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
class UIMessengerBrowser;

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
    virtual int vfunc_86(void* pTab, const CStringW& strName);              // 86 0x141a0f040 the tab name is free
    virtual void vfunc_87();                                                // 87 0x141a15ae0
    virtual int vfunc_88(const CStringW& strText, int nType);               // 88 0x141a15dc0 adds a chat line
    virtual void vfunc_89(const CStringW& strText, int nChannel);           // 89 0x141a15d70 adds a line of a channel
    virtual void vfunc_90();                                                // 90 0x141a15e80 focus in: the current window
    virtual void vfunc_91();                                                // 91 0x141a15ef0 focus out
    virtual void vfunc_92();                                                // 92 0x141a15f60 a new tab
    virtual void vfunc_93();                                                // 93 0x141a16030
    virtual void vfunc_94();                                                // 94 0x141a162a0 the input text changed
    virtual void vfunc_95(const CStringW& strTarget);                       // 95 0x141a162e0 the whisper target
    virtual void vfunc_96(int nMenu);                                       // 96 0x141a16310 the tab menu
    virtual void vfunc_97(const CStringW& strName);                         // 97 0x141a16400 select a tab
    virtual void vfunc_98(const CStringW& strName, void* pArg);             // 98 0x141a165c0 attach a tab

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
    int FUN_141a0e2a0(const CStringW& strName);                             // 0x141a0e2a0 selects a tab
    int FUN_141a0e350(const CStringW& strName);                             // 0x141a0e350 removes a tab
    int FUN_141a0e4d0(MessengerData::TalkTab* pTab);                        // 0x141a0e4d0 adds a tab
    int FUN_141a0e810(const CStringW& strName, int nClose, int nDetach, int nAdditive);   // 0x141a0e810 creates a tab
    void FUN_141a0e990();                                                   // 0x141a0e990 selects the default tab
    void FUN_141a0ead0(int nFontSize, CStringW& strHtml);                   // 0x141a0ead0 sets the html font size
    void FUN_141a0f180();                                                   // 0x141a0f180 reads the alignment
    void FUN_141a0f550(NotifyObject* pNotify);                              // 0x141a0f550 NotifyGameEventChanged
    void FUN_141a0f5d0(NotifyObject* pNotify);                              // 0x141a0f5d0 NotifyChatEmoticonSelected
    void FUN_141a0e940(const Scaleform::GFx::FunctionHandler::Params& params);   // the input text changed
    void FUN_141a0f520(const Scaleform::GFx::FunctionHandler::Params& params);   // the dialog was moved
    int FUN_141a12260();                                                    // 0x141a12260 escape: leaves the input
    int FUN_141a12f30();                                                    // 0x141a12f30 has the key focus
    void FUN_141a13ac0();                                                   // 0x141a13ac0 refreshes the tab bar
    void FUN_141a13c20(int bUp);                                            // 0x141a13c20 input history
    void FUN_141a13d20(CStringW* pName);                                    // 0x141a13d20 a free tab name
    int FUN_141a14110();                                                    // 0x141a14110 the default chat type index
    void FUN_141a14600();
    void FUN_141a14760();
    void FUN_141a14dc0();                                                   // 0x141a14dc0 rebuilds the subject list
    void FUN_141a15970();                                                   // 0x141a15970 orders the tabs as the bar
    void FUN_141a17700();
    void FUN_141a17830(const CStringW& strText, int bSelectEnd);            // 0x141a17830 sets the input text
    void FUN_141a17900(const CStringW& strTarget);                          // 0x141a17900 begins a whisper

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
    // +0x1b8 .. +0x310: unrecovered (the browser's containers, recovered with its half of the unit)
    void* m_unrecovered[(0x310 - 0x1b8) / 8];
};
MS2_CHECK_SIZE(UIMessengerBrowser, 0x310);
