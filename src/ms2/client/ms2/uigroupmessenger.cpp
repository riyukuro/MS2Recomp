// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGroupMessenger / UIGroupMessengerBrowser: the group chat
// windows and their tray, see uigroupmessenger.h.
// MS2-UNIT: client\ms2\uigroupmessenger.cpp
// MS2-RANGE: 0x141947920-0x141959330 .text$mn
// MS2-RANGE: 0x140113b00-0x140113ff0 .text$di
// MS2-GUESS-LOOKALIKES
//
// Two original TUs: the window (0x141947920-0x141950650) and the tray (0x141950770-), each with its own COMDAT copies
// of the container glue.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigroupmessenger.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uigroupmessenger.h"

#include <stdlib.h>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/chatemoticoncli.h"
#include "ms2/client/ms2/groupchatmanager.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uichatemoticondialog.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/itempreview.h"
#include "ms2/commonfiles/chatemoticontable.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/unk_blocklist.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

using namespace GroupMessengerData;

// ---- statics (.text$di, in init order): the list entry keys, the message box tags, the headers' statics, the sounds ----
static CString s_strCharacterName = "characterName";               // 0x143af29f0
static CString s_strFrame = "frame";                               // 0x143af2a00
static CString s_strIconPath = "iconPath";                         // 0x143af29e8
static CString s_strLevelAndJobName = "levelAndJobName";           // 0x143af29f8
static CString s_strOnline = "online";                             // 0x143af29e0
static CString s_strText = "text";                                 // 0x143af2a08
static CStringW s_strGroupEdit = L"groupEdit";                     // 0x143af2988 the settings box
static CStringW s_strGroupExit = L"groupExit";                     // 0x143af29d8 the leave box
#ifndef MS2_HOOK_DLL
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unkTab(17, 0.75f, 0.25f, 2.25f, 10);
#endif
static CStringW s_strGroupList = L"groupList";                     // 0x143af2a58 the "too many chats" box
#ifndef MS2_HOOK_DLL
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill2 = "skill";
static CString s_strStun2 = "stun";
static Unk_1402a9d70 s_unkTab2(17, 0.75f, 0.25f, 2.25f, 10);
#endif
static CString s_strButtonClick = "button_click";                  // 0x143af2aa8
static CString s_strSystemGroupChat = "system_GroupChat";          // 0x143af2ab0

// ---- unit-local views of exe types ----

// The AS controls of the window. Slot 24 (+0xc0) of the components redraws them.
class Unk_GrmControl : public ASUIComponent
{
public:
#define GRM_V(n) virtual void vfunc_##n();
    GRM_V(16) GRM_V(17) GRM_V(18) GRM_V(19) GRM_V(20) GRM_V(21) GRM_V(22) GRM_V(23)
#undef GRM_V
    virtual void vfunc_24(int n);
};
// "m_textOutput" / "m_userList": the chat lines and the member list.
class Unk_GrmList : public Unk_GrmControl
{
public:
    void FUN_1422dd000(int nRows);                                  // the visible row count
    void FUN_1422dd0d0(int nRows);                                  // the visible row count (chat lines)
    int FUN_1422dd150();                                            // the entry count
    void FUN_1422dd1d0();                                           // clear
    void FUN_1422dd230(const ASObj& item);                          // append an entry
    void FUN_1422e17a0();                                           // scroll to the end
    void FUN_1422e17f0(int nPosition);                              // scroll to a position
};
// "m_textInput": the chat input.
class Unk_GrmInput : public ASTextInput
{
public:
    void FUN_1422e0b80(const CString& strText);                     // set the text (narrow)
    void FUN_1422e0bd0(const CStringW& strHtml);                    // set the html text
    CStringW FUN_1422e0c20();                                       // the html text
    void FUN_1422e0d60(int nMaxChars);                              // limit the length
    int FUN_1422e0da0();                                            // the length limit
    void FUN_1422e1500(int nBegin, int nEnd);                       // select a range
};
// "m_slider0" of the settings box: the window alpha.
class Unk_GrmSlider : public AScript
{
public:
    float FUN_1422ce840();
};
// The settings box's movie (the child lookup of the slider).
class Unk_GrmBoxRoot : public ASObj
{
public:
    template <class T> MS2Ptr<T> FUN_140fafed0(const CString& strName);
};
// The message carries the box's AS root.
class Unk_GrmMsg : public UIMsg
{
public:
    Scaleform::GFx::Value FUN_1422b9260();
};

// The movie root of every dialog is an ASDialog.
class ASDialog : public ASUIComponent
{
};

// The chat UI: the current chat name and the group chat tray (+0x50).
class Unk_GrmChatUI
{
public:
    void FUN_141482c80(CStringW strName);                           // make a chat the current one
    void FUN_141482d30(CStringW strName);                           // drop a chat name
    CStringW FUN_1414829e0();                                       // the current chat name
    char m_pad_00[0x50];
    UIGroupMessengerBrowser* m_pBrowser;                            // +0x50
};
MS2_CHECK_OFFSET(Unk_GrmChatUI, m_pBrowser, 0x50);
Unk_GrmChatUI* FUN_141482e80();

// The own player.
class Unk_GrmWorld { public: PCBase* FUN_141bd0cc0(); };
Unk_GrmWorld* FUN_1403ed2d0();

// The key state.
class Unk_GrmKeys
{
public:
    bool FUN_14116d840();                                           // escape pressed
    bool FUN_14116d9c0(int nKey, int a, int b);
};
Unk_GrmKeys* FUN_14025e7c0();

// The notify manager.
class Unk_GrmNotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb);   // subscribe
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> cb);   // unsubscribe
};
Unk_GrmNotices* FUN_140939a10();

// The UGC event dispatcher (the typing notices).
class Unk_GrmUgcEvents
{
public:
    void FUN_141b38be0(UIUGCEventListener* pListener);
    void FUN_141b38c70(UIUGCEventListener* pListener);
};
Unk_GrmUgcEvents* FUN_140bc09f0();

