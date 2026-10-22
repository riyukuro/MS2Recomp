// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The socket unlock page of the item socket dialog
// ("SocketUnlockPage_*" bags; packet 0x88 operations 0 / 2 / 0xe / 0x10), the packet records it sends and the COMDAT glue
// of its callbacks.
// MS2-UNIT: unit_140f7d060
// MS2-RANGE: 0x140f7d060-0x140f83ff0 .text$mn
// MS2-RANGE: 0x1400e09d0-0x1400e0c00 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSelectSound@@YAXXZ 0x1400e0a90 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400e0ac0 ; probe
// MS2-PIN: ??__Es_keyInput1@@YAXXZ 0x1400e0b40 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400e0b70 ; probe
// MS2-PIN: ??__Es_strSuccessSound@@YAXXZ 0x1400e0ba0 ; probe
// MS2-PIN: ??$?8PEAVItemSocketSystemPageSocketUnlock@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageSocketUnlock@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140f83810 ; prop
// MS2-PIN: ??$?8PEAVItemSocketSystemPageSocketUnlock@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageSocketUnlock@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140f83880 ; prop
// MS2-PIN: ??$forward@AEBQ8ItemSocketSystemPageSocketUnlock@@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YAAEBQ8ItemSocketSystemPageSocketUnlock@@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@ZAEBQ81@EAAX0@Z@Z 0x140f838f0 ; unique
// MS2-PIN: ??$forward@AEBQ8ItemSocketSystemPageSocketUnlock@@EAA_NHAEBVCMsgBoxData@@@Z@std@@YAAEBQ8ItemSocketSystemPageSocketUnlock@@EAA_NHAEBVCMsgBoxData@@@ZAEBQ81@EAA_NH0@Z@Z 0x140f83900 ; unique
// MS2-PIN: ??0Unk_SockUidList@@QEAA@XZ 0x140f83b00 ; unique
// MS2-PIN: ??1Unk_SockUidList@@QEAA@XZ 0x140f83bd0 ; unique
// MS2-PIN: ??8?$MS2Ptr@VUnk_SocketPageBag@@@@QEBA_NPEAVUnk_SocketPageBag@@@Z 0x140f83c10 ; unique
// MS2-PIN: ??_G?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketUnlock@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAAPEAXI@Z 0x140f83cf0 ; prop
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketUnlock@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f83f30 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketUnlock@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140f83f90 ; unique
// MS2-PINS-END tplpin
// fx14: byte-identical copy ctor / clone pairs, bound from the exe vftables (0x142e86110 Params, 0x142e86138 CMsgBoxData)
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketUnlock@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x140f839c0 ; vftable
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketUnlock@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140f83a60 ; vftable
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketUnlock@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f83d80 ; vftable
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketUnlock@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140f83de0 ; vftable
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemsocketsystempagesocketunlock.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/itemsocketsystempagesocketunlock.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/commonfiles/itemsocketsystemutil.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/gfxui/dragslot.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The header statics of the original TU (the same set as the other pages of the family).
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static UICommon::CMyPCKeyInputController s_keyInput1;               // 0x143acb7c0
static CString s_strSelectSound = "System_Gemstone_button_01";      // 0x143acb768
static CString s_strSuccessSound = "System_Gemstone_Success_01";    // 0x143acb7b8
static UICommon::CMyPCKeyInputController s_keyInput2;               // 0x143acb810

class Unk_ItemEquipData : public CItemData {};   // CItem::FUN_140527840's record (as commonfiles\item.cpp)
class Unk_TrWorld;
class Unk_TrPlayer;
class Unk_TrInventory;
Unk_TrWorld* FUN_1403ed2d0();
Unk_TrPlayer* FUN_141bd0cc0(Unk_TrWorld*);
Unk_TrInventory* FUN_1416561a0(Unk_TrPlayer*);
void FUN_1411e1ce0(Unk_TrInventory*, CAtlList<MS2Ptr<CEquipItem>>&, int);
float FUN_1411e1110(Unk_TrInventory*, int);
int FUN_141662de0(Unk_TrPlayer*);
int FUN_141658f30(Unk_TrPlayer*);
// The player's inventory (global 0x143ab2a90).
class Unk_TrBag {
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 uid);
    int FUN_140a5f180(int itemId, int grade);
    int FUN_140a5f7b0(int itemId);
    void FUN_140a60880(int tab, CAtlArray<MS2Ptr<CItem>>& out);
};
extern Unk_TrBag DAT_143ab2a90;
extern int DAT_143ab2914;
extern __int64 DAT_143ab2898;

MS2Ptr<CItem> FUN_141425750(__int64 uid, bool* pbEquipped);
void FUN_1412752d0(const CStringW& key, int type);
void FUN_141276180(const CString& sound, const CString& arg);
void FUN_141415600(const CString& name);
void FUN_14141f970(const CString& name);
void FUN_141415450(const CString& name, MS2Ptr<CItem> item, int a, int b, int c);
void FUN_14141ff80(ItemSlotBag* bag, int count);
void FUN_1422cf860(Unk_SocketPageBag* bag);
int FUN_1422dccd0(Unk_SocketPageBag* bag);
void FUN_1422dcca0(Unk_SocketPageBag* bag, int index);
NotifyContext::BindData* FUN_1422c8e90(const CString& name);
class Unk_TrDebug;
Unk_TrDebug* FUN_14025e7c0();
bool FUN_14116d720(Unk_TrDebug*);
void FUN_1422ce240(Unk_SocketPageButton*, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&, int);
void FUN_1422dce60(Unk_SocketPageBag*, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&, int);
void FUN_1422de0e0(Unk_SocketPageBag*, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&, int);
struct Unk_TrFindBag { MS2Ptr<Unk_SocketPageBag> FUN_140c4bc60(const CString&); };
struct Unk_TrFindButton { MS2Ptr<Unk_SocketPageButton> FUN_140acce30(const CString&); };
CStringW GetStringCommonByKey(const CStringW& key);
CStringW FUN_1405c2690(CStringW key, const CStringW& arg);
CStringW FUN_1409404f0(__int64 v);
CStringW FUN_14042cb90(CStringW key, const float& v);
CStringW FUN_1419021b0(unsigned a, unsigned b);
CStringW FUN_1406564a0(const wchar_t* pszFormat, const CStringW& a, const CStringW& b, const CStringW& c);
CStringW FUN_140627390(unsigned id);
CStringW FUN_14062ae60(int itemId);
CStringW FUN_14062b310(MS2Ptr<TSocketGemStoneInfo> info);
int FUN_140628350();
int FUN_140627ac0(int flag, unsigned* pRate, unsigned bonus);
int FUN_140627b80(int count, unsigned rate);
bool FUN_140627c10(MS2Ptr<CItem> item);
void FUN_140628390(int level, unsigned short rate, int count, CIngredientContainer* cost);
void FUN_140710590(COutPacket&);
void FUN_1409e4950(MS2Ptr<CItem> item, CStringW& out, char* pFlag);
MS2Ptr<CMsgBoxData> FUN_140d73d20(int type, CStringW text, int a, CStringW b);
MS2Ptr<CMsgBoxData> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW text);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
__int64 FUN_141a02ed0(const CMsgBoxData& box, int index, int def);
DragSlotBag* FUN_140c54570(const CString& name);
ItemSlotBag* FUN_140c54590(const CString& name);
class Unk_ItemEventSystem {
public:
    void FUN_1419cae20(UIItemEventListener* listener);      // register (once)
    void FUN_1419caeb0(UIItemEventListener* listener);      // unregister
};
Unk_ItemEventSystem* FUN_140a6a840();

