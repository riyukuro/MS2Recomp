// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CTradeManagerEx: the player-to-player trade manager (first of
// the three consecutive trademanagerex.cpp objs; the exe unit ?\trademanagerex.cpp was split in the queue).
// MS2-UNIT: ?\trademanagerex.cpp#1
// MS2-RANGE: 0x14185b130-0x14185dca0 .text$mn
// MS2-RANGE: 0x14010e4a0-0x14010e670 .text$di
// MS2-PIN: ??0?$TSingleton@VCTradeManagerEx@@@@QEAA@XZ 0x14185db70
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GCTradeManagerEx@@UEAAPEAXI@Z 0x14185dc00 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: memmove_s 0x14185b660
// MS2-PIN: ??0Unk_TradeItemTable@@QEAA@XZ 0x14185b130
// MS2-PIN: ??1Unk_TradeItemTable@@QEAA@XZ 0x14185b170
// MS2-PIN: ??$?0W4Unk_TradeResult@@$0A@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@QEAA@AEBW4Unk_TradeResult@@@Z 0x14185d930
// MS2-PIN: ??$Unk_TradeFormat@W4Unk_TradeResult@@@@YA?AV?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HAEBW4Unk_TradeResult@@@Z 0x14185d960
// MS2-PIN: ??$FormatCustomArg@W4Unk_TradeResult@@@?$MakeValue@V?$BasicFormatter@_W@fmt@@@internal@fmt@@SAXPEAXPEBX0@Z 0x14185db10
// MS2-PIN: ??$format_arg@_WW4Unk_TradeResult@@@fmt@@YAXAEAV?$BasicFormatter@_W@0@AEAPEB_WAEBW4Unk_TradeResult@@@Z 0x14185d9f0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\trademanagerex.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "trademanagerex.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uimessagebox.h"
#include "ms2/commonfiles/blockchecker.h"
#include "blockmanager.h"
#include "pcbase.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/cgameoption.h"
#include "ms2/placeholder/fittingdollpc.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/uitradedialogex.h"   // C3: UITradeDialogEx members

// ---- out-of-unit callees ----

// Client options (+8: refuse trade requests).
struct Unk_TradeOptions
{
    __int64 m_pad_00;
    bool m_bRefuseTrade;
};
class Unk_TradeConfig;
class Unk_BuddyOptions   // C3: member view for the former free stand-ins
{
public:
    struct Unk_BuddySettings& GetSettings();
};

// The trade window (UI id 0x4e83): +0x1a0 is the partner's name.
class Unk_TradeDialog : public UIDialog
{
public:
    CStringW GetPartner();                           // m_strPartner (this unit)
    char m_pad_178[0x28];
    CStringW m_strPartner;                              // +0x1a0
};
MS2_CHECK_OFFSET(Unk_TradeDialog, m_strPartner, 0x1a0);
template <class T> T* Unk_InvGetDialogById(int nId);   // C3: was FUN_14140e820 (the open UI with this id, 0 if none; invenslot.cpp)

// UI manager (FUN_1403ed2b0).
class Unk_TradeUIManager
{
public:
    void FUN_141adc530(int nUiId);                      // open
};
Unk_TradeUIManager* FUN_1403ed2b0();

// Inventory event notifier (FUN_140a6a840): +0x88 an item was added to the trade table.
class Unk_TradeInventory
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17(CItem* pItem);                // 0x88
    virtual void vfunc_18(CItem* pItem);                // 0x90
};
class Unk_InventoryListener* FUN_140a6a840();   // C3: was FUN_140a6a840

class Unk_TradeWorld
{
public:
};

   // the player's account/character name (PCBase member: this=rcx, hidden return=rdx)
