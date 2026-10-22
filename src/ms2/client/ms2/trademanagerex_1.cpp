// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CTradeManagerEx: the player-to-player trade manager (first of
// the three consecutive trademanagerex.cpp objs; the exe unit ?\trademanagerex.cpp was split in the queue).
// MS2-UNIT: ?\trademanagerex.cpp#1
// MS2-RANGE: 0x14185b1b0-0x14185dca0 .text$mn
// MS2-RANGE: 0x14010e4a0-0x14010e670 .text$di
// MS2-PIN: ??0?$TSingleton@VCTradeManagerEx@@@@QEAA@XZ 0x14185db70
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??_GCTradeManagerEx@@UEAAPEAXI@Z 0x14185dc00 ; prop
// MS2-PINS-END tplpin
// MS2-PIN: memmove_s 0x14185b660
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

// ---- out-of-unit callees ----

// Client options (+8: refuse trade requests).
struct Unk_TradeOptions
{
    __int64 m_pad_00;
    bool m_bRefuseTrade;
};
class Unk_TradeConfig;
Unk_TradeConfig* FUN_1409a8b10();
Unk_TradeOptions* FUN_140ae6540(Unk_TradeConfig*);

// The trade window (UI id 0x4e83): +0x1a0 is the partner's name.
class Unk_TradeDialog : public UIDialog
{
public:
    CStringW FUN_14185dc40();                           // m_strPartner (this unit)
    void FUN_141b27de0(bool bMine, int nSlot, MS2Ptr<CItem> spItem);    // an item was put on the table
    void FUN_141b27fa0(bool bMine, int nSlot);          // an item was taken off
    void FUN_141b28130(unsigned char a, __int64 value); // a money amount changed
    void FUN_141b28290(bool bConfirmed, int bFinal);    // confirm state changed
    void FUN_141b297e0(int nResult);                    // request result
    char m_pad_178[0x28];
    CStringW m_strPartner;                              // +0x1a0
};
MS2_CHECK_OFFSET(Unk_TradeDialog, m_strPartner, 0x1a0);
Unk_TradeDialog* FUN_14140e820(int nUiId);              // the open UI with this id, 0 if none

