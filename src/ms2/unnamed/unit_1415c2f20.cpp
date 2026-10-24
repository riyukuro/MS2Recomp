// Nexon Messenger path getter recovered from unit_1415c2f20.
// MS2-UNIT: unit_1415c2f20
// MS2-RANGE: 0x1415c2f20-0x1415c30d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"

extern void FUN_1415fbe70(void* dst, unsigned int capacity, const void* src);

// @0x1415c2f20
char* FUN_1415c2f20(char* path)
{
    CNMGetPathFunc request(2);
    if (!CNMManager::GetInstance()->CallNMFunc(&request)) {
        *path = 0;
        return nullptr;
    }
    FUN_1415fbe70(path, 0x104, request.m_34);
    return path;
}
// MS2-FUNCTIONAL: performs the recovered CNM path request and returns null on failure.
// MS2-PIN: ?FUN_1415c2f20@@YAPEADPEAD@Z 0x1415c2f20