// The ingredient control of the page: the multi select list (RTTI ASMultiSelectTileCacheList over ASItemBag).
class ASItemBag : public Unk_SocketPageBag {};
class ASMultiSelectTileCacheList : public ASItemBag {
public:
    unsigned FUN_1422cf920();                       // the selected count
    void FUN_1422cf980(CAtlArray<int>& indices);    // the selected row indices
};
struct Unk_TrFindMulti { MS2Ptr<ASMultiSelectTileCacheList> FUN_140e8cee0(const CString&); };

// The list change event handed to the handlers and the row wrapper of the clicked row.
class Unk_ListEventBase {
public:
    ~Unk_ListEventBase();                                                   // 0x1422e22a0
    __int64 m_f0, m_f1, m_f2, m_f3, m_f4, m_f5, m_f6, m_f7;                 // 0x40 bytes (no array: the exe has no GS cookie)
};
class ASListEvent : public Unk_ListEventBase {
public:
    ASListEvent(const Scaleform::GFx::FunctionHandler::Params& params);     // 0x1422e2740
    ~ASListEvent();                                                         // 0x140f83bb0
    Scaleform::GFx::Value FUN_1422e27d0();                                  // the clicked row
    int FUN_1422e2820();                                                    // its index
};
class ASListItemRenderer : public AScript {
public:
    ASListItemRenderer(const Scaleform::GFx::Value& row, int nMovie);       // 0x1422e1c50
    virtual ~ASListItemRenderer();                                          // 0x1422e1ca0
    bool FUN_1422ce0e0();                                                   // is checked
    __int64 m_f0, m_f1, m_f2, m_f3, m_f4, m_f5, m_f6, m_f7, m_f8, m_f9, m_f10;   // up to 0x98 bytes
};
MS2_CHECK_SIZE(ASListItemRenderer, 0x98);

// The packet records of the page (the encoders are free functions of commonfiles\itemsocketsystemutil.cpp).
struct Unk_SockUidList {
    Unk_SockUidList() : m_nUid(0) {}                                // 0x140f83b00
    ~Unk_SockUidList() {}                                           // 0x140f83bd0
    __int64 m_nUid;
    std::vector<__int64> m_aUids;
};
struct Unk_SockItemMsg {
    Unk_SockItemMsg() : m_bValid(false), m_spItem(0), m_nByte(-1) {}   // 0x140f83b30
    ~Unk_SockItemMsg() {}                                           // 0x140f83bf0
    bool m_bValid;                          // +0
    MS2Ptr<CItem> m_spItem;                 // +8
    int m_nByte;                            // +0x18
};
namespace CCItemSocketSystemPacket {
class GemStoneInEquip {
public:
    GemStoneInEquip() : m_nUid(0), m_nSlot(-1) {}
    virtual bool vfunc_0();
    unsigned __int64 m_nUid;            // +0x08
    int m_nSlot;                        // +0x10
};
class SelectItem : public GemStoneInEquip {
public:
    SelectItem() : m_nGemUid(0) {}
    virtual ~SelectItem() {}
    __int64 m_nGemUid;                  // +0x18
};
class SelectItemResult : public GemStoneInEquip {
public:
    SelectItemResult() : m_nGemUid(0), m_fProb(0) {}
    virtual ~SelectItemResult() {}
    __int64 m_nGemUid;                  // +0x18
    float m_fProb;                      // +0x20
};
class ForceFillIngredient {
public:
    ForceFillIngredient() : m_nType(0), m_nB(0), m_nUid(0), m_n18(0) {}     // 0x140c54820
    virtual ~ForceFillIngredient() {}                                       // 0x140c54950
    int m_nType;                        // +0x08
    int m_nB;                           // +0x0c
    __int64 m_nUid;                     // +0x10
    int m_n18;                          // +0x18
};
}
MS2_CHECK_SIZE(CCItemSocketSystemPacket::ForceFillIngredient, 0x20);
MS2_CHECK_OFFSET(CCItemSocketSystemPacket::SelectItemResult, m_fProb, 0x20);
void FUN_140628c80(Unk_SockUidList&, COutputStream&);
void FUN_140628e20(Unk_SockUidList&, const __int64&, const std::vector<MS2Ptr<CItem> >&);
void FUN_140628f60(Unk_SockUidList&, const __int64&, const std::vector<__int64>&);
void FUN_140629140(Unk_SockItemMsg&, CInPacket&);
void FUN_140629c50(CCItemSocketSystemPacket::SelectItem&, COutputStream&);
void FUN_140629d60(CCItemSocketSystemPacket::SelectItemResult&, CInPacket&);
void FUN_140629de0(CCItemSocketSystemPacket::ForceFillIngredient&, COutputStream&);

// @0x140f83bb0
ASListEvent::~ASListEvent() {}

// @0x140f7d060
ItemSocketSystemPageSocketUnlock::ItemSocketSystemPageSocketUnlock()
    : m_state(0), m_selectedUid(0), m_highlightUid(0)
{
    m_selectedName = "SocketUnlockPage_selectedSlot";
    m_ingredientSlotName = "SocketUnlockPage_selectedIngredientSlot";
    m_ingredientName = "SocketUnlockPage_ingredient";
    m_slots0Name = "SocketUnlockPage_slots0";
    m_slots1Name = "SocketUnlockPage_slots1";
}

// @0x140f7d280
ItemSocketSystemPageSocketUnlock::~ItemSocketSystemPageSocketUnlock()
{
    FUN_140f80f30();
}

// @0x140f7d400
void ItemSocketSystemPageSocketUnlock::vfunc_1()
{
    ItemSocketSystemPageBase::vfunc_1();
    FUN_140f80f30();
}

