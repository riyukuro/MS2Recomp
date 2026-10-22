// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). See uimicrogamerps.h.
// MS2-UNIT: client\ms2\uimicrogamerps.cpp
// MS2-RANGE: 0x140e66040-0x140e66920 .text$mn
//
// Status: see progress/status.tsv. Callees that are not recovered yet are declared below ("unit-local
// placeholders") or in src/ms2/placeholder/; their names are Ghidra's (FUN_<va>) unless evident.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uimicrogamerps.cpp"
#include <vcruntime_string.h>
#pragma function(memcpy, memset)
#include "ms2/placeholder/ms2stdafx.h"

#include "uimicrogamerps.h"

#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/coutpacket.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asgameentity.h"

// ---- unit-local placeholders (unrecovered singletons / helpers; promote to src/ms2/placeholder/ when shared) ----



// This assignment COMDAT belongs to the earlier unit at 0x140ba7780.
template <> template <>
MS2Ptr<AScript>& MS2Ptr<AScript>::operator=<ASGameEntity>(const MS2Ptr<ASGameEntity>&);

MS2Ptr<ASGameEntity> FUN_140ba77e0(int n, const Scaleform::GFx::Value& v);    // new ASGameEntity(v, n)

// Singleton at 0x1401d3200 (a huge manager); two members at +0xc768 / +0xc7c0 give the screen origin.
class Unk_14025a620 { public: int FUN_14025a620(); void* m_unknown; };
class Unk_1402056b0 { public: int* FUN_1402056b0(); void* m_unknown; };
class Unk_1401d3200
{
public:
    void* m_pad_0; void* m_pad_8; void* m_pad_10; void* m_pad_18; void* m_pad_20; void* m_pad_28; void* m_pad_30; void* m_pad_38;
    void* m_pad_40; void* m_pad_48; void* m_pad_50; void* m_pad_58; void* m_pad_60; void* m_pad_68; void* m_pad_70; void* m_pad_78;
    void* m_pad_80; void* m_pad_88; void* m_pad_90; void* m_pad_98; void* m_pad_a0; void* m_pad_a8; void* m_pad_b0; void* m_pad_b8;
    void* m_pad_c0; void* m_pad_c8; void* m_pad_d0; void* m_pad_d8; void* m_pad_e0; void* m_pad_e8; void* m_pad_f0; void* m_pad_f8;
    void* m_pad_100; void* m_pad_108; void* m_pad_110; void* m_pad_118; void* m_pad_120; void* m_pad_128; void* m_pad_130; void* m_pad_138;
    void* m_pad_140; void* m_pad_148; void* m_pad_150; void* m_pad_158; void* m_pad_160; void* m_pad_168; void* m_pad_170; void* m_pad_178;
    void* m_pad_180; void* m_pad_188; void* m_pad_190; void* m_pad_198; void* m_pad_1a0; void* m_pad_1a8; void* m_pad_1b0; void* m_pad_1b8;
    void* m_pad_1c0; void* m_pad_1c8; void* m_pad_1d0; void* m_pad_1d8; void* m_pad_1e0; void* m_pad_1e8; void* m_pad_1f0; void* m_pad_1f8;
    void* m_pad_200; void* m_pad_208; void* m_pad_210; void* m_pad_218; void* m_pad_220; void* m_pad_228; void* m_pad_230; void* m_pad_238;
    void* m_pad_240; void* m_pad_248; void* m_pad_250; void* m_pad_258; void* m_pad_260; void* m_pad_268; void* m_pad_270; void* m_pad_278;
    void* m_pad_280; void* m_pad_288; void* m_pad_290; void* m_pad_298; void* m_pad_2a0; void* m_pad_2a8; void* m_pad_2b0; void* m_pad_2b8;
    void* m_pad_2c0; void* m_pad_2c8; void* m_pad_2d0; void* m_pad_2d8; void* m_pad_2e0; void* m_pad_2e8; void* m_pad_2f0; void* m_pad_2f8;
    void* m_pad_300; void* m_pad_308; void* m_pad_310; void* m_pad_318; void* m_pad_320; void* m_pad_328; void* m_pad_330; void* m_pad_338;
    void* m_pad_340; void* m_pad_348; void* m_pad_350; void* m_pad_358; void* m_pad_360; void* m_pad_368; void* m_pad_370; void* m_pad_378;
    void* m_pad_380; void* m_pad_388; void* m_pad_390; void* m_pad_398; void* m_pad_3a0; void* m_pad_3a8; void* m_pad_3b0; void* m_pad_3b8;
    void* m_pad_3c0; void* m_pad_3c8; void* m_pad_3d0; void* m_pad_3d8; void* m_pad_3e0; void* m_pad_3e8; void* m_pad_3f0; void* m_pad_3f8;
    void* m_pad_400; void* m_pad_408; void* m_pad_410; void* m_pad_418; void* m_pad_420; void* m_pad_428; void* m_pad_430; void* m_pad_438;
    void* m_pad_440; void* m_pad_448; void* m_pad_450; void* m_pad_458; void* m_pad_460; void* m_pad_468; void* m_pad_470; void* m_pad_478;
    void* m_pad_480; void* m_pad_488; void* m_pad_490; void* m_pad_498; void* m_pad_4a0; void* m_pad_4a8; void* m_pad_4b0; void* m_pad_4b8;
    void* m_pad_4c0; void* m_pad_4c8; void* m_pad_4d0; void* m_pad_4d8; void* m_pad_4e0; void* m_pad_4e8; void* m_pad_4f0; void* m_pad_4f8;
    void* m_pad_500; void* m_pad_508; void* m_pad_510; void* m_pad_518; void* m_pad_520; void* m_pad_528; void* m_pad_530; void* m_pad_538;
    void* m_pad_540; void* m_pad_548; void* m_pad_550; void* m_pad_558; void* m_pad_560; void* m_pad_568; void* m_pad_570; void* m_pad_578;
    void* m_pad_580; void* m_pad_588; void* m_pad_590; void* m_pad_598; void* m_pad_5a0; void* m_pad_5a8; void* m_pad_5b0; void* m_pad_5b8;
    void* m_pad_5c0; void* m_pad_5c8; void* m_pad_5d0; void* m_pad_5d8; void* m_pad_5e0; void* m_pad_5e8; void* m_pad_5f0; void* m_pad_5f8;
    void* m_pad_600; void* m_pad_608; void* m_pad_610; void* m_pad_618; void* m_pad_620; void* m_pad_628; void* m_pad_630; void* m_pad_638;
    void* m_pad_640; void* m_pad_648; void* m_pad_650; void* m_pad_658; void* m_pad_660; void* m_pad_668; void* m_pad_670; void* m_pad_678;
    void* m_pad_680; void* m_pad_688; void* m_pad_690; void* m_pad_698; void* m_pad_6a0; void* m_pad_6a8; void* m_pad_6b0; void* m_pad_6b8;
    void* m_pad_6c0; void* m_pad_6c8; void* m_pad_6d0; void* m_pad_6d8; void* m_pad_6e0; void* m_pad_6e8; void* m_pad_6f0; void* m_pad_6f8;
    void* m_pad_700; void* m_pad_708; void* m_pad_710; void* m_pad_718; void* m_pad_720; void* m_pad_728; void* m_pad_730; void* m_pad_738;
    void* m_pad_740; void* m_pad_748; void* m_pad_750; void* m_pad_758; void* m_pad_760; void* m_pad_768; void* m_pad_770; void* m_pad_778;
    void* m_pad_780; void* m_pad_788; void* m_pad_790; void* m_pad_798; void* m_pad_7a0; void* m_pad_7a8; void* m_pad_7b0; void* m_pad_7b8;
    void* m_pad_7c0; void* m_pad_7c8; void* m_pad_7d0; void* m_pad_7d8; void* m_pad_7e0; void* m_pad_7e8; void* m_pad_7f0; void* m_pad_7f8;
    void* m_pad_800; void* m_pad_808; void* m_pad_810; void* m_pad_818; void* m_pad_820; void* m_pad_828; void* m_pad_830; void* m_pad_838;
    void* m_pad_840; void* m_pad_848; void* m_pad_850; void* m_pad_858; void* m_pad_860; void* m_pad_868; void* m_pad_870; void* m_pad_878;
    void* m_pad_880; void* m_pad_888; void* m_pad_890; void* m_pad_898; void* m_pad_8a0; void* m_pad_8a8; void* m_pad_8b0; void* m_pad_8b8;
    void* m_pad_8c0; void* m_pad_8c8; void* m_pad_8d0; void* m_pad_8d8; void* m_pad_8e0; void* m_pad_8e8; void* m_pad_8f0; void* m_pad_8f8;
    void* m_pad_900; void* m_pad_908; void* m_pad_910; void* m_pad_918; void* m_pad_920; void* m_pad_928; void* m_pad_930; void* m_pad_938;
    void* m_pad_940; void* m_pad_948; void* m_pad_950; void* m_pad_958; void* m_pad_960; void* m_pad_968; void* m_pad_970; void* m_pad_978;
    void* m_pad_980; void* m_pad_988; void* m_pad_990; void* m_pad_998; void* m_pad_9a0; void* m_pad_9a8; void* m_pad_9b0; void* m_pad_9b8;
    void* m_pad_9c0; void* m_pad_9c8; void* m_pad_9d0; void* m_pad_9d8; void* m_pad_9e0; void* m_pad_9e8; void* m_pad_9f0; void* m_pad_9f8;
    void* m_pad_a00; void* m_pad_a08; void* m_pad_a10; void* m_pad_a18; void* m_pad_a20; void* m_pad_a28; void* m_pad_a30; void* m_pad_a38;
    void* m_pad_a40; void* m_pad_a48; void* m_pad_a50; void* m_pad_a58; void* m_pad_a60; void* m_pad_a68; void* m_pad_a70; void* m_pad_a78;
    void* m_pad_a80; void* m_pad_a88; void* m_pad_a90; void* m_pad_a98; void* m_pad_aa0; void* m_pad_aa8; void* m_pad_ab0; void* m_pad_ab8;
    void* m_pad_ac0; void* m_pad_ac8; void* m_pad_ad0; void* m_pad_ad8; void* m_pad_ae0; void* m_pad_ae8; void* m_pad_af0; void* m_pad_af8;
    void* m_pad_b00; void* m_pad_b08; void* m_pad_b10; void* m_pad_b18; void* m_pad_b20; void* m_pad_b28; void* m_pad_b30; void* m_pad_b38;
    void* m_pad_b40; void* m_pad_b48; void* m_pad_b50; void* m_pad_b58; void* m_pad_b60; void* m_pad_b68; void* m_pad_b70; void* m_pad_b78;
    void* m_pad_b80; void* m_pad_b88; void* m_pad_b90; void* m_pad_b98; void* m_pad_ba0; void* m_pad_ba8; void* m_pad_bb0; void* m_pad_bb8;
    void* m_pad_bc0; void* m_pad_bc8; void* m_pad_bd0; void* m_pad_bd8; void* m_pad_be0; void* m_pad_be8; void* m_pad_bf0; void* m_pad_bf8;
    void* m_pad_c00; void* m_pad_c08; void* m_pad_c10; void* m_pad_c18; void* m_pad_c20; void* m_pad_c28; void* m_pad_c30; void* m_pad_c38;
    void* m_pad_c40; void* m_pad_c48; void* m_pad_c50; void* m_pad_c58; void* m_pad_c60; void* m_pad_c68; void* m_pad_c70; void* m_pad_c78;
    void* m_pad_c80; void* m_pad_c88; void* m_pad_c90; void* m_pad_c98; void* m_pad_ca0; void* m_pad_ca8; void* m_pad_cb0; void* m_pad_cb8;
    void* m_pad_cc0; void* m_pad_cc8; void* m_pad_cd0; void* m_pad_cd8; void* m_pad_ce0; void* m_pad_ce8; void* m_pad_cf0; void* m_pad_cf8;
    void* m_pad_d00; void* m_pad_d08; void* m_pad_d10; void* m_pad_d18; void* m_pad_d20; void* m_pad_d28; void* m_pad_d30; void* m_pad_d38;
    void* m_pad_d40; void* m_pad_d48; void* m_pad_d50; void* m_pad_d58; void* m_pad_d60; void* m_pad_d68; void* m_pad_d70; void* m_pad_d78;
    void* m_pad_d80; void* m_pad_d88; void* m_pad_d90; void* m_pad_d98; void* m_pad_da0; void* m_pad_da8; void* m_pad_db0; void* m_pad_db8;
    void* m_pad_dc0; void* m_pad_dc8; void* m_pad_dd0; void* m_pad_dd8; void* m_pad_de0; void* m_pad_de8; void* m_pad_df0; void* m_pad_df8;
    void* m_pad_e00; void* m_pad_e08; void* m_pad_e10; void* m_pad_e18; void* m_pad_e20; void* m_pad_e28; void* m_pad_e30; void* m_pad_e38;
    void* m_pad_e40; void* m_pad_e48; void* m_pad_e50; void* m_pad_e58; void* m_pad_e60; void* m_pad_e68; void* m_pad_e70; void* m_pad_e78;
    void* m_pad_e80; void* m_pad_e88; void* m_pad_e90; void* m_pad_e98; void* m_pad_ea0; void* m_pad_ea8; void* m_pad_eb0; void* m_pad_eb8;
    void* m_pad_ec0; void* m_pad_ec8; void* m_pad_ed0; void* m_pad_ed8; void* m_pad_ee0; void* m_pad_ee8; void* m_pad_ef0; void* m_pad_ef8;
    void* m_pad_f00; void* m_pad_f08; void* m_pad_f10; void* m_pad_f18; void* m_pad_f20; void* m_pad_f28; void* m_pad_f30; void* m_pad_f38;
    void* m_pad_f40; void* m_pad_f48; void* m_pad_f50; void* m_pad_f58; void* m_pad_f60; void* m_pad_f68; void* m_pad_f70; void* m_pad_f78;
    void* m_pad_f80; void* m_pad_f88; void* m_pad_f90; void* m_pad_f98; void* m_pad_fa0; void* m_pad_fa8; void* m_pad_fb0; void* m_pad_fb8;
    void* m_pad_fc0; void* m_pad_fc8; void* m_pad_fd0; void* m_pad_fd8; void* m_pad_fe0; void* m_pad_fe8; void* m_pad_ff0; void* m_pad_ff8;
    void* m_pad_1000; void* m_pad_1008; void* m_pad_1010; void* m_pad_1018; void* m_pad_1020; void* m_pad_1028; void* m_pad_1030; void* m_pad_1038;
    void* m_pad_1040; void* m_pad_1048; void* m_pad_1050; void* m_pad_1058; void* m_pad_1060; void* m_pad_1068; void* m_pad_1070; void* m_pad_1078;
    void* m_pad_1080; void* m_pad_1088; void* m_pad_1090; void* m_pad_1098; void* m_pad_10a0; void* m_pad_10a8; void* m_pad_10b0; void* m_pad_10b8;
    void* m_pad_10c0; void* m_pad_10c8; void* m_pad_10d0; void* m_pad_10d8; void* m_pad_10e0; void* m_pad_10e8; void* m_pad_10f0; void* m_pad_10f8;
    void* m_pad_1100; void* m_pad_1108; void* m_pad_1110; void* m_pad_1118; void* m_pad_1120; void* m_pad_1128; void* m_pad_1130; void* m_pad_1138;
    void* m_pad_1140; void* m_pad_1148; void* m_pad_1150; void* m_pad_1158; void* m_pad_1160; void* m_pad_1168; void* m_pad_1170; void* m_pad_1178;
    void* m_pad_1180; void* m_pad_1188; void* m_pad_1190; void* m_pad_1198; void* m_pad_11a0; void* m_pad_11a8; void* m_pad_11b0; void* m_pad_11b8;
    void* m_pad_11c0; void* m_pad_11c8; void* m_pad_11d0; void* m_pad_11d8; void* m_pad_11e0; void* m_pad_11e8; void* m_pad_11f0; void* m_pad_11f8;
    void* m_pad_1200; void* m_pad_1208; void* m_pad_1210; void* m_pad_1218; void* m_pad_1220; void* m_pad_1228; void* m_pad_1230; void* m_pad_1238;
    void* m_pad_1240; void* m_pad_1248; void* m_pad_1250; void* m_pad_1258; void* m_pad_1260; void* m_pad_1268; void* m_pad_1270; void* m_pad_1278;
    void* m_pad_1280; void* m_pad_1288; void* m_pad_1290; void* m_pad_1298; void* m_pad_12a0; void* m_pad_12a8; void* m_pad_12b0; void* m_pad_12b8;
    void* m_pad_12c0; void* m_pad_12c8; void* m_pad_12d0; void* m_pad_12d8; void* m_pad_12e0; void* m_pad_12e8; void* m_pad_12f0; void* m_pad_12f8;
    void* m_pad_1300; void* m_pad_1308; void* m_pad_1310; void* m_pad_1318; void* m_pad_1320; void* m_pad_1328; void* m_pad_1330; void* m_pad_1338;
    void* m_pad_1340; void* m_pad_1348; void* m_pad_1350; void* m_pad_1358; void* m_pad_1360; void* m_pad_1368; void* m_pad_1370; void* m_pad_1378;
    void* m_pad_1380; void* m_pad_1388; void* m_pad_1390; void* m_pad_1398; void* m_pad_13a0; void* m_pad_13a8; void* m_pad_13b0; void* m_pad_13b8;
    void* m_pad_13c0; void* m_pad_13c8; void* m_pad_13d0; void* m_pad_13d8; void* m_pad_13e0; void* m_pad_13e8; void* m_pad_13f0; void* m_pad_13f8;
    void* m_pad_1400; void* m_pad_1408; void* m_pad_1410; void* m_pad_1418; void* m_pad_1420; void* m_pad_1428; void* m_pad_1430; void* m_pad_1438;
    void* m_pad_1440; void* m_pad_1448; void* m_pad_1450; void* m_pad_1458; void* m_pad_1460; void* m_pad_1468; void* m_pad_1470; void* m_pad_1478;
    void* m_pad_1480; void* m_pad_1488; void* m_pad_1490; void* m_pad_1498; void* m_pad_14a0; void* m_pad_14a8; void* m_pad_14b0; void* m_pad_14b8;
    void* m_pad_14c0; void* m_pad_14c8; void* m_pad_14d0; void* m_pad_14d8; void* m_pad_14e0; void* m_pad_14e8; void* m_pad_14f0; void* m_pad_14f8;
    void* m_pad_1500; void* m_pad_1508; void* m_pad_1510; void* m_pad_1518; void* m_pad_1520; void* m_pad_1528; void* m_pad_1530; void* m_pad_1538;
    void* m_pad_1540; void* m_pad_1548; void* m_pad_1550; void* m_pad_1558; void* m_pad_1560; void* m_pad_1568; void* m_pad_1570; void* m_pad_1578;
    void* m_pad_1580; void* m_pad_1588; void* m_pad_1590; void* m_pad_1598; void* m_pad_15a0; void* m_pad_15a8; void* m_pad_15b0; void* m_pad_15b8;
    void* m_pad_15c0; void* m_pad_15c8; void* m_pad_15d0; void* m_pad_15d8; void* m_pad_15e0; void* m_pad_15e8; void* m_pad_15f0; void* m_pad_15f8;
    void* m_pad_1600; void* m_pad_1608; void* m_pad_1610; void* m_pad_1618; void* m_pad_1620; void* m_pad_1628; void* m_pad_1630; void* m_pad_1638;
    void* m_pad_1640; void* m_pad_1648; void* m_pad_1650; void* m_pad_1658; void* m_pad_1660; void* m_pad_1668; void* m_pad_1670; void* m_pad_1678;
    void* m_pad_1680; void* m_pad_1688; void* m_pad_1690; void* m_pad_1698; void* m_pad_16a0; void* m_pad_16a8; void* m_pad_16b0; void* m_pad_16b8;
    void* m_pad_16c0; void* m_pad_16c8; void* m_pad_16d0; void* m_pad_16d8; void* m_pad_16e0; void* m_pad_16e8; void* m_pad_16f0; void* m_pad_16f8;
    void* m_pad_1700; void* m_pad_1708; void* m_pad_1710; void* m_pad_1718; void* m_pad_1720; void* m_pad_1728; void* m_pad_1730; void* m_pad_1738;
    void* m_pad_1740; void* m_pad_1748; void* m_pad_1750; void* m_pad_1758; void* m_pad_1760; void* m_pad_1768; void* m_pad_1770; void* m_pad_1778;
    void* m_pad_1780; void* m_pad_1788; void* m_pad_1790; void* m_pad_1798; void* m_pad_17a0; void* m_pad_17a8; void* m_pad_17b0; void* m_pad_17b8;
    void* m_pad_17c0; void* m_pad_17c8; void* m_pad_17d0; void* m_pad_17d8; void* m_pad_17e0; void* m_pad_17e8; void* m_pad_17f0; void* m_pad_17f8;
    void* m_pad_1800; void* m_pad_1808; void* m_pad_1810; void* m_pad_1818; void* m_pad_1820; void* m_pad_1828; void* m_pad_1830; void* m_pad_1838;
    void* m_pad_1840; void* m_pad_1848; void* m_pad_1850; void* m_pad_1858; void* m_pad_1860; void* m_pad_1868; void* m_pad_1870; void* m_pad_1878;
    void* m_pad_1880; void* m_pad_1888; void* m_pad_1890; void* m_pad_1898; void* m_pad_18a0; void* m_pad_18a8; void* m_pad_18b0; void* m_pad_18b8;
    void* m_pad_18c0; void* m_pad_18c8; void* m_pad_18d0; void* m_pad_18d8; void* m_pad_18e0; void* m_pad_18e8; void* m_pad_18f0; void* m_pad_18f8;
    void* m_pad_1900; void* m_pad_1908; void* m_pad_1910; void* m_pad_1918; void* m_pad_1920; void* m_pad_1928; void* m_pad_1930; void* m_pad_1938;
    void* m_pad_1940; void* m_pad_1948; void* m_pad_1950; void* m_pad_1958; void* m_pad_1960; void* m_pad_1968; void* m_pad_1970; void* m_pad_1978;
    void* m_pad_1980; void* m_pad_1988; void* m_pad_1990; void* m_pad_1998; void* m_pad_19a0; void* m_pad_19a8; void* m_pad_19b0; void* m_pad_19b8;
    void* m_pad_19c0; void* m_pad_19c8; void* m_pad_19d0; void* m_pad_19d8; void* m_pad_19e0; void* m_pad_19e8; void* m_pad_19f0; void* m_pad_19f8;
    void* m_pad_1a00; void* m_pad_1a08; void* m_pad_1a10; void* m_pad_1a18; void* m_pad_1a20; void* m_pad_1a28; void* m_pad_1a30; void* m_pad_1a38;
    void* m_pad_1a40; void* m_pad_1a48; void* m_pad_1a50; void* m_pad_1a58; void* m_pad_1a60; void* m_pad_1a68; void* m_pad_1a70; void* m_pad_1a78;
    void* m_pad_1a80; void* m_pad_1a88; void* m_pad_1a90; void* m_pad_1a98; void* m_pad_1aa0; void* m_pad_1aa8; void* m_pad_1ab0; void* m_pad_1ab8;
    void* m_pad_1ac0; void* m_pad_1ac8; void* m_pad_1ad0; void* m_pad_1ad8; void* m_pad_1ae0; void* m_pad_1ae8; void* m_pad_1af0; void* m_pad_1af8;
    void* m_pad_1b00; void* m_pad_1b08; void* m_pad_1b10; void* m_pad_1b18; void* m_pad_1b20; void* m_pad_1b28; void* m_pad_1b30; void* m_pad_1b38;
    void* m_pad_1b40; void* m_pad_1b48; void* m_pad_1b50; void* m_pad_1b58; void* m_pad_1b60; void* m_pad_1b68; void* m_pad_1b70; void* m_pad_1b78;
    void* m_pad_1b80; void* m_pad_1b88; void* m_pad_1b90; void* m_pad_1b98; void* m_pad_1ba0; void* m_pad_1ba8; void* m_pad_1bb0; void* m_pad_1bb8;
    void* m_pad_1bc0; void* m_pad_1bc8; void* m_pad_1bd0; void* m_pad_1bd8; void* m_pad_1be0; void* m_pad_1be8; void* m_pad_1bf0; void* m_pad_1bf8;
    void* m_pad_1c00; void* m_pad_1c08; void* m_pad_1c10; void* m_pad_1c18; void* m_pad_1c20; void* m_pad_1c28; void* m_pad_1c30; void* m_pad_1c38;
    void* m_pad_1c40; void* m_pad_1c48; void* m_pad_1c50; void* m_pad_1c58; void* m_pad_1c60; void* m_pad_1c68; void* m_pad_1c70; void* m_pad_1c78;
    void* m_pad_1c80; void* m_pad_1c88; void* m_pad_1c90; void* m_pad_1c98; void* m_pad_1ca0; void* m_pad_1ca8; void* m_pad_1cb0; void* m_pad_1cb8;
    void* m_pad_1cc0; void* m_pad_1cc8; void* m_pad_1cd0; void* m_pad_1cd8; void* m_pad_1ce0; void* m_pad_1ce8; void* m_pad_1cf0; void* m_pad_1cf8;
    void* m_pad_1d00; void* m_pad_1d08; void* m_pad_1d10; void* m_pad_1d18; void* m_pad_1d20; void* m_pad_1d28; void* m_pad_1d30; void* m_pad_1d38;
    void* m_pad_1d40; void* m_pad_1d48; void* m_pad_1d50; void* m_pad_1d58; void* m_pad_1d60; void* m_pad_1d68; void* m_pad_1d70; void* m_pad_1d78;
    void* m_pad_1d80; void* m_pad_1d88; void* m_pad_1d90; void* m_pad_1d98; void* m_pad_1da0; void* m_pad_1da8; void* m_pad_1db0; void* m_pad_1db8;
    void* m_pad_1dc0; void* m_pad_1dc8; void* m_pad_1dd0; void* m_pad_1dd8; void* m_pad_1de0; void* m_pad_1de8; void* m_pad_1df0; void* m_pad_1df8;
    void* m_pad_1e00; void* m_pad_1e08; void* m_pad_1e10; void* m_pad_1e18; void* m_pad_1e20; void* m_pad_1e28; void* m_pad_1e30; void* m_pad_1e38;
    void* m_pad_1e40; void* m_pad_1e48; void* m_pad_1e50; void* m_pad_1e58; void* m_pad_1e60; void* m_pad_1e68; void* m_pad_1e70; void* m_pad_1e78;
    void* m_pad_1e80; void* m_pad_1e88; void* m_pad_1e90; void* m_pad_1e98; void* m_pad_1ea0; void* m_pad_1ea8; void* m_pad_1eb0; void* m_pad_1eb8;
    void* m_pad_1ec0; void* m_pad_1ec8; void* m_pad_1ed0; void* m_pad_1ed8; void* m_pad_1ee0; void* m_pad_1ee8; void* m_pad_1ef0; void* m_pad_1ef8;
    void* m_pad_1f00; void* m_pad_1f08; void* m_pad_1f10; void* m_pad_1f18; void* m_pad_1f20; void* m_pad_1f28; void* m_pad_1f30; void* m_pad_1f38;
    void* m_pad_1f40; void* m_pad_1f48; void* m_pad_1f50; void* m_pad_1f58; void* m_pad_1f60; void* m_pad_1f68; void* m_pad_1f70; void* m_pad_1f78;
    void* m_pad_1f80; void* m_pad_1f88; void* m_pad_1f90; void* m_pad_1f98; void* m_pad_1fa0; void* m_pad_1fa8; void* m_pad_1fb0; void* m_pad_1fb8;
    void* m_pad_1fc0; void* m_pad_1fc8; void* m_pad_1fd0; void* m_pad_1fd8; void* m_pad_1fe0; void* m_pad_1fe8; void* m_pad_1ff0; void* m_pad_1ff8;
    void* m_pad_2000; void* m_pad_2008; void* m_pad_2010; void* m_pad_2018; void* m_pad_2020; void* m_pad_2028; void* m_pad_2030; void* m_pad_2038;
    void* m_pad_2040; void* m_pad_2048; void* m_pad_2050; void* m_pad_2058; void* m_pad_2060; void* m_pad_2068; void* m_pad_2070; void* m_pad_2078;
    void* m_pad_2080; void* m_pad_2088; void* m_pad_2090; void* m_pad_2098; void* m_pad_20a0; void* m_pad_20a8; void* m_pad_20b0; void* m_pad_20b8;
    void* m_pad_20c0; void* m_pad_20c8; void* m_pad_20d0; void* m_pad_20d8; void* m_pad_20e0; void* m_pad_20e8; void* m_pad_20f0; void* m_pad_20f8;
    void* m_pad_2100; void* m_pad_2108; void* m_pad_2110; void* m_pad_2118; void* m_pad_2120; void* m_pad_2128; void* m_pad_2130; void* m_pad_2138;
    void* m_pad_2140; void* m_pad_2148; void* m_pad_2150; void* m_pad_2158; void* m_pad_2160; void* m_pad_2168; void* m_pad_2170; void* m_pad_2178;
    void* m_pad_2180; void* m_pad_2188; void* m_pad_2190; void* m_pad_2198; void* m_pad_21a0; void* m_pad_21a8; void* m_pad_21b0; void* m_pad_21b8;
    void* m_pad_21c0; void* m_pad_21c8; void* m_pad_21d0; void* m_pad_21d8; void* m_pad_21e0; void* m_pad_21e8; void* m_pad_21f0; void* m_pad_21f8;
    void* m_pad_2200; void* m_pad_2208; void* m_pad_2210; void* m_pad_2218; void* m_pad_2220; void* m_pad_2228; void* m_pad_2230; void* m_pad_2238;
    void* m_pad_2240; void* m_pad_2248; void* m_pad_2250; void* m_pad_2258; void* m_pad_2260; void* m_pad_2268; void* m_pad_2270; void* m_pad_2278;
    void* m_pad_2280; void* m_pad_2288; void* m_pad_2290; void* m_pad_2298; void* m_pad_22a0; void* m_pad_22a8; void* m_pad_22b0; void* m_pad_22b8;
    void* m_pad_22c0; void* m_pad_22c8; void* m_pad_22d0; void* m_pad_22d8; void* m_pad_22e0; void* m_pad_22e8; void* m_pad_22f0; void* m_pad_22f8;
    void* m_pad_2300; void* m_pad_2308; void* m_pad_2310; void* m_pad_2318; void* m_pad_2320; void* m_pad_2328; void* m_pad_2330; void* m_pad_2338;
    void* m_pad_2340; void* m_pad_2348; void* m_pad_2350; void* m_pad_2358; void* m_pad_2360; void* m_pad_2368; void* m_pad_2370; void* m_pad_2378;
    void* m_pad_2380; void* m_pad_2388; void* m_pad_2390; void* m_pad_2398; void* m_pad_23a0; void* m_pad_23a8; void* m_pad_23b0; void* m_pad_23b8;
    void* m_pad_23c0; void* m_pad_23c8; void* m_pad_23d0; void* m_pad_23d8; void* m_pad_23e0; void* m_pad_23e8; void* m_pad_23f0; void* m_pad_23f8;
    void* m_pad_2400; void* m_pad_2408; void* m_pad_2410; void* m_pad_2418; void* m_pad_2420; void* m_pad_2428; void* m_pad_2430; void* m_pad_2438;
    void* m_pad_2440; void* m_pad_2448; void* m_pad_2450; void* m_pad_2458; void* m_pad_2460; void* m_pad_2468; void* m_pad_2470; void* m_pad_2478;
    void* m_pad_2480; void* m_pad_2488; void* m_pad_2490; void* m_pad_2498; void* m_pad_24a0; void* m_pad_24a8; void* m_pad_24b0; void* m_pad_24b8;
    void* m_pad_24c0; void* m_pad_24c8; void* m_pad_24d0; void* m_pad_24d8; void* m_pad_24e0; void* m_pad_24e8; void* m_pad_24f0; void* m_pad_24f8;
    void* m_pad_2500; void* m_pad_2508; void* m_pad_2510; void* m_pad_2518; void* m_pad_2520; void* m_pad_2528; void* m_pad_2530; void* m_pad_2538;
    void* m_pad_2540; void* m_pad_2548; void* m_pad_2550; void* m_pad_2558; void* m_pad_2560; void* m_pad_2568; void* m_pad_2570; void* m_pad_2578;
    void* m_pad_2580; void* m_pad_2588; void* m_pad_2590; void* m_pad_2598; void* m_pad_25a0; void* m_pad_25a8; void* m_pad_25b0; void* m_pad_25b8;
    void* m_pad_25c0; void* m_pad_25c8; void* m_pad_25d0; void* m_pad_25d8; void* m_pad_25e0; void* m_pad_25e8; void* m_pad_25f0; void* m_pad_25f8;
    void* m_pad_2600; void* m_pad_2608; void* m_pad_2610; void* m_pad_2618; void* m_pad_2620; void* m_pad_2628; void* m_pad_2630; void* m_pad_2638;
    void* m_pad_2640; void* m_pad_2648; void* m_pad_2650; void* m_pad_2658; void* m_pad_2660; void* m_pad_2668; void* m_pad_2670; void* m_pad_2678;
    void* m_pad_2680; void* m_pad_2688; void* m_pad_2690; void* m_pad_2698; void* m_pad_26a0; void* m_pad_26a8; void* m_pad_26b0; void* m_pad_26b8;
    void* m_pad_26c0; void* m_pad_26c8; void* m_pad_26d0; void* m_pad_26d8; void* m_pad_26e0; void* m_pad_26e8; void* m_pad_26f0; void* m_pad_26f8;
    void* m_pad_2700; void* m_pad_2708; void* m_pad_2710; void* m_pad_2718; void* m_pad_2720; void* m_pad_2728; void* m_pad_2730; void* m_pad_2738;
    void* m_pad_2740; void* m_pad_2748; void* m_pad_2750; void* m_pad_2758; void* m_pad_2760; void* m_pad_2768; void* m_pad_2770; void* m_pad_2778;
    void* m_pad_2780; void* m_pad_2788; void* m_pad_2790; void* m_pad_2798; void* m_pad_27a0; void* m_pad_27a8; void* m_pad_27b0; void* m_pad_27b8;
    void* m_pad_27c0; void* m_pad_27c8; void* m_pad_27d0; void* m_pad_27d8; void* m_pad_27e0; void* m_pad_27e8; void* m_pad_27f0; void* m_pad_27f8;
    void* m_pad_2800; void* m_pad_2808; void* m_pad_2810; void* m_pad_2818; void* m_pad_2820; void* m_pad_2828; void* m_pad_2830; void* m_pad_2838;
    void* m_pad_2840; void* m_pad_2848; void* m_pad_2850; void* m_pad_2858; void* m_pad_2860; void* m_pad_2868; void* m_pad_2870; void* m_pad_2878;
    void* m_pad_2880; void* m_pad_2888; void* m_pad_2890; void* m_pad_2898; void* m_pad_28a0; void* m_pad_28a8; void* m_pad_28b0; void* m_pad_28b8;
    void* m_pad_28c0; void* m_pad_28c8; void* m_pad_28d0; void* m_pad_28d8; void* m_pad_28e0; void* m_pad_28e8; void* m_pad_28f0; void* m_pad_28f8;
    void* m_pad_2900; void* m_pad_2908; void* m_pad_2910; void* m_pad_2918; void* m_pad_2920; void* m_pad_2928; void* m_pad_2930; void* m_pad_2938;
    void* m_pad_2940; void* m_pad_2948; void* m_pad_2950; void* m_pad_2958; void* m_pad_2960; void* m_pad_2968; void* m_pad_2970; void* m_pad_2978;
    void* m_pad_2980; void* m_pad_2988; void* m_pad_2990; void* m_pad_2998; void* m_pad_29a0; void* m_pad_29a8; void* m_pad_29b0; void* m_pad_29b8;
    void* m_pad_29c0; void* m_pad_29c8; void* m_pad_29d0; void* m_pad_29d8; void* m_pad_29e0; void* m_pad_29e8; void* m_pad_29f0; void* m_pad_29f8;
    void* m_pad_2a00; void* m_pad_2a08; void* m_pad_2a10; void* m_pad_2a18; void* m_pad_2a20; void* m_pad_2a28; void* m_pad_2a30; void* m_pad_2a38;
    void* m_pad_2a40; void* m_pad_2a48; void* m_pad_2a50; void* m_pad_2a58; void* m_pad_2a60; void* m_pad_2a68; void* m_pad_2a70; void* m_pad_2a78;
    void* m_pad_2a80; void* m_pad_2a88; void* m_pad_2a90; void* m_pad_2a98; void* m_pad_2aa0; void* m_pad_2aa8; void* m_pad_2ab0; void* m_pad_2ab8;
    void* m_pad_2ac0; void* m_pad_2ac8; void* m_pad_2ad0; void* m_pad_2ad8; void* m_pad_2ae0; void* m_pad_2ae8; void* m_pad_2af0; void* m_pad_2af8;
    void* m_pad_2b00; void* m_pad_2b08; void* m_pad_2b10; void* m_pad_2b18; void* m_pad_2b20; void* m_pad_2b28; void* m_pad_2b30; void* m_pad_2b38;
    void* m_pad_2b40; void* m_pad_2b48; void* m_pad_2b50; void* m_pad_2b58; void* m_pad_2b60; void* m_pad_2b68; void* m_pad_2b70; void* m_pad_2b78;
    void* m_pad_2b80; void* m_pad_2b88; void* m_pad_2b90; void* m_pad_2b98; void* m_pad_2ba0; void* m_pad_2ba8; void* m_pad_2bb0; void* m_pad_2bb8;
    void* m_pad_2bc0; void* m_pad_2bc8; void* m_pad_2bd0; void* m_pad_2bd8; void* m_pad_2be0; void* m_pad_2be8; void* m_pad_2bf0; void* m_pad_2bf8;
    void* m_pad_2c00; void* m_pad_2c08; void* m_pad_2c10; void* m_pad_2c18; void* m_pad_2c20; void* m_pad_2c28; void* m_pad_2c30; void* m_pad_2c38;
    void* m_pad_2c40; void* m_pad_2c48; void* m_pad_2c50; void* m_pad_2c58; void* m_pad_2c60; void* m_pad_2c68; void* m_pad_2c70; void* m_pad_2c78;
    void* m_pad_2c80; void* m_pad_2c88; void* m_pad_2c90; void* m_pad_2c98; void* m_pad_2ca0; void* m_pad_2ca8; void* m_pad_2cb0; void* m_pad_2cb8;
    void* m_pad_2cc0; void* m_pad_2cc8; void* m_pad_2cd0; void* m_pad_2cd8; void* m_pad_2ce0; void* m_pad_2ce8; void* m_pad_2cf0; void* m_pad_2cf8;
    void* m_pad_2d00; void* m_pad_2d08; void* m_pad_2d10; void* m_pad_2d18; void* m_pad_2d20; void* m_pad_2d28; void* m_pad_2d30; void* m_pad_2d38;
    void* m_pad_2d40; void* m_pad_2d48; void* m_pad_2d50; void* m_pad_2d58; void* m_pad_2d60; void* m_pad_2d68; void* m_pad_2d70; void* m_pad_2d78;
    void* m_pad_2d80; void* m_pad_2d88; void* m_pad_2d90; void* m_pad_2d98; void* m_pad_2da0; void* m_pad_2da8; void* m_pad_2db0; void* m_pad_2db8;
    void* m_pad_2dc0; void* m_pad_2dc8; void* m_pad_2dd0; void* m_pad_2dd8; void* m_pad_2de0; void* m_pad_2de8; void* m_pad_2df0; void* m_pad_2df8;
    void* m_pad_2e00; void* m_pad_2e08; void* m_pad_2e10; void* m_pad_2e18; void* m_pad_2e20; void* m_pad_2e28; void* m_pad_2e30; void* m_pad_2e38;
    void* m_pad_2e40; void* m_pad_2e48; void* m_pad_2e50; void* m_pad_2e58; void* m_pad_2e60; void* m_pad_2e68; void* m_pad_2e70; void* m_pad_2e78;
    void* m_pad_2e80; void* m_pad_2e88; void* m_pad_2e90; void* m_pad_2e98; void* m_pad_2ea0; void* m_pad_2ea8; void* m_pad_2eb0; void* m_pad_2eb8;
    void* m_pad_2ec0; void* m_pad_2ec8; void* m_pad_2ed0; void* m_pad_2ed8; void* m_pad_2ee0; void* m_pad_2ee8; void* m_pad_2ef0; void* m_pad_2ef8;
    void* m_pad_2f00; void* m_pad_2f08; void* m_pad_2f10; void* m_pad_2f18; void* m_pad_2f20; void* m_pad_2f28; void* m_pad_2f30; void* m_pad_2f38;
    void* m_pad_2f40; void* m_pad_2f48; void* m_pad_2f50; void* m_pad_2f58; void* m_pad_2f60; void* m_pad_2f68; void* m_pad_2f70; void* m_pad_2f78;
    void* m_pad_2f80; void* m_pad_2f88; void* m_pad_2f90; void* m_pad_2f98; void* m_pad_2fa0; void* m_pad_2fa8; void* m_pad_2fb0; void* m_pad_2fb8;
    void* m_pad_2fc0; void* m_pad_2fc8; void* m_pad_2fd0; void* m_pad_2fd8; void* m_pad_2fe0; void* m_pad_2fe8; void* m_pad_2ff0; void* m_pad_2ff8;
    void* m_pad_3000; void* m_pad_3008; void* m_pad_3010; void* m_pad_3018; void* m_pad_3020; void* m_pad_3028; void* m_pad_3030; void* m_pad_3038;
    void* m_pad_3040; void* m_pad_3048; void* m_pad_3050; void* m_pad_3058; void* m_pad_3060; void* m_pad_3068; void* m_pad_3070; void* m_pad_3078;
    void* m_pad_3080; void* m_pad_3088; void* m_pad_3090; void* m_pad_3098; void* m_pad_30a0; void* m_pad_30a8; void* m_pad_30b0; void* m_pad_30b8;
    void* m_pad_30c0; void* m_pad_30c8; void* m_pad_30d0; void* m_pad_30d8; void* m_pad_30e0; void* m_pad_30e8; void* m_pad_30f0; void* m_pad_30f8;
    void* m_pad_3100; void* m_pad_3108; void* m_pad_3110; void* m_pad_3118; void* m_pad_3120; void* m_pad_3128; void* m_pad_3130; void* m_pad_3138;
    void* m_pad_3140; void* m_pad_3148; void* m_pad_3150; void* m_pad_3158; void* m_pad_3160; void* m_pad_3168; void* m_pad_3170; void* m_pad_3178;
    void* m_pad_3180; void* m_pad_3188; void* m_pad_3190; void* m_pad_3198; void* m_pad_31a0; void* m_pad_31a8; void* m_pad_31b0; void* m_pad_31b8;
    void* m_pad_31c0; void* m_pad_31c8; void* m_pad_31d0; void* m_pad_31d8; void* m_pad_31e0; void* m_pad_31e8; void* m_pad_31f0; void* m_pad_31f8;
    void* m_pad_3200; void* m_pad_3208; void* m_pad_3210; void* m_pad_3218; void* m_pad_3220; void* m_pad_3228; void* m_pad_3230; void* m_pad_3238;
    void* m_pad_3240; void* m_pad_3248; void* m_pad_3250; void* m_pad_3258; void* m_pad_3260; void* m_pad_3268; void* m_pad_3270; void* m_pad_3278;
    void* m_pad_3280; void* m_pad_3288; void* m_pad_3290; void* m_pad_3298; void* m_pad_32a0; void* m_pad_32a8; void* m_pad_32b0; void* m_pad_32b8;
    void* m_pad_32c0; void* m_pad_32c8; void* m_pad_32d0; void* m_pad_32d8; void* m_pad_32e0; void* m_pad_32e8; void* m_pad_32f0; void* m_pad_32f8;
    void* m_pad_3300; void* m_pad_3308; void* m_pad_3310; void* m_pad_3318; void* m_pad_3320; void* m_pad_3328; void* m_pad_3330; void* m_pad_3338;
    void* m_pad_3340; void* m_pad_3348; void* m_pad_3350; void* m_pad_3358; void* m_pad_3360; void* m_pad_3368; void* m_pad_3370; void* m_pad_3378;
    void* m_pad_3380; void* m_pad_3388; void* m_pad_3390; void* m_pad_3398; void* m_pad_33a0; void* m_pad_33a8; void* m_pad_33b0; void* m_pad_33b8;
    void* m_pad_33c0; void* m_pad_33c8; void* m_pad_33d0; void* m_pad_33d8; void* m_pad_33e0; void* m_pad_33e8; void* m_pad_33f0; void* m_pad_33f8;
    void* m_pad_3400; void* m_pad_3408; void* m_pad_3410; void* m_pad_3418; void* m_pad_3420; void* m_pad_3428; void* m_pad_3430; void* m_pad_3438;
    void* m_pad_3440; void* m_pad_3448; void* m_pad_3450; void* m_pad_3458; void* m_pad_3460; void* m_pad_3468; void* m_pad_3470; void* m_pad_3478;
    void* m_pad_3480; void* m_pad_3488; void* m_pad_3490; void* m_pad_3498; void* m_pad_34a0; void* m_pad_34a8; void* m_pad_34b0; void* m_pad_34b8;
    void* m_pad_34c0; void* m_pad_34c8; void* m_pad_34d0; void* m_pad_34d8; void* m_pad_34e0; void* m_pad_34e8; void* m_pad_34f0; void* m_pad_34f8;
    void* m_pad_3500; void* m_pad_3508; void* m_pad_3510; void* m_pad_3518; void* m_pad_3520; void* m_pad_3528; void* m_pad_3530; void* m_pad_3538;
    void* m_pad_3540; void* m_pad_3548; void* m_pad_3550; void* m_pad_3558; void* m_pad_3560; void* m_pad_3568; void* m_pad_3570; void* m_pad_3578;
    void* m_pad_3580; void* m_pad_3588; void* m_pad_3590; void* m_pad_3598; void* m_pad_35a0; void* m_pad_35a8; void* m_pad_35b0; void* m_pad_35b8;
    void* m_pad_35c0; void* m_pad_35c8; void* m_pad_35d0; void* m_pad_35d8; void* m_pad_35e0; void* m_pad_35e8; void* m_pad_35f0; void* m_pad_35f8;
    void* m_pad_3600; void* m_pad_3608; void* m_pad_3610; void* m_pad_3618; void* m_pad_3620; void* m_pad_3628; void* m_pad_3630; void* m_pad_3638;
    void* m_pad_3640; void* m_pad_3648; void* m_pad_3650; void* m_pad_3658; void* m_pad_3660; void* m_pad_3668; void* m_pad_3670; void* m_pad_3678;
    void* m_pad_3680; void* m_pad_3688; void* m_pad_3690; void* m_pad_3698; void* m_pad_36a0; void* m_pad_36a8; void* m_pad_36b0; void* m_pad_36b8;
    void* m_pad_36c0; void* m_pad_36c8; void* m_pad_36d0; void* m_pad_36d8; void* m_pad_36e0; void* m_pad_36e8; void* m_pad_36f0; void* m_pad_36f8;
    void* m_pad_3700; void* m_pad_3708; void* m_pad_3710; void* m_pad_3718; void* m_pad_3720; void* m_pad_3728; void* m_pad_3730; void* m_pad_3738;
    void* m_pad_3740; void* m_pad_3748; void* m_pad_3750; void* m_pad_3758; void* m_pad_3760; void* m_pad_3768; void* m_pad_3770; void* m_pad_3778;
    void* m_pad_3780; void* m_pad_3788; void* m_pad_3790; void* m_pad_3798; void* m_pad_37a0; void* m_pad_37a8; void* m_pad_37b0; void* m_pad_37b8;
    void* m_pad_37c0; void* m_pad_37c8; void* m_pad_37d0; void* m_pad_37d8; void* m_pad_37e0; void* m_pad_37e8; void* m_pad_37f0; void* m_pad_37f8;
    void* m_pad_3800; void* m_pad_3808; void* m_pad_3810; void* m_pad_3818; void* m_pad_3820; void* m_pad_3828; void* m_pad_3830; void* m_pad_3838;
    void* m_pad_3840; void* m_pad_3848; void* m_pad_3850; void* m_pad_3858; void* m_pad_3860; void* m_pad_3868; void* m_pad_3870; void* m_pad_3878;
    void* m_pad_3880; void* m_pad_3888; void* m_pad_3890; void* m_pad_3898; void* m_pad_38a0; void* m_pad_38a8; void* m_pad_38b0; void* m_pad_38b8;
    void* m_pad_38c0; void* m_pad_38c8; void* m_pad_38d0; void* m_pad_38d8; void* m_pad_38e0; void* m_pad_38e8; void* m_pad_38f0; void* m_pad_38f8;
    void* m_pad_3900; void* m_pad_3908; void* m_pad_3910; void* m_pad_3918; void* m_pad_3920; void* m_pad_3928; void* m_pad_3930; void* m_pad_3938;
    void* m_pad_3940; void* m_pad_3948; void* m_pad_3950; void* m_pad_3958; void* m_pad_3960; void* m_pad_3968; void* m_pad_3970; void* m_pad_3978;
    void* m_pad_3980; void* m_pad_3988; void* m_pad_3990; void* m_pad_3998; void* m_pad_39a0; void* m_pad_39a8; void* m_pad_39b0; void* m_pad_39b8;
    void* m_pad_39c0; void* m_pad_39c8; void* m_pad_39d0; void* m_pad_39d8; void* m_pad_39e0; void* m_pad_39e8; void* m_pad_39f0; void* m_pad_39f8;
    void* m_pad_3a00; void* m_pad_3a08; void* m_pad_3a10; void* m_pad_3a18; void* m_pad_3a20; void* m_pad_3a28; void* m_pad_3a30; void* m_pad_3a38;
    void* m_pad_3a40; void* m_pad_3a48; void* m_pad_3a50; void* m_pad_3a58; void* m_pad_3a60; void* m_pad_3a68; void* m_pad_3a70; void* m_pad_3a78;
    void* m_pad_3a80; void* m_pad_3a88; void* m_pad_3a90; void* m_pad_3a98; void* m_pad_3aa0; void* m_pad_3aa8; void* m_pad_3ab0; void* m_pad_3ab8;
    void* m_pad_3ac0; void* m_pad_3ac8; void* m_pad_3ad0; void* m_pad_3ad8; void* m_pad_3ae0; void* m_pad_3ae8; void* m_pad_3af0; void* m_pad_3af8;
    void* m_pad_3b00; void* m_pad_3b08; void* m_pad_3b10; void* m_pad_3b18; void* m_pad_3b20; void* m_pad_3b28; void* m_pad_3b30; void* m_pad_3b38;
    void* m_pad_3b40; void* m_pad_3b48; void* m_pad_3b50; void* m_pad_3b58; void* m_pad_3b60; void* m_pad_3b68; void* m_pad_3b70; void* m_pad_3b78;
    void* m_pad_3b80; void* m_pad_3b88; void* m_pad_3b90; void* m_pad_3b98; void* m_pad_3ba0; void* m_pad_3ba8; void* m_pad_3bb0; void* m_pad_3bb8;
    void* m_pad_3bc0; void* m_pad_3bc8; void* m_pad_3bd0; void* m_pad_3bd8; void* m_pad_3be0; void* m_pad_3be8; void* m_pad_3bf0; void* m_pad_3bf8;
    void* m_pad_3c00; void* m_pad_3c08; void* m_pad_3c10; void* m_pad_3c18; void* m_pad_3c20; void* m_pad_3c28; void* m_pad_3c30; void* m_pad_3c38;
    void* m_pad_3c40; void* m_pad_3c48; void* m_pad_3c50; void* m_pad_3c58; void* m_pad_3c60; void* m_pad_3c68; void* m_pad_3c70; void* m_pad_3c78;
    void* m_pad_3c80; void* m_pad_3c88; void* m_pad_3c90; void* m_pad_3c98; void* m_pad_3ca0; void* m_pad_3ca8; void* m_pad_3cb0; void* m_pad_3cb8;
    void* m_pad_3cc0; void* m_pad_3cc8; void* m_pad_3cd0; void* m_pad_3cd8; void* m_pad_3ce0; void* m_pad_3ce8; void* m_pad_3cf0; void* m_pad_3cf8;
    void* m_pad_3d00; void* m_pad_3d08; void* m_pad_3d10; void* m_pad_3d18; void* m_pad_3d20; void* m_pad_3d28; void* m_pad_3d30; void* m_pad_3d38;
    void* m_pad_3d40; void* m_pad_3d48; void* m_pad_3d50; void* m_pad_3d58; void* m_pad_3d60; void* m_pad_3d68; void* m_pad_3d70; void* m_pad_3d78;
    void* m_pad_3d80; void* m_pad_3d88; void* m_pad_3d90; void* m_pad_3d98; void* m_pad_3da0; void* m_pad_3da8; void* m_pad_3db0; void* m_pad_3db8;
    void* m_pad_3dc0; void* m_pad_3dc8; void* m_pad_3dd0; void* m_pad_3dd8; void* m_pad_3de0; void* m_pad_3de8; void* m_pad_3df0; void* m_pad_3df8;
    void* m_pad_3e00; void* m_pad_3e08; void* m_pad_3e10; void* m_pad_3e18; void* m_pad_3e20; void* m_pad_3e28; void* m_pad_3e30; void* m_pad_3e38;
    void* m_pad_3e40; void* m_pad_3e48; void* m_pad_3e50; void* m_pad_3e58; void* m_pad_3e60; void* m_pad_3e68; void* m_pad_3e70; void* m_pad_3e78;
    void* m_pad_3e80; void* m_pad_3e88; void* m_pad_3e90; void* m_pad_3e98; void* m_pad_3ea0; void* m_pad_3ea8; void* m_pad_3eb0; void* m_pad_3eb8;
    void* m_pad_3ec0; void* m_pad_3ec8; void* m_pad_3ed0; void* m_pad_3ed8; void* m_pad_3ee0; void* m_pad_3ee8; void* m_pad_3ef0; void* m_pad_3ef8;
    void* m_pad_3f00; void* m_pad_3f08; void* m_pad_3f10; void* m_pad_3f18; void* m_pad_3f20; void* m_pad_3f28; void* m_pad_3f30; void* m_pad_3f38;
    void* m_pad_3f40; void* m_pad_3f48; void* m_pad_3f50; void* m_pad_3f58; void* m_pad_3f60; void* m_pad_3f68; void* m_pad_3f70; void* m_pad_3f78;
    void* m_pad_3f80; void* m_pad_3f88; void* m_pad_3f90; void* m_pad_3f98; void* m_pad_3fa0; void* m_pad_3fa8; void* m_pad_3fb0; void* m_pad_3fb8;
    void* m_pad_3fc0; void* m_pad_3fc8; void* m_pad_3fd0; void* m_pad_3fd8; void* m_pad_3fe0; void* m_pad_3fe8; void* m_pad_3ff0; void* m_pad_3ff8;
    void* m_pad_4000; void* m_pad_4008; void* m_pad_4010; void* m_pad_4018; void* m_pad_4020; void* m_pad_4028; void* m_pad_4030; void* m_pad_4038;
    void* m_pad_4040; void* m_pad_4048; void* m_pad_4050; void* m_pad_4058; void* m_pad_4060; void* m_pad_4068; void* m_pad_4070; void* m_pad_4078;
    void* m_pad_4080; void* m_pad_4088; void* m_pad_4090; void* m_pad_4098; void* m_pad_40a0; void* m_pad_40a8; void* m_pad_40b0; void* m_pad_40b8;
    void* m_pad_40c0; void* m_pad_40c8; void* m_pad_40d0; void* m_pad_40d8; void* m_pad_40e0; void* m_pad_40e8; void* m_pad_40f0; void* m_pad_40f8;
    void* m_pad_4100; void* m_pad_4108; void* m_pad_4110; void* m_pad_4118; void* m_pad_4120; void* m_pad_4128; void* m_pad_4130; void* m_pad_4138;
    void* m_pad_4140; void* m_pad_4148; void* m_pad_4150; void* m_pad_4158; void* m_pad_4160; void* m_pad_4168; void* m_pad_4170; void* m_pad_4178;
    void* m_pad_4180; void* m_pad_4188; void* m_pad_4190; void* m_pad_4198; void* m_pad_41a0; void* m_pad_41a8; void* m_pad_41b0; void* m_pad_41b8;
    void* m_pad_41c0; void* m_pad_41c8; void* m_pad_41d0; void* m_pad_41d8; void* m_pad_41e0; void* m_pad_41e8; void* m_pad_41f0; void* m_pad_41f8;
    void* m_pad_4200; void* m_pad_4208; void* m_pad_4210; void* m_pad_4218; void* m_pad_4220; void* m_pad_4228; void* m_pad_4230; void* m_pad_4238;
    void* m_pad_4240; void* m_pad_4248; void* m_pad_4250; void* m_pad_4258; void* m_pad_4260; void* m_pad_4268; void* m_pad_4270; void* m_pad_4278;
    void* m_pad_4280; void* m_pad_4288; void* m_pad_4290; void* m_pad_4298; void* m_pad_42a0; void* m_pad_42a8; void* m_pad_42b0; void* m_pad_42b8;
    void* m_pad_42c0; void* m_pad_42c8; void* m_pad_42d0; void* m_pad_42d8; void* m_pad_42e0; void* m_pad_42e8; void* m_pad_42f0; void* m_pad_42f8;
    void* m_pad_4300; void* m_pad_4308; void* m_pad_4310; void* m_pad_4318; void* m_pad_4320; void* m_pad_4328; void* m_pad_4330; void* m_pad_4338;
    void* m_pad_4340; void* m_pad_4348; void* m_pad_4350; void* m_pad_4358; void* m_pad_4360; void* m_pad_4368; void* m_pad_4370; void* m_pad_4378;
    void* m_pad_4380; void* m_pad_4388; void* m_pad_4390; void* m_pad_4398; void* m_pad_43a0; void* m_pad_43a8; void* m_pad_43b0; void* m_pad_43b8;
    void* m_pad_43c0; void* m_pad_43c8; void* m_pad_43d0; void* m_pad_43d8; void* m_pad_43e0; void* m_pad_43e8; void* m_pad_43f0; void* m_pad_43f8;
    void* m_pad_4400; void* m_pad_4408; void* m_pad_4410; void* m_pad_4418; void* m_pad_4420; void* m_pad_4428; void* m_pad_4430; void* m_pad_4438;
    void* m_pad_4440; void* m_pad_4448; void* m_pad_4450; void* m_pad_4458; void* m_pad_4460; void* m_pad_4468; void* m_pad_4470; void* m_pad_4478;
    void* m_pad_4480; void* m_pad_4488; void* m_pad_4490; void* m_pad_4498; void* m_pad_44a0; void* m_pad_44a8; void* m_pad_44b0; void* m_pad_44b8;
    void* m_pad_44c0; void* m_pad_44c8; void* m_pad_44d0; void* m_pad_44d8; void* m_pad_44e0; void* m_pad_44e8; void* m_pad_44f0; void* m_pad_44f8;
    void* m_pad_4500; void* m_pad_4508; void* m_pad_4510; void* m_pad_4518; void* m_pad_4520; void* m_pad_4528; void* m_pad_4530; void* m_pad_4538;
    void* m_pad_4540; void* m_pad_4548; void* m_pad_4550; void* m_pad_4558; void* m_pad_4560; void* m_pad_4568; void* m_pad_4570; void* m_pad_4578;
    void* m_pad_4580; void* m_pad_4588; void* m_pad_4590; void* m_pad_4598; void* m_pad_45a0; void* m_pad_45a8; void* m_pad_45b0; void* m_pad_45b8;
    void* m_pad_45c0; void* m_pad_45c8; void* m_pad_45d0; void* m_pad_45d8; void* m_pad_45e0; void* m_pad_45e8; void* m_pad_45f0; void* m_pad_45f8;
    void* m_pad_4600; void* m_pad_4608; void* m_pad_4610; void* m_pad_4618; void* m_pad_4620; void* m_pad_4628; void* m_pad_4630; void* m_pad_4638;
    void* m_pad_4640; void* m_pad_4648; void* m_pad_4650; void* m_pad_4658; void* m_pad_4660; void* m_pad_4668; void* m_pad_4670; void* m_pad_4678;
    void* m_pad_4680; void* m_pad_4688; void* m_pad_4690; void* m_pad_4698; void* m_pad_46a0; void* m_pad_46a8; void* m_pad_46b0; void* m_pad_46b8;
    void* m_pad_46c0; void* m_pad_46c8; void* m_pad_46d0; void* m_pad_46d8; void* m_pad_46e0; void* m_pad_46e8; void* m_pad_46f0; void* m_pad_46f8;
    void* m_pad_4700; void* m_pad_4708; void* m_pad_4710; void* m_pad_4718; void* m_pad_4720; void* m_pad_4728; void* m_pad_4730; void* m_pad_4738;
    void* m_pad_4740; void* m_pad_4748; void* m_pad_4750; void* m_pad_4758; void* m_pad_4760; void* m_pad_4768; void* m_pad_4770; void* m_pad_4778;
    void* m_pad_4780; void* m_pad_4788; void* m_pad_4790; void* m_pad_4798; void* m_pad_47a0; void* m_pad_47a8; void* m_pad_47b0; void* m_pad_47b8;
    void* m_pad_47c0; void* m_pad_47c8; void* m_pad_47d0; void* m_pad_47d8; void* m_pad_47e0; void* m_pad_47e8; void* m_pad_47f0; void* m_pad_47f8;
    void* m_pad_4800; void* m_pad_4808; void* m_pad_4810; void* m_pad_4818; void* m_pad_4820; void* m_pad_4828; void* m_pad_4830; void* m_pad_4838;
    void* m_pad_4840; void* m_pad_4848; void* m_pad_4850; void* m_pad_4858; void* m_pad_4860; void* m_pad_4868; void* m_pad_4870; void* m_pad_4878;
    void* m_pad_4880; void* m_pad_4888; void* m_pad_4890; void* m_pad_4898; void* m_pad_48a0; void* m_pad_48a8; void* m_pad_48b0; void* m_pad_48b8;
    void* m_pad_48c0; void* m_pad_48c8; void* m_pad_48d0; void* m_pad_48d8; void* m_pad_48e0; void* m_pad_48e8; void* m_pad_48f0; void* m_pad_48f8;
    void* m_pad_4900; void* m_pad_4908; void* m_pad_4910; void* m_pad_4918; void* m_pad_4920; void* m_pad_4928; void* m_pad_4930; void* m_pad_4938;
    void* m_pad_4940; void* m_pad_4948; void* m_pad_4950; void* m_pad_4958; void* m_pad_4960; void* m_pad_4968; void* m_pad_4970; void* m_pad_4978;
    void* m_pad_4980; void* m_pad_4988; void* m_pad_4990; void* m_pad_4998; void* m_pad_49a0; void* m_pad_49a8; void* m_pad_49b0; void* m_pad_49b8;
    void* m_pad_49c0; void* m_pad_49c8; void* m_pad_49d0; void* m_pad_49d8; void* m_pad_49e0; void* m_pad_49e8; void* m_pad_49f0; void* m_pad_49f8;
    void* m_pad_4a00; void* m_pad_4a08; void* m_pad_4a10; void* m_pad_4a18; void* m_pad_4a20; void* m_pad_4a28; void* m_pad_4a30; void* m_pad_4a38;
    void* m_pad_4a40; void* m_pad_4a48; void* m_pad_4a50; void* m_pad_4a58; void* m_pad_4a60; void* m_pad_4a68; void* m_pad_4a70; void* m_pad_4a78;
    void* m_pad_4a80; void* m_pad_4a88; void* m_pad_4a90; void* m_pad_4a98; void* m_pad_4aa0; void* m_pad_4aa8; void* m_pad_4ab0; void* m_pad_4ab8;
    void* m_pad_4ac0; void* m_pad_4ac8; void* m_pad_4ad0; void* m_pad_4ad8; void* m_pad_4ae0; void* m_pad_4ae8; void* m_pad_4af0; void* m_pad_4af8;
    void* m_pad_4b00; void* m_pad_4b08; void* m_pad_4b10; void* m_pad_4b18; void* m_pad_4b20; void* m_pad_4b28; void* m_pad_4b30; void* m_pad_4b38;
    void* m_pad_4b40; void* m_pad_4b48; void* m_pad_4b50; void* m_pad_4b58; void* m_pad_4b60; void* m_pad_4b68; void* m_pad_4b70; void* m_pad_4b78;
    void* m_pad_4b80; void* m_pad_4b88; void* m_pad_4b90; void* m_pad_4b98; void* m_pad_4ba0; void* m_pad_4ba8; void* m_pad_4bb0; void* m_pad_4bb8;
    void* m_pad_4bc0; void* m_pad_4bc8; void* m_pad_4bd0; void* m_pad_4bd8; void* m_pad_4be0; void* m_pad_4be8; void* m_pad_4bf0; void* m_pad_4bf8;
    void* m_pad_4c00; void* m_pad_4c08; void* m_pad_4c10; void* m_pad_4c18; void* m_pad_4c20; void* m_pad_4c28; void* m_pad_4c30; void* m_pad_4c38;
    void* m_pad_4c40; void* m_pad_4c48; void* m_pad_4c50; void* m_pad_4c58; void* m_pad_4c60; void* m_pad_4c68; void* m_pad_4c70; void* m_pad_4c78;
    void* m_pad_4c80; void* m_pad_4c88; void* m_pad_4c90; void* m_pad_4c98; void* m_pad_4ca0; void* m_pad_4ca8; void* m_pad_4cb0; void* m_pad_4cb8;
    void* m_pad_4cc0; void* m_pad_4cc8; void* m_pad_4cd0; void* m_pad_4cd8; void* m_pad_4ce0; void* m_pad_4ce8; void* m_pad_4cf0; void* m_pad_4cf8;
    void* m_pad_4d00; void* m_pad_4d08; void* m_pad_4d10; void* m_pad_4d18; void* m_pad_4d20; void* m_pad_4d28; void* m_pad_4d30; void* m_pad_4d38;
    void* m_pad_4d40; void* m_pad_4d48; void* m_pad_4d50; void* m_pad_4d58; void* m_pad_4d60; void* m_pad_4d68; void* m_pad_4d70; void* m_pad_4d78;
    void* m_pad_4d80; void* m_pad_4d88; void* m_pad_4d90; void* m_pad_4d98; void* m_pad_4da0; void* m_pad_4da8; void* m_pad_4db0; void* m_pad_4db8;
    void* m_pad_4dc0; void* m_pad_4dc8; void* m_pad_4dd0; void* m_pad_4dd8; void* m_pad_4de0; void* m_pad_4de8; void* m_pad_4df0; void* m_pad_4df8;
    void* m_pad_4e00; void* m_pad_4e08; void* m_pad_4e10; void* m_pad_4e18; void* m_pad_4e20; void* m_pad_4e28; void* m_pad_4e30; void* m_pad_4e38;
    void* m_pad_4e40; void* m_pad_4e48; void* m_pad_4e50; void* m_pad_4e58; void* m_pad_4e60; void* m_pad_4e68; void* m_pad_4e70; void* m_pad_4e78;
    void* m_pad_4e80; void* m_pad_4e88; void* m_pad_4e90; void* m_pad_4e98; void* m_pad_4ea0; void* m_pad_4ea8; void* m_pad_4eb0; void* m_pad_4eb8;
    void* m_pad_4ec0; void* m_pad_4ec8; void* m_pad_4ed0; void* m_pad_4ed8; void* m_pad_4ee0; void* m_pad_4ee8; void* m_pad_4ef0; void* m_pad_4ef8;
    void* m_pad_4f00; void* m_pad_4f08; void* m_pad_4f10; void* m_pad_4f18; void* m_pad_4f20; void* m_pad_4f28; void* m_pad_4f30; void* m_pad_4f38;
    void* m_pad_4f40; void* m_pad_4f48; void* m_pad_4f50; void* m_pad_4f58; void* m_pad_4f60; void* m_pad_4f68; void* m_pad_4f70; void* m_pad_4f78;
    void* m_pad_4f80; void* m_pad_4f88; void* m_pad_4f90; void* m_pad_4f98; void* m_pad_4fa0; void* m_pad_4fa8; void* m_pad_4fb0; void* m_pad_4fb8;
    void* m_pad_4fc0; void* m_pad_4fc8; void* m_pad_4fd0; void* m_pad_4fd8; void* m_pad_4fe0; void* m_pad_4fe8; void* m_pad_4ff0; void* m_pad_4ff8;
    void* m_pad_5000; void* m_pad_5008; void* m_pad_5010; void* m_pad_5018; void* m_pad_5020; void* m_pad_5028; void* m_pad_5030; void* m_pad_5038;
    void* m_pad_5040; void* m_pad_5048; void* m_pad_5050; void* m_pad_5058; void* m_pad_5060; void* m_pad_5068; void* m_pad_5070; void* m_pad_5078;
    void* m_pad_5080; void* m_pad_5088; void* m_pad_5090; void* m_pad_5098; void* m_pad_50a0; void* m_pad_50a8; void* m_pad_50b0; void* m_pad_50b8;
    void* m_pad_50c0; void* m_pad_50c8; void* m_pad_50d0; void* m_pad_50d8; void* m_pad_50e0; void* m_pad_50e8; void* m_pad_50f0; void* m_pad_50f8;
    void* m_pad_5100; void* m_pad_5108; void* m_pad_5110; void* m_pad_5118; void* m_pad_5120; void* m_pad_5128; void* m_pad_5130; void* m_pad_5138;
    void* m_pad_5140; void* m_pad_5148; void* m_pad_5150; void* m_pad_5158; void* m_pad_5160; void* m_pad_5168; void* m_pad_5170; void* m_pad_5178;
    void* m_pad_5180; void* m_pad_5188; void* m_pad_5190; void* m_pad_5198; void* m_pad_51a0; void* m_pad_51a8; void* m_pad_51b0; void* m_pad_51b8;
    void* m_pad_51c0; void* m_pad_51c8; void* m_pad_51d0; void* m_pad_51d8; void* m_pad_51e0; void* m_pad_51e8; void* m_pad_51f0; void* m_pad_51f8;
    void* m_pad_5200; void* m_pad_5208; void* m_pad_5210; void* m_pad_5218; void* m_pad_5220; void* m_pad_5228; void* m_pad_5230; void* m_pad_5238;
    void* m_pad_5240; void* m_pad_5248; void* m_pad_5250; void* m_pad_5258; void* m_pad_5260; void* m_pad_5268; void* m_pad_5270; void* m_pad_5278;
    void* m_pad_5280; void* m_pad_5288; void* m_pad_5290; void* m_pad_5298; void* m_pad_52a0; void* m_pad_52a8; void* m_pad_52b0; void* m_pad_52b8;
    void* m_pad_52c0; void* m_pad_52c8; void* m_pad_52d0; void* m_pad_52d8; void* m_pad_52e0; void* m_pad_52e8; void* m_pad_52f0; void* m_pad_52f8;
    void* m_pad_5300; void* m_pad_5308; void* m_pad_5310; void* m_pad_5318; void* m_pad_5320; void* m_pad_5328; void* m_pad_5330; void* m_pad_5338;
    void* m_pad_5340; void* m_pad_5348; void* m_pad_5350; void* m_pad_5358; void* m_pad_5360; void* m_pad_5368; void* m_pad_5370; void* m_pad_5378;
    void* m_pad_5380; void* m_pad_5388; void* m_pad_5390; void* m_pad_5398; void* m_pad_53a0; void* m_pad_53a8; void* m_pad_53b0; void* m_pad_53b8;
    void* m_pad_53c0; void* m_pad_53c8; void* m_pad_53d0; void* m_pad_53d8; void* m_pad_53e0; void* m_pad_53e8; void* m_pad_53f0; void* m_pad_53f8;
    void* m_pad_5400; void* m_pad_5408; void* m_pad_5410; void* m_pad_5418; void* m_pad_5420; void* m_pad_5428; void* m_pad_5430; void* m_pad_5438;
    void* m_pad_5440; void* m_pad_5448; void* m_pad_5450; void* m_pad_5458; void* m_pad_5460; void* m_pad_5468; void* m_pad_5470; void* m_pad_5478;
    void* m_pad_5480; void* m_pad_5488; void* m_pad_5490; void* m_pad_5498; void* m_pad_54a0; void* m_pad_54a8; void* m_pad_54b0; void* m_pad_54b8;
    void* m_pad_54c0; void* m_pad_54c8; void* m_pad_54d0; void* m_pad_54d8; void* m_pad_54e0; void* m_pad_54e8; void* m_pad_54f0; void* m_pad_54f8;
    void* m_pad_5500; void* m_pad_5508; void* m_pad_5510; void* m_pad_5518; void* m_pad_5520; void* m_pad_5528; void* m_pad_5530; void* m_pad_5538;
    void* m_pad_5540; void* m_pad_5548; void* m_pad_5550; void* m_pad_5558; void* m_pad_5560; void* m_pad_5568; void* m_pad_5570; void* m_pad_5578;
    void* m_pad_5580; void* m_pad_5588; void* m_pad_5590; void* m_pad_5598; void* m_pad_55a0; void* m_pad_55a8; void* m_pad_55b0; void* m_pad_55b8;
    void* m_pad_55c0; void* m_pad_55c8; void* m_pad_55d0; void* m_pad_55d8; void* m_pad_55e0; void* m_pad_55e8; void* m_pad_55f0; void* m_pad_55f8;
    void* m_pad_5600; void* m_pad_5608; void* m_pad_5610; void* m_pad_5618; void* m_pad_5620; void* m_pad_5628; void* m_pad_5630; void* m_pad_5638;
    void* m_pad_5640; void* m_pad_5648; void* m_pad_5650; void* m_pad_5658; void* m_pad_5660; void* m_pad_5668; void* m_pad_5670; void* m_pad_5678;
    void* m_pad_5680; void* m_pad_5688; void* m_pad_5690; void* m_pad_5698; void* m_pad_56a0; void* m_pad_56a8; void* m_pad_56b0; void* m_pad_56b8;
    void* m_pad_56c0; void* m_pad_56c8; void* m_pad_56d0; void* m_pad_56d8; void* m_pad_56e0; void* m_pad_56e8; void* m_pad_56f0; void* m_pad_56f8;
    void* m_pad_5700; void* m_pad_5708; void* m_pad_5710; void* m_pad_5718; void* m_pad_5720; void* m_pad_5728; void* m_pad_5730; void* m_pad_5738;
    void* m_pad_5740; void* m_pad_5748; void* m_pad_5750; void* m_pad_5758; void* m_pad_5760; void* m_pad_5768; void* m_pad_5770; void* m_pad_5778;
    void* m_pad_5780; void* m_pad_5788; void* m_pad_5790; void* m_pad_5798; void* m_pad_57a0; void* m_pad_57a8; void* m_pad_57b0; void* m_pad_57b8;
    void* m_pad_57c0; void* m_pad_57c8; void* m_pad_57d0; void* m_pad_57d8; void* m_pad_57e0; void* m_pad_57e8; void* m_pad_57f0; void* m_pad_57f8;
    void* m_pad_5800; void* m_pad_5808; void* m_pad_5810; void* m_pad_5818; void* m_pad_5820; void* m_pad_5828; void* m_pad_5830; void* m_pad_5838;
    void* m_pad_5840; void* m_pad_5848; void* m_pad_5850; void* m_pad_5858; void* m_pad_5860; void* m_pad_5868; void* m_pad_5870; void* m_pad_5878;
    void* m_pad_5880; void* m_pad_5888; void* m_pad_5890; void* m_pad_5898; void* m_pad_58a0; void* m_pad_58a8; void* m_pad_58b0; void* m_pad_58b8;
    void* m_pad_58c0; void* m_pad_58c8; void* m_pad_58d0; void* m_pad_58d8; void* m_pad_58e0; void* m_pad_58e8; void* m_pad_58f0; void* m_pad_58f8;
    void* m_pad_5900; void* m_pad_5908; void* m_pad_5910; void* m_pad_5918; void* m_pad_5920; void* m_pad_5928; void* m_pad_5930; void* m_pad_5938;
    void* m_pad_5940; void* m_pad_5948; void* m_pad_5950; void* m_pad_5958; void* m_pad_5960; void* m_pad_5968; void* m_pad_5970; void* m_pad_5978;
    void* m_pad_5980; void* m_pad_5988; void* m_pad_5990; void* m_pad_5998; void* m_pad_59a0; void* m_pad_59a8; void* m_pad_59b0; void* m_pad_59b8;
    void* m_pad_59c0; void* m_pad_59c8; void* m_pad_59d0; void* m_pad_59d8; void* m_pad_59e0; void* m_pad_59e8; void* m_pad_59f0; void* m_pad_59f8;
    void* m_pad_5a00; void* m_pad_5a08; void* m_pad_5a10; void* m_pad_5a18; void* m_pad_5a20; void* m_pad_5a28; void* m_pad_5a30; void* m_pad_5a38;
    void* m_pad_5a40; void* m_pad_5a48; void* m_pad_5a50; void* m_pad_5a58; void* m_pad_5a60; void* m_pad_5a68; void* m_pad_5a70; void* m_pad_5a78;
    void* m_pad_5a80; void* m_pad_5a88; void* m_pad_5a90; void* m_pad_5a98; void* m_pad_5aa0; void* m_pad_5aa8; void* m_pad_5ab0; void* m_pad_5ab8;
    void* m_pad_5ac0; void* m_pad_5ac8; void* m_pad_5ad0; void* m_pad_5ad8; void* m_pad_5ae0; void* m_pad_5ae8; void* m_pad_5af0; void* m_pad_5af8;
    void* m_pad_5b00; void* m_pad_5b08; void* m_pad_5b10; void* m_pad_5b18; void* m_pad_5b20; void* m_pad_5b28; void* m_pad_5b30; void* m_pad_5b38;
    void* m_pad_5b40; void* m_pad_5b48; void* m_pad_5b50; void* m_pad_5b58; void* m_pad_5b60; void* m_pad_5b68; void* m_pad_5b70; void* m_pad_5b78;
    void* m_pad_5b80; void* m_pad_5b88; void* m_pad_5b90; void* m_pad_5b98; void* m_pad_5ba0; void* m_pad_5ba8; void* m_pad_5bb0; void* m_pad_5bb8;
    void* m_pad_5bc0; void* m_pad_5bc8; void* m_pad_5bd0; void* m_pad_5bd8; void* m_pad_5be0; void* m_pad_5be8; void* m_pad_5bf0; void* m_pad_5bf8;
    void* m_pad_5c00; void* m_pad_5c08; void* m_pad_5c10; void* m_pad_5c18; void* m_pad_5c20; void* m_pad_5c28; void* m_pad_5c30; void* m_pad_5c38;
    void* m_pad_5c40; void* m_pad_5c48; void* m_pad_5c50; void* m_pad_5c58; void* m_pad_5c60; void* m_pad_5c68; void* m_pad_5c70; void* m_pad_5c78;
    void* m_pad_5c80; void* m_pad_5c88; void* m_pad_5c90; void* m_pad_5c98; void* m_pad_5ca0; void* m_pad_5ca8; void* m_pad_5cb0; void* m_pad_5cb8;
    void* m_pad_5cc0; void* m_pad_5cc8; void* m_pad_5cd0; void* m_pad_5cd8; void* m_pad_5ce0; void* m_pad_5ce8; void* m_pad_5cf0; void* m_pad_5cf8;
    void* m_pad_5d00; void* m_pad_5d08; void* m_pad_5d10; void* m_pad_5d18; void* m_pad_5d20; void* m_pad_5d28; void* m_pad_5d30; void* m_pad_5d38;
    void* m_pad_5d40; void* m_pad_5d48; void* m_pad_5d50; void* m_pad_5d58; void* m_pad_5d60; void* m_pad_5d68; void* m_pad_5d70; void* m_pad_5d78;
    void* m_pad_5d80; void* m_pad_5d88; void* m_pad_5d90; void* m_pad_5d98; void* m_pad_5da0; void* m_pad_5da8; void* m_pad_5db0; void* m_pad_5db8;
    void* m_pad_5dc0; void* m_pad_5dc8; void* m_pad_5dd0; void* m_pad_5dd8; void* m_pad_5de0; void* m_pad_5de8; void* m_pad_5df0; void* m_pad_5df8;
    void* m_pad_5e00; void* m_pad_5e08; void* m_pad_5e10; void* m_pad_5e18; void* m_pad_5e20; void* m_pad_5e28; void* m_pad_5e30; void* m_pad_5e38;
    void* m_pad_5e40; void* m_pad_5e48; void* m_pad_5e50; void* m_pad_5e58; void* m_pad_5e60; void* m_pad_5e68; void* m_pad_5e70; void* m_pad_5e78;
    void* m_pad_5e80; void* m_pad_5e88; void* m_pad_5e90; void* m_pad_5e98; void* m_pad_5ea0; void* m_pad_5ea8; void* m_pad_5eb0; void* m_pad_5eb8;
    void* m_pad_5ec0; void* m_pad_5ec8; void* m_pad_5ed0; void* m_pad_5ed8; void* m_pad_5ee0; void* m_pad_5ee8; void* m_pad_5ef0; void* m_pad_5ef8;
    void* m_pad_5f00; void* m_pad_5f08; void* m_pad_5f10; void* m_pad_5f18; void* m_pad_5f20; void* m_pad_5f28; void* m_pad_5f30; void* m_pad_5f38;
    void* m_pad_5f40; void* m_pad_5f48; void* m_pad_5f50; void* m_pad_5f58; void* m_pad_5f60; void* m_pad_5f68; void* m_pad_5f70; void* m_pad_5f78;
    void* m_pad_5f80; void* m_pad_5f88; void* m_pad_5f90; void* m_pad_5f98; void* m_pad_5fa0; void* m_pad_5fa8; void* m_pad_5fb0; void* m_pad_5fb8;
    void* m_pad_5fc0; void* m_pad_5fc8; void* m_pad_5fd0; void* m_pad_5fd8; void* m_pad_5fe0; void* m_pad_5fe8; void* m_pad_5ff0; void* m_pad_5ff8;
    void* m_pad_6000; void* m_pad_6008; void* m_pad_6010; void* m_pad_6018; void* m_pad_6020; void* m_pad_6028; void* m_pad_6030; void* m_pad_6038;
    void* m_pad_6040; void* m_pad_6048; void* m_pad_6050; void* m_pad_6058; void* m_pad_6060; void* m_pad_6068; void* m_pad_6070; void* m_pad_6078;
    void* m_pad_6080; void* m_pad_6088; void* m_pad_6090; void* m_pad_6098; void* m_pad_60a0; void* m_pad_60a8; void* m_pad_60b0; void* m_pad_60b8;
    void* m_pad_60c0; void* m_pad_60c8; void* m_pad_60d0; void* m_pad_60d8; void* m_pad_60e0; void* m_pad_60e8; void* m_pad_60f0; void* m_pad_60f8;
    void* m_pad_6100; void* m_pad_6108; void* m_pad_6110; void* m_pad_6118; void* m_pad_6120; void* m_pad_6128; void* m_pad_6130; void* m_pad_6138;
    void* m_pad_6140; void* m_pad_6148; void* m_pad_6150; void* m_pad_6158; void* m_pad_6160; void* m_pad_6168; void* m_pad_6170; void* m_pad_6178;
    void* m_pad_6180; void* m_pad_6188; void* m_pad_6190; void* m_pad_6198; void* m_pad_61a0; void* m_pad_61a8; void* m_pad_61b0; void* m_pad_61b8;
    void* m_pad_61c0; void* m_pad_61c8; void* m_pad_61d0; void* m_pad_61d8; void* m_pad_61e0; void* m_pad_61e8; void* m_pad_61f0; void* m_pad_61f8;
    void* m_pad_6200; void* m_pad_6208; void* m_pad_6210; void* m_pad_6218; void* m_pad_6220; void* m_pad_6228; void* m_pad_6230; void* m_pad_6238;
    void* m_pad_6240; void* m_pad_6248; void* m_pad_6250; void* m_pad_6258; void* m_pad_6260; void* m_pad_6268; void* m_pad_6270; void* m_pad_6278;
    void* m_pad_6280; void* m_pad_6288; void* m_pad_6290; void* m_pad_6298; void* m_pad_62a0; void* m_pad_62a8; void* m_pad_62b0; void* m_pad_62b8;
    void* m_pad_62c0; void* m_pad_62c8; void* m_pad_62d0; void* m_pad_62d8; void* m_pad_62e0; void* m_pad_62e8; void* m_pad_62f0; void* m_pad_62f8;
    void* m_pad_6300; void* m_pad_6308; void* m_pad_6310; void* m_pad_6318; void* m_pad_6320; void* m_pad_6328; void* m_pad_6330; void* m_pad_6338;
    void* m_pad_6340; void* m_pad_6348; void* m_pad_6350; void* m_pad_6358; void* m_pad_6360; void* m_pad_6368; void* m_pad_6370; void* m_pad_6378;
    void* m_pad_6380; void* m_pad_6388; void* m_pad_6390; void* m_pad_6398; void* m_pad_63a0; void* m_pad_63a8; void* m_pad_63b0; void* m_pad_63b8;
    void* m_pad_63c0; void* m_pad_63c8; void* m_pad_63d0; void* m_pad_63d8; void* m_pad_63e0; void* m_pad_63e8; void* m_pad_63f0; void* m_pad_63f8;
    void* m_pad_6400; void* m_pad_6408; void* m_pad_6410; void* m_pad_6418; void* m_pad_6420; void* m_pad_6428; void* m_pad_6430; void* m_pad_6438;
    void* m_pad_6440; void* m_pad_6448; void* m_pad_6450; void* m_pad_6458; void* m_pad_6460; void* m_pad_6468; void* m_pad_6470; void* m_pad_6478;
    void* m_pad_6480; void* m_pad_6488; void* m_pad_6490; void* m_pad_6498; void* m_pad_64a0; void* m_pad_64a8; void* m_pad_64b0; void* m_pad_64b8;
    void* m_pad_64c0; void* m_pad_64c8; void* m_pad_64d0; void* m_pad_64d8; void* m_pad_64e0; void* m_pad_64e8; void* m_pad_64f0; void* m_pad_64f8;
    void* m_pad_6500; void* m_pad_6508; void* m_pad_6510; void* m_pad_6518; void* m_pad_6520; void* m_pad_6528; void* m_pad_6530; void* m_pad_6538;
    void* m_pad_6540; void* m_pad_6548; void* m_pad_6550; void* m_pad_6558; void* m_pad_6560; void* m_pad_6568; void* m_pad_6570; void* m_pad_6578;
    void* m_pad_6580; void* m_pad_6588; void* m_pad_6590; void* m_pad_6598; void* m_pad_65a0; void* m_pad_65a8; void* m_pad_65b0; void* m_pad_65b8;
    void* m_pad_65c0; void* m_pad_65c8; void* m_pad_65d0; void* m_pad_65d8; void* m_pad_65e0; void* m_pad_65e8; void* m_pad_65f0; void* m_pad_65f8;
    void* m_pad_6600; void* m_pad_6608; void* m_pad_6610; void* m_pad_6618; void* m_pad_6620; void* m_pad_6628; void* m_pad_6630; void* m_pad_6638;
    void* m_pad_6640; void* m_pad_6648; void* m_pad_6650; void* m_pad_6658; void* m_pad_6660; void* m_pad_6668; void* m_pad_6670; void* m_pad_6678;
    void* m_pad_6680; void* m_pad_6688; void* m_pad_6690; void* m_pad_6698; void* m_pad_66a0; void* m_pad_66a8; void* m_pad_66b0; void* m_pad_66b8;
    void* m_pad_66c0; void* m_pad_66c8; void* m_pad_66d0; void* m_pad_66d8; void* m_pad_66e0; void* m_pad_66e8; void* m_pad_66f0; void* m_pad_66f8;
    void* m_pad_6700; void* m_pad_6708; void* m_pad_6710; void* m_pad_6718; void* m_pad_6720; void* m_pad_6728; void* m_pad_6730; void* m_pad_6738;
    void* m_pad_6740; void* m_pad_6748; void* m_pad_6750; void* m_pad_6758; void* m_pad_6760; void* m_pad_6768; void* m_pad_6770; void* m_pad_6778;
    void* m_pad_6780; void* m_pad_6788; void* m_pad_6790; void* m_pad_6798; void* m_pad_67a0; void* m_pad_67a8; void* m_pad_67b0; void* m_pad_67b8;
    void* m_pad_67c0; void* m_pad_67c8; void* m_pad_67d0; void* m_pad_67d8; void* m_pad_67e0; void* m_pad_67e8; void* m_pad_67f0; void* m_pad_67f8;
    void* m_pad_6800; void* m_pad_6808; void* m_pad_6810; void* m_pad_6818; void* m_pad_6820; void* m_pad_6828; void* m_pad_6830; void* m_pad_6838;
    void* m_pad_6840; void* m_pad_6848; void* m_pad_6850; void* m_pad_6858; void* m_pad_6860; void* m_pad_6868; void* m_pad_6870; void* m_pad_6878;
    void* m_pad_6880; void* m_pad_6888; void* m_pad_6890; void* m_pad_6898; void* m_pad_68a0; void* m_pad_68a8; void* m_pad_68b0; void* m_pad_68b8;
    void* m_pad_68c0; void* m_pad_68c8; void* m_pad_68d0; void* m_pad_68d8; void* m_pad_68e0; void* m_pad_68e8; void* m_pad_68f0; void* m_pad_68f8;
    void* m_pad_6900; void* m_pad_6908; void* m_pad_6910; void* m_pad_6918; void* m_pad_6920; void* m_pad_6928; void* m_pad_6930; void* m_pad_6938;
    void* m_pad_6940; void* m_pad_6948; void* m_pad_6950; void* m_pad_6958; void* m_pad_6960; void* m_pad_6968; void* m_pad_6970; void* m_pad_6978;
    void* m_pad_6980; void* m_pad_6988; void* m_pad_6990; void* m_pad_6998; void* m_pad_69a0; void* m_pad_69a8; void* m_pad_69b0; void* m_pad_69b8;
    void* m_pad_69c0; void* m_pad_69c8; void* m_pad_69d0; void* m_pad_69d8; void* m_pad_69e0; void* m_pad_69e8; void* m_pad_69f0; void* m_pad_69f8;
    void* m_pad_6a00; void* m_pad_6a08; void* m_pad_6a10; void* m_pad_6a18; void* m_pad_6a20; void* m_pad_6a28; void* m_pad_6a30; void* m_pad_6a38;
    void* m_pad_6a40; void* m_pad_6a48; void* m_pad_6a50; void* m_pad_6a58; void* m_pad_6a60; void* m_pad_6a68; void* m_pad_6a70; void* m_pad_6a78;
    void* m_pad_6a80; void* m_pad_6a88; void* m_pad_6a90; void* m_pad_6a98; void* m_pad_6aa0; void* m_pad_6aa8; void* m_pad_6ab0; void* m_pad_6ab8;
    void* m_pad_6ac0; void* m_pad_6ac8; void* m_pad_6ad0; void* m_pad_6ad8; void* m_pad_6ae0; void* m_pad_6ae8; void* m_pad_6af0; void* m_pad_6af8;
    void* m_pad_6b00; void* m_pad_6b08; void* m_pad_6b10; void* m_pad_6b18; void* m_pad_6b20; void* m_pad_6b28; void* m_pad_6b30; void* m_pad_6b38;
    void* m_pad_6b40; void* m_pad_6b48; void* m_pad_6b50; void* m_pad_6b58; void* m_pad_6b60; void* m_pad_6b68; void* m_pad_6b70; void* m_pad_6b78;
    void* m_pad_6b80; void* m_pad_6b88; void* m_pad_6b90; void* m_pad_6b98; void* m_pad_6ba0; void* m_pad_6ba8; void* m_pad_6bb0; void* m_pad_6bb8;
    void* m_pad_6bc0; void* m_pad_6bc8; void* m_pad_6bd0; void* m_pad_6bd8; void* m_pad_6be0; void* m_pad_6be8; void* m_pad_6bf0; void* m_pad_6bf8;
    void* m_pad_6c00; void* m_pad_6c08; void* m_pad_6c10; void* m_pad_6c18; void* m_pad_6c20; void* m_pad_6c28; void* m_pad_6c30; void* m_pad_6c38;
    void* m_pad_6c40; void* m_pad_6c48; void* m_pad_6c50; void* m_pad_6c58; void* m_pad_6c60; void* m_pad_6c68; void* m_pad_6c70; void* m_pad_6c78;
    void* m_pad_6c80; void* m_pad_6c88; void* m_pad_6c90; void* m_pad_6c98; void* m_pad_6ca0; void* m_pad_6ca8; void* m_pad_6cb0; void* m_pad_6cb8;
    void* m_pad_6cc0; void* m_pad_6cc8; void* m_pad_6cd0; void* m_pad_6cd8; void* m_pad_6ce0; void* m_pad_6ce8; void* m_pad_6cf0; void* m_pad_6cf8;
    void* m_pad_6d00; void* m_pad_6d08; void* m_pad_6d10; void* m_pad_6d18; void* m_pad_6d20; void* m_pad_6d28; void* m_pad_6d30; void* m_pad_6d38;
    void* m_pad_6d40; void* m_pad_6d48; void* m_pad_6d50; void* m_pad_6d58; void* m_pad_6d60; void* m_pad_6d68; void* m_pad_6d70; void* m_pad_6d78;
    void* m_pad_6d80; void* m_pad_6d88; void* m_pad_6d90; void* m_pad_6d98; void* m_pad_6da0; void* m_pad_6da8; void* m_pad_6db0; void* m_pad_6db8;
    void* m_pad_6dc0; void* m_pad_6dc8; void* m_pad_6dd0; void* m_pad_6dd8; void* m_pad_6de0; void* m_pad_6de8; void* m_pad_6df0; void* m_pad_6df8;
    void* m_pad_6e00; void* m_pad_6e08; void* m_pad_6e10; void* m_pad_6e18; void* m_pad_6e20; void* m_pad_6e28; void* m_pad_6e30; void* m_pad_6e38;
    void* m_pad_6e40; void* m_pad_6e48; void* m_pad_6e50; void* m_pad_6e58; void* m_pad_6e60; void* m_pad_6e68; void* m_pad_6e70; void* m_pad_6e78;
    void* m_pad_6e80; void* m_pad_6e88; void* m_pad_6e90; void* m_pad_6e98; void* m_pad_6ea0; void* m_pad_6ea8; void* m_pad_6eb0; void* m_pad_6eb8;
    void* m_pad_6ec0; void* m_pad_6ec8; void* m_pad_6ed0; void* m_pad_6ed8; void* m_pad_6ee0; void* m_pad_6ee8; void* m_pad_6ef0; void* m_pad_6ef8;
    void* m_pad_6f00; void* m_pad_6f08; void* m_pad_6f10; void* m_pad_6f18; void* m_pad_6f20; void* m_pad_6f28; void* m_pad_6f30; void* m_pad_6f38;
    void* m_pad_6f40; void* m_pad_6f48; void* m_pad_6f50; void* m_pad_6f58; void* m_pad_6f60; void* m_pad_6f68; void* m_pad_6f70; void* m_pad_6f78;
    void* m_pad_6f80; void* m_pad_6f88; void* m_pad_6f90; void* m_pad_6f98; void* m_pad_6fa0; void* m_pad_6fa8; void* m_pad_6fb0; void* m_pad_6fb8;
    void* m_pad_6fc0; void* m_pad_6fc8; void* m_pad_6fd0; void* m_pad_6fd8; void* m_pad_6fe0; void* m_pad_6fe8; void* m_pad_6ff0; void* m_pad_6ff8;
    void* m_pad_7000; void* m_pad_7008; void* m_pad_7010; void* m_pad_7018; void* m_pad_7020; void* m_pad_7028; void* m_pad_7030; void* m_pad_7038;
    void* m_pad_7040; void* m_pad_7048; void* m_pad_7050; void* m_pad_7058; void* m_pad_7060; void* m_pad_7068; void* m_pad_7070; void* m_pad_7078;
    void* m_pad_7080; void* m_pad_7088; void* m_pad_7090; void* m_pad_7098; void* m_pad_70a0; void* m_pad_70a8; void* m_pad_70b0; void* m_pad_70b8;
    void* m_pad_70c0; void* m_pad_70c8; void* m_pad_70d0; void* m_pad_70d8; void* m_pad_70e0; void* m_pad_70e8; void* m_pad_70f0; void* m_pad_70f8;
    void* m_pad_7100; void* m_pad_7108; void* m_pad_7110; void* m_pad_7118; void* m_pad_7120; void* m_pad_7128; void* m_pad_7130; void* m_pad_7138;
    void* m_pad_7140; void* m_pad_7148; void* m_pad_7150; void* m_pad_7158; void* m_pad_7160; void* m_pad_7168; void* m_pad_7170; void* m_pad_7178;
    void* m_pad_7180; void* m_pad_7188; void* m_pad_7190; void* m_pad_7198; void* m_pad_71a0; void* m_pad_71a8; void* m_pad_71b0; void* m_pad_71b8;
    void* m_pad_71c0; void* m_pad_71c8; void* m_pad_71d0; void* m_pad_71d8; void* m_pad_71e0; void* m_pad_71e8; void* m_pad_71f0; void* m_pad_71f8;
    void* m_pad_7200; void* m_pad_7208; void* m_pad_7210; void* m_pad_7218; void* m_pad_7220; void* m_pad_7228; void* m_pad_7230; void* m_pad_7238;
    void* m_pad_7240; void* m_pad_7248; void* m_pad_7250; void* m_pad_7258; void* m_pad_7260; void* m_pad_7268; void* m_pad_7270; void* m_pad_7278;
    void* m_pad_7280; void* m_pad_7288; void* m_pad_7290; void* m_pad_7298; void* m_pad_72a0; void* m_pad_72a8; void* m_pad_72b0; void* m_pad_72b8;
    void* m_pad_72c0; void* m_pad_72c8; void* m_pad_72d0; void* m_pad_72d8; void* m_pad_72e0; void* m_pad_72e8; void* m_pad_72f0; void* m_pad_72f8;
    void* m_pad_7300; void* m_pad_7308; void* m_pad_7310; void* m_pad_7318; void* m_pad_7320; void* m_pad_7328; void* m_pad_7330; void* m_pad_7338;
    void* m_pad_7340; void* m_pad_7348; void* m_pad_7350; void* m_pad_7358; void* m_pad_7360; void* m_pad_7368; void* m_pad_7370; void* m_pad_7378;
    void* m_pad_7380; void* m_pad_7388; void* m_pad_7390; void* m_pad_7398; void* m_pad_73a0; void* m_pad_73a8; void* m_pad_73b0; void* m_pad_73b8;
    void* m_pad_73c0; void* m_pad_73c8; void* m_pad_73d0; void* m_pad_73d8; void* m_pad_73e0; void* m_pad_73e8; void* m_pad_73f0; void* m_pad_73f8;
    void* m_pad_7400; void* m_pad_7408; void* m_pad_7410; void* m_pad_7418; void* m_pad_7420; void* m_pad_7428; void* m_pad_7430; void* m_pad_7438;
    void* m_pad_7440; void* m_pad_7448; void* m_pad_7450; void* m_pad_7458; void* m_pad_7460; void* m_pad_7468; void* m_pad_7470; void* m_pad_7478;
    void* m_pad_7480; void* m_pad_7488; void* m_pad_7490; void* m_pad_7498; void* m_pad_74a0; void* m_pad_74a8; void* m_pad_74b0; void* m_pad_74b8;
    void* m_pad_74c0; void* m_pad_74c8; void* m_pad_74d0; void* m_pad_74d8; void* m_pad_74e0; void* m_pad_74e8; void* m_pad_74f0; void* m_pad_74f8;
    void* m_pad_7500; void* m_pad_7508; void* m_pad_7510; void* m_pad_7518; void* m_pad_7520; void* m_pad_7528; void* m_pad_7530; void* m_pad_7538;
    void* m_pad_7540; void* m_pad_7548; void* m_pad_7550; void* m_pad_7558; void* m_pad_7560; void* m_pad_7568; void* m_pad_7570; void* m_pad_7578;
    void* m_pad_7580; void* m_pad_7588; void* m_pad_7590; void* m_pad_7598; void* m_pad_75a0; void* m_pad_75a8; void* m_pad_75b0; void* m_pad_75b8;
    void* m_pad_75c0; void* m_pad_75c8; void* m_pad_75d0; void* m_pad_75d8; void* m_pad_75e0; void* m_pad_75e8; void* m_pad_75f0; void* m_pad_75f8;
    void* m_pad_7600; void* m_pad_7608; void* m_pad_7610; void* m_pad_7618; void* m_pad_7620; void* m_pad_7628; void* m_pad_7630; void* m_pad_7638;
    void* m_pad_7640; void* m_pad_7648; void* m_pad_7650; void* m_pad_7658; void* m_pad_7660; void* m_pad_7668; void* m_pad_7670; void* m_pad_7678;
    void* m_pad_7680; void* m_pad_7688; void* m_pad_7690; void* m_pad_7698; void* m_pad_76a0; void* m_pad_76a8; void* m_pad_76b0; void* m_pad_76b8;
    void* m_pad_76c0; void* m_pad_76c8; void* m_pad_76d0; void* m_pad_76d8; void* m_pad_76e0; void* m_pad_76e8; void* m_pad_76f0; void* m_pad_76f8;
    void* m_pad_7700; void* m_pad_7708; void* m_pad_7710; void* m_pad_7718; void* m_pad_7720; void* m_pad_7728; void* m_pad_7730; void* m_pad_7738;
    void* m_pad_7740; void* m_pad_7748; void* m_pad_7750; void* m_pad_7758; void* m_pad_7760; void* m_pad_7768; void* m_pad_7770; void* m_pad_7778;
    void* m_pad_7780; void* m_pad_7788; void* m_pad_7790; void* m_pad_7798; void* m_pad_77a0; void* m_pad_77a8; void* m_pad_77b0; void* m_pad_77b8;
    void* m_pad_77c0; void* m_pad_77c8; void* m_pad_77d0; void* m_pad_77d8; void* m_pad_77e0; void* m_pad_77e8; void* m_pad_77f0; void* m_pad_77f8;
    void* m_pad_7800; void* m_pad_7808; void* m_pad_7810; void* m_pad_7818; void* m_pad_7820; void* m_pad_7828; void* m_pad_7830; void* m_pad_7838;
    void* m_pad_7840; void* m_pad_7848; void* m_pad_7850; void* m_pad_7858; void* m_pad_7860; void* m_pad_7868; void* m_pad_7870; void* m_pad_7878;
    void* m_pad_7880; void* m_pad_7888; void* m_pad_7890; void* m_pad_7898; void* m_pad_78a0; void* m_pad_78a8; void* m_pad_78b0; void* m_pad_78b8;
    void* m_pad_78c0; void* m_pad_78c8; void* m_pad_78d0; void* m_pad_78d8; void* m_pad_78e0; void* m_pad_78e8; void* m_pad_78f0; void* m_pad_78f8;
    void* m_pad_7900; void* m_pad_7908; void* m_pad_7910; void* m_pad_7918; void* m_pad_7920; void* m_pad_7928; void* m_pad_7930; void* m_pad_7938;
    void* m_pad_7940; void* m_pad_7948; void* m_pad_7950; void* m_pad_7958; void* m_pad_7960; void* m_pad_7968; void* m_pad_7970; void* m_pad_7978;
    void* m_pad_7980; void* m_pad_7988; void* m_pad_7990; void* m_pad_7998; void* m_pad_79a0; void* m_pad_79a8; void* m_pad_79b0; void* m_pad_79b8;
    void* m_pad_79c0; void* m_pad_79c8; void* m_pad_79d0; void* m_pad_79d8; void* m_pad_79e0; void* m_pad_79e8; void* m_pad_79f0; void* m_pad_79f8;
    void* m_pad_7a00; void* m_pad_7a08; void* m_pad_7a10; void* m_pad_7a18; void* m_pad_7a20; void* m_pad_7a28; void* m_pad_7a30; void* m_pad_7a38;
    void* m_pad_7a40; void* m_pad_7a48; void* m_pad_7a50; void* m_pad_7a58; void* m_pad_7a60; void* m_pad_7a68; void* m_pad_7a70; void* m_pad_7a78;
    void* m_pad_7a80; void* m_pad_7a88; void* m_pad_7a90; void* m_pad_7a98; void* m_pad_7aa0; void* m_pad_7aa8; void* m_pad_7ab0; void* m_pad_7ab8;
    void* m_pad_7ac0; void* m_pad_7ac8; void* m_pad_7ad0; void* m_pad_7ad8; void* m_pad_7ae0; void* m_pad_7ae8; void* m_pad_7af0; void* m_pad_7af8;
    void* m_pad_7b00; void* m_pad_7b08; void* m_pad_7b10; void* m_pad_7b18; void* m_pad_7b20; void* m_pad_7b28; void* m_pad_7b30; void* m_pad_7b38;
    void* m_pad_7b40; void* m_pad_7b48; void* m_pad_7b50; void* m_pad_7b58; void* m_pad_7b60; void* m_pad_7b68; void* m_pad_7b70; void* m_pad_7b78;
    void* m_pad_7b80; void* m_pad_7b88; void* m_pad_7b90; void* m_pad_7b98; void* m_pad_7ba0; void* m_pad_7ba8; void* m_pad_7bb0; void* m_pad_7bb8;
    void* m_pad_7bc0; void* m_pad_7bc8; void* m_pad_7bd0; void* m_pad_7bd8; void* m_pad_7be0; void* m_pad_7be8; void* m_pad_7bf0; void* m_pad_7bf8;
    void* m_pad_7c00; void* m_pad_7c08; void* m_pad_7c10; void* m_pad_7c18; void* m_pad_7c20; void* m_pad_7c28; void* m_pad_7c30; void* m_pad_7c38;
    void* m_pad_7c40; void* m_pad_7c48; void* m_pad_7c50; void* m_pad_7c58; void* m_pad_7c60; void* m_pad_7c68; void* m_pad_7c70; void* m_pad_7c78;
    void* m_pad_7c80; void* m_pad_7c88; void* m_pad_7c90; void* m_pad_7c98; void* m_pad_7ca0; void* m_pad_7ca8; void* m_pad_7cb0; void* m_pad_7cb8;
    void* m_pad_7cc0; void* m_pad_7cc8; void* m_pad_7cd0; void* m_pad_7cd8; void* m_pad_7ce0; void* m_pad_7ce8; void* m_pad_7cf0; void* m_pad_7cf8;
    void* m_pad_7d00; void* m_pad_7d08; void* m_pad_7d10; void* m_pad_7d18; void* m_pad_7d20; void* m_pad_7d28; void* m_pad_7d30; void* m_pad_7d38;
    void* m_pad_7d40; void* m_pad_7d48; void* m_pad_7d50; void* m_pad_7d58; void* m_pad_7d60; void* m_pad_7d68; void* m_pad_7d70; void* m_pad_7d78;
    void* m_pad_7d80; void* m_pad_7d88; void* m_pad_7d90; void* m_pad_7d98; void* m_pad_7da0; void* m_pad_7da8; void* m_pad_7db0; void* m_pad_7db8;
    void* m_pad_7dc0; void* m_pad_7dc8; void* m_pad_7dd0; void* m_pad_7dd8; void* m_pad_7de0; void* m_pad_7de8; void* m_pad_7df0; void* m_pad_7df8;
    void* m_pad_7e00; void* m_pad_7e08; void* m_pad_7e10; void* m_pad_7e18; void* m_pad_7e20; void* m_pad_7e28; void* m_pad_7e30; void* m_pad_7e38;
    void* m_pad_7e40; void* m_pad_7e48; void* m_pad_7e50; void* m_pad_7e58; void* m_pad_7e60; void* m_pad_7e68; void* m_pad_7e70; void* m_pad_7e78;
    void* m_pad_7e80; void* m_pad_7e88; void* m_pad_7e90; void* m_pad_7e98; void* m_pad_7ea0; void* m_pad_7ea8; void* m_pad_7eb0; void* m_pad_7eb8;
    void* m_pad_7ec0; void* m_pad_7ec8; void* m_pad_7ed0; void* m_pad_7ed8; void* m_pad_7ee0; void* m_pad_7ee8; void* m_pad_7ef0; void* m_pad_7ef8;
    void* m_pad_7f00; void* m_pad_7f08; void* m_pad_7f10; void* m_pad_7f18; void* m_pad_7f20; void* m_pad_7f28; void* m_pad_7f30; void* m_pad_7f38;
    void* m_pad_7f40; void* m_pad_7f48; void* m_pad_7f50; void* m_pad_7f58; void* m_pad_7f60; void* m_pad_7f68; void* m_pad_7f70; void* m_pad_7f78;
    void* m_pad_7f80; void* m_pad_7f88; void* m_pad_7f90; void* m_pad_7f98; void* m_pad_7fa0; void* m_pad_7fa8; void* m_pad_7fb0; void* m_pad_7fb8;
    void* m_pad_7fc0; void* m_pad_7fc8; void* m_pad_7fd0; void* m_pad_7fd8; void* m_pad_7fe0; void* m_pad_7fe8; void* m_pad_7ff0; void* m_pad_7ff8;
    void* m_pad_8000; void* m_pad_8008; void* m_pad_8010; void* m_pad_8018; void* m_pad_8020; void* m_pad_8028; void* m_pad_8030; void* m_pad_8038;
    void* m_pad_8040; void* m_pad_8048; void* m_pad_8050; void* m_pad_8058; void* m_pad_8060; void* m_pad_8068; void* m_pad_8070; void* m_pad_8078;
    void* m_pad_8080; void* m_pad_8088; void* m_pad_8090; void* m_pad_8098; void* m_pad_80a0; void* m_pad_80a8; void* m_pad_80b0; void* m_pad_80b8;
    void* m_pad_80c0; void* m_pad_80c8; void* m_pad_80d0; void* m_pad_80d8; void* m_pad_80e0; void* m_pad_80e8; void* m_pad_80f0; void* m_pad_80f8;
    void* m_pad_8100; void* m_pad_8108; void* m_pad_8110; void* m_pad_8118; void* m_pad_8120; void* m_pad_8128; void* m_pad_8130; void* m_pad_8138;
    void* m_pad_8140; void* m_pad_8148; void* m_pad_8150; void* m_pad_8158; void* m_pad_8160; void* m_pad_8168; void* m_pad_8170; void* m_pad_8178;
    void* m_pad_8180; void* m_pad_8188; void* m_pad_8190; void* m_pad_8198; void* m_pad_81a0; void* m_pad_81a8; void* m_pad_81b0; void* m_pad_81b8;
    void* m_pad_81c0; void* m_pad_81c8; void* m_pad_81d0; void* m_pad_81d8; void* m_pad_81e0; void* m_pad_81e8; void* m_pad_81f0; void* m_pad_81f8;
    void* m_pad_8200; void* m_pad_8208; void* m_pad_8210; void* m_pad_8218; void* m_pad_8220; void* m_pad_8228; void* m_pad_8230; void* m_pad_8238;
    void* m_pad_8240; void* m_pad_8248; void* m_pad_8250; void* m_pad_8258; void* m_pad_8260; void* m_pad_8268; void* m_pad_8270; void* m_pad_8278;
    void* m_pad_8280; void* m_pad_8288; void* m_pad_8290; void* m_pad_8298; void* m_pad_82a0; void* m_pad_82a8; void* m_pad_82b0; void* m_pad_82b8;
    void* m_pad_82c0; void* m_pad_82c8; void* m_pad_82d0; void* m_pad_82d8; void* m_pad_82e0; void* m_pad_82e8; void* m_pad_82f0; void* m_pad_82f8;
    void* m_pad_8300; void* m_pad_8308; void* m_pad_8310; void* m_pad_8318; void* m_pad_8320; void* m_pad_8328; void* m_pad_8330; void* m_pad_8338;
    void* m_pad_8340; void* m_pad_8348; void* m_pad_8350; void* m_pad_8358; void* m_pad_8360; void* m_pad_8368; void* m_pad_8370; void* m_pad_8378;
    void* m_pad_8380; void* m_pad_8388; void* m_pad_8390; void* m_pad_8398; void* m_pad_83a0; void* m_pad_83a8; void* m_pad_83b0; void* m_pad_83b8;
    void* m_pad_83c0; void* m_pad_83c8; void* m_pad_83d0; void* m_pad_83d8; void* m_pad_83e0; void* m_pad_83e8; void* m_pad_83f0; void* m_pad_83f8;
    void* m_pad_8400; void* m_pad_8408; void* m_pad_8410; void* m_pad_8418; void* m_pad_8420; void* m_pad_8428; void* m_pad_8430; void* m_pad_8438;
    void* m_pad_8440; void* m_pad_8448; void* m_pad_8450; void* m_pad_8458; void* m_pad_8460; void* m_pad_8468; void* m_pad_8470; void* m_pad_8478;
    void* m_pad_8480; void* m_pad_8488; void* m_pad_8490; void* m_pad_8498; void* m_pad_84a0; void* m_pad_84a8; void* m_pad_84b0; void* m_pad_84b8;
    void* m_pad_84c0; void* m_pad_84c8; void* m_pad_84d0; void* m_pad_84d8; void* m_pad_84e0; void* m_pad_84e8; void* m_pad_84f0; void* m_pad_84f8;
    void* m_pad_8500; void* m_pad_8508; void* m_pad_8510; void* m_pad_8518; void* m_pad_8520; void* m_pad_8528; void* m_pad_8530; void* m_pad_8538;
    void* m_pad_8540; void* m_pad_8548; void* m_pad_8550; void* m_pad_8558; void* m_pad_8560; void* m_pad_8568; void* m_pad_8570; void* m_pad_8578;
    void* m_pad_8580; void* m_pad_8588; void* m_pad_8590; void* m_pad_8598; void* m_pad_85a0; void* m_pad_85a8; void* m_pad_85b0; void* m_pad_85b8;
    void* m_pad_85c0; void* m_pad_85c8; void* m_pad_85d0; void* m_pad_85d8; void* m_pad_85e0; void* m_pad_85e8; void* m_pad_85f0; void* m_pad_85f8;
    void* m_pad_8600; void* m_pad_8608; void* m_pad_8610; void* m_pad_8618; void* m_pad_8620; void* m_pad_8628; void* m_pad_8630; void* m_pad_8638;
    void* m_pad_8640; void* m_pad_8648; void* m_pad_8650; void* m_pad_8658; void* m_pad_8660; void* m_pad_8668; void* m_pad_8670; void* m_pad_8678;
    void* m_pad_8680; void* m_pad_8688; void* m_pad_8690; void* m_pad_8698; void* m_pad_86a0; void* m_pad_86a8; void* m_pad_86b0; void* m_pad_86b8;
    void* m_pad_86c0; void* m_pad_86c8; void* m_pad_86d0; void* m_pad_86d8; void* m_pad_86e0; void* m_pad_86e8; void* m_pad_86f0; void* m_pad_86f8;
    void* m_pad_8700; void* m_pad_8708; void* m_pad_8710; void* m_pad_8718; void* m_pad_8720; void* m_pad_8728; void* m_pad_8730; void* m_pad_8738;
    void* m_pad_8740; void* m_pad_8748; void* m_pad_8750; void* m_pad_8758; void* m_pad_8760; void* m_pad_8768; void* m_pad_8770; void* m_pad_8778;
    void* m_pad_8780; void* m_pad_8788; void* m_pad_8790; void* m_pad_8798; void* m_pad_87a0; void* m_pad_87a8; void* m_pad_87b0; void* m_pad_87b8;
    void* m_pad_87c0; void* m_pad_87c8; void* m_pad_87d0; void* m_pad_87d8; void* m_pad_87e0; void* m_pad_87e8; void* m_pad_87f0; void* m_pad_87f8;
    void* m_pad_8800; void* m_pad_8808; void* m_pad_8810; void* m_pad_8818; void* m_pad_8820; void* m_pad_8828; void* m_pad_8830; void* m_pad_8838;
    void* m_pad_8840; void* m_pad_8848; void* m_pad_8850; void* m_pad_8858; void* m_pad_8860; void* m_pad_8868; void* m_pad_8870; void* m_pad_8878;
    void* m_pad_8880; void* m_pad_8888; void* m_pad_8890; void* m_pad_8898; void* m_pad_88a0; void* m_pad_88a8; void* m_pad_88b0; void* m_pad_88b8;
    void* m_pad_88c0; void* m_pad_88c8; void* m_pad_88d0; void* m_pad_88d8; void* m_pad_88e0; void* m_pad_88e8; void* m_pad_88f0; void* m_pad_88f8;
    void* m_pad_8900; void* m_pad_8908; void* m_pad_8910; void* m_pad_8918; void* m_pad_8920; void* m_pad_8928; void* m_pad_8930; void* m_pad_8938;
    void* m_pad_8940; void* m_pad_8948; void* m_pad_8950; void* m_pad_8958; void* m_pad_8960; void* m_pad_8968; void* m_pad_8970; void* m_pad_8978;
    void* m_pad_8980; void* m_pad_8988; void* m_pad_8990; void* m_pad_8998; void* m_pad_89a0; void* m_pad_89a8; void* m_pad_89b0; void* m_pad_89b8;
    void* m_pad_89c0; void* m_pad_89c8; void* m_pad_89d0; void* m_pad_89d8; void* m_pad_89e0; void* m_pad_89e8; void* m_pad_89f0; void* m_pad_89f8;
    void* m_pad_8a00; void* m_pad_8a08; void* m_pad_8a10; void* m_pad_8a18; void* m_pad_8a20; void* m_pad_8a28; void* m_pad_8a30; void* m_pad_8a38;
    void* m_pad_8a40; void* m_pad_8a48; void* m_pad_8a50; void* m_pad_8a58; void* m_pad_8a60; void* m_pad_8a68; void* m_pad_8a70; void* m_pad_8a78;
    void* m_pad_8a80; void* m_pad_8a88; void* m_pad_8a90; void* m_pad_8a98; void* m_pad_8aa0; void* m_pad_8aa8; void* m_pad_8ab0; void* m_pad_8ab8;
    void* m_pad_8ac0; void* m_pad_8ac8; void* m_pad_8ad0; void* m_pad_8ad8; void* m_pad_8ae0; void* m_pad_8ae8; void* m_pad_8af0; void* m_pad_8af8;
    void* m_pad_8b00; void* m_pad_8b08; void* m_pad_8b10; void* m_pad_8b18; void* m_pad_8b20; void* m_pad_8b28; void* m_pad_8b30; void* m_pad_8b38;
    void* m_pad_8b40; void* m_pad_8b48; void* m_pad_8b50; void* m_pad_8b58; void* m_pad_8b60; void* m_pad_8b68; void* m_pad_8b70; void* m_pad_8b78;
    void* m_pad_8b80; void* m_pad_8b88; void* m_pad_8b90; void* m_pad_8b98; void* m_pad_8ba0; void* m_pad_8ba8; void* m_pad_8bb0; void* m_pad_8bb8;
    void* m_pad_8bc0; void* m_pad_8bc8; void* m_pad_8bd0; void* m_pad_8bd8; void* m_pad_8be0; void* m_pad_8be8; void* m_pad_8bf0; void* m_pad_8bf8;
    void* m_pad_8c00; void* m_pad_8c08; void* m_pad_8c10; void* m_pad_8c18; void* m_pad_8c20; void* m_pad_8c28; void* m_pad_8c30; void* m_pad_8c38;
    void* m_pad_8c40; void* m_pad_8c48; void* m_pad_8c50; void* m_pad_8c58; void* m_pad_8c60; void* m_pad_8c68; void* m_pad_8c70; void* m_pad_8c78;
    void* m_pad_8c80; void* m_pad_8c88; void* m_pad_8c90; void* m_pad_8c98; void* m_pad_8ca0; void* m_pad_8ca8; void* m_pad_8cb0; void* m_pad_8cb8;
    void* m_pad_8cc0; void* m_pad_8cc8; void* m_pad_8cd0; void* m_pad_8cd8; void* m_pad_8ce0; void* m_pad_8ce8; void* m_pad_8cf0; void* m_pad_8cf8;
    void* m_pad_8d00; void* m_pad_8d08; void* m_pad_8d10; void* m_pad_8d18; void* m_pad_8d20; void* m_pad_8d28; void* m_pad_8d30; void* m_pad_8d38;
    void* m_pad_8d40; void* m_pad_8d48; void* m_pad_8d50; void* m_pad_8d58; void* m_pad_8d60; void* m_pad_8d68; void* m_pad_8d70; void* m_pad_8d78;
    void* m_pad_8d80; void* m_pad_8d88; void* m_pad_8d90; void* m_pad_8d98; void* m_pad_8da0; void* m_pad_8da8; void* m_pad_8db0; void* m_pad_8db8;
    void* m_pad_8dc0; void* m_pad_8dc8; void* m_pad_8dd0; void* m_pad_8dd8; void* m_pad_8de0; void* m_pad_8de8; void* m_pad_8df0; void* m_pad_8df8;
    void* m_pad_8e00; void* m_pad_8e08; void* m_pad_8e10; void* m_pad_8e18; void* m_pad_8e20; void* m_pad_8e28; void* m_pad_8e30; void* m_pad_8e38;
    void* m_pad_8e40; void* m_pad_8e48; void* m_pad_8e50; void* m_pad_8e58; void* m_pad_8e60; void* m_pad_8e68; void* m_pad_8e70; void* m_pad_8e78;
    void* m_pad_8e80; void* m_pad_8e88; void* m_pad_8e90; void* m_pad_8e98; void* m_pad_8ea0; void* m_pad_8ea8; void* m_pad_8eb0; void* m_pad_8eb8;
    void* m_pad_8ec0; void* m_pad_8ec8; void* m_pad_8ed0; void* m_pad_8ed8; void* m_pad_8ee0; void* m_pad_8ee8; void* m_pad_8ef0; void* m_pad_8ef8;
    void* m_pad_8f00; void* m_pad_8f08; void* m_pad_8f10; void* m_pad_8f18; void* m_pad_8f20; void* m_pad_8f28; void* m_pad_8f30; void* m_pad_8f38;
    void* m_pad_8f40; void* m_pad_8f48; void* m_pad_8f50; void* m_pad_8f58; void* m_pad_8f60; void* m_pad_8f68; void* m_pad_8f70; void* m_pad_8f78;
    void* m_pad_8f80; void* m_pad_8f88; void* m_pad_8f90; void* m_pad_8f98; void* m_pad_8fa0; void* m_pad_8fa8; void* m_pad_8fb0; void* m_pad_8fb8;
    void* m_pad_8fc0; void* m_pad_8fc8; void* m_pad_8fd0; void* m_pad_8fd8; void* m_pad_8fe0; void* m_pad_8fe8; void* m_pad_8ff0; void* m_pad_8ff8;
    void* m_pad_9000; void* m_pad_9008; void* m_pad_9010; void* m_pad_9018; void* m_pad_9020; void* m_pad_9028; void* m_pad_9030; void* m_pad_9038;
    void* m_pad_9040; void* m_pad_9048; void* m_pad_9050; void* m_pad_9058; void* m_pad_9060; void* m_pad_9068; void* m_pad_9070; void* m_pad_9078;
    void* m_pad_9080; void* m_pad_9088; void* m_pad_9090; void* m_pad_9098; void* m_pad_90a0; void* m_pad_90a8; void* m_pad_90b0; void* m_pad_90b8;
    void* m_pad_90c0; void* m_pad_90c8; void* m_pad_90d0; void* m_pad_90d8; void* m_pad_90e0; void* m_pad_90e8; void* m_pad_90f0; void* m_pad_90f8;
    void* m_pad_9100; void* m_pad_9108; void* m_pad_9110; void* m_pad_9118; void* m_pad_9120; void* m_pad_9128; void* m_pad_9130; void* m_pad_9138;
    void* m_pad_9140; void* m_pad_9148; void* m_pad_9150; void* m_pad_9158; void* m_pad_9160; void* m_pad_9168; void* m_pad_9170; void* m_pad_9178;
    void* m_pad_9180; void* m_pad_9188; void* m_pad_9190; void* m_pad_9198; void* m_pad_91a0; void* m_pad_91a8; void* m_pad_91b0; void* m_pad_91b8;
    void* m_pad_91c0; void* m_pad_91c8; void* m_pad_91d0; void* m_pad_91d8; void* m_pad_91e0; void* m_pad_91e8; void* m_pad_91f0; void* m_pad_91f8;
    void* m_pad_9200; void* m_pad_9208; void* m_pad_9210; void* m_pad_9218; void* m_pad_9220; void* m_pad_9228; void* m_pad_9230; void* m_pad_9238;
    void* m_pad_9240; void* m_pad_9248; void* m_pad_9250; void* m_pad_9258; void* m_pad_9260; void* m_pad_9268; void* m_pad_9270; void* m_pad_9278;
    void* m_pad_9280; void* m_pad_9288; void* m_pad_9290; void* m_pad_9298; void* m_pad_92a0; void* m_pad_92a8; void* m_pad_92b0; void* m_pad_92b8;
    void* m_pad_92c0; void* m_pad_92c8; void* m_pad_92d0; void* m_pad_92d8; void* m_pad_92e0; void* m_pad_92e8; void* m_pad_92f0; void* m_pad_92f8;
    void* m_pad_9300; void* m_pad_9308; void* m_pad_9310; void* m_pad_9318; void* m_pad_9320; void* m_pad_9328; void* m_pad_9330; void* m_pad_9338;
    void* m_pad_9340; void* m_pad_9348; void* m_pad_9350; void* m_pad_9358; void* m_pad_9360; void* m_pad_9368; void* m_pad_9370; void* m_pad_9378;
    void* m_pad_9380; void* m_pad_9388; void* m_pad_9390; void* m_pad_9398; void* m_pad_93a0; void* m_pad_93a8; void* m_pad_93b0; void* m_pad_93b8;
    void* m_pad_93c0; void* m_pad_93c8; void* m_pad_93d0; void* m_pad_93d8; void* m_pad_93e0; void* m_pad_93e8; void* m_pad_93f0; void* m_pad_93f8;
    void* m_pad_9400; void* m_pad_9408; void* m_pad_9410; void* m_pad_9418; void* m_pad_9420; void* m_pad_9428; void* m_pad_9430; void* m_pad_9438;
    void* m_pad_9440; void* m_pad_9448; void* m_pad_9450; void* m_pad_9458; void* m_pad_9460; void* m_pad_9468; void* m_pad_9470; void* m_pad_9478;
    void* m_pad_9480; void* m_pad_9488; void* m_pad_9490; void* m_pad_9498; void* m_pad_94a0; void* m_pad_94a8; void* m_pad_94b0; void* m_pad_94b8;
    void* m_pad_94c0; void* m_pad_94c8; void* m_pad_94d0; void* m_pad_94d8; void* m_pad_94e0; void* m_pad_94e8; void* m_pad_94f0; void* m_pad_94f8;
    void* m_pad_9500; void* m_pad_9508; void* m_pad_9510; void* m_pad_9518; void* m_pad_9520; void* m_pad_9528; void* m_pad_9530; void* m_pad_9538;
    void* m_pad_9540; void* m_pad_9548; void* m_pad_9550; void* m_pad_9558; void* m_pad_9560; void* m_pad_9568; void* m_pad_9570; void* m_pad_9578;
    void* m_pad_9580; void* m_pad_9588; void* m_pad_9590; void* m_pad_9598; void* m_pad_95a0; void* m_pad_95a8; void* m_pad_95b0; void* m_pad_95b8;
    void* m_pad_95c0; void* m_pad_95c8; void* m_pad_95d0; void* m_pad_95d8; void* m_pad_95e0; void* m_pad_95e8; void* m_pad_95f0; void* m_pad_95f8;
    void* m_pad_9600; void* m_pad_9608; void* m_pad_9610; void* m_pad_9618; void* m_pad_9620; void* m_pad_9628; void* m_pad_9630; void* m_pad_9638;
    void* m_pad_9640; void* m_pad_9648; void* m_pad_9650; void* m_pad_9658; void* m_pad_9660; void* m_pad_9668; void* m_pad_9670; void* m_pad_9678;
    void* m_pad_9680; void* m_pad_9688; void* m_pad_9690; void* m_pad_9698; void* m_pad_96a0; void* m_pad_96a8; void* m_pad_96b0; void* m_pad_96b8;
    void* m_pad_96c0; void* m_pad_96c8; void* m_pad_96d0; void* m_pad_96d8; void* m_pad_96e0; void* m_pad_96e8; void* m_pad_96f0; void* m_pad_96f8;
    void* m_pad_9700; void* m_pad_9708; void* m_pad_9710; void* m_pad_9718; void* m_pad_9720; void* m_pad_9728; void* m_pad_9730; void* m_pad_9738;
    void* m_pad_9740; void* m_pad_9748; void* m_pad_9750; void* m_pad_9758; void* m_pad_9760; void* m_pad_9768; void* m_pad_9770; void* m_pad_9778;
    void* m_pad_9780; void* m_pad_9788; void* m_pad_9790; void* m_pad_9798; void* m_pad_97a0; void* m_pad_97a8; void* m_pad_97b0; void* m_pad_97b8;
    void* m_pad_97c0; void* m_pad_97c8; void* m_pad_97d0; void* m_pad_97d8; void* m_pad_97e0; void* m_pad_97e8; void* m_pad_97f0; void* m_pad_97f8;
    void* m_pad_9800; void* m_pad_9808; void* m_pad_9810; void* m_pad_9818; void* m_pad_9820; void* m_pad_9828; void* m_pad_9830; void* m_pad_9838;
    void* m_pad_9840; void* m_pad_9848; void* m_pad_9850; void* m_pad_9858; void* m_pad_9860; void* m_pad_9868; void* m_pad_9870; void* m_pad_9878;
    void* m_pad_9880; void* m_pad_9888; void* m_pad_9890; void* m_pad_9898; void* m_pad_98a0; void* m_pad_98a8; void* m_pad_98b0; void* m_pad_98b8;
    void* m_pad_98c0; void* m_pad_98c8; void* m_pad_98d0; void* m_pad_98d8; void* m_pad_98e0; void* m_pad_98e8; void* m_pad_98f0; void* m_pad_98f8;
    void* m_pad_9900; void* m_pad_9908; void* m_pad_9910; void* m_pad_9918; void* m_pad_9920; void* m_pad_9928; void* m_pad_9930; void* m_pad_9938;
    void* m_pad_9940; void* m_pad_9948; void* m_pad_9950; void* m_pad_9958; void* m_pad_9960; void* m_pad_9968; void* m_pad_9970; void* m_pad_9978;
    void* m_pad_9980; void* m_pad_9988; void* m_pad_9990; void* m_pad_9998; void* m_pad_99a0; void* m_pad_99a8; void* m_pad_99b0; void* m_pad_99b8;
    void* m_pad_99c0; void* m_pad_99c8; void* m_pad_99d0; void* m_pad_99d8; void* m_pad_99e0; void* m_pad_99e8; void* m_pad_99f0; void* m_pad_99f8;
    void* m_pad_9a00; void* m_pad_9a08; void* m_pad_9a10; void* m_pad_9a18; void* m_pad_9a20; void* m_pad_9a28; void* m_pad_9a30; void* m_pad_9a38;
    void* m_pad_9a40; void* m_pad_9a48; void* m_pad_9a50; void* m_pad_9a58; void* m_pad_9a60; void* m_pad_9a68; void* m_pad_9a70; void* m_pad_9a78;
    void* m_pad_9a80; void* m_pad_9a88; void* m_pad_9a90; void* m_pad_9a98; void* m_pad_9aa0; void* m_pad_9aa8; void* m_pad_9ab0; void* m_pad_9ab8;
    void* m_pad_9ac0; void* m_pad_9ac8; void* m_pad_9ad0; void* m_pad_9ad8; void* m_pad_9ae0; void* m_pad_9ae8; void* m_pad_9af0; void* m_pad_9af8;
    void* m_pad_9b00; void* m_pad_9b08; void* m_pad_9b10; void* m_pad_9b18; void* m_pad_9b20; void* m_pad_9b28; void* m_pad_9b30; void* m_pad_9b38;
    void* m_pad_9b40; void* m_pad_9b48; void* m_pad_9b50; void* m_pad_9b58; void* m_pad_9b60; void* m_pad_9b68; void* m_pad_9b70; void* m_pad_9b78;
    void* m_pad_9b80; void* m_pad_9b88; void* m_pad_9b90; void* m_pad_9b98; void* m_pad_9ba0; void* m_pad_9ba8; void* m_pad_9bb0; void* m_pad_9bb8;
    void* m_pad_9bc0; void* m_pad_9bc8; void* m_pad_9bd0; void* m_pad_9bd8; void* m_pad_9be0; void* m_pad_9be8; void* m_pad_9bf0; void* m_pad_9bf8;
    void* m_pad_9c00; void* m_pad_9c08; void* m_pad_9c10; void* m_pad_9c18; void* m_pad_9c20; void* m_pad_9c28; void* m_pad_9c30; void* m_pad_9c38;
    void* m_pad_9c40; void* m_pad_9c48; void* m_pad_9c50; void* m_pad_9c58; void* m_pad_9c60; void* m_pad_9c68; void* m_pad_9c70; void* m_pad_9c78;
    void* m_pad_9c80; void* m_pad_9c88; void* m_pad_9c90; void* m_pad_9c98; void* m_pad_9ca0; void* m_pad_9ca8; void* m_pad_9cb0; void* m_pad_9cb8;
    void* m_pad_9cc0; void* m_pad_9cc8; void* m_pad_9cd0; void* m_pad_9cd8; void* m_pad_9ce0; void* m_pad_9ce8; void* m_pad_9cf0; void* m_pad_9cf8;
    void* m_pad_9d00; void* m_pad_9d08; void* m_pad_9d10; void* m_pad_9d18; void* m_pad_9d20; void* m_pad_9d28; void* m_pad_9d30; void* m_pad_9d38;
    void* m_pad_9d40; void* m_pad_9d48; void* m_pad_9d50; void* m_pad_9d58; void* m_pad_9d60; void* m_pad_9d68; void* m_pad_9d70; void* m_pad_9d78;
    void* m_pad_9d80; void* m_pad_9d88; void* m_pad_9d90; void* m_pad_9d98; void* m_pad_9da0; void* m_pad_9da8; void* m_pad_9db0; void* m_pad_9db8;
    void* m_pad_9dc0; void* m_pad_9dc8; void* m_pad_9dd0; void* m_pad_9dd8; void* m_pad_9de0; void* m_pad_9de8; void* m_pad_9df0; void* m_pad_9df8;
    void* m_pad_9e00; void* m_pad_9e08; void* m_pad_9e10; void* m_pad_9e18; void* m_pad_9e20; void* m_pad_9e28; void* m_pad_9e30; void* m_pad_9e38;
    void* m_pad_9e40; void* m_pad_9e48; void* m_pad_9e50; void* m_pad_9e58; void* m_pad_9e60; void* m_pad_9e68; void* m_pad_9e70; void* m_pad_9e78;
    void* m_pad_9e80; void* m_pad_9e88; void* m_pad_9e90; void* m_pad_9e98; void* m_pad_9ea0; void* m_pad_9ea8; void* m_pad_9eb0; void* m_pad_9eb8;
    void* m_pad_9ec0; void* m_pad_9ec8; void* m_pad_9ed0; void* m_pad_9ed8; void* m_pad_9ee0; void* m_pad_9ee8; void* m_pad_9ef0; void* m_pad_9ef8;
    void* m_pad_9f00; void* m_pad_9f08; void* m_pad_9f10; void* m_pad_9f18; void* m_pad_9f20; void* m_pad_9f28; void* m_pad_9f30; void* m_pad_9f38;
    void* m_pad_9f40; void* m_pad_9f48; void* m_pad_9f50; void* m_pad_9f58; void* m_pad_9f60; void* m_pad_9f68; void* m_pad_9f70; void* m_pad_9f78;
    void* m_pad_9f80; void* m_pad_9f88; void* m_pad_9f90; void* m_pad_9f98; void* m_pad_9fa0; void* m_pad_9fa8; void* m_pad_9fb0; void* m_pad_9fb8;
    void* m_pad_9fc0; void* m_pad_9fc8; void* m_pad_9fd0; void* m_pad_9fd8; void* m_pad_9fe0; void* m_pad_9fe8; void* m_pad_9ff0; void* m_pad_9ff8;
    void* m_pad_a000; void* m_pad_a008; void* m_pad_a010; void* m_pad_a018; void* m_pad_a020; void* m_pad_a028; void* m_pad_a030; void* m_pad_a038;
    void* m_pad_a040; void* m_pad_a048; void* m_pad_a050; void* m_pad_a058; void* m_pad_a060; void* m_pad_a068; void* m_pad_a070; void* m_pad_a078;
    void* m_pad_a080; void* m_pad_a088; void* m_pad_a090; void* m_pad_a098; void* m_pad_a0a0; void* m_pad_a0a8; void* m_pad_a0b0; void* m_pad_a0b8;
    void* m_pad_a0c0; void* m_pad_a0c8; void* m_pad_a0d0; void* m_pad_a0d8; void* m_pad_a0e0; void* m_pad_a0e8; void* m_pad_a0f0; void* m_pad_a0f8;
    void* m_pad_a100; void* m_pad_a108; void* m_pad_a110; void* m_pad_a118; void* m_pad_a120; void* m_pad_a128; void* m_pad_a130; void* m_pad_a138;
    void* m_pad_a140; void* m_pad_a148; void* m_pad_a150; void* m_pad_a158; void* m_pad_a160; void* m_pad_a168; void* m_pad_a170; void* m_pad_a178;
    void* m_pad_a180; void* m_pad_a188; void* m_pad_a190; void* m_pad_a198; void* m_pad_a1a0; void* m_pad_a1a8; void* m_pad_a1b0; void* m_pad_a1b8;
    void* m_pad_a1c0; void* m_pad_a1c8; void* m_pad_a1d0; void* m_pad_a1d8; void* m_pad_a1e0; void* m_pad_a1e8; void* m_pad_a1f0; void* m_pad_a1f8;
    void* m_pad_a200; void* m_pad_a208; void* m_pad_a210; void* m_pad_a218; void* m_pad_a220; void* m_pad_a228; void* m_pad_a230; void* m_pad_a238;
    void* m_pad_a240; void* m_pad_a248; void* m_pad_a250; void* m_pad_a258; void* m_pad_a260; void* m_pad_a268; void* m_pad_a270; void* m_pad_a278;
    void* m_pad_a280; void* m_pad_a288; void* m_pad_a290; void* m_pad_a298; void* m_pad_a2a0; void* m_pad_a2a8; void* m_pad_a2b0; void* m_pad_a2b8;
    void* m_pad_a2c0; void* m_pad_a2c8; void* m_pad_a2d0; void* m_pad_a2d8; void* m_pad_a2e0; void* m_pad_a2e8; void* m_pad_a2f0; void* m_pad_a2f8;
    void* m_pad_a300; void* m_pad_a308; void* m_pad_a310; void* m_pad_a318; void* m_pad_a320; void* m_pad_a328; void* m_pad_a330; void* m_pad_a338;
    void* m_pad_a340; void* m_pad_a348; void* m_pad_a350; void* m_pad_a358; void* m_pad_a360; void* m_pad_a368; void* m_pad_a370; void* m_pad_a378;
    void* m_pad_a380; void* m_pad_a388; void* m_pad_a390; void* m_pad_a398; void* m_pad_a3a0; void* m_pad_a3a8; void* m_pad_a3b0; void* m_pad_a3b8;
    void* m_pad_a3c0; void* m_pad_a3c8; void* m_pad_a3d0; void* m_pad_a3d8; void* m_pad_a3e0; void* m_pad_a3e8; void* m_pad_a3f0; void* m_pad_a3f8;
    void* m_pad_a400; void* m_pad_a408; void* m_pad_a410; void* m_pad_a418; void* m_pad_a420; void* m_pad_a428; void* m_pad_a430; void* m_pad_a438;
    void* m_pad_a440; void* m_pad_a448; void* m_pad_a450; void* m_pad_a458; void* m_pad_a460; void* m_pad_a468; void* m_pad_a470; void* m_pad_a478;
    void* m_pad_a480; void* m_pad_a488; void* m_pad_a490; void* m_pad_a498; void* m_pad_a4a0; void* m_pad_a4a8; void* m_pad_a4b0; void* m_pad_a4b8;
    void* m_pad_a4c0; void* m_pad_a4c8; void* m_pad_a4d0; void* m_pad_a4d8; void* m_pad_a4e0; void* m_pad_a4e8; void* m_pad_a4f0; void* m_pad_a4f8;
    void* m_pad_a500; void* m_pad_a508; void* m_pad_a510; void* m_pad_a518; void* m_pad_a520; void* m_pad_a528; void* m_pad_a530; void* m_pad_a538;
    void* m_pad_a540; void* m_pad_a548; void* m_pad_a550; void* m_pad_a558; void* m_pad_a560; void* m_pad_a568; void* m_pad_a570; void* m_pad_a578;
    void* m_pad_a580; void* m_pad_a588; void* m_pad_a590; void* m_pad_a598; void* m_pad_a5a0; void* m_pad_a5a8; void* m_pad_a5b0; void* m_pad_a5b8;
    void* m_pad_a5c0; void* m_pad_a5c8; void* m_pad_a5d0; void* m_pad_a5d8; void* m_pad_a5e0; void* m_pad_a5e8; void* m_pad_a5f0; void* m_pad_a5f8;
    void* m_pad_a600; void* m_pad_a608; void* m_pad_a610; void* m_pad_a618; void* m_pad_a620; void* m_pad_a628; void* m_pad_a630; void* m_pad_a638;
    void* m_pad_a640; void* m_pad_a648; void* m_pad_a650; void* m_pad_a658; void* m_pad_a660; void* m_pad_a668; void* m_pad_a670; void* m_pad_a678;
    void* m_pad_a680; void* m_pad_a688; void* m_pad_a690; void* m_pad_a698; void* m_pad_a6a0; void* m_pad_a6a8; void* m_pad_a6b0; void* m_pad_a6b8;
    void* m_pad_a6c0; void* m_pad_a6c8; void* m_pad_a6d0; void* m_pad_a6d8; void* m_pad_a6e0; void* m_pad_a6e8; void* m_pad_a6f0; void* m_pad_a6f8;
    void* m_pad_a700; void* m_pad_a708; void* m_pad_a710; void* m_pad_a718; void* m_pad_a720; void* m_pad_a728; void* m_pad_a730; void* m_pad_a738;
    void* m_pad_a740; void* m_pad_a748; void* m_pad_a750; void* m_pad_a758; void* m_pad_a760; void* m_pad_a768; void* m_pad_a770; void* m_pad_a778;
    void* m_pad_a780; void* m_pad_a788; void* m_pad_a790; void* m_pad_a798; void* m_pad_a7a0; void* m_pad_a7a8; void* m_pad_a7b0; void* m_pad_a7b8;
    void* m_pad_a7c0; void* m_pad_a7c8; void* m_pad_a7d0; void* m_pad_a7d8; void* m_pad_a7e0; void* m_pad_a7e8; void* m_pad_a7f0; void* m_pad_a7f8;
    void* m_pad_a800; void* m_pad_a808; void* m_pad_a810; void* m_pad_a818; void* m_pad_a820; void* m_pad_a828; void* m_pad_a830; void* m_pad_a838;
    void* m_pad_a840; void* m_pad_a848; void* m_pad_a850; void* m_pad_a858; void* m_pad_a860; void* m_pad_a868; void* m_pad_a870; void* m_pad_a878;
    void* m_pad_a880; void* m_pad_a888; void* m_pad_a890; void* m_pad_a898; void* m_pad_a8a0; void* m_pad_a8a8; void* m_pad_a8b0; void* m_pad_a8b8;
    void* m_pad_a8c0; void* m_pad_a8c8; void* m_pad_a8d0; void* m_pad_a8d8; void* m_pad_a8e0; void* m_pad_a8e8; void* m_pad_a8f0; void* m_pad_a8f8;
    void* m_pad_a900; void* m_pad_a908; void* m_pad_a910; void* m_pad_a918; void* m_pad_a920; void* m_pad_a928; void* m_pad_a930; void* m_pad_a938;
    void* m_pad_a940; void* m_pad_a948; void* m_pad_a950; void* m_pad_a958; void* m_pad_a960; void* m_pad_a968; void* m_pad_a970; void* m_pad_a978;
    void* m_pad_a980; void* m_pad_a988; void* m_pad_a990; void* m_pad_a998; void* m_pad_a9a0; void* m_pad_a9a8; void* m_pad_a9b0; void* m_pad_a9b8;
    void* m_pad_a9c0; void* m_pad_a9c8; void* m_pad_a9d0; void* m_pad_a9d8; void* m_pad_a9e0; void* m_pad_a9e8; void* m_pad_a9f0; void* m_pad_a9f8;
    void* m_pad_aa00; void* m_pad_aa08; void* m_pad_aa10; void* m_pad_aa18; void* m_pad_aa20; void* m_pad_aa28; void* m_pad_aa30; void* m_pad_aa38;
    void* m_pad_aa40; void* m_pad_aa48; void* m_pad_aa50; void* m_pad_aa58; void* m_pad_aa60; void* m_pad_aa68; void* m_pad_aa70; void* m_pad_aa78;
    void* m_pad_aa80; void* m_pad_aa88; void* m_pad_aa90; void* m_pad_aa98; void* m_pad_aaa0; void* m_pad_aaa8; void* m_pad_aab0; void* m_pad_aab8;
    void* m_pad_aac0; void* m_pad_aac8; void* m_pad_aad0; void* m_pad_aad8; void* m_pad_aae0; void* m_pad_aae8; void* m_pad_aaf0; void* m_pad_aaf8;
    void* m_pad_ab00; void* m_pad_ab08; void* m_pad_ab10; void* m_pad_ab18; void* m_pad_ab20; void* m_pad_ab28; void* m_pad_ab30; void* m_pad_ab38;
    void* m_pad_ab40; void* m_pad_ab48; void* m_pad_ab50; void* m_pad_ab58; void* m_pad_ab60; void* m_pad_ab68; void* m_pad_ab70; void* m_pad_ab78;
    void* m_pad_ab80; void* m_pad_ab88; void* m_pad_ab90; void* m_pad_ab98; void* m_pad_aba0; void* m_pad_aba8; void* m_pad_abb0; void* m_pad_abb8;
    void* m_pad_abc0; void* m_pad_abc8; void* m_pad_abd0; void* m_pad_abd8; void* m_pad_abe0; void* m_pad_abe8; void* m_pad_abf0; void* m_pad_abf8;
    void* m_pad_ac00; void* m_pad_ac08; void* m_pad_ac10; void* m_pad_ac18; void* m_pad_ac20; void* m_pad_ac28; void* m_pad_ac30; void* m_pad_ac38;
    void* m_pad_ac40; void* m_pad_ac48; void* m_pad_ac50; void* m_pad_ac58; void* m_pad_ac60; void* m_pad_ac68; void* m_pad_ac70; void* m_pad_ac78;
    void* m_pad_ac80; void* m_pad_ac88; void* m_pad_ac90; void* m_pad_ac98; void* m_pad_aca0; void* m_pad_aca8; void* m_pad_acb0; void* m_pad_acb8;
    void* m_pad_acc0; void* m_pad_acc8; void* m_pad_acd0; void* m_pad_acd8; void* m_pad_ace0; void* m_pad_ace8; void* m_pad_acf0; void* m_pad_acf8;
    void* m_pad_ad00; void* m_pad_ad08; void* m_pad_ad10; void* m_pad_ad18; void* m_pad_ad20; void* m_pad_ad28; void* m_pad_ad30; void* m_pad_ad38;
    void* m_pad_ad40; void* m_pad_ad48; void* m_pad_ad50; void* m_pad_ad58; void* m_pad_ad60; void* m_pad_ad68; void* m_pad_ad70; void* m_pad_ad78;
    void* m_pad_ad80; void* m_pad_ad88; void* m_pad_ad90; void* m_pad_ad98; void* m_pad_ada0; void* m_pad_ada8; void* m_pad_adb0; void* m_pad_adb8;
    void* m_pad_adc0; void* m_pad_adc8; void* m_pad_add0; void* m_pad_add8; void* m_pad_ade0; void* m_pad_ade8; void* m_pad_adf0; void* m_pad_adf8;
    void* m_pad_ae00; void* m_pad_ae08; void* m_pad_ae10; void* m_pad_ae18; void* m_pad_ae20; void* m_pad_ae28; void* m_pad_ae30; void* m_pad_ae38;
    void* m_pad_ae40; void* m_pad_ae48; void* m_pad_ae50; void* m_pad_ae58; void* m_pad_ae60; void* m_pad_ae68; void* m_pad_ae70; void* m_pad_ae78;
    void* m_pad_ae80; void* m_pad_ae88; void* m_pad_ae90; void* m_pad_ae98; void* m_pad_aea0; void* m_pad_aea8; void* m_pad_aeb0; void* m_pad_aeb8;
    void* m_pad_aec0; void* m_pad_aec8; void* m_pad_aed0; void* m_pad_aed8; void* m_pad_aee0; void* m_pad_aee8; void* m_pad_aef0; void* m_pad_aef8;
    void* m_pad_af00; void* m_pad_af08; void* m_pad_af10; void* m_pad_af18; void* m_pad_af20; void* m_pad_af28; void* m_pad_af30; void* m_pad_af38;
    void* m_pad_af40; void* m_pad_af48; void* m_pad_af50; void* m_pad_af58; void* m_pad_af60; void* m_pad_af68; void* m_pad_af70; void* m_pad_af78;
    void* m_pad_af80; void* m_pad_af88; void* m_pad_af90; void* m_pad_af98; void* m_pad_afa0; void* m_pad_afa8; void* m_pad_afb0; void* m_pad_afb8;
    void* m_pad_afc0; void* m_pad_afc8; void* m_pad_afd0; void* m_pad_afd8; void* m_pad_afe0; void* m_pad_afe8; void* m_pad_aff0; void* m_pad_aff8;
    void* m_pad_b000; void* m_pad_b008; void* m_pad_b010; void* m_pad_b018; void* m_pad_b020; void* m_pad_b028; void* m_pad_b030; void* m_pad_b038;
    void* m_pad_b040; void* m_pad_b048; void* m_pad_b050; void* m_pad_b058; void* m_pad_b060; void* m_pad_b068; void* m_pad_b070; void* m_pad_b078;
    void* m_pad_b080; void* m_pad_b088; void* m_pad_b090; void* m_pad_b098; void* m_pad_b0a0; void* m_pad_b0a8; void* m_pad_b0b0; void* m_pad_b0b8;
    void* m_pad_b0c0; void* m_pad_b0c8; void* m_pad_b0d0; void* m_pad_b0d8; void* m_pad_b0e0; void* m_pad_b0e8; void* m_pad_b0f0; void* m_pad_b0f8;
    void* m_pad_b100; void* m_pad_b108; void* m_pad_b110; void* m_pad_b118; void* m_pad_b120; void* m_pad_b128; void* m_pad_b130; void* m_pad_b138;
    void* m_pad_b140; void* m_pad_b148; void* m_pad_b150; void* m_pad_b158; void* m_pad_b160; void* m_pad_b168; void* m_pad_b170; void* m_pad_b178;
    void* m_pad_b180; void* m_pad_b188; void* m_pad_b190; void* m_pad_b198; void* m_pad_b1a0; void* m_pad_b1a8; void* m_pad_b1b0; void* m_pad_b1b8;
    void* m_pad_b1c0; void* m_pad_b1c8; void* m_pad_b1d0; void* m_pad_b1d8; void* m_pad_b1e0; void* m_pad_b1e8; void* m_pad_b1f0; void* m_pad_b1f8;
    void* m_pad_b200; void* m_pad_b208; void* m_pad_b210; void* m_pad_b218; void* m_pad_b220; void* m_pad_b228; void* m_pad_b230; void* m_pad_b238;
    void* m_pad_b240; void* m_pad_b248; void* m_pad_b250; void* m_pad_b258; void* m_pad_b260; void* m_pad_b268; void* m_pad_b270; void* m_pad_b278;
    void* m_pad_b280; void* m_pad_b288; void* m_pad_b290; void* m_pad_b298; void* m_pad_b2a0; void* m_pad_b2a8; void* m_pad_b2b0; void* m_pad_b2b8;
    void* m_pad_b2c0; void* m_pad_b2c8; void* m_pad_b2d0; void* m_pad_b2d8; void* m_pad_b2e0; void* m_pad_b2e8; void* m_pad_b2f0; void* m_pad_b2f8;
    void* m_pad_b300; void* m_pad_b308; void* m_pad_b310; void* m_pad_b318; void* m_pad_b320; void* m_pad_b328; void* m_pad_b330; void* m_pad_b338;
    void* m_pad_b340; void* m_pad_b348; void* m_pad_b350; void* m_pad_b358; void* m_pad_b360; void* m_pad_b368; void* m_pad_b370; void* m_pad_b378;
    void* m_pad_b380; void* m_pad_b388; void* m_pad_b390; void* m_pad_b398; void* m_pad_b3a0; void* m_pad_b3a8; void* m_pad_b3b0; void* m_pad_b3b8;
    void* m_pad_b3c0; void* m_pad_b3c8; void* m_pad_b3d0; void* m_pad_b3d8; void* m_pad_b3e0; void* m_pad_b3e8; void* m_pad_b3f0; void* m_pad_b3f8;
    void* m_pad_b400; void* m_pad_b408; void* m_pad_b410; void* m_pad_b418; void* m_pad_b420; void* m_pad_b428; void* m_pad_b430; void* m_pad_b438;
    void* m_pad_b440; void* m_pad_b448; void* m_pad_b450; void* m_pad_b458; void* m_pad_b460; void* m_pad_b468; void* m_pad_b470; void* m_pad_b478;
    void* m_pad_b480; void* m_pad_b488; void* m_pad_b490; void* m_pad_b498; void* m_pad_b4a0; void* m_pad_b4a8; void* m_pad_b4b0; void* m_pad_b4b8;
    void* m_pad_b4c0; void* m_pad_b4c8; void* m_pad_b4d0; void* m_pad_b4d8; void* m_pad_b4e0; void* m_pad_b4e8; void* m_pad_b4f0; void* m_pad_b4f8;
    void* m_pad_b500; void* m_pad_b508; void* m_pad_b510; void* m_pad_b518; void* m_pad_b520; void* m_pad_b528; void* m_pad_b530; void* m_pad_b538;
    void* m_pad_b540; void* m_pad_b548; void* m_pad_b550; void* m_pad_b558; void* m_pad_b560; void* m_pad_b568; void* m_pad_b570; void* m_pad_b578;
    void* m_pad_b580; void* m_pad_b588; void* m_pad_b590; void* m_pad_b598; void* m_pad_b5a0; void* m_pad_b5a8; void* m_pad_b5b0; void* m_pad_b5b8;
    void* m_pad_b5c0; void* m_pad_b5c8; void* m_pad_b5d0; void* m_pad_b5d8; void* m_pad_b5e0; void* m_pad_b5e8; void* m_pad_b5f0; void* m_pad_b5f8;
    void* m_pad_b600; void* m_pad_b608; void* m_pad_b610; void* m_pad_b618; void* m_pad_b620; void* m_pad_b628; void* m_pad_b630; void* m_pad_b638;
    void* m_pad_b640; void* m_pad_b648; void* m_pad_b650; void* m_pad_b658; void* m_pad_b660; void* m_pad_b668; void* m_pad_b670; void* m_pad_b678;
    void* m_pad_b680; void* m_pad_b688; void* m_pad_b690; void* m_pad_b698; void* m_pad_b6a0; void* m_pad_b6a8; void* m_pad_b6b0; void* m_pad_b6b8;
    void* m_pad_b6c0; void* m_pad_b6c8; void* m_pad_b6d0; void* m_pad_b6d8; void* m_pad_b6e0; void* m_pad_b6e8; void* m_pad_b6f0; void* m_pad_b6f8;
    void* m_pad_b700; void* m_pad_b708; void* m_pad_b710; void* m_pad_b718; void* m_pad_b720; void* m_pad_b728; void* m_pad_b730; void* m_pad_b738;
    void* m_pad_b740; void* m_pad_b748; void* m_pad_b750; void* m_pad_b758; void* m_pad_b760; void* m_pad_b768; void* m_pad_b770; void* m_pad_b778;
    void* m_pad_b780; void* m_pad_b788; void* m_pad_b790; void* m_pad_b798; void* m_pad_b7a0; void* m_pad_b7a8; void* m_pad_b7b0; void* m_pad_b7b8;
    void* m_pad_b7c0; void* m_pad_b7c8; void* m_pad_b7d0; void* m_pad_b7d8; void* m_pad_b7e0; void* m_pad_b7e8; void* m_pad_b7f0; void* m_pad_b7f8;
    void* m_pad_b800; void* m_pad_b808; void* m_pad_b810; void* m_pad_b818; void* m_pad_b820; void* m_pad_b828; void* m_pad_b830; void* m_pad_b838;
    void* m_pad_b840; void* m_pad_b848; void* m_pad_b850; void* m_pad_b858; void* m_pad_b860; void* m_pad_b868; void* m_pad_b870; void* m_pad_b878;
    void* m_pad_b880; void* m_pad_b888; void* m_pad_b890; void* m_pad_b898; void* m_pad_b8a0; void* m_pad_b8a8; void* m_pad_b8b0; void* m_pad_b8b8;
    void* m_pad_b8c0; void* m_pad_b8c8; void* m_pad_b8d0; void* m_pad_b8d8; void* m_pad_b8e0; void* m_pad_b8e8; void* m_pad_b8f0; void* m_pad_b8f8;
    void* m_pad_b900; void* m_pad_b908; void* m_pad_b910; void* m_pad_b918; void* m_pad_b920; void* m_pad_b928; void* m_pad_b930; void* m_pad_b938;
    void* m_pad_b940; void* m_pad_b948; void* m_pad_b950; void* m_pad_b958; void* m_pad_b960; void* m_pad_b968; void* m_pad_b970; void* m_pad_b978;
    void* m_pad_b980; void* m_pad_b988; void* m_pad_b990; void* m_pad_b998; void* m_pad_b9a0; void* m_pad_b9a8; void* m_pad_b9b0; void* m_pad_b9b8;
    void* m_pad_b9c0; void* m_pad_b9c8; void* m_pad_b9d0; void* m_pad_b9d8; void* m_pad_b9e0; void* m_pad_b9e8; void* m_pad_b9f0; void* m_pad_b9f8;
    void* m_pad_ba00; void* m_pad_ba08; void* m_pad_ba10; void* m_pad_ba18; void* m_pad_ba20; void* m_pad_ba28; void* m_pad_ba30; void* m_pad_ba38;
    void* m_pad_ba40; void* m_pad_ba48; void* m_pad_ba50; void* m_pad_ba58; void* m_pad_ba60; void* m_pad_ba68; void* m_pad_ba70; void* m_pad_ba78;
    void* m_pad_ba80; void* m_pad_ba88; void* m_pad_ba90; void* m_pad_ba98; void* m_pad_baa0; void* m_pad_baa8; void* m_pad_bab0; void* m_pad_bab8;
    void* m_pad_bac0; void* m_pad_bac8; void* m_pad_bad0; void* m_pad_bad8; void* m_pad_bae0; void* m_pad_bae8; void* m_pad_baf0; void* m_pad_baf8;
    void* m_pad_bb00; void* m_pad_bb08; void* m_pad_bb10; void* m_pad_bb18; void* m_pad_bb20; void* m_pad_bb28; void* m_pad_bb30; void* m_pad_bb38;
    void* m_pad_bb40; void* m_pad_bb48; void* m_pad_bb50; void* m_pad_bb58; void* m_pad_bb60; void* m_pad_bb68; void* m_pad_bb70; void* m_pad_bb78;
    void* m_pad_bb80; void* m_pad_bb88; void* m_pad_bb90; void* m_pad_bb98; void* m_pad_bba0; void* m_pad_bba8; void* m_pad_bbb0; void* m_pad_bbb8;
    void* m_pad_bbc0; void* m_pad_bbc8; void* m_pad_bbd0; void* m_pad_bbd8; void* m_pad_bbe0; void* m_pad_bbe8; void* m_pad_bbf0; void* m_pad_bbf8;
    void* m_pad_bc00; void* m_pad_bc08; void* m_pad_bc10; void* m_pad_bc18; void* m_pad_bc20; void* m_pad_bc28; void* m_pad_bc30; void* m_pad_bc38;
    void* m_pad_bc40; void* m_pad_bc48; void* m_pad_bc50; void* m_pad_bc58; void* m_pad_bc60; void* m_pad_bc68; void* m_pad_bc70; void* m_pad_bc78;
    void* m_pad_bc80; void* m_pad_bc88; void* m_pad_bc90; void* m_pad_bc98; void* m_pad_bca0; void* m_pad_bca8; void* m_pad_bcb0; void* m_pad_bcb8;
    void* m_pad_bcc0; void* m_pad_bcc8; void* m_pad_bcd0; void* m_pad_bcd8; void* m_pad_bce0; void* m_pad_bce8; void* m_pad_bcf0; void* m_pad_bcf8;
    void* m_pad_bd00; void* m_pad_bd08; void* m_pad_bd10; void* m_pad_bd18; void* m_pad_bd20; void* m_pad_bd28; void* m_pad_bd30; void* m_pad_bd38;
    void* m_pad_bd40; void* m_pad_bd48; void* m_pad_bd50; void* m_pad_bd58; void* m_pad_bd60; void* m_pad_bd68; void* m_pad_bd70; void* m_pad_bd78;
    void* m_pad_bd80; void* m_pad_bd88; void* m_pad_bd90; void* m_pad_bd98; void* m_pad_bda0; void* m_pad_bda8; void* m_pad_bdb0; void* m_pad_bdb8;
    void* m_pad_bdc0; void* m_pad_bdc8; void* m_pad_bdd0; void* m_pad_bdd8; void* m_pad_bde0; void* m_pad_bde8; void* m_pad_bdf0; void* m_pad_bdf8;
    void* m_pad_be00; void* m_pad_be08; void* m_pad_be10; void* m_pad_be18; void* m_pad_be20; void* m_pad_be28; void* m_pad_be30; void* m_pad_be38;
    void* m_pad_be40; void* m_pad_be48; void* m_pad_be50; void* m_pad_be58; void* m_pad_be60; void* m_pad_be68; void* m_pad_be70; void* m_pad_be78;
    void* m_pad_be80; void* m_pad_be88; void* m_pad_be90; void* m_pad_be98; void* m_pad_bea0; void* m_pad_bea8; void* m_pad_beb0; void* m_pad_beb8;
    void* m_pad_bec0; void* m_pad_bec8; void* m_pad_bed0; void* m_pad_bed8; void* m_pad_bee0; void* m_pad_bee8; void* m_pad_bef0; void* m_pad_bef8;
    void* m_pad_bf00; void* m_pad_bf08; void* m_pad_bf10; void* m_pad_bf18; void* m_pad_bf20; void* m_pad_bf28; void* m_pad_bf30; void* m_pad_bf38;
    void* m_pad_bf40; void* m_pad_bf48; void* m_pad_bf50; void* m_pad_bf58; void* m_pad_bf60; void* m_pad_bf68; void* m_pad_bf70; void* m_pad_bf78;
    void* m_pad_bf80; void* m_pad_bf88; void* m_pad_bf90; void* m_pad_bf98; void* m_pad_bfa0; void* m_pad_bfa8; void* m_pad_bfb0; void* m_pad_bfb8;
    void* m_pad_bfc0; void* m_pad_bfc8; void* m_pad_bfd0; void* m_pad_bfd8; void* m_pad_bfe0; void* m_pad_bfe8; void* m_pad_bff0; void* m_pad_bff8;
    void* m_pad_c000; void* m_pad_c008; void* m_pad_c010; void* m_pad_c018; void* m_pad_c020; void* m_pad_c028; void* m_pad_c030; void* m_pad_c038;
    void* m_pad_c040; void* m_pad_c048; void* m_pad_c050; void* m_pad_c058; void* m_pad_c060; void* m_pad_c068; void* m_pad_c070; void* m_pad_c078;
    void* m_pad_c080; void* m_pad_c088; void* m_pad_c090; void* m_pad_c098; void* m_pad_c0a0; void* m_pad_c0a8; void* m_pad_c0b0; void* m_pad_c0b8;
    void* m_pad_c0c0; void* m_pad_c0c8; void* m_pad_c0d0; void* m_pad_c0d8; void* m_pad_c0e0; void* m_pad_c0e8; void* m_pad_c0f0; void* m_pad_c0f8;
    void* m_pad_c100; void* m_pad_c108; void* m_pad_c110; void* m_pad_c118; void* m_pad_c120; void* m_pad_c128; void* m_pad_c130; void* m_pad_c138;
    void* m_pad_c140; void* m_pad_c148; void* m_pad_c150; void* m_pad_c158; void* m_pad_c160; void* m_pad_c168; void* m_pad_c170; void* m_pad_c178;
    void* m_pad_c180; void* m_pad_c188; void* m_pad_c190; void* m_pad_c198; void* m_pad_c1a0; void* m_pad_c1a8; void* m_pad_c1b0; void* m_pad_c1b8;
    void* m_pad_c1c0; void* m_pad_c1c8; void* m_pad_c1d0; void* m_pad_c1d8; void* m_pad_c1e0; void* m_pad_c1e8; void* m_pad_c1f0; void* m_pad_c1f8;
    void* m_pad_c200; void* m_pad_c208; void* m_pad_c210; void* m_pad_c218; void* m_pad_c220; void* m_pad_c228; void* m_pad_c230; void* m_pad_c238;
    void* m_pad_c240; void* m_pad_c248; void* m_pad_c250; void* m_pad_c258; void* m_pad_c260; void* m_pad_c268; void* m_pad_c270; void* m_pad_c278;
    void* m_pad_c280; void* m_pad_c288; void* m_pad_c290; void* m_pad_c298; void* m_pad_c2a0; void* m_pad_c2a8; void* m_pad_c2b0; void* m_pad_c2b8;
    void* m_pad_c2c0; void* m_pad_c2c8; void* m_pad_c2d0; void* m_pad_c2d8; void* m_pad_c2e0; void* m_pad_c2e8; void* m_pad_c2f0; void* m_pad_c2f8;
    void* m_pad_c300; void* m_pad_c308; void* m_pad_c310; void* m_pad_c318; void* m_pad_c320; void* m_pad_c328; void* m_pad_c330; void* m_pad_c338;
    void* m_pad_c340; void* m_pad_c348; void* m_pad_c350; void* m_pad_c358; void* m_pad_c360; void* m_pad_c368; void* m_pad_c370; void* m_pad_c378;
    void* m_pad_c380; void* m_pad_c388; void* m_pad_c390; void* m_pad_c398; void* m_pad_c3a0; void* m_pad_c3a8; void* m_pad_c3b0; void* m_pad_c3b8;
    void* m_pad_c3c0; void* m_pad_c3c8; void* m_pad_c3d0; void* m_pad_c3d8; void* m_pad_c3e0; void* m_pad_c3e8; void* m_pad_c3f0; void* m_pad_c3f8;
    void* m_pad_c400; void* m_pad_c408; void* m_pad_c410; void* m_pad_c418; void* m_pad_c420; void* m_pad_c428; void* m_pad_c430; void* m_pad_c438;
    void* m_pad_c440; void* m_pad_c448; void* m_pad_c450; void* m_pad_c458; void* m_pad_c460; void* m_pad_c468; void* m_pad_c470; void* m_pad_c478;
    void* m_pad_c480; void* m_pad_c488; void* m_pad_c490; void* m_pad_c498; void* m_pad_c4a0; void* m_pad_c4a8; void* m_pad_c4b0; void* m_pad_c4b8;
    void* m_pad_c4c0; void* m_pad_c4c8; void* m_pad_c4d0; void* m_pad_c4d8; void* m_pad_c4e0; void* m_pad_c4e8; void* m_pad_c4f0; void* m_pad_c4f8;
    void* m_pad_c500; void* m_pad_c508; void* m_pad_c510; void* m_pad_c518; void* m_pad_c520; void* m_pad_c528; void* m_pad_c530; void* m_pad_c538;
    void* m_pad_c540; void* m_pad_c548; void* m_pad_c550; void* m_pad_c558; void* m_pad_c560; void* m_pad_c568; void* m_pad_c570; void* m_pad_c578;
    void* m_pad_c580; void* m_pad_c588; void* m_pad_c590; void* m_pad_c598; void* m_pad_c5a0; void* m_pad_c5a8; void* m_pad_c5b0; void* m_pad_c5b8;
    void* m_pad_c5c0; void* m_pad_c5c8; void* m_pad_c5d0; void* m_pad_c5d8; void* m_pad_c5e0; void* m_pad_c5e8; void* m_pad_c5f0; void* m_pad_c5f8;
    void* m_pad_c600; void* m_pad_c608; void* m_pad_c610; void* m_pad_c618; void* m_pad_c620; void* m_pad_c628; void* m_pad_c630; void* m_pad_c638;
    void* m_pad_c640; void* m_pad_c648; void* m_pad_c650; void* m_pad_c658; void* m_pad_c660; void* m_pad_c668; void* m_pad_c670; void* m_pad_c678;
    void* m_pad_c680; void* m_pad_c688; void* m_pad_c690; void* m_pad_c698; void* m_pad_c6a0; void* m_pad_c6a8; void* m_pad_c6b0; void* m_pad_c6b8;
    void* m_pad_c6c0; void* m_pad_c6c8; void* m_pad_c6d0; void* m_pad_c6d8; void* m_pad_c6e0; void* m_pad_c6e8; void* m_pad_c6f0; void* m_pad_c6f8;
    void* m_pad_c700; void* m_pad_c708; void* m_pad_c710; void* m_pad_c718; void* m_pad_c720; void* m_pad_c728; void* m_pad_c730; void* m_pad_c738;
    void* m_pad_c740; void* m_pad_c748; void* m_pad_c750; void* m_pad_c758; void* m_pad_c760;
    Unk_14025a620 m_c768;
    void* m_pad_c770; void* m_pad_c778; void* m_pad_c780; void* m_pad_c788; void* m_pad_c790; void* m_pad_c798; void* m_pad_c7a0; void* m_pad_c7a8;
    void* m_pad_c7b0; void* m_pad_c7b8;
    Unk_1402056b0 m_c7c0;
};
MS2_CHECK_OFFSET(Unk_1401d3200, m_c768, 0xc768);
MS2_CHECK_OFFSET(Unk_1401d3200, m_c7c0, 0xc7c0);
MS2_CHECK_SIZE(Unk_1401d3200, 0xc7c8); // recovered prefix only
Unk_1401d3200* FUN_1401d3200();

