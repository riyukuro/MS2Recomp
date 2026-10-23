// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a1df0
// MS2-RANGE: 0x1415a1df0-0x1415a2190 .text$mn
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
extern void FUN_1415fbe70(char*, unsigned int, const char*);
extern void FUN_14156ae30(void*, const char*);
extern void FUN_1415f9990(void*);

// @0x1415a1df0
// MS2-FUNCTIONAL: initializes the recovered 0xc202 request with an empty path buffer.
CNMFUSSendFileFunc::CNMFUSSendFileFunc()
    : CNMFunc(0xc202, 1, 0, 0), m_30{}
{
}

// @0x1415a1e50
// MS2-FUNCTIONAL: preserves the serial key and copies the supplied path into the recovered 0x104-byte buffer.
CNMFUSSendFileFunc::CNMFUSSendFileFunc(unsigned int serial, const char* path)
    : CNMFunc(0xc202, 1, static_cast<int>(serial), 0), m_30{}
{
    if (path) FUN_1415fbe70(m_30, 0x104, path);
}

// @0x1415a1ef0
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMFUSSendFileFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// @0x1415a1f50
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMFUSSendFileFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// @0x1415a1fb0
// MS2-FUNCTIONAL: encodes the file path only for request direction and finalizes the stream.
unsigned int CNMFUSSendFileFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
        FUN_14156ae30(pEncoder, m_30);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a2020
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMFUSSendFileFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156be10(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bf10(decoder);
    return result;
}

// @0x1415a20b0
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMFUSSendFileFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// @0x1415a2110
// MS2-FUNCTIONAL: decodes the file path into its fixed-capacity buffer for request direction.
unsigned int CNMFUSSendFileFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadBuffer = unsigned int(__fastcall*)(void*, void*, unsigned int);
        reinterpret_cast<ReadBuffer>(vftable[9])(pDecoder, m_30, 0x104);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMFUSSendFileFunc@@QEAA@XZ 0x1415a1df0
