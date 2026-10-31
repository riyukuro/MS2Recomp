// Recovered event context layouts; names other than EventStruct::DTReward are invented.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/placeholder/cptred.h"
struct Unk_EventPayload { void* value; };
struct Unk_EventHolder : CPtred, Unk_EventPayload {};
namespace EventStruct {
class DTReward : public CPtred {
public:
    DTReward() : a(0), b(0), c(0), d(0), e(0), f(1), g(0), h(0), i(0) {}
    ~DTReward() = default;
    int a,b,c,d,e,f,g;
    unsigned __int64 h,i;
};
}
MS2_CHECK_SIZE(EventStruct::DTReward, 0x48);
MS2_CHECK_OFFSET(EventStruct::DTReward, a, 0x18);
MS2_CHECK_OFFSET(EventStruct::DTReward, h, 0x38);
template<class T> struct Unk_EventBase { static T* Get(T* p) { return p; } };
template<> struct Unk_EventBase<Unk_EventPayload> {
    static Unk_EventHolder* Get(Unk_EventPayload* p) { return p == NULL ? NULL : reinterpret_cast<Unk_EventHolder*>(reinterpret_cast<char*>(p) - offsetof(Unk_EventHolder, value)); }
};
template<class T> class Unk_EventPtr {
public:
    Unk_EventPtr(const Unk_EventPtr& o) : p(o.p) { AddRef(); }
    Unk_EventPtr(T* value) : p(value) { AddRef(); }
    ~Unk_EventPtr();
    Unk_EventPtr& operator=(const Unk_EventPtr& o) { o.AddRef(); Release(); p=o.p; return *this; }
    T* operator->() const { return p; }
private:
    typedef decltype(Unk_EventBase<T>::Get(static_cast<T*>(0))) BasePtr;
    static void AddRefObject(BasePtr value);
    void AddRefImpl(void*) const { AddRefObject(p); }
    void AddRef() const { if (p) AddRefImpl(0); }
    void ReleaseImpl(void*) {
        Unk_EventHolder* base = Unk_EventBase<T>::Get(p);
        if (CPtred::ReleasePtred(reinterpret_cast<CPtred*>(base)) == 0) {
            AddRefObject(base);
            CPtred::DeletePtred(reinterpret_cast<CPtred*>(base));
        }
    }
    void Release() { if (p) { ReleaseImpl(0); p=0; } }
    void* pad; T* p;
};
template<> inline void Unk_EventPtr<Unk_EventPayload>::AddRefObject(Unk_EventHolder* value) {
    CPtred::AddRefPtred(reinterpret_cast<CPtred*>(value));
}
template<> inline void Unk_EventPtr<Unk_EventPayload>::AddRefImpl(void*) const {
    AddRefObject(Unk_EventBase<Unk_EventPayload>::Get(p));
}
struct Unk_EventTime {
    Unk_EventTime& operator=(const Unk_EventTime&);
    __int64 FUN_140282020();
    __int64 a,b;
};
class Unk_140165cf0;
class CMsTime;
struct Unk_EventCore {
    void FUN_1408d5390(int);
    bool FUN_1408d5040(Unk_140165cf0*);                 // load from a mail/event xml element (unit_1408d5040.cpp)
    void FUN_1408d5320(const Unk_EventTime&);           // set the end time (unit_1408d5040.cpp)
    CMsTime FUN_1408d53f0() const;                      // the end time, or now + mode days (unit_1408d5040.cpp)
    int type,id; CStringW name,text,extra; Unk_EventTime time;
    int mode; __int64 a,b,c;
};
MS2_CHECK_SIZE(Unk_EventCore, 0x50);
struct Unk_EventItem {
    Unk_EventItem() : id(0), count(0), rarity(1), kind(0), time(0) {}
    int id,count; unsigned char rarity; int kind; __int64 time;
};
MS2_CHECK_SIZE(Unk_EventItem, 0x18);
// 16-byte element of UserEventContext::extras (the exe's Add copies 0x10 bytes; fields unrecovered)
struct Unk_EventExtra {
    __int64 m_0, m_8;
};
MS2_CHECK_SIZE(Unk_EventExtra, 0x10);
class UserEventContext {
public:
    void FUN_1408d5470(const Unk_EventCore&);
    bool FUN_1408d54a0(int,int,unsigned char,int,__int64);
    bool FUN_1408d55e0(Unk_EventExtra);
    bool FUN_1408d5630(const CStringW&);
    bool FUN_1408d57c0(const CStringW&);
    void FUN_1408d58d0(int);
    void FUN_1408d5900(__int64);
    void FUN_1408d5920(__int64);
    int FUN_1408d5940() const;
    __int64 FUN_1408d5960() const;
    __int64 FUN_1408d5980() const;
    __int64 FUN_1408d59a0() const;
    size_t FUN_1408d59c0() const;
    const ATL::CAtlArray<Unk_EventItem>& FUN_1408d59f0() const;
    Unk_EventCore data;
    ATL::CAtlArray<Unk_EventItem> items;
    ATL::CAtlArray<Unk_EventExtra> extras;
};
MS2_CHECK_OFFSET(UserEventContext, items, 0x50);
MS2_CHECK_OFFSET(UserEventContext, extras, 0x70);
class Unk_EventRewards {
public:
    void FUN_1408d5a10(const Unk_EventPtr<Unk_EventPayload>&);
    Unk_EventPtr<Unk_EventPayload> FUN_1408d5a40() const;

    void FUN_1408d5af0(__int64);
    void FUN_1408d5b30(const Unk_EventPtr<Unk_EventPayload>&);
    Unk_EventPtr<Unk_EventPayload> FUN_1408d5b60() const;
    void FUN_1408d5bb0(const Unk_EventPtr<Unk_EventPayload>&);
    Unk_EventPtr<Unk_EventPayload> FUN_1408d5be0() const;
    void* p0; void* p8; void* p10; void* p18;
    Unk_EventPtr<Unk_EventPayload> r20;
    __int64 n30;
    Unk_EventPtr<Unk_EventPayload> r38,r48;
};
class Unk_EventRewardList {
public:
    void FUN_1408d5c30(const ATL::CAtlArray<unsigned int>&);
    void* p0; void* p8; void* p10; void* p18; void* p20; void* p28; void* p30;
    // The reward-array and pointer accessors belong to different original classes.
    ATL::CAtlArray<Unk_EventPtr<EventStruct::DTReward>> rewards;
};
class Unk_EventReward40 {
public:
    void FUN_1408d5e70(const Unk_EventPtr<Unk_EventPayload>&);
    Unk_EventPtr<Unk_EventPayload> FUN_1408d5ea0() const;
    void* p0; void* p8; void* p10; void* p18; void* p20; void* p28; void* p30; void* p38;
    Unk_EventPtr<Unk_EventPayload> r40;
};
MS2_CHECK_OFFSET(Unk_EventRewards, r38, 0x38);
MS2_CHECK_OFFSET(Unk_EventRewards, r48, 0x48);
MS2_CHECK_OFFSET(Unk_EventRewardList, rewards, 0x38);
MS2_CHECK_OFFSET(Unk_EventReward40, r40, 0x40);

class Unk_EventCounters {
public:
    void FUN_1408d5ad0(__int64);
    void* p0; void* p8; void* p10; void* p18; void* p20; __int64 value;
};
MS2_CHECK_OFFSET(Unk_EventCounters, value, 0x28);
