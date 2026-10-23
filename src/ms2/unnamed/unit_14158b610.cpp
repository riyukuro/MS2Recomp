// Nexon Messenger send-note-info request serialization.
// MS2-UNIT: unit_14158b610
// MS2-RANGE: 0x14158b610-0x14158ba00 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern long long FUN_141571730(long long, long long);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ab00(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x14158b610: initializes the status and default note payload.
// @0x14158b610
CNMSendNoteInfoFunc::CNMSendNoteInfoFunc() : CNMFunc(0x6004, 1, 0, 0), m_note()
{
    *reinterpret_cast<unsigned int*>(m_30) = 0;
    m_note.m_30 = 1;
}

// MS2-FUNCTIONAL 0x14158b690: copies note content and stores the request status.
// @0x14158b690
CNMSendNoteInfoFunc::CNMSendNoteInfoFunc(const CNMNoteInfo& note, int status)
    : CNMFunc(0x6004, 1, 0, 0), m_note()
{
    *reinterpret_cast<unsigned int*>(m_30) = static_cast<unsigned int>(status);
    FUN_141571730(reinterpret_cast<long long>(&m_note), reinterpret_cast<long long>(const_cast<CNMNoteInfo*>(&note)));
    m_note.m_30 = 1;
}

// MS2-FUNCTIONAL 0x14158b730: frames the send-note-info request.
// @0x14158b730
unsigned int CNMSendNoteInfoFunc::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMSendNoteInfoFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158b790: selects the encoder by wire format.
// @0x14158b790
unsigned int CNMSendNoteInfoFunc::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMSendNoteInfoFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, encoder, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMSendNoteInfoFunc*, CNMStream*);
    return reinterpret_cast<Method>(vtable[3])(this, stream);
}

// MS2-FUNCTIONAL 0x14158b7f0: encodes status and note payload for replies.
// @0x14158b7f0
unsigned int CNMSendNoteInfoFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) {
        FUN_14156ab00(encoder, *reinterpret_cast<unsigned int*>(m_30));
        m_note.Encode(encoder, stream);
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158b880: decodes a framed response.
// @0x14158b880
unsigned int CNMSendNoteInfoFunc::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMSendNoteInfoFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158b910: selects the decoder by wire format.
// @0x14158b910
unsigned int CNMSendNoteInfoFunc::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(decoder) == 2) {
        using Method = unsigned int(__fastcall*)(CNMSendNoteInfoFunc*, CNMStream*);
        return reinterpret_cast<Method>(vtable[6])(this, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMSendNoteInfoFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, decoder, stream);
}

// MS2-FUNCTIONAL 0x14158b970: restores status and delegates note payload decoding.
// @0x14158b970
unsigned int CNMSendNoteInfoFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
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

// MS2-PIN: ??0CNMSendNoteInfoFunc@@QEAA@XZ 0x14158b610
