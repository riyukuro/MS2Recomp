// Data unit (sfr22; group 143ae0748 of work/sfr35/outside-units.tsv):
// exe globals of the .bss block below that no recovered TU defines (zero: the exe's raw .data ends at 0x143aab400).
// One definition per exe address (tools/datacheck.py checks address, size and initializer); the other names
// users declare at an address are mapped to it with /alternatename. Class objects are byte images up to the
// next known exe global; their constructors (the owning TU's .text$di initializer) are not run by this unit,
// see the zero-blob list in work/sfr22/outside-summary.md. A recovered owner moves a definition to its TU.
// The hook DLL binds every name to the exe's own global (symbols table), so nothing here is compiled into it
// (docs/RECOVERY.md sec. 9).
// MS2-UNIT: data_bss_143ae0748
// MS2-RANGE: 0x143ae0748-0x143ae5f80 .bss

#ifndef MS2_HOOK_DLL

class PostProcessingService;
class Unk_SingletonObj;

Unk_SingletonObj* DAT_143ae0748;                                // 0x143ae0748
bool DAT_143ae0ac0;                                             // 0x143ae0ac0
alignas(8) unsigned char DAT_143ae0ad8[0xb0];                   // 0x143ae0ad8
unsigned __int64 DAT_143ae0bd0 = 0x0ull;                        // 0x143ae0bd0
int DAT_143ae0dd0;                                              // 0x143ae0dd0
int DAT_143ae0fb0;                                              // 0x143ae0fb0
int DAT_143ae0fb4;                                              // 0x143ae0fb4
int DAT_143ae0fb8;                                              // 0x143ae0fb8
int DAT_143ae0fbc;                                              // 0x143ae0fbc
int g_nDebugUI;                                                 // 0x143ae0fc0
alignas(8) unsigned char DAT_143ae10a8[0x8];                    // 0x143ae10a8
alignas(8) unsigned char DAT_143ae14b8[0x10];                   // 0x143ae14b8
alignas(8) unsigned char DAT_143ae14c8[0x118];                  // 0x143ae14c8
int DAT_143ae1f20;                                              // 0x143ae1f20
int DAT_143ae2960;                                              // 0x143ae2960
int DAT_143ae2b30;                                              // 0x143ae2b30
int DAT_143ae2b34;                                              // 0x143ae2b34
alignas(8) unsigned char DAT_143ae2b38[0x4];                    // 0x143ae2b38
int DAT_143ae2b3c;                                              // 0x143ae2b3c
int DAT_143ae2b40;                                              // 0x143ae2b40
int DAT_143ae2b44;                                              // 0x143ae2b44
int DAT_143ae2b48;                                              // 0x143ae2b48
int DAT_143ae2b4c;                                              // 0x143ae2b4c
int DAT_143ae2b50;                                              // 0x143ae2b50
int DAT_143ae2b54;                                              // 0x143ae2b54
int DAT_143ae2b58;                                              // 0x143ae2b58
int DAT_143ae2bf8;                                              // 0x143ae2bf8
alignas(8) unsigned char DAT_143ae2de8[0x38];                   // 0x143ae2de8
alignas(16) unsigned char DAT_143ae2e20[0x4a8];                 // 0x143ae2e20
alignas(8) unsigned char DAT_143ae32c8[0x8];                    // 0x143ae32c8
alignas(16) unsigned char DAT_143ae37d0[0x1d0];                 // 0x143ae37d0
PostProcessingService* DAT_143ae4660;                           // 0x143ae4660
alignas(16) unsigned char DAT_143ae50a0[0x8];                   // 0x143ae50a0
alignas(8) unsigned char DAT_143ae50a8[0x8];                    // 0x143ae50a8
alignas(16) unsigned char DAT_143ae50b0[0x8];                   // 0x143ae50b0
alignas(8) unsigned char DAT_143ae50b8[0x8];                    // 0x143ae50b8
alignas(16) unsigned char DAT_143ae50c0[0x8];                   // 0x143ae50c0
alignas(8) unsigned char DAT_143ae50c8[0x8];                    // 0x143ae50c8
alignas(16) unsigned char DAT_143ae50d0[0x8];                   // 0x143ae50d0
alignas(8) unsigned char DAT_143ae50d8[0x8];                    // 0x143ae50d8
alignas(16) unsigned char DAT_143ae50e0[0x8];                   // 0x143ae50e0
alignas(8) unsigned char DAT_143ae50e8[0x8];                    // 0x143ae50e8
alignas(8) unsigned char DAT_143ae50f8[0x8];                    // 0x143ae50f8
alignas(16) unsigned char DAT_143ae5100[0x8];                   // 0x143ae5100
alignas(8) unsigned char DAT_143ae5108[0x8];                    // 0x143ae5108
alignas(16) unsigned char DAT_143ae5110[0x8];                   // 0x143ae5110
alignas(8) unsigned char DAT_143ae5118[0x8];                    // 0x143ae5118
alignas(16) unsigned char DAT_143ae5120[0x8];                   // 0x143ae5120
alignas(8) unsigned char DAT_143ae5128[0x8];                    // 0x143ae5128
alignas(16) unsigned char DAT_143ae5130[0x8];                   // 0x143ae5130
alignas(8) unsigned char DAT_143ae5138[0x8];                    // 0x143ae5138
alignas(16) unsigned char DAT_143ae5140[0x8];                   // 0x143ae5140
alignas(8) unsigned char DAT_143ae5158[0x8];                    // 0x143ae5158
alignas(16) unsigned char DAT_143ae5160[0x8];                   // 0x143ae5160
alignas(8) unsigned char DAT_143ae5168[0x8];                    // 0x143ae5168
alignas(16) unsigned char DAT_143ae5170[0x8];                   // 0x143ae5170
alignas(8) unsigned char DAT_143ae5178[0x8];                    // 0x143ae5178
alignas(16) unsigned char DAT_143ae5180[0x8];                   // 0x143ae5180
alignas(8) unsigned char DAT_143ae5188[0x8];                    // 0x143ae5188
alignas(16) unsigned char DAT_143ae5190[0x8];                   // 0x143ae5190
alignas(8) unsigned char DAT_143ae5198[0x8];                    // 0x143ae5198
alignas(8) unsigned char DAT_143ae51a8[0x8];                    // 0x143ae51a8
alignas(16) unsigned char DAT_143ae51b0[0x8];                   // 0x143ae51b0
alignas(8) unsigned char DAT_143ae51b8[0x8];                    // 0x143ae51b8
alignas(16) unsigned char DAT_143ae51c0[0x8];                   // 0x143ae51c0
alignas(8) unsigned char DAT_143ae51c8[0x8];                    // 0x143ae51c8
alignas(16) unsigned char DAT_143ae51e0[0x8];                   // 0x143ae51e0
alignas(8) unsigned char DAT_143ae51e8[0x8];                    // 0x143ae51e8
alignas(16) unsigned char DAT_143ae51f0[0x8];                   // 0x143ae51f0
alignas(16) unsigned char DAT_143ae5200[0x8];                   // 0x143ae5200
alignas(8) unsigned char DAT_143ae5218[0x8];                    // 0x143ae5218
alignas(16) unsigned char DAT_143ae5220[0x8];                   // 0x143ae5220
alignas(8) unsigned char DAT_143ae5228[0x8];                    // 0x143ae5228
alignas(16) unsigned char DAT_143ae5230[0x8];                   // 0x143ae5230
alignas(16) unsigned char DAT_143ae5240[0x8];                   // 0x143ae5240
alignas(8) unsigned char DAT_143ae5248[0x8];                    // 0x143ae5248
alignas(16) unsigned char DAT_143ae5250[0x8];                   // 0x143ae5250
alignas(8) unsigned char DAT_143ae5258[0x8];                    // 0x143ae5258
alignas(16) unsigned char DAT_143ae5260[0x8];                   // 0x143ae5260
alignas(8) unsigned char DAT_143ae5268[0x8];                    // 0x143ae5268
alignas(16) unsigned char DAT_143ae5270[0x8];                   // 0x143ae5270
alignas(8) unsigned char DAT_143ae5278[0x8];                    // 0x143ae5278
alignas(16) unsigned char DAT_143ae5280[0x8];                   // 0x143ae5280
alignas(8) unsigned char DAT_143ae5288[0x8];                    // 0x143ae5288
alignas(16) unsigned char DAT_143ae5290[0x8];                   // 0x143ae5290
alignas(8) unsigned char DAT_143ae5298[0x8];                    // 0x143ae5298
alignas(16) unsigned char DAT_143ae52a0[0x8];                   // 0x143ae52a0
alignas(8) unsigned char DAT_143ae52a8[0x8];                    // 0x143ae52a8
alignas(16) unsigned char DAT_143ae52b0[0x8];                   // 0x143ae52b0
alignas(8) unsigned char DAT_143ae52b8[0x8];                    // 0x143ae52b8
alignas(16) unsigned char DAT_143ae52c0[0x8];                   // 0x143ae52c0
alignas(16) unsigned char DAT_143ae52d0[0x8];                   // 0x143ae52d0
alignas(8) unsigned char DAT_143ae52d8[0x8];                    // 0x143ae52d8
alignas(16) unsigned char DAT_143ae52e0[0x18];                  // 0x143ae52e0
alignas(8) unsigned char DAT_143ae52f8[0x8];                    // 0x143ae52f8
alignas(16) unsigned char DAT_143ae5300[0x8];                   // 0x143ae5300
alignas(8) unsigned char DAT_143ae5308[0x8];                    // 0x143ae5308
alignas(16) unsigned char DAT_143ae5310[0x8];                   // 0x143ae5310
alignas(8) unsigned char DAT_143ae5318[0x8];                    // 0x143ae5318
alignas(16) unsigned char DAT_143ae5320[0x8];                   // 0x143ae5320
alignas(8) unsigned char DAT_143ae5328[0x8];                    // 0x143ae5328
alignas(16) unsigned char DAT_143ae5330[0x8];                   // 0x143ae5330
alignas(8) unsigned char DAT_143ae5338[0x8];                    // 0x143ae5338
alignas(16) unsigned char DAT_143ae5340[0x8];                   // 0x143ae5340
alignas(8) unsigned char DAT_143ae5348[0x8];                    // 0x143ae5348
alignas(16) unsigned char DAT_143ae5350[0x8];                   // 0x143ae5350
alignas(8) unsigned char DAT_143ae5358[0x8];                    // 0x143ae5358
alignas(16) unsigned char DAT_143ae5360[0x8];                   // 0x143ae5360
alignas(8) unsigned char DAT_143ae5368[0x8];                    // 0x143ae5368
alignas(16) unsigned char DAT_143ae5370[0x8];                   // 0x143ae5370
alignas(8) unsigned char DAT_143ae5378[0x8];                    // 0x143ae5378
alignas(16) unsigned char DAT_143ae5380[0x8];                   // 0x143ae5380
alignas(8) unsigned char DAT_143ae5388[0x8];                    // 0x143ae5388
alignas(16) unsigned char DAT_143ae5390[0x8];                   // 0x143ae5390
alignas(8) unsigned char DAT_143ae5398[0x8];                    // 0x143ae5398
alignas(16) unsigned char DAT_143ae53a0[0x8];                   // 0x143ae53a0
alignas(8) unsigned char DAT_143ae53a8[0x8];                    // 0x143ae53a8
alignas(16) unsigned char DAT_143ae53b0[0x8];                   // 0x143ae53b0
alignas(8) unsigned char DAT_143ae53b8[0x8];                    // 0x143ae53b8
alignas(16) unsigned char DAT_143ae53c0[0x8];                   // 0x143ae53c0
alignas(8) unsigned char DAT_143ae53c8[0x8];                    // 0x143ae53c8
alignas(16) unsigned char DAT_143ae53d0[0x8];                   // 0x143ae53d0
char DAT_143ae53d8;                                             // 0x143ae53d8
alignas(16) unsigned char DAT_143ae53e0[0x8];                   // 0x143ae53e0
alignas(8) unsigned char DAT_143ae53e8[0x8];                    // 0x143ae53e8
alignas(16) unsigned char DAT_143ae53f0[0x8];                   // 0x143ae53f0
alignas(8) unsigned char DAT_143ae53f8[0x8];                    // 0x143ae53f8
alignas(16) unsigned char DAT_143ae5400[0x8];                   // 0x143ae5400
alignas(8) unsigned char DAT_143ae5408[0x8];                    // 0x143ae5408
alignas(16) unsigned char DAT_143ae5410[0x8];                   // 0x143ae5410
alignas(8) unsigned char DAT_143ae5418[0x8];                    // 0x143ae5418
alignas(16) unsigned char DAT_143ae5420[0x8];                   // 0x143ae5420
alignas(8) unsigned char DAT_143ae5428[0x8];                    // 0x143ae5428
alignas(16) unsigned char DAT_143ae5430[0x8];                   // 0x143ae5430
alignas(8) unsigned char DAT_143ae5438[0x8];                    // 0x143ae5438
alignas(16) unsigned char DAT_143ae5440[0x8];                   // 0x143ae5440
alignas(8) unsigned char DAT_143ae5448[0x8];                    // 0x143ae5448
alignas(16) unsigned char DAT_143ae5450[0x8];                   // 0x143ae5450
alignas(8) unsigned char DAT_143ae5458[0x8];                    // 0x143ae5458
alignas(16) unsigned char DAT_143ae5460[0x8];                   // 0x143ae5460
alignas(8) unsigned char DAT_143ae5468[0x8];                    // 0x143ae5468
alignas(16) unsigned char DAT_143ae5470[0x870];                 // 0x143ae5470
alignas(16) unsigned char DAT_143ae5ce0[0x2a0];                 // 0x143ae5ce0

