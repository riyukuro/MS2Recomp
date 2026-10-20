// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIMessenger / UIMessengerBrowser: the chat windows and
// their owner, see uimessenger.h.
// MS2-UNIT: client\ms2\uimessenger.cpp
// MS2-RANGE: 0x141a08af0-0x141a30f30 .text$mn
// MS2-RANGE: 0x140117620-0x140117c70 .text$di
// MS2-GUESS-LOOKALIKES
//
// Two original TUs: the window (0x141a08af0-0x141a20f80, members up to 0x141a17e20, then its container glue) and the
// browser (0x141a20f90-), each with its own COMDAT copies of the glue.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimessenger.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "uimessenger.h"

#include <list>
#include <utility>
#include <vector>

#include "ms2/ms2format.h"
#include "ms2/client/ms2/chatemoticoncli.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/messengerdata.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/dungeonrecordcli.h"
#include "ms2/client/ms2/uicashshopdialog.h"
#include "ms2/client/ms2/uidungeonroomdialog.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/placeholder/cashshopref.h"
#include "ms2/placeholder/iclientplatform.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/tusercommandinfo.h"
#include "ms2/client/ms2/uichatemoticondialog.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/commonfiles/chatemoticontable.h"
#include "ms2/guess/usercommandcli.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/notifygameeventchanged.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextarea.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

using namespace MessengerData;

// ---- statics of the window TU (.text$di, in init order) ----
static MS2Ptr<CCacheData> s_spDebugCommandCache = 0;               // 0x143af3f70 DebugChatCommand.xml
// The debug commands keyed by their lower-case name and search tags (one entry per key).
static std::vector<std::pair<CStringW, MS2Ptr<TDebugCommand> > > s_debugCommands;   // 0x143af3f80
static CString s_strColor = "color";                               // 0x143af3fb0
static CString s_strFrame = "frame";                               // 0x143af3f98
static CString s_strIconPath = "iconPath";                         // 0x143af3fa0
static CString s_strLabel = "label";                               // 0x143af3fa8
static CString s_strOriginPrice = "originPrice";                   // 0x143af3fc0
static CString s_strPrice = "price";                               // 0x143af3fb8
static CString s_strMarketSortNames[] = {"None", "Buy", "PriceLow", "PriceHigh", "Create", "ChartOrder", "BuyTotal",
                                         "EnumEnd"};               // 0x143af3f30
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unkTab(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInputController;     // 0x143af3ee0
static CString s_strJobCode = "jobCode";                           // 0x143af3f28
static CString s_strSortValue = "sortValue";                       // 0x143af3ed8
static CString s_strTabIndex = "tabIndex";                         // 0x143af3e88

// ---- unit-local views of exe types ----

// The movie root of every dialog is an ASDialog.
class ASDialog : public ASUIComponent
{
public:
    int FUN_1422c1340();                                            // the width
    int FUN_1422c13b0();                                            // the height
    void FUN_1422c7490(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int n);   // "moved"
    void FUN_1422deb40(bool bActive);                               // the active frame
    void FUN_1407cb9c0(const char* szName, int n);                  // set an int member
};

// "m_subject": the chat type drop-down.
class ASDropdownMenu : public ASUIComponent
{
public:
    unsigned FUN_1422df620();                                       // the entry count
    void FUN_1422df690(int nIndex);                                 // select an entry
    int FUN_1422df6c0();                                            // the selected entry
};

// The messenger settings element (messengerdata.cpp's view): children by name.
class Unk_MdXml
{
public:
    Unk_MdXml* FUN_140872ec0(const char* szName, bool bCreate);    // child element (created on request)
};

// The key state.
class Unk_MsgKeys
{
public:
    bool FUN_14116d840();                                           // escape pressed
    bool FUN_14116d9c0(int nKey, int a, int b);                     // key pressed
    bool FUN_14116dd30(int nKeyCode, int a, int b);                 // bound key pressed
    bool FUN_14116d720();                                           // the ":alias:" emoticons are on
    bool FUN_14116d7a0(int nKey);                                   // a key is held
};
Unk_MsgKeys* FUN_14025e7c0();

// The own field state.
class Unk_MsgField
{
public:
    int FUN_141adbb00();
    void FUN_141adc530(int nUiId);                                  // opens a UI
    int FUN_141adc940(int nUiId);                                   // the UI can open
};
Unk_MsgField* FUN_1403ed2b0();

// The notify manager.
class Unk_MsgNotices
{
public:
    void FUN_140da4e40(CStringW strName, Delegate<void(NotifyObject*)> cb);   // subscribe
    void FUN_140da4eb0(CStringW strName, Delegate<void(NotifyObject*)> cb);   // unsubscribe
};
Unk_MsgNotices* FUN_140939a10();

// The data file loader.
class Unk_MsgFiles { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* szPath, int a, bool b, bool c); };
Unk_MsgFiles* FUN_140166420();

CString FUN_14071a6f0(const CString& strFile);                      // the data path of a file
CString FUN_14016a600(const wchar_t* psz, int n);                   // wide -> narrow
CString FUN_1412755f0();                                            // the UI settings directory
CString FUN_140cc2a00(const CString& strRoot, const CString& strFile);   // path join
void FUN_14086ddc0(TiXmlDocument* pDoc);                            // Clear
void* FUN_14081b310(TiXmlDocument* pDoc);                           // RootElement
void* FUN_14086e090(TiXmlDocument* pDoc, class TiXmlElement* pChild);   // LinkEndChild
bool FUN_1408710c0(TiXmlDocument* pDoc, const char* szPath);        // SaveFile
void* FUN_140165cf0(TiXmlDocument* pDoc, const char* szName);       // FirstChildElement
void* FUN_140165cf0(void* pNode, const char* szName);               // FirstChildElement
void* FUN_140168650(void* pNode, const char* szName);               // NextSiblingElement
void FUN_140873e30(void* pCfg, const char* szName, float f);
void FUN_140873ca0(void* pCfg, const char* szName, int n);
int FUN_140873360(void* pCfg, const char* szName, float* pf);
int FUN_1408731e0(void* pCfg, const char* szName, int* pn);
int FUN_140873420(void* pCfg, const char* szName, CStringW* pstr);
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>& arr, const wchar_t* szDelim);   // split
void FUN_140988d60(CStringW& str, std::vector<CStringW>& arr, const wchar_t* szDelim);   // split
bool FUN_140841300(const CStringW& str, const char* sz);           // equals a narrow string
bool FUN_140d2aa60(CStringW& strHtml);                              // the input has item links
CStringW FUN_140cde1f0(const wchar_t* szFormat, const unsigned& nId, const int& nVSpace, const CStringW& strSize);
int FUN_1418fd740(__int64 nParam, __int64 nId, int nType);          // uicommon.cpp: reports a user
void FUN_1418fdfd0(__int64 nKey);                                   // uicommon.cpp: blocks a user

// The emoticon tables and the per-user emoticon state.
class Unk_MsgUser
{
public:
    MS2Ptr<DungeonRecordManagerCli> FUN_140d9f2c0();                // the dungeon records
    int FUN_140d9f880(int nRoomId);                                 // the room's entry state (10+: refused)
    MS2Ptr<CChatEmoticonCli> FUN_140d9f8f0();
};
Unk_MsgUser* FUN_140931510();
CChatEmoticonTable* FUN_1409eecd0();

// The world and its local player (the selected super world chat item).
class Unk_MsgWorld { public: MyPC* FUN_141bd0cc0(); };
Unk_MsgWorld* FUN_1403ed2d0();
extern Unk_Inventory DAT_143ab2a90;                                 // the player's inventory

// The messenger state (messengerdata.cpp's Unk_MdState): the current window name and the browser (+0x48).
class Unk_MsgState
{
public:
    CStringW FUN_1414829e0();                                       // the current window name
    void FUN_141482c80(CStringW strName);                           // make a window the current one
    char m_pad_00[0x38];
    int m_nNewTabMode;                                              // +0x38 why the new tab dialog opened (1 menu, 2 button)
    UIMessenger* m_pNewTabWindow;                                   // +0x40 the window asking for a new tab
    UIMessengerBrowser* m_pBrowser;                                 // +0x48
};
Unk_MsgState* FUN_141482e80();
int FUN_141482f00(int nChannel);                                    // the line type of a chat channel

// The chat line request (usercommandcli.cpp's Unk_CommandChat).
struct Unk_MsgChat
{
    Unk_MsgChat();                                                  // 0x140acd570
    ~Unk_MsgChat();                                                 // 0x140acd770
    int m_nState;                                                   // +0x00
    int m_nType;                                                    // +0x04
    CStringW m_strText;                                             // +0x08
    CStringW m_strTarget;                                           // +0x10
    __int64 m_nValue;                                               // +0x18
};
void FUN_141276f80(const Unk_MsgChat& chat);                       // sends a chat line

