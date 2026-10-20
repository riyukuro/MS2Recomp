// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// CubeMapInformationService COMDAT tail slice 0x1410e29c0-0x1410e4e80: _Destroy_range, tree-iterator _Distance1,
// _Uninitialized_backout_al::_Emplace_back and vector::_Emplace_reallocate instances of the service's containers.
// MS2-UNIT: unit_1410e29c0
// MS2-RANGE: 0x1410e29c0-0x1410e4e80 .text$mn
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@YAXPEAVEntityID@egf@@0AEAV?$CustomAllocator@VEntityID@egf@@@efd@@U?$integral_constant@_N$0A@@0@@Z 0x1410e2a80 ; w560: SmartPointer/EntityID vector swap (exe destroy chain)
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@YAXPEAV?$SmartPointer@VEntity@egf@@@efd@@0AEAV?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@U?$integral_constant@_N$0A@@0@@Z 0x1410e2a20 ; w560: SmartPointer/EntityID vector swap (exe destroy chain)
// MS2-PIN: ??$_Destroy_range1@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@YAXPEAUUnk_CMISElem52@@0AEAV?$CustomAllocator@UUnk_CMISElem52@@@efd@@U?$integral_constant@_N$0A@@0@@Z 0x1410e2ae0
// MS2-PIN: ??$_Destroy_range1@V?$allocator@PEAVCube@@@std@@@std@@YAXPEAPEAVCube@@0AEAV?$allocator@PEAVCube@@@0@U?$integral_constant@_N$00@0@@Z 0x1410e2b40
// MS2-PIN: ??$_Destroy_range@V?$allocator@PEAVCube@@@std@@@std@@YAXPEAPEAVCube@@0AEAV?$allocator@PEAVCube@@@0@@Z 0x1410e2cc0
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBQEAVCube@@@?$vector@PEAVCube@@V?$allocator@PEAVCube@@@std@@@std@@AEAAXAEBQEAVCube@@@Z 0x1410e3720
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$SmartPointer@VEntity@egf@@@efd@@@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@AEAAXAEBV?$SmartPointer@VEntity@egf@@@efd@@@Z 0x1410e37e0
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBV?$SmartPointer@VEntity@egf@@@efd@@@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@AEAAXAEBV?$SmartPointer@VEntity@egf@@@efd@@@Z 0x1410e38a0
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBVEntityID@egf@@@?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@AEAAXAEBVEntityID@egf@@@Z 0x1410e3960
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@PEAVCube@@@?$vector@PEAVCube@@V?$allocator@PEAVCube@@@std@@@std@@AEAAX$$QEAPEAVCube@@@Z 0x1410e3ae0
// MS2-PIN: ??$_Emplace_reallocate@AEBQEAVCube@@@?$vector@PEAVCube@@V?$allocator@PEAVCube@@@std@@@std@@QEAAPEAPEAVCube@@QEAPEAV2@AEBQEAV2@@Z 0x1410e3ea0
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$SmartPointer@VEntity@egf@@@efd@@@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@QEAAPEAV?$SmartPointer@VEntity@egf@@@efd@@QEAV23@AEBV23@@Z 0x1410e40e0
// MS2-PIN: ??$_Emplace_reallocate@AEBV?$SmartPointer@VEntity@egf@@@efd@@@?$vector@V?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@QEAAPEAV?$SmartPointer@VEntity@egf@@@efd@@QEAV23@AEBV23@@Z 0x1410e4320
// MS2-PIN: ??$_Emplace_reallocate@AEBVEntityID@egf@@@?$vector@VEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@QEAAPEAVEntityID@egf@@QEAV23@AEBV23@@Z 0x1410e4560
// MS2-PIN: ??$_Emplace_reallocate@PEAVCube@@@?$vector@PEAVCube@@V?$allocator@PEAVCube@@@std@@@std@@QEAAPEAPEAVCube@@QEAPEAV2@$$QEAPEAV2@@Z 0x1410e4a00
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBHV?$MS2Ptr@VCube@@@@@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x1410e2fa0 ; prop
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@H@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x1410e3180 ; prop
// MS2-PIN: ??$_Distance1@V?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@std@@@std@@@std@@YA_JV?$_Tree_iterator@V?$_Tree_val@U?$_Tree_simple_types@U?$pair@$$CBW4Unk_CMISKindA@@H@std@@@std@@@std@@@0@0Uinput_iterator_tag@0@@Z 0x1410e32a0 ; prop
// MS2-PIN: ??$_Emplace_back@UUnk_CMISElem52@@@?$_Uninitialized_backout_al@PEAUUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@QEAAX$$QEAUUnk_CMISElem52@@@Z 0x1410e3600 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBUUnk_CMISElem52@@@?$vector@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@AEAAXAEBUUnk_CMISElem52@@@Z 0x1410e3a20 ; unique
// MS2-PIN: ??$_Emplace_back_with_unused_capacity@AEBW4Unk_CMISKindC@@@?$vector@W4Unk_CMISKindC@@V?$allocator@W4Unk_CMISKindC@@@std@@@std@@AEAAXAEBW4Unk_CMISKindC@@@Z 0x1410e3ba0 ; unique
// MS2-PIN: ??$_Emplace_reallocate@AEBUUnk_CMISElem52@@@?$vector@UUnk_CMISElem52@@V?$CustomAllocator@UUnk_CMISElem52@@@efd@@@std@@QEAAPEAUUnk_CMISElem52@@QEAU2@AEBU2@@Z 0x1410e47a0 ; unique
// MS2-PIN: ??$_Emplace_reallocate@AEBW4Unk_CMISKindC@@@?$vector@W4Unk_CMISKindC@@V?$allocator@W4Unk_CMISKindC@@@std@@@std@@QEAAPEAW4Unk_CMISKindC@@QEAW42@AEBW42@@Z 0x1410e4c40 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/cubemapinformationservice_tail.h"
#include <NiTransform.h>

