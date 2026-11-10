// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_141079ed0: the out-of-line glue of a
// family of small sequence containers. Four shapes repeat:
//   * 16 forwards that hand a raw node pointer and an uninitialised one-byte scratch to a per-type helper and pass
//     the helper's result straight back (0x141074140..0x141074320);
//   * 7 forwards that re-read a node through a per-type accessor and push it through one of the 16 (0x141072db0..);
//   * 10 "clamp to the global limit" wrappers: min(FUN_140190260(), <accessor>(<node getter>(p)));
//   * 10 "number of elements" wrappers returning the distance between two node-pointer getters divided by the
//     element size (1, 8, 16 or 24 bytes; 24 goes through a real idiv), plus the 0x0fffffffffffffff sentinel and a
//     handful of downcasts/upcasts that forward to 0x141062xxx / 0x141063xxx.
// The exe reads the one-byte scratch before anything writes it, so the source declares it uninitialised (C4700).
// All names invented from shape; the callee prototypes live in the neighbouring unit.
// MS2-UNIT: unit_141079ed0
// MS2-RANGE: 0x141079ed0-0x14107ac30 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2recover.h"

#include <utility>                               // std::_Min_value
#include <limits>
#include <efd/StdContainers.h>

typedef __int64 i64;
typedef unsigned __int64 u64;

// ---- unit-local views of the node shapes the accessors read ----
class NiTransform;
class NiMesh;
class NiAVObject;
class NiDataStreamRef;
struct Unk_UVRect;                               // defined in unit_141073440
#include "ms2/placeholder/meshmergerelems.h"   // Unk_StreamElementDesc, Unk_AtlasResult (as in unit_1410799d0)
typedef efd::map<unsigned char, unsigned char> Unk_ByteMap;
typedef efd::set<unsigned char> Unk_ByteSet;
typedef efd::vector<unsigned char> Unk_ByteVec;
typedef efd::set<NiAVObject*> Unk_ObjSet;
typedef efd::vector<NiMesh*> Unk_MeshVec;
typedef efd::map<NiMesh*, Unk_ByteMap> Unk_MeshByteMap;

struct Unk_Node0 { i64 m_nValue; };              // the field at +0
struct Unk_Node8 { i64 m_pad_00; i64 m_nValue; };// the field at +8

// ---- the container helpers this unit forwards to (defined outside it) ----
u64 FUN_141074140(void*, bool);                  // per-list insert; the flag is the uninitialised scratch
#include "ms2/client/ms2/charactermeshmerger.h"   // CCharacterMeshMerger::TexNode; 0x141074200 = _Max_size1 (CString,TexNode* map node)
#include <NiTransform.h>                          // 0x141074220 = _Max_size1 (NiTransform,Unk_MeshVec map node)
// 0x141074260 / 0x141074320 = _Normal_allocator_traits<..map<NiMesh*,Unk_UVRect> node / Unk_AtlasResult..>::_Max_size1
//

void* FUN_141072db0(void*);                      // per-type node accessors (forward 1)
// 0x141072e70 = _Tree_comp_alloc<..NiMesh*,Unk_UVRect..>::_Getal() const
struct Unk_TransformLess { bool operator()(const NiTransform& kA, const NiTransform& kB) const; };   // 0x141072ed0 = _Getal (CString map)
// 0x141072f30 = _Tree_comp_alloc<..NiTransform,Unk_MeshVec,Unk_TransformLess..>::_Getal() const

void* FUN_141073040(void*);                      // per-type node accessors (forward 2)
// 0x141073100 / 0x141073280 = _Vector_alloc<..Unk_StreamElementDesc / Unk_AtlasResult..>::_Getal() const
//

Unk_Node8* FUN_1410722e0(void*);                 // per-type node accessors reading +8
// 0x1410723a0 = _Tree_comp_alloc<..NiMesh*,Unk_UVRect..>::_Get_data() const

// 0x141063d00 / 0x141063d70 = vector<Unk_AtlasResult>::emplace_back<const&> / vector<Unk_StreamElementDesc>::emplace_back<&&>
//

// (was: void FUN_141075730(void*, void*, bool); the private _Select_on_container_copy_construction1)
// (was: void FUN_141075770(void*, void*, bool); the private _Select_on_container_copy_construction1)
// (was: void FUN_1410757b0(void*, void*, bool); the private _Select_on_container_copy_construction1)
// (was: void FUN_1410757f0(void*, void*, bool); the private _Select_on_container_copy_construction1)
// (was: void FUN_141075830(void*, void*, bool); the private _Select_on_container_copy_construction1)
// (was: void FUN_141075870(void*, void*, bool); the private _Select_on_container_copy_construction1)