// @0x140f7d430
// MS2-FUNCTIONAL: real controls and callback delegates; temporary and cleanup layout differs.
void ItemSocketSystemPageSocketUnlock::vfunc_7(MS2Ptr<AScript> root)
{
    ItemSocketSystemPageBase::vfunc_7(root);
    if (!(root == 0)) {
        if (m_root == 0)
            m_root = root->FUN_1409b4560("m_socketUnlockPage");
        if (!(m_root == 0)) {
            FUN_140f7e8d0();
            FUN_140f7ec20();
            int multiCount = FUN_140628350();
            bool multi = 1 < multiCount;
            {
                MS2Ptr<ASMovieClip> slots = m_root->FUN_1409b4560("m_slots0");
                if (slots.get() != 0) {
                    m_sourceControl = reinterpret_cast<Unk_TrFindBag*>(slots.operator->())->FUN_140c4bc60("m_itemBag");
                    if (m_sourceControl.get() != 0)
                        FUN_1422dce60(m_sourceControl.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageSocketUnlock::FUN_140f82d50), 0);
                }
            }
            {
                MS2Ptr<ASMovieClip> slots = m_root->FUN_1409b4560("m_slots1");
                if (slots.get() != 0) {
                    m_ingredientControl = reinterpret_cast<Unk_TrFindMulti*>(slots.operator->())->FUN_140e8cee0("m_itemBag");
                    if (m_ingredientControl.get() != 0) {
                        if (multi)
                            FUN_1422de0e0(m_ingredientControl.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageSocketUnlock::FUN_140f82ba0), 0);
                        else
                            FUN_1422dce60(m_ingredientControl.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageSocketUnlock::FUN_140f82e10), 0);
                    }
                }
            }
            m_actionButton = reinterpret_cast<Unk_TrFindButton*>(m_root.operator->())->FUN_140acce30("m_btnAction");
            if (m_actionButton.get() != 0)
                FUN_1422ce240(m_actionButton.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageSocketUnlock::FUN_140f82d00), 0);
            bool debug = FUN_14116d720(FUN_14025e7c0());
            m_debugButton = reinterpret_cast<Unk_TrFindButton*>(m_root.operator->())->FUN_140acce30("m_debugBtnAction");
            if (m_debugButton.get() != 0) {
                m_debugButton->vfunc_3(debug);
                if (debug)
                    FUN_1422ce240(m_debugButton.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageSocketUnlock::SendItemSocketSystemMode14), 0);
            }
            m_debugFillButton = reinterpret_cast<Unk_TrFindButton*>(m_root.operator->())->FUN_140acce30("m_debugBtnFillIngredient");
            if (m_debugFillButton.get() != 0) {
                m_debugFillButton->vfunc_3(debug);
                if (debug)
                    FUN_1422ce240(m_debugFillButton.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageSocketUnlock::SendItemSocketSystemMode16), 0);
            }
            FUN_140f6d450(m_slots0Name, m_sourceItems, 0x435, 0x20);
            FUN_140f6d450(m_slots1Name, m_ingredientEquips, 0x415, 0x20);
            FUN_140f6d590(m_selectedName, m_selected, 0x405, 0x20);
            ASObj data(2);
            data.FUN_1407cba60("bagId0", m_slots0Name);
            data.FUN_1407cba60("bagId1", m_slots1Name);
            data.FUN_1407cba60("selectedSlotId", m_selectedName);
            ASObj bag1(2);
            bag1.FUN_1407cb9c0("maxSelectedCount", multi ? multiCount : 1);
            bag1.FUN_1407cbbe0("toggleRenderer", multi);
            data.FUN_1409adbe0("bag1Data", bag1.FUN_1422bb870());
            m_root->Invoke("initData", data.FUN_1422bb870());
            m_state = 0;
            FUN_140a6a840()->FUN_1419cae20(static_cast<UIItemEventListener*>(this));
            FUN_140f6dbe0(m_sourceControl);
            FUN_140f6dbe0(m_ingredientControl);
        }
    }
}

// @0x140f7e340
void ItemSocketSystemPageSocketUnlock::vfunc_2()
{
    ItemSocketSystemPageBase::vfunc_2();
    FUN_140f80f30();
}

// @0x140f7e370
void ItemSocketSystemPageSocketUnlock::vfunc_5(CInPacket* packet)
{
    ItemSocketSystemPageBase::vfunc_5(packet);
    int operation = packet->vfunc_o8_1();
    FUN_140f6d620(1);
    if (operation == 1)
        FUN_140f82340(packet);
    else if (operation == 3)
        FUN_140f81f00(packet);
    else if (operation == 16)
        FUN_140f826b0(packet);
    else if (operation == 18)
        vfunc_8(packet);
}

// @0x140f7e440
int ItemSocketSystemPageSocketUnlock::vfunc_3(const char* event, const Scaleform::GFx::Value* args, int count)
{
    if (_stricmp("onIndexChangeSlot0", event) == 0) {
        ASData data;
        if (data.FUN_1422b9620(args, count) != 0) {
            int index = data.FUN_1422b8a10();
            MS2Ptr<CItem> item = FUN_140f6d840(m_sourceItems, index);
            FUN_140f7ef70(item);
        }
        return 1;
    } else if (_stricmp("onIndexChangeSlot1", event) == 0) {
        ASData data;
        if (data.FUN_1422b9620(args, count) != 0) {
            int index = data.FUN_1422b8a10();
            MS2Ptr<CItem> item = FUN_140f6d840(m_ingredientEquips, index);
            FUN_140f7f420(item);
        }
        return 1;
    } else if (_stricmp("onClickAction", event) == 0) {
        if (m_state == 1)
            FUN_140f80160();
        else if (m_state == 2)
            FUN_140f80d70();
    }
    return 0;
}

// @0x140f7e690
// The item listener's item removed / changed: redraw the slot of the item in both lists.
void ItemSocketSystemPageSocketUnlock::vfunc_3(void* p, bool bFlag)
{
    if (p == 0)
        return;
    if (m_root == 0 || m_sourceItems.IsEmpty())
        return;
    if (!bFlag)
    {
        int index = -1;
        FUN_140f6d6b0(static_cast<CItem*>(p)->FUN_140526a50(), m_sourceItems, &index);
        if (index >= 0)
            FUN_140f6d9a0(index, m_slots0Name, m_sourceItems, m_sourceControl);
        index = -1;
        FUN_140f6d6b0(static_cast<CItem*>(p)->FUN_140526a50(), m_ingredientEquips, &index);
        if (index >= 0)
            FUN_140f6d9a0(index, m_slots1Name, m_ingredientEquips, m_ingredientControl);
    }
}

// @0x140f7e8d0
// MS2-FUNCTIONAL: typed inventory and equipped-item enumeration; smart-pointer temporaries differ.
void ItemSocketSystemPageSocketUnlock::FUN_140f7e8d0()
{
    Unk_TrPlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
    if (player == 0)
        return;
    m_sourceItems.RemoveAll();
    CAtlArray<MS2Ptr<CItem>> items;
    FUN_140f82ed0(items);
    if (!items.IsEmpty()) {
        size_t count = items.GetCount();
        for (size_t i = 0; i < count; ++i) {
            MS2Ptr<CItem> item(items.GetAt(i));
            if (!(item == 0) && item->FUN_1405279c0() != 0 && item->FUN_140529560() != 0
                && item->FUN_1405279c0()->GetMaxSlot() != 0)
                m_sourceItems.Add(item);
        }
    }
    CAtlList<MS2Ptr<CEquipItem>> equipped(10);
    Unk_TrInventory* inventory = FUN_1416561a0(player);
    FUN_1411e1ce0(inventory, equipped, 0);
    FUN_1411e1ce0(inventory, equipped, 1);
    POSITION pos = equipped.GetHeadPosition();
    while (pos != 0) {
        MS2Ptr<CEquipItem> equip(equipped.GetAt(pos));
        if (!(equip == 0)) {
            MS2Ptr<CItem> item = equip->GetItem();
            if (!(item == 0) && item->FUN_1405279c0() != 0 && item->FUN_1405279c0()->GetMaxSlot() != 0)
                m_sourceItems.Add(item);
        }
        equipped.GetNext(pos);
    }
}

