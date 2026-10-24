// Data unit (sfr22; groups 143aab428, 143ab0560, 143ab5b00, 143ab7800, 143ab9510, 143abb058, 143abdc30, 143abf510, 143ac1928, 143ac2bd0, 143ac5988, 143acdb20, 143acf820, 143ad1b20, 143ad76a8, 143adc208, 143ae95e0, 143aedab0, 143aef240, 143af1bc8, 143af37a0, 143af6008, 143af7d40, 143afa350, 143afe6f8, 143b023c0, 143b03490, 143b08a3c, 143b0d2d8, 143b15f78, 143ba9d08, 143d6eab8, 143e64b00 of work/sfr35/outside-units.tsv):
// exe globals of the .bss blocks below that no recovered TU defines (zero: the exe's raw .data ends at 0x143aab400).
// One definition per exe address (tools/datacheck.py checks address, size and initializer); the other names
// users declare at an address are mapped to it with /alternatename. Class objects are byte images up to the
// next known exe global; their constructors (the owning TU's .text$di initializer) are not run by this unit,
// see the zero-blob list in work/sfr22/outside-summary.md. A recovered owner moves a definition to its TU.
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

alignas(8) unsigned char DAT_143aab428[0xd0];                   // 0x143aab428
bool DAT_143aac290;                                             // 0x143aac290
unsigned long g_dwCrashMainThreadId = 0x0u;                     // 0x143aac530
void* DAT_143aac538;                                            // 0x143aac538
bool DAT_143aac548;                                             // 0x143aac548
alignas(8) unsigned char DAT_143aacc88[0x8];                    // 0x143aacc88
alignas(16) unsigned char DAT_143aacc90[0x58];                  // 0x143aacc90
Unk_AltStringMgr* DAT_143aaccf8;                                // 0x143aaccf8
alignas(16) unsigned char DAT_143aacd50[0x40];                  // 0x143aacd50
long g_lUniqueSeq;                                              // 0x143aacf78
unsigned __int64 DAT_143aad0e8 = 0x0ull;                        // 0x143aad0e8
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
alignas(8) unsigned char DAT_143ab78e8[0x20];                   // 0x143ab78e8
Unk_McEntityRules* DAT_143ab9510;                               // 0x143ab9510
UISwfEntityManager* DAT_143abb058;                              // 0x143abb058
float g_143abb090 = 0.0f;                                       // 0x143abb090
int DAT_143abdc30;                                              // 0x143abdc30
int DAT_143abdf50;                                              // 0x143abdf50
alignas(16) unsigned char DAT_143abf510[0x8];                   // 0x143abf510
void* DAT_143abf890;                                            // 0x143abf890
Unk_SingletonObj* DAT_143ac1928;                                // 0x143ac1928
alignas(16) unsigned char DAT_143ac2bd0[0x2c8];                 // 0x143ac2bd0
int DAT_143ac2fd0;                                              // 0x143ac2fd0
int DAT_143ac2fd4;                                              // 0x143ac2fd4
float DAT_143ac30a8 = 0.0f;                                     // 0x143ac30a8
float DAT_143ac30ac = 0.0f;                                     // 0x143ac30ac
char DAT_143ac3ce8;                                             // 0x143ac3ce8
float DAT_143ac3d08 = 0.0f;                                     // 0x143ac3d08
alignas(16) unsigned char DAT_143ac3d10[0x8];                   // 0x143ac3d10
void* DAT_143ac3d18;                                            // 0x143ac3d18
int DAT_143ac47c8;                                              // 0x143ac47c8
alignas(8) unsigned char DAT_143ac5988[0x2b0];                  // 0x143ac5988
Unk_140e45740* DAT_143ac5d88;                                   // 0x143ac5d88
char DAT_143acdb20;                                             // 0x143acdb20
alignas(16) unsigned char DAT_143acf820[0x130];                 // 0x143acf820
void* DAT_143ad08c8;                                            // 0x143ad08c8
int DAT_143ad1b20;                                              // 0x143ad1b20
char DAT_143ad2168;                                             // 0x143ad2168
alignas(8) unsigned char DAT_143ad2288[0xc0];                   // 0x143ad2288
char DAT_143ad2348;                                             // 0x143ad2348
alignas(8) unsigned char DAT_143ad76a8[0xc88];                  // 0x143ad76a8
__int64 DAT_143ad9140 = 0LL;                                    // 0x143ad9140
void* DAT_143ad95f0;                                            // 0x143ad95f0
alignas(8) unsigned char DAT_143adc208[0xf8];                   // 0x143adc208
alignas(16) unsigned char DAT_143adca50[0x48];                  // 0x143adca50
alignas(16) unsigned char DAT_143add400[0xc0];                  // 0x143add400
alignas(8) unsigned char DAT_143adda48[0x78];                   // 0x143adda48
char DAT_143ae95e0;                                             // 0x143ae95e0
char DAT_143ae95e1;                                             // 0x143ae95e1
char DAT_143ae95e2;                                             // 0x143ae95e2
char DAT_143ae95e3;                                             // 0x143ae95e3
bool DAT_143ae9750;                                             // 0x143ae9750
float DAT_143aea120 = 0.0f;                                     // 0x143aea120
alignas(8) unsigned char DAT_143aea1b8[0x8];                    // 0x143aea1b8
alignas(16) unsigned char DAT_143aea1c0[0x8];                   // 0x143aea1c0
alignas(8) unsigned char DAT_143aea1c8[0x8];                    // 0x143aea1c8
alignas(16) unsigned char DAT_143aea1d0[0x8];                   // 0x143aea1d0
alignas(8) unsigned char DAT_143aea1d8[0x8];                    // 0x143aea1d8
alignas(16) unsigned char DAT_143aea1e0[0x60];                  // 0x143aea1e0
long g_socketThreads;                                           // 0x143aedab0
float g_143aef240 = 0.0f;                                       // 0x143aef240
alignas(8) unsigned char DAT_143aef3b8[0xd0];                   // 0x143aef3b8
alignas(8) unsigned char DAT_143af1bc8[0x50];                   // 0x143af1bc8
alignas(8) unsigned char DAT_143af1c18[0x338];                  // 0x143af1c18
alignas(8) unsigned char DAT_143af2258[0x398];                  // 0x143af2258
__int64 DAT_143af25f0 = 0LL;                                    // 0x143af25f0
int DAT_143af25f8;                                              // 0x143af25f8
alignas(16) unsigned char DAT_143af37a0[0x10];                  // 0x143af37a0
int DAT_143af37b0;                                              // 0x143af37b0
int DAT_143af37b4;                                              // 0x143af37b4
__int64 DAT_143af37b8 = 0LL;                                    // 0x143af37b8
unsigned int DAT_143af3960 = 0x0u;                              // 0x143af3960
alignas(8) unsigned char DAT_143af3e28[0x8];                    // 0x143af3e28
alignas(16) unsigned char DAT_143af3e30[0x3b0];                 // 0x143af3e30
int DAT_143af4400;                                              // 0x143af4400
alignas(8) unsigned char DAT_143af6008[0x2b8];                  // 0x143af6008
alignas(16) unsigned char DAT_143af62c0[0x10];                  // 0x143af62c0
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
alignas(16) unsigned char DAT_143af7e00[0x180];                 // 0x143af7e00
alignas(16) unsigned char DAT_143af7f80[0x178];                 // 0x143af7f80
int g_bPrintScreenPending;                                      // 0x143af80f8
int g_bHotkeyPrintScreen;                                       // 0x143af80fc
int g_bHotkeyAltPrintScreen;                                    // 0x143af8100
alignas(8) unsigned char DAT_143af8278[0xe8];                   // 0x143af8278
alignas(16) unsigned char DAT_143af88e0[0x20];                  // 0x143af88e0
char DAT_143af89f0;                                             // 0x143af89f0
char DAT_143af8a00;                                             // 0x143af8a00
char DAT_143af8a10;                                             // 0x143af8a10
int g_143afa350;                                                // 0x143afa350
int DAT_143afa750;                                              // 0x143afa750
alignas(8) unsigned char DAT_143afa798[0x10];                   // 0x143afa798
char DAT_143afa7c8;                                             // 0x143afa7c8
alignas(16) unsigned char DAT_143afa7f0[0x8];                   // 0x143afa7f0
alignas(16) unsigned char DAT_143afb020[0x28];                  // 0x143afb020
char DAT_143afb348;                                             // 0x143afb348
alignas(8) unsigned char DAT_143afbb98[0x8];                    // 0x143afbb98
alignas(16) unsigned char DAT_143afbba0[0x10];                  // 0x143afbba0
alignas(8) unsigned char DAT_143afbfb8[0x10];                   // 0x143afbfb8
alignas(8) unsigned char DAT_143afbfc8[0x8];                    // 0x143afbfc8
char DAT_143afc898;                                             // 0x143afc898
char DAT_143afc8d0;                                             // 0x143afc8d0
char DAT_143afc8e8;                                             // 0x143afc8e8
char DAT_143afc900;                                             // 0x143afc900
char DAT_143afc918;                                             // 0x143afc918
char DAT_143afcb90;                                             // 0x143afcb90
char DAT_143afcba8;                                             // 0x143afcba8
alignas(8) unsigned char DAT_143afe6f8[0x68];                   // 0x143afe6f8
alignas(16) unsigned char DAT_143b023c0[0x8];                   // 0x143b023c0
alignas(8) unsigned char DAT_143b023c8[0x10];                   // 0x143b023c8
alignas(16) unsigned char DAT_143b03490[0x20b8];                // 0x143b03490
alignas(16) unsigned char DAT_143b05980[0x8];                   // 0x143b05980
alignas(8) unsigned char DAT_143b059e8[0x468];                  // 0x143b059e8
char DAT_143b08a3c;                                             // 0x143b08a3c
void* DAT_143b09498;                                            // 0x143b09498
void* DAT_143b094a0;                                            // 0x143b094a0
void* DAT_143b0d2d8;                                            // 0x143b0d2d8
alignas(16) unsigned char DAT_143b0d330[0x8];                   // 0x143b0d330
alignas(8) unsigned char DAT_143b0d338[0x8];                    // 0x143b0d338
alignas(16) unsigned char DAT_143b0d340[0x8];                   // 0x143b0d340
alignas(8) unsigned char DAT_143b0d348[0x8];                    // 0x143b0d348
int DAT_143b0d360;                                              // 0x143b0d360
alignas(8) unsigned char DAT_143b0d368[0x8];                    // 0x143b0d368
alignas(8) unsigned char DAT_143b0d778[0x8];                    // 0x143b0d778
void* DAT_143b0d780;                                            // 0x143b0d780
int DAT_143b0d788;                                              // 0x143b0d788
alignas(16) unsigned char DAT_143b0d790[0x8];                   // 0x143b0d790
alignas(8) unsigned char DAT_143b0d798[0x8];                    // 0x143b0d798
alignas(16) unsigned char DAT_143b0d7a0[0x8];                   // 0x143b0d7a0
alignas(8) unsigned char DAT_143b0d7a8[0x8];                    // 0x143b0d7a8
alignas(16) unsigned char DAT_143b0d7b0[0x8];                   // 0x143b0d7b0
alignas(8) unsigned char DAT_143b0d7b8[0x8];                    // 0x143b0d7b8
alignas(8) unsigned char DAT_143b0dc28[0x8];                    // 0x143b0dc28
alignas(16) unsigned char DAT_143b0dc30[0x8];                   // 0x143b0dc30
unsigned int DAT_143b15f78 = 0x0u;                              // 0x143b15f78
unsigned int DAT_143b15f7c = 0x0u;                              // 0x143b15f7c
unsigned int DAT_143b15f80 = 0x0u;                              // 0x143b15f80
alignas(8) unsigned char DAT_143b15f88[0x8];                    // 0x143b15f88
alignas(16) unsigned char DAT_143b15f90[0x60];                  // 0x143b15f90
alignas(8) unsigned char DAT_143b16008[0x18];                   // 0x143b16008
void* DAT_143b16080;                                            // 0x143b16080
alignas(8) unsigned char DAT_143ba9d08[0x8];                    // 0x143ba9d08
alignas(16) unsigned char DAT_143ba9d10[0x8];                   // 0x143ba9d10
alignas(8) unsigned char DAT_143ba9d18[0x8];                    // 0x143ba9d18
alignas(16) unsigned char DAT_143ba9d20[0x8];                   // 0x143ba9d20
alignas(8) unsigned char DAT_143ba9d28[0x18];                   // 0x143ba9d28
Unk_CriUtfSortTable* DAT_143ba9d40;                             // 0x143ba9d40
unsigned int DAT_143ba9d48 = 0x0u;                              // 0x143ba9d48
const char* DAT_143ba9d50 = nullptr;                            // 0x143ba9d50
Unk_M2vCtx* DAT_143ba9d60;                                      // 0x143ba9d60
const char* DAT_143ba9d68 = nullptr;                            // 0x143ba9d68
alignas(16) unsigned char DAT_143ba9d70[0x40];                  // 0x143ba9d70
int DAT_143ba9db0;                                              // 0x143ba9db0
Unk_M2vCtx* DAT_143ba9db8;                                      // 0x143ba9db8
alignas(16) unsigned char DAT_143ba9dd0[0x400];                 // 0x143ba9dd0
alignas(16) unsigned char DAT_143baa1d0[0x400];                 // 0x143baa1d0
alignas(16) unsigned char DAT_143baa5d0[0x400];                 // 0x143baa5d0
alignas(16) unsigned char DAT_143baa9d0[0x400];                 // 0x143baa9d0
alignas(16) unsigned char DAT_143baadd0[0x400];                 // 0x143baadd0
alignas(16) unsigned char DAT_143bab1d0[0x400];                 // 0x143bab1d0
alignas(16) unsigned char DAT_143bab5d0[0x400];                 // 0x143bab5d0
alignas(16) unsigned char DAT_143bab9d0[0x400];                 // 0x143bab9d0
alignas(16) unsigned char DAT_143babdd0[0x8];                   // 0x143babdd0
alignas(8) unsigned char DAT_143babdd8[0x8];                    // 0x143babdd8
alignas(16) unsigned char DAT_143babde0[0x10];                  // 0x143babde0
alignas(16) unsigned char DAT_143babdf0[0x800];                 // 0x143babdf0
alignas(16) unsigned char DAT_143bac5f0[0x50];                  // 0x143bac5f0
alignas(16) unsigned char DAT_143bac640[0x8];                   // 0x143bac640
alignas(8) unsigned char DAT_143bac648[0x8];                    // 0x143bac648
alignas(16) unsigned char DAT_143bac650[0x8];                   // 0x143bac650
alignas(8) unsigned char DAT_143bac658[0x8];                    // 0x143bac658
alignas(16) unsigned char DAT_143bac660[0x8];                   // 0x143bac660
alignas(8) unsigned char DAT_143bac668[0x8];                    // 0x143bac668
alignas(16) unsigned char DAT_143bac670[0x8];                   // 0x143bac670
alignas(8) unsigned char DAT_143bac678[0x8];                    // 0x143bac678
alignas(16) unsigned char DAT_143bac680[0x10];                  // 0x143bac680
alignas(16) unsigned char DAT_143bac690[0x800];                 // 0x143bac690
alignas(16) unsigned char DAT_143bace90[0x800];                 // 0x143bace90
alignas(16) unsigned char DAT_143bad690[0x10];                  // 0x143bad690
alignas(16) unsigned char DAT_143bad6a0[0x8];                   // 0x143bad6a0
alignas(8) unsigned char DAT_143bad6a8[0x8];                    // 0x143bad6a8
alignas(16) unsigned char DAT_143bad6b0[0x180];                 // 0x143bad6b0
alignas(16) unsigned char DAT_143bad830[0x280];                 // 0x143bad830
alignas(16) unsigned char DAT_143badab0[0x50];                  // 0x143badab0
alignas(16) unsigned char DAT_143badb00[0x8];                   // 0x143badb00
alignas(8) unsigned char DAT_143badb08[0x8];                    // 0x143badb08
alignas(16) unsigned char DAT_143badb10[0x8];                   // 0x143badb10
alignas(8) unsigned char DAT_143badb18[0xc];                    // 0x143badb18
alignas(4) unsigned char DAT_143badb24[0x4];                    // 0x143badb24
alignas(8) unsigned char DAT_143badb28[0x8];                    // 0x143badb28
alignas(16) unsigned char DAT_143badb30[0x8];                   // 0x143badb30
alignas(8) unsigned char DAT_143badb38[0x8];                    // 0x143badb38
alignas(16) unsigned char DAT_143badb40[0x8];                   // 0x143badb40
alignas(8) unsigned char DAT_143badb48[0x8];                    // 0x143badb48
alignas(16) unsigned char DAT_143badb50[0x10];                  // 0x143badb50
alignas(16) unsigned char DAT_143badb60[0x4];                   // 0x143badb60
alignas(4) unsigned char DAT_143badb64[0x4];                    // 0x143badb64
alignas(8) unsigned char DAT_143badb68[0x1c];                   // 0x143badb68
alignas(4) unsigned char DAT_143badb84[0x4];                    // 0x143badb84
alignas(8) unsigned char DAT_143badb88[0x30];                   // 0x143badb88
alignas(8) unsigned char DAT_143badbb8[0x4];                    // 0x143badbb8
alignas(4) unsigned char DAT_143badbbc[0x20];                   // 0x143badbbc
alignas(4) unsigned char DAT_143badbdc[0x24];                   // 0x143badbdc
alignas(16) unsigned char DAT_143badc00[0x380];                 // 0x143badc00
alignas(16) unsigned char DAT_143badf80[0x9b160];               // 0x143badf80
Unk_PtrArray* DAT_143d6eab8;                                    // 0x143d6eab8
alignas(8) unsigned char DAT_143d6eb38[0x8];                    // 0x143d6eb38
alignas(16) unsigned char DAT_143d6eb40[0x8];                   // 0x143d6eb40
alignas(8) unsigned char DAT_143d6eb48[0x8];                    // 0x143d6eb48
alignas(16) unsigned char DAT_143d6eb50[0x8];                   // 0x143d6eb50
alignas(16) unsigned char DAT_143e64b00[0x8];                   // 0x143e64b00
alignas(8) unsigned char DAT_143e64b08[0x8];                    // 0x143e64b08
alignas(16) unsigned char DAT_143e64b10[0x8];                   // 0x143e64b10
alignas(8) unsigned char DAT_143e64b18[0x8];                    // 0x143e64b18
void* DAT_143e64b20;                                            // 0x143e64b20
alignas(8) unsigned char DAT_143e64b28[0x8];                    // 0x143e64b28
alignas(16) unsigned char DAT_143e64b30[0x8];                   // 0x143e64b30
alignas(8) unsigned char DAT_143e64b38[0x8];                    // 0x143e64b38
alignas(16) unsigned char DAT_143e64b40[0x8];                   // 0x143e64b40
alignas(8) unsigned char DAT_143e64b48[0x8];                    // 0x143e64b48
alignas(16) unsigned char DAT_143e64b50[0x8];                   // 0x143e64b50
alignas(8) unsigned char DAT_143e64b58[0x8];                    // 0x143e64b58
void* DAT_143e64b60;                                            // 0x143e64b60
alignas(8) unsigned char DAT_143e64b68[0x8];                    // 0x143e64b68
alignas(16) unsigned char DAT_143e64b70[0x8];                   // 0x143e64b70
alignas(8) unsigned char DAT_143e64b78[0x8];                    // 0x143e64b78
alignas(16) unsigned char DAT_143e64b80[0x8];                   // 0x143e64b80
alignas(8) unsigned char DAT_143e64b88[0x8];                    // 0x143e64b88
alignas(16) unsigned char DAT_143e64b90[0x8];                   // 0x143e64b90
alignas(8) unsigned char DAT_143e64b98[0x8];                    // 0x143e64b98
alignas(16) unsigned char DAT_143e64ba0[0x8];                   // 0x143e64ba0
alignas(8) unsigned char DAT_143e64ba8[0x18];                   // 0x143e64ba8
alignas(16) unsigned char DAT_143e64bc0[0x20];                  // 0x143e64bc0
alignas(16) unsigned char DAT_143e64be0[0x1];                   // 0x143e64be0
alignas(1) unsigned char DAT_143e64be1[0x1f];                   // 0x143e64be1
alignas(16) unsigned char DAT_143e64c00[0x1];                   // 0x143e64c00
alignas(1) unsigned char DAT_143e64c01[0x7ff];                  // 0x143e64c01
alignas(16) unsigned char DAT_143e65400[0x1];                   // 0x143e65400
alignas(1) unsigned char DAT_143e65401[0x400];                  // 0x143e65401
alignas(1) unsigned char DAT_143e65801[0x1];                    // 0x143e65801
alignas(2) unsigned char DAT_143e65802[0x1e];                   // 0x143e65802
alignas(16) unsigned char DAT_143e65820[0x1];                   // 0x143e65820
alignas(1) unsigned char DAT_143e65821[0xfff];                  // 0x143e65821
alignas(16) unsigned char DAT_143e66820[0x1];                   // 0x143e66820
alignas(1) unsigned char DAT_143e66821[0xf];                    // 0x143e66821
alignas(16) unsigned char DAT_143e66830[0x1];                   // 0x143e66830
alignas(1) unsigned char DAT_143e66831[0xf];                    // 0x143e66831
alignas(16) unsigned char DAT_143e66840[0x1];                   // 0x143e66840
alignas(1) unsigned char DAT_143e66841[0x7f];                   // 0x143e66841
alignas(16) unsigned char DAT_143e668c0[0x1];                   // 0x143e668c0
alignas(1) unsigned char DAT_143e668c1[0x1];                    // 0x143e668c1
alignas(2) unsigned char DAT_143e668c2[0x7fffe];                // 0x143e668c2

