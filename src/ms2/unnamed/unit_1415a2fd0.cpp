// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a2fd0
// MS2-RANGE: 0x1415a2fd0-0x1415a33b0 .text$mn
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
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156af60(void*, void*, unsigned int);
extern void FUN_1415f9990(void*);

// @0x1415a2fd0
// MS2-FUNCTIONAL: initializes the recovered 0xc401 request and clears its 32 KiB payload.
CNMWSSendWBMessageFunc::CNMWSSendWBMessageFunc()
    : CNMFunc(0xc401, 1, 0, 0), m_30(0), m_34(0), m_38{}
{
}

// @0x1415a3050
// MS2-FUNCTIONAL: copies serial, message type, and the caller-specified payload bytes.
CNMWSSendWBMessageFunc::CNMWSSendWBMessageFunc(unsigned int serial, unsigned int messageType,
                                               const unsigned char* data, unsigned int size)
    : CNMFunc(0xc401, 1, static_cast<int>(serial), 0), m_30(messageType), m_34(size), m_38{}
{
    for (unsigned int i = 0; i < size; ++i)
        m_38[i] = data[i];
}

// @0x1415a30e0
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMWSSendWBMessageFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a3140
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMWSSendWBMessageFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a31a0
// MS2-FUNCTIONAL: encodes the message type and byte payload for request direction.
unsigned int CNMWSSendWBMessageFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ac20(pEncoder, m_30);
        FUN_14156af60(pEncoder, m_38, m_34);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a3220
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMWSSendWBMessageFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a32b0
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMWSSendWBMessageFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a3310
// MS2-FUNCTIONAL: restores type and payload through the decoder's corresponding fields.
unsigned int CNMWSSendWBMessageFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
        m_30 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        m_34 = reinterpret_cast<ReadBytes>(vftable[11])(pDecoder, m_38, 0x8000);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMWSSendWBMessageFunc@@QEAA@XZ 0x1415a2fd0
