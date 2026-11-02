// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). MS2InputService: ecrInput::InputService with the game's
// unified key id space (keyboard / mouse / gamepad), gamepad discovery and rumble.
// MS2-UNIT: ?\ms2inputservice.cpp
// MS2-RANGE: 0x140d8a570-0x140d8f690 .text$mn
// MS2-PIN: ??_7MS2InputService@@6BInputService@ecrInput@@@ 0x142e32c70
// MS2-PIN: ??_7MS2InputService@@6B?$TSingleton@VMS2InputService@@@@@ 0x142e32cf8
// MS2-PIN: ??$format_arg@DW4Unk_PadKind@@@fmt@@YAXAEAV?$BasicFormatter@D@0@AEAPEBDAEBW4Unk_PadKind@@@Z 0x140d8e150
// MS2-PIN: ?vfunc_1@?$DelegateImpl@U?$pair@PEAVMS2InputService@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEBAPEAVDelegateImplBase@2@XZ 0x140d8f550
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??B?$SmartPointer@VNiInputXInputGamePad@@@efd@@QEBAPEAVNiInputXInputGamePad@@XZ 0x140d8e9a0 ; order
// MS2-PIN: ??C?$SmartPointer@VNiInputDI8GamePad@@@efd@@QEBAPEAVNiInputDI8GamePad@@XZ 0x140d8e9b0 ; order
// MS2-PIN: ?GetClassDesc@InputService@ecrInput@@UEBAPEBVClassInfo@efd@@XZ 0x140d8edf0 ; unique
// MS2-PIN: ?GetGamePad@NiInputSystem@@QEBAPEAVNiInputGamePad@@I@Z 0x140d8ee00 ; unique
// MS2-PIN: ?IncRefCount@InputService@ecrInput@@UEBAXXZ 0x140d8f090 ; unique
// MS2-PIN: ?TypeCast@InputService@ecrInput@@UEBA_NIPEAPEAX@Z 0x140d8f3f0 ; order
// MS2-PIN: ?TypeCast@InputService@ecrInput@@UEBA_NIPEAPEBX@Z 0x140d8f440 ; order
// MS2-PIN: ?Invoke@?$DelegateImpl@U?$pair@PEAVMS2InputService@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@UEAA_NHAEBVCMsgBoxData@@@Z 0x140d8f5b0 ; unique
// MS2-PIN: ??$Call@VMS2InputService@@P81@EAA_NHAEBVCMsgBoxData@@@Z@?$DelegateImpl@U?$pair@PEAVMS2InputService@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@@?$Delegate@$$A6A_NHAEBVCMsgBoxData@@@Z@@CA_NAEAU?$pair@PEAVMS2InputService@@P81@EAA_NHAEBVCMsgBoxData@@@Z@std@@HAEBVCMsgBoxData@@@Z 0x140d8f5f0 ; unique
// MS2-PINS-END tplpin
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\ms2inputservice.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <efd/Point3.h>
#include "ms2inputservice.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/nipoint3.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "ms2/placeholder/ckeytable.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/uimainplayerinfo.h"
#include "ms2/client/ms2/bigdatalogsystem.h"
#include "ms2/placeholder/asmousecursor.h"
#include "ms2/client/ms2/windowservice.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/cmainsystem.h"
#include "ms2/placeholder/crashmanagercli.h"
#include "ms2/placeholder/ichromamanager.h"  // C3: ChromaSDK::GetChromaManager
#include "ms2/commonfiles/os.h"

// ---- out-of-unit callees ----

MS2InputService* FUN_140a58540();                       // TSingleton<MS2InputService>::GetInstance

class Unk_140a44830                                     // the game log / diagnostics object
{
public:
    void FUN_140a439b0();
    bool FUN_140d8f0b0() const { return m_bFlag; }      // 0x140d8f0b0
    char m_pad[0x60];
    bool m_bFlag;
};


class Unk_SettingsHolder;                               // option flags
class Unk_140166410* FUN_140166410();   // C3: was FUN_140166410
class CFeatureManager { public: bool FUN_14036d570(int nFeature); };   // C3: unit-local view

class Unk_KeyBindings                                   // key binding table
{
public:
    int FUN_141431a90(int nKey);
};

UIMainPlayerInfo* FUN_140931900(int nId);

class Unk_Clock;

class Unk_RsApp : public CWindowService { public: void FUN_141b90f20(int nMsg); };
void* FUN_140aadf80();   // C3: was FUN_140aadf80

class Unk_HudDlg : public ASMouseCursor { public: void FUN_1422cee50(int n);};
class Unk_HudPtr
{
public:
    ~Unk_HudPtr();                                      // 0x140a58400
    bool FUN_140d41080(int nNull);
    Unk_HudDlg* FUN_140a584a0();
private:
    void* m_pad_00;
    void* m_pad_08;
    void* m_pad_10;
};
class Unk_HudMgr { public: Unk_HudPtr FUN_1422b0370(int n); };
class Unk_AltStringMgr* FUN_14025e7a0();   // C3: was FUN_14025e7a0

struct Unk_PadCursorCfg { int m_0; float fSpeedX; float fSpeedY; };
class CGameOption;
struct Unk_GpState* FUN_140a58500(class Unk_GpSettings*);   // C3: was FUN_140a58500

class Unk_1403ed2b0 { public: int FUN_141adbd10(); };

class Unk_EventSink : public CBigDataLogSystem { };
extern int DAT_143af7d40;                               // input enabled
extern float DAT_143ac30a8;                             // last stick x
extern float DAT_143ac30ac;                             // last stick y
#define DAT_143b01a60 (*(Vector3*)&efd::Point3::ZERO)          // C3: was extern Vector3 DAT_143b01a60
class CBigDataLogSystem;

class CMsgBoxData : public CPtred
{
public:
    void FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)> cb);
};
MS2Ptr<CMsgBoxData> FUN_140d73d20(int nType, CStringW text, void* p, CStringW tag);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
CStringW FUN_140298ea0(CStringW str);
CStringW GetStringCommonByKey(const CStringW& str);


