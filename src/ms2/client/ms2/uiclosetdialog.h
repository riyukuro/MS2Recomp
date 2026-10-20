// uiclosetdialog.h - UIClosetDialog (RTTI .?AVUIClosetDialog@@, 0x2c0 bytes, UIDialog + UIItemEventListener at +0x178,
// UI id 0x4f76, swf "ClosetDialog"): the closet (saved equipment sets) window. Each tab holds an ItemCloset::TabInfo
// (the server's record of a saved set: index, equip layer, hot key action id, slots); the slot list shows the items of
// the selected tab per equip slot group, a tab can be saved from the current equipment, cleared, put on, renamed and
// bound to a hot key. Server packet 0x123 (mode 5: one tab), client packet 0xb4 (0 save, 1 put on, 2 clear, 4 key,
// 6 rename). NOT an original header (the unit is client\ms2\uiclosetdialog.cpp; header name assumed). Layouts from the
// ctor/dtor and the v2525 snapshot's UIClosetDialog.h / UICloset/*.h; member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/intervaltimer.h"
#include "ms2/placeholder/itemcloset.h"
#include "ms2/placeholder/pendingkeyinput.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/client/ms2/uidialog.h"

class ASArray;
class ASButton;
class ASButtonBar;
class ASDropdownMenu;
class ASMovieClip;
class ASObj;
class ASSlot;
class ASTooltip;
class CInPacket;
class CItem;
class CMsgBoxData;

// The equip slot group of a closet slot (the 14 groups the dialog lists, filled in vfunc_65). The values are the
// game's equip slot ids; the enum's real name (v2525: EquipSlotType) is not confirmed by a symbol.
enum EquipSlotType
{
    EquipSlot_None = 0
};

namespace UICloset {

// A closet tab (RTTI .?AVCTab@UICloset@@, 0x28 bytes, vftable 0x142df5118): the tab's server record.
class CTab : public CPtred
{
public:
    CTab();                                                     // 0x140be30d0
    virtual ~CTab() = default;                                  // 0x140be3650 (no vptr store; ??_G 0x140be3f20)

    bool Initialize(const CStringW& strName, int nLayer);       // 0x140bd8ca0 new record
    void SetInfo(MS2Ptr<ItemCloset::TabInfo> spInfo);           // 0x140bd8db0
    void SetIndex(int nIndex);                                  // 0x140bd8e00
    void SetName(const CStringW& strName);                      // 0x140bd8e50
    int GetIndex();                                             // 0x140bd8eb0 (-1 without a record)
    CStringW GetName();                                         // 0x140bd8f00
    CStringW TooltipText();                                     // 0x140bd8fa0
    __int64 GetId();                                            // 0x140bd9040 the hot key action id
    bool IsEmpty();                                             // 0x140bd9090 no record
    bool ItemsEmpty();                                          // 0x140bd90d0 no saved slots
    MS2Ptr<ItemCloset::TabInfo> GetInfo() { return m_info; }    // 0x140be4770

    MS2Ptr<ItemCloset::TabInfo> m_info;                         // +0x18
};

// One slot of the selected tab (RTTI .?AVCSlotData@UICloset@@, 0x40 bytes).
class CSlotData : public CPtred
{
public:
    CSlotData(MS2Ptr<ItemCloset::SlotInfo> spInfo, MS2Ptr<CItem> spItem, bool bOwned);   // 0x140be3030
    virtual ~CSlotData() = default;                             // 0x140be3610 (no vptr store; ??_G 0x140be3ee0)

    void CopyFrom(MS2Ptr<CSlotData> spOther);                   // 0x140bd9140
    MS2Ptr<CItem> RecreateItem();                               // 0x140bd9190 a display item from the record
    MS2Ptr<CItem> GetItem() { return m_item; }                  // 0x140be46b0
    bool IsOwned() { return m_owned; }                          // 0x140be4ef0
    bool IsChanged() { return m_changed; }                      // 0x140be4f50
    void SetOwned(bool b) { m_owned = b; }                      // 0x140be6210
    void SetChanged(bool b) { m_changed = b; }                  // 0x140be6300

    MS2Ptr<ItemCloset::SlotInfo> m_info;                        // +0x18
    MS2Ptr<CItem> m_item;                                       // +0x28
    bool m_owned;                                               // +0x38 the player still has the item
    bool m_changed;                                             // +0x39
};

// The hot key capture of a tab (RTTI .?AUPendingKeyInput@UICloset@@, 0x30 bytes).
struct PendingKeyInput : public CGameOptionCommon::PendingKeyInput
{
    PendingKeyInput();                                          // 0x140be31a0
    virtual ~PendingKeyInput() = default;                       // 0x140be36b0 (no vptr store; ??_G 0x140be3fa0)
    virtual void Clear();                                       // 1 0x140be4380
    virtual bool Ready();                                       // 2 0x140be4cc0

