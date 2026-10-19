// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CUserEventManager: the client's store of the user event
// contexts (attendance rewards, mentoring, ...) the server pushes; and the CAtlMap / MS2Ptr instantiations its
// containers need.
// MS2-UNIT: ?\usereventmanager.cpp
// MS2-RANGE: 0x1408d6b30-0x1408e1840 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$MS2Ptr@VMentoringContext@@@@QEAA@AEBV0@@Z 0x1408d8960 ; prop
// MS2-PIN: ??0?$MS2Ptr@VMentoringContext@@@@QEAA@XZ 0x1408d89a0 ; unique
// MS2-PIN: ??0?$MS2Ptr@VContext258@CUserEventManager@@@@QEAA@AEBV0@@Z 0x1408d8a80 ; unique
// MS2-PIN: ??0?$MS2Ptr@VContext218@CUserEventManager@@@@QEAA@AEBV0@@Z 0x1408d8ae0 ; unique
// MS2-PIN: ??0CNode@?$CAtlMap@HV?$MS2Ptr@VMentoringContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VMentoringContext@@@@@3@@ATL@@QEAA@HI@Z 0x1408d8c70 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@HV?$MS2Ptr@VMentoringContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VMentoringContext@@@@@3@@ATL@@IEAA@H@Z 0x1408d8e30 ; unique
// MS2-PIN: ??1CPair@?$CAtlMap@HV?$MS2Ptr@VMentoringContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VMentoringContext@@@@@3@@ATL@@QEAA@XZ 0x1408d93a0 ; unique
// MS2-PIN: ??4?$MS2Ptr@VMentoringContext@@@@QEAAAEAV0@AEBV0@@Z 0x1408d95b0 ; unique
// MS2-PIN: ?Add@?$CAtlArray@V?$MS2Ptr@VMentoringContext@@@@V?$CElementTraits@V?$MS2Ptr@VMentoringContext@@@@@ATL@@@ATL@@QEAA_KAEBV?$MS2Ptr@VMentoringContext@@@@@Z 0x1408d9c20 ; unique
// MS2-PIN: ?CreateNode@?$CAtlMap@HV?$MS2Ptr@VMentoringContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VMentoringContext@@@@@3@@ATL@@AEAAPEAVCNode@12@HII@Z 0x1408da030 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VContext1A0@CUserEventManager@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VContext1A0@CUserEventManager@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1408db480 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VDTRewardEventContext@CommonUserEvent@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VDTRewardEventContext@CommonUserEvent@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1408db570 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VContext350@CUserEventManager@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VContext350@CUserEventManager@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1408db660 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VContext38@CUserEventManager@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VContext38@CUserEventManager@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1408db750 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VMentoringContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VMentoringContext@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1408db840 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VContext2D8@CUserEventManager@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VContext2D8@CUserEventManager@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1408db930 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@HV?$MS2Ptr@VContextB0@CUserEventManager@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VContextB0@CUserEventManager@@@@@3@@ATL@@AEBAPEAVCNode@12@HAEAI0AEAPEAV312@@Z 0x1408dba20 ; unique
// MS2-PIN: ?GrowBuffer@?$CAtlArray@V?$MS2Ptr@VMentoringContext@@@@V?$CElementTraits@V?$MS2Ptr@VMentoringContext@@@@@ATL@@@ATL@@AEAA_N_K@Z 0x1408dc7b0 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@HV?$MS2Ptr@VMentoringContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VMentoringContext@@@@@3@@ATL@@AEAAPEAVCNode@12@HII@Z 0x1408ddf50 ; unique
// MS2-PIN: ?RelocateElements@?$CElementTraitsBase@V?$MS2Ptr@VMentoringContext@@@@@ATL@@SAXPEAV?$MS2Ptr@VMentoringContext@@@@0_K@Z 0x1408dfc60 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@HV?$MS2Ptr@VMentoringContext@@@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$MS2Ptr@VMentoringContext@@@@@3@@ATL@@QEAAPEAU__POSITION@@HAEBV?$MS2Ptr@VMentoringContext@@@@@Z 0x1408e1630 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\usereventmanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/cusereventmanager.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The scoped lock of a CLockCriticalSection (the 0x140203610 copy of the ctor, dtor 0x1401b5120).
struct Unk_UserEventLock
{
    Unk_UserEventLock(CLockCriticalSection& lock, int acquire);     // 0x140203610
    ~Unk_UserEventLock();                                           // 0x1401b5120
    void* m_p;
};
MS2_CHECK_SIZE(Unk_UserEventLock, 8);

// @0x1408d6b30
CUserEventManager::CUserEventManager()
{
}

