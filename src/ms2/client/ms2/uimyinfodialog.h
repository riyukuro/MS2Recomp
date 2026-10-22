// uimyinfodialog.h - UIMyInfoDialog (RTTI .?AVUIMyInfoDialog@@, 0x308 bytes, UI id 0x2711): the player's own character info
// window (equipment / gem pages, stat points, title, today's memo, the codi tab period, the screenshot upload). Bases:
// UIPCInfoDialog (+0x0, placeholder/uipcinfodialog.h) and the four listeners UIItemEventListener (+0x1e8),
// UIStatusEventListener (+0x1f0), UIDialogEventListener (+0x1f8) and UIEntityEventListener (+0x200); the other
// listeners of UIPCInfoDialog (UIUGCEventListener +0x178, IUIAvatarEventListener +0x180) are overridden by it.
// Owning unit: client\ms2\uimyinfodialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/client/ms2/uipcinfodialog.h"
// UIItemEventListener::vfunc_23 and UISwfEntity::vfunc_23 share a name and signature; the dialog overrides only the
// listener's slot (see uistatcontroldialog.h), so the listener's slot is renamed here.
#define vfunc_23 vfunc_il23
#include "ms2/placeholder/uiitemeventlistener.h"
#undef vfunc_23
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uidialogeventlistener.h"
// UIItemEventListener and UIEntityEventListener both have a slot 5 (void*, int); the entity listener's is renamed.
#define vfunc_5 vfunc_el5
#include "ms2/placeholder/uientityeventlistener.h"
#undef vfunc_5
#include "ms2/commonfiles/timer.h"
#include "ms2/commonfiles/imagehttpclient.h"
#include "ms2/placeholder/astextfield.h"
#include "ms2/placeholder/asbutton.h"

class NotifyObject;
class CMsgBoxData;

