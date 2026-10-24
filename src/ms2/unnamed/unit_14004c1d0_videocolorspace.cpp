// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: a block of video colour-space helpers
// (3-plane to packed copies with an optional lookup, 3x3 double matrix multiply / inverse, YCbCr conversion tables).
// MS2-UNIT: unit_14004c1d0
// MS2-RANGE: 0x14004c1d0-0x14004da40 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_14004c1d0.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2layout.h"
#include "hook/ms2hook.h"

// Source planes: three data pointers followed by three pitches (names invented).
struct Unk_PlaneSet
{
    unsigned char* m_pPlane0;   // +0x00
    unsigned char* m_pPlane1;   // +0x08
    unsigned char* m_pPlane2;   // +0x10
    int m_nPitch0;              // +0x18
    int m_nPitch1;              // +0x1c
    int m_nPitch2;              // +0x20
};

// Destination plane description.
struct Unk_PlaneDst
{
    unsigned char* m_pBase;     // +0x00
    unsigned int m_nWidth;      // +0x08
    unsigned int m_nHeight;     // +0x0c
    __int64 m_nStride;          // +0x10
};

// One entry of the frame's plane list (0x18 bytes each, starting at +8 in the frame).
struct Unk_FramePlane
{
    unsigned char* m_pData;     // +0x00
    __int64 m_08;               // +0x08
    int m_nPitch;               // +0x10
    int m_14;                   // +0x14
};

struct Unk_Frame
{
    __int64 m_00;               // +0x00
    Unk_FramePlane m_plane[3];  // +0x08
};

// Destination surface as the callers see it (base pointer at +8).
struct Unk_Surface
{
    __int64 m_00;               // +0x00
    unsigned char* m_pBase;     // +0x08
    unsigned int m_nWidth;      // +0x10
    unsigned int m_nHeight;     // +0x14
    int m_nStride;              // +0x18
};

// Table entries of 4 shorts, 256 per table.
struct Unk_YuvEntry { short v[4]; };

// Colour tables (all indexed by a byte value). A and C are the 256-entry centred curves built by FUN_14004c370.
extern double DAT_143babdf0[256];
extern double DAT_143bac690[256];
extern double DAT_143bace90[256];
extern double DAT_143bac5f0[9];
extern double DAT_143bac640[9];
extern double DAT_143a48740[9];
extern double DAT_143a48790[9];

// @0x14004c1d0
void FUN_14004c1d0(Unk_PlaneSet* pSrc, Unk_PlaneDst* pDst, int nOffset)
{
    unsigned int nWidth = pDst->m_nWidth;
    __int64 nStride = pDst->m_nStride;
    unsigned int nHeight = pDst->m_nHeight;
    unsigned char* pOut = pDst->m_pBase + nOffset;
    unsigned char* pIn = pSrc->m_pPlane0;
    int nPitch = pSrc->m_nPitch0;
    for (int y = 0; y < (int)nHeight; ++y)
    {
        for (int x = 0; x < (int)nWidth; ++x)
        {
            *pOut = *pIn;
            pOut += 4;
            pIn += 1;
        }
        pOut += (int)((int)nStride + nWidth * -4);
        pIn += (int)(nPitch - nWidth);
    }
}

// @0x14004c250
void FUN_14004c250(Unk_PlaneSet* pSrc, Unk_PlaneDst* pDst, const unsigned char* pLut, int nOffset)
{
    unsigned int nWidth = pDst->m_nWidth;
    unsigned int nHeight = pDst->m_nHeight;
    __int64 nStride = pDst->m_nStride;
    unsigned char* pOut = pDst->m_pBase + nOffset;
    unsigned char* pIn = pSrc->m_pPlane0;
    int nPitch = pSrc->m_nPitch0;
    for (int y = 0; y < (int)nHeight; ++y)
    {
        for (int x = 0; x < (int)nWidth; ++x)
        {
            unsigned char b = *pIn;
            pOut += 4;
            pIn += 1;
            pOut[-4] = pLut[b];
        }
        pOut += (int)((int)nStride + nWidth * -4);
        pIn += (int)(nPitch - nWidth);
    }
}

