// trademanagerex.h - CTradeManagerEx (player-to-player trade manager, packet type 0x49 and the trade UI messages) and the
// trade UI slot classes TradeSlot / TradeSlotBag. Owning unit: ?\trademanagerex.cpp (three consecutive objs in the exe:
// CTradeManagerEx 0x14185b1b0-0x14185dca0, TradeSlot 0x14185dca0-0x14185e970, TradeSlotBag 0x14185e970-0x14185f0b0;
// dir client\ms2).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/ms2dragslot.h"
#include "ms2/placeholder/uiitemeventlistener.h"

class CItem;
class CInPacket;

// The player-to-player trade manager singleton (FUN_14140ea30 returns it; s_instance is DAT_143ad9d78). Handles the
// trade packet (type 0x82 in, 0x49 out) and the trade-request message boxes.
class CTradeManagerEx;
template <class T> class TSingleton;
template<> class TSingleton<CTradeManagerEx>
{
public:
    TSingleton();                                   // 0x14185db70
    virtual ~TSingleton() { s_instance = 0; }       // 0x14185dba0 (scalar deleting 0x14185dbc0)
    static CTradeManagerEx* s_instance;
    static CTradeManagerEx* GetInstance();              // 0x14140ea30
};

class CTradeManagerEx : public TSingleton<CTradeManagerEx>
{
public:
    CTradeManagerEx();                              // 0x14185b780
    virtual ~CTradeManagerEx();                     // 0x14185b810 (scalar deleting 0x14185dc00)

    // Outgoing packets (type 0x49, sub-code in the comment).
    void SendTradeMode0(__int64 uid);                // 0  request a trade with uid
    void FUN_14185b8e0(__int64 uid, int bAccept);   // 3 accept / 4 decline the request from uid
    void SendTradeMode7();                           // 7
    void SendTradeMode8(__int64 uid, int a, int b);  // 8
    void SendTradeMode9(__int64 uid, int nSlot);     // 9  remove item <uid> from slot
    void SendTradeMode10(__int64 uid);                // 10 (once per uid)
    void SendTradeMode11();                           // 11
    void SendTradeMode13();                           // 13
    void SendTradeMode2(__int64 uid);                // 2
    void SendTradeMode14(__int64 uid);                // 14

    // Incoming packet (opcode 0x82): OnTrade switches on the sub-code.
    void OnTrade(CInPacket& packet);
    void FUN_14185bec0(CInPacket& packet);          // 0  trade request from a player
    void FUN_14185c230();                           // 2  request sent
    void FUN_14185c2a0(CInPacket& packet);          // 1  request failed (reason code)
    void FUN_14185cc60(CInPacket& packet);          // 4  request declined
    void FUN_14185cd10(CInPacket& packet);          // 5  trade started
    void FUN_14185cee0(CInPacket& packet);          // 6  trade finished / cancelled
    void FUN_14185d020(CInPacket& packet);          // 8  item added
    void FUN_14185d380(CInPacket& packet);          // 9  item removed
    void FUN_14185d4f0(CInPacket& packet);          // 10
    void FUN_14185d590(CInPacket& packet);          // 11 confirm
    void FUN_14185d610(CInPacket& packet);          // 12
    void FUN_14185d720();                           // 13
    void FUN_14185d750();                           // 14

    void FUN_14185d7b0();                           // reset the trade state
    void FUN_14185d820(__int64 uid, CStringW strName, CString strChar); // begin a trade with uid
    bool FUN_14185d8b0();                           // can a new trade start?
    __int64 GetUidLastSent();                        // m_uidLastSent
    void FUN_14185dc90();                           // m_bConfirmed = false
    // Inline accessors (COMDATs first emitted in uitradedialogex.cpp).
    __int64 FUN_141b29c10() { return m_uidPartner; }    // 0x141b29c10
    CStringW FUN_141b29c20() { return m_strName; }      // 0x141b29c20
    CString FUN_141b29c70() { return m_strChar; }       // 0x141b29c70

public:
    MS2_LAYOUT_FRIEND;
    bool m_bConfirmed;                              // +0x08
    __int64 m_uidPartner;                           // +0x10
    CStringW m_strName;                             // +0x18
    CString m_strChar;                              // +0x20
    __int64 m_uidLastSent;                          // +0x28
};
MS2_CHECK_SIZE(CTradeManagerEx, 0x30);
MS2_CHECK_OFFSET(CTradeManagerEx, m_uidPartner, 0x10);
MS2_CHECK_OFFSET(CTradeManagerEx, m_strName, 0x18);
MS2_CHECK_OFFSET(CTradeManagerEx, m_strChar, 0x20);
MS2_CHECK_OFFSET(CTradeManagerEx, m_uidLastSent, 0x28);
CTradeManagerEx* FUN_14140ea30();

