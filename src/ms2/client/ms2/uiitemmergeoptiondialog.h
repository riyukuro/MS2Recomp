// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiitemmergeoptiondialog.h (name assumed:
// the class name; the .cpp has an assert path).
//
// UIItemMergeOptionDialog (RTTI .?AVUIItemMergeOptionDialog@@, 0x1f0 bytes, UI id 0x4e68, swf "ItemMergeOptionDialog"):
// the dialog that re-rolls the option of a merged item. Bases: UIDialog (0x178), UIStatusEventListener at +0x178 and
// UIItemEventListener at +0x180 (it registers as an item event listener while open and re-reads the selected item on
// the item events). The player picks an item and a material, the server answers with a CItemMergeOptionProxy (price,
// ingredients, option ranges) and later with the rolled option; the dialog walks through the phases kept in m_nPhase:
//   0 empty, 1 ready, 2 item picked, 3 material picked, 4 waiting for the merge answer, 5 merge sent, 6 result shown.
// Packet 0x3f carries the requests (sub-op 0 info, 1 select, 2 preview, 3 merge, 4 choose, 7 debug material).
// Names: virtuals are Ghidra's vfunc_<slot>; the member names are invented; the FUN_<va> members are called from
// outside the unit (scenestategame.cpp, fusionslotbag.cpp).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <utility>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiitemeventlistener.h"
#include "ms2/placeholder/citemmergeoptionproxy.h"

class CItem;
class CInPacket;
class CMsgBoxData;
class ItemInfoSlot;
class ASMovieClip;
class Unk_MergeButton;

class UIItemMergeOptionDialog : public UIDialog, public UIStatusEventListener, public UIItemEventListener
{
public:
    UIItemMergeOptionDialog();                                  // 0x1419ccd00
    virtual ~UIItemMergeOptionDialog();                         //  0 0x1419ce3d0 (??_G 0x1419d74f0)
    virtual CString GetTypeName();                                  //  1 0x1419ce4a0 "ItemMergeOptionDialog"
    virtual int vfunc_13();                                     // 13 0x1419ce8f0 may the dialog be closed (not while a merge is pending)
    virtual void vfunc_15();                                    // 15 0x1419cf520 empty
    virtual void OnLoadComplete();                              // 22 0x1419ce650 register for the item events, build the bags
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x1419ceea0 the AS commands
    virtual void vfunc_43();                                    // 43 0x1419cec20 align beside the NPC dialog
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
                                                                // 45 0x1419ce9a0 ExternalInterface: isMergeable, getTooltipByGUID, getTooltipByID
    // @0x1419d7610
    virtual int vfunc_48() { return 0x4e68; }                   // 48
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x1419ce980 empty
    virtual void vfunc_67();                                    // 67 0x1419ce750 close: drop the bags and the listener
    // UIItemEventListener (+0x180) overrides
    virtual void vfunc_2(void* pSlot);                          //  2 0x1419ce4f0 the selected item changed: show it again
    virtual void vfunc_3(void* pSlot, bool b);                  //  3 0x1419ce590 empty
    virtual void vfunc_4(void* pSlot, int n);                   //  4 0x1419ce5b0 same as slot 2

    void FUN_1419d0ef0(CInPacket& packet);                      // answer: the options of the item merged before
    void FUN_1419d11b0(CInPacket& packet);                      // answer: the material items
    void FUN_1419d12f0(CInPacket& packet);                      // answer: the option proxy (price, ranges)
    void FUN_1419d1490(int nNormal, int nSpecial, int nValue);  // show the old and the new option (the merge answer)
    void FUN_1419d1ad0(MS2Ptr<CItem> spItem);                   // show the merge result
    void FUN_1419d1d20(int nError);                             // show the message of an error code
    int FUN_1419d27e0(ItemInfoSlot& slot);                      // is the movie idle (no merge animation running)

    // Sorts the option ranges for the preview: the fixed order of m_optionOrder first, the rest by name.
    class OptionLess
    {
    public:
        // @0x1419d6dc0
        explicit OptionLess(std::map<std::pair<int, int>, int>* pOrder) : m_pOrder(pOrder) {}      // 0x1419d6dc0
        bool operator()(const std::pair<int, int>& left, const std::pair<int, int>& right);         // 0x1419d7300
        CStringW GetName(const std::pair<int, int>& option);                                        // 0x1419d7570
    private:
        std::map<std::pair<int, int>, int>* m_pOrder;
    };

private:
    MS2_LAYOUT_FRIEND;
    void ApplyMergeItem(MS2Ptr<CItem> spItem);                  // 0x1419cfd10 show the ingredients of the item
    void ResetMergeItems();                                     // 0x1419cf530 rebuild the two slot bags
    void RefreshSelectedIngredient();                           // 0x1419cfa10
    void ShowOptionPreview(MS2Ptr<CItem> spItem);               // 0x1419d0140 the possible options
    void RefreshMaterialBag();                                  // 0x1419d0ba0
    void ShowMergePrice(MS2Ptr<CItem> spItem);                  // 0x1419d0d90 the meso price on the merge button
    bool ConfirmMerge(int nButton, const CMsgBoxData& box);     // 0x1419d2140 message box result: send the merge
    void RequestInfo();                                         // 0x1419d2180
    void RequestPreview();                                      // 0x1419d21e0
    void RequestSelection();                                    // 0x1419d2260
    void RequestMerge();                                        // 0x1419d22d0
    void RequestChoice(unsigned char nChoice);                  // 0x1419d2350
    void RequestMaterial();                                     // 0x1419d23c0
    void RequestResultTalk();                                   // 0x1419d2440
    int CheckMerge();                                           // 0x1419d2540 0 ok, else an error code (1..4)
    MS2Ptr<CItem> FindMergeItem(unsigned __int64 nUid);         // 0x1419d2890
    CStringW GetCurrentOption(MS2Ptr<CItem> spItem);            // 0x1419d28e0 the first option of the item as text
    void ShowMissingItem(int nItemId);                          // 0x1419d2ca0
    void SetPhase(int nPhase);                                  // 0x1419d2db0
    int GetPhase();                                             // 0x1419d2dd0
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);  // a movie clip child by name
    MS2Ptr<Unk_MergeButton> FUN_140bb4b10(const CString& strName);   // a button child by name

    unsigned __int64 m_188;                                     // +0x188
    ATL::CAtlArray<void*> m_items190;                           // +0x190 the uids of the material items
    MS2Ptr<CItemMergeOptionProxy> m_spProxy;                    // +0x1b0
    unsigned __int64 m_nItemUid;                                // +0x1c0 the item to re-roll
    unsigned __int64 m_nMaterialUid;                            // +0x1c8 the material item
    unsigned int m_nTalkId;                                     // +0x1d0 npc talk id of the result
    int m_nPhase;                                               // +0x1d4
    bool m_bSpecial;                                            // +0x1d8 the item has special options
    std::map<std::pair<int, int>, int> m_optionOrder;           // +0x1e0 (stat id, special id) -> display order
};
MS2_CHECK_SIZE(UIItemMergeOptionDialog, 0x1f0);
MS2_CHECK_OFFSET(UIItemMergeOptionDialog, m_items190, 0x190);
MS2_CHECK_OFFSET(UIItemMergeOptionDialog, m_spProxy, 0x1b0);
MS2_CHECK_OFFSET(UIItemMergeOptionDialog, m_nItemUid, 0x1c0);
MS2_CHECK_OFFSET(UIItemMergeOptionDialog, m_nPhase, 0x1d4);
MS2_CHECK_OFFSET(UIItemMergeOptionDialog, m_optionOrder, 0x1e0);
