// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). AdBannerData / CAdBannerManager: the ad banner records and the
// banner list with its type-name table, including their packet (de)serialisation.
// MS2-UNIT: ?\adbannerdata.cpp
// MS2-RANGE: 0x14016da90-0x14016fda0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
// MS2-PIN: ??1AdBannerData@@UEAA@XZ 0x14016e460
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\adbannerdata.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"
#include "adbannerdata.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
class COutputStream;

// The packet writer / reader primitives (second flavours of the int / int64 / wide string helpers).
COutputStream & FUN_14070f960(COutputStream &, long);  // C3: the definition's signature
COutputStream & FUN_14070fa20(COutputStream &, unsigned __int64);  // C3: the definition's signature
void FUN_14070fae0(Unk_AbOut* pOut, CStringW* pStr);
void FUN_14070f440(Unk_AbIn* pIn, int* pn);
void FUN_14070f500(Unk_AbIn* pIn, __int64* pn);
void FUN_14070f5f0(Unk_AbIn* pIn, CStringW* pStr);

// ---- the pointer to a boxed banner (CPtred header 0x18 bytes before the pointee) ----

// @0x14016e320
Unk_AdbPtr::Unk_AdbPtr() { m_p = 0; }
// @0x14016e2f0
Unk_AdbPtr::Unk_AdbPtr(AdBannerData* p) { m_p = p; AddRef(); }
// @0x14016e2b0
Unk_AdbPtr::Unk_AdbPtr(const Unk_AdbPtr& o) { m_p = o.m_p; AddRef(); }
// @0x14016e430
Unk_AdbPtr::~Unk_AdbPtr() { Release(); }
// @0x14016e520
Unk_AdbPtr& Unk_AdbPtr::operator=(const Unk_AdbPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
// @0x14016e5a0
AdBannerData* Unk_AdbPtr::get() const { return m_p; }
AdBannerData* Unk_AdbPtr::operator->() const { return m_p; }
void Unk_AdbPtr::AddRef() const
{
    if (m_p)
        AddRefImpl(0);
}
void Unk_AdbPtr::AddRefImpl(void*) const { Reference(m_p); }
void Unk_AdbPtr::Reference(AdBannerData* p) { CPtred::AddRefPtred(p); }
void Unk_AdbPtr::Release()
{
    if (m_p) {
        ReleaseImpl(0);
        m_p = 0;
    }
}
void Unk_AdbPtr::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0) {
        Reference(m_p);
        CPtred::DeletePtred(m_p);
    }
}

// @0x14016e150
void Unk_AdbArray::FUN_14016e150(const ATL::CAtlArray<Unk_AdbPtr>& src)
{
    Copy(src);
}

// ---- the banner record ----

// @0x14016da90
AdBannerData::AdBannerData()
    : m_nType(0), m_strTypeName(L""), m_strName(L""), m_str30(L""), m_str38(L""), m_str40(L""),
      m_nSlot(-1), m_nBegin(0), m_nEnd(0)
{
}

// @0x14016db80
void AdBannerData::Write(Unk_AbOut* pOut)
{
    FUN_14070f960(*(COutputStream *)pOut, m_nType);
    FUN_14070fae0(pOut, &m_strTypeName);
    FUN_14070fae0(pOut, &m_strName);
    FUN_14070fae0(pOut, &m_str30);
    FUN_14070fae0(pOut, &m_str38);
    FUN_14070fae0(pOut, &m_str40);
    FUN_14070f960(*(COutputStream *)pOut, m_nSlot);
    FUN_14070fa20(*(COutputStream *)pOut, m_nBegin);
    FUN_14070fa20(*(COutputStream *)pOut, m_nEnd);
}

// @0x14016dc60
void AdBannerData::Read(Unk_AbIn* pIn)
{
    int nSlot = -1;
    FUN_14070f440(pIn, &m_nType);
    FUN_14070f5f0(pIn, &m_strTypeName);
    FUN_14070f5f0(pIn, &m_strName);
    FUN_14070f5f0(pIn, &m_str30);
    FUN_14070f5f0(pIn, &m_str38);
    FUN_14070f5f0(pIn, &m_str40);
    FUN_14070f440(pIn, &nSlot);
    FUN_14070f500(pIn, &m_nBegin);
    FUN_14070f500(pIn, &m_nEnd);
    m_nSlot = nSlot;
}

// ---- the manager ----

// @0x14016dd50
CAdBannerManager::CAdBannerManager()
{
    {
        CStringW strName(L"cash");
        EAdBannerType nKey = (EAdBannerType)1;
        m_typeNames.SetAt(nKey, strName);
    }
    {
        CStringW strName(L"merat");
        EAdBannerType nKey = (EAdBannerType)2;
        m_typeNames.SetAt(nKey, strName);
    }
    {
        CStringW strName(L"pcbang");
        EAdBannerType nKey = (EAdBannerType)3;
        m_typeNames.SetAt(nKey, strName);
    }
    {
        CStringW strName(L"playgift");
        EAdBannerType nKey = (EAdBannerType)4;
        m_typeNames.SetAt(nKey, strName);
    }
    {
        CStringW strName(L"title");
        EAdBannerType nKey = (EAdBannerType)5;
        m_typeNames.SetAt(nKey, strName);
    }
}

// @0x14016df30
CAdBannerManager::~CAdBannerManager()
{
}

// @0x14016df70
void CAdBannerManager::FUN_14016df70()
{
    m_banners.RemoveAll();
}

// @0x14016dfa0
void CAdBannerManager::FUN_14016dfa0(const ATL::CAtlArray<Unk_AdbPtr>& src)
{
    m_banners.FUN_14016e150(src);
}

// @0x14016dfd0
void CAdBannerManager::FUN_14016dfd0(Unk_AbOut* pOut)
{
    int nCount = (int)m_banners.GetCount();
    pOut->vfunc_2((unsigned short)nCount);
    for (int i = 0; i < nCount; i++)
        m_banners[i].get()->Write(pOut);
}

// @0x14016e060
void CAdBannerManager::FUN_14016e060(Unk_AbIn* pIn)
{
    FUN_14016df70();
    int nCount = pIn->vfunc_2();
    for (int i = 0; i < nCount; i++) {
        Unk_AdbPtr banner(new AdBannerData());
        banner.get()->Read(pIn);
        m_banners.Add(banner);
    }
}

MS2_EMIT_CRT_MEMMOVE_S();
