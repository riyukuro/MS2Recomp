// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Critical section guarded reset of a pointer array.
// MS2-UNIT: unit_140de0f70
// MS2-RANGE: 0x140de0f70-0x140de11a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/citem.h"
#include "ms2/ms2recover.h"
#include <atlcoll.h>
#include "ms2/client/ms2/store.h"

extern void FUN_1408f3d90(void*, __int64, int);
extern unsigned FUN_140720ca0(void*);
extern void* FUN_140a69ee0(void*, __int64);
extern void FUN_1401bffb0(void*, int);

// CStore (store.h), the store table's class: its ctor, dtor, Initialize and Clear sit here, before store.cpp.

// @0x140de0f70
CStore::CStore() : m_capacity(0), m_items(10)
{
    Initialize();
}

// @0x140de0ff0
CStore::~CStore()
{
}

// @0x140de1040
void CStore::Initialize()
{
    m_capacity = 0x24;
    Clear();
}

// @0x140de1070
void CStore::Clear()
{
    Unk_LockGuard guard(m_lock);
    if (guard.operator int()) {
    } else {
        m_extended = 0;
        m_id = 0;
        m_type = 0;
        m_ready = 0;
        m_received = 0;
        ((ATL::CRBTree<unsigned __int64, MS2Ptr<CItem>, ATL::CElementTraits<unsigned __int64>, ATL::CElementTraits<MS2Ptr<CItem>>>*)(void*)(&m_items))->RemoveAll();
        ((ATL::CAtlArray<MS2Ptr<CItem>, ATL::CElementTraits<MS2Ptr<CItem>>>*)(void*)(&m_slots))->RemoveAll();
        FUN_1408f3d90(&m_slots, m_capacity, -1);
        int count = FUN_140720ca0(&m_slots);
        for (int i = 0; i < count; ++i) {
            FUN_1401bffb0(FUN_140a69ee0(&m_slots, i), 0);
        }
    }
}
