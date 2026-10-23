// Nexon Messenger set-stat-info request serialization.
// MS2-UNIT: unit_1415841e0
// MS2-RANGE: 0x1415841e0-0x141584630 .text$mn
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

// MS2-FUNCTIONAL 0x1415841e0: initializes five stat values to zero.
// @0x1415841e0
CNMSetStatInfoFunc::CNMSetStatInfoFunc() : CNMFunc(0x2103, 1, 0, 0), m_30(0), m_34(0), m_38(0), m_3c(0), m_40(0) {}

// MS2-FUNCTIONAL 0x141584270: stores five stat values.
// @0x141584270
CNMSetStatInfoFunc::CNMSetStatInfoFunc(int a, int b, int c, int d, int e)
    : CNMFunc(0x2103, 1, 0, 0), m_30(a), m_34(b), m_38(c), m_3c(d), m_40(e) {}

// MS2-FUNCTIONAL 0x141584300: frames the request and dispatches its encoder slot.
// @0x141584300
unsigned int CNMSetStatInfoFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18]; FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this); using Method = unsigned int(__fastcall*)(CNMSetStatInfoFunc*, CNMEncoder*, CNMStream*);
    auto result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream); FUN_14156bd50(storage); return result;
}

// MS2-FUNCTIONAL 0x141584360: selects raw or framed encoding by the format flag.
// @0x141584360
unsigned int CNMSetStatInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) { using Method = unsigned int(__fastcall*)(CNMSetStatInfoFunc*, CNMEncoder*, CNMStream*); return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream); }
    using Framed = unsigned int(__fastcall*)(CNMSetStatInfoFunc*, CNMStream*); return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x1415843c0: serializes the five stat values.
// @0x1415843c0
unsigned int CNMSetStatInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) { FUN_14156ac20(pEncoder, m_30); FUN_14156ac20(pEncoder, m_34); FUN_14156ac20(pEncoder, m_38); FUN_14156ac20(pEncoder, m_3c); FUN_14156ac20(pEncoder, m_40); }
    FUN_1415f9990(pEncoder); return 1;
}

// MS2-FUNCTIONAL 0x141584470: decodes through a temporary framed decoder.
// @0x141584470
unsigned int CNMSetStatInfoFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38]; FUN_14156be10(storage, pStream, this); unsigned int result = 0;
    if (FUN_1415fb750(storage)) { void** vtable = *reinterpret_cast<void***>(this); using Method = unsigned int(__fastcall*)(CNMSetStatInfoFunc*, CNMSerializableDecoder*, CNMStream*); result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream); }
    FUN_14156bf10(storage); return result;
}

// MS2-FUNCTIONAL 0x141584500: selects framed decoding for wire format 2.
// @0x141584500
unsigned int CNMSetStatInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) { using Framed = unsigned int(__fastcall*)(CNMSetStatInfoFunc*, CNMStream*); return reinterpret_cast<Framed>(vtable[6])(this, pStream); }
    using Method = unsigned int(__fastcall*)(CNMSetStatInfoFunc*, CNMSerializableDecoder*, CNMStream*); return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141584560: restores all five stat values.
// @0x141584560
unsigned int CNMSetStatInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) { void** vtable = *reinterpret_cast<void***>(pDecoder); using U32 = unsigned int(__fastcall*)(void*); m_30 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder)); m_34 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder)); m_38 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder)); m_3c = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder)); m_40 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder)); }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMSetStatInfoFunc@@QEAA@XZ 0x1415841e0
