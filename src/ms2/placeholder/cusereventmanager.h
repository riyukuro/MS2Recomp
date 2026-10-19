// cusereventmanager.h - CUserEventManager (RTTI .?AVCUserEventManager@@, 0x450 bytes, TSingleton<CUserEventManager> at
// +0x0). A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates. Eleven lock + container pairs of user event
// contexts (the event data the server pushes to the client): a map by id, or a single slot, each behind its own critical
// section. Only the DT reward and the mentoring context have RTTI; the other nine are unit-local placeholder types named by
// their member offset. Layout and method roles follow the third-party v2525 decompile; the names are invented.
// Owning unit: ?\usereventmanager.cpp.
#pragma once

#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/commonfiles/dtrewardeventcontext.h"
#include "ms2/commonfiles/gameeventcontext.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"

class CUserEventManager : public TSingleton<CUserEventManager>
{
public:
    // CPtred contexts of the unrecovered events; ContextB0 and Context350 carry their map key at +0x18.
    class Context38 : public CPtred {};
    class ContextB0 : public CPtred { public: int m_key; };
    class Context1A0 : public CPtred {};
    class Context218 : public CPtred {};
    class Context258 : public CPtred {};
    class Context298 : public CPtred {};
    class Context2D8 : public CPtred {};
    class Context350 : public CPtred { public: int m_key; };
    class Context3C8 : public CPtred {};

    CUserEventManager();                                    // 0x1408d6b30
    virtual ~CUserEventManager();                           // 0x1408d6e50 (??_G 0x1408d9920)
    bool Initialize();                                      // 0x1408d7020

    void Add38(int nKey, MS2Ptr<Context38> spContext);                  // 0x1408d7030
    void Remove38(int nKey);                                            // 0x1408d70b0
    void GetAll38(ATL::CAtlArray<MS2Ptr<Context38> >& rOut);            // 0x1408d7120
    void AddB0(MS2Ptr<ContextB0> spContext);                            // 0x1408d71d0
    void RemoveB0(int nKey);                                            // 0x1408d7250
    void GetAllB0(ATL::CAtlArray<MS2Ptr<ContextB0> >& rOut);            // 0x1408d72b0
    void AddMentoring(int nKey, MS2Ptr<MentoringContext> spContext);    // 0x1408d7360
    void RemoveMentoring(int nKey);                                     // 0x1408d73e0
    void GetAllMentoring(ATL::CAtlArray<MS2Ptr<MentoringContext> >& rOut);   // 0x1408d7440
    void Add1A0(int nKey, MS2Ptr<Context1A0> spContext);                // 0x1408d74f0
    void Remove1A0(int nKey);                                           // 0x1408d7570
    void GetAll1A0(ATL::CAtlArray<MS2Ptr<Context1A0> >& rOut);          // 0x1408d75d0
    void Set218(MS2Ptr<Context218> spContext);                          // 0x1408d7680
    MS2Ptr<Context218> Get218();                                        // 0x1408d7700
    void Set258(MS2Ptr<Context258> spContext);                          // 0x1408d77a0
    MS2Ptr<Context258> Get258();                                        // 0x1408d7820
    void Set298(MS2Ptr<Context298> spContext);                          // 0x1408d78c0
    MS2Ptr<Context298> Get298();                                        // 0x1408d7930
    void Add2D8(int nKey, MS2Ptr<Context2D8> spContext);                // 0x1408d79b0
    void Remove2D8(int nKey);                                           // 0x1408d7a30
    void GetAll2D8(ATL::CAtlArray<MS2Ptr<Context2D8> >& rOut);          // 0x1408d7a90
    void Add350(MS2Ptr<Context350> spContext);                          // 0x1408d7b40
    void Remove350(int nKey);                                           // 0x1408d7bc0
    void GetAll350(ATL::CAtlArray<MS2Ptr<Context350> >& rOut);          // 0x1408d7c20
    void AddDTReward(MS2Ptr<CommonUserEvent::DTRewardEventContext> spContext);   // 0x1408d7cd0
    void RemoveDTReward(int nKey);                                      // 0x1408d7d50
    void GetAllDTReward(ATL::CAtlArray<MS2Ptr<CommonUserEvent::DTRewardEventContext> >& rOut);   // 0x1408d7db0
    int HasDTReward(unsigned short nLevel);                             // 0x1408d7e60
    void Set3C8(MS2Ptr<Context3C8> spContext);                          // 0x1408d7f40
    void Reset3C8();                                                    // 0x1408d7fb0
    MS2Ptr<Context3C8> Get3C8();                                        // 0x1408d8010

private:
    MS2_LAYOUT_FRIEND;
    CLockCriticalSection m_lock38;
    ATL::CAtlMap<int, MS2Ptr<Context38> > m_map38;                      // +0x38
    CLockCriticalSection m_lockB0;
    ATL::CAtlMap<int, MS2Ptr<ContextB0> > m_mapB0;                      // +0xb0
    CLockCriticalSection m_lockMentoring;
    ATL::CAtlMap<int, MS2Ptr<MentoringContext> > m_mentoring;           // +0x128
    CLockCriticalSection m_lock1A0;
    ATL::CAtlMap<int, MS2Ptr<Context1A0> > m_map1A0;                    // +0x1a0
    CLockCriticalSection m_lock218;
    MS2Ptr<Context218> m_ptr218;                                        // +0x218
    CLockCriticalSection m_lock258;
    MS2Ptr<Context258> m_ptr258;                                        // +0x258
    CLockCriticalSection m_lock298;
    MS2Ptr<Context298> m_ptr298;                                        // +0x298
    CLockCriticalSection m_lock2D8;
    ATL::CAtlMap<int, MS2Ptr<Context2D8> > m_map2D8;                    // +0x2d8
    CLockCriticalSection m_lock350;
    ATL::CAtlMap<int, MS2Ptr<Context350> > m_map350;                    // +0x350
    CLockCriticalSection m_lock3C8;
    MS2Ptr<Context3C8> m_ptr3C8;                                        // +0x3c8
    CLockCriticalSection m_lockDTReward;
    ATL::CAtlMap<int, MS2Ptr<CommonUserEvent::DTRewardEventContext> > m_dtRewards;   // +0x408
};
MS2_CHECK_SIZE(CUserEventManager, 0x450);
MS2_CHECK_OFFSET(CUserEventManager, m_map38, 0x38);
MS2_CHECK_OFFSET(CUserEventManager, m_ptr218, 0x218);
MS2_CHECK_OFFSET(CUserEventManager, m_ptr3C8, 0x3c8);
MS2_CHECK_OFFSET(CUserEventManager, m_dtRewards, 0x408);
