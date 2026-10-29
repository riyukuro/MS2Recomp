// Nexon Messenger session-value request serialization.
// MS2-UNIT: unit_141594ea0
// MS2-RANGE: 0x141594ea0-0x141595360 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*,const void*); extern void FUN_14156ab00(void*,unsigned char); extern void FUN_14156ac20(void*,unsigned int); extern void FUN_1415f9990(void*); extern void FUN_1415fbe70(void*,unsigned int,const void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
CNMSetSessionValueFunc::CNMSetSessionValueFunc() : CNMFunc(0x8006, 1, 0, 0)
{
    m_szName[0] = 0;
    m_szValue[0] = 0;
    m_n150 = 1;
    m_n154 = 0;
}
CNMSetSessionValueFunc::CNMSetSessionValueFunc(const char* name, const char* value, int option) : CNMFunc(0x8006, 1, 0, 0)
{
    if (name)
        FUN_1415fbe70(m_szName, 0x20, name);
    else
        m_szName[0] = 0;
    if (value)
        FUN_1415fbe70(m_szValue, 0x100, value);
    else
        m_szValue[0] = 0;
    m_n150 = option;
    m_n154 = 0;
}
unsigned int CNMSetSessionValueFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSetSessionValueFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
unsigned int CNMSetSessionValueFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSetSessionValueFunc::Encode(pEncoder, pStream);
    return CNMSetSessionValueFunc::EncodeFramed(pStream);
}
unsigned int CNMSetSessionValueFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ae30(e,m_szName);FUN_14156ae30(e,m_szValue);FUN_14156ab00(e,static_cast<unsigned char>(m_n150));FUN_14156ac20(e,static_cast<unsigned int>(m_n154));}FUN_1415f9990(e);return 1;}
unsigned int CNMSetSessionValueFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSetSessionValueFunc::Decode(&decoder, pStream);
}
unsigned int CNMSetSessionValueFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSetSessionValueFunc::DecodeFramed(pStream);
    return CNMSetSessionValueFunc::Decode(pDecoder, pStream);
}
unsigned int CNMSetSessionValueFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
    {
        pDecoder->ReadStringBufAlias(m_szName, 0x20);
        pDecoder->ReadStringBufAlias(m_szValue, 0x100);
        m_n150 = pDecoder->ReadU8();
        m_n154 = pDecoder->ReadU32();
    }
    return FUN_1415fb750(pDecoder);
}
// MS2-PIN: ??0CNMSetSessionValueFunc@@QEAA@XZ 0x141594ea0
// MS2-PIN: ??0CNMSetSessionValueFunc@@QEAA@PEBD0H@Z 0x141594f30
// MS2-PIN: ?EncodeFramed@CNMSetSessionValueFunc@@UEAAIPEAVCNMStream@@@Z 0x141595020
// MS2-PIN: ?EncodeDispatch@CNMSetSessionValueFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141595080
// MS2-PIN: ?Encode@CNMSetSessionValueFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415950e0
// MS2-PIN: ?DecodeFramed@CNMSetSessionValueFunc@@UEAAIPEAVCNMStream@@@Z 0x141595190
// MS2-PIN: ?DecodeDispatch@CNMSetSessionValueFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141595220
// MS2-PIN: ?Decode@CNMSetSessionValueFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141595280
