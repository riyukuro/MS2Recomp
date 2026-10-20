// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). CFeatureTable / CFeatureManager: the built-in feature
// names and ids, and the feature_setting.xml / feature.xml switches that decide which features are on.
// MS2-UNIT: commonfiles\featuremanager.cpp
// MS2-RANGE: 0x1400b6120-0x1400b6150 .text$di
// MS2-RANGE: 0x1403687f0-0x1403727d0 .text$mn
// MS2-GUESS-LOOKALIKES
// MS2-PINS-BEGIN tplpin
// MS2-PIN: memmove_s 0x14036c950 ; unique
// MS2-PIN: ??0?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAA@IMMMI@Z 0x14036eab0 ; unique
// MS2-PIN: ??0CNode@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAA@PEB_WI@Z 0x14036ef60 ; unique
// MS2-PIN: ??0CPair@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@IEAA@PEB_W@Z 0x14036f020 ; unique
// MS2-PIN: ??1?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAA@XZ 0x14036f0b0 ; unique
// MS2-PIN: ??1CPair@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAA@XZ 0x14036f240 ; unique
// MS2-PIN: ??_GCNode@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAAPEAXI@Z 0x14036f3d0 ; unique
// MS2-PIN: ?CreateNode@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@PEB_WII@Z 0x14036f5d0 ; unique
// MS2-PIN: ?DisableAutoRehash@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x14036f7b0 ; unique
// MS2-PIN: ?EnableAutoRehash@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x14036f810 ; unique
// MS2-PIN: ?FreeNode@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@@Z 0x14036f930 ; unique
// MS2-PIN: ?FreePlexes@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@AEAAXXZ 0x14036fc20 ; unique
// MS2-PIN: ?GetHash@CNode@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEBAIXZ 0x14036fd10 ; unique
// MS2-PIN: ?GetNode@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@AEBAPEAVCNode@12@PEB_WAEAI1AEAPEAV312@@Z 0x14036fe10 ; unique
// MS2-PIN: ?InitHashTable@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAA_NI_N@Z 0x1403701e0 ; unique
// MS2-PIN: ?IsLocked@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@AEBA_NXZ 0x140370570 ; unique
// MS2-PIN: ?Lookup@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEBA_NPEB_WAEAH@Z 0x140370610 ; unique
// MS2-PIN: ?NewNode@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@AEAAPEAVCNode@12@PEB_WII@Z 0x1403707a0 ; unique
// MS2-PIN: ?PickSize@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@AEBAI_K@Z 0x140370dd0 ; unique
// MS2-PIN: ?Rehash@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAAXI@Z 0x1403710a0 ; unique
// MS2-PIN: ?RemoveAll@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAAXXZ 0x140371730 ; unique
// MS2-PIN: ?RemoveAtPos@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAAXPEAU__POSITION@@@Z 0x140371a60 ; unique
// MS2-PIN: ?RemoveNode@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@AEAAXPEAVCNode@12@0@Z 0x140371d30 ; unique
// MS2-PIN: ?SetAt@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAAPEAU__POSITION@@PEB_WH@Z 0x140371f70 ; unique
// MS2-PIN: ?SetOptimalLoad@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@QEAAXMMM_N@Z 0x140372140 ; unique
// MS2-PIN: ?UpdateRehashThresholds@?$CAtlMap@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@HV?$CStringElementTraitsI@V?$CStringT@_WV?$StrTraitMFC_DLL@_WV?$ChTraitsCRT@_W@ATL@@@@@ATL@@V?$CDefaultCharTraits@_W@2@@2@V?$CElementTraits@H@2@@ATL@@AEAAXXZ 0x140372410 ; unique
// MS2-PINS-END tplpin
// MS2-PIN: ??_7?$TSingleton@VCFeatureTable@@@@6B@ 0x142d2e258
// MS2-PIN: ??_7CFeatureManager@@6B?$TSingleton@VCFeatureManager@@@@@ 0x142d2e278
// MS2-PIN: ??_7CFeatureManager@@6B?$CValidData@VCFeatureManager@@@@@ 0x142d2e2c8
// MS2-PIN: ?StringCompare@?$ChTraitsCRT@_W@ATL@@SAHPEB_W0@Z 0x14036c840
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\commonfiles\\featuremanager.cpp"
#include <wchar.h>
#pragma function(wcscmp)   // the exe calls the CRT wcscmp from ATL StringCompare instead of expanding it
#include "ms2/placeholder/ms2stdafx.h"
#include "featuremanager.h"
#include "filesystem.h"
#include "logstring.h"
#include "ms2/ms2format.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"
#include <algorithm>

// Unrecovered helpers.
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);       // Table/<file>
void FUN_14015eb90(CLogString* log, int level, int category, const wchar_t* format, const CString& arg);
void FUN_1401859c0(CLogString* log, int level, int category, const wchar_t* format);
CString FUN_140651390();                                                    // the locale name of the client
CStringW FUN_14016a730(const char* psz, int nCodePage);
bool FUN_14025cd60(const CStringW& strA, const CStringW& strB);             // the strings are equal
bool FUN_140164830(const CStringW& strA, const CStringW& strB);
CStringW FUN_140875470(Unk_140165cf0* pElem);                               // the <feature> row as text
bool FUN_140184310(CString str, const char* psz);
int FUN_140219a50(const CString& strType);                                  // the server type name -> id
void FUN_14025a680(const CStringW& str, ATL::CAtlArray<CStringW>* pOut, const wchar_t* pszSep);   // split
void FUN_140291e40(CStringW strName, bool bOn, const char* pszTag);
class Unk_1406aeee0 { public: void FUN_1406af150(); };
Unk_1406aeee0* FUN_1406aeee0();

// The enum customization of the log formatter for the feature id (the exe copy keeps a stack cookie and scratch locals).
// MS2-FUNCTIONAL: integer conversion and formatter cursor update match the enum path.
// @0x14036e930
void format_arg(fmt::BasicFormatter<wchar_t>& formatter, const wchar_t*& cursor, const Unk_FeatureId& value)
{
    fmt::internal::Arg arg;
    arg.int_value = static_cast<int>(value);
    arg.type = fmt::internal::Arg::INT;
    cursor = formatter.format(cursor, arg);
}

// The unit's one-argument log calls (FMT_VARIADIC wrappers over CLogString::FUN_1406530d0 / FUN_1406536f0).
// @0x14036e770
template <class T>
inline void Unk_FeatureLog(CLogString* log, int level, int category, const wchar_t* format, const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}

