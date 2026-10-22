// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The hyperlink data of chat/mail text: see itemlinkdata.h.
// MS2-UNIT: ?\itemlinkdata.cpp
// MS2-RANGE: 0x1405bd5b0-0x1405bea40 .text$mn
// MS2-PIN: ??1CHyperLinkData@@UEAA@XZ 0x1405be190
// MS2-PIN: ??1CItemLinkData@@UEAA@XZ 0x1405be1b0
// MS2-PIN: ??1CLinkAchieveID@@UEAA@XZ 0x1405be1d0
// MS2-PIN: ??1CLinkBlackMarketSN@@UEAA@XZ 0x1405be1f0
// MS2-PIN: ??1CLinkCashSaleProduct@@UEAA@XZ 0x1405be210
// MS2-PIN: ??1CLinkItemGUID@@UEAA@XZ 0x1405be230
// MS2-PIN: ??1CLinkItemID@@UEAA@XZ 0x1405be250
// MS2-PIN: ??1CLinkMeratMarketProduct@@UEAA@XZ 0x1405be270
// MS2-PIN: ??1CLinkSerialID@@UEAA@XZ 0x1405be2a0
// MS2-PIN: ??_GCHyperLinkData@@UEAAPEAXI@Z 0x1405be340
// MS2-PIN: ??_GCItemLinkData@@UEAAPEAXI@Z 0x1405be380
// MS2-PIN: ??_GCLinkAchieveID@@UEAAPEAXI@Z 0x1405be3c0
// MS2-PIN: ??_GCLinkBlackMarketSN@@UEAAPEAXI@Z 0x1405be400
// MS2-PIN: ??_GCLinkCashSaleProduct@@UEAAPEAXI@Z 0x1405be440
// MS2-PIN: ??_GCLinkItemGUID@@UEAAPEAXI@Z 0x1405be480
// MS2-PIN: ??_GCLinkItemID@@UEAAPEAXI@Z 0x1405be4c0
// MS2-PIN: ??_GCLinkMeratMarketProduct@@UEAAPEAXI@Z 0x1405be500
// MS2-PIN: ??_GCLinkSerialID@@UEAAPEAXI@Z 0x1405be540
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\itemlinkdata.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "itemlinkdata.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- out-of-unit callees ----
void FUN_14028cf00(const CStringW& strText, ATL::CAtlArray<CStringW>& arrOut, const CStringW& strOpen, const CStringW& strClose);   // splits by the delimiters
CString FUN_14016a600(const wchar_t* sz, int n);                                // wide to narrow
void FUN_1402a5010(const CString& str, ATL::CAtlArray<__int64>* pOut, const char* pszSep);   // numbers of a "," list
CString FUN_1407194b0(__int64 n);                                               // number to string

// the per-type parsers (defined below)
CHyperLinkData* FUN_1405bda30(ATL::CAtlArray<__int64>& arrValues);
CHyperLinkData* FUN_1405bdba0(ATL::CAtlArray<__int64>& arrValues);
CHyperLinkData* FUN_1405bdce0(ATL::CAtlArray<__int64>& arrValues);
CHyperLinkData* FUN_1405bde50(ATL::CAtlArray<__int64>& arrValues);
CHyperLinkData* FUN_1405bdfb0(ATL::CAtlArray<__int64>& arrValues);

// @0x1405bd5b0
CHyperLinkData::CHyperLinkData(long nType)
{
    m_nType = nType;
}

// @0x1405bd600
long CHyperLinkData::GetType() const
{
    return m_nType;
}

// @0x1405bd620: the link types the text parser can build (achievement and cash sale links are not)
static int FUN_1405bd620(int nType)
{
    if (nType == 4)
        return 0;
    if (nType == 5)
        return 0;
    return 1;
}

// @0x1405bd650
CLinkAchieveID::CLinkAchieveID() : CHyperLinkData(4)
{
}

// @0x1405bd690
CLinkCashSaleProduct::CLinkCashSaleProduct() : CHyperLinkData(5)
{
}

// @0x1405bd6d0
CItemLinkData::CItemLinkData(long nType, __int64 nOwnerId) : CHyperLinkData(nType)
{
    m_nOwnerId = nOwnerId;
}

// MS2-FUNCTIONAL: frame/temporary slot order of the CString delimiters and the AssignRaw chain differs
// @0x1405bd720
void FUN_1405bd720(const CStringW& strText, ATL::CAtlArray<MS2Ptr<CHyperLinkData> >& arrOut)
{
    ATL::CAtlArray<CStringW> arrTags;
    CStringW strClose(L">");
    CStringW strOpen(L"<");
    FUN_14028cf00(strText, arrTags, strOpen, strClose);
    for (unsigned i = 0; i < arrTags.GetCount(); i++)
    {
        CString strTag = FUN_14016a600(arrTags[i], 0);
        if (strTag.IsEmpty())
            continue;
        ATL::CAtlArray<__int64> arrValues;
        FUN_1402a5010(strTag, &arrValues, ",");
        if (arrValues.GetCount() > 3)
        {
            int nType = (int)arrValues[2];
            if (FUN_1405bd620(nType) == 0)
                continue;
            MS2Ptr<CHyperLinkData> spLink(0);
            if (nType == 2)
                spLink.AssignRaw(FUN_1405bda30(arrValues));
            else if (nType == 3)
                spLink.AssignRaw(FUN_1405bdba0(arrValues));
            else if (nType == 1)
                spLink.AssignRaw(FUN_1405bdce0(arrValues));
            else if (nType == 6)
                spLink.AssignRaw(FUN_1405bde50(arrValues));
            else if (nType == 7)
                spLink.AssignRaw(FUN_1405bdfb0(arrValues));
            if (spLink.get() != 0)
                arrOut.Add(spLink);
        }
    }
}

