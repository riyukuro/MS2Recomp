// Nexon Messenger execute-launcher request serialization.
// MS2-UNIT: unit_14158deb0
// MS2-RANGE: 0x14158deb0-0x14158e360 .text$mn
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

// MS2-FUNCTIONAL 0x14158deb0: initializes an empty launcher request with the default result flag.
CNMExecuteLauncherFunc::CNMExecuteLauncherFunc()
    : CNMFunc(0x8002, 1, 0, 0), m_nGameCode(0), m_n34(0), m_szArgument{}, m_n808(1), m_n80c(0) {}

// MS2-FUNCTIONAL 0x14158df40: stores launcher codes, a bounded argument, and option fields.
CNMExecuteLauncherFunc::CNMExecuteLauncherFunc(int gameCode, int n2, const char* argument, int n4, int n5)
    : CNMFunc(0x8002, 1, 0, 0), m_nGameCode(gameCode), m_n34(n2), m_szArgument{}, m_n808(n4), m_n80c(n5)
{
    if (argument) FUN_1415fbe70(m_szArgument, 2000, argument);
}

// MS2-FUNCTIONAL 0x14158e010: frames a serialized launcher request.
unsigned int CNMExecuteLauncherFunc::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMExecuteLauncherFunc*, CNMEncoder*, CNMStream*);
    const auto result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158e070: dispatches serialization according to the framing mode.
unsigned int CNMExecuteLauncherFunc::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMExecuteLauncherFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, encoder, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMExecuteLauncherFunc*, CNMStream*);
    return reinterpret_cast<Method>(vtable[3])(this, stream);
}

// MS2-FUNCTIONAL 0x14158e0d0: encodes launch identifiers, argument, and options in replies.
unsigned int CNMExecuteLauncherFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_nGameCode));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n34));
        FUN_14156ae30(encoder, m_szArgument);
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n808));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n80c));
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158e190: decodes a framed launcher response.
unsigned int CNMExecuteLauncherFunc::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMExecuteLauncherFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158e220: dispatches decoding by response format.
unsigned int CNMExecuteLauncherFunc::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(decoder) == 2) {
        using Method = unsigned int(__fastcall*)(CNMExecuteLauncherFunc*, CNMStream*);
        return reinterpret_cast<Method>(vtable[6])(this, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMExecuteLauncherFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, decoder, stream);
}

// MS2-FUNCTIONAL 0x14158e280: restores launch identifiers, argument, and options from the reply.
unsigned int CNMExecuteLauncherFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(decoder);
        using ReadBytes = void(__fastcall*)(void*, void*, unsigned int);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_nGameCode = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
        m_n34 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
        reinterpret_cast<ReadBytes>(vtable[9])(decoder, m_szArgument, 2000);
        m_n808 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
        m_n80c = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMExecuteLauncherFunc@@QEAA@XZ 0x14158deb0
// MS2-PIN: ??0CNMExecuteLauncherFunc@@QEAA@HHPEBDHH@Z 0x14158df40
// MS2-PIN: ?EncodeFramed@CNMExecuteLauncherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158e010
// MS2-PIN: ?EncodeDispatch@CNMExecuteLauncherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158e070
// MS2-PIN: ?Encode@CNMExecuteLauncherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158e0d0
// MS2-PIN: ?DecodeFramed@CNMExecuteLauncherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158e190
// MS2-PIN: ?DecodeDispatch@CNMExecuteLauncherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158e220
// MS2-PIN: ?Decode@CNMExecuteLauncherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158e280
