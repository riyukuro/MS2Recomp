// Unit-local stand-ins for the exe's std::map iterator/lookup glue (25 map instantiations whose key/value types are not
// recoverable from the byte-identical bodies). Unk_IterA/Unk_IterB<N> are the tree-node iterators (value at node+0x20 / +0x1c).
// MS2-UNIT: unit_141127a90
// MS2-RANGE: 0x141127a90-0x141128e70 .text$mn
// MS2-PIN: ?Get@?$Unk_Head@$0A@@@QEBAPEAXXZ 0x141128450 ; manual
// MS2-PIN: ?Get@?$Unk_Head@$00@@QEBAPEAXXZ 0x141128e50 ; manual
// MS2-PIN: ?Get@?$Unk_Head@$01@@QEBAPEAXXZ 0x141128e60 ; manual
// MS2-PIN: ?Val@?$Unk_IterA@$0BI@@@QEBAPEADXZ 0x141128b10 ; manual
// MS2-PIN: ?Val@?$Unk_IterA@$0BJ@@@QEBAPEADXZ 0x141128b30 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$0A@@@QEBAPEAXXZ 0x1411283f0 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$00@@QEBAPEAXXZ 0x141128400 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$01@@QEBAPEAXXZ 0x141128410 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$02@@QEBAPEAXXZ 0x141128420 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$03@@QEBAPEAXXZ 0x141128430 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$04@@QEBAPEAXXZ 0x141128440 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$05@@QEBAPEAXXZ 0x141128460 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$06@@QEBAPEAXXZ 0x141128470 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$07@@QEBAPEAXXZ 0x141128480 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$08@@QEBAPEAXXZ 0x141128490 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$09@@QEBAPEAXXZ 0x1411284a0 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$0L@@@QEBAPEAXXZ 0x1411284b0 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$0M@@@QEBAPEAXXZ 0x1411284c0 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$0N@@@QEBAPEAXXZ 0x1411284d0 ; manual
// MS2-PIN: ?Get@?$Unk_Link@$0O@@@QEBAPEAXXZ 0x141128800 ; manual
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <utility>

// Tree-node iterator: the node pointer; the pair value starts 0x20 (IterA) or 0x1c (IterB) into the node.
template <int N>
class Unk_IterA
{
public:
    char* Val() const { return (m_pNode + 0x20); }
    char* Ref() const { return Val(); }
    char* m_pNode;
};

template <int N>
class Unk_IterB
{
public:
    char* Val() const { return (m_pNode + 0x1c); }
    char* Ref() const { return Val(); }
    char* m_pNode;
};

template <int N>
class Unk_Link
{
public:
    void* Get() const { return m_pNext; }
    void* m_pFirst;
    void* m_pNext;
};

template <int N>
class Unk_Head
{
public:
    void* Get() const { return m_pFirst; }
    void* m_pFirst;
};

struct Unk_Cursor { void* m_p; };
// The insert wrappers (0x14111d6e0..0x14111dfa0, via 0x1410d7c20 / 0x1410da090) write a std::pair<iterator, bool>:
// 16 bytes, the bool at +8. The callers' slot is the pair; they read .first through the returned pointer.
template <class It> struct Unk_InsPair { It first; bool second; };
struct Unk_Key;
struct Unk_Elem52 { char m_acData[0x34]; };
class Unk_Array52;
class Unk_ArrayInt;

