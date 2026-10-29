// Recovered from the Nexon Messenger client library: request session to another user.
// MS2-UNIT: unit_14159b760
// MS2-RANGE: 0x14159b760-0x14159c0c0 .text$mn
// MS2-PINS-BEGIN tplpin
// MS2-PINS-END tplpin
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
#include <utility>

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb720(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_1415fbe70(void*, unsigned int, const char*);

// MS2-FUNCTIONAL: recovered vector construction and field initialization; base constructor call width differs.
// @0x14159b760
CNMRequestSessionToOtherFunc::CNMRequestSessionToOtherFunc()
    : CNMFunc(0xa008, 1, 0, 0)
{
    m_30 = 0;
    m_34 = 2;
    m_38 = 0;
    m_3c.nLow = 0;
    m_3c.nHigh = 0;
    m_44[0] = '\0';
    m_84 = 0;
    m_a0 = 0;
    m_a4 = 0;
    m_a8 = 0;
}

// @0x14159b850
CNMRequestSessionToOtherFunc::CNMRequestSessionToOtherFunc(unsigned int n30, unsigned int n34, NMKey64 key,
                                                           const char* name, unsigned int n84,
                                                           const std::vector<CNMFilePath>& files)
    : CNMFunc(0xa008, 1, 0, 0), m_files()
{
    m_30 = n30;
    m_34 = n34;
    m_38 = 0;
    m_3c = key;
    if (name)
        FUN_1415fbe70(m_44, 0x40, name);
    else
        m_44[0] = '\0';
    m_84 = n84;
    m_files = files;
    m_a0 = 0;
    m_a4 = 0;
    m_a8 = 0;
}

// @0x14159b990
CNMRequestSessionToOtherFunc::CNMRequestSessionToOtherFunc(unsigned int n30, unsigned int n34, NMKey64 key,
                                                           const char* name, unsigned int n84, unsigned int nA0)
    : CNMFunc(0xa008, 1, 0, 0), m_files()
{
    m_30 = n30;
    m_34 = n34;
    m_38 = 0;
    m_3c = key;
    if (name)
        FUN_1415fbe70(m_44, 0x40, name);
    else
        m_44[0] = '\0';
    m_84 = n84;
    m_a0 = nA0;
    m_a4 = 0;
    m_a8 = 0;
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
// @0x14159bab0
unsigned int CNMRequestSessionToOtherFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMRequestSessionToOtherFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: recovered format branch; direct calls replace virtual dispatch.
// @0x14159bb10
unsigned int CNMRequestSessionToOtherFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMRequestSessionToOtherFunc::Encode(pEncoder, pStream);
    return CNMRequestSessionToOtherFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: request/reply branches and field order recovered; vector iteration uses source-level range iteration.
// @0x14159bb70
unsigned int CNMRequestSessionToOtherFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) == 0)
    {
        if (FUN_1415fb720(this) != 0)
        {
            FUN_14156ac20(pEncoder, m_a4);
            FUN_14156ac20(pEncoder, m_a8);
        }
    }
    else
    {
        FUN_14156ac20(pEncoder, m_30);
        FUN_14156ac20(pEncoder, m_34);
        FUN_14156ac20(pEncoder, m_38);
        FUN_14156ac20(pEncoder, m_3c.nLow);
        FUN_14156ac20(pEncoder, m_3c.nHigh);
        FUN_14156ae30(pEncoder, m_44);
        FUN_14156ac20(pEncoder, m_84);
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_files.size()));
        for (CNMFilePath& path : m_files)
            path.EncodeFramed(pStream);
        FUN_14156ac20(pEncoder, m_a0);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder wrapper lifetime and validity branch match; local decoder storage differs.
// @0x14159bd30
unsigned int CNMRequestSessionToOtherFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMRequestSessionToOtherFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: recovered decoder format branch; direct calls replace virtual dispatch.
// @0x14159bdc0
unsigned int CNMRequestSessionToOtherFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMRequestSessionToOtherFunc::DecodeFramed(pStream);
    return CNMRequestSessionToOtherFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: scalar fields and file-path vector recovered; vector helpers use standard container operations.
// @0x14159be20
unsigned int CNMRequestSessionToOtherFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        m_30 = pDecoder->ReadU32();
        m_34 = pDecoder->ReadU32();
        m_38 = pDecoder->ReadU32();
        m_3c.nLow = pDecoder->ReadU32();
        m_3c.nHigh = pDecoder->ReadU32();
        pDecoder->ReadStringBufAlias(m_44, 0x40);
        m_84 = pDecoder->ReadU32();
        {
            // One record is decoded into the same local each time and a copy is pushed (a failed decode keeps
            // the previous record's data).
            CNMFilePath path;
            unsigned int count = pDecoder->ReadU32();
            m_files.clear();
            for (unsigned int i = 0; i < count; ++i)
            {
                path.DecodeFramed(pStream);
                m_files.push_back(path);
            }
        }
        m_a0 = pDecoder->ReadU32();
    }
    else if (FUN_1415fb720(this) != 0)
    {
        m_a4 = pDecoder->ReadU32();
        m_a8 = pDecoder->ReadU32();
    }
    return FUN_1415fb750(pDecoder);
}
