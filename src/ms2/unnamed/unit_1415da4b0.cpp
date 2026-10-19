// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Template zone of the boxed-pointer TU: std::find<char>
// helpers, 12 std::_Get_size_of_n<sizeof(T)> instantiations (element types unknown) and identity/forwarding thunks.
// MS2-UNIT: unit_1415da4b0
// MS2-RANGE: 0x1415da4b0-0x1415dad30 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$_Find_unchecked1@PEBDD@std@@YAPEBDPEBDQEBDAEBDU?$integral_constant@_N$00@0@@Z 0x1415da4b0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include <algorithm>

// Unrecovered callees: FUN_1415e1730 (identity getter), FUN_1415e3880 (guard-object ctor),
// FUN_141609460 (guard-object dtor/commit), FUN_14160700x (destroy-range step helpers).
extern void* FUN_1415e1730(void* p);
extern void FUN_1415e3880(void* guard, void* p);
extern void FUN_141609460(void* guard, void* p, int n);
extern void FUN_141606ff0(void* p);
extern void FUN_141607000(void* p);
extern void FUN_141607010(void* p);

template const char* std::_Find_unchecked<const char*, char>(const char* const, const char* const, const char&);

// @0x1415da590
// MS2-FUNCTIONAL: exe frame carries a C++ EH unwind state (-2) for the unrecovered guard object; ours has no unwind object.
void FUN_1415da590(void* a, void* p)
{
    char guard[8];
    FUN_1415e3880(guard, FUN_1415e1730(p));
    FUN_1415e3880(guard, FUN_1415e1730((char*)p + 8));
    FUN_1415e3880(guard, FUN_1415e1730((char*)p + 0x10));
    FUN_141609460(guard, p, 1);
}

// 12 x _Get_size_of_n<sizeof(T)>, in exe order
template size_t std::_Get_size_of_n<0x118>(const size_t);
template size_t std::_Get_size_of_n<0x128>(const size_t);
template size_t std::_Get_size_of_n<0x14a8>(const size_t);
template size_t std::_Get_size_of_n<400>(const size_t);
template size_t std::_Get_size_of_n<0x220>(const size_t);
template size_t std::_Get_size_of_n<0x490>(const size_t);
template size_t std::_Get_size_of_n<0x580>(const size_t);
template size_t std::_Get_size_of_n<0xae8>(const size_t);
template size_t std::_Get_size_of_n<0xb8>(const size_t);
template size_t std::_Get_size_of_n<0xe0>(const size_t);
template size_t std::_Get_size_of_n<0xec8>(const size_t);
template size_t std::_Get_size_of_n<0xf8>(const size_t);

// @0x1415da9e0
void* FUN_1415da9e0(void* p)
{
    return p;
}

// @0x1415da9f0
void* FUN_1415da9f0(void* p)
{
    return p;
}

// @0x1415daa00
void* FUN_1415daa00(void* p)
{
    return p;
}

// @0x1415daa10
void FUN_1415daa10(void* p)
{
    FUN_141606ff0(p);
}

// @0x1415daa30
void FUN_1415daa30(void* p)
{
    FUN_141607000(p);
}

// @0x1415daa50
void FUN_1415daa50(void* p)
{
    FUN_141607010(p);
}

// @0x1415daa70
void* FUN_1415daa70(void* p)
{
    return p;
}

// @0x1415daa80
void* FUN_1415daa80(void* p)
{
    return p;
}

// @0x1415daa90
void* FUN_1415daa90(void* p)
{
    return p;
}

// @0x1415daaa0
void* FUN_1415daaa0(void* p)
{
    return p;
}

// @0x1415daab0
void* FUN_1415daab0(void* p)
{
    return p;
}

// @0x1415daac0
void* FUN_1415daac0(void* p)
{
    return p;
}

// @0x1415daad0
void* FUN_1415daad0(void* p)
{
    return p;
}

// @0x1415daae0
void* FUN_1415daae0(void* p)
{
    return p;
}

// @0x1415daaf0
void* FUN_1415daaf0(void* p)
{
    return p;
}

// @0x1415dab00
void* FUN_1415dab00(void* p)
{
    return p;
}

// @0x1415dab10
void* FUN_1415dab10(void* p)
{
    return p;
}

// @0x1415dab20
void* FUN_1415dab20(void* p)
{
    return p;
}

// @0x1415dab30
void* FUN_1415dab30(void* p)
{
    return p;
}

// @0x1415dab40
void* FUN_1415dab40(void* p)
{
    return p;
}

// @0x1415dab50
void* FUN_1415dab50(void* p)
{
    return p;
}

// @0x1415dab60
void* FUN_1415dab60(void* p)
{
    return p;
}

// @0x1415dab70
void* FUN_1415dab70(void* p)
{
    return p;
}

// @0x1415dab80
void* FUN_1415dab80(void* p)
{
    return p;
}

// @0x1415dab90
void* FUN_1415dab90(void* p)
{
    return p;
}

// @0x1415daba0
void* FUN_1415daba0(void* p)
{
    return p;
}

// @0x1415dabb0
void* FUN_1415dabb0(void* p)
{
    return p;
}

// @0x1415dabc0
void* FUN_1415dabc0(void* p, void* q)
{
    return p;
}

// @0x1415dabd0
void* FUN_1415dabd0(void* p, void* q)
{
    return p;
}

// @0x1415dabe0
void* FUN_1415dabe0(void* p, void* q)
{
    return p;
}

// @0x1415dabf0
void* FUN_1415dabf0(void* p, void* q)
{
    return p;
}

// @0x1415dac00
void* FUN_1415dac00(void* p, void* q)
{
    return p;
}

// @0x1415dac10
void* FUN_1415dac10(void* p, void* q)
{
    return p;
}

// @0x1415dac20
void* FUN_1415dac20(void* p, void* q)
{
    return p;
}

// @0x1415dac30
void* FUN_1415dac30(void* p, void* q)
{
    return p;
}

// @0x1415dac40
void* FUN_1415dac40(void* p, void* q)
{
    return p;
}

// @0x1415dac50
void* FUN_1415dac50(void* p, void* q)
{
    return p;
}

// @0x1415dac60
void* FUN_1415dac60(void* p, void* q)
{
    return p;
}

// @0x1415dac70
void* FUN_1415dac70(void* p, void* q)
{
    return p;
}

// @0x1415dac80
void* FUN_1415dac80(void* p, void* q)
{
    return p;
}

// @0x1415dac90
void* FUN_1415dac90(void* p, void* q)
{
    return p;
}

// @0x1415daca0
void* FUN_1415daca0(void* p, void* q)
{
    return p;
}

// @0x1415dacb0
void* FUN_1415dacb0(void* p, void* q)
{
    return p;
}

// @0x1415dacc0
void* FUN_1415dacc0(void* p, void* q)
{
    return p;
}

// @0x1415dacd0
void* FUN_1415dacd0(void* p, void* q)
{
    return p;
}

// @0x1415dace0
void* FUN_1415dace0(void* p, void* q)
{
    return p;
}

// @0x1415dacf0
void* FUN_1415dacf0(void* p, void* q)
{
    return p;
}

// @0x1415dad00
void* FUN_1415dad00(void* p, void* q)
{
    return p;
}

// @0x1415dad10
void* FUN_1415dad10(void* p, void* q)
{
    return p;
}

// @0x1415dad20
void* FUN_1415dad20(void* p, void* q)
{
    return p;
}
