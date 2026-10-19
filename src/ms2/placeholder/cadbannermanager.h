// cadbannermanager.h - PLACEHOLDER for CAdBannerManager (RTTI .?AVCAdBannerManager@@: CAdBannerManagerCli's non-polymorphic
// base at +0x8, after its TSingleton; 0x68 bytes, the rest of the 0x70-byte CAdBannerManagerCli). NOT an original header.
// Layout (ctor 0x14016dd50, dtor 0x14016df30; both live in ?\adbannerdata.cpp and are declared here only):
//   +0x00 the banner list (Unk_AdBannerArray of MS2Ptr<AdBannerData>), +0x20 the banner-type name table (a CAtlMap<int,
//   CStringW>, 0x48 bytes: 1 cash, 2 merat, 3 pcbang, 4 playgift, 5 title).
#pragma once

#include <afx.h>
#include "ms2/ms2layout.h"

// AdBannerData (CPtred-derived, 0x60 bytes; ?\adbannerdata.cpp) as far as the manager's lookups read it.
class AdBannerData
{
public:
    char m_pad_0[0x20];
    CStringW m_strTypeName;     // +0x20
    CStringW m_strName;         // +0x28 (compared with the type-name table value)
    CStringW m_str30;           // +0x30 (CBannerUrlGetter: copied into its +0x18)
    CStringW m_str38;           // +0x38 (copied into its +0x20)
    CStringW m_str40;           // +0x40 (converted into its +0x10: the banner url)
    int m_nSlot;                // +0x48 (locale / group, -1 = any)
    __int64 m_nBegin;           // +0x50 server time the banner starts
    __int64 m_nEnd;             // +0x58 server time the banner ends
};
MS2_CHECK_SIZE(AdBannerData, 0x60);

// MS2Ptr<AdBannerData> (16 bytes, pointer at +8) as the manager's containers store it; its copy / assign / release are
// exe functions (14016e2b0 / 14016e430).
struct Unk_AdBannerPtr
{
    Unk_AdBannerPtr(int);                         // 0x14096b950: the null pointer
    Unk_AdBannerPtr(const Unk_AdBannerPtr& o);      // 0x14016e2b0
    ~Unk_AdBannerPtr();                         // 0x14016e430
    AdBannerData* get() const;                  // 0x1409fb8a0 (unit_1409faff0)
    AdBannerData* FUN_14016e5a0() const;        // 0x14016e5a0 operator-> (unit_141347b10)
    void* m_pad_0;
    AdBannerData* m_p;
};

// The list of MS2Ptr<AdBannerData> (data, count, max, grow-by). ctor 0x14016e180, dtor 0x14016e3c0.
struct Unk_AdBannerArray
{
    Unk_AdBannerArray();
    ~Unk_AdBannerArray();
    bool FUN_14096bab0() const;     // true when empty
    Unk_AdBannerPtr* m_pData;
    size_t m_nSize;
    size_t m_nMaxSize;
    int m_nGrowBy;
};
MS2_CHECK_SIZE(Unk_AdBannerArray, 0x20);

// CAtlMap<int, CStringW> (m_ppBins, m_nElements, m_nBins, the load factors, ... 0x48 bytes).
struct Unk_AdBannerNameMap
{
    CStringW& FUN_14096b9c0(const int& nKey);     // operator[]: finds or inserts the key
    char m_pad[0x48];
};
MS2_CHECK_SIZE(Unk_AdBannerNameMap, 0x48);

class CAdBannerManager
{
public:
    CAdBannerManager();                 // 0x14016dd50
    ~CAdBannerManager();                // 0x14016df30
    Unk_AdBannerArray m_banners;          // +0x00
    Unk_AdBannerNameMap m_typeNames;      // +0x20
};
MS2_CHECK_SIZE(CAdBannerManager, 0x68);
