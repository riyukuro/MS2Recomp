// uiugcbannerdialog.h - UIUGCBannerDialog (RTTI .?AVUIUGCBannerDialog@@, 0x248 bytes, UI id 0x4e70, swf "UGCBannerDialog") and
// UIUGCCameraDialog (RTTI .?AVUIUGCCameraDialog@@, 0x1a0 bytes, UI id 0x4e5b, swf "UGCCameraDialog").
// The banner dialog picks the image file and the hours of a field banner (the preview and upload of a banner image, the
// reservation of its hourly slots on a day); the camera dialog takes the profile snapshot of the player and saves it as
// the thumbnail file. The unit also holds the UIUGCEventListener / UIUGCEventDispatcher bodies and the ATL glue of the
// listener array. Bases of the banner dialog: UIDialog, UIStatusEventListener (+0x178) and UIUGCEventListener (+0x180).
// Owning unit: ?\uiugcbannerdialog.cpp. Header name assumed from the unit path; member names are invented from use.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/client/ms2/uidialog.h"
#include "ms2/placeholder/uistatuseventlistener.h"
#include "ms2/placeholder/uiugceventlistener.h"

class CUgcPreReserve;
class Unk_WcTitle;

// The broken-down time (0x30 bytes, unit_14088dbf0) built by FUN_14088dfa0(out, time, hourOffset).
struct Unk_DateParts
{
    void* m_00;
    int m_date;                                                 // +0x08 YYYYMMDD
    int m_hour;                                                 // +0x0c
    void* m_time;
    int m_year;
    int m_month;
    int m_day;
    int m_dow;
    int m_hour2;
    int m_minute;
    CStringW FUN_14088e040();                                   // the date as text
};
MS2_CHECK_SIZE(Unk_DateParts, 0x30);

class UIUGCBannerDialog : public UIDialog, public UIStatusEventListener, public UIUGCEventListener
{
public:
    UIUGCBannerDialog();                                        // 0x141b34100
    virtual ~UIUGCBannerDialog();                               //  0 0x141b34270 (??_G 0x141b36e40)
    virtual CString vfunc_1();                                  //  1 0x141b34320 "UGCBannerDialog"
    virtual void OnLoadInit();                                  // 20 0x141b346a0
    virtual void OnLoadComplete();                              // 22 0x141b34850
    virtual void vfunc_26();                                    // 26 0x141b348d0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b34b60
    virtual int vfunc_48() { return 0x4e70; }                   // 48 0x141b36f30
    virtual void vfunc_49(Scaleform::GFx::Value* pRetVal, ASData* pArgs);   // 49 0x141b35070 "getTooltip" of a time slot / image
    virtual int vfunc_65();                                     // 65 0x141b34370 Open: listen for status / UGC events
    virtual void vfunc_67();                                    // 67 0x141b34410 Close
    virtual void vfunc_72();                                    // 72 0x141b34520 the hour changed: rebuild the reservations
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141b34910 the message boxes
    // UIUGCEventListener (+0x180)
    virtual void vfunc_ugc_4(int nDialog);                      // 4 0x141b35420 the upload moved to this dialog

