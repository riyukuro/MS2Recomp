// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Template zone of the boxed-pointer TU, part 4:
// std::_Tree / allocator glue instantiated for 22 map/set element types that are not recoverable from this range alone
// (head init, node free, deallocate(p, n * sizeof(Node)), iterator ==, insert helpers). Written over void* with the
// per-type helpers (FUN_) left as exe callees.
// MS2-UNIT: unit_1416088c0
// MS2-RANGE: 0x1416088c0-0x14160a570 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

// Tree node header (_Left, _Parent, _Right, _Color, _Isnil) followed by the value at +0x20.
struct Unk_TreeNode
{
    void* _Left;
    void* _Parent;
    void* _Right;
    char _Color;
    char _Isnil;
    void* _Myval;
};
MS2_CHECK_SIZE(Unk_TreeNode, 0x28);

extern void FUN_14015fc80(void*, size_t);
extern void* FUN_14029b840(void*);
extern void** FUN_14029c010(void*);
extern void FUN_1415da590(void*, void*);
extern void* FUN_1415e1600(void*);
extern void* FUN_1415e1610(void*);
extern void* FUN_1415e1740(void*);
extern void* FUN_1415e1750(void*);
extern void* FUN_1415e1760(void*);
extern void* FUN_1415e1770(void*);
extern void* FUN_1415e1780(void*);
extern void* FUN_1415e1790(void*);
extern void* FUN_1415e17a0(void*);
extern void* FUN_1415e17b0(void*);
extern void* FUN_1415e17c0(void*);
extern void* FUN_1415e17d0(void*);
extern void* FUN_1415e17e0(void*);
extern void* FUN_1415e17f0(void*);
extern void* FUN_1415e1800(void*);
extern void* FUN_1415e1810(void*);
extern void* FUN_1415e1820(void*);
extern void* FUN_1415e1830(void*);
extern void* FUN_1415e1840(void*);
extern void* FUN_1415e1850(void*);
extern void* FUN_1415e1860(void*);
extern void* FUN_1415e1870(void*);
extern void* FUN_1415e1880(void*);
extern void* FUN_1415e1890(void*);
extern void* FUN_1415e18a0(void*);
extern void* FUN_1415e18b0(void*);
extern void* FUN_1415e18c0(void*);
extern void* FUN_1415e18d0(void*);
extern void FUN_1415e3890(void*, void*);
extern void FUN_1415e5cf0(void*, void*, void*);
extern void FUN_1415e6870(void*, void*, void*);
extern void FUN_1415e68b0(void*, void*, void*);
extern void FUN_1415e6db0(void*, void*, void*);
extern void FUN_1415e6df0(void*, void*, void*);
extern void FUN_1415e6e30(void*, void*, void*);
extern void FUN_1415e6e70(void*, void*, void*);
extern void FUN_1415e6eb0(void*, void*, void*);
extern void FUN_1415e6ef0(void*, void*, void*);
extern void FUN_1415e6f30(void*, void*, void*);
extern void FUN_1415e6f70(void*, void*, void*);
extern void FUN_1415e6fb0(void*, void*, void*);
extern void FUN_1415e6ff0(void*, void*, void*);
extern void FUN_1415e7030(void*, void*, void*);
extern void FUN_1415e7070(void*, void*, void*);
extern void FUN_1415e70b0(void*, void*, void*);
extern void FUN_1415e70f0(void*, void*, void*);
extern void FUN_1415e7130(void*, void*, void*);
extern void FUN_1415e7170(void*, void*, void*);
extern void FUN_1415e71d0(void*, void*, void*);
extern void FUN_1415e7210(void*, void*, void*);
extern void FUN_1415e7270(void*, void*, void*);
extern void FUN_1415e72b0(void*, void*, void*);
extern void FUN_1415e72f0(void*, void*, void*);
extern void FUN_1415e7330(void*, void*, void*);
extern void FUN_1415e7370(void*, void*, void*);
extern void FUN_1415e73b0(void*, void*, void*);
extern bool FUN_1415f2a60(void*, void*);
extern bool FUN_1415f3280(void*, void*);
extern void** FUN_1415f3ec0(void*, void*, int);
extern void FUN_1415f3f10(void*);
extern void FUN_141600150(void*, void*, void*);
extern void FUN_141600190(void*, void*, void*);
extern void FUN_1416001d0(void*, void*, void*);
extern void FUN_141600210(void*, void*, void*);
extern void FUN_141600250(void*, void*, void*);
extern void FUN_141600290(void*, void*, void*);
extern void FUN_1416002d0(void*, void*, void*);
extern void FUN_141600310(void*, void*, void*);
extern void FUN_141600350(void*, void*, void*);
extern void FUN_141600390(void*, void*, void*);
extern void FUN_1416003d0(void*, void*, void*);
extern void FUN_141600410(void*, void*, void*);
extern void FUN_141600450(void*, void*, void*);
extern void FUN_141600490(void*, void*, void*);
extern void FUN_1416004d0(void*, void*, void*);
extern void FUN_141600510(void*, void*, void*);
extern void FUN_141600550(void*, void*, void*);
extern void FUN_141600590(void*, void*, void*);
extern void FUN_1416005d0(void*, void*, void*);
extern void FUN_141600610(void*, void*, void*);
extern void FUN_141600650(void*, void*, void*);
extern void FUN_141600690(void*, void*, void*);
extern void FUN_141600760(void*, void*);
extern void* FUN_141600800(void*, void*);
extern void** FUN_141600e10(void*);
extern void* FUN_141600e70(void*);
extern void* FUN_141600eb0(void*);
extern void* FUN_141600ef0(void*);
extern void* FUN_141600f30(void*);
extern void* FUN_141600f50(void*);
extern void* FUN_141600f70(void*);
extern void* FUN_141600f90(void*);
extern void* FUN_141600fb0(void*);
extern void* FUN_141600ff0(void*);
extern void* FUN_141601030(void*);
extern void* FUN_141601070(void*);
extern void* FUN_1416010b0(void*);
extern void* FUN_1416010f0(void*);
extern void* FUN_141601130(void*);
extern void* FUN_141601170(void*);
extern void* FUN_1416011b0(void*);
extern void* FUN_1416011f0(void*);
extern void* FUN_141601230(void*);
extern void* FUN_141601270(void*);
extern void* FUN_1416012b0(void*);
extern void* FUN_1416012f0(void*);
extern void* FUN_141601330(void*);
extern void* FUN_141601370(void*);
extern void* FUN_1416013b0(void*);
extern void* FUN_1416013f0(void*);
extern void* FUN_141601a70(void*);
extern void** FUN_141602850(void**);
extern void** FUN_1416033c0(void*);
extern void** FUN_141603400(void*);
extern void** FUN_141603440(void*);
extern void** FUN_141603480(void*);
extern void** FUN_1416034c0(void*);
extern void** FUN_1416034e0(void*);
extern void** FUN_141603500(void*);
extern void** FUN_141603540(void*);
extern void** FUN_141603580(void*);
extern void** FUN_1416035c0(void*);
extern void** FUN_141603600(void*);
extern void** FUN_141603640(void*);
extern void** FUN_141603680(void*);
extern void** FUN_1416036c0(void*);
extern void** FUN_141603700(void*);
extern void** FUN_141603740(void*);
extern void** FUN_141603780(void*);
extern void** FUN_1416037c0(void*);
extern void** FUN_141603800(void*);
extern void** FUN_141603840(void*);
extern void** FUN_141603880(void*);
extern void** FUN_1416038c0(void*);
extern void** FUN_141603900(void*);
extern void** FUN_141603920(void*);
extern void** FUN_141603980(void*);
extern void** FUN_1416039c0(void*);
extern void** FUN_141603a00(void*);
extern void** FUN_141603a40(void*);
extern void** FUN_141603a60(void*);
extern void** FUN_141603a80(void*);
extern void** FUN_141603aa0(void*);
extern void** FUN_141603ac0(void*);
extern void** FUN_141603b00(void*);
extern void** FUN_141603b40(void*);
extern void** FUN_141603b80(void*);
extern void** FUN_141603bc0(void*);
extern void** FUN_141603c00(void*);
extern void** FUN_141603c40(void*);
extern void** FUN_141603c80(void*);
extern void** FUN_141603cc0(void*);
extern void** FUN_141603d00(void*);
extern void** FUN_141603d40(void*);
extern void** FUN_141603d80(void*);
extern void** FUN_141603dc0(void*);
extern void** FUN_141603e00(void*);
extern void** FUN_141603e40(void*);
extern void** FUN_141603e80(void*);
extern void** FUN_141603ec0(void*);
extern void** FUN_141603ee0(void*);
extern void** FUN_141603f00(void*);
extern void FUN_141603f40(void*);
extern void FUN_141603f60(void*);
extern void FUN_141603f80(void*);
extern void FUN_141603fa0(void*);
extern void FUN_141603fc0(void*);
extern void FUN_141603fe0(void*);
extern void FUN_141604000(void*);
extern void FUN_141604020(void*);
extern void FUN_141604040(void*);
extern void FUN_141604060(void*);
extern void FUN_141604080(void*);
extern void FUN_1416040a0(void*);
extern void FUN_1416040c0(void*);
extern void FUN_1416040e0(void*);
extern void FUN_141604100(void*);
extern void FUN_141604120(void*);
extern void FUN_141604140(void*);
extern void FUN_141604160(void*);
extern void FUN_141604180(void*);
extern void FUN_1416041a0(void*);
extern void FUN_1416041c0(void*);
extern void FUN_1416041e0(void*);
extern void** FUN_141604630(void**);
extern void** FUN_141604650(void**);
extern void* FUN_141607780(void*, void*);
extern void FUN_1416088c0(void*) noexcept;
extern void* FUN_1416099b0(void*, void*) noexcept;
extern void* FUN_14160a4c0(void*, void*, void*);

