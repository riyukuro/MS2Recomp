// machineidmanager.h - CMachineIDManager (RTTI .?AVCMachineIDManager@@, 0x20 bytes, base
// TSingleton<class CMachineIDManager> at +0): the process-wide machine-id holder (a 16-byte id at +0x8 and a 32-bit
// value at +0x18). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the unit is `?\machineidmanager.cpp`
// (0x140d4fcd0-0x140d50010 .text$mn). Header name assumed; member and method names invented.
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"     // TSingleton

class CMachineIDManager;

// This instantiation stores the complete object pointer (exe DAT_143ab8aa8).
template <> class TSingleton<CMachineIDManager>
{
public:
    TSingleton();                                       // 0x140d4fe20
    virtual ~TSingleton();                              // 0x140d4fe50 (??_G 0x140d4fe70)
    static CMachineIDManager* s_instance;               // 0x143ab8aa8
    static CMachineIDManager* GetInstance() { return s_instance; }
};

// The 16-byte machine id filled by BuildID.
struct Unk_MachineID
{
    unsigned __int64 m_lo;
    unsigned __int64 m_hi;
};
MS2_CHECK_SIZE(Unk_MachineID, 0x10);

// The 40-byte working object BuildID passes to the id helpers (unit_1423ae840_cxsupportid.cpp); RTTI .?AVCSystemInfo@@.
class CSystemInfo
{
public:
    CSystemInfo();                                      // 0x1423ae7f0
    virtual ~CSystemInfo();                             // 0x1423ae800 (vftable 0x143135128)
    unsigned char m_data[0x20];                         // +8: support id, +0x18: hardware id
};
MS2_CHECK_SIZE(CSystemInfo, 0x28);

void FUN_1423b10a0(CSystemInfo* pLocal);         // fills the hardware and support ids
void* FUN_1423b1080(CSystemInfo* pLocal);        // the id buffer inside the working object
unsigned int GetPcBangCode(CSystemInfo* pLocal); // the PC-bang code, 0 if none

class CMachineIDManager : public TSingleton<CMachineIDManager>
{
public:
    CMachineIDManager();                                // 0x140d4fcd0
    virtual ~CMachineIDManager();                       // 0x140d4fd20 (??_G 0x140d4feb0)
    void BuildID();                                     // 0x140d4fd50
    Unk_MachineID* GetID();                             // 0x140d4fdf0: &m_id
    unsigned int GetValue();                            // 0x140d4fe10: m_n18

    Unk_MachineID m_id;                                 // +0x08
    unsigned int m_n18;                                 // +0x18
};
MS2_CHECK_SIZE(CMachineIDManager, 0x20);
MS2_CHECK_OFFSET(CMachineIDManager, m_id, 0x08);
MS2_CHECK_OFFSET(CMachineIDManager, m_n18, 0x18);
