// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). UIJobChangeDialog: see uijobchangedialog.h.
// MS2-UNIT: ?\uijobchangedialog.cpp
// MS2-RANGE: 0x1419db000-0x1419df070 .text$mn
// MS2-RANGE: 0x1401159b0-0x140115b20 .text$di
// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??__Es_strSkill@@YAXXZ 0x1401159b0 ; probe
// MS2-PIN: ??__Es_strStun@@YAXXZ 0x1401159e0 ; probe
// MS2-PIN: ??0JobPreview@UIJobChangeDialog@@QEAA@XZ 0x1419dcb00 ; unique
// MS2-PIN: ??1JobPreview@UIJobChangeDialog@@UEAA@XZ 0x1419dcd10 ; unique
// MS2-PIN: ?get@?$MS2Ptr@VASTextField@@@@QEBAPEAVASTextField@@XZ 0x1419dcde0 ; order
// MS2-PIN: ?vfunc_48@UIJobChangeDialog@@UEAAHXZ 0x1419dd650 ; unique
// MS2-PINS-END tplpin
// MS2-GUESS-LOOKALIKES
#define MS2_THIS_FILE "e:\\build\\kr\\22_04\\ms2code\\client\\ms2\\uijobchangedialog.cpp"    // assumed
#include "ms2/placeholder/ms2stdafx.h"

#include "uijobchangedialog.h"

#include <stdlib.h>
#include <typeinfo>

#include "ms2/placeholder/asdata.h"
#include "ms2/placeholder/asobj.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/astooltip.h"
#include "ms2/placeholder/tixmldocument.h"
#include "ms2/placeholder/ms2ptr_impl.h"

#include "ms2/placeholder/header_statics_a.h"

#include "ms2/ms2recover.h"
#include "hook/ms2hook.h"

// ---- unit-local views of unrecovered callees -------------------------------------------------------------------------

class ASDialog : public ASDisplayObject {};

// The xml reader of the exe (see achievemanager.cpp).
class Unk_140165cf0 { public: Unk_140165cf0* FUN_140165cf0(const char*); };
class Unk_140168650 { public: Unk_140168650* FUN_140168650(const char*); };
class Unk_JcFileSystem { public: int FUN_1403974b0(TiXmlDocument* pDoc, const char* pszPath, int nUnused, bool bA, bool bB); };
Unk_JcFileSystem* FUN_140166420();
CStringA FUN_14071ae20(const CStringA& strFile);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
CStringW FUN_1401bf530(Unk_140165cf0* pNode, const char* pszName, CStringW strDefault);
int FUN_1408731e0(Unk_140165cf0* pNode, const char* pszName, int& nValue);
int FUN_140873220(Unk_140165cf0* pNode, const char* pszName, int& nValue);

// The skill table: the row of a skill id.
struct Unk_JcSkillRow { char m_pad_00[0x48]; CString m_strIcon; };
class Unk_JcSkillRef
{
public:
    ~Unk_JcSkillRef();                                          // 0x14063e5c0
    bool FUN_1407f6e90() const;                                 // the skill is missing
    Unk_JcSkillRow* FUN_14063ed50() const;
    void* m_pad_00;
    void* m_p;
};
class Unk_JcSkillTable { public: Unk_JcSkillRef FUN_1407ee1d0(int nSkillId); };
Unk_JcSkillTable* FUN_1401958b0();
CStringW FUN_1409e88d0(int nStringId, const unsigned short& n);     // formatted string table entry

class Unk_JcStrings { public: CStringW FUN_141811980(int, int); };
Unk_JcStrings* FUN_1401a9d70();

class Unk_JcUi { public: float FUN_1422afec0(int nUiId); };
Unk_JcUi* FUN_14025e7a0();
class Unk_JcRewardUI { public: int FUN_141b1d3d0(); };
Unk_JcRewardUI* FUN_140a7b2b0(int nId);

