// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2RenderService (ecr::RenderService subclass with the game's
// renderer creation, device-lost handling and render-state dump), CRenderCallback and MS2PickService's OnPreInit/OnInit.
// MS2-UNIT: ?\ms2renderservice.cpp
// MS2-RANGE: 0x1414ea3d0-0x1414f0b90 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??$DynamicCast@VIConfigManager@efd@@VISystemService@2@@efd@@YAPEAVIConfigManager@0@PEAVISystemService@0@@Z 0x1414eed40 ; unique
// MS2-PIN: ??$DynamicCast@VWin32PlatformService@efd@@VISystemService@2@@efd@@YAPEAVWin32PlatformService@0@PEAVISystemService@0@@Z 0x1414eed90 ; unique
// MS2-PIN: ??$GetSystemServiceAs@VIConfigManager@efd@@@ServiceManager@efd@@QEBAPEAVIConfigManager@1@XZ 0x1414ef160 ; unique
// MS2-PIN: ??$GetSystemServiceAs@VWin32PlatformService@efd@@@ServiceManager@efd@@QEBAPEAVWin32PlatformService@1@XZ 0x1414ef1a0 ; unique
// MS2-PIN: ??_G?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVMS2RenderService@@P82@EAAXXZ@@UEAAPEAXI@Z 0x1414efb30 ; unique
// MS2-PIN: ??_G?$NiTArray@PEBVModeDesc@NiDX9AdapterDesc@@V?$NiTMallocInterface@PEBVModeDesc@NiDX9AdapterDesc@@@@@@UEAAPEAXI@Z 0x1414efb70 ; prop
// MS2-PIN: ??_G?$NiTArray@PEBVNiDX9AdapterDesc@@V?$NiTMallocInterface@PEBVNiDX9AdapterDesc@@@@@@UEAAPEAXI@Z 0x1414efbd0 ; prop
// MS2-PIN: ??_G?$NiTArray@VNiFixedString@@V?$NiTNewInterface@VNiFixedString@@@@@@UEAAPEAXI@Z 0x1414efc30 ; prop
// MS2-PIN: ??_G?$NiTArray@W4DepthStencilFormat@NiDX9Renderer@@V?$NiTMallocInterface@W4DepthStencilFormat@NiDX9Renderer@@@@@@UEAAPEAXI@Z 0x1414efc90 ; prop
// MS2-PIN: ??_G?$NiTArray@W4FrameBufferFormat@NiDX9Renderer@@V?$NiTMallocInterface@W4FrameBufferFormat@NiDX9Renderer@@@@@@UEAAPEAXI@Z 0x1414efcf0 ; prop
// MS2-PIN: ??_G?$NiTArray@W4FramebufferMode@NiDX9Renderer@@V?$NiTMallocInterface@W4FramebufferMode@NiDX9Renderer@@@@@@UEAAPEAXI@Z 0x1414efd50 ; prop
// MS2-PIN: ??_G?$NiTListBase@V?$NiTPointerAllocator@_K@@PEAVNiAVObject@@@@MEAAPEAXI@Z 0x1414efdb0 ; prop
// MS2-PIN: ??_G?$NiTObjectArray@VNiFixedString@@@@UEAAPEAXI@Z 0x1414efe10 ; prop
// MS2-PIN: ??_G?$NiTPointerList@PEAVNiAVObject@@@@UEAAPEAXI@Z 0x1414efe70 ; prop
// MS2-PIN: ??_G?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@PEAVNiAVObject@@@@UEAAPEAXI@Z 0x1414efed0 ; prop
// MS2-PIN: ?Clone@?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVMS2RenderService@@P82@EAAXXZ@@UEBAPEAV1@XZ 0x1414f03f0 ; unique
// MS2-PIN: ?GetPixelShaderVersion@NiDX9Renderer@@QEBAIXZ 0x1414f0490 ; unique
// MS2-PIN: ?GetRefCount@RenderService@ecr@@UEBAIXZ 0x1414f04b0 ; unique
// MS2-PIN: ?GetRenderState@NiDX9RenderState@@QEBAIW4_D3DRENDERSTATETYPE@@@Z 0x1414f04d0 ; unique
// MS2-PIN: ?GetSize@?$NiTArray@VNiFixedString@@V?$NiTNewInterface@VNiFixedString@@@@@@QEBAIXZ 0x1414f0580 ; unique
// MS2-PIN: ?GetTextureStageState@NiDX9RenderState@@QEBAIIW4_D3DTEXTURESTAGESTATETYPE@@@Z 0x1414f0590 ; unique
// MS2-PIN: ?GetVertexShaderVersion@NiDX9Renderer@@QEBAIXZ 0x1414f05d0 ; unique
// MS2-PIN: ?IncRefCount@RenderService@ecr@@UEBAXXZ 0x1414f05f0 ; unique
// MS2-PIN: ?TypeCast@RenderService@ecr@@UEBA_NIPEAPEAX@Z 0x1414f0af0 ; unique
// MS2-PIN: ?TypeCast@RenderService@ecr@@UEBA_NIPEAPEBX@Z 0x1414f0b40 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??1?$SmartPointer@VNiRenderer@@@efd@@QEAA@XZ 0x1414ef740 ; manual
// MS2-PIN: ??C?$SmartPointer@VNiRenderer@@@efd@@QEBAPEAVNiRenderer@@XZ 0x1414ef9e0 ; manual
// MS2-PIN: ??_GCRenderCallback@@UEAAPEAXI@Z 0x1414eff30 ; manual
// MS2-PIN: ?Invoke@?$ClassFunHandler@V?$TFunctor@XVEmptyParam@@@@PEAVMS2RenderService@@P82@EAAXXZ@@UEAAXXZ 0x1414efa00 ; manual
// MS2-PIN: ?DecRefCount@RenderService@ecr@@UEBAXXZ 0x1414f02e0 ; manual
// MS2-PIN: ?DeleteItem@?$NiTPointerListBase@V?$NiTPointerAllocator@_K@@PEAVNiAVObject@@@@MEAAXPEAV?$NiTListItem@PEAVNiAVObject@@@@@Z 0x1414f0320 ; manual
// MS2-PIN: ?DeleteThis@RenderService@ecr@@MEBAXXZ 0x1414f0360 ; manual
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2renderservice.h"
#include "ms2pickservice.h"
#include "ms2rendercontext.h"
#include "hook/ms2hook.h"
#include "ms2/ms2format.h"
#include <time.h>
#include <float.h>
#include <atlstr.h>
#include <d3d9.h>
#include <NiDX9Renderer.h>
#include <NiBaseRendererSetup.h>
#include <NiRendererSettings.h>
#include <NiMessageBox.h>
#include <NiImageReader.h>
#include <NiDevImageConverter.h>
#include <NiShaderFactory.h>
#include <NiString.h>
#include <NiPick.h>
#include <ecr/IDefaultSurfaceCreator.h>
#include <efd/IConfigManager.h>
#include <efd/Win32/Win32PlatformService.h>
#include <efd/ServiceManager.h>
#include "ms2/placeholder/tfunctor.h"
#include "ms2/commonfiles/logstring.h"

