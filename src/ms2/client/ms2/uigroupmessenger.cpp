// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGroupMessenger / UIGroupMessengerBrowser: the group chat
// windows and their tray, see uigroupmessenger.h.
// MS2-UNIT: client\ms2\uigroupmessenger.cpp
// MS2-RANGE: 0x141947920-0x141959330 .text$mn
// MS2-RANGE: 0x140113b00-0x140113ff0 .text$di
// MS2-GUESS-LOOKALIKES
// MS2-PIN: memmove_s 0x141950650
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
#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/blindmanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/mstime.h"
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
    void FUN_141482b70();                                           // forgets every chat name
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
    void FUN_14199fd10(int nGroupId, const CStringW& strName, const CStringW& strText);
    void FUN_14199fd60(int nGroupId, const CStringW& strName, const CStringW& strOther);
    void FUN_14199fdb0(int nGroupId, const CStringW& strName);
    void FUN_14199fdf0(int nGroupId, const CStringW& strName);
    void FUN_14199fe30(int nGroupId, const CStringW& strName);
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
MS2_REPLACE_METHOD(0x141947C60, UIGroupMessenger, vfunc_1, 61, 0xEA0A8AA4);

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
MS2_REPLACE_METHOD(0x141947F10, UIGroupMessenger, vfunc_69, 38, 0xF585F677);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x141947F40, UIGroupMessenger, vfunc_63, 890, 0x0DD48E64);

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
MS2_REPLACE_METHOD(0x1419482C0, UIGroupMessenger, vfunc_4, 598, 0x06A5FC79);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x141948520, UIGroupMessenger, vfunc_5, 662, 0x45487133);

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
MS2_REPLACE_METHOD(0x1419487C0, UIGroupMessenger, vfunc_53, 434, 0x79EF8D2C);

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
MS2_REPLACE_METHOD(0x141948980, UIGroupMessenger, vfunc_54, 415, 0x74DBE6B6);

// @0x141948b30
int UIGroupMessenger::vfunc_84(int bDeleteSave)
{
    m_80 = bDeleteSave == 0;
    return DeleteFileA(FUN_140cc2a00(FUN_1412755f0(), FUN_14194b8a0()));
}
MS2_REPLACE_METHOD(0x141948B30, UIGroupMessenger, vfunc_84, 219, 0xD2B9BC23);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x141948C20, UIGroupMessenger, OnLoadComplete, 783, 0xCFF786F7);

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
MS2_REPLACE_METHOD(0x141948F40, UIGroupMessenger, vfunc_43, 211, 0x36AB4734);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x141949020, UIGroupMessenger, vfunc_13, 130, 0x3D622FE2);

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
MS2_REPLACE_METHOD(0x1419490B0, UIGroupMessenger, vfunc_15, 115, 0x265CF2CC);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x141949640, UIGroupMessenger, vfunc_45, 686, 0xE24B8EBC);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194A320, UIGroupMessenger, FUN_14194a320, 20, 0x19CBB9B4);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x14194a340
void UIGroupMessenger::FUN_14194a340(int nKind, const CStringW& strName, const CStringW& strOther)
{
    FUN_14194bde0();
    FUN_14194a650(nKind, strName, FUN_140632a60(0x80e, strName, strOther));
}
MS2_REPLACE_METHOD(0x14194A340, UIGroupMessenger, FUN_14194a340, 109, 0xF1D02319);

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
MS2_REPLACE_METHOD(0x14194A3C0, UIGroupMessenger, FUN_14194a3c0, 252, 0xF0BC3812);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x14194a4d0
void UIGroupMessenger::FUN_14194a4d0(int nKind, const CStringW& strName)
{
    FUN_14194bde0();
    FUN_14194a650(nKind, strName, FUN_14052bd00(0x811, strName));
}
MS2_REPLACE_METHOD(0x14194A4D0, UIGroupMessenger, FUN_14194a4d0, 99, 0xBA001AB9);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x14194a540
void UIGroupMessenger::FUN_14194a540(int nKind, const CStringW& strName)
{
    FUN_14194bde0();
    FUN_14194a650(nKind, strName, FUN_14052bd00(0x812, strName));
}
MS2_REPLACE_METHOD(0x14194A540, UIGroupMessenger, FUN_14194a540, 99, 0x5DE0CDB3);

// @0x14194a5b0
void UIGroupMessenger::FUN_14194a5b0(int nKind, const CStringW& strName, const CStringW& strMsg)
{
    FUN_14194d3d0(nKind, strName, strMsg, 0);
    if (FUN_141482e80()->m_pBrowser != 0)
        FUN_141482e80()->m_pBrowser->FUN_141953810(nKind, strName, strMsg, 0, vfunc_64());
}
MS2_REPLACE_METHOD(0x14194A5B0, UIGroupMessenger, FUN_14194a5b0, 139, 0x816186C3);