// UI manager (FUN_1403ed2b0).
class Unk_TradeUIManager
{
public:
    void FUN_141adc530(int nUiId);                      // open
    void FUN_141adc5d0(int nUiId);                      // close
    int FUN_141adc940(int nUiId);                       // is open
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
Unk_TradeInventory* FUN_140a6a840();

class Unk_TradeWorld
{
public:
    PCBase* FUN_141bd1530(__int64 uid);                 // find a player by id
};
Unk_TradeWorld* FUN_1403ed2d0();

class Unk_TradeText
{
public:
    CStringW FUN_141811980(int a, int nId);
};
Unk_TradeText* FUN_1401a9d70();

struct Unk_TmPlayerView { CString FUN_1416612e0(); };   // the player's account/character name (PCBase member: this=rcx, hidden return=rdx)
CBlockManager* FUN_140a6a830();
CStringW FUN_1401ca400(const BlockPtr& record, int action);
Unk_MessageBoxPtr FUN_14151f820();
Unk_MessageBoxPtr FUN_140d73d20(int, CStringW, void*, CStringW);
void FUN_140d73c60(Unk_MessageBoxPtr);
void* FUN_140534fc0(const Unk_MessageBoxPtr&);
void* FUN_140534fe0(const Unk_MessageBoxPtr&);
void FUN_1405340b0(void*, __int64);
void FUN_141a01ca0(void*, int, int, const CStringW&);
void FUN_141a02460(void*, bool);
void FUN_141a02480(void*, bool);
void FUN_141a024a0(void*, bool);
int FUN_14025a620(void*);
void* FUN_1401d3200();
CStringW FUN_14028de60(int id);
CStringW FUN_14052bd00(int id, const CStringW& arg);
CStringW FUN_1409eec40(int id);
CStringW FUN_1409e8820(CStringW key, const unsigned short& n);
CStringW FUN_140a22c00(int id, const CStringW& a, const unsigned short& n);
void FUN_1412751b0(const CStringW& text, int channel);
void FUN_1412751f0(const CStringW& text, int a, int b);
void FUN_141275260(int stringId, int a, int b);
void FUN_141276180(const CString& strSound, const CString& strArg);
void FUN_140961010(int, int, int, const CStringW&);
void FUN_140f8ff40(int, int, int);
void FUN_140710590(COutPacket& packet);

// The string table entry formatter with one enum argument: FMT_VARIADIC_W instance (0x14185d960).
enum Unk_TradeResult : unsigned int {};
CStringW Unk_TradeFormat(int, const fmt::ArgList&);
FMT_VARIADIC_W(CStringW, Unk_TradeFormat, int)

// ---- statics (.text$di) ----
static CStringW s_requestTradeEx(L"requestTradeEx");
#include "ms2/placeholder/header_statics_a.h"     // sort names, skill/stun, the condition table (Unk_1402a9d70: ctor 0x1402a9d70)
static CString s_inviteSuccess("PC_InviteSuccess");

CTradeManagerEx* TSingleton<CTradeManagerEx>::s_instance = 0;
inline TSingleton<CTradeManagerEx>::TSingleton() { s_instance = static_cast<CTradeManagerEx*>(this); }

MS2_EMIT_CRT_MEMMOVE_S();

// ---- Unk_TradeItemTable ----
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
    if (m_byUid.Lookup(pItem->FUN_140526a50()) != 0)
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
        m_byUid.SetAt(pItem->FUN_140526a50(), spItem);
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
// MS2-FUNCTIONAL: the exe moves the local into the return slot (shared MS2Ptr has no move ctor); this builds the return value from the raw pointer
MS2Ptr<CItem> Unk_TradeItemTable::FUN_14185b4a0(__int64 uid)
{
    MS2Ptr<CItem> spItem;
    m_byUid.Lookup(uid, spItem);
    return MS2Ptr<CItem>(spItem.get());
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
void CTradeManagerEx::FUN_14185b870(__int64 uid)
{
    COutPacket packet(0x49, 0);
    packet.vfunc_o10_1(0);
    packet.vfunc_o10_4(uid);
    FUN_140710590(packet);
}

// @0x14185b8e0
void CTradeManagerEx::FUN_14185b8e0(__int64 uid, int bAccept)
{
    COutPacket packet(0x49, 0);
    packet.vfunc_o10_1(bAccept ? 3 : 4);
    packet.vfunc_o10_4(uid);
    FUN_140710590(packet);
}

// @0x14185b970
void CTradeManagerEx::FUN_14185b970()
{
    COutPacket packet(0x49, 0);
    packet.vfunc_o10_1(7);
    FUN_140710590(packet);
}

// @0x14185b9d0
void CTradeManagerEx::FUN_14185b9d0(__int64 uid, int a, int b)
{
    COutPacket packet(0x49, 0);
    packet.vfunc_o10_1(8);
    packet.vfunc_o10_4(uid);
    packet.vfunc_o10_3(a);
    packet.vfunc_o10_3(b);
    FUN_140710590(packet);
}

// @0x14185ba70
void CTradeManagerEx::FUN_14185ba70(__int64 uid, int nSlot)
{
    COutPacket packet(0x49, 0);
    packet.vfunc_o10_1(9);
    packet.vfunc_o10_4(uid);
    packet.vfunc_o10_3(nSlot);
    FUN_140710590(packet);
}

// @0x14185baf0
void CTradeManagerEx::FUN_14185baf0(__int64 uid)
{
    if (uid == m_uidLastSent)
        return;
    COutPacket packet(0x49, 0);
    packet.vfunc_o10_1(10);
    packet.vfunc_o10_4(uid);
    FUN_140710590(packet);
    m_uidLastSent = uid;
}

// @0x14185bb80
void CTradeManagerEx::FUN_14185bb80()
{
    COutPacket packet(0x49, 0);
    packet.vfunc_o10_1(0xb);
    FUN_140710590(packet);
}

// @0x14185bbe0
void CTradeManagerEx::FUN_14185bbe0()
{
    COutPacket packet(0x49, 0);
    packet.vfunc_o10_1(0xd);
    FUN_140710590(packet);
}

// @0x14185bc40
void CTradeManagerEx::FUN_14185bc40(__int64 uid)
{
    COutPacket packet(0x49, 0);
    packet.vfunc_o10_1(2);
    packet.vfunc_o10_4(uid);
    FUN_140710590(packet);
}

// @0x14185bcb0
void CTradeManagerEx::FUN_14185bcb0(__int64 uid)
{
    COutPacket packet(0x49, 0);
    packet.vfunc_o10_1(0xe);
    packet.vfunc_o10_4(uid);
    FUN_140710590(packet);
}

// @0x14185bd20
void CTradeManagerEx::OnTrade(CInPacket& packet)
{
    switch (packet.vfunc_o8_1())
    {
    case 0:
        FUN_14185bec0(packet);
        break;
    case 1:
        FUN_14185c2a0(packet);
        break;
    case 2:
        FUN_14185c230();
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
        FUN_14185d720();
        break;
    case 14:
        FUN_14185d750();
        break;
    }
}

// @0x14185bec0
void CTradeManagerEx::FUN_14185bec0(CInPacket& packet)
{
    CStringW strName = packet.vfunc_o8_8();
    __int64 uid = packet.vfunc_o8_4();
    if (FUN_140ae6540(FUN_1409a8b10())->m_bRefuseTrade == 0)
    {
        BlockPtr blocked = FUN_140a6a830()->FindBlockedAction(0x20);
        if (blocked.get() == 0)
        {
            blocked = 0;
            Unk_MessageBoxPtr current = FUN_14151f820();
            if (FUN_140534fc0(current) == 0)
            {
                Unk_MessageBoxPtr box = FUN_140d73d20(1, FUN_14052bd00(0x823, strName), 0, s_requestTradeEx);
                if (FUN_140534fc0(box) != 0)
                {
                    FUN_1405340b0(FUN_140534fe0(box), uid);
                    FUN_141a01ca0(FUN_140534fe0(box), FUN_14025a620(reinterpret_cast<char*>(FUN_1401d3200()) + 0x3788), 1, FUN_14028de60(0x2b8));
                    FUN_141a02460(FUN_140534fe0(box), true);
                    FUN_141a02480(FUN_140534fe0(box), true);
                    FUN_141a024a0(FUN_140534fe0(box), false);
                    FUN_140d73c60(box);
                    FUN_14185bc40(uid);
                }
            }
            else
            {
                FUN_14185bcb0(uid);
            }
        }
        else
        {
            FUN_14140ea30()->FUN_14185b8e0(uid, 0);
            FUN_1412751b0(FUN_1401ca400(blocked, 0x20), 0x12);
        }
    }
    else
    {
        FUN_14140ea30()->FUN_14185b8e0(uid, 0);
    }
}

// @0x14185c230
void CTradeManagerEx::FUN_14185c230()
{
    FUN_141275260(0x822, 1, 1);
    FUN_141276180(s_inviteSuccess, CString(""));
}

// @0x14185c2a0
void CTradeManagerEx::FUN_14185c2a0(CInPacket& packet)
{
    Unk_TradeResult code = (Unk_TradeResult)packet.vfunc_o8_1();
    CStringW strName = packet.vfunc_o8_8();
    int nArg = packet.vfunc_o8_3();
    unsigned short nLevel = (unsigned short)packet.vfunc_o8_3();
    CStringW strMsg;
    switch ((int)code)
    {
    case 0:
        strMsg = FUN_14052bd00(0x827, strName);
        break;
    case 1:
        strMsg = FUN_14052bd00(0x828, strName);
        break;
    case 2:
        strMsg = FUN_14052bd00(0x82a, strName);
        break;
    case 3:
        strMsg = FUN_14052bd00(0x82b, strName);
        break;
    default:
        strMsg = Unk_TradeFormat(0x837, code);
        break;
    case 5:
        strMsg = FUN_14052bd00(0x82d, strName);
        break;
    case 6:
        strMsg = FUN_14052bd00(0x82e, strName);
        break;
    case 7:
        strMsg = FUN_1409eec40(0x82f);
        break;
    case 8:
        strMsg = FUN_1409eec40(0x830);
        break;
    case 9:
        strMsg = FUN_1409eec40(0x831);
        break;
    case 10:
        strMsg = FUN_1409eec40(0x832);
        break;
    case 0xb:
        strMsg = FUN_1409eec40(0x833);
        break;
    case 0xc:
        strMsg = FUN_14052bd00(0x829, strName);
        break;
    case 0xd:
        strMsg = FUN_1409eec40(0x834);
        break;
    case 0xe:
        strMsg = FUN_1409eec40(0x82c);
        break;
    case 0xf:
        strMsg = FUN_14052bd00(0x835, strName);
        break;
    case 0x10:
        strMsg = FUN_14052bd00(0x836, strName);
        break;
    case 0x11:
        break;
    case 0x12:
        strMsg = FUN_1409e8820(CStringW(L"s_trade_error_restricted_userlevel_max"), nLevel);
        break;
    case 0x13:
        strMsg = FUN_1409e8820(CStringW(L"s_trade_error_restricted_target_userlevel_max"), nLevel);
        break;
    case 0x14:
        strMsg = FUN_140a22c00(0x93f, FUN_1401a9d70()->FUN_141811980(1, nArg), nLevel);
        break;
    case 0x15:
        strMsg = FUN_140a22c00(0x940, FUN_1401a9d70()->FUN_141811980(1, nArg), nLevel);
        break;
    }
    if (!strMsg.IsEmpty())
    {
        FUN_1412751b0(strMsg, 0x12);
        FUN_1412751f0(strMsg, 1, 0);
    }
    Unk_TradeDialog* pDlg = FUN_14140e820(0x4e83);
    if (pDlg != 0)
        pDlg->FUN_141b297e0(code);
}

// @0x14185cc60
void CTradeManagerEx::FUN_14185cc60(CInPacket& packet)
{
    CStringW strName = packet.vfunc_o8_8();
    FUN_1412751b0(FUN_14052bd00(0x824, strName), 0x12);
    FUN_140961010(0x824, 1, 0, strName);
}

// @0x14185cd10
void CTradeManagerEx::FUN_14185cd10(CInPacket& packet)
{
    __int64 uid = packet.vfunc_o8_4();
    PCBase* pPlayer = FUN_1403ed2d0()->FUN_141bd1530(uid);
    if (pPlayer != 0)
    {
        FUN_14185d820(uid, pPlayer->vfunc_77(), reinterpret_cast<Unk_TmPlayerView*>(pPlayer)->FUN_1416612e0());
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e3b);
        FUN_1403ed2b0()->FUN_141adc5d0(0x4ec1);
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e47);
        m_uidLastSent = 0;
        FUN_1403ed2b0()->FUN_141adc530(0x4e83);
        FUN_1412751b0(FUN_14052bd00(0x846, pPlayer->vfunc_77()), 0x12);
    }
}

