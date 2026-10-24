// cdirwatcher.h - PLACEHOLDER for CDirWatcher (RTTI .?AVCDirWatcher@@, 0x28 bytes). NOT an original header.
// Bases: CThread at +0x0, TSingleton<CDirWatcher> at +0x18.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates; only the ctor is declared, the members are not
// recovered.
#pragma once

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cthread.h"

// The owner's TU (commonfiles/cachedata.cpp) specializes TSingleton<CDirWatcher> and defines its s_instance (0x143aac5b8) outright; the same
// specialization here keeps this header's users from instantiating a second, COMDAT s_instance of the primary template.
class CDirWatcher;
template<> class TSingleton<CDirWatcher> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static CDirWatcher* s_instance;
    static CDirWatcher* GetInstance() { return s_instance; }
};

class CDirWatcher : public CThread, public TSingleton<CDirWatcher>
{
public:
    CDirWatcher();                                          // 0x1401d1940
    virtual ~CDirWatcher();
    void FUN_1401d1cd0();                                   // stops the watch (InitInstance teardown)
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_20[0x28 - 0x20];
};
MS2_CHECK_SIZE(CDirWatcher, 0x28);
