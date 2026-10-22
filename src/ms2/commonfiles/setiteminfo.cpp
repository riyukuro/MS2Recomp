// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). SetItemInfo: one <set> row of Table/SetItemInfo.xml (an
// equipment set: its piece item ids and its SetItemOptionPart bonuses by piece count). See setiteminfo.h. The range
// 0x1407af440-0x1407bc4b0 of the queue unit is a second TU (CSetItemManager), in setiteminfo_2.cpp.
// MS2-UNIT: ?\setiteminfo.cpp#1
// MS2-RANGE: 0x1407ad240-0x1407af440 .text$mn
// MS2-PIN: ??1SetItemInfo@@UEAA@XZ 0x1407adff0
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\setiteminfo.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <algorithm>
#include "ms2/commonfiles/setiteminfo.h"
#include "ms2/commonfiles/setitemoptionpart.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

int FUN_1408736d0(Unk_140165cf0* pElem, const char* pszName, bool& bOut);     // bool attribute ("true"/"1")
bool FUN_14028f710(Unk_140165cf0* pElem);                                     // the element is enabled (feature/locale)

// The table log (CLogString) and its fmt wrappers, instantiated in other units.
void* FUN_140166440();
unsigned __int64 FUN_1401859c0(void* pLogger, int nLevel, int nCategory, const wchar_t* pszText);
void FUN_140177a80(void* pLogger, int nLevel, int nCategory, const wchar_t* pszFormat, const unsigned& arg0);
void FUN_1403d7960(void* pLogger, int nLevel, int nCategory, const wchar_t* pszFormat, const unsigned& arg0,
                   const unsigned& arg1);

// @0x1407ad240
SetItemInfo::SetItemInfo() : m_nId(0), m_bShowEffect(false), m_bDisableTooltip(false)
{
}

// @0x1407ad2f0
bool SetItemInfo::Load(Unk_140165cf0* pNode)
{
    FUN_140873220(pNode, "id", m_nId);
    FUN_1408736d0(pNode, "showEffectIfItsSetItemMotion", m_bShowEffect);
    FUN_1408736d0(pNode, "isDisableTooltip", m_bDisableTooltip);
    XmlTokenList(pNode, "itemIDs", m_items);
    for (Unk_140165cf0* pPart = pNode->FUN_140165cf0("part"); pPart != NULL; pPart = pPart->FUN_140168650("part"))
    {
        if (!FUN_14028f710(pPart))
            continue;
        MS2Ptr<SetItemOptionPart> spPart(new SetItemOptionPart);
        if (!spPart->Load(pPart))
            return false;
        if (!AddOptionPart(spPart))
        {
            FUN_140177a80(FUN_140166440(), 1, 0x13,
                          L"\xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4PartCount is Duplicated, optionID={0}",
                          m_nId);
            return false;
        }
    }
    if (m_nId == 0)
    {
        FUN_1401859c0(FUN_140166440(), 1, 0x13, L"\xac12\xc774 0 \xc785\xb2c8\xb2e4.Set ItemData SetID is NULL");
        return false;
    }
    return true;
}

// @0x1407ad550
int SetItemInfo::FUN_1407ad550()
{
    return m_nId;
}
MS2_REPLACE_METHOD(0x1407AD550, SetItemInfo, FUN_1407ad550, 14, 0x72E52537);

// @0x1407ad570
int SetItemInfo::HasItem(unsigned nItemId) const
{
    return std::find(m_items.begin(), m_items.end(), nItemId) != m_items.end();
}
MS2_REPLACE_METHOD(0x1407AD570, SetItemInfo, HasItem, 133, 0x28AE5B7B);

// @0x1407ad600
bool SetItemInfo::IsShowEffect()
{
    return m_bShowEffect;
}
MS2_REPLACE_METHOD(0x1407AD600, SetItemInfo, IsShowEffect, 18, 0xCC6927D5);

