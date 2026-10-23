// Nexon Messenger restricted-words request serialization.
// MS2-UNIT: unit_14158ff90
// MS2-RANGE: 0x14158ff90-0x141590470 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ae30(void*,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
extern void* FUN_1415e5b60(void*); extern void FUN_1415e5b20(void*,const void*); extern void* FUN_1415f39e0(void*);
extern unsigned int FUN_1415fa080(void*); extern void* FUN_1415f9fe0(void*);
// The owning string-template unit is still partial; supply its recovered specialization for this request.
template<> CNMStr<0x400>::CNMStr() : m_p(nullptr) { FUN_1415e5b60(this); }
// MS2-FUNCTIONAL 0x14158ff90: initializes restriction mode and its fixed string.
CNMRestrictedWordsFunc::CNMRestrictedWordsFunc():CNMFunc(0x8018,1,0,0),m_30(1),m_34(0),m_38(),m_40(0),m_44(0){FUN_1415e5b60(&m_38);}
// MS2-FUNCTIONAL 0x141590020: stores restriction mode, category, and supplied words.
CNMRestrictedWordsFunc::CNMRestrictedWordsFunc(int mode,int category,const char* words):CNMFunc(0x8018,1,0,0),m_30(mode),m_34(category),m_38(),m_40(0),m_44(0){FUN_1415e5b60(&m_38);FUN_1415e5b20(&m_38,words);}
// MS2-FUNCTIONAL 0x1415900c0: frames the restricted-words request.
unsigned int CNMRestrictedWordsFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMRestrictedWordsFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141590120: dispatches encoding according to message format.
unsigned int CNMRestrictedWordsFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMRestrictedWordsFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMRestrictedWordsFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141590180: encodes a query or the returned restriction records.
unsigned int CNMRestrictedWordsFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this)){FUN_14156ac20(e,static_cast<unsigned int>(m_40));if(m_30==2)FUN_14156ae30(e,FUN_1415f39e0(&m_38));}else{FUN_14156ac20(e,static_cast<unsigned int>(m_30));FUN_14156ac20(e,static_cast<unsigned int>(m_34));FUN_14156ae30(e,FUN_1415f39e0(&m_38));}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141590250: decodes a framed restricted-words response.
unsigned int CNMRestrictedWordsFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMRestrictedWordsFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x1415902e0: dispatches decoding according to response format.
unsigned int CNMRestrictedWordsFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMRestrictedWordsFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMRestrictedWordsFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141590340: reads the request result and optional word string.
unsigned int CNMRestrictedWordsFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(!FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);using B=void(__fastcall*)(void*,void*,unsigned);m_40=static_cast<int>(reinterpret_cast<U>(v[3])(d));if(m_30==2)reinterpret_cast<B>(v[9])(d,FUN_1415f9fe0(&m_38),FUN_1415fa080(&m_38));}else{void**v=*reinterpret_cast<void***>(d);using U=unsigned(__fastcall*)(void*);using B=void(__fastcall*)(void*,void*,unsigned);m_30=static_cast<int>(reinterpret_cast<U>(v[3])(d));m_34=static_cast<int>(reinterpret_cast<U>(v[3])(d));reinterpret_cast<B>(v[9])(d,FUN_1415f9fe0(&m_38),FUN_1415fa080(&m_38));}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMRestrictedWordsFunc@@QEAA@XZ 0x14158ff90
// MS2-PIN: ??0CNMRestrictedWordsFunc@@QEAA@HHPEBD@Z 0x141590020
// MS2-PIN: ?EncodeFramed@CNMRestrictedWordsFunc@@UEAAIPEAVCNMStream@@@Z 0x1415900c0
// MS2-PIN: ?EncodeDispatch@CNMRestrictedWordsFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141590120
// MS2-PIN: ?Encode@CNMRestrictedWordsFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141590180
// MS2-PIN: ?DecodeFramed@CNMRestrictedWordsFunc@@UEAAIPEAVCNMStream@@@Z 0x141590250
// MS2-PIN: ?DecodeDispatch@CNMRestrictedWordsFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415902e0
// MS2-PIN: ?Decode@CNMRestrictedWordsFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141590340
