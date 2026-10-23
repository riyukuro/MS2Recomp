// Nexon Messenger channel member conversion and serializers.
// MS2-UNIT: unit_14157adc0
// MS2-RANGE: 0x14157adc0-0x14157f390 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern unsigned int FUN_1415fb290(unsigned long long);
extern void FUN_1415e5a40(void*, const void*);
extern void FUN_1415e5ae0(void*, const void*);
extern void* FUN_1415e5ac0(void*);
extern void* FUN_1415e5b60(void*);
extern void FUN_1415ef1f0(void*, const void*);
extern void FUN_1415e5a80(void*, const void*);
extern void FUN_1415ef1c0(void*, const void*);
extern void FUN_1415ef220(void*, const void*);
extern void* FUN_1415f39d0(void*);
extern void* FUN_1415f39e0(void*);
extern unsigned int FUN_1415fa070(void*);
extern void* FUN_1415f9fc0(void*);
extern unsigned int FUN_1415fa080(void*);
extern void* FUN_1415f9fe0(void*);

// MS2-FUNCTIONAL: these local template constructors delegate to the recovered CNMStr initializers.
template<> CNMStr<0x40>::CNMStr() : m_p(nullptr) { FUN_1415e5ac0(this); }
template<> CNMStr<0x400>::CNMStr() : m_p(nullptr) { FUN_1415e5b60(this); }

// MS2-FUNCTIONAL 0x14157c1d0: initializes the channel-member strings and record fields.
// @0x14157c1d0
CNMChannelMemberInfo::CNMChannelMemberInfo() : CNMSerializable(0x686d,1,1),m_10{},m_18(),m_20(),m_28{} {m_bFlag=0xfe;}

// MS2-FUNCTIONAL 0x14157c260: copies the channel-member scalars and both string objects.
// @0x14157c260
CNMChannelMemberInfo::CNMChannelMemberInfo(const CNMChannelMemberInfo&r) : CNMSerializable(0x686d,1,1),m_10{},m_18(),m_20(),m_28{} {m_bFlag=0xfe;memcpy(m_10,r.m_10,sizeof(m_10));FUN_1415e5a40(&m_18,&r.m_18);FUN_1415e5ae0(&m_20,&r.m_20);memcpy(m_28,r.m_28,sizeof(m_28));}

// MS2-FUNCTIONAL 0x14157c310: copy helper for the channel-member record layout.
// @0x14157c310
long long FUN_14157c310(long long dst,long long src){auto*d=reinterpret_cast<CNMChannelMemberInfo*>(dst);auto*s=reinterpret_cast<CNMChannelMemberInfo*>(src);memcpy(d->m_10,s->m_10,sizeof(d->m_10));FUN_1415ef1c0(&d->m_18,&s->m_18);FUN_1415ef220(&d->m_20,&s->m_20);memcpy(d->m_28,s->m_28,sizeof(d->m_28));return dst;}

// MS2-FUNCTIONAL 0x14157c3a0: converts a chat-room member into channel-member fields.
// @0x14157c3a0
CNMChannelMemberInfo::CNMChannelMemberInfo(const CNMChatRoomMemberInfo&r) : CNMSerializable(0x686d,1,1),m_10{},m_18(),m_20(),m_28{} {m_bFlag=0xfe;*reinterpret_cast<unsigned int*>(m_10)=FUN_1415fb290(static_cast<unsigned long long>(r.m_50));*reinterpret_cast<unsigned int*>(m_10+4)=static_cast<unsigned int>(r.m_1c8.nHigh);FUN_1415e5a80(&m_18,r.m_d0);memcpy(m_28,&r.m_214,sizeof(r.m_214));}

// MS2-FUNCTIONAL 0x14157c460: helper that copies chat-room member values into a channel-member record.
// @0x14157c460
long long FUN_14157c460(long long dst,long long src){auto*d=reinterpret_cast<CNMChannelMemberInfo*>(dst);auto*s=reinterpret_cast<CNMChatRoomMemberInfo*>(src);*reinterpret_cast<unsigned int*>(d->m_10)=FUN_1415fb290(static_cast<unsigned long long>(s->m_50));*reinterpret_cast<unsigned int*>(d->m_10+4)=static_cast<unsigned int>(s->m_1c8.nHigh);FUN_1415ef1f0(&d->m_18,s->m_d0);memcpy(d->m_28,&s->m_214,sizeof(s->m_214));return dst;}

// MS2-FUNCTIONAL 0x14157c4e0: frames the channel-member payload.
// @0x14157c4e0
unsigned int CNMChannelMemberInfo::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChannelMemberInfo*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}

// MS2-FUNCTIONAL 0x14157c540: dispatches channel-member encoding by format.
// @0x14157c540
unsigned int CNMChannelMemberInfo::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMChannelMemberInfo*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMChannelMemberInfo*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}

// MS2-FUNCTIONAL 0x14157c5a0: serializes channel identifiers, names, and member flags.
// @0x14157c5a0
unsigned int CNMChannelMemberInfo::Encode(CNMEncoder*e,CNMStream*){FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(m_10));FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(m_10+4));FUN_14156ae30(e,FUN_1415f39d0(&m_18));FUN_14156ae30(e,FUN_1415f39e0(&m_20));FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(m_28));FUN_1415f9990(e);return 1;}

// MS2-FUNCTIONAL 0x14157c640: decodes the framed channel-member payload.
// @0x14157c640
unsigned int CNMChannelMemberInfo::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChannelMemberInfo*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}

// MS2-FUNCTIONAL 0x14157c6d0: dispatches channel-member decoding by format.
// @0x14157c6d0
unsigned int CNMChannelMemberInfo::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMChannelMemberInfo*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMChannelMemberInfo*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}

// MS2-FUNCTIONAL 0x14157c730: reads the two names through their CNMStr buffers.
// @0x14157c730
unsigned int CNMChannelMemberInfo::Decode(CNMSerializableDecoder*d,CNMStream*){void**v=*reinterpret_cast<void***>(d);using U32=unsigned int(__fastcall*)(void*);using Bytes=unsigned int(__fastcall*)(void*,void*,unsigned int);*reinterpret_cast<unsigned int*>(m_10)=reinterpret_cast<U32>(v[3])(d);*reinterpret_cast<unsigned int*>(m_10+4)=reinterpret_cast<U32>(v[3])(d);reinterpret_cast<Bytes>(v[9])(d,FUN_1415f9fc0(&m_18),FUN_1415fa070(&m_18));reinterpret_cast<Bytes>(v[9])(d,FUN_1415f9fe0(&m_20),FUN_1415fa080(&m_20));*reinterpret_cast<unsigned int*>(m_28)=reinterpret_cast<U32>(v[3])(d);return static_cast<unsigned int>(FUN_1415fb750(d));}

// MS2-PIN: ??0CNMChannelMemberInfo@@QEAA@XZ 0x14157c1d0 ; recovered default constructor
// MS2-PIN: ??0CNMChannelMemberInfo@@QEAA@AEBV0@@Z 0x14157c260 ; recovered copy constructor
// MS2-PIN: ??0CNMChannelMemberInfo@@QEAA@AEBVCNMChatRoomMemberInfo@@@Z 0x14157c3a0 ; recovered conversion constructor
