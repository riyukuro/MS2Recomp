// Nexon Messenger channel member conversion and serializers.
// MS2-UNIT: unit_14157adc0
// MS2-RANGE: 0x14157adc0-0x14157f390 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb720(void*);
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

// ---- connection configuration record -----------------------------------------------------------------------------
extern void FUN_1415fc140(void*,unsigned int,const void*); extern void FUN_14156ab90(void*,unsigned short); extern void FUN_14156ab00(void*,unsigned char);
extern void FUN_1415e5a20(void*); extern void FUN_1415e59e0(void*,const void*); extern void FUN_1415e59a0(void*,const void*);
extern void FUN_1415e5a40(void*,const void*); extern void FUN_1415e5ae0(void*,const void*); extern void FUN_1415ef160(void*,const void*);
extern void* FUN_1415f39c0(void*); extern void* FUN_1415fa060(void*); extern void* FUN_1415f9fa0(void*);
// MS2-FUNCTIONAL 0x14157adc0: builds the recovered record layout, but constructor parameter types were erased in the decompiler.
// @0x14157adc0
CNMConnConfig::CNMConnConfig():CNMSerializable(0x6363,1,1),m_10{},m_30(0),m_32{},m_52(0),m_54(1),m_58(),m_60(0){m_bFlag=0xfe;FUN_1415e5a20(&m_58);}
// MS2-FUNCTIONAL 0x14157ae70: copies the bounded string fields and string object per the decompiled constructor.
// @0x14157ae70
CNMConnConfig::CNMConnConfig(const char*host,unsigned short port,const char*user,unsigned short mode,unsigned char flags,const char*token,unsigned short channel):CNMSerializable(0x6363,1,1),m_10{},m_30(port),m_32{},m_52(mode),m_54(flags),m_58(),m_60(channel){m_bFlag=0xfe;if(host)FUN_1415fc140(m_10,0x20,host);if(user)FUN_1415fc140(m_32,0x20,user);if(token)FUN_1415e59e0(&m_58,token);}
// MS2-FUNCTIONAL 0x14157af50: copies fixed fields and the embedded CNMStr through the recovered copy routines.
// @0x14157af50
CNMConnConfig::CNMConnConfig(const CNMConnConfig&r):CNMSerializable(0x6363,1,1),m_10{},m_30(r.m_30),m_32{},m_52(r.m_52),m_54(r.m_54),m_58(),m_60(r.m_60){m_bFlag=0xfe;memcpy(m_10,r.m_10,sizeof m_10);memcpy(m_32,r.m_32,sizeof m_32);FUN_1415e59a0(&m_58,&r.m_58);}
// MS2-FUNCTIONAL 0x14157b040: applies the recovered field-wise assignment helper.
// @0x14157b040
CNMConnConfig& CNMConnConfig::operator=(const CNMConnConfig&r){if(this!=&r){FUN_1415fc140(m_10,0x20,r.m_10);m_30=r.m_30;FUN_1415fc140(m_32,0x20,r.m_32);m_52=r.m_52;m_54=r.m_54;FUN_1415ef160(&m_58,&r.m_58);m_60=r.m_60;}return *this;}
// MS2-FUNCTIONAL 0x14157b100: frames this serializable record with the recovered encoder helper.
// @0x14157b100
unsigned int CNMConnConfig::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMConnConfig*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157b160: selects the same virtual serializer slots from the message format.
// @0x14157b160
unsigned int CNMConnConfig::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMConnConfig*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMConnConfig*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157b1c0: emits both fixed strings, ports, flags and token in the decompiled field order.
// @0x14157b1c0
unsigned int CNMConnConfig::Encode(CNMEncoder*e,CNMStream*){FUN_14156ae30(e,m_10);FUN_14156ab90(e,m_30);FUN_14156ae30(e,m_32);FUN_14156ab90(e,m_52);FUN_14156ab00(e,static_cast<unsigned char>(m_54));FUN_14156ae30(e,FUN_1415f39c0(&m_58));FUN_14156ab90(e,m_60);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157b290: decodes the framed record using the shared decoder helper.
// @0x14157b290
unsigned int CNMConnConfig::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMConnConfig*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157b320: chooses framed or direct decode based on the decoder format.
// @0x14157b320
unsigned int CNMConnConfig::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMConnConfig*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMConnConfig*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157b380: reads the fields in their serialized order with the proper field widths.
// @0x14157b380
unsigned int CNMConnConfig::Decode(CNMSerializableDecoder*d,CNMStream*){void**v=*reinterpret_cast<void***>(d);using U16=unsigned short(__fastcall*)(void*);using U8=unsigned char(__fastcall*)(void*);using U32=unsigned(__fastcall*)(void*);using Bytes=void(__fastcall*)(void*,void*,unsigned);reinterpret_cast<Bytes>(v[9])(d,m_10,0x20);m_30=static_cast<short>(reinterpret_cast<U16>(v[2])(d));reinterpret_cast<Bytes>(v[9])(d,m_32,0x20);m_52=static_cast<short>(reinterpret_cast<U16>(v[2])(d));m_54=reinterpret_cast<U8>(v[1])(d);reinterpret_cast<Bytes>(v[9])(d,FUN_1415f9fa0(&m_58),static_cast<unsigned>(reinterpret_cast<U32>(v[3])(d)));m_60=static_cast<short>(reinterpret_cast<U16>(v[2])(d));FUN_1415fb750(d);return 1;}

// ---- channel information record ------------------------------------------------------------------------------------
extern void* FUN_1415f39e0(void*); extern void* FUN_1415f39d0(void*); extern void* FUN_1415f9fe0(void*); extern void* FUN_1415f9fc0(void*);
extern unsigned int FUN_1415fa080(void*); extern unsigned int FUN_1415fa070(void*);
// MS2-FUNCTIONAL 0x14157b4b0: initializes all scalar fields and embedded strings from the record constructor.
// @0x14157b4b0
CNMChannelInfo::CNMChannelInfo():CNMSerializable(0x6869,1,1),m_10(0),m_14(0),m_18(0),m_1c(0),m_20(0),m_28(),m_30(),m_38(0),m_3c(0),m_40(0),m_44(0),m_48(0),m_4c(0),m_50(){m_bFlag=0xfe;FUN_1415e5b60(&m_28);FUN_1415e5ac0(&m_30);FUN_1415e5ac0(&m_50);}
// MS2-FUNCTIONAL 0x14157b5b0: copies scalars and embedded strings using the recovered copy routines.
// @0x14157b5b0
CNMChannelInfo::CNMChannelInfo(const CNMChannelInfo&r):CNMSerializable(0x6869,1,1),m_10(r.m_10),m_14(r.m_14),m_18(r.m_18),m_1c(r.m_1c),m_20(r.m_20),m_28(),m_30(),m_38(r.m_38),m_3c(r.m_3c),m_40(r.m_40),m_44(r.m_44),m_48(r.m_48),m_4c(r.m_4c),m_50(){m_bFlag=0xfe;FUN_1415e5ae0(&m_28,&r.m_28);FUN_1415e5a40(&m_30,&r.m_30);FUN_1415e5a40(&m_50,&r.m_50);}
// MS2-FUNCTIONAL 0x14157b6f0: reuses the recovered field-wise copy helper.
// @0x14157b6f0
CNMChannelInfo& CNMChannelInfo::operator=(const CNMChannelInfo&r){if(this!=&r){m_10=r.m_10;m_14=r.m_14;m_18=r.m_18;m_1c=r.m_1c;m_20=r.m_20;FUN_1415ef220(&m_28,&r.m_28);FUN_1415ef1c0(&m_30,&r.m_30);m_38=r.m_38;m_3c=r.m_3c;m_40=r.m_40;m_44=r.m_44;m_48=r.m_48;m_4c=r.m_4c;FUN_1415ef1c0(&m_50,&r.m_50);}return *this;}
// MS2-FUNCTIONAL 0x14157b800: frames the channel-information record.
// @0x14157b800
unsigned int CNMChannelInfo::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChannelInfo*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157b860: selects the matching virtual encoding slot by format.
// @0x14157b860
unsigned int CNMChannelInfo::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMChannelInfo*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMChannelInfo*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157b8c0: writes five scalars, three strings, then five scalars in the decompiled order.
// @0x14157b8c0
unsigned int CNMChannelInfo::Encode(CNMEncoder*e,CNMStream*){FUN_14156ac20(e,m_10);FUN_14156ac20(e,m_14);FUN_14156ac20(e,m_18);FUN_14156ac20(e,m_1c);FUN_14156ac20(e,m_20);FUN_14156ae30(e,FUN_1415f39e0(&m_28));FUN_14156ae30(e,FUN_1415f39d0(&m_30));FUN_14156ac20(e,m_38);FUN_14156ac20(e,m_3c);FUN_14156ac20(e,m_40);FUN_14156ac20(e,m_44);FUN_14156ac20(e,m_48);FUN_14156ae30(e,FUN_1415f39d0(&m_50));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157ba00: frames channel-info decoding with the common decoder helper.
// @0x14157ba00
unsigned int CNMChannelInfo::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChannelInfo*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157ba90: dispatches direct/framed decode based on the message discriminator.
// @0x14157ba90
unsigned int CNMChannelInfo::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMChannelInfo*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMChannelInfo*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157baf0: restores scalar and string fields with capacities from the embedded CNMStr objects.
// @0x14157baf0
unsigned int CNMChannelInfo::Decode(CNMSerializableDecoder*d,CNMStream*){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);using Bytes=void(__fastcall*)(void*,void*,unsigned);m_10=reinterpret_cast<U>(v[3])(d);m_14=reinterpret_cast<U>(v[3])(d);m_18=reinterpret_cast<U>(v[3])(d);m_1c=reinterpret_cast<U>(v[3])(d);m_20=reinterpret_cast<U>(v[3])(d);reinterpret_cast<Bytes>(v[9])(d,FUN_1415f9fe0(&m_28),FUN_1415fa080(&m_28));reinterpret_cast<Bytes>(v[9])(d,FUN_1415f9fc0(&m_30),FUN_1415fa070(&m_30));m_38=reinterpret_cast<U>(v[3])(d);m_3c=reinterpret_cast<U>(v[3])(d);m_40=reinterpret_cast<U>(v[3])(d);m_44=reinterpret_cast<U>(v[3])(d);m_48=reinterpret_cast<U>(v[3])(d);reinterpret_cast<Bytes>(v[9])(d,FUN_1415f9fc0(&m_50),FUN_1415fa070(&m_50));FUN_1415fb750(d);return 1;}

// ---- channel member list ------------------------------------------------------------------------------------------
extern unsigned int FUN_14160b700(void*); extern void FUN_141608ae0(void*); extern void FUN_14160b1e0(void*,void*);
// MS2-FUNCTIONAL 0x14157c830: initializes the channel-member vector and record signature.
// @0x14157c830
CNMChannelMemberInfoList::CNMChannelMemberInfoList():CNMSerializable(0x686c,1,1),m_10(){}
// MS2-FUNCTIONAL 0x14157c880: copies the existing member vector into a record with the copy-constructor flag.
// @0x14157c880
CNMChannelMemberInfoList::CNMChannelMemberInfoList(const CNMChannelMemberInfoList&r):CNMSerializable(0x686c,1,1),m_10(r.m_10){m_bFlag=0xfe;}
// MS2-FUNCTIONAL 0x14157c900: frames the member-list record.
// @0x14157c900
unsigned int CNMChannelMemberInfoList::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChannelMemberInfoList*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157c960: selects the record encoder based on the message format.
// @0x14157c960
unsigned int CNMChannelMemberInfoList::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMChannelMemberInfoList*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMChannelMemberInfoList*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157c9c0: emits the element count and framed member records.
// @0x14157c9c0
unsigned int CNMChannelMemberInfoList::Encode(CNMEncoder*e,CNMStream*s){FUN_14156ac20(e,static_cast<unsigned int>(m_10.size()));for(auto&item:m_10)item.EncodeFramed(s);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157ca80: frames the member-list decoder.
// @0x14157ca80
unsigned int CNMChannelMemberInfoList::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChannelMemberInfoList*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157cb10: dispatches member-list decoding by format.
// @0x14157cb10
unsigned int CNMChannelMemberInfoList::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMChannelMemberInfoList*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMChannelMemberInfoList*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157cb70: reads the count, clears old members, and decodes each framed member.
// @0x14157cb70
unsigned int CNMChannelMemberInfoList::Decode(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);unsigned n=reinterpret_cast<U>(v[3])(d);FUN_141608ae0(&m_10);for(unsigned i=0;i<n;++i){CNMChannelMemberInfo item;item.DecodeFramed(s);FUN_14160b1e0(&m_10,&item);}FUN_1415fb750(d);return 1;}

// ---- channel message ----------------------------------------------------------------------------------------------
extern void FUN_1415e58a0(void*,const void*); extern void FUN_1415e58e0(void*,const void*); extern void FUN_1415e5a80(void*,const void*); extern void FUN_1415ef130(void*,const void*);
extern void* FUN_1415f39a0(void*); extern void* FUN_1415f9f60(void*); extern unsigned int FUN_1415fa040(void*);
// MS2-FUNCTIONAL 0x14157cc30: initializes the channel message record and its three embedded string objects.
// @0x14157cc30
CNMChannelMessage::CNMChannelMessage():CNMSerializable(0x6873,1,1),m_10{},m_20(),m_28{},m_30(),m_38(),m_40{} {FUN_1415e5ac0(&m_20);FUN_1415e5b60(&m_38);}
// MS2-FUNCTIONAL 0x14157cd00: copies scalar storage and all embedded strings using record copy helpers.
// @0x14157cd00
CNMChannelMessage::CNMChannelMessage(const CNMChannelMessage&r):CNMSerializable(0x6873,1,1),m_10{},m_20(),m_28{},m_30(),m_38(),m_40{} {memcpy(m_10,r.m_10,sizeof m_10);FUN_1415e5a40(&m_20,&r.m_20);memcpy(m_28,r.m_28,sizeof m_28);FUN_1415e58a0(&m_30,&r.m_30);FUN_1415e5ae0(&m_38,&r.m_38);memcpy(m_40,r.m_40,sizeof m_40);}
// MS2-FUNCTIONAL 0x14157ce00: copies every member using the recovered field-wise helper.
// @0x14157ce00
CNMChannelMessage& CNMChannelMessage::operator=(const CNMChannelMessage&r){if(this!=&r){memcpy(m_10,r.m_10,sizeof m_10);FUN_1415ef1c0(&m_20,&r.m_20);memcpy(m_28,r.m_28,sizeof m_28);FUN_1415ef130(&m_30,&r.m_30);FUN_1415ef220(&m_38,&r.m_38);memcpy(m_40,r.m_40,sizeof m_40);}return *this;}
// MS2-FUNCTIONAL 0x14157ced0: creates a channel message from the recovered chat payload and classifies system labels.
// @0x14157ced0
CNMChannelMessage::CNMChannelMessage(const void*record,int messageType):CNMSerializable(0x6873,1,1),m_10{},m_20(),m_28{},m_30(),m_38(),m_40{} {auto*p=static_cast<const unsigned char*>(record);*reinterpret_cast<int*>(m_10+4)=messageType;*reinterpret_cast<int*>(m_10+8)=*reinterpret_cast<const int*>(p+0x14);FUN_1415e5a80(&m_20,p+0x28);m_28[0]=m_28[1]=m_28[2]=m_28[3]=0;FUN_1415e58e0(&m_30,p+0x268);FUN_1415e5b60(&m_38);m_40[0]=p[0x668];const char*label=reinterpret_cast<const char*>(p+0x28);if(CompareStringA(0x400,0,"_SYSTEM_",-1,label,-1)==2)*reinterpret_cast<int*>(m_10)=2;else if(CompareStringA(0x400,0,"_NOTICE_",-1,label,-1)==2||CompareStringA(0x400,0,"_OPEN_",-1,label,-1)==2)*reinterpret_cast<int*>(m_10)=1;}
// MS2-FUNCTIONAL 0x14157d080: frames channel-message encoding.
// @0x14157d080
unsigned int CNMChannelMessage::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChannelMessage*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157d0e0: selects channel-message encoder slot by format.
// @0x14157d0e0
unsigned int CNMChannelMessage::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMChannelMessage*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMChannelMessage*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157d140: serializes scalars and string fields in the recovered order.
// @0x14157d140
unsigned int CNMChannelMessage::Encode(CNMEncoder*e,CNMStream*){FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(m_10));FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(m_10+4));FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(m_10+8));FUN_14156ae30(e,FUN_1415f39d0(&m_20));FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(m_28));FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(m_28+4));FUN_14156ae30(e,FUN_1415f39a0(&m_30));FUN_14156ae30(e,FUN_1415f39e0(&m_38));FUN_14156ac20(e,*reinterpret_cast<unsigned int*>(m_40));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157d240: frames channel-message decoding.
// @0x14157d240
unsigned int CNMChannelMessage::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChannelMessage*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157d2d0: dispatches channel-message decode according to format.
// @0x14157d2d0
unsigned int CNMChannelMessage::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMChannelMessage*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMChannelMessage*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157d330: reads the scalar and string fields through decoder slots and the record's CNMStr buffers.
// @0x14157d330
unsigned int CNMChannelMessage::Decode(CNMSerializableDecoder*d,CNMStream*){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);using Bytes=void(__fastcall*)(void*,void*,unsigned);*reinterpret_cast<unsigned*>(m_10)=reinterpret_cast<U>(v[3])(d);*reinterpret_cast<unsigned*>(m_10+4)=reinterpret_cast<U>(v[3])(d);*reinterpret_cast<unsigned*>(m_10+8)=reinterpret_cast<U>(v[3])(d);reinterpret_cast<Bytes>(v[9])(d,FUN_1415f9fc0(&m_20),FUN_1415fa070(&m_20));*reinterpret_cast<unsigned*>(m_28)=reinterpret_cast<U>(v[3])(d);*reinterpret_cast<unsigned*>(m_28+4)=reinterpret_cast<U>(v[3])(d);reinterpret_cast<Bytes>(v[9])(d,FUN_1415f9f60(&m_30),FUN_1415fa040(&m_30));reinterpret_cast<Bytes>(v[9])(d,FUN_1415f9fe0(&m_38),FUN_1415fa080(&m_38));*reinterpret_cast<unsigned*>(m_40)=reinterpret_cast<U>(v[3])(d);FUN_1415fb750(d);return 1;}