// @0x1407ad620
bool SetItemInfo::IsDisableTooltip()
{
    return m_bDisableTooltip;
}
MS2_REPLACE_METHOD(0x1407AD620, SetItemInfo, IsDisableTooltip, 18, 0x910FA2F2);

// @0x1407ad640
size_t SetItemInfo::GetItemCount() const
{
    return m_items.size();
}
MS2_REPLACE_METHOD(0x1407AD640, SetItemInfo, GetItemCount, 31, 0x69CB71D1);

// @0x1407ad670
void SetItemInfo::FUN_1407ad670(ATL::CAtlArray<unsigned>* pOut)
{
    std::vector<unsigned>::iterator it = m_items.begin();
    for (it = m_items.begin(); it != m_items.end(); ++it)
        pOut->Add(*it);
}

// @0x1407ad710
std::vector<unsigned>& SetItemInfo::FUN_1407ad710()
{
    return m_items;
}
MS2_REPLACE_METHOD(0x1407AD710, SetItemInfo, FUN_1407ad710, 15, 0x5731F599);

// @0x1407ad730
int SetItemInfo::AddOptionPart(MS2Ptr<SetItemOptionPart> spPart)
{
    if (spPart.IsNull())
        return 0;
    if (spPart->GetCount() < 1)
    {
        unsigned nCount = spPart->GetCount();
        FUN_1403d7960(FUN_140166440(), 1, 0x13,
                      L"\xd30c\xc77c\xc744 \xc77d\xc744 \xc218 \xc5c6\xc2b5\xb2c8\xb2e4[<ms2> {0}] PartCount Error!, optionID = {1}, PartCount = {2}",
                      m_nId, nCount);
        return 0;
    }
    if (m_parts.Lookup(spPart->GetCount()) != NULL)
        return 0;
    m_parts.SetAt(spPart->GetCount(), spPart);
    return 1;
}

// @0x1407ad880
MS2Ptr<SetItemOptionPart> SetItemInfo::GetOptionPart(unsigned nCount)
{
    MS2Ptr<SetItemOptionPart> spPart(0);
    m_parts.Lookup(nCount, spPart);
    return spPart;
}
MS2_REPLACE_METHOD(0x1407AD880, SetItemInfo, GetOptionPart, 121, 0x1628315A);

// @0x1407ad900
void SetItemInfo::GetOptionParts(unsigned nCount, ATL::CAtlArray<MS2Ptr<SetItemOptionPart> >& parts)
{
    for (unsigned i = 1; i <= nCount; i++)
    {
        MS2Ptr<SetItemOptionPart> spPart(0);
        if (m_parts.Lookup(i, spPart))
            parts.Add(spPart);
    }
}

// @0x1407ad990
CStringA SetItemInfo::GetSetEffect(unsigned nCount)
{
    CStringA strEffect;
    for (unsigned i = 1; i <= nCount; i++)
    {
        MS2Ptr<SetItemOptionPart> spPart;
        if (m_parts.Lookup(i, spPart))
        {
            if (!spPart->FUN_1407bce90().IsEmpty())
                strEffect = spPart->FUN_1407bce90();
        }
    }
    return strEffect;
}
MS2_REPLACE_METHOD(0x1407AD990, SetItemInfo, GetSetEffect, 252, 0xFF761BF2);

// @0x1407adaa0
CStringA SetItemInfo::GetGroundAttribute(unsigned nCount)
{
    CStringA strAttribute;
    for (unsigned i = 1; i <= nCount; i++)
    {
        MS2Ptr<SetItemOptionPart> spPart;
        if (m_parts.Lookup(i, spPart))
        {
            if (!spPart->FUN_1407bceb0().IsEmpty())
                strAttribute = spPart->FUN_1407bceb0();
        }
    }
    return strAttribute;
}
MS2_REPLACE_METHOD(0x1407ADAA0, SetItemInfo, GetGroundAttribute, 252, 0x7C8F1E49);

