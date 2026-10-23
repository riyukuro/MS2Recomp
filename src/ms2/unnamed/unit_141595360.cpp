// Nexon Messenger session-value query serialization.
// MS2-UNIT: unit_141595360
// MS2-RANGE: 0x141595360-0x141595750 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*,const void*); extern void FUN_1415f9990(void*); extern void FUN_1415fbe70(void*,unsigned int,const void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141595360: initializes empty name and reply-value buffers.
CNMGetSessionValueFunc::CNMGetSessionValueFunc():CNMFunc(0x8007,1,0,0),m_szName{},m_szValue{}{}
// MS2-FUNCTIONAL 0x1415953d0: stores the bounded session name and clears the reply buffer.
CNMGetSessionValueFunc::CNMGetSessionValueFunc(const char*name):CNMFunc(0x8007,1,0,0),m_szName{},m_szValue{}{if(name)FUN_1415fbe70(m_szName,0x20,name);}
// MS2-FUNCTIONAL 0x141595470: frames the session-value query.
unsigned int CNMGetSessionValueFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetSessionValueFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x1415954d0: dispatches encoding by message format.
unsigned int CNMGetSessionValueFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGetSessionValueFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGetSessionValueFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141595530: sends name in requests and the value in replies.
unsigned int CNMGetSessionValueFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);FUN_14156ae30(e,FUN_1415fb700(this)?m_szName:m_szValue);FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x1415955b0: decodes a framed session-value message.
unsigned int CNMGetSessionValueFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetSessionValueFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141595640: dispatches decoding by message format.
unsigned int CNMGetSessionValueFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGetSessionValueFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGetSessionValueFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x1415956a0: reads the reply value or request name, bounded to the field size.
unsigned int CNMGetSessionValueFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);void**v=*reinterpret_cast<void***>(d);using F=void(__fastcall*)(void*,void*,unsigned int);reinterpret_cast<F>(v[9])(d,FUN_1415fb700(this)?m_szName:m_szValue,FUN_1415fb700(this)?0x20:0x100);FUN_1415fb750(d);return 1;}
// MS2-PIN: ??0CNMGetSessionValueFunc@@QEAA@XZ 0x141595360
// MS2-PIN: ??0CNMGetSessionValueFunc@@QEAA@PEBD@Z 0x1415953d0
// MS2-PIN: ?EncodeFramed@CNMGetSessionValueFunc@@UEAAIPEAVCNMStream@@@Z 0x141595470
// MS2-PIN: ?EncodeDispatch@CNMGetSessionValueFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415954d0
// MS2-PIN: ?Encode@CNMGetSessionValueFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141595530
// MS2-PIN: ?DecodeFramed@CNMGetSessionValueFunc@@UEAAIPEAVCNMStream@@@Z 0x1415955b0
// MS2-PIN: ?DecodeDispatch@CNMGetSessionValueFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141595640
// MS2-PIN: ?Decode@CNMGetSessionValueFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415956a0