// The per-user client state: the chat emoticon pack state.
class Unk_GrmUser { public: MS2Ptr<CChatEmoticonCli> FUN_140d9f8f0(); };
Unk_GrmUser* FUN_140931510();
CChatEmoticonTable* FUN_1409eecd0();

// The member popup menu (ui id 0x4e39).
class Unk_PopupMenuInfo
{
public:
    Unk_PopupMenuInfo(float x, float y, int a, int b, int c, CString str, void* p);   // 0x140c302f0
    ~Unk_PopupMenuInfo() {}                                         // 0x140c304c0
private:
    struct Unk_PmA                                                  // ctor 0x140c30440, dtor 0x140c30550
    {
        Unk_PmA() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(0) {}
        void* m_00; void* m_08; CStringW m_10; int m_18; void* m_20;
    };
    struct Unk_PmB                                                  // ctor 0x140c303c0, dtor 0x140c30510
    {
        Unk_PmB() : m_00(0), m_08(0), m_10(L""), m_18(0), m_20(L"") {}
        void* m_00; int m_08; CStringW m_10; void* m_18; CStringW m_20;
    };
    float m_x, m_y;
    int m_a, m_b, m_c;
    CString m_str;
    void* m_p;
    Unk_PmA m_infoA;
    Unk_PmB m_infoB;
};
class Unk_GrmMenu
{
public:
    void FUN_141a7f890(const Unk_PopupMenuInfo& info, CGroupChatMember* pMember, const CStringW& strHistory, int nKind);
};
Unk_GrmMenu* FUN_140c30140(int nUiId);

// The group invite dialog (ui id 0x4e90).
class UIInviteGroupDialog : public UIDialog
{
public:
    void FUN_14199fcf0(unsigned nGroupId);                          // opens it for a chat
};
UIInviteGroupDialog* FUN_14194dd10(int nUiId);

// One member row of the member list (messengerdata.cpp's entry, built from a group chat member).
struct Unk_GrmEntry
{
    Unk_GrmEntry(CGroupChatMember* pMember);                        // 0x141483af0
    unsigned FUN_141483d80();                                       // online
    __int64 FUN_141483da0();                                        // the character id
    CStringW FUN_141483dc0();                                       // the image
    CStringW FUN_141483e10();                                       // the name
    CStringW FUN_141483e60();                                       // the level / job line
    unsigned m_nKind;                                               // +0x00
    __int64 m_nId;                                                  // +0x08
    CStringW m_strImage;                                            // +0x10
    CStringW m_strName;                                             // +0x18
    CStringW m_strInfo;                                             // +0x20
};
MS2_CHECK_SIZE(Unk_GrmEntry, 0x28);

CStringW FUN_14028de60(int nStringId);
CStringW FUN_14052bd00(int nStringId, const CStringW& strA);
CStringW FUN_140632a60(int nStringId, const CStringW& strA, const CStringW& strB);
CStringW FUN_140cde1f0(const wchar_t* szFormat, const unsigned& nId, const int& nVSpace, const CStringW& strSize);
CString FUN_1414842b0(int nKind, CStringW strName);                 // the line's icon
CString FUN_141028be0(__int64 nId, const CString& strName, int bNoDownload, CString strUrl);   // the local file of an image
void FUN_14083d2b0(CStringW& str);                                  // strips the markup
int FUN_140d2aa60(CStringW& strHtml);                               // the input has item links
void FUN_140d2c650(CStringW& strHtml);                              // encodes the item links
void FUN_140d2c2a0(MS2Ptr<Unk_GrmInput> spInput, ATL::CAtlArray<CStringW>& arrHistory);   // the input history keys
CStringW FUN_141842320(const CStringW& strText);                    // text to html
void FUN_140d73aa0(CStringW strText, int nA, int nB, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, IMessageListener* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
IClientPlatform* FUN_140d86260();
unsigned int FUN_140869420();                                       // the client millisecond clock
void FUN_14151f200();                                               // the click sound
void FUN_1412751f0(CStringW strText, int nA, int nB);               // a system chat line
void FUN_141276180(const CString& strSound, CString strExtra);      // plays a sound
CString FUN_1412755f0();                                            // the UI settings directory
CString FUN_140cc2a00(const CString& strRoot, const CString& strFile);   // path join
void FUN_14086ddc0(TiXmlDocument* pDoc);                            // Clear
void* FUN_14081b310(TiXmlDocument* pDoc);                           // RootElement
void* FUN_14086e090(TiXmlDocument* pDoc, class TiXmlElement* pChild);   // LinkEndChild
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* szPath);        // SaveFile
void* FUN_140165cf0(TiXmlDocument* pDoc, const char* szName);       // FirstChildElement
void FUN_140873e30(void* pCfg, const char* szName, float f);
void FUN_140873ca0(void* pCfg, const char* szName, int n);
void FUN_1408740a0(void* pCfg, const char* szName, const CStringW& str);
int FUN_140873360(void* pCfg, const char* szName, float* pf);
int FUN_1408731e0(void* pCfg, const char* szName, int& n);
int FUN_140873420(void* pCfg, const char* szName, CStringW& str);
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);
void* FUN_1422bb8b0(int nMovieId);                                  // the movie of a UI layer
void FUN_14256e3e0(void* pMovie, Scaleform::GFx::Value* pValue);   // movie->CreateArray

class TiXmlElement
{
public:
    TiXmlElement(const char* szValue);                              // 0x14086f2f0
private:
    char m_pad[0x90];
};

// ---- UIGroupMessenger ----

// @0x141947920
UIGroupMessenger::UIGroupMessenger(int nGroupId, int nIndex, int bDeleteSave)
    : m_fOffsetX(0), m_fOffsetY(0), m_nAlignType(0), m_nScrollPosition(0), m_strName(L""), m_nAlpha(100),
      m_nIndex(nIndex), m_bUserList(0), m_nTypingTime(0), m_nGroupId(nGroupId)
{
    m_80 = 1;
    m_88 = 1;
    FUN_141924170(1);
    FUN_1422dc3b0(1);
    if (bDeleteSave)
        vfunc_84(0);
    m_strName = StringFormat(L"{0} {1}", FUN_14028de60(0x5d0), nIndex + 1);
}

