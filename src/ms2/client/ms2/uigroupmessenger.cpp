// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIGroupMessenger / UIGroupMessengerBrowser: the group chat
// windows and their tray, see uigroupmessenger.h.
// MS2-UNIT: client\ms2\uigroupmessenger.cpp
// MS2-RANGE: 0x141947920-0x141959330 .text$mn
// MS2-RANGE: 0x140113b00-0x140113ff0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??C?$MS2Ptr@VTalkLogList@GroupMessengerData@@@@QEBAPEAVTalkLogList@GroupMessengerData@@XZ 0x14194e5e0 ; unique
// MS2-PIN: ??A?$CAtlArray@VTalkLog@GroupMessengerData@@V?$CElementTraits@VTalkLog@GroupMessengerData@@@ATL@@@ATL@@QEAAAEAVTalkLog@GroupMessengerData@@_K@Z 0x14194eca0 ; unique
// MS2-PIN: ?GetCount@?$CAtlArray@VTalkLog@GroupMessengerData@@V?$CElementTraits@VTalkLog@GroupMessengerData@@@ATL@@@ATL@@QEBA_KXZ 0x14194ed50 ; unique
// MS2-PIN: ?GetHeadPosition@?$CAtlList@V?$Unk_ChatPtr@VCGroupChatMember@@@@V?$CElementTraits@V?$Unk_ChatPtr@VCGroupChatMember@@@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x14194ed80 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@_K@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEBAPEAU__POSITION@@XZ 0x14194f0b0 ; prop
// MS2-PIN: ?IsEmpty@?$CAtlMap@_KV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@V?$CElementTraits@_K@2@V?$CElementTraits@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@2@@ATL@@QEBA_NXZ 0x14194f460 ; prop
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Deque_val@U?$_Deque_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@$00@std@@QEAAAEAV?$_Deque_val@U?$_Deque_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@XZ 0x1419501e0 ; unique
// MS2-PIN: ?empty@?$list@V?$MS2Ptr@VChatEmoticonData@@@@V?$allocator@V?$MS2Ptr@VChatEmoticonData@@@@@std@@@std@@QEBA_NXZ 0x141950420 ; unique
// MS2-PIN: ?rbegin@?$deque@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@QEAA?AV?$reverse_iterator@V?$_Deque_iterator@V?$_Deque_val@U?$_Deque_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@std@@@2@XZ 0x1419505b0 ; unique
// MS2-PIN: ?rend@?$deque@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@QEAA?AV?$reverse_iterator@V?$_Deque_iterator@V?$_Deque_val@U?$_Deque_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@std@@@2@XZ 0x141950600 ; prop
// MS2-PIN: ?AssignRaw@?$MS2Ptr@VUIGroupMessenger@@@@QEAAAEAV1@PEAVUIGroupMessenger@@@Z 0x1419551b0 ; unique
// MS2-PIN: ??Y?$_Deque_const_iterator@V?$_Deque_val@U?$_Deque_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@std@@QEAAAEAV01@_J@Z 0x1419555b0 ; unique
// MS2-PIN: ??Y?$_Deque_iterator@V?$_Deque_val@U?$_Deque_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@@std@@QEAAAEAV01@_J@Z 0x1419555e0 ; unique
// MS2-PIN: ?GetCount@?$CAtlMap@IPEAVUIGroupMessenger@@V?$CElementTraits@I@ATL@@V?$CElementTraits@PEAVUIGroupMessenger@@@3@@ATL@@QEBA_KXZ 0x141955ee0 ; unique
// MS2-PIN: ?GetStartPosition@?$CAtlMap@IPEAVUIGroupMessenger@@V?$CElementTraits@I@ATL@@V?$CElementTraits@PEAVUIGroupMessenger@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x1419561b0 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Deque_val@U?$_Deque_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@$00@std@@QEAAAEAV?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x141958020 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@V?$_Deque_val@U?$_Deque_simple_types@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@2@$00@std@@QEBAAEBV?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@2@XZ 0x141958030 ; unique
// MS2-PIN: ?push_back@?$deque@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@QEAAXAEBV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@Z 0x141958fd0 ; unique
// MS2-PIN: ?size@?$deque@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$allocator@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@@std@@@std@@QEBA_KXZ 0x1419591f0 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
// MS2-PIN: memmove_s 0x141950650
//
// Two original TUs: the window (0x141947920-0x141950650) and the tray (0x141950770-), each with its own COMDAT copies
// of the container glue.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uigroupmessenger.cpp"
// The ASUIComponent slot list (validateNow = 24, ASCoreList's dataProvider setter = 25) for the list calls.
#define MS2_ASUICOMPONENT_SLOTS
#include "ms2/placeholder/ms2stdafx.h"

#include "uigroupmessenger.h"

#include <stdlib.h>

#include "ms2/ms2format.h"
#include "ms2/placeholder/formatstringid.h"
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
#include "ms2/placeholder/asslider.h"
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
#include "ms2/placeholder/notifysystem.h"
#include "ms2/placeholder/uiugceventdispatcher.h"
#include "ms2/placeholder/cmycharacter.h"
#include "ms2/placeholder/cinputkeyhandler.h"
#include "ms2/commonfiles/itemdatatable.h"
#include "ms2/client/ms2/worldservice.h"
int XmlGetAttr(class TiXmlElement*, char const*, CStringW&);   // C3: was FUN_140873420

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
    virtual void vfunc_24(bool b);
};
// The member list and the chat input come through the lookups of other dialogs' template instances.
class UIDailyMissionDialog
{
public:
    MS2Ptr<ASScrollingList> FUN_140c02900(const CString& strName);  // 0x140c02900
};
// "m_textInput": the chat input.
//   (C3: the input is ASTextInput itself; the old Unk_RankInput view is gone)
class UIGameRankingDialog
{
public:
    MS2Ptr<ASTextInput> FUN_140e35bd0(const CString& strName);    // 0x140e35bd0
};
// The message carries the box's AS root.
typedef UIMsg Unk_GrmMsg;

// The movie root of every dialog is an ASDialog.
class ASDialog : public ASUIComponent
{
};

// The chat UI (messengerdata.cpp): the current chat name and the group chat tray (+0x50).
struct Unk_MdNames
{
    void FUN_141482c80(CStringW strName);                           // make a chat the current one
    void FUN_141482d30(CStringW strName);                           // drop a chat name
    CStringW FUN_1414829e0();                                       // the current chat name
    void FUN_141482b70();                                           // forgets every chat name
};
struct Unk_MdState : Unk_MdNames
{
    char m_pad_00[0x50];
    UIGroupMessengerBrowser* m_pBrowser;                            // +0x50
};
MS2_CHECK_OFFSET(Unk_MdState, m_pBrowser, 0x50);
Unk_MdState* FUN_141482e80();

// The key state.
class Unk_GrmKeys : public CInputKeyHandler {};
void* FUN_14025e7c0();   // C3: was FUN_14025e7c0

// The notify manager.
class Unk_SingletonObj* FUN_140939a10();

// The UGC event dispatcher (the typing notices).
class UIUGCEventDispatcher;

// The per-user client state: the chat emoticon pack state.
CMyCharacter* FUN_140931510();

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
class UIPopUpMenu
{
public:
    void OpenForUserEntry(const Unk_PopupMenuInfo& info, class Unk_PmUserEntry* pEntry, const CStringW& strHistory, int nKind);
};
class Unk_PopupMenu* FUN_140c30140(int);   // C3: was FUN_140c30140

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
struct Unk_MdEntry
{
    Unk_MdEntry(class Unk_MdSrcD& src);                             // 0x141483af0
    unsigned GetKind();                                             // online
    __int64 FUN_141483da0();                                        // the character id
    CStringW GetImage();                                            // the image
    CStringW GetName();                                             // the name
    CStringW GetInfo();                                             // the level / job line
    unsigned m_nKind;                                               // +0x00
    __int64 m_nId;                                                  // +0x08
    CStringW m_strImage;                                            // +0x10
    CStringW m_strName;                                             // +0x18
    CStringW m_strInfo;                                             // +0x20
};
MS2_CHECK_SIZE(Unk_MdEntry, 0x28);