// NiInputSystem::m_bGamePadPollEnabled setter (exe-only inline, 0x140d8f490)
struct MS2NiInputSystemAccess : public NiInputSystem
{
    void FUN_140d8f490(bool b) { m_bGamePadPollEnabled = b; }
};

// @0x140d8ee90
Unk_EventSink* FUN_140d8ee90()
{
    return reinterpret_cast<Unk_EventSink*>(TSingleton<CBigDataLogSystem>::s_instance);
}

// Not in the hook DLL: MS2::RegisterServices (hooked) must build the exe object (exe vtable; unhooked virtuals stay exe).
#ifndef MS2_HOOK_DLL
// @0x140d8a570
MS2InputService::MS2InputService()
    : InputService(false, false)
    , m_spKeyboard(0)
    , m_spMouse(0)
    , m_spGamePad(0)
    , m_spXInputPad(0)
    , m_spDI8Pad(0)
{
    m_nPadEnabled = 0;
    m_nPadKind = PADKIND_NONE;
    m_nRumbling = 0;
    m_nCursorMode = 0;
    m_nLeftDown = 0;
    m_nRightDown = 0;
    m_nHeldKey = -1;
    m_nRumbleActive = 0;
}
#endif

// @0x140d8a6c0
MS2InputService::~MS2InputService()
{
}

// @0x140d8a780
efd::AsyncResult MS2InputService::OnInit()
{
    efd::AsyncResult result = InputService::OnInit();
    if (!reinterpret_cast<Unk_140a44830*>(TSingleton<CrashManagerCli>::GetInstance())->FUN_140d8f0b0())
        reinterpret_cast<Unk_140a44830*>(TSingleton<CrashManagerCli>::GetInstance())->FUN_140a439b0();
    NiInputSystem* pInput = GetInputSystem();
    if (pInput != NULL)
    {
        m_spKeyboard = pInput->OpenKeyboard();
        m_spMouse = pInput->OpenMouse();
        if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xb5) == 1)
            reinterpret_cast<MS2NiInputSystemAccess*>(pInput)->FUN_140d8f490(true);
    }
    ChromaSDK::GetChromaManager()->Initialize();
    if (result == efd::AsyncResult_Failure)
        result = efd::AsyncResult_Complete;
    return result;
}
MS2_REPLACE_METHOD(0x140D8A780, MS2InputService, OnInit, 239, 0x560A446A);

// @0x140d8a880
efd::AsyncResult MS2InputService::OnTick()
{
    if (m_nPadEnabled != 0)
    {
        UpdateRumble();
        if (m_nCursorMode != 0)
        {
            if (m_spGamePad)
            {
                float fX = (float)m_spGamePad->GetStickAxisValue(NiInputGamePad::NIGP_STICK_LEFT | NiInputGamePad::NIGP_STICK_AXIS_H);
                int nX = (int)(fX * FUN_140d8bde0());
                float fY = (float)m_spGamePad->GetStickAxisValue(NiInputGamePad::NIGP_STICK_LEFT | NiInputGamePad::NIGP_STICK_AXIS_V);
                int nY = (int)(fY * FUN_140d8be10());
                ((class Unk_RsApp*)FUN_140aadf80())->MoveCursor(nX, nY);
                if (m_nLeftDown != 0)
                {
                    if (m_spGamePad->ButtonWasReleased((NiInputGamePad::Button)FUN_140d8c0a0(0xc3506)))
                    {
                        ((class Unk_RsApp*)FUN_140aadf80())->FUN_141b90f20(0x202);
                        m_nLeftDown = 0;
                    }
                }
                else
                {
                    if (m_spGamePad->ButtonWasPressed((NiInputGamePad::Button)FUN_140d8c0a0(0xc3506)))
                    {
                        ((class Unk_RsApp*)FUN_140aadf80())->FUN_141b90f20(0x201);
                        m_nLeftDown = 1;
                    }
                }
                if (m_nRightDown != 0)
                {
                    if (m_spGamePad->ButtonWasReleased((NiInputGamePad::Button)FUN_140d8c0a0(0xc3505)))
                    {
                        ((class Unk_RsApp*)FUN_140aadf80())->FUN_141b90f20(0x205);
                        m_nRightDown = 0;
                    }
                }
                else
                {
                    if (m_spGamePad->ButtonWasPressed((NiInputGamePad::Button)FUN_140d8c0a0(0xc3505)))
                    {
                        ((class Unk_RsApp*)FUN_140aadf80())->FUN_141b90f20(0x204);
                        m_nRightDown = 1;
                    }
                }
            }
        }
        if (m_spGamePad)
        {
            if (m_spGamePad->ButtonWasPressed((NiInputGamePad::Button)FUN_140d8c0a0(0xc3507)))
                ToggleCursorMode();
        }
        else
        {
            DetectGamePad();
        }
    }
    else
    {
        if (m_nRumbleActive != 0)
            StopRumble(false);
    }
    return InputService::OnTick();
}
MS2_REPLACE_METHOD(0x140D8A880, MS2InputService, OnTick, 789, 0xA91F074C);

// @0x140d8aba0
efd::AsyncResult MS2InputService::OnShutdown()
{
    ChromaSDK::GetChromaManager()->Finalize();
    m_spKeyboard = 0;
    m_spMouse = 0;
    m_spGamePad = 0;
    m_spXInputPad = 0;
    m_spDI8Pad = 0;
    return InputService::OnShutdown();
}
MS2_REPLACE_METHOD(0x140D8ABA0, MS2InputService, OnShutdown, 155, 0xD0796499);

// @0x140d8ac50
bool MS2InputService::IsKeyDownGated(int nKey, int bAllowGroup)
{
    if (DAT_143af7d40 == 0)
        return false;
    int nPacked = IsComboKeyDown(nKey);
    if (nPacked == 1)
        return true;
    if (bAllowGroup == 0 && 0x91 < nKey && nKey < 0xa2)
    {
        for (int nSlot = 0x96; nSlot <= 0x99; nSlot = nSlot + 1)
        {
            if (IsKeyDown(nSlot))
            {
                if (nSlot != nKey)
                    return false;
                __int64 pBinding = FUN_1409331f0()->GetKeyAction(nSlot);
                if (pBinding == 0)
                    return false;
                if (FUN_1409331f0()->FUN_141430b10(pBinding) == 0)
                    return true;
                return false;
            }
        }
    }
    return IsKeyDown(nKey);
}
MS2_REPLACE_METHOD(0x140D8AC50, MS2InputService, IsKeyDownGated, 255, 0x23AF6714);

