// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The socket transfer page of the item socket dialog
// ("SocketTransferPage_*" bags; packet 0x88 operations 0xc / 0x10 / 0x11), the packet records it sends and the
// COMDAT glue of its callbacks.
// MS2-UNIT: unit_140c4ffa0
// MS2-RANGE: 0x140c4ffa0-0x140c54ee0 .text$mn
// MS2-RANGE: 0x1400cd7d0-0x1400cd9a0 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSelectSound@@YAXXZ 0x1400cd890 ; probe
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1400cd8c0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1400cd940 ; probe
// MS2-PIN: ??__Es_strSuccessSound@@YAXXZ 0x1400cd970 ; probe
// MS2-PIN: ??$?8PEAVItemSocketSystemPageSocketTransfer@@P80@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageSocketTransfer@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@0@0@Z 0x140c54430 ; prop
// MS2-PIN: ??$?8PEAVItemSocketSystemPageSocketTransfer@@P80@EAA_NHAEBVCMsgBoxData@@@Z@std@@YA_NAEBU?$pair@PEAVItemSocketSystemPageSocketTransfer@@P81@EAA_NHAEBVCMsgBoxData@@@Z@0@0@Z 0x140c54480 ; prop
// MS2-PIN: ??$forward@AEBQ8ItemSocketSystemPageSocketTransfer@@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@YAAEBQ8ItemSocketSystemPageSocketTransfer@@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@ZAEBQ81@EAAX0@Z@Z 0x140c545b0 ; unique
// MS2-PIN: ??$forward@AEBQEAVItemSocketSystemPageSocketTransfer@@@std@@YAAEBQEAVItemSocketSystemPageSocketTransfer@@AEBQEAV1@@Z 0x140c545d0 ; unique
// MS2-PIN: ??0Unk_SockItemPair@@QEAA@XZ 0x140c548a0 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketTransfer@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c54d00 ; unique
// MS2-PIN: ?vfunc_3@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketTransfer@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBA_NPEBVDelegateImplBase@2@@Z 0x140c54d60 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_GForceFillIngredient@CCItemSocketSystemPacket@@UEAAPEAXI@Z 0x140c54a40
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\itemsocketsystempagesockettransfer.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/itemsocketsystempagesockettransfer.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/citem.h"
#include "ms2/client/ms2/iteminfoslot.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/itemsocket.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/cequipitem.h"
#include "ms2/placeholder/unk_1402a9d70.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/gfxui/dragslot.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The header statics of the original TU (the same set as the other pages of the family).
static CString s_strSortTypeNames[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};
static CString s_strSkill = "skill";
static CString s_strStun = "stun";
static Unk_1402a9d70 s_condition(17, 0.75f, 0.25f, 2.25f, 10);
static CString s_strSelectSound = "System_Gemstone_button_01";        // 0x143abec38
static CString s_strSuccessSound = "System_Gemstone_Success_01";      // 0x143abec88

class Unk_ItemEquipData : public CItemData {};   // CItem::FUN_140527840's record (as commonfiles\item.cpp)
class Unk_TrWorld;
class Unk_TrPlayer;
class Unk_TrInventory;
Unk_TrWorld* FUN_1403ed2d0();
Unk_TrPlayer* FUN_141bd0cc0(Unk_TrWorld*);
Unk_TrInventory* FUN_1416561a0(Unk_TrPlayer*);
void FUN_1411e1ce0(Unk_TrInventory*, CAtlList<MS2Ptr<CEquipItem>>&, int);
// The player's inventory (global 0x143ab2a90).
class Unk_TrBag {
public:
    MS2Ptr<CItem> FUN_140a5d680(__int64 uid);
    int FUN_140a5f180(int itemId, int grade);
    int FUN_140a5f7b0(int itemId);
    void FUN_140a60880(int tab, CAtlArray<MS2Ptr<CItem>>& out);
};
extern Unk_TrBag DAT_143ab2a90;
extern unsigned DAT_143ab2914;

