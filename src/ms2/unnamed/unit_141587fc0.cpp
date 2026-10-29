// Nexon Messenger add-friend-to-category request serialization.
// MS2-UNIT: unit_141587fc0
// MS2-RANGE: 0x141587fc0-0x141588470 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
#include <cstring>
extern void FUN_14156bcb0(void*,void*,void*); extern void FUN_14156bd50(void*); extern void FUN_14156be10(void*,void*,void*); extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int); extern void FUN_14156acb0(void*,unsigned long long); extern void FUN_14156ab00(void*,unsigned char); extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*); extern int FUN_1415fb750(void*); extern int FUN_1415fb6d0(CNMSerializableDecoder*);
// MS2-FUNCTIONAL 0x141587fc0: initializes the friend key and category fields.
// @0x141587fc0
CNMAddFriendToCategoryFunc::CNMAddFriendToCategoryFunc():CNMFunc(0x4007,1,0,0),m_key{},m_48(0),m_4c(0){}
// MS2-FUNCTIONAL 0x141588050: stores friend key, category, and flag.
// @0x141588050
CNMAddFriendToCategoryFunc::CNMAddFriendToCategoryFunc(const unsigned char*key,int category,int flag):CNMAddFriendToCategoryFunc(){if(key)std::memcpy(&m_key,key,0x18);m_48=category;m_4c=flag;}
// MS2-FUNCTIONAL 0x1415880e0: frames the request and dispatches encoder slot.
// @0x1415880e0
unsigned int CNMAddFriendToCategoryFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMAddFriendToCategoryFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x141588140: selects raw or framed encoding by format.
// @0x141588140
unsigned int CNMAddFriendToCategoryFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMAddFriendToCategoryFunc::Encode(pEncoder, pStream);
    return CNMAddFriendToCategoryFunc::EncodeFramed(pStream);
}
// @0x1415881a0
unsigned int CNMAddFriendToCategoryFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this))
    {
        FUN_14156acb0(pEncoder, m_key.uIDCode);
        FUN_14156ac20(pEncoder, m_key.n08);
        FUN_14156ac20(pEncoder, m_key.n0c);
        FUN_14156ac20(pEncoder, m_key.n10);
        FUN_14156ac20(pEncoder, m_key.n14);
        FUN_14156ac20(pEncoder, m_48);
        FUN_14156ab00(pEncoder, static_cast<unsigned char>(m_4c));
    }
    FUN_1415f9990(pEncoder);
    return 1;
}
// MS2-FUNCTIONAL 0x141588280: decodes through a temporary framed decoder.
// @0x141588280
unsigned int CNMAddFriendToCategoryFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMAddFriendToCategoryFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x141588310: selects framed decoding for wire format 2.
// @0x141588310
unsigned int CNMAddFriendToCategoryFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMAddFriendToCategoryFunc::DecodeFramed(pStream);
    return CNMAddFriendToCategoryFunc::Decode(pDecoder, pStream);
}
// @0x141588370
unsigned int CNMAddFriendToCategoryFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this))
    {
        m_key.uIDCode = pDecoder->ReadU64();
        m_key.n08 = pDecoder->ReadU32();
        m_key.n0c = pDecoder->ReadU32();
        m_key.n10 = pDecoder->ReadU32();
        m_key.n14 = pDecoder->ReadU32();
        m_48 = pDecoder->ReadU32();
        m_4c = pDecoder->ReadU8();
    }
    return FUN_1415fb750(pDecoder);
}
// MS2-PIN: ??0CNMAddFriendToCategoryFunc@@QEAA@XZ 0x141587fc0
