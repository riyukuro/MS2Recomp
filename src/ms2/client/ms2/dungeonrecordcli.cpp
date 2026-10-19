// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's dungeon records: DungeonRecordCli (a
// DungeonRecord with the client-side counters: what is left today, the extra tickets, the bonus count) and the manager
// that owns them (DungeonRecordManagerCli: the room id -> record table, the rank reward table, the reward boost state,
// the packet handlers and the error notices), plus the container / MS2Ptr glue over them.
// MS2-UNIT: client\ms2\dungeonrecordcli.cpp
// MS2-GUESS-LOOKALIKES
// MS2-RANGE: 0x140b206b0-0x140b26ff0 .text$mn
// MS2-RANGE: 0x1400c7d40-0x1400c7e00 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??8?$MS2Ptr@VUnk_DungeonEvent@@@@QEBA_NPEAVUnk_DungeonEvent@@@Z 0x140b246a0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\dungeonrecordcli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/dungeonroom.h"
#include "ms2/client/ms2/dungeonrecordcli.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/client/ms2/uigamemenudialog.h"

// ---- unit-local stand-ins ----

// The message box data (0x2a0 bytes; the owner is unit_140d73aa0). Only the pointer type is used here, so its
// MS2Ptr members stay the exe's (declared, not instantiated).
class CMsgBoxData;
typedef Delegate<bool(int, const CMsgBoxData&)> Unk_MsgBoxCallback;
template <> MS2Ptr<CMsgBoxData>::~MS2Ptr();
typedef MS2Ptr<CMsgBoxData> Unk_MsgBoxPtr;

// The end-of-dungeon photo dialog (owner: uidungeonclosingphotodialog.cpp; its header cannot be combined with
// ms2ptr_impl.h, so only the handler is declared here).
class UIDungeonClosingPhotoDialog : public UIObject
{
public:
    void FUN_140e0eb40(CInPacket& packet);
};

// The game event that grants extra dungeon rewards (looked up by room id).
class Unk_DungeonEvent : public CPtred
{
public:
    unsigned m_pad_18[2];
    unsigned m_extraRewardCount;            // +0x20
};
typedef MS2Ptr<Unk_DungeonEvent> Unk_DungeonEventPtr;

struct Unk_GEManagerA
{
    Unk_DungeonEventPtr FUN_14047a5b0(unsigned nRoomID);
};
Unk_GEManagerA* FUN_1401c0d90();

class Unk_CommandStrings
{
public:
    CStringW FUN_141811980(int nType, int nId);
};
Unk_CommandStrings* FUN_1401a9d70();

// Free functions of the exe, bound by their FUN_<va> names.
__int64 FUN_140869440();
UIGameMenuDialog* FUN_140938b90(int nId);
CStringW FUN_14028b8e0(const CStringW& str);
void FUN_1412751f0(const CStringW& text, int nA, int nB);
void FUN_1412752d0(const CStringW& text, int nA);
CStringW FUN_140298ea0(CStringW str);
CStringW FUN_1405c2690(CStringW key, const CStringW& arg);
CStringW FUN_1409eec40(int nId);
CStringW FUN_14062b4f0(CStringW key, const int& nArg);
CStringW FUN_14052bd00(int nId, const CStringW& arg);
CStringW FUN_140b8e9a0(const CMsTime& t);
void FUN_140d73ff0(CStringW text);
void FUN_140d73aa0(CStringW text, int nType, void* p, CStringW tag);
Unk_MsgBoxPtr FUN_140d74390(CStringW text, int nType, Unk_MsgBoxCallback cb);
CInputStream& FUN_14070f480(CInputStream& in, int& n);
CInputStream& FUN_14070f4c0(CInputStream& in, __int64& n);
CInputStream& FUN_14070f500(CInputStream& in, unsigned __int64& n);
CInputStream& FUN_14070f540(CInputStream& in, float& f);
extern unsigned __int64 DAT_143ab2828;

