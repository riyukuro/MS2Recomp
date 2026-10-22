// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Community text ticker.
#pragma once
#include <atlcoll.h>
#include "ms2/placeholder/uiheadupdisplay.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/delegate.h"

// Unit-local intrusive wrapper: the owned value is the second base of TPtredDummy.
#include "ms2/placeholder/tptreddummy.h"
void FUN_14015b020(CPtred*);
int FUN_140159bc0(CPtred*);
void FUN_140159ba0(CPtred*);
CPtred* FUN_1401ba820(CPtred*);
struct Unk_PopupNewTag { explicit Unk_PopupNewTag(int); };
template<class T> class Unk_PopupPtr {
public:
    Unk_PopupPtr(Unk_PopupPtr&& p) : m_p(p.m_p) { p.m_p = 0; }
    Unk_PopupPtr(const Unk_PopupPtr& p) : m_p(p.m_p) { AddRef(); }
    Unk_PopupPtr(const Unk_PopupNewTag&) : m_p(0) { Make(); }
    ~Unk_PopupPtr() { Release(); }
    T* get() const { return m_p; }
    T* operator->() const { return m_p; }
private:
    void AddRef() const { if (m_p) AddRefImpl(0); }
    void Make() { Release(); m_p = Create(0); }
    void Release() { if (m_p) { ReleaseImpl(0); m_p = 0; } }
    // The blank lines keep the tags below from being claimed by the untagged functions above (6-line window).







    // @0x140beb080
    static TPtredDummy<T>* Allocate(void*) { return new TPtredDummy<T>(); }
    // @0x140beb570
    static T* Value(TPtredDummy<T>* p) { return p == NULL ? NULL : &p->value; }
    // @0x140beb7b0
    static TPtredDummy<T>* Owner(T* p) { return p == NULL ? NULL : reinterpret_cast<TPtredDummy<T>*>(reinterpret_cast<char*>(p) - offsetof(TPtredDummy<T>, value)); }
    // @0x140bebc20
    static void Ref(CPtred* p) { FUN_14015b020(p); }
    // @0x140bebca0
    static T* Create(void*) { return Value(static_cast<TPtredDummy<T>*>(FUN_1401ba820(Allocate(0)))); }
    // @0x140bebc40
    void AddRefImpl(void*) const { Ref(Owner(m_p)); }
    // @0x140bebd10
    void ReleaseImpl(void*) {
        CPtred* owner = Owner(m_p);
        if (FUN_140159bc0(owner) == 0) { Ref(owner); FUN_140159ba0(owner); }
    }
    void* m_00;
    T* m_p;
};
class Unk_PopupMovie;
class Unk_PopupField;
class UICommunityPopup : public UIHeadUpDisplay {
public:
    struct PopupText { CStringW text; CString url; };
    UICommunityPopup();
    virtual ~UICommunityPopup();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual void vfunc_15();
    virtual void vfunc_43();
    // @0x140beb940
    virtual int vfunc_48() { return 0x4f5c; }
    void FUN_140bea390(CStringW text, CString url);
    void FUN_140bea540();
    void FUN_140bea6b0();
    void FUN_140bea730();
    void FUN_140bea960(const Scaleform::GFx::FunctionHandler::Params&);
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_PopupMovie> m_movie;
    MS2Ptr<Unk_PopupField> m_field;
    CString m_url;
    CStringW m_text;
    bool m_pending;
    float m_speed;
    float m_x;
    int m_y;
    int m_width;
    __int64 m_time;
    ATL::CAtlList<Unk_PopupPtr<PopupText>> m_queue;
};
MS2_CHECK_SIZE(UICommunityPopup, 0xf0);
MS2_CHECK_OFFSET(UICommunityPopup,m_movie,0x70);
MS2_CHECK_OFFSET(UICommunityPopup,m_field,0x80);
MS2_CHECK_OFFSET(UICommunityPopup,m_url,0x90);
MS2_CHECK_OFFSET(UICommunityPopup,m_text,0x98);
MS2_CHECK_OFFSET(UICommunityPopup,m_pending,0xa0);
MS2_CHECK_OFFSET(UICommunityPopup,m_speed,0xa4);
MS2_CHECK_OFFSET(UICommunityPopup,m_x,0xa8);
MS2_CHECK_OFFSET(UICommunityPopup,m_y,0xac);
MS2_CHECK_OFFSET(UICommunityPopup,m_width,0xb0);
MS2_CHECK_OFFSET(UICommunityPopup,m_time,0xb8);
MS2_CHECK_OFFSET(UICommunityPopup,m_queue,0xc0);
