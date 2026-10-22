// beameffect.h - CBeamEffect (RTTI name): the runtime "Beam" effect (effect XML type 0x15), created by
// CBeamEffectParam::vfunc_6. A textured ribbon (CMesh strip) drawn along a Catmull-Rom curve between the first and the
// last point of the target's point list; the curve shape comes from the param's BeamInfo (pointCurve / directionCurve).
// Owning unit: client\ms2\beameffect.cpp (0x140a071a0-0x140a0c300, .text$di 0x1400c2c90). Header name assumed from the
// unit path. Member and helper names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <NiSmartPointer.h>
#include <efd/StdContainers.h>
#include "ms2/client/ms2/effectparam.h"
#include "ms2/client/ms2/beameffectparam.h"
#include "ms2/client/ms2/mesh.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/unk_nodeptr.h"

class NiTexturingProperty;

// The effect target (CEffect::vfunc_3's second argument), the part this effect reads.
struct Unk_BeamTarget
{
    char m_pad_00[0x10];
    void* m_hNode;                                  // +0x10 handle of the owner's scene node
    char m_pad_18[0x10];
    ATL::CAtlArray<Vector3>* m_pPoints;     // +0x28 the points of the beam (first and last are the end points)
};
MS2_CHECK_OFFSET(Unk_BeamTarget, m_hNode, 0x10);
MS2_CHECK_OFFSET(Unk_BeamTarget, m_pPoints, 0x28);

// 0x78 bytes. vftable 13 slots. dtor 0x140a07280, ??_G 0x140a0ac50. RTTI "CBeamEffect" 0x143ab5bb8.
class CBeamEffect : public CEffect
{
    NiDeclareRTTI;                                              // 2 GetRTTI 0x140a0b010
public:
    CBeamEffect();                                              // 0x140a071a0
    virtual ~CBeamEffect();                                     // 0x140a07280
    virtual bool vfunc_3(const CEffectParam* pParam, Unk_EffectTarget* pTarget);   // 3 0x140a07320 build node + mesh
    virtual void vfunc_4();                                     // 4 0x140a07f80 attach to the scene
    virtual void vfunc_7();                                     // 7 0x140a08090 detach
    virtual int vfunc_8(void* p);                               // 8 0x140a08150 world position of the target node
    virtual bool vfunc_9();                                     // 9 0x140a07ef0 per-update: rebuild the strip
    virtual void vfunc_10(bool bVisible);                       // 10 0x140a080c0
    virtual int vfunc_12();                                     // 12 0x140a0afc0 effect type 0x15

    void UpdateMesh();                                          // 0x140a081d0 pick the texture, build curve + strip
    bool BuildCurve(efd::vector<Vector3>& kOut);        // 0x140a08c60 Catmull-Rom samples between the end points
public:
    MS2_LAYOUT_FRIEND;
    NiPointer<CMesh> m_spMesh;      // +0x30 "BeamEffect"
    Unk_NodePtr m_spRoot;           // +0x38 "Effect Root" EffectNode
    NiPointer<NiTexturingProperty> m_spTexProp;    // +0x40
    Unk_NodePtr m_spTarget;         // +0x48 node the effect follows (resolved from the target handle)
    float m_fHalfWidth;             // +0x50 param width / 2
    int m_nQuality;                 // +0x54 param quality (samples per curve segment)
    int m_nUVSets;                  // +0x58 = 1
    ATL::CAtlArray<Vector3>* m_pPoints;    // +0x60 the target's point list
    MS2Ptr<CBeamEffectParam> m_spParam;            // +0x68 (pointer at +0x70)
};
MS2_CHECK_SIZE(CBeamEffect, 0x78);
MS2_CHECK_OFFSET(CBeamEffect, m_spMesh, 0x30);
MS2_CHECK_OFFSET(CBeamEffect, m_spTexProp, 0x40);
MS2_CHECK_OFFSET(CBeamEffect, m_fHalfWidth, 0x50);
MS2_CHECK_OFFSET(CBeamEffect, m_pPoints, 0x60);
MS2_CHECK_OFFSET(CBeamEffect, m_spParam, 0x68);
