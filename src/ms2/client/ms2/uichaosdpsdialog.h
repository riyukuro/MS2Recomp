// Recovered UIChaosDPSDialog (the chaos-raid damage meter: ranks the party by CBattleRecordManager values).
// Unnamed helpers and members use invented names.
#pragma once
#include <vector>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/cpartymember.h"
#include "ms2/placeholder/ascript.h"

class ASObj;

// 8-byte millisecond poll timer (ctor 0x140517b00, arm 0x140268840, "interval elapsed" test 0x140268870 re-arms).
struct Unk_ChaosTick
{
    Unk_ChaosTick();                        // 0x140517b00
    void FUN_140268840();                   // arm (m_nLastTick = now)
    int FUN_140268870(unsigned nInterval);  // true once the interval elapsed
    unsigned m_nInterval;                   // +0
    unsigned m_nLastTick;                   // +4
};
MS2_CHECK_SIZE(Unk_ChaosTick, 8);

class UIChaosDPSDialog : public UIDialog
{
public:
    UIChaosDPSDialog();                                                     // 0x140e05460
    virtual ~UIChaosDPSDialog();                                            //  0 0x140e05510
    virtual CString vfunc_1();                                              //  1 0x140e05560
    virtual void OnLoadComplete();                                          // 22 0x140e06020
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x140e06080
    virtual int vfunc_48() { return 0x4f23; }                               // 48 0x140e09160
    virtual void vfunc_67();                                                // 67 0x140e06000
    virtual void vfunc_72();                                                // 72 0x140e06630

    bool FUN_140e055b0(ASObj& obj, CPartyMember* pMember, unsigned nRank);  // 0x140e055b0 fill one meter row
    void OnTextToggle();                                                   // 0x140e057d0 title bar and sort direction
    void FUN_140e05950();                                                   // 0x140e05950 rebuild the ranking
    void FUN_140e05f80();                                                   // 0x140e05f80 RemoveMember

    Unk_ChaosTick m_tick;                                                   // +0x178
    std::vector<MS2Ptr<CPartyMember> > m_members;                           // +0x180 the ranking
    int m_nGroup;                                                           // +0x198 battle record group
    int m_nMode;                                                            // +0x19c value kind shown
};
MS2_CHECK_SIZE(UIChaosDPSDialog, 0x1a0);
MS2_CHECK_OFFSET(UIChaosDPSDialog, m_tick, 0x178);
MS2_CHECK_OFFSET(UIChaosDPSDialog, m_members, 0x180);
MS2_CHECK_OFFSET(UIChaosDPSDialog, m_nMode, 0x19c);
