// Recovered from the Nexon Messenger client library: file path record.
// MS2-UNIT: ?\nmfilepath.cpp
// MS2-RANGE: 0x1415731e0-0x1415734a0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: initializes the file-path record with its recovered signature and zeroed path.
// @0x1415731e0
CNMFilePath::CNMFilePath()
    : CNMSerializable(0x6670, 1, 1), m_10{}
{
}

// MS2-FUNCTIONAL: frames file-path encoding through the recovered temporary encoder.
// @0x141573240
unsigned int CNMFilePath::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: dispatches file-path encoding according to the serialized format.
// @0x1415732a0
unsigned int CNMFilePath::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the fixed-size file-path string and finishes the record.
// @0x141573300
unsigned int CNMFilePath::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ae30(pEncoder, m_10);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: frames file-path decoding and validates the temporary decoder.
// @0x141573350
unsigned int CNMFilePath::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: dispatches file-path decoding by decoder version.
// @0x1415733e0
unsigned int CNMFilePath::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: restores the fixed-size file-path string and validates the decoder.
// @0x141573440
unsigned int CNMFilePath::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_10), sizeof m_10);
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMFilePath@@QEAA@XZ 0x1415731e0
