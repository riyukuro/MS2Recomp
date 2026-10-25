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

extern unsigned char DAT_140002930[];
extern unsigned char DAT_140002950[];
extern unsigned char DAT_140002960[];
extern unsigned char DAT_140002980[];
extern unsigned char DAT_140002b00[];
extern unsigned char DAT_140002b30[];
extern unsigned char DAT_140002bb0[];
extern unsigned char DAT_140002c10[];
extern unsigned char DAT_140002cc0[];
extern unsigned char DAT_140002d20[];
extern unsigned char DAT_140002d90[];
extern unsigned char DAT_140002da0[];
extern unsigned char DAT_140002db0[];
extern unsigned char DAT_140002dc0[];
extern unsigned char DAT_140002dd0[];
extern unsigned char DAT_140002de0[];
extern unsigned char DAT_140002df0[];
extern unsigned char DAT_140002e00[];
extern unsigned char DAT_140002e10[];
extern unsigned char DAT_140002e20[];
extern unsigned char DAT_140002e40[];
extern unsigned char DAT_1400047a0[];
extern unsigned char DAT_140004810[];
extern unsigned char DAT_140004880[];
extern unsigned char DAT_140005780[];
extern unsigned char DAT_140007ba0[];
extern unsigned char DAT_140007d90[];
extern unsigned char DAT_140007da0[];
extern unsigned char DAT_140007db0[];
extern unsigned char DAT_140007dc0[];
extern unsigned char DAT_140007dd0[];
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
extern unsigned char DAT_14000a010[];
extern unsigned char DAT_14000a020[];
extern unsigned char DAT_14000a110[];
extern unsigned char DAT_14000a3a0[];
extern unsigned char DAT_14000a770[];
extern unsigned char DAT_14000a880[];
extern unsigned char DAT_14000c9f0[];
extern unsigned char DAT_14000ce70[];
extern unsigned char DAT_14000ce80[];
extern unsigned char DAT_14000ce90[];
extern unsigned char DAT_14000cea0[];
extern unsigned char DAT_14000ceb0[];
extern unsigned char DAT_14000d320[];
extern unsigned char DAT_14000d6e0[];
extern unsigned char DAT_14000d6f0[];
extern unsigned char DAT_14000d700[];
extern unsigned char DAT_14000d710[];
extern unsigned char DAT_14000d730[];
extern unsigned char DAT_14000d760[];
extern unsigned char DAT_14000daa0[];
extern unsigned char DAT_14000db10[];
extern unsigned char DAT_14000dbc0[];
extern unsigned char DAT_14000e1a0[];
extern unsigned char DAT_14000e370[];
extern unsigned char DAT_14000e380[];
extern unsigned char DAT_14000e3e0[];
extern unsigned char DAT_14000e3f0[];
extern unsigned char DAT_14000e400[];
extern unsigned char DAT_14000e410[];
extern unsigned char DAT_14000e470[];
extern unsigned char DAT_14000e4d0[];
extern unsigned char DAT_14000e500[];
extern unsigned char DAT_14000e510[];
extern unsigned char DAT_14000e520[];
extern unsigned char DAT_14000e530[];
extern unsigned char DAT_14000e540[];
extern unsigned char DAT_14000e550[];
extern unsigned char DAT_14000e560[];
extern unsigned char DAT_14000e570[];
extern unsigned char DAT_14000e580[];
extern unsigned char DAT_14000e590[];
extern unsigned char DAT_14000e5d0[];
extern unsigned char DAT_14000e5e0[];
extern unsigned char DAT_14000e600[];
extern unsigned char DAT_14000e610[];
extern unsigned char DAT_14000e620[];
extern unsigned char DAT_14000e630[];
extern unsigned char DAT_14000e640[];
extern unsigned char DAT_14000e650[];
extern unsigned char DAT_14000e670[];
extern unsigned char DAT_14000e680[];
extern unsigned char DAT_14000e690[];
extern unsigned char DAT_14000e6a0[];
extern unsigned char DAT_14000e6b0[];
extern unsigned char DAT_14000e6c0[];
extern unsigned char DAT_14000e6d0[];
extern unsigned char DAT_14000e6e0[];
extern unsigned char DAT_14000e6f0[];
extern unsigned char DAT_14000e700[];
extern unsigned char DAT_14000e710[];
extern unsigned char DAT_14000e720[];
extern unsigned char DAT_14000e730[];
extern unsigned char DAT_14000e740[];
extern unsigned char DAT_14000e750[];
extern unsigned char DAT_14000e760[];
extern unsigned char DAT_14000e770[];
extern unsigned char DAT_14000e780[];
extern unsigned char DAT_14000e790[];
extern unsigned char DAT_14000e7a0[];
extern unsigned char DAT_14000e7b0[];
extern unsigned char DAT_14000e7c0[];
extern unsigned char DAT_14000e7d0[];
extern unsigned char DAT_14000e7e0[];
extern unsigned char DAT_14000e7f0[];
extern unsigned char DAT_14000e800[];
extern unsigned char DAT_14000e810[];
extern unsigned char DAT_14000e820[];
extern unsigned char DAT_14000e830[];
extern unsigned char DAT_14000e880[];
extern unsigned char DAT_14000e890[];
extern unsigned char DAT_14000e8a0[];
extern unsigned char DAT_14000e8f0[];
extern unsigned char DAT_14000e9f0[];
extern unsigned char DAT_140019af0[];
extern unsigned char DAT_140019b60[];
extern unsigned char DAT_140019bd0[];
extern unsigned char DAT_14001a040[];
extern unsigned char DAT_14001a0b0[];
extern unsigned char DAT_14001a2f0[];
extern unsigned char DAT_14001a470[];
extern unsigned char DAT_14001a5c0[];
extern unsigned char DAT_14001a760[];
extern unsigned char DAT_14001a800[];
extern unsigned char DAT_14001a860[];
extern unsigned char DAT_14001ae30[];
extern unsigned char DAT_14001aea0[];
extern unsigned char DAT_14001af10[];
extern unsigned char DAT_14001afd0[];
extern unsigned char DAT_14001afe0[];
extern unsigned char DAT_14001aff0[];
extern unsigned char DAT_14001b000[];
extern unsigned char DAT_14001b010[];
extern unsigned char DAT_14001b020[];
extern unsigned char DAT_14001b030[];
extern unsigned char DAT_14001b040[];
extern unsigned char DAT_14001b050[];
extern unsigned char DAT_14001b060[];
extern unsigned char DAT_14001b070[];
extern unsigned char DAT_14001b080[];
extern unsigned char DAT_14001b090[];
extern unsigned char DAT_14001b0a0[];
extern unsigned char DAT_14001b0b0[];
extern unsigned char DAT_14001b0c0[];
extern unsigned char DAT_14001b0d0[];
extern unsigned char DAT_14001b0e0[];
extern unsigned char DAT_14001b100[];
extern unsigned char DAT_14001b110[];
extern unsigned char DAT_14001b120[];
extern unsigned char DAT_14001b130[];
extern unsigned char DAT_14001b140[];
extern unsigned char DAT_14001b160[];
extern unsigned char DAT_14001b170[];
extern unsigned char DAT_14001b180[];
extern unsigned char DAT_14001b190[];
extern unsigned char DAT_14001b1a0[];
extern unsigned char DAT_14001b1b0[];
extern unsigned char DAT_14001b1c0[];
extern unsigned char DAT_14001b1d0[];
extern unsigned char DAT_14001b1e0[];
extern unsigned char DAT_14001b1f0[];
extern unsigned char DAT_14001b200[];
extern unsigned char DAT_14001b210[];
extern unsigned char DAT_14001b220[];
extern unsigned char DAT_14001b230[];
extern unsigned char DAT_14001b240[];
extern unsigned char DAT_14001b250[];
extern unsigned char DAT_14001b260[];
extern unsigned char DAT_14001b270[];
extern unsigned char DAT_14001b280[];
extern unsigned char DAT_14001b290[];
extern unsigned char DAT_14001b2a0[];
extern unsigned char DAT_14001b2b0[];
extern unsigned char DAT_14001b2c0[];
extern unsigned char DAT_14001b2d0[];
extern unsigned char DAT_14001b2e0[];
extern unsigned char DAT_14001b2f0[];
extern unsigned char DAT_14001b300[];
extern unsigned char DAT_14001b310[];
extern unsigned char DAT_14001b320[];
extern unsigned char DAT_14001b330[];
extern unsigned char DAT_14001b340[];
extern unsigned char DAT_14001b350[];
extern unsigned char DAT_14001b360[];
extern unsigned char DAT_14001b370[];
extern unsigned char DAT_14001b380[];
extern unsigned char DAT_14001b390[];
extern unsigned char DAT_14001b3a0[];
extern unsigned char DAT_142300840[];
extern unsigned char DAT_1423dc0b0[];
extern unsigned char DAT_1423dcd60[];
extern unsigned char DAT_1423df420[];
extern unsigned char DAT_1423df430[];
extern unsigned char DAT_1423df460[];
extern unsigned char DAT_1423df4a0[];
extern unsigned char DAT_1423df580[];
extern unsigned char DAT_1423df590[];
extern unsigned char DAT_1423df5a0[];
extern unsigned char DAT_1423df5b0[];
extern unsigned char DAT_142442e10[];
extern unsigned char DAT_142443380[];
extern unsigned char DAT_1424e4290[];
extern unsigned char DAT_1424e42a0[];
extern unsigned char DAT_1424e8060[];
extern unsigned char DAT_1424eb250[];
extern unsigned char DAT_1424eb770[];
extern unsigned char DAT_1424ee6f0[];
extern unsigned char DAT_1424ee7f0[];
extern unsigned char DAT_1424eeca0[];
extern unsigned char DAT_1424effa0[];
extern unsigned char DAT_1424f0610[];
extern unsigned char DAT_1424f0700[];
extern unsigned char DAT_1424f2400[];
extern unsigned char DAT_1424f4a40[];
extern unsigned char DAT_1424f7180[];
extern unsigned char DAT_1424f74d0[];
extern unsigned char DAT_1424fe610[];
extern unsigned char DAT_142500e50[];
extern unsigned char DAT_142501a60[];
extern unsigned char DAT_142503800[];
extern unsigned char DAT_142503f50[];
extern unsigned char DAT_142503fa0[];
extern unsigned char DAT_142504840[];
extern unsigned char DAT_142505f20[];
extern unsigned char DAT_142506ef0[];
extern unsigned char DAT_142507590[];
extern unsigned char DAT_1425084c0[];
extern unsigned char DAT_1425084d0[];
extern unsigned char DAT_142509990[];
extern unsigned char DAT_142509a80[];
extern unsigned char DAT_142509ca0[];
extern unsigned char DAT_142509d30[];
extern unsigned char DAT_142509d40[];
extern unsigned char DAT_142509da0[];
extern unsigned char DAT_142509dc0[];
extern unsigned char DAT_14250a5b0[];
extern unsigned char DAT_14250b360[];
extern unsigned char DAT_14250b3a0[];
extern unsigned char DAT_14250bbd0[];
extern unsigned char DAT_14250bc40[];
extern unsigned char DAT_14250be40[];
extern unsigned char DAT_14250c010[];
extern unsigned char DAT_14250c060[];
extern unsigned char DAT_14250c2e0[];
extern unsigned char DAT_14250cc20[];
extern unsigned char DAT_14250cc60[];
extern unsigned char DAT_14250d550[];
extern unsigned char DAT_14250d570[];
extern unsigned char DAT_14250d620[];
extern unsigned char DAT_14250d6f0[];
extern unsigned char DAT_14250ee20[];
extern unsigned char DAT_14250f760[];
extern unsigned char DAT_14250f820[];
extern unsigned char DAT_14250f850[];
extern unsigned char DAT_142510a30[];
extern unsigned char DAT_142510d10[];
extern unsigned char DAT_142510d40[];
extern unsigned char DAT_142510e60[];
extern unsigned char DAT_1425117e0[];
extern unsigned char DAT_1425117f0[];
extern unsigned char DAT_142511810[];
extern unsigned char DAT_142512620[];
extern unsigned char DAT_142514320[];
extern unsigned char DAT_142515190[];
extern unsigned char DAT_142516630[];
extern unsigned char DAT_1425185d0[];
extern unsigned char DAT_142518990[];
extern unsigned char DAT_14251a100[];
extern unsigned char DAT_14251a3a0[];
extern unsigned char DAT_14251a820[];
extern unsigned char DAT_14251ac20[];
extern unsigned char DAT_14251ac30[];
extern unsigned char DAT_14251ace0[];
extern unsigned char DAT_14251cab0[];
extern unsigned char DAT_14251ced0[];
extern unsigned char DAT_14251cfc0[];
extern unsigned char DAT_14251f3a0[];
extern unsigned char DAT_14251f540[];
extern unsigned char DAT_14251f550[];
extern unsigned char DAT_14251f560[];
extern unsigned char DAT_14251f5c0[];
extern unsigned char DAT_14251f5d0[];
extern unsigned char DAT_1425227d0[];
extern unsigned char DAT_142525c90[];
extern unsigned char DAT_1425265f0[];
extern unsigned char DAT_142526720[];
extern unsigned char DAT_1425287f0[];
extern unsigned char DAT_142528800[];
extern unsigned char DAT_142528a50[];
extern unsigned char DAT_142528d90[];
extern unsigned char DAT_142529f50[];
extern unsigned char DAT_14252b580[];
extern unsigned char DAT_14252c4e0[];
extern unsigned char DAT_14252c9c0[];
extern unsigned char DAT_14252c9d0[];
extern unsigned char DAT_14252c9e0[];
extern unsigned char DAT_14252e480[];
extern unsigned char DAT_1425f1ae0[];
extern unsigned char DAT_1425f1ca0[];
extern unsigned char DAT_1425f1d50[];
extern unsigned char DAT_1425f1d70[];
extern unsigned char DAT_1425f1db0[];
extern unsigned char DAT_1425f1f60[];
extern unsigned char DAT_1425f2040[];
extern unsigned char DAT_1425f2140[];
extern unsigned char DAT_1425f2210[];
extern unsigned char DAT_1425f22e0[];
extern unsigned char DAT_1425f23e0[];
extern unsigned char DAT_1425f25c0[];
extern unsigned char DAT_1425f2600[];
extern unsigned char DAT_1425f2760[];
extern unsigned char DAT_1425f29a0[];
extern unsigned char DAT_1425f2a40[];
extern unsigned char DAT_1425f2cd0[];
extern unsigned char DAT_1425f2d40[];
extern unsigned char DAT_1425f2db0[];
extern unsigned char DAT_1425f2e20[];
extern unsigned char DAT_1425f2e90[];
extern unsigned char DAT_1425f2f00[];
extern unsigned char DAT_1425f2f70[];
extern unsigned char DAT_1425f2fe0[];
extern unsigned char DAT_1425f3390[];
extern unsigned char DAT_1425f33e0[];
extern unsigned char DAT_1425f3980[];
extern unsigned char DAT_1425f3de0[];
extern unsigned char DAT_1425f40a0[];
extern unsigned char DAT_1425f41b0[];
extern unsigned char DAT_1425f41f0[];
extern unsigned char DAT_1425f4460[];
extern unsigned char DAT_1425f4d70[];
extern unsigned char DAT_1425f5010[];
extern unsigned char DAT_1425f5530[];
extern unsigned char DAT_1425f56c0[];
extern unsigned char DAT_1425f57a0[];
extern unsigned char DAT_1425f5e70[];
extern unsigned char DAT_1425f6130[];
extern unsigned char DAT_1425f64c0[];
extern unsigned char DAT_1425f6690[];
extern unsigned char DAT_1425f6760[];
extern unsigned char DAT_1425f69f0[];
extern unsigned char DAT_1425f6bc0[];
extern unsigned char DAT_1425f6c90[];
extern unsigned char DAT_1425f6f20[];
extern unsigned char DAT_1425f6fe0[];
extern unsigned char DAT_1425f75c0[];
extern unsigned char DAT_1425f7af0[];
extern unsigned char DAT_1425f7fc0[];
extern unsigned char DAT_1425f8480[];
extern unsigned char DAT_1425f8540[];
extern unsigned char DAT_1425f8550[];
extern unsigned char DAT_1425f85e0[];
extern unsigned char DAT_1425f8630[];
extern unsigned char DAT_1425f8690[];
extern unsigned char DAT_1425f86d0[];
extern unsigned char DAT_1425f8760[];
extern unsigned char DAT_1425f8870[];
extern unsigned char DAT_1425f8880[];
extern unsigned char DAT_1425f88e0[];
extern unsigned char DAT_1425f8940[];
extern unsigned char DAT_14280ef52[];
extern unsigned char DAT_1429386e0[];
extern unsigned char DAT_1429388e0[];
extern unsigned char DAT_14293ff70[];
extern unsigned char DAT_142940160[];
extern unsigned char DAT_1429411f0[];
extern unsigned char DAT_1429413c0[];
extern unsigned char DAT_142942e70[];
extern unsigned char DAT_1429448c0[];
extern unsigned char DAT_142944950[];
extern unsigned char DAT_1429493c0[];
extern unsigned char DAT_142949400[];
extern unsigned char DAT_142949860[];
extern unsigned char DAT_14294ab50[];
extern unsigned char DAT_14294afb0[];
extern unsigned char DAT_14294f7d0[];
extern unsigned char DAT_142953280[];
extern unsigned char DAT_142955080[];
extern unsigned char DAT_142956b10[];
extern unsigned char DAT_142956ca0[];
extern unsigned char DAT_14295d840[];
extern unsigned char DAT_14295d970[];
extern unsigned char DAT_142962310[];
extern unsigned char DAT_1429623a0[];
extern unsigned char DAT_142962bb0[];
extern unsigned char DAT_142965510[];
extern unsigned char DAT_1429867f0[];
extern unsigned char DAT_142988930[];
extern unsigned char DAT_1429889c0[];
extern unsigned char DAT_142988bb0[];
extern unsigned char DAT_14298ab80[];
extern unsigned char DAT_14298cc70[];
extern unsigned char DAT_14298dcb0[];
extern unsigned char DAT_142991140[];
extern unsigned char DAT_142991170[];
extern unsigned char DAT_1429926f0[];
extern unsigned char DAT_142992780[];
extern unsigned char DAT_142994660[];
extern unsigned char DAT_1429947f0[];
extern unsigned char DAT_142994bb0[];
extern unsigned char DAT_142994c50[];
extern unsigned char DAT_14313d990[];
extern unsigned char DAT_14313da30[];
extern unsigned char DAT_14313dad0[];
extern unsigned char DAT_14313db20[];
extern unsigned char DAT_143146580[];
extern unsigned char DAT_143150b00[];
extern unsigned char DAT_143177ac0[];
void FUN_14000e0c0();
void FUN_14000ebc0();
void FUN_14000ebd0();
void FUN_14000ec40();
void FUN_14000ed10();
void FUN_14000ed20();
void FUN_140010130();
void FUN_140010140();
void FUN_140010180();
void FUN_140010200();
void FUN_140010530();
void FUN_140011610();
void FUN_140011b80();
void FUN_140011b90();
void FUN_140011ba0();
void FUN_140011bb0();
void FUN_140011bd0();
void FUN_140011c00();
void FUN_140011c70();
void FUN_140011c80();
void FUN_140011d00();
void FUN_140011d10();
void FUN_140011d50();
void FUN_140011d90();
void FUN_140011de0();
void FUN_140012400();
void FUN_140012580();
void FUN_140012590();
void FUN_1400125e0();
void FUN_1400126a0();
void FUN_1400126b0();
void FUN_140012e10();
void FUN_140012ef0();
void FUN_140012f40();
void FUN_140013230();
void FUN_140013250();
void FUN_1400133e0();
void FUN_140013400();
void FUN_140013420();
void FUN_140013440();
void FUN_1400141a0();
void FUN_140014900();
void FUN_140014a80();
void FUN_140014b10();
void FUN_140015590();
void FUN_1400155d0();
void FUN_140015c00();
void FUN_140015c40();
void FUN_140015d20();
void FUN_140015da0();
void FUN_140015e20();
void FUN_140015eb0();
void FUN_140015f20();
void FUN_140015f90();
void FUN_140016000();
void FUN_140016060();
void FUN_140016100();
void FUN_140016180();
void FUN_140016200();
void FUN_140016270();
void FUN_1400162f0();
void FUN_140016350();
void FUN_1400163b0();
void FUN_140016410();
void FUN_1400164a0();
void FUN_140016530();
void FUN_1400165a0();
void FUN_140016600();
void FUN_140016680();
void FUN_140016700();
void FUN_140016790();
void FUN_140016810();
void FUN_1400168a0();
void FUN_140016920();
void FUN_1400169b0();
void FUN_140016a30();
void FUN_140016ac0();
void FUN_140016b50();
void FUN_140016be0();
void FUN_140016fd0();
void FUN_140017020();
void FUN_140017070();
void FUN_140017470();
void FUN_140017520();
void FUN_140017670();
void FUN_1400182f0();
void FUN_140018930();
void FUN_140019890();
void FUN_140019d70();
void FUN_140019e20();
void FUN_140019ed0();

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
struct Sd_1431b5e20 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
    const void* p30;
    const void* p38;
    const void* p40;
    unsigned char b48[0x8];
};
struct Sd_1431b5e70 {
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
struct Sd_1431b5f20 {
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
    unsigned char b88[0x8];
};
struct Sd_1431b5fb0 {
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
struct Sd_1431b6060 {
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
    const void* p148;
    const void* p150;
    const void* p158;
    const void* p160;
    const void* p168;
    const void* p170;
    const void* p178;
    const void* p180;
    const void* p188;
    const void* p190;
    const void* p198;
    const void* p1a0;
    const void* p1a8;
    const void* p1b0;
    const void* p1b8;
    const void* p1c0;
    const void* p1c8;
    const void* p1d0;
    const void* p1d8;
    const void* p1e0;
    const void* p1e8;
    const void* p1f0;
    const void* p1f8;
    const void* p200;
    const void* p208;
    const void* p210;
    const void* p218;
    const void* p220;
    const void* p228;
    const void* p230;
    const void* p238;
    const void* p240;
    const void* p248;
    const void* p250;
    const void* p258;
    const void* p260;
    const void* p268;
    const void* p270;
    const void* p278;
    const void* p280;
    const void* p288;
    const void* p290;
    const void* p298;
    const void* p2a0;
    const void* p2a8;
    const void* p2b0;
    const void* p2b8;
    const void* p2c0;
    const void* p2c8;
    const void* p2d0;
    const void* p2d8;
    const void* p2e0;
    const void* p2e8;
    const void* p2f0;
    const void* p2f8;
    const void* p300;
    const void* p308;
    const void* p310;
    const void* p318;
    const void* p320;
    const void* p328;
    const void* p330;
    const void* p338;
    const void* p340;
    const void* p348;
    const void* p350;
    const void* p358;
    const void* p360;
    const void* p368;
    const void* p370;
    const void* p378;
    const void* p380;
    const void* p388;
    const void* p390;
};
struct Sd_1431b63f8 {
    const void* p0;
    const void* p8;
    unsigned char b10[0x8];
};
struct Sd_1431b6440 {
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
struct Sd_1431b64f0 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
    const void* p30;
    const void* p38;
    const void* p40;
    unsigned char b48[0x8];
};
struct Sd_1431b6540 {
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
struct Sd_1431b65f0 {
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
struct Sd_1431b6640 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
    const void* p28;
    const void* p30;
    const void* p38;
    const void* p40;
    unsigned char b48[0x8];
};
struct Sd_1431b6690 {
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
struct Sd_1431b6740 {
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
    unsigned char b88[0x8];
};
struct Sd_1431b67d0 {
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
    unsigned char ba8[0x1b8];
    const void* p260;
    const void* p268;
    const void* p270;
    unsigned char b278[0x10];
    const void* p288;
    const void* p290;
    const void* p298;
    unsigned char b2a0[0x10];
    const void* p2b0;
    unsigned char b2b8[0x8];
    const void* p2c0;
    unsigned char b2c8[0x10];
    const void* p2d8;
    const void* p2e0;
    const void* p2e8;
    unsigned char b2f0[0x10];
    const void* p300;
    const void* p308;
    const void* p310;
    unsigned char b318[0x10];
    const void* p328;
    const void* p330;
    const void* p338;
    unsigned char b340[0x10];
    const void* p350;
    unsigned char b358[0x8];
    const void* p360;
    unsigned char b368[0x10];
    const void* p378;
    const void* p380;
    const void* p388;
    unsigned char b390[0x10];
    const void* p3a0;
    unsigned char b3a8[0x8];
    const void* p3b0;
    unsigned char b3b8[0x10];
    const void* p3c8;
    const void* p3d0;
    const void* p3d8;
    unsigned char b3e0[0x10];
    const void* p3f0;
    const void* p3f8;
    const void* p400;
    unsigned char b408[0x10];
    const void* p418;
    const void* p420;
    const void* p428;
    unsigned char b430[0x10];
    const void* p440;
    const void* p448;
    const void* p450;
    unsigned char b458[0x10];
    const void* p468;
    unsigned char b470[0x8];
    const void* p478;
    unsigned char b480[0x10];
    const void* p490;
    const void* p498;
    const void* p4a0;
    unsigned char b4a8[0x10];
    const void* p4b8;
    unsigned char b4c0[0x8];
    const void* p4c8;
    unsigned char b4d0[0x10];
    const void* p4e0;
    unsigned char b4e8[0x8];
    const void* p4f0;
    unsigned char b4f8[0x10];
    const void* p508;
    unsigned char b510[0x8];
    const void* p518;
    unsigned char b520[0x10];
    const void* p530;
    unsigned char b538[0x8];
    const void* p540;
    unsigned char b548[0x10];
    const void* p558;
    unsigned char b560[0x8];
    const void* p568;
    unsigned char b570[0x10];
    const void* p580;
    unsigned char b588[0x8];
    const void* p590;
    unsigned char b598[0x10];
    const void* p5a8;
    unsigned char b5b0[0x8];
    const void* p5b8;
    unsigned char b5c0[0x10];
    const void* p5d0;
    unsigned char b5d8[0x8];
    const void* p5e0;
    unsigned char b5e8[0x10];
    const void* p5f8;
    unsigned char b600[0x8];
    const void* p608;
    unsigned char b610[0x10];
    const void* p620;
    unsigned char b628[0x8];
    const void* p630;
    unsigned char b638[0x10];
    const void* p648;
    unsigned char b650[0x8];
    const void* p658;
    unsigned char b660[0x10];
    const void* p670;
    unsigned char b678[0x8];
    const void* p680;
    unsigned char b688[0x10];
    const void* p698;
    unsigned char b6a0[0x8];
    const void* p6a8;
    unsigned char b6b0[0x10];
    const void* p6c0;
    unsigned char b6c8[0x8];
    const void* p6d0;
    unsigned char b6d8[0x10];
    const void* p6e8;
    const void* p6f0;
    const void* p6f8;
    unsigned char b700[0x10];
    const void* p710;
    unsigned char b718[0x8];
    const void* p720;
    unsigned char b728[0x10];
    const void* p738;
    const void* p740;
    const void* p748;
    unsigned char b750[0x10];
    const void* p760;
    const void* p768;
    const void* p770;
    unsigned char b778[0x10];
    const void* p788;
    unsigned char b790[0x8];
    const void* p798;
    unsigned char b7a0[0x10];
    const void* p7b0;
    const void* p7b8;
    const void* p7c0;
    unsigned char b7c8[0x10];
    const void* p7d8;
    unsigned char b7e0[0x8];
    const void* p7e8;
    unsigned char b7f0[0x10];
    const void* p800;
    const void* p808;
    const void* p810;
    unsigned char b818[0x10];
    const void* p828;
    unsigned char b830[0x8];
    const void* p838;
    unsigned char b840[0x10];
    const void* p850;
    const void* p858;
    const void* p860;
    unsigned char b868[0x10];
    const void* p878;
    unsigned char b880[0x8];
    const void* p888;
    unsigned char b890[0x10];
    const void* p8a0;
    const void* p8a8;
    const void* p8b0;
    unsigned char b8b8[0x10];
    const void* p8c8;
    unsigned char b8d0[0x8];
    const void* p8d8;
    unsigned char b8e0[0x10];
    const void* p8f0;
    unsigned char b8f8[0x8];
    const void* p900;
    unsigned char b908[0x10];
    const void* p918;
    unsigned char b920[0x8];
    const void* p928;
    unsigned char b930[0x10];
    const void* p940;
    unsigned char b948[0x8];
    const void* p950;
    unsigned char b958[0x10];
    const void* p968;
    unsigned char b970[0x8];
    const void* p978;
    unsigned char b980[0x10];
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
struct Sd_1431b71b0 {
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
struct Sd_1431b7260 {
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
struct Sd_1431b7360 {
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
};
struct Sd_1431b7858 {
    const void* p0;
    const void* p8;
    const void* p10;
    const void* p18;
    const void* p20;
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

extern Sd_1431b67d0 DAT_1431b67d0;
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
    DAT_140002e40,
    DAT_140002d90,
    DAT_140002da0,
    DAT_140002930,
    DAT_140002db0,
    DAT_140002950,
    DAT_140002dc0,
    DAT_140002dd0,
    DAT_140002de0,
    DAT_140002df0,
    DAT_140002960,
    DAT_140002e00,
    DAT_140002e10,
    DAT_140002e20,
    DAT_140002980,
    {
        0x73, 0x65, 0x74, 0x42, 0x75, 0x66, 0x66, 0x65, 0x72, 0x54, 0x69, 0x6d, 0x65, 0x00, 0x00, 0x00,
        0x70, 0x6c, 0x61, 0x79, 0x00, 0x00, 0x00, 0x00, 0x70, 0x61, 0x75, 0x73, 0x65, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
};
// 0x1431b4d80
alignas(16) Sd_1431b4d80 DAT_1431b4d80 = {
    "close",
    DAT_1400047a0,
    "pause",
    DAT_140004810,
    "play",
    DAT_14000c9f0,
    "setBufferTime",
    DAT_140004880,
    "seek",
    DAT_140005780,
    {0},
};
// 0x1431b5300
alignas(16) Sd_1431b5300 DAT_1431b5300 = {
    DAT_14000a010,
    {0},
};
// 0x1431b5310
alignas(16) Sd_1431b5310 DAT_1431b5310 = {
    DAT_14000a020,
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
void* PTR_s_attachVideo_1431b5800 = (void*)"attachVideo";       // 0x1431b5800
// 0x1431b5b40
alignas(16) Sd_1431b5b40 DAT_1431b5b40 = {
    DAT_14000e710,
    DAT_14000e7b0,
    DAT_14000e800,
    DAT_14000e7a0,
    DAT_14000e810,
    DAT_14000e730,
    DAT_14000e750,
    DAT_14000e720,
    DAT_14000e740,
    DAT_14000e6e0,
    DAT_14000e700,
    DAT_14000e7f0,
    DAT_14000e790,
    DAT_14000e820,
    DAT_14000e770,
    DAT_14000e6d0,
    DAT_14000e7e0,
    DAT_14000e6f0,
    DAT_14000e830,
    DAT_14000e7d0,
    DAT_14000e780,
    DAT_14000e7c0,
    DAT_14000e760,
    {0},
};
// 0x1431b5c00
alignas(16) Sd_1431b5c00 DAT_1431b5c00 = {
    DAT_14000e6c0,
    DAT_14000e370,
    DAT_14000e500,
    DAT_14000e8f0,
    DAT_14000e9f0,
    DAT_1429448c0,
    DAT_1429386e0,
    DAT_142988930,
    DAT_142994660,
    DAT_14295d840,
    DAT_14000e410,
    DAT_14000e470,
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
    DAT_14000e8a0,
    DAT_14000e520,
    DAT_14000e530,
    DAT_14000e540,
    DAT_14000e550,
    DAT_14000e560,
    DAT_14000e570,
    DAT_14000e600,
    DAT_14000e580,
    DAT_14000e590,
    DAT_14000e5d0,
    DAT_14000e5e0,
    DAT_14000e510,
    DAT_14000e620,
    DAT_14000e610,
    DAT_14000e630,
    DAT_14000e640,
    DAT_14000e650,
    DAT_14000e670,
    DAT_14000e680,
    DAT_14000e690,
    DAT_14000e6a0,
    DAT_14000e6b0,
    DAT_14000e380,
    DAT_14294afb0,
    DAT_14000e890,
    DAT_14000e880,
    DAT_14000e3e0,
    DAT_14000e3f0,
    DAT_14000e400,
    DAT_142949400,
    DAT_1429493c0,
    DAT_142956b10,
    DAT_142949860,
    DAT_14000d320,
    DAT_14298ab80,
    DAT_142955080,
    DAT_14000e4d0,
    DAT_142940160,
    DAT_1429413c0,
    DAT_14293ff70,
};
void* PTR_LAB_1431b5e18 = (void*)(const void*)&FUN_14000ebd0;   // 0x1431b5e18
// 0x1431b5e20
alignas(16) Sd_1431b5e20 DAT_1431b5e20 = {
    DAT_14000e1a0,
    DAT_14000dbc0,
    (const void*)&FUN_14000ec40,
    DAT_14298cc70,
    DAT_142956ca0,
    DAT_14000d710,
    DAT_14000db10,
    DAT_14000daa0,
    DAT_140007e00,
    {0},
};
// 0x1431b5e70
alignas(16) Sd_1431b5e70 DAT_1431b5e70 = {
    (const void*)&FUN_14000ebc0,
    DAT_140007dc0,
    DAT_14000d6e0,
    DAT_1429867f0,
    DAT_14000d6f0,
    DAT_142944950,
    DAT_1429388e0,
    DAT_1429889c0,
    DAT_1429947f0,
    DAT_14295d970,
    DAT_142988bb0,
    DAT_14000d760,
    DAT_142991170,
    DAT_140007ba0,
    DAT_140007ff0,
    DAT_140007d90,
    DAT_14000d730,
    DAT_14000d700,
    DAT_1429623a0,
    DAT_142994c50,
    DAT_142992780,
    {0},
};
// 0x1431b5f20
alignas(16) Sd_1431b5f20 DAT_1431b5f20 = {
    DAT_1429411f0,
    DAT_142942e70,
    (const void*)&FUN_14000ed20,
    DAT_14298cc70,
    DAT_142956ca0,
    DAT_140007dd0,
    DAT_140007df0,
    DAT_140007de0,
    DAT_140007e00,
    DAT_14294ab50,
    DAT_142962bb0,
    DAT_14000ce90,
    DAT_142965510,
    DAT_14000cea0,
    DAT_14000ce80,
    (const void*)&FUN_14000e0c0,
    DAT_14000ceb0,
    {0},
};
// 0x1431b5fb0
alignas(16) Sd_1431b5fb0 DAT_1431b5fb0 = {
    (const void*)&FUN_14000ed10,
    DAT_140007dc0,
    DAT_14000ce70,
    DAT_1429867f0,
    DAT_14294f7d0,
    DAT_142944950,
    DAT_1429388e0,
    DAT_1429889c0,
    DAT_1429947f0,
    DAT_14295d970,
    DAT_142988bb0,
    DAT_142953280,
    DAT_142991140,
    DAT_140007ba0,
    DAT_140007ff0,
    DAT_140007d90,
    DAT_140007da0,
    DAT_140007db0,
    DAT_1429623a0,
    DAT_142994c50,
    DAT_142992780,
    {0},
};
// 0x1431b6060
alignas(16) Sd_1431b6060 DAT_1431b6060 = {
    (const void*)&FUN_140010530,
    (const void*)&FUN_140011610,
    DAT_1425f2210,
    DAT_1425f5010,
    DAT_1425f2140,
    DAT_1425f4d70,
    DAT_1425f2600,
    DAT_1425f56c0,
    DAT_1425f29a0,
    DAT_1425f5e70,
    DAT_1425f7af0,
    DAT_1425f75c0,
    DAT_142510d40,
    DAT_1425f1ca0,
    DAT_1425265f0,
    DAT_14250d620,
    DAT_142528d90,
    DAT_1425f64c0,
    DAT_1425f2cd0,
    DAT_1425f69f0,
    DAT_1425f2e20,
    DAT_1425f6f20,
    DAT_1425f2f70,
    DAT_1425f6760,
    DAT_1425f2db0,
    DAT_1425f6c90,
    DAT_1425f2f00,
    DAT_1425f6fe0,
    DAT_1425f2fe0,
    DAT_1425f57a0,
    DAT_1425f2760,
    DAT_1425f6690,
    DAT_1425f2d40,
    DAT_1425f6bc0,
    DAT_1425f2e90,
    DAT_1425f40a0,
    DAT_1425f1d50,
    DAT_1425f41f0,
    DAT_1425f1db0,
    DAT_1425f5530,
    DAT_1425f25c0,
    DAT_1425f6130,
    DAT_1425f2a40,
    DAT_1425f4460,
    DAT_1425f1f60,
    DAT_1425f22e0,
    DAT_1425f23e0,
    DAT_142506ef0,
    DAT_1425084c0,
    DAT_1425f3de0,
    DAT_1425f41b0,
    DAT_1425f1d70,
    DAT_14252b580,
    DAT_142510a30,
    DAT_142504840,
    (const void*)&FUN_140010200,
    DAT_14250d6f0,
    DAT_14251cab0,
    DAT_14250f760,
    (const void*)&FUN_140010130,
    DAT_1425f8550,
    DAT_142509da0,
    DAT_14250f850,
    DAT_1425f8540,
    DAT_142525c90,
    DAT_1424eb250,
    DAT_1425f3980,
    DAT_1425f8870,
    DAT_1425f8940,
    DAT_1425f8880,
    DAT_1425f2040,
    DAT_1425f3390,
    DAT_142515190,
    DAT_142529f50,
    DAT_14250ee20,
    (const void*)&FUN_140010140,
    DAT_1425f1ae0,
    DAT_142509990,
    DAT_1424f74d0,
    DAT_1425f85e0,
    DAT_1425f8630,
    DAT_1425f8760,
    DAT_1425f86d0,
    DAT_1425f8690,
    DAT_1425f88e0,
    DAT_14251a100,
    DAT_14251a820,
    DAT_142509d40,
    DAT_1425f7fc0,
    DAT_1425287f0,
    DAT_14251a3a0,
    DAT_142518990,
    DAT_14251ac30,
    DAT_14251f560,
    DAT_14251ac20,
    DAT_14251f550,
    DAT_142526720,
    DAT_1424eeca0,
    DAT_14251f5c0,
    DAT_14251f5d0,
    DAT_14251f540,
    DAT_1425084d0,
    DAT_14250b360,
    DAT_142509dc0,
    DAT_142510d10,
    DAT_14250b3a0,
    DAT_1424fe610,
    DAT_142510e60,
    DAT_142528800,
    DAT_14250cc20,
    DAT_1425f8480,
    DAT_1425227d0,
    DAT_14252c9c0,
    DAT_14252c9d0,
    DAT_14252c9e0,
};
// 0x1431b63f8
alignas(8) Sd_1431b63f8 DAT_1431b63f8 = {
    (const void*)&FUN_140010180,
    DAT_1425f33e0,
    {
        0x63, 0x6f, 0x6e, 0x6e, 0x65, 0x63, 0x74, 0x00,
    },
};
void* PTR_s_connect_1431b6410 = (void*)"connect";               // 0x1431b6410
void* PTR_LAB_1431b6430 = (void*)(const void*)&FUN_140011c80;   // 0x1431b6430
// 0x1431b6440
alignas(16) Sd_1431b6440 DAT_1431b6440 = {
    (const void*)&FUN_140011c70,
    DAT_140007dc0,
    (const void*)&FUN_140011b80,
    DAT_1429867f0,
    (const void*)&FUN_140011b90,
    DAT_142944950,
    DAT_1429388e0,
    DAT_1429889c0,
    DAT_1429947f0,
    DAT_14295d970,
    DAT_142988bb0,
    (const void*)&FUN_140011de0,
    DAT_142991170,
    DAT_140007ba0,
    DAT_140007ff0,
    DAT_140007d90,
    (const void*)&FUN_140011bd0,
    (const void*)&FUN_140011ba0,
    DAT_1429623a0,
    DAT_142994c50,
    DAT_142992780,
    {0},
};
// 0x1431b64f0
alignas(16) Sd_1431b64f0 DAT_1431b64f0 = {
    (const void*)&FUN_140012400,
    (const void*)&FUN_140011d90,
    (const void*)&FUN_140011c00,
    DAT_14298cc70,
    DAT_142956ca0,
    (const void*)&FUN_140011bb0,
    DAT_140007df0,
    DAT_140007de0,
    DAT_140007e00,
    {0},
};
// 0x1431b6540
alignas(16) Sd_1431b6540 DAT_1431b6540 = {
    (const void*)&FUN_140011d00,
    DAT_140007dc0,
    (const void*)&FUN_140011b80,
    DAT_1429867f0,
    DAT_14294f7d0,
    DAT_142944950,
    DAT_1429388e0,
    DAT_1429889c0,
    DAT_1429947f0,
    DAT_14295d970,
    DAT_142988bb0,
    DAT_142953280,
    DAT_142991170,
    DAT_140007ba0,
    DAT_140007ff0,
    DAT_140007d90,
    DAT_140007da0,
    DAT_140007db0,
    DAT_1429623a0,
    DAT_142994c50,
    DAT_142992780,
    {0},
};
// 0x1431b65f0
alignas(16) Sd_1431b65f0 DAT_1431b65f0 = {
    DAT_1429411f0,
    DAT_142942e70,
    (const void*)&FUN_140011d10,
    DAT_14298cc70,
    DAT_142956ca0,
    DAT_140007dd0,
    DAT_140007df0,
    DAT_140007de0,
    DAT_140007e00,
};
void* PTR_LAB_1431b6638 = (void*)(const void*)&FUN_140012590;   // 0x1431b6638
// 0x1431b6640
alignas(16) Sd_1431b6640 DAT_1431b6640 = {
    (const void*)&FUN_140012400,
    (const void*)&FUN_140011d90,
    (const void*)&FUN_1400125e0,
    DAT_14298cc70,
    DAT_142956ca0,
    (const void*)&FUN_140011bb0,
    DAT_140007df0,
    DAT_140007de0,
    DAT_140007e00,
    {0},
};
// 0x1431b6690
alignas(16) Sd_1431b6690 DAT_1431b6690 = {
    (const void*)&FUN_140012580,
    DAT_140007dc0,
    (const void*)&FUN_140011b80,
    DAT_1429867f0,
    (const void*)&FUN_140011b90,
    DAT_142944950,
    DAT_1429388e0,
    DAT_1429889c0,
    DAT_1429947f0,
    DAT_14295d970,
    DAT_142988bb0,
    (const void*)&FUN_140011de0,
    DAT_142991170,
    DAT_140007ba0,
    DAT_140007ff0,
    DAT_140007d90,
    (const void*)&FUN_140011bd0,
    (const void*)&FUN_140011ba0,
    DAT_1429623a0,
    DAT_142994c50,
    DAT_142992780,
    {0},
};
// 0x1431b6740
alignas(16) Sd_1431b6740 DAT_1431b6740 = {
    DAT_1429411f0,
    DAT_142942e70,
    (const void*)&FUN_1400126b0,
    DAT_14298cc70,
    DAT_142956ca0,
    DAT_140007dd0,
    DAT_140007df0,
    DAT_140007de0,
    DAT_140007e00,
    DAT_14294ab50,
    DAT_142962bb0,
    DAT_14000ce90,
    DAT_142965510,
    DAT_14000cea0,
    DAT_14000ce80,
    (const void*)&FUN_140011d50,
    DAT_14000ceb0,
    {0},
};
// 0x1431b67d0
alignas(16) Sd_1431b67d0 DAT_1431b67d0 = {
    (const void*)&FUN_1400126a0,
    DAT_140007dc0,
    DAT_14000ce70,
    DAT_1429867f0,
    DAT_14294f7d0,
    DAT_142944950,
    DAT_1429388e0,
    DAT_1429889c0,
    DAT_1429947f0,
    DAT_14295d970,
    DAT_142988bb0,
    DAT_142953280,
    DAT_142991140,
    DAT_140007ba0,
    DAT_140007ff0,
    DAT_140007d90,
    DAT_140007da0,
    DAT_140007db0,
    DAT_1429623a0,
    DAT_142994c50,
    DAT_142992780,
    {
        0x66, 0x6c, 0x61, 0x73, 0x68, 0x2e, 0x6e, 0x65, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x4e, 0x65, 0x74, 0x53, 0x74, 0x72, 0x65, 0x61, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x72, 0x65, 0x73, 0x65, 0x74, 0x44, 0x52, 0x4d, 0x56, 0x6f, 0x75, 0x63, 0x68, 0x65, 0x72, 0x73,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6f, 0x70, 0x65, 0x6e, 0x54, 0x69, 0x6d, 0x65,
        0x6f, 0x75, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x4f, 0x66,
        0x46, 0x72, 0x61, 0x6d, 0x65, 0x50, 0x6f, 0x6f, 0x6c, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x72, 0x65, 0x6c, 0x6f, 0x61, 0x64, 0x54, 0x68, 0x72, 0x65, 0x73, 0x68, 0x6f, 0x6c, 0x64, 0x54,
        0x69, 0x6d, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x73, 0x75, 0x62, 0x53, 0x6f, 0x75, 0x6e, 0x64,
        0x54, 0x72, 0x61, 0x6e, 0x73, 0x66, 0x6f, 0x72, 0x6d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x74, 0x6f, 0x67, 0x67, 0x6c, 0x65, 0x50, 0x61, 0x75, 0x73, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x73, 0x65, 0x74, 0x44, 0x52, 0x4d, 0x41, 0x75, 0x74, 0x68, 0x65, 0x6e, 0x74, 0x69, 0x63, 0x61,
        0x74, 0x69, 0x6f, 0x6e, 0x43, 0x72, 0x65, 0x64, 0x65, 0x6e, 0x74, 0x69, 0x61, 0x6c, 0x73, 0x00,
        0x73, 0x65, 0x6e, 0x64, 0x00, 0x00, 0x00, 0x00, 0x72, 0x65, 0x63, 0x65, 0x69, 0x76, 0x65, 0x56,
        0x69, 0x64, 0x65, 0x6f, 0x46, 0x50, 0x53, 0x00, 0x72, 0x65, 0x63, 0x65, 0x69, 0x76, 0x65, 0x56,
        0x69, 0x64, 0x65, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x72, 0x65, 0x63, 0x65, 0x69, 0x76, 0x65, 0x41,
        0x75, 0x64, 0x69, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x70, 0x75, 0x62, 0x6c, 0x69, 0x73, 0x68, 0x00,
        0x61, 0x74, 0x74, 0x61, 0x63, 0x68, 0x43, 0x61, 0x6d, 0x65, 0x72, 0x61, 0x00, 0x00, 0x00, 0x00,
        0x61, 0x74, 0x74, 0x61, 0x63, 0x68, 0x41, 0x75, 0x64, 0x69, 0x6f, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x73, 0x6f, 0x75, 0x6e, 0x64, 0x54, 0x72, 0x61, 0x6e, 0x73, 0x66, 0x6f, 0x72, 0x6d, 0x00, 0x00,
        0x6f, 0x62, 0x6a, 0x65, 0x63, 0x74, 0x45, 0x6e, 0x63, 0x6f, 0x64, 0x69, 0x6e, 0x67, 0x00, 0x00,
        0x6c, 0x69, 0x76, 0x65, 0x44, 0x65, 0x6c, 0x61, 0x79, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x63, 0x75, 0x72, 0x72, 0x65, 0x6e, 0x74, 0x46, 0x50, 0x53, 0x00, 0x00, 0x63, 0x6c, 0x69, 0x65,
        0x6e, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x63, 0x68, 0x65, 0x63, 0x6b, 0x50, 0x6f, 0x6c,
        0x69, 0x63, 0x79, 0x46, 0x69, 0x6c, 0x65, 0x00, 0x62, 0x79, 0x74, 0x65, 0x73, 0x54, 0x6f, 0x74,
        0x61, 0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x79, 0x74, 0x65, 0x73, 0x4c, 0x6f, 0x61,
        0x64, 0x65, 0x64, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x75, 0x66, 0x66, 0x65, 0x72, 0x54, 0x69,
        0x6d, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x62, 0x75, 0x66, 0x66, 0x65, 0x72, 0x4c, 0x65,
        0x6e, 0x67, 0x74, 0x68, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015d20,
    DAT_14313db20,
    "bufferLength",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015da0,
    DAT_14313db20,
    "bufferTime",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015e20,
    {0},
    "bufferTime",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015eb0,
    DAT_14313dad0,
    "bytesLoaded",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015f20,
    DAT_14313dad0,
    "bytesTotal",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140015f90,
    DAT_14313da30,
    "checkPolicyFile",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016000,
    {0},
    "checkPolicyFile",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140019d70,
    DAT_14313d990,
    "client",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016060,
    {0},
    "client",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016100,
    DAT_14313db20,
    "currentFPS",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016180,
    DAT_14313db20,
    "liveDelay",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016200,
    DAT_14313dad0,
    "objectEncoding",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140019e20,
    DAT_143177ac0,
    "soundTransform",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016fd0,
    {0},
    "soundTransform",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016270,
    DAT_14313db20,
    "time",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140017020,
    {0},
    "attachAudio",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140017470,
    {0},
    "attachCamera",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400162f0,
    {0},
    "close",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400133e0,
    {0},
    "pause",
    {0},
    (const void*)&FUN_140013230,
    {0},
    "play",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140017520,
    {0},
    "publish",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016350,
    {0},
    "receiveAudio",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400163b0,
    {0},
    "receiveVideo",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016410,
    {0},
    "receiveVideoFPS",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140013400,
    {0},
    "resume",
    {0},
    (const void*)&FUN_1400164a0,
    {0},
    "seek",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140013250,
    {0},
    "send",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140017670,
    {0},
    "setDRMAuthenticationCredentials",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140013420,
    {0},
    "togglePause",
    {0},
    (const void*)&FUN_140016530,
    DAT_14313da30,
    "loop",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400165a0,
    {0},
    "loop",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016600,
    DAT_14313db20,
    "currentFrame",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016680,
    DAT_14313db20,
    "audioTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016700,
    {0},
    "audioTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016790,
    DAT_14313db20,
    "subAudioTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016810,
    {0},
    "subAudioTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400168a0,
    DAT_14313db20,
    "voiceTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016920,
    {0},
    "voiceTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_1400169b0,
    DAT_14313db20,
    "subtitleTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016a30,
    {0},
    "subtitleTrack",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140019ed0,
    DAT_143177ac0,
    "subSoundTransform",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140017070,
    {0},
    "subSoundTransform",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016ac0,
    {0},
    "reloadThresholdTime",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016b50,
    {0},
    "numberOfFramePools",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140016be0,
    {0},
    "openTimeout",
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const void*)&FUN_140013440,
    {0},
    "resetDRMVouchers",
    {0},
};
// 0x1431b7160
alignas(16) Sd_1431b7160 DAT_1431b7160 = {
    {
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    "NetStream",
    "flash.net",
    DAT_143150b00,
    DAT_140019bd0,
    {
        0x01, 0x00, 0x2d, 0x00, 0x00, 0x00, 0x00, 0x00,
    },
    (const unsigned char*)&DAT_1431b67d0 + 0x968,
    {0},
    (const unsigned char*)&DAT_1431b67d0 + 0x260,
    {0},
};
// 0x1431b71b0
alignas(16) Sd_1431b71b0 DAT_1431b71b0 = {
    DAT_142503fa0,
    DAT_1423df5a0,
    (const void*)&FUN_140012ef0,
    DAT_1423df460,
    (const void*)&FUN_140014a80,
    DAT_1423df420,
    DAT_142514320,
    DAT_14250bbd0,
    DAT_14250d570,
    DAT_142509d30,
    DAT_142509ca0,
    DAT_14252c4e0,
    DAT_14250a5b0,
    DAT_1425117e0,
    (const void*)&FUN_1400155d0,
    DAT_1424e42a0,
    DAT_14252e480,
};
// 0x1431b7260
alignas(16) Sd_1431b7260 DAT_1431b7260 = {
    DAT_142503800,
    DAT_1423df5b0,
    (const void*)&FUN_140012f40,
    DAT_1423df430,
    (const void*)&FUN_140014b10,
    DAT_1423df420,
    DAT_142528a50,
    DAT_14250cc60,
    DAT_142509a80,
    DAT_1424f4a40,
    DAT_1424ee6f0,
    DAT_1424e4290,
    DAT_1424f0610,
    DAT_1423df590,
    DAT_1424e8060,
    DAT_1423df580,
    DAT_14250c010,
    DAT_14250be40,
    DAT_14250c060,
    DAT_142500e50,
    DAT_142512620,
    DAT_14251cfc0,
    DAT_14251ced0,
    DAT_1424eb770,
    DAT_142511810,
    DAT_142516630,
};
// 0x1431b7360
alignas(16) Sd_1431b7360 DAT_1431b7360 = {
    (const void*)&FUN_140012e10,
    DAT_1423df5b0,
    (const void*)&FUN_1400141a0,
    DAT_1423df430,
    (const void*)&FUN_140015590,
    DAT_1423df420,
    DAT_142528a50,
    DAT_14250cc60,
    DAT_142509a80,
    DAT_1424f4a40,
    DAT_1424ee7f0,
    (const void*)&FUN_140015c40,
    DAT_1424f0700,
    DAT_1423df590,
    DAT_1424e8060,
    DAT_1423df580,
    DAT_14250c010,
    DAT_14250be40,
    DAT_14250c060,
    DAT_142500e50,
    DAT_142512620,
};
// 0x1431b7858
alignas(8) Sd_1431b7858 DAT_1431b7858 = {
    (const void*)&FUN_140015c00,
    (const void*)&FUN_140019890,
    (const void*)&FUN_1400182f0,
    (const void*)&FUN_140018930,
    (const void*)&FUN_140014900,
};
// 0x1431b7900
alignas(16) Sd_1431b7900 DAT_1431b7900 = {
    DAT_142503f50,
    DAT_1423df5a0,
    DAT_140019af0,
    DAT_1423df4a0,
    DAT_140019b60,
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
    DAT_14001af10,
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
    DAT_14001a040,
    DAT_142443380,
    DAT_14001a2f0,
    DAT_1423df420,
    DAT_142528a50,
    DAT_14250cc60,
    DAT_142509a80,
    DAT_1424f4a40,
    DAT_1424ee7f0,
    DAT_14001a760,
    DAT_1424f0700,
    DAT_14001a800,
    DAT_1424e8060,
    DAT_1423df580,
    DAT_14250c010,
    DAT_14250be40,
    DAT_14250c060,
    DAT_142500e50,
    DAT_142512620,
    DAT_14001a470,
};
// 0x1431b7c70
alignas(16) Sd_1431b7c70 DAT_1431b7c70 = {
    DAT_142503fa0,
    DAT_1423df5a0,
    DAT_14001a0b0,
    DAT_1423df460,
    DAT_14001a5c0,
    DAT_1423df420,
    DAT_142514320,
    DAT_14250bbd0,
    DAT_14250d570,
    DAT_142509d30,
    DAT_142509ca0,
    DAT_14252c4e0,
    DAT_14250a5b0,
    DAT_1425117e0,
    DAT_14001a860,
    DAT_1424e42a0,
    DAT_14252e480,
};
// 0x1431b7d50
alignas(16) Sd_1431b7d50 DAT_1431b7d50 = {
    DAT_142503f50,
    DAT_1423df5a0,
    DAT_14001ae30,
    DAT_1423df4a0,
    DAT_14001aea0,
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
    DAT_14001b1e0,
    DAT_14001b2a0,
    DAT_14001b2c0,
    DAT_14001b280,
    DAT_14001b2d0,
    DAT_14001b200,
    DAT_14001b270,
    DAT_14001b1f0,
    DAT_14001b220,
    DAT_14001b350,
    DAT_14001b1a0,
    DAT_14001b2e0,
    DAT_14001b250,
    DAT_14001b210,
    DAT_14001b330,
    DAT_14001b240,
    DAT_14001b190,
    DAT_14001b290,
    DAT_14001b230,
    DAT_14001b180,
    DAT_14001b380,
    DAT_14001b160,
    DAT_14001b370,
    {0},
};
// 0x1431b7ea0
alignas(16) Sd_1431b7ea0 DAT_1431b7ea0 = {
    DAT_14001b2f0,
    DAT_14001b170,
    DAT_14001b1b0,
    DAT_14001b390,
    DAT_14001b1c0,
    DAT_14001b310,
    DAT_14001b360,
    DAT_14001b300,
    DAT_14001b320,
    DAT_14001b260,
    DAT_14001b2b0,
    DAT_14001b1d0,
    DAT_14001b340,
    DAT_14001b090,
    DAT_14001b0b0,
    DAT_14001b0c0,
    DAT_14001b0d0,
    DAT_14001b0e0,
    DAT_14001b100,
    DAT_14001b110,
    DAT_14001b120,
    DAT_14001b130,
    DAT_14001b140,
    {0},
};
// 0x1431b7f60
alignas(16) Sd_1431b7f60 DAT_1431b7f60 = {
    DAT_14001b3a0,
    DAT_14001afe0,
    DAT_14001b000,
    DAT_14001b010,
    DAT_14001b020,
    DAT_14001b030,
    DAT_14001b0a0,
    DAT_14001b080,
    DAT_14001b040,
    DAT_14001b050,
    DAT_14001b060,
    DAT_14001b070,
    DAT_14001afd0,
    DAT_1423dc0b0,
    DAT_14251ace0,
    DAT_1424f2400,
    DAT_14001aff0,
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
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b5e20@@3PEAXEA=?DAT_1431b5e20@@3USd_1431b5e20@@A")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b5e70@@3PEAXEA=?DAT_1431b5e70@@3USd_1431b5e70@@A")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b5f20@@3PEAXEA=?DAT_1431b5f20@@3USd_1431b5f20@@A")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b5fb0@@3PEAXEA=?DAT_1431b5fb0@@3USd_1431b5fb0@@A")
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b6060@@3PEAXEA=?DAT_1431b6060@@3USd_1431b6060@@A")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b63f8@@3PEAXEA=?DAT_1431b63f8@@3USd_1431b63f8@@A")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b6440@@3PEAXEA=?DAT_1431b6440@@3USd_1431b6440@@A")
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b64f0@@3PEAXEA=?DAT_1431b64f0@@3USd_1431b64f0@@A")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b6540@@3PEAXEA=?DAT_1431b6540@@3USd_1431b6540@@A")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b65f0@@3PEAXEA=?DAT_1431b65f0@@3USd_1431b65f0@@A")
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b6640@@3PEAXEA=?DAT_1431b6640@@3USd_1431b6640@@A")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b6690@@3PEAXEA=?DAT_1431b6690@@3USd_1431b6690@@A")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b6740@@3PEAXEA=?DAT_1431b6740@@3USd_1431b6740@@A")
#pragma comment(linker, "/alternatename:?PTR_LAB_1431b67d0@@3PEAXEA=?DAT_1431b67d0@@3USd_1431b67d0@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7160@@3PAEA=?DAT_1431b7160@@3USd_1431b7160@@A")
#pragma comment(linker, "/alternatename:?DAT_1431b7160@@3PEAXEA=?DAT_1431b7160@@3USd_1431b7160@@A")
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b71b0@@3PEAXEA=?DAT_1431b71b0@@3USd_1431b71b0@@A")
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b7260@@3PEAXEA=?DAT_1431b7260@@3USd_1431b7260@@A")
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b7360@@3PEAXEA=?DAT_1431b7360@@3USd_1431b7360@@A")
#pragma comment(linker, "/alternatename:?PTR_FUN_1431b7858@@3PEAXEA=?DAT_1431b7858@@3USd_1431b7858@@A")
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
#pragma comment(linker, "/alternatename:?DAT_140002930@@3PAEA=?FUN_140002930@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002950@@3PAEA=?FUN_140002950@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002960@@3PAEA=?FUN_140002960@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002980@@3PAEA=?FUN_140002980@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002b00@@3PAEA=?GetSoundChannel@VideoSoundStream@Video@GFx@Scaleform@@UEAAPEAVUnk_VideoSoundChannel@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_140002b30@@3PAEA=?FUN_140002b30@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002bb0@@3PAEA=?FUN_140002bb0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002c10@@3PAEA=?FUN_140002c10@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002cc0@@3PAEA=?FUN_140002cc0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002d20@@3PAEA=?FUN_140002d20@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002d90@@3PAEA=?FUN_140002d90@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002da0@@3PAEA=?FUN_140002da0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002db0@@3PAEA=?FUN_140002db0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002dc0@@3PAEA=?FUN_140002dc0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002dd0@@3PAEA=?FUN_140002dd0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002de0@@3PAEA=?FUN_140002de0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002df0@@3PAEA=?FUN_140002df0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002e00@@3PAEA=?FUN_140002e00@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002e10@@3PAEA=?FUN_140002e10@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002e20@@3PAEA=?FUN_140002e20@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140002e40@@3PAEA=?FUN_140002e40@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1400047a0@@3PAEA=?FUN_1400047a0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140004810@@3PAEA=?FUN_140004810@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140004880@@3PAEA=?FUN_140004880@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140005780@@3PAEA=?FUN_140005780@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140007ba0@@3PAEA=?Set__proto__@Object@AS2@GFx@Scaleform@@UEAAXPEAVASStringContext@234@PEAV1234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140007d90@@3PAEA=?IsSuper@ObjectInterface@AS2@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_140007da0@@3PAEA=?IsBuiltinPrototype@ObjectInterface@AS2@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_140007db0@@3PAEA=?AddInterface@ObjectInterface@AS2@GFx@Scaleform@@UEAAXPEAVASStringContext@234@HPEAVFunctionObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140007dc0@@3PAEA=?GetTextValue@Object@AS2@GFx@Scaleform@@UEBAPEBDPEAVEnvironment@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_140007dd0@@3PAEA=?DoesImplement@Object@AS2@GFx@Scaleform@@UEBA_NPEAVEnvironment@234@PEBV1234@@Z")
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
#pragma comment(linker, "/alternatename:?DAT_14000a010@@3PAEA=?FUN_14000a010@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000a020@@3PAEA=?FUN_14000a020@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000a110@@3PAEA=?GetMemberRaw@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@PEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000a3a0@@3PAEA=?Finalize_GC@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@MEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000a770@@3PAEA=?ExecuteForEachChild_GC@?$Prototype@VNetStream@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@MEBAXPEAV?$RefCountCollector@$0BED@@234@W4OperationGC@?$RefCountBaseGC@$0BED@@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000a880@@3PAEA=?FUN_14000a880@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000c9f0@@3PAEA=?FUN_14000c9f0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000ce70@@3PAEA=?GetObjectType@FunctionObject@AS2@GFx@Scaleform@@UEBA?AW4ObjectType@ObjectInterface@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_14000ce80@@3PAEA=?IsAsFunction@FunctionObject@AS2@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14000ce90@@3PAEA=?IsNull@CFunctionObject@AS2@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14000cea0@@3PAEA=?IsCFunction@CFunctionObject@AS2@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14000ceb0@@3PAEA=?GetNumArgs@CFunctionObject@AS2@GFx@Scaleform@@UEBAHXZ")
#pragma comment(linker, "/alternatename:?DAT_14000d320@@3PAEA=?FUN_14000d320@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000d6e0@@3PAEA=?GetObjectType@VideoObject@AS2@GFx@Scaleform@@UEBA?AW4ObjectType@ObjectInterface@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_14000d6f0@@3PAEA=?GetMember@?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAA_NPEAVEnvironment@234@AEBVASString@34@PEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000d700@@3PAEA=?AddInterface@?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAAXPEAVASStringContext@234@HPEAVFunctionObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000d710@@3PAEA=?DoesImplement@?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEBA_NPEAVEnvironment@234@PEBVObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000d730@@3PAEA=?IsBuiltinPrototype@?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14000d760@@3PAEA=?GetMemberRaw@?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@PEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000daa0@@3PAEA=?GetASCharacter@VideoObject@AS2@GFx@Scaleform@@UEAAPEAVInteractiveObject@34@XZ")
#pragma comment(linker, "/alternatename:?DAT_14000db10@@3PAEA=?GetASCharacter@VideoObject@AS2@GFx@Scaleform@@UEBAPEBVInteractiveObject@34@XZ")
#pragma comment(linker, "/alternatename:?DAT_14000dbc0@@3PAEA=?Finalize_GC@?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@MEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e1a0@@3PAEA=?ExecuteForEachChild_GC@?$Prototype@VVideoObject@AS2@GFx@Scaleform@@VEnvironment@234@@AS2@GFx@Scaleform@@MEBAXPEAV?$RefCountCollector@$0BED@@234@W4OperationGC@?$RefCountBaseGC@$0BED@@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e370@@3PAEA=?GetTextValue@ObjectInterface@AS2@GFx@Scaleform@@UEBAPEBDPEAVEnvironment@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e380@@3PAEA=?Bind@AvmCharacter@AS2@GFx@Scaleform@@UEAAXPEAVDisplayObject@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e3e0@@3PAEA=?GetRelativeTarget@AvmCharacter@AS2@GFx@Scaleform@@UEAAPEAVInteractiveObject@34@AEBVASString@34@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e3f0@@3PAEA=?ReplaceChildCharacterOnLoad@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVInteractiveObject@34@0@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e400@@3PAEA=?ReplaceChildCharacter@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVInteractiveObject@34@0@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e410@@3PAEA=?FUN_14000e410@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e470@@3PAEA=?FUN_14000e470@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e4d0@@3PAEA=?ExecuteBuffer@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVActionBuffer@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e500@@3PAEA=?FUN_14000e500@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e510@@3PAEA=?FUN_14000e510@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e520@@3PAEA=?FUN_14000e520@AS2@GFx@Scaleform@@YA_K_K@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e530@@3PAEA=?FUN_14000e530@AS2@GFx@Scaleform@@YA_KXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e540@@3PAEA=?FUN_14000e540@AS2@GFx@Scaleform@@YA_KXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e550@@3PAEA=?FUN_14000e550@AS2@GFx@Scaleform@@YA_KXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e560@@3PAEA=?FUN_14000e560@AS2@GFx@Scaleform@@YA_KXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e570@@3PAEA=?FUN_14000e570@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e580@@3PAEA=?FUN_14000e580@AS2@GFx@Scaleform@@YA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e590@@3PAEA=?FUN_14000e590@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e5d0@@3PAEA=?FUN_14000e5d0@AS2@GFx@Scaleform@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e5e0@@3PAEA=?AvmVideoCharacter_OnUnloading@AS2@GFx@Scaleform@@YA_NPEAVAvmCharacter@123@@Z")
#pragma comment(linker, "/alternatename:?DAT_14000e600@@3PAEA=?FUN_14000e600@AS2@GFx@Scaleform@@YA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e610@@3PAEA=?FUN_14000e610@AS2@GFx@Scaleform@@YA_KXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e620@@3PAEA=?FUN_14000e620@AS2@GFx@Scaleform@@YA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e630@@3PAEA=?FUN_14000e630@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e640@@3PAEA=?FUN_14000e640@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e650@@3PAEA=?FUN_14000e650@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e670@@3PAEA=?FUN_14000e670@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e680@@3PAEA=?FUN_14000e680@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e690@@3PAEA=?FUN_14000e690@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e6a0@@3PAEA=?FUN_14000e6a0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e6b0@@3PAEA=?FUN_14000e6b0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e6c0@@3PAEA=?FUN_14000e6c0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e6d0@@3PAEA=?FUN_14000e6d0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e6e0@@3PAEA=?FUN_14000e6e0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e6f0@@3PAEA=?FUN_14000e6f0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e700@@3PAEA=?FUN_14000e700@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e710@@3PAEA=?FUN_14000e710@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e720@@3PAEA=?FUN_14000e720@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e730@@3PAEA=?FUN_14000e730@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e740@@3PAEA=?FUN_14000e740@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e750@@3PAEA=?FUN_14000e750@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e760@@3PAEA=?FUN_14000e760@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e770@@3PAEA=?FUN_14000e770@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e780@@3PAEA=?FUN_14000e780@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e790@@3PAEA=?FUN_14000e790@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e7a0@@3PAEA=?FUN_14000e7a0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e7b0@@3PAEA=?FUN_14000e7b0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e7c0@@3PAEA=?FUN_14000e7c0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e7d0@@3PAEA=?FUN_14000e7d0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e7e0@@3PAEA=?FUN_14000e7e0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e7f0@@3PAEA=?FUN_14000e7f0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e800@@3PAEA=?FUN_14000e800@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e810@@3PAEA=?FUN_14000e810@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e820@@3PAEA=?FUN_14000e820@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e830@@3PAEA=?FUN_14000e830@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e880@@3PAEA=?FUN_14000e880@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e890@@3PAEA=?FUN_14000e890@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e8a0@@3PAEA=?FUN_14000e8a0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e8f0@@3PAEA=?FUN_14000e8f0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14000e9f0@@3PAEA=?FUN_14000e9f0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140019af0@@3PAEA=?FUN_140019af0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140019b60@@3PAEA=?FUN_140019b60@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_140019bd0@@3PAEA=?FUN_140019bd0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001a040@@3PAEA=?FUN_14001a040@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001a0b0@@3PAEA=?FUN_14001a0b0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001a2f0@@3PAEA=?FUN_14001a2f0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001a470@@3PAEA=?FUN_14001a470@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001a5c0@@3PAEA=?FUN_14001a5c0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001a760@@3PAEA=?FUN_14001a760@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001a800@@3PAEA=?FUN_14001a800@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001a860@@3PAEA=?FUN_14001a860@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001ae30@@3PAEA=?FUN_14001ae30@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001aea0@@3PAEA=?FUN_14001aea0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001af10@@3PAEA=?FUN_14001af10@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001afd0@@3PAEA=?FUN_14001afd0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001afe0@@3PAEA=?FUN_14001afe0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001aff0@@3PAEA=?FUN_14001aff0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b000@@3PAEA=?FUN_14001b000@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b010@@3PAEA=?FUN_14001b010@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b020@@3PAEA=?FUN_14001b020@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b030@@3PAEA=?FUN_14001b030@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b040@@3PAEA=?FUN_14001b040@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b050@@3PAEA=?FUN_14001b050@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b060@@3PAEA=?FUN_14001b060@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b070@@3PAEA=?FUN_14001b070@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b080@@3PAEA=?FUN_14001b080@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b090@@3PAEA=?FUN_14001b090@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b0a0@@3PAEA=?FUN_14001b0a0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b0b0@@3PAEA=?FUN_14001b0b0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b0c0@@3PAEA=?FUN_14001b0c0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b0d0@@3PAEA=?FUN_14001b0d0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b0e0@@3PAEA=?FUN_14001b0e0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b100@@3PAEA=?FUN_14001b100@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b110@@3PAEA=?FUN_14001b110@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b120@@3PAEA=?FUN_14001b120@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b130@@3PAEA=?FUN_14001b130@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b140@@3PAEA=?FUN_14001b140@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b160@@3PAEA=?FUN_14001b160@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b170@@3PAEA=?FUN_14001b170@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b180@@3PAEA=?FUN_14001b180@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b190@@3PAEA=?FUN_14001b190@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b1a0@@3PAEA=?FUN_14001b1a0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b1b0@@3PAEA=?FUN_14001b1b0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b1c0@@3PAEA=?FUN_14001b1c0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b1d0@@3PAEA=?FUN_14001b1d0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b1e0@@3PAEA=?FUN_14001b1e0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b1f0@@3PAEA=?FUN_14001b1f0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b200@@3PAEA=?FUN_14001b200@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b210@@3PAEA=?FUN_14001b210@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b220@@3PAEA=?FUN_14001b220@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b230@@3PAEA=?FUN_14001b230@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b240@@3PAEA=?FUN_14001b240@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b250@@3PAEA=?FUN_14001b250@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b260@@3PAEA=?FUN_14001b260@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b270@@3PAEA=?FUN_14001b270@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b280@@3PAEA=?FUN_14001b280@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b290@@3PAEA=?FUN_14001b290@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b2a0@@3PAEA=?FUN_14001b2a0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b2b0@@3PAEA=?FUN_14001b2b0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b2c0@@3PAEA=?FUN_14001b2c0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b2d0@@3PAEA=?FUN_14001b2d0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b2e0@@3PAEA=?FUN_14001b2e0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b2f0@@3PAEA=?FUN_14001b2f0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b300@@3PAEA=?FUN_14001b300@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b310@@3PAEA=?FUN_14001b310@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b320@@3PAEA=?FUN_14001b320@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b330@@3PAEA=?FUN_14001b330@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b340@@3PAEA=?FUN_14001b340@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b350@@3PAEA=?FUN_14001b350@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b360@@3PAEA=?FUN_14001b360@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b370@@3PAEA=?FUN_14001b370@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b380@@3PAEA=?FUN_14001b380@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b390@@3PAEA=?FUN_14001b390@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14001b3a0@@3PAEA=?FUN_14001b3a0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_142300840@@3PAEA=?SetSpatialInfo@VideoSoundStream@Video@GFx@Scaleform@@UEAAXPEBX@Z")
#pragma comment(linker, "/alternatename:?DAT_1423dc0b0@@3PAEA=?Bind@AvmDisplayObj@AS3@GFx@Scaleform@@UEAAXPEAVDisplayObject@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_1423dcd60@@3PAEA=?IsStage@AvmInteractiveObj@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df420@@3PAEA=?Finalize_GC@?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@MEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df430@@3PAEA=?GetAS3ObjectName@Object@AS3@GFx@Scaleform@@UEBA?AVString@4@XZ")
#pragma comment(linker, "/alternatename:?DAT_1423df460@@3PAEA=?GetAS3ObjectName@Traits@AS3@GFx@Scaleform@@UEBA?AVString@4@XZ")
#pragma comment(linker, "/alternatename:?DAT_1423df4a0@@3PAEA=?GetAS3ObjectName@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA?AVString@5@XZ")
#pragma comment(linker, "/alternatename:?DAT_1423df580@@3PAEA=?Unk15@Object@AS3@GFx@Scaleform@@UEAAPEAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df590@@3PAEA=?InitInstance@Object@AS3@GFx@Scaleform@@UEAAX_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1423df5a0@@3PAEA=?IsAS3Object@?$RefCountBaseGC@$0BED@@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1423df5b0@@3PAEA=?IsAS3Object@Object@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142442e10@@3PAEA=?ForEachChild_GC@DisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@MEBAXPEAV?$RefCountCollector@$0BED@@456@P6AX0PEAPEBV?$RefCountBaseGC@$0BED@@456@@Z@Z")
#pragma comment(linker, "/alternatename:?DAT_142443380@@3PAEA=?GetAS3ObjectName@DisplayObject@fl_display@Instances@AS3@GFx@Scaleform@@UEBA?AVString@6@XZ")
#pragma comment(linker, "/alternatename:?DAT_1424e4290@@3PAEA=??1CheckResult@AS3@GFx@Scaleform@@QEAA@XZ")
#pragma comment(linker, "/alternatename:?DAT_1424e42a0@@3PAEA=?AS3Constructor@Traits@InstanceTraits@AS3@GFx@Scaleform@@UEBAXAEBV1345@AEBVValue@345@IPEBV6345@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424e8060@@3PAEA=?AddDynamicSlotValuePair@Object@AS3@GFx@Scaleform@@UEAAXAEBVValue@234@0W4Attribute@SlotInfo@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424eb250@@3PAEA=?AdvanceFrame@DisplayObjectBase@GFx@Scaleform@@UEAAX_NM@Z")
#pragma comment(linker, "/alternatename:?DAT_1424eb770@@3PAEA=?ApplyTypeArgs@Class@AS3@GFx@Scaleform@@UEAAAEAV1234@IPEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424ee6f0@@3PAEA=?Call@Class@AS3@GFx@Scaleform@@UEAAXAEBVValue@234@AEAV5234@IQEBV5234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424ee7f0@@3PAEA=?Call@Object@AS3@GFx@Scaleform@@UEAAXAEBVValue@234@AEAV5234@IQEBV5234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424eeca0@@3PAEA=?CheckAdvanceStatus@InteractiveObject@GFx@Scaleform@@UEAAH_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1424effa0@@3PAEA=?Coerce@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA_NAEBVValue@345@AEAV6345@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f0610@@3PAEA=?Construct@Class@AS3@GFx@Scaleform@@UEAAXAEAVValue@234@IPEBV5234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f0700@@3PAEA=?Sfr33ThrowNotConstructor@AS3@GFx@Scaleform@@YAXPEBE@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f2400@@3PAEA=?CreateASInstance@AvmDisplayObj@AS3@GFx@Scaleform@@UEAAI_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f4a40@@3PAEA=?DeleteProperty@Object@AS3@GFx@Scaleform@@UEAA?AVCheckResult@234@AEBVMultiname@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f7180@@3PAEA=?DetachChild@AvmDisplayObj@AS3@GFx@Scaleform@@UEAA_NPEAVDisplayObjectBase@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_1424f74d0@@3PAEA=?DoDisplayCallback@InteractiveObject@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1424fe610@@3PAEA=?ExecuteFrame0Events@InteractiveObject@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_142500e50@@3PAEA=?FindDynamicSlot@Object@AS3@GFx@Scaleform@@UEAA?AVPropRef@234@AEBVMultiname@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142501a60@@3PAEA=?FindInsertToPlayList@AvmInteractiveObj@AS3@GFx@Scaleform@@UEAAPEAVInteractiveObject@34@PEAV534@@Z")
#pragma comment(linker, "/alternatename:?DAT_142503800@@3PAEA=?Sfr33ForEachChildGC_38_48@AS3@GFx@Scaleform@@YAXPEAEPEAXP6AX111@Z@Z")
#pragma comment(linker, "/alternatename:?DAT_142503f50@@3PAEA=?Sfr33ForEachChildGC_c0a@AS3@GFx@Scaleform@@YAXPEAEPEAXP6AX111@Z@Z")
#pragma comment(linker, "/alternatename:?DAT_142503fa0@@3PAEA=?Sfr33ForEachChildGC_c0b@AS3@GFx@Scaleform@@YAXPEAEPEAXP6AX111@Z@Z")
#pragma comment(linker, "/alternatename:?DAT_142504840@@3PAEA=?ForceShutdown@DisplayObjectBase@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_142505f20@@3PAEA=?GetASClassName@AvmDisplayObj@AS3@GFx@Scaleform@@UEBAAEAVString@4@PEAV54@@Z")
#pragma comment(linker, "/alternatename:?DAT_142506ef0@@3PAEA=?GetAcceptAnimMoves@DisplayObject@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142507590@@3PAEA=?GetAvmTopParent@AvmInteractiveObj@AS3@GFx@Scaleform@@UEBAPEAV1234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1425084c0@@3PAEA=?GetContinueAnimationFlag@DisplayObject@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1425084d0@@3PAEA=?GetCurrentFrame@InteractiveObject@GFx@Scaleform@@UEBAIXZ")
#pragma comment(linker, "/alternatename:?DAT_142509990@@3PAEA=?GetDrawingContext@DisplayObject@GFx@Scaleform@@UEAAPEAVDrawingContext@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_142509a80@@3PAEA=?GetDynamicProperty@Object@AS3@GFx@Scaleform@@UEAAXVAbsoluteIndex@234@AEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142509ca0@@3PAEA=?GetFilePtr@Traits@AS3@GFx@Scaleform@@UEBAPEAVVMAbcFile@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_142509d30@@3PAEA=?GetFixedMemSize@Traits@AS3@GFx@Scaleform@@UEBAIXZ")
#pragma comment(linker, "/alternatename:?DAT_142509d40@@3PAEA=?GetFocusRect@InteractiveObject@GFx@Scaleform@@UEBA?AV?$Rect@M@Render@3@XZ")
#pragma comment(linker, "/alternatename:?DAT_142509da0@@3PAEA=?GetFontManager@DisplayObjectBase@GFx@Scaleform@@UEBAPEAVFontManager@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_142509dc0@@3PAEA=?GetFrameLabel@InteractiveObject@GFx@Scaleform@@UEAAPEBVString@3@IPEAI@Z")
#pragma comment(linker, "/alternatename:?DAT_14250a5b0@@3PAEA=?GetGlobalObjectScript@Traits@AS3@GFx@Scaleform@@UEBAPEAVGlobalObjectScript@fl@Instances@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_14250b360@@3PAEA=?GetLabeledFrame@InteractiveObject@GFx@Scaleform@@UEAA_NPEBDPEAI_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14250b3a0@@3PAEA=?GetLoadingFrame@InteractiveObject@GFx@Scaleform@@UEBAIXZ")
#pragma comment(linker, "/alternatename:?DAT_14250bbd0@@3PAEA=?GetName@CTraits@InstanceTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@XZ")
#pragma comment(linker, "/alternatename:?DAT_14250bc40@@3PAEA=?GetName@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@XZ")
#pragma comment(linker, "/alternatename:?DAT_14250be40@@3PAEA=?GetNextDynPropIndex@Object@AS3@GFx@Scaleform@@UEBA?AVGlobalSlotIndex@234@V5234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250c010@@3PAEA=?GetNextPropertyName@Object@AS3@GFx@Scaleform@@UEBAXAEAVValue@234@VGlobalSlotIndex@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250c060@@3PAEA=?GetNextPropertyValue@Object@AS3@GFx@Scaleform@@UEAAXAEAVValue@234@VGlobalSlotIndex@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250c2e0@@3PAEA=?GetObjectsUnderPoint@AvmDisplayObj@AS3@GFx@Scaleform@@UEBA_NPEAV?$ArrayDH@V?$Ptr@VDisplayObjectBase@GFx@Scaleform@@@Scaleform@@$01UArrayDefaultPolicy@2@@4@AEBV?$Point@M@Render@4@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250cc20@@3PAEA=?GetPlayState@InteractiveObject@GFx@Scaleform@@UEBA?AW4PlayState@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_14250cc60@@3PAEA=?GetProperty@Object@AS3@GFx@Scaleform@@UEAA?AVCheckResult@234@AEBVMultiname@234@AEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250d550@@3PAEA=?GetQualifiedName@Traits@ClassTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@W4QNameFormat@1345@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250d570@@3PAEA=?GetQualifiedName@Traits@InstanceTraits@AS3@GFx@Scaleform@@UEBA?AVASString@45@W4QNameFormat@1345@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250d620@@3PAEA=?GetRatio@DisplayObjectBase@GFx@Scaleform@@UEBAMXZ")
#pragma comment(linker, "/alternatename:?DAT_14250d6f0@@3PAEA=?GetRectBounds@DisplayObjectBase@GFx@Scaleform@@UEBA?AV?$Rect@M@Render@3@AEBV?$Matrix2x4@M@53@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250ee20@@3PAEA=?GetStateChangeFlags@InteractiveObject@GFx@Scaleform@@UEBAEXZ")
#pragma comment(linker, "/alternatename:?DAT_14250f760@@3PAEA=?GetTopMostMouseEntity@DisplayObjectBase@GFx@Scaleform@@UEAA?AW4TopMostResult@123@AEBV?$Point@M@Render@3@PEAUTopMostDescr@123@@Z")
#pragma comment(linker, "/alternatename:?DAT_14250f820@@3PAEA=?GetTopParent@AvmInteractiveObj@AS3@GFx@Scaleform@@UEBAPEAVInteractiveObject@34@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14250f850@@3PAEA=?GetTopParent@DisplayObjectBase@GFx@Scaleform@@UEBAPEAVInteractiveObject@23@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142510a30@@3PAEA=?GetVisible@DisplayObjectBase@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142510d10@@3PAEA=?GotoFrame@InteractiveObject@GFx@Scaleform@@UEAAXI@Z")
#pragma comment(linker, "/alternatename:?DAT_142510d40@@3PAEA=?Has3D@DisplayObjectBase@GFx@Scaleform@@UEAA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142510e60@@3PAEA=?HasLooped@InteractiveObject@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1425117e0@@3PAEA=?InitOnDemand@Traits@AS3@GFx@Scaleform@@MEBAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1425117f0@@3PAEA=?InitOnDemand@Traits@ClassTraits@AS3@GFx@Scaleform@@MEBAXXZ")
#pragma comment(linker, "/alternatename:?DAT_142511810@@3PAEA=?InitPrototype@Class@AS3@GFx@Scaleform@@UEBAXAEAVObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142512620@@3PAEA=?InitializeOnDemand@Object@AS3@GFx@Scaleform@@UEAAPEBVSlotInfo@234@PEBV5234@AEBVASString@34@AEBVNamespace@Instances@234@AEA_K@Z")
#pragma comment(linker, "/alternatename:?DAT_142514320@@3PAEA=?IsGlobal@Traits@AS3@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142515190@@3PAEA=?IsUsedAsMask@DisplayObject@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_142516630@@3PAEA=?MakePrototype@Class@AS3@GFx@Scaleform@@UEBA?AV?$Pickable@VObject@AS3@GFx@Scaleform@@@4@XZ")
#pragma comment(linker, "/alternatename:?DAT_1425185d0@@3PAEA=?OnAdded@AvmDisplayObj@AS3@GFx@Scaleform@@UEAAX_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142518990@@3PAEA=?OnCharEvent@InteractiveObject@GFx@Scaleform@@UEAA_NII@Z")
#pragma comment(linker, "/alternatename:?DAT_14251a100@@3PAEA=?OnGettingKeyboardFocus@InteractiveObject@GFx@Scaleform@@UEAAXIW4FocusMovedType@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14251a3a0@@3PAEA=?OnKeyEvent@InteractiveObject@GFx@Scaleform@@UEAA_NAEBVEventId@23@PEAH@Z")
#pragma comment(linker, "/alternatename:?DAT_14251a820@@3PAEA=?OnLosingKeyboardFocus@InteractiveObject@GFx@Scaleform@@UEAA_NPEAV123@IW4FocusMovedType@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14251ac20@@3PAEA=?OnMouseEvent@InteractiveObject@GFx@Scaleform@@UEAA_NAEBVEventId@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14251ac30@@3PAEA=?OnMouseWheelEvent@InteractiveObject@GFx@Scaleform@@UEAA_NH@Z")
#pragma comment(linker, "/alternatename:?DAT_14251ace0@@3PAEA=?OnRemoved@AvmDisplayObj@AS3@GFx@Scaleform@@UEAAX_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14251cab0@@3PAEA=?PointTestLocal@DisplayObjectBase@GFx@Scaleform@@UEBA_NAEBV?$Point@M@Render@3@E@Z")
#pragma comment(linker, "/alternatename:?DAT_14251ced0@@3PAEA=?PostInit@Class@AS3@GFx@Scaleform@@UEBAXAEBVValue@234@IPEBV5234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14251cfc0@@3PAEA=?PreInit@Class@AS3@GFx@Scaleform@@UEBA?AVCheckResult@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14251f3a0@@3PAEA=?PropagateEvent@AvmDisplayObj@AS3@GFx@Scaleform@@UEAAXAEBVEvent@fl_events@Instances@234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14251f540@@3PAEA=?PropagateFocusGroupMask@InteractiveObject@GFx@Scaleform@@UEAAXI@Z")
#pragma comment(linker, "/alternatename:?DAT_14251f550@@3PAEA=?PropagateKeyEvent@InteractiveObject@GFx@Scaleform@@UEAAXAEBVEventId@23@PEAH@Z")
#pragma comment(linker, "/alternatename:?DAT_14251f560@@3PAEA=?PropagateMouseEvent@InteractiveObject@GFx@Scaleform@@UEAAXAEBVEventId@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14251f5c0@@3PAEA=?PropagateNoAdvanceGlobalFlag@InteractiveObject@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14251f5d0@@3PAEA=?PropagateNoAdvanceLocalFlag@InteractiveObject@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1425227d0@@3PAEA=?RemoveDisplayObject@InteractiveObject@GFx@Scaleform@@UEAAXPEAVDisplayObjectBase@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_142525c90@@3PAEA=?Restart@DisplayObjectBase@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1425265f0@@3PAEA=?SetBlendMode@InteractiveObject@GFx@Scaleform@@UEAAXW4BlendMode@Render@3@@Z")
#pragma comment(linker, "/alternatename:?DAT_142526720@@3PAEA=?SetDisplayCallback@InteractiveObject@GFx@Scaleform@@UEAAXP6AXPEAX@Z0@Z")
#pragma comment(linker, "/alternatename:?DAT_1425287f0@@3PAEA=?SetPause@InteractiveObject@GFx@Scaleform@@UEAAX_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142528800@@3PAEA=?SetPlayState@InteractiveObject@GFx@Scaleform@@UEAAXW4PlayState@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_142528a50@@3PAEA=?SetProperty@Object@AS3@GFx@Scaleform@@UEAA?AVCheckResult@234@AEBVMultiname@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142528d90@@3PAEA=?SetRatio@DisplayObjectBase@GFx@Scaleform@@UEAAXM@Z")
#pragma comment(linker, "/alternatename:?DAT_142529f50@@3PAEA=?SetStateChangeFlags@InteractiveObject@GFx@Scaleform@@UEAAXE@Z")
#pragma comment(linker, "/alternatename:?DAT_14252b580@@3PAEA=?SetVisible@DisplayObjectBase@GFx@Scaleform@@UEAAX_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14252c4e0@@3PAEA=?SetupSlotValues@Traits@AS3@GFx@Scaleform@@UEBA?AVCheckResult@234@AEAVObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14252c9c0@@3PAEA=?StopActiveSounds@InteractiveObject@GFx@Scaleform@@UEAAXPEAVASSoundIntf@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14252c9d0@@3PAEA=?StopActiveSounds@InteractiveObject@GFx@Scaleform@@UEAAXPEAVSoundResource@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_14252c9e0@@3PAEA=?StopActiveSounds@InteractiveObject@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14252e480@@3PAEA=?Sfr31TracerHasTraits@AS3@GFx@Scaleform@@YA_N_K0@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f1ae0@@3PAEA=?CreateNewInstanceName@DisplayObject@GFx@Scaleform@@MEBA?AVASString@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_1425f1ca0@@3PAEA=?GetBlendMode@DisplayObjectBase@GFx@Scaleform@@UEBA?AW4BlendMode@Render@3@XZ")
#pragma comment(linker, "/alternatename:?DAT_1425f1d50@@3PAEA=?GetFOV@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f1d70@@3PAEA=?GetFilters@DisplayObjectBase@GFx@Scaleform@@UEBAPEBVFilterSet@Render@3@XZ")
#pragma comment(linker, "/alternatename:?DAT_1425f1db0@@3PAEA=?GetFocalLength@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f1f60@@3PAEA=?GetHeight@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2040@@3PAEA=?GetLog@DisplayObjectBase@GFx@Scaleform@@UEBAPEAVLog@3@XZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2140@@3PAEA=?GetMatrix3D@DisplayObject@GFx@Scaleform@@UEBAAEBV?$Matrix3x4@M@Render@3@XZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2210@@3PAEA=?GetMatrix@DisplayObject@GFx@Scaleform@@UEBAAEBV?$Matrix2x4@M@Render@3@XZ")
#pragma comment(linker, "/alternatename:?DAT_1425f22e0@@3PAEA=?GetMouseX@DisplayObject@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f23e0@@3PAEA=?GetMouseY@DisplayObject@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f25c0@@3PAEA=?GetProjectionCenter@DisplayObjectBase@GFx@Scaleform@@UEBA?AV?$Point@M@Render@3@XZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2600@@3PAEA=?GetProjectionMatrix3D@DisplayObjectBase@GFx@Scaleform@@UEBA_NPEAV?$Matrix4x4@M@Render@3@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f2760@@3PAEA=?GetRotation@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f29a0@@3PAEA=?GetViewMatrix3D@DisplayObjectBase@GFx@Scaleform@@UEBA_NPEAV?$Matrix3x4@M@Render@3@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f2a40@@3PAEA=?GetWidth@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2cd0@@3PAEA=?GetX@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2d40@@3PAEA=?GetXRotation@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2db0@@3PAEA=?GetXScale@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2e20@@3PAEA=?GetY@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2e90@@3PAEA=?GetYRotation@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2f00@@3PAEA=?GetYScale@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2f70@@3PAEA=?GetZ@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f2fe0@@3PAEA=?GetZScale@DisplayObjectBase@GFx@Scaleform@@UEBANXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f3390@@3PAEA=?IsVerboseAction@DisplayObjectBase@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f33e0@@3PAEA=?IsVerboseActionErrors@DisplayObjectBase@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f3980@@3PAEA=?OnEvent@DisplayObject@GFx@Scaleform@@UEAA_NAEBVEventId@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f3de0@@3PAEA=?SetAcceptAnimMoves@DisplayObject@GFx@Scaleform@@UEAAX_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f40a0@@3PAEA=?SetFOV@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f41b0@@3PAEA=?SetFilters@DisplayObjectBase@GFx@Scaleform@@UEAAXPEBVFilterSet@Render@3@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f41f0@@3PAEA=?SetFocalLength@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f4460@@3PAEA=?SetHeight@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f4d70@@3PAEA=?SetMatrix3D@DisplayObject@GFx@Scaleform@@UEAAXAEBV?$Matrix3x4@M@Render@3@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f5010@@3PAEA=?SetMatrix@DisplayObject@GFx@Scaleform@@UEAAXAEBV?$Matrix2x4@M@Render@3@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f5530@@3PAEA=?SetProjectionCenter@DisplayObjectBase@GFx@Scaleform@@UEAAXV?$Point@M@Render@3@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f56c0@@3PAEA=?SetProjectionMatrix3D@DisplayObjectBase@GFx@Scaleform@@UEAAXAEBV?$Matrix4x4@M@Render@3@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f57a0@@3PAEA=?SetRotation@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f5e70@@3PAEA=?SetViewMatrix3D@DisplayObjectBase@GFx@Scaleform@@UEAAXAEBV?$Matrix3x4@M@Render@3@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f6130@@3PAEA=?SetWidth@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f64c0@@3PAEA=?SetX@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f6690@@3PAEA=?SetXRotation@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f6760@@3PAEA=?SetXScale@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f69f0@@3PAEA=?SetY@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f6bc0@@3PAEA=?SetYRotation@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f6c90@@3PAEA=?SetYScale@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f6f20@@3PAEA=?SetZ@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f6fe0@@3PAEA=?SetZScale@DisplayObjectBase@GFx@Scaleform@@UEAAXN@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f75c0@@3PAEA=?UpdateTransform3D@DisplayObjectBase@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f7af0@@3PAEA=?UpdateViewAndPerspective@DisplayObjectBase@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f7fc0@@3PAEA=?CloneInternalData@InteractiveObject@GFx@Scaleform@@UEAAXPEBV123@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f8480@@3PAEA=?GetCursorType@InteractiveObject@GFx@Scaleform@@UEBAIXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f8540@@3PAEA=?GetRenderContainer@InteractiveObject@GFx@Scaleform@@UEAAPEAVTreeContainer@Render@3@XZ")
#pragma comment(linker, "/alternatename:?DAT_1425f8550@@3PAEA=?GetResourceMovieDef@InteractiveObject@GFx@Scaleform@@UEBAPEAVMovieDefImpl@23@XZ")
#pragma comment(linker, "/alternatename:?DAT_1425f85e0@@3PAEA=?IsFocusAllowed@InteractiveObject@GFx@Scaleform@@UEAA_NPEAVMovieImpl@23@I@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f8630@@3PAEA=?IsFocusAllowed@InteractiveObject@GFx@Scaleform@@UEBA_NPEAVMovieImpl@23@I@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f8690@@3PAEA=?IsFocusEnabled@InteractiveObject@GFx@Scaleform@@UEBA_NW4FocusMovedType@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f86d0@@3PAEA=?IsFocusRectEnabled@InteractiveObject@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f8760@@3PAEA=?IsTabable@InteractiveObject@GFx@Scaleform@@UEBA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f8870@@3PAEA=?OnEventLoad@InteractiveObject@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f8880@@3PAEA=?OnEventUnload@InteractiveObject@GFx@Scaleform@@UEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1425f88e0@@3PAEA=?OnFocus@InteractiveObject@GFx@Scaleform@@UEAAXW4FocusEventType@123@PEAV123@IW4FocusMovedType@23@@Z")
#pragma comment(linker, "/alternatename:?DAT_1425f8940@@3PAEA=?OnUnloading@InteractiveObject@GFx@Scaleform@@UEAA_NXZ")
#pragma comment(linker, "/alternatename:?DAT_14280ef52@@3PAEA=_purecall")
#pragma comment(linker, "/alternatename:?DAT_1429386e0@@3PAEA=?DeleteMember@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_1429388e0@@3PAEA=?DeleteMember@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_14293ff70@@3PAEA=?FUN_14293ff70@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_142940160@@3PAEA=?FUN_142940160@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1429411f0@@3PAEA=?ExecuteForEachChild_GC@Object@AS2@GFx@Scaleform@@MEBAXPEAV?$RefCountCollector@$0BED@@234@W4OperationGC@?$RefCountBaseGC@$0BED@@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1429413c0@@3PAEA=?FUN_1429413c0@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_142942e70@@3PAEA=?Finalize_GC@Object@AS2@GFx@Scaleform@@MEAAXXZ")
#pragma comment(linker, "/alternatename:?DAT_1429448c0@@3PAEA=?FindMember@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@PEAVMember@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142944950@@3PAEA=?FindMember@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@PEAVMember@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1429493c0@@3PAEA=?GetASEnvironment@AvmCharacter@AS2@GFx@Scaleform@@UEAAPEAVEnvironment@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_142949400@@3PAEA=?GetASEnvironment@AvmCharacter@AS2@GFx@Scaleform@@UEBAPEBVEnvironment@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_142949860@@3PAEA=?GetAvmTopParent@AvmCharacter@AS2@GFx@Scaleform@@UEBAPEAV1234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_14294ab50@@3PAEA=?GetEnvironment@CFunctionObject@AS2@GFx@Scaleform@@UEAAPEAVEnvironment@234@AEBVFnCall@234@PEAV?$Ptr@VInteractiveObject@GFx@Scaleform@@@4@@Z")
#pragma comment(linker, "/alternatename:?DAT_14294afb0@@3PAEA=?GetGC@AvmCharacter@AS2@GFx@Scaleform@@UEBAPEAVGlobalContext@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_14294f7d0@@3PAEA=?GetMember@Object@AS2@GFx@Scaleform@@UEAA_NPEAVEnvironment@234@AEBVASString@34@PEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142953280@@3PAEA=?GetMemberRaw@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@PEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142955080@@3PAEA=?GetStandardMember@AvmCharacter@AS2@GFx@Scaleform@@UEBA_NW4StandardMember@1234@PEAVValue@234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142956b10@@3PAEA=?GetTopParent@AvmCharacter@AS2@GFx@Scaleform@@UEBAPEAVInteractiveObject@34@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142956ca0@@3PAEA=?GetValue@Object@AS2@GFx@Scaleform@@UEBA?AVValue@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_14295d840@@3PAEA=?FUN_14295d840@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14295d970@@3PAEA=?HasMember@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142962310@@3PAEA=?InstanceOf@AvmCharacter@AS2@GFx@Scaleform@@UEBA_NPEAVEnvironment@234@PEBVObject@234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_1429623a0@@3PAEA=?InstanceOf@Object@AS2@GFx@Scaleform@@UEBA_NPEAVEnvironment@234@PEBV1234@_N@Z")
#pragma comment(linker, "/alternatename:?DAT_142962bb0@@3PAEA=?Invoke@CFunctionObject@AS2@GFx@Scaleform@@UEAAXAEBVFnCall@234@PEAVLocalFrame@234@PEBD@Z")
#pragma comment(linker, "/alternatename:?DAT_142965510@@3PAEA=?IsEqual@CFunctionObject@AS2@GFx@Scaleform@@UEBA_NAEBVFunctionObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1429867f0@@3PAEA=?SetMember@Object@AS2@GFx@Scaleform@@UEAA_NPEAVEnvironment@234@AEBVASString@34@AEBVValue@234@AEBVPropFlags@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142988930@@3PAEA=?SetMemberFlags@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@E@Z")
#pragma comment(linker, "/alternatename:?DAT_1429889c0@@3PAEA=?SetMemberFlags@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@E@Z")
#pragma comment(linker, "/alternatename:?DAT_142988bb0@@3PAEA=?SetMemberRaw@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@AEBVValue@234@AEBVPropFlags@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14298ab80@@3PAEA=?FUN_14298ab80@@YAXXZ")
#pragma comment(linker, "/alternatename:?DAT_14298cc70@@3PAEA=?SetValue@Object@AS2@GFx@Scaleform@@UEAAXPEAVEnvironment@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14298dcb0@@3PAEA=?Set__proto__@AvmCharacter@AS2@GFx@Scaleform@@UEAAXPEAVASStringContext@234@PEAVObject@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142991140@@3PAEA=?ToFunction@FunctionObject@AS2@GFx@Scaleform@@UEAA?AVFunctionRef@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_142991170@@3PAEA=?ToFunction@Object@AS2@GFx@Scaleform@@UEAA?AVFunctionRef@234@XZ")
#pragma comment(linker, "/alternatename:?DAT_1429926f0@@3PAEA=?Unwatch@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_142992780@@3PAEA=?Unwatch@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@@Z")
#pragma comment(linker, "/alternatename:?DAT_142994660@@3PAEA=?VisitMembers@AvmCharacter@AS2@GFx@Scaleform@@UEBAXPEAVASStringContext@234@PEAUMemberVisitor@ObjectInterface@234@IPEBV7234@@Z")
#pragma comment(linker, "/alternatename:?DAT_1429947f0@@3PAEA=?VisitMembers@Object@AS2@GFx@Scaleform@@UEBAXPEAVASStringContext@234@PEAUMemberVisitor@ObjectInterface@234@IPEBV7234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142994bb0@@3PAEA=?Watch@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@AEBVFunctionRef@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_142994c50@@3PAEA=?Watch@Object@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@AEBVFunctionRef@234@AEBVValue@234@@Z")
#pragma comment(linker, "/alternatename:?DAT_14313d990@@3PAEA=?ObjectCI@fl@AS3@GFx@Scaleform@@3UClassInfo@234@B")
#pragma comment(linker, "/alternatename:?DAT_14313da30@@3PAEA=?BooleanCI@fl@AS3@GFx@Scaleform@@3UClassInfo@234@B")
#pragma comment(linker, "/alternatename:?DAT_14313dad0@@3PAEA=?uintCI@fl@AS3@GFx@Scaleform@@3UClassInfo@234@B")
#pragma comment(linker, "/alternatename:?DAT_14313db20@@3PAEA=?NumberCI@fl@AS3@GFx@Scaleform@@3UClassInfo@234@B")
#pragma comment(linker, "/alternatename:?DAT_143146580@@3PAEA=?DisplayObjectCI@fl_display@AS3@GFx@Scaleform@@3UClassInfo@234@B")
#pragma comment(linker, "/alternatename:?DAT_143150b00@@3PAEA=?EventDispatcherCI@fl_events@AS3@GFx@Scaleform@@3UClassInfo@234@B")
#pragma comment(linker, "/alternatename:?DAT_143177ac0@@3PAEA=?SoundTransformCI@fl_media@AS3@GFx@Scaleform@@3UClassInfo@234@B")

#pragma comment(linker, "/alternatename:?FUN_14000e0c0@@YAXXZ=?CreateNewObject@VideoCtorFunction@AS2@GFx@Scaleform@@UEBAPEAVObject@234@PEAVEnvironment@234@@Z")
#pragma comment(linker, "/alternatename:?FUN_14000ebc0@@YAXXZ=?FUN_14000ebc0@@YAPEAVObject@AS2@GFx@Scaleform@@PEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_14000ebd0@@YAXXZ=?FUN_14000ebd0@@YAPEAVObject@AS2@GFx@Scaleform@@PEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_14000ec40@@YAXXZ=?FUN_14000ec40@@YAPEAVObject@AS2@GFx@Scaleform@@PEAV1234@I@Z")
#pragma comment(linker, "/alternatename:?FUN_14000ed10@@YAXXZ=?FUN_14000ed10@@YAPEAVCFunctionObject@AS2@GFx@Scaleform@@PEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_14000ed20@@YAXXZ=?FUN_14000ed20@@YAPEAVCFunctionObject@AS2@GFx@Scaleform@@PEAV1234@I@Z")
#pragma comment(linker, "/alternatename:?FUN_140010130@@YAXXZ=?FUN_140010130@@YAPEAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140010140@@YAXXZ=?FUN_140010140@@YAHPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140010180@@YAXXZ=?FUN_140010180@@YAPEAVInteractiveObject@GFx@Scaleform@@PEAX_K@Z")
#pragma comment(linker, "/alternatename:?FUN_140010200@@YAXXZ=?FUN_140010200@AS2@GFx@Scaleform@@YAPEAV?$Rect@M@Render@3@PEAXPEAV453@PEBV?$Matrix2x4@M@53@@Z")
#pragma comment(linker, "/alternatename:?FUN_140010530@@YAXXZ=?FUN_140010530@@YAPEAVInteractiveObject@GFx@Scaleform@@PEAV123@_K@Z")
#pragma comment(linker, "/alternatename:?FUN_140011610@@YAXXZ=?FUN_140011610@@YAPEAXPEAXPEAPEAX0@Z")
#pragma comment(linker, "/alternatename:?FUN_140011b80@@YAXXZ=?FUN_140011b80@@YAHPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140011b90@@YAXXZ=?FUN_140011b90@@YAPEAXPEAX000@Z")
#pragma comment(linker, "/alternatename:?FUN_140011ba0@@YAXXZ=?FUN_140011ba0@@YA_NPEAX000@Z")
#pragma comment(linker, "/alternatename:?FUN_140011bb0@@YAXXZ=?FUN_140011bb0@@YA_NPEAX00@Z")
#pragma comment(linker, "/alternatename:?FUN_140011bd0@@YAXXZ=?FUN_140011bd0@@YA_NPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140011c00@@YAXXZ=?FUN_140011c00@@YAPEAVObject@AS2@GFx@Scaleform@@PEAV1234@I@Z")
#pragma comment(linker, "/alternatename:?FUN_140011c70@@YAXXZ=?FUN_140011c70@@YAPEAVObject@AS2@GFx@Scaleform@@PEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_140011c80@@YAXXZ=?FUN_140011c80@@YAPEAVObject@AS2@GFx@Scaleform@@PEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_140011d00@@YAXXZ=?FUN_140011d00@@YAPEAVObject@AS2@GFx@Scaleform@@PEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_140011d10@@YAXXZ=?FUN_140011d10@@YAPEAVObject@AS2@GFx@Scaleform@@PEAV1234@I@Z")
#pragma comment(linker, "/alternatename:?FUN_140011d50@@YAXXZ=?FUN_140011d50@@YAPEAVObject@AS2@GFx@Scaleform@@PEAXPEAVEnvironment@234@@Z")
#pragma comment(linker, "/alternatename:?FUN_140011d90@@YAXXZ=?FUN_140011d90@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140011de0@@YAXXZ=?FUN_140011de0@@YAXPEAVObject@AS2@GFx@Scaleform@@PEAVASStringContext@234@PEAVASString@34@PEAVValue@234@@Z")
#pragma comment(linker, "/alternatename:?FUN_140012400@@YAXXZ=?FUN_140012400@@YAXPEAVObject@AS2@GFx@Scaleform@@PEAV?$RefCountCollector@$0BED@@234@H@Z")
#pragma comment(linker, "/alternatename:?FUN_140012580@@YAXXZ=?FUN_140012580@@YAPEAVObject@AS2@GFx@Scaleform@@PEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_140012590@@YAXXZ=?FUN_140012590@@YAPEAVObject@AS2@GFx@Scaleform@@PEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_1400125e0@@YAXXZ=?FUN_1400125e0@@YAPEAVObject@AS2@GFx@Scaleform@@PEAV1234@I@Z")
#pragma comment(linker, "/alternatename:?FUN_1400126a0@@YAXXZ=?FUN_1400126a0@@YAPEAVCFunctionObject@AS2@GFx@Scaleform@@PEAXI@Z")
#pragma comment(linker, "/alternatename:?FUN_1400126b0@@YAXXZ=?FUN_1400126b0@@YAPEAVCFunctionObject@AS2@GFx@Scaleform@@PEAV1234@I@Z")
#pragma comment(linker, "/alternatename:?FUN_140012e10@@YAXXZ=?FUN_140012e10@@YAXPEAX00@Z")
#pragma comment(linker, "/alternatename:?FUN_140012ef0@@YAXXZ=?FUN_140012ef0@@YAPEBDPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140012f40@@YAXXZ=?FUN_140012f40@@YAPEBDPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140013230@@YAXXZ=?FUN_140013230@@YAXPEAX0PEBX0I1@Z")
#pragma comment(linker, "/alternatename:?FUN_140013250@@YAXXZ=?FUN_140013250@@YAXPEAX0PEBX0I1@Z")
#pragma comment(linker, "/alternatename:?FUN_1400133e0@@YAXXZ=?FUN_1400133e0@@YAXPEAX0PEBX0I1@Z")
#pragma comment(linker, "/alternatename:?FUN_140013400@@YAXXZ=?FUN_140013400@@YAXPEAX0PEBX0I1@Z")
#pragma comment(linker, "/alternatename:?FUN_140013420@@YAXXZ=?FUN_140013420@@YAXPEAX0PEBX0I1@Z")
#pragma comment(linker, "/alternatename:?FUN_140013440@@YAXXZ=?FUN_140013440@@YAXPEAX0PEBX0I1@Z")
#pragma comment(linker, "/alternatename:?FUN_1400141a0@@YAXXZ=?FUN_1400141a0@@YAPEBDPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140014900@@YAXXZ=?FUN_140014900@@YAXPEAXPEB_K@Z")
#pragma comment(linker, "/alternatename:?FUN_140014a80@@YAXXZ=?FUN_140014a80@@YAPEAVCTraits@InstanceTraits@AS3@GFx@Scaleform@@PEAV12345@I@Z")
#pragma comment(linker, "/alternatename:?FUN_140014b10@@YAXXZ=?FUN_140014b10@@YAPEAVClass@AS3@GFx@Scaleform@@PEAV1234@I@Z")
#pragma comment(linker, "/alternatename:?FUN_140015590@@YAXXZ=?FUN_140015590@@YAPEAXPEAX_K@Z")
#pragma comment(linker, "/alternatename:?FUN_1400155d0@@YAXXZ=?FUN_1400155d0@@YAXPEAXPEAVValue@AS3@GFx@Scaleform@@0@Z")
#pragma comment(linker, "/alternatename:?FUN_140015c00@@YAXXZ=?FUN_140015c00@@YAPEAXPEAX_K@Z")
#pragma comment(linker, "/alternatename:?FUN_140015c40@@YAXXZ=?FUN_140015c40@@YAXPEAX@Z")
#pragma comment(linker, "/alternatename:?FUN_140015d20@@YAXXZ=?FUN_140015d20@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140015da0@@YAXXZ=?FUN_140015da0@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140015e20@@YAXXZ=?FUN_140015e20@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140015eb0@@YAXXZ=?FUN_140015eb0@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140015f20@@YAXXZ=?FUN_140015f20@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140015f90@@YAXXZ=?FUN_140015f90@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140016000@@YAXXZ=?FUN_140016000@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016060@@YAXXZ=?FUN_140016060@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016100@@YAXXZ=?FUN_140016100@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140016180@@YAXXZ=?FUN_140016180@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140016200@@YAXXZ=?FUN_140016200@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140016270@@YAXXZ=?FUN_140016270@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_1400162f0@@YAXXZ=?FUN_1400162f0@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016350@@YAXXZ=?FUN_140016350@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_1400163b0@@YAXXZ=?FUN_1400163b0@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016410@@YAXXZ=?FUN_140016410@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_1400164a0@@YAXXZ=?FUN_1400164a0@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016530@@YAXXZ=?FUN_140016530@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_1400165a0@@YAXXZ=?FUN_1400165a0@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016600@@YAXXZ=?FUN_140016600@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140016680@@YAXXZ=?FUN_140016680@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140016700@@YAXXZ=?FUN_140016700@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016790@@YAXXZ=?FUN_140016790@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140016810@@YAXXZ=?FUN_140016810@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_1400168a0@@YAXXZ=?FUN_1400168a0@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140016920@@YAXXZ=?FUN_140016920@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_1400169b0@@YAXXZ=?FUN_1400169b0@@YAXPEAX00PEAI@Z")
#pragma comment(linker, "/alternatename:?FUN_140016a30@@YAXXZ=?FUN_140016a30@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016ac0@@YAXXZ=?FUN_140016ac0@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016b50@@YAXXZ=?FUN_140016b50@?A0xa472a7c9@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016be0@@YAXXZ=?FUN_140016be0@?A0xa472a7c9@@YAXPEAX000HPEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140016fd0@@YAXXZ=?FUN_140016fd0@?A0xa472a7c9@@YAXPEAX000HPEBE@Z")
#pragma comment(linker, "/alternatename:?FUN_140017020@@YAXXZ=?FUN_140017020@?A0xa472a7c9@@YAXPEAX000HPEBE@Z")
#pragma comment(linker, "/alternatename:?FUN_140017070@@YAXXZ=?FUN_140017070@?A0xa472a7c9@@YAXPEAX000HPEBE@Z")
#pragma comment(linker, "/alternatename:?FUN_140017470@@YAXXZ=?FUN_140017470@?A0xa472a7c9@@YAXPEAX000IPEBE@Z")
#pragma comment(linker, "/alternatename:?FUN_140017520@@YAXXZ=?FUN_140017520@?A0xa472a7c9@@YAXPEAX00_KIPEB_K@Z")
#pragma comment(linker, "/alternatename:?FUN_140017670@@YAXXZ=?FUN_140017670@?A0xa472a7c9@@YAXPEAX00_KIPEB_K@Z")
#pragma comment(linker, "/alternatename:?FUN_1400182f0@@YAXXZ=?FUN_1400182f0@?A0xa472a7c9@@YAXPEAXPEBI@Z")
#pragma comment(linker, "/alternatename:?FUN_140018930@@YAXXZ=?FUN_140018930@?A0xa472a7c9@@YAXPEAXPEBI@Z")
#pragma comment(linker, "/alternatename:?FUN_140019890@@YAXXZ=?FUN_140019890@?A0xa472a7c9@@YAXPEAXPEB_K1@Z")
#pragma comment(linker, "/alternatename:?FUN_140019d70@@YAXXZ=?FUN_140019d70@@YAXPEAX00PEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140019e20@@YAXXZ=?FUN_140019e20@@YAXPEAX00PEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_140019ed0@@YAXXZ=?FUN_140019ed0@@YAXPEAX00PEAVValue@AS3@GFx@Scaleform@@@Z")
#pragma comment(linker, "/alternatename:?FUN_14293ff70@@YAXXZ=?ExecuteCFunction@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NP6AXAEBVFnCall@234@@ZAEBV?$Array@VValue@AS2@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@4@@Z")
#pragma comment(linker, "/alternatename:?FUN_142940160@@YAXXZ=?ExecuteEvent@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NAEBVEventId@34@@Z")
#pragma comment(linker, "/alternatename:?FUN_1429413c0@@YAXXZ=?ExecuteFunction@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NAEBVFunctionRef@234@AEBV?$Array@VValue@AS2@GFx@Scaleform@@$01UArrayDefaultPolicy@4@@4@@Z")
#pragma comment(linker, "/alternatename:?FUN_14295d840@@YAXXZ=?HasMember@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NPEAVASStringContext@234@AEBVASString@34@_N@Z")
#pragma comment(linker, "/alternatename:?FUN_14298ab80@@YAXXZ=?SetStandardMember@AvmCharacter@AS2@GFx@Scaleform@@UEAA_NW4StandardMember@1234@AEBVValue@234@_N@Z")
#endif // MS2_HOOK_DLL
