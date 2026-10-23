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
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

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
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMGSGetSessionInfoFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14159fdf0: chooses raw or framed encoding by format.
// @0x14159fdf0
unsigned int CNMGSGetSessionInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMGSGetSessionInfoFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMGSGetSessionInfoFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
}

// MS2-FUNCTIONAL 0x14159fe50: encodes session data and all member records for response direction.
// @0x14159fe50
unsigned int CNMGSGetSessionInfoFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this)) {
        m_30.EncodeFramed(pStream);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_78.size()));
        for (auto& member : m_78)
            member.EncodeFramed(pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14159ff60: frames the response decoder and calls its virtual slot.
// @0x14159ff60
unsigned int CNMGSGetSessionInfoFunc::DecodeFramed(CNMStream* pStream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMGSGetSessionInfoFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14159fff0: selects direct or framed response decoding.
// @0x14159fff0
unsigned int CNMGSGetSessionInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMGSGetSessionInfoFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMGSGetSessionInfoFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x1415a0050: restores session data and decodes each returned member.
// @0x1415a0050
unsigned int CNMGSGetSessionInfoFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this)) {
        m_30.DecodeFramed(pStream);
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        const unsigned int count = reinterpret_cast<ReadU32>(vtable[3])(pDecoder);
        m_78.clear();
        for (unsigned int i = 0; i < count; ++i) {
            CNMSessionMemberInfo member;
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
