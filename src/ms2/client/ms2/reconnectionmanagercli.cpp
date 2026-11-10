// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Client reconnect state machine.
// MS2-UNIT: client\ms2\reconnectionmanagercli.cpp
// MS2-RANGE: 0x1400c5120-0x1400c51d1 .text$di
// MS2-RANGE: 0x140aace60-0x140aadfe4 .text$mn
// MS2-RANGE: 0x142c9fb40-0x142c9fb67 .text$yd
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\reconnectionmanagercli.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "reconnectionmanagercli.h"
#include "networkservice.h"
#include "gamesocket.h"
#include "uiobject.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/client/ms2/networkservice.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/placeholder/formatstringid.h"   // C3: FormatStringId<int> calls FUN_14028dee0
#include <egf/Entity.h>
#include "ms2/client/ms2/statemanager.h"
#include "ms2/guess/machineidmanager.h"
#include "ms2/commonfiles/timeutil.h"
#include <efd/Win32/Win32PlatformService.h>
#include "ms2/client/ms2/windowservice.h"  // C3: TSingleton<CWindowService>::s_instance

// Header static string table (7 names) that this TU instantiates; no use here.
static CString s_shopSort[] = {"None", "Buy", "Like", "PriceLow", "PriceHigh", "Create", "EnumEnd"};

extern int DAT_143af7d44, g_socketClosing;
extern __int64 DAT_143ab2820, DAT_143ab2828;
CReconnectionManagerCli* TSingleton<CReconnectionManagerCli>::s_instance = 0;
inline TSingleton<CReconnectionManagerCli>::TSingleton() { s_instance = static_cast<CReconnectionManagerCli*>(this); }

// RTTI-only: this unit calls two of its own virtual slots.
class UIReconnectTopLayerNotify : public UIObject {
public:
    virtual void vfunc_52(int a, int b);
};

class Unk_MachineId { public: CStringW FUN_14067c400() const; };
class Unk_RCUIManager { public: };
// The exe's caller treats 0x1415384e0 as an int-returning function (no movzx after the call).
CNetworkService* FUN_140714f90();
void* FUN_140aadf70();
void* FUN_140aadf80();
UIReconnectTopLayerNotify* FUN_140aade00(int id);
void FUN_140d73aa0(CStringW, int, void*, CStringW);
void FUN_1412751f0(const CStringW&, int, int);

// @0x140aace60
CReconnectionManagerCli::CReconnectionManagerCli() : m_08(0) {
}

// @0x140aacee0
CReconnectionManagerCli::~CReconnectionManagerCli() {
}

// @0x140aacf50
bool CReconnectionManagerCli::ShouldReconnect(int error) {
    if (!(TSingleton<CStateService>::GetInstance() != 0 && TSingleton<CStateService>::GetInstance()->FUN_1417e2610() == 0x620000c)) return false;
    if (FUN_140714f90() == 0) return false;
    if (FUN_140714f90()->GetSocket().GetDisconnect() != 0) return false;
    if (DAT_143af7d44 == 1) return false;
    if (g_socketClosing == 1) return false;
    if (GetOption(0) == 0) return false;
    if (IsReconnecting() && IsReconnectTimedOut()) return false;
    if (m_context.m_18 != 1) return false;
    switch (error) {
    case 0: break;
    case 0x2745: return true;
    default: return true;
    }
    return false;
}

// @0x140aad050
void CReconnectionManagerCli::SetOptions(const ReconnectionOptions* src) {
    m_options.FUN_140208460(*src);
}
MS2_REPLACE_METHOD(0x140AAD050, CReconnectionManagerCli, SetOptions, 41, 0x9138FC0F);

// @0x140aad080
ReconnectionOptions* CReconnectionManagerCli::GetOptions() {
    return &m_options;
}
MS2_REPLACE_METHOD(0x140AAD080, CReconnectionManagerCli, GetOptions, 15, 0x770B1889);

// @0x140aad0a0
int CReconnectionManagerCli::GetOption(int index) {
    return m_options.FUN_140aadf90(index);
}
MS2_REPLACE_METHOD(0x140AAD0A0, CReconnectionManagerCli, GetOption, 39, 0x7C4E916A);

