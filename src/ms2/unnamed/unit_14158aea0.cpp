// Nexon Messenger send-accuse-note request serialization.
// MS2-UNIT: unit_14158aea0
// MS2-RANGE: 0x14158aea0-0x14158b290 .text$mn
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
extern void FUN_1415fbe70(void*, unsigned int, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x14158aea0: initializes the embedded report request.
// @0x14158aea0
CNMSendAccuseNoteMsgFunc::CNMSendAccuseNoteMsgFunc() : CNMFunc(0x6006, 1, 0, 0), m_report() {}

// MS2-FUNCTIONAL 0x14158af10: stores report type, optional fixed-size detail text, and status.
// @0x14158af10
CNMSendAccuseNoteMsgFunc::CNMSendAccuseNoteMsgFunc(int type, const void* details, int status)
    : CNMFunc(0x6006, 1, 0, 0), m_report()
{
    m_report.m_14 = static_cast<unsigned int>(type);
    if (details) FUN_1415fbe70(m_report.m_60, 4000, details);
    m_report.m_5e20 = static_cast<unsigned int>(status);
}

// MS2-FUNCTIONAL 0x14158afe0: frames the report request.
// @0x14158afe0
unsigned int CNMSendAccuseNoteMsgFunc::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMSendAccuseNoteMsgFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158b040: selects the encoder by wire format.
// @0x14158b040
unsigned int CNMSendAccuseNoteMsgFunc::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMSendAccuseNoteMsgFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, encoder, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMSendAccuseNoteMsgFunc*, CNMStream*);
    return reinterpret_cast<Method>(vtable[3])(this, stream);
}

// MS2-FUNCTIONAL 0x14158b0a0: serializes the embedded report for a response.
// @0x14158b0a0
unsigned int CNMSendAccuseNoteMsgFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) m_report.Encode(encoder, stream);
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158b120: decodes a framed report response.
// @0x14158b120
unsigned int CNMSendAccuseNoteMsgFunc::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMSendAccuseNoteMsgFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158b1b0: selects the decoder by wire format.
// @0x14158b1b0
unsigned int CNMSendAccuseNoteMsgFunc::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(decoder) == 2) {
        using Method = unsigned int(__fastcall*)(CNMSendAccuseNoteMsgFunc*, CNMStream*);
        return reinterpret_cast<Method>(vtable[6])(this, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMSendAccuseNoteMsgFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, decoder, stream);
}

// MS2-FUNCTIONAL 0x14158b210: delegates response payload decoding to CNMReportInfo.
// @0x14158b210
unsigned int CNMSendAccuseNoteMsgFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) m_report.Decode(decoder, stream);
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMSendAccuseNoteMsgFunc@@QEAA@XZ 0x14158aea0
