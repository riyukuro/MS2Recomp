// meratproductkey.h - the key of a merat market product (Unk_MeratProductKey), split out of meratmarketbasketinfo.h so
// headers that only keep products by key (placeholder/cmeratmarketman.h) need not pull in the product records and
// ugcdef.h. NOT an original header.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/placeholder/cinpacket.h"

// The key of a market product: a premium product id, or a UGC product serial (asitemslot.cpp: Unk_MeratOid).
struct Unk_MeratProductKey
{
    // @0x1402038a0
    Unk_MeratProductKey() { Reset(); }
    // @0x1406a8510
    Unk_MeratProductKey(int nPremiumId, __int64 nUgcId) : m_nPremiumId(nPremiumId), m_nUgcId(nUgcId) {}
    // @0x140207730
    void Reset() { m_nPremiumId = 0; m_nUgcId = 0; }
    // @0x1406ad6b0
    void Set(int nPremiumId, __int64 nUgcId) { m_nPremiumId = nPremiumId; m_nUgcId = nUgcId; }
    // @0x1406a9c70
    void Write(COutputStream& stream) const { stream.WriteInt32(m_nPremiumId); stream.WriteInt64(m_nUgcId); }
    // @0x1406a9b40
    void Read(CInPacket& packet) { m_nPremiumId = packet.ReadInt32(); m_nUgcId = packet.ReadInt64(); }

    void FUN_1409c1640(CStringW strText);                   // 0x1409c1640 parse the key from its text (body in another unit)
    CStringW FUN_1409b0470() const;                         // 0x1409b0470 the key as text ("P<n>" / "U<n>")
    bool FUN_140899ce0(const Unk_MeratProductKey& other) const;   // 0x140899ce0 same key (body in another unit)
    bool operator==(const Unk_MeratProductKey& other) const;     // 0x140899ce0 (CRBMap key compare; body in ugcdef.cpp)
    bool operator<(const Unk_MeratProductKey& other) const;      // 0x140899d90 (body in ugcdef.cpp)

    int m_nPremiumId;                                       // +0x00
    unsigned __int64 m_nUgcId;                              // +0x08 (unsigned: the key text formats it as ULONG_LONG, 0x1409b0470)
};
MS2_CHECK_SIZE(Unk_MeratProductKey, 0x10);
