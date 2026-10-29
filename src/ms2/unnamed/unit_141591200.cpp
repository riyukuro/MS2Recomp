// Nexon Messenger write-to-wiselog request serialization.
// MS2-UNIT: unit_141591200
// MS2-RANGE: 0x141591200-0x141591590 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*,const void*); extern void FUN_1415fbe70(void*,unsigned int,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x141591200: initializes an empty log message.
CNMWriteToWiselogFunc::CNMWriteToWiselogFunc():CNMFunc(0x801f,1,0,0),m_text{}{}
// MS2-FUNCTIONAL 0x141591260: copies a bounded log message.
CNMWriteToWiselogFunc::CNMWriteToWiselogFunc(const char*text):CNMFunc(0x801f,1,0,0),m_text{}{if(text)FUN_1415fbe70(m_text,0x400,text);}
// MS2-FUNCTIONAL 0x1415912f0: frames the wiselog request.
unsigned int CNMWriteToWiselogFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMWriteToWiselogFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141591350: dispatches encoding according to wire format.
unsigned int CNMWriteToWiselogFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMWriteToWiselogFunc::Encode(pEncoder, pStream);
    return CNMWriteToWiselogFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x1415913b0: encodes the wiselog message.
unsigned int CNMWriteToWiselogFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this))FUN_14156ae30(e,m_text);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141591420: decodes a framed wiselog response.
unsigned int CNMWriteToWiselogFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMWriteToWiselogFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x1415914b0: dispatches decoding according to response format.
unsigned int CNMWriteToWiselogFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMWriteToWiselogFunc::DecodeFramed(pStream);
    return CNMWriteToWiselogFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141591510: reads the wiselog response message.
unsigned int CNMWriteToWiselogFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using B=void(__fastcall*)(void*,void*,unsigned);reinterpret_cast<B>(v[9])(d,m_text,0x400);}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMWriteToWiselogFunc@@QEAA@XZ 0x141591200
// MS2-PIN: ??0CNMWriteToWiselogFunc@@QEAA@PEBD@Z 0x141591260
// MS2-PIN: ?EncodeFramed@CNMWriteToWiselogFunc@@UEAAIPEAVCNMStream@@@Z 0x1415912f0
// MS2-PIN: ?EncodeDispatch@CNMWriteToWiselogFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141591350
// MS2-PIN: ?Encode@CNMWriteToWiselogFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415913b0
// MS2-PIN: ?DecodeFramed@CNMWriteToWiselogFunc@@UEAAIPEAVCNMStream@@@Z 0x141591420
// MS2-PIN: ?DecodeDispatch@CNMWriteToWiselogFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415914b0
// MS2-PIN: ?Decode@CNMWriteToWiselogFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141591510
