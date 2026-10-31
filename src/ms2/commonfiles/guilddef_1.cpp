// Guild wire records and synchronized guild state (first recovered chunk).
// MS2-UNIT: commonfiles\guilddef.cpp#1
// MS2-RANGE: 0x1404c5c80-0x1404d4180 .text$mn
// MS2-FUNCTIONAL: chunk written as near-literal Ghidra translation (opaque container blobs); 79 of 283 functions differ in bytes only.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\guilddef.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "guilddef_1.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
#include "guilddef_2.h"
#include "seasondatatable.h"
#include "fielddata.h"
#include "commonstringtable.h"
#include "ms2/placeholder/cguildxmldata.h"
#include <algorithm>
#define MS2_ASSERT_MSG_AT(line, msg, cond) (void)((!!(cond)) || (_wassert(msg, _CRT_WIDE(MS2_THIS_FILE), (unsigned)(line)), 0))
__time64_t GetServerTime();
int IsNotRecentDayChange(__int64);
// ---- helpers of the guild containers/smart pointers: defined in neighbouring chunks, reached by address ----
void* FUN_1404f4540();
// CGuildMember map (CGuildInfo+0x320, key = name)
void* FUN_1404f4510(void* map); Unk_GuildRef* FUN_1404f4f70(void* map,void* pos); void FUN_1404f4700(void* map,void** pos);
unsigned FUN_1404f44b0(void* map);
bool FUN_1404f6070(void* map,const wchar_t* key,Unk_GuildRef* out);
void FUN_1404f91b0(void* map,const wchar_t* key);
void FUN_1404f9ae0(void* map,const wchar_t* key,Unk_GuildRef* v);
char FUN_1404f6070(void* map,const wchar_t* key,MS2Ptr<CGuildMember>& out);
char FUN_1404f5f60(void* map,int key,MS2Ptr<CGuildSkill>& out);
char FUN_1404f5ef0(void* map,int key,MS2Ptr<CGuildCustomEvent>& out);
Unk_GuildRef* FUN_1404ec5b0(Unk_GuildRef* dst,const Unk_GuildRef* src);
Unk_GuildRef* FUN_1404ec580(Unk_GuildRef* dst,const Unk_GuildRef* src);
void FUN_1404ec5f0(Unk_GuildRef*,int);
void FUN_1404ec610(Unk_GuildRef*,CGuildMember*);
void FUN_1404eead0(Unk_GuildRef*);
CGuildMember* FUN_1404f0b80(Unk_GuildRef*);
bool FUN_1404f0020(Unk_GuildRef*,int);
__int64 FUN_1404f0ab0(Unk_GuildRef*);
void FUN_1404ef970(Unk_GuildRef* dst,Unk_GuildRef* src);
// CGuildGrade array (CGuildInfo+0xa0)
size_t FUN_1404f4440(void* arr); Unk_GuildRef* FUN_1404f0720(void* arr,__int64 index);
void FUN_1404f86e0(void* arr); void FUN_1404f9b50(void* arr,unsigned count,unsigned grow);
void FUN_1404f9730(void* arr,__int64 index,Unk_GuildRef* v); void FUN_1404f3110(void* arr,Unk_GuildRef* v);
void FUN_1404ec4d0(Unk_GuildRef*,Unk_GuildRef*); void FUN_1404ec510(Unk_GuildRef*,int); void FUN_1404ec530(Unk_GuildRef*,CGuildGrade*);
CGuildGrade* FUN_1404f0b70(Unk_GuildRef*); __int64 FUN_1404f0aa0(Unk_GuildRef*); char FUN_1404effe0(Unk_GuildRef*,int);
// CGuildSkill map (+0x238, key = skill id)
unsigned char FUN_1404f4480(void* map); void* FUN_1404f4cd0(void* map); Unk_GuildRef* FUN_1404f4e90(void* map,void* pos); void FUN_1404f4660(void* map,void** pos);
void FUN_1404f8920(void* map); void FUN_1404f98e0(void* map,int key,Unk_GuildRef* v); char FUN_1404f5f60(void* map,int key,Unk_GuildRef* out);
void FUN_1404ec940(Unk_GuildRef*,CGuildSkill*); void FUN_1404ec920(Unk_GuildRef*,int); void FUN_1404ec8b0(Unk_GuildRef*,Unk_GuildRef*);
void FUN_1404eeb90(Unk_GuildRef*); CGuildSkill* FUN_1404f0bc0(Unk_GuildRef*); char FUN_1404f0120(Unk_GuildRef*,int);
// CGuildCustomEvent map (+0x280, key = event id)
unsigned char FUN_1404f4470(void* map); void* FUN_1404f4c60(void* map); Unk_GuildRef* FUN_1404f4e20(void* map,void* pos); void FUN_1404f4610(void* map,void** pos);
void FUN_1404f8810(void* map); void FUN_1404f9830(void* map,int key,Unk_GuildRef* v); char FUN_1404f5ef0(void* map,int key,Unk_GuildRef* out);
void FUN_1404ec480(Unk_GuildRef*,CGuildCustomEvent*); void FUN_1404ec460(Unk_GuildRef*,int); void FUN_1404ec420(Unk_GuildRef*,Unk_GuildRef*); void FUN_1404ec3f0(Unk_GuildRef*,Unk_GuildRef*);
void FUN_1404eea70(Unk_GuildRef*); CGuildCustomEvent* FUN_1404f0b60(Unk_GuildRef*);
// CGuildNpc map (+0x2c8, key = npc id)
unsigned char FUN_1404f4490(void* map); void* FUN_1404f4d40(void* map); Unk_GuildRef* FUN_1404f4f00(void* map,void* pos); void FUN_1404f46b0(void* map,void** pos);
void FUN_1404f8a30(void* map); void FUN_1404f9990(void* map,int* key,Unk_GuildRef* v); char FUN_1404f5fd0(void* map,int* key,Unk_GuildRef* out);
void FUN_1404ec6f0(Unk_GuildRef*,CGuildNpc*); void FUN_1404ec6d0(Unk_GuildRef*,int); void FUN_1404ec690(Unk_GuildRef*,Unk_GuildRef*); void FUN_1404ec660(Unk_GuildRef*,Unk_GuildRef*);
void FUN_1404eeb00(Unk_GuildRef*); CGuildNpc* FUN_1404f0b90(Unk_GuildRef*); char FUN_1404f0060(Unk_GuildRef*,int);
// Unk_GuildRef wrappers as the exe uses them: real smart-pointer locals (ctor call, EH state, dtor at scope end).
// Member ref: copy ctor 0x1404ec5b0, dtor 0x1404eead0. Npc ref: ctor 0x1404ec6f0, dtor 0x1404eeb00.
struct Unk_GuildMemberRef : Unk_GuildRef { Unk_GuildMemberRef(const Unk_GuildRef& src) { FUN_1404ec5b0(this,&src); } ~Unk_GuildMemberRef() { FUN_1404eead0(this); } };
struct Unk_GuildNpcRef : Unk_GuildRef { Unk_GuildNpcRef(CGuildNpc* p) { FUN_1404ec6f0(this,p); } ~Unk_GuildNpcRef() { FUN_1404eeb00(this); } };
// Unk_GuildStrRec map (+0x170, key = int)
unsigned FUN_1404f4460(void* map); void* FUN_1404f4bf0(void* map); int* FUN_1404f4550(void* map,void* pos); Unk_GuildStrRec* FUN_1404f4db0(void* map,void* pos); void FUN_1404f45c0(void* map,void** pos);
void FUN_1404f8700(void* map); void FUN_1404f9780(void* map,int key,Unk_GuildStrRec* v); char FUN_1404f5e80(void* map,int key,Unk_GuildStrRec* out); Unk_GuildStrRec* FUN_1404f07a0(void* map,int key);
void FUN_1404ee6b0(Unk_GuildStrRec*); void FUN_1404ee640(Unk_GuildStrRec*,Unk_GuildStrRec*); void FUN_1404ef6e0(Unk_GuildStrRec*); void FUN_1404efdf0(Unk_GuildStrRec* dst,Unk_GuildStrRec* src);
// Npc shop manager handle (+0x360) and the manager itself
void FUN_1404ec820(Unk_GuildRef* dst,Unk_GuildRef* src); __int64 FUN_1404f0ad0(Unk_GuildRef*); void* FUN_1404f0bb0(Unk_GuildRef*); bool FUN_1404f00e0(Unk_GuildRef*,int); void FUN_1404efb30(Unk_GuildRef*,void*);
void* FUN_1404ee230(void* mem);   // CGuildNpcShopMgr::CGuildNpcShopMgr
void FUN_1404d8d50(void* mgr,COutputStream* out); void FUN_1404d8e80(void* mgr,CInPacket* in); void FUN_1404d8ff0(void* mgr,int a,void* b); void FUN_1404d9060(void* mgr,int a,void* b);
// guild xml data queries
void FUN_1404d74e0(void* xml,Unk_GuildRef* out,int a,int b); void FUN_1404d7410(void* xml,Unk_GuildRef* out,int a); void FUN_1404d79b0(void* xml,Unk_GuildRef* out,int a,int b);
int FUN_1404d7280(void* xml); int FUN_1404d7130(void* xml,int a);
char FUN_1404effa0(Unk_GuildRef*,int); char FUN_1404eff60(Unk_GuildRef*,int); char FUN_1404eff20(Unk_GuildRef*,int);
char* FUN_1404f0b50(Unk_GuildRef*); char* FUN_1404f0b30(Unk_GuildRef*); char* FUN_1404f0b10(Unk_GuildRef*);
void FUN_1404eea40(Unk_GuildRef*); void FUN_1404ee9b0(Unk_GuildRef*); void FUN_1404ee950(Unk_GuildRef*);
int* FUN_1404eb7e0(void* map,void* key);
// ---- container/ctor helpers in neighbouring chunks (loose types) ----
void FUN_140212bf0(void*,__int64); void FUN_1402fec60(void*); char FUN_1402ffdc0(void*,int); void* FUN_140300710(void*);
void FUN_140374140(void*,__int64); char FUN_140375310(void*);
Unk_GuildPair* FUN_140407ed0(Unk_GuildPair*,int*,int*); Unk_GuildPair* FUN_1404d9660(Unk_GuildPair*,int*,int*);
void FUN_1404ebaf0(void*,int,float,float,float,int); void FUN_1404ebbe0(void*,int,float,float,float,int);
void FUN_1404ebcd0(void*,int,float,float,float,int); void FUN_1404ebdc0(void*,int,float,float,float,int);
void FUN_1404ebeb0(void*,int); void FUN_1404ec640(void*); void FUN_1404ec890(void*); void FUN_1404ec9d0(Unk_GuildRef*,void*);
void FUN_1404ee7e0(void*); void FUN_1404ee810(void*); void FUN_1404ee840(void*); void FUN_1404ee870(void*); void FUN_1404ee8a0(void*);
void FUN_1404eeb60(void*); void FUN_1404eebc0(Unk_GuildRef*); void FUN_1404eec20(Unk_GuildRef*);
void FUN_1404ef9b0(void*,int); void FUN_1404efb00(void*,int); void FUN_1404efd50(void*,void*); void FUN_1404efd90(void*,const void*);
void* FUN_1404efe60(void*,const void*); char FUN_1404f01a0(Unk_GuildRef*,int); char FUN_1404f03a0(void*,void*);
bool FUN_1404f0660(void*,void*); Unk_GuildRef* FUN_1404f0760(void*,__int64); void* FUN_1404f0990(void*,void*);
void* FUN_1404f0ae0(Unk_GuildRef*); CGuildStorage::CGuildStroageHistory* FUN_1404f0bd0(Unk_GuildRef*); char* FUN_1404f0bf0(Unk_GuildRef*);
void* FUN_1404f0ce0(void*); void FUN_1404f14c0(void*); void FUN_1404f31c0(void*,Unk_GuildRef*); void FUN_1404f3270(void*,Unk_GuildRef*);
unsigned FUN_1404f4450(void*); size_t FUN_1404f44a0(void*); void FUN_1404f8b40(void*); void FUN_1404f8c50(void*);
void FUN_1404f9a40(void*,__int64,__int64); void FUN_1405063e0(void*,void*); void FUN_140506ac0(void*); void FUN_140506ca0(void*);
void* FUN_1405076d0(void*,void*); void FUN_1405085e0(void*,void*); void FUN_140508ed0(void*,void*,void*);
void FUN_1405098f0(void*); void FUN_1405099e0(void*,Unk_GuildRef*); void FUN_140509c90(void*,Unk_GuildRef*);
unsigned FUN_14050a000(void*); int FUN_14050a040(void*); void* FUN_14025e7d0(); CString* FUN_1402295b0(void*,CString*,int);
void FUN_140791e40(void*,Unk_GuildRef*,int);
// @0x1404c5c80
 Unk_GuildSeason::Unk_GuildSeason()
{
    FUN_1404c5d20();
}

