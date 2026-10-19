// setitemtable.h - SetItemTable (RTTI .?AVSetItemTable@@, 0x98 bytes): the equipment set table, read from
// Table/SetItemInfo.xml. Header name assumed (it lives in the placeholder dir because ms2.cpp includes it from there).
// Bases: TSingleton<SetItemTable> at +0x0, CValidData<SetItemTable> at +0x8. A TSingleton that CGameApp::InitInstance
// (?\ms2.cpp) creates. Member names are invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <map>
#include <vector>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/setiteminfo.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cvaliddata.h"

typedef MS2Ptr<SetItemInfo> SetItemInfoPtr;

class SetItemTable : public TSingleton<SetItemTable>, public CValidData<SetItemTable>
{
public:
    SetItemTable();                                         // 0x1407c4980
    virtual ~SetItemTable();                                // 0x1407c4a50

    int Load();                                             // 0x1407c4ae0 read the xml, verify, mark initialized
    int LoadSets();                                         // 0x1407c4b30 Table/SetItemInfo.xml into the two maps
    int FUN_1407c52d0();                                    // verification (always passes)
    SetItemInfoPtr GetSetItemInfo(int nSetId);              // 0x1407c5050 the set row (null when missing)
    void FUN_1407c50e0(int nSetId, void* pOut);             // appends the piece item ids of a set
    bool FUN_1407c5160(int nSetId);                         // the flag at +0x80 of a set (false when missing)
    bool HasSetItem(unsigned nItemId) const;                         // 0x1407c51f0 the item is a piece of some set
    void GetSetItemInfos(unsigned nItemId, std::vector<SetItemInfoPtr>& sets);   // 0x1407c5250 every set of an item

    static void CheckInit();                                // 0x1407c7710
    static void SetInit(bool b);                            // 0x1407c8620

    static bool s_bInit;                                    // DAT_143ab0fa8

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;                            // +0x10
    ATL::CAtlMap<int, SetItemInfoPtr> m_map;                // +0x40 set id -> row
    std::multimap<unsigned, SetItemInfoPtr> m_byItem;          // +0x88 piece item id -> sets
};
MS2_CHECK_SIZE(SetItemTable, 0x98);
MS2_CHECK_OFFSET(SetItemTable, m_lock, 0x10);
MS2_CHECK_OFFSET(SetItemTable, m_map, 0x40);
MS2_CHECK_OFFSET(SetItemTable, m_byItem, 0x88);
