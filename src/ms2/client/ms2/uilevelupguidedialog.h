// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uilevelupguidedialog.h (name assumed from
// the class name; the .cpp's __FILE__ string is not in the exe).
//
// UILevelUpGuideDialog ("LevelUpGuideDialog", UI type 0x4efa): the level-up guide window. recommendContents.xml lists the
// contents (common / boss / dungeon entries with a level range) the player should do next; the window shows the entries
// whose level range holds the player's level, one filter check box per kind, and the quest rewards of the level steps
// (the quests of grade 1 and 2 sorted by level). RTTI .?AVUILevelUpGuideDialog@@, 0x210 bytes, vftables 0x142fd...
// (UIDialog), +0x18, UIQuestEventListener at +0x178 and UIStatusEventListener at +0x180.
// Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields are m_<offset> (invented names).
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <atlstr.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/dclevelrange.h"
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)

class ASData;
class UIObject;
class CMsgBoxData;
class Unk_LgCheck;
class Unk_LgList;
class Unk_LgEvent;
class ASTextField;

class UILevelUpGuideDialog : public UIDialog, public UIQuestEventListener, public UIStatusEventListener
{
public:
    class RecommendContnets : public CPtred
    {
    public:
        RecommendContnets();                // 0x140f8a590
        virtual ~RecommendContnets();       // 0x140f8a790 (??_G 0x140f8a940)

        int m_id;                           // +0x18 "id"
        int m_code;                         // +0x1c "code"
        int m_kind;                         // +0x20 0 = common, 1 = boss, 2 = dungeon (from "type"; left unset by the ctor)
        int m_sorting;                      // +0x24 "sorting" (ctor 0x7fffffff)
        unsigned short m_minLevel;          // +0x28 "minLevel"
        unsigned short m_maxLevel;          // +0x2a "maxLevel"
        CString m_type;                     // +0x30 "type": common / boss (npc id) / dungeon
        CString m_img;                      // +0x38 "img"
        CString m_link;                     // +0x40 "link": the dialog the row opens
    };

    UILevelUpGuideDialog();                                                                     // 0x140f84310
    virtual ~UILevelUpGuideDialog();                                                            //  0 0x140f84450 (??_G 0x140f8a980)
    virtual CString vfunc_1();                                                                  //  1 0x140f84520
    virtual int vfunc_65();                                                                     // 65 0x140f84570
    virtual void vfunc_67();                                                                    // 67 0x140f84610
    virtual void OnLoadComplete();                                                              // 22 0x140f84900
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
                                                                                                // 28 0x140f84bb0
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);                       // 49 0x140f84dc0 tooltip
    virtual int vfunc_48() { return 0x4efa; }                                                   // 48 (COMDAT 0x140f8abc0)
    virtual void vfunc_o178_8(void* pQuest);                                                    // 0x140f84f30 a quest was updated
    virtual void vfunc_oa0_9(unsigned short nLevel);                                            // 0x140f851f0 level changed

    bool SendQuestMode24(int nResult, const CMsgBoxData& rBox);       // newbie warning confirmed: send the quest
    void FUN_140f85330(unsigned short nLevel);                      // collect the level steps and select the level
    void FUN_140f854b0(int nId);                                    // open the dialog a row links to
    void FUN_140f857e0(int nQuest);                                 // receive an item reward (asks first when it is a newbie)
    void FUN_140f85ba0();                                           // load recommendContents.xml
    void FUN_140f85f90();                                           // send the level steps of the quests to the movie
    void FUN_140f861c0();                                           // fill the contents list
    void FUN_140f869f0();                                           // send the level steps to the event dialog
    int FUN_140f86dd0(class ASObj& rObj, int nQuest);               // one level step row: state, level text, reward
    void FUN_140f87270(class ASObj& rObj, int nQuest, int bName);   // the item reward of a level step
    void FUN_140f876b0(MS2Ptr<RecommendContnets> spRow, Scaleform::GFx::Value* pRetVal);     // boss tooltip
    void FUN_140f878e0(MS2Ptr<RecommendContnets> spRow, Scaleform::GFx::Value* pRetVal);     // plain text tooltip
    int FUN_140f87a30(MS2Ptr<RecommendContnets> spRow);             // the row's level range holds the selected levels
    void FUN_140f87af0(unsigned short nLevel);                      // pick the shown level range around nLevel
    MS2Ptr<Unk_LgEvent> FUN_140f880c0(const CString& strName);      // the "m_eventDialog" child
    MS2Ptr<Unk_LgCheck> FUN_140e52670(const CString& strName);      // check box child lookup (UIDialog member, shared)
    MS2Ptr<ASTextField> FUN_140bb4cf0(const CString& strName);      // text field child lookup (UIDialog member, shared)
    MS2Ptr<Unk_LgList> FUN_140ba4b70(const CString& strName);       // list child lookup (UIDialog member, shared)

private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<unsigned short> m_188;                           // +0x188 levels of the quest steps
    ATL::CAtlArray<CString> m_1a8;                                  // +0x1a8 names of the bound item slots
    Unk_DcLevelRange m_1c8;                                              // +0x1c8 the level range shown
    int m_1cc[3];                                                   // +0x1cc filter check boxes: common, boss, dungeon
    unsigned short m_1d8;                                           // +0x1d8 the highest level step
    ATL::CRBMap<int, MS2Ptr<RecommendContnets> > m_1e0;             // +0x1e0 rows by id
};
MS2_CHECK_SIZE(UILevelUpGuideDialog, 0x210);
MS2_CHECK_SIZE(UILevelUpGuideDialog::RecommendContnets, 0x48);
MS2_CHECK_OFFSET(UILevelUpGuideDialog::RecommendContnets, m_kind, 0x20);
MS2_CHECK_OFFSET(UILevelUpGuideDialog::RecommendContnets, m_sorting, 0x24);
MS2_CHECK_OFFSET(UILevelUpGuideDialog::RecommendContnets, m_type, 0x30);
MS2_CHECK_OFFSET(UILevelUpGuideDialog::RecommendContnets, m_link, 0x40);
MS2_CHECK_OFFSET(UILevelUpGuideDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UILevelUpGuideDialog, m_1a8, 0x1a8);
MS2_CHECK_OFFSET(UILevelUpGuideDialog, m_1c8, 0x1c8);
MS2_CHECK_OFFSET(UILevelUpGuideDialog, m_1cc, 0x1cc);
MS2_CHECK_OFFSET(UILevelUpGuideDialog, m_1d8, 0x1d8);
MS2_CHECK_OFFSET(UILevelUpGuideDialog, m_1e0, 0x1e0);
