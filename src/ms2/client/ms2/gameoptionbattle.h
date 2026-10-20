// gameoptionbattle.h - CGameOptionBattle (RTTI .?AVCGameOptionBattle@@, base CBaseOption, 0x48 bytes): the battle tab.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the methods live in unit `client\ms2\gameoption.cpp`. Header and member names are
// assumed. Built by UIGameOptionDialog's ctor as tab id 4. The state block's ctor is a FUN_ in client\ms2\gameoptionstruct.cpp.
#pragma once
#include "ms2/client/ms2/baseoption.h"

struct Unk_BattleState
{
    union
    {
    bool m_b[6];                                                    // +0x00..+0x05 (default 1)
        struct
        {
            bool m_bDisplayMyGiveRecovery;
            bool m_bDisplayMyTakeRecovery;
            bool m_bDisplayPartyRecovery;
            bool m_bDisplayGetMeso;
            bool m_bDisplayGetExp;
            bool m_bDisplayEpGauge;
        };
    };
    int m_n08;                                                      // +0x08 (default 7)
    int m_n0c;                                                      // +0x0c (default 3)
    int m_n10;                                                      // +0x10 (default 3)
};
MS2_CHECK_SIZE(Unk_BattleState, 0x14);

class CGameOptionBattle : public CBaseOption
{
public:
    CGameOptionBattle(int nId, int nType);                             // 0x141246d40
    virtual ~CGameOptionBattle();                                       // 0x141246da0
    virtual CString vfunc_1();                                      // 0x1412481f0
    virtual void vfunc_3(int n);                                    // 0x141246dd0
    virtual void vfunc_4(int n);                                    // 0x141246e20
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg); // 0x141246e50
    virtual void vfunc_6();                                         // 0x141246e70 write the state into the UI
    virtual void vfunc_7();                                         // 0x141247770 read the state back from the UI
    virtual void vfunc_10();                                        // 0x141248140
    virtual void vfunc_12();                                        // 0x141248190
    virtual int vfunc_14();                                        // 0x141248240 differs from the saved settings

    Unk_BattleState m_state;                                       // +0x30 (ctor 0x14125ca80)
};
MS2_CHECK_SIZE(CGameOptionBattle, 0x48);
