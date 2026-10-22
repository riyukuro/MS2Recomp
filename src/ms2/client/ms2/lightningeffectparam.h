// lightningeffectparam.h - the "Lightning" effect (effect XML type 0x10): a jagged textured ribbon between two points
// of the target's point list, rebuilt every few ticks. LightningEffectParam (CEffectParam, texture lists per distance
// class + spread/jointLen/width) and LightningEffect (runtime effect that owns a CMesh strip). Owning unit:
// ?\lightningeffectparam.cpp (0x14144b790-0x14144df10, .text$di 0x1400f7340). Header name assumed from the unit path.
// Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiSmartPointer.h>
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/mesh.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/unk_nodeptr.h"

class NiTexturingProperty;

// 0xc8 bytes. Overrides vfuncs 1, 6. Implicit virtual dtor 0x14144dbf0, ??_G 0x14144dd80.
class LightningEffectParam : public CEffectParam
{
public:
    LightningEffectParam();                                     // 0x14144b790
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x14144b880
    virtual CEffectPtr vfunc_6();                               // 6 0x14144bb00 new LightningEffect
public:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<CString> m_arrTexture[3];    // +0x48 "texturePathA/B/C": textures for near / mid / far (<=256, <=512)
    float m_fSpread;                // +0xa8 "spread" = 1
    float m_fJointLen;              // +0xac "jointLen" = 32
    float m_fWidth;                 // +0xb0 "width" = 10
    int m_nAlphaMode;               // +0xb4 "alphaMode": SWOOSH 0, STANDARD 1, ADD 2
    int m_nSortingMode;             // +0xb8 "sortingMode": OFF 0, INHERIT 1
    unsigned int m_nTextureChangeTick;   // +0xbc "textureChangeTick"
    bool m_bTextureSequence;        // +0xc0 "textureSequence": next texture in order instead of random
};
MS2_CHECK_SIZE(LightningEffectParam, 0xc8);
MS2_CHECK_OFFSET(LightningEffectParam, m_arrTexture, 0x48);
MS2_CHECK_OFFSET(LightningEffectParam, m_fSpread, 0xa8);
MS2_CHECK_OFFSET(LightningEffectParam, m_nTextureChangeTick, 0xbc);
MS2_CHECK_OFFSET(LightningEffectParam, m_bTextureSequence, 0xc0);

// 0xf8 bytes. vftable 13 slots. dtor 0x14144bce0, ??_G 0x14144dd20. RTTI "LightningEffect" 0x143adc928.
class LightningEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x14144ddd0
public:
    LightningEffect();                                          // 0x14144bba0
    virtual ~LightningEffect();                                 // 0x14144bce0
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x14144bdf0 build node + mesh
    virtual void vfunc_4();                                     // 4 0x14144ca70 attach to the scene
    virtual void vfunc_7();                                     // 7 0x14144cb50 detach
    virtual int vfunc_8(void* p);                               // 8 0x14144cbd0 world position of the target node
    virtual bool vfunc_9();                                     // 9 0x14144c9e0 per-update: rebuild the strip
    virtual void vfunc_10(bool bVisible);                       // 10 0x14144cb80
    virtual int vfunc_12();                                     // 12 0x14144ddc0 effect type 0x10

    void Rebuild();                                             // 0x14144cc30 pick the texture, build path + mesh
    void BuildPath(Vector3 kStart, Vector3 kEnd);   // 0x14144d670 jagged path + the two edge lines
public:
    MS2_LAYOUT_FRIEND;
    Unk_NodePtr m_spRoot;           // +0x30 "Effect Root" EffectNode
    Unk_NodePtr m_sp38;             // +0x38 unused
    NiPointer<CMesh> m_spMesh;      // +0x40 "LightningEffect"
    Unk_NodePtr m_spTarget;         // +0x48 node the effect follows (resolved from the target handle)
    float m_fSpread;                // +0x50
    float m_fJointLen;              // +0x54
    float m_fWidth;                 // +0x58
    int m_nUVSets;                  // +0x5c = 1
    ATL::CAtlArray<Vector3> m_arrPath;     // +0x60 centre line
    ATL::CAtlArray<Vector3> m_arrLeft;     // +0x80 centre + width/2 * side
    ATL::CAtlArray<Vector3> m_arrRight;    // +0xa0 centre - width/2 * side
    bool m_bSequence;               // +0xc0 param m_bTextureSequence
    unsigned __int64 m_nSequence;   // +0xc8 last texture index
    unsigned int m_nTick;           // +0xd0 param m_nTextureChangeTick (0 = every update)
    unsigned int m_nLastTick;       // +0xd4
    ATL::CAtlArray<Vector3>* m_pPoints;    // +0xd8 the target's point list
    NiPointer<NiTexturingProperty> m_spTexProp;    // +0xe0
    MS2Ptr<LightningEffectParam> m_spParam;        // +0xe8 (pointer at +0xf0)
};
MS2_CHECK_SIZE(LightningEffect, 0xf8);
MS2_CHECK_OFFSET(LightningEffect, m_spMesh, 0x40);
MS2_CHECK_OFFSET(LightningEffect, m_arrPath, 0x60);
MS2_CHECK_OFFSET(LightningEffect, m_bSequence, 0xc0);
MS2_CHECK_OFFSET(LightningEffect, m_pPoints, 0xd8);
MS2_CHECK_OFFSET(LightningEffect, m_spParam, 0xe8);
