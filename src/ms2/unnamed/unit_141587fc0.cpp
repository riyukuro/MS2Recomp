// Nexon Messenger add-friend-to-category request serialization.
// MS2-UNIT: unit_141587fc0
// MS2-RANGE: 0x141587fc0-0x141588470 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
#include <cstring>
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156acb0(void*,unsigned long long); extern void FUN_14156ab00(void*,unsigned int); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141587fc0: initializes the friend key and category fields.
// @0x141587fc0
CNMAddFriendToCategoryFunc::CNMAddFriendToCategoryFunc():CNMFunc(0x4007,1,0,0),m_key{},m_48(0),m_4c(0){}
// MS2-FUNCTIONAL 0x141588050: stores friend key, category, and flag.
// @0x141588050
CNMAddFriendToCategoryFunc::CNMAddFriendToCategoryFunc(const unsigned char*key,int category,int flag):CNMAddFriendToCategoryFunc(){if(key)std::memcpy(&m_key,key,0x18);m_48=category;m_4c=flag;}
// MS2-FUNCTIONAL 0x1415880e0: frames the request and dispatches encoder slot.
// @0x1415880e0
unsigned int CNMAddFriendToCategoryFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMAddFriendToCategoryFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141588140: selects raw or framed encoding by format.
// @0x141588140
unsigned int CNMAddFriendToCategoryFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMAddFriendToCategoryFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMAddFriendToCategoryFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x1415881a0: serializes friend key, category, and flag.
// @0x1415881a0
unsigned int CNMAddFriendToCategoryFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this)){FUN_14156acb0(e,m_key.uIDCode);FUN_14156ac20(e,m_key.n08);FUN_14156ac20(e,m_key.n0c);FUN_14156ac20(e,m_key.n10);FUN_14156ac20(e,m_key.n14);FUN_14156ac20(e,m_48);FUN_14156ab00(e,static_cast<unsigned char>(m_4c));}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141588280: decodes through a temporary framed decoder.
// @0x141588280
unsigned int CNMAddFriendToCategoryFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMAddFriendToCategoryFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141588310: selects framed decoding for wire format 2.
// @0x141588310
unsigned int CNMAddFriendToCategoryFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMAddFriendToCategoryFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMAddFriendToCategoryFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141588370: restores friend key, category, and flag.
// @0x141588370
unsigned int CNMAddFriendToCategoryFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this)){void**v=*reinterpret_cast<void***>(d);using U64=unsigned long long(__fastcall*)(void*);using U32=unsigned int(__fastcall*)(void*);using U8=unsigned char(__fastcall*)(void*);m_key.uIDCode=reinterpret_cast<U64>(v[4])(d);m_key.n08=reinterpret_cast<U32>(v[3])(d);m_key.n0c=reinterpret_cast<U32>(v[3])(d);m_key.n10=reinterpret_cast<U32>(v[3])(d);m_key.n14=reinterpret_cast<U32>(v[3])(d);m_48=static_cast<int>(reinterpret_cast<U32>(v[3])(d));m_4c=static_cast<int>(reinterpret_cast<U8>(v[1])(d));}return static_cast<unsigned int>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMAddFriendToCategoryFunc@@QEAA@XZ 0x141587fc0
