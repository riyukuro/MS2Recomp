// Nexon Messenger upload-file request serialization.
// MS2-UNIT: unit_141592dc0
// MS2-RANGE: 0x141592dc0-0x141593360 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*,const void*); extern void FUN_14156ab00(void*,unsigned char); extern void FUN_1415fbe70(void*,unsigned int,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// Empty upload request: the strings are terminated at [0] only.
// @0x141592dc0
CNMUploadFileFunc::CNMUploadFileFunc()
    : CNMFunc(0x800b, 1, 0, 0)
{
    m_szUrl[0] = 0;
    m_sz430[0] = 0;
    m_sz530[0] = 0;
    m_szResult[0] = 0;
    m_n630 = 0;
}
// Copies the bounded upload parameters (an empty string for a null one) and stores the option.
// @0x141592e70
CNMUploadFileFunc::CNMUploadFileFunc(const char* url, const char* a, const char* b, int option)
    : CNMFunc(0x800b, 1, 0, 0)
{
    if (url)
        FUN_1415fbe70(m_szUrl, 0x400, url);
    else
        m_szUrl[0] = 0;
    if (a)
        FUN_1415fbe70(m_sz430, 0x100, a);
    else
        m_sz430[0] = 0;
    if (b)
        FUN_1415fbe70(m_sz530, 0x100, b);
    else
        m_sz530[0] = 0;
    m_szResult[0] = 0;
    m_n630 = option;
}
// Frames the upload request.
// @0x141592fb0
unsigned int CNMUploadFileFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMUploadFileFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// Dispatches encoding by message format.
// @0x141593010
unsigned int CNMUploadFileFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMUploadFileFunc::Encode(pEncoder, pStream);
    return CNMUploadFileFunc::EncodeFramed(pStream);
}
// Encodes the upload inputs for a request, or the result for a reply.
// @0x141593070
unsigned int CNMUploadFileFunc::Encode(CNMEncoder* e, CNMStream* s)
{
    CNMFunc::EncodeDispatch(e, s);
    if (FUN_1415fb700(this)) {
        FUN_14156ae30(e, m_szUrl);
        FUN_14156ae30(e, m_sz430);
        FUN_14156ae30(e, m_sz530);
        FUN_14156ab00(e, static_cast<unsigned char>(m_n630));
    } else {
        FUN_14156ae30(e, m_szResult);
    }
    FUN_1415f9990(e);
    return 1;
}
// Decodes a framed upload response.
// @0x141593140
unsigned int CNMUploadFileFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMUploadFileFunc::Decode(&decoder, pStream);
}
// Dispatches decoding by response format.
// @0x1415931d0
unsigned int CNMUploadFileFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMUploadFileFunc::DecodeFramed(pStream);
    return CNMUploadFileFunc::Decode(pDecoder, pStream);
}
// Restores the upload inputs for a request, or the result for a reply.
// @0x141593230
unsigned int CNMUploadFileFunc::Decode(CNMSerializableDecoder* d, CNMStream* s)
{
    CNMFunc::DecodeDispatch(d, s);
    if (FUN_1415fb700(this)) {
        d->ReadStringBufAlias(m_szUrl, 0x400);
        d->ReadStringBufAlias(m_sz430, 0x100);
        d->ReadStringBufAlias(m_sz530, 0x100);
        m_n630 = d->ReadU8();
    } else {
        d->ReadStringBufAlias(m_szResult, 0x400);
    }
    return static_cast<unsigned>(FUN_1415fb750(d));
}
// MS2-PIN: ??0CNMUploadFileFunc@@QEAA@XZ 0x141592dc0
// MS2-PIN: ??0CNMUploadFileFunc@@QEAA@PEBD00H@Z 0x141592e70
// MS2-PIN: ?EncodeFramed@CNMUploadFileFunc@@UEAAIPEAVCNMStream@@@Z 0x141592fb0
// MS2-PIN: ?EncodeDispatch@CNMUploadFileFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141593010
// MS2-PIN: ?Encode@CNMUploadFileFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141593070
// MS2-PIN: ?DecodeFramed@CNMUploadFileFunc@@UEAAIPEAVCNMStream@@@Z 0x141593140
// MS2-PIN: ?DecodeDispatch@CNMUploadFileFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415931d0
// MS2-PIN: ?Decode@CNMUploadFileFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141593230