template char* Unk_IterA<0>::Val() const;   // 0x141128810
template char* Unk_IterB<1>::Val() const;   // 0x141128830
template char* Unk_IterA<2>::Val() const;   // 0x141128850
template char* Unk_IterA<3>::Val() const;   // 0x141128870
template char* Unk_IterA<4>::Val() const;   // 0x141128890
template char* Unk_IterA<5>::Val() const;   // 0x1411288b0
template char* Unk_IterA<6>::Val() const;   // 0x1411288d0
template char* Unk_IterA<7>::Val() const;   // 0x1411288f0
template char* Unk_IterA<8>::Val() const;   // 0x141128910
template char* Unk_IterA<9>::Val() const;   // 0x141128930
template char* Unk_IterA<10>::Val() const;   // 0x141128950
template char* Unk_IterA<11>::Val() const;   // 0x141128970
template char* Unk_IterA<12>::Val() const;   // 0x141128990
template char* Unk_IterA<13>::Val() const;   // 0x1411289b0
template char* Unk_IterA<14>::Val() const;   // 0x1411289d0
template char* Unk_IterA<15>::Val() const;   // 0x1411289f0
template char* Unk_IterA<16>::Val() const;   // 0x141128a10
template char* Unk_IterA<17>::Val() const;   // 0x141128a30
template char* Unk_IterA<18>::Val() const;   // 0x141128a50
template char* Unk_IterA<19>::Val() const;   // 0x141128a70
template char* Unk_IterA<20>::Val() const;   // 0x141128a90
template char* Unk_IterB<21>::Val() const;   // 0x141128ab0
template char* Unk_IterB<22>::Val() const;   // 0x141128ad0
template char* Unk_IterB<23>::Val() const;   // 0x141128af0
template char* Unk_IterA<24>::Val() const;   // 0x141128b10
template char* Unk_IterA<25>::Val() const;   // 0x141128b30
template char* Unk_IterA<0>::Ref() const;   // 0x141128b50
template char* Unk_IterB<1>::Ref() const;   // 0x141128b70
template char* Unk_IterA<2>::Ref() const;   // 0x141128b90
template char* Unk_IterA<3>::Ref() const;   // 0x141128bb0
template char* Unk_IterA<4>::Ref() const;   // 0x141128bd0
template char* Unk_IterA<5>::Ref() const;   // 0x141128bf0
template char* Unk_IterA<6>::Ref() const;   // 0x141128c10
template char* Unk_IterA<7>::Ref() const;   // 0x141128c30
template char* Unk_IterA<8>::Ref() const;   // 0x141128c50
template char* Unk_IterA<9>::Ref() const;   // 0x141128c70
template char* Unk_IterA<10>::Ref() const;   // 0x141128c90
template char* Unk_IterA<11>::Ref() const;   // 0x141128cb0
template char* Unk_IterA<12>::Ref() const;   // 0x141128cd0
template char* Unk_IterA<13>::Ref() const;   // 0x141128cf0
template char* Unk_IterA<14>::Ref() const;   // 0x141128d10
template char* Unk_IterA<15>::Ref() const;   // 0x141128d30
template char* Unk_IterA<16>::Ref() const;   // 0x141128d50
template char* Unk_IterA<17>::Ref() const;   // 0x141128d70
template char* Unk_IterA<18>::Ref() const;   // 0x141128d90
template char* Unk_IterA<19>::Ref() const;   // 0x141128db0
template char* Unk_IterA<20>::Ref() const;   // 0x141128dd0
template char* Unk_IterB<21>::Ref() const;   // 0x141128df0
template char* Unk_IterB<22>::Ref() const;   // 0x141128e10
template char* Unk_IterB<23>::Ref() const;   // 0x141128e30

template void* Unk_Link<0>::Get() const;   // 0x1411283f0
template void* Unk_Link<1>::Get() const;   // 0x141128400
template void* Unk_Link<2>::Get() const;   // 0x141128410
template void* Unk_Link<3>::Get() const;   // 0x141128420
template void* Unk_Link<4>::Get() const;   // 0x141128430
template void* Unk_Link<5>::Get() const;   // 0x141128440
template void* Unk_Link<6>::Get() const;   // 0x141128460
template void* Unk_Link<7>::Get() const;   // 0x141128470
template void* Unk_Link<8>::Get() const;   // 0x141128480
template void* Unk_Link<9>::Get() const;   // 0x141128490
template void* Unk_Link<10>::Get() const;   // 0x1411284a0
template void* Unk_Link<11>::Get() const;   // 0x1411284b0
template void* Unk_Link<12>::Get() const;   // 0x1411284c0
template void* Unk_Link<13>::Get() const;   // 0x1411284d0
template void* Unk_Link<14>::Get() const;   // 0x141128800
template void* Unk_Head<0>::Get() const;   // 0x141128450
template void* Unk_Head<1>::Get() const;   // 0x141128e50
template void* Unk_Head<2>::Get() const;   // 0x141128e60

