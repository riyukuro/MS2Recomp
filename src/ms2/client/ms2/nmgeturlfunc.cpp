// Recovered Nexon Messenger URL query.
// MS2-UNIT: ?\nmgeturlfunc.cpp
// MS2-RANGE: 0x141591960-0x141591f50 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL: clears the URL query fields and selects query type one.
// @0x141591960
CNMGetUrlFunc::CNMGetUrlFunc()
    : CNMFunc(0x8004, 1, 0, 0), m_30(1), m_34(0), m_38(0), m_3c(0), m_40{},
      m_140(0), m_144{}, m_244(0), m_248(0), m_24c(0), m_250{}
{
}

// MS2-FUNCTIONAL: frames URL query encoding through the shared encoder.
// @0x141591a50
unsigned int CNMGetUrlFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: chooses direct or framed encoding from the format flag.
// @0x141591ab0
unsigned int CNMGetUrlFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the URL reply or type-specific request parameters.
// @0x141591b10
unsigned int CNMGetUrlFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
        FUN_14156ae30(pEncoder, m_250);
    else
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        if (m_30 == 1)
            FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
        if (m_30 == 2)
            FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
        if (m_30 == 3)
            FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_3c));
        if (m_30 == 4)
            FUN_14156ae30(pEncoder, m_40);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_140));
        FUN_14156ae30(pEncoder, m_144);
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_244));
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_248));
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_24c));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates a framed URL response before decoding it.
// @0x141591c80
unsigned int CNMGetUrlFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: selects framed decoding for version two URL responses.
// @0x141591d10
unsigned int CNMGetUrlFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reads either the reply URL or the request's typed parameters.
// @0x141591d70
unsigned int CNMGetUrlFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    void** vftable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    using ReadString = void(__fastcall*)(void*, void*, unsigned int);
    if (FUN_1415fb700(this) == 0)
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_250, sizeof m_250);
    else
    {
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        if (m_30 == 1)
            m_34 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        if (m_30 == 2)
            m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        if (m_30 == 3)
            m_3c = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        if (m_30 == 4)
            reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_40, sizeof m_40);
        m_140 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_144, sizeof m_144);
        m_244 = reinterpret_cast<ReadU8>(vftable[1])(pDecoder);
        m_248 = reinterpret_cast<ReadU8>(vftable[1])(pDecoder);
        m_24c = reinterpret_cast<ReadU8>(vftable[1])(pDecoder);
    }
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMGetUrlFunc@@QEAA@XZ 0x141591960
