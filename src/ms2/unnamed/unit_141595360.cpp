// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNMGetSessionValueFunc request construction and
// serialization methods. The request serializes its name on the outbound direction and its value on reply.
// MS2-UNIT: unit_141595360
// MS2-RANGE: 0x141595360-0x141595750 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern void FUN_1415fbe70(void*, unsigned int, const char*);
extern int FUN_1415fb700(const void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// @0x141595360
CNMGetSessionValueFunc::CNMGetSessionValueFunc() : CNMFunc(0x8007, 1, 0, 0)
{
    *reinterpret_cast<unsigned int*>(m_szName) = 0;
    *reinterpret_cast<unsigned int*>(m_szValue) = 0;
}

// @0x1415953d0
CNMGetSessionValueFunc::CNMGetSessionValueFunc(const char* szName) : CNMFunc(0x8007, 1, 0, 0)
{
    if (szName)
        FUN_1415fbe70(m_szName, sizeof(m_szName), szName);
    else
        m_szName[0] = 0;
    m_szValue[0] = 0;
}

// MS2-FUNCTIONAL: behavior and virtual slot are recovered; the compiler devirtualizes the encoder helper chain,
// producing a different callee count than the executable's indirect call sequence.
// @0x141595530
unsigned int CNMGetSessionValueFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    const void* field = FUN_1415fb700(this) ? static_cast<const void*>(m_szName)
                                           : static_cast<const void*>(m_szValue);
    FUN_14156ae30(pEncoder, field);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: same framing helper and serializer behavior; local encoder lifetime produces a different frame.
// @0x141595470
unsigned int CNMGetSessionValueFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const auto result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: dispatch condition and target slots match; direct calls replace the executable's indirect calls.
// @0x1415954d0
unsigned int CNMGetSessionValueFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    return m_bFormat == 1 ? Encode(pEncoder, pStream) : EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: field selection, capacity and final decoder status match; the decoder read remains an indirect call.
// @0x1415956a0
unsigned int CNMGetSessionValueFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    const bool requestDirection = FUN_1415fb700(this) != 0;
    using ReadString = void(__fastcall*)(void*, void*, unsigned int);
    void** vftable = *reinterpret_cast<void***>(pDecoder);
    auto readString = reinterpret_cast<ReadString>(vftable[9]);
    void* field = requestDirection ? static_cast<void*>(m_szName) : static_cast<void*>(m_szValue);
    const unsigned int capacity = requestDirection ? sizeof(m_szName) : sizeof(m_szValue);
    readString(pDecoder, field, capacity);
    return FUN_1415fb750(pDecoder);
}

// MS2-FUNCTIONAL: decoder framing behavior is recovered; temporary decoder storage yields a different frame.
// @0x1415955b0
unsigned int CNMGetSessionValueFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    const auto result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: format dispatch is recovered; direct calls replace the executable's indirect calls.
// @0x141595640
unsigned int CNMGetSessionValueFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    return FUN_1415fb6d0(pDecoder) == 2 ? DecodeFramed(pStream) : Decode(pDecoder, pStream);
}

// MS2-PIN: ??0CNMGetSessionValueFunc@@QEAA@XZ 0x141595360
// MS2-PIN: ??0CNMGetSessionValueFunc@@QEAA@PEBD@Z 0x1415953d0
