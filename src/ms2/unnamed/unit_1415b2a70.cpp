// MS2-UNIT: unit_1415b2a70
// MS2-RANGE: 0x1415b2a70-0x1415b2e20 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern unsigned int FUN_1415f9990(void*);
extern void FUN_1415fbe70(void*, unsigned int, const char*);
extern int FUN_1415fb6d0(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);

// MS2-FUNCTIONAL 0x1415b2a70: initializes an empty special event.
// @0x1415b2a70
CNMSpecialEvent::CNMSpecialEvent() : CNMEvent(0x1004, 1, 0, 0), m_28(0), m_2c{} {}

// MS2-FUNCTIONAL 0x1415b2ae0: initializes the event type and copies its optional text.
// @0x1415b2ae0
CNMSpecialEvent::CNMSpecialEvent(int type, const char* text)
    : CNMEvent(0x1004, 1, 0, 0), m_28(type), m_2c{}
{
    if (text)
        FUN_1415fbe70(m_2c, 0x100, text);
}

// MS2-FUNCTIONAL 0x1415b2b80: frames event encoding.
// @0x1415b2b80
unsigned int CNMSpecialEvent::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    auto result = Encode(reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b2be0: dispatches encoding by the event format.
// @0x1415b2be0
unsigned int CNMSpecialEvent::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    return m_bFormat == 1 ? Encode(encoder, stream) : EncodeFramed(stream);
}

// MS2-FUNCTIONAL 0x1415b2c40: serializes the event type and optional text.
// @0x1415b2c40
unsigned int CNMSpecialEvent::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMEvent::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_28));
        FUN_14156ae30(encoder, m_2c);
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415b2cb0: decodes a framed special event.
// @0x1415b2cb0
unsigned int CNMSpecialEvent::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage))
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415b2d40: dispatches decoding by the event format.
// @0x1415b2d40
unsigned int CNMSpecialEvent::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    return FUN_1415fb6d0(decoder) == 2 ? DecodeFramed(stream) : Decode(decoder, stream);
}

// MS2-FUNCTIONAL 0x1415b2da0: restores the base event type and optional text.
// @0x1415b2da0
unsigned int CNMSpecialEvent::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMEvent::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(decoder);
        using ReadInt = unsigned int(__fastcall*)(void*);
        using ReadString = void(__fastcall*)(void*, void*, unsigned int);
        m_28 = static_cast<int>(reinterpret_cast<ReadInt>(vtable[3])(decoder));
        reinterpret_cast<ReadString>(vtable[9])(decoder, m_2c, 0x100);
    }
    return FUN_1415fb750(decoder);
}

// MS2-PIN: ??0CNMSpecialEvent@@QEAA@XZ 0x1415b2a70 ; constructor body for an empty special event
