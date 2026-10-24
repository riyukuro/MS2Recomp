// Data unit (sfr22; group 143ab1b14 of work/sfr35/outside-units.tsv): globals of the exe's .bss block below
// that no recovered TU defines. The exe's raw .data ends at 0x143aab400, so all of them start out zero.
// One definition per exe address (tools/datacheck.py checks address, size and initializer):
//  - scalars and pointers: the widest type their users declare, under the most meaningful name;
//  - class objects (CString, CAtlArray, std::map, the placeholder Unk_* tables ...): a zero blob up to the next
//    known exe global. Their constructors belong to the TU that owns them (its .text$di initializer), not
//    to this unit; a recovered owner moves the definition there and drops it here. The 26 of 0x143ab29d8-0x143ab3318
//    are defined as DAT_<va> by unit_1400be790_mixedheaderstatics and commonfiles/userproxy.cpp now (their
//    initializers run there, work/sfr22/fullexe-staticctors.md); users' other names reach them via tools/fullexe/alias.py.
// The other names users declare at an address are mapped with /alternatename. The hook DLL binds every name
// to the exe's own global (symbols table), so nothing here is compiled into it (docs/RECOVERY.md sec. 9).
// MS2-UNIT: data_bss_143ab1b14
// MS2-RANGE: 0x143ab1b14-0x143ab3da8 .bss

#ifndef MS2_HOOK_DLL

class Unk_AeFeatureMgr;

bool DAT_143ab1b14;                                     // 0x143ab1b14
long DAT_143ab2440;                                     // 0x143ab2440
__int64 DAT_143ab25e8;                                  // 0x143ab25e8
__int64 DAT_143ab2820;                                  // 0x143ab2820
__int64 DAT_143ab2828;                                  // 0x143ab2828
int DAT_143ab2830;                                      // 0x143ab2830
int DAT_143ab2834;                                      // 0x143ab2834
__int64 DAT_143ab2838;                                  // 0x143ab2838
__int64 DAT_143ab2840;                                  // 0x143ab2840
unsigned short DAT_143ab2848;                           // 0x143ab2848
unsigned char DAT_143ab284a;                            // 0x143ab284a
char DAT_143ab284b;                                     // 0x143ab284b
int DAT_143ab284c;                                      // 0x143ab284c
int DAT_143ab2850;                                      // 0x143ab2850
unsigned short DAT_143ab2854;                           // 0x143ab2854
unsigned char DAT_143ab2856;                            // 0x143ab2856
bool DAT_143ab2857;                                     // 0x143ab2857
int DAT_143ab2858;                                      // 0x143ab2858
int DAT_143ab285c;                                      // 0x143ab285c
int DAT_143ab2860;                                      // 0x143ab2860
int g_upperTargetId;                                    // 0x143ab2864
__int64 DAT_143ab2868;                                  // 0x143ab2868
int DAT_143ab2870;                                      // 0x143ab2870
int DAT_143ab2874;                                      // 0x143ab2874
int DAT_143ab2878;                                      // 0x143ab2878
int DAT_143ab287c;                                      // 0x143ab287c
int DAT_143ab2880;                                      // 0x143ab2880
int DAT_143ab2884;                                      // 0x143ab2884
int DAT_143ab2888;                                      // 0x143ab2888
int DAT_143ab288c;                                      // 0x143ab288c
int DAT_143ab2890;                                      // 0x143ab2890
__int64 DAT_143ab2898;                                  // 0x143ab2898
__int64 DAT_143ab28a0;                                  // 0x143ab28a0
__int64 DAT_143ab28a8;                                  // 0x143ab28a8
__int64 DAT_143ab28b0;                                  // 0x143ab28b0
__int64 DAT_143ab28b8;                                  // 0x143ab28b8
__int64 DAT_143ab28c0;                                  // 0x143ab28c0
__int64 DAT_143ab28c8;                                  // 0x143ab28c8
__int64 DAT_143ab28d0;                                  // 0x143ab28d0
__int64 DAT_143ab28d8;                                  // 0x143ab28d8
__int64 DAT_143ab28e0;                                  // 0x143ab28e0
__int64 DAT_143ab28e8;                                  // 0x143ab28e8
__int64 DAT_143ab28f0;                                  // 0x143ab28f0
__int64 DAT_143ab28f8;                                  // 0x143ab28f8
int DAT_143ab2900;                                      // 0x143ab2900
int DAT_143ab2904;                                      // 0x143ab2904
__int64 g_nShutdownTime;                                // 0x143ab2908
int g_socketClosing;                                    // 0x143ab2910
int DAT_143ab2914;                                      // 0x143ab2914
int DAT_143ab2918;                                      // 0x143ab2918
unsigned short DAT_143ab291c;                           // 0x143ab291c
bool DAT_143ab291e;                                     // 0x143ab291e
__int64 DAT_143ab2920;                                  // 0x143ab2920
__int64 DAT_143ab2928;                                  // 0x143ab2928
__int64 DAT_143ab2930;                                  // 0x143ab2930
__int64 DAT_143ab2938;                                  // 0x143ab2938
unsigned short DAT_143ab2940;                           // 0x143ab2940
bool DAT_143ab2942;                                     // 0x143ab2942
char DAT_143ab2943;                                     // 0x143ab2943
unsigned short DAT_143ab2944;                           // 0x143ab2944
char DAT_143ab2946;                                     // 0x143ab2946
bool DAT_143ab2947;                                     // 0x143ab2947
__int64 DAT_143ab2948;                                  // 0x143ab2948
int DAT_143ab2950;                                      // 0x143ab2950
int DAT_143ab2954;                                      // 0x143ab2954
__int64 DAT_143ab2958;                                  // 0x143ab2958
unsigned int DAT_143ab2960;                             // 0x143ab2960
unsigned short DAT_143ab2964;                           // 0x143ab2964
bool DAT_143ab2966;                                     // 0x143ab2966
__int64 DAT_143ab2968;                                  // 0x143ab2968
int DAT_143ab2970;                                      // 0x143ab2970
int DAT_143ab2974;                                      // 0x143ab2974
__int64 DAT_143ab2978;                                  // 0x143ab2978
__int64 DAT_143ab2980;                                  // 0x143ab2980
__int64 DAT_143ab2988;                                  // 0x143ab2988
void* DAT_143ab3910;                                    // 0x143ab3910
void* DAT_143ab3918;                                    // 0x143ab3918
Unk_AeFeatureMgr* DAT_143ab3da0;                        // 0x143ab3da0

