// gfxservice.h - PLACEHOLDER for GFxService and GFxSceneService (RTTI .?AVGFxService@@ 0x30 bytes, .?AVGFxSceneService@@
// 0x40 bytes). NOT an original header. Both are efd system services of the game's Scaleform integration (class ids
// 0x06202711 / 0x06202712); RTTI also lists an empty SingletonClass<T> base (@0x19) for each (GFxService still leaves it out).
// GFxService initialises Scaleform::GFx::System; MS2::RegisterServices gives it the locale's font name (+0x28).
// The integration code (0x1422b9000-0x1422eb000) has no unit yet; only the members ms2.cpp uses are declared.
#pragma once

#include <efd/ISystemService.h>
#include <efd/ReferenceCounting.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/singletonclass.h"

class UISceneEntity;

class GFxService : public efd::ISystemService
{
    EE_DECLARE_CLASS1(GFxService, 0x06202711, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    GFxService();                                                   // 0x1422e9a40
    virtual ~GFxService();
    virtual const char* GetDisplayName() const;
    virtual void vfunc_16();                                        // 0x1422e9c40
    virtual void vfunc_17();                                        // 0x1422e9c90
    virtual void vfunc_18();                                        // 0x1422e9d90
    virtual void vfunc_19(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);   // 0x1422e9df0 sees every message
    void FUN_1422ea230(CString strFont);                            // +0x28
    static int FUN_141b47780();                                     // s_nCaptureBlock (inline COMDAT, uiugcitemeditdialog.cpp)
    bool FUN_1422ea2a0();                                           // 0x1422ea2a0 (GFxMovieMouseCursor::vfunc_5: no cursor show/hide while set)
    static int s_nCaptureBlock;                                     // 0x143b0d360 screenshots blocked while set
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_1c[0x30 - 0x1c];
};
MS2_CHECK_SIZE(GFxService, 0x30);

GFxService* FUN_1414a56c0();                                        // the GFxService instance

// The scene service (0x40 bytes, vftable 0x143109b80, 16 slots): tracks the current UI scene and sub-scene (scene entity
// ids 0x062000xx) and switches them (hide the old one, show the new one). Code in ?\gfxsceneservice.cpp (src/ms2/gfxui/
// gfxsceneservice.cpp); ms_ClassInfo (0x143b0aa10) is initialized in unit_14013acc0's .text$di.
class GFxSceneService : public efd::ISystemService, public SingletonClass<GFxSceneService>
{
    EE_DECLARE_CLASS1(GFxSceneService, 0x06202712, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    GFxSceneService();                                              // 0x1422b9cd0
    // ~GFxSceneService() is implicit (COMDAT 0x1422ba470, scalar deleting 0x1422ba4a0)
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pDependencyRegistrar);   // 0x1422ba2f0
    virtual efd::AsyncResult OnInit();                              // 0x1422ba340
    virtual efd::AsyncResult OnTick();                              // 0x1422ba360
    virtual efd::AsyncResult OnShutdown();                          // 0x1422ba380
    virtual const char* GetDisplayName() const;                     // 0x1422b9d80

    int FUN_1422b9da0();                                            // 0x1422b9da0 the previous scene id
    int FUN_1422b9dc0();                                            // 0x1422b9dc0 the scene id
    int FUN_1422b9de0();                                            // 0x1422b9de0 the previous sub-scene id
    int FUN_1422b9e00();                                            // 0x1422b9e00 the sub-scene id
    UISceneEntity* FUN_1422b9e20(int nSceneId);                     // 0x1422b9e20 the scene entity of an id (UISwfEntityManager)
    UISceneEntity* FUN_1422b9e50();                                 // 0x1422b9e50 the sub-scene, else the scene
    UISceneEntity* FUN_1422b9e80();                                 // 0x1422b9e80 the scene
    int FUN_1422b9ea0();                                            // 0x1422b9ea0 the sub-scene is 0x6200041 or 0x620007f
    int FUN_1422b9ef0(int nSceneId);                                // 0x1422b9ef0 switch the scene (0 if already there)
    int FUN_1422b9fd0(int nSubSceneId);                             // 0x1422b9fd0 switch the sub-scene of the scene
    void FUN_1422ba0d0();                                           // 0x1422ba0d0..0x1422ba250: forward to the scene's
    void FUN_1422ba110();                                           //   UISceneEntity slots 52..58
    void FUN_1422ba150();
    void FUN_1422ba190();
    void FUN_1422ba1d0();
    void FUN_1422ba210();
    void FUN_1422ba250();
    void FUN_1422ba290(void* p, int a, int b);                      // 0x1422ba290 forward to slot 59

private:
    MS2_LAYOUT_FRIEND;
    int m_nPrevSceneId;                                             // +0x20
    int m_nSceneId;                                                 // +0x24
    int m_nPrevSubSceneId;                                          // +0x28
    int m_nSubSceneId;                                              // +0x2c
    UISceneEntity* m_pSubScene;                                     // +0x30
    UISceneEntity* m_pScene;                                        // +0x38
};
MS2_CHECK_SIZE(GFxSceneService, 0x40);

GFxSceneService* FUN_1408e57f0();                                   // the GFxSceneService instance
