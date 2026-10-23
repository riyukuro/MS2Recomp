// Nexon Messenger execute-patcher request serialization.
// MS2-UNIT: unit_14158d8f0
// MS2-RANGE: 0x14158d8f0-0x14158deb0 .text$mn
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

// MS2-FUNCTIONAL 0x14158d8f0: initializes an empty execute-patcher request and its result fields.
CNMExecutePatcherFunc::CNMExecutePatcherFunc()
    : CNMFunc(0x8001, 1, 0, 0), m_szUrl{}, m_szPatchDir{}, m_szExecPath{}, m_na00(1), m_na04(0), m_na08(0), m_na0c(0) {}

// MS2-FUNCTIONAL 0x14158d9b0: copies the three bounded path strings and stores request options.
CNMExecutePatcherFunc::CNMExecutePatcherFunc(const char* url, const char* patchDir, const char* execPath,
                                             int n4, int n5, int n6)
    : CNMFunc(0x8001, 1, 0, 0), m_szUrl{}, m_szPatchDir{}, m_szExecPath{}, m_na00(n4), m_na04(n5), m_na08(n6), m_na0c(0)
{
    if (url) FUN_1415fbe70(m_szUrl, sizeof(m_szUrl), url);
    if (patchDir) FUN_1415fbe70(m_szPatchDir, sizeof(m_szPatchDir), patchDir);
    if (execPath) FUN_1415fbe70(m_szExecPath, 2000, execPath);
}

// MS2-FUNCTIONAL 0x14158daf0: frames a serialized request.
unsigned int CNMExecutePatcherFunc::EncodeFramed(CNMStream* stream)
{
    unsigned char storage[0x18];
    FUN_14156bcb0(storage, stream, this);
    void** vtable = *reinterpret_cast<void***>(this);
    using Method = unsigned int(__fastcall*)(CNMExecutePatcherFunc*, CNMEncoder*, CNMStream*);
    const auto result = reinterpret_cast<Method>(vtable[2])(this, reinterpret_cast<CNMEncoder*>(storage), stream);
    FUN_14156bd50(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158db50: dispatches serialization according to the framing mode.
unsigned int CNMExecutePatcherFunc::EncodeDispatch(CNMEncoder* encoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (m_bFormat == 1) {
        using Method = unsigned int(__fastcall*)(CNMExecutePatcherFunc*, CNMEncoder*, CNMStream*);
        return reinterpret_cast<Method>(vtable[2])(this, encoder, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMExecutePatcherFunc*, CNMStream*);
    return reinterpret_cast<Method>(vtable[3])(this, stream);
}

// MS2-FUNCTIONAL 0x14158dbb0: encodes patch paths and numeric options in replies.
unsigned int CNMExecutePatcherFunc::Encode(CNMEncoder* encoder, CNMStream* stream)
{
    CNMFunc::EncodeDispatch(encoder, stream);
    if (FUN_1415fb700(this)) {
        FUN_14156ae30(encoder, m_szUrl);
        FUN_14156ae30(encoder, m_szPatchDir);
        FUN_14156ae30(encoder, m_szExecPath);
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_na00));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_na04));
        FUN_14156ac20(encoder, static_cast<unsigned int>(m_na08));
    }
    FUN_1415f9990(encoder);
    return 1;
}

// MS2-FUNCTIONAL 0x14158dc90: decodes a framed response.
unsigned int CNMExecutePatcherFunc::DecodeFramed(CNMStream* stream)
{
    unsigned char storage[0x38];
    FUN_14156be10(storage, stream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(storage)) {
        void** vtable = *reinterpret_cast<void***>(this);
        using Method = unsigned int(__fastcall*)(CNMExecutePatcherFunc*, CNMSerializableDecoder*, CNMStream*);
        result = reinterpret_cast<Method>(vtable[5])(this, reinterpret_cast<CNMSerializableDecoder*>(storage), stream);
    }
    FUN_14156bf10(storage);
    return result;
}

// MS2-FUNCTIONAL 0x14158dd20: dispatches decoding by response format.
unsigned int CNMExecutePatcherFunc::DecodeDispatch(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    void** vtable = *reinterpret_cast<void***>(this);
    if (FUN_1415fb6d0(decoder) == 2) {
        using Method = unsigned int(__fastcall*)(CNMExecutePatcherFunc*, CNMStream*);
        return reinterpret_cast<Method>(vtable[6])(this, stream);
    }
    using Method = unsigned int(__fastcall*)(CNMExecutePatcherFunc*, CNMSerializableDecoder*, CNMStream*);
    return reinterpret_cast<Method>(vtable[5])(this, decoder, stream);
}

// MS2-FUNCTIONAL 0x14158dd80: restores bounded output strings and three result values.
unsigned int CNMExecutePatcherFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        void** vtable = *reinterpret_cast<void***>(decoder);
        using ReadBytes = void(__fastcall*)(void*, void*, unsigned int);
        using ReadU32 = unsigned int(__fastcall*)(void*);
        reinterpret_cast<ReadBytes>(vtable[9])(decoder, m_szUrl, 0x100);
        reinterpret_cast<ReadBytes>(vtable[9])(decoder, m_szPatchDir, 0x100);
        reinterpret_cast<ReadBytes>(vtable[9])(decoder, m_szExecPath, 2000);
        m_na00 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
        m_na04 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
        m_na08 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(decoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(decoder));
}

// MS2-PIN: ??0CNMExecutePatcherFunc@@QEAA@XZ 0x14158d8f0
// MS2-PIN: ??0CNMExecutePatcherFunc@@QEAA@PEBD00HHH@Z 0x14158d9b0
// MS2-PIN: ?EncodeFramed@CNMExecutePatcherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158daf0
// MS2-PIN: ?EncodeDispatch@CNMExecutePatcherFunc@@UEAAIPEAVCNMEncoder@@PEAVCNMStream@@@Z 0x14158db50
// MS2-PIN: ?DecodeFramed@CNMExecutePatcherFunc@@UEAAIPEAVCNMStream@@@Z 0x14158dc90
// MS2-PIN: ?DecodeDispatch@CNMExecutePatcherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158dd20
// MS2-PIN: ?Decode@CNMExecutePatcherFunc@@UEAAIPEAVCNMSerializableDecoder@@PEAVCNMStream@@@Z 0x14158dd80