// @0x1404c5cf0
 Unk_GuildSeason::~Unk_GuildSeason()
{
    
}

// @0x1404c5d20
void Unk_GuildSeason::FUN_1404c5d20()
{
    id=0; name=L""; begin=__time64_t(0); end=__time64_t(0); memset(points,0,sizeof(points));
}

// @0x1404c5da0
void Unk_GuildSeason::FUN_1404c5da0(COutputStream& out)
{
    out.WriteInt32(id); out.WriteUnicodeString(name); out.WriteInt64(begin.Get()); out.WriteInt64(end.Get()); for(int i=1;i<8;++i) out.WriteInt32(points[i]);
}

// @0x1404c5ea0
void Unk_GuildSeason::FUN_1404c5ea0(CInPacket& packet)
{
    id=packet.ReadInt32(); name=packet.ReadUnicodeString(); begin=packet.ReadInt64(); end=packet.ReadInt64(); for(int i=1;i<8;++i) points[i]=packet.ReadInt32();
}

// @0x1404c6030
void Unk_GuildSeason::FUN_1404c6030(const Unk_GuildSeason& other)
{
    id=other.id; name=other.name; begin=other.begin; end=other.end; for(int i=1;i<8;++i) points[i]=other.points[i];
}

// @0x1404c60e0
int Unk_GuildSeason::FUN_1404c60e0(int rank)
{
    if (rank < 1 || rank >= 8)
        return 0;
    return points[rank];
}

// @0x1404c6110
int Unk_GuildSeason::FUN_1404c6110(int score)
{
    for(int i=1;i<8;++i) if(points[i]>score) return i-1; return 7;
}

// @0x1404c6160
bool Unk_GuildSeason::FUN_1404c6160()
{
    CMsTime now(GetServerTime());
    if (begin < now && end > now)
        return true;
    return false;
}

// @0x1404c61d0
 Unk_GuildProfile::Unk_GuildProfile()
{
    FUN_1404c6350();
}

// @0x1404c62a0
 Unk_GuildProfile::~Unk_GuildProfile()
{
    
}

// @0x1404c6350
void Unk_GuildProfile::FUN_1404c6350()
{
    name=""; code=""; f18=0; f20=""; f28=""; f30=""; f38=0; f40=0; f48=""; f50=0; f58=0; f60=0; f68=0; f70=0; f78.Empty(); f80=0; f84=0; f88=0; f8c=0; f90=0; f94=0; f98=0; f9c=1; fa0=255; fa4=0; fa8=0; fb8=1; fbc=1; fc0=0; fc8=0; array.FUN_1401c0580();
}

// @0x1404c6570
 CGuildPVPHistoryData::CGuildPVPHistoryData()
{
    FUN_1404c66f0();
}

// @0x1404c6640
 CGuildPVPHistoryData::~CGuildPVPHistoryData()
{
    
}

// @0x1404c66f0
void CGuildPVPHistoryData::FUN_1404c66f0()
{
    f18=0; f1c=0; f20=0; f28=0; f30=0; f38=L""; f40=L""; f48=0; f4c=0; f50=0; f54=0; for(int i=0;i<5;++i) { f58[i]=L""; f80[i]=L""; fa8[i]=0; } fb0=0; fb8=0;
}

// @0x1404c6840
void CGuildPVPHistoryData::FUN_1404c6840(const CGuildPVPHistoryData* other)
{
    if(!other) return;
    f18=other->f18; f1c=other->f1c; f20=other->f20; f28=other->f28; f30=other->f30; f38=other->f38; f40=other->f40; f48=other->f48; f4c=other->f4c; f50=other->f50; f54=other->f54; for(int i=0;i<5;++i) { f58[i]=other->f58[i]; f80[i]=other->f80[i]; fa8[i]=other->fa8[i]; } fb0=other->fb0; fb8=other->fb8;
}

// @0x1404c6a00
void CGuildPVPHistoryData::FUN_1404c6a00(COutPacket* out)
{
    FUN_1404c6a80(*out);
}

// @0x1404c6a30
void CGuildPVPHistoryData::FUN_1404c6a30(CInPacket* in)
{
    FUN_1404c6cb0(*static_cast<CInputStream*>(in));
}

// @0x1404c6a80
void CGuildPVPHistoryData::FUN_1404c6a80(COutputStream& out)
{
    out.WriteInt32(f18); out.WriteInt32(f1c); out.WriteUInt8(f20); out.WriteInt64(f28); out.WriteInt64(f30); out.WriteUnicodeString(f38); out.WriteUnicodeString(f40); out.WriteInt32(f48); out.WriteInt32(f4c); out.WriteInt32(f50); out.WriteInt32(f54); for(int i=0;i<5;++i) { out.WriteUnicodeString(f58[i]); out.WriteUnicodeString(f80[i]); out.WriteUInt8(fa8[i]); } out.WriteInt64(fb0); out.WriteInt64(fb8);
}

// @0x1404c6cb0
void CGuildPVPHistoryData::FUN_1404c6cb0(CInputStream& in)
{
    f18=in.ReadInt32(); f1c=in.ReadInt32(); f20=in.ReadUInt8(); f28=in.ReadInt64(); f30=in.ReadInt64(); f38=in.ReadUnicodeString(); f40=in.ReadUnicodeString(); f48=in.ReadInt32(); f4c=in.ReadInt32(); f50=in.ReadInt32(); f54=in.ReadInt32(); for(int i=0;i<5;++i) { f58[i]=in.ReadUnicodeString(); f80[i]=in.ReadUnicodeString(); fa8[i]=in.ReadUInt8(); } fb0=in.ReadInt64(); fb8=in.ReadInt64();
}

// @0x1404c7000
 CGuildGrade::CGuildGrade()
{
    FUN_1404c70a0();
}

// @0x1404c7060
 CGuildGrade::~CGuildGrade()
{
    
}

// @0x1404c70a0
void CGuildGrade::FUN_1404c70a0()
{
    grade=6; name=""; permissions=0;
}

// @0x1404c70f0
void CGuildGrade::FUN_1404c70f0(int g,CStringW n,int p)
{
    grade=g; name=n; permissions=p;
}

// @0x1404c7160
void CGuildGrade::FUN_1404c7160(COutputStream& out)
{
    out.WriteUInt8((unsigned char)grade); out.WriteUnicodeString(name); out.WriteInt32(permissions);
}

// @0x1404c71d0
void CGuildGrade::FUN_1404c71d0(CInPacket& packet)
{
    grade=packet.ReadUInt8(); name=packet.ReadUnicodeString(); permissions=packet.ReadInt32();
}

// @0x1404c72b0
int CGuildGrade::FUN_1404c72b0()
{
    if(grade<0 || grade>=6) return 0; if(permissions<0 || permissions>4095) return 0; return 1;
}

// @0x1404c7300
 CGuildNameInfo::CGuildNameInfo()
{
    FUN_1404c73d0();
}

// @0x1404c7370
 CGuildNameInfo::~CGuildNameInfo()
{
    
}

// @0x1404c73d0
void CGuildNameInfo::FUN_1404c73d0()
{
    id=0; name.Empty(); code.Empty();
}

// @0x1404c7420
void CGuildNameInfo::FUN_1404c7420(const CGuildNameInfo* other)
{
    if(!other) { FUN_1404c73d0(); } else { id=other->id; name=other->name; code=other->code; }
}

// @0x1404c74a0
void CGuildNameInfo::FUN_1404c74a0(COutPacket* out)
{
    FUN_1404c7520(*out);
}

// @0x1404c74d0
void CGuildNameInfo::FUN_1404c74d0(CInPacket* in)
{
    FUN_1404c75a0(*static_cast<CInputStream*>(in));
}

// @0x1404c7520
void CGuildNameInfo::FUN_1404c7520(COutputStream& out)
{
    out.WriteInt64(id); out.WriteUnicodeString(name); out.WriteUnicodeStringA(code);
}

// @0x1404c75a0
void CGuildNameInfo::FUN_1404c75a0(CInputStream& in)
{
    id=in.ReadInt64(); name=in.ReadUnicodeString(); code=in.ReadUnicodeStringA();
}

// @0x1404c7670
 CGuildJoinRequestForGuild::CGuildJoinRequestForGuild()
{
    FUN_1404c7750();
}

// @0x1404c76f0
 CGuildJoinRequestForGuild::~CGuildJoinRequestForGuild()
{
    
}

// @0x1404c7750
void CGuildJoinRequestForGuild::FUN_1404c7750()
{
    f18=0; f20=0; f28=0; f30=0; f38.Empty(); f40.Empty(); f48=0; f4c=0; f50=0; f54.FUN_140267bd0(); f60=0;
}

// @0x1404c7800
void CGuildJoinRequestForGuild::FUN_1404c7800(const CGuildJoinRequestForGuild* other)
{
    if(!other) { FUN_1404c7750(); } else { f18=other->f18; f20=other->f20; f28=other->f28; f30=other->f30; f38=other->f38; f40=other->f40; f48=other->f48; f4c=other->f4c; f50=other->f50; f54.FUN_140267ea0(other->f54); f60=other->f60; }
}

// @0x1404c7910
void CGuildJoinRequestForGuild::FUN_1404c7910(COutPacket* out)
{
    FUN_1404c7990(*out);
}

// @0x1404c7940
void CGuildJoinRequestForGuild::FUN_1404c7940(CInPacket* in)
{
    FUN_1404c7ad0(*static_cast<CInputStream*>(in));
}

