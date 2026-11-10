// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CMachineIDManager: the TSingleton-derived machine-id holder
// (ctor/dtor, the id builder, two getters) plus the TSingleton<CMachineIDManager> instantiation and the CRT memmove_s
// the unit ends with. See machineidmanager.h.
// MS2-UNIT: ?\machineidmanager.cpp
// MS2-RANGE: 0x140d4fcd0-0x140d50010 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\machineidmanager.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "machineidmanager.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// the singleton classes whose TSingleton<T>::s_instance this unit uses (only the pointer)
class CMachineIDManager;

class Unk_MachineId { public: Unk_MachineId(); };          // C3: member view (unit_14067c020_machineidcodec; 0x14067c020 zero-inits the 16-byte id)

#ifndef MS2_HOOK_DLL
// ms2.cpp calls BuildID through a free declaration (FUN_140d4fd50); define that name here so the relinked exe resolves it.
void FUN_140d4fd50(CMachineIDManager* pManager)
{
    pManager->BuildID();
}
#endif

CMachineIDManager* TSingleton<CMachineIDManager>::s_instance = 0;   // 0x143ab8aa8

// @0x140d4fcd0
CMachineIDManager::CMachineIDManager()
{
    reinterpret_cast<Unk_MachineId*>(&m_id)->Unk_MachineId::Unk_MachineId();
}

// @0x140d4fd20
CMachineIDManager::~CMachineIDManager()
{
}

// @0x140d4fd50
void CMachineIDManager::BuildID()
{
    CSystemInfo local;
    FUN_1423b10a0(&local);
    m_id = *static_cast<Unk_MachineID*>(FUN_1423b1080(&local));
    m_n18 = GetPcBangCode(&local);
}
MS2_REPLACE_METHOD(0x140D4FD50, CMachineIDManager, BuildID, 139, 0xC65EBD09);

// @0x140d4fdf0
Unk_MachineID* CMachineIDManager::GetID()
{
    return &m_id;
}
MS2_REPLACE_METHOD(0x140D4FDF0, CMachineIDManager, GetID, 15, 0x46F5B241);

// @0x140d4fe10
unsigned int CMachineIDManager::GetValue()
{
    return m_n18;
}
MS2_REPLACE_METHOD(0x140D4FE10, CMachineIDManager, GetValue, 14, 0x72E52537);

// @0x140d4fe20
TSingleton<CMachineIDManager>::TSingleton()
{
    s_instance = static_cast<CMachineIDManager*>(this);
}

// @0x140d4fe50
TSingleton<CMachineIDManager>::~TSingleton()
{
    s_instance = 0;
}

// @0x140d4fef0
MS2_EMIT_CRT_MEMMOVE_S();
