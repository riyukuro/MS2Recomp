// ugcmapsetiteminfo.h - CUGCMapSetItemInfo / CUGCMapSetItemData / CUGCMapSetItemTable (RTTI names): the UGC "set item"
// table read from Table/UGCMapSetItem.xml (<UGCMapSetItem group minCount itemID itemCount aniIdle aniWork effect
// effectNode/>). Header name assumed. Member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <map>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/os.h"

// One item of a set. RTTI CUGCMapSetItemInfo, 0x40 bytes; vftable 0x142dea658 (1 slot).
class CUGCMapSetItemInfo : public CPtred
{
public:
    CUGCMapSetItemInfo();                   // 0x140b9c920
    virtual ~CUGCMapSetItemInfo();          // 0x140b9c9d0

    int m_nItemCount;                       // +0x18 "itemCount"
    CString m_strAniIdle;                   // +0x20 "aniIdle"
    CString m_strAniWork;                   // +0x28 "aniWork"
    CString m_strEffect;                    // +0x30 "effect"
    CString m_strEffectNode;                // +0x38 "effectNode"
};
MS2_CHECK_SIZE(CUGCMapSetItemInfo, 0x40);
MS2_CHECK_OFFSET(CUGCMapSetItemInfo, m_strAniIdle, 0x20);
MS2_CHECK_OFFSET(CUGCMapSetItemInfo, m_strEffectNode, 0x38);

typedef MS2SvrPtr<CUGCMapSetItemInfo> UGCMapSetItemInfoPtr;

// One set (<UGCMapSetItem>). RTTI CUGCMapSetItemData, 0x38 bytes; vftable 0x142dea668 (1 slot).
class CUGCMapSetItemData : public CPtred
{
public:
    CUGCMapSetItemData();                   // 0x140b9ca50
    virtual ~CUGCMapSetItemData();          // 0x140b9cad0

    int m_nGroup;                           // +0x18 "group"
    std::map<unsigned int, UGCMapSetItemInfoPtr> m_items;   // +0x20 itemID -> item
    int m_nMinCount;                        // +0x30 "minCount"
};
MS2_CHECK_SIZE(CUGCMapSetItemData, 0x38);
MS2_CHECK_OFFSET(CUGCMapSetItemData, m_items, 0x20);
MS2_CHECK_OFFSET(CUGCMapSetItemData, m_nMinCount, 0x30);

typedef MS2SvrPtr<CUGCMapSetItemData> UGCMapSetItemDataPtr;

class CUGCMapSetItemTable;

// This instantiation stores the complete object pointer; DAT_143ab4620.
template <> class TSingleton<CUGCMapSetItemTable>
{
public:
    TSingleton();                           // 0x140ba0a30
    virtual ~TSingleton() { s_instance = 0; }   // 0x140ba0bb0
    static CUGCMapSetItemTable* s_instance;
    static CUGCMapSetItemTable* GetInstance();          // 0x1409eed50
};

// The table. RTTI CUGCMapSetItemTable, 0x90 bytes (new'd by the singleton getter FUN_14149d810); CCacheData +0,
// TSingleton +0x28; vftable 0x142dea5f0 (CCacheData's slot) + 0x142dea600.
class CUGCMapSetItemTable : public CCacheData, public TSingleton<CUGCMapSetItemTable>
{
public:
    typedef ATL::CRBMap<unsigned int, UGCMapSetItemDataPtr> Map;

    CUGCMapSetItemTable();                  // 0x140b9de60
    virtual ~CUGCMapSetItemTable();         // 0x140b9def0

    UGCMapSetItemDataPtr FUN_140b9df60(unsigned int nGroup);        // cached lookup, loads on miss (name invented)
    void FUN_140b9e0a0();                                           // drop the cache
    UGCMapSetItemDataPtr LoadUGCMapSetItem(unsigned int nGroup);        // (re)load the xml, return that group

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;            // +0x30
    Map m_map;                              // +0x60
};
MS2_CHECK_SIZE(CUGCMapSetItemTable, 0x90);
MS2_CHECK_OFFSET(CUGCMapSetItemTable, m_lock, 0x30);
MS2_CHECK_OFFSET(CUGCMapSetItemTable, m_map, 0x60);