// Methods of the commonfiles units (their link symbols are not in the committed table), bound by VA: this first.
class DungeonRoomTable;
bool FUN_14031b900(DungeonRecord* pThis);                       // DungeonRecord::IsSeasonRankRoom
int FUN_14031b9d0(DungeonRecord* pThis, __int64 tNow);          // DungeonRecord::GetClearCount
unsigned FUN_14031ba10(DungeonRecord* pThis);                   // DungeonRecord::GetSubRewardCount
unsigned FUN_14031ddd0(DungeonRoom* pThis);                     // DungeonRoom::GetDungeonRoomID
unsigned FUN_14031e110(DungeonRoom* pThis);                     // DungeonRoom::GetCouponBaseItemID
bool FUN_14031e190(DungeonRoom* pThis);                         // DungeonRoom::CanBuyCouponInMeratMarket
unsigned FUN_14031e2b0(DungeonRoom* pThis, unsigned nCount);    // DungeonRoom::GetExtraRewardTicketCost
struct Unk_DrcRoomTable { DungeonRoomPtr FUN_1403206b0(unsigned nRoomId); }; // DungeonRoomTable::GetRoom

// the empty callback of the message boxes (declared by unit_140d73aa0)
Unk_MsgBoxCallback FUN_140b240b0();

// the "the number of ... is in the order list" names (the .text$di initializer)
static CStringA s_orderNames[7] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

// ---- DungeonRecordCli ----

// @0x140b206b0
DungeonRecordCli::DungeonRecordCli()
{
}

// @0x140b206f0
DungeonRecordCli::DungeonRecordCli(unsigned nRoomID)
{
    m_dungeonRoomID = nRoomID;
    ResolveRoom();
}

// @0x140b20750
int DungeonRecordCli::GetBonusRewardCountNow()
{
    return GetBonusRewardCount(FUN_140869440());
}

// @0x140b20780
int DungeonRecordCli::GetMaxCount()
{
    if (m_pRoom == 0)
        return 0;
    if (IsExpired())
        return m_pRoom->m_rewardCount;
    return m_pRoom->m_rewardCount + m_bonusCount;
}

unsigned char FUN_140b24dc0(Unk_DungeonTimedValue<unsigned char>* p)
{
    return p->Get(FUN_140869440());
}

// @0x140b207f0
unsigned DungeonRecordCli::GetExtraCountNow()
{
    return FUN_140b24dc0(&m_extraCount);
}

// @0x140b20820
long DungeonRecordCli::Get5c()
{
    return m_5c;
}

// @0x140b20840
// MS2-FUNCTIONAL: return value is widened to int in the exe (xor eax,eax); the uchar ternary differs
unsigned char DungeonRecordCli::GetBonusCountNow()
{
    return IsExpired() ? 0 : m_bonusCount;
}

// @0x140b20880
__int64 DungeonRecordCli::GetExpire()
{
    return m_expire;
}

// @0x140b208a0
short DungeonRecordCli::Get60()
{
    return m_60;
}

// @0x140b208c0
unsigned short DungeonRecordCli::Get68(__int64 tNow)
{
    return m_68.Get(tNow);
}

// @0x140b208f0
bool DungeonRecordCli::HasCountLeft()
{
    if (IsExtraExhausted())
        return true;
    if (FUN_14031ba10(this) > 0)
    {
        if (FUN_14031b9d0(this, FUN_140869440()) >= FUN_14031ba10(this))
            return false;
    }
    return (unsigned)GetBonusRewardCountNow() < (unsigned)GetMaxCount();
}
#line 189

// @0x140b20990
bool DungeonRecordCli::IsExtraExhausted()
{
    Unk_DungeonEventPtr spEvent = FUN_1401c0d90()->FUN_14047a5b0(m_dungeonRoomID);
    if (spEvent == 0)
        return false;
    return GetExtraCountNow() < spEvent->m_extraRewardCount;
}

