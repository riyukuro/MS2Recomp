// unit_1401b6d10.h - CFieldBannerData (RTTI name) and the banner table of Table/banner.xml (?\fieldbannerdata.cpp is
// a guess; the queue unit is unit_1401b6d10). Header name assumed; member and helper names are invented from use.
// Proven (exe): CFieldBannerData is 0x70 bytes (operator new(0x70)), CPtred at +0 and CValidData<CFieldBannerData> at
// +0x18 (the secondary vftable stores in the ctor); the table keeps two CRBMaps (block size 10): banner id -> banner
// and field id -> TPtredDummy<CAtlArray<TPtr<CFieldBannerData>>> (a list of the banners of that field).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/socketptr.h"

class Unk_140165cf0;                    // xml element (declared where the loader is)

class CFieldBannerData;
// TPtr<CFieldBannerData> (RTTI template name): the 16-byte intrusive pointer, pointer at +8. Spelled Unk_BannerPtr.
class Unk_BannerPtr
{
public:
    Unk_BannerPtr(int);                                     // 0x1401b7b00
    Unk_BannerPtr(CFieldBannerData* v);                     // 0x1401b7b20
    Unk_BannerPtr(const Unk_BannerPtr& v);                  // 0x1401b7ac0
    Unk_BannerPtr(Unk_BannerPtr&& v);                       // 0x1401b7a90
    ~Unk_BannerPtr();                                       // 0x1401b7e50
    Unk_BannerPtr& operator=(const Unk_BannerPtr& v);       // 0x1401b7f70
    CFieldBannerData* get() const;                          // 0x1401b8040
    CFieldBannerData* operator->() const;                   // 0x1401b80a0
    bool operator==(const CFieldBannerData* p) const;       // 0x140899ca0 (folded TPtr<T>::operator==)

private:
    void AddRef() const;                                    // 0x1401ba5d0
    void AddRefImpl(void*) const;                           // 0x1401ba670
    void Release();                                         // 0x1401ba740
    void ReleaseImpl(void*);                                // 0x1401ba7d0
    static void Reference(CPtred* v);                       // 0x1401ba620
    void* m_pad;                                            // +0x00 (never written)
    CFieldBannerData* m_p;                                  // +0x08
};
MS2_CHECK_SIZE(Unk_BannerPtr, 0x10);

// One <banner> row of banner.xml, 0x70 bytes.
class CFieldBannerData : public CPtred, public CValidData<CFieldBannerData>
{
public:
    CFieldBannerData();                                     // 0x1401b6d10
    virtual ~CFieldBannerData();                            // 0x1401b6e00

    __int64 GetCurrentHourly();                             // 0x1401b6e90 value of the current hour (name invented)
    __int64 GetHourly(int nHour) const;                           // 0x1401b6ed0 (name invented)
    bool Load(Unk_140165cf0* pNode);                        // 0x1401b6f20 reads the <banner> attributes
    void InitHourly();                                      // 0x1401b70d0 24 zeroed entries
    int ParsePrice(CStringA strPrice);                     // 0x1401b7150 "a,b,c,..." of exactly 24 values

    static int LoadTable();                                // 0x1401b7260 Table/banner.xml into the two maps
    static Unk_BannerPtr GetBanner(int nId);                // 0x1401b7610
    static void GetBannersOfField(int nFieldId, ATL::CRBMap<unsigned, Unk_BannerPtr>& out);    // 0x1401b76c0
    static void CheckInit();                                // 0x1401b8430
    static void SetInit(bool b);                            // 0x1401ba590

    static bool s_bInit;                                    // 0x143aac2f8

    MS2_LAYOUT_FRIEND;
    unsigned m_nId;                                         // +0x20 "id"
    unsigned m_nField;                                      // +0x24 "field"
    int m_nAd;                                              // +0x28 "ad"
    int m_nSize;                                            // +0x2c "size" (default 0x80)
    bool m_bAdmin;                                          // +0x30 "admin"
    CStringA m_strDefault;                                  // +0x38 "default"
    CStringA m_strWebOpenURL;                               // +0x40 "webOpenURL"
    bool m_bManage;                                         // +0x48 "isManage"
    bool m_bVisible;                                        // +0x49 "isVisible" (default true)
    ATL::CAtlArray<__int64> m_hourly;                       // +0x50 24 entries (the "price" list)
};
MS2_CHECK_SIZE(CFieldBannerData, 0x70);
MS2_CHECK_OFFSET(CFieldBannerData, m_nId, 0x20);
MS2_CHECK_OFFSET(CFieldBannerData, m_strDefault, 0x38);
MS2_CHECK_OFFSET(CFieldBannerData, m_bVisible, 0x49);
MS2_CHECK_OFFSET(CFieldBannerData, m_hourly, 0x50);

// The list of the banners of one field: the box the field map's pointer owns.
typedef ATL::CAtlArray<Unk_BannerPtr> Unk_BannerList;
template<> struct Unk_SocketRef<Unk_BannerList> {
    static CPtred* Base(Unk_BannerList* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_BannerList>, value);
        return result;
    }
    static TPtredDummy<Unk_BannerList>* New(void*) { return new TPtredDummy<Unk_BannerList>(); }
    static Unk_BannerList* Value(CPtred* p) {
        Unk_BannerList* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<Unk_BannerList>*>(p)->value;
        return result;
    }
    static Unk_BannerList* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
MS2_SOCKETPTR_BOXED(Unk_BannerList)
MS2_CHECK_SIZE(TPtredDummy<Unk_BannerList>, 0x38);
MS2_CHECK_OFFSET(TPtredDummy<Unk_BannerList>, value, 0x18);

// Unk_BannerPtr (inline members; one COMDAT each, like the exe's TPtr<CFieldBannerData>).
inline Unk_BannerPtr::Unk_BannerPtr(int) { m_p = 0; }
inline Unk_BannerPtr::Unk_BannerPtr(CFieldBannerData* v) { m_p = v; AddRef(); }
inline Unk_BannerPtr::Unk_BannerPtr(const Unk_BannerPtr& v) { m_p = v.m_p; AddRef(); }
inline Unk_BannerPtr::Unk_BannerPtr(Unk_BannerPtr&& v) { m_p = v.m_p; v.m_p = 0; }
inline Unk_BannerPtr::~Unk_BannerPtr() { Release(); }
inline Unk_BannerPtr& Unk_BannerPtr::operator=(const Unk_BannerPtr& v)
{
    v.AddRef();
    Release();
    m_p = v.m_p;
    return *this;
}
inline CFieldBannerData* Unk_BannerPtr::get() const { return m_p; }
inline CFieldBannerData* Unk_BannerPtr::operator->() const { return m_p; }
inline void Unk_BannerPtr::AddRef() const { if (m_p) AddRefImpl(0); }
inline void Unk_BannerPtr::AddRefImpl(void*) const { Reference(m_p); }
inline void Unk_BannerPtr::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
inline void Unk_BannerPtr::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0) {
        Reference(m_p);
        CPtred::DeletePtred(m_p);
    }
}
inline void Unk_BannerPtr::Reference(CPtred* v) { CPtred::AddRefPtred(v); }
