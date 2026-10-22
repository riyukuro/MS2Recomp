// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CStatPointManager: the stat point table and its requests.
// MS2-UNIT: ?\statpointmanager.cpp
// MS2-RANGE: 0x140ca9d50-0x140cac530 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\statpointmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "statpointmanager.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/placeholder/clientconstants.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Unrecovered helpers.
class Unk_StatPointEvents { public: void FUN_141b0ce20(int nEvent, int nArg); };
Unk_StatPointEvents* FUN_140aa6d40();
CStringW GetStringCommonByKey(const CStringW&);
void FUN_1412751f0(const CStringW&, int, int);
void FUN_140710590(COutPacket&);

// @0x140ca9d50
CStatPointManager::CStatPointManager(void* pOwner)
    : m_pOwner(pOwner), m_nTotal(0), m_nUsed(0), m_nRemaining(0), m_stats(17, 0.75f, 0.25f, 2.25f, 10),
      m_extra(17, 0.75f, 0.25f, 2.25f, 10)
{
}

// @0x140ca9e40
CStatPointManager::~CStatPointManager()
{
}

// @0x140ca9e90
void CStatPointManager::OnPacket(CInPacket& packet)
{
    int nMode = packet.ReadUInt8();
    switch (nMode)
    {
    case 0:
        LoadExtra(packet);
        break;
    case 1:
        LoadStats(packet);
        break;
    }
}
MS2_REPLACE_METHOD(0x140CA9E90, CStatPointManager, OnPacket, 116, 0x654A1F4D);

// @0x140ca9f10
void CStatPointManager::LoadExtra(CInPacket& packet)
{
    m_nTotal = packet.ReadInt32();
    m_nRemaining = m_nTotal - m_nUsed;
    m_extra.RemoveAll();
    unsigned nCount = packet.ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        CStatPointManager::Unk_ExtraKey nKey = (CStatPointManager::Unk_ExtraKey)packet.ReadInt32();
        unsigned nValue = packet.ReadInt32();
        m_extra.SetAt(nKey, nValue);
    }
    FUN_140aa6d40()->FUN_141b0ce20(0x10, 0);
}
MS2_REPLACE_METHOD(0x140CA9F10, CStatPointManager, LoadExtra, 298, 0x04657B2B);

// @0x140caa040
void CStatPointManager::LoadStats(CInPacket& packet)
{
    m_stats.RemoveAll();
    m_nTotal = packet.ReadInt32();
    m_nUsed = 0;
    unsigned nCount = packet.ReadInt32();
    for (unsigned i = 0; i < nCount; i++)
    {
        CStatPointManager::Unk_StatKey nStat = (CStatPointManager::Unk_StatKey)packet.ReadUInt8();
        int nPoints = packet.ReadInt32();
        m_stats.SetAt(nStat, nPoints);
        m_nUsed += nPoints;
    }
    m_nRemaining = m_nTotal - m_nUsed;
    FUN_140aa6d40()->FUN_141b0ce20(0x10, 0);
}
MS2_REPLACE_METHOD(0x140CAA040, CStatPointManager, LoadStats, 340, 0x4D535550);

// @0x140caa1a0
int CStatPointManager::GetRemaining()
{
    return m_nRemaining;
}
MS2_REPLACE_METHOD(0x140CAA1A0, CStatPointManager, GetRemaining, 14, 0xD26D6807);

// @0x140caa1c0
int CStatPointManager::GetUsed()
{
    return m_nUsed;
}
MS2_REPLACE_METHOD(0x140CAA1C0, CStatPointManager, GetUsed, 14, 0xBA6447E3);

// @0x140caa1e0
int CStatPointManager::GetStatPoints(Unk_StatKey nStat)
{
    int nPoints = 0;
    m_stats.Lookup(nStat, nPoints);
    return nPoints;
}
MS2_REPLACE_METHOD(0x140CAA1E0, CStatPointManager, GetStatPoints, 57, 0x91963CA1);

// @0x140caa220
unsigned CStatPointManager::GetExtra(Unk_ExtraKey nKey)
{
    unsigned nValue = 0;
    m_extra.Lookup(nKey, nValue);
    return nValue;
}
MS2_REPLACE_METHOD(0x140CAA220, CStatPointManager, GetExtra, 57, 0xFA1D8479);

// @0x140caa260
int CStatPointManager::GetTotal()
{
    return m_nTotal;
}
MS2_REPLACE_METHOD(0x140CAA260, CStatPointManager, GetTotal, 14, 0xA25B27BF);

// @0x140caa280
// MS2-FUNCTIONAL: limit compare loads the limit into eax (cmp [nNew],eax) where the exe loads nNew into edx (cmp edx,[limit]); same semantics
void CStatPointManager::RequestAdd(int nStat, int nAmount)
{
    if (m_nRemaining == 0)
        return;
    unsigned nNew = GetStatPoints((Unk_StatKey)nStat) + nAmount;
    if (nNew > (&FUN_1401d3200()->StatPointLimit_str)[nStat])
    {
        FUN_1412751f0(GetStringCommonByKey(L"s_char_info_limit_stat_point"), 1, 1);
    }
    else
    {
        COutPacket packet(static_cast<int>(SendOp::AttributePoint), 0);
        packet.WriteUInt8(2);
        packet.WriteUInt8((unsigned char)nStat);
        packet.WriteInt32(nAmount);
        FUN_140710590(packet);
    }
}
MS2_REPLACE_METHOD(0x140CAA280, CStatPointManager, RequestAdd, 297, 0x19C3D489);

// @0x140caa3b0
void CStatPointManager::RequestReset()
{
    if (m_nUsed == 0)
        return;
    COutPacket packet(static_cast<int>(SendOp::AttributePoint), 0);
    packet.WriteUInt8(3);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140CAA3B0, CStatPointManager, RequestReset, 88, 0xEE53C2F3);
