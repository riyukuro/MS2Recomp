// Recovered Nexon Messenger game-server callback registration.
// MS2-UNIT: ?\nmgsregistercallbackfunc.cpp
// MS2-RANGE: 0x14159f5e0-0x14159f960 .text$mn
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
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL: initializes callback registration 0xc001 with cleared values.
// @0x14159f5e0
CNMGSRegisterCallbackFunc::CNMGSRegisterCallbackFunc()
    : CNMFunc(0xc001, 1, 0, 0), m_30(0), m_38(0)
{
}

// MS2-FUNCTIONAL: initializes the callback registration parameters.
// @0x14159f640
CNMGSRegisterCallbackFunc::CNMGSRegisterCallbackFunc(int n18, long long callback, int code)
    : CNMFunc(0xc001, 1, n18, 0), m_30(callback), m_38(code)
{
}

// MS2-FUNCTIONAL: frames callback registration encoding.
// @0x14159f6b0
unsigned int CNMGSRegisterCallbackFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: chooses direct or framed encoding based on format.
// @0x14159f710
unsigned int CNMGSRegisterCallbackFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the callback identifier and code for request direction.
// @0x14159f770
unsigned int CNMGSRegisterCallbackFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates framed callback registration input.
// @0x14159f7f0
unsigned int CNMGSRegisterCallbackFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: routes version two callback registration through framed decoding.
// @0x14159f880
unsigned int CNMGSRegisterCallbackFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reads the callback identifier and code into the request.
// @0x14159f8e0
unsigned int CNMGSRegisterCallbackFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMGSRegisterCallbackFunc@@QEAA@XZ 0x14159f5e0
