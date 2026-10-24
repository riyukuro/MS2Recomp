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
    *(void* volatile*)self = DAT_142e1af98;
    if (flags & 1)
        FUN_142749444(self, 0x58);
    return self;
}

// @0x1427b0280
void* FUN_1427b0280(char* self, unsigned flags)
{
    *(void* volatile*)self = DAT_142e1af98;
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
    *(void* volatile*)self = DAT_142e1af98;
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
    *(void* volatile*)self = DAT_142e1af98;
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
    *(void* volatile*)self = DAT_142e1af98;
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
    *(void* volatile*)self = DAT_142e1af98;
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
    *(void* volatile*)self = DAT_142e1af98;
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
    *(void* volatile*)self = DAT_142e1af98;
    if (flags & 1)
        FUN_142749444(base, 0x28);
    return base;
}

extern char DAT_1431d9618[];
extern char DAT_1431d9568[];
extern char DAT_1431d95a0[];
extern char DAT_1431d6fc8[];
extern char DAT_1431d7000[];
extern char DAT_1431d95c0[];
extern char DAT_1431d95f8[];
// @0x142787270
void* FUN_142787270(char* self, int mostDerived)
{
    if (mostDerived)
    {
        *(void* volatile*)(self + 8) = DAT_1431d9618;
        *(void**)(self + 0x20) = DAT_142e1af98;
    }
    *(void* volatile*)self = DAT_1431d9568;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431d95a0;
    *(void* volatile*)self = DAT_1431d6fc8;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431d7000;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    *(volatile int*)(self + 0x10) = 0;
    *(void* volatile*)self = DAT_1431d95c0;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431d95f8;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    return self;
}

extern char DAT_1431da2a8[];
extern char DAT_1431da218[];
extern char DAT_1431da240[];
extern char DAT_1431d75e8[];
extern char DAT_1431d7610[];
extern char DAT_1431da260[];
extern char DAT_1431da288[];
// @0x14278bcd0
void* FUN_14278bcd0(char* self, int mostDerived)
{
    if (mostDerived)
    {
        *(void* volatile*)(self + 8) = DAT_1431da2a8;
        *(void**)(self + 0x20) = DAT_142e1af98;
    }
    *(void* volatile*)self = DAT_1431da218;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431da240;
    *(void* volatile*)self = DAT_1431d75e8;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431d7610;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    *(volatile int*)(self + 0x10) = 0;
    *(void* volatile*)self = DAT_1431da260;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431da288;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    return self;
}

extern char DAT_1431df490[];
extern char DAT_1431df2b0[];
extern char DAT_1431df380[];
extern char DAT_1431dc138[];
extern char DAT_1431dc208[];
extern char DAT_1431df3a0[];
extern char DAT_1431df470[];
// @0x1427a9550
void* FUN_1427a9550(char* self, int mostDerived)
{
    if (mostDerived)
    {
        *(void* volatile*)(self + 8) = DAT_1431df490;
        *(void**)(self + 0x20) = DAT_142e1af98;
    }
    *(void* volatile*)self = DAT_1431df2b0;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431df380;
    *(void* volatile*)self = DAT_1431dc138;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431dc208;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    *(volatile int*)(self + 0x10) = 0;
    *(void* volatile*)self = DAT_1431df3a0;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431df470;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    return self;
}

extern char DAT_1431e03e8[];
extern char DAT_1431e0028[];
extern char DAT_1431e01e8[];
extern char DAT_1431dcf48[];
extern char DAT_1431dd108[];
extern char DAT_1431e0208[];
extern char DAT_1431e03c8[];
// @0x1427ad990
void* FUN_1427ad990(char* self, int mostDerived)
{
    if (mostDerived)
    {
        *(void* volatile*)(self + 8) = DAT_1431e03e8;
        *(void**)(self + 0x20) = DAT_142e1af98;
    }
    *(void* volatile*)self = DAT_1431e0028;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431e01e8;
    *(void* volatile*)self = DAT_1431dcf48;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431dd108;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    *(volatile int*)(self + 0x10) = 0;
    *(void* volatile*)self = DAT_1431e0208;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431e03c8;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    return self;
}

extern char DAT_1431e09b0[];
extern char DAT_1431e0950[];
extern char DAT_1431e0960[];
extern char DAT_1431de378[];
extern char DAT_1431de388[];
extern char DAT_1431e0980[];
extern char DAT_1431e0990[];
// @0x1427b08f0
void* FUN_1427b08f0(char* self, int mostDerived)
{
    if (mostDerived)
    {
        *(void* volatile*)(self + 8) = DAT_1431e09b0;
        *(void**)(self + 0x20) = DAT_142e1af98;
    }
    *(void* volatile*)self = DAT_1431e0950;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431e0960;
    *(void* volatile*)self = DAT_1431de378;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431de388;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    *(volatile int*)(self + 0x10) = 0;
    *(void* volatile*)self = DAT_1431e0980;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431e0990;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    return self;
}

extern char DAT_1431e1418[];
extern char DAT_1431e1268[];
extern char DAT_1431e1320[];
extern char DAT_1431df048[];
extern char DAT_1431df100[];
extern char DAT_1431e1340[];
extern char DAT_1431e13f8[];
// @0x1427b3a60
void* FUN_1427b3a60(char* self, int mostDerived)
{
    if (mostDerived)
    {
        *(void* volatile*)(self + 8) = DAT_1431e1418;
        *(void**)(self + 0x20) = DAT_142e1af98;
    }
    *(void* volatile*)self = DAT_1431e1268;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431e1320;
    *(void* volatile*)self = DAT_1431df048;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431df100;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    *(volatile int*)(self + 0x10) = 0;
    *(void* volatile*)self = DAT_1431e1340;
    *(void**)(self + *(int*)(*(char**)(self + 8) + 4) + 8) = DAT_1431e13f8;
    {
        int off = *(int*)(*(char**)(self + 8) + 4);
        *(int*)(self + off + 4) = off - 0x18;
    }
    return self;
}

// MS2-FUNCTIONAL: same call sequence; the exe frame carries an unwind state slot (-2) from an inlined smart-pointer wrapper we do not model
// @0x14279ff00
bool FUN_14279ff00(void** self)
{
    if (!self)
        return false;
    void** obj = (void**)self[-1];
    return ((bool (*)(void*))(*(void***)obj)[1])(obj);
}
