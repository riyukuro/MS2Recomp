// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item drop preview dialog.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
class CItem;
class Unk_DropList;
class Unk_DropText;
class Unk_DropButton;
class Unk_DropInput;
class Unk_DropSlot;
// The owning pointer has a same-type assignment COMDAT in this unit.
template <class T> class Unk_DropPtr {
public:
    Unk_DropPtr();
    Unk_DropPtr(T*);
    Unk_DropPtr(const Unk_DropPtr&);
    ~Unk_DropPtr();
    Unk_DropPtr& operator=(T*);
    Unk_DropPtr& operator=(const Unk_DropPtr&);
    bool operator==(T*) const;
    T* get() const;
    T* operator->() const;
private:
    void AddRef() const;
    void Release();
    void* m_00;
    T* m_p;
};
// Intrusive handle whose COMDATs are instantiated in this unit (T = Unk_DropSlot); the template name is unknown.
template <class T> class Unk_DropHandle {
public:
    Unk_DropHandle() : m_p(0) {}
    Unk_DropHandle(int) : m_p(0) {}
    Unk_DropHandle(T* p) : m_p(p) { AddRef(); }
    Unk_DropHandle(Unk_DropHandle& o) : m_p(o.m_p) { o.m_p = 0; }
    ~Unk_DropHandle() { Release(); }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
private:
    void AddRef() const { if (m_p) AddRefImpl(0); }
    static void Reference(T* p) { p->FUN_14015b020(); }
    void AddRefImpl(void*) const { Reference(m_p); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    void ReleaseImpl(void*) {
        if (m_p->FUN_140159bc0() == 0) {
            Reference(m_p);
            m_p->FUN_140159ba0();
        }
    }
    void* m_unused;
    T* m_p;
};
class UIItemDropInfoDialog : public UIDialog {
public:
    UIItemDropInfoDialog();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual void vfunc_49(Scaleform::GFx::Value*, ASData*);
    // @0x140c3c760
    virtual int vfunc_48() { return 0x4f74; }
    void FUN_140c3ad20();
    void FUN_140c3af70();
    CStringW FUN_140c3b5f0(int);
    int FUN_140c3b640();
    void FUN_140c3b6f0(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140c3b7d0(int item, int box);
    int FUN_140c3b920();
    Unk_DropPtr<Unk_DropList> FUN_140ba4b70(const CString&);
    template <class T> Unk_DropHandle<T> GetDropChild(const CString&);
private:
    MS2_LAYOUT_FRIEND;
    CString m_slot;
    MS2Ptr<CItem> m_item;
    ATL::CAtlArray<MS2Ptr<CItem>> m_items;
    int m_box;
    Unk_DropPtr<Unk_DropList> m_list;
    Unk_DropPtr<Unk_DropText> m_name;
    Unk_DropPtr<Unk_DropButton> m_test;
    Unk_DropPtr<Unk_DropButton> m_drop;
    Unk_DropPtr<Unk_DropInput> m_count;
};
MS2_CHECK_SIZE(UIItemDropInfoDialog, 0x208);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_slot, 0x178);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_item, 0x180);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_items, 0x190);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_box, 0x1b0);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_list, 0x1b8);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_count, 0x1f8);