// @0x140f7ec20
// MS2-FUNCTIONAL: typed ingredient filter; smart-pointer temporaries differ.
void ItemSocketSystemPageSocketUnlock::FUN_140f7ec20()
{
    if (m_selected == 0 || m_selected->FUN_1405279c0() == 0)
        return;
    Unk_TrPlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
    if (player == 0)
        return;
    m_ingredientEquips.RemoveAll();
    if (!FUN_140627c10(MS2Ptr<CItem>(m_selected)))
        return;
    CAtlArray<MS2Ptr<CItem>> items;
    FUN_140f82ed0(items);
    if (!items.IsEmpty()) {
        CItemSocketSystemUtil::EnableSocketUnlockFunction func;
        int unlockMode = FUN_141662de0(player);
        int socketMode = FUN_141658f30(player);
        func.Init(MS2Ptr<CItem>(m_selected), socketMode, unlockMode);
        size_t count = items.GetCount();
        for (size_t i = 0; i < count; ++i) {
            MS2Ptr<CItem> item(items.GetAt(i));
            if (item == 0)
                continue;
            if (item->FUN_140529560() == 0)
                continue;
            if (!func.Matches(MS2Ptr<CItem>(item)))
                continue;
            m_ingredientEquips.Add(item);
        }
    }
    ItemSlotBag* bag = FUN_140c54590(m_slots1Name);
    if (bag != 0) {
        FUN_14141ff80(bag, (int)m_ingredientEquips.GetCount());
        if (m_ingredientControl.get() != 0)
            FUN_1422cf860(m_ingredientControl.operator->());
    }
}

// @0x140f7ef70
// MS2-FUNCTIONAL: select request through the typed packet record; smart-pointer temporaries differ.
void ItemSocketSystemPageSocketUnlock::FUN_140f7ef70(MS2Ptr<CItem> item)
{
    if (m_root == 0)
        return;
    if (item == 0 || item->FUN_140527840() == 0)
        return;
    __int64 uid = item->FUN_140526a50();
    if (FUN_141425750(uid, 0) == 0) {
        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
        return;
    }
    CItemSocket* socket = item->FUN_1405279c0();
    if (socket == 0 || socket->GetMaxSlot() == 0)
        return;
    FUN_141276180(s_strSelectSound, CString(""));
    if (socket->FUN_140620a70() == 0) {
        FUN_140f7f210(item);
        return;
    }
    CCItemSocketSystemPacket::SelectItem msg;
    msg.m_nGemUid = uid;
    COutPacket out(0x88, 0);
    out.Encode1(2);
    FUN_140629c50(msg, out);
    FUN_140710590(out);
    FUN_140f6d620(0);
}

// @0x140f7f210
// MS2-FUNCTIONAL: Scaleform data and selection refresh with typed temporaries.
void ItemSocketSystemPageSocketUnlock::FUN_140f7f210(MS2Ptr<CItem> item)
{
    FUN_140f810b0();
    if (item == 0)
        return;
    m_selected = item;
    FUN_140f6d340(m_selectedName, m_selected);
    ASObj data(2);
    data.FUN_1407cbb20("itemName", m_selected->FUN_140528160());
    data.FUN_1409c0e60("unlockAllNotice", L"$s_itemsocketsystem_socketunlock_msg_unlock_all");
    FUN_140f81a40(data, -1);
    m_root->Invoke("playSelect", data.FUN_1422bb870());
    m_state = 1;
    m_selectedUid = m_selected->FUN_140526a50();
}

// @0x140f7f420
// MS2-FUNCTIONAL: ingredient pick validation and the high SA option question; temporary layout differs.
void ItemSocketSystemPageSocketUnlock::FUN_140f7f420(MS2Ptr<CItem> item)
{
    if (m_root == 0 || m_selected == 0)
        return;
    CItemSocket* socket = m_selected->FUN_1405279c0();
    if (socket == 0 || socket->GetMaxSlot() == 0)
        return;
    if (item == 0 || item->FUN_140527840() == 0)
        return;
    if (socket->FUN_140620a70() == 0) {
        FUN_140f6dbe0(m_ingredientControl);
        return;
    }
    if (m_state != 1 && m_state != 2) {
        FUN_140f6dbe0(m_ingredientControl);
        return;
    }
    CStringW highSa;
    char bHighSa = 0;
    FUN_1409e4950(MS2Ptr<CItem>(item), highSa, &bHighSa);
    if (item->FUN_140526bd0() < 5 || bHighSa != 1) {
        FUN_140f7fa20(item);
    } else {
        CStringW ask = GetStringCommonByKey(CStringW(L"s_itemsocketsystem_socketunlock_msg_ask_high_sa_option_item"));
        CStringW text;
        text.Append(highSa);
        text.Append(L"\n");
        text.Append(ask);
        MS2Ptr<CMsgBoxData> box = FUN_140d73d20(0x11, CStringW(text), 0, CStringW(L""));
        if (box.get() != 0) {
            box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &ItemSocketSystemPageSocketUnlock::FUN_140f83560));
            box->FUN_141a01600(item->FUN_140526a50());
            box->FUN_141a01ee0(MS2Ptr<CItem>(item), item->FUN_140527b10(), 1, 0, -1, -1, 1);
            box->FUN_141a01700(0x475, 0x476, 0);
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(box));
        }
    }
}

// @0x140f7fa20
// MS2-FUNCTIONAL: ingredient equipment validation with typed temporaries.
void ItemSocketSystemPageSocketUnlock::FUN_140f7fa20(MS2Ptr<CItem> item)
{
    if (m_root == 0 || m_selected == 0)
        return;
    CItemSocket* socket = m_selected->FUN_1405279c0();
    if (socket == 0 || socket->GetMaxSlot() == 0)
        return;
    if (item == 0 || item->FUN_140527840() == 0)
        return;
    if (socket->FUN_140620a70() == 0) {
        FUN_140f6dbe0(m_ingredientControl);
        return;
    }
    if (m_state != 1 && m_state != 2) {
        FUN_140f6dbe0(m_ingredientControl);
        return;
    }
    FUN_141276180(s_strSelectSound, CString(""));
    if (m_state == 2) {
        FUN_140f80d70();
        return;
    }
    __int64 uid = item->FUN_140526a50();
    if (FUN_141425750(uid, 0) == 0) {
        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_ingredient"), 1);
        return;
    }
    CItemSocket* itemSocket = item->FUN_1405279c0();
    if (itemSocket == 0 || itemSocket->GetMaxSlot() == 0)
        return;
    Unk_TrPlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
    if (player == 0)
        return;
    CItemSocketSystemUtil::EnableSocketUnlockFunction func;
    int unlockMode = FUN_141662de0(player);
    int socketMode = FUN_141658f30(player);
    if (!func.InitPair(MS2Ptr<CItem>(m_selected), MS2Ptr<CItem>(item), socketMode, unlockMode)) {
        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_ingredient"), 1);
        return;
    }
    FUN_140f6d340(m_ingredientSlotName, item);
    m_root->Invoke("selectIngredientEquip");
    FUN_140f83170();
}

