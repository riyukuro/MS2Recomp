// Nexon Messenger get-note-box request serialization.
// MS2-UNIT: unit_14158a1e0
// MS2-RANGE: 0x14158a1e0-0x14158a810 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/placeholder/nmfunc.h"
#include "ms2/ms2recover.h"
extern void FUN_14156bcb0(void*,void*,void*);extern void FUN_14156bd50(void*);extern void FUN_14156be10(void*,void*,void*);extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*,unsigned int);extern void FUN_14156ab00(void*,unsigned int);extern void FUN_1415f9990(void*);extern int FUN_1415fb700(void*);extern int FUN_1415fb750(void*);extern int FUN_1415fb6d0(void*);
extern unsigned int FUN_14160bbb0(void*);
// MS2-FUNCTIONAL 0x14158a1e0: initializes default note-box filters and list.
// @0x14158a1e0
CNMGetNoteBoxFunc::CNMGetNoteBoxFunc():CNMFunc(0x6001,1,0,0),m_30(2),m_34(-1),m_38(0),m_40(),m_58(0){}
// MS2-FUNCTIONAL 0x14158a260: stores note-box type and index.
// @0x14158a260
CNMGetNoteBoxFunc::CNMGetNoteBoxFunc(int type,int index):CNMFunc(0x6001,1,0,0),m_30(type),m_34(index),m_38(0),m_40(),m_58(0){}
// MS2-FUNCTIONAL 0x14158a2f0: stores note-box type, index, and status.
// @0x14158a2f0
CNMGetNoteBoxFunc::CNMGetNoteBoxFunc(int type,int index,int status):CNMFunc(0x6001,1,0,0),m_30(type),m_34(index),m_38(status),m_40(),m_58(0){}
// MS2-FUNCTIONAL 0x14158a380: frames request and dispatches encoder slot.
// @0x14158a380
unsigned int CNMGetNoteBoxFunc::EncodeFramed(CNMStream*s){unsigned char b[0x18];FUN_14156bcb0(b,s,this);void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetNoteBoxFunc*,CNMEncoder*,CNMStream*);auto r=reinterpret_cast<F>(v[2])(this,reinterpret_cast<CNMEncoder*>(b),s);FUN_14156bd50(b);return r;}
// MS2-FUNCTIONAL 0x14158a3e0: selects raw or framed encoding by format.
// @0x14158a3e0
unsigned int CNMGetNoteBoxFunc::EncodeDispatch(CNMEncoder*e,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(m_bFormat==1){using F=unsigned int(__fastcall*)(CNMGetNoteBoxFunc*,CNMEncoder*,CNMStream*);return reinterpret_cast<F>(v[2])(this,e,s);}using F=unsigned int(__fastcall*)(CNMGetNoteBoxFunc*,CNMStream*);return reinterpret_cast<F>(v[3])(this,s);}
// MS2-FUNCTIONAL 0x14158a440: serializes note records in list direction or request fields in request direction.
// @0x14158a440
unsigned int CNMGetNoteBoxFunc::Encode(CNMEncoder*e,CNMStream*s){CNMFunc::EncodeDispatch(e,s);if(!FUN_1415fb700(this)){FUN_14156ac20(e,FUN_14160bbb0(&m_40));for(auto& item:m_40)item.EncodeFramed(s);FUN_14156ab00(e,m_58);}else{FUN_14156ab00(e,static_cast<unsigned char>(m_30));FUN_14156ac20(e,m_34);FUN_14156ac20(e,m_38);}FUN_1415f9990(e);return 1;}
// MS2-FUNCTIONAL 0x14158a570: decodes through a temporary framed decoder.
// @0x14158a570
unsigned int CNMGetNoteBoxFunc::DecodeFramed(CNMStream*s){unsigned char b[0x38];FUN_14156be10(b,s,this);unsigned int r=0;if(FUN_1415fb750(b)){void**v=*reinterpret_cast<void***>(this);using F=unsigned int(__fastcall*)(CNMGetNoteBoxFunc*,CNMSerializableDecoder*,CNMStream*);r=reinterpret_cast<F>(v[5])(this,reinterpret_cast<CNMSerializableDecoder*>(b),s);}FUN_14156bf10(b);return r;}
// MS2-FUNCTIONAL 0x14158a600: selects framed decoding for wire format 2.
// @0x14158a600
unsigned int CNMGetNoteBoxFunc::DecodeDispatch(CNMSerializableDecoder*d,CNMStream*s){void**v=*reinterpret_cast<void***>(this);if(FUN_1415fb6d0(d)==2){using F=unsigned int(__fastcall*)(CNMGetNoteBoxFunc*,CNMStream*);return reinterpret_cast<F>(v[6])(this,s);}using F=unsigned int(__fastcall*)(CNMGetNoteBoxFunc*,CNMSerializableDecoder*,CNMStream*);return reinterpret_cast<F>(v[5])(this,d,s);}
// MS2-FUNCTIONAL 0x14158a660: restores note list and status or the requested type/index fields.
// @0x14158a660
unsigned int CNMGetNoteBoxFunc::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    CNMFunc::DecodeDispatch(pDecoder, pStream);
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU8 = unsigned char(__fastcall*)(void*);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    if (!FUN_1415fb700(this)) {
        const unsigned int count = reinterpret_cast<ReadU32>(vtable[3])(pDecoder);
        m_40.clear();
        for (unsigned int i = 0; i < count; ++i) {
            CNMNoteInfo item;
            item.DecodeFramed(pStream);
            m_40.push_back(item);
        }
        m_58 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
    } else {
        m_30 = reinterpret_cast<ReadU8>(vtable[1])(pDecoder);
        m_34 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
        m_38 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    }
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}
// MS2-PIN: ??0CNMGetNoteBoxFunc@@QEAA@XZ 0x14158a1e0
