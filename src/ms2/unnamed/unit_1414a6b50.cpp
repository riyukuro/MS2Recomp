// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Four small helpers: the AddRef/AddRefImpl pair of a smart pointer
// (m_p at +8) over a CPtred-derived type the exe does not name from this range, and two one-line forwarders.
// MS2-UNIT: unit_1414a6b50
// MS2-RANGE: 0x1414a6b50-0x1414a6be0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"

void FUN_140d4db40(void* p);
void FUN_140ad85f0(void* p, int a, int b);

struct Unk_1414a6b50Ptr
{
    void* pad_00;
    void* m_p;

    void AddRef() const;
    void AddRefImpl(void*) const;
};

// @0x1414a6b50
void Unk_1414a6b50Ptr::AddRef() const
{
    if (m_p)
        AddRefImpl(0);
}

// @0x1414a6b80
void Unk_1414a6b50Ptr::AddRefImpl(void*) const
{
    FUN_140d4db40(m_p);
}

// @0x1414a6bb0
int Unk_1414a6b50Free_Kind() { return 3; }

// @0x1414a6bc0
void Unk_1414a6bc0(void* p)
{
    FUN_140ad85f0(p, 0, 0);
}
