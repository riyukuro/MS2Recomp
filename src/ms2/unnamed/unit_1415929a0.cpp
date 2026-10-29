// Nexon Messenger download-file request serialization.
// MS2-UNIT: unit_1415929a0
// MS2-RANGE: 0x1415929a0-0x141592dc0 .text$mn
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
// MS2-FUNCTIONAL 0x1415929a0: initializes empty URL and output-path buffers.
CNMDownloadFileFunc::CNMDownloadFileFunc():CNMFunc(0x800a,1,0,0),m_szUrl{},m_szPath{}{}
// MS2-FUNCTIONAL 0x141592a10: stores bounded URL and output path values.
CNMDownloadFileFunc::CNMDownloadFileFunc(const char*url,const char*path):CNMFunc(0x800a,1,0,0),m_szUrl{},m_szPath{}{if(url)FUN_1415fbe70(m_szUrl,0x100,url);if(path)FUN_1415fbe70(m_szPath,0x100,path);}
// MS2-FUNCTIONAL 0x141592ae0: frames the download request.
unsigned int CNMDownloadFileFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMDownloadFileFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141592b40: dispatches encoding according to wire format.
unsigned int CNMDownloadFileFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMDownloadFileFunc::Encode(pEncoder, pStream);
    return CNMDownloadFileFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141592ba0: serializes the URL and local path.
unsigned int CNMDownloadFileFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ae30(e,m_szUrl);FUN_14156ae30(e,m_szPath);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141592c20: decodes a framed download response.
unsigned int CNMDownloadFileFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMDownloadFileFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141592cb0: dispatches decoding according to response format.
unsigned int CNMDownloadFileFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMDownloadFileFunc::DecodeFramed(pStream);
    return CNMDownloadFileFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141592d10: restores URL and local path values.
unsigned int CNMDownloadFileFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using B=void(__fastcall*)(void*,void*,unsigned);reinterpret_cast<B>(v[9])(d,m_szUrl,0x100);reinterpret_cast<B>(v[9])(d,m_szPath,0x100);}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMDownloadFileFunc@@QEAA@XZ 0x1415929a0
// MS2-PIN: ??0CNMDownloadFileFunc@@QEAA@PEBD0@Z 0x141592a10
// MS2-PIN: ?EncodeFramed@CNMDownloadFileFunc@@UEAAIPEAVCNMStream@@@Z 0x141592ae0
// MS2-PIN: ?EncodeDispatch@CNMDownloadFileFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141592b40
// MS2-PIN: ?Encode@CNMDownloadFileFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141592ba0
// MS2-PIN: ?DecodeFramed@CNMDownloadFileFunc@@UEAAIPEAVCNMStream@@@Z 0x141592c20
// MS2-PIN: ?DecodeDispatch@CNMDownloadFileFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141592cb0
// MS2-PIN: ?Decode@CNMDownloadFileFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141592d10
