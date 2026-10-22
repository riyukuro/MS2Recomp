// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See arccontroller.h.
// MS2-UNIT: ?\arccontroller.cpp
// MS2-RANGE: 0x1400c0150-0x1400c0170 .text$di
// MS2-RANGE: 0x1409ab110-0x1409ab7c0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\arccontroller.cpp"
#include "ms2/placeholder/ms2stdafx.h"

#include "arccontroller.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

bool FUN_14028d470(float a, float b);   // approximately equal

// @0x1400c0150
const NiRTTI CArcController::ms_RTTI("CArcController", 0);

// @0x1409ab110
CArcController::CArcController()
{
}

// @0x1409ab180
CArcController::~CArcController()
{
}

// @0x1409ab1b0
bool CArcController::FUN_1409ab1b0(Vector3 from, Vector3 to, float speed, float gravityScale)
{
    m_bRising = true;
    m_offset = DAT_143b01a60;
    m_position = DAT_143b01a60;
    m_elapsed = 0;
    float fDistance = FUN_140966ea0(from, to);
    if (FUN_14028d470(fDistance, 0.0f))
        return false;
    m_arc.FUN_141479ed0(from, to, speed, gravityScale * 100.0f);
    return true;
}
MS2_REPLACE_METHOD(0x1409ab1b0, CArcController, FUN_1409ab1b0, 324, 0xAA0CCC51);

// @0x1409ab300
float CArcController::FUN_1409ab300() const
{
    return m_arc.m_flightScale;
}
MS2_REPLACE_METHOD(0x1409ab300, CArcController, FUN_1409ab300, 16, 0xEC6BFF26);

// @0x1409ab320
bool CArcController::IsRising() const
{
    return m_bRising;
}
MS2_REPLACE_METHOD(0x1409ab320, CArcController, IsRising, 15, 0x138EA3C5);

// @0x1409ab340
Vector3 CArcController::GetPosition() const
{
    return m_position;
}
MS2_REPLACE_METHOD(0x1409ab340, CArcController, GetPosition, 41, 0xC42EA0F4);

// @0x1409ab370
bool CArcController::FUN_1409ab370() const
{
    return m_elapsed >= m_arc.m_flightScale;
}
MS2_REPLACE_METHOD(0x1409ab370, CArcController, FUN_1409ab370, 55, 0x3F6B811E);

// @0x1409ab3b0
void CArcController::FUN_1409ab3b0(float fDelta)
{
    if (m_elapsed >= m_arc.m_flightScale) {
        m_position = m_arc.m_target;
    } else {
        m_elapsed += fDelta;
        if (m_elapsed > m_arc.m_flightScale)
            m_elapsed = m_arc.m_flightScale;
        Vector3 delta = FUN_1409ab5c0(m_arc.m_speed * m_arc.m_angle.m_cos * m_elapsed, m_arc.m_direction);
        delta.z = 0.5f * m_arc.m_gravity * m_elapsed * m_elapsed + m_arc.m_speed * m_arc.m_angle.m_sin * m_elapsed;
        if (m_offset.FUN_140552690(DAT_143b01a60))
            m_offset = delta;
        if (m_bRising && delta.z < m_offset.z)
            m_bRising = false;
        m_offset = delta;
        m_position = m_arc.m_origin.FUN_14097fd50(delta);
    }
}
MS2_REPLACE_METHOD(0x1409ab3b0, CArcController, FUN_1409ab3b0, 430, 0x4EB1F775);

// @0x1409ab5c0 (efd::Point3 operator*(float, const Point3&), declared in nipoint3.h)
Vector3 FUN_1409ab5c0(float fScalar, const Vector3& pt)
{
    return Vector3(fScalar * pt.x, fScalar * pt.y, fScalar * pt.z);
}

// @0x1409ab690
const NiRTTI* CArcController::GetRTTI() const { return &ms_RTTI; }

MS2_EMIT_CRT_MEMMOVE_S();
