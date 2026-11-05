// bitset.h - PLACEHOLDER for the game's fixed-size bitset template (commonfiles\bitset.inl; the class name is invented,
// NOT an original header). Bytes, bit pos%8 of byte pos/8. The members follow the bitset.inl asserts: operator[] (line
// 152, "UINT(pos) < UINT(T)"), Set (243, "0"), Test (404, "0"). Instances: Unk_Bitset<3>::operator[] const / Set / Test
// at 0x140314650 / 0x140314670 / 0x140314790 (first instantiated by commonfiles\dungeonmatch.cpp). The other T = 3
// COMDATs: ctor / fill / trim 0x140afed60 / 0x140afee90 / 0x140afeef0 (client\ms2\cameramoveeffectparam.cpp), all /
// count / size 0x140afc5a0 / 0x140afca60 / 0x140afd3f0 (camera.cpp), any / set-all 0x1411fe0e0 / 0x1411ff180
// (equipment.cpp), and the non-const operator[] 0x14144b330 (lighteffectparam.cpp; its reference proxy Unk_BitRef is
// declared in lighteffectparam.h).
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"

extern "C" _ACRTIMP void __cdecl _wassert(wchar_t const* _Message, wchar_t const* _File, unsigned _Line);

#define MS2_BITSET_ASSERT(line, expression)                                                                       \
    (void)((!!(expression)) ||                                                                                     \
           (_wassert(_CRT_WIDE(#expression), L"e:\\build\\kr\\22_04\\ms2code\\commonfiles\\bitset.inl", line), 0))

struct Unk_BitRef;

template <int T> class Unk_Bitset
{
public:
    Unk_Bitset() { FUN_140afee90(0); }
    bool operator[](int pos) const { return Test(pos); }
    Unk_BitRef operator[](int pos);                             // 0x14144b330 (lighteffectparam.cpp)
    Unk_Bitset& Set(int pos, bool value = true)
    {
        if (UINT(pos) >= UINT(T)) { MS2_BITSET_ASSERT(243, 0); }
        if (value) m_bits[pos / 8] |= 1 << (pos % 8);
        else m_bits[pos / 8] &= ~(1 << (pos % 8));
        return *this;
    }
    bool Test(int pos) const
    {
        if (UINT(pos) >= UINT(T)) { MS2_BITSET_ASSERT(404, 0); return false; }
        return (m_bits[pos / 8] & (1 << (pos % 8))) != 0;
    }
    // @0x140afee90
    void FUN_140afee90(unsigned char ucValue)                   // Fill
    {
        for (int i = (T + 7) / 8 - 1; i >= 0; --i)
            m_bits[i] = ucValue;
        if (ucValue)
            FUN_140afeef0();
    }
    // @0x140afeef0
    void FUN_140afeef0()                                        // Trim (as compiled: returns early whenever T % 8 != 0)
    {
        if (T % 8)
            return;
        m_bits[(T + 7) / 8 - 1] &= (1 << (T % 8)) - 1;
    }
    // @0x140afc5a0
    bool FUN_140afc5a0() const { return FUN_140afca60() == FUN_140afd3f0(); }   // all
    // @0x140afca60
    int FUN_140afca60() const                                   // count
    {
        int nCount = 0;
        for (int i = (T + 7) / 8 - 1; i >= 0; --i)
            for (unsigned char uc = m_bits[i]; uc != 0; uc >>= 4)
                nCount += "\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4"[uc & 0xf];   // bits per hex digit
        return nCount;
    }
    // @0x140afd3f0
    int FUN_140afd3f0() const { return T; }                     // size
    // @0x1411fe0e0
    bool FUN_1411fe0e0() const                                  // any
    {
        for (int i = (T + 7) / 8 - 1; i >= 0; --i)
            if (m_bits[i] != 0)
                return true;
        return false;
    }
    // @0x1411ff180
    Unk_Bitset& FUN_1411ff180()                                 // set every bit
    {
        FUN_140afee90(0xff);
        return *this;
    }
private:
    unsigned char m_bits[(T + 7) / 8];
};