// ---- out-of-unit callees and data (bound to the exe by name) ----
CLogString* FUN_140166440();                                                 // the game log, or 0
void FUN_1401859c0(CLogString* pLog, int nLevel, int nCategory, const wchar_t* pszMessage);
CStringW FUN_14016a730(const char* pszAnsi, int nCodePage);                  // ANSI -> wide
CStringA FUN_14016a600(const wchar_t* pszWide, int nCodePage);               // wide -> ANSI
CStringW FUN_14028de60(int nStringId);                                       // UI string table (wide)
CStringA FUN_14028dc80(int nStringId);                                       // UI string table (ANSI)
void* FUN_140876480(void* pkOut, int nCategory);                             // memory category helper, returns unsigned int*
void* FUN_14208a860(unsigned __int64 ullSize, unsigned int uiCategory);      // tracked allocation
NiImageReader* FUN_140d9aba0(void* pkMemory);                                // MS2PNGReader constructor
NiImageConverter* FUN_141d6f370();                                           // current image converter
NiDevImageConverter* FUN_140a5af40(char* pRtti, NiImageConverter* pkConverter);   // checked cast to NiDevImageConverter
extern char DAT_143afa940;                                                   // RTTI descriptor of NiDevImageConverter
extern void (*DAT_143afb020)(NiAVObject*);                                   // scene-object post-collect hook
extern void (*DAT_143afbb98)();                                              // hook slots set by FUN_1414f07b0/07d0
extern void (*DAT_143afbba0)();
extern void (*DAT_143d6eb38)(void*);                                            // device-lost / reset hooks
struct Unk_RsRendererSize;
extern void (*DAT_143d6eb40)(Unk_RsRendererSize*);
extern void (*DAT_143d6eb48)();
extern void (*DAT_143d6eb50)(bool);
extern int DAT_143afa750;                                                    // last renderer creation failure code
extern int DAT_143af7d58;                                                    // "keep window hidden" switch
NiRenderer* GetNiRenderer();                                                 // the current NiRenderer
NiDX9Renderer* FUN_140d89bc0();                                              // the DX9 renderer, or 0

// Debug log (console) of the game.
class Unk_RsDebugLog
{
public:
    void FUN_1401ce2b0(const char* pszText);
    void FUN_1401ce2f0(const char* pszFormat, unsigned int a, unsigned int b);
    void FUN_1401ce2f0(const char* pszFormat, unsigned int a);
    void FUN_1401ce2f0(const char* pszFormat, ecr::RenderContext* a, unsigned int b);
    void FUN_1401ce2f0(const char* pszFormat, unsigned int a, unsigned int b, const char* c);
    void FUN_1401ce2f0(const char* pszFormat, const char* a);
};
Unk_RsDebugLog* FUN_140a44830();
void FUN_1401ce3d0(Unk_RsDebugLog* pLog, TFunctor<void, EmptyParam> kFunctor);   // registers a dump command

// Last renderer creation failure code.
// @0x1414f0480
inline int Unk_RsGetFailure() { return DAT_143afa750; }
// @0x1414f0750
inline void Unk_RsSetFailure(int iCode) { DAT_143afa750 = iCode; }

// Set of debug-text hooks; the hook slots store a plain function pointer.
// @0x1414f07b0
inline void Unk_RsSetHookA(void (*pfn)()) { DAT_143afbb98 = pfn; }
// @0x1414f07d0
inline void Unk_RsSetHookB(void (*pfn)()) { DAT_143afbba0 = pfn; }

// ---- 3-argument fmt log helper (log, level, category, "format", a, b, c) ----
// @0x1414ee9d0
template<class T, class U, class V> inline void Unk_RsLog3(CLogString* log, int level, int category, const wchar_t* format,
                                                           const T& first, const U& second, const V& third) {
    const fmt::internal::ArgArray<3>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(first),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(second),
                                                 fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t>>(third)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first, second, third), args));
}

// ---- shader-load context (the nif / node being loaded when a shader error is reported) ----
class Unk_RsShaderCtx { public: bool FUN_141d6fcf0(NiString& kNifPath, NiString& kNodeName); };
Unk_RsShaderCtx* FUN_141d6fd90();
// @0x1414f0ac0
inline bool Unk_RsGetShaderSource(NiString& kNifPath, NiString& kNodeName)
{
    return FUN_141d6fd90()->FUN_141d6fcf0(kNifPath, kNodeName);
}
// Effect manager: remembers the last executed effect / map effect names.
class Unk_RsEffectMgr { public: CStringA FUN_1411aad50(); CStringA FUN_1411aaeb0(); };
Unk_RsEffectMgr* FUN_1403ed280();

// ---- game singletons used while creating the renderer ----
// Video options (the stored resolution and flags).
class Unk_RsVideoOptions
{
public:
    unsigned int FUN_1409a8ab0();               // width
    unsigned int FUN_1409a8aa0();               // height
    void FUN_14125e1f0(int nValue, int bFlag);
    bool FUN_14125e820(int nWidth, int nHeight);
    void FUN_14125eb00(int nWidth, int nHeight);
    // @0x1414f0470
    int GetMode() const { return m_nMode; }
public:
    int m_n0;                    // +0x00
    int m_n4;                    // +0x04
    int m_nMode;                 // +0x08
    char m_pad0c[0x0a];          // +0x0c
    bool m_bVSync;               // +0x16
    char m_pad17[0x15];          // +0x17
    int m_nBufferFormat;         // +0x2c
};
MS2_CHECK_OFFSET(Unk_RsVideoOptions, m_nMode, 0x8);
MS2_CHECK_OFFSET(Unk_RsVideoOptions, m_bVSync, 0x16);
MS2_CHECK_OFFSET(Unk_RsVideoOptions, m_nBufferFormat, 0x2c);
class Unk_RsOptions
{
public:
    Unk_RsVideoOptions* FUN_1409a8ac0();
    int FUN_141243f50(int nWhich);
    int FUN_1412438f0();
    void FUN_1412432d0();
};
Unk_RsOptions* FUN_1409a8b10();
// Application window manager.
class Unk_RsApp
{
public:
    void FUN_1412642e0(bool bFullscreen);
    void FUN_141b91290(bool bFullscreen, int nWidth, int nHeight);
    bool FUN_141b91010(bool bFullscreen, int nWidth, int nHeight);
    // @0x1414f0610
    bool IsWindowHidden() const { return m_bHidden; }
public:
    char m_pad[0xd0];
    bool m_bHidden;                // +0xd0
};
MS2_CHECK_OFFSET(Unk_RsApp, m_bHidden, 0xd0);
Unk_RsApp* FUN_140aadf80();
// GPU information.
class Unk_RsGpuInfo
{
public:
    CStringW& FUN_141245ab0(const CStringW& kOut);   // MS2: fills and returns the by-value temporary
    void FUN_141375390(CStringW kName);
};
Unk_RsGpuInfo* FUN_141245b20();
bool FUN_1403b3c40(const CStringW& kText, const wchar_t* pszFind);
class Unk_RsVSync { public: void FUN_14161c3f0(); };
Unk_RsVSync* FUN_1409f7c90();
class Unk_RsFbFormats { public: int FUN_141376790(int nIndex); };
Unk_RsFbFormats* FUN_140ae1c00();
int FUN_141b91ab0();
// UI front end: slot 23 shows a message dialog.
class Unk_RsUI
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22();
    virtual void ShowCloseNotice(int nStringId, const char* pszArg);           // MS2: slot 23
};
Unk_RsUI* FUN_140d86260();
void FUN_141b6fcf0(const CStringW& kText, const CStringW& kTitle, int nFlags);   // message box + quit prompt

