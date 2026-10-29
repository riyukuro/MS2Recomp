// Nexon Messenger session-info request serialization.
// MS2-UNIT: unit_14159fc90
// MS2-RANGE: 0x14159fc90-0x1415a01a0 .text$mn
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
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x14159fc90: initializes the session query and its member vector.
// @0x14159fc90
CNMGSGetSessionInfoFunc::CNMGSGetSessionInfoFunc()
    : CNMFunc(0xc003, 1, 0, 0), m_30(), m_78()
{
}

// MS2-FUNCTIONAL 0x14159fd10: stores request flags in the base function and resets response data.
// @0x14159fd10
CNMGSGetSessionInfoFunc::CNMGSGetSessionInfoFunc(int nFlags)
    : CNMFunc(0xc003, 1, nFlags, 0), m_30(), m_78()
{
}

// MS2-FUNCTIONAL 0x14159fd90: frames the request and calls its encoder slot.
// @0x14159fd90
unsigned int CNMGSGetSessionInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGSGetSessionInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14159fdf0: chooses raw or framed encoding by format.
// @0x14159fdf0
unsigned int CNMGSGetSessionInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGSGetSessionInfoFunc::Encode(pEncoder, pStream);
    return CNMGSGetSessionInfoFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14159fe50: encodes session data and all member records for response direction.
// @0x14159fe50
unsigned int CNMGSGetSessionInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this)) {
        m_30.EncodeFramed(pStream);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_78.size()));
        for (std::vector<CNMSessionMemberInfo>::iterator it = m_78.begin(), end = m_78.end(); it != end; ++it)
            (*it).EncodeFramed(pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14159ff60: frames the response decoder and calls its virtual slot.
// @0x14159ff60
unsigned int CNMGSGetSessionInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGSGetSessionInfoFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14159fff0: selects direct or framed response decoding.
// @0x14159fff0
unsigned int CNMGSGetSessionInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGSGetSessionInfoFunc::DecodeFramed(pStream);
    return CNMGSGetSessionInfoFunc::Decode(pDecoder, pStream);
}

// @0x1415a0050
unsigned int CNMGSGetSessionInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this)) {
        (&m_30)->DecodeFramed(pStream);
        // One member is decoded into the same local each time and a copy is pushed (a failed decode keeps the
        // previous member's data).
        CNMSessionMemberInfo member;
        unsigned int count = pDecoder->ReadU32();
        m_78.clear();
        for (unsigned int i = 0; i < count; ++i) {
            member.DecodeFramed(pStream);
            m_78.push_back(member);
        }
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGSGetSessionInfoFunc@@QEAA@XZ 0x14159fc90
// MS2-PIN: ??0CNMGSGetSessionInfoFunc@@QEAA@H@Z 0x14159fd10
// MS2-PIN: ?EncodeFramed@CNMGSGetSessionInfoFunc@@UEAAIPEAVCNMStream@@@Z 0x14159fd90
// MS2-PIN: ?EncodeDispatch@CNMGSGetSessionInfoFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14159fdf0
// MS2-PIN: ?Encode@CNMGSGetSessionInfoFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14159fe50
// MS2-PIN: ?DecodeFramed@CNMGSGetSessionInfoFunc@@UEAAIPEAVCNMStream@@@Z 0x14159ff60
// MS2-PIN: ?DecodeDispatch@CNMGSGetSessionInfoFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14159fff0
// MS2-PIN: ?Decode@CNMGSGetSessionInfoFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415a0050
