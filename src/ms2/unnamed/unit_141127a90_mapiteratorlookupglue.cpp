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
Unk_IterA<0>* FUN_14111d6e0(void*, Unk_IterA<0>*, void*);
Unk_IterB<1>* FUN_14111d720(void*, Unk_IterB<1>*, void*);
Unk_IterA<2>* FUN_14111d760(void*, Unk_IterA<2>*, void*);
void* FUN_140181b70(Unk_Key*);
Unk_IterA<2>* FUN_14111d7a0(void*, Unk_IterA<2>*, void*);
Unk_IterA<3>* FUN_14111d7e0(void*, Unk_IterA<3>*, void*);
Unk_IterA<4>* FUN_14111d820(void*, Unk_IterA<4>*, void*);
Unk_IterA<4>* FUN_14111d860(void*, Unk_IterA<4>*, void*);
Unk_IterA<5>* FUN_14111d8a0(void*, Unk_IterA<5>*, void*);
Unk_IterA<6>* FUN_14111d8e0(void*, Unk_IterA<6>*, void*);
Unk_IterA<7>* FUN_14111d920(void*, Unk_IterA<7>*, void*);
Unk_IterA<8>* FUN_14111d960(void*, Unk_IterA<8>*, void*);
Unk_IterA<9>* FUN_14111d9a0(void*, Unk_IterA<9>*, void*);
Unk_IterA<10>* FUN_14111d9e0(void*, Unk_IterA<10>*, void*);
Unk_IterA<10>* FUN_14111da20(void*, Unk_IterA<10>*, void*);
Unk_IterA<11>* FUN_14111da60(void*, Unk_IterA<11>*, void*);
Unk_IterA<12>* FUN_14111daa0(void*, Unk_IterA<12>*, void*);
Unk_IterA<13>* FUN_14111dae0(void*, Unk_IterA<13>*, void*);
Unk_IterA<13>* FUN_14111db20(void*, Unk_IterA<13>*, void*);
Unk_IterA<14>* FUN_14111db60(void*, Unk_IterA<14>*, void*);
char* FUN_140d7b4e0(Unk_Cursor*);
Unk_Cursor* FUN_14111dba0(void*, Unk_Cursor*, void*);
char* FUN_14025cf40(Unk_Cursor*);
Unk_Cursor* FUN_14111dbe0(void*, Unk_Cursor*, void*);
void* FUN_140181b80(Unk_Key*);
char* FUN_1404482f0(Unk_Cursor*);
Unk_Cursor* FUN_14111dc20(void*, Unk_Cursor*, void*);
char* FUN_1409ee2e0(Unk_Cursor*);
Unk_Cursor* FUN_14111dc60(void*, Unk_Cursor*, void*);
Unk_IterA<15>* FUN_14111dca0(void*, Unk_IterA<15>*, void*);
Unk_IterA<16>* FUN_14111dce0(void*, Unk_IterA<16>*, void*);
void* FUN_1404eb810(Unk_Key*);
Unk_IterA<17>* FUN_14111dd20(void*, Unk_IterA<17>*, void*);
Unk_IterA<18>* FUN_14111dd60(void*, Unk_IterA<18>*, void*);
Unk_IterA<19>* FUN_14111dda0(void*, Unk_IterA<19>*, void*);
Unk_IterA<20>* FUN_14111dde0(void*, Unk_IterA<20>*, void*);
Unk_IterB<21>* FUN_14111de20(void*, Unk_IterB<21>*, void*);
Unk_IterB<21>* FUN_14111de60(void*, Unk_IterB<21>*, void*);
Unk_IterB<22>* FUN_14111dea0(void*, Unk_IterB<22>*, void*);
void* FUN_14111d530(Unk_Key*);
Unk_IterB<22>* FUN_14111dee0(void*, Unk_IterB<22>*, void*);
Unk_IterB<23>* FUN_14111df20(void*, Unk_IterB<23>*, void*);
Unk_IterB<23>* FUN_14111df60(void*, Unk_IterB<23>*, void*);
char* FUN_140885360(Unk_Cursor*);
Unk_Cursor* FUN_14111dfa0(void*, Unk_Cursor*, void*);
Unk_Elem52** FUN_141148ff0(Unk_Array52*);
int** FUN_141149030(Unk_ArrayInt*);

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
    Unk_InsPair<Unk_IterA<0>> it;
    return (FUN_141128500(FUN_14111d6e0(pMap, &it.first, key)) + 8);
}

// @0x141127ad0
char* FUN_141127ad0(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterB<1>> it;
    return (FUN_141128520(FUN_14111d720(pMap, &it.first, key)) + 4);
}

// @0x141127b10
char* FUN_141127b10(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_IterA<2>> it;
    return (FUN_141128540(FUN_14111d760(pMap, &it.first, FUN_140181b70(pKey))) + 8);
}

// @0x141127b50
char* FUN_141127b50(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<2>> it;
    return (FUN_141128540(FUN_14111d7a0(pMap, &it.first, key)) + 8);
}

// @0x141127b90
char* FUN_141127b90(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<3>> it;
    return (FUN_141128560(FUN_14111d7e0(pMap, &it.first, key)) + 8);
}

// @0x141127bd0
char* FUN_141127bd0(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_IterA<4>> it;
    return (FUN_141128580(FUN_14111d820(pMap, &it.first, FUN_140181b70(pKey))) + 8);
}

// @0x141127c10
char* FUN_141127c10(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<4>> it;
    return (FUN_141128580(FUN_14111d860(pMap, &it.first, key)) + 8);
}

// @0x141127c50
char* FUN_141127c50(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<5>> it;
    return (FUN_1411285a0(FUN_14111d8a0(pMap, &it.first, key)) + 8);
}

