// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIInventoryDialog (the inventory window, see
// uiinventorydialog.h), UIInviteGroupDialog and the item break dialogs.
// MS2-UNIT: client\ms2\uiinventorydialog.cpp
// MS2-RANGE: 0x141996ec0-0x1419abdd0 .text$mn
// MS2-RANGE: 0x140114d00-0x140115140 .text$di
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local views");
// their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uiinventorydialog.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "uiinventorydialog.h"
#include "uiinvitegroupdialog.h"
#include "uiitembreakdialog.h"

#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include "ms2/ms2format.h"
#include <map>
#include "ms2/client/ms2/buddymanager.h"
#include "ms2/client/ms2/groupchatmanager.h"
#include "ms2/client/ms2/inventory.h"
#include "ms2/client/ms2/partymanager.h"
#include "ms2/client/ms2/invenslot.h"
#include "ms2/client/ms2/mypc.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/uimessagebox.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/uiscenelobbyselect.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/commonfiles/commonstringtable.h"
#include "ms2/commonfiles/guilddef_1.h"
#include "ms2/commonfiles/itembreakmanager.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/asbuttonbar.h"
#include "ms2/placeholder/ascorelist.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astextinput.h"
#include "ms2/placeholder/astilelist.h"
#include "ms2/placeholder/asuicomponent.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/ctalkscript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxexception.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/uiswfentitymanager.h"
#include "ms2/placeholder/uistatuseventdispatcher.h"
#include "ms2/placeholder/uitalkmanager.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/unk_blocklist.h"
#include "ms2/placeholder/chomeprivilege.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of exe objects (names assumed; layouts only as far as this unit reads them) ----------------------

// The movie root of every dialog.
class ASDialog : public ASUIComponent
{
};

// "m_itemBagEx": the tile list of the bag. Slot 24 (+0xc0) redraws it, slot 25 (+0xc8) sets the data provider.
class Unk_InvItemBag : public ASTileList
{
public:
#define INV_V(n) virtual void vfunc_##n();
    INV_V(16) INV_V(17) INV_V(18) INV_V(19) INV_V(20) INV_V(21) INV_V(22) INV_V(23)
    virtual void vfunc_24(int bRefresh);                            // 24 (+0xc0) validateNow
    virtual void vfunc_25(const Scaleform::GFx::Value& provider);   // 25 (+0xc8) dataProvider
    void FUN_1422cf4f0(int nRow);                                   // scroll to a row
    int FUN_1422cf520();                                            // the scroll position
};

// "m_expand": the slot count label.
class Unk_InvExpandLabel : public ASUIComponent
{
public:
    INV_V(16) INV_V(17) INV_V(18) INV_V(19) INV_V(20) INV_V(21) INV_V(22) INV_V(23)
    virtual void vfunc_24(int bRefresh);                            // 24 (+0xc0)
    void FUN_1422e4a50(const CStringW& strText);                    // set the text
};

// The search input's extra calls.
class Unk_InvInput : public ASTextInput
{
public:
    void FUN_1422e0bd0(const CStringW& strHtml);                    // set the html text
};

// The tab bar's data provider setter.
class Unk_InvTabBar : public ASButtonBar
{
public:
    void FUN_1422e2db0(const Scaleform::GFx::Value& provider);
};

// The "m_itemBreak" button: enabled state.
class Unk_InvButton : public ASUIComponent
{
public:
    int FUN_1422c2030();                                            // enabled
};

// The index event of a button bar callback.
class Unk_InvListEventBase : public ASData
{
public:
    ~Unk_InvListEventBase();                                        // 0x1422e22a0
};
class ASIndexEvent : public Unk_InvListEventBase
{
public:
    ASIndexEvent(const Scaleform::GFx::FunctionHandler::Params& params);    // 0x1422e2a60
    ~ASIndexEvent() {}
    int FUN_1422e2aa0();                                            // the index
    Scaleform::GFx::Value FUN_1422e2b60();                          // the item
};
bool FUN_1409b0390(Scaleform::GFx::Value* pValue);                  // undefined
int FUN_1409c1750(const Scaleform::GFx::Value& v);                  // the value as an int

// The movie manager's key focus.
class Unk_InvSwfManager : public UISwfEntityManager
{
public:
    int FUN_1422d4e20(const CString& strKey);                       // has the key focus
    void FUN_1422d4dd0(const CString& strKey);                      // take the key focus
};

// The local player.
class Unk_InvWorld { public: MyPC* FUN_141bd0cc0(); };
Unk_InvWorld* FUN_1403ed2d0();
int FUN_141658f30(MyPC* pPc);                                       // a bank privilege (pc bang)
int FUN_141662de0(MyPC* pPc);                                       // a bank privilege (vip)
int FUN_141662830(MyPC* pPc);                                       // the last bank call time
void FUN_14166cc40(PCBase* pPc, int nPose);

// The item event source and the status listeners' registry.
class Unk_InvItemEvents
{
public:
    void FUN_1419cae20(UIItemEventListener* pListener);
    void FUN_1419caeb0(UIItemEventListener* pListener);
};
Unk_InvItemEvents* FUN_140a6a840();
UIStatusEventDispatcher* FUN_140aa6d40();

// The player inventory (global 0x143ab2a90) and its free helpers.
extern Unk_Inventory DAT_143ab2a90;
unsigned FUN_140a5d0f0();                                           // the expansion price
int FUN_140a66510(int nTab);                                        // the base slot count of a tab
int FUN_140a66750(int nTab);                                        // the extra slot count of a tab
extern __int64 DAT_143ab2898;                                       // the mesos

// The bag bound to a name.
class Unk_InvBagBind;
Unk_InvBagBind* FUN_1422c8e90(const CString& strName);
InventorySlotBag* FUN_14140fb30(Unk_InvBagBind* pBind);             // DynamicCast<InventorySlotBag>
void FUN_1422cca90(InventorySlotBag* pBag);                         // redraw
DragSlotBag* FUN_140c544d0(Unk_InvBagBind* pBind);

// The platform (text filter) service.
class Unk_InvPlatform
{
public:
#define INV_P(n) virtual void vfunc_##n();
    INV_P(0) INV_P(1) INV_P(2) INV_P(3) INV_P(4) INV_P(5) INV_P(6) INV_P(7) INV_P(8) INV_P(9)
    INV_P(10) INV_P(11) INV_P(12) INV_P(13) INV_P(14) INV_P(15) INV_P(16) INV_P(17) INV_P(18) INV_P(19)
    INV_P(20) INV_P(21) INV_P(22) INV_P(23) INV_P(24) INV_P(25) INV_P(26) INV_P(27) INV_P(28) INV_P(29)
    INV_P(30) INV_P(31) INV_P(32) INV_P(33) INV_P(34) INV_P(35) INV_P(36)
    virtual int vfunc_37(Unk_BlockList* pRequest);                  // 37 (+0x128) check a text
    INV_P(38) INV_P(39)
    virtual bool vfunc_40(unsigned nPrice);                         // 40 (+0x140) can pay
    INV_P(41) INV_P(42)
    virtual void vfunc_43(int a1, int a2, int a3);                  // 43 (+0x158)
#undef INV_P
};
Unk_InvPlatform* FUN_140d86260();

// The game feature switches.
class Unk_InvFeatures { public: bool FUN_14036d570(int nFeature); };
Unk_InvFeatures* FUN_140166410();

// The key state.
class Unk_InvKeys { public: bool FUN_14116d9c0(int nKey, int a, int b); };
Unk_InvKeys* FUN_14025e7c0();

// The localized "$s_..." strings.
class Unk_InvStringKeys { public: CStringW FUN_1422b0570(const CString& strKey); };
Unk_InvStringKeys* FUN_14025e7a0();

// The text filter of the common strings.
class Unk_InvStrings { public: MS2Ptr<CBanTextChecker> FUN_140229a50(); };
Unk_InvStrings* FUN_14025e7d0();

// Field flags (the "no item merge here" map flag).
int FUN_1402c4c90(void* pFlags, int nFlag);
char* FUN_14025e7b0();

// The other dialogs the window works with.
UIDialog* FUN_140c300a0(int nUiId);
UIDialog* FUN_140613770(int nUiId);                                 // UIItemLockDialog
UIDialog* FUN_140534590(int nUiId);                                 // UIItemBreakDialog
UIDialog* FUN_1405346e0(int nUiId);                                 // UIItemBreakDonationDialog
UIDialog* FUN_140d27300(int nUiId);
UIDialog* FUN_140d27760(int nUiId);
UIDialog* FUN_140de48d0(int nUiId);                                 // UIStoreDialog
class Unk_InvOptionDialog { public: void FUN_1419da620(int n); };
Unk_InvOptionDialog* FUN_140cbe260(int nUiId);
class Unk_InvTradeManager;
Unk_InvTradeManager* FUN_14140ea30();
int FUN_14185d8b0(Unk_InvTradeManager* p);

// The UI service.
class Unk_InvUIService
{
public:
    void FUN_141adc530(int nUiId);                                  // open
    void FUN_141adc750(int nUiId);                                  // toggle
    void FUN_141add1f0();                                           // the "not enough mesos" shop
    int FUN_141adbb00();                                            // a window takes the keys
};
Unk_InvUIService* FUN_1403ed2b0();
extern bool DAT_143af62d0;                                          // the UI development mode ("initData")
MS2Ptr<CItemData> FUN_14053f870(int nItemId);

// Talk scripts.
MS2Ptr<CTalkScript> FUN_140856820(int nNpcId, int nKind);
UITalkManager* FUN_140967100();

// Message boxes, notices and strings.
struct Unk_InvPoint { float x, y; };
extern Unk_InvPoint DAT_143b02320;                                  // zero offset
void FUN_141275c30(UISwfEntity* pLeft, UISwfEntity* pRight, Unk_InvPoint offLeft, Unk_InvPoint offRight);
void FUN_140d73aa0(CStringW text, int nType, IMessageListener* pListener, CStringW tag);
MS2Ptr<CMsgBoxData> FUN_140d73e40(int nType, int nStringId, IMessageListener* pListener, CStringW tag);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, IMessageListener* pListener, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_141275260(int nStringId, int nA, int nB);
void FUN_141275460(int nStringId, int nA, int nB, const fmt::ArgList& args);
void FUN_14151f200();
UIMessageBox* FUN_14151f890();
CStringW FUN_14028b8e0(const CStringW& strKey);
CStringW FUN_14028de60(int nStringId);
CStringW FUN_1409eec40(int nStringId);
CStringW FUN_14028dee0(int nId, const fmt::ArgList& args);
FMT_VARIADIC_W(CStringW, FUN_14028dee0, int)
CStringW FUN_1405c2690(const CStringW& strKey, const CStringW& strArg);
CStringW FUN_1401ceea0(const wchar_t* szFormat, const int& nArg);
CStringW FUN_1413fa9b0(const CStringW& str);                        // lower case
CStringW FUN_1409404f0(__int64 n);                                  // a number with thousand separators
int FUN_14028cb70(const CStringW& str, ATL::CAtlArray<CStringW>& out, const wchar_t* szDelim, int nMax);
bool FUN_140164830(const CStringW& a, const CStringW& b);           // differ
__int64 FUN_140869440();                                            // now (seconds)

// The notice with two format arguments (a template over the argument types in the original).
template <class A, class B> void Unk_InvNotice(int nStringId, int nA, int nB, const A& a, const B& b)
{
    const fmt::internal::ArgArray<2>::Type values = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(a),
                                                     fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(b)};
    FUN_141275460(nStringId, nA, nB, fmt::ArgList(fmt::internal::make_type(a, b), values));
}

// The tabs of the inventory (CItem categories).
enum Unk_InvTab
{
    INV_TAB_EQUIP = 0,
    INV_TAB_SKIN = 1,
    INV_TAB_SUMMON = 2,
    INV_TAB_MATERIAL = 3,
    INV_TAB_LIFE = 4,
    INV_TAB_QUEST = 5,
    INV_TAB_GEM = 6,
    INV_TAB_MISC = 7,
    INV_TAB_MASTERY = 8,
    INV_TAB_PET = 9,
    INV_TAB_ACTIVESKILL = 10,
    INV_TAB_COIN = 11,
    INV_TAB_BADGE = 12,
    INV_TAB_LAPENSHARD = 13,
    INV_TAB_PIECE = 14,
};

// UISwfEntity::GetChild<T> (uiswfentity.inl), one COMDAT per wrapper class.
template <class T> MS2Ptr<T> UISwfEntity::GetChild(const CString& strName)
{
    if (m_30 == 0)
        return MS2Ptr<T>(0);
    return m_30->FUN_140e159f0<T>(strName);
}