// ---- externs (other units) ----
char* FUN_14115a580(char*);
char* FUN_14115a5a0(char*);
char* FUN_14115a5c0(char*);
char* FUN_14115a5e0(char*);
char* FUN_14115a600(char*);
char* FUN_14115a620(char*);
char* FUN_14115a640(char*);
char* FUN_14115a660(char*);
char* FUN_14115a680(char*);
char* FUN_14115a6a0(char*);
char* FUN_14115a6c0(char*);
char* FUN_14115a6e0(char*);
char* FUN_14115a700(char*);
char* FUN_14115a720(char*);
char* FUN_14115a740(char*);
char* FUN_14115a760(char*);
char* FUN_14115a780(char*);
char* FUN_14115a7a0(char*);
char* FUN_14115a7c0(char*);
char* FUN_14115a7e0(char*);
char* FUN_14115a800(char*);
char* FUN_14115a820(char*);
char* FUN_14115a840(char*);
char* FUN_14115a860(char*);
char* FUN_14115a880(char*);
// Unk_IterA<0>* FUN_14111d6e0(void*, Unk_IterA<0>*, void*);
// Unk_IterB<1>* FUN_14111d720(void*, Unk_IterB<1>*, void*);
// Unk_IterA<2>* FUN_14111d760(void*, Unk_IterA<2>*, void*);
// void* FUN_140181b70(Unk_Key*);
// Unk_IterA<2>* FUN_14111d7a0(void*, Unk_IterA<2>*, void*);
// Unk_IterA<3>* FUN_14111d7e0(void*, Unk_IterA<3>*, void*);
// Unk_IterA<4>* FUN_14111d820(void*, Unk_IterA<4>*, void*);
// Unk_IterA<4>* FUN_14111d860(void*, Unk_IterA<4>*, void*);
// Unk_IterA<5>* FUN_14111d8a0(void*, Unk_IterA<5>*, void*);
// Unk_IterA<6>* FUN_14111d8e0(void*, Unk_IterA<6>*, void*);
// Unk_IterA<7>* FUN_14111d920(void*, Unk_IterA<7>*, void*);
// Unk_IterA<8>* FUN_14111d960(void*, Unk_IterA<8>*, void*);
// Unk_IterA<9>* FUN_14111d9a0(void*, Unk_IterA<9>*, void*);
// Unk_IterA<10>* FUN_14111d9e0(void*, Unk_IterA<10>*, void*);
// Unk_IterA<10>* FUN_14111da20(void*, Unk_IterA<10>*, void*);
// Unk_IterA<11>* FUN_14111da60(void*, Unk_IterA<11>*, void*);
// Unk_IterA<12>* FUN_14111daa0(void*, Unk_IterA<12>*, void*);
// Unk_IterA<13>* FUN_14111dae0(void*, Unk_IterA<13>*, void*);
// Unk_IterA<13>* FUN_14111db20(void*, Unk_IterA<13>*, void*);
// Unk_IterA<14>* FUN_14111db60(void*, Unk_IterA<14>*, void*);
// 0x140d7b4e0 = std::map<int, bool>::iterator::operator-> (the ICF copy FUN_141127f50 calls)
// Unk_Cursor* FUN_14111dba0(void*, Unk_Cursor*, void*);
#include <map>
#include "ms2/placeholder/ms2svrptr.h"   // C3: the real maps of FUN_141127f90 / FUN_141128010 (below)
// void* FUN_140181b80(Unk_Key*);
// 0x1404482f0 = std::map<unsigned long, unsigned long>::iterator::operator-> (the ICF copy FUN_141127fd0 calls)
// Unk_Cursor* FUN_14111dc20(void*, Unk_Cursor*, void*);
#include "ms2/commonfiles/ugcmapsetiteminfo.h"

// Unk_IterA<15>* FUN_14111dca0(void*, Unk_IterA<15>*, void*);
// Unk_IterA<16>* FUN_14111dce0(void*, Unk_IterA<16>*, void*);
// 0x1404eb810 = std::move<std::pair<int, int>&> (FUN_141128090 key)
// Unk_IterA<17>* FUN_14111dd20(void*, Unk_IterA<17>*, void*);
// Unk_IterA<18>* FUN_14111dd60(void*, Unk_IterA<18>*, void*);
// Unk_IterA<19>* FUN_14111dda0(void*, Unk_IterA<19>*, void*);
// Unk_IterA<20>* FUN_14111dde0(void*, Unk_IterA<20>*, void*);
// Unk_IterB<21>* FUN_14111de20(void*, Unk_IterB<21>*, void*);
// Unk_IterB<21>* FUN_14111de60(void*, Unk_IterB<21>*, void*);
// Unk_IterB<22>* FUN_14111dea0(void*, Unk_IterB<22>*, void*);
// void* FUN_14111d530(Unk_Key*);
// Unk_IterB<22>* FUN_14111dee0(void*, Unk_IterB<22>*, void*);
// Unk_IterB<23>* FUN_14111df20(void*, Unk_IterB<23>*, void*);
// Unk_IterB<23>* FUN_14111df60(void*, Unk_IterB<23>*, void*);
class Cube;
template <class T> class MS2Ptr;
std::pair<const int, MS2Ptr<Cube> >* FUN_140885360(void* pIter);   // ugcbuildvalidator.cpp
// Unk_Cursor* FUN_14111dfa0(void*, Unk_Cursor*, void*);
#include <efd/StdContainers.h>   // C3: FUN_141148ff0 / FUN_141149030 were the vectors' _Myfirst()
#include "ms2/client/ms2/cubemapinformationservice_tail.h"   // the real map types of the try_emplace calls (&try_emplace(..).first: the casts emit no code)

