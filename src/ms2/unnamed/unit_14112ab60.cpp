// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). std::map iterator decrement glue (29 map families whose key and
// value types are not recoverable from the byte-identical bodies) plus a few comparators and the cube point arithmetic.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_14112ab60
// MS2-RANGE: 0x14112ab60-0x14112cd60 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <iterator>
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/ugcmappackageinfo.h"
#include "ms2/client/ms2/cubespawnobject.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/client/ms2/functioncubeobject.h"
#include "ms2/client/ms2/gameobject.h"

// Stand-in key of the Nth map family; the exe's families differ only by their tree-node free and max-node functions.
template <int N> struct Unk_DkKey { int v[N + 1]; bool operator<(const Unk_DkKey& o) const { return v[0] < o.v[0]; } };
template <int N> struct Unk_DkMap { typedef std::map<Unk_DkKey<N>, int> type; };

// std::_Tree_iterator::operator-- (calls the const iterator's) and the reverse_iterator::operator++ over it.
template <int N> void Unk_DkStep(typename Unk_DkMap<N>::type::iterator& it)
{
    --it;
}
template <int N> void Unk_DkRev(std::reverse_iterator<typename Unk_DkMap<N>::type::iterator>& it)
{
    ++it;
}
template <int N> void Unk_DkConst(typename Unk_DkMap<N>::type::const_iterator& it)
{
    --it;
}

void Unk_DkAnchor()
{
    Unk_DkMap<1>::type::iterator it1;
    Unk_DkStep<1>(it1);
    Unk_DkMap<2>::type::iterator it2;
    Unk_DkStep<2>(it2);
    Unk_DkMap<3>::type::iterator it3;
    Unk_DkStep<3>(it3);
    Unk_DkMap<4>::type::iterator it4;
    Unk_DkStep<4>(it4);
    Unk_DkMap<5>::type::iterator it5;
    Unk_DkStep<5>(it5);
    Unk_DkMap<6>::type::iterator it6;
    Unk_DkStep<6>(it6);
    Unk_DkMap<7>::type::iterator it7;
    Unk_DkStep<7>(it7);
    Unk_DkMap<8>::type::iterator it8;
    Unk_DkStep<8>(it8);
    Unk_DkMap<9>::type::iterator it9;
    Unk_DkStep<9>(it9);
    Unk_DkMap<10>::type::iterator it10;
    Unk_DkStep<10>(it10);
    Unk_DkMap<11>::type::iterator it11;
    Unk_DkStep<11>(it11);
    Unk_DkMap<12>::type::iterator it12;
    Unk_DkStep<12>(it12);
    Unk_DkMap<13>::type::iterator it13;
    Unk_DkStep<13>(it13);
    Unk_DkMap<14>::type::iterator it14;
    Unk_DkStep<14>(it14);
    Unk_DkMap<15>::type::iterator it15;
    Unk_DkStep<15>(it15);
    Unk_DkMap<16>::type::iterator it16;
    Unk_DkStep<16>(it16);
    Unk_DkMap<17>::type::iterator it17;
    Unk_DkStep<17>(it17);
    Unk_DkMap<18>::type::iterator it18;
    Unk_DkStep<18>(it18);
    Unk_DkMap<19>::type::iterator it19;
    Unk_DkStep<19>(it19);
    Unk_DkMap<20>::type::iterator it20;
    Unk_DkStep<20>(it20);
    Unk_DkMap<21>::type::iterator it21;
    Unk_DkStep<21>(it21);
    Unk_DkMap<22>::type::iterator it22;
    Unk_DkStep<22>(it22);
    Unk_DkMap<23>::type::iterator it23;
    Unk_DkStep<23>(it23);
    Unk_DkMap<24>::type::iterator it24;
    Unk_DkStep<24>(it24);
    Unk_DkMap<25>::type::iterator it25;
    Unk_DkStep<25>(it25);
    Unk_DkMap<26>::type::iterator it26;
    Unk_DkStep<26>(it26);
    Unk_DkMap<27>::type::iterator it27;
    Unk_DkStep<27>(it27);
    Unk_DkMap<28>::type::iterator it28;
    Unk_DkStep<28>(it28);
    Unk_DkMap<29>::type::iterator it29;
    Unk_DkStep<29>(it29);
    std::reverse_iterator<Unk_DkMap<1>::type::iterator> rit1;
    Unk_DkRev<1>(rit1);
    std::reverse_iterator<Unk_DkMap<2>::type::iterator> rit2;
    Unk_DkRev<2>(rit2);
    std::reverse_iterator<Unk_DkMap<3>::type::iterator> rit3;
    Unk_DkRev<3>(rit3);
    std::reverse_iterator<Unk_DkMap<4>::type::iterator> rit4;
    Unk_DkRev<4>(rit4);
    std::reverse_iterator<Unk_DkMap<5>::type::iterator> rit5;
    Unk_DkRev<5>(rit5);
    std::reverse_iterator<Unk_DkMap<6>::type::iterator> rit6;
    Unk_DkRev<6>(rit6);
    std::reverse_iterator<Unk_DkMap<7>::type::iterator> rit7;
    Unk_DkRev<7>(rit7);
    std::reverse_iterator<Unk_DkMap<8>::type::iterator> rit8;
    Unk_DkRev<8>(rit8);
    std::reverse_iterator<Unk_DkMap<9>::type::iterator> rit9;
    Unk_DkRev<9>(rit9);
    std::reverse_iterator<Unk_DkMap<10>::type::iterator> rit10;
    Unk_DkRev<10>(rit10);
    std::reverse_iterator<Unk_DkMap<11>::type::iterator> rit11;
    Unk_DkRev<11>(rit11);
    std::reverse_iterator<Unk_DkMap<12>::type::iterator> rit12;
    Unk_DkRev<12>(rit12);
    std::reverse_iterator<Unk_DkMap<13>::type::iterator> rit13;
    Unk_DkRev<13>(rit13);
    std::reverse_iterator<Unk_DkMap<14>::type::iterator> rit14;
    Unk_DkRev<14>(rit14);
    std::reverse_iterator<Unk_DkMap<15>::type::iterator> rit15;
    Unk_DkRev<15>(rit15);
    std::reverse_iterator<Unk_DkMap<16>::type::iterator> rit16;
    Unk_DkRev<16>(rit16);
    std::reverse_iterator<Unk_DkMap<17>::type::iterator> rit17;
    Unk_DkRev<17>(rit17);
    std::reverse_iterator<Unk_DkMap<18>::type::iterator> rit18;
    Unk_DkRev<18>(rit18);
    std::reverse_iterator<Unk_DkMap<19>::type::iterator> rit19;
    Unk_DkRev<19>(rit19);
    std::reverse_iterator<Unk_DkMap<20>::type::iterator> rit20;
    Unk_DkRev<20>(rit20);
    std::reverse_iterator<Unk_DkMap<21>::type::iterator> rit21;
    Unk_DkRev<21>(rit21);
    std::reverse_iterator<Unk_DkMap<22>::type::iterator> rit22;
    Unk_DkRev<22>(rit22);
    std::reverse_iterator<Unk_DkMap<23>::type::iterator> rit23;
    Unk_DkRev<23>(rit23);
    std::reverse_iterator<Unk_DkMap<24>::type::iterator> rit24;
    Unk_DkRev<24>(rit24);
    std::reverse_iterator<Unk_DkMap<25>::type::iterator> rit25;
    Unk_DkRev<25>(rit25);
}


