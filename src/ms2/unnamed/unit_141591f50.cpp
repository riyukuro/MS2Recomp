// Nexon Messenger extended URL query serialization.
// MS2-UNIT: unit_141591f50
// MS2-RANGE: 0x141591f50-0x141592580 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156acb0(void*,unsigned __int64); extern void FUN_14156ab00(void*,unsigned char); extern void FUN_14156ae30(void*,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x141591f50: initializes URL type one and clears all query/result fields.
CNMGetUrlExFunc::CNMGetUrlExFunc():CNMFunc(0x8009,1,0,0),m_nUrlType(1),m_nGameCode(0),m_n38(0),m_n3c(0),m_n40(0),m_sz48{},m_n248(0),m_sz24c{},m_n34c(0),m_n350(0),m_n354(0),m_n358(0x10000),m_szUrl{}{}
// MS2-FUNCTIONAL 0x141592050: frames an extended URL request.
unsigned int CNMGetUrlExFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetUrlExFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x1415920b0: dispatches encoding according to message format.
unsigned int CNMGetUrlExFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetUrlExFunc::Encode(pEncoder, pStream);
    return CNMGetUrlExFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141592110: encodes the selected URL query and the returned URL/settings.
unsigned int CNMGetUrlExFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ac20(pEncoder, m_nUrlType);
        if (m_nUrlType == 1) FUN_14156ac20(pEncoder, m_nGameCode);
        if (m_nUrlType == 2) FUN_14156ac20(pEncoder, m_n38);
        if (m_nUrlType == 3) FUN_14156acb0(pEncoder, m_n40);
        if (m_nUrlType == 4) FUN_14156ae30(pEncoder, m_sz48);
        FUN_14156ac20(pEncoder, m_n248);
        FUN_14156ae30(pEncoder, m_sz24c);
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_n34c));
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_n350));
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_n354));
        FUN_14156ac20(pEncoder, m_n358);
    }
    else
    {
        FUN_14156ae30(pEncoder, m_szUrl);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}
// MS2-FUNCTIONAL 0x141592290: decodes a framed extended URL response.
unsigned int CNMGetUrlExFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetUrlExFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141592320: dispatches decoding according to response format.
unsigned int CNMGetUrlExFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetUrlExFunc::DecodeFramed(pStream);
    return CNMGetUrlExFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141592380: restores the selected URL query fields and response URL.
unsigned int CNMGetUrlExFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_nUrlType = pDecoder->ReadU32();
        if (m_nUrlType == 1) m_nGameCode = pDecoder->ReadU32();
        if (m_nUrlType == 2) m_n38 = pDecoder->ReadU32();
        if (m_nUrlType == 3) m_n40 = pDecoder->ReadU64();
        if (m_nUrlType == 4) pDecoder->ReadStringBufAlias(m_sz48, 0x200);
        m_n248 = pDecoder->ReadU32();
        pDecoder->ReadStringBufAlias(m_sz24c, 0x100);
        m_n34c = pDecoder->ReadU8();
        m_n350 = pDecoder->ReadU8();
        m_n354 = pDecoder->ReadU8();
        m_n358 = pDecoder->ReadU32();
    }
    else
    {
        pDecoder->ReadStringBufAlias(m_szUrl, 0x400);
    }
    return FUN_1415fb750(pDecoder);
}
// MS2-PIN: ??0CNMGetUrlExFunc@@QEAA@XZ 0x141591f50
// MS2-PIN: ?EncodeFramed@CNMGetUrlExFunc@@UEAAIPEAVCNMStream@@@Z 0x141592050
// MS2-PIN: ?EncodeDispatch@CNMGetUrlExFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415920b0
// MS2-PIN: ?Encode@CNMGetUrlExFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141592110
// MS2-PIN: ?DecodeFramed@CNMGetUrlExFunc@@UEAAIPEAVCNMStream@@@Z 0x141592290
// MS2-PIN: ?DecodeDispatch@CNMGetUrlExFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141592320
// MS2-PIN: ?Decode@CNMGetUrlExFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141592380
