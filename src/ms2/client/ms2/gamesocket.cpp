// Recovered client socket callbacks, packet assembly and event worker.
// MS2-UNIT: client\ms2\gamesocket.cpp
// MS2-RANGE: 0x1400eadb0-0x1400eaed0 .text$di
// MS2-RANGE: 0x1412646a0-0x14126d170 .text$mn
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\gamesocket.cpp"
#define _WINSOCKAPI_
#include <afx.h>
#include <winsock2.h>
#include "ms2/placeholder/ms2stdafx.h"
#include "gamesocket.h"
#include "ms2/placeholder/exception.h"
#include "ms2/client/ms2/uiservice.h"
#include "ms2/client/ms2/bigdatalogsystem.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#pragma comment(lib,"ws2_32.lib")
// The exe passes a null placement argument to New, not the Create argument.
template<> inline CSocketThread* Unk_SocketRef<CSocketThread>::Create(void*) { return static_cast<CSocketThread*>(FUN_1401ba820(New(NULL))); }
// This unit uses the three-argument forwarding formatter at 0x1402bf9a0.
template CString Unk_SocketFormat<CString,unsigned long>(const char*,const CString&,const unsigned long&);
static CStringW s_forceLogin=L"forcelogin";
static CStringW s_gameExit=L"gameexit";
static CString s_marketSort[]={"None","Buy","Like","PriceLow","PriceHigh","Create","EnumEnd"};
class Unk_140659080 { public: void FUN_1401d42d0(); };
extern long g_socketThreads;
long FUN_140298fd0(long*);   // C3: was FUN_140298fd0
// MS2-FUNCTIONAL: equivalent control flow; local temporaries and cleanup code differ.
// @0x141269970
inline long Unk_SocketDecrement(long* p) { return _InterlockedDecrement(p); }
// @0x14126cd90
inline void Unk_SocketThreadAddRef() { FUN_140298fd0(&g_socketThreads); }
// @0x14126ce60
inline void Unk_SocketThreadRelease() { Unk_SocketDecrement(&g_socketThreads); }
template<class T> T Unk_SocketMin(T a,T b) { return a<b?a:b; }
void* FUN_140aadf80(); HWND FUN_14209c720(void*);
class CLogString* GetLogString(); void Unk_AdditionalLog(class CLogString*,int,int,const wchar_t*);
CStringW FUN_14016a730(const char*,int);
void* FUN_140aa6d30(); extern int g_socketClosing;
class CReconnectionManagerCli* FUN_140e800e0();   // C3: was FUN_140e800e0
class CReconnectionManagerCli   // C3: member view for the former free stand-ins
{
public:
    class ReconnectionOptions* FUN_140aad080();
    int FUN_140aad0a0(int);
    bool FUN_140aad1e0();
};
class ReconnectionOptions   // C3: member view for the former free stand-ins
{
public:
    int FUN_140aadf90(int);
};
class CNetworkService* FUN_140714f90();   // C3: was FUN_140714f90
class CNetworkService   // C3: member view for the former free stand-ins
{
public:
    void FUN_14153a1d0(unsigned int, unsigned int);
    void FUN_14153a210(int);
    int GetConnectionState();
};
void FUN_1415396b0(void*,Unk_InPtr);
int Unk_RandomStep(int*);   // C3: was FUN_140768600
void FUN_140710b90(COutPacket*,int,unsigned*);   // no return value (rax is left over)
void FUN_140710870(COutPacket*,ATL::CAtlList<Unk_BufferPtr>*,unsigned,unsigned*,int);
CPacketBuffer* FUN_1407138b0(unsigned,const Unk_SocketNew&);
int FUN_1406516b0();
CStringW FUN_1408116a0(int,const int&);
void FUN_140d73aa0(CStringW,int,void*,CStringW);
void FUN_140d73bc0(int,int,void*,CStringW);
void FUN_1412676a0(int); void FUN_141267720(); void FUN_1412677b0();
class Unk_140d86260 { public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
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
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31(CString,int,int);
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34(COutPacket&);
    virtual int vfunc_35(CInPacket&);
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58(int,int);
};
void* FUN_140d86260();   // C3: was FUN_140d86260
struct Unk_ResponseVersion {
    Unk_ResponseVersion():zero(0),version(0),locale(0),key(0),flag(0) {}
    void FUN_1407a4420(CInputStream&);
    int zero,version,locale,key; bool flag;
};
MS2_CHECK_SIZE(Unk_ResponseVersion,20);
// @0x1412646a0
CGameSocket::CGameSocket():m_packets(10),m_receiveQueue(10),m_sendQueue(10),m_logger(0)
{
    m_state=Unk_SocketState::Closed; m_received=0; m_receiveBuffer=nullptr;
    m_sent=0; m_disconnect=0; m_specialConnect=0; m_retryPort=0; m_showErrors=0;
    m_sendQueue.RemoveAll(); m_packets.RemoveAll(); m_receiveQueue.RemoveAll();
    m_out=new COutPacketBuffer; m_logger=new CPacketLogger; m_logger->Configure(true,true,false);
}
// @0x141264960
CGameSocket::~CGameSocket() { FUN_141265850(); }
// @0x141264a70
void CGameSocket::vfunc_1(CSimpleSocket*,int error)
{
    Unk_LockGuard guard(m_lock);
    if(guard!=0) {} else {
        if(error==0) {
            if(m_specialConnect) {
                int result=-1,last=-1; char buffer[1024];
                for(int i=0;i<50;++i) { Sleep(100); result=recv(m_socket,buffer,0,MSG_PEEK);  /* exe: len 0, flags 2 (peek); a consuming recv ate the server hello and stalled login */ if(result==-1 && (last=WSAGetLastError())==WSAEWOULDBLOCK) continue; break; }
                if(result==-1) {
                    if(last==WSAECONNRESET || last==WSAECONNABORTED) { PostMessageA(FUN_14209c720(FUN_140aadf80()),0x46a,0,0); return; }
                    else { ((class Unk_140d86260*)FUN_140d86260())->vfunc_31(m_host,m_port,error); FUN_141266500(error); return; }
                }
            }
            m_state=Unk_SocketState::Connected;
            CString text=Unk_SocketFormat("Socket Connected {0} {1}",m_host,m_port);
            Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730(text,0));
        } else { ((class Unk_140d86260*)FUN_140d86260())->vfunc_31(m_host,m_port,error); FUN_141266500(error); }
    }
}
MS2_REPLACE_METHOD(0x141264a70, CGameSocket, vfunc_1, 846, 0x028ED379);
// MS2-FUNCTIONAL: equivalent control flow; local temporaries and cleanup code differ.
// @0x141264dd0
void CGameSocket::vfunc_2(CSimpleSocket*,int error)
{
    try {
        if(error) throw Exception(error);
        for(;;) {
            {
                Unk_LockGuard guard(m_lock);
                if(guard!=0) {} else {
                    m_state=Unk_SocketState::Connected;
                    if(m_receiveBuffer==NULL || m_receiveBuffer->GetSize()==m_received) {
                        m_receiveBuffer=FUN_1407138b0(0x5b4,Unk_SocketNew(0)); m_received=0;
                    }
                    int received=0;
                    int result=recv(m_socket,m_receiveBuffer.get()->FUN_140713530()+(unsigned)m_received,m_receiveBuffer->GetSize()-m_received,0);
                    if(result==SOCKET_ERROR) { int last=WSAGetLastError(); if(last!=WSAEWOULDBLOCK) throw Exception(last); }
                    else received=result;
                    if(received==0) break;
                    Unk_BufferPtr buffer(m_receiveBuffer->FUN_140715390(m_received,received,Unk_SocketNew(0)));
                    m_received+=received; m_receiveQueue.AddTail(buffer);
                }
            }
            FUN_141265ae0();
        }
    } catch(Exception& e) { e.GetCode(); }
}
// MS2-FUNCTIONAL: equivalent control flow; local temporaries and cleanup code differ.
// @0x141265140
void CGameSocket::vfunc_3(CSimpleSocket*,int error)
{
    try {
        if(error) throw Exception(error);
        FUN_141267070();
    } catch(Exception& e) {
        PostMessageA(FUN_14209c720(FUN_140aadf80()),0x466,error,0);
        FUN_141266500(error);
    }
}
MS2_REPLACE_METHOD(0x141265140, CGameSocket, vfunc_3, 84, 0x5F016FFD);
// @0x1412651a0
void CGameSocket::OnClose(CSimpleSocket*,int error)
{
    CString text=Unk_SocketFormat("[D] CGameSocket::OnClose : nError = {0}",error);
    Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730(text,0));
    Unk_LockGuard guard(m_lock);
    if(guard!=0) {} else {
        if(m_disconnect==0 && error!=0 && m_state==Unk_SocketState::Connected) {
            if(g_socketClosing==0 && FUN_140aa6d30()!=0) {
                FUN_141266500(error); PostMessageA(FUN_14209c720(FUN_140aadf80()),0x465,error,0);
            }
        } else {
            text=Unk_SocketFormat("m_bDisconnect({0}), nError({1}), m_enState({2})",m_disconnect,error,m_state);
            Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730(text,0));
        }
        m_state=Unk_SocketState::Closed;
    }
}
MS2_REPLACE_METHOD(0x1412651a0, CGameSocket, OnClose, 626, 0x1E61A941);
// @0x141265420
int CGameSocket::FUN_141265420(CString host,int port,int showError,int special)
{
    {
        Unk_LockGuard guard(m_lock);
        if(guard!=0) {} else {
            if(m_state!=Unk_SocketState::Closed) return 0;
            m_disconnect=0; m_state=Unk_SocketState::Connecting;
            try {
            m_socket.FUN_14126c8b0(SOCK_STREAM,AF_INET,0); m_socket.FUN_14126c680(1); m_socket.FUN_14126c5a0(this);
            Unk_SocketOptions& opts=m_options;
            if(opts.noDelay!=INT_MAX) m_socket.FUN_14126c610(opts.noDelay);
            if(opts.option5!=INT_MAX) m_socket.FUN_14126c5c0(opts.option5);
            if(opts.receiveBuffer!=INT_MAX) m_socket.FUN_14126c7d0(opts.receiveBuffer);
            if(opts.sendBuffer!=INT_MAX) m_socket.FUN_14126c840(opts.sendBuffer);
            m_socket.FUN_1412694d0(0x33,0);
            m_host=host; m_port=port; m_specialConnect=special;
            m_retryHost=host; m_retryPort=port; m_showErrors=showError;
            if(m_socket.FUN_141269890(Unk_SocketAddress(host,port))==1) return 1;
            } catch(Exception& e) {}
        }
    }
    int error=WSAGetLastError(); if(showError) FUN_1412676a0(error);
    FUN_141266500(error); FUN_141265850(); return 0;
}
// @0x1412657e0
void CGameSocket::FUN_1412657e0() { FUN_141265420(m_retryHost,m_retryPort,m_showErrors,0); }
// @0x141265850
void CGameSocket::FUN_141265850()
{
    m_socket.FUN_141269750();
    { Unk_LockGuard guard(m_lock); if(guard!=0) {} else { m_state=Unk_SocketState::Closed; m_received=0; m_receiveBuffer=nullptr; m_packets.RemoveAll(); m_receiveQueue.RemoveAll(); } }
    { Unk_LockGuard guard(m_lock); if(guard!=0) {} else { m_sendQueue.RemoveAll(); m_sent=0; } }
}
MS2_REPLACE_METHOD(0x141265850, CGameSocket, FUN_141265850, 262, 0x37CE21CB);
// @0x141265960
void CGameSocket::FUN_141265960() { FUN_141265850(); FUN_1412677b0(); }
MS2_REPLACE_METHOD(0x141265960, CGameSocket, FUN_141265960, 29, 0x706FDE9B);
// @0x141265990
void CGameSocket::FUN_141265990(COutPacket& packet)
{
    bool hold; bool defer=false; hold=false;
    if(((void*)FUN_140e800e0())) { defer=((class CReconnectionManagerCli*)(void*)(((void*)FUN_140e800e0())))->FUN_140aad1e0(); hold=((class CReconnectionManagerCli*)(void*)(((void*)FUN_140e800e0())))->FUN_140aad0a0(9)==1; }
    if(m_state!=Unk_SocketState::Connected) {
        if(hold) return;
        m_out->PushPendingPacket(packet);
    } else if(defer) {
        switch(((class COutPacket*)(class COutPacket*)(&packet))->FUN_14020ba20()) {
        case 1: case 5: case 6: case 7: case 8: m_out->FUN_140208960(this,packet); break;
        default: m_out->PushPendingPacket(packet); break;
        }
    } else m_out->FUN_140208960(this,packet);
}
MS2_REPLACE_METHOD(0x141265990, CGameSocket, FUN_141265990, 330, 0x4BA90009);
// MS2-FUNCTIONAL: equivalent control flow; local temporaries and cleanup code differ.
// @0x141265ae0
void CGameSocket::FUN_141265ae0()
{
    int stopped=0;
    ATL::CAtlList<Unk_InPtr> ready(10);
    try {
        Unk_LockGuard guard(m_lock);
        if(guard!=0) {} else {
            while(!m_receiveQueue.IsEmpty() && !stopped) {
                Unk_BufferPtr buffer(m_receiveQueue.GetHead());
                while(buffer.get()!=0 && !stopped) {
                    Unk_InPtr packet=m_packets.IsEmpty() ? Unk_InPtr(0) : Unk_InPtr(m_packets.GetHead());
                    if(packet==NULL) { packet=Unk_SocketNew(0); m_packets.AddTail(packet); }
                    struct { int state; int sequence; } framing;
                    int state=packet->FUN_14070ff00(&buffer,&framing.state,0);
                    if(buffer.get()!=0) m_receiveQueue.SetAt(m_receiveQueue.GetHeadPosition(),buffer);
                    else m_receiveQueue.RemoveHeadNoReturn();
                    if(state==2) {
                        m_packets.RemoveHeadNoReturn(); Unk_RandomStep((int*)(&m_receiveKey));
                        unsigned key=m_receiveKey;
                        packet->FUN_140710280(((class CNetworkService*)(void*)(((void*)FUN_140714f90())))->GetConnectionState(),&key);
                        ++m_sequence; packet->FUN_14126c7b0(m_sequence);
                        int result=((class Unk_140d86260*)FUN_140d86260())->vfunc_35(*packet);
                        if(result==3 || result==2) {
                            int op=packet->FUN_14070fe80();
                            if(op==1) { Unk_ResponseVersion response; response.FUN_1407a4420(*packet); ((class CNetworkService*)(void*)(((void*)FUN_140714f90())))->FUN_14153a1d0(response.version, response.locale); ((class CNetworkService*)(void*)(((void*)FUN_140714f90())))->FUN_14153a210(response.key); }
                            else if(op==7) m_sequence=packet->ReadInt32();
                            else if(op==8) { int sequence=packet->ReadInt32(); framing.sequence=packet->ReadInt32(); m_sequence=sequence; }
                            ready.AddTail(packet);
                            if(packet->FUN_141269940(m_receiveKey)!=0x9dd) stopped=1;
                            buffer=m_receiveQueue.IsEmpty() ? Unk_BufferPtr(0) : Unk_BufferPtr(m_receiveQueue.GetHead());
                        }
                    }
                }
            }
        }
    } catch(Exception& e) {
        e.GetCode();
        if(TSingleton<CBigDataLogSystem>::GetInstance()) TSingleton<CBigDataLogSystem>::GetInstance()->SendLog(CString("sock_exception"),Unk_SocketFormat("CGameSocket::ProcessPacket {0}",e.GetText()));
        Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730(Unk_SocketFormat("CGameSocket::ProcessPacket {0}",e.GetText()),0));
    }
    if(stopped) PostMessageA(FUN_14209c720(FUN_140aadf80()),0x469,0,0);
    else for(POSITION pos=ready.GetHeadPosition();pos;ready.GetNext(pos)) {
        Unk_InPtr packet(ready.GetAt(pos)); FUN_1415396b0(((void*)FUN_140714f90()),packet);
        m_logger->LogReceive((unsigned short)packet->GetType(),*reinterpret_cast<Unk_LogInPacket*>(packet.get()));
    }
}
// @0x141266480
void CGameSocket::FUN_141266480(unsigned sendKey,unsigned receiveKey) { Unk_LockGuard guard(m_lock); if(guard!=0) {} else { m_sendKey=sendKey; m_receiveKey=receiveKey; } }
MS2_REPLACE_METHOD(0x141266480, CGameSocket, FUN_141266480, 111, 0x563F9D04);
// @0x141266500
void CGameSocket::FUN_141266500(int error)
{
    switch(error) {
    case 0x276d: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("A successful AfxSocketInit must occur before using this API",0)); break;
    case 0x2742: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The Windows Sockets implementation detected that the network subsystem failed",0)); break;
    case 0x2749: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The socket is not connected",0)); break;
    case 0x2734: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("A blocking Windows Sockets operation is in progress",0)); break;
    case 0x2736: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The descriptor is not a socket",0)); break;
    case 0x273d: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("MSG_OOB was specified, but the socket is not of type SOCK_STREAM",0)); break;
    case 0x274a: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The socket has been shut down; it is not possible to call Receive on a socket after ShutDown has been invoked with nHow set to 0 or 2",0)); break;
    case 0x2733: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The socket is marked as nonblocking and the Receive operation would block",0)); break;
    case 0x2738: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The datagram was too large to fit into the specified buffer and was truncated",0)); break;
    case 0x2745: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The virtual circuit was aborted due to timeout or other failure",0)); break;
    case 0x2746: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The virtual circuit was reset by the remote side",0)); break;
    case 0x273f: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("Addresses in the specified family cannot be used with this socket",0)); break;
    case 0x274d: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The attempt to connect was rejected",0)); break;
    case 0x2743: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The network cannot be reached from this host at this time",0)); break;
    case 0x271e: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The namelen parameter is invalid",0)); break;
    case 0x2726: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The socket is already bound to an address",0)); break;
    case 0x2748: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("The socket is already connected",0)); break;
    case 0x2728: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("No more file descriptors are available",0)); break;
    case 0x2747: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("No buffer space is available. The socket cannot be connected",0)); break;
    case 0x274c: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("Attempt to connect timed out without establishing a connection",0)); break;
    default: Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730("Unknown Error",0)); break;
    }
}
MS2_REPLACE_METHOD(0x141266500, CGameSocket, FUN_141266500, 2633, 0x5E518EA6);
// @0x141267000
void CGameSocket::FUN_141267000(int value) { Unk_LockGuard guard(m_lock); if(guard!=0) {} else m_disconnect=value; }
MS2_REPLACE_METHOD(0x141267000, CGameSocket, FUN_141267000, 91, 0x454E3B49);
// MS2-FUNCTIONAL: equivalent control flow; local temporaries and cleanup code differ.
// @0x141267070
void CGameSocket::FUN_141267070()
{
    try {
    Unk_LockGuard guard(m_lock);
    if(guard!=0) {} else {
        if((SOCKET)m_socket==0 || (SOCKET)m_socket==INVALID_SOCKET) return;
        for(;;) {
            if(!m_sendQueue.GetHeadPosition()) break;
            CPacketBuffer* buffer=m_sendQueue.GetHead().get();
            int n=m_socket.FUN_14126c3d0(buffer->FUN_140713530()+m_sent,buffer->GetSize()-m_sent,0);
            if(n==0) break;
            m_sent+=n;
            if(m_sent<(unsigned)buffer->GetSize()) continue;
            m_sendQueue.RemoveHead(); m_sent=0;
        }
    }
    } catch(Exception& e) {
        DWORD code=e.GetCode();
        CString text=Unk_SocketFormat("Socket Send Exception : {0}({1})",e.GetText(),code);
        Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730(text,0));
    }
}
MS2_REPLACE_METHOD(0x141267070, CGameSocket, FUN_141267070, 545, 0xD89E6EA3);
// @0x1412672a0
void CGameSocket::FUN_1412672a0(const Unk_SocketOptions& options) { m_options=options; }
MS2_REPLACE_METHOD(0x1412672a0, CGameSocket, FUN_1412672a0, 39, 0x0D8742A8);
// @0x1412672d0
void CGameSocket::FUN_1412672d0()
{
    m_sequence=0; m_out->FUN_140208d40();
    if(((void*)FUN_140e800e0())) {
        void* settings=((void*)((class CReconnectionManagerCli*)(void*)(((void*)FUN_140e800e0())))->FUN_140aad080()); BOOL enabled=((class ReconnectionOptions*)(void*)(settings))->FUN_140aadf90(0)==1 ? TRUE : FALSE;
        if(enabled) { int value=((class ReconnectionOptions*)(void*)(settings))->FUN_140aadf90(1); m_out->FUN_140209340(value); }
        m_out->FUN_140209450(enabled);
    }
}
MS2_REPLACE_METHOD(0x1412672d0, CGameSocket, FUN_1412672d0, 219, 0xB0C1948F);
// @0x1412673c0
void CGameSocket::FUN_1412673c0() { m_out->FUN_140209430(); }
MS2_REPLACE_METHOD(0x1412673c0, CGameSocket, FUN_1412673c0, 41, 0x0124E8F1);
// @0x1412673f0
int CGameSocket::GetSequence() { return m_sequence; }
MS2_REPLACE_METHOD(0x1412673f0, CGameSocket, GetSequence, 17, 0x116875E2);
// MS2-FUNCTIONAL: equivalent control flow; local temporaries and cleanup code differ.
// @0x141267410
void CGameSocket::FUN_141267410(COutPacket& packet)
{
    unsigned op=((class COutPacket*)(class COutPacket*)(&packet))->FUN_14020ba20();
    try {
    {
        Unk_LockGuard guard(m_lock);
        if(guard!=0) {} else {
            (void)((!!(((class COutPacket*)(class COutPacket*)(&packet))->FUN_14020bc40()==FALSE)) || (_wassert(L"oPacket.IsLoopback() == FALSE",_CRT_WIDE(MS2_THIS_FILE),496),0));
            ((class Unk_140d86260*)FUN_140d86260())->vfunc_34(packet);
            unsigned key=m_sendKey; FUN_140710b90(&packet,((class CNetworkService*)(void*)(((void*)FUN_140714f90())))->GetConnectionState(),&key);
            FUN_140710870(&packet,&m_sendQueue,0x9dd,&m_sendKey,0); Unk_RandomStep((int*)(&m_sendKey));
        }
    }
    m_logger->LogSend(op,*reinterpret_cast<Unk_LogOutPacket*>(&packet)); FUN_141267070();
    } catch(Exception& e) {
        DWORD code=e.GetCode();
        CString text=Unk_SocketFormat("Socket Send Exception : {0}({1})",e.GetText(),code);
        Unk_AdditionalLog(GetLogString(),12,19,FUN_14016a730(text,0));
    }
}
MS2_REPLACE_METHOD(0x141267410, CGameSocket, FUN_141267410, 439, 0x2094E6E2);
// @0x1412675d0
int CGameSocket::GetDisconnect() { return m_disconnect; }
MS2_REPLACE_METHOD(0x1412675d0, CGameSocket, GetDisconnect, 17, 0xC417BCBA);
// @0x1412675f0
int CGameSocket::FUN_1412675f0() { return m_state==Unk_SocketState::Connected ? 1 : 0; }
MS2_REPLACE_METHOD(0x1412675f0, CGameSocket, FUN_1412675f0, 47, 0xE1EE42FC);
// @0x141267630
CString CGameSocket::GetHost() { return m_host; }
MS2_REPLACE_METHOD(0x141267630, CGameSocket, GetHost, 68, 0x2A903A72);
// @0x141267680
int CGameSocket::GetPort() { return m_port; }
MS2_REPLACE_METHOD(0x141267680, CGameSocket, GetPort, 17, 0x04BB11AA);
// @0x1412676a0
void FUN_1412676a0(int error) { CUIService::GetInstance()->FUN_141adbea0(); FUN_140d73bc0(174,0,0,s_forceLogin); ((class Unk_140d86260*)FUN_140d86260())->vfunc_58(174,error); }
MS2_REPLACE(0x1412676a0, FUN_1412676a0, 118, 0x5BB614FD);
// @0x141267720
void FUN_141267720() { CUIService::GetInstance()->FUN_141adbea0(); FUN_140d73aa0(FUN_1408116a0(527,0),0,0,s_forceLogin); }
MS2_REPLACE(0x141267720, FUN_141267720, 137, 0xD9DF5AEA);
// @0x1412677b0
void FUN_1412677b0() { CUIService::GetInstance()->FUN_141adbea0(); int code=532; if(FUN_1406516b0()==3) code=3178; FUN_140d73aa0(FUN_1408116a0(code,0),0,0,s_gameExit); ((class Unk_140d86260*)FUN_140d86260())->vfunc_58(code,0); }
MS2_REPLACE(0x1412677b0, FUN_1412677b0, 198, 0xF4854A56);
// Inline socket and packet helpers instantiated by the client entry points.
// @0x141268620
inline CInPacket::CInPacket(int flags):m_flags(flags),m_length(0),m_opcode(0),m_40(0),m_packetLength(0),m_offset(0),m_sequence(0) { m_data.SetCount(256,-1); FUN_140713940(); }
// @0x141268710
inline Unk_SocketAddress::Unk_SocketAddress(const char* host,int port)
{
    FUN_14126ce80(port,0);
    if(host==0 || *host==0) return;
    ATL::CA2AEX<128> name(host); sin_addr.s_addr=inet_addr(name);
    if(sin_addr.s_addr==INADDR_NONE) {
        hostent* entry=gethostbyname(name);
        if(entry) sin_addr.s_addr=reinterpret_cast<in_addr*>(entry->h_addr_list[0])->s_addr;
        else { int error=WSAGetLastError(); throw Exception(error); }
    }
}
// @0x141268960
inline CSimpleSocket::CSimpleSocket():CSocketBase(INVALID_SOCKET),m_callback(0) {}
// @0x1412689f0
inline CSocketThread::CSocketThread():m_commands(10),m_sockets(17,.75f,.25f,2.25f,10) {}
// @0x141268cb0
inline CInPacket::~CInPacket() {}
// @0x141268d50
inline CSimpleSocket::~CSimpleSocket() { FUN_141269750(); }
// @0x141268de0
inline CSocketThread::~CSocketThread()
{
    FUN_141269dc0();
    if(GetThread()!=0) { m_quit=1; WSASetEvent(m_events[0]); FUN_1401d3510(INFINITE); }
    if(!m_events.IsEmpty()) WSACloseEvent(m_events[0]);
}
// @0x1412694d0
inline void CSimpleSocket::FUN_1412694d0(int events,CSocketThread* worker)
{
    FUN_141269990();
    if(worker==0) m_worker=Unk_SocketNew(0); else m_worker=worker;
    m_worker->FUN_1412696b0();
    HANDLE done=WSACreateEvent(); Unk_SocketCommand command={this,events,done};
    { Unk_LockGuard guard(m_worker->m_lock); if(guard!=0) {} else m_worker->m_commands.AddTail(command); }
    WSASetEvent(m_worker->m_events[0]);
    HANDLE waits[2]={done,m_worker->GetThread()};
    DWORD result=WaitForMultipleObjectsEx(2,waits,FALSE,INFINITE,FALSE);
    WSACloseEvent(done); if(result!=0) throw Exception(WSAEINVAL);
}
// @0x1412696b0
inline void CSocketThread::FUN_1412696b0()
{
    if(!GetThread()) {
        HANDLE event=WSACreateEvent(); m_events.Add(event);
        if(!event || !FUN_141215220(0,0,0,0,0)) throw Exception(GetLastError());
    }
}
// @0x141269750
inline void CSimpleSocket::FUN_141269750() { FUN_141269990(); FUN_141269780(); }
// @0x141269780
inline void CSocketBase::FUN_141269780() { if(m_socket!=INVALID_SOCKET) { closesocket(m_socket); m_socket=INVALID_SOCKET; } }
// @0x141269820
inline int CSimpleSocket::FUN_141269820(const sockaddr* addr,int size) { return connect((SOCKET)*this,addr,size)!=SOCKET_ERROR || WSAGetLastError()==WSAEWOULDBLOCK ? 1 : 0; }
// @0x141269990
inline void CSimpleSocket::FUN_141269990()
{
    if(m_worker.get()) {
        HANDLE done=WSACreateEvent(); void* unused=0; // the exe zeroes an unused local here
        Unk_SocketCommand command={this,-1,done};
        { Unk_LockGuard guard(m_worker->m_lock); if(guard!=0) {} else m_worker->m_commands.AddTail(command); }
        WSASetEvent(m_worker->m_events[0]);
        HANDLE waits[2]={done,m_worker->GetThread()}; WaitForMultipleObjectsEx(2,waits,FALSE,INFINITE,FALSE);
        WSACloseEvent(done); m_worker=0;
    }
}
// MS2-FUNCTIONAL: equivalent control flow; local temporaries and cleanup code differ.
// @0x141269b30
inline int CSocketThread::FUN_141269b30(HANDLE event)
{
    CSimpleSocket* socket=0; m_sockets.Lookup(event,socket);
    try {
    WSANETWORKEVENTS events;
    if(WSAEnumNetworkEvents(*socket,event,&events)==SOCKET_ERROR) throw Exception(WSAGetLastError());
    ISocketCallBack* callback=socket->FUN_14126a3c0();
    if(callback) {
        if(events.lNetworkEvents&FD_ACCEPT) callback->vfunc_0(socket,events.iErrorCode[FD_ACCEPT_BIT]);
        if(events.lNetworkEvents&FD_CONNECT) callback->vfunc_1(socket,events.iErrorCode[FD_CONNECT_BIT]);
        if(events.lNetworkEvents&FD_OOB) callback->vfunc_4(socket,events.iErrorCode[FD_OOB_BIT]);
        if(events.lNetworkEvents&FD_READ) callback->vfunc_2(socket,events.iErrorCode[FD_READ_BIT]);
        if(events.lNetworkEvents&FD_WRITE) callback->vfunc_3(socket,events.iErrorCode[FD_WRITE_BIT]);
        if(events.lNetworkEvents&FD_CLOSE) callback->OnClose(socket,events.iErrorCode[FD_CLOSE_BIT]);
    }
    return m_commands.IsEmpty();
    } catch(Exception& e) { FUN_14126a000(socket,e.GetCode()); return 0; }
}
// @0x141269dc0
inline void CSocketThread::FUN_141269dc0()
{
    for(;;) {
        Unk_LockGuard guard(m_lock);
        if(guard!=0) {} else {
            Unk_SocketCommand command;
            if(m_commands.IsEmpty()) return;
            else { command=m_commands.GetHead(); m_commands.RemoveHead(); }
            if(command.events==-1) FUN_14126b250(command.socket);
            else { HANDLE event=FUN_14126b1c0(command.socket); if(!event || WSAEventSelect(*command.socket,event,command.events)==SOCKET_ERROR) FUN_14126a000(command.socket,WSAGetLastError()); }
            if(command.done) WSASetEvent(command.done);
        }
    }
}
// MS2-FUNCTIONAL: equivalent control flow; local temporaries and cleanup code differ.
// @0x14126a000
inline void CSocketThread::FUN_14126a000(CSimpleSocket* socket,int error)
{
    ISocketCallBack* callback=socket->FUN_14126a3c0();
    if(callback) { try { callback->OnClose(socket,error); } catch(Exception&) {} }
    FUN_14126b250(socket); socket->FUN_141269780();
}
// @0x14126a990
inline HANDLE CThread::GetThread() const { return m_thread; }
// @0x14126b1c0
inline HANDLE CSocketThread::FUN_14126b1c0(CSimpleSocket* socket)
{
    if(m_sockets.GetCount()+1>=64) return 0;
    HANDLE event=WSACreateEvent();
    if(!event) return event;
    m_sockets.SetAt(event,socket); m_events.Add(event);
    return event;
}
// @0x14126b250
inline int CSocketThread::FUN_14126b250(CSimpleSocket* socket)
{
    const ATL::CAtlMap<HANDLE,CSimpleSocket*>::CPair* found=0;
    POSITION pos=m_sockets.GetStartPosition();
    while(pos) { if(m_sockets.GetValueAt(pos)==socket) { found=m_sockets.GetAt(pos); break; } m_sockets.GetNext(pos); }
    if(!found) return false;
    HANDLE event=found->m_key; m_sockets.RemoveKey(event);
    for(size_t index=m_events.GetCount()-1;index>0;--index) if(m_events[index]==event) { WSACloseEvent(event); m_events.RemoveAt(index,1); return true; }
    return true;
}
// @0x14126b3a0
inline int CSimpleSocket::vfunc_1(char* data,int size)
{
    for(;;) {
        int n=recv((SOCKET)*this,data,size,0);
        if(n==SOCKET_ERROR) { int error=WSAGetLastError(); if(error==WSAEWOULDBLOCK) { Sleep(10); continue; } else throw Exception(error); }
        else { if(n==0) throw Exception(WSAENOTCONN); else return n; }
    }
}
// @0x14126b470
inline int CSimpleSocket::vfunc_3(char* data,int size)
{
    int total=size;
    while(size>0U) {
        int n=recv((SOCKET)*this,data,size,0);
        if(n==SOCKET_ERROR) {
            int error=WSAGetLastError();
            if(error==WSAEWOULDBLOCK) { Sleep(10); continue; }
            else if(error==WSAENOTCONN) return total-size;
            else throw Exception(error);
        }
        else if(n==0) return total-size;
        data+=n; size-=n;
    }
    return total;
}
// @0x14126c1a0
inline unsigned int CSocketThread::vfunc_1(void*,Unk_140659080& start)
{
    Unk_SocketThreadAddRef(); m_quit=0; start.FUN_1401d42d0();
    try {
    while(!m_quit) {
        size_t count=m_events.GetCount(); DWORD result=WSAWaitForMultipleEvents((DWORD)Unk_SocketMin(count,size_t(64)),&m_events[0],FALSE,INFINITE,FALSE);
        if(result>=count) throw Exception(WSAGetLastError());
        if(result==0) { WSAResetEvent(m_events[0]); FUN_141269dc0(); result=1; }
        HANDLE* event=&m_events[0]; HANDLE* end=event+m_events.GetCount();
        for(event=event+result;event<end;++event) if(WSAWaitForMultipleEvents(1,event,FALSE,0,FALSE)==0 && !FUN_141269b30(*event)) break;
    }
    } catch(Exception& e) {
        int code=e.GetCode();
        CSimpleSocket* socket=0;
        POSITION pos=m_sockets.GetStartPosition();
        while(pos) { socket=m_sockets.GetValueAt(pos); m_sockets.GetNext(pos); FUN_14126a000(socket,code); }
    }
    Unk_SocketThreadRelease(); return 0;
}
// @0x14126c3d0
inline int CSimpleSocket::FUN_14126c3d0(const char* data,int size,int outOfBand)
{
    int n=send((SOCKET)*this,data,size,outOfBand?1:0);
    if(n==SOCKET_ERROR) { int error=WSAGetLastError(); if(error==WSAEWOULDBLOCK) return 0; else throw Exception(error); }
    else return n;
}
// @0x14126c5c0
inline void CSocketBase::FUN_14126c5c0(int value) { int nValue=value; setsockopt((SOCKET)*this,6,5,reinterpret_cast<char*>(&nValue),4); }
// @0x14126c610
inline void CSocketBase::FUN_14126c610(int value) { int nValue=value; if(setsockopt((SOCKET)*this,6,1,reinterpret_cast<char*>(&nValue),4)==SOCKET_ERROR) throw Exception(WSAGetLastError()); }
// @0x14126c680
inline void CSocketBase::FUN_14126c680(int value) { u_long nonblocking=value!=0; if(ioctlsocket((SOCKET)*this,FIONBIO,&nonblocking)==SOCKET_ERROR) throw Exception(WSAGetLastError()); }
// @0x14126c7d0
inline void CSocketBase::FUN_14126c7d0(int value) { int nValue=value; if(setsockopt((SOCKET)*this,SOL_SOCKET,SO_RCVBUF,reinterpret_cast<char*>(&nValue),4)==SOCKET_ERROR) throw Exception(WSAGetLastError()); }
// @0x14126c840
inline void CSocketBase::FUN_14126c840(int value) { int nValue=value; if(setsockopt((SOCKET)*this,SOL_SOCKET,SO_SNDBUF,reinterpret_cast<char*>(&nValue),4)==SOCKET_ERROR) throw Exception(WSAGetLastError()); }
// @0x14126c8b0
inline void CSocketBase::FUN_14126c8b0(int type,int family,int protocol) { SOCKET s=socket(family,type,protocol); m_socket=s; if(s==INVALID_SOCKET) throw Exception(WSAGetLastError()); }
// @0x14126ca60
inline int CSimpleSocket::vfunc_2(const char* data,int size) { return FUN_14126c3d0(data,size,0); }
// @0x14126ca90
inline int CSimpleSocket::vfunc_4(const char* data,int size)
{
    int total=size;
    while(size>0U) {
        int n=send((SOCKET)*this,data,size,0);
        if(n==SOCKET_ERROR) {
            int error=WSAGetLastError();
            if(error==WSAEWOULDBLOCK) { Sleep(10); continue; }
            else if(error==WSAENOTCONN) return total-size;
            else throw Exception(error);
        }
        else if(n==0) return total-size;
        data+=n; size-=n;
    }
    return total;
}
// @0x14126ce80
inline void Unk_SocketAddress::FUN_14126ce80(int port,unsigned long address) { FUN_14126ced0(htons(port),htonl(address)); }
#pragma function(memset)
// @0x14126ced0
inline void Unk_SocketAddress::FUN_14126ced0(unsigned short port,unsigned long address) { memset(this,0,16); sin_family=AF_INET; sin_port=port; sin_addr.s_addr=address; }
#pragma intrinsic(memset)