MS2Ptr<CItem> FUN_141425750(__int64 uid, bool* pbEquipped);
void FUN_1412752d0(const CStringW& key, int type);
void FUN_141276180(const CString& sound, const CString& arg);
void FUN_141415600(const CString& name);
void FUN_14141f970(const CString& name);
void FUN_141415450(const CString& name, MS2Ptr<CItem> item, int a, int b, int c);
void FUN_14141ff80(ItemSlotBag* bag, int count);
void FUN_1422cf860(Unk_SocketPageBag* bag);
void FUN_1422cc9e0(DragSlotBag* bag);
NotifyContext::BindData* FUN_1422c8e90(const CString& name);
class Unk_TrDebug;
Unk_TrDebug* FUN_14025e7c0();
bool FUN_14116d720(Unk_TrDebug*);
void FUN_1422ce240(Unk_SocketPageButton*, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>&, int);
struct Unk_TrFindBag { MS2Ptr<Unk_SocketPageBag> FUN_140c4bc60(const CString&); };
struct Unk_TrFindButton { MS2Ptr<Unk_SocketPageButton> FUN_140acce30(const CString&); };
CStringW FUN_14028b8e0(const CStringW& key);
CStringW FUN_1405c2690(CStringW key, const CStringW& arg);
CStringW FUN_1409404f0(__int64 v);
CStringW FUN_1406564a0(const wchar_t* pszFormat, const CStringW& a, const CStringW& b, const CStringW& c);
CStringW FUN_140627390(unsigned id);
CStringW FUN_14062ae60(int itemId);
CStringW FUN_14062b310(MS2Ptr<TSocketGemStoneInfo> info);
int FUN_140628200(MS2Ptr<CItem> source, MS2Ptr<CItem> target);
int FUN_140627e80(MS2Ptr<CItem> item);
void FUN_1406284a0(int level, int flag, int* itemId, int* price);
void FUN_14026bd10(CIngredientContainer* cost, int count, int itemId);
void FUN_140710590(COutPacket&);
MS2Ptr<CMsgBoxData> FUN_140d74090(Delegate<bool(int, const CMsgBoxData&)> cb, CStringW text);
DragSlotBag* FUN_140c54570(const CString& name);
ItemSlotBag* FUN_140c54590(const CString& name);

// The packet records of the page (the encoders are free functions of commonfiles\itemsocketsystemutil.cpp).
struct Unk_SockUidPair {
    Unk_SockUidPair() : m_nFirst(0), m_nSecond(0) {}                // 0x140c54870
    __int64 m_nFirst;
    __int64 m_nSecond;
};
struct Unk_SockItemPair {
    Unk_SockItemPair() : m_spA(0), m_spB(0) {}                      // 0x140c548a0
    ~Unk_SockItemPair() {}                                          // 0x140c54970
    MS2Ptr<CItem> m_spA;
    MS2Ptr<CItem> m_spB;
};
namespace CCItemSocketSystemPacket {
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
struct Unk_SockMsgIIL;
void FUN_140629340(Unk_SockUidPair&, COutputStream&);
void FUN_1406295b0(Unk_SockItemPair&, CInPacket&);
void FUN_140629de0(CCItemSocketSystemPacket::ForceFillIngredient&, COutputStream&);

// @0x140c4ffa0
ItemSocketSystemPageSocketTransfer::ItemSocketSystemPageSocketTransfer()
    : m_state(0), m_source(0), m_target(0), m_sourceUid(0), m_highlightUid(0)
{
    m_sourceName = "SocketTransferPage_selectedSourceSlot";
    m_targetName = "SocketTransferPage_selectedTargetSlot";
    m_ingredientName = "SocketTransferPage_ingredient";
    m_slots0Name = "SocketTransferPage_slots0";
    m_slots1Name = "SocketTransferPage_slots1";
}

// @0x140c501a0
ItemSocketSystemPageSocketTransfer::~ItemSocketSystemPageSocketTransfer()
{
    FUN_140c52930();
}

// @0x140c50300
void ItemSocketSystemPageSocketTransfer::vfunc_1()
{
    ItemSocketSystemPageBase::vfunc_1();
    FUN_140c52930();
}

// @0x140c50330
// MS2-FUNCTIONAL: real controls and callback delegates; temporary and cleanup layout differ.
void ItemSocketSystemPageSocketTransfer::vfunc_7(MS2Ptr<AScript> root)
{
    ItemSocketSystemPageBase::vfunc_7(root);
    if (!(root == 0)) {
        if (m_root == 0)
            m_root = root->FUN_1409b4560("m_socketTransferPage");
        if (!(m_root == 0)) {
            FUN_140c51050();
            {
                MS2Ptr<ASMovieClip> slots = m_root->FUN_1409b4560("m_slots0");
                if (slots.get() != 0)
                    m_sourceControl = reinterpret_cast<Unk_TrFindBag*>(slots.operator->())->FUN_140c4bc60("m_itemBag");
            }
            {
                MS2Ptr<ASMovieClip> slots = m_root->FUN_1409b4560("m_slots1");
                if (slots.get() != 0)
                    m_targetControl = reinterpret_cast<Unk_TrFindBag*>(slots.operator->())->FUN_140c4bc60("m_itemBag");
            }
            bool debug = FUN_14116d720(FUN_14025e7c0());
            m_debugButton = reinterpret_cast<Unk_TrFindButton*>(m_root.operator->())->FUN_140acce30("m_debugBtnAction");
            if (m_debugButton.get() != 0) {
                m_debugButton->vfunc_3(debug);
                if (debug)
                    FUN_1422ce240(m_debugButton.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageSocketTransfer::FUN_140c53a70), 0);
            }
            m_debugFillButton = reinterpret_cast<Unk_TrFindButton*>(m_root.operator->())->FUN_140acce30("m_debugBtnFillIngredient");
            if (m_debugFillButton.get() != 0) {
                m_debugFillButton->vfunc_3(debug);
                if (debug)
                    FUN_1422ce240(m_debugFillButton.operator->(), Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>(this, &ItemSocketSystemPageSocketTransfer::FUN_140c53e40), 0);
            }
            FUN_140f6d450(m_slots0Name, m_sourceItems, 0x435, 0x20);
            FUN_140f6d450(m_slots1Name, m_targetItems, 0x415, 0x20);
            FUN_140f6d590(m_sourceName, m_source, 0x405, 0x20);
            ASObj data(2);
            data.FUN_1407cba60("bagId0", m_slots0Name);
            data.FUN_1407cba60("bagId1", m_slots1Name);
            data.FUN_1407cba60("selectedSlotId", m_sourceName);
            m_root->Invoke("initData", data.FUN_1422bb870());
            m_state = 0;
            FUN_140f6dbe0(m_sourceControl);
            FUN_140f6dbe0(m_targetControl);
        }
    }
}

