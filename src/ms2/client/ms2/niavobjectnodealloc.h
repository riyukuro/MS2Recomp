// The NiAVObject* node lists (GameObject vfunc_44 fills one; ChaosLightEffect, ClonePC, TextureOverrideEffectParam,
// ItemCustomizeController and PC use it) and the NiAVObjectPtr vectors next to them are plain std::list<NiAVObject*> and
// std::vector<NiAVObjectPtr> over std::allocator in the exe, not efd::list / efd::vector: their allocate (0x1410451c0 /
// 0x1410451f0) take no hint, destroy (0x1410430f0 / 0x141043100) is empty (_Default_allocator_traits), and the
// _Compressed_pair / ~vector / ~_List_alloc bodies have no allocator dtor (trivial std::allocator).
#pragma once
#include <xmemory0>
#include <list>
#include <vector>
#include <efd/customalloc.h>
#include <efd/SmartPointer.h>

class NiAVObject;
