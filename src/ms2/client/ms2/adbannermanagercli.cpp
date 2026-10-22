// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CAdBannerManagerCli: the client's ad banner registry
// (banner list + type-name table live in CAdBannerManager, ?\adbannerdata.cpp) and its lookups by type / name.
// MS2-UNIT: ?\adbannermanagercli.cpp
// MS2-RANGE: 0x14096b300-0x14096bae0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\adbannermanagercli.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/cadbannermanagercli.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/commonfiles/timeutil.h"

// ---- callees in ?\adbannerdata.cpp and the shared glue ----
int FUN_1406516a0();                                                // the current banner slot
void FUN_14016e060(CAdBannerManager& manager, CInputStream& stream);   // reads the banner list
Unk_AdBannerPtr* FUN_14016e560(Unk_AdBannerArray* pArray, size_t nIndex);    // array element (throws past the end)
AdBannerData* FUN_14016e5a0(Unk_AdBannerPtr* pPtr);                   // the pointee
void FUN_14016e670(Unk_AdBannerArray* pArray, Unk_AdBannerPtr* pItem);       // appends an element
size_t FUN_14016eb40(Unk_AdBannerArray* pArray);                      // element count
struct Unk_AdBannerNameNode;
Unk_AdBannerNameNode* FUN_14016eb60(Unk_AdBannerNameMap* pMap, const int* pKey, unsigned* piBin, unsigned* pnHash, Unk_AdBannerNameNode** ppPrev);
Unk_AdBannerNameNode* FUN_14016e930(Unk_AdBannerNameMap* pMap, const int* pKey, unsigned iBin, unsigned nHash);

// @0x14096b300
CAdBannerManagerCli::CAdBannerManagerCli()
{
}

// @0x14096b350
CAdBannerManagerCli::~CAdBannerManagerCli()
{
}

// @0x14096b390
void CAdBannerManagerCli::FUN_14096b390()
{
}

// @0x14096b3a0
void CAdBannerManagerCli::OnBannerList(CInPacket& packet)
{
    FUN_14016e060(*this, packet);
}

// @0x14096b3e0
Unk_AdBannerPtr CAdBannerManagerCli::FUN_14096b3e0(int nType)
{
    Unk_AdBannerArray own;
    Unk_AdBannerArray any;
    if (FUN_14096b810(nType, own, FUN_1406516a0()) == 1)
        return *FUN_14016e560(&own, 0);
    if (FUN_14096b810(nType, any, -1) == 1)
        return *FUN_14016e560(&any, 0);
    return Unk_AdBannerPtr(0);
}

// @0x14096b540
int CAdBannerManagerCli::FUN_14096b540(int nType, Unk_AdBannerArray& out)
{
    FUN_14096b810(nType, out, FUN_1406516a0());
    FUN_14096b810(nType, out, -1);
    if (out.FUN_14096bab0())
        return 0;
    return 1;
}

// @0x14096b5b0
Unk_AdBannerPtr CAdBannerManagerCli::FUN_14096b5b0(int nType, const CStringW& strName)
{
    Unk_AdBannerArray own;
    Unk_AdBannerArray any;
    FUN_14096b810(nType, own, FUN_1406516a0());
    FUN_14096b810(nType, any, -1);
    for (unsigned i = 0; i < FUN_14016eb40(&own); i++)
    {
        if (FUN_14016e5a0(FUN_14016e560(&own, i))->m_strTypeName.Compare(strName) == 0)
            return *FUN_14016e560(&own, i);
    }
    for (unsigned j = 0; j < FUN_14016eb40(&any); j++)
    {
        if (FUN_14016e5a0(FUN_14016e560(&any, j))->m_strTypeName.Compare(strName) == 0)
            return *FUN_14016e560(&any, j);
    }
    return Unk_AdBannerPtr(0);
}

// @0x14096b810
int CAdBannerManagerCli::FUN_14096b810(int nType, Unk_AdBannerArray& out, int nSlot)
{
    CStringW& strTypeName = m_typeNames.FUN_14096b9c0(nType);
    __int64 now = GetServerTime();
    int nCount = (int)FUN_14016eb40(&m_banners);
    for (int i = 0; i < nCount; i++)
    {
        Unk_AdBannerPtr* pItem = FUN_14016e560(&m_banners, i);
        if (FUN_14016e5a0(pItem)->m_strName.CompareNoCase(strTypeName) == 0 && FUN_14016e5a0(pItem)->m_nBegin <= now
            && FUN_14016e5a0(pItem)->m_nEnd > now && FUN_14016e5a0(pItem)->m_nSlot == nSlot)
            FUN_14016e670(&out, pItem);
    }
    return out.FUN_14096bab0() == 0;
}

// @0x14096b950
Unk_AdBannerPtr::Unk_AdBannerPtr(int)
{
    m_p = 0;
}

// @0x14096b9c0
CStringW& Unk_AdBannerNameMap::FUN_14096b9c0(const int& nKey)
{
    Unk_AdBannerNameNode* pPrev;
    Unk_AdBannerNameNode* pNode;
    unsigned iBin;
    unsigned nHash;
    pNode = FUN_14016eb60(this, &nKey, &iBin, &nHash, &pPrev);
    if (pNode == 0)
        pNode = FUN_14016e930(this, &nKey, iBin, nHash);
    return *(CStringW*)((char*)pNode + 8);
}

// @0x14096bab0
bool Unk_AdBannerArray::FUN_14096bab0() const
{
    return m_nSize == 0;
}