// The search keywords of an emotion (uidynamicactiondialog.cpp's Unk_EmotionKeywords).
class Unk_MsgEmotionKeywords : public CPtred
{
public:
    char m_pad_18[0x34 - 0x18];
    int m_nAction;                                                  // +0x34
    ATL::CAtlArray<CStringW> m_keywords;                            // +0x38
};
MS2Ptr<Unk_MsgEmotionKeywords> FUN_140347050(int nEmotionId);

class Unk_MsgStrings { public: CStringW FUN_1422af5f0(int nId); };   // the UI string table
Unk_MsgStrings* FUN_14025e7a0();
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1409e97f0(int nStringId, const int& n);                // a string with one number
CStringW FUN_141842320(const CStringW& strText);                    // text to html
void FUN_140d2c650(CStringW& strHtml);                              // encodes the item links
void FUN_140d2c2a0(MS2Ptr<ASTextInput> spInput, ATL::CAtlArray<CStringW>& history);   // the input history keys
void* FUN_1422bb8b0(int nMovieId);                                  // the movie of a UI layer
void FUN_14256e3e0(void* pMovie, Scaleform::GFx::Value* pValue);   // movie->CreateArray
CStringW FUN_140298ea0(CStringW strKey);                            // the string of a key
CStringW FUN_1408f71a0(CStringW strKey, const CStringW& a, const CStringW& b);
CStringW FUN_140bfa7f0(CStringW strKey, const CStringW& a, const int& b);
CStringW FUN_1401e8510(const wchar_t* szFormat, const CStringW& a);  // StringFormat
CStringW FUN_140656190(const wchar_t* szFormat, const CStringW& a, const CStringW& b);
int FUN_140718200(const CStringW& str);                             // to int
void FUN_1412751f0(const CStringW& strText, int nA, int nB);        // a system message
void FUN_1412b9870(int nRoomId, int nState);                        // the room entry refusal message
MS2Ptr<CMsgBoxData> FUN_140d74230(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW strText);   // a yes/no box
CPartyManager* FUN_1409670d0();
DungeonRoomTable* FUN_14031c2a0();
UIDungeonRoomDialog* FUN_140961550(int nUiId);                      // Unk_GetUI<UIDungeonRoomDialog>
class Unk_MsgNames { public: CStringW FUN_141811980(int nKind, int nId); };   // names of ids
Unk_MsgNames* FUN_1401a9d70();
UIMessenger* FUN_141a184c0(CString strName);                       // Unk_GetUI<UIMessenger> by name

class TiXmlElement
{
public:
    TiXmlElement(const char* szValue);                              // 0x14086f2f0
private:
    char m_pad[0x90];
};

// ---- UIMessenger ----

// @0x141a08af0
UIMessenger::UIMessenger(UIMessengerBrowser* pBrowser, const TiXmlDocument& doc, CStringW strName, int bFirst)
    : m_178(0), m_bFirst(bFirst), m_bScrollEnd(0), m_fOffsetX(0), m_fOffsetY(0), m_nAlignType(7),
      m_nTabSelectedIndex(0), m_nTargetSelectedIndex(0), m_nHistoryIndex(-1), m_strName(strName), m_238(0), m_doc(doc),
      m_pBrowser(pBrowser)
{
    m_80 = 1;
    FUN_1422dc3b0(1);
    FUN_141925e70(0, 1);
}

// @0x141a08d60
UIMessenger::~UIMessenger()
{
}

// @0x141a08eb0
CString UIMessenger::vfunc_1()
{
    return "MessengerDialog";
}

// @0x141a08f00
int UIMessenger::vfunc_65()
{
    if (!UIDialog::vfunc_65())
        return 0;
    FUN_140939a10()->FUN_140da4e40(L"NotifyGameEventChanged",
                                   Delegate<void(NotifyObject*)>(this, &UIMessenger::FUN_141a0f550));
    FUN_140939a10()->FUN_140da4e40(L"NotifyChatEmoticonSelected",
                                   Delegate<void(NotifyObject*)>(this, &UIMessenger::FUN_141a0f5d0));
    return 1;
}

// @0x141a090d0
void UIMessenger::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_140939a10()->FUN_140da4eb0(L"NotifyGameEventChanged",
                                   Delegate<void(NotifyObject*)>(this, &UIMessenger::FUN_141a0f550));
    FUN_140939a10()->FUN_140da4eb0(L"NotifyChatEmoticonSelected",
                                   Delegate<void(NotifyObject*)>(this, &UIMessenger::FUN_141a0f5d0));
    m_inputHistory.RemoveAll();
    m_tabs.RemoveAll();
    m_textInput = 0;
    m_textOutput = 0;
    m_buttonBar = 0;
    m_subject = 0;
}

// @0x141a09320
int UIMessenger::vfunc_4()
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
    FUN_141a15970();
    if (!vfunc_53(pRoot))
        return 0;
    return FUN_1408710c0(&doc, FUN_140cc2a00(FUN_1412755f0(), FUN_14016a600(m_strName, 0)));
}

// @0x141a095d0
int UIMessenger::vfunc_5()
{
    if (!m_80)
        return 0;
    m_78 = 0;
    void* pNode = FUN_140165cf0(&m_doc, vfunc_1());
    if (pNode == 0)
    {
        TiXmlDocument doc;
        if (doc.FUN_140870fc0(FUN_140cc2a00(FUN_1412755f0(), FUN_14016a600(m_strName, 0)), 0))
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
        FUN_14086ddc0(&m_doc);
    }
    if (!m_78)
        vfunc_84();
    return m_78;
}

// @0x141a098b0
int UIMessenger::vfunc_53(void* pCfg)
{
    if (m_tabs.IsEmpty())
        return 0;
    if (m_30 == 0)
        return 0;
    FUN_141a0f180();
    FUN_140873ca0(pCfg, "width", static_cast<ASDialog*>(m_30.operator->())->FUN_1422c1340());
    FUN_140873ca0(pCfg, "height", static_cast<ASDialog*>(m_30.operator->())->FUN_1422c13b0());
    FUN_140873e30(pCfg, "offsetX", m_fOffsetX);
    FUN_140873e30(pCfg, "offsetY", m_fOffsetY);
    FUN_140873ca0(pCfg, "alignType", m_nAlignType);
    FUN_140873ca0(pCfg, "tabSelectedIndex", m_nTabSelectedIndex);
    FUN_140873ca0(pCfg, "targetSelectedIndex", m_nTargetSelectedIndex);
    for (size_t i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (spTab.get() != 0)
        {
            Unk_MdXml* pTab = static_cast<Unk_MdXml*>(pCfg)->FUN_140872ec0("Tab", false);
            if (pTab != 0 && !spTab->FUN_141482880(pTab))
                return 0;
        }
    }
    return 1;
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141a09af0
int UIMessenger::vfunc_54(void* pCfg)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        int nWidth = 0;
        int nHeight = 0;
        FUN_1408731e0(pCfg, "width", &nWidth);
        FUN_1408731e0(pCfg, "height", &nHeight);
        FUN_140873360(pCfg, "offsetX", &m_fOffsetX);
        FUN_140873360(pCfg, "offsetY", &m_fOffsetY);
        FUN_1408731e0(pCfg, "alignType", &m_nAlignType);
        FUN_1408731e0(pCfg, "tabSelectedIndex", &m_nTabSelectedIndex);
        FUN_1408731e0(pCfg, "targetSelectedIndex", &m_nTargetSelectedIndex);
        if (m_bFirst)
        {
            m_nTabSelectedIndex = 0;
            m_nTargetSelectedIndex = FUN_141a14110();
            m_bFirst = 0;
        }
        for (void* pNode = FUN_140165cf0(pCfg, "Tab"); pNode != 0; pNode = FUN_140168650(pNode, "Tab"))
        {
            TalkTab* pTab = new TalkTab;
            if (pTab != 0)
            {
                if (!pTab->FUN_1414827c0(static_cast<Unk_MdXml*>(pNode)))
                {
                    m_tabs.RemoveAll();
                    return 0;
                }
                if (!FUN_141a0e4d0(pTab))
                    return 0;
            }
        }
        FUN_141a13ac0();
        pDialog->FUN_1422c79e0(nWidth, nHeight);
    }
    return (int)m_tabs.GetCount();
}

