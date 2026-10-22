// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: commonfiles\commonstruct.cpp#1
// MS2-RANGE: 0x14026ced0-0x14026e700 .text$mn
// MS2-RANGE: 0x1400b5630-0x1400b56f0 .text$di
// MS2-PIN: ?GetHeadPosition@?$CAtlList@UUnk_CommonCachedPacket@@V?$CElementTraits@UUnk_CommonCachedPacket@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x140281930
// MS2-PIN: ?GetNext@?$CAtlList@UUnk_CommonCachedPacket@@V?$CElementTraits@UUnk_CommonCachedPacket@@@ATL@@@ATL@@QEAAAEAUUnk_CommonCachedPacket@@AEAPEAU__POSITION@@@Z 0x140281a70
// MS2-PIN: ?GetAt@?$CAtlList@UUnk_CommonCachedPacket@@V?$CElementTraits@UUnk_CommonCachedPacket@@@ATL@@@ATL@@QEAAAEAUUnk_CommonCachedPacket@@PEAU__POSITION@@@Z 0x1402814d0
// MS2-RANGE: 0x142c9a420-0x142c9a450 .text$yd
// Partial recovery: network records, packet logs, resend queue and hardware information.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\commonstruct.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "commonstruct.h"
#include "ms2/placeholder/billboardinfo.h"
#include "ms2/commonfiles/logstring.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
static CString s_commonSortNames[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};

// This formatter constructor belongs to 0x14020a410 in an earlier unit.
template<> fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>::MakeValue(const wchar_t*);

__int64 FUN_140869440();
COutputStream& FUN_14070fa20(COutputStream&,__int64);
COutputStream& FUN_14070f9a0(COutputStream&,int);
COutputStream& FUN_14070fa60(COutputStream&,float);
COutputStream& FUN_14070f820(COutputStream&,bool);
CInputStream& FUN_14070f500(CInputStream&,__int64&);
CInputStream& FUN_14070f480(CInputStream&,int&);
CInputStream& FUN_14070f540(CInputStream&,float&);
CInputStream& FUN_14070f300(CInputStream&,bool&);

class Unk_CommonLog : public CLogString {
public:
    template<class T> void Log(unsigned __int64 a,unsigned __int64 b,int flags,const wchar_t* format,const T& value) {
        fmt::internal::Value values[]={fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(value)};
        FUN_1406535b0(a,b,flags,format,fmt::ArgList(fmt::internal::make_type(value),values));
    }
    void Log(unsigned __int64 a,unsigned __int64 b,int flags,const wchar_t* format) {
        FUN_1406535b0(a,b,flags,format,fmt::ArgList());
    }
};
Unk_CommonLog* FUN_140166440();

