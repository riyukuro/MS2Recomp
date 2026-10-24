// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Dereferencing accessor and its discarding wrapper.
// MS2-UNIT: unit_1408665a0
// MS2-RANGE: 0x1408665a0-0x1408665e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

void** FUN_140864d80(void* node);
void* FUN_1408665a0(void* node);

// @0x1408665a0
void* FUN_1408665a0(void* node)
{
    return *FUN_140864d80(node);
}

// MS2-FUNCTIONAL: exe reloads the argument through rax (mov rax,[arg]; mov rcx,rax); no source form found
// @0x1408665c0
void FUN_1408665c0(void* node)
{
    FUN_1408665a0(node);
}
