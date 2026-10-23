// Nexon Messenger message payload serializer methods.
// MS2-UNIT: unit_141578bf0
// MS2-RANGE: 0x141578bf0-0x141578f50 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415fc140(void*, unsigned int, const void*, ...);

// MS2-FUNCTIONAL 0x141578bf0: initializes an empty message-data payload.
// @0x141578bf0
CNMMessageData::CNMMessageData() : CNMSerializable(0x6d64,1,1),m_10(0),m_14{} {}
// MS2-FUNCTIONAL 0x141578c50: initializes the message type and copies its text payload.
// @0x141578c50
CNMMessageData::CNMMessageData(int type,const char*text) : CNMSerializable(0x6d64,1,1),m_10(type),m_14{} {m_bFlag=0xfe;FUN_1415fc140(m_14,0x1000,text);}

// MS2-FUNCTIONAL 0x141578cd0: uses opaque stack storage for the temporary encoder; payload encoding behavior is preserved.
// @0x141578cd0
unsigned int CNMMessageData::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMMessageData*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141578d30: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141578d30
unsigned int CNMMessageData::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMMessageData*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMMessageData*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// @0x141578d90
unsigned int CNMMessageData::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ae30(pEncoder, m_14);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141578df0: uses opaque stack storage for the temporary decoder; payload decode behavior is preserved.
// @0x141578df0
unsigned int CNMMessageData::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoderStorage) != 0) {
        void** vtable = *reinterpret_cast<void***>(this);
        using DecodeMethod = unsigned int(__fastcall*)(CNMMessageData*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<DecodeMethod>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141578e80: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141578e80
unsigned int CNMMessageData::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using FramedMethod = unsigned int(__fastcall*)(CNMMessageData*, CNMStream*);
        return reinterpret_cast<FramedMethod>(vtable[6])(this, pStream);
    }
    using DecodeMethod = unsigned int(__fastcall*)(CNMMessageData*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<DecodeMethod>(vtable[5])(this, pDecoder, pStream);
}

// @0x141578ee0
unsigned int CNMMessageData::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_14, 0x1000);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMMessageData@@QEAA@XZ 0x141578bf0 ; recovered message payload constructor
// MS2-PIN: ??0CNMMessageData@@QEAA@HPEBD@Z 0x141578c50 ; recovered typed payload constructor
