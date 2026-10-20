// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). OnceCallbackTimer (one-shot millisecond callbacks keyed by
// an id, polled against the service manager's clock 0xe001001b) and the template glue of its
// std::map<unsigned, Entry>. Names are invented from use.
// MS2-UNIT: unit_140ca6fc0
// MS2-RANGE: 0x140ca6fc0-0x140ca9d50 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/oncecallbacktimer.h"
#include <efd/ServiceManager.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

efd::ServiceManager* FUN_1413f9850();                                       // the game's service manager

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's counter (symbols-manual.tsv)
unsigned OnceCallbackTimer::s_nextId = 1;
#endif

// @0x140ca6fc0
OnceCallbackTimer::Entry::Entry(unsigned start, unsigned end, TFunctor<void, EmptyParam> callback)
    : m_start(start), m_end(end), m_callback(callback)
{
}

// @0x140ca7030
OnceCallbackTimer::OnceCallbackTimer()
{
    m_pClock = 0;
}

// @0x140ca7090
OnceCallbackTimer::~OnceCallbackTimer()
{
}

// @0x140ca70d0
void OnceCallbackTimer::FUN_140ca70d0()
{
    m_pClock = FUN_1413f9850()->GetClock(0xe001001b);
}

// @0x140ca7100
// MS2-FUNCTIONAL: operand load order of the wrap test (pNode->start vs it->end) differs
void OnceCallbackTimer::Update()
{
    unsigned now = (unsigned)GetTimeMs();
    std::map<unsigned, Entry>::iterator it = m_timers.begin();
    while (it != m_timers.end())
    {
        if (now >= it->second.m_end)
        {
            std::pair<const unsigned, Entry>* pNode = &*it;
            if (it->second.m_end < pNode->second.m_start && it->second.m_start <= now)
            {
                ++it;
            }
            else
            {
                if (!it->second.m_callback.IsNull())
                    it->second.m_callback();
                it = m_timers.erase(it);
            }
        }
        else
        {
            ++it;
        }
    }
}

// @0x140ca7230
int OnceCallbackTimer::Add(int delayMs, TFunctor<void, EmptyParam> callback)
{
    unsigned now = (unsigned)GetTimeMs();
    unsigned end = now + delayMs;
    if (now > end)
    {
        unsigned remain = 0xffffffff - now;
        end = delayMs - remain;
    }
    int id = s_nextId;
    m_timers.insert(std::make_pair(s_nextId, Entry(now, end, callback)));
    s_nextId = s_nextId + 1;
    if (s_nextId == 0)
        s_nextId = 1;
    return id;
}

// @0x140ca73a0
void OnceCallbackTimer::Cancel(unsigned id)
{
    std::map<unsigned, Entry>::iterator it = m_timers.find(id);
    if (it != m_timers.end())
        m_timers.erase(it);
}

// @0x140ca7420
void OnceCallbackTimer::Clear()
{
    m_timers.clear();
}

// @0x140ca7450
unsigned long long OnceCallbackTimer::GetTimeMs()
{
    return (long long)(m_pClock->GetCurrentTime() * 1000.0);
}

// @0x140ca9c30
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