// @0x14026ced0
BillBoardInfo::BillBoardInfo() { Clear(); }
// @0x14026cf80
void BillBoardInfo::Write(COutputStream& out) {
    out.WriteInt64(firstId); out.WriteInt64(secondId);
    out.WriteUnicodeString(firstName); out.WriteUnicodeString(secondName);
    out.WriteInt16(type); out.WriteInt32(value);
    out.WriteUnicodeString(title); out.WriteUnicodeString(text);
    out.WriteBool(enabled);
    out.WriteInt64(start); out.WriteInt64(end); out.WriteInt64(owner);
}
MS2_REPLACE_METHOD(0x14026CF80, BillBoardInfo, Write, 372, 0x7A43A00D);
// @0x14026d100
void BillBoardInfo::Read(CInputStream& in) {
    firstId=in.ReadInt64(); secondId=in.ReadInt64();
    firstName=in.ReadUnicodeString(); secondName=in.ReadUnicodeString();
    type=in.ReadInt16(); value=in.ReadInt32();
    title=in.ReadUnicodeString(); text=in.ReadUnicodeString();
    enabled=in.ReadBool();
    start=in.ReadInt64(); end=in.ReadInt64(); owner=in.ReadInt64();
}
MS2_REPLACE_METHOD(0x14026D100, BillBoardInfo, Read, 629, 0xFBD6EFDC);
// @0x14026d380
// MS2-FUNCTIONAL: scalar position temporary omits the original reset security cookie.
void BillBoardInfo::Clear() {
    owner=0; localValue=0; firstId=0; secondId=0; type=0; value=0;
    enabled=false; localState=0; start=0; end=0; localIndex=0;
    position=Unk_CommonPosition(0,0,0);
    firstName=L""; secondName=L""; title=L""; text=L"";
}
MS2_REPLACE_METHOD(0x14026D380, BillBoardInfo, Clear, 320, 0xD8223397);
// @0x14026d4d0
bool Unk_CommonOwner::Matches(int kind,__int64 id) {
    if(kind!=this->kind) return EffectiveId()==id;
    return this->id==id;
}
MS2_REPLACE_METHOD(0x14026D4D0, Unk_CommonOwner, Matches, 117, 0xF1388B16);
// @0x14026d550
__int64 Unk_CommonOwner::EffectiveId() { if(alternate==0) return id; return alternate; }
MS2_REPLACE_METHOD(0x14026D550, Unk_CommonOwner, EffectiveId, 37, 0x5FFDBE0A);
// @0x14026d580
Unk_CommonWireRecord::Unk_CommonWireRecord() : first(0),second(0),type(0),value(0),extra(0),enabled(true),flag(false) {}
// @0x14026d670
void Unk_CommonWireRecord::Write(COutputStream& out) {
    FUN_14070fa20(out,first); FUN_14070fa20(out,second);
    out.WriteInt16((short)type);
    FUN_14070f9a0(out,value); FUN_14070fa60(out,extra);
    FUN_14070f820(out,enabled); FUN_14070f820(out,flag);
}
MS2_REPLACE_METHOD(0x14026D670, Unk_CommonWireRecord, Write, 157, 0x700F57C5);
// @0x14026d720
void Unk_CommonWireRecord::Read(CInputStream& in) {
    FUN_14070f500(in,first); FUN_14070f500(in,second);
    type=(unsigned short)in.ReadInt16();
    FUN_14070f480(in,value); FUN_14070f540(in,extra);
    FUN_14070f300(in,enabled); FUN_14070f300(in,flag);
}
MS2_REPLACE_METHOD(0x14026D720, Unk_CommonWireRecord, Read, 174, 0x0EFC825A);
// @0x14026d7e0
Unk_CommonTimedMap::Unk_CommonTimedMap() : selected(0) { selected=0; }
// @0x14026d850
void Unk_CommonTimedMap::Clear() { selected=0; times.RemoveAll(); }
MS2_REPLACE_METHOD(0x14026D850, Unk_CommonTimedMap, Clear, 42, 0xF2FAFB7F);
// @0x14026d880
bool Unk_CommonTimedMap::Active() {
    if(selected==0) return 0;
    __int64 until=0;
    times.Lookup(selected,until);
    if(until>FUN_140869440()) return 1;
    return 0;
}
MS2_REPLACE_METHOD(0x14026D880, Unk_CommonTimedMap, Active, 84, 0x5F451E98);
// @0x14026d8e0
void Unk_CommonTimedMap::Write(COutputStream& out) {
    out.WriteInt32(selected); out.WriteInt32((int)times.GetCount());
    for(POSITION pos=times.GetStartPosition();pos;times.GetNext(pos)) {
        out.WriteInt32(times.GetKeyAt(pos)); out.WriteInt64(times.GetValueAt(pos));
    }
}
MS2_REPLACE_METHOD(0x14026D8E0, Unk_CommonTimedMap, Write, 247, 0xA93F9967);
// @0x14026d9e0
void Unk_CommonTimedMap::Read(CInputStream& in) {
    times.RemoveAll(); selected=in.ReadInt32();
    int count=in.ReadInt32();
    for(int i=0;i<count;++i) {
        int key=in.ReadInt32(); __int64 value=in.ReadInt64(); times.SetAt(key,value);
    }
}
MS2_REPLACE_METHOD(0x14026D9E0, Unk_CommonTimedMap, Read, 178, 0xA22F21D9);
// @0x14026daa0
void Unk_CommonTimedMap::WriteOne(COutputStream& out,int key) {
    __int64 value=0;
    if(times.Lookup(key,value)==true) { out.WriteInt32(key); out.WriteInt64(value); }
    else { out.WriteInt32(0); out.WriteInt64(0); }
}
MS2_REPLACE_METHOD(0x14026DAA0, Unk_CommonTimedMap, WriteOne, 146, 0x1743D37C);
// @0x14026db40
void Unk_CommonTimedMap::ReadOne(CInputStream& in) {
    int key=in.ReadInt32(); __int64 value=in.ReadInt64(); times.SetAt(key,value);
}
MS2_REPLACE_METHOD(0x14026DB40, Unk_CommonTimedMap, ReadOne, 86, 0x2ACB529A);
// @0x14026dba0
void Unk_CommonFourInts::Write(COutputStream& out) {
    out.WriteInt32(first); out.WriteInt32(second); out.WriteInt32(third); out.WriteInt32(fourth);
}
MS2_REPLACE_METHOD(0x14026DBA0, Unk_CommonFourInts, Write, 114, 0xE69225D6);
// @0x14026dc20
void Unk_CommonFourInts::Read(CInputStream& in) {
    first=in.ReadInt32(); second=in.ReadInt32(); third=in.ReadInt32(); fourth=in.ReadInt32();
}
MS2_REPLACE_METHOD(0x14026DC20, Unk_CommonFourInts, Read, 114, 0x69CFBEAE);
// @0x14026dca0
Unk_CommonPacketLogEntry::Unk_CommonPacketLogEntry() : type(0),loopback(0),time(0) {}
// @0x14026dce0
void Unk_CommonPacketLogEntry::Set(int type,int loopback,__int64 time) { this->type=type; this->loopback=loopback; this->time=time; }
MS2_REPLACE_METHOD(0x14026DCE0, Unk_CommonPacketLogEntry, Set, 57, 0x5202EF0B);
// @0x14026dd20
PacketLogQueue::PacketLogQueue(int count) { m_entries.SetCount(count); }
// @0x14026dd80
void PacketLogQueue::Add(int type,int loopback) {
    int index=InterlockedIncrement(&m_cursor);
    index=(int)((size_t)(__int64)index%m_entries.GetCount());
    m_entries[index].Set(type,loopback,FUN_140869440());
}
MS2_REPLACE_METHOD(0x14026DD80, PacketLogQueue, Add, 166, 0xA0B2824F);
// @0x14026de30
void PacketLogQueue::PrintPacketLogs() {
    FUN_140166440()->Log(0,0,12,L"* {0}",L"PacketLogQueue::PrintPacketLogs");
    CStringW text(L"[\r\n");
    for(unsigned i=0;i<m_entries.GetCount();++i) {
        Unk_CommonPacketLogEntry& entry=m_entries[i];
        if(entry.type!=0) text.AppendFormat(L"{{\"type\":%d, \"loopback\":%d, \"time\":\"%I64u\"}},\r\n",entry.type,entry.loopback,entry.time);
    }
    text+=L"]";
    const wchar_t* raw=text;
    FUN_140166440()->Log(0,0,12,raw);
}
MS2_REPLACE_METHOD(0x14026DE30, PacketLogQueue, PrintPacketLogs, 312, 0xD695911F);
// @0x14026df70
Unk_CommonCachedPacket::Unk_CommonCachedPacket() : sequence(0),packet(0) {}
// @0x14026dfb0
Unk_CommonCachedPacket::Unk_CommonCachedPacket(const Unk_CommonPacket& source,unsigned sequence) : sequence(sequence),packet(Unk_CommonNew(0)) {
    packet->FUN_140710740(source.FUN_14020ba20(),source.FUN_14020bc40(),1);
    packet->FUN_14020aa30(source,2);
}
// @0x14026e080
Unk_CommonResendQueue::Unk_CommonResendQueue() : m_totalBytes(0),m_lastPacketSeq(0) {}
// @0x14026e0e0
void Unk_CommonResendQueue::Add(const Unk_CommonPacket& source,unsigned packetSeq) {
    if(Unk_LockGuard guard=m_lock) { __assume(0); } else {
        Unk_CommonCachedPacket entry(source,packetSeq);
        m_packets.AddTail(entry); m_totalBytes+=source.FUN_14020b9f0();
        MS2_ASSERT_AT(0x902,m_lastPacketSeq == 0 || m_lastPacketSeq < packetSeq);
        m_lastPacketSeq=packetSeq;
    }
}
MS2_REPLACE_METHOD(0x14026E0E0, Unk_CommonResendQueue, Add, 227, 0xCF92E809);
// @0x14026e1d0
void Unk_CommonResendQueue::Prune(int targetBytes,int threshold) {
    if(m_totalBytes<=threshold) return;
    {
        if(Unk_LockGuard guard=m_lock) { __assume(0); } else {
            while(m_totalBytes>targetBytes&&!m_packets.IsEmpty()) {
                Unk_CommonCachedPacket entry=m_packets.RemoveHead();
                m_totalBytes-=entry.packet->FUN_14020b9f0();
            }
        }
    }
}
MS2_REPLACE_METHOD(0x14026E1D0, Unk_CommonResendQueue, Prune, 207, 0x532A3B40);
// @0x14026e2b0
void Unk_CommonResendQueue::Acknowledge(unsigned sequence) {
    if(Unk_LockGuard guard=m_lock) { __assume(0); } else {
        while(!m_packets.IsEmpty()) {
            Unk_CommonCachedPacket& entry=m_packets.GetHead();
            if(entry.sequence>sequence) break;
            m_totalBytes-=entry.packet->FUN_14020b9f0(); m_packets.RemoveHeadNoReturn();
        }
    }
}
MS2_REPLACE_METHOD(0x14026E2B0, Unk_CommonResendQueue, Acknowledge, 197, 0x15D091BF);
// @0x14026e380
void Unk_CommonResendQueue::CopyAfter(ATL::CAtlArray<Unk_CommonCachedPacket>& output,unsigned sequence) {
    if(Unk_LockGuard guard=m_lock) { __assume(0); } else {
        for(POSITION pos=m_packets.GetHeadPosition();pos;m_packets.GetNext(pos)) {
            const Unk_CommonCachedPacket& entry=m_packets.GetAt(pos);
            if(entry.sequence>sequence) output.Add(entry);
        }
    }
}
MS2_REPLACE_METHOD(0x14026E380, Unk_CommonResendQueue, CopyAfter, 189, 0x2B6AF8DC);
// @0x14026e450
unsigned Unk_CommonResendQueue::LastSequence() { return m_lastPacketSeq; }
MS2_REPLACE_METHOD(0x14026E450, Unk_CommonResendQueue, LastSequence, 14, 0x9A8B24F3);
// @0x14026e470
CClientHardwareInfo::CClientHardwareInfo() : m_hardware(L"") {}
// @0x14026e4e0
void CClientHardwareInfo::Write(COutputStream& out) { if(Unk_LockGuard guard=m_lock) { __assume(0); } else { out.WriteUnicodeString(m_hardware); } }
MS2_REPLACE_METHOD(0x14026E4E0, CClientHardwareInfo, Write, 116, 0x52C5054C);
// @0x14026e560
void CClientHardwareInfo::Read(CInputStream& in) { if(Unk_LockGuard guard=m_lock) { __assume(0); } else { m_hardware=in.ReadUnicodeString(); } }
MS2_REPLACE_METHOD(0x14026E560, CClientHardwareInfo, Read, 149, 0xE2A7F101);
// @0x14026e600
CStringW CClientHardwareInfo::Get() { if(Unk_LockGuard guard=m_lock) { __assume(0); } else { return m_hardware; } }
MS2_REPLACE_METHOD(0x14026E600, CClientHardwareInfo, Get, 137, 0x8CE2105F);
// @0x14026e690
void CClientHardwareInfo::Set(const CStringW& value) { if(Unk_LockGuard guard=m_lock) { __assume(0); } else { m_hardware=value; } }
MS2_REPLACE_METHOD(0x14026E690, CClientHardwareInfo, Set, 101, 0x13760137);
// @0x14027db40
Unk_CommonPosition::Unk_CommonPosition(float a,float b,float c) : x(a),y(b),z(c) {}