// @0x14036e800
template <class T>
inline void Unk_FeatureLogId(CLogString* log, int level, int category, const wchar_t* format, const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406530d0(level, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}

// @0x14036e890
template <class T>
inline void Unk_FeatureLog2(CLogString* log, unsigned __int64 a, unsigned __int64 b, int category,
                            const wchar_t* format, const T& first)
{
    const fmt::internal::ArgArray<1>::Type args = {fmt::internal::MakeValue<fmt::BasicFormatter<wchar_t> >(first)};
    log->FUN_1406536f0(a, b, category, format, fmt::ArgList(fmt::internal::make_type(first), args));
}

MS2_EMIT_CRT_MEMMOVE_S();
// @0x1403726b0
MS2_EMIT_CRT_MEMMOVE_S_COPY(2);

#ifndef MS2_HOOK_DLL   // the hook DLL binds the exe's init flag and server type (symbols-manual.tsv)
bool CFeatureManager::s_bInit;
CString CFeatureManager::s_strServerType("Live");
int CFeatureManager::s_nServerType;
#endif

// The level caps of the ExtendLevel features (FUN_14036dc80 takes the smaller of the base cap and one of these).
static const unsigned short s_nBaseLevelCap = 60;
static const unsigned short s_nLevelCap55 = 55;
static const unsigned short s_nLevelCap60 = 60;
static const unsigned short s_nLevelCap65 = 65;
static const unsigned short s_nLevelCap70 = 70;
static const unsigned short s_nLevelCap80 = 80;
static const unsigned short s_nLevelCap90 = 90;
static const unsigned short s_nLevelCap99 = 99;

// @0x14036eef0
CFeatureTable::CFeatureTable()
{
}

// @0x1403687f0
bool CFeatureTable::Init()
{
    Unk_FeatureId n1 = (Unk_FeatureId)1;
    m_map.SetAt(L"", n1);
    Unk_FeatureId n2 = (Unk_FeatureId)2;
    m_map.SetAt(L"Develop", n2);
    Unk_FeatureId n3 = (Unk_FeatureId)3;
    m_map.SetAt(L"KarkarIsland", n3);
    Unk_FeatureId n4 = (Unk_FeatureId)4;
    m_map.SetAt(L"MassiveOxQuiz", n4);
    Unk_FeatureId n5 = (Unk_FeatureId)5;
    m_map.SetAt(L"TimeAttackDungeon", n5);
    Unk_FeatureId n6 = (Unk_FeatureId)6;
    m_map.SetAt(L"AricariDailyQ", n6);
    Unk_FeatureId n7 = (Unk_FeatureId)7;
    m_map.SetAt(L"KatvanDungeon", n7);
    Unk_FeatureId n8 = (Unk_FeatureId)8;
    m_map.SetAt(L"RuneBlader", n8);
    Unk_FeatureId n9 = (Unk_FeatureId)9;
    m_map.SetAt(L"FieldEventSpawn", n9);
    Unk_FeatureId n10 = (Unk_FeatureId)10;
    m_map.SetAt(L"MusicInstrument", n10);
    Unk_FeatureId n11 = (Unk_FeatureId)11;
    m_map.SetAt(L"Fishing", n11);
    Unk_FeatureId n12 = (Unk_FeatureId)12;
    m_map.SetAt(L"HabiToken", n12);
    Unk_FeatureId n13 = (Unk_FeatureId)13;
    m_map.SetAt(L"Darkblossom", n13);
    Unk_FeatureId n14 = (Unk_FeatureId)14;
    m_map.SetAt(L"DetectSkillHack", n14);
    Unk_FeatureId n15 = (Unk_FeatureId)15;
    m_map.SetAt(L"Barkhant", n15);
    Unk_FeatureId n16 = (Unk_FeatureId)16;
    m_map.SetAt(L"CompactControl", n16);
    Unk_FeatureId n17 = (Unk_FeatureId)17;
    m_map.SetAt(L"PvPRankingDuelMode", n17);
    Unk_FeatureId n18 = (Unk_FeatureId)18;
    m_map.SetAt(L"Striker", n18);
    Unk_FeatureId n19 = (Unk_FeatureId)19;
    m_map.SetAt(L"MassiveDanceDanceStop", n19);
    Unk_FeatureId n20 = (Unk_FeatureId)20;
    m_map.SetAt(L"ItemDropRenewal", n20);
    Unk_FeatureId n21 = (Unk_FeatureId)21;
    m_map.SetAt(L"MesoMarket", n21);
    Unk_FeatureId n22 = (Unk_FeatureId)22;
    m_map.SetAt(L"ArcadeCrazyMonkeyOcean", n22);
    Unk_FeatureId n23 = (Unk_FeatureId)23;
    m_map.SetAt(L"LuaCorrectionPen", n23);
    Unk_FeatureId n24 = (Unk_FeatureId)24;
    m_map.SetAt(L"ArcadeSpringFarm", n24);
    Unk_FeatureId n25 = (Unk_FeatureId)25;
    m_map.SetAt(L"SuperWorldChat", n25);
    Unk_FeatureId n26 = (Unk_FeatureId)26;
    m_map.SetAt(L"RewardPreview", n26);
    Unk_FeatureId n27 = (Unk_FeatureId)27;
    m_map.SetAt(L"ArcadeSystem", n27);
    Unk_FeatureId n28 = (Unk_FeatureId)28;
    m_map.SetAt(L"NutaNuta", n28);
    Unk_FeatureId n29 = (Unk_FeatureId)29;
    m_map.SetAt(L"EventBossRush", n29);
    Unk_FeatureId n30 = (Unk_FeatureId)30;
    m_map.SetAt(L"EventMapEnterUI", n30);
    Unk_FeatureId n31 = (Unk_FeatureId)31;
    m_map.SetAt(L"EventDuckyCardGame", n31);
    Unk_FeatureId n32 = (Unk_FeatureId)32;
    m_map.SetAt(L"ArcadePapulatus", n32);
    Unk_FeatureId n33 = (Unk_FeatureId)33;
    m_map.SetAt(L"TorrentOfDark", n33);
    Unk_FeatureId n34 = (Unk_FeatureId)34;
    m_map.SetAt(L"ShadowExpedition", n34);
    Unk_FeatureId n35 = (Unk_FeatureId)35;
    m_map.SetAt(L"ShadowCataclysm", n35);
    Unk_FeatureId n36 = (Unk_FeatureId)36;
    m_map.SetAt(L"EventSlimeCardGame", n36);
    Unk_FeatureId n37 = (Unk_FeatureId)37;
    m_map.SetAt(L"SoulBinder", n37);
    Unk_FeatureId n38 = (Unk_FeatureId)38;
    m_map.SetAt(L"ExtendLevel55", n38);
    Unk_FeatureId n39 = (Unk_FeatureId)39;
    m_map.SetAt(L"ExtendLevel60", n39);
    Unk_FeatureId n40 = (Unk_FeatureId)40;
    m_map.SetAt(L"ExtendLevel65", n40);
    Unk_FeatureId n41 = (Unk_FeatureId)41;
    m_map.SetAt(L"ExtendLevel70", n41);
    Unk_FeatureId n42 = (Unk_FeatureId)42;
    m_map.SetAt(L"ExtendLevel80", n42);
    Unk_FeatureId n43 = (Unk_FeatureId)43;
    m_map.SetAt(L"ExtendLevel90", n43);
    Unk_FeatureId n44 = (Unk_FeatureId)44;
    m_map.SetAt(L"ExtendLevel99", n44);
    Unk_FeatureId n45 = (Unk_FeatureId)45;
    m_map.SetAt(L"CharacterAbility", n45);
    Unk_FeatureId n46 = (Unk_FeatureId)46;
    m_map.SetAt(L"ItemSocketSystem", n46);
    Unk_FeatureId n47 = (Unk_FeatureId)47;
    m_map.SetAt(L"GameDictionary", n47);
    Unk_FeatureId n48 = (Unk_FeatureId)48;
    m_map.SetAt(L"JazzInstrument", n48);
    Unk_FeatureId n49 = (Unk_FeatureId)49;
    m_map.SetAt(L"Kandura", n49);
    Unk_FeatureId n50 = (Unk_FeatureId)50;
    m_map.SetAt(L"ChaosPapulatus", n50);
    Unk_FeatureId n51 = (Unk_FeatureId)51;
    m_map.SetAt(L"EventMassiveDungeon", n51);
    Unk_FeatureId n52 = (Unk_FeatureId)52;
    m_map.SetAt(L"ShadowExpedition2nd", n52);
    Unk_FeatureId n53 = (Unk_FeatureId)53;
    m_map.SetAt(L"ShrineOfGuidance", n53);
    Unk_FeatureId n54 = (Unk_FeatureId)54;
    m_map.SetAt(L"DoubleImpactStory", n54);
    Unk_FeatureId n55 = (Unk_FeatureId)55;
    m_map.SetAt(L"itemOptionRenewal", n55);
    Unk_FeatureId n56 = (Unk_FeatureId)56;
    m_map.SetAt(L"ItemRePacking", n56);
    Unk_FeatureId n57 = (Unk_FeatureId)57;
    m_map.SetAt(L"UGCMapFun", n57);
    Unk_FeatureId n58 = (Unk_FeatureId)58;
    m_map.SetAt(L"SkinBreak", n58);
    Unk_FeatureId n59 = (Unk_FeatureId)59;
    m_map.SetAt(L"Maview", n59);
    Unk_FeatureId n60 = (Unk_FeatureId)60;
    m_map.SetAt(L"PCBang", n60);
    Unk_FeatureId n61 = (Unk_FeatureId)61;
    m_map.SetAt(L"MeratUI", n61);
    Unk_FeatureId n62 = (Unk_FeatureId)62;
    m_map.SetAt(L"VisitorBook", n62);
    Unk_FeatureId n63 = (Unk_FeatureId)63;
    m_map.SetAt(L"InGameRank", n63);
    Unk_FeatureId n64 = (Unk_FeatureId)64;
    m_map.SetAt(L"RenewalDungeonQuest01", n64);
    Unk_FeatureId n65 = (Unk_FeatureId)65;
    m_map.SetAt(L"ContentsGuide01", n65);
    Unk_FeatureId n66 = (Unk_FeatureId)66;
    m_map.SetAt(L"EnableGoToNpc", n66);
    Unk_FeatureId n67 = (Unk_FeatureId)67;
    m_map.SetAt(L"RedMerat", n67);
    Unk_FeatureId n68 = (Unk_FeatureId)68;
    m_map.SetAt(L"RedMeratShop", n68);
    Unk_FeatureId n69 = (Unk_FeatureId)69;
    m_map.SetAt(L"Gift", n69);
    Unk_FeatureId n70 = (Unk_FeatureId)70;
    m_map.SetAt(L"GiftUgc", n70);
    Unk_FeatureId n71 = (Unk_FeatureId)71;
    m_map.SetAt(L"GiftPremium", n71);
    Unk_FeatureId n72 = (Unk_FeatureId)72;
    m_map.SetAt(L"UGCMarket", n72);
    Unk_FeatureId n73 = (Unk_FeatureId)73;
    m_map.SetAt(L"PremiumShop", n73);
    Unk_FeatureId n74 = (Unk_FeatureId)74;
    m_map.SetAt(L"VIP", n74);
    Unk_FeatureId n75 = (Unk_FeatureId)75;
    m_map.SetAt(L"VIPDungeon", n75);
    Unk_FeatureId n76 = (Unk_FeatureId)76;
    m_map.SetAt(L"ItemDungeon", n76);
    Unk_FeatureId n77 = (Unk_FeatureId)77;
    m_map.SetAt(L"Mastery", n77);
    Unk_FeatureId n78 = (Unk_FeatureId)78;
    m_map.SetAt(L"PvpTestSeason", n78);
    Unk_FeatureId n79 = (Unk_FeatureId)79;
    m_map.SetAt(L"CashShop", n79);
    Unk_FeatureId n80 = (Unk_FeatureId)80;
    m_map.SetAt(L"ResetServer", n80);
    Unk_FeatureId n81 = (Unk_FeatureId)81;
    m_map.SetAt(L"MustBeModified", n81);
    Unk_FeatureId n82 = (Unk_FeatureId)82;
    m_map.SetAt(L"PirateOcean", n82);
    Unk_FeatureId n83 = (Unk_FeatureId)83;
    m_map.SetAt(L"SnowKingdom", n83);
    Unk_FeatureId n84 = (Unk_FeatureId)84;
    m_map.SetAt(L"DarkCastle", n84);
    Unk_FeatureId n85 = (Unk_FeatureId)85;
    m_map.SetAt(L"ItemPartyDungeon", n85);
    Unk_FeatureId n86 = (Unk_FeatureId)86;
    m_map.SetAt(L"Club", n86);
    Unk_FeatureId n87 = (Unk_FeatureId)87;
    m_map.SetAt(L"VIPAirTaxi", n87);
    Unk_FeatureId n88 = (Unk_FeatureId)88;
    m_map.SetAt(L"NPCPortal01", n88);
    Unk_FeatureId n89 = (Unk_FeatureId)89;
    m_map.SetAt(L"MasterySecond", n89);
    Unk_FeatureId n90 = (Unk_FeatureId)90;
    m_map.SetAt(L"MagicScroll01", n90);
    Unk_FeatureId n91 = (Unk_FeatureId)91;
    m_map.SetAt(L"GuildHouse01", n91);
    Unk_FeatureId n92 = (Unk_FeatureId)92;
    m_map.SetAt(L"AdventureBar", n92);
    Unk_FeatureId n93 = (Unk_FeatureId)93;
    m_map.SetAt(L"DungeonLimitMesoRevival", n93);
    Unk_FeatureId n94 = (Unk_FeatureId)94;
    m_map.SetAt(L"SkinSocket", n94);
    Unk_FeatureId n95 = (Unk_FeatureId)95;
    m_map.SetAt(L"WebGuide", n95);
    Unk_FeatureId n96 = (Unk_FeatureId)96;
    m_map.SetAt(L"MusicConcert", n96);
    Unk_FeatureId n97 = (Unk_FeatureId)97;
    m_map.SetAt(L"RedMeratConstruct", n97);
    Unk_FeatureId n98 = (Unk_FeatureId)98;
    m_map.SetAt(L"RedMeratUGCDesign", n98);
    Unk_FeatureId n99 = (Unk_FeatureId)99;
    m_map.SetAt(L"RedMeratUGCBanner", n99);
    Unk_FeatureId n100 = (Unk_FeatureId)100;
    m_map.SetAt(L"QuestChapter00", n100);
    Unk_FeatureId n101 = (Unk_FeatureId)101;
    m_map.SetAt(L"MagicScroll03", n101);
    Unk_FeatureId n102 = (Unk_FeatureId)102;
    m_map.SetAt(L"GemDamageFont", n102);
    Unk_FeatureId n103 = (Unk_FeatureId)103;
    m_map.SetAt(L"GemTombStone", n103);
    Unk_FeatureId n104 = (Unk_FeatureId)104;
    m_map.SetAt(L"GemSwim", n104);
    Unk_FeatureId n105 = (Unk_FeatureId)105;
    m_map.SetAt(L"GemCharEffect", n105);
    Unk_FeatureId n106 = (Unk_FeatureId)107;
    m_map.SetAt(L"GemEffect", n106);
    Unk_FeatureId n107 = (Unk_FeatureId)108;
    m_map.SetAt(L"GemPetSkin", n107);
    Unk_FeatureId n108 = (Unk_FeatureId)109;
    m_map.SetAt(L"GemMeta", n108);
    Unk_FeatureId n109 = (Unk_FeatureId)110;
    m_map.SetAt(L"QuestProgress", n109);
    Unk_FeatureId n110 = (Unk_FeatureId)111;
    m_map.SetAt(L"ItemMerge", n110);
    Unk_FeatureId n111 = (Unk_FeatureId)112;
    m_map.SetAt(L"UGCMapOX", n111);
    Unk_FeatureId n112 = (Unk_FeatureId)113;
    m_map.SetAt(L"DungeonRank01", n112);
    Unk_FeatureId n113 = (Unk_FeatureId)114;
    m_map.SetAt(L"DungeonRank02", n113);
    Unk_FeatureId n114 = (Unk_FeatureId)115;
    m_map.SetAt(L"GuildSystem01", n114);
    Unk_FeatureId n115 = (Unk_FeatureId)116;
    m_map.SetAt(L"BagRenewal01", n115);
    Unk_FeatureId n116 = (Unk_FeatureId)117;
    m_map.SetAt(L"InventoryBank", n116);
    Unk_FeatureId n117 = (Unk_FeatureId)118;
    m_map.SetAt(L"ReverseRaid01", n117);
    Unk_FeatureId n118 = (Unk_FeatureId)119;
    m_map.SetAt(L"QuestNavigation", n118);
    Unk_FeatureId n119 = (Unk_FeatureId)120;
    m_map.SetAt(L"GuildMinigame01", n119);
    Unk_FeatureId n120 = (Unk_FeatureId)121;
    m_map.SetAt(L"GuildRaid01", n120);
    Unk_FeatureId n121 = (Unk_FeatureId)106;
    m_map.SetAt(L"GemFishingRod", n121);
    Unk_FeatureId n122 = (Unk_FeatureId)122;
    m_map.SetAt(L"HiddenStatAdd01", n122);
    Unk_FeatureId n123 = (Unk_FeatureId)123;
    m_map.SetAt(L"HiddenStatAdd02", n123);
    Unk_FeatureId n124 = (Unk_FeatureId)124;
    m_map.SetAt(L"EnchantScrollTab01", n124);
    Unk_FeatureId n125 = (Unk_FeatureId)125;
    m_map.SetAt(L"RestoreScrollTab01", n125);
    Unk_FeatureId n126 = (Unk_FeatureId)126;
    m_map.SetAt(L"FractoScrollTab01", n126);
    Unk_FeatureId n127 = (Unk_FeatureId)127;
    m_map.SetAt(L"ProtectedScrollTab01", n127);
    Unk_FeatureId n128 = (Unk_FeatureId)128;
    m_map.SetAt(L"ChaosRaid", n128);
    Unk_FeatureId n129 = (Unk_FeatureId)129;
    m_map.SetAt(L"LiveBroadCast", n129);
    Unk_FeatureId n130 = (Unk_FeatureId)130;
    m_map.SetAt(L"VIPGM", n130);
    Unk_FeatureId n131 = (Unk_FeatureId)131;
    m_map.SetAt(L"MeratAirTaxi", n131);
    Unk_FeatureId n132 = (Unk_FeatureId)132;
    m_map.SetAt(L"GlobalTransferType", n132);
    Unk_FeatureId n133 = (Unk_FeatureId)133;
    m_map.SetAt(L"GuildBank01", n133);
    Unk_FeatureId n134 = (Unk_FeatureId)134;
    m_map.SetAt(L"OptionBlock01", n134);
    Unk_FeatureId n135 = (Unk_FeatureId)135;
    m_map.SetAt(L"EnchantBind01", n135);
    Unk_FeatureId n136 = (Unk_FeatureId)136;
    m_map.SetAt(L"WebBrowserPopup", n136);
    Unk_FeatureId n137 = (Unk_FeatureId)137;
    m_map.SetAt(L"OptionBlockWeapon", n137);
    Unk_FeatureId n138 = (Unk_FeatureId)138;
    m_map.SetAt(L"OptionBlockArmor", n138);
    Unk_FeatureId n139 = (Unk_FeatureId)139;
    m_map.SetAt(L"OptionBlockAccessory", n139);
    Unk_FeatureId n140 = (Unk_FeatureId)140;
    m_map.SetAt(L"PetBase", n140);
    Unk_FeatureId n141 = (Unk_FeatureId)141;
    m_map.SetAt(L"PetBattle", n141);
    Unk_FeatureId n142 = (Unk_FeatureId)142;
    m_map.SetAt(L"Skin2tab", n142);
    Unk_FeatureId n143 = (Unk_FeatureId)143;
    m_map.SetAt(L"ItemExtraction", n143);
    Unk_FeatureId n144 = (Unk_FeatureId)144;
    m_map.SetAt(L"BlockExpelDungeonRoom", n144);
    Unk_FeatureId n145 = (Unk_FeatureId)145;
    m_map.SetAt(L"Mentoring", n145);
    Unk_FeatureId n146 = (Unk_FeatureId)146;
    m_map.SetAt(L"DailyMission", n146);
    Unk_FeatureId n147 = (Unk_FeatureId)147;
    m_map.SetAt(L"FindDungeonHelp", n147);
    Unk_FeatureId n148 = (Unk_FeatureId)148;
    m_map.SetAt(L"PetSkillStudy", n148);
    Unk_FeatureId n149 = (Unk_FeatureId)149;
    m_map.SetAt(L"FameContents", n149);
    Unk_FeatureId n150 = (Unk_FeatureId)150;
    m_map.SetAt(L"PcIllustOption", n150);
    Unk_FeatureId n151 = (Unk_FeatureId)151;
    m_map.SetAt(L"PetButton01", n151);
    Unk_FeatureId n152 = (Unk_FeatureId)152;
    m_map.SetAt(L"PetTrade01", n152);
    Unk_FeatureId n153 = (Unk_FeatureId)153;
    m_map.SetAt(L"HappyBirthday", n153);
    Unk_FeatureId n154 = (Unk_FeatureId)154;
    m_map.SetAt(L"PetRemake01", n154);
    Unk_FeatureId n155 = (Unk_FeatureId)155;
    m_map.SetAt(L"PetRemakeBlock01", n155);
    Unk_FeatureId n156 = (Unk_FeatureId)156;
    m_map.SetAt(L"PetRemakeBlock02", n156);
    Unk_FeatureId n157 = (Unk_FeatureId)157;
    m_map.SetAt(L"AutoMastery02", n157);
    Unk_FeatureId n158 = (Unk_FeatureId)158;
    m_map.SetAt(L"SurvivalContents01", n158);
    Unk_FeatureId n159 = (Unk_FeatureId)159;
    m_map.SetAt(L"SurvivalContents02", n159);
    Unk_FeatureId n160 = (Unk_FeatureId)160;
    m_map.SetAt(L"SurvivalContents03", n160);
    Unk_FeatureId n161 = (Unk_FeatureId)161;
    m_map.SetAt(L"SurvivalContentsTeam", n161);
    Unk_FeatureId n162 = (Unk_FeatureId)162;
    m_map.SetAt(L"SurvivalObserver", n162);
    Unk_FeatureId n163 = (Unk_FeatureId)163;
    m_map.SetAt(L"BlackmarketMaxPrice", n163);
    Unk_FeatureId n164 = (Unk_FeatureId)164;
    m_map.SetAt(L"ItemRePacking02", n164);
    Unk_FeatureId n165 = (Unk_FeatureId)165;
    m_map.SetAt(L"OptionBlock02", n165);
    Unk_FeatureId n166 = (Unk_FeatureId)166;
    m_map.SetAt(L"EnchantTransform01", n166);
    Unk_FeatureId n167 = (Unk_FeatureId)167;
    m_map.SetAt(L"ItemSocketTransfer01", n167);
    Unk_FeatureId n168 = (Unk_FeatureId)168;
    m_map.SetAt(L"QuestPostbox", n168);
    Unk_FeatureId n169 = (Unk_FeatureId)169;
    m_map.SetAt(L"UGCMarketMusicScore", n169);
    Unk_FeatureId n170 = (Unk_FeatureId)170;
    m_map.SetAt(L"WorldBossDungeon", n170);
    Unk_FeatureId n171 = (Unk_FeatureId)171;
    m_map.SetAt(L"FameChallengeDungeon", n171);
    Unk_FeatureId n172 = (Unk_FeatureId)172;
    m_map.SetAt(L"PremiumMarketPreListening", n172);
    Unk_FeatureId n173 = (Unk_FeatureId)173;
    m_map.SetAt(L"RideShareAuthority", n173);
    Unk_FeatureId n174 = (Unk_FeatureId)174;
    m_map.SetAt(L"HoldAttack", n174);
    Unk_FeatureId n175 = (Unk_FeatureId)175;
    m_map.SetAt(L"MouseContoller", n175);
    Unk_FeatureId n176 = (Unk_FeatureId)176;
    m_map.SetAt(L"Peachy01", n176);
    Unk_FeatureId n177 = (Unk_FeatureId)177;
    m_map.SetAt(L"StatScale_01", n177);
    Unk_FeatureId n178 = (Unk_FeatureId)178;
    m_map.SetAt(L"StatScale_02", n178);
    Unk_FeatureId n179 = (Unk_FeatureId)179;
    m_map.SetAt(L"StatScale_03", n179);
    Unk_FeatureId n180 = (Unk_FeatureId)180;
    m_map.SetAt(L"StatScale_04", n180);
    Unk_FeatureId n181 = (Unk_FeatureId)181;
    m_map.SetAt(L"GamePad", n181);
    Unk_FeatureId n182 = (Unk_FeatureId)182;
    m_map.SetAt(L"EnableCustomColor", n182);
    Unk_FeatureId n183 = (Unk_FeatureId)183;
    m_map.SetAt(L"NaColorSystem", n183);
    Unk_FeatureId n184 = (Unk_FeatureId)184;
    m_map.SetAt(L"DungeonRewardCountJoin01", n184);
    Unk_FeatureId n185 = (Unk_FeatureId)185;
    m_map.SetAt(L"DungeonRewardCountJoin02", n185);
    Unk_FeatureId n186 = (Unk_FeatureId)186;
    m_map.SetAt(L"MeratMessage", n186);
    Unk_FeatureId n187 = (Unk_FeatureId)187;
    m_map.SetAt(L"AchieveReward01", n187);
    Unk_FeatureId n188 = (Unk_FeatureId)188;
    m_map.SetAt(L"AchieveRewardMakeUp", n188);
    Unk_FeatureId n189 = (Unk_FeatureId)189;
    m_map.SetAt(L"AdventureLevel", n189);
    Unk_FeatureId n190 = (Unk_FeatureId)190;
    m_map.SetAt(L"PartyDamageMeter", n190);
    Unk_FeatureId n191 = (Unk_FeatureId)191;
    m_map.SetAt(L"TriggerEditorHelpURL", n191);
    Unk_FeatureId n192 = (Unk_FeatureId)192;
    m_map.SetAt(L"ConstructExp", n192);
    Unk_FeatureId n193 = (Unk_FeatureId)193;
    m_map.SetAt(L"UserGeneratedDungeon_01", n193);
    Unk_FeatureId n194 = (Unk_FeatureId)194;
    m_map.SetAt(L"CashCharge", n194);
    Unk_FeatureId n195 = (Unk_FeatureId)195;
    m_map.SetAt(L"GamePadVibration", n195);
    Unk_FeatureId n196 = (Unk_FeatureId)196;
    m_map.SetAt(L"MainMenuText", n196);
    Unk_FeatureId n197 = (Unk_FeatureId)197;
    m_map.SetAt(L"UseNumberString", n197);
    Unk_FeatureId n198 = (Unk_FeatureId)198;
    m_map.SetAt(L"TriggerVoiceDuration", n198);
    Unk_FeatureId n199 = (Unk_FeatureId)199;
    m_map.SetAt(L"WorldChampionMushroom", n199);
    Unk_FeatureId n200 = (Unk_FeatureId)200;
    m_map.SetAt(L"DungeonSmartMatch", n200);
    Unk_FeatureId n201 = (Unk_FeatureId)201;
    m_map.SetAt(L"WaterMark", n201);
    Unk_FeatureId n202 = (Unk_FeatureId)202;
    m_map.SetAt(L"JobChange_01", n202);
    Unk_FeatureId n203 = (Unk_FeatureId)203;
    m_map.SetAt(L"LapentaDungeon", n203);
    Unk_FeatureId n204 = (Unk_FeatureId)204;
    m_map.SetAt(L"EnchantReformation01", n204);
    Unk_FeatureId n205 = (Unk_FeatureId)205;
    m_map.SetAt(L"OHItemAdditionalLevel01", n205);
    Unk_FeatureId n206 = (Unk_FeatureId)206;
    m_map.SetAt(L"FreeSkin2tab", n206);
    Unk_FeatureId n207 = (Unk_FeatureId)207;
    m_map.SetAt(L"ItemStoreMoveDisable01", n207);
    Unk_FeatureId n208 = (Unk_FeatureId)208;
    m_map.SetAt(L"NextEpicQuestGuide", n208);
    Unk_FeatureId n209 = (Unk_FeatureId)209;
    m_map.SetAt(L"EnchantExpansion01", n209);
    Unk_FeatureId n210 = (Unk_FeatureId)210;
    m_map.SetAt(L"GuildSkillSystem01", n210);
    Unk_FeatureId n211 = (Unk_FeatureId)211;
    m_map.SetAt(L"Lapenshard01", n211);
    Unk_FeatureId n212 = (Unk_FeatureId)212;
    m_map.SetAt(L"FittingDollEquipAll", n212);
    Unk_FeatureId n213 = (Unk_FeatureId)213;
    m_map.SetAt(L"RazorChroma", n213);
    Unk_FeatureId n214 = (Unk_FeatureId)214;
    m_map.SetAt(L"GamePadLStickMoveSensitivity", n214);
    Unk_FeatureId n215 = (Unk_FeatureId)215;
    m_map.SetAt(L"SplashIncludeCaster", n215);
    Unk_FeatureId n216 = (Unk_FeatureId)216;
    m_map.SetAt(L"MushKingRoyaleModeSelect", n216);
    Unk_FeatureId n217 = (Unk_FeatureId)217;
    m_map.SetAt(L"FoundersPackMode", n217);
    Unk_FeatureId n218 = (Unk_FeatureId)218;
    m_map.SetAt(L"SwitchWeaponLR", n218);
    Unk_FeatureId n219 = (Unk_FeatureId)219;
    m_map.SetAt(L"HousingLevelhurdle", n219);
    Unk_FeatureId n220 = (Unk_FeatureId)220;
    m_map.SetAt(L"DirectQuestFindParty", n220);
    Unk_FeatureId n221 = (Unk_FeatureId)221;
    m_map.SetAt(L"HighlightGameMenu", n221);
    Unk_FeatureId n222 = (Unk_FeatureId)222;
    m_map.SetAt(L"ChatFormat", n222);
    Unk_FeatureId n223 = (Unk_FeatureId)223;
    m_map.SetAt(L"StatScore_01", n223);
    Unk_FeatureId n224 = (Unk_FeatureId)224;
    m_map.SetAt(L"PartyVoteKick", n224);
    Unk_FeatureId n225 = (Unk_FeatureId)225;
    m_map.SetAt(L"JobChange_02", n225);
    Unk_FeatureId n226 = (Unk_FeatureId)226;
    m_map.SetAt(L"MouseInteract", n226);
    Unk_FeatureId n227 = (Unk_FeatureId)227;
    m_map.SetAt(L"Closet", n227);
    Unk_FeatureId n228 = (Unk_FeatureId)228;
    m_map.SetAt(L"HousingDownsize", n228);
    Unk_FeatureId n229 = (Unk_FeatureId)229;
    m_map.SetAt(L"EnchantDisableBreak01", n229);
    Unk_FeatureId n230 = (Unk_FeatureId)230;
    m_map.SetAt(L"Kritias_2018_12", n230);
    Unk_FeatureId n231 = (Unk_FeatureId)231;
    m_map.SetAt(L"Newbie", n231);
    Unk_FeatureId n232 = (Unk_FeatureId)232;
    m_map.SetAt(L"AutoNewEquipSet", n232);
    Unk_FeatureId n233 = (Unk_FeatureId)233;
    m_map.SetAt(L"Blueprint", n233);
    Unk_FeatureId n234 = (Unk_FeatureId)234;
    m_map.SetAt(L"EnchantedGearItemBreak01", n234);
    Unk_FeatureId n235 = (Unk_FeatureId)235;
    m_map.SetAt(L"PetEvolution01", n235);
    Unk_FeatureId n236 = (Unk_FeatureId)236;
    m_map.SetAt(L"BlueprintMarket", n236);
    Unk_FeatureId n237 = (Unk_FeatureId)237;
    m_map.SetAt(L"InventoryPieceTab", n237);
    Unk_FeatureId n238 = (Unk_FeatureId)238;
    m_map.SetAt(L"ChatEmoticon", n238);
    Unk_FeatureId n239 = (Unk_FeatureId)239;
    m_map.SetAt(L"FameCompletionTicket", n239);
    Unk_FeatureId n240 = (Unk_FeatureId)240;
    m_map.SetAt(L"ColosseumDungeon", n240);
    Unk_FeatureId n241 = (Unk_FeatureId)241;
    m_map.SetAt(L"MonsterBuffFilter", n241);
    Unk_FeatureId n242 = (Unk_FeatureId)242;
    m_map.SetAt(L"ComboKeyCoolTime", n242);
    Unk_FeatureId n243 = (Unk_FeatureId)243;
    m_map.SetAt(L"MesoMarketToken", n243);
    Unk_FeatureId n244 = (Unk_FeatureId)244;
    m_map.SetAt(L"MesoMarketNA", n244);
    Unk_FeatureId n245 = (Unk_FeatureId)246;
    m_map.SetAt(L"Discord", n245);
    Unk_FeatureId n246 = (Unk_FeatureId)245;
    m_map.SetAt(L"LUA_itemRemakeOption", n246);
    Unk_FeatureId n247 = (Unk_FeatureId)247;
    m_map.SetAt(L"ScreenshotWebSend", n247);
    Unk_FeatureId n248 = (Unk_FeatureId)248;
    m_map.SetAt(L"MSRebuild", n248);
    Unk_FeatureId n249 = (Unk_FeatureId)249;
    m_map.SetAt(L"DungeonFindRenewal01", n249);
    Unk_FeatureId n250 = (Unk_FeatureId)250;
    m_map.SetAt(L"Peachy02", n250);
    Unk_FeatureId n251 = (Unk_FeatureId)251;
    m_map.SetAt(L"AdventureLevelMission", n251);
    Unk_FeatureId n252 = (Unk_FeatureId)252;
    m_map.SetAt(L"PeachyRecommended", n252);
    Unk_FeatureId n253 = (Unk_FeatureId)253;
    m_map.SetAt(L"ItemSocketExpansion100", n253);
    Unk_FeatureId n254 = (Unk_FeatureId)254;
    m_map.SetAt(L"GemStoneUpgrade100", n254);
    Unk_FeatureId n255 = (Unk_FeatureId)255;
    m_map.SetAt(L"LapenshardUpgrade100", n255);
    Unk_FeatureId n256 = (Unk_FeatureId)256;
    m_map.SetAt(L"UGCMapDelegator", n256);
    Unk_FeatureId n257 = (Unk_FeatureId)257;
    m_map.SetAt(L"PetRePackingInfoOpen", n257);
    Unk_FeatureId n258 = (Unk_FeatureId)258;
    m_map.SetAt(L"RedMeratMaid", n258);
    Unk_FeatureId n259 = (Unk_FeatureId)259;
    m_map.SetAt(L"TurkaDungeon", n259);
    Unk_FeatureId n260 = (Unk_FeatureId)260;
    m_map.SetAt(L"Wedding", n260);
    Unk_FeatureId n261 = (Unk_FeatureId)261;
    m_map.SetAt(L"WeddingBlockSex", n261);
    Unk_FeatureId n262 = (Unk_FeatureId)262;
    m_map.SetAt(L"WeddingBlockAge", n262);
    Unk_FeatureId n263 = (Unk_FeatureId)263;
    m_map.SetAt(L"MassiveHideAndSeek", n263);
    Unk_FeatureId n264 = (Unk_FeatureId)264;
    m_map.SetAt(L"MeratMarketNewBM", n264);
    Unk_FeatureId n265 = (Unk_FeatureId)265;
    m_map.SetAt(L"Payback", n265);
    Unk_FeatureId n266 = (Unk_FeatureId)266;
    m_map.SetAt(L"GachaCapsuleMachine", n266);
    Unk_FeatureId n267 = (Unk_FeatureId)267;
    m_map.SetAt(L"RedMeratBeauty", n267);
    Unk_FeatureId n268 = (Unk_FeatureId)268;
    m_map.SetAt(L"RedMeratSmartPush", n268);
    Unk_FeatureId n269 = (Unk_FeatureId)269;
    m_map.SetAt(L"UnlimitedEnchant", n269);
    Unk_FeatureId n270 = (Unk_FeatureId)270;
    m_map.SetAt(L"WaterGunBattle", n270);
    Unk_FeatureId n271 = (Unk_FeatureId)271;
    m_map.SetAt(L"GemStoneSwap", n271);
    Unk_FeatureId n272 = (Unk_FeatureId)272;
    m_map.SetAt(L"GuildPvP", n272);
    Unk_FeatureId n273 = (Unk_FeatureId)273;
    m_map.SetAt(L"AdventureProtect", n273);
    Unk_FeatureId n274 = (Unk_FeatureId)274;
    m_map.SetAt(L"DeleteAccount", n274);
    Unk_FeatureId n275 = (Unk_FeatureId)275;
    m_map.SetAt(L"ProbabilityLogReport", n275);
    Unk_FeatureId n276 = (Unk_FeatureId)276;
    m_map.SetAt(L"ProbabilityLogWriteDb", n276);
    Unk_FeatureId n277 = (Unk_FeatureId)277;
    m_map.SetAt(L"ProbabilityLogUseStatistics", n277);
    Unk_FeatureId n278 = (Unk_FeatureId)278;
    m_map.SetAt(L"ProbabilityLogReportForTest", n278);
    Unk_FeatureId n279 = (Unk_FeatureId)279;
    m_map.SetAt(L"PersonalInfoAgreement", n279);
    if (m_map.GetCount() != 0x117)
    {
        FUN_1401859c0(CLogString::GetInstance(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4" L"CFeatureTable::Init : can't find featureName.");
        return false;
    }
    return true;
}
#line 698

// @0x14036b9e0
void CFeatureTable::FUN_14036b9e0()
{
    m_map.~NameMap();
}

// @0x14036f550
// MS2-FUNCTIONAL: singleton creation keeps an extra EH temp in the exe
CFeatureTable* CFeatureTable::FUN_14036f550()
{
    if (s_instance != 0)
        return GetInstance();
    return new CFeatureTable;
}

// @0x14036f750
void CFeatureTable::FUN_14036f750()
{
    if (s_instance != 0)
    {
        delete GetInstance();
        s_instance = 0;
    }
}

// @0x14036ca70
CFeatureManager::CFeatureManager()
    : m_nLevel(0)
{
    m_strLocale = s_strServerType;
    m_strLocale.MakeLower();
    CFeatureTable::FUN_14036f550();
}

// @0x14036cbf0
CFeatureManager::~CFeatureManager()
{
    CFeatureTable::FUN_14036f750();
}

// @0x14036ccb0
bool CFeatureManager::FUN_14036ccb0()
{
    if (!FUN_14036d3d0())
        return false;
    if (!FUN_14036cd50())
        return false;
    if (!FUN_14036d040())
        return false;
    SetInit(true);
    if (FUN_14036d570(2))
        FUN_1406aeee0()->FUN_1406af150();
    return true;
}

// @0x14036cd30
bool CFeatureManager::FUN_14036cd30()
{
    return GetInit();
}

// @0x14036cd50
// MS2-FUNCTIONAL: XML loader temp layout differs
bool CFeatureManager::FUN_14036cd50()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("feature_setting.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(CLogString::GetInstance(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pSetting = pRoot->FUN_140165cf0("setting"); pSetting != 0;
         pSetting = pSetting->FUN_140168650("setting"))
    {
        CString strUnused;
        CString strType;
        int nLevel;
        FUN_1408733e0(pSetting, "type", strType);
        FUN_1408731e0(pSetting, FUN_14016a5c0(FUN_140651390(), 0), nLevel);
        if (strType.CompareNoCase(m_strLocale) == 0)
        {
            m_nLevel = nLevel;
            break;
        }
    }
    return true;
}

// @0x14036d040
// MS2-FUNCTIONAL: XML loader temp layout differs
bool CFeatureManager::FUN_14036d040()
{
    CString strPath = FUN_14071a5b0(CString("Table"), CString("feature.xml"));
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, strPath, 0, true, false) == 0)
        return false;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
    {
        FUN_14015eb90(CLogString::GetInstance(), 1, 0x13, L"xml \xd615\xc2dd\xc774 \xc798\xbabb \xb418\xc5c8\xc2b5\xb2c8\xb2e4[<ms2> {0}]", strPath);
        return false;
    }
    for (Unk_140165cf0* pFeature = pRoot->FUN_140165cf0("feature"); pFeature != 0;
         pFeature = pFeature->FUN_140168650("feature"))
    {
        CStringW strName;
        int nLevel = 0;
        FUN_140873420(pFeature, "name", strName);
        FUN_1408731e0(pFeature, FUN_14016a5c0(FUN_140651390(), 0), nLevel);
        if (nLevel != 0)
        {
            m_nameLevels.SetAt(strName, nLevel);
            Unk_FeatureId nId = (Unk_FeatureId)1;
            if (CFeatureTable::GetInstance()->m_map.Lookup(strName, nId))
                m_idLevels.SetAt(nId, nLevel);
            bool bOn = nLevel <= m_nLevel;
            FUN_140291e40(CStringW(strName), bOn, "feature");
        }
    }
    return true;
}

