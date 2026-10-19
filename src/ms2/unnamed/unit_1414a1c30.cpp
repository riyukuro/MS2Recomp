// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Process-shutdown glue: one thunk per TSingleton-style global that deletes
// the singleton through its deleting destructor and clears the global (149 of them, 0x1414a1c30-0x1414a53f0), the matching
// GetInstance accessors, five ATL hash map (CAtlMap) RemoveAll instances with their auto-rehash lock helpers, and a handful of
// tiny virtual-slot stubs of classes that live in other units (CGameApp, the property visualization service, ...).
// File and function names are invented. The singleton classes themselves are not recovered here: they are opaque polymorphic
// types (Unk_SingletonObj*) whose only used member is the scalar deleting destructor in vftable slot 0.
// MS2-UNIT: unit_1414a1c30
// MS2-RANGE: 0x1414a1c30-0x1414a6010 .text$mn
#include "ms2/placeholder/ms2stdafx.h"
#include <atlstr.h>
#include <direct.h>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/filesystem.h"
#include "hook/ms2hook.h"

// Typed prefixes for the otherwise opaque getter objects and hash-chain nodes.
struct Unk_ShutdownValue30 { void* m_opaque[6]; int m_value; };
struct Unk_ShutdownNode18 { void* m_payload[3]; Unk_ShutdownNode18* m_next; };
struct Unk_ShutdownNode20 { void* m_payload[4]; Unk_ShutdownNode20* m_next; };
MS2_CHECK_SIZE(Unk_ShutdownValue30, 0x38);
MS2_CHECK_SIZE(Unk_ShutdownNode18, 0x20);
MS2_CHECK_SIZE(Unk_ShutdownNode20, 0x28);
MS2_CHECK_OFFSET(Unk_ShutdownValue30, m_value, 0x30);
MS2_CHECK_OFFSET(Unk_ShutdownNode18, m_next, 0x18);
MS2_CHECK_OFFSET(Unk_ShutdownNode20, m_next, 0x20);

// ---- opaque singleton objects ---------------------------------------------------------------------------------------------
class Unk_SingletonObj { public: virtual ~Unk_SingletonObj(); };                                // deleted via slot 0
class Unk_SingletonObj1 { public: virtual void vfunc_0(); virtual ~Unk_SingletonObj1(); };      // deleted via slot 1 (0x1414a3df0)
class Unk_SubObj { public: virtual ~Unk_SubObj(); };
class Unk_SingletonObj140 { public: char m_pad[0x140]; Unk_SubObj m_sub; };
class Unk_SingletonObj80 { public: char m_pad[0x80]; Unk_SubObj m_sub; };

// ---- exe globals (the singleton pointers) and getters of other units ----------------------------------------------------------
extern Unk_SingletonObj* DAT_143aab380;
extern Unk_SingletonObj* DAT_143aab390;
extern Unk_SingletonObj* DAT_143aac270;
extern Unk_SingletonObj140* DAT_143aac288;
extern Unk_SingletonObj* DAT_143aac298;
extern Unk_SingletonObj* DAT_143aac4c8;
extern Unk_SingletonObj* DAT_143aac4d8;
extern Unk_SingletonObj* DAT_143aac5c0;
extern Unk_SingletonObj1* DAT_143aac5c8;
extern Unk_SingletonObj* DAT_143aac638;
extern Unk_SingletonObj* DAT_143aacce8;
extern Unk_SingletonObj* DAT_143aad170;
extern Unk_SingletonObj* DAT_143aad1f0;
extern Unk_SingletonObj* DAT_143aad1f8;
extern Unk_SingletonObj* DAT_143aad288;
extern Unk_SingletonObj* DAT_143aaec50;
extern Unk_SingletonObj* DAT_143aaecf0;
extern Unk_SingletonObj* DAT_143aaecf8;
extern Unk_SingletonObj* DAT_143aaedf0;
extern Unk_SingletonObj* DAT_143aaeeb8;
extern Unk_SingletonObj* DAT_143aaef68;
extern Unk_SingletonObj* DAT_143aaf1c8;
extern Unk_SingletonObj* DAT_143aaf1d0;
extern Unk_SingletonObj* DAT_143aaf1d8;
extern Unk_SingletonObj* DAT_143aaf310;
extern Unk_SingletonObj* DAT_143aaf318;
extern Unk_SingletonObj* DAT_143aaf5e8;
extern Unk_SingletonObj* DAT_143ab0198;
extern Unk_SingletonObj* DAT_143ab0200;
extern Unk_SingletonObj* DAT_143ab0260;
extern Unk_SingletonObj* DAT_143ab02e0;
extern Unk_SingletonObj* DAT_143ab0340;
extern Unk_SingletonObj* DAT_143ab0388;
extern Unk_SingletonObj* DAT_143ab0398;
extern Unk_SingletonObj* DAT_143ab03a8;
extern Unk_SingletonObj* DAT_143ab03c8;
extern Unk_SingletonObj* DAT_143ab03d8;
extern Unk_SingletonObj* DAT_143ab0468;
extern Unk_SingletonObj* DAT_143ab0470;
extern Unk_SingletonObj* DAT_143ab0540;
extern Unk_SingletonObj* DAT_143ab0548;
extern Unk_SingletonObj* DAT_143ab05b8;
extern Unk_SingletonObj* DAT_143ab06f0;
extern Unk_SingletonObj* DAT_143ab0aa8;
extern Unk_SingletonObj* DAT_143ab0ac8;
extern Unk_SingletonObj* DAT_143ab0bd8;
extern Unk_SingletonObj* DAT_143ab0c70;
extern Unk_SingletonObj* DAT_143ab0d58;
extern Unk_SingletonObj* DAT_143ab0d60;
extern Unk_SingletonObj* DAT_143ab0d68;
extern Unk_SingletonObj* DAT_143ab0e50;
extern Unk_SingletonObj* DAT_143ab0e60;
extern Unk_SingletonObj* DAT_143ab0e68;
extern Unk_SingletonObj* DAT_143ab0f28;
extern Unk_SingletonObj* DAT_143ab0f68;
extern Unk_SingletonObj* DAT_143ab18c8;
extern Unk_SingletonObj* DAT_143ab1a28;
extern Unk_SingletonObj* DAT_143ab1a38;
extern Unk_SingletonObj* DAT_143ab1b18;
extern Unk_SingletonObj* DAT_143ab1c98;
extern Unk_SingletonObj* DAT_143ab1d28;
extern Unk_SingletonObj* DAT_143ab1f30;
extern Unk_SingletonObj* DAT_143ab1fc8;
extern Unk_SingletonObj* DAT_143ab1fd0;
extern Unk_SingletonObj* DAT_143ab2080;
extern Unk_SingletonObj* DAT_143ab2128;
extern Unk_SingletonObj* DAT_143ab22a8;
extern Unk_SingletonObj* DAT_143ab2628;
extern Unk_SingletonObj* DAT_143ab26c0;
extern Unk_SingletonObj* DAT_143ab26c8;
extern Unk_SingletonObj* DAT_143ab3328;
extern Unk_SingletonObj* DAT_143ab3338;
extern Unk_SingletonObj* DAT_143ab3340;
extern Unk_SingletonObj* DAT_143ab34d0;
extern Unk_SingletonObj* DAT_143ab34d8;
extern Unk_SingletonObj* DAT_143ab3700;
extern Unk_SingletonObj* DAT_143ab3708;
extern Unk_SingletonObj* DAT_143ab3850;
extern Unk_SingletonObj* DAT_143ab38f8;
extern Unk_SingletonObj* DAT_143ab3900;
extern Unk_SingletonObj* DAT_143ab3fc0;
extern Unk_SingletonObj* DAT_143ab4150;
extern Unk_SingletonObj* DAT_143ab4610;
extern Unk_SingletonObj* DAT_143ab4618;
extern Unk_SingletonObj* DAT_143ab4620;
extern Unk_SingletonObj* DAT_143ab4628;
extern Unk_SingletonObj* DAT_143ab4630;
extern Unk_SingletonObj* DAT_143ab47a0;
extern Unk_SingletonObj* DAT_143ab50b8;
extern Unk_SingletonObj* DAT_143ab50c0;
extern Unk_SingletonObj* DAT_143ab6718;
extern Unk_SingletonObj* DAT_143ab6730;
extern Unk_SingletonObj* DAT_143ab67d8;
extern Unk_SingletonObj* DAT_143ab6878;
extern Unk_SingletonObj* DAT_143ab7908;
extern Unk_SingletonObj* DAT_143ab8308;
extern Unk_SingletonObj* DAT_143ab8808;
extern Unk_SingletonObj* DAT_143ab89f0;
extern Unk_SingletonObj* DAT_143ab8aa0;
extern Unk_SingletonObj* DAT_143ab8aa8;
extern Unk_SingletonObj* DAT_143abb018;
extern Unk_SingletonObj* DAT_143abb148;
extern Unk_SingletonObj* DAT_143abb5f8;
extern Unk_SingletonObj* DAT_143abb698;
extern Unk_SingletonObj* DAT_143abb6d8;
extern Unk_SingletonObj* DAT_143abb830;
extern Unk_SingletonObj* DAT_143abd548;
extern Unk_SingletonObj* DAT_143abd628;
extern Unk_SingletonObj* DAT_143abd630;
extern Unk_SingletonObj* DAT_143abdd70;
extern Unk_SingletonObj* DAT_143abdfe8;
extern Unk_SingletonObj* DAT_143abf028;
extern Unk_SingletonObj* DAT_143abf520;
extern Unk_SingletonObj* DAT_143abf748;
extern Unk_SingletonObj* DAT_143abf7e8;
extern Unk_SingletonObj* DAT_143abf888;
extern Unk_SingletonObj* DAT_143abf898;
extern Unk_SingletonObj* DAT_143abfb18;
extern Unk_SingletonObj* DAT_143ac0d40;
extern Unk_SingletonObj* DAT_143ac1928;
extern Unk_SingletonObj* DAT_143ac2b20;
extern Unk_SingletonObj* DAT_143ac2e98;
extern Unk_SingletonObj* DAT_143ac3d20;
extern Unk_SingletonObj* DAT_143ac48f8;
extern Unk_SingletonObj* DAT_143ac49b8;
extern Unk_SingletonObj* DAT_143ac8008;
extern Unk_SingletonObj* DAT_143ac90f0;
extern Unk_SingletonObj* DAT_143acbb70;
extern Unk_SingletonObj* DAT_143acce38;
extern Unk_SingletonObj* DAT_143ad1578;
extern Unk_SingletonObj* DAT_143ad1580;
extern Unk_SingletonObj* DAT_143ad1ac8;
extern Unk_SingletonObj* DAT_143ad5158;
extern Unk_SingletonObj* DAT_143ad6820;
extern Unk_SingletonObj* DAT_143ad8330;
extern Unk_SingletonObj* DAT_143ad86c8;
extern Unk_SingletonObj* DAT_143ad9d70;
extern Unk_SingletonObj* DAT_143ad9d78;
extern Unk_SingletonObj* DAT_143ae0748;
extern Unk_SingletonObj* DAT_143ae0750;
extern Unk_SingletonObj* DAT_143ae0758;
extern Unk_SingletonObj* DAT_143ae0760;
extern Unk_SingletonObj* DAT_143ae0768;
extern Unk_SingletonObj* DAT_143ae0770;
extern Unk_SingletonObj* DAT_143ae0778;
extern Unk_SingletonObj* DAT_143ae0780;
extern Unk_SingletonObj* DAT_143ae0788;
extern Unk_SingletonObj* DAT_143ae0790;
extern Unk_SingletonObj* DAT_143ae0798;
extern Unk_SingletonObj* DAT_143ae07a0;
extern Unk_SingletonObj80* DAT_143ae07a8;
extern Unk_SingletonObj* DAT_143b05988;

