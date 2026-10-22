// Nexon Messenger chat room member record serializer methods.
// MS2-UNIT: unit_141576ae0
// MS2-RANGE: 0x141576ae0-0x1415773e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern unsigned int FUN_14156e8d0(void*, void*, void*);
extern unsigned int FUN_14156f0f0(void*, void*, void*);

// MS2-FUNCTIONAL 0x141576ca0: uses opaque stack storage for the temporary encoder; chat member encoding behavior is preserved.
// @0x141576ca0
unsigned int CNMChatRoomMemberInfo::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMChatRoomMemberInfo*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141576d00: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141576d00
unsigned int CNMChatRoomMemberInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMChatRoomMemberInfo*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMChatRoomMemberInfo*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// @0x141576d60
unsigned int CNMChatRoomMemberInfo::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156e8d0(this, pEncoder, pStream);
    FUN_14156ae30(pEncoder, m_1a8);
    FUN_14156ac20(pEncoder, m_1c8.nLow);
    FUN_14156ac20(pEncoder, m_1c8.nHigh);
    FUN_14156ac20(pEncoder, m_1d0);
    FUN_14156ae30(pEncoder, m_1d4);
    FUN_14156ac20(pEncoder, m_214);
    FUN_14156ac20(pEncoder, m_218);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141576e40: uses opaque stack storage for the temporary decoder; chat member decode behavior is preserved.
// @0x141576e40
unsigned int CNMChatRoomMemberInfo::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoderStorage) != 0) {
        void** vtable = *reinterpret_cast<void***>(this);
        using DecodeMethod = unsigned int(__fastcall*)(CNMChatRoomMemberInfo*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<DecodeMethod>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141576ed0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141576ed0
unsigned int CNMChatRoomMemberInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using FramedMethod = unsigned int(__fastcall*)(CNMChatRoomMemberInfo*, CNMStream*);
        return reinterpret_cast<FramedMethod>(vtable[6])(this, pStream);
    }
    using DecodeMethod = unsigned int(__fastcall*)(CNMChatRoomMemberInfo*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<DecodeMethod>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141576f30: delegates the inherited real-user decoder to its address-bound base helper before reading chat-specific fields.
// @0x141576f30
unsigned int CNMChatRoomMemberInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    FUN_14156f0f0(this, pDecoder, pStream);
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_1a8, 0x20);
    m_1c8.nLow = reinterpret_cast<ReadU32>(vtable[3])(pDecoder);
    m_1c8.nHigh = reinterpret_cast<ReadU32>(vtable[3])(pDecoder);
    m_1d0 = static_cast<unsigned int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_1d4, 0x40);
    m_214 = static_cast<unsigned int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_218 = static_cast<unsigned int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}