// ---- client channel information -----------------------------------------------------------------------------------
extern void FUN_1415cb200(void*,void*,...);
// MS2-FUNCTIONAL 0x14157bce0: derives from channel info, initializes its two client fields and increments the kind byte.
// @0x14157bce0
CNMClientChannelInfo::CNMClientChannelInfo():CNMChannelInfo(),m_58(4),m_5c(0){++m_bKind;}
// MS2-FUNCTIONAL 0x14157bd40: copies base and client fields, then applies the derived-kind adjustment.
// @0x14157bd40
CNMClientChannelInfo::CNMClientChannelInfo(const CNMClientChannelInfo&r):CNMChannelInfo(r),m_58(r.m_58),m_5c(r.m_5c){++m_bKind;}
// MS2-FUNCTIONAL 0x14157be00: initializes the derived fields while copying the CNMChannelInfo base.
// @0x14157be00
CNMClientChannelInfo::CNMClientChannelInfo(const CNMChannelInfo&r):CNMChannelInfo(r),m_58(4),m_5c(0){++m_bKind;}
// MS2-FUNCTIONAL 0x14157bea0: delegates the remaining payload fields to the recovered helper.
// @0x14157bea0
CNMClientChannelInfo::CNMClientChannelInfo(const void*key,int a,int b):CNMChannelInfo(),m_58(0),m_5c(0){++m_bKind;FUN_1415cb200(const_cast<void*>(key),this,a,b,0xfffffffffffffffeULL);}
// MS2-FUNCTIONAL 0x14157bdb0: copies base channel fields and the two derived integers.
// @0x14157bdb0
long long FUN_14157bdb0(long long dst,long long src){auto*d=reinterpret_cast<CNMClientChannelInfo*>(dst);auto*r=reinterpret_cast<CNMClientChannelInfo*>(src);*static_cast<CNMChannelInfo*>(d)=*static_cast<CNMChannelInfo*>(r);d->m_58=r->m_58;d->m_5c=r->m_5c;return dst;}
// MS2-FUNCTIONAL 0x14157be70: copies the base channel-info portion to this object.
// @0x14157be70
void* FUN_14157be70(void*dst,const void*src){*static_cast<CNMChannelInfo*>(dst)=*static_cast<const CNMChannelInfo*>(src);return dst;}
// MS2-FUNCTIONAL 0x14157bf10: populates a client channel-info record through the helper used by the executable.
// @0x14157bf10
void* FUN_14157bf10(void*dst,const void*key){FUN_1415cb200(const_cast<void*>(key),dst);return dst;}
// MS2-FUNCTIONAL 0x14157bf40: frames client-channel encoding.
// @0x14157bf40
unsigned int CNMClientChannelInfo::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMClientChannelInfo*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157bfa0: selects the format-specific virtual encoder slot.
// @0x14157bfa0
unsigned int CNMClientChannelInfo::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMClientChannelInfo*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMClientChannelInfo*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157c000: encodes the base record followed by its two client fields.
// @0x14157c000
unsigned int CNMClientChannelInfo::Encode(CNMEncoder*e,CNMStream*s){CNMChannelInfo::EncodeDispatch(e,s);FUN_14156ac20(e,m_58);FUN_14156ac20(e,m_5c);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157c070: frames client-channel decoding.
// @0x14157c070
unsigned int CNMClientChannelInfo::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMClientChannelInfo*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157c100: selects framed or direct decode.
// @0x14157c100
unsigned int CNMClientChannelInfo::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMClientChannelInfo*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMClientChannelInfo*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157c160: decodes the base data then the two client words.
// @0x14157c160
unsigned int CNMClientChannelInfo::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMChannelInfo::DecodeDispatch(d,s);void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);m_58=reinterpret_cast<U>(v[3])(d);m_5c=reinterpret_cast<U>(v[3])(d);FUN_1415fb750(d);return 1;}