// @0x140d8ad60
bool MS2InputService::WasKeyPressedGated(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    int nPacked = WasComboKeyPressed(nKey);
    if (nPacked == 1)
        return true;
    if (0x91 < nKey && nKey < 0xa2)
    {
        for (int nSlot = 0x96; nSlot <= 0x99; nSlot = nSlot + 1)
        {
            if (IsKeyDown(nSlot))
            {
                if (m_nHeldKey != nSlot)
                {
                    if (m_nHeldKey != -1)
                    {
                        UIMainPlayerInfo* pDlg = FUN_140931900(0x4e5f);
                        if (pDlg != 0)
                            pDlg->FUN_1419f22a0(m_nHeldKey, 0);
                        m_nHeldKey = -1;
                    }
                    m_nHeldKey = nSlot;
                    UIMainPlayerInfo* pDlg = FUN_140931900(0x4e5f);
                    if (pDlg != 0)
                        pDlg->FUN_1419f22a0(m_nHeldKey, 1);
                }
                if (nSlot != nKey)
                    return false;
                __int64 pBinding = FUN_1409331f0()->GetKeyAction(nSlot);
                if (pBinding == 0)
                    return false;
                if (FUN_1409331f0()->FUN_141430b10(pBinding) == 0)
                {
                    if (WasKeyPressed(nSlot))
                        return true;
                }
                return false;
            }
            else
            {
                if (m_nHeldKey == nSlot)
                {
                    UIMainPlayerInfo* pDlg = FUN_140931900(0x4e5f);
                    if (pDlg != 0)
                        pDlg->FUN_1419f22a0(m_nHeldKey, 0);
                    m_nHeldKey = -1;
                }
            }
        }
    }
    return WasKeyPressed(nKey);
}
MS2_REPLACE_METHOD(0x140D8AD60, MS2InputService, WasKeyPressedGated, 518, 0xBFBD51FC);

// @0x140d8af70
bool MS2InputService::WasKeyReleasedGated(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    int nPacked = WasComboKeyReleased(nKey);
    if (nPacked == 1)
        return true;
    if (0x91 < nKey && nKey < 0xa2)
    {
        for (int nSlot = 0x96; nSlot <= 0x99; nSlot = nSlot + 1)
        {
            if (IsKeyDown(nSlot))
                return false;
        }
    }
    return WasKeyReleased(nKey);
}
MS2_REPLACE_METHOD(0x140D8AF70, MS2InputService, WasKeyReleasedGated, 151, 0x78EE826B);

// @0x140d8b010
bool MS2InputService::IsMouseButtonDown(int nButton)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!m_spMouse)
        return false;
    return m_spMouse->ButtonIsDown((NiInputMouse::Button)nButton);
}
MS2_REPLACE_METHOD(0x140D8B010, MS2InputService, IsMouseButtonDown, 90, 0x3316EAD7);

// @0x140d8b070
bool MS2InputService::WasMouseButtonPressed(int nButton)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!m_spMouse)
        return false;
    return m_spMouse->ButtonWasPressed((NiInputMouse::Button)nButton);
}
MS2_REPLACE_METHOD(0x140D8B070, MS2InputService, WasMouseButtonPressed, 90, 0x455CA3A2);

// @0x140d8b0d0
bool MS2InputService::WasMouseButtonReleased(int nButton)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!m_spMouse)
        return false;
    return m_spMouse->ButtonWasReleased((NiInputMouse::Button)nButton);
}
MS2_REPLACE_METHOD(0x140D8B0D0, MS2InputService, WasMouseButtonReleased, 90, 0x946DB23B);

// @0x140d8b130
bool MS2InputService::GetMouseDelta(int* pnX, int* pnY, int* pnZ)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (!m_spMouse)
        return false;
    if (reinterpret_cast<Unk_1403ed2b0*>(TSingleton<CUIService>::GetInstance())->FUN_141adbd10() != 0)
    {
        m_spMouse->GetPositionDelta(*pnX, *pnY, *pnZ);
        *pnZ = 0;
        return false;
    }
    return m_spMouse->GetPositionDelta(*pnX, *pnY, *pnZ);
}
MS2_REPLACE_METHOD(0x140D8B130, MS2InputService, GetMouseDelta, 189, 0x76EAE117);

// @0x140d8b200
bool MS2InputService::InjectKeyPress(int nKey)
{
    if (DAT_143af7d40 == 0)
        return false;
    if (InjectComboKeyPress(nKey))
        return true;
    return InjectSingleKeyPress(nKey);
}
MS2_REPLACE_METHOD(0x140D8B200, MS2InputService, InjectKeyPress, 70, 0xD71B8A8F);

// @0x140d8b250
bool MS2InputService::InjectKeyRelease(int nKey)
{
    if (InjectComboKeyRelease(nKey))
        return true;
    return InjectSingleKeyRelease(nKey);
}
MS2_REPLACE_METHOD(0x140D8B250, MS2InputService, InjectKeyRelease, 57, 0x5191D965);

// @0x140d8b290
int MS2InputService::GetKeyboardCode(int nKey)
{
    if (FUN_1409331f0()->FUN_141431a30(nKey))
        return nKey;
    return 0;
}
MS2_REPLACE(0x140D8B290, MS2InputService::GetKeyboardCode, 42, 0x6B27C144);

// @0x140d8b2c0
int MS2InputService::GetMouseButtonIndex(int nKey)
{
    if (FUN_1409331f0()->FUN_141431a60(nKey))
        return nKey - 200;
    return -1;
}
MS2_REPLACE(0x140D8B2C0, MS2InputService::GetMouseButtonIndex, 50, 0x886E2638);

