// petgroupinfo.h - PetGroupInfo (RTTI) and CPetCollectTable (RTTI): the pet collection groups of Table/petCollectGroup.xml
// (<groupInfo groupId=...>) and the pet -> group indexes the client builds from the pet table. Header name assumed;
// member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <map>
#include <vector>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class Unk_140165cf0;    // xml element (declared where the loader is)

// One <groupInfo> row, 0x20 bytes.
class PetGroupInfo : public CPtred
{
public:
    PetGroupInfo();                                     // 0x140721000
    virtual ~PetGroupInfo();                            // 0x140721040
    bool Load(Unk_140165cf0* pNode);                    // 0x140721070

    int m_nGroupId;                                     // +0x18 "groupId"
};
MS2_CHECK_SIZE(PetGroupInfo, 0x20);

// 16-byte intrusive smart pointer (RTTI TPtr<T>; field 0 unused, field 1 the pointee) to a CPtred-derived object.
template <class T>
class Unk_PetGroupPtr
{
public:
    Unk_PetGroupPtr();
    Unk_PetGroupPtr(int);
    Unk_PetGroupPtr(T* p);                              // adopts the new object (AddRef)
    Unk_PetGroupPtr(const Unk_PetGroupPtr& o);          // copy + AddRef
    ~Unk_PetGroupPtr();
    Unk_PetGroupPtr& operator=(const Unk_PetGroupPtr& o);
    T* get() const;
    T* operator->() const;
    bool operator==(T* p) const;                        // 0x140cb1670 (PetGroupInfoPtr, tabcontentspetcollect.cpp)

private:
    void AddRef() const;
    void Release();
    void AddRefImpl(void*) const;
    void ReleaseImpl(void*);
    static void Ref(CPtred* p);
    void* m_00;
    T* m_p;
};

template <class T> Unk_PetGroupPtr<T>::Unk_PetGroupPtr() { m_p = 0; }
template <class T> Unk_PetGroupPtr<T>::Unk_PetGroupPtr(int) { m_p = 0; }
template <class T> Unk_PetGroupPtr<T>::Unk_PetGroupPtr(T* p) { m_p = p; AddRef(); }
template <class T> Unk_PetGroupPtr<T>::Unk_PetGroupPtr(const Unk_PetGroupPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_PetGroupPtr<T>::~Unk_PetGroupPtr() { Release(); }
template <class T> Unk_PetGroupPtr<T>& Unk_PetGroupPtr<T>::operator=(const Unk_PetGroupPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> T* Unk_PetGroupPtr<T>::get() const { return m_p; }
template <class T> T* Unk_PetGroupPtr<T>::operator->() const { return m_p; }
template <class T> bool Unk_PetGroupPtr<T>::operator==(T* p) const { return m_p == p; }
template <class T> void Unk_PetGroupPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_PetGroupPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> void Unk_PetGroupPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> void Unk_PetGroupPtr<T>::AddRefImpl(void*) const { Ref(m_p); }
template <class T> void Unk_PetGroupPtr<T>::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0) { Ref(m_p); CPtred::DeletePtred(m_p); }
}

typedef Unk_PetGroupPtr<PetGroupInfo> PetGroupInfoPtr;

// RTTI CPetCollectTable, 0x38 bytes.
class CPetCollectTable
{
public:
    CPetCollectTable();                                 // 0x1407210c0
    virtual ~CPetCollectTable();                        // 0x140721130
    bool Load();                                        // 0x140721190
    void Add(unsigned nPetId, int nGroupId);                 // 0x140721410
    std::map<unsigned, unsigned>& PetGroups();                    // 0x140721480 (pet id -> group id)
    std::map<int, std::vector<unsigned> >& GroupPets();      // 0x1407214a0 (group id -> pet ids)
    PetGroupInfoPtr Find(int nGroupId);                 // 0x1407214c0

    std::map<unsigned, unsigned> m_petGroups;                     // +0x08
    std::map<int, std::vector<unsigned> > m_groupPets;       // +0x18
    std::map<int, PetGroupInfoPtr> m_groups;            // +0x28
};
MS2_CHECK_SIZE(CPetCollectTable, 0x38);
