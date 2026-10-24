// Unit-local stand-ins and std::map glue near 0x1403e8960: map<int,int>/map<unsigned long,int>::operator[], 55 identical
// smart-pointer getters (`return m_p;` at +8; element types not recoverable) and the std::_Tree iterator dereferences.
// MS2-UNIT: unit_1403e8960
// MS2-RANGE: 0x1403e8960-0x1403e8e30 .text$mn
// MS2-PIN: ?Get@?$Unk_Ptr@$0A@@@QEBAPEAXXZ 0x1403e89e0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$00@@QEBAPEAXXZ 0x1403e89f0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$01@@QEBAPEAXXZ 0x1403e8a00 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$02@@QEBAPEAXXZ 0x1403e8a10 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$03@@QEBAPEAXXZ 0x1403e8a20 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$04@@QEBAPEAXXZ 0x1403e8a30 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$05@@QEBAPEAXXZ 0x1403e8a40 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$06@@QEBAPEAXXZ 0x1403e8a50 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$07@@QEBAPEAXXZ 0x1403e8a60 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$08@@QEBAPEAXXZ 0x1403e8a70 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$09@@QEBAPEAXXZ 0x1403e8a80 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0L@@@QEBAPEAXXZ 0x1403e8a90 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0M@@@QEBAPEAXXZ 0x1403e8aa0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0N@@@QEBAPEAXXZ 0x1403e8ab0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0O@@@QEBAPEAXXZ 0x1403e8ac0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0P@@@QEBAPEAXXZ 0x1403e8ad0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BA@@@QEBAPEAXXZ 0x1403e8ae0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BB@@@QEBAPEAXXZ 0x1403e8af0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BC@@@QEBAPEAXXZ 0x1403e8b00 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BD@@@QEBAPEAXXZ 0x1403e8b10 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BE@@@QEBAPEAXXZ 0x1403e8b20 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BF@@@QEBAPEAXXZ 0x1403e8b30 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BG@@@QEBAPEAXXZ 0x1403e8b40 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BH@@@QEBAPEAXXZ 0x1403e8b50 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BI@@@QEBAPEAXXZ 0x1403e8b60 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BJ@@@QEBAPEAXXZ 0x1403e8b70 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BK@@@QEBAPEAXXZ 0x1403e8b80 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BL@@@QEBAPEAXXZ 0x1403e8b90 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BM@@@QEBAPEAXXZ 0x1403e8ba0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BN@@@QEBAPEAXXZ 0x1403e8bb0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BO@@@QEBAPEAXXZ 0x1403e8bc0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0BP@@@QEBAPEAXXZ 0x1403e8bd0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CA@@@QEBAPEAXXZ 0x1403e8be0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CB@@@QEBAPEAXXZ 0x1403e8bf0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CC@@@QEBAPEAXXZ 0x1403e8c00 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CD@@@QEBAPEAXXZ 0x1403e8c10 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CE@@@QEBAPEAXXZ 0x1403e8c20 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CF@@@QEBAPEAXXZ 0x1403e8c30 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CG@@@QEBAPEAXXZ 0x1403e8c40 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CH@@@QEBAPEAXXZ 0x1403e8c50 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CI@@@QEBAPEAXXZ 0x1403e8c60 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CJ@@@QEBAPEAXXZ 0x1403e8c70 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CK@@@QEBAPEAXXZ 0x1403e8c80 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CL@@@QEBAPEAXXZ 0x1403e8c90 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CM@@@QEBAPEAXXZ 0x1403e8ca0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CN@@@QEBAPEAXXZ 0x1403e8cb0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CO@@@QEBAPEAXXZ 0x1403e8cc0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0CP@@@QEBAPEAXXZ 0x1403e8cd0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0DA@@@QEBAPEAXXZ 0x1403e8ce0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0DB@@@QEBAPEAXXZ 0x1403e8cf0 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0DC@@@QEBAPEAXXZ 0x1403e8d00 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0DD@@@QEBAPEAXXZ 0x1403e8d10 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0DE@@@QEBAPEAXXZ 0x1403e8d20 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0DF@@@QEBAPEAXXZ 0x1403e8d50 ; manual
// MS2-PIN: ?Get@?$Unk_Ptr@$0DG@@@QEBAPEAXXZ 0x1403e8d60 ; manual
// MS2-PIN: ?Val@?$Unk_Iter@$0A@@@QEBAPEADXZ 0x1403e8d70 ; manual
// MS2-PIN: ?Val@?$Unk_Iter@$00@@QEBAPEADXZ 0x1403e8dd0 ; manual
// MS2-PIN: ?Val@?$Unk_Iter@$01@@QEBAPEADXZ 0x1403e8e10 ; manual
// MS2-PIN: ??D?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAAEAU?$pair@$$CBHH@1@XZ 0x1403e8df0 ; manual
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@I@std@@@std@@@std@@QEBAAEBIXZ 0x1403e8d90 ; prop
// MS2-PIN: ??D?$_Tree_const_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHH@std@@@std@@@std@@@std@@QEBAAEBU?$pair@$$CBHH@1@XZ 0x1403e8db0 ; prop
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <map>
#include <set>

// Smart-pointer shaped handle: 8 bytes of header, then the raw pointer (the getters are `mov rax,[rcx+8]`).
template <int N>
class Unk_Ptr
{
public:
    void* Get() const { return m_p; }
    void* m_pHeader;
    void* m_p;
};

// Tree-node iterator: the node pointer; the value starts 0x1c into the node.
template <int N>
class Unk_Iter
{
public:
    char* Val() const { return (m_pNode + 0x1c); }
    char* m_pNode;
};

