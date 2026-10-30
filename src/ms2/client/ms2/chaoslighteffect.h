// chaoslighteffect.h - the "ChaosLight" effect (effect XML type 0xe): tints a mesh's glow map and chaos materials and
// animates fresnel boost / exponent / dimmer / colour over keyframes. ChaosLightEffectParam (param + defaults),
// ChaosLightTransitionData (keyframe), ChaosLightEffect (runtime effect, TransitionEffect), and the layer pair that
// applies the values to a mesh: ChaosLightEffectLayer (Layer) and ChaosLightEffectLayerManager (LayerManager, owned
// by the WorldService at +0x818). Owning units: ?\chaoslighttransitiondata.cpp (0x1410459c0-0x141049240: keyframe,
// param vfunc_1/6, layer, layer manager) and ?\uichaoslightdialog.cpp (0x141041xxx: ChaosLightEffectParam ctor/dtor/
// copy, ChaosLightEffect). Header name assumed. Member names are invented from use.
#pragma once
#include <vector>
#include <atlcoll.h>
#include <efd/StdContainers.h>
#include "ms2/client/ms2/niavobjectnodealloc.h"
#include <NiMesh.h>
#include <NiColor.h>
#include <NiMaterial.h>
#include "ms2/client/ms2/transitioneffectparam.h"
#include "ms2/client/ms2/layer.h"
#include "ms2/placeholder/postprocesseffect.h"      // Unk_PPSmartC (texture handle)

class ChaosLightEffectLayer;

// 0x38 bytes. vftable 0x142ea33b8 (2 slots: ~, DeleteThis). ctor 0x1410459c0, implicit dtor 0x141047350, ??_G 0x141047730.
class ChaosLightTransitionData : public TransitionData
{
public:
    ChaosLightTransitionData();                                 // 0x1410459c0 defaults 26.09, 5.36, 0, 0.95, 0.57, 0.22
public:
    float m_fFresnelBoost;          // +0x20 "fresnelBoost"
    float m_fFresnelExponent;       // +0x24 "fresnelExponent"
    float m_fDimmer;                // +0x28 "dimmer"
    float m_fRed;                   // +0x2c "rgb" ("r,g,b" floats)
    float m_fGreen;                 // +0x30
    float m_fBlue;                  // +0x34
};
MS2_CHECK_SIZE(ChaosLightTransitionData, 0x38);
MS2_CHECK_OFFSET(ChaosLightTransitionData, m_fFresnelBoost, 0x20);
MS2_CHECK_OFFSET(ChaosLightTransitionData, m_fBlue, 0x34);

// 0xa0 bytes. vftable 0x142ea2e20 (8 slots; overrides 1 and 6). ctor 0x1410415b0, dtor 0x1410439b0, ??_G 0x141044120
// (all in ?\uichaoslightdialog.cpp), operator= 0x141043a30 (keyframes, then the scalars below).
class ChaosLightEffectParam : public TransitionEffectParam
{
public:
    ChaosLightEffectParam();                                    // 0x1410415b0 (type 0xe)
    virtual ~ChaosLightEffectParam() = default;                 // 0x1410439b0
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x141045a60 load the scalars and the keyframes
    virtual CEffectPtr vfunc_6();                               // 6 0x141046110 new ChaosLightEffect

    ChaosLightEffectParam& FUN_141043a30(const ChaosLightEffectParam& rSrc);   // 0x141043a30 copy assign
public:
    MS2_LAYOUT_FRIEND;
    float m_fFresnelBoost;          // +0x70 "fresnelBoost" 26.09
    float m_fFresnelExponent;       // +0x74 "fresnelExponent" 5.36
    float m_fDimmer;                // +0x78 "dimmer" 0
    float m_fRed;                   // +0x7c "rgb" 0.95
    float m_fGreen;                 // +0x80 0.57
    float m_fBlue;                  // +0x84 0.22
    int m_nLayer;                   // +0x88 "layer"
    bool m_bBlink;                  // +0x8c "blink"
    int m_nBlinkBoostStart;         // +0x90 "blinkBoostStart"
    CString m_strNode;              // +0x98 "node"
};
MS2_CHECK_SIZE(ChaosLightEffectParam, 0xa0);
MS2_CHECK_OFFSET(ChaosLightEffectParam, m_fFresnelBoost, 0x70);
MS2_CHECK_OFFSET(ChaosLightEffectParam, m_nLayer, 0x88);
MS2_CHECK_OFFSET(ChaosLightEffectParam, m_bBlink, 0x8c);
MS2_CHECK_OFFSET(ChaosLightEffectParam, m_strNode, 0x98);

