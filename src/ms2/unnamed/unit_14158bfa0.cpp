// Nexon Messenger rejected-user list serialization.
// MS2-UNIT: unit_14158bfa0
// MS2-RANGE: 0x14158bfa0-0x14158c3c0 .text$mn
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
extern void FUN_1415f9990(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL: supplies the inline default initialization needed for the temporary decoded list element.
CNMRejectedUser::CNMRejectedUser() : CNMSerializable(0, 1, 1), m_character(), m_a8{} {}

// MS2-FUNCTIONAL 0x14158bfa0: initializes the rejected-user vector.
// @0x14158bfa0
CNMGetRejectedUserListFunc::CNMGetRejectedUserListFunc()
    : CNMFunc(0x5201, 1, 0, 0), m_30() {}

// MS2-FUNCTIONAL 0x14158c000: frames the rejected-user list response.
// @0x14158c000
unsigned int CNMGetRejectedUserListFunc::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMGetRejectedUserListFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158c060: selects the encoder by wire format.
// @0x14158c060
unsigned int CNMGetRejectedUserListFunc::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMGetRejectedUserListFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, encoder, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMGetRejectedUserListFunc*, CNMStream*);
    return reinterpret_cast<Method>(vtable[3])(this, stream);
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
unsigned int CNMGetRejectedUserListFunc::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMGetRejectedUserListFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158c240: selects the decoder by wire format.
// @0x14158c240
unsigned int CNMGetRejectedUserListFunc::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(decoder) == 2) {
        using Method = unsigned int(__fastcall*)(CNMGetRejectedUserListFunc*, CNMStream*);
        return reinterpret_cast<Method>(vtable[6])(this, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMGetRejectedUserListFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, decoder, stream);
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