CStringW GetStringCommon(int nStringId);
CString FUN_1414842b0(int nKind, CStringW strName);                 // the line's icon
CString FUN_141028be0(__int64 nId, const CString& strName, int bNoDownload, CString strUrl);   // the local file of an image
void FUN_14083d2b0(CStringW& str);                                  // strips the markup
bool FUN_140d2aa60(CStringW& strHtml);                              // the input has item links
void FUN_140d2c650(CStringW& strHtml);                              // encodes the item links
void FUN_140d2c2a0(MS2Ptr<ASTextInput> spInput, ATL::CAtlArray<CStringW>& arrHistory);   // the input history keys
CStringW FUN_141842320(const CStringW& strText);                    // text to html
void FUN_140d73aa0(CStringW strText, int nA, void* pListener, CStringW strTag);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW strText, void* pListener, CStringW strTag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> spBox);
void* FUN_140d86260();   // C3: was FUN_140d86260
unsigned long GetTickCountMs2();   // C3: was FUN_140869420
void FUN_14151f200();                                               // the click sound
void FUN_1412751f0(const CStringW& strText, int nA, int nB);           // a system chat line
int FUN_141276180(const CString& strSound, const CString& strExtra);      // plays a sound
CString FUN_1412755f0();                                            // the UI settings directory
CString FUN_140cc2a00(const CString& strRoot, const CString& strFile);   // path join
class TiXmlNode   // C3: member view for the former free stand-ins
{
public:
    void Clear();
    class TiXmlNode* LinkEndChild(class TiXmlNode*);
};
class TiXmlElement* DocRootElement(class TiXmlDocument*);   // C3: was FUN_14081b310
class Unk_XmlNode   // C3: member view for the former free stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
};
void XmlSetAttr(class TiXmlElement*, char const*, float);   // C3: was FUN_140873e30
void XmlSetAttr(class TiXmlElement*, char const*, int);   // C3: was FUN_140873ca0
void XmlSetAttr(class TiXmlElement*, char const*, const CStringW&);   // C3: was FUN_1408740a0
int XmlGetAttr(class TiXmlElement*, char const*, float&);   // C3: was FUN_140873360
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
Scaleform::GFx::Movie* FUN_1422bb8b0(int nMovieId);                                  // the movie of a UI layer

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
    m_strName = StringFormat(L"{0} {1}", GetStringCommon(0x5d0), nIndex + 1);
}

// @0x141947bc0
UIGroupMessenger::~UIGroupMessenger()
{
}

// @0x141947c60
CString UIGroupMessenger::GetTypeName()
{
    return "GroupMessenger";
}
MS2_REPLACE_METHOD(0x141947C60, UIGroupMessenger, GetTypeName, 61, 0xEA0A8AA4);

// @0x141947cb0
int UIGroupMessenger::vfunc_65()
{
    UIDialog::vfunc_65();
    reinterpret_cast<NotifySystem*>(FUN_140939a10())->RegisterNotify(L"NotifyChatEmoticonSelected",
                                   Delegate<void(NotifyObject*)>(this, &UIGroupMessenger::FUN_14194a6f0));
    return 1;
}

