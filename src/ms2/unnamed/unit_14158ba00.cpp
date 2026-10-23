// Nexon Messenger get-note-box v2 request and response serialization.
// MS2-UNIT: unit_14158ba00
// MS2-RANGE: 0x14158ba00-0x14158bfa0 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x14158ba00: initializes default note filters and the result list.
// @0x14158ba00
CNMGetNoteBox2Func::CNMGetNoteBox2Func()
    : CNMFunc(0x6005, 1, 0, 0), m_30(2), m_34(-1), m_38(0), m_40(), m_58(0) {}

// MS2-FUNCTIONAL 0x14158ba80: stores note filters and initializes the result list.
// @0x14158ba80
CNMGetNoteBox2Func::CNMGetNoteBox2Func(int type, int index, int status)
    : CNMFunc(0x6005, 1, 0, 0), m_30(type), m_34(index), m_38(status), m_40(), m_58(0) {}

// MS2-FUNCTIONAL 0x14158bb10: frames the get-note-box request.
// @0x14158bb10
unsigned int CNMGetNoteBox2Func::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMGetNoteBox2Func*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158bb70: selects the encoder by wire format.
// @0x14158bb70
unsigned int CNMGetNoteBox2Func::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMGetNoteBox2Func*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, encoder, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMGetNoteBox2Func*, CNMStream*);
    return reinterpret_cast<Method>(vtable[3])(this, stream);
}

// MS2-FUNCTIONAL 0x14158bbd0: serializes a note list in replies and filters in requests.
// @0x14158bbd0
unsigned int CNMGetNoteBox2Func::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (!FUN_1415fb700(this)) {
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_40.size()));
        for (CNMNoteInfo2& item : m_40) item.EncodeFramed(stream);
        FUN_14156ab00(encoder, m_58);
    } else {
        FUN_14156ab00(encoder, static_cast<unsigned char>(m_30));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_34));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_38));
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158bd00: decodes a framed note-box response.
// @0x14158bd00
unsigned int CNMGetNoteBox2Func::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMGetNoteBox2Func*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158bd90: selects the decoder by wire format.
// @0x14158bd90
unsigned int CNMGetNoteBox2Func::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(decoder) == 2) {
        using Method = unsigned int(__fastcall*)(CNMGetNoteBox2Func*, CNMStream*);
        return reinterpret_cast<Method>(vtable[6])(this, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMGetNoteBox2Func*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, decoder, stream);
}

// MS2-FUNCTIONAL 0x14158bdf0: restores the note list and status or the requested filters.
// @0x14158bdf0
unsigned int CNMGetNoteBox2Func::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    void** vtable = *reinterpret_cast<void***>(decoder);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    if (!FUN_1415fb700(this)) {
        const unsigned int count = reinterpret_cast<ReadU32>(vtable[3])(decoder);
        m_40.clear();
        for (unsigned int i = 0; i < count; ++i) {
            CNMNoteInfo2 item;
            item.DecodeFramed(stream);
            m_40.push_back(item);
        }
        m_58 = reinterpret_cast<ReadU8>(vtable[1])(decoder);
    } else {
        m_30 = reinterpret_cast<ReadU8>(vtable[1])(decoder);
        m_34 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
        m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMGetNoteBox2Func@@QEAA@XZ 0x14158ba00
