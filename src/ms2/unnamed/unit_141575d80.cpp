// Nexon Messenger session record serializer methods.
// MS2-UNIT: unit_141575d80
// MS2-RANGE: 0x141575d80-0x141576260 .text$mn
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
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x141575e50: uses opaque stack storage for the temporary encoder; session record encoding behavior is preserved.
// @0x141575e50
unsigned int CNMSessionInfo::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMSessionInfo*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141575eb0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141575eb0
unsigned int CNMSessionInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMSessionInfo*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMSessionInfo*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// @0x141575f10
unsigned int CNMSessionInfo::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ac20(pEncoder, m_14.nLow);
    FUN_14156ac20(pEncoder, m_14.nHigh);
    FUN_14156ab00(pEncoder, static_cast<unsigned int>(m_1c));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_20));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_24));
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_28));
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_30));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_38));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_3c));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_40));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_44));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141576020: uses opaque stack storage for the temporary decoder; session record decode behavior is preserved.
// @0x141576020
unsigned int CNMSessionInfo::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoderStorage) != 0) {
        void** vtable = *reinterpret_cast<void***>(this);
        using DecodeMethod = unsigned int(__fastcall*)(CNMSessionInfo*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<DecodeMethod>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x1415760b0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415760b0
unsigned int CNMSessionInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using FramedMethod = unsigned int(__fastcall*)(CNMSessionInfo*, CNMStream*);
        return reinterpret_cast<FramedMethod>(vtable[6])(this, pStream);
    }
    using DecodeMethod = unsigned int(__fastcall*)(CNMSessionInfo*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<DecodeMethod>(vtable[5])(this, pDecoder, pStream);
}

// @0x141576110
unsigned int CNMSessionInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadU64 = unsigned long long(__fastcall*)(void*);
    m_10 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_14.nLow = reinterpret_cast<ReadU32>(vtable[3])(pDecoder);
    m_14.nHigh = reinterpret_cast<ReadU32>(vtable[3])(pDecoder);
    m_1c = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    m_20 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_24 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_28 = static_cast<long long>(reinterpret_cast<ReadU64>(vtable[4])(pDecoder));
    m_30 = static_cast<long long>(reinterpret_cast<ReadU64>(vtable[4])(pDecoder));
    m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_3c = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_40 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_44 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}
