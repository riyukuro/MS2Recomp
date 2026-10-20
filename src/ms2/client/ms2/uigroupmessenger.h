// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uigroupmessenger.h (name assumed: the
// class name; the exe's assert path is e:\build\kr\22_04\ms2code\client\ms2\uigroupmessenger.cpp).
//
// UIGroupMessenger ("GroupMessenger", RTTI .?AVUIGroupMessenger@@, 0x218 bytes = UIDialog + UIUGCEventListener at
// +0x178): one group chat window. It shows the chat's lines (m_textOutput), the member list (m_userList), the typing
// state of other members (the UGC listener reports "typing" profile updates) and the emoticon preview; the window's
// position / alpha / name are saved to GroupMessenger<index>.xml.
// UIGroupMessengerBrowser ("GroupMessengerBrowser", 0x290 bytes): the tray that owns every chat window, keeps each
// chat's talk log (TalkLogList) and the item links shown in the chats.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members, member names invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <deque>
#include <list>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/messengerdata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiugceventlistener.h"

class CItem;
class CInPacket;
class NotifyObject;
class ChatEmoticonData;
class UIGroupMessengerBrowser;

namespace GroupMessengerData {

// One chat's log (0x60 bytes; ctor 0x141954f60, dtor 0x141955170): the lines shown in the window and the plain text
// history handed to the member popup menu (newest last).
class TalkLogList : public CPtred
{
public:
    virtual ~TalkLogList() = default;                               //  0 0x141955170 (??_G 0x1419556d0)
    ATL::CAtlArray<TalkLog> m_logs;                                 // +0x18
    std::deque<CStringW> m_lines;                                   // +0x38
};
MS2_CHECK_SIZE(TalkLogList, 0x60);

}   // namespace GroupMessengerData