// @0x141947bc0
UIGroupMessenger::~UIGroupMessenger()
{
}

// @0x141947c60
CString UIGroupMessenger::vfunc_1()
{
    return "GroupMessenger";
}

// @0x141947cb0
int UIGroupMessenger::vfunc_65()
{
    UIDialog::vfunc_65();
    FUN_140939a10()->FUN_140da4e40(L"NotifyChatEmoticonSelected",
                                   Delegate<void(NotifyObject*)>(this, &UIGroupMessenger::FUN_14194a6f0));
    return 1;
}

// @0x141947da0
void UIGroupMessenger::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChatEmoticonSelected",
                                   Delegate<void(NotifyObject*)>(this, &UIGroupMessenger::FUN_14194a6f0));
    FUN_140bc09f0()->FUN_141b38c70(this);
    m_inputHistory.RemoveAll();
    if (FUN_141482e80()->m_pBrowser != 0)
        FUN_141482e80()->m_pBrowser->FUN_141953460(m_strName);
}

// @0x141947f10
void UIGroupMessenger::vfunc_69()
{
    vfunc_63(1);
}

// @0x141947f40
void UIGroupMessenger::vfunc_63(int n)
{
    m_6c = n;
    FUN_14194bde0();
    vfunc_4();
    if (n == 0)
    {
        MS2Ptr<Unk_GrmList> spOutput = FUN_140c02900("m_textOutput");
        if ((Unk_GrmList*)spOutput)
        {
            unsigned nRows = FUN_141482e80()->m_pBrowser->FUN_141952b30(m_nGroupId);
            if ((unsigned)spOutput->FUN_1422dd150() < nRows + 5)
                nRows = spOutput->FUN_1422dd150();
            else
                nRows = nRows + 5;
            spOutput->FUN_1422dd0d0(nRows);
            spOutput->vfunc_24(1);
        }
        FUN_141482e80()->FUN_141482c80(m_strName);
        FUN_140b632f0()->FUN_1422d48f0(this, m_e0);
    }
    else
    {
        MS2Ptr<Unk_GrmInput> spInput = FUN_140e35bd0("m_textInput");
        if ((Unk_GrmInput*)spInput)
        {
            if (spInput->FUN_1422c76c0())
            {
                spInput->FUN_1422c7630(0);
                spInput->FUN_1422e0b80("");
                spInput->vfunc_24(1);
            }
        }
        FUN_141482e80()->FUN_141482d30(m_strName);
    }
    if (FUN_141482e80()->m_pBrowser != 0)
        FUN_141482e80()->m_pBrowser->FUN_141952960(m_nGroupId);
}

// @0x1419482c0
int UIGroupMessenger::vfunc_4()
{
    if (!m_80)
        return 0;
    if (!m_4c)
        return 1;
    TiXmlDocument doc;
    if (!FUN_14081b310(&doc))
        FUN_14086e090(&doc, new TiXmlElement(vfunc_1()));
    void* pRoot = FUN_14081b310(&doc);
    if (!pRoot)
        return 0;
    vfunc_53(pRoot);
    return FUN_1408710c0(&doc, FUN_140cc2a00(FUN_1412755f0(), FUN_14194b8a0()));
}

// @0x141948520
int UIGroupMessenger::vfunc_5()
{
    if (!m_80)
        return 0;
    m_78 = 0;
    void* pNode = FUN_140165cf0(&m_e8, vfunc_1());
    if (pNode == 0)
    {
        TiXmlDocument doc;
        if (doc.FUN_140870fc0(FUN_140cc2a00(FUN_1412755f0(), FUN_14194b8a0()), 0))
        {
            void* pLoaded = FUN_140165cf0(&doc, vfunc_1());
            if (pLoaded == 0)
                return 0;
            m_78 = vfunc_54(pLoaded);
        }
    }
    else
    {
        m_78 = vfunc_54(pNode);
        FUN_14086ddc0(&m_e8);
    }
    return m_78;
}

// @0x1419487c0
int UIGroupMessenger::vfunc_53(void* pCfg)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        FUN_141926620(&m_nAlignType, &m_fOffsetX, &m_fOffsetY);
        FUN_140873e30(pCfg, "offsetX", m_fOffsetX);
        FUN_140873e30(pCfg, "offsetY", m_fOffsetY);
        FUN_140873ca0(pCfg, "alignType", m_nAlignType);
        FUN_140873ca0(pCfg, "scrollPosition", m_nScrollPosition);
        FUN_140873ca0(pCfg, "width", pDialog->FUN_1422c1340());
        FUN_140873ca0(pCfg, "height", pDialog->FUN_1422c13b0());
        FUN_1408740a0(pCfg, "name", m_strName);
        FUN_140873ca0(pCfg, "alpha", m_nAlpha);
        FUN_140873ca0(pCfg, "userlist", m_bUserList);
        FUN_140873ca0(pCfg, "minimize", m_6c);
    }
    return 1;
}

// @0x141948980
int UIGroupMessenger::vfunc_54(void* pCfg)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        int nWidth = 0;
        int nHeight = 0;
        FUN_140873360(pCfg, "offsetX", &m_fOffsetX);
        FUN_140873360(pCfg, "offsetY", &m_fOffsetY);
        FUN_1408731e0(pCfg, "alignType", m_nAlignType);
        FUN_1408731e0(pCfg, "scrollPosition", m_nScrollPosition);
        FUN_1408731e0(pCfg, "width", nWidth);
        FUN_1408731e0(pCfg, "height", nHeight);
        FUN_140873420(pCfg, "name", m_strName);
        FUN_1408731e0(pCfg, "alpha", m_nAlpha);
        FUN_1408731e0(pCfg, "userlist", m_bUserList);
        FUN_1408731e0(pCfg, "minimize", m_6c);
        pDialog->FUN_1422c79e0(nWidth, nHeight);
    }
    return 1;
}

