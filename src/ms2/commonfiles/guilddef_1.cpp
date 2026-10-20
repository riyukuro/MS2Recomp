// Guild wire records and synchronized guild state (first recovered chunk).
// MS2-UNIT: commonfiles\guilddef.cpp#1
// MS2-RANGE: 0x1404c5c80-0x1404d4180 .text$mn
// MS2-FUNCTIONAL: chunk written as near-literal Ghidra translation (opaque container blobs); 135 of 283 functions differ in bytes only.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\guilddef.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "guilddef_1.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "hook/ms2hook.h"
__time64_t FUN_140869440();
int FUN_14086ace0(__int64);
// ---- helpers of the guild containers/smart pointers: defined in neighbouring chunks, reached by address ----
void* FUN_1404f4530();   // CGuildXmlData::GetInstance
void* FUN_1404f4540();
// CGuildMember map (CGuildInfo+0x320, key = name)
void* FUN_1404f4510(void* map); Unk_GuildRef* FUN_1404f4f70(void* map,void* pos); void FUN_1404f4700(void* map,void** pos);
unsigned FUN_1404f44b0(void* map);
char FUN_1404f6070(void* map,const wchar_t* key,Unk_GuildRef* out);
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
char FUN_1404f0020(Unk_GuildRef*,int);
__int64 FUN_1404f0ab0(Unk_GuildRef*);
void FUN_1404ef970(Unk_GuildRef* dst,Unk_GuildRef* src);
// CGuildGrade array (CGuildInfo+0xa0)
size_t FUN_1404f4440(void* arr); Unk_GuildRef* FUN_1404f0720(void* arr,__int64 index);
void FUN_1404f86e0(void* arr); void FUN_1404f9b50(void* arr,unsigned count,unsigned grow);
void FUN_1404f9730(void* arr,__int64 index,Unk_GuildRef* v); void FUN_1404f3110(void* arr,Unk_GuildRef* v);
void FUN_1404ec4d0(Unk_GuildRef*,Unk_GuildRef*); void FUN_1404ec510(Unk_GuildRef*,int); void FUN_1404ec530(Unk_GuildRef*,CGuildGrade*);
void FUN_1404eeaa0(Unk_GuildRef*); CGuildGrade* FUN_1404f0b70(Unk_GuildRef*); __int64 FUN_1404f0aa0(Unk_GuildRef*); char FUN_1404effe0(Unk_GuildRef*,int);
// CGuildSkill map (+0x238, key = skill id)
unsigned char FUN_1404f4480(void* map); void* FUN_1404f4cd0(void* map); Unk_GuildRef* FUN_1404f4e90(void* map,void* pos); void FUN_1404f4660(void* map,void** pos);
void FUN_1404f8920(void* map); void FUN_1404f98e0(void* map,int key,Unk_GuildRef* v); char FUN_1404f5f60(void* map,int key,Unk_GuildRef* out);
void FUN_1404ec940(Unk_GuildRef*,CGuildSkill*); void FUN_1404ec920(Unk_GuildRef*,int); void FUN_1404ec8e0(Unk_GuildRef*,Unk_GuildRef*); void FUN_1404ec8b0(Unk_GuildRef*,Unk_GuildRef*);
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
// Unk_GuildStrRec map (+0x170, key = int)
unsigned FUN_1404f4460(void* map); void* FUN_1404f4bf0(void* map); int* FUN_1404f4550(void* map,void* pos); Unk_GuildStrRec* FUN_1404f4db0(void* map,void* pos); void FUN_1404f45c0(void* map,void** pos);
void FUN_1404f8700(void* map); void FUN_1404f9780(void* map,int key,Unk_GuildStrRec* v); char FUN_1404f5e80(void* map,int key,Unk_GuildStrRec* out); Unk_GuildStrRec* FUN_1404f07a0(void* map,int key);
void FUN_1404ee6b0(Unk_GuildStrRec*); void FUN_1404ee640(Unk_GuildStrRec*,Unk_GuildStrRec*); void FUN_1404ef6e0(Unk_GuildStrRec*); void FUN_1404efdf0(Unk_GuildStrRec* dst,Unk_GuildStrRec* src);
// Npc shop manager handle (+0x360) and the manager itself
void FUN_1404ec820(Unk_GuildRef* dst,Unk_GuildRef* src); __int64 FUN_1404f0ad0(Unk_GuildRef*); void* FUN_1404f0bb0(Unk_GuildRef*); char FUN_1404f00e0(Unk_GuildRef*,int); void FUN_1404efb30(Unk_GuildRef*,void*);
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
char FUN_1404f0660(void*,void*); Unk_GuildRef* FUN_1404f0760(void*,int); void* FUN_1404f0990(void*,void*);
char FUN_1404f0ae0(Unk_GuildRef*); CGuildStorage::CGuildStroageHistory* FUN_1404f0bd0(Unk_GuildRef*); char* FUN_1404f0bf0(Unk_GuildRef*);
void* FUN_1404f0ce0(void*); void FUN_1404f14c0(void*); void FUN_1404f31c0(void*,Unk_GuildRef*); void FUN_1404f3270(void*,Unk_GuildRef*);
unsigned FUN_1404f4450(void*); size_t FUN_1404f44a0(void*); void FUN_1404f8b40(void*); void FUN_1404f8c50(void*);
void FUN_1404f9a40(void*,__int64,__int64); void FUN_1405063e0(void*,void*); void FUN_140506ac0(void*); void FUN_140506ca0(void*);
void* FUN_1405076d0(void*,void*); void FUN_1405085e0(void*,void*); void FUN_140508ed0(void*,void*,void*);
void FUN_1405098f0(void*); void FUN_1405099e0(void*,Unk_GuildRef*); void FUN_140509c90(void*,Unk_GuildRef*);
unsigned FUN_14050a000(void*); int FUN_14050a040(void*); void* FUN_14025e7d0(); CString* FUN_1402295b0(void*,CString*,int);
#define GSTR(n,dst) { __int64 b_; CString* c_=FUN_1402295b0(FUN_14025e7d0(),(CString*)&b_,n); dst=(const char*)*c_; c_->~CString(); }
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
    out.vfunc_o10_3(id); out.vfunc_o10_8(name); out.vfunc_o10_4(begin.Get()); out.vfunc_o10_4(end.Get()); for(int i=1;i<8;++i) out.vfunc_o10_3(points[i]);
}

// @0x1404c5ea0
void Unk_GuildSeason::FUN_1404c5ea0(CInPacket& packet)
{
    CInputStream& in=packet; id=in.vfunc_o8_3(); name=in.vfunc_o8_8(); begin=in.vfunc_o8_4(); end=in.vfunc_o8_4(); for(int i=1;i<8;++i) points[i]=in.vfunc_o8_3();
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
    for(int i=1;i<=7;++i) if(score<points[i]) return i-1; return 7;
}

// @0x1404c6160
int Unk_GuildSeason::FUN_1404c6160()
{
    CMsTime now(FUN_140869440()); return begin<now && end>now ? 1 : 0;
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
    if(other) { f18=other->f18; f1c=other->f1c; f20=other->f20; f28=other->f28; f30=other->f30; f38=other->f38; f40=other->f40; f48=other->f48; f4c=other->f4c; f50=other->f50; f54=other->f54; for(int i=0;i<5;++i) { f58[i]=other->f58[i]; f80[i]=other->f80[i]; fa8[i]=other->fa8[i]; } fb0=other->fb0; fb8=other->fb8; }
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
    out.vfunc_o10_3(f18); out.vfunc_o10_3(f1c); out.vfunc_o10_1(f20); out.vfunc_o10_4(f28); out.vfunc_o10_4(f30); out.vfunc_o10_8(f38); out.vfunc_o10_8(f40); out.vfunc_o10_3(f48); out.vfunc_o10_3(f4c); out.vfunc_o10_3(f50); out.vfunc_o10_3(f54); for(int i=0;i<5;++i) { out.vfunc_o10_8(f58[i]); out.vfunc_o10_8(f80[i]); out.vfunc_o10_1(fa8[i]); } out.vfunc_o10_4(fb0); out.vfunc_o10_4(fb8);
}

// @0x1404c6cb0
void CGuildPVPHistoryData::FUN_1404c6cb0(CInputStream& in)
{
    f18=in.vfunc_o8_3(); f1c=in.vfunc_o8_3(); f20=in.vfunc_o8_1(); f28=in.vfunc_o8_4(); f30=in.vfunc_o8_4(); f38=in.vfunc_o8_8(); f40=in.vfunc_o8_8(); f48=in.vfunc_o8_3(); f4c=in.vfunc_o8_3(); f50=in.vfunc_o8_3(); f54=in.vfunc_o8_3(); for(int i=0;i<5;++i) { f58[i]=in.vfunc_o8_8(); f80[i]=in.vfunc_o8_8(); fa8[i]=in.vfunc_o8_1(); } fb0=in.vfunc_o8_4(); fb8=in.vfunc_o8_4();
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
    out.vfunc_o10_1((unsigned char)grade); out.vfunc_o10_8(name); out.vfunc_o10_3(permissions);
}

// @0x1404c71d0
void CGuildGrade::FUN_1404c71d0(CInPacket& packet)
{
    CInputStream& in=packet; grade=in.vfunc_o8_1(); name=in.vfunc_o8_8(); permissions=in.vfunc_o8_3();
}

// @0x1404c72b0
int CGuildGrade::FUN_1404c72b0()
{
    if(grade<0 || grade>5) return 0; if(permissions<0 || permissions>4095) return 0; return 1;
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
    out.vfunc_o10_4(id); out.vfunc_o10_8(name); out.vfunc_o10_6(code);
}

// @0x1404c75a0
void CGuildNameInfo::FUN_1404c75a0(CInputStream& in)
{
    id=in.vfunc_o8_4(); name=in.vfunc_o8_8(); code=in.vfunc_o8_6();
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
    out.vfunc_o10_4(f18); out.vfunc_o10_4(f20); out.vfunc_o10_4(f28); out.vfunc_o10_4(f30); out.vfunc_o10_8(f38); out.vfunc_o10_6(f40); out.vfunc_o10_3(f48); out.vfunc_o10_3(f4c); out.vfunc_o10_3(f50); f54.FUN_140267f50(out); out.vfunc_o10_4(f60);
}