// @0x1416088c0
void FUN_1416088c0(void* a) noexcept
{
    void** head = FUN_141600e10(a);
    void* p = *head;
    FUN_141600760(a, *FUN_141604650(head));
    *FUN_141604650(head) = p;
    *FUN_141602850(head) = p;
    *FUN_141604630(head) = p;
    ((Unk_TreeNode*)head)->_Parent = 0;
}

// @0x141608960
void FUN_141608960(void* a) noexcept
{
    FUN_141603f40(a);
    void** x = FUN_141603980(a);
    FUN_141600150(a, *FUN_1416033c0(a), *x);
    void** z = FUN_1416033c0(a);
    *FUN_141603980(a) = *z;
}

// @0x1416089e0
void FUN_1416089e0(void* a) noexcept
{
    FUN_141603f60(a);
    void** x = FUN_1416039c0(a);
    FUN_141600190(a, *FUN_141603400(a), *x);
    void** z = FUN_141603400(a);
    *FUN_1416039c0(a) = *z;
}

// @0x141608a60
void FUN_141608a60(void* a) noexcept
{
    FUN_141603f80(a);
    void** x = FUN_141603a00(a);
    FUN_1416001d0(a, *FUN_141603440(a), *x);
    void** z = FUN_141603440(a);
    *FUN_141603a00(a) = *z;
}

