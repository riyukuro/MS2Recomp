// Nexon Messenger confirm-new-friend request serialization.
// MS2-UNIT: unit_141586f00
// MS2-RANGE: 0x141586f00-0x1415872d0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ab00(void*,unsigned int); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141586f00: initializes default confirmation status and fields.
// @0x141586f00
CNMConfirmNewFriendFunc::CNMConfirmNewFriendFunc():CNMFunc(0x4004,1,0,0),m_30(0),m_34(3),m_38(0),m_3c(0){}
// MS2-FUNCTIONAL 0x141586f70: stores result, flags, and user ID.
// @0x141586f70
CNMConfirmNewFriendFunc::CNMConfirmNewFriendFunc(int result,int flags,int userId):CNMFunc(0x4004,1,0,0),m_30(result),m_34(flags),m_38(userId),m_3c(0){}
// MS2-FUNCTIONAL 0x141586ff0: frames the request and dispatches encoder slot.
// @0x141586ff0
unsigned int CNMConfirmNewFriendFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMConfirmNewFriendFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141587050: selects raw or framed encoding by format.
// @0x141587050
unsigned int CNMConfirmNewFriendFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMConfirmNewFriendFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMConfirmNewFriendFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x1415870b0: serializes result, one-byte flags, and user ID.
// @0x1415870b0
unsigned int CNMConfirmNewFriendFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156ac20(e,m_30);FUN_14156ab00(e,static_cast<unsigned char>(m_34));FUN_14156ac20(e,m_38);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141587140: decodes through a temporary framed decoder.
// @0x141587140
unsigned int CNMConfirmNewFriendFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMConfirmNewFriendFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x1415871d0: selects framed decoding for wire format 2.
// @0x1415871d0
unsigned int CNMConfirmNewFriendFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMConfirmNewFriendFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMConfirmNewFriendFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141587230: restores result, one-byte flags, and user ID.
// @0x141587230
unsigned int CNMConfirmNewFriendFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U32=unsigned int(__fastcall*)(void*);using U8=unsigned char(__fastcall*)(void*);m_30=static_cast<int>(reinterpret_cast<U32>(v[3])(d));m_34=static_cast<int>(reinterpret_cast<U8>(v[1])(d));m_38=static_cast<int>(reinterpret_cast<U32>(v[3])(d));}return static_cast<unsigned int>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMConfirmNewFriendFunc@@QEAA@XZ 0x141586f00
