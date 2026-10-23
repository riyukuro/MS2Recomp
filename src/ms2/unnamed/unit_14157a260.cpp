// Nexon Messenger custom notification payload serializer methods.
// MS2-UNIT: unit_14157a260
// MS2-RANGE: 0x14157a260-0x14157a830 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ab00(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x14157a260: initializes the fixed fields and byte arrays of custom notification data.
// @0x14157a260
CNMCustomNotifyData::CNMCustomNotifyData() : CNMSerializable(0x636e,1,1),m_10(0),m_14(0),m_18(0),m_20(0),m_24(0),m_28(0),m_30(0),m_34(0),m_38{},m_78{},m_b8{},m_1b8(0),m_1ba(0),m_1bc{},m_1be(0),m_1c0{},m_1c8(0) {}

// MS2-FUNCTIONAL 0x14157a360: uses opaque storage for the temporary encoder; payload behavior is preserved.
// @0x14157a360
unsigned int CNMCustomNotifyData::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMCustomNotifyData*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x14157a3c0: dispatches through the recovered virtual slots.
// @0x14157a3c0
unsigned int CNMCustomNotifyData::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMCustomNotifyData*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMCustomNotifyData*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// @0x14157a420
unsigned int CNMCustomNotifyData::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_18));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_20));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_24));
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_28));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    FUN_14156ae30(pEncoder, m_38);
    FUN_14156ae30(pEncoder, m_78);
    FUN_14156ae30(pEncoder, m_b8);
    FUN_14156ac20(pEncoder, m_1b8);
    FUN_14156ab00(pEncoder, m_1ba);
    FUN_14156ab00(pEncoder, m_1be);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_1c8));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14157a570: uses opaque storage for the temporary decoder; payload behavior is preserved.
// @0x14157a570
unsigned int CNMCustomNotifyData::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoderStorage) != 0) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMCustomNotifyData*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x14157a600: dispatches through the recovered virtual slots.
// @0x14157a600
unsigned int CNMCustomNotifyData::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMCustomNotifyData*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMCustomNotifyData*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// @0x14157a660
unsigned int CNMCustomNotifyData::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using Read8 = unsigned char(__fastcall*)(void*);
    using Read16 = unsigned short(__fastcall*)(void*);
    using Read32 = unsigned int(__fastcall*)(void*);
    using Read64 = unsigned long long(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(pDecoder));
    m_18 = static_cast<long long>(reinterpret_cast<Read64>(vtable[5])(pDecoder));
    m_20 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(pDecoder));
    m_24 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(pDecoder));
    m_28 = static_cast<long long>(reinterpret_cast<Read64>(vtable[5])(pDecoder));
    m_30 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(pDecoder));
    m_34 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_38, 0x40);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_78, 0x40);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_b8, 0x100);
    m_1b8 = reinterpret_cast<Read16>(vtable[4])(pDecoder);
    m_1ba = reinterpret_cast<Read8>(vtable[1])(pDecoder);
    m_1be = reinterpret_cast<Read8>(vtable[1])(pDecoder);
    m_1c8 = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(pDecoder));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMCustomNotifyData@@QEAA@XZ 0x14157a260 ; recovered custom notification data constructor
