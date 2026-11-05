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
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uitalkcinematic.h"
#include "ms2/placeholder/cstringtable.h"
#include "ms2/client/ms2/worldservice.h"
#include "ms2/commonfiles/filesystem.h"
#include "ms2/placeholder/blockformat.h"
#include "ms2/placeholder/gfxmanager.h"
#include "ms2/commonfiles/skilloverlapcompare.h"
#include "ms2/commonfiles/os.h"
class Unk_XmlNode   // C3: member view for the former element stand-ins
{
public:
    class Unk_XmlNode* FirstChild(char const*);
    class Unk_XmlNode* NextSibling(char const*);
};

// ---- unit-local views of unrecovered callees -------------------------------------------------------------------------

class ASDialog : public ASDisplayObject
{
};

// The xml reader of the exe (see achievemanager.cpp).
class Unk_JcFileSystem : public CFileSystem { };
CStringA FUN_14071ae20(const CStringA& strFile);
CString FUN_14071a5b0(const CString& strDir, const CString& strFile);
CStringW FUN_1401bf530(TiXmlElement* pNode, const char* pszName, CStringW strDefault);
int XmlGetAttr(class TiXmlElement*, char const*, int&);   // C3: was FUN_1408731e0
int XmlGetAttr(class TiXmlElement*, char const*, unsigned int&);   // C3: was FUN_140873220

// The skill table: the row of a skill id.
struct Unk_JcSkillRow { char m_pad_00[0x48]; CString m_strIcon; };
class Unk_JcSkillTable;
class SkillDataTableCli;

UITalkCinematic* FUN_140a7b2b0(int nId);

void FUN_1422bce00(Scaleform::GFx::Value* pValue, unsigned __int64 n);   // GallerySet: 64-bit value
void FUN_1422bce40(Scaleform::GFx::Value* pValue, const AScript& obj);
CString FUN_14016a5c0(const char* pszName, int nFlags);          // undecorated class name

extern unsigned DAT_143af62d4;                                  // client area width
extern unsigned DAT_143af62d8;                                  // client area height

// The tooltip of a skill (a member of ASTooltip in the exe).
int FUN_1409e1b80(ASTooltip* pTip, int nSkillId, int n);

static bool s_bValid;                                           // 0x143af3588 the tables were read

// the exe's is a member of the dialog's script (this, hidden return slot in rdx); a free function put the slot in rcx
struct Unk_JcInvokeSkill { Scaleform::GFx::Value FUN_1419dc5e0(const char* szMethod, unsigned __int64 n, ASObj& obj); };

