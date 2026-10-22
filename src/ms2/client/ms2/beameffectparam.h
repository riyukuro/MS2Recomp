// beameffectparam.h - the "Beam" effect parameters (effect XML type 0x15): a textured beam/trail drawn along a curve.
// Param (CEffectParam) + the beam curve descriptions BeamInfo / BeamPointCurveInfo / BeamDirectionCurveInfo (all
// CPtred-based, selected by <beamInfo type="pointCurve|directionCurve">). Owning unit: client\ms2\beameffectparam.cpp
// (0x140a0c300-0x140a0cd30). Header name assumed from the unit path. Member names are invented from use.
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include "ms2/client/ms2/effectparam.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"

// 0x20 bytes. Implicit virtual dtor 0x140a0cb10, ??_G 0x140a0cc70.
class BeamInfo : public CPtred
{
public:
    explicit BeamInfo(long nType);                              // 0x140a0ca60
    virtual bool vfunc_1(Unk_140165cf0* pNode);                 // 1 0x140a0c770 node != NULL
public:
    MS2_LAYOUT_FRIEND;
    long m_nType;                   // +0x18 1 = pointCurve, 2 = directionCurve
};
MS2_CHECK_SIZE(BeamInfo, 0x20);

// 0x30 bytes. Implicit virtual dtor 0x140a0cb30, ??_G 0x140a0ccb0.
class BeamPointCurveInfo : public BeamInfo
{
public:
    BeamPointCurveInfo();                                       // 0x140a0caa0
    virtual bool vfunc_1(Unk_140165cf0* pNode);                 // 1 0x140a0c790 passThroughPoint
public:
    Vector3 m_kPassThroughPoint;    // +0x20
};
MS2_CHECK_SIZE(BeamPointCurveInfo, 0x30);

// 0x28 bytes. Implicit virtual dtor 0x140a0caf0, ??_G 0x140a0cc30.
class BeamDirectionCurveInfo : public BeamInfo
{
public:
    BeamDirectionCurveInfo();                                   // 0x140a0ca10
    virtual bool vfunc_1(Unk_140165cf0* pNode);                 // 1 0x140a0c800 directionRate / lengthRate (default 0.5)
public:
    float m_fDirectionRate;         // +0x20
    float m_fLengthRate;            // +0x24
};
MS2_CHECK_SIZE(BeamDirectionCurveInfo, 0x28);

// 0x88 bytes. Overrides vfuncs 1, 6. Implicit virtual dtor 0x140a0cb50, ??_G 0x140a0ccf0.
class CBeamEffectParam : public CEffectParam
{
public:
    CBeamEffectParam();                                         // 0x140a0c300
    virtual void vfunc_1(Unk_140165cf0* pNode);                 // 1 0x140a0c3a0
    virtual CEffectPtr vfunc_6();                               // 6 0x140a0c6d0 new CBeamEffect
public:
    MS2_LAYOUT_FRIEND;
    float m_fWidth;                 // +0x48 "width" = 10
    int m_nQuality;                 // +0x4c "quality" = 4
    int m_nAlphaMode;               // +0x50 "alphaMode": SWOOSH 0, STANDARD 1, ADD 2
    ATL::CAtlArray<CString> m_arrTexturePath;     // +0x58 "texturePath" (split list)
    MS2Ptr<BeamInfo> m_pBeamInfo;   // +0x78 (pointer at +0x80)
};
MS2_CHECK_SIZE(CBeamEffectParam, 0x88);
MS2_CHECK_OFFSET(CBeamEffectParam, m_arrTexturePath, 0x58);
