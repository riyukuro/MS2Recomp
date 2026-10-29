// Nexon Messenger set-code-page request serialization.
// MS2-UNIT: unit_1415849b0
// MS2-RANGE: 0x1415849b0-0x141584d00 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*, void*, void*); extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x1415849b0: initializes code page to zero.
// @0x1415849b0
CNMSetCodePageFunc::CNMSetCodePageFunc() : CNMFunc(0x2109, 1, 0, 0), m_30(0), m_34(0) {}
// MS2-FUNCTIONAL 0x141584a10: stores the requested code page.
// @0x141584a10
CNMSetCodePageFunc::CNMSetCodePageFunc(int codePage) : CNMFunc(0x2109, 1, 0, 0), m_30(codePage), m_34(0) {}
// MS2-FUNCTIONAL 0x141584a70: frames request and dispatches encoder slot.
// @0x141584a70
unsigned int CNMSetCodePageFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSetCodePageFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141584ad0: chooses raw or framed encoding by format.
// @0x141584ad0
unsigned int CNMSetCodePageFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSetCodePageFunc::Encode(pEncoder, pStream);
    return CNMSetCodePageFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141584b30: serializes the code page value.
// @0x141584b30
unsigned int CNMSetCodePageFunc::Encode(CNMEncoder* e,CNMStream* s) { CNMFunc::EncodeDispatch(e,s); if(FUN_1415fb700(this)) FUN_14156ac20(e,static_cast<unsigned int>(m_30)); FUN_1415f9990(e); return 1; }
// MS2-FUNCTIONAL 0x141584ba0: decodes through a temporary framed decoder.
// @0x141584ba0
unsigned int CNMSetCodePageFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSetCodePageFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141584c30: chooses framed decoding for wire format 2.
// @0x141584c30
unsigned int CNMSetCodePageFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSetCodePageFunc::DecodeFramed(pStream);
    return CNMSetCodePageFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141584c90: restores code page from reply.
// @0x141584c90
unsigned int CNMSetCodePageFunc::Decode(CNMSerializableDecoder* d,CNMStream* s) { CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using F=unsigned int(__fastcall*)(void*);m_30=static_cast<int>(reinterpret_cast<F>(v[3])(d));}return static_cast<unsigned int>(FUN_1415fb750(d)); }
// MS2-PIN: ??0CNMSetCodePageFunc@@QEAA@XZ 0x1415849b0