// @0x14194a650
void UIGroupMessenger::FUN_14194a650(int nKind, const CStringW& strName, const CStringW& strMsg)
{
    FUN_14194d3d0(nKind, strName, strMsg, 1);
    if (FUN_141482e80()->m_pBrowser != 0)
        FUN_141482e80()->m_pBrowser->FUN_141953810(nKind, strName, strMsg, 1, vfunc_64());
}
MS2_REPLACE_METHOD(0x14194A650, UIGroupMessenger, FUN_14194a650, 139, 0xEFB6BE61);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194A6F0, UIGroupMessenger, FUN_14194a6f0, 564, 0x30740B48);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194A930, UIGroupMessenger, FUN_14194a930, 1055, 0x7996AA4B);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x14194ad60
void UIGroupMessenger::FUN_14194ad60()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("closeChatEmoticonPreview");
}
MS2_REPLACE_METHOD(0x14194AD60, UIGroupMessenger, FUN_14194ad60, 110, 0xF5CDBC08);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194ADE0, UIGroupMessenger, FUN_14194ade0, 460, 0x5BD64367);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194AFC0, UIGroupMessenger, FUN_14194afc0, 446, 0xADC3693B);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194B190, UIGroupMessenger, FUN_14194b190, 446, 0x0BB5667B);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD_VIA(0x14194B360, UIGroupMessenger, UIUGCEventListener, vfunc_ugc_1, 204, 0x3AB617C1);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194B440, UIGroupMessenger, FUN_14194b440, 951, 0xC1F13251);

// @0x14194b800
void UIGroupMessenger::vfunc_85()
{
    FUN_141482e80()->FUN_141482c80(m_strName);
}
MS2_REPLACE_METHOD(0x14194B800, UIGroupMessenger, vfunc_85, 92, 0xF2FB97DC);

// @0x14194b870
void UIGroupMessenger::vfunc_86()
{
}
MS2_REPLACE_METHOD(0x14194B870, UIGroupMessenger, vfunc_86, 6, 0xA9AF6E37);

// @0x14194b880
int UIGroupMessenger::FUN_14194b880()
{
    return m_bUserList;
}
MS2_REPLACE_METHOD(0x14194B880, UIGroupMessenger, FUN_14194b880, 17, 0x874475EA);

// @0x14194b8a0
CString UIGroupMessenger::FUN_14194b8a0()
{
    CString strFile;
    strFile.Format("%s%d.xml", (const char*)vfunc_1(), m_nIndex);
    return strFile;
}
MS2_REPLACE_METHOD(0x14194B8A0, UIGroupMessenger, FUN_14194b8a0, 183, 0xCC64DC7C);

// @0x14194b960
CStringW UIGroupMessenger::FUN_14194b960()
{
    return m_strName;
}
MS2_REPLACE_METHOD(0x14194B960, UIGroupMessenger, FUN_14194b960, 68, 0x0AB7D61B);

// @0x14194b9b0
unsigned UIGroupMessenger::FUN_14194b9b0()
{
    return m_nGroupId;
}
MS2_REPLACE_METHOD(0x14194B9B0, UIGroupMessenger, FUN_14194b9b0, 17, 0xABC1DB6D);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x14194b9d0
int UIGroupMessenger::FUN_14194b9d0(__int64 nCharacterId)
{
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FUN_14137e630(m_nGroupId);
    if (spChat.get() && spChat->FUN_14137b410(nCharacterId))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14194B9D0, UIGroupMessenger, FUN_14194b9d0, 168, 0x604A3AB2);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194BA80, UIGroupMessenger, FUN_14194ba80, 481, 0xE77E4AA1);

// @0x14194bc70
void UIGroupMessenger::FUN_14194bc70(CStringW strName)
{
    m_strName = strName;
}
MS2_REPLACE_METHOD(0x14194BC70, UIGroupMessenger, FUN_14194bc70, 65, 0x6116EF81);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194BCC0, UIGroupMessenger, FUN_14194bcc0, 270, 0x53094138);

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
MS2_REPLACE_METHOD(0x14194BDE0, UIGroupMessenger, FUN_14194bde0, 627, 0xFCF12C7A);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194C6D0, UIGroupMessenger, FUN_14194c6d0, 331, 0xF9EA75FE);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194C830, UIGroupMessenger, FUN_14194c830, 884, 0x4FB1EAAB);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194CBB0, UIGroupMessenger, FUN_14194cbb0, 322, 0x0B436CC5);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194CD00, UIGroupMessenger, FUN_14194cd00, 314, 0x168DA538);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194CE40, UIGroupMessenger, FUN_14194ce40, 696, 0xB730CB0A);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194D100, UIGroupMessenger, FUN_14194d100, 701, 0x77104F6D);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194D6F0, UIGroupMessenger, FUN_14194d6f0, 498, 0x612545BC);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194D8F0, UIGroupMessenger, FUN_14194d8f0, 299, 0xBD408FB8);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
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
MS2_REPLACE_METHOD(0x14194DA30, UIGroupMessenger, FUN_14194da30, 189, 0xD3318D3F);

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