// @0x140c50d20
void ItemSocketSystemPageSocketTransfer::vfunc_2()
{
    ItemSocketSystemPageBase::vfunc_2();
    FUN_140c52930();
}

// @0x140c50d50
void ItemSocketSystemPageSocketTransfer::vfunc_5(CInPacket* packet)
{
    ItemSocketSystemPageBase::vfunc_5(packet);
    unsigned char operation = packet->vfunc_o8_1();
    FUN_140f6d620(1);
    if (operation == 13)
        FUN_140c533f0(packet);
    else if (operation == 16)
        FUN_140c53920();
    else if (operation == 18)
        vfunc_8(packet);
}

// @0x140c50e00
// MS2-FUNCTIONAL: typed ASData event decoding and smart-pointer temporary layout.
int ItemSocketSystemPageSocketTransfer::vfunc_3(const char* event, const Scaleform::GFx::Value* args, int count)
{
    if (_stricmp("onIndexChangeSlot0", event) == 0) {
        ASData data;
        if (data.FUN_1422b9620(args, count) != 0) {
            MS2Ptr<CItem> item = FUN_140f6d840(m_sourceItems, data.FUN_1422b8a10());
            FUN_140c51680(item);
        }
        return 1;
    } else if (_stricmp("onIndexChangeSlot1", event) == 0) {
        ASData data;
        if (data.FUN_1422b9620(args, count) != 0) {
            MS2Ptr<CItem> item = FUN_140f6d840(m_targetItems, data.FUN_1422b8a10());
            FUN_140c51a60(item);
        }
        return 1;
    } else if (_stricmp("onClickAction", event) == 0) {
        if (m_state == 1)
            FUN_140c51fa0();
        else if (m_state == 2)
            FUN_140c527d0();
    }
    return 0;
}

// @0x140c51050
// MS2-FUNCTIONAL: typed inventory and equipped-item enumeration; smart-pointer temporaries differ.
void ItemSocketSystemPageSocketTransfer::FUN_140c51050()
{
    Unk_TrPlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
    if (player != 0) {
        m_sourceItems.RemoveAll();
        CAtlArray<MS2Ptr<CItem>> items;
        FUN_140c53f90(items);
        if (!items.IsEmpty()) {
            size_t count = items.GetCount();
            for (size_t i = 0; i < count; ++i) {
                MS2Ptr<CItem> item(items.GetAt(i));
                if (!(item == 0) && item->FUN_140529560() != 0 && item->FUN_1405279c0() != 0
                    && FUN_140627e80(MS2Ptr<CItem>(item)) != 0)
                    m_sourceItems.Add(item);
            }
        }
        CAtlList<MS2Ptr<CEquipItem>> equipped(10);
        FUN_1411e1ce0(FUN_1416561a0(player), equipped, 1);
        POSITION pos = equipped.GetHeadPosition();
        while (pos != 0) {
            MS2Ptr<CEquipItem> equip(equipped.GetAt(pos));
            if (!(equip == 0)) {
                MS2Ptr<CItem> item = equip->FUN_1411dc7a0();
                if (!(item == 0) && item->FUN_140529560() != 0 && item->FUN_1405279c0() != 0
                    && FUN_140627e80(MS2Ptr<CItem>(item)) != 0)
                    m_sourceItems.Add(item);
            }
            equipped.GetNext(pos);
        }
    }
}