// @0x14004c370
// Builds the three 256-entry curves used by the YCbCr conversion.
void FUN_14004c370(void)
{
    unsigned int i;
    int k;
    for (i = 0; (int)i < 0x30; i += 3)
        DAT_143bac690[i / 3] = (double)(int)i * 0.5;
    for (i = 0; i < 160; ++i)
        DAT_143bac690[16 + i] = (double)(int)i * 0.5 + 24.0;
    for (i = 0; i < 16; ++i)
        DAT_143bac690[176 + i] = (double)(int)i + 104.0;
    for (i = 0; i < 64; ++i)
    {
        double d = (double)(int)i * 2.0 + 120.0;
        if (255.0 < d)
            d = 255.0;
        DAT_143bac690[192 + i] = d;
    }
    for (k = 0; k < 24; ++k)
    {
        double lo = 128.0 - (double)k / 3.0;
        double hi = (double)k / 3.0 + 128.0;
        DAT_143babdf0[128 + k] = hi;
        DAT_143bace90[128 + k] = hi;
        DAT_143babdf0[128 - k] = lo;
        DAT_143bace90[128 - k] = lo;
    }
    for (k = 24; k < 128; ++k)
    {
        double d = ((double)(k - 24) * 120.0) / 104.0 + 8.0;
        double lo = 128.0 - d;
        double hi = d + 128.0;
        DAT_143babdf0[128 + k] = hi;
        DAT_143bace90[128 + k] = hi;
        DAT_143babdf0[128 - k] = lo;
        DAT_143bace90[128 - k] = lo;
    }
    DAT_143bace90[0] = 0;
    DAT_143babdf0[0] = 0;
}

// @0x14004c590
// pOut = (pA * pB) / 64 (3x3 double matrices, row-major).
void FUN_14004c590(double* pA, double* pB, double* pOut)
{
    double d0 = pA[0] * pB[0] + pB[3] * pA[1] + pA[2] * pB[6];
    pOut[0] = d0;
    double d1 = pB[4] * pA[1] + pB[1] * pA[0] + pB[7] * pA[2];
    pOut[1] = d1;
    double d2 = pB[5] * pA[1] + pB[2] * pA[0] + pB[8] * pA[2];
    pOut[2] = d2;
    double d3 = pA[4] * pB[3] + pA[3] * pB[0] + pA[5] * pB[6];
    pOut[3] = d3;
    double d4 = pA[4] * pB[4] + pA[3] * pB[1] + pA[5] * pB[7];
    pOut[4] = d4;
    double d5 = pA[4] * pB[5] + pA[3] * pB[2] + pB[8] * pA[5];
    pOut[5] = d5;
    double d6 = pB[3] * pA[7] + pB[0] * pA[6] + pA[8] * pB[6];
    pOut[6] = d6;
    double d7 = pB[4] * pA[7] + pB[1] * pA[6] + pB[7] * pA[8];
    pOut[7] = d7;
    double d8 = pB[5] * pA[7] + pB[2] * pA[6] + pB[8] * pA[8];
    pOut[0] = d0 * 0.015625;
    pOut[1] = d1 * 0.015625;
    pOut[2] = d2 * 0.015625;
    pOut[3] = d3 * 0.015625;
    pOut[4] = d4 * 0.015625;
    pOut[8] = d8 * 0.015625;
    pOut[5] = d5 * 0.015625;
    pOut[6] = d6 * 0.015625;
    pOut[7] = d7 * 0.015625;
}