// @0x141608ae0
void FUN_141608ae0(void* a) noexcept
{
    FUN_141603fa0(a);
    void** x = FUN_141603a40(a);
    FUN_141600210(a, *FUN_141603480(a), *x);
    void** z = FUN_141603480(a);
    *FUN_141603a40(a) = *z;
}

// @0x141608b60
void FUN_141608b60(void* a) noexcept
{
    FUN_141603fc0(a);
    void** x = FUN_141603a80(a);
    FUN_141600250(a, *FUN_1416034c0(a), *x);
    void** z = FUN_1416034c0(a);
    *FUN_141603a80(a) = *z;
}

// @0x141608be0
void FUN_141608be0(void* a) noexcept
{
    FUN_141603fe0(a);
    void** x = FUN_141603ac0(a);
    FUN_141600290(a, *FUN_141603500(a), *x);
    void** z = FUN_141603500(a);
    *FUN_141603ac0(a) = *z;
}

// @0x141608c60
void FUN_141608c60(void* a) noexcept
{
    FUN_141604000(a);
    void** x = FUN_141603b00(a);
    FUN_1416002d0(a, *FUN_141603540(a), *x);
    void** z = FUN_141603540(a);
    *FUN_141603b00(a) = *z;
}

// @0x141608ce0
void FUN_141608ce0(void* a) noexcept
{
    FUN_141604020(a);
    void** x = FUN_141603b40(a);
    FUN_141600310(a, *FUN_141603580(a), *x);
    void** z = FUN_141603580(a);
    *FUN_141603b40(a) = *z;
}

