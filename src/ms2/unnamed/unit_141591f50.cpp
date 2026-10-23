// Nexon Messenger extended URL query serialization.
// MS2-UNIT: unit_141591f50
// MS2-RANGE: 0x141591f50-0x141592580 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156acb0(void*,unsigned __int64); extern void FUN_14156ab00(void*,unsigned char); extern void FUN_14156ae30(void*,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141591f50: initializes URL type one and clears all query/result fields.
CNMGetUrlExFunc::CNMGetUrlExFunc():CNMFunc(0x8009,1,0,0),m_nUrlType(1),m_nGameCode(0),m_n38(0),m_n3c(0),m_n40(0),m_sz48{},m_n248(0),m_sz24c{},m_n34c(0),m_n350(0),m_n354(0),m_n358(0x10000),m_szUrl{}{}
// MS2-FUNCTIONAL 0x141592050: frames an extended URL request.
unsigned int CNMGetUrlExFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetUrlExFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x1415920b0: dispatches encoding according to message format.
unsigned int CNMGetUrlExFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGetUrlExFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGetUrlExFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141592110: encodes the selected URL query and the returned URL/settings.
unsigned int CNMGetUrlExFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this))FUN_14156ae30(e,m_szUrl);else{FUN_14156ac20(e,m_nUrlType);if(m_nUrlType==1)FUN_14156ac20(e,m_nGameCode);if(m_nUrlType==2)FUN_14156ac20(e,m_n38);if(m_nUrlType==3)FUN_14156acb0(e,m_n40);if(m_nUrlType==4)FUN_14156ae30(e,m_sz48);FUN_14156ac20(e,m_n248);FUN_14156ae30(e,m_sz24c);FUN_14156ab00(e,static_cast<unsigned char>(m_n34c));FUN_14156ab00(e,static_cast<unsigned char>(m_n350));FUN_14156ab00(e,static_cast<unsigned char>(m_n354));FUN_14156ac20(e,m_n358);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141592290: decodes a framed extended URL response.
unsigned int CNMGetUrlExFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetUrlExFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141592320: dispatches decoding according to response format.
unsigned int CNMGetUrlExFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGetUrlExFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGetUrlExFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141592380: restores the selected URL query fields and response URL.
unsigned int CNMGetUrlExFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);using U64=unsigned __int64(__fastcall*)(void*);using U8=unsigned char(__fastcall*)(void*);using B=void(__fastcall*)(void*,void*,unsigned);if(!FUN_1415fb700(this))reinterpret_cast<B>(v[9])(d,m_szUrl,0x400);else{m_nUrlType=static_cast<int>(reinterpret_cast<U>(v[3])(d));if(m_nUrlType==1)m_nGameCode=static_cast<int>(reinterpret_cast<U>(v[3])(d));if(m_nUrlType==2)m_n38=static_cast<int>(reinterpret_cast<U>(v[3])(d));if(m_nUrlType==3)m_n40=reinterpret_cast<U64>(v[4])(d);if(m_nUrlType==4)reinterpret_cast<B>(v[9])(d,m_sz48,0x200);m_n248=static_cast<int>(reinterpret_cast<U>(v[3])(d));reinterpret_cast<B>(v[9])(d,m_sz24c,0x100);m_n34c=reinterpret_cast<U8>(v[1])(d);m_n350=reinterpret_cast<U8>(v[1])(d);m_n354=reinterpret_cast<U8>(v[1])(d);m_n358=static_cast<int>(reinterpret_cast<U>(v[3])(d));}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMGetUrlExFunc@@QEAA@XZ 0x141591f50
// MS2-PIN: ?EncodeFramed@CNMGetUrlExFunc@@UEAAIPEAVCNMStream@@@Z 0x141592050
// MS2-PIN: ?EncodeDispatch@CNMGetUrlExFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415920b0
// MS2-PIN: ?Encode@CNMGetUrlExFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141592110
// MS2-PIN: ?DecodeFramed@CNMGetUrlExFunc@@UEAAIPEAVCNMStream@@@Z 0x141592290
// MS2-PIN: ?DecodeDispatch@CNMGetUrlExFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141592320
// MS2-PIN: ?Decode@CNMGetUrlExFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141592380