// The state object of the local player (0x1403ed2d0 singleton -> 0x141bd0cc0).
class Unk_14166ccb0 { public: void FUN_140b877c0(); };
class Unk_141bd0cc0
{
public:
    int FUN_14166c930();                                    // state type (0x3c = micro game)
    Unk_14166ccb0* FUN_14166ccb0();
};
class Unk_1403ed2d0 { public: Unk_141bd0cc0* FUN_141bd0cc0(); };
Unk_1403ed2d0* FUN_1403ed2d0();

int FUN_141277f40();
int FUN_140768010(int n1, int n2);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// @0x140e66040
UIMicroGameRps::UIMicroGameRps()
{
    m_58 = 0;
    m_2c = 9;
    m_28 = FUN_141277f40();
    m_nCard = -1;
}

// @0x140e660c0
CString UIMicroGameRps::vfunc_1()
{
    return "MicroGameRps";
}
MS2_REPLACE_METHOD(0x140E660C0, UIMicroGameRps, vfunc_1, 61, 0xE98C0E76);

// @0x140e66110
void UIMicroGameRps::vfunc_15()
{
    if (FUN_140e66710() != 0)
        FUN_140e663b0();
    else
        FUN_140e664a0();
}
MS2_REPLACE_METHOD(0x140E66110, UIMicroGameRps, vfunc_15, 50, 0xF24423E3);

