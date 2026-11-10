// Recovered UIHomeMenuDialog (the menu bar of the home / cube designer, UI type 0x4f7c, RTTI .?AVUIHomeMenuDialog@@,
// 0x1f8 bytes); names of fields and local helpers are inferred. Original header name assumed: the .cpp's __FILE__ string
// is in the exe, the header's is not.
// The menu has the buttons "ToggleCraftMode" (craft), "ToggleDesignMode" (design), "ToggleBlueprintMode", "OnScreenshot",
// "OnFreeCamera", "OnDesignSave/Load", "OnBlueprintSave/Import/Export/Shop", "OnHomePriority/Attribute/Demolish". The
// state shown by the movie ("setState") comes from the cube service (class id 0x06100017) and the local player.
#pragma once
#include "ms2/ms2layout.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"

class CMsgBoxData;

#include "ms2/commonfiles/imagehttpclient.h"

class UIHomeMenuDialog : public UIDialog
{
public:
    UIHomeMenuDialog();                                                    // 0x140c29160
    virtual ~UIHomeMenuDialog();                                           //  0 0x140c29230 (??_G 0x140c2b850)
    virtual CString GetTypeName();                                             //  1 0x140c29280
    virtual void OnLoadComplete();                                         // 22 0x140c29300
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c29340
    virtual int vfunc_48();                                                // 48 0x140c2b8e0
    virtual void vfunc_67();                                               // 67 0x140c292d0

    void Refresh(bool bCraft);                                       // refresh the movie ("setState", buttons, camera)
    void FUN_140c296e0(bool bCraft);                                       // same
    void ToggleDesignMode();                                                  // "ToggleDesignMode"
    void ToggleBlueprintMode();                                                  // "ToggleBlueprintMode"
    void FUN_140c29b70();                                                  // "OnHomePriority" (again)
    void ToggleCraftMode();                                                  // "ToggleCraftMode"
    void OnScreenshot();                                                  // "OnScreenshot"
    void OnFreeCamera();                                                  // "OnFreeCamera"
    void OnDesignSave();                                                  // "OnDesignSave"
    void OnDesignLoad();                                                  // "OnDesignLoad"
    void OnBlueprintSave();                                                  // "OnBlueprintSave"
    void OnBlueprintImport();                                                  // "OnBlueprintImport"
    void OnHomePriority();                                                  // "OnHomePriority"
    void OnHomeAttribute();                                                  // "OnHomeAttribute"
    void OnHomeDemolish();                                                  // "OnHomeDemolish"
    void OnBlueprintExport();                                                  // "OnBlueprintExport"
    void OnBlueprintShop();                                                  // "OnBlueprintShop"
    void FUN_140c2a780();                                                  // enable / check the buttons of the movie
    CString GetStateFrameName();                                               // the state frame name of the movie
    bool IsCraftMode();                                                  // the local player is in craft mode
    void SetFreeCamera(bool bFreeCamera);                                  // switch the free camera
    CStringW TakeScreenshot();                                              // the screenshot upload address (empty: none)
    bool FUN_140c2b0e0(int nResult, const CMsgBoxData& data);              // "save design" box result
    bool FUN_140c2b130(int nResult, const CMsgBoxData& data);              // "save blueprint" box result
    bool FUN_140c2b180(int nResult, const CMsgBoxData& data);              // screenshot upload box result
    bool OnLeaveDesignResult(int nResult, const CMsgBoxData& data);              // "leave design" box result
    bool SendRequestCube(int nResult, const CMsgBoxData& data);              // "demolish" box result

private:
    MS2_LAYOUT_FRIEND;
    bool m_bFreeCamera;                                                    // +0x178 (the 8 bytes up to +0x180 are padding)
    CImageHttpClient m_screenshot;                                          // +0x180
};
MS2_CHECK_SIZE(UIHomeMenuDialog, 0x1f8);
MS2_CHECK_OFFSET(UIHomeMenuDialog, m_bFreeCamera, 0x178);
MS2_CHECK_OFFSET(UIHomeMenuDialog, m_screenshot, 0x180);
