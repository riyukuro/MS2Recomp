// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). The client's dpsmetersystem.cpp: the DPS tool dialog
// (CDPSDialog), the DPS meter (CDPSMeterSystem) and its record types (dpsmetersystem.h).
// MS2-UNIT: client\ms2\dpsmetersystem.cpp
// MS2-RANGE: 0x141178370-0x14118b420 .text$mn
// MS2-RANGE: 0x1400e7190-0x1400e7300 .text$di
// MS2-RANGE: 0x142cac920-0x142caca70 .text$yd
// CDPSDialog::_GetBaseClass (IMPLEMENT_DYNAMIC) is 0x141178340, which the done ?\depthoffieldmanager.cpp range holds
// as FUN_141178340.
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\dpsmetersystem.cpp"
#include "ms2/placeholder/ms2stdafx.h"
#include <process.h>
#include <shlwapi.h>
#include <stdlib.h>
#include "dpsmetersystem.h"
#include "ms2/placeholder/header_statics_a.h"
#include "ms2/client/ms2/pcbase.h"
#include "ms2/client/ms2/skillrecord.h"
#include "ms2/client/ms2/additionalcli.h"
#include "ms2/commonfiles/additionalactionadditional.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/tptrvalue.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

IMPLEMENT_DYNAMIC(CDPSDialog, CDialog)

// ---- callees outside the unit ----
CDPSMeterSystem* FUN_14109a6f0();                           // TSingleton<CDPSMeterSystem>::GetInstance
CStringTable* FUN_1401a9d70();
unsigned FUN_140869420();                                   // the current time (ms)
CStringA FUN_1401d4330(const wchar_t* pszWide, int nCodePage);   // wide -> multibyte
CString FUN_140390ea0(const wchar_t* psz, int n);           // wide -> multibyte (the text files)
CStringA FUN_14016a600(const wchar_t* psz, int n);          // wide -> multibyte (the csv file)
int FUN_14123c580(PCBase* pPC);                             // the object id
int FUN_141654730(PCBase* pPC);                             // the job code
float FUN_1416628b0(PCBase* pPC, int nKind, int nId);       // a skill stat rate of the player

// The world service (FUN_1403ed2d0) as this unit uses it.
class Unk_DpsSummon
{
public:
    int FUN_141094f40();                                    // the owner's object id
};
class Unk_DpsWorld
{
public:
    PCBase* FUN_141bd0cc0();                                // the own player
    PCBase* FUN_141bd1200(int nId);                         // an actor by object id
    Unk_DpsSummon* FUN_141bd13a0(int nId);                  // a pet / summon by object id
    CStringW FUN_141bd1830(int nId);                        // the name of an object
};
Unk_DpsWorld* FUN_1403ed2d0();

// The skill table (FUN_1401958b0) as this unit uses it.
class Unk_DpsSkillTable
{
public:
    MS2Ptr<SkillLevelData> FUN_1407ee2f0(int nSkillId, unsigned short nLevel);
};
Unk_DpsSkillTable* FUN_1401958b0();

// The buffs of an actor (PCBase::FUN_1416749a0).
class Unk_PCBaseBuffs
{
public:
    MS2Ptr<AdditionalCli> FUN_14096fc80(int nEffectLevel);  // one buff
};

// ---- helpers ----

// @0x1411821c0
static CStringW GetAttributeName(int nAttribute)
{
    switch (nAttribute)
    {
    case 0: return CStringW(L"무속성");
    case 1: return CStringW(L"화염속성");
    case 2: return CStringW(L"빙결속성");
    case 3: return CStringW(L"전격속성");
    case 4: return CStringW(L"신성속성");
    case 5: return CStringW(L"암흑속성");
    case 6: return CStringW(L"독속성");
    case 7: return CStringW(L"물리속성");
    default: return CStringW(L"");
    }
}

// @0x141182380
static CStringW GetGradeName(int nGrade)
{
    switch (nGrade)
    {
    case 0: return CStringW(L"Normal");
    case 1: return CStringW(L"Critical");
    case 2: return CStringW(L"Miss");
    case 3: return CStringW(L"Block");
    case 4: return CStringW(L"Invincible");
    case 5: return CStringW(L"Hp");
    case 6: return CStringW(L"Mp");
    case 7: return CStringW(L"Cp");
    case 8: return CStringW(L"InvincibleReflection");
    default: return CStringW(L"");
    }
}

// The key of a skill level in the per-skill maps ("<id>_<level>").
// @0x141182570
static CStringW MakeSkillKey(unsigned nSkillId, unsigned short nLevel)
{
    CStringW str;
    str.Format(L"%d_%d", nSkillId, nLevel);
    return str;
}

// ---- CDPSDialog ----

// @0x141178390
CDPSDialog::CDPSDialog(CWnd* pParent)
    : CToolBaseDialog(0x91, pParent)
{
}

// @0x141178440
CDPSDialog::~CDPSDialog()
{
}

// @0x1411784d0
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
BOOL CDPSDialog::OnInitDialog()
{
    BOOL bRet = CToolBaseDialog::OnInitDialog();
    if (bRet)
    {
        GetClientRect(&m_rcClient);
        m_editText.MoveWindow(10, 10, m_rcClient.right - m_rcClient.left - 0x28, m_rcClient.bottom - m_rcClient.top - 0x78, 1);
        CRect rcText;
        m_editText.GetRect(&rcText);
        m_btnSave.MoveWindow(10, rcText.bottom + 0x14, rcText.right + 5, 0x32, 1);
    }
    return bRet != 0;
}