// ---- engine-adjacent pieces (MS2 additions) ----
// NiRenderer's recursive lock, entered/left without the Do_LockRenderer virtuals.
class Unk_RsRenderer
{
public:
    char m_pad[0xe20];
    efd::CriticalSection m_kLock;     // +0xe20
    // @0x1414f0190
    void LockSimple() { m_kLock.Lock(); }
    // @0x1414f01c0
    void UnlockSimple() { m_kLock.Unlock(); }
};
MS2_CHECK_OFFSET(Unk_RsRenderer, m_kLock, 0xe20);

// The renderer as seen by the device-reset hook: the creation size sits at +0x1074.
struct Unk_RsRendererSize
{
    char m_pad[0x1074];
    unsigned int m_uiWidth;      // +0x1074
    unsigned int m_uiHeight;     // +0x1078
    // @0x1414f0520
    unsigned int GetWidth() const { return m_uiWidth; }
    // @0x1414f0500
    unsigned int GetHeight() const { return m_uiHeight; }
};
MS2_CHECK_OFFSET(Unk_RsRendererSize, m_uiHeight, 0x1078);

// Scene-object collector reachable through the global at 0x143afa980.
class Unk_RsCollector
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2();
    virtual void Collect(NiAVObject* pRoot, NiTPointerList<NiAVObject*>* pOut, bool bRecurse);   // MS2: slot 3
};
struct Unk_RsSceneRoot
{
    char m_pad[0x218];
    Unk_RsCollector* m_pCollector;      // +0x218
};
MS2_CHECK_OFFSET(Unk_RsSceneRoot, m_pCollector, 0x218);
extern Unk_RsSceneRoot* DAT_143afa980;
// @0x1414f0540
inline Unk_RsCollector* Unk_RsGetCollector()
{
    return DAT_143afa980 != 0 ? DAT_143afa980->m_pCollector : 0;
}
// Objects with a "fade" virtual (slot 41) found by the collector.
class Unk_RsFadeObject
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15();
    virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19();
    virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23();
    virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27();
    virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31();
    virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35();
    virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void SetFadeValue(float fValue);       // MS2: slot 41
};
extern char DAT_143afbfb8;                                  // RTTI descriptor of Unk_RsFadeObject
Unk_RsFadeObject* FUN_14098d8d0(char* pRtti, NiAVObject* pObject);
void FUN_141d2c900(NiAVObject* pObject, bool bFlag);
class Unk_RsWorldService
{
public:
    void FUN_141bd8660(unsigned int uiWidth);
    void FUN_141bd8680(unsigned int uiHeight);
};
Unk_RsWorldService* FUN_1403ed2d0();
void FUN_141bbae40(Unk_RsWorldService* pWorld, IWorldServiceCallback* pCallback);
void FUN_1414f0700(NiPick* pPick);

// ---- unit statics ----
static __time64_t s_lastDeviceOkTime;        // 0x143ae0c10
static bool s_deviceLostNoticeShown;         // 0x143ae0c18
static bool s_driverErrorShown;              // 0x143ae0c19
static bool s_deviceOk = false;              // 0x1439f800c


static unsigned int Unk_RsShaderError(const char* pcMsg, NiShaderError eErr, bool bRecoverable);
static void Unk_RsLockHook();
static void Unk_RsUnlockHook();
static void Unk_RsCollectFade(NiAVObject* pRoot);
static void Unk_RsNoopHook(void* pUnused);
static void Unk_RsResetHook(Unk_RsRendererSize* pRenderer);
static void Unk_RsDriverErrorHook();
static void Unk_RsDeviceLostHook(bool bDeviceOk);

// ---- renderer log ----
// @0x1414ea3d0
void CRenderCallback::Message(const char* pText)
{
    if (FUN_140166440() != 0) {
        CStringA text(pText);
        text.Trim();
        FUN_1401859c0(FUN_140166440(), 0xb, 0x13, FUN_14016a730(text, 0));
    }
}
MS2_REPLACE_METHOD(0x1414EA3D0, CRenderCallback, Message, 184, 0x559ACDD4);

// @0x1414ea490
void CRenderCallback::Warning(const char* pText)
{
    if (FUN_140166440() != 0) {
        CStringA text(pText);
        text.Trim();
        FUN_1401859c0(FUN_140166440(), 2, 0x13, FUN_14016a730(text, 0));
    }
}
MS2_REPLACE_METHOD(0x1414EA490, CRenderCallback, Warning, 184, 0xC0005629);

// @0x1414ea550
void CRenderCallback::Error(const char* pText)
{
    if (FUN_140166440() != 0) {
        CStringA text(pText);
        text.Trim();
        FUN_1401859c0(FUN_140166440(), 1, 0x13, FUN_14016a730(text, 0));
    }
    if (FUN_140a44830() != 0) {
        FUN_140a44830()->FUN_1401ce2f0("Renderer: %s", pText);
    }
}
MS2_REPLACE_METHOD(0x1414EA550, CRenderCallback, Error, 219, 0x9B8E5B6C);

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x1414ea640
MS2RenderService::MS2RenderService(NiWindowRef parentHandle)
    : ecr::RenderService(parentHandle)
{
    m_bValidateFrames = 0;
    m_pRendererDesc = 0;
    m_pCurrentContext = 0;
    m_uiCurrentIndex = 0;
}
#endif

// @0x1414ea6d0
MS2RenderService::~MS2RenderService()
{
}