// @0x141a09db0
int UIMessenger::vfunc_84()
{
    m_80 = 0;
    return DeleteFileA(FUN_140cc2a00(FUN_1412755f0(), FUN_14016a600(m_strName, 0)));
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141a09e90
void UIMessenger::OnLoadComplete()
{
    m_textInput = FUN_140e35bd0("m_textInput");
    m_textOutput = FUN_140c26f60("m_textOutput");
    m_buttonBar = FUN_140c02870("m_buttonBar");
    m_subject = FUN_140c28560("m_subject");
    m_chatEmoticonPreview = FUN_140ba7930("m_chatEmoticonPreview");
    m_textInput->FUN_1422e0920(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMessenger::FUN_141a0e940));
    UIDialog::OnLoadComplete();
    FUN_141923680(1);
    FUN_141a14dc0();
    if (m_textInput)
        m_textInput->FUN_1422e0d60(*Client::Constants::GetInstance()->MaxChatLength.Get());
    if (m_buttonBar)
    {
        m_buttonBar->FUN_1422c7630(1);
        m_buttonBar->FUN_1422e31e0(m_nTabSelectedIndex);
    }
    static_cast<ASDialog*>(m_30.operator->())->FUN_1422c7490(
        Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &UIMessenger::FUN_141a0f520), 0);
    FUN_141a13ac0();
    vfunc_4();
    m_bScrollEnd = 1;
    FUN_141a0d930();
    FUN_141a0e990();
}

// @0x141a0a3a0
void UIMessenger::vfunc_26()
{
    UIDialog::vfunc_26();
    m_2e0 = 0;
    m_2f0 = 0;
}

// @0x141a0a3f0
void UIMessenger::vfunc_43()
{
    if (m_60 == 0)
    {
        ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
        if (pDialog)
            pDialog->vfunc_2(m_nAlignType, (int)m_fOffsetX, (int)m_fOffsetY);
    }
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141a0a4a0
int UIMessenger::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (!FUN_141a12f30())
        return 0;
    if (!m_pBrowser->m_180)
        return 0;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
    {
        FUN_141a17700();
        return 1;
    }
    if (FUN_14025e7c0()->FUN_14116dd30(0x49405, 0, 0))
    {
        if (m_textInput && !m_textInput->FUN_1422c76c0())
        {
            m_textInput->FUN_1422c7630(1);
            FUN_141a17900(m_pBrowser->m_strWhisperTarget);
            return 1;
        }
        return 0;
    }
    if (FUN_14025e7c0()->FUN_14116d9c0(0x39, 0, 0))
    {
        if (FUN_1403ed2b0()->FUN_141adbb00())
        {
            FUN_141a14600();
            return 1;
        }
        return 0;
    }
    if (FUN_14025e7c0()->FUN_14116d840())
        return FUN_141a12260();
    if (m_textInput && m_textInput->FUN_1422c76c0() && FUN_14025e7c0()->FUN_14116d9c0(0x79, 0, 0))
    {
        FUN_141a13c20(1);
        return 1;
    }
    if (m_textInput && m_textInput->FUN_1422c76c0() && FUN_14025e7c0()->FUN_14116d9c0(0x7e, 0, 0))
    {
        FUN_141a13c20(0);
        return 1;
    }
    if (FUN_14025e7c0()->FUN_14116d9c0(0xf, 0, 0) && m_textInput)
    {
        if (!m_textInput->FUN_1422c76c0())
            return 0;
        if (!m_strLastWhisper.IsEmpty())
        {
            FUN_141a17830(m_strLastWhisper, 1);
            return 1;
        }
        FUN_141a14760();
        return 1;
    }
    return 0;
}

// @0x141a0a810
void UIMessenger::vfunc_15()
{
    if (m_bScrollEnd)
    {
        if (m_textOutput.get())
        {
            MS2Ptr<ASTextField> spField = m_textOutput->FUN_1422e1490();
            if (spField)
            {
                if (m_textOutput->FUN_1422e4620() != spField->FUN_1422c58b0())
                    m_textOutput->FUN_1422e4720();
            }
        }
        m_bScrollEnd = 0;
    }
}

// @0x141a0d880
void UIMessenger::FUN_141a0d880(bool bVisible)
{
    if (m_2e0.get())
        m_2e0->vfunc_4(bVisible);
    if (m_2f0.get())
        m_2f0->vfunc_4(bVisible);
}

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141a0d930
bool UIMessenger::FUN_141a0d930()
{
    if (!s_debugCommands.empty())
        return true;
    TiXmlDocument doc;
    CString strPath = FUN_14071a6f0("DebugChatCommand.xml");
    if (s_spDebugCommandCache == 0)
    {
        s_spDebugCommandCache.AssignRaw(new CCacheData);
        s_spDebugCommandCache->FUN_1401d1160(strPath);
    }
    if (!FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false))
        return false;
    void* pRoot = FUN_140165cf0(&doc, "ms2");
    if (pRoot == 0)
        return false;
    for (void* pSet = FUN_140165cf0(pRoot, "CommandSet"); pSet != 0; pSet = FUN_140168650(pSet, "CommandSet"))
    {
        CStringW strCmd;
        FUN_140873420(pSet, "cmd", &strCmd);
        if (strCmd.IsEmpty())
            continue;
        MS2Ptr<TDebugCommand> spCmd = new TDebugCommand;
        if (spCmd == 0)
            continue;
        FUN_140873420(pSet, "desc", &spCmd->m_strDesc);
        FUN_140873420(pSet, "arg", &spCmd->m_strArg);
        FUN_140873420(pSet, "ex", &spCmd->m_strEx);
        spCmd->m_strDesc.Replace(L"\\n", L"\n");
        spCmd->m_strEx.Replace(L"\\n", L"\n");
        spCmd->m_strArg.Replace(L"\\n", L"\n");
        CStringW strTags;
        FUN_140873420(pSet, "searchTag", &strTags);
        ATL::CAtlArray<CStringW> tags;
        if (!strTags.IsEmpty())
            FUN_14025a680(strTags, tags, L",");
        spCmd->m_strName = strCmd;
        s_debugCommands.push_back(std::pair<CStringW, MS2Ptr<TDebugCommand> >(strCmd.MakeLower(), spCmd));
        if (!tags.IsEmpty())
        {
            for (size_t i = 0; i < tags.GetCount(); i++)
                s_debugCommands.push_back(std::pair<CStringW, MS2Ptr<TDebugCommand> >(tags[i].MakeLower(), spCmd));
        }
    }
    return true;
}

// @0x141a0df10
int UIMessenger::FUN_141a0df10()
{
    if (s_spDebugCommandCache == 0)
        return 0;
    if (FUN_1401d1320(s_spDebugCommandCache.operator->()))
    {
        s_debugCommands.clear();
        FUN_141a0d930();
    }
    return 1;
}

// @0x141a0df70
CStringW UIMessenger::FUN_141a0df70()
{
    return m_strName;
}

// @0x141a0dfc0
CStringW UIMessenger::FUN_141a0dfc0()
{
    if (m_buttonBar)
        return m_buttonBar->FUN_1422e3790();
    return L"";
}

// @0x141a0e050
TalkTab* UIMessenger::FUN_141a0e050()
{
    if (m_tabs.GetCount() == 1)
        return m_tabs[0].get();
    return FUN_141a0e0f0(FUN_141a0dfc0());
}

// @0x141a0e0f0
TalkTab* UIMessenger::FUN_141a0e0f0(const CStringW& strName)
{
    for (unsigned i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (spTab)
        {
            if (spTab->m_strName == strName)
                return spTab;
        }
    }
    return 0;
}

// @0x141a0e1f0
int UIMessenger::FUN_141a0e1f0(int nIndex)
{
    if (m_buttonBar)
    {
        m_buttonBar->FUN_1422c7630(1);
        m_buttonBar->FUN_1422e31e0(nIndex);
        m_buttonBar->vfunc_24(1);
    }
    return 1;
}

// @0x141a0e2a0
int UIMessenger::FUN_141a0e2a0(const CStringW& strName)
{
    if (m_buttonBar)
    {
        m_buttonBar->FUN_1422c7630(1);
        m_buttonBar->FUN_1422e3590(strName);
        m_buttonBar->vfunc_24(1);
    }
    return 1;
}

// @0x141a0e350
int UIMessenger::FUN_141a0e350(const CStringW& strName)
{
    MS2Ptr<TalkTab> spTab = FUN_141a0e0f0(strName);
    if (!spTab)
        return 0;
    for (size_t i = 0; i < m_tabs.GetCount(); i++)
    {
        if (spTab == m_tabs[i].get())
        {
            m_tabs.RemoveAt(i, 1);
            break;
        }
    }
    if (m_buttonBar)
    {
        m_buttonBar->FUN_1422e3a70(strName);
        m_buttonBar->vfunc_24(1);
        FUN_141a13ac0();
    }
    return 1;
}

