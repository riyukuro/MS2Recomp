// setiteminfo.h - SetItemInfo (RTTI .?AVSetItemInfo@@, 0x88 bytes, base CPtred): one <set> row of Table/SetItemInfo.xml
// (an equipment set). Header name assumed. Only the members the SetItemTable unit uses are declared; the rest of the
// class belongs to the ?\setiteminfo.cpp unit (not recovered yet).
#pragma once
#include <afx.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class Unk_140165cf0;

class SetItemInfo : public CPtred
{
public:
    SetItemInfo();                              // 0x1407ad240
    virtual ~SetItemInfo();                     // 0x1407adff0 (deleting 0x1407ae0f0)

    bool FUN_1407ad2f0(Unk_140165cf0* pNode);   // read a <set> element; false when it is invalid
    int FUN_1407ad550();                        // the set id
    bool FUN_1407ad600();                       // the flag at +0x80
    void FUN_1407ad670(void* pOut);             // appends the piece item ids to a container
    std::vector<int>& FUN_1407ad710();          // the item ids of the set pieces (+0x20)

private:
    MS2_LAYOUT_FRIEND;
    int m_nId;                                  // +0x18 "id"
    std::vector<int> m_items;                   // +0x20 the item ids of the pieces
    char m_pad_38[0x48];                        // +0x38 an ATL::CAtlMap (the option parts by piece count)
    bool m_b80;                                 // +0x80
    bool m_b81;                                 // +0x81
    char m_pad_82[6];
};
MS2_CHECK_SIZE(SetItemInfo, 0x88);
MS2_CHECK_OFFSET(SetItemInfo, m_items, 0x20);
MS2_CHECK_OFFSET(SetItemInfo, m_b80, 0x80);
