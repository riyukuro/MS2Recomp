// Data unit (sfr22; groups 1431b8db0, 143b27438, 143c490e0, 143d49580, 143d74820, 143db4a84, 143e44b00, 143ee68c0, 143f67cc0, 143fe8240, 143ffbce0 of work/sfr35/outside-units.tsv):
// exe globals of the .rdata blocks below that no recovered TU defines, initialized with the exe's values.
// One definition per exe address (tools/datacheck.py checks address, size and initializer); the other names
// users declare at an address are mapped to it with /alternatename. Class objects are byte images up to the
// next known exe global; their constructors (the owning TU's .text$di initializer) are not run by this unit,
// see the zero-blob list in work/sfr22/outside-summary.md. A recovered owner moves a definition to its TU.
// The hook DLL binds every name to the exe's own global (symbols table), so nothing here is compiled into it
// (docs/RECOVERY.md sec. 9).
// MS2-UNIT: data_cri
// MS2-RANGE: 0x1431b8db0-0x1431bef70 .rdata
// MS2-RANGE: 0x143b27438-0x143ba9d08 .bss
// MS2-RANGE: 0x143c490e0-0x143d49580 .bss
// MS2-RANGE: 0x143d49580-0x143d68b40 .bss
// MS2-RANGE: 0x143d74820-0x143db4a84 .bss
// MS2-RANGE: 0x143db4a84-0x143e44b00 .bss
// MS2-RANGE: 0x143e44b00-0x143e64b00 .bss
// MS2-RANGE: 0x143ee68c0-0x143f67cc0 .bss
// MS2-RANGE: 0x143f67cc0-0x143fe8240 .bss
// MS2-RANGE: 0x143fe8240-0x143ffbce0 .bss
// MS2-RANGE: 0x143ffbce0-0x143ffd558 .bss

#ifndef MS2_HOOK_DLL

extern unsigned char DAT_14001d720[];
extern unsigned char DAT_1400284b0[];
extern unsigned char DAT_140029280[];
extern unsigned char DAT_14002d490[];
extern unsigned char DAT_14002d4a0[];
extern unsigned char DAT_14002d4b0[];
extern unsigned char DAT_14002d4c0[];
extern unsigned char DAT_14002d4d0[];
extern unsigned char DAT_140041270[];
extern unsigned char DAT_142443950[];
extern unsigned char DAT_142444340[];
extern unsigned char DAT_142444bc0[];
extern unsigned char DAT_142447310[];
extern unsigned char DAT_142447340[];
extern unsigned char DAT_14257aa60[];
extern unsigned char DAT_14257b4a0[];
extern unsigned char DAT_14257b4e0[];
extern unsigned char DAT_14257b550[];
extern unsigned char DAT_14257b5f0[];
extern unsigned char DAT_14257b970[];
extern unsigned char DAT_14257b9a0[];
extern unsigned char DAT_14257b9b0[];
extern unsigned char DAT_14257ba20[];
extern unsigned char DAT_14257bda0[];
extern unsigned char DAT_14257c140[];
extern unsigned char DAT_14257c210[];
extern unsigned char DAT_14257c310[];
extern unsigned char DAT_14257c500[];
extern unsigned char DAT_14257cb10[];
extern unsigned char DAT_14257d120[];
extern unsigned char DAT_14257d1b0[];
extern unsigned char DAT_14257d470[];
extern unsigned char DAT_14257d4c0[];
extern unsigned char DAT_14257dc40[];
extern unsigned char DAT_14257dcf0[];
extern unsigned char DAT_14280ef52[];
extern unsigned char DAT_143224848[];
void FUN_1400283a0();
void FUN_1400283e0();
void FUN_140029240();
void FUN_140029260();
void FUN_140029970();
void FUN_1400299d0();
void FUN_140029a50();
void FUN_140029ab0();
void FUN_140029ec0();
void FUN_140029f20();
void FUN_140029f40();
void FUN_140029f60();
void FUN_140029f80();
void FUN_140029fa0();
void FUN_14002a060();
void FUN_14002a070();
void FUN_14002a080();
void FUN_14002a0e0();
void FUN_14002a2b0();
void FUN_14002ac70();
void FUN_14002b0d0();
void FUN_14002b0e0();
void FUN_14002b0f0();
void FUN_14002b200();
void FUN_14002d6d0();
void FUN_14002d750();
void FUN_14002d7b0();
void FUN_14002d840();
void FUN_14002d9e0();
void FUN_14002de50();
void FUN_14002dec0();
void FUN_14002df50();
void FUN_14002e050();
void FUN_14002e1e0();
void FUN_14002e230();
void FUN_14002e260();
void FUN_14002e370();
void FUN_14002e510();
void FUN_140041220();
void FUN_140041250();
void FUN_1400412a0();
void FUN_1400412c0();
void FUN_1400412e0();
void FUN_140041300();
void FUN_140041340();
void FUN_140041360();
void FUN_1400415f0();
void FUN_140041910();
void FUN_140041a60();
void FUN_140041aa0();
void FUN_140041ad0();
void FUN_140041b50();
void FUN_140041c50();
void FUN_140041c60();
void FUN_1400590c0();
void FUN_140059170();
void FUN_1400592c0();
void FUN_140059340();
void FUN_1400593b0();
void FUN_1400593f0();
void FUN_140059570();
void FUN_140059700();
void FUN_1400597b0();
void FUN_140059810();
void FUN_140059ac0();
void FUN_140059b80();
void FUN_140059c10();
void FUN_140059c40();
void FUN_140059dd0();
void FUN_14005a070();
void FUN_14005a140();
void FUN_14005a1b0();
void FUN_140062c10();
long FUN_142ccb000(void*, void*);
long FUN_142ccb710(void*, void*);
long FUN_142ccbe90(void*, void*);
long FUN_142cccba0(void*);
long FUN_142cccd80(void*);
long FUN_142cccef0(void*);
long FUN_142ccd080(void*);
void FUN_140066450();
void FUN_140066d80();
void FUN_140066da0();
void FUN_140066de0();
void FUN_140068510();
void FUN_140068520();
void FUN_140068540();
void FUN_140068560();
void FUN_14008c880();
void FUN_14008d220();
void FUN_14008d240();
void FUN_14008d280();
void FUN_140095b40();
void FUN_14009a3d0();
void FUN_14009ec40();
void FUN_1400a3920();
void FUN_1400a8ad0();
void FUN_1400adc50();
void FUN_14274397c();
void FUN_142743988();
void FUN_142743994();
void FUN_1427439a0();
void FUN_1427439ac();
void FUN_1427439b8();
void FUN_1427439c4();
void FUN_1427439d0();
void FUN_142743a30();
void FUN_142743a60();
void FUN_142743ac0();
void FUN_142743b60();
void FUN_142743c10();
void FUN_142743c80();
void FUN_142743cf0();
void FUN_142743db0();
void FUN_142743e00();
void FUN_142743e60();
void FUN_142743f00();
void FUN_142743fa0();
void FUN_1427447e0();
void FUN_1427447f0();
void FUN_1427449f0();
void FUN_142744ea0();
void FUN_142745620();
void FUN_142745760();
void FUN_1427457a0();
void FUN_1427457e0();
void FUN_142745830();
void FUN_142745840();
void FUN_142745880();
void FUN_1427458b0();
void FUN_1427458e0();
void FUN_142745980();
void FUN_142745a90();
void FUN_142745ab0();
void FUN_142745b70();
void FUN_142745b80();
void FUN_142745b90();
void FUN_142745bc0();
void FUN_142745c30();
void FUN_142745c40();
void FUN_142745c80();
void FUN_142745e70();
void FUN_142745ea0();
void FUN_142745eb0();
void FUN_142745f30();
void FUN_142746220();
void FUN_142746230();
void FUN_1427462b0();
void FUN_142746380();
void FUN_1427464c0();
void FUN_142746500();
void FUN_142746510();
void FUN_142746560();
void FUN_142746640();
void FUN_1427466c0();
void FUN_1427466d0();
void FUN_142746a30();
void FUN_142746a40();
void FUN_142746bd0();
void FUN_142746d70();
void FUN_142746da0();
void FUN_1427471a0();