// @0x141947da0
void UIGroupMessenger::vfunc_67()
{
    UIDialog::vfunc_67();
    reinterpret_cast<NotifySystem*>(FUN_140939a10())->UnregisterNotify(L"NotifyChatEmoticonSelected",
                                   Delegate<void(NotifyObject*)>(this, &UIGroupMessenger::FUN_14194a6f0));
    TSingleton<UIUGCEventDispatcher>::GetInstance()->FUN_141b38c70(this);
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
    if (n != 0)
    {
        if (MS2Ptr<ASTextInput> spInput = reinterpret_cast<UIGameRankingDialog*>(this)->FUN_140e35bd0("m_textInput"))
        {
            if (spInput->GetFocused())
            {
                spInput->SetFocused(0);
                spInput->SetHtmlTextA("");
                spInput->vfunc_24(1);
            }
        }
        FUN_141482e80()->FUN_141482d30(m_strName);
    }
    else
    {
        if (MS2Ptr<ASScrollingList> spOutput = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02900("m_textOutput"))
        {
            unsigned nCount = FUN_141482e80()->m_pBrowser->FUN_141952b30(m_nGroupId);
            unsigned nRows;
            if ((unsigned)spOutput->GetItemCount() < nCount + 5)
                nRows = spOutput->GetItemCount();
            else
                nRows = nCount + 5;
            spOutput->ScrollToIndex(nRows);
            spOutput->vfunc_24(1);
        }
        FUN_141482e80()->FUN_141482c80(m_strName);
        FUN_140b632f0()->BringToFront(this, m_e0);
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
    if (!((void*)DocRootElement(&doc)))
        ((void*)((class TiXmlNode*)(class TiXmlDocument*)(&doc))->LinkEndChild((class TiXmlNode*)(new TiXmlElement(GetTypeName()))));
    void* pRoot = ((void*)DocRootElement(&doc));
    if (!pRoot)
        return 0;
    vfunc_53(pRoot);
    return doc.SaveFile(FUN_140cc2a00(FUN_1412755f0(), GetXmlFileName()));
}
MS2_REPLACE_METHOD(0x1419482C0, UIGroupMessenger, vfunc_4, 598, 0x06A5FC79);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141948520
int UIGroupMessenger::vfunc_5()
{
    if (!m_80)
        return 0;
    m_78 = 0;
    void* pNode;
    void* pFirst = pNode = ((void*)((class Unk_XmlNode*)(class TiXmlDocument*)(&m_e8))->FirstChild(GetTypeName()));
    if (pNode != 0)
    {
        m_78 = vfunc_54(pNode);
        ((class TiXmlNode*)(class TiXmlDocument*)(&m_e8))->Clear();
    }
    else
    {
        TiXmlDocument doc;
        if (doc.LoadFile(FUN_140cc2a00(FUN_1412755f0(), GetXmlFileName()), TIXML_ENCODING_UNKNOWN))
        {
            void* pLoaded = ((void*)((class Unk_XmlNode*)(class TiXmlDocument*)(&doc))->FirstChild(GetTypeName()));
            if (pLoaded == 0)
                return 0;
            m_78 = vfunc_54(pLoaded);
        }
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
        XmlSetAttr((class TiXmlElement*)(pCfg), "offsetX", m_fOffsetX);
        XmlSetAttr((class TiXmlElement*)(pCfg), "offsetY", m_fOffsetY);
        XmlSetAttr((class TiXmlElement*)(pCfg), "alignType", m_nAlignType);
        XmlSetAttr((class TiXmlElement*)(pCfg), "scrollPosition", m_nScrollPosition);
        XmlSetAttr((class TiXmlElement*)(pCfg), "width", pDialog->FUN_1422c1340());
        XmlSetAttr((class TiXmlElement*)(pCfg), "height", pDialog->GetHeightCeil());
        XmlSetAttr((TiXmlElement*)pCfg, "name", m_strName);
        XmlSetAttr((class TiXmlElement*)(pCfg), "alpha", m_nAlpha);
        XmlSetAttr((class TiXmlElement*)(pCfg), "userlist", m_bUserList);
        XmlSetAttr((class TiXmlElement*)(pCfg), "minimize", m_6c);
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
        XmlGetAttr((class TiXmlElement*)(pCfg), "offsetX", *(float*)(&m_fOffsetX));
        XmlGetAttr((class TiXmlElement*)(pCfg), "offsetY", *(float*)(&m_fOffsetY));
        XmlGetAttr((class TiXmlElement*)(pCfg), "alignType", m_nAlignType);
        XmlGetAttr((class TiXmlElement*)(pCfg), "scrollPosition", m_nScrollPosition);
        XmlGetAttr((class TiXmlElement*)(pCfg), "width", nWidth);
        XmlGetAttr((class TiXmlElement*)(pCfg), "height", nHeight);
        XmlGetAttr((class TiXmlElement*)(pCfg), "name", m_strName);
        XmlGetAttr((class TiXmlElement*)(pCfg), "alpha", m_nAlpha);
        XmlGetAttr((class TiXmlElement*)(pCfg), "userlist", m_bUserList);
        XmlGetAttr((class TiXmlElement*)(pCfg), "minimize", m_6c);
        pDialog->SetSizeInt(nWidth, nHeight);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x141948980, UIGroupMessenger, vfunc_54, 415, 0x74DBE6B6);

// @0x141948b30
int UIGroupMessenger::vfunc_84(int bDeleteSave)
{
    m_80 = bDeleteSave == 0;
    return DeleteFileA(FUN_140cc2a00(FUN_1412755f0(), GetXmlFileName()));
}
MS2_REPLACE_METHOD(0x141948B30, UIGroupMessenger, vfunc_84, 219, 0xD2B9BC23);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x141948c20
void UIGroupMessenger::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    TSingleton<UIUGCEventDispatcher>::GetInstance()->FUN_141b38be0(this);
    FUN_14194bde0();
    if (FUN_141482e80()->m_pBrowser != 0)
    {
        ATL::CAtlArray<TalkLog> logs;
        MS2Ptr<TalkLogList> spLog;
        if (FUN_141482e80()->m_pBrowser->m_logs.Lookup(m_nGroupId, spLog))
            logs.Copy(spLog->m_logs);
        int nScrollPosition = m_nScrollPosition;
        for (unsigned int i = 0; i < logs.GetCount(); i++)
        {
            TalkLog log(logs[i]);
            FUN_14194d3d0(log.m_nKind, log.m_strMsg, log.m_strName, log.m_nA);
        }
        if (MS2Ptr<ASScrollingList> spOutput = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02900("m_textOutput"))
        {
            m_nScrollPosition = nScrollPosition;
            spOutput->FUN_1422e17f0(m_nScrollPosition);
        }
        if (MS2Ptr<ASTextInput> spInput = reinterpret_cast<UIGameRankingDialog*>(this)->FUN_140e35bd0("m_textInput"))
            spInput->SetMaxChars(*Client::Constants::GetInstance()->MaxChatLength.Get());
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

// @0x141949020
int UIGroupMessenger::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (!FUN_14194c6d0())
        return 0;
    if (((class Unk_GrmKeys*)FUN_14025e7c0())->FUN_14116d9c0(0x1c, 0, 0))
        return FUN_14194cbb0();
    else if (((class Unk_GrmKeys*)FUN_14025e7c0())->FUN_14116d840())
        return ClearInput();
    return 0;
}
MS2_REPLACE_METHOD(0x141949020, UIGroupMessenger, vfunc_13, 130, 0x3D622FE2);

// @0x1419490b0
void UIGroupMessenger::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (m_nTypingTime != 0)
    {
        if (m_nTypingTime + 10000 <= GetTickCountMs2())
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
        int nResult = pMsg->PopInt();
        Scaleform::GFx::Value root = static_cast<Unk_GrmMsg*>(pMsg)->PopValue();
        if (strTag == s_strGroupEdit)
        {
            if (nResult == 0)
            {
                ASObj box(root, 2);
                if (MS2Ptr<ASTextField> spName = box.FUN_1409b4620("m_textInput"))
                {
                    Unk_BlockList request(0x4e93, m_nGroupId);
                    request.Add("MessengerName", spName->GetTextW(), 0);
                    request.SetEnabled(1);
                    if (((class IClientPlatform*)FUN_140d86260())->vfunc_37(&request) == 1)
                    {
                        if (FUN_14194ce40(spName->GetTextW()) == 1)
                            return 0;
                        SetName(spName->GetTextW());
                    }
                }
                if (MS2Ptr<ASSlider> spAlpha = reinterpret_cast<AScript&>(box).FUN_140fafed0<ASSlider>("m_slider0"))
                    m_nAlpha = (int)spAlpha->FUN_1422ce840();
                FUN_14194bde0();
                if (FUN_141482e80()->m_pBrowser != 0)
                    FUN_141482e80()->m_pBrowser->FUN_141952530();
            }
            vfunc_4();
            FUN_14151f200();
            return 1;
        }
        else if (strTag == s_strGroupExit)
        {
            if (nResult == 0)
                CGroupChatManager::GetInstance()->SendGroupChatMode4(m_nGroupId, 0);
            FUN_14151f200();
            return 1;
        }
    }
    return 0;
}

// @0x141949640
void UIGroupMessenger::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
    PCBase* pPlayer = static_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    if (FUN_141482e80()->m_pBrowser == 0)
        return;
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
                *pRetVal = tooltip.FUN_1422bb870();
            }
        }
    }
    else if (strMethod == "itemPreview")
    {
        MS2Ptr<CItem> spItem(0);
        __int64 nUid = _atoi64(pArgs->FUN_1422b8d30());
        if (FUN_141482e80()->m_pBrowser->m_items.Lookup(nUid, spItem))
        {
            if (ItemPreviewMgr::GetInstance()->IsHudOn())
                ItemPreviewMgr::GetInstance()->OpenPreview(spItem, 0);
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
    else if (_stricmp("OnHideDialog", szMethod) == 0)
    {
        if (FUN_141482e80()->m_pBrowser != 0)
            FUN_141482e80()->m_pBrowser->FUN_141953160(m_strName);
        return 1;
    }
    else if (_stricmp("OnShowInviteDialog", szMethod) == 0)
    {
        UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
        if (pInvite != 0)
        {
            pInvite->FUN_14199fcf0(m_nGroupId);
            CUIService::GetInstance()->OpenDialog((eUIClassID)0x4e90);
        }
        return 1;
    }
    else if (_stricmp("OnShowUserList", szMethod) == 0)
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
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x15, L"", static_cast<IMessageListener*>(this), s_strGroupEdit);
        if (spBox)
        {
            spBox->FUN_140b76940(m_strName);
            spBox->Append<int>(m_nAlpha);
            FUN_140d73c60(spBox);
        }
    }
    else if (_stricmp("OnLeaveGroupMessenger", szMethod) == 0)
    {
        if (MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FormatStringId<CStringW>(0x81b, GetName()), static_cast<IMessageListener*>(this), s_strGroupExit))
            FUN_140d73c60(spBox);
    }
    else if (_stricmp("OnBuildScrollingList", szMethod) == 0)
    {
        OnBuildScrollingList();
    }
    else if (_stricmp("OnPopupMenu", szMethod) == 0)
    {
        ASData args;
        if (args.SetArgsIfAny(pArgs, nArgs))
        {
            CStringW strName = args.FUN_1422b8f40();
            float x = args.PopFloat();
            float y = args.PopFloat();
            FUN_14194b440(strName, x, y);
        }
    }
    else
    {
        if (_stricmp("eventTextInput", szMethod) == 0)
        {
            if (MS2Ptr<ASTextInput> spInput = reinterpret_cast<UIGameRankingDialog*>(this)->FUN_140e35bd0("m_textInput"))
                FUN_140d2c2a0(spInput, m_inputHistory);
            return 1;
        }
        else if (_stricmp("scrollPosition", szMethod) == 0)
        {
            ASData args;
            if (args.SetArgsIfAny(pArgs, nArgs))
                m_nScrollPosition = (int)args.PopFloat();
        }
        else if (_stricmp("eventChatEmoticonOpen", szMethod) == 0)
        {
            CUIService::GetInstance()->ToggleDialog((eUIClassID)0x4f80);
        }
        else if (_stricmp("eventChatEmoticonPush", szMethod) == 0)
        {
            ASData args;
            if (!args.SetArgsIfAny(pArgs, nArgs))
                return 0;
            int nEmoticonId = args.PopInt();
            SendMessengerMode4(nEmoticonId);
        }
        else if (_stricmp("eventChatEmoticonFavorite", szMethod) == 0)
        {
            ASData args;
            if (!args.SetArgsIfAny(pArgs, nArgs))
                return 0;
            int nEmoticonId = args.PopInt();
            bool bFavorite = args.PopBool();
            FUN_14194b190(nEmoticonId, bFavorite);
        }
        else if (_stricmp("eventChatEmoticonPush", szMethod) == 0)
        {
            ASData args;
            if (args.SetArgsIfAny(pArgs, nArgs))
            {
                CStringW strText = args.FUN_1422b8f40();
                CGroupChatManager::GetInstance()->SendGroupChatMode10(m_nGroupId, strText);
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

// @0x14194a340
void UIGroupMessenger::AddInvitedMessage(int nKind, const CStringW& strName, const CStringW& strOther)
{
    FUN_14194bde0();
    CStringW strMsg = FormatStringId<CStringW, CStringW>(0x80e, strName, strOther);
    AddSystemMessage(nKind, strName, strMsg);
}
MS2_REPLACE_METHOD(0x14194A340, UIGroupMessenger, AddInvitedMessage, 109, 0xF1D02319);

// @0x14194a3c0
void UIGroupMessenger::FUN_14194a3c0(int nKind, const CStringW& strName, int nMode)
{
    FUN_14194bde0();
    CStringW strMsg;
    if (nMode == 0)
        strMsg = FormatStringId<CStringW>(0x810, strName);
    else if (nMode == 1)
        strMsg = FormatStringId<CStringW>(0x813, strName);
    AddSystemMessage(nKind, strName, strMsg);
}
MS2_REPLACE_METHOD(0x14194A3C0, UIGroupMessenger, FUN_14194a3c0, 252, 0xF0BC3812);

// @0x14194a4d0
void UIGroupMessenger::AddMemberOnlineMessage(int nKind, const CStringW& strName)
{
    FUN_14194bde0();
    CStringW strMsg = FormatStringId<CStringW>(0x811, strName);
    AddSystemMessage(nKind, strName, strMsg);
}
MS2_REPLACE_METHOD(0x14194A4D0, UIGroupMessenger, AddMemberOnlineMessage, 99, 0xBA001AB9);

// @0x14194a540
void UIGroupMessenger::AddMemberOfflineMessage(int nKind, const CStringW& strName)
{
    FUN_14194bde0();
    CStringW strMsg = FormatStringId<CStringW>(0x812, strName);
    AddSystemMessage(nKind, strName, strMsg);
}
MS2_REPLACE_METHOD(0x14194A540, UIGroupMessenger, AddMemberOfflineMessage, 99, 0x5DE0CDB3);

// @0x14194a5b0
void UIGroupMessenger::AddChatMessage(int nKind, const CStringW& strName, const CStringW& strMsg)
{
    FUN_14194d3d0(nKind, strName, strMsg, 0);
    if (FUN_141482e80()->m_pBrowser != 0)
        FUN_141482e80()->m_pBrowser->FUN_141953810(nKind, strName, strMsg, 0, vfunc_64());
}
MS2_REPLACE_METHOD(0x14194A5B0, UIGroupMessenger, AddChatMessage, 139, 0x816186C3);

// @0x14194a650
void UIGroupMessenger::AddSystemMessage(int nKind, const CStringW& strName, const CStringW& strMsg)
{
    FUN_14194d3d0(nKind, strName, strMsg, 1);
    if (FUN_141482e80()->m_pBrowser != 0)
        FUN_141482e80()->m_pBrowser->FUN_141953810(nKind, strName, strMsg, 1, vfunc_64());
}
MS2_REPLACE_METHOD(0x14194A650, UIGroupMessenger, AddSystemMessage, 139, 0xEFB6BE61);

// @0x14194a6f0
void UIGroupMessenger::FUN_14194a6f0(NotifyObject* pNotify)
{
    NotifyChatEmoticonSelected* pSelected = dynamic_cast<NotifyChatEmoticonSelected*>(pNotify);
    if (pSelected == 0)
        return;
    if (m_30.IsNull())
        return;
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    if (pSelected->m_strTarget != m_strName)
    {
        CloseEmoticonPreview();
        return;
    }
    ChatEmoticonDataPtr spEmo = TSingleton<CChatEmoticonTable>::GetInstance()->FUN_1401e7120(pSelected->m_nEmoticonId);
    if (!spEmo)
        return;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->GetChatEmoticon();
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
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->GetChatEmoticon();
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
    ((Scaleform::GFx::Movie*)(void*)(pMovie))->CreateArray(&arr);
    const std::list<ChatEmoticonDataPtr>& rEmoticons = emoticons;
    std::list<ChatEmoticonDataPtr>::const_iterator itEnd = rEmoticons.end();
    for (std::list<ChatEmoticonDataPtr>::const_iterator it = rEmoticons.begin(); it != itEnd; ++it)
    {
        ChatEmoticonDataPtr spEmo = *it;
        if (!spEmo)
            continue;
        ASObj item(2);
        item.FUN_1409c0d20("id", spEmo->m_nId);
        item.FUN_1407cbb20("imgPath", spEmo->m_strImagePath);
        item.FUN_1407cb9c0("width", spEmo->m_nWidth);
        item.FUN_1407cb9c0("height", spEmo->m_nHeight);
        item.FUN_1407cbbe0("favorite", spCli->IsEmoticonFavorite(spEmo->m_nId));
        arr.PushBack(item.FUN_1422bb870());
    }
    if (arr.GetArraySize() <= 0)
        return;
    data.FUN_1409adbe0("emoticonDatas", arr);
    pDialog->Invoke("openChatEmoticonPreview", data.FUN_1422bb870());
}
MS2_REPLACE_METHOD(0x14194A930, UIGroupMessenger, FUN_14194a930, 1055, 0x7996AA4B);

// @0x14194ad60
void UIGroupMessenger::CloseEmoticonPreview()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog == 0)
        return;
    pDialog->Invoke("closeChatEmoticonPreview");
}
MS2_REPLACE_METHOD(0x14194AD60, UIGroupMessenger, CloseEmoticonPreview, 110, 0xF5CDBC08);

// @0x14194ade0
int UIGroupMessenger::SendMessengerMode4(int nEmoticonId)
{
    ChatEmoticonDataPtr spEmo = TSingleton<CChatEmoticonTable>::GetInstance()->FUN_1401e7120(nEmoticonId);
    if (!spEmo)
        return 0;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->GetChatEmoticon();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x4e8, 0);
        return 0;
    }
    if (!spCli->FUN_140a39dd0(spEmo->m_nId))
        return 0;
    COutPacket packet(static_cast<int>(SendOp::ChatSticker), 0);
    packet.WriteUInt8(4);
    packet.WriteInt32(nEmoticonId);
    packet.WriteUnicodeString(GetName());
    FUN_140710590(packet);
    return 1;
}
MS2_REPLACE_METHOD(0x14194ADE0, UIGroupMessenger, SendMessengerMode4, 460, 0x5BD64367);