// @0x1411284e0
char* FUN_1411284e0(Unk_IterB<21>* pIter)
{
    return FUN_14115a880(pIter->Val());
}

// @0x141128500
char* FUN_141128500(Unk_IterA<0>* pIter)
{
    return FUN_14115a580(pIter->Ref());
}

// @0x141128520
char* FUN_141128520(Unk_IterB<1>* pIter)
{
    return FUN_14115a5a0(pIter->Ref());
}

// @0x141128540
char* FUN_141128540(Unk_IterA<2>* pIter)
{
    return FUN_14115a5c0(pIter->Ref());
}

// @0x141128560
char* FUN_141128560(Unk_IterA<3>* pIter)
{
    return FUN_14115a5e0(pIter->Ref());
}

// @0x141128580
char* FUN_141128580(Unk_IterA<4>* pIter)
{
    return FUN_14115a600(pIter->Ref());
}

// @0x1411285a0
char* FUN_1411285a0(Unk_IterA<5>* pIter)
{
    return FUN_14115a620(pIter->Ref());
}

// @0x1411285c0
char* FUN_1411285c0(Unk_IterA<6>* pIter)
{
    return FUN_14115a640(pIter->Ref());
}

// @0x1411285e0
char* FUN_1411285e0(Unk_IterA<7>* pIter)
{
    return FUN_14115a660(pIter->Ref());
}

// @0x141128600
char* FUN_141128600(Unk_IterA<8>* pIter)
{
    return FUN_14115a680(pIter->Ref());
}

// @0x141128620
char* FUN_141128620(Unk_IterA<9>* pIter)
{
    return FUN_14115a6a0(pIter->Ref());
}

// @0x141128640
char* FUN_141128640(Unk_IterA<10>* pIter)
{
    return FUN_14115a6c0(pIter->Ref());
}

// @0x141128660
char* FUN_141128660(Unk_IterA<11>* pIter)
{
    return FUN_14115a6e0(pIter->Ref());
}

// @0x141128680
char* FUN_141128680(Unk_IterA<12>* pIter)
{
    return FUN_14115a700(pIter->Ref());
}

// @0x1411286a0
char* FUN_1411286a0(Unk_IterA<13>* pIter)
{
    return FUN_14115a720(pIter->Ref());
}

// @0x1411286c0
char* FUN_1411286c0(Unk_IterA<14>* pIter)
{
    return FUN_14115a740(pIter->Ref());
}

// @0x1411286e0
char* FUN_1411286e0(Unk_IterA<15>* pIter)
{
    return FUN_14115a760(pIter->Ref());
}

// @0x141128700
char* FUN_141128700(Unk_IterA<16>* pIter)
{
    return FUN_14115a780(pIter->Ref());
}

// @0x141128720
char* FUN_141128720(Unk_IterA<17>* pIter)
{
    return FUN_14115a7a0(pIter->Ref());
}

// @0x141128740
char* FUN_141128740(Unk_IterA<18>* pIter)
{
    return FUN_14115a7c0(pIter->Ref());
}

// @0x141128760
char* FUN_141128760(Unk_IterA<19>* pIter)
{
    return FUN_14115a7e0(pIter->Ref());
}

// @0x141128780
char* FUN_141128780(Unk_IterA<20>* pIter)
{
    return FUN_14115a800(pIter->Ref());
}

// @0x1411287a0
char* FUN_1411287a0(Unk_IterB<21>* pIter)
{
    return FUN_14115a820(pIter->Ref());
}

// @0x1411287c0
char* FUN_1411287c0(Unk_IterB<22>* pIter)
{
    return FUN_14115a840(pIter->Ref());
}

// @0x1411287e0
char* FUN_1411287e0(Unk_IterB<23>* pIter)
{
    return FUN_14115a860(pIter->Ref());
}