// @0x140c51410
// MS2-FUNCTIONAL: typed candidate filter; smart-pointer temporaries differ.
void ItemSocketSystemPageSocketTransfer::FUN_140c51410()
{
    if (!(m_source == 0) && m_source->FUN_1405279c0() != 0) {
        Unk_TrPlayer* player = FUN_141bd0cc0(FUN_1403ed2d0());
        if (player != 0) {
            m_targetItems.RemoveAll();
            CAtlArray<MS2Ptr<CItem>> items;
            FUN_140c53f90(items);
            if (!items.IsEmpty()) {
                size_t count = items.GetCount();
                for (size_t i = 0; i < count; ++i) {
                    MS2Ptr<CItem> item(items.GetAt(i));
                    if (!(item == 0) && FUN_140628200(MS2Ptr<CItem>(m_source), MS2Ptr<CItem>(item)) != 0)
                        m_targetItems.Add(item);
                }
            }
            ItemSlotBag* bag = FUN_140c54590(m_slots1Name);
            if (bag != 0) {
                FUN_14141ff80(bag, (int)m_targetItems.GetCount());
                if (m_targetControl.get() != 0)
                    FUN_1422cf860(m_targetControl.operator->());
            }
        }
    }
}

// @0x140c51680
// MS2-FUNCTIONAL: Scaleform data and selection refresh with typed temporaries.
void ItemSocketSystemPageSocketTransfer::FUN_140c51680(MS2Ptr<CItem> item)
{
    FUN_140c52a80();
    if (m_root == 0)
        return;
    if (!(item == 0) && item->FUN_140527840() != 0) {
        __int64 uid = item->FUN_140526a50();
        if (FUN_141425750(uid, 0) == 0) {
            FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
            return;
        }
        CItemSocket* socket = item->FUN_1405279c0();
        if (socket != 0 && socket->FUN_140620a50() != 0) {
            FUN_141276180(s_strSelectSound, CString(""));
            socket->FUN_140620a70();
            m_source = item;
            FUN_140f6d340(m_sourceName, m_source);
            ASObj data(2);
            data.FUN_1407cbb20("itemName", m_source->FUN_140528160());
            FUN_140c52b20(data);
            m_root->Invoke("playSelect", data.FUN_1422bb870());
            m_state = 1;
            m_sourceUid = m_source->FUN_140526a50();
            FUN_140c51410();
            FUN_140f6dbe0(m_targetControl);
        }
    }
}

// @0x140c51a60
// MS2-FUNCTIONAL: Scaleform data and selection refresh with typed temporaries.
void ItemSocketSystemPageSocketTransfer::FUN_140c51a60(MS2Ptr<CItem> item)
{
    if (m_root == 0 || m_source == 0)
        return;
    CItemSocket* socket = m_source->FUN_1405279c0();
    if (socket == 0 || socket->FUN_140620a50() == 0)
        return;
    if (!(item == 0) && item->FUN_140527840() != 0) {
        if (m_state != 1 && m_state != 2) {
            FUN_140f6dbe0(m_targetControl);
            return;
        }
        FUN_141276180(s_strSelectSound, CString(""));
        if (m_state == 2) {
            FUN_140c527d0();
            return;
        }
        __int64 uid = item->FUN_140526a50();
        if (FUN_141425750(uid, 0) == 0) {
            FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_transfer"), 1);
            return;
        }
        CItemSocket* targetSocket = item->FUN_1405279c0();
        if (targetSocket == 0 || targetSocket->FUN_140620a50() == 0)
            return;
        if (FUN_141bd0cc0(FUN_1403ed2d0()) == 0)
            return;
        m_target = item;
        if (FUN_140628200(MS2Ptr<CItem>(m_source), MS2Ptr<CItem>(m_target)) == 0) {
            FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_transfer"), 1);
            return;
        }
        FUN_140f6d340(m_targetName, m_target);
        ASObj data(2);
        data.FUN_1407cbb20("targetName", m_target->FUN_140528160());
        m_root->Invoke("selectTarget", data.FUN_1422bb870());
    }
}

