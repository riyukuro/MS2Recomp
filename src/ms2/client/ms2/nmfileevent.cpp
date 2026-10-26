// Recovered from the Nexon Messenger client library: file transfer event record.
// MS2-UNIT: ?\nmfileevent.cpp
// MS2-RANGE: 0x141572e00-0x1415731e0 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: initializes the file-event record with its recovered signature and zeroed fields.
// @0x141572e00
CNMFileEvent::CNMFileEvent()
    : CNMSerializable(0x6665, 1, 1), m_10(0), m_14{}, m_114(0), m_118(0), m_11c(0), m_120(0)
{
}

// MS2-FUNCTIONAL: frames file-event encoding through the recovered temporary encoder.
// @0x141572ea0
unsigned int CNMFileEvent::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: dispatches file-event encoding according to the serialized format.
// @0x141572f00
unsigned int CNMFileEvent::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the ID, fixed path, three integer fields, and final byte in wire order.
// @0x141572f60
unsigned int CNMFileEvent::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ae30(pEncoder, m_14);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_114));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_118));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_11c));
    FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_120));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: frames file-event decoding and validates the temporary decoder.
// @0x141573010
unsigned int CNMFileEvent::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: dispatches file-event decoding by decoder version.
// @0x1415730a0
unsigned int CNMFileEvent::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: restores all file-event fields in serialized order and validates the decoder.
// @0x141573100
unsigned int CNMFileEvent::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_10 = static_cast<int>(pDecoder->ReadU32());
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(m_14), sizeof m_14);
    m_114 = static_cast<int>(pDecoder->ReadU32());
    m_118 = static_cast<int>(pDecoder->ReadU32());
    m_11c = static_cast<int>(pDecoder->ReadU32());
    m_120 = pDecoder->ReadU8();
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMFileEvent@@QEAA@XZ 0x141572e00