// @0x141127a90
char* FUN_141127a90(void* pMap, void* key)
{
    // real try_emplace (0x14111d6e0), read through the unit's iterator view
    return (FUN_141128500(reinterpret_cast<Unk_IterA<0>*>(const_cast<Unk_CMISMapMark::iterator*>(&static_cast<const std::pair<Unk_CMISMapMark::iterator, bool>&>(((Unk_CMISMapMark*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127ad0
char* FUN_141127ad0(void* pMap, void* key)
{
    // real try_emplace (0x14111d720), read through the unit's iterator view
    return (FUN_141128520(reinterpret_cast<Unk_IterB<1>*>(const_cast<Unk_CMISMapNear::iterator*>(&static_cast<const std::pair<Unk_CMISMapNear::iterator, bool>&>(((Unk_CMISMapNear*)pMap)->try_emplace(*(const int*)key)).first))) + 4);
}

// @0x141127b10
char* FUN_141127b10(void* pMap, Unk_Key* pKey)
{
    // real try_emplace (0x14111d760), read through the unit's iterator view
    return (FUN_141128540(reinterpret_cast<Unk_IterA<2>*>(const_cast<Unk_CMISMapCell::iterator*>(&static_cast<const std::pair<Unk_CMISMapCell::iterator, bool>&>(((Unk_CMISMapCell*)pMap)->try_emplace(std::move(*(int*)pKey))).first))) + 8);
}

// @0x141127b50
char* FUN_141127b50(void* pMap, void* key)
{
    // real try_emplace (0x14111d7a0), read through the unit's iterator view
    return (FUN_141128540(reinterpret_cast<Unk_IterA<2>*>(const_cast<Unk_CMISMapCell::iterator*>(&static_cast<const std::pair<Unk_CMISMapCell::iterator, bool>&>(((Unk_CMISMapCell*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127b90
char* FUN_141127b90(void* pMap, void* key)
{
    // real try_emplace (0x14111d7e0), read through the unit's iterator view
    return (FUN_141128560(reinterpret_cast<Unk_IterA<3>*>(const_cast<efd::map<long, egf::EntityPtr>::iterator*>(&static_cast<const std::pair<efd::map<long, egf::EntityPtr>::iterator, bool>&>(((efd::map<long, egf::EntityPtr>*)pMap)->try_emplace(*(const long*)key)).first))) + 8);
}

// @0x141127bd0
char* FUN_141127bd0(void* pMap, Unk_Key* pKey)
{
    // real try_emplace (0x14111d820), read through the unit's iterator view
    return (FUN_141128580(reinterpret_cast<Unk_IterA<4>*>(const_cast<Unk_CMISMapDoll::iterator*>(&static_cast<const std::pair<Unk_CMISMapDoll::iterator, bool>&>(((Unk_CMISMapDoll*)pMap)->try_emplace(std::move(*(int*)pKey))).first))) + 8);
}

// @0x141127c10
char* FUN_141127c10(void* pMap, void* key)
{
    // real try_emplace (0x14111d860), read through the unit's iterator view
    return (FUN_141128580(reinterpret_cast<Unk_IterA<4>*>(const_cast<Unk_CMISMapDoll::iterator*>(&static_cast<const std::pair<Unk_CMISMapDoll::iterator, bool>&>(((Unk_CMISMapDoll*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127c50
char* FUN_141127c50(void* pMap, void* key)
{
    // real try_emplace (0x14111d8a0), read through the unit's iterator view
    return (FUN_1411285a0(reinterpret_cast<Unk_IterA<5>*>(const_cast<Unk_CMISStdMapCube::iterator*>(&static_cast<const std::pair<Unk_CMISStdMapCube::iterator, bool>&>(((Unk_CMISStdMapCube*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127c90
char* FUN_141127c90(void* pMap, void* key)
{
    // real try_emplace (0x14111d8e0), read through the unit's iterator view
    return (FUN_1411285c0(reinterpret_cast<Unk_IterA<6>*>(const_cast<Unk_CMISMapSetEffect::iterator*>(&static_cast<const std::pair<Unk_CMISMapSetEffect::iterator, bool>&>(((Unk_CMISMapSetEffect*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127cd0
char* FUN_141127cd0(void* pMap, void* key)
{
    // real try_emplace (0x14111d920), read through the unit's iterator view
    return (FUN_1411285e0(reinterpret_cast<Unk_IterA<7>*>(const_cast<Unk_CMISMapCube::iterator*>(&static_cast<const std::pair<Unk_CMISMapCube::iterator, bool>&>(((Unk_CMISMapCube*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127d10
char* FUN_141127d10(void* pMap, void* key)
{
    // real try_emplace (0x14111d960), read through the unit's iterator view
    return (FUN_141128600(reinterpret_cast<Unk_IterA<8>*>(const_cast<Unk_CMISMapHead::iterator*>(&static_cast<const std::pair<Unk_CMISMapHead::iterator, bool>&>(((Unk_CMISMapHead*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127d50
char* FUN_141127d50(void* pMap, void* key)
{
    // real try_emplace (0x14111d9a0), read through the unit's iterator view
    return (FUN_141128620(reinterpret_cast<Unk_IterA<9>*>(const_cast<Unk_CMISMapBuckets::iterator*>(&static_cast<const std::pair<Unk_CMISMapBuckets::iterator, bool>&>(((Unk_CMISMapBuckets*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// fc8 as declared: the exe builds the inner map through 0x1411228d0 and frees it through 0x1411258b0, both CustomAllocator
typedef efd::map<int, efd::map<__int64, MS2Ptr<Cube> > > Unk_CMISFc8Map;

// @0x141127d90
char* FUN_141127d90(void* pMap, Unk_Key* pKey)
{
    // real try_emplace (0x14111d9e0), read through the unit's iterator view
    return (FUN_141128640(reinterpret_cast<Unk_IterA<10>*>(const_cast<Unk_CMISFc8Map::iterator*>(&static_cast<const std::pair<Unk_CMISFc8Map::iterator, bool>&>(((Unk_CMISFc8Map*)pMap)->try_emplace(std::move(*(int*)pKey))).first))) + 8);
}

// @0x141127dd0
char* FUN_141127dd0(void* pMap, void* key)
{
    // real try_emplace (0x14111da20), read through the unit's iterator view
    return (FUN_141128640(reinterpret_cast<Unk_IterA<10>*>(const_cast<Unk_CMISFc8Map::iterator*>(&static_cast<const std::pair<Unk_CMISFc8Map::iterator, bool>&>(((Unk_CMISFc8Map*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127e10
char* FUN_141127e10(void* pMap, void* key)
{
    // real try_emplace (0x14111da60), read through the unit's iterator view
    return (FUN_141128660(reinterpret_cast<Unk_IterA<11>*>(const_cast<Unk_CMISMapColumns::iterator*>(&static_cast<const std::pair<Unk_CMISMapColumns::iterator, bool>&>(((Unk_CMISMapColumns*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127e50
char* FUN_141127e50(void* pMap, void* key)
{
    // real try_emplace (0x14111daa0), read through the unit's iterator view
    return (FUN_141128680(reinterpret_cast<Unk_IterA<12>*>(const_cast<Unk_CMISMapEntVec::iterator*>(&static_cast<const std::pair<Unk_CMISMapEntVec::iterator, bool>&>(((Unk_CMISMapEntVec*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127e90
char* FUN_141127e90(void* pMap, Unk_Key* pKey)
{
    // real try_emplace (0x14111dae0), read through the unit's iterator view
    return (FUN_1411286a0(reinterpret_cast<Unk_IterA<13>*>(const_cast<Unk_CMISMapEntityId::iterator*>(&static_cast<const std::pair<Unk_CMISMapEntityId::iterator, bool>&>(((Unk_CMISMapEntityId*)pMap)->try_emplace(std::move(*(int*)pKey))).first))) + 8);
}

// @0x141127ed0
char* FUN_141127ed0(void* pMap, void* key)
{
    // real try_emplace (0x14111db20), read through the unit's iterator view
    return (FUN_1411286a0(reinterpret_cast<Unk_IterA<13>*>(const_cast<Unk_CMISMapEntityId::iterator*>(&static_cast<const std::pair<Unk_CMISMapEntityId::iterator, bool>&>(((Unk_CMISMapEntityId*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127f10
char* FUN_141127f10(void* pMap, void* key)
{
    // real try_emplace (0x14111db60), read through the unit's iterator view
    return (FUN_1411286c0(reinterpret_cast<Unk_IterA<14>*>(const_cast<Unk_CMISMapCubeTimer::iterator*>(&static_cast<const std::pair<Unk_CMISMapCubeTimer::iterator, bool>&>(((Unk_CMISMapCubeTimer*)pMap)->try_emplace(*(const int*)key)).first))) + 8);
}

// @0x141127f50
char* FUN_141127f50(void* pMap, Unk_Key* pKey)
{
    // real try_emplace (0x14111dba0), read through the unit's iterator view
    return (char*)&reinterpret_cast<std::map<int, bool>::iterator*>(const_cast<Unk_CMISMapKind::iterator*>(&static_cast<const std::pair<Unk_CMISMapKind::iterator, bool>&>(((Unk_CMISMapKind*)pMap)->try_emplace(std::move(*(int*)pKey))).first))->operator->()->second;
}

// @0x141127f90
char* FUN_141127f90(void* pMap, Unk_Key* pKey)
{
    // C3: std::map<unsigned, int>::operator[](unsigned&&): try_emplace 0x14111dbe0, iterator::operator-> 0x14025cf40, std::move<unsigned&> 0x140181b80
    return (char*)&((std::map<unsigned, int>*)pMap)->try_emplace(std::move(*(unsigned*)pKey)).first->second;
}

// @0x141127fd0
char* FUN_141127fd0(void* pMap, Unk_Key* pKey)
{
    // real try_emplace (0x14111dc20), read through the unit's iterator view
    return (char*)&reinterpret_cast<std::map<unsigned long, unsigned long>::iterator*>(const_cast<Unk_CMISMapUIntInt::iterator*>(&static_cast<const std::pair<Unk_CMISMapUIntInt::iterator, bool>&>(((Unk_CMISMapUIntInt*)pMap)->try_emplace(std::move(*(unsigned int*)pKey))).first))->operator->()->second;
}

// @0x141128010
char* FUN_141128010(void* pMap, Unk_Key* pKey)
{
    // C3: std::map<unsigned, MS2SvrPtr<CUGCMapSetItemInfo>>::operator[](unsigned&&): try_emplace 0x14111dc60, operator-> 0x1409ee2e0, std::move 0x140181b80
    return (char*)&((std::map<unsigned, MS2SvrPtr<CUGCMapSetItemInfo> >*)pMap)->try_emplace(std::move(*(unsigned*)pKey)).first->second;
}

// @0x141128050
char* FUN_141128050(void* pMap, void* key)
{
    // real try_emplace (0x14111dca0), read through the unit's iterator view
    return (FUN_1411286e0(reinterpret_cast<Unk_IterA<15>*>(const_cast<std::map<unsigned long, std::set<int> >::iterator*>(&static_cast<const std::pair<std::map<unsigned long, std::set<int> >::iterator, bool>&>(((std::map<unsigned long, std::set<int> >*)pMap)->try_emplace(*(const unsigned long*)key)).first))) + 8);
}

// @0x141128090
char* FUN_141128090(void* pMap, Unk_Key* pKey)
{
    // real try_emplace (0x14111dce0), read through the unit's iterator view
    return (FUN_141128700(reinterpret_cast<Unk_IterA<16>*>(const_cast<efd::map<std::pair<int, int>, MS2Ptr<SaleStateData> >::iterator*>(&static_cast<const std::pair<efd::map<std::pair<int, int>, MS2Ptr<SaleStateData> >::iterator, bool>&>(((efd::map<std::pair<int, int>, MS2Ptr<SaleStateData> >*)pMap)->try_emplace(std::move(*reinterpret_cast<std::pair<int, int>*>(pKey)))).first))) + 8);
}

// @0x1411280d0
char* FUN_1411280d0(void* pMap, void* key)
{
    // real try_emplace (0x14111dd20), read through the unit's iterator view
    return (FUN_141128720(reinterpret_cast<Unk_IterA<17>*>(const_cast<efd::map<CString, int>::iterator*>(&static_cast<const std::pair<efd::map<CString, int>::iterator, bool>&>(((efd::map<CString, int>*)pMap)->try_emplace(*(const CString*)key)).first))) + 8);
}

// @0x141128110
char* FUN_141128110(void* pMap, void* key)
{
    // real try_emplace (0x14111dd60), read through the unit's iterator view
    return (FUN_141128740(reinterpret_cast<Unk_IterA<18>*>(const_cast<efd::map<egf::EntityID, __int64>::iterator*>(&static_cast<const std::pair<efd::map<egf::EntityID, __int64>::iterator, bool>&>(((efd::map<egf::EntityID, __int64>*)pMap)->try_emplace(*(const egf::EntityID*)key)).first))) + 8);
}

// @0x141128150
char* FUN_141128150(void* pMap, void* key)
{
    // real try_emplace (0x14111dda0), read through the unit's iterator view
    return (FUN_141128760(reinterpret_cast<Unk_IterA<19>*>(const_cast<efd::map<egf::EntityID, efd::SmartPointer<egfPhysX::EntityActorData> >::iterator*>(&static_cast<const std::pair<efd::map<egf::EntityID, efd::SmartPointer<egfPhysX::EntityActorData> >::iterator, bool>&>(((efd::map<egf::EntityID, efd::SmartPointer<egfPhysX::EntityActorData> >*)pMap)->try_emplace(*(const egf::EntityID*)key)).first))) + 8);
}

// @0x141128190
char* FUN_141128190(void* pMap, void* key)
{
    // real try_emplace (0x14111dde0), read through the unit's iterator view
    return (FUN_141128780(reinterpret_cast<Unk_IterA<20>*>(const_cast<efd::map<egf::EntityID, MS2Ptr<Cube> >::iterator*>(&static_cast<const std::pair<efd::map<egf::EntityID, MS2Ptr<Cube> >::iterator, bool>&>(((efd::map<egf::EntityID, MS2Ptr<Cube> >*)pMap)->try_emplace(*(const egf::EntityID*)key)).first))) + 8);
}

// @0x1411281d0
char* FUN_1411281d0(void* pMap, void* key)
{
    // real try_emplace (0x14111de20), read through the unit's iterator view
    return (FUN_1411287a0(reinterpret_cast<Unk_IterB<21>*>(const_cast<efd::map<Unk_CMISKindA, int>::iterator*>(&static_cast<const std::pair<efd::map<Unk_CMISKindA, int>::iterator, bool>&>(((efd::map<Unk_CMISKindA, int>*)pMap)->try_emplace(*(const Unk_CMISKindA*)key)).first))) + 4);
}

// @0x141128210
char* FUN_141128210(void* pMap, void* key)
{
    // real try_emplace (0x14111de60), read through the unit's iterator view
    return (FUN_1411287a0(reinterpret_cast<Unk_IterB<21>*>(const_cast<std::map<Unk_CMISKindA, int>::iterator*>(&static_cast<const std::pair<std::map<Unk_CMISKindA, int>::iterator, bool>&>(((std::map<Unk_CMISKindA, int>*)pMap)->try_emplace(*(const Unk_CMISKindA*)key)).first))) + 4);
}

// @0x141128250
char* FUN_141128250(void* pMap, Unk_Key* pKey)
{
    // real try_emplace (0x14111dea0), read through the unit's iterator view
    return (FUN_1411287c0(reinterpret_cast<Unk_IterB<22>*>(const_cast<efd::map<Unk_CMISKindB, int>::iterator*>(&static_cast<const std::pair<efd::map<Unk_CMISKindB, int>::iterator, bool>&>(((efd::map<Unk_CMISKindB, int>*)pMap)->try_emplace(std::move(*(Unk_CMISKindB*)pKey))).first))) + 4);
}

// @0x141128290
char* FUN_141128290(void* pMap, void* key)
{
    // real try_emplace (0x14111dee0), read through the unit's iterator view
    return (FUN_1411287c0(reinterpret_cast<Unk_IterB<22>*>(const_cast<efd::map<Unk_CMISKindB, int>::iterator*>(&static_cast<const std::pair<efd::map<Unk_CMISKindB, int>::iterator, bool>&>(((efd::map<Unk_CMISKindB, int>*)pMap)->try_emplace(*(const Unk_CMISKindB*)key)).first))) + 4);
}

// @0x1411282d0
char* FUN_1411282d0(void* pMap, Unk_Key* pKey)
{
    // real try_emplace (0x14111df20), read through the unit's iterator view
    return (FUN_1411287e0(reinterpret_cast<Unk_IterB<23>*>(const_cast<efd::map<Unk_CMISKindB, unsigned char>::iterator*>(&static_cast<const std::pair<efd::map<Unk_CMISKindB, unsigned char>::iterator, bool>&>(((efd::map<Unk_CMISKindB, unsigned char>*)pMap)->try_emplace(std::move(*(Unk_CMISKindB*)pKey))).first))) + 4);
}

// @0x141128310
char* FUN_141128310(void* pMap, void* key)
{
    // real try_emplace (0x14111df60), read through the unit's iterator view
    return (FUN_1411287e0(reinterpret_cast<Unk_IterB<23>*>(const_cast<efd::map<Unk_CMISKindB, unsigned char>::iterator*>(&static_cast<const std::pair<efd::map<Unk_CMISKindB, unsigned char>::iterator, bool>&>(((efd::map<Unk_CMISKindB, unsigned char>*)pMap)->try_emplace(*(const Unk_CMISKindB*)key)).first))) + 4);
}

// @0x141128350
char* FUN_141128350(void* pMap, void* key)
{
    // real try_emplace (0x14111dfa0), read through the unit's iterator view
    return (reinterpret_cast<char*>(FUN_140885360((void*)const_cast<efd::map<long, MS2Ptr<Cube> >::iterator*>(&static_cast<const std::pair<efd::map<long, MS2Ptr<Cube> >::iterator, bool>&>(((efd::map<long, MS2Ptr<Cube> >*)pMap)->try_emplace(*(const long*)key)).first))) + 8);
}

// @0x141128390
Unk_Elem52* FUN_141128390(Unk_Array52* pArray, unsigned long long uIndex)
{
    return (reinterpret_cast<Unk_Elem52*&>(reinterpret_cast<std::vector<Unk_CMISElem52, efd::CustomAllocator<Unk_CMISElem52> >*>(pArray)->_Myfirst()) + uIndex);
}

// @0x1411283c0
int* FUN_1411283c0(Unk_ArrayInt* pArray, unsigned long long uIndex)
{
    return (reinterpret_cast<int*&>(reinterpret_cast<std::vector<Unk_CMISKindC>*>(pArray)->_Myfirst()) + uIndex);
}

