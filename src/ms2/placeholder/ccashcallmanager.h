// ccashcallmanager.h - CCashCallManager (RTTI .?AVCCashCallManager@@, 0x8 bytes). NOT an original header (name from the
// RTTI, unit ?\cashcallmanager.cpp, 0x140b03040-0x140b04a50). Bases: TSingleton<CCashCallManager> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; it checks whether the local player may call a cash
// vehicle (air taxi / helicopter / bank, state 0x2a) or recall (state 0x2c) and starts the state, or the matching
// RideOffAction when the player is riding. Every Request* shows a notice (FUN_140d73bc0 ids 0x94-0x9f, 0xb57-0xb5f) and
// returns 0 when refused. Names invented from use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"

class CCashCallManager : public TSingleton<CCashCallManager>
{
public:
    CCashCallManager();                                     // 0x140b03040
    virtual ~CCashCallManager();                            // 0x140b03080
    int FUN_140b030b0(int nCallType);                       // 0x140b030b0 meso / cash air taxi (type 1, 2, 3)
    int FUN_140b03590(__int64 nItemUid);                    // 0x140b03590 helicopter (type 5)
    int FUN_140b03980(__int64 nItemUid);                    // 0x140b03980 bank (type 4)
    int FUN_140b03d70(__int64 nItemUid);                    // 0x140b03d70 type 6
    int CanRecall(int nCount);                          // 0x140b040a0 the player may recall (checks only)
    int FUN_140b04430(__int64 nTarget, int nCount);         // 0x140b04430 start the recall state 0x2c
};
MS2_CHECK_SIZE(CCashCallManager, 0x8);
