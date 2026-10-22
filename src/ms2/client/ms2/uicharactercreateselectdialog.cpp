// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UICharacterCreateSelectDialog: see
// uicharactercreateselectdialog.h.
// MS2-UNIT: ?\uicharactercreateselectdialog.cpp
// MS2-RANGE: 0x1400de990-0x1400dea20 .text$di
// MS2-RANGE: 0x140f2e4d0-0x140f32290 .text$mn
// MS2-PIN: ??1TJobData@UICharacterCreateSelectDialog@@UEAA@XZ 0x140f30930
//
// File name assumed (the class name; the exe has no assert path for it).
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uicharactercreateselectdialog.cpp"    // assumed

#include "ms2/placeholder/ms2stdafx.h"

#include "uicharactercreateselectdialog.h"

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cmypckeyinputcontroller.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/xmlattr.h"
#include "ms2/commonfiles/featuremanager.h"
#include "ms2/commonfiles/jobtable.h"
#include "ms2/client/ms2/effectservice.h"
#include "ms2/client/ms2/scenestatemulti.h"
#include "ms2/client/ms2/soundeventmgr.h"
#include "ms2/client/ms2/statemanager.h"
#include "ms2/client/ms2/uimessageboxdata.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

typedef UICharacterCreateSelectDialog::TJobData Unk_CsJobData;

static CString s_skill("skill");
static CString s_stun("stun");
static UICommon::CMyPCKeyInputController s_keyInput;

// ---- unit-local views of unrecovered callees ------------------------------------------------------------------------

// The TinyXML document loader of the file system singleton (as in datatable_impl.h).
class Unk_CsLoader { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int a, bool b, bool c); };
Unk_CsLoader* FUN_140166420();
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);   // Table/<file>
bool FUN_14028f710(Unk_140165cf0* pElem);                               // the row is for this client's region
int FUN_140873ad0(Unk_140165cf0* pElem, const char* pszName, CString& strOut);
int FUN_140873b30(Unk_140165cf0* pElem, const char* pszName, CStringW& strOut);
CFeatureManager* FUN_140166410();                                       // the content switches
bool FUN_14025cd60(const CStringW& a, const CStringW& b);               // equal
int FUN_1406516b0();                                                    // current language id
unsigned FUN_140768010(unsigned nCount, unsigned nBase);                // random index
bool FUN_141900c80(int nButton, const CMsgBoxData& box);
CStringTable* FUN_1401a9d70();
CSoundEventMgr* FUN_140d13c40();
CEffectService* FUN_1403ed280();
extern NiPoint3 DAT_143b01a60;                                          // the zero point
MS2Ptr<CMsgBoxData> FUN_140d74500(CStringW text, int nType, Delegate<bool(int, const CMsgBoxData&)> cb);
void FUN_140d73c60(MS2Ptr<CMsgBoxData> box);
WorldService* FUN_1403ed2d0();
CStateService* FUN_140aa6d30();

// The hud object the character picker tells about the job (slot 14).
class Unk_CsHud
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11();
    virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(int nJobCode);
};
Unk_CsHud* FUN_140a94350();
unsigned char FUN_1401d1320(CCacheData* p);                             // file changed since load
inline CSceneStateMulti* FUN_140f30370();

// Is the value in the array.
template <class C> bool Contains(C& arr, int nValue)
{
    for (size_t i = 0; i < arr.GetCount(); ++i)
    {
        if (arr.GetAt(i) == nValue)
            return true;
    }
    return false;
}

// @0x140f2e4d0
UICharacterCreateSelectDialog::UICharacterCreateSelectDialog()
{
    m_nSelectJob = 0;
    m_nPopupJob = 1;
    m_nPopupMsg = 0;
    m_nBgm = 0;
    m_7c = 1;
    m_80 = 0;
    FUN_141924170(0);
    LoadCharacterCreateSelect();
}

// @0x140f2e5d0
UICharacterCreateSelectDialog::~UICharacterCreateSelectDialog()
{
}

// @0x140f2e650
CString UICharacterCreateSelectDialog::GetTypeName()
{
    return "CharacterCreateSelectDialog";
}
MS2_REPLACE_METHOD(0x140F2E650, UICharacterCreateSelectDialog, GetTypeName, 61, 0x23041F47);

