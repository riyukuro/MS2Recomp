// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). NvidiaGPU: the NVIDIA (nvapi.dll) GPU helper behind GPUManager.
// MS2-UNIT: ?\nvidiagpu.cpp
// MS2-RANGE: 0x14160c6d0-0x14160d520 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\nvidiagpu.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "gpumanager.h"


// Query records: the first int is the struct version (size | version << 16).
struct Unk_NvMemEntry { int m_nValue; int m_nPad; };
struct Unk_NvMemInfo { unsigned int m_nVersion; int m_nPad[2]; Unk_NvMemEntry m_aEntry[8]; };
struct Unk_NvClockInfo { unsigned int m_nVersion; int m_aValue[5]; };                                  // 0x18 bytes
struct Unk_NvPStateInfo { unsigned int m_nVersion; int m_aValue[0x22]; };                             // 0x8c bytes
struct Unk_NvDisplayInfo { unsigned int m_nVersion; int m_aValue[0x120]; };                           // 0x484 bytes
struct Unk_NvGpuMemory { int m_nCount; int m_aHandle[4]; unsigned int m_nTotal; int m_nFree; };

int FUN_14160ccd0(NvidiaGPU* pGpu, int nIndex, Unk_NvGpuMemory* pOut);
int FUN_14160ce50(NvidiaGPU* pGpu);
int FUN_14160cf10(NvidiaGPU* pGpu, int nHandle, Unk_NvGpu* pRec);
int FUN_14160d1d0(NvidiaGPU* pGpu, int nHandle, Unk_NvGpu* pRec);
int* FUN_14160d380(int* a, int* b);

// @0x14160c6d0
NvidiaGPU::NvidiaGPU()
{
    m_hModule = 0;
    m_nGpus = 0;
    m_pGpus = 0;
    m_nA8 = 0;
}

// @0x14160c740
NvidiaGPU::~NvidiaGPU()
{
}

// @0x14160c770
int NvidiaGPU::vfunc_1()
{
    int nResult = 0;
    int nOk = 0;
    int i = 0;
    int nRet = 0;
    m_hModule = LoadLibraryA("nvapi.dll");
    if (m_hModule != 0)
    {
        m_pfnQueryInterface = (Unk_NvQueryInterface)GetProcAddress(m_hModule, "nvapi_QueryInterface");
        if (m_pfnQueryInterface != 0)
        {
            m_pfn10 = (decltype(m_pfn10))m_pfnQueryInterface(0x150e828);
            m_pfn18 = (decltype(m_pfn18))m_pfnQueryInterface(0xceee8e9f);
            m_pfn20 = (decltype(m_pfn20))m_pfnQueryInterface(0xe3640a56);
            m_pfn28 = (decltype(m_pfn28))m_pfnQueryInterface(0x9abdd40d);
            m_pfn30 = (decltype(m_pfn30))m_pfnQueryInterface(0x34ef9506);
            m_pfn38 = (decltype(m_pfn38))m_pfnQueryInterface(0xe5ac921f);
            m_pfn40 = (decltype(m_pfn40))m_pfnQueryInterface(0x5f608315);
            m_pfn48 = (decltype(m_pfn48))m_pfnQueryInterface(0x1bd69f49);
            m_pfn50 = (decltype(m_pfn50))m_pfnQueryInterface(0x60ded2ed);
            m_pfn58 = (decltype(m_pfn58))m_pfnQueryInterface(0x189a1fdf);
            m_pfn60 = (decltype(m_pfn60))m_pfnQueryInterface(0xda141340);
            m_pfn68 = (decltype(m_pfn68))m_pfnQueryInterface(0x891fa0ae);
            m_pfn70 = (decltype(m_pfn70))m_pfnQueryInterface(0x774aa982);
            m_pfn78 = (decltype(m_pfn78))m_pfnQueryInterface(0xf951a4d1);
            m_pfn80 = (decltype(m_pfn80))m_pfnQueryInterface(0x1053fa5);
            m_pfn88 = (decltype(m_pfn88))m_pfnQueryInterface(0x2ddfb66e);
            if (m_pfn10 != 0)
            {
                nRet = m_pfn10();
                if (nRet == 0)
                {
                    m_pGpus = new Unk_NvGpu[4];
                    memset(m_pGpus, 0, 0x8c0);
                    nRet = FUN_14160ce50(this);
                    do { if (!(nRet > 0)) goto LExit; } while (0);
                    for (i = 0; i < m_nGpus; i++)
                    {
                        nOk = FUN_14160cf10(this, m_pGpus[i].m_nHandle, &m_pGpus[i]);
                        do { if (!(nOk != 0)) goto LExit; } while (0);
                    }
                    nResult = 1;
                }
            }
        }
    }
LExit:
    return nResult;
}

