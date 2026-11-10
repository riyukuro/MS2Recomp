// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Item drop preview dialog.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/ascript.h"
class CItem;
class ASTileList;
class ASTextField;
class ASButton;
class ASTextInput;
// Intrusive handle whose COMDATs are instantiated in this unit (T = ASMDragTarget); the template name is unknown.
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
    static void Reference(T* p) { CPtred::AddRefPtred(p); }
    void AddRefImpl(void*) const { Reference(m_p); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    void ReleaseImpl(void*) {
        if (CPtred::ReleasePtred(m_p) == 0) {
            Reference(m_p);
            CPtred::DeletePtred(m_p);
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
    void UpdateItemDisplay();
    void FUN_140c3af70();
    CStringW GetStringById(int);
    int GetDropCount();
    void OnClickDropOrTestButton(const Scaleform::GFx::FunctionHandler::Params&);
    void SetItemAndBox(int item, int box);
    int GetItemId();
    template <class T> Unk_DropHandle<T> GetDropChild(const CString&);
private:
    MS2_LAYOUT_FRIEND;
    CString m_slot;
    MS2Ptr<CItem> m_item;
    ATL::CAtlArray<MS2Ptr<CItem>> m_items;
    int m_box;
    MS2Ptr<ASTileList> m_list;
    MS2Ptr<ASTextField> m_name;
    MS2Ptr<ASButton> m_test;
    MS2Ptr<ASButton> m_drop;
    MS2Ptr<ASTextInput> m_count;
};
MS2_CHECK_SIZE(UIItemDropInfoDialog, 0x208);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_slot, 0x178);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_item, 0x180);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_items, 0x190);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_box, 0x1b0);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_list, 0x1b8);
MS2_CHECK_OFFSET(UIItemDropInfoDialog, m_count, 0x1f8);
