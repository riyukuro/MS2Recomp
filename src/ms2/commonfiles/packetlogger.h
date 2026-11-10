// CPacketLogger recovered from RTTI; field and helper names inferred.
#pragma once
#include <atlcoll.h>
#include <atlfile.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/intervaltimer.h"
struct Unk_LogInPacket {
    int GetLength() const { return length; }
    int GetSequence() const { return sequence; }
    int GetFlags() const { return flags; }
    void* p00;void* p08;int flags;int p14;void* p18;void* p20;void* p28;void* p30;void* p38;
    int p40;int length;int p48;int sequence;
};
MS2_CHECK_OFFSET(Unk_LogInPacket,flags,0x10);
MS2_CHECK_OFFSET(Unk_LogInPacket,length,0x44);
MS2_CHECK_OFFSET(Unk_LogInPacket,sequence,0x4c);
class Unk_LogOutPacket { public: int GetLength() const;int GetSequence() const;int IsLoopback() const; };
class CPacketLogger : public CPtred {
public:
    CPacketLogger(); virtual ~CPacketLogger();
    bool Configure(bool,bool,bool);
    void LogSend(int,const Unk_LogOutPacket&);
    void LogReceive(int,const Unk_LogInPacket&);
    void Update();
    const float& SendRate() const;
    const float& ReceiveRate() const;
    void Open();
    void WriteHeader();
    void Close();
    bool ShouldReceive(int,const Unk_LogInPacket&) const;
    bool ShouldSend(int,const Unk_LogOutPacket&) const;
    bool AllowClient(int) const;
    bool AllowGame(int) const;
    CString Timestamp(int) const;
    CString DescribeReceive(int,const Unk_LogInPacket&) const;
    CString DescribeSend(int,const Unk_LogOutPacket&) const;
    void Write(const CString&,const CString&);
private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;
    bool m_client,m_enabled;
    ATL::CAtlFile m_file;
    ATL::CRBMap<int,CString> m_sendNames,m_receiveNames;
    unsigned m_lastSend,m_lastReceive;
    Unk_IntervalTimer m_timer;
    float m_sendRate; int m_sendBytes;
    float m_receiveRate; int m_receiveBytes;
};
MS2_CHECK_SIZE(CPacketLogger,0xe0);
MS2_CHECK_OFFSET(CPacketLogger,m_lock,0x18);
MS2_CHECK_OFFSET(CPacketLogger,m_client,0x48);
MS2_CHECK_OFFSET(CPacketLogger,m_file,0x50);
MS2_CHECK_OFFSET(CPacketLogger,m_sendNames,0x60);
MS2_CHECK_OFFSET(CPacketLogger,m_receiveNames,0x90);
MS2_CHECK_OFFSET(CPacketLogger,m_timer,0xc8);
MS2_CHECK_OFFSET(CPacketLogger,m_sendRate,0xd0);
MS2_CHECK_OFFSET(CPacketLogger,m_receiveRate,0xd8);
