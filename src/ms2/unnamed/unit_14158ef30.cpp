// Nexon Messenger execute-NGM-launcher request serialization.
// MS2-UNIT: unit_14158ef30
// MS2-RANGE: 0x14158ef30-0x14158f620 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*, void*, void*); extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*, const void*); extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415fbe70(void*, unsigned int, const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x14158ef30: initializes an empty launcher request.
CNMExecuteNGMLauncherFunc::CNMExecuteNGMLauncherFunc()
 : CNMFunc(0x8016,1,0,0),m_nGameCode(0),m_n34(0),m_sz38{},m_n438(1),m_sz43c{},m_n83c(0),m_sz840{},m_sz848{},m_n8c8(0),m_n8cc(0){}
// MS2-FUNCTIONAL 0x14158f010: stores NGM launcher parameters in bounded fields.
CNMExecuteNGMLauncherFunc::CNMExecuteNGMLauncherFunc(int gameCode,int n2,const char* sz3,int n4,const char* sz5,int n6,const char* sz7,const char* sz8,int n9)
 : CNMFunc(0x8016,1,0,0),m_nGameCode(gameCode),m_n34(n2),m_sz38{},m_n438(n4),m_sz43c{},m_n83c(n6),m_sz840{},m_sz848{},m_n8c8(n9),m_n8cc(0)
{ if(sz3)FUN_1415fbe70(m_sz38,0x400,sz3); if(sz5)FUN_1415fbe70(m_sz43c,0x400,sz5); if(sz7)FUN_1415fbe70(m_sz840,8,sz7); if(sz8)FUN_1415fbe70(m_sz848,0x80,sz8); }
// MS2-FUNCTIONAL 0x14158f1c0: frames the launcher request.
unsigned int CNMExecuteNGMLauncherFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMExecuteNGMLauncherFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14158f220: dispatches encoding according to wire format.
unsigned int CNMExecuteNGMLauncherFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMExecuteNGMLauncherFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMExecuteNGMLauncherFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14158f280: serializes launcher values.
unsigned int CNMExecuteNGMLauncherFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,m_nGameCode);FUN_14156ac20(e,m_n34);FUN_14156ae30(e,m_sz38);FUN_14156ac20(e,m_n438);FUN_14156ae30(e,m_sz43c);FUN_14156ac20(e,m_n83c);FUN_14156ae30(e,m_sz840);FUN_14156ae30(e,m_sz848);FUN_14156ac20(e,m_n8c8);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14158f3a0: decodes a framed launcher response.
unsigned int CNMExecuteNGMLauncherFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMExecuteNGMLauncherFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14158f430: dispatches decoding according to response format.
unsigned int CNMExecuteNGMLauncherFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMExecuteNGMLauncherFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMExecuteNGMLauncherFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14158f490: restores launcher values from the reply.
unsigned int CNMExecuteNGMLauncherFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using B=void(__fastcall*)(void*,void*,unsigned);using U=unsigned(__fastcall*)(void*);m_nGameCode=static_cast<int>(reinterpret_cast<U>(v[3])(d));m_n34=static_cast<int>(reinterpret_cast<U>(v[3])(d));reinterpret_cast<B>(v[9])(d,m_sz38,0x400);m_n438=static_cast<int>(reinterpret_cast<U>(v[3])(d));reinterpret_cast<B>(v[9])(d,m_sz43c,0x400);m_n83c=static_cast<int>(reinterpret_cast<U>(v[3])(d));reinterpret_cast<B>(v[9])(d,m_sz840,8);reinterpret_cast<B>(v[9])(d,m_sz848,0x80);m_n8c8=static_cast<int>(reinterpret_cast<U>(v[3])(d));}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMExecuteNGMLauncherFunc@@QEAA@XZ 0x14158ef30
// MS2-PIN: ??0CNMExecuteNGMLauncherFunc@@QEAA@HHPEBDH0H00H@Z 0x14158f010
// MS2-PIN: ?EncodeFramed@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158f1c0
// MS2-PIN: ?EncodeDispatch@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158f220
// MS2-PIN: ?Encode@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158f280
// MS2-PIN: ?DecodeFramed@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158f3a0
// MS2-PIN: ?DecodeDispatch@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158f430
// MS2-PIN: ?Decode@CNMExecuteNGMLauncherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158f490
