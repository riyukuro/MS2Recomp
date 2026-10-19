// dpsmetersystem.h - the DPS meter of the client (?\dpsmetersystem.cpp): CDPSMeterSystem records the damage, heal and
// stat events of the own player between a start and a stop (UIDPSDialog drives it) into a CMeterRecordData, and a worker
// thread writes each finished record as text/csv files under <exe dir>\log\DPS. CDPSDialog is the debug tool dialog
// (resource 0x91) that shows the summary text. Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13); header name
// assumed. Class names are RTTI names; member names are invented from use (cross-checked against the v2525 decomp,
// work/ext/v2525/x/ms2decomp/include/ms2/CDPSMeterSystem.h and CMeterRecordData.h).
#pragma once

#include <afxcmn.h>
#include <atlcoll.h>
#include <map>

#include "ms2/ms2layout.h"
#include "ms2/commonfiles/os.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/clockcriticalsection.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/client/ms2/toolbasedialog.h"

class CDamageRecord;
class CDotDamageRecord;
class CSplashDamageRecord;

// One hit (vftable 0x142eb83c8, new(0x78)).
class CDamageMeterData : public CPtred
{
public:
    CDamageMeterData();                                     // 0x141185440 (dtor 0x141185c90, ??_G 0x141186700)

    SYSTEMTIME m_time;                                      // +0x18
    __int64 m_nTagId;                                       // +0x28 the hit's tag (CDamageRecord::m_nTagId)
    int m_nSkillId;                                         // +0x30 skill or additional effect id
    short m_nLevel;                                         // +0x34
    int m_nCasterId;                                        // +0x38
    int m_nTargetId;                                        // +0x3c
    CStringW m_strCaster;                                   // +0x40
    CStringW m_strTarget;                                   // +0x48
    int m_nKind;                                            // +0x50 0 skill hit, 1 damage over time
    int m_nAttribute;                                       // +0x54 0..7 (FUN_1411821c0 names them)
    int m_nGrade;                                           // +0x58 0 normal, 1 critical, 2 miss, 3 block ...
    __int64 m_nDamage;                                      // +0x60
    double m_dRate;                                         // +0x68 the DamageRate share of the hit
    int m_bKilled;                                          // +0x70 the target died
};
MS2_CHECK_OFFSET(CDamageMeterData, m_nTagId, 0x28);
MS2_CHECK_OFFSET(CDamageMeterData, m_strCaster, 0x40);
MS2_CHECK_OFFSET(CDamageMeterData, m_nDamage, 0x60);
MS2_CHECK_SIZE(CDamageMeterData, 0x78);

// The per-skill sum of the skill report (vftable 0x142eb83b8, new(0x58)).
class CSkillMeterData : public CPtred
{
public:
    CSkillMeterData();                                      // 0x141185870 (dtor 0x141185ee0, ??_G 0x141186900)

    int m_nSkillId;                                         // +0x18
    short m_nLevel;                                         // +0x1c
    __int64 m_nTotal;                                       // +0x20
    __int64 m_nNormal;                                      // +0x28
    __int64 m_nCritical;                                    // +0x30
    int m_nHit;                                             // +0x38
    int m_nMiss;                                            // +0x3c
    int m_nAttribute;                                       // +0x40
    __int64 m_nNormalMax;                                   // +0x48
    __int64 m_nCriticalMax;                                 // +0x50
};
MS2_CHECK_OFFSET(CSkillMeterData, m_nTotal, 0x20);
MS2_CHECK_OFFSET(CSkillMeterData, m_nNormalMax, 0x48);
MS2_CHECK_SIZE(CSkillMeterData, 0x58);

// One stat change (heal / spirit / stamina; vftable 0x142eb83e8, new(0x40)).
class CStatMeterData : public CPtred
{
public:
    CStatMeterData();                                       // 0x141185920 (dtor 0x141185f00, ??_G 0x141186940)

