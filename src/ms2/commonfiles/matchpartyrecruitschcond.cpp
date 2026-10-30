// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The party-recruit search condition (the class the search
// dialog pages through) and the recruit record it returns. The class is the twin of CBlackMarketSchCond
// (0x1401be4a0-0x1401bef60), which has the same layout, the same function set and the same bodies, so that class's
// PDB names give the roles here: Reset, CopyFrom, IsEqual, Write, Read, WriteStream, ReadStream, GetLevelBand,
// GetBandMin, GetBandMax, GetLimit. Only the three functions a done unit already calls out of line
// (FUN_1406943b0 / FUN_140694630 / FUN_140695080) plus the member set of CMatchPartyRecruit keep a FUN_ name.
// MS2-UNIT: ?\matchpartyrecruitschcond.cpp
// MS2-RANGE: 0x1406943b0-0x140695130 .text$mn
// MS2-PIN: ??1CMatchPartyRecruitSchCond@@UEAA@XZ 0x140694410 ; empty user body
// MS2-PIN: ??_GCMatchPartyRecruit@@UEAAPEAXI@Z 0x1406950b0 ; prop
// MS2-PIN: ??_GCMatchPartyRecruitSchCond@@UEAAPEAXI@Z 0x1406950f0 ; prop
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\matchpartyrecruitschcond.cpp"

#include "ms2/placeholder/ms2stdafx.h"

#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/cmatchpartyrecruit.h"
#include "ms2/commonfiles/stream.h"
#include "ms2/ms2recover.h"

// The exe reads the search request's byte-typed kind as a 4-byte integer (FUN_140694b70 loads a dword at +8), so the
// same offset is accessed as an int here. It is a macro because /Od emits even a __forceinline helper as a call.
#define KindOf(p) (*reinterpret_cast<int*>(const_cast<unsigned char*>(&(p)->kind)))

// Defined further down, in exe order.
void FUN_140694450(CMatchPartyRecruitSchCond* pThis);                                    // Reset
void FUN_1406946b0(const CMatchPartyRecruitSchCond* pThis, COutputStream* out);          // WriteStream
void FUN_140694770(CMatchPartyRecruitSchCond* pThis, CInputStream* in);                  // ReadStream
void FUN_140694c60(const CMatchPartyRecruit* pThis, COutputStream* out);                 // WriteStream
void FUN_140694dc0(CMatchPartyRecruit* pThis, CInputStream* in);                         // ReadStream

// ---- CMatchPartyRecruitSchCond ---------------------------------------------------------------------------------------

// The constructor: base constructor, vftable store and default construction of the search text, then Reset. The
// search dialog allocates 0x38 bytes and calls it through its FUN_1406943b0 extern (the same VA; a constructor returns
// this in rax, so the factory-shaped declaration is ABI-identical).
// @0x1406943b0
CMatchPartyRecruitSchCond::CMatchPartyRecruitSchCond()
{
    FUN_140694450(this);
}

// The exe's destructor stores the vftable before destroying the search text, so it is user-declared with an empty
// body.
// @0x140694410
CMatchPartyRecruitSchCond::~CMatchPartyRecruitSchCond()
{
}

// @0x140694450
void FUN_140694450(CMatchPartyRecruitSchCond* pThis)
{
    pThis->fieldId = 0;
    pThis->category = 0;
    pThis->kind = 0xc;
    pThis->text.Empty();
    pThis->page = 0;
    pThis->pageSize = 0;
}

// @0x1406944c0
void FUN_1406944c0(CMatchPartyRecruitSchCond* pThis, const CMatchPartyRecruitSchCond* pOther)
{
    FUN_140694450(pThis);
    if (pOther == 0)
        return;
    pThis->fieldId = pOther->fieldId;
    pThis->category = pOther->category;
    pThis->kind = pOther->kind;
    pThis->text = pOther->text;
    pThis->page = pOther->page;
    pThis->pageSize = pOther->pageSize;
}

// @0x140694560  IsEqual
int FUN_140694560(const CMatchPartyRecruitSchCond* pThis, const CMatchPartyRecruitSchCond* pOther)
{
    if (pOther == 0)
        return 0;
    if (pOther->fieldId != pThis->fieldId)
        return 0;
    if (pOther->category != pThis->category)
        return 0;
    if (pOther->kind != pThis->kind)
        return 0;
    if (pOther->text != pThis->text)
        return 0;
    if (pOther->page != pThis->page)
        return 0;
    if (pOther->pageSize != pThis->pageSize)
        return 0;
    return 1;
}

// @0x140694630  Write
void FUN_140694630(const CMatchPartyRecruitSchCond* pThis, COutputStream& out)
{
    FUN_1406946b0(pThis, &out);
}

// @0x140694660  Read: the packet's stream subobject is at +8.
void FUN_140694660(CMatchPartyRecruitSchCond* pThis, CInPacket* pPacket)
{
    FUN_140694770(pThis, pPacket);
}

// @0x1406946b0
void FUN_1406946b0(const CMatchPartyRecruitSchCond* pThis, COutputStream* out)
{
    out->WriteInt32(pThis->fieldId);
    out->WriteInt32(pThis->category);
    out->WriteUInt8(pThis->kind);
    out->WriteUnicodeString(pThis->text);
    out->WriteInt32(pThis->page);
    out->WriteInt32(pThis->pageSize);
}

// @0x140694770
void FUN_140694770(CMatchPartyRecruitSchCond* pThis, CInputStream* in)
{
    pThis->fieldId = in->ReadInt32();
    pThis->category = in->ReadInt32();
    pThis->kind = in->ReadUInt8();
    pThis->text = in->ReadUnicodeString();
    pThis->page = in->ReadInt32();
    pThis->pageSize = in->ReadInt32();
}

