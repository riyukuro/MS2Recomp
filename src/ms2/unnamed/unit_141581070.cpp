// Nexon Messenger change-my-info request serialization.
// MS2-UNIT: unit_141581070
// MS2-RANGE: 0x141581070-0x141581690 .text$mn
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
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415fbe70(void*, unsigned int, const void*);

// MS2-FUNCTIONAL 0x141581070: initializes all optional change fields to their absent defaults.
// @0x141581070
CNMChangeMyInfoFunc::CNMChangeMyInfoFunc()
    : CNMFunc(0x2003, 1, 0, 0)
{
    m_30 = 0;
    m_34 = 0;
    m_b8 = -1;
    m_38[0] = 0;
    m_78[0] = 0;
}

// MS2-FUNCTIONAL 0x141581110: sets optional name, position, and state fields and their presence bits.
// @0x141581110
CNMChangeMyInfoFunc::CNMChangeMyInfoFunc(int mode, long long name, long long position, int state, unsigned extra)
    : CNMFunc(0x2003, 1, 0, 0)
{
    // The exe only initialises the mask and the extra value; absent fields stay unset.
    m_30 = 0;
    m_bc = extra;
    if (mode != 0) { m_34 = mode; m_30 |= 1; }
    if (name != 0) {
        if (name != 0) FUN_1415fbe70(m_38, 0x40, reinterpret_cast<const void*>(name)); else m_38[0] = 0;
        m_30 |= 2;
    }
    if (position != 0) {
        if (position != 0) FUN_1415fbe70(m_78, 0x40, reinterpret_cast<const void*>(position)); else m_78[0] = 0;
        m_30 |= 4;
    }
    if (state != -1) { m_b8 = state; m_30 |= 0x10; }
}

// MS2-FUNCTIONAL 0x141581280: frames the request and dispatches its encoder slot.
// @0x141581280
unsigned int CNMChangeMyInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMChangeMyInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415812e0: selects raw or framed encoding from the format flag.
// @0x1415812e0
unsigned int CNMChangeMyInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMChangeMyInfoFunc::Encode(pEncoder, pStream);
    return CNMChangeMyInfoFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x141581340: serializes only the fields selected by the presence mask.
// @0x141581340
unsigned int CNMChangeMyInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
        if (m_30 & 1) FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_34));
        if (m_30 & 2) FUN_14156ae30(pEncoder, m_38);
        if (m_30 & 4) FUN_14156ae30(pEncoder, m_78);
        if (m_30 & 0x10) FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_b8));
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_bc));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141581450: decodes through a temporary framed decoder and the virtual decode slot.
// @0x141581450
unsigned int CNMChangeMyInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMChangeMyInfoFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415814e0: chooses framed decoding for wire format 2.
// @0x1415814e0
unsigned int CNMChangeMyInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMChangeMyInfoFunc::DecodeFramed(pStream);
    return CNMChangeMyInfoFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141581540: restores fields selected by the reply presence mask.
// @0x141581540
unsigned int CNMChangeMyInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        m_30 = pDecoder->ReadU32();
        if (m_30 & 1) m_34 = pDecoder->ReadU32();
        if (m_30 & 2) pDecoder->ReadStringBufAlias(m_38, 0x40);
        if (m_30 & 4) pDecoder->ReadStringBufAlias(m_78, 0x40);
        if (m_30 & 0x10) m_b8 = pDecoder->ReadU32();
        m_bc = pDecoder->ReadU32();
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMChangeMyInfoFunc@@QEAA@XZ 0x141581070