// @0x140f7ff50
// MS2-FUNCTIONAL: confirmation box carrying the selected item and the ingredient uids.
void ItemSocketSystemPageSocketUnlock::FUN_140f7ff50(const CStringW& text, __int64* uid, std::vector<MS2Ptr<CItem> >& items)
{
    MS2Ptr<CMsgBoxData> box = FUN_140d74090(
        Delegate<bool(int, const CMsgBoxData&)>(this, &ItemSocketSystemPageSocketUnlock::FUN_140f83440), CStringW(text));
    if (box == 0)
        return;
    box->FUN_1405340b0(*uid);
    unsigned __int64 count = items.size();
    box->FUN_1405340b0(count);
    for (unsigned __int64 i = 0; i < count; ++i) {
        MS2Ptr<CItem> item(items.at(i));
        if (item.get() != 0)
            box->FUN_1405340b0(item->FUN_140526a50());
        else
            box->FUN_140533ff0(0);
    }
}

// @0x140f80160
// MS2-FUNCTIONAL: validation chain with typed ingredient list; cleanup layout differs.
void ItemSocketSystemPageSocketUnlock::FUN_140f80160()
{
    if (m_selected == 0 || m_selected->FUN_140527840() == 0)
        return;
    if (m_ingredientControl == 0)
        return;
    __int64 uid = m_selected->FUN_140526a50();
    if (FUN_141425750(uid, 0) == 0) {
        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
        return;
    }
    CItemSocket* socket = m_selected->FUN_1405279c0();
    if (socket == 0 || socket->GetMaxSlot() == 0)
        return;
    if (socket->FUN_140620a70() == 0) {
        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_socket_unlock_all"), 1);
        return;
    }
    std::vector<MS2Ptr<CItem> > ingredients;
    bool multi = FUN_140627c10(MS2Ptr<CItem>(m_selected));
    if (multi) {
        int need = FUN_140628350();
        MS2Ptr<ASMultiSelectTileCacheList> list(dynamic_cast<ASMultiSelectTileCacheList*>(static_cast<ASItemBag*>(m_ingredientControl.get())));
        if (list.get() != 0) {
            CAtlArray<int> selected;
            list->FUN_1422cf980(selected);
            if (selected.IsEmpty()) {
                FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_ingredient_null"), 1);
                return;
            }
            int count = (int)selected.GetCount();
            if (count != need) {
                FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_ingredient_count"), 1);
                return;
            }
            for (int i = 0; i < count; ++i) {
                int index = selected[i];
                MS2Ptr<CItem> item = FUN_140f6d840(m_ingredientEquips, index);
                if (item == 0 || DAT_143ab2a90.FUN_140a5d680(item->FUN_140526a50()) == 0) {
                    FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_ingredient"), 1);
                    return;
                }
                ingredients.push_back(item);
            }
        }
    }
    MS2Ptr<CItemData> data(m_selected->FUN_140527840());
    unsigned rate = 0;
    unsigned bonus = 0;
    int flag = data->FUN_14053de40();
    Unk_TrPlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
    if (player != 0)
        bonus = (unsigned)(FUN_1411e1110(FUN_1416561a0(player), 0xb3) * 10000.0f);
    int sale = FUN_140627ac0(flag, &rate, bonus);
    CIngredientContainer cost;
    unsigned level = m_selected->FUN_140527710();
    FUN_140628390(m_selected->FUN_140526bd0(), level & 0xffff, flag, &cost);
    Unk_IngVec* entries = cost.FUN_14026c230();
    size_t entryCount = entries->FUN_14028b500();
    for (size_t i = 0; i < entryCount; ++i) {
        Unk_IngRef ingredient(*entries->FUN_14028a0f0(i));
        if (!(ingredient == 0)) {
            int have = DAT_143ab2a90.FUN_140a5f180(ingredient->m_a, 0);
            if (ingredient->m_b != 0)
                have = DAT_143ab2a90.FUN_140a5f7b0(ingredient->m_b);
            int need = ingredient->m_c;
            if (sale != 0)
                need = FUN_140627b80(need, rate);
            if (have < need) {
                bool lack = ingredient->m_b != 0x60;
                if (!lack) {
                    unsigned __int64 fee = (unsigned)((need - have) * 1000);
                    lack = DAT_143ab2898 < (__int64)fee;
                }
                if (lack) {
                    FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_lack_price"), 1);
                    return;
                }
            }
        }
    }
    if (multi) {
        for (size_t i = 0; i < ingredients.size(); ++i) {
            MS2Ptr<CItem> item(ingredients[i]);
            if (!(item == 0)) {
                CItemSocket* itemSocket = item->FUN_1405279c0();
                if (itemSocket != 0) {
                    unsigned open = itemSocket->FUN_140620a20();
                    if (socket->FUN_140620a20() == open) {
                        for (unsigned j = 0; j < open; ++j) {
                            if (itemSocket->FUN_140620ac0(j) != 0) {
                                FUN_140f7ff50(CStringW(L"s_itemsocketsystem_socketunlock_msg_ask_unlock_ingredient_in_gemstone"), &uid, ingredients);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    if (data->FUN_14053cf90()) {
        if (reinterpret_cast<CItemTransfer*>(m_selected->FUN_140527930())->FUN_140635120() == 0 && socket->FUN_140620a20() == 0) {
            FUN_140f7ff50(CStringW(L"s_itemsocketsystem_socketunlock_msg_ask_unlock_skin_first"), &uid, ingredients);
            return;
        }
    }
    Unk_SockUidList request;
    FUN_140628e20(request, uid, ingredients);
    SendItemSocketSystemMode0(request);
}

// @0x140f80d70
void ItemSocketSystemPageSocketUnlock::FUN_140f80d70()
{
    if (m_selectedUid != 0) {
        MS2Ptr<CItem> found = FUN_141425750(m_selectedUid, 0);
        if ((bool)found.get() && found->FUN_1405279c0() != 0 && (unsigned)found->FUN_1405279c0()->FUN_140620a70() > 0) {
            FUN_140f832f0();
            return;
        }
    }
    m_selectedUid = 0;
    m_selected = 0;
    FUN_140f6d340(m_selectedName, m_selected);
    FUN_140f6dbe0(m_sourceControl);
    m_root->Invoke("playStart");
}

// @0x140f80f30
void ItemSocketSystemPageSocketUnlock::FUN_140f80f30()
{
    FUN_14141f970(m_slots0Name);
    FUN_14141f970(m_slots1Name);
    FUN_14141f970(m_ingredientName);
    FUN_141415600(m_selectedName);
    FUN_141415600(m_ingredientSlotName);
    m_selected = 0;
    m_ingredients.RemoveAll();
    m_sourceItems.RemoveAll();
    m_ingredientEquips.RemoveAll();
    m_selectedUid = 0;
    m_highlightUid = 0;
    m_sourceControl = 0;
    m_ingredientControl = 0;
    m_actionButton = 0;
    m_debugButton = 0;
    m_debugFillButton = 0;
    FUN_140a6a840()->FUN_1419caeb0(static_cast<UIItemEventListener*>(this));
    m_state = 0;
}

// @0x140f810b0
void ItemSocketSystemPageSocketUnlock::FUN_140f810b0()
{
    FUN_141415600(m_ingredientSlotName);
    FUN_14141f970(m_ingredientName);
    m_ingredients.RemoveAll();
}

// @0x140f81100
// MS2-FUNCTIONAL: sale, ingredient and ingredient equipment data with typed temporaries.
void ItemSocketSystemPageSocketUnlock::FUN_140f81100(ASObj& data)
{
    FUN_140f810b0();
    if (m_selected == 0 || m_selected->FUN_140527840() == 0)
        return;
    CItemSocket* socket = m_selected->FUN_1405279c0();
    if (socket == 0)
        return;
    MS2Ptr<CItemData> itemData(m_selected->FUN_140527840());
    CIngredientContainer cost;
    int flag = itemData->FUN_14053de40();
    unsigned level = m_selected->FUN_140527710();
    FUN_140628390(m_selected->FUN_140526bd0(), level & 0xffff, flag, &cost);
    MS2Ptr<SaleParam> sale(new SaleParam);
    if (sale.get() != 0) {
        unsigned bonus = 0;
        Unk_TrPlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
        if (player != 0)
            bonus = (unsigned)(FUN_1411e1110(FUN_1416561a0(player), 0xb3) * 10000.0f);
        sale->enabled = FUN_140627ac0(flag, reinterpret_cast<unsigned*>(&sale->rate), bonus);
    }
    __int64 fee = 0;
    FUN_140f6dc70(m_ingredientName, cost, data, m_ingredients, MS2Ptr<CItem>(m_selected), &fee, MS2Ptr<SaleParam>(sale));
    if (fee != 0)
        data.FUN_1407cbb20("unlockFee", FUN_1405c2690(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(fee)));
    int icon = 0x405;
    int flags = 0x20;
    MS2Ptr<CItem> equipItem(0);
    bool showEffect = true;
    int needCount = FUN_140628350();
    if (1 < needCount) {
        showEffect = false;
        icon = 0x415;
        flags = 0x6800;
        equipItem.AssignRaw(new CItem);
        int grade = m_selected->FUN_140526bd0();
        int itemId = m_selected->FUN_1405276c0();
        equipItem->FUN_14052b130(itemId, grade, 0);
        CItemSocket* itemSocket = m_selected->FUN_1405279c0();
        if (itemSocket != 0)
            equipItem->FUN_14052b420(itemSocket->FUN_140620a20());
    }
    FUN_141415450(m_ingredientSlotName, MS2Ptr<CItem>(equipItem), 0, icon, flags);
    data.FUN_1407cba60("ingredientEquipSlotId", m_ingredientSlotName);
    data.FUN_1407cbbe0("showIngredientEquipSlotEffect", showEffect);
    data.FUN_1407cb9c0("needIngredientEquipCount", needCount);
    CStringW countText;
    if (1 < needCount)
        countText = FUN_1419021b0(0, needCount);
    data.FUN_1407cbb20("ingredientEquipCountText", countText);
    CStringW saleDesc;
    if (sale.get() != 0) {
        if (sale->enabled == 1) {
            float percent = (float)(unsigned)sale->rate * 0.01f;
            saleDesc = FUN_14042cb90(CStringW(L"s_itemsocketsystem_gemstoneupgrade_sale_desc"), percent);
        } else if (sale->enabled == 2) {
            float percent = (float)(unsigned)sale->rate * 0.01f;
            saleDesc = FUN_14042cb90(CStringW(L"s_itemsocketsystem_gemstoneupgrade_sa_sale_desc"), percent);
        }
    }
    data.FUN_1407cbb20("saleDesc", saleDesc);
}

// @0x140f81a40
// MS2-FUNCTIONAL: socket row texts built with typed temporaries; string temporary layout differs.
void ItemSocketSystemPageSocketUnlock::FUN_140f81a40(ASObj& data, int unlockIndex)
{
    if (m_selected == 0 || m_selected->FUN_140527840() == 0)
        return;
    CItemSocket* socket = m_selected->FUN_1405279c0();
    if (socket == 0 || socket->GetMaxSlot() == 0)
        return;
    ASArray rows(2);
    unsigned open = socket->FUN_140620a20();
    CStringW emptyText;
    CStringW rowStat = GetStringCommonByKey(CStringW(L"s_itemsocketsystem_socketunlock_row_socket_stat"));
    for (unsigned i = 0; i < open; ++i) {
        CStringW text;
        MS2Ptr<TSocketGemStoneInfo> info = socket->FUN_140620b70(i);
        if (!(info == 0) && !info->FUN_14061fab0()) {
            int gemId = info->GetGemId();
            text = FUN_1406564a0(rowStat, FUN_140627390(gemId), FUN_14062ae60(gemId), FUN_14062b310(MS2Ptr<TSocketGemStoneInfo>(info)));
        } else {
            if (emptyText.IsEmpty())
                emptyText = GetStringCommonByKey(CStringW(L"s_itemsocketsystem_socketunlock_row_socket_empty"));
            text = emptyText;
        }
        rows.FUN_1422bbfe0(text);
    }
    unsigned left = socket->FUN_140620a70();
    if (left != 0) {
        CStringW lockText = GetStringCommonByKey(CStringW(L"s_itemsocketsystem_socketunlock_row_socket_lock"));
        for (unsigned i = 0; i < left; ++i)
            rows.FUN_1422bbfe0(lockText);
    }
    data.FUN_1409adbe0("arrSocket", rows.FUN_1422bb870());
    data.FUN_1407cb9c0("unlockSocketIndex", unlockIndex);
}

// @0x140f81f00
// MS2-FUNCTIONAL: select result refresh with typed temporaries.
void ItemSocketSystemPageSocketUnlock::FUN_140f81f00(CInPacket* packet)
{
    if (m_root == 0)
        return;
    CCItemSocketSystemPacket::SelectItemResult result;
    FUN_140629d60(result, *packet);
    m_selected = FUN_141425750(result.m_nGemUid, 0);
    if (m_selected == 0) {
        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
        return;
    }
    FUN_140f6d340(m_selectedName, m_selected);
    ASObj data(2);
    data.FUN_1407cbb20("itemName", m_selected->FUN_140528160());
    data.FUN_1407cbb20("successProb", FUN_14042cb90(CStringW(L"s_itemsocketsystem_success_prob"), result.m_fProb));
    data.FUN_1407cbbe0("noSelect", !FUN_140627c10(MS2Ptr<CItem>(m_selected)));
    FUN_140f81100(data);
    FUN_140f81a40(data, -1);
    m_root->Invoke("playSelect", data.FUN_1422bb870());
    m_state = 1;
    m_selectedUid = m_selected->FUN_140526a50();
    FUN_140f7ec20();
    FUN_140f6dbe0(m_ingredientControl);
}

// @0x140f82340
// MS2-FUNCTIONAL: unlock result refresh with typed temporaries.
void ItemSocketSystemPageSocketUnlock::FUN_140f82340(CInPacket* packet)
{
    if (m_root == 0)
        return;
    if (m_selected == 0)
        return;
    CItemSocket* socket = m_selected->FUN_1405279c0();
    if (socket == 0)
        return;
    __int64 highlight = m_selected->FUN_140526a50();
    Unk_SockItemMsg msg;
    msg.m_spItem = m_selected;
    FUN_140629140(msg, *packet);
    FUN_140f6d340(m_selectedName, m_selected);
    ASObj data(2);
    data.FUN_1407cb9c0("unlockSocketIndex", msg.m_nByte);
    FUN_140f81a40(data, msg.m_nByte);
    CString method;
    if (!msg.m_bValid) {
        method = "playFail";
        highlight = 0;
    } else {
        method = "playSuccess";
        FUN_141276180(s_strSuccessSound, CString(""));
    }
    m_root->Invoke((const char*)method, data.FUN_1422bb870());
    m_state = 2;
    FUN_140f6dbe0(m_ingredientControl);
    FUN_140f82f90();
    FUN_140f83060(highlight);
    FUN_140f6e700(m_selected->FUN_140526a50());
}

// @0x140f826b0
void ItemSocketSystemPageSocketUnlock::FUN_140f826b0(CInPacket*)
{
    if (m_root == 0 || m_selected == 0 || m_selected->FUN_140527840() == 0)
        return;
    if (DAT_143ab2914 < 0x32)
        return;
    if (m_state != 1)
        return;
    FUN_140f7ec20();
    MS2Ptr<SaleParam> sale(new SaleParam);
    if (sale.get() != 0) {
        unsigned bonus = 0;
        Unk_TrPlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
        if (player != 0)
            bonus = (unsigned)(FUN_1411e1110(FUN_1416561a0(player), 0xb3) * 10000.0f);
        int flag = m_selected->FUN_140527840()->FUN_14053de40();
        sale->enabled = FUN_140627ac0(flag, reinterpret_cast<unsigned*>(&sale->rate), bonus);
    }
    __int64 price = 0;
    FUN_140f6e250(m_ingredientName, m_ingredients, MS2Ptr<CItem>(m_selected), &price, MS2Ptr<SaleParam>(sale));
}

// @0x140f82940
// MS2-FUNCTIONAL: debug unlock request through the typed uid list record.
void ItemSocketSystemPageSocketUnlock::SendItemSocketSystemMode14(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_selected == 0)
        return;
    if (DAT_143ab2914 < 0x32)
        return;
    if (m_state != 1)
        return;
    std::vector<__int64> uids;
    Unk_SockUidList request;
    __int64 uid = m_selected->FUN_140526a50();
    FUN_140628f60(request, uid, uids);
    COutPacket out(0x88, 0);
    out.Encode1(0xe);
    FUN_140628c80(request, out);
    FUN_140710590(out);
}

// @0x140f82a50
// MS2-FUNCTIONAL: debug fill-ingredient request through the typed packet record.
void ItemSocketSystemPageSocketUnlock::SendItemSocketSystemMode16(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_selected == 0 || m_selected->FUN_1405279c0() == 0)
        return;
    if (DAT_143ab2914 < 0x32)
        return;
    if (m_state != 1)
        return;
    CItemSocket* socket = m_selected->FUN_1405279c0();
    if (socket->GetMaxSlot() == 0)
        return;
    CCItemSocketSystemPacket::ForceFillIngredient fill;
    fill.m_nType = 0;
    fill.m_nUid = m_selected->FUN_140526a50();
    COutPacket out(0x88, 0);
    out.Encode1(0x10);
    FUN_140629de0(fill, out);
    FUN_140710590(out);
}

// @0x140f82ba0
// MS2-FUNCTIONAL: list event decoding through the row renderer wrapper.
void ItemSocketSystemPageSocketUnlock::FUN_140f82ba0(const Scaleform::GFx::FunctionHandler::Params& params)
{
    ASListEvent evt(params);
    Scaleform::GFx::Value row = evt.FUN_1422e27d0();
    ASListItemRenderer renderer(row, 2);
    if (renderer.FUN_1422ba9a0())
        return;
    unsigned index = evt.FUN_1422e2820();
    if (renderer.FUN_1422ce0e0()) {
        MS2Ptr<CItem> item = FUN_140f6d840(m_ingredientEquips, index);
        FUN_140f7f420(item);
    } else {
        FUN_140f83170();
    }
}

// @0x140f82d00
void ItemSocketSystemPageSocketUnlock::FUN_140f82d00(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (m_state == 1)
        FUN_140f80160();
    else if (m_state == 2)
        FUN_140f80d70();
}

// @0x140f82d50
// MS2-FUNCTIONAL: list event decoding.
void ItemSocketSystemPageSocketUnlock::FUN_140f82d50(const Scaleform::GFx::FunctionHandler::Params& params)
{
    ASListEvent evt(params);
    unsigned index = evt.FUN_1422e2820();
    MS2Ptr<CItem> item = FUN_140f6d840(m_sourceItems, index);
    FUN_140f7ef70(item);
}

// @0x140f82e10
// MS2-FUNCTIONAL: list event decoding.
void ItemSocketSystemPageSocketUnlock::FUN_140f82e10(const Scaleform::GFx::FunctionHandler::Params& params)
{
    ASListEvent evt(params);
    unsigned index = evt.FUN_1422e2820();
    MS2Ptr<CItem> item = FUN_140f6d840(m_ingredientEquips, index);
    FUN_140f7f420(item);
}

// @0x140f82ed0
void ItemSocketSystemPageSocketUnlock::FUN_140f82ed0(CAtlArray<MS2Ptr<CItem>>& out)
{
    DAT_143ab2a90.FUN_140a60880(0, out);
    DAT_143ab2a90.FUN_140a60880(1, out);
}

// @0x140f82f20
void ItemSocketSystemPageSocketUnlock::SendItemSocketSystemMode0(Unk_SockUidList& request)
{
    COutPacket out(0x88, 0);
    out.Encode1(0);
    FUN_140628c80(request, out);
    FUN_140710590(out);
}

// @0x140f82f90
void ItemSocketSystemPageSocketUnlock::FUN_140f82f90()
{
    int index = -1;
    MS2Ptr<CItem> found = FUN_140f6d6b0(m_selectedUid, m_sourceItems, &index);
    FUN_140f6dbe0(m_sourceControl);
    if (found == 0)
        m_selectedUid = 0;
}

// @0x140f83060
void ItemSocketSystemPageSocketUnlock::FUN_140f83060(__int64 uid)
{
    __int64 previous = m_highlightUid;
    if (previous != uid && previous != 0) {
        int index = -1;
        FUN_140f6d6b0(previous, m_sourceItems, &index);
        if (index >= 0)
            FUN_140f6e500(index, false);
    }
    if (uid != 0) {
        int index = -1;
        FUN_140f6d6b0(uid, m_sourceItems, &index);
        if (index >= 0)
            FUN_140f6e500(index, true);
    }
    m_highlightUid = uid;
}

// @0x140f83170
// MS2-FUNCTIONAL: multi select count text with the typed list cast.
void ItemSocketSystemPageSocketUnlock::FUN_140f83170()
{
    if (m_ingredientControl == 0)
        return;
    unsigned need = FUN_140628350();
    if (need <= 1)
        return;
    MS2Ptr<ASMultiSelectTileCacheList> list(dynamic_cast<ASMultiSelectTileCacheList*>(static_cast<ASItemBag*>(m_ingredientControl.get())));
    if (list == 0)
        return;
    unsigned count = list->FUN_1422cf920();
    CStringW text = FUN_1419021b0(count, need);
    m_root->Invoke("updateIngredientEquipCount", count, need, CStringW(text));
}

// @0x140f832f0
void ItemSocketSystemPageSocketUnlock::FUN_140f832f0()
{
    int index = -1;
    MS2Ptr<CItem> found = FUN_140f6d6b0(m_selectedUid, m_sourceItems, &index);
    if (found == 0) {
        FUN_140f6dbe0(m_sourceControl);
        m_selectedUid = 0;
    } else {
        if (FUN_1422dccd0(m_sourceControl.operator->()) != index) {
            FUN_1422dcca0(m_sourceControl.operator->(), index);
            m_sourceControl->vfunc_24(false);
        }
    }
}

// @0x140f83440
// MS2-FUNCTIONAL: confirmation answer rebuilding the uid list from the box arguments.
bool ItemSocketSystemPageSocketUnlock::FUN_140f83440(int result, const CMsgBoxData& box)
{
    if (result == 0) {
        __int64 uid = box.FUN_141a02f10(0, 0);
        std::vector<__int64> uids;
        unsigned __int64 count = box.FUN_141a02f10(1, 0);
        for (unsigned __int64 i = 0; i < count; ++i) {
            __int64 value = FUN_141a02ed0(box, i + 2, 0);
            uids.push_back(value);
        }
        Unk_SockUidList request;
        FUN_140628f60(request, uid, uids);
        SendItemSocketSystemMode0(request);
    }
    return true;
}

// @0x140f83560
bool ItemSocketSystemPageSocketUnlock::FUN_140f83560(int result, const CMsgBoxData& box)
{
    if (result == 0) {
        __int64 uid = box.FUN_141a02c20();
        int index = 0;
        MS2Ptr<CItem> found = FUN_140f6d6b0(uid, m_ingredientEquips, &index);
        if (found.get() != 0)
            FUN_140f7fa20(found);
    }
    return true;
}

// Hooks (functions that build no callback delegates, read no unit statics and cast through no RTTI).
MS2_REPLACE_METHOD(0x140F7D400, ItemSocketSystemPageSocketUnlock, vfunc_1, 34, 0xB4985E8C);
MS2_REPLACE_METHOD(0x140F7E340, ItemSocketSystemPageSocketUnlock, vfunc_2, 34, 0xEE66478F);
MS2_REPLACE_METHOD(0x140F7E370, ItemSocketSystemPageSocketUnlock, vfunc_5, 190, 0x7F2D3383);
MS2_REPLACE_METHOD(0x140F7E8D0, ItemSocketSystemPageSocketUnlock, FUN_140f7e8d0, 842, 0x319E6E61);
MS2_REPLACE_METHOD(0x140F7EC20, ItemSocketSystemPageSocketUnlock, FUN_140f7ec20, 833, 0x701D098A);
MS2_REPLACE_METHOD(0x140F7F210, ItemSocketSystemPageSocketUnlock, FUN_140f7f210, 520, 0x1249B769);
MS2_REPLACE_METHOD(0x140F80D70, ItemSocketSystemPageSocketUnlock, FUN_140f80d70, 438, 0xECAEDA60);
MS2_REPLACE_METHOD(0x140F80F30, ItemSocketSystemPageSocketUnlock, FUN_140f80f30, 373, 0x975064D0);
MS2_REPLACE_METHOD(0x140F810B0, ItemSocketSystemPageSocketUnlock, FUN_140f810b0, 65, 0x5B596625);
MS2_REPLACE_METHOD(0x140F81100, ItemSocketSystemPageSocketUnlock, FUN_140f81100, 2362, 0x89F66170);
MS2_REPLACE_METHOD(0x140F81A40, ItemSocketSystemPageSocketUnlock, FUN_140f81a40, 1200, 0x5B4E074A);
MS2_REPLACE_METHOD(0x140F81F00, ItemSocketSystemPageSocketUnlock, FUN_140f81f00, 1074, 0x6C036DA4);
MS2_REPLACE_METHOD(0x140F826B0, ItemSocketSystemPageSocketUnlock, FUN_140f826b0, 637, 0x4E69FD08);
MS2_REPLACE_METHOD(0x140F82940, ItemSocketSystemPageSocketUnlock, SendItemSocketSystemMode14, 265, 0xD82C5B61);
MS2_REPLACE_METHOD(0x140F82A50, ItemSocketSystemPageSocketUnlock, SendItemSocketSystemMode16, 316, 0xA5F94481);
MS2_REPLACE_METHOD(0x140F82D00, ItemSocketSystemPageSocketUnlock, FUN_140f82d00, 63, 0xAB13AB14);
MS2_REPLACE_METHOD(0x140F82D50, ItemSocketSystemPageSocketUnlock, FUN_140f82d50, 178, 0x8CA9523E);
MS2_REPLACE_METHOD(0x140F82E10, ItemSocketSystemPageSocketUnlock, FUN_140f82e10, 178, 0x89C8085C);
MS2_REPLACE_METHOD(0x140F82ED0, ItemSocketSystemPageSocketUnlock, FUN_140f82ed0, 60, 0x0C919240);
MS2_REPLACE_METHOD(0x140F82F20, ItemSocketSystemPageSocketUnlock, SendItemSocketSystemMode0, 95, 0x27AA6D34);
MS2_REPLACE_METHOD(0x140F82F90, ItemSocketSystemPageSocketUnlock, FUN_140f82f90, 200, 0xD31CE18E);
MS2_REPLACE_METHOD(0x140F83060, ItemSocketSystemPageSocketUnlock, FUN_140f83060, 253, 0xCB4FF49C);
MS2_REPLACE_METHOD(0x140F832F0, ItemSocketSystemPageSocketUnlock, FUN_140f832f0, 327, 0x39B1FAC1);
MS2_REPLACE_METHOD(0x140F83440, ItemSocketSystemPageSocketUnlock, FUN_140f83440, 270, 0x68123107);
MS2_REPLACE_METHOD(0x140F83560, ItemSocketSystemPageSocketUnlock, FUN_140f83560, 205, 0x9565FF57);
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9ee0-0x142ca9ff0 .text$yd