// @0x141178600
void CDPSDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Control(pDX, 0x4d0, m_editText);
    DDX_Control(pDX, 0x406, m_btnSave);
}

BEGIN_MESSAGE_MAP(CDPSDialog, CDialog)
    ON_WM_WINDOWPOSCHANGING()
    ON_EN_CHANGE(0x4d0, &CDPSDialog::OnEnChangeText)
    ON_WM_SIZING()
    ON_BN_CLICKED(0x406, &CDPSDialog::OnBnClickedSave)
END_MESSAGE_MAP()

// @0x1411786a0
void CDPSDialog::OnWindowPosChanging(WINDOWPOS* lpwndpos)
{
    CToolBaseDialog::OnWindowPosChanging(lpwndpos);
}

// @0x1411786d0
void CDPSDialog::OnEnChangeText()
{
}

// @0x1411786e0
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
void CDPSDialog::OnSizing(UINT fwSide, LPRECT pRect)
{
    CToolBaseDialog::OnSizing(fwSide, pRect);
    m_editText.MoveWindow(10, 10, pRect->right - pRect->left - 0x28, pRect->bottom - pRect->top - 0x78, 1);
    CRect rcText;
    m_editText.GetRect(&rcText);
    CRect rcButton;
    m_btnSave.GetClientRect(&rcButton);
    m_btnSave.MoveWindow(10, rcText.bottom + 0x14, rcText.right + 5, 0x32, 1);
}

// @0x141178830
void CDPSDialog::OnBnClickedSave()
{
    FUN_14109a6f0()->Flush();
    m_btnSave.EnableWindow(0);
}

// @0x141178870
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
void CDPSDialog::Refresh()
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (FUN_14109a6f0()->IsRecording() == 0)
        {
            CString strText;
            m_editText.GetWindowText(strText);
            if (strText.GetLength() != 0)
                m_btnSave.EnableWindow(1);
        }
        else
        {
            if (m_btnSave.IsWindowVisible())
                m_btnSave.EnableWindow(0);
            CStringW strSummary;
            FUN_14109a6f0()->GetSummary(strSummary);
            m_editText.SetWindowText(FUN_1401d4330(strSummary, 0));
        }
    }
}

// @0x1411789e0
void CDPSDialog::OnStop(unsigned nTime)
{
    if (FUN_14109a6f0()->IsRecording() != 0)
    {
        FUN_14109a6f0()->FUN_14117ea90(nTime, 1);
        CStringW strSummary;
        FUN_14109a6f0()->GetSummary(strSummary);
        m_editText.SetWindowText(FUN_1401d4330(strSummary, 0));
    }
}

// ---- CMeterRecordData::Aggregation ----

// @0x141178c40
CMeterRecordData::Aggregation::Aggregation()
    : m_nTotal(0), m_nNormal(0), m_nCritical(0), m_nDot(0), m_dRate(0), m_nMagic(0), m_nPhysical(0)
    , m_nCount(0), m_nMiss(0), m_nBlock(0), m_nHit(0), m_nKill(0), m_nCriticalCount(0)
{
    memset(m_attributes, 0, sizeof(m_attributes));
}

// @0x141178de0
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
void CMeterRecordData::Aggregation::AddDamage(MS2Ptr<CDamageMeterData> spData)
{
    if (spData->m_nKind == 0)
    {
        m_damages.AddTail(spData);
        TPtrValue<float> spUnused(nullptr);
        if (m_skillRates.find(spData->m_nSkillId) == m_skillRates.end())
            m_skillRates.insert(std::make_pair(spData->m_nSkillId, spData->m_dRate));
        else
            m_skillRates[spData->m_nSkillId] = (float)(m_skillRates[spData->m_nSkillId] + spData->m_dRate);
    }
    else if (spData->m_nKind == 1)
    {
        m_dots.AddTail(spData);
        if (m_dotRates.find(spData->m_nSkillId) == m_dotRates.end())
            m_dotRates.insert(std::make_pair(spData->m_nSkillId, spData->m_dRate));
        else
            m_dotRates[spData->m_nSkillId] = (float)(m_dotRates[spData->m_nSkillId] + spData->m_dRate);
    }
}