// @0x1408d6e50
CUserEventManager::~CUserEventManager()
{
}

// @0x1408d7020
bool CUserEventManager::Initialize()
{
    return true;
}

// @0x1408d7030
void CUserEventManager::Add38(int nKey, MS2Ptr<Context38> spContext)
{
    Unk_LockGuard guard(m_lock38);
    if (guard)
    {
    }
    else
    {
        m_map38.SetAt(nKey, spContext);
    }
}

// @0x1408d70b0
void CUserEventManager::Remove38(int nKey)
{
    Unk_LockGuard guard(m_lock38);
    if (guard)
    {
    }
    else
    {
        m_map38.RemoveKey(nKey);
    }
}

// @0x1408d7120
void CUserEventManager::GetAll38(ATL::CAtlArray<MS2Ptr<Context38> >& rOut)
{
    Unk_LockGuard guard(m_lock38);
    if (guard)
    {
    }
    else
    {
        for (POSITION pos = m_map38.GetStartPosition(); pos != 0; m_map38.GetNext(pos))
            rOut.Add(m_map38.GetValueAt(pos));
    }
}

// @0x1408d71d0
void CUserEventManager::AddB0(MS2Ptr<ContextB0> spContext)
{
    Unk_UserEventLock guard(m_lockB0, 1);
    m_mapB0.SetAt(spContext->m_key, spContext);
}

// @0x1408d7250
void CUserEventManager::RemoveB0(int nKey)
{
    Unk_UserEventLock guard(m_lockB0, 1);
    m_mapB0.RemoveKey(nKey);
}

// @0x1408d72b0
void CUserEventManager::GetAllB0(ATL::CAtlArray<MS2Ptr<ContextB0> >& rOut)
{
    Unk_UserEventLock guard(m_lockB0, 1);
    for (POSITION pos = m_mapB0.GetStartPosition(); pos != 0; m_mapB0.GetNext(pos))
        rOut.Add(m_mapB0.GetValueAt(pos));
}

// @0x1408d7360
void CUserEventManager::AddMentoring(int nKey, MS2Ptr<MentoringContext> spContext)
{
    Unk_UserEventLock guard(m_lockMentoring, 1);
    m_mentoring.SetAt(nKey, spContext);
}

// @0x1408d73e0
void CUserEventManager::RemoveMentoring(int nKey)
{
    Unk_UserEventLock guard(m_lockMentoring, 1);
    m_mentoring.RemoveKey(nKey);
}

// @0x1408d7440
void CUserEventManager::GetAllMentoring(ATL::CAtlArray<MS2Ptr<MentoringContext> >& rOut)
{
    Unk_UserEventLock guard(m_lockMentoring, 1);
    for (POSITION pos = m_mentoring.GetStartPosition(); pos != 0; m_mentoring.GetNext(pos))
        rOut.Add(m_mentoring.GetValueAt(pos));
}

// @0x1408d74f0
void CUserEventManager::Add1A0(int nKey, MS2Ptr<Context1A0> spContext)
{
    Unk_UserEventLock guard(m_lock1A0, 1);
    m_map1A0.SetAt(nKey, spContext);
}

// @0x1408d7570
void CUserEventManager::Remove1A0(int nKey)
{
    Unk_UserEventLock guard(m_lock1A0, 1);
    m_map1A0.RemoveKey(nKey);
}

// @0x1408d75d0
void CUserEventManager::GetAll1A0(ATL::CAtlArray<MS2Ptr<Context1A0> >& rOut)
{
    Unk_UserEventLock guard(m_lock1A0, 1);
    for (POSITION pos = m_map1A0.GetStartPosition(); pos != 0; m_map1A0.GetNext(pos))
        rOut.Add(m_map1A0.GetValueAt(pos));
}

// @0x1408d7680
void CUserEventManager::Set218(MS2Ptr<Context218> spContext)
{
    Unk_LockGuard guard(m_lock218);
    if (guard)
    {
    }
    else
    {
        m_ptr218 = spContext;
    }
}

#pragma warning(push)
#pragma warning(disable : 4715)     // the exe falls off the end when the lock fails
// MS2-FUNCTIONAL: the exe has an extra nop after the guard destructor on the failure path (falls off the end)
// @0x1408d7700
MS2Ptr<CUserEventManager::Context218> CUserEventManager::Get218()
{
    {
        Unk_LockGuard guard(m_lock218);
        if (guard)
        {
        }
        else
        {
            return m_ptr218;
        }
    }
}

// @0x1408d77a0
void CUserEventManager::Set258(MS2Ptr<Context258> spContext)
{
    Unk_LockGuard guard(m_lock258);
    if (guard)
    {
    }
    else
    {
        m_ptr258 = spContext;
    }
}