// Cube point arithmetic (0x1408a85a0 constructs the result).
struct Unk_DkPoint : public Unk_Int3
{
    Unk_Int3 operator-(const Unk_DkPoint& o) const { return Unk_Int3(x - o.x, y - o.y, z - o.z); }
    Unk_Int3 operator+(const Unk_DkPoint& o) const { return Unk_Int3(x + o.x, y + o.y, z + o.z); }
};
Unk_Int3 Unk_DkSub(const Unk_DkPoint& a, const Unk_DkPoint& b) { return a - b; }
Unk_Int3 Unk_DkAdd(const Unk_DkPoint& a, const Unk_DkPoint& b) { return a + b; }

unsigned __int64 FUN_1411283f0(const void* pLink);
unsigned __int64 FUN_1409657b0(const void* pPtr);
struct Unk_DkLessLink { bool operator()(const void* a, const void* b) const { return FUN_1411283f0(a) < FUN_1411283f0(b); } };
struct Unk_DkLessPtr { bool operator()(const void* a, const void* b) const { return FUN_1409657b0(a) < FUN_1409657b0(b); } };
struct Unk_DkLessInt { bool operator()(const int& a, const int& b) const { return a < b; } };
struct Unk_DkLessInt2 { bool operator()(const int& a, const int& b) const { return a < b; } };
void Unk_DkLessAnchor(const void* a, const void* b, const int& c, const int& d)
{
    Unk_DkLessLink()(a, b);
    Unk_DkLessPtr()(a, b);
    Unk_DkLessInt()(c, d);
    Unk_DkLessInt2()(c, d);
}

// Sorts entities by their distance to the player (the lambda's capture) from the banner-style point property 0xfd95ca52.
extern Vector3 DAT_143b01a60;                       // the zero point
void FUN_1409618c0(Unk_Entity* pEntity, unsigned nProperty, Vector3* pOut);   // reads a point property
float FUN_140966f00(NiPoint3 kA, Vector3 kB);       // the distance

struct Unk_DkNearer
{
    GameObject* m_pPlayer;
    // @0x14112cbc0
    // MS2-FUNCTIONAL: register allocation of the copied 12-byte points differs
    bool operator()(Unk_EntRef kA, Unk_EntRef kB) const
    {
        NiPoint3 kPlayer = m_pPlayer->vfunc_18();
        Vector3 kPosA = DAT_143b01a60;
        Vector3 kPosB = DAT_143b01a60;
        FUN_1409618c0(kA.FUN_1408a9280(), 0xfd95ca52, &kPosA);
        FUN_1409618c0(kB.FUN_1408a9280(), 0xfd95ca52, &kPosB);
        float fA = FUN_140966f00(kPlayer, kPosA);
        float fB = FUN_140966f00(kPlayer, kPosB);
        return fA < fB;
    }
};
bool Unk_DkNearerAnchor(GameObject* pPlayer, Unk_EntRef kA, Unk_EntRef kB)
{
    Unk_DkNearer kLess = { pPlayer };
    return kLess(kA, kB);
}
