// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed (the unit's first class); the unit
// ?\uisidepopuptalk.cpp is three original TUs (three copies of the header statics, three COMDAT tails), written as
// uisidepopuptalk_1.cpp (UISidePopupTalk), _2.cpp (UISelectSuperWorldChatDialog) and _3.cpp (the side popup
// conditions and CSidePopupTalkTable).
//
// UISidePopupTalk ("SidePopupTalk", UI type 0x4f57, RTTI .?AVUISidePopupTalk@@, 0x140 bytes = UIHeadUpDisplay +
// UIQuestEventListener at +0x70 + UIWorldShareInfoEventListener at +0x78): the NPC speech balloons in the screen
// corner. Quest accept / progress / complete events, boss regen notices and the map's fade-in look up a popup of
// Table/SidePopupTalk.xml (CSidePopupTalkTable) and push it to the movie ("addPopup").
// UISelectSuperWorldChatDialog ("SelectSuperWorldChatDialog", 0x4f58, 0x230 bytes): picks the super world chat item.
// CSidePopupCondition and subclasses (ClassObject, created by name "CSidePopupCondition<eventType>"): when a popup
// of the table may show.
// Names: virtuals are Ghidra's vfunc_<slot> where the base does so; other names are invented from their use.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <utility>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/uiworldshareinfoeventdispatcher.h"
#include "ms2/placeholder/classobject.h"
#include "ms2/placeholder/sidepopuptalkparam.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)

class ASData;
class NotifyObject;
class Unk_140165cf0;

// ---- ?\uisidepopuptalk.cpp#3: the conditions and the table ----------------------------------------------------------

// The event a popup reacts to (CSidePopupCondition::m_eKind; the table key's first half). Names invented.
enum eSidePopupEvent
{
    SIDEPOPUP_EVENT_NONE = 0,
    SIDEPOPUP_EVENT_QUEST_ACCEPT = 1,
    SIDEPOPUP_EVENT_QUEST_PROGRESS = 2,
    SIDEPOPUP_EVENT_QUEST_SATISFIED = 3,
    SIDEPOPUP_EVENT_QUEST_COMPLETE = 4,
    SIDEPOPUP_EVENT_BOSS_REGEN = 5,
};

// RTTI .?AVCSidePopupCondition@@, vftable 0x142e5b3b0 (5 slots), 0x20 bytes. The dtors are implicit.
class CSidePopupCondition : public ClassObject
{
public:
    static ClassObject* CreateObject();                     // 0x140e8d770
    CSidePopupCondition();                                  // 0x140e8d820
    virtual CStringW vfunc_1();                             // 1 0x140e8d7d0 class name
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x140e8d860 Load: "key"
    // @0x140e91ba0
    virtual int vfunc_3() { return 1; }                     // 3 the popup may show (Find)
    // @0x140e91b90
    virtual int vfunc_4() { return 0; }                     // 4 the popup may show on entering its map (FindByMap)

    unsigned m_nId;                                         // +0x18 "key": quest id / npc id
    eSidePopupEvent m_eKind;                                // +0x1c
};
MS2_CHECK_SIZE(CSidePopupCondition, 0x20);

class CSidePopupConditionQuestAccept : public CSidePopupCondition
{
public:
    static ClassObject* CreateObject();                     // 0x140e8d8a0
    virtual CStringW vfunc_1();                             // 1 0x140e8d900
    CSidePopupConditionQuestAccept();                       // 0x140e8d950
};

class CSidePopupConditionQuestSatisfied : public CSidePopupCondition
{
public:
    static ClassObject* CreateObject();                     // 0x140e8d990
    virtual CStringW vfunc_1();                             // 1 0x140e8d9f0
    CSidePopupConditionQuestSatisfied();                    // 0x140e8da40
    virtual int vfunc_4();                                  // 4 0x140e8da80 the quest is complete
};

class CSidePopupConditionQuestComplete : public CSidePopupCondition
{
public:
    static ClassObject* CreateObject();                     // 0x140e8db30
    virtual CStringW vfunc_1();                             // 1 0x140e8db90
    CSidePopupConditionQuestComplete();                     // 0x140e8dbe0
};

