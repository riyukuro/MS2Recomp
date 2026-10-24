// Nexon Messenger STL construction glue recovered from the decompilation.
// MS2-UNIT: unit_1415e2390
// MS2-RANGE: 0x1415e2390-0x1415e5c20 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/unnamed/unk_stlglue.h"
#include <cstring>
#include <new>
#include <string>

extern void* FUN_140159860(unsigned __int64 n, void* p);
extern void FUN_1415f9a90(void* p, const char* value);
extern void FUN_1415f9b80(void* p, const char* value);
extern void FUN_1415f93d0(void* p, unsigned int flags);
extern void FUN_1415ce470(void* p, const void* value);
extern void* FUN_1415e4ea0(void* p);
extern ptrdiff_t FUN_1415d44c0(Unk_StlElem<0x10>* first, Unk_StlElem<0x10>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d44f0(Unk_StlElem<0x18>* first, Unk_StlElem<0x18>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4520(Unk_StlElem<0x58>* first, Unk_StlElem<0x58>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4550(Unk_StlElem<0x30>* first, Unk_StlElem<0x30>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4580(Unk_StlElem<0x98>* first, Unk_StlElem<0x98>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d45b0(Unk_StlElem<0x220>* first, Unk_StlElem<0x220>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d45e0(Unk_StlElem<0x128>* first, Unk_StlElem<0x128>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4610(Unk_StlElem<0x118>* first, Unk_StlElem<0x118>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4640(Unk_StlElem<0x580>* first, Unk_StlElem<0x580>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4670(Unk_StlElem<0x18>* first, Unk_StlElem<0x18>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d46a0(Unk_StlElem<0x14a8>* first, Unk_StlElem<0x14a8>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d46d0(Unk_StlElem<0x18>* first, Unk_StlElem<0x18>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4700(Unk_StlElem<0xb8>* first, Unk_StlElem<0xb8>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4730(Unk_StlElem<0x58>* first, Unk_StlElem<0x58>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4760(Unk_StlElem<0xae8>* first, Unk_StlElem<0xae8>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4790(Unk_StlElem<0xc8>* first, Unk_StlElem<0xc8>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d47c0(Unk_StlElem<0xf8>* first, Unk_StlElem<0xf8>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d47f0(Unk_StlElem<0x490>* first, Unk_StlElem<0x490>* last, std::random_access_iterator_tag);
extern ptrdiff_t FUN_1415d4820(Unk_StlElem<0x30>* first, Unk_StlElem<0x30>* last, std::random_access_iterator_tag);

static const char nm_empty[] = "";

static void nm_copy_cnm_string(void* dst, const char* src, size_t capacity)
{
    if (!src) return;
    size_t length = 0;
    while (length + 1 < capacity && src[length]) ++length;
    char* buffer = static_cast<char*>(::operator new(capacity));
    std::memcpy(buffer, src, length);
    buffer[length] = '\0';
    *reinterpret_cast<char**>(dst) = buffer;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5820
void FUN_1415e5820(void* p, const void* value)
{
    *reinterpret_cast<const char**>(p) = nm_empty; nm_copy_cnm_string(p, static_cast<const char*>(value), 9);
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5860
void* FUN_1415e5860(void* p)
{
    *reinterpret_cast<const char**>(p) = nm_empty; return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5880
void* FUN_1415e5880(void* p)
{
    *reinterpret_cast<const char**>(p) = nm_empty; return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e58a0
void* FUN_1415e58a0(void* p, const void* const* value)
{
    *reinterpret_cast<const char**>(p) = nm_empty; nm_copy_cnm_string(p, static_cast<const char*>(*value), 0x1000); return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e58e0
void* FUN_1415e58e0(void* p, const void* value)
{
    *reinterpret_cast<const char**>(p) = nm_empty; nm_copy_cnm_string(p, static_cast<const char*>(value), 0x1000); return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5920
void* FUN_1415e5920(void* p)
{
    *reinterpret_cast<const char**>(p) = nm_empty; return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5940
void* FUN_1415e5940(void* p, const void* value)
{
    *reinterpret_cast<const char**>(p) = nm_empty; nm_copy_cnm_string(p, static_cast<const char*>(value), 0x15e); return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5980
void* FUN_1415e5980(void* p)
{
    *reinterpret_cast<const char**>(p) = nm_empty; return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5a40
void* FUN_1415e5a40(void* p, const void* const* value)
{
    *reinterpret_cast<const char**>(p) = nm_empty; nm_copy_cnm_string(p, static_cast<const char*>(*value), 0x40); return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5a80
void* FUN_1415e5a80(void* p, const void* value)
{
    *reinterpret_cast<const char**>(p) = nm_empty; nm_copy_cnm_string(p, static_cast<const char*>(value), 0x40); return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5ac0
void* FUN_1415e5ac0(void* p)
{
    *reinterpret_cast<const char**>(p) = nm_empty; return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5ae0
void* FUN_1415e5ae0(void* p, const void* const* value)
{
    *reinterpret_cast<const char**>(p) = nm_empty; nm_copy_cnm_string(p, static_cast<const char*>(*value), 0x400); return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5b20
void* FUN_1415e5b20(void* p, const void* value)
{
    *reinterpret_cast<const char**>(p) = nm_empty; nm_copy_cnm_string(p, static_cast<const char*>(value), 0x400); return p;
}

// MS2-FUNCTIONAL: initializes the fixed-capacity CNM string storage and copies at most capacity minus one bytes.
// @0x1415e5b60
void* FUN_1415e5b60(void* p)
{
    *reinterpret_cast<const char**>(p) = nm_empty; return p;
}

// MS2-FUNCTIONAL: copies the 12-byte record exactly as recovered from the loop in the decompilation.
// @0x1415e57f0
unsigned char* FUN_1415e57f0(unsigned char* dst, const unsigned char* src)
{
    std::memcpy(dst, src, 0x0c);
    return dst;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5330
void* FUN_1415e5330(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x10>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5360
void* FUN_1415e5360(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x18>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5390
void* FUN_1415e5390(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x58>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e53c0
void* FUN_1415e53c0(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x30>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e53f0
void* FUN_1415e53f0(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x98>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5420
void* FUN_1415e5420(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x220>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5450
void* FUN_1415e5450(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x128>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5480
void* FUN_1415e5480(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x118>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e54b0
void* FUN_1415e54b0(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x580>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e54e0
void* FUN_1415e54e0(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x18>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5510
void* FUN_1415e5510(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x14a8>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5540
void* FUN_1415e5540(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x18>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5570
void* FUN_1415e5570(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0xb8>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e55a0
void* FUN_1415e55a0(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x58>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e55d0
void* FUN_1415e55d0(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0xae8>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5600
void* FUN_1415e5600(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0xc8>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5630
void* FUN_1415e5630(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0xf8>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5660
void* FUN_1415e5660(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x490>*>(p) + n;
}

// MS2-FUNCTIONAL: advances the recovered pointer by the requested number of elements.
// @0x1415e5690
void* FUN_1415e5690(void* p, ptrdiff_t n)
{
    return static_cast<Unk_StlElem<0x30>*>(p) + n;
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3c80
ptrdiff_t FUN_1415e3c80(void* first, void* last)
{
    return FUN_1415d44c0(static_cast<Unk_StlElem<0x10>*>(first), static_cast<Unk_StlElem<0x10>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3cb0
ptrdiff_t FUN_1415e3cb0(void* first, void* last)
{
    return FUN_1415d44f0(static_cast<Unk_StlElem<0x18>*>(first), static_cast<Unk_StlElem<0x18>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3ce0
ptrdiff_t FUN_1415e3ce0(void* first, void* last)
{
    return FUN_1415d4520(static_cast<Unk_StlElem<0x58>*>(first), static_cast<Unk_StlElem<0x58>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3d10
ptrdiff_t FUN_1415e3d10(void* first, void* last)
{
    return FUN_1415d4550(static_cast<Unk_StlElem<0x30>*>(first), static_cast<Unk_StlElem<0x30>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3d40
ptrdiff_t FUN_1415e3d40(void* first, void* last)
{
    return FUN_1415d4580(static_cast<Unk_StlElem<0x98>*>(first), static_cast<Unk_StlElem<0x98>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3d70
ptrdiff_t FUN_1415e3d70(void* first, void* last)
{
    return FUN_1415d45b0(static_cast<Unk_StlElem<0x220>*>(first), static_cast<Unk_StlElem<0x220>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3da0
ptrdiff_t FUN_1415e3da0(void* first, void* last)
{
    return FUN_1415d45e0(static_cast<Unk_StlElem<0x128>*>(first), static_cast<Unk_StlElem<0x128>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3dd0
ptrdiff_t FUN_1415e3dd0(void* first, void* last)
{
    return FUN_1415d4610(static_cast<Unk_StlElem<0x118>*>(first), static_cast<Unk_StlElem<0x118>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3e00
ptrdiff_t FUN_1415e3e00(void* first, void* last)
{
    return FUN_1415d4640(static_cast<Unk_StlElem<0x580>*>(first), static_cast<Unk_StlElem<0x580>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3e30
ptrdiff_t FUN_1415e3e30(void* first, void* last)
{
    return FUN_1415d4670(static_cast<Unk_StlElem<0x18>*>(first), static_cast<Unk_StlElem<0x18>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3e60
ptrdiff_t FUN_1415e3e60(void* first, void* last)
{
    return FUN_1415d46a0(static_cast<Unk_StlElem<0x14a8>*>(first), static_cast<Unk_StlElem<0x14a8>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3e90
ptrdiff_t FUN_1415e3e90(void* first, void* last)
{
    return FUN_1415d46d0(static_cast<Unk_StlElem<0x18>*>(first), static_cast<Unk_StlElem<0x18>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3ec0
ptrdiff_t FUN_1415e3ec0(void* first, void* last)
{
    return FUN_1415d4700(static_cast<Unk_StlElem<0xb8>*>(first), static_cast<Unk_StlElem<0xb8>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3ef0
ptrdiff_t FUN_1415e3ef0(void* first, void* last)
{
    return FUN_1415d4730(static_cast<Unk_StlElem<0x58>*>(first), static_cast<Unk_StlElem<0x58>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3f20
ptrdiff_t FUN_1415e3f20(void* first, void* last)
{
    return FUN_1415d4760(static_cast<Unk_StlElem<0xae8>*>(first), static_cast<Unk_StlElem<0xae8>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3f50
ptrdiff_t FUN_1415e3f50(void* first, void* last)
{
    return FUN_1415d4790(static_cast<Unk_StlElem<0xc8>*>(first), static_cast<Unk_StlElem<0xc8>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3f80
ptrdiff_t FUN_1415e3f80(void* first, void* last)
{
    return FUN_1415d47c0(static_cast<Unk_StlElem<0xf8>*>(first), static_cast<Unk_StlElem<0xf8>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3fb0
ptrdiff_t FUN_1415e3fb0(void* first, void* last)
{
    return FUN_1415d47f0(static_cast<Unk_StlElem<0x490>*>(first), static_cast<Unk_StlElem<0x490>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: computes the decompiled random-access iterator distance via its recovered helper.
// @0x1415e3fe0
ptrdiff_t FUN_1415e3fe0(void* first, void* last)
{
    return FUN_1415d4820(static_cast<Unk_StlElem<0x30>*>(first), static_cast<Unk_StlElem<0x30>*>(last), std::random_access_iterator_tag{});
}

// MS2-FUNCTIONAL: follows the decompiled allocator construction path and calls the recovered element copy helper.
// @0x1415e23e0
void FUN_1415e23e0(void*, void* p, void* pVal)
{
    void* pObject = FUN_140159860(0x10, p);
    const void* value = reinterpret_cast<const void*>(FUN_1415e4ea0(pVal));
    FUN_1415ce470(pObject, value);
}

// MS2-FUNCTIONAL: reproduces the allocator-traits construction operation recovered at 0x1415e2430.
// @0x1415e2430
void FUN_1415e2430(void*, Unk_StlElem<0x10>* p, Unk_StlElem<0x10>* pVal)
{
    std::memcpy(p, pVal, 0x10);
}
// MS2-PIN: ?FUN_1415e2430@@YAXPEAXPEAU?$Unk_StlElem@$0BA@@@1@Z 0x1415e2430

// MS2-FUNCTIONAL: reproduces the allocator-traits construction operation recovered at 0x1415e2480.
// @0x1415e2480
void FUN_1415e2480(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    std::memcpy(p, pVal, 0x18);
}
// MS2-PIN: ?FUN_1415e2480@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2480

// MS2-FUNCTIONAL: reproduces the allocator-traits construction operation recovered at 0x1415e24d0.
// @0x1415e24d0
void FUN_1415e24d0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    ::new (p) std::string(*reinterpret_cast<const std::string*>(pVal));
}
// MS2-PIN: ?FUN_1415e24d0@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e24d0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCateFriendInfo's copy constructor.
// @0x1415e2520
void FUN_1415e2520(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMCateFriendInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMCateFriendInfo(*reinterpret_cast<const CNMCateFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2520@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e2520

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCateFriendInfo's copy constructor.
// @0x1415e2570
void FUN_1415e2570(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMCateFriendInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMCateFriendInfo(*reinterpret_cast<const CNMCateFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2570@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e2570

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCateFriendInfo's copy constructor.
// @0x1415e25c0
void FUN_1415e25c0(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMCateFriendInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMCateFriendInfo(*reinterpret_cast<const CNMCateFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e25c0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e25c0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChannelMemberInfo's copy constructor.
// @0x1415e2610
void FUN_1415e2610(void*, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal)
{
    auto* pObject = static_cast<CNMChannelMemberInfo*>(FUN_140159860(0x30, p));
    ::new (pObject) CNMChannelMemberInfo(*reinterpret_cast<const CNMChannelMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2610@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x1415e2610

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChannelMemberInfo's copy constructor.
// @0x1415e2660
void FUN_1415e2660(void*, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal)
{
    auto* pObject = static_cast<CNMChannelMemberInfo*>(FUN_140159860(0x30, p));
    ::new (pObject) CNMChannelMemberInfo(*reinterpret_cast<const CNMChannelMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2660@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x1415e2660

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChannelMemberInfo's copy constructor.
// @0x1415e26b0
void FUN_1415e26b0(void*, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal)
{
    auto* pObject = static_cast<CNMChannelMemberInfo*>(FUN_140159860(0x30, p));
    ::new (pObject) CNMChannelMemberInfo(*reinterpret_cast<const CNMChannelMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e26b0@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x1415e26b0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCharacter's copy constructor.
// @0x1415e2700
void FUN_1415e2700(void*, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal)
{
    auto* pObject = static_cast<CNMCharacter*>(FUN_140159860(0x98, p));
    ::new (pObject) CNMCharacter(*reinterpret_cast<const CNMCharacter*>(pVal));
}
// MS2-PIN: ?FUN_1415e2700@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x1415e2700

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCharacter's copy constructor.
// @0x1415e2750
void FUN_1415e2750(void*, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal)
{
    auto* pObject = static_cast<CNMCharacter*>(FUN_140159860(0x98, p));
    ::new (pObject) CNMCharacter(*reinterpret_cast<const CNMCharacter*>(pVal));
}
// MS2-PIN: ?FUN_1415e2750@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x1415e2750

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMCharacter's copy constructor.
// @0x1415e27a0
void FUN_1415e27a0(void*, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal)
{
    auto* pObject = static_cast<CNMCharacter*>(FUN_140159860(0x98, p));
    ::new (pObject) CNMCharacter(*reinterpret_cast<const CNMCharacter*>(pVal));
}
// MS2-PIN: ?FUN_1415e27a0@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x1415e27a0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChatRoomMemberInfo's copy constructor.
// @0x1415e27f0
void FUN_1415e27f0(void*, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal)
{
    auto* pObject = static_cast<CNMChatRoomMemberInfo*>(FUN_140159860(0x220, p));
    ::new (pObject) CNMChatRoomMemberInfo(*reinterpret_cast<const CNMChatRoomMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e27f0@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x1415e27f0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChatRoomMemberInfo's copy constructor.
// @0x1415e2840
void FUN_1415e2840(void*, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal)
{
    auto* pObject = static_cast<CNMChatRoomMemberInfo*>(FUN_140159860(0x220, p));
    ::new (pObject) CNMChatRoomMemberInfo(*reinterpret_cast<const CNMChatRoomMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2840@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x1415e2840

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMChatRoomMemberInfo's copy constructor.
// @0x1415e2890
void FUN_1415e2890(void*, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal)
{
    auto* pObject = static_cast<CNMChatRoomMemberInfo*>(FUN_140159860(0x220, p));
    ::new (pObject) CNMChatRoomMemberInfo(*reinterpret_cast<const CNMChatRoomMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2890@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x1415e2890

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFileEvent's copy constructor.
// @0x1415e28e0
void FUN_1415e28e0(void*, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal)
{
    auto* pObject = static_cast<CNMFileEvent*>(FUN_140159860(0x128, p));
    ::new (pObject) CNMFileEvent(*reinterpret_cast<const CNMFileEvent*>(pVal));
}
// MS2-PIN: ?FUN_1415e28e0@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x1415e28e0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFileEvent's copy constructor.
// @0x1415e2930
void FUN_1415e2930(void*, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal)
{
    auto* pObject = static_cast<CNMFileEvent*>(FUN_140159860(0x128, p));
    ::new (pObject) CNMFileEvent(*reinterpret_cast<const CNMFileEvent*>(pVal));
}
// MS2-PIN: ?FUN_1415e2930@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x1415e2930

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFileEvent's copy constructor.
// @0x1415e2980
void FUN_1415e2980(void*, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal)
{
    auto* pObject = static_cast<CNMFileEvent*>(FUN_140159860(0x128, p));
    ::new (pObject) CNMFileEvent(*reinterpret_cast<const CNMFileEvent*>(pVal));
}
// MS2-PIN: ?FUN_1415e2980@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x1415e2980

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFilePath's copy constructor.
// @0x1415e29d0
void FUN_1415e29d0(void*, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal)
{
    auto* pObject = static_cast<CNMFilePath*>(FUN_140159860(0x118, p));
    ::new (pObject) CNMFilePath(*reinterpret_cast<const CNMFilePath*>(pVal));
}
// MS2-PIN: ?FUN_1415e29d0@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x1415e29d0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFilePath's copy constructor.
// @0x1415e2a20
void FUN_1415e2a20(void*, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal)
{
    auto* pObject = static_cast<CNMFilePath*>(FUN_140159860(0x118, p));
    ::new (pObject) CNMFilePath(*reinterpret_cast<const CNMFilePath*>(pVal));
}
// MS2-PIN: ?FUN_1415e2a20@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x1415e2a20

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFilePath's copy constructor.
// @0x1415e2a70
void FUN_1415e2a70(void*, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal)
{
    auto* pObject = static_cast<CNMFilePath*>(FUN_140159860(0x118, p));
    ::new (pObject) CNMFilePath(*reinterpret_cast<const CNMFilePath*>(pVal));
}
// MS2-PIN: ?FUN_1415e2a70@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x1415e2a70

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFindUserInfo's copy constructor.
// @0x1415e2ac0
void FUN_1415e2ac0(void*, Unk_StlElem<0xe0>* p, Unk_StlElem<0xe0>* pVal)
{
    auto* pObject = static_cast<CNMFindUserInfo*>(FUN_140159860(0xe0, p));
    ::new (pObject) CNMFindUserInfo(*reinterpret_cast<const CNMFindUserInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2ac0@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@1@Z 0x1415e2ac0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFindUserInfo's copy constructor.
// @0x1415e2b10
void FUN_1415e2b10(void*, Unk_StlElem<0xe0>* p, Unk_StlElem<0xe0>* pVal)
{
    auto* pObject = static_cast<CNMFindUserInfo*>(FUN_140159860(0xe0, p));
    ::new (pObject) CNMFindUserInfo(*reinterpret_cast<const CNMFindUserInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2b10@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@1@Z 0x1415e2b10

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFriendInfo's copy constructor.
// @0x1415e2b60
void FUN_1415e2b60(void*, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal)
{
    auto* pObject = static_cast<CNMFriendInfo*>(FUN_140159860(0x580, p));
    ::new (pObject) CNMFriendInfo(*reinterpret_cast<const CNMFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2b60@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1415e2b60

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFriendInfo's copy constructor.
// @0x1415e2bb0
void FUN_1415e2bb0(void*, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal)
{
    auto* pObject = static_cast<CNMFriendInfo*>(FUN_140159860(0x580, p));
    ::new (pObject) CNMFriendInfo(*reinterpret_cast<const CNMFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2bb0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1415e2bb0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMFriendInfo's copy constructor.
// @0x1415e2c00
void FUN_1415e2c00(void*, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal)
{
    auto* pObject = static_cast<CNMFriendInfo*>(FUN_140159860(0x580, p));
    ::new (pObject) CNMFriendInfo(*reinterpret_cast<const CNMFriendInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2c00@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1415e2c00

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameCode's copy constructor.
// @0x1415e2c50
void FUN_1415e2c50(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameCode(*reinterpret_cast<const CNMGameCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2c50@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2c50

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameCode's copy constructor.
// @0x1415e2ca0
void FUN_1415e2ca0(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameCode(*reinterpret_cast<const CNMGameCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2ca0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2ca0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameCode's copy constructor.
// @0x1415e2cf0
void FUN_1415e2cf0(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameCode(*reinterpret_cast<const CNMGameCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2cf0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2cf0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameInfo's copy constructor.
// @0x1415e2d40
void FUN_1415e2d40(void*, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal)
{
    auto* pObject = static_cast<CNMGameInfo*>(FUN_140159860(0x14a8, p));
    ::new (pObject) CNMGameInfo(*reinterpret_cast<const CNMGameInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2d40@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1415e2d40

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameInfo's copy constructor.
// @0x1415e2d90
void FUN_1415e2d90(void*, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal)
{
    auto* pObject = static_cast<CNMGameInfo*>(FUN_140159860(0x14a8, p));
    ::new (pObject) CNMGameInfo(*reinterpret_cast<const CNMGameInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2d90@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1415e2d90

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameInfo's copy constructor.
// @0x1415e2de0
void FUN_1415e2de0(void*, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal)
{
    auto* pObject = static_cast<CNMGameInfo*>(FUN_140159860(0x14a8, p));
    ::new (pObject) CNMGameInfo(*reinterpret_cast<const CNMGameInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2de0@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1415e2de0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameServerCode's copy constructor.
// @0x1415e2e30
void FUN_1415e2e30(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameServerCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameServerCode(*reinterpret_cast<const CNMGameServerCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2e30@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2e30

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameServerCode's copy constructor.
// @0x1415e2e80
void FUN_1415e2e80(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameServerCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameServerCode(*reinterpret_cast<const CNMGameServerCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2e80@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2e80

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGameServerCode's copy constructor.
// @0x1415e2ed0
void FUN_1415e2ed0(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    auto* pObject = static_cast<CNMGameServerCode*>(FUN_140159860(0x18, p));
    ::new (pObject) CNMGameServerCode(*reinterpret_cast<const CNMGameServerCode*>(pVal));
}
// MS2-PIN: ?FUN_1415e2ed0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2ed0

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e2f20
void FUN_1415e2f20(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2f20@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1415e2f20

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e2f70
void FUN_1415e2f70(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2f70@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1415e2f70

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e2fc0
void FUN_1415e2fc0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e2fc0@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1415e2fc0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberInfo's copy constructor.
// @0x1415e3010
void FUN_1415e3010(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberInfo*>(FUN_140159860(0xb8, p));
    ::new (pObject) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3010@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e3010

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberInfo's copy constructor.
// @0x1415e3060
void FUN_1415e3060(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberInfo*>(FUN_140159860(0xb8, p));
    ::new (pObject) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3060@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e3060

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberInfo's copy constructor.
// @0x1415e30b0
void FUN_1415e30b0(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberInfo*>(FUN_140159860(0xb8, p));
    ::new (pObject) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e30b0@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e30b0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberInfo's copy constructor.
// @0x1415e3100
void FUN_1415e3100(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberInfo*>(FUN_140159860(0xb8, p));
    ::new (pObject) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3100@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e3100

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberLevelInfo's copy constructor.
// @0x1415e3150
void FUN_1415e3150(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberLevelInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMGuildMemberLevelInfo(*reinterpret_cast<const CNMGuildMemberLevelInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3150@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e3150

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberLevelInfo's copy constructor.
// @0x1415e31a0
void FUN_1415e31a0(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberLevelInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMGuildMemberLevelInfo(*reinterpret_cast<const CNMGuildMemberLevelInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e31a0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e31a0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildMemberLevelInfo's copy constructor.
// @0x1415e31f0
void FUN_1415e31f0(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    auto* pObject = static_cast<CNMGuildMemberLevelInfo*>(FUN_140159860(0x58, p));
    ::new (pObject) CNMGuildMemberLevelInfo(*reinterpret_cast<const CNMGuildMemberLevelInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e31f0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e31f0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildOnlineInfoEx's copy constructor.
// @0x1415e3240
void FUN_1415e3240(void*, Unk_StlElem<0x68>* p, Unk_StlElem<0x68>* pVal)
{
    auto* pObject = static_cast<CNMGuildOnlineInfoEx*>(FUN_140159860(0x68, p));
    ::new (pObject) CNMGuildOnlineInfoEx(*reinterpret_cast<const CNMGuildOnlineInfoEx*>(pVal));
}
// MS2-PIN: ?FUN_1415e3240@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@1@Z 0x1415e3240

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMGuildOnlineInfoEx's copy constructor.
// @0x1415e3290
void FUN_1415e3290(void*, Unk_StlElem<0x68>* p, Unk_StlElem<0x68>* pVal)
{
    auto* pObject = static_cast<CNMGuildOnlineInfoEx*>(FUN_140159860(0x68, p));
    ::new (pObject) CNMGuildOnlineInfoEx(*reinterpret_cast<const CNMGuildOnlineInfoEx*>(pVal));
}
// MS2-PIN: ?FUN_1415e3290@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@1@Z 0x1415e3290

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo2's copy constructor.
// @0x1415e32e0
void FUN_1415e32e0(void*, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo2*>(FUN_140159860(0xae8, p));
    ::new (pObject) CNMNoteInfo2(*reinterpret_cast<const CNMNoteInfo2*>(pVal));
}
// MS2-PIN: ?FUN_1415e32e0@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x1415e32e0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo2's copy constructor.
// @0x1415e3330
void FUN_1415e3330(void*, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo2*>(FUN_140159860(0xae8, p));
    ::new (pObject) CNMNoteInfo2(*reinterpret_cast<const CNMNoteInfo2*>(pVal));
}
// MS2-PIN: ?FUN_1415e3330@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x1415e3330

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo2's copy constructor.
// @0x1415e3380
void FUN_1415e3380(void*, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo2*>(FUN_140159860(0xae8, p));
    ::new (pObject) CNMNoteInfo2(*reinterpret_cast<const CNMNoteInfo2*>(pVal));
}
// MS2-PIN: ?FUN_1415e3380@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x1415e3380

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo's copy constructor.
// @0x1415e33d0
void FUN_1415e33d0(void*, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo*>(FUN_140159860(0xec8, p));
    ::new (pObject) CNMNoteInfo(*reinterpret_cast<const CNMNoteInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e33d0@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x1415e33d0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo's copy constructor.
// @0x1415e3420
void FUN_1415e3420(void*, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo*>(FUN_140159860(0xec8, p));
    ::new (pObject) CNMNoteInfo(*reinterpret_cast<const CNMNoteInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3420@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x1415e3420

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMNoteInfo's copy constructor.
// @0x1415e3470
void FUN_1415e3470(void*, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal)
{
    auto* pObject = static_cast<CNMNoteInfo*>(FUN_140159860(0xec8, p));
    ::new (pObject) CNMNoteInfo(*reinterpret_cast<const CNMNoteInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3470@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x1415e3470

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e34c0
void FUN_1415e34c0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e34c0@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x1415e34c0

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e3510
void FUN_1415e3510(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3510@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x1415e3510

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e3560
void FUN_1415e3560(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3560@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x1415e3560

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMSessionMemberInfo's copy constructor.
// @0x1415e35b0
void FUN_1415e35b0(void*, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal)
{
    auto* pObject = static_cast<CNMSessionMemberInfo*>(FUN_140159860(0xf8, p));
    ::new (pObject) CNMSessionMemberInfo(*reinterpret_cast<const CNMSessionMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e35b0@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x1415e35b0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMSessionMemberInfo's copy constructor.
// @0x1415e3600
void FUN_1415e3600(void*, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal)
{
    auto* pObject = static_cast<CNMSessionMemberInfo*>(FUN_140159860(0xf8, p));
    ::new (pObject) CNMSessionMemberInfo(*reinterpret_cast<const CNMSessionMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3600@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x1415e3600

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMSessionMemberInfo's copy constructor.
// @0x1415e3650
void FUN_1415e3650(void*, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal)
{
    auto* pObject = static_cast<CNMSessionMemberInfo*>(FUN_140159860(0xf8, p));
    ::new (pObject) CNMSessionMemberInfo(*reinterpret_cast<const CNMSessionMemberInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3650@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x1415e3650

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMVirtualUserInfo's copy constructor.
// @0x1415e36a0
void FUN_1415e36a0(void*, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal)
{
    auto* pObject = static_cast<CNMVirtualUserInfo*>(FUN_140159860(0x490, p));
    ::new (pObject) CNMVirtualUserInfo(*reinterpret_cast<const CNMVirtualUserInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e36a0@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x1415e36a0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMVirtualUserInfo's copy constructor.
// @0x1415e36f0
void FUN_1415e36f0(void*, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal)
{
    auto* pObject = static_cast<CNMVirtualUserInfo*>(FUN_140159860(0x490, p));
    ::new (pObject) CNMVirtualUserInfo(*reinterpret_cast<const CNMVirtualUserInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e36f0@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x1415e36f0

// MS2-FUNCTIONAL: reconstructs the recovered allocator construction by invoking CNMVirtualUserInfo's copy constructor.
// @0x1415e3740
void FUN_1415e3740(void*, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal)
{
    auto* pObject = static_cast<CNMVirtualUserInfo*>(FUN_140159860(0x490, p));
    ::new (pObject) CNMVirtualUserInfo(*reinterpret_cast<const CNMVirtualUserInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3740@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x1415e3740

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e3790
void FUN_1415e3790(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3790@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e3790

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e37e0
void FUN_1415e37e0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e37e0@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e37e0

// MS2-FUNCTIONAL: reconstructs the recovered request-info allocator copy constructor.
// @0x1415e3830
void FUN_1415e3830(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    auto* pObject = static_cast<CNMSetServerInfoFunc::RequestInfo*>(FUN_140159860(0x20, p));
    ::new (pObject) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(pVal));
}
// MS2-PIN: ?FUN_1415e3830@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e3830

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e38a0
void FUN_1415e38a0(void*, Unk_StlElem<0x58>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e38a0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@@Z 0x1415e38a0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e38d0
void FUN_1415e38d0(void*, Unk_StlElem<0x30>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e38d0@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@@Z 0x1415e38d0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3900
void FUN_1415e3900(void*, Unk_StlElem<0x98>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3900@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@@Z 0x1415e3900

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3930
void FUN_1415e3930(void*, Unk_StlElem<0x220>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3930@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@@Z 0x1415e3930

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3960
void FUN_1415e3960(void*, Unk_StlElem<0x128>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3960@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@@Z 0x1415e3960

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3990
void FUN_1415e3990(void*, Unk_StlElem<0x118>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3990@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@@Z 0x1415e3990

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e39c0
void FUN_1415e39c0(void*, Unk_StlElem<0xe0>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e39c0@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@@Z 0x1415e39c0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e39f0
void FUN_1415e39f0(void*, Unk_StlElem<0x580>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e39f0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@@Z 0x1415e39f0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3a20
void FUN_1415e3a20(void*, Unk_StlElem<0x18>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3a20@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@@Z 0x1415e3a20

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3a50
void FUN_1415e3a50(void*, Unk_StlElem<0x14a8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3a50@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@@Z 0x1415e3a50

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3a80
void FUN_1415e3a80(void*, Unk_StlElem<0x18>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3a80@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@@Z 0x1415e3a80

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3ab0
void FUN_1415e3ab0(void*, Unk_StlElem<0x190>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3ab0@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@@Z 0x1415e3ab0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3ae0
void FUN_1415e3ae0(void*, Unk_StlElem<0xb8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3ae0@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@@Z 0x1415e3ae0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3b10
void FUN_1415e3b10(void*, Unk_StlElem<0x58>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3b10@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@@Z 0x1415e3b10

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3b40
void FUN_1415e3b40(void*, Unk_StlElem<0x68>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3b40@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@@Z 0x1415e3b40

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3b70
void FUN_1415e3b70(void*, Unk_StlElem<0xae8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3b70@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@@Z 0x1415e3b70

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3ba0
void FUN_1415e3ba0(void*, Unk_StlElem<0xec8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3ba0@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@@Z 0x1415e3ba0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3bd0
void FUN_1415e3bd0(void*, Unk_StlElem<0xc8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3bd0@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@@Z 0x1415e3bd0

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3c00
void FUN_1415e3c00(void*, Unk_StlElem<0xf8>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3c00@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@@Z 0x1415e3c00

// MS2-FUNCTIONAL: dispatches the recovered scalar-deleting destructor through the element vtable.
// @0x1415e3c30
void FUN_1415e3c30(void*, Unk_StlElem<0x490>* p)
{
    auto** vftable = *reinterpret_cast<void***>(p);
    using Destroy = void(__fastcall*)(void*, unsigned int);
    reinterpret_cast<Destroy>(vftable[0])(p, 0);
}
// MS2-PIN: ?FUN_1415e3c30@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@@Z 0x1415e3c30

// MS2-FUNCTIONAL: forwards the recovered allocator destroy operation to the function-object destructor.
// @0x1415e3c60
void FUN_1415e3c60(void*, Unk_StlElem<0x20>* p)
{
    FUN_1415f93d0(p, 0);
}
// MS2-PIN: ?FUN_1415e3c60@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@@Z 0x1415e3c60

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4bf0
Unk_StlElem<0x58>* FUN_1415e4bf0(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4bf0@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4bf0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c00
Unk_StlElem<0x30>* FUN_1415e4c00(Unk_StlElem<0x30>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c00@@YAPEAU?$Unk_StlElem@$0DA@@@PEAU1@@Z 0x1415e4c00

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c10
Unk_StlElem<0x98>* FUN_1415e4c10(Unk_StlElem<0x98>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c10@@YAPEAU?$Unk_StlElem@$0JI@@@PEAU1@@Z 0x1415e4c10

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c20
Unk_StlElem<0x220>* FUN_1415e4c20(Unk_StlElem<0x220>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c20@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAU1@@Z 0x1415e4c20

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c30
Unk_StlElem<0x128>* FUN_1415e4c30(Unk_StlElem<0x128>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c30@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAU1@@Z 0x1415e4c30

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c40
Unk_StlElem<0x118>* FUN_1415e4c40(Unk_StlElem<0x118>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c40@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAU1@@Z 0x1415e4c40

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c50
Unk_StlElem<0x580>* FUN_1415e4c50(Unk_StlElem<0x580>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c50@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAU1@@Z 0x1415e4c50

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c60
Unk_StlElem<0x18>* FUN_1415e4c60(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c60@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4c60

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c70
Unk_StlElem<0x14a8>* FUN_1415e4c70(Unk_StlElem<0x14a8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c70@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAU1@@Z 0x1415e4c70

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c80
Unk_StlElem<0x18>* FUN_1415e4c80(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c80@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4c80

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4c90
Unk_StlElem<0x190>* FUN_1415e4c90(Unk_StlElem<0x190>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4c90@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAU1@@Z 0x1415e4c90

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4ca0
Unk_StlElem<0xb8>* FUN_1415e4ca0(Unk_StlElem<0xb8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4ca0@@YAPEAU?$Unk_StlElem@$0LI@@@PEAU1@@Z 0x1415e4ca0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4cb0
Unk_StlElem<0x58>* FUN_1415e4cb0(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4cb0@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4cb0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4cc0
Unk_StlElem<0xae8>* FUN_1415e4cc0(Unk_StlElem<0xae8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4cc0@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAU1@@Z 0x1415e4cc0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4cd0
Unk_StlElem<0xec8>* FUN_1415e4cd0(Unk_StlElem<0xec8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4cd0@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAU1@@Z 0x1415e4cd0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4ce0
Unk_StlElem<0xc8>* FUN_1415e4ce0(Unk_StlElem<0xc8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4ce0@@YAPEAU?$Unk_StlElem@$0MI@@@PEAU1@@Z 0x1415e4ce0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4cf0
Unk_StlElem<0xf8>* FUN_1415e4cf0(Unk_StlElem<0xf8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4cf0@@YAPEAU?$Unk_StlElem@$0PI@@@PEAU1@@Z 0x1415e4cf0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d00
Unk_StlElem<0x490>* FUN_1415e4d00(Unk_StlElem<0x490>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d00@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAU1@@Z 0x1415e4d00

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d10
Unk_StlElem<0x20>* FUN_1415e4d10(Unk_StlElem<0x20>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d10@@YAPEAU?$Unk_StlElem@$0CA@@@PEAU1@@Z 0x1415e4d10

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d20
Unk_StlElem<0x10>* FUN_1415e4d20(Unk_StlElem<0x10>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d20@@YAPEAU?$Unk_StlElem@$0BA@@@PEAU1@@Z 0x1415e4d20

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d30
Unk_StlElem<0x18>* FUN_1415e4d30(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d30@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4d30

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d40
Unk_StlElem<0x58>* FUN_1415e4d40(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d40@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4d40

// MS2-FUNCTIONAL: returns the input pointer as recovered.
// @0x1415e4d50
void* FUN_1415e4d50(void* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d50@@YAPEAXPEAX@Z 0x1415e4d50

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d60
Unk_StlElem<0x98>* FUN_1415e4d60(Unk_StlElem<0x98>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d60@@YAPEAU?$Unk_StlElem@$0JI@@@PEAU1@@Z 0x1415e4d60

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d70
Unk_StlElem<0x220>* FUN_1415e4d70(Unk_StlElem<0x220>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d70@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAU1@@Z 0x1415e4d70

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d80
Unk_StlElem<0x128>* FUN_1415e4d80(Unk_StlElem<0x128>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d80@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAU1@@Z 0x1415e4d80

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4d90
Unk_StlElem<0x118>* FUN_1415e4d90(Unk_StlElem<0x118>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4d90@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAU1@@Z 0x1415e4d90

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4da0
Unk_StlElem<0xe0>* FUN_1415e4da0(Unk_StlElem<0xe0>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4da0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAU1@@Z 0x1415e4da0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4db0
Unk_StlElem<0x580>* FUN_1415e4db0(Unk_StlElem<0x580>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4db0@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAU1@@Z 0x1415e4db0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4dc0
Unk_StlElem<0x18>* FUN_1415e4dc0(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4dc0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4dc0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4dd0
Unk_StlElem<0x14a8>* FUN_1415e4dd0(Unk_StlElem<0x14a8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4dd0@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAU1@@Z 0x1415e4dd0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4de0
Unk_StlElem<0x18>* FUN_1415e4de0(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4de0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4de0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4df0
Unk_StlElem<0x190>* FUN_1415e4df0(Unk_StlElem<0x190>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4df0@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAU1@@Z 0x1415e4df0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e00
Unk_StlElem<0xb8>* FUN_1415e4e00(Unk_StlElem<0xb8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e00@@YAPEAU?$Unk_StlElem@$0LI@@@PEAU1@@Z 0x1415e4e00

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e10
Unk_StlElem<0x58>* FUN_1415e4e10(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e10@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4e10

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e20
Unk_StlElem<0x68>* FUN_1415e4e20(Unk_StlElem<0x68>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e20@@YAPEAU?$Unk_StlElem@$0GI@@@PEAU1@@Z 0x1415e4e20

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e30
Unk_StlElem<0xae8>* FUN_1415e4e30(Unk_StlElem<0xae8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e30@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAU1@@Z 0x1415e4e30

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e40
Unk_StlElem<0xec8>* FUN_1415e4e40(Unk_StlElem<0xec8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e40@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAU1@@Z 0x1415e4e40

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e50
Unk_StlElem<0xc8>* FUN_1415e4e50(Unk_StlElem<0xc8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e50@@YAPEAU?$Unk_StlElem@$0MI@@@PEAU1@@Z 0x1415e4e50

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e60
Unk_StlElem<0xf8>* FUN_1415e4e60(Unk_StlElem<0xf8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e60@@YAPEAU?$Unk_StlElem@$0PI@@@PEAU1@@Z 0x1415e4e60

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e70
Unk_StlElem<0x490>* FUN_1415e4e70(Unk_StlElem<0x490>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e70@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAU1@@Z 0x1415e4e70

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4e80
Unk_StlElem<0x20>* FUN_1415e4e80(Unk_StlElem<0x20>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4e80@@YAPEAU?$Unk_StlElem@$0CA@@@PEAU1@@Z 0x1415e4e80

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4f60
Unk_StlElem<0x58>* FUN_1415e4f60(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4f60@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4f60

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4f70
Unk_StlElem<0x30>* FUN_1415e4f70(Unk_StlElem<0x30>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4f70@@YAPEAU?$Unk_StlElem@$0DA@@@PEAU1@@Z 0x1415e4f70

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4f80
Unk_StlElem<0x98>* FUN_1415e4f80(Unk_StlElem<0x98>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4f80@@YAPEAU?$Unk_StlElem@$0JI@@@PEAU1@@Z 0x1415e4f80

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4f90
Unk_StlElem<0x220>* FUN_1415e4f90(Unk_StlElem<0x220>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4f90@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAU1@@Z 0x1415e4f90

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4fa0
Unk_StlElem<0x128>* FUN_1415e4fa0(Unk_StlElem<0x128>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4fa0@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAU1@@Z 0x1415e4fa0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4fb0
Unk_StlElem<0x118>* FUN_1415e4fb0(Unk_StlElem<0x118>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4fb0@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAU1@@Z 0x1415e4fb0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4fc0
Unk_StlElem<0xe0>* FUN_1415e4fc0(Unk_StlElem<0xe0>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4fc0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAU1@@Z 0x1415e4fc0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4fd0
Unk_StlElem<0x580>* FUN_1415e4fd0(Unk_StlElem<0x580>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4fd0@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAU1@@Z 0x1415e4fd0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4fe0
Unk_StlElem<0x18>* FUN_1415e4fe0(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4fe0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4fe0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e4ff0
Unk_StlElem<0x14a8>* FUN_1415e4ff0(Unk_StlElem<0x14a8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e4ff0@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAU1@@Z 0x1415e4ff0

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5000
Unk_StlElem<0x18>* FUN_1415e5000(Unk_StlElem<0x18>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5000@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e5000

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5010
Unk_StlElem<0x190>* FUN_1415e5010(Unk_StlElem<0x190>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5010@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAU1@@Z 0x1415e5010

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5020
Unk_StlElem<0xb8>* FUN_1415e5020(Unk_StlElem<0xb8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5020@@YAPEAU?$Unk_StlElem@$0LI@@@PEAU1@@Z 0x1415e5020

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5030
Unk_StlElem<0x58>* FUN_1415e5030(Unk_StlElem<0x58>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5030@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e5030

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5040
Unk_StlElem<0x68>* FUN_1415e5040(Unk_StlElem<0x68>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5040@@YAPEAU?$Unk_StlElem@$0GI@@@PEAU1@@Z 0x1415e5040

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5050
Unk_StlElem<0xae8>* FUN_1415e5050(Unk_StlElem<0xae8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5050@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAU1@@Z 0x1415e5050

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5060
Unk_StlElem<0xec8>* FUN_1415e5060(Unk_StlElem<0xec8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5060@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAU1@@Z 0x1415e5060

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5070
Unk_StlElem<0xc8>* FUN_1415e5070(Unk_StlElem<0xc8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5070@@YAPEAU?$Unk_StlElem@$0MI@@@PEAU1@@Z 0x1415e5070

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5080
Unk_StlElem<0xf8>* FUN_1415e5080(Unk_StlElem<0xf8>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5080@@YAPEAU?$Unk_StlElem@$0PI@@@PEAU1@@Z 0x1415e5080

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e5090
Unk_StlElem<0x490>* FUN_1415e5090(Unk_StlElem<0x490>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e5090@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAU1@@Z 0x1415e5090

// MS2-FUNCTIONAL: returns the input element pointer as recovered.
// @0x1415e50a0
Unk_StlElem<0x20>* FUN_1415e50a0(Unk_StlElem<0x20>* p)
{
    return p;
}
// MS2-PIN: ?FUN_1415e50a0@@YAPEAU?$Unk_StlElem@$0CA@@@PEAU1@@Z 0x1415e50a0

// MS2-FUNCTIONAL: initializes the recovered fixed-capacity string copy and delegates content ownership.
// @0x1415e59a0
template<> CNMStr<0x20>::CNMStr(const CNMStr<0x20>& r)
    : m_p(nullptr)
{
    FUN_1415f9a90(this, r.m_p);
}
// MS2-PIN: ??0?$CNMStr@$0CA@@@QEAA@AEBV0@@Z 0x1415e59a0

// MS2-FUNCTIONAL: initializes the recovered fixed-capacity string to its shared empty value.
// @0x1415e5a20
template<> CNMStr<0x20>::CNMStr()
    : m_p(nullptr)
{
}
// MS2-PIN: ??0?$CNMStr@$0CA@@@QEAA@XZ 0x1415e5a20

// MS2-FUNCTIONAL: initializes the recovered fixed-capacity string copy and delegates content ownership.
// @0x1415e5b80
template<> CNMStr<0x800>::CNMStr(const CNMStr<0x800>& r)
    : m_p(nullptr)
{
    FUN_1415f9b80(this, r.m_p);
}
// MS2-PIN: ??0?$CNMStr@$0IAA@@@QEAA@AEBV0@@Z 0x1415e5b80

// MS2-FUNCTIONAL: initializes the recovered fixed-capacity string to its shared empty value.
// @0x1415e5c00
template<> CNMStr<0x800>::CNMStr()
    : m_p(nullptr)
{
}
// MS2-PIN: ??0?$CNMStr@$0IAA@@@QEAA@XZ 0x1415e5c00

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4bc0
void* FUN_1415e4bc0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4bd0
void* FUN_1415e4bd0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4be0
void* FUN_1415e4be0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4e90
void* FUN_1415e4e90(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4ea0
void* FUN_1415e4ea0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4eb0
void* FUN_1415e4eb0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4ec0
void* FUN_1415e4ec0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4ed0
void* FUN_1415e4ed0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4ee0
void* FUN_1415e4ee0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4ef0
void* FUN_1415e4ef0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4f00
void* FUN_1415e4f00(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4f10
void* FUN_1415e4f10(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4f20
void* FUN_1415e4f20(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4f30
void* FUN_1415e4f30(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4f40
void* FUN_1415e4f40(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e4f50
void* FUN_1415e4f50(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5140
void* FUN_1415e5140(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5150
void* FUN_1415e5150(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5160
void* FUN_1415e5160(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5170
void* FUN_1415e5170(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5180
void* FUN_1415e5180(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5190
void* FUN_1415e5190(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e51a0
void* FUN_1415e51a0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e51b0
void* FUN_1415e51b0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e51c0
void* FUN_1415e51c0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e51d0
void* FUN_1415e51d0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e51e0
void* FUN_1415e51e0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e51f0
void* FUN_1415e51f0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5200
void* FUN_1415e5200(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5210
void* FUN_1415e5210(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5220
void* FUN_1415e5220(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5230
void* FUN_1415e5230(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5240
void* FUN_1415e5240(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5250
void* FUN_1415e5250(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5260
void* FUN_1415e5260(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5270
void* FUN_1415e5270(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5280
void* FUN_1415e5280(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5290
void* FUN_1415e5290(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e52a0
void* FUN_1415e52a0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e52b0
void* FUN_1415e52b0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e52c0
void* FUN_1415e52c0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e52d0
void* FUN_1415e52d0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e52e0
void* FUN_1415e52e0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e52f0
void* FUN_1415e52f0(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5300
void* FUN_1415e5300(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5310
void* FUN_1415e5310(void* p) { return p; }

// MS2-FUNCTIONAL: implements the recovered one-argument identity helper.
// @0x1415e5320
void* FUN_1415e5320(void* p) { return p; }

// MS2-PIN: ??$construct@PEADAEBQEAD@?$_Default_allocator_traits@V?$allocator@D@std@@@std@@SAXAEAV?$allocator@D@1@QEAPEADAEBQEAD@Z 0x1415e2390
// MS2-PIN: ??$forward@AEBQEAD@std@@YAAEBQEADAEBQEAD@Z 0x1415e4bb0
// MS2-PIN: ?FUN_1415e4bc0@@YAPEAXPEAX@Z 0x1415e4bc0
// MS2-PIN: ?FUN_1415e4bd0@@YAPEAXPEAX@Z 0x1415e4bd0
// MS2-PIN: ?FUN_1415e4be0@@YAPEAXPEAX@Z 0x1415e4be0
// MS2-PIN: ?FUN_1415e4e90@@YAPEAXPEAX@Z 0x1415e4e90
// MS2-PIN: ?FUN_1415e4ea0@@YAPEAXPEAX@Z 0x1415e4ea0
// MS2-PIN: ?FUN_1415e4eb0@@YAPEAXPEAX@Z 0x1415e4eb0
// MS2-PIN: ?FUN_1415e4ec0@@YAPEAXPEAX@Z 0x1415e4ec0
// MS2-PIN: ?FUN_1415e4ed0@@YAPEAXPEAX@Z 0x1415e4ed0
// MS2-PIN: ?FUN_1415e4ee0@@YAPEAXPEAX@Z 0x1415e4ee0
// MS2-PIN: ?FUN_1415e4ef0@@YAPEAXPEAX@Z 0x1415e4ef0
// MS2-PIN: ?FUN_1415e4f00@@YAPEAXPEAX@Z 0x1415e4f00
// MS2-PIN: ?FUN_1415e4f10@@YAPEAXPEAX@Z 0x1415e4f10
// MS2-PIN: ?FUN_1415e4f20@@YAPEAXPEAX@Z 0x1415e4f20
// MS2-PIN: ?FUN_1415e4f30@@YAPEAXPEAX@Z 0x1415e4f30
// MS2-PIN: ?FUN_1415e4f40@@YAPEAXPEAX@Z 0x1415e4f40
// MS2-PIN: ?FUN_1415e4f50@@YAPEAXPEAX@Z 0x1415e4f50
// MS2-PIN: ?FUN_1415e5140@@YAPEAXPEAX@Z 0x1415e5140
// MS2-PIN: ?FUN_1415e5150@@YAPEAXPEAX@Z 0x1415e5150
// MS2-PIN: ?FUN_1415e5160@@YAPEAXPEAX@Z 0x1415e5160
// MS2-PIN: ?FUN_1415e5170@@YAPEAXPEAX@Z 0x1415e5170
// MS2-PIN: ?FUN_1415e5180@@YAPEAXPEAX@Z 0x1415e5180
// MS2-PIN: ?FUN_1415e5190@@YAPEAXPEAX@Z 0x1415e5190
// MS2-PIN: ?FUN_1415e51a0@@YAPEAXPEAX@Z 0x1415e51a0
// MS2-PIN: ?FUN_1415e51b0@@YAPEAXPEAX@Z 0x1415e51b0
// MS2-PIN: ?FUN_1415e51c0@@YAPEAXPEAX@Z 0x1415e51c0
// MS2-PIN: ?FUN_1415e51d0@@YAPEAXPEAX@Z 0x1415e51d0
// MS2-PIN: ?FUN_1415e51e0@@YAPEAXPEAX@Z 0x1415e51e0
// MS2-PIN: ?FUN_1415e51f0@@YAPEAXPEAX@Z 0x1415e51f0
// MS2-PIN: ?FUN_1415e5200@@YAPEAXPEAX@Z 0x1415e5200
// MS2-PIN: ?FUN_1415e5210@@YAPEAXPEAX@Z 0x1415e5210
// MS2-PIN: ?FUN_1415e5220@@YAPEAXPEAX@Z 0x1415e5220
// MS2-PIN: ?FUN_1415e5230@@YAPEAXPEAX@Z 0x1415e5230
// MS2-PIN: ?FUN_1415e5240@@YAPEAXPEAX@Z 0x1415e5240
// MS2-PIN: ?FUN_1415e5250@@YAPEAXPEAX@Z 0x1415e5250
// MS2-PIN: ?FUN_1415e5260@@YAPEAXPEAX@Z 0x1415e5260
// MS2-PIN: ?FUN_1415e5270@@YAPEAXPEAX@Z 0x1415e5270
// MS2-PIN: ?FUN_1415e5280@@YAPEAXPEAX@Z 0x1415e5280
// MS2-PIN: ?FUN_1415e5290@@YAPEAXPEAX@Z 0x1415e5290
// MS2-PIN: ?FUN_1415e52a0@@YAPEAXPEAX@Z 0x1415e52a0
// MS2-PIN: ?FUN_1415e52b0@@YAPEAXPEAX@Z 0x1415e52b0
// MS2-PIN: ?FUN_1415e52c0@@YAPEAXPEAX@Z 0x1415e52c0
// MS2-PIN: ?FUN_1415e52d0@@YAPEAXPEAX@Z 0x1415e52d0
// MS2-PIN: ?FUN_1415e52e0@@YAPEAXPEAX@Z 0x1415e52e0
// MS2-PIN: ?FUN_1415e52f0@@YAPEAXPEAX@Z 0x1415e52f0
// MS2-PIN: ?FUN_1415e5300@@YAPEAXPEAX@Z 0x1415e5300
// MS2-PIN: ?FUN_1415e5310@@YAPEAXPEAX@Z 0x1415e5310
// MS2-PIN: ?FUN_1415e5320@@YAPEAXPEAX@Z 0x1415e5320
// MS2-PIN: ?FUN_1415e23e0@@YAXPEAX00@Z 0x1415e23e0
// MS2-PIN: ??$distance@PEAUNMChatSessionTarget@@@std@@YA_JPEAUNMChatSessionTarget@@0@Z 0x1415e3c80
// MS2-PIN: ??$distance@PEAUNMFriendKey@@@std@@YA_JPEAUNMFriendKey@@0@Z 0x1415e3cb0
// MS2-PIN: ??$distance@PEAVCNMCateFriendInfo@@@std@@YA_JPEAVCNMCateFriendInfo@@0@Z 0x1415e3ce0
// MS2-PIN: ??$distance@PEAVCNMChannelMemberInfo@@@std@@YA_JPEAVCNMChannelMemberInfo@@0@Z 0x1415e3d10
// MS2-PIN: ??$distance@PEAVCNMCharacter@@@std@@YA_JPEAVCNMCharacter@@0@Z 0x1415e3d40
// MS2-PIN: ??$distance@PEAVCNMChatRoomMemberInfo@@@std@@YA_JPEAVCNMChatRoomMemberInfo@@0@Z 0x1415e3d70
// MS2-PIN: ??$distance@PEAVCNMFileEvent@@@std@@YA_JPEAVCNMFileEvent@@0@Z 0x1415e3da0
// MS2-PIN: ??$distance@PEAVCNMFilePath@@@std@@YA_JPEAVCNMFilePath@@0@Z 0x1415e3dd0
// MS2-PIN: ??$distance@PEAVCNMFriendInfo@@@std@@YA_JPEAVCNMFriendInfo@@0@Z 0x1415e3e00
// MS2-PIN: ??$distance@PEAVCNMGameCode@@@std@@YA_JPEAVCNMGameCode@@0@Z 0x1415e3e30
// MS2-PIN: ??$distance@PEAVCNMGameInfo@@@std@@YA_JPEAVCNMGameInfo@@0@Z 0x1415e3e60
// MS2-PIN: ??$distance@PEAVCNMGameServerCode@@@std@@YA_JPEAVCNMGameServerCode@@0@Z 0x1415e3e90
// MS2-PIN: ??$distance@PEAVCNMGuildMemberInfo@@@std@@YA_JPEAVCNMGuildMemberInfo@@0@Z 0x1415e3ec0
// MS2-PIN: ??$distance@PEAVCNMGuildMemberLevelInfo@@@std@@YA_JPEAVCNMGuildMemberLevelInfo@@0@Z 0x1415e3ef0
// MS2-PIN: ??$distance@PEAVCNMNoteInfo2@@@std@@YA_JPEAVCNMNoteInfo2@@0@Z 0x1415e3f20
// MS2-PIN: ??$distance@PEAVCNMRejectedUser@@@std@@YA_JPEAVCNMRejectedUser@@0@Z 0x1415e3f50
// MS2-PIN: ??$distance@PEAVCNMSessionMemberInfo@@@std@@YA_JPEAVCNMSessionMemberInfo@@0@Z 0x1415e3f80
// MS2-PIN: ??$distance@PEAVCNMVirtualUserInfo@@@std@@YA_JPEAVCNMVirtualUserInfo@@0@Z 0x1415e3fb0
// MS2-PIN: ??$distance@PEBVCNMChannelMemberInfo@@@std@@YA_JPEBVCNMChannelMemberInfo@@0@Z 0x1415e3fe0
// MS2-PIN: ??$next@PEAUNMChatSessionTarget@@@std@@YAPEAUNMChatSessionTarget@@PEAU1@_J@Z 0x1415e5330
// MS2-PIN: ??$next@PEAUNMFriendKey@@@std@@YAPEAUNMFriendKey@@PEAU1@_J@Z 0x1415e5360
// MS2-PIN: ??$next@PEAVCNMCateFriendInfo@@@std@@YAPEAVCNMCateFriendInfo@@PEAV1@_J@Z 0x1415e5390
// MS2-PIN: ??$next@PEAVCNMChannelMemberInfo@@@std@@YAPEAVCNMChannelMemberInfo@@PEAV1@_J@Z 0x1415e53c0
// MS2-PIN: ??$next@PEAVCNMCharacter@@@std@@YAPEAVCNMCharacter@@PEAV1@_J@Z 0x1415e53f0
// MS2-PIN: ??$next@PEAVCNMChatRoomMemberInfo@@@std@@YAPEAVCNMChatRoomMemberInfo@@PEAV1@_J@Z 0x1415e5420
// MS2-PIN: ??$next@PEAVCNMFileEvent@@@std@@YAPEAVCNMFileEvent@@PEAV1@_J@Z 0x1415e5450
// MS2-PIN: ??$next@PEAVCNMFilePath@@@std@@YAPEAVCNMFilePath@@PEAV1@_J@Z 0x1415e5480
// MS2-PIN: ??$next@PEAVCNMFriendInfo@@@std@@YAPEAVCNMFriendInfo@@PEAV1@_J@Z 0x1415e54b0
// MS2-PIN: ??$next@PEAVCNMGameCode@@@std@@YAPEAVCNMGameCode@@PEAV1@_J@Z 0x1415e54e0
// MS2-PIN: ??$next@PEAVCNMGameInfo@@@std@@YAPEAVCNMGameInfo@@PEAV1@_J@Z 0x1415e5510
// MS2-PIN: ??$next@PEAVCNMGameServerCode@@@std@@YAPEAVCNMGameServerCode@@PEAV1@_J@Z 0x1415e5540
// MS2-PIN: ??$next@PEAVCNMGuildMemberInfo@@@std@@YAPEAVCNMGuildMemberInfo@@PEAV1@_J@Z 0x1415e5570
// MS2-PIN: ??$next@PEAVCNMGuildMemberLevelInfo@@@std@@YAPEAVCNMGuildMemberLevelInfo@@PEAV1@_J@Z 0x1415e55a0
// MS2-PIN: ??$next@PEAVCNMNoteInfo2@@@std@@YAPEAVCNMNoteInfo2@@PEAV1@_J@Z 0x1415e55d0
// MS2-PIN: ??$next@PEAVCNMRejectedUser@@@std@@YAPEAVCNMRejectedUser@@PEAV1@_J@Z 0x1415e5600
// MS2-PIN: ??$next@PEAVCNMSessionMemberInfo@@@std@@YAPEAVCNMSessionMemberInfo@@PEAV1@_J@Z 0x1415e5630
// MS2-PIN: ??$next@PEAVCNMVirtualUserInfo@@@std@@YAPEAVCNMVirtualUserInfo@@PEAV1@_J@Z 0x1415e5660
// MS2-PIN: ??$next@PEBVCNMChannelMemberInfo@@@std@@YAPEBVCNMChannelMemberInfo@@PEBV1@_J@Z 0x1415e5690
// MS2-PIN: ?FUN_1415e57f0@@YAPEAEPEAEPEBE@Z 0x1415e57f0
// MS2-PIN: ?FUN_1415e5820@@YAXPEAXPEBX@Z 0x1415e5820
// MS2-PIN: ?FUN_1415e5860@@YAPEAXPEAX@Z 0x1415e5860
// MS2-PIN: ?FUN_1415e5880@@YAPEAXPEAX@Z 0x1415e5880
// MS2-PIN: ?FUN_1415e58a0@@YAPEAXPEAXPEBQBX@Z 0x1415e58a0
// MS2-PIN: ?FUN_1415e58e0@@YAPEAXPEAXPEBX@Z 0x1415e58e0
// MS2-PIN: ?FUN_1415e5920@@YAPEAXPEAX@Z 0x1415e5920
// MS2-PIN: ?FUN_1415e5940@@YAPEAXPEAXPEBX@Z 0x1415e5940
// MS2-PIN: ?FUN_1415e5980@@YAPEAXPEAX@Z 0x1415e5980
// MS2-PIN: ?FUN_1415e5a40@@YAPEAXPEAXPEBQBX@Z 0x1415e5a40
// MS2-PIN: ?FUN_1415e5a80@@YAPEAXPEAXPEBX@Z 0x1415e5a80
// MS2-PIN: ?FUN_1415e5ac0@@YAPEAXPEAX@Z 0x1415e5ac0
// MS2-PIN: ?FUN_1415e5ae0@@YAPEAXPEAXPEBQBX@Z 0x1415e5ae0
// MS2-PIN: ?FUN_1415e5b20@@YAPEAXPEAXPEBX@Z 0x1415e5b20
// MS2-PIN: ?FUN_1415e5b60@@YAPEAXPEAX@Z 0x1415e5b60