// @0x14004c7c0
// pOut = 64 * inverse(pIn) (3x3 double matrices, row-major).
void FUN_14004c7c0(double* pIn, double* pOut)
{
    double a01 = pIn[1];
    double a00 = pIn[0];
    double a20 = pIn[6];
    double a21 = pIn[7];
    double a12 = pIn[5];
    double a22 = pIn[8];
    double a02 = pIn[2];
    double a11 = pIn[4];
    double a10 = pIn[3];
    double det = (a11 * a00 * a22 + a12 * a01 * a20 + a10 * a02 * a21) -
                 (a12 * a00 * a21 + a10 * a01 * a22 + a11 * a02 * a20);
    pOut[2] = ((a12 * a01 - a11 * a02) * 64.0) / det;
    pOut[0] = ((a22 * a11 - a21 * a12) * 64.0) / det;
    pOut[1] = ((a22 * a01 - a21 * a02) * -64.0) / det;
    pOut[3] = ((a22 * a10 - a20 * a12) * -64.0) / det;
    pOut[5] = ((a12 * a00 - a10 * a02) * -64.0) / det;
    pOut[4] = ((a22 * a00 - a20 * a02) * 64.0) / det;
    pOut[8] = ((a11 * a00 - a10 * a01) * 64.0) / det;
    pOut[6] = ((a21 * a10 - a20 * a11) * 64.0) / det;
    pOut[7] = ((a21 * a00 - a20 * a01) * -64.0) / det;
}

// @0x14004ca60
// Chroma-to-RGB contribution tables: pBlue/pGreen entries and pRed/pGreen2 entries for each of the 256 chroma values.
void FUN_14004ca60(Unk_YuvEntry* pTab1, Unk_YuvEntry* pTab2)
{
    int nStepA = -0x2000;
    int nStepB = 0x2000;
    for (int i = 0; i < 256; ++i)
    {
        pTab1[i].v[2] = 0;
        pTab1[i].v[3] = 0;
        pTab1[i].v[0] = (short)(int)(((float)nStepA * 1.772 * 255.0) / 224.0 + 0.5);
        pTab1[i].v[1] = (short)(int)(((float)nStepB * 0.344 * 255.0) / 224.0 + 0.5);
        pTab2[i].v[0] = 0;
        pTab2[i].v[3] = 0;
        pTab2[i].v[1] = (short)(int)(((float)nStepB * 0.714 * 255.0) / 224.0 + 0.5);
        pTab2[i].v[2] = (short)(int)(((float)nStepA * 1.402 * 255.0) / 224.0 + 0.5);
        nStepA += 0x40;
        nStepB -= 0x40;
    }
}

// @0x14004cbb0
void FUN_14004cbb0(Unk_Frame* pFrame, Unk_Surface* pSurface, unsigned char** ppLut)
{
    Unk_PlaneSet kSrc;
    Unk_PlaneDst kDst;
    kSrc.m_pPlane0 = pFrame->m_plane[0].m_pData;
    kSrc.m_pPlane1 = pFrame->m_plane[1].m_pData;
    kSrc.m_pPlane2 = pFrame->m_plane[2].m_pData;
    kSrc.m_nPitch0 = pFrame->m_plane[0].m_nPitch;
    kSrc.m_nPitch1 = pFrame->m_plane[1].m_nPitch;
    kSrc.m_nPitch2 = pFrame->m_plane[2].m_nPitch;
    kDst.m_pBase = pSurface->m_pBase;
    kDst.m_nWidth = pSurface->m_nWidth;
    kDst.m_nHeight = pSurface->m_nHeight;
    kDst.m_nStride = pSurface->m_nStride;
    if (*ppLut == 0)
    {
        FUN_14004c1d0(&kSrc, &kDst, 3);
        return;
    }
    FUN_14004c250(&kSrc, &kDst, *ppLut, 3);
}

