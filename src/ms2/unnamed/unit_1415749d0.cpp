// Nexon Messenger guild member record serializer methods.
// MS2-UNIT: unit_1415749d0
// MS2-RANGE: 0x1415749d0-0x141575d80 .text$mn
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
extern void FUN_14156ab00(void*, unsigned int);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned long long);
extern void FUN_14156ab90(void*, unsigned short);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern unsigned long long FUN_1415fb780(unsigned int, unsigned int);
extern unsigned long long FUN_1415fb760(unsigned int, unsigned int);
extern void* FUN_1415f39d0(void*);
extern void FUN_1415fc140(void*, unsigned int, const void*);
extern void FUN_1415eb480(void*, unsigned int, long long);

// MS2-FUNCTIONAL 0x1415749d0: initializes the guild-member identity, avatar and default flags.
// @0x1415749d0
CNMGuildMemberInfo::CNMGuildMemberInfo() : CNMSerializable(0x676d,1,1),m_nIDCode(0),m_szLoginID{},m_szNickName{},m_avatar(),m_na8(0),m_bac(0),m_nb0(0),m_nb4(1) {}

// MS2-FUNCTIONAL 0x141574aa0: builds a guild member from a channel member and derives its guild ID.
// @0x141574aa0
CNMGuildMemberInfo::CNMGuildMemberInfo(const CNMChannelMemberInfo& r) : CNMSerializable(0x676d,1,1),m_nIDCode(FUN_1415fb780(*reinterpret_cast<const unsigned int*>(&r.m_10[0]),0x10000)),m_szLoginID{},m_szNickName{},m_avatar(),m_na8(0),m_bac(0),m_nb0(0),m_nb4(*reinterpret_cast<const int*>(&r.m_10[4])) {FUN_1415fc140(m_szNickName,0x40,FUN_1415f39d0(const_cast<CNMStr<0x40>*>(&r.m_18)));}

// MS2-FUNCTIONAL 0x141574ba0: uses opaque stack storage for the temporary encoder; member record encoding behavior is preserved.
// @0x141574ba0
unsigned int CNMGuildMemberInfo::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141574c00: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141574c00
unsigned int CNMGuildMemberInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
}

// @0x141574c60
unsigned int CNMGuildMemberInfo::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    FUN_14156acb0(pEncoder, m_nIDCode);
    FUN_14156ae30(pEncoder, m_szLoginID);
    FUN_14156ae30(pEncoder, m_szNickName);
    m_avatar.EncodeFramed(pStream);
    FUN_14156ab00(pEncoder, static_cast<unsigned int>(m_na8));
    FUN_14156ab00(pEncoder, m_bac);
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_nb0));
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_nb4));
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141574d50: uses opaque stack storage for the temporary decoder; member record decode behavior is preserved.
// @0x141574d50
unsigned int CNMGuildMemberInfo::DecodeFramed(CNMStream* pStream)
{
    unsigned char decoderStorage[0x38];
    FUN_14156be10(decoderStorage, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoderStorage) != 0) {
        void** vtable = *reinterpret_cast<void***>(this);
        using DecodeMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<DecodeMethod>(vtable[5])(
            this, reinterpret_cast<CNMSerializableDecoder*>(decoderStorage), pStream);
    }
    FUN_14156bf10(decoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x141574de0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141574de0
unsigned int CNMGuildMemberInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(pDecoder) == 2) {
        using FramedMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMStream*);
        return reinterpret_cast<FramedMethod>(vtable[6])(this, pStream);
    }
    using DecodeMethod = unsigned int(__fastcall*)(CNMGuildMemberInfo*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<DecodeMethod>(vtable[5])(this, pDecoder, pStream);
}

// @0x141574e40
unsigned int CNMGuildMemberInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadU64 = unsigned long long(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_nIDCode = reinterpret_cast<ReadU64>(vtable[4])(pDecoder);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_szLoginID, 0x40);
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_szNickName, 0x40);
    m_avatar.Decode(reinterpret_cast<CNMSerializableDecoder*>(pDecoder), pStream);
    m_na8 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    m_bac = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    m_nb0 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    m_nb4 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-FUNCTIONAL 0x141574f80: initializes the extended guild-online record and its member vector.
