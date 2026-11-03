// Recovered UIQuestDebugDialog. Member names are invented where no original name survives.
#pragma once
#include "uigalleryeventdialog.h" // UIQuestEventListener declaration owned by this recovery agent
#include <atlcoll.h>
#include "ms2/placeholder/questdata.h"
#include "ms2/placeholder/ascorelist.h"
class ASCheckBox;
class Unk_QuestDebugDesc;
template<class T> class Unk_QuestDebugPtr
{
public:
    Unk_QuestDebugPtr();
    Unk_QuestDebugPtr(T*);
    Unk_QuestDebugPtr(const Unk_QuestDebugPtr&);
    Unk_QuestDebugPtr(Unk_QuestDebugPtr&&);
    ~Unk_QuestDebugPtr();
    Unk_QuestDebugPtr& operator=(Unk_QuestDebugPtr&&);
    Unk_QuestDebugPtr& operator=(T* p)
    {
        Unk_QuestDebugPtr tmp(p);
        T* old = m_p;
        m_p = tmp.m_p;
        tmp.m_p = old;
        return *this;
    }
    operator T*() const;
    T* operator->() const;
    bool operator==(T*) const;
    bool operator!() const;
private:
    void* m_0;
    T* m_p;
};
class UIQuestDebugDialog : public UIDialog, public UIQuestEventListener
{
public:
    UIQuestDebugDialog();
    virtual ~UIQuestDebugDialog();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual int vfunc_13();
    virtual void vfunc_45(Scaleform::GFx::Value*, const CString&, ASData*);
    virtual void vfunc_15();
    virtual void vfunc_o178_1(void*);
    virtual void vfunc_o178_2(void*);
    virtual void vfunc_o178_3(void*);
    virtual void vfunc_o178_7(int, int);
    virtual void vfunc_o178_8(void*);
    void FUN_141a95010();
    void FUN_141a95310(int, int);
    CStringW FUN_141a966a0(unsigned int);
    int FUN_141a96870(int);
    int FUN_141a96960(int, CStringW&, CStringW&, const CStringW&);
    int FUN_141a96c30(int, MS2Ptr<CQuestData>);
    // Unrecovered child-binding helpers; this is the original UISwfEntity subobject.
    MS2Ptr<ASCheckBox> FUN_140e52670(const CString&);
    Unk_QuestDebugPtr<Unk_QuestDebugDesc> FUN_140c26f60(const CString&);
    virtual int vfunc_48() { return 20043; }
private:
    MS2_LAYOUT_FRIEND;
    int m_chapter;
    int m_refresh;
    ATL::CAtlArray<unsigned int> m_ids;
    MS2Ptr<ASScrollingList> m_quests;
};
MS2_CHECK_SIZE(UIQuestDebugDialog, 0x1b8);
MS2_CHECK_OFFSET(UIQuestDebugDialog, m_chapter, 0x180);
MS2_CHECK_OFFSET(UIQuestDebugDialog, m_refresh, 0x184);
MS2_CHECK_OFFSET(UIQuestDebugDialog, m_ids, 0x188);
MS2_CHECK_OFFSET(UIQuestDebugDialog, m_quests, 0x1a8);