// @0x14194f120
int UIGroupMessenger::vfunc_48()
{
    return 0x4e94;
}
MS2_REPLACE_METHOD(0x14194F120, UIGroupMessenger, vfunc_48, 11, 0xF4D94525);

// ---- the tray's views ----

// The message box record: the group list box's choices and its dropdown's text.
class Unk_GrmBox : public CMsgBoxData
{
public:
    CStringW FUN_141a02d00() const;                                 // the text the box was opened with
    void FUN_141a02b00(const CStringW& strText, ATL::CAtlList<CStringW>& choices);   // the dropdown entries
};
class Unk_GrmDropdown : public ASDropdownMenu
{
public:
    CStringW FUN_1422dfe00();                                       // the selected label
};
// The item rarity colours.
class Unk_GrmRarityColors
{
public:
    unsigned FUN_1405569f0(int nRarity);
};
Unk_GrmRarityColors* FUN_140281980();
MS2Ptr<CMsgBoxData> FUN_14151f820();                                // the shown message box
CStringW FUN_1409eec40(int nStringId);
BlindManager* FUN_1409c1730();
__int64 FUN_140869440();                                            // the server time (epoch seconds)
bool FUN_140d2c080(CStringW strText, ATL::CAtlList<CStringW>& links, CStringW strBegin, CStringW strEnd);
__int64 FUN_140d2caf0(const CStringW& strLink);                     // an item link's uid
CStringW FUN_14183e930(const CStringW& strText, int nColor);        // colours a text
void FUN_141484270(TalkLog* pLog);                                  // marks a line read
int FUN_141484290(TalkLog* pLog);                                   // a line is unread
extern int DAT_143ab2864;

// ---- UIGroupMessengerBrowser ----

// @0x141950770
UIGroupMessengerBrowser::UIGroupMessengerBrowser()
    : m_fOffsetX(0), m_fOffsetY(-300.0f), m_nAlignType(7), m_items(17, 0.75f, 0.25f, 2.25f, 10),
      m_windows(17, 0.75f, 0.25f, 2.25f, 10), m_pending(10), m_logs(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_80 = 1;
    m_88 = 1;
    FUN_141482e80()->m_pBrowser = this;
    FUN_141925e70(0, 1);
}

// @0x141950910
UIGroupMessengerBrowser::~UIGroupMessengerBrowser()
{
    FUN_141482e80()->m_pBrowser = 0;
}

// @0x1419509c0
CString UIGroupMessengerBrowser::vfunc_1()
{
    return "GroupMessengerBrowser";
}
MS2_REPLACE_METHOD(0x1419509C0, UIGroupMessengerBrowser, vfunc_1, 61, 0xA7FDB2D8);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141950a10
void UIGroupMessengerBrowser::vfunc_67()
{
    UIDialog::vfunc_67();
    ATL::CAtlArray<MS2Ptr<UIGroupMessenger> > windows;
    POSITION pos = m_windows.GetStartPosition();
    while (pos != 0)
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0)
            windows.Add(MS2Ptr<UIGroupMessenger>(pWindow));
        m_windows.GetNext(pos);
    }
    m_windows.RemoveAll();
    for (unsigned i = 0; i < windows.GetCount(); i++)
        windows[i]->vfunc_67();
}
MS2_REPLACE_METHOD(0x141950A10, UIGroupMessengerBrowser, vfunc_67, 337, 0x85A4A307);

// @0x141950b70
int UIGroupMessengerBrowser::vfunc_53(void* pCfg)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        FUN_141926620(&m_nAlignType, &m_fOffsetX, &m_fOffsetY);
        FUN_140873e30(pCfg, "offsetX", m_fOffsetX);
        FUN_140873e30(pCfg, "offsetY", m_fOffsetY);
        FUN_140873ca0(pCfg, "alignType", m_nAlignType);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141950B70, UIGroupMessengerBrowser, vfunc_53, 230, 0xC1FBF5E7);

// @0x141950c60
int UIGroupMessengerBrowser::vfunc_54(void* pCfg)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        FUN_140873360(pCfg, "offsetX", &m_fOffsetX);
        FUN_140873360(pCfg, "offsetY", &m_fOffsetY);
        FUN_1408731e0(pCfg, "alignType", m_nAlignType);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141950C60, UIGroupMessengerBrowser, vfunc_54, 179, 0x3A420653);

// @0x141950d20
void UIGroupMessengerBrowser::OnLoadInit()
{
    UIObject::OnLoadInit();
    FUN_141952be0();
    FUN_141952530();
}
MS2_REPLACE_METHOD(0x141950D20, UIGroupMessengerBrowser, OnLoadInit, 44, 0xE7A007D2);

