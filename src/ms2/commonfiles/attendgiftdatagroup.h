// attendgiftdatagroup.h - AttendGiftDataGroup, AttendGiftData and AttendGiftDataTable (RTTI names): the attendance gift
// table read from Table/AttendGiftData.xml (<AttendGiftData giftID=..><group><v .../></group></AttendGiftData>). Header
// name assumed; member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/itemgift.h"

class Unk_140165cf0;    // xml element (declared where the loader is)

// 16-byte intrusive smart pointer (RTTI TPtr<T>; field 0 unused, field 1 the pointee) to a CPtred-derived object.
template <class T>
class Unk_AttendPtr
{
public:
    Unk_AttendPtr();
    Unk_AttendPtr(int);
    Unk_AttendPtr(T* p);                                // adopts the new object (AddRef)
    Unk_AttendPtr(const Unk_AttendPtr& o);              // copy + AddRef
    Unk_AttendPtr(Unk_AttendPtr&& o);                   // move
    ~Unk_AttendPtr();
    Unk_AttendPtr& operator=(const Unk_AttendPtr& o);
    T* get() const;
    T* operator->() const;

private:
    void AddRef() const;
    void Release();
    void AddRefImpl(void*) const;
    void ReleaseImpl(void*);
    static void Ref(CPtred* p);
    void* m_00;
    T* m_p;
};

template <class T> Unk_AttendPtr<T>::Unk_AttendPtr() { m_p = 0; }
template <class T> Unk_AttendPtr<T>::Unk_AttendPtr(int) { m_p = 0; }
template <class T> Unk_AttendPtr<T>::Unk_AttendPtr(T* p) { m_p = p; AddRef(); }
template <class T> Unk_AttendPtr<T>::Unk_AttendPtr(const Unk_AttendPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_AttendPtr<T>::Unk_AttendPtr(Unk_AttendPtr&& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> Unk_AttendPtr<T>::~Unk_AttendPtr() { Release(); }
template <class T> Unk_AttendPtr<T>& Unk_AttendPtr<T>::operator=(const Unk_AttendPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> T* Unk_AttendPtr<T>::get() const { return m_p; }
template <class T> T* Unk_AttendPtr<T>::operator->() const { return m_p; }
template <class T> void Unk_AttendPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_AttendPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> void Unk_AttendPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> void Unk_AttendPtr<T>::AddRefImpl(void*) const { Ref(m_p); }
template <class T> void Unk_AttendPtr<T>::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0) { Ref(m_p); CPtred::DeletePtred(m_p); }
}

// One <group>, 0x30 bytes: the reward items of its <v> rows.
class AttendGiftDataGroup : public CPtred
{
public:
    AttendGiftDataGroup();                                          // 0x1401adea0
    bool Load(Unk_140165cf0* pNode, const CString& strContext);     // 0x1401adef0

    std::vector<Unk_AttendPtr<ItemGift> > m_gifts;                  // +0x18
};
MS2_CHECK_SIZE(AttendGiftDataGroup, 0x30);

typedef Unk_AttendPtr<AttendGiftDataGroup> AttendGiftDataGroupPtr;

// One <AttendGiftData>, 0x38 bytes.
class AttendGiftData : public CPtred
{
public:
    AttendGiftData();                                               // 0x1401adff0
    bool Load(Unk_140165cf0* pNode);                                // 0x1401ae040
    unsigned GetId();                                               // 0x1401ae1c0
    unsigned GetGroupCount();                                       // 0x1401ae1e0
    AttendGiftDataGroupPtr GetGroup(unsigned nIndex) const;         // 0x1401ae210

    unsigned m_nGiftId;                                             // +0x18 "giftID"
    std::vector<AttendGiftDataGroupPtr> m_groups;                   // +0x20
};
MS2_CHECK_SIZE(AttendGiftData, 0x38);

typedef Unk_AttendPtr<AttendGiftData> AttendGiftDataPtr;

// RTTI AttendGiftDataTable, 0x18 bytes.
class AttendGiftDataTable : public TSingleton<AttendGiftDataTable>
{
public:
    AttendGiftDataTable();                                          // 0x1401ae2a0
    bool Load();                                                    // 0x1401ae2f0
    AttendGiftDataPtr Find(unsigned nGiftId);                       // 0x1401ae630

    std::map<unsigned, AttendGiftDataPtr> m_data;                   // +0x08
};
MS2_CHECK_SIZE(AttendGiftDataTable, 0x18);
