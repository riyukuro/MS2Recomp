// randomeffectparam.h - the "Random" effect (effect XML type 0xb): a list of child <effect> params with "prob"
// weights; CRandomEffect picks one (weighted, or Unk_EffectTarget::m_nRandomIndex) and forwards every slot to it.
// Owning unit: ?\randomeffectparam.cpp (0x1416f44e0-0x1416f57c0). Header name assumed from the unit path.
//
// Unk_WeightedPicker is the game's weighted random choice helper (0x68 bytes; all its members are COMDATs emitted
// in this unit): Set(key, weight) per candidate, Build() the cumulative table, then Pick(rng).
#pragma once
#include <map>
#include <atlcoll.h>
#include "ms2/client/ms2/effectparam.h"
#include "ms2/placeholder/ascript.h"   // MS2Ptr<T>
#include "ms2/placeholder/clockcriticalsection.h"

// Game random generator (0x40 bytes; commonfiles\questmasktable.cpp holds its methods): a three-word generator behind
// a lock. Seeded ctor 0x140768210, default ctor 0x140768110 (seeded from the clock), dtor 0x1401cdc30,
// next value 0x1407684c0.
class Unk_Random
{
public:
    Unk_Random();                                   // 0x140768110
    explicit Unk_Random(int nSeed);                 // 0x140768210
    Unk_Random(unsigned s1, unsigned s2, unsigned s3);      // 0x140768290
    Unk_Random(const Unk_Random& o);                // 0x1407681b0
    ~Unk_Random();                                  // 0x1401cdc30
    void Seed(int nSeed);                           // 0x1407682f0
    void SetState(unsigned s1, unsigned s2, unsigned s3);   // 0x140768350 (forces the low bits)
    void GetState(unsigned* s1, unsigned* s2, unsigned* s3);        // 0x1407683d0
    void SetRaw(unsigned s1, unsigned s2, unsigned s3);     // 0x140768450
    unsigned int FUN_1407684c0();                   // next
    int Range(unsigned nCount, int nBase);          // 0x1407685b0 nBase + next % nCount
private:
    unsigned m_s1;                                  // +0x00
    unsigned m_s2;                                  // +0x04
    unsigned m_s3;                                  // +0x08
    unsigned m_pad_0c;
    CLockCriticalSection m_lock;                    // +0x10
};
MS2_CHECK_SIZE(Unk_Random, 0x40);

// 0x68 bytes. ctor 0x1416f4e10, implicit dtor 0x1416f4eb0.
class Unk_WeightedPicker
{
public:
    Unk_WeightedPicker()                                            // 0x1416f4e10
        : m_nTotal(0)
    {
    }
    // 0x1416f5530 (indexes the map with the caller's key slot, no conversion temporary)
    void Set(const unsigned int& nKey, const unsigned int& nWeight)
    {
        m_mapWeights[reinterpret_cast<const DWORD&>(nKey)] = nWeight;
    }
    bool Build();                                                   // 0x1416f5250
    const unsigned int* Pick(Unk_Random& kRandom);                  // 0x1416f55b0 NULL when every weight is 0
    // map<DWORD, int>: the exe's picker uses that instantiation's copies (ctor 0x14025bf00, dtor 0x14025c810,
    // operator[] 0x1403e89a0, which calls the DWORD-keyed try_emplace 0x1403e1410)
    typedef std::map<DWORD, int> WeightMap;
public:
    Unk_Random m_kRandom;                           // +0x00 (unused here)
    WeightMap m_mapWeights;                                         // +0x40 key -> weight
    std::map<int, unsigned int> m_mapCumulative;                    // +0x50 running total - 1 -> key
    int m_nTotal;                                   // +0x60
};
MS2_CHECK_SIZE(Unk_WeightedPicker, 0x68);
MS2_CHECK_OFFSET(Unk_WeightedPicker, m_mapWeights, 0x40);
MS2_CHECK_OFFSET(Unk_WeightedPicker, m_nTotal, 0x60);

typedef MS2Ptr<CEffectParam> CEffectParamPtr;

// 0x88 bytes. vftable 0x142f4d6a0 region (8 slots; overrides 1, 2, 5, 6). Implicit dtor 0x1416f4ef0,
// ??_G 0x1416f50a0.
class CRandomEffectParam : public CEffectParam
{
public:
    CRandomEffectParam();                                           // 0x1416f44e0
    virtual void vfunc_1(Unk_140165cf0* pNode);                     // 1 0x1416f4540 "prob" + child <effect>s
    virtual bool vfunc_2();                                         // 2 0x1416f4640 warn when there is no child
    virtual bool vfunc_5(int n);                                    // 5 0x1416f46c0 every child's vfunc_5
    virtual CEffectPtr vfunc_6();                                   // 6 0x1416f47b0 new CRandomEffect
public:
    ATL::CAtlArray<CEffectParamPtr> m_arrEffects;   // +0x48 child effect params
    ATL::CAtlArray<DWORD> m_arrWeights;      // +0x68 "prob" (comma list; missing = 0)
};
MS2_CHECK_SIZE(CRandomEffectParam, 0x88);
MS2_CHECK_OFFSET(CRandomEffectParam, m_arrEffects, 0x48);
MS2_CHECK_OFFSET(CRandomEffectParam, m_arrWeights, 0x68);

// 0x38 bytes. 13 slots; ??_G 0x1416f5040. Every slot forwards to the chosen child effect.
class CRandomEffect : public CEffect
{
    NiDeclareRTTI;                                                  // 2 GetRTTI 0x1416f5240; ms_RTTI 0x143ae6898
public:
    CRandomEffect();                                                // 0x1416f4850
    virtual ~CRandomEffect();                                       // 0x1416f48a0
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x1416f48e0 pick + create
    virtual void vfunc_5();                                         // 5 0x1416f4ba0
    virtual void vfunc_7();                                         // 7 0x1416f4be0
    virtual int vfunc_8(void* p);                                   // 8 0x1416f4c20
    virtual bool vfunc_9();                                         // 9 0x1416f4b60
    virtual void vfunc_10(bool b);                                  // 10 0x1416f4c70
    virtual int vfunc_12();                                         // 12 0x1416f4cc0 child's type, else 0xb
public:
    CEffectPtr m_spEffect;          // +0x30 the chosen child effect
};
MS2_CHECK_SIZE(CRandomEffect, 0x38);
MS2_CHECK_OFFSET(CRandomEffect, m_spEffect, 0x30);
