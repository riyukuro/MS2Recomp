// Nexon Messenger send-note-info request serialization.
// MS2-UNIT: unit_14158b610
// MS2-RANGE: 0x14158b610-0x14158ba00 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
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
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

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
unsigned int CNMSendNoteInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSendNoteInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158b790: selects the encoder by wire format.
// @0x14158b790
unsigned int CNMSendNoteInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSendNoteInfoFunc::Encode(pEncoder, pStream);
    return CNMSendNoteInfoFunc::EncodeFramed(pStream);
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
unsigned int CNMSendNoteInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSendNoteInfoFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158b910: selects the decoder by wire format.
// @0x14158b910
unsigned int CNMSendNoteInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSendNoteInfoFunc::DecodeFramed(pStream);
    return CNMSendNoteInfoFunc::Decode(pDecoder, pStream);
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
