// Nexon Messenger guild record serializer methods.
// MS2-UNIT: unit_141573790
// MS2-RANGE: 0x141573790-0x141574050 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ab00(void*, unsigned int);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415eb480(void*, unsigned int, long long);

// @0x141573870
void* FUN_141573870(CNMGuildInfoEx* info, void* out)
{
    FUN_1415eb480(out, static_cast<unsigned int>(info->m_78), info->m_10);
    return out;
}

// MS2-FUNCTIONAL 0x1415738b0: uses opaque stack storage for the temporary encoder; guild encoding behavior is preserved.
// @0x1415738b0
unsigned int CNMGuildInfoEx::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMGuildInfoEx*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141573910: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141573910
unsigned int CNMGuildInfoEx::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMGuildInfoEx*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMGuildInfoEx*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// @0x141573970
unsigned int CNMGuildInfoEx::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_10));
    FUN_14156ae30(pEncoder, m_18);
    FUN_14156ae30(pEncoder, m_58);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_78));
    FUN_14156ae30(pEncoder, m_7c);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_17c));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_180));
    FUN_14156ab00(pEncoder, static_cast<unsigned int>(m_184));
    FUN_14156ab00(pEncoder, static_cast<unsigned int>(m_188));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141573a60: uses opaque stack storage for the temporary decoder; decode behavior is preserved.
// @0x141573a60
unsigned int CNMGuildInfoEx::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoderStorage) != 0) {
        void** vtable = *reinterpret_cast<void***>(this);
        using DecodeMethod = unsigned int(__fastcall*)(CNMGuildInfoEx*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<DecodeMethod>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141573af0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141573af0
unsigned int CNMGuildInfoEx::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using FramedMethod = unsigned int(__fastcall*)(CNMGuildInfoEx*, CNMStream*);
        return reinterpret_cast<FramedMethod>(vtable[6])(this, pStream);
    }
    using DecodeMethod = unsigned int(__fastcall*)(CNMGuildInfoEx*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<DecodeMethod>(vtable[5])(this, pDecoder, pStream);
}

// @0x141573b50
unsigned int CNMGuildInfoEx::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadU64 = unsigned long long(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = static_cast<long long>(reinterpret_cast<ReadU64>(vtable[4])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_18, 0x40);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_58, 0x20);
    m_78 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_7c, 0x100);
    m_17c = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_180 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_184 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    m_188 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}