// @0x141950d60
void UIGroupMessengerBrowser::vfunc_43()
{
    if (m_60 != 0)
    {
        m_nAlignType = 7;
        m_fOffsetX = 0;
        m_fOffsetY = -300.0f;
    }
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        pDialog->vfunc_2(m_nAlignType, (int)m_fOffsetX, (int)m_fOffsetY);
        FUN_141926620(&m_nAlignType, &m_fOffsetX, &m_fOffsetY);
    }
}
MS2_REPLACE_METHOD(0x141950D60, UIGroupMessengerBrowser, vfunc_43, 259, 0xF88D137F);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141950e70
int UIGroupMessengerBrowser::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg))
        return 1;
    if (pMsg->FUN_1422e4520() == 0x7d1)
    {
        CStringW strTag = pMsg->FUN_1422b8f40();
        int nResult = pMsg->FUN_1422b8a10();
        Scaleform::GFx::Value root = static_cast<Unk_GrmMsg*>(pMsg)->FUN_1422b9260();
        if (strTag == s_strGroupList)
        {
            bool bDone = false;
            if (nResult == 0)
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_14151f820();
                if (spBox.get())
                {
                    CStringW strText = static_cast<Unk_GrmBox*>(spBox.operator->())->FUN_141a02d00();
                    ASObj box(root, 2);
                    MS2Ptr<ASDropdownMenu> spGroups = box.FUN_140bbe700("m_dropdown");
                    if (spGroups.get())
                    {
                        UIGroupMessenger* pWindow =
                            FUN_141952fc0(static_cast<Unk_GrmDropdown*>(spGroups.operator->())->FUN_1422dfe00());
                        if (pWindow == 0)
                        {
                            FUN_14151f200();
                            CGroupChatManager::GetInstance()->Create(strText);
                        }
                        else
                        {
                            FUN_14151f200();
                            CGroupChatManager::GetInstance()->Invite(pWindow->FUN_14194b9b0(), strText);
                        }
                        bDone = true;
                    }
                }
            }
            if (!bDone)
                FUN_14151f200();
        }
    }
    return 0;
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141951180
int UIGroupMessengerBrowser::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnCreateDefaultGroupMessenger", szMethod) == 0)
    {
        CGroupChatManager::GetInstance()->Create(L"");
        return 1;
    }
    if (_stricmp("OnToggleDialog", szMethod) == 0)
    {
        ASData args;
        if (args.FUN_1422b9620(pArgs, nArgs))
            FUN_141953240(args.FUN_1422b8f40());
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141951180, UIGroupMessengerBrowser, vfunc_28, 342, 0x67129DB4);

// @0x1419512f0
void UIGroupMessengerBrowser::vfunc_80(void* pPacket)
{
    Unk_BlockList result(*static_cast<CInPacket*>(pPacket));
    Unk_BlockEntry entry;
    if (result.Find("MessengerName", entry) == 1)
    {
        if (entry.m_nFlags == 0)
        {
            UIGroupMessenger* pWindow = FUN_141952f20(result.GetMode());
            if (pWindow != 0)
            {
                pWindow->FUN_14194bc70(entry.m_strName);
                pWindow->FUN_14194bde0();
            }
        }
        else
        {
            FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, L"");
        }
    }
}
MS2_REPLACE_METHOD(0x1419512F0, UIGroupMessengerBrowser, vfunc_80, 377, 0x139CC221);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141951470
void UIGroupMessengerBrowser::vfunc_15()
{
    if (m_68 == 0 && m_4c != 0)
    {
        UISwfEntity::vfunc_15();
        if (!m_pending.IsEmpty())
        {
            POSITION pos = m_pending.GetHeadPosition();
            while (pos != 0)
            {
                TalkLog& log = m_pending.GetNext(pos);
                CStringW strMsg = FUN_141953b10(log.m_strName);
                UIGroupMessenger* pWindow = FUN_141952f20(log.m_nKind);
                if (pWindow != 0)
                {
                    pWindow->FUN_14194a5b0(log.m_nKind, log.m_strMsg, strMsg);
                    if (pWindow->vfunc_64())
                        FUN_141952530();
                }
            }
            m_pending.RemoveAll();
        }
    }
}
MS2_REPLACE_METHOD(0x141951470, UIGroupMessengerBrowser, vfunc_15, 323, 0x51F96ABA);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x1419515c0
void UIGroupMessengerBrowser::FUN_1419515c0(int nGroupId)
{
    m_logs.SetAt(nGroupId, MS2Ptr<TalkLogList>(new TalkLogList()));
    FUN_141952d80(nGroupId, 1, 0);
    UIGroupMessenger* pWindow = FUN_141952f20(nGroupId);
    if (pWindow != 0)
        FUN_141482e80()->FUN_141482c80(pWindow->FUN_14194b960());
    FUN_141276180(s_strButtonClick, "");
}

