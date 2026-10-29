// Data unit (sfr22; group 143ae0748 of work/sfr35/outside-units.tsv):
// exe globals of the .bss block below that no recovered TU defines (zero: the exe's raw .data ends at 0x143aab400).
// One definition per exe address (tools/datacheck.py checks address, size and initializer); the other names
// users declare at an address are mapped to it with /alternatename. Class objects are byte images up to the
// next known exe global; their constructors (the owning TU's .text$di initializer) are not run by this unit,
// see the zero-blob list in work/sfr22/outside-summary.md. A recovered owner moves a definition to its TU.
// The 117 constructed objects of this block (NiFixedString keys and arrays, NiRTTI, efd::ClassInfo, CString statics) are
// defined by their owners as DAT_<va> now, with their dynamic initializers; users' other names reach them via alias.py.
// The hook DLL binds every name to the exe's own global (symbols table), so nothing here is compiled into it
// (docs/RECOVERY.md sec. 9).
// MS2-UNIT: data_bss_143ae0748
// MS2-RANGE: 0x143ae0748-0x143ae5f80 .bss

#ifndef MS2_HOOK_DLL

class PostProcessingService;
class Unk_SingletonObj;

Unk_SingletonObj* DAT_143ae0748;                                // 0x143ae0748
bool DAT_143ae0ac0;                                             // 0x143ae0ac0
unsigned __int64 DAT_143ae0bd0 = 0x0ull;                        // 0x143ae0bd0
int DAT_143ae0dd0;                                              // 0x143ae0dd0
int DAT_143ae0fb0;                                              // 0x143ae0fb0
int DAT_143ae0fb4;                                              // 0x143ae0fb4
int DAT_143ae0fb8;                                              // 0x143ae0fb8
int DAT_143ae0fbc;                                              // 0x143ae0fbc
int g_nDebugUI;                                                 // 0x143ae0fc0
int DAT_143ae1f20;                                              // 0x143ae1f20
char DAT_143ae2848;                                             // 0x143ae2848: NM CNMStr<32> empty-string sentinel
char DAT_143ae2849;                                             // 0x143ae2849: NM CNMStr<2048> empty-string sentinel
char DAT_143ae28e8;                                             // 0x143ae28e8: NM CNMStr<1024> empty-string sentinel
char DAT_143ae28e9;                                             // 0x143ae28e9: NM CNMStr<64> empty-string sentinel
char DAT_143ae28ea;                                             // 0x143ae28ea: NM CNMStr<4096> empty-string sentinel
char DAT_143ae28eb;                                             // 0x143ae28eb: NM CNMStr<256> empty-string sentinel
char DAT_143ae28ec;                                             // 0x143ae28ec: NM CNMStr<9> empty-string sentinel
char DAT_143ae28ed;                                             // 0x143ae28ed: NM CNMStr<350> empty-string sentinel
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
alignas(16) unsigned char DAT_143ae37d0[0x1d0];                 // 0x143ae37d0
PostProcessingService* DAT_143ae4660;                           // 0x143ae4660
char DAT_143ae53d8;                                             // 0x143ae53d8

#pragma comment(linker, "/alternatename:?DAT_143ae2848@@3DB=?DAT_143ae2848@@3DA")
#pragma comment(linker, "/alternatename:?DAT_143ae2849@@3DB=?DAT_143ae2849@@3DA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VGFxService@@@@2PEAVGFxService@@EA=?DAT_143ae0748@@3PEAVUnk_SingletonObj@@EA")
#pragma comment(linker, "/alternatename:?DAT_143ae0fb0@@3IA=?DAT_143ae0fb0@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ae0fb8@@3IA=?DAT_143ae0fb8@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ae0fc0@@3HA=?g_nDebugUI@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ae2b34@@3DA=?DAT_143ae2b34@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ae2b38@@3DA=?DAT_143ae2b38@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ae2b38@@3HA=?DAT_143ae2b38@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ae2b38=?DAT_143ae2b38@@3PAEA")
#pragma comment(linker, "/alternatename:?ms_nModelCulling@COptimizer@@2HA=?DAT_143ae2b44@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ae37d0@@3PADA=?DAT_143ae37d0@@3PAEA")

#endif // MS2_HOOK_DLL
