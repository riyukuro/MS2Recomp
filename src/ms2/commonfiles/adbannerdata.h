// adbannerdata.h - AdBannerData (RTTI .?AVAdBannerData@@, CPtred-derived, 0x60 bytes) and CAdBannerManager (RTTI
// .?AVCAdBannerManager@@, 0x68 bytes: the banner list and the banner-type name table). Owning unit: ?\adbannerdata.cpp.
// Header name assumed from the unit path; member names are invented from use. The client-side placeholder
// ms2/placeholder/cadbannermanager.h still describes the same objects for its (older) users.
#pragma once
#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

// The packet stream slots the banner (de)serialisation calls (slot 2 = a 16-bit count).
class Unk_AbOut
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(unsigned short n);
};
class Unk_AbIn
{
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual unsigned short vfunc_2();
};

enum EAdBannerType {};   // the banner type key of m_typeNames (an enum: the exe's map takes the key by const reference)

class AdBannerData : public CPtred
{
public:
    AdBannerData();                                             // 0x14016da90
    virtual ~AdBannerData() = default;                          //  0 0x14016e460 (??_G 0x14016e5f0; no vptr store)

    void Write(Unk_AbOut* pOut);                                // 0x14016db80
    void Read(Unk_AbIn* pIn);                                   // 0x14016dc60

    int m_nType;                                                // +0x18
    CStringW m_strTypeName;                                     // +0x20
    CStringW m_strName;                                         // +0x28
    CStringW m_str30;                                           // +0x30
    CStringW m_str38;                                           // +0x38
    CStringW m_str40;                                           // +0x40
    int m_nSlot;                                                // +0x48 (-1 = any)
    __int64 m_nBegin;                                           // +0x50
    __int64 m_nEnd;                                             // +0x58
};
MS2_CHECK_SIZE(AdBannerData, 0x60);
MS2_CHECK_OFFSET(AdBannerData, m_strTypeName, 0x20);
MS2_CHECK_OFFSET(AdBannerData, m_nSlot, 0x48);
MS2_CHECK_OFFSET(AdBannerData, m_nEnd, 0x58);

// 16-byte intrusive pointer of a boxed AdBannerData (the CPtred header sits 0x18 bytes before the pointee).
class Unk_AdbPtr
{
public:
    Unk_AdbPtr();                                               // 0x14016e320
    Unk_AdbPtr(AdBannerData* p);                                // 0x14016e2f0
    Unk_AdbPtr(int);                                            // 0x14096b950 the null pointer (adbannermanagercli)
    Unk_AdbPtr(const Unk_AdbPtr& o);                            // 0x14016e2b0
    ~Unk_AdbPtr();                                              // 0x14016e430
    Unk_AdbPtr& operator=(const Unk_AdbPtr& o);                 // 0x14016e520
    AdBannerData* get() const;                                  // 0x1409fb8a0 (unit_1409faff0)
    AdBannerData* operator->() const;                           // 0x14016e5a0
private:
    void AddRef() const;
    void AddRefImpl(void*) const;
    static void Reference(AdBannerData* p);
    void Release();
    void ReleaseImpl(void*);
    void* m_00;
    AdBannerData* m_p;
};
MS2_CHECK_SIZE(Unk_AdbPtr, 0x10);

// The banner list (a CAtlArray with the exe's out-of-line copy wrapper).
class Unk_AdbArray : public ATL::CAtlArray<Unk_AdbPtr>
{
public:
    void FUN_14016e150(const ATL::CAtlArray<Unk_AdbPtr>& src);   // 0x14016e150 (Copy)
};

class CAdBannerManager
{
public:
    CAdBannerManager();                                         // 0x14016dd50
    ~CAdBannerManager();                                        // 0x14016df30

    void FUN_14016df70();                                       // forget all banners
    void FUN_14016dfa0(const ATL::CAtlArray<Unk_AdbPtr>& src);  // replace the banners
    void FUN_14016dfd0(Unk_AbOut* pOut);                        // write the banner list

    Unk_AdbArray m_banners;                       // +0x00
    ATL::CAtlMap<EAdBannerType, CStringW> m_typeNames;                    // +0x20 1 cash, 2 merat, 3 pcbang, 4 playgift, 5 title
};
MS2_CHECK_SIZE(CAdBannerManager, 0x68);

class CInputStream;
void FUN_14016e060(CAdBannerManager& manager, CInputStream& stream);   // 0x14016e060 read the banner list (adbannermanagercli)
MS2_CHECK_OFFSET(CAdBannerManager, m_typeNames, 0x20);
