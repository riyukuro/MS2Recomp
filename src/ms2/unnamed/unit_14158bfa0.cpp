// Nexon Messenger rejected-user list serialization.
// MS2-UNIT: unit_14158bfa0
// MS2-RANGE: 0x14158bfa0-0x14158c3c0 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14158bfa0: initializes the rejected-user vector.
// @0x14158bfa0
CNMGetRejectedUserListFunc::CNMGetRejectedUserListFunc()
    : CNMFunc(0x5201, 1, 0, 0), m_30() {}

// MS2-FUNCTIONAL 0x14158c000: frames the rejected-user list response.
// @0x14158c000
unsigned int CNMGetRejectedUserListFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetRejectedUserListFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158c060: selects the encoder by wire format.
// @0x14158c060
unsigned int CNMGetRejectedUserListFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetRejectedUserListFunc::Encode(pEncoder, pStream);
    return CNMGetRejectedUserListFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14158c0c0: serializes rejected-user records when the response flag is set.
// @0x14158c0c0
unsigned int CNMGetRejectedUserListFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb720(this)) {
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_30.size()));
        for (CNMRejectedUser& item : m_30) item.EncodeFramed(stream);
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158c1b0: decodes a framed rejected-user response.
// @0x14158c1b0
unsigned int CNMGetRejectedUserListFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetRejectedUserListFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158c240: selects the decoder by wire format.
// @0x14158c240
unsigned int CNMGetRejectedUserListFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetRejectedUserListFunc::DecodeFramed(pStream);
    return CNMGetRejectedUserListFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14158c2a0: restores the rejected-user list from the response.
// @0x14158c2a0
unsigned int CNMGetRejectedUserListFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb720(this)) {
        void** vtable = *reinterpret_cast<void***>(decoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        const unsigned int count = reinterpret_cast<ReadU32>(vtable[3])(decoder);
        m_30.clear();
        for (unsigned int i = 0; i < count; ++i) {
            CNMRejectedUser item;
            item.DecodeFramed(stream);
            m_30.push_back(item);
        }
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMGetRejectedUserListFunc@@QEAA@XZ 0x14158bfa0