// @0x1404c7990
void CGuildJoinRequestForGuild::FUN_1404c7990(COutputStream& out)
{
    out.WriteInt64(f18); out.WriteInt64(f20); out.WriteInt64(f28); out.WriteInt64(f30); out.WriteUnicodeString(f38); out.WriteUnicodeStringA(f40); out.WriteInt32(f48); out.WriteInt32(f4c); out.WriteInt32(f50); f54.FUN_140267f50(out); out.WriteInt64(f60);
}

// @0x1404c7ad0
void CGuildJoinRequestForGuild::FUN_1404c7ad0(CInputStream& in)
{
    f18=in.ReadInt64(); f20=in.ReadInt64(); f28=in.ReadInt64(); f30=in.ReadInt64(); f38=in.ReadUnicodeString(); f40=in.ReadUnicodeStringA(); f48=in.ReadInt32(); f4c=in.ReadInt32(); f50=in.ReadInt32(); f54.FUN_140267fb0(in); f60=in.ReadInt64();
}

// @0x1404c7c60
 CGuildJoinRequestForChar::CGuildJoinRequestForChar()
{
    FUN_1404c7d70();
}

// @0x1404c7d00
 CGuildJoinRequestForChar::~CGuildJoinRequestForChar()
{
    
}

// @0x1404c7d70
void CGuildJoinRequestForChar::FUN_1404c7d70()
{
    f18=0; f20=0; f28.Empty(); f30=0; f38.Empty(); f44.FUN_140267bd0(); f50=0; f40=0; f58.Empty(); f60=0; f68=0; f70=0;
}

// @0x1404c7e30
void CGuildJoinRequestForChar::FUN_1404c7e30(const CGuildJoinRequestForChar* other)
{
    if(!other) { FUN_1404c7d70(); } else { f18=other->f18; f20=other->f20; f28=other->f28; f30=other->f30; f38=other->f38; f44.FUN_140267ea0(other->f44); f50=other->f50; f40=other->f40; f58=other->f58; f60=other->f60; f68=other->f68; f70=other->f70; }
}

// @0x1404c7f60
void CGuildJoinRequestForChar::FUN_1404c7f60(COutPacket* out)
{
    FUN_1404c7fe0(*out);
}

// @0x1404c7f90
void CGuildJoinRequestForChar::FUN_1404c7f90(CInPacket* in)
{
    FUN_1404c8150(*static_cast<CInputStream*>(in));
}

// @0x1404c7fe0
void CGuildJoinRequestForChar::FUN_1404c7fe0(COutputStream& out)
{
    out.WriteInt64(f18); out.WriteInt64(f20); out.WriteUnicodeString(f28); out.WriteInt32(f30); out.WriteUnicodeStringA(f38); f44.FUN_140267f50(out); out.WriteInt32(f50); out.WriteInt32(f40); out.WriteUnicodeString(f58); out.WriteInt64(f60); out.WriteInt64(f68); out.WriteInt64(f70);
}

// @0x1404c8150
void CGuildJoinRequestForChar::FUN_1404c8150(CInputStream& in)
{
    f18=in.ReadInt64(); f20=in.ReadInt64(); f28=in.ReadUnicodeString(); f30=in.ReadInt32(); f38=in.ReadUnicodeStringA(); f44.FUN_140267fb0(in); f50=in.ReadInt32(); f40=in.ReadInt32(); f58=in.ReadUnicodeString(); f60=in.ReadInt64(); f68=in.ReadInt64(); f70=in.ReadInt64();
}

// @0x1404c8390
 CGuildJoinRequestSchCond::CGuildJoinRequestSchCond()
{
    FUN_1404c8410();
}

// @0x1404c83e0
 CGuildJoinRequestSchCond::~CGuildJoinRequestSchCond()
{
    
}

// @0x1404c8410
void CGuildJoinRequestSchCond::FUN_1404c8410()
{
    f18=0; f1c=0;
}

// @0x1404c8440
void CGuildJoinRequestSchCond::FUN_1404c8440(const CGuildJoinRequestSchCond* other)
{
    FUN_1404c8410(); if(!other) return;
    f18=other->f18; f1c=other->f1c;
}

// @0x1404c8490
int CGuildJoinRequestSchCond::FUN_1404c8490(const CGuildJoinRequestSchCond* other)
{
    if(!other) return 0; if(other->f18!=f18) return 0; if(other->f1c!=f1c) return 0; return 1;
}

// @0x1404c84e0
void CGuildJoinRequestSchCond::FUN_1404c84e0(COutPacket* out)
{
    FUN_1404c8560(*out);
}

// @0x1404c8510
void CGuildJoinRequestSchCond::FUN_1404c8510(CInPacket* in)
{
    FUN_1404c85b0(*static_cast<CInputStream*>(in));
}

// @0x1404c8560
void CGuildJoinRequestSchCond::FUN_1404c8560(COutputStream& out)
{
    out.WriteInt32(f18); out.WriteInt32(f1c);
}

// @0x1404c85b0
void CGuildJoinRequestSchCond::FUN_1404c85b0(CInputStream& in)
{
    f18=in.ReadInt32(); f1c=in.ReadInt32();
}

// @0x1404c8600
int CGuildJoinRequestSchCond::FUN_1404c8600()
{
    if(f1c==0) return -1;
    int idx=f1c-1; int step=idx/10; return step;
}

// @0x1404c8650
int CGuildJoinRequestSchCond::FUN_1404c8650()
{
    int n=FUN_1404c8600(); if(n==-1) return 0;
    int days=90; int v=n*days+1; return v;
}

// @0x1404c86a0
int CGuildJoinRequestSchCond::FUN_1404c86a0()
{
    int n=FUN_1404c8600(); if(n==-1) return 0;
    int days=90; int v=(n+1)*days; return v;
}

// @0x1404c86f0
int CGuildJoinRequestSchCond::FUN_1404c86f0()
{
    if(f1c==0) return -1;
    int idx=f1c-1; int step=idx/10; int days=90; int v=(step+1)*days; return v;
}

// @0x1404c8750
 CSearchGuildJoin::CSearchGuildJoin()
{
    FUN_1404c8860();
}

// @0x1404c87f0
 CSearchGuildJoin::~CSearchGuildJoin()
{
    
}

// @0x1404c8860
void CSearchGuildJoin::FUN_1404c8860()
{
    f18=0; f20.Empty(); f28.Empty(); f38.FUN_140267bd0(); f44=0; f30=0; f34=0; f48=0; f50=0; f58.Empty();
}

// @0x1404c8910
void CSearchGuildJoin::FUN_1404c8910(const CSearchGuildJoin* other)
{
    if(!other) { FUN_1404c8860(); } else { f18=other->f18; f20=other->f20; f28=other->f28; f38.FUN_140267ea0(other->f38); f44=other->f44; f30=other->f30; f34=other->f34; f48=other->f48; f50=other->f50; f58=other->f58; }
}

// @0x1404c8a20
void CSearchGuildJoin::FUN_1404c8a20(COutPacket* out)
{
    FUN_1404c8aa0(*out);
}

// @0x1404c8a50
void CSearchGuildJoin::FUN_1404c8a50(CInPacket* in)
{
    FUN_1404c8be0(*static_cast<CInputStream*>(in));
}

// @0x1404c8aa0
void CSearchGuildJoin::FUN_1404c8aa0(COutputStream& out)
{
    out.WriteInt64(f18); out.WriteUnicodeString(f20); out.WriteUnicodeStringA(f28); f38.FUN_140267f50(out); out.WriteInt32(f44); out.WriteInt32(f30); out.WriteInt32(f34); out.WriteInt64(f48); out.WriteInt64(f50); out.WriteUnicodeString(f58);
}

// @0x1404c8be0
void CSearchGuildJoin::FUN_1404c8be0(CInputStream& in)
{
    f18=in.ReadInt64(); f20=in.ReadUnicodeString(); f28=in.ReadUnicodeStringA(); f38.FUN_140267fb0(in); f44=in.ReadInt32(); f30=in.ReadInt32(); f34=in.ReadInt32(); f48=in.ReadInt64(); f50=in.ReadInt64(); f58=in.ReadUnicodeString();
}

// @0x1404c8de0
 CGuildInviteInfo::CGuildInviteInfo()
{
    FUN_1404c8f00();
}

// @0x1404c8e80
 CGuildInviteInfo::~CGuildInviteInfo()
{
    
}

// @0x1404c8f00
void CGuildInviteInfo::FUN_1404c8f00()
{
    f18=0; f20.Empty(); f28.Empty(); f30.Empty(); f38.Empty();
}

// @0x1404c8f70
void CGuildInviteInfo::FUN_1404c8f70(const CGuildInviteInfo* other)
{
    if(!other) FUN_1404c8f00(); else { f18=other->f18; f20=other->f20; f28=other->f28; f30=other->f30; f38=other->f38; }
}

// @0x1404c9020
void CGuildInviteInfo::FUN_1404c9020(CGuildInfo* guild,CStringW a,CStringW b)
{
    if(guild==0) return;
    f18=guild->FUN_1404ccbd0(); f20=guild->FUN_1404cccb0(); f28=guild->FUN_1404ccdb0(); f30=a; f38=b;
}

// @0x1404c9160
void CGuildInviteInfo::FUN_1404c9160(COutputStream& out)
{
    out.WriteInt64(f18); out.WriteUnicodeString(f20); out.WriteUnicodeStringA(f28); out.WriteUnicodeString(f30); out.WriteUnicodeString(f38);
}

// @0x1404c9230
void CGuildInviteInfo::FUN_1404c9230(CInputStream& in)
{
    f18=in.ReadInt64(); f20=in.ReadUnicodeString(); f28=in.ReadUnicodeStringA(); f30=in.ReadUnicodeString(); f38=in.ReadUnicodeString();
}

// @0x1404c93c0
 Unk_GuildMemberData::Unk_GuildMemberData()
{
    FUN_1404c9490();
}

// @0x1404c9440
 Unk_GuildMemberData::~Unk_GuildMemberData()
{
    
}

// @0x1404c9490
void Unk_GuildMemberData::FUN_1404c9490()
{
    f00=0; f08=0; f10=3; f14=0; f18=0; f1c=0; f20=0; f24=0; f28=0; f2c.FUN_140267bd0(); f38=0; f3c=0; f40=0; f48=0; FUN_1404ca910(L""); FUN_1404caa00("");
}

// @0x1404c95b0
void Unk_GuildMemberData::FUN_1404c95b0(COutputStream& out)
{
    out.WriteInt32(f24);
}

// @0x1404c95f0
void Unk_GuildMemberData::FUN_1404c95f0(CInPacket& in)
{
    f24=in.ReadInt32();
}

// @0x1404c9640
void Unk_GuildMemberData::FUN_1404c9640(COutPacket* out)
{
    FUN_1404c99d0(*out);
}

// @0x1404c9670
void Unk_GuildMemberData::FUN_1404c9670(CInPacket* in)
{
    FUN_1404c9bd0(*static_cast<CInputStream*>(in));
}

// @0x1404c96c0
void Unk_GuildMemberData::FUN_1404c96c0(COutputStream& out)
{
    out.WriteUnicodeString(FUN_1404ca890()); out.WriteInt32(f14); out.WriteInt32(f18); out.WriteInt16(f1c); out.WriteUnicodeStringA(code);
}

