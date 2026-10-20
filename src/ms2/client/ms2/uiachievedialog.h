// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiachievedialog.h (name assumed from the
// class name; the .cpp's __FILE__ string is not in the exe).
//
// UIAchieveDialog ("AchieveDialog", UI type 0x4e73): the trophy window. A tab list (summary / emblem / trophy categories of
// achieveCategory.xml), the hero list of the trophies of the selected category (search box, filter drop-down, bookmark,
// reward check boxes), the summary page (latest cleared trophies and the score) and the debug up/down commands of
// the GM build (packet 0x46, operation 5). RTTI .?AVUIAchieveDialog@@, 0x228 bytes.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset> (invented names).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uidialog.h"

class ASData;
class ASObj;
class CAchieve;
class Unk_AcHero;
class Unk_AcList;

class UIAchieveDialog : public UIDialog
{
public:
    // one cleared grade of a trophy (the summary page sorts them newest first)
    struct ClearRecord
    {
        int m_id;                       // +0x00
        int m_grade;                    // +0x04
        __int64 m_time;                 // +0x08
    };

    // the filters of the hero list
    struct FilterOptions
    {
        FilterOptions() : m_filter(0), m_survival(0) {}
        int m_filter;                   // +0x00 all / started / completed / bookmarked
        int m_survival;                 // +0x04 the survival page
        CString m_categoryTag;          // +0x08
        CString m_contentsTag;          // +0x10
    };

    UIAchieveDialog();                                                                  // 0x1418a7310
    virtual ~UIAchieveDialog();                                                         //  0 0x1418a74b0 (??_G 0x1418b0020...)
    virtual CString vfunc_1();                                                          //  1 0x1418a7530 "AchieveDialog"
    virtual int vfunc_13();                                                             // 13 0x1418a8430 key (close the popup / search)
    virtual void vfunc_15();                                                            // 15 0x1418a8390 per frame: refresh the updated trophies
    virtual void OnLoadComplete();                                                      // 22 0x1418a7580
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                        // 28 0x1418a7640
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);
                                                                                        // 45 0x1418a89d0
    virtual int vfunc_48() { return 0x4e73; }                                           // 48 (COMDAT 0x1418b0010)
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);               // 49 0x1418a8690 tooltip
    virtual int vfunc_53(void* pCfg);                                                   // 53 0x1418a8760 save the filters
    virtual int vfunc_54(void* pCfg);                                                   // 54 0x1418a88b0 load the filters
    virtual int vfunc_65();                                                             // 65 0x1418a8310
    virtual void vfunc_67();                                                            // 67 0x1418a8330
    virtual void vfunc_80(void* pRequest);                                              // 80 0x1418a8530 the search request answered

    void FUN_1418a8f80();                                                               // refresh the movie
    void FUN_1418a8ff0();                                                               // fill the list of the selected category
    void FUN_1418a9360();                                                               // the category tree
    void FUN_1418a9800();                                                               // the reward counts of the tabs
    void FUN_1418a9c20();                                                               // the summary page
    void FUN_1418aa190(const FilterOptions* pOptions);                                  // the hero list
    void FUN_1418aa660(int nId);                                                        // update one trophy row
    void FUN_1418aa890();                                                               // send the search
    void FUN_1418aa9b0(int nId);                                                        // show the trophy of the id
    CStringW FUN_1418aaaf0(CAchieve* pAchieve);                                         // "", "normal" or "complete"
    int FUN_1418aaba0(CAchieve* pAchieve);                                              // the reward count
    CStringW FUN_1418aabd0(CAchieve* pAchieve);                                         // the description of the current grade
    CStringW FUN_1418aac30(CAchieve* pAchieve, int nGrade);                             // the description of a grade
    CStringW FUN_1418aad60();                                                           // the text of the search box
    void FUN_1418aaee0(const CStringW& strText);                                        // set the search box
    void FUN_1418ab000(ASObj& rRow, CAchieve* pAchieve);                                // reward text and palette colours
    void FUN_1418ab520(ASObj& rRow, CAchieve* pAchieve);                                // title, progress and grade
    void FUN_1418ab7e0(ASObj& rRow, CAchieve* pAchieve);                                // one row of the hero list
    void FUN_1418abaa0(ASObj& rRow, CAchieve* pAchieve);                                // the conditions
    void FUN_1418abc60(ASObj& rRow, CAchieve* pAchieve);                                // the required trophies
    void FUN_1418abfa0(ASObj& rRow, CAchieve* pAchieve);                                // the cleared grades
    int FUN_1418ac320(int nId);                                                         // the tab of the trophy
    int FUN_1418ac480();                                                                // the selected filter
    void FUN_1418ac5f0(int nIndex);                                                     // select a filter
    void FUN_1418ac710(int nTab);                                                       // select the tab in the movie (the exe passes m_178, the body reads the member)
    int FUN_1418ac780(CAchieve* pAchieve);                                              // locked for a player
    int FUN_1418ac870(CAchieve* pAchieve);                                              // locked and hidden
    int FUN_1418ac8f0(CAchieve* pAchieve);                                              // 0 reward, 1 open, 2 done
    int FUN_1418ac9e0();                                                                // the selected tab of the list
    int FUN_1418aca90(CAchieve* pAchieve);                                              // the description is secret
    int FUN_1418acaf0();                                                                // debug: the filter shows everything
    int FUN_1418acca0(int nId);                                                         // the row is expanded
    int FUN_1418acce0(CAchieve* pAchieve);                                              // 0
    int FUN_1418acd10(int nId);                                                         // the debug upgrade is possible
    int FUN_1418ace00(CAchieve* pAchieve, const CStringW& strSearch, const FilterOptions* pOptions);   // the row is shown

    int FUN_1418ad560(int nCondType);                                                   // the condition type lists collected ids
    CStringW FUN_1418ad5d0(int nCondType, unsigned nId);                                // the text of one collected id
    int FUN_1418ad960(int nCondType, unsigned nId);                                     // the collected id is done

    // movie children (ICF'd child lookups of the exe)
    MS2Ptr<Unk_AcHero> FUN_140ede180(const CString& strName);
    MS2Ptr<Unk_AcList> FUN_140c02900(const CString& strName);

private:
    MS2_LAYOUT_FRIEND;
    int m_178;                                                                          // +0x178 the selected tab
    int m_17c;                                                                          // +0x17c the selected category id
    int m_180;                                                                          // +0x180 the filter index
    int m_184;                                                                          // +0x184
    CStringW m_188;                                                                     // +0x188 the search text
    bool m_190;                                                                         // +0x190 show every reward kind
    ATL::CAtlMap<int, int> m_198;                                                       // +0x198 reward kinds shown (17 buckets)
    ATL::CAtlMap<unsigned int, int> m_1e0;                                              // +0x1e0 expanded rows
};
MS2_CHECK_SIZE(UIAchieveDialog, 0x228);
MS2_CHECK_OFFSET(UIAchieveDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIAchieveDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIAchieveDialog, m_190, 0x190);
MS2_CHECK_OFFSET(UIAchieveDialog, m_198, 0x198);
MS2_CHECK_OFFSET(UIAchieveDialog, m_1e0, 0x1e0);
MS2_CHECK_SIZE(UIAchieveDialog::ClearRecord, 0x10);
MS2_CHECK_SIZE(UIAchieveDialog::FilterOptions, 0x18);
