// uitencentaas2dialog.h - UITencentAas2Dialog (RTTI .?AVUITencentAas2Dialog@@, 0x1d0 bytes, UI type 0x4f32?): the Tencent
// anti-addiction (AAS) notice page, a UIWebBrowserBase (uiupperhuddialog.h) that renders a web page into an image of its swf
// (a sibling of UITencentCashChargeDialog). Header name assumed from the unit path (?\uitencentaas2dialog.cpp,
// 0x140e988a0-0x140e99b90). Names invented from the callers: FUN_<va> are non-virtual members. w276.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uiupperhuddialog.h"

class ASUIComponent;
class Unk_AasImage;

// The smart pointer of the page image (16 bytes, pointee at +8): a MS2Ptr-shaped handle whose inline COMDATs are
// owned by this unit (the same shapes as MS2Ptr<T>; the dtor is the exe's 0x140d030a0 instance).
class Unk_AasImagePtr
{
public:
    Unk_AasImagePtr();                          // 0x140e999b0
    Unk_AasImagePtr(Unk_AasImage* p);           // 0x140e99980
    ~Unk_AasImagePtr();                         // 0x140d030a0 (earlier unit)
    Unk_AasImagePtr& operator=(int nNull);      // 0x140e999d0
    Unk_AasImagePtr& AssignRaw(Unk_AasImage* p);   // 0x140e99a00
    Unk_AasImage* get() const;                  // 0x140e99a70
    Unk_AasImage* operator->() const;           // 0x140e99a80
private:
    void AddRef() const;                        // 0x140e99b30
    void AddRefImpl(void*) const;               // 0x140e99b60
    void* m_0;
    Unk_AasImage* m_p;
};
MS2_CHECK_SIZE(Unk_AasImagePtr, 0x10);

class UITencentAas2Dialog : public UIWebBrowserBase
{
public:
    UITencentAas2Dialog();                                          // 0x140e988a0
    virtual ~UITencentAas2Dialog();                                 // 0x140e989c0 (??_G 0x140e99aa0, ??_E thunk 0x140e99a90)

    virtual CString GetTypeName();                                      //  1 0x140e98b20
    virtual void vfunc_8(int nVisible);                             //  8 0x140e98b70
    virtual void vfunc_16();                                        // 16 0x140e99320
    virtual void OnLoadComplete();                                  // 22 0x140e98cd0
    virtual void vfunc_26();                                        // 26 0x140e98f20
    virtual void vfunc_43();                                        // 43 0x140e99500
    virtual void vfunc_47(int n);                                   // 47 0x140e98ae0
    virtual int vfunc_48() { return 0x4f32; }                       // 48 (COMDAT 0x140e99ae0)
    virtual int vfunc_65();                                         // 65 0x140e99570
    virtual void vfunc_67();                                        // 67 0x140e98c40
    virtual void vfunc_68();                                        // 68 0x140e98ca0
    virtual void vfunc_85();                                        // 85 0x140e98f70
    virtual void vfunc_86();                                        // 86 0x140e99220
    virtual void vfunc_87(SIZE* pSize);                             // 87 0x140e995b0
    virtual bool vfunc_90(POINT* pPos);                             // 90 0x140e99360

    void FUN_140e98a50(CStringW strUrl, int nExitOnClose);          // set the page url and the exit-on-close flag

private:
    MS2_LAYOUT_FRIEND;
    MS2Ptr<ASUIComponent> FUN_140e48e10(const CString& strName, MS2Ptr<ASUIComponent>* pOut);   // finds the child and stores it in *pOut

    int m_nDialogWidth;                                             // +0x198
    int m_nDialogHeight;                                            // +0x19c
    MS2Ptr<ASUIComponent> m_spTarget;                               // +0x1a0 "m_renderTarget"
    Unk_AasImagePtr m_spImage;                                      // +0x1b0 the page image
    CString m_strPage;                                              // +0x1c0 the page url
    int m_nExitOnClose;                                             // +0x1c8 1: closing the notice quits the game
};
MS2_CHECK_SIZE(UITencentAas2Dialog, 0x1d0);
MS2_CHECK_OFFSET(UITencentAas2Dialog, m_spTarget, 0x1a0);
MS2_CHECK_OFFSET(UITencentAas2Dialog, m_spImage, 0x1b0);
MS2_CHECK_OFFSET(UITencentAas2Dialog, m_strPage, 0x1c0);
MS2_CHECK_OFFSET(UITencentAas2Dialog, m_nExitOnClose, 0x1c8);