// @0x14004cc40
void FUN_14004cc40(Unk_Frame* pFrame, Unk_Surface* pSurface, unsigned char** ppLut)
{
    Unk_PlaneSet kSrc;
    Unk_PlaneDst kDst;
    kSrc.m_pPlane0 = pFrame->m_plane[0].m_pData;
    kSrc.m_pPlane1 = pFrame->m_plane[1].m_pData;
    kSrc.m_pPlane2 = pFrame->m_plane[2].m_pData;
    kSrc.m_nPitch0 = pFrame->m_plane[0].m_nPitch;
    kSrc.m_nPitch1 = pFrame->m_plane[1].m_nPitch;
    kSrc.m_nPitch2 = pFrame->m_plane[2].m_nPitch;
    kDst.m_pBase = pSurface->m_pBase;
    kDst.m_nWidth = pSurface->m_nWidth;
    kDst.m_nHeight = pSurface->m_nHeight;
    kDst.m_nStride = pSurface->m_nStride;
    if (*ppLut == 0)
    {
        FUN_14004c1d0(&kSrc, &kDst, 0);
        return;
    }
    FUN_14004c250(&kSrc, &kDst, *ppLut, 0);
}

// Table block used by FUN_14004ccc0 / ce20 / cfd0: luma entries at +0, chroma tables at +0x800 / +0x1000.
struct Unk_YuvTables
{
    Unk_YuvEntry m_luma[256];
    Unk_YuvEntry m_cb[256];
    Unk_YuvEntry m_cr[256];
};
MS2_CHECK_SIZE(Unk_YuvTables, 0x1800);

// @0x14004ccc0
void FUN_14004ccc0(int nMode, int nLow, int nHigh, Unk_YuvTables* pTab)
{
    FUN_14004ca60(pTab->m_cb, pTab->m_cr);
    int nStepA = -0x10;
    for (int i = 0; i < 256; ++i)
    {
        short s = (short)(int)((double)nStepA * 74.496 + 0.5);
        pTab->m_luma[i].v[0] = s;
        pTab->m_luma[i].v[1] = s;
        pTab->m_luma[i].v[2] = s;
        nStepA += 1;
    }
    __int64 nIdx = 0;
    double dScale = 255.0 / (double)(nHigh - nLow);
    if (nMode == 1)
    {
        int nVal = (nHigh - nLow) + nLow;
        do
        {
            if (nIdx < nLow)
                pTab->m_luma[nIdx].v[3] = 0x3fc0;
            else if (nHigh < nIdx)
                pTab->m_luma[nIdx].v[3] = 0;
            else
                pTab->m_luma[nIdx].v[3] = (short)(int)((double)nVal * dScale) << 6;
            nIdx += 1;
            nVal -= 1;
        } while (nIdx < 0x100);
    }
    else
    {
        int nVal = -nLow;
        do
        {
            if (nIdx < nLow)
                pTab->m_luma[nIdx].v[3] = 0;
            else if (nHigh < nIdx)
                pTab->m_luma[nIdx].v[3] = 0x3fc0;
            else
                pTab->m_luma[nIdx].v[3] = (short)(int)((double)nVal * dScale) << 6;
            nIdx += 1;
            nVal += 1;
        } while (nIdx < 0x100);
    }
}

// @0x14004ce20
void FUN_14004ce20(Unk_YuvTables* pTab, unsigned char nA, unsigned short nB, unsigned short nC)
{
    FUN_14004ca60(pTab->m_cb, pTab->m_cr);
    int i;
    for (i = 0; i < 9; ++i)
    {
        pTab->m_luma[i].v[0] = 0;
        pTab->m_luma[i].v[1] = 0;
        pTab->m_luma[i].v[2] = 0;
        pTab->m_luma[i].v[3] = (unsigned short)nA;
    }
    for (i = 9; i < 0x86; ++i)
    {
        double d = (double)i - 16.0;
        if (0.0 <= d)
        {
            if (255.0 < d)
                d = 255.0;
        }
        else
            d = 0.0;
        pTab->m_luma[i].v[3] = (nB & 0xff) << 6;
        short s = (short)(int)(d * 64.0 * 2.3181818181818183 + 0.5);
        pTab->m_luma[i].v[0] = s;
        pTab->m_luma[i].v[1] = s;
        pTab->m_luma[i].v[2] = s;
    }
    for (i = 0x86; i < 0x100; ++i)
    {
        double d = 251.0 - (double)i;
        if (0.0 <= d)
        {
            if (255.0 < d)
                d = 255.0;
        }
        else
            d = 0.0;
        pTab->m_luma[i].v[3] = (nC & 0xff) << 6;
        short s = (short)(int)(d * 64.0 * 2.3181818181818183 + 0.5);
        pTab->m_luma[i].v[0] = s;
        pTab->m_luma[i].v[1] = s;
        pTab->m_luma[i].v[2] = s;
    }
}

