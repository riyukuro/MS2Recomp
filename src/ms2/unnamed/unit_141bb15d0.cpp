// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Template glue in front of WorldService's own range: the shared
// std::map / std::set / std::list / std::vector members of the instantiations over WorldService's per-member element types
// (see client/ms2/worldservice.h). File and function names are invented.
// MS2-UNIT: unit_141bb15d0
// MS2-RANGE: 0x141bb15d0-0x141bb9720 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/ms2ptr_impl.h"

template class std::set<void*>;
template class std::map<unsigned __int64, Unk_WsV1d8>;
template class std::map<int, std::set<unsigned __int64> >;
template class std::map<int, Unk_WsV1f8>;
template class std::map<unsigned __int64, Unk_WsV2e8>;
template class std::set<unsigned __int64>;
template class std::map<unsigned __int64, Unk_WsPod8>;
template class std::map<unsigned __int64, Unk_WsV980>;
template class std::map<unsigned __int64, Unk_WsV990>;
template class std::vector<Unk_WsV9a0>;
template class std::vector<Unk_WsVa00>;
template class std::vector<Unk_WsVa18>;
template class std::map<unsigned __int64, Unk_WsVab0>;
template class std::map<unsigned, Unk_WsVac0>;
template class std::map<unsigned __int64, Unk_WsVad0>;
template class std::set<unsigned>;
template class std::set<int>;
template class std::vector<unsigned>;

// Stand-in families: the exe has more 0x38-node (key + 16-byte value) map instantiations in this zone than WorldService's
// named members account for; the value types are not recovered (only their size).
struct Unk_WsF0 { unsigned char raw[16]; };
struct Unk_WsF1 { unsigned char raw[16]; };
struct Unk_WsF2 { unsigned char raw[16]; };
struct Unk_WsF3 { unsigned char raw[16]; };
// 16-byte vector elements with a destructor (the exe's _Tidy of these vectors sits here; their other members are elsewhere).
struct Unk_WsN0 { void* p0; void* p1; ~Unk_WsN0() {} };
struct Unk_WsN1 { void* p0; void* p1; ~Unk_WsN1() {} };
struct Unk_WsN2 { void* p0; void* p1; ~Unk_WsN2() {} };
template class std::vector<Unk_WsN0>;
template class std::vector<Unk_WsN1>;
template class std::vector<Unk_WsN2>;
struct Unk_WsN3 { void* p0; void* p1; ~Unk_WsN3() {} };
template class std::vector<Unk_WsN3>;
struct Unk_WsN4 { void* p0; void* p1; ~Unk_WsN4() {} };
struct Unk_WsN5 { void* p0; void* p1; ~Unk_WsN5() {} };
template class std::vector<Unk_WsN4>;
template class std::vector<Unk_WsN5>;
struct Unk_WsG0 { unsigned char raw[24]; };
template class std::map<unsigned __int64, Unk_WsG0>;
template class std::map<int, Unk_WsF0>;
template class std::map<unsigned, Unk_WsF1>;
template class std::map<unsigned __int64, Unk_WsF2>;
template class std::map<unsigned __int64, Unk_WsF3>;
struct Unk_WsF4 { unsigned char raw[16]; };
struct Unk_WsF5 { unsigned char raw[16]; };
struct Unk_WsF6 { unsigned char raw[16]; };
struct Unk_WsF7 { unsigned char raw[16]; };
template class std::map<int, Unk_WsF4>;
template class std::map<unsigned __int64, Unk_WsF5>;
template class std::map<unsigned, Unk_WsF6>;
template class std::map<unsigned __int64, Unk_WsF7>;

// Anchor: the member templates (find/erase/insert/operator[]/iterators) that the class instantiations above do not reach.
template <class M> void Unk_WsTouchTree(M& m, typename M::key_type k)
{
    typename M::iterator it = m.find(k);
    if (it != m.end())
        m.erase(it);
    m.erase(k);
    m.insert(typename M::value_type(k, typename M::mapped_type()));
    m[k];
    (void)m.count(k);
    (void)m.lower_bound(k);
    for (typename M::iterator i = m.begin(); i != m.end(); ++i)
        ;
    for (typename M::iterator i = m.begin(); i != m.end(); i++)
        ;
    for (typename M::iterator i = m.end(); i != m.begin(); --i)
        ;
    for (typename M::const_iterator i = m.begin(); i != m.end(); ++i)
        ;
}
template <class S> void Unk_WsTouchSet(S& s, typename S::key_type k)
{
    typename S::iterator it = s.find(k);
    if (it != s.end())
        s.erase(it);
    s.erase(k);
    s.insert(k);
    (void)s.count(k);
    for (typename S::iterator i = s.begin(); i != s.end(); ++i)
        ;
    for (typename S::iterator i = s.end(); i != s.begin(); --i)
        ;
}
void Unk_WsAnchor()
{
    std::map<unsigned __int64, Unk_WsV1d8> a0; Unk_WsTouchTree(a0, 0);
    std::map<int, Unk_WsV1f8> a1; Unk_WsTouchTree(a1, 0);
    std::map<unsigned __int64, Unk_WsV2e8> a2; Unk_WsTouchTree(a2, 0);
    std::map<unsigned __int64, Unk_WsPod8> a3; Unk_WsTouchTree(a3, 0);
    std::map<unsigned __int64, Unk_WsV980> a4; Unk_WsTouchTree(a4, 0);
    std::map<unsigned __int64, Unk_WsV990> a5; Unk_WsTouchTree(a5, 0);
    std::map<unsigned __int64, Unk_WsVab0> a6; Unk_WsTouchTree(a6, 0);
    std::map<unsigned, Unk_WsVac0> a7; Unk_WsTouchTree(a7, 0);
    std::map<unsigned __int64, Unk_WsVad0> a8; Unk_WsTouchTree(a8, 0);
    std::map<int, std::set<unsigned __int64> > a9; Unk_WsTouchTree(a9, 0);
    std::map<int, Unk_WsF0> b0; Unk_WsTouchTree(b0, 0);
    std::map<unsigned, Unk_WsF1> b1; Unk_WsTouchTree(b1, 0);
    std::map<unsigned __int64, Unk_WsF2> b2; Unk_WsTouchTree(b2, 0);
    std::map<unsigned __int64, Unk_WsF3> b3; Unk_WsTouchTree(b3, 0);
    std::map<int, Unk_WsF4> b4; Unk_WsTouchTree(b4, 0);
    std::map<unsigned __int64, Unk_WsF5> b5; Unk_WsTouchTree(b5, 0);
    std::map<unsigned, Unk_WsF6> b6; Unk_WsTouchTree(b6, 0);
    std::map<unsigned __int64, Unk_WsF7> b7; Unk_WsTouchTree(b7, 0);
    std::map<unsigned __int64, Unk_WsG0> g0; Unk_WsTouchTree(g0, 0);
    std::set<void*> c0; Unk_WsTouchSet(c0, 0);
    std::set<unsigned __int64> c1; Unk_WsTouchSet(c1, 0);
    std::set<unsigned> c2; Unk_WsTouchSet(c2, 0);
    std::set<int> c3; Unk_WsTouchSet(c3, 0);
}