// @0x1404c7ad0
void CGuildJoinRequestForGuild::FUN_1404c7ad0(CInputStream& in)
{
    f18=in.vfunc_o8_4(); f20=in.vfunc_o8_4(); f28=in.vfunc_o8_4(); f30=in.vfunc_o8_4(); f38=in.vfunc_o8_8(); f40=in.vfunc_o8_6(); f48=in.vfunc_o8_3(); f4c=in.vfunc_o8_3(); f50=in.vfunc_o8_3(); f54.FUN_140267fb0(in); f60=in.vfunc_o8_4();
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
    out.vfunc_o10_4(f18); out.vfunc_o10_4(f20); out.vfunc_o10_8(f28); out.vfunc_o10_3(f30); out.vfunc_o10_6(f38); f44.FUN_140267f50(out); out.vfunc_o10_3(f50); out.vfunc_o10_3(f40); out.vfunc_o10_8(f58); out.vfunc_o10_4(f60); out.vfunc_o10_4(f68); out.vfunc_o10_4(f70);
}

// @0x1404c8150
void CGuildJoinRequestForChar::FUN_1404c8150(CInputStream& in)
{
    f18=in.vfunc_o8_4(); f20=in.vfunc_o8_4(); f28=in.vfunc_o8_8(); f30=in.vfunc_o8_3(); f38=in.vfunc_o8_6(); f44.FUN_140267fb0(in); f50=in.vfunc_o8_3(); f40=in.vfunc_o8_3(); f58=in.vfunc_o8_8(); f60=in.vfunc_o8_4(); f68=in.vfunc_o8_4(); f70=in.vfunc_o8_4();
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
    FUN_1404c8410(); if(other) { f18=other->f18; f1c=other->f1c; }
}

// @0x1404c8490
int CGuildJoinRequestSchCond::FUN_1404c8490(const CGuildJoinRequestSchCond* other)
{
    if(!other) return 0; if(other->f18!=f18) return 0; return other->f1c==f1c ? 1 : 0;
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
    out.vfunc_o10_3(f18); out.vfunc_o10_3(f1c);
}

// @0x1404c85b0
void CGuildJoinRequestSchCond::FUN_1404c85b0(CInputStream& in)
{
    f18=in.vfunc_o8_3(); f1c=in.vfunc_o8_3();
}

// @0x1404c8600
int CGuildJoinRequestSchCond::FUN_1404c8600()
{
    return f1c==0 ? -1 : (f1c-1)/10;
}

// @0x1404c8650
int CGuildJoinRequestSchCond::FUN_1404c8650()
{
    int n=FUN_1404c8600(); return n==-1 ? 0 : n*90+1;
}

// @0x1404c86a0
int CGuildJoinRequestSchCond::FUN_1404c86a0()
{
    int n=FUN_1404c8600(); return n==-1 ? 0 : (n+1)*90;
}

// @0x1404c86f0
int CGuildJoinRequestSchCond::FUN_1404c86f0()
{
    return f1c==0 ? -1 : ((f1c-1)/10+1)*90;
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
    out.vfunc_o10_4(f18); out.vfunc_o10_8(f20); out.vfunc_o10_6(f28); f38.FUN_140267f50(out); out.vfunc_o10_3(f44); out.vfunc_o10_3(f30); out.vfunc_o10_3(f34); out.vfunc_o10_4(f48); out.vfunc_o10_4(f50); out.vfunc_o10_8(f58);
}

// @0x1404c8be0
void CSearchGuildJoin::FUN_1404c8be0(CInputStream& in)
{
    f18=in.vfunc_o8_4(); f20=in.vfunc_o8_8(); f28=in.vfunc_o8_6(); f38.FUN_140267fb0(in); f44=in.vfunc_o8_3(); f30=in.vfunc_o8_3(); f34=in.vfunc_o8_3(); f48=in.vfunc_o8_4(); f50=in.vfunc_o8_4(); f58=in.vfunc_o8_8();
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
    out.vfunc_o10_4(f18); out.vfunc_o10_8(f20); out.vfunc_o10_6(f28); out.vfunc_o10_8(f30); out.vfunc_o10_8(f38);
}

// @0x1404c9230
void CGuildInviteInfo::FUN_1404c9230(CInputStream& in)
{
    f18=in.vfunc_o8_4(); f20=in.vfunc_o8_8(); f28=in.vfunc_o8_6(); f30=in.vfunc_o8_8(); f38=in.vfunc_o8_8();
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
    out.vfunc_o10_3(f24);
}

// @0x1404c95f0
void Unk_GuildMemberData::FUN_1404c95f0(CInPacket& in)
{
    f24=in.vfunc_o8_3();
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
    out.vfunc_o10_8(FUN_1404ca890()); out.vfunc_o10_3(f14); out.vfunc_o10_3(f18); out.vfunc_o10_2(f1c); out.vfunc_o10_6(code);
}

// @0x1404c97a0
void Unk_GuildMemberData::FUN_1404c97a0(CInPacket& in)
{
    CStringW n; CString c; n=in.vfunc_o8_8(); f14=in.vfunc_o8_3(); f18=in.vfunc_o8_3(); f1c=in.vfunc_o8_2(); c=in.vfunc_o8_6(); FUN_1404ca910(n); FUN_1404caa00(c);
}

// @0x1404c99d0
void Unk_GuildMemberData::FUN_1404c99d0(COutputStream& out)
{
    out.vfunc_o10_4(f00); out.vfunc_o10_4(f08); out.vfunc_o10_8(FUN_1404ca890()); out.vfunc_o10_1(f10); out.vfunc_o10_3(f14); out.vfunc_o10_3(f18); out.vfunc_o10_2(f1c); out.vfunc_o10_3(f20); out.vfunc_o10_3(f24); out.vfunc_o10_2((short)f28); out.vfunc_o10_6(FUN_1404ca980()); out.vfunc_o10_3(f38); out.vfunc_o10_3(f3c); out.vfunc_o10_3(f40); out.vfunc_o10_4(f48); f2c.FUN_140267f50(out);
}

// @0x1404c9bd0
void Unk_GuildMemberData::FUN_1404c9bd0(CInputStream& in)
{
    CStringW n; CString c; f00=in.vfunc_o8_4(); f08=in.vfunc_o8_4(); n=in.vfunc_o8_8(); f10=in.vfunc_o8_1(); f14=in.vfunc_o8_3(); f18=in.vfunc_o8_3(); f1c=in.vfunc_o8_2(); f20=in.vfunc_o8_3(); f24=in.vfunc_o8_3(); f28=(unsigned short)in.vfunc_o8_2(); c=in.vfunc_o8_6(); f38=in.vfunc_o8_3(); f3c=in.vfunc_o8_3(); f40=in.vfunc_o8_3(); f48=in.vfunc_o8_4(); f2c.FUN_140267fb0(in); FUN_1404ca910(n); FUN_1404caa00(c);
}

// @0x1404c9ef0
void Unk_GuildMemberData::FUN_1404c9ef0(COutputStream& out)
{
    out.vfunc_o10_8(FUN_1404ca890()); out.vfunc_o10_3(f14); out.vfunc_o10_3(f18); out.vfunc_o10_2(f1c); out.vfunc_o10_6(FUN_1404ca980());
}

// @0x1404c9fe0
void Unk_GuildMemberData::FUN_1404c9fe0(CInputStream& in)
{
    CStringW n; CString c; n=in.vfunc_o8_8(); f14=in.vfunc_o8_3(); f18=in.vfunc_o8_3(); f1c=in.vfunc_o8_2(); c=in.vfunc_o8_6(); FUN_1404ca910(n); FUN_1404caa00(c);
}

// @0x1404ca1a0
void Unk_GuildMemberData::FUN_1404ca1a0(const Unk_GuildMemberData& other)
{
    CStringW n; CString c; f00=other.f00; f08=other.f08; n=other.name; f10=other.f10; f14=other.f14; f18=other.f18; f1c=other.f1c; f20=other.f20; f24=other.f24; f28=other.f28; c=other.code; f38=other.f38; f3c=other.f3c; f40=other.f40; f48=other.f48; f2c.FUN_140267ea0(other.f2c); FUN_1404ca910(n); FUN_1404caa00(c);
}

// @0x1404ca3e0
void Unk_GuildMemberData::FUN_1404ca3e0(Unk_GuildCharacter* other)
{
    CStringW n; CString c;
    const char* raw=reinterpret_cast<const char*>(other);
    f00=*reinterpret_cast<const __int64*>(raw); f08=*reinterpret_cast<const __int64*>(raw+8);
    n=other->FUN_1408f19e0(); f10=*reinterpret_cast<const unsigned char*>(raw+0x14);
    f14=*reinterpret_cast<const int*>(raw+0x3c); f18=*reinterpret_cast<const int*>(raw+0x40); f1c=*reinterpret_cast<const short*>(raw+0x34);
    f20=*reinterpret_cast<const int*>(raw+0xd0); f24=*reinterpret_cast<const int*>(raw+0x2c); f28=*reinterpret_cast<const int*>(raw+0x38);
    c=other->FUN_1408f1a60(); f38=*reinterpret_cast<const int*>(raw+0x98); f3c=*reinterpret_cast<const int*>(raw+0x9c); f40=*reinterpret_cast<const int*>(raw+0xa0); f48=*reinterpret_cast<const __int64*>(raw+0xa8);
    f2c.FUN_140267ea0(*reinterpret_cast<const Unk_GuildTriple*>(raw+0xd4)); FUN_1404ca910(n); FUN_1404caa00(c);
}

// @0x1404ca680
void Unk_GuildMemberData::FUN_1404ca680(const CGuildJoinRequestForGuild* other)
{
    if(other) { CStringW n; CString c; f00=other->f28; f08=other->f30; n=other->f38; f10=0; f14=other->f48; f18=other->f4c; f1c=(short)other->f50; f20=0; f24=0; f28=1; c=other->f40; f38=0; f3c=0; f40=0; f48=0; f2c.FUN_140267ea0(other->f54); FUN_1404ca910(n); FUN_1404caa00(c); }
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
    Unk_GuildMapLock guard(lock,1); auto i=raids.find(id); if(i==raids.end() || i->second<count) { FUN_1404cad50(id,count,false); return true; } return false;
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
    Unk_GuildMapLock guard(lock,1); auto i=raids.begin(),end=raids.end(); out.vfunc_o10_3((int)raids.size()); while(i!=end) { out.vfunc_o10_3(i->first); out.vfunc_o10_3(i->second); ++i; }
}

