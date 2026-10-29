// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a2c30
// MS2-RANGE: 0x1415a2c30-0x1415a2fd0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fbe70(void*, long long, void*);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_14156ae30(void*, void*);
extern void FUN_1415f9990(void*);

// @0x1415a2c30
// MS2-FUNCTIONAL: initializes the recovered 0xc303 request and clears its directory buffer.
CNMFDSSetDownloadDirFunc::CNMFDSSetDownloadDirFunc()
    : CNMFunc(0xc303, 1, 0, 0)
{
    *reinterpret_cast<unsigned int*>(m_30) = 0;
}

// @0x1415a2c90
// MS2-FUNCTIONAL: preserves serial and copies the supplied 0x104-capacity directory path.
CNMFDSSetDownloadDirFunc::CNMFDSSetDownloadDirFunc(unsigned int serial, const char* directory)
    : CNMFunc(0xc303, 1, static_cast<int>(serial), 0)
{
    if (directory == nullptr)
        *reinterpret_cast<unsigned int*>(m_30) = 0;
    else
        FUN_1415fbe70(m_30, 0x104, const_cast<char*>(directory));
}

// @0x1415a2d30
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMFDSSetDownloadDirFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMFDSSetDownloadDirFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a2d90
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMFDSSetDownloadDirFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMFDSSetDownloadDirFunc::Encode(pEncoder, pStream);
    return CNMFDSSetDownloadDirFunc::EncodeFramed(pStream);
}

// @0x1415a2df0
// MS2-FUNCTIONAL: emits the request directory path and finalizes the stream.
unsigned int CNMFDSSetDownloadDirFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
        FUN_14156ae30(pEncoder, m_30);
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a2e60
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMFDSSetDownloadDirFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMFDSSetDownloadDirFunc::Decode(&decoder, pStream);
}

// @0x1415a2ef0
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMFDSSetDownloadDirFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMFDSSetDownloadDirFunc::DecodeFramed(pStream);
    return CNMFDSSetDownloadDirFunc::Decode(pDecoder, pStream);
}

// @0x1415a2f50
// MS2-FUNCTIONAL: restores the request directory path with the recovered 0x104-byte capacity.
unsigned int CNMFDSSetDownloadDirFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        using ReadString = void(__fastcall*)(void*, void*, unsigned int);
        reinterpret_cast<ReadString>(vftable[9])(pDecoder, m_30, 0x104);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMFDSSetDownloadDirFunc@@QEAA@XZ 0x1415a2c30