    unsigned m_nTime;                                       // +0x18
    __int64 m_nValue;                                       // +0x20
    __int64 m_nEffective;                                   // +0x28
    __int64 m_nOver;                                        // +0x30
    int m_nType;                                            // +0x38
};
MS2_CHECK_OFFSET(CStatMeterData, m_nValue, 0x20);
MS2_CHECK_SIZE(CStatMeterData, 0x40);

// One additional effect event (vftable 0x142eb83d8, new(0x58)).
class CAdditionalEffectMeterData : public CPtred
{
public:
    CAdditionalEffectMeterData();                           // 0x141185390 (dtor 0x141185c40, ??_G 0x141186680)

    SYSTEMTIME m_time;                                      // +0x18
    CStringW m_strEvent;                                    // +0x28
    __int64 m_n30;                                          // +0x30
    int m_nEffectId;                                        // +0x38
    short m_nLevel;                                         // +0x3c
    int m_nCasterId;                                        // +0x40
    int m_nTargetId;                                        // +0x44
    CStringW m_strCaster;                                   // +0x48
    CStringW m_strTarget;                                   // +0x50
};
MS2_CHECK_OFFSET(CAdditionalEffectMeterData, m_nEffectId, 0x38);
MS2_CHECK_OFFSET(CAdditionalEffectMeterData, m_strTarget, 0x50);
MS2_CHECK_SIZE(CAdditionalEffectMeterData, 0x58);

// One recording (vftable 0x142eb83f8, new(0x3e0)).
class CMeterRecordData : public CPtred
{
public:
    // The sums of one side (the player as the attacker, and as the target), 0x1a0 bytes.
    struct Aggregation
    {
        Aggregation();                                      // 0x141178c40 (dtor 0x141185e50)
        void AddDamage(MS2Ptr<CDamageMeterData> spData);    // 0x141178de0
        const CStringW& GetSkillReport();                   // 0x1411790a0 m_damages by skill
        const CStringW& GetDamageLog();                     // 0x141179ac0 m_damages hit by hit
        const CStringW& GetDotReport();                     // 0x141179ec0 m_dots by effect
        const CStringW& GetEffectLog();                     // 0x14117a950 m_effects

        ATL::CAtlList<MS2Ptr<CDamageMeterData> > m_damages;            // +0x00 skill hits
        ATL::CAtlList<MS2Ptr<CDamageMeterData> > m_dots;               // +0x30 damage over time
        std::map<int, float> m_skillRates;                             // +0x60 DamageRate by skill id
        std::map<int, float> m_dotRates;                               // +0x70 DamageRate by effect id
        ATL::CAtlList<MS2Ptr<CStatMeterData> > m_heals;                // +0x80
        ATL::CAtlList<MS2Ptr<CStatMeterData> > m_spirits;              // +0xb0
        ATL::CAtlList<MS2Ptr<CAdditionalEffectMeterData> > m_effects;  // +0xe0
        __int64 m_nTotal;                                   // +0x110
        __int64 m_nNormal;                                  // +0x118
        __int64 m_nCritical;                                // +0x120
        __int64 m_nDot;                                     // +0x128
        double m_dRate;                                     // +0x130
        __int64 m_nMagic;                                   // +0x138 attributes 0..5
        __int64 m_nPhysical;                                // +0x140 attributes 6, 7
        __int64 m_attributes[8];                            // +0x148
        int m_nCount;                                       // +0x188
        int m_nMiss;                                        // +0x18c
        int m_nBlock;                                       // +0x190
        int m_nHit;                                         // +0x194
        int m_nKill;                                        // +0x198
        int m_nCriticalCount;                               // +0x19c
    };

    CMeterRecordData();                                     // 0x141185530 (dtor 0x141185cd0, ??_G 0x141186740)

