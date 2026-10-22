// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed (the unit's first class).
//
// UIQuestEventDispatcher: the quest event hub (a TSingleton, global accessor FUN_140bfc4b0) that forwards quest state
// changes to every registered UIQuestEventListener (declared in uigalleryeventdialog.h; its ctor/dtor live here).
// UIQuestGuideDialog: the quest guide HUD ("QuestGuideDialog", UI type 0x4e43) listing the tracked quests, the field /
// dungeon mission and the recommended next quest. RTTI .?AVUIQuestGuideDialog@@, 0x248 bytes, vftables 0x142fd99e0
// (84 slots), 0x142fd9c88 (IMessageListener at +0x18) and 0x142fd9c98 (UIQuestEventListener at +0x178).
// Names: virtuals are Ghidra's vfunc_<slot> where the base does so; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)
#include "ms2/client/ms2/uisnowmaneventdialog.h"     // SnowmanPtr<>
#include "ms2/unnamed/payloadptr_1401f9eb0.h"

class ASData;
class ASObj;
class CInPacket;
class CQuest;
class NotifyObject;
class Unk_RewardEntryPtr;
namespace UICommon { class CAlignmentInfo; }

// vftable 0x142fd8790. Each slot walks the listeners and forwards to the matching UIQuestEventListener slot; the
// quest-state slots 1..3 route the special quest types (3, 4, 5, 7, 10) to listener slots 8..12.
class UIQuestEventDispatcher : public TSingleton<UIQuestEventDispatcher>
{
public:
    UIQuestEventDispatcher();                       // 0x141aa8720
    virtual ~UIQuestEventDispatcher();              // 0 0x141aa8770 (??_G 0x141aa9000)
    virtual void vfunc_1(CQuest* pQuest);           // 1 0x141aa88e0 accepted
    virtual void vfunc_2(CQuest* pQuest);           // 2 0x141aa8a30 removed
    virtual void vfunc_3(CQuest* pQuest);           // 3 0x141aa8b70 progress
    virtual void vfunc_4(void* p);                  // 4 0x141aa8cb0
    virtual void vfunc_5(void* p);                  // 5 0x141aa8d40 completed
    virtual void vfunc_6(void* p);                  // 6 0x141aa8dd0 tracking changed
    virtual void vfunc_7(int a1, int a2);           // 7 0x141aa8e60

    void FUN_141aa87c0(UIQuestEventListener* pListener);    // register (once)
    void FUN_141aa8850(UIQuestEventListener* pListener);    // unregister

private:
    ATL::CAtlArray<UIQuestEventListener*> m_listeners;      // +0x08
};
MS2_CHECK_SIZE(UIQuestEventDispatcher, 0x28);

// An 8-byte millisecond poll timer (ctor 0x140517b00, "interval elapsed" test 0x140268870).
class Unk_DTTick
{
public:
    Unk_DTTick();
    int FUN_140268870(unsigned nInterval);
private:
    unsigned __int64 m_tick;
};
MS2_CHECK_SIZE(Unk_DTTick, 8);

class UIQuestGuideDialog : public UIDialog, public UIQuestEventListener
{
public:
    UIQuestGuideDialog();                                                                   // 0x141aa97d0
    virtual ~UIQuestGuideDialog();                                                          //  0 0x141aa99c0
    virtual CString GetTypeName();                                                              //  1 0x141aa9a90
    virtual void vfunc_15();                                                                // 15 0x141aaa450
    virtual void vfunc_18();                                                                // 18 0x141aab350
    virtual void OnLoadComplete();                                                          // 22 0x141aa9f60
    virtual void vfunc_26();                                                                // 26 0x141aaa380
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                            // 28 0x141aaa670
    virtual void vfunc_43();                                                                // 43 0x141aa9f10
    virtual int vfunc_48() { return 0x4e43; }                                               // 48 (COMDAT 0x141ab1a20)
    virtual int vfunc_52();                                                                 // 52 0x141aaafa0
    virtual int vfunc_53(void* pCfg);                                                       // 53 0x141aaafc0
    virtual int vfunc_54(void* pCfg);                                                       // 54 0x141aab180
    virtual int vfunc_65();                                                                 // 65 0x141aa9ae0
    virtual void vfunc_67();                                                                // 67 0x141aa9cb0

