// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Template glue in front of WorldService's own range: the shared
// std::map / std::set / std::list / std::vector members of the instantiations over WorldService's per-member element types
// (see client/ms2/worldservice.h). File and function names are invented.
// MS2-UNIT: unit_141bb15d0
// MS2-RANGE: 0x141bb15d0-0x141bb9720 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ?clear@?$vector@UUnk_WsV9a0@@V?$allocator@UUnk_WsV9a0@@@std@@@std@@QEAAXXZ 0x141bb7960
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tset_traits@PEAXU?$less@PEAX@std@@V?$allocator@PEAX@2@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@PEAXPEAX@2@@Z 0x141bb2540
// MS2-PIN: ?_Tidy@?$vector@UUnk_WsN1@@V?$allocator@UUnk_WsN1@@@std@@@std@@AEAAXXZ 0x141bb6e60
// MS2-PIN: ?_Tidy@?$vector@UUnk_WsN2@@V?$allocator@UUnk_WsN2@@@std@@@std@@AEAAXXZ 0x141bb6d90
// MS2-PIN: ?ReleaseImpl@?$MS2Ptr@VUnk_WsK_Rank@@@@AEAAXPEAX@Z 0x141bb6440
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// The exe's MS2Ptr<Unk_WsK_Rank> reaches its CPtred through a helper (a down-adjust by -0x18 with a null test), not the
// inline upcast of ms2ptr_impl.h.
CPtred* FUN_141bb0630(Unk_WsK_Rank* p);
void FUN_141bb1410(CPtred* p);
template <> void MS2Ptr<Unk_WsK_Rank>::ReleaseImpl(void*)
{
    CPtred* p = FUN_141bb0630(m_p);
    if (CPtred::ReleasePtred(p) == 0)
    {
        FUN_141bb1410(p);
        CPtred::DeletePtred(p);
    }
}

// Not WorldService::m_980's map: this copy is unsigned-keyed (find 0x141bb8e00 / lower_bound 0x141bb91a0 call
// less<unsigned> 0x140185090) and its erase (0x141bb8750) destroys a non-trivial value (0x141babd70), while m_980's own
// family in worldservice.cpp#3 (erase 0x141c2d170 -> destroy 0x141bedc50) is u64-keyed and trivially destructible.
// Own stand-in so the two families do not share one mangled name.
struct Unk_WsV980g { void* p; void* q; };   // 16 bytes: allocate 0x141bb71d0 asks _Get_size_of_n<56>