    void SetTab(MS2Ptr<CTab> spTab) { m_tab = spTab; }          // 0x140be61d0
    MS2Ptr<CTab> GetTab() { return m_tab; }                     // 0x140be4640

    MS2Ptr<CTab> m_tab;                                         // +0x20
};

} // namespace UICloset

MS2_CHECK_SIZE(UICloset::CTab, 0x28);
MS2_CHECK_SIZE(UICloset::CSlotData, 0x40);
MS2_CHECK_SIZE(UICloset::PendingKeyInput, 0x30);

class UIClosetDialog : public UIDialog, public UIItemEventListener
{
public:
    UIClosetDialog();                                           // 0x140bd9290
    virtual ~UIClosetDialog();                                  // 0x140bd9530 (??_G 0x140be4020)
    virtual CString vfunc_1();                                  //  1 0x140bd9770 "ClosetDialog"
    virtual int vfunc_13();                                     // 13 0x140bdb4e0 hot key capture
    virtual void OnLoadComplete();                              // 22 0x140bd9c00
    virtual void vfunc_26();                                    // 26 0x140bdb360
    virtual int vfunc_48() { return 0x4f76; }                   // 48 0x140be47c0
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x140bdba00 "slot" tooltip
    virtual int vfunc_65();                                     // 65 0x140bd97c0
    virtual void vfunc_72();                                    // 72 0x140bdbba0 refresh the changed slots
    virtual int vfunc_73();                                     // 73 0x140bdbad0 not in battle
    virtual bool vfunc_75();                                    // 75 0x140bdb9d0 feature 0xe3
    virtual void vfunc_3(void* pItem, bool bRemoved);           // UIItemEventListener 3 0x140bdbf50
    virtual void vfunc_21(void* pItem);                         // UIItemEventListener 21 0x140bdbfd0

