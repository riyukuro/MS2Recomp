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

#include <utility>
#include <vector>

#include "ms2/client/ms2/messengerdata.h"
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
};

// "m_subject": the chat type drop-down.
class ASDropdownMenu : public ASUIComponent
{
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
};
Unk_MsgKeys* FUN_14025e7c0();

// The own field state.
class Unk_MsgField { public: int FUN_141adbb00(); };
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
