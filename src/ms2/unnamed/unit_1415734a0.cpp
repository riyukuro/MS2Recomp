// Nexon Messenger user's game profile record serializer methods.
// MS2-UNIT: unit_1415734a0
// MS2-RANGE: 0x1415734a0-0x141573790 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
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

// MS2-FUNCTIONAL 0x141573500: uses opaque stack storage for the temporary encoder; profile encoding behavior is preserved.
// @0x141573500
unsigned int CNMMyGameInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMMyGameInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141573560: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141573560
unsigned int CNMMyGameInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMMyGameInfo::Encode(pEncoder, pStream);
    return CNMMyGameInfo::EncodeFramed(pStream);
}

// @0x1415735c0
unsigned int CNMMyGameInfo::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    for (unsigned int i = 0; i < 10; ++i)
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10[i]));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141573630: uses opaque stack storage for the temporary decoder; decode behavior is preserved.
// @0x141573630
unsigned int CNMMyGameInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMMyGameInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415736c0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415736c0
unsigned int CNMMyGameInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMMyGameInfo::DecodeFramed(pStream);
    return CNMMyGameInfo::Decode(pDecoder, pStream);
}

// @0x141573720
unsigned int CNMMyGameInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    for (unsigned int i = 0; i < 10; ++i)
        m_10[i] = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-FUNCTIONAL 0x1415734a0: initializes the my-game record signature and zeroed ten-entry payload.
// @0x1415734a0
CNMMyGameInfo::CNMMyGameInfo() : CNMSerializable(0x6d67,1,1),m_10{} {}

// MS2-PIN: ??0CNMMyGameInfo@@QEAA@XZ 0x1415734a0 ; recovered my-game constructor