class UIGroupMessenger : public UIDialog, public UIUGCEventListener
{
public:
    UIGroupMessenger(int nGroupId, int nIndex, int bDeleteSave);           // 0x141947920
    virtual ~UIGroupMessenger();                                            //  0 0x141947bc0 (??_G 0x14194e7d0)
    virtual CString vfunc_1();                                              //  1 0x141947c60 "GroupMessenger"
    virtual int vfunc_4();                                                  //  4 0x1419482c0 save the window settings
    virtual int vfunc_5();                                                  //  5 0x141948520 load the window settings
    virtual int vfunc_13();                                                 // 13 0x141949020 key input (enter / escape)
    virtual void vfunc_15();                                                // 15 0x1419490b0 typing time-out
    virtual void OnLoadComplete();                                          // 22 0x141948c20
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x141949900
    virtual void vfunc_43();                                                // 43 0x141948f40 alignment
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
                                                                            // 45 0x141949640 item tooltip / preview
    virtual int vfunc_48();                                                 // 48 0x14194f120 UI type id (0x4e94)
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);               // IMessageListener 0 0x141949130
    virtual int vfunc_53(void* pCfg);                                       // 53 0x1419487c0 save
    virtual int vfunc_54(void* pCfg);                                       // 54 0x141948980 load
    virtual void vfunc_63(int n);                                           // 63 0x141947f40 minimize
    virtual int vfunc_65();                                                 // 65 0x141947cb0 Open
    virtual void vfunc_67();                                                // 67 0x141947da0 Close
    virtual void vfunc_69();                                                // 69 0x141947f10 minimize instead of closing
    virtual int vfunc_84(int bDeleteSave);                                  // 84 0x141948b30 deletes the settings file
    virtual void vfunc_85();                                                // 85 0x14194b800 makes this chat the current one
    virtual void vfunc_86();                                                // 86 0x14194b870 empty
    // UIUGCEventListener (+0x178)
    virtual void vfunc_ugc_1(void* pId, CString strText);                   // 1 0x14194b360 a member is typing

    void FUN_14194a320(int nKind, const CStringW& strName, const CStringW& strText);    // empty
    void FUN_14194a340(int nKind, const CStringW& strName, const CStringW& strOther);   // invited
    void FUN_14194a3c0(int nKind, const CStringW& strName, int nMode);      // joined / refused
    void FUN_14194a4d0(int nKind, const CStringW& strName);                 // left
    void FUN_14194a540(int nKind, const CStringW& strName);                 // kicked
    void FUN_14194a5b0(int nKind, const CStringW& strName, const CStringW& strMsg);     // a member's line
    void FUN_14194a650(int nKind, const CStringW& strName, const CStringW& strMsg);     // a notice line
    void FUN_14194a6f0(NotifyObject* pNotify);                              // NotifyChatEmoticonSelected
    void FUN_14194a930(std::list<MS2Ptr<ChatEmoticonData> >& emoticons);    // opens the emoticon preview
    void FUN_14194ad60();                                                   // closes the emoticon preview
    int FUN_14194ade0(int nEmoticonId);                                     // sends an emoticon
    void FUN_14194afc0(int nEmoticonId);                                    // sends an emoticon as an image line
    int FUN_14194b190(int nEmoticonId, bool bFavorite);                     // (un)marks a favorite emoticon
    void FUN_14194b440(const CStringW& strName, float x, float y);          // the member popup menu
    int FUN_14194b880();                                                    // the member list is shown
    CString FUN_14194b8a0();                                                // the settings file name
    CStringW FUN_14194b960();                                               // the chat name
    unsigned FUN_14194b9b0();                                               // the group id
    int FUN_14194b9d0(__int64 nCharacterId);                                // is a member
    CStringW FUN_14194ba80(unsigned __int64 nCharacterId);                  // a member's name
    void FUN_14194bc70(CStringW strName);                                   // renames the chat
    void FUN_14194bcc0(CStringW strText);                                   // appends to the input
    void FUN_14194bde0();                                                   // refreshes the window
    void FUN_14194c060();                                                   // refreshes the member list
    int FUN_14194c6d0();                                                    // has the key focus
    int FUN_14194c830();                                                    // sends the input
    int FUN_14194cbb0();                                                    // enter: focus the input or send
    int FUN_14194cd00();                                                    // escape: leave the input
    int FUN_14194ce40(CStringW strName);                                    // the new name is refused
    void FUN_14194d100(MS2Ptr<class Unk_GrmInput> spInput, const CStringW& strText, int bSelectEnd);
    void FUN_14194d3d0(int nKind, const CStringW& strName, const CStringW& strMsg, int bSystem);   // adds a line
    void FUN_14194d6f0();                                                   // shows the typing members
    static CStringW FUN_14194d8f0(const CStringW& strName, int bSystem);    // the line frame name (static in the exe: rcx = sret)
    static bool FUN_14194da30(CStringW strMsg);                                  // the line shows a background

    MS2Ptr<class Unk_GrmList> FUN_140c02900(const CString& strName);       // 0x140c02900 list / text output
    MS2Ptr<class Unk_GrmInput> FUN_140e35bd0(const CString& strName);      // 0x140e35bd0 text input

private:
    MS2_LAYOUT_FRIEND;
    float m_fOffsetX;                                                       // +0x180
    float m_fOffsetY;                                                       // +0x184
    int m_nAlignType;                                                       // +0x188
    int m_nScrollPosition;                                                  // +0x18c
    CStringW m_strName;                                                     // +0x190
    int m_nAlpha;                                                           // +0x198
    int m_nIndex;                                                           // +0x19c
    int m_bUserList;                                                        // +0x1a0
    unsigned m_nTypingTime;                                                 // +0x1a4
    ATL::CAtlMap<unsigned __int64, CString> m_typing;                       // +0x1a8 typing member id -> profile
    ATL::CAtlArray<CStringW> m_inputHistory;                                // +0x1f0
    unsigned m_nGroupId;                                                    // +0x210
};
MS2_CHECK_SIZE(UIGroupMessenger, 0x218);