class Unk_InventoryStateManager* FUN_140a6a830();   // C3: was FUN_140a6a830
CStringW FUN_1401ca400(const BlockPtr& record, int action);
Unk_MessageBoxPtr FUN_14151f820();
Unk_MessageBoxPtr FUN_140d73d20(int, CStringW, void*, CStringW);
void FUN_140d73c60(Unk_MessageBoxPtr);
class CMsgBoxData   // C3: unit-local view
{
public:
    template <class T> void Append(T value);
    void SetTimer(int a, int b, const CStringW& str);
    void FUN_141a02460(int n);
    void FUN_141a02480(int n);
    void FUN_141a024a0(int n);
};
template <class T> class Unk_BreakPtr { public: operator T*() const; T* operator->() const; };   // C3: view of itembreakmanager.h
#define TM_BOX(p) reinterpret_cast<const Unk_BreakPtr<CMsgBoxData>&>(p)
int FUN_14025a620(class Unk_ConstVal*);
class Unk_SingletonObj1* FUN_1401d3200();   // C3: was void* FUN_1401d3200()
CStringW GetStringCommon(int id);
template <class A> CStringW FormatStringId(int nId, const A& a);
CStringW BlockFormat(int id);
CStringW FUN_140a22c00(int id, const CStringW& a, const unsigned short& n);
void FUN_1412751b0(const CStringW& text, int channel);
void FUN_1412751f0(const CStringW& text, int a, int b);
void FUN_141275260(int stringId, int a, int b);
int FUN_141276180(const CString& strSound, const CString& strArg);
template <class T> void Unk_AkoMessage(int, int, int, const T&);   // C3: was FUN_140961010
void FUN_140f8ff40(int, int, int);
void FUN_140710590(COutPacket& packet);

// The string table entry formatter with one enum argument: FMT_VARIADIC_W instance (0x14185d960).
enum Unk_TradeResult : unsigned int {};
CStringW Unk_TradeFormat(int, const fmt::ArgList&);
FMT_VARIADIC_W(CStringW, Unk_TradeFormat, int)

// ---- statics (.text$di) ----
static CStringW s_requestTradeEx(L"requestTradeEx");
#include "ms2/placeholder/header_statics_a.h"     // sort names, skill/stun, the condition table (Unk_1402a9d70: ctor 0x1402a9d70)
#include "ms2/client/ms2/trademanagerex.h"
#include "ms2/client/ms2/uiservice.h"  // C3: CUIService::OpenDialog
#include "ms2/placeholder/wcformat.h"  // C3: FUN_14028dfa0 wrappers
static CString s_inviteSuccess("PC_InviteSuccess");

CTradeManagerEx* TSingleton<CTradeManagerEx>::s_instance = 0;
inline TSingleton<CTradeManagerEx>::TSingleton() { s_instance = static_cast<CTradeManagerEx*>(this); }

MS2_EMIT_CRT_MEMMOVE_S();

// ---- Unk_TradeItemTable ----
Unk_TradeItemTable::Unk_TradeItemTable() {}
Unk_TradeItemTable::~Unk_TradeItemTable() {}

// @0x14185b1b0
void Unk_TradeItemTable::FUN_14185b1b0()
{
    m_nSlots = 5;
    m_bySlot.SetCount(m_nSlots);
    FUN_14185b200();
}

// @0x14185b200
void Unk_TradeItemTable::FUN_14185b200()
{
    m_byUid.RemoveAll();
    m_bySlot.RemoveAll();
    m_bySlot.SetCount(m_nSlots);
    for (int i = 0; i < m_nSlots; i++)
        m_bySlot[i] = 0;
}

// @0x14185b2a0
int Unk_TradeItemTable::FUN_14185b2a0(CItem* pItem)
{
    if (m_byUid.Lookup(pItem->GetItemUid()) != 0)
        return 0;
    int nSlot = pItem->FUN_140526b50();
    if (nSlot >= m_nSlots)
        return 0;
    if (nSlot != -1)
    {
        if (m_bySlot[nSlot].get() != 0)
            return 0;
    }
    else
    {
        int nFree = FUN_14185b5c0();
        if (nFree == -1)
            return 0;
        nSlot = nFree;
        pItem->FUN_140526b70(nSlot);
    }
    {
        MS2Ptr<CItem> spItem(pItem);
        m_byUid.SetAt(pItem->GetItemUid(), spItem);
    }
    m_bySlot[nSlot].AssignRaw(pItem);
    return 1;
}