// @0x1404c97a0
void Unk_GuildMemberData::FUN_1404c97a0(CInPacket& in)
{
    CStringW n; CString c; n=in.ReadUnicodeString(); f14=in.ReadInt32(); f18=in.ReadInt32(); f1c=in.ReadInt16(); c=in.ReadUnicodeStringA(); FUN_1404ca910(n); FUN_1404caa00(c);
}

// @0x1404c99d0
void Unk_GuildMemberData::FUN_1404c99d0(COutputStream& out)
{
    out.WriteInt64(f00); out.WriteInt64(f08); out.WriteUnicodeString(FUN_1404ca890()); out.WriteUInt8(f10); out.WriteInt32(f14); out.WriteInt32(f18); out.WriteInt16(f1c); out.WriteInt32(f20); out.WriteInt32(f24); out.WriteInt16((short)f28); out.WriteUnicodeStringA(FUN_1404ca980()); out.WriteInt32(f38); out.WriteInt32(f3c); out.WriteInt32(f40); out.WriteInt64(f48); f2c.FUN_140267f50(out);
}

// @0x1404c9bd0
void Unk_GuildMemberData::FUN_1404c9bd0(CInputStream& in)
{
    CStringW n; CString c; f00=in.ReadInt64(); f08=in.ReadInt64(); n=in.ReadUnicodeString(); f10=in.ReadUInt8(); f14=in.ReadInt32(); f18=in.ReadInt32(); f1c=in.ReadInt16(); f20=in.ReadInt32(); f24=in.ReadInt32(); f28=(unsigned short)in.ReadInt16(); c=in.ReadUnicodeStringA(); f38=in.ReadInt32(); f3c=in.ReadInt32(); f40=in.ReadInt32(); f48=in.ReadInt64(); f2c.FUN_140267fb0(in); FUN_1404ca910(n); FUN_1404caa00(c);
}

// @0x1404c9ef0
void Unk_GuildMemberData::FUN_1404c9ef0(COutputStream& out)
{
    out.WriteUnicodeString(FUN_1404ca890()); out.WriteInt32(f14); out.WriteInt32(f18); out.WriteInt16(f1c); out.WriteUnicodeStringA(FUN_1404ca980());
}

// @0x1404c9fe0
void Unk_GuildMemberData::FUN_1404c9fe0(CInputStream& in)
{
    CStringW n; CString c; n=in.ReadUnicodeString(); f14=in.ReadInt32(); f18=in.ReadInt32(); f1c=in.ReadInt16(); c=in.ReadUnicodeStringA(); FUN_1404ca910(n); FUN_1404caa00(c);
}

// @0x1404ca1a0
void Unk_GuildMemberData::FUN_1404ca1a0(const Unk_GuildMemberData& other)
{
    CStringW n; CString c; f00=other.f00; f08=other.f08; n=other.name; f10=other.f10; f14=other.f14; f18=other.f18; f1c=other.f1c; f20=other.f20; f24=other.f24; f28=other.f28; c=other.code; f38=other.f38; f3c=other.f3c; f40=other.f40; f48=other.f48; f2c.FUN_140267ea0(other.f2c); FUN_1404ca910(n); FUN_1404caa00(c);
}

// @0x1404ca3e0
void Unk_GuildMemberData::FUN_1404ca3e0(Unk_GuildCharacter* other)
{
    CStringW n;
    CString c;
    f00=other->m_00;
    f08=other->m_08;
    n=other->FUN_1408f19e0();
    f10=other->m_14;
    f14=other->m_3c;
    f18=other->m_40;
    f1c=other->m_34;
    f20=other->m_d0;
    f24=other->m_2c;
    f28=other->m_38;
    c=other->FUN_1408f1a60();
    f38=other->m_98;
    f3c=other->m_9c;
    f40=other->m_a0;
    f48=other->m_a8;
    f2c.FUN_140267ea0(other->m_d4);
    FUN_1404ca910(n);
    FUN_1404caa00(c);
}

// @0x1404ca680
void Unk_GuildMemberData::FUN_1404ca680(const CGuildJoinRequestForGuild* other)
{
    if(!other) return;
    CStringW n; CString c; f00=other->f28; f08=other->f30; n=other->f38; f10=0; f14=other->f48; f18=other->f4c; f1c=(short)other->f50; f20=0; f24=0; f28=1; c=other->f40; f38=0; f3c=0; f40=0; f48=0; f2c.FUN_140267ea0(other->f54); FUN_1404ca910(n); FUN_1404caa00(c);
}

// @0x1404ca890
CStringW Unk_GuildMemberData::FUN_1404ca890()
{
    Unk_GuildNameLock guard(lock,1); return name;
}

// @0x1404ca910
void Unk_GuildMemberData::FUN_1404ca910(CStringW value)
{
    Unk_GuildNameLock guard(lock,1); name=value;
}

// @0x1404ca980
CString Unk_GuildMemberData::FUN_1404ca980()
{
    Unk_GuildNameLock guard(lock,1); return code;
}

// @0x1404caa00
void Unk_GuildMemberData::FUN_1404caa00(CString value)
{
    Unk_GuildNameLock guard(lock,1); code=value;
}

// @0x1404caa70
 CGuildMemberRaid::CGuildMemberRaid()
{
    
}

// @0x1404caad0
 CGuildMemberRaid::~CGuildMemberRaid()
{
    
}

// @0x1404cab20
bool CGuildMemberRaid::FUN_1404cab20()
{
    Unk_GuildMapLock guard(lock,1);
    if (raids.empty())
        return false;
    raids.clear();
    return true;
}

// @0x1404cabb0
void CGuildMemberRaid::FUN_1404cabb0(const CGuildMemberRaid& other)
{
    Unk_GuildMapLock guard(lock,1); raids.clear(); raids=other.raids;
}

// @0x1404cac30
bool CGuildMemberRaid::FUN_1404cac30(unsigned long id,int count)
{
    Unk_GuildMapLock guard(lock,1); auto i=raids.find(id);
    if(i==raids.end()) { FUN_1404cad50(id,count,false); return true; }
    else { int cur=i->second; if(cur<count) { FUN_1404cad50(id,count,false); return true; } }
    return false;
}

// @0x1404cad50
void CGuildMemberRaid::FUN_1404cad50(unsigned long id,int count,bool)
{
    Unk_GuildMapLock guard(lock,1); raids[id]=count;
}

// @0x1404cadc0
int CGuildMemberRaid::FUN_1404cadc0()
{
    int count=0; Unk_GuildMapLock guard(lock,1); for(auto i=raids.begin(),end=raids.end();i!=end;++i) count+=i->second; return count;
}

// @0x1404cae90
int CGuildMemberRaid::FUN_1404cae90(unsigned long id)
{
    Unk_GuildMapLock guard(lock,1);
    auto i=raids.find(id);
    if (i==raids.end())
        return 0;
    return i->second;
}

// @0x1404caf50
void CGuildMemberRaid::FUN_1404caf50(COutputStream& out)
{
    Unk_GuildMapLock guard(lock,1); auto i=raids.begin(),end=raids.end(); out.WriteInt32((int)raids.size()); for(;i!=end;++i) { out.WriteInt32(i->first); out.WriteInt32(i->second); }
}

// @0x1404cb070
void CGuildMemberRaid::FUN_1404cb070(CInputStream& in)
{
    Unk_GuildMapLock guard(lock,1); raids.clear(); int count=in.ReadInt32(); for(int i=0;i<count;++i) { unsigned long id=in.ReadInt32(); int value=in.ReadInt32(); raids[id]=value; }
}

// @0x1404cb150
 CGuildMember::CGuildMember()
{
    FUN_1404cb250();
}

// @0x1404cb1e0
 CGuildMember::~CGuildMember()
{
    
}

// @0x1404cb250
void CGuildMember::FUN_1404cb250()
{
    f18=0; data.FUN_1404c9490(); fb4=0; fb0=0; fb8.Empty(); fc0=0; fc8=0; fd0=0; fd8=0; fe0=0; fe4=0; fe8=0; fec=0; ff0=0; ff8=0; raid.FUN_1404cab20(); f158=1;
}

// @0x1404cb370
int CGuildMember::FUN_1404cb370()
{
    return data.f20;
}

// @0x1404cb390
Unk_GuildTriple* CGuildMember::FUN_1404cb390()
{
    return &data.f2c;
}

// @0x1404cb3b0
int CGuildMember::FUN_1404cb3b0()
{
    return data.f2c.FUN_140267c10();
}

// @0x1404cb3e0
int CGuildMember::FUN_1404cb3e0()
{
    if(IsNotRecentDayChange(ff8)==1) return 0;
    return ff0;
}

// @0x1404cb420
void CGuildMember::FUN_1404cb420(COutPacket* out)
{
    FUN_1404cb4a0(*out);
}

// @0x1404cb450
void CGuildMember::FUN_1404cb450(CInPacket* in)
{
    FUN_1404cb6c0(*static_cast<CInputStream*>(in));
}

// @0x1404cb4a0
void CGuildMember::FUN_1404cb4a0(COutputStream& out)
{
    out.WriteUInt8((unsigned char)fb0); out.WriteUInt8((unsigned char)fb4); if(fb0==3) { out.WriteInt64(f18); data.FUN_1404c99d0(out); out.WriteUnicodeString(fb8); out.WriteInt64(fc8); out.WriteInt64(fd0); out.WriteInt64(fd8); out.WriteInt32(fe0); out.WriteInt32(fe4); out.WriteInt32(fe8); out.WriteInt32(fec); out.WriteInt32(ff0); out.WriteInt64(ff8); raid.FUN_1404caf50(out); out.WriteUInt8((unsigned char)f158); } else { out.WriteInt64(f18); data.FUN_1404c9ef0(out); }
}

// @0x1404cb6c0
void CGuildMember::FUN_1404cb6c0(CInputStream& in)
{
    fb0=in.ReadUInt8(); fb4=in.ReadUInt8(); if(fb0==3) { f18=in.ReadInt64(); data.FUN_1404c9bd0(in); fb8=in.ReadUnicodeString(); fc8=in.ReadInt64(); fd0=in.ReadInt64(); fd8=in.ReadInt64(); fe0=in.ReadInt32(); fe4=in.ReadInt32(); fe8=in.ReadInt32(); fec=in.ReadInt32(); ff0=in.ReadInt32(); ff8=in.ReadInt64(); raid.FUN_1404cb070(in); f158=in.ReadUInt8(); } else { f18=in.ReadInt64(); data.FUN_1404c9fe0(in); }
}

// @0x1404cb910
CGuildSkill::CGuildSkill()
{
    f18=0; f1c=1; f20=0;
}

// @0x1404cb970
CGuildSkill::~CGuildSkill()
{
}

// @0x1404cb9a0
void CGuildSkill::FUN_1404cb9a0(const CGuildSkill* other)
{
    f18=other->f18; f1c=other->f1c; f20=other->f20;
}

// @0x1404cb9f0
void CGuildSkill::FUN_1404cb9f0(COutputStream& out)
{
    out.WriteInt32(f18); out.WriteInt32(f1c); out.WriteInt64(f20);
}

// @0x1404cba60
void CGuildSkill::FUN_1404cba60(CInPacket& packet)
{
    f18=packet.ReadInt32(); f1c=packet.ReadInt32(); f20=packet.ReadInt64();
}