AScript* FUN_1409ee290(MS2Ptr<AScript>* p);
AScript* FUN_1409ee240(MS2Ptr<AScript>* p);
struct Unk_JcInvoke4 { Scaleform::GFx::Value FUN_14190b490(const char* szMethod, unsigned nW, unsigned nH, float fScale); };
void FUN_1422bce00(Scaleform::GFx::Value* pValue, int n);
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);
struct Unk_JcInvoke1 { Scaleform::GFx::Value FUN_1409ba030(const char* szMethod, int n); };
struct Unk_JcInvoke2 { Scaleform::GFx::Value FUN_1409ba0d0(const char* szMethod, int a1, int a2); };
struct Unk_JcInvokeS { Scaleform::GFx::Value FUN_140e78470(const char* szMethod, CStringW a1, CStringW a2); };
CString FUN_14016a5c0(const char* pszName, int nFlags);          // undecorated class name

extern unsigned DAT_143af62d4;                                  // client area width
extern unsigned DAT_143af62d8;                                  // client area height

// The tooltip of a skill (a member of ASTooltip in the exe).
int FUN_1409e1b80(ASTooltip* pTip, int nSkillId, int n);
void* FUN_1409b4bc0(Scaleform::GFx::Value* pRetVal, Scaleform::GFx::Value& v);
class Unk_JcWorld { public: void* FUN_141bd0cc0(); };
Unk_JcWorld* FUN_1403ed2d0();

static bool s_bValid;                                           // 0x143af3588 the tables were read

// @0x1419dc5e0
Scaleform::GFx::Value FUN_1419dc5e0(AScript* pDlg, const char* szMethod, int n, ASObj& obj)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce00(args.FUN_1409b1f70(0), n);
    FUN_1422bce40(args.FUN_1409b1f70(1), obj);
    return pDlg->FUN_1422bb8f0(szMethod, args);
}

#ifndef MS2_HOOK_DLL
// @0x1419dcf80
void UIJobChangeDialog::FUN_1419dcf80()
{
    if (!s_bValid)
    {
        CString msg;
        msg.Format("%s is not initialized", (const char*)FUN_14016a5c0(typeid(UIJobChangeDialog).name(), 0));
        MessageBoxA(0, msg, "Error", 0);
    }
}
#endif

// @0x1419db000
UIJobChangeDialog::UIJobChangeDialog()
    : m_previews(17, 0.75f, 0.25f, 2.25f, 10), m_descs(17, 0.75f, 0.25f, 2.25f, 10)
{
    m_2c = 0xc;
    FUN_141924170(1);
    FUN_1419db600();
}

// @0x1419db120
UIJobChangeDialog::~UIJobChangeDialog()
{
}

// @0x1419db1b0
CString UIJobChangeDialog::vfunc_1()
{
    return CString("JobChangeDialog");
}

// @0x1419db200
void UIJobChangeDialog::OnLoadComplete()
{
    UIDialog::OnLoadComplete();
    FUN_1419dc1e0(m_nJob);
    FUN_1419dbe30(m_nJob);
}

// @0x1419db250
void UIJobChangeDialog::vfunc_26()
{
    UIDialog::vfunc_26();
}

// @0x1419db270
int UIJobChangeDialog::vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs)
{
    return UIDialog::vfunc_28(szMethod, pArgs, nArgs);
}

// @0x1419db2b0
void UIJobChangeDialog::vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs)
{
    FUN_1419dcf80();
    CString strArg = pArgs->FUN_1422b8d30();
    unsigned nIndex = atoi(CString(strArg.GetAt(7), 1));
    MS2Ptr<JobPreview> spPreview(0);
    if (m_previews.Lookup(m_nJob, spPreview))
    {
        if (spPreview->m_skills.GetCount() <= nIndex)
            return;
        ASTooltip tip(FUN_1403ed2d0()->FUN_141bd0cc0(), 0x10, 2);
        if (FUN_1409e1b80(&tip, spPreview->m_skills[nIndex], 0) != 0)
        {
            tip.FUN_1409c69b0(L"");
            FUN_1409b4bc0(pRetVal, tip.FUN_1422bb870());
        }
    }
}