// @0x141a0e4d0
int UIMessenger::FUN_141a0e4d0(TalkTab* pTab)
{
    if (pTab == 0)
        return 0;
    if (FUN_141a13070(pTab->m_strName))
        return 0;
    m_tabs.Add(pTab);
    if (m_buttonBar)
    {
        ASObj item(2);
        item.FUN_1407cbb20("label", pTab->m_strName);
        item.FUN_1407cb9c0("close", pTab->m_nClose);
        item.FUN_1407cb9c0("detach", pTab->m_nDetach);
        m_buttonBar->FUN_1422e3460(item);
    }
    return 1;
}

// @0x141a0e650
int UIMessenger::FUN_141a0e650(TalkTab* pTab)
{
    if (pTab == 0)
        return 0;
    if (FUN_141a13070(pTab->m_strName))
        return 0;
    m_tabs.Add(pTab);
    if (m_buttonBar)
    {
        ASObj item(2);
        item.FUN_1407cbb20("label", pTab->m_strName);
        item.FUN_1407cb9c0("close", pTab->m_nClose);
        item.FUN_1407cb9c0("detach", pTab->m_nDetach);
        m_buttonBar->FUN_1422e3460(item);
        m_buttonBar->vfunc_24(1);
        FUN_141a13ac0();
    }
    return 1;
}

// @0x141a0e810
int UIMessenger::FUN_141a0e810(const CStringW& strName, int nClose, int nDetach, int nAdditive)
{
    MS2Ptr<TalkTab> spTab = new TalkTab(strName, nClose, nDetach, nAdditive);
    return FUN_141a0e650(spTab);
}

// @0x141a0e900
size_t UIMessenger::FUN_141a0e900(ATL::CAtlArray<MS2Ptr<TalkTab> >& tabs)
{
    tabs.Copy(m_tabs);
    return tabs.GetCount();
}

// @0x141a0e940
void UIMessenger::FUN_141a0e940(const Scaleform::GFx::FunctionHandler::Params& params)
{
    switch (FUN_141a14250())
    {
    case 0x18:
        FUN_141a13210();
        break;
    }
}

// @0x141a0e990
void UIMessenger::FUN_141a0e990()
{
    vfunc_97(FUN_141a0dfc0());
}

// @0x141a0e9f0
void UIMessenger::FUN_141a0e9f0(const CStringW& strOld, const CStringW& strNew)
{
    if (strOld == strNew)
        return;
    TalkTab* pTab = FUN_141a0e0f0(strOld);
    if (pTab == 0)
        return;
    if (m_buttonBar)
    {
        m_buttonBar->FUN_1422e3c70(strOld, strNew);
        m_buttonBar->vfunc_24(1);
    }
    pTab->m_strName = strNew;
}

// @0x141a0ead0
void UIMessenger::FUN_141a0ead0(unsigned nFontSize, CStringW& strHtml)
{
    for (unsigned i = 12; static_cast<int>(i) <= 18; ++i)
    {
        CStringW strFrom;
        strFrom.Format(L"size='%d'", i);
        CStringW strTo;
        strTo.Format(L"size='%d'", nFontSize);
        strHtml.Replace(strFrom, strTo);
    }
}

// @0x141a0ebb0
void UIMessenger::FUN_141a0ebb0(unsigned nAlpha)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("backgroundAlpha", nAlpha);
}

// @0x141a0ec30
void UIMessenger::FUN_141a0ec30(const CStringW& strText)
{
    if (m_textInput == 0)
        return;
    CStringW strCurrent = m_textInput->FUN_1422e0b00();
    if (strCurrent.GetLength() >= m_textInput->FUN_1422e0da0())
        return;
    CStringW strSpace(L" ");
    CStringW strHtml = m_textInput->FUN_1422e0c20();
    if (FUN_141a14ce0(strHtml + strText + strSpace, m_textInput->FUN_1422e0da0()))
    {
        m_textInput->FUN_1422e0bd0(strHtml + strText + strSpace);
        m_textInput->vfunc_24(1);
        int nLength = m_textInput->FUN_1422e0b00().GetLength();
        if (0 < nLength)
        {
            vfunc_78();
            m_textInput->FUN_1422e1500(nLength, nLength);
        }
        m_textInput->vfunc_24(1);
        m_inputHistory.Add(strText);
    }
}

// @0x141a0efa0
void UIMessenger::vfunc_85(int bActive)
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        pDialog->FUN_1422deb40(bActive != 0);
        pDialog->FUN_1422c6640(bActive != 0);
    }
}

// @0x141a0f040
int UIMessenger::vfunc_86(TalkTab* pExcept, const CStringW& strName)
{
    for (size_t i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (spTab.get() != 0 && !(spTab == pExcept))
        {
            if (spTab->FUN_141482940() == strName)
                return 0;
        }
    }
    return 1;
}

// @0x141a0f180
void UIMessenger::FUN_141a0f180()
{
    FUN_141926620(&m_nAlignType, &m_fOffsetX, &m_fOffsetY);
}

// @0x141a0f1d0
void UIMessenger::FUN_141a0f1d0(CStringW strText, CStringW strHtml, bool bHistory)
{
    CStringW strSend = strText;
    bool bLinks = FUN_140d2aa60(strHtml);
    if (bLinks)
        strSend = strHtml;
    if (strText.GetAt(0) == L'/')
    {
        if (FUN_141a10fd0(strText, strHtml, bLinks) && bHistory)
            m_pBrowser->FUN_141a25f70(strText, m_inputHistory);
        return;
    }
    int nType = FUN_141a144a0();
    if (FUN_141a12380(nType, strSend))
        return;
    FUN_141a12e40(nType, strSend, bHistory);
}

// @0x141a0f430
void UIMessenger::FUN_141a0f430(CStringW strText, bool bHistory)
{
    if (strText.GetAt(0) != L'/')
        return;
    if (FUN_141a10fd0(strText, CStringW(L""), 0) && bHistory)
        m_pBrowser->FUN_141a25f70(strText, m_inputHistory);
}

// @0x141a0f520
void UIMessenger::FUN_141a0f520(const Scaleform::GFx::FunctionHandler::Params& params)
{
    FUN_141a0f180();
}

// @0x141a0f550
void UIMessenger::FUN_141a0f550(NotifyObject* pNotify)
{
    NotifyGameEventChanged* pChanged = dynamic_cast<NotifyGameEventChanged*>(pNotify);
    if (pChanged != 0 && FUN_140841300(pChanged->m_eventName, "SaleChat"))
        FUN_141a14dc0();
}

// @0x141a0f5d0
void UIMessenger::FUN_141a0f5d0(NotifyObject* pNotify)
{
    NotifyChatEmoticonSelected* pSelected = dynamic_cast<NotifyChatEmoticonSelected*>(pNotify);
    if (pSelected == 0)
        return;
    if (pSelected->m_strTarget != m_strName)
    {
        FUN_141a13940();
        return;
    }
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(pSelected->m_nEmoticonId);
    if (!spEmo)
        return;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x4c3, 0);
        return;
    }
    if (!spCli->FUN_140a39dd0(spEmo->m_nId))
        return;
    std::list<ChatEmoticonDataPtr> emoticons;
    emoticons.push_back(spEmo);
    FUN_141a13510(emoticons);
    FUN_1419235d0();
}

// @0x141a0f7b0
void UIMessenger::FUN_141a0f7b0()
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    FUN_141a14dc0();
    int nType = FUN_141a14500();
    if (!m_pBrowser->FUN_141a264c0(0x10))
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e2e0(pPlayer->FUN_1416639e0());
        if (spItem)
            nType = 0x10;
    }
    FUN_141a146d0(nType);
}

// @0x141a0f870
void UIMessenger::FUN_141a0f870()
{
    if (!m_pBrowser->FUN_141a26480())
    {
        if (m_nHistoryIndex != -1)
        {
            m_nTargetSelectedIndex = m_nHistoryIndex;
            m_nHistoryIndex = -1;
        }
    }
    else
    {
        m_nHistoryIndex = m_nTargetSelectedIndex;
    }
    FUN_141a14dc0();
    FUN_141a0e990();
}

// @0x141a0f900
bool UIMessenger::FUN_141a0f900(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        FUN_1418fd740(box.FUN_141a02ed0(0, 0), box.FUN_141a02ed0(1, 0), box.FUN_141a02e50(2, 0));
    return true;
}

// @0x141a0f980
bool UIMessenger::FUN_141a0f980(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
        FUN_1418fdfd0(box.FUN_141a02f10(0, 0));
    return true;
}

// @0x141a0f9d0
bool UIMessenger::FUN_141a0f9d0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        if (const_cast<CMsgBoxData&>(box).FUN_141a04aa0())
        {
            CGameOption::GetInstance()->FUN_140ae6540()->m_b[0] = 0;
            CGameOption::GetInstance()->FUN_1412432d0();
        }
        const CStringW& strText = box.FUN_141a02fd0(0, CStringW());
        FUN_141a12e40(0x10, strText, 1);
        {
            CString strNone("");
            m_textInput->FUN_1422e0b80(strNone);
        }
        m_textInput->vfunc_24(1);
    }
    return true;
}

