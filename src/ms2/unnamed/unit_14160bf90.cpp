// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The NPC's jump-arc mover (CNpc +0xdb0, driven from
// CNpc::vfunc_53): moves a position along a parabolic arc between two points and derives the heading. Unit and member
// names are invented from use.
// MS2-UNIT: unit_14160bf90
// MS2-RANGE: 0x14160bf90-0x14160c280 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nipoint3.h"
#include "hook/ms2hook.h"

// Arc between m_vStart and m_vEnd taking m_fDuration seconds, peaking m_fHeight * 1 above the straight line.
class Unk_ArcMover
{
public:
    void FUN_14160bf90(float fDelta, Unk_StreamPoint* pPos, float* pAngle);     // advance and sample
    bool IsMoving() const;                                                 // moving
    CString GetName() const;                                              // the moving animation name

    bool m_bMoving;                 // +0x00
    Unk_StreamPoint m_vStart;       // +0x04
    Unk_StreamPoint m_vEnd;         // +0x10
    float m_fElapsed;               // +0x1c
    float m_fDuration;              // +0x20
    float m_fHeight;                // +0x24
    CString m_strName;              // +0x28
};

float FUN_140a4e660(float fY, float fX);                    // atan2

// @0x14160c230
float FUN_14160c230(const Unk_StreamPoint* p)
{
    return p->x * p->x + p->y * p->y + p->z * p->z;
}
MS2_REPLACE(0x14160C230, FUN_14160c230, 72, 0x8F023533);

// @0x14160bf90
// MS2-FUNCTIONAL: exe frame is 7 bytes larger (extra temporaries in the arc blend); behaviour-equivalent
void Unk_ArcMover::FUN_14160bf90(float fDelta, Unk_StreamPoint* pPos, float* pAngle)
{
    m_fElapsed = m_fElapsed + fDelta;
    if (!(m_fElapsed < m_fDuration))
    {
        m_fElapsed = m_fDuration;
        m_strName = "";
        m_bMoving = false;
    }
    float fT = (m_fDuration == 0.0f) ? 1.0f : m_fElapsed / m_fDuration;
    *pPos = FUN_1409ab5c0(1.0f - fT, m_vStart).FUN_14097fd50(FUN_1409ab5c0(fT, m_vEnd));
    pPos->z = pPos->z + m_fHeight * 4.0f * fT * (1.0f - fT);
    Unk_StreamPoint vDir = m_vEnd.FUN_140965c40(m_vStart);
    if (FUN_14160c230(&vDir) > 0.0f)
        *pAngle = FUN_140a4e660(vDir.y, vDir.x) * 180.0f / 3.1415927f + 90.0f;
}

// @0x14160c1c0
bool Unk_ArcMover::IsMoving() const
{
    return m_bMoving;
}
MS2_REPLACE_METHOD(0x14160C1C0, Unk_ArcMover, IsMoving, 14, 0xDA496095);

// @0x14160c1e0
CString Unk_ArcMover::GetName() const
{
    return m_strName;
}
MS2_REPLACE_METHOD(0x14160C1E0, Unk_ArcMover, GetName, 66, 0x9DF20AC9);
