// GPUManager (RTTI name): picks the vendor GPU helper (NVIDIA/AMD-ATI/Intel) from the display adapter name and polls memory use.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/commonfiles/timer.h"
class GPUManager;
template <class T> class TSingleton;
template <> class TSingleton<GPUManager> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static GPUManager* s_instance;
    static GPUManager* GetInstance();                   // 0x141245b20
};


// Vendor helper interface (RTTI name GPUBass; base of NvidiaGPU / ATiGPU, ?\atigpu.cpp). The no-GPU default bodies return 0.
class GPUBass {
public:
    GPUBass();                                          // 0x1409f0f30
    virtual ~GPUBass();                                 // 0x1409f0f50
    virtual int vfunc_1() = 0;                          // init, 0 = failed
    virtual void vfunc_2() = 0;                         // shutdown
    virtual int vfunc_3(int* a, int* b);                // 0x1409f1060
    virtual unsigned __int64 vfunc_4();                 // 0x1409f0ff0
    virtual int vfunc_5(unsigned __int64* a, unsigned __int64* b);   // 0x1409f1020
};
typedef GPUBass Unk_GPUBase;

// AMD Display Library (atiadlxx.dll) records the helper keeps.
struct Unk_ADLPMActivity { __int64 m_pad[5]; };         // 0x28 bytes
struct Unk_ADLMemoryInfo {                              // 0x110 bytes
    char m_pad_0[0x108];
    unsigned __int64 m_nBandwidth;                      // +0x108
};

class ATiGPU : public GPUBass {
public:
    ATiGPU();                                           // 0x1409f0910
    virtual ~ATiGPU();                                  // 0x1409f0a40
    virtual int vfunc_1() override;                     // 0x1409f0a70: loads atiadlxx.dll and starts ADL
    virtual void vfunc_2() override;                    // 0x1409f0dd0
    virtual int vfunc_3(int* a, int* b) override;       // 0x1409f1040
    virtual unsigned __int64 vfunc_4() override;        // 0x1409f0e80
    virtual int vfunc_5(unsigned __int64* a, unsigned __int64* b) override;   // 0x1409f1000

    FARPROC m_pfnMainControlCreate;                     // +0x08 ADL_Main_Control_Create
    FARPROC m_pfnMainControlDestroy;                    // +0x10
    FARPROC m_pfnNumberOfAdaptersGet;                   // +0x18
    FARPROC m_pfnDisplayInfoGet;                        // +0x20
    FARPROC m_pfnTemperatureGet;                        // +0x28
    FARPROC m_pfnFanSpeedInfoGet;                       // +0x30
    FARPROC m_pfnMemoryInfoGet;                         // +0x38
    FARPROC m_pfnSpeedGet;                              // +0x40
    FARPROC m_pfnFanSpeedGet;                           // +0x48
    FARPROC m_pfnCurrentActivityGet;                    // +0x50
    FARPROC m_pfnAdapterInfoGet;                        // +0x58
    FARPROC m_pfnAdapterActiveGet;                      // +0x60
    FARPROC m_pfnColorCapsGet;                          // +0x68
    FARPROC m_pfnColorGet;                              // +0x70
    FARPROC m_pfnColorSet;                              // +0x78
    HMODULE m_hModule;                                  // +0x80
    Unk_ADLPMActivity* m_pActivity;                     // +0x88
    Unk_ADLMemoryInfo* m_pMemoryInfo;                   // +0x90
};
MS2_CHECK_SIZE(ATiGPU, 0x98);
// One display output of an NVIDIA GPU (0x88 bytes).
struct Unk_NvDisplay {
    int m_nHandle;                                      // +0x00
    int m_nValue;                                       // +0x04
    char m_szName[0x80];                                // +0x08
};
// One physical NVIDIA GPU record (0x230 bytes).
struct Unk_NvGpu {
    int m_nHandle;                                      // +0x00
    int m_nDisplays;                                    // +0x04
    int m_n8;                                           // +0x08
    int m_nC;                                           // +0x0c
    Unk_NvDisplay m_aDisplay[4];                        // +0x10
};
MS2_CHECK_SIZE(Unk_NvGpu, 0x230);