// @0x140e66150
void UIMicroGameRps::vfunc_43()
{
}
MS2_REPLACE_METHOD(0x140E66150, UIMicroGameRps, vfunc_43, 6, 0xA9AF6E37);

// @0x140e66160
void UIMicroGameRps::vfunc_2()
{
    UIHeadUpDisplay::vfunc_2();
}
MS2_REPLACE_METHOD(0x140E66160, UIMicroGameRps, vfunc_2, 24, 0xEF4E921A);

// @0x140e66180
void UIMicroGameRps::vfunc_3()
{
    FUN_140e663b0();
    UIHeadUpDisplay::vfunc_3();
}
MS2_REPLACE_METHOD(0x140E66180, UIMicroGameRps, vfunc_3, 34, 0xD551E9EA);

// @0x140e661b0
int UIMicroGameRps::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UISwfEntity::vfunc_28(szMethod, pArgs, nArgs))
        return 1;
    if (_stricmp(szMethod, "onSelectCard") == 0) {
        ASData data;
        if (!data.FUN_1422b9620(pArgs, nArgs)) {
            MS2_ASSERT_AT(0x73, 0);
            return 0;
        }
        int nCard = data.FUN_1422b8b10();
        SetCard(nCard);
        return 1;
    }
    if (_stricmp(szMethod, "onSelectTimeUp") == 0) {
        SendMicrogame();
        return 1;
    }
    if (_stricmp(szMethod, "onRandChat") == 0) {
        OnRandChat();
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140E661B0, UIMicroGameRps, vfunc_28, 370, 0xB3BFB6DD);