// MS2-FUNCTIONAL: the exe builds the TFunctor temporary with one more unwind state and a different stack layout (frame 0xb8 vs 0xa8); the AddReader call also copies the reader into an extra slot.
// @0x1414ea710
efd::SyncResult MS2RenderService::OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar)
{
    efd::SyncResult result = ecr::RenderService::OnPreInit(pDependencyRegistrar);
    if (result == efd::SyncResult_Success) {
        NiDevImageConverter* pConverter = FUN_140a5af40(&DAT_143afa940, FUN_141d6f370());
        if (pConverter != 0) {
            int categoryTemp;
            unsigned int* puiCategory = (unsigned int*)FUN_140876480(&categoryTemp, 0);
            void* pReaderMemory = FUN_14208a860(0xe0, *puiCategory);
            NiImageReader* pReader;
            if (pReaderMemory == 0) {
                pReader = 0;
            } else {
                pReader = FUN_140d9aba0(pReaderMemory);
            }
            pConverter->AddReader(pReader);
        }
    }
    NiShaderFactory::RegisterErrorCallback(Unk_RsShaderError);
    DAT_143afb020 = Unk_RsCollectFade;
    Unk_RsSetHookA(Unk_RsLockHook);
    Unk_RsSetHookB(Unk_RsUnlockHook);
    FUN_1401ce3d0(FUN_140a44830(), TFunctor<void, EmptyParam>(this, &MS2RenderService::LogState));
    return result;
}

