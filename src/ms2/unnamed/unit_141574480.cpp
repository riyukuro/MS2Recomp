// Nexon Messenger user lookup record serializer methods.
// MS2-UNIT: unit_141574480
// MS2-RANGE: 0x141574480-0x1415749d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x141574580: uses opaque stack storage for the temporary encoder; lookup record encoding behavior is preserved.
// @0x141574580
unsigned int CNMFindUserInfo::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMFindUserInfo*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x1415745e0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415745e0
unsigned int CNMFindUserInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMFindUserInfo*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMFindUserInfo*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// @0x141574640
unsigned int CNMFindUserInfo::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_10));
    FUN_14156ae30(pEncoder, m_18);
    FUN_14156ae30(pEncoder, m_58);
    FUN_14156ae30(pEncoder, m_78);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_b8));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_bc));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_c0));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_c4));
    m_c8.EncodeFramed(pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_d8));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141574760: uses opaque stack storage for the temporary decoder; lookup record decode behavior is preserved.
// @0x141574760
unsigned int CNMFindUserInfo::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoderStorage) != 0) {
        void** vtable = *reinterpret_cast<void***>(this);
        using DecodeMethod = unsigned int(__fastcall*)(CNMFindUserInfo*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<DecodeMethod>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x1415747f0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415747f0
unsigned int CNMFindUserInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using FramedMethod = unsigned int(__fastcall*)(CNMFindUserInfo*, CNMStream*);
        return reinterpret_cast<FramedMethod>(vtable[6])(this, pStream);
    }
    using DecodeMethod = unsigned int(__fastcall*)(CNMFindUserInfo*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<DecodeMethod>(vtable[5])(this, pDecoder, pStream);
}

// @0x141574850
unsigned int CNMFindUserInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadU64 = unsigned long long(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = static_cast<long long>(reinterpret_cast<ReadU64>(vtable[4])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_18, 0x40);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_58, 0x20);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_78, 0x40);
    m_b8 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_bc = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_c0 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_c4 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_c8.Decode(reinterpret_cast<CNMSerializableDecoder*>(pDecoder), pStream);
    m_d8 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-FUNCTIONAL 0x141574480: initializes the find-user signature, avatar subobject and fixed result fields.
// @0x141574480
CNMFindUserInfo::CNMFindUserInfo() : CNMSerializable(0x6675,1,1),m_10(0),m_18{},m_58{},m_78{},m_b8(0),m_bc(0),m_c0(0),m_c4(0),m_c8(),m_d8(0) {}

// MS2-PIN: ??0CNMFindUserInfo@@QEAA@XZ 0x141574480 ; recovered find-user constructor
