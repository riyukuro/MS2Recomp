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
#include <atlcoll.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// One limit entry (a purchase with its expiry); same layout as in unit_1402698d0.
class Unk_UlgEntry
{
public:
    char m_pad[0x38];
    __int64 m_nKey;                 // +0x38
    int m_nCount;                   // +0x40
    int m_nPad44;
    __int64 m_tExpire;              // +0x48
};

// The smart reference to an entry (16 bytes, object at +8); the same instance as in unit_1402698d0.
struct Unk_PplRef
{
    Unk_PplRef(const Unk_PplRef& other);    // 0x14027cc70 (adds a reference)
    ~Unk_PplRef();                          // 0x14027e090
    void* m_unknown;
    Unk_UlgEntry* m_p;
};
MS2_CHECK_SIZE(Unk_PplRef, 0x10);
bool FUN_14027ed60(struct Unk_Ref16*, void*);   // C3: was FUN_14027ed60
void* FUN_14027f270(struct Unk_Ref16* pRef);                    // the raw pointer

// The list of entry references (CAtlList-like, 0x30 bytes).
struct Unk_UlgList { __int64 m_data[6]; };
void* FUN_140281940(Unk_UlgList* pList);                        // head position

// The real types behind the stand-ins: the bucket list and the map.
class CUserLimitHistory;
typedef ATL::CAtlList<MS2Ptr<CUserLimitHistory> > Unk_UlgHistList;
typedef ATL::CRBMap<unsigned __int64, TPtrValue<Unk_UlgHistList> > Unk_UlgHistMap;

// The smart reference to one bucket (an Unk_UlgList on the heap), 16 bytes, object at +8.
struct Unk_UlgBucket
{
    Unk_UlgBucket(void* p);                     // 0x14027ca80
    Unk_UlgBucket(const Unk_UlgBucket& other);  // 0x14027ca40
    ~Unk_UlgBucket();                           // 0x14027dfa0
    Unk_UlgBucket& operator=(const Unk_UlgBucket& other);   // 0x140280740 (as FUN_)
    void* m_unknown;
    Unk_UlgList* m_p;
};
MS2_CHECK_SIZE(Unk_UlgBucket, 0x10);
bool FUN_14027eca0(struct Unk_Ref16*, void*);   // C3: was FUN_14027eca0
void* FUN_14027f260(struct Unk_Ref16* pRef);                    // the raw pointer
Unk_UlgList* FUN_14027f2d0(Unk_UlgBucket* pRef);                // the object
void FUN_1402805b0(Unk_UlgList* pList, Unk_PplRef* pRef);       // append
void FUN_140284f90(Unk_UlgList* pList, void* pos);              // remove the entry at the position
void FUN_140280740(Unk_UlgBucket* pDst, const MS2SvrNewTag& tag);   // assign a fresh bucket

// The map from key to bucket (CAtlMap-like, 0x30 bytes).
struct Unk_UlgMap { __int64 m_data[6]; };
struct Unk_Mv30* FUN_14027c890(struct Unk_Mv30* pMap, void* nBlockSize) noexcept;
void FUN_14027df10(struct Unk_A28* pMap) noexcept;              // destroy

class CUserLimitGroup : public CPtred
{
public:
    CUserLimitGroup(int nId);                                   // 0x140269440
    virtual ~CUserLimitGroup();                                 // 0x1402694a0
    void FUN_1402694f0(__int64 tNow);                           // drops the expired entries and empty buckets
    void FUN_1402696c0(Unk_PplRef ref);                         // files an entry under its key
    int FUN_1402697c0(__int64 nKey);                            // the summed count of one key

    int m_nId;                      // +0x18
    Unk_UlgMap m_map;               // +0x20
};
MS2_CHECK_SIZE(CUserLimitGroup, 0x50);

// @0x140269440
CUserLimitGroup::CUserLimitGroup(int nId)
{
    FUN_14027c890((struct Unk_Mv30*)&m_map, (void*)10);
    m_nId = nId;
}

// @0x1402694a0
CUserLimitGroup::~CUserLimitGroup()
{
    reinterpret_cast<Unk_UlgHistMap*>(&m_map)->RemoveAll();
    FUN_14027df10((struct Unk_A28*)&m_map);
}