// @0x1419dc5e0
Scaleform::GFx::Value Unk_JcInvokeSkill::FUN_1419dc5e0(const char* szMethod, unsigned __int64 n, ASObj& obj)
{
    ASArgList args;
    args.FUN_1409b2800(2);
    FUN_1422bce00(args.FUN_1409b1f70(0), n);
    FUN_1422bce40(args.FUN_1409b1f70(1), obj);
    return reinterpret_cast<AScript*>(this)->FUN_1422bb8f0(szMethod, args);
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
CString UIJobChangeDialog::GetTypeName()
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
    size_t nIndex = atoi(CString(strArg.GetAt(7), 1));
    MS2Ptr<JobPreview> spPreview(0);
    if (m_previews.Lookup(m_nJob, spPreview))
    {
        if (nIndex >= spPreview->m_skills.GetCount())
            return;
        ASTooltip tip(WorldService::GetInstance()->FUN_141bd0cc0(), 0x10, 2);
        if (FUN_1409e1b80(&tip, spPreview->m_skills[nIndex], 0) != 0)
        {
            tip.SetEnablePuton(L"");
            *pRetVal = tip.FUN_1422bb870();
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
    UITalkCinematic* pUI;
    int n;
    if (pDlg != 0 && (pUI = FUN_140a7b2b0(0x4e40)) != 0 && (n = pUI->GetLowerCutGlobalY()) != -1)
    {
        n = (int)((double)(n - pDlg->GetHeightCeil()) * 0.5);
        pDlg->vfunc_2(1, 0, n);
        return;
    }
    if (((MS2Ptr<AScript>*)(void*)(&m_30))->get() != 0)
        reinterpret_cast<AScript*>(((MS2Ptr<AScript>*)(&m_30))->operator->())->FUN_14190b490("setStageSize", DAT_143af62d4, DAT_143af62d8,
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
    bool bFailed = ((class Unk_JcFileSystem*)GetFileSystem())->FUN_1403974b0(&doc, FUN_14071a5b0("Table", "jobPreview.xml"), 0, true, false) == 0;
    if (bFailed)
        return;
    TiXmlElement* root = ((class TiXmlElement*)((class Unk_XmlNode*)(((TiXmlElement*)&doc)))->FirstChild("ms2"));
    if (root == 0)
        return;
    for (TiXmlElement* node = ((class TiXmlElement*)((class Unk_XmlNode*)(root))->FirstChild("job")); node != 0;
         node = ((TiXmlElement*)((class Unk_XmlNode*)(node))->NextSibling("job")))
    {
        int nJob = 0;
        int nDifficulty = 0;
        XmlGetAttr((class TiXmlElement*)(node), "code", nJob);
        XmlGetAttr((class TiXmlElement*)(node), "difficulty", nDifficulty);
        MS2Ptr<JobPreview> sp(new JobPreview());
        sp->m_nDifficulty = nDifficulty;
        for (TiXmlElement* skill = ((class TiXmlElement*)((class Unk_XmlNode*)(node))->FirstChild("skill")); skill != 0;
             skill = ((TiXmlElement*)((class Unk_XmlNode*)(skill))->NextSibling("skill")))
        {
            int nSkill = 0;
            int nLevel = 0;
            XmlGetAttr((class TiXmlElement*)(skill), "id", *(unsigned int*)&static_cast<int&>(nSkill));
            XmlGetAttr((class TiXmlElement*)(skill), "level", nLevel);
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
    bool bFailed = ((class Unk_JcFileSystem*)GetFileSystem())->FUN_1403974b0(&doc, FUN_14071ae20("korJobDescription.xml"), 0, true, false) == 0;
    if (bFailed)
        return;
    TiXmlElement* root = ((class TiXmlElement*)((class Unk_XmlNode*)(((TiXmlElement*)&doc)))->FirstChild("ms2"));
    if (root == 0)
        return;
    for (TiXmlElement* node = ((class TiXmlElement*)((class Unk_XmlNode*)(root))->FirstChild("job")); node != 0;
         node = ((TiXmlElement*)((class Unk_XmlNode*)(node))->NextSibling("job")))
    {
        int nJob = 0;
        XmlGetAttr((class TiXmlElement*)(node), "code", nJob);
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
    if (pDlg != 0)
    {
        MS2Ptr<JobPreview> spPreview(0);
        if (m_previews.Lookup(nJob, spPreview))
        {
            if (spPreview->m_skills.GetCount() != spPreview->m_levels.GetCount())
                return;
            for (size_t i = 0; i < spPreview->m_skills.GetCount(); i++)
            {
                int nSkill = spPreview->m_skills[i];
                unsigned short nLevel = spPreview->m_levels[i];
                MS2Ptr<SkillData> ref = reinterpret_cast<SkillDataTable*>(reinterpret_cast<Unk_JcSkillTable*>(TSingleton<SkillDataTableCli>::GetInstance()))->GetSkillData(nSkill);
                if (ref.IsNull())
                    continue;
                CStringW strLevel;
                strLevel = BlockFormat(0x582, nLevel);
                ASObj obj(2);
                obj.FUN_1407cbb20("skillName", TSingleton<CStringTable>::GetInstance()->FUN_141811980(4, nSkill));
                obj.FUN_1407cbb20("skillLevel", strLevel);
                obj.FUN_1407cba60("imgPath", reinterpret_cast<Unk_JcSkillRow*>(ref.operator->())->m_strIcon);
                reinterpret_cast<Unk_JcInvokeSkill*>(pDlg)->FUN_1419dc5e0("setSkill", i, obj);
            }
            reinterpret_cast<AScript*>(pDlg)->Invoke("setDifficulty", spPreview->m_nDifficulty);
        }
    }
}

// @0x1419dc1e0
void UIJobChangeDialog::FUN_1419dc1e0(int nJob)
{
    FUN_1419dcf80();
    ASDialog* pDlg = dynamic_cast<ASDialog*>((AScript*)m_30);
    if (pDlg != 0)
    {
        MS2Ptr<JobDescription> spDesc(0);
        if (m_descs.Lookup(nJob, spDesc))
        {
            if (MS2Ptr<ASTextField> spDescText = GetChild<ASTextField>("m_jobDesc"))
                spDescText->SetTextW(spDesc->m_strSpecific);
            if (MS2Ptr<ASTextField> spHistoryText = GetChild<ASTextField>("m_jobHistory"))
                spHistoryText->SetTextW(spDesc->m_strHistory);
            pDlg->Invoke("setJobName", spDesc->m_strMain, spDesc->m_strSub);
            reinterpret_cast<AScript*>(pDlg)->Invoke("setJob", nJob);
            reinterpret_cast<AScript*>(pDlg)->FUN_1409ba0d0("setVideo", 1, nJob);
        }
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
int UIJobChangeDialog::FUN_1419dc530()
{
    FUN_1419dcf80();
    MS2Ptr<JobPreview> spPreview(0);
    if (m_previews.Lookup(m_nJob, spPreview))
        return spPreview->m_nDifficulty >= 5 ? 1 : 0;
    return 0;
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
