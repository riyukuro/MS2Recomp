// unit_140268010.h - Unk_LockedIntMap (defined in unit_140268010_sharedstatemap.cpp): a lock plus an int -> int map
// (0x78 bytes), the counters of CPartyMember. Names invented.
#pragma once
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/clockcriticalsection.h"

class COutputStream;
class CInputStream;

// The map value: stored in 4 bytes, one byte on the wire (an enum in the exe; same layout as int).
enum Unk_LimitValue : int;

// A lock plus an int -> int map (0x78 bytes; 17 bins, load .75/.25/2.25, block size 10), every access under the lock.
class Unk_LockedIntMap
{
public:
    Unk_LockedIntMap();                                         // 0x140268010
    ~Unk_LockedIntMap();                                        // 0x141634280 (partymanager.cpp)
    void Clear();                                               // 0x140268090
    void Write(COutputStream* pOut);                            // 0x1402680f0
    void Read(CInputStream* pIn);                               // 0x140268210
    void Assign(Unk_LockedIntMap* pOther);                      // 0x140268300
    void Set(int nKey, Unk_LimitValue nValue);                  // 0x1402684d0
    Unk_LimitValue Get(int nKey);                               // 0x140268570

    CLockCriticalSection m_lock;                                // +0x00
    ATL::CAtlMap<int, Unk_LimitValue> m_map;                    // +0x30
};
MS2_CHECK_SIZE(Unk_LockedIntMap, 0x78);
