// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiugccubepalettedialog.h (name assumed:
// the .cpp's __FILE__ string is in the exe, the header's is not).
//
// UIUGCCubePaletteDialog ("UGCCubePaletteDialog", UI type 0x4f16): the cube palette of the UGC (home / map) editor. It
// lists the cubes of the UGCCubePalette singleton filtered by cube type / main + sub category / sort / owned / usable /
// search text, previews a cube (item tooltip), buys the missing cubes, and hands the picked cube to the key controller.
// The key controller (UGCKeyController, 0x18 bytes, no virtual destructor) forwards the mouse events of the editor view
// to the current key mode (UGCKeyMode: 1 = place / pick cubes with a ray cast, 2 = a variant). RTTI
// .?AVUIUGCCubePaletteDialog@@, 0x238 bytes, vftables UIDialog / +0x18 (IMessageListener) / +0x178 (UIItemEventListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset>.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/timer.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ugccubepalette.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uiitemeventlistener.h"

class ASData;
class ASObj;
class CMsgBoxData;

// ---- key modes ----

class UGCKeyMode : public CPtred
{
public:
    UGCKeyMode();                                           // 0x140ef1bc0
    virtual ~UGCKeyMode();                                  //  0 0x140ef4c20 (??_G 0x140ef4d90)
    virtual void vfunc_1();                                 //  1 0x140ef1c00 (leave the mode: FUN_141adbdc0(ui, 1))
    virtual void vfunc_2(void*, float, float) {}                               //  2 0x140ef4e30
    virtual void vfunc_3(void*, float, float) {}                               //  3 0x140ef4e10
    virtual void vfunc_4(void*, float, float) {}                               //  4 0x140ef4df0
    virtual void vfunc_5(void*, float, float) {}                               //  5 0x140ef4e70
    virtual void vfunc_6(void*, float, float) {}                               //  6 0x140ef4e50
    virtual void vfunc_7(void*, float, float, float) {}     //  7 0x140ef4e90
};
MS2_CHECK_SIZE(UGCKeyMode, 0x18);

class UGCKeyMode1 : public UGCKeyMode
{
public:
    UGCKeyMode1();                                          // 0x140ef1c30
    virtual ~UGCKeyMode1();                                 //  0 0x140ef4be0 (??_G 0x140ef4d10)
    virtual void vfunc_1();                                 //  1 0x140ef1c70 ray cast: preview the picked cube
    virtual void vfunc_5(void*, float, float);              //  5 0x140ef21c0 place / remove
    virtual void vfunc_7(void*, float, float, float f);     //  7 0x140ef22d0 wheel: next / previous cube
};
MS2_CHECK_SIZE(UGCKeyMode1, 0x18);

class UGCKeyMode2 : public UGCKeyMode
{
public:
    UGCKeyMode2();                                          // 0x140ef2330
    virtual ~UGCKeyMode2();                                 //  0 0x140ef4c00 (??_G 0x140ef4d50)
    virtual void vfunc_1();                                 //  1 0x140ef2370
    virtual void vfunc_5(void*, float, float);              //  5 0x140ef2810
};
MS2_CHECK_SIZE(UGCKeyMode2, 0x18);

// The editor's input forwarder: owns the current key mode and passes the mouse events through (slot 0 = the per-frame
// update). No virtual destructor (0x140ef04e0 is the plain destructor).
class UGCKeyController
{
public:
    UGCKeyController();                                     // 0x140ef2920 (starts in UGCKeyMode1)
    ~UGCKeyController();                                    // 0x140ef04e0
    virtual void vfunc_0();                                 //  0 0x140ef29c0 mode->vfunc_1()
    virtual void vfunc_1(void* p, float x, float y);        //  1 0x140ef2ba0
    virtual void vfunc_2(void* p, float x, float y);        //  2 0x140ef2c30
    virtual void vfunc_3(void* p, float x, float y);        //  3 0x140ef2ce0
    virtual void vfunc_4(void* p, float x, float y);        //  4 0x140ef2d90
    virtual void vfunc_5(void* p, float x, float y);        //  5 0x140ef2e40
    virtual void vfunc_6(void* p, float x, float y, float f);   //  6 0x140ef2ef0
    bool FUN_140ef4970();                                   // 0x140ef4970 in a UGC edit session

    MS2Ptr<UGCKeyMode> m_mode;                              // +0x08 (pointer at +0x10)
};
MS2_CHECK_SIZE(UGCKeyController, 0x18);

// ---- dialog helpers ----