#pragma comment(linker, "/alternatename:?DAT_143aab428@@3V?$CAtlList@V?$MS2Ptr@VCAchieveData@@@@V?$CElementTraits@V?$MS2Ptr@VCAchieveData@@@@@ATL@@@ATL@@A=?DAT_143aab428@@3PAEA")
#pragma comment(linker, "/alternatename:?s_instance@Unk_CrashSingleton@@2PEAVCCrashManager@@EA=?DAT_143aac538@@3PEAXEA")
#pragma comment(linker, "/alternatename:?DAT_143aacc88@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143aacc88@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aacc90@@3V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@A=?DAT_143aacc90@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VGFxManager@@@@2PEAVGFxManager@@EA=?DAT_143aaccf8@@3PEAVUnk_AltStringMgr@@EA")
#pragma comment(linker, "/alternatename:?DAT_143aacd50@@3VQuestMask@@A=?DAT_143aacd50@@3PAEA")
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
#pragma comment(linker, "/alternatename:?DAT_143ab78e8@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143ab78e8@@3PAEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VCTriggerService@@@@2PEAVCTriggerService@@EA=?DAT_143ab9510@@3PEAVUnk_McEntityRules@@EA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VUISwfEntityManager@@@@2PEAVUISwfEntityManager@@EA=?DAT_143abb058@@3PEAVUISwfEntityManager@@EA")
#pragma comment(linker, "/alternatename:?g_strMaintenanceExit@@3V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@A=?DAT_143abf510@@3PAEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VCSoundService@@@@2PEAVCSoundService@@EA=?DAT_143abf890@@3PEAXEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VCSoundEventMgr@@@@2PEAVCSoundEventMgr@@EA=?DAT_143ac1928@@3PEAVUnk_SingletonObj@@EA")
#pragma comment(linker, "/alternatename:?g_spLoadingDialog@@3V?$MS2Ptr@VCLoadingDialog@@@@A=?DAT_143ac2bd0@@3PAEA")
#pragma comment(linker, "/alternatename:?g_workerPtr@@3VUnk_WorkerPtr@@A=?DAT_143ac2bd0@@3PAEA")
#pragma comment(linker, "/alternatename:?s_fTime@MultiSceneUpdater@@2MA=?DAT_143ac3d08@@3MA")
#pragma comment(linker, "/alternatename:?s_pfnCallback@MultiSceneUpdater@@2P6AXPEAXHIIPEAVNiBatchedUpdateProcess@@@ZEA=?DAT_143ac3d10@@3PAEA")
#pragma comment(linker, "/alternatename:?s_pCallbackContext@MultiSceneUpdater@@2PEAXEA=?DAT_143ac3d18@@3PEAXEA")
#pragma comment(linker, "/alternatename:?g_unkRewardSound@@3VUnk_RewardSound@@A=?DAT_143ac5988@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VUIAlignWidgetManager@@@@2PEAVUIAlignWidgetManager@@EA=?DAT_143ac5d88@@3PEAVUnk_140e45740@@EA")
#pragma comment(linker, "/alternatename:?DAT_143acf820@@3UUnk_CMISEntityRef@@A=?DAT_143acf820@@3PAEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VDecoEditService@@@@2PEAVDecoEditService@@EA=?DAT_143ad08c8@@3PEAXEA")
#pragma comment(linker, "/alternatename:?DAT_143ad2288@@3PADA=?DAT_143ad2288@@3PAEA")
#pragma comment(linker, "/alternatename:?g_strMeratLogDefault@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143ad76a8@@3PAEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VMS2LightService@@@@2PEAVMS2LightService@@EA=?DAT_143ad95f0@@3PEAXEA")
#pragma comment(linker, "/alternatename:?DAT_143adc208@@3PADA=?DAT_143adc208@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143adca50@@3UUnk_MagicTable@@A=?DAT_143adca50@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143add400@@3PAHA=?DAT_143add400@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143add400@@3PAIA=?DAT_143add400@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143adda48@@3UScreenSetting@MessengerData@@A=?DAT_143adda48@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae95e0@@3_NA=?DAT_143ae95e0@@3DA")
#pragma comment(linker, "/alternatename:?DAT_143ae95e1@@3_NA=?DAT_143ae95e1@@3DA")
#pragma comment(linker, "/alternatename:?DAT_143aea1b8@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143aea1b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aea1c0@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143aea1c0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aea1c8@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143aea1c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aea1d0@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143aea1d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aea1d8@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143aea1d8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aea1e0@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143aea1e0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143aef3b8@@3V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@A=?DAT_143aef3b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af1bc8@@3V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@A=?DAT_143af1bc8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af1c18@@3V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@A=?DAT_143af1c18@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af2258@@3V?$CAtlList@HV?$CElementTraits@H@ATL@@@ATL@@A=?DAT_143af2258@@3PAEA")
#pragma comment(linker, "/alternatename:?g_strFlavor@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143af37a0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af3e28@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143af3e28@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af3e30@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143af3e30@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af6008@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143af6008@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af62c0@@3V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@A=?DAT_143af62c0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af62d4@@3IA=?DAT_143af62d4@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143af62d8@@3IA=?DAT_143af62d8@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143af7d40@@3HA=?g_bAppActive@@3HA")
#pragma comment(linker, "/alternatename:?g_rcWindow@@3UtagRECT@@A=?DAT_143af7d48@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af7d58@@3HA=?g_143af7d58@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143af7e00@@3VUnk_UtilErrorDialog@@A=?DAT_143af7e00@@3PAEA")
#pragma comment(linker, "/alternatename:?g_dlgCrash@@3VUnk_CrashDialog@@A=?DAT_143af7f80@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af8278@@3VEntityID@egf@@A=?DAT_143af8278@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143af88e0@@3V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@A=?DAT_143af88e0@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_RTTI@MS2RenderListProcessor@@2VNiRTTI@@B=?DAT_143afa798@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afa7f0@@3V?$SmartPointer@VNiFogProperty@@@efd@@A=?DAT_143afa7f0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afb020@@3P6AXPEAVNiAVObject@@@ZEA=?DAT_143afb020@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afbb98@@3P6AXXZEA=?DAT_143afbb98@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afbba0@@3P6AXXZEA=?DAT_143afbba0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afbfb8@@3DA=?DAT_143afbfb8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afbfb8@@3VNiRTTI@@B=?DAT_143afbfb8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afbfc8@@3P6AXPEAVNiAVObject@@@ZEA=?DAT_143afbfc8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143afc898@@3EA=?DAT_143afc898@@3DA")
#pragma comment(linker, "/alternatename:?DAT_143afe6f8@@3P6A?AUUnk_MCPPtr@@PEAVNiVisibleArray@@PEAVNiSPWorkflowManager@@@ZEA=?DAT_143afe6f8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b023c0@@3P6AXXZEA=?DAT_143b023c0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b023c8@@3P6AH_K@ZEA=?DAT_143b023c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b03490@@3P6AXFEPEBD@ZEA=?DAT_143b03490@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b05980@@3P6A?AVutf8string@efd@@AEBV12@@ZEA=?DAT_143b05980@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3DA=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3EA=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3HA=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3UUnk_EntityAppFramework@@A=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3UUnk_FdFramework@@A=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3UUnk_FmFramework@@A=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3UUnk_TeFramework@@A=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3UUnk_TrgFramework@@A=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3UUnk_UgcFramework@@A=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3VUnk_CinFramework@@A=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3VUnk_GsAppG@@A=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b059e8@@3VUnk_WmFieldHolder@@A=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?g_143b059e8@@3VUnk_AppFramework@@A=?DAT_143b059e8@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VUniqueSwfIDCreator@@@@2PEAVUniqueSwfIDCreator@@EA=?DAT_143b0d2d8@@3PEAXEA")
#pragma comment(linker, "/alternatename:?DAT_143b0d330@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143b0d330@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b0d338@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143b0d338@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b0d340@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143b0d340@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b0d348@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143b0d348@@3PAEA")
#pragma comment(linker, "/alternatename:?s_nCaptureBlock@GFxService@@2HA=?DAT_143b0d360@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143b0d368@@3P6AXXZEA=?DAT_143b0d368@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b0d778@@3VCategory@efd@@B=?DAT_143b0d778@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VGFxAtlasCache@@@@2PEAVGFxAtlasCache@@EA=?DAT_143b0d780@@3PEAXEA")
#pragma comment(linker, "/alternatename:?DAT_143b0d790@@3P6APEAVFile@Scaleform@@V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@@ZEA=?DAT_143b0d790@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_strLocale@NiGFxLocalizeManager@@2V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143b0d798@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_kXmlLoader1@NiGFxLocalizeManager@@2V?$Delegate@$$A6A_NAEAVTiXmlDocument@@@Z@@A=?DAT_143b0d7a0@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_kXmlLoader2@NiGFxLocalizeManager@@2V?$Delegate@$$A6A_NAEAVTiXmlDocument@@@Z@@A=?DAT_143b0d7a8@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_kXmlLoader3@NiGFxLocalizeManager@@2V?$Delegate@$$A6A_NAEAVTiXmlDocument@@@Z@@A=?DAT_143b0d7b0@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_kXmlLoader4@NiGFxLocalizeManager@@2V?$Delegate@$$A6A_NAEAVTiXmlDocument@@@Z@@A=?DAT_143b0d7b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b0dc28@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143b0dc28@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143b0dc30@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143b0dc30@@3PAEA")
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
