// Nexon Messenger user lookup record serializer methods.
// MS2-UNIT: unit_141574480
// MS2-RANGE: 0x141574480-0x1415749d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x141574580: uses opaque stack storage for the temporary encoder; lookup record encoding behavior is preserved.
// @0x141574580
unsigned int CNMFindUserInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMFindUserInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415745e0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415745e0
unsigned int CNMFindUserInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMFindUserInfo::Encode(pEncoder, pStream);
    return CNMFindUserInfo::EncodeFramed(pStream);
}

// @0x141574640
unsigned int CNMFindUserInfo::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156acb0(pEncoder, static_cast<unsigned long long>(m_10));
    FUN_14156ae30(pEncoder, m_18);
    FUN_14156ae30(pEncoder, m_58);
    FUN_14156ae30(pEncoder, m_78);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_b8));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_bc));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_c0));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_c4));
    m_c8.EncodeFramed(pStream);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_d8));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141574760: uses opaque stack storage for the temporary decoder; lookup record decode behavior is preserved.
// @0x141574760
unsigned int CNMFindUserInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMFindUserInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415747f0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415747f0
unsigned int CNMFindUserInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMFindUserInfo::DecodeFramed(pStream);
    return CNMFindUserInfo::Decode(pDecoder, pStream);
}

// @0x141574850
unsigned int CNMFindUserInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    m_10 = pDecoder->ReadU64();
    pDecoder->ReadStringBufAlias(m_18, 0x40);
    pDecoder->ReadStringBufAlias(m_58, 0x20);
    pDecoder->ReadStringBufAlias(m_78, 0x40);
    m_b8 = pDecoder->ReadU32();
    m_bc = pDecoder->ReadU32();
    m_c0 = pDecoder->ReadU32();
    m_c4 = pDecoder->ReadU32();
    m_c8.DecodeFramed(pStream);
    m_d8 = pDecoder->ReadU32();
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-FUNCTIONAL 0x141574480: initializes the find-user signature, avatar subobject and fixed result fields.
// @0x141574480
CNMFindUserInfo::CNMFindUserInfo() : CNMSerializable(0x6675,1,1)
{
    m_10 = 0;
    memset(m_18,0,sizeof(m_18));
    memset(m_58,0,sizeof(m_58));
    memset(m_78,0,sizeof(m_78));
    m_b8 = 0;
    m_bc = 0;
    m_c0 = 0;
    m_c4 = 0;
    m_d8 = 0;
}

// MS2-PIN: ??0CNMFindUserInfo@@QEAA@XZ 0x141574480 ; recovered find-user constructor