// 0x150 bytes. vftable 0x142ea3?? (all in ?\uichaoslightdialog.cpp), GetRTTI 0x141044490, ms_RTTI 0x143acd3d0.
class ChaosLightEffect : public TransitionEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x141044490
public:
    ChaosLightEffect();                                         // 0x1410416a0
    virtual ~ChaosLightEffect();                                // 0x141041750
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x1410417c0 collect the owner's nodes
    virtual void vfunc_4();                                     // 4 0x1410419e0 start: layer on every node
    virtual void vfunc_7();                                     // 7 0x141041ae0 stop: remove the layers
    virtual bool vfunc_9();                                     // 9 0x141041e50 blink, then the keyframe step
    virtual int vfunc_12() { return 0xe; }                      // 12 0x141044440
    virtual void vfunc_13(TransitionData* pFrom, TransitionData* pTo, float fT);   // 13 0x141041c20

    void FUN_1410420d0();                                       // 0x1410420d0 blink step
    void FUN_1410423d0(NiAVObjectPtr spObject);                 // 0x1410423d0 add a layer per chaos-material mesh
public:
    MS2_LAYOUT_FRIEND;
    efd::vector<NiAVObjectPtr> m_vecObjects;                    // +0x58 the effect's target objects (vfunc_3 fills it)
    ATL::CAtlArray<NiPointer<ChaosLightEffectLayer> > m_arrLayers;   // +0x70 the layer made per mesh
    ChaosLightEffectParam m_param;                              // +0x90 the current (interpolated) values: vfunc_13 writes m_param.m_f* (+0x100..0x114)
    double m_dStartTime2;                                       // +0x130 start of the blink clock
    double m_dLastTick;                                         // +0x138
    double m_dPhase;                                            // +0x140 blink phase 0..1
    bool m_bBlinkOn;                                            // +0x148
};
MS2_CHECK_SIZE(ChaosLightEffect, 0x150);
MS2_CHECK_OFFSET(ChaosLightEffect, m_vecObjects, 0x58);
MS2_CHECK_OFFSET(ChaosLightEffect, m_arrLayers, 0x70);
MS2_CHECK_OFFSET(ChaosLightEffect, m_param, 0x90);
MS2_CHECK_OFFSET(ChaosLightEffect, m_bBlinkOn, 0x148);

// 0xd8 bytes. vftable 0x142ea33d0 (21 slots; overrides ~, 18, 19, 20). ctor 0x1410461b0, dtor 0x1410472d0, ??_G 0x141047670.
class ChaosLightEffectLayer : public Layer
{
public:
    // pMesh: the mesh to tint; pTexture: glow texture (null: take the one of the mesh's glow map); pParam: the effect
    // param to start from (null: take the defaults and read the mesh's own chaos material).
    ChaosLightEffectLayer(NiMesh* pMesh, void* pTexture, const ChaosLightEffectParam* pParam);   // 0x1410461b0
    virtual ~ChaosLightEffectLayer() = default;                           // 0x1410472d0
    virtual NiMesh* vfunc_18();                                 // 18 0x1410463e0 the mesh
    virtual void vfunc_19();                                    // 19 0x1410466b0 apply: glow map, chaos material, values
    virtual void vfunc_20();                                    // 20 0x141046820 remove (clears the active flag)

    void FUN_141046410(const ChaosLightEffectParam& rParam);    // 0x141046410 set the param, push the values to the mesh
public:
    MS2_LAYOUT_FRIEND;
    efd::SmartPointer<NiMesh> m_spMesh;     // +0x18
    Unk_PPSmartC m_spTexture;               // +0x20 glow texture
    NiMaterial* m_pMaterial;                // +0x28 the chaos material matching the mesh's current material (or null)
    ChaosLightEffectParam m_param;          // +0x30
    bool m_bActive;                         // +0xd0
};
MS2_CHECK_SIZE(ChaosLightEffectLayer, 0xd8);
MS2_CHECK_OFFSET(ChaosLightEffectLayer, m_spMesh, 0x18);
MS2_CHECK_OFFSET(ChaosLightEffectLayer, m_param, 0x30);
MS2_CHECK_OFFSET(ChaosLightEffectLayer, m_bActive, 0xd0);

// 0x28 bytes. vftable 0x142ea3?? (slots as LayerManager; 18 creates a ChaosLightEffectLayer). ctor 0x141046850, dtor
// 0x141047320, ??_G 0x1410476d0. The WorldService owns the single instance (+0x818, getter 0x141bd3680).
class ChaosLightEffectLayerManager : public LayerManager
{
public:
    ChaosLightEffectLayerManager();                             // 0x141046850 builds the 1x1 white glow texture
    virtual ~ChaosLightEffectLayerManager() = default;                  // 0x141047320
    virtual NiPointer<Layer> vfunc_18(NiAVObject* pObject);     // 18 0x1410469f0

    void* FUN_1410469c0();                                      // 0x1410469c0 the shared white texture
public:
    MS2_LAYOUT_FRIEND;
    Unk_PPSmartC m_spTexture;       // +0x20
};
MS2_CHECK_SIZE(ChaosLightEffectLayerManager, 0x28);
MS2_CHECK_OFFSET(ChaosLightEffectLayerManager, m_spTexture, 0x20);
