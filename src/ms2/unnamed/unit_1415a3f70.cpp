// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a3f70
// MS2-RANGE: 0x1415a3f70-0x1415a42e0 .text$mn
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
extern void FUN_1415f9990(void*);

// @0x1415a3f70
// MS2-FUNCTIONAL: initializes the recovered 0x1109 request and clears its 64-bit key.
CNMRemoveMyVirtualUserFunc::CNMRemoveMyVirtualUserFunc()
    : CNMFunc(0x1109, 1, 0, 0), m_30{0, 0}
{
}

// @0x1415a3fd0
// MS2-FUNCTIONAL: copies both dwords from the supplied virtual-user key.
CNMRemoveMyVirtualUserFunc::CNMRemoveMyVirtualUserFunc(const NMKey64* key)
    : CNMFunc(0x1109, 1, 0, 0), m_30(*key)
{
}

// @0x1415a4030
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMRemoveMyVirtualUserFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a4090
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMRemoveMyVirtualUserFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a40f0
// MS2-FUNCTIONAL: encodes the key's two dwords in recovered request wire order.
unsigned int CNMRemoveMyVirtualUserFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ac20(pEncoder, m_30.nLow);
        FUN_14156ac20(pEncoder, m_30.nHigh);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a4170
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMRemoveMyVirtualUserFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a4200
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMRemoveMyVirtualUserFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a4260
// MS2-FUNCTIONAL: restores both key dwords in recovered response wire order.
unsigned int CNMRemoveMyVirtualUserFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30.nLow = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        m_30.nHigh = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMRemoveMyVirtualUserFunc@@QEAA@XZ 0x1415a3f70