// @0x1419db480
void UIJobChangeDialog::vfunc_67()
{
    UIDialog::vfunc_67();
}

// @0x1419db4a0
int UIJobChangeDialog::vfunc_13()
{
    return 0;
}

// @0x1419db4b0
void UIJobChangeDialog::vfunc_43()
{
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    Unk_JcRewardUI* pUI;
    int n;
    if (pDlg != 0 && (pUI = FUN_140a7b2b0(0x4e40)) != 0 && (n = pUI->FUN_141b1d3d0()) != -1)
    {
        pDlg->vfunc_2(1, 0, (int)((double)(n - pDlg->FUN_1422c13b0()) * 0.5));
        return;
    }
    if (FUN_1409ee240(&m_30) != 0)
        reinterpret_cast<Unk_JcInvoke4*>(FUN_1409ee290(&m_30))->FUN_14190b490("setStageSize", DAT_143af62d4, DAT_143af62d8,
                      FUN_14025e7a0()->FUN_1422afec0(m_28));
}

// @0x1419db600
void UIJobChangeDialog::FUN_1419db600()
{
    LoadJobPreview();
    LoadJobDescription();
    FUN_1419dec80(true);
}

// @0x1419db630
void UIJobChangeDialog::LoadJobPreview()
{
    TiXmlDocument doc;
    CString path = FUN_14071a5b0(CString("Table"), CString("jobPreview.xml"));
    if (FUN_140166420()->FUN_1403974b0(&doc, path, 0, true, false) == 0)
        return;
    Unk_140165cf0* root = ((Unk_140165cf0*)&doc)->FUN_140165cf0("ms2");
    if (root == 0)
        return;
    for (Unk_140165cf0* node = root->FUN_140165cf0("job"); node != 0;
         node = (Unk_140165cf0*)((Unk_140168650*)node)->FUN_140168650("job"))
    {
        int nJob = 0;
        int nDifficulty = 0;
        FUN_1408731e0(node, "code", nJob);
        FUN_1408731e0(node, "difficulty", nDifficulty);
        MS2Ptr<JobPreview> sp(new JobPreview());
        sp->m_nDifficulty = nDifficulty;
        for (Unk_140165cf0* skill = node->FUN_140165cf0("skill"); skill != 0;
             skill = (Unk_140165cf0*)((Unk_140168650*)skill)->FUN_140168650("skill"))
        {
            int nSkill = 0;
            int nLevel = 0;
            FUN_140873220(skill, "id", nSkill);
            FUN_1408731e0(skill, "level", nLevel);
            sp->m_skills.Add(nSkill);
            sp->m_levels.Add((unsigned short)nLevel);
        }
        m_previews.SetAt(nJob, sp);
    }
}

// @0x1419db970
void UIJobChangeDialog::LoadJobDescription()
{
    TiXmlDocument doc;
    CStringA path = FUN_14071ae20(CStringA("korJobDescription.xml"));
    if (FUN_140166420()->FUN_1403974b0(&doc, path, 0, true, false) == 0)
        return;
    Unk_140165cf0* root = ((Unk_140165cf0*)&doc)->FUN_140165cf0("ms2");
    if (root == 0)
        return;
    for (Unk_140165cf0* node = root->FUN_140165cf0("job"); node != 0;
         node = (Unk_140165cf0*)((Unk_140168650*)node)->FUN_140168650("job"))
    {
        int nJob = 0;
        FUN_1408731e0(node, "code", nJob);
        MS2Ptr<JobDescription> sp(new JobDescription());
        sp->m_strMain = FUN_1401bf530(node, "mainJobName", L"");
        sp->m_strSub = FUN_1401bf530(node, "subJobName", L"");
        sp->m_strSpecific = FUN_1401bf530(node, "specific", L"");
        sp->m_strHistory = FUN_1401bf530(node, "history", L"");
        sp->m_strSpecific.Replace(L"\\n", L"\n");
        sp->m_strHistory.Replace(L"\\n", L"\n");
        m_descs.SetAt(nJob, sp);
    }
}

