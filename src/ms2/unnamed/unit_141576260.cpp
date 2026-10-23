// Nexon Messenger session member list encoding methods.
// MS2-UNIT: unit_141576260
// MS2-RANGE: 0x141576260-0x141576ae0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
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
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x141576780: uses opaque stack storage for the temporary encoder; list encoding behavior is preserved.
// @0x141576780
unsigned int CNMSessionMemberList::EncodeFramed(CNMStream* pStream)
{
    unsigned char encoderStorage[0x18];
    FUN_14156bcb0(encoderStorage, pStream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using EncodeMethod = unsigned int(__fastcall*)(CNMSessionMemberList*, CNMEncoder*, CNMStream*);
    const unsigned int result = reinterpret_cast<EncodeMethod>(vtable[2])(
        this, reinterpret_cast<CNMEncoder*>(encoderStorage), pStream);
    FUN_14156bd50(encoderStorage);
    return result;
}

// MS2-FUNCTIONAL 0x1415767e0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415767e0
unsigned int CNMSessionMemberList::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using EncodeMethod = unsigned int(__fastcall*)(CNMSessionMemberList*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<EncodeMethod>(vtable[2])(this, pEncoder, pStream);
    }
    using FramedMethod = unsigned int(__fastcall*)(CNMSessionMemberList*, CNMStream*);
    return reinterpret_cast<FramedMethod>(vtable[3])(this, pStream);
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
unsigned int CNMSessionMemberInfo::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMSessionMemberInfo*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x1415763a0: selects direct or framed member encoding.
// @0x1415763a0
unsigned int CNMSessionMemberInfo::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMSessionMemberInfo*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMSessionMemberInfo*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141576400: serializes member fields and the nested avatar.
// @0x141576400
unsigned int CNMSessionMemberInfo::Encode(CNMEncoder*e,CNMStream*s){auto*p=reinterpret_cast<unsigned char*>(this);FUN_14156acb0(e,*reinterpret_cast<unsigned long long*>(p+0x10));FUN_14156ae30(e,p+0x18);FUN_14156ae30(e,p+0x58);FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(p+0x98));FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(p+0x9c));FUN_14156ae30(e,p+0xa0);FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(p+0xe0));m_avatar.EncodeDispatch(e,s);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x1415764f0: decodes the framed member payload.
// @0x1415764f0
unsigned int CNMSessionMemberInfo::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMSessionMemberInfo*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141576580: selects direct or framed member decoding.
// @0x141576580
unsigned int CNMSessionMemberInfo::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMSessionMemberInfo*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMSessionMemberInfo*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x1415765e0: decodes member fields and its nested avatar.
// @0x1415765e0
unsigned int CNMSessionMemberInfo::Decode(CNMSerializableDecoder*d,CNMStream*s){auto*p=reinterpret_cast<unsigned char*>(this);void**v=*reinterpret_cast<void***>(d);using U32=unsigned int(__fastcall*)(void*);using U64=unsigned long long(__fastcall*)(void*);using Bytes=unsigned int(__fastcall*)(void*,void*,unsigned int);*reinterpret_cast<unsigned long long*>(p+0x10)=reinterpret_cast<U64>(v[4])(d);reinterpret_cast<Bytes>(v[9])(d,p+0x18,0x40);reinterpret_cast<Bytes>(v[9])(d,p+0x58,0x40);*reinterpret_cast<unsigned int*>(p+0x98)=reinterpret_cast<U32>(v[3])(d);*reinterpret_cast<unsigned int*>(p+0x9c)=reinterpret_cast<U32>(v[3])(d);reinterpret_cast<Bytes>(v[9])(d,p+0xa0,0x40);*reinterpret_cast<unsigned int*>(p+0xe0)=reinterpret_cast<U32>(v[3])(d);m_avatar.DecodeDispatch(d,s);return static_cast<unsigned int>(FUN_1415fb750(d));}

// MS2-FUNCTIONAL 0x141576730: initializes the session-member list record.
// @0x141576730
CNMSessionMemberList::CNMSessionMemberList() : CNMSerializable(0x6d6c,1,1),m_10{} {}
// MS2-FUNCTIONAL 0x141576900: decodes the framed member-list payload.
// @0x141576900
unsigned int CNMSessionMemberList::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMSessionMemberList*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141576990: selects direct or framed member-list decoding.
// @0x141576990
unsigned int CNMSessionMemberList::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMSessionMemberList*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMSessionMemberList*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x1415769f0: rebuilds the list from framed member records.
// @0x1415769f0
unsigned int CNMSessionMemberList::Decode(CNMSerializableDecoder*d,CNMStream*s){const unsigned int n=d->ReadU32();m_10.clear();for(unsigned int i=0;i<n;++i){m_10.emplace_back();m_10.back().DecodeFramed(s);}return static_cast<unsigned int>(FUN_1415fb750(d));}

// MS2-PIN: ??0CNMSessionMemberInfo@@QEAA@XZ 0x141576260 ; recovered session member constructor
// MS2-PIN: ??0CNMSessionMemberList@@QEAA@XZ 0x141576730 ; recovered member list constructor
