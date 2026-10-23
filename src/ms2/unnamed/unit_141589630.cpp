// Nexon Messenger change-category-name request serialization.
// MS2-UNIT: unit_141589630
// MS2-RANGE: 0x141589630-0x141589a40 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*);extern void FUN_14156bd50(void*);extern void FUN_14156be10(void*,void*,void*);extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int);extern void FUN_14156ae30(void*,const void*);extern void FUN_14156ab00(void*,unsigned int);extern void FUN_1415f9990(void*);extern void FUN_1415fbe70(void*,unsigned int,const void*);
extern int FUN_1415fb700(void*);extern int FUN_1415fb750(void*);extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141589630: initializes empty category-name fields.
// @0x141589630
CNMChangeCategoryNameFunc::CNMChangeCategoryNameFunc():CNMFunc(0x4103,1,0,0),m_30(0),m_34{},m_54(0){}
// MS2-FUNCTIONAL 0x1415896a0: stores category, optional name and flag.
// @0x1415896a0
CNMChangeCategoryNameFunc::CNMChangeCategoryNameFunc(int category,long long name,int flag):CNMFunc(0x4103,1,0,0),m_30(category),m_34{},m_54(flag){if(name)FUN_1415fbe70(m_34,0x20,reinterpret_cast<const void*>(name));}
// MS2-FUNCTIONAL 0x141589750: frames request and dispatches encoder slot.
// @0x141589750
unsigned int CNMChangeCategoryNameFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChangeCategoryNameFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x1415897b0: selects raw or framed encoding by format.
// @0x1415897b0
unsigned int CNMChangeCategoryNameFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMChangeCategoryNameFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMChangeCategoryNameFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141589810: serializes category, name and flag.
// @0x141589810
unsigned int CNMChangeCategoryNameFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,m_30);FUN_14156ae30(e,m_34);FUN_14156ab00(e,static_cast<unsigned char>(m_54));}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x1415898a0: decodes through a temporary framed decoder.
// @0x1415898a0
unsigned int CNMChangeCategoryNameFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChangeCategoryNameFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141589930: selects framed decoding for wire format 2.
// @0x141589930
unsigned int CNMChangeCategoryNameFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMChangeCategoryNameFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMChangeCategoryNameFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141589990: restores category, name and flag.
// @0x141589990
unsigned int CNMChangeCategoryNameFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U32=unsigned int(__fastcall*)(void*);using U8=unsigned char(__fastcall*)(void*);using B=unsigned int(__fastcall*)(void*,void*,unsigned int);m_30=static_cast<int>(reinterpret_cast<U32>(v[3])(d));reinterpret_cast<B>(v[9])(d,m_34,0x20);m_54=static_cast<int>(reinterpret_cast<U8>(v[1])(d));}return static_cast<unsigned int>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMChangeCategoryNameFunc@@QEAA@XZ 0x141589630
