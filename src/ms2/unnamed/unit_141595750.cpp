// Nexon Messenger game-list request serialization.
// MS2-UNIT: unit_141595750
// MS2-RANGE: 0x141595750-0x141595a70 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb720(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141595750: initializes the embedded game-list response.
CNMGetGameListFunc::CNMGetGameListFunc():CNMFunc(0x8008,1,0,0),m_30(){}
// MS2-FUNCTIONAL 0x1415957c0: frames the game-list request.
unsigned int CNMGetGameListFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetGameListFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141595820: dispatches encoding by message format.
unsigned int CNMGetGameListFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGetGameListFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGetGameListFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141595880: serializes the embedded game list for requests.
unsigned int CNMGetGameListFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb720(this))m_30.EncodeFramed(s);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141595900: decodes a framed game-list message.
unsigned int CNMGetGameListFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetGameListFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141595990: dispatches decoding by message format.
unsigned int CNMGetGameListFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGetGameListFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGetGameListFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x1415959f0: restores the embedded game list for requests.
unsigned int CNMGetGameListFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb720(this))m_30.DecodeFramed(s);FUN_1415fb750(d);return 1;}
// MS2-PIN: ??0CNMGetGameListFunc@@QEAA@XZ 0x141595750
// MS2-PIN: ?EncodeFramed@CNMGetGameListFunc@@UEAAIPEAVCNMStream@@@Z 0x1415957c0
// MS2-PIN: ?EncodeDispatch@CNMGetGameListFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141595820
// MS2-PIN: ?Encode@CNMGetGameListFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141595880
// MS2-PIN: ?DecodeFramed@CNMGetGameListFunc@@UEAAIPEAVCNMStream@@@Z 0x141595900
// MS2-PIN: ?DecodeDispatch@CNMGetGameListFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141595990
// MS2-PIN: ?Decode@CNMGetGameListFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415959f0