// End of recovered definitions.
// MS2-FUNCTIONAL: fmt custom formatting omits unused scratch; ATL map GetAt uses the supplied library check.
// Verified template pins.
// MS2-PIN: ??$?0$$CCH@ArgType@internal@fmt@@QEAA@AEDH@Z 0x141267880
// MS2-PIN: ??$Unk_SocketFormat@$$CCHHW4Unk_SocketState@@@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEDHAEBHAEBW4Unk_SocketState@@@Z 0x141267910
// MS2-PIN: ??$Unk_SocketFormat@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@K@@YA?AV?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@PEBDAEBV01@AEBK@Z 0x141267c90
// MS2-PIN: ?New@?$Unk_SocketRef@VCInPacket@@@@SAPEAV?$TPtredDummy@VCInPacket@@@@PEAX@Z 0x141267fa0
// MS2-PIN: ??$format_arg@DW4Unk_SocketState@@@fmt@@YAXAEAV?$BasicFormatter@D@0@AEAPEBDAEBW4Unk_SocketState@@@Z 0x141268010
// MS2-PIN: ??$make_type@$$CCH@internal@fmt@@YA_KAEDH@Z 0x141268160
// MS2-PIN: ??$Unk_SocketMin@_K@@YA_K_K0@Z 0x1412681a0
// MS2-PIN: ??0?$Unk_SocketPtr@VCInPacket@@@@QEAA@H@Z 0x141268470
// MS2-PIN: ??0?$Unk_SocketPtr@VCPacketBuffer@@@@QEAA@H@Z 0x141268510
// MS2-PIN: ??0?$Unk_SocketPtr@VCPacketLogger@@@@QEAA@H@Z 0x141268530
// MS2-PIN: ??0?$Unk_SocketPtr@VCPacketLogger@@@@QEAA@PEAVCPacketLogger@@@Z 0x141268550
// MS2-PIN: ??0?$Unk_SocketPtr@VCSocketThread@@@@QEAA@PEAVCSocketThread@@@Z 0x141268580
// MS2-PIN: ??0?$TPtredDummy@VCInPacket@@@@QEAA@XZ 0x1412685d0
// MS2-PIN: ??0CNode@?$CAtlList@V?$Unk_SocketPtr@VCInPacket@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCInPacket@@@@@ATL@@@ATL@@QEAA@AEBV?$Unk_SocketPtr@VCInPacket@@@@@Z 0x141268880
// MS2-PIN: ??0CPair@?$CAtlMap@PEAXPEAVCSimpleSocket@@V?$CElementTraits@PEAX@ATL@@V?$CElementTraits@PEAVCSimpleSocket@@@3@@ATL@@IEAA@PEAX@Z 0x1412688f0
// MS2-PIN: ??0Unk_ResponseVersion@@QEAA@XZ 0x141268910
// MS2-PIN: ??1Unk_SocketAddress@@QEAA@XZ 0x141268cf0
// MS2-PIN: ??4?$Unk_SocketPtr@VCOutPacketBuffer@@@@QEAAAEAV0@PEAVCOutPacketBuffer@@@Z 0x141268f20
// MS2-PIN: ??4?$Unk_SocketPtr@VCPacketLogger@@@@QEAAAEAV0@PEAVCPacketLogger@@@Z 0x141268fd0
// MS2-PIN: ??4?$Unk_SocketPtr@VCSocketThread@@@@QEAAAEAV0@H@Z 0x141269040
// MS2-PIN: ??4?$Unk_SocketPtr@VCSocketThread@@@@QEAAAEAV0@PEAVCSocketThread@@@Z 0x141269070
// MS2-PIN: ??8?$Unk_SocketPtr@VCInPacket@@@@QEBA_NPEAVCInPacket@@@Z 0x1412690e0
// MS2-PIN: ?get@?$Unk_SocketPtr@VCSocketThread@@@@QEBAPEAVCSocketThread@@XZ 0x141269120
// MS2-PIN: ?Value@?$Unk_SocketRef@VCInPacket@@@@SAPEAVCInPacket@@PEAV?$TPtredDummy@VCInPacket@@@@@Z 0x141269130
// MS2-PIN: ??BUnk_SocketAddress@@QEBAPEBUsockaddr@@XZ 0x141269170
// MS2-PIN: ?AddTail@?$CAtlList@V?$Unk_SocketPtr@VCInPacket@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCInPacket@@@@@ATL@@@ATL@@QEAAPEAU__POSITION@@AEBV?$Unk_SocketPtr@VCInPacket@@@@@Z 0x1412693f0
// MS2-PIN: ??4?$Unk_SocketPtr@VCInPacket@@@@QEAAAEAV0@AEBUUnk_SocketNew@@@Z 0x141269470
// MS2-PIN: ??4?$Unk_SocketPtr@VCSocketThread@@@@QEAAAEAV0@AEBUUnk_SocketNew@@@Z 0x1412694a0
// MS2-PIN: ?CompareElements@?$CDefaultCompareTraits@PEAX@ATL@@SA_NAEBQEAX0@Z 0x1412697c0
// MS2-PIN: ?CreateNode@?$CAtlMap@PEAXPEAVCSimpleSocket@@V?$CElementTraits@PEAX@ATL@@V?$CElementTraits@PEAVCSimpleSocket@@@3@@ATL@@AEAAPEAVCNode@12@PEAXII@Z 0x1412698c0
// MS2-PIN: ?FUN_141269940@CInPacket@@QEAAGI@Z 0x141269940
// MS2-PIN: ?FindNextNode@?$CAtlMap@PEAXPEAVCSimpleSocket@@V?$CElementTraits@PEAX@ATL@@V?$CElementTraits@PEAVCSimpleSocket@@@3@@ATL@@AEBAPEAVCNode@12@PEAV312@@Z 0x141269f40
// MS2-PIN: ?Base@?$Unk_SocketRef@VCInPacket@@@@SAPEAVCPtred@@PEAVCInPacket@@@Z 0x14126a310
// MS2-PIN: ?FUN_14126a3c0@CSimpleSocket@@QEAAPEAVISocketCallBack@@XZ 0x14126a3c0
// MS2-PIN: ?GetCount@?$CAtlMap@PEAXPEAVCSimpleSocket@@V?$CElementTraits@PEAX@ATL@@V?$CElementTraits@PEAVCSimpleSocket@@@3@@ATL@@QEBA_KXZ 0x14126a3d0
// MS2-PIN: ?GetFreeNode@?$CAtlList@V?$Unk_SocketPtr@VCInPacket@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCInPacket@@@@@ATL@@@ATL@@AEAAXXZ 0x14126a4c0
// MS2-PIN: ?GetHead@?$CAtlList@UUnk_SocketCommand@@V?$CElementTraits@UUnk_SocketCommand@@@ATL@@@ATL@@QEAAAEAUUnk_SocketCommand@@XZ 0x14126a5b0
// MS2-PIN: ?GetHead@?$CAtlList@V?$Unk_SocketPtr@VCInPacket@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCInPacket@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_SocketPtr@VCInPacket@@@@XZ 0x14126a610
// MS2-PIN: ?GetHead@?$CAtlList@V?$Unk_SocketPtr@VCPacketBuffer@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCPacketBuffer@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_SocketPtr@VCPacketBuffer@@@@XZ 0x14126a670
// MS2-PIN: ?GetHeadPosition@?$CAtlList@V?$Unk_SocketPtr@VCInPacket@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCInPacket@@@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x14126a6d0
// MS2-PIN: ?GetHeadPosition@?$CAtlList@V?$Unk_SocketPtr@VCPacketBuffer@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCPacketBuffer@@@@@ATL@@@ATL@@QEBAPEAU__POSITION@@XZ 0x14126a6e0
// MS2-PIN: ?GetAt@?$CAtlMap@PEAXPEAVCSimpleSocket@@V?$CElementTraits@PEAX@ATL@@V?$CElementTraits@PEAVCSimpleSocket@@@3@@ATL@@QEAAPEAVCPair@12@PEAU__POSITION@@@Z 0x14126a6f0
// MS2-PIN: ?GetNext@?$CAtlList@V?$Unk_SocketPtr@VCInPacket@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCInPacket@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_SocketPtr@VCInPacket@@@@AEAPEAU__POSITION@@@Z 0x14126a760
// MS2-PIN: ?GetNext@?$CAtlMap@PEAXPEAVCSimpleSocket@@V?$CElementTraits@PEAX@ATL@@V?$CElementTraits@PEAVCSimpleSocket@@@3@@ATL@@QEAAPEAVCPair@12@AEAPEAU__POSITION@@@Z 0x14126a7e0
// MS2-PIN: ?GetStartPosition@?$CAtlMap@PEAXPEAVCSimpleSocket@@V?$CElementTraits@PEAX@ATL@@V?$CElementTraits@PEAVCSimpleSocket@@@3@@ATL@@QEBAPEAU__POSITION@@XZ 0x14126a920
// MS2-PIN: ?NewNode@?$CAtlList@V?$Unk_SocketPtr@VCInPacket@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCInPacket@@@@@ATL@@@ATL@@AEAAPEAVCNode@12@AEBV?$Unk_SocketPtr@VCInPacket@@@@PEAV312@1@Z 0x14126ad80
// MS2-PIN: ?vfunc_0@CGameSocket@@UEAAXPEAVCSimpleSocket@@H@Z 0x14126b050
// MS2-PIN: ?vfunc_0@ISocketCallBack@@UEAAXPEAVCSimpleSocket@@H@Z 0x14126b060
// MS2-PIN: ?OnClose@ISocketCallBack@@UEAAXPEAVCSimpleSocket@@H@Z 0x14126b070
// MS2-PIN: ?vfunc_1@ISocketCallBack@@UEAAXPEAVCSimpleSocket@@H@Z 0x14126b080
// MS2-PIN: ?vfunc_4@CGameSocket@@UEAAXPEAVCSimpleSocket@@H@Z 0x14126b090
// MS2-PIN: ?vfunc_4@ISocketCallBack@@UEAAXPEAVCSimpleSocket@@H@Z 0x14126b0a0
// MS2-PIN: ?vfunc_2@ISocketCallBack@@UEAAXPEAVCSimpleSocket@@H@Z 0x14126b0b0
// MS2-PIN: ?vfunc_3@ISocketCallBack@@UEAAXPEAVCSimpleSocket@@H@Z 0x14126b0c0
// MS2-PIN: ?SetAt@?$CAtlList@V?$Unk_SocketPtr@VCPacketBuffer@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCPacketBuffer@@@@@ATL@@@ATL@@QEAAXPEAU__POSITION@@AEBV?$Unk_SocketPtr@VCPacketBuffer@@@@@Z 0x14126c480
// MS2-PIN: ?SetAt@?$CAtlMap@PEAXPEAVCSimpleSocket@@V?$CElementTraits@PEAX@ATL@@V?$CElementTraits@PEAVCSimpleSocket@@@3@@ATL@@QEAAPEAU__POSITION@@PEAXAEBQEAVCSimpleSocket@@@Z 0x14126c500
// MS2-PIN: ?FUN_14126c7b0@CInPacket@@QEAAXH@Z 0x14126c7b0
// MS2-PIN: ?AddRef@?$Unk_SocketPtr@VCInPacket@@@@AEBAXXZ 0x14126cb90
// MS2-PIN: ?AddRef@?$Unk_SocketPtr@VCOutPacketBuffer@@@@AEBAXXZ 0x14126cbc0
// MS2-PIN: ?AddRef@?$Unk_SocketPtr@VCPacketLogger@@@@AEBAXXZ 0x14126cbf0
// MS2-PIN: ?AddRef@?$Unk_SocketPtr@VCSocketThread@@@@AEBAXXZ 0x14126cc20
// MS2-PIN: ?Reference@?$Unk_SocketPtr@VCInPacket@@@@CAXPEAVCPtred@@@Z 0x14126cc50
// MS2-PIN: ?Reference@?$Unk_SocketPtr@VCOutPacketBuffer@@@@CAXPEAVCPtred@@@Z 0x14126cc70
// MS2-PIN: ?Reference@?$Unk_SocketPtr@VCPacketLogger@@@@CAXPEAVCPtred@@@Z 0x14126cc90
// MS2-PIN: ?Reference@?$Unk_SocketPtr@VCSocketThread@@@@CAXPEAVCPtred@@@Z 0x14126ccb0
// MS2-PIN: ?AddRefImpl@?$Unk_SocketPtr@VCInPacket@@@@AEBAXPEAX@Z 0x14126ccd0
// MS2-PIN: ?AddRefImpl@?$Unk_SocketPtr@VCOutPacketBuffer@@@@AEBAXPEAX@Z 0x14126cd00
// MS2-PIN: ?AddRefImpl@?$Unk_SocketPtr@VCPacketLogger@@@@AEBAXPEAX@Z 0x14126cd30
// MS2-PIN: ?AddRefImpl@?$Unk_SocketPtr@VCSocketThread@@@@AEBAXPEAX@Z 0x14126cd60
// MS2-PIN: ?ResetNew@?$Unk_SocketPtr@VCInPacket@@@@AEAAXXZ 0x14126cdb0
// MS2-PIN: ?ResetNew@?$Unk_SocketPtr@VCSocketThread@@@@AEAAXXZ 0x14126cde0
// MS2-PIN: ?Create@?$Unk_SocketRef@VCInPacket@@@@SAPEAVCInPacket@@PEAX@Z 0x14126ce10
// MS2-PIN: ?Create@?$Unk_SocketRef@VCSocketThread@@@@SAPEAVCSocketThread@@PEAX@Z 0x14126ce40
// MS2-PIN: ?FUN_14126ced0@Unk_SocketAddress@@QEAAXGK@Z 0x14126ced0
// MS2-PIN: ?ReleaseImpl@?$Unk_SocketPtr@VCOutPacketBuffer@@@@AEAAXPEAX@Z 0x14126d080
// MS2-PIN: ?ReleaseImpl@?$Unk_SocketPtr@VCPacketLogger@@@@AEAAXPEAX@Z 0x14126d0d0
// MS2-PIN: ?ReleaseImpl@?$Unk_SocketPtr@VCSocketThread@@@@AEAAXPEAX@Z 0x14126d120
// MS2-PIN: ?FUN_141269890@CSimpleSocket@@QEAAHPEBUsockaddr@@@Z 0x141269890
// MS2-PIN: ?FUN_14126c5a0@CSimpleSocket@@QEAAXPEAVISocketCallBack@@@Z 0x14126c5a0
// MS2-PIN: ?GetAt@?$CAtlList@V?$Unk_SocketPtr@VCInPacket@@@@V?$CElementTraits@V?$Unk_SocketPtr@VCInPacket@@@@@ATL@@@ATL@@QEAAAEAV?$Unk_SocketPtr@VCInPacket@@@@PEAU__POSITION@@@Z 0x14126a350