// @0x14194afc0
void UIGroupMessenger::FUN_14194afc0(int nEmoticonId)
{
    ChatEmoticonDataPtr spEmo = TSingleton<CChatEmoticonTable>::GetInstance()->FUN_1401e7120(nEmoticonId);
    if (!spEmo)
        return;
    CStringW strSize(L"");
    if (spEmo->m_nWidth != 0 || spEmo->m_nHeight != 0)
        strSize = StringFormat(L"width='{0}' height='{1}'", spEmo->m_nWidth, spEmo->m_nHeight);
    CStringW strLine = StringFormat<unsigned, int, CStringW>(L"<img src='img://emoticon:{0}' vspace='{1}' {2} />", spEmo->m_nId,
                                     spEmo->m_nVSpace, strSize);
    CGroupChatManager::GetInstance()->SendGroupChatMode10(m_nGroupId, strLine);
}
MS2_REPLACE_METHOD(0x14194AFC0, UIGroupMessenger, FUN_14194afc0, 446, 0xADC3693B);

// @0x14194b190
int UIGroupMessenger::FUN_14194b190(int nEmoticonId, bool bFavorite)
{
    ChatEmoticonDataPtr spEmo = TSingleton<CChatEmoticonTable>::GetInstance()->FUN_1401e7120(nEmoticonId);
    if (!spEmo)
        return 0;
    MS2Ptr<CChatEmoticonCli> spCli = FUN_140931510()->GetChatEmoticon();
    if (spCli.IsNull())
    {
        MS2_ASSERT_AT(0x518, 0);
        return 0;
    }
    if (!spCli->FUN_140a39dd0(spEmo->m_nId))
        return 0;
    int nMode = bFavorite ? 5 : 6;
    COutPacket packet(static_cast<int>(SendOp::ChatSticker), 0);
    packet.WriteUInt8(nMode);
    packet.WriteInt32(nEmoticonId);
    FUN_140710590(packet);
    return 1;
}
MS2_REPLACE_METHOD(0x14194B190, UIGroupMessenger, FUN_14194b190, 446, 0x0BB5667B);

// @0x14194b360
void UIGroupMessenger::vfunc_ugc_1(void* pId, CString strText)
{
    if (vfunc_55())
        return;
    if (pId == 0)
        return;
    PCBase* pPlayer = static_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    m_nTypingTime = GetTickCountMs2();
    m_typing.SetAt((unsigned __int64)pId, strText);
}
MS2_REPLACE_METHOD_VIA(0x14194B360, UIGroupMessenger, UIUGCEventListener, vfunc_ugc_1, 204, 0x3AB617C1);