// @0x140d8b300
int MS2InputService::GetGamePadButtonIndex(int nKey)
{
    if (reinterpret_cast<Unk_KeyBindings*>(FUN_1409331f0())->FUN_141431a90(nKey) != 0 && nKey < 0xa2)
    {
        nKey = FUN_140a58540()->RemapPadButtonForDualShock(nKey);
        return nKey - 0x92;
    }
    return -1;
}
MS2_REPLACE(0x140D8B300, MS2InputService::GetGamePadButtonIndex, 81, 0x3C97B7A6);

// @0x140d8b360
bool MS2InputService::FUN_140d8b360() const
{
    return true;
}
MS2_REPLACE_METHOD(0x140D8B360, MS2InputService, FUN_140d8b360, 8, 0x71679366);

// @0x140d8b370
bool MS2InputService::HasKeyHeldOrGamePad() const
{
    if (m_spKeyboard)
    {
        if (m_spKeyboard->AnyKeyDown())
            return true;
    }
    if (m_spGamePad)
        return true;
    return false;
}
MS2_REPLACE_METHOD(0x140D8B370, MS2InputService, HasKeyHeldOrGamePad, 106, 0xB57266D3);

// @0x140d8b3e0
void MS2InputService::StartRumbleFor(double dSeconds)
{
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xc3) != 1)
        return;
    m_nRumbleActive = 1;
    m_dRumbleStart = ((class CMainSystem*)(class Unk_Clock*)(reinterpret_cast<Unk_Clock*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473280();
    m_dRumbleEnd = m_dRumbleStart + dSeconds;
    StartRumble();
}
MS2_REPLACE_METHOD(0x140D8B3E0, MS2InputService, StartRumbleFor, 131, 0xDE1C9608);

// @0x140d8b470
void MS2InputService::StartRumble()
{
    if (m_spGamePad && m_nRumbling == 0)
    {
        m_spGamePad->SetRumbleValue(0, 1.0f, false);
        m_spGamePad->SetRumbleValue(1, 1.0f, false);
        m_spGamePad->StartRumble();
        m_nRumbling = 1;
    }
}
MS2_REPLACE_METHOD(0x140D8B470, MS2InputService, StartRumble, 219, 0x4A497FFD);

// @0x140d8b560
void MS2InputService::StopRumble(bool bQuickStop)
{
    if (m_spGamePad && m_nRumbling != 0)
    {
        m_nRumbling = 0;
        m_nRumbleActive = 0;
        m_spGamePad->StopRumble(bQuickStop);
    }
}
MS2_REPLACE_METHOD(0x140D8B560, MS2InputService, StopRumble, 152, 0xA695DC52);

union Unk_PackedKey { int n; struct { unsigned char b0, b1, b2, b3; } b; };

// The packed modifier-group keys: (kind << 16) | (first << 8) | second, kind 0xf0 / 0xf1; first and second are
// offsets from the first gamepad button id 0x91.
// @0x140d8b600
int MS2InputService::IsComboKeyDown(int nKey)
{
    Unk_PackedKey key;
    key.n = nKey;
    if (key.b.b2 == 0xf0 || key.b.b2 == 0xf1)
    {
        int nFirst = key.b.b1 + 0x91;
        int nSecond = key.b.b0 + 0x91;
        if (!IsKeyDown(nFirst))
            return -1;
        if (IsKeyDown(nSecond))
            return 1;
        return -1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140D8B600, MS2InputService, IsComboKeyDown, 143, 0x47CF2044);

// @0x140d8b6a0
int MS2InputService::WasComboKeyPressed(int nKey)
{
    Unk_PackedKey key;
    key.n = nKey;
    if (key.b.b2 == 0xf0 || key.b.b2 == 0xf1)
    {
        int nFirst = key.b.b1 + 0x91;
        int nSecond = key.b.b0 + 0x91;
        if (!IsKeyDown(nFirst))
            return -1;
        if (WasKeyPressed(nSecond))
            return 1;
        return -1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140D8B6A0, MS2InputService, WasComboKeyPressed, 143, 0xB9D5FA10);

// @0x140d8b740
int MS2InputService::WasComboKeyReleased(int nKey)
{
    Unk_PackedKey key;
    key.n = nKey;
    if (key.b.b2 == 0xf0 || key.b.b2 == 0xf1)
    {
        int nFirst = key.b.b1 + 0x91;
        int nSecond = key.b.b0 + 0x91;
        if (!WasKeyReleased(nFirst))
            return -1;
        if (WasKeyReleased(nSecond))
            return 1;
        return -1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140D8B740, MS2InputService, WasComboKeyReleased, 143, 0xA4A564C8);

// @0x140d8b7e0
bool MS2InputService::InjectComboKeyPress(int nKey)
{
    Unk_PackedKey key;
    key.n = nKey;
    if (key.b.b2 == 0xf0 || key.b.b2 == 0xf1)
    {
        int nFirst = key.b.b1 + 0x91;
        int nSecond = key.b.b0 + 0x91;
        if (!InjectSingleKeyPress(nFirst))
            return false;
        if (InjectSingleKeyPress(nSecond))
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140D8B7E0, MS2InputService, InjectComboKeyPress, 130, 0x0E158E32);

// @0x140d8b870
bool MS2InputService::InjectComboKeyRelease(int nKey)
{
    Unk_PackedKey key;
    key.n = nKey;
    if (key.b.b2 == 0xf0 || key.b.b2 == 0xf1)
    {
        int nFirst = key.b.b1 + 0x91;
        int nSecond = key.b.b0 + 0x91;
        if (!InjectSingleKeyRelease(nFirst))
            return false;
        if (InjectSingleKeyRelease(nSecond))
            return true;
    }
    return false;
}
MS2_REPLACE_METHOD(0x140D8B870, MS2InputService, InjectComboKeyRelease, 130, 0xE2098423);

// @0x140d8b900
void MS2InputService::SetGamePadEnabled(bool bEnable, bool bNotify)
{
    NiInputSystem* pInput = GetInputSystem();
    if (pInput == NULL)
        return;
    {
        int nOldKind = m_nPadKind;
        reinterpret_cast<MS2NiInputSystemAccess*>(pInput)->FUN_140d8f490(bEnable);
        m_nPadEnabled = bEnable;
        if (bEnable)
        {
            DetectGamePad();
            if (m_spGamePad == 0 && bNotify)
            {
                MS2Ptr<CMsgBoxData> box = FUN_140d73d20(1, FUN_140298ea0(L"s_gamepad_notice_search_gamepad"), 0, L"");
                if (box)
                {
                    box->FUN_141a027c0(Delegate<bool(int, const CMsgBoxData&)>(this, &MS2InputService::OnNoGamePadMsgBoxResult));
                    FUN_140d73c60(box);
                }
            }
            if (FUN_1409331f0()->FUN_14142c940(0x30d41, 2) == 0)
            {
                if (FUN_140a58540()->FUN_140d8ee40() == 2)
                    FUN_1409331f0()->FUN_141429e60("./Data/Xml/Table/default/DefaultPSKey.xml");
                else
                    FUN_1409331f0()->FUN_141429e60("./Data/Xml/Table/default/DefaultXboxKey.xml");
            }
        }
        else
        {
            m_nPadKind = PADKIND_NONE;
            m_spGamePad = 0;
        }
        if (nOldKind != m_nPadKind && FUN_140d8ee90() != 0)
            FUN_140d8ee90()->SendLog("controller", StringFormat("{0}", m_nPadKind));
    }
}
MS2_REPLACE_METHOD(0x140D8B900, MS2InputService, SetGamePadEnabled, 1016, 0x66A2098E);

// @0x140d8bd00
void MS2InputService::ToggleCursorMode()
{
    m_nCursorMode = m_nCursorMode ^ 1;
    Unk_HudPtr hud = ((class Unk_HudMgr*)FUN_14025e7a0())->FUN_1422b0370(6);
    if (hud.FUN_140d41080(0))
        return;
    if (m_nCursorMode != 0)
    {
        hud.FUN_140a584a0()->FUN_1422cee50(10);
        hud.FUN_140a584a0()->FUN_1422cedb0();
    }
    else
    {
        hud.FUN_140a584a0()->FUN_1422cee00();
        hud.FUN_140a584a0()->FUN_1422cee50(0);
    }
}
MS2_REPLACE_METHOD(0x140D8BD00, MS2InputService, ToggleCursorMode, 210, 0x770EEEE7);

// @0x140d8bde0
float MS2InputService::FUN_140d8bde0()
{
    return ((struct Unk_PadCursorCfg*)FUN_140a58500((class Unk_GpSettings*)((void*)TSingleton<CGameOption>::GetInstance())))->fSpeedX;
}
MS2_REPLACE_METHOD(0x140D8BDE0, MS2InputService, FUN_140d8bde0, 32, 0xA407171B);

// @0x140d8be10
float MS2InputService::FUN_140d8be10()
{
    return ((struct Unk_PadCursorCfg*)FUN_140a58500((class Unk_GpSettings*)((void*)TSingleton<CGameOption>::GetInstance())))->fSpeedY;
}
MS2_REPLACE_METHOD(0x140D8BE10, MS2InputService, FUN_140d8be10, 32, 0xCBEBD717);

// @0x140d8be40
void MS2InputService::DetectGamePad()
{
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xb5) == 1)
    {
        NiInputSystem* pInput = GetInputSystem();
        if (pInput != NULL)
        {
            if (m_spGamePad)
                return;
            m_nPadKind = PADKIND_NONE;
            if (!m_spGamePad)
            {
                for (unsigned int ui = 0; ui < 4; ui = ui + 1)
                {
                    m_spXInputPad = NiDynamicCast(NiInputXInputGamePad, pInput->GetGamePad(ui));
                    if (m_spXInputPad)
                    {
                        if (m_spXInputPad->GetStatus() == 0)
                        {
                            m_spGamePad = m_spXInputPad;
                            m_nPadKind = PADKIND_XINPUT;
                            break;
                        }
                    }
                    m_spXInputPad = 0;
                }
            }
            if (m_nPadKind == 0)
            {
                m_spXInputPad = 0;
                m_spGamePad = 0;
                m_spDI8Pad = NiDynamicCast(NiInputDI8GamePad, pInput->GetGamePad(4));
                if (m_spDI8Pad ? true : false)
                {
                    if (m_spDI8Pad->GetStatus() == 0)
                    {
                        m_spGamePad = m_spDI8Pad;
                        m_nPadKind = PADKIND_DUAL;
                    }
                }
            }
        }
    }
}
MS2_REPLACE_METHOD(0x140D8BE40, MS2InputService, DetectGamePad, 600, 0x7CBF8EF8);

// @0x140d8c0a0
int MS2InputService::FUN_140d8c0a0(__int64 nSetting)
{
    int nKey = FUN_1409331f0()->FUN_14142c940(nSetting, 2);
    nKey = RemapPadButtonForDualShock(nKey);
    int nSlot = nKey - 0x92;
    return nSlot;
}
MS2_REPLACE_METHOD(0x140D8C0A0, MS2InputService, FUN_140d8c0a0, 82, 0x08BBEB54);

// @0x140d8c100
NiPointer<NiInputGamePad> MS2InputService::GetGamePad()
{
    return m_spGamePad;
}
MS2_REPLACE_METHOD(0x140D8C100, MS2InputService, GetGamePad, 67, 0xD0E3CADB);

// @0x140d8c150
int MS2InputService::RemapPadButtonForDualShock(int nKey)
{
    int nMapped = nKey;
    if (FUN_140a58540()->FUN_140d8ee40() == 2)
    {
        switch (nKey)
        {
        case 0x97:
            nMapped = 0xa1;
            break;
        case 0x99:
            nMapped = 0xa0;
            break;
        case 0x9e:
            nMapped = 0x97;
            break;
        case 0x9f:
            nMapped = 0x99;
            break;
        case 0xa0:
            nMapped = 0x9f;
            break;
        case 0xa1:
            nMapped = 0x9e;
        }
    }
    return nMapped;
}
MS2_REPLACE_METHOD(0x140D8C150, MS2InputService, RemapPadButtonForDualShock, 158, 0x643CAA41);

// @0x140d8c230
void MS2InputService::UpdateRumble()
{
    double dNow = ((class CMainSystem*)(class Unk_Clock*)(reinterpret_cast<Unk_Clock*>(TSingleton<CMainSystem>::GetInstance())))->FUN_141473280();
    if (m_nRumbleActive == 0)
        return;
    if (dNow < m_dRumbleStart)
        return;
    else if (dNow < m_dRumbleEnd)
    {
        if (m_spGamePad)
            m_spGamePad->StartRumble();
        return;
    }
    else
    {
        StopRumble(true);
    }
}
MS2_REPLACE_METHOD(0x140D8C230, MS2InputService, UpdateRumble, 171, 0x76B0BCD7);

// @0x140d8c2f0
Vector3 MS2InputService::GetLeftStickMoveDir()
{
    if (!m_spGamePad)
        return DAT_143b01a60;
    if (DAT_143af7d40 == 0)
        return DAT_143b01a60;
    float fX = (float)m_spGamePad->GetStickAxisValue(NiInputGamePad::NIGP_STICK_LEFT | NiInputGamePad::NIGP_STICK_AXIS_H);
    float fY = (float)m_spGamePad->GetStickAxisValue(NiInputGamePad::NIGP_STICK_LEFT | NiInputGamePad::NIGP_STICK_AXIS_V);
    Vector3 kDir = DAT_143b01a60;
    if (fX != 0.0f || fY != 0.0f)
    {
        kDir.x = fX * -1.0f;
        kDir.y = fY * -1.0f;
    }
    kDir.FUN_140968990();
    return kDir;
}
MS2_REPLACE_METHOD(0x140D8C2F0, MS2InputService, GetLeftStickMoveDir, 334, 0x7C552B1D);

// @0x140d8c450
int MS2InputService::GetLeftStickYPercent()
{
    int nResult = 0;
    if (m_spGamePad)
    {
        nResult = m_spGamePad->GetStickAxisValue(NiInputGamePad::NIGP_STICK_LEFT | NiInputGamePad::NIGP_STICK_AXIS_V);
        nResult = (int)(((float)nResult / 127.0f) * 100.0f);
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x140D8C450, MS2InputService, GetLeftStickYPercent, 116, 0x9831EC2D);

// @0x140d8c4d0
int MS2InputService::GetLeftStickXPercent()
{
    int nResult = 0;
    if (m_spGamePad)
    {
        nResult = m_spGamePad->GetStickAxisValue(NiInputGamePad::NIGP_STICK_LEFT | NiInputGamePad::NIGP_STICK_AXIS_H);
        nResult = (int)(((float)nResult / 127.0f) * 100.0f);
    }
    return nResult;
}
MS2_REPLACE_METHOD(0x140D8C4D0, MS2InputService, GetLeftStickXPercent, 116, 0x72F197D8);

// @0x140d8c550
bool MS2InputService::FUN_140d8c550()
{
    if (m_spGamePad == 0)
        return false;
    bool bChanged = true;
    if (((class CFeatureManager*)FUN_140166410())->FUN_14036d570(0xb5) == 1)
    {
        float fX = (float)m_spGamePad->GetStickAxisValue(NiInputGamePad::NIGP_STICK_LEFT | NiInputGamePad::NIGP_STICK_AXIS_H);
        float fY = (float)m_spGamePad->GetStickAxisValue(NiInputGamePad::NIGP_STICK_LEFT | NiInputGamePad::NIGP_STICK_AXIS_V);
        if (DAT_143ac30a8 * fX < 0.0f)
            bChanged = false;
        if (DAT_143ac30ac * fY < 0.0f)
            bChanged = false;
        DAT_143ac30a8 = fX;
        DAT_143ac30ac = fY;
    }
    return bChanged;
}
MS2_REPLACE_METHOD(0x140D8C550, MS2InputService, FUN_140d8c550, 257, 0x7AC0FD99);

// @0x140d8c660
int MS2InputService::GetPadFamily()
{
    if (m_nPadKind == 3)
        return 1;
    return m_nPadKind;
}
MS2_REPLACE_METHOD(0x140D8C660, MS2InputService, GetPadFamily, 38, 0xE5254B11);

// @0x140d8c690
CStringW MS2InputService::GetPadKindName()
{
    CStringW strName;
    if (FUN_140d8ee40() == 2)
        return CStringW(L"dual");
    else
        return CStringW(L"xbox");
}
MS2_REPLACE_METHOD(0x140D8C690, MS2InputService, GetPadKindName, 157, 0x9EF15297);

// @0x140d8c750
CStringW MS2InputService::GetPadKindDisplayName()
{
    CStringW strText;
    if (FUN_140d8ee40() == 2)
        return GetStringCommonByKey(L"s_gameoption_input_gamepad_dual");
    else if (FUN_140d8ee40() == 1)
        return GetStringCommonByKey(L"s_gameoption_input_gamepad_xbox");
    else if (FUN_140d8ee40() == 3)
        return GetStringCommonByKey(L"s_gameoption_input_gamepad_steam");
    return L"";
}
MS2_REPLACE_METHOD(0x140D8C750, MS2InputService, GetPadKindDisplayName, 369, 0x67FCD932);

// @0x140d8c8d0
bool MS2InputService::OnNoGamePadMsgBoxResult(int nResult, const CMsgBoxData& data)
{
    if (nResult == 0)
    {
        NiInputSystem* pInput = GetInputSystem();
        if (pInput != NULL)
            pInput->CheckEnumerationStatus();
    }
    return true;
}
MS2_REPLACE_METHOD(0x140D8C8D0, MS2InputService, OnNoGamePadMsgBoxResult, 74, 0xB7CE330A);

// @0x140d8c920
bool MS2InputService::IsKeyDown(int nKey)
{
    if (nKey == 0 || nKey == -1)
        return false;
    bool bDown;
    int nKb = GetKeyboardCode(nKey);
    int nMouse = GetMouseButtonIndex(nKey);
    if (nKb != 0)
    {
        if (m_spKeyboard)
            return m_spKeyboard->KeyIsDown((NiInputKeyboard::KeyCode)nKb);
        return false;
    }
    else if (nMouse != -1)
    {
        if (m_spMouse)
            return m_spMouse->ButtonIsDown((NiInputMouse::Button)nMouse);
    }
    else
    {
        if (m_spGamePad)
        {
            if (0x91 < nKey)
            {
                if (nKey < 0xa2)
                {
                    NiInputGamePad::Button eButton = (NiInputGamePad::Button)GetGamePadButtonIndex(nKey);
                    if (eButton != NiInputGamePad::NIGP_NONE)
                    {
                        bDown = m_spGamePad->ButtonIsDown(eButton);
                        return bDown;
                    }
                }
                else if (nKey < 0xb3)
                {
                    int nAxis = 0;
                    switch (nKey)
                    {
                    case 0xa3:
                        nAxis = m_spGamePad->GetStickAxisValue(0x10001);
                        return nAxis < 0;
                    case 0xa4:
                        nAxis = m_spGamePad->GetStickAxisValue(0x10001);
                        return 0 < nAxis;
                    case 0xa5:
                        nAxis = m_spGamePad->GetStickAxisValue(0x10002);
                        return nAxis < 0;
                    case 0xa6:
                        nAxis = m_spGamePad->GetStickAxisValue(0x10002);
                        return 0 < nAxis;
                    case 0xa7:
                        nAxis = m_spGamePad->GetStickAxisValue(0x20001);
                        return nAxis < 0;
                    case 0xa8:
                        nAxis = m_spGamePad->GetStickAxisValue(0x20001);
                        return 0 < nAxis;
                    case 0xa9:
                        nAxis = m_spGamePad->GetStickAxisValue(0x20002);
                        return nAxis < 0;
                    case 0xaa:
                        nAxis = m_spGamePad->GetStickAxisValue(0x20002);
                        return 0 < nAxis;
                    case 0xb3:
                        return false;
                    }
                }
            }
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x140D8C920, MS2InputService, IsKeyDown, 975, 0xF3BA13B0);

// @0x140d8cd50
bool MS2InputService::WasKeyPressed(int nKey)
{
    if (nKey == 0 || nKey == -1)
        return false;
    int nKb = GetKeyboardCode(nKey);
    int nMouse = GetMouseButtonIndex(nKey);
    if (nKb != 0)
    {
        if (m_spKeyboard)
            return m_spKeyboard->KeyWasPressed((NiInputKeyboard::KeyCode)nKb);
    }
    else if (nMouse != -1)
    {
        if (m_spMouse)
            return m_spMouse->ButtonWasPressed((NiInputMouse::Button)nMouse);
    }
    else
    {
        if (m_spGamePad)
        {
            if (0x91 < nKey)
            {
                if (nKey < 0xa2)
                {
                    NiInputGamePad::Button eButton = (NiInputGamePad::Button)GetGamePadButtonIndex(nKey);
                    if (eButton != NiInputGamePad::NIGP_NONE)
                    {
                        if (m_spGamePad->ButtonWasPressed(eButton))
                            return true;
                        return false;
                    }
                }
                else if (nKey < 0xb3)
                {
                    int nAxis = 0;
                    switch (nKey)
                    {
                    case 0xa3:
                        if (m_spGamePad->GetStickAxisLastValue(0x10001) == 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x10001);
                            return nAxis < 0;
                        }
                        return false;
                    case 0xa4:
                        if (m_spGamePad->GetStickAxisLastValue(0x10001) == 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x10001);
                            return 0 < nAxis;
                        }
                        return false;
                    case 0xa5:
                        if (m_spGamePad->GetStickAxisLastValue(0x10002) == 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x10002);
                            return nAxis < 0;
                        }
                        return false;
                    case 0xa6:
                        if (m_spGamePad->GetStickAxisLastValue(0x10002) == 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x10002);
                            return 0 < nAxis;
                        }
                        return false;
                    case 0xa7:
                        if (m_spGamePad->GetStickAxisLastValue(0x20001) == 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x20001);
                            return nAxis < 0;
                        }
                        return false;
                    case 0xa8:
                        if (m_spGamePad->GetStickAxisLastValue(0x20001) == 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x20001);
                            return 0 < nAxis;
                        }
                        return false;
                    case 0xa9:
                        if (m_spGamePad->GetStickAxisLastValue(0x20002) == 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x20002);
                            return nAxis < 0;
                        }
                        return false;
                    case 0xaa:
                        if (m_spGamePad->GetStickAxisLastValue(0x20002) == 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x20002);
                            return 0 < nAxis;
                        }
                        return false;
                    case 0xb3:
                        return false;
                    }
                }
            }
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x140D8CD50, MS2InputService, WasKeyPressed, 1318, 0xA9F64406);

