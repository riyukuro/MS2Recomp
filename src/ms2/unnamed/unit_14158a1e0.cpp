// Nexon Messenger get-note-box request serialization.
// MS2-UNIT: unit_14158a1e0
// MS2-RANGE: 0x14158a1e0-0x14158a810 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*);extern void FUN_14156bd50(void*);extern void FUN_14156be10(void*,void*,void*);extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int);extern void FUN_14156ab00(void*,unsigned char);extern void FUN_1415f9990(void*);extern int FUN_1415fb700(void*);extern int FUN_1415fb750(void*);extern int FUN_1415fb6d0(CNMSerializableDecoder*);
extern unsigned int FUN_14160bbb0(void*);
// MS2-FUNCTIONAL 0x14158a1e0: initializes default note-box filters and list.
// @0x14158a1e0
CNMGetNoteBoxFunc::CNMGetNoteBoxFunc():CNMFunc(0x6001,1,0,0){m_30=2;m_34=-1;m_38=0;}
// MS2-FUNCTIONAL 0x14158a260: stores note-box type and index.
// @0x14158a260
CNMGetNoteBoxFunc::CNMGetNoteBoxFunc(int type,int index):CNMFunc(0x6001,1,0,0){m_30=type;m_34=index;m_38=0;}
// MS2-FUNCTIONAL 0x14158a2f0: stores note-box type, index, and status.
// @0x14158a2f0
CNMGetNoteBoxFunc::CNMGetNoteBoxFunc(int type,int index,int status):CNMFunc(0x6001,1,0,0){m_30=type;m_34=index;m_38=status;}
// MS2-FUNCTIONAL 0x14158a380: frames request and dispatches encoder slot.
// @0x14158a380
unsigned int CNMGetNoteBoxFunc::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMGetNoteBoxFunc::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}
// MS2-FUNCTIONAL 0x14158a3e0: selects raw or framed encoding by format.
// @0x14158a3e0
unsigned int CNMGetNoteBoxFunc::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMGetNoteBoxFunc::Encode(pEncoder, pStream);
    return CNMGetNoteBoxFunc::EncodeFramed(pStream);
}
// MS2-FUNCTIONAL 0x14158a440: serializes note records in list direction or request fields in request direction.
// @0x14158a440
unsigned int CNMGetNoteBoxFunc::Encode(CNMEncoder* e, CNMStream* s)
{
    CNMFunc::EncodeDispatch(e, s);
    if (FUN_1415fb700(this) != 0) {
        FUN_14156ab00(e, static_cast<unsigned char>(m_30));
        FUN_14156ac20(e, m_34);
        FUN_14156ac20(e, m_38);
    } else {
        FUN_14156ac20(e, FUN_14160bbb0(&m_40));
        for (auto& item : m_40)
            item.EncodeFramed(s);
        FUN_14156ab00(e, m_58);
    }
    FUN_1415f9990(e);
    return 1;
}
// MS2-FUNCTIONAL 0x14158a570: decodes through a temporary framed decoder.
// @0x14158a570
unsigned int CNMGetNoteBoxFunc::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMGetNoteBoxFunc::Decode(&decoder, pStream);
}
// MS2-FUNCTIONAL 0x14158a600: selects framed decoding for wire format 2.
// @0x14158a600
unsigned int CNMGetNoteBoxFunc::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMGetNoteBoxFunc::DecodeFramed(pStream);
    return CNMGetNoteBoxFunc::Decode(pDecoder, pStream);
}
// MS2-FUNCTIONAL 0x14158a660: restores note list and status or the requested type/index fields.
// @0x14158a660
unsigned int CNMGetNoteBoxFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    if (FUN_1415fb700(this) != 0) {
        m_30 = pDecoder->ReadU8();
        m_34 = pDecoder->ReadU32();
        m_38 = pDecoder->ReadU32();
    } else {
        // One record is decoded into the same local each time and a copy is pushed (a failed decode keeps
        // the previous record's data).
        {
            CNMNoteInfo item;
            unsigned int count = pDecoder->ReadU32();
            m_40.clear();
            for (unsigned int i = 0; i < count; ++i) {
                item.DecodeFramed(pStream);
                m_40.push_back(item);
            }
        }
        m_58 = pDecoder->ReadU8();
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}
// MS2-PIN: ??0CNMGetNoteBoxFunc@@QEAA@XZ 0x14158a1e0
