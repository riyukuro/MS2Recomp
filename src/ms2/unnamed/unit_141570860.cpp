// Nexon Messenger note serialization and record helpers; this first batch recovers the note list append helper.
// MS2-UNIT: unit_141570860
// MS2-RANGE: 0x141570860-0x1415722e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

extern bool FUN_141609910(void*);
extern void* FUN_1415f38c0(void*, int);
extern void FUN_1415efdd0(void*, void*);
extern void FUN_14160b210(void*, void*);

// @0x141571fb0
void FUN_141571fb0(void* note, void* item)
{
    if (!FUN_141609910(static_cast<char*>(note) + 0xad0))
        FUN_1415efdd0(FUN_1415f38c0(static_cast<char*>(note) + 0xad0, 0), item);
    else
        FUN_14160b210(static_cast<char*>(note) + 0xad0, item);
}

// MS2-FUNCTIONAL 0x1415711f0: uses opaque stack storage for the temporary CNMEncoder; stream encode behavior is preserved.
// @0x1415711f0
__declspec(noinline) unsigned int CNMNoteInfoEx::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMNoteInfoEx*, CNMEncoder*, CNMStream*);
    unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141571250: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141571250
__declspec(noinline) unsigned int CNMNoteInfoEx::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMNoteInfoEx*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMNoteInfoEx*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// @0x1415712b0
__declspec(noinline) unsigned int CNMNoteInfoEx::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ae30(pEncoder, m_14);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141571310: uses opaque stack storage for the temporary decoder; decode behavior is preserved.
// @0x141571310
__declspec(noinline) unsigned int CNMNoteInfoEx::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result;
    if (FUN_1415fb750(decoderStorage) == 0)
        result = 0;
    else
    {
        void** vtable = *reinterpret_cast<void***>(this);
        using DecodeMethod = unsigned int(__fastcall*)(CNMNoteInfoEx*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<DecodeMethod>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x1415713a0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415713a0
__declspec(noinline) unsigned int CNMNoteInfoEx::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pStream) == 2) {
        using FramedMethod = unsigned int(__fastcall*)(CNMNoteInfoEx*, CNMStream*);
        return reinterpret_cast<FramedMethod>(vtable[6])(this, pStream);
    }
    using DecodeMethod = unsigned int(__fastcall*)(CNMNoteInfoEx*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<DecodeMethod>(vtable[5])(this, pDecoder, pStream);
}

// @0x141571400
__declspec(noinline) unsigned int CNMNoteInfoEx::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_14, 0x8000);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}
