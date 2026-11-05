// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CU name unknown: CRI M2V (Sofdec MPEG-2 video) decoder
// core: context pool, parameter defaults, the function table and the YCbCr conversion curves.
// MS2-UNIT: unit_140047430
// MS2-TOOLSET: vc9
// MS2-RANGE: 0x140047430-0x140047b30 .text
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\unknown_140047430.cpp"
#include <string.h>
#pragma function(memset, memcpy)
#define MS2_CHECK_SIZE(T, n) typedef char T##_size_check[sizeof(T) == (n) ? 1 : -1]

// ---- exe callees ----
__int64 FUN_1400530c0(__int64 pBuf, int nLen, int nCode);       // find a start code (sfr_cri_05c)
long FUN_140053000(unsigned char* pHeader);                       // header flags (sfr_cri_05c)
struct Unk_M2vCtx;
void FUN_1400544e0(void* pCtx);   // sfr_cri_06
void FUN_1400540d0(Unk_M2vCtx* pCtx);
void M2VERR_Init();
void FUN_1400544b0();
void M2VVLC_Init();
void thunk_FUN_140054080();                             // 0x140054200, a jmp to FUN_140054080 (sfr_cri_06a)
void M2VAPRD_Init();
void M2VAMC_Init();
// the sfr_cri_06 definitions' signatures (the table entries are only stored by address)
unsigned int FUN_14005af30(__int64 nA, unsigned int uError);
void FUN_14005af70(__int64 a1, unsigned __int64 a2, unsigned __int64 a3);
void FUN_14005afd0(__int64 a1, unsigned __int64* a2);
void FUN_14005b390(__int64 a1, unsigned __int64 a2, void* a3);
void FUN_14005b300(unsigned __int64 a1, unsigned __int64 a2);
unsigned int FUN_140059030(unsigned __int64 a1, unsigned __int64 a2);
void FUN_14005e5b0(__int64 a1, void* a2);
void FUN_14005e600(__int64 a1, unsigned int* a2);
void FUN_14005e650(__int64 a1, int* a2, unsigned int* a3, unsigned int* a4);
void FUN_14005e6c0(__int64 a1, unsigned int* a2, unsigned int* a3);
void FUN_14005b860(__int64 a1);
const char* FUN_140047420(void);                        // unit_140046e04
void FUN_140054590(void* pCtx, int nIndex, unsigned __int64 a3, unsigned __int64 a4, unsigned __int64 a5);
void FUN_1400545c0(void* pCtx, unsigned __int64 a2, unsigned int a3);
void FUN_1400545d0(void* pCtx, unsigned __int64* pOut, unsigned int* pCount);

// Decoder parameter block (0x6c bytes; field names invented).
struct Unk_M2vParams
{
    int m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30, m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    short m_50;
    short m_52;
    unsigned char m_54, m_55, m_56, m_57;
    unsigned char m_58, m_59, m_5a, m_5b;
    unsigned char m_5c, m_5d, m_5e;
    signed char m_5f;
    signed char m_60;
    unsigned char m_61, m_62, m_63;
    unsigned char m_64, m_65, m_66, m_67;
    int m_68;
};
MS2_CHECK_SIZE(Unk_M2vParams, 0x6c);

// One decoder context of the pool (0x7200 bytes; only the fields used here).
struct Unk_M2vCtx
{
    char m_pad0[0x1a28];
    int m_nState;                       // +0x1a28: 1 = free, 2 = in use
    char m_pad1[0x1a50 - 0x1a2c];
    int m_aParam[16];                   // +0x1a50
    int m_1a90;
    char m_pad2[4];
    unsigned long long m_1a98;
    unsigned long long m_1aa0;
    Unk_M2vParams m_kParams;            // +0x1aa8
    char m_pad3[0x1bc0 - 0x1b14];
    int m_1bc0;
    char m_pad4[0x1c58 - 0x1bc4];
    void* m_pUserArg;                   // +0x1c58
    char m_pad5[0x7200 - 0x1c60];
};
MS2_CHECK_SIZE(Unk_M2vCtx, 0x7200);