// @0x140c51fa0
// MS2-FUNCTIONAL: validation chain with typed ingredient list; cleanup layout differs.
void ItemSocketSystemPageSocketTransfer::FUN_140c51fa0()
{
    if (!(m_source == 0) && m_source->FUN_140527840() != 0) {
        __int64 sourceUid = m_source->FUN_140526a50();
        if (FUN_141425750(sourceUid, 0) == 0) {
            FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
            return;
        }
        CItemSocket* sourceSocket = m_source->FUN_1405279c0();
        if (sourceSocket != 0 && sourceSocket->FUN_140620a50() != 0) {
            __int64 targetUid = 0;
            if (m_target == 0) {
                FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_transfer_null"), 1);
                return;
            }
            targetUid = m_target->FUN_140526a50();
            if (DAT_143ab2a90.FUN_140a5d680(targetUid) == 0) {
                FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_transfer"), 1);
                return;
            }
            MS2Ptr<CItemData> sourceData(m_source->FUN_140527840());
            unsigned level = sourceSocket->FUN_140620a20();
            int flag = sourceData->FUN_14053de40();
            int itemId = 0;
            int price = 0;
            FUN_1406284a0(level, flag, &itemId, &price);
            CIngredientContainer cost;
            FUN_14026bd10(&cost, itemId, price);
            Unk_IngVec* entries = cost.FUN_14026c230();
            size_t count = entries->FUN_14028b500();
            for (size_t i = 0; i < count; ++i) {
                Unk_IngRef ingredient(*entries->FUN_14028a0f0(i));
                if (!(ingredient == 0)) {
                    int have = DAT_143ab2a90.FUN_140a5f180(ingredient->m_a, 0);
                    if (ingredient->m_b != 0)
                        have = DAT_143ab2a90.FUN_140a5f7b0(ingredient->m_b);
                    int need = ingredient->m_c;
                    if (have < need) {
                        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_lack_price"), 1);
                        return;
                    }
                }
            }
            MS2Ptr<CItemData> targetData(m_target->FUN_140527840());
            if (!(targetData == 0)) {
                CItemSocket* targetSocket = m_target->FUN_1405279c0();
                if (targetSocket != 0) {
                    if (FUN_140628200(MS2Ptr<CItem>(m_source), MS2Ptr<CItem>(m_target)) == 0) {
                        FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_transfer"), 1);
                        return;
                    }
                    if (targetData->FUN_14053cf90()) {
                        if (reinterpret_cast<CItemTransfer*>(m_target->FUN_140527930())->FUN_140635120() == 0 && targetSocket->FUN_140620a20() == 0) {
                            MS2Ptr<CMsgBoxData> box = FUN_140d74090(
                                Delegate<bool(int, const CMsgBoxData&)>(this, &ItemSocketSystemPageSocketTransfer::FUN_140c54210),
                                CStringW(L"s_itemsocketsystem_socketunlock_msg_ask_transfer_skin_first"));
                            if (box.get() != 0) {
                                box->FUN_1405340b0(sourceUid);
                                box->FUN_1405340b0(targetUid);
                            }
                            return;
                        }
                    }
                    Unk_SockUidPair request;
                    request.m_nFirst = sourceUid;
                    request.m_nSecond = targetUid;
                    FUN_140c53fc0(request);
                }
            }
        }
    }
}

// @0x140c527d0
void ItemSocketSystemPageSocketTransfer::FUN_140c527d0()
{
    m_sourceUid = 0;
    m_source = 0;
    m_target = 0;
    FUN_140f6d340(m_sourceName, m_source);
    FUN_140f6dbe0(m_sourceControl);
    FUN_140f6dbe0(m_targetControl);
    m_root->Invoke("playStart");
}

// @0x140c52930
void ItemSocketSystemPageSocketTransfer::FUN_140c52930()
{
    FUN_14141f970(m_slots0Name);
    FUN_14141f970(m_slots1Name);
    FUN_14141f970(m_ingredientName);
    FUN_141415600(m_sourceName);
    FUN_141415600(m_targetName);
    m_source = 0;
    m_target = 0;
    m_ingredients.RemoveAll();
    m_sourceItems.RemoveAll();
    m_targetItems.RemoveAll();
    m_sourceUid = 0;
    m_highlightUid = 0;
    m_sourceControl = 0;
    m_targetControl = 0;
    m_debugButton = 0;
    m_debugFillButton = 0;
    m_state = 0;
}

// @0x140c52a80
void ItemSocketSystemPageSocketTransfer::FUN_140c52a80()
{
    m_source = 0;
    m_target = 0;
}

// @0x140c52ac0
void ItemSocketSystemPageSocketTransfer::FUN_140c52ac0()
{
    FUN_141415600(m_targetName);
    FUN_14141f970(m_ingredientName);
    m_target = 0;
    m_ingredients.RemoveAll();
}