class UIGroupMessengerBrowser : public UIDialog
{
public:
    UIGroupMessengerBrowser();                                              // 0x141950770
    virtual ~UIGroupMessengerBrowser();                                     //  0 0x141950910 (??_G 0x141955710)
    virtual CString vfunc_1();                                              //  1 0x1419509c0 "GroupMessengerBrowser"
    virtual void vfunc_15();                                                // 15 0x141951470 flushes the pending lines
    virtual void OnLoadInit();                                              // 20 0x141950d20
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x141951180
    virtual void vfunc_43();                                                // 43 0x141950d60 alignment
    virtual int vfunc_48();                                                 // 48 0x141956220 UI type id
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);               // IMessageListener 0 0x141950e70
    virtual int vfunc_53(void* pCfg);                                       // 53 0x141950b70 save
    virtual int vfunc_54(void* pCfg);                                       // 54 0x141950c60 load
    virtual void vfunc_67();                                                // 67 0x141950a10 Close: closes every window
    virtual void vfunc_80(void* pPacket);                                   // 80 0x1419512f0 the rename check result

    void FUN_1419515c0(int nGroupId);                                       // a chat was created
    void FUN_141951720(int nGroupId, const CStringW& strName, const CStringW& strText);
    void FUN_1419517b0(int nGroupId, const CStringW& strName, const CStringW& strOther);   // invited to a chat
    void FUN_1419519a0(int nGroupId);                                       // a chat was left
    void FUN_1419519e0(int nGroupId, const CStringW& strName, const CStringW& strOther);   // a member was invited
    void FUN_141951a70(int nGroupId, const CStringW& strName, int nMode);   // a member joined / refused
    void FUN_141951af0(int nGroupId, const CStringW& strName);              // a member left
    void FUN_141951b70(int nGroupId, const CStringW& strName);              // a member was kicked
    void FUN_141951bf0(int nGroupId, const CStringW& strName, const CStringW& strMsg);    // a notice line
    void FUN_141951c50(int nGroupId, const CStringW& strName, const CStringW& strMsg);    // queues a member's line
    void FUN_141951d80(int nGroupId, const CStringW& strName, CInPacket* pPacket);       // the item links of a line
    void FUN_141951f70(CStringW strText);                                   // shares a text with a chat
    void FUN_1419524e0();                                                   // forgets everything
    void FUN_141952530();                                                   // refreshes the tray
    int FUN_141952780();                                                    // minimizes every window
    int FUN_141952840();                                                    // a window is shown
    unsigned FUN_141952900();                                               // the first free window slot
    void FUN_141952960(unsigned nGroupId);                                  // marks a chat read
    int FUN_141952a30(unsigned nGroupId);                                   // the read line count
    int FUN_141952b30(unsigned nGroupId);                                   // the unread line count
    int FUN_141952be0();                                                    // opens the windows of the joined chats
    int FUN_141952d80(unsigned nGroupId, int bDeleteSave, int bMinimized);  // opens a chat window
    UIGroupMessenger* FUN_141952f20(int nGroupId);                          // the window of a chat
    UIGroupMessenger* FUN_141952fc0(const CStringW& strName);               // the window of a chat name
    void FUN_141953090(const CStringW& strName);                            // shows a window
    void FUN_141953160(const CStringW& strName);                            // a window was hidden
    void FUN_141953240(const CStringW& strName);                            // toggles a window
    void FUN_1419532d0(int nGroupId);                                       // closes the window of a chat
    void FUN_141953460(const CStringW& strName);                            // a window was closed
    void FUN_141953660(CStringW strText);                                   // appends to the current window's input
    void FUN_141953810(int nGroupId, const CStringW& strName, const CStringW& strMsg, int bSystem, int bMinimized);
    CStringW FUN_141953b10(const CStringW& strMsg);                         // colours the item links
    MS2Ptr<CItem> FUN_141953df0(__int64 nUid);                              // an item link's item

    float m_fOffsetX;                                                       // +0x178
    float m_fOffsetY;                                                       // +0x17c
    int m_nAlignType;                                                       // +0x180
    ATL::CAtlMap<__int64, MS2Ptr<CItem> > m_items;                          // +0x188 item links by uid
    ATL::CAtlMap<unsigned, UIGroupMessenger*> m_windows;                    // +0x1d0
    ATL::CAtlList<GroupMessengerData::TalkLog> m_pending;                   // +0x218
    ATL::CAtlMap<unsigned, MS2Ptr<GroupMessengerData::TalkLogList> > m_logs;   // +0x248
};
MS2_CHECK_SIZE(UIGroupMessengerBrowser, 0x290);