// @0x140aad0d0
void CReconnectionManagerCli::Reset() {
    m_08 = 0;
    m_context.FUN_1402085c0();
    m_cli.FUN_140208780();
}
MS2_REPLACE_METHOD(0x140AAD0D0, CReconnectionManagerCli, Reset, 62, 0x6CE6D00E);

// @0x140aad120
void CReconnectionManagerCli::SetPending() {
    m_cli.m_pending = true;
}
MS2_REPLACE_METHOD(0x140AAD120, CReconnectionManagerCli, SetPending, 18, 0xFC112093);

// @0x140aad140
void CReconnectionManagerCli::PostPendingReconnect() {
    if (m_cli.m_pending) {
        unsigned deadline = GetOption(8) * 1000 + m_cli.m_lastTick;
        if (deadline < GetTickCountMs2()) {
            PostMessageA(reinterpret_cast<efd::Win32PlatformService*>(FUN_140aadf80())->GetWindowRef(), 0x46b, m_cli.m_postParam, 0);
            m_cli.m_pending = false;
        }
    }
}
MS2_REPLACE_METHOD(0x140AAD140, CReconnectionManagerCli, PostPendingReconnect, 144, 0xD64AFCC7);

// @0x140aad1e0
bool CReconnectionManagerCli::IsReconnecting() {
    return m_cli.m_startTick != 0;
}
MS2_REPLACE_METHOD(0x140AAD1E0, CReconnectionManagerCli, IsReconnecting, 48, 0x3852C998);

// @0x140aad220
bool CReconnectionManagerCli::IsReconnectTimedOut() {
    if (m_cli.m_disabled) return true;
    if (m_cli.m_attempt > m_cli.m_maxAttempts) return true;
    unsigned deadline = GetOption(2) * 1000 + m_cli.m_startTick;
    return deadline < GetTickCountMs2();
}
MS2_REPLACE_METHOD(0x140AAD220, CReconnectionManagerCli, IsReconnectTimedOut, 132, 0x295953E6);

// @0x140aad2b0
int CReconnectionManagerCli::FUN_140aad2b0() {
    return m_cli.m_lastError;
}
MS2_REPLACE_METHOD(0x140AAD2B0, CReconnectionManagerCli, FUN_140aad2b0, 17, 0xBA29CEEF);

// @0x140aad2d0
bool CReconnectionManagerCli::IsFatalReconnectError(int code) {
    switch (code) {
    case 100:
    case 101:
    case 102:
    case 103:
    case 104:
    case 105:
    case 106:
    case 203:
    case 204:
    case 400:
    case 401:
    case 402:
    case 403:
    case 404:
    case 405:
    case 407:
    case 408:
        return true;
    default:
        return false;
    }
}
MS2_REPLACE_METHOD(0x140AAD2D0, CReconnectionManagerCli, IsFatalReconnectError, 101, 0x126FA365);

// @0x140aad340
void CReconnectionManagerCli::BeginReconnect(unsigned code) {
    if (FUN_140714f90() == 0) return;
    m_cli.m_startTick = GetTickCountMs2();
    m_cli.m_attempt = 0;
    m_cli.m_maxAttempts = GetOption(7);
    m_cli.m_postParam = code;
    m_cli.m_session = FUN_140714f90()->GetSocketSequence();
    PostMessageA(reinterpret_cast<efd::Win32PlatformService*>(FUN_140aadf80())->GetWindowRef(), 0x46b, (WPARAM)code, 0);
    ShowProgress(1, m_cli.m_maxAttempts);
    CStringW text(L"[DEBUG] * PreReconnect");
    FUN_1412751f0(text, 1, 1);
}
MS2_REPLACE_METHOD(0x140AAD340, CReconnectionManagerCli, BeginReconnect, 264, 0x7A30D3FA);