// ---- statics (.text$di, in init order): the headers' statics, the user list keys, the break sounds ----------------------
#ifndef MS2_HOOK_DLL
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_unkTab(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput;
#endif
static CString s_strCharacterName = "characterName";               // 0x143af3090
static CString s_strIconPath = "iconPath";                         // 0x143af3088
static CString s_strLevelAndJobName = "levelAndJobName";           // 0x143af3098
static CString s_strOnline = "online";                             // 0x143af3080
#ifndef MS2_HOOK_DLL
static CString s_strSortTypeNames2[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSortTypeNames3[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
#endif
static CString s_strExtractEnd = "Extract_End";                    // 0x143af30e0
static CString s_strExtractProgress = "Extract_Progress";          // 0x143af30d8

// ---- UIInventoryDialog -----------------------------------------------------------------------------------------------

#ifndef MS2_HOOK_DLL
int UIInventoryDialog::s_nAlignMode;
#endif

// @0x141996ec0
UIInventoryDialog::UIInventoryDialog()
    : m_188(vfunc_1()), m_190(0), m_194(0), m_198(0), m_19c(0), m_1a0(-1), m_1a4(0)
{
    m_88 = 1;
    m_5c = 1;
    FUN_141924170(1);
}

// @0x141997080
UIInventoryDialog::~UIInventoryDialog()
{
}

// @0x141997190
CString UIInventoryDialog::vfunc_1()
{
    return "InventoryDialog";
}
MS2_REPLACE_METHOD(0x141997190, UIInventoryDialog, vfunc_1, 61, 0);

// @0x1419971e0
int UIInventoryDialog::vfunc_il1()
{
    return vfunc_55() == 0;
}
MS2_REPLACE_METHOD_VIA(0x1419971E0, UIInventoryDialog, UIItemEventListener, vfunc_il1, 69, 0);

// @0x141997230
int UIInventoryDialog::vfunc_oa0_1()
{
    return vfunc_55() == 0;
}
MS2_REPLACE_METHOD_VIA(0x141997230, UIInventoryDialog, UIStatusEventListener, vfunc_oa0_1, 69, 0);

// @0x141997280
int UIInventoryDialog::vfunc_65()
{
    m_1a0 = -1;
    if (UIDialog::vfunc_65() == 0)
        return 0;
    FUN_140a6a840()->FUN_1419cae20(this);
    FUN_140aa6d40()->FUN_141b0cd00(this);
    return 1;
}
MS2_REPLACE_METHOD(0x141997280, UIInventoryDialog, vfunc_65, 158, 0);

// @0x141997330
void UIInventoryDialog::vfunc_67()
{
    FUN_140a6a840()->FUN_1419caeb0(this);
    FUN_140aa6d40()->FUN_141b0cd90(this);
    FUN_14199be00(INV_TAB_EQUIP);
    FUN_14199be00(INV_TAB_LIFE);
    FUN_14199be00(INV_TAB_MISC);
    FUN_14199be00(INV_TAB_SUMMON);
    FUN_14199be00(INV_TAB_SKIN);
    FUN_14199be00(INV_TAB_GEM);
    FUN_14199be00(INV_TAB_QUEST);
    FUN_14199be00(INV_TAB_MATERIAL);
    FUN_14199be00(INV_TAB_MASTERY);
    FUN_14199be00(INV_TAB_PET);
    FUN_14199be00(INV_TAB_LAPENSHARD);
    FUN_14199be00(INV_TAB_ACTIVESKILL);
    FUN_14199be00(INV_TAB_COIN);
    FUN_14199be00(INV_TAB_BADGE);
    FUN_14199be00(INV_TAB_PIECE);
    FUN_14140ed60(m_188);
    UIDialog::vfunc_67();
    m_190 = 0;
    m_19c = 0;
    m_1a8.RemoveAll();
}
MS2_REPLACE_METHOD(0x141997330, UIInventoryDialog, vfunc_67, 420, 0);

// @0x1419974e0
void UIInventoryDialog::vfunc_43()
{
    if (s_nAlignMode == 0)
    {
        UIDialog::vfunc_43();
    }
    else
    {
        if (ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30))
            pDlg->vfunc_2(4, -200, 0);
        FUN_141923710(0);
    }
}
MS2_REPLACE_METHOD(0x1419974E0, UIInventoryDialog, vfunc_43, 139, 0);

// @0x141997580
void UIInventoryDialog::vfunc_15()
{
    UISwfEntity::vfunc_15();
    if (vfunc_55() == 0 && 0 < m_19c)
    {
        if ((m_19c & 1) != 0)
            FUN_14199bc00();
        if ((m_19c & 2) != 0)
            FUN_14199c0d0();
        if ((m_19c & 4) != 0)
            FUN_14199ba10();
    }
}
MS2_REPLACE_METHOD(0x141997580, UIInventoryDialog, vfunc_15, 147, 0);

// @0x141997620
void UIInventoryDialog::vfunc_62(int nWidth, int nHeight)
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        int nCurWidth, nCurHeight;
        FUN_14199c8a0(&nCurWidth, &nCurHeight);
        if (nHeight == 0)
            nHeight = nCurHeight;
        if (nWidth == 0)
            nWidth = nCurWidth;
        if (nCurWidth != nWidth || nCurHeight != nHeight)
            pDlg->FUN_1422c79e0(nWidth, nHeight);
    }
}
MS2_REPLACE_METHOD(0x141997620, UIInventoryDialog, vfunc_62, 174, 0);

// @0x1419976e0
void UIInventoryDialog::vfunc_oa0_11(void* a1)
{
    if (vfunc_55() == 0)
    {
        MS2Ptr<ASTextField> spMeso = GetChild<ASTextField>("m_meso");
        if (spMeso.get() != 0)
            spMeso->FUN_1422c4cd0(FUN_1409404f0((__int64)a1));
    }
}
MS2_REPLACE_METHOD_VIA(0x1419976E0, UIInventoryDialog, UIStatusEventListener, vfunc_oa0_11, 272, 0);

// @0x141997800
void UIInventoryDialog::vfunc_oa0_9(unsigned short a1)
{
    if (vfunc_55() == 0)
    {
        if (InventorySlotBag* pBag = FUN_14140fb30(FUN_1422c8e90(m_188)))
            FUN_1422cca90(pBag);
    }
}
MS2_REPLACE_METHOD_VIA(0x141997800, UIInventoryDialog, UIStatusEventListener, vfunc_oa0_9, 115, 0);

// @0x141997880
void UIInventoryDialog::vfunc_oa0_7(int a1, CStringW s)
{
    if (vfunc_55() == 0)
    {
        if (InventorySlotBag* pBag = FUN_14140fb30(FUN_1422c8e90(m_188)))
            FUN_1422cca90(pBag);
    }
}
MS2_REPLACE_METHOD_VIA(0x141997880, UIInventoryDialog, UIStatusEventListener, vfunc_oa0_7, 151, 0);

// @0x141997920
void UIInventoryDialog::vfunc_oa0_25(void* a1)
{
    if (DragSlotBag* pBag = FUN_140c544d0(FUN_1422c8e90(m_188)))
        pBag->vfunc_11(a1);
}
MS2_REPLACE_METHOD_VIA(0x141997920, UIInventoryDialog, UIStatusEventListener, vfunc_oa0_25, 78, 0);

// @0x141997980
void UIInventoryDialog::vfunc_oa0_26(void* a1)
{
    if (DragSlotBag* pBag = FUN_140c544d0(FUN_1422c8e90(m_188)))
        pBag->vfunc_12(a1);
}
MS2_REPLACE_METHOD_VIA(0x141997980, UIInventoryDialog, UIStatusEventListener, vfunc_oa0_26, 78, 0);

// @0x1419979e0
void UIInventoryDialog::vfunc_26(int nItemId)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0 || (pPc->FUN_14166c930() != 1 && pPc->FUN_14166c930() != 0xe))
        return;
    MS2Ptr<CItemData> spData = FUN_14053f870(nItemId);
    if (spData == 0)
        return;
    CString strModel = pPc->FUN_14166dc50();
    if (strModel == "Idle_A" && pPc->FUN_141527120() != 0)
    {
        if (spData->FUN_14053c620() == 0xd)
            FUN_14166cc40(pPc, 0x4c);
        else if (spData->FUN_14053c620() == 0x10)
            FUN_14166cc40(pPc, 0x51);
        else if (spData->FUN_14053c620() == 0x12)
            FUN_14166cc40(pPc, 0x52);
        else if (spData->FUN_14053c620() == 0x11)
            FUN_14166cc40(pPc, 0x53);
        else if (spData->FUN_14053d110())
            FUN_14166cc40(pPc, 0x4e);
    }
}
#ifndef MS2_STANDALONE
// vfunc_26 is overloaded (UIDialog slot 26 and UIItemEventListener slot 26): explicit thunks instead of MS2_REPLACE_METHOD.
namespace {
struct Unk_InvItemUsedThunk : UIItemEventListener
{
    void Call(int nItemId) { static_cast<UIInventoryDialog*>(static_cast<UIItemEventListener*>(this))->UIInventoryDialog::vfunc_26(nItemId); }
};
}
MS2_REPLACE_IMPL(0x1419979E0, ::ms2::hook::detail::MemberToVoid(&Unk_InvItemUsedThunk::Call), "UIInventoryDialog::vfunc_26(int)", 430, 0);
#endif

// @0x141997ba0
// MS2-FUNCTIONAL: frame layout of the request temporaries differs
void UIInventoryDialog::vfunc_80(void* pRequest)
{
    if (!(m_1e0 == 0))
    {
        Unk_BlockList reply(*(CInPacket*)pRequest);
        Unk_BlockEntry entry;
        if (reply.Find("m_inputSearch", entry) == 1)
        {
            if (entry.m_nFlags == 0)
            {
                FUN_14199c2b0(CStringW(FUN_1413fa9b0(m_1e0->FUN_1422e0b00())));
            }
            else
            {
                static_cast<Unk_InvInput*>(m_1e0.operator->())->FUN_1422e0bd0(CStringW(L""));
                FUN_140d73aa0(FUN_1409eec40(0x8b7), 0, 0, CStringW(L""));
            }
        }
    }
}
MS2_REPLACE_METHOD(0x141997BA0, UIInventoryDialog, vfunc_80, 543, 0);

// @0x141997dd0
void UIInventoryDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    m_1d8 = "";
    do {
        m_30->FUN_140c57d70("m_itemBagEx", m_210);
        if (m_210 == NULL)
            throw new GfxExceptionSwfLoad(StringFormat("GfxError:{0} {1}({2}) function:{3}", "SwfLoadError",
                                                      MS2_THIS_FILE, MS2_LINE(0x154), __FUNCTION__));
    } while (0);
    FUN_141999f60();
    if (m_30->FUN_140bbe940("m_inputSearch", m_1e0).get() != 0)
        m_1e0->FUN_1422e0920(ParamsDelegate(this, &UIInventoryDialog::FUN_14199a620));
    FUN_14199ca90();
    m_30->Invoke("initData", FUN_14199d920(m_194), DAT_143af62d0);
    m_19c |= 1;
    m_19c |= 2;
    static_cast<UIStatusEventListener*>(this)->vfunc_oa0_11((void*)DAT_143ab2898);
    FUN_140d86260()->vfunc_43(0xe, 0, 1000);
}
MS2_REPLACE_METHOD(0x141997DD0, UIInventoryDialog, OnLoadComplete, 1103, 0);

// @0x141998250
void UIInventoryDialog::vfunc_26()
{
    UIDialog::vfunc_26();
    m_210.AssignRaw(0);
    m_1c8.AssignRaw(0);
    m_1e0.AssignRaw(0);
}
#ifndef MS2_STANDALONE
namespace {
struct Unk_InvDropControlsThunk : UIInventoryDialog
{
    void Call() { static_cast<UIInventoryDialog*>(this)->UIInventoryDialog::vfunc_26(); }
};
}
MS2_REPLACE_IMPL(0x141998250, ::ms2::hook::detail::MemberToVoid(&Unk_InvDropControlsThunk::Call), "UIInventoryDialog::vfunc_26()", 87, 0);
#endif

// @0x1419982b0
int UIInventoryDialog::OnMessage(UISwfEntity* pSender, UIMsg* pMsg)
{
    if (UIDialog::OnMessage(pSender, pMsg) != 0)
        return 1;
    if (pMsg->FUN_1422e4520() != 0)
        return 0;
    if (dynamic_cast<UIMessageBox*>(pSender) == 0)
    {
        if (dynamic_cast<UISceneLobbyServer*>(pSender) == 0)
        {
            if (pMsg->FUN_1422b8d30() == "openWindowPos")
            {
                m_190 = pMsg->FUN_1422b8a10();
                if (vfunc_55() == 0)
                {
                    if (FUN_1422dc390() != 0)
                        vfunc_66();
                }
                else
                {
                    FUN_1403ed2b0()->FUN_141adc530(vfunc_48());
                }
            }
        }
        else if (pMsg->FUN_1422b8d30() == "OnReset")
        {
            m_194 = 0;
            return 1;
        }
        return 0;
    }
    int nAnswer = pMsg->FUN_1422b8a10();
    CStringW strTag = pMsg->FUN_1422b8f40();
    if (nAnswer != 0)
    {
        FUN_14151f200();
        return 0;
    }
    if (strTag == L"expandSlot")
    {
        FUN_14199e2a0();
        return 0;
    }
    ATL::CAtlArray<CStringW> aParts;
    if (FUN_14028cb70(strTag, aParts, L",", 2) == 0)
        return 0;
    CStringW strAmount(aParts[1]);
    if (strAmount.IsEmpty())
        return 0;
    __int64 nAmount = _wtoi64(strAmount);
    FUN_14199bed0(nAmount);
    return 1;
}
MS2_REPLACE_METHOD_VIA(0x1419982B0, UIInventoryDialog, IMessageListener, OnMessage, 968, 0);

