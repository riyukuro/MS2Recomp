// Nexon Messenger execute-NGM-patcher2 request serialization.
// MS2-UNIT: unit_14158eb50
// MS2-RANGE: 0x14158eb50-0x14158ef30 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415fbe70(void*, unsigned int, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb700(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);

// MS2-FUNCTIONAL 0x14158eb50: initializes an empty NGM patcher request.
CNMExecuteNGMPatcher2Func::CNMExecuteNGMPatcher2Func()
    : CNMFunc(0x8022, 1, 0, 0), m_szArgument{}, m_n8030(0), m_n8034(0) {}

// MS2-FUNCTIONAL 0x14158ebc0: stores a bounded patch argument and its option.
CNMExecuteNGMPatcher2Func::CNMExecuteNGMPatcher2Func(const char* argument, int n2)
    : CNMFunc(0x8022, 1, 0, 0), m_szArgument{}, m_n8030(n2), m_n8034(0)
{
    if (argument) FUN_1415fbe70(m_szArgument, 0x7fff, argument);
}

// MS2-FUNCTIONAL 0x14158ec60: frames a serialized NGM patcher2 request.
unsigned int CNMExecuteNGMPatcher2Func::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18]; FUN_14156bcb0(storage, stream, this);
    void** vt = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcher2Func*, CNMEncoder*, CNMStream*);
    auto result = reinterpret_cast<Method>(vt[2])(this, reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage); return result;
}

// MS2-FUNCTIONAL 0x14158ecc0: selects the encoder based on wire format.
unsigned int CNMExecuteNGMPatcher2Func::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    void** vt = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) { using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcher2Func*, CNMEncoder*, CNMStream*); return reinterpret_cast<Method>(vt[2])(this, encoder, stream); }
    using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcher2Func*, CNMStream*); return reinterpret_cast<Method>(vt[3])(this, stream);
}

// MS2-FUNCTIONAL 0x14158ed20: encodes the argument and option in replies.
unsigned int CNMExecuteNGMPatcher2Func::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) { FUN_14156ae30(encoder, m_szArgument); FUN_14156ac20(encoder, static_cast<unsigned int>(m_n8030)); }
    FUN_1415f9990(encoder); return 1;
}

// MS2-FUNCTIONAL 0x14158eda0: decodes a framed NGM patcher2 response.
unsigned int CNMExecuteNGMPatcher2Func::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38]; FUN_14156be10(storage, stream, this); unsigned int result = 0;
    if (FUN_1415fb750(storage)) { void** vt = *reinterpret_cast<void***>(this); using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcher2Func*, CNMSerializableDecoder*, CNMStream*); result = reinterpret_cast<Method>(vt[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), stream); }
    FUN_14156bf10(storage); return result;
}

// MS2-FUNCTIONAL 0x14158ee30: selects the decoder based on response format.
unsigned int CNMExecuteNGMPatcher2Func::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    void** vt = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(decoder) == 2) { using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcher2Func*, CNMStream*); return reinterpret_cast<Method>(vt[6])(this, stream); }
    using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcher2Func*, CNMSerializableDecoder*, CNMStream*); return reinterpret_cast<Method>(vt[5])(this, decoder, stream);
}

// MS2-FUNCTIONAL 0x14158ee90: restores the patch argument and option.
unsigned int CNMExecuteNGMPatcher2Func::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) { void** vt = *reinterpret_cast<void***>(decoder); using ReadBytes = void(__fastcall*)(void*, void*, unsigned int); using ReadU32 = unsigned int(__fastcall*)(void*); reinterpret_cast<ReadBytes>(vt[9])(decoder, m_szArgument, 0x7fff); m_n8030 = static_cast<int>(reinterpret_cast<ReadU32>(vt[3])(decoder)); }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMExecuteNGMPatcher2Func@@QEAA@XZ 0x14158eb50
// MS2-PIN: ??0CNMExecuteNGMPatcher2Func@@QEAA@PEBDH@Z 0x14158ebc0
// MS2-PIN: ?EncodeFramed@CNMExecuteNGMPatcher2Func@@UEAAIPEAVCNMStream@@@Z 0x14158ec60
// MS2-PIN: ?EncodeDispatch@CNMExecuteNGMPatcher2Func@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158ecc0
// MS2-PIN: ?Encode@CNMExecuteNGMPatcher2Func@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158ed20
// MS2-PIN: ?DecodeFramed@CNMExecuteNGMPatcher2Func@@UEAAIPEAVCNMStream@@@Z 0x14158eda0
// MS2-PIN: ?DecodeDispatch@CNMExecuteNGMPatcher2Func@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158ee30
// MS2-PIN: ?Decode@CNMExecuteNGMPatcher2Func@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158ee90
