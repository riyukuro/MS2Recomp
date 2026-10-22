// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). DungeonRecord / DungeonRankReward: a character's per-room
// dungeon record and rank reward, read from and written to packets.
// MS2-UNIT: commonfiles\dungeonrecord.cpp
// MS2-RANGE: 0x14031b800-0x14031c510 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??1DungeonRankReward@@UEAA@XZ 0x14031c120 ; prop
// MS2-PIN: ??1DungeonRecord@@UEAA@XZ 0x14031c140 ; prop
// MS2-PIN: ??_GDungeonRankReward@@UEAAPEAXI@Z 0x14031c170 ; unique
// MS2-PIN: ??_GDungeonRecord@@UEAAPEAXI@Z 0x14031c1b0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\dungeonrecord.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "dungeonrecord.h"
#include "dungeonroom.h"
#include "stream.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The packet stream operators (commonfiles\packet.cpp).
CInputStream& FUN_14070f340(CInputStream& in, unsigned char& value);
CInputStream& FUN_14070f3c0(CInputStream& in, unsigned short& value);
CInputStream& FUN_14070f3c0(CInputStream& in, short& value);
CInputStream& FUN_14070f440(CInputStream& in, long& value);
CInputStream& FUN_14070f480(CInputStream& in, unsigned& value);
CInputStream& FUN_14070f500(CInputStream& in, __int64& value);
COutputStream& FUN_14070f860(COutputStream& out, unsigned char value);
COutputStream& FUN_14070f8e0(COutputStream& out, unsigned short value);
COutputStream& FUN_14070f960(COutputStream& out, long value);
COutputStream& FUN_14070f9a0(COutputStream& out, unsigned value);
COutputStream& FUN_14070fa20(COutputStream& out, __int64 value);

// The bitset stream helpers (bitset.inl: one byte per 8 bits).
// @0x14031c1f0
inline void ReadBits(Unk_PartyBits& bits, CInputStream& in)
{
    for (int i = 0; i < 1; i++)
        bits.m_bits[i] = in.ReadUInt8();
}
// @0x14031c240
inline void WriteBits(Unk_PartyBits& bits, COutputStream& out)
{
    for (int i = 0; i < 1; i++)
        out.WriteUInt8(bits.m_bits[i]);
}
// @0x14031bf10
inline CInputStream& operator>>(CInputStream& in, Unk_PartyBits& bits)
{
    ReadBits(bits, in);
    return in;
}
// @0x14031bf40
inline CInputStream& operator>>(CInputStream& in, Unk_DungeonTimedValue<unsigned char>& v)
{
    FUN_14070f340(in, v.value);
    FUN_14070f500(in, v.expire);
    return in;
}
// @0x14031bf80
inline CInputStream& operator>>(CInputStream& in, Unk_DungeonTimedValue<unsigned short>& v)
{
    FUN_14070f3c0(in, v.value);
    FUN_14070f500(in, v.expire);
    return in;
}
// @0x14031bfc0
inline COutputStream& operator<<(COutputStream& out, Unk_PartyBits& bits)
{
    WriteBits(bits, out);
    return out;
}
// @0x14031bff0
inline COutputStream& operator<<(COutputStream& out, Unk_DungeonTimedValue<unsigned char>& v)
{
    FUN_14070f860(out, v.value);
    FUN_14070fa20(out, v.expire);
    return out;
}
// @0x14031c030
inline COutputStream& operator<<(COutputStream& out, Unk_DungeonTimedValue<unsigned short>& v)
{
    FUN_14070f8e0(out, v.value);
    FUN_14070fa20(out, v.expire);
    return out;
}

// @0x14031b800
DungeonRecord::DungeonRecord()
    : m_dungeonRoomID(0), m_expire(0), m_bonusRewardCount(0), m_bonusCount(0), m_usedBonusCount(0), m_5c(0), m_60(-1),
      m_68(0), m_pRoom(0)
{
}

// @0x14031b8e0
unsigned DungeonRecord::GetDungeonRoomID()
{
    return m_dungeonRoomID;
}
MS2_REPLACE_METHOD(0x14031B8E0, DungeonRecord, GetDungeonRoomID, 14, 0x72E52537);

// @0x14031b900
bool DungeonRecord::IsSeasonRankRoom()
{
    if (!m_pRoom)
        return false;
    return m_pRoom->IsSeasonRankRoom();
}
MS2_REPLACE_METHOD(0x14031B900, DungeonRecord, IsSeasonRankRoom, 50, 0xA138B2DE);

// @0x14031b940
bool DungeonRecord::TestFlag(int nBit)
{
    return m_flags.FUN_1402e4ee0(nBit);
}
MS2_REPLACE_METHOD(0x14031B940, DungeonRecord, TestFlag, 39, 0x6B1143BA);

// @0x14031b970
unsigned char DungeonRecord::IsAccountReward()
{
    if (!m_pRoom)
        return false;
    return m_pRoom->m_isAccountReward;
}
MS2_REPLACE_METHOD(0x14031B970, DungeonRecord, IsAccountReward, 41, 0x4E70DC08);