// @0x1419dbe30
void UIJobChangeDialog::FUN_1419dbe30(int nJob)
{
    FUN_1419dcf80();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg == 0)
        return;
    MS2Ptr<JobPreview> spPreview(0);
    if (m_previews.Lookup(nJob, spPreview))
    {
        if (spPreview->m_skills.GetCount() != spPreview->m_levels.GetCount())
            return;
        for (size_t i = 0; i < spPreview->m_skills.GetCount(); i++)
        {
            int nSkill = spPreview->m_skills[i];
            unsigned short nLevel = spPreview->m_levels[i];
            Unk_JcSkillRef ref = FUN_1401958b0()->FUN_1407ee1d0(nSkill);
            if (!ref.FUN_1407f6e90())
            {
                CStringW strLevel;
                strLevel = FUN_1409e88d0(0x582, nLevel);
                ASObj obj(2);
                obj.FUN_1407cbb20("skillName", FUN_1401a9d70()->FUN_141811980(4, nSkill));
                obj.FUN_1407cbb20("skillLevel", strLevel);
                obj.FUN_1407cba60("imgPath", ref.FUN_14063ed50()->m_strIcon);
                FUN_1419dc5e0(pDlg, "setSkill", (int)i, obj);
            }
        }
        reinterpret_cast<Unk_JcInvoke1*>(pDlg)->FUN_1409ba030("setDifficulty", spPreview->m_nDifficulty);
    }
}

// @0x1419dc1e0
void UIJobChangeDialog::FUN_1419dc1e0(int nJob)
{
    FUN_1419dcf80();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg == 0)
        return;
    MS2Ptr<JobDescription> spDesc(0);
    if (m_descs.Lookup(nJob, spDesc))
    {
        MS2Ptr<ASTextField> spDescText = FUN_140bb4cf0("m_jobDesc");
        if (spDescText.get())
            spDescText->FUN_1422c4cd0(spDesc->m_strSpecific);
        MS2Ptr<ASTextField> spHistoryText = FUN_140bb4cf0("m_jobHistory");
        if (spHistoryText.get())
            spHistoryText->FUN_1422c4cd0(spDesc->m_strHistory);
        reinterpret_cast<Unk_JcInvokeS*>(pDlg)->FUN_140e78470("setJobName", spDesc->m_strSub, spDesc->m_strMain);
        reinterpret_cast<Unk_JcInvoke1*>(pDlg)->FUN_1409ba030("setJob", nJob);
        reinterpret_cast<Unk_JcInvoke2*>(pDlg)->FUN_1409ba0d0("setVideo", 1, nJob);
    }
}

#ifndef MS2_HOOK_DLL
// @0x1419dec80
void UIJobChangeDialog::FUN_1419dec80(bool bValid)
{
    s_bValid = bValid;
}
#endif

// @0x1419dc510
void UIJobChangeDialog::FUN_1419dc510(int nJob)
{
    m_nJob = nJob;
}

// @0x1419dc530
bool UIJobChangeDialog::FUN_1419dc530()
{
    FUN_1419dcf80();
    MS2Ptr<JobPreview> spPreview(0);
    if (!m_previews.Lookup(m_nJob, spPreview))
        return false;
    return spPreview->m_nDifficulty > 4;
}

// @0x1419db000 siblings: the nested classes
UIJobChangeDialog::JobPreview::JobPreview()
{
}

UIJobChangeDialog::JobDescription::JobDescription()
{
}
// Atexit thunks of this unit's statics (gap1 yd sweep).
// MS2-RANGE: 0x142cbf080-0x142cbf0b0 .text$yd