// @0x141998680
// MS2-FUNCTIONAL: frame layout of the per-branch temporaries differs
int UIInventoryDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("OnClickSort", szMethod) == 0)
    {
        int nTab = FUN_141999de0();
        if (-1 < nTab && nTab < 0xf)
        {
            if (DAT_143ab2a90.FUN_140a5cf30(nTab) == 0)
                return 1;
            if (0 < FUN_14199d840())
            {
                MS2Ptr<CMsgBoxData> box = FUN_140d73e40(1, 0x2a1, 0, CStringW(L""));
                if (box.get() != 0)
                {
                    box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIInventoryDialog::FUN_14199b480));
                    box->FUN_141a01800(1);
                    box->FUN_141a024a0(0);
                    box->FUN_141a02480(1);
                    FUN_140d73c60(box);
                    return 1;
                }
            }
            FUN_14199c230(nTab, false);
        }
        return 1;
    }
    if (_stricmp("onClickItemOption", szMethod) == 0)
    {
        if (Unk_InvOptionDialog* pDlg = FUN_140cbe260(0x4e6c))
        {
            pDlg->FUN_1419da620(1);
            FUN_1403ed2b0()->FUN_141adc530(0x4e6c);
        }
        return 1;
    }
    if (_stricmp("onClickItemBreak", szMethod) == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4e8d);
        return 1;
    }
    if (_stricmp("onClickItemLock", szMethod) == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4f08);
        return 1;
    }
    if (_stricmp("onClickItemSocketAndGem", szMethod) == 0)
    {
        FUN_1403ed2b0()->FUN_141adc750(0x4f0a);
        return 1;
    }
    if (_stricmp("onClickItemEnchant", szMethod) == 0)
    {
        FUN_14199aaa0();
        return 1;
    }
    if (_stricmp("onClickItemEnchantTransform", szMethod) == 0)
    {
        MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc != 0 && pPc->vfunc_65() == 1)
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_error_talk_battle_state_force_talk")), 1, 1);
            return 1;
        }
        int nNpcId = *FUN_1401d3200()->EnchantTransformScriptID.Get();
        if (CTalkScript* pScript = FUN_140856820(0xa7dabf, nNpcId).get())
        {
            FUN_140967100()->FUN_141b213f0(MS2Ptr<CTalkScript>(pScript), 0xa7dabf, 2, 0);
            FUN_140967100()->FUN_141b1eb90(CString("ItemEnchantTransformDialog"), CString(""));
        }
        return 1;
    }
    if (_stricmp("onClickUnlimitedEnchant", szMethod) == 0)
    {
        if (CTalkScript* pScript = FUN_140856820(0xa7eb82, 10).get())
        {
            FUN_140967100()->FUN_141b213f0(MS2Ptr<CTalkScript>(pScript), 0xa7eb82, 2, 0);
            FUN_140967100()->FUN_141b1eb90(CString("UnlimitedEnchantDialog"), CString(""));
        }
        return 1;
    }
    if (_stricmp("onClickItemMerge", szMethod) == 0)
    {
        if (FUN_1402c4c90(FUN_14025e7b0() + 8, 0x39) == 1)
        {
            FUN_141275260(0x2f7, 1, 1);
            return 1;
        }
        MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc != 0 && pPc->vfunc_65() == 1)
        {
            FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_error_talk_battle_state_force_talk")), 1, 1);
            return 1;
        }
        int nNpcId = *FUN_1401d3200()->MergeSmithScriptID.Get();
        if (CTalkScript* pScript = FUN_140856820(0xa7e618, nNpcId).get())
        {
            FUN_140967100()->FUN_141b213f0(MS2Ptr<CTalkScript>(pScript), 0xa7e618, 2, 0);
            FUN_140967100()->FUN_141b1eb90(CString("ItemMergeOptionDialog"), CString(""));
        }
        return 1;
    }
    if (_stricmp("onClickItemRemakeOption", szMethod) == 0)
    {
        MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc == 0)
            return 0;
        pPc->FUN_141528970();
        return 0;
    }
    if (_stricmp("OnItemSearch", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            FUN_14199b800(data.FUN_1422b8f40());
        return 1;
    }
    if (_stricmp("onClickSlotExpand", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            CStringW strArg = data.FUN_1422b8f40();
            if (FUN_14199d980() == 0)
            {
                CStringW strMsg = FUN_1409eec40(0x267);
                FUN_140d73aa0(CStringW(strMsg), 0, 0, CStringW(L""));
            }
            else
            {
                unsigned nPrice = FUN_140a5d0f0();
                CStringW strMsg = FUN_14028dee0(0x266, nPrice, strArg, 6);
                FUN_140d73aa0(CStringW(strMsg), 1, this, CStringW(L"expandSlot"));
            }
        }
        return 1;
    }
    if (_stricmp("onClickOpenBank", szMethod) == 0)
        FUN_14199a910();
    return 0;
}
MS2_REPLACE_METHOD(0x141998680, UIInventoryDialog, vfunc_28, 3611, 0);

// @0x1419994e0
// MS2-FUNCTIONAL: frame layout of the button temporaries differs
int UIInventoryDialog::vfunc_46()
{
    if (UISwfEntity::vfunc_46() == 0)
        return 0;
    if (m_30 == 0)
        return 0;
    {
        MS2Ptr<ASUIComponent> spButton = m_30->FUN_140acce30<ASUIComponent>("m_itemBreak");
        if (spButton.get() != 0)
            spButton->FUN_1422c7b40(FUN_14199d9c0());
    }
    static const struct { int nFeature; const char* szButton; } s_aButtons[] = {
        {0x2e, "m_itemSocketAndGem"}, {0x6f, "m_itemMerge"}, {0x75, "m_openBank"},
        {0xa6, "m_itemEnchantTransform"}, {0x10d, "m_unlimitedEnchant"},
    };
    for (int i = 0; i < 5; ++i)
    {
        if (!FUN_140166410()->FUN_14036d570(s_aButtons[i].nFeature))
        {
            MS2Ptr<ASUIComponent> spButton = m_30->FUN_140acce30<ASUIComponent>(s_aButtons[i].szButton);
            if (spButton.get() != 0)
                spButton->vfunc_3(0);
        }
    }
    m_30->Invoke("updateButtonPos");
    return 1;
}
MS2_REPLACE_METHOD(0x1419994E0, UIInventoryDialog, vfunc_46, 1421, 0);

// @0x141999a80
int UIInventoryDialog::vfunc_13()
{
    if (vfunc_55() != 0)
        return 0;
    if (UIDialog::vfunc_13() != 0)
        return 1;
    if (FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
    {
        if (ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30))
        {
            if (FUN_140b632f0() != 0)
            {
                if (static_cast<Unk_InvSwfManager*>(FUN_140b632f0())->FUN_1422d4e20(CString(m_20)) == 0)
                    return 0;
            }
            if (m_1e0.get() != 0)
            {
                if (m_1e0->FUN_1422c76c0() != 0)
                {
                    FUN_14199b800(m_1e0->FUN_1422e0b00());
                    pDlg->FUN_1422c7630(1);
                    m_1e0->FUN_1422c7630(0);
                    return 1;
                }
                pDlg->FUN_1422c7630(0);
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x141999A80, UIInventoryDialog, vfunc_13, 488, 0);

// @0x141999c70
void UIInventoryDialog::vfunc_18()
{
    UIDialog::vfunc_18();
    if (vfunc_55() == 0 && m_190 != 0)
    {
        UIDialog* pDlg = FUN_140c300a0(m_190);
        if (pDlg != 0 && pDlg->vfunc_55() == 0 && pDlg->FUN_1422dc430() != 0)
            FUN_141275c30(pDlg, this, DAT_143b02320, DAT_143b02320);
    }
}
MS2_REPLACE_METHOD(0x141999C70, UIInventoryDialog, vfunc_18, 156, 0);

// @0x141999d20
void UIInventoryDialog::FUN_141999d20(int nMode)
{
    s_nAlignMode = nMode;
}
MS2_REPLACE(0x141999D20, UIInventoryDialog::FUN_141999d20, 15, 0);

// @0x141999d40
void UIInventoryDialog::FUN_141999d40(int nTab)
{
    if (m_1c8.get() == 0)
    {
        m_194 = nTab;
    }
    else
    {
        m_1c8->FUN_1422e31e0(FUN_14199d920(nTab));
        m_1c8->vfunc_24(true);
    }
}
MS2_REPLACE_METHOD(0x141999D40, UIInventoryDialog, FUN_141999d40, 153, 0);

// @0x141999de0
int UIInventoryDialog::FUN_141999de0()
{
    return m_194;
}
MS2_REPLACE_METHOD(0x141999DE0, UIInventoryDialog, FUN_141999de0, 17, 0);

// @0x141999e00
void UIInventoryDialog::FUN_141999e00()
{
    m_19c = 7;
}
MS2_REPLACE_METHOD(0x141999E00, UIInventoryDialog, FUN_141999e00, 21, 0);

// @0x141999e20
void UIInventoryDialog::FUN_141999e20()
{
    m_194 = 0;
    m_1a0 = -1;
}
MS2_REPLACE_METHOD(0x141999E20, UIInventoryDialog, FUN_141999e20, 36, 0);

// @0x141999e50
void UIInventoryDialog::FUN_141999e50()
{
    m_19c = 7;
    MS2Ptr<ASMovieClip> spEff = GetChild<ASMovieClip>("m_expandEff");
    if (spEff.get() != 0)
        spEff->vfunc_12(1);
}
MS2_REPLACE_METHOD(0x141999E50, UIInventoryDialog, FUN_141999e50, 175, 0);

// @0x141999f10
int UIInventoryDialog::FUN_141999f10()
{
    if (m_210 == 0)
        return 0;
    return m_210->FUN_1422cf520();
}
MS2_REPLACE_METHOD(0x141999F10, UIInventoryDialog, FUN_141999f10, 73, 0);

// @0x141999f60
// MS2-FUNCTIONAL: the original reads the dialogs' vfunc_55 without null checks (kept)
void UIInventoryDialog::FUN_141999f60()
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    m_1a4 = 0;
    ASObj state(2);
    short nAutoPickup = (short)pPc->vfunc_78();
    int bBank = 0;
    if (FUN_141658f30(pPc) != 0 || FUN_141662de0(pPc) != 0)
        bBank = 1;
    UIDialog* pLock = FUN_140613770(0x4f08);
    UIDialog* pBreak = FUN_140534590(0x4e8d);
    UIDialog* pDonation = FUN_1405346e0(0x4e8e);
    UIDialog* pDlg4 = FUN_140d27300(0x4f49);
    UIDialog* pDlg5 = FUN_140d27760(0x4f4a);
    if (pLock == 0 && pBreak == 0 && pDlg4 == 0 && pDlg5 == 0)
        return;
    int bLockClosed = pLock->vfunc_55();
    if (bLockClosed == 0)
        m_1a4 = 3;
    int bBreakClosed = pBreak->vfunc_55();
    if (bBreakClosed == 0)
        m_1a4 = 1;
    int bDonationClosed = pDonation->vfunc_55();
    if (bDonationClosed == 0)
        m_1a4 = 2;
    bool bOpen4 = pDlg4->vfunc_55() == 0;
    if (bOpen4)
        m_1a4 = 4;
    bool bOpen5 = pDlg5->vfunc_55() == 0;
    if (bOpen5)
        m_1a4 = 5;
    if (ASDialog* pAs = dynamic_cast<ASDialog*>((AScript*)m_30))
    {
        state.FUN_1407cb9c0("bAutoPickup", nAutoPickup != 0);
        state.FUN_1407cbbe0("bItemEchant", true);
        state.FUN_1407cb9c0("bItemBreak", !bOpen5 && !bOpen4 && bLockClosed != 0);
        state.FUN_1407cbb20("itemBreakToolTip", FUN_14199d9c0());
        state.FUN_1407cb9c0("bItemLock", !bOpen5 && !bOpen4 && bDonationClosed != 0 && bBreakClosed != 0);
        state.FUN_1407cbbe0("bRemakeOption", true);
        state.FUN_1407cbbe0("bUnlimitedEnchant", true);
        state.FUN_1407cbbe0("bGem", true);
        state.FUN_1407cbb20("slotExpandToolTip", FUN_14199ddd0());
        state.FUN_1407cb9c0("bOpenBank", bBank);
        state.FUN_1407cbb20("openBankTooltip", FUN_14199deb0(bBank));
        pAs->Invoke("updateButtonState", state);
    }
}
MS2_REPLACE_METHOD(0x141999F60, UIInventoryDialog, FUN_141999f60, 1151, 0);

// @0x14199a3f0
void UIInventoryDialog::FUN_14199a3f0(__int64 nItemUid)
{
    if (vfunc_55() == 0)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2a90.FUN_140a5d680(nItemUid);
        if (!(spItem == 0))
        {
            if (InventorySlotBag* pBag = FUN_14140fb30(FUN_1422c8e90(m_188)))
                pBag->FUN_14140f5b0(spItem.get());
        }
    }
}
MS2_REPLACE_METHOD(0x14199A3F0, UIInventoryDialog, FUN_14199a3f0, 179, 0);

// @0x14199a4b0
void UIInventoryDialog::FUN_14199a4b0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    ASIndexEvent event(params);
    if (event.FUN_1422e2aa0() < 0)
        return;
    Scaleform::GFx::Value item = event.FUN_1422e2b60();
    if (FUN_1409b0390(&item))
        return;
    ASObj obj(item, 2);
    m_1a0 = m_194;
    m_194 = FUN_1409c1750(obj.FUN_1422baa20("tabIndex"));
    m_19c = 7;
    FUN_141999f60();
}
MS2_REPLACE_METHOD(0x14199A4B0, UIInventoryDialog, FUN_14199a4b0, 348, 0);

// @0x14199a620
// MS2-FUNCTIONAL: frame layout of the candidate temporaries differs
void UIInventoryDialog::FUN_14199a620(const Scaleform::GFx::FunctionHandler::Params& params)
{
    if (!m_1e0)
        return;
    if (m_1e0->FUN_1422c76c0() == 0)
        return;
    CStringW strText = m_1e0->FUN_1422e0b00();
    if (strText.IsEmpty())
        return;
    strText.TrimRight();
    CStringW strSearch = FUN_1413fa9b0(strText);
    ASDataProvider candidates(2);
    if (0 < strSearch.GetLength())
    {
        ATL::CAtlList<CStringW> names(10);
        FUN_14199c610(CStringW(strSearch), names);
        for (POSITION pos = names.GetHeadPosition(); pos != 0; names.GetNext(pos))
        {
            CStringW strLower = FUN_1413fa9b0(names.GetAt(pos));
            ASObj row(2);
            row.FUN_1407cbb20("label", CStringW(names.GetAt(pos)));
            candidates.FUN_1422bbf00(row);
        }
    }
    int nRows = candidates.FUN_1422bc5d0() < 6 ? (int)candidates.FUN_1422bc5d0() : 5;
    static_cast<ASObj*>(static_cast<AScript*>(m_1e0.operator->()))->FUN_1407cb9c0("m_rowCount", nRows);
    m_1e0->Invoke("setCandidates", candidates);
}
MS2_REPLACE_METHOD(0x14199A620, UIInventoryDialog, FUN_14199a620, 743, 0);

// @0x14199a910
void UIInventoryDialog::FUN_14199a910()
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return;
    UIDialog* pStore = FUN_140de48d0(0x4e47);
    if (pStore->vfunc_55() == 0)
    {
        pStore->vfunc_69();
        return;
    }
    __int64 nNow = FUN_140869440();
    unsigned nCooltime = *FUN_1401d3200()->HomeBankCallCooltime.Get();
    int nElapsed = (int)nNow - FUN_141662830(pPc);
    if (nElapsed < (int)(nCooltime / 1000))
    {
        int nRemain = nCooltime / 1000 - nElapsed;
        FUN_1412751f0(FUN_1401ceea0(FUN_14028b8e0(CStringW(L"s_inventory_err_open_bank_remain_time")), nRemain), 1, 1);
    }
    else
    {
        pPc->FUN_1415283c0(2);
    }
}
MS2_REPLACE_METHOD(0x14199A910, UIInventoryDialog, FUN_14199a910, 390, 0);

// @0x14199aaa0
void UIInventoryDialog::FUN_14199aaa0()
{
    FUN_1403ed2b0()->FUN_141adc750(0x4e91);
}
MS2_REPLACE_METHOD(0x14199AAA0, UIInventoryDialog, FUN_14199aaa0, 32, 0);