// @0x1404cbb00
int CGuildSkill::FUN_1404cbb00()
{
    if(f20==0) return 0;
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skill=TSingleton<CGuildXmlData>::GetInstance()->FUN_1404d74e0(f18,f1c);
    if(skill==0) return 0;
    __int64 now=GetServerTime(); __int64 until=(__int64)skill->f2c+f20;
    if(until<now) return 0;
    return (int)(until-now);
}

// @0x1404cbbf0
int CGuildSkill::FUN_1404cbbf0()
{
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skill=TSingleton<CGuildXmlData>::GetInstance()->FUN_1404d74e0(f18,f1c);
    if(skill==0) return 0x7fffffff;
    __int64 now=GetServerTime(); __int64 until=(__int64)skill->f30+f20;
    if(now>until) return 0;
    return (int)(until-now);
}

// @0x1404cbcd0
bool CGuildSkill::FUN_1404cbcd0()
{
    if(FUN_1404cbb00()>0) return false;
    int n=FUN_1404cbbf0(); if(n>0) return false;
    return true;
}

// @0x1404cbd20
bool CGuildSkill::FUN_1404cbd20()
{
    if(!FUN_1404cbcd0()) return false;
    f20=GetServerTime();
    return true;
}

// @0x1404cbd60
CGuildCustomEvent::CGuildCustomEvent()
{
    f18=0; f20=0;
}

// @0x1404cbdb0
CGuildCustomEvent::~CGuildCustomEvent()
{
}

// @0x1404cbde0
void CGuildCustomEvent::FUN_1404cbde0(const CGuildCustomEvent* other)
{
    f18=other->f18; f20=other->f20;
}

// @0x1404cbe20
void CGuildCustomEvent::FUN_1404cbe20(COutputStream& out)
{
    out.WriteInt32(f18); out.WriteInt32((int)f20);
}

// @0x1404cbe70
void CGuildCustomEvent::FUN_1404cbe70(CInPacket& packet)
{
    f18=packet.ReadInt32(); f20=(unsigned)packet.ReadInt32();
}

// @0x1404cbee0
bool CGuildCustomEvent::FUN_1404cbee0()
{
    __int64 now=GetServerTime();
    if(f20+0x1e>now) return true;
    return false;
}

// @0x1404cbf20
CGuildStorage::CGuildStroageHistory::CGuildStroageHistory()
{
    f78=0;
}

// @0x1404cbfa0
CGuildStorage::CGuildStroageHistory::~CGuildStroageHistory()
{
}

// @0x1404cc000
CGuildStorage::CGuildStorage()
{
}

// @0x1404cc090
CGuildStorage::~CGuildStorage()
{
}

// @0x1404cc110
void CGuildStorage::FUN_1404cc110(const CGuildStorage* other)
{
    f18.clear();
    f18=other->f18;
}

// @0x1404cc160
void CGuildStorage::FUN_1404cc160(COutputStream& out)
{
    out.WriteInt32(f18.size());
    for(std::map<std::pair<unsigned,int>,ItemEntity>::iterator it=f18.begin();it!=f18.end();++it) {
        it->second.FUN_14026b030(*(Unk_GiftOutput*)&out);
    }
}

// @0x1404cc210
void CGuildStorage::FUN_1404cc210(CInPacket& packet)
{
    f18.clear();
    unsigned __int64 count=(unsigned)packet.ReadInt32();
    for(unsigned __int64 i=0;i<count;++i) {
        ItemEntity item; item.FUN_14026b100(*(Unk_GiftInput*)&static_cast<CInputStream&>(packet));
        std::pair<unsigned,int> key(item.vfunc_o18_0(),item.vfunc_o18_1());
        f18[key]=item;
    }
}

// @0x1404cc340
CGuildNpc::CGuildNpc()
{
}

// @0x1404cc380
CGuildNpc::~CGuildNpc()
{
}

// @0x1404cc3b0
void CGuildNpc::FUN_1404cc3b0(const CGuildNpc* other)
{
    f18=other->f18; f1c=other->f1c;
}

// @0x1404cc3f0
void CGuildNpc::FUN_1404cc3f0(COutputStream& out)
{
    out.WriteInt32(f18); out.WriteInt32(f1c);
}

// @0x1404cc440
void CGuildNpc::FUN_1404cc440(CInPacket& packet)
{
    f18=packet.ReadInt32(); f1c=packet.ReadInt32();
}

// @0x1404cc4b0
CGuildInfo::CGuildInfo()
{
    FUN_1404cc900();
    f360=new CGuildNpcShopMgr;
}

// @0x1404cc780
CGuildInfo::~CGuildInfo()
{
}

// @0x1404cc900
void CGuildInfo::FUN_1404cc900()
{
    f38=0; f40=""; f48=""; f50=0; f58=""; f60=""; f68=0; f70=0; f78=0; f80=""; f88=0; f90=0; f98="";
    fc0=0; fc4=0; fd8.Empty(); fc8=0; fd0=0;
    f130=0; f134=f150; f138=0; f13c=0; f140=0; f144=0; f148=0; f14c=0; f154=1; f158=0; f15c=0; f160=0; f164=0; f168=1; f16c=1;
    f170.RemoveAll(); f310=0; f320.RemoveAll();
    f358=0; f350=0; f354=0; f360=0;
}

// @0x1404ccbd0
__int64 CGuildInfo::FUN_1404ccbd0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f38; }
}

// @0x1404ccc40
void CGuildInfo::FUN_1404ccc40(__int64 v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f38=v; }
}

// @0x1404cccb0
CStringW CGuildInfo::FUN_1404cccb0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f40; }
}

// @0x1404ccd40
void CGuildInfo::FUN_1404ccd40(const CStringW& v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f40=v; }
}

// @0x1404ccdb0
CString CGuildInfo::FUN_1404ccdb0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f48; }
}

// @0x1404cce40
void CGuildInfo::FUN_1404cce40(CString v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f48=v; }
}

// @0x1404ccec0
__int64 CGuildInfo::FUN_1404ccec0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f68; }
}

// @0x1404ccf30
void CGuildInfo::FUN_1404ccf30(__int64 v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f68=v; }
}

// @0x1404ccfa0
CStringW CGuildInfo::FUN_1404ccfa0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f58; }
}

// @0x1404cd030
void CGuildInfo::FUN_1404cd030(CStringW v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f58=v; }
}

// @0x1404cd0b0
CStringW CGuildInfo::FUN_1404cd0b0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f60; }
}

// @0x1404cd140
void CGuildInfo::FUN_1404cd140(CStringW v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f60=v; }
}

// @0x1404cd1c0
int CGuildInfo::FUN_1404cd1c0()
{
    Unk_GuildMapLock guard(lock,1);
    Unk_PayloadPtr<CGuildXmlData::GuildProperty> prop=TSingleton<CGuildXmlData>::GetInstance()->FUN_1404d7410(FUN_1404d1ad0());
    if(prop==0) return f50;
    return (std::max)(prop->f20,f50);
}

// @0x1404cd2b0
void CGuildInfo::FUN_1404cd2b0(int v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f50=v; }
}

// @0x1404cd310
void CGuildInfo::FUN_1404cd310(__int64 a,__int64 b,CStringW c,int)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f70=a; f78=b; f80=c; }
}

// @0x1404cd3b0
__int64 CGuildInfo::FUN_1404cd3b0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f70; }
}

// @0x1404cd420
__int64 CGuildInfo::FUN_1404cd420()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f78; }
}

// @0x1404cd490
CStringW CGuildInfo::FUN_1404cd490()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f80; }
}

// @0x1404cd530
__int64 CGuildInfo::FUN_1404cd530()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f88; }
}

// @0x1404cd5b0
void CGuildInfo::FUN_1404cd5b0(__int64 v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f88=v; }
}

// @0x1404cd620
__int64 CGuildInfo::FUN_1404cd620()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f90; }
}

// @0x1404cd6a0
void CGuildInfo::FUN_1404cd6a0(__int64 v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f90=v; }
}

// @0x1404cd710
void CGuildInfo::FUN_1404cd710(int a,__int64 b,__int64 c,CStringW d)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { fc4=a; fc8=b; fd0=c; fd8=d; }
}

// @0x1404cd7d0
void CGuildInfo::FUN_1404cd7d0(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        out.WriteInt64(FUN_1404ccbd0());
        out.WriteUnicodeString(FUN_1404cccb0());
        out.WriteUnicodeStringA(FUN_1404ccdb0());
        out.WriteUInt8((unsigned char)FUN_1404cd1c0());
        out.WriteUnicodeString(FUN_1404ccfa0());
        out.WriteUnicodeString(FUN_1404cd0b0());
        out.WriteInt64(FUN_1404cd3b0());
        out.WriteInt64(FUN_1404cd420());
        out.WriteUnicodeString(FUN_1404cd490());
        out.WriteInt64(f68);
        out.WriteUInt8((unsigned char)f130);
        out.WriteInt32(f134); out.WriteInt32(f138); out.WriteInt32(f13c); out.WriteInt32(f140);
        out.WriteInt32(f144); out.WriteInt32(f148); out.WriteInt32(f14c); out.WriteInt32(f358);
        out.WriteUInt8((unsigned char)f154);
        out.WriteInt32(f158); out.WriteInt32(f15c); out.WriteInt32(f160); out.WriteInt32(f164);
        out.WriteBool(reinterpret_cast<const bool&>(f354));
        out.WriteInt32(f350);
        FUN_1404ce690(out); FUN_1404ce8f0(out); FUN_1404ceb90(out); FUN_1404cee00(out);
        FUN_1404cf070(out); FUN_1404cf390(out); FUN_1404cf5f0(out);
        storage.FUN_1404cc160(out);
    }
}

// @0x1404cdda0
void CGuildInfo::FUN_1404cdda0(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        __int64 id=packet.ReadInt64();
        CStringW name=packet.ReadUnicodeString();
        CString code=packet.ReadUnicodeStringA();
        int b1=packet.ReadUInt8();
        CStringW s188=packet.ReadUnicodeString();
        CStringW s190=packet.ReadUnicodeString();
        __int64 l48=packet.ReadInt64();
        __int64 l50=packet.ReadInt64();
        CStringW s198=packet.ReadUnicodeString();
        __int64 l40=packet.ReadInt64();
        int b2=packet.ReadUInt8();
        int v6=packet.ReadInt32(); int v7=packet.ReadInt32(); int v8=packet.ReadInt32(); int v9=packet.ReadInt32();
        int v10=packet.ReadInt32(); int v11=packet.ReadInt32(); int v12=packet.ReadInt32(); int v13=packet.ReadInt32();
        int b3=packet.ReadUInt8();
        int v14=packet.ReadInt32(); int v15=packet.ReadInt32(); int v16=packet.ReadInt32(); int v17=packet.ReadInt32();
        f354=packet.ReadBool();
        f350=packet.ReadInt32();
        FUN_1404ccc40(id);
        FUN_1404ccd40(name);
        FUN_1404cce40(code);
        FUN_1404cd2b0(b1);
        FUN_1404cd140(s190);
        FUN_1404cd030(s188);
        FUN_1404cd310(l48,l50,s198,1);
        FUN_1404ccf30(l40);
        FUN_1404d11b0(v6,v7,v8,v9,v10,v11,v12);
        FUN_1404d1140(b2);
        FUN_1404d3600(v13);
        FUN_1404d17e0(b3,v14);
        FUN_1404d1940(v15);
        FUN_1404d1b40(v16,false);
        FUN_1404d1c90(v17,false);
        FUN_1404ce790(packet); FUN_1404cea10(packet); FUN_1404ceca0(packet); FUN_1404cef10(packet);
        FUN_1404cf1e0(packet); FUN_1404cf490(packet); FUN_1404cf6c0(packet);
        storage.FUN_1404cc210(packet);
    }
}

