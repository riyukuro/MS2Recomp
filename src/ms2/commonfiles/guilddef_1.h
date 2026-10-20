// Guild wire payloads, part 1. RTTI class names are original; field/helper names inferred.
#pragma once
#include <afx.h>
#include <map>
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/cinpacket.h"
#include "ms2/placeholder/coutpacket.h"
#include <atlcoll.h>
#include "ms2/commonfiles/itemgift.h"
#include "ms2/unnamed/payloadptr_1401f9eb0.h"
struct Unk_GuildTriple {
    Unk_GuildTriple(); void FUN_140267bd0(); int FUN_140267c10(); void FUN_140267ea0(const Unk_GuildTriple&);
    void FUN_140267f50(COutputStream&); void FUN_140267fb0(CInputStream&);
    int x,y,z;
};
MS2_CHECK_SIZE(Unk_GuildTriple,12);
struct Unk_GuildArray {
    Unk_GuildArray(); ~Unk_GuildArray(); void FUN_1401c0580();
    void* p0; size_t p8,p10; int p18;
};
MS2_CHECK_SIZE(Unk_GuildArray,32);

class CGuildInfo;
template <class T> class MS2Ptr;
struct Unk_GuildMapLock { Unk_GuildMapLock(CLockCriticalSection&,int); ~Unk_GuildMapLock(); void* p; };
MS2_CHECK_SIZE(Unk_GuildMapLock,8);
struct Unk_GuildNameLock { Unk_GuildNameLock(CLockCriticalSection&,int); ~Unk_GuildNameLock(); void* p; };
MS2_CHECK_SIZE(Unk_GuildNameLock,8);
// External character record: only pointer passing; named helpers retain the original member ABI.
class Unk_GuildCharacter {
public: CStringW FUN_1408f19e0(); CString FUN_1408f1a60();
};
class Unk_GuildSeason {
public:
    Unk_GuildSeason();
    ~Unk_GuildSeason();
    void FUN_1404c5d20();
    void FUN_1404c5da0(COutputStream& out);
    void FUN_1404c5ea0(CInPacket& packet);
    void FUN_1404c6030(const Unk_GuildSeason& other);
    int FUN_1404c60e0(int rank);
    int FUN_1404c6110(int score);
    int FUN_1404c6160();
    int id; CStringW name; CMsTime begin,end; int points[8];
};
MS2_CHECK_SIZE(Unk_GuildSeason,0x50);
class Unk_GuildProfile {
public:
    Unk_GuildProfile();
    ~Unk_GuildProfile();
    void FUN_1404c6350();
    __int64 p00; CStringW name; CString code; int f18; CStringW f20,f28; CString f30;
    __int64 f38,f40; CStringW f48; __int64 f50,f58; int f60; __int64 f68,f70; CStringW f78;
    int f80,f84,f88,f8c,f90,f94,f98,f9c,fa0,fa4,fa8,fac,fb0,fb4,fb8,fbc; __int64 fc0,fc8; Unk_GuildArray array;
};
MS2_CHECK_SIZE(Unk_GuildProfile,0xf0);
class CGuildPVPHistoryData : public CPtred {
public:
    CGuildPVPHistoryData();
    virtual ~CGuildPVPHistoryData();
    void FUN_1404c66f0();
    void FUN_1404c6840(const CGuildPVPHistoryData* other);
    void FUN_1404c6a00(COutPacket* out);
    void FUN_1404c6a30(CInPacket* in);
    void FUN_1404c6a80(COutputStream& out);
    void FUN_1404c6cb0(CInputStream& in);
    int f18,f1c; unsigned char f20; __int64 f28,f30; CStringW f38,f40; int f48,f4c,f50,f54; CStringW f58[5],f80[5]; unsigned char fa8[5]; __int64 fb0,fb8;
};
MS2_CHECK_SIZE(CGuildPVPHistoryData,0xc0);
class CGuildGrade : public CPtred {
public:
    CGuildGrade();
    virtual ~CGuildGrade();
    void FUN_1404c70a0();
    void FUN_1404c70f0(int g,CStringW n,int p);
    void FUN_1404c7160(COutputStream& out);
    void FUN_1404c71d0(CInPacket& packet);
    int FUN_1404c72b0();
    int grade; CStringW name; int permissions;
};
MS2_CHECK_SIZE(CGuildGrade,0x30);
class CGuildNameInfo : public CPtred {
public:
    CGuildNameInfo();
    virtual ~CGuildNameInfo();
    void FUN_1404c73d0();
    void FUN_1404c7420(const CGuildNameInfo* other);
    void FUN_1404c74a0(COutPacket* out);
    void FUN_1404c74d0(CInPacket* in);
    void FUN_1404c7520(COutputStream& out);
    void FUN_1404c75a0(CInputStream& in);
    __int64 id; CStringW name; CString code;
};
MS2_CHECK_SIZE(CGuildNameInfo,0x30);
class CGuildJoinRequestForGuild : public CPtred {
public:
    CGuildJoinRequestForGuild();
    virtual ~CGuildJoinRequestForGuild();
    void FUN_1404c7750();
    void FUN_1404c7800(const CGuildJoinRequestForGuild* other);
    void FUN_1404c7910(COutPacket* out);
    void FUN_1404c7940(CInPacket* in);
    void FUN_1404c7990(COutputStream& out);
    void FUN_1404c7ad0(CInputStream& in);
    __int64 f18,f20,f28,f30; CStringW f38; CString f40; int f48,f4c,f50; Unk_GuildTriple f54; __int64 f60;
};
MS2_CHECK_SIZE(CGuildJoinRequestForGuild,0x68);
class CGuildJoinRequestForChar : public CPtred {
public:
    CGuildJoinRequestForChar();
    virtual ~CGuildJoinRequestForChar();
    void FUN_1404c7d70();
    void FUN_1404c7e30(const CGuildJoinRequestForChar* other);
    void FUN_1404c7f60(COutPacket* out);
    void FUN_1404c7f90(CInPacket* in);
    void FUN_1404c7fe0(COutputStream& out);
    void FUN_1404c8150(CInputStream& in);
    __int64 f18,f20; CStringW f28; int f30; CString f38; int f40; Unk_GuildTriple f44; int f50; CStringW f58; __int64 f60,f68,f70;
};
MS2_CHECK_SIZE(CGuildJoinRequestForChar,0x78);
class CGuildJoinRequestSchCond : public CPtred {
public:
    CGuildJoinRequestSchCond();
    virtual ~CGuildJoinRequestSchCond();
    void FUN_1404c8410();
    void FUN_1404c84e0(COutPacket* out);
    void FUN_1404c8510(CInPacket* in);
    void FUN_1404c8560(COutputStream& out);
    void FUN_1404c85b0(CInputStream& in);
    void FUN_1404c8440(const CGuildJoinRequestSchCond* other);
    int FUN_1404c8490(const CGuildJoinRequestSchCond* other);
    int FUN_1404c8600();
    int FUN_1404c8650();
    int FUN_1404c86a0();
    int FUN_1404c86f0();
    int f18,f1c;
};
MS2_CHECK_SIZE(CGuildJoinRequestSchCond,0x20);
class CSearchGuildJoin : public CPtred {
public:
    CSearchGuildJoin();
    virtual ~CSearchGuildJoin();
    void FUN_1404c8860();
    void FUN_1404c8910(const CSearchGuildJoin* other);
    void FUN_1404c8a20(COutPacket* out);
    void FUN_1404c8a50(CInPacket* in);
    void FUN_1404c8aa0(COutputStream& out);
    void FUN_1404c8be0(CInputStream& in);
    __int64 f18; CStringW f20; CString f28; int f30,f34; Unk_GuildTriple f38; int f44; __int64 f48,f50; CStringW f58;
};
MS2_CHECK_SIZE(CSearchGuildJoin,0x60);
class CGuildInviteInfo : public CPtred {
public:
    CGuildInviteInfo();
    virtual ~CGuildInviteInfo();
    void FUN_1404c8f00();
    void FUN_1404c8f70(const CGuildInviteInfo* other);
    void FUN_1404c9020(CGuildInfo* guild,CStringW a,CStringW b);
    void FUN_1404c9160(COutputStream& out);
    void FUN_1404c9230(CInputStream& in);
    __int64 f18; CStringW f20; CString f28; CStringW f30,f38;
};
MS2_CHECK_SIZE(CGuildInviteInfo,0x40);
class Unk_GuildMemberData {
public:
    Unk_GuildMemberData();
    ~Unk_GuildMemberData();
    void FUN_1404c9490();
    void FUN_1404c95b0(COutputStream& out);
    void FUN_1404c95f0(CInPacket& in);
    void FUN_1404c9640(COutPacket* out);
    void FUN_1404c9670(CInPacket* in);
    void FUN_1404c96c0(COutputStream& out);
    void FUN_1404c97a0(CInPacket& in);
    void FUN_1404c99d0(COutputStream& out);
    void FUN_1404c9bd0(CInputStream& in);
    void FUN_1404c9ef0(COutputStream& out);
    void FUN_1404c9fe0(CInputStream& in);
    void FUN_1404ca1a0(const Unk_GuildMemberData& other);
    void FUN_1404ca3e0(Unk_GuildCharacter* other);
    void FUN_1404ca680(const CGuildJoinRequestForGuild* other);
    CStringW FUN_1404ca890();
    void FUN_1404ca910(CStringW value);
    CString FUN_1404ca980();
    void FUN_1404caa00(CString value);
    __int64 f00,f08; unsigned char f10; int f14,f18; short f1c; int f20,f24,f28; Unk_GuildTriple f2c; int f38,f3c,f40; __int64 f48; CLockCriticalSection lock; CStringW name; CString code;
};
MS2_CHECK_SIZE(Unk_GuildMemberData,0x90);
class CGuildMemberRaid : public CPtred {
public:
    CGuildMemberRaid();
    virtual ~CGuildMemberRaid();
    bool FUN_1404cab20();
    void FUN_1404cabb0(const CGuildMemberRaid& other);
    bool FUN_1404cac30(unsigned long id,int count);
    void FUN_1404cad50(unsigned long id,int count,bool);
    int FUN_1404cadc0();
    int FUN_1404cae90(unsigned long id);
    void FUN_1404caf50(COutputStream& out);
    void FUN_1404cb070(CInputStream& in);
    std::map<unsigned long,int> raids; CLockCriticalSection lock;
};
MS2_CHECK_SIZE(CGuildMemberRaid,0x58);
class CGuildMember : public CPtred {
public:
    CGuildMember();
    virtual ~CGuildMember();
    void FUN_1404cb250();
    int FUN_1404cb370();
    Unk_GuildTriple* FUN_1404cb390();
    int FUN_1404cb3b0();
    int FUN_1404cb3e0();
    void FUN_1404cb420(COutPacket* out);
    void FUN_1404cb450(CInPacket* in);
    void FUN_1404cb4a0(COutputStream& out);
    void FUN_1404cb6c0(CInputStream& in);
    __int64 f18; Unk_GuildMemberData data; int fb0,fb4; CStringW fb8; int fc0; __int64 fc8,fd0,fd8; int fe0,fe4,fe8,fec,ff0; __int64 ff8; CGuildMemberRaid raid; int f158;
};
MS2_CHECK_SIZE(CGuildMember,0x160);

