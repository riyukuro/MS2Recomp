// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13).
// MS2-UNIT: unit_1415a1970
// MS2-RANGE: 0x1415a1970-0x1415a1df0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern int FUN_1415fb720(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_1415f9990(void*);

// @0x1415a1970
// MS2-FUNCTIONAL: initializes the recovered 0xc201 request and its empty file-event list.
CNMFUDSGetFileEventFunc::CNMFUDSGetFileEventFunc()
    : CNMFunc(0xc201, 1, 0, 0), m_30()
{
}

// @0x1415a19d0
// MS2-FUNCTIONAL: preserves the serial key and initializes the empty event list.
CNMFUDSGetFileEventFunc::CNMFUDSGetFileEventFunc(unsigned int serial)
    : CNMFunc(0xc201, 1, static_cast<int>(serial), 0), m_30()
{
}

// @0x1415a1a30
// MS2-FUNCTIONAL: framed encoder setup and cleanup match; local encoder storage differs.
unsigned int CNMFUDSGetFileEventFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMFUDSGetFileEventFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// @0x1415a1a90
// MS2-FUNCTIONAL: preserves format dispatch; direct calls replace virtual slot dispatch.
unsigned int CNMFUDSGetFileEventFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMFUDSGetFileEventFunc::Encode(pEncoder, pStream);
    return CNMFUDSGetFileEventFunc::EncodeFramed(pStream);
}

// @0x1415a1af0
// MS2-FUNCTIONAL: writes the event count and serializes each file event in vector order.
unsigned int CNMFUDSGetFileEventFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb720(this) != 0)
    {
        FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_30.size()));
        for (auto& event : m_30)
            event.EncodeFramed(pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// @0x1415a1be0
// MS2-FUNCTIONAL: framed decoder setup, validity check, and cleanup match; local decoder storage differs.
unsigned int CNMFUDSGetFileEventFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMFUDSGetFileEventFunc::Decode(&decoder, pStream);
}

// @0x1415a1c70
// MS2-FUNCTIONAL: selects framed decoding for decoder format 2.
unsigned int CNMFUDSGetFileEventFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMFUDSGetFileEventFunc::DecodeFramed(pStream);
    return CNMFUDSGetFileEventFunc::Decode(pDecoder, pStream);
}

// @0x1415a1cd0
unsigned int CNMFUDSGetFileEventFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb720(this) != 0)
    {
        // One record is decoded into the same local each time and a copy is pushed (a failed decode keeps
        // the previous record's data).
        CNMFileEvent event;
        unsigned int count = pDecoder->ReadU32();
        m_30.clear();
        for (unsigned int i = 0; i < count; ++i)
        {
            event.DecodeFramed(pStream);
            m_30.push_back(event);
        }
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-PIN: ??0CNMFUDSGetFileEventFunc@@QEAA@XZ 0x1415a1970