#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VGFxService@@@@2PEAVGFxService@@EA=?DAT_143ae0748@@3PEAVUnk_SingletonObj@@EA")
#pragma comment(linker, "/alternatename:?ms_RTTI@MS2OuterGlowMaterialSwapProcessor@@2VNiRTTI@@B=?DAT_143ae0ad8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae0fb0@@3IA=?DAT_143ae0fb0@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ae0fb8@@3IA=?DAT_143ae0fb8@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ae0fc0@@3HA=?g_nDebugUI@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ae10a8@@3VUnk_MyPCNoticeSound@@A=?DAT_143ae10a8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae14b8@@3VUnk_MyPCNoticeSound@@A=?DAT_143ae14b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae14c8@@3VUnk_MyPCNoticeSound@@A=?DAT_143ae14c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae2b34@@3DA=?DAT_143ae2b34@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ae2b38@@3DA=?DAT_143ae2b38@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae2b38@@3HA=?DAT_143ae2b38@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ae2b38=?DAT_143ae2b38@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_nModelCulling@COptimizer@@2HA=?DAT_143ae2b44@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ae2de8@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143ae2de8@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_ClassInfo@PC@@2VClassInfo@efd@@B=?DAT_143ae2e20@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae32c8@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143ae32c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae37d0@@3PADA=?DAT_143ae37d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50a0@@3VNiFixedString@@A=?DAT_143ae50a0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50a8@@3VNiFixedString@@A=?DAT_143ae50a8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50b0@@3VNiFixedString@@A=?DAT_143ae50b0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50b8@@3VNiFixedString@@A=?DAT_143ae50b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50c0@@3VNiFixedString@@A=?DAT_143ae50c0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50c8@@3DA=?DAT_143ae50c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50c8@@3VNiFixedString@@A=?DAT_143ae50c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50c8@@3VNiFixedString@@B=?DAT_143ae50c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50d0@@3DA=?DAT_143ae50d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50d0@@3VNiFixedString@@A=?DAT_143ae50d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50d0@@3VNiFixedString@@B=?DAT_143ae50d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50d8@@3DA=?DAT_143ae50d8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50d8@@3VNiFixedString@@A=?DAT_143ae50d8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50d8@@3VNiFixedString@@B=?DAT_143ae50d8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50e0@@3DA=?DAT_143ae50e0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50e0@@3VNiFixedString@@A=?DAT_143ae50e0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50e8@@3DA=?DAT_143ae50e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50e8@@3VNiFixedString@@A=?DAT_143ae50e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50f8@@3DA=?DAT_143ae50f8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50f8@@3VNiFixedString@@A=?DAT_143ae50f8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae50f8@@3VNiFixedString@@B=?DAT_143ae50f8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5100@@3VNiFixedString@@A=?DAT_143ae5100@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5100@@3VNiFixedString@@B=?DAT_143ae5100@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5108@@3VNiFixedString@@A=?DAT_143ae5108@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5108@@3VNiFixedString@@B=?DAT_143ae5108@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5110@@3VNiFixedString@@A=?DAT_143ae5110@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5110@@3VNiFixedString@@B=?DAT_143ae5110@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5118@@3VNiFixedString@@A=?DAT_143ae5118@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5120@@3VNiFixedString@@A=?DAT_143ae5120@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5128@@3VNiFixedString@@A=?DAT_143ae5128@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5130@@3VNiFixedString@@A=?DAT_143ae5130@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5138@@3VNiFixedString@@A=?DAT_143ae5138@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5140@@3VNiFixedString@@A=?DAT_143ae5140@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5158@@3VNiFixedString@@A=?DAT_143ae5158@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5160@@3VNiFixedString@@A=?DAT_143ae5160@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5168@@3VNiFixedString@@A=?DAT_143ae5168@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5170@@3VNiFixedString@@A=?DAT_143ae5170@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5178@@3DA=?DAT_143ae5178@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5178@@3VNiFixedString@@A=?DAT_143ae5178@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5180@@3VNiFixedString@@A=?DAT_143ae5180@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5188@@3VNiFixedString@@A=?DAT_143ae5188@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5190@@3DA=?DAT_143ae5190@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5190@@3VNiFixedString@@A=?DAT_143ae5190@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5198@@3DA=?DAT_143ae5198@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5198@@3VNiFixedString@@A=?DAT_143ae5198@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51a8@@3DA=?DAT_143ae51a8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51a8@@3VNiFixedString@@A=?DAT_143ae51a8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51b0@@3VNiFixedString@@A=?DAT_143ae51b0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51b8@@3DA=?DAT_143ae51b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51b8@@3VNiFixedString@@A=?DAT_143ae51b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51c0@@3VNiFixedString@@A=?DAT_143ae51c0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51c8@@3VNiFixedString@@A=?DAT_143ae51c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51e0@@3VNiFixedString@@A=?DAT_143ae51e0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51e8@@3DA=?DAT_143ae51e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51e8@@3VNiFixedString@@A=?DAT_143ae51e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae51f0@@3VNiFixedString@@A=?DAT_143ae51f0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5200@@3DA=?DAT_143ae5200@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5200@@3VNiFixedString@@A=?DAT_143ae5200@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5200@@3VNiFixedString@@B=?DAT_143ae5200@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5218@@3VNiFixedString@@A=?DAT_143ae5218@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5220@@3VNiFixedString@@A=?DAT_143ae5220@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5228@@3VNiFixedString@@A=?DAT_143ae5228@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5230@@3VNiFixedString@@A=?DAT_143ae5230@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5240@@3VNiFixedString@@A=?DAT_143ae5240@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5248@@3VNiFixedString@@A=?DAT_143ae5248@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5250@@3VNiFixedString@@A=?DAT_143ae5250@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5258@@3VNiFixedString@@A=?DAT_143ae5258@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5260@@3VNiFixedString@@A=?DAT_143ae5260@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5268@@3VNiFixedString@@A=?DAT_143ae5268@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5270@@3VNiFixedString@@A=?DAT_143ae5270@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5278@@3DA=?DAT_143ae5278@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5278@@3VNiFixedString@@A=?DAT_143ae5278@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5280@@3VNiFixedString@@A=?DAT_143ae5280@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5288@@3VNiFixedString@@A=?DAT_143ae5288@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5290@@3VNiFixedString@@A=?DAT_143ae5290@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5290@@3VNiFixedString@@B=?DAT_143ae5290@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5298@@3VNiFixedString@@A=?DAT_143ae5298@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5298@@3VNiFixedString@@B=?DAT_143ae5298@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52a0@@3VNiFixedString@@A=?DAT_143ae52a0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52a0@@3VNiFixedString@@B=?DAT_143ae52a0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52a8@@3VNiFixedString@@A=?DAT_143ae52a8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52b0@@3VNiFixedString@@A=?DAT_143ae52b0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52b8@@3VNiFixedString@@A=?DAT_143ae52b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52c0@@3VNiFixedString@@A=?DAT_143ae52c0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52d0@@3VNiFixedString@@A=?DAT_143ae52d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52d8@@3VNiFixedString@@A=?DAT_143ae52d8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52e0@@3DA=?DAT_143ae52e0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52e0@@3VNiFixedString@@A=?DAT_143ae52e0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae52f8@@3VNiFixedString@@A=?DAT_143ae52f8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5300@@3VNiFixedString@@A=?DAT_143ae5300@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5308@@3VNiFixedString@@A=?DAT_143ae5308@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5310@@3VNiFixedString@@A=?DAT_143ae5310@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5318@@3VNiFixedString@@A=?DAT_143ae5318@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5320@@3DA=?DAT_143ae5320@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5320@@3VNiFixedString@@A=?DAT_143ae5320@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5328@@3VNiFixedString@@A=?DAT_143ae5328@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5330@@3VNiFixedString@@A=?DAT_143ae5330@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5338@@3VNiFixedString@@A=?DAT_143ae5338@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5340@@3VNiFixedString@@A=?DAT_143ae5340@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5348@@3VNiFixedString@@A=?DAT_143ae5348@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5350@@3VNiFixedString@@A=?DAT_143ae5350@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5358@@3VNiFixedString@@A=?DAT_143ae5358@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5360@@3VNiFixedString@@A=?DAT_143ae5360@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5368@@3VNiFixedString@@A=?DAT_143ae5368@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5370@@3VNiFixedString@@A=?DAT_143ae5370@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5378@@3VNiFixedString@@A=?DAT_143ae5378@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5380@@3VNiFixedString@@A=?DAT_143ae5380@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5388@@3VNiFixedString@@A=?DAT_143ae5388@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5390@@3VNiFixedString@@A=?DAT_143ae5390@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5398@@3VNiFixedString@@A=?DAT_143ae5398@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53a0@@3VNiFixedString@@A=?DAT_143ae53a0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53a8@@3DA=?DAT_143ae53a8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53a8@@3VNiFixedString@@A=?DAT_143ae53a8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53b0@@3DA=?DAT_143ae53b0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53b0@@3VNiFixedString@@A=?DAT_143ae53b0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53b8@@3DA=?DAT_143ae53b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53b8@@3VNiFixedString@@A=?DAT_143ae53b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53c0@@3DA=?DAT_143ae53c0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53c0@@3VNiFixedString@@A=?DAT_143ae53c0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53c0@@3_NA=?DAT_143ae53c0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53c8@@3DA=?DAT_143ae53c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53c8@@3VNiFixedString@@A=?DAT_143ae53c8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53d0@@3VNiFixedString@@A=?DAT_143ae53d0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53e0@@3VNiFixedString@@A=?DAT_143ae53e0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53e8@@3VNiFixedString@@A=?DAT_143ae53e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53f0@@3VNiFixedString@@A=?DAT_143ae53f0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae53f8@@3VNiFixedString@@A=?DAT_143ae53f8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5400@@3VNiFixedString@@A=?DAT_143ae5400@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5408@@3VNiFixedString@@A=?DAT_143ae5408@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5410@@3VNiFixedString@@A=?DAT_143ae5410@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5418@@3VNiFixedString@@A=?DAT_143ae5418@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5420@@3VNiFixedString@@A=?DAT_143ae5420@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5428@@3VNiFixedString@@A=?DAT_143ae5428@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5430@@3VNiFixedString@@A=?DAT_143ae5430@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5438@@3VNiFixedString@@A=?DAT_143ae5438@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5440@@3VNiFixedString@@A=?DAT_143ae5440@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5448@@3VNiFixedString@@A=?DAT_143ae5448@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5450@@3VNiFixedString@@A=?DAT_143ae5450@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5458@@3VNiFixedString@@A=?DAT_143ae5458@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5460@@3VNiFixedString@@A=?DAT_143ae5460@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5468@@3VNiFixedString@@A=?DAT_143ae5468@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5470@@3PAY0BO@VNiFixedString@@A=?DAT_143ae5470@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae5ce0@@3PAVNiFixedString@@A=?DAT_143ae5ce0@@3PAEA")

#endif // MS2_HOOK_DLL
