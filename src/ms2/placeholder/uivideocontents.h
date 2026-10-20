// uivideocontents.h - PLACEHOLDER for UIVideoContents (RTTI .?AVUIVideoContents@@, 0x78 bytes). NOT an original
// header. Base UIObject. Primary vftable 0x142ef50c8 (55 slots), IMessageListener-in-UIVideoContents 0x142ef5288.
// Ctor 0x14135aa20, dtor 0x14135aaa0. Its code (and the COMDATs GetChild<Unk_ASVideoPlayer> 0x14135b280,
// MS2Ptr<Unk_ASVideoPlayer> members 0x14135b390..0x14135b3d0) lives in client\ms2\uiupperhuddialog.cpp.
// Ownership and slot rules: uiswfentity.h.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/uiobject.h"
#include "ms2/placeholder/ascript.h"

// The AS video player clip ("m_videoPlayer"); class unknown (an AS* wrapper, methods in 0x1422c1500..0x1422e9810).
class Unk_ASVideoPlayer : public AScript
{
public:
    Unk_ASVideoPlayer(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422e92e0
    void FUN_1422e9650();               // stop
    int FUN_1422c1500();                // width?
    int FUN_1422c1530();                // height?
    float FUN_1422e9540();              // current play time (s)?
    void FUN_1422e9490(float fVolume);
    void FUN_1422e95b0(const CString& strPath);     // play file
    void FUN_1422e9690(float f);
    void FUN_1422e9810(int a1, int a2); // resize?
private:
    char m_pad_40[0x40];
};
MS2_CHECK_SIZE(Unk_ASVideoPlayer, 0x80);

class UIVideoContents : public UIObject
{
public:
    UIVideoContents();
    virtual ~UIVideoContents();                                             //  0 0x14135b3e0 (??_G)
    virtual CString vfunc_1();                                              //  1 0x14135aaf0
    virtual int vfunc_13();                                                 // 13 0x14135af90
    virtual void OnLoadComplete();                                          // 22 0x14135af20
    virtual void vfunc_41(const Scaleform::GFx::Value& root);              // 41 0x14135b0a0
    virtual int vfunc_48();                                                 // 48 0x14135b420
    virtual int vfunc_52(const CString& strPath, float fVolume);            // 52 0x14135ab40 play
    virtual int vfunc_53();                                                 // 53 0x14135ad10 stop
    virtual int vfunc_54(float fTimeout);                                  // 54 0x14135adc0
    void FUN_14135afa0(int bMute);

protected:
    MS2_LAYOUT_FRIEND;
    float m_68;                         // +0x68 volume (2nd argument of vfunc_52)
    int m_pad_6c;
    CString m_strPath;                  // +0x70 video path (1st argument of vfunc_52)
};
MS2_CHECK_SIZE(UIVideoContents, 0x78);
MS2_CHECK_OFFSET(UIVideoContents, m_68, 0x68);
MS2_CHECK_OFFSET(UIVideoContents, m_strPath, 0x70);