// The items currently on the trade table: global DAT_143ab2e80 (0x58 bytes, zero-initialised, set up by the
// CTradeManagerEx ctor). m_nSlots slots (5), the items by uid (ATL::CRBMap node: key +0, value +8, color +0x18,
// left/right/parent +0x20/+0x28/+0x30) and by slot index.
class Unk_TradeItemTable
{
public:
    void FUN_14185b1b0();                           // m_nSlots = 5; size the slot array; Reset()
    void FUN_14185b200();                           // Reset: clear the map, size the slot array, clear every slot
    int FUN_14185b2a0(CItem* pItem);                // put the item on the table (assigns a free slot if its slot is -1)
    void FUN_14185b3d0(__int64 uid);                // take the item with this uid off the table
    MS2Ptr<CItem> FUN_14185b4a0(__int64 uid);       // find an item by uid
    void FUN_14185b520(ATL::CAtlArray<MS2Ptr<CItem> >& out); // append every item (MS2Ptr<CItem> copies) to out
    int FUN_14185b5c0();                            // first free slot index, -1 if none

public:
    MS2_LAYOUT_FRIEND;
    int m_nSlots;                                   // +0x00
    ATL::CRBMap<__int64, MS2Ptr<CItem> > m_byUid;   // +0x08
    ATL::CAtlArray<MS2Ptr<CItem> > m_bySlot;        // +0x38
};
MS2_CHECK_SIZE(Unk_TradeItemTable, 0x58);
MS2_CHECK_OFFSET(Unk_TradeItemTable, m_byUid, 0x8);
MS2_CHECK_OFFSET(Unk_TradeItemTable, m_bySlot, 0x38);
extern Unk_TradeItemTable DAT_143ab2e80;

// 0xa8 bytes. vftable 0x142f87cc0 (26 slots, ??_G 0x14185e6e0 sized delete 0xa8), ITooltip @+0x78 0x142f87d98.
// DragSlot::m_nIndex is the trade slot index (0..4 = my offer?), m_bMine tells whose side the slot shows.
class TradeSlot : public MS2DragSlot
{
public:
    TradeSlot(const CString& strName, MS2Ptr<CItem> spItem, int nIndex, bool bMine);    // 0x14185dca0
    virtual ~TradeSlot() = default;                 // 0x14185e6b0 (implicit: the exe's dtor writes no vptr)

    // slots 2-4: GetClassDesc 0x14185e740, TypeCast 0x14185e7b0 / 0x14185e800; ms_ClassInfo 0x143aef8a0,
    // SetupClassInfo 0x14185e750 (parent MS2DragSlot, id 0x6200057).
    EE_DECLARE_CLASS1(TradeSlot, 0x06200057, MS2DragSlot);
public:
    virtual int vfunc_8(void* p);                   // 8  0x14185e1b0 build the item slot tooltip into p
    virtual int vfunc_14();                         // 14 0x14185dd50
    virtual int vfunc_15();                         // 15 0x14185ddf0
    virtual int vfunc_18(void* p);                  // 18 0x14185de60
    virtual int vfunc_20();                         // 20 0x14185e2c0
    virtual CStringW vfunc_22();                    // 22 0x14185e670
    virtual MS2Ptr<CItem> vfunc_25();               // 25 0x14185e320 the item in the slot
    virtual int vfunc_0(void* p);                   // ITooltip 0x14185df40 build the item tooltip into p

    void FUN_14185e370(MS2Ptr<CItem> spItem);       // play the item's pickup/drop sound
    void SetItem(MS2Ptr<CItem> spItem);       // m_spItem = spItem
    int FUN_14185e530();                            // item template id, 0 if empty
    __int64 FUN_14185e580();                        // item uid, 0 if empty
    void FUN_14185e5d0();                           // send "remove item" for this slot if it is mine
    bool IsMine();                           // return m_bMine

public:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CItem> m_spItem;                         // +0x90
    bool m_bMine;                                   // +0xa0
};
MS2_CHECK_SIZE(TradeSlot, 0xa8);
MS2_CHECK_OFFSET(TradeSlot, m_spItem, 0x90);
MS2_CHECK_OFFSET(TradeSlot, m_bMine, 0xa0);

// 0x98 bytes. vftable 0x142f87ef0 (17 slots, ??_G 0x14185ee20 sized delete 0x98), UIItemEventListener @+0x88 0x142f87f80.
class TradeSlotBag : public DragSlotBag, public UIItemEventListener
{
public:
    explicit TradeSlotBag(const CString& strName);  // 0x14185e970
    virtual ~TradeSlotBag();                        // 0x14185ea20

    // slots 2-4: GetClassDesc 0x14185ee80, TypeCast 0x14185eef0 / 0x14185ef40; ms_ClassInfo 0x143aefcf0,
    // SetupClassInfo 0x14185ee90 (parent DragSlotBag, id 0x620005a).
    EE_DECLARE_CLASS1(TradeSlotBag, 0x0620005A, DragSlotBag);
public:
    virtual DragSlot* vfunc_16(int nIndex);         // 16 0x14185eb20 new TradeSlot(name of slot nIndex)
    virtual void vfunc_18(void* p);                 // UIItemEventListener 18-20 (0x14185eac0 / eae0 / eb00): {}
    virtual void vfunc_19(void* p);
    virtual void vfunc_20(void* p);

    void SetMine(bool b);                     // m_bMine = b
    bool IsMine();                           // return m_bMine
    int FUN_14185ec70(void*);                       // return 1 (not virtual)

public:
    MS2_LAYOUT_FRIEND;
    bool m_bMine;                                   // +0x90 (passed to the TradeSlot ctor)
};
MS2_CHECK_SIZE(TradeSlotBag, 0x98);
MS2_CHECK_OFFSET(TradeSlotBag, m_bMine, 0x90);
