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

struct Unk_VDtorElem { virtual void ScalarDelete(unsigned int flags) = 0; };

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
extern bool FUN_1416020d0(void*);
extern Unk_StlElem<0x10>*& FUN_141603980(void*);
extern Unk_StlElem<0x10>* FUN_1415d6b70(void*, Unk_StlElem<0x10>*, Unk_StlElem<0x10>*);
extern void FUN_1415d5970(void*, Unk_StlElem<0x10>*);
extern bool FUN_141602120(void*);
extern Unk_StlElem<0x18>*& FUN_1416039c0(void*);
extern Unk_StlElem<0x18>* FUN_1415d6dc0(void*, Unk_StlElem<0x18>*, Unk_StlElem<0x18>*);
extern void FUN_1415d5a30(void*, Unk_StlElem<0x18>*);
extern bool FUN_14029bbc0(void*);
extern Unk_StlElem<0x20>*& FUN_14029c010(void*);
extern Unk_StlElem<0x20>* FUN_1415d7010(void*, Unk_StlElem<0x20>*, Unk_StlElem<0x20>*);
extern void FUN_1415d5af0(void*, Unk_StlElem<0x20>*);
extern bool FUN_141602170(void*);
extern Unk_StlElem<0x58>*& FUN_141603a00(void*);
extern Unk_StlElem<0x58>* FUN_1415d7260(void*, Unk_StlElem<0x58>*, Unk_StlElem<0x58>*);
extern void FUN_1415d5bb0(void*, Unk_StlElem<0x58>*);
extern bool FUN_1416021c0(void*);
extern Unk_StlElem<0x30>*& FUN_141603a40(void*);
extern Unk_StlElem<0x30>* FUN_1415d74b0(void*, Unk_StlElem<0x30>*, Unk_StlElem<0x30>*);
extern void FUN_1415d5c70(void*, Unk_StlElem<0x30>*);
extern bool FUN_141602210(void*);
extern Unk_StlElem<0x98>*& FUN_141603a80(void*);
extern Unk_StlElem<0x98>* FUN_1415d7700(void*, Unk_StlElem<0x98>*, Unk_StlElem<0x98>*);
extern void FUN_1415d5d30(void*, Unk_StlElem<0x98>*);
extern bool FUN_141602260(void*);
extern Unk_StlElem<0x220>*& FUN_141603ac0(void*);
extern Unk_StlElem<0x220>* FUN_1415d7970(void*, Unk_StlElem<0x220>*, Unk_StlElem<0x220>*);
extern void FUN_1415d5df0(void*, Unk_StlElem<0x220>*);
extern bool FUN_1416022b0(void*);
extern Unk_StlElem<0x128>*& FUN_141603b00(void*);
extern Unk_StlElem<0x128>* FUN_1415d7be0(void*, Unk_StlElem<0x128>*, Unk_StlElem<0x128>*);
extern void FUN_1415d5eb0(void*, Unk_StlElem<0x128>*);
extern bool FUN_141602300(void*);
extern Unk_StlElem<0x118>*& FUN_141603b40(void*);
extern Unk_StlElem<0x118>* FUN_1415d7e50(void*, Unk_StlElem<0x118>*, Unk_StlElem<0x118>*);
extern void FUN_1415d5f70(void*, Unk_StlElem<0x118>*);
extern bool FUN_141602350(void*);
extern Unk_StlElem<0xe0>*& FUN_141603b80(void*);
extern Unk_StlElem<0xe0>* FUN_1415d80c0(void*, Unk_StlElem<0xe0>*, Unk_StlElem<0xe0>*);
extern void FUN_1415d6030(void*, Unk_StlElem<0xe0>*);
extern bool FUN_1416023a0(void*);
extern Unk_StlElem<0x580>*& FUN_141603bc0(void*);
extern Unk_StlElem<0x580>* FUN_1415d8330(void*, Unk_StlElem<0x580>*, Unk_StlElem<0x580>*);
extern void FUN_1415d60f0(void*, Unk_StlElem<0x580>*);
extern bool FUN_1416023f0(void*);
extern Unk_StlElem<0x18>*& FUN_141603c00(void*);
extern Unk_StlElem<0x18>* FUN_1415d85a0(void*, Unk_StlElem<0x18>*, Unk_StlElem<0x18>*);
extern void FUN_1415d61b0(void*, Unk_StlElem<0x18>*);
extern bool FUN_141602440(void*);
extern Unk_StlElem<0x14a8>*& FUN_141603c40(void*);
extern Unk_StlElem<0x14a8>* FUN_1415d87f0(void*, Unk_StlElem<0x14a8>*, Unk_StlElem<0x14a8>*);
extern void FUN_1415d6270(void*, Unk_StlElem<0x14a8>*);
extern bool FUN_141602490(void*);
extern Unk_StlElem<0x18>*& FUN_141603c80(void*);
extern Unk_StlElem<0x18>* FUN_1415d8a60(void*, Unk_StlElem<0x18>*, Unk_StlElem<0x18>*);
extern void FUN_1415d6330(void*, Unk_StlElem<0x18>*);
extern bool FUN_1416024e0(void*);
extern Unk_StlElem<0x190>*& FUN_141603cc0(void*);
extern Unk_StlElem<0x190>* FUN_1415d8cb0(void*, Unk_StlElem<0x190>*, Unk_StlElem<0x190>*);
extern void FUN_1415d63f0(void*, Unk_StlElem<0x190>*);
extern bool FUN_141602530(void*);
extern Unk_StlElem<0xb8>*& FUN_141603d00(void*);
extern Unk_StlElem<0xb8>* FUN_1415d8f20(void*, Unk_StlElem<0xb8>*, Unk_StlElem<0xb8>*);
extern void FUN_1415d64b0(void*, Unk_StlElem<0xb8>*);
extern bool FUN_141602580(void*);
extern Unk_StlElem<0x58>*& FUN_141603d40(void*);
extern Unk_StlElem<0x58>* FUN_1415d9190(void*, Unk_StlElem<0x58>*, Unk_StlElem<0x58>*);
extern void FUN_1415d6570(void*, Unk_StlElem<0x58>*);
extern bool FUN_1416025d0(void*);
extern Unk_StlElem<0x68>*& FUN_141603d80(void*);
extern Unk_StlElem<0x68>* FUN_1415d93e0(void*, Unk_StlElem<0x68>*, Unk_StlElem<0x68>*);
extern void FUN_1415d6630(void*, Unk_StlElem<0x68>*);
extern bool FUN_141602620(void*);
extern Unk_StlElem<0xae8>*& FUN_141603dc0(void*);
extern Unk_StlElem<0xae8>* FUN_1415d9630(void*, Unk_StlElem<0xae8>*, Unk_StlElem<0xae8>*);
extern void FUN_1415d66f0(void*, Unk_StlElem<0xae8>*);
extern bool FUN_141602670(void*);
extern Unk_StlElem<0xec8>*& FUN_141603e00(void*);
extern Unk_StlElem<0xec8>* FUN_1415d98a0(void*, Unk_StlElem<0xec8>*, Unk_StlElem<0xec8>*);
extern void FUN_1415d67b0(void*, Unk_StlElem<0xec8>*);
extern bool FUN_1416026c0(void*);
extern Unk_StlElem<0xc8>*& FUN_141603e40(void*);
extern Unk_StlElem<0xc8>* FUN_1415d9b10(void*, Unk_StlElem<0xc8>*, Unk_StlElem<0xc8>*);
extern void FUN_1415d6870(void*, Unk_StlElem<0xc8>*);
extern bool FUN_141602710(void*);
extern Unk_StlElem<0xf8>*& FUN_141603e80(void*);
extern Unk_StlElem<0xf8>* FUN_1415d9d80(void*, Unk_StlElem<0xf8>*, Unk_StlElem<0xf8>*);
extern void FUN_1415d6930(void*, Unk_StlElem<0xf8>*);
extern bool FUN_141602760(void*);
extern Unk_StlElem<0x490>*& FUN_141603ec0(void*);
extern Unk_StlElem<0x490>* FUN_1415d9ff0(void*, Unk_StlElem<0x490>*, Unk_StlElem<0x490>*);
extern void FUN_1415d69f0(void*, Unk_StlElem<0x490>*);
extern bool FUN_1416027b0(void*);
extern Unk_StlElem<0x20>*& FUN_141603f00(void*);
extern Unk_StlElem<0x20>* FUN_1415da260(void*, Unk_StlElem<0x20>*, Unk_StlElem<0x20>*);
extern void FUN_1415d6ab0(void*, Unk_StlElem<0x20>*);
extern Unk_StlElem<0x20>* FUN_1403a4b80(Unk_StlElem<0x20>*);

extern char DAT_143ae2848;  // CNMStr<0x20>
extern char DAT_143ae2849;  // CNMStr<0x800>
extern char DAT_143ae28e8;  // CNMStr<0x400>
extern char DAT_143ae28e9;  // CNMStr<0x40>
extern char DAT_143ae28ea;  // CNMStr<0x1000>
extern char DAT_143ae28eb;  // CNMStr<0x100>
extern char DAT_143ae28ec;  // CNMStr<9>
extern char DAT_143ae28ed;  // CNMStr<0x15e>
extern void FUN_1415f99a0(void** slot, const char* value);
extern void FUN_1415f99f0(void** slot, const char* value);
extern void FUN_1415f9a40(void** slot, const char* value);
extern void FUN_1415f9ae0(void** slot, const char* value);
extern void FUN_1415f9b30(void** slot, const char* value);

class CNMCOClientObject;
template <class T>
class CNMSingleton
{
public:
    CNMSingleton();
    virtual ~CNMSingleton();
};

// @0x1415e57b0
template <>
CNMSingleton<CNMCOClientObject>::CNMSingleton() { }

// @0x1415e57d0
template <>
CNMSingleton<CNMManager>::CNMSingleton() { }

// MS2-FUNCTIONAL: stores the per-capacity empty sentinel and delegates the copy to the CNMStr set helper.
// @0x1415e5820
void FUN_1415e5820(void* p, const void* value)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28ec;
    FUN_1415f99a0(reinterpret_cast<void**>(p), static_cast<const char*>(value));
}

// @0x1415e5860
void* FUN_1415e5860(void* p)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28ec;
    return p;
}

// @0x1415e5880
void* FUN_1415e5880(void* p)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28eb;
    return p;
}

// @0x1415e58a0
void* FUN_1415e58a0(void* p, const void* const* value)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28ea;
    FUN_1415f99f0(reinterpret_cast<void**>(p), static_cast<const char*>(*value));
    return p;
}

// @0x1415e58e0
void* FUN_1415e58e0(void* p, const void* value)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28ea;
    FUN_1415f99f0(reinterpret_cast<void**>(p), static_cast<const char*>(value));
    return p;
}

// @0x1415e5920
void* FUN_1415e5920(void* p)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28ea;
    return p;
}

// @0x1415e5940
void* FUN_1415e5940(void* p, const void* value)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28ed;
    FUN_1415f9a40(reinterpret_cast<void**>(p), static_cast<const char*>(value));
    return p;
}

// @0x1415e5980
void* FUN_1415e5980(void* p)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28ed;
    return p;
}

// @0x1415e5a40
void* FUN_1415e5a40(void* p, const void* const* value)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28e9;
    FUN_1415f9ae0(reinterpret_cast<void**>(p), static_cast<const char*>(*value));
    return p;
}

// @0x1415e5a80
void* FUN_1415e5a80(void* p, const void* value)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28e9;
    FUN_1415f9ae0(reinterpret_cast<void**>(p), static_cast<const char*>(value));
    return p;
}

// @0x1415e5ac0
void* FUN_1415e5ac0(void* p)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28e9;
    return p;
}

// @0x1415e5ae0
void* FUN_1415e5ae0(void* p, const void* const* value)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28e8;
    FUN_1415f9b30(reinterpret_cast<void**>(p), static_cast<const char*>(*value));
    return p;
}

