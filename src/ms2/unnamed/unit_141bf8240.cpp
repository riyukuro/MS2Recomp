// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). std::map iterator increment glue: 10 map families whose key and
// value types are not recoverable from the byte-identical bodies (they differ only by the tree-min function). Each family
// contributes _Tree_const_iterator::operator++ (calls the family's _Min), _Tree_iterator::operator++ and the post-increment;
// seven also have the std::reverse_iterator::operator-- over it.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_141bf8240
// MS2-RANGE: 0x141bf8240-0x141bf8d20 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <iterator>
#include "ms2/ms2recover.h"

// Stand-in key of the Nth map family.
template <int N> struct Unk_BiKey { int v[N + 1]; bool operator<(const Unk_BiKey& o) const { return v[0] < o.v[0]; } };
template <int N> struct Unk_BiMap { typedef std::map<Unk_BiKey<N>, int> type; };

template <int N> void Unk_BiPre(typename Unk_BiMap<N>::type::iterator& it)
{
    ++it;
}
template <int N> typename Unk_BiMap<N>::type::iterator Unk_BiPost(typename Unk_BiMap<N>::type::iterator& it)
{
    return it++;
}
template <int N> void Unk_BiRev(std::reverse_iterator<typename Unk_BiMap<N>::type::iterator>& it)
{
    --it;
}

void Unk_BiAnchor()
{
    Unk_BiMap<1>::type::iterator it1;
    Unk_BiPre<1>(it1);
    Unk_BiPost<1>(it1);
    Unk_BiMap<2>::type::iterator it2;
    Unk_BiPre<2>(it2);
    Unk_BiPost<2>(it2);
    Unk_BiMap<3>::type::iterator it3;
    Unk_BiPre<3>(it3);
    Unk_BiPost<3>(it3);
    Unk_BiMap<4>::type::iterator it4;
    Unk_BiPre<4>(it4);
    Unk_BiPost<4>(it4);
    Unk_BiMap<5>::type::iterator it5;
    Unk_BiPre<5>(it5);
    Unk_BiPost<5>(it5);
    Unk_BiMap<6>::type::iterator it6;
    Unk_BiPre<6>(it6);
    Unk_BiPost<6>(it6);
    Unk_BiMap<7>::type::iterator it7;
    Unk_BiPre<7>(it7);
    Unk_BiPost<7>(it7);
    Unk_BiMap<8>::type::iterator it8;
    Unk_BiPre<8>(it8);
    Unk_BiPost<8>(it8);
    Unk_BiMap<9>::type::iterator it9;
    Unk_BiPre<9>(it9);
    Unk_BiPost<9>(it9);
    Unk_BiMap<10>::type::iterator it10;
    Unk_BiPre<10>(it10);
    Unk_BiPost<10>(it10);
    std::reverse_iterator<Unk_BiMap<4>::type::iterator> rit4;
    Unk_BiRev<4>(rit4);
    std::reverse_iterator<Unk_BiMap<5>::type::iterator> rit5;
    Unk_BiRev<5>(rit5);
    std::reverse_iterator<Unk_BiMap<6>::type::iterator> rit6;
    Unk_BiRev<6>(rit6);
    std::reverse_iterator<Unk_BiMap<7>::type::iterator> rit7;
    Unk_BiRev<7>(rit7);
    std::reverse_iterator<Unk_BiMap<8>::type::iterator> rit8;
    Unk_BiRev<8>(rit8);
    std::reverse_iterator<Unk_BiMap<9>::type::iterator> rit9;
    Unk_BiRev<9>(rit9);
    std::reverse_iterator<Unk_BiMap<10>::type::iterator> rit10;
    Unk_BiRev<10>(rit10);
}
