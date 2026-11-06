// launchbitset.h - PLACEHOLDER for the T = 4 launch-flag bitset (commonfiles\bitset.inl: operator[] line 152, Set line
// 243, Test line 404) with its proxy reference. The class names are invented, NOT an original header. One instance:
// g_bits (0x143ae0901), the launch-argument flags of the command-line parser (unit_1414b1230). Bits: 0 passport given,
// 1 sid given, 2/3 read and ignored.
//   operator[] 0x140c79bc0, reference ctor 0x140c799f0, reference::operator bool 0x140c79c60, Test 0x140c7cbb0
//     (first instantiated by unit_140c77ab0, ms2clientplatformnexonkorea)
//   ctor 0x1414b2250, reference::operator= 0x1414b2270, Set 0x1414b22b0, Fill 0x1414b23d0, ClearUnusedBits 0x1414b2430
//     (defined in unit_1414b1230)
#pragma once
#include "ms2/placeholder/bitset.h"   // MS2_BITSET_ASSERT

template <int T> class Unk_LaunchBitset
{
public:
    class reference
    {
    public:
        reference(Unk_LaunchBitset* pBits, int nPos) : m_pBits(pBits), m_nPos(nPos) {}
        reference& operator=(bool bValue);                      // 0x1414b2270
        operator bool() const { return m_pBits->Test(m_nPos); }
        Unk_LaunchBitset* m_pBits;
        int m_nPos;
    };
    Unk_LaunchBitset();                                         // 0x1414b2250
    reference operator[](int pos)
    {
        MS2_BITSET_ASSERT(152, UINT(pos) < UINT(T));
        return reference(this, pos);
    }
    Unk_LaunchBitset& FUN_1414b22b0(unsigned nPos, bool bValue);   // Set
    void FUN_1414b23d0(bool bFill);                             // Fill
    void FUN_1414b2430();                                       // ClearUnusedBits
    bool Test(int pos) const
    {
        if (UINT(pos) >= UINT(T)) { MS2_BITSET_ASSERT(404, 0); return false; }
        return (m_bits[pos / 8] & (1 << (pos % 8))) != 0;
    }
    unsigned char m_bits[(T + 7) / 8];
};