// @0x14185b3d0
void Unk_TradeItemTable::FUN_14185b3d0(__int64 uid)
{
    MS2Ptr<CItem> spItem;
    if (m_byUid.Lookup(uid, spItem))
    {
        m_byUid.RemoveKey(uid);
        if (spItem.get())
        {
            int nSlot = spItem->FUN_140526b50();
            if (nSlot >= m_nSlots)
                return;
            m_bySlot[nSlot] = 0;
        }
    }
}

// @0x14185b4a0
// The exe moves the local into the return slot.
MS2Ptr<CItem> Unk_TradeItemTable::FUN_14185b4a0(__int64 uid)
{
    MS2Ptr<CItem> spItem;
    m_byUid.Lookup(uid, spItem);
    return spItem;
}

// @0x14185b520
void Unk_TradeItemTable::FUN_14185b520(ATL::CAtlArray<MS2Ptr<CItem> >& out)
{
    for (POSITION pos = m_byUid.GetHeadPosition(); pos != 0; m_byUid.GetNext(pos))
    {
        MS2Ptr<CItem> spItem(m_byUid.GetValueAt(pos));
        out.Add(spItem);
    }
}

// @0x14185b5c0
int Unk_TradeItemTable::FUN_14185b5c0()
{
    for (int i = 0; i < m_nSlots; i++)
    {
        MS2Ptr<CItem> spItem = m_bySlot[i];
        if (spItem == 0)
            return i;
    }
    return -1;
}

// ---- CTradeManagerEx ----
// @0x14185b780
CTradeManagerEx::CTradeManagerEx() : m_bConfirmed(false), m_uidPartner(0)
{
    DAT_143ab2e80.FUN_14185b1b0();
}

// @0x14185b810
CTradeManagerEx::~CTradeManagerEx()
{
}

// @0x14185b870
void CTradeManagerEx::SendTradeMode0(__int64 uid)
{
    COutPacket packet(static_cast<int>(SendOp::Trade), 0);
    packet.WriteUInt8(0);
    packet.WriteInt64(uid);
    FUN_140710590(packet);
}

// @0x14185b8e0
void CTradeManagerEx::FUN_14185b8e0(__int64 uid, int bAccept)
{
    COutPacket packet(static_cast<int>(SendOp::Trade), 0);
    packet.WriteUInt8(bAccept ? 3 : 4);
    packet.WriteInt64(uid);
    FUN_140710590(packet);
}

// @0x14185b970
void CTradeManagerEx::SendTradeMode7()
{
    COutPacket packet(static_cast<int>(SendOp::Trade), 0);
    packet.WriteUInt8(7);
    FUN_140710590(packet);
}

// @0x14185b9d0
void CTradeManagerEx::SendTradeMode8(__int64 uid, int a, int b)
{
    COutPacket packet(static_cast<int>(SendOp::Trade), 0);
    packet.WriteUInt8(8);
    packet.WriteInt64(uid);
    packet.WriteInt32(a);
    packet.WriteInt32(b);
    FUN_140710590(packet);
}

// @0x14185ba70
void CTradeManagerEx::SendTradeMode9(__int64 uid, int nSlot)
{
    COutPacket packet(static_cast<int>(SendOp::Trade), 0);
    packet.WriteUInt8(9);
    packet.WriteInt64(uid);
    packet.WriteInt32(nSlot);
    FUN_140710590(packet);
}

// @0x14185baf0
void CTradeManagerEx::SendTradeMode10(__int64 uid)
{
    if (uid == m_uidLastSent)
        return;
    COutPacket packet(static_cast<int>(SendOp::Trade), 0);
    packet.WriteUInt8(10);
    packet.WriteInt64(uid);
    FUN_140710590(packet);
    m_uidLastSent = uid;
}