// @0x14036d3d0
// MS2-FUNCTIONAL: map lookup glue/temp layout differs
bool CFeatureManager::FUN_14036d3d0()
{
    if (!CFeatureTable::GetInstance()->Init())
        return false;
    POSITION pos = CFeatureTable::GetInstance()->m_map.GetStartPosition();
    while (pos != 0)
    {
        CStringW strName = CFeatureTable::GetInstance()->m_map.GetKeyAt(pos);
        Unk_FeatureId nId = CFeatureTable::GetInstance()->m_map.GetValueAt(pos);
        m_idNames.SetAt(nId, strName);
        CFeatureTable::GetInstance()->m_map.GetNext(pos);
    }
    return true;
}

// @0x14036d4b0
bool CFeatureManager::FUN_14036d4b0(const CStringW& strName)
{
    CheckInit();
    if (strName.IsEmpty())
        return true;
    int nLevel = 0;
    if (m_nameLevels.Lookup(strName, nLevel))
        return nLevel <= m_nLevel;
    Unk_FeatureLog(CLogString::GetInstance(), 1, 0x13, L"Feature Unknown Feature Name: {0}", strName);
    return false;
}

// @0x14036d570
bool CFeatureManager::FUN_14036d570(int nFeature)
{
    CheckInit();
    if (nFeature == 0)
        return false;
    if (nFeature == 1)
        return true;
    int nLevel = 0;
    if (m_idLevels.Lookup(*reinterpret_cast<const Unk_FeatureId*>(&nFeature), nLevel))
        return nLevel <= m_nLevel;
    Unk_FeatureLogId(CLogString::GetInstance(), 1, 0x13, L"Feature Unknown Feature Name: {0}",
                     *reinterpret_cast<const Unk_FeatureId*>(&nFeature));
    MS2_ASSERT_AT(0xb3, 0);
    return false;
}

