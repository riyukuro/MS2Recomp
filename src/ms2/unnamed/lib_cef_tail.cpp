// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CEF 3.x wrapper stream/refcount thunks that the gb:cef TUs
// leave as stubs (ICF-folded bodies and this-adjusting scalar deleting destructors of std::ostringstream-style classes
// with a virtual base), written out over raw object bytes.
// MS2-UNIT: lib_cef_tail
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

void FUN_142749444(void* p, size_t size);   // sized operator delete
extern char DAT_142e1af98[];                // std::ios_base vftable

// @0x1427a54a0
void* FUN_1427a54a0(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        FUN_142749444(base, 0x18);
    return base;
}

// @0x1427aabf0
void* FUN_1427aabf0(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        FUN_142749444(base, 0x18);
    return base;
}

// @0x1427b0d10
void* FUN_1427b0d10(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        FUN_142749444(base, 0x18);
    return base;
}

// @0x1427b1070
void* FUN_1427b1070(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        FUN_142749444(base, 0x18);
    return base;
}

// @0x1427b36f0
void* FUN_1427b36f0(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        FUN_142749444(base, 0x18);
    return base;
}

// @0x1427b4610
void* FUN_1427b4610(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        FUN_142749444(base, 0x18);
    return base;
}

// @0x1427b5780
void* FUN_1427b5780(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        FUN_142749444(base, 0x18);
    return base;
}

// @0x1427b0250
void* FUN_1427b0250(char* self, unsigned flags)
{
    *(void**)self = DAT_142e1af98;
    if (flags & 1)
        FUN_142749444(self, 0x58);
    return self;
}

// @0x1427b0280
void* FUN_1427b0280(char* self, unsigned flags)
{
    *(void**)self = DAT_142e1af98;
    if (flags & 1)
        FUN_142749444(self, 0x58);
    return self;
}

extern char DAT_1431de6c8[];
extern char DAT_1431de6f0[];
// @0x1427a54d0
void* FUN_1427a54d0(char* self, unsigned flags)
{
    char* base = self - 0x20;
    *(void**)base = DAT_1431de6c8;
    *(void**)(self - 0x18 + *(int*)(*(char**)(self - 0x18) + 4)) = DAT_1431de6f0;
    char* vbtable = *(char**)(self - 0x18);
    int off = *(int*)(vbtable + 4);
    *(int*)(self - 0x1c + off) = off - 0x18;
    *(void**)self = DAT_142e1af98;
    if (flags & 1)
        FUN_142749444(base, 0x28);
    return base;
}

extern char DAT_1431dc618[];
extern char DAT_1431dc628[];
// @0x1427aac20
void* FUN_1427aac20(char* self, unsigned flags)
{
    char* base = self - 0x20;
    *(void**)base = DAT_1431dc618;
    *(void**)(self - 0x18 + *(int*)(*(char**)(self - 0x18) + 4)) = DAT_1431dc628;
    char* vbtable = *(char**)(self - 0x18);
    int off = *(int*)(vbtable + 4);
    *(int*)(self - 0x1c + off) = off - 0x18;
    *(void**)self = DAT_142e1af98;
    if (flags & 1)
        FUN_142749444(base, 0x28);
    return base;
}

extern char DAT_1431de3d8[];
extern char DAT_1431de3e0[];
// @0x1427b0d40
void* FUN_1427b0d40(char* self, unsigned flags)
{
    char* base = self - 0x20;
    *(void**)base = DAT_1431de3d8;
    *(void**)(self - 0x18 + *(int*)(*(char**)(self - 0x18) + 4)) = DAT_1431de3e0;
    char* vbtable = *(char**)(self - 0x18);
    int off = *(int*)(vbtable + 4);
    *(int*)(self - 0x1c + off) = off - 0x18;
    *(void**)self = DAT_142e1af98;
    if (flags & 1)
        FUN_142749444(base, 0x28);
    return base;
}

extern char DAT_1431de400[];
extern char DAT_1431de410[];
// @0x1427b10a0
void* FUN_1427b10a0(char* self, unsigned flags)
{
    char* base = self - 0x20;
    *(void**)base = DAT_1431de400;
    *(void**)(self - 0x18 + *(int*)(*(char**)(self - 0x18) + 4)) = DAT_1431de410;
    char* vbtable = *(char**)(self - 0x18);
    int off = *(int*)(vbtable + 4);
    *(int*)(self - 0x1c + off) = off - 0x18;
    *(void**)self = DAT_142e1af98;
    if (flags & 1)
        FUN_142749444(base, 0x28);
    return base;
}

extern char DAT_1431df020[];
extern char DAT_1431df028[];
// @0x1427b3720
void* FUN_1427b3720(char* self, unsigned flags)
{
    char* base = self - 0x20;
    *(void**)base = DAT_1431df020;
    *(void**)(self - 0x18 + *(int*)(*(char**)(self - 0x18) + 4)) = DAT_1431df028;
    char* vbtable = *(char**)(self - 0x18);
    int off = *(int*)(vbtable + 4);
    *(int*)(self - 0x1c + off) = off - 0x18;
    *(void**)self = DAT_142e1af98;
    if (flags & 1)
        FUN_142749444(base, 0x28);
    return base;
}

extern char DAT_1431df560[];
extern char DAT_1431df5a0[];
// @0x1427b4640
void* FUN_1427b4640(char* self, unsigned flags)
{
    char* base = self - 0x20;
    *(void**)base = DAT_1431df560;
    *(void**)(self - 0x18 + *(int*)(*(char**)(self - 0x18) + 4)) = DAT_1431df5a0;
    char* vbtable = *(char**)(self - 0x18);
    int off = *(int*)(vbtable + 4);
    *(int*)(self - 0x1c + off) = off - 0x18;
    *(void**)self = DAT_142e1af98;
    if (flags & 1)
        FUN_142749444(base, 0x28);
    return base;
}
