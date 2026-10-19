// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). std::map iterator decrement glue: 11 map families whose key
// and value types are not recoverable from the byte-identical bodies (they differ only by the tree-max function). Each family
// contributes _Tree_const_iterator::operator-- (calls the family's _Max), _Tree_iterator::operator-- (calls the const
// iterator's); nine also have the std::reverse_iterator::operator++ over it.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_141bf8d60
// MS2-RANGE: 0x141bf8d60-0x141bf98d0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <iterator>
#include "ms2/ms2recover.h"

// Stand-in key of the Nth map family.
template <int N> struct Unk_BfKey { int v[N + 1]; bool operator<(const Unk_BfKey& o) const { return v[0] < o.v[0]; } };
template <int N> struct Unk_BfMap { typedef std::map<Unk_BfKey<N>, int> type; };

template <int N> void Unk_BfStep(typename Unk_BfMap<N>::type::iterator& it)
{
    --it;
}
template <int N> void Unk_BfRev(std::reverse_iterator<typename Unk_BfMap<N>::type::iterator>& it)
{
    ++it;
}

void Unk_BfAnchor()
{
    Unk_BfMap<1>::type::iterator it1;
    Unk_BfStep<1>(it1);
    Unk_BfMap<2>::type::iterator it2;
    Unk_BfStep<2>(it2);
    Unk_BfMap<3>::type::iterator it3;
    Unk_BfStep<3>(it3);
    Unk_BfMap<4>::type::iterator it4;
    Unk_BfStep<4>(it4);
    Unk_BfMap<5>::type::iterator it5;
    Unk_BfStep<5>(it5);
    Unk_BfMap<6>::type::iterator it6;
    Unk_BfStep<6>(it6);
    Unk_BfMap<7>::type::iterator it7;
    Unk_BfStep<7>(it7);
    Unk_BfMap<8>::type::iterator it8;
    Unk_BfStep<8>(it8);
    Unk_BfMap<9>::type::iterator it9;
    Unk_BfStep<9>(it9);
    Unk_BfMap<10>::type::iterator it10;
    Unk_BfStep<10>(it10);
    Unk_BfMap<11>::type::iterator it11;
    Unk_BfStep<11>(it11);
    std::reverse_iterator<Unk_BfMap<1>::type::iterator> rit1;
    Unk_BfRev<1>(rit1);
    std::reverse_iterator<Unk_BfMap<2>::type::iterator> rit2;
    Unk_BfRev<2>(rit2);
    std::reverse_iterator<Unk_BfMap<3>::type::iterator> rit3;
    Unk_BfRev<3>(rit3);
    std::reverse_iterator<Unk_BfMap<4>::type::iterator> rit4;
    Unk_BfRev<4>(rit4);
    std::reverse_iterator<Unk_BfMap<5>::type::iterator> rit5;
    Unk_BfRev<5>(rit5);
    std::reverse_iterator<Unk_BfMap<6>::type::iterator> rit6;
    Unk_BfRev<6>(rit6);
    std::reverse_iterator<Unk_BfMap<7>::type::iterator> rit7;
    Unk_BfRev<7>(rit7);
    std::reverse_iterator<Unk_BfMap<8>::type::iterator> rit8;
    Unk_BfRev<8>(rit8);
    std::reverse_iterator<Unk_BfMap<9>::type::iterator> rit9;
    Unk_BfRev<9>(rit9);
}
