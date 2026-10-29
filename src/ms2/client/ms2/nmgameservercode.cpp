// Recovered Nexon Messenger game server code record.
// MS2-UNIT: ?\nmgameservercode.cpp
// MS2-RANGE: 0x14157aaf0-0x14157adc0 .text$mn
// MS2-PIN: ??0CNMSerializableEncoder@@QEAA@PEAVCNMStream@@PEAVCNMSerializable@@@Z 0x14156bcb0
// MS2-PIN: ??1CNMSerializableEncoder@@QEAA@XZ 0x14156bd50
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);

// @0x14157aaf0
CNMGameServerCode::CNMGameServerCode()
    : CNMSerializable(0x6773, 1, 1), m_nServerCode(0)
{
}

// @0x14157ab40
CNMGameServerCode::CNMGameServerCode(int serverCode)
    : CNMSerializable(0x6773, 1, 1), m_nServerCode(serverCode)
{
}

// @0x14157ab90
unsigned int CNMGameServerCode::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGameServerCode::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x14157abf0
unsigned int CNMGameServerCode::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGameServerCode::Encode(pEncoder, pStream);
    return CNMGameServerCode::EncodeFramed(pStream);
}

// @0x14157ac50
unsigned int CNMGameServerCode::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_nServerCode));
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x14157ac90
unsigned int CNMGameServerCode::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGameServerCode::Decode(&decoder, pStream);
}

// @0x14157ad20
unsigned int CNMGameServerCode::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGameServerCode::DecodeFramed(pStream);
    return CNMGameServerCode::Decode(pDecoder, pStream);
}

// @0x14157ad80
unsigned int CNMGameServerCode::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    m_nServerCode = static_cast<int>(pDecoder->ReadU32());
    return FUN_1415fb750(pDecoder);
}