// @0x141948b30
int UIGroupMessenger::vfunc_84(int bDeleteSave)
{
    m_80 = bDeleteSave == 0;
    return DeleteFileA(FUN_140cc2a00(FUN_1412755f0(), FUN_14194b8a0()));
}

// @0x141948c20
void UIGroupMessenger::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_140bc09f0()->FUN_141b38be0(this);
    FUN_14194bde0();
    if (FUN_141482e80()->m_pBrowser != 0)
    {
        ATL::CAtlArray<TalkLog> logs;
        MS2Ptr<TalkLogList> spLog;
        if (FUN_141482e80()->m_pBrowser->m_logs.Lookup(m_nGroupId, spLog))
            logs.Copy(spLog->m_logs);
        int nScrollPosition = m_nScrollPosition;
        for (size_t i = 0; i < logs.GetCount(); i++)
        {
            TalkLog log(logs[i]);
            FUN_14194d3d0(log.m_nKind, log.m_strMsg, log.m_strName, log.m_nA);
        }
        MS2Ptr<Unk_GrmList> spOutput = FUN_140c02900("m_textOutput");
        if ((Unk_GrmList*)spOutput)
        {
            m_nScrollPosition = nScrollPosition;
            spOutput->FUN_1422e17f0(m_nScrollPosition);
        }
        MS2Ptr<Unk_GrmInput> spInput = FUN_140e35bd0("m_textInput");
        if ((Unk_GrmInput*)spInput)
            spInput->FUN_1422e0d60(*Client::Constants::GetInstance()->MaxChatLength.Get());
    }
}

// @0x141948f40
void UIGroupMessenger::vfunc_43()
{
    if (m_60 == 0)
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog)
        {
            pDialog->vfunc_2(m_nAlignType, (int)m_fOffsetX, (int)m_fOffsetY);
            FUN_141926620(&m_nAlignType, &m_fOffsetX, &m_fOffsetY);
        }
    }
}

// @0x141949020
int UIGroupMessenger::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (!FUN_14194c6d0())
        return 0;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
        return FUN_14194cbb0();
    if (FUN_14025e7c0()->FUN_14116d840())
        return FUN_14194cd00();
    return 0;
}

// @0x1419490b0
void UIGroupMessenger::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_nTypingTime != 0)
    {
        if (m_nTypingTime + 10000 <= FUN_140869420())
        {
            FUN_14194d6f0();
            m_nTypingTime = 0;
            m_typing.RemoveAll();
        }
    }
}

// @0x141949130
int UIGroupMessenger::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520() == 0x7d1)
    {
        CStringW strTag = pMsg->FUN_1422b8f40();
        int nResult = pMsg->FUN_1422b8a10();
        Scaleform::GFx::Value root = static_cast<Unk_GrmMsg*>(pMsg)->FUN_1422b9260();
        if (strTag == s_strGroupEdit)
        {
            if (nResult == 0)
            {
                ASObj box(root, 2);
                if (MS2Ptr<ASTextField> spName = box.FUN_1409b4620("m_textInput"))
                {
                    Unk_BlockList request(0x4e93, m_nGroupId);
                    request.Add("MessengerName", spName->FUN_1422c4da0(), 0);
                    request.SetEnabled(1);
                    if (FUN_140d86260()->vfunc_37(&request) == 1)
                    {
                        if (FUN_14194ce40(spName->FUN_1422c4da0()) == 1)
                            return 0;
                        FUN_14194bc70(spName->FUN_1422c4da0());
                    }
                }
                MS2Ptr<Unk_GrmSlider> spAlpha = static_cast<Unk_GrmBoxRoot&>(box).FUN_140fafed0<Unk_GrmSlider>("m_slider0");
                if ((Unk_GrmSlider*)spAlpha)
                    m_nAlpha = (int)spAlpha->FUN_1422ce840();
                FUN_14194bde0();
                if (FUN_141482e80()->m_pBrowser != 0)
                    FUN_141482e80()->m_pBrowser->FUN_141952530();
            }
            vfunc_4();
            FUN_14151f200();
            return 1;
        }
        if (strTag == s_strGroupExit)
        {
            if (nResult == 0)
                CGroupChatManager::GetInstance()->FUN_14137efa0(m_nGroupId, 0);
            FUN_14151f200();
            return 1;
        }
    }
    return 0;
}

// @0x141949640
void UIGroupMessenger::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer != 0 && FUN_141482e80()->m_pBrowser != 0)
    {
        if (strMethod == "getTooltip")
        {
            MS2Ptr<CItem> spItem(0);
            __int64 nUid = _atoi64(pArgs->FUN_1422b8d30());
            if (FUN_141482e80()->m_pBrowser->m_items.Lookup(nUid, spItem))
            {
                ASTooltip tooltip(pPlayer, 2, 2);
                if (tooltip.FUN_1409e0d40(spItem.get()))
                {
                    tooltip.FUN_1409c6c80();
                    tooltip.FUN_1409db7b0(spItem);
                    FUN_1409b4bc0(pRetVal, tooltip.FUN_1422bb870());
                }
            }
        }
        else if (strMethod == "itemPreview")
        {
            MS2Ptr<CItem> spItem(0);
            __int64 nUid = _atoi64(pArgs->FUN_1422b8d30());
            if (FUN_141482e80()->m_pBrowser->m_items.Lookup(nUid, spItem))
            {
                if (ItemPreviewMgr::GetInstance()->FUN_140d40670())
                    ItemPreviewMgr::GetInstance()->FUN_140d40120(spItem, 0);
            }
        }
    }
}

