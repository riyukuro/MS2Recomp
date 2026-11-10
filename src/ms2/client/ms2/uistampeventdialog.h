// Recovered UIStampEventDialog (UI type 0x4f33 "StampEventDialog"): the stamp event board. RTTI vftables: dialog at +0,
// IMessageListener at +0x18, UIQuestEventListener at +0x178. File name assumed (the class name).
// Unnamed helpers and members use invented names.
#pragma once
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"        // UIQuestEventListener (13 slots)
#include "ms2/placeholder/ascript.h"

class ASTextField;
class NotifyObject;
class StampEventContext;
class ASScrollingList;
class UIStampEventDialog : public UIDialog, public UIQuestEventListener
{
public:
    UIStampEventDialog();                                           // 0x140ed74c0
    virtual ~UIStampEventDialog();                                  //  0 0x140ed7610 (??_G 0x140ed98e0)
    virtual CString GetTypeName();                                      //  1 0x140ed7680
    virtual int vfunc_65();                                         // 65 0x140ed76d0
    virtual void vfunc_67();                                        // 67 0x140ed7730
    virtual void OnLoadComplete();                                  // 22 0x140ed7790
    virtual int vfunc_13();                                         // 13 0x140ed7990
    virtual void vfunc_45(Scaleform::GFx::Value* pOut, const CString& strMethod, ASData* pArgs);   // 45 0x140ed79b0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140ed7bb0
    virtual void vfunc_o178_10(void* pQuest);                       // quest progress: refresh the stamp 0x140ed7cf0
    virtual int vfunc_48() { return 0x4f33; }                       // 48 (COMDAT 0x140ed9920)

    void FUN_140ed7ea0();                                           // re-send stamps and rewards
    void FUN_140ed7f90(NotifyObject* pObj);                         // NotifyGameStart: open the board
    int GetClaimableRewardCount();                                            // number of claimable rewards
    void AddStamps(MS2Ptr<StampEventContext> spContext);        // "addStamp" for every stamp
    void FUN_140ed8590(MS2Ptr<StampEventContext> spContext);        // fill "m_reward"
    void SetCompleteReward(MS2Ptr<StampEventContext> spContext);        // "setCompleteReward"
    void UpdateStamp(unsigned nQuest);                            // "updateStamp"
    void FUN_140ed8c70();                                           // "m_count" text
    void SendEventRewardMode0(int nCount, int nSpecial);                   // request a reward (packet 0x97, 0)
    void SendEventRewardMode1();                                           // request the complete reward (packet 0x97, 1)
    int CanClaimCompleteReward();                                            // the complete reward can be claimed
    int GetRewardState(int nCount, int nSpecial);                    // reward state: 0 locked, 1 claimable, 2 claimed
    CString GetItemIconPath(int nItemId);                             // item icon name
    CString GetEventTag();                                        // the event tag
};
MS2_CHECK_SIZE(UIStampEventDialog, 0x180);
