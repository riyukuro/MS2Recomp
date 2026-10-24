// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). A 12-byte value of three ints (shared by the achievement
// tally, the guild trophy triple and the proxy color): its constructor and the clear it forwards to.
// MS2-UNIT: unit_140267ba0
// MS2-RANGE: 0x140267ba0-0x140267c10 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_140267ba0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"

// Name invented; the exe has one 0xc-byte value of three ints with these two functions.
class Unk_IntTriple
{
public:
    Unk_IntTriple();
    void Clear();
    int m_v[3];
};
MS2_CHECK_SIZE(Unk_IntTriple, 0xc);

// @0x140267ba0
Unk_IntTriple::Unk_IntTriple()
{
    Clear();
}

// @0x140267bd0
void Unk_IntTriple::Clear()
{
    for (int i = 0; i < 3; ++i) {
        m_v[i] = 0;
    }
}
