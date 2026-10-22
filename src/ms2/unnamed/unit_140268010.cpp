// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Small shared-state helpers in front of the common structs:
// a locked int -> int map with its stream (de)serialisation, the AccountBlockInfo / CDBMarketBuyLimitHistory
// record ctors with their stream Write/Read, and the tick based interval timer. File and class names are invented
// except the RTTI ones (no __FILE__ string in the range).
// MS2-UNIT: unit_140268010
// MS2-RANGE: 0x140268010-0x140268b20 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_140268010.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include <new>
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/timeutil.h"
#define MS2_ACCOUNTBLOCKINFO_OWN_LAYOUT
#include "ms2/client/ms2/blockmanager.h"

// The map value: stored in 4 bytes, one byte on the wire; its traits take it by reference (not a primitive).
enum Unk_LimitValue { Unk_LimitValue_Zero = 0 };

// A lock plus an int -> int map (0x78 bytes; 17 bins, load .75/.25/2.25, block size 10), every access under the lock.
class Unk_LockedIntMap
{
public:
    Unk_LockedIntMap();                                         // 0x140268010
    void Clear();                                               // 0x140268090
    void Write(COutputStream* pOut);                            // 0x1402680f0
    void Read(CInputStream* pIn);                               // 0x140268210
    void Assign(Unk_LockedIntMap* pOther);                      // 0x140268300
    void Set(int nKey, Unk_LimitValue nValue);                             // 0x1402684d0
    Unk_LimitValue Get(int nKey);                                          // 0x140268570

    CLockCriticalSection m_lock;                                // +0x00
    ATL::CAtlMap<int, Unk_LimitValue> m_map;                               // +0x30
};
MS2_CHECK_SIZE(Unk_LockedIntMap, 0x78);

// A tick based interval timer: Check() succeeds at most once per interval.
class Unk_IntervalTimer
{
public:
    void Init();                                                // 0x140268840
    int Check(unsigned int nInterval);                         // 0x140268870

    unsigned int m_nInterval;
    unsigned int m_nLast;
};
MS2_CHECK_SIZE(Unk_IntervalTimer, 8);

// RTTI CDBMarketBuyLimitHistory: the market buy limit row as stored in the DB.
class CDBMarketBuyLimitHistory : public CPtred
{
public:
    CDBMarketBuyLimitHistory();                                 // 0x1402688d0
    void Write(COutputStream* pOut);                            // 0x140268950
    void Read(CInPacket& packet);                              // 0x140268a00

    __int64 m_n18;                                              // +0x18
    __int64 m_n20;                                              // +0x20
    int m_nFlag;                                                // +0x28 (one byte on the wire)
    int m_n2c;                                                  // +0x2c
    int m_n30;                                                  // +0x30
    int m_pad_34;
    __int64 m_n38;                                              // +0x38
};
MS2_CHECK_SIZE(CDBMarketBuyLimitHistory, 0x40);

// @0x140268010
Unk_LockedIntMap::Unk_LockedIntMap()
    : m_map(17, 0.75f, 0.25f, 2.25f, 10)
{
    Clear();
}

// @0x140268090
void Unk_LockedIntMap::Clear()
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_map.RemoveAll();
    }
}

// @0x1402680f0
void Unk_LockedIntMap::Write(COutputStream* pOut)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        int nCount = (int)m_map.GetCount();
        pOut->WriteInt32(nCount);
        for (POSITION pos = m_map.GetStartPosition(); pos != 0; m_map.GetNext(pos))
        {
            pOut->WriteInt32(m_map.GetKeyAt(pos));
            pOut->WriteUInt8((unsigned char)m_map.GetValueAt(pos));
        }
    }
}

// @0x140268210
void Unk_LockedIntMap::Read(CInputStream* pIn)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_map.RemoveAll();
        int nCount = pIn->ReadInt32();
        if (nCount == 0)
            return;
        for (int i = 0; i < nCount; i++)
        {
            int nKey = pIn->ReadInt32();
            Unk_LimitValue nValue = (Unk_LimitValue)pIn->ReadUInt8();
            m_map.SetAt(nKey, nValue);
        }
    }
}

