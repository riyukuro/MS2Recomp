// Nexon Messenger new friend request data serializer methods.
// MS2-UNIT: unit_141578f50
// MS2-RANGE: 0x141578f50-0x1415794f0 .text$mn
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

// MS2-FUNCTIONAL 0x141578f50: initializes the new-friend request fields and fixed-size strings.
// @0x141578f50
CNMRequestNewFriendData::CNMRequestNewFriendData() : CNMSerializable(0x7266,1,1),m_10(0),m_14{},m_54(0),m_58(0),m_5c(0),m_60{},m_a0(0),m_a4(0),m_a8{},m_e8(0),m_ec{},m_1ec(0) {}

// MS2-FUNCTIONAL 0x141579060: uses opaque stack storage for the temporary encoder; request data encoding behavior is preserved.
// @0x141579060
unsigned int CNMRequestNewFriendData::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMRequestNewFriendData*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x1415790c0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415790c0
unsigned int CNMRequestNewFriendData::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMRequestNewFriendData*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMRequestNewFriendData*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// @0x141579120
unsigned int CNMRequestNewFriendData::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ae30(pEncoder, m_14);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_54));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_58));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_5c));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_a0));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_a4));
    FUN_14156ae30(pEncoder, m_60);
    FUN_14156ae30(pEncoder, m_a8);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_e8));
    FUN_14156ae30(pEncoder, m_ec);
    FUN_14156ab00(pEncoder, static_cast<unsigned int>(m_1ec));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141579250: uses opaque stack storage for the temporary decoder; request data decode behavior is preserved.
// @0x141579250
unsigned int CNMRequestNewFriendData::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoderStorage) != 0) {
        void** vtable = *reinterpret_cast<void***>(this);
        using DecodeMethod = unsigned int(__fastcall*)(CNMRequestNewFriendData*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<DecodeMethod>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x1415792e0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415792e0
unsigned int CNMRequestNewFriendData::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using FramedMethod = unsigned int(__fastcall*)(CNMRequestNewFriendData*, CNMStream*);
        return reinterpret_cast<FramedMethod>(vtable[6])(this, pStream);
    }
    using DecodeMethod = unsigned int(__fastcall*)(CNMRequestNewFriendData*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<DecodeMethod>(vtable[5])(this, pDecoder, pStream);
}

// @0x141579340
unsigned int CNMRequestNewFriendData::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_14, 0x40);
    m_54 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_58 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_5c = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_a0 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_a4 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_60, 0x40);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_a8, 0x40);
    m_e8 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_ec, 0x100);
    m_1ec = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMRequestNewFriendData@@QEAA@XZ 0x141578f50 ; recovered new-friend request data constructor