// @0x140c52b20
// MS2-FUNCTIONAL: typed ingredient price lookup and fee text; temporary layout differs.
void ItemSocketSystemPageSocketTransfer::FUN_140c52b20(ASObj& data)
{
    FUN_140c52ac0();
    if (!(m_source == 0) && m_source->FUN_140527840() != 0) {
        CItemSocket* socket = m_source->FUN_1405279c0();
        if (socket != 0) {
            MS2Ptr<CItemData> sourceData(m_source->FUN_140527840());
            unsigned level = socket->FUN_140620a20();
            int flag = sourceData->FUN_14053de40();
            int itemId = 0;
            int price = 0;
            FUN_1406284a0(level, flag, &itemId, &price);
            __int64 fee = 0;
            CIngredientContainer cost(1);
            if (price < 0)
                price = 0;
            FUN_14026bd10(&cost, itemId, price);
            FUN_140f6dc70(m_ingredientName, cost, data, m_ingredients, MS2Ptr<CItem>(m_source), &fee, MS2Ptr<SaleParam>(0));
            FUN_141415450(m_targetName, MS2Ptr<CItem>(m_target), 0, 0x405, 0x20);
            data.FUN_1407cba60("ingredientEquipSlotId", m_targetName);
            if (fee != 0)
                data.FUN_1407cbb20("transferFee", FUN_1405c2690(CStringW(L"s_itemenchant_fee"), FUN_1409404f0(fee)));
        }
    }
}

// @0x140c52f10
// MS2-FUNCTIONAL: socket row texts built with typed temporaries; string temporary layout differs.
void ItemSocketSystemPageSocketTransfer::FUN_140c52f10(MS2Ptr<CItem> item, ASObj& data, int unlockIndex)
{
    if (!(item == 0) && item->FUN_140527840() != 0) {
        CItemSocket* socket = item->FUN_1405279c0();
        if (socket == 0)
            return;
        if (socket->FUN_140620a50() == 0)
            return;
        ASArray rows(2);
        unsigned open = socket->FUN_140620a20();
        CStringW emptyText;
        CStringW rowStat = FUN_14028b8e0(CStringW(L"s_itemsocketsystem_socketunlock_row_socket_stat"));
        for (unsigned i = 0; i < open; ++i) {
            CStringW text;
            MS2Ptr<TSocketGemStoneInfo> info = socket->FUN_140620b70(i);
            if (!(info == 0) && !info->FUN_14061fab0()) {
                int gemId = info->FUN_140620260();
                text = FUN_1406564a0(rowStat, FUN_140627390(gemId), FUN_14062ae60(gemId), FUN_14062b310(MS2Ptr<TSocketGemStoneInfo>(info)));
            } else {
                if (emptyText.IsEmpty())
                    emptyText = FUN_14028b8e0(CStringW(L"s_itemsocketsystem_socketunlock_row_socket_empty"));
                text = emptyText;
            }
            rows.FUN_1422bbfe0(text);
        }
        unsigned left = socket->FUN_140620a70();
        if (left != 0) {
            CStringW lockText = FUN_14028b8e0(CStringW(L"s_itemsocketsystem_socketunlock_row_socket_lock"));
            for (unsigned i = 0; i < left; ++i)
                rows.FUN_1422bbfe0(lockText);
        }
        data.FUN_1409adbe0("arrSocket", rows.FUN_1422bb870());
        data.FUN_1407cb9c0("unlockSocketIndex", unlockIndex);
    }
}

// @0x140c533f0
// MS2-FUNCTIONAL: transfer result refresh with typed temporaries.
void ItemSocketSystemPageSocketTransfer::FUN_140c533f0(CInPacket* packet)
{
    if (!(m_root == 0) && !(m_source == 0) && !(m_target == 0)) {
        if (m_source->FUN_1405279c0() != 0) {
            __int64 uid = m_source->FUN_140526a50();
            Unk_SockItemPair result;
            result.m_spA = m_source;
            result.m_spB = m_target;
            FUN_1406295b0(result, *packet);
            FUN_140f6d340(m_targetName, m_target);
            ASObj data(2);
            data.FUN_1407cb9c0("unlockSocketIndex", -1);
            FUN_140c52f10(MS2Ptr<CItem>(m_target), data, -1);
            data.FUN_1407cbb20("itemName", m_target->FUN_140528160());
            m_sourceUid = 0;
            uid = m_target->FUN_140526a50();
            FUN_141276180(s_strSuccessSound, CString(""));
            m_root->Invoke("playSuccess", data.FUN_1422bb870());
            m_state = 2;
            FUN_140f6dbe0(m_targetControl);
            FUN_140f6dbe0(m_sourceControl);
            FUN_140c54030();
            FUN_140f6e700(m_source->FUN_140526a50());
            FUN_140f6e700(m_target->FUN_140526a50());
            FUN_140c51050();
            DragSlotBag* bag = FUN_140c54570(m_slots0Name);
            if (bag != 0) {
                FUN_1422cc9e0(bag);
                bag->vfunc_10((int)m_sourceItems.GetCount());
            }
            if (m_sourceControl.get() != 0)
                FUN_1422cf860(m_sourceControl.operator->());
            FUN_140c54100(uid);
        }
    }
}

