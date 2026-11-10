// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The first Scaleform object of the exe's .text: small
// helpers of a statically linked Scaleform 4.1.18 obj (VS2008, no /Gy, so the whole obj is kept). Nothing in the exe
// calls or references the functions below; they are the obj's own copies of the vector constructor / copy constructor /
// destructor iterators, an ASString release and assign, a heap delete, the AS2 collector's root page allocation,
// AllocatorBaseLH<2> / <324>::Alloc and a builtin string lookup. The other functions in the range are matched
// elsewhere by identical bytes. Named FUN_<va>: the same templates' named copies are bound to other exe addresses.
// MS2-UNIT: unit_140001020
// MS2-TOOLSET: vc9v
// MS2-FLAGS: scaleform
// MS2-RANGE: 0x140001020-0x140001690 .text$mn
#define MS2_THIS_FILE ""

#include "../scaleform/include/kernel/sf_memory.h"
#include "../scaleform/include/gfx/gfx_asstring.h"

// Statically linked Scaleform library: built like the sfr_video units (the VS2008 SP1 cl with the vc11 options,
// MS2-TOOLSET: vc9v). Keep it C++03.

using namespace Scaleform;
using namespace Scaleform::GFx;

namespace Scaleform { namespace GFx { namespace AS2 {
class StringManager;
class GlobalContext { public: StringManager* GetStringManager() const; };   // exe 0x1429561c0
} } }

// The vector constructor iterator: runs ctor on count items of size bytes.
// @0x140001020
void ConstructArray(void* ptr, UPInt size, int count, void (*ctor)(void*))
{
    char* p = (char*)ptr;
    while (--count >= 0)
    {
        ctor(p);
        p += size;
    }
}

// ASString::~ASString on a node holder.
// @0x1400010b0
void ReleaseStringNode(ASStringNode** holder)
{
    (*holder)->Release();
}

// ASString::AssignNode: takes a reference on node and drops the old one.
// @0x1400010e0
void SetStringNode(ASStringNode** holder, ASStringNode* node)
{
    node->AddRef();
    (*holder)->Release();
    *holder = node;
}

// The vector copy constructor iterator: copies count items of size bytes from src to dst.
// @0x140001150
void FUN_140001150(void* dst, void* src, UPInt size, int count, void (*copyCtor)(void*, void*))
{
    while (--count >= 0)
    {
        copyCtor(dst, src);
        dst = (char*)dst + size;
        src = (char*)src + size;
    }
}

// The vector destructor iterator: runs dtor on count items of size bytes, last item first.
// @0x1400011b0
void FUN_1400011b0(void* ptr, UPInt size, int count, void (*dtor)(void*))
{
    char* p = (char*)ptr + count * size;
    while (--count >= 0)
    {
        p -= size;
        dtor(p);
    }
}

// AllocatorBaseLH<2>::Alloc (sf_allocator.h).
// @0x140001320
void* FUN_140001320(const void* pheapAddr, UPInt size, const char*, unsigned)
{
    return Memory::AllocAutoHeap(pheapAddr, size, AllocInfo(2, 0, 0));
}

namespace
{
struct U1020Object
{
    virtual void Slot0();
    virtual void Destroy();
};

// ArrayPagedBase layout: allocator (8 bytes); +0x08 Size; +0x10 NumPages; +0x18 MaxPages; +0x20 Pages.
struct U1020PagedArray
{
    void*  Reserved;
    UPInt  Size;
    UPInt  NumPages;
    UPInt  MaxPages;
    void** Pages;
};
}

// Destroys an object through its second virtual and frees it from the global heap.
// @0x140001420
void FUN_140001420(U1020Object* obj)
{
    obj->Destroy();
    Memory::Free(obj);
}

// ArrayPagedBase<const RefCountBaseGC*, 10, 5, AllocatorPagedLH_POD<..., 2>>::allocatePage (sf_arraypaged.h): the
// page table grows by 5 entries, a page holds 1024 pointers.
// @0x140001450
void AddPage(U1020PagedArray* a, UPInt nb)
{
    if (nb >= a->MaxPages)
    {
        if (a->Pages)
            a->Pages = (void**)Memory::Realloc(a->Pages, (a->MaxPages + 5) * sizeof(void*));
        else
            a->Pages = (void**)Memory::AllocAutoHeap(a, 5 * sizeof(void*), AllocInfo(2, 0, 0));
        a->MaxPages += 5;
    }
    a->Pages[nb] = Memory::AllocAutoHeap(a, 1024 * sizeof(void*), AllocInfo(2, 0, 0));
    a->NumPages++;
}

// AllocatorBaseLH<324>::Alloc (sf_allocator.h).
// @0x1400015f0
void* FUN_1400015f0(const void* pheapAddr, UPInt size, const char*, unsigned)
{
    return Memory::AllocAutoHeap(pheapAddr, size, AllocInfo(324, 0, 0));
}

// The idx-th string slot of the AS2 string manager.
// @0x140001660
ASStringNode** FUN_140001660(AS2::GlobalContext* gc, int idx)
{
    return (ASStringNode**)gc->GetStringManager() + idx;
}
