// Nexon Messenger execute-NGM-patcher request serialization.
// MS2-UNIT: unit_14158e360
// MS2-RANGE: 0x14158e360-0x14158eb50 .text$mn
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
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415fbe70(void*, unsigned int, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14158e360: initializes all fixed buffers and default result fields.
CNMExecuteNGMPatcherFunc::CNMExecuteNGMPatcherFunc()
    : CNMFunc(0x8015, 1, 0, 0), m_nGameCode(0), m_sz2{}, m_sz3{}, m_sz4{}, m_pad8537(0),
      m_n5(1), m_n6(0), m_n7(0), m_sz8{}, m_n9(0), m_sz10{}, m_n11(0) {}

// @0x14158e470
CNMExecuteNGMPatcherFunc::CNMExecuteNGMPatcherFunc(int gameCode, const char* sz2, const char* sz3, const char* sz4,
                                                   int n5, int n6, int n7, const char* sz8, int n9,
                                                   const char* sz10, int n11)
    : CNMFunc(0x8015, 1, 0, 0)
{
    m_nGameCode = gameCode;
    if (sz2) FUN_1415fbe70(m_sz2, 0x7fff, sz2);
    else m_sz2[0] = 0;
    if (sz3) FUN_1415fbe70(m_sz3, 0x104, sz3);
    else m_sz3[0] = 0;
    if (sz4) FUN_1415fbe70(m_sz4, 0x400, sz4);
    else m_sz4[0] = 0;
    m_n5 = n5;
    m_n6 = n6;
    m_n7 = n7;
    if (sz8) FUN_1415fbe70(m_sz8, 0x20, sz8);
    else m_sz8[0] = 0;
    m_n9 = n9;
    if (sz10) FUN_1415fbe70(m_sz10, 0x80, sz10);
    else m_sz10[0] = 0;
    m_n11 = n11;
}

// MS2-FUNCTIONAL 0x14158e670: frames a serialized NGM patcher request.
unsigned int CNMExecuteNGMPatcherFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMExecuteNGMPatcherFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158e6d0: dispatches encoding based on the message format.
unsigned int CNMExecuteNGMPatcherFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMExecuteNGMPatcherFunc::Encode(pEncoder, pStream);
    return CNMExecuteNGMPatcherFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14158e730: serializes patch paths, options, and output settings.
unsigned int CNMExecuteNGMPatcherFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_nGameCode));
        FUN_14156ae30(encoder, m_sz2);
        FUN_14156ae30(encoder, m_sz3);
        FUN_14156ae30(encoder, m_sz4);
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n5));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n6));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n7));
        FUN_14156ae30(encoder, m_sz8);
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n9));
        FUN_14156ae30(encoder, m_sz10);
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n11));
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158e880: decodes a framed NGM patcher response.
unsigned int CNMExecuteNGMPatcherFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMExecuteNGMPatcherFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158e910: dispatches decoding by response format.
unsigned int CNMExecuteNGMPatcherFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMExecuteNGMPatcherFunc::DecodeFramed(pStream);
    return CNMExecuteNGMPatcherFunc::Decode(pDecoder, pStream);
}

// @0x14158e970
unsigned int CNMExecuteNGMPatcherFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        m_nGameCode = decoder->ReadU32();
        decoder->ReadStringBufAlias(m_sz2, 0x7fff);
        decoder->ReadStringBufAlias(m_sz3, 0x104);
        decoder->ReadStringBufAlias(m_sz4, 0x400);
        m_n5 = decoder->ReadU32();
        m_n6 = decoder->ReadU32();
        m_n7 = decoder->ReadU32();
        decoder->ReadStringBufAlias(m_sz8, 0x20);
        m_n9 = decoder->ReadU32();
        decoder->ReadStringBufAlias(m_sz10, 0x80);
        m_n11 = decoder->ReadU32();
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMExecuteNGMPatcherFunc@@QEAA@XZ 0x14158e360
// MS2-PIN: ??0CNMExecuteNGMPatcherFunc@@QEAA@HPEBD00HHH0H0H@Z 0x14158e470
// MS2-PIN: ?EncodeFramed@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158e670
// MS2-PIN: ?EncodeDispatch@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158e6d0
// MS2-PIN: ?Encode@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158e730
// MS2-PIN: ?DecodeFramed@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158e880
// MS2-PIN: ?DecodeDispatch@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158e910
// MS2-PIN: ?Decode@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158e970
