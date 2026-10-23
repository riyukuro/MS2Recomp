// Nexon Messenger get hardware ID request serialization.
// MS2-UNIT: unit_1415856c0
// MS2-RANGE: 0x1415856c0-0x1415859f0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*,const void*); extern void FUN_1415f9990(void*);
extern void* FUN_1415f39d0(void*); extern unsigned int FUN_1415fa070(void*); extern void* FUN_1415f9fc0(void*);
extern int FUN_1415fb720(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x1415856c0: initializes the request and empty hardware ID string.
// @0x1415856c0
CNMGetNxHWIDFunc::CNMGetNxHWIDFunc() : CNMFunc(0x2107,1,0,0), m_30() {}
// MS2-FUNCTIONAL 0x141585730: frames the request and dispatches its encoder slot.
// @0x141585730
unsigned int CNMGetNxHWIDFunc::EncodeFramed(CNMStream* s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetNxHWIDFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141585790: selects raw or framed encoding by format.
// @0x141585790
unsigned int CNMGetNxHWIDFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGetNxHWIDFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGetNxHWIDFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x1415857f0: encodes the hardware ID string.
// @0x1415857f0
unsigned int CNMGetNxHWIDFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb720(this))FUN_14156ae30(e,FUN_1415f39d0(&m_30));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141585860: decodes through a temporary framed decoder.
// @0x141585860
unsigned int CNMGetNxHWIDFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetNxHWIDFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x1415858f0: selects framed decoding for wire format 2.
// @0x1415858f0
unsigned int CNMGetNxHWIDFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGetNxHWIDFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGetNxHWIDFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141585950: restores the hardware ID string.
// @0x141585950
unsigned int CNMGetNxHWIDFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb720(this)){void**v=*reinterpret_cast<void***>(d);using F=unsigned int(__fastcall*)(void*,void*,unsigned int);reinterpret_cast<F>(v[9])(d,FUN_1415f9fc0(&m_30),FUN_1415fa070(&m_30));}return static_cast<unsigned int>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMGetNxHWIDFunc@@QEAA@XZ 0x1415856c0