// @0x14036d650
bool CFeatureManager::FUN_14036d650()
{
    if (!GetInstance()->FUN_14036d570(0x43))
        return false;
    return true;
}

// @0x14036d690
bool CFeatureManager::FUN_14036d690(int nFeature)
{
    if (!FUN_14036d650())
        return false;
    return GetInstance()->FUN_14036d570(nFeature);
}

// @0x14036d6d0
bool CFeatureManager::FUN_14036d6d0()
{
    if (!GetInstance()->FUN_14036d570(0x43))
        return false;
    return true;
}

// @0x14036d710
bool CFeatureManager::FUN_14036d710(int nFeature)
{
    if (!FUN_14036d6d0())
        return false;
    return GetInstance()->FUN_14036d570(nFeature);
}

// @0x14036d750
bool CFeatureManager::FUN_14036d750(const CStringW& strList)
{
    if (strList.IsEmpty())
        return true;
    ATL::CAtlArray<CStringW> locales;
    FUN_14025a680(strList, &locales, L",");
    for (UINT i = 0; i < locales.GetCount(); i++)
    {
        if (FUN_14036d960().CompareNoCase(locales[i]) == 0)
            return true;
    }
    return false;
}

// @0x14036d8b0
int CFeatureManager::FUN_14036d8b0()
{
    CheckInit();
    return m_nLevel;
}

