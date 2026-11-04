// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUserLimitGroup: per-user purchase limits, a map from a
// product key to the list of limit entries (the same entries as CPremiumProductLimitInfo's). Names invented from use.
// MS2-UNIT: unit_140269440
// MS2-RANGE: 0x140269440-0x1402698d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/commonstructptred.h"   // C3: CUserLimitGroup, CUserLimitHistory
#include <atlcoll.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

bool FUN_14027ed60(struct Unk_Ref16*, void*);   // C3: was FUN_14027ed60
void* FUN_14027f270(struct Unk_Ref16* pRef);                    // the raw pointer
bool FUN_14027eca0(struct Unk_Ref16*, void*);   // C3: was FUN_14027eca0
void* FUN_14027f260(struct Unk_Ref16* pRef);                    // the raw pointer

typedef ATL::CRBMap<unsigned __int64, TPtrValue<CUserLimitGroup::HistoryList> > Unk_UlgHistMap;
// Defined out of line by the exe (0x140280740); declared only, so this unit does not emit the box's vftable.
template <> TPtrValue<CUserLimitGroup::HistoryList>& TPtrValue<CUserLimitGroup::HistoryList>::operator=(const Unk_GrNewTag&);

// @0x140269440
CUserLimitGroup::CUserLimitGroup(int groupId)
{
    m_groupId = groupId;
}

// @0x1402694a0
CUserLimitGroup::~CUserLimitGroup()
{
    m_histories.RemoveAll();
}

// @0x1402694f0
void CUserLimitGroup::RemoveExpired(__int64 now)
{
    POSITION pos = m_histories.GetHeadPosition();
    while (pos != 0)
    {
        POSITION posCur = pos;
        static_cast<const Unk_UlgHistMap&>(m_histories).GetNext(pos);
        TPtrValue<HistoryList> bucket(static_cast<const Unk_UlgHistMap&>(m_histories).GetValueAt(posCur));
        if (FUN_14027eca0((struct Unk_Ref16*)(&bucket), 0) != 0)
        {
            m_histories.RemoveAt(posCur);
            continue;
        }
        POSITION posIn = bucket->GetHeadPosition();
        while (posIn != 0)
        {
            POSITION posInCur = posIn;
            bucket->GetNext(posIn);
            MS2Ptr<CUserLimitHistory> history(bucket->GetAt(posInCur));
            if (history == 0)
            {
                bucket->RemoveAt(posInCur);
                continue;
            }
            if (history->m_expireTime <= now)
            {
                bucket->RemoveAt(posInCur);
                continue;
            }
        }
    }
}

// @0x1402696c0
void CUserLimitGroup::Add(MS2Ptr<CUserLimitHistory> history)
{
    if (history == 0)
        return;
    __int64 productId = history->m_productId;
    TPtrValue<HistoryList> bucket(0);
    static_cast<const Unk_UlgHistMap&>(m_histories).Lookup(productId, bucket);
    if (FUN_14027eca0((struct Unk_Ref16*)(&bucket), 0) != 0)
    {
        bucket = Unk_GrNewTag(0);
        m_histories.SetAt(productId, bucket);
    }
    bucket->AddTail(history);
}

// @0x1402697c0
int CUserLimitGroup::GetCount(__int64 productId)
{
    int total = 0;
    TPtrValue<HistoryList> bucket(0);
    static_cast<const Unk_UlgHistMap&>(m_histories).Lookup(productId, bucket);
    if (FUN_14027f260((struct Unk_Ref16*)&bucket) != 0)
    {
        for (POSITION pos = bucket->GetHeadPosition(); pos != 0; bucket->GetNext(pos))
        {
            MS2Ptr<CUserLimitHistory> history(bucket->GetAt(pos));
            if (FUN_14027f270((struct Unk_Ref16*)&history) != 0)
                total = total + history->m_count;
        }
    }
    return total;
}
