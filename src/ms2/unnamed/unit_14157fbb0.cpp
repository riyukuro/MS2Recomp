// Nexon Messenger virtual-user list request and reply serialization.
// MS2-UNIT: unit_14157fbb0
// MS2-RANGE: 0x14157fbb0-0x141580080 .text$mn
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
extern unsigned int FUN_14160bca0(void*);
extern void FUN_1416093e0(void*);

// MS2-FUNCTIONAL 0x14157fbb0: initializes request ID, status, and vector.
// @0x14157fbb0
CNMGetMyVirtualUserListFunc::CNMGetMyVirtualUserListFunc()
    : CNMFunc(0x1105, 1, 0, 0), m_30(0), m_38()
{
}

// MS2-FUNCTIONAL 0x14157fc20: stores the supplied result value and initializes vector.
// @0x14157fc20
CNMGetMyVirtualUserListFunc::CNMGetMyVirtualUserListFunc(unsigned result)
    : CNMFunc(0x1105, 1, 0, 0), m_30(static_cast<int>(result)), m_38()
{
}

// MS2-FUNCTIONAL 0x14157fc90: frames request and calls encoder slot.
// @0x14157fc90
unsigned int CNMGetMyVirtualUserListFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetMyVirtualUserListFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14157fcf0: selects raw or framed encoding by format.
// @0x14157fcf0
unsigned int CNMGetMyVirtualUserListFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetMyVirtualUserListFunc::Encode(pEncoder, pStream);
    return CNMGetMyVirtualUserListFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x14157fd50: emits vector payloads in request mode or the result value in reply mode.
// @0x14157fd50
unsigned int CNMGetMyVirtualUserListFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0) {
        FUN_14156ac20(pEncoder, FUN_14160bca0(&m_38));
        for (CNMVirtualUserInfo& info : m_38)
            info.EncodeDispatch(pEncoder, pStream);
    } else {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14157fe50: decodes a framed reply through a temporary decoder.
// @0x14157fe50
unsigned int CNMGetMyVirtualUserListFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetMyVirtualUserListFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14157fee0: chooses framed decoding for wire format 2.
// @0x14157fee0
unsigned int CNMGetMyVirtualUserListFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetMyVirtualUserListFunc::DecodeFramed(pStream);
    return CNMGetMyVirtualUserListFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14157ff40: reads the result in reply mode, or decodes framed virtual-user records into one reused local.
// @0x14157ff40
unsigned int CNMGetMyVirtualUserListFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_30 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    } else {
        CNMVirtualUserInfo info;
        void** vtable = *reinterpret_cast<void***>(pDecoder);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        const unsigned int count = reinterpret_cast<ReadU32>(vtable[3])(pDecoder);
        m_38.clear();
        for (unsigned int i = 0; i < count; ++i) {
            info.DecodeFramed(pStream);
            m_38.push_back(info);
        }
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMGetMyVirtualUserListFunc@@QEAA@XZ 0x14157fbb0