// @0x140b20a40
unsigned short DungeonRecordCli::GetRaw68()
{
    return m_68.value;
}

// @0x140b20a60
bool DungeonRecordCli::IsExpired()
{
    return FUN_140869440() >= m_expire;
}

// ---- DungeonRecordManagerCli ----

// @0x140b20aa0
DungeonRecordManagerCli::DungeonRecordManagerCli()
    : m_records(10), m_rewards(17, 0.75f, 0.25f, 2.25f, 10), m_90(0), m_98(0), m_a0(1.0f), m_a4(1.0f)
{
}

// @0x140b20b70
size_t DungeonRecordManagerCli::GetRecordCount()
{
    return m_records.GetCount();
}

// @0x140b20ba0
void DungeonRecordManagerCli::Clear()
{
    m_records.RemoveAll();
    m_rewards.RemoveAll();
}

// @0x140b20be0
// MS2-FUNCTIONAL: exe keeps the stream sub-object pointer in an extra temp (12 bytes longer)
void DungeonRecordManagerCli::OnPacket(CInPacket& packet)
{
    CInputStream& in = packet;
    switch (in.vfunc_o8_1())
    {
    case 5:
        OnRecords(packet);
        break;
    case 6:
        OnAddRecord(packet);
        break;
    case 7:
        OnRewardNotice(packet);
        break;
    case 10:
        OnClosingPhoto(packet);
        break;
    case 11:
        OnOpenDialog(packet);
        break;
    case 0x12:
        OnError(packet);
        break;
    case 0x13:
        OnRewards(packet);
        break;
    case 0x14:
        OnAddReward(packet);
        break;
    case 0x16:
        OnBoostState(packet);
        break;
    }
}

// reads a count and that many (room id, record) pairs
// @0x140b22f40
CInputStream& FUN_140b22f40(CInputStream& in, ATL::CRBMap<unsigned, DungeonRecordCliPtr>& map);
// @0x140b22ea0
CInputStream& FUN_140b22ea0(CInputStream& in, ATL::CAtlMap<unsigned, DungeonRankRewardPtr>& map);
CInputStream& FUN_140b22fe0(CInputStream& in, DungeonRankRewardPtr& spReward);
CInputStream& FUN_140b23070(CInputStream& in, DungeonRecordCliPtr& spRecord);

// @0x140b20d40
void DungeonRecordManagerCli::OnRecords(CInPacket& packet)
{
    m_records.RemoveAll();
    FUN_140b22f40(packet, m_records);
}

// @0x140b20d90
void DungeonRecordManagerCli::OnAddRecord(CInPacket& packet)
{
    DungeonRecordCliPtr spRecord(new DungeonRecordCli);
    packet >> *spRecord;
    m_records.SetAt(spRecord->GetDungeonRoomID(), spRecord);
    if (UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28))
        pMenu->FUN_141938ae0(0x4f1c, 0);
}

// @0x140b20e80
// MS2-FUNCTIONAL: CStringW temp slots / branch layout of the notice chain not matched
void DungeonRecordManagerCli::OnRewardNotice(CInPacket& packet)
{
    CInputStream& in = packet;
    unsigned char nKind = in.vfunc_o8_1();
    int nValue = in.vfunc_o8_3();
    if (nKind == 1)
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_room_dungeon_give_reward")), 1, 1);
    else if (nKind == 2)
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_room_dungeon_give_dungeonHelperReward")), 1, 1);
    else if (nKind == 3)
        FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_room_dungeon_reward_addExtraCount")), 1, 1);
    else if (nKind == 4)
        FUN_1412751f0(FUN_1405c2690(CStringW(L"s_room_dungeon_record_notify_change_expert"), FUN_1401a9d70()->FUN_141811980(0x14, nValue)), 1, 1);
}

