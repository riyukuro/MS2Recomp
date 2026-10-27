// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). COMDAT tail after unit_1404477b0: std::map<...>::operator[] and the
// _Tree iterator operator* / operator-> glue for the game-event value containers (element types not recovered yet:
// distinct stand-in value types, so each tree gets its own instance), vector<unsigned __int64>::operator[].
// MS2-UNIT: unit_140447ef0
// MS2-RANGE: 0x140447ef0-0x140448770 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??A?$map@IU?$Unk_Gev447V4@$06@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_Gev447V4@$06@@@std@@@3@@std@@QEAAAEAU?$Unk_Gev447V4@$06@@AEBI@Z 0x140447ef0 ; prop
// MS2-PIN: ??A?$map@IU?$Unk_Gev447V8@$01@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_Gev447V8@$01@@@std@@@3@@std@@QEAAAEAU?$Unk_Gev447V8@$01@@AEBI@Z 0x140447f70 ; prop
// MS2-PIN: ??A?$map@IU?$Unk_Gev447V8@$02@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_Gev447V8@$02@@@std@@@3@@std@@QEAAAEAU?$Unk_Gev447V8@$02@@AEBI@Z 0x140447fb0 ; prop
// MS2-PIN: ??A?$map@IU?$Unk_Gev447V8@$03@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_Gev447V8@$03@@@std@@@3@@std@@QEAAAEAU?$Unk_Gev447V8@$03@@AEBI@Z 0x140447ff0 ; prop
// MS2-PIN: ??A?$map@IU?$Unk_Gev447V8@$04@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_Gev447V8@$04@@@std@@@3@@std@@QEAAAEAU?$Unk_Gev447V8@$04@@AEBI@Z 0x140448030 ; prop
// MS2-PIN: ??A?$map@IU?$Unk_Gev447V8@$07@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_Gev447V8@$07@@@std@@@3@@std@@QEAAAEAU?$Unk_Gev447V8@$07@@AEBI@Z 0x140448070 ; prop
// MS2-PIN: ??A?$map@IU?$Unk_Gev447V4@$0A@@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIU?$Unk_Gev447V4@$0A@@@@std@@@3@@std@@QEAAAEAU?$Unk_Gev447V4@$0A@@@AEBI@Z 0x1404480b0 ; prop
// MS2-PIN: ??A?$map@U?$pair@IH@std@@U?$Unk_Gev447V4@$05@@U?$less@U?$pair@IH@std@@@2@V?$allocator@U?$pair@$$CBU?$pair@IH@std@@U?$Unk_Gev447V4@$05@@@std@@@2@@std@@QEAAAEAU?$Unk_Gev447V4@$05@@AEBU?$pair@IH@1@@Z 0x1404480f0 ; prop
// MS2-PIN: ??A?$vector@_KV?$allocator@_K@std@@@std@@QEAAAEA_K_K@Z 0x140448130 ; unique
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$00@@@@QEBAPEAU?$Unk_Gev447P@$00@@XZ 0x140448160 ; probe
// MS2-PIN: ?GetModuleInstance@CAtlBaseModule@ATL@@QEAAPEAUHINSTANCE__@@XZ 0x140448170 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$01@@@@QEBAPEAU?$Unk_Gev447P@$01@@XZ 0x140448180 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$02@@@@QEBAPEAU?$Unk_Gev447P@$02@@XZ 0x140448190 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$03@@@@QEBAPEAU?$Unk_Gev447P@$03@@XZ 0x1404481a0 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$04@@@@QEBAPEAU?$Unk_Gev447P@$04@@XZ 0x1404481b0 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$05@@@@QEBAPEAU?$Unk_Gev447P@$05@@XZ 0x1404481c0 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$06@@@@QEBAPEAU?$Unk_Gev447P@$06@@XZ 0x140448210 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$07@@@@QEBAPEAU?$Unk_Gev447P@$07@@XZ 0x140448220 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$08@@@@QEBAPEAU?$Unk_Gev447P@$08@@XZ 0x140448230 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$09@@@@QEBAPEAU?$Unk_Gev447P@$09@@XZ 0x140448240 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$0A@@@@@QEBAPEAU?$Unk_Gev447P@$0A@@@XZ 0x140448250 ; probe
// MS2-PIN: ??B?$MS2Ptr@U?$Unk_Gev447P@$0L@@@@@QEBAPEAU?$Unk_Gev447P@$0L@@@XZ 0x140448260 ; probe
// MS2-PIN: ??C?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$Unk_Gev447V4@$05@@@std@@@std@@@std@@@std@@QEBAPEBU?$pair@$$CBU?$pair@IH@std@@U?$Unk_Gev447V4@$05@@@1@XZ 0x140448290 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V4@$06@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBIU?$Unk_Gev447V4@$06@@@1@XZ 0x1404482f0 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$08@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBIU?$Unk_Gev447V8@$08@@@1@XZ 0x140448370 ; prop
// MS2-PIN: ??C?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V4@$0A@@@@std@@@std@@@std@@@std@@QEBAPEAU?$pair@$$CBIU?$Unk_Gev447V4@$0A@@@@1@XZ 0x1404483f0 ; prop
// MS2-PIN: ??D?$_List_const_iterator@V?$_List_val@U?$_List_simple_types@U?$Unk_Gev447V8@$0N@@@@std@@@std@@@std@@QEBAAEBU?$Unk_Gev447V8@$0N@@@XZ 0x140448430 ; prop
// MS2-PIN: ??D?$_List_iterator@V?$_List_val@U?$_List_simple_types@U?$Unk_Gev447V8@$0N@@@@std@@@std@@@std@@QEBAAEAU?$Unk_Gev447V8@$0N@@@XZ 0x140448450 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$Unk_Gev447V4@$05@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBU?$pair@IH@std@@U?$Unk_Gev447V4@$05@@@1@XZ 0x1404484b0 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$00@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBIU?$Unk_Gev447V8@$00@@@1@XZ 0x140448510 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$01@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBIU?$Unk_Gev447V8@$01@@@1@XZ 0x140448530 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$02@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBIU?$Unk_Gev447V8@$02@@@1@XZ 0x140448550 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$08@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBIU?$Unk_Gev447V8@$08@@@1@XZ 0x140448570 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$03@@@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBIU?$Unk_Gev447V8@$03@@@1@XZ 0x140448590 ; prop
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$00@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIU?$Unk_Gev447V8@$00@@@1@XZ 0x140448650 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$01@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIU?$Unk_Gev447V8@$01@@@1@XZ 0x140448670 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$02@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIU?$Unk_Gev447V8@$02@@@1@XZ 0x140448690 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$08@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIU?$Unk_Gev447V8@$08@@@1@XZ 0x1404486b0 ; prop
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$03@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIU?$Unk_Gev447V8@$03@@@1@XZ 0x1404486d0 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$04@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIU?$Unk_Gev447V8@$04@@@1@XZ 0x1404486f0 ; unique
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V8@$07@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIU?$Unk_Gev447V8@$07@@@1@XZ 0x140448750 ; la1: calls the V8<7> const operator* 140448610 (deepobj; 140448710 calls 1404485d0)
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBIU?$Unk_Gev447V4@$0A@@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBIU?$Unk_Gev447V4@$0A@@@@1@XZ 0x140448730 ; prop
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBU?$pair@IH@std@@U?$Unk_Gev447V4@$05@@@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBU?$pair@IH@std@@U?$Unk_Gev447V4@$05@@@1@XZ 0x140448710 ; la1: deep-matches 140448710/140448630 (V4 node layout), not 140448750
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_140447ef0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include <list>
#include <vector>
#include "ms2/ms2recover.h"
#include "ms2/commonfiles/fieldmetatable.h"

