// Nexon Messenger game server-name request serialization.
// MS2-UNIT: unit_141594740
// MS2-RANGE: 0x141594740-0x141594b20 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ae30(void*,void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x141594740: initializes the request and empty reply buffer.
CNMGetGameServerNameFunc::CNMGetGameServerNameFunc():CNMFunc(0x8011,1,0,0),m_nGameCode(0),m_nServerCode(0),m_szName{}{}
// MS2-FUNCTIONAL 0x1415947B0: stores the requested game and server codes and clears the reply buffer.
CNMGetGameServerNameFunc::CNMGetGameServerNameFunc(int code,int server):CNMFunc(0x8011,1,0,0),m_nGameCode(code),m_nServerCode(server),m_szName{}{}
// MS2-FUNCTIONAL 0x141594830: frames the server-name request.
unsigned int CNMGetGameServerNameFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetGameServerNameFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141594890: dispatches encoding according to message format.
unsigned int CNMGetGameServerNameFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetGameServerNameFunc::Encode(pEncoder, pStream);
    return CNMGetGameServerNameFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x1415948F0: writes the name on replies and the game code on requests.
unsigned int CNMGetGameServerNameFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this))FUN_14156ae30(e,m_szName);else{FUN_14156ac20(e,static_cast<unsigned int>(m_nGameCode));FUN_14156ac20(e,static_cast<unsigned int>(m_nServerCode));}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141594980: decodes a framed full-name response.
unsigned int CNMGetGameServerNameFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetGameServerNameFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141594A10: dispatches decoding according to response format.
unsigned int CNMGetGameServerNameFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetGameServerNameFunc::DecodeFramed(pStream);
    return CNMGetGameServerNameFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141594A70: reads the 0x80-byte server name on replies, or game code on requests.
unsigned int CNMGetGameServerNameFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(!FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using F=void(__fastcall*)(void*,void*,unsigned int);reinterpret_cast<F>(v[9])(d,m_szName,0x80);}else{void**v=*reinterpret_cast<void***>(d);using F=unsigned(__fastcall*)(void*);m_nGameCode=static_cast<int>(reinterpret_cast<F>(v[3])(d));m_nServerCode=static_cast<int>(reinterpret_cast<F>(v[3])(d));}return FUN_1415fb750(d);}
// MS2-PIN: ??0CNMGetGameServerNameFunc@@QEAA@XZ 0x141594740
// MS2-PIN: ??0CNMGetGameServerNameFunc@@QEAA@HH@Z 0x1415947B0
// MS2-PIN: ?EncodeFramed@CNMGetGameServerNameFunc@@UEAAIPEAVCNMStream@@@Z 0x141594830
// MS2-PIN: ?EncodeDispatch@CNMGetGameServerNameFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141594890
// MS2-PIN: ?Encode@CNMGetGameServerNameFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415948F0
// MS2-PIN: ?DecodeFramed@CNMGetGameServerNameFunc@@UEAAIPEAVCNMStream@@@Z 0x141594980
// MS2-PIN: ?DecodeDispatch@CNMGetGameServerNameFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141594A10
// MS2-PIN: ?Decode@CNMGetGameServerNameFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141594A70
