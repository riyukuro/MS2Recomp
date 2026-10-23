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
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_1415f9990(void*);
extern void FUN_1415f05b0(void*, const void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

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
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMCRChangeMyInfoFunc*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<Method>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(storage), pStream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14159df60: selects direct or framed encoding from the message format.
// @0x14159df60
unsigned int CNMCRChangeMyInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMCRChangeMyInfoFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, pEncoder, pStream);
    }
    using Framed = unsigned int(__fastcall*)(CNMCRChangeMyInfoFunc*, CNMStream*);
    return reinterpret_cast<Framed>(vtable[3])(this, pStream);
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
    unsigned char storage[0x38];
    FUN_14156be10(storage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMCRChangeMyInfoFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(storage), pStream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14159e0d0: selects direct or framed reply decoding by wire format.
// @0x14159e0d0
unsigned int CNMCRChangeMyInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using Framed = unsigned int(__fastcall*)(CNMCRChangeMyInfoFunc*, CNMStream*);
        return reinterpret_cast<Framed>(vtable[6])(this, pStream);
    }
    using Method = unsigned int(__fastcall*)(CNMCRChangeMyInfoFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, pDecoder, pStream);
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