    unsigned m_nStartTime;                                  // +0x18
    unsigned m_nEndTime;                                    // +0x1c
    unsigned m_nCombatTime;                                 // +0x20
    Aggregation m_attack;                                   // +0x28
    Aggregation m_defense;                                  // +0x1c8
    CStringW m_strSummary;                                  // +0x368
    CStringW m_strCsv;                                      // +0x370
    __int64 m_nExp;                                         // +0x378
    __int64 m_nMeso;                                        // +0x380
    __int64 m_nNaturalSp;                                   // +0x388
    __int64 m_nNaturalEp;                                   // +0x390
    __int64 m_nSkillSp;                                     // +0x398
    __int64 m_nHealed;                                      // +0x3a0
    __int64 m_nHealedEffective;                             // +0x3a8
    __int64 m_nSpentSp;                                     // +0x3b0
    __int64 m_nSpentEp;                                     // +0x3b8
    int m_nHealTargets;                                     // +0x3c0
    __int64 m_nHeal;                                        // +0x3c8
    __int64 m_nHealEffective;                               // +0x3d0
    int m_nSkillUse;                                        // +0x3d8
};
MS2_CHECK_OFFSET(CMeterRecordData::Aggregation, m_skillRates, 0x60);
MS2_CHECK_OFFSET(CMeterRecordData::Aggregation, m_heals, 0x80);
MS2_CHECK_OFFSET(CMeterRecordData::Aggregation, m_effects, 0xe0);
MS2_CHECK_OFFSET(CMeterRecordData::Aggregation, m_nTotal, 0x110);
MS2_CHECK_OFFSET(CMeterRecordData::Aggregation, m_attributes, 0x148);
MS2_CHECK_OFFSET(CMeterRecordData::Aggregation, m_nCount, 0x188);
MS2_CHECK_SIZE(CMeterRecordData::Aggregation, 0x1a0);
MS2_CHECK_OFFSET(CMeterRecordData, m_attack, 0x28);
MS2_CHECK_OFFSET(CMeterRecordData, m_defense, 0x1c8);
MS2_CHECK_OFFSET(CMeterRecordData, m_strSummary, 0x368);
MS2_CHECK_OFFSET(CMeterRecordData, m_nHealTargets, 0x3c0);
MS2_CHECK_OFFSET(CMeterRecordData, m_nSkillUse, 0x3d8);
MS2_CHECK_SIZE(CMeterRecordData, 0x3e0);

// The meter (TSingleton, vftable 0x142eb8418, 0x2a8 bytes; created by CGameApp::InitInstance in ?\ms2.cpp).
class CDPSMeterSystem : public TSingleton<CDPSMeterSystem>
{
public:
    CDPSMeterSystem();                                      // 0x14117acd0
    virtual ~CDPSMeterSystem();                             // 0x14117adb0 (??_G 0x1411866c0)

    void StartThread();                                     // 0x14117ae30
    void StopThread();                                      // 0x14117b080
    static unsigned __stdcall ThreadEntry(void* pParam);    // 0x14117b120
    unsigned ThreadProc();                                  // 0x14117b170 writes the finished records
    int StartRecord(unsigned nTime);                        // 0x14117c650
    int StopRecord(unsigned nTime);                         // 0x14117c7c0
    int IsRecording();                                      // 0x14117c8b0
    int Reset();                                            // 0x14117c920 drops the current and the queued records
    void Flush();                                           // 0x14117c9b0 wakes the writer
    void Accumulate(CMeterRecordData::Aggregation* pAgg, MS2Ptr<CDamageMeterData> spData);   // 0x14117c9f0
    int AddDamage(int nSide, int nCasterId, int nTargetId, int nKind, int nAttribute, __int64 nTagId, int nSkillId,
        short nLevel, int nGrade, __int64 nDamage, float fRate);                              // 0x14117ccc0
    int AddStat(int nSide, int nList, __int64 nValue, __int64 nEffective, __int64 nOver, int nType);   // 0x14117d090
    int AddEffect(CStringW strEvent, int nSide, int nCasterId, int nTargetId, int nEffectId, short nLevel);  // 0x14117d460
    void OnDamage(MS2Ptr<CDamageRecord> spRecord);          // 0x14117d750
    void OnDotDamage(MS2Ptr<CDotDamageRecord> spRecord);    // 0x14117dbe0
    void OnSplashDamage(MS2Ptr<CSplashDamageRecord> spRecord);   // 0x14117e030
    void AddMeso(__int64 nMeso);                            // 0x14117e4c0
    void AddExp(__int64 nExp);                              // 0x14117e560
    void AddSkillUse();                                     // 0x14117e600
    void AddHealTarget();                                   // 0x14117e690
    void AddHealedEffective(__int64 nValue);                // 0x14117e720
    void AddHealEffective(__int64 nValue);                  // 0x14117e7c0
    void SetCombat(int bCombat);                            // 0x14117e860
    void GetSummary(CStringW& str);                         // 0x14117e960
    void FUN_14117ea90(unsigned nTime, int bCsv);           // 0x14117ea90 builds m_strSummary / m_strCsv (not written yet)

