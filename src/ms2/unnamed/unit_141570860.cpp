// Nexon Messenger note serialization and record helpers; this first batch recovers the note list append helper.
// MS2-UNIT: unit_141570860
// MS2-RANGE: 0x141570860-0x1415722e0 .text$mn
#define MS2_THIS_FILE ""
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/placeholder/nmstream.h"
#include "ms2/placeholder/nmobjects.h"
#include "ms2/placeholder/nmencoder.h"
#include "ms2/ms2recover.h"

extern void FUN_14156bcb0(void*, void*, void*);
extern void FUN_14156bd50(void*);
extern void FUN_14156be10(void*, void*, void*);
extern void FUN_14156bf10(void*);
extern void FUN_14156ac20(void*, unsigned int);
extern void FUN_14156ae30(void*, const void*);
extern void FUN_1415f9990(void*);
extern int FUN_1415fb750(void*);
extern int FUN_1415fb6d0(CNMSerializableDecoder*);

extern bool FUN_141609910(void*);
extern void* FUN_1415f38c0(void*, long long);
extern void FUN_1415efdd0(void*, void*);
extern void FUN_14160b210(void*, void*);
extern void FUN_141608b60(void*);
extern void FUN_14156ab00(void*, unsigned char);
extern void FUN_14156ab90(void*, unsigned short);
extern void FUN_14156acb0(long long*, unsigned long long);
bool FUN_141572020(const std::vector<CNMCharacter>*, char*, unsigned int);
unsigned int FUN_141572110(const char*, std::vector<CNMCharacter>*, unsigned int);

// CNMCharacter::CNMCharacter: nmcharacter.cpp @0x141570010

// @0x141571fb0
void FUN_141571fb0(void* note, void* item)
{
    if (!FUN_141609910(static_cast<char*>(note) + 0xad0))
        FUN_1415efdd0(FUN_1415f38c0(static_cast<char*>(note) + 0xad0, 0), item);
    else
        FUN_14160b210(static_cast<char*>(note) + 0xad0, item);
}

// MS2-FUNCTIONAL 0x1415711f0: uses opaque stack storage for the temporary CNMEncoder; stream encode behavior is preserved.
// @0x1415711f0
unsigned int CNMNoteInfoEx::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMNoteInfoEx::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141571250: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x141571250
unsigned int CNMNoteInfoEx::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMNoteInfoEx::Encode(pEncoder, pStream);
    return CNMNoteInfoEx::EncodeFramed(pStream);
}

// @0x1415712b0
__declspec(noinline) unsigned int CNMNoteInfoEx::Encode(CNMEncoder* pEncoder, CNMStream*)
{
    FUN_14156ac20(pEncoder, static_cast<unsigned int>(m_10));
    FUN_14156ae30(pEncoder, m_14);
    FUN_1415f9990(pEncoder);
    return 1;
}

// MS2-FUNCTIONAL 0x141571310: uses opaque stack storage for the temporary decoder; decode behavior is preserved.
// @0x141571310
unsigned int CNMNoteInfoEx::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMNoteInfoEx::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x1415713a0: dispatches through the class vtable; the indirect call shape differs from the recovered image.
// @0x1415713a0
unsigned int CNMNoteInfoEx::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMNoteInfoEx::DecodeFramed(pStream);
    return CNMNoteInfoEx::Decode(pDecoder, pStream);
}

// @0x141571400
__declspec(noinline) unsigned int CNMNoteInfoEx::Decode(CNMSerializableDecoder* pDecoder, CNMStream*)
{
    void** vtable = *reinterpret_cast<void***>(pDecoder);
    using ReadU32 = unsigned int(__fastcall*)(void*);
    using ReadBytes = unsigned int(__fastcall*)(void*, void*, unsigned int);
    m_10 = static_cast<int>(reinterpret_cast<ReadU32>(vtable[3])(pDecoder));
    reinterpret_cast<ReadBytes>(vtable[9])(pDecoder, m_14, 0x8000);
    return static_cast<unsigned int>(FUN_1415fb750(pDecoder));
}

// MS2-FUNCTIONAL 0x141570860: initializes the note payload, nested avatar and fixed string buffers.
// @0x141570860
CNMNoteInfo::CNMNoteInfo() : CNMSerializable(0x6e69,1,1),m_10(0),m_14(0),m_18(0),m_1c{},m_24(0),m_28{},m_38{},m_438{},m_478{},m_4b8{},m_cb8{},m_db8{},m_eb8() {}

