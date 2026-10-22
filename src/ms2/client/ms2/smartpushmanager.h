// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CSmartPushManager: the client-side owner of the smart push
// suggestions (Table/smartPush.xml rows). Each row gets a "CSmartPush<content>" object from the class factory; the
// manager polls them every 100 ms and adds / removes them on the UISmartPush HUD strip.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members whose job is clear but whose name is not.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ms2svrptr.h"
#include "ms2/commonfiles/os.h"
#include "ms2/client/ms2/smartpushtable.h"

// Base of the "CSmartPush<content>" classes (CSmartPushAutoBreeding, CSmartPushAutoFarming ...; created by name through
// the class factory). Only the members and slots the manager touches are recovered; the subclasses live in
// ?\smartpush.cpp.
class CSmartPush : public CPtred
{
public:
    virtual void GetTypeName() = 0;                                 //  1 0x08 (not called by the manager)
    virtual void vfunc_2() = 0;                                 //  2 0x10 after-update hook
    virtual void vfunc_3() = 0;                                 //  3 0x18 (event: no argument)
    virtual void vfunc_4(int nValue) = 0;                       //  4 0x20 (event: one argument)
    virtual void vfunc_5() = 0;                                 //  5 0x28 (not called by the manager)
    virtual int vfunc_6() = 0;                                  //  6 0x30 current display state (0 = hidden)

    int m_nId;                                                  // +0x18 CSmartPushData::m_nId
    int m_n1c;
    int m_nState;                                               // +0x20 state last shown on the strip
    int m_pad_24;
    MS2SvrPtr<CSmartPushData> m_data;                           // +0x28 the table row
};
MS2_CHECK_SIZE(CSmartPush, 0x38);

class CSmartPushManager : public TSingleton<CSmartPushManager>
{
public:
    typedef MS2SvrPtr<CSmartPush> PushPtr;
    typedef ATL::CAtlMap<unsigned long, PushPtr> PushMap;

    CSmartPushManager();                                        // 0x140dd81d0
    virtual ~CSmartPushManager();                               // 0x140dd8250 (??_G 0x140dd8e50)

    void FUN_140dd82b0();                                       // create one CSmartPush per table row
    void FUN_140dd8440();                                       // per-frame poll, 100 ms throttle
    void FUN_140dd8620(int nId);                                // forward event to push nId
    void FUN_140dd86a0(int nId, int nValue);                    // forward event with a value to push nId
    void FUN_140dd8730();                                       // reset every push to hidden
    void FUN_140dd87d0();                                       // re-add every visible push to the strip

private:
    MS2_LAYOUT_FRIEND;
    unsigned m_nLastTick;                                       // +0x08 client clock of the last poll
    PushMap m_pushes;                                           // +0x10 id -> push
};
MS2_CHECK_SIZE(CSmartPushManager, 0x58);
MS2_CHECK_OFFSET(CSmartPushManager, m_pushes, 0x10);
