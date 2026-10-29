// Nexon Messenger finalization request serialization.
// MS2-UNIT: unit_1415a79d0
// MS2-RANGE: 0x1415a79d0-0x1415a7c70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x1415a79d0: initializes the finalization function request.
// @0x1415a79d0
CNMFinalizeFunc::CNMFinalizeFunc() : CNMFunc(0x1114, 1, 0, 0)
{
}

// MS2-FUNCTIONAL 0x1415a7a20: wraps the request encoder in the stream frame.
// @0x1415a7a20
unsigned int CNMFinalizeFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMFinalizeFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415a7a80: selects direct or framed request encoding.
// @0x1415a7a80
unsigned int CNMFinalizeFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMFinalizeFunc::Encode(pEncoder, pStream);
    return CNMFinalizeFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415a7ae0: finalizes the empty request payload.
// @0x1415a7ae0
unsigned int CNMFinalizeFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    (void)FUN_1415fb700(this);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415a7b30: decodes a framed finalization response.
// @0x1415a7b30
unsigned int CNMFinalizeFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMFinalizeFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415a7bc0: selects direct or framed response decoding.
// @0x1415a7bc0
unsigned int CNMFinalizeFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMFinalizeFunc::DecodeFramed(pStream);
    return CNMFinalizeFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415a7c20: validates the empty response payload.
// @0x1415a7c20
unsigned int CNMFinalizeFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    (void)FUN_1415fb700(this);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMFinalizeFunc@@QEAA@XZ 0x1415a79d0
// MS2-PIN: ?EncodeFramed@CNMFinalizeFunc@@UEAAIPEAVCNMStream@@@Z 0x1415a7a20
// MS2-PIN: ?EncodeDispatch@CNMFinalizeFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a7a80
// MS2-PIN: ?Encode@CNMFinalizeFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a7ae0
// MS2-PIN: ?DecodeFramed@CNMFinalizeFunc@@UEAAIPEAVCNMStream@@@Z 0x1415a7b30
// MS2-PIN: ?DecodeDispatch@CNMFinalizeFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a7bc0
// MS2-PIN: ?Decode@CNMFinalizeFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a7c20
