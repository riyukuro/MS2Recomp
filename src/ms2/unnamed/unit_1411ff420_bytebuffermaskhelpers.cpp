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
// The exe's `xor eax,eax; cmp eax,6; je; jmp` is a constant-true condition (6) with an empty then: /Od tests the
// value against 0 and jumps over the never-taken else.
void FUN_1411ff480(unsigned char* p)
{
    if (6) {
    } else {
        p[0] = p[0] & 0x3f;
    }
}
