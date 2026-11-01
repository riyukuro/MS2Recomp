// RoomTimerManager from RTTI; field and helper names inferred from packet handling.
#pragma once
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/os.h"
#include "uitimergaugedialog.h"
#include <map>
class Unk_RoomPacketPrefix { public: virtual void vfunc_0(); };
// The input interface is the secondary base at +8, so virtual dispatch remains dynamic.
class Unk_RoomPacket : public Unk_RoomPacketPrefix, public Unk_OSInput {};
MS2_CHECK_SIZE(Unk_RoomPacket,0x10);

template<class T> class Unk_RoomPtr {
public:
    Unk_RoomPtr(int) : m_p(0) {}
    Unk_RoomPtr(T* p) : m_p(p) { AddRef(); }
    Unk_RoomPtr() : m_p(0) {}
    ~Unk_RoomPtr() { Release(); }
    Unk_RoomPtr& operator=(const Unk_RoomPtr& p) { p.AddRef(); Release(); m_p=p.m_p; return *this; }
    Unk_RoomPtr& operator=(int) { Release(); return *this; }
    bool operator==(T* p) const { return m_p==p; }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
private:
    void AddRef() const { if(m_p) ReferenceImpl((void*)0); }
    static void Reference(T* p) { CPtred::AddRefPtred(p); }
    void ReferenceImpl(void*) const { Reference(m_p); }
    void Release() { if(m_p) { ReleaseImpl((void*)0); m_p=0; } }
    void ReleaseImpl(void*) { if(CPtred::ReleasePtred(m_p)==0) { Reference(m_p); CPtred::DeletePtred(m_p); } }
    void* m_0; T* m_p;
};
MS2_CHECK_SIZE(Unk_RoomPtr<UITimerBase>,0x10);
class RoomTimerManager : public TSingleton<RoomTimerManager> {
public:
    RoomTimerManager(); virtual ~RoomTimerManager();
    void Dispatch(Unk_RoomPacket&);
    void Start(Unk_RoomPacket&);
    void Update(Unk_RoomPacket&);
    void Restart(Unk_RoomPacket&);
    void ReadValues(Unk_RoomPacket&);
    void Stop(Unk_RoomPacket&);
    void Cancel(Unk_RoomPacket&);
    void Show();
    bool IsActive();
    void Reset();
    Unk_RoomPtr<UITimerBase> GetTimer(int);
    void Close();
private:
    MS2_LAYOUT_FRIEND;
    int m_type; unsigned m_start,m_duration; int m_offset;
    std::map<unsigned,int> m_values;
    Unk_RoomPtr<UITimerBase> m_timer;
};
MS2_CHECK_SIZE(RoomTimerManager,0x38);
MS2_CHECK_OFFSET(RoomTimerManager,m_values,0x18);
MS2_CHECK_OFFSET(RoomTimerManager,m_timer,0x28);