// @0x140e66330
void UIMicroGameRps::FUN_140e66330()
{
    if (m_30 == NULL)
        return;
    m_68 = 1;
    FUN_140e664a0();
    m_30->Invoke("popUp");
}
MS2_REPLACE_METHOD(0x140E66330, UIMicroGameRps, FUN_140e66330, 111, 0xEB1146CD);

// @0x140e663b0
void UIMicroGameRps::FUN_140e663b0()
{
    if (m_30 == NULL)
        return;
    if (FUN_141986d30() == 0)
        return;
    m_68 = 0;
    m_30->Invoke("hide");
}
MS2_REPLACE_METHOD(0x140E663B0, UIMicroGameRps, FUN_140e663b0, 117, 0x9B525C31);

// @0x140e66430
void UIMicroGameRps::vfunc_41(const Scaleform::GFx::Value& root)
{
    m_30 = FUN_140ba77e0(m_28, root);
}
MS2_REPLACE_METHOD(0x140E66430, UIMicroGameRps, vfunc_41, 99, 0x1825152D);

// @0x140e664a0
void UIMicroGameRps::FUN_140e664a0()
{
    MS2Ptr<ASGameEntity> pEntity(dynamic_cast<ASGameEntity*>((AScript*)m_30));
    if (pEntity == NULL)
        return;
    int nX = FUN_1401d3200()->m_c768.FUN_14025a620();
    int nY = *FUN_1401d3200()->m_c7c0.FUN_1402056b0() - 0x32;
    int nWidth = (int)(pEntity->FUN_1422c1500() * 0.5f + nX);
    int nHeight = (int)(pEntity->FUN_1422c1530() * 0.5f + nY);
    pEntity->FUN_1422bffe0(nWidth, nHeight);
}
MS2_REPLACE_METHOD(0x140E664A0, UIMicroGameRps, FUN_140e664a0, 305, 0xB598E51F);

