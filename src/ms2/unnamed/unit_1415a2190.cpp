// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a2190
// MS2-RANGE: 0x1415a2190-0x1415a2510 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);

// @0x1415a2190
// MS2-FUNCTIONAL: initializes the recovered 0xc203 request and clears both control fields.
CNMFUSControlFunc::CNMFUSControlFunc()
    : CNMFunc(0xc203, 1, 0, 0), m_30(0), m_34(0)
{
}

// @0x1415a21f0
// MS2-FUNCTIONAL: preserves serial, control type, and control value in their recovered fields.
CNMFUSControlFunc::CNMFUSControlFunc(unsigned int serial, int controlType, int controlValue)
    : CNMFunc(0xc203, 1, static_cast<int>(serial), 0), m_30(controlType), m_34(controlValue)
{
}

// @0x1415a2260
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMFUSControlFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMFUSControlFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a22c0
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMFUSControlFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMFUSControlFunc::Encode(pEncoder, pStream);
    return CNMFUSControlFunc::EncodeFramed(pStream);
}

// @0x1415a2320
// MS2-FUNCTIONAL: encodes the two control fields for request direction and finalizes the stream.
unsigned int CNMFUSControlFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a23a0
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMFUSControlFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMFUSControlFunc::Decode(&decoder, pStream);
}

// @0x1415a2430
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMFUSControlFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMFUSControlFunc::DecodeFramed(pStream);
    return CNMFUSControlFunc::Decode(pDecoder, pStream);
}

// @0x1415a2490
// MS2-FUNCTIONAL: restores both control fields in wire order for request direction.
unsigned int CNMFUSControlFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        m_34 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMFUSControlFunc@@QEAA@XZ 0x1415a2190