#include "hook/ms2hook.h"

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"

// Distinct stand-in element types: one per tree, the node layout is all the exe code shows.
template <int N> struct Unk_Gev447V4 { int raw; };          // value type of alignment 4
template <int N> struct Unk_Gev447V8 { void* raw; };        // value type of alignment 8
template <int N> struct Unk_Gev447P : CPtred { };           // pointee of an MS2Ptr stored in a tree

// operator[] with an lvalue key, begin()->, cbegin()->
template <class M, class K> void Unk_Gev447Use(M& m, const K& k)
{
    m[k];
    m.begin()->second;
    m.cbegin()->second;
}
// operator[] with an rvalue key
template <class M> void Unk_Gev447UseMove(M& m)
{
    m[1u];
    m.begin()->second;
}
template <class M> void Unk_Gev447UseIter(M& m)
{
    m.begin()->second;
}
template <class M> void Unk_Gev447UseConst(M& m)
{
    m.cbegin()->second;
}
template <int N> void Unk_Gev447Ptr()
{
    MS2Ptr<Unk_Gev447P<N> > p;
    (Unk_Gev447P<N>*)p;
}

void Unk_Gev447Anchor()
{
    unsigned k = 0;
    std::pair<unsigned, int> pk(0, 0);
    std::map<unsigned, Unk_Gev447V4<0> > m0; Unk_Gev447Use(m0, k);
    std::map<unsigned, Unk_Gev447V8<1> > m1; Unk_Gev447UseMove(m1);
    std::map<unsigned, Unk_Gev447V8<2> > m2; Unk_Gev447Use(m2, k);
    std::map<unsigned, Unk_Gev447V8<3> > m3; Unk_Gev447Use(m3, k);
    std::map<unsigned, Unk_Gev447V8<4> > m4; Unk_Gev447Use(m4, k);
    std::map<unsigned, Unk_Gev447V8<5> > m5; Unk_Gev447Use(m5, k);
    std::map<std::pair<unsigned, int>, Unk_Gev447V4<6> > m6; Unk_Gev447Use(m6, pk);
    std::map<unsigned, Unk_Gev447V4<7> > m7; Unk_Gev447Use(m7, k);
    std::map<unsigned, Unk_Gev447V8<8> > m8; Unk_Gev447Use(m8, k);
    std::map<unsigned, Unk_Gev447V8<9> > m9; Unk_Gev447UseIter(m9);
    std::map<unsigned, Unk_Gev447V8<10> > c0; Unk_Gev447UseConst(c0);
    std::map<unsigned, Unk_Gev447V8<11> > c1; Unk_Gev447UseConst(c1);
    std::map<unsigned, Unk_Gev447V8<12> > c2; Unk_Gev447UseConst(c2);
    std::list<Unk_Gev447V8<13> > l0; *l0.cbegin(); *l0.begin();
    std::list<Unk_Gev447V8<14> > l1; *l1.cbegin();
    std::vector<unsigned __int64> v; v[0];
    Unk_Gev447Ptr<0>(); Unk_Gev447Ptr<1>(); Unk_Gev447Ptr<2>(); Unk_Gev447Ptr<3>(); Unk_Gev447Ptr<4>();
    Unk_Gev447Ptr<5>(); Unk_Gev447Ptr<6>(); Unk_Gev447Ptr<7>(); Unk_Gev447Ptr<8>(); Unk_Gev447Ptr<9>();
    Unk_Gev447Ptr<10>(); Unk_Gev447Ptr<11>();
    _AtlBaseModule.GetModuleInstance();
}

// Unk_FieldPtr<CAtlList<unsigned>>::Value (0x1404481d0), the pointee address of a fresh box (called by Create at 0x14045b710)
template ATL::CAtlList<unsigned int>* Unk_FieldPtr<ATL::CAtlList<unsigned int> >::Value(TPtredDummy<ATL::CAtlList<unsigned int> >*);