// @0x140c53920
void ItemSocketSystemPageSocketTransfer::FUN_140c53920()
{
    if (!(m_root == 0) && !(m_source == 0)) {
        if (m_source->FUN_140527840() != 0 && DAT_143ab2914 > 0x31 && m_state == 1) {
            __int64 price = 0;
            FUN_140f6e250(m_ingredientName, m_ingredients, MS2Ptr<CItem>(m_source), &price, MS2Ptr<SaleParam>(0));
        }
    }
}

// @0x140c53a70
// MS2-FUNCTIONAL: debug transfer request through the typed packet record.
void ItemSocketSystemPageSocketTransfer::FUN_140c53a70(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (!(m_source == 0) && DAT_143ab2914 > 0x31 && m_state == 1 && !(m_source == 0)) {
        if (m_source->FUN_140527840() != 0) {
            __int64 sourceUid = m_source->FUN_140526a50();
            if (FUN_141425750(sourceUid, 0) == 0) {
                FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target"), 1);
                return;
            }
            CItemSocket* socket = m_source->FUN_1405279c0();
            if (socket != 0 && socket->FUN_140620a50() != 0) {
                if (m_target == 0) {
                    FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_transfer_null"), 1);
                    return;
                }
                __int64 targetUid = m_target->FUN_140526a50();
                if (DAT_143ab2a90.FUN_140a5d680(targetUid) == 0) {
                    FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_transfer"), 1);
                    return;
                }
                if (FUN_140628200(MS2Ptr<CItem>(m_source), MS2Ptr<CItem>(m_target)) == 0) {
                    FUN_1412752d0(CStringW(L"s_itemsocketsystem_error_invalid_target_transfer"), 1);
                    return;
                }
                Unk_SockUidPair request;
                request.m_nFirst = sourceUid;
                request.m_nSecond = targetUid;
                COutPacket out(0x88, 0);
                out.Encode1(0x11);
                FUN_140629340(request, out);
                FUN_140710590(out);
            }
        }
    }
}

// @0x140c53e40
// MS2-FUNCTIONAL: debug fill-ingredient request through the typed packet record.
void ItemSocketSystemPageSocketTransfer::FUN_140c53e40(const Scaleform::GFx::FunctionHandler::Params&)
{
    if (!(m_source == 0)) {
        if (m_source->FUN_1405279c0() != 0 && DAT_143ab2914 > 0x31 && m_state == 1) {
            if (FUN_140627e80(MS2Ptr<CItem>(m_source)) != 0) {
                CCItemSocketSystemPacket::ForceFillIngredient fill;
                fill.m_nType = 0xc;
                fill.m_nUid = m_source->FUN_140526a50();
                COutPacket out(0x88, 0);
                out.Encode1(0x10);
                FUN_140629de0(fill, out);
                FUN_140710590(out);
            }
        }
    }
}

// @0x140c53f90
void ItemSocketSystemPageSocketTransfer::FUN_140c53f90(CAtlArray<MS2Ptr<CItem>>& out)
{
    DAT_143ab2a90.FUN_140a60880(1, out);
}

// @0x140c53fc0
void ItemSocketSystemPageSocketTransfer::FUN_140c53fc0(Unk_SockUidPair& request)
{
    COutPacket out(0x88, 0);
    out.Encode1(0xc);
    FUN_140629340(request, out);
    FUN_140710590(out);
}

// @0x140c54030
void ItemSocketSystemPageSocketTransfer::FUN_140c54030()
{
    int index = -1;
    MS2Ptr<CItem> found = FUN_140f6d6b0(m_sourceUid, m_sourceItems, &index);
    FUN_140f6dbe0(m_sourceControl);
    if (found == 0)
        m_sourceUid = 0;
}

// @0x140c54100
void ItemSocketSystemPageSocketTransfer::FUN_140c54100(__int64 uid)
{
    __int64 previous = m_highlightUid;
    if (previous != uid && previous != 0) {
        int index = -1;
        FUN_140f6d6b0(previous, m_sourceItems, &index);
        if (-1 < index)
            FUN_140f6e500(index, false);
    }
    if (uid != 0) {
        int index = -1;
        FUN_140f6d6b0(uid, m_sourceItems, &index);
        if (-1 < index)
            FUN_140f6e500(index, true);
    }
    m_highlightUid = uid;
}

// @0x140c54210
bool ItemSocketSystemPageSocketTransfer::FUN_140c54210(int result, const CMsgBoxData& box)
{
    if (result == 0) {
        __int64 first = box.FUN_141a02f10(0, 0);
        __int64 second = box.FUN_141a02f10(1, 0);
        Unk_SockUidPair request;
        request.m_nFirst = first;
        request.m_nSecond = second;
        FUN_140c53fc0(request);
    }
    return true;
}