// @0x14199aad0
MS2Ptr<ASButtonBar> UIInventoryDialog::FUN_14199aad0()
{
    return m_1c8;
}
MS2_REPLACE_METHOD(0x14199AAD0, UIInventoryDialog, FUN_14199aad0, 67, 0);

// @0x14199ab20
int UIInventoryDialog::FUN_14199ab20(CString strName)
{
    for (unsigned i = 0; i < m_1f0.GetCount(); ++i)
    {
        if (m_1f0[i].first == strName)
            return i;
    }
    return -1;
}
MS2_REPLACE_METHOD(0x14199AB20, UIInventoryDialog, FUN_14199ab20, 177, 0);

// @0x14199abe0
CStringW UIInventoryDialog::FUN_14199abe0()
{
    return m_1d8;
}
MS2_REPLACE_METHOD(0x14199ABE0, UIInventoryDialog, FUN_14199abe0, 68, 0);

// @0x14199ac30
// MS2-FUNCTIONAL: frame layout of the message box temporaries differs
bool UIInventoryDialog::FUN_14199ac30(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    __int64 nItemUid = box.FUN_141a02f10(0, 0);
    CStringW strName = box.FUN_141a02d50().Trim(L',');
    if (strName.IsEmpty())
    {
        if (UIMessageBox* pBox = FUN_14151f890())
            pBox->FUN_1419f82b0(FUN_14028de60(0xd));
        return false;
    }
    if (CBanTextChecker* pChecker = FUN_14025e7d0()->FUN_140229a50().get())
    {
        CStringW strMsg;
        if (pChecker->FUN_140225210(strName, strMsg, 0) != 0)
        {
            FUN_1412751f0(strMsg, 1, 1);
            return false;
        }
    }
    CItem* pItem = DAT_143ab2a90.FUN_140a5d680(nItemUid).get();
    if (pItem == 0)
        return false;
    MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(1, FUN_1405c2690(CStringW(L"s_coupleeffect_send_confirm"), strName), 0, CStringW(L""));
    if (spBox.get() != 0)
    {
        spBox->FUN_1405340b0(nItemUid);
        spBox->FUN_140b76940(CStringW(strName));
        spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIInventoryDialog::FUN_14199b100));
        FUN_140d73c60(spBox);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14199AC30, UIInventoryDialog, FUN_14199ac30, 1212, 0);

// @0x14199b100
// MS2-FUNCTIONAL: frame layout of the message box temporaries differs
bool UIInventoryDialog::FUN_14199b100(int nResult, const CMsgBoxData& box)
{
    __int64 nItemUid = box.FUN_141a02f10(0, 0);
    CStringW strName = box.FUN_141a02fd0(1, CStringW(L""));
    CItem* pItem = DAT_143ab2a90.FUN_140a5d680(nItemUid).get();
    if (pItem == 0)
        return false;
    if (nResult == 0)
    {
        DAT_143ab2a90.FUN_140a63880(pItem, strName);
    }
    else
    {
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(10, FUN_14028b8e0(CStringW(L"s_coupleeffect_recevie_name")), 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            spBox->FUN_141a01d30(2, CStringW(L""), 0xc, 0, 0);
            spBox->FUN_1405340b0(nItemUid);
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIInventoryDialog::FUN_14199ac30));
            FUN_140d73c60(spBox);
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x14199B100, UIInventoryDialog, FUN_14199b100, 883, 0);

// @0x14199b480
bool UIInventoryDialog::FUN_14199b480(int nResult, const CMsgBoxData& box)
{
    FUN_14199c230(m_194, nResult == 0);
    return true;
}
MS2_REPLACE_METHOD(0x14199B480, UIInventoryDialog, FUN_14199b480, 86, 0);

// @0x14199b4e0
// MS2-FUNCTIONAL: frame layout of the packet temporaries differs
bool UIInventoryDialog::FUN_14199b4e0(int nResult, const CMsgBoxData& box)
{
    if (nResult != 0)
        return true;
    __int64 nItemUid = box.FUN_141a02f10(0, 0);
    CStringW strOld = box.FUN_141a02fd0(1, CStringW(L""));
    CStringW strName = box.FUN_141a02d50().Trim(L',');
    if (strName.IsEmpty() || 0x1f < strName.GetLength())
        return false;
    MS2Ptr<CBanTextChecker> spChecker = FUN_14025e7d0()->FUN_140229a50();
    CStringW strMsg;
    if (spChecker.get() == 0)
        return true;
    if (spChecker->FUN_140225630(strName, strMsg) == 0)
    {
        if (FUN_140164830(strOld, strName))
        {
            COutPacket packet(0x98, 0);
            packet.vfunc_o10_4(nItemUid);
            packet.vfunc_o10_8(strName);
            FUN_140710590(packet);
            return true;
        }
        if (UIMessageBox* pBox = FUN_14151f890())
            pBox->FUN_1419f82b0(FUN_14028de60(0xe7));
    }
    else
    {
        if (UIMessageBox* pBox = FUN_14151f890())
            pBox->FUN_1419f82b0(strMsg);
    }
    return false;
}
MS2_REPLACE_METHOD(0x14199B4E0, UIInventoryDialog, FUN_14199b4e0, 787, 0);

// @0x14199b800
void UIInventoryDialog::FUN_14199b800(CStringW strText)
{
    if (strText.IsEmpty())
    {
        FUN_14199c2b0(CStringW(L""));
        return;
    }
    Unk_BlockList request(0x4e2d);
    request.Add("m_inputSearch", CStringW(strText), false);
    int nResult = FUN_140d86260()->vfunc_37(&request);
    if (nResult == 1)
        FUN_14199c2b0(CStringW(FUN_1413fa9b0(strText)));
}
MS2_REPLACE_METHOD(0x14199B800, UIInventoryDialog, FUN_14199b800, 490, 0);

// @0x14199ba10
void UIInventoryDialog::FUN_14199ba10()
{
    if (m_210 == 0)
        return;
    m_1d8 = "";
    int nCount = DAT_143ab2a90.FUN_140a5d050(m_194);
    FUN_14140ed60(m_188);
    if (InventorySlotBag* pBag = FUN_14140eca0(m_188, m_194, nCount))
    {
        m_210->vfunc_25(pBag->FUN_14140f7a0().FUN_1422bb890());
        m_210->vfunc_24(1);
        m_19c &= ~4;
    }
}
MS2_REPLACE_METHOD(0x14199BA10, UIInventoryDialog, FUN_14199ba10, 395, 0);

// @0x14199bbb0
void UIInventoryDialog::FUN_14199bbb0(int nTab)
{
    m_1a0 = m_194;
    m_194 = nTab;
    FUN_14199ba10();
}
MS2_REPLACE_METHOD(0x14199BBB0, UIInventoryDialog, FUN_14199bbb0, 65, 0);

// @0x14199bc00
void UIInventoryDialog::FUN_14199bc00()
{
    if (ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30))
    {
        size_t nCount = m_1a8.GetCount();
        for (size_t i = 0; i < nCount; ++i)
        {
            int nButton = m_1a8.GetAt(i);
            if (nButton == -1)
                continue;
            Unk_Inventory::ItemArray items;
            DAT_143ab2a90.FUN_140a60880((int)i, items);
            int bNew = 0;
            for (unsigned j = 0; j < items.GetCount(); ++j)
            {
                MS2Ptr<CItem> spItem = items[j];
                if (spItem.get() != 0 && spItem->FUN_1405268f0() != 0)
                {
                    bNew = 1;
                    break;
                }
            }
            pDlg->FUN_1409ba0d0("setNew", nButton, bNew);
        }
    }
    m_19c &= ~1;
}
MS2_REPLACE_METHOD(0x14199BC00, UIInventoryDialog, FUN_14199bc00, 499, 0);

// @0x14199be00
void UIInventoryDialog::FUN_14199be00(int nTab)
{
    Unk_Inventory::ItemArray items;
    DAT_143ab2a90.FUN_140a60880(nTab, items);
    for (size_t i = 0; i < items.GetCount(); ++i)
    {
        MS2Ptr<CItem> spItem = items[i];
        if (spItem.get() != 0)
            spItem->FUN_1405268d0(0);
    }
}
MS2_REPLACE_METHOD(0x14199BE00, UIInventoryDialog, FUN_14199be00, 199, 0);

// @0x14199bed0
void UIInventoryDialog::FUN_14199bed0(const __int64& nMesos)
{
    if (DAT_143ab2898 < nMesos)
    {
        FUN_141275260(0x34, 1, 1);
    }
    else if (nMesos < 10 || 50000 < nMesos)
    {
        int nMin = 10;
        Unk_InvNotice(0xee, 1, 1, nMin, FUN_1409404f0(std::min<__int64>(50000, DAT_143ab2898)));
    }
    else
    {
        FUN_14151f200();
    }
}
MS2_REPLACE_METHOD(0x14199BED0, UIInventoryDialog, FUN_14199bed0, 232, 0);

// @0x14199bfc0
int UIInventoryDialog::FUN_14199bfc0()
{
    if (FUN_14185d8b0(FUN_14140ea30()) != 0)
    {
        MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
        if (pPc != 0 && pPc->FUN_14166ce30() == 0)
            return 1;
    }
    return 0;
}
MS2_REPLACE(0x14199BFC0, UIInventoryDialog::FUN_14199bfc0, 84, 0);

// @0x14199c020
void UIInventoryDialog::vfunc_66()
{
    UIDialog::vfunc_66();
    if (m_190 != 0 && dynamic_cast<ASDialog*>((AScript*)m_30) != 0)
    {
        if (UIDialog* pDlg = FUN_140c300a0(m_190))
            FUN_141275c30(pDlg, this, DAT_143b02320, DAT_143b02320);
    }
}
MS2_REPLACE_METHOD(0x14199C020, UIInventoryDialog, vfunc_66, 158, 0);

// @0x14199c0d0
void UIInventoryDialog::FUN_14199c0d0()
{
    int nUsed = DAT_143ab2a90.FUN_140a5cf30(m_194);
    int nTotal = DAT_143ab2a90.FUN_140a5d050(m_194);
    MS2Ptr<Unk_InvExpandLabel> spLabel = GetChild<Unk_InvExpandLabel>("m_expand");
    if (spLabel.get() != 0)
    {
        spLabel->FUN_1422e4a50(StringFormat(L"{0}/{1}", nUsed, nTotal));
        spLabel->vfunc_24(1);
    }
    m_19c &= ~2;
}
MS2_REPLACE_METHOD(0x14199C0D0, UIInventoryDialog, FUN_14199c0d0, 337, 0);

// @0x14199c230
void UIInventoryDialog::FUN_14199c230(int nTab, bool bStack)
{
    COutPacket packet(0x17, 0);
    packet.vfunc_o10_1(8);
    packet.vfunc_o10_1((unsigned char)nTab);
    packet.vfunc_o10_0(bStack);
    FUN_140710590(packet);
}
MS2_REPLACE(0x14199C230, UIInventoryDialog::FUN_14199c230, 117, 0);

// @0x14199c2b0
// MS2-FUNCTIONAL: frame layout of the message box temporaries differs
void UIInventoryDialog::FUN_14199c2b0(CStringW strText)
{
    m_1d8 = strText;
    if (dynamic_cast<ASDialog*>((AScript*)m_30) == 0)
        return;
    InventorySlotBag* pBag = FUN_14140fb30(FUN_1422c8e90(m_188));
    if (pBag == 0)
        return;
    int nSlot = pBag->FUN_14140f620(CStringW(strText));
    if (nSlot < 0)
    {
        if (m_1e0.get() != 0)
        {
            m_1e0->FUN_1422c7630(0);
            static_cast<Unk_InvInput*>(m_1e0.operator->())->FUN_1422e0bd0(CStringW(L""));
            m_1e0->vfunc_24(1);
        }
        MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(0, 0x937, 0, CStringW(L""));
        if (spBox.get() != 0)
        {
            spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIInventoryDialog::FUN_14199c7b0));
            FUN_140d73c60(spBox);
        }
    }
    else if (m_210.operator Unk_InvItemBag*() != 0)
    {
        m_210->FUN_1422cf4f0(nSlot / 6);
    }
}
MS2_REPLACE_METHOD(0x14199C2B0, UIInventoryDialog, FUN_14199c2b0, 851, 0);

// @0x14199c610
void UIInventoryDialog::FUN_14199c610(CStringW strSearch, ATL::CAtlList<CStringW>& names)
{
    Unk_Inventory::ItemArray items;
    DAT_143ab2a90.FUN_140a60880(m_194, items);
    for (unsigned i = 0; i < items.GetCount(); ++i)
    {
        MS2Ptr<CItem> spItem = items[i];
        if (spItem == 0)
            continue;
        CStringW strName = spItem->FUN_140527b10();
        CStringW strLower = FUN_1413fa9b0(strName);
        strSearch.MakeLower();
        strLower.MakeLower();
        if (strLower.Find(strSearch, 0) != -1 && names.Find(strName) == 0)
            names.AddTail(strName);
    }
}
MS2_REPLACE_METHOD(0x14199C610, UIInventoryDialog, FUN_14199c610, 405, 0);

// @0x14199c7b0
bool UIInventoryDialog::FUN_14199c7b0(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0 && dynamic_cast<ASDialog*>((AScript*)m_30) != 0 && m_1e0.get() != 0)
    {
        static_cast<Unk_InvSwfManager*>(FUN_140b632f0())->FUN_1422d4dd0(CString(m_20));
        m_1e0->FUN_1422c7630(1);
    }
    return true;
}
MS2_REPLACE_METHOD(0x14199C7B0, UIInventoryDialog, FUN_14199c7b0, 233, 0);

// @0x14199c8a0
void UIInventoryDialog::FUN_14199c8a0(int* pWidth, int* pHeight)
{
    if (!m_30)
        return;
    *pHeight = 0;
    *pWidth = 0;
    MS2Ptr<ASMovieClip> spPanel = GetChild<ASMovieClip>("m_panel");
    if (spPanel.get() != 0)
    {
        *pWidth = spPanel->FUN_1422c1340();
        *pHeight = spPanel->FUN_1422c13b0();
        MS2Ptr<ASMovieClip> spEmblem = GetChild<ASMovieClip>("m_emblem");
        if (spEmblem.get() != 0)
        {
            float fY = spEmblem->FUN_1422c1110();
            *pHeight += 0.0f <= fY ? 0 : (int)ceilf(-fY);
        }
    }
}
MS2_REPLACE_METHOD(0x14199C8A0, UIInventoryDialog, FUN_14199c8a0, 490, 0);

