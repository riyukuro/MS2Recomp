// Nexon Messenger guild member record serializer methods.
// MS2-UNIT: unit_1415749d0
// MS2-RANGE: 0x1415749d0-0x141575d80 .text$mn
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

// MS2-FUNCTIONAL 0x141574ba0: uses opaque stack storage for the temporary encoder; member record encoding behavior is preserved.
// @0x141574ba0
unsigned int CNMGuildMemberInfo::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141574c00: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141574c00
unsigned int CNMGuildMemberInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// @0x141574c60
unsigned int CNMGuildMemberInfo::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156acb0(pEncoder, m_nIDCode);
    FUN_14156ae30(pEncoder, m_szLoginID);
    FUN_14156ae30(pEncoder, m_szNickName);
    m_avatar.EncodeFramed(pStream);
    FUN_14156ab00(pEncoder, static_cast<unsigned int>(m_na8));
    FUN_14156ab00(pEncoder, m_bac);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_nb0));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_nb4));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141574d50: uses opaque stack storage for the temporary decoder; member record decode behavior is preserved.
// @0x141574d50
unsigned int CNMGuildMemberInfo::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoderStorage) != 0) {
        void** vtable = *reinterpret_cast<void***>(this);
        using DecodeMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<DecodeMethod>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141574de0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141574de0
unsigned int CNMGuildMemberInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using FramedMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMStream*);
        return reinterpret_cast<FramedMethod>(vtable[6])(this, pStream);
    }
    using DecodeMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<DecodeMethod>(vtable[5])(this, pDecoder, pStream);
}

// @0x141574e40
unsigned int CNMGuildMemberInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadU64 = unsigned long long(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_nIDCode = reinterpret_cast<ReadU64>(vtable[4])(pDecoder);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_szLoginID, 0x40);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_szNickName, 0x40);
    m_avatar.Decode(reinterpret_cast<CNMSerializableDecoder*>(pDecoder), pStream);
    m_na8 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    m_bac = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    m_nb0 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_nb4 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}
