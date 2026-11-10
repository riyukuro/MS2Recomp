// CNetworkService from RTTI; helper and field names inferred from the exe.
#pragma once
#define EE_EFD_CONFIG_RELEASE
#define EE_EFD_NO_IMPORT
#define EE_USE_NATIVE_STL
#include "gamesocket.h"
#include <efd/ISystemService.h>
#include "ms2/commonfiles/os.h"
#include <queue>
#include "ms2/placeholder/ascript.h"
class CUserReportData;
class Unk_NetworkCallbacks {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual int vfunc_2();                                  // 1: the screenshot upload is offered (uiugcitemeditdialog)
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(__int64);
    virtual void vfunc_22(int,const char*,...);
    virtual void vfunc_23(int,const char*,...);
    virtual void vfunc_24();
    virtual void vfunc_25(CInPacket&);
    virtual void vfunc_26(CInPacket&);
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32(CInPacket&);
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38(CInPacket&);
    virtual void vfunc_39();
    virtual bool vfunc_40(__int64 nCharacterId);   // uicommon.cpp: character is on the block list
    virtual bool vfunc_41(__int64 nCharacterId);   // uicommon.cpp: character is a friend / contact
    virtual void vfunc_42(CInPacket&);
    virtual void vfunc_43(int nA, int nB, int nC);   // 0x158 (uiugcbannerdialog.cpp: (0xe, 0, 1000))
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48(MS2Ptr<CUserReportData> spReport);   // uicommon.cpp: send a user report (callee releases the reference)
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55(float fHpPercent);   // 0x1b8: scenestategame 0x2e passes the hp percentage
    virtual void vfunc_56(int nMode);           // 0x1c0: scenestategame 0x21 passes the mode byte
    virtual void vfunc_57();
    virtual void vfunc_58(int,int);
    virtual void vfunc_59(int);
    virtual void vfunc_60(int);
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63(bool,int,int);
    virtual void vfunc_64(int nValue);   // 0x200: usercommandcli's 'hide' command calls it with the parsed int (sb2)
    virtual void vfunc_65();
    virtual void vfunc_66();
    virtual void vfunc_67();
    virtual void vfunc_68();
    virtual void vfunc_69();
    virtual void vfunc_70();
    virtual void vfunc_71();
    virtual void vfunc_72();
    virtual void vfunc_73();
    virtual void vfunc_74();
    virtual CStringA vfunc_75();   // 0x258: npsman.cpp reads a survey-url string (hidden-return slot)
};
class IClientPlatform* GetClientPlatform();   // the client platform (0x140d86260, ms2actormanager.cpp; C3: was void* FUN_140d86260())
#define FUN_140d86260() (static_cast<Unk_NetworkCallbacks*>(static_cast<void*>(GetClientPlatform())))   // read as the Unk_NetworkCallbacks view
struct Unk_NetworkLatency {
    Unk_NetworkLatency();
    void Reset(); void Clear(); void Sent(unsigned sequence); void Received(unsigned sequence);
    CLockCriticalSection lock;
    ATL::CRBMap<unsigned,unsigned> sent,samples;
    unsigned minimum,maximum,average;
};
MS2_CHECK_SIZE(Unk_NetworkLatency,0xa0);
MS2_CHECK_OFFSET(Unk_NetworkLatency,minimum,0x90);
class CNetworkService;
template<> class TSingleton<CNetworkService> {
public:
    TSingleton();
    virtual ~TSingleton() { s_instance=0; }
    static CNetworkService* s_instance;
};
class CNetworkService : public efd::ISystemService,public TSingleton<CNetworkService> {
    EE_DECLARE_CLASS1(CNetworkService,0x06100008,efd::ISystemService);
    EE_DECLARE_CONCRETE_ATOMIC_REFCOUNT;
public:
    CNetworkService(); virtual ~CNetworkService();
    const char* GetDisplayName() const override;
    efd::SyncResult OnPreInit(efd::IDependencyRegistrar*) override;
    efd::AsyncResult OnInit() override;
    efd::AsyncResult OnTick() override;
    efd::AsyncResult OnShutdown() override;
    int ConnectToConfiguredServer();
    int ConnectTo(CString,int,int,int,int);
    void Reconnect(int);
    int IsConnected(); void Close(); void FUN_141538540();
    BOOL SendRetrieveFurnishingItem(class CItem*);
    void SendResponseVersion(); bool SendPatchFileList();
    bool OnFoundersMsgBoxResult(int,const class CMsgBoxData&);
    void FUN_141538570(); void FUN_1415385a0(); int GetSocketSequence();
    void SendRequestQuit(); void SendRequestQuitAndDisconnect();
    void SendRequestItemInventoryMode4(__int64,int); void SendRequestItemInventoryMode5(__int64); void SendRequestItemStorage(__int64);
    void SendFittingDoll(__int64,__int64); void SendRecallUserReply(int);
    void SendRecallUserText(CStringW,int); void SendSystemShop(int,int);
    unsigned GetMinLatency(); unsigned GetMaxLatency(); unsigned GetAverageLatency();
    void ProcessReceivedPackets(); void SaveServerAddress(); int RestoreServerAddress();
    int GetConnectionCount(); void IncrementConnectionCount(); void SendServerEnter(); CGameSocket& GetSocket();
    void UpdateLogger(); const float* GetSendRate(); const float* GetReceiveRate();
    void ClearReceiveQueue(); void QueueReceivedPacket(Unk_InPtr); void DispatchPacket(CInPacket&);
    void SendPacket(COutPacket&); void FUN_14153a1d0(unsigned,unsigned); void SetConnectionState(int); int GetConnectionState();
    void SendTimeSyncRequest();
    void OnRequestVersion(CInPacket&);
    void OnVersionResult(CInPacket&);
    void OnDataPatch(CInPacket&);
    void OnRequestKey(CInPacket&);
    void OnReconnect(CInPacket&);
    void OnPingRequest(CInPacket&);
    void OnReconnectUnk(CInPacket&);
    void OnRetransmitRequest(CInPacket&);
    void OnLoginResult(CInPacket&);
    void OnMoveResult(CInPacket&);
    void OnLoginToGame(CInPacket&);
    void OnGameToLogin(CInPacket&);
    void OnGameToGame(CInPacket&);
    void OnTimeSyncResponse(CInPacket&);
    void OnHeartbeatRequest(CInPacket&);
    void OnRequestClientTickSync(CInPacket&);
    void OnSyncNumber(CInPacket&);
    void OnGvg(CInPacket&);
    void OnRelocateWorld(CInPacket&);
    void OnDynamicChannel(CInPacket&);
    void OnCharMaxCount(CInPacket&);
    void OnNpsInfo(CInPacket&);
    void OnAaErr(CInPacket&);
    void OnBypassKey(CInPacket&);
    void OnRoomStageDungeon(CInPacket&);
    void OnBuddyEmote(CInPacket&);
    void OnBuddyBadge(CInPacket&);
    void OnWorldTimeSync(CInPacket&);
    void FUN_14153f8c0(CInPacket&);
    void OnDynamicBanWords(CInPacket&);
    void OnSystemInfoRequest(CInPacket&);
    void FUN_14153fae0(CInPacket&);
private:
    MS2_LAYOUT_FRIEND;
    Unk_NetworkLatency m_latency;
    LONG m_pingSequence;
    CGameSocket m_socket;
    int m_connectionState,m_connectionCount;
    CLockCriticalSection m_receiveLock;
    ATL::CAtlList<Unk_InPtr> m_received;
    ATL::CAtlList<DWORD> m_receiveTimes; // DWORD: distinct from the packet unit's CAtlList<unsigned> copy (0x140203150)
    std::queue<std::pair<unsigned,COutPacket*>> m_sends;
    unsigned m_sendMin,m_sendMax,m_receiveMin,m_receiveMax;
};
MS2_CHECK_SIZE(CNetworkService,0x350);
MS2_CHECK_OFFSET(CNetworkService,m_latency,0x28);
MS2_CHECK_OFFSET(CNetworkService,m_socket,0xd0);
MS2_CHECK_OFFSET(CNetworkService,m_receiveLock,0x288);
MS2_CHECK_OFFSET(CNetworkService,m_received,0x2b8);
MS2_CHECK_OFFSET(CNetworkService,m_sends,0x318);
MS2_CHECK_OFFSET(CNetworkService,m_sendMin,0x340);