// The cube the list should focus on after a refresh (0x140ee9c90 ctor).
struct Unk_CubeFocus
{
    Unk_CubeFocus();                                        // 0x140ee9c90
    bool IsActive();                                   // active
    void FUN_140ee9cf0(int nIndex, int nCubeId);            // activate (index clamped at 0)
    void FUN_140ee9d50();                                   // clear
    int FUN_140ee9d70();                                    // list index of the cube (or the stored index)
    bool m_bActive;
    int m_nIndex;
    int m_nCubeId;
};
MS2_CHECK_SIZE(Unk_CubeFocus, 0xc);

// A one-shot timer with a payload (the page to scroll to when it expires). A Timer member followed by an int, not a
// derived class (the ctor 0x140ee9e40 sets no vftable of its own).
struct Unk_CubeTimer
{
    Unk_CubeTimer();                                        // 0x140ee9e40
    ~Unk_CubeTimer();                                       // 0x140ef04c0
    bool FUN_140ee9e80();                                   // expired
    void FUN_140ee9eb0(int n);                              // arm (200 ms), remember max(n, 0)
    void FUN_140ee9f00();                                   // reset
    int GetValue();                                    // the remembered value
    Timer m_timer;                                          // +0x00
    int m_nValue;                                           // +0x38
};
MS2_CHECK_SIZE(Unk_CubeTimer, 0x40);

class UIUGCCubePaletteDialog : public UIDialog, public UIItemEventListener
{
public:
    UIUGCCubePaletteDialog();                                                                       // 0x140ee9f50
    virtual ~UIUGCCubePaletteDialog();                                                              //  0 0x140eea200 (??_G 0x140ef0770)
    virtual CString vfunc_1();                                                                      //  1 0x140eea300
    virtual int vfunc_13();                                                                         // 13 0x140eea8a0 key input
    virtual void vfunc_15();                                                                        // 15 0x140eea7c0 per-frame
    virtual void OnLoadComplete();                                                                  // 22 0x140eea620
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                    // 28 0x140eeb860
    virtual void vfunc_32(void* p, float x, float y);                                               // 32 0x140eeaf40
    virtual void vfunc_33(void* p, float x, float y);                                               // 33 0x140eeafa0
    virtual void vfunc_35(void* p, float x, float y);                                               // 35 0x140eeb000
    virtual void vfunc_36(void* p, float x, float y);                                               // 36 0x140eeb060
    virtual void vfunc_38(void* p, float x, float y);                                               // 38 0x140eeaee0
    virtual void vfunc_39(void* p, float x, float y, float f);                                      // 39 0x140eeb0c0
    virtual void vfunc_43();                                                                        // 43 0x140eea720
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs); // 45 0x140eeb500
    virtual int vfunc_48() { return 0x4f16; }                                                       // 48 (0x140ef0be0, COMDAT)
    virtual int vfunc_53(void* pCfg);                                                               // 53 0x140eea350
    virtual int vfunc_54(void* pCfg);                                                               // 54 0x140eea420
    virtual void vfunc_67();                                                                        // 67 0x140eea550

    // UIItemEventListener (+0x178) overrides: 1, 14, 15, 16
    virtual int vfunc_il1();                                                                        // 0x140eea4b0
    virtual void vfunc_14(void* pItem);                                                             // 0x140eeb130
    virtual void vfunc_15(void*);                                                                   // 0x140eeb480
    virtual void vfunc_16(void*);                                                                   // 0x140eeb4c0

    // non-virtual members (this = UIUGCCubePaletteDialog*)
    void FUN_140eec0b0(unsigned __int64 uid);
    bool FUN_140eec330(int nBtn, const CMsgBoxData& data);
    bool FUN_140eec410(int nBtn, const CMsgBoxData& data);
    void FUN_140eec480();
    int FUN_140eec4d0(int nTypeId, Unk_StreamPoint* pPos);
    void FUN_140eeca50();
    void FUN_140eecfe0();
    void FUN_140eed2d0();
    void FUN_140eed620(int n);
    void FUN_140eede00(int nCubeType);
    void FUN_140eee160(int nCubeType, unsigned int nMainCategory);
    int FUN_140eee630();
    void FUN_140eeea80(int n);
    void OnDestroyCubeItem();
    void FUN_140eef510(const CStringW& str);
    void FUN_140eef560(int n);
    void FUN_140eef670(int n);
    void FUN_140eef7e0(int nCubeIndex);
    void FUN_140eefc50(int nState);
    void FUN_140eefdd0(int nIndex);
    void FUN_140eefe00();

    Unk_CubeFocus m_focus;                                  // +0x180
    Unk_CubeTimer m_timer;                                  // +0x190
    UGCKeyController m_keys;                                // +0x1d0
    Unk_CubePaletteFilter m_filter;                         // +0x1e8 (+0x1ec cube type, +0x1f8 sub category)
    ATL::CRBMap<int, int> m_map;                            // +0x208 UI event id (2..11) -> row (1..10)
};
MS2_CHECK_SIZE(UIUGCCubePaletteDialog, 0x238);