// @0x141949900
int UIGroupMessenger::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("eventFocusIn", szMethod) == 0)
    {
        vfunc_85();
        return 1;
    }
    if (_stricmp("OnHideDialog", szMethod) == 0)
    {
        if (FUN_141482e80()->m_pBrowser != 0)
            FUN_141482e80()->m_pBrowser->FUN_141953160(m_strName);
        return 1;
    }
    if (_stricmp("OnShowInviteDialog", szMethod) == 0)
    {
        UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
        if (pInvite != 0)
        {
            pInvite->FUN_14199fcf0(m_nGroupId);
            CUIService::GetInstance()->FUN_141adc530((eUIClassID)0x4e90);
        }
        return 1;
    }
    if (_stricmp("OnShowUserList", szMethod) == 0)
    {
        m_bUserList = 1;
        FUN_14194bde0();
    }
    else if (_stricmp("OnHideUserList", szMethod) == 0)
    {
        m_bUserList = 0;
        FUN_14194bde0();
    }
    else if (_stricmp("OnShowConfigDialog", szMethod) == 0)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x15, L"", this, s_strGroupEdit);
        if (spBox)
        {
            spBox->FUN_140b76940(m_strName);
            spBox->FUN_140533ff0(m_nAlpha);
            FUN_140d73c60(spBox);
        }
    }
    else if (_stricmp("OnLeaveGroupMessenger", szMethod) == 0)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_14052bd00(0x81b, FUN_14194b960()), this, s_strGroupExit);
        if (spBox)
            FUN_140d73c60(spBox);
    }
    else if (_stricmp("OnBuildScrollingList", szMethod) == 0)
    {
        FUN_14194c060();
    }
    else if (_stricmp("OnPopupMenu", szMethod) == 0)
    {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs))
        {
            CStringW strName = args.FUN_1422b8f40();
            float x = args.FUN_1422b8c10();
            float y = args.FUN_1422b8c10();
            FUN_14194b440(strName, x, y);
        }
    }
    else
    {
        if (_stricmp("eventTextInput", szMethod) == 0)
        {
            MS2Ptr<Unk_GrmInput> spInput = FUN_140e35bd0("m_textInput");
            if ((Unk_GrmInput*)spInput)
                FUN_140d2c2a0(spInput, m_inputHistory);
            return 1;
        }
        if (_stricmp("scrollPosition", szMethod) == 0)
        {
            ASData args;
            if (args.FUN_1422b9620(pArgs, nArgs))
                m_nScrollPosition = (int)args.FUN_1422b8c10();
        }
        else if (_stricmp("eventChatEmoticonOpen", szMethod) == 0)
        {
            CUIService::GetInstance()->FUN_141adc750((eUIClassID)0x4f80);
        }
        else if (_stricmp("eventChatEmoticonPush", szMethod) == 0)
        {
            ASData args;
            if (!args.FUN_1422b9620(pArgs, nArgs))
                return 0;
            FUN_14194ade0(args.FUN_1422b8a10());
        }
        else if (_stricmp("eventChatEmoticonFavorite", szMethod) == 0)
        {
            ASData args;
            if (!args.FUN_1422b9620(pArgs, nArgs))
                return 0;
            FUN_14194b190(args.FUN_1422b8a10(), args.FUN_1422b8a90());
        }
        else if (_stricmp("eventChatEmoticonPush", szMethod) == 0)
        {
            ASData args;
            if (args.FUN_1422b9620(pArgs, nArgs))
            {
                CStringW strText = args.FUN_1422b8f40();
                CGroupChatManager::GetInstance()->FUN_14137f080(m_nGroupId, strText);
            }
        }
    }
    return 0;
}

// @0x14194a320
void UIGroupMessenger::FUN_14194a320(int nKind, const CStringW& strName, const CStringW& strText)
{
}

// @0x14194a340
void UIGroupMessenger::FUN_14194a340(int nKind, const CStringW& strName, const CStringW& strOther)
{
    FUN_14194bde0();
    FUN_14194a650(nKind, strName, FUN_140632a60(0x80e, strName, strOther));
}

// @0x14194a3c0
void UIGroupMessenger::FUN_14194a3c0(int nKind, const CStringW& strName, int nMode)
{
    FUN_14194bde0();
    CStringW strMsg;
    if (nMode == 0)
        strMsg = FUN_14052bd00(0x810, strName);
    else if (nMode == 1)
        strMsg = FUN_14052bd00(0x813, strName);
    FUN_14194a650(nKind, strName, strMsg);
}

// @0x14194a4d0
void UIGroupMessenger::FUN_14194a4d0(int nKind, const CStringW& strName)
{
    FUN_14194bde0();
    FUN_14194a650(nKind, strName, FUN_14052bd00(0x811, strName));
}

// @0x14194a540
void UIGroupMessenger::FUN_14194a540(int nKind, const CStringW& strName)
{
    FUN_14194bde0();
    FUN_14194a650(nKind, strName, FUN_14052bd00(0x812, strName));
}

// @0x14194a5b0
void UIGroupMessenger::FUN_14194a5b0(int nKind, const CStringW& strName, const CStringW& strMsg)
{
    FUN_14194d3d0(nKind, strName, strMsg, 0);
    if (FUN_141482e80()->m_pBrowser != 0)
        FUN_141482e80()->m_pBrowser->FUN_141953810(nKind, strName, strMsg, 0, vfunc_64());
}

// @0x14194a650
void UIGroupMessenger::FUN_14194a650(int nKind, const CStringW& strName, const CStringW& strMsg)
{
    FUN_14194d3d0(nKind, strName, strMsg, 1);
    if (FUN_141482e80()->m_pBrowser != 0)
        FUN_141482e80()->m_pBrowser->FUN_141953810(nKind, strName, strMsg, 1, vfunc_64());
}

// @0x14194a6f0
void UIGroupMessenger::FUN_14194a6f0(NotifyObject* pNotify)
{
    NotifyChatEmoticonSelected* pSelected = dynamic_cast<NotifyChatEmoticonSelected*>(pNotify);
    if (pSelected == 0 || m_30.IsNull())
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    if (pSelected->m_strTarget != m_strName)
    {
        FUN_14194ad60();
        return;
    }
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(pSelected->m_nEmoticonId);
    if (!spEmo)
        return;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x2d2, 0);
        return;
    }
    if (!spCli->FUN_140a39dd0(spEmo->m_nId))
        return;
    std::list<ChatEmoticonDataPtr> emoticons;
    emoticons.push_back(spEmo);
    FUN_14194a930(emoticons);
    FUN_1419235d0();
}

