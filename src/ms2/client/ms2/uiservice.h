// uiservice.h - CUIService (RTTI name, efd system service class id 0x06100004, display name "CUIService"): the client's
// UI manager. It owns the table of the open/registered dialogs (class id -> dialog, +0x88), the per-dialog help /
// button state ("hot key" tables), the Scaleform movie background / damage overlay helpers and the per-scene
// "which dialogs are open" bookkeeping (+0x138 / +0x180 map a scene id to a 0/1 flag; +0x1c8 / +0x1f8 are the lists
// of the dialogs a scene opens / closes). The big registration function FUN_141adf580 creates every dialog.
// Member and helper names are invented from their use.
// Owning unit: ?\uiservice.cpp (.text$di 0x14011d200-0x14011d540, .text$mn 0x141ad8bc0-0x141af2110).
#pragma once
#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>
#include <efd/ISystemService.h>
#include <efd/SmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/ascript.h"

#include <NiSmartPointer.h>
class NiDebugVisualizationClick;
class NiAVObject;
class GFxMovieBackground;
class UIDialog;
class CGemBase;
class UIObject;
// UI dialog class id (the type name is from the OpenDialog log text; enumerator names are not recovered)
enum eUIClassID
{
    eUI_3ed = 0x3ed,
    eUI_3ee = 0x3ee,
    eUI_3ef = 0x3ef,
    eUI_2711 = 0x2711,
    eUI_4e2d = 0x4e2d,
    eUI_4e3e = 0x4e3e,
    eUI_4e42 = 0x4e42,
    eUI_4e49 = 0x4e49,
    eUI_4e4a = 0x4e4a,
    eUI_4e4d = 0x4e4d,
    eUI_4e56 = 0x4e56,
    eUI_4e68 = 0x4e68,
    eUI_4e69 = 0x4e69,
    eUI_4e6d = 0x4e6d,
    eUI_4e6e = 0x4e6e,
    eUI_4e70 = 0x4e70,
    eUI_4e73 = 0x4e73,
    eUI_4e77 = 0x4e77,
    eUI_4e78 = 0x4e78,
    eUI_4e7c = 0x4e7c,
    eUI_4e92 = 0x4e92,
    eUI_4e93 = 0x4e93,
    eUI_4e97 = 0x4e97,
    eUI_4e98 = 0x4e98,
    eUI_4e9d = 0x4e9d,
    eUI_4ec0 = 0x4ec0,
    eUI_4ec1 = 0x4ec1,
    eUI_4ec3 = 0x4ec3,
    eUI_4eeb = 0x4eeb,
    eUI_4ef1 = 0x4ef1,
    eUI_4ef2 = 0x4ef2,
    eUI_4ef3 = 0x4ef3,
    eUI_4f14 = 0x4f14,
    eUI_4f2d = 0x4f2d,
    eUI_4f33 = 0x4f33,
    eUI_4f34 = 0x4f34,
    eUI_4f38 = 0x4f38,
    eUI_4f3e = 0x4f3e,
    eUI_4f42 = 0x4f42,
    eUI_4f5b = 0x4f5b,
    eUI_4f6d = 0x4f6d,
    eUI_4f76 = 0x4f76,
    eUI_4f7b = 0x4f7b,
    eUI_4f8d = 0x4f8d,
    eUI_4f8e = 0x4f8e,
    eUI_4f94 = 0x4f94,
    eUI_4f97 = 0x4f97
};

// Opaque exe containers owned by this unit (CAtlMap-shaped, 0x48 bytes; their bodies are unit glue).
struct Unk_UisMap
{
    char m_pad[0x48];
};
MS2_CHECK_SIZE(Unk_UisMap, 0x48);

struct Unk_UisPtr8
{
    char m_pad[8];
};
typedef ATL::CAtlList<eUIClassID> Unk_UisList;                // class ids still to open / close, handed out three per tick
MS2_CHECK_SIZE(Unk_UisList, 0x30);

// Scaleform log sink member (class of an unrecovered unit).
struct Unk_UisLogger
{
    char m_pad[0x10];
};

