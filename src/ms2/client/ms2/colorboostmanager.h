// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed (unit ?\colorboostdata.cpp).
//
// CColorBoostData: one timed colour-scale boost on an actor (0x20: vfptr, started flag, start time, ...).
// CColorBoostManager: the list of the active boosts of a PCBase (RTTI .?AVCColorBoostManager@@, 0x48 bytes,
// PCBase+0x648). Split from colorboostdata.h so pcbase.h can hold the member without the UI headers.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <NiRefObject.h>
#include <egf/EntityID.h>

#include "ms2/ms2layout.h"

class CColorBoostData
{
public:
    CColorBoostData(float fColorScale, float fDuration, float fAccumRatio);     // 0x14109b6b0
    CColorBoostData(const CColorBoostData& kOther);                             // 0x14109bfa0
    virtual ~CColorBoostData();                                                 // 0x14109b750, ??_G 0x14109b8c0

    // Adds this boost's remaining effect to *pfScale; false once it has expired.
    bool FUN_14109b770(float* pfScale, int nIndex);

private:
    bool m_b08;
    float m_f0c;                                                                // start time
    float m_f10;                                                                // colour scale
    float m_f14;                                                                // duration
    float m_f18;                                                                // accumulation ratio
    float m_f1c;                                                                // the extra scale, fixed on the first update
};
MS2_CHECK_SIZE(CColorBoostData, 0x20);

class CColorBoostManager : public NiRefObject
{
public:
    CColorBoostManager();                                                       // 0x14109bd60
    virtual ~CColorBoostManager();                                              // 0x14109bdc0, ??_G 0x14109c0b0

    void FUN_14109be00(const CColorBoostData& kData);                           // add a boost
    void FUN_14109be30(const egf::EntityID& kId);                               // per-frame update of the actor's colour

private:
    ATL::CAtlList<CColorBoostData> m_boosts;                                    // +0x10
    float m_fScale;                                                             // +0x40 the scale last applied
};
MS2_CHECK_SIZE(CColorBoostManager, 0x48);
