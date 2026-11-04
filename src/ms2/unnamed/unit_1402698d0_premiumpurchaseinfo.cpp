// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPremiumProductLimitInfo: the purchase-limit record of one
// premium product (how many were bought, with per-entry expiry). Member and helper names are invented from use.
// MS2-UNIT: unit_1402698d0
// MS2-RANGE: 0x1402698d0-0x140269c30 .text$mn
// MS2-PIN: ??_GCPremiumProductLimitInfo@@UEAAPEAXI@Z 0x14027fdb0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/commonstructptred.h"   // C3: CUserLimitHistory
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

__int64 GetServerTime();                                        // server time

class CPremiumProductLimitInfo : public CPtred
{
public:
    CPremiumProductLimitInfo(int nProductId);                   // 0x1402698d0
    virtual ~CPremiumProductLimitInfo();                        // 0x140269970, ??_G 0x14027fdb0
    void FUN_1402699d0();                                       // drops the expired entries and recounts
    void FUN_140269b50(MS2Ptr<CUserLimitHistory> ref);                         // adds an entry of this product

    CLockCriticalSection m_lock;    // +0x18
    int m_nProductId;               // +0x48
    int m_nTotal;                   // +0x4c
    ATL::CAtlList<MS2Ptr<CUserLimitHistory> > m_list;   // +0x50
};
MS2_CHECK_SIZE(CPremiumProductLimitInfo, 0x80);

// @0x1402698d0
CPremiumProductLimitInfo::CPremiumProductLimitInfo(int nProductId)
{
    m_nProductId = nProductId;
    m_nTotal = 0;
    m_list.RemoveAll();
}

// @0x140269970
CPremiumProductLimitInfo::~CPremiumProductLimitInfo()
{
    m_list.RemoveAll();
}

// @0x1402699d0
void CPremiumProductLimitInfo::FUN_1402699d0()
{
    __int64 tNow = GetServerTime();
    Unk_LockGuard guard(m_lock);   // clockcriticalsection.h
    if (guard != 0)
    {
    }
    else
    {
        int nTotal = 0;
        POSITION pos = m_list.GetHeadPosition();
        while (pos != 0)
        {
            POSITION posCur = pos;
            m_list.GetNext(pos);
            MS2Ptr<CUserLimitHistory> ref(m_list.GetAt(posCur));
            if (ref == 0)
            {
                m_list.RemoveAt(posCur);
                continue;
            }
            if (ref->m_expireTime < tNow)
            {
                m_list.RemoveAt(posCur);
                continue;
            }
            nTotal = nTotal + ref->m_count;
        }
        if (nTotal != m_nTotal)
            m_nTotal = nTotal;
    }
}

// @0x140269b50
void CPremiumProductLimitInfo::FUN_140269b50(MS2Ptr<CUserLimitHistory> ref)
{
    if (ref == 0)
        return;
    int nProductId = (int)ref->m_productId;
    if (nProductId != m_nProductId)
        return;
    Unk_LockGuard guard(m_lock);   // clockcriticalsection.h
    if (guard != 0)
    {
    }
    else
    {
        m_list.AddTail(ref);
        m_nTotal = m_nTotal + ref->m_count;
    }
}