// @0x140f2e6a0
void UICharacterCreateSelectDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    if (m_30.get() != 0)
    {
        ASObj root(2);
        ASArray tabs(2);
        ASObj selected(2);
        int nCount = m_jobs.GetCount();
        int nSelect = FUN_140f30150();
        int nSelectedTab = 0;
        for (int i = 0; i < nCount; ++i)
        {
            JobPtr spJob(m_jobs.GetAt(i));
            if (spJob.IsNull())
                return;
            if (nSelect == spJob.operator->()->m_nJobCode)
            {
                nSelectedTab = i;
                spJob.operator->()->FUN_140f2ee10(&selected);
                FUN_140f2ffb0(spJob.operator->()->m_nJobCode);
            }
            ASObj row(2);
            row.FUN_1407cbb20("name", spJob.operator->()->m_strName);
            row.FUN_1407cb9c0("jobCode", spJob.operator->()->m_nJobCode);
            row.FUN_1407cbbe0("enabled", spJob.operator->()->m_bEnabled);
            row.FUN_1407cbbe0("event", spJob.operator->()->m_bEvent);
            tabs.FUN_1422bc050(row.FUN_1422bb870());
        }
        root.FUN_1409adbe0("arrTab", tabs.FUN_1422bb870());
        root.FUN_1407cb9c0("selectedTabIndex", nSelectedTab);
        root.FUN_1409adbe0("selectedJobData", selected.FUN_1422bb870());
        m_30.operator->()->Invoke("initData", root.FUN_1422bb870());
    }
}
MS2_REPLACE_METHOD(0x140F2E6A0, UICharacterCreateSelectDialog, OnLoadComplete, 1036, 0xDFE5DF2A);

