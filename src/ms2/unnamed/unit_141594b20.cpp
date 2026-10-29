// Nexon Messenger path request serialization.
// MS2-UNIT: unit_141594b20
// MS2-RANGE: 0x141594b20-0x141594ea0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ae30(void*,void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x141594B20: initializes the request and empty reply buffer.
CNMGetPathFunc::CNMGetPathFunc():CNMFunc(0x8005,1,0,0),m_30(0),m_34{}{}
// MS2-FUNCTIONAL 0x141594B80: stores the requested game code and clears the reply buffer.
CNMGetPathFunc::CNMGetPathFunc(int code):CNMFunc(0x8005,1,0,0),m_30(code),m_34{}{}
// MS2-FUNCTIONAL 0x141594BE0: frames the path request.
unsigned int CNMGetPathFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetPathFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141594C40: dispatches encoding according to message format.
unsigned int CNMGetPathFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetPathFunc::Encode(pEncoder, pStream);
    return CNMGetPathFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141594CA0: writes the name on replies and the game code on requests.
unsigned int CNMGetPathFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this))FUN_14156ae30(e,m_34);else FUN_14156ac20(e,static_cast<unsigned int>(m_30));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141594D20: decodes a framed full-name response.
unsigned int CNMGetPathFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetPathFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141594DB0: dispatches decoding according to response format.
unsigned int CNMGetPathFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetPathFunc::DecodeFramed(pStream);
    return CNMGetPathFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141594E10: reads the 0x420-byte path on replies, or game code on requests.
unsigned int CNMGetPathFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(!FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using F=void(__fastcall*)(void*,void*,unsigned int);reinterpret_cast<F>(v[9])(d,m_34,0x104);}else{void**v=*reinterpret_cast<void***>(d);using F=unsigned(__fastcall*)(void*);m_30=static_cast<int>(reinterpret_cast<F>(v[3])(d));}return FUN_1415fb750(d);}
// MS2-PIN: ??0CNMGetPathFunc@@QEAA@XZ 0x141594B20
// MS2-PIN: ??0CNMGetPathFunc@@QEAA@H@Z 0x141594B80
// MS2-PIN: ?EncodeFramed@CNMGetPathFunc@@UEAAIPEAVCNMStream@@@Z 0x141594BE0
// MS2-PIN: ?EncodeDispatch@CNMGetPathFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141594C40
// MS2-PIN: ?Encode@CNMGetPathFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141594CA0
// MS2-PIN: ?DecodeFramed@CNMGetPathFunc@@UEAAIPEAVCNMStream@@@Z 0x141594D20
// MS2-PIN: ?DecodeDispatch@CNMGetPathFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141594DB0
// MS2-PIN: ?Decode@CNMGetPathFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141594E10