// @0x1402694f0
void CUserLimitGroup::FUN_1402694f0(__int64 tNow)
{
    POSITION pos = reinterpret_cast<Unk_UlgHistMap*>(&m_map)->GetHeadPosition();
    while (pos != 0)
    {
        POSITION posCur = pos;
        reinterpret_cast<const Unk_UlgHistMap*>(&m_map)->GetNext(pos);
        Unk_UlgBucket bucket(reinterpret_cast<const Unk_UlgBucket&>(reinterpret_cast<const Unk_UlgHistMap*>(&m_map)->GetValueAt(posCur)));
        if (FUN_14027eca0((struct Unk_Ref16*)(&bucket), 0) != 0)
        {
            reinterpret_cast<Unk_UlgHistMap*>(&m_map)->RemoveAt(posCur);
            continue;
        }
        void* posIn = FUN_140281940(FUN_14027f2d0(&bucket));
        while (posIn != 0)
        {
            void* posInCur = posIn;
            reinterpret_cast<Unk_UlgHistList*>(FUN_14027f2d0(&bucket))->GetNext(reinterpret_cast<POSITION&>(posIn));
            Unk_PplRef ref(reinterpret_cast<const Unk_PplRef&>(reinterpret_cast<Unk_UlgHistList*>(FUN_14027f2d0(&bucket))->GetAt(reinterpret_cast<POSITION>(posInCur))));
            if (FUN_14027ed60((struct Unk_Ref16*)(&ref), 0) != 0)
            {
                FUN_140284f90(FUN_14027f2d0(&bucket), posInCur);
                continue;
            }
            if (((Unk_UlgEntry*)reinterpret_cast<MS2Ptr<CPtred>*>(&ref)->operator CPtred*())->m_tExpire <= tNow)
            {
                FUN_140284f90(FUN_14027f2d0(&bucket), posInCur);
                continue;
            }
        }
    }
}

// @0x1402696c0
void CUserLimitGroup::FUN_1402696c0(Unk_PplRef ref)
{
    if (FUN_14027ed60((struct Unk_Ref16*)(&ref), 0) != 0)
        return;
    __int64 nKey = ((Unk_UlgEntry*)reinterpret_cast<MS2Ptr<CPtred>*>(&ref)->operator CPtred*())->m_nKey;
    Unk_UlgBucket bucket(0);
    reinterpret_cast<const Unk_UlgHistMap*>(&m_map)->Lookup(nKey, reinterpret_cast<TPtrValue<Unk_UlgHistList>&>(bucket));
    if (FUN_14027eca0((struct Unk_Ref16*)(&bucket), 0) != 0)
    {
        FUN_140280740(&bucket, MS2SvrNewTag(0));
        reinterpret_cast<Unk_UlgHistMap*>(&m_map)->SetAt(nKey, reinterpret_cast<const TPtrValue<Unk_UlgHistList>&>(bucket));
    }
    FUN_1402805b0(FUN_14027f2d0(&bucket), &ref);
}

// @0x1402697c0
int CUserLimitGroup::FUN_1402697c0(__int64 nKey)
{
    int nTotal = 0;
    Unk_UlgBucket bucket(0);
    reinterpret_cast<const Unk_UlgHistMap*>(&m_map)->Lookup(nKey, reinterpret_cast<TPtrValue<Unk_UlgHistList>&>(bucket));
    if (FUN_14027f260((struct Unk_Ref16*)&bucket) != 0)
    {
        for (void* pos = FUN_140281940(FUN_14027f2d0(&bucket)); pos != 0; reinterpret_cast<Unk_UlgHistList*>(FUN_14027f2d0(&bucket))->GetNext(reinterpret_cast<POSITION&>(pos)))
        {
            Unk_PplRef ref(reinterpret_cast<const Unk_PplRef&>(reinterpret_cast<Unk_UlgHistList*>(FUN_14027f2d0(&bucket))->GetAt(reinterpret_cast<POSITION>(pos))));
            if (FUN_14027f270((struct Unk_Ref16*)&ref) != 0)
                nTotal = nTotal + ((Unk_UlgEntry*)reinterpret_cast<MS2Ptr<CPtred>*>(&ref)->operator CPtred*())->m_nCount;
        }
    }
    return nTotal;
}
