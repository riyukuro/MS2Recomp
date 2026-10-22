// ribboneffectparam.h - the "Ribbon" effect (effect XML type 0xd): param + runtime effect. A textured strip (CMesh) drawn
// along the Catmull-Rom curve through the target's point list, or a copy of the first mesh of the param's nif. Owning
// unit: ?\ribboneffectparam.cpp (0x141701380-0x141703a70 .text$mn, .text$di 0x1400ff2b0; dir client\ms2). Header name
// assumed from the unit path. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiSmartPointer.h>
#include <efd/StdContainers.h>
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/mesh.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/unk_nodeptr.h"

// 0x68 bytes. vftable 0x142f5b228 (8 slots, ??_G 0x1417038c0). Overrides slots 1, 5 and 6.
class CRibbonEffectParam : public CEffectParam
{
public:
    CRibbonEffectParam();                                       // 0x141701380
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x141701410 texturePath / nifPath / width / quality / alphaMode
    virtual bool vfunc_5(int n);                                // 5 0x141701560 preload the nif
    virtual CEffectPtr vfunc_6();                               // 6 0x141701610 new CRibbonEffect
public:
    MS2_LAYOUT_FRIEND;
    CString m_strTexturePath;       // +0x48 "texturePath"
    CString m_strNifPath;           // +0x50 "nifPath"
    float m_fWidth;                 // +0x58 "width" = 10
    int m_nQuality;                 // +0x5c "quality" = 4 (samples per curve segment)
    int m_nAlphaMode;               // +0x60 "alphaMode": SWOOSH 0, STANDARD 1, ADD 2
};
MS2_CHECK_SIZE(CRibbonEffectParam, 0x68);
MS2_CHECK_OFFSET(CRibbonEffectParam, m_strTexturePath, 0x48);
MS2_CHECK_OFFSET(CRibbonEffectParam, m_strNifPath, 0x50);
MS2_CHECK_OFFSET(CRibbonEffectParam, m_fWidth, 0x58);
MS2_CHECK_OFFSET(CRibbonEffectParam, m_nAlphaMode, 0x60);

// The effect target (CEffect::vfunc_3's second argument), the part this effect reads.
struct Unk_RibbonTarget
{
    char m_pad_00[0x10];
    void* m_hNode;                                  // +0x10 handle of the owner's scene node
    char m_pad_18[0x10];
    ATL::CAtlArray<Vector3>* m_pPoints;     // +0x28 the points the ribbon follows
};
MS2_CHECK_OFFSET(Unk_RibbonTarget, m_hNode, 0x10);
MS2_CHECK_OFFSET(Unk_RibbonTarget, m_pPoints, 0x28);

// 0x80 bytes. vftable 13 slots. dtor 0x1417017a0, ??_G 0x141703860. RTTI "CRibbonEffect" 0x143ae6a10.
class CRibbonEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x141703910
public:
    CRibbonEffect();                                            // 0x1417016b0
    virtual ~CRibbonEffect();                                   // 0x1417017a0
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x141701850 build node + mesh
    virtual void vfunc_4();                                     // 4 0x141702ae0 attach to the owner node
    virtual void vfunc_7();                                     // 7 0x141702bd0 detach
    virtual int vfunc_8(void* p);                               // 8 0x141702c50 world position of the root
    virtual bool vfunc_9();                                     // 9 0x141702a50 per-update: rebuild the strip
    virtual void vfunc_10(bool bVisible);                       // 10 0x141702c00
    virtual int vfunc_12();                                     // 12 0x141703900 effect type 0xd

    void UpdateMesh();                                          // 0x141702d00 curve through the points + strip
public:
    MS2_LAYOUT_FRIEND;
    Unk_NodePtr m_spOwner;          // +0x30 node the root is attached to (owner node or the effect scene root)
    Unk_NodePtr m_spRoot;           // +0x38 "Effect Root" EffectNode
    Unk_NodePtr m_spUnused40;       // +0x40 (never set)
    NiPointer<CMesh> m_spMesh;      // +0x48 "RibbonEffect"
    Unk_NodePtr m_spTarget;         // +0x50 node of the target handle
    float m_fHalfWidth;             // +0x58 param width / 2
    int m_nQuality;                 // +0x5c param quality
    int m_nUVSets;                  // +0x60 = 1
    float m_fFadeStart;             // +0x64 = 0 alpha ramp: start
    float m_fFadeEnd;               // +0x68 = 1 alpha ramp: end
    float m_fAlphaFrom;             // +0x6c = 1
    float m_fAlphaTo;               // +0x70 = 1
    ATL::CAtlArray<Vector3>* m_pPoints;    // +0x78 the target's point list
};
MS2_CHECK_SIZE(CRibbonEffect, 0x80);
MS2_CHECK_OFFSET(CRibbonEffect, m_spOwner, 0x30);
MS2_CHECK_OFFSET(CRibbonEffect, m_spMesh, 0x48);
MS2_CHECK_OFFSET(CRibbonEffect, m_spTarget, 0x50);
MS2_CHECK_OFFSET(CRibbonEffect, m_fHalfWidth, 0x58);
MS2_CHECK_OFFSET(CRibbonEffect, m_nUVSets, 0x60);
MS2_CHECK_OFFSET(CRibbonEffect, m_fAlphaTo, 0x70);
MS2_CHECK_OFFSET(CRibbonEffect, m_pPoints, 0x78);
