// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Unnamed unit unit_1408e1840: seven instantiations of one
// "resize window" template (set the three float thresholds, recompute the 64-bit low / high marks, and re-seat the
// current position when it falls outside). Names invented from shape; the per-type callees live in the unit before it.
// MS2-UNIT: unit_1408e1840
// MS2-RANGE: 0x1408e1840-0x1408e2330 .text$mn
#define MS2_THIS_FILE ""

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/ms2recover.h"

struct Unk_ThresholdWindow
{
    void* m_pUnused;                    // +0x00
    unsigned long long m_uPos;          // +0x08 current position
    unsigned int m_uSize;               // +0x10 base size
    float m_f14;                        // +0x14
    float m_fLow;                       // +0x18 low mark as a fraction of the size
    float m_fHigh;                      // +0x1c high mark as a fraction of the size
    unsigned long long m_uHighMark;     // +0x20
    unsigned long long m_uLowMark;      // +0x28
};

unsigned int FUN_1408de580(Unk_ThresholdWindow* pWin, unsigned long long uPos);
void FUN_1408dec10(Unk_ThresholdWindow* pWin, unsigned int uValue);
unsigned int FUN_1408de670(Unk_ThresholdWindow* pWin, unsigned long long uPos);
void FUN_1408dee40(Unk_ThresholdWindow* pWin, unsigned int uValue);
unsigned int FUN_1408de760(Unk_ThresholdWindow* pWin, unsigned long long uPos);
void FUN_1408df070(Unk_ThresholdWindow* pWin, unsigned int uValue);
unsigned int FUN_1408de850(Unk_ThresholdWindow* pWin, unsigned long long uPos);
void FUN_1408df2a0(Unk_ThresholdWindow* pWin, unsigned int uValue);
unsigned int FUN_1408de940(Unk_ThresholdWindow* pWin, unsigned long long uPos);
void FUN_1408df4d0(Unk_ThresholdWindow* pWin, unsigned int uValue);
unsigned int FUN_1408dea30(Unk_ThresholdWindow* pWin, unsigned long long uPos);
void FUN_1408df700(Unk_ThresholdWindow* pWin, unsigned int uValue);
unsigned int FUN_1408deb20(Unk_ThresholdWindow* pWin, unsigned long long uPos);
void FUN_1408df930(Unk_ThresholdWindow* pWin, unsigned int uValue);
void FUN_1408e1d10(Unk_ThresholdWindow* pWin);
void FUN_1408e1df0(Unk_ThresholdWindow* pWin);
void FUN_1408e1ed0(Unk_ThresholdWindow* pWin);
void FUN_1408e1fb0(Unk_ThresholdWindow* pWin);
void FUN_1408e2090(Unk_ThresholdWindow* pWin);
void FUN_1408e2170(Unk_ThresholdWindow* pWin);
void FUN_1408e2250(Unk_ThresholdWindow* pWin);

// @0x1408e1840
void FUN_1408e1840(Unk_ThresholdWindow* pWin, float f14, float fLow, float fHigh, bool bReseat)
{
    pWin->m_f14 = f14;
    pWin->m_fLow = fLow;
    pWin->m_fHigh = fHigh;
    FUN_1408e1d10(pWin);
    if (bReseat && (pWin->m_uPos > pWin->m_uHighMark || pWin->m_uPos < pWin->m_uLowMark))
    {
        FUN_1408dec10(pWin, FUN_1408de580(pWin, pWin->m_uPos));
    }
}

// @0x1408e18f0
void FUN_1408e18f0(Unk_ThresholdWindow* pWin, float f14, float fLow, float fHigh, bool bReseat)
{
    pWin->m_f14 = f14;
    pWin->m_fLow = fLow;
    pWin->m_fHigh = fHigh;
    FUN_1408e1df0(pWin);
    if (bReseat && (pWin->m_uPos > pWin->m_uHighMark || pWin->m_uPos < pWin->m_uLowMark))
    {
        FUN_1408dee40(pWin, FUN_1408de670(pWin, pWin->m_uPos));
    }
}

// @0x1408e19a0
void FUN_1408e19a0(Unk_ThresholdWindow* pWin, float f14, float fLow, float fHigh, bool bReseat)
{
    pWin->m_f14 = f14;
    pWin->m_fLow = fLow;
    pWin->m_fHigh = fHigh;
    FUN_1408e1ed0(pWin);
    if (bReseat && (pWin->m_uPos > pWin->m_uHighMark || pWin->m_uPos < pWin->m_uLowMark))
    {
        FUN_1408df070(pWin, FUN_1408de760(pWin, pWin->m_uPos));
    }
}

// @0x1408e1a50
void FUN_1408e1a50(Unk_ThresholdWindow* pWin, float f14, float fLow, float fHigh, bool bReseat)
{
    pWin->m_f14 = f14;
    pWin->m_fLow = fLow;
    pWin->m_fHigh = fHigh;
    FUN_1408e1fb0(pWin);
    if (bReseat && (pWin->m_uPos > pWin->m_uHighMark || pWin->m_uPos < pWin->m_uLowMark))
    {
        FUN_1408df2a0(pWin, FUN_1408de850(pWin, pWin->m_uPos));
    }
}

