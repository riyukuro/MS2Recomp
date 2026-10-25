// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). std::_Tree_node<...>::_Freenode0 instances plus one equal_range.
// MS2-GUESS-LOOKALIKES
// MS2-UNIT: unit_1410e78b0
// MS2-RANGE: 0x1410e78b0-0x1410e9350 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Eqrange@_J@?$_Tree@V?$_Tmap_traits@_JV?$Unk_PayloadPtr@VCubeOwner@@@@U?$less@_J@std@@V?$allocator@U?$pair@$$CB_JV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@3@$0A@@std@@@std@@IEBA?AU?$pair@V?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@std@@@std@@@std@@V12@@1@AEB_J@Z 0x1410e7940 ; unique
// MS2-PIN: ?_Get_first@?$_Compressed_pair@U?$less@_J@std@@V?$_Compressed_pair@V?$allocator@U?$_Tree_node@U?$pair@$$CB_JV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@PEAX@std@@@std@@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CB_JV?$Unk_PayloadPtr@VCubeOwner@@@@@std@@@std@@@2@$00@2@$00@std@@QEBAAEBU?$less@_J@2@XZ 0x1410e92d0 ; order
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <map>
#include "ms2/ms2recover.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include "hook/ms2hook.h"
#include "ms2/commonfiles/ugcmapdata.h"

template <int N> struct Unk_Fn { int v[N + 1]; };

// Stand-in for the exe's tree allocator: a converting constructor and a user-provided destructor are out-of-line calls.
template <class T>
struct Unk_FnAlloc
{
    typedef T value_type;
    template <class U> struct rebind { typedef Unk_FnAlloc<U> other; };
    Unk_FnAlloc() {}
    template <class U> Unk_FnAlloc(const Unk_FnAlloc<U>&) {}
    ~Unk_FnAlloc() {}
    T* allocate(size_t n) { return (T*)::operator new(n * sizeof(T)); }
    void deallocate(T* p, size_t) { ::operator delete(p); }
};

typedef std::map<unsigned __int64, Unk_PayloadPtr<CubeOwner> > Unk_CMISOwnerById;

// The exe's 29 tree-node frees through a converting-constructor allocator and 8 through the node allocator, each over its own
// map family (stand-in value types), plus the std::allocator default / converting constructors of five more families.
template <int N> struct Unk_FnPick { };
template <int N> void Unk_FnFreeA(std::_Tree_node<Unk_Fn<N>, void*>* p)
{
    Unk_FnAlloc<Unk_Fn<N> > a;
    std::_Tree_node<Unk_Fn<N>, void*>::_Freenode0(a, p);
}
template <int N> void Unk_FnFreeB(std::_Tree_node<Unk_Fn<N>, void*>* p)
{
    std::allocator<std::_Tree_node<Unk_Fn<N>, void*> > a;
    std::_Tree_node<Unk_Fn<N>, void*>::_Freenode0(a, p);
}
template <int N> void Unk_FnCtors()
{
    std::allocator<Unk_Fn<N> > a;
    std::allocator<std::_Tree_node<Unk_Fn<N>, void*> > b(a);
}
void Unk_FnAnchor()
{
    Unk_FnFreeA<1>(0);
    Unk_FnFreeA<2>(0);
    Unk_FnFreeA<3>(0);
    Unk_FnFreeA<4>(0);
    Unk_FnFreeA<5>(0);
    Unk_FnFreeA<6>(0);
    Unk_FnFreeA<7>(0);
    Unk_FnFreeA<8>(0);
    Unk_FnFreeA<9>(0);
    Unk_FnFreeA<10>(0);
    Unk_FnFreeA<11>(0);
    Unk_FnFreeA<12>(0);
    Unk_FnFreeA<13>(0);
    Unk_FnFreeA<14>(0);
    Unk_FnFreeA<15>(0);
    Unk_FnFreeA<16>(0);
    Unk_FnFreeA<17>(0);
    Unk_FnFreeA<18>(0);
    Unk_FnFreeA<19>(0);
    Unk_FnFreeA<20>(0);
    Unk_FnFreeA<21>(0);
    Unk_FnFreeA<22>(0);
    Unk_FnFreeA<23>(0);
    Unk_FnFreeA<24>(0);
    Unk_FnFreeA<25>(0);
    Unk_FnFreeA<26>(0);
    Unk_FnFreeA<27>(0);
    Unk_FnFreeB<30>(0);
    Unk_FnFreeB<31>(0);
    Unk_FnFreeB<32>(0);
    Unk_FnFreeB<33>(0);
    Unk_FnFreeB<34>(0);
    Unk_FnFreeB<35>(0);
    Unk_FnFreeB<36>(0);
    Unk_FnFreeB<37>(0);
    Unk_FnCtors<38>();
    Unk_FnCtors<39>();
    Unk_FnCtors<40>();
    Unk_FnCtors<41>();
    Unk_FnCtors<42>();
    Unk_CMISOwnerById m;
    (void)m.equal_range(0);
}
