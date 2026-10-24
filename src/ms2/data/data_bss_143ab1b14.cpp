// Data unit (sfr22; group 143ab1b14 of work/sfr35/outside-units.tsv): globals of the exe's .bss block below
// that no recovered TU defines. The exe's raw .data ends at 0x143aab400, so all of them start out zero.
// One definition per exe address (tools/datacheck.py checks address, size and initializer):
//  - scalars and pointers: the widest type their users declare, under the most meaningful name;
//  - class objects (CString, CAtlArray, std::map, the placeholder Unk_* tables ...): a zero blob up to the next
//    known exe global. Their constructors belong to the TU that owns them (its .text$di initializer), not
//    to this unit; a recovered owner moves the definition there and drops it here.
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
alignas(8) unsigned char DAT_143ab29d8[0x50];           // 0x143ab29d8
alignas(8) unsigned char DAT_143ab2a28[0x8];            // 0x143ab2a28
alignas(16) unsigned char DAT_143ab2a30[0x10];          // 0x143ab2a30
alignas(16) unsigned char DAT_143ab2a40[0x8];           // 0x143ab2a40
alignas(8) unsigned char DAT_143ab2a48[0x8];            // 0x143ab2a48
alignas(8) unsigned char DAT_143ab2a58[0x20];           // 0x143ab2a58
alignas(8) unsigned char DAT_143ab2d78[0x8];            // 0x143ab2d78
alignas(16) unsigned char DAT_143ab2d80[0xa0];          // 0x143ab2d80
alignas(16) unsigned char DAT_143ab2e20[0x30];          // 0x143ab2e20
alignas(16) unsigned char DAT_143ab2e80[0x60];          // 0x143ab2e80
alignas(16) unsigned char DAT_143ab2fc0[0x50];          // 0x143ab2fc0
alignas(16) unsigned char DAT_143ab3010[0x48];          // 0x143ab3010
alignas(8) unsigned char DAT_143ab3058[0x20];           // 0x143ab3058
alignas(8) unsigned char DAT_143ab3078[0x20];           // 0x143ab3078
alignas(8) unsigned char DAT_143ab3098[0x20];           // 0x143ab3098
alignas(8) unsigned char DAT_143ab30b8[0x28];           // 0x143ab30b8
alignas(16) unsigned char DAT_143ab30e0[0x48];          // 0x143ab30e0
alignas(8) unsigned char DAT_143ab31e8[0x38];           // 0x143ab31e8
alignas(8) unsigned char DAT_143ab3268[0x20];           // 0x143ab3268
alignas(8) unsigned char DAT_143ab3288[0x30];           // 0x143ab3288
alignas(8) unsigned char DAT_143ab32b8[0x20];           // 0x143ab32b8
alignas(8) unsigned char DAT_143ab32d8[0x10];           // 0x143ab32d8
alignas(8) unsigned char DAT_143ab32e8[0x10];           // 0x143ab32e8
alignas(8) unsigned char DAT_143ab32f8[0x10];           // 0x143ab32f8
alignas(8) unsigned char DAT_143ab3308[0x10];           // 0x143ab3308
alignas(8) unsigned char DAT_143ab3318[0x10];           // 0x143ab3318
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
#pragma comment(linker, "/alternatename:?DAT_143ab29d8@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143ab29d8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2a28@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143ab2a28@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2a30@@3VUnk_InventoryCharacters@@A=?DAT_143ab2a30@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2a40@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143ab2a40@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2a48@@3V?$CStringT@DV?$StrTraitMFC_DLL@DV?$ChTraitsCRT@D@ATL@@@@@ATL@@A=?DAT_143ab2a48@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2a58@@3V?$CAtlArray@EV?$CElementTraits@E@ATL@@@ATL@@A=?DAT_143ab2a58@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2d78@@3V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@A=?DAT_143ab2d78@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2d80@@3DA=?DAT_143ab2d80@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2d80@@3PADA=?DAT_143ab2d80@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2d80@@3VUnk_MessageBoxStore@@A=?DAT_143ab2d80@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2d80@@3VUnk_Misc2d80@@A=?DAT_143ab2d80@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2d80@@3VUnk_SSGMisc2d80@@A=?DAT_143ab2d80@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2d80@@3VUnk_StModel@@A=?DAT_143ab2d80@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2e20@@3UUnk_ItemMgr@@A=?DAT_143ab2e20@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2e20@@3VCWarehouseItemTable@@A=?DAT_143ab2e20@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2e20@@3VUnk_CubeFallbackInventory@@A=?DAT_143ab2e20@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2e20@@3VUnk_MFurnInv@@A=?DAT_143ab2e20@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2e20@@3VUnk_Misc2e20@@A=?DAT_143ab2e20@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2e20@@3VUnk_MyPCGlobal2e20@@A=?DAT_143ab2e20@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2e20@@3VUnk_UgcCubeInventory@@A=?DAT_143ab2e20@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2e80@@3VUnk_TradeItemTable@@A=?DAT_143ab2e80@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2fc0@@3VUnk_CliEvtKeys@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2fc0@@3VUnk_GmEvtKey@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab2fc0@@3VUnk_NoticeList@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?g_attendTable@@3VUnk_AttendTable@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?g_galleryCounters@@3VUnk_GalleryCounters@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?g_gameEventUserValue@@3VGameEventUserValue@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?g_ltaTable@@3VUnk_LtaTable@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?g_rpsStrings@@3VUnk_RpsStringTable@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?g_snowmanStrings@@3VUnk_SnowmanStrings@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?g_unkTable@@3VUnk_Table@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?g_unkTableA@@3VUnk_DTTable@@A=?DAT_143ab2fc0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3010@@3VUnk_GmQuestRec@@A=?DAT_143ab3010@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3010@@3VUnk_NoticeList@@A=?DAT_143ab3010@@3PAEA")
#pragma comment(linker, "/alternatename:?g_stampTable@@3VUnk_AttendTable@@A=?DAT_143ab3010@@3PAEA")
#pragma comment(linker, "/alternatename:?g_trCounters@@3VUnk_TrCounters@@A=?DAT_143ab3010@@3PAEA")
#pragma comment(linker, "/alternatename:?g_unkTableB@@3VUnk_DTTable@@A=?DAT_143ab3010@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3058@@3UUnk_WsD_IdArray@@A=?DAT_143ab3058@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3058@@3V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@A=?DAT_143ab3058@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3058@@3VUnk_CcIdList@@A=?DAT_143ab3058@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3058@@3VUnk_IdList@@A=?DAT_143ab3058@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3058@@3VUnk_SSGIntList@@A=?DAT_143ab3058@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3078@@3UUnk_TaxiIdArray@@A=?DAT_143ab3078@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3078@@3V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@A=?DAT_143ab3078@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3078@@3VUnk_AkoTaxiList@@A=?DAT_143ab3078@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3078@@3VUnk_SSGIntList@@A=?DAT_143ab3078@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3098@@3UUnk_TaxiIdArray@@A=?DAT_143ab3098@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3098@@3VUnk_AkoTaxiList@@A=?DAT_143ab3098@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3098@@3VUnk_SSGIntList@@A=?DAT_143ab3098@@3PAEA")
#pragma comment(linker, "/alternatename:?g_aShutdownNoticed@@3V?$CAtlArray@HV?$CElementTraits@H@ATL@@@ATL@@A=?DAT_143ab30b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab30e0@@3V?$CAtlMap@IIV?$CElementTraits@I@ATL@@V12@@ATL@@A=?DAT_143ab30e0@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab31e8@@3V?$CRBMap@_JHV?$CElementTraits@_J@ATL@@V?$CElementTraits@H@2@@ATL@@A=?DAT_143ab31e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3268@@3V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@A=?DAT_143ab3268@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3268@@3VUnk_G9U32Arr@@A=?DAT_143ab3268@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3268@@3VUnk_IdList@@A=?DAT_143ab3268@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3268@@3VUnk_NametagTitles@@A=?DAT_143ab3268@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3288@@3V?$CRBMap@UUnk_MyPCPortalKey@@V?$MS2Ptr@VUnk_MyPCPortalLock@@@@V?$CElementTraits@UUnk_MyPCPortalKey@@@ATL@@V?$CElementTraits@V?$MS2Ptr@VUnk_MyPCPortalLock@@@@@4@@ATL@@A=?DAT_143ab3288@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab32b8@@3V?$CAtlArray@IV?$CElementTraits@I@ATL@@@ATL@@A=?DAT_143ab32b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab32b8@@3VUnk_MHouseSet@@A=?DAT_143ab32b8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab32d8@@3V?$set@UUnk_SSGHouseKey@@U?$less@UUnk_SSGHouseKey@@@std@@V?$allocator@UUnk_SSGHouseKey@@@3@@std@@A=?DAT_143ab32d8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab32d8@@3VUnk_Misc32d8@@A=?DAT_143ab32d8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab32e8@@3VUnk_SSGCountMapMap@@A=?DAT_143ab32e8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab32f8@@3VUnk_SSGCountMap@@A=?DAT_143ab32f8@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3308@@3V?$set@IU?$less@I@std@@V?$allocator@I@2@@std@@A=?DAT_143ab3308@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3308@@3VUnk_GmEvtKey@@A=?DAT_143ab3308@@3PAEA")
#pragma comment(linker, "/alternatename:?g_unkClaimed@@3VUnk_ALClaimed@@A=?DAT_143ab3308@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_143ab3318@@3V?$map@IVCAdventureLevelMissionData@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVCAdventureLevelMissionData@@@std@@@3@@std@@A=?DAT_143ab3318@@3PAEA")
#pragma comment(linker, "/alternatename:?g_unkMissionStates@@3V?$map@IVUnk_ALMissionState@@U?$less@I@std@@V?$allocator@U?$pair@$$CBIVUnk_ALMissionState@@@std@@@3@@std@@A=?DAT_143ab3318@@3PAEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VEntityWorldManager@@@@2PEAVEntityWorldManager@@EA=?DAT_143ab3910@@3PEAXEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VCFunctionCubeService@@@@2PEAVCFunctionCubeService@@EA=?DAT_143ab3918@@3PEAXEA")
#pragma comment(linker, "/alternatename:?s_instance@?$TSingleton@VPostProcessingService@@@@2PEAVPostProcessingService@@EA=?DAT_143ab3da0@@3PEAVUnk_AeFeatureMgr@@EA")

#endif // MS2_HOOK_DLL