// @0x14036d8e0
CString CFeatureManager::FUN_14036d8e0()
{
    return FUN_14016a5c0(FUN_140651390(), 0);
}

// @0x14036d960
CStringW CFeatureManager::FUN_14036d960()
{
    return FUN_14016a730(FUN_140651390(), 0);
}

// @0x14036d9e0
int CFeatureManager::FUN_14036d9e0(const CStringW& strName)
{
    CheckInit();
    Unk_FeatureId nId = (Unk_FeatureId)0;
    if (CFeatureTable::GetInstance()->m_map.Lookup(strName, nId))
        return nId;
    return nId;
}

// @0x14036da50
CStringW CFeatureManager::FUN_14036da50(int nFeature)
{
    CheckInit();
    CStringW strName(L"");
    if (m_idNames.Lookup(*reinterpret_cast<const Unk_FeatureId*>(&nFeature), strName))
        return strName;
    return strName;
}

// @0x14036db20
int CFeatureManager::FUN_14036db20()
{
    if (FUN_14036d570(0x2c))
        return 99;
    else if (FUN_14036d570(0x2b))
        return 90;
    else if (FUN_14036d570(0x2a))
        return 80;
    else if (FUN_14036d570(0x29))
        return 70;
    else if (FUN_14036d570(0x28))
        return 65;
    else if (FUN_14036d570(0x27))
        return 60;
    else if (FUN_14036d570(0x26))
        return 55;
    return 50;
}

