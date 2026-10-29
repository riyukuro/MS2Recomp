// Nexon Messenger game-server-list request serialization.
// MS2-UNIT: unit_1415937e0
// MS2-RANGE: 0x1415937e0-0x141593c60 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_1415f9990(void*); extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415e8260(void*); extern void FUN_141608f60(void*); extern void FUN_14160b390(void*,void*); extern unsigned int FUN_14160b9d0(void*);
// CNMGameServerCode::CNMGameServerCode: nmgameservercode.cpp @0x14157aaf0
// MS2-FUNCTIONAL 0x1415937e0: initializes the game-server list with request mode zero.
CNMGetGameServerListFunc::CNMGetGameServerListFunc():CNMFunc(0x800d,1,0,0),m_nGameCode(0),m_n34(0),m_aServerCode(){FUN_1415e8260(&m_aServerCode);}
// MS2-FUNCTIONAL 0x141593850: stores the requested game code.
CNMGetGameServerListFunc::CNMGetGameServerListFunc(int code):CNMFunc(0x800d,1,0,0),m_nGameCode(code),m_n34(0),m_aServerCode(){FUN_1415e8260(&m_aServerCode);}
// MS2-FUNCTIONAL 0x1415938c0: frames the game-server-list request.
unsigned int CNMGetGameServerListFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetGameServerListFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141593920: dispatches encoding according to message format.
unsigned int CNMGetGameServerListFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetGameServerListFunc::Encode(pEncoder, pStream);
    return CNMGetGameServerListFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141593980: writes the returned server codes or request game code.
unsigned int CNMGetGameServerListFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this)){FUN_14156ac20(e,FUN_14160b9d0(&m_aServerCode));for(auto&code:m_aServerCode)code.EncodeFramed(s);}else FUN_14156ac20(e,static_cast<unsigned int>(m_nGameCode));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141593a80: decodes a framed game-server-list response.
unsigned int CNMGetGameServerListFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetGameServerListFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141593b10: dispatches decoding according to response format.
unsigned int CNMGetGameServerListFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetGameServerListFunc::DecodeFramed(pStream);
    return CNMGetGameServerListFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141593b70: restores the server-code vector or request game code.
unsigned int CNMGetGameServerListFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(!FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);unsigned count=reinterpret_cast<U>(v[3])(d);m_aServerCode.clear();for(unsigned i=0;i<count;++i){CNMGameServerCode code;code.DecodeFramed(s);FUN_14160b390(&m_aServerCode,&code);}}else{void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);m_nGameCode=static_cast<int>(reinterpret_cast<U>(v[3])(d));}return FUN_1415fb750(d);}
// MS2-PIN: ??0CNMGetGameServerListFunc@@QEAA@XZ 0x1415937e0
// MS2-PIN: ??0CNMGetGameServerListFunc@@QEAA@H@Z 0x141593850
// MS2-PIN: ?EncodeFramed@CNMGetGameServerListFunc@@UEAAIPEAVCNMStream@@@Z 0x1415938c0
// MS2-PIN: ?EncodeDispatch@CNMGetGameServerListFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141593920
// MS2-PIN: ?Encode@CNMGetGameServerListFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141593980
// MS2-PIN: ?DecodeFramed@CNMGetGameServerListFunc@@UEAAIPEAVCNMStream@@@Z 0x141593a80
// MS2-PIN: ?DecodeDispatch@CNMGetGameServerListFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141593b10
// MS2-PIN: ?Decode@CNMGetGameServerListFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141593b70