// @0x14199ca90
// MS2-FUNCTIONAL: frame layout of the key strings differs
void UIInventoryDialog::FUN_14199ca90()
{
    m_1c8 = GetChild<ASButtonBar>("m_tab");
    if (m_1c8 == 0)
        return;
    m_1a8.RemoveAll();
    m_1a8.SetCount(0xf, -1);
    for (size_t i = 0; i < m_1a8.GetCount(); ++i)
        m_1a8[i] = -1;
    FUN_14199d1c0();
    CString strTabPrefix("$s_inventory_tab_");
    CString strTooltipPrefix("$s_tooltip_inven_");
    CString strTooltipClass("export_common_tooltip_tooltipText");
    CString strTopLeft("topLeft");
    CString strLabel("label");
    CString strTooltipData("tooltipData");
    CString strId("id");
    CString strClassName("className");
    CString strAlign("align");
    CString strTabIndex("tabIndex");
    ASDataProvider buttons(2);
    size_t nCount = m_1f0.GetCount();
    for (size_t i = 0; i < nCount; ++i)
    {
        const std::pair<CString, int>& tab = m_1f0[i];
        CString strName(tab.first);
        int nTab = tab.second;
        ASObj item(2);
        CString strTooltipId = strTooltipPrefix + strName;
        CString strText = strTabPrefix + strName;
        ASObj tooltip(2);
        tooltip.FUN_1407cba60(strClassName, CString(strTooltipClass));
        tooltip.FUN_1407cba60(strId, CString(strTooltipId));
        tooltip.FUN_1407cba60(strAlign, CString(strTopLeft));
        item.FUN_1407cba60(strLabel, CString(strText));
        item.FUN_1409adbe0(strTooltipData, Scaleform::GFx::Value(tooltip.FUN_1422bb870()));
        item.FUN_1407cb9c0(strTabIndex, nTab);
        buttons.FUN_1422bc050(Scaleform::GFx::Value(item.FUN_1422bb870()));
        m_1a8.SetAt(nTab, (int)i);
    }
    static_cast<Unk_InvTabBar*>(m_1c8.operator->())->FUN_1422e2db0(buttons.FUN_1422bb870());
    m_1c8->FUN_1422e4190(ParamsDelegate(this, &UIInventoryDialog::FUN_14199a4b0), 0);
}
MS2_REPLACE_METHOD(0x14199CA90, UIInventoryDialog, FUN_14199ca90, 1831, 0);

// @0x14199d1c0
void UIInventoryDialog::FUN_14199d1c0()
{
    m_1f0.RemoveAll();
    m_1f0.Add(std::pair<CString, int>("equip", INV_TAB_EQUIP));
    m_1f0.Add(std::pair<CString, int>("skin", INV_TAB_SKIN));
    m_1f0.Add(std::pair<CString, int>("summon", INV_TAB_SUMMON));
    m_1f0.Add(std::pair<CString, int>("material", INV_TAB_MATERIAL));
    if (FUN_140166410()->FUN_14036d570(0xed))
        m_1f0.Add(std::pair<CString, int>("piece", INV_TAB_PIECE));
    m_1f0.Add(std::pair<CString, int>("mastery", INV_TAB_MASTERY));
    m_1f0.Add(std::pair<CString, int>("life", INV_TAB_LIFE));
    m_1f0.Add(std::pair<CString, int>("quest", INV_TAB_QUEST));
    if (FUN_140166410()->FUN_14036d570(0x2e) == true)
        m_1f0.Add(std::pair<CString, int>("gem", INV_TAB_GEM));
    if (FUN_140166410()->FUN_14036d570(0x8c))
        m_1f0.Add(std::pair<CString, int>("pet", INV_TAB_PET));
    if (FUN_140166410()->FUN_14036d570(0xd3))
        m_1f0.Add(std::pair<CString, int>("lapenshard", INV_TAB_LAPENSHARD));
    m_1f0.Add(std::pair<CString, int>("activeskill", INV_TAB_ACTIVESKILL));
    m_1f0.Add(std::pair<CString, int>("coin", INV_TAB_COIN));
    m_1f0.Add(std::pair<CString, int>("badge", INV_TAB_BADGE));
    m_1f0.Add(std::pair<CString, int>("misc", INV_TAB_MISC));
}
MS2_REPLACE_METHOD(0x14199D1C0, UIInventoryDialog, FUN_14199d1c0, 1646, 0);

// @0x14199d840
int UIInventoryDialog::FUN_14199d840()
{
    Unk_Inventory::ItemArray items;
    DAT_143ab2a90.FUN_140a60880(m_194, items);
    int nCount = 0;
    for (size_t i = 0; i < items.GetCount(); ++i)
    {
        MS2Ptr<CItem> spItem = items.GetAt(i);
        if (spItem->FUN_140528930())
            ++nCount;
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x14199D840, UIInventoryDialog, FUN_14199d840, 216, 0);

// @0x14199d920
int UIInventoryDialog::FUN_14199d920(int nTab)
{
    if (-1 < nTab && nTab < (int)m_1a8.GetCount())
        return m_1a8[nTab];
    return 0;
}
MS2_REPLACE_METHOD(0x14199D920, UIInventoryDialog, FUN_14199d920, 81, 0);

// @0x14199d980
bool UIInventoryDialog::FUN_14199d980()
{
    return !DAT_143ab2a90.FUN_140a5cdc0(m_194);
}
MS2_REPLACE_METHOD(0x14199D980, UIInventoryDialog, FUN_14199d980, 53, 0);

// @0x14199d9c0
CStringW UIInventoryDialog::FUN_14199d9c0()
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return L"";
    CStringW strTooltip(L"");
    MS2Ptr<Unk_InvButton> spButton = m_30->FUN_140acce30<Unk_InvButton>("m_itemBreak");
    if (spButton.get() != 0)
    {
        if (spButton->FUN_1422c2030() == 1 || 0x13 < (unsigned short)pPc->vfunc_78())
        {
            strTooltip = FUN_14025e7a0()->FUN_1422b0570("$s_inventory_item_break_tooltip");
            if (FUN_140166410()->FUN_14036d570(0x3a) == true)
                strTooltip = StringFormat(L"{0}\n{1}", strTooltip, FUN_14025e7a0()->FUN_1422b0570("$s_itembreak_tooltip_skin"));
            if (FUN_140166410()->FUN_14036d570(0x2e) == true)
                strTooltip = StringFormat(L"{0}\n{1}", strTooltip, FUN_14025e7a0()->FUN_1422b0570("$s_itembreak_tooltip_socket"));
        }
        else
        {
            strTooltip = FUN_14025e7a0()->FUN_1422b0570("$s_inventory_item_break_disable_tooltip");
        }
    }
    return strTooltip;
}
MS2_REPLACE_METHOD(0x14199D9C0, UIInventoryDialog, FUN_14199d9c0, 1030, 0);

// @0x14199ddd0
CStringW UIInventoryDialog::FUN_14199ddd0()
{
    CStringW strFormat = FUN_14025e7a0()->FUN_1422b0570("$s_inventory_slotexpand_tooltip");
    int nSlots = FUN_140a66510(m_194) + FUN_140a66750(m_194);
    int nStep = 6;
    return StringFormat(strFormat, nStep, nSlots);
}
MS2_REPLACE_METHOD(0x14199DDD0, UIInventoryDialog, FUN_14199ddd0, 207, 0);

// @0x14199deb0
CStringW UIInventoryDialog::FUN_14199deb0(int bBank)
{
    MyPC* pPc = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pPc == 0)
        return L"";
    CStringW strTooltip(L"");
    MS2Ptr<ASUIComponent> spButton = m_30->FUN_140acce30<ASUIComponent>("m_openBank");
    if (spButton.get() != 0)
    {
        if (bBank == 1)
        {
            strTooltip = FUN_14025e7a0()->FUN_1422b0570("$s_inventory_open_bank_tooltip");
        }
        else
        {
            strTooltip = FUN_14025e7a0()->FUN_1422b0570("$s_inventory_open_bank_disable_tooltip");
            if (FUN_140166410()->FUN_14036d570(0x3c) == true)
                strTooltip = StringFormat(L"{0}\n{1}", strTooltip, FUN_14025e7a0()->FUN_1422b0570("$s_inventory_open_bank_tooltip_pcbang"));
            if (FUN_140166410()->FUN_14036d570(0x4a) == true)
                strTooltip = StringFormat(L"{0}\n{1}", strTooltip, FUN_14025e7a0()->FUN_1422b0570("$s_inventory_open_bank_tooltip_vip"));
        }
    }
    return strTooltip;
}
MS2_REPLACE_METHOD(0x14199DEB0, UIInventoryDialog, FUN_14199deb0, 991, 0);

// @0x14199e2a0
void UIInventoryDialog::FUN_14199e2a0()
{
    if (FUN_140d86260()->vfunc_40(FUN_140a5d0f0()))
        DAT_143ab2a90.FUN_140a62cc0((unsigned char)m_194);
    else
        FUN_1403ed2b0()->FUN_141add1f0();
}
MS2_REPLACE_METHOD(0x14199E2A0, UIInventoryDialog, FUN_14199e2a0, 113, 0);

// ---- UIInviteGroupDialog ---------------------------------------------------------------------------------------------

