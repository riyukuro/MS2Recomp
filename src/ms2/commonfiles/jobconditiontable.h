// jobconditiontable.h - CJobConditionTable and its NpcJobData rows (RTTI names): the job conditions of the job-change
// npcs, read from Table/jobConditionTable.xml (<condition npcID moveFieldID movePortalID jobCode/>). Header name
// assumed. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cvaliddata.h"

// The creating-constructor tag of the smart pointer below (`Unk_JobPtr<T> p(Unk_JobNewTag(0))`).
#include "ms2/placeholder/socketptr.h"   // C3: Unk_JobNewTag = Unk_SocketNew (one tag type; its ctor 0x1401b7b90 is shared)
typedef Unk_SocketNew Unk_JobNewTag;



CPtred* FUN_1401ba820(CPtred* p);                           // marks a freshly allocated object (sets the count to 1)

// 16-byte intrusive smart pointer (RTTI TPtr<T>; field 0 unused, field 1 the pointee) to a CPtred-derived object.
// Members are defined below the class so that they stay out-of-line COMDATs like the exe's.
template <class T>
class Unk_JobPtr
{
public:
    Unk_JobPtr();
    Unk_JobPtr(int);
    Unk_JobPtr(const Unk_JobNewTag&);                       // fresh object
    Unk_JobPtr(const Unk_JobPtr& o);                        // copy + AddRef
    Unk_JobPtr(Unk_JobPtr&& o);                             // move (a returned local)
    ~Unk_JobPtr();
    Unk_JobPtr& operator=(const Unk_JobPtr& o);
    T* get() const;
    T* operator->() const;

private:
    void AddRef() const;
    void Make();
    void Release();
    static T* Allocate(void*);
    static T* Create(void*);
    void AddRefImpl(void*) const;
    void ReleaseImpl(void*);
    static void Ref(CPtred* p);
    void* m_00;
    T* m_p;
};

template <class T> Unk_JobPtr<T>::Unk_JobPtr() { m_p = 0; }
template <class T> Unk_JobPtr<T>::Unk_JobPtr(int) { m_p = 0; }
template <class T> Unk_JobPtr<T>::Unk_JobPtr(const Unk_JobNewTag&) { m_p = 0; Make(); }
template <class T> Unk_JobPtr<T>::Unk_JobPtr(const Unk_JobPtr& o) { m_p = o.m_p; AddRef(); }
template <class T> Unk_JobPtr<T>::Unk_JobPtr(Unk_JobPtr&& o) { m_p = o.m_p; o.m_p = 0; }
template <class T> Unk_JobPtr<T>::~Unk_JobPtr() { Release(); }
template <class T> Unk_JobPtr<T>& Unk_JobPtr<T>::operator=(const Unk_JobPtr& o)
{
    o.AddRef();
    Release();
    m_p = o.m_p;
    return *this;
}
template <class T> T* Unk_JobPtr<T>::get() const { return m_p; }
template <class T> T* Unk_JobPtr<T>::operator->() const { return m_p; }
template <class T> void Unk_JobPtr<T>::AddRef() const { if (m_p) AddRefImpl(0); }
template <class T> void Unk_JobPtr<T>::Make() { Release(); m_p = Create(0); }
template <class T> void Unk_JobPtr<T>::Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
template <class T> T* Unk_JobPtr<T>::Allocate(void*) { return new T(); }
template <class T> T* Unk_JobPtr<T>::Create(void*) { return static_cast<T*>(FUN_1401ba820(Allocate(0))); }
template <class T> void Unk_JobPtr<T>::Ref(CPtred* p) { CPtred::AddRefPtred(p); }
template <class T> void Unk_JobPtr<T>::AddRefImpl(void*) const { Ref(m_p); }
template <class T> void Unk_JobPtr<T>::ReleaseImpl(void*)
{
    if (CPtred::ReleasePtred(m_p) == 0) { Ref(m_p); CPtred::DeletePtred(m_p); }
}

// The table. RTTI CJobConditionTable, 0x88 bytes: TSingleton +0, CValidData +8, the lock +0x10, the npc id -> row map
// +0x40. Created by CGameApp::InitInstance (?\ms2.cpp).
class CJobConditionTable : public TSingleton<CJobConditionTable>,
                           public CValidData<CJobConditionTable>
{
public:
    // One <condition> row. RTTI CJobConditionTable::NpcJobData, 0x28 bytes, base CPtred.
    class NpcJobData : public CPtred
    {
    public:
        NpcJobData();                       // 0x1406366f0

        unsigned int m_nMoveFieldId;        // +0x18 "moveFieldID"
        int m_nMovePortalId;                // +0x1c "movePortalID"
        int m_nJobCode;                     // +0x20 "jobCode"
    };
    typedef Unk_JobPtr<NpcJobData> NpcJobDataPtr;

    CJobConditionTable();                   // 0x140635ec0
    virtual ~CJobConditionTable();          // 0x140635f70

    int Load();                             // 0x140636000 Table/jobConditionTable.xml
    int LoadFile(const CString& strPath);   // 0x1406360a0 parses the xml into the map
    NpcJobDataPtr GetData(int nNpcId);      // 0x1406362f0 the row of an npc (null when missing)

    static void CheckInit();                // 0x1406369e0
    static void SetInit(bool b);            // 0x1406378b0

    static bool s_bInit;                    // DAT_143ab01a0

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock;            // +0x10
    ATL::CAtlMap<int, NpcJobDataPtr> m_map; // +0x40 npc id -> row
};
MS2_CHECK_SIZE(CJobConditionTable::NpcJobData, 0x28);
MS2_CHECK_OFFSET(CJobConditionTable::NpcJobData, m_nJobCode, 0x20);
MS2_CHECK_SIZE(CJobConditionTable, 0x88);
MS2_CHECK_OFFSET(CJobConditionTable, m_lock, 0x10);
MS2_CHECK_OFFSET(CJobConditionTable, m_map, 0x40);