Unk_Node0* FUN_1410749b0(void*);                 // the two node-pointer getters of a distance pair
// 0x141074a70 / 0x1410747f0 = std::vector<Unk_StreamElementDesc>::_Mylast / _Myfirst
//
// 0x141074bf0 / 0x141074970 = efd::vector<Unk_AtlasResult>::_Mylast / _Myfirst
//

// ---------------------------------------------------------------------------
// the sentinel and the 16 flag-passing forwards
// ---------------------------------------------------------------------------

// @0x141079ed0
u64 FUN_141079ed0(void* p)
{
    return 0x0fffffffffffffff;
}

// @0x141079ee0
u64 FUN_141079ee0(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<unsigned char>>::_Max_size1(*(const efd::CustomAllocator<unsigned char>*)p, bFlag);
}

// @0x141079f00
u64 FUN_141079f00(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<NiAVObject*>>::_Max_size1(*(const efd::CustomAllocator<NiAVObject*>*)p, bFlag);
}

// @0x141079f20
u64 FUN_141079f20(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<NiMesh*>>::_Max_size1(*(const efd::CustomAllocator<NiMesh*>*)p, bFlag);
}

// @0x141079f40
u64 FUN_141079f40(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<unsigned char, void*>>>::_Max_size1(*(const efd::CustomAllocator<std::_Tree_node<unsigned char, void*>>*)p, bFlag);
}

// @0x141079f60
u64 FUN_141079f60(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<NiAVObject*, void*>>>::_Max_size1(*(const efd::CustomAllocator<std::_Tree_node<NiAVObject*, void*>>*)p, bFlag);
}

// @0x141079f80
u64 FUN_141079f80(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<std::pair<const unsigned char, unsigned char>, void*>>>::_Max_size1(*(const efd::CustomAllocator<std::_Tree_node<std::pair<const unsigned char, unsigned char>, void*>>*)p, bFlag);
}

// @0x141079fa0
u64 FUN_141079fa0(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<std::pair<const CString, CCharacterMeshMerger::TexNode*>, void*>>>::_Max_size1(*(const efd::CustomAllocator<std::_Tree_node<std::pair<const CString, CCharacterMeshMerger::TexNode*>, void*>>*)p, bFlag);
}

// @0x141079fc0
u64 FUN_141079fc0(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<std::pair<const NiTransform, Unk_MeshVec>, void*>>>::_Max_size1(*(const efd::CustomAllocator<std::_Tree_node<std::pair<const NiTransform, Unk_MeshVec>, void*>>*)p, bFlag);
}

// @0x141079fe0
u64 FUN_141079fe0(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<std::pair<NiMesh* const, Unk_ByteMap>, void*>>>::_Max_size1(*(const efd::CustomAllocator<std::_Tree_node<std::pair<NiMesh* const, Unk_ByteMap>, void*>>*)p, bFlag);
}

// @0x14107a000
u64 FUN_14107a000(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<std::pair<NiMesh* const, Unk_UVRect>, void*>>>::_Max_size1(*(const efd::CustomAllocator<std::_Tree_node<std::pair<NiMesh* const, Unk_UVRect>, void*>>*)p, bFlag);
}

// @0x14107a020
u64 FUN_14107a020(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<Unk_ByteMap>>::_Max_size1(*(const efd::CustomAllocator<Unk_ByteMap>*)p, bFlag);
}

// @0x14107a040
u64 FUN_14107a040(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<Unk_ByteSet>>::_Max_size1(*(const efd::CustomAllocator<Unk_ByteSet>*)p, bFlag);
}

// @0x14107a060
u64 FUN_14107a060(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<Unk_ObjSet>>::_Max_size1(*(const efd::CustomAllocator<Unk_ObjSet>*)p, bFlag);
}

// @0x14107a080
u64 FUN_14107a080(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<Unk_ByteVec>>::_Max_size1(*(const efd::CustomAllocator<Unk_ByteVec>*)p, bFlag);
}

// @0x14107a0a0
u64 FUN_14107a0a0(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<Unk_MeshVec>>::_Max_size1(*(const efd::CustomAllocator<Unk_MeshVec>*)p, bFlag);
}

// @0x14107a0c0
u64 FUN_14107a0c0(void* p)
{
    std::true_type bFlag;
    return std::_Normal_allocator_traits<efd::CustomAllocator<Unk_AtlasResult>>::_Max_size1(*(const efd::CustomAllocator<Unk_AtlasResult>*)p, bFlag);
}

