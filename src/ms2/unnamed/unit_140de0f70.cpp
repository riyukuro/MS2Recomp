// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Critical section guarded reset of a pointer array.
// MS2-UNIT: unit_140de0f70
// MS2-RANGE: 0x140de0f70-0x140de11a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/ms2recover.h"
#include <atlcoll.h>

extern void FUN_140a698a0(void*, int, void*, void*, unsigned __int64);
extern void FUN_140a69d20(void*);
extern void FUN_140a6c360(void*);
extern void FUN_1408f3a80(void*);
extern void FUN_1408f3d90(void*, __int64, int);
extern unsigned FUN_140720ca0(void*);
extern void* FUN_140a69ee0(void*, unsigned);
extern void FUN_1401bffb0(void*, int);
void FUN_140de1040(struct Unk_De0f70*);
void FUN_140de1070(struct Unk_De0f70*);

struct Unk_De0f70
{
    int m_state;
    int m_reset1;
    int m_reset2;
    int m_reset3;
    int m_reset4;
    int m_reset5;
    int m_reset6;
    CLockCriticalSection m_lock;
    char m_serviceStorage[0x30];
    CAtlArray<void*> m_items;
};

// @0x140de0f70
Unk_De0f70* FUN_140de0f70(Unk_De0f70* self, void*, void* p3, void* p4)
{
    self->m_state = 0;
    new (&self->m_lock) CLockCriticalSection;
    FUN_140a698a0(&self->m_serviceStorage, 10, p3, p4, ~static_cast<unsigned __int64>(1));
    new (&self->m_items) CAtlArray<void*>;
    FUN_140de1040(self);
    return self;
}

// @0x140de0ff0 (the ctor's object: m_items +0x80, m_serviceStorage +0x50, m_lock +0x20)
void FUN_140de0ff0(Unk_De0f70* self)
{
    self->m_items.~CAtlArray<void*>();
    FUN_140a69d20(&self->m_serviceStorage);
    self->m_lock.~CLockCriticalSection();
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
    if (guard.operator int() == 0) {
        self->m_reset1 = 0;
        self->m_reset2 = 0;
        self->m_reset3 = 0;
        self->m_reset4 = 0;
        self->m_reset5 = 0;
        self->m_reset6 = 0;
        FUN_140a6c360(&self->m_serviceStorage);
        FUN_1408f3a80(&self->m_items);
        FUN_1408f3d90(&self->m_items, self->m_state, -1);
        unsigned count = FUN_140720ca0(&self->m_items);
        for (unsigned i = 0; i < count; ++i) {
            FUN_1401bffb0(FUN_140a69ee0(&self->m_items, i), 0);
        }
    }
}