// @0x140c544d0
DragSlotBag* FUN_140c544d0(NotifyContext::BindData* p)
{
    DragSlotBag* bag = 0;
    if (p != 0 && p->TypeCast(0x6202736, (void**)&bag))
        return bag;
    else
        return 0;
}

// @0x140c54520
ItemSlotBag* FUN_140c54520(NotifyContext::BindData* p)
{
    ItemSlotBag* bag = 0;
    if (p != 0 && p->TypeCast(0x620002e, (void**)&bag))
        return bag;
    else
        return 0;
}

// @0x140c54570
DragSlotBag* FUN_140c54570(const CString& name)
{
    return FUN_140c544d0(FUN_1422c8e90(name));
}

// @0x140c54590
ItemSlotBag* FUN_140c54590(const CString& name)
{
    return FUN_140c54520(FUN_1422c8e90(name));
}

// Hooks (functions that build no callback delegates and read no unit statics).
MS2_REPLACE_METHOD(0x140C50300, ItemSocketSystemPageSocketTransfer, vfunc_1, 34, 0xA88F668C);
MS2_REPLACE_METHOD(0x140C50D20, ItemSocketSystemPageSocketTransfer, vfunc_2, 34, 0xF66F66F3);
MS2_REPLACE_METHOD(0x140C50E00, ItemSocketSystemPageSocketTransfer, vfunc_3, 570, 0x2306E369);
MS2_REPLACE_METHOD(0x140C50D50, ItemSocketSystemPageSocketTransfer, vfunc_5, 166, 0x59B3020E);
MS2_REPLACE_METHOD(0x140C51050, ItemSocketSystemPageSocketTransfer, FUN_140c51050, 951, 0x7BDED608);
MS2_REPLACE_METHOD(0x140C51410, ItemSocketSystemPageSocketTransfer, FUN_140c51410, 615, 0xFC56AB9C);
MS2_REPLACE_METHOD(0x140C527D0, ItemSocketSystemPageSocketTransfer, FUN_140c527d0, 332, 0x54CB44DE);
MS2_REPLACE_METHOD(0x140C52930, ItemSocketSystemPageSocketTransfer, FUN_140c52930, 322, 0x5C280B39);
MS2_REPLACE_METHOD(0x140C52A80, ItemSocketSystemPageSocketTransfer, FUN_140c52a80, 52, 0xB67C4D1C);
MS2_REPLACE_METHOD(0x140C52AC0, ItemSocketSystemPageSocketTransfer, FUN_140c52ac0, 86, 0x639902B4);
MS2_REPLACE_METHOD(0x140C52B20, ItemSocketSystemPageSocketTransfer, FUN_140c52b20, 995, 0x9CEADCBE);
MS2_REPLACE_METHOD(0x140C52F10, ItemSocketSystemPageSocketTransfer, FUN_140c52f10, 1237, 0x59CBBE94);
MS2_REPLACE_METHOD(0x140C53920, ItemSocketSystemPageSocketTransfer, FUN_140c53920, 319, 0x125C8A93);
MS2_REPLACE_METHOD(0x140C53A70, ItemSocketSystemPageSocketTransfer, FUN_140c53a70, 957, 0xE021B62B);
MS2_REPLACE_METHOD(0x140C53E40, ItemSocketSystemPageSocketTransfer, FUN_140c53e40, 326, 0x93DED7C3);
MS2_REPLACE_METHOD(0x140C53F90, ItemSocketSystemPageSocketTransfer, FUN_140c53f90, 41, 0x01CA403F);
MS2_REPLACE_METHOD(0x140C53FC0, ItemSocketSystemPageSocketTransfer, FUN_140c53fc0, 95, 0x9F00587C);
MS2_REPLACE_METHOD(0x140C54030, ItemSocketSystemPageSocketTransfer, FUN_140c54030, 200, 0xDE335BE4);
MS2_REPLACE_METHOD(0x140C54100, ItemSocketSystemPageSocketTransfer, FUN_140c54100, 253, 0x87789B05);
MS2_REPLACE_METHOD(0x140C54210, ItemSocketSystemPageSocketTransfer, FUN_140c54210, 120, 0xB1E4E0BC);

// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketTransfer@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@QEAA@AEBV01@@Z 0x140c54720
// MS2-PIN: ??0?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketTransfer@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@QEAA@AEBV01@@Z 0x140c54680
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketTransfer@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c54bd0
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVItemSocketSystemPageSocketTransfer@@P81@EAAXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@std@@@?$Delegate@$$A6AXAEBUParams@FunctionHandler@GFx@Scaleform@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140c54b70
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca2e40-0x142ca2f10 .text$yd