// ---------------------------------------------------------------------------
// forwards through a per-type node accessor
// ---------------------------------------------------------------------------

// @0x14107a0e0
u64 FUN_14107a0e0(void* p)
{
    return FUN_141079f80((void*)&((const Unk_ByteMap*)p)->_Getal());
}

// @0x14107a100
u64 FUN_14107a100(void* p)
{
    return FUN_141079fe0((void*)&((const Unk_MeshByteMap*)p)->_Getal());
}

// @0x14107a120
u64 FUN_14107a120(void* p)
{
    return FUN_14107a000((void*)&((const efd::map<NiMesh*, Unk_UVRect>*)p)->_Getal());
}

// @0x14107a140
u64 FUN_14107a140(void* p)
{
    return FUN_141079fa0((void*)&((const efd::map<CString, CCharacterMeshMerger::TexNode*>*)p)->_Getal());
}

// @0x14107a160
u64 FUN_14107a160(void* p)
{
    return FUN_141079fc0((void*)&((const efd::map<NiTransform, Unk_MeshVec, Unk_TransformLess>*)p)->_Getal());
}

// @0x14107a180
u64 FUN_14107a180(void* p)
{
    return FUN_141079f40((void*)&((const Unk_ByteSet*)p)->_Getal());
}

// @0x14107a1a0
u64 FUN_14107a1a0(void* p)
{
    return FUN_141079f60((void*)&((const Unk_ObjSet*)p)->_Getal());
}

// ---------------------------------------------------------------------------
// clamped element counts: min(the global limit, the list's own count)
// (`std::_Min_value` is the STL helper the exe calls out of line here)
// ---------------------------------------------------------------------------