template <class T> class TSingleton;
class CUIService;
template <> class TSingleton<CUIService>
{
public:
    TSingleton();                                   // inline
    virtual ~TSingleton() { s_instance = 0; }       // 0x141aef230
    static CUIService* GetInstance() { return s_instance; }         // 0x1403ed2b0 (COMDAT of gameevent.cpp)
    static CUIService* s_instance;
};

class CUIService : public efd::ISystemService, public TSingleton<CUIService>
{
    EE_DECLARE_CLASS1(CUIService, 0x06100004, efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CUIService();                                   // 0x141ad8bc0
    virtual ~CUIService();                          // 0x141ad91c0
    virtual const char* GetDisplayName() const;     // 0x141ad9330
    virtual efd::SyncResult OnPreInit(efd::IDependencyRegistrar* pRegistrar);   // 0x141adea90
    virtual efd::AsyncResult OnInit();              // 0x141adeb70
    virtual efd::AsyncResult OnTick();              // 0x141adecf0
    virtual efd::AsyncResult OnShutdown();          // 0x141adeff0

    // ---- scene flags and the dialogs a scene opens ----
    void FUN_141ad9e50(int nScene);                 // 0x141ad9e50 enter a scene: set the flag, open its dialogs
    void FUN_141ada610(int nScene);                 // 0x141ada610 leave a scene: clear the flag
    void FUN_141ada6f0(int nScene);                 // 0x141ada6f0
    void FUN_141adad20(int nScene);                 // 0x141adad20
    void FUN_141add1f0();                           // 0x141add1f0
    void FUN_141add210();                           // 0x141add210 "not enough merat" confirm box
    void FUN_141add390();                           // 0x141add390 "not enough meso market token" confirm box
    void FUN_141add520(CStringW strText, CStringW strArg);   // 0x141add520 market confirm box with one argument
    void FUN_141aec8f0(char bOn, NiAVObject* pRoot);   // 0x141aec8f0 debug visualization click on / off
    void FUN_141aebed0();                           // 0x141aebed0 register the camera dialog and the callbacks
    static int FUN_141aed0a0(MS2Ptr<UIDialog> spDlg);   // 0x141aed0a0 log one dialog
    void FUN_141aecd70();                           // 0x141aecd70 close-request every dialog that is open
    void FUN_141aecc30();                           // 0x141aecc30 rebuilds the scene UI (field enter)
    void FUN_141adafd0(int nScene);                 // 0x141adafd0 hide the world UI for a scene change
    void FUN_141adb2a0(int nScene);                 // 0x141adb2a0 show it again (argument unused)
    void FUN_141adbbb0();                           // 0x141adbbb0
    bool FUN_141adcd40();                           // 0x141adcd40 close the dialogs that can be closed
    bool FUN_141aec1f0(MS2Ptr<UIDialog> spDlg);     // 0x141aec1f0 dialog may be closed in bulk
    void FUN_141adb4c0(int bOn);                    // 0x141adb4c0 enable / disable every hot key slot
    void FUN_141adb7b0(int bOn);                    // 0x141adb7b0
    void FUN_141adbb40();                           // 0x141adbb40 step the cursor mode 0..3
    void FUN_141adbd60(int n);                      // 0x141adbd60
    int FUN_141adbd80();                           // 0x141adbd80
    void FUN_141adbdc0(int n);                      // 0x141adbdc0
    unsigned FUN_141adbd10();                       // 0x141adbd10
    void FUN_141adbea0();                           // 0x141adbea0
    void FUN_141adbf00();                           // 0x141adbf00
    int FUN_141adcb40();                            // 0x141adcb40
    void FUN_141adcb60(int n);                      // 0x141adcb60
    void FUN_141add1b0(int nSlot, bool bOn);        // 0x141add1b0 enable one hot key slot
    void OpenDialog(eUIClassID nClass);          // 0x141adc530 open a dialog
    void FUN_141add040(eUIClassID nClass);          // 0x141add040 close a dialog
    void FUN_141aec3e0();                           // 0x141aec3e0 reset the saved UI layout
    void FUN_141aec690();                           // 0x141aec690
    void FUN_141aec760(float fDelta);               // 0x141aec760
    void FUN_141aec9c0();                           // 0x141aec9c0
    void FUN_141aece70();                           // 0x141aece70 reset the input handlers
    void FUN_141adf250();                           // 0x141adf250 create the click render steps
    void FUN_141adf580();                           // 0x141adf580 create every dialog
    static void FUN_141ade300(CString strName, void* pUnused, void* pArg1, void* pArg2);   // 0x141ade300
    static bool FUN_141ade1f0(bool bFlag, void* p); // 0x141ade1f0
    static bool FUN_141ade2d0(void* pContext);                  // 0x141ade2d0
    static void FUN_141ade400();                    // 0x141ade400
    static int FUN_141aecf60(MS2Ptr<UIDialog> spDlg);   // 0x141aecf60
    static int FUN_141aed000(MS2Ptr<UIDialog> spDlg);   // 0x141aed000
    int FUN_141adcbb0(int (*pfn)(MS2Ptr<UIDialog>));   // 0x141adcbb0

    // ---- generated member decls ----
    void FUN_141adc050();                                                   // 0x141adc050 close the closable dialogs
    void FUN_141aec8c0(int nMode);                                          // 0x141aec8c0
    void FUN_141ad9350();                                              // 0x141ad9350
    void FUN_141ad93b0();                                              // 0x141ad93b0 check / rewrite version.xml
    void FUN_141ad9650();                                              // 0x141ad9650 field background movie
    void FUN_141ad9980(char nStage);                                   // 0x141ad9980
    void FUN_141ad9a60(CStringA strBg);                                // 0x141ad9a60
    void FUN_141ad9b30();                                              // 0x141ad9b30
    bool FUN_141ad9b60();                                              // 0x141ad9b60
    void FUN_141ad9c10();                                              // 0x141ad9c10
    void FUN_141ad9c40(MS2Ptr<CGemBase> spGem);                        // 0x141ad9c40 damage overlay: gem effect on
    void FUN_141ad9d00(MS2Ptr<CGemBase> spGem);                        // 0x141ad9d00 damage overlay: gem effect off
    void FUN_141ad9dc0();                                              // 0x141ad9dc0
    bool FUN_141ad9e20(HWND__* hWnd);                                  // 0x141ad9e20 window-proc style callback (argument unused)
    void FUN_141adbca0(int n);                                         // 0x141adbca0
    void FUN_141adbcd0(char b);                                        // 0x141adbcd0
    int FUN_141adbe00(float fValue, int bRaw);                           // 0x141adbe00
    void FUN_141adbe70();                                              // 0x141adbe70
    void FUN_141adbf30();                                              // 0x141adbf30
    void FUN_141adbf70(int n);                                         // 0x141adbf70
    void FUN_141aebfa0(MS2Ptr<UIObject> spObj);                        // 0x141aebfa0 register an object (class id / name tables)
    void FUN_141aec080(MS2Ptr<UIDialog> spDlg);                        // 0x141aec080 register a dialog
    void FUN_141adb810();                                              // 0x141adb810
    void FUN_141adb880();                                              // 0x141adb880
    void FUN_141adb900(int n);                                         // 0x141adb900
    void FUN_141adb9c0(const CStringW& str, int a, int b);             // 0x141adb9c0
    void FUN_141adba40();                                              // 0x141adba40
    int FUN_141adbb00();                                               // 0x141adbb00
    void FUN_141adbfb0(void* p);                                       // 0x141adbfb0 vfunc_79 on every floating dialog
    void FUN_141add6e0(int nMode);                                     // 0x141add6e0 set the mode (deferred while m_b120)
    int FUN_141add730();                                               // 0x141add730
    bool FUN_141add880(int nResult, const class CMsgBoxData& box);     // 0x141add880
    bool FUN_141add940(int nResult, const class CMsgBoxData& box);     // 0x141add940
    bool FUN_141add9b0(int nResult, const class CMsgBoxData& box);     // 0x141add9b0
    int FUN_141adf0f0(int nMsg, void* wParam, void* lParam);           // 0x141adf0f0 offer a window message to the dialogs
    int FUN_141add860();                                               // 0x141add860 m_nMode
    int FUN_141aec350();                                               // 0x141aec350 current field's name id
    void FUN_141adc170();                                              // 0x141adc170
    void FUN_141adc190();                                              // 0x141adc190
    void FUN_141adc2c0();                                              // 0x141adc2c0
    void FUN_141adc3d0();                                              // 0x141adc3d0
    void FUN_141adc400();                                              // 0x141adc400
    void FUN_141adc5d0(eUIClassID nClass);                                    // 0x141adc5d0 close a dialog (if open)
    void FUN_141adc690(eUIClassID nClass);                                    // 0x141adc690 close-request a dialog (if open)
    void ToggleDialog(eUIClassID nClass);                                    // 0x141adc750 toggle a dialog
    int FUN_141adc7f0(eUIClassID nClass);                              // 0x141adc7f0 dialog vfunc_73 (can open)
    int FUN_141adc890(eUIClassID nClass);                              // 0x141adc890 dialog open
    int FUN_141adc940(eUIClassID nClass);                              // 0x141adc940 dialog vfunc_55 (closed)
    int FUN_141adc9e0(eUIClassID nClass);                              // 0x141adc9e0
    void FUN_141adca70();                                              // 0x141adca70 TooltipManager.dispatchRefreshTooltip
    MS2Ptr<UIDialog> FUN_141aec130(eUIClassID nClass);                 // 0x141aec130 dialog by class id
    MS2Ptr<UIObject> FUN_141adcea0(eUIClassID nClass);                 // 0x141adcea0 object by class id
    MS2Ptr<UIObject> FUN_141adcf50(const CStringA& strName);           // 0x141adcf50 object by name
    void FUN_141add0b0(eUIClassID nClass);                             // 0x141add0b0
    void FUN_141add120(eUIClassID nClass, int n);                      // 0x141add120
    // @@

    void* m_pEntitySvc28;                           // +0x28 (OnInit: FUN_14168ab40(service manager))
    void* m_pWorldSvc30;                            // +0x30 (OnInit: FUN_1411d15b0(service manager))
    Unk_UisPtr8 m_x38;                              // +0x38 ctor 0x1416ae2a0, dtor 0x1416aecf0
    ATL::CAtlMap<eUIClassID, MS2Ptr<UIObject> > m_mapA;                                       // +0x40 ctor 0x141aed9e0, clear 0x141af0f00, dtor 0x141aee190
    ATL::CAtlMap<eUIClassID, MS2Ptr<UIDialog> > m_mapDlg;                            // +0x88 class id -> dialog, ctor 0x141aed8f0, clear 0x141af0df0
    ATL::CAtlMap<CStringA, MS2Ptr<UIObject>, ATL::CStringElementTraitsI<CStringA> > m_mapC;                              // +0xd0 name -> dialog, ctor 0x141aed800, clear 0x141af0ce0
    int m_nMode;                                    // +0x118 initial 0x3ed
    int m_n11c;                                     // +0x11c
    bool m_b120;                                    // +0x120
    char m_pad_121[3];
    int m_n124;                                     // +0x124
    int m_n128;                                     // +0x128
    int m_n12c;                                     // +0x12c
    int m_n130;                                     // +0x130
    int m_nCursor;                                  // +0x134 0..3
    Unk_UisMap m_mapOpen;                           // +0x138 scene id -> 0/1 (CAtlMap<int,int>; ctor 0x140163400)
    Unk_UisMap m_mapOpen2;                          // +0x180
    Unk_UisList m_listOpen;                         // +0x1c8 CAtlList<int>, ctor 0x141926ff0
    Unk_UisList m_listClose;                        // +0x1f8
    Unk_UisLogger m_log;                            // +0x228 GFxLogger
    CStringA m_strTable;                            // +0x238
    CCacheData m_cache;                             // +0x240
    NiPointer<NiDebugVisualizationClick> m_spDebugClick;   // +0x268 NiPointer glue 0x141aedd80 / 0x141aee240 / 0x141aee3b0
};