// @0x1404ce690
void CGuildInfo::FUN_1404ce690(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        int count=FUN_1404d0020();
        out.WriteUInt8(count);
        for(void* pos=FUN_1404f4510(&f320);pos!=0;FUN_1404f4700(&f320,&pos)) {
            MS2Ptr<CGuildMember> ref(reinterpret_cast<MS2Ptr<CGuildMember>&>(*FUN_1404f4f70(&f320,pos)));
            ref->FUN_1404cb420((COutPacket*)&out);
        }
    }
}

// @0x1404ce790
void CGuildInfo::FUN_1404ce790(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        int count=packet.ReadUInt8();
        for(int i=0;i<count;++i) {
            Unk_PayloadPtr<CGuildMember> member(new CGuildMember);
            member->FUN_1404cb450(&packet);
            vfunc_0(member);
        }
    }
}

// @0x1404ce8f0
void CGuildInfo::FUN_1404ce8f0(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        out.WriteUInt8((unsigned char)fa0.GetCount());
        for(unsigned i=0;i<fa0.GetCount();++i) {
            Unk_PayloadPtr<CGuildGrade> grade(fa0[i]);
            if(grade.get()!=0) grade->FUN_1404c7160(out);
        }
    }
}

// @0x1404cea10
void CGuildInfo::FUN_1404cea10(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        fa0.RemoveAll();
        int count=packet.ReadUInt8();
        fa0.SetCount(count);
        for(int i=0;i<count;++i) {
            Unk_PayloadPtr<CGuildGrade> grade(new CGuildGrade);
            grade->FUN_1404c71d0(packet);
            fa0.SetAt(i,grade);
        }
    }
}

// @0x1404ceb90
void CGuildInfo::FUN_1404ceb90(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        out.WriteUInt8(FUN_1404f4480(&f238));
        for(void* pos=FUN_1404f4cd0(&f238);pos!=0;FUN_1404f4660(&f238,&pos)) {
            Unk_PayloadPtr<CGuildSkill> ref(reinterpret_cast<Unk_PayloadPtr<CGuildSkill>&>(*FUN_1404f4e90(&f238,pos)));
            ref->FUN_1404cb9f0(out);
        }
    }
}

// @0x1404ceca0
void CGuildInfo::FUN_1404ceca0(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        f238.RemoveAll();
        int count=packet.ReadUInt8();
        for(int i=0;i<count;++i) {
            Unk_PayloadPtr<CGuildSkill> skill(new CGuildSkill);
            skill->FUN_1404cba60(packet);
            f238.SetAt(skill->f18,skill);
        }
    }
}

// @0x1404cee00
void CGuildInfo::FUN_1404cee00(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        out.WriteUInt8(FUN_1404f4470(&f280));
        for(void* pos=FUN_1404f4c60(&f280);pos!=0;FUN_1404f4610(&f280,&pos)) {
            Unk_PayloadPtr<CGuildCustomEvent> ref(reinterpret_cast<Unk_PayloadPtr<CGuildCustomEvent>&>(*FUN_1404f4e20(&f280,pos)));
            ref->FUN_1404cbe20(out);
        }
    }
}

// @0x1404cef10
void CGuildInfo::FUN_1404cef10(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        f280.RemoveAll();
        int count=packet.ReadUInt8();
        for(int i=0;i<count;++i) {
            Unk_PayloadPtr<CGuildCustomEvent> ev(new CGuildCustomEvent);
            ev->FUN_1404cbe70(packet);
            f280.SetAt(ev->f18,ev);
        }
    }
}

// @0x1404cf070
void CGuildInfo::FUN_1404cf070(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        out.WriteInt32(f168); out.WriteInt32(f16c);
        out.WriteInt32((int)f170.GetCount());
        for(POSITION pos=f170.GetStartPosition();pos!=0;f170.GetNext(pos)) {
            int key=f170.GetKeyAt(pos);
            out.WriteInt32(key);
            Unk_GuildStrEntry rec(f170.GetValueAt(pos));
            FUN_1404d3fe0((Unk_GuildStrRec*)&rec,&out);
        }
    }
}

// @0x1404cf1e0
void CGuildInfo::FUN_1404cf1e0(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        f170.RemoveAll();
        f168=packet.ReadInt32(); f16c=packet.ReadInt32();
        int count=packet.ReadInt32();
        for(int i=0;i<count;++i) {
            int key=packet.ReadInt32();
            Unk_GuildStrEntry rec;
            FUN_1404d4060((Unk_GuildStrRec*)&rec,&packet);
            f170.SetAt(key,rec);
        }
    }
}

// @0x1404cf390
void CGuildInfo::FUN_1404cf390(COutputStream& out)
{
    Unk_GuildMapLock guard(lock,1);
    out.WriteUInt8(FUN_1404f4490(&f2c8));
    for(void* pos=FUN_1404f4d40(&f2c8);pos!=0;FUN_1404f46b0(&f2c8,&pos)) {
        Unk_PayloadPtr<CGuildNpc> ref(reinterpret_cast<Unk_PayloadPtr<CGuildNpc>&>(*FUN_1404f4f00(&f2c8,pos)));
        ref->FUN_1404cc3f0(out);
    }
}

// @0x1404cf490
void CGuildInfo::FUN_1404cf490(CInPacket& packet)
{
    Unk_GuildMapLock guard(lock,1);
    FUN_1404f8a30(&f2c8);
    int count=packet.ReadUInt8();
    for(int i=0;i<count;++i) {
        Unk_GuildNpcRef ref(new CGuildNpc);
        FUN_1404f0b90(&ref)->FUN_1404cc440(packet);
        FUN_1404f9990(&f2c8,&FUN_1404f0b90(&ref)->f18,&ref);
    }
}

// @0x1404cf5f0
void CGuildInfo::FUN_1404cf5f0(COutputStream& out)
{
    Unk_GuildMapLock guard(lock,1);
    bool has=f360?true:false;
    out.WriteBool(has);
    if(f360) f360->FUN_1404d8d50(out);
}

// @0x1404cf6c0
void CGuildInfo::FUN_1404cf6c0(CInPacket& packet)
{
    Unk_GuildMapLock guard(lock,1);
    bool has=packet.ReadBool();
    if(has) {
        if(f360==0) {
            f360=new CGuildNpcShopMgr;
        }
        f360->FUN_1404d8e80(&packet);
    }
}

// @0x1404cf7d0
int CGuildInfo::vfunc_0(Unk_PayloadPtr<CGuildMember> member)
{
    if(member==0) return 0;
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        if((int)f320.GetCount()>=f50) return 0;
        f320.SetAt(member->data.FUN_1404ca890(),member);
        if(f310==0 && member->data.f08==f78) f310=member;
        return 1;
    }
}

// @0x1404cf970
void CGuildInfo::vfunc_1(CStringW name)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        FUN_1404f91b0(&f320,name);
    }
}

// @0x1404cf9f0
MS2Ptr<CGuildMember> CGuildInfo::FUN_1404cf9f0(CStringW name)
{
    if(name.IsEmpty())
        return MS2Ptr<CGuildMember>(0);
    MS2Ptr<CGuildMember> found(0);
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        FUN_1404f6070(&f320,name,found);
    }
    return found;
}

// @0x1404cfb00
MS2Ptr<CGuildMember> CGuildInfo::FUN_1404cfb00(__int64 id)
{
    MS2Ptr<CGuildMember> found(0);
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        for(void* pos=FUN_1404f4510(&f320); pos!=0; FUN_1404f4700(&f320,&pos)) {
            MS2Ptr<CGuildMember> member=reinterpret_cast<MS2Ptr<CGuildMember>&>(*FUN_1404f4f70(&f320,pos));
            if((member.get() ? true : false) && member->f18==id) {
                found=member;
                break;
            }
        }
    }
    return found;
}

// @0x1404cfc70
void CGuildInfo::FUN_1404cfc70(const CStringW& oldName,const CStringW& newName)
{
    MS2Ptr<CGuildMember> ref(0);
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        if(FUN_1404f6070(&f320,oldName,(Unk_GuildRef*)&ref)==1) {
            FUN_1404f91b0(&f320,oldName);
            ref->data.FUN_1404ca910(newName);
            FUN_1404f9ae0(&f320,newName,(Unk_GuildRef*)&ref);
        }
    }
}

// @0x1404cfdb0
void CGuildInfo::FUN_1404cfdb0(const CStringW& name,int value)
{
    MS2Ptr<CGuildMember> ref(0);
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        if(FUN_1404f6070(&f320,name,(Unk_GuildRef*)&ref)==1) ref->data.f20=value;
    }
}

// @0x1404cfe60
void CGuildInfo::FUN_1404cfe60(const CStringW& name,__int64 value)
{
    MS2Ptr<CGuildMember> ref(0);
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        if(FUN_1404f6070(&f320,name,(Unk_GuildRef*)&ref)==1) ref->fd8=value;
    }
}

// @0x1404cff20
int CGuildInfo::FUN_1404cff20()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        int count=0;
        for(POSITION pos=f320.GetHeadPosition();pos!=0;f320.GetNext(pos)) {
            Unk_PayloadPtr<CGuildMember> member(f320.GetValueAt(pos));
            if(member->fb0==3) ++count;
        }
        return count;
    }
}

// @0x1404d0020
int CGuildInfo::FUN_1404d0020()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return FUN_1404f44b0(&f320); }
}

// @0x1404d00a0
Unk_PayloadPtr<CGuildMember> CGuildInfo::FUN_1404d00a0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f310; }
}

// @0x1404d0130
void CGuildInfo::FUN_1404d0130(Unk_PayloadPtr<CGuildMember> v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f310=v; }
}

// @0x1404d01b0
int CGuildInfo::FUN_1404d01b0(CStringW name)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        MS2Ptr<CGuildMember> member=FUN_1404cf9f0(name);
        if(member==0) return FALSE;
        if(member->data.f08==f78) return TRUE;
        else return FALSE;
    }
}

// @0x1404d0330
void CGuildInfo::FUN_1404d0330(void* out)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        for(void* pos=FUN_1404f4510(&f320);pos!=0;FUN_1404f4700(&f320,&pos)) {
            MS2Ptr<CGuildMember> ref(reinterpret_cast<MS2Ptr<CGuildMember>&>(*FUN_1404f4f70(&f320,pos)));
            if(ref->fb0==3) FUN_140212bf0(out,ref->data.f08);
        }
    }
}