// @0x14160ca80
void NvidiaGPU::vfunc_2()
{
    m_nGpus = 0;
    if (m_pGpus != 0)
    {
        void* pBuf = m_pGpus;
        operator delete[](pBuf);
        m_pGpus = 0;
    }
    if (m_hModule != 0)
    {
        FreeLibrary(m_hModule);
        m_hModule = 0;
    }
}

// @0x14160cb10
int NvidiaGPU::vfunc_3(int* a, int* b)
{
    if (m_pGpus != 0 && a != 0 && b != 0 && m_pfn50 != 0)
    {
        Unk_NvMemInfo info;
        info.m_nVersion = 0x10048;
        if (m_pfn50(m_pGpus[0].m_aDisplay[0].m_nHandle, &info) == 0)
        {
            *a = info.m_aEntry[0].m_nValue;
            *b = info.m_aEntry[1].m_nValue;
            return 1;
        }
    }
    return 0;
}

// @0x14160cc20
int NvidiaGPU::vfunc_5(unsigned __int64* a, unsigned __int64* b)
{
    Unk_NvGpuMemory mem;
    if (FUN_14160ccd0(this, 0, &mem) != 0)
    {
        *a = mem.m_nTotal / 0x400;
        *b = (unsigned int)(mem.m_nTotal - mem.m_nFree) / 0x400;
    }
    return 0;
}

// @0x14160ccb0
int FUN_14160ccb0(NvidiaGPU* pGpu)
{
    return pGpu->m_nGpus;
}

// @0x14160ccd0
int FUN_14160ccd0(NvidiaGPU* pGpu, int nIndex, Unk_NvGpuMemory* pOut)
{
    int nResult = 0;
    int i = 0;
    if (nIndex < pGpu->m_nGpus && pGpu->m_nGpus != 0)
    {
        pOut->m_nCount = pGpu->m_pGpus[nIndex].m_nDisplays;
        for (i = 0; i < pOut->m_nCount; i++)
            pOut->m_aHandle[i] = pGpu->m_pGpus[nIndex].m_aDisplay[i].m_nValue;
        nResult = FUN_14160d1d0(pGpu, pGpu->m_pGpus[nIndex].m_nHandle, &pGpu->m_pGpus[nIndex]);
        do
        {
            if (nResult == 0)
                goto Exit;
        } while (0);
        pOut->m_nTotal = pGpu->m_pGpus[nIndex].m_n8;
        pOut->m_nFree = pGpu->m_pGpus[nIndex].m_nC;
    }
Exit:
    return nResult;
}

// @0x14160ce50
int FUN_14160ce50(NvidiaGPU* pGpu)
{
    int i = 0;
    pGpu->m_nGpus = 0;
    if (pGpu->m_pfn28 != 0)
    {
        for (i = 0; i < 4; i++)
        {
            int nHandle;
            int nRet = pGpu->m_pfn28(i, &nHandle);
            if (nRet == 0)
            {
                pGpu->m_pGpus[pGpu->m_nGpus].m_nHandle = nHandle;
                pGpu->m_nGpus++;
            }
        }
    }
    return pGpu->m_nGpus;
}

