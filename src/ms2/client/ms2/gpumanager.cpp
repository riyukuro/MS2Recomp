// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: ?\gpumanager.cpp
// MS2-RANGE: 0x141375250-0x141375cb0 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gpumanager.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "gpumanager.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/crashmanagercli.h"
#include "hook/ms2hook.h"
// MS2: the exe calls the imported wcslen through the IAT (no /Oi inline loop, no static call).
extern "C" size_t (__cdecl* __imp_wcslen)(const wchar_t*);

GPUManager* TSingleton<GPUManager>::s_instance = 0;
inline TSingleton<GPUManager>::TSingleton() { s_instance = static_cast<GPUManager*>(this); }

// @0x141375250
GPUManager::GPUManager() : m_type(0), m_elapsed(0), m_gpu(0), m_20(0), m_28(0), m_30(0), m_34(0), m_38(0) {}

// @0x141375320
GPUManager::~GPUManager() { FUN_1413759f0(); }

// @0x141375390
int GPUManager::FUN_141375390(CStringW adapterName)
{
    if (m_gpu != 0) {
        delete m_gpu;
        m_gpu = 0;
    }
    if (!adapterName.IsEmpty()) {
        m_name = adapterName;
    } else {
        DISPLAY_DEVICEW dd;
        memset(&dd, 0, sizeof(dd));
        dd.cb = sizeof(DISPLAY_DEVICEW);
        if (EnumDisplayDevicesW(0, 0, &dd, 0) != 0) {
            int len = (int)__imp_wcslen(dd.DeviceString);
            for (int i = len - 1; i > 0; i--) {
                if (dd.DeviceString[i] == L' ')
                    dd.DeviceString[i] = L'\0';
                else
                    break;
            }
            m_name = dd.DeviceString;
        } else {
            return 0;
        }
    }
    CStringW nvidia(L"NVIDIA ");
    CStringW amd(L"AMD ");
    CStringW ati(L"ATI ");
    CStringW intel(L"Intel ");
    if (m_name.Find((LPCWSTR)nvidia, 0) != -1) {
        m_type = 1;
        m_gpu = new NvidiaGPU();
    } else if (m_name.Find((LPCWSTR)amd, 0) != -1) {
        m_type = 2;
        m_gpu = new ATiGPU();
    } else if (m_name.Find((LPCWSTR)ati, 0) != -1) {
        m_type = 2;
        m_gpu = new ATiGPU();
    } else if (m_name.Find((LPCWSTR)intel, 0) != -1) {
        m_type = 3;
    }
    if (m_gpu != 0) {
        if (m_gpu->vfunc_1() != 0)
            m_38 = m_gpu->vfunc_4() / 1000;
        else
            return 0;
    }
    m_timer.FUN_140868750(1000);
    return 1;
}

// @0x1413758b0
void GPUManager::FUN_1413758b0()
{
    m_elapsed += TSingleton<CMainSystem>::GetInstance()->GetDeltaTime();
    if (0.1f > m_elapsed) {
        m_elapsed = 0;
    } else if (m_timer.FUN_140868c00() != 0) {
        if (m_gpu != 0) {
            m_gpu->vfunc_3(&m_30, &m_34);
            m_gpu->vfunc_5(&m_20, &m_28);
        }
        m_timer.FUN_140868750(1000);
    }
}

// @0x1413759f0
void GPUManager::FUN_1413759f0()
{
    if (m_gpu != 0) {
        m_gpu->vfunc_2();
        delete m_gpu;
        m_gpu = 0;
    }
}

// @0x141375a80
void GPUManager::FUN_141375a80()
{
    char text[64];
    FUN_1413758b0();
    unsigned __int64 total = FUN_141375c90();
    unsigned __int64 used = FUN_141375c80();
    int percent = FUN_141375ca0();
    float pct = (float)percent * 0.01f;
    float mb = pct * (float)total;
    sprintf_s(text, 0x40, "Nv Using GPU memory %% %0.f(MB)", (double)mb);
    reinterpret_cast<CCrashManager*>(TSingleton<CrashManagerCli>::GetInstance())->FUN_1401ce2b0(text);
    sprintf_s(text, 0x40, "Nv Alloc GPU memory %zu/%zu(MB)", used, total);
    reinterpret_cast<CCrashManager*>(TSingleton<CrashManagerCli>::GetInstance())->FUN_1401ce2b0(text);
}

// @0x141375c80
unsigned __int64 GPUManager::FUN_141375c80() { return m_28; }

// @0x141375c90
unsigned __int64 GPUManager::FUN_141375c90() { return m_20; }

// @0x141375ca0
int GPUManager::FUN_141375ca0() { return m_34; }

MS2_REPLACE_METHOD(0x141375390, GPUManager, FUN_141375390, 1300, 0xE9CF4B22);
MS2_REPLACE_METHOD(0x1413758B0, GPUManager, FUN_1413758b0, 300, 0x9F48965D);
MS2_REPLACE_METHOD(0x1413759F0, GPUManager, FUN_1413759f0, 131, 0xCBCFC807);
MS2_REPLACE_METHOD(0x141375A80, GPUManager, FUN_141375a80, 291, 0xA07212EB);
