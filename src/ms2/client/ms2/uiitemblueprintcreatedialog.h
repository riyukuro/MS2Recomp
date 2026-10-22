// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Header name assumed.
#pragma once
#include "ms2/placeholder/uidialog.h"
#include <utility>
class Unk_BpButton;
class Unk_BpInput;
class CUgcUploadCtrl;
class CUgcViewerBlueprintImage;
class Unk_BpViewerBase;
class Unk_BpImage;
class Unk_BpItem;
class CMsgBoxData;
enum Unk_BpCurrency { Unk_BpCurrency_Default = 1 };
// Unit-local intrusive pointer family. Names are invented; the template instances occur in this CU.
class Unk_BpRefCount {
public: void FUN_14015b020(); int FUN_140159bc0(); void FUN_140159ba0();
};
template<class T> class Unk_BpPtr {
    template<class U> friend class Unk_BpPtr;
public:
    Unk_BpPtr() : p(0) {}
    Unk_BpPtr(int) : p(0) {}
    Unk_BpPtr(T* ptr) : p(ptr) { AddRef(); }
    Unk_BpPtr(const Unk_BpPtr& other) : p(other.p) { AddRef(); }
    ~Unk_BpPtr() { Release(); }
    Unk_BpPtr& operator=(int) { Release(); return *this; }
    Unk_BpPtr& operator=(T* ptr) { Unk_BpPtr temp(ptr); T* old = p; p = temp.p; temp.p = old; return *this; }
    Unk_BpPtr& operator=(const Unk_BpPtr& other) { other.AddRef(); Release(); p = other.p; return *this; }
    template<class U> Unk_BpPtr& operator=(const Unk_BpPtr<U>& other) { other.AddRef(); Release(); p = other.p; return *this; }
    bool operator==(T* ptr) const { return p == ptr; }
    T* get() const { return p; }
    T* operator->() const { return p; }
private:
    static void AddRefObject(T* ptr) { reinterpret_cast<Unk_BpRefCount*>(ptr)->FUN_14015b020(); }
    void AddRefImpl(void*) const { AddRefObject(p); }
    void ReleaseImpl(void*) {
        if (reinterpret_cast<Unk_BpRefCount*>(p)->FUN_140159bc0() == 0) {
            AddRefObject(p);
            reinterpret_cast<Unk_BpRefCount*>(p)->FUN_140159ba0();
        }
    }
    void AddRef() const { if (p) AddRefImpl((void*)0); }
    void Release() { if (p) { ReleaseImpl((void*)0); p = 0; } }
    void* pad;
    T* p;
};
MS2_CHECK_SIZE(Unk_BpPtr<CUgcUploadCtrl>, 0x10);
class UIItemBlueprintCreateDialog : public UIDialog {
public:
    UIItemBlueprintCreateDialog();
    virtual ~UIItemBlueprintCreateDialog();
    virtual CString GetTypeName();
    virtual void OnLoadComplete();
    virtual void vfunc_26();
    virtual void vfunc_72();
    virtual int vfunc_48() { return 0x4f7b; }
    void FUN_140c36b40(Unk_BpItem*);
    void FUN_140c36fe0(__int64);
    void FUN_140c370a0(const int&, Unk_BpPtr<Unk_BpImage>);
    void FUN_140c37360(Unk_BpPtr<Unk_BpImage>, const int&);
    void FUN_140c374b0();
    void FUN_140c37540(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140c37620(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140c37700(const Scaleform::GFx::FunctionHandler::Params&);
    void FUN_140c37c60(const Scaleform::GFx::FunctionHandler::Params&);
    bool FUN_140c37d50(int, const CMsgBoxData&);
    bool FUN_140c37f90(int, const CMsgBoxData&);
    CStringW FUN_140c38080();
    void FUN_140c38150();
    void FUN_140c381b0(Unk_BpPtr<Unk_BpImage>);
    void FUN_140c38240();
    void FUN_140c38400();
private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<Unk_BpButton> m_addIcon, m_addImage, m_create;
    MS2Ptr<Unk_BpInput> m_input;
    int m_type;
    Unk_BpPtr<CUgcUploadCtrl> m_upload;
    MS2Ptr<Unk_BpItem> m_item;
    Unk_BpPtr<Unk_BpImage> m_icon, m_image;
    std::pair<Unk_BpCurrency, __int64> m_fee;
    __int64 m_itemId;
    int m_ready, m_dirty;
};
MS2_CHECK_SIZE(UIItemBlueprintCreateDialog, 0x220);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_addIcon, 0x178);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_type, 0x1b8);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_upload, 0x1c0);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_item, 0x1d0);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_fee, 0x200);
MS2_CHECK_OFFSET(UIItemBlueprintCreateDialog, m_itemId, 0x210);
