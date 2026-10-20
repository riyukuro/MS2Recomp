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
    virtual void vfunc_63(int,int,int);
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
Unk_NetworkCallbacks* FUN_140d86260();
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
    int FUN_1415382c0();
    int FUN_1415383a0(CString,int,int,int,int);
    void FUN_141538480(int);
    int FUN_1415384e0(); void FUN_141538510(); void FUN_141538540();
    bool FUN_141538600(class CItem*);
    void FUN_141538cb0(); bool FUN_141538d50();
    bool FUN_1415395a0(int,const class CMsgBoxData&);
    void FUN_141538570(); void FUN_1415385a0(); int FUN_1415385d0();
    void FUN_141538820(); void FUN_1415388a0();
    void FUN_141538930(__int64,int); void FUN_1415389b0(__int64); void FUN_141538a20(__int64);
    void FUN_141538a90(__int64,__int64); void FUN_141538b10(int);
    void FUN_141538bb0(CStringW,int); void FUN_141538c40(int,int);
    unsigned FUN_141538f20(); unsigned FUN_141538f40(); unsigned FUN_141538f60();
    void FUN_141538f80(); void FUN_141539130(); bool FUN_141539180();
    int FUN_141539210(); void FUN_141539230(); void FUN_141539260(); CGameSocket& FUN_1415392c0();
    void FUN_1415392e0(); const float* FUN_141539330(); const float* FUN_141539380();
    void FUN_141539630(); void FUN_1415396b0(Unk_InPtr); void FUN_1415397d0(CInPacket&);
    void FUN_14153a020(COutPacket&); void FUN_14153a1d0(unsigned,unsigned); void FUN_14153a210(int); int FUN_14153a230();
    void FUN_14153a250();
    void FUN_14153ad10(CInPacket&);
    void FUN_14153af70(CInPacket&);
    void FUN_14153af40(CInPacket&);
    void FUN_14153b010(CInPacket&);
    bool FUN_14153b1c0(CInPacket&);
    void FUN_14153b220(CInPacket&);
    void FUN_14153b2d0(CInPacket&);
    void FUN_14153b310(CInPacket&);
    void FUN_14153c670(CInPacket&);
    void FUN_14153b440(CInPacket&);
    void FUN_14153b570(CInPacket&);
    void FUN_14153bc00(CInPacket&);
    void FUN_14153be30(CInPacket&);
    void FUN_14153a380(CInPacket&);
    void FUN_14153a2e0(CInPacket&);
    void FUN_14153a780(CInPacket&);
    void FUN_14153a820(CInPacket&);
    void FUN_14153a8f0(CInPacket&);
    void FUN_14153c0c0(CInPacket&);
    void FUN_14153c4b0(CInPacket&);
    void FUN_14153e050(CInPacket&);
    void FUN_14153e0d0(CInPacket&);
    void FUN_14153e150(CInPacket&);
    void FUN_14153b3b0(CInPacket&);
    void FUN_14153e180(CInPacket&);
    void FUN_14153e280(CInPacket&);
    void FUN_14153f6c0(CInPacket&);
    void FUN_14153a8a0(CInPacket&);
    void FUN_14153f8c0(CInPacket&);
    void FUN_14153f9d0(CInPacket&);
    void FUN_14153fa20(CInPacket&);
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
