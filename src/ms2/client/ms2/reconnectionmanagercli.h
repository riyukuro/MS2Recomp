// CReconnectionManagerCli: client reconnect state machine over the game socket. Names except RTTI inferred.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/reconnectionstructs.h"
#include "ms2/placeholder/cinpacket.h"
class CReconnectionManagerCli;
// This instantiation stores the complete object pointer (same shape as TSingleton<CNetworkService>); DAT_143ab8aa0.
template<> class TSingleton<CReconnectionManagerCli> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance = 0; }
    static CReconnectionManagerCli* s_instance;
    static CReconnectionManagerCli* GetInstance();      // 0x140e800e0
};
class UIReconnectTopLayerNotify;
class CReconnectionManagerCli : public TSingleton<CReconnectionManagerCli> {
public:
    CReconnectionManagerCli();                              // 0x140aace60
    virtual ~CReconnectionManagerCli();                     // 0x140aacee0
    bool ShouldReconnect(int error);
    void SetOptions(const ReconnectionOptions* src);
    ReconnectionOptions* GetOptions();
    int GetOption(int index);
    void Reset();
    void SetPending();
    void PostPendingReconnect();
    bool IsReconnecting();
    bool IsReconnectTimedOut();
    int FUN_140aad2b0();
    bool IsFatalReconnectError(int code);
    void BeginReconnect(unsigned code);
    bool AttemptReconnect();
    void OnReconnectResult(int ok);
    void OnReconnectFailed(int error);
    void SendReconnectRequest();
    void DisableReconnect();
    void ShowProgress(int a, int b);
    void HideProgress();
    void DisconnectAndDelayReconnect(int seconds);
    void OnReconnectPacket(CInPacket* packet);
    void Tick();
private:
    MS2_LAYOUT_FRIEND;
    int m_08;
    ReconnectionOptions m_options;                          // +0x10
    ReconnectionContext m_context;                          // +0x58
    ReconnectionContextCli m_cli;                           // +0x88
};
MS2_CHECK_SIZE(CReconnectionManagerCli, 0xd8);
