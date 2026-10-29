// Nexon Messenger execute-NGM-launcher request serialization.
// MS2-UNIT: unit_14158ef30
// MS2-RANGE: 0x14158ef30-0x14158f620 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*, void*, void*); extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*, const void*); extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415fbe70(void*, unsigned int, const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14158ef30: initializes an empty launcher request.
CNMExecuteNGMLauncherFunc::CNMExecuteNGMLauncherFunc()
 : CNMFunc(0x8016,1,0,0)
{
    m_nGameCode = 0;
    m_n34 = 0;
    m_sz38[0] = 0;
    m_n438 = 1;
    m_sz43c[0] = 0;
    m_n83c = 0;
    m_sz840[0] = 0;
    m_sz848[0] = 0;
    m_n8c8 = 0;
}
// MS2-FUNCTIONAL 0x14158f010: stores NGM launcher parameters in bounded fields.
CNMExecuteNGMLauncherFunc::CNMExecuteNGMLauncherFunc(int gameCode,int n2,const char* sz3,int n4,const char* sz5,int n6,const char* sz7,const char* sz8,int n9)
 : CNMFunc(0x8016,1,0,0)
{
    m_nGameCode = gameCode;
    m_n34 = n2;
    if (sz3) FUN_1415fbe70(m_sz38, 0x400, sz3); else m_sz38[0] = 0;
    m_n438 = n4;
    if (sz5) FUN_1415fbe70(m_sz43c, 0x400, sz5); else m_sz43c[0] = 0;
    m_n83c = n6;
    if (sz7) FUN_1415fbe70(m_sz840, 8, sz7); else m_sz840[0] = 0;
    if (sz8) FUN_1415fbe70(m_sz848, 0x80, sz8); else m_sz848[0] = 0;
    m_n8c8 = n9;
}
// MS2-FUNCTIONAL 0x14158f1c0: frames the launcher request.
unsigned int CNMExecuteNGMLauncherFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMExecuteNGMLauncherFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x14158f220: dispatches encoding according to wire format.
unsigned int CNMExecuteNGMLauncherFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMExecuteNGMLauncherFunc::Encode(pEncoder, pStream);
    return CNMExecuteNGMLauncherFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x14158f280: serializes launcher values.
unsigned int CNMExecuteNGMLauncherFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,m_nGameCode);FUN_14156ac20(e,m_n34);FUN_14156ae30(e,m_sz38);FUN_14156ac20(e,m_n438);FUN_14156ae30(e,m_sz43c);FUN_14156ac20(e,m_n83c);FUN_14156ae30(e,m_sz840);FUN_14156ae30(e,m_sz848);FUN_14156ac20(e,m_n8c8);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14158f3a0: decodes a framed launcher response.
unsigned int CNMExecuteNGMLauncherFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMExecuteNGMLauncherFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x14158f430: dispatches decoding according to response format.
unsigned int CNMExecuteNGMLauncherFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMExecuteNGMLauncherFunc::DecodeFramed(pStream);
    return CNMExecuteNGMLauncherFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x14158f490: restores launcher values from the reply.
unsigned int CNMExecuteNGMLauncherFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        m_nGameCode = pDecoder->ReadU32();
        m_n34 = pDecoder->ReadU32();
        pDecoder->ReadStringBufAlias(m_sz38, 0x400);
        m_n438 = pDecoder->ReadU32();
        pDecoder->ReadStringBufAlias(m_sz43c, 0x400);
        m_n83c = pDecoder->ReadU32();
        pDecoder->ReadStringBufAlias(m_sz840, 8);
        pDecoder->ReadStringBufAlias(m_sz848, 0x80);
        m_n8c8 = pDecoder->ReadU32();
    }
    return static_cast<unsigned>(FUN_1415fb750(pDecoder));
}
// MS2-PIN: ??0CNMExecuteNGMLauncherFunc@@QEAA@XZ 0x14158ef30
// MS2-PIN: ??0CNMExecuteNGMLauncherFunc@@QEAA@HHPEBDH0H00H@Z 0x14158f010
// MS2-PIN: ?EncodeFramed@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158f1c0
// MS2-PIN: ?EncodeDispatch@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158f220
// MS2-PIN: ?Encode@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158f280
// MS2-PIN: ?DecodeFramed@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158f3a0
// MS2-PIN: ?DecodeDispatch@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158f430
// MS2-PIN: ?Decode@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158f490