// The use count and the per-skill sums of a damage list; one row per skill level.
static void SumSkills(ATL::CAtlList<MS2Ptr<CDamageMeterData> >& list,
    ATL::CAtlMap<CStringW, int, CStringElementTraits<CStringW> >& mapCount,
    ATL::CAtlMap<CStringW, MS2Ptr<CSkillMeterData>, CStringElementTraits<CStringW> >& mapSkill)
{
    for (POSITION pos = list.GetHeadPosition(); pos != NULL; list.GetNext(pos))
    {
        MS2Ptr<CDamageMeterData> spData = list.GetAt(pos);
        if (spData == 0)
            continue;
        CStringW strKey = MakeSkillKey(spData->m_nSkillId, spData->m_nLevel);
        ATL::CAtlMap<CStringW, int, CStringElementTraits<CStringW> >::CPair* pCount = mapCount.Lookup(strKey);
        if (pCount == NULL)
        {
            mapCount.SetAt(strKey, 1);
        }
        else
        {
            int nCount = mapCount.GetValueAt(pCount) + 1;
            mapCount.SetValueAt(pCount, nCount);
        }
        MS2Ptr<CSkillMeterData> spSkill(0);
        if (!mapSkill.Lookup(strKey, spSkill))
        {
            spSkill.AssignRaw(new CSkillMeterData());
            spSkill->m_nSkillId = spData->m_nSkillId;
            spSkill->m_nLevel = spData->m_nLevel;
            spSkill->m_nAttribute = spData->m_nAttribute;
            mapSkill.SetAt(strKey, spSkill);
        }
        spSkill->m_nTotal += spData->m_nDamage;
        if (spData->m_nGrade == 0)
        {
            spSkill->m_nNormal += spData->m_nDamage;
            spSkill->m_nNormalMax = spSkill->m_nNormalMax > spData->m_nDamage ? spSkill->m_nNormalMax : spData->m_nDamage;
        }
        else if (spData->m_nGrade == 1)
        {
            spSkill->m_nCritical += spData->m_nDamage;
            spSkill->m_nCriticalMax = spSkill->m_nCriticalMax > spData->m_nDamage ? spSkill->m_nCriticalMax : spData->m_nDamage;
        }
        else if (spData->m_nGrade == 2)
        {
            spSkill->m_nMiss++;
        }
        if (spData->m_nGrade != -2)
            spSkill->m_nHit++;
    }
}

// @0x1411790a0
// MS2-FUNCTIONAL: written from the decompile (the list loop is shared with GetDotReport through SumSkills)
const CStringW& CMeterRecordData::Aggregation::GetSkillReport()
{
    ATL::CAtlMap<CStringW, int, CStringElementTraits<CStringW> > mapCount;
    ATL::CAtlMap<CStringW, MS2Ptr<CSkillMeterData>, CStringElementTraits<CStringW> > mapSkill;
    SumSkills(m_damages, mapCount, mapSkill);
    static CStringW s_strReport;
    s_strReport.Empty();
    s_strReport.Format(L"아이디, 레벨, 이름, 사용횟수, 전체 대미지, 전체 일반 대미지, 전체 크리티컬 대미지, 일반 최대 대미지, 크리티컬 최대 대미지, 명중 횟수, 미스 횟수, 대미지 속성\r\n");
    for (POSITION pos = mapSkill.GetStartPosition(); pos != NULL; mapSkill.GetNext(pos))
    {
        MS2Ptr<CSkillMeterData> spSkill = mapSkill.GetValueAt(pos);
        if (spSkill == 0)
            continue;
        int nCount = 0;
        ATL::CAtlMap<CStringW, int, CStringElementTraits<CStringW> >::CPair* pCount =
            mapCount.Lookup(MakeSkillKey(spSkill->m_nSkillId, spSkill->m_nLevel));
        if (pCount != NULL)
            nCount = mapCount.GetValueAt(pCount);
        s_strReport.AppendFormat(L"%d, %d, %s, %d, %d, %d, %d, %d, %d, %d, %d, %s\r\n", spSkill->m_nSkillId,
            (unsigned short)spSkill->m_nLevel, (const wchar_t*)FUN_1401a9d70()->FUN_141811980(4, spSkill->m_nSkillId), nCount,
            spSkill->m_nTotal, spSkill->m_nNormal, spSkill->m_nCritical, spSkill->m_nNormalMax, spSkill->m_nCriticalMax,
            spSkill->m_nHit, spSkill->m_nMiss, (const wchar_t*)GetAttributeName(spSkill->m_nAttribute));
    }
    return s_strReport;
}

// @0x141179ac0
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
const CStringW& CMeterRecordData::Aggregation::GetDamageLog()
{
    static CStringW s_strLog;
    s_strLog.Empty();
    s_strLog.Format(L"시간, 공격자, 피해자, 스킬아이디, 스킬레벨, 스킬명, 대미지, 대미지 속성, 대미지 등급, 피해자 사망여부\r\n");
    for (POSITION pos = m_damages.GetHeadPosition(); pos != NULL; m_damages.GetNext(pos))
    {
        MS2Ptr<CDamageMeterData> spData = m_damages.GetAt(pos);
        if (spData == 0)
            continue;
        CStringW strTime;
        strTime.Format(L"%02d:%02d:%02d", spData->m_time.wHour, spData->m_time.wMinute, spData->m_time.wSecond);
        s_strLog.AppendFormat(L"%s, %s, %s, %d, %d, %s, %d, %s, %s, %d\r\n", (const wchar_t*)strTime,
            (const wchar_t*)spData->m_strCaster, (const wchar_t*)spData->m_strTarget, spData->m_nSkillId,
            (unsigned short)spData->m_nLevel, (const wchar_t*)FUN_1401a9d70()->FUN_141811980(4, spData->m_nSkillId),
            spData->m_nDamage, (const wchar_t*)GetAttributeName(spData->m_nAttribute),
            (const wchar_t*)GetGradeName(spData->m_nGrade), spData->m_bKilled);
    }
    return s_strLog;
}

