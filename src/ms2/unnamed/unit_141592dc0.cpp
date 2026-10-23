// Nexon Messenger upload-file request serialization.
// MS2-UNIT: unit_141592dc0
// MS2-RANGE: 0x141592dc0-0x141593360 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*,const void*); extern void FUN_14156ab00(void*,unsigned char); extern void FUN_1415fbe70(void*,unsigned int,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141592dc0: initializes upload fields and an empty result.
CNMUploadFileFunc::CNMUploadFileFunc():CNMFunc(0x800b,1,0,0),m_szUrl{},m_sz430{},m_sz530{},m_n630(0),m_szResult{}{}
// MS2-FUNCTIONAL 0x141592e70: stores bounded upload parameters and the requested option.
CNMUploadFileFunc::CNMUploadFileFunc(const char*url,const char*a,const char*b,int option):CNMFunc(0x800b,1,0,0),m_szUrl{},m_sz430{},m_sz530{},m_n630(option),m_szResult{}{if(url)FUN_1415fbe70(m_szUrl,0x400,url);if(a)FUN_1415fbe70(m_sz430,0x100,a);if(b)FUN_1415fbe70(m_sz530,0x100,b);}
// MS2-FUNCTIONAL 0x141592fb0: frames the upload request.
unsigned int CNMUploadFileFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMUploadFileFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141593010: dispatches encoding by message format.
unsigned int CNMUploadFileFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMUploadFileFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMUploadFileFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141593070: encodes upload fields or the reply result.
unsigned int CNMUploadFileFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this))FUN_14156ae30(e,m_szResult);else{FUN_14156ae30(e,m_szUrl);FUN_14156ae30(e,m_sz430);FUN_14156ae30(e,m_sz530);FUN_14156ab00(e,static_cast<unsigned char>(m_n630));}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141593140: decodes a framed upload response.
unsigned int CNMUploadFileFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMUploadFileFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x1415931d0: dispatches decoding by response format.
unsigned int CNMUploadFileFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMUploadFileFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMUploadFileFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141593230: restores upload inputs or the reply result.
unsigned int CNMUploadFileFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);void**v=*reinterpret_cast<void***>(d);using B=void(__fastcall*)(void*,void*,unsigned);using U8=unsigned char(__fastcall*)(void*);if(!FUN_1415fb700(this))reinterpret_cast<B>(v[9])(d,m_szResult,0x400);else{reinterpret_cast<B>(v[9])(d,m_szUrl,0x400);reinterpret_cast<B>(v[9])(d,m_sz430,0x100);reinterpret_cast<B>(v[9])(d,m_sz530,0x100);m_n630=reinterpret_cast<U8>(v[1])(d);}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMUploadFileFunc@@QEAA@XZ 0x141592dc0
// MS2-PIN: ??0CNMUploadFileFunc@@QEAA@PEBD00H@Z 0x141592e70
// MS2-PIN: ?EncodeFramed@CNMUploadFileFunc@@UEAAIPEAVCNMStream@@@Z 0x141592fb0
// MS2-PIN: ?EncodeDispatch@CNMUploadFileFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141593010
// MS2-PIN: ?Encode@CNMUploadFileFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141593070
// MS2-PIN: ?DecodeFramed@CNMUploadFileFunc@@UEAAIPEAVCNMStream@@@Z 0x141593140
// MS2-PIN: ?DecodeDispatch@CNMUploadFileFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415931d0
// MS2-PIN: ?Decode@CNMUploadFileFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141593230