// @0x14194a930
void UIGroupMessenger::FUN_14194a930(std::list<MS2Ptr<ChatEmoticonData> >& emoticons)
{
    if (emoticons.empty())
        return;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x4ad, 0);
        return;
    }
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    void* pMovie = FUN_1422bb8b0(m_28);
    if (pMovie == 0)
        return;
    ASObj data(2);
    Scaleform::GFx::Value arr;
    FUN_14256e3e0(pMovie, &arr);
    for (std::list<ChatEmoticonDataPtr>::const_iterator it = emoticons.begin(); it != emoticons.end(); ++it)
    {
        ChatEmoticonDataPtr spEmo = *it;
        if (!!spEmo)
        {
            ASObj item(2);
            item.FUN_1409c0d20("id", spEmo->m_nId);
            item.FUN_1407cbb20("imgPath", spEmo->m_strImagePath);
            item.FUN_1407cb9c0("width", spEmo->m_nWidth);
            item.FUN_1407cb9c0("height", spEmo->m_nHeight);
            item.FUN_1407cbbe0("favorite", spCli->FUN_140a39fa0(spEmo->m_nId));
            arr.PushBack(item.FUN_1422bb870());
        }
    }
    if (arr.GetArraySize() == 0)
        return;
    data.FUN_1409adbe0("emoticonDatas", arr);
    pDialog->Invoke("openChatEmoticonPreview", data.FUN_1422bb870());
}

// @0x14194ad60
void UIGroupMessenger::FUN_14194ad60()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("closeChatEmoticonPreview");
}

// @0x14194ade0
int UIGroupMessenger::FUN_14194ade0(int nEmoticonId)
{
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (!!spEmo)
    {
        MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
        if (spCli.IsNull())
        {
            MS2_ASSERT_AT(0x4e8, 0);
            return 0;
        }
        if (!spCli->FUN_140a39dd0(spEmo->m_nId))
            return 0;
        COutPacket packet(0xb7, 0);
        packet.vfunc_o10_1(4);
        packet.vfunc_o10_3(nEmoticonId);
        packet.vfunc_o10_8(FUN_14194b960());
        FUN_140710590(packet);
        return 1;
    }
    return 0;
}

// @0x14194afc0
void UIGroupMessenger::FUN_14194afc0(int nEmoticonId)
{
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (!!spEmo)
    {
        CStringW strSize(L"");
        if (spEmo->m_nWidth != 0 || spEmo->m_nHeight != 0)
            strSize = StringFormat(L"width='{0}' height='{1}'", spEmo->m_nWidth, spEmo->m_nHeight);
        CStringW strLine = FUN_140cde1f0(L"<img src='img://emoticon:{0}' vspace='{1}' {2} />", spEmo->m_nId,
                                         spEmo->m_nVSpace, strSize);
        CGroupChatManager::GetInstance()->FUN_14137f080(m_nGroupId, strLine);
    }
}

// @0x14194b190
int UIGroupMessenger::FUN_14194b190(int nEmoticonId, bool bFavorite)
{
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (!!spEmo)
    {
        MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
        if (spCli.IsNull())
        {
            MS2_ASSERT_AT(0x518, 0);
            return 0;
        }
        if (!spCli->FUN_140a39dd0(spEmo->m_nId))
            return 0;
        COutPacket packet(0xb7, 0);
        packet.vfunc_o10_1(bFavorite ? 5 : 6);
        packet.vfunc_o10_3(nEmoticonId);
        FUN_140710590(packet);
        return 1;
    }
    return 0;
}

// @0x14194b360
void UIGroupMessenger::vfunc_ugc_1(void* pId, CString strText)
{
    if (vfunc_55())
        return;
    if (pId == 0)
        return;
    if (FUN_1403ed2d0()->FUN_141bd0cc0() == 0)
        return;
    m_nTypingTime = FUN_140869420();
    m_typing.SetAt((unsigned __int64)pId, strText);
}

// @0x14194b440
void UIGroupMessenger::FUN_14194b440(const CStringW& strName, float x, float y)
{
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (pPlayer->vfunc_77() != strName)
    {
        Unk_GrmMenu* pMenu = FUN_140c30140(0x4e39);
        if (pMenu != 0)
        {
            Unk_PopupMenuInfo info(x, y, 3, 0x635e, 0, "", 0);
            CStringW strHistory;
            MS2Ptr<TalkLogList> spLog;
            if (FUN_141482e80()->m_pBrowser->m_logs.Lookup(m_nGroupId, spLog))
            {
                for (std::deque<CStringW>::reverse_iterator it = spLog->m_lines.rbegin(); it != spLog->m_lines.rend(); ++it)
                {
                    CStringW strLine(*it);
                    FUN_14083d2b0(strLine);
                    if (strHistory.GetLength() + strLine.GetLength() > 2000)
                        break;
                    strHistory.AppendFormat(strLine);
                }
            }
            Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FUN_14137e630(m_nGroupId);
            if (spChat.get())
            {
                Unk_ChatMemberPtr spMember = spChat->FUN_14137ba10(strName);
                if (spMember.get())
                    pMenu->FUN_141a7f890(info, spMember.get(), strHistory, 6);
            }
        }
    }
}

// @0x14194b800
void UIGroupMessenger::vfunc_85()
{
    FUN_141482e80()->FUN_141482c80(m_strName);
}

// @0x14194b870
void UIGroupMessenger::vfunc_86()
{
}

// @0x14194b880
int UIGroupMessenger::FUN_14194b880()
{
    return m_bUserList;
}

// @0x14194b8a0
CString UIGroupMessenger::FUN_14194b8a0()
{
    CString strFile;
    strFile.Format("%s%d.xml", (const char*)vfunc_1(), m_nIndex);
    return strFile;
}

// @0x14194b960
CStringW UIGroupMessenger::FUN_14194b960()
{
    return m_strName;
}

// @0x14194b9b0
unsigned UIGroupMessenger::FUN_14194b9b0()
{
    return m_nGroupId;
}

// @0x14194b9d0
int UIGroupMessenger::FUN_14194b9d0(__int64 nCharacterId)
{
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FUN_14137e630(m_nGroupId);
    if (spChat.get() && spChat->FUN_14137b410(nCharacterId))
        return 1;
    return 0;
}