// @0x1415e5b20
void* FUN_1415e5b20(void* p, const void* value)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28e8;
    FUN_1415f9b30(reinterpret_cast<void**>(p), static_cast<const char*>(value));
    return p;
}

// @0x1415e5b60
void* FUN_1415e5b60(void* p)
{
    *reinterpret_cast<char**>(p) = &DAT_143ae28e8;
    return p;
}

// @0x1415e57f0
unsigned char* FUN_1415e57f0(unsigned char* dst, const unsigned char* src)
{
    std::memcpy(dst, src, 0x0c);
    return dst;
}

// @0x1415e5330
extern void FUN_1415e18e0(void*, ptrdiff_t);
void* FUN_1415e5330(void* p, ptrdiff_t n)
{
    FUN_1415e18e0(&p, n);
    return p;
}

// @0x1415e5360
extern void FUN_1415e1910(void*, ptrdiff_t);
void* FUN_1415e5360(void* p, ptrdiff_t n)
{
    FUN_1415e1910(&p, n);
    return p;
}

// @0x1415e5390
extern void FUN_1415e1940(void*, ptrdiff_t);
void* FUN_1415e5390(void* p, ptrdiff_t n)
{
    FUN_1415e1940(&p, n);
    return p;
}

// @0x1415e53c0
extern void FUN_1415e1970(void*, ptrdiff_t);
void* FUN_1415e53c0(void* p, ptrdiff_t n)
{
    FUN_1415e1970(&p, n);
    return p;
}

// @0x1415e53f0
extern void FUN_1415e19a0(void*, ptrdiff_t);
void* FUN_1415e53f0(void* p, ptrdiff_t n)
{
    FUN_1415e19a0(&p, n);
    return p;
}

// @0x1415e5420
extern void FUN_1415e19d0(void*, ptrdiff_t);
void* FUN_1415e5420(void* p, ptrdiff_t n)
{
    FUN_1415e19d0(&p, n);
    return p;
}

// @0x1415e5450
extern void FUN_1415e1a00(void*, ptrdiff_t);
void* FUN_1415e5450(void* p, ptrdiff_t n)
{
    FUN_1415e1a00(&p, n);
    return p;
}

// @0x1415e5480
extern void FUN_1415e1a30(void*, ptrdiff_t);
void* FUN_1415e5480(void* p, ptrdiff_t n)
{
    FUN_1415e1a30(&p, n);
    return p;
}

// @0x1415e54b0
extern void FUN_1415e1a60(void*, ptrdiff_t);
void* FUN_1415e54b0(void* p, ptrdiff_t n)
{
    FUN_1415e1a60(&p, n);
    return p;
}

// @0x1415e54e0
extern void FUN_1415e1a90(void*, ptrdiff_t);
void* FUN_1415e54e0(void* p, ptrdiff_t n)
{
    FUN_1415e1a90(&p, n);
    return p;
}

// @0x1415e5510
extern void FUN_1415e1ac0(void*, ptrdiff_t);
void* FUN_1415e5510(void* p, ptrdiff_t n)
{
    FUN_1415e1ac0(&p, n);
    return p;
}

// @0x1415e5540
extern void FUN_1415e1af0(void*, ptrdiff_t);
void* FUN_1415e5540(void* p, ptrdiff_t n)
{
    FUN_1415e1af0(&p, n);
    return p;
}

// @0x1415e5570
extern void FUN_1415e1b20(void*, ptrdiff_t);
void* FUN_1415e5570(void* p, ptrdiff_t n)
{
    FUN_1415e1b20(&p, n);
    return p;
}

// @0x1415e55a0
extern void FUN_1415e1b50(void*, ptrdiff_t);
void* FUN_1415e55a0(void* p, ptrdiff_t n)
{
    FUN_1415e1b50(&p, n);
    return p;
}

// @0x1415e55d0
extern void FUN_1415e1b80(void*, ptrdiff_t);
void* FUN_1415e55d0(void* p, ptrdiff_t n)
{
    FUN_1415e1b80(&p, n);
    return p;
}

// @0x1415e5600
extern void FUN_1415e1bb0(void*, ptrdiff_t);
void* FUN_1415e5600(void* p, ptrdiff_t n)
{
    FUN_1415e1bb0(&p, n);
    return p;
}

// @0x1415e5630
extern void FUN_1415e1be0(void*, ptrdiff_t);
void* FUN_1415e5630(void* p, ptrdiff_t n)
{
    FUN_1415e1be0(&p, n);
    return p;
}

// @0x1415e5660
extern void FUN_1415e1c10(void*, ptrdiff_t);
void* FUN_1415e5660(void* p, ptrdiff_t n)
{
    FUN_1415e1c10(&p, n);
    return p;
}

// @0x1415e5690
extern void FUN_1415e1c40(void*, ptrdiff_t);
void* FUN_1415e5690(void* p, ptrdiff_t n)
{
    FUN_1415e1c40(&p, n);
    return p;
}

