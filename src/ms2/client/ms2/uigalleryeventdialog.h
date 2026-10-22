// Recovered UIGalleryEventDialog. Unnamed helpers and members use invented names.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include "ms2/placeholder/itemslotbinder.h"

class Unk_GalleryContext;
template<class T> class Unk_GalleryPtr
{
public:
    Unk_GalleryPtr(const Unk_GalleryPtr&);
    ~Unk_GalleryPtr();
    T* operator->() const;
    bool operator!() const;
    bool operator==(T* p) const { return m_p == p; }
    operator T*() const { return m_p; }
private:
    void* m_0;
    T* m_p;
};
MS2_CHECK_SIZE(Unk_GalleryPtr<Unk_GalleryContext>, 0x10);
class UIQuestEventListener
{
public:
    UIQuestEventListener();
    virtual ~UIQuestEventListener();
    virtual void vfunc_o178_1(void*);
    virtual void vfunc_o178_2(void*);
    virtual void vfunc_o178_3(void*);
    virtual void vfunc_o178_4(void*);
    virtual void vfunc_o178_5(void*);
    virtual void vfunc_o178_6(void*);
    virtual void vfunc_o178_7(int, int);
    virtual void vfunc_o178_8(void*);
    virtual void vfunc_o178_9(void*);
    virtual void vfunc_o178_10(void*);
    virtual void vfunc_o178_11(void*);
    virtual void vfunc_o178_12(void*);
};
MS2_CHECK_SIZE(UIQuestEventListener, 8);
class Unk_GalleryPacket;
class UIGalleryEventDialog : public UIDialog, public UIQuestEventListener
{
public:
    UIGalleryEventDialog();
    virtual ~UIGalleryEventDialog();
    virtual CString GetTypeName();
    virtual int vfunc_65();
    virtual void vfunc_67();
    virtual void OnLoadComplete();
    virtual int vfunc_13();
    virtual void vfunc_45(Scaleform::GFx::Value*, const CString&, ASData*);
    virtual int vfunc_28(const char*, const Scaleform::GFx::Value*, unsigned int);
    virtual void vfunc_o178_10(void*);
    void FUN_140c17200(unsigned int, Unk_GalleryPacket*);
    int FUN_140c17560();
    void FUN_140c176f0(Unk_GalleryPtr<Unk_GalleryContext>);
    void FUN_140c17d20(Unk_GalleryPtr<Unk_GalleryContext>);
    void FUN_140c181a0(int);
    void FUN_140c18330();
    void FUN_140c18460();
    void SendEventRewardMode7(int);
    void SendEventRewardMode8(int);
    void SendEventRewardMode9();
    int FUN_140c187e0();
    CString FUN_140c189d0(int);
    int FUN_140c18ab0(int);
    int FUN_140c18c60(int);
    void FUN_140c18e10(int, int);
    bool FUN_140c18f10();
    virtual int vfunc_48() { return 20313; }
private:
    MS2_LAYOUT_FRIEND;
    ItemSlotBinder m_binder;
};
MS2_CHECK_SIZE(UIGalleryEventDialog, 0x1c0);
MS2_CHECK_OFFSET(UIGalleryEventDialog, m_binder, 0x180);
