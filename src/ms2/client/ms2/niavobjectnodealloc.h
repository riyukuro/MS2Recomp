// The NiAVObject* node lists (GameObject vfunc_44 fills one; ChaosLightEffect, ClonePC, TextureOverrideEffectParam
// and ItemCustomizeController use it) and the NiAVObjectPtr vectors next to them allocate from the CRT heap in the exe:
// their allocate/deallocate (0x1410451c0 / 0x1410451f0 / 0x141045580 / 0x1410455b0) are std::_Allocate<16> /
// std::_Deallocate<16> (::operator new/delete), not the efd::_Malloc/_Free of the GB SDK's CustomAllocator. These explicit
// specializations keep the CustomAllocator names (and _Normal_allocator_traits) and use the exe's heap, so a list
// filled or freed on the exe side pairs with ours. Must be seen before any use of these containers.
#pragma once
#include <xmemory0>
#include <list>
#include <efd/customalloc.h>
#include <efd/SmartPointer.h>

class NiAVObject;
typedef std::_List_node<NiAVObject*, void*> Unk_NiAVObjectListNode;

// exe 0x1410451c0
template<> inline Unk_NiAVObjectListNode* efd::CustomAllocator<Unk_NiAVObjectListNode>::allocate(
    size_type count, CustomAllocator<void>::const_pointer)
{
    return static_cast<Unk_NiAVObjectListNode*>(std::_Allocate<std::_New_alignof<Unk_NiAVObjectListNode>>(
        std::_Get_size_of_n<sizeof(Unk_NiAVObjectListNode)>(count)));
}

// exe 0x141045580
template<> inline void efd::CustomAllocator<Unk_NiAVObjectListNode>::deallocate(pointer p, size_type count)
{
    std::_Deallocate<std::_New_alignof<Unk_NiAVObjectListNode>>(p, sizeof(Unk_NiAVObjectListNode) * count);
}

// exe 0x1410451f0
template<> inline efd::SmartPointer<NiAVObject>* efd::CustomAllocator<efd::SmartPointer<NiAVObject> >::allocate(
    size_type count, CustomAllocator<void>::const_pointer)
{
    return static_cast<efd::SmartPointer<NiAVObject>*>(std::_Allocate<std::_New_alignof<efd::SmartPointer<NiAVObject> >>(
        std::_Get_size_of_n<sizeof(efd::SmartPointer<NiAVObject>)>(count)));
}

// exe 0x1410455b0
template<> inline void efd::CustomAllocator<efd::SmartPointer<NiAVObject> >::deallocate(pointer p, size_type count)
{
    std::_Deallocate<std::_New_alignof<efd::SmartPointer<NiAVObject> >>(p, sizeof(efd::SmartPointer<NiAVObject>) * count);
}
