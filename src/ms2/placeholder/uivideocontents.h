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
#include "ms2/placeholder/asvideo.h"

// The AS video player clip ("m_videoPlayer"): ASVideoPlayer (RTTI .?AVASVideoPlayer@@, base ASVideo, vftable 0x143116770:
// only the dtor is overridden), recovered with ?\asvideoplayer.cpp (src/ms2/gfxui/asvideoplayer.cpp, 0x1422e92e0-
// 0x1422e9a40). The Unk_ name is kept for the existing callers; the comments name the AS member / method each one uses.
class Unk_ASVideoPlayer : public ASVideo
{
public:
    Unk_ASVideoPlayer(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422e92e0
    virtual ~Unk_ASVideoPlayer();                                       // 0 0x1422e9330 (scalar deleting 0x1422e9a00)
    void FUN_1422e9360(const CString& strMode);     // set "scaleMode"
    CString FUN_1422e93b0();                        // "scaleMode"
    void FUN_1422e9440(int n);                      // (empty)
    int FUN_1422e9450();                            // returns 0
    void FUN_1422e9460(float f);                    // (empty)
    float FUN_1422e9480();                          // returns 0.0f
    void FUN_1422e9490(float fVolume);              // set "volume"
    float FUN_1422e94d0();                          // "volume"
    float FUN_1422e9540();                          // "time": the current play time (s)
    void FUN_1422e95b0(const CString& strPath);     // play(path)
    void FUN_1422e9610();                           // rePlay()
    void FUN_1422e9650();                           // stop()
    void FUN_1422e9690(float fTime);                // seek(time)
    void FUN_1422e96d0();                           // pause()
    int FUN_1422e9710();                            // isPlay()
    void FUN_1422e9780(int bLoop);                  // setLoop(loop)
    void FUN_1422e97c0(int nWidth, int nHeight);    // setAspectRatio(w, h)
    void FUN_1422e9810(int nWidth, int nHeight);    // setSize(w, h)
    void FUN_1422e9860(unsigned nWidth, unsigned nHeight);   // setSize(w, h) (the unsigned Invoke 0x140acd070)
    void FUN_1422e98b0(float fWidth, float fHeight);         // setSize(w, h)
    void FUN_1422e9910(int nX, int nY);             // setScale(x, y)
    void FUN_1422e9960(unsigned nX, unsigned nY);   // setScale(x, y) (unsigned)
    void FUN_1422e99b0(float fX, float fY);         // setScale(x, y)
    int FUN_1422c1500();                // ASDisplayObject: width
    int FUN_1422c1530();                // ASDisplayObject: height
};
MS2_CHECK_SIZE(Unk_ASVideoPlayer, 0x80);

class UIVideoContents : public UIObject
{
public:
    UIVideoContents();
    virtual ~UIVideoContents();                                             //  0 0x14135b3e0 (??_G)
    virtual CString GetTypeName();                                              //  1 0x14135aaf0
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