// @0x14194b440
void UIGroupMessenger::FUN_14194b440(const CStringW& strName, float x, float y)
{
    PCBase* pPlayer = static_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return;
    if (pPlayer->vfunc_77() != strName)
    {
        UIPopUpMenu* pMenu = ((class UIPopUpMenu*)FUN_140c30140(0x4e39));
        if (pMenu != 0)
        {
            Unk_PopupMenuInfo info(x, y, 3, 0x635e, 0, "", 0);
            CStringW strHistory;
            MS2Ptr<TalkLogList> spLog;
            if (FUN_141482e80()->m_pBrowser->m_logs.Lookup(m_nGroupId, spLog))
            {
                for (std::deque<CStringW>::reverse_iterator it = spLog->m_lines.rbegin(), itEnd = spLog->m_lines.rend(); it != itEnd; ++it)
                {
                    CStringW strLine(*it);
                    FUN_14083d2b0(strLine);
                    if (strHistory.GetLength() + strLine.GetLength() > 2000)
                        break;
                    strHistory.AppendFormat(strLine);
                }
            }
            Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FindChat(m_nGroupId);
            if (spChat.get())
            {
                Unk_ChatMemberPtr spMember = spChat->FindMemberByName(strName);
                if (spMember.get())
                    pMenu->OpenForUserEntry(info, reinterpret_cast<Unk_PmUserEntry*>(static_cast<CGroupChatMember*>(spMember)), strHistory, 6);
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
int UIGroupMessenger::IsUserList()
{
    return m_bUserList;
}
MS2_REPLACE_METHOD(0x14194B880, UIGroupMessenger, IsUserList, 17, 0x874475EA);

// @0x14194b8a0
CString UIGroupMessenger::GetXmlFileName()
{
    CString strFile;
    strFile.Format("%s%d.xml", (const char*)GetTypeName(), m_nIndex);
    return strFile;
}
MS2_REPLACE_METHOD(0x14194B8A0, UIGroupMessenger, GetXmlFileName, 183, 0xCC64DC7C);

// @0x14194b960
CStringW UIGroupMessenger::GetName()
{
    return m_strName;
}
MS2_REPLACE_METHOD(0x14194B960, UIGroupMessenger, GetName, 68, 0x0AB7D61B);

// @0x14194b9b0
unsigned UIGroupMessenger::GetGroupId()
{
    return m_nGroupId;
}
MS2_REPLACE_METHOD(0x14194B9B0, UIGroupMessenger, GetGroupId, 17, 0xABC1DB6D);

// @0x14194b9d0
int UIGroupMessenger::IsGroupMember(__int64 nCharacterId)
{
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FindChat(m_nGroupId);
    if ((spChat.get() ? true : false) && spChat->HasMemberById(nCharacterId))
        return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14194B9D0, UIGroupMessenger, IsGroupMember, 168, 0x604A3AB2);

// @0x14194ba80
CStringW UIGroupMessenger::FUN_14194ba80(unsigned __int64 nCharacterId)
{
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FindChat(m_nGroupId);
    if (spChat == 0)
        return L"";
    ATL::CAtlList<Unk_ChatMemberPtr> members(10);
    spChat->FUN_14137bdc0(members);
    for (POSITION pos = members.GetHeadPosition(); pos != 0; members.GetNext(pos))
    {
        Unk_ChatMemberPtr spMember = members.GetAt(pos);
        if (spMember == 0)
            continue;
        if (spMember->m_proxy.m_8 == nCharacterId)
            return spMember->m_proxy.FUN_1408f19e0();
    }
    return L"";
}
MS2_REPLACE_METHOD(0x14194BA80, UIGroupMessenger, FUN_14194ba80, 481, 0xE77E4AA1);

// @0x14194bc70
void UIGroupMessenger::SetName(CStringW strName)
{
    m_strName = strName;
}
MS2_REPLACE_METHOD(0x14194BC70, UIGroupMessenger, SetName, 65, 0x6116EF81);

// @0x14194bcc0
void UIGroupMessenger::SetInputText(CStringW strText)
{
    if (MS2Ptr<ASTextInput> spInput = reinterpret_cast<UIGameRankingDialog*>(this)->FUN_140e35bd0("m_textInput"))
    {
        vfunc_78();
        FUN_14194d100(spInput, strText, 1);
    }
    m_inputHistory.Add(strText);
}
MS2_REPLACE_METHOD(0x14194BCC0, UIGroupMessenger, SetInputText, 270, 0x53094138);

// @0x14194bde0
void UIGroupMessenger::FUN_14194bde0()
{
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FindChat(m_nGroupId);
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
void UIGroupMessenger::OnBuildScrollingList()
{
    if (m_6c != 0)
        return;
    if (m_bUserList == 0)
        return;
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FindChat(m_nGroupId);
    if (spChat == 0)
        return;
    ATL::CAtlList<Unk_ChatMemberPtr> joined(10);
    spChat->FUN_14137bdc0(joined);
    ATL::CAtlList<Unk_ChatMemberPtr> invited(10);
    spChat->FUN_14137bee0(invited);
    if (MS2Ptr<ASScrollingList> spList = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02900("m_userList"))
    {
        spList->FUN_1422dd1d0();
        static_cast<Unk_GrmControl*>(static_cast<ASUIComponent*>(spList.operator->()))->vfunc_24(1);   // slot 24 validateNow
        for (POSITION pos = joined.GetHeadPosition(); pos != 0; joined.GetNext(pos))
        {
            Unk_ChatMemberPtr spMember = joined.GetAt(pos);
            if (spMember == 0)
                continue;
            Unk_MdEntry entry(reinterpret_cast<Unk_MdSrcD&>(*spMember.get()));
            ASObj item(2);
            item.FUN_1407cb9c0(s_strOnline, entry.GetKind());
            item.FUN_1407cbb20(s_strIconPath, entry.GetImage());
            item.FUN_1407cbb20(s_strCharacterName, entry.GetName());
            item.FUN_1407cbb20(s_strLevelAndJobName, entry.GetInfo());
            spList->AddItem(item);
        }
        for (POSITION pos = invited.GetHeadPosition(); pos != 0; invited.GetNext(pos))
        {
            Unk_ChatMemberPtr spMember = invited.GetAt(pos);
            if (spMember == 0)
                continue;
            Unk_MdEntry entry(reinterpret_cast<Unk_MdSrcD&>(*spMember.get()));
            ASObj item(2);
            item.FUN_1407cb9c0(s_strOnline, entry.GetKind());
            item.FUN_1407cbb20(s_strIconPath, entry.GetImage());
            item.FUN_1407cbb20(s_strCharacterName, entry.GetName());
            item.FUN_1407cbb20(s_strLevelAndJobName, entry.GetInfo());
            spList->AddItem(item);
        }
        unsigned nRows;
        if (spList->GetItemCount() > 8)
            nRows = 8;
        else
            nRows = spList->GetItemCount();
        spList->SetRowCount(nRows);
        static_cast<Unk_GrmControl*>(static_cast<ASUIComponent*>(spList.operator->()))->vfunc_24(1);   // slot 24 validateNow
    }
}

// @0x14194c6d0
int UIGroupMessenger::FUN_14194c6d0()
{
    if (vfunc_64())
        return 0;
    if (FUN_141482e80()->FUN_1414829e0() != m_strName)
        return 0;
    if (MS2Ptr<ASTextInput> spInput = reinterpret_cast<UIGameRankingDialog*>(this)->FUN_140e35bd0("m_textInput"))
    {
        if (spInput->GetFocused())
            return 1;
    }
    if (CUIService::GetInstance()->FUN_141adbb00() != 0)
        return 0;
    return 1;
}
MS2_REPLACE_METHOD(0x14194C6D0, UIGroupMessenger, FUN_14194c6d0, 331, 0xF9EA75FE);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x14194c830
int UIGroupMessenger::FUN_14194c830()
{
    MS2Ptr<ASTextInput> spInput = reinterpret_cast<UIGameRankingDialog*>(this)->FUN_140e35bd0("m_textInput");
    if (spInput == 0)
        return 0;
    CStringW strText = spInput->GetText();
    strText = strText.Trim();
    if (strText.IsEmpty())
    {
        ClearInput();
        return 0;
    }
    CStringW strHtml = spInput->GetHtmlText();
    bool bHtml = FUN_140d2aa60(strHtml);
    if (bHtml)
    {
        if (CBanTextChecker* pChecker = CommonString::GetInstance()->GetChecker())
        {
            pChecker->MaskBannedWords(strHtml);
            pChecker->FilterReservedWords(strHtml);
        }
        FUN_140d2c650(strHtml);
        CGroupChatManager::GetInstance()->SendGroupChatMode10(m_nGroupId, strHtml);
    }
    else
    {
        if (CBanTextChecker* pChecker = CommonString::GetInstance()->GetChecker())
        {
            pChecker->MaskBannedWords(strText);
            pChecker->FilterReservedWords(strText);
        }
        strText = FUN_141842320(strText);
        CGroupChatManager::GetInstance()->SendGroupChatMode10(m_nGroupId, strText);
    }
    ClearInput();
    return 1;
}
MS2_REPLACE_METHOD(0x14194C830, UIGroupMessenger, FUN_14194c830, 884, 0x4FB1EAAB);

// @0x14194cbb0
int UIGroupMessenger::FUN_14194cbb0()
{
    if (MS2Ptr<ASTextInput> spInput = reinterpret_cast<UIGameRankingDialog*>(this)->FUN_140e35bd0("m_textInput"))
    {
        if (spInput->GetFocused())
        {
            FUN_14194c830();
        }
        else
        {
            int nLength = spInput->GetText().GetLength();
            spInput->SetFocused(1);
            spInput->FocusAndSetSelection(nLength, nLength);
            spInput->vfunc_24(1);
        }
    }
    return 1;
}
MS2_REPLACE_METHOD(0x14194CBB0, UIGroupMessenger, FUN_14194cbb0, 322, 0x0B436CC5);

// @0x14194cd00
int UIGroupMessenger::ClearInput()
{
    if (MS2Ptr<ASTextInput> spInput = reinterpret_cast<UIGameRankingDialog*>(this)->FUN_140e35bd0("m_textInput"))
    {
        if (spInput->GetFocused())
        {
            m_inputHistory.RemoveAll();
            spInput->SetFocused(0);
            spInput->SetHtmlTextW(L"<FONT></FONT>");
            spInput->vfunc_24(1);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14194CD00, UIGroupMessenger, ClearInput, 314, 0x168DA538);

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
        UIGroupMessenger* pOther = FUN_141482e80()->m_pBrowser->FindWindowByName(strName);
        if (pOther != 0 && pOther != this)
        {
            if (MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0, GetStringCommon(0x817), 0, L""))
                FUN_140d73c60(spBox);
            return 1;
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14194CE40, UIGroupMessenger, FUN_14194ce40, 696, 0xB730CB0A);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x14194d100
void UIGroupMessenger::FUN_14194d100(MS2Ptr<ASTextInput> spInput, const CStringW& strText, int bSelectEnd)
{
    CStringW strCurrent = spInput->GetText();
    if (strCurrent.GetLength() >= spInput->GetMaxChars())
        return;
    CStringW strSpace(L" ");
    CStringW strHtml = spInput->GetHtmlText();
    unsigned int nTotal = strHtml.GetLength() + strSpace.GetLength() + strText.GetLength();
    if (nTotal >= 0x800)
        return;
    spInput->SetHtmlTextW(strHtml + strText + strSpace);
    spInput->vfunc_24(1);
    int nLength = spInput->GetText().GetLength();
    if (bSelectEnd && nLength > 0)
        spInput->FocusAndSetSelection(nLength, nLength);
    spInput->vfunc_24(1);
}
MS2_REPLACE_METHOD(0x14194D100, UIGroupMessenger, FUN_14194d100, 701, 0x77104F6D);

// MS2-FUNCTIONAL: control flow / temporaries differ from the exe (functional-first)
// @0x14194d3d0
void UIGroupMessenger::FUN_14194d3d0(int nKind, const CStringW& strName, const CStringW& strMsg, int bSystem)
{
    if (MS2Ptr<ASScrollingList> spOutput = reinterpret_cast<UIDailyMissionDialog*>(this)->FUN_140c02900("m_textOutput"))
    {
        bool bVisibleBg = ShowsLineBackground(strMsg);
        CStringW strFrame = GetMessageFrameName(strName, bSystem);
        CString strIcon = FUN_1414842b0(nKind, strName);
        ASObj item(2);
        item.FUN_1407cbb20(s_strFrame, strFrame);
        item.FUN_1407cbb20(s_strText, strMsg);
        item.FUN_1407cba60(s_strIconPath, strIcon);
        item.FUN_1407cbb20(s_strCharacterName, strName);
        item.FUN_1407cbbe0("visibleBg", bVisibleBg);
        spOutput->AddItem(item);
        spOutput->vfunc_24(1);
        spOutput->FUN_1422e17a0();
    }
}

// @0x14194d6f0
void UIGroupMessenger::FUN_14194d6f0()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog != 0)
    {
        for (POSITION pos = m_typing.GetStartPosition(); pos != 0; m_typing.GetNext(pos))
        {
            unsigned __int64 nId = m_typing.GetKeyAt(pos);
            CString strProfile(m_typing.GetValueAt(pos));
            CString strImage = FUN_141028be0(nId, strProfile, 1, "");
            pDialog->Invoke("updateProfile", FUN_14194ba80(nId), CString(strImage));
        }
    }
}
MS2_REPLACE_METHOD(0x14194D6F0, UIGroupMessenger, FUN_14194d6f0, 498, 0x612545BC);

// @0x14194d8f0
CStringW UIGroupMessenger::GetMessageFrameName(const CStringW& strName, int bSystem)
{
    PCBase* pPlayer = static_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (bSystem)
        return L"notify";
    if (pPlayer != 0 && pPlayer->vfunc_77() == strName)
        return L"me";
    return L"other";
}
MS2_REPLACE(0x14194D8F0, UIGroupMessenger::GetMessageFrameName, 299, 0xBD408FB8);

// @0x14194da30
bool UIGroupMessenger::ShowsLineBackground(CStringW strMsg)
{
    if (strMsg.IsEmpty())
        return true;
    if (strMsg.GetAt(0) != L'<')
        return true;
    strMsg.MakeLower();
    if (strMsg.Find(L"img://emoticon:") != -1)
        return false;
    return true;
}
MS2_REPLACE(0x14194DA30, UIGroupMessenger::ShowsLineBackground, 189, 0xD3318D3F);

// @0x14194dd10
UIInviteGroupDialog* FUN_14194dd10(int nUiId)
{
    if (CUIService::GetInstance() != 0)
    {
        MS2Ptr<UIObject> spObj = CUIService::GetInstance()->FindObject((eUIClassID)nUiId);
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

MS2Ptr<CMsgBoxData> FUN_14151f820();                                // the shown message box
CStringW BlockFormat(int nStringId);
class Unk_MeratBlindManager* FUN_1409c1730();   // C3: was FUN_1409c1730
__int64 GetServerTime();                                            // the server time (epoch seconds)
bool FUN_140d2c080(CStringW strText, ATL::CAtlList<CStringW>& links, CStringW strBegin, CStringW strEnd);
__int64 FUN_140d2caf0(const CStringW& strLink);                     // an item link's uid
CStringW FUN_14183e930(const CStringW& strText, unsigned nColor);        // colours a text
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
CString UIGroupMessengerBrowser::GetTypeName()
{
    return "GroupMessengerBrowser";
}
MS2_REPLACE_METHOD(0x1419509C0, UIGroupMessengerBrowser, GetTypeName, 61, 0xA7FDB2D8);

// @0x141950a10
void UIGroupMessengerBrowser::vfunc_67()
{
    UIDialog::vfunc_67();
    ATL::CAtlArray<MS2Ptr<UIGroupMessenger> > windows;
    for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow == 0)
            continue;
        MS2Ptr<UIGroupMessenger> spWindow(pWindow);
        windows.Add(spWindow);
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
        XmlSetAttr((class TiXmlElement*)(pCfg), "offsetX", m_fOffsetX);
        XmlSetAttr((class TiXmlElement*)(pCfg), "offsetY", m_fOffsetY);
        XmlSetAttr((class TiXmlElement*)(pCfg), "alignType", m_nAlignType);
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
        XmlGetAttr((class TiXmlElement*)(pCfg), "offsetX", *(float*)(&m_fOffsetX));
        XmlGetAttr((class TiXmlElement*)(pCfg), "offsetY", *(float*)(&m_fOffsetY));
        XmlGetAttr((class TiXmlElement*)(pCfg), "alignType", m_nAlignType);
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
        int nResult = pMsg->PopInt();
        Scaleform::GFx::Value root = static_cast<Unk_GrmMsg*>(pMsg)->PopValue();
        if (strTag == s_strGroupList)
        {
            int bDone = 0;
            if (nResult == 0)
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_14151f820();
                if (spBox.get())
                {
                    CStringW strText = spBox->FUN_141a02d00();
                    ASObj box(root, 2);
                    if (MS2Ptr<ASDropdownMenu> spGroups = box.GetDropdownMenu("m_dropdown"))
                    {
                        CStringW strGroup = spGroups->FUN_1422dfe00();
                        UIGroupMessenger* pWindow = FindWindowByName(strGroup);
                        if (pWindow != 0)
                        {
                            bDone = 1;
                            FUN_14151f200();
                            CGroupChatManager::GetInstance()->Invite(pWindow->GetGroupId(), strText);
                        }
                        else
                        {
                            bDone = 1;
                            FUN_14151f200();
                            CGroupChatManager::GetInstance()->Create(strText);
                        }
                    }
                }
            }
            if (!bDone)
                FUN_14151f200();
        }
    }
    return 0;
}

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
    else if (_stricmp("OnToggleDialog", szMethod) == 0)
    {
        ASData args;
        if (args.SetArgsIfAny(pArgs, nArgs))
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
            UIGroupMessenger* pWindow = FindWindowByGroupId(result.GetMode());
            if (pWindow != 0)
            {
                pWindow->SetName(entry.m_strName);
                pWindow->FUN_14194bde0();
            }
        }
        else
        {
            FUN_140d73aa0(BlockFormat(0x8b7), 0, 0, L"");
        }
    }
}
MS2_REPLACE_METHOD(0x1419512F0, UIGroupMessengerBrowser, vfunc_80, 377, 0x139CC221);

// @0x141951470
void UIGroupMessengerBrowser::vfunc_15()
{
    if (m_68 != 0)
        return;
    if (m_4c == 0)
        return;
    UISwfEntity::vfunc_15();
    if (!m_pending.IsEmpty())
    {
        POSITION pos = m_pending.GetHeadPosition();
        while (pos != 0)
        {
            TalkLog& log = m_pending.GetNext(pos);
            CStringW strMsg = FUN_141953b10(log.m_strName);
            UIGroupMessenger* pWindow = FindWindowByGroupId(log.m_nKind);
            if (pWindow != 0)
            {
                pWindow->AddChatMessage(log.m_nKind, log.m_strMsg, strMsg);
                if (pWindow->vfunc_64())
                    FUN_141952530();
            }
        }
        m_pending.RemoveAll();
    }
}
MS2_REPLACE_METHOD(0x141951470, UIGroupMessengerBrowser, vfunc_15, 323, 0x51F96ABA);

// @0x1419515c0
void UIGroupMessengerBrowser::OnChatCreated(int nGroupId)
{
    m_logs.SetAt(nGroupId, new TalkLogList());
    FUN_141952d80(nGroupId, 1, 0);
    UIGroupMessenger* pWindow = FindWindowByGroupId(nGroupId);
    if (pWindow != 0)
        FUN_141482e80()->FUN_141482c80(pWindow->GetName());
    FUN_141276180(s_strButtonClick, "");
}

// @0x141951720
void UIGroupMessengerBrowser::FUN_141951720(int nGroupId, const CStringW& strName, const CStringW& strText)
{
    UIGroupMessenger* pWindow = FindWindowByGroupId(nGroupId);
    if (pWindow != 0)
        pWindow->FUN_14194a320(nGroupId, strName, strText);
    UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
    if (pInvite != 0)
        pInvite->FUN_14199fd10(nGroupId, strName, strText);
}
MS2_REPLACE_METHOD(0x141951720, UIGroupMessengerBrowser, FUN_141951720, 126, 0x0701CC9B);

// @0x1419517b0
void UIGroupMessengerBrowser::FUN_1419517b0(int nGroupId, const CStringW& strName, const CStringW& strOther)
{
    m_logs.SetAt(nGroupId, new TalkLogList());
    FUN_141952d80(nGroupId, 1, 1);
    FUN_141276180(s_strSystemGroupChat, "");
    FUN_1412751f0(FormatStringId<CStringW>(0x80f, strName), 3, 1);
    UIGroupMessenger* pWindow = FindWindowByGroupId(nGroupId);
    if (pWindow != 0)
    {
        pWindow->AddSystemMessage(nGroupId, strName, FormatStringId<CStringW, CStringW>(0x80e, strName, strOther));
        if (pWindow->vfunc_64())
            FUN_141952530();
    }
}

// @0x1419519a0
void UIGroupMessengerBrowser::RemoveGroup(int nGroupId)
{
    m_logs.RemoveKey(nGroupId);
    CloseGroupWindow(nGroupId);
}
MS2_REPLACE_METHOD(0x1419519A0, UIGroupMessengerBrowser, RemoveGroup, 55, 0x80CDBA28);

// @0x1419519e0
void UIGroupMessengerBrowser::OnMemberInvited(int nGroupId, const CStringW& strName, const CStringW& strOther)
{
    UIGroupMessenger* pWindow = FindWindowByGroupId(nGroupId);
    if (pWindow != 0)
        pWindow->AddInvitedMessage(nGroupId, strName, strOther);
    UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
    if (pInvite != 0)
        pInvite->FUN_14199fd60(nGroupId, strName, strOther);
}
MS2_REPLACE_METHOD(0x1419519E0, UIGroupMessengerBrowser, OnMemberInvited, 126, 0xC503682C);

// @0x141951a70
void UIGroupMessengerBrowser::FUN_141951a70(int nGroupId, const CStringW& strName, int nMode)
{
    UIGroupMessenger* pWindow = FindWindowByGroupId(nGroupId);
    if (pWindow != 0)
        pWindow->FUN_14194a3c0(nGroupId, strName, nMode);
    UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
    if (pInvite != 0)
        pInvite->FUN_14199fdb0(nGroupId, strName);
}
MS2_REPLACE_METHOD(0x141951A70, UIGroupMessengerBrowser, FUN_141951a70, 121, 0x1BF01CE1);

// @0x141951af0
void UIGroupMessengerBrowser::OnGroupMemberOnline(int nGroupId, const CStringW& strName)
{
    UIGroupMessenger* pWindow = FindWindowByGroupId(nGroupId);
    if (pWindow != 0)
        pWindow->AddMemberOnlineMessage(nGroupId, strName);
    UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
    if (pInvite != 0)
        pInvite->FUN_14199fdf0(nGroupId, strName);
}
MS2_REPLACE_METHOD(0x141951AF0, UIGroupMessengerBrowser, OnGroupMemberOnline, 111, 0xCDEE56EC);

// @0x141951b70
void UIGroupMessengerBrowser::OnGroupMemberOffline(int nGroupId, const CStringW& strName)
{
    UIGroupMessenger* pWindow = FindWindowByGroupId(nGroupId);
    if (pWindow != 0)
        pWindow->AddMemberOfflineMessage(nGroupId, strName);
    UIInviteGroupDialog* pInvite = FUN_14194dd10(0x4e90);
    if (pInvite != 0)
        pInvite->FUN_14199fe30(nGroupId, strName);
}
MS2_REPLACE_METHOD(0x141951B70, UIGroupMessengerBrowser, OnGroupMemberOffline, 111, 0x08E085A3);

// @0x141951bf0
void UIGroupMessengerBrowser::AddNoticeLine(int nGroupId, const CStringW& strName, const CStringW& strMsg)
{
    UIGroupMessenger* pWindow = FindWindowByGroupId(nGroupId);
    if (pWindow != 0)
        pWindow->AddSystemMessage(nGroupId, strName, strMsg);
}
MS2_REPLACE_METHOD(0x141951BF0, UIGroupMessengerBrowser, AddNoticeLine, 79, 0xBE8B028E);

// @0x141951c50
void UIGroupMessengerBrowser::QueueTalkLog(int nGroupId, const CStringW& strName, const CStringW& strMsg)
{
    if (((class BlindManager*)FUN_1409c1730())->IsBlocked(0, strName))
        return;
    m_pending.AddTail(TalkLog(nGroupId, strMsg, strName));
}
MS2_REPLACE_METHOD(0x141951C50, UIGroupMessengerBrowser, QueueTalkLog, 290, 0x441E5D4D);

// @0x141951d80
void UIGroupMessengerBrowser::FUN_141951d80(int nGroupId, const CStringW& strName, CInPacket* pPacket)
{
    unsigned nCount = pPacket->ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        __int64 nUid = pPacket->ReadInt64();
        int nItemId = pPacket->ReadInt32();
        int nRarity = pPacket->ReadInt32();
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_140523c40(nItemId, nRarity, 0))
        {
            spItem->SetObjectId(DAT_143ab2864);
            spItem->FUN_140524eb0(*pPacket);
            m_items.SetAt(nUid, spItem);
        }
    }
}
MS2_REPLACE_METHOD(0x141951D80, UIGroupMessengerBrowser, FUN_141951d80, 490, 0xBC44B2DC);

