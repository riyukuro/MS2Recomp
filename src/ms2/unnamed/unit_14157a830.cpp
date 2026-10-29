// Nexon Messenger game code serializers.
// MS2-UNIT: unit_14157a830
// MS2-RANGE: 0x14157a830-0x14157aaf0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14157a830: initializes the serializable game-code record.
// @0x14157a830
CNMGameCode::CNMGameCode() : CNMSerializable(0x6763,1,1),m_nGameCode(0) {}
// MS2-FUNCTIONAL 0x14157a870: initializes a game-code record with its supplied code.
// @0x14157a870
CNMGameCode::CNMGameCode(int code) : CNMSerializable(0x6763,1,1),m_nGameCode(code) {}

// MS2-FUNCTIONAL 0x14157a8c0: uses opaque temporary encoder storage; serialized value and framing are preserved.
// @0x14157a8c0
unsigned int CNMGameCode::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGameCode::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14157a920: dispatches through the recovered virtual slots.
// @0x14157a920
unsigned int CNMGameCode::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGameCode::Encode(pEncoder, pStream);
    return CNMGameCode::EncodeFramed(pStream);
}

// @0x14157a980
unsigned int CNMGameCode::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_nGameCode));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14157a9c0: uses opaque temporary decoder storage; validity and cleanup behavior are preserved.
// @0x14157a9c0
unsigned int CNMGameCode::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGameCode::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14157aa50: dispatches through the recovered virtual slots.
// @0x14157aa50
unsigned int CNMGameCode::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGameCode::DecodeFramed(pStream);
    return CNMGameCode::Decode(pDecoder, pStream);
}

// @0x14157aab0
unsigned int CNMGameCode::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using Read32 = unsigned int(__fastcall*)(void*);
    m_nGameCode = static_cast<int>(reinterpret_cast<Read32>(vtable[3])(pDecoder));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGameCode@@QEAA@XZ 0x14157a830 ; recovered default constructor
// MS2-PIN: ??0CNMGameCode@@QEAA@H@Z 0x14157a870 ; recovered value constructor