// @0x1404cb070
void CGuildMemberRaid::FUN_1404cb070(CInputStream& in)
{
    Unk_GuildMapLock guard(lock,1); raids.clear(); int count=in.vfunc_o8_3(); for(int i=0;i<count;++i) { unsigned long id=in.vfunc_o8_3(); int value=in.vfunc_o8_3(); raids[id]=value; }
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
    return FUN_14086ace0(ff8)==1 ? 0 : ff0;
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
    out.vfunc_o10_1((unsigned char)fb0); out.vfunc_o10_1((unsigned char)fb4); if(fb0==3) { out.vfunc_o10_4(f18); data.FUN_1404c99d0(out); out.vfunc_o10_8(fb8); out.vfunc_o10_4(fc8); out.vfunc_o10_4(fd0); out.vfunc_o10_4(fd8); out.vfunc_o10_3(fe0); out.vfunc_o10_3(fe4); out.vfunc_o10_3(fe8); out.vfunc_o10_3(fec); out.vfunc_o10_3(ff0); out.vfunc_o10_4(ff8); raid.FUN_1404caf50(out); out.vfunc_o10_1((unsigned char)f158); } else { out.vfunc_o10_4(f18); data.FUN_1404c9ef0(out); }
}

// @0x1404cb6c0
void CGuildMember::FUN_1404cb6c0(CInputStream& in)
{
    fb0=in.vfunc_o8_1(); fb4=in.vfunc_o8_1(); if(fb0==3) { f18=in.vfunc_o8_4(); data.FUN_1404c9bd0(in); fb8=in.vfunc_o8_8(); fc8=in.vfunc_o8_4(); fd0=in.vfunc_o8_4(); fd8=in.vfunc_o8_4(); fe0=in.vfunc_o8_3(); fe4=in.vfunc_o8_3(); fe8=in.vfunc_o8_3(); fec=in.vfunc_o8_3(); ff0=in.vfunc_o8_3(); ff8=in.vfunc_o8_4(); raid.FUN_1404cb070(in); f158=in.vfunc_o8_1(); } else { f18=in.vfunc_o8_4(); data.FUN_1404c9fe0(in); }
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
    out.vfunc_o10_3(f18); out.vfunc_o10_3(f1c); out.vfunc_o10_4(f20);
}

// @0x1404cba60
void CGuildSkill::FUN_1404cba60(CInPacket& packet)
{
    CInputStream& in=packet; f18=in.vfunc_o8_3(); f1c=in.vfunc_o8_3(); f20=in.vfunc_o8_4();
}

// MS2-FUNCTIONAL: the guild smart-pointer/record temporaries are raw Unk_Guild* structs driven by explicit FUN_ ctor/dtor calls; the exe objects have real dtors (EH states + dtor ordering) - frame differs
// @0x1404cbb00
int CGuildSkill::FUN_1404cbb00()
{
    if(f20==0) return 0;
    void* xml=FUN_1404f4530(); Unk_GuildRef ref; FUN_1404d74e0(xml,&ref,f18,f1c);
    if(FUN_1404effa0(&ref,0)==0) {
        __int64 now=FUN_140869440(); __int64 until=(__int64)*(int*)(FUN_1404f0b50(&ref)+0x2c)+f20;
        if(until<now) { FUN_1404eea40(&ref); return 0; }
        int left=(int)until-(int)now; FUN_1404eea40(&ref); return left;
    }
    FUN_1404eea40(&ref); return 0;
}

// MS2-FUNCTIONAL: the guild smart-pointer/record temporaries are raw Unk_Guild* structs driven by explicit FUN_ ctor/dtor calls; the exe objects have real dtors (EH states + dtor ordering) - frame differs
// @0x1404cbbf0
int CGuildSkill::FUN_1404cbbf0()
{
    void* xml=FUN_1404f4530(); Unk_GuildRef ref; FUN_1404d74e0(xml,&ref,f18,f1c);
    if(FUN_1404effa0(&ref,0)==0) {
        __int64 now=FUN_140869440(); __int64 until=(__int64)*(int*)(FUN_1404f0b50(&ref)+0x30)+f20;
        if(until<now) { FUN_1404eea40(&ref); return 0; }
        int left=(int)until-(int)now; FUN_1404eea40(&ref); return left;
    }
    FUN_1404eea40(&ref); return 0x7fffffff;
}

// @0x1404cbcd0
bool CGuildSkill::FUN_1404cbcd0()
{
    if(FUN_1404cbb00()<1) { if(FUN_1404cbbf0()<1) return true; return false; }
    return false;
}

// @0x1404cbd20
bool CGuildSkill::FUN_1404cbd20()
{
    char ok=FUN_1404cbcd0();
    if(ok!=0) f20=FUN_140869440();
    return ok!=0;
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
    out.vfunc_o10_3(f18); out.vfunc_o10_3((int)f20);
}

// @0x1404cbe70
void CGuildCustomEvent::FUN_1404cbe70(CInPacket& packet)
{
    CInputStream& in=packet; f18=in.vfunc_o8_3(); unsigned v=in.vfunc_o8_3(); f20=(unsigned __int64)v;
}

// @0x1404cbee0
bool CGuildCustomEvent::FUN_1404cbee0()
{
    __int64 now=FUN_140869440(); __int64 until=f20+0x1e;
    return now<until;
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
    FUN_140506ac0(&f18); FUN_1404efd50(&f18,(void*)&other->f18);
}

// @0x1404cc160
void CGuildStorage::FUN_1404cc160(COutputStream& out)
{
    unsigned n=FUN_14050a000(&f18); out.vfunc_o10_3(n);
    void* it; void* endBuf[3]; FUN_1405063e0(&f18,&it);
    while(FUN_1404f0660(&it,FUN_1405076d0(&f18,endBuf))!=0) {
        char* pair=(char*)FUN_1404f0ce0(&it); ((ItemEntity*)(pair+8))->FUN_14026b030(*(Unk_GiftOutput*)&out); FUN_1404f14c0(&it);
    }
}