// @0x14185cee0
void CTradeManagerEx::FUN_14185cee0(CInPacket& packet)
{
    bool bAccepted = packet.vfunc_o8_1() != 0;
    Unk_TradeDialog* pDlg = FUN_14140e820(0x4e83);
    if (pDlg != 0)
    {
        CStringW strPartner = pDlg->FUN_14185dc40();
        FUN_1403ed2b0()->FUN_141adc5d0(0x4e83);
        if (!bAccepted)
            FUN_1412751b0(FUN_14052bd00(0x825, strPartner), 0x12);
        else
            FUN_1412751b0(FUN_14052bd00(0x826, strPartner), 0x12);
    }
    m_uidLastSent = 0;
}

// @0x14185d020
void CTradeManagerEx::FUN_14185d020(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = FUN_14140e820(0x4e83);
    if (pDlg != 0)
    {
        bool bMine = packet.vfunc_o8_1() != 0;
        int nTemplate = packet.vfunc_o8_3();
        __int64 uid = packet.vfunc_o8_4();
        int nRarity = packet.vfunc_o8_3();
        int nCount = packet.vfunc_o8_3();
        int nSlotInItem = packet.vfunc_o8_3();
        int nSlot = packet.vfunc_o8_3();
        MS2Ptr<CItem> spItem(new CItem);
        if (spItem->FUN_140523c40(nTemplate, nRarity, 0))
        {
            spItem->FUN_140524eb0(packet);
            spItem->FUN_140526a70(uid);
            spItem->FUN_140526c70(nSlotInItem);
            spItem->FUN_140526b70(nCount);
            if (bMine)
            {
                FUN_140a6a840()->vfunc_17(spItem);
                DAT_143ab2e80.FUN_14185b2a0(spItem);
            }
            pDlg->FUN_141b27de0(bMine, nSlot, spItem);
        }
        else
        {
            pDlg->vfunc_67();
        }
    }
}

