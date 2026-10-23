// Nexon Messenger execute-NGM-installer request serialization.
// MS2-UNIT: unit_14158f620
// MS2-RANGE: 0x14158f620-0x14158fca0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*,const void*); extern void FUN_14156ac20(void*,unsigned int); extern void FUN_1415fbe70(void*,unsigned int,const void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x14158f620: initializes the installer request and its default enable flag.
CNMExecuteNGMInstallerFunc::CNMExecuteNGMInstallerFunc():CNMFunc(0x8020,1,0,0),m_nGameCode(0),m_n34(1),m_n38(0),m_sz3c{},m_sz43c{},m_sz83c{},m_sz85c{},m_n8dc(0){}
// MS2-FUNCTIONAL 0x14158f6f0: copies installer paths and stores request settings.
CNMExecuteNGMInstallerFunc::CNMExecuteNGMInstallerFunc(int gameCode,int n2,int n3,const char* sz4,const char* sz5,const char* sz6,const char* sz7,int n8):CNMFunc(0x8020,1,0,0),m_nGameCode(gameCode),m_n34(n2),m_n38(n3),m_sz3c{},m_sz43c{},m_sz83c{},m_sz85c{},m_n8dc(n8){if(sz4)FUN_1415fbe70(m_sz3c,0x400,sz4);if(sz5)FUN_1415fbe70(m_sz43c,0x400,sz5);if(sz6)FUN_1415fbe70(m_sz83c,0x20,sz6);if(sz7)FUN_1415fbe70(m_sz85c,0x80,sz7);}
// MS2-FUNCTIONAL 0x14158f880: frames the installer request.
unsigned int CNMExecuteNGMInstallerFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMExecuteNGMInstallerFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14158f8e0: dispatches encoding by message format.
unsigned int CNMExecuteNGMInstallerFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMExecuteNGMInstallerFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMExecuteNGMInstallerFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14158f940: encodes installer identifiers, paths, and options.
unsigned int CNMExecuteNGMInstallerFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,m_nGameCode);FUN_14156ac20(e,m_n34);FUN_14156ac20(e,m_n38);FUN_14156ae30(e,m_sz3c);FUN_14156ae30(e,m_sz43c);FUN_14156ae30(e,m_sz83c);FUN_14156ae30(e,m_sz85c);FUN_14156ac20(e,m_n8dc);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14158fa40: decodes a framed installer response.
unsigned int CNMExecuteNGMInstallerFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMExecuteNGMInstallerFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14158fad0: dispatches decoding by response format.
unsigned int CNMExecuteNGMInstallerFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMExecuteNGMInstallerFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMExecuteNGMInstallerFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14158fb30: restores installer identifiers, paths, and settings.
unsigned int CNMExecuteNGMInstallerFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using B=void(__fastcall*)(void*,void*,unsigned);using U=unsigned(__fastcall*)(void*);m_nGameCode=static_cast<int>(reinterpret_cast<U>(v[3])(d));m_n34=static_cast<int>(reinterpret_cast<U>(v[3])(d));m_n38=static_cast<int>(reinterpret_cast<U>(v[3])(d));reinterpret_cast<B>(v[9])(d,m_sz3c,0x400);reinterpret_cast<B>(v[9])(d,m_sz43c,0x400);reinterpret_cast<B>(v[9])(d,m_sz83c,0x20);reinterpret_cast<B>(v[9])(d,m_sz85c,0x80);m_n8dc=static_cast<int>(reinterpret_cast<U>(v[3])(d));}return static_cast<unsigned>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMExecuteNGMInstallerFunc@@QEAA@XZ 0x14158f620
// MS2-PIN: ??0CNMExecuteNGMInstallerFunc@@QEAA@HHHPEBD000H@Z 0x14158f6f0
// MS2-PIN: ?EncodeFramed@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMStream@@@Z 0x14158f880
// MS2-PIN: ?EncodeDispatch@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158f8e0
// MS2-PIN: ?Encode@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158f940
// MS2-PIN: ?DecodeFramed@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMStream@@@Z 0x14158fa40
// MS2-PIN: ?DecodeDispatch@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158fad0
// MS2-PIN: ?Decode@CNMExecuteNGMInstallerFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158fb30
