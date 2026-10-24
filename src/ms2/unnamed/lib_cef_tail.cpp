// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CEF 3.x wrapper stream/refcount thunks that the gb:cef TUs
// leave as stubs (ICF-folded bodies and this-adjusting scalar deleting destructors of std::ostringstream-style classes
// with a virtual base), written out over raw object bytes.
// MS2-UNIT: lib_cef_tail
// MS2-RANGE: 0x142787270-0x142787313 .text$mn
// MS2-RANGE: 0x14278bcd0-0x14278bd73 .text$mn
// MS2-RANGE: 0x14279ff00-0x14279ff2b .text$mn
// MS2-RANGE: 0x1427a54a0-0x1427a54c5 .text$mn
// MS2-RANGE: 0x1427a54d0-0x1427a552f .text$mn
// MS2-RANGE: 0x1427a9550-0x1427a95f3 .text$mn
// MS2-RANGE: 0x1427aabf0-0x1427aac15 .text$mn
// MS2-RANGE: 0x1427aac20-0x1427aac7f .text$mn
// MS2-RANGE: 0x1427ad990-0x1427ada33 .text$mn
// MS2-RANGE: 0x1427b0250-0x1427b027b .text$mn
// MS2-RANGE: 0x1427b0280-0x1427b02ab .text$mn
// MS2-RANGE: 0x1427b08f0-0x1427b0993 .text$mn
// MS2-RANGE: 0x1427b0d10-0x1427b0d35 .text$mn
// MS2-RANGE: 0x1427b0d40-0x1427b0d9f .text$mn
// MS2-RANGE: 0x1427b1070-0x1427b1095 .text$mn
// MS2-RANGE: 0x1427b10a0-0x1427b10ff .text$mn
// MS2-RANGE: 0x1427b36f0-0x1427b3715 .text$mn
// MS2-RANGE: 0x1427b3720-0x1427b377f .text$mn
// MS2-RANGE: 0x1427b3a60-0x1427b3b03 .text$mn
// MS2-RANGE: 0x1427b4610-0x1427b4635 .text$mn
// MS2-RANGE: 0x1427b4640-0x1427b469f .text$mn
// MS2-RANGE: 0x1427b5780-0x1427b57a5 .text$mn
// MS2-FLAGS: gamebryo
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

void operator delete(void* p, size_t size);   // sized operator delete (the CRT's)
extern char DAT_142e1af98[];                // std::ios_base vftable

// @0x1427a54a0
void* FUN_1427a54a0(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        operator delete(base, 0x18);
    return base;
}

// @0x1427aabf0
void* FUN_1427aabf0(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        operator delete(base, 0x18);
    return base;
}

// @0x1427b0d10
void* FUN_1427b0d10(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        operator delete(base, 0x18);
    return base;
}

// @0x1427b1070
void* FUN_1427b1070(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        operator delete(base, 0x18);
    return base;
}

// @0x1427b36f0
void* FUN_1427b36f0(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        operator delete(base, 0x18);
    return base;
}

// @0x1427b4610
void* FUN_1427b4610(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        operator delete(base, 0x18);
    return base;
}

// @0x1427b5780
void* FUN_1427b5780(char* self, unsigned flags)
{
    char* base = self - 0x10;
    if (flags & 1)
        operator delete(base, 0x18);
    return base;
}

// @0x1427b0250
void* FUN_1427b0250(char* self, unsigned flags)
{
    *(void**)self = DAT_142e1af98;
    if (flags & 1)
        operator delete(self, 0x58);
    return self;
}

// @0x1427b0280
void* FUN_1427b0280(char* self, unsigned flags)
{
    *(void**)self = DAT_142e1af98;
    if (flags & 1)
        operator delete(self, 0x58);
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
        operator delete(base, 0x28);
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
        operator delete(base, 0x28);
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
        operator delete(base, 0x28);
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
        operator delete(base, 0x28);
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
        operator delete(base, 0x28);
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
        operator delete(base, 0x28);
    return base;
}

// ostringstream-style object with a virtual base: vptr, vbtable pointer (entry 1 = offset of the virtual base), a state word
// and the virtual base's ios_base vptr at +0x20
struct CefStrmObj
{
    void* volatile vptr;            // +0x00
    void* volatile vbptr;           // +0x08 (vbtable; [1] = virtual base offset)
    volatile int state;             // +0x10
    char pad_14[0xc];
    void* iosVptr;                  // +0x20
};
struct CefVBase
{
    int pad_0;
    int adj;                        // +4
    void* vptr;                     // +8
};
static inline int CefVBaseOff(CefStrmObj* self) { return ((const int*)self->vbptr)[1]; }
static inline CefVBase* CefVBaseAt(CefStrmObj* self, int off) { return (CefVBase*)((char*)self + off); }
static inline CefVBase* CefVBaseOf(CefStrmObj* self) { return CefVBaseAt(self, CefVBaseOff(self)); }