// @0x141179ec0
// MS2-FUNCTIONAL: written from the decompile (the list loop is shared with GetSkillReport through SumSkills)
const CStringW& CMeterRecordData::Aggregation::GetDotReport()
{
    ATL::CAtlMap<CStringW, int, CStringElementTraits<CStringW> > mapCount;
    ATL::CAtlMap<CStringW, MS2Ptr<CSkillMeterData>, CStringElementTraits<CStringW> > mapSkill;
    SumSkills(m_dots, mapCount, mapSkill);
    static CStringW s_strReport;
    s_strReport.Empty();
    s_strReport.Format(L"아이디, 레벨, 이름, 사용횟수, 전체 대미지, 전체 일반 대미지, 전체 크리티컬 대미지, 일반 최대 대미지, 크리티컬 최대 대미지, 명중 횟수, 미스 횟수, 대미지 속성\r\n");
    for (POSITION pos = mapSkill.GetStartPosition(); pos != NULL; mapSkill.GetNext(pos))
    {
        MS2Ptr<CSkillMeterData> spSkill = mapSkill.GetValueAt(pos);
        if (spSkill == 0)
            continue;
        int nCount = 0;
        ATL::CAtlMap<CStringW, int, CStringElementTraits<CStringW> >::CPair* pCount =
            mapCount.Lookup(MakeSkillKey(spSkill->m_nSkillId, spSkill->m_nLevel));
        if (pCount != NULL)
            nCount = mapCount.GetValueAt(pCount);
        s_strReport.AppendFormat(L"%d, %d, %s, %d, %d, %d, %d, %d, %d, %d, %d, %s\r\n", spSkill->m_nSkillId,
            (unsigned short)spSkill->m_nLevel,
            (const wchar_t*)FUN_1401a9d70()->FUN_141812290(spSkill->m_nSkillId, spSkill->m_nLevel, CString("name")), nCount,
            spSkill->m_nTotal, spSkill->m_nNormal, spSkill->m_nCritical, spSkill->m_nNormalMax, spSkill->m_nCriticalMax,
            spSkill->m_nHit, spSkill->m_nMiss, (const wchar_t*)GetAttributeName(spSkill->m_nAttribute));
    }
    return s_strReport;
}

// @0x14117a950
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
const CStringW& CMeterRecordData::Aggregation::GetEffectLog()
{
    static CStringW s_strLog;
    s_strLog.Empty();
    s_strLog.Format(L"시간, 이벤트, 캐스터, 타겟, 이펙트아이디, 이펙트레벨, 이펙트이름\r\n");
    for (POSITION pos = m_effects.GetHeadPosition(); pos != NULL; m_effects.GetNext(pos))
    {
        MS2Ptr<CAdditionalEffectMeterData> spData = m_effects.GetAt(pos);
        if (spData == 0)
            continue;
        CStringW strTime;
        strTime.Format(L"%02d:%02d:%02d", spData->m_time.wHour, spData->m_time.wMinute, spData->m_time.wSecond);
        s_strLog.AppendFormat(L"%s, %s, %s, %s, %d, %d, %s\r\n", (const wchar_t*)strTime, (const wchar_t*)spData->m_strEvent,
            (const wchar_t*)spData->m_strCaster, (const wchar_t*)spData->m_strTarget, spData->m_nEffectId,
            (unsigned short)spData->m_nLevel,
            (const wchar_t*)FUN_1401a9d70()->FUN_141812290(spData->m_nEffectId, spData->m_nLevel, CString("name")));
    }
    return s_strLog;
}

// ---- CDPSMeterSystem ----

// @0x14117acd0
CDPSMeterSystem::CDPSMeterSystem()
    : m_bRunning(0), m_hThread(0), m_hEvent(0), m_nCombatStart(0), m_bCombat(0), m_bFlush(0), m_bRecording(0)
{
    StartThread();
}

// @0x14117adb0
CDPSMeterSystem::~CDPSMeterSystem()
{
    StopThread();
}

// @0x14117ae30
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
void CDPSMeterSystem::StartThread()
{
    if (m_bRunning != 0)
        return;
    m_bRunning = 1;
    unsigned nThreadId;
    m_hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadEntry, this, 0, &nThreadId);
    m_hEvent = CreateEventA(NULL, 0, 0, NULL);
    if (m_hEvent == 0 || m_hThread == 0)
    {
        m_bRunning = 0;
        TerminateThread(m_hThread, 0);
        CloseHandle(m_hThread);
        m_hThread = INVALID_HANDLE_VALUE;
        m_hEvent = INVALID_HANDLE_VALUE;
    }
    memset(m_szDir, 0, sizeof(m_szDir));
    const wchar_t* pszSub = L"log\\DPS";
    wchar_t szDrive[256];
    memset(szDrive, 0, sizeof(szDrive));
    wchar_t szDir[256];
    memset(szDir, 0, sizeof(szDir));
    wchar_t szPath[MAX_PATH];
    memset(szPath, 0, sizeof(szPath));
    GetModuleFileNameW(NULL, szPath, MAX_PATH);
    _wsplitpath(szPath, szDrive, szDir, NULL, NULL);
    wcscat(m_szDir, szDrive);
    wcscat(m_szDir, szDir);
    wcscat(m_szDir, pszSub);
    if (!PathIsDirectoryW(m_szDir))
        CreateDirectoryW(m_szDir, NULL);
}

// @0x14117b080
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
void CDPSMeterSystem::StopThread()
{
    if (m_hThread == 0)
        return;
    m_bRunning = 0;
    SetEvent(m_hEvent);
    DWORD dwResult = WaitForSingleObject(m_hThread, INFINITE);
    if (dwResult == WAIT_ABANDONED || dwResult == WAIT_TIMEOUT)
        TerminateThread(m_hThread, 0);
    CloseHandle(m_hThread);
    m_hThread = INVALID_HANDLE_VALUE;
}

