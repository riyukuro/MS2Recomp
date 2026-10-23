// Recovered from the Nexon Messenger client library: set serving process ID request.
// MS2-UNIT: unit_1415a01a0
// MS2-RANGE: 0x1415a01a0-0x1415a04e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// MS2-FUNCTIONAL: base request initialization and no payload writes match; vftable setup codegen differs.
// @0x1415a01a0
CNMGSSetServingProcessIDFunc::CNMGSSetServingProcessIDFunc()
    : CNMFunc(0xc004, 1, 0, 0)
{
}

// MS2-FUNCTIONAL: request code, serial key, and process ID payload match; base constructor codegen differs.
// @0x1415a01f0
CNMGSSetServingProcessIDFunc::CNMGSSetServingProcessIDFunc(unsigned uSerialKey, unsigned uProcessId)
    : CNMFunc(0xc004, 1, static_cast<int>(uSerialKey), 0), m_30(static_cast<int>(uProcessId))
{
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x1415a0250
unsigned int CNMGSSetServingProcessIDFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x1415a02b0
unsigned int CNMGSSetServingProcessIDFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: request/reply payload gate and process ID write match; direct dispatch replaces virtual calls.
// @0x1415a0310
unsigned int CNMGSSetServingProcessIDFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x1415a0380
unsigned int CNMGSSetServingProcessIDFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x1415a0410
unsigned int CNMGSSetServingProcessIDFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: process ID reply gate and read match; direct dispatch replaces virtual calls.
// @0x1415a0470
unsigned int CNMGSSetServingProcessIDFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMGSSetServingProcessIDFunc@@QEAA@XZ 0x1415a01a0
