// Recovered UITimeRunEventDialog (UI type 0x4f43 "TimeRunEventDialog"): the time-run event board. A TimeRunEventContext
// (the GameEventTimeRunEvent state kept by CGameRule) holds one quest per opening day plus a distance-reward table; the
// dialog shows the day tabs, the quests of the selected day, the distance rewards and the final reward. RTTI vftables:
// dialog at +0, IMessageListener at +0x18, UIQuestEventListener at +0x178. File name assumed (the class name).
// Unnamed helpers and members use invented names.
#pragma once
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uiquesteventlistener.h"        // UIQuestEventListener (13 slots), Unk_DTTick
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/commonfiles/gameevent.h"                  // TimeRunEventContext

class ASTextField;
class Unk_TrList;
class Unk_TrTab;
class UITimeRunEventDialog : public UIDialog, public UIQuestEventListener
{
public:
    UITimeRunEventDialog();                                                 // 0x140ee2190
    virtual ~UITimeRunEventDialog();                                        //  0 0x140ee2330 (??_G 0x140ee5170)
    virtual CString GetTypeName();                                              //  1 0x140ee23c0
    virtual int vfunc_65();                                                 // 65 0x140ee2410
    virtual void vfunc_67();                                                // 67 0x140ee2470
    virtual void OnLoadComplete();                                          // 22 0x140ee24d0
    virtual int vfunc_13();                                                 // 13 0x140ee26d0
    virtual void vfunc_15();                                                // 15 0x140ee3100
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);   // 45 0x140ee26f0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ee2b30
    virtual void vfunc_o178_10(void* pQuest);                               // 0x140ee2f20 quest progress
    virtual int vfunc_48() { return 0x4f43; }                               // 48 (COMDAT 0x140ee51c0)

    void FUN_140ee3580();                                                   // setMapData / setRewardData / setFinalReward
    void FUN_140ee3c00(int nDay);                                           // fill "m_list" with the quests of a day
    int FUN_140ee4280(MS2Ptr<TimeRunEventContext> spContext);               // distance earned by the rewarded quests
    CStringW FUN_140ee4380(MS2Ptr<TimeRunEventContext> spContext);          // time left of the first quest
    void FUN_140ee4570(int n);                                                 // refresh and open the reward dialog
    __int64 FUN_140ee4990(MS2Ptr<TimeRunEventContext> spContext);           // start time of the first quest
    int FUN_140ee4b00();                                                    // selected day tab + 1, -1 when unbound
    int FUN_140ee4bb0(MS2Ptr<TimeRunEventContext> spContext);               // elapsed days, at most 6
    void FUN_140ee4ca0();                                                   // setTabCount per day
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);              // text field child lookup
    MS2Ptr<Unk_TrList> FUN_140c02900(const CString& strName);               // list child lookup
    MS2Ptr<Unk_TrTab> FUN_140c02870(const CString& strName);                // tab strip child lookup

private:
    MS2_LAYOUT_FRIEND;
    ItemSlotBinder m_missionBinder;                                         // +0x180 "<name>_mission"
    ItemSlotBinder m_mapBinder;                                             // +0x1c0 "<name>_map"
    Unk_DTTick m_tick;                                                      // +0x200 1 s refresh timer
public:
    int FUN_140ee3290();                                    // 0x140ee3290 as bound by the game menu table (ClassFunHandler RTTI)
};
MS2_CHECK_SIZE(UITimeRunEventDialog, 0x208);
MS2_CHECK_OFFSET(UITimeRunEventDialog, m_missionBinder, 0x180);
MS2_CHECK_OFFSET(UITimeRunEventDialog, m_mapBinder, 0x1c0);
MS2_CHECK_OFFSET(UITimeRunEventDialog, m_tick, 0x200);

// Free helpers of the unit (no `this`).
int FUN_140ee3290();                                                        // a reward is waiting
int FUN_140ee45c0();                                                        // number of claimable steps