// MS2-FUNCTIONAL: the exe has an extra nop after the guard destructor on the failure path (falls off the end)
// @0x1408d7820
MS2Ptr<CUserEventManager::Context258> CUserEventManager::Get258()
{
    Unk_LockGuard guard(m_lock258);
    if (guard)
    {
    }
    else
    {
        return m_ptr258;
    }
}
#pragma warning(pop)

// @0x1408d78c0
void CUserEventManager::Set298(MS2Ptr<Context298> spContext)
{
    Unk_UserEventLock guard(m_lock298, 1);
    m_ptr298 = spContext;
}

// @0x1408d7930
MS2Ptr<CUserEventManager::Context298> CUserEventManager::Get298()
{
    Unk_UserEventLock guard(m_lock298, 1);
    return m_ptr298;
}

// @0x1408d79b0
void CUserEventManager::Add2D8(int nKey, MS2Ptr<Context2D8> spContext)
{
    Unk_UserEventLock guard(m_lock2D8, 1);
    m_map2D8.SetAt(nKey, spContext);
}

// @0x1408d7a30
void CUserEventManager::Remove2D8(int nKey)
{
    Unk_UserEventLock guard(m_lock2D8, 1);
    m_map2D8.RemoveKey(nKey);
}

// @0x1408d7a90
void CUserEventManager::GetAll2D8(ATL::CAtlArray<MS2Ptr<Context2D8> >& rOut)
{
    Unk_UserEventLock guard(m_lock2D8, 1);
    for (POSITION pos = m_map2D8.GetStartPosition(); pos != 0; m_map2D8.GetNext(pos))
        rOut.Add(m_map2D8.GetValueAt(pos));
}

// @0x1408d7b40
void CUserEventManager::Add350(MS2Ptr<Context350> spContext)
{
    Unk_UserEventLock guard(m_lock350, 1);
    m_map350.SetAt(spContext->m_key, spContext);
}

// @0x1408d7bc0
void CUserEventManager::Remove350(int nKey)
{
    Unk_UserEventLock guard(m_lock350, 1);
    m_map350.RemoveKey(nKey);
}

// @0x1408d7c20
void CUserEventManager::GetAll350(ATL::CAtlArray<MS2Ptr<Context350> >& rOut)
{
    Unk_UserEventLock guard(m_lock350, 1);
    for (POSITION pos = m_map350.GetStartPosition(); pos != 0; m_map350.GetNext(pos))
        rOut.Add(m_map350.GetValueAt(pos));
}

// @0x1408d7cd0
void CUserEventManager::AddDTReward(MS2Ptr<CommonUserEvent::DTRewardEventContext> spContext)
{
    Unk_UserEventLock guard(m_lockDTReward, 1);
    m_dtRewards.SetAt(spContext->m_id, spContext);
}

// @0x1408d7d50
void CUserEventManager::RemoveDTReward(int nKey)
{
    Unk_UserEventLock guard(m_lockDTReward, 1);
    m_dtRewards.RemoveKey(nKey);
}

// @0x1408d7db0
void CUserEventManager::GetAllDTReward(ATL::CAtlArray<MS2Ptr<CommonUserEvent::DTRewardEventContext> >& rOut)
{
    Unk_UserEventLock guard(m_lockDTReward, 1);
    for (POSITION pos = m_dtRewards.GetStartPosition(); pos != 0; m_dtRewards.GetNext(pos))
        rOut.Add(m_dtRewards.GetValueAt(pos));
}

// @0x1408d7e60
int CUserEventManager::HasDTReward(unsigned short nLevel)
{
    Unk_UserEventLock guard(m_lockDTReward, 1);
    for (POSITION pos = m_dtRewards.GetStartPosition(); pos != 0; m_dtRewards.GetNext(pos))
    {
        MS2Ptr<CommonUserEvent::DTRewardEventContext>& rContext = m_dtRewards.GetValueAt(pos);
        if (rContext->m_level <= nLevel)
            return 1;
    }
    return 0;
}

// @0x1408d7f40
void CUserEventManager::Set3C8(MS2Ptr<Context3C8> spContext)
{
    Unk_UserEventLock guard(m_lock3C8, 1);
    m_ptr3C8 = spContext;
}

// @0x1408d7fb0
void CUserEventManager::Reset3C8()
{
    Unk_UserEventLock guard(m_lock3C8, 1);
    m_ptr3C8 = 0;
}

// @0x1408d8010
MS2Ptr<CUserEventManager::Context3C8> CUserEventManager::Get3C8()
{
    Unk_UserEventLock guard(m_lock3C8, 1);
    return m_ptr3C8;
}