// @0x14107a1c0
u64 FUN_14107a1c0(void* p)
{
    u64 nValue = FUN_141079ee0((void*)&((const Unk_ByteVec*)p)->_Getal());
    u64 nLimit = (std::numeric_limits<i64>::max)();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a210
u64 FUN_14107a210(void* p)
{
    u64 nValue = FUN_141079f00((void*)&((const efd::vector<NiDataStreamRef*>*)p)->_Getal());
    u64 nLimit = (std::numeric_limits<i64>::max)();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a260
u64 FUN_14107a260(void* p)
{
    u64 nValue = FUN_141079f20((void*)&((const Unk_MeshVec*)p)->_Getal());
    u64 nLimit = (std::numeric_limits<i64>::max)();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a2b0
u64 FUN_14107a2b0(void* p)
{
    u64 nValue = FUN_141079ed0((void*)&((const std::vector<Unk_StreamElementDesc>*)p)->_Getal());
    u64 nLimit = (std::numeric_limits<i64>::max)();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a300
u64 FUN_14107a300(void* p)
{
    u64 nValue = FUN_14107a020((void*)&((const efd::vector<Unk_ByteMap>*)p)->_Getal());
    u64 nLimit = (std::numeric_limits<i64>::max)();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a350
u64 FUN_14107a350(void* p)
{
    u64 nValue = FUN_14107a040((void*)&((const efd::vector<Unk_ByteSet>*)p)->_Getal());
    u64 nLimit = (std::numeric_limits<i64>::max)();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a3a0
u64 FUN_14107a3a0(void* p)
{
    u64 nValue = FUN_14107a060((void*)&((const efd::vector<Unk_ObjSet>*)p)->_Getal());
    u64 nLimit = (std::numeric_limits<i64>::max)();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a3f0
u64 FUN_14107a3f0(void* p)
{
    u64 nValue = FUN_14107a080((void*)&((const efd::vector<Unk_ByteVec>*)p)->_Getal());
    u64 nLimit = (std::numeric_limits<i64>::max)();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a440
u64 FUN_14107a440(void* p)
{
    u64 nValue = FUN_14107a0a0((void*)&((const efd::vector<Unk_MeshVec>*)p)->_Getal());
    u64 nLimit = (std::numeric_limits<i64>::max)();
    return std::_Min_value(nLimit, nValue);
}

// @0x14107a490
u64 FUN_14107a490(void* p)
{
    u64 nValue = FUN_14107a0c0((void*)&((const efd::vector<Unk_AtlasResult>*)p)->_Getal());
    u64 nLimit = (std::numeric_limits<i64>::max)();
    return std::_Min_value(nLimit, nValue);
}

// ---------------------------------------------------------------------------
// the element-count shims
// ---------------------------------------------------------------------------

// @0x14107a4e0
void FUN_14107a4e0(void* p)
{
    std::addressof(*(std::pair<const unsigned char, unsigned char>*)p);
}

// @0x14107a500
void FUN_14107a500(void* p)
{
    std::addressof(*(std::pair<const NiTransform, efd::vector<NiMesh*>>*)p);
}

// @0x14107a520
void FUN_14107a520(void* p)
{
    std::addressof(*(std::pair<NiMesh* const, Unk_ByteMap>*)p);
}

// @0x14107a540
void FUN_14107a540(void* p)
{
    std::addressof(*(std::pair<NiMesh* const, Unk_UVRect>*)p);
}

// @0x14107a560
void FUN_14107a560(void* p)
{
    std::_Get_unwrapped((const unsigned char*)p);
}

// @0x14107a580
void AddDataStreamRef(void* p1, void* p2)
{
    ((efd::vector<NiDataStreamRef*>*)p1)->emplace_back(*(NiDataStreamRef* const*)p2);
}

// @0x14107a5b0
void AddMesh(void* p1, void* p2)
{
    ((Unk_MeshVec*)p1)->emplace_back(*(NiMesh* const*)p2);
}

// @0x14107a5e0
void FUN_14107a5e0(void* p1, void* p2)
{
    ((std::vector<Unk_StreamElementDesc>*)p1)->emplace_back(std::move(*(Unk_StreamElementDesc*)p2));
}

// @0x14107a610
void FUN_14107a610(void* p1, void* p2)
{
    ((efd::vector<Unk_ByteMap>*)p1)->emplace_back(std::move(*(Unk_ByteMap*)p2));
}

// @0x14107a640
void FUN_14107a640(void* p1, void* p2)
{
    ((efd::vector<Unk_ByteSet>*)p1)->emplace_back(std::move(*(Unk_ByteSet*)p2));
}

// @0x14107a670
void FUN_14107a670(void* p1, void* p2)
{
    ((efd::vector<Unk_ObjSet>*)p1)->emplace_back(std::move(*(Unk_ObjSet*)p2));
}

// @0x14107a6a0
void FUN_14107a6a0(void* p1, void* p2)
{
    ((efd::vector<Unk_ByteVec>*)p1)->emplace_back(std::move(*(Unk_ByteVec*)p2));
}

// @0x14107a6d0
void FUN_14107a6d0(void* p1, void* p2)
{
    ((efd::vector<Unk_MeshVec>*)p1)->emplace_back(std::move(*(Unk_MeshVec*)p2));
}

// @0x14107a700
void FUN_14107a700(void* p1, void* p2)
{
    ((efd::vector<Unk_MeshVec>*)p1)->emplace_back(*(const Unk_MeshVec*)p2);
}

// @0x14107a730
void FUN_14107a730(void* p1, void* p2)
{
    ((efd::vector<Unk_AtlasResult>*)p1)->emplace_back(*(const Unk_AtlasResult*)p2);
}

// 0x14107a760: the real select_on_container_copy_construction (was the FUN_14107a760 wrapper)
template efd::CustomAllocator<unsigned char> std::_Normal_allocator_traits<efd::CustomAllocator<unsigned char>>::select_on_container_copy_construction(const efd::CustomAllocator<unsigned char>&);
//
//
//
//
//
//
//

// 0x14107a7a0: the real select_on_container_copy_construction (was the FUN_14107a7a0 wrapper)
template efd::CustomAllocator<NiMesh*> std::_Normal_allocator_traits<efd::CustomAllocator<NiMesh*>>::select_on_container_copy_construction(const efd::CustomAllocator<NiMesh*>&);
//
//
//
//
//
//
//

// 0x14107a7e0: the real select_on_container_copy_construction (was the FUN_14107a7e0 wrapper)
template efd::CustomAllocator<std::_Tree_node<unsigned char, void*>> std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<unsigned char, void*>>>::select_on_container_copy_construction(const efd::CustomAllocator<std::_Tree_node<unsigned char, void*>>&);
//
//
//
//
//
//
//

// 0x14107a820: the real select_on_container_copy_construction (was the FUN_14107a820 wrapper)
template efd::CustomAllocator<std::_Tree_node<NiAVObject*, void*>> std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<NiAVObject*, void*>>>::select_on_container_copy_construction(const efd::CustomAllocator<std::_Tree_node<NiAVObject*, void*>>&);
//
//
//
//
//
//
//

// 0x14107a860: the real select_on_container_copy_construction (was the FUN_14107a860 wrapper)
template efd::CustomAllocator<std::_Tree_node<std::pair<const unsigned char, unsigned char>, void*>> std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<std::pair<const unsigned char, unsigned char>, void*>>>::select_on_container_copy_construction(const efd::CustomAllocator<std::_Tree_node<std::pair<const unsigned char, unsigned char>, void*>>&);
//
//
//
//
//
//
//

// 0x14107a8a0: the real select_on_container_copy_construction (was the FUN_14107a8a0 wrapper)
template efd::CustomAllocator<std::_Tree_node<std::pair<NiMesh* const, Unk_UVRect>, void*>> std::_Normal_allocator_traits<efd::CustomAllocator<std::_Tree_node<std::pair<NiMesh* const, Unk_UVRect>, void*>>>::select_on_container_copy_construction(const efd::CustomAllocator<std::_Tree_node<std::pair<NiMesh* const, Unk_UVRect>, void*>>&);
//
//
//
//
//
//
//

// ---------------------------------------------------------------------------
// the field-at-+8 readers
// ---------------------------------------------------------------------------

// @0x14107a8e0
i64 FUN_14107a8e0(void* p)
{
    return ((const Unk_ByteMap*)p)->_Get_data()._Mysize;
}

// @0x14107a900
i64 FUN_14107a900(void* p)
{
    return ((const Unk_MeshByteMap*)p)->_Get_data()._Mysize;
}

// @0x14107a920
i64 FUN_14107a920(void* p)
{
    return ((const efd::map<NiMesh*, Unk_UVRect>*)p)->_Get_data()._Mysize;
}

// @0x14107a940
i64 FUN_14107a940(void* p)
{
    return ((const Unk_ByteSet*)p)->_Get_data()._Mysize;
}

// @0x14107a960
i64 FUN_14107a960(void* p)
{
    return ((const Unk_ObjSet*)p)->_Get_data()._Mysize;
}

// ---------------------------------------------------------------------------
// the element distances: the two node pointers differ by whole elements, so the
// quotient is a real division (shifts for 8/16, an idiv for the 24-byte element)
// ---------------------------------------------------------------------------

// @0x14107a980
i64 FUN_14107a980(void* p)
{
    return (i64)((const Unk_ByteVec*)p)->_Mylast() - (i64)((const Unk_ByteVec*)p)->_Myfirst();
}

// @0x14107a9c0
i64 FUN_14107a9c0(void* p)
{
    return ((i64)((const efd::vector<NiDataStreamRef*>*)p)->_Mylast() - (i64)((const efd::vector<NiDataStreamRef*>*)p)->_Myfirst()) >> 3;
}

// @0x14107aa00
i64 FUN_14107aa00(void* p)
{
    return ((i64)((const Unk_MeshVec*)p)->_Mylast() - (i64)((const Unk_MeshVec*)p)->_Myfirst()) >> 3;
}

// @0x14107aa40
i64 FUN_14107aa40(void* p)
{
    return ((i64)((const std::vector<Unk_StreamElementDesc>*)p)->_Mylast() - (i64)((const std::vector<Unk_StreamElementDesc>*)p)->_Myfirst()) >> 4;
}

// @0x14107aa80
i64 FUN_14107aa80(void* p)
{
    return ((i64)((const efd::vector<Unk_ByteMap>*)p)->_Mylast() - (i64)((const efd::vector<Unk_ByteMap>*)p)->_Myfirst()) >> 4;
}

// @0x14107aac0
i64 FUN_14107aac0(void* p)
{
    return ((i64)((const efd::vector<Unk_ByteSet>*)p)->_Mylast() - (i64)((const efd::vector<Unk_ByteSet>*)p)->_Myfirst()) >> 4;
}

// @0x14107ab00
i64 FUN_14107ab00(void* p)
{
    return ((i64)((const efd::vector<Unk_ObjSet>*)p)->_Mylast() - (i64)((const efd::vector<Unk_ObjSet>*)p)->_Myfirst()) >> 4;
}

// @0x14107ab40
i64 FUN_14107ab40(void* p)
{
    return ((i64)((const efd::vector<Unk_ByteVec>*)p)->_Mylast() - (i64)((const efd::vector<Unk_ByteVec>*)p)->_Myfirst()) / 0x18;
}

// @0x14107ab90
i64 FUN_14107ab90(void* p)
{
    return ((i64)((const efd::vector<Unk_MeshVec>*)p)->_Mylast() - (i64)((const efd::vector<Unk_MeshVec>*)p)->_Myfirst()) / 0x18;
}

// @0x14107abe0
i64 FUN_14107abe0(void* p)
{
    return ((i64)((const efd::vector<Unk_AtlasResult>*)p)->_Mylast() - (i64)((const efd::vector<Unk_AtlasResult>*)p)->_Myfirst()) / 0x18;
}