// @0x14117b120
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
unsigned __stdcall CDPSMeterSystem::ThreadEntry(void* ptr)
{
    MS2_ASSERT_AT(0x1ac, NULL != ptr);
    static_cast<CDPSMeterSystem*>(ptr)->ThreadProc();
    return 0;
}

// Writes one text of a finished record to <dir>\<name><suffix>.
static void WriteRecordFile(wchar_t* szFile, const wchar_t* szDir, const wchar_t* pszName, const CStringW& strSuffix,
    const CStringA& strText)
{
    wcscat(szFile, szDir);
    wcscat(szFile, pszName);
    wcscat(szFile, strSuffix);
    CFile file;
    if (file.Open(FUN_1401d4330(szFile, 0), 0x5022, NULL))
    {
        file.Write(strText, strText.GetLength());
        file.Close();
    }
    memset(szFile, 0, sizeof(wchar_t) * MAX_PATH);
}

const CStringW& FUN_141181540();                            // the character info text (not written yet)

// @0x14117b170
// MS2-FUNCTIONAL: written from the decompile (the ten file writes share WriteRecordFile)
unsigned CDPSMeterSystem::ThreadProc()
{
    while (m_bRunning)
    {
        WaitForSingleObject(m_hEvent, INFINITE);
        if (IsRecording() != 0 || m_bFlush == 0)
            continue;
        if (Unk_LockGuard guard = m_lock)
        {
        }
        else
        {
            MS2Ptr<CMeterRecordData> spRecord = m_spRecord;
            if (spRecord == 0)
            {
                if (m_records.GetCount() == 0)
                    continue;
                spRecord = m_records.GetTail();
                if (spRecord == 0)
                    continue;
            }
            CStringW strName;
            PCBase* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
            if (pMe != 0)
            {
                int nJob = FUN_141654730(pMe);
                strName.Format(L"_%s_%s", (const wchar_t*)pMe->vfunc_77(), (const wchar_t*)FUN_1401a9d70()->FUN_141811980(6, nJob));
            }
            if (!PathIsDirectoryW(m_szDir))
                CreateDirectoryW(m_szDir, NULL);
            SYSTEMTIME st;
            GetLocalTime(&st);
            CStringW strTime;
            strTime.Format(L"\\%04d%02d%02d_%02d%02d%02d%03d", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond,
                st.wMilliseconds);
            wchar_t szDir[MAX_PATH];
            memset(szDir, 0, sizeof(szDir));
            wcscat(szDir, m_szDir);
            wcscat(szDir, strTime);
            wcscat(szDir, strName);
            if (!PathIsDirectoryW(szDir))
                CreateDirectoryW(szDir, NULL);
            CStringW strCsv(strName);
            strCsv.Append(L".csv");
            strName.Append(L".txt");
            wchar_t szFile[MAX_PATH];
            memset(szFile, 0, sizeof(szFile));
            WriteRecordFile(szFile, szDir, L"\\0_캐릭터정보", strName, FUN_140390ea0(FUN_141181540(), 0));
            WriteRecordFile(szFile, szDir, L"\\1_DPS_기본정보", strName, FUN_140390ea0(spRecord->m_strSummary, 0));
            WriteRecordFile(szFile, szDir, L"\\2_타격_스킬_상세정보", strName, FUN_140390ea0(spRecord->m_attack.GetSkillReport(), 0));
            WriteRecordFile(szFile, szDir, L"\\3_타격_스킬_대미지_상세정보", strName, FUN_140390ea0(spRecord->m_attack.GetDamageLog(), 0));
            WriteRecordFile(szFile, szDir, L"\\4_피격_스킬_상세정보", strName, FUN_140390ea0(spRecord->m_defense.GetSkillReport(), 0));
            WriteRecordFile(szFile, szDir, L"\\5_피격_스킬_대미지_상세정보", strName, FUN_140390ea0(spRecord->m_defense.GetDamageLog(), 0));
            WriteRecordFile(szFile, szDir, L"\\6_타격_Dot_상세정보", strName, FUN_140390ea0(spRecord->m_attack.GetDotReport(), 0));
            WriteRecordFile(szFile, szDir, L"\\7_피격_Dot_상세정보", strName, FUN_140390ea0(spRecord->m_defense.GetDotReport(), 0));
            WriteRecordFile(szFile, szDir, L"\\8_플레이어_상세정보", strCsv, FUN_14016a600(spRecord->m_strCsv, 0));
            WriteRecordFile(szFile, szDir, L"\\9_AdditionalEffect_캐스터로그", strName, FUN_140390ea0(spRecord->m_attack.GetEffectLog(), 0));
            WriteRecordFile(szFile, szDir, L"\\10_AdditionalEffect_타겟로그", strName, FUN_140390ea0(spRecord->m_defense.GetEffectLog(), 0));
            m_bFlush = 0;
            MessageBoxW(NULL, szDir, L"Complete!", 0);
        }
    }
    return 0;
}

// @0x14117c650
int CDPSMeterSystem::StartRecord(unsigned nTime)
{
    if (IsRecording() != 0)
        return 0;
    PCBase* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return 0;
    m_bCombat = pMe->vfunc_65();
    SetCombat(m_bCombat);
    if (m_bCombat != 0)
        m_nCombatStart = nTime;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        MS2Ptr<CMeterRecordData> spRecord(new CMeterRecordData());
        spRecord->m_nStartTime = nTime;
        m_spRecord = spRecord;
        m_bRecording = 1;
    }
    return m_bRecording;
}