// @0x1404d0420
void CGuildInfo::FUN_1404d0420(void* out)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        for(void* pos=FUN_1404f4510(&f320);pos!=0;FUN_1404f4700(&f320,&pos)) {
            MS2Ptr<CGuildMember> ref(reinterpret_cast<MS2Ptr<CGuildMember>&>(*FUN_1404f4f70(&f320,pos)));
            if(ref->fb0==3) FUN_1404f31c0(out,(Unk_GuildRef*)&ref);
        }
    }
}

// @0x1404d0510
int CGuildInfo::FUN_1404d0510()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return fc0; }
}

// @0x1404d0580
int CGuildInfo::FUN_1404d0580()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return (int)(FUN_1404f4440(&fa0)-1); }
}

// @0x1404d0600
int CGuildInfo::FUN_1404d0600(CStringW name,unsigned mask)
{
    unsigned v=FUN_1404d06a0(name);
    if ((v&mask)!=0)
        return 1;
    return 0;
}

// @0x1404d06a0
unsigned CGuildInfo::FUN_1404d06a0(CStringW name)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        MS2Ptr<CGuildMember> member=FUN_1404cf9f0(name);
        if(member==0) return 0;
        Unk_PayloadPtr<CGuildGrade> grade=FUN_1404d0860(member->fb4);
        if(grade.get()!=0) {
            return grade->permissions;
        } else {
            return 0;
        }
    }
}

// @0x1404d0860
Unk_PayloadPtr<CGuildGrade> CGuildInfo::FUN_1404d0860(int index)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        if(fa0.GetCount()==0) return 0;
        if(index<0 || index>FUN_1404d0580()) {
            return 0;
        } else {
            return fa0[index];
        }
    }
}

// @0x1404d0990
int CGuildInfo::FUN_1404d0990(int index,Unk_PayloadPtr<CGuildGrade> grade)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        if(FUN_1404d0860(index)==0) {
            if(index!=FUN_1404d0580()+1) return 0;
            fa0.Add(grade);
        } else {
            fa0.SetAt(index,grade);
        }
        fc0=0;
        return 1;
    }
}

// @0x1404d0af0
CStringW CGuildInfo::FUN_1404d0af0(int index)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        Unk_PayloadPtr<CGuildGrade> grade=FUN_1404d0860(index);
        if(grade.get()!=0) return grade->name;
        return L"";
    }
}

// @0x1404d0c00
int CGuildInfo::FUN_1404d0c00()
{
    int total=0;
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        for(void* pos=FUN_1404f4510(&f320);pos!=0;FUN_1404f4700(&f320,&pos)) {
            MS2Ptr<CGuildMember> ref(reinterpret_cast<MS2Ptr<CGuildMember>&>(*FUN_1404f4f70(&f320,pos)));
            total=total+ref->FUN_1404cb3b0();
        }
    }
    total=total+f358;
    return total;
}

// @0x1404d0d00
int CGuildInfo::FUN_1404d0d00()
{
    int total=0;
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        for(void* pos=FUN_1404f4510(&f320);pos!=0;FUN_1404f4700(&f320,&pos)) {
            MS2Ptr<CGuildMember> ref(reinterpret_cast<MS2Ptr<CGuildMember>&>(*FUN_1404f4f70(&f320,pos)));
            total=total+(unsigned)(unsigned short)ref->data.f1c;
        }
    }
    return total;
}

// @0x1404d0df0
int CGuildInfo::FUN_1404d0df0()
{
    int total=0;
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        for(void* pos=FUN_1404f4510(&f320);pos!=0;FUN_1404f4700(&f320,&pos)) {
            MS2Ptr<CGuildMember> ref(reinterpret_cast<MS2Ptr<CGuildMember>&>(*FUN_1404f4f70(&f320,pos)));
            total=total+ref->data.f20;
        }
    }
    return total;
}

// @0x1404d0ee0
int CGuildInfo::FUN_1404d0ee0()
{
    int total=0;
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        for(void* pos=FUN_1404f4510(&f320);pos!=0;FUN_1404f4700(&f320,&pos)) {
            Unk_GuildMemberRef ref(*FUN_1404f4f70(&f320,pos));
            if(FUN_1404f0020(&ref,0))
                continue;
            total+=FUN_1404f0b80(&ref)->raid.FUN_1404cadc0();
        }
    }
    return total;
}

// @0x1404d0ff0
unsigned CGuildInfo::FUN_1404d0ff0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f134; }
}

// @0x1404d1060
void CGuildInfo::FUN_1404d1060(int v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f134=v; }
}

// @0x1404d10d0
unsigned CGuildInfo::FUN_1404d10d0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f130; }
}

// @0x1404d1140
void CGuildInfo::FUN_1404d1140(int v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f130=v; }
}

// @0x1404d11b0
void CGuildInfo::FUN_1404d11b0(int a,int b,int c,int d,int e,int f,int g)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f134=a; f138=b; f13c=c; f140=d; f144=e; f148=f; f14c=g; }
}

// @0x1404d1280
unsigned CGuildInfo::FUN_1404d1280()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f138; }
}

// @0x1404d12f0
void CGuildInfo::FUN_1404d12f0(int v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f138=v; }
}

// @0x1404d1360
unsigned CGuildInfo::FUN_1404d1360()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f13c; }
}

// @0x1404d13d0
void CGuildInfo::FUN_1404d13d0(int v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f13c=v; }
}

// @0x1404d1440
unsigned CGuildInfo::FUN_1404d1440()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f140; }
}

// @0x1404d14b0
unsigned CGuildInfo::FUN_1404d14b0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f144; }
}

// @0x1404d1520
void CGuildInfo::FUN_1404d1520(int v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f144=v; }
}

// @0x1404d1590
unsigned CGuildInfo::FUN_1404d1590()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f148; }
}

// @0x1404d1600
void CGuildInfo::FUN_1404d1600(int v)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f148=v; }
}

// @0x1404d1670
unsigned CGuildInfo::FUN_1404d1670()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f14c; }
}

// @0x1404d16e0
int CGuildInfo::FUN_1404d16e0()
{
    int total=0;
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        for(void* pos=FUN_1404f4510(&f320);pos!=0;FUN_1404f4700(&f320,&pos)) {
            MS2Ptr<CGuildMember> ref(reinterpret_cast<MS2Ptr<CGuildMember>&>(*FUN_1404f4f70(&f320,pos)));
            if(ref->fb0==3 && ref->f158==0) total=total+1;
        }
    }
    return total;
}

// @0x1404d17e0
void CGuildInfo::FUN_1404d17e0(int a,int b)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { f154=a; f158=b; }
}

// @0x1404d1860
unsigned CGuildInfo::FUN_1404d1860()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f154; }
}

// @0x1404d18d0
unsigned CGuildInfo::FUN_1404d18d0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f158; }
}

// @0x1404d1940
void CGuildInfo::FUN_1404d1940(int v)
{
    Unk_GuildMapLock guard(lock,1);
    f15c=v;
}

// @0x1404d1990
bool CGuildInfo::FUN_1404d1990(int delta)
{
    Unk_GuildMapLock guard(lock,1);
    int before=f15c;
    int limit=FUN_1404d7280(TSingleton<CGuildXmlData>::GetInstance());
    f15c=f15c+delta;
    if(f15c<0) f15c=0;
    if(f15c>limit) f15c=limit;
    if(before==f15c) return false;
    return true;
}

// @0x1404d1a80
int CGuildInfo::FUN_1404d1a80()
{
    Unk_GuildMapLock guard(lock,1);
    return f15c;
}

// @0x1404d1ad0
int CGuildInfo::FUN_1404d1ad0()
{
    Unk_GuildMapLock guard(lock,1);
    return FUN_1404d7130(TSingleton<CGuildXmlData>::GetInstance(),f15c);
}

// @0x1404d1b40
void CGuildInfo::FUN_1404d1b40(int v,bool bNotify)
{
    Unk_GuildMapLock guard(lock,1);
    f160=v;
}

// @0x1404d1ba0
bool CGuildInfo::FUN_1404d1ba0(int delta)
{
    Unk_GuildMapLock guard(lock,1);
    int before=f160;
    f160=f160+delta;
    int limit=FUN_1404d1e90();
    if(f160<0) f160=0;
    if(f160>limit) f160=limit;
    if(before==f160) return false;
    return true;
}

// @0x1404d1c90
void CGuildInfo::FUN_1404d1c90(int v,bool bNotify)
{
    Unk_GuildMapLock guard(lock,1);
    if(f164==v)
        return;
    f164=v;
}

// @0x1404d1d00
bool CGuildInfo::FUN_1404d1d00(int delta)
{
    Unk_GuildMapLock guard(lock,1);
    int before=f164;
    f164=f164+delta;
    int limit=FUN_1404d1f20();
    if(f164<0) f164=0;
    if(f164>limit) f164=limit;
    if(before==f164) return false;
    return true;
}

// @0x1404d1df0
int CGuildInfo::FUN_1404d1df0()
{
    Unk_GuildMapLock guard(lock,1);
    return f160;
}

// @0x1404d1e40
int CGuildInfo::FUN_1404d1e40()
{
    Unk_GuildMapLock guard(lock,1);
    return f164;
}

// @0x1404d1e90
int CGuildInfo::FUN_1404d1e90()
{
    int level=FUN_1404d1ad0();
    Unk_PayloadPtr<CGuildXmlData::GuildProperty> prop=TSingleton<CGuildXmlData>::GetInstance()->FUN_1404d7410(level);
    if(prop==0) return 0;
    return (int)prop->f28;
}

// @0x1404d1f20
int CGuildInfo::FUN_1404d1f20()
{
    return 0x7fffffff;
}

// @0x1404d1f40
void CGuildInfo::FUN_1404d1f40(int v)
{
    Unk_GuildMapLock guard(lock,1);
    f168=v;
}

// @0x1404d1f90
int CGuildInfo::FUN_1404d1f90()
{
    Unk_GuildMapLock guard(lock,1);
    return f168;
}

// @0x1404d1fe0
void CGuildInfo::FUN_1404d1fe0(int v)
{
    Unk_GuildMapLock guard(lock,1);
    f16c=v;
}

// @0x1404d2030
int CGuildInfo::FUN_1404d2030()
{
    Unk_GuildMapLock guard(lock,1);
    return f16c;
}

// @0x1404d2080
int CGuildInfo::FUN_1404d2080()
{
    Unk_GuildMapLock guard(lock,1);
    Unk_PayloadPtr<CGuildXmlData::GuildHouse> house=TSingleton<CGuildXmlData>::GetInstance()->FUN_1404d79b0(f168,f16c);
    if(house==0) return 0;
    return house->f50;
}

// @0x1404d2150
void CGuildInfo::vfunc_2(__int64 value,CStringW name,int key,const CStringW& text)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildStrEntry rec;
    rec.name=text;
    rec.value=value;
    rec.text=name;
    f170[key]=rec;
}

// @0x1404d2220
CStringW CGuildInfo::FUN_1404d2220(int key)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildStrEntry rec;
    if(f170.Lookup(key,rec)==true) {
        return rec.name;
    } else {
        return L"";
    }
}

// @0x1404d2330
__int64 CGuildInfo::FUN_1404d2330(int key)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildStrEntry rec;
    if(f170.Lookup(key,rec)==true) {
        return rec.value;
    } else {
        return 0;
    }
}