// Instantiate the real service containers without constructing DLL-local state.
template <class M> void Unk_CMISDistance(M& m)
{
    (void)std::distance(m.begin(), m.end());
}
template <class T, class A> void Unk_CMISBackout(T* p, A& a, T& x)
{
    std::_Uninitialized_backout_al<T*, A> b(p, a);
    b._Emplace_back(x);
}
template <class T, class A> void Unk_CMISBackoutRv(T* p, A& a, T&& x)
{
    std::_Uninitialized_backout_al<T*, A> b(p, a);
    b._Emplace_back(std::move(x));
}

template <class P> void Unk_CMISDistancePtr(P p)
{
    (void)std::distance(p, p);
}
template <class T, class A> void Unk_CMISDestroy(T* p, A& a)
{
    std::_Destroy_range(p, p, a);
}

typedef std::vector<Cube*> Unk_CMISCubePtrVec;
template <class V, class T> void Unk_CMISEmplace(V& v, T& x)
{
    const T& cx = x;
    v.push_back(cx);
}

void Unk_CMISDrive1410e29c0()
{
    { Unk_CMISIntVec v; int n = 0; Unk_CMISEmplace(v, n); }
    { Unk_CMISEntityIdVec v; egf::EntityID id; Unk_CMISEmplace(v, id); }
    { Unk_CMISEntVec v; egf::EntityPtr p; Unk_CMISEmplace(v, p); }
    { Unk_CMISStdEntVec v; egf::EntityPtr p; Unk_CMISEmplace(v, p); v.push_back(std::move(p)); }
    { Unk_CMISCubePtrVec v; Cube* p = 0; Unk_CMISEmplace(v, p); v.push_back(std::move(p)); }
    { Unk_CMISElem52Vec v; Unk_CMISElem52 e; Unk_CMISEmplace(v, e); }
    { Unk_CMISKindVec v; Unk_CMISKindC k = Unk_CMISKindC_None; Unk_CMISEmplace(v, k); }
    { efd::CustomAllocator<int> a; int* p = 0; Unk_CMISDestroy(p, a); }
    { efd::CustomAllocator<egf::EntityID> a; egf::EntityID* p = 0; Unk_CMISDestroy(p, a); }
    { efd::CustomAllocator<egf::EntityPtr> a; egf::EntityPtr* p = 0; Unk_CMISDestroy(p, a); Unk_CMISBackout(p, a, *p); Unk_CMISBackoutRv(p, a, std::move(*p)); }
    { Unk_CMISDistancePtr(static_cast<egf::EntityID*>(0)); Unk_CMISDistancePtr(static_cast<egf::EntityPtr*>(0)); }
    { efd::CustomAllocator<Unk_CMISElem52> a; Unk_CMISElem52* p = 0; Unk_CMISDestroy(p, a); }
    { std::allocator<Unk_CMISKindC> a; Unk_CMISKindC* p = 0; Unk_CMISDestroy(p, a); }
    { std::allocator<Cube*> a; Cube** p = 0; Unk_CMISDestroy(p, a); }
    { std::allocator<egf::EntityPtr> a; egf::EntityPtr* p = 0; Unk_CMISBackout(p, a, *p); Unk_CMISBackoutRv(p, a, std::move(*p)); }
    { efd::CustomAllocator<egf::EntityID> a; egf::EntityID* p = 0; Unk_CMISBackout(p, a, *p); Unk_CMISBackoutRv(p, a, std::move(*p)); }
    { efd::CustomAllocator<int> a; int* p = 0; Unk_CMISBackoutRv(p, a, std::move(*p)); }
    { std::allocator<Unk_CMISKindC> a; Unk_CMISKindC* p = 0; Unk_CMISBackoutRv(p, a, std::move(*p)); }
    { Unk_CMISMapIntUInt m; Unk_CMISDistance(m); }
    { Unk_CMISMapMark m; Unk_CMISDistance(m); }
    { Unk_CMISMapNear m; Unk_CMISDistance(m); }
    { Unk_CMISMapDoll m; Unk_CMISDistance(m); }
    { Unk_CMISMapSetEffect m; Unk_CMISDistance(m); }
    { Unk_CMISMapCube m; Unk_CMISDistance(m); }
    { Unk_CMISMapHead m; Unk_CMISDistance(m); }
    { Unk_CMISMapEntityId m; Unk_CMISDistance(m); }
    { Unk_CMISMapCubeTimer m; Unk_CMISDistance(m); }
    { Unk_CMISMapSaleState m; Unk_CMISDistance(m); }
    { Unk_CMISMapName m; Unk_CMISDistance(m); }
    { Unk_CMISMapEntityVal m; Unk_CMISDistance(m); }
    { Unk_CMISMapProp m; Unk_CMISDistance(m); }
    { Unk_CMISMapUid m; Unk_CMISDistance(m); }
    { Unk_CMISMapKindCount m; Unk_CMISDistance(m); }
}
// MS2-PIN: ??$_Emplace_back@V?$SmartPointer@VEntity@egf@@@efd@@@?$_Uninitialized_backout_al@PEAV?$SmartPointer@VEntity@egf@@@efd@@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@std@@QEAAX$$QEAV?$SmartPointer@VEntity@egf@@@efd@@@Z 0x1410e34e0 ; the rvalue (_Uninitialized_move) copy; the lvalue one is byte-identical but sits at 0x1410e3360-0x1410e3420
// MS2-PIN: ??$_Emplace_back@V?$SmartPointer@VEntity@egf@@@efd@@@?$_Uninitialized_backout_al@PEAV?$SmartPointer@VEntity@egf@@@efd@@V?$allocator@V?$SmartPointer@VEntity@egf@@@efd@@@std@@@std@@QEAAX$$QEAV?$SmartPointer@VEntity@egf@@@efd@@@Z 0x1410e3540 ; the rvalue (_Uninitialized_move) copy; the lvalue one is byte-identical but sits at 0x1410e3360-0x1410e3420
// MS2-PIN: ??$_Emplace_back@VEntityID@egf@@@?$_Uninitialized_backout_al@PEAVEntityID@egf@@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@QEAAX$$QEAVEntityID@egf@@@Z 0x1410e35a0 ; the rvalue (_Uninitialized_move) copy; the lvalue one is byte-identical but sits at 0x1410e3360-0x1410e3420
// w560: the SmartPointer<Entity> / EntityID vector rollback chains, by the exe destroy chain (0x1410e2bd0 -> 0x1410e2a20 -> 0x14111a810 -> 0x1410e28f0 -> 0x141151660 calls ??_G SmartPointer)
// MS2-PIN: ??$_Destroy_range@V?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@efd@@@std@@YAXPEAV?$SmartPointer@VEntity@egf@@@efd@@0AEAV?$CustomAllocator@V?$SmartPointer@VEntity@egf@@@efd@@@2@@Z 0x1410e2bd0
// MS2-PIN: ??$_Destroy_range@V?$CustomAllocator@VEntityID@egf@@@efd@@@std@@YAXPEAVEntityID@egf@@0AEAV?$CustomAllocator@VEntityID@egf@@@efd@@@Z 0x1410e2c20