// @0x14117c7c0
int CDPSMeterSystem::StopRecord(unsigned nTime)
{
    if (IsRecording() == 0)
        return 0;
    SetCombat(0);
    m_bCombat = 0;
    m_nCombatStart = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_spRecord->m_nEndTime = nTime;
        m_records.AddTail(m_spRecord);
        m_spRecord = 0;
        m_bRecording = 0;
    }
    return m_bRecording;
}

// @0x14117c8b0
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
int CDPSMeterSystem::IsRecording()
{
    return (m_bRecording != 0 && m_spRecord.get() != 0) ? 1 : 0;
}

// @0x14117c920
int CDPSMeterSystem::Reset()
{
    if (IsRecording() != 0)
        return 0;
    m_spRecord = 0;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_records.RemoveAll();
    }
    return 1;
}

// @0x14117c9b0
void CDPSMeterSystem::Flush()
{
    if (IsRecording() != 0)
        return;
    m_bFlush = 1;
    SetEvent(m_hEvent);
}

// @0x14117c9f0
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
void CDPSMeterSystem::Accumulate(CMeterRecordData::Aggregation* pAgg, MS2Ptr<CDamageMeterData> spData)
{
    pAgg->m_nCount++;
    switch (spData->m_nGrade)
    {
    case 0:
        pAgg->m_nHit++;
        pAgg->m_nTotal += spData->m_nDamage;
        pAgg->m_nNormal += spData->m_nDamage;
        break;
    case 1:
        pAgg->m_nCriticalCount++;
        pAgg->m_nHit++;
        pAgg->m_nTotal += spData->m_nDamage;
        pAgg->m_nCritical += spData->m_nDamage;
        break;
    case 2:
        pAgg->m_nMiss++;
        break;
    case 3:
        pAgg->m_nBlock++;
        break;
    }
    if (spData->m_bKilled != 0)
        pAgg->m_nKill++;
    pAgg->m_attributes[spData->m_nAttribute] += spData->m_nDamage;
    if ((unsigned)spData->m_nAttribute < 6)
        pAgg->m_nMagic += spData->m_nDamage;
    else if ((unsigned)spData->m_nAttribute < 8)
        pAgg->m_nPhysical += spData->m_nDamage;
    if (spData->m_nKind == 1)
        pAgg->m_nDot += spData->m_nDamage;
}

// @0x14117ccc0
int CDPSMeterSystem::AddDamage(int nSide, int nCasterId, int nTargetId, int nKind, int nAttribute, __int64 nTagId,
    int nSkillId, short nLevel, int nGrade, __int64 nDamage, float fRate)
{
    if (IsRecording() == 0)
        return 0;
    MS2Ptr<CDamageMeterData> spData(new CDamageMeterData());
    spData->m_nTagId = nTagId;
    spData->m_nSkillId = nSkillId;
    spData->m_nLevel = nLevel;
    spData->m_nCasterId = nCasterId;
    spData->m_nTargetId = nTargetId;
    spData->m_strCaster = FUN_1403ed2d0()->FUN_141bd1830(nCasterId);
    spData->m_strTarget = FUN_1403ed2d0()->FUN_141bd1830(nTargetId);
    spData->m_nKind = nKind;
    spData->m_nAttribute = nAttribute;
    spData->m_nGrade = nGrade;
    spData->m_nDamage = nDamage;
    spData->m_dRate = fRate;
    PCBase* pTarget = FUN_1403ed2d0()->FUN_141bd1200(nTargetId);
    if (pTarget != 0 && pTarget->FUN_14166ce30() != 0)
        spData->m_bKilled = 1;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        CMeterRecordData::Aggregation* pAgg = 0;
        if (nSide == 0)
            pAgg = &m_spRecord->m_attack;
        else if (nSide == 1)
            pAgg = &m_spRecord->m_defense;
        if (pAgg == 0)
            return 0;
        pAgg->AddDamage(spData);
        Accumulate(pAgg, spData);
    }
    return 1;
}

// @0x14117d090
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
int CDPSMeterSystem::AddStat(int nSide, int nList, __int64 nValue, __int64 nEffective, __int64 nOver, int nType)
{
    if (IsRecording() == 0)
        return 0;
    MS2Ptr<CStatMeterData> spStat(new CStatMeterData());
    spStat->m_nValue = nValue;
    spStat->m_nEffective = nEffective;
    spStat->m_nOver = nOver;
    spStat->m_nType = nType;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        CMeterRecordData::Aggregation* pAgg = 0;
        if (nSide == 0)
            pAgg = &m_spRecord->m_attack;
        else if (nSide == 1)
            pAgg = &m_spRecord->m_defense;
        if (nList == 0)
        {
            pAgg->m_heals.AddTail(spStat);
            if (nSide == 0)
            {
                if (nType == 0)
                {
                    m_spRecord->m_nSkillSp += nEffective;
                    m_spRecord->m_nHealed += nValue;
                }
                else
                {
                    m_spRecord->m_nNaturalSp += nEffective;
                    m_spRecord->m_nNaturalEp += nOver;
                }
            }
            else if (nSide == 1 && nType == 0)
            {
                m_spRecord->m_nHeal += nValue;
            }
        }
        else if (nList == 1)
        {
            pAgg->m_spirits.AddTail(spStat);
            m_spRecord->m_nSpentSp += nEffective;
            m_spRecord->m_nSpentEp += nOver;
        }
    }
    return 1;
}