// ---- globals ----
extern int DAT_143ba9db0;                       // number of 0x2000-byte units in the pool
extern Unk_M2vCtx* DAT_143ba9db8;               // pool base
extern int DAT_143ba9d70[16];                   // default parameter block
extern Unk_M2vCtx* DAT_143ba9d60;               // current context
extern const char* DAT_143ba9d68;               // version string
extern "C" int DAT_143e64b88;                                 // the decoder-ready flag (4-byte store in the exe)
extern void* DAT_143e64b60;
extern void* DAT_143e64b20;
extern void* DAT_143e64b80;
extern void* DAT_143e64b78;
extern void* DAT_143e64b58;
extern void* DAT_143e64b50;
extern void* DAT_143e64b28;
extern void* DAT_143e64b90;
extern void* DAT_143e64b08;
extern void* DAT_143e64b68;
extern void* DAT_143e64b10;
extern void* DAT_143e64b00;
extern void* DAT_143e64b98;
extern void* DAT_143e64b70;
extern void* DAT_143e64b40;
extern void* DAT_143e64b48;
extern void* DAT_143e64ba0;
extern void* DAT_143e64b18;
extern void* DAT_143e64ba8;
extern void* DAT_143e64b38;
extern void* DAT_143e64b30;
extern int DAT_143baa9d0[256];
extern int DAT_143ba9dd0[256];
extern int DAT_143baadd0[256];
extern int DAT_143baa5d0[256];
extern int DAT_143baa1d0[256];
extern int DAT_143bab5d0[256];
extern int DAT_143bab1d0[256];
extern int DAT_143bab9d0[256];

int FUN_140047750(Unk_M2vCtx* pCtx);

// @0x140047430
int FUN_140047430(const unsigned char* pBuf, int nLen)
{
    const unsigned char* pFound;
    const unsigned char* pData;
    int nRemain;
    int nResult;

    pFound = (const unsigned char*)FUN_1400530c0((__int64)pBuf, nLen, 0x40);
    if (pFound == 0)
        return 0;
    pFound = pFound + 4;
    nLen = nLen - (int)(pFound - pBuf);
    if (nLen <= 0)
        return 0;
    pData = (const unsigned char*)FUN_1400530c0((__int64)pFound, nLen, -1);
    if (pData == 0)
        return 0;
    if ((FUN_140053000((unsigned char*)pData) & 0x10) == 0)
        return 0;
    pData = pData + 4;
    nRemain = nLen - (int)(pData - pFound);
    nResult = 0;
    if (0 < nRemain)
        nResult = (*pData & 0xf0) == 0x10;
    return nResult;
}

// @0x1400474d0
void FUN_1400474d0(void)
{
    int nCount = DAT_143ba9db0;
    if (0 < nCount)
    {
        Unk_M2vCtx* pCtx = DAT_143ba9db8;
        for (int i = 0; i < nCount; i += 4)
        {
            pCtx->m_nState = 1;
            pCtx = pCtx + 1;
        }
    }
}

// @0x140047510
void FUN_140047510(int nUnits, unsigned char* pMem, unsigned long long uSize)
{
    for (int nBytes = nUnits << 0xd; (unsigned long long)(nBytes + (__int64)0x80U) > uSize; nBytes = nBytes + -0x2000)
        nUnits = nUnits + -1;
    void* pAligned = (void*)(((unsigned long long)pMem + 0x7fU) & 0xffffffffffffff80);
    memset(pAligned, 0, (__int64)(nUnits << 0xd));
    DAT_143ba9db8 = (Unk_M2vCtx*)pAligned;
    DAT_143ba9db0 = nUnits;
}

