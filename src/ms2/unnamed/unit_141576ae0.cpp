// Nexon Messenger chat room member record serializer methods.
// MS2-UNIT: unit_141576ae0
// MS2-RANGE: 0x141576ae0-0x1415773e0 .text$mn
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
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern unsigned int FUN_14156e8d0(void*, void*, void*);
extern unsigned long long FUN_1415fb780(unsigned int, unsigned int);
extern void* FUN_1415f39d0(void*);
extern HRESULT Unk_CopyNullOnFail(char* dest, unsigned cch, const char* src);

// MS2-FUNCTIONAL 0x141576ca0: uses opaque stack storage for the temporary encoder; chat member encoding behavior is preserved.
// @0x141576ca0
unsigned int CNMChatRoomMemberInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMChatRoomMemberInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141576d00: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141576d00
unsigned int CNMChatRoomMemberInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMChatRoomMemberInfo::Encode(pEncoder, pStream);
    return CNMChatRoomMemberInfo::EncodeFramed(pStream);
}

// @0x141576d60
unsigned int CNMChatRoomMemberInfo::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156e8d0(this, pEncoder, pStream);
    FUN_14156ae30(pEncoder, m_1a8);
    FUN_14156ac20(pEncoder, m_1c8.nLow);
    FUN_14156ac20(pEncoder, m_1c8.nHigh);
    FUN_14156ac20(pEncoder, m_1d0);
    FUN_14156ae30(pEncoder, m_1d4);
    FUN_14156ac20(pEncoder, m_214);
    FUN_14156ac20(pEncoder, m_218);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141576e40: uses opaque stack storage for the temporary decoder; chat member decode behavior is preserved.
// @0x141576e40
unsigned int CNMChatRoomMemberInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMChatRoomMemberInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x141576ed0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141576ed0
unsigned int CNMChatRoomMemberInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMChatRoomMemberInfo::DecodeFramed(pStream);
    return CNMChatRoomMemberInfo::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x141576f30: delegates the inherited real-user decoder to its address-bound base helper before reading chat-specific fields.
// @0x141576f30
unsigned int CNMChatRoomMemberInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMRealUserInfo::DecodeDispatch(pDecoder, pStream);
    pDecoder->ReadStringBufAlias(m_1a8, 0x20);
    m_1c8.nLow = pDecoder->ReadU32();
    m_1c8.nHigh = pDecoder->ReadU32();
    m_1d0 = pDecoder->ReadU32();
    pDecoder->ReadStringBufAlias(m_1d4, 0x40);
    m_214 = pDecoder->ReadU32();
    m_218 = pDecoder->ReadU32();
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-FUNCTIONAL 0x141576ae0: initializes chat-specific fields on the real-user record.
// @0x141576ae0
CNMChatRoomMemberInfo::CNMChatRoomMemberInfo()
    : CNMRealUserInfo(), m_1d0(0), m_214(0), m_218(0)
{
    ++m_bKind;
    m_1a8[0] = 0;
    m_1c8.nLow = 0;
    m_1c8.nHigh = 0;
    m_1d4[0] = 0;
}
// MS2-FUNCTIONAL 0x141576ba0: builds a chat member from channel membership information and room metadata.
// @0x141576ba0
// The exe leaves m_1a8 and m_1d4 unset here and ignores roomName (the nickname copy takes three arguments).
CNMChatRoomMemberInfo::CNMChatRoomMemberInfo(const CNMChannelMemberInfo& r, unsigned int roomMode, const char* roomName)
    : CNMRealUserInfo(), m_1d0(0), m_214(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(&r) + 0x28)), m_218(0)
{
    ++m_bKind;
    m_50 = static_cast<long long>(FUN_1415fb780(*reinterpret_cast<const unsigned int*>(reinterpret_cast<const unsigned char*>(&r) + 0x10), 0x10000));
    m_1c8.nLow = roomMode;
    m_1c8.nHigh = *reinterpret_cast<const int*>(reinterpret_cast<const unsigned char*>(&r) + 0x14);
    Unk_CopyNullOnFail(m_d0, 0x40, static_cast<const char*>(FUN_1415f39d0(const_cast<CNMStr<0x40>*>(&r.m_18))));
}

// MS2-FUNCTIONAL 0x141577050: initializes the chat-room member list.
// @0x141577050
CNMChatRoomMemberList::CNMChatRoomMemberList() : CNMSerializable(0x6d61,1,1),m_members{} {}
// MS2-FUNCTIONAL 0x1415770a0: frames the chat-room member list payload.
// @0x1415770a0
unsigned int CNMChatRoomMemberList::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMChatRoomMemberList::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141577100: selects direct or framed list encoding.
// @0x141577100
unsigned int CNMChatRoomMemberList::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMChatRoomMemberList::Encode(pEncoder, pStream);
    return CNMChatRoomMemberList::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141577160: encodes the member count and framed members.
// @0x141577160
unsigned int CNMChatRoomMemberList::Encode(CNMEncoder*e,CNMStream*s){unsigned int n=static_cast<unsigned int>(m_members.size());FUN_14156ac20(e,n);for(unsigned int i=0;i<n;i++){CNMChatRoomMemberInfo* p=&m_members[i];p->EncodeFramed(s);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141577200: decodes the framed list payload.
// @0x141577200
unsigned int CNMChatRoomMemberList::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMChatRoomMemberList::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141577290: selects direct or framed list decoding.
// @0x141577290
unsigned int CNMChatRoomMemberList::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMChatRoomMemberList::DecodeFramed(pStream);
    return CNMChatRoomMemberList::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x1415772f0: clears and rebuilds the chat-room member vector.
// @0x1415772f0
unsigned int CNMChatRoomMemberList::Decode(CNMSerializableDecoder*d,CNMStream*s){unsigned int n=d->ReadU32();m_members.clear();for(unsigned int i=0;i<n;i++){CNMChatRoomMemberInfo info;info.CNMChatRoomMemberInfo::DecodeFramed(s);m_members.push_back(info);}return static_cast<unsigned int>(FUN_1415fb750(d));}

// MS2-PIN: ??0CNMChatRoomMemberInfo@@QEAA@XZ 0x141576ae0 ; recovered chat member constructor
// MS2-PIN: ??0CNMChatRoomMemberList@@QEAA@XZ 0x141577050 ; recovered member list constructor
