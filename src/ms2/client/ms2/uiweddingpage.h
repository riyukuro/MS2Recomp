// uiweddingpage.h - UIWeddingPage (RTTI .?AVUIWeddingPage@@, 0x30 bytes, CPtred) and its three pages: the tabs of
// UIWeddingDialog (message, skill, mission). A page is held by MS2Ptr and keyed by its vfunc_6() name in the dialog's
// page map. Created by ?\uiweddingdialog.cpp (the dialog only needs the constructors, the size and the vftable
// slots); the owning unit ?\uiweddingpage.cpp (0x140fe7390-0x140fe9d00) extends it. Member names are invented.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/itemslotbinder.h"
#include "ms2/client/ms2/uigalleryeventdialog.h"     // UIQuestEventListener (13 slots)

class CMsgBoxData;
class UIWeddingDialog;
class ASData;
namespace Scaleform { namespace GFx { class Value; } }

class UIWeddingPage : public CPtred
{
public:
    UIWeddingPage(UIWeddingDialog* pDialog);                    // 0x140fe7390
    virtual ~UIWeddingPage();                                   //  0 0x140fe98c0 (??_G)
    virtual bool vfunc_1();                                     //  1 0x140fe7440 the page is shown (binds "m_currentPage")
    virtual void vfunc_2();                                     //  2 0x140fe75a0 the page is hidden
    virtual bool vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 3 0x140fe75d0 handle a movie call
    virtual void vfunc_4();                                     //  4 0x140fe75f0
    virtual void vfunc_5(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 5 0x140fe7600
    virtual CString vfunc_6() = 0;                              //  6 the page key
    virtual CStringW vfunc_7() = 0;                              //  7 the tab label
    MS2Ptr<AScript> FUN_140fe7620() const;                      // 0x140fe7620 the page movie clip
    UIWeddingDialog* FUN_140fe7670() const;                     // 0x140fe7670 the owner

protected:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<AScript> m_pScript;                                  // +0x18 the page movie clip ("m_currentPage")
    UIWeddingDialog* m_28;                                      // +0x28 the owner
};
MS2_CHECK_SIZE(UIWeddingPage, 0x30);
MS2_CHECK_OFFSET(UIWeddingPage, m_28, 0x28);

class UIWeddingPageMessage : public UIWeddingPage
{
public:
    UIWeddingPageMessage(UIWeddingDialog* pDialog);             // 0x140fe7690
    virtual ~UIWeddingPageMessage();
    virtual bool vfunc_1();
    virtual bool vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual CString vfunc_6();
    virtual CStringW vfunc_7();

    bool FUN_140fe7c60(int nResult, const CMsgBoxData& box);   // 0x140fe7c60 couple message confirmed
};
MS2_CHECK_SIZE(UIWeddingPageMessage, 0x30);

class UIWeddingPageSkill : public UIWeddingPage
{
public:
    UIWeddingPageSkill(UIWeddingDialog* pDialog);               // 0x140fe7d30
    virtual ~UIWeddingPageSkill();
    virtual bool vfunc_1();
    virtual bool vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_5(Scaleform::GFx::Value* pRetVal, ASData* pArgs);
    virtual CString vfunc_6();
    virtual CStringW vfunc_7();
};
MS2_CHECK_SIZE(UIWeddingPageSkill, 0x30);

// The second base (UIQuestEventListener at +0x30) and the ItemSlotBinder at +0x38. Mission rows are the quests of the
// quest manager; slot 12 of the listener refreshes the list.
class UIWeddingPageMission : public UIWeddingPage, public UIQuestEventListener
{
public:
    UIWeddingPageMission(UIWeddingDialog* pDialog);             // 0x140fe8950
    virtual ~UIWeddingPageMission();
    virtual bool vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_5(Scaleform::GFx::Value* pRetVal, ASData* pArgs);
    virtual CString vfunc_6();
    virtual CStringW vfunc_7();
    virtual void vfunc_o178_12(void* pQuest);                   // 0x140fe8e20 (listener slot 12) refresh the list

    void FUN_140fe8e50(int nQuestId);                           // 0x140fe8e50 turn in a completed quest
    void FUN_140fe8fb0();                                       // 0x140fe8fb0 fill "m_list" with the quests

private:
    ItemSlotBinder m_binder;                                    // +0x38
};
MS2_CHECK_SIZE(UIWeddingPageMission, 0x78);
