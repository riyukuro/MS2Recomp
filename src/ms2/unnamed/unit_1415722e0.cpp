// Nexon Messenger report information serializer methods.
// MS2-UNIT: unit_1415722e0
// MS2-RANGE: 0x1415722e0-0x1415727c0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ab00(void*, unsigned int);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x1415723c0: uses opaque stack storage for the temporary encoder; report encoding behavior is preserved.
// @0x1415723c0
unsigned int CNMReportInfo::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMReportInfo*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141572420: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141572420
unsigned int CNMReportInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMReportInfo*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMReportInfo*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// @0x141572480
unsigned int CNMReportInfo::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ab00(pEncoder, m_10);
    FUN_14156ab00(pEncoder, m_14);
    FUN_14156ac20(pEncoder, m_18);
    FUN_14156ac20(pEncoder, m_1c);
    FUN_14156ae30(pEncoder, m_20);
    FUN_14156ae30(pEncoder, m_60);
    FUN_14156ae30(pEncoder, m_1000);
    FUN_14156ac20(pEncoder, m_5e20);
    FUN_14156ae30(pEncoder, m_5e24);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141572570: uses opaque stack storage for the temporary decoder; decode behavior is preserved.
// @0x141572570
unsigned int CNMReportInfo::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoderStorage) != 0) {
        void** vtable = *reinterpret_cast<void***>(this);
        using DecodeMethod = unsigned int(__fastcall*)(CNMReportInfo*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<DecodeMethod>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141572600: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141572600
unsigned int CNMReportInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using FramedMethod = unsigned int(__fastcall*)(CNMReportInfo*, CNMStream*);
        return reinterpret_cast<FramedMethod>(vtable[6])(this, pStream);
    }
    using DecodeMethod = unsigned int(__fastcall*)(CNMReportInfo*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<DecodeMethod>(vtable[5])(this, pDecoder, pStream);
}

// @0x141572660
unsigned int CNMReportInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    m_14 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    m_18 = reinterpret_cast<ReadU32>(vtable[3])(pDecoder);
    m_1c = reinterpret_cast<ReadU32>(vtable[3])(pDecoder);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_20, 0x40);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_60, 4000);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_1000, 20000);
    m_5e20 = reinterpret_cast<ReadU32>(vtable[3])(pDecoder);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_5e24, 0x40);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}