// @0x14036dc20
int CFeatureManager::FUN_14036dc20()
{
    return 0x32;
}

// @0x14036dc40
int CFeatureManager::FUN_14036dc40()
{
    return 0x32;
}

// @0x14036dc60
int CFeatureManager::FUN_14036dc60()
{
    return 0x32;
}

// @0x14036dc80
// MS2-FUNCTIONAL: the cap constants are separate 4-byte statics in the exe; here they are unit-local ushort constants
unsigned short CFeatureManager::FUN_14036dc80()
{
    if (FUN_14036d570(0x2c))
        return std::min<unsigned short>(s_nBaseLevelCap, s_nLevelCap99);
    if (FUN_14036d570(0x2b))
        return std::min<unsigned short>(s_nBaseLevelCap, s_nLevelCap90);
    if (FUN_14036d570(0x2a))
        return std::min<unsigned short>(s_nBaseLevelCap, s_nLevelCap80);
    if (FUN_14036d570(0x29))
        return std::min<unsigned short>(s_nBaseLevelCap, s_nLevelCap70);
    if (FUN_14036d570(0x28))
        return std::min<unsigned short>(s_nBaseLevelCap, s_nLevelCap65);
    if (FUN_14036d570(0x27))
        return std::min<unsigned short>(s_nBaseLevelCap, s_nLevelCap60);
    if (FUN_14036d570(0x26))
        return std::min<unsigned short>(s_nBaseLevelCap, s_nLevelCap55);
    return 0x32;
}

