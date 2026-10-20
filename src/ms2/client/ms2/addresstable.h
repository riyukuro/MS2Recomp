// addresstable.h - CAddressData / CAddressTable (Table/addressName.xml: the town/block names of the maps). Names are
// invented from use. Proven (exe): CAddressData is 0x30 bytes (operator new(0x30)), CPtred at +0 with mapcode at +0x18,
// blockCode at +0x1c and the two Korean names at +0x20/+0x28; the table keeps one CRBMap (block size 10):
// mapcode -> TPtr<TPtredDummy<CRBMap<int, TPtr<CAddressData>>>> (the blocks of that map).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/placeholder/tptreddummy.h"
#include "ms2/placeholder/socketptr.h"

class Unk_140165cf0;                    // xml element (declared where the loader is)

class CAddressData;
// TPtr<CAddressData> (RTTI template name): the 16-byte intrusive pointer, pointer at +8. Spelled Unk_AddressPtr.
class Unk_AddressPtr
{
public:
    Unk_AddressPtr(int);                                    // 0x140979c50
    Unk_AddressPtr(CAddressData* v);                        // 0x140979c70
    Unk_AddressPtr(const Unk_AddressPtr& v);                // 0x140979c10
    Unk_AddressPtr(Unk_AddressPtr&& v);                     // 0x140979be0
    ~Unk_AddressPtr();                                      // 0x140979f90
    Unk_AddressPtr& operator=(const Unk_AddressPtr& v);
    CAddressData* get() const;                              // 0x14097a170
    CAddressData* operator->() const;                       // 0x14097a1d0

private:
    void AddRef() const;                                    // 0x14097bef0
    void AddRefImpl(void*) const;                           // 0x14097bfb0
    void Release();                                         // 0x14097c080
    void ReleaseImpl(void*);                                // 0x14097c150
    static void Reference(CPtred* v);                       // 0x14097bf40
    void* m_pad;                                            // +0x00 (never written)
    CAddressData* m_p;                                      // +0x08
};
MS2_CHECK_SIZE(Unk_AddressPtr, 0x10);

// One <address> row of addressName.xml, 0x30 bytes.
class CAddressData : public CPtred
{
public:
    CAddressData();                                         // 0x140979cf0
    virtual ~CAddressData();                                // 0x14097a020

    int m_nMapCode;                                         // +0x18 "mapcode"
    int m_nBlockCode;                                       // +0x1c "blockCode"
    CStringW m_strBlockName;                                // +0x20 "blockNameKor"
    CStringW m_strBlockModifier;                            // +0x28 "blockModifierKor"
};
MS2_CHECK_SIZE(CAddressData, 0x30);
MS2_CHECK_OFFSET(CAddressData, m_nMapCode, 0x18);
MS2_CHECK_OFFSET(CAddressData, m_strBlockName, 0x20);
MS2_CHECK_OFFSET(CAddressData, m_strBlockModifier, 0x28);

// The blocks of one map: the box the table's pointer owns.
typedef ATL::CRBMap<int, Unk_AddressPtr > Unk_AddressBlockMap;
template<> struct Unk_SocketRef<Unk_AddressBlockMap> {
    static CPtred* Base(Unk_AddressBlockMap* p) {
        CPtred* result;
        if (p == NULL) result = NULL;
        else result = CONTAINING_RECORD(p, TPtredDummy<Unk_AddressBlockMap>, value);
        return result;
    }
    static TPtredDummy<Unk_AddressBlockMap>* New(void*) { return new TPtredDummy<Unk_AddressBlockMap>(); }
    static Unk_AddressBlockMap* Value(CPtred* p) {
        Unk_AddressBlockMap* result;
        if (p == NULL) result = NULL;
        else result = &static_cast<TPtredDummy<Unk_AddressBlockMap>*>(p)->value;
        return result;
    }
    static Unk_AddressBlockMap* Create(void*) { return Value(FUN_1401ba820(New(NULL))); }
};
MS2_SOCKETPTR_BOXED(Unk_AddressBlockMap)
MS2_CHECK_OFFSET(TPtredDummy<Unk_AddressBlockMap>, value, 0x18);

inline Unk_AddressPtr::Unk_AddressPtr(int) { m_p = 0; }
inline Unk_AddressPtr::Unk_AddressPtr(CAddressData* v) { m_p = v; AddRef(); }
inline Unk_AddressPtr::Unk_AddressPtr(const Unk_AddressPtr& v) { m_p = v.m_p; AddRef(); }
inline Unk_AddressPtr::Unk_AddressPtr(Unk_AddressPtr&& v) { m_p = v.m_p; v.m_p = 0; }
inline Unk_AddressPtr::~Unk_AddressPtr() { Release(); }
inline Unk_AddressPtr& Unk_AddressPtr::operator=(const Unk_AddressPtr& v)
{
    v.AddRef();
    Release();
    m_p = v.m_p;
    return *this;
}
inline CAddressData* Unk_AddressPtr::get() const { return m_p; }
inline CAddressData* Unk_AddressPtr::operator->() const { return m_p; }
inline void Unk_AddressPtr::AddRef() const { if (m_p) AddRefImpl(0); }
inline void Unk_AddressPtr::AddRefImpl(void*) const { Reference(m_p); }
inline void Unk_AddressPtr::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
inline void Unk_AddressPtr::ReleaseImpl(void*)
{
    if (FUN_140159bc0(m_p) == 0) {
        Reference(m_p);
        FUN_140159ba0(m_p);
    }
}
inline void Unk_AddressPtr::Reference(CPtred* v) { FUN_14015b020(v); }

class CAddressTable : public CValidData<CAddressTable>
{
public:
    CAddressTable();                                        // 0x140978f40
    virtual ~CAddressTable();                               // 0x140978f80

    static int LoadTable();                                 // 0x140978fd0 Table/addressName.xml
    static Unk_AddressPtr GetAddress(int nMapCode, int nBlockCode);    // 0x1409794b0
    static void CheckInit();                                // 0x14097a370
    static void SetInit(bool b);                            // 0x14097beb0

    // Display texts (invented names): the string table 3 entry of an id, or empty when the row does not exist.
    static CStringW GetText(int nId);                                               // 0x140979570
    static CStringW GetTextChecked(int nId, int nType, int nUnused);                // 0x1409795f0
    static CStringW FormatChecked(int nId, int nType, int nUnused, CStringW strArg);  // 0x1409796e0
    static CStringW GetBuddyText(__int64 nCharId, int nId, int nType, int nUnused);   // 0x1409797c0
    static CStringW FormatBuddy(__int64 nCharId, int nId, int nType, int nUnused, CStringW strArg);  // 0x1409798a0

    static bool s_bInit;                                    // 0x143ab3a68
};
MS2_CHECK_SIZE(CAddressTable, 8);
