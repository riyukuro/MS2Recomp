// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Critical section guarded reset of a pointer array.
// MS2-UNIT: unit_140de0f70
// MS2-RANGE: 0x140de0f70-0x140de11a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/citem.h"
#include "ms2/ms2recover.h"
#include <atlcoll.h>

extern void FUN_140a6c360(void*);
extern void FUN_1408f3a80(void*);
extern void FUN_1408f3d90(void*, __int64, int);
extern unsigned FUN_140720ca0(void*);
extern void* FUN_140a69ee0(void*, __int64);
extern void FUN_1401bffb0(void*, int);
void FUN_140de1040(struct Unk_De0f70*);
void FUN_140de1070(struct Unk_De0f70*);

struct Unk_De0f70
{
    Unk_De0f70();
    ~Unk_De0f70();

    int m_state;
    int m_reset1;
    __int64 m_reset2;                                 // +0x08
    int m_reset4;
    int m_reset5;
    int m_reset6;
    CLockCriticalSection m_lock;                      // +0x20
    ATL::CRBMap<__int64, MS2Ptr<CItem> > m_serviceStorage;  // +0x50
    CAtlArray<MS2Ptr<CItem> > m_items;                // +0x80
};

// @0x140de0f70
Unk_De0f70::Unk_De0f70() : m_state(0), m_serviceStorage(10)
{
    FUN_140de1040(this);
}

// @0x140de0ff0
Unk_De0f70::~Unk_De0f70()
{
}

// @0x140de1040
void FUN_140de1040(Unk_De0f70* self)
{
    self->m_state = 0x24;
    FUN_140de1070(self);
}

// @0x140de1070
void FUN_140de1070(Unk_De0f70* self)
{
    Unk_LockGuard guard(self->m_lock);
    if (guard.operator int()) {
    } else {
        self->m_reset1 = 0;
        self->m_reset2 = 0;
        self->m_reset4 = 0;
        self->m_reset5 = 0;
        self->m_reset6 = 0;
        FUN_140a6c360(&self->m_serviceStorage);
        FUN_1408f3a80(&self->m_items);
        FUN_1408f3d90(&self->m_items, self->m_state, -1);
        int count = FUN_140720ca0(&self->m_items);
        for (int i = 0; i < count; ++i) {
            FUN_1401bffb0(FUN_140a69ee0(&self->m_items, i), 0);
        }
    }
}