// @0x141951f70
void UIGroupMessengerBrowser::FUN_141951f70(const CStringW& strText)
{
    int nCount = CGroupChatManager::GetInstance()->GetChatCount();
    if (nCount == 0)
    {
        CGroupChatManager::GetInstance()->Create(strText);
    }
    else if (nCount < 3)
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x16, GetStringCommon(0x81a), static_cast<IMessageListener*>(this), s_strGroupList);
        if (spBox.get())
        {
            ATL::CAtlList<CStringW> choices(10);
            choices.AddTail(GetStringCommon(0x5d1));
            for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
            {
                UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
                if (pWindow == 0)
                    continue;
                choices.AddTail(pWindow->GetName());
            }
            spBox->FUN_141a02b00(strText, choices);
            FUN_140d73c60(spBox);
        }
    }
    else
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x16, GetStringCommon(0x81a), static_cast<IMessageListener*>(this), s_strGroupList);
        if (spBox.get())
        {
            ATL::CAtlList<CStringW> choices(10);
            choices.AddTail(GetStringCommon(0x5d1));
            for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
            {
                UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
                if (pWindow == 0)
                    continue;
                choices.AddTail(pWindow->GetName());
            }
            spBox->FUN_141a02b00(strText, choices);
            FUN_140d73c60(spBox);
        }
    }
}