Unk_SingletonObj* FUN_14015a050();
Unk_SingletonObj* FUN_140166440();
Unk_SingletonObj* FUN_140186320();
Unk_SingletonObj140* FUN_1401958b0();
Unk_SingletonObj* FUN_1401a9d70();
Unk_SingletonObj* FUN_1401c0da0();
Unk_SingletonObj* FUN_1401c0db0();
Unk_SingletonObj* FUN_1401d31f0();
Unk_SingletonObj1* FUN_1401d3200();
Unk_SingletonObj* FUN_1401d7a50();
Unk_SingletonObj* FUN_14025e7d0();
Unk_SingletonObj* FUN_14031c2a0();
Unk_SingletonObj* FUN_1403b4750();
Unk_SingletonObj* FUN_1403ed2a0();
Unk_SingletonObj* FUN_14041beb0();
Unk_SingletonObj* FUN_1404f4540();
Unk_SingletonObj* FUN_14052d210();
Unk_SingletonObj* FUN_14052d220();
Unk_SingletonObj* FUN_14052d230();
Unk_SingletonObj* FUN_140535320();
Unk_SingletonObj* FUN_140541580();
Unk_SingletonObj* FUN_140552df0();
Unk_SingletonObj* FUN_1405a1fd0();
Unk_SingletonObj* FUN_14067e910();
Unk_SingletonObj* FUN_1406aa4b0();
Unk_SingletonObj* FUN_1406aa4c0();
Unk_SingletonObj* FUN_1406c7610();
Unk_SingletonObj* FUN_1406d6e90();
Unk_SingletonObj* FUN_1406f2370();
Unk_SingletonObj* FUN_14071d7d0();
Unk_SingletonObj* FUN_1407476c0();
Unk_SingletonObj* FUN_140764020();
Unk_SingletonObj* FUN_140764030();
Unk_SingletonObj* FUN_14076dcd0();
Unk_SingletonObj* FUN_140789c40();
Unk_SingletonObj* FUN_1407b75e0();
Unk_SingletonObj* FUN_1409023c0();
Unk_SingletonObj* FUN_1409331f0();
Unk_SingletonObj* FUN_140933200();
Unk_SingletonObj* FUN_140933210();
Unk_SingletonObj* FUN_140933220();
Unk_SingletonObj* FUN_140933230();
Unk_SingletonObj* FUN_140939a00();
Unk_SingletonObj* FUN_140939a10();
Unk_SingletonObj* FUN_1409478c0();
Unk_SingletonObj* FUN_140953f30();
Unk_SingletonObj* FUN_1409670c0();
Unk_SingletonObj* FUN_1409670d0();
Unk_SingletonObj* FUN_140967100();
Unk_SingletonObj* FUN_140976580();
Unk_SingletonObj* FUN_1409bb9e0();
Unk_SingletonObj* FUN_1409c1740();
Unk_SingletonObj* FUN_1409eed10();
Unk_SingletonObj* FUN_1409eed20();
Unk_SingletonObj* FUN_1409eed30();
Unk_SingletonObj* FUN_1409eed40();
Unk_SingletonObj* FUN_1409eed50();
Unk_SingletonObj* FUN_1409eed60();
Unk_SingletonObj* FUN_1409eed70();
Unk_SingletonObj* FUN_1409eed80();
Unk_SingletonObj* FUN_1409eed90();
Unk_SingletonObj* FUN_1409f24a0();
Unk_SingletonObj* FUN_1409f24b0();
Unk_SingletonObj* FUN_1409f7c90();
Unk_SingletonObj* FUN_1409f7ca0();
Unk_SingletonObj* FUN_140a44830();
Unk_SingletonObj* FUN_140a4a7b0();
Unk_SingletonObj* FUN_140a6a840();
Unk_SingletonObj* FUN_140a87680();
Unk_SingletonObj* FUN_140aa6d40();
Unk_SingletonObj* FUN_140aadf70();
Unk_SingletonObj* FUN_140ac74e0();
Unk_SingletonObj* FUN_140ad0da0();
Unk_SingletonObj* FUN_140b1db00();
Unk_SingletonObj* FUN_140b20590();
Unk_SingletonObj* FUN_140b2e990();
Unk_SingletonObj* FUN_140b6a040();
Unk_SingletonObj* FUN_140b702a0();
Unk_SingletonObj* FUN_140bc09f0();
Unk_SingletonObj* FUN_140bccd50();
Unk_SingletonObj* FUN_140bfc4b0();
Unk_SingletonObj* FUN_140c0e750();
Unk_SingletonObj* FUN_140c24ef0();
Unk_SingletonObj* FUN_140c607b0();
Unk_SingletonObj* FUN_140c70240();
Unk_SingletonObj* FUN_140c7a250();
Unk_SingletonObj* FUN_140c9b8e0();
Unk_SingletonObj* FUN_140c9cb20();
Unk_SingletonObj* FUN_140cb17d0();
Unk_SingletonObj* FUN_140cea070();
Unk_SingletonObj* FUN_140cea080();
Unk_SingletonObj* FUN_140d13c40();
Unk_SingletonObj* FUN_140d52030();
Unk_SingletonObj* FUN_140dc19b0();
Unk_SingletonObj* FUN_140dd7910();
Unk_SingletonObj* FUN_140e5ca20();
Unk_SingletonObj* FUN_140e7c990();
Unk_SingletonObj* FUN_140e800e0();
Unk_SingletonObj* FUN_140e898d0();
Unk_SingletonObj* FUN_140ea4060();
Unk_SingletonObj* FUN_140ec3940();
Unk_SingletonObj* FUN_140ef0b20();
Unk_SingletonObj* FUN_140f17d50();
Unk_SingletonObj* FUN_140f26650();
Unk_SingletonObj* FUN_140f97ef0();
Unk_SingletonObj* FUN_140fb9980();
Unk_SingletonObj* FUN_141025b70();
Unk_SingletonObj* FUN_14109a710();
Unk_SingletonObj* FUN_14119f490();
Unk_SingletonObj* FUN_1411b1db0();
Unk_SingletonObj* FUN_1411b1dc0();
Unk_SingletonObj* FUN_1411b1dd0();
Unk_SingletonObj* FUN_1411b1de0();
Unk_SingletonObj* FUN_141245b20();
Unk_SingletonObj* FUN_1412976a0();
Unk_SingletonObj* FUN_1412db940();
Unk_SingletonObj* FUN_14131e120();
Unk_SingletonObj* FUN_14134e430();
Unk_SingletonObj* FUN_14135a4d0();
Unk_SingletonObj* FUN_141371b30();
Unk_SingletonObj* FUN_14140ea30();
Unk_SingletonObj* FUN_14140ea40();
// ---- in-unit getters (defined below)
Unk_SingletonObj* FUN_1414a56c0();
Unk_SingletonObj* FUN_1414a56d0();
Unk_SingletonObj* FUN_1414a56e0();
Unk_SingletonObj* FUN_1414a56f0();
Unk_SingletonObj* FUN_1414a5700();
Unk_SingletonObj* FUN_1414a5710();
Unk_SingletonObj* FUN_1414a5720();
Unk_SingletonObj* FUN_1414a5730();
Unk_SingletonObj* FUN_1414a5740();
Unk_SingletonObj* FUN_1414a5750();
Unk_SingletonObj* FUN_1414a5760();
Unk_SingletonObj* FUN_1414a5770();
Unk_SingletonObj* FUN_1414a5780();
Unk_SingletonObj* FUN_1414a5790();
Unk_SingletonObj* FUN_1414a57a0();
Unk_SingletonObj* FUN_1414a57b0();
Unk_SingletonObj* FUN_1414a57c0();
Unk_SingletonObj* FUN_1414a57d0();
Unk_SingletonObj* FUN_1414a57e0();
Unk_SingletonObj* FUN_1414a57f0();
Unk_SingletonObj* FUN_1414a5800();
Unk_SingletonObj* FUN_1414a5810();
Unk_SingletonObj* FUN_1414a5820();
Unk_SingletonObj* FUN_1414a5830();
Unk_SingletonObj* FUN_1414a5840();
Unk_SingletonObj* FUN_1414a5850();
Unk_SingletonObj* FUN_1414a5860();
Unk_SingletonObj* FUN_1414a5870();
Unk_SingletonObj80* FUN_1414a5880();
Unk_SingletonObj* FUN_1414a5890();
class Unk_MiscThis {
public:
    unsigned long long FUN_1414a55e0(); unsigned long long FUN_1414a55f0(); unsigned long long FUN_1414a5600(); void* FUN_1414a5640(); int* FUN_1414a5650(); int* FUN_1414a5660(); const char* FUN_1414a5680(); int FUN_1414a5a30();
};
// ---- misc externs ---------------------------------------------------------------------------------------------------------
extern char DAT_143ae0130; extern int DAT_143a01f90; extern int DAT_143a284b0; extern char* DAT_143afa980; extern int DAT_143ae2b48;
struct CResultObj { void* p; CResultObj(void* ptr); ~CResultObj(); };
void* FUN_1414a54f0_ctor(void* mem, void* self);
void FUN_1409a8120(void*); void FUN_1409f2d50(void*); void FUN_1409f2d60(void*); void FUN_140c8f690(void*); void* FUN_141427740(void*);
class Unk_HashMap1 {
public:
    void** m_ppBins; unsigned long long m_nElements; unsigned int m_nBins; char m_pad[0x1c]; int m_nLockCount;
    void FUN_1414a5450(); void FUN_1414a5540();
    void FUN_14076d7d0(void* pNode); bool FUN_14076e320(); unsigned int FUN_14076ea00(unsigned long long n); void FUN_14076e0e0(unsigned int n, int b); void FUN_14076d9d0();
    void FUN_1414a5ac0();
};
class Unk_HashMap2 {
public:
    void** m_ppBins; unsigned long long m_nElements; unsigned int m_nBins; char m_pad[0x1c]; int m_nLockCount;
    void FUN_1414a5470(); void FUN_1414a5560();
    void FUN_14076d8d0(void* pNode); bool FUN_14076e350(); unsigned int FUN_14076eaf0(unsigned long long n); void FUN_14076e200(unsigned int n, int b); void FUN_14076da20();
    void FUN_1414a5bd0();
};
class Unk_HashMap3 {
public:
    void** m_ppBins; unsigned long long m_nElements; unsigned int m_nBins; char m_pad[0x1c]; int m_nLockCount;
    void FUN_1414a5490(); void FUN_1414a5580();
    void FUN_1401a9940(void* pNode); bool FUN_1401aa520(); unsigned int FUN_1401aae10(unsigned long long n); void FUN_1401aa190(unsigned int n, int b); void FUN_1401a9c40();
    void FUN_1414a5ce0();
};
class Unk_HashMap4 {
public:
    void** m_ppBins; unsigned long long m_nElements; unsigned int m_nBins; char m_pad[0x1c]; int m_nLockCount;
    void FUN_1414a54b0(); void FUN_1414a55a0();
    void FUN_1401a9a40(void* pNode); bool FUN_1401aa550(); unsigned int FUN_1401aaf00(unsigned long long n); void FUN_1401aa2b0(unsigned int n, int b); void FUN_1401a9c90();
    void FUN_1414a5df0();
};
class Unk_HashMap5 {
public:
    void** m_ppBins; unsigned long long m_nElements; unsigned int m_nBins; char m_pad[0x1c]; int m_nLockCount;
    void FUN_1414a54d0(); void FUN_1414a55c0();
    void FUN_1401a9b40(void* pNode); bool FUN_1401aa580(); unsigned int FUN_1401aaff0(unsigned long long n); void FUN_1401aa3d0(unsigned int n, int b); void FUN_1401a9ce0();
    void FUN_1414a5f00();
};