// @0x141608d60
void FUN_141608d60(void* a) noexcept
{
    FUN_141604040(a);
    void** x = FUN_141603b80(a);
    FUN_141600350(a, *FUN_1416035c0(a), *x);
    void** z = FUN_1416035c0(a);
    *FUN_141603b80(a) = *z;
}

// @0x141608de0
void FUN_141608de0(void* a) noexcept
{
    FUN_141604060(a);
    void** x = FUN_141603bc0(a);
    FUN_141600390(a, *FUN_141603600(a), *x);
    void** z = FUN_141603600(a);
    *FUN_141603bc0(a) = *z;
}

// @0x141608e60
void FUN_141608e60(void* a) noexcept
{
    FUN_141604080(a);
    void** x = FUN_141603c00(a);
    FUN_1416003d0(a, *FUN_141603640(a), *x);
    void** z = FUN_141603640(a);
    *FUN_141603c00(a) = *z;
}

// @0x141608ee0
void FUN_141608ee0(void* a) noexcept
{
    FUN_1416040a0(a);
    void** x = FUN_141603c40(a);
    FUN_141600410(a, *FUN_141603680(a), *x);
    void** z = FUN_141603680(a);
    *FUN_141603c40(a) = *z;
}

// @0x141608f60
void FUN_141608f60(void* a) noexcept
{
    FUN_1416040c0(a);
    void** x = FUN_141603c80(a);
    FUN_141600450(a, *FUN_1416036c0(a), *x);
    void** z = FUN_1416036c0(a);
    *FUN_141603c80(a) = *z;
}

// @0x141608fe0
void FUN_141608fe0(void* a) noexcept
{
    FUN_1416040e0(a);
    void** x = FUN_141603cc0(a);
    FUN_141600490(a, *FUN_141603700(a), *x);
    void** z = FUN_141603700(a);
    *FUN_141603cc0(a) = *z;
}

// @0x141609060
void FUN_141609060(void* a) noexcept
{
    FUN_141604100(a);
    void** x = FUN_141603d00(a);
    FUN_1416004d0(a, *FUN_141603740(a), *x);
    void** z = FUN_141603740(a);
    *FUN_141603d00(a) = *z;
}

// @0x1416090e0
void FUN_1416090e0(void* a) noexcept
{
    FUN_141604120(a);
    void** x = FUN_141603d40(a);
    FUN_141600510(a, *FUN_141603780(a), *x);
    void** z = FUN_141603780(a);
    *FUN_141603d40(a) = *z;
}