// @0x14185d380
void CTradeManagerEx::FUN_14185d380(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = FUN_14140e820(0x4e83);
    if (pDlg != 0)
    {
        bool bMine = packet.vfunc_o8_1() != 0;
        int nSlot = packet.vfunc_o8_3();
        __int64 uid = packet.vfunc_o8_4();
        if (bMine)
        {
            MS2Ptr<CItem> spItem = DAT_143ab2e80.FUN_14185b4a0(uid);
            if (!spItem.get())
                return;
            FUN_140a6a840()->vfunc_18(spItem);
            DAT_143ab2e80.FUN_14185b3d0(uid);
        }
        pDlg->FUN_141b27fa0(bMine, nSlot);
    }
}

// @0x14185d4f0
void CTradeManagerEx::FUN_14185d4f0(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = FUN_14140e820(0x4e83);
    if (pDlg != 0)
    {
        unsigned char nSide = packet.vfunc_o8_1();
        __int64 nValue = packet.vfunc_o8_4();
        pDlg->FUN_141b28130(nSide, nValue);
    }
}

// @0x14185d590
void CTradeManagerEx::FUN_14185d590(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = FUN_14140e820(0x4e83);
    if (pDlg != 0)
    {
        bool bMine = packet.vfunc_o8_1() != 0;
        if (bMine)
            m_bConfirmed = true;
        pDlg->FUN_141b28290(bMine, 1);
    }
}