// @0x14004cfd0
void FUN_14004cfd0(Unk_YuvTables* pTab, unsigned char nA, unsigned short nB, unsigned char nC)
{
    FUN_14004ca60(pTab->m_cb, pTab->m_cr);
    int i;
    for (i = 0; i < 0x30; ++i)
        pTab->m_luma[i].v[3] = (unsigned short)nA;
    for (i = 0x30; i < 0x30 + 0x52; ++i)
        pTab->m_luma[i].v[3] = (nB & 0xff) << 6;
    for (i = 0x30 + 0x52; i < 0x100; ++i)
        pTab->m_luma[i].v[3] = (unsigned short)nC << 6;
    for (i = 0; i < 0x40; ++i)
    {
        pTab->m_luma[i].v[0] = (short)0xfb78;
        pTab->m_luma[i].v[1] = (short)0xfb78;
        pTab->m_luma[i].v[2] = (short)0xfb78;
    }
    for (i = 0x40; i < 0x80; ++i)
    {
        double d = (double)i - 68.0;
        if (0.0 <= d)
        {
            if (255.0 < d)
                d = 255.0;
        }
        else
            d = 0.0;
        short s = (short)(int)(d * 64.0 * 4.636363636363637 + 0.5);
        pTab->m_luma[i].v[0] = s;
        pTab->m_luma[i].v[1] = s;
        pTab->m_luma[i].v[2] = s;
    }
    for (i = 0x80; i < 0x100; ++i)
    {
        double d = 247.0 - (double)i;
        if (0.0 <= d)
        {
            if (255.0 < d)
                d = 255.0;
        }
        else
            d = 0.0;
        short s = (short)(int)(d * 64.0 * 2.2972972972972974 + 0.5);
        pTab->m_luma[i].v[0] = s;
        pTab->m_luma[i].v[1] = s;
        pTab->m_luma[i].v[2] = s;
    }
}

// 64-bit conversion tables built by FUN_14004d1c0: a 16-byte entry per index, then two 8-byte tables.
struct Unk_Entry16 { unsigned __int64 m_lo, m_hi; };
struct Unk_YuvTables64
{
    Unk_Entry16 m_y[256];               // +0x0000
    unsigned __int64 m_cb[256];         // +0x1000
    unsigned __int64 m_cr[256];         // +0x1800
};
MS2_CHECK_SIZE(Unk_YuvTables64, 0x2000);

// @0x14004d1c0
void FUN_14004d1c0(Unk_YuvTables64* pTab)
{
    FUN_14004c370();
    FUN_14004c7c0(DAT_143a48740, DAT_143bac640);
    FUN_14004c590(DAT_143a48790, DAT_143bac640, DAT_143bac5f0);
    double dM0 = DAT_143bac5f0[0];
    double dM4 = DAT_143bac5f0[4];
    double dM8 = DAT_143bac5f0[8];
    double dZero = dM0 * 0.0;
    double dOff4 = dM4 * 128.0;
    double dOff8 = dM8 * 128.0;
    for (int i = 0; i < 256; ++i)
    {
        double dY = dM0 * DAT_143bac690[i] + dZero + 16.0 + 0.5;
        double dCb = (dM4 * DAT_143babdf0[i] - dOff4) + 128.0 + 0.0;
        double dCr = (dM8 * DAT_143bace90[i] - dOff8) + 128.0 + 0.0;
        pTab->m_y[i].m_lo = (unsigned __int64)dY << 0x30;
        pTab->m_y[i].m_hi = (unsigned __int64)dY << 0x20;
        pTab->m_cb[i] = (unsigned __int64)dCb << 0x28;
        pTab->m_cr[i] = (unsigned __int64)dCr << 0x38;
    }
}
