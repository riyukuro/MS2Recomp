// Nexon Messenger change-my-position request serialization.
// MS2-UNIT: unit_141580080
// MS2-RANGE: 0x141580080-0x141580530 .text$mn
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
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415fbe70(void*, unsigned int, const void*);

// MS2-FUNCTIONAL 0x141580080: initializes the request ID, zero key, and empty position.
// @0x141580080
CNMChangeMyPositionFunc::CNMChangeMyPositionFunc() : CNMFunc(0x1106, 1, 0, 0), m_30{}, m_38{} {}

// MS2-FUNCTIONAL 0x1415800f0: initializes the key and copies an optional position string.
// @0x1415800f0
CNMChangeMyPositionFunc::CNMChangeMyPositionFunc(long long position)
    : CNMFunc(0x1106, 1, 0, 0), m_30{}, m_38{}
{
    if (position) FUN_1415fbe70(m_38, 0x40, reinterpret_cast<const void*>(position));
}

// MS2-FUNCTIONAL 0x1415801a0: stores a 64-bit user key and optional position string.
// @0x1415801a0
CNMChangeMyPositionFunc::CNMChangeMyPositionFunc(long long key, long long position)
    : CNMFunc(0x1106, 1, 0, 0),
      m_30{static_cast<unsigned int>(key), static_cast<unsigned int>(static_cast<unsigned long long>(key) >> 32)},
      m_38{}
{
    if (position) FUN_1415fbe70(m_38, 0x40, reinterpret_cast<const void*>(position));
}

// MS2-FUNCTIONAL 0x141580240: frames the request and dispatches its encoder slot.
// @0x141580240
unsigned int CNMChangeMyPositionFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMChangeMyPositionFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415802a0: selects raw or framed encoding from the format flag.
// @0x1415802a0
unsigned int CNMChangeMyPositionFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMChangeMyPositionFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMChangeMyPositionFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x141580300: serializes the position key and text.
// @0x141580300
unsigned int CNMChangeMyPositionFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(pEncoder, m_30.nLow);
        FUN_14156ac20(pEncoder, m_30.nHigh);
        FUN_14156ae30(pEncoder, m_38);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141580390: decodes through a temporary framed decoder and the virtual decode slot.
// @0x141580390
unsigned int CNMChangeMyPositionFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMChangeMyPositionFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x141580420: chooses framed decoding for wire format 2.
// @0x141580420
unsigned int CNMChangeMyPositionFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMChangeMyPositionFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMChangeMyPositionFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141580480: restores the key and position fields from the reply decoder.
// @0x141580480
unsigned int CNMChangeMyPositionFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using U32 = unsigned int(__fastcall*)(void*);
        using Bytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
        m_30.nLow = reinterpret_cast<U32>(vtable[3])(pDecoder);
        m_30.nHigh = reinterpret_cast<U32>(vtable[3])(pDecoder);
        reinterpret_cast<Bytes>(vtable[9])(pDecoder, m_38, 0x40);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMChangeMyPositionFunc@@QEAA@XZ 0x141580080