class UIMyInfoDialog : public UIPCInfoDialog, public UIItemEventListener, public UIStatusEventListener,
                       public UIDialogEventListener, public UIEntityEventListener
{
public:
    UIMyInfoDialog();                                           // 0x141a58040
    // ~UIMyInfoDialog: implicit (0x141a5de20, ??_G 0x141a5dfd0): the exe dtor does not re-store the vftables
    virtual int vfunc_13();                                     // 13 0x141a593c0
    virtual void vfunc_15();                                    // 15 0x141a593e0 per-frame update
    virtual void vfunc_16();                                    // 16 0x141a5d3e0
    virtual bool vfunc_17();                                    // 17 0x141a5d410
    virtual void OnLoadInit();                                  // 20 0x141a58c80
    virtual void OnLoadComplete();                              // 22 0x141a58ca0
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);   // 25 0x141a5d0c0 drop an item on the avatar
    virtual void vfunc_26();                                    // 26 0x141a58b90
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141a595a0
    virtual void vfunc_43();                                    // 43 0x141a58be0
    virtual int vfunc_46();                                     // 46 0x141a5a610
    virtual int vfunc_48() { return 0x2711; }                   // 48 0x141a5e010
    virtual int vfunc_65();                                     // 65 0x141a58310
    virtual void vfunc_67();                                    // 67 0x141a58630
    virtual void vfunc_84();                                    // 84 0x141a5ae40
    virtual void vfunc_87();                                    // 87 0x141a5d060
    virtual void vfunc_90(int nTab);                            // 90 0x141a5b3b0
    virtual void vfunc_91(int n);                               // 91 0x141a5af10 one more point on a stat
    virtual void vfunc_92();                                    // 92 0x141a5b2c0
    virtual int vfunc_93();                                     // 93 0x141a5b470 may the skill book be changed now
    virtual void vfunc_99(const CStringW& strMemo);             // 99 0x141a5b690
    virtual void vfunc_104(int n);                              // 104 0x141a5ae90 the trophy count

    // IUIAvatarEventListener (+0x180)
    virtual int vfunc_o178_1(void* pAvatar);                    // 0x141a5d450 the avatar is ready: show the action list

    // UIItemEventListener (+0x1e8)
    virtual int vfunc_il1();                                    //  1 0x141a58270
    virtual void vfunc_21(void* p);                             // 21 0x141a59bd0
    virtual void vfunc_22(void* p);                             // 22 0x141a59cf0
    virtual void vfunc_il23(void* p);                           // 23 0x141a59d80
    virtual void vfunc_30(void* p);                             // 30 0x141a59fa0
    virtual void vfunc_31(void* p);                             // 31 0x141a5a090
    virtual void vfunc_32(void* p, int a, int b);               // 32 0x141a5a190
    virtual void vfunc_33(int nClass, int n);                   // 33 0x141a5a260

    // UIStatusEventListener (+0x1f0)
    virtual int vfunc_oa0_1();                                  //  1 0x141a582c0
    virtual void vfunc_oa0_2();                                 //  2 0x141a599a0
    virtual void vfunc_oa0_3(int a1, int a2);                   //  3 0x141a599d0
    virtual void vfunc_oa0_4(int a1, int a2);                   //  4 0x141a59a00
    virtual void vfunc_oa0_5(int a1, int a2);                   //  5 0x141a59a30
    virtual void vfunc_oa0_6(void* a1, void* a2);               //  6 0x141a59a60
    virtual void vfunc_oa0_7(int a1, CStringW s);               //  7 0x141a59b20
    virtual void vfunc_oa0_9(unsigned short a1);                //  9 0x141a59aa0
    virtual void vfunc_oa0_10(CStringW s);                      // 10 0x141a59ad0
    virtual void vfunc_oa0_29();                                // 29 0x141a59b70
    virtual void vfunc_oa0_30(int a1);                          // 30 0x141a59ba0

    // UIDialogEventListener (+0x1f8)
    virtual void vfunc_dl_3(void* p);                           //  3 0x141a5a320 an item drag starts
    virtual void vfunc_dl_4(void* p);                           //  4 0x141a5a4e0 the drag ends

    // UIEntityEventListener (+0x200)
    virtual void vfunc_el5(void* p, int n);                     //  5 0x141a5a1e0

    MS2Ptr<ASMovieClip> FUN_140ba7930(const CString& strName);  // 0x140ba7930 movie clip child lookup
    MS2Ptr<ASButton> FUN_140bb4b10(const CString& strName);     // 0x140bb4b10 button child lookup
    void FUN_141a5a560();                                       // mark the window dirty (refresh in 100 ms)
    void FUN_141a5a5c0();                                       // mark dirty and the second refresh flag
    void FUN_141a5a640(NotifyObject* pNotify);                  // NotifyChangeBuff
    void OnChangeProfile();                                       // OnChangeProfile
    void OnChangeTodayMemo();                                       // OnChangeTodayMemo
    void FUN_141a5a8d0(int nTitle);                             // OnTitleChange
    void FUN_141a5a9f0(int nConfig);                            // OnConfig
    void FUN_141a5aab0(int a, int b, int c, int d);             // OnScreenshot
    void FUN_141a5ab10(int bRefresh, int bTabs, int bStats);    // rebuild the shown PCInfo from the player
    void FUN_141a5ac90(unsigned short nLevel);                  // the symbol of the level
    void FUN_141a5b080(int nStat);                              // OnAddStatPointRepeat
    void FUN_141a5b6c0();                                       // the remaining time of the codi tab
    void FUN_141a5bed0();                                       // the active codi tab changed
    void FUN_141a5c080();                                       // first read of the active codi tab
    void FUN_141a5c1a0(NotifyObject* pNotify);                  // NotifyChangeBuff -> period
    void FUN_141a5c220(NotifyObject* pNotify);                  // NotifyActiveMyCodiTab -> active
    void FUN_141a5c2a0(NotifyObject* pNotify);                  // NotifyPcBang
    bool FUN_141a5c3a0();                                       // may the window refresh now
    void FUN_141a5c410(int nTab, int nNewTab);                  // ask whether the codi tab may change
    bool FUN_141a5c640(int nButton, const CMsgBoxData& kData);  // the answer of the codi tab question
    int GetTab();                                        // the info mode
    void FUN_141a5c7c0(int nStat);                              // show one stat point row
    void FUN_141a5cf30(int nStat);                              // OnAddStatPointStop
    void FUN_141a5d5d0();                                       // loadRenderTarget
    void FUN_141a5d630();                                       // unloadRenderTarget
    void FUN_141a5d690(const Scaleform::GFx::FunctionHandler::Params& params);   // the closet button

    MS2_LAYOUT_FRIEND;
    int m_208;                                                  // +0x208 refresh pending
    int m_20c;                                                  // +0x20c the second refresh flag
    bool m_210;                                                 // +0x210 a buff changed
    Timer m_218;                                                // +0x218 the refresh delay
    int m_250;                                                  // +0x250 stat points added but not sent
    bool m_254;                                                 // +0x254 the points were sent
    MS2Ptr<ASTextField> m_258;                                  // +0x258 the codi tab period text
    Unk_IntervalTimer m_268;                                             // +0x268 the period tick holder
    bool m_270;                                                 // +0x270 a period is shown
    int m_274;                                                  // +0x274 its refresh interval (ms)
    bool m_278;                                                 // +0x278 the active codi tab flag
    MS2Ptr<ASButton> m_280;                                     // +0x280 "m_closet"
    CImageHttpClient m_290;                                     // +0x290
};
MS2_CHECK_SIZE(UIMyInfoDialog, 0x308);
MS2_CHECK_OFFSET(UIMyInfoDialog, m_208, 0x208);
MS2_CHECK_OFFSET(UIMyInfoDialog, m_218, 0x218);
MS2_CHECK_OFFSET(UIMyInfoDialog, m_250, 0x250);
MS2_CHECK_OFFSET(UIMyInfoDialog, m_258, 0x258);
MS2_CHECK_OFFSET(UIMyInfoDialog, m_268, 0x268);
MS2_CHECK_OFFSET(UIMyInfoDialog, m_270, 0x270);
MS2_CHECK_OFFSET(UIMyInfoDialog, m_280, 0x280);
MS2_CHECK_OFFSET(UIMyInfoDialog, m_290, 0x290);
