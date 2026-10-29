// Nexon Messenger get-friend-info request serialization.
// MS2-UNIT: unit_1415866f0
// MS2-RANGE: 0x1415866f0-0x141586b60 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
#include <cstring>
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156acb0(void*,unsigned long long); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x1415866f0: initializes the nested friend record.
// @0x1415866f0
CNMGetFriendInfoFunc::CNMGetFriendInfoFunc() : CNMFunc(0x4002,1,0,0), m_30(0),m_38(0),m_3c(0),m_40(0),m_44(0),m_48() {}
// MS2-FUNCTIONAL 0x141586760: stores the 0x18-byte friend key and initializes result data.
// @0x141586760
CNMGetFriendInfoFunc::CNMGetFriendInfoFunc(const unsigned char* key) : CNMGetFriendInfoFunc() { if(key) std::memcpy(&m_30,key,0x18); }
// MS2-FUNCTIONAL 0x1415867e0: frames the request and dispatches its encoder slot.
// @0x1415867e0
unsigned int CNMGetFriendInfoFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetFriendInfoFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141586840: selects raw or framed encoding by format.
// @0x141586840
unsigned int CNMGetFriendInfoFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetFriendInfoFunc::Encode(pEncoder, pStream);
    return CNMGetFriendInfoFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x1415868a0: serializes either the returned friend record or requested key fields.
// @0x1415868a0
unsigned int CNMGetFriendInfoFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this)){m_48.EncodeFramed(s);}else{FUN_14156acb0(e,m_30);FUN_14156ac20(e,m_38);FUN_14156ac20(e,m_3c);FUN_14156ac20(e,m_40);FUN_14156ac20(e,m_44);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x141586980: decodes through a temporary framed decoder.
// @0x141586980
unsigned int CNMGetFriendInfoFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetFriendInfoFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141586a10: selects framed decoding for wire format 2.
// @0x141586a10
unsigned int CNMGetFriendInfoFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetFriendInfoFunc::DecodeFramed(pStream);
    return CNMGetFriendInfoFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x141586a70: restores nested friend info or request key fields.
// @0x141586a70
unsigned int CNMGetFriendInfoFunc::Decode(CNMSerializableDecoder*d,CNMStream*s){CNMFunc::DecodeDispatch(d,s);if(!FUN_1415fb700(this)){m_48.DecodeFramed(s);}else{void**v=*reinterpret_cast<void***>(d);using U64=unsigned long long(__fastcall*)(void*);using U32=unsigned int(__fastcall*)(void*);m_30=reinterpret_cast<U64>(v[4])(d);m_38=static_cast<int>(reinterpret_cast<U32>(v[3])(d));m_3c=static_cast<int>(reinterpret_cast<U32>(v[3])(d));m_40=static_cast<int>(reinterpret_cast<U32>(v[3])(d));m_44=static_cast<int>(reinterpret_cast<U32>(v[3])(d));}return static_cast<unsigned int>(FUN_1415fb750(d));}
// MS2-PIN: ??0CNMGetFriendInfoFunc@@QEAA@XZ 0x1415866f0
