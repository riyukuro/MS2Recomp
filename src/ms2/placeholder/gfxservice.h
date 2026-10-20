// gfxservice.h - PLACEHOLDER for GFxService and GFxSceneService (RTTI .?AVGFxService@@ 0x30 bytes, .?AVGFxSceneService@@
// 0x40 bytes). NOT an original header. Both are efd system services of the game's Scaleform integration (class ids
// 0x06202711 / 0x06202712); RTTI also lists an empty SingletonClass<T> base for each (not recovered, left out).
// GFxService initialises Scaleform::GFx::System; MS2::RegisterServices gives it the locale's font name (+0x28).
// The integration code (0x1422b9000-0x1422eb000) has no unit yet; only the members ms2.cpp uses are declared.
#pragma once

#include <efd/ISystemService.h>
#include <efd/ReferenceCounting.h>

#include "ms2/ms2layout.h"

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
    static int s_nCaptureBlock;                                     // 0x143b0d360 screenshots blocked while set
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_1c[0x30 - 0x1c];
};
MS2_CHECK_SIZE(GFxService, 0x30);

GFxService* FUN_1414a56c0();                                        // the GFxService instance

class GFxSceneService : public efd::ISystemService
{
    EE_DECLARE_CLASS1(GFxSceneService, 0x06202712, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    GFxSceneService();                                              // 0x1422b9cd0
    virtual ~GFxSceneService();
    virtual const char* GetDisplayName() const;
private:
    MS2_LAYOUT_FRIEND;
    char m_pad_1c[0x40 - 0x1c];
};
MS2_CHECK_SIZE(GFxSceneService, 0x40);
