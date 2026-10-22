// ms2inputservice.h - MS2InputService (vftable 0x142e32c70, TSingleton<MS2InputService> sub-vftable 0x142e32cf8 at +0xe8):
// the game's ecrInput::InputService with game key ids (keyboard / mouse / gamepad all folded into one id space),
// gamepad discovery (XInput first, then DirectInput) and rumble timing. Header name assumed.
//
// Key id space (as used by the FUN_* queries below): 1..0x91 keyboard (NiInputKeyboard::KeyCode), 0xc8.. mouse
// buttons (id - 200), 0x92..0xa1 gamepad buttons, 0xa3..0xb2 gamepad stick directions.
#pragma once
#include "ms2/placeholder/ms2stdafx.h"
#include <ecrInput/InputService.h>
#include <NiInputSystem.h>
#include <NiInputKeyboard.h>
#include <NiInputMouse.h>
#include <NiInputGamePad.h>
#include <NiDI8Headers.h>
#include <NiInputXInputGamePad.h>
#include <NiInputDI8GamePad.h>
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/nipoint3.h"

class MS2InputService;
class CMsgBoxData;

// formatted with the custom-arg path of the exe's fmt (enum), hence a real enum
enum Unk_PadKind { PADKIND_NONE = 0, PADKIND_XINPUT = 1, PADKIND_DUAL = 2, PADKIND_STEAM = 3 };

template <class T> class TSingleton;
template <> class TSingleton<MS2InputService>
{
public:
    TSingleton();                                       // 0x140d8e560 (inline, below)
    virtual ~TSingleton() { s_instance = 0; }           // 0x140d8e6c0
    static MS2InputService* s_instance;                 // 0x143ab7800
};

class MS2InputService : public ecrInput::InputService, public TSingleton<MS2InputService>
{
public:
    MS2InputService();                                  // 0x140d8a570
    virtual ~MS2InputService();                         // 0x140d8a6c0
    virtual efd::AsyncResult OnInit();                  // 0x140d8a780
    virtual efd::AsyncResult OnTick();                  // 0x140d8a880
    virtual efd::AsyncResult OnShutdown();              // 0x140d8aba0

    bool FUN_140d8ac50(int nKey, int bAllowGroup);      // key is held (group-aware)
    bool FUN_140d8ad60(int nKey);                       // key was pressed this frame (group-aware, tracks the held modifier)
    bool FUN_140d8af70(int nKey);                       // key was released this frame (group-aware)
    bool FUN_140d8b010(int nButton);                    // mouse button is held
    bool FUN_140d8b070(int nButton);                    // mouse button was pressed
    bool FUN_140d8b0d0(int nButton);                    // mouse button was released
    bool FUN_140d8b130(int* pnX, int* pnY, int* pnZ);   // mouse movement deltas
    bool FUN_140d8b200(int nKey);                       // inject a press
    bool FUN_140d8b250(int nKey);                       // inject a release
    static int FUN_140d8b290(int nKey);                 // keyboard code of a key id (0 if not a keyboard key)
    static int FUN_140d8b2c0(int nKey);                 // mouse button of a key id (-1 if not a mouse button)
    static int FUN_140d8b300(int nKey);                      // gamepad button of a key id (-1 if none)
    bool FUN_140d8b360() const;                         // always true
    bool FUN_140d8b370() const;                         // a keyboard key is held or a gamepad is present
    void FUN_140d8b3e0(double dSeconds);                // rumble for the given time
    void FUN_140d8b470();                               // start rumbling
    void FUN_140d8b560(bool bQuickStop);                // stop rumbling
    int FUN_140d8b600(int nKey);                        // modifier group (both held) test: down
    int FUN_140d8b6a0(int nKey);                        // modifier group test: pressed
    int FUN_140d8b740(int nKey);                        // modifier group test: released
    bool FUN_140d8b7e0(int nKey);                       // modifier group inject press
    bool FUN_140d8b870(int nKey);                       // modifier group inject release
    void FUN_140d8b900(bool bEnable, bool bNotify);     // enable / disable gamepad input
    void FUN_140d8bd00();                               // toggle gamepad cursor mode
    float FUN_140d8bde0();                              // cursor speed x
    float FUN_140d8be10();                         // cursor speed y
    void FUN_140d8be40();                               // find a gamepad
    int FUN_140d8c0a0(__int64 nSetting);   // gamepad button for a key setting
    int FUN_140d8c150(int nKey);                        // remap a gamepad key id for the dual layout
    void FUN_140d8c230();                               // rumble timer update
    Vector3 FUN_140d8c2f0();                           // gamepad left stick as a direction
    int FUN_140d8c450();                                // left stick Y percent
    int FUN_140d8c4d0();                                // left stick X percent
    bool FUN_140d8c550();                               // stick changed direction
    int FUN_140d8c660();                                // pad kind (3 folds into 1)
    CStringW FUN_140d8c690();                           // layout name
    CStringW FUN_140d8c750();           // layout display text
    bool FUN_140d8c8d0(int nResult, const CMsgBoxData& data);   // message box callback: resume the input system
    bool FUN_140d8c920(int nKey);                       // key is held
    NiPointer<NiInputGamePad> GetGamePad();           // the active gamepad (by value)
    bool FUN_140d8cd50(int nKey);                       // key was pressed
    bool FUN_140d8d2d0(int nKey);                       // key was released
    bool FUN_140d8d840(int nKey);                       // inject a key press
    bool FUN_140d8db30(int nKey);                       // inject a key release
    int FUN_140d8ee40() const { return m_nPadKind; }    // 0x140d8ee40

private:
    NiPointer<NiInputKeyboard> m_spKeyboard;            // +0xf0
    NiPointer<NiInputMouse> m_spMouse;                  // +0xf8
    NiPointer<NiInputGamePad> m_spGamePad;              // +0x100  the active gamepad
    NiPointer<NiInputXInputGamePad> m_spXInputPad;      // +0x108
    NiPointer<NiInputDI8GamePad> m_spDI8Pad;            // +0x110
    int m_nPadEnabled;                                  // +0x118
    Unk_PadKind m_nPadKind;                             // +0x11c  0 none, 1 XInput, 2 DirectInput (dual)
    int m_nRumbling;                                    // +0x120
    int m_nCursorMode;                                  // +0x124
    int m_nLeftDown;                                    // +0x128
    int m_nRightDown;                                   // +0x12c
    int m_nHeldKey;                                     // +0x130
    double m_dRumbleStart;                              // +0x138
    double m_dRumbleEnd;                                // +0x140
    int m_nRumbleActive;                                // +0x148
};
MS2_CHECK_SIZE(MS2InputService, 0x150);

inline TSingleton<MS2InputService>::TSingleton() { s_instance = static_cast<MS2InputService*>(this); }
