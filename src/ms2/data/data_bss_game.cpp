// Data unit (sfr22; groups 143aab428, 143ab0560, 143ab5b00, 143ab7800, 143ab9510, 143abb058, 143abdc30, 143abf510, 143ac1928, 143ac2bd0, 143ac5988, 143acdb20, 143acf820, 143ad1b20, 143ad76a8, 143adc208, 143ae95e0, 143aedab0, 143aef240, 143af1bc8, 143af37a0, 143af6008, 143af7d40, 143afa350, 143afe6f8, 143b023c0, 143b03490, 143b08a3c, 143b0d2d8, 143b15f78, 143ba9d08, 143d6eab8, 143e64b00 of work/sfr35/outside-units.tsv):
// exe globals of the .bss blocks below that no recovered TU defines (zero: the exe's raw .data ends at 0x143aab400).
// One definition per exe address (tools/datacheck.py checks address, size and initializer); the other names
// users declare at an address are mapped to it with /alternatename. Class objects are byte images up to the
// next known exe global; their constructors (the owning TU's .text$di initializer) are not run by this unit,
// see the zero-blob list in work/sfr22/outside-summary.md. A recovered owner moves a definition to its TU.
// The 39 constructed objects of these blocks (CString statics, CAtlList/CAtlMap, QuestMask, the dialogs, ...) are
// defined by their owners as DAT_<va> now, with their dynamic initializers (work/sfr22/fullexe-staticctors.md);
// 0x143afbfb8 is Gamebryo's NiPSParticleSystem::ms_RTTI. Users' other names reach them via tools/fullexe/alias.py.
// Gamebryo/efd/CRT statics that were zero-blobbed here (NiRTTIs, NiViewRenderClick/NiFogProperty defaults,
// egf::g_bapiContext, _OptionsStorage, ...) were dropped: their GB/CRT definition owns the address (symbols rows),
// and the blob would have shadowed it (sfr36, work/sfr36/fullexe-gamedata.md).
// 0x143d6eab8 is NiDX9Renderer::ms_pkDefaultVisibleArray (alias-manual.tsv): MS2Renderer::Do_RenderMesh read a
// zero copy here that GB's _SDMInit never set.
// 0x143b09498/0x143b094a0 are AnimationService.cpp's g_pfnMS2SceneGraphCacheFilter/g_pfnMS2CreateKFMCache
// (alias-manual.tsv): the game's setters wrote zero copies here that AnimationService never read.
// The hook DLL binds every name to the exe's own global (symbols table), so nothing here is compiled into it
// (docs/RECOVERY.md sec. 9).
// MS2-UNIT: data_bss_game
// MS2-RANGE: 0x143aab428-0x143aaf1d8 .bss
// MS2-RANGE: 0x143ab0560-0x143ab0564 .bss
// MS2-RANGE: 0x143ab5b00-0x143ab6730 .bss
// MS2-RANGE: 0x143ab7800-0x143ab7908 .bss
// MS2-RANGE: 0x143ab9510-0x143ab9658 .bss
// MS2-RANGE: 0x143abb058-0x143abb094 .bss
// MS2-RANGE: 0x143abdc30-0x143abdf54 .bss
// MS2-RANGE: 0x143abf510-0x143abf898 .bss
// MS2-RANGE: 0x143ac1928-0x143ac1b80 .bss
// MS2-RANGE: 0x143ac2bd0-0x143ac47cc .bss
// MS2-RANGE: 0x143ac5988-0x143ac5e80 .bss
// MS2-RANGE: 0x143acdb20-0x143acdb21 .bss
// MS2-RANGE: 0x143acf820-0x143ad0970 .bss
// MS2-RANGE: 0x143ad1b20-0x143ad2349 .bss
// MS2-RANGE: 0x143ad76a8-0x143ad97b8 .bss
// MS2-RANGE: 0x143adc208-0x143addac0 .bss
// MS2-RANGE: 0x143ae95e0-0x143aea240 .bss
// MS2-RANGE: 0x143aedab0-0x143aedab4 .bss
// MS2-RANGE: 0x143aef240-0x143aef488 .bss
// MS2-RANGE: 0x143af1bc8-0x143af25fc .bss
// MS2-RANGE: 0x143af37a0-0x143af4404 .bss
// MS2-RANGE: 0x143af6008-0x143af62e4 .bss
// MS2-RANGE: 0x143af7d40-0x143af8a11 .bss
// MS2-RANGE: 0x143afa350-0x143afcba9 .bss
// MS2-RANGE: 0x143afe6f8-0x143afe760 .bss
// MS2-RANGE: 0x143b018a0-0x143b018a8 .bss
// MS2-RANGE: 0x143b023c0-0x143b023d8 .bss
// MS2-RANGE: 0x143b03490-0x143b05e50 .bss
// MS2-RANGE: 0x143b08a3c-0x143b094a8 .bss
// MS2-RANGE: 0x143b0d2d8-0x143b0dc38 .bss
// MS2-RANGE: 0x143b15f78-0x143b16088 .bss
// MS2-RANGE: 0x143ba9d08-0x143c490e0 .bss
// MS2-RANGE: 0x143d6eab8-0x143d6eb58 .bss
// MS2-RANGE: 0x143e64b00-0x143ee68c0 .bss

#ifndef MS2_HOOK_DLL

class UISwfEntityManager;
class Unk_140e45740;
class Unk_AltStringMgr;
class Unk_McEntityRules;
class Unk_SingletonObj;
struct Unk_CriUtfSortTable;
struct Unk_M2vCtx;
struct Unk_PtrArray;
struct __crt_locale_pointers;

