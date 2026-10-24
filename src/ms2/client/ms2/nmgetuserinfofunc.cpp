// Recovered Nexon Messenger user information query.
// MS2-UNIT: ?\nmgetuserinfofunc.cpp
// MS2-RANGE: 0x141595d10-0x1415960e0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/ms2recover.h"

extern void FUN_1415fbe70(void*, unsigned int, const char*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL: initializes an empty user information request.
// @0x141595d10
CNMGetUserInfoFunc::CNMGetUserInfoFunc()
    : CNMFunc(0x9001, 1, 0, 0), m_30{}, m_70(0)
{
}

// MS2-FUNCTIONAL: initializes a request with its user identifier and query type.
// @0x141595d80
CNMGetUserInfoFunc::CNMGetUserInfoFunc(const char* userId, int type)
    : CNMFunc(0x9001, 1, 0, 0), m_30{}, m_70(type)
{
    if (userId != nullptr)
        FUN_1415fbe70(m_30, sizeof m_30, userId);
}

// MS2-FUNCTIONAL: frames encoding through the shared temporary encoder.
// @0x141595e20
unsigned int CNMGetUserInfoFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: chooses direct or framed encoding by format.
// @0x141595e80
unsigned int CNMGetUserInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: writes the user identifier and query type for the request direction.
// @0x141595ee0
unsigned int CNMGetUserInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        FUN_14156ae30(pEncoder, m_30);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_70));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: validates framed input before decoding a user information response.
// @0x141595f60
unsigned int CNMGetUserInfoFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: routes version two replies through framed decoding.
// @0x141595ff0
unsigned int CNMGetUserInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: reads the returned user identifier and query type.
// @0x141596050
unsigned int CNMGetUserInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadString = void(__fastcall*)(void*, void*, unsigned int);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_30, sizeof m_30);
        m_70 = static_cast<int>(reinterpret_cast<ReadU32>(vftable[3])(pDecoder));
    }
    FUN_1415fb750(pDecoder);
    return 1;
}

// MS2-PIN: ??0CNMGetUserInfoFunc@@QEAA@XZ 0x141595d10
// MS2-PIN: ??0CNMGetUserInfoFunc@@QEAA@PEBDH@Z 0x141595d80
