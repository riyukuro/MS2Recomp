// setiteminfo.h - SetItemInfo (RTTI .?AVSetItemInfo@@, 0x88 bytes, base CPtred): one <set> row of Table/SetItemInfo.xml
// (an equipment set). Header name assumed. Recovered with ?\setiteminfo.cpp#1 (the FUN_ names are the ones the
// SetItemTable unit already calls; the other method names are invented).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"

class Unk_140165cf0;
class SetItemOptionPart;

class SetItemInfo : public CPtred
{
public:
    SetItemInfo();                              // 0x1407ad240
    virtual ~SetItemInfo() = default;           // 0x1407adff0 (no vptr store; deleting 0x1407ae0f0)

    bool Load(Unk_140165cf0* pNode);   // read a <set> element; false when it is invalid
    int FUN_1407ad550();                        // the set id
    int HasItem(unsigned nItemId) const;        // 0x1407ad570 the item is one of the pieces
    bool IsShowEffect();                       // showEffectIfItsSetItemMotion (+0x80)
    bool IsDisableTooltip();                    // 0x1407ad620 isDisableTooltip (+0x81)
    size_t GetItemCount() const;                // 0x1407ad640 the number of pieces
    void FUN_1407ad670(ATL::CAtlArray<unsigned>* pOut);     // appends the piece item ids to an array
    std::vector<unsigned>& FUN_1407ad710();     // the item ids of the set pieces (+0x20)
    int AddOptionPart(MS2Ptr<SetItemOptionPart> spPart);    // 0x1407ad730 false for a zero or duplicated part count
    MS2Ptr<SetItemOptionPart> GetOptionPart(unsigned nCount);                               // 0x1407ad880
    void GetOptionParts(unsigned nCount, ATL::CAtlArray<MS2Ptr<SetItemOptionPart> >& parts);  // 0x1407ad900 parts 1..n
    CStringA GetSetEffect(unsigned nCount);         // 0x1407ad990 the last non-empty setEffect of parts 1..n
    CStringA GetGroundAttribute(unsigned nCount);   // 0x1407adaa0 the same for groundAttribute

private:
    MS2_LAYOUT_FRIEND;
    unsigned m_nId;                             // +0x18 "id"
    std::vector<unsigned> m_items;              // +0x20 "itemIDs", the item ids of the pieces
    ATL::CAtlMap<unsigned, MS2Ptr<SetItemOptionPart> > m_parts;     // +0x38 the <part>s by piece count
    bool m_bShowEffect;                         // +0x80 "showEffectIfItsSetItemMotion"
    bool m_bDisableTooltip;                     // +0x81 "isDisableTooltip"
};
MS2_CHECK_SIZE(SetItemInfo, 0x88);
MS2_CHECK_OFFSET(SetItemInfo, m_items, 0x20);
MS2_CHECK_OFFSET(SetItemInfo, m_parts, 0x38);
MS2_CHECK_OFFSET(SetItemInfo, m_bShowEffect, 0x80);
