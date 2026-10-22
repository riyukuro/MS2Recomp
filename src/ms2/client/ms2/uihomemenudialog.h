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

// The screenshot uploader (CImageHttpClient of commonfiles\imagehttpclient.cpp, 0x78 bytes, vftable at +0): the dialog
// embeds one and asks it for the upload address. Stand-in: only the members this dialog calls.
class Unk_HmImageHttp
{
public:
    Unk_HmImageHttp();                                                     // 0x140511030
    ~Unk_HmImageHttp();                                                    // 0x1405110d0 (non-virtual call)
    void FUN_140511190(int n);                                             // m_20 = n
    bool FUN_1405116c0();                                                  // true when the uploader is ready

private:
    void* m_vftable;                                                       // +0x00
    char m_pad[0x70];
};
MS2_CHECK_SIZE(Unk_HmImageHttp, 0x78);

class UIHomeMenuDialog : public UIDialog
{
public:
    UIHomeMenuDialog();                                                    // 0x140c29160
    virtual ~UIHomeMenuDialog();                                           //  0 0x140c29230 (??_G 0x140c2b850)
    virtual CString vfunc_1();                                             //  1 0x140c29280
    virtual void OnLoadComplete();                                         // 22 0x140c29300
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x140c29340
    virtual int vfunc_48();                                                // 48 0x140c2b8e0
    virtual void vfunc_67();                                               // 67 0x140c292d0

    void FUN_140c29600(bool bCraft);                                       // refresh the movie ("setState", buttons, camera)
    void FUN_140c296e0(bool bCraft);                                       // same
    void FUN_140c29710();                                                  // "ToggleDesignMode"
    void FUN_140c29980();                                                  // "ToggleBlueprintMode"
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
    CString FUN_140c2ad90();                                               // the state frame name of the movie
    bool FUN_140c2af70();                                                  // the local player is in craft mode
    void FUN_140c2afd0(bool bFreeCamera);                                  // switch the free camera
    CStringW FUN_140c2b080();                                              // the screenshot upload address (empty: none)
    bool FUN_140c2b0e0(int nResult, const CMsgBoxData& data);              // "save design" box result
    bool FUN_140c2b130(int nResult, const CMsgBoxData& data);              // "save blueprint" box result
    bool FUN_140c2b180(int nResult, const CMsgBoxData& data);              // screenshot upload box result
    bool FUN_140c2b390(int nResult, const CMsgBoxData& data);              // "leave design" box result
    bool SendRequestCube(int nResult, const CMsgBoxData& data);              // "demolish" box result

private:
    MS2_LAYOUT_FRIEND;
    bool m_bFreeCamera;                                                    // +0x178 (the 8 bytes up to +0x180 are padding)
    Unk_HmImageHttp m_screenshot;                                          // +0x180
};
MS2_CHECK_SIZE(UIHomeMenuDialog, 0x1f8);
MS2_CHECK_OFFSET(UIHomeMenuDialog, m_bFreeCamera, 0x178);
MS2_CHECK_OFFSET(UIHomeMenuDialog, m_screenshot, 0x180);
