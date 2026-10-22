// swoosheffectparam.h - the "Swoosh" effect (effect XML type 7): a textured trail ribbon that follows two nodes of the
// target (TrailNode1 / TrailNode2), sampled over time and smoothed with a Catmull-Rom curve. Param (CEffectParam) +
// runtime effect (CEffect). Owning unit: ?\swoosheffectparam.cpp (0x14181cf50-0x141821bf0, .text$di 0x14010d290).
// Header name assumed from the unit path. Member names are invented from use.
#pragma once
#include <afx.h>
#include <NiSmartPointer.h>
#include <NiAVObject.h>
#include <efd/StdContainers.h>
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/mesh.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/unk_nodeptr.h"

// 0x78 bytes. Overrides vfuncs 1, 3, 4, 5, 6. Implicit virtual dtor 0x141820cd0, ??_G 0x141820dc0.
class CSwooshEffectParam : public CEffectParam
{
public:
    CSwooshEffectParam();                                       // 0x14181cf50
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x14181d010
    virtual bool vfunc_3();                                     // 3 0x14181d1e0 preload the nif (true when none)
    virtual void vfunc_4();                                     // 4 0x14181d290 release the nif cache entry
    virtual bool vfunc_5(int n);                                // 5 0x14181d330 load the nif into the cache
    virtual CEffectPtr vfunc_6();                               // 6 0x14181d3f0 new CSwooshEffect
public:
    MS2_LAYOUT_FRIEND;
    CString m_strTexturePath;       // +0x48 "texturePath" (used when there is no nif)
    CString m_strNifPath;           // +0x50 "nifPath" (a model whose first mesh supplies the material)
    CString m_strNode1;             // +0x58 "node1"
    CString m_strNode2;             // +0x60 "node2"
    float m_fLength;                // +0x68 "length" = 0.1 (seconds of trail)
    int m_nQuality;                 // +0x6c "quality" = 4, at most 4 (curve samples per control segment)
    int m_nAlphaMode;               // +0x70 "alphaMode": SWOOSH 0, STANDARD 1, ADD 2
    int m_nSampling;                // +0x74 "sampling" = 15, at most 60 (control points per second)
};
MS2_CHECK_SIZE(CSwooshEffectParam, 0x78);
MS2_CHECK_OFFSET(CSwooshEffectParam, m_strTexturePath, 0x48);
MS2_CHECK_OFFSET(CSwooshEffectParam, m_strNode2, 0x60);
MS2_CHECK_OFFSET(CSwooshEffectParam, m_fLength, 0x68);
MS2_CHECK_OFFSET(CSwooshEffectParam, m_nSampling, 0x74);

// 0xf0 bytes. vftable 13 slots. dtor 0x14181d650, ??_G 0x141820d60. RTTI "CSwooshEffect" 0x143aef0b8.
class CSwooshEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x141820f90
public:
    CSwooshEffect();                                            // 0x14181d490
    virtual ~CSwooshEffect();                                   // 0x14181d650
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x14181d760 build the ribbon mesh
    virtual void vfunc_4();                                     // 4 0x14181ed70 attach to the target node
    virtual void vfunc_7();                                     // 7 0x14181f0c0 detach
    virtual int vfunc_8(void* p);                               // 8 0x14181f140 world position of the root
    virtual bool vfunc_9();                                     // 9 0x14181ecd0 per-update
    virtual void vfunc_10(bool bVisible);                       // 10 0x14181f0f0
    virtual int vfunc_12();                                     // 12 0x141820f80 effect type 7

    void UpdateTrail();                                         // 0x14181f1d0 sample the nodes, rebuild the strip
public:
    MS2_LAYOUT_FRIEND;
    Unk_NodePtr m_spRoot;           // +0x30 "Effect Root" EffectNode (a SeparateNode child holds the mesh)
    Unk_NodePtr m_spUnused38;       // +0x38 (initialised, never used here)
    NiPointer<CMesh> m_spMesh;      // +0x40 "SwooshEffect"
    NiAVObjectPtr m_spTrail1;       // +0x48 TrailNode1 (node named by the param's node1)
    NiAVObjectPtr m_spTrail2;       // +0x50 TrailNode2
    Unk_NodePtr m_spTarget;         // +0x58 node the effect follows
    int m_nUVSets;                  // +0x60 = 1 (taken from the nif's mesh when there is one)
    int m_nCurveSamples;            // +0x64 samples kept in the ribbon (segments * quality)
    int m_nSegments;                // +0x68 control segments kept (length * sampling rate)
    int m_unk_6c;                   // +0x6c
    efd::vector<Vector3> m_kPointsA;    // +0x70 trail 1 control points (reserved 0x28)
    efd::vector<Vector3> m_kPointsB;    // +0x88 trail 2 control points
    efd::vector<Vector3> m_kCurveA;     // +0xa0 trail 1 smoothed samples
    efd::vector<Vector3> m_kCurveB;     // +0xb8 trail 2 smoothed samples
    double m_dLastSample;           // +0xd0 time of the last control point
    float m_fInterval;              // +0xd8 seconds between control points
    CString m_strNode1;             // +0xe0 param node1
    CString m_strNode2;             // +0xe8 param node2
};
MS2_CHECK_SIZE(CSwooshEffect, 0xf0);
MS2_CHECK_OFFSET(CSwooshEffect, m_spRoot, 0x30);
MS2_CHECK_OFFSET(CSwooshEffect, m_spMesh, 0x40);
MS2_CHECK_OFFSET(CSwooshEffect, m_spTarget, 0x58);
MS2_CHECK_OFFSET(CSwooshEffect, m_nUVSets, 0x60);
MS2_CHECK_OFFSET(CSwooshEffect, m_kPointsA, 0x70);
MS2_CHECK_OFFSET(CSwooshEffect, m_kCurveB, 0xb8);
MS2_CHECK_OFFSET(CSwooshEffect, m_dLastSample, 0xd0);
MS2_CHECK_OFFSET(CSwooshEffect, m_strNode2, 0xe8);
