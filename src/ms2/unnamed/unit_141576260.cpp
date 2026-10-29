// Nexon Messenger session member list encoding methods.
// MS2-UNIT: unit_141576260
// MS2-RANGE: 0x141576260-0x141576ae0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// MS2-FUNCTIONAL 0x141576780: uses opaque stack storage for the temporary encoder; list encoding behavior is preserved.
// @0x141576780
unsigned int CNMSessionMemberList::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSessionMemberList::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415767e0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415767e0
unsigned int CNMSessionMemberList::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSessionMemberList::Encode(pEncoder, pStream);
    return CNMSessionMemberList::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x141576840: serializes the count and each member in order; the range loop differs from the original iterator helper calls.
// @0x141576840
unsigned int CNMSessionMemberList::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10.size()));
    for (CNMSessionMemberInfo& member : m_10)
        member.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141576260: initializes member fields and the nested avatar record.
// @0x141576260
CNMSessionMemberInfo::CNMSessionMemberInfo() : CNMSerializable(0x736d,1,1),m_10{},m_avatar() {m_bFlag=0xfe;}
// MS2-FUNCTIONAL 0x141576340: frames the session-member payload.
// @0x141576340
unsigned int CNMSessionMemberInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSessionMemberInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x1415763a0: selects direct or framed member encoding.
// @0x1415763a0
unsigned int CNMSessionMemberInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSessionMemberInfo::Encode(pEncoder, pStream);
    return CNMSessionMemberInfo::EncodeFramed(pStream);
}
// Serializes the member fields, then the nested avatar as its own framed record.
// @0x141576400
unsigned int CNMSessionMemberInfo::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156acb0(pEncoder, *reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(this) + 0x10));
    FUN_14156ae30(pEncoder, reinterpret_cast<unsigned char*>(this) + 0x18);
    FUN_14156ae30(pEncoder, reinterpret_cast<unsigned char*>(this) + 0x58);
    FUN_14156ac20(pEncoder, *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x98));
    FUN_14156ac20(pEncoder, *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x9c));
    FUN_14156ae30(pEncoder, reinterpret_cast<unsigned char*>(this) + 0xa0);
    FUN_14156ac20(pEncoder, *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xe0));
    m_avatar.EncodeFramed(pStream);
    FUN_1415f9990(pEncoder);
    return 1;
}
// MS2-FUNCTIONAL 0x1415764f0: decodes the framed member payload.
// @0x1415764f0
unsigned int CNMSessionMemberInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSessionMemberInfo::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141576580: selects direct or framed member decoding.
// @0x141576580
unsigned int CNMSessionMemberInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSessionMemberInfo::DecodeFramed(pStream);
    return CNMSessionMemberInfo::Decode(pDecoder, pStream);
}
// Reads the member fields, then the nested avatar as its own framed record.
// @0x1415765e0
unsigned int CNMSessionMemberInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    *reinterpret_cast<unsigned long long*>(reinterpret_cast<unsigned char*>(this) + 0x10) = pDecoder->ReadU64();
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(this) + 0x18, 0x40);
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(this) + 0x58, 0x40);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x98) = pDecoder->ReadU32();
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0x9c) = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(reinterpret_cast<char*>(this) + 0xa0, 0x40);
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned char*>(this) + 0xe0) = pDecoder->ReadU32();
    m_avatar.DecodeFramed(pStream);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-FUNCTIONAL 0x141576730: initializes the session-member list record.
// @0x141576730
CNMSessionMemberList::CNMSessionMemberList() : CNMSerializable(0x6d6c,1,1),m_10{} {}
// MS2-FUNCTIONAL 0x141576900: decodes the framed member-list payload.
// @0x141576900
unsigned int CNMSessionMemberList::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSessionMemberList::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141576990: selects direct or framed member-list decoding.
// @0x141576990
unsigned int CNMSessionMemberList::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSessionMemberList::DecodeFramed(pStream);
    return CNMSessionMemberList::Decode(pDecoder, pStream);
}
// Rebuilds the list from framed member records. One record local is reused for every entry and a copy is pushed.
// @0x1415769f0
unsigned int CNMSessionMemberList::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMSessionMemberInfo member;
    unsigned int nCount = pDecoder->ReadU32();
    m_10.clear();
    for (unsigned int i = 0; i < nCount; ++i)
    {
        member.DecodeFramed(pStream);
        m_10.push_back(member);
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMSessionMemberInfo@@QEAA@XZ 0x141576260 ; recovered session member constructor
// MS2-PIN: ??0CNMSessionMemberList@@QEAA@XZ 0x141576730 ; recovered member list constructor