    int m_bRunning;                                         // +0x08 the writer thread runs
    HANDLE m_hThread;                                       // +0x10
    HANDLE m_hEvent;                                        // +0x18
    unsigned m_nCombatStart;                                // +0x20
    int m_bCombat;                                          // +0x24
    int m_bFlush;                                           // +0x28 a record waits for the writer
    int m_bRecording;                                       // +0x2c
    ATL::CAtlList<MS2Ptr<CMeterRecordData> > m_records;     // +0x30 finished records
    wchar_t m_szDir[MAX_PATH];                              // +0x60 <exe dir>\log\DPS
    CLockCriticalSection m_lock;                            // +0x268
    MS2Ptr<CMeterRecordData> m_spRecord;                    // +0x298 the running record
};
MS2_CHECK_OFFSET(CDPSMeterSystem, m_records, 0x30);
MS2_CHECK_OFFSET(CDPSMeterSystem, m_szDir, 0x60);
MS2_CHECK_OFFSET(CDPSMeterSystem, m_lock, 0x268);
MS2_CHECK_OFFSET(CDPSMeterSystem, m_spRecord, 0x298);
MS2_CHECK_SIZE(CDPSMeterSystem, 0x2a8);

// The DPS tool dialog (resource 0x91, 0x350 bytes; TSingleton<CDPSDialog>::s_instance is 0x143ad0d98).
class CDPSDialog : public CToolBaseDialog, public TSingleton<CDPSDialog>
{
    DECLARE_DYNAMIC(CDPSDialog)
public:
    CDPSDialog(CWnd* pParent = NULL);                       // 0x141178390
    virtual ~CDPSDialog();                                  // 0x141178440 (??_G 0x141178b70)

    virtual void DoDataExchange(CDataExchange* pDX);        // 0x141178600
    virtual BOOL OnInitDialog();                            // 0x1411784d0

    afx_msg void OnWindowPosChanging(WINDOWPOS* lpwndpos);  // 0x1411786a0
    afx_msg void OnEnChangeText();                          // 0x1411786d0
    afx_msg void OnSizing(UINT fwSide, LPRECT pRect);       // 0x1411786e0
    afx_msg void OnBnClickedSave();                         // 0x141178830
    DECLARE_MESSAGE_MAP()

public:
    void Refresh();                                         // 0x141178870
    void OnStop(unsigned nTime);                            // 0x1411789e0

    CRichEditCtrl m_editText;                               // +0x140 DDX 0x4d0
    CButton m_btnSave;                                      // +0x228 DDX 0x406
    CLockCriticalSection m_lock;                            // +0x310
    RECT m_rcClient;                                        // +0x340 (no ctor in the exe)
};
MS2_CHECK_OFFSET(CDPSDialog, m_editText, 0x140);
MS2_CHECK_OFFSET(CDPSDialog, m_btnSave, 0x228);
MS2_CHECK_OFFSET(CDPSDialog, m_lock, 0x310);
MS2_CHECK_OFFSET(CDPSDialog, m_rcClient, 0x340);
MS2_CHECK_SIZE(CDPSDialog, 0x350);
