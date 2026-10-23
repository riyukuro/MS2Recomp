// Nexon Messenger session-value request serialization.
// MS2-UNIT: unit_141594ea0
// MS2-RANGE: 0x141594ea0-0x141595360 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*,const void*); extern void FUN_14156ab00(void*,unsigned char); extern void FUN_14156ac20(void*,unsigned int); extern void FUN_1415f9990(void*); extern void FUN_1415fbe70(void*,unsigned int,const void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141594ea0: initializes empty session-value fields and default option one.
CNMSetSessionValueFunc::CNMSetSessionValueFunc():CNMFunc(0x8006,1,0,0),m_szName{},m_szValue{},m_n150(1),m_n154(0){}
// MS2-FUNCTIONAL 0x141594f30: copies bounded name/value strings and stores the option.
CNMSetSessionValueFunc::CNMSetSessionValueFunc(const char*name,const char*value,int option):CNMFunc(0x8006,1,0,0),m_szName{},m_szValue{},m_n150(option),m_n154(0){if(name)FUN_1415fbe70(m_szName,0x20,name);if(value)FUN_1415fbe70(m_szValue,0x100,value);}
// MS2-FUNCTIONAL 0x141595020: frames the session-value request.
unsigned int CNMSetSessionValueFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMSetSessionValueFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141595080: dispatches encoding by message format.
unsigned int CNMSetSessionValueFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMSetSessionValueFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMSetSessionValueFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x1415950e0: writes fields for the request message; replies contain only the frame.
unsigned int CNMSetSessionValueFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ae30(e,m_szName);FUN_14156ae30(e,m_szValue);FUN_14156ab00(e,static_cast<unsigned char>(m_n150));FUN_14156ac20(e,static_cast<unsigned int>(m_n154));}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141595190: decodes a framed session-value message.
unsigned int CNMSetSessionValueFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMSetSessionValueFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141595220: dispatches decoding by message format.
unsigned int CNMSetSessionValueFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMSetSessionValueFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMSetSessionValueFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141595280: reads name, value, option byte and trailing integer on requests.
unsigned int CNMSetSessionValueFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using Str=void(__fastcall*)(void*,void*,unsigned int);reinterpret_cast<Str>(v[9])(d,m_szName,0x20);reinterpret_cast<Str>(v[9])(d,m_szValue,0x100);using Byte=unsigned char(__fastcall*)(void*);m_n150=reinterpret_cast<Byte>(v[1])(d);using Int=unsigned(__fastcall*)(void*);m_n154=static_cast<int>(reinterpret_cast<Int>(v[3])(d));}FUN_1415fb750(d);return 1;}
// MS2-PIN: ??0CNMSetSessionValueFunc@@QEAA@XZ 0x141594ea0
// MS2-PIN: ??0CNMSetSessionValueFunc@@QEAA@PEBD0H@Z 0x141594f30
// MS2-PIN: ?EncodeFramed@CNMSetSessionValueFunc@@UEAAIPEAVCNMStream@@@Z 0x141595020
// MS2-PIN: ?EncodeDispatch@CNMSetSessionValueFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141595080
// MS2-PIN: ?Encode@CNMSetSessionValueFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415950e0
// MS2-PIN: ?DecodeFramed@CNMSetSessionValueFunc@@UEAAIPEAVCNMStream@@@Z 0x141595190
// MS2-PIN: ?DecodeDispatch@CNMSetSessionValueFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141595220
// MS2-PIN: ?Decode@CNMSetSessionValueFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141595280