// ---- callback registration and server attach requests ------------------------------------------------------------
extern void FUN_14156ab90(void*,unsigned short); extern void FUN_14156ab00(void*,unsigned char); extern void FUN_1415fba60(void*,unsigned int,const void*);
// MS2-FUNCTIONAL 0x14157d800: initializes callback registration fields.
// @0x14157d800
CNMRegisterCallbackFunc::CNMRegisterCallbackFunc():CNMFunc(0x1002,1,0,0),m_30(0),m_38(0),m_3c(0){}
// MS2-FUNCTIONAL 0x14157d860: stores callback pointer and flags in the recovered layout.
// @0x14157d860
CNMRegisterCallbackFunc::CNMRegisterCallbackFunc(const void*pCallback,int flags):CNMFunc(0x1002,1,0,0),m_30(reinterpret_cast<long long>(pCallback)),m_38(flags),m_3c(0){}
// MS2-FUNCTIONAL 0x14157d8d0: frames callback registration.
// @0x14157d8d0
unsigned int CNMRegisterCallbackFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMRegisterCallbackFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157d930: dispatches callback encoding by format.
// @0x14157d930
unsigned int CNMRegisterCallbackFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMRegisterCallbackFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMRegisterCallbackFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157d990: writes callback identifier and flags in the request direction.
// @0x14157d990
unsigned int CNMRegisterCallbackFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,static_cast<unsigned>(m_30));FUN_14156ac20(e,m_38);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157da10: frames callback-registration decoding.
// @0x14157da10
unsigned int CNMRegisterCallbackFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMRegisterCallbackFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157daa0: dispatches callback decoding according to message format.
// @0x14157daa0
unsigned int CNMRegisterCallbackFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMRegisterCallbackFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMRegisterCallbackFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157db00: reads callback identifier and option word.
// @0x14157db00
unsigned int CNMRegisterCallbackFunc::Decode(CNMSerializableDecoder*d,CNMStream*){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);m_30=reinterpret_cast<U>(v[3])(d);m_38=reinterpret_cast<U>(v[3])(d);FUN_1415fb750(d);return 1;}
// MS2-FUNCTIONAL 0x14157db80: initializes callback reset data.
// @0x14157db80
CNMResetCallbackFunc::CNMResetCallbackFunc():CNMFunc(0x1003,1,0,0),m_30(0){}
// MS2-FUNCTIONAL 0x14157dbe0: stores the callback identifier.
// @0x14157dbe0
CNMResetCallbackFunc::CNMResetCallbackFunc(unsigned long long callback):CNMFunc(0x1003,1,0,0),m_30(callback){}
// MS2-FUNCTIONAL 0x14157dc40: frames callback reset encoding.
// @0x14157dc40
unsigned int CNMResetCallbackFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMResetCallbackFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157dca0: dispatches callback-reset encoding by format.
// @0x14157dca0
unsigned int CNMResetCallbackFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMResetCallbackFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMResetCallbackFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157dd00: sends the callback identifier when request direction is active.
// @0x14157dd00
unsigned int CNMResetCallbackFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this))FUN_14156ac20(e,static_cast<unsigned>(m_30));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157dd70: frames callback-reset decoding.
// @0x14157dd70
unsigned int CNMResetCallbackFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMResetCallbackFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157de00: dispatches callback-reset decoding according to format.
// @0x14157de00
unsigned int CNMResetCallbackFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMResetCallbackFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMResetCallbackFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157de60: restores callback identifier from the request decoder.
// @0x14157de60
unsigned int CNMResetCallbackFunc::Decode(CNMSerializableDecoder*d,CNMStream*){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);m_30=reinterpret_cast<U>(v[3])(d);FUN_1415fb750(d);return 1;}
// MS2-FUNCTIONAL 0x14157ded0: initializes attach request defaults.
// @0x14157ded0
CNMAttachToNMCOServerFunc::CNMAttachToNMCOServerFunc():CNMFunc(0x1004,1,0,0),m_30(0),m_34(0),m_38(0),m_3c(1),m_40(0),m_44(0){}
// MS2-FUNCTIONAL 0x14157df60: stores the five constructor arguments in their recovered fields.
// @0x14157df60
CNMAttachToNMCOServerFunc::CNMAttachToNMCOServerFunc(int a,int b,int c,int d,int e):CNMFunc(0x1004,1,0,0),m_30(a),m_34(b),m_38(c),m_3c(d),m_40(e),m_44(0){}
// MS2-FUNCTIONAL 0x14157dff0: frames attach-request encoding.
// @0x14157dff0
unsigned int CNMAttachToNMCOServerFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMAttachToNMCOServerFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157e050: dispatches attach-request encoding.
// @0x14157e050
unsigned int CNMAttachToNMCOServerFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMAttachToNMCOServerFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMAttachToNMCOServerFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157e0b0: writes five request integers.
// @0x14157e0b0
unsigned int CNMAttachToNMCOServerFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,m_30);FUN_14156ac20(e,m_34);FUN_14156ac20(e,m_38);FUN_14156ac20(e,m_3c);FUN_14156ac20(e,m_40);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157e160: frames attach-request decoding.
// @0x14157e160
unsigned int CNMAttachToNMCOServerFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMAttachToNMCOServerFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157e1f0: dispatches attach-request decoding.
// @0x14157e1f0
unsigned int CNMAttachToNMCOServerFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMAttachToNMCOServerFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMAttachToNMCOServerFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157e250: restores the five request integers.
// @0x14157e250
unsigned int CNMAttachToNMCOServerFunc::Decode(CNMSerializableDecoder*d,CNMStream*){if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);m_30=reinterpret_cast<U>(v[3])(d);m_34=reinterpret_cast<U>(v[3])(d);m_38=reinterpret_cast<U>(v[3])(d);m_3c=reinterpret_cast<U>(v[3])(d);m_40=reinterpret_cast<U>(v[3])(d);}FUN_1415fb750(d);return 1;}
// MS2-FUNCTIONAL 0x14157e320: initializes detach request fields.
// @0x14157e320
CNMDetachFromNMCOServerFunc::CNMDetachFromNMCOServerFunc():CNMFunc(0x1005,1,0,0),m_30(0),m_34(0){}
// MS2-FUNCTIONAL 0x14157e380: stores the detach request id.
// @0x14157e380
CNMDetachFromNMCOServerFunc::CNMDetachFromNMCOServerFunc(int id):CNMFunc(0x1005,1,0,0),m_30(id),m_34(0){}
// MS2-FUNCTIONAL 0x14157e3e0: frames detach-request encoding.
// @0x14157e3e0
unsigned int CNMDetachFromNMCOServerFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMDetachFromNMCOServerFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157e440: dispatches detach-request encoding.
// @0x14157e440
unsigned int CNMDetachFromNMCOServerFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMDetachFromNMCOServerFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMDetachFromNMCOServerFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157e4a0: sends the detach id in request direction.
// @0x14157e4a0
unsigned int CNMDetachFromNMCOServerFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this))FUN_14156ac20(e,m_30);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157e510: frames detach-request decoding.
// @0x14157e510
unsigned int CNMDetachFromNMCOServerFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMDetachFromNMCOServerFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157e5a0: dispatches detach-request decoding.
// @0x14157e5a0
unsigned int CNMDetachFromNMCOServerFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMDetachFromNMCOServerFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMDetachFromNMCOServerFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157e600: restores the detach id.
// @0x14157e600
unsigned int CNMDetachFromNMCOServerFunc::Decode(CNMSerializableDecoder*d,CNMStream*){if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);m_30=reinterpret_cast<U>(v[3])(d);}FUN_1415fb750(d);return 1;}
// MS2-FUNCTIONAL 0x14157ece0: initializes the game connection-config query with its embedded record.
// @0x14157ece0
CNMGetConnConfigFunc::CNMGetConnConfigFunc():CNMFunc(0x8012,1,0,0),m_30(){}
// MS2-FUNCTIONAL 0x14157ed50: frames connection-config query encoding.
// @0x14157ed50
unsigned int CNMGetConnConfigFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetConnConfigFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157edb0: dispatches connection-config query encoding.
// @0x14157edb0
unsigned int CNMGetConnConfigFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGetConnConfigFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGetConnConfigFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157ee10: serializes the embedded config when request direction is active.
// @0x14157ee10
unsigned int CNMGetConnConfigFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb720(this))m_30.EncodeFramed(s);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157ee90: frames connection-config response decoding.
// @0x14157ee90
unsigned int CNMGetConnConfigFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetConnConfigFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157ef20: dispatches connection-config decode.
// @0x14157ef20
unsigned int CNMGetConnConfigFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGetConnConfigFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGetConnConfigFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157ef80: decodes the embedded configuration payload when requested.
// @0x14157ef80
unsigned int CNMGetConnConfigFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb720(this))m_30.DecodeFramed(s);FUN_1415fb750(d);return 1;}
// MS2-FUNCTIONAL 0x14157f000: initializes the set-config request.
// @0x14157f000
CNMSetConnConfigFunc::CNMSetConnConfigFunc():CNMFunc(0x8013,1,0,0),m_30(){}
// MS2-FUNCTIONAL 0x14157f070: copies a supplied configuration into the set request.
// @0x14157f070
CNMSetConnConfigFunc::CNMSetConnConfigFunc(const CNMConnConfig&config):CNMFunc(0x8013,1,0,0),m_30(config){}
// MS2-FUNCTIONAL 0x14157f0e0: frames set-config encoding.
// @0x14157f0e0
unsigned int CNMSetConnConfigFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMSetConnConfigFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157f140: dispatches set-config encoding.
// @0x14157f140
unsigned int CNMSetConnConfigFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMSetConnConfigFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMSetConnConfigFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157f1a0: serializes the embedded connection configuration on requests.
// @0x14157f1a0
unsigned int CNMSetConnConfigFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb720(this))m_30.EncodeFramed(s);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157f220: frames set-config decoding.
// @0x14157f220
unsigned int CNMSetConnConfigFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMSetConnConfigFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157f2b0: dispatches set-config decoding.
// @0x14157f2b0
unsigned int CNMSetConnConfigFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMSetConnConfigFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMSetConnConfigFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157f310: decodes the embedded configuration from request messages.
// @0x14157f310
unsigned int CNMSetConnConfigFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb720(this))m_30.DecodeFramed(s);FUN_1415fb750(d);return 1;}
// MS2-FUNCTIONAL 0x14157e970: initializes an empty stand-alone message.
// @0x14157e970
CNMStartStandAloneMsgFunc::CNMStartStandAloneMsgFunc():CNMFunc(0x1007,1,0,0),m_30{}{}
// MS2-FUNCTIONAL 0x14157e9d0: stores a bounded stand-alone message string.
// @0x14157e9d0
CNMStartStandAloneMsgFunc::CNMStartStandAloneMsgFunc(const char*message):CNMFunc(0x1007,1,0,0),m_30{} {if(message)FUN_1415fba60(m_30,0x400,message);}
// MS2-FUNCTIONAL 0x14157ea40: frames stand-alone message encoding.
// @0x14157ea40
unsigned int CNMStartStandAloneMsgFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMStartStandAloneMsgFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14157eaa0: dispatches stand-alone message encoding.
// @0x14157eaa0
unsigned int CNMStartStandAloneMsgFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMStartStandAloneMsgFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMStartStandAloneMsgFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14157eb00: sends the message string in request direction.
// @0x14157eb00
unsigned int CNMStartStandAloneMsgFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this))FUN_14156ae30(e,m_30);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14157eb70: frames stand-alone message decoding.
// @0x14157eb70
unsigned int CNMStartStandAloneMsgFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMStartStandAloneMsgFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14157ec00: dispatches stand-alone message decoding.
// @0x14157ec00
unsigned int CNMStartStandAloneMsgFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMStartStandAloneMsgFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMStartStandAloneMsgFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14157ec60: reads the message string with its recovered capacity.
// @0x14157ec60
unsigned int CNMStartStandAloneMsgFunc::Decode(CNMSerializableDecoder*d,CNMStream*){if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using Bytes=void(__fastcall*)(void*,void*,unsigned);reinterpret_cast<Bytes>(v[9])(d,m_30,0x400);}FUN_1415fb750(d);return 1;}