// MS2-FUNCTIONAL: 8.6 KB render-state dump; the 86 render-state and 17 texture-stage checks are macro-expanded here, but the exe keeps different temporaries/logging templates per check, so stack layout and unwind states differ.
// @0x1414ea8b0
void MS2RenderService::CheckRenderState()
{
    NiRenderer* pBase = m_spRenderer;
    if (pBase == 0) {
        return;
    }
    NiDX9Renderer* pRenderer = static_cast<NiDX9Renderer*>(pBase);
    IDirect3DDevice9* pDevice = pRenderer->GetD3DDevice();
    NiDX9RenderState* pRenderState = pRenderer->GetRenderState();
    if (pDevice == 0 || pRenderState == 0) {
        return;
    }
    DWORD deviceValue = 0;
    unsigned int niValue = 0;
    FUN_140a44830()->FUN_1401ce2b0("Check render state Start!!");
#define CHECK_RS(state) \
    niValue = pRenderState->GetRenderState(state); \
    pDevice->GetRenderState(state, &deviceValue); \
    FUN_140a44830()->FUN_1401ce2f0("CheckRenderState " #state " : Device [%d] NiState[%d]", deviceValue, niValue)
        CHECK_RS(D3DRS_ZENABLE);
        CHECK_RS(D3DRS_FILLMODE);
        CHECK_RS(D3DRS_SHADEMODE);
        CHECK_RS(D3DRS_ZWRITEENABLE);
        CHECK_RS(D3DRS_ALPHATESTENABLE);
        CHECK_RS(D3DRS_LASTPIXEL);
        CHECK_RS(D3DRS_SRCBLEND);
        CHECK_RS(D3DRS_DESTBLEND);
        CHECK_RS(D3DRS_CULLMODE);
        CHECK_RS(D3DRS_ZFUNC);
        CHECK_RS(D3DRS_ALPHAREF);
        CHECK_RS(D3DRS_ALPHAFUNC);
        CHECK_RS(D3DRS_DITHERENABLE);
        CHECK_RS(D3DRS_ALPHABLENDENABLE);
        CHECK_RS(D3DRS_FOGENABLE);
        CHECK_RS(D3DRS_SPECULARENABLE);
        CHECK_RS(D3DRS_FOGCOLOR);
        CHECK_RS(D3DRS_FOGTABLEMODE);
        CHECK_RS(D3DRS_FOGSTART);
        CHECK_RS(D3DRS_FOGEND);
        CHECK_RS(D3DRS_FOGDENSITY);
        CHECK_RS(D3DRS_RANGEFOGENABLE);
        CHECK_RS(D3DRS_STENCILENABLE);
        CHECK_RS(D3DRS_STENCILFAIL);
        CHECK_RS(D3DRS_FOGDENSITY);
        CHECK_RS(D3DRS_STENCILZFAIL);
        CHECK_RS(D3DRS_STENCILPASS);
        CHECK_RS(D3DRS_STENCILFUNC);
        CHECK_RS(D3DRS_STENCILREF);
        CHECK_RS(D3DRS_STENCILMASK);
        CHECK_RS(D3DRS_STENCILWRITEMASK);
        CHECK_RS(D3DRS_TEXTUREFACTOR);
        CHECK_RS(D3DRS_CLIPPING);
        CHECK_RS(D3DRS_LIGHTING);
        CHECK_RS(D3DRS_AMBIENT);
        CHECK_RS(D3DRS_FOGVERTEXMODE);
        CHECK_RS(D3DRS_COLORVERTEX);
        CHECK_RS(D3DRS_LOCALVIEWER);
        CHECK_RS(D3DRS_NORMALIZENORMALS);
        CHECK_RS(D3DRS_DIFFUSEMATERIALSOURCE);
        CHECK_RS(D3DRS_SPECULARMATERIALSOURCE);
        CHECK_RS(D3DRS_AMBIENTMATERIALSOURCE);
        CHECK_RS(D3DRS_EMISSIVEMATERIALSOURCE);
        CHECK_RS(D3DRS_CLIPPLANEENABLE);
        CHECK_RS(D3DRS_POINTSIZE);
        CHECK_RS(D3DRS_POINTSIZE_MIN);
        CHECK_RS(D3DRS_POINTSPRITEENABLE);
        CHECK_RS(D3DRS_POINTSCALEENABLE);
        CHECK_RS(D3DRS_POINTSCALE_A);
        CHECK_RS(D3DRS_POINTSCALE_B);
        CHECK_RS(D3DRS_POINTSCALE_C);
        CHECK_RS(D3DRS_MULTISAMPLEANTIALIAS);
        CHECK_RS(D3DRS_MULTISAMPLEMASK);
        CHECK_RS(D3DRS_PATCHEDGESTYLE);
        CHECK_RS(D3DRS_DEBUGMONITORTOKEN);
        CHECK_RS(D3DRS_POINTSIZE_MAX);
        CHECK_RS(D3DRS_INDEXEDVERTEXBLENDENABLE);
        CHECK_RS(D3DRS_COLORWRITEENABLE);
        CHECK_RS(D3DRS_TWEENFACTOR);
        CHECK_RS(D3DRS_BLENDOP);
        CHECK_RS(D3DRS_POSITIONDEGREE);
        CHECK_RS(D3DRS_NORMALDEGREE);
        CHECK_RS(D3DRS_SCISSORTESTENABLE);
        CHECK_RS(D3DRS_SLOPESCALEDEPTHBIAS);
        CHECK_RS(D3DRS_ANTIALIASEDLINEENABLE);
        CHECK_RS(D3DRS_MINTESSELLATIONLEVEL);
        CHECK_RS(D3DRS_MAXTESSELLATIONLEVEL);
        CHECK_RS(D3DRS_ADAPTIVETESS_X);
        CHECK_RS(D3DRS_ADAPTIVETESS_Y);
        CHECK_RS(D3DRS_ADAPTIVETESS_Z);
        CHECK_RS(D3DRS_ADAPTIVETESS_W);
        CHECK_RS(D3DRS_ENABLEADAPTIVETESSELLATION);
        CHECK_RS(D3DRS_TWOSIDEDSTENCILMODE);
        CHECK_RS(D3DRS_CCW_STENCILZFAIL);
        CHECK_RS(D3DRS_CCW_STENCILPASS);
        CHECK_RS(D3DRS_CCW_STENCILFUNC);
        CHECK_RS(D3DRS_COLORWRITEENABLE1);
        CHECK_RS(D3DRS_COLORWRITEENABLE2);
        CHECK_RS(D3DRS_COLORWRITEENABLE3);
        CHECK_RS(D3DRS_BLENDFACTOR);
        CHECK_RS(D3DRS_SRGBWRITEENABLE);
        CHECK_RS(D3DRS_DEPTHBIAS);
        CHECK_RS(D3DRS_SEPARATEALPHABLENDENABLE);
        CHECK_RS(D3DRS_SRCBLENDALPHA);
        CHECK_RS(D3DRS_DESTBLENDALPHA);
        CHECK_RS(D3DRS_SRCBLENDALPHA);
        CHECK_RS(D3DRS_BLENDOPALPHA);
#undef CHECK_RS
    for (int stage = 0; stage < 8; stage = stage + 1) {
        FUN_140a44830()->FUN_1401ce2f0("TextureStageState %d", stage);
#define CHECK_TSS(type) \
        niValue = pRenderState->GetTextureStageState(stage, type); \
        pDevice->GetTextureStageState(stage, type, &deviceValue); \
        FUN_140a44830()->FUN_1401ce2f0("CheckTextureStageState " #type " : Device [%d] NiState[%d]", deviceValue, niValue)
            CHECK_TSS(D3DTSS_COLOROP);
            CHECK_TSS(D3DTSS_COLORARG1);
            CHECK_TSS(D3DTSS_COLORARG2);
            CHECK_TSS(D3DTSS_ALPHAOP);
            CHECK_TSS(D3DTSS_COLOROP);
            CHECK_TSS(D3DTSS_ALPHAARG1);
            CHECK_TSS(D3DTSS_ALPHAARG2);
            CHECK_TSS(D3DTSS_BUMPENVMAT00);
            CHECK_TSS(D3DTSS_BUMPENVMAT01);
            CHECK_TSS(D3DTSS_BUMPENVMAT10);
            CHECK_TSS(D3DTSS_BUMPENVMAT11);
            CHECK_TSS(D3DTSS_TEXCOORDINDEX);
            CHECK_TSS(D3DTSS_BUMPENVLSCALE);
            CHECK_TSS(D3DTSS_BUMPENVLOFFSET);
            CHECK_TSS(D3DTSS_TEXTURETRANSFORMFLAGS);
            CHECK_TSS(D3DTSS_COLORARG0);
            CHECK_TSS(D3DTSS_ALPHAARG0);
            CHECK_TSS(D3DTSS_RESULTARG);
#undef CHECK_TSS
    }
    FUN_140a44830()->FUN_1401ce2b0("Check render state End!!");
}


// @0x1414eca50
void MS2RenderService::AddRenderedEntity(egf::Entity* pEntity, NiAVObject* pAVObject)
{
    ecr::RenderService::AddRenderedEntity(pEntity, pAVObject);
}
MS2_REPLACE_METHOD(0x1414ECA50, MS2RenderService, AddRenderedEntity, 44, 0xE3E400E7);

// @0x1414eca90
void MS2RenderService::RemoveRenderedEntity(egf::Entity* pEntity, NiAVObject* pAVObject)
{
    for (DelegateList::iterator i = m_renderServiceDelegates.begin(); i != m_renderServiceDelegates.end(); ++i) {
        (*i)->OnRenderedEntityRemoved(this, pEntity, pAVObject);
    }
    efd::UInt32 size = GetRenderContextCount();
    for (efd::UInt32 ui = 0; ui < size; ++ui) {
        (m_renderContexts[ui])->RemoveRenderedEntity(pEntity, pAVObject);
    }
}
MS2_REPLACE_METHOD(0x1414ECA90, MS2RenderService, RemoveRenderedEntity, 256, 0x514594B4);

// @0x1414ecba0
void MS2RenderService::SetValidateFrames(bool bValidate)
{
    m_bValidateFrames = bValidate;
    ecr::RenderContext* pContext = GetActiveRenderContext();
    if (pContext != 0) {
        pContext->SetValidateFrames(m_bValidateFrames);
    }
}
MS2_REPLACE_METHOD(0x1414ECBA0, MS2RenderService, SetValidateFrames, 79, 0x779F6C4C);

// The exe instantiates this 3-argument form against its own copy of the formatter (the one the socket code uses).
CStringA FUN_1402bf9a0(const char* format, const fmt::ArgList& args);
// @0x1414eede0
template<> CStringA StringFormat<const char*, const char*, const char*>(const char* format, const char* const& first,
                                                                        const char* const& second, const char* const& third)
{
    const fmt::internal::ArgArray<3>::Type array = {fmt::internal::MakeValue<fmt::BasicFormatter<char>>(first),
                                                  fmt::internal::MakeValue<fmt::BasicFormatter<char>>(second),
                                                  fmt::internal::MakeValue<fmt::BasicFormatter<char>>(third)};
    return FUN_1402bf9a0(format, fmt::ArgList(fmt::internal::make_type(first, second, third), array));
}

// Shader factory error callback: logs, asks whether to keep going, and throws on "yes".
// MS2-FUNCTIONAL: the CStringA temporaries (text, formatted notice) get a different unwind-state numbering than the exe (state order 2/5/4 vs 3/2/4).
// @0x1414ecc00
static unsigned int Unk_RsShaderError(const char* pcMsg, NiShaderError eErr, bool bRecoverable)
{
    CStringA text;
    NiString kNifPath(0x100);
    NiString kNodeName(0x100);
    if (!Unk_RsGetShaderSource(kNifPath, kNodeName)) {
        text = StringFormat("Shader Error\260\241 \271\337\273\375\307\337\275\300\264\317\264\331.\n\n\270\266\301\366\270\267 \275\307\307\340\265\310 \300\314\306\345\306\256\n{0}\n\n\270\266\301\366\270\267 \275\307\307\340\265\310 \270\312 \300\314\306\345\306\256\n{1}\n\n.\264\375\307\301 \306\304\300\317\300\273 \273\375\274\272\307\317\275\303\260\332\275\300\264\317\261\356?", FUN_1403ed280()->FUN_1411aad50(), FUN_1403ed280()->FUN_1411aaeb0());
    } else {
        text = StringFormat("Shader Error\260\241 \271\337\273\375\307\337\275\300\264\317\264\331.\n\nNif path : \n{0}\n\nNode name : {1}\n\n{2}\n\n\264\375\307\301 \306\304\300\317\300\273 \273\375\274\272\307\317\275\303\260\332\275\300\264\317\261\356?", (const char*)kNifPath, (const char*)kNodeName, pcMsg);
    }
    Unk_RsLog3(FUN_140166440(), 1, 0x133, L"Code:{0:X} bRecoverable:{1} {2}", eErr, bRecoverable, pcMsg);
    int answer = MessageBoxA(0, text, "Shader error", 4);
    if (answer == 6) {
        FUN_140a44830()->FUN_1401ce2f0("[%x][bRecoverable %d] %s", eErr, (unsigned int)bRecoverable, pcMsg);
        throw 0xd;
    }
    return 0;
}

// @0x1414ecec0
static void Unk_RsLockHook()
{
    NiRenderer* pRenderer = GetNiRenderer();
    if (pRenderer != 0) {
        reinterpret_cast<Unk_RsRenderer*>(pRenderer)->LockSimple();
    }
}

// @0x1414ecef0
static void Unk_RsUnlockHook()
{
    NiRenderer* pRenderer = GetNiRenderer();
    if (pRenderer != 0) {
        reinterpret_cast<Unk_RsRenderer*>(pRenderer)->UnlockSimple();
    }
}

// @0x1414ecf20
void MS2RenderService::LogState()
{
    FUN_140a44830()->FUN_1401ce2b0("\n--- MS2RenderService Log---");
    FUN_140a44830()->FUN_1401ce2f0("Current Context %x %d", m_pCurrentContext, m_uiCurrentIndex);
}
MS2_REPLACE_METHOD(0x1414ECF20, MS2RenderService, LogState, 78, 0x102BBE40);

// MS2-FUNCTIONAL: unwind-state boundaries and a few temporaries differ (ip2state offsets are 7 bytes apart after the SmartPointer temporary).
// @0x1414ecf80
bool MS2RenderService::CreateRendererSized(bool bFullscreen, int width, int height)
{
    efd::Win32PlatformService* pWin32 = m_pServiceManager->GetSystemServiceAs<efd::Win32PlatformService>();
    if (m_parentHandle == 0 && pWin32 != 0) {
        m_parentHandle = pWin32->GetWindowRef();
    }
    NiRendererSettings settings;
    settings.LoadFromConfigManager(m_pServiceManager->GetSystemServiceAs<efd::IConfigManager>());
    settings.m_bVSync = FUN_1409a8b10()->FUN_1409a8ac0()->m_bVSync;
    settings.m_eDX9FBFormat = (NiDX9Renderer::FramebufferMode)FUN_140ae1c00()->FUN_141376790(
        FUN_1409a8b10()->FUN_1409a8ac0()->m_nBufferFormat);
    settings.m_uiScreenWidth = width;
    settings.m_uiScreenHeight = height;
    settings.m_bFullscreen = bFullscreen;
    if (settings.m_bVSync) {
        FUN_1409f7c90()->FUN_14161c3f0();
    }
    if (FUN_140aadf80()->IsWindowHidden()) {
        settings.m_bFullscreen = false;
    }
    if (m_parentHandle != 0 && settings.m_uiScreenHeight != 0 && settings.m_uiScreenWidth != 0) {
        WINDOWINFO windowInfo;
        windowInfo.cbSize = sizeof(windowInfo);
        GetWindowInfo(m_parentHandle, &windowInfo);
        FUN_140aadf80()->FUN_141b91290(bFullscreen, settings.m_uiScreenWidth, settings.m_uiScreenHeight);
        if (bFullscreen && (FUN_140aadf80(), DAT_143af7d58 == 0)) {
            ShowWindow(m_parentHandle, SW_SHOWMAXIMIZED);
        }
    }
    m_spRenderer = NiBaseRendererSetup::CreateRenderer(&settings, m_parentHandle, m_parentHandle);
    if (settings.m_eRendererID == efd::SystemDesc::RENDERER_DX9) {
        NiRenderer* pRenderer = m_spRenderer;
        if (pRenderer != 0) {
            NiDX9Renderer* pDX9Renderer = static_cast<NiDX9Renderer*>(pRenderer);
            if (pDX9Renderer->GetVertexShaderVersion() < 0xfffe0300) {
                Unk_RsSetFailure(0x10);
                return false;
            }
            if (pDX9Renderer->GetPixelShaderVersion() < 0xfffe0300) {
                Unk_RsSetFailure(0x11);
                return false;
            }
            NiDX9Renderer* pActive = FUN_140d89bc0();
            if ((pActive->GetFlags() & 0x20) == 0) {
                Unk_RsSetFailure(0x12);
                return false;
            }
            CStringA driver(pDX9Renderer->NiDX9Renderer::GetDriverInfo());
            driver.MakeLower();
            if (driver.Find("mctu.dll") >= 0) {
                FUN_140a44830()->FUN_1401ce2b0("!!! mctu.dll !!!");
            }
            pDX9Renderer->AddLostDeviceNotificationFunc(&ecr::RenderService::OnDeviceLost, this);
            pDX9Renderer->AddResetNotificationFunc(&ecr::RenderService::OnDeviceReset, this);
            NiRenderer::SetCallbackObject(&m_renderCallback);
            DAT_143d6eb48 = Unk_RsDriverErrorHook;
            DAT_143d6eb50 = Unk_RsDeviceLostHook;
            DAT_143d6eb38 = Unk_RsNoopHook;
            DAT_143d6eb40 = Unk_RsResetHook;
            FUN_140aadf80()->FUN_141b91290(bFullscreen, settings.m_uiScreenWidth, settings.m_uiScreenHeight);
        }
    }
    return m_spRenderer != 0;
}

// MS2-FUNCTIONAL: 3.8 KB; the settings/adapter-list setup creates several NiTObjectArray temporaries whose order and unwind states differ from the exe.
// @0x1414ed3a0
efd::AsyncResult MS2RenderService::OnInit()
{
    if (FUN_141b91ab0() != 0) {
        return efd::AsyncResult_Pending;
    }
    if (m_pRendererDesc == 0) {
        NiRendererSettings settings;
        settings.LoadFromConfigManager(m_pServiceManager->GetSystemServiceAs<efd::IConfigManager>());
        settings.m_bVSync = true;
        settings.m_eDX9FBFormat = NiDX9Renderer::FBMODE_DEFAULT;
        settings.m_bFullscreen = false;
        settings.m_uiScreenWidth = GetSystemMetrics(SM_CXSCREEN);
        settings.m_uiScreenHeight = GetSystemMetrics(SM_CYSCREEN);
        int categoryTemp;
        unsigned int* puiCategory = (unsigned int*)FUN_140876480(&categoryTemp, 0);
        void* pDescMemory = FUN_14208a860(0xb0, *puiCategory);
        NiDX9RendererDesc* pDesc;
        if (pDescMemory == 0) {
            pDesc = 0;
        } else {
            pDesc = new (pDescMemory) NiDX9RendererDesc(&settings);
        }
        m_pRendererDesc = pDesc;
        if (!m_pRendererDesc->Initialize()) {
            CStringW message;
            message.Format(L"%s", (LPCWSTR)FUN_14028de60(0x8d7));
            NiMessageBox(FUN_14016a600(message, 0), FUN_14028dc80(0x8d4), 0);
            return efd::AsyncResult_Failure;
        }
        NiTObjectArray<NiFixedString> adapters(0, 1);
        m_pRendererDesc->GetAdapterList(adapters);
        CStringW adapterName;
        if (adapters.GetSize() != 0) {
            std::string name(adapters.GetAt(0));
            int n = (int)name.length();
            while (n = n - 1, 0 < n && name[n] == ' ') {
                name[n] = 0;
            }
            adapterName = FUN_14016a730(name.c_str(), 0);
        }
        FUN_141245b20()->FUN_141375390(adapterName);
    }
    int fullscreenMode = FUN_1409a8b10()->FUN_141243f50(0);
    bool bFullscreenFlag;
    if (fullscreenMode == 0) {
        FUN_1409a8b10()->FUN_1409a8ac0();
        bFullscreenFlag = (FUN_1409a8b10()->FUN_1409a8ac0()->GetMode() == 0);
    } else {
        bFullscreenFlag = false;
    }
    bool bBorderless;
    if (fullscreenMode == 0) {
        bBorderless = (FUN_1409a8b10()->FUN_1409a8ac0()->GetMode() == 2);
    } else {
        bBorderless = true;
    }
    int width;
    if (fullscreenMode == 0) {
        width = FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1409a8ab0();
    } else {
        width = GetSystemMetrics(SM_CXSCREEN);
    }
    int height;
    if (fullscreenMode == 0) {
        height = FUN_1409a8b10()->FUN_1409a8ac0()->FUN_1409a8aa0();
    } else {
        height = GetSystemMetrics(SM_CYSCREEN);
    }
    FUN_140aadf80()->FUN_1412642e0(bBorderless);
    if (bBorderless) {
        bFullscreenFlag = true;
    }
    if (fullscreenMode != 0) {
        int mode = FUN_1409a8b10()->FUN_1412438f0();
        FUN_1409a8b10()->FUN_1409a8ac0()->FUN_14125e1f0(mode, 1);
    }
    bool bBasicDriver;
    {
        CStringW driverName;
        bBasicDriver = FUN_1403b3c40(FUN_141245b20()->FUN_141245ab0(driverName), L"Microsoft Basic Display Driver");
    }
    if (bBasicDriver) {
        FUN_140d86260()->ShowCloseNotice(0x397, "");
        CStringW message;
        message.Format(L"%s\n%s", (LPCWSTR)FUN_141245b20()->FUN_141245ab0(CStringW()), (LPCWSTR)FUN_14028de60(0x8d5));
        NiMessageBox(FUN_14016a600(message, 0), FUN_14028dc80(0x8d4), 0);
        return efd::AsyncResult_Failure;
    }
    if (!CreateRendererSized(bFullscreenFlag, width, height)) {
        width = 0x400;
        height = 0x300;
        if (!CreateRendererSized(bFullscreenFlag, 0x400, 0x300)) {
            FUN_140d86260()->ShowCloseNotice(0x397, "");
            CStringW message;
            message.Format(L"%s\n%s", (LPCWSTR)FUN_141245b20()->FUN_141245ab0(CStringW()),
                           (LPCWSTR)FUN_14028de60(Unk_RsGetFailure() + 0x8d6));
            NiMessageBox(FUN_14016a600(message, 0), FUN_14028dc80(0x8d4), 0);
            return efd::AsyncResult_Failure;
        }
    }
    if (!FUN_1409a8b10()->FUN_1409a8ac0()->FUN_14125e820(width, height)) {
        width = 0x400;
        height = 0x300;
        if (!FUN_140aadf80()->FUN_141b91010(bFullscreenFlag, 0x400, 0x300)) {
            FUN_140d86260()->ShowCloseNotice(0x397, "");
            CStringW message;
            message.Format(L"%s\n%s", (LPCWSTR)FUN_141245b20()->FUN_141245ab0(CStringW()),
                           (LPCWSTR)FUN_14028de60(Unk_RsGetFailure() + 0x8d6));
            NiMessageBox(FUN_14016a600(message, 0), FUN_14028dc80(0x8d4), 0);
            return efd::AsyncResult_Failure;
        }
    }
    if (fullscreenMode != 0) {
        FUN_1409a8b10()->FUN_1409a8ac0()->m_nMode = 2;
        FUN_1409a8b10()->FUN_1409a8ac0()->FUN_14125eb00(width, height);
        FUN_1409a8b10()->FUN_1412432d0();
    }
    FUN_140aadf80();
    if (DAT_143af7d58 == 0) {
        ShowWindow(m_parentHandle, SW_SHOWNORMAL);
    }
    if (m_pDefaultSurfaceCreator != 0 && m_pDefaultSurfaceCreator->CreateDefaultSurface(this, m_defaultContextBackgroundColor)) {
        // the default surface creator made the contexts
    } else {
        int categoryTemp;
        unsigned int* puiCategory = (unsigned int*)FUN_140876480(&categoryTemp, 0);
        void* pContextMemory = FUN_14208a860(0xa0, *puiCategory);
        ecr::RenderContext* pContext;
        if (pContextMemory == 0) {
            pContext = 0;
        } else {
            pContext = new (pContextMemory) MS2RenderContext(this, 0);
        }
        AddRenderContext(pContext);
        pContext->SetBackgroundColor(m_defaultContextBackgroundColor);
        ecr::RenderSurfacePtr spSurface = CreateRenderSurface(0);
        pContext->AddRenderSurface(spSurface);
        SetActiveRenderSurface(spSurface);
    }
    MS2RenderContext* pRecordContext = dynamic_cast<MS2RenderContext*>(GetActiveRenderContext());
    if (pRecordContext != 0) {
        pRecordContext->CreateRecodeSurface();
        pRecordContext->ReleaseRecodeSurface();
    }
    return efd::AsyncResult_Complete;
}

// @0x1414ee2b0
efd::AsyncResult MS2RenderService::OnTick()
{
    efd::Float32 currTime = (efd::Float32)m_pServiceManager->GetTime(efd::kCLASSID_GameTimeClock);
    efd::UInt32 size = GetRenderContextCount();
    for (m_uiCurrentIndex = 0; m_uiCurrentIndex < size; ++m_uiCurrentIndex) {
        m_pCurrentContext = m_renderContexts[m_uiCurrentIndex];
        m_pCurrentContext->Draw(currTime);
    }
    m_pCurrentContext = 0;
    m_uiCurrentIndex = 0;
    return efd::AsyncResult_Pending;
}
MS2_REPLACE_METHOD(0x1414EE2B0, MS2RenderService, OnTick, 236, 0xD4075678);

// @0x1414ee3b0
efd::AsyncResult MS2RenderService::OnShutdown()
{
    if (m_pRendererDesc != 0) {
        delete m_pRendererDesc;
        m_pRendererDesc = 0;
    }
    NiRenderer* pRenderer = m_spRenderer;
    if (m_spRenderer) {
        NiRenderer* pSame = pRenderer;
        if (pSame != 0) {
            DAT_143d6eb38 = 0;
            DAT_143d6eb40 = 0;
        }
    }
    efd::AsyncResult result = ecr::RenderService::OnShutdown();
    if (m_spRenderer) {
        m_spRenderer->SetCallbackObject(0);
    }
    return result;
}
MS2_REPLACE_METHOD(0x1414EE3B0, MS2RenderService, OnShutdown, 259, 0xF5A7741E);

// @0x1414ee4c0
static void Unk_RsNoopHook(void* pUnused)
{
}

// @0x1414ee4d0
static void Unk_RsResetHook(Unk_RsRendererSize* pRenderer)
{
    Unk_RsWorldService* pWorld = FUN_1403ed2d0();
    if (pWorld != 0 && pRenderer != 0) {
        Unk_RsRendererSize* pSize = pRenderer;
        pWorld->FUN_141bd8660(pSize->GetWidth());
        pWorld->FUN_141bd8680(pSize->GetHeight());
    }
}

// @0x1414ee540
static void Unk_RsDriverErrorHook()
{
    if (!s_driverErrorShown) {
        FUN_140d86260()->ShowCloseNotice(0x398, "");
        s_driverErrorShown = true;
        CStringW message = StringFormat(L"D3DERR_DRIVERINTERNALERROR\n{0}", FUN_14028de60(0xb20));
        FUN_141b6fcf0(message, FUN_14028de60(0x8d4), 0);
        PostQuitMessage(0);
    }
}

// @0x1414ee630
static void Unk_RsDeviceLostHook(bool bDeviceOk)
{
    if (!bDeviceOk) {
        if (s_deviceOk) {
            _time64(&s_lastDeviceOkTime);
            s_deviceOk = false;
        } else {
            __time64_t now;
            _time64(&now);
            double elapsed = _difftime64(now, s_lastDeviceOkTime);
            if (elapsed >= 5.0 && !s_deviceLostNoticeShown) {
                s_deviceLostNoticeShown = true;
                CStringW message = FUN_14028de60(0xb1f);
                FUN_141b6fcf0(message, FUN_14028de60(0x8d4), 0);
                throw 0xd;
            }
        }
    } else {
        s_deviceOk = true;
    }
}

// @0x1414ee750
efd::SyncResult MS2PickService::OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar)
{
    ecr::PickService::OnPreInit(pDependencyRegistrar);
    if (m_pPicker != 0) {
        m_pPicker->SetPickObjectPolicy(m_spDefaultPickPolicy);
    }
    return efd::SyncResult_Success;
}
MS2_REPLACE_METHOD(0x1414EE750, MS2PickService, OnPreInit, 85, 0x1608DFF5);

// @0x1414ee7b0
efd::AsyncResult MS2PickService::OnInit()
{
    FUN_141bbae40(FUN_1403ed2d0(), this);
    return ecr::PickService::OnInit();
}
MS2_REPLACE_METHOD(0x1414EE7B0, MS2PickService, OnInit, 77, 0x1B2425B2);

// @0x1414ee810
void MS2PickService::vfunc_3(int)
{
    if (m_pPicker != 0) {
        m_pPicker->RemoveTarget();
        m_pPicker->ClearResultsArray();
    }
}
MS2_REPLACE_METHOD_VIA(0x1414EE810, MS2PickService, IWorldServiceCallback, vfunc_3, 58, 0x6B060310);

// Pushes the "fade" colour onto every scene object the collector reports for the root.
// @0x1414ee850
static void Unk_RsCollectFade(NiAVObject* pRoot)
{
    NiTPointerList<NiAVObject*> found;
    Unk_RsCollector* pCollector = Unk_RsGetCollector();
    if (pCollector != 0) {
        pCollector->Collect(pRoot, &found, 1);
    }
    NiTListIterator pos = found.GetHeadPos();
    while (pos != 0) {
        NiAVObject* pObject = found.GetNext(pos);
        Unk_RsFadeObject* pFade = FUN_14098d8d0(&DAT_143afbfb8, pObject);
        if (pFade != 0) {
            pFade->SetFadeValue(-FLT_MAX);
        }
        FUN_141d2c900(pObject, 1);
    }
}

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x1414f0480, Unk_RsGetFailure, 7, 0x398B5D1C);
MS2_REPLACE(0x1414f0750, Unk_RsSetFailure, 15, 0x716D61E1);
MS2_REPLACE(0x1414f07b0, Unk_RsSetHookA, 18, 0x708AB386);
MS2_REPLACE(0x1414f07d0, Unk_RsSetHookB, 18, 0xB60CAB9E);
MS2_REPLACE(0x1414f0ac0, Unk_RsGetShaderSource, 42, 0xDF4B6D0F);
MS2_REPLACE(0x1414f0540, Unk_RsGetCollector, 51, 0x5BAF357E);
MS2_REPLACE_METHOD(0x1414ea710, MS2RenderService, OnPreInit, 403, 0xD83C13D2);
MS2_REPLACE_METHOD(0x1414ea8b0, MS2RenderService, CheckRenderState, 8599, 0x757AA2B5);
MS2_REPLACE(0x1414ecec0, Unk_RsLockHook, 37, 0x4B389766);
MS2_REPLACE(0x1414ecef0, Unk_RsUnlockHook, 37, 0xC856A5B6);
MS2_REPLACE_METHOD(0x1414ecf80, MS2RenderService, CreateRendererSized, 1046, 0xA0872AB7);
MS2_REPLACE(0x1414ee4c0, Unk_RsNoopHook, 6, 0xA9AF6E37);
MS2_REPLACE(0x1414ee4d0, Unk_RsResetHook, 94, 0xBD38532B);
MS2_REPLACE(0x1414ee540, Unk_RsDriverErrorHook, 225, 0xE2470B7A);
MS2_REPLACE(0x1414ee850, Unk_RsCollectFade, 211, 0x6188DCA2);

