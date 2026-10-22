// Nexon Messenger stream utility bodies; the stream and codec layouts are being recovered in nmstream.h.
// MS2-UNIT: unit_14156a020
// MS2-RANGE: 0x14156a020-0x14156f7e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

extern void FUN_14156a5a0(void*);

// MS2-FUNCTIONAL: delegates to the stream reset implementation at 0x14156a5a0.
// @0x14156a080
void FUN_14156a080(void* p)
{
    FUN_14156a5a0(p);
}

// MS2-FUNCTIONAL: clears the stream fields and frees owned storage; remaining difference is code generation around HeapFree.
// @0x14156a5a0
void FUN_14156a5a0(long long* p)
{
    if (reinterpret_cast<int*>(p)[2] == 0 && p[0] != 0)
        HeapFree(GetProcessHeap(), 0, reinterpret_cast<void*>(p[0]));
    p[0] = 0;
    reinterpret_cast<unsigned int*>(p)[2] = 0;
    reinterpret_cast<unsigned int*>(p)[3] = 0;
    reinterpret_cast<unsigned int*>(p)[4] = 0;
    reinterpret_cast<unsigned int*>(p)[5] = 0;
    reinterpret_cast<unsigned int*>(p)[6] = 0;
    reinterpret_cast<unsigned char*>(p)[0x1c] = 0;
}

// @0x14156a0b0
int FUN_14156a0b0(void* p)
{
    return *reinterpret_cast<int*>(static_cast<char*>(p) + 0x18);
}

// @0x14156a260
void FUN_14156a260(void* p, int clearSize)
{
    *reinterpret_cast<int*>(static_cast<char*>(p) + 0x14) = 8;
    if (clearSize != 0)
        *reinterpret_cast<int*>(static_cast<char*>(p) + 0x0c) = 0;
}

// @0x14156a320
int FUN_14156a320(void* p)
{
    return *reinterpret_cast<int*>(static_cast<char*>(p) + 0x0c) + 0x0c;
}