// @0x14117d460
int CDPSMeterSystem::AddEffect(CStringW strEvent, int nSide, int nCasterId, int nTargetId, int nEffectId, short nLevel)
{
    if (IsRecording() == 0)
        return 0;
    MS2Ptr<CAdditionalEffectMeterData> spData(new CAdditionalEffectMeterData());
    spData->m_strEvent = strEvent;
    spData->m_nEffectId = nEffectId;
    spData->m_nLevel = nLevel;
    spData->m_nCasterId = nCasterId;
    spData->m_nTargetId = nTargetId;
    spData->m_strCaster = FUN_1403ed2d0()->FUN_141bd1830(nCasterId);
    spData->m_strTarget = FUN_1403ed2d0()->FUN_141bd1830(nTargetId);
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        CMeterRecordData::Aggregation* pAgg = 0;
        if (nSide == 0)
            pAgg = &m_spRecord->m_attack;
        else if (nSide == 1)
            pAgg = &m_spRecord->m_defense;
        if (pAgg == 0)
            return 0;
        pAgg->m_effects.AddTail(spData);
    }
    return 1;
}

// @0x14117d750
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
void CDPSMeterSystem::OnDamage(MS2Ptr<CDamageRecord> spRecord)
{
    if (IsRecording() == 0 || spRecord.IsNull())
        return;
    PCBase* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    int nAttackerId = spRecord->m_nOwnerId;
    Unk_DpsSummon* pSummon = FUN_1403ed2d0()->FUN_141bd13a0(nAttackerId);
    if (pSummon != 0)
        nAttackerId = pSummon->FUN_141094f40();
    if (spRecord->m_nCasterId != FUN_14123c580(pMe) && nAttackerId != FUN_14123c580(pMe))
        return;
    bool bTarget = spRecord->m_nCasterId == FUN_14123c580(pMe);
    float fRate = 0.0f;
    if (!bTarget)
    {
        MS2Ptr<SkillLevelData> spLevel = FUN_1401958b0()->FUN_1407ee2f0(spRecord->m_nSkillId, spRecord->m_nLevel);
        if (spLevel.get() != 0)
        {
            fRate = spLevel->FUN_140804150(spRecord->m_nMotion, spRecord->m_nAttack);
            fRate = fRate + fRate * FUN_1416628b0(pMe, 0x3ec, spRecord->m_nSkillId);
            m_spRecord->m_attack.m_dRate += fRate;
        }
    }
    unsigned nCount = (unsigned)spRecord->m_damages.GetCount();
    for (unsigned i = 0; i < nCount; i++)
    {
        __int64 nDamage = abs(spRecord->m_damages[i]);
        AddDamage(bTarget, nAttackerId, spRecord->m_nCasterId, 0, spRecord->m_spSkill->GetElement(), spRecord->m_nTagId,
            spRecord->m_nSkillId, spRecord->m_nLevel, spRecord->m_types[i], nDamage, fRate);
    }
}

// @0x14117dbe0
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
void CDPSMeterSystem::OnDotDamage(MS2Ptr<CDotDamageRecord> spRecord)
{
    if (IsRecording() == 0 || spRecord.IsNull())
        return;
    PCBase* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    int nAttackerId = spRecord->m_nOwnerId;
    Unk_DpsSummon* pSummon = FUN_1403ed2d0()->FUN_141bd13a0(nAttackerId);
    if (pSummon != 0)
        nAttackerId = pSummon->FUN_141094f40();
    if (spRecord->m_nCasterId != FUN_14123c580(pMe) && nAttackerId != FUN_14123c580(pMe))
        return;
    bool bTarget = spRecord->m_nCasterId == FUN_14123c580(pMe);
    MS2Ptr<AdditionalCli> spBuff;
    PCBase* pCaster = FUN_1403ed2d0()->FUN_141bd1200(spRecord->m_nCasterId);
    if (pCaster != 0)
        spBuff = pCaster->FUN_1416749a0()->FUN_14096fc80(spRecord->m_nEffectLevel);
    if (spBuff.IsNull())
        return;
    float fRate = 0.0f;
    if (!bTarget)
    {
        fRate = spBuff->FUN_14096d810()->m_dotDamage.m_fRate;
        fRate = fRate + fRate * FUN_1416628b0(pMe, 5, spBuff->FUN_14096d2a0());
        m_spRecord->m_attack.m_dRate += fRate;
    }
    __int64 nDamage = abs(spRecord->FUN_14175ac30());
    int nGrade = spRecord->FUN_14175b130();
    unsigned short nLevel = spBuff->FUN_14096d810()->GetLevel();
    unsigned nEffectId = spBuff->FUN_14096d810()->GetID();
    AddDamage(bTarget, nAttackerId, spRecord->m_nCasterId, 1, spBuff->FUN_14096d810()->m_dotDamage.m_eElement,
        (unsigned)spRecord->m_nEffectLevel, nEffectId, nLevel, nGrade, nDamage, fRate);
}