// @0x141951720
void UIGroupMessengerBrowser::FUN_141951720(int nGroupId, const CStringW& strName, const CStringW& strText)
{
    UIGroupMessenger* pWindow = FUN_141952f20(nGroupId);
    if (pWindow != 0)
        pWindow->FUN_14194a320(nGroupId, strName, strText);
    UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
    if (pInvite != 0)
        pInvite->FUN_14199fd10(nGroupId, strName, strText);
}
MS2_REPLACE_METHOD(0x141951720, UIGroupMessengerBrowser, FUN_141951720, 126, 0x0701CC9B);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x1419517b0
void UIGroupMessengerBrowser::FUN_1419517b0(int nGroupId, const CStringW& strName, const CStringW& strOther)
{
    m_logs.SetAt(nGroupId, MS2Ptr<TalkLogList>(new TalkLogList()));
    FUN_141952d80(nGroupId, 1, 1);
    FUN_141276180(s_strSystemGroupChat, "");
    FUN_1412751f0(FUN_14052bd00(0x80f, strName), 3, 1);
    UIGroupMessenger* pWindow = FUN_141952f20(nGroupId);
    if (pWindow != 0)
    {
        pWindow->FUN_14194a650(nGroupId, strName, FUN_140632a60(0x80e, strName, strOther));
        if (pWindow->vfunc_64())
            FUN_141952530();
    }
}

// @0x1419519a0
void UIGroupMessengerBrowser::FUN_1419519a0(int nGroupId)
{
    m_logs.RemoveKey(nGroupId);
    FUN_1419532d0(nGroupId);
}
MS2_REPLACE_METHOD(0x1419519A0, UIGroupMessengerBrowser, FUN_1419519a0, 55, 0x80CDBA28);

// @0x1419519e0
void UIGroupMessengerBrowser::FUN_1419519e0(int nGroupId, const CStringW& strName, const CStringW& strOther)
{
    UIGroupMessenger* pWindow = FUN_141952f20(nGroupId);
    if (pWindow != 0)
        pWindow->FUN_14194a340(nGroupId, strName, strOther);
    UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
    if (pInvite != 0)
        pInvite->FUN_14199fd60(nGroupId, strName, strOther);
}
MS2_REPLACE_METHOD(0x1419519E0, UIGroupMessengerBrowser, FUN_1419519e0, 126, 0xC503682C);

// @0x141951a70
void UIGroupMessengerBrowser::FUN_141951a70(int nGroupId, const CStringW& strName, int nMode)
{
    UIGroupMessenger* pWindow = FUN_141952f20(nGroupId);
    if (pWindow != 0)
        pWindow->FUN_14194a3c0(nGroupId, strName, nMode);
    UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
    if (pInvite != 0)
        pInvite->FUN_14199fdb0(nGroupId, strName);
}
MS2_REPLACE_METHOD(0x141951A70, UIGroupMessengerBrowser, FUN_141951a70, 121, 0x1BF01CE1);

// @0x141951af0
void UIGroupMessengerBrowser::FUN_141951af0(int nGroupId, const CStringW& strName)
{
    UIGroupMessenger* pWindow = FUN_141952f20(nGroupId);
    if (pWindow != 0)
        pWindow->FUN_14194a4d0(nGroupId, strName);
    UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
    if (pInvite != 0)
        pInvite->FUN_14199fdf0(nGroupId, strName);
}
MS2_REPLACE_METHOD(0x141951AF0, UIGroupMessengerBrowser, FUN_141951af0, 111, 0xCDEE56EC);

// @0x141951b70
void UIGroupMessengerBrowser::FUN_141951b70(int nGroupId, const CStringW& strName)
{
    UIGroupMessenger* pWindow = FUN_141952f20(nGroupId);
    if (pWindow != 0)
        pWindow->FUN_14194a540(nGroupId, strName);
    UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
    if (pInvite != 0)
        pInvite->FUN_14199fe30(nGroupId, strName);
}
MS2_REPLACE_METHOD(0x141951B70, UIGroupMessengerBrowser, FUN_141951b70, 111, 0x08E085A3);

// @0x141951bf0
void UIGroupMessengerBrowser::FUN_141951bf0(int nGroupId, const CStringW& strName, const CStringW& strMsg)
{
    UIGroupMessenger* pWindow = FUN_141952f20(nGroupId);
    if (pWindow != 0)
        pWindow->FUN_14194a650(nGroupId, strName, strMsg);
}
MS2_REPLACE_METHOD(0x141951BF0, UIGroupMessengerBrowser, FUN_141951bf0, 79, 0xBE8B028E);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141951c50
void UIGroupMessengerBrowser::FUN_141951c50(int nGroupId, const CStringW& strName, const CStringW& strMsg)
{
    if (!FUN_1409c1730()->IsBlocked(0, strName))
    {
        TalkLog log(nGroupId, strMsg, strName);
        m_pending.AddTail(log);
    }
}
MS2_REPLACE_METHOD(0x141951C50, UIGroupMessengerBrowser, FUN_141951c50, 290, 0x441E5D4D);