// @0x1419524e0
void UIGroupMessengerBrowser::ClearAll()
{
    FUN_141482e80()->FUN_141482b70();
    m_logs.RemoveAll();
    m_pending.RemoveAll();
}
MS2_REPLACE_METHOD(0x1419524E0, UIGroupMessengerBrowser, ClearAll, 65, 0x08A06B2A);

// @0x141952530
void UIGroupMessengerBrowser::FUN_141952530()
{
    ASDialog* pDialog = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDialog)
    {
        ASArray windows(2);
        for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
        {
            UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
            if (pWindow == 0)
                continue;
            ASObj item(2);
            item.FUN_1409c0d20("number", FUN_141952a30(pWindow->GetGroupId()));
            item.FUN_1407cbb20("name", pWindow->GetName());
            item.FUN_1407cb9c0("minimize", pWindow->vfunc_64());
            windows.PushValue(item.FUN_1422bb870());
        }
        pDialog->Invoke("setData", windows.FUN_1422bb870());
    }
}
MS2_REPLACE_METHOD(0x141952530, UIGroupMessengerBrowser, FUN_141952530, 579, 0x8F780D0B);

// @0x141952780
int UIGroupMessengerBrowser::FUN_141952780()
{
    int bMinimized = 0;
    for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow == 0)
            continue;
        if (pWindow->vfunc_64() == 0)
        {
            bMinimized = 1;
            pWindow->vfunc_69();
        }
    }
    return bMinimized;
}
MS2_REPLACE_METHOD(0x141952780, UIGroupMessengerBrowser, FUN_141952780, 178, 0x3F984899);

// @0x141952840
int UIGroupMessengerBrowser::FUN_141952840()
{
    for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow == 0)
            continue;
        if (pWindow->vfunc_55() != 0)
            continue;
        if (pWindow->vfunc_64() == 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141952840, UIGroupMessengerBrowser, FUN_141952840, 176, 0xFA7309D9);

// @0x141952900
unsigned UIGroupMessengerBrowser::FindFreeWindowSlot()
{
    for (unsigned i = 0; i < 3; i++)
    {
        if (m_windows.Lookup(i) != 0)
            continue;
        return i;
    }
    return 3;
}
MS2_REPLACE_METHOD(0x141952900, UIGroupMessengerBrowser, FindFreeWindowSlot, 82, 0x18D7270B);

// @0x141952960
void UIGroupMessengerBrowser::FUN_141952960(unsigned nGroupId)
{
    MS2Ptr<TalkLogList> spLog;
    if (m_logs.Lookup(nGroupId, spLog))
    {
        for (unsigned i = 0; i < spLog->m_logs.GetCount(); i++)
        {
            TalkLog* pLog = &spLog->m_logs[i];
            FUN_141484270(pLog);
        }
    }
}
MS2_REPLACE_METHOD(0x141952960, UIGroupMessengerBrowser, FUN_141952960, 200, 0x44FE2226);