// @0x1404cc210
void CGuildStorage::FUN_1404cc210(CInPacket& packet)
{
    FUN_140506ac0(&f18);
    CInputStream& in=packet; unsigned count=in.vfunc_o8_3();
    for(unsigned __int64 i=0;i<count;++i) {
        ItemEntity item; item.FUN_14026b100(*(Unk_GiftInput*)&in);
        int rank=item.vfunc_o18_1(); int id=item.vfunc_o18_0(); Unk_GuildPair key; FUN_140407ed0(&key,&id,&rank);
        FUN_1404efe60(FUN_1404f0990(&f18,&key),&item);
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
    out.vfunc_o10_3(f18); out.vfunc_o10_3(f1c);
}

// @0x1404cc440
void CGuildNpc::FUN_1404cc440(CInPacket& packet)
{
    CInputStream& in=packet; f18=in.vfunc_o8_3(); f1c=in.vfunc_o8_3();
}

// MS2-FUNCTIONAL: CGuildInfo members are raw blobs constructed through explicit FUN_ ctor calls; the exe member ctors carry EH states and one fewer call (23 vs 22)
// @0x1404cc4b0
CGuildInfo::CGuildInfo()
{
    season.FUN_1404c5d20();
    f150=1000;
    FUN_1404ebaf0(&f170,0x11,0.75f,0.25f,2.25f,10);
    FUN_1404ebcd0(&f238,0x11,0.75f,0.25f,2.25f,10);
    FUN_1404ebbe0(&f280,0x11,0.75f,0.25f,2.25f,10);
    FUN_1404ebdc0(&f2c8,0x11,0.75f,0.25f,2.25f,10);
    FUN_1404ec640(&f310); FUN_1404ebeb0(&f320,10);
    f358=0; FUN_1404ec890(&f360);
    FUN_1404cc900();
    void* mem=operator new(0x28); void* mgr=mem ? FUN_1404ee230(mem) : 0;
    FUN_1404efb30(&f360,mgr);
}

// MS2-FUNCTIONAL: CGuildInfo members are raw blobs destroyed through explicit FUN_ dtor calls; the exe implicit member dtors form a different frame
// @0x1404cc780
CGuildInfo::~CGuildInfo()
{
    FUN_1404eeb60(&f360); FUN_1404ee8a0(&f320); FUN_1404eead0(&f310); FUN_1404ee870(&f2c8); FUN_1404ee810(&f280); FUN_1404ee840(&f238);
    FUN_1404ee7e0(&f170);
}

// @0x1404cc900
void CGuildInfo::FUN_1404cc900()
{
    f38=0; f40=L""; f48=""; f50=0; f58=L""; f60=L""; f68=0; f70=0; f78=0; f80=L""; f88=0; f90=0; f98=L"";
    fc0=0; fc4=0; fd8.Empty(); fc8=0; fd0=0;
    f130=0; f134=f150; f138=0; f13c=0; f140=0; f144=0; f148=0; f14c=0; f154=1; f158=0; f15c=0; f160=0; f164=0; f168=1; f16c=1;
    FUN_1404f8700(&f170); FUN_1404ef9b0(&f310,0); FUN_1404f8c50(&f320);
    f358=0; f350=0; f354=0; FUN_1404efb00(&f360,0);
}

// @0x1404ccbd0
__int64 CGuildInfo::FUN_1404ccbd0()
{
    { if(Unk_LockGuard guard=lock) {} else { return f38; } }
}

// @0x1404ccc40
void CGuildInfo::FUN_1404ccc40(__int64 v)
{
    if(Unk_LockGuard guard=lock) {} else { f38=v; }
}

// @0x1404cccb0
CStringW CGuildInfo::FUN_1404cccb0()
{
    { if(Unk_LockGuard guard=lock) {} else { return f40; } }
}

// @0x1404ccd40
void CGuildInfo::FUN_1404ccd40(const CStringW& v)
{
    if(Unk_LockGuard guard=lock) {} else { f40=v; }
}

// @0x1404ccdb0
CString CGuildInfo::FUN_1404ccdb0()
{
    { if(Unk_LockGuard guard=lock) {} else { return f48; } }
}

// @0x1404cce40
void CGuildInfo::FUN_1404cce40(CString v)
{
    if(Unk_LockGuard guard=lock) {} else { f48=v; }
}

// @0x1404ccec0
__int64 CGuildInfo::FUN_1404ccec0()
{
    { if(Unk_LockGuard guard=lock) {} else { return f68; } }
}

// @0x1404ccf30
void CGuildInfo::FUN_1404ccf30(__int64 v)
{
    if(Unk_LockGuard guard=lock) {} else { f68=v; }
}

// @0x1404ccfa0
CStringW CGuildInfo::FUN_1404ccfa0()
{
    { if(Unk_LockGuard guard=lock) {} else { return f58; } }
}

// @0x1404cd030
void CGuildInfo::FUN_1404cd030(CStringW v)
{
    if(Unk_LockGuard guard=lock) {} else { f58=v; }
}

// @0x1404cd0b0
CStringW CGuildInfo::FUN_1404cd0b0()
{
    { if(Unk_LockGuard guard=lock) {} else { return f60; } }
}

// @0x1404cd140
void CGuildInfo::FUN_1404cd140(CStringW v)
{
    if(Unk_LockGuard guard=lock) {} else { f60=v; }
}

// @0x1404cd1c0
int CGuildInfo::FUN_1404cd1c0()
{
    Unk_GuildMapLock guard(lock,1);
    int key=FUN_1404d1ad0(); void* xml=FUN_1404f4530(); Unk_GuildRef ref; FUN_1404d7410(xml,&ref,key);
    if(FUN_1404eff60(&ref,0)==0) {
        void* mapKey=&f50; int* p=FUN_1404eb7e0(FUN_1404f0b30(&ref)+0x20,mapKey); int v=*p; FUN_1404ee9b0(&ref); return v;
    }
    int v=f50; FUN_1404ee9b0(&ref); return v;
}

// @0x1404cd2b0
void CGuildInfo::FUN_1404cd2b0(int v)
{
    if(Unk_LockGuard guard=lock) {} else { f50=v; }
}

// @0x1404cd310
void CGuildInfo::FUN_1404cd310(__int64 a,__int64 b,CStringW c,int)
{
    if(Unk_LockGuard guard=lock) {} else { f70=a; f78=b; f80=c; }
}

// @0x1404cd3b0
__int64 CGuildInfo::FUN_1404cd3b0()
{
    { if(Unk_LockGuard guard=lock) {} else { return f70; } }
}

// @0x1404cd420
__int64 CGuildInfo::FUN_1404cd420()
{
    { if(Unk_LockGuard guard=lock) {} else { return f78; } }
}

// @0x1404cd490
CStringW CGuildInfo::FUN_1404cd490()
{
    { if(Unk_LockGuard guard=lock) {} else { return f80; } }
}

// @0x1404cd530
__int64 CGuildInfo::FUN_1404cd530()
{
    { if(Unk_LockGuard guard=lock) {} else { return f88; } }
}

// @0x1404cd5b0
void CGuildInfo::FUN_1404cd5b0(__int64 v)
{
    if(Unk_LockGuard guard=lock) {} else { f88=v; }
}

// @0x1404cd620
__int64 CGuildInfo::FUN_1404cd620()
{
    { if(Unk_LockGuard guard=lock) {} else { return f90; } }
}

// @0x1404cd6a0
void CGuildInfo::FUN_1404cd6a0(__int64 v)
{
    if(Unk_LockGuard guard=lock) {} else { f90=v; }
}

// @0x1404cd710
void CGuildInfo::FUN_1404cd710(int a,__int64 b,__int64 c,CStringW d)
{
    if(Unk_LockGuard guard=lock) {} else { fc4=a; fc8=b; fd0=c; fd8=d; }
}

// @0x1404cd7d0
void CGuildInfo::FUN_1404cd7d0(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) {} else {
        out.vfunc_o10_4(FUN_1404ccbd0());
        out.vfunc_o10_8(FUN_1404cccb0());
        out.vfunc_o10_6(FUN_1404ccdb0());
        out.vfunc_o10_1((unsigned char)FUN_1404cd1c0());
        out.vfunc_o10_8(FUN_1404ccfa0());
        out.vfunc_o10_8(FUN_1404cd0b0());
        out.vfunc_o10_4(FUN_1404cd3b0());
        out.vfunc_o10_4(FUN_1404cd420());
        out.vfunc_o10_8(FUN_1404cd490());
        out.vfunc_o10_4(f68);
        out.vfunc_o10_1((unsigned char)f130);
        out.vfunc_o10_3(f134); out.vfunc_o10_3(f138); out.vfunc_o10_3(f13c); out.vfunc_o10_3(f140);
        out.vfunc_o10_3(f144); out.vfunc_o10_3(f148); out.vfunc_o10_3(f14c); out.vfunc_o10_3(f358);
        out.vfunc_o10_1((unsigned char)f154);
        out.vfunc_o10_3(f158); out.vfunc_o10_3(f15c); out.vfunc_o10_3(f160); out.vfunc_o10_3(f164);
        out.vfunc_o10_0(f354 ? true : false);
        out.vfunc_o10_3(f350);
        FUN_1404ce690(out); FUN_1404ce8f0(out); FUN_1404ceb90(out); FUN_1404cee00(out);
        FUN_1404cf070(out); FUN_1404cf390(out); FUN_1404cf5f0(out);
        storage.FUN_1404cc160(out);
    }
}

// @0x1404cdda0
void CGuildInfo::FUN_1404cdda0(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) {} else {
        CInputStream& in=packet;
        __int64 id=in.vfunc_o8_4();
        CStringW name=in.vfunc_o8_8();
        CString code=in.vfunc_o8_6();
        unsigned char b1=in.vfunc_o8_1();
        CStringW s188=in.vfunc_o8_8();
        CStringW s190=in.vfunc_o8_8();
        __int64 l48=in.vfunc_o8_4();
        __int64 l50=in.vfunc_o8_4();
        CStringW s198=in.vfunc_o8_8();
        __int64 l40=in.vfunc_o8_4();
        unsigned char b2=in.vfunc_o8_1();
        int v6=in.vfunc_o8_3(); int v7=in.vfunc_o8_3(); int v8=in.vfunc_o8_3(); int v9=in.vfunc_o8_3();
        int v10=in.vfunc_o8_3(); int v11=in.vfunc_o8_3(); int v12=in.vfunc_o8_3(); int v13=in.vfunc_o8_3();
        unsigned char b3=in.vfunc_o8_1();
        int v14=in.vfunc_o8_3(); int v15=in.vfunc_o8_3(); int v16=in.vfunc_o8_3(); int v17=in.vfunc_o8_3();
        f354=in.vfunc_o8_0();
        f350=in.vfunc_o8_3();
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
        FUN_1404d1b40(v16);
        FUN_1404d1c90(v17);
        FUN_1404ce790(packet); FUN_1404cea10(packet); FUN_1404ceca0(packet); FUN_1404cef10(packet);
        FUN_1404cf1e0(packet); FUN_1404cf490(packet); FUN_1404cf6c0(packet);
        storage.FUN_1404cc210(packet);
    }
}

// @0x1404ce690
void CGuildInfo::FUN_1404ce690(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) {} else {
        out.vfunc_o10_1((unsigned char)FUN_1404d0020());
        void* pos=FUN_1404f4510(&f320);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec5b0(&ref,FUN_1404f4f70(&f320,pos));
            FUN_1404f0b80(&ref)->FUN_1404cb420((COutPacket*)&out);
            FUN_1404eead0(&ref);
            FUN_1404f4700(&f320,&pos);
        }
    }
}

// @0x1404ce790
void CGuildInfo::FUN_1404ce790(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) {} else {
        CInputStream& in=packet;
        unsigned char count=in.vfunc_o8_1();
        for(int i=0;i<(int)count;++i) {
            CGuildMember* member=new CGuildMember;
            Unk_GuildRef ref; FUN_1404ec610(&ref,member);
            FUN_1404f0b80(&ref)->FUN_1404cb450(&packet);
            Unk_GuildRef copy; FUN_1404ec5b0(&copy,&ref);
            vfunc_0(&copy);
            FUN_1404eead0(&ref);
        }
    }
}

// @0x1404ce8f0
void CGuildInfo::FUN_1404ce8f0(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) {} else {
        out.vfunc_o10_1((unsigned char)FUN_1404f4440(&fa0));
        for(int i=0;;++i) {
            __int64 index=i;
            if(FUN_1404f4440(&fa0)<=(unsigned __int64)index) break;
            Unk_GuildRef ref; FUN_1404ec4d0(&ref,FUN_1404f0720(&fa0,i));
            if(FUN_1404f0aa0(&ref)!=0) FUN_1404f0b70(&ref)->FUN_1404c7160(out);
            FUN_1404eeaa0(&ref);
        }
    }
}

// @0x1404cea10
void CGuildInfo::FUN_1404cea10(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) {} else {
        FUN_1404f86e0(&fa0);
        CInputStream& in=packet;
        unsigned char count=in.vfunc_o8_1();
        FUN_1404f9b50(&fa0,count,0xffffffff);
        for(int i=0;i<(int)count;++i) {
            CGuildGrade* grade=new CGuildGrade;
            Unk_GuildRef ref; FUN_1404ec530(&ref,grade);
            FUN_1404f0b70(&ref)->FUN_1404c71d0(packet);
            FUN_1404f9730(&fa0,i,&ref);
            FUN_1404eeaa0(&ref);
        }
    }
}

// @0x1404ceb90
void CGuildInfo::FUN_1404ceb90(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) {} else {
        out.vfunc_o10_1(FUN_1404f4480(&f238));
        void* pos=FUN_1404f4cd0(&f238);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec8e0(&ref,FUN_1404f4e90(&f238,pos));
            FUN_1404f0bc0(&ref)->FUN_1404cb9f0(out);
            FUN_1404eeb90(&ref);
            FUN_1404f4660(&f238,&pos);
        }
    }
}