typedef void* (__cdecl* Unk_NvQueryInterface)(unsigned int nId);
typedef int (__cdecl* Unk_NvInit)();
typedef int (__cdecl* Unk_NvGetName)(int nHandle, void* pOut);
typedef int (__cdecl* Unk_NvEnumGpu)(int nIndex, int* pHandle);
typedef int (__cdecl* Unk_NvEnumDisplays)(int nHandle, int* pBuf, int* pCount);
typedef int (__cdecl* Unk_NvQuery)(int nHandle, void* pInfo);

// NVIDIA (nvapi.dll) GPU helper: the nvapi entry points are fetched by id through nvapi_QueryInterface.
class NvidiaGPU : public GPUBass {
public:
    NvidiaGPU();                                        // 0x14160c6d0
    virtual ~NvidiaGPU();                               // 0x14160c740
    virtual int vfunc_1() override;                     // 0x14160c770: loads nvapi.dll, enumerates the GPUs
    virtual void vfunc_2() override;                    // 0x14160ca80
    virtual int vfunc_3(int* a, int* b) override;       // 0x14160cb10
    virtual unsigned __int64 vfunc_4() override;        // 0x14160d3f0
    virtual int vfunc_5(unsigned __int64* a, unsigned __int64* b) override;   // 0x14160cc20

    Unk_NvQueryInterface m_pfnQueryInterface;                          // +0x08 nvapi_QueryInterface
    Unk_NvInit m_pfn10;                                      // +0x10 initialize
    Unk_NvGetName m_pfn18;                                      // +0x18
    void* m_pfn20;                                      // +0x20
    Unk_NvEnumGpu m_pfn28;                                      // +0x28 enumerate GPU i
    Unk_NvEnumDisplays m_pfn30;                                      // +0x30
    void* m_pfn38;                                      // +0x38
    void* m_pfn40;                                      // +0x40
    Unk_NvQuery m_pfn48;                                      // +0x48
    Unk_NvQuery m_pfn50;                                      // +0x50
    Unk_NvQuery m_pfn58;                                      // +0x58
    void* m_pfn60;                                      // +0x60
    void* m_pfn68;                                      // +0x68
    Unk_NvQuery m_pfn70;                                      // +0x70
    void* m_pfn78;                                      // +0x78
    void* m_pfn80;                                      // +0x80
    void* m_pfn88;                                      // +0x88
    int m_nGpus;                                        // +0x90
    Unk_NvGpu* m_pGpus;                                 // +0x98
    HMODULE m_hModule;                                  // +0xa0
    int m_nA8;                                          // +0xa8
};
MS2_CHECK_SIZE(NvidiaGPU, 0xb0);

class Unk_GPUApp { public: double FUN_141473260(); float FUN_141473210(); /* frame rate (w25) */ };
Unk_GPUApp* FUN_14086d260();
class Unk_GPULog { public: void FUN_1401ce2b0(const char* text); };
Unk_GPULog* FUN_140a44830();
int FUN_140392040(char* buf, size_t size, const char* fmt, ...);

class GPUManager : public TSingleton<GPUManager> {
public:
    GPUManager();                                       // 0x141375250
    virtual ~GPUManager();                              // 0x141375320
    int FUN_141375390(CStringW adapterName);
    void FUN_1413758b0();
    void FUN_1413759f0();
    void FUN_141375a80();
    unsigned __int64 FUN_141375c80();
    unsigned __int64 FUN_141375c90();
    int FUN_141375ca0();

    int m_type;                                         // +0x08 1 nvidia, 2 amd/ati, 3 intel
    float m_elapsed;                                    // +0x0c
    GPUBass* m_gpu;                                 // +0x10
    CStringW m_name;                                    // +0x18
    unsigned __int64 m_20;                              // +0x20
    unsigned __int64 m_28;                              // +0x28
    int m_30;                                           // +0x30
    int m_34;                                           // +0x34
    unsigned __int64 m_38;                              // +0x38
    Timer m_timer;                                      // +0x40
};
MS2_CHECK_SIZE(GPUManager, 0x78);
