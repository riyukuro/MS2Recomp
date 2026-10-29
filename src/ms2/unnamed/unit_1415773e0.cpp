// Nexon Messenger guild member level serializer methods.
// MS2-UNIT: unit_1415773e0
// MS2-RANGE: 0x1415773e0-0x141578bf0 .text$mn
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
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ab00(void*, unsigned int);
extern void FUN_1415cb0b0(const void*, void*);
extern void FUN_1415fc140(void*, unsigned int, const void*, ...);

// MS2-FUNCTIONAL 0x1415773e0: initializes the guild-member level record.
// @0x1415773e0
CNMGuildMemberLevelInfo::CNMGuildMemberLevelInfo() : CNMSerializable(0x6d65,1,1),m_10(0),m_11{} {}

// MS2-FUNCTIONAL 0x141577440: uses opaque stack storage for the temporary encoder; guild level encoding behavior is preserved.
// @0x141577440
unsigned int CNMGuildMemberLevelInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGuildMemberLevelInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x1415774a0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415774a0
unsigned int CNMGuildMemberLevelInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGuildMemberLevelInfo::Encode(pEncoder, pStream);
    return CNMGuildMemberLevelInfo::EncodeFramed(pStream);
}

// @0x141577500
unsigned int CNMGuildMemberLevelInfo::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ab00(pEncoder, m_10);
    FUN_14156ae30(pEncoder, m_11);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141577560: uses opaque stack storage for the temporary decoder; guild level decode behavior is preserved.
// @0x141577560
unsigned int CNMGuildMemberLevelInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGuildMemberLevelInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415775f0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415775f0
unsigned int CNMGuildMemberLevelInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGuildMemberLevelInfo::DecodeFramed(pStream);
    return CNMGuildMemberLevelInfo::Decode(pDecoder, pStream);
}

// @0x141577650
unsigned int CNMGuildMemberLevelInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_11, 0x40);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-FUNCTIONAL 0x1415776c0: initializes the extended chat-room record and its member-level vector.
// @0x1415776c0
CNMChatRoomInfoEx::CNMChatRoomInfoEx() : CNMSerializable(0x7265,1,1)
{
    m_10 = 0;
    m_18 = 0;
    m_20 = 0;
    m_24 = 0;
    memset(m_28,0,sizeof(m_28));
    memset(m_68,0,sizeof(m_68));
    m_468 = 0;
    m_46c = 0;
    m_470 = 0;
    memset(m_474,0,sizeof(m_474));
    m_4b8 = 0;
    m_4d8 = 0;
    m_4dc = 0;
}
// MS2-FUNCTIONAL 0x1415777e0: initializes a copied extended chat-room record using the vendor copy helper.
// @0x1415777e0
CNMChatRoomInfoEx::CNMChatRoomInfoEx(const CNMChatRoomInfoEx&r) : CNMSerializable(0x7265,1,1),m_10(0),m_18(0),m_20(0),m_24(0),m_28{},m_68{},m_468(0),m_46c(0),m_470(0),m_474{},m_4b8(0),m_4c0{},m_4d8(0),m_4dc(0) {m_bFlag=0xfe;FUN_1415cb0b0(&r,this);}
// MS2-FUNCTIONAL 0x141577850: forwards construction through the vendor chat-room copy helper.
// @0x141577850
CNMChatRoomInfoEx* FUN_141577850(CNMChatRoomInfoEx*a,CNMChatRoomInfoEx*b){FUN_1415cb0b0(b,a);return a;}
// MS2-FUNCTIONAL 0x141577880: frames the extended chat-room payload.
// @0x141577880
unsigned int CNMChatRoomInfoEx::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMChatRoomInfoEx::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x1415778e0: selects direct or framed extended chat-room encoding.
// @0x1415778e0
unsigned int CNMChatRoomInfoEx::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMChatRoomInfoEx::Encode(pEncoder, pStream);
    return CNMChatRoomInfoEx::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x141577940: serializes extended chat-room metadata and guild-member-level entries.