// @0x14185bb80
void CTradeManagerEx::SendTradeMode11()
{
    COutPacket packet(static_cast<int>(SendOp::Trade), 0);
    packet.WriteUInt8(0xb);
    FUN_140710590(packet);
}

// @0x14185bbe0
void CTradeManagerEx::SendTradeMode13()
{
    COutPacket packet(static_cast<int>(SendOp::Trade), 0);
    packet.WriteUInt8(0xd);
    FUN_140710590(packet);
}

// @0x14185bc40
void CTradeManagerEx::SendTradeMode2(__int64 uid)
{
    COutPacket packet(static_cast<int>(SendOp::Trade), 0);
    packet.WriteUInt8(2);
    packet.WriteInt64(uid);
    FUN_140710590(packet);
}

// @0x14185bcb0
void CTradeManagerEx::SendTradeMode14(__int64 uid)
{
    COutPacket packet(static_cast<int>(SendOp::Trade), 0);
    packet.WriteUInt8(0xe);
    packet.WriteInt64(uid);
    FUN_140710590(packet);
}

// @0x14185bd20
void CTradeManagerEx::OnTrade(CInPacket& packet)
{
    int nCode = packet.ReadUInt8();
    switch (nCode)
    {
    case 0:
        FUN_14185bec0(packet);
        break;
    case 1:
        FUN_14185c2a0(packet);
        break;
    case 2:
        FUN_14185c230(packet);
        break;
    case 4:
        FUN_14185cc60(packet);
        break;
    case 5:
        FUN_14185cd10(packet);
        break;
    case 6:
        FUN_14185cee0(packet);
        break;
    case 8:
        FUN_14185d020(packet);
        break;
    case 9:
        FUN_14185d380(packet);
        break;
    case 10:
        FUN_14185d4f0(packet);
        break;
    case 11:
        FUN_14185d590(packet);
        break;
    case 12:
        FUN_14185d610(packet);
        break;
    case 13:
        FUN_14185d720(packet);
        break;
    case 14:
        FUN_14185d750(packet);
        break;
    }
}

// @0x14185bec0
void CTradeManagerEx::FUN_14185bec0(CInPacket& packet)
{
    CStringW strName = packet.ReadUnicodeString();
    __int64 uid = packet.ReadInt64();
    if (((struct Unk_TradeOptions*)&((class Unk_BuddyOptions*)(class Unk_TradeConfig*)(reinterpret_cast<Unk_TradeConfig*>(TSingleton<CGameOption>::GetInstance())))->GetSettings())->m_bRefuseTrade != 0)
    {
        TSingleton<CTradeManagerEx>::GetInstance()->FUN_14185b8e0(uid, 0);
        return;
    }
    {
        BlockPtr blocked = ((class CBlockManager*)FUN_140a6a830())->FindBlockedAction(0x20);
        if (blocked.get() != 0)
        {
            TSingleton<CTradeManagerEx>::GetInstance()->FUN_14185b8e0(uid, 0);
            CStringW strMsg = FUN_1401ca400(blocked, 0x20);
            FUN_1412751b0(strMsg, 0x12);
            return;
        }
    }
    Unk_MessageBoxPtr current = FUN_14151f820();
    if (TM_BOX(current).operator CMsgBoxData*() != 0)
    {
        SendTradeMode14(uid);
    }
    else
    {
        Unk_MessageBoxPtr box = FUN_140d73d20(1, FormatStringId<CStringW>(0x823, strName), 0, s_requestTradeEx);
        if (TM_BOX(box).operator CMsgBoxData*() != 0)
        {
            TM_BOX(box).operator->()->Append<__int64>(uid);
            TM_BOX(box).operator->()->SetTimer(FUN_14025a620((class Unk_ConstVal*)(reinterpret_cast<char*>(FUN_1401d3200()) + 0x3788)), 1, GetStringCommon(0x2b8));
            TM_BOX(box).operator->()->FUN_141a02460(true);
            TM_BOX(box).operator->()->FUN_141a02480(true);
            TM_BOX(box).operator->()->FUN_141a024a0(false);
            FUN_140d73c60(box);
            SendTradeMode2(uid);
        }
    }
}

