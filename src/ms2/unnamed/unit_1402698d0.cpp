// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CPremiumProductLimitInfo: the purchase-limit record of one
// premium product (how many were bought, with per-entry expiry). Member and helper names are invented from use.
// MS2-UNIT: unit_1402698d0
// MS2-RANGE: 0x1402698d0-0x140269c30 .text$mn
// MS2-PIN: ??_GCPremiumProductLimitInfo@@UEAAPEAXI@Z 0x14027fdb0
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The guard of a CLockCriticalSection (the same instance as in logstring.cpp; "operator int" is non-zero when locking failed).
class Unk_140163940 {
public:
    Unk_140163940(CLockCriticalSection&);
    ~Unk_140163940();
    operator int() const;
private: void* m_lock;
};
MS2_CHECK_SIZE(Unk_140163940, 8);

// One limit entry (a purchase with its expiry).
class Unk_PplEntry
{
public:
    char m_pad[0x38];
    int m_nProductId;               // +0x38
    int m_nPad3c;
    int m_nCount;                   // +0x40
    int m_nPad44;
    __int64 m_tExpire;              // +0x48
};

// The smart reference to an entry (16 bytes, object at +8).
struct Unk_PplRef
{
    Unk_PplRef(const Unk_PplRef& other);    // 0x14027cc70 (adds a reference)
    ~Unk_PplRef();                          // 0x14027e090
    void* m_unknown;
    Unk_PplEntry* m_p;
};
MS2_CHECK_SIZE(Unk_PplRef, 0x10);
bool FUN_14027ed60(Unk_PplRef* pRef, void* p);                  // pRef->m_p == p
Unk_PplEntry* FUN_14027f310(Unk_PplRef* pRef);                  // the object

// The list of entry references (CAtlList-like: head, tail, free, blocks, count, blockSize).
struct Unk_PplList { char m_data[0x30]; };
Unk_PplList* FUN_14027c5f0(Unk_PplList* pList, int nBlockSize) noexcept;
void FUN_14027de70(Unk_PplList* pList) noexcept;                         // destroy
void FUN_140284b30(Unk_PplList* pList) noexcept;                         // remove all
void* FUN_140281940(Unk_PplList* pList);                        // head position
void* FUN_140281af0(Unk_PplList* pList, void** ppPos);          // advance the position
Unk_PplRef* FUN_140281540(Unk_PplList* pList, void* pos);       // the entry at the position
void FUN_140284f90(Unk_PplList* pList, void* pos);              // remove the entry at the position
void FUN_1402805b0(Unk_PplList* pList, Unk_PplRef* pRef);       // append
__int64 FUN_140869440();                                        // server time

class CPremiumProductLimitInfo : public CPtred
{
public:
    CPremiumProductLimitInfo(int nProductId);                   // 0x1402698d0
    virtual ~CPremiumProductLimitInfo();                        // 0x140269970, ??_G 0x14027fdb0
    void FUN_1402699d0();                                       // drops the expired entries and recounts
    void FUN_140269b50(Unk_PplRef ref);                         // adds an entry of this product

    CLockCriticalSection m_lock;    // +0x18
    int m_nProductId;               // +0x48
    int m_nTotal;                   // +0x4c
    Unk_PplList m_list;             // +0x50
};
MS2_CHECK_SIZE(CPremiumProductLimitInfo, 0x80);

// @0x1402698d0
CPremiumProductLimitInfo::CPremiumProductLimitInfo(int nProductId)
{
    FUN_14027c5f0(&m_list, 10);
    m_nProductId = nProductId;
    m_nTotal = 0;
    FUN_140284b30(&m_list);
}

// @0x140269970
CPremiumProductLimitInfo::~CPremiumProductLimitInfo()
{
    FUN_140284b30(&m_list);
    FUN_14027de70(&m_list);
}

// @0x1402699d0
void CPremiumProductLimitInfo::FUN_1402699d0()
{
    __int64 tNow = FUN_140869440();
    Unk_140163940 guard(m_lock);
    if (guard != 0)
    {
    }
    else
    {
        int nTotal = 0;
        void* pos = FUN_140281940(&m_list);
        while (pos != 0)
        {
            void* posCur = pos;
            FUN_140281af0(&m_list, &pos);
            Unk_PplRef ref(*FUN_140281540(&m_list, posCur));
            if (FUN_14027ed60(&ref, 0) != 0)
            {
                FUN_140284f90(&m_list, posCur);
                continue;
            }
            if (FUN_14027f310(&ref)->m_tExpire < tNow)
            {
                FUN_140284f90(&m_list, posCur);
                continue;
            }
            nTotal = nTotal + FUN_14027f310(&ref)->m_nCount;
        }
        if (nTotal != m_nTotal)
            m_nTotal = nTotal;
    }
}

// @0x140269b50
void CPremiumProductLimitInfo::FUN_140269b50(Unk_PplRef ref)
{
    if (FUN_14027ed60(&ref, 0) != 0)
        return;
    int nProductId = FUN_14027f310(&ref)->m_nProductId;
    if (nProductId != m_nProductId)
        return;
    Unk_140163940 guard(m_lock);
    if (guard != 0)
    {
    }
    else
    {
        FUN_1402805b0(&m_list, &ref);
        m_nTotal = m_nTotal + FUN_14027f310(&ref)->m_nCount;
    }
}