// @0x14160cf10
int FUN_14160cf10(NvidiaGPU* pGpu, int nHandle, Unk_NvGpu* pRec)
{
    int nResult = 0;
    int* pBuf = 0;
    int i = 0;
    int nCount = 0;
    if (pGpu->m_pfn30 != 0)
    {
        pBuf = new int[0x40];
        int nRet = pGpu->m_pfn30(nHandle, pBuf, &nCount);
        if (nRet == 0)
        {
            int nMax = 4;
            int nLimit = nCount;
            pRec->m_nDisplays = *FUN_14160d380(&nLimit, &nMax);
            for (i = 0; i < pRec->m_nDisplays; i++)
            {
                pRec->m_aDisplay[i].m_nHandle = pBuf[i];
                if (pGpu->m_pfn18 != 0 && pBuf[i] != 0)
                    pGpu->m_pfn18(pBuf[i], pRec->m_aDisplay[i].m_szName);
            }
            nResult = 1;
        }
        delete[] pBuf;
        pBuf = 0;
    }
    return nResult;
}

// @0x14160d090
int FUN_14160d090(NvidiaGPU* pGpu, int nUnused, Unk_NvGpu* pRec)
{
    int nResult = 0;
    int i = 0;
    int nRet = -1;
    Unk_NvPStateInfo* pInfo = 0;
    if (pGpu->m_pfn58 != 0)
    {
        pInfo = new Unk_NvPStateInfo;
        pInfo->m_nVersion = 0x1008c;
        for (i = 0; i < pRec->m_nDisplays; i++)
        {
            nRet = pGpu->m_pfn58(pRec->m_aDisplay[i].m_nHandle, pInfo);
            if (nRet == 0)
                pRec->m_aDisplay[i].m_nValue = pInfo->m_aValue[2];
        }
        delete pInfo;
        pInfo = 0;
        nResult = nRet == 0 ? 1 : 0;
    }
    return nResult;
}

// @0x14160d1d0
int FUN_14160d1d0(NvidiaGPU* pGpu, int nHandle, Unk_NvGpu* pRec)
{
    int nRet;
    int nResult = 0;
    nRet = -1;
    if (pGpu->m_pfn70 != 0)
    {
        Unk_NvClockInfo info;
        info.m_nVersion = 0x20018;
        nRet = pGpu->m_pfn70(nHandle, &info);
        if (nRet == 0)
        {
            pRec->m_n8 = info.m_aValue[0];
            pRec->m_nC = info.m_aValue[4];
            nResult = 1;
        }
    }
    return nResult;
}

// @0x14160d280
// MS2-BEHAVIOUR: the exe checks m_pfn58 but calls m_pfn48
int FUN_14160d280(NvidiaGPU* pGpu, int nUnused, Unk_NvGpu* pRec)
{
    int nResult = 0;
    int i = 0;
    int nRet = -1;
    Unk_NvDisplayInfo* pInfo = 0;
    if (pGpu->m_pfn58 != 0)
    {
        pInfo = new Unk_NvDisplayInfo;
        pInfo->m_nVersion = 0x20484;
        for (i = 0; i < pRec->m_nDisplays; i++)
            nRet = pGpu->m_pfn48(pRec->m_aDisplay[i].m_nHandle, pInfo);
        delete pInfo;
        pInfo = 0;
        nResult = nRet == 0 ? 1 : 0;
    }
    return nResult;
}

// @0x14160d380 (std::min<int>)
int* FUN_14160d380(int* a, int* b);
int* FUN_14160d380(int* a, int* b)
{
    if (*b < *a)
        return b;
    return a;
}

// @0x14160d3f0
unsigned __int64 NvidiaGPU::vfunc_4()
{
    return 0;
}

MS2_EMIT_CRT_MEMMOVE_S();
