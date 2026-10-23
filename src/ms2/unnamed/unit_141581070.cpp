// Nexon Messenger change-my-info request serialization.
// MS2-UNIT: unit_141581070
// MS2-RANGE: 0x141581070-0x141581690 .text$mn
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

// MS2-FUNCTIONAL 0x141581070: initializes all optional change fields to their absent defaults.
// @0x141581070
CNMChangeMyInfoFunc::CNMChangeMyInfoFunc()
    : CNMFunc(0x2003, 1, 0, 0), m_30(0), m_34(0), m_38{}, m_78{}, m_b8(-1), m_bc(0)
{
}

// MS2-FUNCTIONAL 0x141581110: sets optional name, position, and state fields and their presence bits.
// @0x141581110
CNMChangeMyInfoFunc::CNMChangeMyInfoFunc(int mode, long long name, long long position, int state, unsigned extra)
    : CNMFunc(0x2003, 1, 0, 0), m_30(0), m_34(0), m_38{}, m_78{}, m_b8(-1), m_bc(extra)
{
    if (mode != 0) { m_34 = mode; m_30 |= 1; }
    if (name != 0) { FUN_1415fbe70(m_38, 0x40, reinterpret_cast<const void*>(name)); m_30 |= 2; }
    if (position != 0) { FUN_1415fbe70(m_78, 0x40, reinterpret_cast<const void*>(position)); m_30 |= 4; }
    if (state != -1) { m_b8 = state; m_30 |= 0x10; }
}

// MS2-FUNCTIONAL 0x141581280: frames the request and dispatches its encoder slot.
// @0x141581280
unsigned int CNMChangeMyInfoFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMChangeMyInfoFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415812e0: selects raw or framed encoding from the format flag.
// @0x1415812e0
unsigned int CNMChangeMyInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMChangeMyInfoFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMChangeMyInfoFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x141581340: serializes only the fields selected by the presence mask.
// @0x141581340
unsigned int CNMChangeMyInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        if (m_30 & 1) FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
        if (m_30 & 2) FUN_14156ae30(pEncoder, m_38);
        if (m_30 & 4) FUN_14156ae30(pEncoder, m_78);
        if (m_30 & 0x10) FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_b8));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_bc));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141581450: decodes through a temporary framed decoder and the virtual decode slot.
// @0x141581450
unsigned int CNMChangeMyInfoFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMChangeMyInfoFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415814e0: chooses framed decoding for wire format 2.
// @0x1415814e0
unsigned int CNMChangeMyInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMChangeMyInfoFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMChangeMyInfoFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141581540: restores fields selected by the reply presence mask.
// @0x141581540
unsigned int CNMChangeMyInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using U32 = unsigned int(__fastcall*)(void*);
        using Bytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
        m_30 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        if (m_30 & 1) m_34 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        if (m_30 & 2) reinterpret_cast<Bytes>(vtable[9])(pDecoder, m_38, 0x40);
        if (m_30 & 4) reinterpret_cast<Bytes>(vtable[9])(pDecoder, m_78, 0x40);
        if (m_30 & 0x10) m_b8 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_bc = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMChangeMyInfoFunc@@QEAA@XZ 0x141581070