// MS2-FUNCTIONAL 0x141570b60: frames the note payload and closes the temporary encoder.
// @0x141570b60
unsigned int CNMNoteInfo::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMNoteInfo::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141570bc0: chooses framed or direct note encoding.
// @0x141570bc0
unsigned int CNMNoteInfo::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMNoteInfo::Encode(pEncoder, pStream);
    return CNMNoteInfo::EncodeFramed(pStream);
}

// MS2-FUNCTIONAL 0x141570c20: serializes note metadata, text fields and the embedded avatar.
// @0x141570c20
unsigned int CNMNoteInfo::Encode(CNMEncoder*e,CNMStream*s){FUN_14156ac20(e,m_10);FUN_14156ac20(e,m_14);FUN_14156ac20(e,m_18);FUN_14156ac20(e,m_1c.nLow);FUN_14156ac20(e,m_1c.nHigh);FUN_14156ab00(e,static_cast<unsigned char>(m_24));auto*t=reinterpret_cast<unsigned char*>(&m_28);FUN_14156ab90(e,*reinterpret_cast<unsigned short*>(t));for(int i:{2,6,8,10,12})FUN_14156ab00(e,t[i]);FUN_14156ae30(e,m_38);FUN_14156ae30(e,m_438);FUN_14156ae30(e,m_478);FUN_14156ae30(e,m_4b8);FUN_14156ae30(e,m_cb8);FUN_14156ae30(e,m_db8);m_eb8.EncodeFramed(s);FUN_1415f9990(e);return 1;}

// MS2-FUNCTIONAL 0x141570df0: decodes the framed note payload.
// @0x141570df0
unsigned int CNMNoteInfo::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMNoteInfo::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x141570e80: chooses framed or direct note decoding.
// @0x141570e80
unsigned int CNMNoteInfo::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMNoteInfo::DecodeFramed(pStream);
    return CNMNoteInfo::Decode(pDecoder, pStream);
}

// Decodes note metadata, strings and the embedded avatar.
// @0x141570ee0
unsigned int CNMNoteInfo::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    m_10 = pDecoder->ReadU32();
    m_14 = pDecoder->ReadU32();
    m_18 = pDecoder->ReadU32();
    m_1c.nLow = pDecoder->ReadU32();
    m_1c.nHigh = pDecoder->ReadU32();
    m_24 = pDecoder->ReadU8();
    m_28.wYear = pDecoder->ReadU16();
    m_28.wMonth = pDecoder->ReadU8();
    m_28.wDay = pDecoder->ReadU8();
    m_28.wHour = pDecoder->ReadU8();
    m_28.wMinute = pDecoder->ReadU8();
    m_28.wSecond = pDecoder->ReadU8();
    pDecoder->ReadStringBufAlias(m_38, 0x400);
    pDecoder->ReadStringBufAlias(m_438, 0x40);
    pDecoder->ReadStringBufAlias(m_478, 0x40);
    pDecoder->ReadStringBufAlias(m_4b8, 0x800);
    pDecoder->ReadStringBufAlias(m_cb8, 0x100);
    pDecoder->ReadStringBufAlias(m_db8, 0x100);
    m_eb8.DecodeFramed(pStream);
    return FUN_1415fb750(pDecoder);
}

// MS2-FUNCTIONAL 0x141571190: initializes the secondary note record with its owning serializable type.
// @0x141571190
CNMNoteInfoEx::CNMNoteInfoEx() : CNMSerializable(0x6e65,1,1),m_10(0),m_14{},m_8014(0) {}

// MS2-FUNCTIONAL 0x141571470: initializes the note-box record, embedded character and character vector.
// @0x141571470
CNMNoteInfo2::CNMNoteInfo2() : CNMSerializable(0x6e32,1,1),m_10(0),m_14(0),m_18(0),m_1c{},m_2c(0),m_30(0),m_34{},m_834{},m_934{},m_a38(),m_aCharacters{} {}

// MS2-FUNCTIONAL 0x1415718a0: frames the note-box payload.
// @0x1415718a0
unsigned int CNMNoteInfo2::EncodeFramed(CNMStream* pStream)
{
    CNMSerializableEncoder encoder(pStream, this);
    return CNMNoteInfo2::Encode(reinterpret_cast<CNMEncoder*>(&encoder), pStream);
}

