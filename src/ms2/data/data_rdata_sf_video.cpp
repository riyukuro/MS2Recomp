// Data unit (sfr33, tools/datagen/gen_data_unit.py; group sfr33v):
// exe globals of the .rdata block below that no recovered TU defines, initialized with the exe's values.
// One definition per exe address (tools/datacheck.py checks address, size and initializer); the other names
// users declare at an address are mapped to it with /alternatename. Class objects are byte images up to the
// next known exe global; their constructors (the owning TU's .text$di initializer) are not run by this unit,
// see the zero-blob list in work/sfr22/outside-summary.md. A recovered owner moves a definition to its TU.
// The hook DLL binds every name to the exe's own global (symbols table), so nothing here is compiled into it
// (docs/RECOVERY.md sec. 9).
// MS2-UNIT: data_rdata_sf_video
// MS2-RANGE: 0x1431b4be0-0x1431b5408 .rdata

#ifndef MS2_HOOK_DLL

extern unsigned char DAT_140002b00[];
extern unsigned char DAT_140007de0[];
extern unsigned char DAT_140007df0[];
extern unsigned char DAT_140007e00[];
extern unsigned char DAT_140009f10[];
extern unsigned char DAT_14000a3a0[];
extern unsigned char DAT_14000a770[];
extern unsigned char DAT_142300840[];
extern unsigned char DAT_14280ef52[];
extern unsigned char DAT_142956ca0[];
extern unsigned char DAT_14298cc70[];
void FUN_140002b30();
void FUN_140002bb0();
void FUN_140002c10();
void FUN_140002cc0();
void FUN_140002d20();
void FUN_14000a880();

#pragma pack(push, 1)
struct Sd_1431b4be0 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
    const void* p30;
    const void* p38;
    const void* p40;
    const void* p48;
    const void* p50;
    const void* p58;
    const void* p60;
    const void* p68;
    const void* p70;
    const void* p78;
};
struct Sd_1431b4c60 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
    const void* p30;
    const void* p38;
    const void* p40;
    const void* p48;
    const void* p50;
    const void* p58;
    const void* p60;
    const void* p68;
    const void* p70;
    unsigned char b78[0x8];
};
struct Sd_1431b53c0 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
    const void* p30;
    const void* p38;
    const void* p40;
};
#pragma pack(pop)

// 0x1431b4be0
alignas(16) Sd_1431b4be0 DAT_1431b4be0 = {
    (const void*)&FUN_140002c10,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_140002b00,
    DAT_142300840,
    DAT_14280ef52,
    DAT_14280ef52,
    (const void*)&FUN_140002b30,
    (const void*)&FUN_140002bb0,
    (const void*)&FUN_140002cc0,
};
// 0x1431b4c60
alignas(16) Sd_1431b4c60 DAT_1431b4c60 = {
    (const void*)&FUN_140002d20,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    {0},
};
// 0x1431b53c0
alignas(16) Sd_1431b53c0 DAT_1431b53c0 = {
    DAT_14000a770,
    DAT_14000a3a0,
    (const void*)&FUN_14000a880,
    DAT_14298cc70,
    DAT_142956ca0,
    DAT_140009f10,
    DAT_140007df0,
    DAT_140007de0,
    DAT_140007e00,
};

#pragma comment(linker, "/alternatename:?DAT_1431b4be0@@3PAEA=?DAT_1431b4be0@@3USd_1431b4be0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b4be0@@3PEAXEA=?DAT_1431b4be0@@3USd_1431b4be0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b4c60@@3PAEA=?DAT_1431b4c60@@3USd_1431b4c60@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b4c60@@3PEAXEA=?DAT_1431b4c60@@3USd_1431b4c60@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b53c0@@3PAEA=?DAT_1431b53c0@@3USd_1431b53c0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b53c0@@3PEAXEA=?DAT_1431b53c0@@3USd_1431b53c0@@A")
#pragma comment(linker, "/alternatename:?DAT_140002b00@@3PAEA=?GetSoundChannel@VideoSoundStream@Video@GFx@Scaleform@@UEAAPEAVUnk_VideoSoundChannel@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_140007de0@@3PAEA=?GetASCharacter@Object@AS2@GFx@Scaleform@@UEAAPEAVInteractiveObject@34@XZ")
#pragma comment(linker, "/alternatename:?DAT_140007df0@@3PAEA=?GetASCharacter@Object@AS2@GFx@Scaleform@@UEBAPEBVInteractiveObject@34@XZ")
#pragma comment(linker, "/alternatename:?DAT_140007e00@@3PAEA=?CheckAndResetCtorRef@Object@AS2@GFx@Scaleform@@UEAAXPEAVFunctionObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140009f10@@3PAEA=?DoesImplement@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEBA_NPEAVEnvironment@234@PEBVObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000a3a0@@3PAEA=?Finalize_GC@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@MEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000a770@@3PAEA=?ExecuteForEachChild_GC@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@MEBAXPEAV?$RefCountCollector@$0BED@@234@W4OperationGC@?$RefCountBaseGC@$0BED@@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142300840@@3PAEA=?SetSpatialInfo@VideoSoundStream@Video@GFx@Scaleform@@UEAAXPEBX@Z")
#pragma comment(linker, "/alternatename:?DAT_14280ef52@@3PAEA=_purecall")
#pragma comment(linker, "/alternatename:?DAT_142956ca0@@3PAEA=?GetValue@Object@AS2@GFx@Scaleform@@UEBA?AVValue@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_14298cc70@@3PAEA=?SetValue@Object@AS2@GFx@Scaleform@@UEAAXPEAVEnvironment@234@AEBVValue@234@@Z")

#pragma comment(linker, "/alternatename:?FUN_140002b30@@YAXXZ=?FUN_140002b30@@YAPEAXPEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_140002bb0@@YAXXZ=?FUN_140002bb0@@YAPEAXPEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_140002c10@@YAXXZ=?FUN_140002c10@@YAPEAXPEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_140002cc0@@YAXXZ=?FUN_140002cc0@@YAPEAXPEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_140002d20@@YAXXZ=?FUN_140002d20@@YAPEAXPEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_14000a880@@YAXXZ=?FUN_14000a880@@YAPEAXPEAXI@Z")
#endif // MS2_HOOK_DLL