// @0x140f2eac0
int UICharacterCreateSelectDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    if (UIDialog::vfunc_28(szMethod, pArgs, nArgs) != 0)
        return 1;
    if (_stricmp("onChangeTab", szMethod) == 0)
    {
        ASData data;
        if (data.FUN_1422b9620(pArgs, nArgs) != 0)
        {
            int nIndex = data.FUN_1422b8b10();
            int nJobCode = data.FUN_1422b8a10();
            FUN_140f2fba0(nIndex, nJobCode);
        }
        return 1;
    }
    else
    {
        if (_stricmp("onClickCreate", szMethod) == 0)
        {
            ASData data;
            if (data.FUN_1422b9620(pArgs, nArgs) != 0)
            {
                int nJobCode = data.FUN_1422b8a10();
                FUN_140f2fa00(nJobCode);
            }
            return 1;
        }
        else
        {
            if (_stricmp("onClickPrev", szMethod) == 0)
            {
                FUN_140f2fd50();
                FUN_140f30110();
                return 1;
            }
            else
            {
                if (_stricmp("OnEndPopdown", szMethod) == 0)
                {
                    OnEndPopdown();
                    return 1;
                }
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x140F2EAC0, UICharacterCreateSelectDialog, vfunc_28, 472, 0xB3F4D9C4);

// @0x140f2ecb0
int UICharacterCreateSelectDialog::vfunc_65()
{
    if (m_spCache.get() ? true : false)
    {
        if (FUN_1401d1320(m_spCache.operator->()) != 0)
            LoadCharacterCreateSelect();
    }
    return UIDialog::vfunc_65();
}

// @0x140f2ed30
void UICharacterCreateSelectDialog::vfunc_67()
{
    UIDialog::vfunc_67();
    m_nPopupJob = 1;
    m_nPopupMsg = 0;
    m_nBgm = 0;
}
MS2_REPLACE_METHOD(0x140F2ED30, UICharacterCreateSelectDialog, vfunc_67, 69, 0x01BACEAE);

// @0x140f2ed80
void UICharacterCreateSelectDialog::vfunc_69()
{
    if (vfunc_71() == 0)
    {
        FUN_140f2fd50();
        FUN_140f30110();
    }
}
MS2_REPLACE_METHOD(0x140F2ED80, UICharacterCreateSelectDialog, vfunc_69, 57, 0xCF6734CB);

// @0x140f2edc0
void UICharacterCreateSelectDialog::vfunc_40()
{
    m_jobs.RemoveAll();
    m_randomJobs.RemoveAll();
    LoadCharacterCreateSelect();
}

// @0x140f2ee10
void UICharacterCreateSelectDialog::TJobData::FUN_140f2ee10(ASObj* pObj)
{
    pObj->FUN_1407cbb20("name", m_strName);
    pObj->FUN_1407cbb20("desc", m_strDesc);
    pObj->FUN_1407cba60("movie", m_strMovie);
    pObj->FUN_1407cb9c0("jobCode", m_nJobCode);
}
MS2_REPLACE_METHOD(0x140F2EE10, Unk_CsJobData, FUN_140f2ee10, 249, 0xD9C56FCA);

// MS2-FUNCTIONAL: LoadTable: locals / branch layout of the long XML walk differ from the exe
// @0x140f2ef10
void UICharacterCreateSelectDialog::LoadCharacterCreateSelect()
{
    CString strPath = FUN_14071a5b0("Table", "characterCreateSelect.xml");
    if (m_spCache == 0)
    {
        m_spCache.AssignRaw(new CCacheData);
        if (m_spCache.get() != 0)
            m_spCache.operator->()->FUN_1401d1160(CString(strPath));
    }
    TiXmlDocument doc;
    if (FUN_140166420()->FUN_1403974b0(&doc, (const char*)strPath, 0, true, false) == 0)
        return;
    Unk_140165cf0* pRoot = reinterpret_cast<Unk_140165cf0*>(&doc)->FUN_140165cf0("ms2");
    if (pRoot == 0)
        return;
    m_nSelectJob = 0;
    m_jobs.RemoveAll();
    m_randomJobs.RemoveAll();
    JobMap mapJobs(17, 0.75f, 0.25f, 2.25f, 10);
    Unk_140165cf0* pDisplay = 0;
    Unk_140165cf0* pDisplayAny = 0;
    Unk_140165cf0* pData = 0;
    Unk_140165cf0* pSelected = 0;
    for (Unk_140165cf0* pGroup = pRoot->FUN_140165cf0("group"); pGroup != 0; pGroup = pGroup->FUN_140168650("group"))
    {
        CString strType("");
        FUN_140873ad0(pGroup, "name", strType);
        if (strType.CompareNoCase("data") == 0)
        {
            pData = pGroup->FUN_140165cf0("list");
        }
        else
        {
            if (strType.CompareNoCase("display") == 0)
            {
                CStringW strLocale;
                FUN_140873b30(pGroup, "locale", strLocale);
                if (FUN_140166410()->FUN_14036d750(strLocale))
                {
                    if (strLocale.IsEmpty())
                        pDisplayAny = pGroup;
                    else
                        pDisplay = pGroup;
                }
            }
        }
    }
    if (pDisplay == 0)
        pDisplay = pDisplayAny;
    if (pDisplay != 0)
    {
        CStringW strBest;
        for (Unk_140165cf0* pRow = pDisplay->FUN_140165cf0("list"); pRow != 0; pRow = pRow->FUN_140168650("list"))
        {
            CStringW strFeature;
            FUN_140873420(pRow, "feature", strFeature);
            if (FUN_140166410()->FUN_14036d4b0(strFeature))
            {
                if (FUN_14025cd60(FUN_140166410()->FUN_14036de20(strBest, strFeature), strFeature))
                {
                    pSelected = pRow;
                    strBest = strFeature;
                }
            }
        }
    }
    if (pData != 0)
    {
        for (Unk_140165cf0* pRow = pData; pRow != 0; pRow = pRow->FUN_140168650("list"))
        {
            if (FUN_14028f710(pRow))
            {
                int nJobCode = 0;
                FUN_1408731e0(pRow, "jobCode", nJobCode);
                if (nJobCode != 0)
                {
                    JobPtr spJob(new TJobData);
                    if (spJob == 0)
                    {
                    }
                    else
                    {
                        spJob.operator->()->m_nJobCode = nJobCode;
                        spJob.operator->()->m_strName = FUN_1401a9d70()->FUN_141811980(
                            6, JobTable::GetInstance()->GetSubJob1(nJobCode));
                        FUN_140873ad0(pRow, "movie", spJob.operator->()->m_strMovie);
                        int nDescKey = 0;
                        FUN_1408731e0(pRow, "descKey", nDescKey);
                        if (nDescKey != 0)
                            spJob.operator->()->m_strDesc = FUN_1401a9d70()->FUN_141811980(0x1c, nDescKey);
                        mapJobs.SetAt(nJobCode, spJob);
                    }
                }
            }
        }
    }
    if (pSelected != 0)
    {
        ATL::CAtlArray<int> arrOrder;
        XmlTokenList(pSelected, "order", arrOrder);
        ATL::CAtlArray<int> arrDisable;
        XmlTokenList(pSelected, "disableJobCode", arrDisable);
        int nSelectJob;
        FUN_1408731e0(pSelected, "selectJobCode", nSelectJob);
        CStringA strRandom;
        FUN_1408733e0(pSelected, "randomselectJobCode", strRandom);
        XmlSplit(strRandom, m_randomJobs, ",");
        ATL::CAtlArray<int> arrEvent;
        XmlTokenList(pSelected, "eventJobCode", arrEvent);
        for (size_t i = 0; i < arrOrder.GetCount(); ++i)
        {
            int nJobCode = arrOrder.GetAt(i);
            JobPtr spJob(0);
            if (!mapJobs.Lookup(nJobCode, spJob))
            {
            }
            else
            {
                if (Contains(arrEvent, nJobCode))
                    spJob.operator->()->m_bEvent = true;
                if (Contains(arrDisable, nJobCode))
                    spJob.operator->()->m_bEnabled = false;
                if (nJobCode == nSelectJob)
                    m_nSelectJob = spJob.operator->()->m_nJobCode;
                m_jobs.Add(spJob);
            }
        }
    }
}

// @0x140f2f9c0
void UICharacterCreateSelectDialog::FUN_140f2f9c0(int nJobCode)
{
    FUN_140f2fd50();
    m_nPopupMsg = 0x620001c;
    m_nPopupJob = nJobCode;
}
MS2_REPLACE_METHOD(0x140F2F9C0, UICharacterCreateSelectDialog, FUN_140f2f9c0, 58, 0x88D4E6CA);

// MS2-FUNCTIONAL: FUN_140f2fa00: the delegate / member-pointer temporaries of the exe are laid out differently (frame 0xc8 vs 0xd8)
// @0x140f2fa00
void UICharacterCreateSelectDialog::FUN_140f2fa00(int nJobCode)
{
    if (FUN_1406516b0() == 1)
    {
        MS2Ptr<CMsgBoxData> box = FUN_140d74500(CStringW(L"$s_msgbox_ugc_turms_content"), 0x1e,
            Delegate<bool(int, const CMsgBoxData&)>(this, &UICharacterCreateSelectDialog::FUN_140f301d0));
        if (box.get() != 0)
        {
            box.operator->()->SetTitle(CStringW(L"$s_msgbox_ugc_turms_title"));
            box.operator->()->FUN_140533ff0(nJobCode);
            FUN_140d73c60(MS2Ptr<CMsgBoxData>(box));
        }
    }
    else
    {
        FUN_140f2f9c0(nJobCode);
    }
}

// @0x140f2fba0
void UICharacterCreateSelectDialog::FUN_140f2fba0(int nIndex, int nJobCode)
{
    if (nIndex < 0 || nIndex >= (int)m_jobs.GetCount())
        return;
    if (m_30.get() != 0)
    {
        JobPtr spJob(m_jobs.GetAt(nIndex));
        if (spJob.IsNull())
            return;
        if (spJob.operator->()->m_nJobCode != nJobCode)
            return;
        ASObj obj(2);
        spJob.operator->()->FUN_140f2ee10(&obj);
        m_30.operator->()->Invoke("changeTab", obj.FUN_1422bb870());
        FUN_140f2ffb0(spJob.operator->()->m_nJobCode);
    }
}
MS2_REPLACE_METHOD(0x140F2FBA0, UICharacterCreateSelectDialog, FUN_140f2fba0, 421, 0x4D4E886C);

// @0x140f2fd50
void UICharacterCreateSelectDialog::FUN_140f2fd50()
{
    if (m_30.get() != 0)
        m_30.operator->()->Invoke("popdown");
}
MS2_REPLACE_METHOD(0x140F2FD50, UICharacterCreateSelectDialog, FUN_140f2fd50, 83, 0x77B6ED2A);

// @0x140f2fdb0
void UICharacterCreateSelectDialog::OnEndPopdown()
{
    if (0 < m_nPopupMsg)
    {
        CSceneStateMulti* pScene = FUN_140f30370();
        if (pScene != 0 && m_nPopupMsg == 0x620001c)
            pScene->FUN_14174eb80(m_nPopupJob);
    }
    m_nPopupMsg = 0;
    vfunc_67();
}
MS2_REPLACE_METHOD(0x140F2FDB0, UICharacterCreateSelectDialog, OnEndPopdown, 118, 0x691E40AA);

// @0x140f2fe30
UICharacterCreateSelectDialog::JobPtr UICharacterCreateSelectDialog::FUN_140f2fe30(int nJobCode, int* pnIndex)
{
    *pnIndex = -1;
    if (m_jobs.IsEmpty())
        return JobPtr(0);
    size_t nCount = m_jobs.GetCount();
    for (size_t i = 0; i < nCount; ++i)
    {
        JobPtr spJob(m_jobs.GetAt(i));
        if (spJob == 0)
            continue;
        if (spJob.operator->()->m_nJobCode == nJobCode)
        {
            *pnIndex = (int)i;
            return spJob;
        }
    }
    return JobPtr(0);
}
MS2_REPLACE_METHOD(0x140F2FE30, UICharacterCreateSelectDialog, FUN_140f2fe30, 365, 0x35D8F0A2);

// @0x140f2ffb0
void UICharacterCreateSelectDialog::FUN_140f2ffb0(int nJobCode)
{
    JobDataPtr spJob = JobTable::GetInstance()->GetJobData(nJobCode);
    if (spJob.IsNull())
        return;
    if (spJob.operator->()->GetCharacterBGM() != 0)
    {
        FUN_140d13c40()->FUN_14177c100(spJob.operator->()->GetCharacterBGM(), 0.0f, 0x80, 0);
        m_nBgm = 1;
    }
    if (spJob.operator->()->m_characterVoice.GetLength() > 0)
        FUN_1403ed280()->FUN_1411a4f40(CString(spJob.operator->()->m_characterVoice), DAT_143b01a60);
    FUN_140a94350()->vfunc_14(nJobCode);
}
MS2_REPLACE_METHOD(0x140F2FFB0, UICharacterCreateSelectDialog, FUN_140f2ffb0, 340, 0x1693AEC9);

// @0x140f30110
void UICharacterCreateSelectDialog::FUN_140f30110()
{
    if (m_nBgm != 0)
    {
        m_nBgm = 0;
        FUN_1403ed2d0()->FUN_141bc7b80(0);
    }
}
MS2_REPLACE_METHOD(0x140F30110, UICharacterCreateSelectDialog, FUN_140f30110, 58, 0xC3E3CD19);

// @0x140f30150
int UICharacterCreateSelectDialog::FUN_140f30150()
{
    if (m_randomJobs.GetCount() == 0)
        return m_nSelectJob;
    unsigned nIndex = FUN_140768010((unsigned)m_randomJobs.GetCount(), 0);
    return m_randomJobs[nIndex];
}
MS2_REPLACE_METHOD(0x140F30150, UICharacterCreateSelectDialog, FUN_140f30150, 108, 0xFE5794CA);

// @0x140f301d0
bool UICharacterCreateSelectDialog::FUN_140f301d0(int nButton, const CMsgBoxData& box)
{
    bool bResult = FUN_141900c80(nButton, box);
    if (nButton == 0)
    {
        int nJobCode = box.FUN_141a02e50(0, 0);
        FUN_140f2f9c0(nJobCode);
    }
    return bResult;
}
MS2_REPLACE_METHOD(0x140F301D0, UICharacterCreateSelectDialog, FUN_140f301d0, 86, 0x85082A83);

// @0x140f30370
inline CSceneStateMulti* FUN_140f30370()
{
    CSceneStateMulti* pScene = static_cast<CSceneStateMulti*>(FUN_140aa6d30()->GetCurrent().operator CSceneStateBase*());
    return pScene;
}

// @0x140f30770
UICharacterCreateSelectDialog::TJobData::TJobData()
    : m_nJobCode(0), m_bEnabled(true), m_bEvent(false)
{
}

// @0x140f31080
int UICharacterCreateSelectDialog::vfunc_48()
{
    return 0x4eea;
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142ca9210-0x142ca9270 .text$yd