// One row of the user list (messengerdata.cpp's entry: kind, character id, image, name, level / job line), built from a
// buddy, a party member or a guild member. The copy and the destruction are implicit (dtor 0x14194e470).
struct Unk_InvGroupEntry
{
    Unk_InvGroupEntry(CBuddy& src);                                 // 0x141483300
    Unk_InvGroupEntry(CPartyMember& src);                           // 0x141483580
    Unk_InvGroupEntry(CGuildMember& src);                           // 0x141483830
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
MS2_CHECK_SIZE(Unk_InvGroupEntry, 0x28);

// The counted guild member handle of CGuildInfo's member list (guilddef_1.cpp's Unk_GuildRef with its release).
class Unk_InvGuildRef
{
public:
    ~Unk_InvGuildRef();                                             // 0x1404eead0
    CGuildMember* FUN_1404f0ab0();                                  // get()
private:
    void* m_00;
    CGuildMember* m_p;
};
MS2_CHECK_SIZE(Unk_InvGuildRef, 0x10);

// "m_userList": the user list. Slot 24 (+0xc0) redraws it.
class Unk_InvUserList : public ASTileList
{
public:
    INV_V(16) INV_V(17) INV_V(18) INV_V(19) INV_V(20) INV_V(21) INV_V(22) INV_V(23)
    virtual void vfunc_24(int bRefresh);                            // 24 (+0xc0)
    void FUN_1422dd000(int nRows);                                  // the visible row count
    unsigned FUN_1422dd150();                                       // the entry count
};

// The group chat windows (UIGroupMessengerBrowser at +0x50 of the chat UI).
class Unk_InvGroupWindow { public: int FUN_14194b9d0(__int64 nCharacterId); };   // UIGroupMessenger: is a member
class Unk_InvGroupBrowser { public: Unk_InvGroupWindow* FUN_141952f20(int nGroupId); };
class Unk_InvChatUI
{
public:
    char m_pad_00[0x50];
    Unk_InvGroupBrowser* m_pBrowser;                                // +0x50
};
MS2_CHECK_OFFSET(Unk_InvChatUI, m_pBrowser, 0x50);
Unk_InvChatUI* FUN_141482e80();
CGroupChatManager* FUN_141484720();                                 // TSingleton<CGroupChatManager>::GetInstance
CPartyManager* FUN_1409670d0();                                     // TSingleton<CPartyManager>::GetInstance
CBuddyManager* FUN_14097a780();                                     // TSingleton<CBuddyManager>::GetInstance
class Unk_InvGuildManager
{
public:
    void* m_vfptr;                                                  // TSingleton<CGuildManager>
    CGuildInfo m_info;                                              // +0x08 the own guild
};
Unk_InvGuildManager* FUN_1403ed290();                               // TSingleton<CGuildManager>::GetInstance
MS2Ptr<CMsgBoxData> FUN_14151f820();                                // the message box on top

// @0x14199f740
UIInviteGroupDialog::UIInviteGroupDialog()
    : m_180(0)
{
    m_80 = 1;
    m_88 = 1;
    FUN_141924170(1);
    FUN_1422dc3b0(1);
}

// @0x14199f7e0
UIInviteGroupDialog::~UIInviteGroupDialog()
{
}

// @0x14199f820
CString UIInviteGroupDialog::vfunc_1()
{
    return "InviteGroupDialog";
}
MS2_REPLACE_METHOD(0x14199F820, UIInviteGroupDialog, vfunc_1, 61, 0);

// @0x14199f870
void UIInviteGroupDialog::vfunc_67()
{
    UIModalDialog::vfunc_67();
    FUN_14199fcf0(0);
}
MS2_REPLACE_METHOD(0x14199F870, UIInviteGroupDialog, vfunc_67, 36, 0);

// @0x14199f8a0
void UIInviteGroupDialog::OnLoadInit()
{
    UIObject::OnLoadInit();
    MS2Ptr<ASTextField> spCount = GetChild<ASTextField>("m_userCount");
    if (spCount.get() != 0)
        spCount->FUN_1422c4cd0(FUN_14028dee0(0x48a, 0));
    FUN_1419a0240();
}
MS2_REPLACE_METHOD(0x14199F8A0, UIInviteGroupDialog, OnLoadInit, 237, 0);

// @0x14199f9a0
int UIInviteGroupDialog::vfunc_13()
{
    if (UIDialog::vfunc_13())
        return 1;
    if (!FUN_1419a0b20())
        return 0;
    if (!FUN_14025e7c0()->FUN_14116d9c0(0x1c, 0, 0))
        return 0;
    MS2Ptr<ASTextInput> spInput = GetChild<ASTextInput>("m_textInput");
    if (spInput.get() != 0)
        FUN_141484720()->Invite(m_180, spInput->FUN_1422e0b00());
    return 1;
}
MS2_REPLACE_METHOD(0x14199F9A0, UIInviteGroupDialog, vfunc_13, 309, 0);

// @0x14199fae0
int UIInviteGroupDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp("OnInvite", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_141484720()->Invite(m_180, data.FUN_1422b8f40());
        return 1;
    }
    if (_stricmp("OnChangeUserCount", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_14199fe70(data.FUN_1422b8b10());
    }
    else if (_stricmp("OnRefreshUserCount", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            FUN_1419a0160(data.FUN_1422b8b10());
    }
    return 0;
}
MS2_REPLACE_METHOD(0x14199FAE0, UIInviteGroupDialog, vfunc_28, 506, 0);

// @0x14199fcf0
void UIInviteGroupDialog::FUN_14199fcf0(unsigned nGroupId)
{
    m_180 = nGroupId;
}
MS2_REPLACE_METHOD(0x14199FCF0, UIInviteGroupDialog, FUN_14199fcf0, 25, 0);

// @0x14199fd10
void UIInviteGroupDialog::FUN_14199fd10(int nGroupId, const CStringW& strName, const CStringW& strText)
{
    if (vfunc_55() == 0)
        FUN_1419a0240();
}
MS2_REPLACE_METHOD(0x14199FD10, UIInviteGroupDialog, FUN_14199fd10, 63, 0);

// @0x14199fd60
void UIInviteGroupDialog::FUN_14199fd60(int nGroupId, const CStringW& strName, const CStringW& strOther)
{
    if (vfunc_55() == 0)
        FUN_1419a0240();
}
MS2_REPLACE_METHOD(0x14199FD60, UIInviteGroupDialog, FUN_14199fd60, 63, 0);

// @0x14199fdb0
void UIInviteGroupDialog::FUN_14199fdb0(int nGroupId, const CStringW& strName)
{
    if (vfunc_55() == 0)
        FUN_1419a0240();
}
MS2_REPLACE_METHOD(0x14199FDB0, UIInviteGroupDialog, FUN_14199fdb0, 58, 0);

// @0x14199fdf0
void UIInviteGroupDialog::FUN_14199fdf0(int nGroupId, const CStringW& strName)
{
    if (vfunc_55() == 0)
        FUN_1419a0240();
}
MS2_REPLACE_METHOD(0x14199FDF0, UIInviteGroupDialog, FUN_14199fdf0, 58, 0);

// @0x14199fe30
void UIInviteGroupDialog::FUN_14199fe30(int nGroupId, const CStringW& strName)
{
    if (vfunc_55() == 0)
        FUN_1419a0240();
}
MS2_REPLACE_METHOD(0x14199FE30, UIInviteGroupDialog, FUN_14199fe30, 58, 0);

// @0x14199fe70
void UIInviteGroupDialog::FUN_14199fe70(unsigned nCount)
{
    FUN_1419a0160(nCount);
    MS2Ptr<ASUIComponent> spButton = GetChild<ASUIComponent>("m_inviteFromComunity");
    if (spButton.get() != 0)
    {
        Unk_ChatPtrChat spChat = FUN_141484720()->FUN_14137e630(m_180);
        unsigned nTotal = nCount;
        if (spChat.get() != 0)
            nTotal = nCount + spChat->FUN_14137bad0();
        if (nTotal < 0x15)
        {
            spButton->FUN_1422c1fe0(1);
        }
        else
        {
            spButton->FUN_1422c1fe0(0);
            CStringW strText = FUN_14028de60(0x814);
            MS2Ptr<CMsgBoxData> spTop = FUN_14151f820();
            if (spTop.get() != 0 && spTop->FUN_141a02ce0() == strText)
                return;
            MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0, strText, 0, strText);
            if (spBox.get() != 0)
                FUN_140d73c60(spBox);
        }
    }
}
MS2_REPLACE_METHOD(0x14199FE70, UIInviteGroupDialog, FUN_14199fe70, 735, 0);

// @0x1419a0160
void UIInviteGroupDialog::FUN_1419a0160(unsigned nCount)
{
    MS2Ptr<ASTextField> spCount = GetChild<ASTextField>("m_userCount");
    if (spCount.get() != 0)
        spCount->FUN_1422c4cd0(FUN_14028dee0(0x48a, nCount));
}
MS2_REPLACE_METHOD(0x1419A0160, UIInviteGroupDialog, FUN_1419a0160, 204, 0);

// @0x1419a0240
void UIInviteGroupDialog::FUN_1419a0240()
{
    EntryList entries(10);
    FUN_1419a06d0(entries);
    FUN_1419a07d0(entries);
    FUN_1419a08f0(entries);
    MS2Ptr<Unk_InvUserList> spList = GetChild<Unk_InvUserList>("m_userList");
    if (spList.get() != 0)
    {
        spList->FUN_1422dd1d0();
        for (POSITION pos = entries.GetHeadPosition(); pos != 0; entries.GetNext(pos))
        {
            Unk_InvGroupEntry entry = entries.GetAt(pos);
            ASObj row(2);
            row.FUN_1407cb9c0(s_strOnline, entry.FUN_141483d80());
            row.FUN_1407cbb20(s_strIconPath, entry.FUN_141483dc0());
            row.FUN_1407cbb20(s_strCharacterName, entry.FUN_141483e10());
            row.FUN_1407cbb20(s_strLevelAndJobName, entry.FUN_141483e60());
            if (entry.FUN_141483d80() != 0)
                spList->FUN_1422dd230(row);
        }
        spList->FUN_1422dd000(spList->FUN_1422dd150() < 9 ? spList->FUN_1422dd150() : 8);
        spList->vfunc_24(1);
    }
    MS2Ptr<ASTextInput> spInput = GetChild<ASTextInput>("m_textInput");
    if (spInput.get() != 0)
        spInput->FUN_1422e0a60(CString(""));
    if (ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30))
        pDlg->Invoke("updateUserCount");
}
MS2_REPLACE_METHOD(0x1419A0240, UIInviteGroupDialog, FUN_1419a0240, 1149, 0);

// @0x1419a06d0
void UIInviteGroupDialog::FUN_1419a06d0(EntryList& entries)
{
    ATL::CAtlArray<MS2Ptr<CPartyMember> >& members = FUN_1409670d0()->FUN_14162ba30();
    size_t nCount = members.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        CPartyMember* pMember = members[i].get();
        if (pMember != 0 && FUN_1419a0a10(pMember->user.m_8, entries) == 0)
            entries.AddTail(Unk_InvGroupEntry(*pMember));
    }
}
MS2_REPLACE_METHOD(0x1419A06D0, UIInviteGroupDialog, FUN_1419a06d0, 243, 0);

// @0x1419a07d0
void UIInviteGroupDialog::FUN_1419a07d0(EntryList& entries)
{
    ATL::CAtlArray<Unk_InvGuildRef> members;
    FUN_1403ed290()->m_info.FUN_1404d0420(&members);
    size_t nCount = members.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        CGuildMember* pMember = members[i].FUN_1404f0ab0();
        if (pMember != 0 && FUN_1419a0a10(pMember->data.f08, entries) == 0)
            entries.AddTail(Unk_InvGroupEntry(*pMember));
    }
}
MS2_REPLACE_METHOD(0x1419A07D0, UIInviteGroupDialog, FUN_1419a07d0, 268, 0);

// @0x1419a08f0
void UIInviteGroupDialog::FUN_1419a08f0(EntryList& entries)
{
    ATL::CAtlArray<CBuddyManager::Ptr> buddies;
    FUN_14097a780()->FUN_140ae4df0(buddies);
    size_t nCount = buddies.GetCount();
    for (size_t i = 0; i < nCount; i++)
    {
        CBuddy* pBuddy = buddies[i].get();
        if (pBuddy != 0 && FUN_1419a0a10(pBuddy->FUN_1401cc230(), entries) == 0)
            entries.AddTail(Unk_InvGroupEntry(*pBuddy));
    }
}
MS2_REPLACE_METHOD(0x1419A08F0, UIInviteGroupDialog, FUN_1419a08f0, 268, 0);

// @0x1419a0a10
int UIInviteGroupDialog::FUN_1419a0a10(__int64 nCharacterId, EntryList& entries)
{
    if (FUN_141482e80()->m_pBrowser != 0)
    {
        Unk_InvGroupWindow* pWindow = FUN_141482e80()->m_pBrowser->FUN_141952f20(m_180);
        if (pWindow != 0 && pWindow->FUN_14194b9d0(nCharacterId))
            return 1;
    }
    for (POSITION pos = entries.GetHeadPosition(); pos != 0; entries.GetNext(pos))
    {
        Unk_InvGroupEntry entry = entries.GetAt(pos);
        if (entry.FUN_141483da0() == nCharacterId)
            return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419A0A10, UIInviteGroupDialog, FUN_1419a0a10, 254, 0);

// @0x1419a0b20
bool UIInviteGroupDialog::FUN_1419a0b20()
{
    MS2Ptr<ASTextInput> spInput = GetChild<ASTextInput>("m_textInput");
    if (spInput.get() != 0 && spInput->FUN_1422c76c0())
        return true;
    UIMessageBox* pBox = FUN_14151f890();
    if (pBox != 0 && pBox->FUN_1419f8270() == 0)
        return false;
    return FUN_1403ed2b0()->FUN_141adbb00() == 0;
}
MS2_REPLACE_METHOD(0x1419A0B20, UIInviteGroupDialog, FUN_1419a0b20, 234, 0);

// ---- UIItemBreakBase / UIItemBreakDialog / UIItemBreakDonationDialog -------------------------------------------------

// The slot bag movie of "m_itemBag" ("instance"): the bag name and the scrolling.
class Unk_IbSlotBag : public ASObj
{
public:
    void FUN_1422cf4f0(int nRow);                                   // scroll to a row
    int FUN_1422cf520();                                            // the scroll position
};
// The slot bag registered under a movie name (FUN_1422c8e90): redraw a slot.
class Unk_IbBreakBag;
Unk_IbBreakBag* FUN_1414109f0(Unk_InvBagBind* pBind);               // DynamicCast to the item break bag
void FUN_1414109a0(Unk_IbBreakBag* pBag, int nIndex);               // a slot changed
void FUN_141410780(const CString& strName);                         // drop the item break bag of a name
void FUN_1414106d0(const CString& strName);                         // create the item break bag of a name
void FUN_141415450(const CString& strName, MS2Ptr<CItem> spItem, int a, int nFlags, int b);   // bind an item slot to a name
void FUN_141415600(const CString& strName);                         // release an item slot name
void FUN_141276180(const CString& strSound, const CString& strArg);  // play a UI sound
int FUN_14053feb0(int nItemId);                                     // the default rarity of an item
CStringW FUN_141425950(int nItemId);                                // the item name
CStringW FUN_140b99450(CStringW strKey, const CStringW& strName, const int& nCount);   // the localized "{name} x{n}"
CStringW FUN_140e9fe10(CStringW strKey, const CStringW& strName, const int& nLow, const int& nHigh);
CStringW FUN_140298ea0(CStringW strKey);                            // a localized string
void FUN_1412751b0(const CStringW& strText, int nType);             // a notice
CItemBreakManager* FUN_1409c4b20();                                 // TSingleton<CItemBreakManager>::GetInstance
UIInventoryDialog* FUN_1405344f0(int nUiId);                        // the inventory window
int FUN_1405352d0(UIItemBreakBase* pDialog);                        // breaking (m_188)
void FUN_140c3fe30(UIInventoryDialog* pInventory, int nTab);        // select a tab of the inventory
class Unk_IbRankTexts { public: CStringW FUN_141813150(int nRank); };   // the rarity names
Unk_IbRankTexts* FUN_1401a9d70();
class Unk_IbAnalytics;
Unk_IbAnalytics* FUN_140d8ee90();
void FUN_140a1f970(Unk_IbAnalytics* p, const CString& strEvent, const CString& strName);
// The UI message to the inventory ("openWindowPos", the ui id).
class Unk_IbUIMsg : public UIMsg
{
public:
    Unk_IbUIMsg();                                                  // 0x1422e4490
    ~Unk_IbUIMsg();                                                 // 0x140c30570
    void FUN_1422b82b0(const char* szMethod);
    void FUN_1422b7f70(int n);
    void* m_pad[10];
};
// "m_bundleTypeDropdown" / "m_bundleRankDropdown": slot 24 (+0xc0) redraws.
class Unk_IbDropdown : public ASDropdownMenu
{
public:
    INV_V(16) INV_V(17) INV_V(18) INV_V(19) INV_V(20) INV_V(21) INV_V(22) INV_V(23)
    virtual void vfunc_24(int bRefresh);                            // 24 (+0xc0)
    void FUN_1422dfc70(const ASObj& item);                          // add an item
    int FUN_1422dfb90();                                            // the item count
};

// @0x1419a1280
UIItemBreakBase::UIItemBreakBase()
    : m_190(10)
{
    m_188 = 0;
    FUN_141924170(1);
    m_164 = 1;
}

// @0x1419a1360
UIItemBreakBase::~UIItemBreakBase()
{
}

// @0x1419a1400
int UIItemBreakBase::vfunc_46()
{
    return UISwfEntity::vfunc_46() != 0;
}
MS2_REPLACE_METHOD(0x1419A1400, UIItemBreakBase, vfunc_46, 37, 0);

// @0x1419a1430
void UIItemBreakBase::FUN_1419a1430()
{
    FUN_141410780(vfunc_1());
    FUN_1414106d0(vfunc_1());
    MS2Ptr<ASMovieClip> spBag = GetChild<ASMovieClip>("m_itemBag");
    if (spBag.get() != 0)
    {
        MS2Ptr<Unk_IbSlotBag> spSlots = spBag->FUN_140accef0<Unk_IbSlotBag>("instance");
        if (spSlots.get() != 0)
            spSlots->FUN_1407cba60("bagId", vfunc_1());
    }
    vfunc_85(true, 0);
}
MS2_REPLACE_METHOD(0x1419A1430, UIItemBreakBase, FUN_1419a1430, 541, 0);

// @0x1419a1660
int UIItemBreakBase::FUN_1419a1660()
{
    if (m_30 == 0)
        return 0;
    MS2Ptr<ASMovieClip> spBag = m_30->FUN_1409b4560("m_itemBag");
    if (spBag.get() == 0)
        return 0;
    return spBag->FUN_1422bfca0();
}
MS2_REPLACE_METHOD(0x1419A1660, UIItemBreakBase, FUN_1419a1660, 214, 0);

// @0x1419a1740
void UIItemBreakBase::OnLoadInit()
{
    UIObject::OnLoadInit();
    m_188 = 0;
}
MS2_REPLACE_METHOD(0x1419A1740, UIItemBreakBase, OnLoadInit, 39, 0);

// @0x1419a1770
void UIItemBreakBase::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1419a1430();
    FUN_140a6a840()->FUN_1419cae20(this);
    FUN_1409c4b20()->FUN_140531c20(vfunc_88());
    if (UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d))
    {
        pInventory->FUN_141999f60();
        pInventory->FUN_141999e00();
    }
}
MS2_REPLACE_METHOD(0x1419A1770, UIItemBreakBase, OnLoadComplete, 172, 0);

