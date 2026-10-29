// Nexon Messenger change local configuration request serialization.
// MS2-UNIT: unit_1415825b0
// MS2-RANGE: 0x1415825b0-0x141582980 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415fbe70(void*, unsigned int, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x1415825b0: initializes request and empty config string.
// @0x1415825b0
CNMChangeLocalConfigFunc::CNMChangeLocalConfigFunc()
    : CNMFunc(0x2007, 1, 0, 0), m_30(0), m_34{}
{
}

// MS2-FUNCTIONAL 0x141582620: stores result and optional configuration string.
// @0x141582620
CNMChangeLocalConfigFunc::CNMChangeLocalConfigFunc(unsigned result, long long config)
    : CNMFunc(0x2007, 1, 0, 0), m_30(static_cast<int>(result)), m_34{}
{
    if (config) FUN_1415fbe70(m_34, 0x400, reinterpret_cast<const void*>(config));
}

// MS2-FUNCTIONAL 0x1415826c0: frames the request and dispatches encoder slot.
// @0x1415826c0
unsigned int CNMChangeLocalConfigFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMChangeLocalConfigFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141582720: selects raw or framed encoding by format.
// @0x141582720
unsigned int CNMChangeLocalConfigFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMChangeLocalConfigFunc::Encode(pEncoder, pStream);
    return CNMChangeLocalConfigFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x141582780: encodes result and configuration in reply mode.
// @0x141582780
unsigned int CNMChangeLocalConfigFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        FUN_14156ae30(pEncoder, m_34);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141582800: decodes through a temporary framed decoder.
// @0x141582800
unsigned int CNMChangeLocalConfigFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMChangeLocalConfigFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x141582890: chooses framed decoding for wire format 2.
// @0x141582890
unsigned int CNMChangeLocalConfigFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMChangeLocalConfigFunc::DecodeFramed(pStream);
    return CNMChangeLocalConfigFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415828f0: restores result and config data in reply mode.
// @0x1415828f0
unsigned int CNMChangeLocalConfigFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
        reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_34, 0x400);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMChangeLocalConfigFunc@@QEAA@XZ 0x1415825b0