// @0x141577940
unsigned int CNMChatRoomInfoEx::Encode(CNMEncoder*e,CNMStream*s){FUN_14156ac20(e,m_10);FUN_14156acb0(e,m_18);FUN_14156ac20(e,m_20);FUN_14156ac20(e,m_24);FUN_14156ae30(e,m_28);FUN_14156ae30(e,m_68);FUN_14156ac20(e,m_468);FUN_14156ac20(e,m_46c);FUN_14156ac20(e,m_470);FUN_14156ae30(e,m_474);FUN_14156acb0(e,m_4b8);FUN_14156ac20(e,m_4d8);FUN_14156ac20(e,m_4dc);FUN_14156ac20(e,static_cast<unsigned int>(m_4c0.size()));for(auto&x:m_4c0)x.EncodeFramed(s);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141577b10: decodes the framed extended chat-room payload.
// @0x141577b10
unsigned int CNMChatRoomInfoEx::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMChatRoomInfoEx::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141577ba0: selects direct or framed extended chat-room decoding.
// @0x141577ba0
unsigned int CNMChatRoomInfoEx::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMChatRoomInfoEx::DecodeFramed(pStream);
    return CNMChatRoomInfoEx::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141577c00: decodes extended metadata and recreates its vector records.
// @0x141577c00
unsigned int CNMChatRoomInfoEx::Decode(CNMSerializableDecoder*d,CNMStream*s){m_10=d->ReadU32();m_18=d->ReadU64();m_20=d->ReadU32();m_24=d->ReadU32();d->ReadStringBufAlias(reinterpret_cast<char*>(m_28),0x40);d->ReadStringBufAlias(reinterpret_cast<char*>(m_68),0x400);m_468=d->ReadU32();m_46c=d->ReadU32();m_470=d->ReadU32();d->ReadStringBufAlias(reinterpret_cast<char*>(m_474),0x40);m_4b8=d->ReadU64();m_4d8=d->ReadU32();m_4dc=d->ReadU32();{CNMGuildMemberLevelInfo x;unsigned int n=d->ReadU32();m_4c0.clear();for(unsigned int i=0;i<n;++i){x.DecodeFramed(s);m_4c0.push_back(x);}}return static_cast<unsigned int>(FUN_1415fb750(d));}

// Initializes the legacy chat-room record; the exe zeroes the five label buffers in the body and leaves m_1c/m_4ac uninitialized.
// @0x141577ef0
CNMChatRoomInfo::CNMChatRoomInfo() : CNMSerializable(0x7269,1,1),m_10(0),m_14(0),m_18(0),m_20{},m_60{},m_460(0),m_464(0),m_468(0),m_46c{},m_4b0(0),m_5f8(0),m_5fc(0)
{
    memset(m_4b8,0,sizeof(m_4b8));
    memset(m_4f8,0,sizeof(m_4f8));
    memset(m_538,0,sizeof(m_538));
    memset(m_578,0,sizeof(m_578));
    memset(m_5b8,0,sizeof(m_5b8));
}
// MS2-FUNCTIONAL 0x141578070: converts extended room metadata and its five typed labels into legacy layout.
// @0x141578070
long long FUN_141578070(long long dst,long long src)
{
#define D reinterpret_cast<CNMChatRoomInfo*>(dst)
#define S reinterpret_cast<CNMChatRoomInfoEx*>(src)
    D->m_10=S->m_10;D->m_14=static_cast<int>(S->m_18);D->m_18=S->m_20;D->m_1c=S->m_24;
    FUN_1415fc140(D->m_20,0x40,S->m_28);FUN_1415fc140(D->m_60,0x400,S->m_68);
    D->m_460=S->m_468;D->m_464=S->m_46c;D->m_468=S->m_470;FUN_1415fc140(D->m_46c,0x40,S->m_474);
    D->m_4b0=static_cast<long long>(S->m_4b8);D->m_5f8=S->m_4d8;D->m_5fc=S->m_4dc;
    for (std::vector<CNMGuildMemberLevelInfo>::iterator it=S->m_4c0.begin(), end=S->m_4c0.end(); it!=end; ++it)
    {
        switch ((*it).m_10)
        {
        case 1: FUN_1415fc140(D->m_4b8,0x40,(*it).m_11); break;
        case 2: FUN_1415fc140(D->m_4f8,0x40,(*it).m_11); break;
        case 3: FUN_1415fc140(D->m_538,0x40,(*it).m_11); break;
        case 4: FUN_1415fc140(D->m_578,0x40,(*it).m_11); break;
        case 5: FUN_1415fc140(D->m_5b8,0x40,(*it).m_11); break;
        }
    }
    return dst;
#undef D
#undef S
}
// MS2-FUNCTIONAL 0x141578330: converts a legacy chat-room record into extended layout and five label records.
// @0x141578330
CNMChatRoomInfoEx* FUN_141578330(const CNMChatRoomInfo*src,CNMChatRoomInfoEx*out){CNMChatRoomInfoEx tmp;CNMGuildMemberLevelInfo x;tmp.m_10=src->m_10;tmp.m_18=static_cast<unsigned int>(src->m_14);tmp.m_20=src->m_18;tmp.m_24=src->m_1c;FUN_1415fc140(tmp.m_28,0x40,src->m_20);FUN_1415fc140(tmp.m_68,0x400,src->m_60);tmp.m_468=src->m_460;tmp.m_46c=src->m_464;tmp.m_470=src->m_468;FUN_1415fc140(tmp.m_474,0x40,src->m_46c);tmp.m_4b8=static_cast<unsigned long long>(src->m_4b0);tmp.m_4d8=src->m_5f8;tmp.m_4dc=src->m_5fc;const char*labels[]={src->m_4b8,src->m_4f8,src->m_538,src->m_578,src->m_5b8};for(unsigned int i=0;i<5;++i){x.m_10=static_cast<unsigned char>(i+1);FUN_1415fc140(x.m_11,0x40,labels[i]);tmp.m_4c0.push_back(x);}*out=tmp;return out;}
// MS2-FUNCTIONAL 0x141578620: frames the legacy chat-room payload.
// @0x141578620
unsigned int CNMChatRoomInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMChatRoomInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141578680: selects direct or framed legacy chat-room encoding.
// @0x141578680
unsigned int CNMChatRoomInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMChatRoomInfo::Encode(pEncoder, pStream);
    return CNMChatRoomInfo::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x1415786e0: serializes legacy chat-room metadata and the five member labels.
// @0x1415786e0
unsigned int CNMChatRoomInfo::Encode(CNMEncoder*e,CNMStream*){FUN_14156ac20(e,m_10);FUN_14156ac20(e,m_14);FUN_14156ac20(e,m_18);FUN_14156ae30(e,m_20);FUN_14156ae30(e,m_60);FUN_14156ac20(e,m_460);FUN_14156ac20(e,m_464);FUN_14156ac20(e,m_468);FUN_14156ae30(e,m_46c);FUN_14156acb0(e,static_cast<unsigned long long>(m_4b0));FUN_14156ac20(e,m_5f8);FUN_14156ac20(e,m_5fc);FUN_14156ae30(e,m_4b8);FUN_14156ae30(e,m_4f8);FUN_14156ae30(e,m_538);FUN_14156ae30(e,m_578);FUN_14156ae30(e,m_5b8);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141578880: decodes the framed legacy chat-room payload.
// @0x141578880
unsigned int CNMChatRoomInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMChatRoomInfo::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141578910: selects direct or framed legacy chat-room decoding.
// @0x141578910
unsigned int CNMChatRoomInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMChatRoomInfo::DecodeFramed(pStream);
    return CNMChatRoomInfo::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141578970: decodes all legacy chat-room fields.
// @0x141578970
unsigned int CNMChatRoomInfo::Decode(CNMSerializableDecoder*d,CNMStream*){m_10=d->ReadU32();m_14=d->ReadU32();m_18=d->ReadU32();d->ReadStringBufAlias(reinterpret_cast<char*>(m_20),0x40);d->ReadStringBufAlias(reinterpret_cast<char*>(m_60),0x400);m_460=d->ReadU32();m_464=d->ReadU32();m_468=d->ReadU32();d->ReadStringBufAlias(reinterpret_cast<char*>(m_46c),0x40);m_4b0=static_cast<long long>(d->ReadU64());m_5f8=d->ReadU32();m_5fc=d->ReadU32();d->ReadStringBufAlias(reinterpret_cast<char*>(m_4b8),0x40);d->ReadStringBufAlias(reinterpret_cast<char*>(m_4f8),0x40);d->ReadStringBufAlias(reinterpret_cast<char*>(m_538),0x40);d->ReadStringBufAlias(reinterpret_cast<char*>(m_578),0x40);d->ReadStringBufAlias(reinterpret_cast<char*>(m_5b8),0x40);return static_cast<unsigned int>(FUN_1415fb750(d));}

// MS2-PIN: ??0CNMGuildMemberLevelInfo@@QEAA@XZ 0x1415773e0 ; recovered guild member level constructor
// MS2-PIN: ??0CNMChatRoomInfoEx@@QEAA@XZ 0x1415776c0 ; recovered extended room constructor
// MS2-PIN: ??0CNMChatRoomInfo@@QEAA@XZ 0x141577ef0 ; recovered room constructor
