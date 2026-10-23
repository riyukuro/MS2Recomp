// Nexon Messenger game short-name request serialization.
// MS2-UNIT: unit_141594000
// MS2-RANGE: 0x141594000-0x1415943a0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ae30(void*,void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141594000: initializes the request and empty reply buffer.
CNMGetGameShortNameFunc::CNMGetGameShortNameFunc():CNMFunc(0x800f,1,0,0),m_nGameCode(0),m_szName{}{}
// MS2-FUNCTIONAL 0x141594070: stores the requested game code and clears the reply buffer.
CNMGetGameShortNameFunc::CNMGetGameShortNameFunc(int code):CNMFunc(0x800f,1,0,0),m_nGameCode(code),m_szName{}{}
// MS2-FUNCTIONAL 0x1415940E0: frames the short-name request.
unsigned int CNMGetGameShortNameFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetGameShortNameFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141594140: dispatches encoding according to message format.
unsigned int CNMGetGameShortNameFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGetGameShortNameFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGetGameShortNameFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x1415941A0: writes the name on replies and the game code on requests.
unsigned int CNMGetGameShortNameFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this))FUN_14156ae30(e,m_szName);else FUN_14156ac20(e,static_cast<unsigned int>(m_nGameCode));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141594220: decodes a framed full-name response.
unsigned int CNMGetGameShortNameFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetGameShortNameFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x1415942B0: dispatches decoding according to response format.
unsigned int CNMGetGameShortNameFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGetGameShortNameFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGetGameShortNameFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141594310: reads the 0x420-byte short name on replies, or game code on requests.
unsigned int CNMGetGameShortNameFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(!FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using F=void(__fastcall*)(void*,void*,unsigned int);reinterpret_cast<F>(v[9])(d,m_szName,0x80);}else{void**v=*reinterpret_cast<void***>(d);using F=unsigned(__fastcall*)(void*);m_nGameCode=static_cast<int>(reinterpret_cast<F>(v[3])(d));}FUN_1415fb750(d);return 1;}
// MS2-PIN: ??0CNMGetGameShortNameFunc@@QEAA@XZ 0x141594000
// MS2-PIN: ??0CNMGetGameShortNameFunc@@QEAA@H@Z 0x141594070
// MS2-PIN: ?EncodeFramed@CNMGetGameShortNameFunc@@UEAAIPEAVCNMStream@@@Z 0x1415940E0
// MS2-PIN: ?EncodeDispatch@CNMGetGameShortNameFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141594140
// MS2-PIN: ?Encode@CNMGetGameShortNameFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415941A0
// MS2-PIN: ?DecodeFramed@CNMGetGameShortNameFunc@@UEAAIPEAVCNMStream@@@Z 0x141594220
// MS2-PIN: ?DecodeDispatch@CNMGetGameShortNameFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415942B0
// MS2-PIN: ?Decode@CNMGetGameShortNameFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141594310
