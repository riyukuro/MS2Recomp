// Nexon Messenger monitor-guild-online-info-ex request serialization.
// MS2-UNIT: unit_14158d360
// MS2-RANGE: 0x14158d360-0x14158d8f0 .text$mn
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
extern void FUN_14156acb0(void*, unsigned __int64);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14158d360: initializes the extended monitor request fields to zero.
// @0x14158d360
CNMMonitorGuildOnlineInfoExFunc::CNMMonitorGuildOnlineInfoExFunc()
    : CNMFunc(0x7004, 1, 0, 0), m_30(0), m_38(0), m_3c(0), m_40(0), m_44(0) {}

// MS2-FUNCTIONAL 0x14158d3f0: stores guild identity and monitor type.
// @0x14158d3f0
CNMMonitorGuildOnlineInfoExFunc::CNMMonitorGuildOnlineInfoExFunc(unsigned __int64 guildId, int type)
    : CNMFunc(0x7004, 1, 0, 0), m_30(guildId), m_38(type), m_3c(0), m_40(0), m_44(0) {}

// MS2-FUNCTIONAL 0x14158d480: stores guild identity, monitor type, and status.
// @0x14158d480
CNMMonitorGuildOnlineInfoExFunc::CNMMonitorGuildOnlineInfoExFunc(unsigned __int64 guildId, int type, int status)
    : CNMFunc(0x7004, 1, 0, 0), m_30(guildId), m_38(type), m_3c(status), m_40(0), m_44(0) {}

// MS2-FUNCTIONAL 0x14158d520: stores all extended monitor fields.
// @0x14158d520
CNMMonitorGuildOnlineInfoExFunc::CNMMonitorGuildOnlineInfoExFunc(unsigned __int64 guildId, int type, int status,
                                                                 int flags, int result)
    : CNMFunc(0x7004, 1, 0, 0), m_30(guildId), m_38(type), m_3c(status), m_40(flags), m_44(result) {}

// MS2-FUNCTIONAL 0x14158d5c0: frames the extended monitor request.
// @0x14158d5c0
unsigned int CNMMonitorGuildOnlineInfoExFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMMonitorGuildOnlineInfoExFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158d620: selects the encoder by wire format.
// @0x14158d620
unsigned int CNMMonitorGuildOnlineInfoExFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMMonitorGuildOnlineInfoExFunc::Encode(pEncoder, pStream);
    return CNMMonitorGuildOnlineInfoExFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14158d680: encodes guild identity and extended monitor fields in replies.
// @0x14158d680
unsigned int CNMMonitorGuildOnlineInfoExFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) {
        FUN_14156acb0(encoder, static_cast<unsigned __int64>(m_30));
        FUN_14156ab00(encoder, static_cast<unsigned char>(m_38));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_3c));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_40));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_44));
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158d730: decodes a framed extended monitor response.
// @0x14158d730
unsigned int CNMMonitorGuildOnlineInfoExFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMMonitorGuildOnlineInfoExFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158d7c0: selects the decoder by wire format.
// @0x14158d7c0
unsigned int CNMMonitorGuildOnlineInfoExFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMMonitorGuildOnlineInfoExFunc::DecodeFramed(pStream);
    return CNMMonitorGuildOnlineInfoExFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14158d820: restores guild identity and extended monitor fields.
// @0x14158d820
unsigned int CNMMonitorGuildOnlineInfoExFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(decoder);
        using ReadU8 = unsigned char(__fastcall*)(void*);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        using ReadU64 = unsigned __int64(__fastcall*)(void*);
        m_30 = static_cast<long long>(reinterpret_cast<ReadU64>(vtable[4])(decoder));
        m_38 = reinterpret_cast<ReadU8>(vtable[1])(decoder);
        m_3c = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
        m_40 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
        m_44 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMMonitorGuildOnlineInfoExFunc@@QEAA@XZ 0x14158d360
