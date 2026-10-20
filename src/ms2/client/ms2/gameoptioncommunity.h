// gameoptioncommunity.h - CGameOptionCommunity (RTTI .?AVCGameOptionCommunity@@, base CBaseOption, 0x40 bytes): the community tab.
// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); the methods live in unit `client\ms2\gameoption.cpp`. Header and member names are
// assumed. Built by UIGameOptionDialog's ctor as tab id 5. The state block's ctor is a FUN_ in client\ms2\gameoptionstruct.cpp.
#pragma once
#include "ms2/client/ms2/baseoption.h"

struct Unk_CommunityStateA
{
    union
    {
    bool m_b[3];                                                    // +0x00 (default 1,1,0)
        struct
        {
            bool m_bDisplayMyChatBalloon;
            bool m_bDisplayOtherChatBalloon;
            bool m_bDisableSingleRiding;
        };
    };
};
MS2_CHECK_SIZE(Unk_CommunityStateA, 0x3);

struct Unk_CommunityStateB
{
    union
    {
    bool m_b[0xc];                                                  // +0x00 (default 1,1,1 then 0; bytes 0..10 set by the ctor)
        struct
        {
            bool m_bDisplayChatComfirmSuper;
            bool m_bDisplayChatComfirmWorld;
            bool m_bDisplayChatComfirmChannel;
            bool m_bDisablePartyRequest;
            bool m_bDisableBuddyRequest;
            bool m_bDisableGuildRequest;
            bool m_bDisableGroupRequest;
            bool m_bDisableWhisperNotify;
            bool m_bDisableTradeRequest;
            bool m_bDisableHomeRequest;
            bool m_bDisableCouplemotionRequest;
        };
    };
};
MS2_CHECK_SIZE(Unk_CommunityStateB, 0xc);

class CGameOptionCommunity : public CBaseOption
{
public:
    CGameOptionCommunity(int nId, int nType);                          // 0x1412492f0
    virtual ~CGameOptionCommunity();                                    // 0x141249370
    virtual CString vfunc_1();                                      // 0x14124aa20
    virtual void vfunc_3(int n);                                    // 0x1412493a0
    virtual void vfunc_4(int n);                                    // 0x141249410
    virtual int vfunc_5(const char* pszName, void* pArg, int nArg); // 0x141249440
    virtual void vfunc_6();                                         // 0x141249460 write the state into the UI
    virtual void vfunc_7();                                         // 0x141249e50 read the state back from the UI
    virtual void vfunc_10();                                        // 0x14124a8d0
    virtual void vfunc_12();                                        // 0x14124a990
    virtual int vfunc_14();                                        // 0x14124aa70 differs from the saved settings

    Unk_CommunityStateA m_stateA;                                  // +0x30 (ctor 0x14125d130)
    Unk_CommunityStateB m_stateB;                                  // +0x33 (ctor 0x14125d330)
};
MS2_CHECK_SIZE(CGameOptionCommunity, 0x40);
