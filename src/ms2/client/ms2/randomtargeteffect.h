// randomtargeteffect.h - CRandomTargetEffect (a one-off effect attached to a target; created through the effect
// manager singleton 0x1403ed280) and CRandomTargetEffectController (blinks a list of such effects, one id after
// another, to show which target was picked). Owning unit: ?\randomtargeteffect.cpp (0x140aaadb0-0x140aace60).
// Header name assumed from the unit path. Class names are real (RTTI): vftables 0x142dcfec8 / 0x142dcfed8.
#pragma once
#include <atlcoll.h>
#include <atlstr.h>
#include <atlcomcli.h>
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"       // MS2Ptr<T>
#include "ms2/placeholder/unk_nodeptr.h"

// 0x38 bytes, vftable 0x142dcfec8 (1 slot: the deleting dtor 0x140aac460).
class CRandomTargetEffect : public CPtred
{
public:
    explicit CRandomTargetEffect(void* pOwner);     // 0x140aaadb0
    virtual ~CRandomTargetEffect();                 // 0x140aaae40
    void Create(CString strName);                   // 0x140aaaea0 spawn the effect on the owner (destroys a previous one)
    void Destroy();                                 // 0x140aab080
    void UpdatePosition();                          // 0x140aab0f0 snap to the owner's shadow node, 150 units up
    void SetVisible(bool bVisible);                 // 0x140aab2e0
    void Show();                                    // 0x140aab320
    void Hide();                                    // 0x140aab370
    int SetScale(float fScale);                     // 0x140aab3c0

private:
    void* m_pOwner;                                 // +0x18 the target game object
    int m_nEffectId;                                // +0x20 effect-manager handle, 0 = none
    Unk_NodePtr m_spNode;                           // +0x28 attached NiNode
    float m_fScale;                                 // +0x30 (1.0)
    bool m_bVisible;                                // +0x34
};

// Objects reachable through the world-service maps that carry an effect (field offsets proven by the lookups).
struct IRteWorldObject : public IUnknown {};
struct Unk_RtePlayer : public IRteWorldObject
{
    CRandomTargetEffect* GetEffectPtr() const;      // 0x140aac710 raw pointer of the +0x12c8 slot
    char m_pad_08[0x12c8 - 8];
    MS2Ptr<CRandomTargetEffect> m_spEffect;         // +0x12c8
};
class Unk_UpperNpc : public IRteWorldObject
{
public:
    MS2Ptr<CRandomTargetEffect> GetEffect();        // 0x140aac6c0 copy of the +0xf28 slot
    char m_pad_08[0xf28 - 8];
    MS2Ptr<CRandomTargetEffect> m_spEffect;         // +0xf28
};

// 0x78 bytes, vftable 0x142dcfed8 (1 slot: the deleting dtor 0x140aac4a0).
class CRandomTargetEffectController : public CPtred
{
public:
    CRandomTargetEffectController();                // 0x140aab420
    virtual ~CRandomTargetEffectController();       // 0x140aab4b0
    void Reset();                                   // 0x140aab530
    // Mode 1: blink the ids one at a time (300 ms) using strEffect.
    void StartSequence(const CAtlArray<unsigned>& aIds, CString strEffect);                 // 0x140aab5b0
    // Mode 2: hide the mode-1 ids' effects, spawn strEffect on aIdsNew and flicker it (100 ms).
    void StartFlicker(const CAtlArray<unsigned>& aIdsNew, CString strEffect);               // 0x140aab720
    void Stop();                                    // 0x140aab950
    void Update();                                  // 0x140aaba50 per frame

    MS2Ptr<CRandomTargetEffect> FindByPlayerMap(unsigned nId);   // 0x140aabd10
    MS2Ptr<CRandomTargetEffect> FindByNpcMap(unsigned nId);      // 0x140aabde0
    MS2Ptr<CRandomTargetEffect> Find(unsigned nId);              // 0x140aabee0

private:
    CAtlArray<unsigned> m_aIdsA;                    // +0x18
    CString m_strEffectA;                           // +0x38
    CAtlArray<unsigned> m_aIdsB;                    // +0x40
    CString m_strEffectB;                           // +0x60
    unsigned m_nTick;                               // +0x68
    bool m_bToggle;                                 // +0x6c
    unsigned m_nIndex;                              // +0x70
    int m_nMode;                                    // +0x74 0 idle, 1 sequence, 2 flicker
};