// @0x14036de00
int CFeatureManager::FUN_14036de00()
{
    return 0x32;
}

// @0x14036de20
// MS2-FUNCTIONAL: CString return temps differ
CStringW CFeatureManager::FUN_14036de20(const CStringW& strA, const CStringW& strB)
{
    CheckInit();
    if (FUN_14025cd60(strA, strB))
        return strA;
    int nLevelA = 0;
    int nLevelB = 0;
    m_nameLevels.Lookup(strA, nLevelA);
    m_nameLevels.Lookup(strB, nLevelB);
    if (nLevelB < nLevelA)
        return strA;
    if (nLevelA < nLevelB)
        return strB;
    if (strA.Compare(strB) < 1)
        return strB;
    return strA;
}

// @0x14036dfa0
// MS2-FUNCTIONAL: CString return temps differ
CStringW CFeatureManager::FUN_14036dfa0(const CStringW& strA, const CStringW& strB)
{
    CheckInit();
    if (FUN_14025cd60(strA, strB))
        return strA;
    if (FUN_14025cd60(FUN_14036d960(), strA))
        return strA;
    if (FUN_14025cd60(FUN_14036d960(), strB))
        return strB;
    if (strA.IsEmpty())
        return strA;
    if (strB.IsEmpty())
        return strB;
    return strA;
}

