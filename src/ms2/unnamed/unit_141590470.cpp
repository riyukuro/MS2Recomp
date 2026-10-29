// Nexon Messenger minimize-all request serialization.
// MS2-UNIT: unit_141590470
// MS2-RANGE: 0x141590470-0x1415907c0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ab00(void*,unsigned char); extern void FUN_1415f9990(void*); extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x141590470: initializes the minimize-all result flag.
CNMMinimizeAllFunc::CNMMinimizeAllFunc():CNMFunc(0x8019,1,0,0),m_30(0){}
// MS2-FUNCTIONAL 0x1415904d0: stores the requested minimize-all flag.
CNMMinimizeAllFunc::CNMMinimizeAllFunc(int value):CNMFunc(0x8019,1,0,0),m_30(value){}
// MS2-FUNCTIONAL 0x141590530: frames the minimize-all request.
unsigned int CNMMinimizeAllFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMMinimizeAllFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141590590: dispatches encoding according to wire format.
unsigned int CNMMinimizeAllFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMMinimizeAllFunc::Encode(pEncoder, pStream);
    return CNMMinimizeAllFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x1415905f0: encodes the requested minimize-all state.
unsigned int CNMMinimizeAllFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this))FUN_14156ab00(e,static_cast<unsigned char>(m_30));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141590660: decodes a framed minimize-all response.
unsigned int CNMMinimizeAllFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMMinimizeAllFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x1415906f0: dispatches decoding according to response format.
unsigned int CNMMinimizeAllFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMMinimizeAllFunc::DecodeFramed(pStream);
    return CNMMinimizeAllFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141590750: reads the returned minimize-all flag.
unsigned int CNMMinimizeAllFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U8=unsigned char(__fastcall*)(void*);m_30=static_cast<int>(reinterpret_cast<U8>(v[1])(d));}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMMinimizeAllFunc@@QEAA@XZ 0x141590470
// MS2-PIN: ??0CNMMinimizeAllFunc@@QEAA@H@Z 0x1415904d0
// MS2-PIN: ?EncodeFramed@CNMMinimizeAllFunc@@UEAAIPEAVCNMStream@@@Z 0x141590530
// MS2-PIN: ?EncodeDispatch@CNMMinimizeAllFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141590590
// MS2-PIN: ?Encode@CNMMinimizeAllFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415905f0
// MS2-PIN: ?DecodeFramed@CNMMinimizeAllFunc@@UEAAIPEAVCNMStream@@@Z 0x141590660
// MS2-PIN: ?DecodeDispatch@CNMMinimizeAllFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415906f0
// MS2-PIN: ?Decode@CNMMinimizeAllFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141590750
