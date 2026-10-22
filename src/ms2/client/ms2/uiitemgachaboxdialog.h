// Recovered gacha box dialog (the capsule machine: opens one or ten gacha boxes with a key, shows the obtained items in
// the machine's result slots). Unk_ names are local reconstruction names.
#pragma once
#include <set>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/commonfiles/itemgift.h"
#include "ms2/commonfiles/commonstruct_wa.h"
#include "ms2/commonfiles/itemgachaboxtable.h"
class CMsgBoxData;
class ASMovieClip;
// Orders the set of special items (the comparator is the ItemEntity ordering of commonfiles\commonstruct).
struct Unk_GachaLess
{
    bool operator()(const ItemEntity& a, const ItemEntity& b) const { return FUN_14026aeb0(a, b); }
};
class UIItemGachaBoxDialog : public UIDialog
{
public:
    UIItemGachaBoxDialog();
    virtual ~UIItemGachaBoxDialog();
    virtual CString vfunc_1();
    virtual int vfunc_65();
    virtual void vfunc_26();
    virtual void vfunc_67();
    virtual void OnLoadComplete();
    virtual void vfunc_79(void*);
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    // @0x140c464d0
    virtual int vfunc_48() { return 20363; }
    void FUN_140c40ad0();
    int FUN_140c41700();
    void FUN_140c41900(int);
    void FUN_140c41c30(int);
    void FUN_140c41e10();
    void OnOpenCoinShop();
    int FUN_140c420e0();
    void FUN_140c42160();
    bool FUN_140c42e70(const ItemEntity&);
    void FUN_140c42ee0(CString);
    bool FUN_140c42fd0(int, const CMsgBoxData&);
    void FUN_140c43010();
    void FUN_140c43090();
    GachaBoxDataPtr FUN_140c43110();
    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString&);
private:
    MS2_LAYOUT_FRIEND;
    int m_boxItemId;                            // +0x178 item id of the box that is being opened
    int m_machineId;                            // +0x17c item id of the capsule machine (the key shop)
    CStringW m_title;                           // +0x180 name of the box item
    int m_uiType;                               // +0x188 GachaBoxData::m_nUi
    int m_season;                               // +0x18c GachaBoxData::GetSeason()
    bool m_multi;                               // +0x190 ten at a time
    bool m_sent;                                // +0x191 the open request was sent
    int m_sndRolling;                           // +0x194 handle of the looping rolling effect
    Unk_StrVec m_bagIds;                        // +0x198 names of the three prize preview bags
    Unk_ItemVec m_result;                       // +0x1b0 the obtained items (std::vector<ItemEntity>)
    Unk_StrVec m_slotBinds;                     // +0x1c8 the "binding" strings handed to the AS result slots
    std::set<ItemEntity, Unk_GachaLess> m_special;      // +0x1e0 rare items of the last result
    MS2Ptr<ASMovieClip> m_resultItem;           // +0x1f0 "m_resultItem" of the machine
};
MS2_CHECK_SIZE(UIItemGachaBoxDialog, 0x200);
MS2_CHECK_OFFSET(UIItemGachaBoxDialog, m_boxItemId, 0x178);
MS2_CHECK_OFFSET(UIItemGachaBoxDialog, m_title, 0x180);
MS2_CHECK_OFFSET(UIItemGachaBoxDialog, m_multi, 0x190);
MS2_CHECK_OFFSET(UIItemGachaBoxDialog, m_sndRolling, 0x194);
MS2_CHECK_OFFSET(UIItemGachaBoxDialog, m_bagIds, 0x198);
MS2_CHECK_OFFSET(UIItemGachaBoxDialog, m_result, 0x1b0);
MS2_CHECK_OFFSET(UIItemGachaBoxDialog, m_slotBinds, 0x1c8);
MS2_CHECK_OFFSET(UIItemGachaBoxDialog, m_special, 0x1e0);
MS2_CHECK_OFFSET(UIItemGachaBoxDialog, m_resultItem, 0x1f0);
