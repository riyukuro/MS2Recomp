// Nexon Messenger path getter recovered from unit_1415c2f20.
// MS2-UNIT: unit_1415c2f20
// MS2-RANGE: 0x1415c2f20-0x1415c30d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include <cstring>
#include <strsafe.h>

extern void FUN_1415fbe70(void* dst, unsigned int capacity, const void* src);

// MS2-FUNCTIONAL: performs the recovered CNM path request and returns null on failure.
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
// MS2-PIN: ?FUN_1415c2f20@@YAPEADPEAD@Z 0x1415c2f20


// MS2-FUNCTIONAL: appends the recovered banner directory suffix through the executable's StringCchCat helper.
// @0x1415c2ff0
char* FUN_1415c2ff0(char* path)
{
    FUN_1415c2f20(path);
    StringCchCatA(path, 0x104, "\\Banner");
    return path;
}

// MS2-FUNCTIONAL: builds the recovered banner file path; the appended separator and URL basename match the decompilation.
// @0x1415c3030
char* FUN_1415c3030(char* url, char* path, void*, void*)
{
    FUN_1415c2ff0(path);
    StringCchCatA(path, 0x104, "\\");
    const char* basename = std::strrchr(url, '/');
    StringCchCatA(path, 0x104, basename ? basename + 1 : url);
    return path;
}
