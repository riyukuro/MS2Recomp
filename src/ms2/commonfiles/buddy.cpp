// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CBuddy: one friend-list entry (the class is declared in
// client/ms2/buddymanager.h, which this unit shares with CBuddyManager).
// MS2-UNIT: ?\buddy.cpp
// MS2-RANGE: 0x1401cbd50-0x1401cd310 .text$mn
// MS2-RANGE: 0x1400b4640-0x1400b4657 .text$di
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\buddy.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include "ms2/client/ms2/buddymanager.h"
#include <efd/ISystemService.h>
#include <efd/ServiceManager.h>
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// The packet object CBuddyManager hands to the reader: a virtual at slot 0 and the CInputStream sub-object at +8.
// (buddymanager.cpp keeps its own shape of this class; neither constructs it.)
class Unk_BuddyInputBase { public: virtual unsigned vfunc_0(); };
// The stream sub-object: CInputStream with every slot declared concrete (the reads are virtual calls on the member).
class Unk_BuddyReadStream : public CInputStream {
public:
    virtual bool ReadBool(); virtual unsigned char ReadUInt8(); virtual short ReadInt16(); virtual int ReadInt32();
    virtual __int64 ReadInt64(); virtual float ReadFloat(); virtual CString ReadUnicodeStringA(); virtual CString ReadString();
    virtual CStringW ReadUnicodeString(); virtual void ReadBytes(void* data, int count); virtual Unk_StreamPoint ReadVector3();
    virtual Unk_StreamPoint ReadVector3Short(); virtual float ReadShortX10(); virtual float ReadShortX100();
    virtual float ReadShortScaled(int scale); virtual float ReadShortDiv10(); virtual float ReadShortDivScaled(int scale);
};
class Unk_BuddyInput : public Unk_BuddyInputBase { public: Unk_BuddyReadStream stream; };

// The application service (class id 0x06100017) looked up through the global service manager cell; the unit only
// calls one lookup method of it. DAT_143b059e8 is the framework (ms2entitymanagerservice.cpp keeps the same view).
class Unk_Service6100017 : public efd::ISystemService {
public:
    static const efd::ClassID CLASS_ID = 0x06100017;
    int FUN_1410d33a0(unsigned, Unk_StreamPoint*);
};
struct Unk_EntityAppFramework { efd::ServiceManagerPtr manager; };
extern Unk_EntityAppFramework DAT_143b059e8;
extern Unk_StreamPoint DAT_143b01a60;
Unk_Service6100017* FUN_1401cd040(Unk_EntityAppFramework*);

// A header static of this unit: a pointer-sized handle constructed from 0 through a base ctor (the two COMDATs
// 0x1401cd100 / 0x1401cd130 and the lone initializer 0x1400b4640). Its real type is unknown.
class Unk_BuddyHandleBase { public: Unk_BuddyHandleBase(void* h) : handle(h) {} void* handle; };
class Unk_BuddyHandle : public Unk_BuddyHandleBase { public: Unk_BuddyHandle(void* h) : Unk_BuddyHandleBase(h) {} };
static Unk_BuddyHandle s_buddyHandle(0);