// @0x1404d2400
CStringW CGuildInfo::FUN_1404d2400(int key)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildStrEntry rec;
    if(f170.Lookup(key,rec)==true) {
        return rec.text;
    } else {
        return L"";
    }
}

// @0x1404d2510
int CGuildInfo::FUN_1404d2510(int a,int b)
{
    Unk_PayloadPtr<CGuildXmlData::GuildSkill> skill=TSingleton<CGuildXmlData>::GetInstance()->FUN_1404d74e0(a,b);
    if(skill==0) return 0x7fffffff;
    return skill->f28;
}

// @0x1404d25a0
void CGuildInfo::FUN_1404d25a0(Unk_PayloadPtr<CGuildSkill> skill)
{
    if(skill==0) return;
    Unk_GuildMapLock guard(lock,1);
    f238.SetAt(skill->f18,skill);
}

// @0x1404d2640
MS2Ptr<CGuildSkill> CGuildInfo::FUN_1404d2640(int key)
{
    Unk_GuildMapLock guard(lock,1);
    MS2Ptr<CGuildSkill> skill(0);
    FUN_1404f5f60(&f238,key,skill);
    return skill;
}

// @0x1404d26f0
int CGuildInfo::FUN_1404d26f0(int key)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_PayloadPtr<CGuildSkill> skill(0);
    if(f238.Lookup(key,skill)) return skill->f1c;
    return 0;
}

// @0x1404d27b0
MS2Ptr<CGuildCustomEvent> CGuildInfo::FUN_1404d27b0(int key)
{
    Unk_GuildMapLock guard(lock,1);
    MS2Ptr<CGuildCustomEvent> event(0);
    FUN_1404f5ef0(&f280,key,event);
    return event;
}

// @0x1404d2860
void CGuildInfo::FUN_1404d2860(Unk_PayloadPtr<CGuildNpc> npc)
{
    Unk_GuildMapLock guard(lock,1);
    f2c8.SetAt((Unk_GuildNpcKind&)npc->f18,npc);
}

// @0x1404d28e0
Unk_PayloadPtr<CGuildNpc> CGuildInfo::FUN_1404d28e0(int key)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_PayloadPtr<CGuildNpc> npc(0);
    f2c8.Lookup((Unk_GuildNpcKind&)key,npc);
    return npc;
}

// @0x1404d2990
int CGuildInfo::FUN_1404d2990(int key)
{
    Unk_PayloadPtr<CGuildNpc> npc=FUN_1404d28e0(key);
    if(npc==0) return 0;
    return npc->f1c;
}

// @0x1404d2a10
void CGuildInfo::FUN_1404d2a10(CInPacket* packet)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        if(f360==0) {
            f360=new CGuildNpcShopMgr;
        }
        f360->FUN_1404d8e80(packet);
    }
}

// @0x1404d2b00
void CGuildInfo::FUN_1404d2b00(int a,void* b)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else if(f360) {
        f360->FUN_1404d8ff0(a,(CInPacket*)b);
    }
}

// @0x1404d2ba0
void CGuildInfo::FUN_1404d2ba0(int a,void* b)
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else if(f360) {
        f360->FUN_1404d9060(a,(CInPacket*)b);
    }
}

// @0x1404d2c60
bool CGuildInfo::FUN_1404d2c60()
{
    return reinterpret_cast<const bool&>(f354);   // the exe field is a bool (f354 stays a byte for guildmanager's stores)
}

// @0x1404d2ca0
int CGuildInfo::FUN_1404d2ca0()
{
    return f350;
}

// @0x1404d2cc0
void CGuildInfo::FUN_1404d2cc0(ItemEntity* item)
{
    Unk_GuildMapLock guard(lock,1);
    std::pair<unsigned,int> key(item->vfunc_o18_0(),item->vfunc_o18_1());
    std::map<std::pair<unsigned,int>,ItemEntity>& items=storage.f18;
    items[key]=*item;
    if(item->m_count==0) items.erase(key);
}

// @0x1404d2db0
int CGuildInfo::FUN_1404d2db0(unsigned a,int b)
{
    Unk_GuildMapLock guard(lock,1);
    std::pair<unsigned,int> key(a,b);
    std::map<std::pair<unsigned,int>,ItemEntity>& items=storage.f18;
    std::map<std::pair<unsigned,int>,ItemEntity>::iterator it=items.find(key);
    if(it==items.end()) return 0;
    return it->second.m_count;
}

// @0x1404d2e90
void CGuildInfo::FUN_1404d2e90(const Unk_GuildHist* a,const Unk_GuildHist* b,const ItemEntity* item,__int64 c)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_PayloadPtr<CGuildStorage::CGuildStroageHistory> history(new CGuildStorage::CGuildStroageHistory);
    history->f18=*a;
    history->f30=*b;
    history->item=*item;
    history->f78=c;
    storage.f38.push_back(history);
    storage.f60.Add(history);
    int count=storage.f38.size();
    if(count>0x32) {
        int excess=count-0x32;
        for(int i=0;i<excess;++i) storage.f38.pop_front();
    }
}

// @0x1404d3050
void CGuildInfo::FUN_1404d3050(void* list)
{
    Unk_GuildMapLock guard(lock,1);
    FUN_140506ca0((char*)&storage+0x38);
    int n=FUN_1404f4450(list);
    for(int i=0;i<n;++i) {
        Unk_GuildRef* h=FUN_1404f0760(list,i);
        MS2_ASSERT_MSG_AT(0x988,L"pHistory != NULL",FUN_1404f0ae0(h));
        FUN_140509c90((char*)&storage+0x38,h);
    }
}

// @0x1404d3140
void CGuildInfo::FUN_1404d3140(const Unk_GuildSeason* s)
{
    season.FUN_1404c6030(*s);
}

// @0x1404d3180
Unk_GuildSeason* CGuildInfo::FUN_1404d3180()
{
    FUN_1404d31b0();
    return &season;
}

// @0x1404d31b0
void CGuildInfo::FUN_1404d31b0()
{
    MS2Ptr<CSeasonData> spData=CSeasonDataTable::GetInstance()->GetCurrent((SeasonRankType)2);
    if(spData==NULL) {
        season.FUN_1404c5d20();
        return;
    }
    if(season.id!=spData->m_nSeasonID) {
        season.id=spData->m_nSeasonID;
        season.name=spData->m_strDisplayName;
        season.begin=spData->m_start;
        season.end=spData->m_end;
        season.points[1]=spData->m_grades[0];
        season.points[2]=spData->m_grades[1];
        season.points[3]=spData->m_grades[2];
        season.points[4]=spData->m_grades[3];
        season.points[5]=spData->m_grades[4];
        season.points[6]=spData->m_grades[5];
        season.points[7]=spData->m_grades[6];
    }
}

// @0x1404d3400
int CGuildInfo::FUN_1404d3400(ATL::CAtlMap<__int64,__int64>* out)
{
    out->RemoveAll();
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        for(POSITION pos=f320.GetHeadPosition();pos!=NULL;f320.GetNext(pos)) {
            Unk_PayloadPtr<CGuildMember> spMember=f320.GetValueAt(pos);
            if(spMember==NULL) continue;
            if(spMember->f158!=0) continue;
            if(spMember->fb0!=3) continue;
            MS2Ptr<CFieldData> spField=CFieldData::FUN_140374140(spMember->data.f24);
            if(spField==NULL) continue;
            if(spField->HasTutorialType()==1) continue;
            out->SetAt(spMember->data.f08,spMember->data.f08);
        }
    }
    return (int)out->GetCount();
}

// @0x1404d3600
void CGuildInfo::FUN_1404d3600(int v)
{
    f358=v;
}

// @0x1404d3620
int CGuildInfo::FUN_1404d3620()
{
    return f358;
}

// @0x1404d3640
Unk_PayloadPtr<CGuildNpcShopMgr> CGuildInfo::FUN_1404d3640()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else { return f360; }
}

// @0x1404d36d0
void CGuildInfo::FUN_1404d36d0()
{
    if(Unk_LockGuard guard=lock) { __assume(0); } else {
        fa0.RemoveAll();
        fc0=1;
        for(int i=0;i<6;++i) {
            Unk_PayloadPtr<CGuildGrade> spGrade(new CGuildGrade);
            if(i==0) {
                spGrade->grade=0;
                spGrade->name=CommonString::GetInstance()->GetNarrowDefault(0x399);
                spGrade->permissions=0xfff;
            } else {
                spGrade->grade=i;
                spGrade->name="";
                spGrade->permissions=1;
                if(spGrade->grade==1) { spGrade->name=CommonString::GetInstance()->GetNarrowDefault(0x39a); }
                else if(spGrade->grade==2) { spGrade->name=CommonString::GetInstance()->GetNarrowDefault(0x39b); }
                else if(spGrade->grade==3) { spGrade->name=CommonString::GetInstance()->GetNarrowDefault(0x39c); }
                else if(spGrade->grade==4) { spGrade->name=CommonString::GetInstance()->GetNarrowDefault(0x39d); }
                else if(spGrade->grade==5) { spGrade->name=CommonString::GetInstance()->GetNarrowDefault(0x39e); }
            }
            fa0.Add(spGrade);
        }
    }
}


// @0x1404d3b80
void CGuildInfo::FUN_1404d3b80()
{
    Unk_GuildMapLock guard(lock,1);
    f238.RemoveAll();
    {
        std::vector<int> v1;
        TSingleton<CGuildXmlData>::GetInstance()->FUN_1404d7630(v1);
        for(unsigned __int64 i=0;i<v1.size();++i) {
            Unk_PayloadPtr<CGuildSkill> ref(new CGuildSkill);
            ref->f18=v1[i];
            ref->f1c=1;
            FUN_1404d25a0(ref);
        }
    }
    {
        std::vector<int> v2;
        TSingleton<CGuildXmlData>::GetInstance()->FUN_1404d7730(v2);
        for(unsigned __int64 i=0;i<v2.size();++i) {
            Unk_PayloadPtr<CGuildSkill> ref(new CGuildSkill);
            ref->f18=v2[i];
            ref->f1c=1;
            FUN_1404d25a0(ref);
        }
    }
}

// @0x1404d3e70
void CGuildInfo::FUN_1404d3e70()
{
    Unk_GuildMapLock guard(lock,1);
    f280.RemoveAll();
    std::vector<int> v;
    TSingleton<CGuildXmlData>::GetInstance()->FUN_1404d7900(v);
    for(unsigned __int64 i=0;i<v.size();++i) {
        Unk_PayloadPtr<CGuildCustomEvent> ref(new CGuildCustomEvent);
        ref->f18=v[i];
        f280.SetAt(ref->f18,ref);
    }
}

// @0x1404d3fe0
void FUN_1404d3fe0(Unk_GuildStrRec* rec,COutputStream* out)
{
    out->WriteUnicodeString(*(CStringW*)&rec->q0);
    out->WriteInt64(rec->q1);
    out->WriteUnicodeString(*(CStringW*)&rec->q2);
}

// @0x1404d4060
void FUN_1404d4060(Unk_GuildStrRec* rec,CInPacket* packet)
{
    *(CStringW*)&rec->q0=packet->ReadUnicodeString();
    rec->q1=packet->ReadInt64();
    *(CStringW*)&rec->q2=packet->ReadUnicodeString();
}