// @0x1414a1c30
void FUN_1414a1c30()
{
    if (DAT_143ab0198 != 0) {
        delete FUN_1414a56e0();
        DAT_143ab0198 = 0;
    }
}
MS2_REPLACE(0x1414A1C30, FUN_1414a1c30, 94, 0x5D047549);
// @0x1414a1c90
void FUN_1414a1c90()
{
    if (DAT_143ab3328 != 0) {
        delete FUN_1409331f0();
        DAT_143ab3328 = 0;
    }
}
MS2_REPLACE(0x1414A1C90, FUN_1414a1c90, 94, 0x5F0E2522);
// @0x1414a1cf0
void FUN_1414a1cf0()
{
    if (DAT_143ab0200 != 0) {
        delete FUN_140ea4060();
        DAT_143ab0200 = 0;
    }
}
MS2_REPLACE(0x1414A1CF0, FUN_1414a1cf0, 94, 0x38EC75AE);
// @0x1414a1d50
void FUN_1414a1d50()
{
    if (DAT_143ae0798 != 0) {
        delete FUN_1414a56f0();
        DAT_143ae0798 = 0;
    }
}
MS2_REPLACE(0x1414A1D50, FUN_1414a1d50, 94, 0xCB3F4CBD);
// @0x1414a1db0
void FUN_1414a1db0()
{
    if (DAT_143ac2b20 != 0) {
        delete FUN_1414a5700();
        DAT_143ac2b20 = 0;
    }
}
MS2_REPLACE(0x1414A1DB0, FUN_1414a1db0, 94, 0x2FE8C8DA);
// @0x1414a1e10
void FUN_1414a1e10()
{
    if (DAT_143aac4d8 != 0) {
        delete FUN_1401c0da0();
        DAT_143aac4d8 = 0;
    }
}
MS2_REPLACE(0x1414A1E10, FUN_1414a1e10, 94, 0x06CE8805);
// @0x1414a1e70
void FUN_1414a1e70()
{
    if (DAT_143aab390 != 0) {
        delete FUN_140166440();
        DAT_143aab390 = 0;
    }
}
MS2_REPLACE(0x1414A1E70, FUN_1414a1e70, 94, 0x670F1EE5);
// @0x1414a1ed0
void FUN_1414a1ed0()
{
    if (DAT_143aac4c8 != 0) {
        delete FUN_1401c0db0();
        DAT_143aac4c8 = 0;
    }
}
MS2_REPLACE(0x1414A1ED0, FUN_1414a1ed0, 94, 0xE5A6F238);
// @0x1414a1f30
void FUN_1414a1f30()
{
    if (DAT_143ab8aa8 != 0) {
        delete FUN_140aadf70();
        DAT_143ab8aa8 = 0;
    }
}
MS2_REPLACE(0x1414A1F30, FUN_1414a1f30, 94, 0xE0475430);
// @0x1414a1f90
void FUN_1414a1f90()
{
    if (DAT_143ab0398 != 0) {
        delete FUN_1409eed10();
        DAT_143ab0398 = 0;
    }
}
MS2_REPLACE(0x1414A1F90, FUN_1414a1f90, 94, 0x9A1392E9);
// @0x1414a1ff0
void FUN_1414a1ff0()
{
    if (DAT_143ab0340 != 0) {
        delete FUN_14067e910();
        DAT_143ab0340 = 0;
    }
}
MS2_REPLACE(0x1414A1FF0, FUN_1414a1ff0, 94, 0xCAB7A503);
// @0x1414a2050
void FUN_1414a2050()
{
    if (DAT_143ab0388 != 0) {
        delete FUN_1409eed20();
        DAT_143ab0388 = 0;
    }
}
MS2_REPLACE(0x1414A2050, FUN_1414a2050, 94, 0x5C9BCF69);
// @0x1414a20b0
void FUN_1414a20b0()
{
    if (DAT_143ab03a8 != 0) {
        delete FUN_140d52030();
        DAT_143ab03a8 = 0;
    }
}
MS2_REPLACE(0x1414A20B0, FUN_1414a20b0, 94, 0xDFFD19A9);
// @0x1414a2110
void FUN_1414a2110()
{
    if (DAT_143ab03d8 != 0) {
        delete FUN_1412db940();
        DAT_143ab03d8 = 0;
    }
}
MS2_REPLACE(0x1414A2110, FUN_1414a2110, 94, 0xA6232421);
// @0x1414a2170
void FUN_1414a2170()
{
    if (DAT_143ab03c8 != 0) {
        delete FUN_1409eed30();
        DAT_143ab03c8 = 0;
    }
}
MS2_REPLACE(0x1414A2170, FUN_1414a2170, 94, 0x27944BBC);
// @0x1414a21d0
void FUN_1414a21d0()
{
    if (DAT_143ab4618 != 0) {
        delete FUN_1409eed40();
        DAT_143ab4618 = 0;
    }
}
MS2_REPLACE(0x1414A21D0, FUN_1414a21d0, 94, 0x7FDD7164);
// @0x1414a2230
void FUN_1414a2230()
{
    if (DAT_143ab0260 != 0) {
        delete FUN_140933200();
        DAT_143ab0260 = 0;
    }
}
MS2_REPLACE(0x1414A2230, FUN_1414a2230, 94, 0xD5C92767);
// @0x1414a2290
void FUN_1414a2290()
{
    if (DAT_143abb5f8 != 0) {
        delete FUN_140e5ca20();
        DAT_143abb5f8 = 0;
    }
}
MS2_REPLACE(0x1414A2290, FUN_1414a2290, 94, 0xC025FFEE);
// @0x1414a22f0
void FUN_1414a22f0()
{
    if (DAT_143ab02e0 != 0) {
        delete FUN_1409670c0();
        DAT_143ab02e0 = 0;
    }
}
MS2_REPLACE(0x1414A22F0, FUN_1414a22f0, 94, 0x658FD221);
// @0x1414a2350
void FUN_1414a2350()
{
    if (DAT_143abb698 != 0) {
        delete FUN_140b702a0();
        DAT_143abb698 = 0;
    }
}
MS2_REPLACE(0x1414A2350, FUN_1414a2350, 94, 0x73FAC6CE);
// @0x1414a23b0
void FUN_1414a23b0()
{
    if (DAT_143abb6d8 != 0) {
        delete FUN_140c70240();
        DAT_143abb6d8 = 0;
    }
}
MS2_REPLACE(0x1414A23B0, FUN_1414a23b0, 94, 0x70469E1B);
// @0x1414a2410
void FUN_1414a2410()
{
    if (DAT_143ab34d0 != 0) {
        delete FUN_140939a00();
        DAT_143ab34d0 = 0;
    }
}
MS2_REPLACE(0x1414A2410, FUN_1414a2410, 94, 0xEC6E0E4E);
// @0x1414a2470
void FUN_1414a2470()
{
    if (DAT_143ab0540 != 0) {
        delete FUN_1406f2370();
        DAT_143ab0540 = 0;
    }
}
MS2_REPLACE(0x1414A2470, FUN_1414a2470, 94, 0xD6A98232);
// @0x1414a24d0
void FUN_1414a24d0()
{
    if (DAT_143ac2e98 != 0) {
        delete FUN_140f17d50();
        DAT_143ac2e98 = 0;
    }
}
MS2_REPLACE(0x1414A24D0, FUN_1414a24d0, 94, 0x0C227F71);
// @0x1414a2530
void FUN_1414a2530()
{
    if (DAT_143abb830 != 0) {
        delete FUN_1414a5710();
        DAT_143abb830 = 0;
    }
}
MS2_REPLACE(0x1414A2530, FUN_1414a2530, 94, 0xCDA6DDFA);
// @0x1414a2590
void FUN_1414a2590()
{
    if (DAT_143ab3850 != 0) {
        delete FUN_140953f30();
        DAT_143ab3850 = 0;
    }
}
MS2_REPLACE(0x1414A2590, FUN_1414a2590, 94, 0x21B5BA98);
// @0x1414a25f0
void FUN_1414a25f0()
{
    if (DAT_143abf520 != 0) {
        delete FUN_140c7a250();
        DAT_143abf520 = 0;
    }
}
MS2_REPLACE(0x1414A25F0, FUN_1414a25f0, 94, 0x7FEBD5CE);
// @0x1414a2650
void FUN_1414a2650()
{
    if (DAT_143ab05b8 != 0) {
        delete FUN_14131e120();
        DAT_143ab05b8 = 0;
    }
}
MS2_REPLACE(0x1414A2650, FUN_1414a2650, 94, 0xA327B3AF);
// @0x1414a26b0
void FUN_1414a26b0()
{
    if (DAT_143ae0788 != 0) {
        delete FUN_1414a5720();
        DAT_143ae0788 = 0;
    }
}
MS2_REPLACE(0x1414A26B0, FUN_1414a26b0, 94, 0xF4B59DEF);
// @0x1414a2710
void FUN_1414a2710()
{
    if (DAT_143ab0aa8 != 0) {
        delete FUN_1411b1db0();
        DAT_143ab0aa8 = 0;
    }
}
MS2_REPLACE(0x1414A2710, FUN_1414a2710, 94, 0x0F17A306);
// @0x1414a2770
void FUN_1414a2770()
{
    if (DAT_143ab8808 != 0) {
        delete FUN_1414a5730();
        DAT_143ab8808 = 0;
    }
}
MS2_REPLACE(0x1414A2770, FUN_1414a2770, 94, 0xF22A46B0);
// @0x1414a27d0
void FUN_1414a27d0()
{
    if (DAT_143ab50c0 != 0) {
        delete FUN_1409f7c90();
        DAT_143ab50c0 = 0;
    }
}
MS2_REPLACE(0x1414A27D0, FUN_1414a27d0, 94, 0xDE0809E3);
// @0x1414a2830
void FUN_1414a2830()
{
    if (DAT_143ae0770 != 0) {
        delete FUN_1414a5740();
        DAT_143ae0770 = 0;
    }
}
MS2_REPLACE(0x1414A2830, FUN_1414a2830, 94, 0x1408F048);
// @0x1414a2890
void FUN_1414a2890()
{
    if (DAT_143acbb70 != 0) {
        delete FUN_140f97ef0();
        DAT_143acbb70 = 0;
    }
}
MS2_REPLACE(0x1414A2890, FUN_1414a2890, 94, 0xE0594503);
// @0x1414a28f0
void FUN_1414a28f0()
{
    if (DAT_143ab38f8 != 0) {
        delete FUN_1409670d0();
        DAT_143ab38f8 = 0;
    }
}
MS2_REPLACE(0x1414A28F0, FUN_1414a28f0, 94, 0xA7D7656B);
// @0x1414a2950
void FUN_1414a2950()
{
    if (DAT_143aaf1c8 != 0) {
        delete FUN_14052d210();
        DAT_143aaf1c8 = 0;
    }
}
MS2_REPLACE(0x1414A2950, FUN_1414a2950, 94, 0x2262C580);
// @0x1414a29b0
void FUN_1414a29b0()
{
    if (DAT_143aaf310 != 0) {
        delete FUN_140535320();
        DAT_143aaf310 = 0;
    }
}
MS2_REPLACE(0x1414A29B0, FUN_1414a29b0, 94, 0x213EEB3E);
// @0x1414a2a10
void FUN_1414a2a10()
{
    if (DAT_143ab50b8 != 0) {
        delete FUN_1409f7ca0();
        DAT_143ab50b8 = 0;
    }
}
MS2_REPLACE(0x1414A2A10, FUN_1414a2a10, 94, 0x3FA8C3C1);
// @0x1414a2a70
void FUN_1414a2a70()
{
    if (DAT_143ae0790 != 0) {
        delete FUN_1414a5750();
        DAT_143ae0790 = 0;
    }
}
MS2_REPLACE(0x1414A2A70, FUN_1414a2a70, 94, 0xF938B626);
// @0x1414a2ad0
void FUN_1414a2ad0()
{
    if (DAT_143ab0bd8 != 0) {
        delete FUN_1414a5760();
        DAT_143ab0bd8 = 0;
    }
}
MS2_REPLACE(0x1414A2AD0, FUN_1414a2ad0, 94, 0xEF432CFB);
// @0x1414a2b30
void FUN_1414a2b30()
{
    if (DAT_143aaf5e8 != 0) {
        delete FUN_140552df0();
        DAT_143aaf5e8 = 0;
    }
}
MS2_REPLACE(0x1414A2B30, FUN_1414a2b30, 94, 0x42CD3A87);
// @0x1414a2b90
void FUN_1414a2b90()
{
    if (DAT_143ab0d58 != 0) {
        delete FUN_140764020();
        DAT_143ab0d58 = 0;
    }
}
MS2_REPLACE(0x1414A2B90, FUN_1414a2b90, 94, 0x7296AF54);
// @0x1414a2bf0
void FUN_1414a2bf0()
{
    if (DAT_143ab0d68 != 0) {
        delete FUN_14109a710();
        DAT_143ab0d68 = 0;
    }
}
MS2_REPLACE(0x1414A2BF0, FUN_1414a2bf0, 94, 0x8971EF9E);
// @0x1414a2c50
void FUN_1414a2c50()
{
    if (DAT_143abf748 != 0) {
        delete FUN_140c9b8e0();
        DAT_143abf748 = 0;
    }
}
MS2_REPLACE(0x1414A2C50, FUN_1414a2c50, 94, 0x0496A4FD);
// @0x1414a2cb0
void FUN_1414a2cb0()
{
    if (DAT_143abf7e8 != 0) {
        delete FUN_140e7c990();
        DAT_143abf7e8 = 0;
    }
}
MS2_REPLACE(0x1414A2CB0, FUN_1414a2cb0, 94, 0xF0CFCCF6);
// @0x1414a2d10
void FUN_1414a2d10()
{
    if (DAT_143ae0760 != 0) {
        delete FUN_1414a5770();
        DAT_143ae0760 = 0;
    }
}
MS2_REPLACE(0x1414A2D10, FUN_1414a2d10, 94, 0x1244F2CA);
// @0x1414a2d70
void FUN_1414a2d70()
{
    if (DAT_143ab0e60 != 0) {
        delete FUN_1414a5780();
        DAT_143ab0e60 = 0;
    }
}
MS2_REPLACE(0x1414A2D70, FUN_1414a2d70, 94, 0x3B1D802E);
// @0x1414a2dd0
void FUN_1414a2dd0()
{
    if (DAT_143ab0e50 != 0) {
        delete FUN_140dc19b0();
        DAT_143ab0e50 = 0;
    }
}
MS2_REPLACE(0x1414A2DD0, FUN_1414a2dd0, 94, 0xEDF53850);
// @0x1414a2e30
void FUN_1414a2e30()
{
    if (DAT_143ab0e68 != 0) {
        delete FUN_14076dcd0();
        DAT_143ab0e68 = 0;
    }
}
MS2_REPLACE(0x1414A2E30, FUN_1414a2e30, 94, 0x8854C121);
// @0x1414a2e90
void FUN_1414a2e90()
{
    if (DAT_143ab8aa0 != 0) {
        delete FUN_140e800e0();
        DAT_143ab8aa0 = 0;
    }
}
MS2_REPLACE(0x1414A2E90, FUN_1414a2e90, 94, 0x32132896);
// @0x1414a2ef0
void FUN_1414a2ef0()
{
    if (DAT_143aaecf0 != 0) {
        delete FUN_1403b4750();
        DAT_143aaecf0 = 0;
    }
}
MS2_REPLACE(0x1414A2EF0, FUN_1414a2ef0, 94, 0x63475792);
// @0x1414a2f50
void FUN_1414a2f50()
{
    if (DAT_143ac48f8 != 0) {
        delete FUN_140f26650();
        DAT_143ac48f8 = 0;
    }
}
MS2_REPLACE(0x1414A2F50, FUN_1414a2f50, 94, 0x23151BB2);
// @0x1414a2fb0
void FUN_1414a2fb0()
{
    if (DAT_143acce38 != 0) {
        delete FUN_141371b30();
        DAT_143acce38 = 0;
    }
}
MS2_REPLACE(0x1414A2FB0, FUN_1414a2fb0, 94, 0xDB010B03);
// @0x1414a3010
void FUN_1414a3010()
{
    if (DAT_143aaef68 != 0) {
        delete FUN_1404f4540();
        DAT_143aaef68 = 0;
    }
}
MS2_REPLACE(0x1414A3010, FUN_1414a3010, 94, 0x7BD2310F);
// @0x1414a3070
void FUN_1414a3070()
{
    if (DAT_143ae0780 != 0) {
        delete FUN_1414a5790();
        DAT_143ae0780 = 0;
    }
}
MS2_REPLACE(0x1414A3070, FUN_1414a3070, 94, 0xAB9DE9C9);
// @0x1414a30d0
void FUN_1414a30d0()
{
    if (DAT_143ab2080 != 0) {
        delete FUN_140a87680();
        DAT_143ab2080 = 0;
    }
}
MS2_REPLACE(0x1414A30D0, FUN_1414a30d0, 94, 0xAD0A4637);
// @0x1414a3130
void FUN_1414a3130()
{
    if (DAT_143ab0470 != 0) {
        delete FUN_1406aa4b0();
        DAT_143ab0470 = 0;
    }
}
MS2_REPLACE(0x1414A3130, FUN_1414a3130, 94, 0x05CC0E62);
// @0x1414a3190
void FUN_1414a3190()
{
    if (DAT_143aaedf0 != 0) {
        delete FUN_1403ed2a0();
        DAT_143aaedf0 = 0;
    }
}
MS2_REPLACE(0x1414A3190, FUN_1414a3190, 94, 0x793C4AFD);
// @0x1414a31f0
void FUN_1414a31f0()
{
    if (DAT_143ac49b8 != 0) {
        delete FUN_1414a57a0();
        DAT_143ac49b8 = 0;
    }
}
MS2_REPLACE(0x1414A31F0, FUN_1414a31f0, 94, 0x444F494A);
// @0x1414a3250
void FUN_1414a3250()
{
    if (DAT_143ab18c8 != 0) {
        delete FUN_1414a57b0();
        DAT_143ab18c8 = 0;
    }
}
MS2_REPLACE(0x1414A3250, FUN_1414a3250, 94, 0x3CBF46EE);
// @0x1414a32b0
void FUN_1414a32b0()
{
    if (DAT_143ac0d40 != 0) {
        delete FUN_140cea070();
        DAT_143ac0d40 = 0;
    }
}
MS2_REPLACE(0x1414A32B0, FUN_1414a32b0, 94, 0xD0C912A5);
// @0x1414a3310
void FUN_1414a3310()
{
    if (DAT_143ab1a28 != 0) {
        delete FUN_140dd7910();
        DAT_143ab1a28 = 0;
    }
}
MS2_REPLACE(0x1414A3310, FUN_1414a3310, 94, 0x57813219);
// @0x1414a3370
void FUN_1414a3370()
{
    if (DAT_143ad8330 != 0) {
        delete FUN_14134e430();
        DAT_143ad8330 = 0;
    }
}
MS2_REPLACE(0x1414A3370, FUN_1414a3370, 94, 0xD98601C2);
// @0x1414a33d0
void FUN_1414a33d0()
{
    if (DAT_143abb018 != 0) {
        delete FUN_140b2e990();
        DAT_143abb018 = 0;
    }
}
MS2_REPLACE(0x1414A33D0, FUN_1414a33d0, 94, 0xD2E6055A);
// @0x1414a3430
void FUN_1414a3430()
{
    if (DAT_143ab1a38 != 0) {
        delete FUN_1414a57c0();
        DAT_143ab1a38 = 0;
    }
}
MS2_REPLACE(0x1414A3430, FUN_1414a3430, 94, 0xF8F04190);
// @0x1414a3490
void FUN_1414a3490()
{
    if (DAT_143ac1928 != 0) {
        delete FUN_140d13c40();
        DAT_143ac1928 = 0;
    }
}
MS2_REPLACE(0x1414A3490, FUN_1414a3490, 94, 0xCD8ED2A6);
// @0x1414a34f0
void FUN_1414a34f0()
{
    if (DAT_143ae07a0 != 0) {
        delete FUN_1414a57d0();
        DAT_143ae07a0 = 0;
    }
}
MS2_REPLACE(0x1414A34F0, FUN_1414a34f0, 94, 0x702DF741);
// @0x1414a3550
void FUN_1414a3550()
{
    if (DAT_143ab1b18 != 0) {
        delete FUN_140976580();
        DAT_143ab1b18 = 0;
    }
}
MS2_REPLACE(0x1414A3550, FUN_1414a3550, 94, 0x371777FF);
// @0x1414a35b0
void FUN_1414a35b0()
{
    if (DAT_143ae0778 != 0) {
        delete FUN_1414a57e0();
        DAT_143ae0778 = 0;
    }
}
MS2_REPLACE(0x1414A35B0, FUN_1414a35b0, 94, 0x44476E8D);
// @0x1414a3610
void FUN_1414a3610()
{
    if (DAT_143aac298 != 0) {
        delete FUN_1401a9d70();
        DAT_143aac298 = 0;
    }
}
MS2_REPLACE(0x1414A3610, FUN_1414a3610, 94, 0x88FFB246);
// @0x1414a3670
void FUN_1414a3670()
{
    if (DAT_143ab1d28 != 0) {
        delete FUN_140ad0da0();
        DAT_143ab1d28 = 0;
    }
}
MS2_REPLACE(0x1414A3670, FUN_1414a3670, 94, 0x4F112A91);
// @0x1414a36d0
void FUN_1414a36d0()
{
    if (DAT_143ab1f30 != 0) {
        delete FUN_1409f24a0();
        DAT_143ab1f30 = 0;
    }
}
MS2_REPLACE(0x1414A36D0, FUN_1414a36d0, 94, 0xABC65B61);
// @0x1414a3730
void FUN_1414a3730()
{
    if (DAT_143ab1fc8 != 0) {
        delete FUN_140933210();
        DAT_143ab1fc8 = 0;
    }
}
MS2_REPLACE(0x1414A3730, FUN_1414a3730, 94, 0xE64E015A);
// @0x1414a3790
void FUN_1414a3790()
{
    if (DAT_143ad9d78 != 0) {
        delete FUN_14140ea30();
        DAT_143ad9d78 = 0;
    }
}
MS2_REPLACE(0x1414A3790, FUN_1414a3790, 94, 0xC59A7510);
// @0x1414a37f0
void FUN_1414a37f0()
{
    if (DAT_143ab1fd0 != 0) {
        delete FUN_140cea080();
        DAT_143ab1fd0 = 0;
    }
}
MS2_REPLACE(0x1414A37F0, FUN_1414a37f0, 94, 0xE084A75C);
// @0x1414a3850
void FUN_1414a3850()
{
    if (DAT_143ab0548 != 0) {
        delete FUN_1406aa4c0();
        DAT_143ab0548 = 0;
    }
}
MS2_REPLACE(0x1414A3850, FUN_1414a3850, 94, 0xF2260634);
// @0x1414a38b0
void FUN_1414a38b0()
{
    if (DAT_143ab4620 != 0) {
        delete FUN_1409eed50();
        DAT_143ab4620 = 0;
    }
}
MS2_REPLACE(0x1414A38B0, FUN_1414a38b0, 94, 0x41A8B8C8);
// @0x1414a3910
void FUN_1414a3910()
{
    if (DAT_143ae0758 != 0) {
        delete FUN_1414a57f0();
        DAT_143ae0758 = 0;
    }
}
MS2_REPLACE(0x1414A3910, FUN_1414a3910, 94, 0xC21544C6);
// @0x1414a3970
void FUN_1414a3970()
{
    if (DAT_143ae0768 != 0) {
        delete FUN_1414a5800();
        DAT_143ae0768 = 0;
    }
}
MS2_REPLACE(0x1414A3970, FUN_1414a3970, 94, 0xDD4A3579);
// @0x1414a39d0
void FUN_1414a39d0()
{
    if (DAT_143ab22a8 != 0) {
        delete FUN_140ec3940();
        DAT_143ab22a8 = 0;
    }
}
MS2_REPLACE(0x1414A39D0, FUN_1414a39d0, 94, 0x78B3D6DC);
// @0x1414a3a30
void FUN_1414a3a30()
{
    if (DAT_143aaf1d8 != 0) {
        delete FUN_14052d220();
        DAT_143aaf1d8 = 0;
    }
}
MS2_REPLACE(0x1414A3A30, FUN_1414a3a30, 94, 0x8581D2D7);
// @0x1414a3a90
void FUN_1414a3a90()
{
    if (DAT_143ad86c8 != 0) {
        delete FUN_14135a4d0();
        DAT_143ad86c8 = 0;
    }
}
MS2_REPLACE(0x1414A3A90, FUN_1414a3a90, 94, 0x43C76F10);
// @0x1414a3af0
void FUN_1414a3af0()
{
    if (DAT_143aaeeb8 != 0) {
        delete FUN_14041beb0();
        DAT_143aaeeb8 = 0;
    }
}
MS2_REPLACE(0x1414A3AF0, FUN_1414a3af0, 94, 0x98C9C077);
// @0x1414a3b50
void FUN_1414a3b50()
{
    if (DAT_143ab4610 != 0) {
        delete FUN_1409eed60();
        DAT_143ab4610 = 0;
    }
}
MS2_REPLACE(0x1414A3B50, FUN_1414a3b50, 94, 0x484FE139);
// @0x1414a3bb0
void FUN_1414a3bb0()
{
    if (DAT_143ab2628 != 0) {
        delete FUN_140fb9980();
        DAT_143ab2628 = 0;
    }
}
MS2_REPLACE(0x1414A3BB0, FUN_1414a3bb0, 94, 0xA273971A);
// @0x1414a3c10
void FUN_1414a3c10()
{
    if (DAT_143ab3700 != 0) {
        delete FUN_1409478c0();
        DAT_143ab3700 = 0;
    }
}
MS2_REPLACE(0x1414A3C10, FUN_1414a3c10, 94, 0x7EC97F36);
// @0x1414a3c70
void FUN_1414a3c70()
{
    if (DAT_143ad6820 != 0) {
        delete FUN_1412976a0();
        DAT_143ad6820 = 0;
    }
}
MS2_REPLACE(0x1414A3C70, FUN_1414a3c70, 94, 0x10A5FB83);
// @0x1414a3cd0
void FUN_1414a3cd0()
{
    if (DAT_143ab0f28 != 0) {
        delete FUN_140789c40();
        DAT_143ab0f28 = 0;
    }
}
MS2_REPLACE(0x1414A3CD0, FUN_1414a3cd0, 94, 0x424E3052);
// @0x1414a3d30
void FUN_1414a3d30()
{
    if (DAT_143aac5c0 != 0) {
        delete FUN_1401d31f0();
        DAT_143aac5c0 = 0;
    }
}
MS2_REPLACE(0x1414A3D30, FUN_1414a3d30, 94, 0x2B2DA0BB);
// @0x1414a3d90
void FUN_1414a3d90()
{
    if (DAT_143aacce8 != 0) {
        delete FUN_14025e7d0();
        DAT_143aacce8 = 0;
    }
}
MS2_REPLACE(0x1414A3D90, FUN_1414a3d90, 94, 0x6EEE7143);
// @0x1414a3df0
void FUN_1414a3df0()
{
    if (DAT_143aac5c8 != 0) {
        delete FUN_1401d3200();
        DAT_143aac5c8 = 0;
    }
}
MS2_REPLACE(0x1414A3DF0, FUN_1414a3df0, 95, 0x2F862E4F);
// @0x1414a3e50
void FUN_1414a3e50()
{
    if (DAT_143ab6718 != 0) {
        delete FUN_1411b1dc0();
        DAT_143ab6718 = 0;
    }
}
MS2_REPLACE(0x1414A3E50, FUN_1414a3e50, 94, 0x3CD3859F);
// @0x1414a3eb0
void FUN_1414a3eb0()
{
    if (DAT_143aaf318 != 0) {
        delete FUN_140b1db00();
        DAT_143aaf318 = 0;
    }
}
MS2_REPLACE(0x1414A3EB0, FUN_1414a3eb0, 94, 0x994256D1);
// @0x1414a3f10
void FUN_1414a3f10()
{
    if (DAT_143ab6730 != 0) {
        delete FUN_140a44830();
        DAT_143ab6730 = 0;
    }
}
MS2_REPLACE(0x1414A3F10, FUN_1414a3f10, 94, 0xF19B752C);
// @0x1414a3f70
void FUN_1414a3f70()
{
    if (DAT_143ac90f0 != 0) {
        delete FUN_140ef0b20();
        DAT_143ac90f0 = 0;
    }
}
MS2_REPLACE(0x1414A3F70, FUN_1414a3f70, 94, 0x128A9E27);
// @0x1414a3fd0
void FUN_1414a3fd0()
{
    if (DAT_143aad1f0 != 0) {
        delete FUN_140b20590();
        DAT_143aad1f0 = 0;
    }
}
MS2_REPLACE(0x1414A3FD0, FUN_1414a3fd0, 94, 0xBC1EF21F);
// @0x1414a4030
void FUN_1414a4030()
{
    if (DAT_143aad1f8 != 0) {
        delete FUN_14031c2a0();
        DAT_143aad1f8 = 0;
    }
}
MS2_REPLACE(0x1414A4030, FUN_1414a4030, 94, 0xF4AA19C6);
// @0x1414a4090
void FUN_1414a4090()
{
    if (DAT_143ad1580 != 0) {
        delete FUN_1411b1dd0();
        DAT_143ad1580 = 0;
    }
}
MS2_REPLACE(0x1414A4090, FUN_1414a4090, 94, 0x4134B3DD);
// @0x1414a40f0
void FUN_1414a40f0()
{
    if (DAT_143ad1578 != 0) {
        delete FUN_14119f490();
        DAT_143ad1578 = 0;
    }
}
MS2_REPLACE(0x1414A40F0, FUN_1414a40f0, 94, 0x9787CD5A);
// @0x1414a4150
void FUN_1414a4150()
{
    if (DAT_143ae0750 != 0) {
        delete FUN_1414a5810();
        DAT_143ae0750 = 0;
    }
}
MS2_REPLACE(0x1414A4150, FUN_1414a4150, 94, 0xF9201881);
// @0x1414a41b0
void FUN_1414a41b0()
{
    if (DAT_143aaec50 != 0) {
        delete FUN_1414a5820();
        DAT_143aaec50 = 0;
    }
}
MS2_REPLACE(0x1414A41B0, FUN_1414a41b0, 94, 0x37405945);
// @0x1414a4210
void FUN_1414a4210()
{
    if (DAT_143ad5158 != 0) {
        delete FUN_141245b20();
        DAT_143ad5158 = 0;
    }
}
MS2_REPLACE(0x1414A4210, FUN_1414a4210, 94, 0xAA0F2CF3);
// @0x1414a4270
void FUN_1414a4270()
{
    if (DAT_143aaecf8 != 0) {
        delete FUN_140541580();
        DAT_143aaecf8 = 0;
    }
}
MS2_REPLACE(0x1414A4270, FUN_1414a4270, 94, 0xC6F92785);
// @0x1414a42d0
void FUN_1414a42d0()
{
    if (DAT_143aab380 != 0) {
        delete FUN_14015a050();
        DAT_143aab380 = 0;
    }
}
MS2_REPLACE(0x1414A42D0, FUN_1414a42d0, 94, 0xFCAB6435);
// @0x1414a4330
void FUN_1414a4330()
{
    if (DAT_143ab3338 != 0) {
        delete FUN_140933220();
        DAT_143ab3338 = 0;
    }
}
MS2_REPLACE(0x1414A4330, FUN_1414a4330, 94, 0x0EB0AC8E);
// @0x1414a4390
void FUN_1414a4390()
{
    if (DAT_143ab67d8 != 0) {
        delete FUN_1414a5830();
        DAT_143ab67d8 = 0;
    }
}
MS2_REPLACE(0x1414A4390, FUN_1414a4390, 94, 0x33E83678);
// @0x1414a43f0
void FUN_1414a43f0()
{
    if (DAT_143aad170 != 0) {
        delete FUN_1405a1fd0();
        DAT_143aad170 = 0;
    }
}
MS2_REPLACE(0x1414A43F0, FUN_1414a43f0, 94, 0x0E6BA856);
// @0x1414a4450
void FUN_1414a4450()
{
    if (DAT_143aaf1d0 != 0) {
        delete FUN_14052d230();
        DAT_143aaf1d0 = 0;
    }
}
MS2_REPLACE(0x1414A4450, FUN_1414a4450, 94, 0x87DBB161);
// @0x1414a44b0
void FUN_1414a44b0()
{
    if (DAT_143ab3fc0 != 0) {
        delete FUN_1409bb9e0();
        DAT_143ab3fc0 = 0;
    }
}
MS2_REPLACE(0x1414A44B0, FUN_1414a44b0, 94, 0x23986293);
// @0x1414a4510
void FUN_1414a4510()
{
    if (DAT_143aac638 != 0) {
        delete FUN_1401d7a50();
        DAT_143aac638 = 0;
    }
}
MS2_REPLACE(0x1414A4510, FUN_1414a4510, 94, 0x879E4000);
// @0x1414a4570
void FUN_1414a4570()
{
    if (DAT_143ab8308 != 0) {
        delete FUN_1414a5840();
        DAT_143ab8308 = 0;
    }
}
MS2_REPLACE(0x1414A4570, FUN_1414a4570, 94, 0x6819E981);
// @0x1414a45d0
void FUN_1414a45d0()
{
    if (DAT_143ab0468 != 0) {
        delete FUN_1406c7610();
        DAT_143ab0468 = 0;
    }
}
MS2_REPLACE(0x1414A45D0, FUN_1414a45d0, 94, 0xF6EDF752);
// @0x1414a4630
void FUN_1414a4630()
{
    if (DAT_143ac3d20 != 0) {
        delete FUN_1414a5850();
        DAT_143ac3d20 = 0;
    }
}
MS2_REPLACE(0x1414A4630, FUN_1414a4630, 94, 0x30110431);
// @0x1414a4690
void FUN_1414a4690()
{
    if (DAT_143ab34d8 != 0) {
        delete FUN_140939a10();
        DAT_143ab34d8 = 0;
    }
}
MS2_REPLACE(0x1414A4690, FUN_1414a4690, 94, 0xF88364D7);
// @0x1414a46f0
void FUN_1414a46f0()
{
    if (DAT_143ab06f0 != 0) {
        delete FUN_1406d6e90();
        DAT_143ab06f0 = 0;
    }
}
MS2_REPLACE(0x1414A46F0, FUN_1414a46f0, 94, 0x6E73979E);
// @0x1414a4750
void FUN_1414a4750()
{
    if (DAT_143ab47a0 != 0) {
        delete FUN_1409f24b0();
        DAT_143ab47a0 = 0;
    }
}
MS2_REPLACE(0x1414A4750, FUN_1414a4750, 94, 0x40A420CD);
// @0x1414a47b0
void FUN_1414a47b0()
{
    if (DAT_143ab3708 != 0) {
        delete FUN_1414a5860();
        DAT_143ab3708 = 0;
    }
}
MS2_REPLACE(0x1414A47B0, FUN_1414a47b0, 94, 0x1C74740E);
// @0x1414a4810
void FUN_1414a4810()
{
    if (DAT_143abd630 != 0) {
        delete FUN_140bccd50();
        DAT_143abd630 = 0;
    }
}
MS2_REPLACE(0x1414A4810, FUN_1414a4810, 94, 0x6F65BAF4);
// @0x1414a4870
void FUN_1414a4870()
{
    if (DAT_143ab4150 != 0) {
        delete FUN_1409c1740();
        DAT_143ab4150 = 0;
    }
}
MS2_REPLACE(0x1414A4870, FUN_1414a4870, 94, 0x655019B1);
// @0x1414a48d0
void FUN_1414a48d0()
{
    if (DAT_143ab0ac8 != 0) {
        delete FUN_14071d7d0();
        DAT_143ab0ac8 = 0;
    }
}
MS2_REPLACE(0x1414A48D0, FUN_1414a48d0, 94, 0xF13FF98B);
// @0x1414a4930
void FUN_1414a4930()
{
    if (DAT_143ab0c70 != 0) {
        delete FUN_1407476c0();
        DAT_143ab0c70 = 0;
    }
}
MS2_REPLACE(0x1414A4930, FUN_1414a4930, 94, 0xD3DA3822);
// @0x1414a4990
void FUN_1414a4990()
{
    if (DAT_143abf888 != 0) {
        delete FUN_140c9cb20();
        DAT_143abf888 = 0;
    }
}
MS2_REPLACE(0x1414A4990, FUN_1414a4990, 94, 0xFE51A354);
// @0x1414a49f0
void FUN_1414a49f0()
{
    if (DAT_143ab0d60 != 0) {
        delete FUN_140764030();
        DAT_143ab0d60 = 0;
    }
}
MS2_REPLACE(0x1414A49F0, FUN_1414a49f0, 94, 0x331AAB1F);
// @0x1414a4a50
void FUN_1414a4a50()
{
    if (DAT_143ab0f68 != 0) {
        delete FUN_1407b75e0();
        DAT_143ab0f68 = 0;
    }
}
MS2_REPLACE(0x1414A4A50, FUN_1414a4a50, 94, 0xD90BC029);
// @0x1414a4ab0
// MS2-FUNCTIONAL: exe takes the null check before adjusting to the sub-object and loads the vtable from the unadjusted pointer; no source form found (118 vs 117 bytes)
void FUN_1414a4ab0()
{
    if (DAT_143aac288 != 0) {
        delete &FUN_1401958b0()->m_sub;
        DAT_143aac288 = 0;
    }
}
MS2_REPLACE(0x1414A4AB0, FUN_1414a4ab0, 117, 0x313028D3);
// @0x1414a4b30
void FUN_1414a4b30()
{
    if (DAT_143ad1ac8 != 0) {
        delete FUN_1411b1de0();
        DAT_143ad1ac8 = 0;
    }
}
MS2_REPLACE(0x1414A4B30, FUN_1414a4b30, 94, 0x0CBBBA6A);
// @0x1414a4b90
void FUN_1414a4b90()
{
    if (DAT_143aac270 != 0) {
        delete FUN_140186320();
        DAT_143aac270 = 0;
    }
}
MS2_REPLACE(0x1414A4B90, FUN_1414a4b90, 94, 0x490821D4);
// @0x1414a4bf0
void FUN_1414a4bf0()
{
    if (DAT_143abf898 != 0) {
        delete FUN_1414a5870();
        DAT_143abf898 = 0;
    }
}
MS2_REPLACE(0x1414A4BF0, FUN_1414a4bf0, 94, 0x5A4F6B43);
// @0x1414a4c50
void FUN_1414a4c50()
{
    if (DAT_143ab1c98 != 0) {
        delete FUN_141025b70();
        DAT_143ab1c98 = 0;
    }
}
MS2_REPLACE(0x1414A4C50, FUN_1414a4c50, 94, 0xDB996F1C);
// @0x1414a4cb0
void FUN_1414a4cb0()
{
    if (DAT_143ab4630 != 0) {
        delete FUN_1409eed70();
        DAT_143ab4630 = 0;
    }
}
MS2_REPLACE(0x1414A4CB0, FUN_1414a4cb0, 94, 0x1D473DD0);
// @0x1414a4d10
void FUN_1414a4d10()
{
    if (DAT_143ab2128 != 0) {
        delete FUN_1409eed80();
        DAT_143ab2128 = 0;
    }
}
MS2_REPLACE(0x1414A4D10, FUN_1414a4d10, 94, 0x18FFC21F);
// @0x1414a4d70
void FUN_1414a4d70()
{
    if (DAT_143abd628 != 0) {
        delete FUN_140c24ef0();
        DAT_143abd628 = 0;
    }
}
MS2_REPLACE(0x1414A4D70, FUN_1414a4d70, 94, 0xDE9241E5);
// @0x1414a4dd0
void FUN_1414a4dd0()
{
    if (DAT_143ab6878 != 0) {
        delete FUN_140a4a7b0();
        DAT_143ab6878 = 0;
    }
}
MS2_REPLACE(0x1414A4DD0, FUN_1414a4dd0, 94, 0x709ABCE7);
// @0x1414a4e30
void FUN_1414a4e30()
{
    if (DAT_143ad9d70 != 0) {
        delete FUN_14140ea40();
        DAT_143ad9d70 = 0;
    }
}
MS2_REPLACE(0x1414A4E30, FUN_1414a4e30, 94, 0xCEEF069C);
// @0x1414a4e90
void FUN_1414a4e90()
{
    if (DAT_143abdfe8 != 0) {
        delete FUN_140c0e750();
        DAT_143abdfe8 = 0;
    }
}
MS2_REPLACE(0x1414A4E90, FUN_1414a4e90, 94, 0x626BFA13);
// @0x1414a4ef0
void FUN_1414a4ef0()
{
    if (DAT_143abf028 != 0) {
        delete FUN_140c607b0();
        DAT_143abf028 = 0;
    }
}
MS2_REPLACE(0x1414A4EF0, FUN_1414a4ef0, 94, 0x2D1FF1F4);
// @0x1414a4f50
void FUN_1414a4f50()
{
    if (DAT_143ab7908 != 0) {
        delete FUN_140a6a840();
        DAT_143ab7908 = 0;
    }
}
MS2_REPLACE(0x1414A4F50, FUN_1414a4f50, 94, 0x00A4DD0C);
// @0x1414a4fb0
void FUN_1414a4fb0()
{
    if (DAT_143abdd70 != 0) {
        delete FUN_140bfc4b0();
        DAT_143abdd70 = 0;
    }
}
MS2_REPLACE(0x1414A4FB0, FUN_1414a4fb0, 94, 0xF3966947);
// @0x1414a5010
void FUN_1414a5010()
{
    if (DAT_143ab3340 != 0) {
        delete FUN_140933230();
        DAT_143ab3340 = 0;
    }
}
MS2_REPLACE(0x1414A5010, FUN_1414a5010, 94, 0x51DCA32B);
// @0x1414a5070
void FUN_1414a5070()
{
    if (DAT_143ab89f0 != 0) {
        delete FUN_140aa6d40();
        DAT_143ab89f0 = 0;
    }
}
MS2_REPLACE(0x1414A5070, FUN_1414a5070, 94, 0x1C7FB274);
// @0x1414a50d0
void FUN_1414a50d0()
{
    if (DAT_143ab3900 != 0) {
        delete FUN_140967100();
        DAT_143ab3900 = 0;
    }
}
MS2_REPLACE(0x1414A50D0, FUN_1414a50d0, 94, 0xDBE27E7F);
// @0x1414a5130
void FUN_1414a5130()
{
    if (DAT_143abd548 != 0) {
        delete FUN_140bc09f0();
        DAT_143abd548 = 0;
    }
}
MS2_REPLACE(0x1414A5130, FUN_1414a5130, 94, 0xAFBAF998);
// @0x1414a5190
void FUN_1414a5190()
{
    if (DAT_143ac8008 != 0) {
        delete FUN_140e898d0();
        DAT_143ac8008 = 0;
    }
}
MS2_REPLACE(0x1414A5190, FUN_1414a5190, 94, 0xE9B3A445);
// @0x1414a51f0
void FUN_1414a51f0()
{
    if (DAT_143abb148 != 0) {
        delete FUN_140b6a040();
        DAT_143abb148 = 0;
    }
}
MS2_REPLACE(0x1414A51F0, FUN_1414a51f0, 94, 0x993BA5D3);
// @0x1414a5250
// MS2-FUNCTIONAL: exe takes the null check before adjusting to the sub-object and loads the vtable from the unadjusted pointer; no source form found (118 vs 117 bytes)
void FUN_1414a5250()
{
    if (DAT_143ae07a8 != 0) {
        delete &FUN_1414a5880()->m_sub;
        DAT_143ae07a8 = 0;
    }
}
MS2_REPLACE(0x1414A5250, FUN_1414a5250, 117, 0x4F2219E0);
// @0x1414a52d0
void FUN_1414a52d0()
{
    if (DAT_143ab26c8 != 0) {
        delete FUN_140ac74e0();
        DAT_143ab26c8 = 0;
    }
}
MS2_REPLACE(0x1414A52D0, FUN_1414a52d0, 94, 0x2D0FCE7F);
// @0x1414a5330
void FUN_1414a5330()
{
    if (DAT_143ab4628 != 0) {
        delete FUN_1409eed90();
        DAT_143ab4628 = 0;
    }
}
MS2_REPLACE(0x1414A5330, FUN_1414a5330, 94, 0xCF0DEAAA);
// @0x1414a5390
void FUN_1414a5390()
{
    if (DAT_143ab26c0 != 0) {
        delete FUN_1409023c0();
        DAT_143ab26c0 = 0;
    }
}
MS2_REPLACE(0x1414A5390, FUN_1414a5390, 94, 0x0ED93E76);
// @0x1414a53f0
void FUN_1414a53f0()
{
    if (DAT_143abfb18 != 0) {
        delete FUN_140cb17d0();
        DAT_143abfb18 = 0;
    }
}
MS2_REPLACE(0x1414A53F0, FUN_1414a53f0, 94, 0xAE08E5EE);
// @0x1414a5450
void Unk_HashMap1::FUN_1414a5450() { m_nLockCount++; }
// @0x1414a5470
void Unk_HashMap2::FUN_1414a5470() { m_nLockCount++; }
// @0x1414a5490
void Unk_HashMap3::FUN_1414a5490() { m_nLockCount++; }
// @0x1414a54b0
void Unk_HashMap4::FUN_1414a54b0() { m_nLockCount++; }
// @0x1414a54d0
void Unk_HashMap5::FUN_1414a54d0() { m_nLockCount++; }
// @0x1414a54f0
void* FUN_1414a54f0(char* self)
{
    char* p = (char*)operator new(0x10);
    void* r;
    if (p != 0)
        r = FUN_1414a54f0_ctor(p, self);
    else
        r = 0;
    return r;
}
// @0x1414a5540
void Unk_HashMap1::FUN_1414a5540() { do { } while (0); m_nLockCount--; }
// @0x1414a5560
void Unk_HashMap2::FUN_1414a5560() { do { } while (0); m_nLockCount--; }
// @0x1414a5580
void Unk_HashMap3::FUN_1414a5580() { do { } while (0); m_nLockCount--; }
// @0x1414a55a0
void Unk_HashMap4::FUN_1414a55a0() { do { } while (0); m_nLockCount--; }
// @0x1414a55c0
void Unk_HashMap5::FUN_1414a55c0() { do { } while (0); m_nLockCount--; }
// @0x1414a55e0
unsigned long long Unk_MiscThis::FUN_1414a55e0() { return 0; }
// @0x1414a55f0
unsigned long long Unk_MiscThis::FUN_1414a55f0() { return 5000; }
// @0x1414a5600
unsigned long long Unk_MiscThis::FUN_1414a5600() { return 0; }
// @0x1414a5610
void FUN_1414a5610(char* pThis, char* pDst) { memcpy(pDst, pThis + 0x60, 0x10); }
MS2_REPLACE(0x1414A5610, FUN_1414a5610, 36, 0x8905C4F3);
// @0x1414a5640
void* Unk_MiscThis::FUN_1414a5640() { return &DAT_143ae0130; }
// @0x1414a5650
int* Unk_MiscThis::FUN_1414a5650() { return &DAT_143a01f90; }
// @0x1414a5660
int* Unk_MiscThis::FUN_1414a5660() { return &DAT_143a284b0; }
// @0x1414a5670
int FUN_1414a5670(Unk_ShutdownValue30* pThis) { return pThis->m_value; }
MS2_REPLACE(0x1414A5670, FUN_1414a5670, 14, 0x828204CF);
// @0x1414a5680
const char* Unk_MiscThis::FUN_1414a5680() { return "MS2PropertyVisualizationService"; }
// @0x1414a5690
int FUN_1414a5690(CFileSystem* pThis) { return pThis->archiveMode; }
MS2_REPLACE(0x1414A5690, FUN_1414a5690, 17, 0x05FDCC0A);
// @0x1414a56b0
int FUN_1414a56b0(char* pThis) { return *(int*)(pThis + 8); }
MS2_REPLACE(0x1414A56B0, FUN_1414a56b0, 14, 0x92BE4827);
// @0x1414a56c0
Unk_SingletonObj* FUN_1414a56c0() { return DAT_143ae0748; }
MS2_REPLACE(0x1414A56C0, FUN_1414a56c0, 8, 0x088FC0A0);
// @0x1414a56d0
Unk_SingletonObj* FUN_1414a56d0() { return DAT_143aad288; }
MS2_REPLACE(0x1414A56D0, FUN_1414a56d0, 8, 0x102F39C2);
// @0x1414a56e0
Unk_SingletonObj* FUN_1414a56e0() { return DAT_143ab0198; }
MS2_REPLACE(0x1414A56E0, FUN_1414a56e0, 8, 0x6F63F71B);
// @0x1414a56f0
Unk_SingletonObj* FUN_1414a56f0() { return DAT_143ae0798; }
MS2_REPLACE(0x1414A56F0, FUN_1414a56f0, 8, 0x42AB2040);
// @0x1414a5700
Unk_SingletonObj* FUN_1414a5700() { return DAT_143ac2b20; }
MS2_REPLACE(0x1414A5700, FUN_1414a5700, 8, 0x70220B8A);
// @0x1414a5710
Unk_SingletonObj* FUN_1414a5710() { return DAT_143abb830; }
MS2_REPLACE(0x1414A5710, FUN_1414a5710, 8, 0xEDD70F33);
// @0x1414a5720
Unk_SingletonObj* FUN_1414a5720() { return DAT_143ae0788; }
MS2_REPLACE(0x1414A5720, FUN_1414a5720, 8, 0xA57EC080);
// @0x1414a5730
Unk_SingletonObj* FUN_1414a5730() { return DAT_143ab8808; }
MS2_REPLACE(0x1414A5730, FUN_1414a5730, 8, 0x5647EF76);
// @0x1414a5740
Unk_SingletonObj* FUN_1414a5740() { return DAT_143ae0770; }
MS2_REPLACE(0x1414A5740, FUN_1414a5740, 8, 0x586410F8);
// @0x1414a5750
Unk_SingletonObj* FUN_1414a5750() { return DAT_143ae0790; }
MS2_REPLACE(0x1414A5750, FUN_1414a5750, 8, 0x1B5AC088);
// @0x1414a5760
Unk_SingletonObj* FUN_1414a5760() { return DAT_143ab0bd8; }
MS2_REPLACE(0x1414A5760, FUN_1414a5760, 8, 0xF2F59F09);
// @0x1414a5770
Unk_SingletonObj* FUN_1414a5770() { return DAT_143ae0760; }
MS2_REPLACE(0x1414A5770, FUN_1414a5770, 8, 0xE29D831F);
// @0x1414a5780
Unk_SingletonObj* FUN_1414a5780() { return DAT_143ab0e60; }
MS2_REPLACE(0x1414A5780, FUN_1414a5780, 8, 0x640A1A97);
// @0x1414a5790
Unk_SingletonObj* FUN_1414a5790() { return DAT_143ae0780; }
MS2_REPLACE(0x1414A5790, FUN_1414a5790, 8, 0xE29D831F);
// @0x1414a57a0
Unk_SingletonObj* FUN_1414a57a0() { return DAT_143ac49b8; }
MS2_REPLACE(0x1414A57A0, FUN_1414a57a0, 8, 0xCB0CBDA4);
// @0x1414a57b0
Unk_SingletonObj* FUN_1414a57b0() { return DAT_143ab18c8; }
MS2_REPLACE(0x1414A57B0, FUN_1414a57b0, 8, 0x119CF53C);
// @0x1414a57c0
Unk_SingletonObj* FUN_1414a57c0() { return DAT_143ab1a38; }
MS2_REPLACE(0x1414A57C0, FUN_1414a57c0, 8, 0xF5F7CA73);
// @0x1414a57d0
Unk_SingletonObj* FUN_1414a57d0() { return DAT_143ae07a0; }
MS2_REPLACE(0x1414A57D0, FUN_1414a57d0, 8, 0xC1CED87F);
// @0x1414a57e0
Unk_SingletonObj* FUN_1414a57e0() { return DAT_143ae0778; }
MS2_REPLACE(0x1414A57E0, FUN_1414a57e0, 8, 0xFE969267);
// @0x1414a57f0
Unk_SingletonObj* FUN_1414a57f0() { return DAT_143ae0758; }
MS2_REPLACE(0x1414A57F0, FUN_1414a57f0, 8, 0xAF7A7FD7);
// @0x1414a5800
Unk_SingletonObj* FUN_1414a5800() { return DAT_143ae0768; }
MS2_REPLACE(0x1414A5800, FUN_1414a5800, 8, 0xAF7A7FD7);
// @0x1414a5810
Unk_SingletonObj* FUN_1414a5810() { return DAT_143ae0750; }
MS2_REPLACE(0x1414A5810, FUN_1414a5810, 8, 0x5C402B0F);
// @0x1414a5820
Unk_SingletonObj* FUN_1414a5820() { return DAT_143aaec50; }
MS2_REPLACE(0x1414A5820, FUN_1414a5820, 8, 0xE2227D11);
// @0x1414a5830
Unk_SingletonObj* FUN_1414a5830() { return DAT_143ab67d8; }
MS2_REPLACE(0x1414A5830, FUN_1414a5830, 8, 0x8BBF69B5);
// @0x1414a5840
Unk_SingletonObj* FUN_1414a5840() { return DAT_143ab8308; }
MS2_REPLACE(0x1414A5840, FUN_1414a5840, 8, 0x7852BC4C);
// @0x1414a5850
Unk_SingletonObj* FUN_1414a5850() { return DAT_143ac3d20; }
MS2_REPLACE(0x1414A5850, FUN_1414a5850, 8, 0xBF92926A);
// @0x1414a5860
Unk_SingletonObj* FUN_1414a5860() { return DAT_143ab3708; }
MS2_REPLACE(0x1414A5860, FUN_1414a5860, 8, 0xD92FE2D7);
// @0x1414a5870
Unk_SingletonObj* FUN_1414a5870() { return DAT_143abf898; }
MS2_REPLACE(0x1414A5870, FUN_1414a5870, 8, 0x3EFF4636);
// @0x1414a5880
Unk_SingletonObj80* FUN_1414a5880() { return DAT_143ae07a8; }
MS2_REPLACE(0x1414A5880, FUN_1414a5880, 8, 0x2543A217);
// @0x1414a5890
Unk_SingletonObj* FUN_1414a5890() { return DAT_143b05988; }
MS2_REPLACE(0x1414A5890, FUN_1414a5890, 8, 0xC6930D6B);
// @0x1414a58a0
void FUN_1414a58a0(char* pThis) { FUN_1409a8120(pThis + 0x10); }
MS2_REPLACE(0x1414A58A0, FUN_1414a58a0, 31, 0x5650D8A9);
// @0x1414a58c0
CResultObj FUN_1414a58c0(int idx)
{
    return CResultObj(DAT_143afa980 + 0x170 + (long long)idx * 8);
}
// @0x1414a5910
int FUN_1414a5910(char* pThis) { return *(int*)(pThis + 100); }
MS2_REPLACE(0x1414A5910, FUN_1414a5910, 14, 0xB9C4E423);
// @0x1414a5920
void FUN_1414a5920(char* pThis) { FUN_1409f2d50(pThis + 0x20); }
MS2_REPLACE(0x1414A5920, FUN_1414a5920, 31, 0xF886CB09);
// @0x1414a5940
void FUN_1414a5940(char* pThis) { FUN_1409f2d50(pThis + 0x18); }
MS2_REPLACE(0x1414A5940, FUN_1414a5940, 31, 0x888D3262);
// @0x1414a5960
void FUN_1414a5960(char* pThis) { FUN_1409f2d50(pThis + 0x18); }
MS2_REPLACE(0x1414A5960, FUN_1414a5960, 31, 0x24583782);
// @0x1414a5980
void FUN_1414a5980(char* pThis) { FUN_140c8f690(pThis + 0x28); }
MS2_REPLACE(0x1414A5980, FUN_1414a5980, 31, 0xEFCBF263);
// @0x1414a59a0
void* FUN_1414a59a0(char* pThis) { return FUN_141427740(pThis + 0x118); }
MS2_REPLACE(0x1414A59A0, FUN_1414a59a0, 33, 0x0033409D);
// @0x1414a59d0
void FUN_1414a59d0(char* pThis) { FUN_1409f2d60(pThis + 0x20); }
MS2_REPLACE(0x1414A59D0, FUN_1414a59d0, 31, 0x1941A24A);
// @0x1414a59f0
void FUN_1414a59f0(char* pThis) { FUN_1409f2d60(pThis + 0x18); }
MS2_REPLACE(0x1414A59F0, FUN_1414a59f0, 31, 0x4A3FA102);
// @0x1414a5a10
void FUN_1414a5a10(char* pThis) { FUN_1409f2d60(pThis + 0x18); }
MS2_REPLACE(0x1414A5A10, FUN_1414a5a10, 31, 0x09A43922);
// @0x1414a5a30
int Unk_MiscThis::FUN_1414a5a30() { return DAT_143ae2b48; }
// @0x1414a5a40
int FUN_1414a5a40(CStringW sPath) { return _wmkdir(sPath); }
// @0x1414a5a80
void FUN_1414a5a80(HANDLE* pThis)
{
    if (*pThis != 0)
        CloseHandle(*pThis);
    *pThis = 0;
    *(int*)(pThis + 1) = 0;
}
MS2_REPLACE(0x1414A5A80, FUN_1414a5a80, 63, 0x35494406);
// @0x1414a5ac0
void Unk_HashMap1::FUN_1414a5ac0()
{
    FUN_1414a5450();
    if (m_ppBins != 0) {
        for (unsigned int iBin = 0; iBin < m_nBins; iBin++) {
            Unk_ShutdownNode18* pNode = (Unk_ShutdownNode18*)m_ppBins[iBin];
            while (pNode != 0) {
                Unk_ShutdownNode18* pKill = pNode;
                pNode = pNode->m_next;
                FUN_14076d7d0(pKill);
            }
        }
    }
    delete[] m_ppBins;
    m_ppBins = 0;
    m_nElements = 0;
    if (!FUN_14076e320()) {
        FUN_14076e0e0(FUN_14076ea00(m_nElements), 0);
    }
    FUN_14076d9d0();
    FUN_1414a5540();
}
// @0x1414a5bd0
void Unk_HashMap2::FUN_1414a5bd0()
{
    FUN_1414a5470();
    if (m_ppBins != 0) {
        for (unsigned int iBin = 0; iBin < m_nBins; iBin++) {
            Unk_ShutdownNode18* pNode = (Unk_ShutdownNode18*)m_ppBins[iBin];
            while (pNode != 0) {
                Unk_ShutdownNode18* pKill = pNode;
                pNode = pNode->m_next;
                FUN_14076d8d0(pKill);
            }
        }
    }
    delete[] m_ppBins;
    m_ppBins = 0;
    m_nElements = 0;
    if (!FUN_14076e350()) {
        FUN_14076e200(FUN_14076eaf0(m_nElements), 0);
    }
    FUN_14076da20();
    FUN_1414a5560();
}
// @0x1414a5ce0
void Unk_HashMap3::FUN_1414a5ce0()
{
    FUN_1414a5490();
    if (m_ppBins != 0) {
        for (unsigned int iBin = 0; iBin < m_nBins; iBin++) {
            Unk_ShutdownNode18* pNode = (Unk_ShutdownNode18*)m_ppBins[iBin];
            while (pNode != 0) {
                Unk_ShutdownNode18* pKill = pNode;
                pNode = pNode->m_next;
                FUN_1401a9940(pKill);
            }
        }
    }
    delete[] m_ppBins;
    m_ppBins = 0;
    m_nElements = 0;
    if (!FUN_1401aa520()) {
        FUN_1401aa190(FUN_1401aae10(m_nElements), 0);
    }
    FUN_1401a9c40();
    FUN_1414a5580();
}
// @0x1414a5df0
void Unk_HashMap4::FUN_1414a5df0()
{
    FUN_1414a54b0();
    if (m_ppBins != 0) {
        for (unsigned int iBin = 0; iBin < m_nBins; iBin++) {
            Unk_ShutdownNode20* pNode = (Unk_ShutdownNode20*)m_ppBins[iBin];
            while (pNode != 0) {
                Unk_ShutdownNode20* pKill = pNode;
                pNode = pNode->m_next;
                FUN_1401a9a40(pKill);
            }
        }
    }
    delete[] m_ppBins;
    m_ppBins = 0;
    m_nElements = 0;
    if (!FUN_1401aa550()) {
        FUN_1401aa2b0(FUN_1401aaf00(m_nElements), 0);
    }
    FUN_1401a9c90();
    FUN_1414a55a0();
}
// @0x1414a5f00
void Unk_HashMap5::FUN_1414a5f00()
{
    FUN_1414a54d0();
    if (m_ppBins != 0) {
        for (unsigned int iBin = 0; iBin < m_nBins; iBin++) {
            Unk_ShutdownNode20* pNode = (Unk_ShutdownNode20*)m_ppBins[iBin];
            while (pNode != 0) {
                Unk_ShutdownNode20* pKill = pNode;
                pNode = pNode->m_next;
                FUN_1401a9b40(pKill);
            }
        }
    }
    delete[] m_ppBins;
    m_ppBins = 0;
    m_nElements = 0;
    if (!FUN_1401aa580()) {
        FUN_1401aa3d0(FUN_1401aaff0(m_nElements), 0);
    }
    FUN_1401a9ce0();
    FUN_1414a55c0();
}