// @0x14031b9a0
int DungeonRecord::GetBonusRewardCount(__int64 tNow)
{
    if (tNow >= m_expire)
        return 0;
    return m_bonusRewardCount;
}
MS2_REPLACE_METHOD(0x14031B9A0, DungeonRecord, GetBonusRewardCount, 40, 0x8EF39474);

// @0x14031b9d0
int DungeonRecord::GetClearCount(__int64 tNow)
{
    return m_clearCount.Get(tNow);
}
MS2_REPLACE_METHOD(0x14031B9D0, DungeonRecord, GetClearCount, 44, 0x2324F281);

// @0x14031ba10
unsigned DungeonRecord::GetSubRewardCount()
{
    return m_pRoom->m_subRewardCount;
}
MS2_REPLACE_METHOD(0x14031BA10, DungeonRecord, GetSubRewardCount, 21, 0xA4241172);

// @0x14031ba30
int DungeonRecord::GetExtraCount(__int64 tNow)
{
    return m_extraCount.Get(tNow);
}
MS2_REPLACE_METHOD(0x14031BA30, DungeonRecord, GetExtraCount, 44, 0x46F8BF69);

// @0x14031ba70
int DungeonRecord::GetRewardCount(__int64 tNow)
{
    if (!m_pRoom)
        return 0;
    if (tNow >= m_expire)
        return m_pRoom->m_rewardCount;
    return m_pRoom->m_rewardCount + m_bonusCount;
}
MS2_REPLACE_METHOD(0x14031BA70, DungeonRecord, GetRewardCount, 89, 0x92DBC21E);

// @0x14031bad0
int DungeonRecord::GetUsedBonusCount(__int64 tNow)
{
    if (tNow >= m_expire)
        return 0;
    return m_usedBonusCount;
}
MS2_REPLACE_METHOD(0x14031BAD0, DungeonRecord, GetUsedBonusCount, 40, 0x2E2FB024);

// @0x14031bb00
int DungeonRecord::GetBonusCount(__int64 tNow)
{
    if (tNow >= m_expire)
        return 0;
    return m_bonusCount;
}
MS2_REPLACE_METHOD(0x14031BB00, DungeonRecord, GetBonusCount, 40, 0x7E1B135C);

// @0x14031bb30
MS2Ptr<DungeonRoom> DungeonRecord::GetRoom()
{
    return m_pRoom;
}
MS2_REPLACE_METHOD(0x14031BB30, DungeonRecord, GetRoom, 65, 0xD9AAA2B6);

// @0x14031bb80 (not hooked: reads the DLL-local TSingleton instance)
void DungeonRecord::ResolveRoom()
{
    if (!DungeonRoomTable::GetInstance())
        return;
    m_pRoom = DungeonRoomTable::GetInstance()->GetRoom(m_dungeonRoomID).get();
}

// @0x14031bc00
CInputStream& operator>>(CInputStream& in, DungeonRecord& record)
{
    FUN_14070f480(in, record.m_dungeonRoomID);
    FUN_14070f500(in, record.m_expire);
    FUN_14070f340(in, record.m_bonusRewardCount);
    in >> record.m_clearCount;
    FUN_14070f340(in, record.m_bonusCount);
    in >> record.m_extraCount;
    FUN_14070f440(in, record.m_5c);
    FUN_14070f3c0(in, record.m_60);
    in >> record.m_68;
    in >> record.m_flags;
    record.ResolveRoom();
    return in;
}

// @0x14031bd10
COutputStream& operator<<(COutputStream& out, DungeonRecord& record)
{
    FUN_14070f9a0(out, record.m_dungeonRoomID);
    FUN_14070fa20(out, record.m_expire);
    FUN_14070f860(out, record.m_bonusRewardCount);
    out << record.m_clearCount;
    FUN_14070f860(out, record.m_bonusCount);
    out << record.m_extraCount;
    FUN_14070f960(out, record.m_5c);
    FUN_14070f8e0(out, record.m_60);
    out << record.m_68;
    out << record.m_flags;
    return out;
}
MS2_REPLACE_OVERLOAD(0x14031BD10, COutputStream&(COutputStream&, DungeonRecord&), operator<<, 224, 0xC8F6F312);

// @0x14031be00
DungeonRankReward::DungeonRankReward() : m_18(0), m_1c(0), m_20(0)
{
}

// @0x14031be60
CInputStream& operator>>(CInputStream& in, DungeonRankReward& reward)
{
    FUN_14070f480(in, reward.m_18);
    FUN_14070f440(in, reward.m_1c);
    FUN_14070f500(in, reward.m_20);
    return in;
}
MS2_REPLACE_OVERLOAD(0x14031BE60, CInputStream&(CInputStream&, DungeonRankReward&), operator>>, 90, 0x36AC0FCE);

// @0x14031bec0
COutputStream& operator<<(COutputStream& out, DungeonRankReward& reward)
{
    FUN_14070f9a0(out, reward.m_18);
    FUN_14070f960(out, reward.m_1c);
    FUN_14070fa20(out, reward.m_20);
    return out;
}
MS2_REPLACE_OVERLOAD(0x14031BEC0, COutputStream&(COutputStream&, DungeonRankReward&), operator<<, 79, 0x8FEDE8CD);

MS2_EMIT_CRT_MEMMOVE_S();