// @0x141951d80
void UIGroupMessengerBrowser::FUN_141951d80(int nGroupId, const CStringW& strName, CInPacket* pPacket)
{
    unsigned nCount = pPacket->vfunc_o8_3();
    for (unsigned i = 0; i < nCount; i++)
    {
        __int64 nUid = pPacket->vfunc_o8_4();
        int nItemId = pPacket->vfunc_o8_3();
        int nRarity = pPacket->vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_140523c40(nItemId, nRarity, 0))
        {
            spItem->FUN_140526b30(DAT_143ab2864);
            spItem->FUN_140524eb0(*pPacket);
            m_items.SetAt(nUid, spItem);
        }
    }
}
MS2_REPLACE_METHOD(0x141951D80, UIGroupMessengerBrowser, FUN_141951d80, 490, 0xBC44B2DC);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141951f70
void UIGroupMessengerBrowser::FUN_141951f70(CStringW strText)
{
    int nCount = CGroupChatManager::GetInstance()->FUN_14137e820();
    if (nCount == 0)
    {
        CGroupChatManager::GetInstance()->Create(strText);
    }
    else if (nCount < 3)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x16, FUN_14028de60(0x81a), this, s_strGroupList);
        if (spBox.get())
        {
            ATL::CAtlList<CStringW> choices(10);
            choices.AddTail(FUN_14028de60(0x5d1));
            POSITION pos = m_windows.GetStartPosition();
            while (pos != 0)
            {
                UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
                if (pWindow != 0)
                    choices.AddTail(pWindow->FUN_14194b960());
                m_windows.GetNext(pos);
            }
            static_cast<Unk_GrmBox*>(spBox.operator->())->FUN_141a02b00(strText, choices);
            FUN_140d73c60(spBox);
        }
    }
    else
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x16, FUN_14028de60(0x81a), this, s_strGroupList);
        if (spBox.get())
        {
            ATL::CAtlList<CStringW> choices(10);
            choices.AddTail(FUN_14028de60(0x5d1));
            POSITION pos = m_windows.GetStartPosition();
            while (pos != 0)
            {
                UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
                if (pWindow != 0)
                    choices.AddTail(pWindow->FUN_14194b960());
                m_windows.GetNext(pos);
            }
            static_cast<Unk_GrmBox*>(spBox.operator->())->FUN_141a02b00(strText, choices);
            FUN_140d73c60(spBox);
        }
    }
}

// @0x1419524e0
void UIGroupMessengerBrowser::FUN_1419524e0()
{
    FUN_141482e80()->FUN_141482b70();
    m_logs.RemoveAll();
    m_pending.RemoveAll();
}
MS2_REPLACE_METHOD(0x1419524E0, UIGroupMessengerBrowser, FUN_1419524e0, 65, 0x08A06B2A);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952530
void UIGroupMessengerBrowser::FUN_141952530()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        ASArray windows(2);
        POSITION pos = m_windows.GetStartPosition();
        while (pos != 0)
        {
            UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
            if (pWindow != 0)
            {
                ASObj item(2);
                item.FUN_1409c0d20("number", FUN_141952a30(pWindow->FUN_14194b9b0()));
                item.FUN_1407cbb20("name", pWindow->FUN_14194b960());
                item.FUN_1407cb9c0("minimize", pWindow->vfunc_64());
                windows.FUN_1422bc050(item.FUN_1422bb870());
            }
            m_windows.GetNext(pos);
        }
        pDialog->Invoke("setData", windows.FUN_1422bb870());
    }
}
MS2_REPLACE_METHOD(0x141952530, UIGroupMessengerBrowser, FUN_141952530, 579, 0x8F780D0B);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952780
int UIGroupMessengerBrowser::FUN_141952780()
{
    int bMinimized = 0;
    POSITION pos = m_windows.GetStartPosition();
    while (pos != 0)
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0 && pWindow->vfunc_64() == 0)
        {
            bMinimized = 1;
            pWindow->vfunc_69();
        }
        m_windows.GetNext(pos);
    }
    return bMinimized;
}
MS2_REPLACE_METHOD(0x141952780, UIGroupMessengerBrowser, FUN_141952780, 178, 0x3F984899);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952840
int UIGroupMessengerBrowser::FUN_141952840()
{
    POSITION pos = m_windows.GetStartPosition();
    while (pos != 0)
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0 && pWindow->vfunc_55() == 0 && pWindow->vfunc_64() == 0)
            return 1;
        m_windows.GetNext(pos);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141952840, UIGroupMessengerBrowser, FUN_141952840, 176, 0xFA7309D9);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952900
