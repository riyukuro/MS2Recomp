// Recovered from the Nexon Messenger client library. CNMRequestFileUploadSessionExFunc constructors and serializers.
// MS2-UNIT: unit_141598e60
// MS2-RANGE: 0x141598e60-0x141599560 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <vector>
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb720(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned __int64);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// @0x141598e60
CNMRequestFileUploadSessionExFunc::CNMRequestFileUploadSessionExFunc()
    : CNMFunc(0xa00d, 1, 0, 0), m_30(0), m_38(0), m_3c(0), m_40(0), m_44(0), m_48(0), m_4c(0),
      m_files(), m_68(0), m_6c(0)
{
}

// MS2-FUNCTIONAL: vector payload is copied and request fields match; by-value cleanup codegen differs.
// @0x141598f10
CNMRequestFileUploadSessionExFunc::CNMRequestFileUploadSessionExFunc(
    const unsigned char* pTarget, unsigned int nTarget, std::vector<CNMFilePath> files)
    : CNMFunc(0xa00d, 1, 0, 0), m_30(0), m_38(0), m_3c(0), m_40(0), m_44(0), m_48(nTarget), m_4c(0),
      m_files(files), m_68(0), m_6c(0)
{
    *reinterpret_cast<unsigned __int64*>(&m_30) = *reinterpret_cast<const unsigned __int64*>(pTarget);
    *reinterpret_cast<unsigned __int64*>(&m_38) = *reinterpret_cast<const unsigned __int64*>(pTarget + 8);
    *reinterpret_cast<unsigned __int64*>(&m_40) = *reinterpret_cast<const unsigned __int64*>(pTarget + 16);
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs in frame layout.
// @0x141598fe0
unsigned int CNMRequestFileUploadSessionExFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRequestFileUploadSessionExFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace indirect virtual dispatch.
// @0x141599040
unsigned int CNMRequestFileUploadSessionExFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRequestFileUploadSessionExFunc::Encode(pEncoder, pStream);
    return CNMRequestFileUploadSessionExFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: request/reply field order and path serialization match; STL traversal codegen differs.
// @0x1415990a0
unsigned int CNMRequestFileUploadSessionExFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            FUN_14156ac20(pEncoder, m_68);
            FUN_14156ac20(pEncoder, m_6c);
        }
    }
    else
    {
        FUN_14156acb0(pEncoder, m_30);
        FUN_14156ac20(pEncoder, m_38);
        FUN_14156ac20(pEncoder, m_3c);
        FUN_14156ac20(pEncoder, m_40);
        FUN_14156ac20(pEncoder, m_44);
        FUN_14156ac20(pEncoder, m_48);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_files.size()));
        for (CNMFilePath& file : m_files)
            file.EncodeFramed(pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: framed decoder setup and cleanup match; local decoder storage differs in frame layout.
// @0x141599230
unsigned int CNMRequestFileUploadSessionExFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRequestFileUploadSessionExFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: framed decoder selection matches; direct dispatch replaces the indirect virtual call.
// @0x1415992c0
unsigned int CNMRequestFileUploadSessionExFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRequestFileUploadSessionExFunc::DecodeFramed(pStream);
    return CNMRequestFileUploadSessionExFunc::Decode(pDecoder, pStream);
}

// @0x141599320
unsigned int CNMRequestFileUploadSessionExFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_30 = pDecoder->ReadU64();
        m_38 = pDecoder->ReadU32();
        m_3c = pDecoder->ReadU32();
        m_40 = pDecoder->ReadU32();
        m_44 = pDecoder->ReadU32();
        m_48 = pDecoder->ReadU32();
        CNMFilePath file;
        const unsigned int count = pDecoder->ReadU32();
        m_files.clear();
        for (unsigned int i = 0; i < count; ++i)
        {
            file.DecodeFramed(pStream);
            m_files.push_back(file);
        }
    }
    else if (FUN_1415fb720(this) != 0)
    {
        m_68 = pDecoder->ReadU32();
        m_6c = pDecoder->ReadU32();
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMRequestFileUploadSessionExFunc@@QEAA@XZ 0x141598e60
// MS2-PIN: ??0CNMRequestFileUploadSessionExFunc@@QEAA@PEBEIV?$vector@VCNMFilePath@@V?$allocator@VCNMFilePath@@@std@@@std@@@Z 0x141598f10
