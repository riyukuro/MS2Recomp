// Nexon Messenger execute-NGM-patcher request serialization.
// MS2-UNIT: unit_14158e360
// MS2-RANGE: 0x14158e360-0x14158eb50 .text$mn
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

// MS2-FUNCTIONAL 0x14158e360: initializes all fixed buffers and default result fields.
CNMExecuteNGMPatcherFunc::CNMExecuteNGMPatcherFunc()
    : CNMFunc(0x8015, 1, 0, 0), m_nGameCode(0), m_sz2{}, m_sz3{}, m_sz4{}, m_pad8537(0),
      m_n5(1), m_n6(0), m_n7(0), m_sz8{}, m_n9(0), m_sz10{}, m_n11(0) {}

// MS2-FUNCTIONAL 0x14158e470: copies bounded patch parameters and stores numeric options.
CNMExecuteNGMPatcherFunc::CNMExecuteNGMPatcherFunc(int gameCode, const char* sz2, const char* sz3, const char* sz4,
                                                   int n5, int n6, int n7, const char* sz8, int n9,
                                                   const char* sz10, int n11)
    : CNMFunc(0x8015, 1, 0, 0), m_nGameCode(gameCode), m_sz2{}, m_sz3{}, m_sz4{}, m_pad8537(0),
      m_n5(n5), m_n6(n6), m_n7(n7), m_sz8{}, m_n9(n9), m_sz10{}, m_n11(n11)
{
    if (sz2) FUN_1415fbe70(m_sz2, 0x7fff, sz2);
    if (sz3) FUN_1415fbe70(m_sz3, 0x104, sz3);
    if (sz4) FUN_1415fbe70(m_sz4, 0x400, sz4);
    if (sz8) FUN_1415fbe70(m_sz8, 0x20, sz8);
    if (sz10) FUN_1415fbe70(m_sz10, 0x80, sz10);
}

// MS2-FUNCTIONAL 0x14158e670: frames a serialized NGM patcher request.
unsigned int CNMExecuteNGMPatcherFunc::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    void** vt = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcherFunc*, CNMEncoder*, CNMStream*);
    auto result = reinterpret_cast<Method>(vt[2])(this, reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158e6d0: dispatches encoding based on the message format.
unsigned int CNMExecuteNGMPatcherFunc::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    void** vt = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcherFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vt[2])(this, encoder, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcherFunc*, CNMStream*);
    return reinterpret_cast<Method>(vt[3])(this, stream);
}

// MS2-FUNCTIONAL 0x14158e730: serializes patch paths, options, and output settings.
unsigned int CNMExecuteNGMPatcherFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) {
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_nGameCode));
        FUN_14156ae30(encoder, m_sz2);
        FUN_14156ae30(encoder, m_sz3);
        FUN_14156ae30(encoder, m_sz4);
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n5));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n6));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n7));
        FUN_14156ae30(encoder, m_sz8);
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n9));
        FUN_14156ae30(encoder, m_sz10);
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_n11));
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158e880: decodes a framed NGM patcher response.
unsigned int CNMExecuteNGMPatcherFunc::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vt = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcherFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vt[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158e910: dispatches decoding by response format.
unsigned int CNMExecuteNGMPatcherFunc::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    void** vt = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(decoder) == 2) {
        using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcherFunc*, CNMStream*);
        return reinterpret_cast<Method>(vt[6])(this, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMExecuteNGMPatcherFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vt[5])(this, decoder, stream);
}

// MS2-FUNCTIONAL 0x14158e970: restores patch paths, options, and output settings from the reply.
unsigned int CNMExecuteNGMPatcherFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        void** vt = *reinterpret_cast<void***>(decoder);
        using ReadBytes = void(__fastcall*)(void*, void*, unsigned int);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        m_nGameCode = static_cast<int>(reinterpret_cast<ReadU32>(vt[3])(decoder));
        reinterpret_cast<ReadBytes>(vt[9])(decoder, m_sz2, 0x7fff);
        reinterpret_cast<ReadBytes>(vt[9])(decoder, m_sz3, 0x104);
        reinterpret_cast<ReadBytes>(vt[9])(decoder, m_sz4, 0x400);
        m_n5 = static_cast<int>(reinterpret_cast<ReadU32>(vt[3])(decoder));
        m_n6 = static_cast<int>(reinterpret_cast<ReadU32>(vt[3])(decoder));
        m_n7 = static_cast<int>(reinterpret_cast<ReadU32>(vt[3])(decoder));
        reinterpret_cast<ReadBytes>(vt[9])(decoder, m_sz8, 0x20);
        m_n9 = static_cast<int>(reinterpret_cast<ReadU32>(vt[3])(decoder));
        reinterpret_cast<ReadBytes>(vt[9])(decoder, m_sz10, 0x80);
        m_n11 = static_cast<int>(reinterpret_cast<ReadU32>(vt[3])(decoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMExecuteNGMPatcherFunc@@QEAA@XZ 0x14158e360
// MS2-PIN: ??0CNMExecuteNGMPatcherFunc@@QEAA@HPEBD00HHH0H0H@Z 0x14158e470
// MS2-PIN: ?EncodeFramed@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158e670
// MS2-PIN: ?EncodeDispatch@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158e6d0
// MS2-PIN: ?Encode@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158e730
// MS2-PIN: ?DecodeFramed@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158e880
// MS2-PIN: ?DecodeDispatch@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158e910
// MS2-PIN: ?Decode@CNMExecuteNGMPatcherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158e970