    void OnPacket(CInPacket& packet);                           // 0x140bdc020
    void SelectTab(int nIndex);                                 // 0x140bdc0a0
    void BuildTabRow(ASObj& obj, MS2Ptr<UICloset::CTab> spTab); // 0x140bdc3b0
    void AddTabRow(ASArray& dp, MS2Ptr<UICloset::CTab> spTab);  // 0x140bdc620
    void UpdateTabRow(MS2Ptr<ASButton> spButton, MS2Ptr<UICloset::CTab> spTab, int nIndex);   // 0x140bdc6f0
    void AddEquipRow(ASArray& dp, const CStringW& strLabel, const int& nIndex);              // 0x140bdc960
    void BuildSlot(ASSlot& slot, MS2Ptr<UICloset::CSlotData> spSlot, int nIndex);             // 0x140bdca40
    void BuildEquipProvider(ASArray& dp);                       // 0x140bdcbb0
    void BuildTabProvider(ASArray& dp);                         // 0x140bdcd10
    void UpdateTab(int nIndex);                                 // 0x140bdce50 the hot key label
    void PopulateItems(MS2Ptr<ItemCloset::TabInfo> spInfo);     // 0x140bdd030
    void BuildSlots(ASObj& obj);                                // 0x140bdd890
    void BuildTooltip(ASTooltip& tooltip, int nIndex);          // 0x140bddb50
    void ReceiveTab(CInPacket& packet);                         // 0x140bddcf0
    void OnSave(const Scaleform::GFx::FunctionHandler::Params& params);        // 0x140bddf80
    void OnClear(const Scaleform::GFx::FunctionHandler::Params& params);       // 0x140bde400
    void OnPutOn(const Scaleform::GFx::FunctionHandler::Params& params);       // 0x140bde610
    void OnTabAdd(const Scaleform::GFx::FunctionHandler::Params& params);      // 0x140bde7a0
    void OnInputKey(const Scaleform::GFx::FunctionHandler::Params& params);    // 0x140bdea60
    void OnInputEnd(const Scaleform::GFx::FunctionHandler::Params& params);    // 0x140bdee80
    void OnTabChange(const Scaleform::GFx::FunctionHandler::Params& params);   // 0x140bdf000
    void OnEquipLayer(const Scaleform::GFx::FunctionHandler::Params& params);  // 0x140bdf080
    void OnTabMenu(const Scaleform::GFx::FunctionHandler::Params& params);     // 0x140bdf240
    bool OnAddConfirmed(int nResult, const CMsgBoxData& box);                  // 0x140bdf500
    bool OnRenameConfirmed(int nResult, const CMsgBoxData& box);               // 0x140bdf9f0
    bool OnSaveConfirmed(int nResult, const CMsgBoxData& box);                 // 0x140bdfdd0
    bool OnKeyConfirmed(int nResult, const CMsgBoxData& box);                  // 0x140bdff00
    bool OnClearConfirmed(int nResult, const CMsgBoxData& box);                // 0x140be00d0
    int CurrentTabIndex();                                      // 0x140be01f0
    int GetLayer();                                             // 0x140be0250
    MS2Ptr<UICloset::CTab> GetTab(int nIndex);                  // 0x140be0270
    MS2Ptr<UICloset::CTab> CurrentTab();                        // 0x140be0350
    bool AssignKey(const unsigned& nKey, const __int64& nId);   // 0x140be03a0
    __int64 TabIdentifier(int nIndex);                          // 0x140be0590 the tab's hot key action id
    bool GetGroup(unsigned nIndex, EquipSlotType& eType);       // 0x140be06e0
    int FindGroup(EquipSlotType eType);                         // 0x140be0770
    MS2Ptr<UICloset::CSlotData> GetSlot(int nIndex);            // 0x140be0820
    MS2Ptr<UICloset::CSlotData> FindSlot(__int64 nUid, int& nIndex);           // 0x140be0900
    void SetSlot(int nIndex, MS2Ptr<UICloset::CSlotData> spSlot);              // 0x140be0b90
    int TabIndex(int nIndex);                                   // 0x140be0c10
    int EmptyTabIndex();                                        // 0x140be0ca0
    MS2Ptr<UICloset::CTab> FindTab(const __int64& nId);         // 0x140be0da0
    bool SendApply(MS2Ptr<UICloset::CTab> spTab);               // 0x140be0f50
    bool SendSave(int nLayer, MS2Ptr<UICloset::CTab> spTab);    // 0x140be1180
    bool SendRename(MS2Ptr<UICloset::CTab> spTab);              // 0x140be1280
    bool SendClear(MS2Ptr<UICloset::CTab> spTab);               // 0x140be13d0
    MS2Ptr<CItem> FindItem(const __int64& nUid);                // 0x140be14c0
    void InvalidateItem(const __int64& nUid);                   // 0x140be1610
    void ResetTabs();                                           // 0x140be18a0
    bool RequestById(int nId);                                  // 0x140be1910
    CStringW TabName(const __int64& nId);                       // 0x140be1a00

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<MS2Ptr<UICloset::CTab> > m_tabs;             // +0x180 (max tab count entries)
    ATL::CAtlArray<MS2Ptr<UICloset::CSlotData> > m_slots;       // +0x1a0 one per group
    ATL::CAtlArray<EquipSlotType> m_groups;                     // +0x1c0
    ATL::CRBMap<int, MS2Ptr<UICloset::CSlotData> > m_changed;   // +0x1e0 slots to refresh (vfunc_72)
    Unk_IntervalTimer m_timer;                                  // +0x210
    MS2Ptr<ASButton> m_save;                                    // +0x218
    MS2Ptr<ASButton> m_clear;                                   // +0x228
    MS2Ptr<ASButton> m_putOn;                                   // +0x238
    MS2Ptr<ASButton> m_inputKey;                                // +0x248
    MS2Ptr<ASButtonBar> m_tab;                                  // +0x258
    MS2Ptr<ASButton> m_tabAdd;                                  // +0x268
    MS2Ptr<ASDropdownMenu> m_equipLayer;                        // +0x278
    MS2Ptr<ASMovieClip> m_symbol;                               // +0x288
    MS2Ptr<UICloset::PendingKeyInput> m_pendingKey;             // +0x298
    MS2Ptr<UICloset::PendingKeyInput> m_pendingSwap;            // +0x2a8 (the key's previous tab)
    int m_nLayer;                                               // +0x2b8 equip layer 0-2 (3 = none)
};
MS2_CHECK_SIZE(UIClosetDialog, 0x2c0);
MS2_CHECK_OFFSET(UIClosetDialog, m_tabs, 0x180);
MS2_CHECK_OFFSET(UIClosetDialog, m_changed, 0x1e0);
MS2_CHECK_OFFSET(UIClosetDialog, m_timer, 0x210);
MS2_CHECK_OFFSET(UIClosetDialog, m_pendingKey, 0x298);
MS2_CHECK_OFFSET(UIClosetDialog, m_nLayer, 0x2b8);