// @0x1419a1830
void UIItemBreakBase::vfunc_26()
{
    UIDialog::vfunc_26();
    if (UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d))
    {
        pInventory->FUN_141999f60();
        pInventory->FUN_141999e00();
    }
    FUN_141410780(vfunc_1());
}
#ifndef MS2_STANDALONE
namespace {
struct Unk_IbDropControlsThunk : UIItemBreakBase
{
    void Call() { UIItemBreakBase::vfunc_26(); }
};
}
MS2_REPLACE_IMPL(0x1419A1830, ::ms2::hook::detail::MemberToVoid(&Unk_IbDropControlsThunk::Call), "UIItemBreakBase::vfunc_26()", 134, 0);
#endif

// @0x1419a18c0
void UIItemBreakBase::vfunc_67()
{
    UIDialog::vfunc_67();
    FUN_141410780(vfunc_1());
    FUN_1419a1fb0();
    FUN_140a6a840()->FUN_1419caeb0(this);
    FUN_1409c4b20()->FUN_140531cc0();
}
MS2_REPLACE_METHOD(0x1419A18C0, UIItemBreakBase, vfunc_67, 167, 0);

// @0x1419a1970
int UIItemBreakBase::vfunc_73()
{
    UIDialog* pLock = FUN_140613770(0x4f08);
    if (pLock != 0 && pLock->vfunc_55() == 0)
        return 0;
    return UIDialog::vfunc_73();
}
MS2_REPLACE_METHOD(0x1419A1970, UIItemBreakBase, vfunc_73, 86, 0);

// @0x1419a19d0
void UIItemBreakBase::vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs)
{
}
MS2_REPLACE_METHOD(0x1419A19D0, UIItemBreakBase, vfunc_45, 21, 0);

// @0x1419a19f0
int UIItemBreakBase::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0;
}
MS2_REPLACE_METHOD(0x1419A19F0, UIItemBreakBase, vfunc_28, 67, 0);

// @0x1419a1a40
void UIItemBreakBase::vfunc_15()
{
    if (vfunc_55() == 0)
        FUN_1409c4b20()->FUN_140531ed0();
}
MS2_REPLACE_METHOD(0x1419A1A40, UIItemBreakBase, vfunc_15, 52, 0);

// @0x1419a1a80
void UIItemBreakBase::vfunc_66()
{
    UIDialog::vfunc_66();
    UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
    if (pInventory != 0 && pInventory->vfunc_55() != 0)
    {
        if (dynamic_cast<ASDialog*>((AScript*)m_30) != 0)
        {
            Unk_IbUIMsg msg;
            msg.FUN_1422b82b0("openWindowPos");
            msg.FUN_1422b7f70(vfunc_48());
            pInventory->OnMessage(this, &msg);
        }
    }
}
MS2_REPLACE_METHOD(0x1419A1A80, UIItemBreakBase, vfunc_66, 283, 0);

// @0x1419a1bb0
void UIItemBreakBase::vfunc_43()
{
    UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d);
    if (pInventory != 0 && pInventory->FUN_1422dc430())
    {
        float fX = 0.0f;
        float fY = 0.0f;
        ASDialog* pOther = dynamic_cast<ASDialog*>((AScript*)pInventory->FUN_1422dba00());
        if (pOther != 0)
        {
            fX = pOther->FUN_1422c10a0();
            fY = pOther->FUN_1422c1110();
        }
        if (ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30))
        {
            pDlg->FUN_1422c00f0(fX - (float)pDlg->FUN_1422c1340(), fY);
            return;
        }
    }
    UIDialog::vfunc_43();
}
MS2_REPLACE_METHOD(0x1419A1BB0, UIItemBreakBase, vfunc_43, 361, 0);

// @0x1419a1d20
void UIItemBreakBase::FUN_1419a1d20(int nIndex)
{
    Unk_IbBreakBag* pBag = FUN_1414109f0(FUN_1422c8e90(vfunc_1()));
    if (pBag != 0)
        FUN_1414109a0(pBag, nIndex);
    vfunc_85(false, nIndex);
}
MS2_REPLACE_METHOD(0x1419A1D20, UIItemBreakBase, FUN_1419a1d20, 145, 0);

// @0x1419a1dc0
CString UIItemBreakBase::FUN_1419a1dc0(int nItemId, int nRarity, int nCount)
{
    CItem* pItem = new CItem();
    if (!pItem->FUN_140523c40(nItemId, nRarity, 0))
        return "";
    pItem->FUN_140526c70(nCount);
    CString strName;
    strName.Format("%s_%d", (const char*)vfunc_1(), nItemId);
    FUN_141415450(strName, MS2Ptr<CItem>(pItem), 0, 0x401, 0);
    m_190.AddTail(strName);
    return strName;
}
MS2_REPLACE_METHOD(0x1419A1DC0, UIItemBreakBase, FUN_1419a1dc0, 475, 0);

// @0x1419a1fb0
void UIItemBreakBase::FUN_1419a1fb0()
{
    for (POSITION pos = m_190.GetHeadPosition(); pos != 0; m_190.GetNext(pos))
        FUN_141415600(CString(m_190.GetAt(pos)));
    m_190.RemoveAll();
}
MS2_REPLACE_METHOD(0x1419A1FB0, UIItemBreakBase, FUN_1419a1fb0, 163, 0);

// @0x1419a2060
void UIItemBreakBase::FUN_1419a2060()
{
    if (m_30 != 0)
    {
        m_30->Invoke("startBreak");
        m_188 = 1;
    }
    FUN_141276180(s_strExtractProgress, CString(""));
}
MS2_REPLACE_METHOD(0x1419A2060, UIItemBreakBase, FUN_1419a2060, 155, 0);

// @0x1419a2110
void UIItemBreakBase::FUN_1419a2110()
{
    if (m_30 != 0)
    {
        m_30->Invoke("endBreak");
        m_188 = 0;
    }
    FUN_141276180(s_strExtractEnd, CString(""));
}
MS2_REPLACE_METHOD(0x1419A2110, UIItemBreakBase, FUN_1419a2110, 155, 0);

// @0x1419a21c0
UIItemBreakDialog::UIItemBreakDialog()
    : m_1c8(10)
{
    m_1c0 = 1;
    m_1f8 = 0;
    m_1fc = 1;
    m_200.clear();
}

// @0x1419a22a0
UIItemBreakDialog::~UIItemBreakDialog()
{
}

// @0x1419a2330
CString UIItemBreakDialog::vfunc_1()
{
    return "ItemBreakDialog";
}
MS2_REPLACE_METHOD(0x1419A2330, UIItemBreakDialog, vfunc_1, 61, 0);

// @0x1419a2380
void UIItemBreakDialog::OnLoadInit()
{
    UIItemBreakBase::OnLoadInit();
    FUN_140a1f970(FUN_140d8ee90(), "dialog_open", "item_break");
}
MS2_REPLACE_METHOD(0x1419A2380, UIItemBreakDialog, OnLoadInit, 118, 0);

// @0x1419a2400
void UIItemBreakDialog::OnLoadComplete()
{
    UIItemBreakBase::OnLoadComplete();
    m_200.clear();
    MS2Ptr<Unk_IbDropdown> spType = GetChild<Unk_IbDropdown>("m_bundleTypeDropdown");
    if (spType.get() != 0)
    {
        int nIndex = 0;
        ASObj equip(2);
        equip.FUN_1407cb9c0("type", INV_TAB_EQUIP);
        equip.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570("$s_inventory_tab_equip"));
        spType->FUN_1422dfc70(equip);
        m_200.insert(std::make_pair((int)INV_TAB_EQUIP, nIndex));
        nIndex++;
        if (FUN_140166410()->FUN_14036d570(0x3a))
        {
            ASObj skin(2);
            skin.FUN_1407cb9c0("type", INV_TAB_SKIN);
            skin.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570("$s_inventory_tab_skin"));
            spType->FUN_1422dfc70(skin);
            m_200.insert(std::make_pair((int)INV_TAB_SKIN, nIndex));
            nIndex++;
        }
        if (FUN_140166410()->FUN_14036d570(0x2e))
        {
            ASObj gem(2);
            gem.FUN_1407cb9c0("type", INV_TAB_GEM);
            gem.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570("$s_inventory_tab_gem"));
            spType->FUN_1422dfc70(gem);
            m_200.insert(std::make_pair((int)INV_TAB_GEM, nIndex));
            nIndex++;
        }
        ASObj pet(2);
        pet.FUN_1407cb9c0("type", INV_TAB_PET);
        pet.FUN_1407cbb20("label", FUN_14025e7a0()->FUN_1422b0570("$s_inventory_tab_pet"));
        spType->FUN_1422dfc70(pet);
        m_200.insert(std::make_pair((int)INV_TAB_PET, nIndex));
        nIndex++;
        int nRows = spType->FUN_1422dfb90();
        if (nRows < 2)
            nRows = 1;
        spType->FUN_1422df5f0(nRows);
        int nSelect = 0;
        std::map<int, int>::iterator it = m_200.find(m_1f8);
        if (it != m_200.end())
            nSelect = it->second;
        spType->FUN_1422df690(nSelect);
        spType->vfunc_24(1);
    }
    MS2Ptr<Unk_IbDropdown> spRank = GetChild<Unk_IbDropdown>("m_bundleRankDropdown");
    if (spRank.get() != 0)
    {
        CStringW strOrBelow = FUN_140298ea0(CStringW(L"s_itembreak_rank_or_below"));
        for (int nRank = 1; nRank < 7; nRank++)
        {
            ASObj rank(2);
            rank.FUN_1407cb9c0("rank", nRank);
            rank.FUN_1407cbb20("label", StringFormat(L"{0} {1}", FUN_1401a9d70()->FUN_141813150(nRank), strOrBelow));
            spRank->FUN_1422dfc70(rank);
        }
        int nRows = spRank->FUN_1422dfb90();
        if (nRows < 2)
            nRows = 1;
        spRank->FUN_1422df5f0(nRows);
        spRank->FUN_1422df690(m_1fc - 1);
        spRank->vfunc_24(1);
    }
}
MS2_REPLACE_METHOD(0x1419A2400, UIItemBreakDialog, OnLoadComplete, 2266, 0);

// @0x1419a2ce0
void UIItemBreakDialog::vfunc_67()
{
    UIItemBreakBase::vfunc_67();
    FUN_1419a4c80();
    FUN_140a1f970(FUN_140d8ee90(), "dialog_close", "item_break");
}
MS2_REPLACE_METHOD(0x1419A2CE0, UIItemBreakDialog, vfunc_67, 128, 0);

// @0x1419a2d70
int UIItemBreakDialog::vfunc_73()
{
    UIDialog* pDonation = FUN_1405346e0(0x4e8e);
    if (pDonation == 0)
        return UIItemBreakBase::vfunc_73();
    return pDonation->FUN_1422dc430() == 0;
}
MS2_REPLACE_METHOD(0x1419A2D70, UIItemBreakDialog, vfunc_73, 85, 0);

// @0x1419a2dd0
int UIItemBreakDialog::vfunc_86()
{
    if (FUN_1405352d0(this) != 0)
        return 0;
    return FUN_1419a1660();
}
MS2_REPLACE_METHOD(0x1419A2DD0, UIItemBreakDialog, vfunc_86, 42, 0);

// @0x1419a2e10
int UIItemBreakDialog::vfunc_88()
{
    return m_1c0;
}
MS2_REPLACE_METHOD(0x1419A2E10, UIItemBreakDialog, vfunc_88, 17, 0);

// @0x1419a2e30
void UIItemBreakDialog::vfunc_85(bool bReset, int nIndex)
{
    MS2Ptr<ASUIComponent> spBreak = GetChild<ASUIComponent>("m_break");
    if (spBreak.get() != 0)
        spBreak->FUN_1422c1fe0(FUN_1409c4b20()->FUN_140532b60());
    MS2Ptr<ASMovieClip> spBag = GetChild<ASMovieClip>("m_itemBag");
    if (spBag.get() != 0)
    {
        MS2Ptr<Unk_IbSlotBag> spSlots = spBag->FUN_140accef0<Unk_IbSlotBag>("instance");
        if (spSlots.get() != 0)
        {
            if (!bReset)
            {
                int nLastRow = (int)FUN_1409c4b20()->FUN_140533e20() / 5;
                int nRow = nIndex / 5;
                nRow = (std::min)((std::max)(0, nRow), nLastRow);
                int nTop = spSlots->FUN_1422cf520();
                if (nRow < nTop || nTop + 2 < nRow)
                    spSlots->FUN_1422cf4f0(nRow);
            }
            else
            {
                int nLastRow = (int)FUN_1409c4b20()->FUN_140533e20() / 5;
                spSlots->FUN_1422cf4f0((std::max)(nLastRow - 2, 0));
            }
        }
    }
}
MS2_REPLACE_METHOD(0x1419A2E30, UIItemBreakDialog, vfunc_85, 729, 0);

