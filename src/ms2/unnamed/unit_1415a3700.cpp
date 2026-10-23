// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a3700
// MS2-RANGE: 0x1415a3700-0x1415a3b70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fbe70(void*, long long, void*);
extern CNMSerializable* FUN_1415f06d0(CNMSerializable*, const CNMSerializable*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);

// @0x1415a3700
// MS2-FUNCTIONAL: constructs the empty custom notification payload.
CNMCustomNotifyFunc::CNMCustomNotifyFunc()
    : CNMFunc(0x9006, 1, 0, 0), m_data()
{
}

// @0x1415a3770
// MS2-FUNCTIONAL: stores the recovered type, optional message, and flags in the payload.
CNMCustomNotifyFunc::CNMCustomNotifyFunc(int type, const char* message, int flags)
    : CNMFunc(0x9006, 1, 0, 0), m_data()
{
    m_data.m_10 = type;
    if (message == nullptr)
        *reinterpret_cast<unsigned int*>(m_data.m_b8) = 0;
    else
        FUN_1415fbe70(m_data.m_b8, 0x100, const_cast<char*>(message));
    m_data.m_1c8 = flags;
}

// @0x1415a3840
// MS2-FUNCTIONAL: copies the supplied serializable payload through the recovered helper.
CNMCustomNotifyFunc::CNMCustomNotifyFunc(const CNMCustomNotifyData& data)
    : CNMFunc(0x9006, 1, 0, 0), m_data()
{
    FUN_1415f06d0(&m_data, &data);
}

// @0x1415a38c0
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMCustomNotifyFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a3920
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMCustomNotifyFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a3980
// MS2-FUNCTIONAL: encodes the nested notification payload for response direction.
unsigned int CNMCustomNotifyFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
        m_data.Encode(pEncoder, pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a3a00
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMCustomNotifyFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a3a90
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMCustomNotifyFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a3af0
// MS2-FUNCTIONAL: decodes the nested notification payload for response direction.
unsigned int CNMCustomNotifyFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
        m_data.Decode(pDecoder, pStream);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMCustomNotifyFunc@@QEAA@XZ 0x1415a3700