// @0x141952a30
int UIGroupMessengerBrowser::FUN_141952a30(unsigned nGroupId)
{
    int nCount = 0;
    MS2Ptr<TalkLogList> spLog;
    if (m_logs.Lookup(nGroupId, spLog))
    {
        for (unsigned i = 0; i < spLog->m_logs.GetCount(); i++)
        {
            TalkLog* pLog = &spLog->m_logs[i];
            if (FUN_141484290(pLog))
                nCount++;
        }
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x141952A30, UIGroupMessengerBrowser, FUN_141952a30, 238, 0xA2A41905);

// @0x141952b30
int UIGroupMessengerBrowser::FUN_141952b30(unsigned nGroupId)
{
    int nCount = 0;
    MS2Ptr<TalkLogList> spLog;
    if (m_logs.Lookup(nGroupId, spLog))
    {
        nCount = (int)(spLog->m_logs.GetCount() - (unsigned)FUN_141952a30(nGroupId));
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x141952B30, UIGroupMessengerBrowser, FUN_141952b30, 161, 0x0A7AEDC7);

// @0x141952be0
int UIGroupMessengerBrowser::FUN_141952be0()
{
    PCBase* pPlayer = static_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd0cc0());
    if (pPlayer == 0)
        return 0;
    ATL::CAtlList<unsigned> groups(10);
    CGroupChatManager::GetInstance()->FindChatsWithMember(pPlayer->FUN_141656a80(), groups);
    for (POSITION pos = groups.GetHeadPosition(); pos != 0; groups.GetNext(pos))
    {
        unsigned nGroupId = groups.GetAt(pos);
        if (m_logs.Lookup(nGroupId) == 0)
            m_logs.SetAt(nGroupId, new TalkLogList());
        FUN_141952d80(nGroupId, 0, 0);
    }
    return 1;
}

// @0x141952d80
int UIGroupMessengerBrowser::FUN_141952d80(unsigned nGroupId, int bDeleteSave, int bMinimized)
{
    if (m_windows.GetCount() >= 3)
        return 0;
    Unk_ChatPtrChat spChat = CGroupChatManager::GetInstance()->FindChat(nGroupId);
    if (spChat == 0)
        return 0;
    CloseGroupWindow(nGroupId);
    unsigned nSlot = FindFreeWindowSlot();
    UIGroupMessenger* pWindow = new UIGroupMessenger(nGroupId, nSlot, bDeleteSave);
    if (pWindow->vfunc_65() != 0)
    {
        if (bDeleteSave)
            pWindow->vfunc_63(bMinimized);
        m_windows.SetAt(nSlot, pWindow);
        return 1;
    }
    return 0;
}

// @0x141952f20
UIGroupMessenger* UIGroupMessengerBrowser::FindWindowByGroupId(int nGroupId)
{
    for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow == 0)
            continue;
        if (pWindow->GetGroupId() == nGroupId)
            return pWindow;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141952F20, UIGroupMessengerBrowser, FindWindowByGroupId, 145, 0x408E827A);

// @0x141952fc0
UIGroupMessenger* UIGroupMessengerBrowser::FindWindowByName(const CStringW& strName)
{
    for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow == 0)
            continue;
        if (pWindow->GetName() == strName)
            return pWindow;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141952FC0, UIGroupMessengerBrowser, FindWindowByName, 192, 0x8B12CA66);

// @0x141953090
void UIGroupMessengerBrowser::FUN_141953090(const CStringW& strName)
{
    UIGroupMessenger* pWindow = FindWindowByName(strName);
    if (pWindow != 0 && pWindow->GetName() == strName)
    {
        pWindow->vfunc_63(0);
        FUN_141952530();
    }
}
MS2_REPLACE_METHOD(0x141953090, UIGroupMessengerBrowser, FUN_141953090, 202, 0xD6C75BFA);

// @0x141953160
void UIGroupMessengerBrowser::FUN_141953160(const CStringW& strName)
{
    UIGroupMessenger* pWindow = FindWindowByName(strName);
    if (pWindow != 0 && pWindow->GetName() == strName)
    {
        pWindow->vfunc_63(1);
        FUN_141952530();
    }
}
MS2_REPLACE_METHOD(0x141953160, UIGroupMessengerBrowser, FUN_141953160, 205, 0xA33C9EAF);

// @0x141953240
void UIGroupMessengerBrowser::FUN_141953240(const CStringW& strName)
{
    UIGroupMessenger* pWindow = FindWindowByName(strName);
    if (pWindow != 0)
    {
        if (pWindow->vfunc_64())
            pWindow->vfunc_63(0);
        else
            pWindow->vfunc_63(1);
        FUN_141952530();
    }
}
MS2_REPLACE_METHOD(0x141953240, UIGroupMessengerBrowser, FUN_141953240, 127, 0x1F711C0A);

// @0x1419532d0
void UIGroupMessengerBrowser::CloseGroupWindow(int nGroupId)
{
    MS2Ptr<UIGroupMessenger> spClosed(0);
    for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0 && pWindow->GetGroupId() == nGroupId)
        {
            spClosed.AssignRaw(pWindow);
            FUN_141482e80()->FUN_141482d30(pWindow->GetName());
            pWindow->vfunc_84(1);
            m_windows.RemoveAtPos(pos);
            FUN_141952530();
            break;
        }
    }
    if (spClosed.get())
        spClosed->vfunc_67();
}
MS2_REPLACE_METHOD(0x1419532D0, UIGroupMessengerBrowser, CloseGroupWindow, 383, 0x00E95FD5);

// @0x141953460
void UIGroupMessengerBrowser::FUN_141953460(const CStringW& strName)
{
    MS2Ptr<UIGroupMessenger> spClosed(0);
    for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0 && pWindow->GetName() == strName)
        {
            spClosed.AssignRaw(pWindow);
            FUN_141482e80()->FUN_141482d30(pWindow->GetName());
            pWindow->vfunc_84(1);
            m_windows.RemoveAtPos(pos);
            FUN_141952530();
            break;
        }
    }
    if (spClosed.get())
        spClosed->vfunc_67();
}
MS2_REPLACE_METHOD(0x141953460, UIGroupMessengerBrowser, FUN_141953460, 500, 0x19831DD4);

// @0x141953660
void UIGroupMessengerBrowser::FUN_141953660(CStringW strText)
{
    for (POSITION pos = m_windows.GetStartPosition(); pos != 0; m_windows.GetNext(pos))
    {
        UIGroupMessenger* pWindow = m_windows.GetValueAt(pos);
        if (pWindow != 0 && FUN_141482e80()->FUN_1414829e0() == pWindow->GetName())
            pWindow->SetInputText(strText);
    }
}
MS2_REPLACE_METHOD(0x141953660, UIGroupMessengerBrowser, FUN_141953660, 412, 0x0972322B);

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
        CMsTime now(GetServerTime());
        int nHour = now.GetHour();
        int nMinute = now.GetMinute();
        int nSecond = now.GetSecond();
        strLine.Format(L"[%2d:%2d:%2d][Group][%s] %s\n", nHour, nMinute, nSecond, (const wchar_t*)strName,
                       (const wchar_t*)strMsg);
        spLog->m_lines.push_back(strLine);
    }
}

// @0x141953b10
CStringW UIGroupMessengerBrowser::FUN_141953b10(const CStringW& strMsg)
{
    CStringW strHtml(strMsg);
    ATL::CAtlList<CStringW> links(10);
    if (!FUN_140d2c080(strHtml, links, L"<A HREF=", L"/A>"))
        return strMsg;
    for (POSITION pos = links.GetHeadPosition(); pos != 0; links.GetNext(pos))
    {
        CStringW strLink(links.GetAt(pos));
        __int64 nUid = FUN_140d2caf0(strLink);
        int nColor = 0xffffff;
        {
            MS2Ptr<CItem> spItem = FindItemByUid(nUid);
            if (spItem.get())
                nColor = TSingleton<CItemDataTable>::GetInstance()->GetTextColor((ItemGradeKey)spItem->GetRarity());
        }
        CStringW strColored = FUN_14183e930(strLink, nColor);
        strHtml.Replace(strLink, strColored);
    }
    return strHtml;
}
MS2_REPLACE_METHOD(0x141953B10, UIGroupMessengerBrowser, FUN_141953b10, 719, 0x1FCCFF0C);

// @0x141953df0
MS2Ptr<CItem> UIGroupMessengerBrowser::FindItemByUid(__int64 nUid)
{
    MS2Ptr<CItem> spItem;
    if (m_items.Lookup(nUid, spItem))
        return spItem;
    return MS2Ptr<CItem>(0);
}
MS2_REPLACE_METHOD(0x141953DF0, UIGroupMessengerBrowser, FindItemByUid, 169, 0xB578D5C7);

// @0x141956220
int UIGroupMessengerBrowser::vfunc_48()
{
    return 0x4e93;
}
MS2_REPLACE_METHOD(0x141956220, UIGroupMessengerBrowser, vfunc_48, 11, 0xF77482E4);

// The range holds two of the CRT's static-inline memmove_s copies (the window's and the tray's TU tails).
// @0x141959210
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbe280-0x142cbe500 .text$yd