    void FUN_141b35480(int nResult);                            // the server answered the upload
    int FUN_141b35540(MS2Ptr<CUgcPreReserve> spReserve);        // the reservations of the banner (0 = ok)
    int FUN_141b357e0();                                        // take the banner of the running upload
    void FUN_141b358d0();                                       // rebuild the file list
    void FUN_141b359b0();                                       // rebuild the 24 hour rows of the day
    void FUN_141b35b80();                                       // tell the movie the upload directory
    void FUN_141b35cd0();                                       // open the upload directory
    int FUN_141b35d00(int nIndex);                             // preview a file
    int FUN_141b35e10(int nIndex);                             // upload a file
    int FUN_141b36080();                                       // OnNewDraw: clear the upload
    int FUN_141b360c0();                                       // OnAddImage: pick an image file
    int FUN_141b36140(int nIndex);                              // scroll the list
    int FUN_141b36230(int nHour, bool bPicked);                // pick / drop an hour
    int FUN_141b362b0(int nOffset);                            // move the day
    void FUN_141b363b0();                                       // update the thumbnail image
    void FUN_141b364a0(int nIndex);                             // select the thumbnail
    void FUN_141b365e0();                                       // show the date
    void FUN_141b366b0();                                       // show the price of the picked hours
    void FUN_141b36750(__int64 nPrice);                         // set the price text
    __int64 FUN_141b368b0();                                    // the price of the picked hours
    void FUN_141b369d0();                                       // mark the reservation list dirty
    int FUN_141b36a60();                                        // the pay type of the price

private:
    MS2_LAYOUT_FRIEND;
    int m_188;                                                  // +0x188 the banner id
    Unk_DateParts m_190;                                        // +0x190 now
    Unk_DateParts m_1c0;                                        // +0x1c0 the day shown
    int m_1f0;                                                  // +0x1f0 the hour last seen
    int m_1f4;                                                  // +0x1f4 the day offset
    ATL::CRBMap<int, bool> m_1f8;                               // +0x1f8 the picked hours
    int m_228;                                                  // +0x228 the tick of the last check
    int m_22c;                                                  // +0x22c the thumbnail needs a refresh
    int m_230;                                                  // +0x230 the hours before the check time
    MS2Ptr<Unk_WcTitle> m_238;                                  // +0x238 the price text
};
MS2_CHECK_SIZE(UIUGCBannerDialog, 0x248);
MS2_CHECK_OFFSET(UIUGCBannerDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIUGCBannerDialog, m_190, 0x190);
MS2_CHECK_OFFSET(UIUGCBannerDialog, m_1c0, 0x1c0);
MS2_CHECK_OFFSET(UIUGCBannerDialog, m_1f8, 0x1f8);
MS2_CHECK_OFFSET(UIUGCBannerDialog, m_228, 0x228);
MS2_CHECK_OFFSET(UIUGCBannerDialog, m_238, 0x238);

class UIUGCCameraDialog : public UIDialog
{
public:
    UIUGCCameraDialog();                                        // 0x141b37fb0
    virtual ~UIUGCCameraDialog();                               //  0 0x141b380c0 (??_G 0x141b38990)
    virtual CString vfunc_1();                                  //  1 0x141b38130 "UGCCameraDialog"
    virtual void OnLoadInit();                                  // 20 0x141b38320
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141b384b0
    virtual int vfunc_48() { return 0x4e5b; }                   // 48 0x141b389d0
    virtual int vfunc_65();                                     // 65 0x141b38180
    virtual void vfunc_67();                                    // 67 0x141b381b0
    virtual void vfunc_72();                                    // 72 0x141b381d0 take the snapshot one frame after the click
    virtual void vfunc_79(void* p);                             // 79 0x141b38430
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);   // IMessageListener 0 0x141b38460

    void FUN_141b386b0(int nX, int nY, int nWidth, int nHeight);   // save the snapshot of the rectangle

private:
    MS2_LAYOUT_FRIEND;
    CStringW m_178;                                             // +0x178 the snapshot file as an url
    CStringW m_180;                                             // +0x180 the snapshot file as a path
    int m_188;                                                  // +0x188 0 idle, 1 asked, 2 take it now
    int m_18c;                                                  // +0x18c the snapshot rectangle
    int m_190;
    int m_194;
    int m_198;
    char m_pad_19c[0x1a0 - 0x19c];
};
MS2_CHECK_SIZE(UIUGCCameraDialog, 0x1a0);
MS2_CHECK_OFFSET(UIUGCCameraDialog, m_178, 0x178);
MS2_CHECK_OFFSET(UIUGCCameraDialog, m_188, 0x188);
MS2_CHECK_OFFSET(UIUGCCameraDialog, m_198, 0x198);