// @0x1404ceca0
void CGuildInfo::FUN_1404ceca0(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) {} else {
        FUN_1404f8920(&f238);
        CInputStream& in=packet;
        unsigned char count=in.vfunc_o8_1();
        for(int i=0;i<(int)count;++i) {
            CGuildSkill* skill=new CGuildSkill;
            Unk_GuildRef ref; FUN_1404ec940(&ref,skill);
            FUN_1404f0bc0(&ref)->FUN_1404cba60(packet);
            FUN_1404f98e0(&f238,FUN_1404f0bc0(&ref)->f18,&ref);
            FUN_1404eeb90(&ref);
        }
    }
}

// @0x1404cee00
void CGuildInfo::FUN_1404cee00(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) {} else {
        out.vfunc_o10_1(FUN_1404f4470(&f280));
        void* pos=FUN_1404f4c60(&f280);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec420(&ref,FUN_1404f4e20(&f280,pos));
            FUN_1404f0b60(&ref)->FUN_1404cbe20(out);
            FUN_1404eea70(&ref);
            FUN_1404f4610(&f280,&pos);
        }
    }
}

// @0x1404cef10
void CGuildInfo::FUN_1404cef10(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) {} else {
        FUN_1404f8810(&f280);
        CInputStream& in=packet;
        unsigned char count=in.vfunc_o8_1();
        for(int i=0;i<(int)count;++i) {
            CGuildCustomEvent* ev=new CGuildCustomEvent;
            Unk_GuildRef ref; FUN_1404ec480(&ref,ev);
            FUN_1404f0b60(&ref)->FUN_1404cbe70(packet);
            FUN_1404f9830(&f280,FUN_1404f0b60(&ref)->f18,&ref);
            FUN_1404eea70(&ref);
        }
    }
}

// @0x1404cf070
void CGuildInfo::FUN_1404cf070(COutputStream& out)
{
    if(Unk_LockGuard guard=lock) {} else {
        out.vfunc_o10_3(f168); out.vfunc_o10_3(f16c);
        out.vfunc_o10_3(FUN_1404f4460(&f170));
        void* pos=FUN_1404f4bf0(&f170);
        while(pos!=0) {
            out.vfunc_o10_3(*FUN_1404f4550(&f170,pos));
            Unk_GuildStrRec rec; FUN_1404ee640(&rec,FUN_1404f4db0(&f170,pos));
            FUN_1404d3fe0(&rec,&out);
            FUN_1404ef6e0(&rec);
            FUN_1404f45c0(&f170,&pos);
        }
    }
}

// @0x1404cf1e0
void CGuildInfo::FUN_1404cf1e0(CInPacket& packet)
{
    if(Unk_LockGuard guard=lock) {} else {
        FUN_1404f8700(&f170);
        CInputStream& in=packet;
        f168=in.vfunc_o8_3(); f16c=in.vfunc_o8_3();
        int count=in.vfunc_o8_3();
        for(int i=0;i<count;++i) {
            int key=in.vfunc_o8_3();
            Unk_GuildStrRec rec; FUN_1404ee6b0(&rec);
            FUN_1404d4060(&rec,&packet);
            FUN_1404f9780(&f170,key,&rec);
            FUN_1404ef6e0(&rec);
        }
    }
}

// @0x1404cf390
void CGuildInfo::FUN_1404cf390(COutputStream& out)
{
    Unk_GuildMapLock guard(lock,1);
    out.vfunc_o10_1(FUN_1404f4490(&f2c8));
    void* pos=FUN_1404f4d40(&f2c8);
    while(pos!=0) {
        Unk_GuildRef ref; FUN_1404ec690(&ref,FUN_1404f4f00(&f2c8,pos));
        FUN_1404f0b90(&ref)->FUN_1404cc3f0(out);
        FUN_1404eeb00(&ref);
        FUN_1404f46b0(&f2c8,&pos);
    }
}

// @0x1404cf490
void CGuildInfo::FUN_1404cf490(CInPacket& packet)
{
    Unk_GuildMapLock guard(lock,1);
    FUN_1404f8a30(&f2c8);
    CInputStream& in=packet;
    unsigned char count=in.vfunc_o8_1();
    for(int i=0;i<(int)count;++i) {
        CGuildNpc* npc=new CGuildNpc;
        Unk_GuildRef ref; FUN_1404ec6f0(&ref,npc);
        FUN_1404f0b90(&ref)->FUN_1404cc440(packet);
        FUN_1404f9990(&f2c8,&FUN_1404f0b90(&ref)->f18,&ref);
        FUN_1404eeb00(&ref);
    }
}

// @0x1404cf5f0
void CGuildInfo::FUN_1404cf5f0(COutputStream& out)
{
    Unk_GuildMapLock guard(lock,1);
    __int64 has=FUN_1404f0ad0(&f360);
    out.vfunc_o10_0(has!=0);
    if(FUN_1404f0ad0(&f360)!=0) FUN_1404d8d50(FUN_1404f0bb0(&f360),&out);
}

// @0x1404cf6c0
void CGuildInfo::FUN_1404cf6c0(CInPacket& packet)
{
    Unk_GuildMapLock guard(lock,1);
    CInputStream& in=packet;
    if(in.vfunc_o8_0()) {
        if(FUN_1404f00e0(&f360,0)!=0) {
            void* mem=operator new(0x28); void* mgr=mem ? FUN_1404ee230(mem) : 0;
            FUN_1404efb30(&f360,mgr);
        }
        FUN_1404d8e80(FUN_1404f0bb0(&f360),&packet);
    }
}

// MS2-FUNCTIONAL: the guild smart-pointer/record temporaries are raw Unk_Guild* structs driven by explicit FUN_ ctor/dtor calls; the exe objects have real dtors (EH states + dtor ordering) (18 vs exe 19 callees)
// @0x1404cf7d0
int CGuildInfo::vfunc_0(Unk_GuildRef* member)
{
    if(FUN_1404f0020(member,0)==0) {
        if(Unk_LockGuard guard=lock) {
            FUN_1404eead0(member);
            return 0;
        }
        if((int)FUN_1404f44b0(&f320)<f50) {
            CStringW name=FUN_1404f0b80(member)->data.FUN_1404ca890();
            FUN_1404f9ae0(&f320,name,member);
            if(FUN_1404f0020(&f310,0)!=0) {
                if(FUN_1404f0b80(member)->data.f08==f78) FUN_1404ef970(&f310,member);
            }
            FUN_1404eead0(member);
            return 1;
        }
        FUN_1404eead0(member);
        return 0;
    }
    FUN_1404eead0(member);
    return 0;
}

// @0x1404cf970
void CGuildInfo::vfunc_1(CStringW name)
{
    if(Unk_LockGuard guard=lock) {} else {
        FUN_1404f91b0(&f320,name);
    }
}

// @0x1404cf9f0
MS2Ptr<CGuildMember> CGuildInfo::FUN_1404cf9f0(CStringW name)
{
    if(name.IsEmpty())
        return MS2Ptr<CGuildMember>(0);
    MS2Ptr<CGuildMember> found(0);
    if(Unk_LockGuard guard=lock) {} else {
        FUN_1404f6070(&f320,name,found);
    }
    return found;
}

// @0x1404cfb00
MS2Ptr<CGuildMember> CGuildInfo::FUN_1404cfb00(__int64 id)
{
    MS2Ptr<CGuildMember> found(0);
    if(Unk_LockGuard guard=lock) {} else {
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
    Unk_GuildRef ref; FUN_1404ec5f0(&ref,0);
    if(Unk_LockGuard guard=lock) {} else {
        if(FUN_1404f6070(&f320,oldName,&ref)==1) {
            FUN_1404f91b0(&f320,oldName);
            FUN_1404f0b80(&ref)->data.FUN_1404ca910(newName);
            FUN_1404f9ae0(&f320,newName,&ref);
        }
    }
    FUN_1404eead0(&ref);
}

// @0x1404cfdb0
void CGuildInfo::FUN_1404cfdb0(const CStringW& name,int value)
{
    Unk_GuildRef ref; FUN_1404ec5f0(&ref,0);
    if(Unk_LockGuard guard=lock) {} else {
        if(FUN_1404f6070(&f320,name,&ref)==1) FUN_1404f0b80(&ref)->data.f20=value;
    }
    FUN_1404eead0(&ref);
}

// @0x1404cfe60
void CGuildInfo::FUN_1404cfe60(const CStringW& name,__int64 value)
{
    Unk_GuildRef ref; FUN_1404ec5f0(&ref,0);
    if(Unk_LockGuard guard=lock) {} else {
        if(FUN_1404f6070(&f320,name,&ref)==1) FUN_1404f0b80(&ref)->fd8=value;
    }
    FUN_1404eead0(&ref);
}

// @0x1404cff20
unsigned __int64 CGuildInfo::FUN_1404cff20()
{
    if(Unk_LockGuard guard=lock) {} else {
        unsigned __int64 count=0;
        void* pos=FUN_1404f4510(&f320);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec5b0(&ref,FUN_1404f4f70(&f320,pos));
            if(FUN_1404f0b80(&ref)->fb0==3) count=count+1;
            FUN_1404eead0(&ref);
            FUN_1404f4700(&f320,&pos);
        }
        return count;
    }
    return 0;
}

// @0x1404d0020
int CGuildInfo::FUN_1404d0020()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned count=FUN_1404f44b0(&f320); return count; } }
}

// @0x1404d00a0
Unk_GuildRef* CGuildInfo::FUN_1404d00a0(Unk_GuildRef* ret)
{
    { if(Unk_LockGuard guard=lock) {} else { FUN_1404ec5b0(ret,&f310); return ret; } }
}

// @0x1404d0130
void CGuildInfo::FUN_1404d0130(Unk_GuildRef* v)
{
    if(Unk_LockGuard guard=lock) {} else { FUN_1404ef970(&f310,v); }
    FUN_1404eead0(v);
}

// @0x1404d01b0
int CGuildInfo::FUN_1404d01b0(CStringW name)
{
    if(Unk_LockGuard guard=lock) {} else {
        MS2Ptr<CGuildMember> member=FUN_1404cf9f0(name);
        if(member==0) return FALSE;
        if(member->data.f08==f78) return TRUE;
        else return FALSE;
    }
}