// @0x1408e1b00
void FUN_1408e1b00(Unk_ThresholdWindow* pWin, float f14, float fLow, float fHigh, bool bReseat)
{
    pWin->m_f14 = f14;
    pWin->m_fLow = fLow;
    pWin->m_fHigh = fHigh;
    FUN_1408e2090(pWin);
    if (bReseat && (pWin->m_uPos > pWin->m_uHighMark || pWin->m_uPos < pWin->m_uLowMark))
    {
        FUN_1408df4d0(pWin, FUN_1408de940(pWin, pWin->m_uPos));
    }
}

// @0x1408e1bb0
void FUN_1408e1bb0(Unk_ThresholdWindow* pWin, float f14, float fLow, float fHigh, bool bReseat)
{
    pWin->m_f14 = f14;
    pWin->m_fLow = fLow;
    pWin->m_fHigh = fHigh;
    FUN_1408e2170(pWin);
    if (bReseat && (pWin->m_uPos > pWin->m_uHighMark || pWin->m_uPos < pWin->m_uLowMark))
    {
        FUN_1408df700(pWin, FUN_1408dea30(pWin, pWin->m_uPos));
    }
}

// @0x1408e1c60
void FUN_1408e1c60(Unk_ThresholdWindow* pWin, float f14, float fLow, float fHigh, bool bReseat)
{
    pWin->m_f14 = f14;
    pWin->m_fLow = fLow;
    pWin->m_fHigh = fHigh;
    FUN_1408e2250(pWin);
    if (bReseat && (pWin->m_uPos > pWin->m_uHighMark || pWin->m_uPos < pWin->m_uLowMark))
    {
        FUN_1408df930(pWin, FUN_1408deb20(pWin, pWin->m_uPos));
    }
}

// @0x1408e1d10
void FUN_1408e1d10(Unk_ThresholdWindow* pWin)
{
    pWin->m_uHighMark = (unsigned long long)(pWin->m_fHigh * (float)pWin->m_uSize);
    pWin->m_uLowMark = (unsigned long long)(pWin->m_fLow * (float)pWin->m_uSize);
    if (pWin->m_uLowMark < 0x11)
        pWin->m_uLowMark = 0;
}

// @0x1408e1df0
void FUN_1408e1df0(Unk_ThresholdWindow* pWin)
{
    pWin->m_uHighMark = (unsigned long long)(pWin->m_fHigh * (float)pWin->m_uSize);
    pWin->m_uLowMark = (unsigned long long)(pWin->m_fLow * (float)pWin->m_uSize);
    if (pWin->m_uLowMark < 0x11)
        pWin->m_uLowMark = 0;
}

// @0x1408e1ed0
void FUN_1408e1ed0(Unk_ThresholdWindow* pWin)
{
    pWin->m_uHighMark = (unsigned long long)(pWin->m_fHigh * (float)pWin->m_uSize);
    pWin->m_uLowMark = (unsigned long long)(pWin->m_fLow * (float)pWin->m_uSize);
    if (pWin->m_uLowMark < 0x11)
        pWin->m_uLowMark = 0;
}

// @0x1408e1fb0
void FUN_1408e1fb0(Unk_ThresholdWindow* pWin)
{
    pWin->m_uHighMark = (unsigned long long)(pWin->m_fHigh * (float)pWin->m_uSize);
    pWin->m_uLowMark = (unsigned long long)(pWin->m_fLow * (float)pWin->m_uSize);
    if (pWin->m_uLowMark < 0x11)
        pWin->m_uLowMark = 0;
}

// @0x1408e2090
void FUN_1408e2090(Unk_ThresholdWindow* pWin)
{
    pWin->m_uHighMark = (unsigned long long)(pWin->m_fHigh * (float)pWin->m_uSize);
    pWin->m_uLowMark = (unsigned long long)(pWin->m_fLow * (float)pWin->m_uSize);
    if (pWin->m_uLowMark < 0x11)
        pWin->m_uLowMark = 0;
}

// @0x1408e2170
void FUN_1408e2170(Unk_ThresholdWindow* pWin)
{
    pWin->m_uHighMark = (unsigned long long)(pWin->m_fHigh * (float)pWin->m_uSize);
    pWin->m_uLowMark = (unsigned long long)(pWin->m_fLow * (float)pWin->m_uSize);
    if (pWin->m_uLowMark < 0x11)
        pWin->m_uLowMark = 0;
}

// @0x1408e2250
void FUN_1408e2250(Unk_ThresholdWindow* pWin)
{
    pWin->m_uHighMark = (unsigned long long)(pWin->m_fHigh * (float)pWin->m_uSize);
    pWin->m_uLowMark = (unsigned long long)(pWin->m_fLow * (float)pWin->m_uSize);
    if (pWin->m_uLowMark < 0x11)
        pWin->m_uLowMark = 0;
}

