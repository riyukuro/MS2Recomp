// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The game's PhysX allocator (CRT malloc/realloc/free).
// MS2-UNIT: ?\ms2physxallocator.cpp
// MS2-RANGE: 0x1414d6c20-0x1414d6fa0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2physxallocator.cpp"
#include <stdlib.h>
#include <new>
#include "ms2physxallocator.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// Process-fatal error handler (shows the out-of-memory message and exits); out-of-unit.
int FUN_141b6db40(size_t nSize);

// @0x1414d6c20
MS2PhysXAllocator::MS2PhysXAllocator()
{
}

// @0x1414d6c60
MS2PhysXAllocator::~MS2PhysXAllocator()
{
}

// @0x1414d6c90
void* MS2PhysXAllocator::malloc(size_t size)
{
    void* result = NULL;
    try
    {
        result = ::malloc(size);
    }
    catch (std::bad_alloc& e)
    {
        e.what();
        FUN_141b6db40(1);
    }
    return result;
}

// @0x1414d6ce0
void* MS2PhysXAllocator::malloc(size_t size, NxMemoryType type)
{
    void* result = NULL;
    try
    {
        result = ::malloc(size);
    }
    catch (std::bad_alloc& e)
    {
        e.what();
        FUN_141b6db40(1);
    }
    return result;
}

// @0x1414d6d30
void* MS2PhysXAllocator::mallocDEBUG(size_t size, const char* fileName, int line)
{
    void* result = NULL;
    try
    {
        result = ::malloc(size);
    }
    catch (std::bad_alloc& e)
    {
        e.what();
        FUN_141b6db40(1);
    }
    return result;
}

// @0x1414d6d80
void* MS2PhysXAllocator::mallocDEBUG(size_t size, const char* fileName, int line, const char* className, NxMemoryType type)
{
    void* result = NULL;
    try
    {
        result = ::malloc(size);
    }
    catch (std::bad_alloc& e)
    {
        e.what();
        FUN_141b6db40(1);
    }
    return result;
}

// @0x1414d6dd0
void* MS2PhysXAllocator::realloc(void* memory, size_t size)
{
    void* result = NULL;
    try
    {
        result = ::realloc(memory, size);
    }
    catch (std::bad_alloc& e)
    {
        e.what();
        FUN_141b6db40(1);
    }
    return result;
}
MS2_REPLACE_METHOD(0x1414D6DD0, MS2PhysXAllocator, realloc, 70, 0x960C9162);

// @0x1414d6e20
void MS2PhysXAllocator::free(void* memory)
{
    ::free(memory);
}
MS2_REPLACE_METHOD(0x1414D6E20, MS2PhysXAllocator, free, 30, 0xC6F0FC13);