// @0x1404d0330
void CGuildInfo::FUN_1404d0330(void* out)
{
    if(Unk_LockGuard guard=lock) {} else {
        void* pos=FUN_1404f4510(&f320);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec5b0(&ref,FUN_1404f4f70(&f320,pos));
            if(FUN_1404f0b80(&ref)->fb0==3) FUN_140212bf0(out,FUN_1404f0b80(&ref)->data.f08);
            FUN_1404eead0(&ref);
            FUN_1404f4700(&f320,&pos);
        }
    }
}

// @0x1404d0420
void CGuildInfo::FUN_1404d0420(void* out)
{
    if(Unk_LockGuard guard=lock) {} else {
        void* pos=FUN_1404f4510(&f320);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec5b0(&ref,FUN_1404f4f70(&f320,pos));
            if(FUN_1404f0b80(&ref)->fb0==3) FUN_1404f31c0(out,&ref);
            FUN_1404eead0(&ref);
            FUN_1404f4700(&f320,&pos);
        }
    }
}

// @0x1404d0510
int CGuildInfo::FUN_1404d0510()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=fc0; return v; } }
}

// @0x1404d0580
int CGuildInfo::FUN_1404d0580()
{
    { if(Unk_LockGuard guard=lock) {} else { int n=(int)FUN_1404f4440(&fa0); return n-1; } }
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
    if(Unk_LockGuard guard=lock) {} else {
        MS2Ptr<CGuildMember> member=FUN_1404cf9f0(name);
        if(!(member==0)) {
            Unk_GuildRef grade; FUN_1404d0860(&grade,member->fb4);
            if(FUN_1404f0aa0(&grade)==0) { FUN_1404eeaa0(&grade); return 0; }
            unsigned v=FUN_1404f0b70(&grade)->permissions;
            FUN_1404eeaa0(&grade); return v;
        }
        return 0;
    }
    return 0;
}

// MS2-FUNCTIONAL: the guild smart-pointer/record temporaries are raw Unk_Guild* structs driven by explicit FUN_ ctor/dtor calls; the exe objects have real dtors (EH states + dtor ordering) (10 vs exe 12 callees)
// @0x1404d0860
Unk_GuildRef* CGuildInfo::FUN_1404d0860(Unk_GuildRef* ret,int index)
{
    if(Unk_LockGuard guard=lock) {} else {
        if(FUN_1404f4440(&fa0)==0) {
            FUN_1404ec510(ret,0);
        } else {
            if(-1<index && index<=FUN_1404d0580()) {
                FUN_1404ec4d0(ret,FUN_1404f0720(&fa0,index));
                return ret;
            }
            FUN_1404ec510(ret,0);
        }
    }
    return ret;
}

// @0x1404d0990
int CGuildInfo::FUN_1404d0990(int index,Unk_GuildRef* grade)
{
    if(Unk_LockGuard guard=lock) {
        FUN_1404eeaa0(grade);
        return 0;
    }
    Unk_GuildRef cur;
    char isNull=FUN_1404effe0(FUN_1404d0860(&cur,index),0);
    FUN_1404eeaa0(&cur);
    if(isNull==0) {
        FUN_1404f9730(&fa0,index,grade);
    } else {
        if(index!=FUN_1404d0580()+1) { FUN_1404eeaa0(grade); return 0; }
        FUN_1404f3110(&fa0,grade);
    }
    fc0=0;
    FUN_1404eeaa0(grade);
    return 1;
}

// MS2-FUNCTIONAL: the guild smart-pointer/record temporaries are raw Unk_Guild* structs driven by explicit FUN_ ctor/dtor calls; the exe objects have real dtors (EH states + dtor ordering) (16 vs exe 12 callees)
// @0x1404d0af0
CStringW CGuildInfo::FUN_1404d0af0(int index)
{
    { if(Unk_LockGuard guard=lock) {} else {
        Unk_GuildRef grade; FUN_1404d0860(&grade,index);
        if(FUN_1404f0aa0(&grade)==0) { CStringW empty(L""); FUN_1404eeaa0(&grade); return empty; }
        CStringW text(FUN_1404f0b70(&grade)->name);
        FUN_1404eeaa0(&grade);
        return text;
    } }
}

// @0x1404d0c00
int CGuildInfo::FUN_1404d0c00()
{
    int total=0;
    if(Unk_LockGuard guard=lock) {} else {
        void* pos=FUN_1404f4510(&f320);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec5b0(&ref,FUN_1404f4f70(&f320,pos));
            int v=FUN_1404f0b80(&ref)->FUN_1404cb3b0();
            total=total+v;
            FUN_1404eead0(&ref);
            FUN_1404f4700(&f320,&pos);
        }
    }
    return total+f358;
}

// @0x1404d0d00
int CGuildInfo::FUN_1404d0d00()
{
    int total=0;
    if(Unk_LockGuard guard=lock) {} else {
        void* pos=FUN_1404f4510(&f320);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec5b0(&ref,FUN_1404f4f70(&f320,pos));
            total=total+(unsigned)(unsigned short)FUN_1404f0b80(&ref)->data.f1c;
            FUN_1404eead0(&ref);
            FUN_1404f4700(&f320,&pos);
        }
    }
    return total;
}

// @0x1404d0df0
int CGuildInfo::FUN_1404d0df0()
{
    int total=0;
    if(Unk_LockGuard guard=lock) {} else {
        void* pos=FUN_1404f4510(&f320);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec5b0(&ref,FUN_1404f4f70(&f320,pos));
            total=total+FUN_1404f0b80(&ref)->data.f20;
            FUN_1404eead0(&ref);
            FUN_1404f4700(&f320,&pos);
        }
    }
    return total;
}

// @0x1404d0ee0
int CGuildInfo::FUN_1404d0ee0()
{
    int total=0;
    if(Unk_LockGuard guard=lock) {} else {
        void* pos=FUN_1404f4510(&f320);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec5b0(&ref,FUN_1404f4f70(&f320,pos));
            if(FUN_1404f0020(&ref,0)==0) {
                int v=FUN_1404f0b80(&ref)->raid.FUN_1404cadc0();
                total=total+v;
                FUN_1404eead0(&ref);
            } else {
                FUN_1404eead0(&ref);
            }
            FUN_1404f4700(&f320,&pos);
        }
    }
    return total;
}

// @0x1404d0ff0
unsigned CGuildInfo::FUN_1404d0ff0()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=f134; return v; } }
}

// @0x1404d1060
void CGuildInfo::FUN_1404d1060(int v)
{
    if(Unk_LockGuard guard=lock) {} else { f134=v; }
}

// @0x1404d10d0
unsigned CGuildInfo::FUN_1404d10d0()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=f130; return v; } }
}

// @0x1404d1140
void CGuildInfo::FUN_1404d1140(int v)
{
    if(Unk_LockGuard guard=lock) {} else { f130=v; }
}

// @0x1404d11b0
void CGuildInfo::FUN_1404d11b0(int a,int b,int c,int d,int e,int f,int g)
{
    if(Unk_LockGuard guard=lock) {} else { f134=a; f138=b; f13c=c; f140=d; f144=e; f148=f; f14c=g; }
}

// @0x1404d1280
unsigned CGuildInfo::FUN_1404d1280()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=f138; return v; } }
}

// @0x1404d12f0
void CGuildInfo::FUN_1404d12f0(int v)
{
    if(Unk_LockGuard guard=lock) {} else { f138=v; }
}

// @0x1404d1360
unsigned CGuildInfo::FUN_1404d1360()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=f13c; return v; } }
}

// @0x1404d13d0
void CGuildInfo::FUN_1404d13d0(int v)
{
    if(Unk_LockGuard guard=lock) {} else { f13c=v; }
}

// @0x1404d1440
unsigned CGuildInfo::FUN_1404d1440()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=f140; return v; } }
}

// @0x1404d14b0
unsigned CGuildInfo::FUN_1404d14b0()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=f144; return v; } }
}

// @0x1404d1520
void CGuildInfo::FUN_1404d1520(int v)
{
    if(Unk_LockGuard guard=lock) {} else { f144=v; }
}

// @0x1404d1590
unsigned CGuildInfo::FUN_1404d1590()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=f148; return v; } }
}

// @0x1404d1600
void CGuildInfo::FUN_1404d1600(int v)
{
    if(Unk_LockGuard guard=lock) {} else { f148=v; }
}

// @0x1404d1670
unsigned CGuildInfo::FUN_1404d1670()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=f14c; return v; } }
}

// @0x1404d16e0
int CGuildInfo::FUN_1404d16e0()
{
    int total=0;
    if(Unk_LockGuard guard=lock) {} else {
        void* pos=FUN_1404f4510(&f320);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec5b0(&ref,FUN_1404f4f70(&f320,pos));
            if(FUN_1404f0b80(&ref)->fb0==3 && FUN_1404f0b80(&ref)->f158==0) total=total+1;
            FUN_1404eead0(&ref);
            FUN_1404f4700(&f320,&pos);
        }
    }
    return total;
}

// @0x1404d17e0
void CGuildInfo::FUN_1404d17e0(int a,int b)
{
    if(Unk_LockGuard guard=lock) {} else { f154=a; f158=b; }
}

// @0x1404d1860
unsigned CGuildInfo::FUN_1404d1860()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=f154; return v; } }
}

// @0x1404d18d0
unsigned CGuildInfo::FUN_1404d18d0()
{
    { if(Unk_LockGuard guard=lock) {} else { unsigned v=f158; return v; } }
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
    int limit=FUN_1404d7280(FUN_1404f4530());
    f15c=f15c+delta;
    if(f15c<0) f15c=0;
    if(limit<f15c) f15c=limit;
    bool changed=before!=f15c;
    return changed;
}

// @0x1404d1a80
int CGuildInfo::FUN_1404d1a80()
{
    Unk_GuildMapLock guard(lock,1);
    int v=f15c;
    return v;
}

// @0x1404d1ad0
int CGuildInfo::FUN_1404d1ad0()
{
    Unk_GuildMapLock guard(lock,1);
    int v=FUN_1404d7130(FUN_1404f4530(),f15c);
    return v;
}

