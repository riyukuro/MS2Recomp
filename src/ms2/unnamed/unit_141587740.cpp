// Nexon Messenger change-friend-memo request serialization.
// MS2-UNIT: unit_141587740
// MS2-RANGE: 0x141587740-0x141587b10 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156acb0(void*,unsigned long long); extern void FUN_14156ae30(void*,const void*); extern void FUN_1415f9990(void*); extern void FUN_1415fbe70(void*,unsigned int,const void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141587740: initializes empty memo fields.
// @0x141587740
CNMChangeFriendMemoFunc::CNMChangeFriendMemoFunc():CNMFunc(0x4006,1,0,0),m_30(0),m_38{}{}
// MS2-FUNCTIONAL 0x1415877b0: stores the friend key and optional memo.
// @0x1415877b0
CNMChangeFriendMemoFunc::CNMChangeFriendMemoFunc(long long key,long long memo):CNMFunc(0x4006,1,0,0),m_30(key),m_38{}{if(memo)FUN_1415fbe70(m_38,0x20,reinterpret_cast<const void*>(memo));}
// MS2-FUNCTIONAL 0x141587850: frames request and dispatches encoder slot.
// @0x141587850
unsigned int CNMChangeFriendMemoFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChangeFriendMemoFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x1415878b0: selects raw or framed encoding by format.
// @0x1415878b0
unsigned int CNMChangeFriendMemoFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMChangeFriendMemoFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMChangeFriendMemoFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141587910: serializes friend key and memo text.
// @0x141587910
unsigned int CNMChangeFriendMemoFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156acb0(e,static_cast<unsigned long long>(m_30));FUN_14156ae30(e,m_38);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141587990: decodes through a temporary framed decoder.
// @0x141587990
unsigned int CNMChangeFriendMemoFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChangeFriendMemoFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141587a20: selects framed decoding for wire format 2.
// @0x141587a20
unsigned int CNMChangeFriendMemoFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMChangeFriendMemoFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMChangeFriendMemoFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141587a80: restores key and memo buffer.
// @0x141587a80
unsigned int CNMChangeFriendMemoFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U64=unsigned long long(__fastcall*)(void*);using Bytes=unsigned int(__fastcall*)(void*,void*,unsigned int);m_30=static_cast<long long>(reinterpret_cast<U64>(v[4])(d));reinterpret_cast<Bytes>(v[9])(d,m_38,0x20);}return static_cast<unsigned int>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMChangeFriendMemoFunc@@QEAA@XZ 0x141587740