// ---- CNMFunc base implementation ----------------------------------------------------------------------------------
// MS2-FUNCTIONAL 14157d4c0: initializes the base function id, byte format and trailer words as recovered.
// @0x14157d4c0
CNMFunc::CNMFunc(int id,int format,int n28,int n20):CNMSerializable(0x666f,1,static_cast<unsigned char>(format)),m_nFuncId(id),m_nDirection(0),m_n18(0),m_n1c(0),m_n20(n20),m_n24(0),m_n28(n28),m_n2c(0){}
// MS2-FUNCTIONAL 14157d570: frames the base function serializer.
// @0x14157d570
unsigned int CNMFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 14157d5d0: selects the function serializer slots based on its format.
// @0x14157d5d0
unsigned int CNMFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 14157d630: writes the outgoing or return trailer word selected by direction.
// @0x14157d630
unsigned int CNMFunc::Encode(CNMEncoder*e,CNMStream*s){EncodeDispatch(e,s);FUN_14156ac20(e,FUN_1415fb700(this)?static_cast<unsigned>(m_n28):static_cast<unsigned>(m_n2c));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 14157d6a0: frames base function decoding.
// @0x14157d6a0
unsigned int CNMFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 14157d730: selects the direct or framed decoder virtual slot.
// @0x14157d730
unsigned int CNMFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 14157d790: restores the direction-selected trailer word.
// @0x14157d790
unsigned int CNMFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);m_n28=reinterpret_cast<U>(v[3])(d);}else{void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);m_n2c=reinterpret_cast<U>(v[3])(d);}return static_cast<unsigned>(FUN_1415fb750(d));}