typedef std::map<int, int> IntIntMap;
typedef std::map<unsigned long, int> ULongIntMap;

template void* Unk_Ptr<0>::Get() const;   // 0x1403e89e0
template void* Unk_Ptr<1>::Get() const;   // 0x1403e89f0
template void* Unk_Ptr<2>::Get() const;   // 0x1403e8a00
template void* Unk_Ptr<3>::Get() const;   // 0x1403e8a10
template void* Unk_Ptr<4>::Get() const;   // 0x1403e8a20
template void* Unk_Ptr<5>::Get() const;   // 0x1403e8a30
template void* Unk_Ptr<6>::Get() const;   // 0x1403e8a40
template void* Unk_Ptr<7>::Get() const;   // 0x1403e8a50
template void* Unk_Ptr<8>::Get() const;   // 0x1403e8a60
template void* Unk_Ptr<9>::Get() const;   // 0x1403e8a70
template void* Unk_Ptr<10>::Get() const;   // 0x1403e8a80
template void* Unk_Ptr<11>::Get() const;   // 0x1403e8a90
template void* Unk_Ptr<12>::Get() const;   // 0x1403e8aa0
template void* Unk_Ptr<13>::Get() const;   // 0x1403e8ab0
template void* Unk_Ptr<14>::Get() const;   // 0x1403e8ac0
template void* Unk_Ptr<15>::Get() const;   // 0x1403e8ad0
template void* Unk_Ptr<16>::Get() const;   // 0x1403e8ae0
template void* Unk_Ptr<17>::Get() const;   // 0x1403e8af0
template void* Unk_Ptr<18>::Get() const;   // 0x1403e8b00
template void* Unk_Ptr<19>::Get() const;   // 0x1403e8b10
template void* Unk_Ptr<20>::Get() const;   // 0x1403e8b20
template void* Unk_Ptr<21>::Get() const;   // 0x1403e8b30
template void* Unk_Ptr<22>::Get() const;   // 0x1403e8b40
template void* Unk_Ptr<23>::Get() const;   // 0x1403e8b50
template void* Unk_Ptr<24>::Get() const;   // 0x1403e8b60
template void* Unk_Ptr<25>::Get() const;   // 0x1403e8b70
template void* Unk_Ptr<26>::Get() const;   // 0x1403e8b80
template void* Unk_Ptr<27>::Get() const;   // 0x1403e8b90
template void* Unk_Ptr<28>::Get() const;   // 0x1403e8ba0
template void* Unk_Ptr<29>::Get() const;   // 0x1403e8bb0
template void* Unk_Ptr<30>::Get() const;   // 0x1403e8bc0
template void* Unk_Ptr<31>::Get() const;   // 0x1403e8bd0
template void* Unk_Ptr<32>::Get() const;   // 0x1403e8be0
template void* Unk_Ptr<33>::Get() const;   // 0x1403e8bf0
template void* Unk_Ptr<34>::Get() const;   // 0x1403e8c00
template void* Unk_Ptr<35>::Get() const;   // 0x1403e8c10
template void* Unk_Ptr<36>::Get() const;   // 0x1403e8c20
template void* Unk_Ptr<37>::Get() const;   // 0x1403e8c30
template void* Unk_Ptr<38>::Get() const;   // 0x1403e8c40
template void* Unk_Ptr<39>::Get() const;   // 0x1403e8c50
template void* Unk_Ptr<40>::Get() const;   // 0x1403e8c60
template void* Unk_Ptr<41>::Get() const;   // 0x1403e8c70
template void* Unk_Ptr<42>::Get() const;   // 0x1403e8c80
template void* Unk_Ptr<43>::Get() const;   // 0x1403e8c90
template void* Unk_Ptr<44>::Get() const;   // 0x1403e8ca0
template void* Unk_Ptr<45>::Get() const;   // 0x1403e8cb0
template void* Unk_Ptr<46>::Get() const;   // 0x1403e8cc0
template void* Unk_Ptr<47>::Get() const;   // 0x1403e8cd0
template void* Unk_Ptr<48>::Get() const;   // 0x1403e8ce0
template void* Unk_Ptr<49>::Get() const;   // 0x1403e8cf0
template void* Unk_Ptr<50>::Get() const;   // 0x1403e8d00
template void* Unk_Ptr<51>::Get() const;   // 0x1403e8d10
template void* Unk_Ptr<52>::Get() const;   // 0x1403e8d20
template void* Unk_Ptr<53>::Get() const;   // 0x1403e8d50
template void* Unk_Ptr<54>::Get() const;   // 0x1403e8d60
// Tree iterator dereferences (0x1403e8d90 set<unsigned>, 0x1403e8df0 map<int,int>); the other three +0x1c getters are local.
typedef std::set<unsigned int>::const_iterator UIntSetIter;
template const unsigned int& UIntSetIter::operator*() const;   // 0x1403e8d90
template std::pair<const int, int>& IntIntMap::iterator::operator*() const;   // 0x1403e8df0
template char* Unk_Iter<0>::Val() const;   // 0x1403e8d70
template char* Unk_Iter<1>::Val() const;   // 0x1403e8dd0
template char* Unk_Iter<2>::Val() const;   // 0x1403e8e10

// 0x1403e8960: map<int,int>::operator[] (= _Try_emplace(key).first->second); 0x1403e89a0: map<unsigned long,int>
template int& IntIntMap::operator[](const int&);
template int& ULongIntMap::operator[](const unsigned long&);
