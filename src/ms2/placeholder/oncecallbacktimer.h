// oncecallbacktimer.h - PLACEHOLDER for OnceCallbackTimer (RTTI .?AVOnceCallbackTimer@@, 0x20 bytes). NOT an original header.
// Bases: TSingleton<OnceCallbackTimer> at +0x0.
// A TSingleton that CGameApp::InitInstance (?\ms2.cpp) creates: one-shot millisecond callbacks keyed by an id, polled
// against the service manager's clock 0xe001001b (unit_140ca6fc0). Member names are invented from use.
#pragma once

#include <map>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/tfunctor.h"           // TFunctor<void, EmptyParam>

namespace efd { class IClock; }

class OnceCallbackTimer : public TSingleton<OnceCallbackTimer>
{
public:
    struct Entry                                            // 0x10 bytes
    {
        Entry(unsigned start, unsigned end, TFunctor<void, EmptyParam> callback);     // 0x140ca6fc0
        Entry(const Entry& o) : m_start(o.m_start), m_end(o.m_end), m_callback(o.m_callback) {}

        unsigned m_start;                                   // +0x00 (ms clock when scheduled)
        unsigned m_end;                                     // +0x04 (ms clock when due, wraps)
        TFunctor<void, EmptyParam> m_callback;              // +0x08
    };

    OnceCallbackTimer();                                    // 0x140ca7030
    virtual ~OnceCallbackTimer();
    void FUN_140ca70d0();                                   // binds the clock
    void Update();                                          // 0x140ca7100
    int Add(int delayMs, TFunctor<void, EmptyParam> callback);       // 0x140ca7230, returns the timer id
    void Cancel(unsigned id);                               // 0x140ca73a0
    void Clear();                                           // 0x140ca7420
    unsigned long long GetTimeMs();                         // 0x140ca7450

    std::map<unsigned, Entry> m_timers;                     // +0x08
    efd::IClock* m_pClock;                                  // +0x18
    static unsigned s_nextId;                               // 0x1439f5468
};
MS2_CHECK_SIZE(OnceCallbackTimer, 0x20);