// @0x141127c90
char* FUN_141127c90(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<6>> it;
    return (FUN_1411285c0(FUN_14111d8e0(pMap, &it.first, key)) + 8);
}

// @0x141127cd0
char* FUN_141127cd0(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<7>> it;
    return (FUN_1411285e0(FUN_14111d920(pMap, &it.first, key)) + 8);
}

// @0x141127d10
char* FUN_141127d10(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<8>> it;
    return (FUN_141128600(FUN_14111d960(pMap, &it.first, key)) + 8);
}

// @0x141127d50
char* FUN_141127d50(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<9>> it;
    return (FUN_141128620(FUN_14111d9a0(pMap, &it.first, key)) + 8);
}

// @0x141127d90
char* FUN_141127d90(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_IterA<10>> it;
    return (FUN_141128640(FUN_14111d9e0(pMap, &it.first, FUN_140181b70(pKey))) + 8);
}

// @0x141127dd0
char* FUN_141127dd0(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<10>> it;
    return (FUN_141128640(FUN_14111da20(pMap, &it.first, key)) + 8);
}

// @0x141127e10
char* FUN_141127e10(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<11>> it;
    return (FUN_141128660(FUN_14111da60(pMap, &it.first, key)) + 8);
}

// @0x141127e50
char* FUN_141127e50(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<12>> it;
    return (FUN_141128680(FUN_14111daa0(pMap, &it.first, key)) + 8);
}

// @0x141127e90
char* FUN_141127e90(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_IterA<13>> it;
    return (FUN_1411286a0(FUN_14111dae0(pMap, &it.first, FUN_140181b70(pKey))) + 8);
}

// @0x141127ed0
char* FUN_141127ed0(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<13>> it;
    return (FUN_1411286a0(FUN_14111db20(pMap, &it.first, key)) + 8);
}

// @0x141127f10
char* FUN_141127f10(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<14>> it;
    return (FUN_1411286c0(FUN_14111db60(pMap, &it.first, key)) + 8);
}

// @0x141127f50
char* FUN_141127f50(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_Cursor> it;
    return (FUN_140d7b4e0(FUN_14111dba0(pMap, &it.first, FUN_140181b70(pKey))) + 4);
}

// @0x141127f90
char* FUN_141127f90(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_Cursor> it;
    return (FUN_14025cf40(FUN_14111dbe0(pMap, &it.first, FUN_140181b80(pKey))) + 4);
}

// @0x141127fd0
char* FUN_141127fd0(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_Cursor> it;
    return (FUN_1404482f0(FUN_14111dc20(pMap, &it.first, FUN_140181b80(pKey))) + 4);
}

// @0x141128010
char* FUN_141128010(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_Cursor> it;
    return (FUN_1409ee2e0(FUN_14111dc60(pMap, &it.first, FUN_140181b80(pKey))) + 8);
}

// @0x141128050
char* FUN_141128050(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<15>> it;
    return (FUN_1411286e0(FUN_14111dca0(pMap, &it.first, key)) + 8);
}

// @0x141128090
char* FUN_141128090(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_IterA<16>> it;
    return (FUN_141128700(FUN_14111dce0(pMap, &it.first, FUN_1404eb810(pKey))) + 8);
}

// @0x1411280d0
char* FUN_1411280d0(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<17>> it;
    return (FUN_141128720(FUN_14111dd20(pMap, &it.first, key)) + 8);
}

// @0x141128110
char* FUN_141128110(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<18>> it;
    return (FUN_141128740(FUN_14111dd60(pMap, &it.first, key)) + 8);
}

// @0x141128150
char* FUN_141128150(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<19>> it;
    return (FUN_141128760(FUN_14111dda0(pMap, &it.first, key)) + 8);
}

// @0x141128190
char* FUN_141128190(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterA<20>> it;
    return (FUN_141128780(FUN_14111dde0(pMap, &it.first, key)) + 8);
}

// @0x1411281d0
char* FUN_1411281d0(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterB<21>> it;
    return (FUN_1411287a0(FUN_14111de20(pMap, &it.first, key)) + 4);
}

// @0x141128210
char* FUN_141128210(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterB<21>> it;
    return (FUN_1411287a0(FUN_14111de60(pMap, &it.first, key)) + 4);
}

// @0x141128250
char* FUN_141128250(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_IterB<22>> it;
    return (FUN_1411287c0(FUN_14111dea0(pMap, &it.first, FUN_14111d530(pKey))) + 4);
}

// @0x141128290
char* FUN_141128290(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterB<22>> it;
    return (FUN_1411287c0(FUN_14111dee0(pMap, &it.first, key)) + 4);
}

// @0x1411282d0
char* FUN_1411282d0(void* pMap, Unk_Key* pKey)
{
    Unk_InsPair<Unk_IterB<23>> it;
    return (FUN_1411287e0(FUN_14111df20(pMap, &it.first, FUN_14111d530(pKey))) + 4);
}

// @0x141128310
char* FUN_141128310(void* pMap, void* key)
{
    Unk_InsPair<Unk_IterB<23>> it;
    return (FUN_1411287e0(FUN_14111df60(pMap, &it.first, key)) + 4);
}

// @0x141128350
char* FUN_141128350(void* pMap, void* key)
{
    Unk_InsPair<Unk_Cursor> it;
    return (FUN_140885360(FUN_14111dfa0(pMap, &it.first, key)) + 8);
}

// @0x141128390
Unk_Elem52* FUN_141128390(Unk_Array52* pArray, unsigned long long uIndex)
{
    return (*FUN_141148ff0(pArray) + uIndex);
}

// @0x1411283c0
int* FUN_1411283c0(Unk_ArrayInt* pArray, unsigned long long uIndex)
{
    return (*FUN_141149030(pArray) + uIndex);
}

