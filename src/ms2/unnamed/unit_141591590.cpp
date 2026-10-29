// Nexon Messenger execute-common request serialization.
// MS2-UNIT: unit_141591590
// MS2-RANGE: 0x141591590-0x141591960 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ae30(void*,const void*); extern void FUN_1415fbe70(void*,unsigned int,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x141591590: initializes an empty execute-common request.
CNMExecuteCommonFunc::CNMExecuteCommonFunc():CNMFunc(0x8003,1,0,0),m_30(0),m_34{}{}
// MS2-FUNCTIONAL 0x141591600: stores the request code and bounded argument.
CNMExecuteCommonFunc::CNMExecuteCommonFunc(int code,const char*argument):CNMFunc(0x8003,1,0,0),m_30(code),m_34{}{if(argument)FUN_1415fbe70(m_34,0x400,argument);}
// MS2-FUNCTIONAL 0x1415916a0: frames the execute-common request.
unsigned int CNMExecuteCommonFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMExecuteCommonFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141591700: dispatches encoding according to wire format.
unsigned int CNMExecuteCommonFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMExecuteCommonFunc::Encode(pEncoder, pStream);
    return CNMExecuteCommonFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141591760: encodes the operation code and argument.
unsigned int CNMExecuteCommonFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,static_cast<unsigned int>(m_30));FUN_14156ae30(e,m_34);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x1415917e0: decodes a framed execute-common response.
unsigned int CNMExecuteCommonFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMExecuteCommonFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141591870: dispatches decoding according to response format.
unsigned int CNMExecuteCommonFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMExecuteCommonFunc::DecodeFramed(pStream);
    return CNMExecuteCommonFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x1415918d0: restores the operation code and argument.
unsigned int CNMExecuteCommonFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);using B=void(__fastcall*)(void*,void*,unsigned);m_30=static_cast<int>(reinterpret_cast<U>(v[3])(d));reinterpret_cast<B>(v[9])(d,m_34,0x400);}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMExecuteCommonFunc@@QEAA@XZ 0x141591590
// MS2-PIN: ??0CNMExecuteCommonFunc@@QEAA@HPEBD@Z 0x141591600
// MS2-PIN: ?EncodeFramed@CNMExecuteCommonFunc@@UEAAIPEAVCNMStream@@@Z 0x1415916a0
// MS2-PIN: ?EncodeDispatch@CNMExecuteCommonFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141591700
// MS2-PIN: ?Encode@CNMExecuteCommonFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141591760
// MS2-PIN: ?DecodeFramed@CNMExecuteCommonFunc@@UEAAIPEAVCNMStream@@@Z 0x1415917e0
// MS2-PIN: ?DecodeDispatch@CNMExecuteCommonFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141591870
// MS2-PIN: ?Decode@CNMExecuteCommonFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415918d0