// @0x140d8d2d0
bool MS2InputService::WasKeyReleased(int nKey)
{
    if (nKey == 0 || nKey == -1)
        return false;
    int nKb = GetKeyboardCode(nKey);
    int nMouse = GetMouseButtonIndex(nKey);
    if (nKb != 0)
    {
        if (m_spKeyboard)
            return m_spKeyboard->KeyWasReleased((NiInputKeyboard::KeyCode)nKb);
    }
    else if (nMouse != -1)
    {
        if (m_spMouse)
            return m_spMouse->ButtonWasReleased((NiInputMouse::Button)nMouse);
    }
    else
    {
        if (m_spGamePad)
        {
            if (0x91 < nKey)
            {
                if (nKey < 0xa2)
                {
                    NiInputGamePad::Button eButton = (NiInputGamePad::Button)GetGamePadButtonIndex(nKey);
                    if (eButton != NiInputGamePad::NIGP_NONE)
                        return m_spGamePad->ButtonWasReleased(eButton);
                }
                else if (nKey < 0xb3)
                {
                    int nAxis = 0;
                    switch (nKey)
                    {
                    case 0xa3:
                        if (m_spGamePad->GetStickAxisLastValue(0x10001) < 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x10001);
                            return nAxis == 0;
                        }
                        return false;
                    case 0xa4:
                        if (0 < m_spGamePad->GetStickAxisLastValue(0x10001))
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x10001);
                            return nAxis == 0;
                        }
                        return false;
                    case 0xa5:
                        if (m_spGamePad->GetStickAxisLastValue(0x10002) < 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x10002);
                            return nAxis == 0;
                        }
                        return false;
                    case 0xa6:
                        if (0 < m_spGamePad->GetStickAxisLastValue(0x10002))
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x10002);
                            return nAxis == 0;
                        }
                        return false;
                    case 0xa7:
                        if (m_spGamePad->GetStickAxisLastValue(0x20001) < 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x20001);
                            return nAxis == 0;
                        }
                        return false;
                    case 0xa8:
                        if (0 < m_spGamePad->GetStickAxisLastValue(0x20001))
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x20001);
                            return nAxis == 0;
                        }
                        return false;
                    case 0xa9:
                        if (m_spGamePad->GetStickAxisLastValue(0x20002) < 0)
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x20002);
                            return nAxis == 0;
                        }
                        return false;
                    case 0xaa:
                        if (0 < m_spGamePad->GetStickAxisLastValue(0x20002))
                        {
                            nAxis = m_spGamePad->GetStickAxisValue(0x20002);
                            return nAxis == 0;
                        }
                        return false;
                    case 0xb3:
                        return false;
                    }
                }
            }
        }
    }
    return false;
}
MS2_REPLACE_METHOD(0x140D8D2D0, MS2InputService, WasKeyReleased, 1302, 0x9158B018);

