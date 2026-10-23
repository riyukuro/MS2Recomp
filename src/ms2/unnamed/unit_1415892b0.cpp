// Nexon Messenger delete-category request serialization.
// MS2-UNIT: unit_1415892b0
// MS2-RANGE: 0x1415892b0-0x141589630 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*);extern void FUN_14156bd50(void*);extern void FUN_14156be10(void*,void*,void*);extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int);extern void FUN_14156ab00(void*,unsigned int);extern void FUN_1415f9990(void*);extern int FUN_1415fb700(void*);extern int FUN_1415fb750(void*);extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x1415892b0: initializes empty category and flag fields.
// @0x1415892b0
CNMDeleteCategoryFunc::CNMDeleteCategoryFunc():CNMFunc(0x4102,1,0,0),m_30(0),m_34(0){}
// MS2-FUNCTIONAL 0x141589310: stores category and flag.
// @0x141589310
CNMDeleteCategoryFunc::CNMDeleteCategoryFunc(int category,int flag):CNMFunc(0x4102,1,0,0),m_30(category),m_34(flag){}
// MS2-FUNCTIONAL 0x141589380: frames request and dispatches encoder slot.
// @0x141589380
unsigned int CNMDeleteCategoryFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMDeleteCategoryFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x1415893e0: selects raw or framed encoding by format.
// @0x1415893e0
unsigned int CNMDeleteCategoryFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMDeleteCategoryFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMDeleteCategoryFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141589440: serializes category and one-byte flag.
// @0x141589440
unsigned int CNMDeleteCategoryFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,m_30);FUN_14156ab00(e,static_cast<unsigned char>(m_34));}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x1415894c0: decodes through a temporary framed decoder.
// @0x1415894c0
unsigned int CNMDeleteCategoryFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMDeleteCategoryFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141589550: selects framed decoding for wire format 2.
// @0x141589550
unsigned int CNMDeleteCategoryFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMDeleteCategoryFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMDeleteCategoryFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x1415895b0: restores category and one-byte flag.
// @0x1415895b0
unsigned int CNMDeleteCategoryFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U32=unsigned int(__fastcall*)(void*);using U8=unsigned char(__fastcall*)(void*);m_30=static_cast<int>(reinterpret_cast<U32>(v[3])(d));m_34=static_cast<int>(reinterpret_cast<U8>(v[1])(d));}return static_cast<unsigned int>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMDeleteCategoryFunc@@QEAA@XZ 0x1415892b0