// @0x1405bd9a0
__int64 CItemLinkData::GetOwnerId() const
{
    return m_nOwnerId;
}

// @0x1405bd9c0
CLinkItemID::CLinkItemID(__int64 nOwnerId, int nItemId, int nRarity) : CItemLinkData(2, nOwnerId)
{
    m_nItemId = nItemId;
    m_nRarity = nRarity;
}

// @0x1405bda30
CHyperLinkData* FUN_1405bda30(ATL::CAtlArray<__int64>& arrValues)
{
    if (arrValues.GetCount() != 6)
        return 0;
    __int64 nOwner = arrValues[1];
    int nItemId = (int)arrValues[4];
    int nRarity = (int)arrValues[5];
    return new CLinkItemID(nOwner, nItemId, nRarity);
}

// @0x1405bdb00
int CLinkItemID::GetItemId() const
{
    return m_nItemId;
}

// @0x1405bdb20
unsigned short CLinkItemID::FUN_1405bdb20() const
{
    return (unsigned short)m_nRarity;
}

// @0x1405bdb40
CLinkItemGUID::CLinkItemGUID(__int64 nOwnerId, __int64 nGuid) : CItemLinkData(3, nOwnerId)
{
    m_nGuid = nGuid;
}

// @0x1405bdba0
CHyperLinkData* FUN_1405bdba0(ATL::CAtlArray<__int64>& arrValues)
{
    if (arrValues.GetCount() != 6)
        return 0;
    __int64 nOwner = arrValues[1];
    __int64 nGuid = arrValues[3];
    return new CLinkItemGUID(nOwner, nGuid);
}

// @0x1405bdc50
__int64 CLinkItemGUID::GetGuid() const
{
    return m_nGuid;
}

// @0x1405bdc70
CLinkSerialID::CLinkSerialID(__int64 nOwnerId, int nSerialLow, int nSerialHigh) : CItemLinkData(1, nOwnerId)
{
    m_nLow = nSerialLow;
    m_nHigh = nSerialHigh;
}

// @0x1405bdce0
CHyperLinkData* FUN_1405bdce0(ATL::CAtlArray<__int64>& arrValues)
{
    if (arrValues.GetCount() != 6)
        return 0;
    __int64 nOwner = arrValues[1];
    int nLow = (int)arrValues[4];
    int nHigh = (int)arrValues[5];
    return new CLinkSerialID(nOwner, nLow, nHigh);
}

// @0x1405bddb0
int CLinkSerialID::GetLow() const
{
    return m_nLow;
}

// @0x1405bddd0
int CLinkSerialID::GetHigh() const
{
    return m_nHigh;
}

// @0x1405bddf0
CLinkBlackMarketSN::CLinkBlackMarketSN(__int64 nOwnerId, __int64 nSerial) : CItemLinkData(6, nOwnerId)
{
    m_nSerial = nSerial;
}

// @0x1405bde50
CHyperLinkData* FUN_1405bde50(ATL::CAtlArray<__int64>& arrValues)
{
    if (arrValues.GetCount() != 6)
        return 0;
    __int64 nOwner = arrValues[1];
    __int64 nSerial = arrValues[3];
    return new CLinkBlackMarketSN(nOwner, nSerial);
}

// @0x1405bdf00
__int64 CLinkBlackMarketSN::GetSerial() const
{
    return m_nSerial;
}

// @0x1405bdf20
CLinkMeratMarketProduct::CLinkMeratMarketProduct(__int64 nOwnerId, const CString& strName, bool bFlag, int nCount) : CItemLinkData(7, nOwnerId), m_strName(strName)
{
    m_bFlag = bFlag;
    m_nCount = nCount;
}

// MS2-FUNCTIONAL: frame 0x10 larger (bool temp slots)
// @0x1405bdfb0
CHyperLinkData* FUN_1405bdfb0(ATL::CAtlArray<__int64>& arrValues)
{
    if (arrValues.GetCount() < 8)
        return 0;
    __int64 nOwner = arrValues[1];
    CString strName = FUN_1407194b0(arrValues[3]);
    bool bFlag = arrValues[4] == 1;
    int nCount = (int)arrValues[7];
    return new CLinkMeratMarketProduct(nOwner, strName, bFlag, nCount);
}