// No hooks for 141264dd0/141265ae0 (packet wrapper allocation), or
// 141265420/1412657e0 (socket worker allocation); those construct local RTTI.
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cae240-0x142cae2b0 .text$yd

// hk1 2026-10-20: hooks for the remaining recovered functions (work/hk1/report.md)
MS2_REPLACE(0x141269970, Unk_SocketDecrement, 24, 0xE8938165);
MS2_REPLACE(0x14126cd90, Unk_SocketThreadAddRef, 21, 0x8D4F5A8B);
MS2_REPLACE(0x14126ce60, Unk_SocketThreadRelease, 21, 0x6E9F9D2A);
MS2_REPLACE_METHOD(0x1412657e0, CGameSocket, FUN_1412657e0, 101, 0xA4BA1795);
MS2_REPLACE_METHOD(0x141265ae0, CGameSocket, FUN_141265ae0, 2450, 0x4E0FB171);
MS2_REPLACE_METHOD(0x141269750, CSimpleSocket, FUN_141269750, 41, 0xCA8FD322);
MS2_REPLACE_METHOD(0x141269780, CSocketBase, FUN_141269780, 51, 0xDDA3D594);
MS2_REPLACE_METHOD(0x141269820, CSimpleSocket, FUN_141269820, 100, 0x6DEE46BF);
MS2_REPLACE_METHOD(0x141269990, CSimpleSocket, FUN_141269990, 369, 0x79C79B2C);
MS2_REPLACE_METHOD(0x141269dc0, CSocketThread, FUN_141269dc0, 344, 0xF2248F24);
MS2_REPLACE_METHOD(0x14126a000, CSocketThread, FUN_14126a000, 117, 0x3579A715);
MS2_REPLACE_METHOD(0x14126a990, CThread, GetThread, 15, 0x6BC6B691);
MS2_REPLACE_METHOD(0x14126b1c0, CSocketThread, FUN_14126b1c0, 133, 0x44A07B33);
MS2_REPLACE_METHOD(0x14126b250, CSocketThread, FUN_14126b250, 336, 0xD719EBD3);
MS2_REPLACE_METHOD(0x14126c5c0, CSocketBase, FUN_14126c5c0, 69, 0xB3367F3B);
MS2_REPLACE_METHOD(0x14126ca60, CSimpleSocket, vfunc_2, 47, 0xD80D9096);
MS2_REPLACE_METHOD(0x14126ce80, Unk_SocketAddress, FUN_14126ce80, 68, 0xACD2AB79);
MS2_REPLACE_METHOD(0x14126ced0, Unk_SocketAddress, FUN_14126ced0, 81, 0x8A65074E);