extern char DAT_1431d9618[];
extern char DAT_1431d9568[];
extern char DAT_1431d95a0[];
extern char DAT_1431d6fc8[];
extern char DAT_1431d7000[];
extern char DAT_1431d95c0[];
extern char DAT_1431d95f8[];
// @0x142787270
void* FUN_142787270(CefStrmObj* self, int mostDerived)
{
    if (mostDerived)
    {
        self->vbptr = DAT_1431d9618;
        self->iosVptr = DAT_142e1af98;
    }
    self->vptr = DAT_1431d9568;
    CefVBaseOf(self)->vptr = DAT_1431d95a0;
    self->vptr = DAT_1431d6fc8;
    CefVBaseOf(self)->vptr = DAT_1431d7000;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
    }
    self->state = 0;
    self->vptr = DAT_1431d95c0;
    CefVBaseOf(self)->vptr = DAT_1431d95f8;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
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
void* FUN_14278bcd0(CefStrmObj* self, int mostDerived)
{
    if (mostDerived)
    {
        self->vbptr = DAT_1431da2a8;
        self->iosVptr = DAT_142e1af98;
    }
    self->vptr = DAT_1431da218;
    CefVBaseOf(self)->vptr = DAT_1431da240;
    self->vptr = DAT_1431d75e8;
    CefVBaseOf(self)->vptr = DAT_1431d7610;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
    }
    self->state = 0;
    self->vptr = DAT_1431da260;
    CefVBaseOf(self)->vptr = DAT_1431da288;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
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
void* FUN_1427a9550(CefStrmObj* self, int mostDerived)
{
    if (mostDerived)
    {
        self->vbptr = DAT_1431df490;
        self->iosVptr = DAT_142e1af98;
    }
    self->vptr = DAT_1431df2b0;
    CefVBaseOf(self)->vptr = DAT_1431df380;
    self->vptr = DAT_1431dc138;
    CefVBaseOf(self)->vptr = DAT_1431dc208;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
    }
    self->state = 0;
    self->vptr = DAT_1431df3a0;
    CefVBaseOf(self)->vptr = DAT_1431df470;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
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
void* FUN_1427ad990(CefStrmObj* self, int mostDerived)
{
    if (mostDerived)
    {
        self->vbptr = DAT_1431e03e8;
        self->iosVptr = DAT_142e1af98;
    }
    self->vptr = DAT_1431e0028;
    CefVBaseOf(self)->vptr = DAT_1431e01e8;
    self->vptr = DAT_1431dcf48;
    CefVBaseOf(self)->vptr = DAT_1431dd108;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
    }
    self->state = 0;
    self->vptr = DAT_1431e0208;
    CefVBaseOf(self)->vptr = DAT_1431e03c8;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
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
void* FUN_1427b08f0(CefStrmObj* self, int mostDerived)
{
    if (mostDerived)
    {
        self->vbptr = DAT_1431e09b0;
        self->iosVptr = DAT_142e1af98;
    }
    self->vptr = DAT_1431e0950;
    CefVBaseOf(self)->vptr = DAT_1431e0960;
    self->vptr = DAT_1431de378;
    CefVBaseOf(self)->vptr = DAT_1431de388;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
    }
    self->state = 0;
    self->vptr = DAT_1431e0980;
    CefVBaseOf(self)->vptr = DAT_1431e0990;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
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
void* FUN_1427b3a60(CefStrmObj* self, int mostDerived)
{
    if (mostDerived)
    {
        self->vbptr = DAT_1431e1418;
        self->iosVptr = DAT_142e1af98;
    }
    self->vptr = DAT_1431e1268;
    CefVBaseOf(self)->vptr = DAT_1431e1320;
    self->vptr = DAT_1431df048;
    CefVBaseOf(self)->vptr = DAT_1431df100;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
    }
    self->state = 0;
    self->vptr = DAT_1431e1340;
    CefVBaseOf(self)->vptr = DAT_1431e13f8;
    {
        int off = CefVBaseOff(self);
        CefVBaseAt(self, off)->adj = off - 0x18;
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