// the end-of-dungeon photo dialog, if open
// @0x140b23100
UIDungeonClosingPhotoDialog* FUN_140b23100(int nId)
{
    if (CUIService::GetInstance())
    {
        MS2Ptr<UIObject> p = CUIService::GetInstance()->FUN_141adcea0((eUIClassID)nId);
        if (p.get())
            return dynamic_cast<UIDungeonClosingPhotoDialog*>((UIObject*)p);
    }
    return 0;
}

// @0x140b21150
void DungeonRecordManagerCli::OnClosingPhoto(CInPacket& packet)
{
    if (UIDungeonClosingPhotoDialog* pDlg = FUN_140b23100(0x4f19))
        pDlg->FUN_140e0eb40(packet);
}

// @0x140b21190
void DungeonRecordManagerCli::OnOpenDialog(CInPacket& packet)
{
    CUIService::GetInstance()->FUN_141adc530((eUIClassID)0x4ef9);
}

// @0x140b211c0
// MS2-FUNCTIONAL: temp slot order of the new record / MS2Ptr not matched
void DungeonRecordManagerCli::OnAddRecordExtra(CInPacket& packet)
{
    DungeonRecordCliPtr spRecord(new DungeonRecordCli);
    packet >> *spRecord;
    m_records.SetAt(spRecord->GetDungeonRoomID(), spRecord);
    FUN_1412751f0(FUN_14028b8e0(CStringW(L"s_room_dungeon_reward_addExtraCount")), 1, 1);
    if (UIGameMenuDialog* pMenu = FUN_140938b90(0x4e28))
        pMenu->FUN_141938ae0(0x4f1c, 0);
}

// @0x140b21310
// MS2-FUNCTIONAL: CStringW literal temps and message-box temp slots of the 33-way switch not matched
void DungeonRecordManagerCli::OnError(CInPacket& packet)
{
    CInputStream& in = packet;
    int nError = in.vfunc_o8_3();
    int nArg = in.vfunc_o8_3();
    switch (nError)
    {
    case 1:
        FUN_140d73ff0(CStringW(L"s_room_party_err_not_chief"));
        break;
    case 2:
        FUN_140d73ff0(CStringW(L"s_room_party_err_full_room"));
        break;
    case 3:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_error_invalidPartyOID"));
        break;
    case 4:
    {
        DungeonRoomPtr spRoom = reinterpret_cast<Unk_DrcRoomTable*>(DungeonRoomTable::GetInstance())->FUN_1403206b0((unsigned)nArg);
        if (!(spRoom == 0))
        {
            DungeonRecordCliPtr spRecord = GetRecord(FUN_14031ddd0(spRoom.operator->()));
            if (spRecord.get())
            {
                CMsTime tExpire(spRecord->GetExpire());
                FUN_140d73aa0(FUN_14052bd00(0x9a2, FUN_140b8e9a0(tExpire)), 0, 0, CStringW(L""));
            }
        }
        break;
    }
    case 5:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_reward_CantUseExtraReward"));
        break;
    case 6:
        ShowLackExtraTicket(nArg);
        break;
    case 7:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_max_reward_count"));
        break;
    case 8:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_expired"));
        break;
    case 9:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_commingSoon"));
        break;
    case 10:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_canEnterOnDungeonMatch"));
        break;
    case 0xb:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_canEnterTutorialField"));
        break;
    case 0xc:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_canEnterDayOfWeeks"));
        break;
    case 0xd:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_AlreadyChaosHall"));
        break;
    case 0xe:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_AlreadyLapentaHall"));
        break;
    case 0xf:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_AlreadyColosseumHall"));
        break;
    case 0x10:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_CantEnterInDungeon"));
        break;
    case 0x11:
        FUN_140d74390(FUN_14062b4f0(CStringW(L"s_room_dungeon_OverMaxUserCount"), nArg), 0, FUN_140b240b0());
        break;
    case 0x12:
        FUN_140d74390(FUN_14062b4f0(CStringW(L"s_room_dungeon_UnderMinUserCount"), nArg), 0, FUN_140b240b0());
        break;
    case 0x13:
        FUN_1412752d0(CStringW(L"s_room_dungeon_noRewardDayOfWeeks"), 1);
        break;
    case 0x14:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_HasNotLimitItem"));
        break;
    case 0x15:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_NotAllowTime"));
        break;
    case 0x16:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_CantUseAtDungeonRoom"));
        break;
    case 0x17:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_notOpenTimeDungeon"));
        break;
    case 0x18:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_cannot_giveup_yet"));
        break;
    case 0x19:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_require_guild_partry"));
        break;
    case 0x1a:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_require_guild_join_date"));
        break;
    case 0x1b:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_shutdown_find_dungeon_helper"));
        break;
    case 0x1c:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_is_not_open_period_date"));
        break;
    case 0x1d:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_is_not_open_period"));
        break;
    case 0x1e:
        FUN_140d73ff0(CStringW(L"s_room_dungeon_cant_enter_in_partymember"));
        break;
    case 0x1f:
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_room_dungeon_error_used_reset_united_reward")), 1, 1);
        break;
    case 0x20:
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_room_dungeon_error_still_have_united_reawrd")), 1, 1);
        break;
    case 0x21:
        FUN_1412751f0(FUN_140298ea0(CStringW(L"s_room_dungeon_error_shutdown_united_reawrd_reset")), 1, 1);
        break;
    default:
        MS2_ASSERT_AT(0x15c, 0);
        break;
    }
}

