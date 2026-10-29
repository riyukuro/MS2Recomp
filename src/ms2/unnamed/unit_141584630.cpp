// Nexon Messenger set-locale request serialization.
// MS2-UNIT: unit_141584630
// MS2-RANGE: 0x141584630-0x1415849b0 .text$mn
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
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x141584630: initializes locale to the default and sublocale to zero.
// @0x141584630
CNMSetLocaleFunc::CNMSetLocaleFunc() : CNMFunc(0x2104, 1, 0, 0), m_30(1), m_34(0) {}

// MS2-FUNCTIONAL 0x141584690: stores locale and sublocale values.
// @0x141584690
CNMSetLocaleFunc::CNMSetLocaleFunc(int locale, int sublocale) : CNMFunc(0x2104, 1, 0, 0), m_30(locale), m_34(sublocale) {}

// MS2-FUNCTIONAL 0x141584700: frames the request and dispatches its encoder slot.
// @0x141584700
unsigned int CNMSetLocaleFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSetLocaleFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141584760: selects raw or framed encoding by the format flag.
// @0x141584760
unsigned int CNMSetLocaleFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSetLocaleFunc::Encode(pEncoder, pStream);
    return CNMSetLocaleFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x1415847c0: serializes locale and sublocale values.
// @0x1415847c0
unsigned int CNMSetLocaleFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream); if (FUN_1415fb700(this)) { FUN_14156ac20(pEncoder, m_30); FUN_14156ac20(pEncoder, m_34); } FUN_1415f9990(pEncoder); return 1;
}

// MS2-FUNCTIONAL 0x141584840: decodes through a temporary framed decoder.
// @0x141584840
unsigned int CNMSetLocaleFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSetLocaleFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415848d0: selects framed decoding for wire format 2.
// @0x1415848d0
unsigned int CNMSetLocaleFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSetLocaleFunc::DecodeFramed(pStream);
    return CNMSetLocaleFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141584930: restores locale and sublocale values.
// @0x141584930
unsigned int CNMSetLocaleFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream); if (FUN_1415fb700(this)) { void** vtable = *reinterpret_cast<void***>(pDecoder); using U32 = unsigned int(__fastcall*)(void*); m_30 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder)); m_34 = static_cast<int>(reinterpret_cast<U32>(vtable[3])(pDecoder)); } return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMSetLocaleFunc@@QEAA@XZ 0x141584630