// @0x1401cbd50
CBuddy::CBuddy()
    : position(0), id(0), account(0), m_48(0), m_50(0), m_58(0), m_90(0), m_98(0), m_9c(0), m_a0(1), m_a4(0), m_a8(0),
      m_b8(0), m_bc(0), m_c0(0), m_d0(0) {
    f0 = 0;
    f1 = 0;
    f2 = 0;
    f3 = 0;
    f4 = 0;
    f5 = 0;
    f6 = 0;
    f7 = 0;
    f8 = 0;
    fRest = 0;
    m_ac.Clear();
}
// @0x1401cc020
CBuddy::~CBuddy() {}
// @0x1401cc0d0
CString CBuddy::FUN_1401cc0d0() {
    if (f0 != 0) return CString("offline");
    if (f6 != 0) return CString("away");
    const char* text;
    if (f5 != 0) text = "online"; else text = "offline";
    return CString(text);
}
MS2_REPLACE_METHOD(0x1401CC0D0, CBuddy, FUN_1401cc0d0, 220, 0xE20574BB);
// @0x1401cc1c0
CStringW CBuddy::FUN_1401cc1c0() { return name; }
MS2_REPLACE_METHOD(0x1401CC1C0, CBuddy, FUN_1401cc1c0, 66, 0x28B2A44D);
// @0x1401cc210
short CBuddy::FUN_1401cc210() { return m_98; }
MS2_REPLACE_METHOD(0x1401CC210, CBuddy, FUN_1401cc210, 18, 0x0DBE6A62);
// @0x1401cc230
__int64 CBuddy::FUN_1401cc230() { return account; }
MS2_REPLACE_METHOD(0x1401CC230, CBuddy, FUN_1401cc230, 15, 0x8B0075C1);
// @0x1401cc250
__int64 CBuddy::FUN_1401cc250() { return m_48; }
MS2_REPLACE_METHOD(0x1401CC250, CBuddy, FUN_1401cc250, 15, 0x5AEB0F79);
// @0x1401cc270
int CBuddy::FUN_1401cc270() { return m_9c; }
MS2_REPLACE_METHOD(0x1401CC270, CBuddy, FUN_1401cc270, 17, 0x444DCEE7);
// @0x1401cc290
int CBuddy::FUN_1401cc290() { return m_a0; }
MS2_REPLACE_METHOD(0x1401CC290, CBuddy, FUN_1401cc290, 17, 0xB518FD33);
// @0x1401cc2b0
int CBuddy::FUN_1401cc2b0() {
    if (m_a4 == 0) return m_a0 * 10;
    return m_a4;
}
MS2_REPLACE_METHOD(0x1401CC2B0, CBuddy, FUN_1401cc2b0, 45, 0x905EA3AC);
// @0x1401cc2f0
__int64 CBuddy::FUN_1401cc2f0() { return id; }
MS2_REPLACE_METHOD(0x1401CC2F0, CBuddy, FUN_1401cc2f0, 15, 0x7BFFD3E9);
// @0x1401cc310
int CBuddy::FUN_1401cc310() { return m_a8; }
MS2_REPLACE_METHOD(0x1401CC310, CBuddy, FUN_1401cc310, 17, 0xEA51A84B);
// @0x1401cc330
Unk_UserProxyColor* CBuddy::FUN_1401cc330() { return &m_ac; }
MS2_REPLACE_METHOD(0x1401CC330, CBuddy, FUN_1401cc330, 17, 0x3090C907);
// @0x1401cc350
CStringW CBuddy::FUN_1401cc350() { return m_c8; }
MS2_REPLACE_METHOD(0x1401CC350, CBuddy, FUN_1401cc350, 68, 0x92E42477);
// @0x1401cc3a0
int CBuddy::FUN_1401cc3a0() { return m_bc; }
MS2_REPLACE_METHOD(0x1401CC3A0, CBuddy, FUN_1401cc3a0, 17, 0xEF627A07);
// @0x1401cc3c0
int CBuddy::FUN_1401cc3c0() { return m_c0; }
MS2_REPLACE_METHOD(0x1401CC3C0, CBuddy, FUN_1401cc3c0, 17, 0x33D25353);
// @0x1401cc3e0
int CBuddy::FUN_1401cc3e0() { return m_b8; }
MS2_REPLACE_METHOD(0x1401CC3E0, CBuddy, FUN_1401cc3e0, 17, 0x54C6247B);
// @0x1401cc400
int CBuddy::FUN_1401cc400(Unk_StreamPoint* out) {
    *out = DAT_143b01a60;
    if ((unsigned)m_b8 > 0) {
        efd::SmartPointer<Unk_Service6100017> service(FUN_1401cd040(&DAT_143b059e8));
        if (service->FUN_1410d33a0(m_bc, out)) return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1401CC400, CBuddy, FUN_1401cc400, 159, 0x9EAED7A0);
// @0x1401cc4b0
void CBuddy::FUN_1401cc4b0(int v) { m_d0 = v; }
MS2_REPLACE_METHOD(0x1401CC4B0, CBuddy, FUN_1401cc4b0, 25, 0x09284B7F);
// @0x1401cc4d0
int CBuddy::FUN_1401cc4d0() { return m_d0; }
MS2_REPLACE_METHOD(0x1401CC4D0, CBuddy, FUN_1401cc4d0, 17, 0x9E46CF83);
// @0x1401cc4f0
int CBuddy::FUN_1401cc4f0() {
    int v = m_d0;
    m_d0 = 0;
    return v;
}
MS2_REPLACE_METHOD(0x1401CC4F0, CBuddy, FUN_1401cc4f0, 46, 0xA54CC4C5);
// @0x1401cc530
CStringA* CBuddy::FUN_1401cc530() { return &m_28; }
MS2_REPLACE_METHOD(0x1401CC530, CBuddy, FUN_1401cc530, 15, 0x874435E1);
// @0x1401cc550
CStringW* CBuddy::FUN_1401cc550() { return &m_30; }
MS2_REPLACE_METHOD(0x1401CC550, CBuddy, FUN_1401cc550, 15, 0x3758D2A9);
// @0x1401cc570
CStringW* CBuddy::FUN_1401cc570() { return &m_60; }
MS2_REPLACE_METHOD(0x1401CC570, CBuddy, FUN_1401cc570, 15, 0x57D15959);
// @0x1401cc590
CStringW* CBuddy::FUN_1401cc590() { return &memo; }
MS2_REPLACE_METHOD(0x1401CC590, CBuddy, FUN_1401cc590, 15, 0x87E399A1);
// @0x1401cc5b0
unsigned CBuddy::FUN_1401cc5b0() { return f2; }
MS2_REPLACE_METHOD(0x1401CC5B0, CBuddy, FUN_1401cc5b0, 23, 0x758D9D8C);
// @0x1401cc5d0
int CBuddy::FUN_1401cc5d0() { return f0; }
MS2_REPLACE_METHOD(0x1401CC5D0, CBuddy, FUN_1401cc5d0, 20, 0xC2CC3355);
// @0x1401cc5f0
int CBuddy::FUN_1401cc5f0() {
    int r;
    if (f2 == 0 && f0 == 0 && f1 == 0) r = 1; else r = 0;
    return r;
}
MS2_REPLACE_METHOD(0x1401CC5F0, CBuddy, FUN_1401cc5f0, 92, 0x5BD7EE38);
// @0x1401cc660
int CBuddy::FUN_1401cc660() { return f1; }
MS2_REPLACE_METHOD(0x1401CC660, CBuddy, FUN_1401cc660, 22, 0xD4BC6A24);
// @0x1401cc680
int CBuddy::FUN_1401cc680() { return f5; }
MS2_REPLACE_METHOD(0x1401CC680, CBuddy, FUN_1401cc680, 23, 0x895787C5);
// @0x1401cc6a0
unsigned CBuddy::FUN_1401cc6a0() { return f7; }
MS2_REPLACE_METHOD(0x1401CC6A0, CBuddy, FUN_1401cc6a0, 23, 0x1F6D3937);
// @0x1401cc6c0
void CBuddy::FUN_1401cc6c0() { f6 = 0; f5 = 1; }
MS2_REPLACE_METHOD(0x1401CC6C0, CBuddy, FUN_1401cc6c0, 56, 0x0510611C);
// @0x1401cc700
void CBuddy::FUN_1401cc700() { f6 = 0; f5 = 0; }
MS2_REPLACE_METHOD(0x1401CC700, CBuddy, FUN_1401cc700, 56, 0x30A4A651);
// @0x1401cc740
void CBuddy::FUN_1401cc740() { f5 = 1; f6 = 1; }
MS2_REPLACE_METHOD(0x1401CC740, CBuddy, FUN_1401cc740, 56, 0x4CEA9C6F);
// @0x1401cc7c0
void CBuddy::FUN_1401cc7c0(Unk_BuddyInput& input) {
    id = (&input.stream)->ReadInt64();
    account = (&input.stream)->ReadInt64();
    m_48 = (&input.stream)->ReadInt64();
    name = (&input.stream)->ReadUnicodeString();
    m_30 = (&input.stream)->ReadUnicodeString();
    m_a8 = (unsigned short)(&input.stream)->ReadInt16();
    m_9c = (&input.stream)->ReadInt32();
    m_a0 = (&input.stream)->ReadInt32();
    m_a4 = (&input.stream)->ReadInt32();
    m_98 = (&input.stream)->ReadInt16();
    f0 = (&input.stream)->ReadUInt8();
    f1 = (&input.stream)->ReadUInt8();
    f2 = (&input.stream)->ReadUInt8();
    f5 = (&input.stream)->ReadUInt8();
    f6 = (&input.stream)->ReadUInt8();
    m_50 = (unsigned)(&input.stream)->ReadInt32();
    m_58 = (unsigned)(&input.stream)->ReadInt32();
    m_28 = (&input.stream)->ReadUnicodeStringA();
    m_60 = (&input.stream)->ReadUnicodeString();
    memo = (&input.stream)->ReadUnicodeString();
    m_b8 = (&input.stream)->ReadInt32();
    m_bc = (&input.stream)->ReadInt32();
    m_c0 = (&input.stream)->ReadInt32();
    m_c8 = (&input.stream)->ReadUnicodeString();
    m_90 = (&input.stream)->ReadInt64();
    m_ac.FUN_140267e70(input.stream);
    flags |= 0x80;
}
MS2_REPLACE_METHOD(0x1401CC7C0, CBuddy, FUN_1401cc7c0, 2087, 0x6A3E5EB7);
// @0x1401cd040
Unk_Service6100017* FUN_1401cd040(Unk_EntityAppFramework* framework) {
    return framework->manager->GetSystemServiceAs<Unk_Service6100017>();
}
MS2_REPLACE(0x1401CD040, FUN_1401cd040, 35, 0x3CF7DD05);
MS2_EMIT_CRT_MEMMOVE_S();
