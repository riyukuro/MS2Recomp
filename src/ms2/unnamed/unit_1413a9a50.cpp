// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The tail of the CGuideConditionCountInDoorInstallItem
// methods and the whole CGuideConditionFieldId (factory, name, XML loader, check). See ms2/placeholder/cguidecondition.h.
// MS2-UNIT: unit_1413a9a50
// MS2-RANGE: 0x1413a9a50-0x1413a9df0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"

#include <new>
#include <exception>

#include "ms2/placeholder/cguidecondition.h"
#include "ms2/placeholder/citem.h"
#include "ms2/placeholder/citemdata.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2format.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of the exe objects and unrecovered callees --------------------------------------------------------

// CItem::FUN_140527840's record (item.cpp owns the real one).
class Unk_ItemEquipData : public CItemData { };

// The player inventory (global 0x143ab2a90): the items of one inventory tab.
class Unk_GuideInvMgr { public: void FUN_140a60880(int nTab, ATL::CAtlArray<MS2Ptr<CItem> >& arrOut); };
extern Unk_GuideInvMgr DAT_143ab2a90;

// The world manager: the id of the map the player is in.
class Unk_GuideWorld { public: unsigned FUN_141bd3060(); };
Unk_GuideWorld* FUN_1403ed2d0();
extern int DAT_143ab2890;                                   // set while the client is in a test / free-roam field

void FUN_1412751b0(const CStringW& strText, int nColor);    // 0x1412751b0 chat-log line

// @0x1413a9a50
void CGuideConditionCountInDoorInstallItem::vfunc_5()
{
    FUN_1412751b0(StringFormat(L"CGuideConditionCountInDoorInstallItem> itemCount={0}", FUN_1413a9ac0()), 0x14);
}
MS2_REPLACE_METHOD(0x1413A9A50, CGuideConditionCountInDoorInstallItem, vfunc_5, 101, 0x956B69E9);

// @0x1413a9ac0
int CGuideConditionCountInDoorInstallItem::FUN_1413a9ac0()
{
    ATL::CAtlArray<MS2Ptr<CItem> > items;
    DAT_143ab2a90.FUN_140a60880(4, items);
    int nCount = 0;
    int nInstallMask = 6;
    for (unsigned i = 0; i < items.GetCount(); i++)
    {
        if (!items[i]->FUN_140528980())
            continue;
        if ((items[i]->FUN_140527840()->install.space & 6) != 0)
            nCount++;
    }
    return nCount;
}
MS2_REPLACE_METHOD(0x1413A9AC0, CGuideConditionCountInDoorInstallItem, FUN_1413a9ac0, 244, 0xDDECDB81);

// @0x1413a9bc0
ClassObject* CGuideConditionFieldId::CreateObject()
{
    return new CGuideConditionFieldId;
}

// @0x1413a9c20
CStringW CGuideConditionFieldId::GetTypeName()
{
    return L"CGuideConditionFieldId";
}
MS2_REPLACE_METHOD(0x1413A9C20, CGuideConditionFieldId, GetTypeName, 61, 0x959B8408);

// @0x1413a9c70
void CGuideConditionFieldId::vfunc_2(Unk_140165cf0* pElem)
{
    CGuideCondition::vfunc_2(pElem);
    m_n18 = 1;
    m_nRangeBeg = 0;
    m_nRangeEnd = 0;
    FUN_1408731e0(pElem, "rangeBeg", m_nRangeBeg);
    FUN_1408731e0(pElem, "rangeEnd", m_nRangeEnd);
    if (m_n20 == 0 && m_nRangeBeg == 0 && m_nRangeEnd == 0)
        throw std::exception("Invalid FieldId Data");
}
MS2_REPLACE_METHOD(0x1413A9C70, CGuideConditionFieldId, vfunc_2, 195, 0x89E750BE);

// @0x1413a9d40
int CGuideConditionFieldId::vfunc_3()
{
    unsigned nFieldId = FUN_1403ed2d0()->FUN_141bd3060();
    if (DAT_143ab2890 != 0)
        nFieldId = 0;
    if (m_nRangeBeg != 0 || m_nRangeEnd != 0)
    {
        bool bIn;
        if (nFieldId >= m_nRangeBeg && nFieldId <= m_nRangeEnd)
            bIn = true;
        else
            bIn = false;
        return FUN_1413a5600(bIn);
    }
    return FUN_1413a5600(m_n20 == nFieldId ? true : false);
}
MS2_REPLACE_METHOD(0x1413A9D40, CGuideConditionFieldId, vfunc_3, 168, 0x1B17AC86);
