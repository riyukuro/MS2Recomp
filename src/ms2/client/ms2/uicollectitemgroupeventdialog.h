// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICollectItemGroupEventDialog ("CollectItemGroupEventDialog"):
// the collect-item-group event window. Up to three running CollectItemGroup events (one tab button each); the selected
// one shows its condition items (2..5 slots in "item_panel{N}") and its reward, and a receive button sends packet 0x97.
// Class name from RTTI (.?AVUICollectItemGroupEventDialog@@, direct base UIDialog, UIItemEventListener at +0x178);
// size 0x218 (CUIService::RegisterDialogs 0x141adf580). Header name and member/method names are invented.
#pragma once
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/client/ms2/uidialog.h"

class ASButton;
class ASItemSlot;
class ASMovieClip;
class CollectItemGroupContext;
class GameEventVariable;

class UICollectItemGroupEventDialog : public UIDialog, public UIItemEventListener
{
public:
    UICollectItemGroupEventDialog();                            // 0x140be6eb0
    virtual ~UICollectItemGroupEventDialog();                   // 0x140be6fe0 (??_G 0x140be9570)
    virtual CString vfunc_1();                                  //  1 0x140be70e0 "CollectItemGroupEventDialog"
    virtual void OnLoadComplete();                              // 22 0x140be7130
    virtual void vfunc_26();                                    // 26 0x140be76c0
    virtual int vfunc_48() { return 0x4f81; }                   // 48 0x140be95d0
    virtual void vfunc_67();                                    // 67 0x140be7860
    virtual void vfunc_2(void* pItem);                          // UIItemEventListener 2 0x140be89e0
    virtual void vfunc_3(void* pItem, bool bRemoved);           // UIItemEventListener 3 0x140be8a30
    virtual void vfunc_4(void* pItem, int n);                   // UIItemEventListener 4 0x140be8a80
    virtual void vfunc_30(void* pItem);                         // UIItemEventListener 30 0x140be8ad0

    void RefreshEvents();                                       // 0x140be7880 the event tab buttons
    void Refresh();                                             // 0x140be7b60 the selected event's items and reward
    void SelectEvent(int nIndex);                               // 0x140be85f0
    bool HasItem(int nItemId, int nRarity, int nCount);         // 0x140be86c0 in the inventory (or worn, for one)
    bool IsComplete(int nIndex);                                // 0x140be8790 every condition item is owned
    void HideItemPanels();                                      // 0x140be8900
    void OnGameEvent(GameEventVariable* pVariable);             // 0x140be8b20 user value 0x898 changed
    void OnEventButton(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x140be8b60
    void OnReceive(const Scaleform::GFx::FunctionHandler::Params& params);       // 0x140be8ba0

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASButton> m_eventButtons[3];                         // +0x180 "m_eventButton{0}"
    MS2Ptr<ASMovieClip> m_conditionItem;                        // +0x1b0
    std::vector<MS2Ptr<ASItemSlot> > m_slots;                   // +0x1c0 the item slots shown
    MS2Ptr<ASMovieClip> m_rewardPanel;                          // +0x1d8
    MS2Ptr<ASButton> m_recieveItemButton;                       // +0x1e8
    int m_selected;                                             // +0x1f8 selected event (-1: none)
    std::vector<MS2Ptr<CollectItemGroupContext> > m_contexts;   // +0x200 the running events
};
MS2_CHECK_SIZE(UICollectItemGroupEventDialog, 0x218);
MS2_CHECK_OFFSET(UICollectItemGroupEventDialog, m_eventButtons, 0x180);
MS2_CHECK_OFFSET(UICollectItemGroupEventDialog, m_slots, 0x1c0);
MS2_CHECK_OFFSET(UICollectItemGroupEventDialog, m_selected, 0x1f8);
MS2_CHECK_OFFSET(UICollectItemGroupEventDialog, m_contexts, 0x200);