// @0x14185c230
void CTradeManagerEx::FUN_14185c230(CInPacket& packet)
{
    FUN_141275260(0x822, 1, 1);
    CString strArg("");
    FUN_141276180(s_inviteSuccess, strArg);
}

// @0x14185c2a0
void CTradeManagerEx::FUN_14185c2a0(CInPacket& packet)
{
    Unk_TradeResult code = (Unk_TradeResult)packet.ReadUInt8();
    CStringW strName = packet.ReadUnicodeString();
    int nArg = packet.ReadInt32();
    unsigned short nLevel = (unsigned short)packet.ReadInt32();
    CStringW strMsg;
    switch ((int)code)
    {
    case 0:
        strMsg = FormatStringId<CStringW>(0x827, strName);
        break;
    case 0xc:
        strMsg = FormatStringId<CStringW>(0x829, strName);
        break;
    case 1:
        strMsg = FormatStringId<CStringW>(0x828, strName);
        break;
    case 2:
        strMsg = FormatStringId<CStringW>(0x82a, strName);
        break;
    case 3:
        strMsg = FormatStringId<CStringW>(0x82b, strName);
        break;
    case 5:
        strMsg = FormatStringId<CStringW>(0x82d, strName);
        break;
    case 6:
        strMsg = FormatStringId<CStringW>(0x82e, strName);
        break;
    case 0xe:
        strMsg = BlockFormat(0x82c);
        break;
    case 7:
        strMsg = BlockFormat(0x82f);
        break;
    case 8:
        strMsg = BlockFormat(0x830);
        break;
    case 9:
        strMsg = BlockFormat(0x831);
        break;
    case 10:
        strMsg = BlockFormat(0x832);
        break;
    case 0xb:
        strMsg = BlockFormat(0x833);
        break;
    case 0xd:
        strMsg = BlockFormat(0x834);
        break;
    case 0xf:
        strMsg = FormatStringId<CStringW>(0x835, strName);
        break;
    case 0x10:
        strMsg = FormatStringId<CStringW>(0x836, strName);
        break;
    case 0x11:
        break;
    case 0x12:
        strMsg = FUN_14028dfa0<unsigned short>(CStringW(L"s_trade_error_restricted_userlevel_max"), nLevel);
        break;
    case 0x13:
        strMsg = FUN_14028dfa0<unsigned short>(CStringW(L"s_trade_error_restricted_target_userlevel_max"), nLevel);
        break;
    case 0x14:
        strMsg = FUN_140a22c00(0x93f, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nArg), nLevel);
        break;
    case 0x15:
        strMsg = FUN_140a22c00(0x940, TSingleton<CStringTable>::GetInstance()->FUN_141811980(1, nArg), nLevel);
        break;
    default:
        strMsg = Unk_TradeFormat(0x837, code);
        break;
    }
    if (!strMsg.IsEmpty())
    {
        FUN_1412751b0(strMsg, 0x12);
        FUN_1412751f0(strMsg, 1, 0);
    }
    Unk_TradeDialog* pDlg = reinterpret_cast<Unk_TradeDialog*>(Unk_InvGetDialogById<UITradeDialogEx>(0x4e83));
    if (pDlg != 0)
        reinterpret_cast<UITradeDialogEx*>(pDlg)->FUN_141b297e0(code);
}

// @0x14185cc60
void CTradeManagerEx::FUN_14185cc60(CInPacket& packet)
{
    CStringW strName = packet.ReadUnicodeString();
    FUN_1412751b0(FormatStringId<CStringW>(0x824, strName), 0x12);
    Unk_AkoMessage<CStringW>(0x824, 1, 0, strName);
}