#pragma pack(push, 1)
struct Sd_1431b8db0 {
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
};
struct Sd_1431b8e08 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
};
struct Sd_1431b8f18 {
    const void* p0;
    const void* p8;
    const void* p10;
};
struct Sd_1431b8f30 {
    const void* p0;
    const void* p8;
    const void* p10;
};
struct Sd_1431b8fa0 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
};
struct Sd_1431b8fc8 {
    const void* p0;
};
struct Sd_1431b8fd0 {
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
};
struct Sd_1431b9028 {
    const void* p0;
    const void* p8;
    unsigned char b10[0x8];
    const void* p18;
    const void* p20;
    const void* p28;
    const void* p30;
    const void* p38;
    const void* p40;
    const void* p48;
    const void* p50;
};
struct Sd_1431b9080 {
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
    unsigned char be8[0x8];
};
struct Sd_1431b91b0 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
};
struct Sd_1431b91d8 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
};
struct Sd_1431b93b0 {
    const void* p0;
    const void* p8;
};
struct Sd_1431b93c0 {
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
};
struct Sd_1431b9410 {
    const void* p0;
};
struct Sd_1431b9430 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
};
struct Sd_1431b97a8 {
    const void* p0;
    unsigned char b8[0x8];
    const void* p10;
    unsigned char b18[0x8];
    const void* p20;
    unsigned char b28[0x8];
    const void* p30;
    unsigned char b38[0x8];
    const void* p40;
    unsigned char b48[0x8];
    const void* p50;
    unsigned char b58[0x8];
    const void* p60;
    unsigned char b68[0x10];
};
struct Sd_1431b9b10 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
};
struct Sd_1431ba7c8 {
    unsigned char b0[0x8];
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
};
struct Sd_1431bab50 {
    const void* p0;
    const void* p8;
};
struct Sd_1431bab60 {
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
    unsigned char b80[0x20];
};
struct Sd_1431bbd20 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
};
struct Sd_1431bbd40 {
    const void* p0;
    const void* p8;
};
struct Sd_1431bbd50 {
    const void* p0;
    const void* p8;
};
struct Sd_1431bc290 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
};
struct Sd_1431bc450 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    unsigned char b20[0x48];
};
struct Sd_1431bc6c0 {
    const void* p0;
    const void* p8;
    const void* p10;
};
struct Sd_1431bc6d8 {
    const void* p0;
    const void* p8;
    const void* p10;
};
struct Sd_1431bcbb0 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
    const void* p30;
};
struct Sd_1431bcbe8 {
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
};
struct Sd_1431bec40 {
    const void* p0;
    const void* p8;
};
struct Sd_1431bec50 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
};
struct Sd_1431bec80 {
    const void* p0;
    const void* p8;
};
struct Sd_1431bec90 {
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
struct Sd_1431bed08 {
    const void* p0;
    const void* p8;
};
struct Sd_1431bed18 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
    const void* p30;
};
struct Sd_1431bed50 {
    const void* p0;
    const void* p8;
};
struct Sd_1431bed60 {
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
struct Sd_1431bedd8 {
    const void* p0;
    const void* p8;
};
struct Sd_1431bede8 {
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
};
struct Sd_1431bee50 {
    const void* p0;
    const void* p8;
    const void* p10;
};
struct Sd_1431bee68 {
    const void* p0;
    const void* p8;
};
struct Sd_1431bee78 {
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
struct Sd_1431beef0 {
    const void* p0;
    const void* p8;
};
struct Sd_1431bef00 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
    const void* p30;
};
struct Sd_1431bef38 {
    const void* p0;
    const void* p8;
};
#pragma pack(pop)

// 0x1431b8db0
alignas(16) Sd_1431b8db0 DAT_1431b8db0 = {
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
    (const void*)&FUN_1400283a0,
};
// 0x1431b8e08
alignas(8) Sd_1431b8e08 DAT_1431b8e08 = {
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    (const void*)&FUN_1400283e0,
};
// 0x1431b8f18
alignas(8) Sd_1431b8f18 DAT_1431b8f18 = {
    DAT_1400284b0,
    DAT_14280ef52,
    DAT_14280ef52,
};
// 0x1431b8f30
alignas(16) Sd_1431b8f30 DAT_1431b8f30 = {
    DAT_140029280,
    (const void*)&FUN_140029240,
    (const void*)&FUN_140029260,
};
// 0x1431b8fa0
alignas(16) Sd_1431b8fa0 DAT_1431b8fa0 = {
    (const void*)&FUN_140029f20,
    (const void*)&FUN_140029f40,
    (const void*)&FUN_140029f60,
    (const void*)&FUN_140029f80,
    (const void*)&FUN_140029ec0,
};
// 0x1431b8fc8
alignas(8) Sd_1431b8fc8 DAT_1431b8fc8 = {
    (const void*)&FUN_140029fa0,
};
// 0x1431b8fd0
alignas(16) Sd_1431b8fd0 DAT_1431b8fd0 = {
    (const void*)&FUN_140041220,
    (const void*)&FUN_140041250,
    DAT_140041270,
    (const void*)&FUN_14002a060,
    (const void*)&FUN_14002a070,
    (const void*)&FUN_1400412a0,
    (const void*)&FUN_1400412c0,
    (const void*)&FUN_140041300,
    (const void*)&FUN_1400412e0,
    (const void*)&FUN_140041340,
    (const void*)&FUN_14002a080,
};
// 0x1431b9028
alignas(8) Sd_1431b9028 DAT_1431b9028 = {
    (const void*)&FUN_14002a0e0,
    (const void*)&FUN_140041360,
    {0},
    (const void*)&FUN_14002a2b0,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
};
// 0x1431b9080
alignas(16) Sd_1431b9080 DAT_1431b9080 = {
    (const void*)&FUN_14002ac70,
    DAT_14257dc40,
    DAT_14257dcf0,
    DAT_14257b9a0,
    DAT_14257b5f0,
    DAT_14257c140,
    DAT_142444340,
    DAT_14257bda0,
    (const void*)&FUN_1400415f0,
    DAT_14257b4a0,
    DAT_142444bc0,
    DAT_14257b550,
    DAT_14257b970,
    DAT_14257b4e0,
    DAT_14257aa60,
    DAT_14257c500,
    DAT_14257d120,
    DAT_14257b9b0,
    DAT_14257d1b0,
    DAT_14257ba20,
    DAT_14257cb10,
    DAT_14257d4c0,
    DAT_142447310,
    DAT_142447340,
    (const void*)&FUN_140041910,
    DAT_14257c210,
    DAT_14257c310,
    DAT_14257d470,
    DAT_142443950,
    {0},
};
// 0x1431b91b0
alignas(16) Sd_1431b91b0 DAT_1431b91b0 = {
    (const void*)&FUN_14002b0f0,
    DAT_14280ef52,
    (const void*)&FUN_14002b0d0,
    DAT_14001d720,
    (const void*)&FUN_14002b0e0,
};
// 0x1431b91d8
alignas(8) Sd_1431b91d8 DAT_1431b91d8 = {
    (const void*)&FUN_14002b200,
    (const void*)&FUN_14002df50,
    (const void*)&FUN_14002b0d0,
    DAT_14001d720,
    (const void*)&FUN_14002b0e0,
};
// 0x1431b93b0
alignas(16) Sd_1431b93b0 DAT_1431b93b0 = {
    (const void*)&FUN_14002d9e0,
    (const void*)&FUN_14002d840,
};
// 0x1431b93c0
alignas(16) Sd_1431b93c0 DAT_1431b93c0 = {
    (const void*)&FUN_14002e1e0,
    (const void*)&FUN_14002e230,
    (const void*)&FUN_14002e260,
    DAT_14002d4b0,
    DAT_14002d4c0,
    DAT_14002d4d0,
    DAT_14002d4a0,
    (const void*)&FUN_14002d7b0,
    DAT_14002d490,
    (const void*)&FUN_14002de50,
};
// 0x1431b9410
alignas(16) Sd_1431b9410 DAT_1431b9410 = {
    (const void*)&FUN_14002dec0,
};
// 0x1431b9430
alignas(16) Sd_1431b9430 DAT_1431b9430 = {
    (const void*)&FUN_14002e510,
    (const void*)&FUN_14002e050,
    (const void*)&FUN_14002d750,
    (const void*)&FUN_14002e370,
    (const void*)&FUN_14002d6d0,
};
alignas(16) unsigned char DAT_1431b97a0[0x8];                   // 0x1431b97a0
// 0x1431b97a8
alignas(8) Sd_1431b97a8 DAT_1431b97a8 = {
    "<No Error>",
    {
        0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    },
    "Some kind of error.",
    {
        0xfe, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    },
    "Invalid parameter. ",
    {
        0xfd, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    },
    "Failed to allocate memory.",
    {
        0xfc, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    },
    "Thread-unsafe function has been executed in parallel.",
    {
        0xfb, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    },
    "Function not implemented.",
    {
        0xfa, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    },
    "Initialize the library before calling this function.",
    {0},
};
// 0x1431b9820
alignas(16) unsigned char DAT_1431b9820[0x8] = {
    0x3a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431b9b10
alignas(16) Sd_1431b9b10 DAT_1431b9b10 = {
    (const void*)&FUN_140041c60,
    (const void*)&FUN_140041c50,
    (const void*)&FUN_140041a60,
    (const void*)&FUN_140041aa0,
    (const void*)&FUN_140041ad0,
    (const void*)&FUN_140041b50,
};
// 0x1431b9ca0
alignas(16) unsigned char DAT_1431b9ca0[0xc] = {
    0x53, 0x6a, 0x52, 0x62, 0x66, 0x42, 0x75, 0x66, 0x66, 0x65, 0x72, 0x00,
};
// 0x1431ba290
alignas(16) unsigned char DAT_1431ba290[0x50] = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x5a, 0x5a, 0x5a, 0x5a, 0x70, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0xd0, 0x1c, 0x00, 0x00,
};
// 0x1431ba2e0
alignas(16) unsigned char DAT_1431ba2e0[0x8] = {
    0x32, 0x2e, 0x30, 0x38, 0x30, 0x00, 0x00, 0x00,
};
// 0x1431ba2e8
alignas(8) unsigned char DAT_1431ba2e8[0x10] = {
    0x41, 0xee, 0x9e, 0xdd, 0x79, 0x16, 0xd2, 0x11, 0x93, 0x6c, 0x00, 0x60, 0x08, 0x94, 0x48, 0xbc,
};
// 0x1431ba4f8
alignas(8) unsigned char DAT_1431ba4f8[0x10] = {
    0x81, 0x9e, 0x9a, 0x3b, 0xbb, 0x0d, 0xd2, 0x11, 0xa6, 0xbf, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00,
};
// 0x1431ba7c8
alignas(8) Sd_1431ba7c8 DAT_1431ba7c8 = {
    {0},
    (const void*)&FUN_142ccb000,
    (const void*)&FUN_142ccbe90,
    (const void*)&FUN_142ccb710,
    (const void*)&FUN_140062c10,
};
// 0x1431ba800
alignas(16) unsigned char DAT_1431ba800[0x100] = {
    0x04, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x00, 0x00, 0x20, 0x40, 0x00, 0x10, 0x00, 0x80, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431ba950
alignas(16) unsigned char DAT_1431ba950[0x40] = {
    0x00, 0x01, 0x08, 0x10, 0x09, 0x02, 0x03, 0x0a, 0x11, 0x18, 0x20, 0x19, 0x12, 0x0b, 0x04, 0x05,
    0x0c, 0x13, 0x1a, 0x21, 0x28, 0x30, 0x29, 0x22, 0x1b, 0x14, 0x0d, 0x06, 0x07, 0x0e, 0x15, 0x1c,
    0x23, 0x2a, 0x31, 0x38, 0x39, 0x32, 0x2b, 0x24, 0x1d, 0x16, 0x0f, 0x17, 0x1e, 0x25, 0x2c, 0x33,
    0x3a, 0x3b, 0x34, 0x2d, 0x26, 0x1f, 0x27, 0x2e, 0x35, 0x3c, 0x3d, 0x36, 0x2f, 0x37, 0x3e, 0x3f,
};
// 0x1431ba990
alignas(16) unsigned char DAT_1431ba990[0x80] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431baa10
alignas(16) unsigned char DAT_1431baa10[0x10] = {
    0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
};
// 0x1431baa20
alignas(16) unsigned char DAT_1431baa20[0x8] = {
    0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x02, 0x04,
};
// 0x1431baa28
alignas(8) unsigned char DAT_1431baa28[0x8] = {
    0x00, 0x00, 0x01, 0xb2, 0x32, 0x6e, 0x64, 0x00,
};
// 0x1431baa30..0x1431bab30 are two tables split into per-address pieces: the zigzag (+0x00), alternate (+0x40)
// and identity (+0x80) scans, and the default intra quantiser matrix (0x1431baaf0). FUN_1400544b0 and
// FUN_140054820 walk them by index, so each piece gets an ordered .data$ group section named by its exe address
// and the link keeps them contiguous in exe order (allocate also holds the zero-initialised one in place).
#pragma section(".data$crid_1431baa30", read, write)
__declspec(allocate(".data$crid_1431baa30")) alignas(16) unsigned char DAT_1431baa30[0x1] = {0x00};
// 0x1431baa31
#pragma section(".data$crid_1431baa31", read, write)
__declspec(allocate(".data$crid_1431baa31")) alignas(1) unsigned char DAT_1431baa31[0x1] = {
    0x01,
};
// 0x1431baa32
#pragma section(".data$crid_1431baa32", read, write)
__declspec(allocate(".data$crid_1431baa32")) alignas(2) unsigned char DAT_1431baa32[0x1] = {
    0x05,
};
// 0x1431baa33
#pragma section(".data$crid_1431baa33", read, write)
__declspec(allocate(".data$crid_1431baa33")) alignas(1) unsigned char DAT_1431baa33[0xbd] = {
    0x06, 0x0e, 0x0f, 0x1b, 0x1c, 0x02, 0x04, 0x07, 0x0d, 0x10, 0x1a, 0x1d, 0x2a, 0x03, 0x08, 0x0c,
    0x11, 0x19, 0x1e, 0x29, 0x2b, 0x09, 0x0b, 0x12, 0x18, 0x1f, 0x28, 0x2c, 0x35, 0x0a, 0x13, 0x17,
    0x20, 0x27, 0x2d, 0x34, 0x36, 0x14, 0x16, 0x21, 0x26, 0x2e, 0x33, 0x37, 0x3c, 0x15, 0x22, 0x25,
    0x2f, 0x32, 0x38, 0x3b, 0x3d, 0x23, 0x24, 0x30, 0x31, 0x39, 0x3a, 0x3e, 0x3f, 0x00, 0x04, 0x06,
    0x14, 0x16, 0x24, 0x26, 0x34, 0x01, 0x05, 0x07, 0x15, 0x17, 0x25, 0x27, 0x35, 0x02, 0x08, 0x13,
    0x18, 0x22, 0x28, 0x32, 0x36, 0x03, 0x09, 0x12, 0x19, 0x23, 0x29, 0x33, 0x37, 0x0a, 0x11, 0x1a,
    0x1e, 0x2a, 0x2e, 0x38, 0x3c, 0x0b, 0x10, 0x1b, 0x1f, 0x2b, 0x2f, 0x39, 0x3d, 0x0c, 0x0f, 0x1c,
    0x20, 0x2c, 0x30, 0x3a, 0x3e, 0x0d, 0x0e, 0x1d, 0x21, 0x2d, 0x31, 0x3b, 0x3f, 0x00, 0x01, 0x02,
    0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12,
    0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22,
    0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32,
    0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
};
// 0x1431baaf0
#pragma section(".data$crid_1431baaf0", read, write)
__declspec(allocate(".data$crid_1431baaf0")) alignas(16) unsigned char DAT_1431baaf0[0x1] = {
    0x08,
};
// 0x1431baaf1
#pragma section(".data$crid_1431baaf1", read, write)
__declspec(allocate(".data$crid_1431baaf1")) alignas(1) unsigned char DAT_1431baaf1[0x1] = {
    0x10,
};
// 0x1431baaf2
#pragma section(".data$crid_1431baaf2", read, write)
__declspec(allocate(".data$crid_1431baaf2")) alignas(2) unsigned char DAT_1431baaf2[0x1] = {
    0x13,
};
// 0x1431baaf3
#pragma section(".data$crid_1431baaf3", read, write)
__declspec(allocate(".data$crid_1431baaf3")) alignas(1) unsigned char DAT_1431baaf3[0x3d] = {
    0x16, 0x1a, 0x1b, 0x1d, 0x22, 0x10, 0x10, 0x16, 0x18, 0x1b, 0x1d, 0x22, 0x25, 0x13, 0x16, 0x1a,
    0x1b, 0x1d, 0x22, 0x22, 0x26, 0x16, 0x16, 0x1a, 0x1b, 0x1d, 0x22, 0x25, 0x28, 0x16, 0x1a, 0x1b,
    0x1d, 0x20, 0x23, 0x28, 0x30, 0x1a, 0x1b, 0x1d, 0x20, 0x23, 0x28, 0x30, 0x3a, 0x1a, 0x1b, 0x1d,
    0x22, 0x26, 0x2e, 0x38, 0x45, 0x1b, 0x1d, 0x23, 0x26, 0x2e, 0x38, 0x45, 0x53,
};
// 0x1431bab30
alignas(16) unsigned char DAT_1431bab30[0x10] = {
    0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
};
// 0x1431bab40
alignas(16) unsigned char DAT_1431bab40[0x10] = {
    0x08, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
};
// 0x1431bab50
alignas(16) Sd_1431bab50 DAT_1431bab50 = {
    (const void*)&FUN_1400590c0,
    (const void*)&FUN_140059170,
};
// 0x1431bab60
alignas(16) Sd_1431bab60 DAT_1431bab60 = {
    (const void*)&FUN_1400592c0,
    (const void*)&FUN_140059340,
    (const void*)&FUN_1400593b0,
    (const void*)&FUN_1400593f0,
    (const void*)&FUN_140059570,
    (const void*)&FUN_140059700,
    (const void*)&FUN_1400597b0,
    (const void*)&FUN_140059810,
    (const void*)&FUN_140059ac0,
    (const void*)&FUN_140059b80,
    (const void*)&FUN_140059c10,
    (const void*)&FUN_140059c40,
    (const void*)&FUN_140059dd0,
    (const void*)&FUN_14005a070,
    (const void*)&FUN_14005a140,
    (const void*)&FUN_14005a1b0,
    {
        0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0x02, 0x00, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe,
        0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};
// 0x1431bac00
alignas(16) unsigned char DAT_1431bac00[0x90] = {
    0x00, 0x04, 0x01, 0x01, 0x00, 0x03, 0x03, 0x02, 0x00, 0x02, 0x03, 0x03, 0x80, 0x01, 0x04, 0x04,
    0x00, 0x01, 0x04, 0x05, 0xc0, 0x00, 0x05, 0x06, 0x80, 0x00, 0x05, 0x07, 0x70, 0x00, 0x07, 0x08,
    0x60, 0x00, 0x07, 0x09, 0x58, 0x00, 0x08, 0x0a, 0x50, 0x00, 0x08, 0x0b, 0x48, 0x00, 0x08, 0x0c,
    0x40, 0x00, 0x08, 0x0d, 0x38, 0x00, 0x08, 0x0e, 0x30, 0x00, 0x08, 0x0f, 0x2e, 0x00, 0x0a, 0x10,
    0x2c, 0x00, 0x0a, 0x11, 0x2a, 0x00, 0x0a, 0x12, 0x28, 0x00, 0x0a, 0x13, 0x26, 0x00, 0x0a, 0x14,
    0x24, 0x00, 0x0a, 0x15, 0x23, 0x00, 0x0b, 0x16, 0x22, 0x00, 0x0b, 0x17, 0x21, 0x00, 0x0b, 0x18,
    0x20, 0x00, 0x0b, 0x19, 0x1f, 0x00, 0x0b, 0x1a, 0x1e, 0x00, 0x0b, 0x1b, 0x1d, 0x00, 0x0b, 0x1c,
    0x1c, 0x00, 0x0b, 0x1d, 0x1b, 0x00, 0x0b, 0x1e, 0x1a, 0x00, 0x0b, 0x1f, 0x19, 0x00, 0x0b, 0x20,
    0x18, 0x00, 0x0b, 0x21, 0x0f, 0x00, 0x0b, 0x22, 0x08, 0x00, 0x0b, 0x23, 0x01, 0x00, 0x01, 0x04,
};
// 0x1431bac90
alignas(16) unsigned char DAT_1431bac90[0x8] = {
    0x02, 0x00, 0x01, 0x04, 0x01, 0x00, 0x02, 0x44,
};
// 0x1431bac98
alignas(8) unsigned char DAT_1431bac98[0x20] = {
    0x20, 0x00, 0x01, 0x28, 0x10, 0x00, 0x02, 0x08, 0x08, 0x00, 0x03, 0x20, 0x06, 0x00, 0x05, 0x04,
    0x04, 0x00, 0x05, 0x68, 0x02, 0x00, 0x05, 0x48, 0x01, 0x00, 0x06, 0x44, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bacb8
alignas(8) unsigned char DAT_1431bacb8[0x30] = {
    0x20, 0x00, 0x02, 0x30, 0x30, 0x00, 0x02, 0x38, 0x10, 0x00, 0x03, 0x10, 0x18, 0x00, 0x03, 0x18,
    0x08, 0x00, 0x04, 0x20, 0x0c, 0x00, 0x04, 0x28, 0x06, 0x00, 0x05, 0x04, 0x04, 0x00, 0x05, 0x78,
    0x03, 0x00, 0x06, 0x68, 0x02, 0x00, 0x06, 0x58, 0x01, 0x00, 0x06, 0x44, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bace8
alignas(8) unsigned char DAT_1431bace8[0x18] = {
    0x08, 0x00, 0x01, 0x08, 0x04, 0x00, 0x02, 0x48, 0x03, 0x00, 0x04, 0x05, 0x02, 0x00, 0x04, 0x45,
    0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bad00
alignas(16) unsigned char DAT_1431bad00[0x40] = {
    0x40, 0x00, 0x02, 0x28, 0x30, 0x00, 0x03, 0x2a, 0x04, 0x00, 0x07, 0x08, 0x0e, 0x00, 0x06, 0x0a,
    0x10, 0x00, 0x04, 0x20, 0x07, 0x00, 0x07, 0x04, 0x18, 0x00, 0x04, 0x22, 0x20, 0x00, 0x03, 0x68,
    0x08, 0x00, 0x06, 0x48, 0x06, 0x00, 0x07, 0x44, 0x60, 0x00, 0x02, 0x6a, 0x0a, 0x00, 0x06, 0x4a,
    0x0c, 0x00, 0x06, 0x02, 0x05, 0x00, 0x07, 0x09, 0x02, 0x00, 0x07, 0x49, 0x03, 0x00, 0x07, 0x01,
};
// 0x1431bad40
alignas(16) unsigned char DAT_1431bad40[0x50] = {
    0x00, 0x01, 0x02, 0x30, 0x80, 0x01, 0x02, 0x38, 0x80, 0x00, 0x03, 0x10, 0xc0, 0x00, 0x03, 0x18,
    0x40, 0x00, 0x04, 0x20, 0x60, 0x00, 0x04, 0x28, 0x30, 0x00, 0x06, 0x12, 0x38, 0x00, 0x06, 0x1a,
    0x20, 0x00, 0x06, 0x22, 0x28, 0x00, 0x06, 0x2a, 0x18, 0x00, 0x07, 0x04, 0x1c, 0x00, 0x07, 0x78,
    0x10, 0x00, 0x07, 0x68, 0x14, 0x00, 0x07, 0x58, 0x08, 0x00, 0x08, 0x44, 0x0a, 0x00, 0x08, 0x6a,
    0x0c, 0x00, 0x09, 0x5a, 0x0e, 0x00, 0x09, 0x01, 0x0d, 0x00, 0x09, 0x49, 0x0f, 0x00, 0x09, 0x09,
};
// 0x1431bad90
alignas(16) unsigned char DAT_1431bad90[0x10] = {
    0x04, 0x00, 0x01, 0x08, 0x02, 0x00, 0x02, 0x48, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bada0
alignas(16) unsigned char DAT_1431bada0[0x88] = {
    0x19, 0x00, 0x0b, 0xf0, 0x1b, 0x00, 0x0b, 0xf1, 0x1d, 0x00, 0x0b, 0xf2, 0x1f, 0x00, 0x0b, 0xf3,
    0x21, 0x00, 0x0b, 0xf4, 0x23, 0x00, 0x0b, 0xf5, 0x26, 0x00, 0x0a, 0xf6, 0x2a, 0x00, 0x0a, 0xf7,
    0x2e, 0x00, 0x0a, 0xf8, 0x38, 0x00, 0x08, 0xf9, 0x48, 0x00, 0x08, 0xfa, 0x58, 0x00, 0x08, 0xfb,
    0x70, 0x00, 0x07, 0xfc, 0xc0, 0x00, 0x05, 0xfd, 0x80, 0x01, 0x04, 0xfe, 0x00, 0x03, 0x03, 0xff,
    0x00, 0x04, 0x01, 0x00, 0x00, 0x02, 0x03, 0x01, 0x00, 0x01, 0x04, 0x02, 0x80, 0x00, 0x05, 0x03,
    0x60, 0x00, 0x07, 0x04, 0x50, 0x00, 0x08, 0x05, 0x40, 0x00, 0x08, 0x06, 0x30, 0x00, 0x08, 0x07,
    0x2c, 0x00, 0x0a, 0x08, 0x28, 0x00, 0x0a, 0x09, 0x24, 0x00, 0x0a, 0x0a, 0x22, 0x00, 0x0b, 0x0b,
    0x20, 0x00, 0x0b, 0x0c, 0x1e, 0x00, 0x0b, 0x0d, 0x1c, 0x00, 0x0b, 0x0e, 0x1a, 0x00, 0x0b, 0x0f,
    0x18, 0x00, 0x0b, 0x10, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bae28
alignas(8) unsigned char DAT_1431bae28[0x18] = {
    0x03, 0x00, 0x02, 0xff, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bae40
alignas(16) unsigned char DAT_1431bae40[0x100] = {
    0xc0, 0x01, 0x03, 0x3c, 0xa0, 0x01, 0x04, 0x04, 0x80, 0x01, 0x04, 0x08, 0x60, 0x01, 0x04, 0x10,
    0x40, 0x01, 0x04, 0x20, 0x30, 0x01, 0x05, 0x0c, 0x20, 0x01, 0x05, 0x30, 0x10, 0x01, 0x05, 0x14,
    0x00, 0x01, 0x05, 0x28, 0xf0, 0x00, 0x05, 0x1c, 0xe0, 0x00, 0x05, 0x2c, 0xd0, 0x00, 0x05, 0x34,
    0xc0, 0x00, 0x05, 0x38, 0xb0, 0x00, 0x05, 0x01, 0xa0, 0x00, 0x05, 0x3d, 0x90, 0x00, 0x05, 0x02,
    0x80, 0x00, 0x05, 0x3e, 0x78, 0x00, 0x06, 0x18, 0x70, 0x00, 0x06, 0x24, 0x68, 0x00, 0x06, 0x03,
    0x60, 0x00, 0x06, 0x3f, 0x5c, 0x00, 0x07, 0x05, 0x58, 0x00, 0x07, 0x09, 0x54, 0x00, 0x07, 0x11,
    0x50, 0x00, 0x07, 0x21, 0x4c, 0x00, 0x07, 0x06, 0x48, 0x00, 0x07, 0x0a, 0x44, 0x00, 0x07, 0x12,
    0x40, 0x00, 0x07, 0x22, 0x3e, 0x00, 0x08, 0x07, 0x3c, 0x00, 0x08, 0x0b, 0x3a, 0x00, 0x08, 0x13,
    0x38, 0x00, 0x08, 0x23, 0x36, 0x00, 0x08, 0x0d, 0x34, 0x00, 0x08, 0x31, 0x32, 0x00, 0x08, 0x15,
    0x30, 0x00, 0x08, 0x29, 0x2e, 0x00, 0x08, 0x0e, 0x2c, 0x00, 0x08, 0x32, 0x2a, 0x00, 0x08, 0x16,
    0x28, 0x00, 0x08, 0x2a, 0x26, 0x00, 0x08, 0x0f, 0x24, 0x00, 0x08, 0x33, 0x22, 0x00, 0x08, 0x17,
    0x20, 0x00, 0x08, 0x2b, 0x1e, 0x00, 0x08, 0x19, 0x1c, 0x00, 0x08, 0x25, 0x1a, 0x00, 0x08, 0x1a,
    0x18, 0x00, 0x08, 0x26, 0x16, 0x00, 0x08, 0x1d, 0x14, 0x00, 0x08, 0x2d, 0x12, 0x00, 0x08, 0x35,
    0x10, 0x00, 0x08, 0x39, 0x0e, 0x00, 0x08, 0x1e, 0x0c, 0x00, 0x08, 0x2e, 0x0a, 0x00, 0x08, 0x36,
    0x08, 0x00, 0x08, 0x3a, 0x07, 0x00, 0x09, 0x1f, 0x06, 0x00, 0x09, 0x2f, 0x05, 0x00, 0x09, 0x37,
    0x04, 0x00, 0x09, 0x3b, 0x03, 0x00, 0x09, 0x1b, 0x02, 0x00, 0x09, 0x27, 0x01, 0x00, 0x09, 0x00,
};
// 0x1431baf40
alignas(16) unsigned char DAT_1431baf40[0x30] = {
    0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x02, 0x01, 0x80, 0x00, 0x02, 0x02, 0x40, 0x01, 0x03, 0x03,
    0x80, 0x01, 0x03, 0x04, 0xc0, 0x01, 0x04, 0x05, 0xe0, 0x01, 0x05, 0x06, 0xf0, 0x01, 0x06, 0x07,
    0xf8, 0x01, 0x07, 0x08, 0xfc, 0x01, 0x08, 0x09, 0xfe, 0x01, 0x09, 0x0a, 0xff, 0x01, 0x09, 0x0b,
};
// 0x1431baf70
alignas(16) unsigned char DAT_1431baf70[0x30] = {
    0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x02, 0x01, 0x00, 0x02, 0x02, 0x02, 0x00, 0x03, 0x03, 0x03,
    0x80, 0x03, 0x04, 0x04, 0xc0, 0x03, 0x05, 0x05, 0xe0, 0x03, 0x06, 0x06, 0xf0, 0x03, 0x07, 0x07,
    0xf8, 0x03, 0x08, 0x08, 0xfc, 0x03, 0x09, 0x09, 0xfe, 0x03, 0x0a, 0x0a, 0xff, 0x03, 0x0a, 0x0b,
};
// 0x1431bafa0
alignas(16) unsigned char DAT_1431bafa0[0x380] = {
    0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x04, 0x01, 0x01, 0x00,
    0x00, 0x80, 0x00, 0x00, 0x05, 0x00, 0x02, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x05, 0x02, 0x01, 0x00,
    0x00, 0x50, 0x00, 0x00, 0x06, 0x00, 0x03, 0x00, 0x00, 0x70, 0x00, 0x00, 0x06, 0x03, 0x01, 0x00,
    0x00, 0x60, 0x00, 0x00, 0x06, 0x04, 0x01, 0x00, 0x00, 0x30, 0x00, 0x00, 0x07, 0x01, 0x02, 0x00,
    0x00, 0x38, 0x00, 0x00, 0x07, 0x05, 0x01, 0x00, 0x00, 0x28, 0x00, 0x00, 0x07, 0x06, 0x01, 0x00,
    0x00, 0x20, 0x00, 0x00, 0x07, 0x07, 0x01, 0x00, 0x00, 0x18, 0x00, 0x00, 0x08, 0x00, 0x04, 0x00,
    0x00, 0x10, 0x00, 0x00, 0x08, 0x02, 0x02, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x08, 0x08, 0x01, 0x00,
    0x00, 0x14, 0x00, 0x00, 0x08, 0x09, 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x06, 0x81, 0x81, 0x00,
    0x00, 0x4c, 0x00, 0x00, 0x09, 0x00, 0x05, 0x00, 0x00, 0x42, 0x00, 0x00, 0x09, 0x00, 0x06, 0x00,
    0x00, 0x4a, 0x00, 0x00, 0x09, 0x01, 0x03, 0x00, 0x00, 0x48, 0x00, 0x00, 0x09, 0x03, 0x02, 0x00,
    0x00, 0x4e, 0x00, 0x00, 0x09, 0x0a, 0x01, 0x00, 0x00, 0x46, 0x00, 0x00, 0x09, 0x0b, 0x01, 0x00,
    0x00, 0x44, 0x00, 0x00, 0x09, 0x0c, 0x01, 0x00, 0x00, 0x40, 0x00, 0x00, 0x09, 0x0d, 0x01, 0x00,
    0x00, 0x05, 0x00, 0x00, 0x0b, 0x00, 0x07, 0x00, 0x00, 0x06, 0x00, 0x00, 0x0b, 0x01, 0x04, 0x00,
    0x80, 0x05, 0x00, 0x00, 0x0b, 0x02, 0x03, 0x00, 0x80, 0x07, 0x00, 0x00, 0x0b, 0x04, 0x02, 0x00,
    0x80, 0x04, 0x00, 0x00, 0x0b, 0x05, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x0b, 0x0e, 0x01, 0x00,
    0x80, 0x06, 0x00, 0x00, 0x0b, 0x0f, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0b, 0x10, 0x01, 0x00,
    0xa0, 0x03, 0x00, 0x00, 0x0d, 0x00, 0x08, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0d, 0x00, 0x09, 0x00,
    0x60, 0x02, 0x00, 0x00, 0x0d, 0x00, 0x0a, 0x00, 0x00, 0x02, 0x00, 0x00, 0x0d, 0x00, 0x0b, 0x00,
    0x60, 0x03, 0x00, 0x00, 0x0d, 0x01, 0x05, 0x00, 0x80, 0x02, 0x00, 0x00, 0x0d, 0x02, 0x04, 0x00,
    0x80, 0x03, 0x00, 0x00, 0x0d, 0x03, 0x03, 0x00, 0x40, 0x02, 0x00, 0x00, 0x0d, 0x04, 0x03, 0x00,
    0xc0, 0x03, 0x00, 0x00, 0x0d, 0x06, 0x02, 0x00, 0xa0, 0x02, 0x00, 0x00, 0x0d, 0x07, 0x02, 0x00,
    0x20, 0x02, 0x00, 0x00, 0x0d, 0x08, 0x02, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x0d, 0x11, 0x01, 0x00,
    0x40, 0x03, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00, 0x20, 0x03, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00,
    0xe0, 0x02, 0x00, 0x00, 0x0d, 0x14, 0x01, 0x00, 0xc0, 0x02, 0x00, 0x00, 0x0d, 0x15, 0x01, 0x00,
    0xa0, 0x01, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00, 0x90, 0x01, 0x00, 0x00, 0x0e, 0x00, 0x0d, 0x00,
    0x80, 0x01, 0x00, 0x00, 0x0e, 0x00, 0x0e, 0x00, 0x70, 0x01, 0x00, 0x00, 0x0e, 0x00, 0x0f, 0x00,
    0x60, 0x01, 0x00, 0x00, 0x0e, 0x01, 0x06, 0x00, 0x50, 0x01, 0x00, 0x00, 0x0e, 0x01, 0x07, 0x00,
    0x40, 0x01, 0x00, 0x00, 0x0e, 0x02, 0x05, 0x00, 0x30, 0x01, 0x00, 0x00, 0x0e, 0x03, 0x04, 0x00,
    0x20, 0x01, 0x00, 0x00, 0x0e, 0x05, 0x03, 0x00, 0x10, 0x01, 0x00, 0x00, 0x0e, 0x09, 0x02, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x0e, 0x0a, 0x02, 0x00, 0xf0, 0x01, 0x00, 0x00, 0x0e, 0x16, 0x01, 0x00,
    0xe0, 0x01, 0x00, 0x00, 0x0e, 0x17, 0x01, 0x00, 0xd0, 0x01, 0x00, 0x00, 0x0e, 0x18, 0x01, 0x00,
    0xc0, 0x01, 0x00, 0x00, 0x0e, 0x19, 0x01, 0x00, 0xb0, 0x01, 0x00, 0x00, 0x0e, 0x1a, 0x01, 0x00,
    0xf8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x10, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x11, 0x00,
    0xe8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x12, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x13, 0x00,
    0xd8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x14, 0x00, 0xd0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x15, 0x00,
    0xc8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x16, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x17, 0x00,
    0xb8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x18, 0x00, 0xb0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x19, 0x00,
    0xa8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1a, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1b, 0x00,
    0x98, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1c, 0x00, 0x90, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1d, 0x00,
    0x88, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1e, 0x00, 0x80, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1f, 0x00,
    0x60, 0x00, 0x00, 0x00, 0x10, 0x00, 0x20, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x21, 0x00,
    0x58, 0x00, 0x00, 0x00, 0x10, 0x00, 0x22, 0x00, 0x54, 0x00, 0x00, 0x00, 0x10, 0x00, 0x23, 0x00,
    0x50, 0x00, 0x00, 0x00, 0x10, 0x00, 0x24, 0x00, 0x4c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x25, 0x00,
    0x48, 0x00, 0x00, 0x00, 0x10, 0x00, 0x26, 0x00, 0x44, 0x00, 0x00, 0x00, 0x10, 0x00, 0x27, 0x00,
    0x40, 0x00, 0x00, 0x00, 0x10, 0x00, 0x28, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x10, 0x01, 0x08, 0x00,
    0x78, 0x00, 0x00, 0x00, 0x10, 0x01, 0x09, 0x00, 0x74, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0a, 0x00,
    0x70, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0b, 0x00, 0x6c, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0c, 0x00,
    0x68, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0d, 0x00, 0x64, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0e, 0x00,
    0x26, 0x00, 0x00, 0x00, 0x11, 0x01, 0x0f, 0x00, 0x24, 0x00, 0x00, 0x00, 0x11, 0x01, 0x10, 0x00,
    0x22, 0x00, 0x00, 0x00, 0x11, 0x01, 0x11, 0x00, 0x20, 0x00, 0x00, 0x00, 0x11, 0x01, 0x12, 0x00,
    0x28, 0x00, 0x00, 0x00, 0x11, 0x06, 0x03, 0x00, 0x34, 0x00, 0x00, 0x00, 0x11, 0x0b, 0x02, 0x00,
    0x32, 0x00, 0x00, 0x00, 0x11, 0x0c, 0x02, 0x00, 0x30, 0x00, 0x00, 0x00, 0x11, 0x0d, 0x02, 0x00,
    0x2e, 0x00, 0x00, 0x00, 0x11, 0x0e, 0x02, 0x00, 0x2c, 0x00, 0x00, 0x00, 0x11, 0x0f, 0x02, 0x00,
    0x2a, 0x00, 0x00, 0x00, 0x11, 0x10, 0x02, 0x00, 0x3e, 0x00, 0x00, 0x00, 0x11, 0x1b, 0x01, 0x00,
    0x3c, 0x00, 0x00, 0x00, 0x11, 0x1c, 0x01, 0x00, 0x3a, 0x00, 0x00, 0x00, 0x11, 0x1d, 0x01, 0x00,
    0x38, 0x00, 0x00, 0x00, 0x11, 0x1e, 0x01, 0x00, 0x36, 0x00, 0x00, 0x00, 0x11, 0x1f, 0x01, 0x00,
};
// 0x1431bb320
alignas(16) unsigned char DAT_1431bb320[0x390] = {
    0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00,
    0x00, 0xc0, 0x00, 0x00, 0x04, 0x01, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x05, 0x00, 0x02, 0x00,
    0x00, 0xa0, 0x00, 0x00, 0x05, 0x02, 0x01, 0x00, 0x00, 0x50, 0x00, 0x00, 0x06, 0x00, 0x03, 0x00,
    0x00, 0x70, 0x00, 0x00, 0x06, 0x03, 0x01, 0x00, 0x00, 0x60, 0x00, 0x00, 0x06, 0x04, 0x01, 0x00,
    0x00, 0x30, 0x00, 0x00, 0x07, 0x01, 0x02, 0x00, 0x00, 0x38, 0x00, 0x00, 0x07, 0x05, 0x01, 0x00,
    0x00, 0x28, 0x00, 0x00, 0x07, 0x06, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x07, 0x07, 0x01, 0x00,
    0x00, 0x18, 0x00, 0x00, 0x08, 0x00, 0x04, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x02, 0x02, 0x00,
    0x00, 0x1c, 0x00, 0x00, 0x08, 0x08, 0x01, 0x00, 0x00, 0x14, 0x00, 0x00, 0x08, 0x09, 0x01, 0x00,
    0x00, 0x08, 0x00, 0x00, 0x06, 0x81, 0x81, 0x00, 0x00, 0x4c, 0x00, 0x00, 0x09, 0x00, 0x05, 0x00,
    0x00, 0x42, 0x00, 0x00, 0x09, 0x00, 0x06, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x09, 0x01, 0x03, 0x00,
    0x00, 0x48, 0x00, 0x00, 0x09, 0x03, 0x02, 0x00, 0x00, 0x4e, 0x00, 0x00, 0x09, 0x0a, 0x01, 0x00,
    0x00, 0x46, 0x00, 0x00, 0x09, 0x0b, 0x01, 0x00, 0x00, 0x44, 0x00, 0x00, 0x09, 0x0c, 0x01, 0x00,
    0x00, 0x40, 0x00, 0x00, 0x09, 0x0d, 0x01, 0x00, 0x00, 0x05, 0x00, 0x00, 0x0b, 0x00, 0x07, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x0b, 0x01, 0x04, 0x00, 0x80, 0x05, 0x00, 0x00, 0x0b, 0x02, 0x03, 0x00,
    0x80, 0x07, 0x00, 0x00, 0x0b, 0x04, 0x02, 0x00, 0x80, 0x04, 0x00, 0x00, 0x0b, 0x05, 0x02, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x0b, 0x0e, 0x01, 0x00, 0x80, 0x06, 0x00, 0x00, 0x0b, 0x0f, 0x01, 0x00,
    0x00, 0x04, 0x00, 0x00, 0x0b, 0x10, 0x01, 0x00, 0xa0, 0x03, 0x00, 0x00, 0x0d, 0x00, 0x08, 0x00,
    0x00, 0x03, 0x00, 0x00, 0x0d, 0x00, 0x09, 0x00, 0x60, 0x02, 0x00, 0x00, 0x0d, 0x00, 0x0a, 0x00,
    0x00, 0x02, 0x00, 0x00, 0x0d, 0x00, 0x0b, 0x00, 0x60, 0x03, 0x00, 0x00, 0x0d, 0x01, 0x05, 0x00,
    0x80, 0x02, 0x00, 0x00, 0x0d, 0x02, 0x04, 0x00, 0x80, 0x03, 0x00, 0x00, 0x0d, 0x03, 0x03, 0x00,
    0x40, 0x02, 0x00, 0x00, 0x0d, 0x04, 0x03, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x0d, 0x06, 0x02, 0x00,
    0xa0, 0x02, 0x00, 0x00, 0x0d, 0x07, 0x02, 0x00, 0x20, 0x02, 0x00, 0x00, 0x0d, 0x08, 0x02, 0x00,
    0xe0, 0x03, 0x00, 0x00, 0x0d, 0x11, 0x01, 0x00, 0x40, 0x03, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00,
    0x20, 0x03, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0xe0, 0x02, 0x00, 0x00, 0x0d, 0x14, 0x01, 0x00,
    0xc0, 0x02, 0x00, 0x00, 0x0d, 0x15, 0x01, 0x00, 0xa0, 0x01, 0x00, 0x00, 0x0e, 0x00, 0x0c, 0x00,
    0x90, 0x01, 0x00, 0x00, 0x0e, 0x00, 0x0d, 0x00, 0x80, 0x01, 0x00, 0x00, 0x0e, 0x00, 0x0e, 0x00,
    0x70, 0x01, 0x00, 0x00, 0x0e, 0x00, 0x0f, 0x00, 0x60, 0x01, 0x00, 0x00, 0x0e, 0x01, 0x06, 0x00,
    0x50, 0x01, 0x00, 0x00, 0x0e, 0x01, 0x07, 0x00, 0x40, 0x01, 0x00, 0x00, 0x0e, 0x02, 0x05, 0x00,
    0x30, 0x01, 0x00, 0x00, 0x0e, 0x03, 0x04, 0x00, 0x20, 0x01, 0x00, 0x00, 0x0e, 0x05, 0x03, 0x00,
    0x10, 0x01, 0x00, 0x00, 0x0e, 0x09, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0e, 0x0a, 0x02, 0x00,
    0xf0, 0x01, 0x00, 0x00, 0x0e, 0x16, 0x01, 0x00, 0xe0, 0x01, 0x00, 0x00, 0x0e, 0x17, 0x01, 0x00,
    0xd0, 0x01, 0x00, 0x00, 0x0e, 0x18, 0x01, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x0e, 0x19, 0x01, 0x00,
    0xb0, 0x01, 0x00, 0x00, 0x0e, 0x1a, 0x01, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x10, 0x00,
    0xf0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x11, 0x00, 0xe8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x12, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x13, 0x00, 0xd8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x14, 0x00,
    0xd0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x15, 0x00, 0xc8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x16, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x17, 0x00, 0xb8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x18, 0x00,
    0xb0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x19, 0x00, 0xa8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1a, 0x00,
    0xa0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1b, 0x00, 0x98, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1c, 0x00,
    0x90, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1d, 0x00, 0x88, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1e, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1f, 0x00, 0x60, 0x00, 0x00, 0x00, 0x10, 0x00, 0x20, 0x00,
    0x5c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x21, 0x00, 0x58, 0x00, 0x00, 0x00, 0x10, 0x00, 0x22, 0x00,
    0x54, 0x00, 0x00, 0x00, 0x10, 0x00, 0x23, 0x00, 0x50, 0x00, 0x00, 0x00, 0x10, 0x00, 0x24, 0x00,
    0x4c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x25, 0x00, 0x48, 0x00, 0x00, 0x00, 0x10, 0x00, 0x26, 0x00,
    0x44, 0x00, 0x00, 0x00, 0x10, 0x00, 0x27, 0x00, 0x40, 0x00, 0x00, 0x00, 0x10, 0x00, 0x28, 0x00,
    0x7c, 0x00, 0x00, 0x00, 0x10, 0x01, 0x08, 0x00, 0x78, 0x00, 0x00, 0x00, 0x10, 0x01, 0x09, 0x00,
    0x74, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0a, 0x00, 0x70, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0b, 0x00,
    0x6c, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0c, 0x00, 0x68, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0d, 0x00,
    0x64, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0e, 0x00, 0x26, 0x00, 0x00, 0x00, 0x11, 0x01, 0x0f, 0x00,
    0x24, 0x00, 0x00, 0x00, 0x11, 0x01, 0x10, 0x00, 0x22, 0x00, 0x00, 0x00, 0x11, 0x01, 0x11, 0x00,
    0x20, 0x00, 0x00, 0x00, 0x11, 0x01, 0x12, 0x00, 0x28, 0x00, 0x00, 0x00, 0x11, 0x06, 0x03, 0x00,
    0x34, 0x00, 0x00, 0x00, 0x11, 0x0b, 0x02, 0x00, 0x32, 0x00, 0x00, 0x00, 0x11, 0x0c, 0x02, 0x00,
    0x30, 0x00, 0x00, 0x00, 0x11, 0x0d, 0x02, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x11, 0x0e, 0x02, 0x00,
    0x2c, 0x00, 0x00, 0x00, 0x11, 0x0f, 0x02, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x11, 0x10, 0x02, 0x00,
    0x3e, 0x00, 0x00, 0x00, 0x11, 0x1b, 0x01, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x11, 0x1c, 0x01, 0x00,
    0x3a, 0x00, 0x00, 0x00, 0x11, 0x1d, 0x01, 0x00, 0x38, 0x00, 0x00, 0x00, 0x11, 0x1e, 0x01, 0x00,
    0x36, 0x00, 0x00, 0x00, 0x11, 0x1f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bb6b0
alignas(16) unsigned char DAT_1431bb6b0[0x390] = {
    0x00, 0xc0, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x01, 0x00,
    0x00, 0x80, 0x00, 0x00, 0x04, 0x01, 0x01, 0x00, 0x00, 0x80, 0x01, 0x00, 0x04, 0x00, 0x02, 0x00,
    0x00, 0x50, 0x00, 0x00, 0x06, 0x02, 0x01, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x05, 0x00, 0x03, 0x00,
    0x00, 0x70, 0x00, 0x00, 0x06, 0x03, 0x01, 0x00, 0x00, 0x30, 0x00, 0x00, 0x07, 0x04, 0x01, 0x00,
    0x00, 0x60, 0x00, 0x00, 0x06, 0x01, 0x02, 0x00, 0x00, 0x38, 0x00, 0x00, 0x07, 0x05, 0x01, 0x00,
    0x00, 0x18, 0x00, 0x00, 0x08, 0x06, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x07, 0x01, 0x00,
    0x00, 0xc0, 0x01, 0x00, 0x06, 0x00, 0x04, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x08, 0x02, 0x02, 0x00,
    0x00, 0x14, 0x00, 0x00, 0x08, 0x08, 0x01, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x08, 0x09, 0x01, 0x00,
    0x00, 0x08, 0x00, 0x00, 0x06, 0x81, 0x81, 0x00, 0x00, 0xd0, 0x01, 0x00, 0x06, 0x00, 0x05, 0x00,
    0x00, 0x28, 0x00, 0x00, 0x07, 0x00, 0x06, 0x00, 0x00, 0xe4, 0x01, 0x00, 0x08, 0x01, 0x03, 0x00,
    0x00, 0x4c, 0x00, 0x00, 0x09, 0x03, 0x02, 0x00, 0x00, 0xe8, 0x01, 0x00, 0x08, 0x0a, 0x01, 0x00,
    0x00, 0x42, 0x00, 0x00, 0x09, 0x0b, 0x01, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x09, 0x0c, 0x01, 0x00,
    0x00, 0x48, 0x00, 0x00, 0x09, 0x0d, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x07, 0x00, 0x07, 0x00,
    0x00, 0x4e, 0x00, 0x00, 0x09, 0x01, 0x04, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x09, 0x02, 0x03, 0x00,
    0x00, 0xfa, 0x01, 0x00, 0x09, 0x04, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x0a, 0x05, 0x02, 0x00,
    0x00, 0x05, 0x00, 0x00, 0x0a, 0x0e, 0x01, 0x00, 0x00, 0x07, 0x00, 0x00, 0x0a, 0x0f, 0x01, 0x00,
    0x80, 0x06, 0x00, 0x00, 0x0b, 0x10, 0x01, 0x00, 0x00, 0xec, 0x01, 0x00, 0x08, 0x00, 0x08, 0x00,
    0x00, 0xf0, 0x01, 0x00, 0x08, 0x00, 0x09, 0x00, 0x00, 0x46, 0x00, 0x00, 0x09, 0x00, 0x0a, 0x00,
    0x00, 0x44, 0x00, 0x00, 0x09, 0x00, 0x0b, 0x00, 0x00, 0x40, 0x00, 0x00, 0x09, 0x01, 0x05, 0x00,
    0x00, 0x06, 0x00, 0x00, 0x0b, 0x02, 0x04, 0x00, 0x80, 0x03, 0x00, 0x00, 0x0d, 0x03, 0x03, 0x00,
    0x40, 0x02, 0x00, 0x00, 0x0d, 0x04, 0x03, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x0d, 0x06, 0x02, 0x00,
    0xa0, 0x02, 0x00, 0x00, 0x0d, 0x07, 0x02, 0x00, 0x20, 0x02, 0x00, 0x00, 0x0d, 0x08, 0x02, 0x00,
    0xe0, 0x03, 0x00, 0x00, 0x0d, 0x11, 0x01, 0x00, 0x40, 0x03, 0x00, 0x00, 0x0d, 0x12, 0x01, 0x00,
    0x20, 0x03, 0x00, 0x00, 0x0d, 0x13, 0x01, 0x00, 0xe0, 0x02, 0x00, 0x00, 0x0d, 0x14, 0x01, 0x00,
    0xc0, 0x02, 0x00, 0x00, 0x0d, 0x15, 0x01, 0x00, 0x00, 0xf4, 0x01, 0x00, 0x09, 0x00, 0x0c, 0x00,
    0x00, 0xf6, 0x01, 0x00, 0x09, 0x00, 0x0d, 0x00, 0x00, 0xfc, 0x01, 0x00, 0x09, 0x00, 0x0e, 0x00,
    0x00, 0xfe, 0x01, 0x00, 0x09, 0x00, 0x0f, 0x00, 0x60, 0x01, 0x00, 0x00, 0x0e, 0x01, 0x06, 0x00,
    0x50, 0x01, 0x00, 0x00, 0x0e, 0x01, 0x07, 0x00, 0x40, 0x01, 0x00, 0x00, 0x0e, 0x02, 0x05, 0x00,
    0x30, 0x01, 0x00, 0x00, 0x0e, 0x03, 0x04, 0x00, 0x20, 0x01, 0x00, 0x00, 0x0e, 0x05, 0x03, 0x00,
    0x10, 0x01, 0x00, 0x00, 0x0e, 0x09, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x0e, 0x0a, 0x02, 0x00,
    0xf0, 0x01, 0x00, 0x00, 0x0e, 0x16, 0x01, 0x00, 0xe0, 0x01, 0x00, 0x00, 0x0e, 0x17, 0x01, 0x00,
    0xd0, 0x01, 0x00, 0x00, 0x0e, 0x18, 0x01, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x0e, 0x19, 0x01, 0x00,
    0xb0, 0x01, 0x00, 0x00, 0x0e, 0x1a, 0x01, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x10, 0x00,
    0xf0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x11, 0x00, 0xe8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x12, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x13, 0x00, 0xd8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x14, 0x00,
    0xd0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x15, 0x00, 0xc8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x16, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x17, 0x00, 0xb8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x18, 0x00,
    0xb0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x19, 0x00, 0xa8, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1a, 0x00,
    0xa0, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1b, 0x00, 0x98, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1c, 0x00,
    0x90, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1d, 0x00, 0x88, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1e, 0x00,
    0x80, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x1f, 0x00, 0x60, 0x00, 0x00, 0x00, 0x10, 0x00, 0x20, 0x00,
    0x5c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x21, 0x00, 0x58, 0x00, 0x00, 0x00, 0x10, 0x00, 0x22, 0x00,
    0x54, 0x00, 0x00, 0x00, 0x10, 0x00, 0x23, 0x00, 0x50, 0x00, 0x00, 0x00, 0x10, 0x00, 0x24, 0x00,
    0x4c, 0x00, 0x00, 0x00, 0x10, 0x00, 0x25, 0x00, 0x48, 0x00, 0x00, 0x00, 0x10, 0x00, 0x26, 0x00,
    0x44, 0x00, 0x00, 0x00, 0x10, 0x00, 0x27, 0x00, 0x40, 0x00, 0x00, 0x00, 0x10, 0x00, 0x28, 0x00,
    0x7c, 0x00, 0x00, 0x00, 0x10, 0x01, 0x08, 0x00, 0x78, 0x00, 0x00, 0x00, 0x10, 0x01, 0x09, 0x00,
    0x74, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0a, 0x00, 0x70, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0b, 0x00,
    0x6c, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0c, 0x00, 0x68, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0d, 0x00,
    0x64, 0x00, 0x00, 0x00, 0x10, 0x01, 0x0e, 0x00, 0x26, 0x00, 0x00, 0x00, 0x11, 0x01, 0x0f, 0x00,
    0x24, 0x00, 0x00, 0x00, 0x11, 0x01, 0x10, 0x00, 0x22, 0x00, 0x00, 0x00, 0x11, 0x01, 0x11, 0x00,
    0x20, 0x00, 0x00, 0x00, 0x11, 0x01, 0x12, 0x00, 0x28, 0x00, 0x00, 0x00, 0x11, 0x06, 0x03, 0x00,
    0x34, 0x00, 0x00, 0x00, 0x11, 0x0b, 0x02, 0x00, 0x32, 0x00, 0x00, 0x00, 0x11, 0x0c, 0x02, 0x00,
    0x30, 0x00, 0x00, 0x00, 0x11, 0x0d, 0x02, 0x00, 0x2e, 0x00, 0x00, 0x00, 0x11, 0x0e, 0x02, 0x00,
    0x2c, 0x00, 0x00, 0x00, 0x11, 0x0f, 0x02, 0x00, 0x2a, 0x00, 0x00, 0x00, 0x11, 0x10, 0x02, 0x00,
    0x3e, 0x00, 0x00, 0x00, 0x11, 0x1b, 0x01, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x11, 0x1c, 0x01, 0x00,
    0x3a, 0x00, 0x00, 0x00, 0x11, 0x1d, 0x01, 0x00, 0x38, 0x00, 0x00, 0x00, 0x11, 0x1e, 0x01, 0x00,
    0x36, 0x00, 0x00, 0x00, 0x11, 0x1f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bba40
alignas(16) unsigned char DAT_1431bba40[0x10] = {
    0x06, 0x03, 0x07, 0x04, 0x02, 0x01, 0x05, 0x04, 0x02, 0x05, 0x07, 0x04, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bba50
alignas(16) unsigned char DAT_1431bba50[0x10] = {
    0x00, 0x01, 0x02, 0x01, 0x01, 0x02, 0x03, 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bba60
alignas(16) unsigned char DAT_1431bba60[0x40] = {
    0x00, 0x02, 0x04, 0x06, 0x08, 0x0a, 0x0c, 0x0e, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e,
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x0a, 0x0c, 0x0e, 0x10, 0x12, 0x14, 0x16,
    0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38, 0x40, 0x48, 0x50, 0x58, 0x60, 0x68, 0x70,
};
// 0x1431bbbd8
alignas(8) unsigned char DAT_1431bbbd8[0x20] = {
    0x01, 0x12, 0x01, 0x11, 0x01, 0x10, 0x01, 0x0f, 0x06, 0x03, 0x10, 0x02, 0x0f, 0x02, 0x0e, 0x02,
    0x0d, 0x02, 0x0c, 0x02, 0x0b, 0x02, 0x1f, 0x01, 0x1e, 0x01, 0x1d, 0x01, 0x1c, 0x01, 0x1b, 0x01,
};
// 0x1431bbbf8
alignas(8) unsigned char DAT_1431bbbf8[0x20] = {
    0x00, 0x28, 0x00, 0x27, 0x00, 0x26, 0x00, 0x25, 0x00, 0x24, 0x00, 0x23, 0x00, 0x22, 0x00, 0x21,
    0x00, 0x20, 0x01, 0x0e, 0x01, 0x0d, 0x01, 0x0c, 0x01, 0x0b, 0x01, 0x0a, 0x01, 0x09, 0x01, 0x08,
};
// 0x1431bbc18
alignas(8) unsigned char DAT_1431bbc18[0x20] = {
    0x00, 0x1f, 0x00, 0x1e, 0x00, 0x1d, 0x00, 0x1c, 0x00, 0x1b, 0x00, 0x1a, 0x00, 0x19, 0x00, 0x18,
    0x00, 0x17, 0x00, 0x16, 0x00, 0x15, 0x00, 0x14, 0x00, 0x13, 0x00, 0x12, 0x00, 0x11, 0x00, 0x10,
};
// 0x1431bbc38
alignas(8) unsigned char DAT_1431bbc38[0x20] = {
    0x0a, 0x02, 0x09, 0x02, 0x05, 0x03, 0x03, 0x04, 0x02, 0x05, 0x01, 0x07, 0x01, 0x06, 0x00, 0x0f,
    0x00, 0x0e, 0x00, 0x0d, 0x00, 0x0c, 0x1a, 0x01, 0x19, 0x01, 0x18, 0x01, 0x17, 0x01, 0x16, 0x01,
};
// 0x1431bbc58
alignas(8) unsigned char DAT_1431bbc58[0x20] = {
    0x00, 0x0b, 0x08, 0x02, 0x04, 0x03, 0x00, 0x0a, 0x02, 0x04, 0x07, 0x02, 0x15, 0x01, 0x14, 0x01,
    0x00, 0x09, 0x13, 0x01, 0x12, 0x01, 0x01, 0x05, 0x03, 0x03, 0x00, 0x08, 0x06, 0x02, 0x11, 0x01,
};
// 0x1431bbc78
alignas(8) unsigned char DAT_1431bbc78[0x18] = {
    0x10, 0x01, 0x05, 0x02, 0x00, 0x07, 0x02, 0x03, 0x01, 0x04, 0x0f, 0x01, 0x0e, 0x01, 0x04, 0x02,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bbc90
alignas(16) unsigned char DAT_1431bbc90[0x40] = {
    0xcd, 0x3b, 0x7f, 0x66, 0x9e, 0xa0, 0xd6, 0x3f, 0xb0, 0x5c, 0xf7, 0xcf, 0x97, 0x62, 0xdf, 0x3f,
    0x46, 0x8d, 0x32, 0xcf, 0x6b, 0x90, 0xdd, 0x3f, 0xa3, 0xa1, 0x0e, 0x29, 0x66, 0x9b, 0xda, 0x3f,
    0xcd, 0x3b, 0x7f, 0x66, 0x9e, 0xa0, 0xd6, 0x3f, 0xc8, 0x68, 0xae, 0x39, 0x3b, 0xc7, 0xd1, 0x3f,
    0x63, 0xa9, 0xae, 0xa6, 0xe2, 0x7d, 0xc8, 0x3f, 0x0b, 0xa6, 0x69, 0x3c, 0xb8, 0xf8, 0xb8, 0x3f,
};
// 0x1431bbcd0
alignas(16) unsigned char DAT_1431bbcd0[0x50] = {
    0xf3, 0x04, 0xb5, 0x3f, 0xf3, 0x04, 0xb5, 0x3f, 0xf3, 0x04, 0xb5, 0x3f, 0xf3, 0x04, 0xb5, 0x3f,
    0x75, 0x3d, 0x27, 0x40, 0x75, 0x3d, 0x27, 0x40, 0x75, 0x3d, 0x27, 0x40, 0x75, 0x3d, 0x27, 0x40,
    0xf3, 0x04, 0xb5, 0x3f, 0xf3, 0x04, 0xb5, 0x3f, 0xf3, 0x04, 0xb5, 0x3f, 0xf3, 0x04, 0xb5, 0x3f,
    0xd4, 0x8b, 0x8a, 0x3f, 0xd4, 0x8b, 0x8a, 0x3f, 0xd4, 0x8b, 0x8a, 0x3f, 0xd4, 0x8b, 0x8a, 0x3f,
    0x15, 0xef, 0x43, 0x3f, 0x15, 0xef, 0x43, 0x3f, 0x15, 0xef, 0x43, 0x3f, 0x15, 0xef, 0x43, 0x3f,
};
// 0x1431bbd20
alignas(16) Sd_1431bbd20 DAT_1431bbd20 = {
    (const void*)&FUN_140066450,
    (const void*)&FUN_140066de0,
    (const void*)&FUN_140066d80,
    (const void*)&FUN_140066da0,
};
// 0x1431bbd40
alignas(16) Sd_1431bbd40 DAT_1431bbd40 = {
    (const void*)&FUN_142cccba0,
    (const void*)&FUN_142cccd80,
};
// 0x1431bbd50
alignas(16) Sd_1431bbd50 DAT_1431bbd50 = {
    (const void*)&FUN_142cccef0,
    (const void*)&FUN_142ccd080,
};
// 0x1431bbd60
alignas(16) unsigned char DAT_1431bbd60[0x1d] = {
    0xff, 0xff, 0xff, 0x7f, 0xff, 0x3f, 0xff, 0x1f, 0xff, 0x0f, 0xff, 0x07, 0xff, 0x03, 0xff, 0x01,
    0xff, 0x00, 0x7f, 0x00, 0x3f, 0x00, 0x1f, 0x00, 0x0f, 0x00, 0x07, 0x00, 0x03,
};
alignas(1) unsigned char DAT_1431bbd7d[0x1];                    // 0x1431bbd7d
// 0x1431bbd7e
alignas(2) unsigned char DAT_1431bbd7e[0x1] = {
    0x01,
};
alignas(1) unsigned char DAT_1431bbd7f[0x1];                    // 0x1431bbd7f
// 0x1431bbd80
alignas(16) unsigned char DAT_1431bbd80[0x3c] = {
    0x00, 0x01, 0x08, 0x10, 0x09, 0x02, 0x03, 0x0a, 0x11, 0x18, 0x20, 0x19, 0x12, 0x0b, 0x04, 0x05,
    0x0c, 0x13, 0x1a, 0x21, 0x28, 0x30, 0x29, 0x22, 0x1b, 0x14, 0x0d, 0x06, 0x07, 0x0e, 0x15, 0x1c,
    0x23, 0x2a, 0x31, 0x38, 0x39, 0x32, 0x2b, 0x24, 0x1d, 0x16, 0x0f, 0x17, 0x1e, 0x25, 0x2c, 0x33,
    0x3a, 0x3b, 0x34, 0x2d, 0x26, 0x1f, 0x27, 0x2e, 0x35, 0x3c, 0x3d, 0x36,
};
// 0x1431bbdbc
alignas(4) unsigned char DAT_1431bbdbc[0x2] = {
    0x2f, 0x37,
};
// 0x1431bbdbe
alignas(2) unsigned char DAT_1431bbdbe[0x1] = {
    0x3e,
};
// 0x1431bbdbf
alignas(1) unsigned char DAT_1431bbdbf[0x2] = {
    0x3f, 0x08,
};
// 0x1431bbdc1
alignas(1) unsigned char DAT_1431bbdc1[0x5f] = {
    0x10, 0x13, 0x16, 0x1a, 0x1b, 0x1d, 0x22, 0x10, 0x10, 0x16, 0x18, 0x1b, 0x1d, 0x22, 0x25, 0x13,
    0x16, 0x1a, 0x1b, 0x1d, 0x22, 0x22, 0x26, 0x16, 0x16, 0x1a, 0x1b, 0x1d, 0x22, 0x25, 0x28, 0x16,
    0x1a, 0x1b, 0x1d, 0x20, 0x23, 0x28, 0x30, 0x1a, 0x1b, 0x1d, 0x20, 0x23, 0x28, 0x30, 0x3a, 0x1a,
    0x1b, 0x1d, 0x22, 0x26, 0x2e, 0x38, 0x45, 0x1b, 0x1d, 0x23, 0x26, 0x2e, 0x38, 0x45, 0x53, 0x05,
    0x04, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bc290
alignas(16) Sd_1431bc290 DAT_1431bc290 = {
    (const void*)&FUN_140068510,
    (const void*)&FUN_140068520,
    (const void*)&FUN_140068540,
    (const void*)&FUN_140068560,
};
// 0x1431bc310
alignas(16) unsigned char DAT_1431bc310[0x40] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x3f, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x40, 0x40,
    0x00, 0x00, 0x80, 0x40, 0x00, 0x00, 0xa0, 0x40, 0x00, 0x00, 0xc0, 0x40, 0x00, 0x00, 0xe0, 0x40,
    0x00, 0x00, 0x00, 0xc1, 0x00, 0x00, 0xe0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0xa0, 0xc0,
    0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x40, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x80, 0xbf,
};
// 0x1431bc350
alignas(16) unsigned char DAT_1431bc350[0x48] = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00,
    0xf8, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xfa, 0xff, 0xff, 0xff, 0xfb, 0xff, 0xff, 0xff,
    0xfc, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x00, 0x01, 0x00, 0x36, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bc3b8
alignas(8) unsigned char DAT_1431bc3b8[0x30] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
};
// 0x1431bc3e8
alignas(8) unsigned char DAT_1431bc3e8[0x10] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bc3f8
alignas(8) unsigned char DAT_1431bc3f8[0x18] = {
    0x00, 0x80, 0x00, 0x40, 0x00, 0x20, 0x00, 0x10, 0x00, 0x08, 0x00, 0x04, 0x00, 0x02, 0x00, 0x01,
    0x80, 0x00, 0x40, 0x00, 0x20, 0x00, 0x10, 0x00,
};
// 0x1431bc410
alignas(16) unsigned char DAT_1431bc410[0x30] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
};
// 0x1431bc440
alignas(16) unsigned char DAT_1431bc440[0x10] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
// 0x1431bc450
alignas(16) Sd_1431bc450 DAT_1431bc450 = {
    (const void*)&FUN_14008c880,
    (const void*)&FUN_14008d280,
    (const void*)&FUN_14008d220,
    (const void*)&FUN_14008d240,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00,
    },
};
// 0x1431bc6c0
alignas(16) Sd_1431bc6c0 DAT_1431bc6c0 = {
    (const void*)&FUN_140095b40,
    (const void*)&FUN_14009a3d0,
    (const void*)&FUN_14009ec40,
};
// 0x1431bc6d8
alignas(8) Sd_1431bc6d8 DAT_1431bc6d8 = {
    (const void*)&FUN_1400a3920,
    (const void*)&FUN_1400a8ad0,
    (const void*)&FUN_1400adc50,
};
// 0x1431bcbb0
alignas(16) Sd_1431bcbb0 DAT_1431bcbb0 = {
    (const void*)&FUN_142743db0,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    (const void*)&FUN_1427439d0,
};
// 0x1431bcbe8
alignas(8) Sd_1431bcbe8 DAT_1431bcbe8 = {
    (const void*)&FUN_142743c10,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    (const void*)&FUN_1427447e0,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    (const void*)&FUN_142743c80,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    (const void*)&FUN_1427447e0,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
};
// 0x1431bec40
alignas(16) Sd_1431bec40 DAT_1431bec40 = {
    (const void*)&FUN_142743a30,
    (const void*)&FUN_142746220,
};
// 0x1431bec50
alignas(16) Sd_1431bec50 DAT_1431bec50 = {
    (const void*)&FUN_142743f00,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
    DAT_14280ef52,
};
// 0x1431bec80
alignas(16) Sd_1431bec80 DAT_1431bec80 = {
    (const void*)&FUN_1427439b8,
    (const void*)&FUN_142746220,
};
// 0x1431bec90
alignas(16) Sd_1431bec90 DAT_1431bec90 = {
    (const void*)&FUN_142743b60,
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
};
// 0x1431bed08
alignas(8) Sd_1431bed08 DAT_1431bed08 = {
    (const void*)&FUN_142743994,
    (const void*)&FUN_142746220,
};
// 0x1431bed18
alignas(8) Sd_1431bed18 DAT_1431bed18 = {
    (const void*)&FUN_142743e00,
    (const void*)&FUN_142745b80,
    (const void*)&FUN_142745c30,
    (const void*)&FUN_1427457e0,
    (const void*)&FUN_1427457a0,
    (const void*)&FUN_142745760,
    (const void*)&FUN_142746a40,
};
// 0x1431bed50
alignas(16) Sd_1431bed50 DAT_1431bed50 = {
    (const void*)&FUN_1427439a0,
    (const void*)&FUN_1427462b0,
};
// 0x1431bed60
alignas(16) Sd_1431bed60 DAT_1431bed60 = {
    (const void*)&FUN_142743a60,
    (const void*)&FUN_142745b70,
    (const void*)&FUN_142745ab0,
    (const void*)&FUN_142746d70,
    (const void*)&FUN_142745ea0,
    (const void*)&FUN_142745c40,
    (const void*)&FUN_142746510,
    (const void*)&FUN_1427458e0,
    (const void*)&FUN_142745c80,
    (const void*)&FUN_142745b90,
    (const void*)&FUN_142746a30,
    (const void*)&FUN_1427458b0,
    (const void*)&FUN_142746500,
    (const void*)&FUN_1427466d0,
    (const void*)&FUN_1427466c0,
};
// 0x1431bedd8
alignas(8) Sd_1431bedd8 DAT_1431bedd8 = {
    (const void*)&FUN_14274397c,
    (const void*)&FUN_142746230,
};
// 0x1431bede8
alignas(8) Sd_1431bede8 DAT_1431bede8 = {
    (const void*)&FUN_142743cf0,
    (const void*)&FUN_142745a90,
    (const void*)&FUN_142744ea0,
    (const void*)&FUN_1427449f0,
    (const void*)&FUN_1427447f0,
    (const void*)&FUN_142745f30,
    (const void*)&FUN_142745840,
    (const void*)&FUN_1427464c0,
    (const void*)&FUN_1427471a0,
    (const void*)&FUN_142745e70,
    (const void*)&FUN_142745830,
    (const void*)&FUN_142745bc0,
    (const void*)&FUN_142745620,
};
// 0x1431bee50
alignas(16) Sd_1431bee50 DAT_1431bee50 = {
    (const void*)&FUN_142743fa0,
    (const void*)&FUN_142745880,
    (const void*)&FUN_142746640,
};
// 0x1431bee68
alignas(8) Sd_1431bee68 DAT_1431bee68 = {
    (const void*)&FUN_1427439c4,
    (const void*)&FUN_142746380,
};
// 0x1431bee78
alignas(8) Sd_1431bee78 DAT_1431bee78 = {
    (const void*)&FUN_142743ac0,
    (const void*)&FUN_142745b70,
    (const void*)&FUN_142745ab0,
    (const void*)&FUN_142746da0,
    (const void*)&FUN_142745eb0,
    (const void*)&FUN_142745c40,
    (const void*)&FUN_142746560,
    (const void*)&FUN_142745980,
    (const void*)&FUN_142745c80,
    (const void*)&FUN_142745b90,
    (const void*)&FUN_142746a30,
    (const void*)&FUN_1427458b0,
    (const void*)&FUN_142746500,
    (const void*)&FUN_1427466d0,
    (const void*)&FUN_1427466c0,
};
// 0x1431beef0
alignas(16) Sd_1431beef0 DAT_1431beef0 = {
    (const void*)&FUN_142743988,
    (const void*)&FUN_142746230,
};
// 0x1431bef00
alignas(16) Sd_1431bef00 DAT_1431bef00 = {
    (const void*)&FUN_142743e60,
    (const void*)&FUN_142745b80,
    (const void*)&FUN_142745c30,
    (const void*)&FUN_1427457e0,
    (const void*)&FUN_1427457a0,
    (const void*)&FUN_142745760,
    (const void*)&FUN_142746bd0,
};
// 0x1431bef38
alignas(8) Sd_1431bef38 DAT_1431bef38 = {
    (const void*)&FUN_1427439ac,
    (const void*)&FUN_1427462b0,
};
// The .bss blocks below are CRI/video state the code walks as larger objects than the per-address names
// (stride tables, pair/decode tables, ...). The compiler does not keep .bss globals in source order, so
// each one gets an ordered .bss$ group section named by its exe address: the link keeps them contiguous
// in exe order with nothing in between.
#pragma bss_seg(".bss$crid_143b27438")
void* DAT_143b27438;                                            // 0x143b27438
#pragma bss_seg(".bss$crid_143b27440")
void* DAT_143b27440;                                            // 0x143b27440
#pragma bss_seg(".bss$crid_143b27448")
void* DAT_143b27448;                                            // 0x143b27448
#pragma bss_seg(".bss$crid_143b27450")
void* DAT_143b27450;                                            // 0x143b27450
#pragma bss_seg(".bss$crid_143b27458")
void* DAT_143b27458;                                            // 0x143b27458
#pragma bss_seg(".bss$crid_143b27460")
void* DAT_143b27460;                                            // 0x143b27460
#pragma bss_seg(".bss$crid_143b27468")
void* DAT_143b27468;                                            // 0x143b27468
#pragma bss_seg(".bss$crid_143b27470")
void* DAT_143b27470;                                            // 0x143b27470
#pragma bss_seg(".bss$crid_143b27478")
void* DAT_143b27478;                                            // 0x143b27478
#pragma bss_seg(".bss$crid_143b27480")
void* DAT_143b27480;                                            // 0x143b27480
#pragma bss_seg(".bss$crid_143b27488")
void* DAT_143b27488;                                            // 0x143b27488
#pragma bss_seg(".bss$crid_143b27490")
void* DAT_143b27490;                                            // 0x143b27490
#pragma bss_seg(".bss$crid_143b27498")
void* DAT_143b27498;                                            // 0x143b27498
#pragma bss_seg(".bss$crid_143b274a0")
int DAT_143b274a0;                                              // 0x143b274a0
#pragma bss_seg(".bss$crid_143b274a8")
void* DAT_143b274a8;                                            // 0x143b274a8
#pragma bss_seg(".bss$crid_143b274b0")
int DAT_143b274b0;                                              // 0x143b274b0
#pragma bss_seg(".bss$crid_143b274b8")
void* DAT_143b274b8;                                            // 0x143b274b8
#pragma bss_seg(".bss$crid_143b274c0")
void* DAT_143b274c0;                                            // 0x143b274c0
#pragma bss_seg(".bss$crid_143b274c8")
void* DAT_143b274c8;                                            // 0x143b274c8
#pragma bss_seg(".bss$crid_143b274d0")
void* DAT_143b274d0;                                            // 0x143b274d0
#pragma bss_seg(".bss$crid_143b274d8")
void* DAT_143b274d8;                                            // 0x143b274d8
#pragma bss_seg(".bss$crid_143b274e0")
void* DAT_143b274e0;                                            // 0x143b274e0
#pragma bss_seg(".bss$crid_143b274e8")
void* DAT_143b274e8;                                            // 0x143b274e8
#pragma bss_seg(".bss$crid_143b274f0")
void* DAT_143b274f0;                                            // 0x143b274f0
#pragma bss_seg(".bss$crid_143b274f8")
void* DAT_143b274f8;                                            // 0x143b274f8
#pragma bss_seg(".bss$crid_143b27500")
void* DAT_143b27500;                                            // 0x143b27500
#pragma bss_seg(".bss$crid_143b27508")
void* DAT_143b27508;                                            // 0x143b27508
#pragma bss_seg(".bss$crid_143b27510")
void* DAT_143b27510;                                            // 0x143b27510
#pragma bss_seg(".bss$crid_143b27518")
void* DAT_143b27518;                                            // 0x143b27518
#pragma bss_seg(".bss$crid_143b27520")
void* DAT_143b27520;                                            // 0x143b27520
#pragma bss_seg(".bss$crid_143b27528")
void* DAT_143b27528;                                            // 0x143b27528
#pragma bss_seg(".bss$crid_143b27530")
void* DAT_143b27530;                                            // 0x143b27530
#pragma bss_seg(".bss$crid_143b27538")
void* DAT_143b27538;                                            // 0x143b27538
#pragma bss_seg(".bss$crid_143b27540")
void* DAT_143b27540;                                            // 0x143b27540
#pragma bss_seg(".bss$crid_143b27548")
void* DAT_143b27548;                                            // 0x143b27548
#pragma bss_seg(".bss$crid_143b27550")
void* DAT_143b27550;                                            // 0x143b27550
#pragma bss_seg(".bss$crid_143b27558")
void* DAT_143b27558;                                            // 0x143b27558
#pragma bss_seg(".bss$crid_143b27560")
int DAT_143b27560;                                              // 0x143b27560
#pragma bss_seg(".bss$crid_143b27568")
void* DAT_143b27568;                                            // 0x143b27568
#pragma bss_seg(".bss$crid_143b27570")
void* DAT_143b27570;                                            // 0x143b27570
#pragma bss_seg(".bss$crid_143b27578")
void* DAT_143b27578;                                            // 0x143b27578
#pragma bss_seg(".bss$crid_143b27580")
void* DAT_143b27580;                                            // 0x143b27580
#pragma bss_seg(".bss$crid_143b27588")
void* DAT_143b27588;                                            // 0x143b27588
#pragma bss_seg(".bss$crid_143b27590")
void* DAT_143b27590;                                            // 0x143b27590
#pragma bss_seg(".bss$crid_143b27598")
void* DAT_143b27598;                                            // 0x143b27598
#pragma bss_seg(".bss$crid_143b275a0")
void* DAT_143b275a0;                                            // 0x143b275a0
#pragma bss_seg(".bss$crid_143b275a8")
void* DAT_143b275a8;                                            // 0x143b275a8
#pragma bss_seg(".bss$crid_143b275b0")
void* DAT_143b275b0;                                            // 0x143b275b0
#pragma bss_seg(".bss$crid_143b275b8")
void* DAT_143b275b8;                                            // 0x143b275b8
#pragma bss_seg(".bss$crid_143b275c0")
void* DAT_143b275c0;                                            // 0x143b275c0
#pragma bss_seg(".bss$crid_143b275c8")
void* DAT_143b275c8;                                            // 0x143b275c8
#pragma bss_seg(".bss$crid_143b275d0")
void* DAT_143b275d0;                                            // 0x143b275d0
#pragma bss_seg(".bss$crid_143b275d8")
void* DAT_143b275d8;                                            // 0x143b275d8
#pragma bss_seg(".bss$crid_143b275e0")
int DAT_143b275e0;                                              // 0x143b275e0
#pragma bss_seg(".bss$crid_143b275e8")
void* DAT_143b275e8;                                            // 0x143b275e8
#pragma bss_seg(".bss$crid_143b275f0")
void* DAT_143b275f0;                                            // 0x143b275f0
#pragma bss_seg(".bss$crid_143b275f8")
void* DAT_143b275f8;                                            // 0x143b275f8
#pragma bss_seg(".bss$crid_143b27600")
void* DAT_143b27600;                                            // 0x143b27600
#pragma bss_seg(".bss$crid_143b27608")
void* DAT_143b27608;                                            // 0x143b27608
#pragma bss_seg(".bss$crid_143b27610")
void* DAT_143b27610;                                            // 0x143b27610
#pragma bss_seg(".bss$crid_143b27618")
void* DAT_143b27618;                                            // 0x143b27618
#pragma bss_seg(".bss$crid_143b27620")
void* DAT_143b27620;                                            // 0x143b27620
#pragma bss_seg(".bss$crid_143b27628")
void* DAT_143b27628;                                            // 0x143b27628
#pragma bss_seg(".bss$crid_143b27630")
void* DAT_143b27630;                                            // 0x143b27630
#pragma bss_seg(".bss$crid_143b27638")
void* DAT_143b27638;                                            // 0x143b27638
#pragma bss_seg(".bss$crid_143b27640")
void* DAT_143b27640;                                            // 0x143b27640
#pragma bss_seg(".bss$crid_143b27648")
void* DAT_143b27648;                                            // 0x143b27648
#pragma bss_seg(".bss$crid_143b27650")
void* DAT_143b27650;                                            // 0x143b27650
#pragma bss_seg(".bss$crid_143b27658")
void* DAT_143b27658;                                            // 0x143b27658
#pragma bss_seg(".bss$crid_143b27660")
void* DAT_143b27660;                                            // 0x143b27660
#pragma bss_seg(".bss$crid_143b27668")
void* DAT_143b27668;                                            // 0x143b27668
#pragma bss_seg(".bss$crid_143b27670")
int DAT_143b27670;                                              // 0x143b27670
#pragma bss_seg(".bss$crid_143b27678")
void* DAT_143b27678;                                            // 0x143b27678
#pragma bss_seg(".bss$crid_143b27680")
void* DAT_143b27680;                                            // 0x143b27680
#pragma bss_seg(".bss$crid_143b27688")
void* DAT_143b27688;                                            // 0x143b27688
#pragma bss_seg(".bss$crid_143b27690")
void* DAT_143b27690;                                            // 0x143b27690
#pragma bss_seg(".bss$crid_143b27698")
void* DAT_143b27698;                                            // 0x143b27698
#pragma bss_seg(".bss$crid_143b276a0")
void* DAT_143b276a0;                                            // 0x143b276a0
#pragma bss_seg(".bss$crid_143b276a8")
void* DAT_143b276a8;                                            // 0x143b276a8
#pragma bss_seg(".bss$crid_143b276b0")
void* DAT_143b276b0;                                            // 0x143b276b0
#pragma bss_seg(".bss$crid_143b276b8")
void* DAT_143b276b8;                                            // 0x143b276b8
#pragma bss_seg(".bss$crid_143b276c0")
void* DAT_143b276c0;                                            // 0x143b276c0
#pragma bss_seg(".bss$crid_143b276c8")
void* DAT_143b276c8;                                            // 0x143b276c8
#pragma bss_seg(".bss$crid_143b276d0")
void* DAT_143b276d0;                                            // 0x143b276d0
#pragma bss_seg(".bss$crid_143b276d8")
void* DAT_143b276d8;                                            // 0x143b276d8
#pragma bss_seg(".bss$crid_143b276e0")
void* DAT_143b276e0;                                            // 0x143b276e0
#pragma bss_seg(".bss$crid_143b276e8")
void* DAT_143b276e8;                                            // 0x143b276e8
#pragma bss_seg(".bss$crid_143b276f0")
void* DAT_143b276f0;                                            // 0x143b276f0
#pragma bss_seg(".bss$crid_143b276f8")
void* DAT_143b276f8;                                            // 0x143b276f8
#pragma bss_seg(".bss$crid_143b27700")
int DAT_143b27700;                                              // 0x143b27700
#pragma bss_seg(".bss$crid_143b27708")
void* DAT_143b27708;                                            // 0x143b27708
#pragma bss_seg(".bss$crid_143b27710")
void* DAT_143b27710;                                            // 0x143b27710
#pragma bss_seg(".bss$crid_143b27718")
void* DAT_143b27718;                                            // 0x143b27718
#pragma bss_seg(".bss$crid_143b27720")
void* DAT_143b27720;                                            // 0x143b27720
#pragma bss_seg(".bss$crid_143b27728")
void* DAT_143b27728;                                            // 0x143b27728
#pragma bss_seg(".bss$crid_143b27730")
void* DAT_143b27730;                                            // 0x143b27730
#pragma bss_seg(".bss$crid_143b27738")
void* DAT_143b27738;                                            // 0x143b27738
#pragma bss_seg(".bss$crid_143b27740")
void* DAT_143b27740;                                            // 0x143b27740
#pragma bss_seg(".bss$crid_143b27748")
void* DAT_143b27748;                                            // 0x143b27748
#pragma bss_seg(".bss$crid_143b27750")
void* DAT_143b27750;                                            // 0x143b27750
#pragma bss_seg(".bss$crid_143b27758")
void* DAT_143b27758;                                            // 0x143b27758
#pragma bss_seg(".bss$crid_143b27760")
void* DAT_143b27760;                                            // 0x143b27760
#pragma bss_seg(".bss$crid_143b27768")
void* DAT_143b27768;                                            // 0x143b27768
#pragma bss_seg(".bss$crid_143b27770")
void* DAT_143b27770;                                            // 0x143b27770
#pragma bss_seg(".bss$crid_143b27778")
void* DAT_143b27778;                                            // 0x143b27778
#pragma bss_seg(".bss$crid_143b27780")
void* DAT_143b27780;                                            // 0x143b27780
#pragma bss_seg(".bss$crid_143b27788")
void* DAT_143b27788;                                            // 0x143b27788
#pragma bss_seg(".bss$crid_143b27790")
int DAT_143b27790;                                              // 0x143b27790
#pragma bss_seg(".bss$crid_143b27798")
void* DAT_143b27798;                                            // 0x143b27798
#pragma bss_seg(".bss$crid_143b277a0")
void* DAT_143b277a0;                                            // 0x143b277a0
#pragma bss_seg(".bss$crid_143b277a8")
void* DAT_143b277a8;                                            // 0x143b277a8
#pragma bss_seg(".bss$crid_143b277b0")
unsigned long DAT_143b277b0;                                    // 0x143b277b0
#pragma bss_seg(".bss$crid_143b277b4")
unsigned int DAT_143b277b4;                                     // 0x143b277b4
#pragma bss_seg(".bss$crid_143b277b8")
const char* DAT_143b277b8;                                      // 0x143b277b8
#pragma bss_seg(".bss$crid_143b277c0")
alignas(16) unsigned char DAT_143b277c0[0x100];                 // 0x143b277c0
#pragma bss_seg(".bss$crid_143b278c0")
alignas(16) unsigned char DAT_143b278c0[0x4];                   // 0x143b278c0
#pragma bss_seg(".bss$crid_143b278c4")
unsigned long DAT_143b278c4;                                    // 0x143b278c4
#pragma bss_seg(".bss$crid_143b278c8")
unsigned long DAT_143b278c8;                                    // 0x143b278c8
#pragma bss_seg(".bss$crid_143b278d0")
const char* DAT_143b278d0;                                      // 0x143b278d0
#pragma bss_seg(".bss$crid_143b278d8")
long DAT_143b278d8;                                             // 0x143b278d8
#pragma bss_seg(".bss$crid_143b278e0")
void* DAT_143b278e0;                                            // 0x143b278e0
#pragma bss_seg(".bss$crid_143b278f0")
alignas(16) unsigned char DAT_143b278f0[0x58];                  // 0x143b278f0
#pragma bss_seg(".bss$crid_143b27948")
alignas(8) unsigned char DAT_143b27948[0x4];                    // 0x143b27948
#pragma bss_seg(".bss$crid_143b2794c")
alignas(4) unsigned char DAT_143b2794c[0x4];                    // 0x143b2794c
#pragma bss_seg(".bss$crid_143b27950")
alignas(16) unsigned char DAT_143b27950[0xf0];                  // 0x143b27950
#pragma bss_seg(".bss$crid_143b27a40")
alignas(16) unsigned char DAT_143b27a40[0x8];                   // 0x143b27a40
#pragma bss_seg(".bss$crid_143b27a48")
alignas(8) unsigned char DAT_143b27a48[0x20];                   // 0x143b27a48
#pragma bss_seg(".bss$crid_143b27a68")
alignas(8) unsigned char DAT_143b27a68[0x20];                   // 0x143b27a68
#pragma bss_seg(".bss$crid_143b27a88")
alignas(8) unsigned char DAT_143b27a88[0x20];                   // 0x143b27a88
#pragma bss_seg(".bss$crid_143b27aa8")
alignas(8) unsigned char DAT_143b27aa8[0x8];                    // 0x143b27aa8
#pragma bss_seg(".bss$crid_143b27ab0")
alignas(16) unsigned char DAT_143b27ab0[0x100];                 // 0x143b27ab0
#pragma bss_seg(".bss$crid_143b27bb0")
alignas(16) unsigned char DAT_143b27bb0[0x8];                   // 0x143b27bb0
#pragma bss_seg(".bss$crid_143b27bb8")
alignas(8) unsigned char DAT_143b27bb8[0x8];                    // 0x143b27bb8
#pragma bss_seg(".bss$crid_143b27bc0")
alignas(16) unsigned char DAT_143b27bc0[0x8];                   // 0x143b27bc0
#pragma bss_seg(".bss$crid_143b27bc8")
alignas(8) unsigned char DAT_143b27bc8[0x4];                    // 0x143b27bc8
#pragma bss_seg(".bss$crid_143b27bcc")
alignas(4) unsigned char DAT_143b27bcc[0x4];                    // 0x143b27bcc
#pragma bss_seg(".bss$crid_143b27bd0")
alignas(16) unsigned char DAT_143b27bd0[0x10];                  // 0x143b27bd0
#pragma bss_seg(".bss$crid_143b27be0")
alignas(16) unsigned char DAT_143b27be0[0x8];                   // 0x143b27be0
#pragma bss_seg(".bss$crid_143b27be8")
alignas(8) unsigned char DAT_143b27be8[0x8];                    // 0x143b27be8
#pragma bss_seg(".bss$crid_143b27bf0")
alignas(16) unsigned char DAT_143b27bf0[0x4c];                  // 0x143b27bf0
#pragma bss_seg(".bss$crid_143b27c3c")
alignas(4) unsigned char DAT_143b27c3c[0x4];                    // 0x143b27c3c
#pragma bss_seg(".bss$crid_143b27c40")
alignas(16) unsigned char DAT_143b27c40[0x8];                   // 0x143b27c40
#pragma bss_seg(".bss$crid_143b27c48")
alignas(8) unsigned char DAT_143b27c48[0x8];                    // 0x143b27c48
#pragma bss_seg(".bss$crid_143b27c50")
alignas(16) unsigned char DAT_143b27c50[0x8];                   // 0x143b27c50
#pragma bss_seg(".bss$crid_143b27c58")
alignas(8) unsigned char DAT_143b27c58[0x8];                    // 0x143b27c58
#pragma bss_seg(".bss$crid_143b27c60")
alignas(16) unsigned char DAT_143b27c60[0x4];                   // 0x143b27c60
#pragma bss_seg(".bss$crid_143b27c64")
alignas(4) unsigned char DAT_143b27c64[0x4];                    // 0x143b27c64
#pragma bss_seg(".bss$crid_143b27c68")
alignas(8) unsigned char DAT_143b27c68[0x4];                    // 0x143b27c68
#pragma bss_seg(".bss$crid_143b27c6c")
alignas(4) unsigned char DAT_143b27c6c[0x4];                    // 0x143b27c6c
#pragma bss_seg(".bss$crid_143b27c70")
alignas(16) unsigned char DAT_143b27c70[0x8];                   // 0x143b27c70
#pragma bss_seg(".bss$crid_143b27c78")
alignas(8) unsigned char DAT_143b27c78[0x8];                    // 0x143b27c78
#pragma bss_seg(".bss$crid_143b27c80")
alignas(16) unsigned char DAT_143b27c80[0x82088];               // 0x143b27c80
#pragma bss_seg(".bss$crid_143c490e0")
alignas(16) unsigned char DAT_143c490e0[0x8];                   // 0x143c490e0
#pragma bss_seg(".bss$crid_143c490e8")
alignas(8) unsigned char DAT_143c490e8[0x8];                    // 0x143c490e8
#pragma bss_seg(".bss$crid_143c490f0")
alignas(16) unsigned char DAT_143c490f0[0x8];                   // 0x143c490f0
#pragma bss_seg(".bss$crid_143c490f8")
alignas(8) unsigned char DAT_143c490f8[0x8];                    // 0x143c490f8
#pragma bss_seg(".bss$crid_143c49100")
alignas(16) unsigned char DAT_143c49100[0x10];                  // 0x143c49100
#pragma bss_seg(".bss$crid_143c49110")
alignas(16) unsigned char DAT_143c49110[0x8];                   // 0x143c49110
#pragma bss_seg(".bss$crid_143c49118")
alignas(8) unsigned char DAT_143c49118[0x8];                    // 0x143c49118
#pragma bss_seg(".bss$crid_143c49120")
alignas(16) unsigned char DAT_143c49120[0x8];                   // 0x143c49120
#pragma bss_seg(".bss$crid_143c49128")
alignas(8) unsigned char DAT_143c49128[0x38];                   // 0x143c49128
#pragma bss_seg(".bss$crid_143c49160")
alignas(16) unsigned char DAT_143c49160[0x18];                  // 0x143c49160
#pragma bss_seg(".bss$crid_143c49178")
alignas(8) unsigned char DAT_143c49178[0x38];                   // 0x143c49178
#pragma bss_seg(".bss$crid_143c491b0")
alignas(16) unsigned char DAT_143c491b0[0x8];                   // 0x143c491b0
#pragma bss_seg(".bss$crid_143c491b8")
alignas(8) unsigned char DAT_143c491b8[0x8];                    // 0x143c491b8
#pragma bss_seg(".bss$crid_143c491c0")
alignas(16) unsigned char DAT_143c491c0[0x8];                   // 0x143c491c0
#pragma bss_seg(".bss$crid_143c491c8")
alignas(8) unsigned char DAT_143c491c8[0x8];                    // 0x143c491c8
#pragma bss_seg(".bss$crid_143c491d0")
alignas(16) unsigned char DAT_143c491d0[0x38];                  // 0x143c491d0
#pragma bss_seg(".bss$crid_143c49208")
alignas(8) unsigned char DAT_143c49208[0x8];                    // 0x143c49208
#pragma bss_seg(".bss$crid_143c49210")
alignas(16) unsigned char DAT_143c49210[0x8];                   // 0x143c49210
#pragma bss_seg(".bss$crid_143c49218")
alignas(8) unsigned char DAT_143c49218[0x8];                    // 0x143c49218
#pragma bss_seg(".bss$crid_143c49220")
alignas(16) unsigned char DAT_143c49220[0x30];                  // 0x143c49220
#pragma bss_seg(".bss$crid_143c49250")
alignas(16) unsigned char DAT_143c49250[0x10];                  // 0x143c49250
#pragma bss_seg(".bss$crid_143c49260")
alignas(16) unsigned char DAT_143c49260[0x8];                   // 0x143c49260
#pragma bss_seg(".bss$crid_143c49268")
alignas(8) unsigned char DAT_143c49268[0x38];                   // 0x143c49268
#pragma bss_seg(".bss$crid_143c492a0")
alignas(16) unsigned char DAT_143c492a0[0x10];                  // 0x143c492a0
#pragma bss_seg(".bss$crid_143c492b0")
alignas(16) unsigned char DAT_143c492b0[0x18];                  // 0x143c492b0
#pragma bss_seg(".bss$crid_143c492c8")
alignas(8) unsigned char DAT_143c492c8[0x38];                   // 0x143c492c8
#pragma bss_seg(".bss$crid_143c49300")
alignas(16) unsigned char DAT_143c49300[0x18];                  // 0x143c49300
#pragma bss_seg(".bss$crid_143c49318")
alignas(8) unsigned char DAT_143c49318[0x38];                   // 0x143c49318
#pragma bss_seg(".bss$crid_143c49350")
alignas(16) unsigned char DAT_143c49350[0x10];                  // 0x143c49350
#pragma bss_seg(".bss$crid_143c49360")
alignas(16) unsigned char DAT_143c49360[0x8];                   // 0x143c49360
#pragma bss_seg(".bss$crid_143c49368")
alignas(8) unsigned char DAT_143c49368[0x38];                   // 0x143c49368
#pragma bss_seg(".bss$crid_143c493a0")
alignas(16) unsigned char DAT_143c493a0[0x8];                   // 0x143c493a0
#pragma bss_seg(".bss$crid_143c493a8")
alignas(8) unsigned char DAT_143c493a8[0x8];                    // 0x143c493a8
#pragma bss_seg(".bss$crid_143c493b0")
alignas(16) unsigned char DAT_143c493b0[0x8];                   // 0x143c493b0
#pragma bss_seg(".bss$crid_143c493b8")
alignas(8) unsigned char DAT_143c493b8[0x38];                   // 0x143c493b8
#pragma bss_seg(".bss$crid_143c493f0")
alignas(16) unsigned char DAT_143c493f0[0x18];                  // 0x143c493f0
#pragma bss_seg(".bss$crid_143c49408")
alignas(8) unsigned char DAT_143c49408[0x38];                   // 0x143c49408
#pragma bss_seg(".bss$crid_143c49440")
alignas(16) unsigned char DAT_143c49440[0x8];                   // 0x143c49440
#pragma bss_seg(".bss$crid_143c49448")
alignas(8) unsigned char DAT_143c49448[0x8];                    // 0x143c49448
#pragma bss_seg(".bss$crid_143c49450")
alignas(16) unsigned char DAT_143c49450[0x8];                   // 0x143c49450
#pragma bss_seg(".bss$crid_143c49458")
alignas(8) unsigned char DAT_143c49458[0x8];                    // 0x143c49458
#pragma bss_seg(".bss$crid_143c49460")
alignas(16) unsigned char DAT_143c49460[0x38];                  // 0x143c49460
#pragma bss_seg(".bss$crid_143c49498")
alignas(8) unsigned char DAT_143c49498[0x8];                    // 0x143c49498
#pragma bss_seg(".bss$crid_143c494a0")
alignas(16) unsigned char DAT_143c494a0[0x8];                   // 0x143c494a0
#pragma bss_seg(".bss$crid_143c494a8")
alignas(8) unsigned char DAT_143c494a8[0x8];                    // 0x143c494a8
#pragma bss_seg(".bss$crid_143c494b0")
alignas(16) unsigned char DAT_143c494b0[0x30];                  // 0x143c494b0
#pragma bss_seg(".bss$crid_143c494e0")
alignas(16) unsigned char DAT_143c494e0[0x8];                   // 0x143c494e0
#pragma bss_seg(".bss$crid_143c494e8")
alignas(8) unsigned char DAT_143c494e8[0x8];                    // 0x143c494e8
#pragma bss_seg(".bss$crid_143c494f0")
alignas(16) unsigned char DAT_143c494f0[0x8];                   // 0x143c494f0
#pragma bss_seg(".bss$crid_143c494f8")
alignas(8) unsigned char DAT_143c494f8[0x8];                    // 0x143c494f8
#pragma bss_seg(".bss$crid_143c49500")
alignas(16) unsigned char DAT_143c49500[0x100080];              // 0x143c49500
#pragma bss_seg(".bss$crid_143d49580")
alignas(16) unsigned char DAT_143d49580[0x100];                 // 0x143d49580
#pragma bss_seg(".bss$crid_143d49680")
alignas(16) unsigned char DAT_143d49680[0x100];                 // 0x143d49680
#pragma bss_seg(".bss$crid_143d49780")
alignas(16) unsigned char DAT_143d49780[0x100];                 // 0x143d49780
#pragma bss_seg(".bss$crid_143d49880")
alignas(16) unsigned char DAT_143d49880[0x80];                  // 0x143d49880
#pragma bss_seg(".bss$crid_143d49900")
alignas(16) unsigned char DAT_143d49900[0x8];                   // 0x143d49900
#pragma bss_seg(".bss$crid_143d49908")
alignas(8) unsigned char DAT_143d49908[0x8];                    // 0x143d49908
#pragma bss_seg(".bss$crid_143d49910")
alignas(16) unsigned char DAT_143d49910[0x8];                   // 0x143d49910
#pragma bss_seg(".bss$crid_143d49918")
alignas(8) unsigned char DAT_143d49918[0x8];                    // 0x143d49918
#pragma bss_seg(".bss$crid_143d49920")
alignas(16) unsigned char DAT_143d49920[0x8];                   // 0x143d49920
#pragma bss_seg(".bss$crid_143d49928")
alignas(8) unsigned char DAT_143d49928[0x8];                    // 0x143d49928
#pragma bss_seg(".bss$crid_143d49930")
alignas(16) unsigned char DAT_143d49930[0x8];                   // 0x143d49930
#pragma bss_seg(".bss$crid_143d49938")
alignas(8) unsigned char DAT_143d49938[0x8];                    // 0x143d49938
#pragma bss_seg(".bss$crid_143d49940")
alignas(16) unsigned char DAT_143d49940[0x8];                   // 0x143d49940
#pragma bss_seg(".bss$crid_143d49948")
alignas(8) unsigned char DAT_143d49948[0x8];                    // 0x143d49948
#pragma bss_seg(".bss$crid_143d49950")
alignas(16) unsigned char DAT_143d49950[0x8];                   // 0x143d49950
#pragma bss_seg(".bss$crid_143d49958")
alignas(8) unsigned char DAT_143d49958[0x8];                    // 0x143d49958
#pragma bss_seg(".bss$crid_143d49960")
alignas(16) unsigned char DAT_143d49960[0x8];                   // 0x143d49960
#pragma bss_seg(".bss$crid_143d49968")
alignas(8) unsigned char DAT_143d49968[0x8];                    // 0x143d49968
#pragma bss_seg(".bss$crid_143d49970")
alignas(16) unsigned char DAT_143d49970[0x8];                   // 0x143d49970
#pragma bss_seg(".bss$crid_143d49978")
alignas(8) unsigned char DAT_143d49978[0x4];                    // 0x143d49978
#pragma bss_seg(".bss$crid_143d4997c")
alignas(4) unsigned char DAT_143d4997c[0x1];                    // 0x143d4997c
#pragma bss_seg(".bss$crid_143d4997d")
alignas(1) unsigned char DAT_143d4997d[0x1];                    // 0x143d4997d
#pragma bss_seg(".bss$crid_143d4997e")
alignas(2) unsigned char DAT_143d4997e[0x1];                    // 0x143d4997e
#pragma bss_seg(".bss$crid_143d4997f")
alignas(1) unsigned char DAT_143d4997f[0x1];                    // 0x143d4997f
#pragma bss_seg(".bss$crid_143d49980")
alignas(16) unsigned char DAT_143d49980[0x400];                 // 0x143d49980
#pragma bss_seg(".bss$crid_143d49d80")
alignas(16) unsigned char DAT_143d49d80[0x8];                   // 0x143d49d80
#pragma bss_seg(".bss$crid_143d49d88")
alignas(8) unsigned char DAT_143d49d88[0x8];                    // 0x143d49d88
#pragma bss_seg(".bss$crid_143d49d90")
alignas(16) unsigned char DAT_143d49d90[0x8];                   // 0x143d49d90
#pragma bss_seg(".bss$crid_143d49d98")
alignas(8) unsigned char DAT_143d49d98[0x8];                    // 0x143d49d98
#pragma bss_seg(".bss$crid_143d49da0")
alignas(16) unsigned char DAT_143d49da0[0x8];                   // 0x143d49da0
#pragma bss_seg(".bss$crid_143d49da8")
alignas(8) unsigned char DAT_143d49da8[0x8];                    // 0x143d49da8
#pragma bss_seg(".bss$crid_143d49db0")
alignas(16) unsigned char DAT_143d49db0[0x8];                   // 0x143d49db0
#pragma bss_seg(".bss$crid_143d49db8")
alignas(8) unsigned char DAT_143d49db8[0x8];                    // 0x143d49db8
#pragma bss_seg(".bss$crid_143d49dc0")
alignas(16) unsigned char DAT_143d49dc0[0x8];                   // 0x143d49dc0
#pragma bss_seg(".bss$crid_143d49dc8")
alignas(8) unsigned char DAT_143d49dc8[0x8];                    // 0x143d49dc8
#pragma bss_seg(".bss$crid_143d49dd0")
alignas(16) unsigned char DAT_143d49dd0[0x8];                   // 0x143d49dd0
#pragma bss_seg(".bss$crid_143d49dd8")
alignas(8) unsigned char DAT_143d49dd8[0x8];                    // 0x143d49dd8
#pragma bss_seg(".bss$crid_143d49de0")
alignas(16) unsigned char DAT_143d49de0[0x8];                   // 0x143d49de0
#pragma bss_seg(".bss$crid_143d49de8")
alignas(8) unsigned char DAT_143d49de8[0x8];                    // 0x143d49de8
#pragma bss_seg(".bss$crid_143d49df0")
alignas(16) unsigned char DAT_143d49df0[0x8];                   // 0x143d49df0
#pragma bss_seg(".bss$crid_143d49df8")
alignas(8) unsigned char DAT_143d49df8[0x8];                    // 0x143d49df8
#pragma bss_seg(".bss$crid_143d49e00")
alignas(16) unsigned char DAT_143d49e00[0x4];                   // 0x143d49e00
#pragma bss_seg(".bss$crid_143d49e04")
alignas(4) unsigned char DAT_143d49e04[0x4];                    // 0x143d49e04
#pragma bss_seg(".bss$crid_143d49e08")
alignas(8) unsigned char DAT_143d49e08[0x4];                    // 0x143d49e08
#pragma bss_seg(".bss$crid_143d49e0c")
alignas(4) unsigned char DAT_143d49e0c[0x4];                    // 0x143d49e0c
#pragma bss_seg(".bss$crid_143d49e10")
alignas(16) unsigned char DAT_143d49e10[0x4];                   // 0x143d49e10
#pragma bss_seg(".bss$crid_143d49e14")
alignas(4) unsigned char DAT_143d49e14[0x4];                    // 0x143d49e14
#pragma bss_seg(".bss$crid_143d49e18")
alignas(8) unsigned char DAT_143d49e18[0x4];                    // 0x143d49e18
#pragma bss_seg(".bss$crid_143d49e1c")
alignas(4) unsigned char DAT_143d49e1c[0x4];                    // 0x143d49e1c
#pragma bss_seg(".bss$crid_143d49e20")
alignas(16) unsigned char DAT_143d49e20[0x8];                   // 0x143d49e20
#pragma bss_seg(".bss$crid_143d49e28")
alignas(8) unsigned char DAT_143d49e28[0x8];                    // 0x143d49e28
#pragma bss_seg(".bss$crid_143d49e30")
alignas(16) unsigned char DAT_143d49e30[0x8];                   // 0x143d49e30
#pragma bss_seg(".bss$crid_143d49e38")
alignas(8) unsigned char DAT_143d49e38[0x8];                    // 0x143d49e38
#pragma bss_seg(".bss$crid_143d49e40")
alignas(16) unsigned char DAT_143d49e40[0x8];                   // 0x143d49e40
#pragma bss_seg(".bss$crid_143d49e48")
alignas(8) unsigned char DAT_143d49e48[0x8];                    // 0x143d49e48
#pragma bss_seg(".bss$crid_143d49e50")
alignas(16) unsigned char DAT_143d49e50[0x8];                   // 0x143d49e50
#pragma bss_seg(".bss$crid_143d49e58")
alignas(8) unsigned char DAT_143d49e58[0x8];                    // 0x143d49e58
#pragma bss_seg(".bss$crid_143d49e60")
alignas(16) unsigned char DAT_143d49e60[0x8];                   // 0x143d49e60
#pragma bss_seg(".bss$crid_143d49e68")
alignas(8) unsigned char DAT_143d49e68[0x8];                    // 0x143d49e68
#pragma bss_seg(".bss$crid_143d49e70")
alignas(16) unsigned char DAT_143d49e70[0x8];                   // 0x143d49e70
#pragma bss_seg(".bss$crid_143d49e78")
alignas(8) unsigned char DAT_143d49e78[0x8];                    // 0x143d49e78
#pragma bss_seg(".bss$crid_143d49e80")
alignas(16) unsigned char DAT_143d49e80[0x8];                   // 0x143d49e80
#pragma bss_seg(".bss$crid_143d49e88")
alignas(8) unsigned char DAT_143d49e88[0x8];                    // 0x143d49e88
#pragma bss_seg(".bss$crid_143d49e90")
alignas(16) unsigned char DAT_143d49e90[0x8];                   // 0x143d49e90
#pragma bss_seg(".bss$crid_143d49e98")
alignas(8) unsigned char DAT_143d49e98[0x8];                    // 0x143d49e98
#pragma bss_seg(".bss$crid_143d49ea0")
alignas(16) unsigned char DAT_143d49ea0[0x8];                   // 0x143d49ea0
#pragma bss_seg(".bss$crid_143d49ea8")
alignas(8) unsigned char DAT_143d49ea8[0x8];                    // 0x143d49ea8
#pragma bss_seg(".bss$crid_143d49eb0")
alignas(16) unsigned char DAT_143d49eb0[0x8];                   // 0x143d49eb0
#pragma bss_seg(".bss$crid_143d49eb8")
alignas(8) unsigned char DAT_143d49eb8[0x8];                    // 0x143d49eb8
#pragma bss_seg(".bss$crid_143d49ec0")
alignas(16) unsigned char DAT_143d49ec0[0x8];                   // 0x143d49ec0
#pragma bss_seg(".bss$crid_143d49ec8")
alignas(8) unsigned char DAT_143d49ec8[0x8];                    // 0x143d49ec8
#pragma bss_seg(".bss$crid_143d49ed0")
alignas(16) unsigned char DAT_143d49ed0[0x8];                   // 0x143d49ed0
#pragma bss_seg(".bss$crid_143d49ed8")
alignas(8) unsigned char DAT_143d49ed8[0x8];                    // 0x143d49ed8
#pragma bss_seg(".bss$crid_143d49ee0")
alignas(16) unsigned char DAT_143d49ee0[0x8];                   // 0x143d49ee0
#pragma bss_seg(".bss$crid_143d49ee8")
alignas(8) unsigned char DAT_143d49ee8[0x8];                    // 0x143d49ee8
#pragma bss_seg(".bss$crid_143d49ef0")
alignas(16) unsigned char DAT_143d49ef0[0x8];                   // 0x143d49ef0
#pragma bss_seg(".bss$crid_143d49ef8")
alignas(8) unsigned char DAT_143d49ef8[0x8];                    // 0x143d49ef8
#pragma bss_seg(".bss$crid_143d49f00")
alignas(16) unsigned char DAT_143d49f00[0x80];                  // 0x143d49f00
#pragma bss_seg(".bss$crid_143d49f80")
alignas(16) unsigned char DAT_143d49f80[0x2];                   // 0x143d49f80
#pragma bss_seg(".bss$crid_143d49f82")
alignas(2) unsigned char DAT_143d49f82[0x2];                    // 0x143d49f82
#pragma bss_seg(".bss$crid_143d49f84")
alignas(4) unsigned char DAT_143d49f84[0x2];                    // 0x143d49f84
#pragma bss_seg(".bss$crid_143d49f86")
alignas(2) unsigned char DAT_143d49f86[0x2];                    // 0x143d49f86
#pragma bss_seg(".bss$crid_143d49f88")
alignas(8) unsigned char DAT_143d49f88[0x2];                    // 0x143d49f88
#pragma bss_seg(".bss$crid_143d49f8a")
alignas(2) unsigned char DAT_143d49f8a[0x2];                    // 0x143d49f8a
#pragma bss_seg(".bss$crid_143d49f8c")
alignas(4) unsigned char DAT_143d49f8c[0x2];                    // 0x143d49f8c
#pragma bss_seg(".bss$crid_143d49f8e")
alignas(2) unsigned char DAT_143d49f8e[0x2];                    // 0x143d49f8e
#pragma bss_seg(".bss$crid_143d49f90")
alignas(16) unsigned char DAT_143d49f90[0x2];                   // 0x143d49f90
#pragma bss_seg(".bss$crid_143d49f92")
alignas(2) unsigned char DAT_143d49f92[0x2];                    // 0x143d49f92
#pragma bss_seg(".bss$crid_143d49f94")
alignas(4) unsigned char DAT_143d49f94[0x2];                    // 0x143d49f94
#pragma bss_seg(".bss$crid_143d49f96")
alignas(2) unsigned char DAT_143d49f96[0x2];                    // 0x143d49f96
#pragma bss_seg(".bss$crid_143d49f98")
alignas(8) unsigned char DAT_143d49f98[0x2];                    // 0x143d49f98
#pragma bss_seg(".bss$crid_143d49f9a")
alignas(2) unsigned char DAT_143d49f9a[0x2];                    // 0x143d49f9a
#pragma bss_seg(".bss$crid_143d49f9c")
alignas(4) unsigned char DAT_143d49f9c[0x2];                    // 0x143d49f9c
#pragma bss_seg(".bss$crid_143d49f9e")
alignas(2) unsigned char DAT_143d49f9e[0x2];                    // 0x143d49f9e
#pragma bss_seg(".bss$crid_143d49fa0")
alignas(16) unsigned char DAT_143d49fa0[0x2];                   // 0x143d49fa0
#pragma bss_seg(".bss$crid_143d49fa2")
alignas(2) unsigned char DAT_143d49fa2[0x2];                    // 0x143d49fa2
#pragma bss_seg(".bss$crid_143d49fa4")
alignas(4) unsigned char DAT_143d49fa4[0x2];                    // 0x143d49fa4
#pragma bss_seg(".bss$crid_143d49fa6")
alignas(2) unsigned char DAT_143d49fa6[0x2];                    // 0x143d49fa6
#pragma bss_seg(".bss$crid_143d49fa8")
alignas(8) unsigned char DAT_143d49fa8[0x2];                    // 0x143d49fa8
#pragma bss_seg(".bss$crid_143d49faa")
alignas(2) unsigned char DAT_143d49faa[0x2];                    // 0x143d49faa
#pragma bss_seg(".bss$crid_143d49fac")
alignas(4) unsigned char DAT_143d49fac[0x2];                    // 0x143d49fac
#pragma bss_seg(".bss$crid_143d49fae")
alignas(2) unsigned char DAT_143d49fae[0x2];                    // 0x143d49fae
#pragma bss_seg(".bss$crid_143d49fb0")
alignas(16) unsigned char DAT_143d49fb0[0xd0];                  // 0x143d49fb0
#pragma bss_seg(".bss$crid_143d4a080")
alignas(16) unsigned char DAT_143d4a080[0x2];                   // 0x143d4a080
#pragma bss_seg(".bss$crid_143d4a082")
alignas(2) unsigned char DAT_143d4a082[0x2];                    // 0x143d4a082
#pragma bss_seg(".bss$crid_143d4a084")
alignas(4) unsigned char DAT_143d4a084[0x2];                    // 0x143d4a084
#pragma bss_seg(".bss$crid_143d4a086")
alignas(2) unsigned char DAT_143d4a086[0x2];                    // 0x143d4a086
#pragma bss_seg(".bss$crid_143d4a088")
alignas(8) unsigned char DAT_143d4a088[0x2];                    // 0x143d4a088
#pragma bss_seg(".bss$crid_143d4a08a")
alignas(2) unsigned char DAT_143d4a08a[0x2];                    // 0x143d4a08a
#pragma bss_seg(".bss$crid_143d4a08c")
alignas(4) unsigned char DAT_143d4a08c[0x2];                    // 0x143d4a08c
#pragma bss_seg(".bss$crid_143d4a08e")
alignas(2) unsigned char DAT_143d4a08e[0x2];                    // 0x143d4a08e
#pragma bss_seg(".bss$crid_143d4a090")
alignas(16) unsigned char DAT_143d4a090[0x2];                   // 0x143d4a090
#pragma bss_seg(".bss$crid_143d4a092")
alignas(2) unsigned char DAT_143d4a092[0x2];                    // 0x143d4a092
#pragma bss_seg(".bss$crid_143d4a094")
alignas(4) unsigned char DAT_143d4a094[0x2];                    // 0x143d4a094
#pragma bss_seg(".bss$crid_143d4a096")
alignas(2) unsigned char DAT_143d4a096[0x2];                    // 0x143d4a096
#pragma bss_seg(".bss$crid_143d4a098")
alignas(8) unsigned char DAT_143d4a098[0x2];                    // 0x143d4a098
#pragma bss_seg(".bss$crid_143d4a09a")
alignas(2) unsigned char DAT_143d4a09a[0x2];                    // 0x143d4a09a
#pragma bss_seg(".bss$crid_143d4a09c")
alignas(4) unsigned char DAT_143d4a09c[0x2];                    // 0x143d4a09c
#pragma bss_seg(".bss$crid_143d4a09e")
alignas(2) unsigned char DAT_143d4a09e[0x2];                    // 0x143d4a09e
#pragma bss_seg(".bss$crid_143d4a0a0")
alignas(16) unsigned char DAT_143d4a0a0[0x2];                   // 0x143d4a0a0
#pragma bss_seg(".bss$crid_143d4a0a2")
alignas(2) unsigned char DAT_143d4a0a2[0x2];                    // 0x143d4a0a2
#pragma bss_seg(".bss$crid_143d4a0a4")
alignas(4) unsigned char DAT_143d4a0a4[0x2];                    // 0x143d4a0a4
#pragma bss_seg(".bss$crid_143d4a0a6")
alignas(2) unsigned char DAT_143d4a0a6[0x2];                    // 0x143d4a0a6
#pragma bss_seg(".bss$crid_143d4a0a8")
alignas(8) unsigned char DAT_143d4a0a8[0x2];                    // 0x143d4a0a8
#pragma bss_seg(".bss$crid_143d4a0aa")
alignas(2) unsigned char DAT_143d4a0aa[0x2];                    // 0x143d4a0aa
#pragma bss_seg(".bss$crid_143d4a0ac")
alignas(4) unsigned char DAT_143d4a0ac[0x2];                    // 0x143d4a0ac
#pragma bss_seg(".bss$crid_143d4a0ae")
alignas(2) unsigned char DAT_143d4a0ae[0x2];                    // 0x143d4a0ae
#pragma bss_seg(".bss$crid_143d4a0b0")
alignas(16) unsigned char DAT_143d4a0b0[0x2];                   // 0x143d4a0b0
#pragma bss_seg(".bss$crid_143d4a0b2")
alignas(2) unsigned char DAT_143d4a0b2[0x2];                    // 0x143d4a0b2
#pragma bss_seg(".bss$crid_143d4a0b4")
alignas(4) unsigned char DAT_143d4a0b4[0x2];                    // 0x143d4a0b4
#pragma bss_seg(".bss$crid_143d4a0b6")
alignas(2) unsigned char DAT_143d4a0b6[0x2];                    // 0x143d4a0b6
#pragma bss_seg(".bss$crid_143d4a0b8")
alignas(8) unsigned char DAT_143d4a0b8[0x2];                    // 0x143d4a0b8
#pragma bss_seg(".bss$crid_143d4a0ba")
alignas(2) unsigned char DAT_143d4a0ba[0x2];                    // 0x143d4a0ba
#pragma bss_seg(".bss$crid_143d4a0bc")
alignas(4) unsigned char DAT_143d4a0bc[0x2];                    // 0x143d4a0bc
#pragma bss_seg(".bss$crid_143d4a0be")
alignas(2) unsigned char DAT_143d4a0be[0x2];                    // 0x143d4a0be
#pragma bss_seg(".bss$crid_143d4a0c0")
alignas(16) unsigned char DAT_143d4a0c0[0x20];                  // 0x143d4a0c0
#pragma bss_seg(".bss$crid_143d4a0e0")
alignas(16) unsigned char DAT_143d4a0e0[0x20];                  // 0x143d4a0e0
#pragma bss_seg(".bss$crid_143d4a100")
alignas(16) unsigned char DAT_143d4a100[0x30];                  // 0x143d4a100
#pragma bss_seg(".bss$crid_143d4a130")
alignas(16) unsigned char DAT_143d4a130[0xd0];                  // 0x143d4a130
#pragma bss_seg(".bss$crid_143d4a200")
alignas(16) unsigned char DAT_143d4a200[0x2];                   // 0x143d4a200
#pragma bss_seg(".bss$crid_143d4a202")
alignas(2) unsigned char DAT_143d4a202[0x2];                    // 0x143d4a202
#pragma bss_seg(".bss$crid_143d4a204")
alignas(4) unsigned char DAT_143d4a204[0x3c];                   // 0x143d4a204
#pragma bss_seg(".bss$crid_143d4a240")
alignas(16) unsigned char DAT_143d4a240[0x2];                   // 0x143d4a240
#pragma bss_seg(".bss$crid_143d4a242")
alignas(2) unsigned char DAT_143d4a242[0x2];                    // 0x143d4a242
#pragma bss_seg(".bss$crid_143d4a244")
alignas(4) unsigned char DAT_143d4a244[0x2];                    // 0x143d4a244
#pragma bss_seg(".bss$crid_143d4a246")
alignas(2) unsigned char DAT_143d4a246[0x2];                    // 0x143d4a246
#pragma bss_seg(".bss$crid_143d4a248")
alignas(8) unsigned char DAT_143d4a248[0x78];                   // 0x143d4a248
#pragma bss_seg(".bss$crid_143d4a2c0")
alignas(16) unsigned char DAT_143d4a2c0[0x2];                   // 0x143d4a2c0
#pragma bss_seg(".bss$crid_143d4a2c2")
alignas(2) unsigned char DAT_143d4a2c2[0x2];                    // 0x143d4a2c2
#pragma bss_seg(".bss$crid_143d4a2c4")
alignas(4) unsigned char DAT_143d4a2c4[0x2];                    // 0x143d4a2c4
#pragma bss_seg(".bss$crid_143d4a2c6")
alignas(2) unsigned char DAT_143d4a2c6[0x2];                    // 0x143d4a2c6
#pragma bss_seg(".bss$crid_143d4a2c8")
alignas(8) unsigned char DAT_143d4a2c8[0x2];                    // 0x143d4a2c8
#pragma bss_seg(".bss$crid_143d4a2ca")
alignas(2) unsigned char DAT_143d4a2ca[0x2];                    // 0x143d4a2ca
#pragma bss_seg(".bss$crid_143d4a2cc")
alignas(4) unsigned char DAT_143d4a2cc[0x2];                    // 0x143d4a2cc
#pragma bss_seg(".bss$crid_143d4a2ce")
alignas(2) unsigned char DAT_143d4a2ce[0x2];                    // 0x143d4a2ce
#pragma bss_seg(".bss$crid_143d4a2d0")
alignas(16) unsigned char DAT_143d4a2d0[0x2];                   // 0x143d4a2d0
#pragma bss_seg(".bss$crid_143d4a2d2")
alignas(2) unsigned char DAT_143d4a2d2[0x2];                    // 0x143d4a2d2
#pragma bss_seg(".bss$crid_143d4a2d4")
alignas(4) unsigned char DAT_143d4a2d4[0x2];                    // 0x143d4a2d4
#pragma bss_seg(".bss$crid_143d4a2d6")
alignas(2) unsigned char DAT_143d4a2d6[0x2];                    // 0x143d4a2d6
#pragma bss_seg(".bss$crid_143d4a2d8")
alignas(8) unsigned char DAT_143d4a2d8[0x2];                    // 0x143d4a2d8
#pragma bss_seg(".bss$crid_143d4a2da")
alignas(2) unsigned char DAT_143d4a2da[0x2];                    // 0x143d4a2da
#pragma bss_seg(".bss$crid_143d4a2dc")
alignas(4) unsigned char DAT_143d4a2dc[0x2];                    // 0x143d4a2dc
#pragma bss_seg(".bss$crid_143d4a2de")
alignas(2) unsigned char DAT_143d4a2de[0x2];                    // 0x143d4a2de
#pragma bss_seg(".bss$crid_143d4a2e0")
alignas(16) unsigned char DAT_143d4a2e0[0x20];                  // 0x143d4a2e0
#pragma bss_seg(".bss$crid_143d4a300")
alignas(16) unsigned char DAT_143d4a300[0x2];                   // 0x143d4a300
#pragma bss_seg(".bss$crid_143d4a302")
alignas(2) unsigned char DAT_143d4a302[0x2];                    // 0x143d4a302
#pragma bss_seg(".bss$crid_143d4a304")
alignas(4) unsigned char DAT_143d4a304[0x2];                    // 0x143d4a304
#pragma bss_seg(".bss$crid_143d4a306")
alignas(2) unsigned char DAT_143d4a306[0x2];                    // 0x143d4a306
#pragma bss_seg(".bss$crid_143d4a308")
alignas(8) unsigned char DAT_143d4a308[0x2];                    // 0x143d4a308
#pragma bss_seg(".bss$crid_143d4a30a")
alignas(2) unsigned char DAT_143d4a30a[0x2];                    // 0x143d4a30a
#pragma bss_seg(".bss$crid_143d4a30c")
alignas(4) unsigned char DAT_143d4a30c[0x2];                    // 0x143d4a30c
#pragma bss_seg(".bss$crid_143d4a30e")
alignas(2) unsigned char DAT_143d4a30e[0x2];                    // 0x143d4a30e
#pragma bss_seg(".bss$crid_143d4a310")
alignas(16) unsigned char DAT_143d4a310[0x2];                   // 0x143d4a310
#pragma bss_seg(".bss$crid_143d4a312")
alignas(2) unsigned char DAT_143d4a312[0x2];                    // 0x143d4a312
#pragma bss_seg(".bss$crid_143d4a314")
alignas(4) unsigned char DAT_143d4a314[0x2];                    // 0x143d4a314
#pragma bss_seg(".bss$crid_143d4a316")
alignas(2) unsigned char DAT_143d4a316[0x2];                    // 0x143d4a316
#pragma bss_seg(".bss$crid_143d4a318")
alignas(8) unsigned char DAT_143d4a318[0x2];                    // 0x143d4a318
#pragma bss_seg(".bss$crid_143d4a31a")
alignas(2) unsigned char DAT_143d4a31a[0x2];                    // 0x143d4a31a
#pragma bss_seg(".bss$crid_143d4a31c")
alignas(4) unsigned char DAT_143d4a31c[0x2];                    // 0x143d4a31c
#pragma bss_seg(".bss$crid_143d4a31e")
alignas(2) unsigned char DAT_143d4a31e[0x2];                    // 0x143d4a31e
#pragma bss_seg(".bss$crid_143d4a320")
alignas(16) unsigned char DAT_143d4a320[0x20];                  // 0x143d4a320
#pragma bss_seg(".bss$crid_143d4a340")
alignas(16) unsigned char DAT_143d4a340[0x8];                   // 0x143d4a340
#pragma bss_seg(".bss$crid_143d4a348")
alignas(8) unsigned char DAT_143d4a348[0x8];                    // 0x143d4a348
#pragma bss_seg(".bss$crid_143d4a350")
alignas(16) unsigned char DAT_143d4a350[0x8];                   // 0x143d4a350
#pragma bss_seg(".bss$crid_143d4a358")
alignas(8) unsigned char DAT_143d4a358[0x8];                    // 0x143d4a358
#pragma bss_seg(".bss$crid_143d4a360")
alignas(16) unsigned char DAT_143d4a360[0x8];                   // 0x143d4a360
#pragma bss_seg(".bss$crid_143d4a368")
alignas(8) unsigned char DAT_143d4a368[0x8];                    // 0x143d4a368
#pragma bss_seg(".bss$crid_143d4a370")
alignas(16) unsigned char DAT_143d4a370[0x8];                   // 0x143d4a370
#pragma bss_seg(".bss$crid_143d4a378")
alignas(8) unsigned char DAT_143d4a378[0x8];                    // 0x143d4a378
#pragma bss_seg(".bss$crid_143d4a380")
alignas(16) unsigned char DAT_143d4a380[0x8];                   // 0x143d4a380
#pragma bss_seg(".bss$crid_143d4a388")
alignas(8) unsigned char DAT_143d4a388[0x8];                    // 0x143d4a388
#pragma bss_seg(".bss$crid_143d4a390")
alignas(16) unsigned char DAT_143d4a390[0x8];                   // 0x143d4a390
#pragma bss_seg(".bss$crid_143d4a398")
alignas(8) unsigned char DAT_143d4a398[0x8];                    // 0x143d4a398
#pragma bss_seg(".bss$crid_143d4a3a0")
alignas(16) unsigned char DAT_143d4a3a0[0x8];                   // 0x143d4a3a0
#pragma bss_seg(".bss$crid_143d4a3a8")
alignas(8) unsigned char DAT_143d4a3a8[0x8];                    // 0x143d4a3a8
#pragma bss_seg(".bss$crid_143d4a3b0")
alignas(16) unsigned char DAT_143d4a3b0[0x8];                   // 0x143d4a3b0
#pragma bss_seg(".bss$crid_143d4a3b8")
alignas(8) unsigned char DAT_143d4a3b8[0x4];                    // 0x143d4a3b8
#pragma bss_seg(".bss$crid_143d4a3bc")
alignas(4) unsigned char DAT_143d4a3bc[0x1];                    // 0x143d4a3bc
#pragma bss_seg(".bss$crid_143d4a3bd")
alignas(1) unsigned char DAT_143d4a3bd[0x1];                    // 0x143d4a3bd
#pragma bss_seg(".bss$crid_143d4a3be")
alignas(2) unsigned char DAT_143d4a3be[0x1];                    // 0x143d4a3be
#pragma bss_seg(".bss$crid_143d4a3bf")
alignas(1) unsigned char DAT_143d4a3bf[0x1];                    // 0x143d4a3bf
#pragma bss_seg(".bss$crid_143d4a3c0")
alignas(16) unsigned char DAT_143d4a3c0[0x2];                   // 0x143d4a3c0
#pragma bss_seg(".bss$crid_143d4a3c2")
alignas(2) unsigned char DAT_143d4a3c2[0x2];                    // 0x143d4a3c2
#pragma bss_seg(".bss$crid_143d4a3c4")
alignas(4) unsigned char DAT_143d4a3c4[0x3c];                   // 0x143d4a3c4
#pragma bss_seg(".bss$crid_143d4a400")
alignas(16) unsigned char DAT_143d4a400[0x8];                   // 0x143d4a400
#pragma bss_seg(".bss$crid_143d4a408")
alignas(8) unsigned char DAT_143d4a408[0x8];                    // 0x143d4a408
#pragma bss_seg(".bss$crid_143d4a410")
alignas(16) unsigned char DAT_143d4a410[0x8];                   // 0x143d4a410
#pragma bss_seg(".bss$crid_143d4a418")
alignas(8) unsigned char DAT_143d4a418[0x8];                    // 0x143d4a418
#pragma bss_seg(".bss$crid_143d4a420")
alignas(16) unsigned char DAT_143d4a420[0x8];                   // 0x143d4a420
#pragma bss_seg(".bss$crid_143d4a428")
alignas(8) unsigned char DAT_143d4a428[0x8];                    // 0x143d4a428
#pragma bss_seg(".bss$crid_143d4a430")
alignas(16) unsigned char DAT_143d4a430[0x8];                   // 0x143d4a430
#pragma bss_seg(".bss$crid_143d4a438")
alignas(8) unsigned char DAT_143d4a438[0x8];                    // 0x143d4a438
#pragma bss_seg(".bss$crid_143d4a440")
alignas(16) unsigned char DAT_143d4a440[0x8];                   // 0x143d4a440
#pragma bss_seg(".bss$crid_143d4a448")
alignas(8) unsigned char DAT_143d4a448[0x8];                    // 0x143d4a448
#pragma bss_seg(".bss$crid_143d4a450")
alignas(16) unsigned char DAT_143d4a450[0x8];                   // 0x143d4a450
#pragma bss_seg(".bss$crid_143d4a458")
alignas(8) unsigned char DAT_143d4a458[0x8];                    // 0x143d4a458
#pragma bss_seg(".bss$crid_143d4a460")
alignas(16) unsigned char DAT_143d4a460[0x8];                   // 0x143d4a460
#pragma bss_seg(".bss$crid_143d4a468")
alignas(8) unsigned char DAT_143d4a468[0x8];                    // 0x143d4a468
#pragma bss_seg(".bss$crid_143d4a470")
alignas(16) unsigned char DAT_143d4a470[0x8];                   // 0x143d4a470
#pragma bss_seg(".bss$crid_143d4a478")
alignas(8) unsigned char DAT_143d4a478[0x4];                    // 0x143d4a478
#pragma bss_seg(".bss$crid_143d4a47c")
alignas(4) unsigned char DAT_143d4a47c[0x1];                    // 0x143d4a47c
#pragma bss_seg(".bss$crid_143d4a47d")
alignas(1) unsigned char DAT_143d4a47d[0x1];                    // 0x143d4a47d
#pragma bss_seg(".bss$crid_143d4a47e")
alignas(2) unsigned char DAT_143d4a47e[0x1];                    // 0x143d4a47e
#pragma bss_seg(".bss$crid_143d4a47f")
alignas(1) unsigned char DAT_143d4a47f[0x1];                    // 0x143d4a47f
#pragma bss_seg(".bss$crid_143d4a480")
alignas(16) unsigned char DAT_143d4a480[0x100];                 // 0x143d4a480
#pragma bss_seg(".bss$crid_143d4a580")
alignas(16) unsigned char DAT_143d4a580[0x100];                 // 0x143d4a580
#pragma bss_seg(".bss$crid_143d4a680")
alignas(16) unsigned char DAT_143d4a680[0x80];                  // 0x143d4a680
#pragma bss_seg(".bss$crid_143d4a700")
alignas(16) unsigned char DAT_143d4a700[0x80];                  // 0x143d4a700
#pragma bss_seg(".bss$crid_143d4a780")
alignas(16) unsigned char DAT_143d4a780[0x80];                  // 0x143d4a780
#pragma bss_seg(".bss$crid_143d4a800")
alignas(16) unsigned char DAT_143d4a800[0x8];                   // 0x143d4a800
#pragma bss_seg(".bss$crid_143d4a808")
alignas(8) unsigned char DAT_143d4a808[0x8];                    // 0x143d4a808
#pragma bss_seg(".bss$crid_143d4a810")
alignas(16) unsigned char DAT_143d4a810[0x8];                   // 0x143d4a810
#pragma bss_seg(".bss$crid_143d4a818")
alignas(8) unsigned char DAT_143d4a818[0x8];                    // 0x143d4a818
#pragma bss_seg(".bss$crid_143d4a820")
alignas(16) unsigned char DAT_143d4a820[0x8];                   // 0x143d4a820
#pragma bss_seg(".bss$crid_143d4a828")
alignas(8) unsigned char DAT_143d4a828[0x8];                    // 0x143d4a828
#pragma bss_seg(".bss$crid_143d4a830")
alignas(16) unsigned char DAT_143d4a830[0x8];                   // 0x143d4a830
#pragma bss_seg(".bss$crid_143d4a838")
alignas(8) unsigned char DAT_143d4a838[0x8];                    // 0x143d4a838
#pragma bss_seg(".bss$crid_143d4a840")
alignas(16) unsigned char DAT_143d4a840[0x8];                   // 0x143d4a840
#pragma bss_seg(".bss$crid_143d4a848")
alignas(8) unsigned char DAT_143d4a848[0x8];                    // 0x143d4a848
#pragma bss_seg(".bss$crid_143d4a850")
alignas(16) unsigned char DAT_143d4a850[0x8];                   // 0x143d4a850
#pragma bss_seg(".bss$crid_143d4a858")
alignas(8) unsigned char DAT_143d4a858[0x8];                    // 0x143d4a858
#pragma bss_seg(".bss$crid_143d4a860")
alignas(16) unsigned char DAT_143d4a860[0x8];                   // 0x143d4a860
#pragma bss_seg(".bss$crid_143d4a868")
alignas(8) unsigned char DAT_143d4a868[0x8];                    // 0x143d4a868
#pragma bss_seg(".bss$crid_143d4a870")
alignas(16) unsigned char DAT_143d4a870[0x8];                   // 0x143d4a870
#pragma bss_seg(".bss$crid_143d4a878")
alignas(8) unsigned char DAT_143d4a878[0x4];                    // 0x143d4a878
#pragma bss_seg(".bss$crid_143d4a87c")
alignas(4) unsigned char DAT_143d4a87c[0x1];                    // 0x143d4a87c
#pragma bss_seg(".bss$crid_143d4a87d")
alignas(1) unsigned char DAT_143d4a87d[0x1];                    // 0x143d4a87d
#pragma bss_seg(".bss$crid_143d4a87e")
alignas(2) unsigned char DAT_143d4a87e[0x1];                    // 0x143d4a87e
#pragma bss_seg(".bss$crid_143d4a87f")
alignas(1) unsigned char DAT_143d4a87f[0x1];                    // 0x143d4a87f
#pragma bss_seg(".bss$crid_143d4a880")
alignas(16) unsigned char DAT_143d4a880[0x20];                  // 0x143d4a880
#pragma bss_seg(".bss$crid_143d4a8a0")
alignas(16) unsigned char DAT_143d4a8a0[0x2];                   // 0x143d4a8a0
#pragma bss_seg(".bss$crid_143d4a8a2")
alignas(2) unsigned char DAT_143d4a8a2[0x2];                    // 0x143d4a8a2
#pragma bss_seg(".bss$crid_143d4a8a4")
alignas(4) unsigned char DAT_143d4a8a4[0x18];                   // 0x143d4a8a4
#pragma bss_seg(".bss$crid_143d4a8bc")
alignas(4) unsigned char DAT_143d4a8bc[0x2];                    // 0x143d4a8bc
#pragma bss_seg(".bss$crid_143d4a8be")
alignas(2) unsigned char DAT_143d4a8be[0x2];                    // 0x143d4a8be
#pragma bss_seg(".bss$crid_143d4a8c0")
alignas(16) unsigned char DAT_143d4a8c0[0x20];                  // 0x143d4a8c0
#pragma bss_seg(".bss$crid_143d4a8e0")
alignas(16) unsigned char DAT_143d4a8e0[0x1a0];                 // 0x143d4a8e0
#pragma bss_seg(".bss$crid_143d4aa80")
alignas(16) unsigned char DAT_143d4aa80[0x2];                   // 0x143d4aa80
#pragma bss_seg(".bss$crid_143d4aa82")
alignas(2) unsigned char DAT_143d4aa82[0x2];                    // 0x143d4aa82
#pragma bss_seg(".bss$crid_143d4aa84")
alignas(4) unsigned char DAT_143d4aa84[0x2];                    // 0x143d4aa84
#pragma bss_seg(".bss$crid_143d4aa86")
alignas(2) unsigned char DAT_143d4aa86[0x2];                    // 0x143d4aa86
#pragma bss_seg(".bss$crid_143d4aa88")
alignas(8) unsigned char DAT_143d4aa88[0x2];                    // 0x143d4aa88
#pragma bss_seg(".bss$crid_143d4aa8a")
alignas(2) unsigned char DAT_143d4aa8a[0x2];                    // 0x143d4aa8a
#pragma bss_seg(".bss$crid_143d4aa8c")
alignas(4) unsigned char DAT_143d4aa8c[0x2];                    // 0x143d4aa8c
#pragma bss_seg(".bss$crid_143d4aa8e")
alignas(2) unsigned char DAT_143d4aa8e[0x2];                    // 0x143d4aa8e
#pragma bss_seg(".bss$crid_143d4aa90")
alignas(16) unsigned char DAT_143d4aa90[0x2];                   // 0x143d4aa90
#pragma bss_seg(".bss$crid_143d4aa92")
alignas(2) unsigned char DAT_143d4aa92[0x2];                    // 0x143d4aa92
#pragma bss_seg(".bss$crid_143d4aa94")
alignas(4) unsigned char DAT_143d4aa94[0x2];                    // 0x143d4aa94
#pragma bss_seg(".bss$crid_143d4aa96")
alignas(2) unsigned char DAT_143d4aa96[0x2];                    // 0x143d4aa96
#pragma bss_seg(".bss$crid_143d4aa98")
alignas(8) unsigned char DAT_143d4aa98[0x2];                    // 0x143d4aa98
#pragma bss_seg(".bss$crid_143d4aa9a")
alignas(2) unsigned char DAT_143d4aa9a[0x2];                    // 0x143d4aa9a
#pragma bss_seg(".bss$crid_143d4aa9c")
alignas(4) unsigned char DAT_143d4aa9c[0x2];                    // 0x143d4aa9c
#pragma bss_seg(".bss$crid_143d4aa9e")
alignas(2) unsigned char DAT_143d4aa9e[0x2];                    // 0x143d4aa9e
#pragma bss_seg(".bss$crid_143d4aaa0")
alignas(16) unsigned char DAT_143d4aaa0[0x2];                   // 0x143d4aaa0
#pragma bss_seg(".bss$crid_143d4aaa2")
alignas(2) unsigned char DAT_143d4aaa2[0x2];                    // 0x143d4aaa2
#pragma bss_seg(".bss$crid_143d4aaa4")
alignas(4) unsigned char DAT_143d4aaa4[0x2];                    // 0x143d4aaa4
#pragma bss_seg(".bss$crid_143d4aaa6")
alignas(2) unsigned char DAT_143d4aaa6[0x2];                    // 0x143d4aaa6
#pragma bss_seg(".bss$crid_143d4aaa8")
alignas(8) unsigned char DAT_143d4aaa8[0x2];                    // 0x143d4aaa8
#pragma bss_seg(".bss$crid_143d4aaaa")
alignas(2) unsigned char DAT_143d4aaaa[0x2];                    // 0x143d4aaaa
#pragma bss_seg(".bss$crid_143d4aaac")
alignas(4) unsigned char DAT_143d4aaac[0x2];                    // 0x143d4aaac
#pragma bss_seg(".bss$crid_143d4aaae")
alignas(2) unsigned char DAT_143d4aaae[0x2];                    // 0x143d4aaae
#pragma bss_seg(".bss$crid_143d4aab0")
alignas(16) unsigned char DAT_143d4aab0[0xd0];                  // 0x143d4aab0
#pragma bss_seg(".bss$crid_143d4ab80")
alignas(16) unsigned char DAT_143d4ab80[0x8];                   // 0x143d4ab80
#pragma bss_seg(".bss$crid_143d4ab88")
alignas(8) unsigned char DAT_143d4ab88[0x8];                    // 0x143d4ab88
#pragma bss_seg(".bss$crid_143d4ab90")
alignas(16) unsigned char DAT_143d4ab90[0x60];                  // 0x143d4ab90
#pragma bss_seg(".bss$crid_143d4abf0")
alignas(16) unsigned char DAT_143d4abf0[0x8];                   // 0x143d4abf0
#pragma bss_seg(".bss$crid_143d4abf8")
alignas(8) unsigned char DAT_143d4abf8[0x1f8];                  // 0x143d4abf8
#pragma bss_seg(".bss$crid_143d4adf0")
alignas(16) unsigned char DAT_143d4adf0[0x8];                   // 0x143d4adf0
#pragma bss_seg(".bss$crid_143d4adf8")
alignas(8) unsigned char DAT_143d4adf8[0x3ff8];                 // 0x143d4adf8
#pragma bss_seg(".bss$crid_143d4edf0")
alignas(16) unsigned char DAT_143d4edf0[0x8];                   // 0x143d4edf0
#pragma bss_seg(".bss$crid_143d4edf8")
alignas(8) unsigned char DAT_143d4edf8[0x8];                    // 0x143d4edf8
#pragma bss_seg(".bss$crid_143d4ee00")
alignas(16) unsigned char DAT_143d4ee00[0x8];                   // 0x143d4ee00
#pragma bss_seg(".bss$crid_143d4ee08")
alignas(8) unsigned char DAT_143d4ee08[0x8];                    // 0x143d4ee08
#pragma bss_seg(".bss$crid_143d4ee10")
alignas(16) unsigned char DAT_143d4ee10[0x8];                   // 0x143d4ee10
#pragma bss_seg(".bss$crid_143d4ee18")
alignas(8) unsigned char DAT_143d4ee18[0x8];                    // 0x143d4ee18
#pragma bss_seg(".bss$crid_143d4ee20")
alignas(16) unsigned char DAT_143d4ee20[0x40];                  // 0x143d4ee20
#pragma bss_seg(".bss$crid_143d4ee60")
alignas(16) unsigned char DAT_143d4ee60[0x48];                  // 0x143d4ee60
#pragma bss_seg(".bss$crid_143d4eea8")
alignas(8) unsigned char DAT_143d4eea8[0x30];                   // 0x143d4eea8
#pragma bss_seg(".bss$crid_143d4eed8")
alignas(8) unsigned char DAT_143d4eed8[0x8];                    // 0x143d4eed8
#pragma bss_seg(".bss$crid_143d4eee0")
alignas(16) unsigned char DAT_143d4eee0[0x8];                   // 0x143d4eee0
#pragma bss_seg(".bss$crid_143d4eee8")
alignas(8) unsigned char DAT_143d4eee8[0x8];                    // 0x143d4eee8
#pragma bss_seg(".bss$crid_143d4eef0")
alignas(16) unsigned char DAT_143d4eef0[0x30];                  // 0x143d4eef0
#pragma bss_seg(".bss$crid_143d4ef20")
alignas(16) unsigned char DAT_143d4ef20[0x8];                   // 0x143d4ef20
#pragma bss_seg(".bss$crid_143d4ef28")
alignas(8) unsigned char DAT_143d4ef28[0x8];                    // 0x143d4ef28
#pragma bss_seg(".bss$crid_143d4ef30")
alignas(16) unsigned char DAT_143d4ef30[0x8];                   // 0x143d4ef30
#pragma bss_seg(".bss$crid_143d4ef38")
alignas(8) unsigned char DAT_143d4ef38[0x8];                    // 0x143d4ef38
#pragma bss_seg(".bss$crid_143d4ef40")
alignas(16) unsigned char DAT_143d4ef40[0x10];                  // 0x143d4ef40
#pragma bss_seg(".bss$crid_143d4ef50")
alignas(16) unsigned char DAT_143d4ef50[0xc00];                 // 0x143d4ef50
#pragma bss_seg(".bss$crid_143d4fb50")
alignas(16) unsigned char DAT_143d4fb50[0x400];                 // 0x143d4fb50
#pragma bss_seg(".bss$crid_143d4ff50")
alignas(16) unsigned char DAT_143d4ff50[0x400];                 // 0x143d4ff50
#pragma bss_seg(".bss$crid_143d50350")
alignas(16) unsigned char DAT_143d50350[0xc00];                 // 0x143d50350
#pragma bss_seg(".bss$crid_143d50f50")
alignas(16) unsigned char DAT_143d50f50[0xc00];                 // 0x143d50f50
#pragma bss_seg(".bss$crid_143d51b50")
alignas(16) unsigned char DAT_143d51b50[0xc00];                 // 0x143d51b50
#pragma bss_seg(".bss$crid_143d52750")
alignas(16) unsigned char DAT_143d52750[0xc00];                 // 0x143d52750
#pragma bss_seg(".bss$crid_143d53350")
alignas(16) unsigned char DAT_143d53350[0x400];                 // 0x143d53350
#pragma bss_seg(".bss$crid_143d53750")
alignas(16) unsigned char DAT_143d53750[0xc00];                 // 0x143d53750
#pragma bss_seg(".bss$crid_143d54350")
alignas(16) unsigned char DAT_143d54350[0xc00];                 // 0x143d54350
#pragma bss_seg(".bss$crid_143d54f50")
alignas(16) unsigned char DAT_143d54f50[0xc00];                 // 0x143d54f50
#pragma bss_seg(".bss$crid_143d55b50")
alignas(16) unsigned char DAT_143d55b50[0xc00];                 // 0x143d55b50
#pragma bss_seg(".bss$crid_143d56750")
alignas(16) unsigned char DAT_143d56750[0xc00];                 // 0x143d56750
#pragma bss_seg(".bss$crid_143d57350")
alignas(16) unsigned char DAT_143d57350[0xc00];                 // 0x143d57350
#pragma bss_seg(".bss$crid_143d57f50")
alignas(16) unsigned char DAT_143d57f50[0xc00];                 // 0x143d57f50
#pragma bss_seg(".bss$crid_143d58b50")
alignas(16) unsigned char DAT_143d58b50[0xc00];                 // 0x143d58b50
#pragma bss_seg(".bss$crid_143d59750")
alignas(16) unsigned char DAT_143d59750[0x400];                 // 0x143d59750
#pragma bss_seg(".bss$crid_143d59b50")
alignas(16) unsigned char DAT_143d59b50[0x400];                 // 0x143d59b50
#pragma bss_seg(".bss$crid_143d59f50")
alignas(16) unsigned char DAT_143d59f50[0xc00];                 // 0x143d59f50
#pragma bss_seg(".bss$crid_143d5ab50")
alignas(16) unsigned char DAT_143d5ab50[0xc00];                 // 0x143d5ab50
#pragma bss_seg(".bss$crid_143d5b750")
alignas(16) unsigned char DAT_143d5b750[0xc00];                 // 0x143d5b750
#pragma bss_seg(".bss$crid_143d5c350")
alignas(16) unsigned char DAT_143d5c350[0x400];                 // 0x143d5c350
#pragma bss_seg(".bss$crid_143d5c750")
alignas(16) unsigned char DAT_143d5c750[0x400];                 // 0x143d5c750
#pragma bss_seg(".bss$crid_143d5cb50")
alignas(16) unsigned char DAT_143d5cb50[0xc00];                 // 0x143d5cb50
#pragma bss_seg(".bss$crid_143d5d750")
alignas(16) unsigned char DAT_143d5d750[0xc00];                 // 0x143d5d750
#pragma bss_seg(".bss$crid_143d5e350")
alignas(16) unsigned char DAT_143d5e350[0xc00];                 // 0x143d5e350
#pragma bss_seg(".bss$crid_143d5ef50")
alignas(16) unsigned char DAT_143d5ef50[0xc00];                 // 0x143d5ef50
#pragma bss_seg(".bss$crid_143d5fb50")
alignas(16) unsigned char DAT_143d5fb50[0x400];                 // 0x143d5fb50
#pragma bss_seg(".bss$crid_143d5ff50")
alignas(16) unsigned char DAT_143d5ff50[0xc00];                 // 0x143d5ff50
#pragma bss_seg(".bss$crid_143d60b50")
alignas(16) unsigned char DAT_143d60b50[0xc00];                 // 0x143d60b50
#pragma bss_seg(".bss$crid_143d61750")
alignas(16) unsigned char DAT_143d61750[0xc00];                 // 0x143d61750
#pragma bss_seg(".bss$crid_143d62350")
alignas(16) unsigned char DAT_143d62350[0xc00];                 // 0x143d62350
#pragma bss_seg(".bss$crid_143d62f50")
alignas(16) unsigned char DAT_143d62f50[0xc00];                 // 0x143d62f50
#pragma bss_seg(".bss$crid_143d63b50")
alignas(16) unsigned char DAT_143d63b50[0xc00];                 // 0x143d63b50
#pragma bss_seg(".bss$crid_143d64750")
alignas(16) unsigned char DAT_143d64750[0xc00];                 // 0x143d64750
#pragma bss_seg(".bss$crid_143d65350")
alignas(16) unsigned char DAT_143d65350[0xc00];                 // 0x143d65350
#pragma bss_seg(".bss$crid_143d65f50")
alignas(16) unsigned char DAT_143d65f50[0x400];                 // 0x143d65f50
#pragma bss_seg(".bss$crid_143d66350")
alignas(16) unsigned char DAT_143d66350[0x400];                 // 0x143d66350
#pragma bss_seg(".bss$crid_143d66750")
alignas(16) unsigned char DAT_143d66750[0xc00];                 // 0x143d66750
#pragma bss_seg(".bss$crid_143d67350")
alignas(16) unsigned char DAT_143d67350[0xc00];                 // 0x143d67350
#pragma bss_seg(".bss$crid_143d67f50")
alignas(16) unsigned char DAT_143d67f50[0x8];                   // 0x143d67f50
#pragma bss_seg(".bss$crid_143d67f58")
alignas(8) unsigned char DAT_143d67f58[0x8];                    // 0x143d67f58
#pragma bss_seg(".bss$crid_143d67f60")
alignas(16) unsigned char DAT_143d67f60[0x8];                   // 0x143d67f60
#pragma bss_seg(".bss$crid_143d67f68")
alignas(8) unsigned char DAT_143d67f68[0x8];                    // 0x143d67f68
#pragma bss_seg(".bss$crid_143d67f70")
alignas(16) unsigned char DAT_143d67f70[0x10];                  // 0x143d67f70
#pragma bss_seg(".bss$crid_143d67f80")
alignas(16) unsigned char DAT_143d67f80[0x10];                  // 0x143d67f80
#pragma bss_seg(".bss$crid_143d67f90")
alignas(16) unsigned char DAT_143d67f90[0x200];                 // 0x143d67f90
#pragma bss_seg(".bss$crid_143d68190")
alignas(16) unsigned char DAT_143d68190[0x200];                 // 0x143d68190
#pragma bss_seg(".bss$crid_143d68390")
alignas(16) unsigned char DAT_143d68390[0x8];                   // 0x143d68390
#pragma bss_seg(".bss$crid_143d68398")
alignas(8) unsigned char DAT_143d68398[0x8];                    // 0x143d68398
#pragma bss_seg(".bss$crid_143d683a0")
alignas(16) unsigned char DAT_143d683a0[0x8];                   // 0x143d683a0
#pragma bss_seg(".bss$crid_143d683a8")
alignas(8) unsigned char DAT_143d683a8[0x8];                    // 0x143d683a8
#pragma bss_seg(".bss$crid_143d683b0")
alignas(16) unsigned char DAT_143d683b0[0x8];                   // 0x143d683b0
#pragma bss_seg(".bss$crid_143d683b8")
alignas(8) unsigned char DAT_143d683b8[0x8];                    // 0x143d683b8
#pragma bss_seg(".bss$crid_143d683c0")
alignas(16) unsigned char DAT_143d683c0[0x8];                   // 0x143d683c0
#pragma bss_seg(".bss$crid_143d683c8")
alignas(8) unsigned char DAT_143d683c8[0x8];                    // 0x143d683c8
#pragma bss_seg(".bss$crid_143d683d0")
alignas(16) unsigned char DAT_143d683d0[0x8];                   // 0x143d683d0
#pragma bss_seg(".bss$crid_143d683d8")
alignas(8) unsigned char DAT_143d683d8[0x8];                    // 0x143d683d8
#pragma bss_seg(".bss$crid_143d683e0")
alignas(16) unsigned char DAT_143d683e0[0x470];                 // 0x143d683e0
#pragma bss_seg(".bss$crid_143d68850")
alignas(16) unsigned char DAT_143d68850[0x8];                   // 0x143d68850
#pragma bss_seg(".bss$crid_143d68858")
alignas(8) unsigned char DAT_143d68858[0x8];                    // 0x143d68858
#pragma bss_seg(".bss$crid_143d68860")
alignas(16) unsigned char DAT_143d68860[0x8];                   // 0x143d68860
#pragma bss_seg(".bss$crid_143d68868")
alignas(8) unsigned char DAT_143d68868[0x8];                    // 0x143d68868
#pragma bss_seg(".bss$crid_143d68870")
alignas(16) unsigned char DAT_143d68870[0x8];                   // 0x143d68870
#pragma bss_seg(".bss$crid_143d68878")
alignas(8) unsigned char DAT_143d68878[0x8];                    // 0x143d68878
#pragma bss_seg(".bss$crid_143d68880")
alignas(16) unsigned char DAT_143d68880[0x8];                   // 0x143d68880
#pragma bss_seg(".bss$crid_143d68888")
alignas(8) unsigned char DAT_143d68888[0x8];                    // 0x143d68888
#pragma bss_seg(".bss$crid_143d68890")
alignas(16) unsigned char DAT_143d68890[0x8];                   // 0x143d68890
#pragma bss_seg(".bss$crid_143d68898")
alignas(8) unsigned char DAT_143d68898[0x8];                    // 0x143d68898
#pragma bss_seg(".bss$crid_143d688a0")
alignas(16) unsigned char DAT_143d688a0[0x8];                   // 0x143d688a0
#pragma bss_seg(".bss$crid_143d688a8")
alignas(8) unsigned char DAT_143d688a8[0x8];                    // 0x143d688a8
#pragma bss_seg(".bss$crid_143d688b0")
alignas(16) unsigned char DAT_143d688b0[0x8];                   // 0x143d688b0
#pragma bss_seg(".bss$crid_143d688b8")
alignas(8) unsigned char DAT_143d688b8[0x78];                   // 0x143d688b8
#pragma bss_seg(".bss$crid_143d68930")
alignas(16) unsigned char DAT_143d68930[0x180];                 // 0x143d68930
#pragma bss_seg(".bss$crid_143d68ab0")
alignas(16) unsigned char DAT_143d68ab0[0x4];                   // 0x143d68ab0
#pragma bss_seg(".bss$crid_143d68ab4")
alignas(4) unsigned char DAT_143d68ab4[0x4];                    // 0x143d68ab4
#pragma bss_seg(".bss$crid_143d68ab8")
alignas(8) unsigned char DAT_143d68ab8[0x8];                    // 0x143d68ab8
#pragma bss_seg(".bss$crid_143d68ac0")
alignas(16) unsigned char DAT_143d68ac0[0x8];                   // 0x143d68ac0
#pragma bss_seg(".bss$crid_143d68ac8")
alignas(8) unsigned char DAT_143d68ac8[0x8];                    // 0x143d68ac8
#pragma bss_seg(".bss$crid_143d68ad0")
alignas(16) unsigned char DAT_143d68ad0[0x70];                  // 0x143d68ad0
#pragma bss_seg(".bss$crid_143d74820")
alignas(16) unsigned char DAT_143d74820[0x8];                   // 0x143d74820
#pragma bss_seg(".bss$crid_143d74828")
alignas(8) unsigned char DAT_143d74828[0x8];                    // 0x143d74828
#pragma bss_seg(".bss$crid_143d74830")
alignas(16) unsigned char DAT_143d74830[0x8];                   // 0x143d74830
#pragma bss_seg(".bss$crid_143d74838")
alignas(8) unsigned char DAT_143d74838[0x8];                    // 0x143d74838
#pragma bss_seg(".bss$crid_143d74840")
alignas(16) unsigned char DAT_143d74840[0x100];                 // 0x143d74840
#pragma bss_seg(".bss$crid_143d74940")
alignas(16) unsigned char DAT_143d74940[0x20];                  // 0x143d74940
#pragma bss_seg(".bss$crid_143d74960")
alignas(16) unsigned char DAT_143d74960[0x8];                   // 0x143d74960
#pragma bss_seg(".bss$crid_143d74968")
alignas(8) unsigned char DAT_143d74968[0x8];                    // 0x143d74968
#pragma bss_seg(".bss$crid_143d74970")
alignas(16) unsigned char DAT_143d74970[0x10];                  // 0x143d74970
#pragma bss_seg(".bss$crid_143d74980")
alignas(16) unsigned char DAT_143d74980[0x8];                   // 0x143d74980
#pragma bss_seg(".bss$crid_143d74988")
alignas(8) unsigned char DAT_143d74988[0x8];                    // 0x143d74988
#pragma bss_seg(".bss$crid_143d74990")
alignas(16) unsigned char DAT_143d74990[0x10];                  // 0x143d74990
#pragma bss_seg(".bss$crid_143d749a0")
alignas(16) unsigned char DAT_143d749a0[0x8];                   // 0x143d749a0
#pragma bss_seg(".bss$crid_143d749a8")
alignas(8) unsigned char DAT_143d749a8[0x8];                    // 0x143d749a8
#pragma bss_seg(".bss$crid_143d749b0")
alignas(16) unsigned char DAT_143d749b0[0x8];                   // 0x143d749b0
#pragma bss_seg(".bss$crid_143d749b8")
alignas(8) unsigned char DAT_143d749b8[0x8];                    // 0x143d749b8
#pragma bss_seg(".bss$crid_143d749c0")
alignas(16) unsigned char DAT_143d749c0[0x8];                   // 0x143d749c0
#pragma bss_seg(".bss$crid_143d749c8")
alignas(8) unsigned char DAT_143d749c8[0x8];                    // 0x143d749c8
#pragma bss_seg(".bss$crid_143d749d0")
alignas(16) unsigned char DAT_143d749d0[0x8];                   // 0x143d749d0
#pragma bss_seg(".bss$crid_143d749d8")
alignas(8) unsigned char DAT_143d749d8[0x8];                    // 0x143d749d8
#pragma bss_seg(".bss$crid_143d749e0")
alignas(16) unsigned char DAT_143d749e0[0x8];                   // 0x143d749e0
#pragma bss_seg(".bss$crid_143d749e8")
alignas(8) unsigned char DAT_143d749e8[0x8];                    // 0x143d749e8
#pragma bss_seg(".bss$crid_143d749f0")
alignas(16) unsigned char DAT_143d749f0[0x8];                   // 0x143d749f0
#pragma bss_seg(".bss$crid_143d749f8")
alignas(8) unsigned char DAT_143d749f8[0x8];                    // 0x143d749f8
#pragma bss_seg(".bss$crid_143d74a00")
alignas(16) unsigned char DAT_143d74a00[0x8];                   // 0x143d74a00
#pragma bss_seg(".bss$crid_143d74a08")
alignas(8) unsigned char DAT_143d74a08[0x8];                    // 0x143d74a08
#pragma bss_seg(".bss$crid_143d74a10")
alignas(16) unsigned char DAT_143d74a10[0x8];                   // 0x143d74a10
#pragma bss_seg(".bss$crid_143d74a18")
alignas(8) unsigned char DAT_143d74a18[0x8];                    // 0x143d74a18
#pragma bss_seg(".bss$crid_143d74a20")
alignas(16) unsigned char DAT_143d74a20[0x8];                   // 0x143d74a20
#pragma bss_seg(".bss$crid_143d74a28")
alignas(8) unsigned char DAT_143d74a28[0x8];                    // 0x143d74a28
#pragma bss_seg(".bss$crid_143d74a30")
alignas(16) unsigned char DAT_143d74a30[0x8];                   // 0x143d74a30
#pragma bss_seg(".bss$crid_143d74a38")
alignas(8) unsigned char DAT_143d74a38[0x8];                    // 0x143d74a38
#pragma bss_seg(".bss$crid_143d74a40")
alignas(16) unsigned char DAT_143d74a40[0x8];                   // 0x143d74a40
#pragma bss_seg(".bss$crid_143d74a48")
alignas(8) unsigned char DAT_143d74a48[0x8];                    // 0x143d74a48
#pragma bss_seg(".bss$crid_143d74a50")
alignas(16) unsigned char DAT_143d74a50[0x8];                   // 0x143d74a50
#pragma bss_seg(".bss$crid_143d74a58")
alignas(8) unsigned char DAT_143d74a58[0x8];                    // 0x143d74a58
#pragma bss_seg(".bss$crid_143d74a60")
alignas(16) unsigned char DAT_143d74a60[0x20];                  // 0x143d74a60
#pragma bss_seg(".bss$crid_143d74a80")
alignas(16) unsigned char DAT_143d74a80[0x4];                   // 0x143d74a80
#pragma bss_seg(".bss$crid_143d74a84")
alignas(4) unsigned char DAT_143d74a84[0x40000];                // 0x143d74a84
#pragma bss_seg(".bss$crid_143db4a84")
alignas(4) unsigned char DAT_143db4a84[0x3c];                   // 0x143db4a84
#pragma bss_seg(".bss$crid_143db4ac0")
alignas(16) unsigned char DAT_143db4ac0[0x1];                   // 0x143db4ac0
#pragma bss_seg(".bss$crid_143db4ac1")
alignas(1) unsigned char DAT_143db4ac1[0x1003f];                // 0x143db4ac1
#pragma bss_seg(".bss$crid_143dc4b00")
alignas(16) unsigned char DAT_143dc4b00[0x2];                   // 0x143dc4b00
#pragma bss_seg(".bss$crid_143dc4b02")
alignas(2) unsigned char DAT_143dc4b02[0x7fffe];                // 0x143dc4b02
#pragma bss_seg(".bss$crid_143e44b00")
alignas(16) unsigned char DAT_143e44b00[0x20000];               // 0x143e44b00
#pragma bss_seg(".bss$crid_143ee68c0")
alignas(16) unsigned char DAT_143ee68c0[0x1];                   // 0x143ee68c0
#pragma bss_seg(".bss$crid_143ee68c1")
alignas(1) unsigned char DAT_143ee68c1[0xfff];                  // 0x143ee68c1
#pragma bss_seg(".bss$crid_143ee78c0")
alignas(16) unsigned char DAT_143ee78c0[0x1];                   // 0x143ee78c0
#pragma bss_seg(".bss$crid_143ee78c1")
alignas(1) unsigned char DAT_143ee78c1[0x3ff];                  // 0x143ee78c1
#pragma bss_seg(".bss$crid_143ee7cc0")
alignas(16) unsigned char DAT_143ee7cc0[0x1];                   // 0x143ee7cc0
#pragma bss_seg(".bss$crid_143ee7cc1")
alignas(1) unsigned char DAT_143ee7cc1[0x7ffff];                // 0x143ee7cc1
#pragma bss_seg(".bss$crid_143f67cc0")
alignas(16) unsigned char DAT_143f67cc0[0x1];                   // 0x143f67cc0
#pragma bss_seg(".bss$crid_143f67cc1")
alignas(1) unsigned char DAT_143f67cc1[0x3ff];                  // 0x143f67cc1
#pragma bss_seg(".bss$crid_143f680c0")
alignas(16) unsigned char DAT_143f680c0[0x1];                   // 0x143f680c0
#pragma bss_seg(".bss$crid_143f680c1")
alignas(1) unsigned char DAT_143f680c1[0x7f];                   // 0x143f680c1
#pragma bss_seg(".bss$crid_143f68140")
alignas(16) unsigned char DAT_143f68140[0x1];                   // 0x143f68140
#pragma bss_seg(".bss$crid_143f68141")
alignas(1) unsigned char DAT_143f68141[0xff];                   // 0x143f68141
#pragma bss_seg(".bss$crid_143f68240")
alignas(16) unsigned char DAT_143f68240[0x1];                   // 0x143f68240
#pragma bss_seg(".bss$crid_143f68241")
alignas(1) unsigned char DAT_143f68241[0x1];                    // 0x143f68241
#pragma bss_seg(".bss$crid_143f68242")
alignas(2) unsigned char DAT_143f68242[0x7fffe];                // 0x143f68242
#pragma bss_seg(".bss$crid_143fe8240")
alignas(16) unsigned char DAT_143fe8240[0x1];                   // 0x143fe8240
#pragma bss_seg(".bss$crid_143fe8241")
alignas(1) unsigned char DAT_143fe8241[0x7];                    // 0x143fe8241
#pragma bss_seg(".bss$crid_143fe8248")
alignas(8) unsigned char DAT_143fe8248[0x8];                    // 0x143fe8248
#pragma bss_seg(".bss$crid_143fe8250")
alignas(16) unsigned char DAT_143fe8250[0x10];                  // 0x143fe8250
#pragma bss_seg(".bss$crid_143fe8260")
alignas(16) unsigned char DAT_143fe8260[0x1];                   // 0x143fe8260
#pragma bss_seg(".bss$crid_143fe8261")
alignas(1) unsigned char DAT_143fe8261[0x1];                    // 0x143fe8261
#pragma bss_seg(".bss$crid_143fe8262")
alignas(2) unsigned char DAT_143fe8262[0x1];                    // 0x143fe8262
#pragma bss_seg(".bss$crid_143fe8263")
alignas(1) unsigned char DAT_143fe8263[0x5];                    // 0x143fe8263
#pragma bss_seg(".bss$crid_143fe8268")
alignas(8) unsigned char DAT_143fe8268[0x8];                    // 0x143fe8268
#pragma bss_seg(".bss$crid_143fe8270")
alignas(16) unsigned char DAT_143fe8270[0x8];                   // 0x143fe8270
#pragma bss_seg(".bss$crid_143fe8278")
alignas(8) unsigned char DAT_143fe8278[0x8];                    // 0x143fe8278
#pragma bss_seg(".bss$crid_143fe8280")
alignas(16) unsigned char DAT_143fe8280[0x8];                   // 0x143fe8280
#pragma bss_seg(".bss$crid_143fe8288")
alignas(8) unsigned char DAT_143fe8288[0x8];                    // 0x143fe8288
#pragma bss_seg(".bss$crid_143fe8290")
alignas(16) unsigned char DAT_143fe8290[0x8];                   // 0x143fe8290
#pragma bss_seg(".bss$crid_143fe8298")
alignas(8) unsigned char DAT_143fe8298[0x8];                    // 0x143fe8298
#pragma bss_seg(".bss$crid_143fe82a0")
alignas(16) unsigned char DAT_143fe82a0[0x40];                  // 0x143fe82a0
#pragma bss_seg(".bss$crid_143fe82e0")
alignas(16) unsigned char DAT_143fe82e0[0x100];                 // 0x143fe82e0
#pragma bss_seg(".bss$crid_143fe83e0")
alignas(16) unsigned char DAT_143fe83e0[0x3f];                  // 0x143fe83e0
#pragma bss_seg(".bss$crid_143fe841f")
alignas(1) unsigned char DAT_143fe841f[0x1];                    // 0x143fe841f
#pragma bss_seg(".bss$crid_143fe8420")
alignas(16) unsigned char DAT_143fe8420[0xc0];                  // 0x143fe8420
#pragma bss_seg(".bss$crid_143fe84e0")
alignas(16) unsigned char DAT_143fe84e0[0x8];                   // 0x143fe84e0
#pragma bss_seg(".bss$crid_143fe84e8")
alignas(8) unsigned char DAT_143fe84e8[0x8];                    // 0x143fe84e8
#pragma bss_seg(".bss$crid_143fe84f0")
alignas(16) unsigned char DAT_143fe84f0[0x18];                  // 0x143fe84f0
#pragma bss_seg(".bss$crid_143fe8508")
alignas(8) unsigned char DAT_143fe8508[0x8];                    // 0x143fe8508
#pragma bss_seg(".bss$crid_143fe8510")
alignas(16) unsigned char DAT_143fe8510[0x4];                   // 0x143fe8510
#pragma bss_seg(".bss$crid_143fe8514")
alignas(4) unsigned char DAT_143fe8514[0x14];                   // 0x143fe8514
#pragma bss_seg(".bss$crid_143fe8528")
alignas(8) unsigned char DAT_143fe8528[0x8];                    // 0x143fe8528
#pragma bss_seg(".bss$crid_143fe8530")
alignas(16) unsigned char DAT_143fe8530[0x8];                   // 0x143fe8530
#pragma bss_seg(".bss$crid_143fe8538")
alignas(8) unsigned char DAT_143fe8538[0x8];                    // 0x143fe8538
#pragma bss_seg(".bss$crid_143fe8540")
alignas(16) unsigned char DAT_143fe8540[0x137a0];               // 0x143fe8540
#pragma bss_seg(".bss$crid_143ffbce0")
alignas(16) unsigned char DAT_143ffbce0[0x8];                   // 0x143ffbce0
#pragma bss_seg(".bss$crid_143ffbce8")
alignas(8) unsigned char DAT_143ffbce8[0x8];                    // 0x143ffbce8
#pragma bss_seg(".bss$crid_143ffbcf0")
alignas(16) unsigned char DAT_143ffbcf0[0x10];                  // 0x143ffbcf0
#pragma bss_seg(".bss$crid_143ffbd00")
alignas(16) unsigned char DAT_143ffbd00[0x8];                   // 0x143ffbd00
#pragma bss_seg(".bss$crid_143ffbd08")
alignas(8) unsigned char DAT_143ffbd08[0x8];                    // 0x143ffbd08
#pragma bss_seg(".bss$crid_143ffbd10")
alignas(16) unsigned char DAT_143ffbd10[0x8];                   // 0x143ffbd10
#pragma bss_seg(".bss$crid_143ffbd18")
alignas(8) unsigned char DAT_143ffbd18[0x17d0];                 // 0x143ffbd18
#pragma bss_seg(".bss$crid_143ffd4e8")
alignas(8) unsigned char DAT_143ffd4e8[0x18];                   // 0x143ffd4e8
#pragma bss_seg(".bss$crid_143ffd500")
alignas(16) unsigned char DAT_143ffd500[0x4];                   // 0x143ffd500
#pragma bss_seg(".bss$crid_143ffd504")
alignas(4) unsigned char DAT_143ffd504[0x4c];                   // 0x143ffd504
#pragma bss_seg(".bss$crid_143ffd550")
alignas(16) unsigned char DAT_143ffd550[0x8];                   // 0x143ffd550
#pragma bss_seg()

#pragma comment(linker, "/alternatename:?DAT_1431b8db0@@3QBQEBXB=?DAT_1431b8db0@@3USd_1431b8db0@@A")
#pragma comment(linker, "/alternatename:DAT_1431b8db0=?DAT_1431b8db0@@3USd_1431b8db0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b8e08@@3QBQEBXB=?DAT_1431b8e08@@3USd_1431b8e08@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b8f18@@3QBQEBXB=?DAT_1431b8f18@@3USd_1431b8f18@@A")
#pragma comment(linker, "/alternatename:DAT_1431b8f18=?DAT_1431b8f18@@3USd_1431b8f18@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b8f30@@3QBQEBXB=?DAT_1431b8f30@@3USd_1431b8f30@@A")
#pragma comment(linker, "/alternatename:DAT_1431b8f30=?DAT_1431b8f30@@3USd_1431b8f30@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b8fa0@@3QBQEBXB=?DAT_1431b8fa0@@3USd_1431b8fa0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b8fc8@@3QBQEBXB=?DAT_1431b8fc8@@3USd_1431b8fc8@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b8fd0@@3QBQEBXB=?DAT_1431b8fd0@@3USd_1431b8fd0@@A")
#pragma comment(linker, "/alternatename:DAT_1431b8fd0=?DAT_1431b8fd0@@3USd_1431b8fd0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b9028@@3QBQEBXB=?DAT_1431b9028@@3USd_1431b9028@@A")
#pragma comment(linker, "/alternatename:DAT_1431b9028=?DAT_1431b9028@@3USd_1431b9028@@A")
#pragma comment(linker, "/alternatename:DAT_1431b9080=?DAT_1431b9080@@3USd_1431b9080@@A")
#pragma comment(linker, "/alternatename:DAT_1431b91b0=?DAT_1431b91b0@@3USd_1431b91b0@@A")
#pragma comment(linker, "/alternatename:DAT_1431b91d8=?DAT_1431b91d8@@3USd_1431b91d8@@A")
#pragma comment(linker, "/alternatename:DAT_1431b93b0=?DAT_1431b93b0@@3USd_1431b93b0@@A")
#pragma comment(linker, "/alternatename:DAT_1431b93c0=?DAT_1431b93c0@@3USd_1431b93c0@@A")
#pragma comment(linker, "/alternatename:DAT_1431b9410=?DAT_1431b9410@@3USd_1431b9410@@A")
#pragma comment(linker, "/alternatename:DAT_1431b9430=?DAT_1431b9430@@3USd_1431b9430@@A")
#pragma comment(linker, "/alternatename:DAT_1431b97a0=?DAT_1431b97a0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431b97a8=?DAT_1431b97a8@@3USd_1431b97a8@@A")
#pragma comment(linker, "/alternatename:DAT_1431b9820=?DAT_1431b9820@@3PAEA")
#pragma comment(linker, "/alternatename:PTR_FUN_1431b9b10=?DAT_1431b9b10@@3USd_1431b9b10@@A")
#pragma comment(linker, "/alternatename:DAT_1431b9ca0=?DAT_1431b9ca0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431ba290=?DAT_1431ba290@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431ba2e0=?DAT_1431ba2e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431ba2e8=?DAT_1431ba2e8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431ba4f8=?DAT_1431ba4f8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431ba7c8=?DAT_1431ba7c8@@3USd_1431ba7c8@@A")
#pragma comment(linker, "/alternatename:DAT_1431ba800=?DAT_1431ba800@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431ba950=?DAT_1431ba950@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431ba990=?DAT_1431ba990@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baa10=?DAT_1431baa10@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baa20=?DAT_1431baa20@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baa28=?DAT_1431baa28@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baa30=?DAT_1431baa30@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baa31=?DAT_1431baa31@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baa32=?DAT_1431baa32@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baa33=?DAT_1431baa33@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baaf0=?DAT_1431baaf0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baaf1=?DAT_1431baaf1@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baaf2=?DAT_1431baaf2@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baaf3=?DAT_1431baaf3@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bab30=?DAT_1431bab30@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bab40=?DAT_1431bab40@@3PAEA")
#pragma comment(linker, "/alternatename:PTR_LAB_1431bab50=?DAT_1431bab50@@3USd_1431bab50@@A")
#pragma comment(linker, "/alternatename:PTR_LAB_1431bab60=?DAT_1431bab60@@3USd_1431bab60@@A")
#pragma comment(linker, "/alternatename:DAT_1431bac00=?DAT_1431bac00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bac90=?DAT_1431bac90@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bac98=?DAT_1431bac98@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bacb8=?DAT_1431bacb8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bace8=?DAT_1431bace8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bad00=?DAT_1431bad00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bad40=?DAT_1431bad40@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bad90=?DAT_1431bad90@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bada0=?DAT_1431bada0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bae28=?DAT_1431bae28@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bae40=?DAT_1431bae40@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baf40=?DAT_1431baf40@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431baf70=?DAT_1431baf70@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bafa0=?DAT_1431bafa0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bb320=?DAT_1431bb320@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bb6b0=?DAT_1431bb6b0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bba40=?DAT_1431bba40@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bba50=?DAT_1431bba50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bba60=?DAT_1431bba60@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bbbd8=?DAT_1431bbbd8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bbbf8=?DAT_1431bbbf8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bbc18=?DAT_1431bbc18@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bbc38=?DAT_1431bbc38@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bbc58=?DAT_1431bbc58@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bbc78=?DAT_1431bbc78@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bbc90=?DAT_1431bbc90@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bbcd0=?DAT_1431bbcd0@@3PAEA")
#pragma comment(linker, "/alternatename:PTR_LAB_1431bbd20=?DAT_1431bbd20@@3USd_1431bbd20@@A")
#pragma comment(linker, "/alternatename:PTR_FUN_1431bbd40=?DAT_1431bbd40@@3USd_1431bbd40@@A")
#pragma comment(linker, "/alternatename:PTR_FUN_1431bbd50=?DAT_1431bbd50@@3USd_1431bbd50@@A")
#pragma comment(linker, "/alternatename:DAT_1431bbd60=?DAT_1431bbd60@@3PAEA")
#pragma comment(linker, "/alternatename:UNK_1431bbd7d=?DAT_1431bbd7d@@3PAEA")
#pragma comment(linker, "/alternatename:UNK_1431bbd7e=?DAT_1431bbd7e@@3PAEA")
#pragma comment(linker, "/alternatename:UNK_1431bbd7f=?DAT_1431bbd7f@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bbd80=?DAT_1431bbd80@@3PAEA")
#pragma comment(linker, "/alternatename:UNK_1431bbdbc=?DAT_1431bbdbc@@3PAEA")
#pragma comment(linker, "/alternatename:UNK_1431bbdbe=?DAT_1431bbdbe@@3PAEA")
#pragma comment(linker, "/alternatename:UNK_1431bbdbf=?DAT_1431bbdbf@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bbdc1=?DAT_1431bbdc1@@3PAEA")
#pragma comment(linker, "/alternatename:PTR_LAB_1431bc290=?DAT_1431bc290@@3USd_1431bc290@@A")
#pragma comment(linker, "/alternatename:DAT_1431bc310=?DAT_1431bc310@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bc350=?DAT_1431bc350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bc3b8=?DAT_1431bc3b8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bc3e8=?DAT_1431bc3e8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bc3f8=?DAT_1431bc3f8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bc410=?DAT_1431bc410@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_1431bc440=?DAT_1431bc440@@3PAEA")
#pragma comment(linker, "/alternatename:PTR_LAB_1431bc450=?DAT_1431bc450@@3USd_1431bc450@@A")
#pragma comment(linker, "/alternatename:PTR_FUN_1431bc6c0=?DAT_1431bc6c0@@3USd_1431bc6c0@@A")
#pragma comment(linker, "/alternatename:PTR_FUN_1431bc6d8=?DAT_1431bc6d8@@3USd_1431bc6d8@@A")
#pragma comment(linker, "/alternatename:DAT_1431bcbb0=?DAT_1431bcbb0@@3USd_1431bcbb0@@A")
#pragma comment(linker, "/alternatename:DAT_1431bcbe8=?DAT_1431bcbe8@@3USd_1431bcbe8@@A")
#pragma comment(linker, "/alternatename:DAT_1431bec40=?DAT_1431bec40@@3USd_1431bec40@@A")
#pragma comment(linker, "/alternatename:DAT_1431bec50=?DAT_1431bec50@@3USd_1431bec50@@A")
#pragma comment(linker, "/alternatename:DAT_1431bec80=?DAT_1431bec80@@3USd_1431bec80@@A")
#pragma comment(linker, "/alternatename:DAT_1431bec90=?DAT_1431bec90@@3USd_1431bec90@@A")
#pragma comment(linker, "/alternatename:DAT_1431bed08=?DAT_1431bed08@@3USd_1431bed08@@A")
#pragma comment(linker, "/alternatename:DAT_1431bed18=?DAT_1431bed18@@3USd_1431bed18@@A")
#pragma comment(linker, "/alternatename:DAT_1431bed50=?DAT_1431bed50@@3USd_1431bed50@@A")
#pragma comment(linker, "/alternatename:DAT_1431bed60=?DAT_1431bed60@@3USd_1431bed60@@A")
#pragma comment(linker, "/alternatename:DAT_1431bedd8=?DAT_1431bedd8@@3USd_1431bedd8@@A")
#pragma comment(linker, "/alternatename:DAT_1431bede8=?DAT_1431bede8@@3USd_1431bede8@@A")
#pragma comment(linker, "/alternatename:DAT_1431bee50=?DAT_1431bee50@@3USd_1431bee50@@A")
#pragma comment(linker, "/alternatename:DAT_1431bee68=?DAT_1431bee68@@3USd_1431bee68@@A")
#pragma comment(linker, "/alternatename:DAT_1431bee78=?DAT_1431bee78@@3USd_1431bee78@@A")
#pragma comment(linker, "/alternatename:DAT_1431beef0=?DAT_1431beef0@@3USd_1431beef0@@A")
#pragma comment(linker, "/alternatename:DAT_1431bef00=?DAT_1431bef00@@3USd_1431bef00@@A")
#pragma comment(linker, "/alternatename:DAT_1431bef38=?DAT_1431bef38@@3USd_1431bef38@@A")
#pragma comment(linker, "/alternatename:?pHandleWorkBuf@Video@1GFx@Scaleform@@2PEAXEA=?DAT_143b277a8@@3PEAXEA")
#pragma comment(linker, "/alternatename:?HandleWorkSize@Video@1GFx@Scaleform@@2KA=?DAT_143b277b0@@3KA")
#pragma comment(linker, "/alternatename:?Initialized@Video@1GFx@Scaleform@@2IA=?DAT_143b277b4@@3IA")
#pragma comment(linker, "/alternatename:?DAT_143b277c0@@3PADA=?DAT_143b277c0@@3PAEA")
#pragma comment(linker, "/alternatename:?ErrorContainer@CriMv@@3W4CriError@@A=?DAT_143b278c0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27948=?DAT_143b27948@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b2794c=?DAT_143b2794c@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27950=?DAT_143b27950@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27a40=?DAT_143b27a40@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27a48=?DAT_143b27a48@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27a68=?DAT_143b27a68@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27a88=?DAT_143b27a88@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27aa8=?DAT_143b27aa8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27ab0=?DAT_143b27ab0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27bb0=?DAT_143b27bb0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27bb8=?DAT_143b27bb8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27bc0=?DAT_143b27bc0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27bc8=?DAT_143b27bc8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27bcc=?DAT_143b27bcc@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27bd0=?DAT_143b27bd0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27be0=?DAT_143b27be0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27be8=?DAT_143b27be8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27bf0=?DAT_143b27bf0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c3c=?DAT_143b27c3c@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c40=?DAT_143b27c40@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c48=?DAT_143b27c48@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c50=?DAT_143b27c50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c58=?DAT_143b27c58@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c60=?DAT_143b27c60@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c64=?DAT_143b27c64@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c68=?DAT_143b27c68@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c6c=?DAT_143b27c6c@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c70=?DAT_143b27c70@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c78=?DAT_143b27c78@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143b27c80=?DAT_143b27c80@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c490e0=?DAT_143c490e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c490e8=?DAT_143c490e8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c490f0=?DAT_143c490f0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c490f8=?DAT_143c490f8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c49100=?DAT_143c49100@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c49110=?DAT_143c49110@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49118=?DAT_143c49118@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49120=?DAT_143c49120@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49128=?DAT_143c49128@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c49160=?DAT_143c49160@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49178=?DAT_143c49178@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c491b0=?DAT_143c491b0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c491b8=?DAT_143c491b8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c491c0=?DAT_143c491c0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c491c8=?DAT_143c491c8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c491d0=?DAT_143c491d0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49208=?DAT_143c49208@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49210=?DAT_143c49210@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49218=?DAT_143c49218@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49220=?DAT_143c49220@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c49250=?DAT_143c49250@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49260=?DAT_143c49260@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49268=?DAT_143c49268@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c492a0=?DAT_143c492a0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c492b0=?DAT_143c492b0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c492c8=?DAT_143c492c8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c49300=?DAT_143c49300@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49318=?DAT_143c49318@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c49350=?DAT_143c49350@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49360=?DAT_143c49360@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49368=?DAT_143c49368@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c493a0=?DAT_143c493a0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c493a8=?DAT_143c493a8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c493b0=?DAT_143c493b0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c493b8=?DAT_143c493b8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c493f0=?DAT_143c493f0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49408=?DAT_143c49408@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c49440=?DAT_143c49440@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49448=?DAT_143c49448@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49450=?DAT_143c49450@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49458=?DAT_143c49458@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49460=?DAT_143c49460@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c49498=?DAT_143c49498@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c494a0=?DAT_143c494a0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c494a8=?DAT_143c494a8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c494b0=?DAT_143c494b0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c494e0=?DAT_143c494e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c494e8=?DAT_143c494e8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143c494f0=?DAT_143c494f0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c494f8=?DAT_143c494f8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143c49500=?DAT_143c49500@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d49580=?DAT_143d49580@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d49680=?DAT_143d49680@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d49780=?DAT_143d49780@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d49880=?DAT_143d49880@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49900=?DAT_143d49900@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49908=?DAT_143d49908@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49910=?DAT_143d49910@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49918=?DAT_143d49918@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49920=?DAT_143d49920@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49928=?DAT_143d49928@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49930=?DAT_143d49930@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49938=?DAT_143d49938@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49940=?DAT_143d49940@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49948=?DAT_143d49948@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49950=?DAT_143d49950@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49958=?DAT_143d49958@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49960=?DAT_143d49960@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49968=?DAT_143d49968@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49970=?DAT_143d49970@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49978=?DAT_143d49978@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4997c=?DAT_143d4997c@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4997d=?DAT_143d4997d@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4997e=?DAT_143d4997e@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4997f=?DAT_143d4997f@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d49980=?DAT_143d49980@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d49d80=?DAT_143d49d80@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49d80=?DAT_143d49d80@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49d88=?DAT_143d49d88@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49d90=?DAT_143d49d90@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49d98=?DAT_143d49d98@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49da0=?DAT_143d49da0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49da8=?DAT_143d49da8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49db0=?DAT_143d49db0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49db8=?DAT_143d49db8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49dc0=?DAT_143d49dc0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49dc8=?DAT_143d49dc8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49dd0=?DAT_143d49dd0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49dd8=?DAT_143d49dd8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49de0=?DAT_143d49de0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49de8=?DAT_143d49de8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49df0=?DAT_143d49df0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49df8=?DAT_143d49df8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e00=?DAT_143d49e00@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e04=?DAT_143d49e04@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e08=?DAT_143d49e08@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e0c=?DAT_143d49e0c@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e10=?DAT_143d49e10@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e14=?DAT_143d49e14@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e18=?DAT_143d49e18@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e1c=?DAT_143d49e1c@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e20=?DAT_143d49e20@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e28=?DAT_143d49e28@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e30=?DAT_143d49e30@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e38=?DAT_143d49e38@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e40=?DAT_143d49e40@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e48=?DAT_143d49e48@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e50=?DAT_143d49e50@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e58=?DAT_143d49e58@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e60=?DAT_143d49e60@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e68=?DAT_143d49e68@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e70=?DAT_143d49e70@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e78=?DAT_143d49e78@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e80=?DAT_143d49e80@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e88=?DAT_143d49e88@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e90=?DAT_143d49e90@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49e98=?DAT_143d49e98@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49ea0=?DAT_143d49ea0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49ea8=?DAT_143d49ea8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49eb0=?DAT_143d49eb0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49eb8=?DAT_143d49eb8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49ec0=?DAT_143d49ec0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49ec8=?DAT_143d49ec8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49ed0=?DAT_143d49ed0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49ed8=?DAT_143d49ed8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49ee0=?DAT_143d49ee0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49ee8=?DAT_143d49ee8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49ef0=?DAT_143d49ef0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49ef8=?DAT_143d49ef8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d49f00=?DAT_143d49f00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d49f80=?DAT_143d49f80@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f80=?DAT_143d49f80@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f82=?DAT_143d49f82@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f84=?DAT_143d49f84@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f86=?DAT_143d49f86@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f88=?DAT_143d49f88@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f8a=?DAT_143d49f8a@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f8c=?DAT_143d49f8c@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f8e=?DAT_143d49f8e@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f90=?DAT_143d49f90@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f92=?DAT_143d49f92@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f94=?DAT_143d49f94@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f96=?DAT_143d49f96@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f98=?DAT_143d49f98@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f9a=?DAT_143d49f9a@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f9c=?DAT_143d49f9c@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49f9e=?DAT_143d49f9e@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49fa0=?DAT_143d49fa0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49fa2=?DAT_143d49fa2@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49fa4=?DAT_143d49fa4@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49fa6=?DAT_143d49fa6@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49fa8=?DAT_143d49fa8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49faa=?DAT_143d49faa@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49fac=?DAT_143d49fac@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d49fae=?DAT_143d49fae@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d49fb0=?DAT_143d49fb0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a080=?DAT_143d4a080@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a080=?DAT_143d4a080@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a082=?DAT_143d4a082@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a084=?DAT_143d4a084@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a086=?DAT_143d4a086@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a088=?DAT_143d4a088@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a08a=?DAT_143d4a08a@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a08c=?DAT_143d4a08c@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a08e=?DAT_143d4a08e@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a090=?DAT_143d4a090@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a092=?DAT_143d4a092@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a094=?DAT_143d4a094@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a096=?DAT_143d4a096@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a098=?DAT_143d4a098@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a09a=?DAT_143d4a09a@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a09c=?DAT_143d4a09c@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a09e=?DAT_143d4a09e@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0a0=?DAT_143d4a0a0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0a2=?DAT_143d4a0a2@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0a4=?DAT_143d4a0a4@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0a6=?DAT_143d4a0a6@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0a8=?DAT_143d4a0a8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0aa=?DAT_143d4a0aa@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0ac=?DAT_143d4a0ac@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0ae=?DAT_143d4a0ae@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0b0=?DAT_143d4a0b0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0b2=?DAT_143d4a0b2@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0b4=?DAT_143d4a0b4@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0b6=?DAT_143d4a0b6@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0b8=?DAT_143d4a0b8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0ba=?DAT_143d4a0ba@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0bc=?DAT_143d4a0bc@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a0be=?DAT_143d4a0be@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a0c0=?DAT_143d4a0c0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a0e0=?DAT_143d4a0e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a100=?DAT_143d4a100@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a130=?DAT_143d4a130@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a200=?DAT_143d4a200@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a200=?DAT_143d4a200@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a202=?DAT_143d4a202@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a204=?DAT_143d4a204@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a240=?DAT_143d4a240@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a240=?DAT_143d4a240@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a242=?DAT_143d4a242@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a244=?DAT_143d4a244@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a246=?DAT_143d4a246@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a248=?DAT_143d4a248@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a2c0=?DAT_143d4a2c0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2c0=?DAT_143d4a2c0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2c2=?DAT_143d4a2c2@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2c4=?DAT_143d4a2c4@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2c6=?DAT_143d4a2c6@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2c8=?DAT_143d4a2c8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2ca=?DAT_143d4a2ca@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2cc=?DAT_143d4a2cc@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2ce=?DAT_143d4a2ce@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2d0=?DAT_143d4a2d0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2d2=?DAT_143d4a2d2@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2d4=?DAT_143d4a2d4@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2d6=?DAT_143d4a2d6@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2d8=?DAT_143d4a2d8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2da=?DAT_143d4a2da@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2dc=?DAT_143d4a2dc@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a2de=?DAT_143d4a2de@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a2e0=?DAT_143d4a2e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a300=?DAT_143d4a300@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a300=?DAT_143d4a300@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a302=?DAT_143d4a302@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a304=?DAT_143d4a304@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a306=?DAT_143d4a306@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a308=?DAT_143d4a308@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a30a=?DAT_143d4a30a@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a30c=?DAT_143d4a30c@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a30e=?DAT_143d4a30e@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a310=?DAT_143d4a310@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a312=?DAT_143d4a312@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a314=?DAT_143d4a314@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a316=?DAT_143d4a316@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a318=?DAT_143d4a318@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a31a=?DAT_143d4a31a@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a31c=?DAT_143d4a31c@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a31e=?DAT_143d4a31e@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a320=?DAT_143d4a320@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a340=?DAT_143d4a340@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a340=?DAT_143d4a340@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a348=?DAT_143d4a348@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a350=?DAT_143d4a350@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a358=?DAT_143d4a358@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a360=?DAT_143d4a360@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a368=?DAT_143d4a368@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a370=?DAT_143d4a370@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a378=?DAT_143d4a378@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a380=?DAT_143d4a380@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a388=?DAT_143d4a388@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a390=?DAT_143d4a390@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a398=?DAT_143d4a398@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a3a0=?DAT_143d4a3a0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a3a8=?DAT_143d4a3a8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a3b0=?DAT_143d4a3b0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a3b8=?DAT_143d4a3b8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a3bc=?DAT_143d4a3bc@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a3bd=?DAT_143d4a3bd@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a3be=?DAT_143d4a3be@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a3bf=?DAT_143d4a3bf@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a3c0=?DAT_143d4a3c0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a3c0=?DAT_143d4a3c0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a3c2=?DAT_143d4a3c2@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a3c4=?DAT_143d4a3c4@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a400=?DAT_143d4a400@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a400=?DAT_143d4a400@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a408=?DAT_143d4a408@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a410=?DAT_143d4a410@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a418=?DAT_143d4a418@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a420=?DAT_143d4a420@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a428=?DAT_143d4a428@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a430=?DAT_143d4a430@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a438=?DAT_143d4a438@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a440=?DAT_143d4a440@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a448=?DAT_143d4a448@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a450=?DAT_143d4a450@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a458=?DAT_143d4a458@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a460=?DAT_143d4a460@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a468=?DAT_143d4a468@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a470=?DAT_143d4a470@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a478=?DAT_143d4a478@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a47c=?DAT_143d4a47c@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a47d=?DAT_143d4a47d@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a47e=?DAT_143d4a47e@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a47f=?DAT_143d4a47f@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a480=?DAT_143d4a480@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a580=?DAT_143d4a580@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a680=?DAT_143d4a680@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a700=?DAT_143d4a700@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a780=?DAT_143d4a780@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a800=?DAT_143d4a800@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a808=?DAT_143d4a808@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a810=?DAT_143d4a810@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a818=?DAT_143d4a818@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a820=?DAT_143d4a820@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a828=?DAT_143d4a828@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a830=?DAT_143d4a830@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a838=?DAT_143d4a838@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a840=?DAT_143d4a840@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a848=?DAT_143d4a848@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a850=?DAT_143d4a850@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a858=?DAT_143d4a858@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a860=?DAT_143d4a860@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a868=?DAT_143d4a868@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a870=?DAT_143d4a870@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a878=?DAT_143d4a878@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a87c=?DAT_143d4a87c@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a87d=?DAT_143d4a87d@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a87e=?DAT_143d4a87e@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a87f=?DAT_143d4a87f@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a880=?DAT_143d4a880@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a8a0=?DAT_143d4a8a0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a8a2=?DAT_143d4a8a2@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a8a4=?DAT_143d4a8a4@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a8bc=?DAT_143d4a8bc@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4a8be=?DAT_143d4a8be@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a8c0=?DAT_143d4a8c0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4a8e0=?DAT_143d4a8e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4aa80=?DAT_143d4aa80@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa80=?DAT_143d4aa80@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa82=?DAT_143d4aa82@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa84=?DAT_143d4aa84@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa86=?DAT_143d4aa86@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa88=?DAT_143d4aa88@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa8a=?DAT_143d4aa8a@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa8c=?DAT_143d4aa8c@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa8e=?DAT_143d4aa8e@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa90=?DAT_143d4aa90@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa92=?DAT_143d4aa92@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa94=?DAT_143d4aa94@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa96=?DAT_143d4aa96@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa98=?DAT_143d4aa98@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa9a=?DAT_143d4aa9a@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa9c=?DAT_143d4aa9c@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aa9e=?DAT_143d4aa9e@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aaa0=?DAT_143d4aaa0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aaa2=?DAT_143d4aaa2@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aaa4=?DAT_143d4aaa4@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aaa6=?DAT_143d4aaa6@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aaa8=?DAT_143d4aaa8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aaaa=?DAT_143d4aaaa@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aaac=?DAT_143d4aaac@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4aaae=?DAT_143d4aaae@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4aab0=?DAT_143d4aab0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ab80=?DAT_143d4ab80@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4ab88=?DAT_143d4ab88@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ab90=?DAT_143d4ab90@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4abf0=?DAT_143d4abf0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4abf8=?DAT_143d4abf8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4adf0=?DAT_143d4adf0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4adf8=?DAT_143d4adf8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4edf0=?DAT_143d4edf0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4edf8=?DAT_143d4edf8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4ee00=?DAT_143d4ee00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ee08=?DAT_143d4ee08@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ee10=?DAT_143d4ee10@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ee18=?DAT_143d4ee18@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ee20=?DAT_143d4ee20@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ee60=?DAT_143d4ee60@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4eea8=?DAT_143d4eea8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4eed8=?DAT_143d4eed8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4eee0=?DAT_143d4eee0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4eee8=?DAT_143d4eee8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4eef0=?DAT_143d4eef0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4ef20=?DAT_143d4ef20@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ef28=?DAT_143d4ef28@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ef30=?DAT_143d4ef30@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4ef38=?DAT_143d4ef38@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d4ef40=?DAT_143d4ef40@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ef50=?DAT_143d4ef50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4fb50=?DAT_143d4fb50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d4ff50=?DAT_143d4ff50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d50350=?DAT_143d50350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d50f50=?DAT_143d50f50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d51b50=?DAT_143d51b50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d52750=?DAT_143d52750@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d53350=?DAT_143d53350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d53750=?DAT_143d53750@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d54350=?DAT_143d54350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d54f50=?DAT_143d54f50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d55b50=?DAT_143d55b50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d56750=?DAT_143d56750@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d57350=?DAT_143d57350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d57f50=?DAT_143d57f50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d58b50=?DAT_143d58b50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d59750=?DAT_143d59750@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d59b50=?DAT_143d59b50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d59f50=?DAT_143d59f50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d5ab50=?DAT_143d5ab50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d5b750=?DAT_143d5b750@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d5c350=?DAT_143d5c350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d5c750=?DAT_143d5c750@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d5cb50=?DAT_143d5cb50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d5d750=?DAT_143d5d750@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d5e350=?DAT_143d5e350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d5ef50=?DAT_143d5ef50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d5fb50=?DAT_143d5fb50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d5ff50=?DAT_143d5ff50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d60b50=?DAT_143d60b50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d61750=?DAT_143d61750@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d62350=?DAT_143d62350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d62f50=?DAT_143d62f50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d63b50=?DAT_143d63b50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d64750=?DAT_143d64750@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d65350=?DAT_143d65350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d65f50=?DAT_143d65f50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d66350=?DAT_143d66350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d66750=?DAT_143d66750@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d67350=?DAT_143d67350@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d67f50=?DAT_143d67f50@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d67f58=?DAT_143d67f58@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d67f60=?DAT_143d67f60@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d67f68=?DAT_143d67f68@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d67f70=?DAT_143d67f70@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d67f80=?DAT_143d67f80@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d67f90=?DAT_143d67f90@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68190=?DAT_143d68190@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68390=?DAT_143d68390@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68398=?DAT_143d68398@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d683a0=?DAT_143d683a0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d683a8=?DAT_143d683a8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d683b0=?DAT_143d683b0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d683b8=?DAT_143d683b8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d683c0=?DAT_143d683c0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d683c8=?DAT_143d683c8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d683d0=?DAT_143d683d0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d683d8=?DAT_143d683d8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d683e0=?DAT_143d683e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68850=?DAT_143d68850@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68858=?DAT_143d68858@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68860=?DAT_143d68860@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68868=?DAT_143d68868@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68870=?DAT_143d68870@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68878=?DAT_143d68878@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d68880=?DAT_143d68880@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d68888=?DAT_143d68888@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d68890=?DAT_143d68890@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d68898=?DAT_143d68898@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d688a0=?DAT_143d688a0@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d688a8=?DAT_143d688a8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d688b0=?DAT_143d688b0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d688b8=?DAT_143d688b8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68930=?DAT_143d68930@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68ab0=?DAT_143d68ab0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68ab4=?DAT_143d68ab4@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68ab8=?DAT_143d68ab8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d68ac0=?DAT_143d68ac0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68ac8=?DAT_143d68ac8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d68ad0=?DAT_143d68ad0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74820=?DAT_143d74820@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d74820=?DAT_143d74820@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d74828=?DAT_143d74828@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d74830=?DAT_143d74830@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d74838=?DAT_143d74838@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74840=?DAT_143d74840@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74940=?DAT_143d74940@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74960=?DAT_143d74960@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74968=?DAT_143d74968@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d74970=?DAT_143d74970@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74980=?DAT_143d74980@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74988=?DAT_143d74988@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d74990=?DAT_143d74990@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749a0=?DAT_143d749a0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749a8=?DAT_143d749a8@@3PAEA")
#pragma comment(linker, "/alternatename:_DAT_143d749b0=?DAT_143d749b0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749b8=?DAT_143d749b8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749c0=?DAT_143d749c0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749c8=?DAT_143d749c8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749d0=?DAT_143d749d0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749d8=?DAT_143d749d8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749e0=?DAT_143d749e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749e8=?DAT_143d749e8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749f0=?DAT_143d749f0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d749f8=?DAT_143d749f8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a00=?DAT_143d74a00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a08=?DAT_143d74a08@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a10=?DAT_143d74a10@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a18=?DAT_143d74a18@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a20=?DAT_143d74a20@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a28=?DAT_143d74a28@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a30=?DAT_143d74a30@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a38=?DAT_143d74a38@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a40=?DAT_143d74a40@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a48=?DAT_143d74a48@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a50=?DAT_143d74a50@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a58=?DAT_143d74a58@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a60=?DAT_143d74a60@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a80=?DAT_143d74a80@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143d74a84=?DAT_143d74a84@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143db4a84=?DAT_143db4a84@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143db4ac0=?DAT_143db4ac0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143db4ac1=?DAT_143db4ac1@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143dc4b00=?DAT_143dc4b00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143dc4b02=?DAT_143dc4b02@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143e44b00=?DAT_143e44b00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ee68c0=?DAT_143ee68c0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ee68c1=?DAT_143ee68c1@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ee78c0=?DAT_143ee78c0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ee78c1=?DAT_143ee78c1@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ee7cc0=?DAT_143ee7cc0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ee7cc1=?DAT_143ee7cc1@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143f67cc0=?DAT_143f67cc0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143f67cc1=?DAT_143f67cc1@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143f680c0=?DAT_143f680c0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143f680c1=?DAT_143f680c1@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143f68140=?DAT_143f68140@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143f68141=?DAT_143f68141@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143f68240=?DAT_143f68240@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143f68241=?DAT_143f68241@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143f68242=?DAT_143f68242@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8240=?DAT_143fe8240@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8241=?DAT_143fe8241@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8248=?DAT_143fe8248@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8250=?DAT_143fe8250@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8260=?DAT_143fe8260@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8261=?DAT_143fe8261@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8262=?DAT_143fe8262@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8263=?DAT_143fe8263@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8268=?DAT_143fe8268@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8270=?DAT_143fe8270@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8278=?DAT_143fe8278@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8280=?DAT_143fe8280@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8288=?DAT_143fe8288@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8290=?DAT_143fe8290@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8298=?DAT_143fe8298@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe82a0=?DAT_143fe82a0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe82e0=?DAT_143fe82e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe83e0=?DAT_143fe83e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe841f=?DAT_143fe841f@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8420=?DAT_143fe8420@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe84e0=?DAT_143fe84e0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe84e8=?DAT_143fe84e8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe84f0=?DAT_143fe84f0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8508=?DAT_143fe8508@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8510=?DAT_143fe8510@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8514=?DAT_143fe8514@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8528=?DAT_143fe8528@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8530=?DAT_143fe8530@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8538=?DAT_143fe8538@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143fe8540=?DAT_143fe8540@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffbce0=?DAT_143ffbce0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffbce8=?DAT_143ffbce8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffbcf0=?DAT_143ffbcf0@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffbd00=?DAT_143ffbd00@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffbd08=?DAT_143ffbd08@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffbd10=?DAT_143ffbd10@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffbd18=?DAT_143ffbd18@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffd4e8=?DAT_143ffd4e8@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffd500=?DAT_143ffd500@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffd504=?DAT_143ffd504@@3PAEA")
#pragma comment(linker, "/alternatename:DAT_143ffd550=?DAT_143ffd550@@3PAEA")
#pragma comment(linker, "/alternatename:?DAT_14001d720@@3PAEA=?DetachReader@VideoReaderConfig@Video@GFx@Scaleform@@UEAAXPEAVVideoReader@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1400284b0@@3PAEA=?FUN_1400284b0@@YAPEAXPEAXE@Z")
#pragma comment(linker, "/alternatename:?DAT_140029280@@3PAEA=?FUN_140029280@@YAPEAXPEAXE@Z")
#pragma comment(linker, "/alternatename:?DAT_14002d490@@3PAEA=?GetFileSize@VideoReader@Video@GFx@Scaleform@@UEAA_JXZ")
#pragma comment(linker, "/alternatename:?DAT_14002d4a0@@3PAEA=?GetReadSize@VideoReader@Video@GFx@Scaleform@@UEAA_JXZ")
#pragma comment(linker, "/alternatename:?DAT_14002d4b0@@3PAEA=?GetOpenStatus@VideoReader@Video@GFx@Scaleform@@UEAA?AW4AsyncStatus@CriMvFileReaderInterface@@XZ")
#pragma comment(linker, "/alternatename:?DAT_14002d4c0@@3PAEA=?GetCloseStatus@VideoReader@Video@GFx@Scaleform@@UEAA?AW4AsyncStatus@CriMvFileReaderInterface@@XZ")
#pragma comment(linker, "/alternatename:?DAT_14002d4d0@@3PAEA=?GetReadStatus@VideoReader@Video@GFx@Scaleform@@UEAA?AW4AsyncStatus@CriMvFileReaderInterface@@XZ")
#pragma comment(linker, "/alternatename:?DAT_140041270@@3PAEA=?FUN_140041270@@YAJPEAX@Z")
#pragma comment(linker, "/alternatename:?DAT_142443950@@3PAEA=?GetAsMemoryImage@Image@Render@Scaleform@@UEAAPEAVMemoryBufferImage@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_142444340@@3PAEA=?GetRect@Image@Render@Scaleform@@UEBA?AV?$Rect@K@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_142444bc0@@3PAEA=?IsDelegate@ImageBase@Render@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142447310@@3PAEA=?Update@Image@Render@Scaleform@@UEAA_NPEAVImageUpdate@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_142447340@@3PAEA=?Update@Image@Render@Scaleform@@UEAA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14257aa60@@3PAEA=?CreateSubImage@Image@Render@Scaleform@@UEAAPEAV123@AEBV?$Rect@I@23@PEAVMemoryHeap@3@@Z")
#pragma comment(linker, "/alternatename:?DAT_14257b4a0@@3PAEA=?GetAsImage@TextureImage@Render@Scaleform@@UEAAPEAVImage@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_14257b4e0@@3PAEA=?GetBaseImageId@TextureImage@Render@Scaleform@@UEBAKXZ")
#pragma comment(linker, "/alternatename:?DAT_14257b550@@3PAEA=?GetBytes@TextureImage@Render@Scaleform@@UEBA_KPEAH@Z")
#pragma comment(linker, "/alternatename:?DAT_14257b5f0@@3PAEA=?GetFormat@TextureImage@Render@Scaleform@@UEBA?AW4ImageFormat@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_14257b970@@3PAEA=?GetImageId@TextureImage@Render@Scaleform@@UEBAKXZ")
#pragma comment(linker, "/alternatename:?DAT_14257b9a0@@3PAEA=?GetImageType@TextureImage@Render@Scaleform@@UEBA?AW4ImageType@ImageBase@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_14257b9b0@@3PAEA=?GetMatrix@Image@Render@Scaleform@@UEBAXPEAV?$Matrix2x4@M@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14257ba20@@3PAEA=?GetMatrixInverse@Image@Render@Scaleform@@UEBAXPEAV?$Matrix2x4@M@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14257bda0@@3PAEA=?GetMipmapCount@TextureImage@Render@Scaleform@@UEBAIXZ")
#pragma comment(linker, "/alternatename:?DAT_14257c140@@3PAEA=?GetSize@TextureImage@Render@Scaleform@@UEBA?AV?$Size@K@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_14257c210@@3PAEA=?GetUVGenMatrix@Image@Render@Scaleform@@UEAAXPEAV?$Matrix2x4@M@23@PEAVTextureManager@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14257c310@@3PAEA=?GetUVNormMatrix@Image@Render@Scaleform@@UEAAXPEAV?$Matrix2x4@M@23@PEAVTextureManager@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14257c500@@3PAEA=?GetUse@TextureImage@Render@Scaleform@@UEBAIXZ")
#pragma comment(linker, "/alternatename:?DAT_14257cb10@@3PAEA=?Map@TextureImage@Render@Scaleform@@UEAA_NPEAVImageData@23@II@Z")
#pragma comment(linker, "/alternatename:?DAT_14257d120@@3PAEA=?SetMatrix@Image@Render@Scaleform@@UEAAXAEBV?$Matrix2x4@M@23@PEAVMemoryHeap@3@@Z")
#pragma comment(linker, "/alternatename:?DAT_14257d1b0@@3PAEA=?SetMatrixInverse@Image@Render@Scaleform@@UEAAXAEBV?$Matrix2x4@M@23@PEAVMemoryHeap@3@@Z")
#pragma comment(linker, "/alternatename:?DAT_14257d470@@3PAEA=?TextureLost@TextureImage@Render@Scaleform@@UEAAXW4TextureLossReason@Image@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14257d4c0@@3PAEA=?Unmap@TextureImage@Render@Scaleform@@UEAA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14257dc40@@3PAEA=?AddRef@RefCountVImpl@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14257dcf0@@3PAEA=?Release@RefCountVImpl@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14280ef52@@3PAEA=_purecall")
#pragma comment(linker, "/alternatename:?DAT_143224848@@3PAEA=??_7DOMBuilder@XML@GFx@Scaleform@@6B@")

#endif // MS2_HOOK_DLL