// @0x141a0fb40
bool UIMessenger::FUN_141a0fb40(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        if (const_cast<CMsgBoxData&>(box).FUN_141a04aa0())
        {
            CGameOption::GetInstance()->FUN_140ae6540()->m_b[1] = 0;
            CGameOption::GetInstance()->FUN_1412432d0();
        }
        const CStringW& strText = box.FUN_141a02fd0(0, CStringW());
        FUN_141a12e40(0xb, strText, 1);
        {
            CString strNone("");
            m_textInput->FUN_1422e0b80(strNone);
        }
        m_textInput->vfunc_24(1);
    }
    return true;
}

// @0x141a0fcb0
bool UIMessenger::FUN_141a0fcb0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        if (const_cast<CMsgBoxData&>(box).FUN_141a04aa0())
        {
            CGameOption::GetInstance()->FUN_140ae6540()->m_b[2] = 0;
            CGameOption::GetInstance()->FUN_1412432d0();
        }
        const CStringW& strText = box.FUN_141a02fd0(0, CStringW());
        FUN_141a12e40(0xc, strText, 1);
        {
            CString strNone("");
            m_textInput->FUN_1422e0b80(strNone);
        }
        m_textInput->vfunc_24(1);
    }
    return true;
}

// @0x141a0fe20
int UIMessenger::FUN_141a0fe20(int nEmoticonId)
{
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (!spEmo)
        return 0;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x782, 0);
        return 0;
    }
    if (!spCli->FUN_140a39dd0(spEmo->m_nId))
        return 0;
    COutPacket packet(0xb7, 0);
    packet.vfunc_o10_1(3);
    packet.vfunc_o10_3(nEmoticonId);
    packet.vfunc_o10_8(FUN_141a0df70());
    packet.vfunc_o10_1(FUN_141a144a0());
    FUN_140710590(packet);
    return 1;
}

// @0x141a10010
void UIMessenger::FUN_141a10010(int nType, int nEmoticonId)
{
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (!spEmo)
        return;
    CStringW strSize(L"");
    if (spEmo->m_nWidth != 0 || spEmo->m_nHeight != 0)
        strSize = StringFormat(L"width='{0}' height='{1}'", spEmo->m_nWidth, spEmo->m_nHeight);
    CStringW strLine = FUN_140cde1f0(L"<img src='img://emoticon:{0}' vspace='{1}' {2} />", spEmo->m_nId,
                                     spEmo->m_nVSpace, strSize);
    CStringW strPrefix;
    if (!m_textInput.IsNull())
    {
        CStringW strInput = m_textInput->FUN_1422e0b00().Trim();
        if (!strInput.IsEmpty() && strInput.GetAt(0) == L'/')
        {
            std::vector<CStringW> parts;
            FUN_140988d60(strInput, parts, L" ");
            if (parts.size() >= 2)
            {
                int nChatType = CUserCommandCli::GetInstance()->ChatType(parts[0]);
                if (nChatType == 4)
                    strPrefix = StringFormat(L"{0} {1} ", parts[0], parts[1]);
            }
        }
    }
    if (strPrefix.IsEmpty())
        FUN_141a146d0(nType);
    strLine = strPrefix + strLine;
    FUN_141a0f1d0(strLine, strLine, 0);
}

// @0x141a10490
int UIMessenger::FUN_141a10490(int nEmoticonId, bool bFavorite)
{
    ChatEmoticonDataPtr spEmo = FUN_1409eecd0()->FUN_1401e7120(nEmoticonId);
    if (!spEmo)
        return 0;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x7d3, 0);
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

// @0x141a11be0
void UIMessenger::FUN_141a11be0(int nType, const CStringW& strText)
{
    Unk_MsgChat chat;
    chat.m_nType = nType;
    chat.m_strText = strText;
    FUN_141276f80(chat);
    m_pBrowser->m_1b0 = FUN_141482f00(nType);
}

// @0x141a11c60
bool UIMessenger::FUN_141a11c60(const CStringW& strCommand, CStringW strText, int* pType)
{
    *pType = 0x1b;
    if (strCommand.IsEmpty())
        return true;
    MS2Ptr<TUserCommandInfo> spInfo = CUserCommandCli::GetInstance()->Find(strCommand);
    int nType = 0x1b;
    if (spInfo.get() != 0)
    {
        nType = spInfo->chatType;
        if (!spInfo->function.IsEmpty())
            strText.Replace(strCommand, L"/" + spInfo->function);
    }
    *pType = nType;
    if (nType == 0x1b || nType == 10 || nType == 0x15)
    {
        FUN_141a11be0(FUN_141a144a0(), strText);
        return true;
    }
    return false;
}

// @0x141a11e30
void UIMessenger::FUN_141a11e30()
{
    if (m_textInput == 0)
        return;
    if (m_textInput->FUN_1422c76c0() == 0)
    {
        vfunc_78();
        if (m_pBrowser->m_1b0 == 4)
        {
            m_textInput->FUN_1422c7630(1);
            FUN_141a17900(m_pBrowser->m_strWhisperTarget);
        }
        else if (m_pBrowser->m_1b0 == 0x1a)
        {
            m_textInput->FUN_1422c7630(1);
            FUN_141a17a60(m_pBrowser->m_1a8);
        }
        else
        {
            int nLength = m_textInput->FUN_1422e0b00().GetLength();
            m_textInput->FUN_1422c7630(1);
            m_textInput->FUN_1422e1500(nLength, nLength);
            m_textInput->vfunc_24(1);
        }
        return;
    }
    FUN_140d2c2a0(m_textInput, m_inputHistory);
    CStringW strText = FUN_141842320(m_textInput->FUN_1422e0b00());
    CStringW strHtml = m_textInput->FUN_1422e0c20();
    FUN_140d2c650(strHtml);
    strText = strText.Trim();
    if (strText.IsEmpty())
    {
        FUN_141a12260();
        return;
    }
    CStringW strSuffix = FUN_14025e7a0()->FUN_1422af5f0(2);
    if (!strSuffix.IsEmpty())
        strText.Append(strSuffix);
    FUN_141a0f1d0(strText, strHtml, 1);
    FUN_141a12260();
}

// @0x141a12260
int UIMessenger::FUN_141a12260()
{
    if (MS2Ptr<ASTextInput> spInput = m_textInput)
    {
        if (spInput->FUN_1422c76c0() != 0)
        {
            m_inputHistory.RemoveAll();
            spInput->FUN_1422c7630(0);
            spInput->FUN_1422e0bd0(CStringW(L"<FONT></FONT>"));
            spInput->vfunc_24(1);
            FUN_141a0d880(0);
            return 1;
        }
    }
    return 0;
}

// @0x141a12e40
void UIMessenger::FUN_141a12e40(int nType, CStringW strText, bool bHistory)
{
    FUN_141a10660(nType, strText, CStringW(L""), 0);
    if (bHistory)
        m_pBrowser->FUN_141a25f70(strText, m_inputHistory);
}

// @0x141a12f30
int UIMessenger::FUN_141a12f30()
{
    if (FUN_141482e80()->FUN_1414829e0() != m_strName)
        return 0;
    {
        MS2Ptr<ASTextInput> spInput = m_textInput;
        if (spInput && spInput->FUN_1422c76c0() != 0)
            return 1;
    }
    if (FUN_14025e7c0()->FUN_14116d7a0(0xf))
        return 0;
    return 1;
}

// @0x141a13030
bool UIMessenger::FUN_141a13030(CStringW& strText)
{
    strText.Trim(L" ");
    return strText.IsEmpty();
}

// @0x141a13070
bool UIMessenger::FUN_141a13070(const CStringW& strName)
{
    for (size_t i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (!spTab)
            continue;
        if (spTab->m_strName == strName)
            return true;
    }
    return false;
}

// @0x141a13160
int UIMessenger::FUN_141a13160(TalkTab* pTab, int nChannel)
{
    return FUN_141a131a0(pTab, FUN_141482f00(nChannel));
}

// @0x141a131a0
int UIMessenger::FUN_141a131a0(TalkTab* pTab, int nType)
{
    if (pTab == 0)
        return 1;
    return pTab->m_panel.FUN_141482460(nType);
}

