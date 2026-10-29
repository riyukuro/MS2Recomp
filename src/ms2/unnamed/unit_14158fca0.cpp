// Nexon Messenger NGM-installed query serialization.
// MS2-UNIT: unit_14158fca0
// MS2-RANGE: 0x14158fca0-0x14158ff90 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_1415f9990(void*); extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x14158fca0: initializes the NGM-installed result to false.
CNMIsNGMInstalledFunc::CNMIsNGMInstalledFunc():CNMFunc(0x8017,1,0,0),m_bInstalled(0),m_n34(0){}
// MS2-FUNCTIONAL 0x14158fd00: frames the installed-state query.
unsigned int CNMIsNGMInstalledFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMIsNGMInstalledFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x14158fd60: dispatches encoding according to wire format.
unsigned int CNMIsNGMInstalledFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMIsNGMInstalledFunc::Encode(pEncoder, pStream);
    return CNMIsNGMInstalledFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x14158fdc0: emits the result value when encoding a request.
unsigned int CNMIsNGMInstalledFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this))FUN_14156ac20(e,static_cast<unsigned int>(m_bInstalled));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14158fe30: decodes a framed installed-state response.
unsigned int CNMIsNGMInstalledFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMIsNGMInstalledFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x14158fec0: dispatches decoding according to response format.
unsigned int CNMIsNGMInstalledFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMIsNGMInstalledFunc::DecodeFramed(pStream);
    return CNMIsNGMInstalledFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x14158ff20: restores the installed-state result.
unsigned int CNMIsNGMInstalledFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(!FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);m_bInstalled=static_cast<int>(reinterpret_cast<U>(v[3])(d));}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMIsNGMInstalledFunc@@QEAA@XZ 0x14158fca0
// MS2-PIN: ?EncodeFramed@CNMIsNGMInstalledFunc@@UEAAIPEAVCNMStream@@@Z 0x14158fd00
// MS2-PIN: ?EncodeDispatch@CNMIsNGMInstalledFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158fd60
// MS2-PIN: ?Encode@CNMIsNGMInstalledFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158fdc0
// MS2-PIN: ?DecodeFramed@CNMIsNGMInstalledFunc@@UEAAIPEAVCNMStream@@@Z 0x14158fe30
// MS2-PIN: ?DecodeDispatch@CNMIsNGMInstalledFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158fec0
// MS2-PIN: ?Decode@CNMIsNGMInstalledFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158ff20
