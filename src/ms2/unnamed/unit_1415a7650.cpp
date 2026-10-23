// Nexon Messenger initialization request serialization.
// MS2-UNIT: unit_1415a7650
// MS2-RANGE: 0x1415a7650-0x1415a79d0 .text$mn
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
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x1415a7650: initializes the request identifier and default fields.
// @0x1415a7650
CNMInitializeFunc::CNMInitializeFunc()
    : CNMFunc(0x1111, 1, 0, 0), m_30(0), m_34(static_cast<int>(0x80000000u))
{
}

// MS2-FUNCTIONAL 0x1415a76b0: initializes the request with caller supplied values.
// @0x1415a76b0
CNMInitializeFunc::CNMInitializeFunc(int n30, int n34)
    : CNMFunc(0x1111, 1, 0, 0), m_30(n30), m_34(n34)
{
}

// MS2-FUNCTIONAL 0x1415a7720: wraps the request encoder in the stream frame.
// @0x1415a7720
unsigned int CNMInitializeFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMInitializeFunc*, CNMEncoder*, CNMStream*);
    const auto result = reinterpret_cast<Method>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415a7780: selects direct or framed request encoding.
// @0x1415a7780
unsigned int CNMInitializeFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMInitializeFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMInitializeFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x1415a77e0: writes both initialization values for a valid request.
// @0x1415a77e0
unsigned int CNMInitializeFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x1415a7860: decodes the request from a framed stream.
// @0x1415a7860
unsigned int CNMInitializeFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMInitializeFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x1415a78f0: selects direct or framed reply decoding.
// @0x1415a78f0
unsigned int CNMInitializeFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMInitializeFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMInitializeFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415a7950: restores both initialization values for a valid message.
// @0x1415a7950
unsigned int CNMInitializeFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using U32 = unsigned int(__fastcall*)(void*);
        m_30 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
        m_34 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMInitializeFunc@@QEAA@XZ 0x1415a7650
// MS2-PIN: ??0CNMInitializeFunc@@QEAA@HH@Z 0x1415a76b0
// MS2-PIN: ?EncodeFramed@CNMInitializeFunc@@UEAAIPEAVCNMStream@@@Z 0x1415a7720
// MS2-PIN: ?EncodeDispatch@CNMInitializeFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a7780
// MS2-PIN: ?Encode@CNMInitializeFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415a77e0
// MS2-PIN: ?DecodeFramed@CNMInitializeFunc@@UEAAIPEAVCNMStream@@@Z 0x1415a7860
// MS2-PIN: ?DecodeDispatch@CNMInitializeFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a78f0
// MS2-PIN: ?Decode@CNMInitializeFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a7950
