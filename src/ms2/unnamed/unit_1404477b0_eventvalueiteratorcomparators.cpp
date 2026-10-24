// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDAT tail after commonfiles\gameeventvalueidipevent.cpp:
// std::_Tree_const_iterator<...>::operator== / operator!= for 15 std::map trees (element types are the game-event value
// containers, not recovered yet: distinct stand-in value types, so each tree gets its own instance).
// MS2-UNIT: unit_1404477b0
// MS2-RANGE: 0x1404477b0-0x140447ef0 .text$mn
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_1404477b0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

struct Unk_GevT0 { void* raw; };
struct Unk_GevT1 { void* raw; };
struct Unk_GevT2 { void* raw; };
struct Unk_GevT3 { void* raw; };
struct Unk_GevT4 { void* raw; };
struct Unk_GevT5 { void* raw; };
struct Unk_GevT6 { void* raw; };
struct Unk_GevT7 { void* raw; };
struct Unk_GevT8 { void* raw; };
struct Unk_GevT9 { void* raw; };
struct Unk_GevT10 { void* raw; };
struct Unk_GevT11 { void* raw; };
struct Unk_GevT12 { void* raw; };
struct Unk_GevT13 { void* raw; };
struct Unk_GevT14 { void* raw; };

template <class M> void Unk_GevCompare(M& m)
{
    typename M::const_iterator a = m.begin(), b = m.end();
    if (a == b || a != b)
        ;
}
template <class M> void Unk_GevCompareEq(M& m)
{
    typename M::const_iterator a = m.begin(), b = m.end();
    if (a == b)
        ;
}

void Unk_GevAnchor()
{
    std::map<unsigned, Unk_GevT0> m0; Unk_GevCompare(m0);
    std::map<unsigned, Unk_GevT1> m1; Unk_GevCompare(m1);
    std::map<unsigned, Unk_GevT2> m2; Unk_GevCompare(m2);
    std::map<unsigned, Unk_GevT3> m3; Unk_GevCompare(m3);
    std::map<unsigned, Unk_GevT4> m4; Unk_GevCompare(m4);
    std::map<unsigned, Unk_GevT5> m5; Unk_GevCompare(m5);
    std::map<unsigned, Unk_GevT6> m6; Unk_GevCompare(m6);
    std::map<unsigned, Unk_GevT7> m7; Unk_GevCompare(m7);
    std::map<unsigned, Unk_GevT8> m8; Unk_GevCompare(m8);
    std::map<unsigned, Unk_GevT9> m9; Unk_GevCompareEq(m9);
    std::map<unsigned, Unk_GevT10> m10; Unk_GevCompare(m10);
    std::map<unsigned, Unk_GevT11> m11; Unk_GevCompare(m11);
    std::map<unsigned, Unk_GevT12> m12; Unk_GevCompare(m12);
    std::map<unsigned, Unk_GevT13> m13; Unk_GevCompare(m13);
    std::map<unsigned, Unk_GevT14> m14; Unk_GevCompare(m14);
}