class CSidePopupConditionBossRegen : public CSidePopupCondition
{
public:
    static ClassObject* CreateObject();                     // 0x140e8dc20
    virtual CStringW vfunc_1();                             // 1 0x140e8dc80
    CSidePopupConditionBossRegen();                         // 0x140e8dcd0
};

// 0x40 bytes: the quest's progress counters must equal "args".
class CSidePopupConditionQuestProgress : public CSidePopupCondition
{
public:
    static ClassObject* CreateObject();                     // 0x140e8dd10
    virtual CStringW vfunc_1();                             // 1 0x140e8dd70
    CSidePopupConditionQuestProgress();                     // 0x140e8ddc0
    virtual void vfunc_2(Unk_140165cf0* pElem);             // 2 0x140e8de10 + "args"
    virtual int vfunc_3();                                  // 3 0x140e8de60
    virtual int vfunc_4();                                  // 4 0x140e8de80
    int FUN_140e8dea0();                                    // every progress counter equals its arg

    ATL::CAtlArray<int> m_args;                             // +0x20
};
MS2_CHECK_SIZE(CSidePopupConditionQuestProgress, 0x40);

// Table/SidePopupTalk.xml: (event, key) -> popup.
class CSidePopupTalkTable
{
public:
    // RTTI .?AVPopupData@CSidePopupTalkTable@@, vftable 0x142e5b4d0, 0x48 bytes.
    class PopupData : public CPtred
    {
    public:
        // @0x140e90c60
        PopupData() : m_18(0), m_spParam(0), m_spCond(0), m_nMapId(0) {}

        int m_18;                                           // +0x18 (never set)
        MS2Ptr<SidePopupTalkParam> m_spParam;               // +0x20
        MS2Ptr<CSidePopupCondition> m_spCond;               // +0x30
        unsigned m_nMapId;                                  // +0x40 "map": only on this map (0: any)
    };
    typedef std::map<std::pair<int, unsigned>, MS2Ptr<PopupData> > PopupMap;

    CSidePopupTalkTable();                                  // 0x140e8dfc0
    ~CSidePopupTalkTable();                                 // 0x140e8dff0
    void Init();                                            // 0x140e8e020 load the xml
    MS2Ptr<SidePopupTalkParam> Find(eSidePopupEvent eKind, unsigned nId);   // 0x140e8e5b0
    MS2Ptr<SidePopupTalkParam> FindByMap(int nMapId);       // 0x140e8e7a0 the first popup of a map whose condition holds

    PopupMap m_popups;                                      // +0x00
};
MS2_CHECK_SIZE(CSidePopupTalkTable, 0x10);
MS2_CHECK_SIZE(CSidePopupTalkTable::PopupData, 0x48);

// ---- ?\uisidepopuptalk.cpp#1: UISidePopupTalk ------------------------------------------------------------------------

// The key of the playing voice effects (the popup's ui type as the movie passes it back). Name invented.
enum eSidePopupVoice
{
    SIDEPOPUP_VOICE_0 = 0,
};

class UISidePopupTalk : public UIHeadUpDisplay, public UIQuestEventListener, public UIWorldShareInfoEventListener
{
public:
    UISidePopupTalk();                                                      // 0x140e86d80 (m_2c = 0x1a)
    virtual ~UISidePopupTalk();                                             //  0 0x140e87040 (??_G 0x140e890f0)
    virtual CString vfunc_1();                                              //  1 0x140e87260 "SidePopupTalk"
    virtual void vfunc_2();                                                 //  2 0x140e878d0 show
    virtual void vfunc_3();                                                 //  3 0x140e878f0 hide: stop the voices
    virtual void OnLoadComplete();                                          // 22 0x140e872b0 push the pending popups
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x140e87420
    virtual void vfunc_43();                                                // 43 0x140e87370
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
                                                                            // 45 0x140e87f50 "getExpireDuration"
    // @0x140e89cb0
    virtual int vfunc_48() { return 0x4f57; }                               // 48 UI type id
    // UIQuestEventListener (+0x70)
    virtual void vfunc_o178_1(void* pQuest);                                // 1 0x140e87a40 quest accepted
    virtual void vfunc_o178_2(void* pQuest);                                // 2 0x140e87d00 quest completed
    virtual void vfunc_o178_3(void* pQuest);                                // 3 0x140e87ba0 quest progress
    // UIWorldShareInfoEventListener (+0x78)
    virtual void vfunc_1(__int64 n, int a, int b);                          // 1 0x140e87da0 a special npc notice