bool DAT_143aac290;                                             // 0x143aac290
unsigned long g_dwCrashMainThreadId = 0x0u;                     // 0x143aac530
void* DAT_143aac538;                                            // 0x143aac538
bool DAT_143aac548;                                             // 0x143aac548
Unk_AltStringMgr* DAT_143aaccf8;                                // 0x143aaccf8
long g_lUniqueSeq;                                              // 0x143aacf78
__crt_locale_pointers* DAT_143aad168;                           // 0x143aad168
char DAT_143aad1e0;                                             // 0x143aad1e0
alignas(16) unsigned char DAT_143aad2d0[0x800];                 // 0x143aad2d0
alignas(16) unsigned char DAT_143aadad0[0x800];                 // 0x143aadad0
alignas(16) unsigned char DAT_143aae2d0[0x800];                 // 0x143aae2d0
alignas(16) unsigned char DAT_143aaead0[0x8];                   // 0x143aaead0
alignas(8) unsigned char DAT_143aaead8[0x8];                    // 0x143aaead8
alignas(16) unsigned char DAT_143aaeae0[0x8];                   // 0x143aaeae0
alignas(8) unsigned char DAT_143aaeae8[0x8];                    // 0x143aaeae8
alignas(16) unsigned char DAT_143aaeaf0[0x8];                   // 0x143aaeaf0
alignas(8) unsigned char DAT_143aaeaf8[0x8];                    // 0x143aaeaf8
void* DAT_143aaee08;                                            // 0x143aaee08
void* DAT_143aaee10;                                            // 0x143aaee10
int DAT_143aaef18;                                              // 0x143aaef18
bool DAT_143aaef5f;                                             // 0x143aaef60
Unk_SingletonObj* DAT_143aaf1d0;                                // 0x143aaf1d0
int g_nLocaleMode;                                              // 0x143ab0560
int DAT_143ab5b00;                                              // 0x143ab5b00
alignas(8) unsigned char DAT_143ab6728[0x8];                    // 0x143ab6728
void* DAT_143ab7800;                                            // 0x143ab7800
Unk_McEntityRules* DAT_143ab9510;                               // 0x143ab9510
UISwfEntityManager* DAT_143abb058;                              // 0x143abb058
float g_143abb090 = 0.0f;                                       // 0x143abb090
int DAT_143abdc30;                                              // 0x143abdc30
int DAT_143abdf50;                                              // 0x143abdf50
void* DAT_143abf890;                                            // 0x143abf890
Unk_SingletonObj* DAT_143ac1928;                                // 0x143ac1928
int DAT_143ac2fd0;                                              // 0x143ac2fd0
int DAT_143ac2fd4;                                              // 0x143ac2fd4
float DAT_143ac30a8 = 0.0f;                                     // 0x143ac30a8
float DAT_143ac30ac = 0.0f;                                     // 0x143ac30ac
float DAT_143ac3d08 = 0.0f;                                     // 0x143ac3d08
alignas(16) unsigned char DAT_143ac3d10[0x8];                   // 0x143ac3d10
void* DAT_143ac3d18;                                            // 0x143ac3d18
int DAT_143ac47c8;                                              // 0x143ac47c8
Unk_140e45740* DAT_143ac5d88;                                   // 0x143ac5d88
char DAT_143acdb20;                                             // 0x143acdb20
void* DAT_143ad08c8;                                            // 0x143ad08c8
int DAT_143ad1b20;                                              // 0x143ad1b20
char DAT_143ad2168;                                             // 0x143ad2168
char DAT_143ad2348;                                             // 0x143ad2348
__int64 DAT_143ad9140 = 0LL;                                    // 0x143ad9140
void* DAT_143ad95f0;                                            // 0x143ad95f0
alignas(8) unsigned char DAT_143adc208[0xf8];                   // 0x143adc208
alignas(16) unsigned char DAT_143add400[0xc0];                  // 0x143add400
char DAT_143ae95e0;                                             // 0x143ae95e0
char DAT_143ae95e1;                                             // 0x143ae95e1
char DAT_143ae95e2;                                             // 0x143ae95e2
char DAT_143ae95e3;                                             // 0x143ae95e3
bool DAT_143ae9750;                                             // 0x143ae9750
float DAT_143aea120 = 0.0f;                                     // 0x143aea120
long g_socketThreads;                                           // 0x143aedab0
float g_143aef240 = 0.0f;                                       // 0x143aef240
__int64 DAT_143af25f0 = 0LL;                                    // 0x143af25f0
int DAT_143af25f8;                                              // 0x143af25f8
int DAT_143af37b0;                                              // 0x143af37b0
int DAT_143af37b4;                                              // 0x143af37b4
__int64 DAT_143af37b8 = 0LL;                                    // 0x143af37b8
unsigned int DAT_143af3960 = 0x0u;                              // 0x143af3960
int DAT_143af4400;                                              // 0x143af4400
bool DAT_143af62d0;                                             // 0x143af62d0
int DAT_143af62d4;                                              // 0x143af62d4
int DAT_143af62d8;                                              // 0x143af62d8
int DAT_143af62dc;                                              // 0x143af62dc
int DAT_143af62e0;                                              // 0x143af62e0
int g_bAppActive;                                               // 0x143af7d40
int DAT_143af7d44;                                              // 0x143af7d44
alignas(8) unsigned char DAT_143af7d48[0x10];                   // 0x143af7d48
int g_143af7d58;                                                // 0x143af7d58
int g_bDefaultWndProc;                                          // 0x143af7d5c
int g_bPrintScreenPending;                                      // 0x143af80f8
int g_bHotkeyPrintScreen;                                       // 0x143af80fc
int g_bHotkeyAltPrintScreen;                                    // 0x143af8100
int g_143afa350;                                                // 0x143afa350
int DAT_143afa750;                                              // 0x143afa750
alignas(8) unsigned char DAT_143afbb98[0x8];                    // 0x143afbb98
alignas(16) unsigned char DAT_143afbba0[0x10];                  // 0x143afbba0
alignas(8) unsigned char DAT_143afbfc8[0x8];                    // 0x143afbfc8
char DAT_143afc898;                                             // 0x143afc898
char DAT_143afc8d0;                                             // 0x143afc8d0
char DAT_143afc8e8;                                             // 0x143afc8e8
char DAT_143afc900;                                             // 0x143afc900
char DAT_143afcb90;                                             // 0x143afcb90
char DAT_143afcba8;                                             // 0x143afcba8
alignas(8) unsigned char DAT_143afe6f8[0x68];                   // 0x143afe6f8
void* DAT_143b018a0;                                            // 0x143b018a0: luaopen_PhysX static
alignas(16) unsigned char DAT_143b023c0[0x8];                   // 0x143b023c0
alignas(8) unsigned char DAT_143b023c8[0x10];                   // 0x143b023c8
alignas(16) unsigned char DAT_143b03490[0x20b8];                // 0x143b03490
alignas(16) unsigned char DAT_143b05980[0x8];                   // 0x143b05980
char DAT_143b08a3c;                                             // 0x143b08a3c
void* DAT_143b0d2d8;                                            // 0x143b0d2d8
int DAT_143b0d360;                                              // 0x143b0d360
alignas(8) unsigned char DAT_143b0d368[0x8];                    // 0x143b0d368
void* DAT_143b0d780;                                            // 0x143b0d780
int DAT_143b0d788;                                              // 0x143b0d788
alignas(16) unsigned char DAT_143b0d790[0x8];                   // 0x143b0d790
unsigned int DAT_143b15f78 = 0x0u;                              // 0x143b15f78
unsigned int DAT_143b15f7c = 0x0u;                              // 0x143b15f7c
unsigned int DAT_143b15f80 = 0x0u;                              // 0x143b15f80
alignas(8) unsigned char DAT_143b15f88[0x8];                    // 0x143b15f88
alignas(16) unsigned char DAT_143b15f90[0x60];                  // 0x143b15f90
alignas(8) unsigned char DAT_143b16008[0x18];                   // 0x143b16008
void* DAT_143b16080;                                            // 0x143b16080
// 0x143ba9d08.. is CRI/video state the code walks as larger objects than the per-address names below
// (the b60/bb8 per-thread record arrays, the 0x143e65800 pair table, the decode tables, ...). The
// compiler does not keep .bss globals in source order, so each one gets an ordered .bss$ group section
// named by its exe address: the link keeps them contiguous in exe order with nothing in between.
#pragma bss_seg(".bss$cri_143ba9d08")
alignas(8) unsigned char DAT_143ba9d08[0x8];                    // 0x143ba9d08
#pragma bss_seg(".bss$cri_143ba9d10")
alignas(16) unsigned char DAT_143ba9d10[0x8];                   // 0x143ba9d10
#pragma bss_seg(".bss$cri_143ba9d18")
alignas(8) unsigned char DAT_143ba9d18[0x8];                    // 0x143ba9d18
#pragma bss_seg(".bss$cri_143ba9d20")
alignas(16) unsigned char DAT_143ba9d20[0x8];                   // 0x143ba9d20
#pragma bss_seg(".bss$cri_143ba9d28")
alignas(8) unsigned char DAT_143ba9d28[0x8];                    // 0x143ba9d28: sfr_cri_03's CriSint32 init count
#pragma bss_seg(".bss$cri_143ba9d30")
alignas(16) unsigned char DAT_143ba9d30[0x10];                  // 0x143ba9d30: sfr_cri_03's CRI Stream Joint version banner pointer
#pragma bss_seg(".bss$cri_143ba9d40")
Unk_CriUtfSortTable* DAT_143ba9d40;                             // 0x143ba9d40
#pragma bss_seg(".bss$cri_143ba9d48")
unsigned int DAT_143ba9d48;                                     // 0x143ba9d48
#pragma bss_seg(".bss$cri_143ba9d50")
const char* DAT_143ba9d50;                                      // 0x143ba9d50
#pragma bss_seg(".bss$cri_143ba9d60")
Unk_M2vCtx* DAT_143ba9d60;                                      // 0x143ba9d60
#pragma bss_seg(".bss$cri_143ba9d68")
const char* DAT_143ba9d68;                                      // 0x143ba9d68
#pragma bss_seg(".bss$cri_143ba9d70")
alignas(16) unsigned char DAT_143ba9d70[0x40];                  // 0x143ba9d70
#pragma bss_seg(".bss$cri_143ba9db0")
int DAT_143ba9db0;                                              // 0x143ba9db0
#pragma bss_seg(".bss$cri_143ba9db8")
Unk_M2vCtx* DAT_143ba9db8;                                      // 0x143ba9db8
#pragma bss_seg(".bss$cri_143ba9dd0")
alignas(16) unsigned char DAT_143ba9dd0[0x400];                 // 0x143ba9dd0
#pragma bss_seg(".bss$cri_143baa1d0")
alignas(16) unsigned char DAT_143baa1d0[0x400];                 // 0x143baa1d0
#pragma bss_seg(".bss$cri_143baa5d0")
alignas(16) unsigned char DAT_143baa5d0[0x400];                 // 0x143baa5d0
#pragma bss_seg(".bss$cri_143baa9d0")
alignas(16) unsigned char DAT_143baa9d0[0x400];                 // 0x143baa9d0
#pragma bss_seg(".bss$cri_143baadd0")
alignas(16) unsigned char DAT_143baadd0[0x400];                 // 0x143baadd0
#pragma bss_seg(".bss$cri_143bab1d0")
alignas(16) unsigned char DAT_143bab1d0[0x400];                 // 0x143bab1d0
#pragma bss_seg(".bss$cri_143bab5d0")
alignas(16) unsigned char DAT_143bab5d0[0x400];                 // 0x143bab5d0
#pragma bss_seg(".bss$cri_143bab9d0")
alignas(16) unsigned char DAT_143bab9d0[0x400];                 // 0x143bab9d0
#pragma bss_seg(".bss$cri_143babdd0")
alignas(16) unsigned char DAT_143babdd0[0x8];                   // 0x143babdd0
#pragma bss_seg(".bss$cri_143babdd8")
alignas(8) unsigned char DAT_143babdd8[0x8];                    // 0x143babdd8
#pragma bss_seg(".bss$cri_143babde0")
alignas(16) unsigned char DAT_143babde0[0x10];                  // 0x143babde0
#pragma bss_seg(".bss$cri_143babdf0")
alignas(16) unsigned char DAT_143babdf0[0x800];                 // 0x143babdf0
#pragma bss_seg(".bss$cri_143bac5f0")
alignas(16) unsigned char DAT_143bac5f0[0x50];                  // 0x143bac5f0
#pragma bss_seg(".bss$cri_143bac640")
alignas(16) unsigned char DAT_143bac640[0x8];                   // 0x143bac640
#pragma bss_seg(".bss$cri_143bac648")
alignas(8) unsigned char DAT_143bac648[0x8];                    // 0x143bac648
#pragma bss_seg(".bss$cri_143bac650")
alignas(16) unsigned char DAT_143bac650[0x8];                   // 0x143bac650
#pragma bss_seg(".bss$cri_143bac658")
alignas(8) unsigned char DAT_143bac658[0x8];                    // 0x143bac658
#pragma bss_seg(".bss$cri_143bac660")
alignas(16) unsigned char DAT_143bac660[0x8];                   // 0x143bac660
#pragma bss_seg(".bss$cri_143bac668")
alignas(8) unsigned char DAT_143bac668[0x8];                    // 0x143bac668
#pragma bss_seg(".bss$cri_143bac670")
alignas(16) unsigned char DAT_143bac670[0x8];                   // 0x143bac670
#pragma bss_seg(".bss$cri_143bac678")
alignas(8) unsigned char DAT_143bac678[0x8];                    // 0x143bac678
#pragma bss_seg(".bss$cri_143bac680")
alignas(16) unsigned char DAT_143bac680[0x10];                  // 0x143bac680
#pragma bss_seg(".bss$cri_143bac690")
alignas(16) unsigned char DAT_143bac690[0x800];                 // 0x143bac690
#pragma bss_seg(".bss$cri_143bace90")
alignas(16) unsigned char DAT_143bace90[0x800];                 // 0x143bace90
#pragma bss_seg(".bss$cri_143bad690")
alignas(16) unsigned char DAT_143bad690[0x10];                  // 0x143bad690
#pragma bss_seg(".bss$cri_143bad6a0")
alignas(16) unsigned char DAT_143bad6a0[0x8];                   // 0x143bad6a0
#pragma bss_seg(".bss$cri_143bad6a8")
alignas(8) unsigned char DAT_143bad6a8[0x8];                    // 0x143bad6a8
#pragma bss_seg(".bss$cri_143bad6b0")
alignas(16) unsigned char DAT_143bad6b0[0x180];                 // 0x143bad6b0
#pragma bss_seg(".bss$cri_143bad830")
alignas(16) unsigned char DAT_143bad830[0x280];                 // 0x143bad830
#pragma bss_seg(".bss$cri_143badab0")
alignas(16) unsigned char DAT_143badab0[0x50];                  // 0x143badab0
#pragma bss_seg(".bss$cri_143badb00")
alignas(16) unsigned char DAT_143badb00[0x8];                   // 0x143badb00
#pragma bss_seg(".bss$cri_143badb08")
alignas(8) unsigned char DAT_143badb08[0x8];                    // 0x143badb08
#pragma bss_seg(".bss$cri_143badb10")
alignas(16) unsigned char DAT_143badb10[0x8];                   // 0x143badb10
#pragma bss_seg(".bss$cri_143badb18")
alignas(8) unsigned char DAT_143badb18[0xc];                    // 0x143badb18
#pragma bss_seg(".bss$cri_143badb24")
alignas(4) unsigned char DAT_143badb24[0x4];                    // 0x143badb24
#pragma bss_seg(".bss$cri_143badb28")
alignas(8) unsigned char DAT_143badb28[0x8];                    // 0x143badb28
#pragma bss_seg(".bss$cri_143badb30")
alignas(16) unsigned char DAT_143badb30[0x8];                   // 0x143badb30
#pragma bss_seg(".bss$cri_143badb38")
alignas(8) unsigned char DAT_143badb38[0x8];                    // 0x143badb38
#pragma bss_seg(".bss$cri_143badb40")
alignas(16) unsigned char DAT_143badb40[0x8];                   // 0x143badb40
#pragma bss_seg(".bss$cri_143badb48")
alignas(8) unsigned char DAT_143badb48[0x8];                    // 0x143badb48
#pragma bss_seg(".bss$cri_143badb50")
alignas(16) unsigned char DAT_143badb50[0x10];                  // 0x143badb50
#pragma bss_seg(".bss$cri_143badb60")
alignas(16) unsigned char DAT_143badb60[0x4];                   // 0x143badb60
#pragma bss_seg(".bss$cri_143badb64")
alignas(4) unsigned char DAT_143badb64[0x4];                    // 0x143badb64
#pragma bss_seg(".bss$cri_143badb68")
alignas(8) unsigned char DAT_143badb68[0x1c];                   // 0x143badb68
#pragma bss_seg(".bss$cri_143badb84")
alignas(4) unsigned char DAT_143badb84[0x4];                    // 0x143badb84
#pragma bss_seg(".bss$cri_143badb88")
alignas(8) unsigned char DAT_143badb88[0x30];                   // 0x143badb88
#pragma bss_seg(".bss$cri_143badbb8")
alignas(8) unsigned char DAT_143badbb8[0x4];                    // 0x143badbb8
#pragma bss_seg(".bss$cri_143badbbc")
alignas(4) unsigned char DAT_143badbbc[0x20];                   // 0x143badbbc
#pragma bss_seg(".bss$cri_143badbdc")
alignas(4) unsigned char DAT_143badbdc[0x24];                   // 0x143badbdc
#pragma bss_seg(".bss$cri_143badc00")
alignas(16) unsigned char DAT_143badc00[0x380];                 // 0x143badc00
#pragma bss_seg(".bss$cri_143badf80")
alignas(16) unsigned char DAT_143badf80[0x9b160];               // 0x143badf80
#pragma bss_seg(".bss$cri_143d6eb38")
alignas(8) unsigned char DAT_143d6eb38[0x8];                    // 0x143d6eb38
#pragma bss_seg(".bss$cri_143d6eb40")
alignas(16) unsigned char DAT_143d6eb40[0x8];                   // 0x143d6eb40
#pragma bss_seg(".bss$cri_143d6eb48")
alignas(8) unsigned char DAT_143d6eb48[0x8];                    // 0x143d6eb48
#pragma bss_seg(".bss$cri_143d6eb50")
alignas(16) unsigned char DAT_143d6eb50[0x8];                   // 0x143d6eb50
#pragma bss_seg(".bss$cri_143e64b00")
alignas(16) unsigned char DAT_143e64b00[0x8];                   // 0x143e64b00
#pragma bss_seg(".bss$cri_143e64b08")
alignas(8) unsigned char DAT_143e64b08[0x8];                    // 0x143e64b08
#pragma bss_seg(".bss$cri_143e64b10")
alignas(16) unsigned char DAT_143e64b10[0x8];                   // 0x143e64b10
#pragma bss_seg(".bss$cri_143e64b18")
alignas(8) unsigned char DAT_143e64b18[0x8];                    // 0x143e64b18
#pragma bss_seg(".bss$cri_143e64b20")
void* DAT_143e64b20;                                            // 0x143e64b20
#pragma bss_seg(".bss$cri_143e64b28")
alignas(8) unsigned char DAT_143e64b28[0x8];                    // 0x143e64b28
#pragma bss_seg(".bss$cri_143e64b30")
alignas(16) unsigned char DAT_143e64b30[0x8];                   // 0x143e64b30
#pragma bss_seg(".bss$cri_143e64b38")
alignas(8) unsigned char DAT_143e64b38[0x8];                    // 0x143e64b38
#pragma bss_seg(".bss$cri_143e64b40")
alignas(16) unsigned char DAT_143e64b40[0x8];                   // 0x143e64b40
#pragma bss_seg(".bss$cri_143e64b48")
alignas(8) unsigned char DAT_143e64b48[0x8];                    // 0x143e64b48
#pragma bss_seg(".bss$cri_143e64b50")
alignas(16) unsigned char DAT_143e64b50[0x8];                   // 0x143e64b50
#pragma bss_seg(".bss$cri_143e64b58")
alignas(8) unsigned char DAT_143e64b58[0x8];                    // 0x143e64b58
#pragma bss_seg(".bss$cri_143e64b60")
void* DAT_143e64b60;                                            // 0x143e64b60
#pragma bss_seg(".bss$cri_143e64b68")
alignas(8) unsigned char DAT_143e64b68[0x8];                    // 0x143e64b68
#pragma bss_seg(".bss$cri_143e64b70")
alignas(16) unsigned char DAT_143e64b70[0x8];                   // 0x143e64b70
#pragma bss_seg(".bss$cri_143e64b78")
alignas(8) unsigned char DAT_143e64b78[0x8];                    // 0x143e64b78
#pragma bss_seg(".bss$cri_143e64b80")
alignas(16) unsigned char DAT_143e64b80[0x8];                   // 0x143e64b80
#pragma bss_seg(".bss$cri_143e64b88")
alignas(8) unsigned char DAT_143e64b88[0x8];                    // 0x143e64b88
#pragma bss_seg(".bss$cri_143e64b90")
alignas(16) unsigned char DAT_143e64b90[0x8];                   // 0x143e64b90
#pragma bss_seg(".bss$cri_143e64b98")
alignas(8) unsigned char DAT_143e64b98[0x8];                    // 0x143e64b98
#pragma bss_seg(".bss$cri_143e64ba0")
alignas(16) unsigned char DAT_143e64ba0[0x8];                   // 0x143e64ba0
#pragma bss_seg(".bss$cri_143e64ba8")
alignas(8) unsigned char DAT_143e64ba8[0x18];                   // 0x143e64ba8
#pragma bss_seg(".bss$cri_143e64bc0")
alignas(16) unsigned char DAT_143e64bc0[0x20];                  // 0x143e64bc0
#pragma bss_seg(".bss$cri_143e64be0")
alignas(16) unsigned char DAT_143e64be0[0x1];                   // 0x143e64be0
#pragma bss_seg(".bss$cri_143e64be1")
alignas(1) unsigned char DAT_143e64be1[0x1f];                   // 0x143e64be1
#pragma bss_seg(".bss$cri_143e64c00")
alignas(16) unsigned char DAT_143e64c00[0x1];                   // 0x143e64c00
#pragma bss_seg(".bss$cri_143e64c01")
alignas(1) unsigned char DAT_143e64c01[0x7ff];                  // 0x143e64c01
#pragma bss_seg(".bss$cri_143e65400")
alignas(16) unsigned char DAT_143e65400[0x1];                   // 0x143e65400
#pragma bss_seg(".bss$cri_143e65401")
alignas(1) unsigned char DAT_143e65401[0x400];                  // 0x143e65401
#pragma bss_seg(".bss$cri_143e65801")
alignas(1) unsigned char DAT_143e65801[0x1];                    // 0x143e65801
#pragma bss_seg(".bss$cri_143e65802")
alignas(2) unsigned char DAT_143e65802[0x1e];                   // 0x143e65802
#pragma bss_seg(".bss$cri_143e65820")
alignas(16) unsigned char DAT_143e65820[0x1];                   // 0x143e65820
#pragma bss_seg(".bss$cri_143e65821")
alignas(1) unsigned char DAT_143e65821[0xfff];                  // 0x143e65821
#pragma bss_seg(".bss$cri_143e66820")
alignas(16) unsigned char DAT_143e66820[0x1];                   // 0x143e66820
#pragma bss_seg(".bss$cri_143e66821")
alignas(1) unsigned char DAT_143e66821[0xf];                    // 0x143e66821
#pragma bss_seg(".bss$cri_143e66830")
alignas(16) unsigned char DAT_143e66830[0x1];                   // 0x143e66830
#pragma bss_seg(".bss$cri_143e66831")
alignas(1) unsigned char DAT_143e66831[0xf];                    // 0x143e66831
#pragma bss_seg(".bss$cri_143e66840")
alignas(16) unsigned char DAT_143e66840[0x1];                   // 0x143e66840
#pragma bss_seg(".bss$cri_143e66841")
alignas(1) unsigned char DAT_143e66841[0x7f];                   // 0x143e66841
#pragma bss_seg(".bss$cri_143e668c0")
alignas(16) unsigned char DAT_143e668c0[0x1];                   // 0x143e668c0
#pragma bss_seg(".bss$cri_143e668c1")
alignas(1) unsigned char DAT_143e668c1[0x1];                    // 0x143e668c1
#pragma bss_seg(".bss$cri_143e668c2")
alignas(2) unsigned char DAT_143e668c2[0x7fffe];                // 0x143e668c2
#pragma bss_seg()