// @0x140e665e0
void UIMicroGameRps::SetCard(int nCard)
{
    m_nCard = nCard;
}
MS2_REPLACE_METHOD(0x140E665E0, UIMicroGameRps, SetCard, 22, 0x161CE143);

// @0x140e66600
void UIMicroGameRps::SendMicrogame()
{
    if (m_30 == NULL)
        return;
    if (m_nCard == -1)
        m_nCard = FUN_140768010(3, 0);
    COutPacket packet(0xa8, 0);
    packet.Encode2(7);
    packet.Encode4(m_nCard);
    FUN_140710590(packet);
}
MS2_REPLACE_METHOD(0x140E66600, UIMicroGameRps, SendMicrogame, 154, 0xD9F68C75);

// @0x140e666a0
void UIMicroGameRps::OnRandChat()
{
    Unk_141bd0cc0* pState = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pState == NULL)
        return;
    if (pState->FUN_14166c930() != 0x3c)
        return;
    Unk_14166ccb0* p = pState->FUN_14166ccb0();
    if (p == NULL)
        return;
    p->FUN_140b877c0();
}

MS2_REPLACE_METHOD(0x140E666A0, UIMicroGameRps, OnRandChat, 94, 0x948CB5A7);

// @0x140e66710
int UIMicroGameRps::FUN_140e66710()
{
    Unk_141bd0cc0* pState = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (!pState)
        return 1;
    if (pState->FUN_14166c930() != 0x3c)
        return 1;
    return 0;
}

MS2_REPLACE_METHOD(0x140E66710, UIMicroGameRps, FUN_140e66710, 71, 0x38DEDF94);

// Retain the CRT inline memcpy_s COMDAT instantiated by the original unit.
__declspec(selectany) extern errno_t (__cdecl* const ms2_rpsMemcpyS)(void*, size_t, const void*, size_t) = &memcpy_s;