// @0x140b21f90
void DungeonRecordManagerCli::OnRewards(CInPacket& packet)
{
    m_rewards.RemoveAll();
    FUN_140b22ea0(packet, m_rewards);
}

// @0x140b21fe0
void DungeonRecordManagerCli::OnAddReward(CInPacket& packet)
{
    DungeonRankRewardPtr spReward(new DungeonRankReward);
    packet >> *spReward;
    m_rewards.SetAt(spReward->m_18, spReward);
}

// @0x140b220a0
void DungeonRecordManagerCli::OnBoostState(CInPacket& packet)
{
    FUN_14070f500(packet, m_90);
    FUN_14070f4c0(packet, m_98);
}

// @0x140b22100
void DungeonRecordManagerCli::OnRates(CInPacket& packet)
{
    FUN_14070f540(packet, m_a0);
    FUN_14070f540(packet, m_a4);
}

// @0x140b22160
// MS2-FUNCTIONAL: MS2Ptr return-copy temp order not matched
DungeonRecordCliPtr DungeonRecordManagerCli::GetRecord(unsigned nRoomID)
{
    DungeonRecordCliPtr spRecord;
    if (!m_records.Lookup(nRoomID, spRecord))
    {
        spRecord.AssignRaw(new DungeonRecordCli(nRoomID));
        m_records.SetAt(nRoomID, spRecord);
        return spRecord;
    }
    return spRecord;
}

// @0x140b22290
bool DungeonRecordManagerCli::CanEnter(unsigned nRoomID)
{
    DungeonRecordCliPtr spRecord = GetRecord(nRoomID);
    if (spRecord == 0)
        return false;
    return spRecord->HasCountLeft();
}

// @0x140b22320
// MS2-FUNCTIONAL: branch layout around the MS2Ptr dtor not matched
bool DungeonRecordManagerCli::HasProgress(unsigned nRoomID)
{
    DungeonRecordCliPtr spRecord = GetRecord(nRoomID);
    if (spRecord.get())
    {
        if (spRecord->GetBonusRewardCountNow() != 0)
            return true;
        if (spRecord->GetExtraCountNow() != 0)
            return true;
    }
    return false;
}

