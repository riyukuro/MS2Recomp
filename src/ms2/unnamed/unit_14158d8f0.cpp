// Nexon Messenger execute-patcher request serialization.
// MS2-UNIT: unit_14158d8f0
// MS2-RANGE: 0x14158d8f0-0x14158deb0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
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
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

// Empty execute-patcher request: the three paths are terminated at [0] only, and m_na0c is left unset.
// @0x14158d8f0
CNMExecutePatcherFunc::CNMExecutePatcherFunc()
    : CNMFunc(0x8001, 1, 0, 0)
{
    m_szUrl[0] = 0;
    m_szPatchDir[0] = 0;
    m_szExecPath[0] = 0;
    m_na00 = 1;
    m_na04 = 0;
    m_na08 = 0;
}

// Copies the three bounded paths (an empty string for a null one) and stores the options. m_na0c is left unset.
// @0x14158d9b0
CNMExecutePatcherFunc::CNMExecutePatcherFunc(const char* url, const char* patchDir, const char* execPath,
                                             int n4, int n5, int n6)
    : CNMFunc(0x8001, 1, 0, 0)
{
    if (url)
        FUN_1415fbe70(m_szUrl, 0x100, url);
    else
        m_szUrl[0] = 0;
    if (patchDir)
        FUN_1415fbe70(m_szPatchDir, 0x100, patchDir);
    else
        m_szPatchDir[0] = 0;
    if (execPath)
        FUN_1415fbe70(m_szExecPath, 2000, execPath);
    else
        m_szExecPath[0] = 0;
    m_na00 = n4;
    m_na04 = n5;
    m_na08 = n6;
}

// MS2-FUNCTIONAL 0x14158daf0: frames a serialized request.
unsigned int CNMExecutePatcherFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMExecutePatcherFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x14158db50: dispatches serialization according to the framing mode.
unsigned int CNMExecutePatcherFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMExecutePatcherFunc::Encode(pEncoder, pStream);
    return CNMExecutePatcherFunc::EncodeFramed(pStream);
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
unsigned int CNMExecutePatcherFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMExecutePatcherFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x14158dd20: dispatches decoding by response format.
unsigned int CNMExecutePatcherFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMExecutePatcherFunc::DecodeFramed(pStream);
    return CNMExecutePatcherFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL 0x14158dd80: restores bounded output strings and three result values.
unsigned int CNMExecutePatcherFunc::Decode(CNMSerializableDecoder* decoder, CNMStream* stream)
{
    CNMFunc::DecodeDispatch(decoder, stream);
    if (FUN_1415fb700(this)) {
        decoder->ReadStringBufAlias(m_szUrl, 0x100);
        decoder->ReadStringBufAlias(m_szPatchDir, 0x100);
        decoder->ReadStringBufAlias(m_szExecPath, 2000);
        m_na00 = decoder->ReadU32();
        m_na04 = decoder->ReadU32();
        m_na08 = decoder->ReadU32();
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
