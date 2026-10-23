// Nexon Messenger game friend-title request serialization.
// MS2-UNIT: unit_1415943a0
// MS2-RANGE: 0x1415943a0-0x141594740 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ae30(void*,void*); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x1415943A0: initializes the request and empty reply buffer.
CNMGetGameFriendTitleFunc::CNMGetGameFriendTitleFunc():CNMFunc(0x8010,1,0,0),m_nGameCode(0),m_szTitle{}{}
// MS2-FUNCTIONAL 0x141594410: stores the requested game code and clears the reply buffer.
CNMGetGameFriendTitleFunc::CNMGetGameFriendTitleFunc(int code):CNMFunc(0x8010,1,0,0),m_nGameCode(code),m_szTitle{}{}
// MS2-FUNCTIONAL 0x141594480: frames the friend-title request.
unsigned int CNMGetGameFriendTitleFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetGameFriendTitleFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x1415944E0: dispatches encoding according to message format.
unsigned int CNMGetGameFriendTitleFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGetGameFriendTitleFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGetGameFriendTitleFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141594540: writes the name on replies and the game code on requests.
unsigned int CNMGetGameFriendTitleFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this))FUN_14156ae30(e,m_szTitle);else FUN_14156ac20(e,static_cast<unsigned int>(m_nGameCode));FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x1415945C0: decodes a framed full-name response.
unsigned int CNMGetGameFriendTitleFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetGameFriendTitleFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141594650: dispatches decoding according to response format.
unsigned int CNMGetGameFriendTitleFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGetGameFriendTitleFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGetGameFriendTitleFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x1415946B0: reads the 0x420-byte friend title on replies, or game code on requests.
unsigned int CNMGetGameFriendTitleFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(!FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using F=void(__fastcall*)(void*,void*,unsigned int);reinterpret_cast<F>(v[9])(d,m_szTitle,0x80);}else{void**v=*reinterpret_cast<void***>(d);using F=unsigned(__fastcall*)(void*);m_nGameCode=static_cast<int>(reinterpret_cast<F>(v[3])(d));}FUN_1415fb750(d);return 1;}
// MS2-PIN: ??0CNMGetGameFriendTitleFunc@@QEAA@XZ 0x1415943A0
// MS2-PIN: ??0CNMGetGameFriendTitleFunc@@QEAA@H@Z 0x141594410
// MS2-PIN: ?EncodeFramed@CNMGetGameFriendTitleFunc@@UEAAIPEAVCNMStream@@@Z 0x141594480
// MS2-PIN: ?EncodeDispatch@CNMGetGameFriendTitleFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x1415944E0
// MS2-PIN: ?Encode@CNMGetGameFriendTitleFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x141594540
// MS2-PIN: ?DecodeFramed@CNMGetGameFriendTitleFunc@@UEAAIPEAVCNMStream@@@Z 0x1415945C0
// MS2-PIN: ?DecodeDispatch@CNMGetGameFriendTitleFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x141594650
// MS2-PIN: ?Decode@CNMGetGameFriendTitleFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x1415946B0
