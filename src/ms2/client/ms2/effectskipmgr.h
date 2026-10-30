// effectskipmgr.h - EffectSkipMgr (RTTI name): decides which spawned effects may be skipped (distance and per-name
// count limits, read from Table/effectOption.xml, effectLimitCount.xml and effect_benchmark.xml). Header name
// assumed; member and method names are invented from use.
#pragma once
#include <afx.h>
#include <map>
#include <string>
#include <vector>
#include <xmmintrin.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cvaliddata.h"
#include "ms2/commonfiles/os.h"

class Unk_SkipActorPos { float m_x, m_y, m_z, m_w; };                 // the actor's 16 byte position
class Unk_SkipDelta { public: float FUN_140968990() const; private: float m_x, m_y, m_z, m_a, m_b, m_c; };    // difference of two positions, FUN_140968990 = length

// A 12 byte point (the exe copies it from the zero point DAT_143b01a60).
struct Unk_SkipPoint
{
    float x, y, z;
    Unk_SkipPoint& operator=(const Unk_SkipPoint&);                    // 0x140194470
    Unk_SkipDelta FUN_140965c40(const Unk_SkipActorPos& other) const;  // this - other
};

// One skip query: which distance row to use and the effect position. Built by 0x1411b8570.
struct Unk_SkipCheck
{
    Unk_SkipCheck();                // 0x1411b8570
    int m_nRow;                     // +0x00 distance table row (the effect kind)
    int m_nCaster;                  // +0x04 distance table column (the caster kind), 0 = never skip
    Unk_SkipPoint m_pos;            // +0x08
    int m_n14;                      // +0x14 nonzero together with row 1 means "never skip"
    float m_fViewDistance;          // +0x18 per-effect override, -1 = use the table
};
MS2_CHECK_SIZE(Unk_SkipCheck, 0x1c);

// One row of the view distance table: 8 distances, one per caster kind.
struct Unk_SkipRow
{
    Unk_SkipRow();                  // 0x1411b8510
    std::vector<float> m_dist;
};
MS2_CHECK_SIZE(Unk_SkipRow, 0x18);

template <class T> class MS2Ptr;
class CEffectData;
class Unk_SkipEffect;

class EffectSkipMgr : public TSingleton<EffectSkipMgr>, public CValidData<EffectSkipMgr>
{
public:
    typedef std::map<std::string, int> CountMap;

    EffectSkipMgr();                                                    // 0x1411b85e0
    // ~EffectSkipMgr (0x1411bb110) is implicit: the exe dtor stores no vptr

    int IsOutOfView(Unk_SkipCheck* pCheck) const;                            // 0x1411b86e0
    int ShouldSkipByView(MS2Ptr<CEffectData> spData, int nRow, Unk_SkipEffect* pEffect);  // 0x1411b8870 (by value)
    bool LoadOption();                                                  // 0x1411b89e0 effectOption.xml
    bool LoadLimitCount();                                              // 0x1411b8d20 effectLimitCount.xml
    int ParseCaster(const char* pszCaster, int* pnCaster);             // 0x1411b9180
    void LoadElements(void* pNode, int nRow);                           // 0x1411b92f0
    bool CanPlay(const char* pszName);                                  // 0x1411b93f0 per-name count limit
    void AddCount(const char* pszName);                                 // 0x1411b9620
    void RemoveCount(const char* pszName);                              // 0x1411b97a0
    void SetSuspended(bool b);                                          // 0x1411b98e0
    void LoadBenchmark();                                               // 0x1411b9900 effect_benchmark.xml

    static void CheckInit();                                            // 0x1411bb610
    static void SetInit(bool b);                                        // 0x1411bb6c0

    static bool s_bInit;                                                // 0x143ad1ae8

private:
    MS2_LAYOUT_FRIEND;
    Unk_SkipRow m_rows[0x17];                                           // +0x10
    CCacheData m_cache;                                                 // +0x238
    CountMap m_mapLimit;                                                // +0x260 per-name limit
    CountMap m_mapCount;                                                // +0x270 per-name live count
    int m_nMaxCount;                                                    // +0x280
    int m_nBaseFrame;                                                   // +0x284
    bool m_bSuspended;                                                  // +0x288
};
MS2_CHECK_SIZE(EffectSkipMgr, 0x290);
MS2_CHECK_OFFSET(EffectSkipMgr, m_rows, 0x10);
MS2_CHECK_OFFSET(EffectSkipMgr, m_cache, 0x238);
MS2_CHECK_OFFSET(EffectSkipMgr, m_mapLimit, 0x260);
MS2_CHECK_OFFSET(EffectSkipMgr, m_mapCount, 0x270);
MS2_CHECK_OFFSET(EffectSkipMgr, m_bSuspended, 0x288);
