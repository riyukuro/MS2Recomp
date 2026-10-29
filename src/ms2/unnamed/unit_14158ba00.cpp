// Nexon Messenger get-note-box v2 request and response serialization.
// MS2-UNIT: unit_14158ba00
// MS2-RANGE: 0x14158ba00-0x14158bfa0 .text$mn
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
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14158ba00: initializes default note filters and the result list.
// @0x14158ba00
CNMGetNoteBox2Func::CNMGetNoteBox2Func()
    : CNMFunc(0x6005, 1, 0, 0)
{
    m_30 = 2;
    m_34 = -1;
    m_38 = 0;
}

// MS2-FUNCTIONAL 0x14158ba80: stores note filters and initializes the result list.
// @0x14158ba80
CNMGetNoteBox2Func::CNMGetNoteBox2Func(int type, int index, int status)
    : CNMFunc(0x6005, 1, 0, 0)
{
    m_30 = type;
    m_34 = index;
    m_38 = status;
}

// MS2-FUNCTIONAL 0x14158bb10: frames the get-note-box request.
// @0x14158bb10
unsigned int CNMGetNoteBox2Func::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetNoteBox2Func::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158bb70: selects the encoder by wire format.
// @0x14158bb70
unsigned int CNMGetNoteBox2Func::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetNoteBox2Func::Encode(pEncoder, pStream);
    return CNMGetNoteBox2Func::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14158bbd0: serializes a note list in replies and filters in requests.
// @0x14158bbd0
unsigned int CNMGetNoteBox2Func::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this) != 0) {
        FUN_14156ab00(encoder, static_cast<unsigned char>(m_30));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_34));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_38));
    } else {
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_40.size()));
        for (CNMNoteInfo2& item : m_40) item.EncodeFramed(stream);
        FUN_14156ab00(encoder, m_58);
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158bd00: decodes a framed note-box response.
// @0x14158bd00
unsigned int CNMGetNoteBox2Func::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetNoteBox2Func::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158bd90: selects the decoder by wire format.
// @0x14158bd90
unsigned int CNMGetNoteBox2Func::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetNoteBox2Func::DecodeFramed(pStream);
    return CNMGetNoteBox2Func::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14158bdf0: restores the note list and status or the requested filters.
// @0x14158bdf0
unsigned int CNMGetNoteBox2Func::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this) != 0) {
        m_30 = decoder->ReadU8();
        m_34 = decoder->ReadU32();
        m_38 = decoder->ReadU32();
    } else {
        // One record is decoded into the same local each time and a copy is pushed (a failed decode keeps
        // the previous record's data).
        {
            CNMNoteInfo2 item;
            unsigned int count = decoder->ReadU32();
            m_40.clear();
            for (unsigned int i = 0; i < count; ++i) {
                item.DecodeFramed(stream);
                m_40.push_back(item);
            }
        }
        m_58 = decoder->ReadU8();
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMGetNoteBox2Func@@QEAA@XZ 0x14158ba00
