// Nexon Messenger check-news request serialization.
// MS2-UNIT: unit_141583b20
// MS2-RANGE: 0x141583b20-0x141583ee0 .text$mn
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
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x141583b20: initializes all three news cursor fields.
// @0x141583b20
CNMCheckNewsFunc::CNMCheckNewsFunc() : CNMFunc(0x200d, 1, 0, 0), m_30(0), m_34{}, m_3c(0) {}

// MS2-FUNCTIONAL 0x141583b90: stores result and the 64-bit news key.
// @0x141583b90
CNMCheckNewsFunc::CNMCheckNewsFunc(unsigned result, long long newsKey)
    : CNMFunc(0x200d, 1, 0, 0), m_30(static_cast<int>(result)),
      m_34{static_cast<unsigned int>(newsKey), static_cast<unsigned int>(static_cast<unsigned long long>(newsKey) >> 32)}, m_3c(0)
{
}

// MS2-FUNCTIONAL 0x141583c00: frames request and dispatches its encoder slot.
// @0x141583c00
unsigned int CNMCheckNewsFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18]; FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMCheckNewsFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage); return result;
}

// MS2-FUNCTIONAL 0x141583c60: selects raw or framed encoding by the format flag.
// @0x141583c60
unsigned int CNMCheckNewsFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) { using Method = unsigned int(__fastcall*)(CNMCheckNewsFunc*, CNMEncoder*, CNMStream*); return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream); }
    using Framed = unsigned int(__fastcall*)(CNMCheckNewsFunc*, CNMStream*); return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x141583cc0: serializes the result and both halves of the news key.
// @0x141583cc0
unsigned int CNMCheckNewsFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) { FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30)); FUN_14156ac20(pEncoder, m_34.nLow); FUN_14156ac20(pEncoder, m_34.nHigh); }
    FUN_1415f9990(pEncoder); return 1;
}

// MS2-FUNCTIONAL 0x141583d50: decodes through a temporary framed decoder.
// @0x141583d50
unsigned int CNMCheckNewsFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38]; FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) { void** vtable = *reinterpret_cast<void***>(this); using Method = unsigned int(__fastcall*)(CNMCheckNewsFunc*, CNMSerializableDecoder*, CNMStream*); result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream); }
    FUN_14156bf10(storage); return result;
}

// MS2-FUNCTIONAL 0x141583de0: selects framed decoding for wire format 2.
// @0x141583de0
unsigned int CNMCheckNewsFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) { using Framed = unsigned int(__fastcall*)(CNMCheckNewsFunc*, CNMStream*); return reinterpret_cast<Framed>(vtable[6])(this, pStream); }
    using Method = unsigned int(__fastcall*)(CNMCheckNewsFunc*, CNMSerializableDecoder*, CNMStream*); return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141583e40: restores all three news cursor fields.
// @0x141583e40
unsigned int CNMCheckNewsFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) { void** vtable = *reinterpret_cast<void***>(pDecoder); using U32 = unsigned int(__fastcall*)(void*); m_30 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder)); m_34.nLow = reinterpret_cast<U32>(vtable[3])(pDecoder); m_34.nHigh = reinterpret_cast<U32>(vtable[3])(pDecoder); }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMCheckNewsFunc@@QEAA@XZ 0x141583b20
