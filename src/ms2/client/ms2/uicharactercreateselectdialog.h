// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicharactercreateselectdialog.h (name
// assumed: the class name; the exe has no assert path for it).
//
// UICharacterCreateSelectDialog ("CharacterCreateSelectDialog", UI type 0x4eea): the job picker shown when a new
// character is created. Table\characterCreateSelect.xml lists the jobs (<group name="data"> rows with jobCode, movie and
// descKey; <group name="display"> with the tab order, the disabled / event / random-select job codes). OnLoadComplete
// sends the tabs to the movie ("initData"), "onChangeTab" switches the preview job ("changeTab"), "onClickCreate" opens
// the create scene for the picked job (after an "UGC terms" box on language 1). RTTI .?AVUICharacterCreateSelectDialog@@,
// 0x1d8 bytes, vftables at +0 and +0x18 (IMessageListener).
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; members are invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/ccachedata.h"
#include "ms2/placeholder/cptred.h"

class ASObj;
class CMsgBoxData;

class UICharacterCreateSelectDialog : public UIDialog
{
public:
    // One selectable job (a <list> row of the data group); the movie name, descriptions and the tab flags.
    class TJobData : public CPtred
    {
    public:
        TJobData();                                             // 0x140f30770
        virtual ~TJobData() = default;                         //  0 0x140f30930 (??_G 0x140f30b10)
        void FUN_140f2ee10(ASObj* pObj);                        // fills the movie object of this job

        int m_nJobCode;                                         // +0x18
        CString m_strMovie;                                     // +0x20 preview movie
        CStringW m_strDesc;                                     // +0x28 description (string table 0x1c)
        CStringW m_strName;                                     // +0x30 job name (string table 6)
        bool m_bEnabled;                                        // +0x38 1
        bool m_bEvent;                                          // +0x39
    };
    typedef MS2Ptr<TJobData> JobPtr;
    typedef ATL::CAtlMap<int, JobPtr> JobMap;

    UICharacterCreateSelectDialog();                            // 0x140f2e4d0
    virtual ~UICharacterCreateSelectDialog();                   //  0 0x140f2e5d0 (??_G 0x140f30b50)
    virtual CString vfunc_1();                                  //  1 0x140f2e650 "CharacterCreateSelectDialog"
    virtual void OnLoadComplete();                              // 22 0x140f2e6a0 send the tabs to the movie
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                // 28 0x140f2eac0 onChangeTab / onClickCreate / onClickPrev / OnEndPopdown
    virtual void vfunc_40();                                    // 40 0x140f2edc0 reload the table
    virtual int vfunc_48();                                     // 48 0x140f31080
    virtual int vfunc_65();                                     // 65 0x140f2ecb0 reload the table when the file changed, then open
    virtual void vfunc_67();                                    // 67 0x140f2ed30 close
    virtual void vfunc_69();                                    // 69 0x140f2ed80

    void LoadCharacterCreateSelect();                                       // 0x140f2ef10 load characterCreateSelect.xml
    void FUN_140f2f9c0(int nJobCode);                           // 0x140f2f9c0 remember the job and pop the tab down
    void FUN_140f2fa00(int nJobCode);                           // 0x140f2fa00 create button
    void FUN_140f2fba0(int nIndex, int nJobCode);               // 0x140f2fba0 tab changed
    void FUN_140f2fd50();                                       // 0x140f2fd50 "popdown"
    void OnEndPopdown();                                       // 0x140f2fdb0 end of the popdown
    JobPtr FUN_140f2fe30(int nJobCode, int* pnIndex);           // 0x140f2fe30 the job and its tab index
    void FUN_140f2ffb0(int nJobCode);                           // 0x140f2ffb0 preview sound of a job
    void FUN_140f30110();                                       // 0x140f30110 stop the preview music
    int FUN_140f30150();                                        // 0x140f30150 the job selected at the start
    bool FUN_140f301d0(int nButton, const CMsgBoxData& box);    // 0x140f301d0 terms box result

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<JobPtr> m_jobs;                              // +0x178 tabs in order
    ATL::CAtlArray<int> m_randomJobs;                           // +0x198 randomselectJobCode
    MS2Ptr<CCacheData> m_spCache;                               // +0x1b8 the loaded table file
    int m_nSelectJob;                                           // +0x1c8 selectJobCode
    int m_nPopupJob;                                            // +0x1cc job waiting for the popdown
    int m_nPopupMsg;                                            // +0x1d0 0x620001c while waiting
    int m_nBgm;                                                 // +0x1d4 preview music started
};
MS2_CHECK_SIZE(UICharacterCreateSelectDialog::TJobData, 0x40);
MS2_CHECK_SIZE(UICharacterCreateSelectDialog, 0x1d8);
MS2_CHECK_OFFSET(UICharacterCreateSelectDialog, m_jobs, 0x178);
MS2_CHECK_OFFSET(UICharacterCreateSelectDialog, m_randomJobs, 0x198);
MS2_CHECK_OFFSET(UICharacterCreateSelectDialog, m_spCache, 0x1b8);
MS2_CHECK_OFFSET(UICharacterCreateSelectDialog, m_nSelectJob, 0x1c8);
MS2_CHECK_OFFSET(UICharacterCreateSelectDialog, m_nBgm, 0x1d4);
