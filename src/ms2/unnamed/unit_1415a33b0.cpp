// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a33b0
// MS2-RANGE: 0x1415a33b0-0x1415a3700 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);

// @0x1415a33b0
// MS2-FUNCTIONAL: initializes the recovered 0xc402 request and clears the associated key.
CNMWSGetAssocSerialKeyFunc::CNMWSGetAssocSerialKeyFunc()
    : CNMFunc(0xc402, 1, 0, 0), m_30(0)
{
}

// @0x1415a3410
// MS2-FUNCTIONAL: preserves the serial and initializes the associated key to zero.
CNMWSGetAssocSerialKeyFunc::CNMWSGetAssocSerialKeyFunc(unsigned int serial)
    : CNMFunc(0xc402, 1, static_cast<int>(serial), 0), m_30(0)
{
}

// @0x1415a3470
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMWSGetAssocSerialKeyFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a34d0
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMWSGetAssocSerialKeyFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a3530
// MS2-FUNCTIONAL: emits the associated key for response direction and finalizes the stream.
unsigned int CNMWSGetAssocSerialKeyFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
        FUN_14156ac20(pEncoder, m_30);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a35a0
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMWSGetAssocSerialKeyFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a3630
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMWSGetAssocSerialKeyFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a3690
// MS2-FUNCTIONAL: restores the associated key for response direction.
unsigned int CNMWSGetAssocSerialKeyFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMWSGetAssocSerialKeyFunc@@QEAA@XZ 0x1415a33b0
