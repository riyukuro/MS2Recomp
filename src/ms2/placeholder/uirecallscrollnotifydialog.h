// uirecallscrollnotifydialog.h - UIRecallScrollNotifyDialog (RTTI .?AVUIRecallScrollNotifyDialog@@, 0x218 bytes, UI
// type 0x4edd "RecallScrollNotifyDialog"): the bottom-centre popups that ask whether to follow a party / guild / wedding
// recall scroll. Three slots (0 guild, 1 party, 2 wedding): the expiry time, the sender name, the field id and the
// movie clip ("m_guildNotify" / "m_partyNotify" / "m_weddingNotify"). Header name assumed (the class name); it lives
// under placeholder/ because ?\uibottomcenteralignmanager.cpp includes it. Ctor 0x14129ba60 (uiservice.cpp creates it).
// Names of members are invented.
#pragma once

#include <afx.h>
#include <atltime.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uibuiltindialog.h"
#include "ms2/placeholder/mstime.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/client/ms2/uiquesteventlistener.h"       // Unk_DTTick

class UIRecallScrollNotifyDialog : public UIBuiltInDialog
{
public:
    UIRecallScrollNotifyDialog();                           // 0x14129ba60
    virtual ~UIRecallScrollNotifyDialog();                  //  0 0x14129cdc0 (??_G 0x14129ce30)
    virtual CString vfunc_1();                              //  1 0x14129bc10
    virtual void OnLoadInit();                              // 20 0x14129bd50
    virtual void OnLoadComplete();                          // 22 0x14129bdd0
    virtual void vfunc_26();                                // 26 0x14129bd70 forget the clips
    virtual void vfunc_43();                                // 43 0x14129c0b0 place the movie above the bottom bar
    virtual int vfunc_13();                                 // 13 0x14129c140
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x14129c170
    virtual int vfunc_65();                                 // 65 0x14129bc60
    virtual void vfunc_67();                                // 67 0x14129bc90 close: forget the three requests
    virtual void vfunc_72();                                // 72 0x14129c610 per second: count down the popups
    virtual int vfunc_48() { return 0x4edd; }               // 48 (COMDAT 0x14129ce70)

    void SetOffset(int nOffset);                        // 0x14129c8e0 stores the int at +0x208
    bool IsActive();                                   // 0x14129c900 returns the byte at +0x20c
    void FUN_14129c920(int nSlot, __time64_t nTime, const CStringW& strName, int nField);   // open a popup
    void FUN_14129caa0(int nSlot);                          // close a popup
    void FUN_14129cb20();                                   // forget the three expiry times
    CStringW FUN_14129cb50(ATL::CTimeSpan span);            // "mm:ss", red when under 11 seconds
    void FUN_14129cc60(bool bActive);                       // 0x14129cc60 m_active, restack the bottom-centre dialogs
    MS2Ptr<ASMovieClip> FUN_140ba4b70(const CString& strName);  // child lookup

private:
    MS2_LAYOUT_FRIEND;
    Unk_DTTick m_tick;                                      // +0x178 1 s timer
    CMsTime m_times[3];                                     // +0x180 expiry of each popup (0 = none)
    CStringW m_names[3];                                    // +0x1b0 sender name
    int m_fields[3];                                        // +0x1c8 field id
    MS2Ptr<ASMovieClip> m_clips[3];                         // +0x1d8
    int m_nOffset;                                          // +0x208 (SetOffset)
    bool m_bActive;                                         // +0x20c (IsActive)
    int m_nCount;                                           // +0x210 popups showing
};
MS2_CHECK_SIZE(UIRecallScrollNotifyDialog, 0x218);
MS2_CHECK_OFFSET(UIRecallScrollNotifyDialog, m_tick, 0x178);
MS2_CHECK_OFFSET(UIRecallScrollNotifyDialog, m_times, 0x180);
MS2_CHECK_OFFSET(UIRecallScrollNotifyDialog, m_names, 0x1b0);
MS2_CHECK_OFFSET(UIRecallScrollNotifyDialog, m_fields, 0x1c8);
MS2_CHECK_OFFSET(UIRecallScrollNotifyDialog, m_clips, 0x1d8);
MS2_CHECK_OFFSET(UIRecallScrollNotifyDialog, m_nOffset, 0x208);
MS2_CHECK_OFFSET(UIRecallScrollNotifyDialog, m_bActive, 0x20c);
MS2_CHECK_OFFSET(UIRecallScrollNotifyDialog, m_nCount, 0x210);
