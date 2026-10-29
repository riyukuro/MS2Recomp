// Nexon Messenger chat-room member info update request serialization.
// MS2-UNIT: unit_14159de00
// MS2-RANGE: 0x14159de00-0x14159e1b0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
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
extern void FUN_1415f9990(void*);
extern void FUN_1415f05b0(void*, const void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14159de00: initializes the change-my-info request and its embedded member record.
// @0x14159de00
CNMCRChangeMyInfoFunc::CNMCRChangeMyInfoFunc()
    : CNMFunc(0xb005, 1, 0, 0), m_30()
{
}

// MS2-FUNCTIONAL 0x14159de70: sets the request flags and copies the supplied member-info payload.
// @0x14159de70
CNMCRChangeMyInfoFunc::CNMCRChangeMyInfoFunc(int nFlags, const char* pszInfo)
    : CNMFunc(0xb005, 1, nFlags, 0), m_30()
{
    FUN_1415f05b0(&m_30, pszInfo);
}

// MS2-FUNCTIONAL 0x14159df00: frames the request and invokes the encoder virtual slot.
// @0x14159df00
unsigned int CNMCRChangeMyInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMCRChangeMyInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14159df60: selects direct or framed encoding from the message format.
// @0x14159df60
unsigned int CNMCRChangeMyInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMCRChangeMyInfoFunc::Encode(pEncoder, pStream);
    return CNMCRChangeMyInfoFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14159dfc0: sends the embedded member info only for request direction.
// @0x14159dfc0
unsigned int CNMCRChangeMyInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
        m_30.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14159e040: frames the reply and dispatches its decoder slot.
// @0x14159e040
unsigned int CNMCRChangeMyInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMCRChangeMyInfoFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14159e0d0: selects direct or framed reply decoding by wire format.
// @0x14159e0d0
unsigned int CNMCRChangeMyInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMCRChangeMyInfoFunc::DecodeFramed(pStream);
    return CNMCRChangeMyInfoFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14159e130: restores embedded member info for request direction and decoder status.
// @0x14159e130
unsigned int CNMCRChangeMyInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
        m_30.DecodeFramed(pStream);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMCRChangeMyInfoFunc@@QEAA@XZ 0x14159de00
// MS2-PIN: ??0CNMCRChangeMyInfoFunc@@QEAA@HPEBD@Z 0x14159de70
// MS2-PIN: ?EncodeFramed@CNMCRChangeMyInfoFunc@@UEAAIPEAVCNMStream@@@Z 0x14159df00
// MS2-PIN: ?EncodeDispatch@CNMCRChangeMyInfoFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14159df60
// MS2-PIN: ?Encode@CNMCRChangeMyInfoFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14159dfc0
// MS2-PIN: ?DecodeFramed@CNMCRChangeMyInfoFunc@@UEAAIPEAVCNMStream@@@Z 0x14159e040
// MS2-PIN: ?DecodeDispatch@CNMCRChangeMyInfoFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14159e0d0
// MS2-PIN: ?Decode@CNMCRChangeMyInfoFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14159e130