// @0x1404d1b40
void CGuildInfo::FUN_1404d1b40(int v)
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
    if(limit<f160) f160=limit;
    bool changed=before!=f160;
    return changed;
}

// @0x1404d1c90
void CGuildInfo::FUN_1404d1c90(int v)
{
    Unk_GuildMapLock guard(lock,1);
    if(f164==v) {
    } else {
        f164=v;
    }
}

// @0x1404d1d00
bool CGuildInfo::FUN_1404d1d00(int delta)
{
    Unk_GuildMapLock guard(lock,1);
    int before=f164;
    f164=f164+delta;
    int limit=FUN_1404d1f20();
    if(f164<0) f164=0;
    if(limit<f164) f164=limit;
    bool changed=before!=f164;
    return changed;
}

// @0x1404d1df0
int CGuildInfo::FUN_1404d1df0()
{
    Unk_GuildMapLock guard(lock,1);
    int v=f160;
    return v;
}

// @0x1404d1e40
int CGuildInfo::FUN_1404d1e40()
{
    Unk_GuildMapLock guard(lock,1);
    int v=f164;
    return v;
}

// MS2-FUNCTIONAL: the guild smart-pointer/record temporaries are raw Unk_Guild* structs driven by explicit FUN_ ctor/dtor calls; the exe objects have real dtors (EH states + dtor ordering) - frame differs
// @0x1404d1e90
int CGuildInfo::FUN_1404d1e90()
{
    int level=FUN_1404d1ad0();
    Unk_GuildRef ref; FUN_1404d7410(FUN_1404f4530(),&ref,level);
    if(FUN_1404eff60(&ref,0)==0) {
        int v=*(int*)(FUN_1404f0b30(&ref)+0x28);
        FUN_1404ee9b0(&ref);
        return v;
    }
    FUN_1404ee9b0(&ref);
    return 0;
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
    int v=f168;
    return v;
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
    int v=f16c;
    return v;
}

// @0x1404d2080
int CGuildInfo::FUN_1404d2080()
{
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildRef ref; FUN_1404d79b0(FUN_1404f4530(),&ref,f168,f16c);
    if(FUN_1404eff20(&ref,0)==0) {
        int v=*(int*)(FUN_1404f0b10(&ref)+0x50);
        FUN_1404ee950(&ref);
        return v;
    }
    FUN_1404ee950(&ref);
    return 0;
}

// MS2-FUNCTIONAL: the {name,value,text} record (Unk_GuildStrRec) is a raw struct with explicit ctor 0x1404ee6b0/dtor 0x1404ef6e0 calls; the exe record object has EH states - frame differs
// @0x1404d2150
void CGuildInfo::vfunc_2(__int64 value,CStringW name,int key,const CStringW& text)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildStrRec rec; FUN_1404ee6b0(&rec);
    rec.name()=text;
    rec.q1=value;
    rec.text()=name;
    FUN_1404efdf0(FUN_1404f07a0(&f170,key),&rec);
    FUN_1404ef6e0(&rec);
}

// MS2-FUNCTIONAL: Unk_GuildStrRec temporaries are raw structs with explicit ctor 0x1404ee6b0/dtor 0x1404ef6e0 calls; the exe has real record objects - frame differs
// @0x1404d2220
CStringW CGuildInfo::FUN_1404d2220(int key)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildStrRec rec; FUN_1404ee6b0(&rec);
    if(FUN_1404f5e80(&f170,key,&rec)==1) {
        CStringW r(rec.name());
        FUN_1404ef6e0(&rec);
        return r;
    }
    CStringW r(L"");
    FUN_1404ef6e0(&rec);
    return r;
}

// MS2-FUNCTIONAL: Unk_GuildStrRec temporaries are raw structs with explicit ctor 0x1404ee6b0/dtor 0x1404ef6e0 calls; the exe has real record objects - frame differs
// @0x1404d2330
__int64 CGuildInfo::FUN_1404d2330(int key)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildStrRec rec; FUN_1404ee6b0(&rec);
    if(FUN_1404f5e80(&f170,key,&rec)==1) {
        __int64 v=rec.q1;
        FUN_1404ef6e0(&rec);
        return v;
    }
    __int64 v=0;
    FUN_1404ef6e0(&rec);
    return v;
}

// MS2-FUNCTIONAL: Unk_GuildStrRec temporaries are raw structs with explicit ctor 0x1404ee6b0/dtor 0x1404ef6e0 calls; the exe has real record objects - frame differs
// @0x1404d2400
CStringW CGuildInfo::FUN_1404d2400(int key)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildStrRec rec; FUN_1404ee6b0(&rec);
    if(FUN_1404f5e80(&f170,key,&rec)==1) {
        CStringW r(rec.text());
        FUN_1404ef6e0(&rec);
        return r;
    }
    CStringW r(L"");
    FUN_1404ef6e0(&rec);
    return r;
}

// MS2-FUNCTIONAL: the guild smart-pointer/record temporaries are raw Unk_Guild* structs driven by explicit FUN_ ctor/dtor calls; the exe objects have real dtors (EH states + dtor ordering) - frame differs
// @0x1404d2510
int CGuildInfo::FUN_1404d2510(int a,int b)
{
    Unk_GuildRef ref; FUN_1404d74e0(FUN_1404f4530(),&ref,a,b);
    if(FUN_1404effa0(&ref,0)==0) {
        int v=*(int*)(FUN_1404f0b50(&ref)+0x28);
        FUN_1404eea40(&ref);
        return v;
    }
    FUN_1404eea40(&ref);
    return 0x7fffffff;
}