template class std::set<void*>;
template class std::map<unsigned __int64, Unk_WsV1d8>;
template class std::map<int, std::set<unsigned __int64> >;
template class std::map<int, Unk_WsV1f8>;
template class std::map<unsigned __int64, Unk_WsV2e8>;
template class std::set<unsigned __int64>;
template class std::map<unsigned __int64, Unk_WsPod8>;
template class std::map<unsigned, Unk_WsV980g>;
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
void Unk_WsAnchorGlue()
{
    std::map<unsigned __int64, Unk_WsV1d8> a0; Unk_WsTouchTree(a0, 0);
    std::map<int, Unk_WsV1f8> a1; Unk_WsTouchTree(a1, 0);
    std::map<unsigned __int64, Unk_WsV2e8> a2; Unk_WsTouchTree(a2, 0);
    std::map<unsigned __int64, Unk_WsPod8> a3; Unk_WsTouchTree(a3, 0);
    std::map<unsigned, Unk_WsV980g> a4; Unk_WsTouchTree(a4, 0);
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
    (void)b6.empty();
    char mb[1], mc[1];
    (void)memmove_s(mb, 1, mc, 1);
    std::set<void*> c0; Unk_WsTouchSet(c0, 0);
    std::set<unsigned __int64> c1; Unk_WsTouchSet(c1, 0);
    std::set<unsigned> c2; Unk_WsTouchSet(c2, 0);
    std::set<int> c3; Unk_WsTouchSet(c3, 0);
}
// px1 2026-10-20: tplpin --simulate pins (look-alike template copies)
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsF3@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF3@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF3@@@std@@PEAX@2@XZ 0x141bb1690
// MS2-PIN: ?_Buyheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_WsV980g@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsV980g@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@2@XZ 0x141bb18d0
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_WsF6@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsF6@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsF6@@@std@@PEAX@2@XZ 0x141bb1a50
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsF3@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF3@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF3@@@std@@PEAX@2@XZ 0x141bb1b30
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsF5@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF5@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF5@@@std@@PEAX@2@XZ 0x141bb1c10
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_WsF1@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsF1@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsF1@@@std@@PEAX@2@XZ 0x141bb1dd0
// MS2-PIN: ?_Buynode0@?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsPod8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsPod8@@@std@@@3@$0A@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsPod8@@@std@@PEAX@2@XZ 0x141bb1eb0
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_WsF0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsF0@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141bb2130
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_WsF4@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsF4@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141bb2170
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBH0@Z 0x141bb21f0
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IUUnk_WsF1@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsF1@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x141bb2230
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IUUnk_WsF6@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsF6@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x141bb2270
// MS2-PIN: ?_Compare@?$_Tree@V?$_Tmap_traits@IUUnk_WsVac0@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsVac0@@@std@@@3@$0A@@std@@@std@@IEBA_NAEBI0@Z 0x141bb22b0
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_WsF6@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsF6@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x141bb22f0
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@_KUUnk_WsF3@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF3@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x141bb2320
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tset_traits@PEAXU?$less@PEAX@std@@V?$allocator@PEAX@2@$0A@@std@@@std@@QEAAXXZ 0x141bb2350
// MS2-PIN: ?_Construct@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x141bb23e0
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF2@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF2@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF2@@@std@@PEAX@2@@Z 0x141bb2450
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF5@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF5@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF5@@@std@@PEAX@2@@Z 0x141bb24f0
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF7@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF7@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF7@@@std@@PEAX@2@@Z 0x141bb2590
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@_KUUnk_WsG0@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsG0@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsG0@@@std@@PEAX@2@@Z 0x141bb25e0
// MS2-PIN: ?_Destroy_if_node@?$_Tree@V?$_Tmap_traits@_KUUnk_WsPod8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsPod8@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsPod8@@@std@@PEAX@2@@Z 0x141bb2630
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF2@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF2@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF2@@@std@@PEAX@2@@Z 0x141bb2680
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF3@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF3@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF3@@@std@@PEAX@2@@Z 0x141bb2720
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF7@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF7@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF7@@@std@@PEAX@2@@Z 0x141bb2860
// MS2-PIN: ?_Erase@?$_Tree@V?$_Tmap_traits@_KUUnk_WsPod8@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsPod8@@@std@@@3@$0A@@std@@@std@@IEAAXPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsPod8@@@std@@PEAX@2@@Z 0x141bb29a0
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@PEAXPEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@PEAX@std@@@std@@@2@@Z 0x141bb35a0
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@2@@Z 0x141bb46b0
// MS2-PIN: ??$_Get_unwrapped@$$CBU?$pair@$$CBHUUnk_WsF4@@@std@@@std@@YAPEBU?$pair@$$CBHUUnk_WsF4@@@0@QEBU10@@Z 0x141bb5160
// MS2-PIN: ??$_Get_unwrapped@$$CBU?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@YAPEBU?$pair@$$CBHUUnk_WsV1f8@@@0@QEBU10@@Z 0x141bb5170
// MS2-PIN: ??$_Get_unwrapped@$$CBU?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@YAPEBU?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@0@QEBU10@@Z 0x141bb5180
// MS2-PIN: ??$_Get_unwrapped@$$CBU?$pair@$$CBIUUnk_WsVac0@@@std@@@std@@YAPEBU?$pair@$$CBIUUnk_WsVac0@@@0@QEBU10@@Z 0x141bb51b0
// MS2-PIN: ??$_Get_unwrapped@$$CBU?$pair@$$CB_KUUnk_WsF3@@@std@@@std@@YAPEBU?$pair@$$CB_KUUnk_WsF3@@@0@QEBU10@@Z 0x141bb51d0
// MS2-PIN: ??$_Get_unwrapped@$$CBU?$pair@$$CB_KUUnk_WsF5@@@std@@@std@@YAPEBU?$pair@$$CB_KUUnk_WsF5@@@0@QEBU10@@Z 0x141bb51e0
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsF0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsF0@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsF0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsF0@@@std@@@std@@@2@$00@2@XZ 0x141bb52e0
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@H@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@2@$00@2@XZ 0x141bb5320
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsF1@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsF1@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsF1@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsF1@@@std@@@std@@@2@$00@2@XZ 0x141bb5360
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsF0@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsF0@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsF0@@@std@@@std@@@2@XZ 0x141bb53a0
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsF4@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsF4@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsF4@@@std@@@std@@@2@XZ 0x141bb53c0
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@2@XZ 0x141bb53e0
// MS2-PIN: ?_Get_second@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsF1@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsF1@@@std@@@std@@@2@$00@std@@QEBAAEBV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsF1@@@std@@@std@@@2@XZ 0x141bb5420
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@HUUnk_WsF0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsF0@@@std@@@3@$0A@@std@@@std@@QEAAAEAU?$less@H@2@XZ 0x141bb5770
// MS2-PIN: ?_Getcomp@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_WsVac0@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsVac0@@@std@@@3@$0A@@std@@@std@@QEBAAEBU?$less@I@2@XZ 0x141bb5870
// MS2-PIN: ?_Kfn@?$_Tree@V?$_Tmap_traits@IUUnk_WsVac0@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsVac0@@@std@@@3@$0A@@std@@@std@@IEBAAEBIAEBU?$pair@$$CBIUUnk_WsVac0@@@2@@Z 0x141bb5af0
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@2@XZ 0x141bb5b60
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@PEAX@std@@@std@@QEAAXPEAU?$_Tree_node@PEAXPEAX@2@@Z 0x141bb5d30
// MS2-PIN: ?_Lrotate@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@2@@Z 0x141bb5fd0
// MS2-PIN: ?_Max@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@2@PEAU32@@Z 0x141bb61a0
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@PEAX@std@@@std@@SAPEAU?$_Tree_node@PEAXPEAX@2@PEAU32@@Z 0x141bb6230
// MS2-PIN: ?_Min@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsF4@@@std@@@std@@@std@@SAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsF4@@@std@@PEAX@2@PEAU32@@Z 0x141bb6290
// MS2-PIN: ?Release@?$MS2Ptr@VUnk_WsK_Rank@@@@AEAAXXZ 0x141bb63e0
// MS2-PIN: ?_Rmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@2@XZ 0x141bb6530
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@PEAX@std@@@std@@QEBAAEAPEAU?$_Tree_node@PEAXPEAX@2@XZ 0x141bb6590
// MS2-PIN: ?_Root@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHUUnk_WsV1f8@@@std@@PEAX@2@XZ 0x141bb65f0
// MS2-PIN: ?_Rrotate@?$_Tree_val@U?$_Tree_simple_types@PEAX@std@@@std@@QEAAXPEAU?$_Tree_node@PEAXPEAX@2@@Z 0x141bb67d0
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IUUnk_WsF6@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsF6@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x141bb6b50
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@IUUnk_WsF1@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsF1@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x141bb6c70
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HUUnk_WsF4@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsF4@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x141bb6cd0
// MS2-PIN: ?_Tidy@?$_Tree@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@IEAAXXZ 0x141bb6d30
// MS2-PIN: ?_Lmost@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@QEBAAEAPEAU?$_Tree_node@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@PEAX@2@XZ 0x141bb70e0
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsF2@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF2@@@std@@PEAX@2@_K@Z 0x141bb7110
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CB_KUUnk_WsF3@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CB_KUUnk_WsF3@@@std@@PEAX@2@_K@Z 0x141bb7140
// MS2-PIN: ?allocate@?$allocator@UUnk_WsN3@@@std@@QEAAPEAUUnk_WsN3@@_K@Z 0x141bb7230
// MS2-PIN: ?begin@?$_Tree@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@2@XZ 0x141bb7490
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF3@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF3@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x141bb7640
// MS2-PIN: ?clear@?$_Tree@V?$_Tset_traits@PEAXU?$less@PEAX@std@@V?$allocator@PEAX@2@$0A@@std@@@std@@QEAAXXZ 0x141bb76e0
// MS2-PIN: ?clear@?$_Tree@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@QEAAXXZ 0x141bb78c0
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF3@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF3@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsF3@@@std@@@std@@@std@@@2@XZ 0x141bb7cf0
// MS2-PIN: ?end@?$_Tree@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@2@XZ 0x141bb7e70
// MS2-PIN: ?end@?$vector@UUnk_WsVa18@@V?$allocator@UUnk_WsVa18@@@std@@@std@@QEBA?AV?$_Vector_const_iterator@V?$_Vector_val@U?$_Simple_types@UUnk_WsVa18@@@std@@@std@@@2@XZ 0x141bb7ed0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IUUnk_WsF6@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsF6@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsF6@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsF6@@@std@@@std@@@std@@@2@0@Z 0x141bb7f70
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF2@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF2@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsF2@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsF2@@@std@@@std@@@std@@@2@@Z 0x141bb8060
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF3@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF3@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsF3@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsF3@@@std@@@std@@@std@@@2@0@Z 0x141bb8110
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF3@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF3@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsF3@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsF3@@@std@@@std@@@std@@@2@@Z 0x141bb8200
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HUUnk_WsF0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsF0@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsF0@@@std@@@std@@@std@@@2@AEBH@Z 0x141bb8b60
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IUUnk_WsF6@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsF6@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsF6@@@std@@@std@@@std@@@2@AEBI@Z 0x141bb8fc0
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF3@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF3@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsF3@@@std@@@std@@@std@@@2@AEB_K@Z 0x141bb9020
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HUUnk_WsF0@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsF0@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsF0@@@std@@@std@@@std@@@2@AEBH@Z 0x141bb9080
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF2@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF2@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_KUUnk_WsF2@@@std@@@std@@@std@@@2@AEB_K@Z 0x141bb90e0
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@IUUnk_WsF1@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsF1@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsF1@@@std@@@std@@@std@@@2@AEBI@Z 0x141bb91a0
// MS2-PIN: ?lower_bound@?$_Tree@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@2@AEBH@Z 0x141bb9200
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@HV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@2@$0A@@std@@@std@@QEBA_KXZ 0x141bb92e0
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF2@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF2@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141bb9300
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF3@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF3@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141bb9320
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF5@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF5@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141bb9360
// MS2-PIN: ?max_size@?$_Tree@V?$_Tmap_traits@_KUUnk_WsF7@@U?$less@_K@std@@V?$allocator@U?$pair@$$CB_KUUnk_WsF7@@@std@@@3@$0A@@std@@@std@@QEBA_KXZ 0x141bb9380
// px10 2026-10-21: Unk_WsV980g (glue-only stand-in, see above) takes over the glue-range copies the old Unk_WsV980 rows named
// MS2-PIN: ?_Extract@?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsV980g@@@std@@@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsV980g@@@std@@@std@@@std@@@2@@Z 0x141bb4100
// MS2-PIN: ?_Freeheadnode@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_WsV980g@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsV980g@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@2@@Z 0x141bb4d20
// MS2-PIN: ?_Freenode0@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_WsV980g@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsV980g@@@std@@@3@$0A@@std@@@std@@QEAAXPEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@2@@Z 0x141bb4e40
// MS2-PIN: ?_Get_data@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_WsV980g@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsV980g@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsV980g@@@std@@@std@@@2@XZ 0x141bb5020
// MS2-PIN: ?_Get_first@?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsV980g@@@std@@@std@@@2@$00@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@std@@@2@XZ 0x141bb5270
// MS2-PIN: ?_Get_second@?$_Compressed_pair@U?$less@I@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsV980g@@@std@@@std@@@2@$00@2@$00@std@@QEAAAEAV?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsV980g@@@std@@@std@@@2@$00@2@XZ 0x141bb5350
// MS2-PIN: ?_Getal@?$_Tree_comp_alloc@V?$_Tmap_traits@IUUnk_WsV980g@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsV980g@@@std@@@3@$0A@@std@@@std@@QEAAAEAV?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@std@@@2@XZ 0x141bb55f0
// MS2-PIN: ?allocate@?$allocator@U?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@std@@@std@@QEAAPEAU?$_Tree_node@U?$pair@$$CBIUUnk_WsV980g@@@std@@PEAX@2@_K@Z 0x141bb71d0
// MS2-PIN: ?erase@?$_Tree@V?$_Tmap_traits@IUUnk_WsV980g@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIUUnk_WsV980g@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsV980g@@@std@@@std@@@std@@@2@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIUUnk_WsV980g@@@std@@@std@@@std@@@2@@Z 0x141bb8750
// px10: the int-keyed find copies (they call less<int> 0x1401f1b70) get int-keyed names
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HUUnk_WsF4@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsF4@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsF4@@@std@@@std@@@std@@@2@AEBH@Z 0x141bb89a0
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HUUnk_WsV1f8@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@3@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHUUnk_WsV1f8@@@std@@@std@@@std@@@2@AEBH@Z 0x141bb8a80
// MS2-PIN: ?find@?$_Tree@V?$_Tmap_traits@HV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@U?$less@H@2@V?$allocator@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@2@$0A@@std@@@std@@QEAA?AV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$set@_KU?$less@_K@std@@V?$allocator@_K@2@@std@@@std@@@std@@@std@@@2@AEBH@Z 0x141bb8c40