// @0x14194ba80
CStringW UIGroupMessenger::FUN_14194ba80(unsigned __int64 nCharacterId)
{
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FUN_14137e630(m_nGroupId);
    if (spChat == 0)
        return L"";
    ATL::CAtlList<Unk_ChatMemberPtr> members(10);
    spChat->FUN_14137bdc0(members);
    POSITION pos = members.GetHeadPosition();
    while (pos != 0)
    {
        Unk_ChatMemberPtr spMember = members.GetAt(pos);
        if (!(spMember == 0))
        {
            if (spMember->m_proxy.m_8 == nCharacterId)
                return spMember->m_proxy.FUN_1408f19e0();
        }
        members.GetNext(pos);
    }
    return L"";
}

// @0x14194bc70
void UIGroupMessenger::FUN_14194bc70(CStringW strName)
{
    m_strName = strName;
}

// @0x14194bcc0
void UIGroupMessenger::FUN_14194bcc0(CStringW strText)
{
    MS2Ptr<Unk_GrmInput> spInput = FUN_140e35bd0("m_textInput");
    if ((Unk_GrmInput*)spInput)
    {
        vfunc_78();
        FUN_14194d100(spInput, strText, 1);
    }
    m_inputHistory.Add(strText);
}

// @0x14194bde0
void UIGroupMessenger::FUN_14194bde0()
{
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FUN_14137e630(m_nGroupId);
    if (spChat == 0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        CStringW strCount;
        strCount.Format(L"%d/%d", spChat->FUN_14137bad0(), 20);
        ASObj data(2);
        data.FUN_1407cb9c0("alpha", m_nAlpha);
        data.FUN_1407cb9c0("minimize", m_6c);
        data.FUN_1407cb9c0("userlist", m_bUserList);
        data.FUN_1407cbb20("groupName", m_strName);
        data.FUN_1407cbb20("userCount", strCount);
        pDialog->Invoke("setData", data.FUN_1422bb870());
    }
    if (FUN_141482e80()->m_pBrowser != 0)
        FUN_141482e80()->m_pBrowser->FUN_141952530();
}

// @0x14194c060
void UIGroupMessenger::FUN_14194c060()
{
    if (m_6c != 0 || m_bUserList == 0)
        return;
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FUN_14137e630(m_nGroupId);
    if (spChat == 0)
        return;
    ATL::CAtlList<Unk_ChatMemberPtr> joined(10);
    spChat->FUN_14137bdc0(joined);
    ATL::CAtlList<Unk_ChatMemberPtr> invited(10);
    spChat->FUN_14137bee0(invited);
    MS2Ptr<Unk_GrmList> spList = FUN_140c02900("m_userList");
    if ((Unk_GrmList*)spList)
    {
        spList->FUN_1422dd1d0();
        spList->vfunc_24(1);
        POSITION pos = joined.GetHeadPosition();
        while (pos != 0)
        {
            Unk_ChatMemberPtr spMember = joined.GetAt(pos);
            if (!(spMember == 0))
            {
                Unk_GrmEntry entry(spMember.get());
                ASObj item(2);
                item.FUN_1407cb9c0(s_strOnline, entry.FUN_141483d80());
                item.FUN_1407cbb20(s_strIconPath, entry.FUN_141483dc0());
                item.FUN_1407cbb20(s_strCharacterName, entry.FUN_141483e10());
                item.FUN_1407cbb20(s_strLevelAndJobName, entry.FUN_141483e60());
                spList->FUN_1422dd230(item);
            }
            joined.GetNext(pos);
        }
        pos = invited.GetHeadPosition();
        while (pos != 0)
        {
            Unk_ChatMemberPtr spMember = invited.GetAt(pos);
            if (!(spMember == 0))
            {
                Unk_GrmEntry entry(spMember.get());
                ASObj item(2);
                item.FUN_1407cb9c0(s_strOnline, entry.FUN_141483d80());
                item.FUN_1407cbb20(s_strIconPath, entry.FUN_141483dc0());
                item.FUN_1407cbb20(s_strCharacterName, entry.FUN_141483e10());
                item.FUN_1407cbb20(s_strLevelAndJobName, entry.FUN_141483e60());
                spList->FUN_1422dd230(item);
            }
            invited.GetNext(pos);
        }
        int nRows = (unsigned)spList->FUN_1422dd150() < 9 ? spList->FUN_1422dd150() : 8;
        spList->FUN_1422dd000(nRows);
        spList->vfunc_24(1);
    }
}

// @0x14194c6d0
int UIGroupMessenger::FUN_14194c6d0()
{
    if (vfunc_64())
        return 0;
    if (FUN_141482e80()->FUN_1414829e0() != m_strName)
        return 0;
    MS2Ptr<Unk_GrmInput> spInput = FUN_140e35bd0("m_textInput");
    if ((Unk_GrmInput*)spInput)
    {
        if (spInput->FUN_1422c76c0())
            return 1;
    }
    if (CUIService::GetInstance()->FUN_141adbb00() == 0)
        return 1;
    return 0;
}

// @0x14194c830
int UIGroupMessenger::FUN_14194c830()
{
    MS2Ptr<Unk_GrmInput> spInput = FUN_140e35bd0("m_textInput");
    if (spInput == 0)
        return 0;
    CStringW strText = spInput->FUN_1422e0b00();
    strText = strText.Trim();
    if (strText.IsEmpty())
    {
        FUN_14194cd00();
        return 0;
    }
    CStringW strHtml = spInput->FUN_1422e0c20();
    if (!FUN_140d2aa60(strHtml))
    {
        if (CBanTextChecker* pChecker = CommonString::GetInstance()->GetChecker())
        {
            pChecker->MaskBannedWords(strText);
            pChecker->FilterReservedWords(strText);
        }
        strText = FUN_141842320(strText);
        CGroupChatManager::GetInstance()->FUN_14137f080(m_nGroupId, strText);
    }
    else
    {
        if (CBanTextChecker* pChecker = CommonString::GetInstance()->GetChecker())
        {
            pChecker->MaskBannedWords(strHtml);
            pChecker->FilterReservedWords(strHtml);
        }
        FUN_140d2c650(strHtml);
        CGroupChatManager::GetInstance()->FUN_14137f080(m_nGroupId, strHtml);
    }
    FUN_14194cd00();
    return 1;
}