// @0x141609160
void FUN_141609160(void* a) noexcept
{
    FUN_141604140(a);
    void** x = FUN_141603d80(a);
    FUN_141600550(a, *FUN_1416037c0(a), *x);
    void** z = FUN_1416037c0(a);
    *FUN_141603d80(a) = *z;
}

// @0x1416091e0
void FUN_1416091e0(void* a) noexcept
{
    FUN_141604160(a);
    void** x = FUN_141603dc0(a);
    FUN_141600590(a, *FUN_141603800(a), *x);
    void** z = FUN_141603800(a);
    *FUN_141603dc0(a) = *z;
}

// @0x141609260
void FUN_141609260(void* a) noexcept
{
    FUN_141604180(a);
    void** x = FUN_141603e00(a);
    FUN_1416005d0(a, *FUN_141603840(a), *x);
    void** z = FUN_141603840(a);
    *FUN_141603e00(a) = *z;
}

// @0x1416092e0
void FUN_1416092e0(void* a) noexcept
{
    FUN_1416041a0(a);
    void** x = FUN_141603e40(a);
    FUN_141600610(a, *FUN_141603880(a), *x);
    void** z = FUN_141603880(a);
    *FUN_141603e40(a) = *z;
}

// @0x141609360
void FUN_141609360(void* a) noexcept
{
    FUN_1416041c0(a);
    void** x = FUN_141603e80(a);
    FUN_141600650(a, *FUN_1416038c0(a), *x);
    void** z = FUN_1416038c0(a);
    *FUN_141603e80(a) = *z;
}

// @0x1416093e0
void FUN_1416093e0(void* a) noexcept
{
    FUN_1416041e0(a);
    void** x = FUN_141603ec0(a);
    FUN_141600690(a, *FUN_141603900(a), *x);
    void** z = FUN_141603900(a);
    *FUN_141603ec0(a) = *z;
}

// @0x141609460
void FUN_141609460(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x30);
}

// @0x141609490
void FUN_141609490(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x30);
}

// @0x1416094c0
void FUN_1416094c0(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x10);
}

// @0x1416094f0
void FUN_1416094f0(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x18);
}

// @0x141609520
void FUN_141609520(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x58);
}

// @0x141609550
void FUN_141609550(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x30);
}

// @0x141609580
void FUN_141609580(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x98);
}

// @0x1416095b0
void FUN_1416095b0(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x220);
}

// @0x1416095e0
void FUN_1416095e0(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x128);
}

// @0x141609610
void FUN_141609610(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x118);
}

// @0x141609640
void FUN_141609640(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0xe0);
}

// @0x141609670
void FUN_141609670(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x580);
}

// @0x1416096a0
void FUN_1416096a0(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x18);
}

// @0x1416096d0
void FUN_1416096d0(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x14a8);
}

// @0x141609700
void FUN_141609700(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x18);
}

// @0x141609730
void FUN_141609730(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x190);
}

// @0x141609760
void FUN_141609760(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0xb8);
}

// @0x141609790
void FUN_141609790(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x58);
}

// @0x1416097c0
void FUN_1416097c0(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x68);
}

// @0x1416097f0
void FUN_1416097f0(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0xae8);
}

// @0x141609820
void FUN_141609820(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0xec8);
}

// @0x141609850
void FUN_141609850(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0xc8);
}

// @0x141609880
void FUN_141609880(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0xf8);
}

// @0x1416098b0
void FUN_1416098b0(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x490);
}

// @0x1416098e0
void FUN_1416098e0(void* alloc, void* p, size_t n)
{
    FUN_14015fc80(p, n * 0x20);
}

// @0x141609910
bool FUN_141609910(void* a)
{
    return *FUN_1416034e0(a) == *FUN_141603aa0(a);
}

// @0x141609960
bool FUN_141609960(void* a)
{
    return *FUN_141603920(a) == *FUN_141603ee0(a);
}

