// Nexon Messenger restricted-words request serialization.
// MS2-UNIT: unit_14158ff90
// MS2-RANGE: 0x14158ff90-0x141590470 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ae30(void*,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void* FUN_1415e5b60(void*); extern void FUN_1415e5b20(void*,const void*); extern void* FUN_1415f39e0(void*);
extern unsigned int FUN_1415fa080(void*); extern void* FUN_1415f9fe0(void*);
// MS2-FUNCTIONAL 0x14158ff90: initializes restriction mode and its fixed string.
CNMRestrictedWordsFunc::CNMRestrictedWordsFunc():CNMFunc(0x8018,1,0,0),m_30(1),m_34(0),m_38(),m_40(0),m_44(0){FUN_1415e5b60(&m_38);}
// MS2-FUNCTIONAL 0x141590020: stores restriction mode, category, and supplied words.
CNMRestrictedWordsFunc::CNMRestrictedWordsFunc(int mode,int category,const char* words):CNMFunc(0x8018,1,0,0),m_30(mode),m_34(category),m_38(),m_40(0),m_44(0){FUN_1415e5b60(&m_38);FUN_1415e5b20(&m_38,words);}
// MS2-FUNCTIONAL 0x1415900c0: frames the restricted-words request.
unsigned int CNMRestrictedWordsFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRestrictedWordsFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141590120: dispatches encoding according to message format.
unsigned int CNMRestrictedWordsFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRestrictedWordsFunc::Encode(pEncoder, pStream);
    return CNMRestrictedWordsFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141590180: encodes a query or the returned restriction records.
unsigned int CNMRestrictedWordsFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
        FUN_14156ae30(pEncoder, FUN_1415f39e0(&m_38));
    }
    else
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_40));
        if (m_30 == 2)
            FUN_14156ae30(pEncoder, FUN_1415f39e0(&m_38));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}
// MS2-FUNCTIONAL 0x141590250: decodes a framed restricted-words response.
unsigned int CNMRestrictedWordsFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRestrictedWordsFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x1415902e0: dispatches decoding according to response format.
unsigned int CNMRestrictedWordsFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRestrictedWordsFunc::DecodeFramed(pStream);
    return CNMRestrictedWordsFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141590340: reads the request result and optional word string.
unsigned int CNMRestrictedWordsFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
    {
        m_30 = pDecoder->ReadU32();
        m_34 = pDecoder->ReadU32();
        pDecoder->ReadStringBufAlias(static_cast<char*>(FUN_1415f9fe0(&m_38)), FUN_1415fa080(&m_38));
    }
    else
    {
        m_40 = pDecoder->ReadU32();
        if (m_30 == 2)
            pDecoder->ReadStringBufAlias(static_cast<char*>(FUN_1415f9fe0(&m_38)), FUN_1415fa080(&m_38));
    }
    return FUN_1415fb750(pDecoder);
}
// MS2-PIN: ??0CNMRestrictedWordsFunc@@QEAA@XZ 0x14158ff90
// MS2-PIN: ??0CNMRestrictedWordsFunc@@QEAA@HHPEBD@Z 0x141590020
// MS2-PIN: ?EncodeFramed@CNMRestrictedWordsFunc@@UEAAIPEAVCNMStream@@@Z 0x1415900c0
// MS2-PIN: ?EncodeDispatch@CNMRestrictedWordsFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141590120
// MS2-PIN: ?Encode@CNMRestrictedWordsFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141590180
// MS2-PIN: ?DecodeFramed@CNMRestrictedWordsFunc@@UEAAIPEAVCNMStream@@@Z 0x141590250
// MS2-PIN: ?DecodeDispatch@CNMRestrictedWordsFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415902e0
// MS2-PIN: ?Decode@CNMRestrictedWordsFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141590340