// @0x141a13210
void UIMessenger::FUN_141a13210()
{
    MS2Ptr<ASTextInput> spInput = m_textInput;
    if (spInput.IsNull())
        return;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x720, 0);
        return;
    }
    CStringW strText = spInput->FUN_1422e0b00();
    strText.Trim();
    std::list<ChatEmoticonDataPtr> found;
    std::list<ChatEmoticonDataPtr> aliases;
    FUN_1409eecd0()->FUN_1401e74c0(strText, &aliases);
    for (std::list<ChatEmoticonDataPtr>::iterator it = aliases.begin(); it != aliases.end(); ++it)
    {
        ChatEmoticonDataPtr spEmo = *it;
        if (!spEmo)
            continue;
        if (!spCli->FUN_140a39dd0(spEmo->m_nId))
            continue;
        found.push_back(spEmo);
    }
    if (found.empty())
        return;
    FUN_141a13510(found);
    spInput->FUN_1422e0ab0(CStringW(L""));
}

// @0x141a13510
void UIMessenger::FUN_141a13510(std::list<ChatEmoticonDataPtr>& emoticons)
{
    if (emoticons.empty())
        return;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->FUN_140d9f8f0();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x747, 0);
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

// @0x141a13940
void UIMessenger::FUN_141a13940()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("closeChatEmoticonPreview");
}

// @0x141a139c0
void UIMessenger::FUN_141a139c0(const CStringW& strText, int bClear)
{
    if (!m_textOutput)
        return;
    int bAtEnd = m_textOutput->FUN_1422e4680();
    if (bClear)
        m_textOutput->FUN_1422e0b80(CString(""));
    if (!strText.IsEmpty())
        m_textOutput->FUN_1422e1430(strText);
    if (bAtEnd)
        m_textOutput->FUN_1422e4720();
}

// @0x141a13ac0
void UIMessenger::FUN_141a13ac0()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    int bAdditive = 0;
    for (unsigned i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (spTab.get() != 0 && spTab->m_nAdditive != 0)
        {
            bAdditive = 1;
            break;
        }
    }
    pDialog->FUN_1407cb9c0("m_additiveTab", bAdditive);
    pDialog->Invoke("updateAdditiveButton");
}

// @0x141a13c20
void UIMessenger::FUN_141a13c20(int bUp)
{
    if (m_textInput == 0)
        return;
    if (m_textInput->FUN_1422c76c0() == 0)
        return;
    Unk_MsgHistory entry;
    if (m_pBrowser->FUN_141a261b0(bUp, entry))
    {
        m_inputHistory.RemoveAll();
        m_inputHistory.Copy(entry.m_keys);
        FUN_141a17830(entry.m_strText, 1);
        vfunc_94(entry.m_strText);
    }
}

// @0x141a13d20
CStringW UIMessenger::FUN_141a13d20()
{
    if (FUN_141482e80()->m_pBrowser != 0)
    {
        for (int i = 1; i < 100; i++)
        {
            CStringW strName = FUN_1409e97f0(0x57d, i);
            if (FUN_141482e80()->m_pBrowser->FUN_141a25410(0, strName))
                return strName;
        }
    }
    return FUN_14028de60(0x57d);
}

// @0x141a13e00
void UIMessenger::FUN_141a13e00()
{
    std::vector<int> types;
    types.push_back(0x10);
    types.push_back(0xb);
    types.push_back(0xc);
    types.push_back(0);
    types.push_back(7);
    types.push_back(8);
    types.push_back(0x12);
    types.push_back(0x14);
    m_subjects.clear();
    m_subjects.push_back(0);
    m_subjects.push_back(0xc);
    m_subjects.push_back(0xb);
    m_subjects.push_back(0x10);
    m_subjects.push_back(7);
    m_subjects.push_back(8);
    m_subjects.push_back(0x12);
    m_subjects.push_back(0x14);
    m_subjectIndex.clear();
    int nIndex = 0;
    for (std::vector<int>::iterator it = types.begin(); it != types.end(); ++it)
    {
        int& nType = *it;
        if (m_pBrowser->FUN_141a264c0(nType))
            continue;
        m_subjectIndex.insert(std::make_pair(nIndex++, nType));
    }
}

// @0x141a14110
int UIMessenger::FUN_141a14110()
{
    for (std::vector<int>::iterator it = m_subjects.begin(); it != m_subjects.end(); ++it)
    {
        int& nType = *it;
        if (!m_pBrowser->FUN_141a264c0(nType))
            return FUN_141a141c0(nType);
    }
    return -1;
}

// @0x141a141c0
int UIMessenger::FUN_141a141c0(int nType)
{
    for (std::map<int, int>::iterator it = m_subjectIndex.begin(); it != m_subjectIndex.end(); ++it)
    {
        if (nType == it->second)
            return it->first;
    }
    return -1;
}

// @0x141a14250
int UIMessenger::FUN_141a14250()
{
    if (MS2Ptr<ASTextInput> spInput = m_textInput)
    {
        CStringW strText = spInput->FUN_1422e0b00();
        strText.Trim();
        if (strText.GetLength() < 2)
            return 0x1b;
        if (strText.GetAt(0) == L'/')
        {
            const int& nType = CUserCommandCli::GetInstance()->ChatType(strText);
            if (!m_pBrowser->FUN_141a264c0(nType))
                return nType;
            return FUN_141a14500();
        }
        if (FUN_14025e7c0()->FUN_14116d720())
        {
            int nLast = strText.GetLength() - 1;
            if (strText.GetAt(0) == L':' && strText.GetAt(nLast) == L':')
            {
                std::list<ChatEmoticonDataPtr> aliases;
                FUN_1409eecd0()->FUN_1401e74c0(strText, &aliases);
                if (aliases.size() != 0)
                    return 0x18;
            }
        }
    }
    return 0x1b;
}

// @0x141a144a0
int UIMessenger::FUN_141a144a0()
{
    if (m_subject)
        return FUN_141a14580(m_subject->FUN_1422df6c0());
    return FUN_141a14500();
}

// @0x141a14500
int UIMessenger::FUN_141a14500()
{
    std::map<int, int>::iterator it = m_subjectIndex.find(FUN_141a14110());
    if (it == m_subjectIndex.end())
        return 0x1b;
    return it->second;
}

// @0x141a14580
int UIMessenger::FUN_141a14580(int nIndex)
{
    std::map<int, int>::iterator it = m_subjectIndex.find(nIndex);
    if (it == m_subjectIndex.end())
        return FUN_141a14500();
    return it->second;
}

// @0x141a14600
void UIMessenger::FUN_141a14600()
{
    int nType = FUN_141a14250();
    switch (nType)
    {
    case 0:
    case 7:
    case 8:
    case 0xb:
    case 0xc:
    case 0x10:
    case 0x12:
        FUN_141a146d0(nType);
        break;
    case 4:
        FUN_141a17900(m_pBrowser->m_strWhisperTarget);
        break;
    case 0x14:
        FUN_141a17a60(m_pBrowser->m_1a8);
        break;
    }
}

// @0x141a146d0
void UIMessenger::FUN_141a146d0(int nType)
{
    if (FUN_141a12f30() && m_subject)
    {
        m_subject->FUN_1422df690(FUN_141a141c0(nType));
        vfunc_93();
    }
}

// @0x141a14760
void UIMessenger::FUN_141a14760()
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0 || !m_subject)
        return;
    unsigned nCount = m_subject->FUN_1422df620();
    unsigned nNext = m_subject->FUN_1422df6c0() + 1;
    if (nCount <= nNext)
        nNext = 0;
    int nType = FUN_141a14580(nNext);
    if (nType == 0x10)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5e2e0(pPlayer->FUN_1416639e0());
        if (spItem == 0)
        {
            if (!m_pBrowser->FUN_141a264c0(0xb))
                nType = 0xb;
            else
                nType = FUN_141a14500();
        }
    }
    FUN_141a146d0(nType);
}

// @0x141a148b0
int UIMessenger::FUN_141a148b0(const CStringW& strText)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return 0;
    ATL::CAtlArray<MS2Ptr<CSkillSystem::stEmotion> > emotions;
    pPlayer->FUN_141523bc0()->FUN_1417691a0(emotions);
    if (emotions.GetCount() == 0)
        return 0;
    CStringW strLine(strText);
    FUN_140d2c650(strLine);
    int nBegin = strLine.Find(L'/', 0);
    if (nBegin == -1)
        return 0;
    int nEnd = strLine.Find(L' ', nBegin);
    if (nEnd == -1)
        nEnd = strLine.GetLength();
    CStringW strCommand = strLine.Mid(nBegin, nEnd);
    strCommand.TrimRight();
    for (size_t i = 0; i < emotions.GetCount(); i++)
    {
        MS2Ptr<Unk_MsgEmotionKeywords> spKeywords = FUN_140347050(emotions[i]->m_id);
        if (spKeywords == 0)
            return 0;
        for (size_t j = 0; j < spKeywords->m_keywords.GetCount(); j++)
        {
            CStringW strKeyword = spKeywords->m_keywords[j];
            if (strKeyword.CompareNoCase(strCommand) == 0)
            {
                pPlayer->FUN_141525480(spKeywords->m_nAction, 0);
                return 1;
            }
        }
    }
    return 0;
}