// @0x140047580
void FUN_140047580(Unk_M2vParams* p)
{
    p->m_38 = 3;
    p->m_3c = 1;
    p->m_44 = 1;
    p->m_55 = 1;
    p->m_00 = 0;
    p->m_04 = 0;
    p->m_08 = 0;
    p->m_0c = 0;
    p->m_10 = 0;
    p->m_14 = 0;
    p->m_18 = 0;
    p->m_1c = 0;
    p->m_20 = 0;
    p->m_24 = 0;
    p->m_28 = 0;
    p->m_2c = 0;
    p->m_30 = 0;
    p->m_34 = 0;
    p->m_40 = 0;
    p->m_48 = 0;
    p->m_4c = 0;
    p->m_50 = -1;
    p->m_52 = -1;
    p->m_54 = 0;
    p->m_56 = 0;
    p->m_57 = 0;
    p->m_58 = 0;
    p->m_5a = 0;
    p->m_5b = 0;
    p->m_5c = 0;
    p->m_5e = 0;
    p->m_5f = -1;
    p->m_60 = -1;
    p->m_61 = 0;
    p->m_68 = 0;
    p->m_59 = 1;
    p->m_5d = 0xff;
    p->m_62 = 0xff;
    p->m_63 = 0xff;
    p->m_64 = 0xff;
}

// The decoder table's no-op entry (LAB_140047620, stored by address in FUN_1400478a0).
// @0x140047620
void FUN_140047620(void)
{
}

// @0x140047630
Unk_M2vCtx* FUN_140047630(void)
{
    int nIndex = 0;
    Unk_M2vCtx* pCtx = DAT_143ba9db8;
    if (0 < DAT_143ba9db0)
    {
        do
        {
            if (pCtx->m_nState == 1)
                return pCtx;
            nIndex = nIndex + 4;
            pCtx = pCtx + 1;
        } while (nIndex < DAT_143ba9db0);
    }
    return 0;
}

// @0x140047660
Unk_M2vCtx* FUN_140047660(Unk_M2vCtx* pCtx)
{
    memcpy(pCtx->m_aParam, DAT_143ba9d70, 0x40);
    pCtx->m_1a98 = 0;
    pCtx->m_1aa0 = 0;
    pCtx->m_1a90 = 0x7fffffff;
    FUN_1400544e0(pCtx);
    FUN_140047580(&pCtx->m_kParams);
    FUN_1400540d0(pCtx);
    pCtx->m_1bc0 = 0;
    pCtx->m_nState = 2;
    return pCtx;
}

// @0x1400476e0
void FUN_1400476e0(int nIndex, int nValue)
{
    Unk_M2vCtx* pCtx = DAT_143ba9db8;
    if (0 < DAT_143ba9db0)
    {
        unsigned long long uCount = (unsigned long long)((((unsigned int)DAT_143ba9db0 - 1U) >> 2) + 1);
        do
        {
            if (pCtx->m_nState == 2)
                pCtx->m_aParam[nIndex] = nValue;
            pCtx = pCtx + 1;
            uCount = uCount - 1;
        } while (uCount != 0);
    }
}

// The decoder table entry LAB_140047730 (stored by address in FUN_1400478a0): sets the +0x1a90 value and the
// +0x1a98/+0x1aa0 pair FUN_140047660 resets.
// @0x140047730
void FUN_140047730(Unk_M2vCtx* pCtx, int n1a90, unsigned long long u1a98, unsigned long long u1aa0)
{
    pCtx->m_1a90 = n1a90;
    pCtx->m_1aa0 = u1aa0;
    pCtx->m_1a98 = u1a98;
}

// @0x140047750
int FUN_140047750(Unk_M2vCtx* pCtx)
{
    if (pCtx == 0)
        return -1;
    if (pCtx->m_nState != 2)
        return -1;
    DAT_143ba9d60 = pCtx;
    return 0;
}

// @0x140047770
void FUN_140047770(int nUnits, unsigned char* pMem, unsigned long long uSize)
{
    DAT_143ba9d68 = "\nCRI M2V/PCx64 Ver.2.076 Build:Jan 13 2012 18:29:31\n";
    M2VERR_Init();
    FUN_1400544b0();
    M2VVLC_Init();
    thunk_FUN_140054080();
    M2VAPRD_Init();
    M2VAMC_Init();
    FUN_140047510(nUnits, pMem, uSize);
    FUN_1400474d0();
}