// @0x1404d25a0
void CGuildInfo::FUN_1404d25a0(Unk_GuildRef* skill)
{
    if(FUN_1404f0120(skill,0)==0) {
        Unk_GuildMapLock guard(lock,1);
        FUN_1404f98e0(&f238,FUN_1404f0bc0(skill)->f18,skill);
    }
    FUN_1404eeb90(skill);
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
    Unk_GuildRef tmp; FUN_1404ec920(&tmp,0);
    if(FUN_1404f5f60(&f238,key,&tmp)==0) {
        FUN_1404eeb90(&tmp);
        return 0;
    }
    int v=FUN_1404f0bc0(&tmp)->f1c;
    FUN_1404eeb90(&tmp);
    return v;
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
void CGuildInfo::FUN_1404d2860(Unk_GuildRef* npc)
{
    Unk_GuildMapLock guard(lock,1);
    CGuildNpc* p=FUN_1404f0b90(npc);
    FUN_1404f9990(&f2c8,&p->f18,npc);
    FUN_1404eeb00(npc);
}

// @0x1404d28e0
Unk_GuildRef* CGuildInfo::FUN_1404d28e0(Unk_GuildRef* ret,int key)
{
    int k=key;
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildRef tmp; FUN_1404ec6d0(&tmp,0);
    FUN_1404f5fd0(&f2c8,&k,&tmp);
    FUN_1404ec660(ret,&tmp);
    FUN_1404eeb00(&tmp);
    return ret;
}

// MS2-FUNCTIONAL: Unk_GuildRef returned by FUN_1404d28e0 is a raw struct destroyed by an explicit FUN_1404eeb00 call; the exe temp is a real smart pointer with an EH state - frame differs
// @0x1404d2990
int CGuildInfo::FUN_1404d2990(int key)
{
    Unk_GuildRef tmp; FUN_1404d28e0(&tmp,key);
    if(FUN_1404f0060(&tmp,0)==0) {
        int v=FUN_1404f0b90(&tmp)->f1c;
        FUN_1404eeb00(&tmp);
        return v;
    }
    FUN_1404eeb00(&tmp);
    return 0;
}

// @0x1404d2a10
void CGuildInfo::FUN_1404d2a10(CInPacket* packet)
{
    if(Unk_LockGuard guard=lock) {} else {
        if(FUN_1404f00e0(&f360,0)!=0) {
            void* mem=operator new(0x28); void* mgr=mem ? FUN_1404ee230(mem) : 0;
            FUN_1404efb30(&f360,mgr);
        }
        FUN_1404d8e80(FUN_1404f0bb0(&f360),packet);
    }
}

// @0x1404d2b00
void CGuildInfo::FUN_1404d2b00(int a,void* b)
{
    if(Unk_LockGuard guard=lock) {} else if(FUN_1404f0ad0(&f360)!=0) {
        FUN_1404d8ff0(FUN_1404f0bb0(&f360),a,b);
    }
}

// @0x1404d2ba0
void CGuildInfo::FUN_1404d2ba0(int a,void* b)
{
    if(Unk_LockGuard guard=lock) {} else if(FUN_1404f0ad0(&f360)!=0) {
        FUN_1404d9060(FUN_1404f0bb0(&f360),a,b);
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
    ItemAble* able=item;
    int rank=able->vfunc_o18_1();
    int id=able->vfunc_o18_0();
    Unk_GuildPair key; FUN_140407ed0(&key,&id,&rank);
    void* map=(char*)&storage+0x18;
    FUN_1404efe60(FUN_1404f0990(map,&key),item);
    if(item->m_count==0) FUN_1405085e0(map,&key);
}

// MS2-FUNCTIONAL: the guild smart-pointer/record temporaries are raw Unk_Guild* structs driven by explicit FUN_ ctor/dtor calls; the exe objects have real dtors (EH states + dtor ordering) - frame differs
// @0x1404d2db0
int CGuildInfo::FUN_1404d2db0(int a,int b)
{
    Unk_GuildMapLock guard(lock,1);
    Unk_GuildPair key; FUN_1404d9660(&key,&a,&b);
    void* it; void* endBuf[3]; void* map=(char*)&storage+0x18;
    FUN_140508ed0(map,&it,&key);
    if(FUN_1404f03a0(&it,FUN_1405076d0(map,endBuf))==0) {
        int v=*(int*)((char*)FUN_1404f0ce0(&it)+0x2c);
        return v;
    }
    return 0;
}

// @0x1404d2e90
void CGuildInfo::FUN_1404d2e90(const Unk_GuildHist* a,const Unk_GuildHist* b,const ItemEntity* item,__int64 c)
{
    Unk_GuildMapLock guard(lock,1);
    CGuildStorage::CGuildStroageHistory* h=new CGuildStorage::CGuildStroageHistory;
    Unk_GuildRef ref; FUN_1404ec9d0(&ref,h);
    FUN_1404efd90(&FUN_1404f0bd0(&ref)->f18,a);
    FUN_1404efd90(&FUN_1404f0bd0(&ref)->f30,b);
    FUN_1404efe60(&FUN_1404f0bd0(&ref)->item,item);
    FUN_1404f0bd0(&ref)->f78=c;
    void* deque=(char*)&storage+0x38;
    FUN_1405099e0(deque,&ref);
    FUN_1404f3270(&storage.f60,&ref);
    int n=FUN_14050a040(deque);
    if(0x32<n) {
        for(int i=0;i<n-0x32;++i) FUN_1405098f0(deque);
    }
    FUN_1404eebc0(&ref);
}

// @0x1404d3050
void CGuildInfo::FUN_1404d3050(void* list)
{
    Unk_GuildMapLock guard(lock,1);
    void* deque=(char*)&storage+0x38;
    FUN_140506ca0(deque);
    int n=FUN_1404f4450(list);
    for(int i=0;i<n;++i) {
        Unk_GuildRef* h=FUN_1404f0760(list,i);
        if(FUN_1404f0ae0(h)==0) MS2_ASSERT_AT(0x988,FALSE);
        FUN_140509c90(deque,h);
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

// Guild season table row as returned by FUN_1404f0bf0 (fields copied into CGuildInfo::season).
struct Unk_GuildSeasonRow {
    char m_0[0x1c];
    int id;
    CStringW name;
    char m_28[8];
    CMsTime begin;
    CMsTime end;
    int points[7];
};
MS2_CHECK_OFFSET(Unk_GuildSeasonRow, id, 0x1c);
MS2_CHECK_OFFSET(Unk_GuildSeasonRow, name, 0x20);
MS2_CHECK_OFFSET(Unk_GuildSeasonRow, begin, 0x30);
MS2_CHECK_OFFSET(Unk_GuildSeasonRow, end, 0x40);
MS2_CHECK_OFFSET(Unk_GuildSeasonRow, points, 0x50);

// @0x1404d31b0
void CGuildInfo::FUN_1404d31b0()
{
    Unk_GuildRef ref; FUN_140791e40(FUN_1404f4540(),&ref,2);
    if(FUN_1404f01a0(&ref,0)==0) {
        Unk_GuildSeasonRow* s=(Unk_GuildSeasonRow*)FUN_1404f0bf0(&ref);
        if(season.id!=s->id) {
            season.id=s->id;
            season.name=s->name;
            season.begin=s->begin;
            season.end=s->end;
            season.points[1]=s->points[0]; season.points[2]=s->points[1]; season.points[3]=s->points[2];
            season.points[4]=s->points[3]; season.points[5]=s->points[4]; season.points[6]=s->points[5];
            season.points[7]=s->points[6];
        }
        FUN_1404eec20(&ref);
    } else {
        season.FUN_1404c5d20();
        FUN_1404eec20(&ref);
    }
}

// @0x1404d3400
int CGuildInfo::FUN_1404d3400(void* out)
{
    FUN_1404f8b40(out);
    if(Unk_LockGuard guard=lock) {} else {
        void* pos=FUN_1404f4510(&f320);
        while(pos!=0) {
            Unk_GuildRef ref; FUN_1404ec5b0(&ref,FUN_1404f4f70(&f320,pos));
            if(FUN_1404f0020(&ref,0)==0) {
                if(FUN_1404f0b80(&ref)->f158==0) {
                    if(FUN_1404f0b80(&ref)->fb0==3) {
                        Unk_GuildRef q; FUN_140374140(&q,FUN_1404f0b80(&ref)->data.f24);
                        if(FUN_1402ffdc0(&q,0)==0) {
                            if(FUN_140375310(FUN_140300710(&q))==1) {
                                FUN_1402fec60(&q);
                                FUN_1404eead0(&ref);
                            } else {
                                CGuildMember* first=FUN_1404f0b80(&ref);
                                FUN_1404f9a40(out,FUN_1404f0b80(&ref)->data.f08,first->data.f08);
                                FUN_1402fec60(&q);
                                FUN_1404eead0(&ref);
                            }
                        } else {
                            FUN_1402fec60(&q);
                            FUN_1404eead0(&ref);
                        }
                    } else {
                        FUN_1404eead0(&ref);
                    }
                } else {
                    FUN_1404eead0(&ref);
                }
            } else {
                FUN_1404eead0(&ref);
            }
            FUN_1404f4700(&f320,&pos);
        }
    }
    return (int)FUN_1404f44a0(out);
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
Unk_GuildRef* CGuildInfo::FUN_1404d3640(Unk_GuildRef* ret)
{
    { if(Unk_LockGuard guard=lock) {} else { FUN_1404ec820(ret,&f360); return ret; } }
}

// @0x1404d36d0
void CGuildInfo::FUN_1404d36d0()
{
    if(Unk_LockGuard guard=lock) {} else {
        FUN_1404f86e0(&fa0);
        fc0=1;
        for(int i=0;i<6;++i) {
            CGuildGrade* gradeObj=new CGuildGrade;
            Unk_GuildRef ref; FUN_1404ec530(&ref,gradeObj);
            if(i==0) {
                FUN_1404f0b70(&ref)->grade=0;
                GSTR(0x399,FUN_1404f0b70(&ref)->name);
                FUN_1404f0b70(&ref)->permissions=0xfff;
            } else {
                FUN_1404f0b70(&ref)->grade=i;
                FUN_1404f0b70(&ref)->name=L"";
                FUN_1404f0b70(&ref)->permissions=1;
                if(FUN_1404f0b70(&ref)->grade==1) { GSTR(0x39a,FUN_1404f0b70(&ref)->name); }
                else if(FUN_1404f0b70(&ref)->grade==2) { GSTR(0x39b,FUN_1404f0b70(&ref)->name); }
                else if(FUN_1404f0b70(&ref)->grade==3) { GSTR(0x39c,FUN_1404f0b70(&ref)->name); }
                else if(FUN_1404f0b70(&ref)->grade==4) { GSTR(0x39d,FUN_1404f0b70(&ref)->name); }
                else if(FUN_1404f0b70(&ref)->grade==5) { GSTR(0x39e,FUN_1404f0b70(&ref)->name); }
            }
            FUN_1404f3110(&fa0,&ref);
            FUN_1404eeaa0(&ref);
        }
    }
}

// ---- local int-vector helpers (neighbouring chunks) ----
struct Unk_GuildIntVec { __int64 q[3]; };
void FUN_140182ea0(Unk_GuildIntVec*); unsigned __int64 FUN_1401910d0(Unk_GuildIntVec*); int* FUN_1404f0a10(Unk_GuildIntVec*,unsigned __int64);
void FUN_140183b60(Unk_GuildIntVec*);
void FUN_1404d7630(void* xml,Unk_GuildIntVec*); void FUN_1404d7730(void* xml,Unk_GuildIntVec*); void FUN_1404d7900(void* xml,Unk_GuildIntVec*);

// @0x1404d3b80
void CGuildInfo::FUN_1404d3b80()
{
    Unk_GuildMapLock guard(lock,1);
    FUN_1404f8920(&f238);
    Unk_GuildIntVec v1; FUN_140182ea0(&v1);
    FUN_1404d7630(FUN_1404f4530(),&v1);
    for(unsigned __int64 i=0;i<FUN_1401910d0(&v1);++i) {
        CGuildSkill* skill=new CGuildSkill;
        Unk_GuildRef ref; FUN_1404ec940(&ref,skill);
        int* id=FUN_1404f0a10(&v1,i);
        FUN_1404f0bc0(&ref)->f18=*id;
        FUN_1404f0bc0(&ref)->f1c=1;
        Unk_GuildRef copy; FUN_1404ec8e0(&copy,&ref);
        FUN_1404d25a0(&copy);
        FUN_1404eeb90(&ref);
    }
    FUN_140183b60(&v1);
    Unk_GuildIntVec v2; FUN_140182ea0(&v2);
    FUN_1404d7730(FUN_1404f4530(),&v2);
    for(unsigned __int64 i=0;i<FUN_1401910d0(&v2);++i) {
        CGuildSkill* skill=new CGuildSkill;
        Unk_GuildRef ref; FUN_1404ec940(&ref,skill);
        int* id=FUN_1404f0a10(&v2,i);
        FUN_1404f0bc0(&ref)->f18=*id;
        FUN_1404f0bc0(&ref)->f1c=1;
        Unk_GuildRef copy; FUN_1404ec8e0(&copy,&ref);
        FUN_1404d25a0(&copy);
        FUN_1404eeb90(&ref);
    }
    FUN_140183b60(&v2);
}

// @0x1404d3e70
void CGuildInfo::FUN_1404d3e70()
{
    Unk_GuildMapLock guard(lock,1);
    FUN_1404f8810(&f280);
    Unk_GuildIntVec v; FUN_140182ea0(&v);
    FUN_1404d7900(FUN_1404f4530(),&v);
    for(unsigned __int64 i=0;i<FUN_1401910d0(&v);++i) {
        CGuildCustomEvent* ev=new CGuildCustomEvent;
        Unk_GuildRef ref; FUN_1404ec480(&ref,ev);
        int* id=FUN_1404f0a10(&v,i);
        FUN_1404f0b60(&ref)->f18=*id;
        FUN_1404f9830(&f280,FUN_1404f0b60(&ref)->f18,&ref);
        FUN_1404eea70(&ref);
    }
    FUN_140183b60(&v);
}

// @0x1404d3fe0
void FUN_1404d3fe0(Unk_GuildStrRec* rec,COutputStream* out)
{
    out->vfunc_o10_8(rec->name());
    out->vfunc_o10_4(rec->q1);
    out->vfunc_o10_8(rec->text());
}

// @0x1404d4060
void FUN_1404d4060(Unk_GuildStrRec* rec,CInPacket* packet)
{
    CInputStream& in=*packet;
    rec->name()=in.vfunc_o8_8();
    rec->q1=in.vfunc_o8_4();
    rec->text()=in.vfunc_o8_8();
}