// @0x141a14bb0
void UIMessenger::FUN_141a14bb0(const CStringW& strTarget)
{
    MyPC* pPlayer = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPlayer == 0)
        return;
    if (pPlayer->vfunc_77() == strTarget)
        return;
    FUN_141a17900(strTarget);
}

// @0x141a14c40
bool UIMessenger::FUN_141a14c40(CStringW& strText, CStringW strPart)
{
    int nFound = strText.Find(strPart, 0);
    if (nFound != -1)
        strText.Delete(nFound, strPart.GetLength());
    return nFound != -1;
}

// @0x141a14ce0
bool UIMessenger::FUN_141a14ce0(CStringW strText, int nMax)
{
    int nOpen;
    int nClose;
    while ((nOpen = strText.Find(L"<", 0)) != -1)
    {
        nClose = strText.Find(L">", nOpen + 1);
        if (nClose == -1)
            break;
        strText.Delete(nOpen, nClose - nOpen + 1);
    }
    int nLength = strText.GetLength();
    return nLength <= nMax;
}

// @0x141a15890
void UIMessenger::FUN_141a15890()
{
    bool bEffect = false;
    const int& nType = FUN_141a14580(m_nTargetSelectedIndex);
    if (nType == 0x10 && !m_pBrowser->FUN_141a264c0(0x10))
        bEffect = true;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
        pDialog->Invoke("updateSuperWorldChatEffect", bEffect);
}

// @0x141a15970
void UIMessenger::FUN_141a15970()
{
    if (!m_buttonBar)
        return;
    unsigned nCount = m_buttonBar->FUN_1422e3380();
    ATL::CAtlArray<MS2Ptr<TalkTab> > tabs;
    for (unsigned i = 0; i < nCount; i++)
    {
        TalkTab* pTab = FUN_141a0e0f0(m_buttonBar->FUN_1422e37e0(i));
        if (pTab == 0)
            return;
        tabs.Add(MS2Ptr<TalkTab>(pTab));
    }
    m_tabs.RemoveAll();
    m_tabs.Copy(tabs);
}

// @0x141a15ae0
void UIMessenger::vfunc_87()
{
    if (m_tabs.IsEmpty())
        return;
    void* pMovie = FUN_1422bb8b0(m_28);
    if (pMovie == 0)
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    Scaleform::GFx::Value names;
    FUN_14256e3e0(pMovie, &names);
    for (unsigned i = 0; i < m_tabs.GetCount(); i++)
    {
        MS2Ptr<TalkTab> spTab = m_tabs[i];
        if (spTab.get() == 0)
            continue;
        if (spTab->m_panel.FUN_141482200()->m_nWhisper == 0)
            continue;
        if (spTab == FUN_141a0e050())
            continue;
        names.PushBack(Scaleform::GFx::Value((const wchar_t*)spTab->m_strName));
    }
    if (names.GetArraySize() != 0)
        pDialog->Invoke("whisperFrom", Scaleform::GFx::Value(names));
}

// @0x141a15d70
void UIMessenger::vfunc_89(const CStringW& strText, int nChannel)
{
    vfunc_88(strText, FUN_141482f00(nChannel));
}

// @0x141a15dc0
int UIMessenger::vfunc_88(const CStringW& strText, int nType)
{
    TalkTab* pTab = FUN_141a0e050();
    if (pTab == 0)
        return 0;
    if (!FUN_141a131a0(pTab, nType))
    {
        CStringW strLine(strText);
        FUN_141a0ead0(pTab->m_panel.FUN_1414821b0()->m_nFontSize, strLine);
        FUN_141a139c0(strLine, 0);
    }
    return 1;
}

// @0x141a15e80
void UIMessenger::vfunc_90()
{
    FUN_141482e80()->FUN_141482c80(m_strName);
}

// @0x141a15ef0
void UIMessenger::vfunc_91()
{
    m_pBrowser->m_itHistory = m_pBrowser->m_history.end();
}

// @0x141a15f60
void UIMessenger::vfunc_92()
{
    if (FUN_1403ed2b0()->FUN_141adc940(0x4e62))
    {
        CStringW strName = FUN_141a13d20();
        if (FUN_141a0e810(strName, 1, 1, 0))
        {
            FUN_141a0e2a0(strName);
            vfunc_4();
            FUN_141482e80()->m_nNewTabMode = 2;
            FUN_141482e80()->m_pNewTabWindow = this;
            FUN_1403ed2b0()->FUN_141adc530(0x4e62);
        }
    }
}

// @0x141a16030
void UIMessenger::vfunc_93()
{
    if (FUN_1422dc2d0())
    {
        CStringW strHtml = m_textInput->FUN_1422e0c20();
        CStringW strText = m_textInput->FUN_1422e0b00();
        if (strText.GetAt(0) == L'/')
        {
            int nSpace = strText.Find(L" ", 0);
            if (nSpace == -1)
            {
                strHtml = L"";
            }
            else
            {
                strText = strText.Mid(0, nSpace);
                FUN_141a14c40(strHtml, strText);
            }
        }
        FUN_141a17830(strHtml, 1);
        if (m_subject)
        {
            m_nTargetSelectedIndex = m_subject->FUN_1422df6c0();
            const int& nType = FUN_141a14580(m_nTargetSelectedIndex);
            if (!m_pBrowser->FUN_141a264c0(nType) && (nType == 0x10 || nType == 0xb || nType == 0xc))
                GetClientPlatform()->vfunc_43(2, false, 1000);
            FUN_141a15890();
        }
    }
}

// @0x141a162a0
void UIMessenger::vfunc_94(const CStringW& strText)
{
    if (FUN_141a14250() == 4)
        FUN_141a131f0();
    else
        FUN_141a13200();
}

// @0x141a162e0
void UIMessenger::vfunc_95(const CStringW& strTarget)
{
    FUN_141a14bb0(strTarget);
}

// @0x141a16310
void UIMessenger::vfunc_96(int nMenu)
{
    if (nMenu == 0)
    {
        FUN_141482e80()->m_nNewTabMode = 1;
        FUN_141482e80()->m_pNewTabWindow = this;
        FUN_1403ed2b0()->FUN_141adc530(0x4e62);
    }
    else if (nMenu == 1)
    {
        if (FUN_141a0e350(FUN_141a0dfc0()))
        {
            if (FUN_141482e80()->m_pBrowser != 0)
                FUN_141482e80()->m_pBrowser->FUN_141a245d0(m_strName);
            vfunc_4();
        }
    }
}

// @0x141a16400
void UIMessenger::vfunc_97(const CStringW& strName)
{
    TalkTab* pTab = FUN_141a0e0f0(strName);
    if (pTab == 0)
        return;
    CStringW strHtml;
    POSITION pos = m_pBrowser->m_logs.GetHeadPosition();
    while (pos != 0)
    {
        MessengerData::TalkLog& log = m_pBrowser->m_logs.GetNext(pos);
        if (!FUN_141a131a0(pTab, log.m_nKind))
            strHtml += log.m_strMsg;
    }
    FUN_141a0ead0(pTab->m_panel.FUN_1414821b0()->m_nFontSize, strHtml);
    FUN_141a0ebb0(pTab->m_panel.FUN_1414821b0()->m_nBackgroundAlpha);
    FUN_141a139c0(strHtml, 1);
    if (m_buttonBar)
        m_nTabSelectedIndex = m_buttonBar->FUN_1422e3210();
    m_pBrowser->m_194 = (int)m_pBrowser->m_logs.GetCount();
    m_pBrowser->m_pendingLogs.RemoveAll();
}

// @0x141a165c0
void UIMessenger::vfunc_98(const CStringW& strName, const CString& strWindow)
{
    MS2Ptr<TalkTab> spTab = FUN_141a0e0f0(strName);
    if (!spTab)
        return;
    UIMessenger* pWindow = FUN_141a184c0(CString(strWindow));
    if (pWindow == 0)
        return;
    if (FUN_141a0e350(spTab->m_strName))
    {
        if (pWindow->FUN_141a0e650(spTab.get()))
        {
            pWindow->FUN_141a0e2a0(spTab->m_strName);
            pWindow->vfunc_4();
        }
        if (FUN_141482e80()->m_pBrowser != 0)
            FUN_141482e80()->m_pBrowser->FUN_141a245d0(m_strName);
        vfunc_4();
    }
}

