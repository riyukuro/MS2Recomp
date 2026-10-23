// Nexon Messenger request-new-friend function serialization.
// MS2-UNIT: unit_141586b60
// MS2-RANGE: 0x141586b60-0x141586f00 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
#include <cstring>
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(void*);
// MS2-FUNCTIONAL 0x141586b60: initializes embedded new-friend data.
// @0x141586b60
CNMRequestNewFriendFunc::CNMRequestNewFriendFunc() : CNMFunc(0x4003,1,0,0),m_30() {}
// MS2-FUNCTIONAL 0x141586bd0: copies the data payload into the embedded object.
// @0x141586bd0
CNMRequestNewFriendFunc::CNMRequestNewFriendFunc(const CNMRequestNewFriendData& data) : CNMRequestNewFriendFunc() { std::memcpy(reinterpret_cast<char*>(&m_30)+0x10,reinterpret_cast<const char*>(&data)+0x10,0x1e0); }
// MS2-FUNCTIONAL 0x141586c50: frames the request and dispatches encoder slot.
// @0x141586c50
unsigned int CNMRequestNewFriendFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMRequestNewFriendFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x141586cb0: selects raw or framed encoding by format.
// @0x141586cb0
unsigned int CNMRequestNewFriendFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMRequestNewFriendFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMRequestNewFriendFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x141586d10: encodes the embedded new-friend payload in reply direction.
// @0x141586d10
unsigned int CNMRequestNewFriendFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(FUN_1415fb700(this))m_30.EncodeFramed(s);return 1;}
// MS2-FUNCTIONAL 0x141586d90: decodes through a temporary framed decoder.
// @0x141586d90
unsigned int CNMRequestNewFriendFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMRequestNewFriendFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x141586e20: selects framed decoding for wire format 2.
// @0x141586e20
unsigned int CNMRequestNewFriendFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMRequestNewFriendFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMRequestNewFriendFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x141586e80: decodes embedded new-friend data in reply direction.
// @0x141586e80
unsigned int CNMRequestNewFriendFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(FUN_1415fb700(this))m_30.DecodeFramed(s);return static_cast<unsigned int>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMRequestNewFriendFunc@@QEAA@XZ 0x141586b60