// ---- Part 1b: guild skill/event/storage/npc records and the synchronized CGuildInfo (owner of the shared declarations) ----
// Intrusive smart pointer handle as used by the guild containers: the MS2Ptr<T> shape (16 bytes, object pointer at +8).
// Proof: null ctor 0x1404ec890 / 0x1404ec640 store 0 to [this+8], copy ctor 0x1404ec820 copies [src+8] then AddRefs,
// get 0x1404f0bb0 returns [this+8], assign-raw 0x1404efb30 swaps [this+8], release 0x140504020 clears [this+8]; the
// CGuildInfo members f310/f360 are 16 apart from their neighbours (CGuildManager ctor 0x1413b5a10 puts its first own
// member at 0x378 = 8 (TSingleton) + sizeof(CGuildInfo) 0x370). The element helpers live in neighbouring chunks
// and are reached through FUN_ declarations (see guilddef_1.cpp).
struct Unk_GuildRef { void* m_unk_00; void* p; };
MS2_CHECK_SIZE(Unk_GuildRef,16);
// Opaque blobs for containers whose element helpers live in other chunks (sizes proven by the neighbouring member offsets).
template<int N> struct Unk_GuildBlob { __int64 q[N/8]; };
struct Unk_GuildPair { int a,b; };
// {CStringW name; __int64 value; CStringW text} map value of CGuildInfo (size 0x18); ctor 0x1404ee6b0, dtor 0x1404ef6e0.
struct Unk_GuildStrRec {
    __int64 q0,q1,q2;
    CStringW& name() { return *(CStringW*)&q0; }
    CStringW& text() { return *(CStringW*)&q2; }
};
struct Unk_GuildArr3 { __int64 a,b,c; };
MS2_CHECK_SIZE(Unk_GuildStrRec,0x18);
class CGuildSkill : public CPtred {
public:
    CGuildSkill();
    virtual ~CGuildSkill();
    void FUN_1404cb9a0(const CGuildSkill* other);
    void FUN_1404cb9f0(COutputStream& out);
    void FUN_1404cba60(CInPacket& packet);
    int FUN_1404cbb00();
    int FUN_1404cbbf0();
    bool FUN_1404cbcd0();
    bool FUN_1404cbd20();
    int f18,f1c; __int64 f20;
};
MS2_CHECK_SIZE(CGuildSkill,0x28);
class CGuildCustomEvent : public CPtred {
public:
    CGuildCustomEvent();
    virtual ~CGuildCustomEvent();
    void FUN_1404cbde0(const CGuildCustomEvent* other);
    void FUN_1404cbe20(COutputStream& out);
    void FUN_1404cbe70(CInPacket& packet);
    bool FUN_1404cbee0();
    int f18; __int64 f20;
};
MS2_CHECK_SIZE(CGuildCustomEvent,0x28);
void FUN_1404edfa0(void*); void FUN_1404ee000(void*); void FUN_1404ede30(void*); void FUN_1404ee5f0(void*);
void FUN_1404ef230(void*); void FUN_1404ef270(void*); void FUN_1404ef120(void*); void FUN_1404ef6a0(void*);
struct Unk_GuildMapA { __int64 q[2]; Unk_GuildMapA(){FUN_1404edfa0(this);} ~Unk_GuildMapA(){FUN_1404ef230(this);} };
struct Unk_GuildMapB { __int64 q[2]; Unk_GuildMapB(){FUN_1404ee000(this);} ~Unk_GuildMapB(){FUN_1404ef270(this);} };
struct Unk_GuildMapC { __int64 q[5]; Unk_GuildMapC(){FUN_1404ede30(this);} ~Unk_GuildMapC(){FUN_1404ef120(this);} };
struct Unk_GuildHist { __int64 a,b,text;   /* MS2: no array (the exe frames have no /GS cookie); text is the CStringW the out-of-line ctor/dtor manage */ Unk_GuildHist(){FUN_1404ee5f0(this);} ~Unk_GuildHist(){FUN_1404ef6a0(this);}
    void FUN_1404c5be0(CInputStream& in);   // MS2: reads a, b (8 bytes each) and the text (CGuildManager 0x1413c5dc0)
};
struct Unk_GuildPtr { void* p; };   // distinct element type so the CAtlArray instantiation has a guild-only mangled name
class CGuildStorage;
// Nested record type name (sic) comes from the RTTI: CGuildStorage::CGuildStroageHistory.
class CGuildStorage : public CPtred {
public:
    class CGuildStroageHistory : public CPtred {
    public:
        CGuildStroageHistory();
        virtual ~CGuildStroageHistory();
        Unk_GuildHist f18,f30; ItemEntity item; __int64 f78;
    };
    CGuildStorage();
    virtual ~CGuildStorage();
    void FUN_1404cc110(const CGuildStorage* other);
    void FUN_1404cc160(COutputStream& out);
    void FUN_1404cc210(CInPacket& packet);
    Unk_GuildMapA f18; Unk_GuildMapB f28; Unk_GuildMapC f38; ATL::CAtlArray<Unk_GuildPtr> f60;
};
MS2_CHECK_SIZE(CGuildStorage::CGuildStroageHistory,0x80);
MS2_CHECK_SIZE(CGuildStorage,0x80);
class CGuildNpc : public CPtred {
public:
    CGuildNpc();
    virtual ~CGuildNpc();
    void FUN_1404cc3b0(const CGuildNpc* other);
    void FUN_1404cc3f0(COutputStream& out);
    void FUN_1404cc440(CInPacket& packet);
    int f18,f1c;
};
MS2_CHECK_SIZE(CGuildNpc,0x20);
class CGuildInfo {
public:
    CGuildInfo();
    ~CGuildInfo();
    virtual int vfunc_0(Unk_GuildRef* member);
    virtual void vfunc_1(CStringW name);
    virtual void vfunc_2(__int64 value,CStringW name,int key,const CStringW& text);
    void FUN_1404cc900();
    __int64 FUN_1404ccbd0(); void FUN_1404ccc40(__int64 v);
    CStringW FUN_1404cccb0(); void FUN_1404ccd40(const CStringW& v);
    CString FUN_1404ccdb0(); void FUN_1404cce40(CString v);
    __int64 FUN_1404ccec0(); void FUN_1404ccf30(__int64 v);
    CStringW FUN_1404ccfa0(); void FUN_1404cd030(CStringW v);
    CStringW FUN_1404cd0b0(); void FUN_1404cd140(CStringW v);
    int FUN_1404cd1c0(); void FUN_1404cd2b0(int v);
    void FUN_1404cd310(__int64 a,__int64 b,CStringW c,int unused);   // every caller passes 1 as the last argument
    __int64 FUN_1404cd3b0(); __int64 FUN_1404cd420(); CStringW FUN_1404cd490();
    __int64 FUN_1404cd530(); void FUN_1404cd5b0(__int64 v);
    __int64 FUN_1404cd620(); void FUN_1404cd6a0(__int64 v);
    void FUN_1404cd710(int a,__int64 b,__int64 c,CStringW d);
    void FUN_1404cd7d0(COutputStream& out);
    void FUN_1404cdda0(CInPacket& packet);
    void FUN_1404ce690(COutputStream& out); void FUN_1404ce790(CInPacket& packet);
    void FUN_1404ce8f0(COutputStream& out); void FUN_1404cea10(CInPacket& packet);
    void FUN_1404ceb90(COutputStream& out); void FUN_1404ceca0(CInPacket& packet);
    void FUN_1404cee00(COutputStream& out); void FUN_1404cef10(CInPacket& packet);
    void FUN_1404cf070(COutputStream& out); void FUN_1404cf1e0(CInPacket& packet);
    void FUN_1404cf390(COutputStream& out); void FUN_1404cf490(CInPacket& packet);
    void FUN_1404cf5f0(COutputStream& out); void FUN_1404cf6c0(CInPacket& packet);
    MS2Ptr<CGuildMember> FUN_1404cf9f0(CStringW name);   // member by name (sret)
    MS2Ptr<CGuildMember> FUN_1404cfb00(__int64 id);      // member by character id (sret)
    void FUN_1404cfc70(const CStringW& oldName,const CStringW& newName);
    void FUN_1404cfdb0(const CStringW& name,int value);
    void FUN_1404cfe60(const CStringW& name,__int64 value);
    unsigned __int64 FUN_1404cff20();
    int FUN_1404d0020();
    Unk_PayloadPtr<CGuildMember> FUN_1404d00a0();   // the same function as a value return: the master (uiguilddialog.cpp)
    Unk_GuildRef* FUN_1404d00a0(Unk_GuildRef* ret); void FUN_1404d0130(Unk_GuildRef* v);
    int FUN_1404d01b0(CStringW name);
    void FUN_1404d0330(void* out); void FUN_1404d0420(void* out);
    int FUN_1404d0510(); int FUN_1404d0580();
    int FUN_1404d0600(CStringW name,unsigned mask);
    unsigned FUN_1404d06a0(CStringW name);
    Unk_GuildRef* FUN_1404d0860(Unk_GuildRef* ret,int index);
    Unk_PayloadPtr<CGuildGrade> FUN_1404d0860(int index);   // the same function as a value return (uiguilddialog.cpp)
    int FUN_1404d0990(int index,Unk_GuildRef* grade);
    CStringW FUN_1404d0af0(int index);
    int FUN_1404d0c00(); int FUN_1404d0d00(); int FUN_1404d0df0(); int FUN_1404d0ee0();
    unsigned FUN_1404d0ff0(); void FUN_1404d1060(int v);
    unsigned FUN_1404d10d0(); void FUN_1404d1140(int v);
    void FUN_1404d11b0(int a,int b,int c,int d,int e,int f,int g);
    unsigned FUN_1404d1280(); void FUN_1404d12f0(int v);
    unsigned FUN_1404d1360(); void FUN_1404d13d0(int v);
    unsigned FUN_1404d1440(); unsigned FUN_1404d14b0(); void FUN_1404d1520(int v);
    unsigned FUN_1404d1590(); void FUN_1404d1600(int v);
    unsigned FUN_1404d1670();
    int FUN_1404d16e0();
    void FUN_1404d17e0(int a,int b);
    unsigned FUN_1404d1860(); unsigned FUN_1404d18d0();
    void FUN_1404d1940(int v);
    bool FUN_1404d1990(int delta);
    int FUN_1404d1a80(); int FUN_1404d1ad0();
    void FUN_1404d1b40(int v);
    bool FUN_1404d1ba0(int delta);
    void FUN_1404d1c90(int v);
    bool FUN_1404d1d00(int delta);
    int FUN_1404d1df0(); int FUN_1404d1e40(); int FUN_1404d1e90();
    int FUN_1404d1f20();
    void FUN_1404d1f40(int v); int FUN_1404d1f90();
    void FUN_1404d1fe0(int v); int FUN_1404d2030();
    int FUN_1404d2080();
    CStringW FUN_1404d2220(int key);
    __int64 FUN_1404d2330(int key);
    CStringW FUN_1404d2400(int key);
    int FUN_1404d2510(int a,int b);
    void FUN_1404d25a0(Unk_GuildRef* skill);
    MS2Ptr<CGuildSkill> FUN_1404d2640(int key);           // skill by id (sret)
    int FUN_1404d26f0(int key);
    MS2Ptr<CGuildCustomEvent> FUN_1404d27b0(int key);     // custom event by id (sret)
    void FUN_1404d2860(Unk_GuildRef* npc);
    Unk_GuildRef* FUN_1404d28e0(Unk_GuildRef* ret,int key);
    int FUN_1404d2990(int key);
    void FUN_1404d2a10(CInPacket* packet);
    void FUN_1404d2b00(int a,void* b); void FUN_1404d2ba0(int a,void* b);
    bool FUN_1404d2c60(); int FUN_1404d2ca0();
    void FUN_1404d2cc0(ItemEntity* item);
    int FUN_1404d2db0(int a,int b);
    void FUN_1404d2e90(const Unk_GuildHist* a,const Unk_GuildHist* b,const ItemEntity* item,__int64 c);   // MS2: the callers pass Unk_GuildHist (ctor 0x1404ee5f0)
    void FUN_1404d3050(void* list);
    void FUN_1404d3140(const Unk_GuildSeason* season);
    Unk_GuildSeason* FUN_1404d3180();
    void FUN_1404d31b0();
    int FUN_1404d3400(void* out);   // fills a member map, returns its count
    void FUN_1404d3600(int v); int FUN_1404d3620();
    Unk_GuildRef* FUN_1404d3640(Unk_GuildRef* ret);
    void FUN_1404d36d0();
    void FUN_1404d3b80();
    void FUN_1404d3e70();
    // @0x1404d3fe0 / 0x1404d4060: the Unk_GuildStrRec (de)serializers are free helpers in guilddef_1.cpp.
    CLockCriticalSection lock; __int64 f38; CStringW f40; CString f48; int f50; CStringW f58,f60; __int64 f68,f70,f78; CStringW f80; __int64 f88,f90; CStringW f98;
    ATL::CAtlArray<Unk_PayloadPtr<CGuildGrade> > fa0; int fc0,fc4; __int64 fc8,fd0; CStringW fd8; Unk_GuildSeason season;   // MS2: fa0 holds the grades (CAtlArray<Unk_PayloadPtr<CGuildGrade>> RemoveAll 0x1404f86e0 / SetCount 0x1404f9b50 / SetAt 0x1404f9730)
    int f130,f134,f138,f13c,f140,f144,f148,f14c,f150,f154,f158,f15c,f160,f164,f168,f16c;
    Unk_GuildBlob<0x48> f170; CGuildStorage storage; Unk_GuildBlob<0x48> f238,f280,f2c8; Unk_GuildRef f310; Unk_GuildBlob<0x30> f320;
    // @0x14197dff0
    CGuildStorage* FUN_14197dff0() { return &storage; }   // the storage (inline; uiguilddialog.cpp)
    int f350; unsigned char f354; int f358; Unk_GuildRef f360;   // f360: MS2Ptr<CGuildNpcShopMgr> (new 0x28, ctor 0x1404ee230)
    MS2_LAYOUT_FRIEND;
};
MS2_CHECK_SIZE(CGuildInfo,0x370);
MS2_CHECK_OFFSET(CGuildInfo,f310,0x310);
MS2_CHECK_OFFSET(CGuildInfo,f320,0x320);
MS2_CHECK_OFFSET(CGuildInfo,f360,0x360);

void FUN_1404d3fe0(Unk_GuildStrRec* rec,COutputStream* out);
void FUN_1404d4060(Unk_GuildStrRec* rec,CInPacket* packet);