// @0x140aad450
bool CReconnectionManagerCli::AttemptReconnect() {
    if (FUN_140714f90() == 0) return false;
    unsigned now = GetTickCountMs2();
    m_cli.m_attempt = m_cli.m_attempt + 1;
    m_cli.m_lastTick = now;
    {
        CStringW text(L"[DEBUG] * Reconnecting...");
        FUN_1412751f0(text, 1, 1);
    }
    ShowProgress(m_cli.m_attempt, m_cli.m_maxAttempts);
    if (m_cli.m_deadline != 0 && (unsigned)m_cli.m_deadline > now) return false;
    int ok = FUN_140714f90()->ConnectTo(CString(m_cli.m_host), m_cli.m_port, 1, 1, 1);
    if (ok == 0) return false;
    return true;
}
MS2_REPLACE_METHOD(0x140AAD450, CReconnectionManagerCli, AttemptReconnect, 358, 0x221EB435);

// @0x140aad5c0
void CReconnectionManagerCli::OnReconnectResult(int ok) {
    HideProgress();
    if (ok == 1) {
        m_cli.m_attempt = 0;
        m_cli.m_maxAttempts = 0;
        m_cli.m_postParam = 0;
        m_cli.m_session = 0;
        m_cli.m_pending = false;
        m_cli.m_lastError = 0;
        m_cli.m_startTick = 0;
        m_cli.m_lastTick = 0;
        CStringW text(L"[DEBUG] * PostReconnect. succeed");
        FUN_1412751f0(text, 1, 1);
    } else {
        CStringW text(L"[DEBUG] !!! PostReconnect. failed");
        FUN_1412751f0(text, 1, 1);
    }
}
MS2_REPLACE_METHOD(0x140AAD5C0, CReconnectionManagerCli, OnReconnectResult, 271, 0x3FCE6E1F);

// @0x140aad6e0
void CReconnectionManagerCli::OnReconnectFailed(int error) {
    {
        CStringW text(L"[DEBUG] !! ReconnectFailed");
        FUN_1412751f0(text, 1, 1);
    }
    m_cli.m_lastError = error;
    if (IsFatalReconnectError(error) == 1 || IsReconnectTimedOut() == 1) {
        HideProgress();
        if (FUN_140714f90() != 0) {
            if (reinterpret_cast<CNetworkService*>(FUN_140714f90())->IsConnected() != 0) {
                FUN_140714f90()->Close();
            }
        }
        PostMessageA(reinterpret_cast<efd::Win32PlatformService*>(FUN_140aadf80())->GetWindowRef(), 0x465, (WPARAM)m_cli.m_postParam, 0);
    } else {
        SetPending();
    }
}
MS2_REPLACE_METHOD(0x140AAD6E0, CReconnectionManagerCli, OnReconnectFailed, 251, 0xCC066A0F);

// @0x140aad7f0
void CReconnectionManagerCli::SendReconnectRequest() {
    CStringW name = reinterpret_cast<Unk_MachineId*>(reinterpret_cast<CMachineIDManager*>(FUN_140aadf70())->GetID())->FUN_14067c400();
    COutPacket packet(static_cast<int>(SendOp::Reconnect), 0);
    packet.WriteUInt8(1);
    packet.WriteInt64(DAT_143ab2820);
    packet.WriteInt64(DAT_143ab2828);
    packet.WriteInt32(m_cli.m_attempt);
    packet.WriteInt32(m_cli.m_session);
    packet.WriteUnicodeString(name);
    m_context.FUN_140208610(packet);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140AAD7F0, CReconnectionManagerCli, SendReconnectRequest, 236, 0xA06EF1BE);

// @0x140aad8f0
void CReconnectionManagerCli::DisableReconnect() {
    m_cli.m_disabled = true;
}
MS2_REPLACE_METHOD(0x140AAD8F0, CReconnectionManagerCli, DisableReconnect, 18, 0xDEC0E05B);

// @0x140aad910
void CReconnectionManagerCli::ShowProgress(int a, int b) {
    UIReconnectTopLayerNotify* ui = FUN_140aade00(0x4f78);
    if (ui != 0) {
        ui->vfunc_2();
        ui->vfunc_52(a, b);
    }
}
MS2_REPLACE_METHOD(0x140AAD910, CReconnectionManagerCli, ShowProgress, 90, 0x47078FC4);

// @0x140aad970
void CReconnectionManagerCli::HideProgress() {
    UIReconnectTopLayerNotify* ui = FUN_140aade00(0x4f78);
    if (ui != 0) {
        ui->vfunc_3();
    }
}
MS2_REPLACE_METHOD(0x140AAD970, CReconnectionManagerCli, HideProgress, 53, 0xA618BCD8);

