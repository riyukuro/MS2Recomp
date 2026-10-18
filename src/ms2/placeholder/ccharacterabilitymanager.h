// ccharacterabilitymanager.h - PLACEHOLDER for CCharacterAbilityManager (RTTI .?AVCCharacterAbilityManager@@, 0x48 bytes). NOT an original header.
// Bases: TSingleton<CCharacterAbilityManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. It keeps the ids of the learned abilities, the time of the
// last reset and the points (uicharacterabilitydialog.cpp, packet 0xdf).
#pragma once

#include <afx.h>
#include <atltime.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/abilitytable.h"

class CInPacket;

class CCharacterAbilityManager : public TSingleton<CCharacterAbilityManager>
{
public:
    CCharacterAbilityManager();                             // 0x140f29a20
    virtual ~CCharacterAbilityManager();                    //  0 0x140f29a90
    void FUN_140f29ad0(CInPacket& packet);                  // packet 0xdf: 0 all abilities, 1 nothing, 2 one learned
    void FUN_140f29b70(CInPacket& packet);                  // mode 0: the learned ids, the reset time, the points
    void FUN_140f29cc0(CInPacket& packet);                  // mode 2: one ability learned
    void FUN_140f29de0();                                   // mode 1: empty
    int FUN_140f29e00();                                    // the points left
    unsigned FUN_140f29e40();                               // the points of the level
    ATL::CTimeSpan FUN_140f29ea0();                         // the time left until the next reset
    int FUN_140f29f90(MS2Ptr<Unk_CaAbilityRow> ref);        // the ability can be learned now (by value: callee destroys)
    int FUN_140f2a0b0(int nId);                             // learned
    int FUN_140f2a100(int nId);                             // the level is too low
    int FUN_140f2a210();                                    // something is learned
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlList<unsigned> m_abilities;                    // +0x08 learned ability ids
    __int64 m_nResetTime;                                   // +0x38
    int m_nPoints;                                          // +0x40
    int m_pad_44;
};
MS2_CHECK_SIZE(CCharacterAbilityManager, 0x48);