// @0x14194cbb0
int UIGroupMessenger::FUN_14194cbb0()
{
    MS2Ptr<Unk_GrmInput> spInput = FUN_140e35bd0("m_textInput");
    if ((Unk_GrmInput*)spInput)
    {
        if (!spInput->FUN_1422c76c0())
        {
            int nLength = spInput->FUN_1422e0b00().GetLength();
            spInput->FUN_1422c7630(1);
            spInput->FUN_1422e1500(nLength, nLength);
            spInput->vfunc_24(1);
        }
        else
        {
            FUN_14194c830();
        }
    }
    return 1;
}

// @0x14194cd00
int UIGroupMessenger::FUN_14194cd00()
{
    MS2Ptr<Unk_GrmInput> spInput = FUN_140e35bd0("m_textInput");
    if ((Unk_GrmInput*)spInput)
    {
        if (spInput->FUN_1422c76c0())
        {
            m_inputHistory.RemoveAll();
            spInput->FUN_1422c7630(0);
            spInput->FUN_1422e0bd0(L"<FONT></FONT>");
            spInput->vfunc_24(1);
            return 1;
        }
    }
    return 0;
}

// @0x14194ce40
int UIGroupMessenger::FUN_14194ce40(CStringW strName)
{
    if (CBanTextChecker* pChecker = CommonString::GetInstance()->GetChecker())
    {
        CStringW strMessage;
        if (pChecker->FUN_140225f70(strName, strMessage))
        {
            FUN_140d73aa0(strMessage, 0, 0, L"");
            return 1;
        }
    }
    if (FUN_141482e80()->m_pBrowser != 0)
    {
        UIGroupMessenger* pOther = FUN_141482e80()->m_pBrowser->FUN_141952fc0(strName);
        if (pOther != 0 && pOther != this)
        {
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0, FUN_14028de60(0x817), 0, L"");
            if (spBox)
                FUN_140d73c60(spBox);
            return 1;
        }
    }
    return 0;
}

// @0x14194d100
void UIGroupMessenger::FUN_14194d100(MS2Ptr<Unk_GrmInput> spInput, const CStringW& strText, int bSelectEnd)
{
    CStringW strCurrent = spInput->FUN_1422e0b00();
    if (strCurrent.GetLength() < spInput->FUN_1422e0da0())
    {
        CStringW strSpace(L" ");
        CStringW strHtml = spInput->FUN_1422e0c20();
        if (strHtml.GetLength() + strSpace.GetLength() + strText.GetLength() < 0x800)
        {
            spInput->FUN_1422e0bd0(strHtml + strText + strSpace);
            spInput->vfunc_24(1);
            int nLength = spInput->FUN_1422e0b00().GetLength();
            if (bSelectEnd && nLength > 0)
                spInput->FUN_1422e1500(nLength, nLength);
            spInput->vfunc_24(1);
        }
    }
}

// @0x14194d3d0
void UIGroupMessenger::FUN_14194d3d0(int nKind, const CStringW& strName, const CStringW& strMsg, int bSystem)
{
    MS2Ptr<Unk_GrmList> spOutput = FUN_140c02900("m_textOutput");
    if ((Unk_GrmList*)spOutput)
    {
        bool bVisibleBg = FUN_14194da30(strMsg);
        CStringW strFrame = FUN_14194d8f0(strName, bSystem);
        CString strIcon = FUN_1414842b0(nKind, strName);
        ASObj item(2);
        item.FUN_1407cbb20(s_strFrame, strFrame);
        item.FUN_1407cbb20(s_strText, strMsg);
        item.FUN_1407cba60(s_strIconPath, strIcon);
        item.FUN_1407cbb20(s_strCharacterName, strName);
        item.FUN_1407cbbe0("visibleBg", bVisibleBg);
        spOutput->FUN_1422dd230(item);
        spOutput->vfunc_24(1);
        spOutput->FUN_1422e17a0();
    }
}

// @0x14194d6f0
void UIGroupMessenger::FUN_14194d6f0()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    POSITION pos = m_typing.GetStartPosition();
    while (pos != 0)
    {
        unsigned __int64 nId = m_typing.GetKeyAt(pos);
        CString strProfile(m_typing.GetValueAt(pos));
        CString strImage = FUN_141028be0(nId, strProfile, 1, "");
        pDialog->Invoke("updateProfile", FUN_14194ba80(nId), CString(strImage));
        m_typing.GetNext(pos);
    }
}

// @0x14194d8f0
CStringW UIGroupMessenger::FUN_14194d8f0(const CStringW& strName, int bSystem)
{
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (bSystem)
        return L"notify";
    if (pPlayer != 0 && pPlayer->vfunc_77() == strName)
        return L"me";
    return L"other";
}

// @0x14194da30
bool UIGroupMessenger::FUN_14194da30(CStringW strMsg)
{
    if (strMsg.IsEmpty())
        return true;
    if (strMsg.GetAt(0) == L'<')
    {
        strMsg.MakeLower();
        return strMsg.Find(L"img://emoticon:") == -1;
    }
    return true;
}

// @0x14194dd10
UIInviteGroupDialog* FUN_14194dd10(int nUiId)
{
    if (CUIService::GetInstance() != 0)
    {
        MS2Ptr<UIObject> spObj = CUIService::GetInstance()->FUN_141adcea0((eUIClassID)nUiId);
        if (spObj.get() != 0)
            return dynamic_cast<UIInviteGroupDialog*>(spObj.operator->());
    }
    return 0;
}

// @0x14194e740
// (thunk: UIUGCEventListener slot 0 of the window, the compiler's this-adjusting destructor thunk)

// @0x14194f120
int UIGroupMessenger::vfunc_48()
{
    return 0x4e91;
}