// @0x14185cd10
void CTradeManagerEx::FUN_14185cd10(CInPacket& packet)
{
    __int64 uid = packet.ReadInt64();
    PCBase* pPlayer = reinterpret_cast<PCBase*>(WorldService::GetInstance()->FUN_141bd1530(uid));
    if (pPlayer != 0)
    {
        FUN_14185d820(uid, pPlayer->vfunc_77(), reinterpret_cast<PC*>(pPlayer)->FUN_1416612e0());
        reinterpret_cast<CUIService*>(FUN_1403ed2b0())->CloseDialog((eUIClassID)0x4e3b);
        reinterpret_cast<CUIService*>(FUN_1403ed2b0())->CloseDialog((eUIClassID)0x4ec1);
        reinterpret_cast<CUIService*>(FUN_1403ed2b0())->CloseDialog((eUIClassID)0x4e47);
        m_uidLastSent = 0;
        ((CUIService*)FUN_1403ed2b0())->OpenDialog((eUIClassID)(0x4e83));
        FUN_1412751b0(FormatStringId<CStringW>(0x846, pPlayer->vfunc_77()), 0x12);
    }
}

// @0x14185cee0
void CTradeManagerEx::FUN_14185cee0(CInPacket& packet)
{
    int bAccepted = packet.ReadUInt8();
    Unk_TradeDialog* pDlg = reinterpret_cast<Unk_TradeDialog*>(Unk_InvGetDialogById<UITradeDialogEx>(0x4e83));
    if (pDlg != 0)
    {
        CStringW strPartner = pDlg->GetPartner();
        reinterpret_cast<CUIService*>(FUN_1403ed2b0())->CloseDialog((eUIClassID)0x4e83);
        if (bAccepted)
            FUN_1412751b0(FormatStringId<CStringW>(0x826, strPartner), 0x12);
        else
            FUN_1412751b0(FormatStringId<CStringW>(0x825, strPartner), 0x12);
    }
    m_uidLastSent = 0;
}

// @0x14185d020
void CTradeManagerEx::FUN_14185d020(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = reinterpret_cast<Unk_TradeDialog*>(Unk_InvGetDialogById<UITradeDialogEx>(0x4e83));
    if (pDlg == 0)
        return;
    int bMine = packet.ReadUInt8();
    int nTemplate = packet.ReadInt32();
    __int64 uid = packet.ReadInt64();
    int nRarity = packet.ReadInt32();
    int nCount = packet.ReadInt32();
    int nSlotInItem = packet.ReadInt32();
    int nSlot = packet.ReadInt32();
    MS2Ptr<CItem> spItem(new CItem);
    if (!spItem->FUN_140523c40(nTemplate, nRarity, 0))
    {
        pDlg->vfunc_67();
        return;
    }
    spItem->FUN_140524eb0(packet);
    spItem->SetItemUid(uid);
    spItem->SetCountClamped(nSlotInItem);
    spItem->FUN_140526b70(nCount);
    if (bMine)
    {
        ((class Unk_TradeInventory*)FUN_140a6a840())->vfunc_17(spItem);
        DAT_143ab2e80.FUN_14185b2a0(spItem);
    }
    reinterpret_cast<UITradeDialogEx*>(pDlg)->FUN_141b27de0(bMine, nSlot, spItem);
}

// @0x14185d380
void CTradeManagerEx::FUN_14185d380(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = reinterpret_cast<Unk_TradeDialog*>(Unk_InvGetDialogById<UITradeDialogEx>(0x4e83));
    if (pDlg == 0)
        return;
    int bMine = packet.ReadUInt8();
    int nSlot = packet.ReadInt32();
    __int64 uid = packet.ReadInt64();
    if (bMine)
    {
        MS2Ptr<CItem> spItem = DAT_143ab2e80.FUN_14185b4a0(uid);
        if (!spItem)
            return;
        ((class Unk_TradeInventory*)FUN_140a6a840())->vfunc_18(spItem);
        DAT_143ab2e80.FUN_14185b3d0(uid);
    }
    reinterpret_cast<UITradeDialogEx*>(pDlg)->FUN_141b27fa0(bMine, nSlot);
}