// @0x140aad9b0
void CReconnectionManagerCli::DisconnectAndDelayReconnect(int seconds) {
    m_cli.m_deadline = GetTickCountMs2() + seconds * 1000;
    FUN_140714f90()->Close();
    PostMessageA(reinterpret_cast<efd::Win32PlatformService*>(FUN_140aadf80())->GetWindowRef(), 0x465, 0x2745, 0);
}
MS2_REPLACE_METHOD(0x140AAD9B0, CReconnectionManagerCli, DisconnectAndDelayReconnect, 93, 0x25593940);

// @0x140aada20
void CReconnectionManagerCli::OnReconnectPacket(CInPacket* packet) {
    int kind = packet->ReadUInt8();
    switch (kind) {
    case 0: {
        int mode = packet->ReadInt32();
        CString host = packet->ReadString();
        int port = packet->ReadInt32();
        m_context.m_18 = mode;
        m_context.m_20 = host;
        m_context.m_28 = port;
        m_cli.m_host = FUN_140714f90()->GetSocket().GetHost();
        m_cli.m_port = FUN_140714f90()->GetSocket().GetPort();
    }
        break;
    case 2: {
        int result = packet->ReadInt32();
        switch (result) {
        case 1:
            if (TSingleton<CStateService>::GetInstance() != 0 && TSingleton<CStateService>::GetInstance()->FUN_1417e2610() == 0x620000c) {
                OnReconnectResult(1);
            } else {
                OnReconnectFailed(0xcc);
            }
            break;
        default:
            OnReconnectFailed(result);
            break;
        }
    }
        break;
    case 3:
        Reset();
        if (TSingleton<CStateService>::GetInstance() != 0) {
            if (TSingleton<CStateService>::GetInstance()->FUN_1417e2610() == 0x620000c) {
                FUN_140714f90()->SendRequestQuitAndDisconnect();
                TSingleton<CStateService>::GetInstance()->FUN_1417e25a0(0x6200009);
                FUN_140d73aa0(FormatStringId<int>(0x20f, 0), 0, 0, CStringW(L""));
            }
        }
        break;
    }
}
MS2_REPLACE_METHOD(0x140AADA20, CReconnectionManagerCli, OnReconnectPacket, 834, 0x633CEC99);

// @0x140aadd70
void CReconnectionManagerCli::Tick() {
    unsigned now = GetTickCountMs2();
    if (m_08 != 0 && (unsigned)(m_08 + 1000) > now) return;
    m_08 = now;
    if (IsReconnecting() == true && IsReconnectTimedOut()) {
        OnReconnectFailed(0xc9);
    } else {
        PostPendingReconnect();
    }
}
MS2_REPLACE_METHOD(0x140AADD70, CReconnectionManagerCli, Tick, 129, 0x7EEBCA39);

// @0x140aade00
UIReconnectTopLayerNotify* FUN_140aade00(int id) {
    if (reinterpret_cast<Unk_RCUIManager*>(TSingleton<CUIService>::GetInstance())) {
        MS2Ptr<UIObject> p = TSingleton<CUIService>::GetInstance()->FindObject((eUIClassID)id);
        if (p.get()) {
            return dynamic_cast<UIReconnectTopLayerNotify*>((UIObject*)p);
        }
    }
    return 0;
}
MS2_REPLACE(0x140AADE00, FUN_140aade00, 147, 0x8BBE3F9F);

// @0x140aadf70
void* FUN_140aadf70() {
    return TSingleton<CMachineIDManager>::s_instance;
}

// @0x140aadf80
void* FUN_140aadf80() {
    return TSingleton<CWindowService>::s_instance;
}

// @0x140aadf90
int ReconnectionOptions::FUN_140aadf90(int index) {
    if (index < 0 || index >= 11) {
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\clientreconnectionstructs.h"
        MS2_ASSERT_AT(0xa4, FALSE);
#undef MS2_THIS_FILE
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\reconnectionmanagercli.cpp"
        return 0;
    }
    return m_values[index];
}
