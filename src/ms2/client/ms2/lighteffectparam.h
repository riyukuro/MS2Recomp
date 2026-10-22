// lighteffectparam.h - the "Light" effect (effect XML type 9): a point light on the effect root that fades through
// keyframes. CLightEffectParam (param, TransitionEffectParam + light settings), LightEffectTransitionData (one
// keyframe: diffuse / specular / dimmer / range) and CLightEffect (runtime effect, TransitionEffect that owns an
// "EffectPointLight" entity). Owning unit: ?\lighteffectparam.cpp (0x1414494d0-0x14144b790, .text$di 0x1400f7290).
// Header name assumed from the unit path. Member names are invented from use.
#pragma once
#include "ms2/client/ms2/transitioneffectparam.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/unk_nodeptr.h"
#include "ms2/client/ms2/cubespawnobject.h"        // Unk_EntRef

// 12-byte RGB colour (the entity "colour" property value type). Arithmetic is the inline operators of this TU.
struct Unk_LightColor
{
    Unk_LightColor(float fR, float fG, float fB);                  // 0x1406c4340
    Unk_LightColor FUN_1414424f0(float f) const;                    // operator*(float)
    Unk_LightColor operator-(const Unk_LightColor& o) const;        // 0x14144b3f0
    Unk_LightColor operator+(const Unk_LightColor& o) const;        // 0x14144b480
    friend Unk_LightColor operator*(float f, const Unk_LightColor& c) { return c.FUN_1414424f0(f); }   // 0x14144b3b0
    float r, g, b;
};
MS2_CHECK_SIZE(Unk_LightColor, 12);

// 1-byte flag set (commonfiles bitset<3>, bitset.inl): which parts of the parent transform the light follows.
struct Unk_LightUpdateBits;
struct Unk_BitRef                                                   // proxy returned by operator[]
{
    Unk_BitRef(Unk_LightUpdateBits* pBits, unsigned nPos);          // 0x14144b240
    Unk_BitRef& operator=(bool bValue);                             // 0x14144b2f0
    operator bool() const;                                          // 0x14154f4b0 (nifeffectparam.cpp)
    Unk_LightUpdateBits* m_pBits;
    unsigned m_nPos;
};
struct Unk_LightUpdateBits
{
    Unk_LightUpdateBits();                                          // 0x140afed60
    Unk_BitRef operator[](unsigned nPos);                           // 0x14144b330
    unsigned char m_bits;
};
MS2_CHECK_SIZE(Unk_LightUpdateBits, 1);

// 0x40 bytes. vftable 0x142f8b3a8 (2 slots: ~, DeleteThis). Implicit dtor 0x14144b2d0, ??_G 0x14144b5b0.
class LightEffectTransitionData : public TransitionData
{
public:
    LightEffectTransitionData();                                // 0x14144b1d0
public:
    Unk_LightColor m_clrDiffuse;    // +0x20 "diffuse" "r,g,b" 0..255
    Unk_LightColor m_clrSpecular;   // +0x2c "specular"
    float m_fDimmer;                // +0x38 "dimmer"
    float m_fRange;                 // +0x3c "range"
};
MS2_CHECK_SIZE(LightEffectTransitionData, 0x40);
MS2_CHECK_OFFSET(LightEffectTransitionData, m_clrDiffuse, 0x20);
MS2_CHECK_OFFSET(LightEffectTransitionData, m_fRange, 0x3c);

// 0xb8 bytes. vftable 0x142f8b348 (8 slots). implicit dtor 0x14144b2a0, ??_G 0x14144b570.
class CLightEffectParam : public TransitionEffectParam
{
public:
    CLightEffectParam();                                        // 0x1414494d0
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x141449600
    virtual CEffectPtr vfunc_6();                               // 6 0x14144a0f0 new CLightEffect
public:
    MS2_LAYOUT_FRIEND;
    CString m_strParentNode;        // +0x70 <attachInfo parentNode>
    Vector3 m_ptTranslate;  // +0x78 <transform translate>
    Unk_LightColor m_clrDiffuse;    // +0x84 <light diffuse> (default 1,1,1 if not 3 components)
    Unk_LightColor m_clrSpecular;   // +0x90 <light specular>
    float m_fDimmer;                // +0x9c 1.0
    float m_fRange;                 // +0xa0 1000.0
    float m_fAttConstant;           // +0xa4 1.0
    float m_fAttLinear;             // +0xa8
    float m_fAttQuadratic;          // +0xac
    bool m_bUsePreDataTransform;    // +0xb0
    Unk_LightUpdateBits m_update;   // +0xb1 <update translate/rotation/scale>
};
MS2_CHECK_SIZE(CLightEffectParam, 0xb8);
MS2_CHECK_OFFSET(CLightEffectParam, m_strParentNode, 0x70);
MS2_CHECK_OFFSET(CLightEffectParam, m_ptTranslate, 0x78);
MS2_CHECK_OFFSET(CLightEffectParam, m_clrSpecular, 0x90);
MS2_CHECK_OFFSET(CLightEffectParam, m_fDimmer, 0x9c);
MS2_CHECK_OFFSET(CLightEffectParam, m_bUsePreDataTransform, 0xb0);
MS2_CHECK_OFFSET(CLightEffectParam, m_update, 0xb1);

// 0x88 bytes. vftable 0x142f8b3e8 (14 slots). dtor 0x14144a240, ??_G 0x14144b510. RTTI "CLightEffect" 0x143adc900.
class CLightEffect : public TransitionEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x14144b620
public:
    CLightEffect();                                             // 0x14144a190
    virtual ~CLightEffect();
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x14144a2d0 build the light
    virtual void vfunc_4();                                     // 4 0x14144ad00 start
    virtual void vfunc_7();                                     // 7 0x14144adf0 destroy the light entity
    virtual bool vfunc_9();                                     // 9 0x14144acc0
    virtual void vfunc_10(bool bVisible);                       // 10 0x14144b060 dimmer 0 when hidden
    virtual int vfunc_12();                                     // 12 0x14144b610 effect type 9
    virtual void vfunc_13(TransitionData* pFrom, TransitionData* pTo, float fT);   // 13 0x14144ae60

    void FUN_14144b0d0();                                       // 0x14144b0d0 follow the light node: position property
public:
    MS2_LAYOUT_FRIEND;
    Unk_NodePtr m_spParent;         // +0x58 node the light hangs from (effect root or the named node)
    Unk_NodePtr m_spOuter;          // +0x60 root or the SeparateNode wrapping it
    Unk_NodePtr m_spLightNode;      // +0x68 "Light Effect Root" EffectNode
    Unk_EntRef m_entity;            // +0x70 the "EffectPointLight" entity
    float m_fDimmer;                // +0x78
    Vector3 m_ptTranslate;  // +0x7c
};
MS2_CHECK_SIZE(CLightEffect, 0x88);
MS2_CHECK_OFFSET(CLightEffect, m_spParent, 0x58);
MS2_CHECK_OFFSET(CLightEffect, m_entity, 0x70);
MS2_CHECK_OFFSET(CLightEffect, m_ptTranslate, 0x7c);
