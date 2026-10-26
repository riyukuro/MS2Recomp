// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Two byte-buffer helpers: the first stamps a value at
// offset 0 of the buffer and, for a non-zero value, runs the mask pass; the second is a compiler-shaped no-op that
// masks the first byte with 0x3f only on a compile-time-false branch (dead code kept by /Od).
// MS2-UNIT: unit_1411ff420
// MS2-RANGE: 0x1411ff420-0x1411ff4c0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

extern void FUN_1411ff480(unsigned char* p);

// @0x1411ff420
void FUN_1411ff420(unsigned char* p, unsigned char c)
{
    for (int i = 0; i >= 0; i = i + -1) {
        p[i] = c;
    }
    if (c != '\0') {
        FUN_1411ff480(p);
    }
}

// @0x1411ff480
// MS2-FUNCTIONAL: the exe compares a constant 0 against 6 (`xor eax,eax; cmp eax,6; je`), an always-false branch its
// /Od build did not fold; cl folds the same source to `test eax,eax`. The branch is never taken either way, so the
// emitted behaviour is identical.
void FUN_1411ff480(unsigned char* p)
{
    if (0 == 6) {
        p[0] = p[0] & 0x3f;
    }
}
