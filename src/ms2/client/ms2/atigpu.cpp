// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). ATiGPU: the AMD (ATI Display Library, atiadlxx.dll) GPU
// helper behind GPUManager, with the GPUBass base whose default bodies serve the vendors without support.
// MS2-UNIT: ?\atigpu.cpp
// MS2-RANGE: 0x1409f0910-0x1409f11a0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\atigpu.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/ms2recover.h"
#include "gpumanager.h"

typedef void* (__cdecl* Unk_ADLMemAlloc)(int nSize);
typedef int (__cdecl* Unk_ADLMainControlCreate)(Unk_ADLMemAlloc pfnAlloc, int nEnumConnectedAdapters);
typedef int (__cdecl* Unk_ADLMainControlDestroy)();
typedef int (__cdecl* Unk_ADLQueryAdapter)(int nAdapterIndex, void* pInfo);

// The ADL memory callbacks (ADL_Main_Memory_Alloc / ADL_Main_Memory_Free of the SDK sample).
// @0x1409f0ec0
void* Alloc(int nSize)
{
    void* p = malloc(nSize);
    return p;
}

// @0x1409f0ef0
void FUN_1409f0ef0(void** ppBuffer)
{
    if (*ppBuffer != 0)
    {
        free(*ppBuffer);
        *ppBuffer = 0;
    }
}

// @0x1409f0910
ATiGPU::ATiGPU()
{
    m_hModule = 0;
    m_pActivity = 0;
    m_pMemoryInfo = 0;
    m_pfnMainControlCreate = 0;
    m_pfnMainControlDestroy = 0;
    m_pfnNumberOfAdaptersGet = 0;
    m_pfnDisplayInfoGet = 0;
    m_pfnTemperatureGet = 0;
    m_pfnFanSpeedInfoGet = 0;
    m_pfnMemoryInfoGet = 0;
    m_pfnSpeedGet = 0;
    m_pfnFanSpeedGet = 0;
    m_pfnCurrentActivityGet = 0;
    m_pfnAdapterInfoGet = 0;
    m_pfnAdapterActiveGet = 0;
    m_pfnColorCapsGet = 0;
    m_pfnColorGet = 0;
    m_pfnColorSet = 0;
}

// @0x1409f0a40
ATiGPU::~ATiGPU()
{
}

// @0x1409f0a70
int ATiGPU::vfunc_1()
{
    m_hModule = LoadLibraryA("atiadlxx.dll");
    if (m_hModule == 0)
        m_hModule = LoadLibraryA("atiadlxy.dll");
    if (m_hModule == 0)
        return 0;
    {
        m_pfnMainControlCreate = GetProcAddress(m_hModule, "ADL_Main_Control_Create");
        m_pfnMainControlDestroy = GetProcAddress(m_hModule, "ADL_Main_Control_Destroy");
        m_pfnNumberOfAdaptersGet = GetProcAddress(m_hModule, "ADL_Adapter_NumberOfAdapters_Get");
        m_pfnAdapterInfoGet = GetProcAddress(m_hModule, "ADL_Adapter_AdapterInfo_Get");
        m_pfnDisplayInfoGet = GetProcAddress(m_hModule, "ADL_Display_DisplayInfo_Get");
        m_pfnColorCapsGet = GetProcAddress(m_hModule, "ADL_Display_ColorCaps_Get");
        m_pfnColorGet = GetProcAddress(m_hModule, "ADL_Display_Color_Get");
        m_pfnColorSet = GetProcAddress(m_hModule, "ADL_Display_Color_Set");
        m_pfnCurrentActivityGet = GetProcAddress(m_hModule, "ADL_Overdrive5_CurrentActivity_Get");
        m_pfnTemperatureGet = GetProcAddress(m_hModule, "ADL_Overdrive5_Temperature_Get");
        m_pfnFanSpeedInfoGet = GetProcAddress(m_hModule, "ADL_Overdrive5_FanSpeedInfo_Get");
        m_pfnMemoryInfoGet = GetProcAddress(m_hModule, "ADL_Adapter_MemoryInfo_Get");
        m_pfnSpeedGet = GetProcAddress(m_hModule, "ADL_Adapter_Speed_Get");
        m_pfnFanSpeedGet = GetProcAddress(m_hModule, "ADL_Overdrive5_FanSpeed_Get");
        m_pfnAdapterActiveGet = GetProcAddress(m_hModule, "ADL_Adapter_Active_Get");
        if (m_pfnMainControlCreate != 0)
        {
            if (((Unk_ADLMainControlCreate)m_pfnMainControlCreate)(Alloc, 1) != 0)
                return 0;
        }
        else
        {
            return 0;
        }
        if (m_pfnCurrentActivityGet != 0)
        {
            void* pActivity = operator new(sizeof(Unk_ADLPMActivity));
            m_pActivity = (Unk_ADLPMActivity*)pActivity;
            memset(m_pActivity, 0, sizeof(Unk_ADLPMActivity));
            ((Unk_ADLQueryAdapter)m_pfnCurrentActivityGet)(0, m_pActivity);
        }
        if (m_pfnMemoryInfoGet != 0)
        {
            void* pMemoryInfo = operator new(sizeof(Unk_ADLMemoryInfo));
            m_pMemoryInfo = (Unk_ADLMemoryInfo*)pMemoryInfo;
            memset(m_pMemoryInfo, 0, sizeof(Unk_ADLMemoryInfo));
            ((Unk_ADLQueryAdapter)m_pfnMemoryInfoGet)(0, m_pMemoryInfo);
        }
        return 1;
    }
}

// @0x1409f0dd0
void ATiGPU::vfunc_2()
{
    if (m_pActivity != 0)
    {
        delete m_pActivity;
        m_pActivity = 0;
    }
    if (m_pMemoryInfo != 0)
    {
        delete m_pMemoryInfo;
        m_pMemoryInfo = 0;
    }
    if (m_pfnMainControlDestroy != 0)
        ((Unk_ADLMainControlDestroy)m_pfnMainControlDestroy)();
}

// @0x1409f0e80
unsigned __int64 ATiGPU::vfunc_4()
{
    if (m_pMemoryInfo != 0)
        return m_pMemoryInfo->m_nBandwidth;
    return 0;
}

// @0x1409f0f30
GPUBass::GPUBass()
{
}

// @0x1409f0f50
GPUBass::~GPUBass()
{
}

// @0x1409f0ff0
unsigned __int64 GPUBass::vfunc_4()
{
    return 0;
}

// @0x1409f1000
int ATiGPU::vfunc_5(unsigned __int64* a, unsigned __int64* b)
{
    return 0;
}

// @0x1409f1020
int GPUBass::vfunc_5(unsigned __int64* a, unsigned __int64* b)
{
    return 0;
}

// @0x1409f1040
int ATiGPU::vfunc_3(int* a, int* b)
{
    return 0;
}

// @0x1409f1060
int GPUBass::vfunc_3(int* a, int* b)
{
    return 0;
}

// @0x1409f1080
MS2_EMIT_CRT_MEMMOVE_S_COPY(1);
