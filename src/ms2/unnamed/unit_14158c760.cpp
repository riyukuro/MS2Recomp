// Nexon Messenger remove-rejected-user request serialization.
// MS2-UNIT: unit_14158c760
// MS2-RANGE: 0x14158c760-0x14158cbf0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
#include <new>

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14158c760: initializes the embedded rejected-user record.
// @0x14158c760
CNMRemoveRejectedUserFunc::CNMRemoveRejectedUserFunc()
    : CNMFunc(0x5203, 1, 0, 0), m_30() {}

// MS2-FUNCTIONAL 0x14158c7d0: copies the supplied rejected-user record into the request.
// @0x14158c7d0
CNMRemoveRejectedUserFunc::CNMRemoveRejectedUserFunc(const CNMRejectedUser* user)
    : CNMFunc(0x5203, 1, 0, 0), m_30()
{
    m_30 = *user;
}

// MS2-FUNCTIONAL 0x14158c850: constructs a removal request from a character and detail text.
// @0x14158c850
CNMFunc* FUN_14158c850(CNMFunc* storage, const CNMCharacter* character, const char* details)
{
    auto* request = ::new (storage) CNMRemoveRejectedUserFunc();
    CNMRejectedUser rejected(character, details);
    request->m_30 = rejected;
    return request;
}

// MS2-FUNCTIONAL 0x14158c940: frames the remove-rejected-user request.
// @0x14158c940
unsigned int CNMRemoveRejectedUserFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRemoveRejectedUserFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158c9a0: selects the encoder by wire format.
// @0x14158c9a0
unsigned int CNMRemoveRejectedUserFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRemoveRejectedUserFunc::Encode(pEncoder, pStream);
    return CNMRemoveRejectedUserFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14158ca00: serializes the embedded rejected-user record in replies.
// @0x14158ca00
unsigned int CNMRemoveRejectedUserFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) m_30.Encode(encoder, stream);
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158ca80: decodes a framed remove-rejected-user response.
// @0x14158ca80
unsigned int CNMRemoveRejectedUserFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRemoveRejectedUserFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158cb10: selects the decoder by wire format.
// @0x14158cb10
unsigned int CNMRemoveRejectedUserFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRemoveRejectedUserFunc::DecodeFramed(pStream);
    return CNMRemoveRejectedUserFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14158cb70: decodes the embedded rejected-user response record.
// @0x14158cb70
unsigned int CNMRemoveRejectedUserFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) m_30.Decode(decoder, stream);
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMRemoveRejectedUserFunc@@QEAA@XZ 0x14158c760