// @0x1416099b0
void* FUN_1416099b0(void* a, void* b) noexcept
{
    void** h = FUN_141600e10(a);
    FUN_1415e5cf0(b, *h, FUN_1415e1750(h));
    return b;
}

// @0x141609a10
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609a10(void* a, void* b) noexcept
{
    void* t = FUN_1415e1760(FUN_141600e70(a));
    FUN_1415e6db0(b, *FUN_141603980(a), t);
    return b;
}

// @0x141609a70
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609a70(void* a, void* b) noexcept
{
    void* t = FUN_1415e1770(FUN_141600eb0(a));
    FUN_1415e6df0(b, *FUN_1416039c0(a), t);
    return b;
}

// @0x141609ad0
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609ad0(void* a, void* b) noexcept
{
    void* t = FUN_1415e1780(FUN_14029b840(a));
    FUN_1415e6e30(b, *FUN_14029c010(a), t);
    return b;
}

// @0x141609b30
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609b30(void* a, void* b) noexcept
{
    void* t = FUN_1415e1790(FUN_141600ef0(a));
    FUN_1415e6e70(b, *FUN_141603a00(a), t);
    return b;
}

// @0x141609b90
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609b90(void* a, void* b) noexcept
{
    void* t = FUN_1415e17a0(FUN_141600f30(a));
    FUN_1415e6eb0(b, *FUN_141603a40(a), t);
    return b;
}

// @0x141609bf0
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609bf0(void* a, void* b) noexcept
{
    void* t = FUN_1415e1600(FUN_141600f50(a));
    FUN_1415e6870(b, *FUN_141603a60(a), t);
    return b;
}

// @0x141609c50
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609c50(void* a, void* b) noexcept
{
    void* t = FUN_1415e17b0(FUN_141600f70(a));
    FUN_1415e6ef0(b, *FUN_141603a80(a), t);
    return b;
}

// @0x141609cb0
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609cb0(void* a, void* b) noexcept
{
    void* t = FUN_1415e1610(FUN_141600f90(a));
    FUN_1415e68b0(b, *FUN_141603aa0(a), t);
    return b;
}

// @0x141609d10
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609d10(void* a, void* b) noexcept
{
    void* t = FUN_1415e17c0(FUN_141600fb0(a));
    FUN_1415e6f30(b, *FUN_141603ac0(a), t);
    return b;
}

// @0x141609d70
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609d70(void* a, void* b) noexcept
{
    void* t = FUN_1415e17d0(FUN_141600ff0(a));
    FUN_1415e6f70(b, *FUN_141603b00(a), t);
    return b;
}

// @0x141609dd0
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609dd0(void* a, void* b) noexcept
{
    void* t = FUN_1415e17e0(FUN_141601030(a));
    FUN_1415e6fb0(b, *FUN_141603b40(a), t);
    return b;
}

// @0x141609e30
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609e30(void* a, void* b) noexcept
{
    void* t = FUN_1415e17f0(FUN_141601070(a));
    FUN_1415e6ff0(b, *FUN_141603b80(a), t);
    return b;
}

// @0x141609e90
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609e90(void* a, void* b) noexcept
{
    void* t = FUN_1415e1800(FUN_1416010b0(a));
    FUN_1415e7030(b, *FUN_141603bc0(a), t);
    return b;
}

// @0x141609ef0
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609ef0(void* a, void* b) noexcept
{
    void* t = FUN_1415e1810(FUN_1416010f0(a));
    FUN_1415e7070(b, *FUN_141603c00(a), t);
    return b;
}

// @0x141609f50
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609f50(void* a, void* b) noexcept
{
    void* t = FUN_1415e1820(FUN_141601130(a));
    FUN_1415e70b0(b, *FUN_141603c40(a), t);
    return b;
}

// @0x141609fb0
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_141609fb0(void* a, void* b) noexcept
{
    void* t = FUN_1415e1830(FUN_141601170(a));
    FUN_1415e70f0(b, *FUN_141603c80(a), t);
    return b;
}

