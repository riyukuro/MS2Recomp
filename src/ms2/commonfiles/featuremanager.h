// featuremanager.h - CFeatureTable / CFeatureManager (commonfiles\featuremanager.cpp, RTTI .?AVCFeatureTable@@ and
// .?AVCFeatureManager@@). Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The member names are invented where
// the exe has none (the functions keep their FUN_ names).
//
// CFeatureTable is the built-in table of the 279 feature names and their numeric ids (a singleton created by the
// CFeatureManager ctor). CFeatureManager reads feature_setting.xml (the level of this server/locale) and feature.xml
// (name -> the level a feature switches on) and answers "is this feature on" queries.
#pragma once

#include <atlcoll.h>
#include <atlstr.h>
#include <typeinfo>
#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/cvaliddata.h"

class Unk_140165cf0;                        // game TinyXML element

CString FUN_14016a5c0(const char* psz, int nCodePage);          // narrows a string (the RTTI name in CheckInit)

// The feature id (the 279 ids of CFeatureTable::Init). The maps below store it as an enum: the exe's SetAt/Lookup glue
// takes the keys and values by reference. The member names of the ids are not recovered.
enum Unk_FeatureId : int { Unk_FeatureNone = 0 };

class CFeatureTable;
class CFeatureManager;

// 0x50 bytes: TSingleton +0 (vftable 0x142d3ebd0), the name -> id map +8.
class CFeatureTable : public TSingleton<CFeatureTable>
{
public:
    CFeatureTable();                        // 0x14036eef0

    bool Init();                            // 0x1403687f0 fills the name -> id map, false when the count is not 279
    void FUN_14036b9e0();                   // runs the map destructor (never called)
    static CFeatureTable* FUN_14036f550();  // the instance (created when missing)
    static void FUN_14036f750();            // deletes the instance

    typedef ATL::CAtlMap<CStringW, Unk_FeatureId, ATL::CStringElementTraits<CStringW> > NameMap;
    NameMap m_map;                          // +0x08
};
MS2_CHECK_SIZE(CFeatureTable, 0x50);
MS2_CHECK_OFFSET(CFeatureTable, m_map, 0x08);

// 0x100 bytes: TSingleton +0, CValidData +8, the data below from +0x10.
class CFeatureManager : public TSingleton<CFeatureManager>, public CValidData<CFeatureManager>
{
public:
    CFeatureManager();                      // 0x14036ca70
    virtual ~CFeatureManager();             // 0x14036cbf0

    bool FUN_14036ccb0();                                       // loads the feature files; false when missing
    bool FUN_14036cd30();                                       // the manager is initialised
    bool LoadFeatureSetting();                                       // feature_setting.xml: the level of this locale
    bool LoadFeature();                                       // feature.xml: feature name -> level
    bool FUN_14036d3d0();                                       // builds the id -> name map
    bool FUN_14036d4b0(const CStringW& strName);                // the named feature is switched on
    bool FUN_14036d570(int nFeature);                           // the feature is switched on
    bool FUN_14036d650();                                       // red merat in use
    bool FUN_14036d690(int nFeature);
    bool FUN_14036d6d0();
    bool FUN_14036d710(int nFeature);
    bool FUN_14036d750(const CStringW& strList);                // one of a ","-separated list of locales matches
    int FUN_14036d8b0();                                        // the server number of the window title
    CString FUN_14036d8e0();                                    // the server name of the window title
    CStringW FUN_14036d960();                                   // the same as a wide string
    int FUN_14036d9e0(const CStringW& strName);                 // the level of a feature name
    CStringW FUN_14036da50(int nFeature);                       // the name of a feature id
    int FUN_14036db20();                                        // the level cap of this server
    int FUN_14036dc20();
    int FUN_14036dc40();
    int FUN_14036dc60();
    unsigned short FUN_14036dc80();                             // the level cap as the smaller of two limits
    int FUN_14036de00();
    CStringW FUN_14036de20(const CStringW& strA, const CStringW& strB);     // the one with the higher feature level
    CStringW FUN_14036dfa0(const CStringW& strA, const CStringW& strB);     // the one matching this locale
    Unk_140165cf0* FUN_14036e160(Unk_140165cf0* pA, Unk_140165cf0* pB);    // the winner of two <feature> rows
    bool FUN_14036e4c0();                                       // locale KR
    bool FUN_14036e510();                                       // locale CN
    bool FUN_14036e560();                                       // locale NA
    bool FUN_14036e5b0();                                       // locale JP

    static CString FUN_14036e600();                             // the server type name ("Live" by default)
    static void FUN_14036e640(CString strType);                 // sets the server type name and its id
    static int FUN_14036e6b0();                                 // the server type id
    static bool FUN_14036e6c0();                                // the server type is 1, 2 or 3
    static int FUN_14036e700(const CStringW& strName);          // the level of a feature name (1 without a manager)

    // @0x14036f450
    static void CheckInit()
    {
        if (!s_bInit)
        {
            CStringA msg;
            msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(CFeatureManager).name(), 0));
            MessageBoxA(0, msg, "Error", 0);
        }
    }
    // @0x140372400
    static void SetInit(bool bInit) { s_bInit = bInit; }
    // @0x140370600
    static bool GetInit() { return s_bInit; }

    static bool s_bInit;                                        // DAT_143aaeb38
    static CString s_strServerType;                             // DAT_143aaeb28 ("Live")
    static int s_nServerType;                                   // DAT_143aaeb20

    int m_nLevel;                                               // +0x10 the level of this locale (feature_setting.xml)
    CString m_str18;                                            // +0x18
    CString m_strLocale;                                        // +0x20 the server type name, lower case
    ATL::CAtlMap<Unk_FeatureId, int> m_idLevels;                          // +0x28 feature id -> level
    ATL::CAtlMap<CStringW, int, ATL::CStringElementTraitsI<CStringW> > m_nameLevels;   // +0x70 feature name -> level
    ATL::CAtlMap<Unk_FeatureId, CStringW> m_idNames;                      // +0xb8 feature id -> name
};
MS2_CHECK_SIZE(CFeatureManager, 0x100);
MS2_CHECK_OFFSET(CFeatureManager, m_nLevel, 0x10);
MS2_CHECK_OFFSET(CFeatureManager, m_idLevels, 0x28);
MS2_CHECK_OFFSET(CFeatureManager, m_nameLevels, 0x70);
MS2_CHECK_OFFSET(CFeatureManager, m_idNames, 0xb8);
