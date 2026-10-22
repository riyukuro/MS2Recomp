// gameoptionstatus.h - CGameOptionStatus (RTTI .?AVCGameOptionStatus@@, base CBaseOption, 0x50 bytes): the status tab.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the methods live in unit `client\ms2\gameoptionstruct.cpp`. Header and member names are
// assumed. Built by UIGameOptionDialog's ctor as tab id 3. State-block ctors are FUN_s in client\ms2\gameoptionstruct.cpp.
#pragma once
#include "ms2/client/ms2/baseoption.h"

struct Unk_StatusState
{
    union
    {
    bool m_b[0x16];                                                 // +0x00..+0x15 (mostly default 1; +5,+9,+0xa,+0xc,+0xe,+0x12..+0x15 default 0; +6 = FUN_14036e4c0(FUN_140166410()))
        struct
        {
            bool m_bDisplayMyName;                                  // +0x00 "DisplayMyName"
            bool m_bDisplayPlayerSymbol;                            // +0x01 "DisplayPlayerSymbol"
            bool m_bDisplayFriendlyName;                            // +0x02 "DisplayFriendlyName"
            bool m_bDisplayEnemyName;                               // +0x03 "DisplayEnemyName"
            bool m_bDisplayNpcName;                                 // +0x04 "DisplayNpcName"
            bool m_bDisplayMonsterName;                             // +0x05 "DisplayMonsterName"
            bool m_bDisplayPcIllust;                                // +0x06 "DisplayPcIllust"
            bool m_bDisplayMonsterGaugeValue;                       // +0x07 "DisplayMonsterGaugeValue"
            bool m_bDisplayExpValue;                                // +0x08 "DisplayExpValue"
            bool m_bDisplayOnlyMyEffectToMonster;                   // +0x09 "DisplayOnlyMyEffectToMonster"
            bool m_bDisplayMyHpGauge;                               // +0x0a "DisplayMyHpGauge"
            bool m_bDisplayMyShieldGauge;                           // +0x0b "DisplayMyShieldGauge"
            bool m_bDisplayPartyHpGauge;                            // +0x0c "DisplayPartyHpGauge"
            bool m_bDisplayPartyShieldGauge;                        // +0x0d "DisplayPartyShieldGauge"
            bool m_bDisplayMonsterHpGauge;                          // +0x0e "DisplayMonsterHpGauge"
            bool m_bDisplayNormalChatBalloon;                       // +0x0f "DisplayNormalChatBalloon"
            bool m_bDisplayPartyChatBalloon;                        // +0x10 "DisplayPartyChatBalloon"
            bool m_bDisplayGuildChatBalloon;                        // +0x11 "DisplayGuildChatBalloon"
            bool m_bDisplayShowOnlyMyPet;                           // +0x12 "DisplayShowOnlyMyPet"
            bool m_bDisplayHideMyPet;                               // +0x13 "DisplayHideMyPet"
            bool m_bDisplayHideSmartPush;                           // +0x14 "DisplayHideSmartPush"
            bool m_bDisplayHideHighlightMenu;                       // +0x15 "DisplayHideHighlightMenu"
        };
    };
    short m_pad16;
    int m_n18;                                                      // +0x18 (default 0)
};
MS2_CHECK_SIZE(Unk_StatusState, 0x1c);

struct Unk_StatusFlag
{
    bool m_b;                                                       // +0x00 (default 0)
};

class CGameOptionStatus : public CBaseOption
{
public:
    CGameOptionStatus(int nId, int nType);                        // 0x1412589a0
    virtual ~CGameOptionStatus();                             // 0x141258a20
    virtual CString GetTypeName();                                     // 0x14125b060
    virtual void vfunc_3(int n);                                   // 0x141258a50
    virtual void vfunc_4(int n);                                   // 0x141258ac0
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg);// 0x141258af0
    virtual void vfunc_6();                                        // 0x141258b10
    virtual void vfunc_7();                                        // 0x141259c40
    virtual void vfunc_10();                                       // 0x14125ae50
    virtual void vfunc_12();                                       // 0x14125afe0
    virtual int vfunc_14();                                       // 0x14125b0b0
    void FUN_14125b130(bool b);                                    // 0x14125b130 "show only my pet" changed (empty)
    void FUN_14125b140(bool b);                                    // 0x14125b140 "hide my pet" changed (empty)

    Unk_StatusState m_state;                                        // +0x30 (ctor 0x14125bda0)
    Unk_StatusFlag m_flag;                                          // +0x4c (ctor 0x14125c880)
};
MS2_CHECK_SIZE(CGameOptionStatus, 0x50);