// @0x141574f80
CNMGuildOnlineInfoEx::CNMGuildOnlineInfoEx() : CNMSerializable(0x6f65,1,1),m_10(0),m_18(0),m_1c(0),m_20{},m_40(0),m_aMembers{},m_60(0) {}

// MS2-FUNCTIONAL 0x141575020: merges two guild-online records and copies the selected member range.
// @0x141575020
CNMGuildOnlineInfoEx::CNMGuildOnlineInfoEx(const CNMGuildOnlineInfo& a,const CNMGuildOnlineInfo& b) : CNMGuildOnlineInfoEx(){const auto*pa=reinterpret_cast<const unsigned char*>(&a);m_10=FUN_1415fb760(*reinterpret_cast<const unsigned int*>(pa+0x20),*reinterpret_cast<const unsigned int*>(pa+0x48));m_18=a.m_10;m_1c=static_cast<unsigned int>(b.m_40.size());m_60=*reinterpret_cast<const unsigned int*>(pa+0x1c);m_aMembers=b.m_40;}

// MS2-FUNCTIONAL 0x141575140: extracts the online-guild key payload.
// @0x141575140
void* FUN_141575140(CNMGuildOnlineInfoEx* p,void* out){FUN_1415eb480(out,p->m_60,p->m_10);return out;}

// MS2-FUNCTIONAL 0x141575180: frames the extended guild-online payload.
// @0x141575180
unsigned int CNMGuildOnlineInfoEx::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGuildOnlineInfoEx*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}

// MS2-FUNCTIONAL 0x1415751e0: selects framed or direct extended guild encoding.
// @0x1415751e0
unsigned int CNMGuildOnlineInfoEx::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGuildOnlineInfoEx*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGuildOnlineInfoEx*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}

// MS2-FUNCTIONAL 0x141575240: serializes extended guild metadata and its member vector.
// @0x141575240
unsigned int CNMGuildOnlineInfoEx::Encode(CNMEncoder*e,CNMStream*s){FUN_14156acb0(reinterpret_cast<long long*>(e),m_10);FUN_14156ac20(e,m_18);FUN_14156ac20(e,m_1c);FUN_14156ae30(e,m_20);FUN_14156ab90(e,m_40);FUN_14156ac20(e,static_cast<unsigned int>(m_aMembers.size()));for(auto&m:m_aMembers)m.EncodeDispatch(e,s);FUN_14156ac20(e,m_60);FUN_1415f9990(e);return 1;}

// MS2-FUNCTIONAL 0x1415753b0: decodes the framed extended guild payload.
// @0x1415753b0
unsigned int CNMGuildOnlineInfoEx::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGuildOnlineInfoEx*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}

// MS2-FUNCTIONAL 0x141575440: selects direct or framed extended guild decoding.
// @0x141575440
unsigned int CNMGuildOnlineInfoEx::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGuildOnlineInfoEx*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGuildOnlineInfoEx*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}

// MS2-FUNCTIONAL 0x1415754a0: decodes extended guild metadata and reconstructs its member vector.
// @0x1415754a0
unsigned int CNMGuildOnlineInfoEx::Decode(CNMSerializableDecoder*d,CNMStream*s){m_10=d->ReadU64();m_18=d->ReadU32();m_1c=d->ReadU32();d->ReadBytes(reinterpret_cast<unsigned char*>(m_20),0x20);m_40=d->ReadU16();const unsigned int n=d->ReadU32();m_aMembers.clear();for(unsigned int i=0;i<n;++i){m_aMembers.emplace_back();m_aMembers.back().DecodeDispatch(d,s);}m_60=d->ReadU32();return static_cast<unsigned int>(FUN_1415fb750(d));}

// MS2-FUNCTIONAL 0x141575670: initializes the legacy guild-online record and its member vector.
// @0x141575670
CNMGuildOnlineInfo::CNMGuildOnlineInfo() : CNMSerializable(0x676f,1,1),m_10(0),m_14(0),m_18(0),m_1c{},m_3c(0),m_40{} {}

