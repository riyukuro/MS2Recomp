// Nexon Messenger extended change-friend-memo request serialization.
// MS2-UNIT: unit_141587b10
// MS2-RANGE: 0x141587b10-0x141587fc0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
#include <cstring>
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156acb0(void*,unsigned long long); extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156ae30(void*,const void*); extern void FUN_1415f9990(void*); extern void FUN_1415fbe70(void*,unsigned int,const void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141587b10: initializes empty key and memo fields.
// @0x141587b10
CNMChangeFriendMemoExFunc::CNMChangeFriendMemoExFunc():CNMFunc(0x400a,1,0,0),m_30(0),m_38(0),m_3c(0),m_40(0),m_44(0),m_48{}{}
// MS2-FUNCTIONAL 0x141587ba0: stores key data and optional memo.
// @0x141587ba0
CNMChangeFriendMemoExFunc::CNMChangeFriendMemoExFunc(const unsigned char*key,long long memo):CNMChangeFriendMemoExFunc(){if(key)std::memcpy(&m_30,key,0x18);if(memo)FUN_1415fbe70(m_48,0x20,reinterpret_cast<const void*>(memo));}
// MS2-FUNCTIONAL 0x141587c50: frames request and dispatches encoder slot.
// @0x141587c50
unsigned int CNMChangeFriendMemoExFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChangeFriendMemoExFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141587cb0: selects raw or framed encoding by format.
// @0x141587cb0
unsigned int CNMChangeFriendMemoExFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMChangeFriendMemoExFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMChangeFriendMemoExFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141587d10: serializes key components and memo.
// @0x141587d10
unsigned int CNMChangeFriendMemoExFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156acb0(e,m_30);FUN_14156ac20(e,m_38);FUN_14156ac20(e,m_3c);FUN_14156ac20(e,m_40);FUN_14156ac20(e,m_44);FUN_14156ae30(e,m_48);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141587dd0: decodes through a temporary framed decoder.
// @0x141587dd0
unsigned int CNMChangeFriendMemoExFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMChangeFriendMemoExFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141587e60: selects framed decoding for wire format 2.
// @0x141587e60
unsigned int CNMChangeFriendMemoExFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMChangeFriendMemoExFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMChangeFriendMemoExFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141587ec0: restores key components and memo buffer.
// @0x141587ec0
unsigned int CNMChangeFriendMemoExFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U64=unsigned long long(__fastcall*)(void*);using U32=unsigned int(__fastcall*)(void*);using B=unsigned int(__fastcall*)(void*,void*,unsigned int);m_30=reinterpret_cast<U64>(v[4])(d);m_38=static_cast<int>(reinterpret_cast<U32>(v[3])(d));m_3c=static_cast<int>(reinterpret_cast<U32>(v[3])(d));m_40=static_cast<int>(reinterpret_cast<U32>(v[3])(d));m_44=static_cast<int>(reinterpret_cast<U32>(v[3])(d));reinterpret_cast<B>(v[9])(d,m_48,0x20);}return static_cast<unsigned int>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMChangeFriendMemoExFunc@@QEAA@XZ 0x141587b10