    // UIQuestEventListener (+0x178) overrides
    virtual void vfunc_o178_1(void* pQuest);                                                // 0x141aab3b0
    virtual void vfunc_o178_2(void* pQuest);                                                // 0x141aab420
    virtual void vfunc_o178_3(void* pQuest);                                                // 0x141aab480
    virtual void vfunc_o178_7(int nQuestId, int a2);                                        // 0x141aab4d0
    virtual void vfunc_o178_5(void* pQuest);                                                // 0x141aab510
    virtual void vfunc_o178_6(void* pQuest);                                                // 0x141aab570
    virtual void vfunc_o178_9(void* p);                                                     // 0x141aab610

    void FUN_141aab700(CInPacket& packet);                      // packet 0x100: field mission update
    void FUN_141aab760(NotifyObject* pObj);                     // NotifyChangeMyLevel: refresh the recommendation
    void FUN_141aab840(CInPacket& packet);                      // packet 0x53: refresh the multi-user quests
    void FUN_141aaba00();                                       // rebuild the whole list ("buildAll")
    void FUN_141aabcb0();                                       // the field / dungeon mission ("addMission")
    void FUN_141aabe50(CQuest* pQuest);                         // "updateEntity"
    int FUN_141aac190(int nQuestId);                            // "addEntity"
    void FUN_141aac360(int nQuestId);                           // "removeEntity"
    void FUN_141aac3e0(ASObj& obj, CQuest* pQuest);             // "conditions"
    void FUN_141aac6a0(ASObj& obj, CQuest* pQuest);             // "period" / "expired"
    void FUN_141aac9b0(ASObj& obj, CQuest* pQuest);             // "navi" / "tracing"
    void FUN_141aaca80(ASObj& obj, CQuest* pQuest);             // "gotoButton"
    bool FUN_141aacd70();                                       // AS "canAdd"
    bool FUN_141aace20(int nQuestId);                           // the quest belongs to the current map
    void FUN_141aacef0(int nQuestId);                           // queue a removal
    void FUN_141aacf20();                                       // request a rebuild
    CStringW FUN_141aacf40(int nQuestId);                       // "chapterName"
    unsigned FUN_141aad300(int nChapter);                       // quests in the chapter
    int FUN_141aad360(int nChapter, int nQuestId);              // 1-based index of the quest in its chapter
    CString FUN_141aad4d0(int nChapter, int nQuestId);          // "questIndex" "{0}/{1}"
    CString FUN_141aad550(CQuest* pQuest);                      // "icon"
    int FUN_141aad6b0(CQuest* pQuest, ASObj& obj);              // fill one quest entity
    void FUN_141aadbc0();                                       // "updateMission" (dungeon)
    void FUN_141aadc50();                                       // re-apply the alignment
    void FUN_141aadd10(int* pnWidth, int* pnHeight);            // the dialog size
    bool FUN_141aaddb0(ASObj& obj);                             // the field mission entity
    bool FUN_141aae150(ASObj& obj);                             // the dungeon mission entity
    CStringW FUN_141aae4f0(Unk_RewardEntryPtr spEntry);         // a dungeon mission goal text
    void FUN_141aae5a0();                                       // refresh the recommended quest
    int FUN_141aae6d0();                                        // the recommended next quest id (ignores this)
    int FUN_141aae8d0(int nQuestId, ASObj& obj);                // fill the recommended quest entity
    CStringW FUN_141aaedd0(int nQuestId);                       // "where to start" text
    void FUN_141aaf150(const Scaleform::GFx::FunctionHandler::Params& params);   // m_funcGetNavigation

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<unsigned> m_removeQueue;                     // +0x180 quests to remove on the next tick
    ATL::CAtlArray<unsigned> m_addQueue;                        // +0x1a0 quests to add on the next tick
    int m_bRebuild;                                             // +0x1c0
    int m_bRecommendDirty;                                      // +0x1c4
    int m_bMissionToggle;                                       // +0x1c8 "onFieldMissionToggle"
    ATL::CAtlMap<__int64, int> m_pageIndex;                     // +0x1d0 "m_pageIndex" per character id
    Unk_DTTick m_navigationTick;                                // +0x218
    MS2Ptr<AScript> m_navigation;                               // +0x220 AS "updateNavigation"
    SnowmanPtr<UICommon::CAlignmentInfo> m_alignment;           // +0x230
    int m_nRecommendQuest;                                      // +0x240
};
MS2_CHECK_SIZE(UIQuestGuideDialog, 0x248);
MS2_CHECK_OFFSET(UIQuestGuideDialog, m_removeQueue, 0x180);
MS2_CHECK_OFFSET(UIQuestGuideDialog, m_pageIndex, 0x1d0);
MS2_CHECK_OFFSET(UIQuestGuideDialog, m_navigation, 0x220);
MS2_CHECK_OFFSET(UIQuestGuideDialog, m_nRecommendQuest, 0x240);
