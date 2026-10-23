// Nexon Messenger support-game-list request serialization.
// MS2-UNIT: unit_141593360
// MS2-RANGE: 0x141593360-0x1415937e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ab00(void*,unsigned char); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*); extern void FUN_1415e8200(void*); extern void FUN_141608e60(void*); extern void FUN_14160b330(void*,void*);
// MS2-FUNCTIONAL 0x141593360: initializes the support-game list with request mode one.
CNMGetSupportGameListFunc::CNMGetSupportGameListFunc():CNMFunc(0x800c,1,0,0),m_n30(1),m_n34(0),m_aGameCode(){FUN_1415e8200(&m_aGameCode);}
// MS2-FUNCTIONAL 0x1415933d0: stores the support-list request mode.
CNMGetSupportGameListFunc::CNMGetSupportGameListFunc(int mode):CNMFunc(0x800c,1,0,0),m_n30(mode),m_n34(0),m_aGameCode(){FUN_1415e8200(&m_aGameCode);}
// MS2-FUNCTIONAL 0x141593440: frames the support-game request.
unsigned int CNMGetSupportGameListFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetSupportGameListFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x1415934a0: dispatches encoding according to message format.
unsigned int CNMGetSupportGameListFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGetSupportGameListFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGetSupportGameListFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141593500: writes returned game codes or the response status.
unsigned int CNMGetSupportGameListFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this)){FUN_14156ac20(e,static_cast<unsigned int>(m_aGameCode.size()));for(auto&code:m_aGameCode)code.EncodeFramed(s);}else FUN_14156ab00(e,static_cast<unsigned char>(m_n30));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141593600: decodes a framed support-game-list response.
unsigned int CNMGetSupportGameListFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetSupportGameListFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141593690: dispatches decoding according to response format.
unsigned int CNMGetSupportGameListFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGetSupportGameListFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGetSupportGameListFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x1415936f0: restores each game code or the one-byte response status.
unsigned int CNMGetSupportGameListFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(!FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);unsigned count=reinterpret_cast<U>(v[3])(d);m_aGameCode.clear();for(unsigned i=0;i<count;++i){CNMGameCode code;code.DecodeFramed(s);FUN_14160b330(&m_aGameCode,&code);}}else{void**v=*reinterpret_cast<void***>(d);using U8=unsigned char(__fastcall*)(void*);m_n30=reinterpret_cast<U8>(v[1])(d);}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMGetSupportGameListFunc@@QEAA@XZ 0x141593360
// MS2-PIN: ??0CNMGetSupportGameListFunc@@QEAA@H@Z 0x1415933d0
// MS2-PIN: ?EncodeFramed@CNMGetSupportGameListFunc@@UEAAIPEAVCNMStream@@@Z 0x141593440
// MS2-PIN: ?EncodeDispatch@CNMGetSupportGameListFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415934a0
// MS2-PIN: ?Encode@CNMGetSupportGameListFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141593500
// MS2-PIN: ?DecodeFramed@CNMGetSupportGameListFunc@@UEAAIPEAVCNMStream@@@Z 0x141593600
// MS2-PIN: ?DecodeDispatch@CNMGetSupportGameListFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141593690
// MS2-PIN: ?Decode@CNMGetSupportGameListFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415936f0