// @0x14160a010
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_14160a010(void* a, void* b) noexcept
{
    void* t = FUN_1415e1840(FUN_1416011b0(a));
    FUN_1415e7130(b, *FUN_141603cc0(a), t);
    return b;
}

// @0x14160a070
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_14160a070(void* a, void* b) noexcept
{
    void* t = FUN_1415e1850(FUN_1416011f0(a));
    FUN_1415e7170(b, *FUN_141603d00(a), t);
    return b;
}

// @0x14160a0d0
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_14160a0d0(void* a, void* b) noexcept
{
    void* t = FUN_1415e1860(FUN_141601230(a));
    FUN_1415e71d0(b, *FUN_141603d40(a), t);
    return b;
}

// @0x14160a130
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_14160a130(void* a, void* b) noexcept
{
    void* t = FUN_1415e1870(FUN_141601270(a));
    FUN_1415e7210(b, *FUN_141603d80(a), t);
    return b;
}

// @0x14160a190
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_14160a190(void* a, void* b) noexcept
{
    void* t = FUN_1415e1880(FUN_1416012b0(a));
    FUN_1415e7270(b, *FUN_141603dc0(a), t);
    return b;
}

// @0x14160a1f0
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_14160a1f0(void* a, void* b) noexcept
{
    void* t = FUN_1415e1890(FUN_1416012f0(a));
    FUN_1415e72b0(b, *FUN_141603e00(a), t);
    return b;
}

// @0x14160a250
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_14160a250(void* a, void* b) noexcept
{
    void* t = FUN_1415e18a0(FUN_141601330(a));
    FUN_1415e72f0(b, *FUN_141603e40(a), t);
    return b;
}

// @0x14160a2b0
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_14160a2b0(void* a, void* b) noexcept
{
    void* t = FUN_1415e18b0(FUN_141601370(a));
    FUN_1415e7330(b, *FUN_141603e80(a), t);
    return b;
}

// @0x14160a310
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_14160a310(void* a, void* b) noexcept
{
    void* t = FUN_1415e18c0(FUN_1416013b0(a));
    FUN_1415e7370(b, *FUN_141603ec0(a), t);
    return b;
}

// @0x14160a370
// MS2-FUNCTIONAL: exe passes the third iterator argument through rcx (by-value iterator copy); the real template types are not recovered.
void* FUN_14160a370(void* a, void* b) noexcept
{
    void* t = FUN_1415e18d0(FUN_1416013f0(a));
    FUN_1415e73b0(b, *FUN_141603f00(a), t);
    return b;
}

// @0x14160a3d0
void* FUN_14160a3d0(void* a, void* b, void* c, void* d)
{
    char l20[8], l28[8], l30[8], l38[8];
    if (FUN_1415f2a60(&c, FUN_141607780(a, l20)))
    {
        if (FUN_1415f2a60(&d, FUN_1416099b0(a, l28)))
        {
            FUN_1416088c0(a);
            FUN_141607780(a, b);
            return b;
        }
    }
    while (FUN_1415f3280(&c, &d))
        FUN_14160a4c0(a, l38, *FUN_1415f3ec0(&c, l30, 0));
    FUN_1415e5cf0(b, c, FUN_1415e1750(FUN_141600e10(a)));
    return b;
}

// @0x14160a4c0
void* FUN_14160a4c0(void* a, void* b, void* c)
{
    void** head = FUN_141600e10(a);
    void* key = c;
    FUN_1415f3f10(&key);
    Unk_TreeNode* node = (Unk_TreeNode*)FUN_141600800(head, c);
    void* al = FUN_141601a70(a);
    FUN_1415e3890(al, FUN_1415e1740(&node->_Myval));
    FUN_1415da590(al, node);
    FUN_1415e5cf0(b, key, FUN_1415e1750(head));
    return b;
}
