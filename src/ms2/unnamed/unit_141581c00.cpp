// Nexon Messenger change configuration request serialization.
// MS2-UNIT: unit_141581c00
// MS2-RANGE: 0x141581c00-0x141582220 .text$mn
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
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_1415f16f0(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x141581c00: initializes configuration flags and embedded game info.
// @0x141581c00
CNMChangeConfigFunc::CNMChangeConfigFunc()
    : CNMFunc(0x2005, 1, 0, 0), m_30(0), m_34(0), m_38(0), m_3c(0), m_40(0), m_48()
{
}

// MS2-FUNCTIONAL 0x141581ca0: sets presence bits for supplied options and copies optional game info.
// @0x141581ca0
CNMChangeConfigFunc::CNMChangeConfigFunc(int setting1, int setting2, int setting3, int setting4, long long gameInfo)
    : CNMFunc(0x2005, 1, 0, 0), m_30(0), m_34(0), m_38(0), m_3c(0), m_40(0), m_48()
{
    if (setting1) { m_30 |= 1; m_34 = setting1; }
    if (setting2) { m_30 |= 2; m_38 = setting2; }
    if (setting3) { m_30 |= 4; m_3c = setting3; }
    if (setting4) { m_30 |= 8; m_40 = setting4; }
    if (gameInfo) {
        m_30 |= 0x10;
        FUN_1415f16f0(&m_48, reinterpret_cast<const void*>(gameInfo));
    }
}

// MS2-FUNCTIONAL 0x141581df0: frames the request and dispatches encoder slot.
// @0x141581df0
unsigned int CNMChangeConfigFunc::EncodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMChangeConfigFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x141581e50: selects raw or framed encoding by format.
// @0x141581e50
unsigned int CNMChangeConfigFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMChangeConfigFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMChangeConfigFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x141581eb0: encodes enabled options and embedded game info in flag order.
// @0x141581eb0
unsigned int CNMChangeConfigFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        if (m_30 & 1) FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_34));
        if (m_30 & 2) FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_38));
        if (m_30 & 4) FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_3c));
        if (m_30 & 8) FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_40));
        if (m_30 & 0x10) m_48.EncodeDispatch(pEncoder, pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141581fe0: decodes through a temporary framed decoder.
// @0x141581fe0
unsigned int CNMChangeConfigFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMChangeConfigFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x141582070: chooses framed decoding for wire format 2.
// @0x141582070
unsigned int CNMChangeConfigFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMChangeConfigFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMChangeConfigFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415820d0: restores each option selected by the decoded presence mask.
// @0x1415820d0
unsigned int CNMChangeConfigFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        using ReadU8 = unsigned char(__fastcall*)(void*);
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
        if (m_30 & 1) m_34 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
        if (m_30 & 2) m_38 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
        if (m_30 & 4) m_3c = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
        if (m_30 & 8) m_40 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
        if (m_30 & 0x10) m_48.DecodeDispatch(pDecoder, pStream);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMChangeConfigFunc@@QEAA@XZ 0x141581c00
