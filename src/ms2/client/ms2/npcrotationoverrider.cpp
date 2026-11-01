// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\npcrotationoverrider.cpp
// MS2-RANGE: 0x14160c280-0x14160c6d0 .text$mn
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\npcrotationoverrider.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"
#include "npcrotationoverrider.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

#include <efd/EEMath.h>                                 // C3: efd::Clamp was FUN_140a17940
float FUN_1409f2310(float f);                           // sin

// @0x14160c280
CNPCRotationOverrider::CNPCRotationOverrider()
{
    m_fFrom = 0.0f;
    m_fTo = 0.0f;
    m_fDuration = 0.0f;
    m_fElapsed = 0.0f;
}

// @0x14160c2f0
CNPCRotationOverrider::~CNPCRotationOverrider()
{
}

// @0x14160c3f0
bool CNPCRotationOverrider::FUN_14160c3f0(float* pfAngle, float fDelta)
{
    m_fElapsed += fDelta;
    bool bFinished = false;
    if (m_fElapsed >= m_fDuration) {
        m_fElapsed = m_fDuration;
        bFinished = true;
        *pfAngle = m_fTo;
    } else {
        *pfAngle = FUN_14160c500();
    }
    if (*pfAngle < 0.0f)
        *pfAngle = *pfAngle + 360.0f;
    if (*pfAngle >= 360.0f)
        *pfAngle = *pfAngle - 360.0f;
    return !bFinished;
}
MS2_REPLACE_METHOD(0x14160C3F0, CNPCRotationOverrider, FUN_14160c3f0, 257, 0xC30D598D);

// @0x14160c500
float CNPCRotationOverrider::FUN_14160c500()
{
    float fHalf = m_fDuration * 0.5f;
    float fRatio = 0.0f;
    if (fHalf > m_fElapsed) {
        float fT = efd::Clamp(m_fElapsed / fHalf, 0.0f, 1.0f);
        fRatio = -0.15915494f * FUN_1409f2310(3.1415927f * fT - 1.5707964f) + 0.5f * fT;
    } else {
        float fT = efd::Clamp(2.0f - m_fElapsed / fHalf, 0.0f, 1.0f);
        fRatio = 1.0f - (-0.15915494f * FUN_1409f2310(3.1415927f * fT - 1.5707964f) + 0.5f * fT);
    }
    return m_fFrom + fRatio * (m_fTo - m_fFrom);
}
MS2_REPLACE_METHOD(0x14160C500, CNPCRotationOverrider, FUN_14160c500, 357, 0x06A522B3);