// MS2-FUNCTIONAL 0x141575710: copies the common guild fields and member vector into the legacy layout.
// @0x141575710
long long FUN_141575710(long long dst,long long src){auto*d=reinterpret_cast<CNMGuildOnlineInfo*>(dst);auto*s=reinterpret_cast<CNMGuildOnlineInfoEx*>(src);d->m_10=static_cast<unsigned int>(s->m_10);d->m_14=s->m_18;d->m_18=s->m_1c;memcpy(d->m_1c,s->m_20,0x20);d->m_3c=s->m_40;d->m_40=s->m_aMembers;return dst;}

// MS2-FUNCTIONAL 0x1415757b0: converts the legacy guild-online layout into the extended record.
// @0x1415757b0
CNMGuildOnlineInfoEx* FUN_1415757b0(const CNMGuildOnlineInfo* src,CNMGuildOnlineInfoEx* out){const auto*p=reinterpret_cast<const unsigned char*>(src);out->m_10=*reinterpret_cast<const unsigned long long*>(p+0x10);out->m_18=*reinterpret_cast<const unsigned int*>(p+0x14);out->m_1c=*reinterpret_cast<const unsigned int*>(p+0x18);memcpy(out->m_20,p+0x1c,0x20);out->m_40=*reinterpret_cast<const unsigned short*>(p+0x3c);out->m_aMembers=*reinterpret_cast<const std::vector<CNMGuildMemberInfo>*>(p+0x40);return out;}

// MS2-FUNCTIONAL 0x1415758c0: frames the legacy guild-online payload.
// @0x1415758c0
unsigned int CNMGuildOnlineInfo::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGuildOnlineInfo*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}

// MS2-FUNCTIONAL 0x141575920: selects framed or direct legacy guild encoding.
// @0x141575920
unsigned int CNMGuildOnlineInfo::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGuildOnlineInfo*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGuildOnlineInfo*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}

// MS2-FUNCTIONAL 0x141575980: serializes legacy guild-online fields and its member sequence.
// @0x141575980
unsigned int CNMGuildOnlineInfo::Encode(CNMEncoder*e,CNMStream*s){FUN_14156ac20(e,m_10);FUN_14156ac20(e,m_14);FUN_14156ac20(e,m_18);FUN_14156ae30(e,m_1c);FUN_14156ab90(e,m_3c);FUN_14156ac20(e,static_cast<unsigned int>(m_40.size()));for(auto&m:m_40)m.EncodeDispatch(e,s);FUN_1415f9990(e);return 1;}

// MS2-FUNCTIONAL 0x141575ae0: decodes the framed legacy guild-online payload.
// @0x141575ae0
unsigned int CNMGuildOnlineInfo::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGuildOnlineInfo*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}

// MS2-FUNCTIONAL 0x141575b70: selects direct or framed legacy guild decoding.
// @0x141575b70
unsigned int CNMGuildOnlineInfo::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGuildOnlineInfo*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGuildOnlineInfo*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}

// MS2-FUNCTIONAL 0x141575bd0: decodes the legacy guild-online fields and member vector.
// @0x141575bd0
unsigned int CNMGuildOnlineInfo::Decode(CNMSerializableDecoder*d,CNMStream*s){m_10=d->ReadU32();m_14=d->ReadU32();m_18=d->ReadU32();d->ReadBytes(reinterpret_cast<unsigned char*>(m_1c),0x20);m_3c=d->ReadU16();const unsigned int n=d->ReadU32();m_40.clear();for(unsigned int i=0;i<n;++i){m_40.emplace_back();m_40.back().DecodeDispatch(d,s);}return static_cast<unsigned int>(FUN_1415fb750(d));}

// MS2-PIN: ??0CNMGuildMemberInfo@@QEAA@XZ 0x1415749d0 ; recovered guild-member constructor
// MS2-PIN: ??0CNMGuildOnlineInfoEx@@QEAA@XZ 0x141574f80 ; recovered extended online constructor
// MS2-PIN: ??0CNMGuildOnlineInfo@@QEAA@XZ 0x141575670 ; recovered legacy online constructor