// @0x141a16730
void UIMessenger::FUN_141a16730(const CStringW& strName, int nX, int nY, int nWidth, int nHeight, int nTarget)
{
    MS2Ptr<TalkTab> spTab = FUN_141a0e0f0(strName);
    if (!spTab)
        return;
    if (m_tabs.GetCount() < 2)
        return;
    if (FUN_141a0e350(spTab->m_strName))
    {
        ATL::CAtlArray<MS2Ptr<TalkTab> > tabs;
        tabs.Add(spTab);
        if (FUN_141482e80()->m_pBrowser != 0)
            FUN_141482e80()->m_pBrowser->FUN_141a24160(tabs, nX, nY, nWidth, nHeight, nTarget);
        FUN_141a0e990();
        vfunc_4();
    }
}

// @0x141a168a0
void UIMessenger::FUN_141a168a0(const ATL::CAtlArray<CStringW>& args)
{
    if (FUN_140841300(args[0], "dungeonRoom"))
    {
        if (args.GetCount() == 2)
            FUN_141a16c50(FUN_140718200(args[1]));
    }
    else if (FUN_140841300(args[0], "joinPartyDungeonHelper"))
    {
        if (args.GetCount() == 4)
        {
            int nPartyId = FUN_140718200(args[1]);
            CStringW strLeader(args[2]);
            int nRoomId = FUN_140718200(args[3]);
            FUN_141a16cc0(nPartyId, strLeader, nRoomId);
        }
    }
    else if (FUN_140841300(args[0], "joinPartyDungeonMember"))
    {
        if (args.GetCount() == 4)
        {
            int nPartyId = FUN_140718200(args[1]);
            CStringW strLeader(args[2]);
            int nRoomId = FUN_140718200(args[3]);
            FUN_141a172a0(nPartyId, strLeader, nRoomId);
        }
    }
    else if (FUN_140841300(args[0], "inviteParty") && args.GetCount() == 2)
    {
        FUN_141a17690(args[1]);
    }
}

// @0x141a16bb0
void UIMessenger::FUN_141a16bb0(int nProductId)
{
    UICashShopDialog* pShop = FUN_140b04f80(0x4ebc);
    if (pShop != 0)
    {
        ATL::CAtlArray<int> ids;
        ids.Add(nProductId);
        pShop->FUN_141035990(CString("OnUserBillDialog"), ids, false);
    }
}

// @0x141a16c50
void UIMessenger::FUN_141a16c50(int nRoomId)
{
    UIDungeonRoomDialog* pDialog = FUN_140961550(0x4ebd);
    if (pDialog != 0)
    {
        if (pDialog->FUN_141924630())
            pDialog->vfunc_68();
        pDialog->FUN_1412b8ff0(nRoomId);
        pDialog->FUN_141924680();
    }
}

// @0x141a16cc0
void UIMessenger::FUN_141a16cc0(int nPartyId, CStringW strLeader, int nRoomId)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    if (pMe->vfunc_77() == strLeader)
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_party_is_my_dungeon_help")), 1, 1);
        return;
    }
    if (FUN_1409670d0()->FUN_14162ab20())
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_party_has_party")), 1, 1);
        return;
    }
    int nState = FUN_140931510()->FUN_140d9f880(nRoomId);
    if (nState >= 10)
    {
        FUN_1412b9870(nRoomId, nState);
        return;
    }
    if (!FUN_140931510()->FUN_140d9f2c0()->CanClaimHelperReward(nRoomId))
    {
        DungeonRoomPtr spRoom = FUN_14031c2a0()->GetRoom(nRoomId);
        if (!(spRoom == 0))
        {
            const int& nClears = spRoom->m_dungeonHelperRequireClearCount;
            FUN_1412751f0(FUN_140bfa7f0(CStringW(L"s_party_join_only_dungeon_expert"),
                                        FUN_1401a9d70()->FUN_141811980(0x14, nRoomId), nClears), 1, 1);
        }
        return;
    }
    CStringW strMsg = FUN_1408f71a0(CStringW(L"s_party_join_dungeon_helper_msg"), strLeader,
                                    FUN_1401a9d70()->FUN_141811980(0x14, nRoomId));
    MS2Ptr<CMsgBoxData> box = FUN_140d74230(
        Delegate<bool(int, const CMsgBoxData&)>(this, &UIMessenger::FUN_141a17bc0), CStringW(strMsg));
    if (box.get() != 0)
    {
        box->FUN_140534050(nPartyId);
        box->FUN_140534050(nRoomId);
    }
}

// @0x141a172a0
void UIMessenger::FUN_141a172a0(int nPartyId, CStringW strLeader, int nRoomId)
{
    MyPC* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    if (pMe->vfunc_77() == strLeader)
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_party_is_my_dungeon_help")), 1, 1);
        return;
    }
    if (FUN_1409670d0()->FUN_14162ab20())
    {
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_party_has_party")), 1, 1);
        return;
    }
    int nState = FUN_140931510()->FUN_140d9f880(nRoomId);
    if (nState >= 10)
    {
        FUN_1412b9870(nRoomId, nState);
        return;
    }
    CStringW strMsg = FUN_1408f71a0(CStringW(L"s_party_join_dungeon_member_msg"), strLeader,
                                    FUN_1401a9d70()->FUN_141811980(0x14, nRoomId));
    MS2Ptr<CMsgBoxData> box = FUN_140d74230(
        Delegate<bool(int, const CMsgBoxData&)>(this, &UIMessenger::FUN_141a17c90), CStringW(strMsg));
    if (box.get() != 0)
    {
        box->FUN_140534050(nPartyId);
        box->FUN_140534050(nRoomId);
    }
}

// @0x141a17690
void UIMessenger::FUN_141a17690(CStringW strName)
{
    FUN_1409670d0()->FUN_14162ba50(CStringW(strName));
}

// @0x141a17700
void UIMessenger::FUN_141a17700()
{
    if (m_30.IsNull())
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0 || m_textInput.IsNull())
        return;
    if (!m_chatEmoticonPreview.IsNull() && m_textInput->FUN_1422c76c0() && m_chatEmoticonPreview->FUN_1422bfca0())
    {
        pDialog->Invoke("pushChatEmoticon");
        return;
    }
    FUN_141a11e30();
}

// @0x141a17830
void UIMessenger::FUN_141a17830(const CStringW& strText, int bSelectEnd)
{
    if (m_textInput == 0)
        return;
    m_textInput->FUN_1422e0bd0(strText);
    int nLength = strText.GetLength();
    if (bSelectEnd != 0 && nLength > 0)
        m_textInput->FUN_1422e1500(nLength, nLength);
    m_textInput->vfunc_24(1);
}

// @0x141a17900
void UIMessenger::FUN_141a17900(const CStringW& strTarget)
{
    CStringW strText;
    if (strTarget.IsEmpty())
        strText = FUN_1401e8510(L"{0} ", FUN_14028de60(0xaa5));
    else
        strText = FUN_140656190(L"{0} {1} ", FUN_14028de60(0xaa5), strTarget);
    FUN_141a17830(strText, 1);
}

// @0x141a17bc0
bool UIMessenger::FUN_141a17bc0(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        unsigned nPartyId = box.FUN_141a02e90(0, 0);
        unsigned nRoomId = box.FUN_141a02e90(1, 0);
        if (nPartyId != 0 && nRoomId != 0)
        {
            COutPacket packet(0x2c, 0);
            packet.vfunc_o10_1(0x27);
            packet.vfunc_o10_3(nPartyId);
            packet.vfunc_o10_3(nRoomId);
            FUN_140710590(packet);
        }
    }
    return true;
}

// @0x141a17c90
bool UIMessenger::FUN_141a17c90(int nButton, const CMsgBoxData& box)
{
    if (nButton == 0)
    {
        unsigned nPartyId = box.FUN_141a02e90(0, 0);
        unsigned nRoomId = box.FUN_141a02e90(1, 0);
        if (nPartyId != 0 && nRoomId != 0)
        {
            COutPacket packet(0x2c, 0);
            packet.vfunc_o10_1(0x2b);
            packet.vfunc_o10_3(nPartyId);
            packet.vfunc_o10_3(nRoomId);
            FUN_140710590(packet);
        }
    }
    return true;
}

// @0x141a184c0
UIMessenger* FUN_141a184c0(CString strName)
{
    return dynamic_cast<UIMessenger*>(FUN_140b632f0()->FUN_1422d41b0(strName).get());
}

// @0x141a17a60
void UIMessenger::FUN_141a17a60(const CStringW& strTarget)
{
    CStringW strText;
    if (strTarget.IsEmpty())
        strText = FUN_1401e8510(L"{0} ", FUN_14028de60(0xaa6));
    else
        strText = FUN_140656190(L"{0} {1} ", FUN_14028de60(0xaa6), strTarget);
    FUN_141a17830(strText, 1);
}

// @0x141a131f0
void UIMessenger::FUN_141a131f0()
{
}

// @0x141a13200
void UIMessenger::FUN_141a13200()
{
}