    void FUN_140e879a0(MS2Ptr<SidePopupTalkParam> spParam);                 // show (queued until the movie loaded)
    void FUN_140e87ec0(NotifyObject* pNotify);                              // "NotifyFadeInComplete": the map's popup
    void FUN_140e88010(MS2Ptr<SidePopupTalkParam> spParam);                 // "addPopup"
    int FUN_140e88690(unsigned nId);                                        // notified within the last minute
    void FUN_140e886f0(int bVisible);                                       // show / hide the minimap and quest guide

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<SidePopupTalkParam> > m_pending;                  // +0x80 pushed in OnLoadComplete
    CSidePopupTalkTable m_table;                                            // +0xa0
    ATL::CAtlMap<unsigned, DWORD> m_lastTick;                               // +0xb0 npc id -> tick of its last notice
    ATL::CAtlMap<eSidePopupVoice, unsigned> m_voices;                       // +0xf8 -> CEffectService effect id
};
MS2_CHECK_SIZE(UISidePopupTalk, 0x140);
MS2_CHECK_OFFSET(UISidePopupTalk, m_pending, 0x80);
MS2_CHECK_OFFSET(UISidePopupTalk, m_table, 0xa0);
MS2_CHECK_OFFSET(UISidePopupTalk, m_voices, 0xf8);

// ---- ?\uisidepopuptalk.cpp#2: UISelectSuperWorldChatDialog -----------------------------------------------------------

#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/itemslotbinder.h"

class ASButton;
class ASMultiSelectTileCacheList;
class CItem;

class UISelectSuperWorldChatDialog : public UIDialog
{
public:
    UISelectSuperWorldChatDialog();                                         // 0x140e8bcb0
    virtual ~UISelectSuperWorldChatDialog();                                //  0 0x140e8bde0 (??_G 0x140e8d3c0)
    virtual CString vfunc_1();                                              //  1 0x140e8be80 "SelectSuperWorldChatDialog"
    virtual void OnLoadComplete();                                          // 22 0x140e8bf40 list the chat items
    virtual void vfunc_26();                                                // 26 0x140e8bed0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                            // 28 0x140e8c720
    // @0x140e8d400
    virtual int vfunc_48() { return 0x4f58; }                               // 48 UI type id

    void FUN_140e8c790(const Scaleform::GFx::FunctionHandler::Params& params);  // "m_okButton": select the item (packet 0xa7)
    void FUN_140e8c8e0(const Scaleform::GFx::FunctionHandler::Params& params);  // "m_close": the same without closing
    void FUN_140e8ca10(ATL::CAtlArray<MS2Ptr<CItem> >& aOut);              // the "SuperWorldChat" items of the inventory
    void FUN_140e8cb80(ATL::CAtlArray<MS2Ptr<CItem> >& aOut);              // the "WeddingChat" items
    MS2Ptr<ASMultiSelectTileCacheList> FUN_140e8d030(const CString& strName, MS2Ptr<ASMultiSelectTileCacheList>& out);  // bind a child
    MS2Ptr<ASButton> FUN_140bc6d10(const CString& strName, MS2Ptr<ASButton>& out);   // bind a child (COMDAT of uicashattenddialog.cpp)

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASButton> m_okButton;                                            // +0x178
    MS2Ptr<ASButton> m_closeButton;                                         // +0x188
    MS2Ptr<ASMultiSelectTileCacheList> m_list;                              // +0x198 "m_selectItemList"
    ItemSlotBinder m_binder;                                                // +0x1a8
    ATL::CAtlMap<unsigned, unsigned> m_slotItems;                           // +0x1e8 list entry -> item id
};
MS2_CHECK_SIZE(UISelectSuperWorldChatDialog, 0x230);
MS2_CHECK_OFFSET(UISelectSuperWorldChatDialog, m_binder, 0x1a8);
MS2_CHECK_OFFSET(UISelectSuperWorldChatDialog, m_slotItems, 0x1e8);