unsigned UIGroupMessengerBrowser::FUN_141952900()
{
    for (unsigned i = 0; i < 3; i++)
    {
        if (m_windows.Lookup(i) == 0)
            return i;
    }
    return 3;
}
MS2_REPLACE_METHOD(0x141952900, UIGroupMessengerBrowser, FUN_141952900, 82, 0x18D7270B);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952960
void UIGroupMessengerBrowser::FUN_141952960(unsigned nGroupId)
{
    MS2Ptr<TalkLogList> spLog;
    if (m_logs.Lookup(nGroupId, spLog))
    {
        for (size_t i = 0; i < spLog->m_logs.GetCount(); i++)
            FUN_141484270(&spLog->m_logs[i]);
    }
}
MS2_REPLACE_METHOD(0x141952960, UIGroupMessengerBrowser, FUN_141952960, 200, 0x44FE2226);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952a30
int UIGroupMessengerBrowser::FUN_141952a30(unsigned nGroupId)
{
    int nCount = 0;
    MS2Ptr<TalkLogList> spLog;
    if (m_logs.Lookup(nGroupId, spLog))
    {
        for (size_t i = 0; i < spLog->m_logs.GetCount(); i++)
        {
            if (FUN_141484290(&spLog->m_logs[i]))
                nCount++;
        }
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x141952A30, UIGroupMessengerBrowser, FUN_141952a30, 238, 0xA2A41905);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952b30
int UIGroupMessengerBrowser::FUN_141952b30(unsigned nGroupId)
{
    int nCount = 0;
    MS2Ptr<TalkLogList> spLog;
    if (m_logs.Lookup(nGroupId, spLog))
    {
        nCount = (int)spLog->m_logs.GetCount();
        nCount -= FUN_141952a30(nGroupId);
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x141952B30, UIGroupMessengerBrowser, FUN_141952b30, 161, 0x0A7AEDC7);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952be0
int UIGroupMessengerBrowser::FUN_141952be0()
{
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ATL::CAtlList<unsigned> groups(10);
    CGroupChatManager::GetInstance()->FUN_14137e6f0(pPlayer->FUN_141656a80(), groups);
    POSITION pos = groups.GetHeadPosition();
    while (pos != 0)
    {
        unsigned nGroupId = groups.GetAt(pos);
        if (m_logs.Lookup(nGroupId) == 0)
            m_logs.SetAt(nGroupId, MS2Ptr<TalkLogList>(new TalkLogList()));
        FUN_141952d80(nGroupId, 0, 0);
        groups.GetNext(pos);
    }
    return 1;
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952d80
int UIGroupMessengerBrowser::FUN_141952d80(unsigned nGroupId, int bDeleteSave, int bMinimized)
{
    if (m_windows.GetCount() >= 3)
        return 0;
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FUN_14137e630(nGroupId);
    if (spChat == 0)
        return 0;
    FUN_1419532d0(nGroupId);
    unsigned nSlot = FUN_141952900();
    UIGroupMessenger* pWindow = new UIGroupMessenger(nGroupId, nSlot, bDeleteSave);
    if (pWindow->vfunc_65() == 0)
        return 0;
    if (bDeleteSave)
        pWindow->vfunc_63(bMinimized);
    m_windows.SetAt(nSlot, pWindow);
    return 1;
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952f20
UIGroupMessenger* UIGroupMessengerBrowser::FUN_141952f20(int nGroupId)
{
    POSITION pos = m_windows.GetStartPosition();
    while (pos != 0)
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0 && pWindow->FUN_14194b9b0() == nGroupId)
            return pWindow;
        m_windows.GetNext(pos);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141952F20, UIGroupMessengerBrowser, FUN_141952f20, 145, 0x408E827A);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141952fc0
UIGroupMessenger* UIGroupMessengerBrowser::FUN_141952fc0(const CStringW& strName)
{
    POSITION pos = m_windows.GetStartPosition();
    while (pos != 0)
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0)
        {
            if (pWindow->FUN_14194b960() == strName)
                return pWindow;
        }
        m_windows.GetNext(pos);
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141952FC0, UIGroupMessengerBrowser, FUN_141952fc0, 192, 0x8B12CA66);

// @0x141953090
void UIGroupMessengerBrowser::FUN_141953090(const CStringW& strName)
{
    UIGroupMessenger* pWindow = FUN_141952fc0(strName);
    if (pWindow != 0 && pWindow->FUN_14194b960() == strName)
    {
        pWindow->vfunc_63(0);
        FUN_141952530();
    }
}
MS2_REPLACE_METHOD(0x141953090, UIGroupMessengerBrowser, FUN_141953090, 202, 0xD6C75BFA);

// @0x141953160
void UIGroupMessengerBrowser::FUN_141953160(const CStringW& strName)
{
    UIGroupMessenger* pWindow = FUN_141952fc0(strName);
    if (pWindow != 0 && pWindow->FUN_14194b960() == strName)
    {
        pWindow->vfunc_63(1);
        FUN_141952530();
    }
}
MS2_REPLACE_METHOD(0x141953160, UIGroupMessengerBrowser, FUN_141953160, 205, 0xA33C9EAF);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141953240
void UIGroupMessengerBrowser::FUN_141953240(const CStringW& strName)
{
    UIGroupMessenger* pWindow = FUN_141952fc0(strName);
    if (pWindow != 0)
    {
        if (pWindow->vfunc_64() == 0)
            pWindow->vfunc_63(1);
        else
            pWindow->vfunc_63(0);
        FUN_141952530();
    }
}
MS2_REPLACE_METHOD(0x141953240, UIGroupMessengerBrowser, FUN_141953240, 127, 0x1F711C0A);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x1419532d0
void UIGroupMessengerBrowser::FUN_1419532d0(int nGroupId)
{
    MS2Ptr<UIGroupMessenger> spClosed(0);
    POSITION pos = m_windows.GetStartPosition();
    while (pos != 0)
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0 && pWindow->FUN_14194b9b0() == nGroupId)
        {
            spClosed.AssignRaw(pWindow);
            FUN_141482e80()->FUN_141482d30(pWindow->FUN_14194b960());
            pWindow->vfunc_84(1);
            m_windows.RemoveAtPos(pos);
            FUN_141952530();
            break;
        }
        m_windows.GetNext(pos);
    }
    if (spClosed.get())
        spClosed->vfunc_67();
}
MS2_REPLACE_METHOD(0x1419532D0, UIGroupMessengerBrowser, FUN_1419532d0, 383, 0x00E95FD5);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141953460
void UIGroupMessengerBrowser::FUN_141953460(const CStringW& strName)
{
    MS2Ptr<UIGroupMessenger> spClosed(0);
    POSITION pos = m_windows.GetStartPosition();
    while (pos != 0)
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0 && pWindow->FUN_14194b960() == strName)
        {
            spClosed.AssignRaw(pWindow);
            FUN_141482e80()->FUN_141482d30(pWindow->FUN_14194b960());
            pWindow->vfunc_84(1);
            m_windows.RemoveAtPos(pos);
            FUN_141952530();
            break;
        }
        m_windows.GetNext(pos);
    }
    if (spClosed.get())
        spClosed->vfunc_67();
}
MS2_REPLACE_METHOD(0x141953460, UIGroupMessengerBrowser, FUN_141953460, 500, 0x19831DD4);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141953660
void UIGroupMessengerBrowser::FUN_141953660(CStringW strText)
{
    POSITION pos = m_windows.GetStartPosition();
    while (pos != 0)
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0 && FUN_141482e80()->FUN_1414829e0() == pWindow->FUN_14194b960())
            pWindow->FUN_14194bcc0(strText);
        m_windows.GetNext(pos);
    }
}
MS2_REPLACE_METHOD(0x141953660, UIGroupMessengerBrowser, FUN_141953660, 412, 0x0972322B);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141953810
void UIGroupMessengerBrowser::FUN_141953810(int nGroupId, const CStringW& strName, const CStringW& strMsg, int bSystem,
                                            int bMinimized)
{
    MS2Ptr<TalkLogList> spLog;
    if (m_logs.Lookup(nGroupId, spLog))
    {
        spLog->m_logs.Add(TalkLog(nGroupId, strMsg, strName, bSystem, bMinimized));
        if (spLog->m_lines.size() > 50)
            spLog->m_lines.erase(spLog->m_lines.begin());
        CStringW strLine;
        CMsTime now(FUN_140869440());
        strLine.Format(L"[%2d:%2d:%2d][Group][%s] %s\n", now.GetHour(), now.GetMinute(), now.GetSecond(),
                       (const wchar_t*)strName, (const wchar_t*)strMsg);
        spLog->m_lines.push_back(strLine);
    }
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141953b10
CStringW UIGroupMessengerBrowser::FUN_141953b10(const CStringW& strMsg)
{
    CStringW strHtml(strMsg);
    ATL::CAtlList<CStringW> links(10);
    if (!FUN_140d2c080(strHtml, links, L"<A HREF=", L"/A>"))
        return strMsg;
    POSITION pos = links.GetHeadPosition();
    while (pos != 0)
    {
        CStringW strLink(links.GetAt(pos));
        __int64 nUid = FUN_140d2caf0(strLink);
        int nColor = 0xffffff;
        MS2Ptr<CItem> spItem = FUN_141953df0(nUid);
        if (spItem.get())
            nColor = FUN_140281980()->FUN_1405569f0(spItem->FUN_140526bd0());
        CStringW strColored = FUN_14183e930(strLink, nColor);
        strHtml.Replace(strLink, strColored);
        links.GetNext(pos);
    }
    return strHtml;
}
MS2_REPLACE_METHOD(0x141953B10, UIGroupMessengerBrowser, FUN_141953b10, 719, 0x1FCCFF0C);

// @0x141953df0
MS2Ptr<CItem> UIGroupMessengerBrowser::FUN_141953df0(__int64 nUid)
{
    MS2Ptr<CItem> spItem;
    if (m_items.Lookup(nUid, spItem))
        return spItem;
    return MS2Ptr<CItem>(0);
}
MS2_REPLACE_METHOD(0x141953DF0, UIGroupMessengerBrowser, FUN_141953df0, 169, 0xB578D5C7);

// @0x141956220
int UIGroupMessengerBrowser::vfunc_48()
{
    return 0x4e93;
}
MS2_REPLACE_METHOD(0x141956220, UIGroupMessengerBrowser, vfunc_48, 11, 0xF77482E4);
