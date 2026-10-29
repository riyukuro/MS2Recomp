// Nexon Messenger game full-name request serialization.
// MS2-UNIT: unit_141593c60
// MS2-RANGE: 0x141593c60-0x141594000 .text$mn
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
// MS2-FUNCTIONAL 0x141593c60: initializes the request and empty reply buffer.
CNMGetGameFullNameFunc::CNMGetGameFullNameFunc():CNMFunc(0x800e,1,0,0),m_nGameCode(0),m_szName{}{}
// MS2-FUNCTIONAL 0x141593cd0: stores the requested game code and clears the reply buffer.
CNMGetGameFullNameFunc::CNMGetGameFullNameFunc(int code):CNMFunc(0x800e,1,0,0),m_nGameCode(code),m_szName{}{}
// MS2-FUNCTIONAL 0x141593d40: frames the full-name request.
unsigned int CNMGetGameFullNameFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetGameFullNameFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141593da0: dispatches encoding according to message format.
unsigned int CNMGetGameFullNameFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetGameFullNameFunc::Encode(pEncoder, pStream);
    return CNMGetGameFullNameFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141593e00: writes the name on replies and the game code on requests.
unsigned int CNMGetGameFullNameFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this))FUN_14156ae30(e,m_szName);else FUN_14156ac20(e,static_cast<unsigned int>(m_nGameCode));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141593e80: decodes a framed full-name response.
unsigned int CNMGetGameFullNameFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetGameFullNameFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141593f10: dispatches decoding according to response format.
unsigned int CNMGetGameFullNameFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetGameFullNameFunc::DecodeFramed(pStream);
    return CNMGetGameFullNameFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141593f70: reads the 0x80-byte full name on replies, or game code on requests.
unsigned int CNMGetGameFullNameFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(!FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using F=void(__fastcall*)(void*,void*,unsigned int);reinterpret_cast<F>(v[9])(d,m_szName,0x80);}else{void**v=*reinterpret_cast<void***>(d);using F=unsigned(__fastcall*)(void*);m_nGameCode=static_cast<int>(reinterpret_cast<F>(v[3])(d));}return FUN_1415fb750(d);}
// MS2-PIN: ??0CNMGetGameFullNameFunc@@QEAA@XZ 0x141593c60
// MS2-PIN: ??0CNMGetGameFullNameFunc@@QEAA@H@Z 0x141593cd0
// MS2-PIN: ?EncodeFramed@CNMGetGameFullNameFunc@@UEAAIPEAVCNMStream@@@Z 0x141593d40
// MS2-PIN: ?EncodeDispatch@CNMGetGameFullNameFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141593da0
// MS2-PIN: ?Encode@CNMGetGameFullNameFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141593e00
// MS2-PIN: ?DecodeFramed@CNMGetGameFullNameFunc@@UEAAIPEAVCNMStream@@@Z 0x141593e80
// MS2-PIN: ?DecodeDispatch@CNMGetGameFullNameFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141593f10
// MS2-PIN: ?Decode@CNMGetGameFullNameFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141593f70
