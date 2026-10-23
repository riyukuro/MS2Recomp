// Nexon Messenger send-note-message request serialization.
// MS2-UNIT: unit_14158a810
// MS2-RANGE: 0x14158a810-0x14158aea0 .text$mn
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
extern void FUN_14156ab00(void*, unsigned int);
extern void FUN_1415fbe70(void*, unsigned int, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x14158a810: default request initializes the embedded note and status.
// @0x14158a810
CNMSendNoteMsgFunc::CNMSendNoteMsgFunc() : CNMFunc(0x6002, 1, 0, 0), m_note()
{
    m_30[0] = 0;
}

// MS2-FUNCTIONAL 0x14158a880: stores note identifiers, status, and the four fixed-size text buffers.
// @0x14158a880
CNMSendNoteMsgFunc::CNMSendNoteMsgFunc(int type, int index, const void* subject, const void* message,
                                       const void* sender, const void* recipient, int status)
    : CNMFunc(0x6002, 1, 0, 0), m_note()
{
    *reinterpret_cast<int*>(m_30) = status;
    m_note.m_14 = type;
    m_note.m_18 = index;
    m_note.m_1c.nLow = 0;
    m_note.m_1c.nHigh = 0;
    m_note.m_24 = 0;
    if (subject) FUN_1415fbe70(m_note.m_38, 0x400, subject);
    if (message) FUN_1415fbe70(m_note.m_4b8, 0x800, message);
    if (sender) FUN_1415fbe70(m_note.m_cb8, 0x100, sender);
    if (recipient) FUN_1415fbe70(m_note.m_db8, 0x100, recipient);
}

// MS2-FUNCTIONAL 0x14158aa30: also stores the supplied 64-bit note key.
// @0x14158aa30
CNMSendNoteMsgFunc::CNMSendNoteMsgFunc(int type, int index, unsigned __int64 timestamp,
                                       const void* subject, const void* message,
                                       const void* sender, const void* recipient, int status)
    : CNMFunc(0x6002, 1, 0, 0), m_note()
{
    *reinterpret_cast<int*>(m_30) = status;
    m_note.m_14 = type;
    m_note.m_18 = index;
    m_note.m_1c.nLow = static_cast<unsigned int>(timestamp);
    m_note.m_1c.nHigh = static_cast<unsigned int>(timestamp >> 32);
    if (subject) FUN_1415fbe70(m_note.m_38, 0x400, subject);
    if (message) FUN_1415fbe70(m_note.m_4b8, 0x800, message);
    if (sender) FUN_1415fbe70(m_note.m_cb8, 0x100, sender);
    if (recipient) FUN_1415fbe70(m_note.m_db8, 0x100, recipient);
}

// MS2-FUNCTIONAL 0x14158abd0: frames the send-note request.
// @0x14158abd0
unsigned int CNMSendNoteMsgFunc::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMSendNoteMsgFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158ac30: selects the request encoder by wire format.
// @0x14158ac30
unsigned int CNMSendNoteMsgFunc::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMSendNoteMsgFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, encoder, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMSendNoteMsgFunc*, CNMStream*);
    return reinterpret_cast<Method>(vtable[3])(this, stream);
}

// MS2-FUNCTIONAL 0x14158ac90: writes the status and serialized note for replies.
// @0x14158ac90
unsigned int CNMSendNoteMsgFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) {
        FUN_14156ab00(encoder, *reinterpret_cast<unsigned int*>(m_30));
        m_note.Encode(encoder, stream);
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158ad20: decodes a framed response into this request object.
// @0x14158ad20
unsigned int CNMSendNoteMsgFunc::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMSendNoteMsgFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158adb0: selects the decoder by wire format.
// @0x14158adb0
unsigned int CNMSendNoteMsgFunc::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(decoder) == 2) {
        using Method = unsigned int(__fastcall*)(CNMSendNoteMsgFunc*, CNMStream*);
        return reinterpret_cast<Method>(vtable[6])(this, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMSendNoteMsgFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, decoder, stream);
}

// MS2-FUNCTIONAL 0x14158ae10: restores reply status and delegates note decoding.
// @0x14158ae10
unsigned int CNMSendNoteMsgFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(decoder);
        using ReadU8 = unsigned char(__fastcall*)(void*);
        *reinterpret_cast<unsigned int*>(m_30) = reinterpret_cast<ReadU8>(vtable[1])(decoder);
        m_note.Decode(decoder, stream);
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMSendNoteMsgFunc@@QEAA@XZ 0x14158a810
