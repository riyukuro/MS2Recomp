// Data unit (sfr22; group sfr33v of work/sfr35/outside-units.tsv):
// exe globals of the .rdata block below that no recovered TU defines, initialized with the exe's values.
// One definition per exe address (tools/datacheck.py checks address, size and initializer); the other names
// users declare at an address are mapped to it with /alternatename. Class objects are byte images up to the
// next known exe global; their constructors (the owning TU's .text$di initializer) are not run by this unit,
// see the zero-blob list in work/sfr22/outside-summary.md. A recovered owner moves a definition to its TU.
// The hook DLL binds every name to the exe's own global (symbols table), so nothing here is compiled into it
// (docs/RECOVERY.md sec. 9).
// MS2-UNIT: data_rdata_sf_video
// MS2-RANGE: 0x1431b4be0-0x1431b8030 .rdata

#ifndef MS2_HOOK_DLL

extern unsigned char DAT_140002b00[];
extern unsigned char DAT_140002b30[];
extern unsigned char DAT_140002bb0[];
extern unsigned char DAT_140002c10[];
extern unsigned char DAT_140002cc0[];
extern unsigned char DAT_140002d20[];
extern unsigned char DAT_140007ba0[];
extern unsigned char DAT_140007d90[];
extern unsigned char DAT_140007da0[];
extern unsigned char DAT_140007db0[];
extern unsigned char DAT_140007dc0[];
extern unsigned char DAT_140007de0[];
extern unsigned char DAT_140007df0[];
extern unsigned char DAT_140007e00[];
extern unsigned char DAT_140007e10[];
extern unsigned char DAT_140007ff0[];
extern unsigned char DAT_140008250[];
extern unsigned char DAT_140009ef0[];
extern unsigned char DAT_140009f00[];
extern unsigned char DAT_140009f10[];
extern unsigned char DAT_140009f30[];
extern unsigned char DAT_14000a110[];
extern unsigned char DAT_14000a3a0[];
extern unsigned char DAT_14000a770[];
extern unsigned char DAT_14000a880[];
extern unsigned char DAT_14000e370[];
extern unsigned char DAT_14000e380[];
extern unsigned char DAT_14000e3e0[];
extern unsigned char DAT_14000e3f0[];
extern unsigned char DAT_14000e400[];
extern unsigned char DAT_14000e4d0[];
extern unsigned char DAT_14000e520[];
extern unsigned char DAT_14000e530[];
extern unsigned char DAT_14000e540[];
extern unsigned char DAT_14000e550[];
extern unsigned char DAT_14000e560[];
extern unsigned char DAT_14000e580[];
extern unsigned char DAT_14000e5d0[];
extern unsigned char DAT_14000e5e0[];
extern unsigned char DAT_14000e600[];
extern unsigned char DAT_14000e610[];
extern unsigned char DAT_14000e620[];
extern unsigned char DAT_142300840[];
extern unsigned char DAT_1423dc0b0[];
extern unsigned char DAT_1423dcd60[];
extern unsigned char DAT_1423df420[];
extern unsigned char DAT_1423df460[];
extern unsigned char DAT_1423df4a0[];
extern unsigned char DAT_1423df580[];
extern unsigned char DAT_1423df5a0[];
extern unsigned char DAT_1423df5b0[];
extern unsigned char DAT_142442e10[];
extern unsigned char DAT_142443380[];
extern unsigned char DAT_1424e42a0[];
extern unsigned char DAT_1424e8060[];
extern unsigned char DAT_1424ee7f0[];
extern unsigned char DAT_1424effa0[];
extern unsigned char DAT_1424f0700[];
extern unsigned char DAT_1424f2400[];
extern unsigned char DAT_1424f4a40[];
extern unsigned char DAT_1424f7180[];
extern unsigned char DAT_142500e50[];
extern unsigned char DAT_142501a60[];
extern unsigned char DAT_142503f50[];
extern unsigned char DAT_142503fa0[];
extern unsigned char DAT_142505f20[];
extern unsigned char DAT_142507590[];
extern unsigned char DAT_142509a80[];
extern unsigned char DAT_142509ca0[];
extern unsigned char DAT_142509d30[];
extern unsigned char DAT_14250a5b0[];
extern unsigned char DAT_14250bbd0[];
extern unsigned char DAT_14250bc40[];
extern unsigned char DAT_14250be40[];
extern unsigned char DAT_14250c010[];
extern unsigned char DAT_14250c060[];
extern unsigned char DAT_14250c2e0[];
extern unsigned char DAT_14250cc60[];
extern unsigned char DAT_14250d550[];
extern unsigned char DAT_14250d570[];
extern unsigned char DAT_14250f820[];
extern unsigned char DAT_1425117e0[];
extern unsigned char DAT_1425117f0[];
extern unsigned char DAT_142512620[];
extern unsigned char DAT_142514320[];
extern unsigned char DAT_1425185d0[];
extern unsigned char DAT_14251ace0[];
extern unsigned char DAT_14251f3a0[];
extern unsigned char DAT_142528a50[];
extern unsigned char DAT_14252c4e0[];
extern unsigned char DAT_14252e480[];
extern unsigned char DAT_14280ef52[];
extern unsigned char DAT_1429386e0[];
extern unsigned char DAT_1429388e0[];
extern unsigned char DAT_1429448c0[];
extern unsigned char DAT_142944950[];
extern unsigned char DAT_1429493c0[];
extern unsigned char DAT_142949400[];
extern unsigned char DAT_142949860[];
extern unsigned char DAT_14294afb0[];
extern unsigned char DAT_142955080[];
extern unsigned char DAT_142956b10[];
extern unsigned char DAT_142956ca0[];
extern unsigned char DAT_14295d970[];
extern unsigned char DAT_142962310[];
extern unsigned char DAT_1429623a0[];
extern unsigned char DAT_142988930[];
extern unsigned char DAT_1429889c0[];
extern unsigned char DAT_142988bb0[];
extern unsigned char DAT_14298cc70[];
extern unsigned char DAT_14298dcb0[];
extern unsigned char DAT_142991170[];
extern unsigned char DAT_1429926f0[];
extern unsigned char DAT_142992780[];
extern unsigned char DAT_142994660[];
extern unsigned char DAT_1429947f0[];
extern unsigned char DAT_142994bb0[];
extern unsigned char DAT_142994c50[];
extern unsigned char DAT_143146580[];
extern unsigned char DAT_143150b00[];
extern unsigned char DAT_1431b67d0[];
void FUN_140002930();
void FUN_140002950();
void FUN_140002960();
void FUN_140002980();
void FUN_140002d90();
void FUN_140002da0();
void FUN_140002db0();
void FUN_140002dc0();
void FUN_140002dd0();
void FUN_140002de0();
void FUN_140002df0();
void FUN_140002e00();
void FUN_140002e10();
void FUN_140002e20();
void FUN_140002e40();
void FUN_1400047a0();
void FUN_140004810();
void FUN_140004880();
void FUN_140005780();
void FUN_14000a010();
void FUN_14000a020();
void FUN_14000c9f0();
void FUN_14000d320();
void FUN_14000e410();
void FUN_14000e470();
void FUN_14000e500();
void FUN_14000e510();
void FUN_14000e570();
void FUN_14000e590();
void FUN_14000e630();
void FUN_14000e640();
void FUN_14000e650();
void FUN_14000e670();
void FUN_14000e680();
void FUN_14000e690();
void FUN_14000e6a0();
void FUN_14000e6b0();
void FUN_14000e6c0();
void FUN_14000e6d0();
void FUN_14000e6e0();
void FUN_14000e6f0();
void FUN_14000e700();
void FUN_14000e710();
void FUN_14000e720();
void FUN_14000e730();
void FUN_14000e740();
void FUN_14000e750();
void FUN_14000e760();
void FUN_14000e770();
void FUN_14000e780();
void FUN_14000e790();
void FUN_14000e7a0();
void FUN_14000e7b0();
void FUN_14000e7c0();
void FUN_14000e7d0();
void FUN_14000e7e0();
void FUN_14000e7f0();
void FUN_14000e800();
void FUN_14000e810();
void FUN_14000e820();
void FUN_14000e830();
void FUN_14000e880();
void FUN_14000e890();
void FUN_14000e8a0();
void FUN_14000e8f0();
void FUN_14000e9f0();
void FUN_140019af0();
void FUN_140019b60();
void FUN_140019bd0();
void FUN_14001a040();
void FUN_14001a0b0();
void FUN_14001a2f0();
void FUN_14001a470();
void FUN_14001a5c0();
void FUN_14001a760();
void FUN_14001a800();
void FUN_14001a860();
void FUN_14001ae30();
void FUN_14001aea0();
void FUN_14001af10();
void FUN_14001afd0();
void FUN_14001afe0();
void FUN_14001aff0();
void FUN_14001b000();
void FUN_14001b010();
void FUN_14001b020();
void FUN_14001b030();
void FUN_14001b040();
void FUN_14001b050();
void FUN_14001b060();
void FUN_14001b070();
void FUN_14001b080();
void FUN_14001b090();
void FUN_14001b0a0();
void FUN_14001b0b0();
void FUN_14001b0c0();
void FUN_14001b0d0();
void FUN_14001b0e0();
void FUN_14001b100();
void FUN_14001b110();
void FUN_14001b120();
void FUN_14001b130();
void FUN_14001b140();
void FUN_14001b160();
void FUN_14001b170();
void FUN_14001b180();
void FUN_14001b190();
void FUN_14001b1a0();
void FUN_14001b1b0();
void FUN_14001b1c0();
void FUN_14001b1d0();
void FUN_14001b1e0();
void FUN_14001b1f0();
void FUN_14001b200();
void FUN_14001b210();
void FUN_14001b220();
void FUN_14001b230();
void FUN_14001b240();
void FUN_14001b250();
void FUN_14001b260();
void FUN_14001b270();
void FUN_14001b280();
void FUN_14001b290();
void FUN_14001b2a0();
void FUN_14001b2b0();
void FUN_14001b2c0();
void FUN_14001b2d0();
void FUN_14001b2e0();
void FUN_14001b2f0();
void FUN_14001b300();
void FUN_14001b310();
void FUN_14001b320();
void FUN_14001b330();
void FUN_14001b340();
void FUN_14001b350();
void FUN_14001b360();
void FUN_14001b370();
void FUN_14001b380();
void FUN_14001b390();
void FUN_14001b3a0();
void FUN_14293ff70();
void FUN_142940160();
void FUN_1429413c0();
void FUN_14295d840();
void FUN_14298ab80();

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
struct Sd_1431b4ce0 {
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
    unsigned char b78[0x28];
};
struct Sd_1431b4d80 {
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
    unsigned char b50[0x10];
};
struct Sd_1431b5300 {
    const void* p0;
    unsigned char b8[0x8];
};
struct Sd_1431b5310 {
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
    const void* p80;
    const void* p88;
    const void* p90;
    const void* p98;
    const void* pa0;
    unsigned char ba8[0x8];
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
struct Sd_1431b5b40 {
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
    const void* p80;
    const void* p88;
    const void* p90;
    const void* p98;
    const void* pa0;
    const void* pa8;
    const void* pb0;
    unsigned char bb8[0x8];
};
struct Sd_1431b5c00 {
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
    const void* p80;
    const void* p88;
    const void* p90;
    const void* p98;
    const void* pa0;
    unsigned char ba8[0x8];
};
struct Sd_1431b5cb0 {
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
    const void* p80;
    const void* p88;
    const void* p90;
    const void* p98;
    const void* pa0;
    const void* pa8;
    const void* pb0;
    const void* pb8;
    const void* pc0;
    const void* pc8;
    const void* pd0;
    const void* pd8;
    const void* pe0;
    const void* pe8;
    const void* pf0;
    const void* pf8;
    const void* p100;
    const void* p108;
    const void* p110;
    const void* p118;
    const void* p120;
    const void* p128;
    const void* p130;
    const void* p138;
    const void* p140;
};
struct Sd_1431b7160 {
    unsigned char b0[0x8];
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    unsigned char b28[0x8];
    const void* p30;
    unsigned char b38[0x8];
    const void* p40;
    unsigned char b48[0x8];
};
struct Sd_1431b7900 {
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
};
struct Sd_1431b7b50 {
    unsigned char b0[0x8];
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    unsigned char b28[0x18];
    const void* p40;
    unsigned char b48[0x8];
};
struct Sd_1431b7ba0 {
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
    const void* p80;
    const void* p88;
    const void* p90;
    const void* p98;
    const void* pa0;
    const void* pa8;
};
struct Sd_1431b7c70 {
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
    const void* p80;
};
struct Sd_1431b7d50 {
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
};
struct Sd_1431b7de0 {
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
    const void* p80;
    const void* p88;
    const void* p90;
    const void* p98;
    const void* pa0;
    const void* pa8;
    const void* pb0;
    unsigned char bb8[0x8];
};
struct Sd_1431b7ea0 {
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
    const void* p80;
    const void* p88;
    const void* p90;
    const void* p98;
    const void* pa0;
    const void* pa8;
    const void* pb0;
    unsigned char bb8[0x8];
};
struct Sd_1431b7f60 {
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
    const void* p80;
    const void* p88;
    const void* p90;
    const void* p98;
    const void* pa0;
    const void* pa8;
    const void* pb0;
    const void* pb8;
    const void* pc0;
    const void* pc8;
};
#pragma pack(pop)

extern Sd_1431b7900 DAT_1431b7900;

// 0x1431b4be0
alignas(16) Sd_1431b4be0 DAT_1431b4be0 = {
    DAT_140002c10,
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
    DAT_140002b30,
    DAT_140002bb0,
    DAT_140002cc0,
};
// 0x1431b4c60
alignas(16) Sd_1431b4c60 DAT_1431b4c60 = {
    DAT_140002d20,
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
// 0x1431b4ce0
alignas(16) Sd_1431b4ce0 DAT_1431b4ce0 = {
    (const void*)&FUN_140002e40,
    (const void*)&FUN_140002d90,
    (const void*)&FUN_140002da0,
    (const void*)&FUN_140002930,
    (const void*)&FUN_140002db0,
    (const void*)&FUN_140002950,
    (const void*)&FUN_140002dc0,
    (const void*)&FUN_140002dd0,
    (const void*)&FUN_140002de0,
    (const void*)&FUN_140002df0,
    (const void*)&FUN_140002960,
    (const void*)&FUN_140002e00,
    (const void*)&FUN_140002e10,
    (const void*)&FUN_140002e20,
    (const void*)&FUN_140002980,
    {
        0x73, 0x65, 0x74, 0x42, 0x75, 0x66, 0x66, 0x65, 0x72, 0x54, 0x69, 0x6d, 0x65, 0x00, 0x00, 0x00,
        0x70, 0x6c, 0x61, 0x79, 0x00, 0x00, 0x00, 0x00, 0x70, 0x61, 0x75, 0x73, 0x65, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};
// 0x1431b4d80
alignas(16) Sd_1431b4d80 DAT_1431b4d80 = {
    "close",
    (const void*)&FUN_1400047a0,
    "pause",
    (const void*)&FUN_140004810,
    "play",
    (const void*)&FUN_14000c9f0,
    "setBufferTime",
    (const void*)&FUN_140004880,
    "seek",
    (const void*)&FUN_140005780,
    {0},
};
// 0x1431b5300
alignas(16) Sd_1431b5300 DAT_1431b5300 = {
    (const void*)&FUN_14000a010,
    {0},
};
// 0x1431b5310
alignas(16) Sd_1431b5310 DAT_1431b5310 = {
    (const void*)&FUN_14000a020,
    DAT_140007dc0,
    DAT_140007e10,
    DAT_140008250,
    DAT_140009ef0,
    DAT_142944950,
    DAT_1429388e0,
    DAT_1429889c0,
    DAT_1429947f0,
    DAT_14295d970,
    DAT_142988bb0,
    DAT_14000a110,
    DAT_142991170,
    DAT_140007ba0,
    DAT_140007ff0,
    DAT_140007d90,
    DAT_140009f30,
    DAT_140009f00,
    DAT_1429623a0,
    DAT_142994c50,
    DAT_142992780,
    {0},
};
// 0x1431b53c0
alignas(16) Sd_1431b53c0 DAT_1431b53c0 = {
    DAT_14000a770,
    DAT_14000a3a0,
    DAT_14000a880,
    DAT_14298cc70,
    DAT_142956ca0,
    DAT_140009f10,
    DAT_140007df0,
    DAT_140007de0,
    DAT_140007e00,
};
// 0x1431b5b40
alignas(16) Sd_1431b5b40 DAT_1431b5b40 = {
    (const void*)&FUN_14000e710,
    (const void*)&FUN_14000e7b0,
    (const void*)&FUN_14000e800,
    (const void*)&FUN_14000e7a0,
    (const void*)&FUN_14000e810,
    (const void*)&FUN_14000e730,
    (const void*)&FUN_14000e750,
    (const void*)&FUN_14000e720,
    (const void*)&FUN_14000e740,
    (const void*)&FUN_14000e6e0,
    (const void*)&FUN_14000e700,
    (const void*)&FUN_14000e7f0,
    (const void*)&FUN_14000e790,
    (const void*)&FUN_14000e820,
    (const void*)&FUN_14000e770,
    (const void*)&FUN_14000e6d0,
    (const void*)&FUN_14000e7e0,
    (const void*)&FUN_14000e6f0,
    (const void*)&FUN_14000e830,
    (const void*)&FUN_14000e7d0,
    (const void*)&FUN_14000e780,
    (const void*)&FUN_14000e7c0,
    (const void*)&FUN_14000e760,
    {0},
};
// 0x1431b5c00
alignas(16) Sd_1431b5c00 DAT_1431b5c00 = {
    (const void*)&FUN_14000e6c0,
    DAT_14000e370,
    (const void*)&FUN_14000e500,
    (const void*)&FUN_14000e8f0,
    (const void*)&FUN_14000e9f0,
    DAT_1429448c0,
    DAT_1429386e0,
    DAT_142988930,
    DAT_142994660,
    (const void*)&FUN_14295d840,
    (const void*)&FUN_14000e410,
    (const void*)&FUN_14000e470,
    DAT_142991170,
    DAT_14298dcb0,
    DAT_140007ff0,
    DAT_140007d90,
    DAT_140007da0,
    DAT_140007db0,
    DAT_142962310,
    DAT_142994bb0,
    DAT_1429926f0,
    {0},
};
// 0x1431b5cb0
alignas(16) Sd_1431b5cb0 DAT_1431b5cb0 = {
    (const void*)&FUN_14000e8a0,
    DAT_14000e520,
    DAT_14000e530,
    DAT_14000e540,
    DAT_14000e550,
    DAT_14000e560,
    (const void*)&FUN_14000e570,
    DAT_14000e600,
    DAT_14000e580,
    (const void*)&FUN_14000e590,
    DAT_14000e5d0,
    DAT_14000e5e0,
    (const void*)&FUN_14000e510,
    DAT_14000e620,
    DAT_14000e610,
    (const void*)&FUN_14000e630,
    (const void*)&FUN_14000e640,
    (const void*)&FUN_14000e650,
    (const void*)&FUN_14000e670,
    (const void*)&FUN_14000e680,
    (const void*)&FUN_14000e690,
    (const void*)&FUN_14000e6a0,
    (const void*)&FUN_14000e6b0,
    DAT_14000e380,
    DAT_14294afb0,
    (const void*)&FUN_14000e890,
    (const void*)&FUN_14000e880,
    DAT_14000e3e0,
    DAT_14000e3f0,
    DAT_14000e400,
    DAT_142949400,
    DAT_1429493c0,
    DAT_142956b10,
    DAT_142949860,
    (const void*)&FUN_14000d320,
    (const void*)&FUN_14298ab80,
    DAT_142955080,
    DAT_14000e4d0,
    (const void*)&FUN_142940160,
    (const void*)&FUN_1429413c0,
    (const void*)&FUN_14293ff70,
};
// 0x1431b7160
alignas(16) Sd_1431b7160 DAT_1431b7160 = {
    {
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    "NetStream",
    "flash.net",
    DAT_143150b00,
    (const void*)&FUN_140019bd0,
    {
        0x01, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    &DAT_1431b67d0[0x968],
    {0},
    &DAT_1431b67d0[0x260],
    {0},
};
// 0x1431b7900
alignas(16) Sd_1431b7900 DAT_1431b7900 = {
    DAT_142503f50,
    DAT_1423df5a0,
    (const void*)&FUN_140019af0,
    DAT_1423df4a0,
    (const void*)&FUN_140019b60,
    DAT_1423df420,
    DAT_142514320,
    DAT_14250bc40,
    DAT_14250d550,
    DAT_142509d30,
    DAT_142509ca0,
    DAT_14252c4e0,
    DAT_14250a5b0,
    DAT_1425117f0,
    DAT_1424effa0,
};
// 0x1431b7b50
alignas(16) Sd_1431b7b50 DAT_1431b7b50 = {
    {
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    "Video",
    "flash.media",
    DAT_143146580,
    (const void*)&FUN_14001af10,
    {
        0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const unsigned char*)&DAT_1431b7900 + 0xe0,
    {0},
};
// 0x1431b7ba0
alignas(16) Sd_1431b7ba0 DAT_1431b7ba0 = {
    DAT_142442e10,
    DAT_1423df5b0,
    (const void*)&FUN_14001a040,
    DAT_142443380,
    (const void*)&FUN_14001a2f0,
    DAT_1423df420,
    DAT_142528a50,
    DAT_14250cc60,
    DAT_142509a80,
    DAT_1424f4a40,
    DAT_1424ee7f0,
    (const void*)&FUN_14001a760,
    DAT_1424f0700,
    (const void*)&FUN_14001a800,
    DAT_1424e8060,
    DAT_1423df580,
    DAT_14250c010,
    DAT_14250be40,
    DAT_14250c060,
    DAT_142500e50,
    DAT_142512620,
    (const void*)&FUN_14001a470,
};
// 0x1431b7c70
alignas(16) Sd_1431b7c70 DAT_1431b7c70 = {
    DAT_142503fa0,
    DAT_1423df5a0,
    (const void*)&FUN_14001a0b0,
    DAT_1423df460,
    (const void*)&FUN_14001a5c0,
    DAT_1423df420,
    DAT_142514320,
    DAT_14250bbd0,
    DAT_14250d570,
    DAT_142509d30,
    DAT_142509ca0,
    DAT_14252c4e0,
    DAT_14250a5b0,
    DAT_1425117e0,
    (const void*)&FUN_14001a860,
    DAT_1424e42a0,
    DAT_14252e480,
};
// 0x1431b7d50
alignas(16) Sd_1431b7d50 DAT_1431b7d50 = {
    DAT_142503f50,
    DAT_1423df5a0,
    (const void*)&FUN_14001ae30,
    DAT_1423df4a0,
    (const void*)&FUN_14001aea0,
    DAT_1423df420,
    DAT_142514320,
    DAT_14250bc40,
    DAT_14250d550,
    DAT_142509d30,
    DAT_142509ca0,
    DAT_14252c4e0,
    DAT_14250a5b0,
    DAT_1425117f0,
    DAT_1424effa0,
};
// 0x1431b7de0
alignas(16) Sd_1431b7de0 DAT_1431b7de0 = {
    (const void*)&FUN_14001b1e0,
    (const void*)&FUN_14001b2a0,
    (const void*)&FUN_14001b2c0,
    (const void*)&FUN_14001b280,
    (const void*)&FUN_14001b2d0,
    (const void*)&FUN_14001b200,
    (const void*)&FUN_14001b270,
    (const void*)&FUN_14001b1f0,
    (const void*)&FUN_14001b220,
    (const void*)&FUN_14001b350,
    (const void*)&FUN_14001b1a0,
    (const void*)&FUN_14001b2e0,
    (const void*)&FUN_14001b250,
    (const void*)&FUN_14001b210,
    (const void*)&FUN_14001b330,
    (const void*)&FUN_14001b240,
    (const void*)&FUN_14001b190,
    (const void*)&FUN_14001b290,
    (const void*)&FUN_14001b230,
    (const void*)&FUN_14001b180,
    (const void*)&FUN_14001b380,
    (const void*)&FUN_14001b160,
    (const void*)&FUN_14001b370,
    {0},
};
// 0x1431b7ea0
alignas(16) Sd_1431b7ea0 DAT_1431b7ea0 = {
    (const void*)&FUN_14001b2f0,
    (const void*)&FUN_14001b170,
    (const void*)&FUN_14001b1b0,
    (const void*)&FUN_14001b390,
    (const void*)&FUN_14001b1c0,
    (const void*)&FUN_14001b310,
    (const void*)&FUN_14001b360,
    (const void*)&FUN_14001b300,
    (const void*)&FUN_14001b320,
    (const void*)&FUN_14001b260,
    (const void*)&FUN_14001b2b0,
    (const void*)&FUN_14001b1d0,
    (const void*)&FUN_14001b340,
    (const void*)&FUN_14001b090,
    (const void*)&FUN_14001b0b0,
    (const void*)&FUN_14001b0c0,
    (const void*)&FUN_14001b0d0,
    (const void*)&FUN_14001b0e0,
    (const void*)&FUN_14001b100,
    (const void*)&FUN_14001b110,
    (const void*)&FUN_14001b120,
    (const void*)&FUN_14001b130,
    (const void*)&FUN_14001b140,
    {0},
};
// 0x1431b7f60
alignas(16) Sd_1431b7f60 DAT_1431b7f60 = {
    (const void*)&FUN_14001b3a0,
    (const void*)&FUN_14001afe0,
    (const void*)&FUN_14001b000,
    (const void*)&FUN_14001b010,
    (const void*)&FUN_14001b020,
    (const void*)&FUN_14001b030,
    (const void*)&FUN_14001b0a0,
    (const void*)&FUN_14001b080,
    (const void*)&FUN_14001b040,
    (const void*)&FUN_14001b050,
    (const void*)&FUN_14001b060,
    (const void*)&FUN_14001b070,
    (const void*)&FUN_14001afd0,
    DAT_1423dc0b0,
    DAT_14251ace0,
    DAT_1424f2400,
    (const void*)&FUN_14001aff0,
    DAT_142505f20,
    DAT_14251f3a0,
    DAT_1425185d0,
    DAT_14250c2e0,
    DAT_1424f7180,
    DAT_1423dcd60,
    DAT_14250f820,
    DAT_142507590,
    DAT_142501a60,
};

#pragma comment(linker, "/alternatename:?DAT_1431b4be0@@3PAEA=?DAT_1431b4be0@@3USd_1431b4be0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b4be0@@3PEAXEA=?DAT_1431b4be0@@3USd_1431b4be0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b4c60@@3PAEA=?DAT_1431b4c60@@3USd_1431b4c60@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b4c60@@3PEAXEA=?DAT_1431b4c60@@3USd_1431b4c60@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b4ce0@@3PAEA=?DAT_1431b4ce0@@3USd_1431b4ce0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b4ce0@@3PEAXEA=?DAT_1431b4ce0@@3USd_1431b4ce0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b4d80@@3UNameFunction@AS2@GFx@Scaleform@@A=?DAT_1431b4d80@@3USd_1431b4d80@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b5300@@3PAEA=?DAT_1431b5300@@3USd_1431b5300@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b5300@@3PEAXEA=?DAT_1431b5300@@3USd_1431b5300@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b5310@@3PAEA=?DAT_1431b5310@@3USd_1431b5310@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b5310@@3PEAXEA=?DAT_1431b5310@@3USd_1431b5310@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b53c0@@3PAEA=?DAT_1431b53c0@@3USd_1431b53c0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b53c0@@3PEAXEA=?DAT_1431b53c0@@3USd_1431b53c0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b5b40@@3PAEA=?DAT_1431b5b40@@3USd_1431b5b40@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b5b40@@3PEAXEA=?DAT_1431b5b40@@3USd_1431b5b40@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b5c00@@3PAEA=?DAT_1431b5c00@@3USd_1431b5c00@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b5c00@@3PEAXEA=?DAT_1431b5c00@@3USd_1431b5c00@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b5cb0@@3PAEA=?DAT_1431b5cb0@@3USd_1431b5cb0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b5cb0@@3PEAXEA=?DAT_1431b5cb0@@3USd_1431b5cb0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7160@@3PAEA=?DAT_1431b7160@@3USd_1431b7160@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7160@@3PEAXEA=?DAT_1431b7160@@3USd_1431b7160@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7900@@3PAEA=?DAT_1431b7900@@3USd_1431b7900@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7900@@3PEAXEA=?DAT_1431b7900@@3USd_1431b7900@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7b50@@3PAEA=?DAT_1431b7b50@@3USd_1431b7b50@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7b50@@3PEAXEA=?DAT_1431b7b50@@3USd_1431b7b50@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7ba0@@3PAEA=?DAT_1431b7ba0@@3USd_1431b7ba0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7ba0@@3PEAXEA=?DAT_1431b7ba0@@3USd_1431b7ba0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7c70@@3PAEA=?DAT_1431b7c70@@3USd_1431b7c70@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7c70@@3PEAXEA=?DAT_1431b7c70@@3USd_1431b7c70@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7d50@@3PAEA=?DAT_1431b7d50@@3USd_1431b7d50@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7d50@@3PEAXEA=?DAT_1431b7d50@@3USd_1431b7d50@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7de0@@3PAEA=?DAT_1431b7de0@@3USd_1431b7de0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7de0@@3PEAXEA=?DAT_1431b7de0@@3USd_1431b7de0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7ea0@@3PAEA=?DAT_1431b7ea0@@3USd_1431b7ea0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7ea0@@3PEAXEA=?DAT_1431b7ea0@@3USd_1431b7ea0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7f60@@3PAEA=?DAT_1431b7f60@@3USd_1431b7f60@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7f60@@3PEAXEA=?DAT_1431b7f60@@3USd_1431b7f60@@A")
#pragma comment(linker, "/alternatename:?DAT_140002b00@@3PAEA=?GetSoundChannel@VideoSoundStream@Video@GFx@Scaleform@@UEAAPEAVUnk_VideoSoundChannel@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_140002b30@@3PAEA=?FUN_140002b30@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002bb0@@3PAEA=?FUN_140002bb0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002c10@@3PAEA=?FUN_140002c10@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002cc0@@3PAEA=?FUN_140002cc0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002d20@@3PAEA=?FUN_140002d20@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140007ba0@@3PAEA=?Set__proto__@Object@AS2@GFx@Scaleform@@UEAAXPEAVASStringContext@234@PEAV1234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140007d90@@3PAEA=?IsSuper@ObjectInterface@AS2@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_140007da0@@3PAEA=?IsBuiltinPrototype@ObjectInterface@AS2@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_140007db0@@3PAEA=?AddInterface@ObjectInterface@AS2@GFx@Scaleform@@UEAAXPEAVASStringContext@234@HPEAVFunctionObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140007dc0@@3PAEA=?GetTextValue@Object@AS2@GFx@Scaleform@@UEBAPEBDPEAVEnvironment@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140007de0@@3PAEA=?GetASCharacter@Object@AS2@GFx@Scaleform@@UEAAPEAVInteractiveObject@34@XZ")
#pragma comment(linker, "/alternatename:?DAT_140007df0@@3PAEA=?GetASCharacter@Object@AS2@GFx@Scaleform@@UEBAPEBVInteractiveObject@34@XZ")
#pragma comment(linker, "/alternatename:?DAT_140007e00@@3PAEA=?CheckAndResetCtorRef@Object@AS2@GFx@Scaleform@@UEAAXPEAVFunctionObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140007e10@@3PAEA=?GetObjectType@NetStream@AS2@GFx@Scaleform@@UEBA?AW4ObjectType@ObjectInterface@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_140007ff0@@3PAEA=?Get__constructor__@ObjectInterface@AS2@GFx@Scaleform@@UEAA?AVFunctionRef@234@PEAVASStringContext@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140008250@@3PAEA=?SetMember@NetStream@AS2@GFx@Scaleform@@UEAA_NPEAVEnvironment@234@AEBVASString@34@AEBVValue@234@AEBVPropFlags@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140009ef0@@3PAEA=?GetMember@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAA_NPEAVEnvironment@234@AEBVASString@34@PEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140009f00@@3PAEA=?AddInterface@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAAXPEAVASStringContext@234@HPEAVFunctionObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140009f10@@3PAEA=?DoesImplement@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEBA_NPEAVEnvironment@234@PEBVObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140009f30@@3PAEA=?IsBuiltinPrototype@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14000a110@@3PAEA=?GetMemberRaw@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@PEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000a3a0@@3PAEA=?Finalize_GC@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@MEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000a770@@3PAEA=?ExecuteForEachChild_GC@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@MEBAXPEAV?$RefCountCollector@$0BED@@234@W4OperationGC@?$RefCountBaseGC@$0BED@@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000a880@@3PAEA=?FUN_14000a880@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e370@@3PAEA=?GetTextValue@ObjectInterface@AS2@GFx@Scaleform@@UEBAPEBDPEAVEnvironment@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e380@@3PAEA=?Bind@AvmCharacter@AS2@GFx@Scaleform@@UEAAXPEAVDisplayObject@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e3e0@@3PAEA=?GetRelativeTarget@AvmCharacter@AS2@GFx@Scaleform@@UEAAPEAVInteractiveObject@34@AEBVASString@34@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e3f0@@3PAEA=?ReplaceChildCharacterOnLoad@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVInteractiveObject@34@0@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e400@@3PAEA=?ReplaceChildCharacter@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVInteractiveObject@34@0@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e4d0@@3PAEA=?ExecuteBuffer@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVActionBuffer@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e520@@3PAEA=?FUN_14000e520@AS2@GFx@Scaleform@@YA_K_K@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e530@@3PAEA=?FUN_14000e530@AS2@GFx@Scaleform@@YA_KXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e540@@3PAEA=?FUN_14000e540@AS2@GFx@Scaleform@@YA_KXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e550@@3PAEA=?FUN_14000e550@AS2@GFx@Scaleform@@YA_KXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e560@@3PAEA=?FUN_14000e560@AS2@GFx@Scaleform@@YA_KXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e580@@3PAEA=?FUN_14000e580@AS2@GFx@Scaleform@@YA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e5d0@@3PAEA=?FUN_14000e5d0@AS2@GFx@Scaleform@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e5e0@@3PAEA=?AvmVideoCharacter_OnUnloading@AS2@GFx@Scaleform@@YA_NPEAVAvmCharacter@123@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e600@@3PAEA=?FUN_14000e600@AS2@GFx@Scaleform@@YA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e610@@3PAEA=?FUN_14000e610@AS2@GFx@Scaleform@@YA_KXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e620@@3PAEA=?FUN_14000e620@AS2@GFx@Scaleform@@YA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142300840@@3PAEA=?SetSpatialInfo@VideoSoundStream@Video@GFx@Scaleform@@UEAAXPEBX@Z")
#pragma comment(linker, "/alternatename:?DAT_1423dc0b0@@3PAEA=?Bind@AvmDisplayObj@AS3@GFx@Scaleform@@UEAAXPEAVDisplayObject@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_1423dcd60@@3PAEA=?IsStage@AvmInteractiveObj@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df420@@3PAEA=?Finalize_GC@?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@MEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df460@@3PAEA=?GetAS3ObjectName@Traits@AS3@GFx@Scaleform@@UEBA?AVString@4@XZ")
#pragma comment(linker, "/alternatename:?DAT_1423df4a0@@3PAEA=?GetAS3ObjectName@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA?AVString@5@XZ")
#pragma comment(linker, "/alternatename:?DAT_1423df580@@3PAEA=?Unk15@Object@AS3@GFx@Scaleform@@UEAAPEAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df5a0@@3PAEA=?IsAS3Object@?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df5b0@@3PAEA=?IsAS3Object@Object@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142442e10@@3PAEA=?ForEachChild_GC@DisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@MEBAXPEAV?$RefCountCollector@$0BED@@456@P6AX0PEAPEBV?$RefCountBaseGC@$0BED@@456@@Z@Z")
#pragma comment(linker, "/alternatename:?DAT_142443380@@3PAEA=?GetAS3ObjectName@DisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@UEBA?AVString@6@XZ")
#pragma comment(linker, "/alternatename:?DAT_1424e42a0@@3PAEA=?AS3Constructor@Traits@InstanceTraits@AS3@GFx@Scaleform@@UEBAXAEBV1345@AEBVValue@345@IPEBV6345@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424e8060@@3PAEA=?AddDynamicSlotValuePair@Object@AS3@GFx@Scaleform@@UEAAXAEBVValue@234@0W4Attribute@SlotInfo@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424ee7f0@@3PAEA=?Call@Object@AS3@GFx@Scaleform@@UEAAXAEBVValue@234@AEAV5234@IQEBV5234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424effa0@@3PAEA=?Coerce@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA_NAEBVValue@345@AEAV6345@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f0700@@3PAEA=?Sfr33ThrowNotConstructor@AS3@GFx@Scaleform@@YAXPEBE@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f2400@@3PAEA=?CreateASInstance@AvmDisplayObj@AS3@GFx@Scaleform@@UEAAI_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f4a40@@3PAEA=?DeleteProperty@Object@AS3@GFx@Scaleform@@UEAA?AVCheckResult@234@AEBVMultiname@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f7180@@3PAEA=?DetachChild@AvmDisplayObj@AS3@GFx@Scaleform@@UEAA_NPEAVDisplayObjectBase@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_142500e50@@3PAEA=?FindDynamicSlot@Object@AS3@GFx@Scaleform@@UEAA?AVPropRef@234@AEBVMultiname@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142501a60@@3PAEA=?FindInsertToPlayList@AvmInteractiveObj@AS3@GFx@Scaleform@@UEAAPEAVInteractiveObject@34@PEAV534@@Z")
#pragma comment(linker, "/alternatename:?DAT_142503f50@@3PAEA=?Sfr33ForEachChildGC_c0a@AS3@GFx@Scaleform@@YAXPEAEPEAXP6AX111@Z@Z")
#pragma comment(linker, "/alternatename:?DAT_142503fa0@@3PAEA=?Sfr33ForEachChildGC_c0b@AS3@GFx@Scaleform@@YAXPEAEPEAXP6AX111@Z@Z")
#pragma comment(linker, "/alternatename:?DAT_142505f20@@3PAEA=?GetASClassName@AvmDisplayObj@AS3@GFx@Scaleform@@UEBAAEAVString@4@PEAV54@@Z")
#pragma comment(linker, "/alternatename:?DAT_142507590@@3PAEA=?GetAvmTopParent@AvmInteractiveObj@AS3@GFx@Scaleform@@UEBAPEAV1234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142509a80@@3PAEA=?GetDynamicProperty@Object@AS3@GFx@Scaleform@@UEAAXVAbsoluteIndex@234@AEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142509ca0@@3PAEA=?GetFilePtr@Traits@AS3@GFx@Scaleform@@UEBAPEAVVMAbcFile@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_142509d30@@3PAEA=?GetFixedMemSize@Traits@AS3@GFx@Scaleform@@UEBAIXZ")
#pragma comment(linker, "/alternatename:?DAT_14250a5b0@@3PAEA=?GetGlobalObjectScript@Traits@AS3@GFx@Scaleform@@UEBAPEAVGlobalObjectScript@fl@Instances@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_14250bbd0@@3PAEA=?GetName@CTraits@InstanceTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@XZ")
#pragma comment(linker, "/alternatename:?DAT_14250bc40@@3PAEA=?GetName@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@XZ")
#pragma comment(linker, "/alternatename:?DAT_14250be40@@3PAEA=?GetNextDynPropIndex@Object@AS3@GFx@Scaleform@@UEBA?AVGlobalSlotIndex@234@V5234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250c010@@3PAEA=?GetNextPropertyName@Object@AS3@GFx@Scaleform@@UEBAXAEAVValue@234@VGlobalSlotIndex@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250c060@@3PAEA=?GetNextPropertyValue@Object@AS3@GFx@Scaleform@@UEAAXAEAVValue@234@VGlobalSlotIndex@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250c2e0@@3PAEA=?GetObjectsUnderPoint@AvmDisplayObj@AS3@GFx@Scaleform@@UEBA_NPEAV?$ArrayDH@V?$Ptr@VDisplayObjectBase@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@4@AEBV?$Point@M@Render@4@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250cc60@@3PAEA=?GetProperty@Object@AS3@GFx@Scaleform@@UEAA?AVCheckResult@234@AEBVMultiname@234@AEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250d550@@3PAEA=?GetQualifiedName@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@W4QNameFormat@1345@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250d570@@3PAEA=?GetQualifiedName@Traits@InstanceTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@W4QNameFormat@1345@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250f820@@3PAEA=?GetTopParent@AvmInteractiveObj@AS3@GFx@Scaleform@@UEBAPEAVInteractiveObject@34@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1425117e0@@3PAEA=?InitOnDemand@Traits@AS3@GFx@Scaleform@@MEBAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1425117f0@@3PAEA=?InitOnDemand@Traits@ClassTraits@AS3@GFx@Scaleform@@MEBAXXZ")
#pragma comment(linker, "/alternatename:?DAT_142512620@@3PAEA=?InitializeOnDemand@Object@AS3@GFx@Scaleform@@UEAAPEBVSlotInfo@234@PEBV5234@AEBVASString@34@AEBVNamespace@Instances@234@AEA_K@Z")
#pragma comment(linker, "/alternatename:?DAT_142514320@@3PAEA=?IsGlobal@Traits@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1425185d0@@3PAEA=?OnAdded@AvmDisplayObj@AS3@GFx@Scaleform@@UEAAX_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14251ace0@@3PAEA=?OnRemoved@AvmDisplayObj@AS3@GFx@Scaleform@@UEAAX_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14251f3a0@@3PAEA=?PropagateEvent@AvmDisplayObj@AS3@GFx@Scaleform@@UEAAXAEBVEvent@fl_events@Instances@234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142528a50@@3PAEA=?SetProperty@Object@AS3@GFx@Scaleform@@UEAA?AVCheckResult@234@AEBVMultiname@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14252c4e0@@3PAEA=?SetupSlotValues@Traits@AS3@GFx@Scaleform@@UEBA?AVCheckResult@234@AEAVObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14252e480@@3PAEA=?Sfr31TracerHasTraits@AS3@GFx@Scaleform@@YA_N_K0@Z")
#pragma comment(linker, "/alternatename:?DAT_14280ef52@@3PAEA=_purecall")
#pragma comment(linker, "/alternatename:?DAT_1429386e0@@3PAEA=?DeleteMember@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_1429388e0@@3PAEA=?DeleteMember@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_1429448c0@@3PAEA=?FindMember@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@PEAVMember@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142944950@@3PAEA=?FindMember@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@PEAVMember@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1429493c0@@3PAEA=?GetASEnvironment@AvmCharacter@AS2@GFx@Scaleform@@UEAAPEAVEnvironment@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_142949400@@3PAEA=?GetASEnvironment@AvmCharacter@AS2@GFx@Scaleform@@UEBAPEBVEnvironment@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_142949860@@3PAEA=?GetAvmTopParent@AvmCharacter@AS2@GFx@Scaleform@@UEBAPEAV1234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14294afb0@@3PAEA=?GetGC@AvmCharacter@AS2@GFx@Scaleform@@UEBAPEAVGlobalContext@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_142955080@@3PAEA=?GetStandardMember@AvmCharacter@AS2@GFx@Scaleform@@UEBA_NW4StandardMember@1234@PEAVValue@234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142956b10@@3PAEA=?GetTopParent@AvmCharacter@AS2@GFx@Scaleform@@UEBAPEAVInteractiveObject@34@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142956ca0@@3PAEA=?GetValue@Object@AS2@GFx@Scaleform@@UEBA?AVValue@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_14295d970@@3PAEA=?HasMember@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142962310@@3PAEA=?InstanceOf@AvmCharacter@AS2@GFx@Scaleform@@UEBA_NPEAVEnvironment@234@PEBVObject@234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1429623a0@@3PAEA=?InstanceOf@Object@AS2@GFx@Scaleform@@UEBA_NPEAVEnvironment@234@PEBV1234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142988930@@3PAEA=?SetMemberFlags@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@E@Z")
#pragma comment(linker, "/alternatename:?DAT_1429889c0@@3PAEA=?SetMemberFlags@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@E@Z")
#pragma comment(linker, "/alternatename:?DAT_142988bb0@@3PAEA=?SetMemberRaw@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@AEBVValue@234@AEBVPropFlags@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14298cc70@@3PAEA=?SetValue@Object@AS2@GFx@Scaleform@@UEAAXPEAVEnvironment@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14298dcb0@@3PAEA=?Set__proto__@AvmCharacter@AS2@GFx@Scaleform@@UEAAXPEAVASStringContext@234@PEAVObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142991170@@3PAEA=?ToFunction@Object@AS2@GFx@Scaleform@@UEAA?AVFunctionRef@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_1429926f0@@3PAEA=?Unwatch@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_142992780@@3PAEA=?Unwatch@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_142994660@@3PAEA=?VisitMembers@AvmCharacter@AS2@GFx@Scaleform@@UEBAXPEAVASStringContext@234@PEAUMemberVisitor@ObjectInterface@234@IPEBV7234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1429947f0@@3PAEA=?VisitMembers@Object@AS2@GFx@Scaleform@@UEBAXPEAVASStringContext@234@PEAUMemberVisitor@ObjectInterface@234@IPEBV7234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142994bb0@@3PAEA=?Watch@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@AEBVFunctionRef@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142994c50@@3PAEA=?Watch@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@AEBVFunctionRef@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_143146580@@3PAEA=?DisplayObjectCI@fl_display@AS3@GFx@Scaleform@@3UClassInfo@234@B")
#pragma comment(linker, "/alternatename:?DAT_143150b00@@3PAEA=?EventDispatcherCI@fl_events@AS3@GFx@Scaleform@@3UClassInfo@234@B")
#pragma comment(linker, "/alternatename:?DAT_1431b67d0@@3PAEA=?PTR_LAB_1431b67d0@@3PEAXEA")

#pragma comment(linker, "/alternatename:?FUN_140002930@@YAXXZ=?FUN_140002930@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002950@@YAXXZ=?FUN_140002950@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002960@@YAXXZ=?FUN_140002960@@YAXPEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_140002980@@YAXXZ=?FUN_140002980@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002d90@@YAXXZ=?FUN_140002d90@@YAHPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002da0@@YAXXZ=?FUN_140002da0@@YAHPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002db0@@YAXXZ=?FUN_140002db0@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002dc0@@YAXXZ=?FUN_140002dc0@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002dd0@@YAXXZ=?FUN_140002dd0@@YAMPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002de0@@YAXXZ=?FUN_140002de0@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002df0@@YAXXZ=?FUN_140002df0@@YAMPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002e00@@YAXXZ=?FUN_140002e00@@YAMPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002e10@@YAXXZ=?FUN_140002e10@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002e20@@YAXXZ=?FUN_140002e20@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140002e40@@YAXXZ=?FUN_140002e40@@YAPEAXPEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_1400047a0@@YAXXZ=?Close@NetStreamProto@AS2@GFx@Scaleform@@SAXAEBVFnCall@234@@Z")
#pragma comment(linker, "/alternatename:?FUN_140004810@@YAXXZ=?Pause@NetStreamProto@AS2@GFx@Scaleform@@SAXAEBVFnCall@234@@Z")
#pragma comment(linker, "/alternatename:?FUN_140004880@@YAXXZ=?SetBufferTime@NetStreamProto@AS2@GFx@Scaleform@@SAXAEBVFnCall@234@@Z")
#pragma comment(linker, "/alternatename:?FUN_140005780@@YAXXZ=?Seek@NetStreamProto@AS2@GFx@Scaleform@@SAXAEBVFnCall@234@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000a010@@YAXXZ=?FUN_14000a010@@YAPEAXPEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_14000a020@@YAXXZ=?FUN_14000a020@@YAPEAXPEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_14000c9f0@@YAXXZ=?Play@NetStreamProto@AS2@GFx@Scaleform@@SAXAEBVFnCall@234@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000d320@@YAXXZ=?FUN_14000d320@@YAIPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e410@@YAXXZ=?FUN_14000e410@@YAXPEAPEAXPEAX111@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e470@@YAXXZ=?FUN_14000e470@AS2@GFx@Scaleform@@YAXPEAPEAXPEAX11@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e500@@YAXXZ=?FUN_14000e500@AS2@GFx@Scaleform@@YAHPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e510@@YAXXZ=?FUN_14000e510@AS2@GFx@Scaleform@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e570@@YAXXZ=?FUN_14000e570@AS2@GFx@Scaleform@@YAPEBDPEAVAvmCharacter@123@PEAVString@3@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e590@@YAXXZ=?FUN_14000e590@AS2@GFx@Scaleform@@YAXPEAPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e630@@YAXXZ=?FUN_14000e630@AS2@GFx@Scaleform@@YAXPEAVAvmCharacter@123@PEBVInteractiveObject@23@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e640@@YAXXZ=?FUN_14000e640@AS2@GFx@Scaleform@@YAXPEAVAvmCharacter@123@PEBVInteractiveObject@23@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e650@@YAXXZ=?FUN_14000e650@AS2@GFx@Scaleform@@YAXPEAVAvmCharacter@123@W4FocusEventType@InteractiveObject@23@PEAV623@IW4FocusMovedType@23@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e670@@YAXXZ=?FUN_14000e670@AS2@GFx@Scaleform@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e680@@YAXXZ=?FUN_14000e680@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e690@@YAXXZ=?FUN_14000e690@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e6a0@@YAXXZ=?FUN_14000e6a0@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e6b0@@YAXXZ=?FUN_14000e6b0@AS2@GFx@Scaleform@@YA_NPEBVAvmCharacter@123@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e6c0@@YAXXZ=?FUN_14000e6c0@AS2@GFx@Scaleform@@YAPEAXPEAX_K@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e6d0@@YAXXZ=?FUN_14000e6d0@AS2@GFx@Scaleform@@YAXPEAXPEBVInteractiveObject@23@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e6e0@@YAXXZ=?FUN_14000e6e0@AS2@GFx@Scaleform@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e6f0@@YAXXZ=?FUN_14000e6f0@AS2@GFx@Scaleform@@YAXPEAXW4FocusEventType@InteractiveObject@23@PEAV523@IW4FocusMovedType@23@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e700@@YAXXZ=?FUN_14000e700@AS2@GFx@Scaleform@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e710@@YAXXZ=?FUN_14000e710@AS2@GFx@Scaleform@@YAPEAXPEAX_K@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e720@@YAXXZ=?FUN_14000e720@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e730@@YAXXZ=?FUN_14000e730@AS2@GFx@Scaleform@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e740@@YAXXZ=?FUN_14000e740@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e750@@YAXXZ=?FUN_14000e750@AS2@GFx@Scaleform@@YAPEBDPEAXPEAVString@3@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e760@@YAXXZ=?FUN_14000e760@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e770@@YAXXZ=?FUN_14000e770@AS2@GFx@Scaleform@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e780@@YAXXZ=?FUN_14000e780@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e790@@YAXXZ=?FUN_14000e790@AS2@GFx@Scaleform@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e7a0@@YAXXZ=?FUN_14000e7a0@AS2@GFx@Scaleform@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e7b0@@YAXXZ=?FUN_14000e7b0@AS2@GFx@Scaleform@@YA_K_K@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e7c0@@YAXXZ=?FUN_14000e7c0@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e7d0@@YAXXZ=?FUN_14000e7d0@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e7e0@@YAXXZ=?FUN_14000e7e0@AS2@GFx@Scaleform@@YAXPEAXPEBVInteractiveObject@23@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e7f0@@YAXXZ=?FUN_14000e7f0@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e800@@YAXXZ=?FUN_14000e800@AS2@GFx@Scaleform@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e810@@YAXXZ=?FUN_14000e810@AS2@GFx@Scaleform@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e820@@YAXXZ=?FUN_14000e820@AS2@GFx@Scaleform@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e830@@YAXXZ=?FUN_14000e830@AS2@GFx@Scaleform@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e880@@YAXXZ=?FUN_14000e880@AS2@GFx@Scaleform@@YAPEAVVideoObject@123@PEAVAvmCharacter@123@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e890@@YAXXZ=?FUN_14000e890@AS2@GFx@Scaleform@@YAPEAVVideoObject@123@PEAVAvmCharacter@123@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e8a0@@YAXXZ=?FUN_14000e8a0@@YAPEAXPEAX_K@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e8f0@@YAXXZ=?FUN_14000e8f0@AS2@GFx@Scaleform@@YA_NPEAXPEAVEnvironment@123@AEBVASString@23@AEBVValue@123@AEBVPropFlags@123@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000e9f0@@YAXXZ=?FUN_14000e9f0@AS2@GFx@Scaleform@@YA_NPEAXPEAVEnvironment@123@AEBVASString@23@PEAVValue@123@@Z")
#pragma comment(linker, "/alternatename:?FUN_140019af0@@YAXXZ=?FUN_140019af0@@YAPEBDPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_140019b60@@YAXXZ=?FUN_140019b60@@YAPEAXPEAX_K@Z")
#pragma comment(linker, "/alternatename:?FUN_140019bd0@@YAXXZ=?FUN_140019bd0@?A0xa472a7c9@@YAPEAPEAXPEAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001a040@@YAXXZ=?FUN_14001a040@@YAPEBDPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001a0b0@@YAXXZ=?FUN_14001a0b0@@YAPEBDPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001a2f0@@YAXXZ=?FUN_14001a2f0@@YAPEAXPEAVDisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@_K@Z")
#pragma comment(linker, "/alternatename:?FUN_14001a470@@YAXXZ=?FUN_14001a470@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001a5c0@@YAXXZ=?FUN_14001a5c0@@YAPEAVCTraits@InstanceTraits@AS3@GFx@Scaleform@@PEAV12345@I@Z")
#pragma comment(linker, "/alternatename:?FUN_14001a760@@YAXXZ=?FUN_14001a760@@YAXPEAXIPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_14001a800@@YAXXZ=?FUN_14001a800@@YAXPEA_KE@Z")
#pragma comment(linker, "/alternatename:?FUN_14001a860@@YAXXZ=?FUN_14001a860@@YAXPEAXPEAVValue@AS3@GFx@Scaleform@@PEAVTraits@InstanceTraits@234@@Z")
#pragma comment(linker, "/alternatename:?FUN_14001ae30@@YAXXZ=?FUN_14001ae30@@YAPEBDPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001aea0@@YAXXZ=?FUN_14001aea0@@YAPEAXPEAX_K@Z")
#pragma comment(linker, "/alternatename:?FUN_14001af10@@YAXXZ=?FUN_14001af10@?A0xa472a7c9@@YAPEAPEAXPEAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001afd0@@YAXXZ=?FUN_14001afd0@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001afe0@@YAXXZ=?FUN_14001afe0@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001aff0@@YAXXZ=?FUN_14001aff0@@YAPEBDPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b000@@YAXXZ=?FUN_14001b000@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b010@@YAXXZ=?FUN_14001b010@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b020@@YAXXZ=?FUN_14001b020@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b030@@YAXXZ=?FUN_14001b030@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b040@@YAXXZ=?thunk_FUN_142518c70@@YA_NPEAX0@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b050@@YAXXZ=?thunk_FUN_142519080@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b060@@YAXXZ=?thunk_FUN_142519860@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b070@@YAXXZ=?FUN_14001b070@@YAEPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b080@@YAXXZ=?thunk_FUN_142510dc0@@YA_NPEBX0@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b090@@YAXXZ=?FUN_14001b090@@YAEPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b0a0@@YAXXZ=?thunk_FUN_142506e10@@YAPEBDPEAX0@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b0b0@@YAXXZ=?FUN_14001b0b0@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b0c0@@YAXXZ=?thunk_FUN_1424efe00@@YAXPEAXPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b0d0@@YAXXZ=?thunk_FUN_1424f1f70@@YAXPEAXPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b0e0@@YAXXZ=?FUN_14001b0e0@@YAXPEAXI0II@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b100@@YAXXZ=?FUN_14001b100@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b110@@YAXXZ=?FUN_14001b110@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b120@@YAXXZ=?FUN_14001b120@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b130@@YAXXZ=?FUN_14001b130@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b140@@YAXXZ=?FUN_14001b140@@YA_NPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b160@@YAXXZ=?FUN_14001b160@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b170@@YAXXZ=?FUN_14001b170@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b180@@YAXXZ=?FUN_14001b180@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b190@@YAXXZ=?FUN_14001b190@@YAXPEAXPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b1a0@@YAXXZ=?FUN_14001b1a0@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b1b0@@YAXXZ=?FUN_14001b1b0@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b1c0@@YAXXZ=?FUN_14001b1c0@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b1d0@@YAXXZ=?FUN_14001b1d0@@YAEPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b1e0@@YAXXZ=?FUN_14001b1e0@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b1f0@@YAXXZ=?FUN_14001b1f0@@YA_NPEAXPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b200@@YAXXZ=?FUN_14001b200@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b210@@YAXXZ=?FUN_14001b210@@YAEPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b220@@YAXXZ=?FUN_14001b220@@YA_NPEAX0@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b230@@YAXXZ=?FUN_14001b230@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b240@@YAXXZ=?FUN_14001b240@@YAXPEAXPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b250@@YAXXZ=?FUN_14001b250@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b260@@YAXXZ=?FUN_14001b260@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b270@@YAXXZ=?FUN_14001b270@@YAPEBDPEAX0@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b280@@YAXXZ=?FUN_14001b280@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b290@@YAXXZ=?FUN_14001b290@@YAXPEAXI0II@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b2a0@@YAXXZ=?FUN_14001b2a0@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b2b0@@YAXXZ=?FUN_14001b2b0@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b2c0@@YAXXZ=?FUN_14001b2c0@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b2d0@@YAXXZ=?FUN_14001b2d0@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b2e0@@YAXXZ=?FUN_14001b2e0@@YAEPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b2f0@@YAXXZ=?FUN_14001b2f0@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b300@@YAXXZ=?FUN_14001b300@@YA_NPEAXPEBX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b310@@YAXXZ=?FUN_14001b310@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b320@@YAXXZ=?FUN_14001b320@@YA_NPEAX0@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b330@@YAXXZ=?FUN_14001b330@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b340@@YAXXZ=?FUN_14001b340@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b350@@YAXXZ=?FUN_14001b350@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b360@@YAXXZ=?FUN_14001b360@@YAPEBDPEAX0@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b370@@YAXXZ=?FUN_14001b370@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b380@@YAXXZ=?FUN_14001b380@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b390@@YAXXZ=?FUN_14001b390@@YA_KPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14001b3a0@@YAXXZ=?FUN_14001b3a0@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_14293ff70@@YAXXZ=?ExecuteCFunction@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NP6AXAEBVFnCall@234@@ZAEBV?$Array@VValue@AS2@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@4@@Z")
#pragma comment(linker, "/alternatename:?FUN_142940160@@YAXXZ=?ExecuteEvent@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NAEBVEventId@34@@Z")
#pragma comment(linker, "/alternatename:?FUN_1429413c0@@YAXXZ=?ExecuteFunction@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NAEBVFunctionRef@234@AEBV?$Array@VValue@AS2@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@4@@Z")
#pragma comment(linker, "/alternatename:?FUN_14295d840@@YAXXZ=?HasMember@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@_N@Z")
#pragma comment(linker, "/alternatename:?FUN_14298ab80@@YAXXZ=?SetStandardMember@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NW4StandardMember@1234@AEBVValue@234@_N@Z")
#endif // MS2_HOOK_DLL