// @0x14185d610
void CTradeManagerEx::FUN_14185d610(CInPacket& packet)
{
    Unk_TradeDialog* pDlg = FUN_14140e820(0x4e83);
    if (pDlg != 0)
    {
        bool bMine = packet.vfunc_o8_1() != 0;
        if (!bMine)
        {
            FUN_1412751b0(FUN_14028de60(0x845), 0x12);
        }
        else
        {
            m_bConfirmed = false;
            FUN_1412751b0(FUN_14028de60(0x844), 0x12);
        }
        pDlg->FUN_141b28290(bMine, 0);
    }
}

// @0x14185d720
void CTradeManagerEx::FUN_14185d720()
{
    FUN_14140e820(0x4e83);
}

// @0x14185d750
void CTradeManagerEx::FUN_14185d750()
{
    FUN_1412751b0(FUN_14028de60(0x843), 0x12);
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
bool CTradeManagerEx::FUN_14185d8b0()
{
    if (FUN_1403ed2b0()->FUN_141adc940(0x4e83) == 0)
    {
        FUN_140f8ff40(0x841, 1, 1);
        return false;
    }
    else if (m_uidPartner == 0)
    {
        return true;
    }
    else
    {
        FUN_140f8ff40(0x841, 1, 1);
        return false;
    }
}

// @0x14185d920
__int64 CTradeManagerEx::FUN_14185d920()
{
    return m_uidLastSent;
}

// @0x14185dc40
CStringW Unk_TradeDialog::FUN_14185dc40()
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