// @0x140b223d0
// MS2-FUNCTIONAL: branch layout around the MS2Ptr dtors not matched
bool DungeonRecordManagerCli::CanClaimHelperReward(unsigned nRoomID)
{
    if (WorldService::GetInstance()->FUN_141bd0cc0())
    {
        DungeonRoomPtr spRoom = reinterpret_cast<Unk_DrcRoomTable*>(DungeonRoomTable::GetInstance())->FUN_1403206b0(nRoomID);
        if (!(spRoom == 0))
        {
            if (spRoom->m_dungeonHelperRequireClearCount != 0)
            {
                DungeonRecordCliPtr spRecord = GetRecord(nRoomID);
                if (spRecord.get())
                {
                    if (spRoom->m_dungeonHelperRequireClearCount <= spRecord->Get5c())
                        return spRecord->TestFlag(0);
                }
            }
        }
    }
    return false;
}

// @0x140b22530
bool DungeonRecordManagerCli::IsBoostActive()
{
    if (DAT_143ab2828 != m_98)
        return false;
    __int64 tNow = FUN_140869440();
    return tNow < (__int64)m_90;
}

// @0x140b225a0
// MS2-FUNCTIONAL: exe returns without a temp after the MS2Ptr dtor (return slot layout)
bool DungeonRecordManagerCli::IsSeasonRoom(unsigned nRoomID)
{
    DungeonRecordCliPtr spRecord = GetRecord(nRoomID);
    if (spRecord.get())
        return spRecord->TestFlag(1);
    return false;
}

// @0x140b22620
float DungeonRecordManagerCli::GetRateA()
{
    return m_a0;
}

// @0x140b22640
float DungeonRecordManagerCli::GetRateB()
{
    return m_a4;
}

// @0x140b22660
short DungeonRecordManagerCli::GetRoomScore60(unsigned nRoomID)
{
    DungeonRecordCliPtr spRecord = GetRecord(nRoomID);
    if (spRecord == 0)
        return -1;
    return spRecord->Get60();
}

// @0x140b226f0
// MS2-FUNCTIONAL: branch layout / tNow temp order not matched
unsigned short DungeonRecordManagerCli::GetRoomScore68(unsigned nRoomID)
{
    DungeonRecordCliPtr spRecord = GetRecord(nRoomID);
    if (spRecord.get() == 0)
        return 0;
    return spRecord->Get68(FUN_140869440());
}

// @0x140b22780
// MS2-FUNCTIONAL: loop temp slots not matched
int DungeonRecordManagerCli::GetTotalScore()
{
    int nTotal = 0;
    for (POSITION pos = m_records.GetHeadPosition(); pos != 0; m_records.GetNext(pos))
    {
        DungeonRecordCliPtr spRecord = m_records.GetValueAt(pos);
        if (FUN_14031b900(spRecord.operator->()))
        {
            __int64 tNow = FUN_140869440();
            short nScore = spRecord->Get68(tNow);
            if (nScore > 0)
                nTotal += nScore;
        }
    }
    return nTotal;
}

// @0x140b22890
// MS2-FUNCTIONAL: exe returns without a temp after the MS2Ptr dtor (return slot layout)
long DungeonRecordManagerCli::GetRoomValue5c(unsigned nRoomID)
{
    DungeonRecordCliPtr spRecord = GetRecord(nRoomID);
    if (spRecord.get() == 0)
        return 0;
    return spRecord->Get5c();
}

// @0x140b22910
int DungeonRecordManagerCli::GetRankRewardCount(unsigned nRank)
{
    DungeonRankRewardPtr spReward;
    if (m_rewards.Lookup(nRank, spReward))
    {
        if (FUN_140869440() < spReward->m_20)
            return spReward->m_1c;
    }
    return 0;
}

// @0x140b229c0
// MS2-FUNCTIONAL: loop temp slots not matched
void DungeonRecordManagerCli::GetScoredRecords(std::vector<DungeonRecordCliPtr>& out)
{
    __int64 tNow = FUN_140869440();
    for (POSITION pos = m_records.GetHeadPosition(); pos != 0; m_records.GetNext(pos))
    {
        DungeonRecordCliPtr spRecord = m_records.GetValueAt(pos);
        if (spRecord->Get68(tNow) > 0)
            out.push_back(spRecord);
    }
}

