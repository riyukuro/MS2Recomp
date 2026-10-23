// Nexon Messenger add-category request serialization.
// MS2-UNIT: unit_141588e20
// MS2-RANGE: 0x141588e20-0x1415892b0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*);extern void FUN_14156bd50(void*);extern void FUN_14156be10(void*,void*,void*);extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int);extern void FUN_14156ae30(void*,const void*);extern void FUN_1415f9990(void*);extern void FUN_1415fbe70(void*,unsigned int,const void*);
extern int FUN_1415fb700(void*);extern int FUN_1415fb750(void*);extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141588e20: initializes an empty category with default status.
// @0x141588e20
CNMAddCategoryFunc::CNMAddCategoryFunc():CNMFunc(0x4101,1,0,0),m_30{},m_38{},m_58(0),m_5c(1){}
// MS2-FUNCTIONAL 0x141588eb0: stores category key, optional name, flags and status.
// @0x141588eb0
CNMAddCategoryFunc::CNMAddCategoryFunc(long long key,long long name,int flags,int status):CNMFunc(0x4101,1,0,0),m_30{static_cast<unsigned int>(key),static_cast<unsigned int>(static_cast<unsigned long long>(key)>>32)},m_38{},m_58(flags),m_5c(status){if(name)FUN_1415fbe70(m_38,0x20,reinterpret_cast<const void*>(name));}
// MS2-FUNCTIONAL 0x141588f70: frames request and dispatches encoder slot.
// @0x141588f70
unsigned int CNMAddCategoryFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMAddCategoryFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141588fd0: selects raw or framed encoding by format.
// @0x141588fd0
unsigned int CNMAddCategoryFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMAddCategoryFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMAddCategoryFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141589030: serializes category key, name, flags and status.
// @0x141589030
unsigned int CNMAddCategoryFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,m_30.nLow);FUN_14156ac20(e,m_30.nHigh);FUN_14156ae30(e,m_38);FUN_14156ac20(e,m_58);FUN_14156ac20(e,m_5c);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x1415890e0: decodes through a temporary framed decoder.
// @0x1415890e0
unsigned int CNMAddCategoryFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMAddCategoryFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141589170: selects framed decoding for wire format 2.
// @0x141589170
unsigned int CNMAddCategoryFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMAddCategoryFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMAddCategoryFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x1415891d0: restores category key, name, flags and status.
// @0x1415891d0
unsigned int CNMAddCategoryFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U32=unsigned int(__fastcall*)(void*);using B=unsigned int(__fastcall*)(void*,void*,unsigned int);m_30.nLow=reinterpret_cast<U32>(v[3])(d);m_30.nHigh=reinterpret_cast<U32>(v[3])(d);reinterpret_cast<B>(v[9])(d,m_38,0x20);m_58=static_cast<int>(reinterpret_cast<U32>(v[3])(d));m_5c=static_cast<int>(reinterpret_cast<U32>(v[3])(d));}return static_cast<unsigned int>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMAddCategoryFunc@@QEAA@XZ 0x141588e20