// @0x140268300
void Unk_LockedIntMap::Assign(Unk_LockedIntMap* pOther)
{
    ATL::CAtlMap<int, Unk_LimitValue> kTemp(17, 0.75f, 0.25f, 2.25f, 10);
    if (Unk_LockGuard guard = pOther->m_lock) {} else
    {
        for (POSITION pos = pOther->m_map.GetStartPosition(); pos != 0; pOther->m_map.GetNext(pos))
            kTemp.SetAt(pOther->m_map.GetKeyAt(pos), pOther->m_map.GetValueAt(pos));
    }
    if (Unk_LockGuard guard = m_lock) {} else
    {
        m_map.RemoveAll();
        for (POSITION pos = kTemp.GetStartPosition(); pos != 0; kTemp.GetNext(pos))
            m_map.SetAt(kTemp.GetKeyAt(pos), kTemp.GetValueAt(pos));
    }
}

// @0x1402684d0
void Unk_LockedIntMap::Set(int nKey, Unk_LimitValue nValue)
{
    if (Unk_LockGuard guard = m_lock) {} else
    {
        ATL::CAtlMap<int, Unk_LimitValue>::CPair* pPair = m_map.Lookup(nKey);
        if (pPair != 0)
            pPair->m_value = nValue;
        else
            m_map.SetAt(nKey, nValue);
    }
}

// @0x140268570
Unk_LimitValue Unk_LockedIntMap::Get(int nKey)
{
    Unk_LimitValue nValue = Unk_LimitValue_Zero;
    if (Unk_LockGuard guard = m_lock) {} else
    {
        ATL::CAtlMap<int, Unk_LimitValue>::CPair* pPair = m_map.Lookup(nKey);
        if (pPair != 0)
            nValue = pPair->m_value;
    }
    return nValue;
}

// @0x140268600
// MS2-FUNCTIONAL: the exe constructs the reason string between the zeroing of +0x28 and +0x38 (member order of the unrecovered original)
AccountBlockInfo::AccountBlockInfo()
{
    m_n18 = 0;
    m_nId = 0;
    m_nKind = 0;
    m_nStart = 0;
    m_nExpiry = 0;
}

// @0x140268690
void AccountBlockInfo::Write(COutputStream* pOut)
{
    pOut->WriteInt64(m_nId);
    pOut->WriteInt32(m_nKind);
    pOut->WriteInt64(m_n18);
    pOut->WriteUnicodeString(m_strReason);
    pOut->WriteInt64(m_nStart);
    pOut->WriteInt64(m_nExpiry);
}

// @0x140268750
void AccountBlockInfo::Read(CInputStream* pIn)
{
    m_nId = pIn->ReadInt64();
    m_nKind = pIn->ReadInt32();
    m_n18 = pIn->ReadInt64();
    m_strReason = pIn->ReadUnicodeString();
    m_nStart = pIn->ReadInt64();
    m_nExpiry = pIn->ReadInt64();
}

// @0x140268840
void Unk_IntervalTimer::Init()
{
    m_nInterval = 0;
    m_nLast = GetTickCountMs2();
}

// @0x140268870
int Unk_IntervalTimer::Check(unsigned int nInterval)
{
    if (nInterval == 0)
        nInterval = m_nInterval;
    if (m_nLast == 0 || GetTickCountMs2() - m_nLast >= nInterval)
    {
        m_nLast = GetTickCountMs2();
        return 1;
    }
    return 0;
}

// @0x1402688d0
CDBMarketBuyLimitHistory::CDBMarketBuyLimitHistory()
{
    m_n18 = 0;
    m_n20 = 0;
    m_nFlag = 0;
    m_n2c = 0;
    m_n30 = 0;
    m_n38 = 0;
}

// @0x140268950
void CDBMarketBuyLimitHistory::Write(COutputStream* pOut)
{
    pOut->WriteInt64(m_n18);
    pOut->WriteInt64(m_n20);
    pOut->WriteUInt8((unsigned char)m_nFlag);
    pOut->WriteInt32(m_n2c);
    pOut->WriteInt32(m_n30);
    pOut->WriteInt64(m_n38);
}

// @0x140268a00
void CDBMarketBuyLimitHistory::Read(CInPacket& packet)
{
    m_n18 = packet.ReadInt64();
    m_n20 = packet.ReadInt64();
    m_nFlag = packet.ReadUInt8();
    m_n2c = packet.ReadInt32();
    m_n30 = packet.ReadInt32();
    m_n38 = packet.ReadInt64();
}