#pragma comment(linker, "/alternatename:?s_instance@Unk_CrashSingleton@@2PEAVCCrashManager@@EA=?DAT_143aac538@@3PEAXEA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VGFxManager@@@@2PEAVGFxManager@@EA=?DAT_143aaccf8@@3PEAVUnk_AltStringMgr@@EA")
#pragma comment(linker, "/alternatename:?DAT_143aad1e0@@3_NA=?DAT_143aad1e0@@3DA")
#pragma comment(linker, "/alternatename:?DAT_143aaead0@@3PEAPEAEEA=?DAT_143aaead0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aaead8@@3PEAPEAEEA=?DAT_143aaead8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aaeae0@@3PEAPEAEEA=?DAT_143aaeae0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aaeae8@@3PEAPEAEEA=?DAT_143aaeae8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aaeaf0@@3PEAPEAEEA=?DAT_143aaeaf0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aaeaf8@@3PEAPEAEEA=?DAT_143aaeaf8@@3PAEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VCEffectService@@@@2PEAVCEffectService@@EA=?DAT_143aaee08@@3PEAXEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VWorldService@@@@2PEAVWorldService@@EA=?DAT_143aaee10@@3PEAXEA")
#pragma comment(linker, "/alternatename:?DAT_143aaef60@@3_NA=?DAT_143aaef5f@@3_NA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VItemGachaBoxTable@@@@2PEAVItemGachaBoxTable@@EA=?DAT_143aaf1d0@@3PEAVUnk_SingletonObj@@EA")
#pragma comment(linker, "/alternatename:?DAT_143ab0560@@3HA=?g_nLocaleMode@@3HA")
#pragma comment(linker, "/alternatename:?g_pfnPrevExceptionFilter@@3P6AJPEAU_EXCEPTION_POINTERS@@@ZEA=?DAT_143ab6728@@3PAEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VMS2InputService@@@@2PEAVMS2InputService@@EA=?DAT_143ab7800@@3PEAXEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VCTriggerService@@@@2PEAVCTriggerService@@EA=?DAT_143ab9510@@3PEAVUnk_McEntityRules@@EA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VUISwfEntityManager@@@@2PEAVUISwfEntityManager@@EA=?DAT_143abb058@@3PEAVUISwfEntityManager@@EA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VCSoundService@@@@2PEAVCSoundService@@EA=?DAT_143abf890@@3PEAXEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VCSoundEventMgr@@@@2PEAVCSoundEventMgr@@EA=?DAT_143ac1928@@3PEAVUnk_SingletonObj@@EA")
#pragma comment(linker, "/alternatename:?s_fTime@MultiSceneUpdater@@2MA=?DAT_143ac3d08@@3MA")
#pragma comment(linker, "/alternatename:?s_pfnCallback@MultiSceneUpdater@@2P6AXPEAXHIIPEAVNiBatchedUpdateProcess@@@ZEA=?DAT_143ac3d10@@3PAEA")
#pragma comment(linker, "/alternatename:?s_pCallbackContext@MultiSceneUpdater@@2PEAXEA=?DAT_143ac3d18@@3PEAXEA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VUIAlignWidgetManager@@@@2PEAVUIAlignWidgetManager@@EA=?DAT_143ac5d88@@3PEAVUnk_140e45740@@EA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VDecoEditService@@@@2PEAVDecoEditService@@EA=?DAT_143ad08c8@@3PEAXEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VMS2LightService@@@@2PEAVMS2LightService@@EA=?DAT_143ad95f0@@3PEAXEA")
#pragma comment(linker, "/alternatename:?DAT_143adc208@@3PADA=?DAT_143adc208@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143add400@@3PAHA=?DAT_143add400@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143add400@@3PAIA=?DAT_143add400@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae95e0@@3_NA=?DAT_143ae95e0@@3DA")
#pragma comment(linker, "/alternatename:?DAT_143ae95e1@@3_NA=?DAT_143ae95e1@@3DA")
#pragma comment(linker, "/alternatename:?DAT_143af62d4@@3IA=?DAT_143af62d4@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143af62d8@@3IA=?DAT_143af62d8@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143af7d40@@3HA=?g_bAppActive@@3HA")
#pragma comment(linker, "/alternatename:?g_rcWindow@@3UtagRECT@@A=?DAT_143af7d48@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af7d58@@3HA=?g_143af7d58@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143afbb98@@3P6AXXZEA=?DAT_143afbb98@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afbba0@@3P6AXXZEA=?DAT_143afbba0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afbfc8@@3P6AXPEAVNiAVObject@@@ZEA=?DAT_143afbfc8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afc898@@3EA=?DAT_143afc898@@3DA")
#pragma comment(linker, "/alternatename:?DAT_143afe6f8@@3P6A?AUUnk_MCPPtr@@PEAVNiVisibleArray@@PEAVNiSPWorkflowManager@@@ZEA=?DAT_143afe6f8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afe6f8@@3P6A?AV?$SmartPointer@VNiCullingProcess@@@efd@@PEAVNiVisibleArray@@PEAVNiSPWorkflowManager@@@ZEA=?DAT_143afe6f8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b023c0@@3P6AXXZEA=?DAT_143b023c0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b023c8@@3P6AH_K@ZEA=?DAT_143b023c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b03490@@3P6AXFEPEBD@ZEA=?DAT_143b03490@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b05980@@3P6A?AVutf8string@efd@@AEBV12@@ZEA=?DAT_143b05980@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VUniqueSwfIDCreator@@@@2PEAVUniqueSwfIDCreator@@EA=?DAT_143b0d2d8@@3PEAXEA")
#pragma comment(linker, "/alternatename:?s_nCaptureBlock@GFxService@@2HA=?DAT_143b0d360@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143b0d368@@3P6AXXZEA=?DAT_143b0d368@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VGFxAtlasCache@@@@2PEAVGFxAtlasCache@@EA=?DAT_143b0d780@@3PEAXEA")
#pragma comment(linker, "/alternatename:?DAT_143b0d790@@3P6APEAVFile@Scaleform@@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@ZEA=?DAT_143b0d790@@3PAEA")
#pragma comment(linker, "/alternatename:?ConstructCopyCalls@ContextImpl@Render@Scaleform@@3IA=?DAT_143b15f78@@3IA")
#pragma comment(linker, "/alternatename:?DestroyCalls@ContextImpl@Render@Scaleform@@3IA=?DAT_143b15f7c@@3IA")
#pragma comment(linker, "/alternatename:?CopyCalls@ContextImpl@Render@Scaleform@@3IA=?DAT_143b15f80@@3IA")
#pragma comment(linker, "/alternatename:?DAT_143b15f88@@3P6AXXZEA=?DAT_143b15f88@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b15f90@@3P6AH_K@ZEA=?DAT_143b15f90@@3PAEA")
#pragma comment(linker, "/alternatename:GFx_Compile_with_SF_BUILD_DEBUG=?DAT_143b16008@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b16080@GFx@Scaleform@@3PEAXEA=?DAT_143b16080@@3PEAXEA")
#pragma comment(linker, "/alternatename:DAT_143ba9d08=?DAT_143ba9d08@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ba9d10=?DAT_143ba9d10@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ba9d18=?DAT_143ba9d18@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ba9d20=?DAT_143ba9d20@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ba9d28=?DAT_143ba9d28@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ba9d30=?DAT_143ba9d30@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ba9d70@@3PAHA=?DAT_143ba9d70@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ba9dd0@@3PAHA=?DAT_143ba9dd0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ba9dd0=?DAT_143ba9dd0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143baa1d0@@3PAHA=?DAT_143baa1d0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143baa1d0=?DAT_143baa1d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143baa5d0@@3PAHA=?DAT_143baa5d0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143baa5d0=?DAT_143baa5d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143baa9d0@@3PAHA=?DAT_143baa9d0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143baa9d0=?DAT_143baa9d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143baadd0@@3PAHA=?DAT_143baadd0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143baadd0=?DAT_143baadd0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143bab1d0@@3PAHA=?DAT_143bab1d0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143bab1d0=?DAT_143bab1d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143bab5d0@@3PAHA=?DAT_143bab5d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143bab9d0@@3PAHA=?DAT_143bab9d0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143babdd0=?DAT_143babdd0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143babdd8=?DAT_143babdd8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143babde0=?DAT_143babde0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143babdf0@@3PANA=?DAT_143babdf0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143babdf0=?DAT_143babdf0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143bac5f0@@3PANA=?DAT_143bac5f0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143bac640@@3PANA=?DAT_143bac640@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143bac640=?DAT_143bac640@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143bac648=?DAT_143bac648@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143bac650=?DAT_143bac650@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143bac658=?DAT_143bac658@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143bac660=?DAT_143bac660@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143bac668=?DAT_143bac668@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143bac670=?DAT_143bac670@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143bac678=?DAT_143bac678@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143bac680=?DAT_143bac680@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143bac690@@3PANA=?DAT_143bac690@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143bac690=?DAT_143bac690@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143bace90@@3PANA=?DAT_143bace90@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143bace90=?DAT_143bace90@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143bad690=?DAT_143bad690@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143bad6a0=?DAT_143bad6a0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143bad6a8=?DAT_143bad6a8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143bad6b0=?DAT_143bad6b0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143bad830=?DAT_143bad830@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badab0=?DAT_143badab0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143badb00=?DAT_143badb00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb08=?DAT_143badb08@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb10=?DAT_143badb10@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb18=?DAT_143badb18@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb24=?DAT_143badb24@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143badb28=?DAT_143badb28@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb30=?DAT_143badb30@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb38=?DAT_143badb38@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb40=?DAT_143badb40@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb48=?DAT_143badb48@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb50=?DAT_143badb50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb60=?DAT_143badb60@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb64=?DAT_143badb64@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb68=?DAT_143badb68@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb84=?DAT_143badb84@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badb88=?DAT_143badb88@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badbb8=?DAT_143badbb8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badbbc=?DAT_143badbbc@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badbdc=?DAT_143badbdc@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badc00=?DAT_143badc00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143badf80=?DAT_143badf80@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143d6eb38@@3P6AXPEAX@ZEA=?DAT_143d6eb38@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143d6eb40@@3P6AXPEAUUnk_RsRendererSize@@@ZEA=?DAT_143d6eb40@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143d6eb48@@3P6AXXZEA=?DAT_143d6eb48@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143d6eb50@@3P6AX_N@ZEA=?DAT_143d6eb50@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b00@@3PEAXEA=?DAT_143e64b00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b00=?DAT_143e64b00@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b08@@3PEAXEA=?DAT_143e64b08@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b08=?DAT_143e64b08@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b10@@3PEAXEA=?DAT_143e64b10@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b10=?DAT_143e64b10@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b18@@3PEAXEA=?DAT_143e64b18@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b18=?DAT_143e64b18@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b28@@3PEAXEA=?DAT_143e64b28@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b28=?DAT_143e64b28@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b30@@3PEAXEA=?DAT_143e64b30@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b30=?DAT_143e64b30@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b38@@3PEAXEA=?DAT_143e64b38@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b38=?DAT_143e64b38@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b40@@3PEAXEA=?DAT_143e64b40@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b40=?DAT_143e64b40@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b48@@3PEAXEA=?DAT_143e64b48@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b48=?DAT_143e64b48@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b50@@3PEAXEA=?DAT_143e64b50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b50=?DAT_143e64b50@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b58@@3PEAXEA=?DAT_143e64b58@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b58=?DAT_143e64b58@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b68@@3PEAXEA=?DAT_143e64b68@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b68=?DAT_143e64b68@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b70@@3PEAXEA=?DAT_143e64b70@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b70=?DAT_143e64b70@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b78@@3PEAXEA=?DAT_143e64b78@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b78=?DAT_143e64b78@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b80@@3PEAXEA=?DAT_143e64b80@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b80=?DAT_143e64b80@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b88@@3PEAXEA=?DAT_143e64b88@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b88=?DAT_143e64b88@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b90@@3PEAXEA=?DAT_143e64b90@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b90=?DAT_143e64b90@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64b98@@3PEAXEA=?DAT_143e64b98@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64b98=?DAT_143e64b98@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64ba0@@3PEAXEA=?DAT_143e64ba0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64ba0=?DAT_143e64ba0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143e64ba8@@3PEAXEA=?DAT_143e64ba8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64ba8=?DAT_143e64ba8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64bc0=?DAT_143e64bc0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64be0=?DAT_143e64be0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64be1=?DAT_143e64be1@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64c00=?DAT_143e64c00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e64c01=?DAT_143e64c01@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e65400=?DAT_143e65400@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e65401=?DAT_143e65401@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e65801=?DAT_143e65801@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143e65802=?DAT_143e65802@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e65820=?DAT_143e65820@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e65821=?DAT_143e65821@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e66820=?DAT_143e66820@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e66821=?DAT_143e66821@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e66830=?DAT_143e66830@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e66831=?DAT_143e66831@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e66840=?DAT_143e66840@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e66841=?DAT_143e66841@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e668c0=?DAT_143e668c0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e668c1=?DAT_143e668c1@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e668c2=?DAT_143e668c2@@3PAEA")

#endif // MS2_HOOK_DLL
