// Nexon Messenger monitor-guild-online-info request serialization.
// MS2-UNIT: unit_14158cf10
// MS2-RANGE: 0x14158cf10-0x14158d360 .text$mn
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
extern void FUN_14156ab00(void*, unsigned int);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14158cf10: initializes the monitor request fields to zero.
// @0x14158cf10
CNMMonitorGuildOnlineInfoFunc::CNMMonitorGuildOnlineInfoFunc()
    : CNMFunc(0x7002, 1, 0, 0), m_30(0), m_34(0), m_38(0) {}

// MS2-FUNCTIONAL 0x14158cf80: stores the monitored guild type and enabled flag.
// @0x14158cf80
CNMMonitorGuildOnlineInfoFunc::CNMMonitorGuildOnlineInfoFunc(int type, int enabled)
    : CNMFunc(0x7002, 1, 0, 0), m_30(type), m_34(enabled), m_38(0) {}

// MS2-FUNCTIONAL 0x14158d000: stores the monitored guild type, enabled flag, and status.
// @0x14158d000
CNMMonitorGuildOnlineInfoFunc::CNMMonitorGuildOnlineInfoFunc(int type, int enabled, int status)
    : CNMFunc(0x7002, 1, 0, 0), m_30(type), m_34(enabled), m_38(status) {}

// MS2-FUNCTIONAL 0x14158d080: frames the monitor-guild-online-info request.
// @0x14158d080
unsigned int CNMMonitorGuildOnlineInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMMonitorGuildOnlineInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158d0e0: selects the encoder by wire format.
// @0x14158d0e0
unsigned int CNMMonitorGuildOnlineInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMMonitorGuildOnlineInfoFunc::Encode(pEncoder, pStream);
    return CNMMonitorGuildOnlineInfoFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14158d140: encodes monitor type, enabled state, and result status.
// @0x14158d140
unsigned int CNMMonitorGuildOnlineInfoFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_30));
        FUN_14156ab00(encoder, static_cast<unsigned char>(m_34));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_38));
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158d1d0: decodes a framed monitor response.
// @0x14158d1d0
unsigned int CNMMonitorGuildOnlineInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMMonitorGuildOnlineInfoFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158d260: selects the decoder by wire format.
// @0x14158d260
unsigned int CNMMonitorGuildOnlineInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMMonitorGuildOnlineInfoFunc::DecodeFramed(pStream);
    return CNMMonitorGuildOnlineInfoFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14158d2c0: restores monitor type, enabled state, and response status.
// @0x14158d2c0
unsigned int CNMMonitorGuildOnlineInfoFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(decoder);
        using ReadU8 = unsigned char(__fastcall*)(void*);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
        m_34 = reinterpret_cast<ReadU8>(vtable[1])(decoder);
        m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMMonitorGuildOnlineInfoFunc@@QEAA@XZ 0x14158cf10