// @0x140d8d840
bool MS2InputService::InjectSingleKeyPress(int nKey)
{
    if (nKey == 0 || nKey == -1)
        return false;
    int nKb = GetKeyboardCode(nKey);
    if (nKb != 0)
    {
        if (m_spKeyboard)
            m_spKeyboard->RecordKeyPress((NiInputKeyboard::KeyCode)nKb);
    }
    else
    {
        if (m_spGamePad)
        {
            if (0x91 < nKey)
            {
                if (nKey < 0xa2)
                {
                    NiInputGamePad::Button eButton = (NiInputGamePad::Button)GetGamePadButtonIndex(nKey);
                    if (eButton != NiInputGamePad::NIGP_NONE)
                    {
                        m_spGamePad->RecordButtonPress(eButton, 0xff);
                        return true;
                    }
                }
                else if (nKey < 0xb3)
                {
                    switch (nKey)
                    {
                    case 0xa3:
                        m_spGamePad->SetRawAxisValue(0x10001, -0x7f);
                        return true;
                    case 0xa4:
                        m_spGamePad->SetRawAxisValue(0x10001, 0x7f);
                        return true;
                    case 0xa5:
                        m_spGamePad->SetRawAxisValue(0x10002, -0x7f);
                        return true;
                    case 0xa6:
                        m_spGamePad->SetRawAxisValue(0x10002, 0x7f);
                        return true;
                    case 0xa7:
                        m_spGamePad->SetRawAxisValue(0x20001, -0x7f);
                        return true;
                    case 0xa8:
                        m_spGamePad->SetRawAxisValue(0x20001, 0x7f);
                        return true;
                    case 0xa9:
                        m_spGamePad->SetRawAxisValue(0x20002, -0x7f);
                        return true;
                    case 0xaa:
                        m_spGamePad->SetRawAxisValue(0x20002, 0x7f);
                        return true;
                    case 0xb3:
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x140D8D840, MS2InputService, InjectSingleKeyPress, 660, 0x6A0E4DB8);

// @0x140d8db30
bool MS2InputService::InjectSingleKeyRelease(int nKey)
{
    if (nKey == 0 || nKey == -1)
        return false;
    int nKb = GetKeyboardCode(nKey);
    if (nKb != 0)
    {
        if (m_spKeyboard)
            m_spKeyboard->RecordKeyRelease((NiInputKeyboard::KeyCode)nKb);
    }
    else
    {
        if (m_spGamePad)
        {
            if (0x91 < nKey)
            {
                if (nKey < 0xa2)
                {
                    NiInputGamePad::Button eButton = (NiInputGamePad::Button)GetGamePadButtonIndex(nKey);
                    if (eButton != NiInputGamePad::NIGP_NONE)
                    {
                        m_spGamePad->RecordButtonRelease(eButton);
                        return true;
                    }
                }
                else if (nKey < 0xb3)
                {
                    switch (nKey)
                    {
                    case 0xa3:
                        m_spGamePad->SetRawAxisValue(0x10001, 0);
                        return true;
                    case 0xa4:
                        m_spGamePad->SetRawAxisValue(0x10001, 0);
                        return true;
                    case 0xa5:
                        m_spGamePad->SetRawAxisValue(0x10002, 0);
                        return true;
                    case 0xa6:
                        m_spGamePad->SetRawAxisValue(0x10002, 0);
                        return true;
                    case 0xa7:
                        m_spGamePad->SetRawAxisValue(0x20001, 0);
                        return true;
                    case 0xa8:
                        m_spGamePad->SetRawAxisValue(0x20001, 0);
                        return true;
                    case 0xa9:
                        m_spGamePad->SetRawAxisValue(0x20002, 0);
                        return true;
                    case 0xaa:
                        m_spGamePad->SetRawAxisValue(0x20002, 0);
                        return true;
                    case 0xab:
                        m_spGamePad->SetRawAxisValue(0x40001, 0);
                        return true;
                    case 0xac:
                        m_spGamePad->SetRawAxisValue(0x40001, 0);
                        return true;
                    case 0xad:
                        m_spGamePad->SetRawAxisValue(0x40002, 0);
                        return true;
                    case 0xae:
                        m_spGamePad->SetRawAxisValue(0x40002, 0);
                        return true;
                    case 0xaf:
                        m_spGamePad->SetRawAxisValue(0x80001, 0);
                        return true;
                    case 0xb0:
                        m_spGamePad->SetRawAxisValue(0x80001, 0);
                        return true;
                    case 0xb1:
                        m_spGamePad->SetRawAxisValue(0x80002, 0);
                        return true;
                    case 0xb2:
                        m_spGamePad->SetRawAxisValue(0x80002, 0);
                        return true;
                    case 0xb3:
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
MS2_REPLACE_METHOD(0x140D8DB30, MS2InputService, InjectSingleKeyRelease, 966, 0xB37FADFE);
