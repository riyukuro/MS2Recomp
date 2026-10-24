// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMarketBuyLimitHistory: the in-memory market buy limit row
// (ctors, Reset, Merge of a DB row, stream Write/Read). File name is invented (no __FILE__ string in the range); the
// dtor and vftable live in the commonstruct range.
// MS2-UNIT: unit_140268b20
// MS2-RANGE: 0x140268b20-0x140269020 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <atlcoll.h>
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/cmarketbuylimithistory.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// @0x140268b20
CMarketBuyLimitHistory::CMarketBuyLimitHistory()
{
    Reset();
}

// @0x140268b80
CMarketBuyLimitHistory::CMarketBuyLimitHistory(CDBMarketBuyLimitHistory* pRow)
{
    Reset();
    if (pRow != 0)
    {
        m_n18 = pRow->m_n18;
        m_n20 = pRow->m_n20;
        m_nType = pRow->m_nFlag;
        m_n2c = pRow->m_n2c;
    }
}

// @0x140268c30
void CMarketBuyLimitHistory::Reset()
{
    m_n18 = 0;
    m_n20 = 0;
    m_nType = 0;
    m_n2c = 0;
    m_n30 = 0;
    m_itemUids.RemoveAll();
}
MS2_REPLACE_METHOD(0x140268C30, CMarketBuyLimitHistory, Reset, 93, 0x929289E6);

// @0x140268ca0
void CMarketBuyLimitHistory::Merge(CDBMarketBuyLimitHistory* pRow)
{
    if (pRow == 0) return;
    if (pRow->m_n18 != m_n18) return;
    if (pRow->m_nFlag != m_nType) return;
    if (m_nType == 2)
    {
        if (pRow->m_n20 != m_n20) return;
    }
    if (pRow->m_n2c != m_n2c) return;
    m_n30 += pRow->m_n30;
    m_itemUids.Add(pRow->m_n38);
}
MS2_REPLACE_METHOD(0x140268CA0, CMarketBuyLimitHistory, Merge, 177, 0x19887617);

// @0x140268d60
void CMarketBuyLimitHistory::Write(COutputStream* pOut)
{
    pOut->WriteInt64(m_n18);
    pOut->WriteInt64(m_n20);
    pOut->WriteUInt8((unsigned char)m_nType);
    pOut->WriteInt32(m_n2c);
    pOut->WriteInt32(m_n30);
    int nCount = (int)m_itemUids.GetCount();
    pOut->WriteInt32(nCount);
    for (int i = 0; i < nCount; i++)
    {
        __int64 nUid = m_itemUids[i];
        pOut->WriteInt64(nUid);
    }
}
MS2_REPLACE_METHOD(0x140268D60, CMarketBuyLimitHistory, Write, 266, 0x444F6BB4);

// @0x140268e70
void CMarketBuyLimitHistory::Read(CInPacket& packet)
{
    m_n18 = packet.ReadInt64();
    m_n20 = packet.ReadInt64();
    m_nType = packet.ReadUInt8();
    m_n2c = packet.ReadInt32();
    m_n30 = packet.ReadInt32();
    int nCount = packet.ReadInt32();
    for (int i = 0; i < nCount; i++)
    {
        __int64 nUid = packet.ReadInt64();
        m_itemUids.Add(nUid);
    }
}
MS2_REPLACE_METHOD(0x140268E70, CMarketBuyLimitHistory, Read, 425, 0x3A9AC300);
