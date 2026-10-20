// COptimizer (RTTI, size 0xa8; ctor 0x14161b900, ?\optimizer.cpp 0x14161b8c0-0x1416252b0). Heap-only singleton:
// per-player model culling / update throttling, frame limiter and frame sampling.
#pragma once
#include <set>
#include <map>
#include <list>
#include <vector>
#include <egf/EntityID.h>
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/mctimer.h"
class PC;
class PCBase;
class COptimizer : public TSingleton<COptimizer> {
public:
    // The record of a throttled player: its distance and the actor (ctor 0x14161b8c0, default 0x141621e50).
    struct Entry {
        Entry();
        Entry(float fDistance, PCBase* pPC);
        friend bool operator<(const Entry& left, const Entry& right);
        float m_fDistance;
        PCBase* m_pPC;
    };
    COptimizer();
    virtual ~COptimizer();
    int FUN_141215630() const;
    int FUN_1414a5910() const;                              // the frame time limit (m_nFrameDelay; 0 = unlimited)
    int FUN_1414a5a30();                                    // a static option (0x143ae2b48): MS2KFMCache on
    int FUN_1409f7ea0();                                    // item loader thread enabled (InitInstance)
    int IsModelCullingOn() { return ms_nModelCulling; }     // 0x1414c98a0 (COMDAT, also optimizer.cpp)
    unsigned __int64 FUN_141245b10() const { return m_nTotalMemory; }   // 0x141245b10
    static int ms_nModelCulling;                            // 0x143ae2b44 model node culling enabled
    // optimizer.cpp
    void FUN_14161baf0();                                   // Initialize
    void FUN_14161bb60();                                   // Update
    unsigned __int64 FUN_14161bdc0() const;                 // pagefile MB
    unsigned __int64 FUN_14161be50() const;                 // private MB
    void FUN_14161bee0();                                   // log the hardware
    float FUN_14161c360();                                  // frame limit from the options
    void FUN_14161c3f0();                                   // no frame limit
    void FUN_14161c420(float fLimit);
    void FUN_14161c490();                                   // load Optimization.xml
    void FUN_14161c8c0();                                   // log the first MyPC load time
    void FUN_14161c940(unsigned nCount, int nCycle);        // start frame sampling
    void FUN_14161c990();                                   // sample the frame rate
    void FUN_14161cc80(int nFlags, int nLimit, int nEnabled, int nMode);
    void FUN_14161cd00();                                   // clear
    void FUN_14161cd60(unsigned __int64 nId);
    void FUN_14161cdd0(unsigned nId);
    int FUN_14161ce60(unsigned nId);
    void FUN_14161cee0(int nSuppressed);
    int FUN_14161cf40() const;
    void FUN_14161cf60(PCBase* pPC);
    void FUN_14161d010(const egf::EntityID& kId);
    void FUN_14161d070(const egf::EntityID& kId);
    int FUN_14161d0f0() const;
    void FUN_14161d130(bool bForce);
    void FUN_14161db10(int nFlags);
    void FUN_14161dbe0(PCBase* pPC, int nFlags);
    void FUN_14161dd30(int nFlags, int nLimit);
    int FUN_141622790() const;
    void FUN_14109ac50(int n);                              // m_nUpdateOn = n
    std::set<unsigned __int64> m_players;                   // +0x08
    std::set<egf::EntityID> m_suppress;                     // +0x18
    unsigned __int64 m_nTotalMemory;                        // +0x28 physical MB
    float m_fMemoryTime;                                    // +0x30
    float m_fUpdateTime;                                    // +0x34
    int preloadMode;                                        // +0x38 mode flags (2 party, 4 guild, 8 nearest)
    int m_nSuppressed;                                      // +0x3c
    int m_nEnabled;                                         // +0x40
    int m_nMode;                                            // +0x44
    int m_nLimit;                                           // +0x48
    std::map<unsigned __int64, Entry> m_selected;                    // +0x50
    float m_fFrameLimit;                                    // +0x60
    int m_nFrameDelay;                                      // +0x64
    int m_nUpdateOn;                                        // +0x68
    void FUN_141c1ca80(int n) { m_nUpdateOn2 = n; }         // 0x141c1ca80 (inline; COMDAT in worldservice.cpp)
    int m_nUpdateOn2;                                       // +0x6c
    int m_nStartTick;                                       // +0x70
    int m_nFirstLoadTick;                                   // +0x74
    Unk_McTimer m_sampleTimer;                              // +0x78
    std::vector<float> m_samples;                           // +0x80
    unsigned __int64 m_nSampleCount;                        // +0x98
    int m_nSampleCycle;                                     // +0xa0
};
MS2_CHECK_SIZE(COptimizer,0xa8);
MS2_CHECK_OFFSET(COptimizer,preloadMode,0x38);
MS2_CHECK_OFFSET(COptimizer,m_selected,0x50);
MS2_CHECK_OFFSET(COptimizer,m_samples,0x80);
