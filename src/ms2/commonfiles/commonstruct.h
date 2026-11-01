// Common wire structures. Unknown source names use unit-local stand-ins.
#pragma once
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/packetlogqueue.h"
#include "ms2/placeholder/cclienthardwareinfo.h"
#include "ms2/placeholder/coutpacket.h"
#include "ms2/commonfiles/coutpacketptr.h"
class Unk_CommonOwner {
public:
    bool Matches(int kind,__int64 id);
    __int64 EffectiveId();
    __int64 id; int kind; __int64 alternate;
};
MS2_CHECK_SIZE(Unk_CommonOwner,0x18);
class Unk_CommonWireRecord {
public:
    Unk_CommonWireRecord();
    void Write(COutputStream&); void Read(CInputStream&);
    __int64 first,second;
    int type,value; float extra; bool enabled,flag;
};
MS2_CHECK_SIZE(Unk_CommonWireRecord,0x20);
MS2_CHECK_OFFSET(Unk_CommonWireRecord,extra,0x18);
class Unk_CommonTimedMap {
public:
    Unk_CommonTimedMap();
    void Clear(); bool Active();
    void Write(COutputStream&); void Read(CInputStream&);
    void WriteOne(COutputStream&,int); void ReadOne(CInputStream&);
    int selected;
    ATL::CAtlMap<int,__int64> times;
};
MS2_CHECK_SIZE(Unk_CommonTimedMap,0x50);
MS2_CHECK_OFFSET(Unk_CommonTimedMap,times,8);
class Unk_CommonFourInts {
public:
    void Write(COutputStream&); void Read(CInputStream&);
    int first,second,third,fourth;
};
MS2_CHECK_SIZE(Unk_CommonFourInts,0x10);
// View of COutPacket; no additional storage or slots.
class Unk_CommonPacket : public COutPacket {
};
MS2_CHECK_SIZE(Unk_CommonPacket,0x38);
struct Unk_CommonCachedPacket {
    Unk_CommonCachedPacket();
    Unk_CommonCachedPacket(const Unk_CommonPacket&,unsigned);
    unsigned sequence;
    COutPacketPtr packet;
};
MS2_CHECK_SIZE(Unk_CommonCachedPacket,0x18);
class Unk_CommonResendQueue {
public:
    Unk_CommonResendQueue();
    void Add(const Unk_CommonPacket&,unsigned packetSeq);
    void Prune(int targetBytes,int threshold);
    void Acknowledge(unsigned sequence);
    void CopyAfter(ATL::CAtlArray<Unk_CommonCachedPacket>&,unsigned sequence);
    unsigned LastSequence();
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;
    int m_totalBytes;
    volatile unsigned m_lastPacketSeq;
    ATL::CAtlList<Unk_CommonCachedPacket> m_packets;
};
MS2_CHECK_SIZE(Unk_CommonResendQueue,0x68);
MS2_CHECK_OFFSET(Unk_CommonResendQueue,m_packets,0x38);