// @0x1415e3c80
ptrdiff_t FUN_1415e3c80(void* first, void* last)
{
    return FUN_1415d44c0(static_cast<Unk_StlElem<0x10>*>(first), static_cast<Unk_StlElem<0x10>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3cb0
ptrdiff_t FUN_1415e3cb0(void* first, void* last)
{
    return FUN_1415d44f0(static_cast<Unk_StlElem<0x18>*>(first), static_cast<Unk_StlElem<0x18>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3ce0
ptrdiff_t FUN_1415e3ce0(void* first, void* last)
{
    return FUN_1415d4520(static_cast<Unk_StlElem<0x58>*>(first), static_cast<Unk_StlElem<0x58>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3d10
ptrdiff_t FUN_1415e3d10(void* first, void* last)
{
    return FUN_1415d4550(static_cast<Unk_StlElem<0x30>*>(first), static_cast<Unk_StlElem<0x30>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3d40
ptrdiff_t FUN_1415e3d40(void* first, void* last)
{
    return FUN_1415d4580(static_cast<Unk_StlElem<0x98>*>(first), static_cast<Unk_StlElem<0x98>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3d70
ptrdiff_t FUN_1415e3d70(void* first, void* last)
{
    return FUN_1415d45b0(static_cast<Unk_StlElem<0x220>*>(first), static_cast<Unk_StlElem<0x220>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3da0
ptrdiff_t FUN_1415e3da0(void* first, void* last)
{
    return FUN_1415d45e0(static_cast<Unk_StlElem<0x128>*>(first), static_cast<Unk_StlElem<0x128>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3dd0
ptrdiff_t FUN_1415e3dd0(void* first, void* last)
{
    return FUN_1415d4610(static_cast<Unk_StlElem<0x118>*>(first), static_cast<Unk_StlElem<0x118>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3e00
ptrdiff_t FUN_1415e3e00(void* first, void* last)
{
    return FUN_1415d4640(static_cast<Unk_StlElem<0x580>*>(first), static_cast<Unk_StlElem<0x580>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3e30
ptrdiff_t FUN_1415e3e30(void* first, void* last)
{
    return FUN_1415d4670(static_cast<Unk_StlElem<0x18>*>(first), static_cast<Unk_StlElem<0x18>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3e60
ptrdiff_t FUN_1415e3e60(void* first, void* last)
{
    return FUN_1415d46a0(static_cast<Unk_StlElem<0x14a8>*>(first), static_cast<Unk_StlElem<0x14a8>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3e90
ptrdiff_t FUN_1415e3e90(void* first, void* last)
{
    return FUN_1415d46d0(static_cast<Unk_StlElem<0x18>*>(first), static_cast<Unk_StlElem<0x18>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3ec0
ptrdiff_t FUN_1415e3ec0(void* first, void* last)
{
    return FUN_1415d4700(static_cast<Unk_StlElem<0xb8>*>(first), static_cast<Unk_StlElem<0xb8>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3ef0
ptrdiff_t FUN_1415e3ef0(void* first, void* last)
{
    return FUN_1415d4730(static_cast<Unk_StlElem<0x58>*>(first), static_cast<Unk_StlElem<0x58>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3f20
ptrdiff_t FUN_1415e3f20(void* first, void* last)
{
    return FUN_1415d4760(static_cast<Unk_StlElem<0xae8>*>(first), static_cast<Unk_StlElem<0xae8>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3f50
ptrdiff_t FUN_1415e3f50(void* first, void* last)
{
    return FUN_1415d4790(static_cast<Unk_StlElem<0xc8>*>(first), static_cast<Unk_StlElem<0xc8>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3f80
ptrdiff_t FUN_1415e3f80(void* first, void* last)
{
    return FUN_1415d47c0(static_cast<Unk_StlElem<0xf8>*>(first), static_cast<Unk_StlElem<0xf8>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3fb0
ptrdiff_t FUN_1415e3fb0(void* first, void* last)
{
    return FUN_1415d47f0(static_cast<Unk_StlElem<0x490>*>(first), static_cast<Unk_StlElem<0x490>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e3fe0
ptrdiff_t FUN_1415e3fe0(void* first, void* last)
{
    return FUN_1415d4820(static_cast<Unk_StlElem<0x30>*>(first), static_cast<Unk_StlElem<0x30>*>(last), std::random_access_iterator_tag{});
}

// @0x1415e23e0
void FUN_1415e23e0(void*, void* p, void* pVal)
{
    void* pObject = FUN_140159860(0x10, p);
    FUN_1415ce470(pObject, FUN_1415e4ea0(pVal));
}

// @0x1415e2430
extern void* FUN_1415e4d20(void* p);
void FUN_1415e2430(void*, Unk_StlElem<0x10>* p, Unk_StlElem<0x10>* pVal)
{
    ::new (static_cast<void*>(p)) Unk_StlElem<0x10>(*reinterpret_cast<const Unk_StlElem<0x10>*>(FUN_1415e4d20(pVal)));
}

// @0x1415e2480
extern void* FUN_1415e4d30(void* p);
void FUN_1415e2480(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    ::new (static_cast<void*>(p)) Unk_StlElem<0x18>(*reinterpret_cast<const Unk_StlElem<0x18>*>(FUN_1415e4d30(pVal)));
}

// @0x1415e24d0
void FUN_1415e24d0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    ::new (static_cast<void*>(p)) std::string(*reinterpret_cast<const std::string*>(FUN_1403a4b80(pVal)));
}

// @0x1415e2520
extern void* FUN_1415e4bf0(void* p);
void FUN_1415e2520(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    ::new (static_cast<void*>(p)) CNMCateFriendInfo(*reinterpret_cast<const CNMCateFriendInfo*>(FUN_1415e4bf0(pVal)));
}

// @0x1415e2570
extern void* FUN_1415e4d40(void* p);
void FUN_1415e2570(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    ::new (static_cast<void*>(p)) CNMCateFriendInfo(*reinterpret_cast<const CNMCateFriendInfo*>(FUN_1415e4d40(pVal)));
}

// @0x1415e25c0
extern void* FUN_1415e4f60(void* p);
extern void FUN_1415e89f0(void* self, void* other);
void FUN_1415e25c0(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    void* pObject = FUN_140159860(0x58, p);
    FUN_1415e89f0(pObject, FUN_1415e4f60(pVal));
}

// @0x1415e2610
extern void* FUN_1415e4c00(void* p);
void FUN_1415e2610(void*, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal)
{
    ::new (static_cast<void*>(p)) CNMChannelMemberInfo(*reinterpret_cast<const CNMChannelMemberInfo*>(FUN_1415e4c00(pVal)));
}

// @0x1415e2660
extern void* FUN_1415e4d50(void* p);
void FUN_1415e2660(void*, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal)
{
    ::new (static_cast<void*>(p)) CNMChannelMemberInfo(*reinterpret_cast<const CNMChannelMemberInfo*>(FUN_1415e4d50(pVal)));
}

// @0x1415e26b0
extern void* FUN_1415e4f70(void* p);
void FUN_1415e26b0(void*, Unk_StlElem<0x30>* p, Unk_StlElem<0x30>* pVal)
{
    ::new (static_cast<void*>(p)) CNMChannelMemberInfo(*reinterpret_cast<const CNMChannelMemberInfo*>(FUN_1415e4f70(pVal)));
}

// @0x1415e2700
extern void* FUN_1415e4c10(void* p);
void FUN_1415e2700(void*, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal)
{
    ::new (static_cast<void*>(p)) CNMCharacter(*reinterpret_cast<const CNMCharacter*>(FUN_1415e4c10(pVal)));
}

// @0x1415e2750
extern void* FUN_1415e4d60(void* p);
void FUN_1415e2750(void*, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal)
{
    ::new (static_cast<void*>(p)) CNMCharacter(*reinterpret_cast<const CNMCharacter*>(FUN_1415e4d60(pVal)));
}

// @0x1415e27a0
extern void* FUN_1415e4f80(void* p);
void FUN_1415e27a0(void*, Unk_StlElem<0x98>* p, Unk_StlElem<0x98>* pVal)
{
    ::new (static_cast<void*>(p)) CNMCharacter(*reinterpret_cast<const CNMCharacter*>(FUN_1415e4f80(pVal)));
}

// @0x1415e27f0
extern void* FUN_1415e4c20(void* p);
void FUN_1415e27f0(void*, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal)
{
    ::new (static_cast<void*>(p)) CNMChatRoomMemberInfo(*reinterpret_cast<const CNMChatRoomMemberInfo*>(FUN_1415e4c20(pVal)));
}

// @0x1415e2840
extern void* FUN_1415e4d70(void* p);
void FUN_1415e2840(void*, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal)
{
    ::new (static_cast<void*>(p)) CNMChatRoomMemberInfo(*reinterpret_cast<const CNMChatRoomMemberInfo*>(FUN_1415e4d70(pVal)));
}

// @0x1415e2890
extern void* FUN_1415e4f90(void* p);
void FUN_1415e2890(void*, Unk_StlElem<0x220>* p, Unk_StlElem<0x220>* pVal)
{
    ::new (static_cast<void*>(p)) CNMChatRoomMemberInfo(*reinterpret_cast<const CNMChatRoomMemberInfo*>(FUN_1415e4f90(pVal)));
}

// @0x1415e28e0
extern void* FUN_1415e4c30(void* p);
void FUN_1415e28e0(void*, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFileEvent(*reinterpret_cast<const CNMFileEvent*>(FUN_1415e4c30(pVal)));
}

// @0x1415e2930
extern void* FUN_1415e4d80(void* p);
void FUN_1415e2930(void*, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFileEvent(*reinterpret_cast<const CNMFileEvent*>(FUN_1415e4d80(pVal)));
}

// @0x1415e2980
extern void* FUN_1415e4fa0(void* p);
void FUN_1415e2980(void*, Unk_StlElem<0x128>* p, Unk_StlElem<0x128>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFileEvent(*reinterpret_cast<const CNMFileEvent*>(FUN_1415e4fa0(pVal)));
}

// @0x1415e29d0
extern void* FUN_1415e4c40(void* p);
void FUN_1415e29d0(void*, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFilePath(*reinterpret_cast<const CNMFilePath*>(FUN_1415e4c40(pVal)));
}

// @0x1415e2a20
extern void* FUN_1415e4d90(void* p);
void FUN_1415e2a20(void*, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFilePath(*reinterpret_cast<const CNMFilePath*>(FUN_1415e4d90(pVal)));
}

// @0x1415e2a70
extern void* FUN_1415e4fb0(void* p);
void FUN_1415e2a70(void*, Unk_StlElem<0x118>* p, Unk_StlElem<0x118>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFilePath(*reinterpret_cast<const CNMFilePath*>(FUN_1415e4fb0(pVal)));
}

// @0x1415e2ac0
extern void* FUN_1415e4da0(void* p);
void FUN_1415e2ac0(void*, Unk_StlElem<0xe0>* p, Unk_StlElem<0xe0>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFindUserInfo(*reinterpret_cast<const CNMFindUserInfo*>(FUN_1415e4da0(pVal)));
}

// @0x1415e2b10
extern void* FUN_1415e4fc0(void* p);
void FUN_1415e2b10(void*, Unk_StlElem<0xe0>* p, Unk_StlElem<0xe0>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFindUserInfo(*reinterpret_cast<const CNMFindUserInfo*>(FUN_1415e4fc0(pVal)));
}

// @0x1415e2b60
extern void* FUN_1415e4c50(void* p);
void FUN_1415e2b60(void*, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFriendInfo(*reinterpret_cast<const CNMFriendInfo*>(FUN_1415e4c50(pVal)));
}

// @0x1415e2bb0
extern void* FUN_1415e4db0(void* p);
void FUN_1415e2bb0(void*, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFriendInfo(*reinterpret_cast<const CNMFriendInfo*>(FUN_1415e4db0(pVal)));
}

// @0x1415e2c00
extern void* FUN_1415e4fd0(void* p);
void FUN_1415e2c00(void*, Unk_StlElem<0x580>* p, Unk_StlElem<0x580>* pVal)
{
    ::new (static_cast<void*>(p)) CNMFriendInfo(*reinterpret_cast<const CNMFriendInfo*>(FUN_1415e4fd0(pVal)));
}

// @0x1415e2c50
extern void* FUN_1415e4c60(void* p);
void FUN_1415e2c50(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGameCode(*reinterpret_cast<const CNMGameCode*>(FUN_1415e4c60(pVal)));
}

// @0x1415e2ca0
extern void* FUN_1415e4dc0(void* p);
void FUN_1415e2ca0(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGameCode(*reinterpret_cast<const CNMGameCode*>(FUN_1415e4dc0(pVal)));
}

// @0x1415e2cf0
extern void* FUN_1415e4fe0(void* p);
void FUN_1415e2cf0(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGameCode(*reinterpret_cast<const CNMGameCode*>(FUN_1415e4fe0(pVal)));
}

// @0x1415e2d40
extern void* FUN_1415e4c70(void* p);
void FUN_1415e2d40(void*, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGameInfo(*reinterpret_cast<const CNMGameInfo*>(FUN_1415e4c70(pVal)));
}

// @0x1415e2d90
extern void* FUN_1415e4dd0(void* p);
void FUN_1415e2d90(void*, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGameInfo(*reinterpret_cast<const CNMGameInfo*>(FUN_1415e4dd0(pVal)));
}

// @0x1415e2de0
extern void* FUN_1415e4ff0(void* p);
void FUN_1415e2de0(void*, Unk_StlElem<0x14a8>* p, Unk_StlElem<0x14a8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGameInfo(*reinterpret_cast<const CNMGameInfo*>(FUN_1415e4ff0(pVal)));
}

// @0x1415e2e30
extern void* FUN_1415e4c80(void* p);
void FUN_1415e2e30(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGameServerCode(*reinterpret_cast<const CNMGameServerCode*>(FUN_1415e4c80(pVal)));
}

// @0x1415e2e80
extern void* FUN_1415e4de0(void* p);
void FUN_1415e2e80(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGameServerCode(*reinterpret_cast<const CNMGameServerCode*>(FUN_1415e4de0(pVal)));
}

// @0x1415e2ed0
extern void* FUN_1415e5000(void* p);
void FUN_1415e2ed0(void*, Unk_StlElem<0x18>* p, Unk_StlElem<0x18>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGameServerCode(*reinterpret_cast<const CNMGameServerCode*>(FUN_1415e5000(pVal)));
}

// @0x1415e2f20
extern void* FUN_1415e4c90(void* p);
extern void FUN_1415e9e20(void* self, void* other);
void FUN_1415e2f20(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    void* pObject = FUN_140159860(0x190, p);
    FUN_1415e9e20(pObject, FUN_1415e4c90(pVal));
}

// @0x1415e2f70
extern void* FUN_1415e4df0(void* p);
void FUN_1415e2f70(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    void* pObject = FUN_140159860(0x190, p);
    FUN_1415e9e20(pObject, FUN_1415e4df0(pVal));
}

// @0x1415e2fc0
extern void* FUN_1415e5010(void* p);
extern void FUN_1415e9d20(void* self, void* other);
void FUN_1415e2fc0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    void* pObject = FUN_140159860(0x190, p);
    FUN_1415e9d20(pObject, FUN_1415e5010(pVal));
}

// @0x1415e3010
extern void* FUN_1415e4ca0(void* p);
void FUN_1415e3010(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(FUN_1415e4ca0(pVal)));
}

// @0x1415e3060
extern void* FUN_1415e4e00(void* p);
void FUN_1415e3060(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(FUN_1415e4e00(pVal)));
}

// @0x1415e30b0
extern void FUN_141574aa0(void* self, void* other);
void FUN_1415e30b0(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    void* pObject = FUN_140159860(0xb8, p);
    FUN_141574aa0(pObject, FUN_1415e4d50(pVal));
}

// @0x1415e3100
extern void* FUN_1415e5020(void* p);
void FUN_1415e3100(void*, Unk_StlElem<0xb8>* p, Unk_StlElem<0xb8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGuildMemberInfo(*reinterpret_cast<const CNMGuildMemberInfo*>(FUN_1415e5020(pVal)));
}

// @0x1415e3150
extern void* FUN_1415e4cb0(void* p);
void FUN_1415e3150(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGuildMemberLevelInfo(*reinterpret_cast<const CNMGuildMemberLevelInfo*>(FUN_1415e4cb0(pVal)));
}

// @0x1415e31a0
extern void* FUN_1415e4e10(void* p);
void FUN_1415e31a0(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGuildMemberLevelInfo(*reinterpret_cast<const CNMGuildMemberLevelInfo*>(FUN_1415e4e10(pVal)));
}

// @0x1415e31f0
extern void* FUN_1415e5030(void* p);
void FUN_1415e31f0(void*, Unk_StlElem<0x58>* p, Unk_StlElem<0x58>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGuildMemberLevelInfo(*reinterpret_cast<const CNMGuildMemberLevelInfo*>(FUN_1415e5030(pVal)));
}

// @0x1415e3240
extern void* FUN_1415e4e20(void* p);
void FUN_1415e3240(void*, Unk_StlElem<0x68>* p, Unk_StlElem<0x68>* pVal)
{
    ::new (static_cast<void*>(p)) CNMGuildOnlineInfoEx(*reinterpret_cast<const CNMGuildOnlineInfoEx*>(FUN_1415e4e20(pVal)));
}

// @0x1415e3290
extern void* FUN_1415e5040(void* p);
extern void FUN_1415ea260(void* self, void* other);
void FUN_1415e3290(void*, Unk_StlElem<0x68>* p, Unk_StlElem<0x68>* pVal)
{
    void* pObject = FUN_140159860(0x68, p);
    FUN_1415ea260(pObject, FUN_1415e5040(pVal));
}

// @0x1415e32e0
extern void* FUN_1415e4cc0(void* p);
void FUN_1415e32e0(void*, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMNoteInfo2(*reinterpret_cast<const CNMNoteInfo2*>(FUN_1415e4cc0(pVal)));
}

// @0x1415e3330
extern void* FUN_1415e4e30(void* p);
void FUN_1415e3330(void*, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMNoteInfo2(*reinterpret_cast<const CNMNoteInfo2*>(FUN_1415e4e30(pVal)));
}

// @0x1415e3380
extern void* FUN_1415e5050(void* p);
extern void FUN_1415ea400(void* self, void* other);
void FUN_1415e3380(void*, Unk_StlElem<0xae8>* p, Unk_StlElem<0xae8>* pVal)
{
    void* pObject = FUN_140159860(0xae8, p);
    FUN_1415ea400(pObject, FUN_1415e5050(pVal));
}

// @0x1415e33d0
extern void* FUN_1415e4cd0(void* p);
void FUN_1415e33d0(void*, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMNoteInfo(*reinterpret_cast<const CNMNoteInfo*>(FUN_1415e4cd0(pVal)));
}

// @0x1415e3420
extern void* FUN_1415e4e40(void* p);
void FUN_1415e3420(void*, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMNoteInfo(*reinterpret_cast<const CNMNoteInfo*>(FUN_1415e4e40(pVal)));
}

// @0x1415e3470
extern void* FUN_1415e5060(void* p);
void FUN_1415e3470(void*, Unk_StlElem<0xec8>* p, Unk_StlElem<0xec8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMNoteInfo(*reinterpret_cast<const CNMNoteInfo*>(FUN_1415e5060(pVal)));
}

// @0x1415e34c0
extern void* FUN_1415e4ce0(void* p);
extern void FUN_1415eaf30(void* self, void* other);
void FUN_1415e34c0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    void* pObject = FUN_140159860(0xc8, p);
    FUN_1415eaf30(pObject, FUN_1415e4ce0(pVal));
}

// @0x1415e3510
extern void* FUN_1415e4e50(void* p);
void FUN_1415e3510(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    void* pObject = FUN_140159860(0xc8, p);
    FUN_1415eaf30(pObject, FUN_1415e4e50(pVal));
}

// @0x1415e3560
extern void* FUN_1415e5070(void* p);
extern void FUN_1415eaeb0(void* self, void* other);
void FUN_1415e3560(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    void* pObject = FUN_140159860(0xc8, p);
    FUN_1415eaeb0(pObject, FUN_1415e5070(pVal));
}

// @0x1415e35b0
extern void* FUN_1415e4cf0(void* p);
void FUN_1415e35b0(void*, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMSessionMemberInfo(*reinterpret_cast<const CNMSessionMemberInfo*>(FUN_1415e4cf0(pVal)));
}

// @0x1415e3600
extern void* FUN_1415e4e60(void* p);
void FUN_1415e3600(void*, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMSessionMemberInfo(*reinterpret_cast<const CNMSessionMemberInfo*>(FUN_1415e4e60(pVal)));
}

// @0x1415e3650
extern void* FUN_1415e5080(void* p);
void FUN_1415e3650(void*, Unk_StlElem<0xf8>* p, Unk_StlElem<0xf8>* pVal)
{
    ::new (static_cast<void*>(p)) CNMSessionMemberInfo(*reinterpret_cast<const CNMSessionMemberInfo*>(FUN_1415e5080(pVal)));
}

// @0x1415e36a0
extern void* FUN_1415e4d00(void* p);
void FUN_1415e36a0(void*, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal)
{
    ::new (static_cast<void*>(p)) CNMVirtualUserInfo(*reinterpret_cast<const CNMVirtualUserInfo*>(FUN_1415e4d00(pVal)));
}

// @0x1415e36f0
extern void* FUN_1415e4e70(void* p);
void FUN_1415e36f0(void*, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal)
{
    ::new (static_cast<void*>(p)) CNMVirtualUserInfo(*reinterpret_cast<const CNMVirtualUserInfo*>(FUN_1415e4e70(pVal)));
}

// @0x1415e3740
extern void* FUN_1415e5090(void* p);
void FUN_1415e3740(void*, Unk_StlElem<0x490>* p, Unk_StlElem<0x490>* pVal)
{
    ::new (static_cast<void*>(p)) CNMVirtualUserInfo(*reinterpret_cast<const CNMVirtualUserInfo*>(FUN_1415e5090(pVal)));
}

// @0x1415e3790
extern void* FUN_1415e4d10(void* p);
void FUN_1415e3790(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    ::new (static_cast<void*>(p)) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(FUN_1415e4d10(pVal)));
}

// @0x1415e37e0
extern void* FUN_1415e4e80(void* p);
void FUN_1415e37e0(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    ::new (static_cast<void*>(p)) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(FUN_1415e4e80(pVal)));
}

// @0x1415e3830
extern void* FUN_1415e50a0(void* p);
void FUN_1415e3830(void*, Unk_StlElem<0x20>* p, Unk_StlElem<0x20>* pVal)
{
    ::new (static_cast<void*>(p)) CNMSetServerInfoFunc::RequestInfo(*reinterpret_cast<const CNMSetServerInfoFunc::RequestInfo*>(FUN_1415e50a0(pVal)));
}

// @0x1415e38a0
void FUN_1415e38a0(void*, Unk_StlElem<0x58>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e38d0
void FUN_1415e38d0(void*, Unk_StlElem<0x30>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3900
void FUN_1415e3900(void*, Unk_StlElem<0x98>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3930
void FUN_1415e3930(void*, Unk_StlElem<0x220>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3960
void FUN_1415e3960(void*, Unk_StlElem<0x128>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3990
void FUN_1415e3990(void*, Unk_StlElem<0x118>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e39c0
void FUN_1415e39c0(void*, Unk_StlElem<0xe0>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e39f0
void FUN_1415e39f0(void*, Unk_StlElem<0x580>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3a20
void FUN_1415e3a20(void*, Unk_StlElem<0x18>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3a50
void FUN_1415e3a50(void*, Unk_StlElem<0x14a8>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3a80
void FUN_1415e3a80(void*, Unk_StlElem<0x18>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3ab0
void FUN_1415e3ab0(void*, Unk_StlElem<0x190>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3ae0
void FUN_1415e3ae0(void*, Unk_StlElem<0xb8>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3b10
void FUN_1415e3b10(void*, Unk_StlElem<0x58>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3b40
void FUN_1415e3b40(void*, Unk_StlElem<0x68>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3b70
void FUN_1415e3b70(void*, Unk_StlElem<0xae8>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3ba0
void FUN_1415e3ba0(void*, Unk_StlElem<0xec8>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3bd0
void FUN_1415e3bd0(void*, Unk_StlElem<0xc8>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3c00
void FUN_1415e3c00(void*, Unk_StlElem<0xf8>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3c30
void FUN_1415e3c30(void*, Unk_StlElem<0x490>* p)
{
    reinterpret_cast<Unk_VDtorElem*>(p)->ScalarDelete(0);
}

// @0x1415e3c60
void FUN_1415e3c60(void*, Unk_StlElem<0x20>* p)
{
    FUN_1415f93d0(p, 0);
}

// @0x1415e4bf0
Unk_StlElem<0x58>* FUN_1415e4bf0(Unk_StlElem<0x58>* p)
{
    return p;
}

// @0x1415e4c00
Unk_StlElem<0x30>* FUN_1415e4c00(Unk_StlElem<0x30>* p)
{
    return p;
}

// @0x1415e4c10
Unk_StlElem<0x98>* FUN_1415e4c10(Unk_StlElem<0x98>* p)
{
    return p;
}

// @0x1415e4c20
Unk_StlElem<0x220>* FUN_1415e4c20(Unk_StlElem<0x220>* p)
{
    return p;
}

// @0x1415e4c30
Unk_StlElem<0x128>* FUN_1415e4c30(Unk_StlElem<0x128>* p)
{
    return p;
}

// @0x1415e4c40
Unk_StlElem<0x118>* FUN_1415e4c40(Unk_StlElem<0x118>* p)
{
    return p;
}

// @0x1415e4c50
Unk_StlElem<0x580>* FUN_1415e4c50(Unk_StlElem<0x580>* p)
{
    return p;
}

// @0x1415e4c60
Unk_StlElem<0x18>* FUN_1415e4c60(Unk_StlElem<0x18>* p)
{
    return p;
}

// @0x1415e4c70
Unk_StlElem<0x14a8>* FUN_1415e4c70(Unk_StlElem<0x14a8>* p)
{
    return p;
}

// @0x1415e4c80
Unk_StlElem<0x18>* FUN_1415e4c80(Unk_StlElem<0x18>* p)
{
    return p;
}

// @0x1415e4c90
Unk_StlElem<0x190>* FUN_1415e4c90(Unk_StlElem<0x190>* p)
{
    return p;
}

// @0x1415e4ca0
Unk_StlElem<0xb8>* FUN_1415e4ca0(Unk_StlElem<0xb8>* p)
{
    return p;
}

// @0x1415e4cb0
Unk_StlElem<0x58>* FUN_1415e4cb0(Unk_StlElem<0x58>* p)
{
    return p;
}

// @0x1415e4cc0
Unk_StlElem<0xae8>* FUN_1415e4cc0(Unk_StlElem<0xae8>* p)
{
    return p;
}

// @0x1415e4cd0
Unk_StlElem<0xec8>* FUN_1415e4cd0(Unk_StlElem<0xec8>* p)
{
    return p;
}

// @0x1415e4ce0
Unk_StlElem<0xc8>* FUN_1415e4ce0(Unk_StlElem<0xc8>* p)
{
    return p;
}

// @0x1415e4cf0
Unk_StlElem<0xf8>* FUN_1415e4cf0(Unk_StlElem<0xf8>* p)
{
    return p;
}

// @0x1415e4d00
Unk_StlElem<0x490>* FUN_1415e4d00(Unk_StlElem<0x490>* p)
{
    return p;
}

// @0x1415e4d10
Unk_StlElem<0x20>* FUN_1415e4d10(Unk_StlElem<0x20>* p)
{
    return p;
}

// @0x1415e4d20
Unk_StlElem<0x10>* FUN_1415e4d20(Unk_StlElem<0x10>* p)
{
    return p;
}

// @0x1415e4d30
Unk_StlElem<0x18>* FUN_1415e4d30(Unk_StlElem<0x18>* p)
{
    return p;
}

// @0x1415e4d40
Unk_StlElem<0x58>* FUN_1415e4d40(Unk_StlElem<0x58>* p)
{
    return p;
}

// @0x1415e4d50
void* FUN_1415e4d50(void* p)
{
    return p;
}

// @0x1415e4d60
Unk_StlElem<0x98>* FUN_1415e4d60(Unk_StlElem<0x98>* p)
{
    return p;
}

// @0x1415e4d70
Unk_StlElem<0x220>* FUN_1415e4d70(Unk_StlElem<0x220>* p)
{
    return p;
}

// @0x1415e4d80
Unk_StlElem<0x128>* FUN_1415e4d80(Unk_StlElem<0x128>* p)
{
    return p;
}

// @0x1415e4d90
Unk_StlElem<0x118>* FUN_1415e4d90(Unk_StlElem<0x118>* p)
{
    return p;
}

// @0x1415e4da0
Unk_StlElem<0xe0>* FUN_1415e4da0(Unk_StlElem<0xe0>* p)
{
    return p;
}

// @0x1415e4db0
Unk_StlElem<0x580>* FUN_1415e4db0(Unk_StlElem<0x580>* p)
{
    return p;
}

// @0x1415e4dc0
Unk_StlElem<0x18>* FUN_1415e4dc0(Unk_StlElem<0x18>* p)
{
    return p;
}

// @0x1415e4dd0
Unk_StlElem<0x14a8>* FUN_1415e4dd0(Unk_StlElem<0x14a8>* p)
{
    return p;
}

// @0x1415e4de0
Unk_StlElem<0x18>* FUN_1415e4de0(Unk_StlElem<0x18>* p)
{
    return p;
}

// @0x1415e4df0
Unk_StlElem<0x190>* FUN_1415e4df0(Unk_StlElem<0x190>* p)
{
    return p;
}

// @0x1415e4e00
Unk_StlElem<0xb8>* FUN_1415e4e00(Unk_StlElem<0xb8>* p)
{
    return p;
}

// @0x1415e4e10
Unk_StlElem<0x58>* FUN_1415e4e10(Unk_StlElem<0x58>* p)
{
    return p;
}

// @0x1415e4e20
Unk_StlElem<0x68>* FUN_1415e4e20(Unk_StlElem<0x68>* p)
{
    return p;
}

// @0x1415e4e30
Unk_StlElem<0xae8>* FUN_1415e4e30(Unk_StlElem<0xae8>* p)
{
    return p;
}

// @0x1415e4e40
Unk_StlElem<0xec8>* FUN_1415e4e40(Unk_StlElem<0xec8>* p)
{
    return p;
}

// @0x1415e4e50
Unk_StlElem<0xc8>* FUN_1415e4e50(Unk_StlElem<0xc8>* p)
{
    return p;
}

// @0x1415e4e60
Unk_StlElem<0xf8>* FUN_1415e4e60(Unk_StlElem<0xf8>* p)
{
    return p;
}

// @0x1415e4e70
Unk_StlElem<0x490>* FUN_1415e4e70(Unk_StlElem<0x490>* p)
{
    return p;
}

// @0x1415e4e80
Unk_StlElem<0x20>* FUN_1415e4e80(Unk_StlElem<0x20>* p)
{
    return p;
}

// @0x1415e4f60
Unk_StlElem<0x58>* FUN_1415e4f60(Unk_StlElem<0x58>* p)
{
    return p;
}

// @0x1415e4f70
Unk_StlElem<0x30>* FUN_1415e4f70(Unk_StlElem<0x30>* p)
{
    return p;
}

// @0x1415e4f80
Unk_StlElem<0x98>* FUN_1415e4f80(Unk_StlElem<0x98>* p)
{
    return p;
}

// @0x1415e4f90
Unk_StlElem<0x220>* FUN_1415e4f90(Unk_StlElem<0x220>* p)
{
    return p;
}

// @0x1415e4fa0
Unk_StlElem<0x128>* FUN_1415e4fa0(Unk_StlElem<0x128>* p)
{
    return p;
}

// @0x1415e4fb0
Unk_StlElem<0x118>* FUN_1415e4fb0(Unk_StlElem<0x118>* p)
{
    return p;
}

// @0x1415e4fc0
Unk_StlElem<0xe0>* FUN_1415e4fc0(Unk_StlElem<0xe0>* p)
{
    return p;
}

// @0x1415e4fd0
Unk_StlElem<0x580>* FUN_1415e4fd0(Unk_StlElem<0x580>* p)
{
    return p;
}

// @0x1415e4fe0
Unk_StlElem<0x18>* FUN_1415e4fe0(Unk_StlElem<0x18>* p)
{
    return p;
}

// @0x1415e4ff0
Unk_StlElem<0x14a8>* FUN_1415e4ff0(Unk_StlElem<0x14a8>* p)
{
    return p;
}

// @0x1415e5000
Unk_StlElem<0x18>* FUN_1415e5000(Unk_StlElem<0x18>* p)
{
    return p;
}

// @0x1415e5010
Unk_StlElem<0x190>* FUN_1415e5010(Unk_StlElem<0x190>* p)
{
    return p;
}

// @0x1415e5020
Unk_StlElem<0xb8>* FUN_1415e5020(Unk_StlElem<0xb8>* p)
{
    return p;
}

// @0x1415e5030
Unk_StlElem<0x58>* FUN_1415e5030(Unk_StlElem<0x58>* p)
{
    return p;
}

// @0x1415e5040
Unk_StlElem<0x68>* FUN_1415e5040(Unk_StlElem<0x68>* p)
{
    return p;
}

// @0x1415e5050
Unk_StlElem<0xae8>* FUN_1415e5050(Unk_StlElem<0xae8>* p)
{
    return p;
}

// @0x1415e5060
Unk_StlElem<0xec8>* FUN_1415e5060(Unk_StlElem<0xec8>* p)
{
    return p;
}

// @0x1415e5070
Unk_StlElem<0xc8>* FUN_1415e5070(Unk_StlElem<0xc8>* p)
{
    return p;
}

// @0x1415e5080
Unk_StlElem<0xf8>* FUN_1415e5080(Unk_StlElem<0xf8>* p)
{
    return p;
}

// @0x1415e5090
Unk_StlElem<0x490>* FUN_1415e5090(Unk_StlElem<0x490>* p)
{
    return p;
}

// @0x1415e50a0
Unk_StlElem<0x20>* FUN_1415e50a0(Unk_StlElem<0x20>* p)
{
    return p;
}

// @0x1415e59a0
template<> CNMStr<0x20>::CNMStr(const CNMStr<0x20>& r)
    : m_p(&DAT_143ae2848)
{
    FUN_1415f9a90(this, r.m_p);
}

// @0x1415e5a20
template<> CNMStr<0x20>::CNMStr()
    : m_p(&DAT_143ae2848)
{
}

// @0x1415e5b80
template<> CNMStr<0x800>::CNMStr(const CNMStr<0x800>& r)
    : m_p(&DAT_143ae2849)
{
    FUN_1415f9b80(this, r.m_p);
}

// @0x1415e5c00
template<> CNMStr<0x800>::CNMStr()
    : m_p(&DAT_143ae2849)
{
}

// @0x1415e4bc0
void* FUN_1415e4bc0(void* p) { return p; }

// @0x1415e4bd0
void* FUN_1415e4bd0(void* p) { return p; }

// @0x1415e4be0
void* FUN_1415e4be0(void* p) { return p; }

// @0x1415e4e90
void* FUN_1415e4e90(void* p) { return p; }

// @0x1415e4ea0
void* FUN_1415e4ea0(void* p) { return p; }

// @0x1415e4eb0
void* FUN_1415e4eb0(void* p) { return p; }

// @0x1415e4ec0
void* FUN_1415e4ec0(void* p) { return p; }

// @0x1415e4ed0
void* FUN_1415e4ed0(void* p) { return p; }

// @0x1415e4ee0
void* FUN_1415e4ee0(void* p) { return p; }

// @0x1415e4ef0
void* FUN_1415e4ef0(void* p) { return p; }

// @0x1415e4f00
void* FUN_1415e4f00(void* p) { return p; }

// @0x1415e4f10
void* FUN_1415e4f10(void* p) { return p; }

// @0x1415e4f20
void* FUN_1415e4f20(void* p) { return p; }

// @0x1415e4f30
void* FUN_1415e4f30(void* p) { return p; }

// @0x1415e4f40
void* FUN_1415e4f40(void* p) { return p; }

// @0x1415e4f50
void* FUN_1415e4f50(void* p) { return p; }

// @0x1415e5140
void* FUN_1415e5140(void* p) { return p; }

// @0x1415e5150
void* FUN_1415e5150(void* p) { return p; }

// @0x1415e5160
void* FUN_1415e5160(void* p) { return p; }

// @0x1415e5170
void* FUN_1415e5170(void* p) { return p; }

// @0x1415e5180
void* FUN_1415e5180(void* p) { return p; }

// @0x1415e5190
void* FUN_1415e5190(void* p) { return p; }

// @0x1415e51a0
void* FUN_1415e51a0(void* p) { return p; }

// @0x1415e51b0
void* FUN_1415e51b0(void* p) { return p; }

// @0x1415e51c0
void* FUN_1415e51c0(void* p) { return p; }

// @0x1415e51d0
void* FUN_1415e51d0(void* p) { return p; }

// @0x1415e51e0
void* FUN_1415e51e0(void* p) { return p; }

// @0x1415e51f0
void* FUN_1415e51f0(void* p) { return p; }

// @0x1415e5200
void* FUN_1415e5200(void* p) { return p; }

// @0x1415e5210
void* FUN_1415e5210(void* p) { return p; }

// @0x1415e5220
void* FUN_1415e5220(void* p) { return p; }

// @0x1415e5230
void* FUN_1415e5230(void* p) { return p; }

// @0x1415e5240
void* FUN_1415e5240(void* p) { return p; }

// @0x1415e5250
void* FUN_1415e5250(void* p) { return p; }

// @0x1415e5260
void* FUN_1415e5260(void* p) { return p; }

// @0x1415e5270
void* FUN_1415e5270(void* p) { return p; }

// @0x1415e5280
void* FUN_1415e5280(void* p) { return p; }

// @0x1415e5290
void* FUN_1415e5290(void* p) { return p; }

// @0x1415e52a0
void* FUN_1415e52a0(void* p) { return p; }

// @0x1415e52b0
void* FUN_1415e52b0(void* p) { return p; }

// @0x1415e52c0
void* FUN_1415e52c0(void* p) { return p; }

// @0x1415e52d0
void* FUN_1415e52d0(void* p) { return p; }

// @0x1415e52e0
void* FUN_1415e52e0(void* p) { return p; }

// @0x1415e52f0
void* FUN_1415e52f0(void* p) { return p; }

// @0x1415e5300
void* FUN_1415e5300(void* p) { return p; }

// @0x1415e5310
void* FUN_1415e5310(void* p) { return p; }

// @0x1415e5320
void* FUN_1415e5320(void* p) { return p; }

// @0x1415e4080
void FUN_1415e4080(void* pThis, Unk_StlElem<0x10>* pVal)
{
    if (FUN_1416020d0(pThis)) {
        FUN_1415d5970(pThis, reinterpret_cast<Unk_StlElem<0x10>*>(FUN_1415e4d20(pVal)));
    } else {
        Unk_StlElem<0x10>* pDead = FUN_1415d6b70(pThis, FUN_141603980(pThis), reinterpret_cast<Unk_StlElem<0x10>*>(FUN_1415e4d20(pVal)));
    }
}

// @0x1415e40f0
void FUN_1415e40f0(void* pThis, Unk_StlElem<0x18>* pVal)
{
    if (FUN_141602120(pThis)) {
        FUN_1415d5a30(pThis, reinterpret_cast<Unk_StlElem<0x18>*>(FUN_1415e4d30(pVal)));
    } else {
        Unk_StlElem<0x18>* pDead = FUN_1415d6dc0(pThis, FUN_1416039c0(pThis), reinterpret_cast<Unk_StlElem<0x18>*>(FUN_1415e4d30(pVal)));
    }
}

// @0x1415e4160
void FUN_1415e4160(void* pThis, Unk_StlElem<0x20>* pVal)
{
    if (FUN_14029bbc0(pThis)) {
        FUN_1415d5af0(pThis, reinterpret_cast<Unk_StlElem<0x20>*>(FUN_1403a4b80(pVal)));
    } else {
        Unk_StlElem<0x20>* pDead = FUN_1415d7010(pThis, FUN_14029c010(pThis), reinterpret_cast<Unk_StlElem<0x20>*>(FUN_1403a4b80(pVal)));
    }
}

// @0x1415e41d0
void FUN_1415e41d0(void* pThis, Unk_StlElem<0x58>* pVal)
{
    if (FUN_141602170(pThis)) {
        FUN_1415d5bb0(pThis, reinterpret_cast<Unk_StlElem<0x58>*>(FUN_1415e4d40(pVal)));
    } else {
        Unk_StlElem<0x58>* pDead = FUN_1415d7260(pThis, FUN_141603a00(pThis), reinterpret_cast<Unk_StlElem<0x58>*>(FUN_1415e4d40(pVal)));
    }
}

// @0x1415e4240
void FUN_1415e4240(void* pThis, Unk_StlElem<0x30>* pVal)
{
    if (FUN_1416021c0(pThis)) {
        FUN_1415d5c70(pThis, reinterpret_cast<Unk_StlElem<0x30>*>(FUN_1415e4d50(pVal)));
    } else {
        Unk_StlElem<0x30>* pDead = FUN_1415d74b0(pThis, FUN_141603a40(pThis), reinterpret_cast<Unk_StlElem<0x30>*>(FUN_1415e4d50(pVal)));
    }
}

// @0x1415e42b0
void FUN_1415e42b0(void* pThis, Unk_StlElem<0x98>* pVal)
{
    if (FUN_141602210(pThis)) {
        FUN_1415d5d30(pThis, reinterpret_cast<Unk_StlElem<0x98>*>(FUN_1415e4d60(pVal)));
    } else {
        Unk_StlElem<0x98>* pDead = FUN_1415d7700(pThis, FUN_141603a80(pThis), reinterpret_cast<Unk_StlElem<0x98>*>(FUN_1415e4d60(pVal)));
    }
}

// @0x1415e4320
void FUN_1415e4320(void* pThis, Unk_StlElem<0x220>* pVal)
{
    if (FUN_141602260(pThis)) {
        FUN_1415d5df0(pThis, reinterpret_cast<Unk_StlElem<0x220>*>(FUN_1415e4d70(pVal)));
    } else {
        Unk_StlElem<0x220>* pDead = FUN_1415d7970(pThis, FUN_141603ac0(pThis), reinterpret_cast<Unk_StlElem<0x220>*>(FUN_1415e4d70(pVal)));
    }
}

// @0x1415e4390
void FUN_1415e4390(void* pThis, Unk_StlElem<0x128>* pVal)
{
    if (FUN_1416022b0(pThis)) {
        FUN_1415d5eb0(pThis, reinterpret_cast<Unk_StlElem<0x128>*>(FUN_1415e4d80(pVal)));
    } else {
        Unk_StlElem<0x128>* pDead = FUN_1415d7be0(pThis, FUN_141603b00(pThis), reinterpret_cast<Unk_StlElem<0x128>*>(FUN_1415e4d80(pVal)));
    }
}

// @0x1415e4400
void FUN_1415e4400(void* pThis, Unk_StlElem<0x118>* pVal)
{
    if (FUN_141602300(pThis)) {
        FUN_1415d5f70(pThis, reinterpret_cast<Unk_StlElem<0x118>*>(FUN_1415e4d90(pVal)));
    } else {
        Unk_StlElem<0x118>* pDead = FUN_1415d7e50(pThis, FUN_141603b40(pThis), reinterpret_cast<Unk_StlElem<0x118>*>(FUN_1415e4d90(pVal)));
    }
}

// @0x1415e4470
void FUN_1415e4470(void* pThis, Unk_StlElem<0xe0>* pVal)
{
    if (FUN_141602350(pThis)) {
        FUN_1415d6030(pThis, reinterpret_cast<Unk_StlElem<0xe0>*>(FUN_1415e4da0(pVal)));
    } else {
        Unk_StlElem<0xe0>* pDead = FUN_1415d80c0(pThis, FUN_141603b80(pThis), reinterpret_cast<Unk_StlElem<0xe0>*>(FUN_1415e4da0(pVal)));
    }
}

// @0x1415e44e0
void FUN_1415e44e0(void* pThis, Unk_StlElem<0x580>* pVal)
{
    if (FUN_1416023a0(pThis)) {
        FUN_1415d60f0(pThis, reinterpret_cast<Unk_StlElem<0x580>*>(FUN_1415e4db0(pVal)));
    } else {
        Unk_StlElem<0x580>* pDead = FUN_1415d8330(pThis, FUN_141603bc0(pThis), reinterpret_cast<Unk_StlElem<0x580>*>(FUN_1415e4db0(pVal)));
    }
}

// @0x1415e4550
void FUN_1415e4550(void* pThis, Unk_StlElem<0x18>* pVal)
{
    if (FUN_1416023f0(pThis)) {
        FUN_1415d61b0(pThis, reinterpret_cast<Unk_StlElem<0x18>*>(FUN_1415e4dc0(pVal)));
    } else {
        Unk_StlElem<0x18>* pDead = FUN_1415d85a0(pThis, FUN_141603c00(pThis), reinterpret_cast<Unk_StlElem<0x18>*>(FUN_1415e4dc0(pVal)));
    }
}

// @0x1415e45c0
void FUN_1415e45c0(void* pThis, Unk_StlElem<0x14a8>* pVal)
{
    if (FUN_141602440(pThis)) {
        FUN_1415d6270(pThis, reinterpret_cast<Unk_StlElem<0x14a8>*>(FUN_1415e4dd0(pVal)));
    } else {
        Unk_StlElem<0x14a8>* pDead = FUN_1415d87f0(pThis, FUN_141603c40(pThis), reinterpret_cast<Unk_StlElem<0x14a8>*>(FUN_1415e4dd0(pVal)));
    }
}

// @0x1415e4630
void FUN_1415e4630(void* pThis, Unk_StlElem<0x18>* pVal)
{
    if (FUN_141602490(pThis)) {
        FUN_1415d6330(pThis, reinterpret_cast<Unk_StlElem<0x18>*>(FUN_1415e4de0(pVal)));
    } else {
        Unk_StlElem<0x18>* pDead = FUN_1415d8a60(pThis, FUN_141603c80(pThis), reinterpret_cast<Unk_StlElem<0x18>*>(FUN_1415e4de0(pVal)));
    }
}

// @0x1415e46a0
void FUN_1415e46a0(void* pThis, Unk_StlElem<0x190>* pVal)
{
    if (FUN_1416024e0(pThis)) {
        FUN_1415d63f0(pThis, reinterpret_cast<Unk_StlElem<0x190>*>(FUN_1415e4df0(pVal)));
    } else {
        Unk_StlElem<0x190>* pDead = FUN_1415d8cb0(pThis, FUN_141603cc0(pThis), reinterpret_cast<Unk_StlElem<0x190>*>(FUN_1415e4df0(pVal)));
    }
}

// @0x1415e4710
void FUN_1415e4710(void* pThis, Unk_StlElem<0xb8>* pVal)
{
    if (FUN_141602530(pThis)) {
        FUN_1415d64b0(pThis, reinterpret_cast<Unk_StlElem<0xb8>*>(FUN_1415e4e00(pVal)));
    } else {
        Unk_StlElem<0xb8>* pDead = FUN_1415d8f20(pThis, FUN_141603d00(pThis), reinterpret_cast<Unk_StlElem<0xb8>*>(FUN_1415e4e00(pVal)));
    }
}

// @0x1415e4780
void FUN_1415e4780(void* pThis, Unk_StlElem<0x58>* pVal)
{
    if (FUN_141602580(pThis)) {
        FUN_1415d6570(pThis, reinterpret_cast<Unk_StlElem<0x58>*>(FUN_1415e4e10(pVal)));
    } else {
        Unk_StlElem<0x58>* pDead = FUN_1415d9190(pThis, FUN_141603d40(pThis), reinterpret_cast<Unk_StlElem<0x58>*>(FUN_1415e4e10(pVal)));
    }
}

// @0x1415e47f0
void FUN_1415e47f0(void* pThis, Unk_StlElem<0x68>* pVal)
{
    if (FUN_1416025d0(pThis)) {
        FUN_1415d6630(pThis, reinterpret_cast<Unk_StlElem<0x68>*>(FUN_1415e4e20(pVal)));
    } else {
        Unk_StlElem<0x68>* pDead = FUN_1415d93e0(pThis, FUN_141603d80(pThis), reinterpret_cast<Unk_StlElem<0x68>*>(FUN_1415e4e20(pVal)));
    }
}

// @0x1415e4860
void FUN_1415e4860(void* pThis, Unk_StlElem<0xae8>* pVal)
{
    if (FUN_141602620(pThis)) {
        FUN_1415d66f0(pThis, reinterpret_cast<Unk_StlElem<0xae8>*>(FUN_1415e4e30(pVal)));
    } else {
        Unk_StlElem<0xae8>* pDead = FUN_1415d9630(pThis, FUN_141603dc0(pThis), reinterpret_cast<Unk_StlElem<0xae8>*>(FUN_1415e4e30(pVal)));
    }
}

// @0x1415e48d0
void FUN_1415e48d0(void* pThis, Unk_StlElem<0xec8>* pVal)
{
    if (FUN_141602670(pThis)) {
        FUN_1415d67b0(pThis, reinterpret_cast<Unk_StlElem<0xec8>*>(FUN_1415e4e40(pVal)));
    } else {
        Unk_StlElem<0xec8>* pDead = FUN_1415d98a0(pThis, FUN_141603e00(pThis), reinterpret_cast<Unk_StlElem<0xec8>*>(FUN_1415e4e40(pVal)));
    }
}

// @0x1415e4940
void FUN_1415e4940(void* pThis, Unk_StlElem<0xc8>* pVal)
{
    if (FUN_1416026c0(pThis)) {
        FUN_1415d6870(pThis, reinterpret_cast<Unk_StlElem<0xc8>*>(FUN_1415e4e50(pVal)));
    } else {
        Unk_StlElem<0xc8>* pDead = FUN_1415d9b10(pThis, FUN_141603e40(pThis), reinterpret_cast<Unk_StlElem<0xc8>*>(FUN_1415e4e50(pVal)));
    }
}

// @0x1415e49b0
void FUN_1415e49b0(void* pThis, Unk_StlElem<0xf8>* pVal)
{
    if (FUN_141602710(pThis)) {
        FUN_1415d6930(pThis, reinterpret_cast<Unk_StlElem<0xf8>*>(FUN_1415e4e60(pVal)));
    } else {
        Unk_StlElem<0xf8>* pDead = FUN_1415d9d80(pThis, FUN_141603e80(pThis), reinterpret_cast<Unk_StlElem<0xf8>*>(FUN_1415e4e60(pVal)));
    }
}

// @0x1415e4a20
void FUN_1415e4a20(void* pThis, Unk_StlElem<0x490>* pVal)
{
    if (FUN_141602760(pThis)) {
        FUN_1415d69f0(pThis, reinterpret_cast<Unk_StlElem<0x490>*>(FUN_1415e4e70(pVal)));
    } else {
        Unk_StlElem<0x490>* pDead = FUN_1415d9ff0(pThis, FUN_141603ec0(pThis), reinterpret_cast<Unk_StlElem<0x490>*>(FUN_1415e4e70(pVal)));
    }
}

// @0x1415e4a90
void FUN_1415e4a90(void* pThis, Unk_StlElem<0x20>* pVal)
{
    if (FUN_1416027b0(pThis)) {
        FUN_1415d6ab0(pThis, reinterpret_cast<Unk_StlElem<0x20>*>(FUN_1415e4e80(pVal)));
    } else {
        Unk_StlElem<0x20>* pDead = FUN_1415da260(pThis, FUN_141603f00(pThis), reinterpret_cast<Unk_StlElem<0x20>*>(FUN_1415e4e80(pVal)));
    }
}

// @0x1415e3880
void FUN_1415e3880(void*, void*) {}

// @0x1415e3890
void FUN_1415e3890(void*, void*) {}


// @0x1415e59e0
void* FUN_1415e59e0(void* pThis, const char* value)
{
    *reinterpret_cast<const char**>(pThis) = &DAT_143ae2848;
    FUN_1415f9a90(pThis, value);
    return pThis;
}

// @0x1415e5bc0
void* FUN_1415e5bc0(void* pThis, const char* value)
{
    *reinterpret_cast<const char**>(pThis) = &DAT_143ae2849;
    FUN_1415f9b80(pThis, value);
    return pThis;
}


// The node fields match the recovered MSVC tree node: three links, color/isnil bytes,
// six bytes of padding, then pair<const unsigned char, void*> at +0x20.
struct Unk_TreePairib
{
    void* m_pNode;
    bool m_bInserted;
};
extern Unk_TreePairib* FUN_1415db990(void* pTree, Unk_TreePairib* pResult, bool bLeftish,
                                     const unsigned char* pVal, std::_Tree_node<unsigned char, void*>* pNewNode);
extern unsigned char FUN_1415f4790(const int* pKey, void* pRecord);

// MS2-FUNCTIONAL: allocates the recovered 0x30-byte byte-to-pointer map node and inserts it through the tree helper.
// @0x1415e4010
void* FUN_1415e4010(void* pTree, Unk_TreePairib* pResult, const void* pVal)
{
    struct NodeLayout
    {
        void* left;
        void* parent;
        void* right;
        unsigned char color;
        unsigned char isNil;
        unsigned char padding[6];
        unsigned char value[0x10];
    };
    static_assert(sizeof(NodeLayout) == 0x30, "node size");
    auto* node = static_cast<NodeLayout*>(::operator new(sizeof(NodeLayout)));
    std::memset(node, 0, 0x20);
    std::memcpy(node->value, FUN_1415e4ea0(const_cast<void*>(pVal)), sizeof(node->value));
    FUN_1415db990(pTree, pResult, false, node->value,
                  reinterpret_cast<std::_Tree_node<unsigned char, void*>*>(node));
    return pResult;
}

// @0x1415e50b0
void* FUN_1415e50b0(void* pTree, Unk_TreePairib* pResult, const void* pVal)
{
    FUN_1415e4010(pTree, pResult, FUN_1415e4ea0(const_cast<void*>(pVal)));
    return pResult;
}

// MS2-FUNCTIONAL: scans the 0x68-byte guild records with the recovered key comparator and returns the found iterator.
// @0x1415e4b00
void* FUN_1415e4b00(void** pResult, void* first, void* last, const int* pKey)
{
    auto* current = static_cast<unsigned char*>(first);
    auto* finish = static_cast<unsigned char*>(last);
    while (current != finish && !FUN_1415f4790(pKey, current))
        current += 0x68;
    *pResult = current;
    return pResult;
}

// MS2-FUNCTIONAL: compacts the range by removing matching characters and returns the new logical end iterator.
// @0x1415e56c0
void* FUN_1415e56c0(void** pResult, char* first, char* last, const char* pValue)
{
    char* found = first;
    while (found != last && *found != *pValue)
        ++found;
    char* output = found;
    for (char* current = found; current != last; ++current)
    {
        if (*current != *pValue)
        {
            *output = *current;
            ++output;
        }
    }
    *pResult = output;
    return pResult;
}


// MS2-FUNCTIONAL: the two callers pass scalar values and a scalar reference; on MSVC x64 double and long double share the same 8-byte ABI.
// @0x1415e50f0
template<> std::pair<double, double> std::make_pair<double, double&>(double&& first, double& second)
{
    return std::pair<double, double>(static_cast<double&&>(first), second);
}


// MS2-PIN: ?FUN_1415e2430@@YAXPEAXPEAU?$Unk_StlElem@$0BA@@@1@Z 0x1415e2430
// MS2-PIN: ?FUN_1415e2480@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2480
// MS2-PIN: ?FUN_1415e24d0@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e24d0
// MS2-PIN: ?FUN_1415e2520@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e2520
// MS2-PIN: ?FUN_1415e2570@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e2570
// MS2-PIN: ?FUN_1415e25c0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e25c0
// MS2-PIN: ?FUN_1415e2610@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x1415e2610
// MS2-PIN: ?FUN_1415e2660@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x1415e2660
// MS2-PIN: ?FUN_1415e26b0@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@1@Z 0x1415e26b0
// MS2-PIN: ?FUN_1415e2700@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x1415e2700
// MS2-PIN: ?FUN_1415e2750@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x1415e2750
// MS2-PIN: ?FUN_1415e27a0@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@1@Z 0x1415e27a0
// MS2-PIN: ?FUN_1415e27f0@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x1415e27f0
// MS2-PIN: ?FUN_1415e2840@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x1415e2840
// MS2-PIN: ?FUN_1415e2890@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@1@Z 0x1415e2890
// MS2-PIN: ?FUN_1415e28e0@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x1415e28e0
// MS2-PIN: ?FUN_1415e2930@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x1415e2930
// MS2-PIN: ?FUN_1415e2980@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@1@Z 0x1415e2980
// MS2-PIN: ?FUN_1415e29d0@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x1415e29d0
// MS2-PIN: ?FUN_1415e2a20@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x1415e2a20
// MS2-PIN: ?FUN_1415e2a70@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@1@Z 0x1415e2a70
// MS2-PIN: ?FUN_1415e2ac0@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@1@Z 0x1415e2ac0
// MS2-PIN: ?FUN_1415e2b10@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@1@Z 0x1415e2b10
// MS2-PIN: ?FUN_1415e2b60@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1415e2b60
// MS2-PIN: ?FUN_1415e2bb0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1415e2bb0
// MS2-PIN: ?FUN_1415e2c00@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@1@Z 0x1415e2c00
// MS2-PIN: ?FUN_1415e2c50@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2c50
// MS2-PIN: ?FUN_1415e2ca0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2ca0
// MS2-PIN: ?FUN_1415e2cf0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2cf0
// MS2-PIN: ?FUN_1415e2d40@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1415e2d40
// MS2-PIN: ?FUN_1415e2d90@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1415e2d90
// MS2-PIN: ?FUN_1415e2de0@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@1@Z 0x1415e2de0
// MS2-PIN: ?FUN_1415e2e30@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2e30
// MS2-PIN: ?FUN_1415e2e80@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2e80
// MS2-PIN: ?FUN_1415e2ed0@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@1@Z 0x1415e2ed0
// MS2-PIN: ?FUN_1415e2f20@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1415e2f20
// MS2-PIN: ?FUN_1415e2f70@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1415e2f70
// MS2-PIN: ?FUN_1415e2fc0@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@1@Z 0x1415e2fc0
// MS2-PIN: ?FUN_1415e3010@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e3010
// MS2-PIN: ?FUN_1415e3060@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e3060
// MS2-PIN: ?FUN_1415e30b0@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e30b0
// MS2-PIN: ?FUN_1415e3100@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@1@Z 0x1415e3100
// MS2-PIN: ?FUN_1415e3150@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e3150
// MS2-PIN: ?FUN_1415e31a0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e31a0
// MS2-PIN: ?FUN_1415e31f0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@1@Z 0x1415e31f0
// MS2-PIN: ?FUN_1415e3240@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@1@Z 0x1415e3240
// MS2-PIN: ?FUN_1415e3290@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@1@Z 0x1415e3290
// MS2-PIN: ?FUN_1415e32e0@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x1415e32e0
// MS2-PIN: ?FUN_1415e3330@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x1415e3330
// MS2-PIN: ?FUN_1415e3380@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@1@Z 0x1415e3380
// MS2-PIN: ?FUN_1415e33d0@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x1415e33d0
// MS2-PIN: ?FUN_1415e3420@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x1415e3420
// MS2-PIN: ?FUN_1415e3470@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@1@Z 0x1415e3470
// MS2-PIN: ?FUN_1415e34c0@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x1415e34c0
// MS2-PIN: ?FUN_1415e3510@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x1415e3510
// MS2-PIN: ?FUN_1415e3560@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@1@Z 0x1415e3560
// MS2-PIN: ?FUN_1415e35b0@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x1415e35b0
// MS2-PIN: ?FUN_1415e3600@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x1415e3600
// MS2-PIN: ?FUN_1415e3650@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@1@Z 0x1415e3650
// MS2-PIN: ?FUN_1415e36a0@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x1415e36a0
// MS2-PIN: ?FUN_1415e36f0@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x1415e36f0
// MS2-PIN: ?FUN_1415e3740@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@1@Z 0x1415e3740
// MS2-PIN: ?FUN_1415e3790@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e3790
// MS2-PIN: ?FUN_1415e37e0@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e37e0
// MS2-PIN: ?FUN_1415e3830@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@1@Z 0x1415e3830
// MS2-PIN: ?FUN_1415e38a0@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@@Z 0x1415e38a0
// MS2-PIN: ?FUN_1415e38d0@@YAXPEAXPEAU?$Unk_StlElem@$0DA@@@@Z 0x1415e38d0
// MS2-PIN: ?FUN_1415e3900@@YAXPEAXPEAU?$Unk_StlElem@$0JI@@@@Z 0x1415e3900
// MS2-PIN: ?FUN_1415e3930@@YAXPEAXPEAU?$Unk_StlElem@$0CCA@@@@Z 0x1415e3930
// MS2-PIN: ?FUN_1415e3960@@YAXPEAXPEAU?$Unk_StlElem@$0BCI@@@@Z 0x1415e3960
// MS2-PIN: ?FUN_1415e3990@@YAXPEAXPEAU?$Unk_StlElem@$0BBI@@@@Z 0x1415e3990
// MS2-PIN: ?FUN_1415e39c0@@YAXPEAXPEAU?$Unk_StlElem@$0OA@@@@Z 0x1415e39c0
// MS2-PIN: ?FUN_1415e39f0@@YAXPEAXPEAU?$Unk_StlElem@$0FIA@@@@Z 0x1415e39f0
// MS2-PIN: ?FUN_1415e3a20@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@@Z 0x1415e3a20
// MS2-PIN: ?FUN_1415e3a50@@YAXPEAXPEAU?$Unk_StlElem@$0BEKI@@@@Z 0x1415e3a50
// MS2-PIN: ?FUN_1415e3a80@@YAXPEAXPEAU?$Unk_StlElem@$0BI@@@@Z 0x1415e3a80
// MS2-PIN: ?FUN_1415e3ab0@@YAXPEAXPEAU?$Unk_StlElem@$0BJA@@@@Z 0x1415e3ab0
// MS2-PIN: ?FUN_1415e3ae0@@YAXPEAXPEAU?$Unk_StlElem@$0LI@@@@Z 0x1415e3ae0
// MS2-PIN: ?FUN_1415e3b10@@YAXPEAXPEAU?$Unk_StlElem@$0FI@@@@Z 0x1415e3b10
// MS2-PIN: ?FUN_1415e3b40@@YAXPEAXPEAU?$Unk_StlElem@$0GI@@@@Z 0x1415e3b40
// MS2-PIN: ?FUN_1415e3b70@@YAXPEAXPEAU?$Unk_StlElem@$0KOI@@@@Z 0x1415e3b70
// MS2-PIN: ?FUN_1415e3ba0@@YAXPEAXPEAU?$Unk_StlElem@$0OMI@@@@Z 0x1415e3ba0
// MS2-PIN: ?FUN_1415e3bd0@@YAXPEAXPEAU?$Unk_StlElem@$0MI@@@@Z 0x1415e3bd0
// MS2-PIN: ?FUN_1415e3c00@@YAXPEAXPEAU?$Unk_StlElem@$0PI@@@@Z 0x1415e3c00
// MS2-PIN: ?FUN_1415e3c30@@YAXPEAXPEAU?$Unk_StlElem@$0EJA@@@@Z 0x1415e3c30
// MS2-PIN: ?FUN_1415e3c60@@YAXPEAXPEAU?$Unk_StlElem@$0CA@@@@Z 0x1415e3c60
// MS2-PIN: ?FUN_1415e4bf0@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4bf0
// MS2-PIN: ?FUN_1415e4c00@@YAPEAU?$Unk_StlElem@$0DA@@@PEAU1@@Z 0x1415e4c00
// MS2-PIN: ?FUN_1415e4c10@@YAPEAU?$Unk_StlElem@$0JI@@@PEAU1@@Z 0x1415e4c10
// MS2-PIN: ?FUN_1415e4c20@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAU1@@Z 0x1415e4c20
// MS2-PIN: ?FUN_1415e4c30@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAU1@@Z 0x1415e4c30
// MS2-PIN: ?FUN_1415e4c40@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAU1@@Z 0x1415e4c40
// MS2-PIN: ?FUN_1415e4c50@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAU1@@Z 0x1415e4c50
// MS2-PIN: ?FUN_1415e4c60@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4c60
// MS2-PIN: ?FUN_1415e4c70@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAU1@@Z 0x1415e4c70
// MS2-PIN: ?FUN_1415e4c80@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4c80
// MS2-PIN: ?FUN_1415e4c90@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAU1@@Z 0x1415e4c90
// MS2-PIN: ?FUN_1415e4ca0@@YAPEAU?$Unk_StlElem@$0LI@@@PEAU1@@Z 0x1415e4ca0
// MS2-PIN: ?FUN_1415e4cb0@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4cb0
// MS2-PIN: ?FUN_1415e4cc0@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAU1@@Z 0x1415e4cc0
// MS2-PIN: ?FUN_1415e4cd0@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAU1@@Z 0x1415e4cd0
// MS2-PIN: ?FUN_1415e4ce0@@YAPEAU?$Unk_StlElem@$0MI@@@PEAU1@@Z 0x1415e4ce0
// MS2-PIN: ?FUN_1415e4cf0@@YAPEAU?$Unk_StlElem@$0PI@@@PEAU1@@Z 0x1415e4cf0
// MS2-PIN: ?FUN_1415e4d00@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAU1@@Z 0x1415e4d00
// MS2-PIN: ?FUN_1415e4d10@@YAPEAU?$Unk_StlElem@$0CA@@@PEAU1@@Z 0x1415e4d10
// MS2-PIN: ?FUN_1415e4d20@@YAPEAU?$Unk_StlElem@$0BA@@@PEAU1@@Z 0x1415e4d20
// MS2-PIN: ?FUN_1415e4d30@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4d30
// MS2-PIN: ?FUN_1415e4d40@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4d40
// MS2-PIN: ?FUN_1415e4d50@@YAPEAXPEAX@Z 0x1415e4d50
// MS2-PIN: ?FUN_1415e4d60@@YAPEAU?$Unk_StlElem@$0JI@@@PEAU1@@Z 0x1415e4d60
// MS2-PIN: ?FUN_1415e4d70@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAU1@@Z 0x1415e4d70
// MS2-PIN: ?FUN_1415e4d80@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAU1@@Z 0x1415e4d80
// MS2-PIN: ?FUN_1415e4d90@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAU1@@Z 0x1415e4d90
// MS2-PIN: ?FUN_1415e4da0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAU1@@Z 0x1415e4da0
// MS2-PIN: ?FUN_1415e4db0@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAU1@@Z 0x1415e4db0
// MS2-PIN: ?FUN_1415e4dc0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4dc0
// MS2-PIN: ?FUN_1415e4dd0@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAU1@@Z 0x1415e4dd0
// MS2-PIN: ?FUN_1415e4de0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4de0
// MS2-PIN: ?FUN_1415e4df0@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAU1@@Z 0x1415e4df0
// MS2-PIN: ?FUN_1415e4e00@@YAPEAU?$Unk_StlElem@$0LI@@@PEAU1@@Z 0x1415e4e00
// MS2-PIN: ?FUN_1415e4e10@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4e10
// MS2-PIN: ?FUN_1415e4e20@@YAPEAU?$Unk_StlElem@$0GI@@@PEAU1@@Z 0x1415e4e20
// MS2-PIN: ?FUN_1415e4e30@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAU1@@Z 0x1415e4e30
// MS2-PIN: ?FUN_1415e4e40@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAU1@@Z 0x1415e4e40
// MS2-PIN: ?FUN_1415e4e50@@YAPEAU?$Unk_StlElem@$0MI@@@PEAU1@@Z 0x1415e4e50
// MS2-PIN: ?FUN_1415e4e60@@YAPEAU?$Unk_StlElem@$0PI@@@PEAU1@@Z 0x1415e4e60
// MS2-PIN: ?FUN_1415e4e70@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAU1@@Z 0x1415e4e70
// MS2-PIN: ?FUN_1415e4e80@@YAPEAU?$Unk_StlElem@$0CA@@@PEAU1@@Z 0x1415e4e80
// MS2-PIN: ?FUN_1415e4f60@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e4f60
// MS2-PIN: ?FUN_1415e4f70@@YAPEAU?$Unk_StlElem@$0DA@@@PEAU1@@Z 0x1415e4f70
// MS2-PIN: ?FUN_1415e4f80@@YAPEAU?$Unk_StlElem@$0JI@@@PEAU1@@Z 0x1415e4f80
// MS2-PIN: ?FUN_1415e4f90@@YAPEAU?$Unk_StlElem@$0CCA@@@PEAU1@@Z 0x1415e4f90
// MS2-PIN: ?FUN_1415e4fa0@@YAPEAU?$Unk_StlElem@$0BCI@@@PEAU1@@Z 0x1415e4fa0
// MS2-PIN: ?FUN_1415e4fb0@@YAPEAU?$Unk_StlElem@$0BBI@@@PEAU1@@Z 0x1415e4fb0
// MS2-PIN: ?FUN_1415e4fc0@@YAPEAU?$Unk_StlElem@$0OA@@@PEAU1@@Z 0x1415e4fc0
// MS2-PIN: ?FUN_1415e4fd0@@YAPEAU?$Unk_StlElem@$0FIA@@@PEAU1@@Z 0x1415e4fd0
// MS2-PIN: ?FUN_1415e4fe0@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e4fe0
// MS2-PIN: ?FUN_1415e4ff0@@YAPEAU?$Unk_StlElem@$0BEKI@@@PEAU1@@Z 0x1415e4ff0
// MS2-PIN: ?FUN_1415e5000@@YAPEAU?$Unk_StlElem@$0BI@@@PEAU1@@Z 0x1415e5000
// MS2-PIN: ?FUN_1415e5010@@YAPEAU?$Unk_StlElem@$0BJA@@@PEAU1@@Z 0x1415e5010
// MS2-PIN: ?FUN_1415e5020@@YAPEAU?$Unk_StlElem@$0LI@@@PEAU1@@Z 0x1415e5020
// MS2-PIN: ?FUN_1415e5030@@YAPEAU?$Unk_StlElem@$0FI@@@PEAU1@@Z 0x1415e5030
// MS2-PIN: ?FUN_1415e5040@@YAPEAU?$Unk_StlElem@$0GI@@@PEAU1@@Z 0x1415e5040
// MS2-PIN: ?FUN_1415e5050@@YAPEAU?$Unk_StlElem@$0KOI@@@PEAU1@@Z 0x1415e5050
// MS2-PIN: ?FUN_1415e5060@@YAPEAU?$Unk_StlElem@$0OMI@@@PEAU1@@Z 0x1415e5060
// MS2-PIN: ?FUN_1415e5070@@YAPEAU?$Unk_StlElem@$0MI@@@PEAU1@@Z 0x1415e5070
// MS2-PIN: ?FUN_1415e5080@@YAPEAU?$Unk_StlElem@$0PI@@@PEAU1@@Z 0x1415e5080
// MS2-PIN: ?FUN_1415e5090@@YAPEAU?$Unk_StlElem@$0EJA@@@PEAU1@@Z 0x1415e5090
// MS2-PIN: ?FUN_1415e50a0@@YAPEAU?$Unk_StlElem@$0CA@@@PEAU1@@Z 0x1415e50a0
// MS2-PIN: ??0?$CNMStr@$0CA@@@QEAA@AEBV0@@Z 0x1415e59a0
// MS2-PIN: ??0?$CNMStr@$0CA@@@QEAA@XZ 0x1415e5a20
// MS2-PIN: ??0?$CNMStr@$0IAA@@@QEAA@AEBV0@@Z 0x1415e5b80
// MS2-PIN: ??0?$CNMStr@$0IAA@@@QEAA@XZ 0x1415e5c00
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
// MS2-PIN: ??0?$CNMSingleton@VCNMCOClientObject@@@@QEAA@XZ 0x1415e57b0
// MS2-PIN: ??0?$CNMSingleton@VCNMManager@@@@QEAA@XZ 0x1415e57d0
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$00$0BI@@@@?$vector@U?$Unk_VecElem@$00$0BI@@@V?$allocator@U?$Unk_VecElem@$00$0BI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$00$0BI@@@@Z 0x1415e4080
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$01$0FI@@@@?$vector@U?$Unk_VecElem@$01$0FI@@@V?$allocator@U?$Unk_VecElem@$01$0FI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$01$0FI@@@@Z 0x1415e40f0
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$02$0DA@@@@?$vector@U?$Unk_VecElem@$02$0DA@@@V?$allocator@U?$Unk_VecElem@$02$0DA@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$02$0DA@@@@Z 0x1415e4160
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$03$0JI@@@@?$vector@U?$Unk_VecElem@$03$0JI@@@V?$allocator@U?$Unk_VecElem@$03$0JI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$03$0JI@@@@Z 0x1415e41d0
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$04$0CCA@@@@?$vector@U?$Unk_VecElem@$04$0CCA@@@V?$allocator@U?$Unk_VecElem@$04$0CCA@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$04$0CCA@@@@Z 0x1415e4240
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$05$0BCI@@@@?$vector@U?$Unk_VecElem@$05$0BCI@@@V?$allocator@U?$Unk_VecElem@$05$0BCI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$05$0BCI@@@@Z 0x1415e42b0
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$06$0BBI@@@@?$vector@U?$Unk_VecElem@$06$0BBI@@@V?$allocator@U?$Unk_VecElem@$06$0BBI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$06$0BBI@@@@Z 0x1415e4320
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$07$0FIA@@@@?$vector@U?$Unk_VecElem@$07$0FIA@@@V?$allocator@U?$Unk_VecElem@$07$0FIA@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$07$0FIA@@@@Z 0x1415e4390
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$08$0BI@@@@?$vector@U?$Unk_VecElem@$08$0BI@@@V?$allocator@U?$Unk_VecElem@$08$0BI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$08$0BI@@@@Z 0x1415e4400
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$09$0BEKI@@@@?$vector@U?$Unk_VecElem@$09$0BEKI@@@V?$allocator@U?$Unk_VecElem@$09$0BEKI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$09$0BEKI@@@@Z 0x1415e4470
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0A@$0BA@@@@?$vector@U?$Unk_VecElem@$0A@$0BA@@@V?$allocator@U?$Unk_VecElem@$0A@$0BA@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0A@$0BA@@@@Z 0x1415e44e0
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0BA@$0OMI@@@@?$vector@U?$Unk_VecElem@$0BA@$0OMI@@@V?$allocator@U?$Unk_VecElem@$0BA@$0OMI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0BA@$0OMI@@@@Z 0x1415e4550
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0BB@$0MI@@@@?$vector@U?$Unk_VecElem@$0BB@$0MI@@@V?$allocator@U?$Unk_VecElem@$0BB@$0MI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0BB@$0MI@@@@Z 0x1415e45c0
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0BC@$0PI@@@@?$vector@U?$Unk_VecElem@$0BC@$0PI@@@V?$allocator@U?$Unk_VecElem@$0BC@$0PI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0BC@$0PI@@@@Z 0x1415e4630
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0BD@$0EJA@@@@?$vector@U?$Unk_VecElem@$0BD@$0EJA@@@V?$allocator@U?$Unk_VecElem@$0BD@$0EJA@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0BD@$0EJA@@@@Z 0x1415e46a0
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0BE@$0CA@@@@?$vector@U?$Unk_VecElem@$0BE@$0CA@@@V?$allocator@U?$Unk_VecElem@$0BE@$0CA@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0BE@$0CA@@@@Z 0x1415e4710
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0BF@$0DA@@@@?$vector@U?$Unk_VecElem@$0BF@$0DA@@@V?$allocator@U?$Unk_VecElem@$0BF@$0DA@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0BF@$0DA@@@@Z 0x1415e4780
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0BG@$0OA@@@@?$vector@U?$Unk_VecElem@$0BG@$0OA@@@V?$allocator@U?$Unk_VecElem@$0BG@$0OA@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0BG@$0OA@@@@Z 0x1415e47f0
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0BH@$0GI@@@@?$vector@U?$Unk_VecElem@$0BH@$0GI@@@V?$allocator@U?$Unk_VecElem@$0BH@$0GI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0BH@$0GI@@@@Z 0x1415e4860
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0L@$0BI@@@@?$vector@U?$Unk_VecElem@$0L@$0BI@@@V?$allocator@U?$Unk_VecElem@$0L@$0BI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0L@$0BI@@@@Z 0x1415e48d0
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0M@$0BJA@@@@?$vector@U?$Unk_VecElem@$0M@$0BJA@@@V?$allocator@U?$Unk_VecElem@$0M@$0BJA@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0M@$0BJA@@@@Z 0x1415e4940
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0N@$0LI@@@@?$vector@U?$Unk_VecElem@$0N@$0LI@@@V?$allocator@U?$Unk_VecElem@$0N@$0LI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0N@$0LI@@@@Z 0x1415e49b0
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0O@$0FI@@@@?$vector@U?$Unk_VecElem@$0O@$0FI@@@V?$allocator@U?$Unk_VecElem@$0O@$0FI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0O@$0FI@@@@Z 0x1415e4a20
// MS2-PIN: ??$emplace_back@AEBU?$Unk_VecElem@$0P@$0KOI@@@@?$vector@U?$Unk_VecElem@$0P@$0KOI@@@V?$allocator@U?$Unk_VecElem@$0P@$0KOI@@@@std@@@std@@QEAAXAEBU?$Unk_VecElem@$0P@$0KOI@@@@Z 0x1415e4a90
// MS2-PIN: ??$make_pair@NAEAN@std@@YA?AU?$pair@NN@0@$$QEANAEAN@Z 0x1415e50f0