// @0x14036e160
// MS2-FUNCTIONAL: CString temps differ
Unk_140165cf0* CFeatureManager::FUN_14036e160(Unk_140165cf0* pA, Unk_140165cf0* pB)
{
    CheckInit();
    Unk_140165cf0* pResult = pA;
    if (pB != 0 && (pResult = pB, pA != 0))
    {
        CStringW strFeatureA;
        CStringW strFeatureB;
        FUN_140873420(pA, "feature", strFeatureA);
        FUN_140873420(pB, "feature", strFeatureB);
        if (!FUN_140164830(strFeatureA, strFeatureB))
        {
            CStringW strLocaleA;
            CStringW strLocaleB;
            FUN_140873420(pA, "locale", strLocaleA);
            FUN_140873420(pB, "locale", strLocaleB);
            if (!FUN_140164830(strLocaleA, strLocaleB))
            {
                CStringW strRow = FUN_140875470(pA);
                Unk_FeatureLog2(CLogString::GetInstance(), 0, 0, 0x13, L"Feature and Locale is Same : {0}", strRow);
                pResult = pA;
            }
            else
            {
                CStringW strBest = FUN_14036dfa0(strLocaleA, strLocaleB);
                if (!FUN_14025cd60(strBest, strLocaleA))
                    pResult = pB;
                else
                    pResult = pA;
            }
        }
        else
        {
            CStringW strBest = FUN_14036de20(strFeatureA, strFeatureB);
            if (!FUN_14025cd60(strBest, strFeatureA))
                pResult = pB;
            else
                pResult = pA;
        }
    }
    return pResult;
}

// @0x14036e4c0
// MS2-FUNCTIONAL: temporary CString result is passed by pointer in the exe (smaller frame)
bool CFeatureManager::FUN_14036e4c0()
{
    return FUN_140184310(FUN_14036d8e0(), "KR");
}

// @0x14036e510
// MS2-FUNCTIONAL: same temporary CString shape as e4c0
bool CFeatureManager::FUN_14036e510()
{
    return FUN_140184310(FUN_14036d8e0(), "CN");
}

// @0x14036e560
// MS2-FUNCTIONAL: same temporary CString shape as e4c0
bool CFeatureManager::FUN_14036e560()
{
    return FUN_140184310(FUN_14036d8e0(), "NA");
}

// @0x14036e5b0
// MS2-FUNCTIONAL: same temporary CString shape as e4c0
bool CFeatureManager::FUN_14036e5b0()
{
    return FUN_140184310(FUN_14036d8e0(), "JP");
}

// @0x14036e600
CString CFeatureManager::FUN_14036e600()
{
    return s_strServerType;
}

// @0x14036e640
void CFeatureManager::FUN_14036e640(CString strType)
{
    if (strType.IsEmpty())
        return;
    s_strServerType = strType;
    s_nServerType = FUN_140219a50(s_strServerType);
}

// @0x14036e6b0
int CFeatureManager::FUN_14036e6b0()
{
    return s_nServerType;
}

// @0x14036e6c0
// MS2-FUNCTIONAL: exe keeps a 4-byte result local with a different branch layout
bool CFeatureManager::FUN_14036e6c0()
{
    bool bRet;
    if (s_nServerType == 1 || s_nServerType == 2 || s_nServerType == 3)
        bRet = true;
    else
        bRet = false;
    return bRet;
}

// @0x14036e700
int CFeatureManager::FUN_14036e700(const CStringW& strName)
{
    if (GetInstance() == 0)
        return 1;
    return GetInstance()->FUN_14036d9e0(strName);
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142c9a700-0x142c9a720 .text$yd
