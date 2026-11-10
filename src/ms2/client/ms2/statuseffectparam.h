// statuseffectparam.h - the "StatusEffect" effect (effect XML type 8): tints the target's meshes (extra data on
// each active-material mesh) for an elemental status (ice, fire, poison, dark, super). Param (CEffectParam) +
// runtime effect (CEffect). Owning unit: ?\statuseffectparam.cpp (0x141801040-0x141803210). Header name assumed
// from the unit path.
#pragma once
#include <NiNode.h>
#include <efd/SmartPointer.h>
#include "ms2/client/ms2/effectparam.h"

// 0x50 bytes. vftable 8 slots (overrides 1, 6). Implicit virtual dtor, ??_G 0x141802d70.
class CStatusEffectParam : public CEffectParam
{
public:
    CStatusEffectParam();                                       // 0x141801040
    virtual void vfunc_1(TiXmlElement* pNode);                 // 1 0x1418010a0 <category="ice|fire|poison|dark|super">
    virtual CEffectPtr vfunc_6();                               // 6 0x1418010f0 new CStatusEffect
public:
    CString m_strCategory;          // +0x48 "category" attribute
};
MS2_CHECK_SIZE(CStatusEffectParam, 0x50);
MS2_CHECK_OFFSET(CStatusEffectParam, m_strCategory, 0x48);

// 0x48 bytes. vftable 13 slots. ??_G 0x141802d10. RTTI "CStatusEffect" 0x143aec370.
class CStatusEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x141802dc0
public:
    CStatusEffect();                                            // 0x141801190
    virtual ~CStatusEffect();                                   // 0x1418011e0
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x141801220 category -> kind
    virtual void vfunc_4();                                     // 4 0x141801520 register on the node (reference count)
    virtual void vfunc_7();                                     // 7 0x141801720 unregister from the node
    virtual int vfunc_8(void* pOut);                            // 8 0x1418018b0 copy the node's world translate
    virtual bool vfunc_9();                                     // 9 0x141801400 update while running
    virtual int vfunc_12();                                     // 12 0x141802db0 return 8

    void ApplyTint(void* pUnused);                            // 0x141801900 apply the tint to every active mesh

public:
    int m_nKind;                    // +0x30 0 ice, 1 fire, 2 poison, 3 dark, 4 super, 7 other
    efd::SmartPointer<NiNode> m_spNode;     // +0x38 target node
    bool m_bSuper;                  // +0x40 category "super": blinks
    bool m_bFlag;                   // +0x41 blink phase
    unsigned int m_dwLastTick;      // +0x44
};
MS2_CHECK_SIZE(CStatusEffect, 0x48);
MS2_CHECK_OFFSET(CStatusEffect, m_nKind, 0x30);
MS2_CHECK_OFFSET(CStatusEffect, m_spNode, 0x38);
MS2_CHECK_OFFSET(CStatusEffect, m_dwLastTick, 0x44);
