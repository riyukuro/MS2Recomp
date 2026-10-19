// gameeventdtreward.h - GameEventDTReward (RTTI .?AVGameEventDTReward@@, 0xf0 bytes, ctor 0x14041b1f0, vftable 0x142d44450):
// the daily attendance (DT) reward event. Its four xml strings (the inherited m_68..m_80) are the reward rows, the level
// limit and two flags; vfunc_2 parses them into the DTRewardEventContext at +0xd0, vfunc_5 / vfunc_6 hand it to / take it
// from CUserEventManager. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); unit `?\gameeventdtreward.cpp`
// (0x14041b140-0x14041c1a0 .text$mn, dir commonfiles). Member names invented from their use.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/gameevent.h"   // GameEvent
#include "ms2/commonfiles/dtrewardeventcontext.h"

// The exe's pointer family around the DT reward context (16 bytes, the pointer at +8; the real names are unknown):
// Unk_DTCtxPtr is the owning handle at GameEventDTReward+0xd0 (same code shape as MS2Ptr<T>, but its COMDATs are separate
// from the MS2Ptr<DTRewardEventContext> ones of CUserEventManager), Unk_DTCtxArg the by-value handle the event passes on.
// Both release through the one Reference() at 0x14041bf70.
template <class T> class Unk_DTCtxPtr
{
public:
    // @0x14041bae0
    Unk_DTCtxPtr() { m_p = 0; }
    // @0x14041bab0
    Unk_DTCtxPtr(T* p) { m_p = p; AddRef(); }
    // @0x14041bc30
    ~Unk_DTCtxPtr() { Release(); }
    // @0x14041bcd0
    Unk_DTCtxPtr& operator=(int) { Release(); return *this; }
    // @0x14041bd00
    Unk_DTCtxPtr& AssignRaw(T* p)
    {
        Unk_DTCtxPtr tmp(p);
        T* pOld = m_p;
        m_p = tmp.m_p;
        tmp.m_p = pOld;
        return *this;
    }
    // @0x14041bd70
    T* get() const { return m_p; }
    // @0x14041bd80
    T* operator->() const { return m_p; }
    // @0x14041bf70
    static void Reference(T* p) { CPtred::AddRefPtred(p); }

private:
    // @0x14041bf20
    void AddRef() const { if (m_p) AddRefImpl(0); }
    // @0x14041bfc0
    void AddRefImpl(void*) const { Reference(m_p); }
    // @0x14041c070
    void Release()
    {
        if (m_p)
        {
            ReleaseImpl(0);
            m_p = 0;
        }
    }
    // @0x14041c150
    void ReleaseImpl(void*)
    {
        if (CPtred::ReleasePtred(m_p) == 0)
        {
            Reference(m_p);
            CPtred::DeletePtred(m_p);
        }
    }
    void* m_unk_00;
    T* m_p;
};
template <class T> class Unk_DTCtxArg
{
public:
    // @0x14041ba70
    Unk_DTCtxArg(const Unk_DTCtxPtr<T>& o) { m_p = o.get(); AddRef(); }
    Unk_DTCtxArg(const Unk_DTCtxArg& o);    // never emitted: forces the argument to be built in place
    // @0x14041bbd0
    ~Unk_DTCtxArg() { Release(); }

private:
    // @0x14041bef0
    void AddRef() const { if (m_p) AddRefImpl(0); }
    // @0x14041bf90
    void AddRefImpl(void*) const { Unk_DTCtxPtr<T>::Reference(m_p); }
    // @0x14041bff0
    void Release()
    {
        if (m_p)
        {
            ReleaseImpl(0);
            m_p = 0;
        }
    }
    // @0x14041c0b0
    void ReleaseImpl(void*)
    {
        T* p = m_p;
        if (CPtred::ReleasePtred(p) == 0)
        {
            Unk_DTCtxPtr<T>::Reference(p);
            CPtred::DeletePtred(p);
        }
    }
    void* m_unk_00;
    T* m_p;
};

class GameEventDTReward : public GameEvent
{
public:
    GameEventDTReward();                        // 0x14041b1f0
    // Implicit dtor (0x14041bc90 has no vptable store).
    virtual ~GameEventDTReward() = default;

    virtual CStringW vfunc_1();                 // 0x14041b1a0: "GameEventDTReward"
    virtual void vfunc_2();                     // 0x14041b280: parse the four xml strings
    virtual void vfunc_3(Unk_GEOut* out);       // 0x14041b3c0
    virtual void vfunc_4(Unk_GEIn* in);         // 0x14041b490
    virtual void vfunc_5();                     // 0x14041b300: hand the context to CUserEventManager
    virtual void vfunc_6();                     // 0x14041b380: remove it again

    // Builds the context from the rewards ("a,b,...;..." rows of nine ids), the level limit, and two flags.
    void FUN_14041b6e0(const CStringW& rewards, const CStringW& levels, const CStringW& flags, const CStringW& last);   // 0x14041b6e0

protected:
    MS2_LAYOUT_FRIEND;
    Unk_DTCtxPtr<CommonUserEvent::DTRewardEventContext> m_spContext;   // +0xd0
    CStringW m_e0;                                               // +0xe0
    bool m_bShown;                                               // +0xe8 (first flag of the level string; 0 = also flag 3)
};
MS2_CHECK_SIZE(GameEventDTReward, 0xf0);
MS2_CHECK_OFFSET(GameEventDTReward, m_spContext, 0xd0);
MS2_CHECK_OFFSET(GameEventDTReward, m_bShown, 0xe8);
