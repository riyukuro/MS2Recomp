// cmasterymanager.h - PLACEHOLDER for CMasteryManager (RTTI .?AVCMasteryManager@@, 0x8 bytes). NOT an original header.
// Bases: TSingleton<CMasteryManager> at +0x0. A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; the
// members (recovered in ?\masterymanager.cpp, names invented from their use) check the mastery learning rules.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

enum Unk_MasteryResult : int {};    // 0 = ok, 1 lack mastery, 2 lack meso, 3 lack quest, 4 lack item, 5 unknown, 7 invalid level, 0xc

class CMasteryManager : public TSingleton<CMasteryManager>
{
public:
    CMasteryManager();                                      // 0x140b6d070
    virtual ~CMasteryManager();                             // 0x140b6d0b0

    int GetTotalClaimableRewardLevels();                                    // total number of learnable steps over the 12 mastery types
    int CountClaimableRewardLevels(int nType);                           // learnable steps of one mastery type
    int HasRewards(int nType, int nLevel);              // the step has a reward
    int FUN_140b6d330(int nStep);                           // a quest requirement of the step is met
    Unk_MasteryResult FUN_140b6d470(int nStep);             // why the step cannot be learned (0 = can)
    void FUN_140b6d710(Unk_MasteryResult eResult);          // show the error text
};
MS2_CHECK_SIZE(CMasteryManager, 0x8);
