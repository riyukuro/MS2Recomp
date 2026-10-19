// cloadingdescriptiontable.h - PLACEHOLDER for CLoadingDescriptionTable (RTTI .?AVCLoadingDescriptionTable@@, 0x20 bytes). NOT an original header.
// Bases: TSingleton<CLoadingDescriptionTable> at +0x0, CValidData<CLoadingDescriptionTable> at +0x8.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include <afx.h>
#include <atlcoll.h>

// The 16-byte CPtred smart pointer of the description rows (same shape as MS2Ptr<T>; the exe has its own copy per row
// type in ?\loadingdescription.cpp: ctor 0x14144f020, dtor 0x14144f1c0).
template <class T>
class Unk_LdRowPtr
{
public:
    Unk_LdRowPtr() { m_p = 0; }
    Unk_LdRowPtr(int) { m_p = 0; }
    Unk_LdRowPtr(T* p) { m_p = p; AddRef(); }
    Unk_LdRowPtr(const Unk_LdRowPtr& o) { m_p = o.m_p; AddRef(); }
    ~Unk_LdRowPtr() { Release(); }
    Unk_LdRowPtr& operator=(const Unk_LdRowPtr& o) { o.AddRef(); Release(); m_p = o.m_p; return *this; }
    T* operator->() const { return m_p; }
    T* get() const { return m_p; }

private:
    void AddRef() const { if (m_p) AddRefImpl((void*)0); }
    void AddRefImpl(void*) const { Reference(m_p); }
    static void Reference(T* p) { CPtred::AddRefPtred(p); }
    void Release() { if (m_p) { ReleaseImpl((void*)0); m_p = 0; } }
    void ReleaseImpl(void*)
    {
        if (CPtred::ReleasePtred(m_p) == 0) {
            Reference(m_p);
            CPtred::DeletePtred(m_p);
        }
    }

    void* m_00;
    T* m_p;
};

// One <tip> row of Table/loadingDescription.xml (0x38). Member names invented.
class CLoadingDescription : public CPtred
{
public:
    CLoadingDescription();                                  // 0x14144f0a0
    virtual ~CLoadingDescription();                         // 0x14144f220 (deleting dtor 0x14144f390)

    CString m_strId;                                        // +0x18 "id"
    CString m_strStart;                                     // +0x20 "startTime": y-m-d-h-m-s
    CString m_strEnd;                                       // +0x28 "endTime"
    CStringW m_strText;                                     // +0x30 "text" (the \n escape expanded)
};
MS2_CHECK_SIZE(CLoadingDescription, 0x38);

// The loaded description list (0x78): the file cache base, the rows, and the lock the loader and the readers take.
class CLoadingDescriptionCache : public CCacheData
{
public:
    typedef Unk_LdRowPtr<CLoadingDescription> DescPtr;

    CLoadingDescriptionCache();                             // 0x14144f120
    virtual ~CLoadingDescriptionCache();                    // 0x14144f280 (deleting dtor 0x14144f3d0)

    ATL::CAtlArray<DescPtr> m_descs;                        // +0x28
    CLockCriticalSection m_lock;                            // +0x48
};
MS2_CHECK_SIZE(CLoadingDescriptionCache, 0x78);

class CLoadingDescriptionTable : public TSingleton<CLoadingDescriptionTable>,
                                 public CValidData<CLoadingDescriptionTable>
{
public:
    // @0x141495f20
    CLoadingDescriptionTable() { FUN_14144e400(); }
    // @0x141497470
    virtual ~CLoadingDescriptionTable() {}
    int FUN_14144e400();                                    // loads the descriptions (?\loadingdescription.cpp)
    int FUN_14144e500(CString strUnused);                   // 0x14144e500 returns 1 (no caller)
    void Clear();                                           // 0x14144e530
    void Add(CLoadingDescriptionCache::DescPtr spDesc);     // 0x14144e5b0
    CStringW GetRandomTip();                                // 0x14144e640 a text valid now, or ""
    int LoadXml(CString strPath);                           // 0x14144eab0
    static void CheckInit();                                // 0x14144f5a0
    static void SetInit(bool bInit) { s_bInit = bInit; }    // 0x14144fa30
    static bool s_bInit;                                    // DAT_143adc948
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<CLoadingDescriptionCache> m_spData;              // +0x10
};
MS2_CHECK_SIZE(CLoadingDescriptionTable, 0x20);
