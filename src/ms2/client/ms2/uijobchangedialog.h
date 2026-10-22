// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uijobchangedialog.h (name assumed: the
// exe has no __FILE__ string for this unit).
//
// UIJobChangeDialog ("JobChangeDialog", UI type 0x4e7c, RTTI .?AVUIJobChangeDialog@@, 0x218 bytes): the job preview.
// The ctor reads two tables: Table/jobPreview.xml (per job: the difficulty and the preview skills with their level)
// and korJobDescription.xml (the job names, the description and the history texts). The movie then shows the chosen
// job: "setJob", "setJobName", "setVideo", "setDifficulty" and one "setSkill" per preview skill; the tooltip of a skill
// icon is built from "<prefix>NN" (the index is the char at position 7 of the argument). The second base (+0x178) is the
// CValidData<UIJobChangeDialog> check. Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/cvaliddata.h"

class ASData;
class ASTextField;

class UIJobChangeDialog : public UIDialog, public CValidData<UIJobChangeDialog>
{
public:
    // One row of jobPreview.xml (0x60 bytes): the difficulty and the preview skills with their levels.
    class JobPreview : public CPtred
    {
    public:
        JobPreview();                                   // 0x1419dcb00
        virtual ~JobPreview() = default;                //  0 0x1419dcd10 (??_G 0x1419dcf00; no vptr store)
        int m_nDifficulty;                              // +0x18
        int m_pad_1c;
        ATL::CAtlArray<int> m_skills;                   // +0x20 skill ids
        ATL::CAtlArray<unsigned short> m_levels;        // +0x40 their levels
    };

    // One row of korJobDescription.xml (0x38 bytes).
    class JobDescription : public CPtred
    {
    public:
        JobDescription();                               // 0x1419dca80
        virtual ~JobDescription() = default;            //  0 0x1419dccb0 (??_G 0x1419dcec0; no vptr store)
        CStringW m_strMain;                             // +0x18 mainJobName
        CStringW m_strSub;                              // +0x20 subJobName
        CStringW m_strSpecific;                         // +0x28 specific (the description)
        CStringW m_strHistory;                          // +0x30 history
    };

    UIJobChangeDialog();                                // 0x1419db000
    virtual ~UIJobChangeDialog();                       //  0 0x1419db120 (??_G 0x1419dcf40)
    virtual CString vfunc_1();                          //  1 0x1419db1b0 "JobChangeDialog"
    virtual void OnLoadComplete();                      // 22 0x1419db200 show the chosen job
    virtual void vfunc_26();                            // 26 0x1419db250
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                        // 28 0x1419db270
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x1419db2b0 "getTooltip" of a skill icon
    virtual void vfunc_67();                            // 67 0x1419db480
    virtual int vfunc_13();                             // 13 0x1419db4a0
    virtual void vfunc_43();                            // 43 0x1419db4b0 center below the inventory / set the stage size
    virtual int vfunc_48() { return 0x4e7c; }           // 48 0x1419dd650 UI type id

    void FUN_1419db600();                               // read both tables, then mark the check valid
    void LoadJobPreview();                               // read jobPreview.xml
    void LoadJobDescription();                               // read korJobDescription.xml
    void FUN_1419dbe30(int nJob);                       // send the preview skills
    void FUN_1419dc1e0(int nJob);                       // send the texts and the job
    void FUN_1419dc510(int nJob);                       // choose the job
    bool FUN_1419dc530();                               // the chosen job is a hard one (difficulty > 4)
    static void FUN_1419dec80(bool bValid);             // the tables were read
    static void FUN_1419dcf80();                        // the tables must be read (message box otherwise)
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);  // text field child lookup (a UIDialog member)

private:
    MS2_LAYOUT_FRIEND;
    int m_nJob;                                         // +0x180
    int m_pad_184;
    ATL::CAtlMap<int, MS2Ptr<JobPreview> > m_previews;  // +0x188 job -> preview
    ATL::CAtlMap<int, MS2Ptr<JobDescription> > m_descs; // +0x1d0 job -> texts
};
MS2_CHECK_SIZE(UIJobChangeDialog, 0x218);
