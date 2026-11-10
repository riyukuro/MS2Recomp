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
int GetLanguage();                                                // the current banner slot

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
    ReadBanners(*this, packet);
}

// @0x14096b3e0
Unk_AdbPtr CAdBannerManagerCli::FUN_14096b3e0(int nType)
{
    ATL::CAtlArray<Unk_AdbPtr> own;
    ATL::CAtlArray<Unk_AdbPtr> any;
    if (CollectActiveBanners((EAdBannerType)nType, own, GetLanguage()) == 1)
        return own[0];
    if (CollectActiveBanners((EAdBannerType)nType, any, -1) == 1)
        return any[0];
    return Unk_AdbPtr(0);
}

// @0x14096b540
int CAdBannerManagerCli::FUN_14096b540(int nType, ATL::CAtlArray<Unk_AdbPtr>& out)
{
    CollectActiveBanners((EAdBannerType)nType, out, GetLanguage());
    CollectActiveBanners((EAdBannerType)nType, out, -1);
    if (out.IsEmpty())
        return 0;
    return 1;
}

// @0x14096b5b0
Unk_AdbPtr CAdBannerManagerCli::FindBannerByName(int nType, const CStringW& strName)
{
    ATL::CAtlArray<Unk_AdbPtr> own;
    ATL::CAtlArray<Unk_AdbPtr> any;
    CollectActiveBanners((EAdBannerType)nType, own, GetLanguage());
    CollectActiveBanners((EAdBannerType)nType, any, -1);
    for (unsigned i = 0; i < own.GetCount(); i++)
    {
        if (own[i]->m_strTypeName.Compare(strName) == 0)
            return own[i];
    }
    for (unsigned j = 0; j < any.GetCount(); j++)
    {
        if (any[j]->m_strTypeName.Compare(strName) == 0)
            return any[j];
    }
    return Unk_AdbPtr(0);
}

// @0x14096b810
int CAdBannerManagerCli::CollectActiveBanners(EAdBannerType nType, ATL::CAtlArray<Unk_AdbPtr>& out, int nSlot)
{
    CStringW& strTypeName = m_typeNames[nType];
    __int64 now = GetServerTime();
    int nCount = (int)m_banners.GetCount();
    for (int i = 0; i < nCount; i++)
    {
        Unk_AdbPtr* pItem = &m_banners[i];
        if ((*pItem)->m_strName.CompareNoCase(strTypeName) == 0 && (*pItem)->m_nBegin <= now
            && (*pItem)->m_nEnd > now && (*pItem)->m_nSlot == nSlot)
            out.Add(*pItem);
    }
    return out.IsEmpty() == 0;
}

// @0x14096b950
Unk_AdbPtr::Unk_AdbPtr(int)
{
    m_p = 0;
}