// MS2-FUNCTIONAL 0x141571900: selects framed or direct note-box encoding.
// @0x141571900
unsigned int CNMNoteInfo2::EncodeDispatch(CNMEncoder* pEncoder, CNMStream* pStream)
{
    if (m_bFormat == 1)
        return CNMNoteInfo2::Encode(pEncoder, pStream);
    return CNMNoteInfo2::EncodeFramed(pStream);
}

// Serializes the note-box fields and each embedded character.
// @0x141571960
unsigned int CNMNoteInfo2::Encode(CNMEncoder* e, CNMStream* s)
{
    FUN_14156ac20(e, m_10);
    FUN_14156ac20(e, m_14);
    FUN_14156ac20(e, m_18);
    FUN_14156ab90(e, m_1c.wYear);
    FUN_14156ab00(e, static_cast<unsigned char>(m_1c.wMonth));
    FUN_14156ab00(e, static_cast<unsigned char>(m_1c.wDay));
    FUN_14156ab00(e, static_cast<unsigned char>(m_1c.wHour));
    FUN_14156ab00(e, static_cast<unsigned char>(m_1c.wMinute));
    FUN_14156ab00(e, static_cast<unsigned char>(m_1c.wSecond));
    FUN_14156ab00(e, static_cast<unsigned char>(m_2c));
    FUN_14156ab00(e, static_cast<unsigned char>(m_30));
    FUN_14156ae30(e, m_34);
    FUN_14156ae30(e, m_834);
    FUN_14156ae30(e, m_934);
    (&m_a38)->EncodeFramed(s);
    FUN_14156ac20(e, static_cast<unsigned int>(m_aCharacters.size()));
    for (std::vector<CNMCharacter>::iterator it = m_aCharacters.begin(), itEnd = m_aCharacters.end(); it != itEnd; ++it)
        it->EncodeFramed(s);
    FUN_1415f9990(e);
    return 1;
}

// MS2-FUNCTIONAL 0x141571b70: decodes the framed note-box payload.
// @0x141571b70
unsigned int CNMNoteInfo2::DecodeFramed(CNMStream* pStream)
{
    CNMSerializableDecoder decoder(pStream, this);
    if (FUN_1415fb750(&decoder) == 0)
        return 0;
    return CNMNoteInfo2::Decode(&decoder, pStream);
}

// MS2-FUNCTIONAL 0x141571c00: chooses direct or framed note-box decoding.
// @0x141571c00
unsigned int CNMNoteInfo2::DecodeDispatch(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    if (FUN_1415fb6d0(pDecoder) == 2)
        return CNMNoteInfo2::DecodeFramed(pStream);
    return CNMNoteInfo2::Decode(pDecoder, pStream);
}

// Reads note-box fields, its primary character and the character list.
// @0x141571c60
unsigned int CNMNoteInfo2::Decode(CNMSerializableDecoder* pDecoder, CNMStream* pStream)
{
    m_10 = pDecoder->ReadU32();
    m_14 = pDecoder->ReadU32();
    m_18 = pDecoder->ReadU32();
    m_1c.wYear = pDecoder->ReadU16();
    m_1c.wMonth = pDecoder->ReadU8();
    m_1c.wDay = pDecoder->ReadU8();
    m_1c.wHour = pDecoder->ReadU8();
    m_1c.wMinute = pDecoder->ReadU8();
    m_1c.wSecond = pDecoder->ReadU8();
    m_2c = pDecoder->ReadU8();
    m_30 = pDecoder->ReadU8();
    pDecoder->ReadStringBufAlias(m_34, 0x800);
    pDecoder->ReadStringBufAlias(m_834, 0x100);
    pDecoder->ReadStringBufAlias(m_934, 0x100);
    m_a38.DecodeFramed(pStream);
    {
        CNMCharacter character;
        unsigned int nCount = pDecoder->ReadU32();
        FUN_141608b60(&m_aCharacters);
        for (unsigned int i = 0; i < nCount; i++)
        {
            character.DecodeFramed(pStream);
            FUN_14160b210(&m_aCharacters, &character);
        }
    }
    return FUN_1415fb750(pDecoder);
}

// MS2-FUNCTIONAL 0x1415709a0: converts the note-box text and fields into a note payload.
// @0x1415709a0
CNMNoteInfo::CNMNoteInfo(const CNMNoteInfo2& r) : CNMNoteInfo(){m_10=r.m_10;m_14=r.m_14;m_18=r.m_18;m_1c.nLow=r.m_1c.wYear;m_1c.nHigh=r.m_1c.wMonth;m_24=r.m_2c;memcpy(&m_28,&r.m_1c,0x10);memcpy(m_38,r.m_34,0x400);memcpy(m_438,r.m_834,0x40);memcpy(m_478,r.m_934,0x40);memcpy(m_4b8,r.m_34,0x800);memcpy(m_cb8,r.m_834,0x100);memcpy(m_db8,r.m_934,0x100);FUN_141572020(&r.m_aCharacters,m_38,0x400);}

