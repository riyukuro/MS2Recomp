// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Sets a global flag to true.
// MS2-UNIT: unit_1408273f0
// MS2-RANGE: 0x1408273f0-0x140827420 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

extern bool DAT_143ab1b14;

void FUN_140827410(bool value);

// @0x1408273f0
bool FUN_1408273f0(void* /*unused*/)
{
    FUN_140827410(true);
    return true;
}

// @0x140827410
void FUN_140827410(bool value)
{
    DAT_143ab1b14 = value;
}