// @0x14117e030
// MS2-FUNCTIONAL: not byte-exact yet (partial unit; frame/temporary layout and branch shape differ)
void CDPSMeterSystem::OnSplashDamage(MS2Ptr<CSplashDamageRecord> spRecord)
{
    if (IsRecording() == 0 || spRecord.IsNull())
        return;
    PCBase* pMe = FUN_1403ed2d0()->FUN_141bd0cc0();
    if (pMe == 0)
        return;
    int nAttackerId = spRecord->m_nOwnerId;
    Unk_DpsSummon* pSummon = FUN_1403ed2d0()->FUN_141bd13a0(nAttackerId);
    if (pSummon != 0)
        nAttackerId = pSummon->FUN_141094f40();
    if (spRecord->m_nCasterId != FUN_14123c580(pMe) && nAttackerId != FUN_14123c580(pMe))
        return;
    bool bTarget = spRecord->m_nCasterId == FUN_14123c580(pMe);
    float fRate = 0.0f;
    if (!bTarget)
    {
        MS2Ptr<SkillLevelData> spLevel = FUN_1401958b0()->FUN_1407ee2f0(spRecord->m_nSkillId, spRecord->m_nLevel);
        if (spLevel.get() != 0)
        {
            fRate = spLevel->FUN_140804150(spRecord->m_nMotion, spRecord->m_nAttack);
            fRate = fRate + fRate * FUN_1416628b0(pMe, 0x3ec, spRecord->m_nSkillId);
            m_spRecord->m_attack.m_dRate += fRate;
        }
    }
    unsigned nCount = (unsigned)spRecord->m_damages.GetCount();
    for (unsigned i = 0; i < nCount; i++)
    {
        __int64 nDamage = abs(spRecord->m_damages[i]);
        AddDamage(bTarget, nAttackerId, spRecord->m_nCasterId, 0, spRecord->m_spSkill->GetElement(), spRecord->m_nTagId,
            spRecord->m_nSkillId, spRecord->m_nLevel, spRecord->m_types[i], nDamage, fRate);
    }
}

// @0x14117e4c0
void CDPSMeterSystem::AddMeso(__int64 nMeso)
{
    if (IsRecording() == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_spRecord->m_nMeso += nMeso;
    }
}

// @0x14117e560
void CDPSMeterSystem::AddExp(__int64 nExp)
{
    if (IsRecording() == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_spRecord->m_nExp += nExp;
    }
}

// @0x14117e600
void CDPSMeterSystem::AddSkillUse()
{
    if (IsRecording() == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_spRecord->m_nSkillUse++;
    }
}

// @0x14117e690
void CDPSMeterSystem::AddHealTarget()
{
    if (IsRecording() == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_spRecord->m_nHealTargets++;
    }
}

// @0x14117e720
void CDPSMeterSystem::AddHealedEffective(__int64 nValue)
{
    if (IsRecording() == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_spRecord->m_nHealedEffective += nValue;
    }
}

// @0x14117e7c0
void CDPSMeterSystem::AddHealEffective(__int64 nValue)
{
    if (IsRecording() == 0)
        return;
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        m_spRecord->m_nHealEffective += nValue;
    }
}

// @0x14117e860
void CDPSMeterSystem::SetCombat(int bCombat)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        if (IsRecording() == 0)
            return;
        if (bCombat == m_bCombat)
            return;
        if (bCombat != 0)
        {
            m_nCombatStart = FUN_140869420();
        }
        else
        {
            unsigned nNow = FUN_140869420();
            unsigned nElapsed = nNow - m_nCombatStart;
            m_spRecord->m_nCombatTime += nElapsed;
        }
        m_bCombat = bCombat;
    }
}

// @0x14117e960
void CDPSMeterSystem::GetSummary(CStringW& str)
{
    if (Unk_LockGuard guard = m_lock)
    {
    }
    else
    {
        MS2Ptr<CMeterRecordData> spRecord = m_spRecord;
        if (spRecord == 0)
        {
            if (m_records.GetCount() == 0)
                return;
            spRecord = m_records.GetTail();
            if (spRecord == 0)
                return;
        }
        str = spRecord->m_strSummary;
    }
}

// ---- the record types ----

// @0x141185390
CAdditionalEffectMeterData::CAdditionalEffectMeterData()
    : m_nEffectId(0), m_nLevel(0), m_nCasterId(0), m_nTargetId(0)
{
    GetLocalTime(&m_time);
}

// @0x141185440
CDamageMeterData::CDamageMeterData()
    : m_nTagId(0), m_nSkillId(0), m_nLevel(0), m_nCasterId(0), m_nTargetId(0), m_nKind(0), m_nAttribute(0), m_nGrade(0)
    , m_nDamage(0), m_dRate(0), m_bKilled(0)
{
    GetLocalTime(&m_time);
}

// @0x141185530
CMeterRecordData::CMeterRecordData()
    : m_nStartTime(0), m_nEndTime(0), m_nCombatTime(0), m_nExp(0), m_nMeso(0), m_nNaturalSp(0), m_nNaturalEp(0)
    , m_nSkillSp(0), m_nHealed(0), m_nHealedEffective(0), m_nSpentSp(0), m_nSpentEp(0), m_nHealTargets(0), m_nHeal(0)
    , m_nHealEffective(0), m_nSkillUse(0)
{
}

// @0x141185870
CSkillMeterData::CSkillMeterData()
    : m_nSkillId(0), m_nLevel(0), m_nTotal(0), m_nNormal(0), m_nCritical(0), m_nHit(0), m_nMiss(0), m_nAttribute(0)
    , m_nNormalMax(0), m_nCriticalMax(0)
{
}

// @0x141185920
CStatMeterData::CStatMeterData()
    : m_nTime(FUN_140869420()), m_nValue(0), m_nEffective(0), m_nOver(0), m_nType(0)
{
}