// The page that holds the search condition is never page 0, which is what every band helper tests first. A band holds
// 10 pages of 12 entries, and GetLimit a 30-page block of them (350 entries in the black-market twin's spelling).
// Every one of them keeps its page difference, its band and its entry count in named locals, which is what the exe's
// spilled stack slots show.
// @0x140694860  GetLevelBand
int FUN_140694860(const CMatchPartyRecruitSchCond* pThis)
{
    if (pThis->page == 0)
        return -1;
    int nPage = pThis->page - 1;
    int nBand = nPage / 10;
    return nBand;
}

// @0x1406948b0  GetBandMin
int FUN_1406948b0(const CMatchPartyRecruitSchCond* pThis)
{
    int nBand = FUN_140694860(pThis);
    if (nBand == -1)
        return 0;
    int nPerPage = 12;
    int nPerBand = nPerPage * 10;
    int nResult = nBand * nPerBand + 1;
    return nResult;
}

// @0x140694910  GetBandMax
int FUN_140694910(const CMatchPartyRecruitSchCond* pThis)
{
    int nBand = FUN_140694860(pThis);
    if (nBand == -1)
        return 0;
    int nPerPage = 12;
    int nPerBand = nPerPage * 10;
    int nResult = (nBand + 1) * nPerBand;
    return nResult;
}

// @0x140694970  GetLimit
int FUN_140694970(const CMatchPartyRecruitSchCond* pThis)
{
    if (pThis->page == 0)
        return -1;
    int nPage = pThis->page - 1;
    int nBlock = nPage / 30;
    int nPerPage = 12;
    int nPerBlock = nPerPage * 30;
    int nResult = (nBlock + 1) * nPerBlock;
    return nResult;
}

// ---- CMatchPartyRecruit ---------------------------------------------------------------------------------------------

// @0x1406949e0
CMatchPartyRecruit::CMatchPartyRecruit()
{
    FUN_140694ab0();
}

// @0x140694a50
CMatchPartyRecruit::~CMatchPartyRecruit()
{
}

// @0x140694ab0
void CMatchPartyRecruit::FUN_140694ab0()
{
    recruitId = 0;
    fieldId = 0;
    category = 0;
    kind = 0;
    title.Empty();
    minimumLevel = 0;
    maximumLevel = 0;
    members = 0;
    ownerId = 0;
    created = 0;
    ownerName.Empty();
    flags = 0;
}

// Fills in the members the search request carries (the recruit id and the owner stay at their Reset values).
// @0x140694b70
void FUN_140694b70(CMatchPartyRecruit* pThis, const Unk_PartyRecruitRequest* pRequest)
{
    pThis->category = 0;
    pThis->kind = 0;
    pThis->title = pRequest->title;
    pThis->minimumLevel = KindOf(pRequest);
    pThis->members = pRequest->fieldId;
}

// @0x140694be0  Write
void FUN_140694be0(const CMatchPartyRecruit* pThis, COutputStream& out)
{
    FUN_140694c60(pThis, &out);
}

// @0x140694c10
void CMatchPartyRecruit::FUN_140694c10(CInPacket& packet)
{
    FUN_140694dc0(this, &packet);
}

// @0x140694c60
void FUN_140694c60(const CMatchPartyRecruit* pThis, COutputStream* out)
{
    out->WriteInt64(pThis->recruitId);
    out->WriteInt32(pThis->fieldId);
    out->WriteInt32(pThis->category);
    out->WriteInt32(pThis->kind);
    out->WriteUnicodeString(pThis->title);
    out->WriteUInt8(pThis->minimumLevel);
    out->WriteInt32(pThis->maximumLevel);
    out->WriteInt32(pThis->members);
    out->WriteInt64(pThis->ownerId);
    out->WriteInt64(pThis->created);
    out->WriteUnicodeString(pThis->ownerName);
    out->WriteInt64(pThis->flags);
}

// @0x140694dc0
void FUN_140694dc0(CMatchPartyRecruit* pThis, CInputStream* in)
{
    pThis->recruitId = in->ReadInt64();
    pThis->fieldId = in->ReadInt32();
    pThis->category = in->ReadInt32();
    pThis->kind = in->ReadInt32();
    pThis->title = in->ReadUnicodeString();
    pThis->minimumLevel = in->ReadUInt8();
    pThis->maximumLevel = in->ReadInt32();
    pThis->members = in->ReadInt32();
    pThis->ownerId = in->ReadInt64();
    pThis->created = in->ReadInt64();
    pThis->ownerName = in->ReadUnicodeString();
    pThis->flags = in->ReadInt64();
}

// The exe's body returns nothing (its `ret` exposes the last field copy's this pointer) and the callers ignore the
// result, so it is declared void.
// @0x140694f70
void CMatchPartyRecruit::FUN_140694f70(const CMatchPartyRecruit& other)
{
    if (&other == 0)
        return;
    recruitId = other.recruitId;
    fieldId = other.fieldId;
    category = other.category;
    kind = other.kind;
    title = other.title;
    minimumLevel = other.minimumLevel;
    maximumLevel = other.maximumLevel;
    members = other.members;
    ownerId = other.ownerId;
    created = other.created;
    ownerName = other.ownerName;
    flags = other.flags;
}

// @0x140695080  IsEmpty: a recruit without an id is an empty slot.
int FUN_140695080(const CMatchPartyRecruit* pThis)
{
    return pThis->recruitId == 0 ? 1 : 0;
}