// @0x14185d4f0
void CTradeManagerEx::FUN_14185d4f0(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = reinterpret_cast<Unk_TradeDialog*>(Unk_InvGetDialogById<UITradeDialogEx>(0x4e83));
    if (pDlg == 0)
        return;
    int nSide = packet.ReadUInt8();
    __int64 nValue = packet.ReadInt64();
    reinterpret_cast<UITradeDialogEx*>(pDlg)->FUN_141b28130(nSide, nValue);
}

// @0x14185d590
void CTradeManagerEx::FUN_14185d590(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = reinterpret_cast<Unk_TradeDialog*>(Unk_InvGetDialogById<UITradeDialogEx>(0x4e83));
    if (pDlg == 0)
        return;
    int bMine = packet.ReadUInt8();
    if (bMine)
        m_bConfirmed = true;
    reinterpret_cast<UITradeDialogEx*>(pDlg)->FUN_141b28290(bMine, 1);
}

// @0x14185d610
void CTradeManagerEx::FUN_14185d610(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = reinterpret_cast<Unk_TradeDialog*>(Unk_InvGetDialogById<UITradeDialogEx>(0x4e83));
    if (pDlg == 0)
        return;
    int bMine = packet.ReadUInt8();
    if (bMine)
    {
        m_bConfirmed = false;
        FUN_1412751b0(GetStringCommon(0x844), 0x12);
    }
    else
    {
        FUN_1412751b0(GetStringCommon(0x845), 0x12);
    }
    reinterpret_cast<UITradeDialogEx*>(pDlg)->FUN_141b28290(bMine, 0);
}

// @0x14185d720
void CTradeManagerEx::FUN_14185d720(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = reinterpret_cast<Unk_TradeDialog*>(Unk_InvGetDialogById<UITradeDialogEx>(0x4e83));
}

// @0x14185d750
void CTradeManagerEx::FUN_14185d750(CInPacket& packet)
{
    FUN_1412751b0(GetStringCommon(0x843), 0x12);
}

// @0x14185d7b0
void CTradeManagerEx::FUN_14185d7b0()
{
    DAT_143ab2e80.FUN_14185b200();
    m_uidPartner = 0;
    m_strName = L"";
    m_strChar = "";
    FUN_14185dc90();
}

// @0x14185d820
void CTradeManagerEx::FUN_14185d820(__int64 uid, CStringW strName, CString strChar)
{
    FUN_14185d7b0();
    m_uidPartner = uid;
    m_strName = strName;
    m_strChar = strChar;
}

// @0x14185d8b0
int CTradeManagerEx::FUN_14185d8b0()
{
    if (reinterpret_cast<CUIService*>(FUN_1403ed2b0())->FUN_141adc940((eUIClassID)0x4e83) == 0)
    {
        FUN_140f8ff40(0x841, 1, 1);
        return 0;
    }
    if ((unsigned __int64)m_uidPartner > 0)
    {
        FUN_140f8ff40(0x841, 1, 1);
        return 0;
    }
    return 1;
}

// @0x14185d920
__int64 CTradeManagerEx::GetUidLastSent()
{
    return m_uidLastSent;
}

// @0x14185dc40
CStringW Unk_TradeDialog::GetPartner()
{
    return m_strPartner;
}

// @0x14185dc90
void CTradeManagerEx::FUN_14185dc90()
{
    m_bConfirmed = false;
}
// Atexit thunks of this unit's statics (gap2 yd sweep, yd2).
// MS2-RANGE: 0x142cbbf90-0x142cbc060 .text$yd
