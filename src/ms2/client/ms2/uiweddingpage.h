// uiweddingpage.h - UIWeddingPage (RTTI .?AVUIWeddingPage@@, 0x30 bytes, CPtred) and its three pages: the tabs of
// UIWeddingDialog (message, skill, mission). A page is held by MS2Ptr and keyed by its vfunc_6() name in the dialog's
// page map. Created by ?\uiweddingdialog.cpp (the dialog only needs the constructors, the size and the vftable
// slots); the owning unit ?\uiweddingpage.cpp (0x140fe7390-0x140fe9d00) extends it. Member names are invented.
#pragma once
#include <afx.h>
#include "ms2/ms2layout.h"
#include "ms2/placeholder/cptred.h"

class UIWeddingDialog;
class ASData;
namespace Scaleform { namespace GFx { class Value; } }

class UIWeddingPage : public CPtred
{
public:
    UIWeddingPage(UIWeddingDialog* pDialog);                    // 0x140fe7390
    virtual ~UIWeddingPage();                                   //  0 0x140fe98c0 (??_G)
    virtual void vfunc_1();                                     //  1 0x140fe7440 the page is shown
    virtual void vfunc_2();                                     //  2 0x140fe75a0 the page is hidden
    virtual char vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 3 0x140fe75d0 handle a movie call
    virtual void vfunc_4();                                     //  4 0x140fe75f0
    virtual void vfunc_5(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 5 0x140fe7600
    virtual CString vfunc_6() = 0;                              //  6 the page key
    virtual CStringW vfunc_7() = 0;                              //  7 the tab label
private:
    MS2_LAYOUT_FRIEND;
    char m_pad18[0x10];                                         // +0x18
    UIWeddingDialog* m_28;                                      // +0x28 the owner
};
MS2_CHECK_SIZE(UIWeddingPage, 0x30);
MS2_CHECK_OFFSET(UIWeddingPage, m_28, 0x28);

class UIWeddingPageMessage : public UIWeddingPage
{
public:
    UIWeddingPageMessage(UIWeddingDialog* pDialog);             // 0x140fe7690
    virtual ~UIWeddingPageMessage();
    virtual void vfunc_1();
    virtual char vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual CString vfunc_6();
    virtual CStringW vfunc_7();
};
MS2_CHECK_SIZE(UIWeddingPageMessage, 0x30);

class UIWeddingPageSkill : public UIWeddingPage
{
public:
    UIWeddingPageSkill(UIWeddingDialog* pDialog);               // 0x140fe7d30
    virtual ~UIWeddingPageSkill();
    virtual void vfunc_1();
    virtual char vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_5(Scaleform::GFx::Value* pRetVal, ASData* pArgs);
    virtual CString vfunc_6();
    virtual CStringW vfunc_7();
};
MS2_CHECK_SIZE(UIWeddingPageSkill, 0x30);

// The second base (UIQuestEventListener at +0x30) and the ItemSlotBinder at +0x38 are left to the owner unit.
class UIWeddingPageMission : public UIWeddingPage
{
public:
    UIWeddingPageMission(UIWeddingDialog* pDialog);             // 0x140fe8950
    virtual ~UIWeddingPageMission();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);
    virtual void vfunc_5(Scaleform::GFx::Value* pRetVal, ASData* pArgs);
    virtual CString vfunc_6();
    virtual CStringW vfunc_7();
private:
    char m_pad30[0x78 - 0x30];
};
MS2_CHECK_SIZE(UIWeddingPageMission, 0x78);
