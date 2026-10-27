// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUserLimitHistory serialization and state initialization.
// MS2-UNIT: unit_140269160
// MS2-RANGE: 0x140269160-0x140269440 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cinpacket.h"

// vftable 0x142d15a98: ??_G (0x14027fef0, crt delete 0x50), Initialize, Serialize, Deserialize. The ctor runs
// CPtred() (0x140159740) and stores that vftable; the old `void* m_vftable` stand-in left it null.
// Serialize writes to a COutputStream (WriteUInt8 slot 1, WriteInt32 slot 3, WriteInt64 slot 4, values by value);
// Deserialize reads from the CInPacket's CInputStream at +8 and stores the returned values.
class CUserLimitHistory : public CPtred
{
public:
    CUserLimitHistory();
    virtual void Initialize();
    virtual void Serialize(COutputStream* pOut);
    virtual void Deserialize(CInPacket& in);
    unsigned __int64 m_value18;
    unsigned __int64 m_value20;
    unsigned __int64 m_value28;
    unsigned int m_value30;
    unsigned int m_pad34;
    unsigned __int64 m_value38;
    unsigned int m_value40;
    unsigned int m_pad44;
    unsigned __int64 m_value48;
};
MS2_CHECK_SIZE(CUserLimitHistory, 0x50);

// @0x140269160
CUserLimitHistory::CUserLimitHistory()
{
    Initialize();
}

// @0x1402691b0
void CUserLimitHistory::Initialize()
{
    m_value18 = 0;
    m_value20 = 0;
    m_value28 = 0;
    m_value30 = 0;
    m_value38 = 0;
    m_value40 = 0;
    m_value48 = 0;
}

// @0x140269220
void CUserLimitHistory::Serialize(COutputStream* pOut)
{
    pOut->WriteInt64(m_value18);
    pOut->WriteInt64(m_value20);
    pOut->WriteInt64(m_value28);
    pOut->WriteUInt8((unsigned char)m_value30);
    pOut->WriteInt64(m_value38);
    pOut->WriteInt32(m_value40);
    pOut->WriteInt64(m_value48);
}

// @0x1402692f0
void CUserLimitHistory::Deserialize(CInPacket& in)
{
    m_value18 = in.ReadInt64();
    m_value20 = in.ReadInt64();
    m_value28 = in.ReadInt64();
    m_value30 = in.ReadUInt8();
    m_value38 = in.ReadInt64();
    m_value40 = in.ReadInt32();
    m_value48 = in.ReadInt64();
}