// @0x1400477e0
Unk_M2vCtx* FUN_1400477e0(void* pUserArg)
{
    Unk_M2vCtx* pCtx = FUN_140047630();
    if (pCtx == 0)
        return 0;
    pCtx = FUN_140047660(pCtx);
    pCtx->m_pUserArg = pUserArg;
    return pCtx;
}

// @0x140047810
void FUN_140047810(Unk_M2vCtx* pCtx)
{
    int nRes = FUN_140047750(pCtx);
    if (nRes != 0)
    {
        FUN_14005af30(0, 0xff050201);
        return;
    }
    pCtx->m_nState = 1;
}

// @0x140047840
void FUN_140047840(Unk_M2vCtx* pCtx, int nIndex, int nValue)
{
    int* pTable;
    if (pCtx == 0)
    {
        FUN_1400476e0(nIndex, nValue);
        pTable = DAT_143ba9d70;
    }
    else
    {
        if (FUN_140047750(pCtx) != 0)
        {
            FUN_14005af30(0, 0xff050202);
            return;
        }
        pTable = pCtx->m_aParam;
    }
    pTable[nIndex] = nValue;
}

// @0x1400478a0
// Fills the decoder's function table.
void FUN_1400478a0(void)
{
    DAT_143e64b88 = 1;
    DAT_143e64b60 = (void*)FUN_140047420;
    DAT_143e64b20 = (void*)FUN_140047430;
    DAT_143e64b80 = (void*)FUN_140047770;
    DAT_143e64b78 = (void*)FUN_140047620;
    DAT_143e64b58 = (void*)FUN_1400477e0;
    DAT_143e64b50 = (void*)FUN_140047810;
    DAT_143e64b28 = (void*)FUN_140047840;
    DAT_143e64b90 = (void*)FUN_140047730;
    DAT_143e64b08 = (void*)FUN_14005af70;
    DAT_143e64b68 = (void*)FUN_14005afd0;
    DAT_143e64b10 = (void*)FUN_14005b390;
    DAT_143e64b00 = (void*)FUN_14005b300;
    DAT_143e64b98 = (void*)FUN_140054590;
    DAT_143e64b70 = (void*)FUN_1400545c0;
    DAT_143e64b40 = (void*)FUN_1400545d0;
    DAT_143e64b48 = (void*)FUN_140059030;
    DAT_143e64ba0 = (void*)FUN_14005e5b0;
    DAT_143e64b18 = (void*)FUN_14005e600;
    DAT_143e64ba8 = (void*)FUN_14005e650;
    DAT_143e64b38 = (void*)FUN_14005e6c0;
    DAT_143e64b30 = (void*)FUN_14005b860;
}

// @0x1400479e0
// Builds the YCbCr -> RGB conversion curves (16.16-ish fixed point, 1048576 = 2^20).
void FUN_1400479e0(void)
{
    int nY = -0x10;
    for (int i = 0; i < 256; ++i)
    {
        DAT_143baa9d0[i] = (int)(((double)nY * 1.164 + 0.5 + 256.0) * 1048576.0);
        nY = nY + 1;
    }
    int nC = -0x80;
    for (int i = 0; i < 256; ++i)
    {
        double dC = (double)nC;
        DAT_143ba9dd0[i] = (int)(dC * 1.596 * 1048576.0);
        DAT_143baadd0[i] = (int)(dC * 0.392 * 1048576.0);
        DAT_143baa5d0[i] = (int)(dC * 0.813 * 1048576.0);
        DAT_143baa1d0[i] = (int)(dC * 2.017 * 1048576.0);
        nC = nC + 1;
    }
    int* pEntry = DAT_143bab5d0;
    for (int i = 0; i < 256; ++i)
    {
        *pEntry = i;
        pEntry[-0x100] = 0;
        pEntry[0x100] = 0xff;
        ++pEntry;
    }
}