// @0x1419a3110
int UIItemBreakDialog::vfunc_46()
{
    if (!UIItemBreakBase::vfunc_46())
        return 0;
    MS2Ptr<ASTextField> spDesc = m_30->FUN_1409b4620("m_desc");
    if (spDesc.get() != 0)
    {
        CStringW strDesc = spDesc->FUN_1422c4da0();
        if (FUN_140166410()->FUN_14036d570(0x3a) == true)
            strDesc = StringFormat(L"{0}, {1}", strDesc, FUN_14025e7a0()->FUN_1422b0570("$s_itembreak_desc_skin"));
        if (FUN_140166410()->FUN_14036d570(0x2e) == true)
            strDesc = StringFormat(L"{0}, {1}", strDesc, FUN_14025e7a0()->FUN_1422b0570("$s_itembreak_desc_socket"));
        spDesc->FUN_1422c4cd0(strDesc);
    }
    MS2Ptr<ASUIComponent> spInfo = m_30->FUN_140acce30<ASUIComponent>("m_info");
    if (spInfo.get() != 0)
    {
        CStringW strTooltip = FUN_14025e7a0()->FUN_1422b0570("$s_itembreak_tooltip_desc");
        if (FUN_140166410()->FUN_14036d570(0x3a) == true)
            strTooltip = StringFormat(L"{0}\n{1}", strTooltip, FUN_14025e7a0()->FUN_1422b0570("$s_itembreak_tooltip_skin"));
        if (FUN_140166410()->FUN_14036d570(0x2e) == true)
            strTooltip = StringFormat(L"{0}\n{1}", strTooltip, FUN_14025e7a0()->FUN_1422b0570("$s_itembreak_tooltip_socket"));
        spInfo->FUN_1422c7b40(strTooltip);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1419A3110, UIItemBreakDialog, vfunc_46, 1422, 0);

// @0x1419a36b0
void UIItemBreakDialog::vfunc_84(CInPacket* pPacket)
{
    if (m_30 == 0)
        return;
    FUN_1419a1fb0();
    ASArray rows(2);
    ASObj data(2);
    unsigned nCount = pPacket->vfunc_o8_3();
    for (unsigned i = 0; i < nCount; i++)
    {
        int nItemId = pPacket->vfunc_o8_3();
        int nAmount = pPacket->vfunc_o8_3();
        if (nAmount != 0)
        {
            ASObj row(2);
            CStringW strText = FUN_140b99450(CStringW(L"s_itembreak_preview_static"), FUN_141425950(nItemId), nAmount);
            CString strBinding = FUN_1419a1dc0(nItemId, FUN_14053feb0(nItemId), nAmount);
            row.FUN_1407cba60("slotBinding", CString(strBinding));
            row.FUN_1407cbbe0("toggle", false);
            row.FUN_1407cbb20("text", CStringW(strText));
            rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
        }
    }
    data.FUN_1409adbe0("dp", Scaleform::GFx::Value(rows.FUN_1422bb870()));
    m_30->Invoke("setResult", data);
    FUN_1419a2110();
}
MS2_REPLACE_METHOD(0x1419A36B0, UIItemBreakDialog, vfunc_84, 957, 0);

// @0x1419a3a80
int UIItemBreakDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIItemBreakBase::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onClickBreak") == 0)
    {
        if (FUN_1409c4b20()->FUN_140532b60() == 0)
        {
            FUN_1412751b0(FUN_1409eec40(0xe6), 0x14);
        }
        else
        {
            int nRarity = FUN_1409c4b20()->FUN_140532c30();
            if (nRarity == 6 || nRarity == 5)
            {
                bool bLegendary = nRarity != 6;
                CStringW strText = bLegendary ? FUN_14028b8e0(CStringW(L"s_itembreak_legendary_item"))
                                              : FUN_14028b8e0(CStringW(L"s_itembreak_artifact_item"));
                CStringW strCheck = bLegendary ? FUN_14028b8e0(CStringW(L"s_itembreak_legendary_item_checkbox"))
                                               : FUN_14028b8e0(CStringW(L"s_itembreak_artifact_item_checkbox"));
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x19, strText, 0, CStringW(L""));
                if (spBox.get() != 0)
                {
                    spBox->FUN_141a01800(1);
                    spBox->FUN_141a026f0(1);
                    spBox->FUN_141a024a0(0);
                    spBox->FUN_141a024e0(strCheck, 0);
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemBreakDialog::vfunc_87));
                    FUN_140d73c60(spBox);
                }
            }
            else if (nRarity == 4)
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(1, 0x8f9, 0, CStringW(L""));
                if (spBox.get() != 0)
                {
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemBreakDialog::vfunc_87));
                    FUN_140d73c60(spBox);
                }
            }
            else
            {
                FUN_1419a2060();
            }
        }
        return 1;
    }
    if (_stricmp(szMethod, "onSendBreak") == 0)
        return FUN_1409c4b20()->FUN_140532d80();
    if (_stricmp(szMethod, "onResetBreak") == 0)
    {
        if (UIInventoryDialog* pInventory = FUN_1405344f0(0x4e2d))
            FUN_140c3fe30(pInventory, 7);
        return 1;
    }
    if (_stricmp(szMethod, "OnBundleType") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_1f8 = data.FUN_1422b8a10();
        return 1;
    }
    if (_stricmp(szMethod, "OnBundleRank") == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs))
            m_1fc = data.FUN_1422b8a10();
        return 1;
    }
    if (_stricmp(szMethod, "OnBundleRegister") == 0)
    {
        FUN_1409c4b20()->FUN_1405332b0(m_1f8, m_1fc);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1419A3A80, UIItemBreakDialog, vfunc_28, 2436, 0);

// @0x1419a4420
bool UIItemBreakDialog::vfunc_87(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
        FUN_1419a2060();
    return true;
}
MS2_REPLACE_METHOD(0x1419A4420, UIItemBreakDialog, vfunc_87, 46, 0);

// @0x1419a4460
void UIItemBreakDialog::FUN_1419a4460()
{
    if (!m_30)
        return;
    m_188 = 0;
    m_30->Invoke("resetBreak");
}
MS2_REPLACE_METHOD(0x1419A4460, UIItemBreakDialog, FUN_1419a4460, 102, 0);

// @0x1419a44d0
void UIItemBreakDialog::FUN_1419a44d0(CInPacket* pPacket)
{
    if (!m_30)
        return;
    FUN_1419a4c80();
    std::map<int, ItemBreakCommon::BreakPreview> previews;
    unsigned nCount = pPacket->vfunc_o8_3();
    for (unsigned i = 0; i < nCount; i++)
    {
        ItemBreakCommon::BreakPreview preview;
        int nItemId = pPacket->vfunc_o8_3();
        preview.FUN_140530920(*reinterpret_cast<Unk_BreakPacket*>(pPacket));
        previews[nItemId] = preview;
    }
    ASArray rows(2);
    ASObj data(2);
    for (std::map<int, ItemBreakCommon::BreakPreview>::iterator it = previews.begin(); it != previews.end(); ++it)
    {
        int nItemId = it->first;
        if (it->second.FUN_1405309d0() == 0)
            continue;
        CStringW strText;
        if (it->second.FUN_140530990() == 0)
            strText = FUN_140b99450(CStringW(L"s_itembreak_preview_static"), FUN_141425950(nItemId), it->second.low);
        else
            strText = FUN_140e9fe10(CStringW(L"s_itembreak_preview_random"), FUN_141425950(nItemId), it->second.low, it->second.high);
        ASObj row(2);
        CString strBinding = FUN_1419a4aa0(nItemId);
        row.FUN_1407cba60("slotBinding", CString(strBinding));
        row.FUN_1407cbbe0("toggle", false);
        row.FUN_1407cbb20("text", CStringW(strText));
        rows.FUN_1422bc050(Scaleform::GFx::Value(row.FUN_1422bb870()));
    }
    data.FUN_1409adbe0("dp", Scaleform::GFx::Value(rows.FUN_1422bb870()));
    m_30->Invoke("setPreview", data);
}
MS2_REPLACE_METHOD(0x1419A44D0, UIItemBreakDialog, FUN_1419a44d0, 1478, 0);

// @0x1419a4aa0
CString UIItemBreakDialog::FUN_1419a4aa0(int nItemId)
{
    CItem* pItem = new CItem();
    if (!pItem->FUN_140523c40(nItemId, FUN_14053feb0(nItemId), 0))
        return "";
    CString strName;
    strName.Format("%s_preview_%d", (const char*)vfunc_1(), nItemId);
    FUN_141415450(strName, MS2Ptr<CItem>(pItem), 0, 0x401, 0);
    m_1c8.AddTail(strName);
    return strName;
}
MS2_REPLACE_METHOD(0x1419A4AA0, UIItemBreakDialog, FUN_1419a4aa0, 460, 0);

// @0x1419a4c80
void UIItemBreakDialog::FUN_1419a4c80()
{
    for (POSITION pos = m_1c8.GetHeadPosition(); pos != 0; m_1c8.GetNext(pos))
        FUN_141415600(CString(m_1c8.GetAt(pos)));
    m_1c8.RemoveAll();
}
MS2_REPLACE_METHOD(0x1419A4C80, UIItemBreakDialog, FUN_1419a4c80, 163, 0);

// @0x1419a4d30
UIItemBreakDonationDialog::UIItemBreakDonationDialog()
{
    m_1c0 = 2;
}

// @0x1419a4db0
UIItemBreakDonationDialog::~UIItemBreakDonationDialog()
{
}

// @0x1419a4e20
CString UIItemBreakDonationDialog::vfunc_1()
{
    return "ItemBreakDonationDialog";
}
MS2_REPLACE_METHOD(0x1419A4E20, UIItemBreakDonationDialog, vfunc_1, 61, 0);

// @0x1419a4e70
void UIItemBreakDonationDialog::OnLoadInit()
{
    UIItemBreakBase::OnLoadInit();
    FUN_140a1f970(FUN_140d8ee90(), "dialog_open", "item_break");
}
MS2_REPLACE_METHOD(0x1419A4E70, UIItemBreakDonationDialog, OnLoadInit, 118, 0);

// @0x1419a4ef0
void UIItemBreakDonationDialog::vfunc_67()
{
    UIItemBreakBase::vfunc_67();
    FUN_140a1f970(FUN_140d8ee90(), "dialog_close", "item_break");
}
MS2_REPLACE_METHOD(0x1419A4EF0, UIItemBreakDonationDialog, vfunc_67, 118, 0);

// @0x1419a4f70
int UIItemBreakDonationDialog::vfunc_73()
{
    UIDialog* pBreak = FUN_140534590(0x4e8d);
    if (pBreak == 0)
        return UIItemBreakBase::vfunc_73();
    return pBreak->FUN_1422dc430() == 0;
}
MS2_REPLACE_METHOD(0x1419A4F70, UIItemBreakDonationDialog, vfunc_73, 85, 0);

// @0x1419a4fd0
int UIItemBreakDonationDialog::vfunc_86()
{
    if (FUN_1405352d0(this) != 0)
        return 0;
    return FUN_1419a1660();
}
MS2_REPLACE_METHOD(0x1419A4FD0, UIItemBreakDonationDialog, vfunc_86, 42, 0);

// @0x1419a5010
int UIItemBreakDonationDialog::vfunc_88()
{
    return m_1c0;
}
MS2_REPLACE_METHOD(0x1419A5010, UIItemBreakDonationDialog, vfunc_88, 17, 0);

// @0x1419a5030
void UIItemBreakDonationDialog::vfunc_85(bool bReset, int nIndex)
{
}
MS2_REPLACE_METHOD(0x1419A5030, UIItemBreakDonationDialog, vfunc_85, 15, 0);

// @0x1419a5050
int UIItemBreakDonationDialog::vfunc_46()
{
    MS2Ptr<ASUIComponent> spInfo = m_30->FUN_140acce30<ASUIComponent>("m_info");
    if (spInfo.get() != 0)
        spInfo->FUN_1422c7b40(FUN_14025e7a0()->FUN_1422b0570("$s_itembreak_donation_tooltip_desc"));
    return 1;
}
MS2_REPLACE_METHOD(0x1419A5050, UIItemBreakDonationDialog, vfunc_46, 256, 0);

// @0x1419a5160
void UIItemBreakDonationDialog::vfunc_84(CInPacket* pPacket)
{
    if (m_30 == 0)
        return;
    FUN_1419a1fb0();
    FUN_1419a2110();
}
MS2_REPLACE_METHOD(0x1419A5160, UIItemBreakDonationDialog, vfunc_84, 67, 0);

// @0x1419a51b0
int UIItemBreakDonationDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIItemBreakBase::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onClickBreak") == 0)
    {
        if (FUN_1409c4b20()->FUN_140532b60() == 0)
        {
            FUN_1412751b0(FUN_1409eec40(0xe6), 0x14);
        }
        else
        {
            int nRarity = FUN_1409c4b20()->FUN_140532c30();
            if (nRarity == 6 || nRarity == 5)
            {
                bool bLegendary = nRarity != 6;
                CStringW strText = bLegendary ? FUN_14028b8e0(CStringW(L"s_itembreak_donation_legendary_item"))
                                              : FUN_14028b8e0(CStringW(L"s_itembreak_donation_artifact_item"));
                CStringW strCheck = bLegendary ? FUN_14028b8e0(CStringW(L"s_itembreak_donation_legendary_item_checkbox"))
                                               : FUN_14028b8e0(CStringW(L"s_itembreak_donation_artifact_item_checkbox"));
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73d20(0x19, strText, 0, CStringW(L""));
                if (spBox.get() != 0)
                {
                    spBox->FUN_141a01800(1);
                    spBox->FUN_141a026f0(1);
                    spBox->FUN_141a024a0(0);
                    spBox->FUN_141a024e0(strCheck, 0);
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemBreakDonationDialog::vfunc_87));
                    FUN_140d73c60(spBox);
                }
            }
            else if (nRarity == 4)
            {
                MS2Ptr<CMsgBoxData> spBox = FUN_140d73e40(1, 0x8fa, 0, CStringW(L""));
                if (spBox.get() != 0)
                {
                    spBox->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &UIItemBreakDonationDialog::vfunc_87));
                    FUN_140d73c60(spBox);
                }
            }
            else
            {
                FUN_1419a2060();
            }
        }
        return 1;
    }
    if (_stricmp(szMethod, "onSendBreak") == 0)
        return FUN_1409c4b20()->FUN_140532d80();
    return 0;
}
MS2_REPLACE_METHOD(0x1419A51B0, UIItemBreakDonationDialog, vfunc_28, 1989, 0);

// @0x1419a5980
bool UIItemBreakDonationDialog::vfunc_87(int nResult, const CMsgBoxData& box)
{
    if (nResult == 0)
        FUN_1419a2060();
    return true;
}
MS2_REPLACE_METHOD(0x1419A5980, UIItemBreakDonationDialog, vfunc_87, 46, 0);
