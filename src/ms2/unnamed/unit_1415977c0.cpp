// Recovered from the Nexon Messenger client library. CNMRequestFileUploadSessionFunc constructors and serializers.
// MS2-UNIT: unit_1415977c0
// MS2-RANGE: 0x1415977c0-0x141597e50 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include <vector>
#include "ms2/placeholder/nmobjects.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb720(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(void*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156acb0(void*, unsigned __int64);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// @0x1415977c0
CNMRequestFileUploadSessionFunc::CNMRequestFileUploadSessionFunc()
    : CNMFunc(0xa003, 1, 0, 0), m_30(0), m_38(0), m_3c(0), m_40(0), m_48(), m_60(0), m_64(0)
{
}

// MS2-FUNCTIONAL: vector payload is copied and the request fields match; by-value cleanup codegen differs.
// @0x141597860
CNMRequestFileUploadSessionFunc::CNMRequestFileUploadSessionFunc(
    const unsigned char* pTarget, unsigned int nTarget, std::vector<CNMFilePath> files)
    : CNMFunc(0xa003, 1, 0, 0), m_30(0), m_38(0), m_3c(0), m_40(nTarget), m_48(files), m_60(0), m_64(0)
{
    *reinterpret_cast<unsigned __int64*>(&m_30) = *reinterpret_cast<const unsigned __int64*>(pTarget);
    *reinterpret_cast<unsigned __int64*>(reinterpret_cast<unsigned char*>(&m_30) + 8) =
        *reinterpret_cast<const unsigned __int64*>(pTarget + 8);
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs in frame layout.
// @0x141597930
unsigned int CNMRequestFileUploadSessionFunc::EncodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char encoder[0x18];
    FUN_14156bcb0(encoder, pStream, this);
    const unsigned int result = Encode(reinterpret_cast<CNMEncoder*>(encoder), pStream);
    FUN_14156bd50(encoder);
    return result;
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace indirect virtual dispatch.
// @0x141597990
unsigned int CNMRequestFileUploadSessionFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        Encode(pEncoder, pStream);
    else
        EncodeFramed(pStream);
    return 0;
}

// MS2-FUNCTIONAL: field order and file path serializers match; STL traversal codegen differs from the library.
// @0x1415979f0
unsigned int CNMRequestFileUploadSessionFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            FUN_14156ac20(pEncoder, m_60);
            FUN_14156ac20(pEncoder, m_64);
        }
    }
    else
    {
        FUN_14156acb0(pEncoder, m_30);
        FUN_14156ac20(pEncoder, m_38);
        FUN_14156ac20(pEncoder, m_3c);
        FUN_14156ac20(pEncoder, m_40);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_48.size()));
        for (CNMFilePath& file : m_48)
            file.EncodeFramed(pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: framed decoder setup and cleanup match; local decoder storage differs in frame layout.
// @0x141597b60
unsigned int CNMRequestFileUploadSessionFunc::DecodeFramed(CNMStream* pStream)
{
    alignas(8) unsigned char decoder[0x38];
    FUN_14156bcb0(decoder, pStream, this);
    unsigned int result = 0;
    if (FUN_1415fb750(decoder) != 0)
        result = Decode(reinterpret_cast<CNMSerializableDecoder*>(decoder), pStream);
    FUN_14156bd50(decoder);
    return result;
}

// MS2-FUNCTIONAL: framed decoder selection matches; direct dispatch replaces the indirect virtual call.
// @0x141597bf0
unsigned int CNMRequestFileUploadSessionFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        DecodeFramed(pStream);
    else
        Decode(pDecoder, pStream);
    return 0;
}

// MS2-FUNCTIONAL: field order, vector clear, and decoded file paths match; STL growth codegen differs.
// @0x141597c50
unsigned int CNMRequestFileUploadSessionFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            using ReadU32 = unsigned int(__fastcall*)(void*);
            void** vftable = *reinterpret_cast<void***>(pDecoder);
            m_60 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
            m_64 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        }
    }
    else
    {
        using ReadU32 = unsigned int(__fastcall*)(void*);
        using ReadU64 = unsigned __int64(__fastcall*)(void*);
        void** vftable = *reinterpret_cast<void***>(pDecoder);
        m_30 = reinterpret_cast<ReadU64>(vftable[4])(pDecoder);
        m_38 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        m_3c = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        m_40 = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        const unsigned int count = reinterpret_cast<ReadU32>(vftable[3])(pDecoder);
        m_48.clear();
        for (unsigned int i = 0; i != count; ++i)
        {
            CNMFilePath file;
            file.DecodeFramed(pStream);
            m_48.push_back(file);
        }
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMRequestFileUploadSessionFunc@@QEAA@XZ 0x1415977c0
// MS2-PIN: ??0CNMRequestFileUploadSessionFunc@@QEAA@PEBEIV?$vector@VCNMFilePath@@V?$allocator@VCNMFilePath@@@std@@@std@@@Z 0x141597860
