// Nexon Messenger process-note request serialization.
// MS2-UNIT: unit_14158b290
// MS2-RANGE: 0x14158b290-0x14158b610 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ab00(void*, unsigned int);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14158b290: initializes a process-note request with zero fields.
// @0x14158b290
CNMProcessNoteFunc::CNMProcessNoteFunc() : CNMFunc(0x6003, 1, 0, 0), m_30(0), m_34(0) {}

// MS2-FUNCTIONAL 0x14158b2f0: stores the note operation and note identifier.
// @0x14158b2f0
CNMProcessNoteFunc::CNMProcessNoteFunc(int noteType, int noteId)
    : CNMFunc(0x6003, 1, 0, 0), m_30(noteType), m_34(noteId) {}

// MS2-FUNCTIONAL 0x14158b360: frames the process-note request.
// @0x14158b360
unsigned int CNMProcessNoteFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMProcessNoteFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158b3c0: selects the encoder by wire format.
// @0x14158b3c0
unsigned int CNMProcessNoteFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMProcessNoteFunc::Encode(pEncoder, pStream);
    return CNMProcessNoteFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14158b420: encodes the operation and note identifier in replies.
// @0x14158b420
unsigned int CNMProcessNoteFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) {
        FUN_14156ab00(encoder, static_cast<unsigned int>(m_30));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_34));
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158b4a0: decodes a framed process-note response.
// @0x14158b4a0
unsigned int CNMProcessNoteFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMProcessNoteFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158b530: selects the decoder by wire format.
// @0x14158b530
unsigned int CNMProcessNoteFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMProcessNoteFunc::DecodeFramed(pStream);
    return CNMProcessNoteFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14158b590: restores response operation and note identifier.
// @0x14158b590
unsigned int CNMProcessNoteFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(decoder);
        using ReadU8 = unsigned char(__fastcall*)(void*);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30 = reinterpret_cast<ReadU8>(vtable[1])(decoder);
        m_34 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMProcessNoteFunc@@QEAA@XZ 0x14158b290
