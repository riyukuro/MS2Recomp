// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUserLimitGroup: per-user purchase limits, a map from a
// product key to the list of limit entries (the same entries as CPremiumProductLimitInfo's). Names invented from use.
// MS2-UNIT: unit_140269440
// MS2-RANGE: 0x140269440-0x1402698d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cptred.h"
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
bool FUN_14027ed60(Unk_PplRef* pRef, void* p);                  // pRef->m_p == p
Unk_UlgEntry* FUN_14027f310(Unk_PplRef* pRef);                  // the object
__int64 FUN_14027f270(Unk_PplRef* pRef);                        // the raw pointer

// The list of entry references (CAtlList-like, 0x30 bytes).
struct Unk_UlgList { __int64 m_data[6]; };
void* FUN_140281940(Unk_UlgList* pList);                        // head position
void* FUN_140281af0(Unk_UlgList* pList, void** ppPos);          // advance the position
Unk_PplRef* FUN_140281540(Unk_UlgList* pList, void* pos);       // the entry at the position
void FUN_140284f90(Unk_UlgList* pList, void* pos);              // remove the entry at the position
void FUN_1402805b0(Unk_UlgList* pList, Unk_PplRef* pRef);       // append

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
bool FUN_14027eca0(Unk_UlgBucket* pRef, void* p);               // pRef->m_p == p
__int64 FUN_14027f260(Unk_UlgBucket* pRef);                     // the raw pointer
Unk_UlgList* FUN_14027f2d0(Unk_UlgBucket* pRef);                // the object
// The fresh-bucket handle FUN_1401b7b90 returns (8 bytes, returned through a hidden pointer, no dtor).
struct Unk_UlgNew
{
    Unk_UlgNew(const Unk_UlgNew& other);
    void* m_p;
};
Unk_UlgNew FUN_1401b7b90(void* p);                              // makes a fresh bucket
void FUN_140280740(Unk_UlgBucket* pDst, const Unk_UlgNew& src);  // assign

// The map from key to bucket (CAtlMap-like, 0x30 bytes).
struct Unk_UlgMap { __int64 m_data[6]; };
Unk_UlgMap* FUN_14027c890(Unk_UlgMap* pMap, int nBlockSize) noexcept;
void FUN_140284f10(Unk_UlgMap* pMap) noexcept;                  // remove all
void FUN_14027df10(Unk_UlgMap* pMap) noexcept;                  // destroy
void* FUN_140281960(Unk_UlgMap* pMap);                          // first position
void* FUN_140281ce0(Unk_UlgMap* pMap, void** ppPos);            // advance the position
Unk_UlgBucket* FUN_140282210(Unk_UlgMap* pMap, void* pos);      // the bucket at the position
void FUN_140285070(Unk_UlgMap* pMap, void* pos);                // remove at the position
void FUN_140283050(Unk_UlgMap* pMap, __int64 nKey, Unk_UlgBucket* pOut);   // lookup
void FUN_140285850(Unk_UlgMap* pMap, __int64 nKey, Unk_UlgBucket* pBucket); // set

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
    FUN_14027c890(&m_map, 10);
    m_nId = nId;
}

// @0x1402694a0
CUserLimitGroup::~CUserLimitGroup()
{
    FUN_140284f10(&m_map);
    FUN_14027df10(&m_map);
}

// @0x1402694f0
void CUserLimitGroup::FUN_1402694f0(__int64 tNow)
{
    void* pos = FUN_140281960(&m_map);
    while (pos != 0)
    {
        void* posCur = pos;
        FUN_140281ce0(&m_map, &pos);
        Unk_UlgBucket bucket(*FUN_140282210(&m_map, posCur));
        if (FUN_14027eca0(&bucket, 0) != 0)
        {
            FUN_140285070(&m_map, posCur);
            continue;
        }
        void* posIn = FUN_140281940(FUN_14027f2d0(&bucket));
        while (posIn != 0)
        {
            void* posInCur = posIn;
            FUN_140281af0(FUN_14027f2d0(&bucket), &posIn);
            Unk_PplRef ref(*FUN_140281540(FUN_14027f2d0(&bucket), posInCur));
            if (FUN_14027ed60(&ref, 0) != 0)
            {
                FUN_140284f90(FUN_14027f2d0(&bucket), posInCur);
                continue;
            }
            if (FUN_14027f310(&ref)->m_tExpire <= tNow)
            {
                FUN_140284f90(FUN_14027f2d0(&bucket), posInCur);
                continue;
            }
        }
    }
}

// @0x1402696c0
// MS2-FUNCTIONAL: frame slot order only (the exe puts the FUN_1401b7b90 temporary below nKey and the unwind slot above both)
void CUserLimitGroup::FUN_1402696c0(Unk_PplRef ref)
{
    if (FUN_14027ed60(&ref, 0) != 0)
        return;
    __int64 nKey = FUN_14027f310(&ref)->m_nKey;
    Unk_UlgBucket bucket(0);
    FUN_140283050(&m_map, nKey, &bucket);
    if (FUN_14027eca0(&bucket, 0) != 0)
    {
        FUN_140280740(&bucket, FUN_1401b7b90(0));
        FUN_140285850(&m_map, nKey, &bucket);
    }
    FUN_1402805b0(FUN_14027f2d0(&bucket), &ref);
}

// @0x1402697c0
int CUserLimitGroup::FUN_1402697c0(__int64 nKey)
{
    int nTotal = 0;
    Unk_UlgBucket bucket(0);
    FUN_140283050(&m_map, nKey, &bucket);
    if (FUN_14027f260(&bucket) != 0)
    {
        for (void* pos = FUN_140281940(FUN_14027f2d0(&bucket)); pos != 0; FUN_140281af0(FUN_14027f2d0(&bucket), &pos))
        {
            Unk_PplRef ref(*FUN_140281540(FUN_14027f2d0(&bucket), pos));
            if (FUN_14027f270(&ref) != 0)
                nTotal = nTotal + FUN_14027f310(&ref)->m_nCount;
        }
    }
    return nTotal;
}
