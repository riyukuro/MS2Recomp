// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CNMSendNoteExMsgFunc constructors and serialization.
// Its CNMNoteInfoEx payload is defined at +0x30 and owns the large fixed text buffer.
// MS2-UNIT: unit_141596980
// MS2-RANGE: 0x141596980-0x141596d50 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern int FUN_1415fb700(const void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern void FUN_1415f9990(void*);
extern void FUN_1415fbe70(void*, unsigned int, const char*);
extern void* FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);

// @0x141596980
CNMSendNoteExMsgFunc::CNMSendNoteExMsgFunc() : CNMFunc(0x9004, 1, 0, 0), m_note()
{
}

// @0x1415969f0
CNMSendNoteExMsgFunc::CNMSendNoteExMsgFunc(int nType, const char* szText)
    : CNMFunc(0x9004, 1, 0, 0), m_note()
{
    m_note.m_10 = nType;
    if (szText)
        FUN_1415fbe70(m_note.m_14, 0x800, szText);
    else
        *reinterpret_cast<unsigned int*>(m_note.m_14) = 0;
}

// MS2-FUNCTIONAL: framed encoder setup and cleanup are recovered; local encoder storage differs in frame layout.
// @0x141596aa0
unsigned int CNMSendNoteExMsgFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMSendNoteExMsgFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL: request format branch and selected serializer slot match; direct calls replace indirect dispatch.
// @0x141596b00
unsigned int CNMSendNoteExMsgFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMSendNoteExMsgFunc::Encode(pEncoder, pStream);
    return CNMSendNoteExMsgFunc::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL: base request fields, payload encoding and final marker are recovered.
// @0x141596b60
unsigned int CNMSendNoteExMsgFunc::Encode(CNMEncoder* pEncoder, CNMStream* pStream)
{
    CNMFunc::EncodeDispatch(pEncoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        using EncodeNote = unsigned int(__fastcall*)(void*, void*, void*);
        void** vftable = *reinterpret_cast<void***>(&m_note);
        reinterpret_cast<EncodeNote>(vftable[2])(&m_note, pEncoder, pStream);
    }
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL: decoder framing validation and payload decode are recovered; local decoder frame differs.
// @0x141596be0
unsigned int CNMSendNoteExMsgFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMSendNoteExMsgFunc::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL: the decoder's format discriminator selects the same framed or direct path.
// @0x141596c70
unsigned int CNMSendNoteExMsgFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMSendNoteExMsgFunc::DecodeFramed(pStream);
    return CNMSendNoteExMsgFunc::Decode(pDecoder, pStream);
}

// MS2-FUNCTIONAL: base decode, request payload branch and final decoder status are recovered.
// @0x141596cd0
unsigned int CNMSendNoteExMsgFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0)
    {
        using DecodeNote = unsigned int(__fastcall*)(void*, void*, void*);
        void** vftable = *reinterpret_cast<void***>(&m_note);
        reinterpret_cast<DecodeNote>(vftable[5])(&m_note, pDecoder, pStream);
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-PIN: ??0CNMSendNoteExMsgFunc@@QEAA@XZ 0x141596980
// MS2-PIN: ??0CNMSendNoteExMsgFunc@@QEAA@HPEBD@Z 0x1415969f0