// MS2-FUNCTIONAL 0x141571580: builds a note-box value from the base note and tokenizes its character string.
// @0x141571580
CNMNoteInfo2::CNMNoteInfo2(const CNMNoteInfo& r) : CNMSerializable(0x6e32,1,1),m_10(r.m_10),m_14(r.m_14),m_18(r.m_18),m_1c(r.m_28),m_2c(0),m_30(0),m_34{},m_834{},m_934{},m_a38(),m_aCharacters{} {memcpy(m_34,r.m_4b8,0x800);memcpy(m_834,r.m_cb8,0x100);memcpy(m_934,r.m_db8,0x100);memcpy(reinterpret_cast<char*>(&m_a38)+0x38,r.m_438,0x40);m_a38.m_50.nLow=r.m_1c.nLow;m_a38.m_50.nHigh=r.m_1c.nHigh;memcpy(reinterpret_cast<char*>(&m_a38)+0x58,r.m_478,0x40);FUN_141572110(r.m_38,&m_aCharacters,r.m_1c.nLow);}

// MS2-FUNCTIONAL 0x141571730: copies the fixed fields and rebuilds the note character vector.
// @0x141571730
long long FUN_141571730(long long dst,long long src){auto*d=reinterpret_cast<CNMNoteInfo2*>(dst);auto*s=reinterpret_cast<CNMNoteInfo*>(src);d->m_10=s->m_10;d->m_14=s->m_14;d->m_18=s->m_18;d->m_1c=s->m_28;d->m_2c=0;d->m_30=0;memcpy(d->m_34,s->m_4b8,0x800);memcpy(d->m_834,s->m_cb8,0x100);memcpy(d->m_934,s->m_db8,0x100);memcpy(reinterpret_cast<char*>(&d->m_a38)+0x38,s->m_438,0x40);d->m_a38.m_50=s->m_1c;memcpy(reinterpret_cast<char*>(&d->m_a38)+0x58,s->m_478,0x40);d->m_aCharacters.clear();FUN_141572110(s->m_38,&d->m_aCharacters,s->m_1c.nLow);return dst;}

// MS2-FUNCTIONAL 0x141572020: joins character names into the bounded separator-delimited note string.
// @0x141572020
bool FUN_141572020(const std::vector<CNMCharacter>* chars,char* out,unsigned int cap){if(!out||!cap)return false;out[0]=0;size_t used=0;for(const auto&c:*chars){if(used&&used+1<cap)out[used++]=';';const size_t left=cap-used-1;const size_t n=strnlen(c.m_10,left);memcpy(out+used,c.m_10,n);used+=n;out[used]=0;if(used+1>=cap)break;}return used!=0;}

// MS2-FUNCTIONAL 0x141572110: splits the separator-delimited note string into character records.
// @0x141572110
unsigned int FUN_141572110(const char* text,std::vector<CNMCharacter>* chars,unsigned int id){chars->clear();if(!text)return 0;const char*cur=text;while(*cur){const char*end=strchr(cur,';');const size_t n=end?static_cast<size_t>(end-cur):strlen(cur);chars->emplace_back();auto&c=chars->back();memcpy(c.m_58,cur,(n<sizeof(c.m_58)-1?n:sizeof(c.m_58)-1));c.m_50.nLow=id;cur=end?end+1:cur+n;}return static_cast<unsigned int>(chars->size());}

// MS2-PIN: ??0CNMNoteInfo@@QEAA@XZ 0x141570860 ; recovered default note constructor
// MS2-PIN: ??0CNMNoteInfo@@QEAA@AEBVCNMNoteInfo2@@@Z 0x1415709a0 ; note-box conversion constructor
// MS2-PIN: ??0CNMNoteInfoEx@@QEAA@XZ 0x141571190 ; recovered extended-note constructor
// MS2-PIN: ??0CNMNoteInfo2@@QEAA@XZ 0x141571470 ; recovered note-box constructor
// MS2-PIN: ??0CNMNoteInfo2@@QEAA@AEBVCNMNoteInfo@@@Z 0x141571580 ; note conversion constructor