// @0x140b22aa0
// MS2-FUNCTIONAL: by-value MS2Ptr param / return temp layout not matched
unsigned DungeonRecordManagerCli::GetExtraTicketCost(DungeonRoomPtr pRoom)
{
    if (pRoom == 0)
        return 0;
    return FUN_14031e2b0(pRoom.operator->(), GetRoomBonusCount(FUN_14031ddd0(pRoom.operator->())));
}

// @0x140b22b40
// MS2-FUNCTIONAL: exe returns without a temp after the MS2Ptr dtor (return slot layout)
unsigned char DungeonRecordManagerCli::GetRoomBonusCount(unsigned nRoomID)
{
    DungeonRecordCliPtr spRecord = GetRecord(nRoomID);
    if (spRecord.get() == 0)
        return 0;
    return spRecord->GetBonusCountNow();
}

// @0x140b22bc0
void DungeonRecordManagerCli::GetSeasonRooms(std::vector<DungeonRoomPtr>& out)
{
    for (POSITION pos = m_records.GetHeadPosition(); pos != 0; m_records.GetNext(pos))
    {
        DungeonRecordCliPtr spRecord = m_records.GetValueAt(pos);
        if (spRecord->TestFlag(1))
            out.push_back(spRecord->GetRoom());
    }
}

// @0x140b22cb0
// MS2-FUNCTIONAL: CStringW temp slots not matched
void DungeonRecordManagerCli::ShowLackExtraTicket(unsigned nRoomID)
{
    DungeonRoomPtr spRoom = reinterpret_cast<Unk_DrcRoomTable*>(DungeonRoomTable::GetInstance())->FUN_1403206b0(nRoomID);
    if (!(spRoom == 0))
    {
        if (!FUN_14031e190(spRoom.operator->()))
        {
            FUN_1412751f0(FUN_1409eec40(0x31), 1, 1);
        }
        else
        {
            unsigned nItemID = FUN_14031e110(spRoom.operator->());
            CStringW strItem = FUN_1401a9d70()->FUN_141811980(1, nItemID);
            CStringW strText = FUN_1405c2690(CStringW(L"s_dungeonRoom_lack_extra_ticket"), strItem);
            CUIService::GetInstance()->FUN_141add520(CStringW(strText), CStringW(strItem));
        }
    }
}

// @0x140b22ea0
CInputStream& FUN_140b22ea0(CInputStream& in, ATL::CAtlMap<unsigned, DungeonRankRewardPtr>& map)
{
    unsigned nCount = in.vfunc_o8_3();
    for (int i = 0; i < nCount; ++i)
    {
        DungeonRankRewardPtr spReward;
        int nKey;
        FUN_140b22fe0(FUN_14070f480(in, nKey), spReward);
        map.SetAt(nKey, spReward);
    }
    return in;
}

// @0x140b22f40
CInputStream& FUN_140b22f40(CInputStream& in, ATL::CRBMap<unsigned, DungeonRecordCliPtr>& map)
{
    unsigned nCount = in.vfunc_o8_3();
    for (int i = 0; i < nCount; ++i)
    {
        DungeonRecordCliPtr spRecord;
        int nKey;
        FUN_140b23070(FUN_14070f480(in, nKey), spRecord);
        map.SetAt(nKey, spRecord);
    }
    return in;
}

// @0x140b22fe0
CInputStream& FUN_140b22fe0(CInputStream& in, DungeonRankRewardPtr& spReward)
{
    spReward.AssignRaw(new DungeonRankReward);
    in >> *spReward;
    return in;
}

// @0x140b23070
CInputStream& FUN_140b23070(CInputStream& in, DungeonRecordCliPtr& spRecord)
{
    spRecord.AssignRaw(new DungeonRecordCli);
    in >> *spRecord;
    return in;
}

// @0x140b240b0
// MS2-FUNCTIONAL: hidden-return Delegate init differs
Unk_MsgBoxCallback FUN_140b240b0()
{
    return Unk_MsgBoxCallback();
}
