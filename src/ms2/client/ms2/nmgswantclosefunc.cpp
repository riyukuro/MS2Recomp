// Recovered Nexon Messenger game-server want-close request.
// MS2-UNIT: ?\nmgswantclosefunc.cpp
// MS2-RANGE: 0x14159f960-0x14159fc90 .text$mn
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
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL: initializes the want-close request with its flag cleared.
// @0x14159f960
CNMGSWantCloseFunc::CNMGSWantCloseFunc()
    : CNMFunc(0xc002, 1, 0, 0), m_30(0)
{
}

// MS2-FUNCTIONAL: initializes the want-close flag and CNMFunc auxiliary value.
// @0x14159f9c0
CNMGSWantCloseFunc::CNMGSWantCloseFunc(int n18, int wantClose)
    : CNMFunc(0xc002, 1, n18, 0), m_30(wantClose)
{
}

// MS2-FUNCTIONAL: frames want-close encoding.
// @0x14159fa20
unsigned int CNMGSWantCloseFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: selects direct or framed encoding by format.
// @0x14159fa80
unsigned int CNMGSWantCloseFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the want-close flag as an unsigned byte.
// @0x14159fae0
unsigned int CNMGSWantCloseFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_30));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates framed input before decoding the want-close flag.
// @0x14159fb40
unsigned int CNMGSWantCloseFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: routes version two want-close messages through framed decoding.
// @0x14159fbd0
unsigned int CNMGSWantCloseFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reads the want-close flag from the response stream.
// @0x14159fc30
unsigned int CNMGSWantCloseFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    void** vftable = *reinterpret_cast<void***>(pDecoder);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    m_30 = reinterpret_cast<ReadU8>(vftable[1])(pDecoder);
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMGSWantCloseFunc@@QEAA@XZ 0x14159f960
