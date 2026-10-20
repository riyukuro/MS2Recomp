// partybits.h - Unk_PartyBits, a one-byte bitset (commonfiles\bitset.inl: operator[] line 152, Set 243, Test 404). NOT an
// original header; the class names are invented. Used for the party permissions (partymanager.h), the dungeon room
// day-of-week limits (dungeonroom.h) and the GameEvent flags (gameevent.h). The members are defined in
// commonfiles\gameeventbase.cpp, the first unit that instantiated them.
#pragma once
#include "ms2/ms2layout.h"

extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);

#define MS2_PARTYBITS_ASSERT(line, expression)                                                                    \
    (void)((!!(expression)) ||                                                                                     \
           (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl", line), 0))

struct Unk_Bitset8;

// What operator[] returns: the bitset and the bit index.
struct Unk_PartyBitRef {
    // @0x1402e4c00
    Unk_PartyBitRef(Unk_Bitset8* pBits, int nPos);
    Unk_PartyBitRef& operator=(bool bValue);     // 0x1402e4dc0
    operator bool() const;                      // 0x140837280 (statesyncobject.cpp)
    Unk_Bitset8* m_pBits;
    int m_nPos;
};

struct Unk_Bitset8 {
    unsigned char m_bits[1];
    void Fill(bool bFill);                  // 0x1402e6bb0
    void ClearUnusedBits();                 // 0x1402e6c10
    Unk_PartyBitRef operator[](int nPos);        // 0x1402e4e80
    Unk_Bitset8& Set(unsigned nPos, bool bValue);   // 0x1402e69d0
    bool Test(unsigned nPos) const;         // 0x1402e6b10
};
MS2_CHECK_SIZE(Unk_Bitset8, 1);

struct Unk_PartyBits : Unk_Bitset8 {
    Unk_PartyBits(); // 1402e49d0
    bool FUN_1402e4ee0(int);
    bool FUN_140b912f0();
    bool FUN_140b91330();                   // none(): !FUN_140b912f0() (uipcbangdialog.cpp)
    unsigned FUN_140b91370();               // size(): 8 (unit_140b8e760)
    Unk_PartyBits& FUN_140837500();         // reset (statesyncobject.cpp)
    void FUN_1402e69d0(unsigned nBit, bool bSet);
};
MS2_CHECK_SIZE(Unk_PartyBits, 1);
