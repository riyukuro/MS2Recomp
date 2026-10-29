// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a7300
// MS2-RANGE: 0x1415a7300-0x1415a7650 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_14156b020(void*, unsigned long long);

// @0x1415a7300
// MS2-FUNCTIONAL: initializes request 0x1118 with a null callback address.
CNMSetAuthClosedCallbackFunc::CNMSetAuthClosedCallbackFunc()
    : CNMFunc(0x1118, 1, 0, 0), m_30(0)
{
}

// @0x1415a7360
// MS2-FUNCTIONAL: initializes request 0x1118 with the supplied callback address.
CNMSetAuthClosedCallbackFunc::CNMSetAuthClosedCallbackFunc(long long callback)
    : CNMFunc(0x1118, 1, 0, 0), m_30(callback)
{
}

// @0x1415a73c0
// MS2-FUNCTIONAL: initializes a framed encoder then delegates to Encode.
unsigned int CNMSetAuthClosedCallbackFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSetAuthClosedCallbackFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a7420
// MS2-FUNCTIONAL: dispatches encoding by the serializable format flag.
unsigned int CNMSetAuthClosedCallbackFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSetAuthClosedCallbackFunc::Encode(pEncoder, pStream);
    return CNMSetAuthClosedCallbackFunc::EncodeFramed(pStream);
}

// @0x1415a7480
// MS2-FUNCTIONAL: writes the callback address when the request is valid.
unsigned int CNMSetAuthClosedCallbackFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
        FUN_14156b020(pEncoder, static_cast<unsigned long long>(m_30));
    return 1;
}

// @0x1415a74f0
// MS2-FUNCTIONAL: initializes a framed decoder, validates it, then decodes the response.
unsigned int CNMSetAuthClosedCallbackFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSetAuthClosedCallbackFunc::Decode(&decoder, pStream);
}

// @0x1415a7580
// MS2-FUNCTIONAL: dispatches decoding according to decoder format.
unsigned int CNMSetAuthClosedCallbackFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSetAuthClosedCallbackFunc::DecodeFramed(pStream);
    return CNMSetAuthClosedCallbackFunc::Decode(pDecoder, pStream);
}

// @0x1415a75e0
// MS2-FUNCTIONAL: restores the callback address when the response is valid.
unsigned int CNMSetAuthClosedCallbackFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU64 = unsigned long long(__fastcall*)(void*);
        m_30 = static_cast<long long>(reinterpret_cast<ReadU64>(vftable[12])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMSetAuthClosedCallbackFunc@@QEAA@XZ 0x1415a7300