// ---- bring-forward stand-alone message request --------------------------------------------------------------------
// MS2-FUNCTIONAL 14157e670: initializes an empty request buffer.
// @0x14157e670
CNMBringForwardStandAloneMsgFunc::CNMBringForwardStandAloneMsgFunc():CNMFunc(0x1006,1,0,0),m_szName{} {m_szName[0]=0;}
// MS2-FUNCTIONAL 14157e6d0: constructs the parameterized request; the executable does not copy the supplied argument here.
// @0x14157e6d0
CNMBringForwardStandAloneMsgFunc::CNMBringForwardStandAloneMsgFunc(const char*):CNMFunc(0x1006,1,0,0),m_szName{}{}
// MS2-FUNCTIONAL 14157e720: frames the empty-payload request.
// @0x14157e720
unsigned int CNMBringForwardStandAloneMsgFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMBringForwardStandAloneMsgFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 14157e780: dispatches request encoding by message format.
// @0x14157e780
unsigned int CNMBringForwardStandAloneMsgFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMBringForwardStandAloneMsgFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMBringForwardStandAloneMsgFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 14157e7e0: completes the empty request after the base function framing path.
// @0x14157e7e0
unsigned int CNMBringForwardStandAloneMsgFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);FUN_1415fb700(this);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 14157e830: frames the empty-payload response.
// @0x14157e830
unsigned int CNMBringForwardStandAloneMsgFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMBringForwardStandAloneMsgFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 14157e8c0: dispatches response decoding by format.
// @0x14157e8c0
unsigned int CNMBringForwardStandAloneMsgFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMBringForwardStandAloneMsgFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMBringForwardStandAloneMsgFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 14157e920: consumes the empty response and decoder status.
// @0x14157e920
unsigned int CNMBringForwardStandAloneMsgFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);FUN_1415fb700(this);FUN_1415fb750(d);return 1;}
// MS2-PIN: ??0CNMConnConfig@@QEAA@XZ 0x14157adc0
// MS2-PIN: ??0CNMChannelInfo@@QEAA@XZ 0x14157b4b0
// MS2-PIN: ??0CNMChannelMessage@@QEAA@XZ 0x14157cc30
// MS2-PIN: ??0CNMRegisterCallbackFunc@@QEAA@XZ 0x14157d800
// MS2-PIN: ??0CNMResetCallbackFunc@@QEAA@XZ 0x14157db80
// MS2-PIN: ??0CNMAttachToNMCOServerFunc@@QEAA@XZ 0x14157ded0
// MS2-PIN: ??0CNMDetachFromNMCOServerFunc@@QEAA@XZ 0x14157e320
// MS2-PIN: ??0CNMBringForwardStandAloneMsgFunc@@QEAA@XZ 0x14157e670
// MS2-PIN: ??0CNMStartStandAloneMsgFunc@@QEAA@XZ 0x14157e970
// MS2-PIN: ??0CNMGetConnConfigFunc@@QEAA@XZ 0x14157ece0
// MS2-PIN: ??0CNMSetConnConfigFunc@@QEAA@XZ 0x14157f000
