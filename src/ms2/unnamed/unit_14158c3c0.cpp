// Nexon Messenger append-rejected-user request serialization.
// MS2-UNIT: unit_14158c3c0
// MS2-RANGE: 0x14158c3c0-0x14158c760 .text$mn
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
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x14158c3c0: initializes the embedded rejected-user record.
// @0x14158c3c0
CNMAppendRejectedUserFunc::CNMAppendRejectedUserFunc()
    : CNMFunc(0x5202, 1, 0, 0), m_30() {}

// MS2-FUNCTIONAL 0x14158c430: copies the supplied rejected-user record into the request.
// @0x14158c430
CNMAppendRejectedUserFunc::CNMAppendRejectedUserFunc(const CNMRejectedUser* user)
    : CNMFunc(0x5202, 1, 0, 0), m_30()
{
    m_30 = *user;
}

// MS2-FUNCTIONAL 0x14158c4b0: frames the append-rejected-user request.
// @0x14158c4b0
unsigned int CNMAppendRejectedUserFunc::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMAppendRejectedUserFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158c510: selects the encoder by wire format.
// @0x14158c510
unsigned int CNMAppendRejectedUserFunc::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMAppendRejectedUserFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, encoder, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMAppendRejectedUserFunc*, CNMStream*);
    return reinterpret_cast<Method>(vtable[3])(this, stream);
}

// MS2-FUNCTIONAL 0x14158c570: serializes the embedded rejected-user record in replies.
// @0x14158c570
unsigned int CNMAppendRejectedUserFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) m_30.Encode(encoder, stream);
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158c5f0: decodes a framed append-rejected-user response.
// @0x14158c5f0
unsigned int CNMAppendRejectedUserFunc::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMAppendRejectedUserFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158c680: selects the decoder by wire format.
// @0x14158c680
unsigned int CNMAppendRejectedUserFunc::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(decoder) == 2) {
        using Method = unsigned int(__fastcall*)(CNMAppendRejectedUserFunc*, CNMStream*);
        return reinterpret_cast<Method>(vtable[6])(this, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMAppendRejectedUserFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, decoder, stream);
}

// MS2-FUNCTIONAL 0x14158c6e0: decodes the embedded rejected-user response record.
// @0x14158c6e0
unsigned int CNMAppendRejectedUserFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) m_30.Decode(decoder, stream);
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMAppendRejectedUserFunc@@QEAA@XZ 0x14158c3c0
