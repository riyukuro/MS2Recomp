// uiitemoptioncreatedialog.h - UIItemOptionCreateDialog (RTTI .?AVUIItemOptionCreateDialog@@, UI type 0x4ecd, 0x198 bytes):
// the GM-style window that builds an item with chosen option rows (a dev tool of the KMS2_DEV client). NOT an original
// header (the unit is ?\uiitemoptioncreatedialog.cpp). It lists the items of the ugc/ing item table, filters them by a
// group and a search text, shows the rank list and the random / constant option rows of the picked item and sends the
// create-item packet (0x15). Names are invented from use; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"

class ASObj;
class ASUIComponent;
class ASScrollingList;

class UIItemOptionCreateDialog : public UIDialog
{
public:
    UIItemOptionCreateDialog();                                 // 0x1412d2660
    // implicit virtual dtor: 0x1412d5060 (no vptr store; ??_G 0x1412d5510)
    virtual CString GetTypeName();                                  //  1 0x1412d2700 "ItemOptionCreateDialog"
    virtual void OnLoadInit();                                  // 20 0x1412d2750 fill the item list once
    virtual int vfunc_13();                                     // 13 0x1412d27d0 Enter in the search box runs the search
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x1412d2980 movie callbacks
    virtual int vfunc_48() { return 0x4ecd; }                   // 48 0x1412d5580 UI type id

    // "OnCreateItem": send the create-item packet; pOptions is the array of {kinds, type, index, value} rows.
    void FUN_1412d2e50(unsigned nItemId, unsigned nCount, int nParam, int nParam2, const Scaleform::GFx::Value& pOptions);
    void FUN_1412d33b0();                                       // fill the rank combo of the picked item
    void FUN_1412d3740();                                       // fill the random option table of the item / rank
    void FUN_1412d3a60();                                       // fill the constant option result of the item / rank
    void FUN_1412d3c10(const CString& strGroup, const CStringW& strSearch);    // fill the item list (group / search filter)

protected:
    MS2_LAYOUT_FRIEND;
    std::vector<unsigned> m_ids;                                // +0x178 the item ids of the list
    int m_nItemId;                                              // +0x190 the picked item
    int m_nRank;                                                // +0x194 the picked rank
};
MS2_CHECK_SIZE(UIItemOptionCreateDialog, 0x198);
MS2_CHECK_OFFSET(UIItemOptionCreateDialog, m_nItemId, 0x190);
MS2_CHECK_OFFSET(UIItemOptionCreateDialog, m_nRank, 0x194);