#pragma comment(linker, "/alternatename:?ms_nCount@Cube@@2JA=?DAT_143ab2440@@3JA")
#pragma comment(linker, "/alternatename:?ms_pSingleton@?$SingletonClass@VGFxSceneService@@@@2PEAVGFxSceneService@@EA=?DAT_143ab25e8@@3_JA")
#pragma comment(linker, "/alternatename:?DAT_143ab2820@@3HA=?DAT_143ab2820@@3_JA")
#pragma comment(linker, "/alternatename:?DAT_143ab2828@@3_KA=?DAT_143ab2828@@3_JA")
#pragma comment(linker, "/alternatename:?DAT_143ab2830@@3IA=?DAT_143ab2830@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ab284b@@3EA=?DAT_143ab284b@@3DA")
#pragma comment(linker, "/alternatename:?DAT_143ab2864@@3HA=?g_upperTargetId@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ab2898@@3HA=?DAT_143ab2898@@3_JA")
#pragma comment(linker, "/alternatename:?DAT_143ab2910@@3HA=?g_socketClosing@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ab2914@@3IA=?DAT_143ab2914@@3HA")
#pragma comment(linker, "/alternatename:?DAT_143ab2930@@3HA=?DAT_143ab2930@@3_JA")
#pragma comment(linker, "/alternatename:?DAT_143ab2946@@3_NA=?DAT_143ab2946@@3DA")
#pragma comment(linker, "/alternatename:?DAT_143ab2970@@3IA=?DAT_143ab2970@@3HA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VEntityWorldManager@@@@2PEAVEntityWorldManager@@EA=?DAT_143ab3910@@3PEAXEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VCFunctionCubeService@@@@2PEAVCFunctionCubeService@@EA=?DAT_143ab3918@@3PEAXEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VPostProcessingService@@@@2PEAVPostProcessingService@@EA=?DAT_143ab3da0@@3PEAVUnk_AeFeatureMgr@@EA")

#endif // MS2_HOOK_DLL
