// CQuestManagerCommon: quest-condition interface, vftable 0x142f573c0.
// Recovered slot order; names use the secondary-base names in CQuestManager.
// Constructor 0x1416dbb50 initializes the selector at +8, so size is 0x10.
#pragma once
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
class CQuest;
class Unk_QuestCondition;
class CQuest;
class CQuestManagerCommon {
public:
    CQuestManagerCommon();
    virtual int vfunc_o10_0(int, int) = 0;
    virtual int vfunc_o10_1(int) = 0;
    virtual int vfunc_o10_2(int) = 0;
    virtual Unk_PayloadPtr<CQuest> vfunc_o10_3(int) = 0;
    virtual int vfunc_o10_4() = 0;
    virtual int vfunc_o10_5() = 0;
    virtual int vfunc_o10_6() = 0;
    virtual int vfunc_o10_7() = 0;
    virtual __int64 vfunc_o10_8() = 0;
    virtual int vfunc_o10_9() = 0;
    virtual int vfunc_o10_10() = 0;
    virtual int vfunc_o10_11() = 0;
    virtual __int64 vfunc_o10_12() = 0;
    virtual int vfunc_o10_13(int) = 0;
    virtual int vfunc_o10_14(int) = 0;
    virtual int vfunc_o10_15(int) = 0;
    virtual int vfunc_o10_16(int) = 0;
    virtual int vfunc_o10_17(int) = 0;
    virtual int vfunc_o10_18() = 0;
    virtual int vfunc_o10_19() = 0;
    virtual int vfunc_o10_20(const ATL::CAtlArray<unsigned>&) = 0;
    virtual int vfunc_o10_21(int, int, int);
    virtual __int64 vfunc_o10_22() = 0;
    virtual unsigned vfunc_o10_23(const Unk_QuestCondition&);
    int FUN_140745590(int questId);     // 0x140745590
    int FUN_140745630(int questId);     // 0x140745630
    int FUN_140746850(int questId, int npcId, int);    // 0x140746850
    int FUN_140746ba0(int questId, int npcId, bool bSkip);    // 0x140746ba0
    int FUN_140746e60(int questId);     // 0x140746e60
    int FUN_1407456d0(int questId);     // 0x1407456d0 quest is complete
    bool FUN_140745770(int questId);    // 0x140745770
    int FUN_140745820(int questId, int flag);   // 0x140745820 the quest can be accepted
    int FUN_140747000(int questId);     // 0x140747000 the quest group's pick seed
    bool FUN_140747350(int questId);    // 0x140747350
    bool FUN_140747400(int questId, int nKind);   // 0x140747400
    bool FUN_140747440(int questId, int nValue);  // 0x140747440
    int m_selector;
};
MS2_CHECK_SIZE(CQuestManagerCommon, 0x10);
MS2_CHECK_OFFSET(CQuestManagerCommon, m_selector, 8);
