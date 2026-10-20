// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uicutscenemovie.h (name assumed:
// the .cpp's __FILE__ string is in the exe, the header's is not).
//
// UICutSceneMovie plays a cut-scene video (.usm through the "m_videoPlayer" clip, or a .swf movie) full-screen
// with a skip button ("m_exit"). RTTI .?AVUICutSceneMovie@@, 0xa8 bytes, vftables 0x142f9e518 (55 slots) and
// 0x142f9e6d8 (IMessageListener at +0x18).
// Member and method names are invented where the exe has no name (vfunc_N / FUN_<va> otherwise).
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/uivideocontents.h"

// The AS clip bound to "m_exit" (the skip button); class unknown (an AS* wrapper with at least 14 slots).
class Unk_ASExitButton : public CPtred
{
public:
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(int nVisible);                 // slot 3: SetVisible?
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13(const CString& strLabel);     // slot 13: gotoAndPlay("show"/"hide")?
    bool FUN_1422bfca0();                               // visible?
};

class UICutSceneMovie : public UIVideoContents
{
public:
    UICutSceneMovie();
    virtual ~UICutSceneMovie();

    // UISwfEntity / UIObject / UIVideoContents overrides (slot index in the primary vftable)
    virtual int vfunc_52(const CString& strPath, float fVolume);    // 52 play
    virtual int vfunc_53();                                          // 53 stop
    virtual void OnLoadComplete();                                  // 22
    virtual void vfunc_26();                                        // 26
    void SetCutSceneId(int nId);                                    // 0x14190f0b0
    void StopIfCutScene(int nId);                                   // 0x14190f0d0
    void PlayScene(int nSceneId, CString strPath);                  // 0x14190f110
    void PlayCurrentScene();                                        // 0x14190f180
    int HasSceneVideo(int nScene);                                  // 0x14190f1d0
    void SetSoundFade(bool bFade);                                  // 0x14190f270
    void RemoveTween();                                             // 0x14190f350
    virtual CString vfunc_1();                                      //  1
    virtual void OnLoadInit();                                      // 20
    virtual int vfunc_13();                                         // 13
    virtual void vfunc_15();                                        // 15
    virtual void vfunc_30(const CString& a1, const CString& a2, const CString& a3);    // 30
    virtual void vfunc_31(const CString& a1, float a2, const void* a3);                // 31
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);      // IMessageListener 0
    virtual void vfunc_11();                                        // 11
    virtual bool vfunc_17();                                        // 17
    void ShowSkipButton();                                          // 0x14190fcb0
    bool Play();                                                    // 0x14190fef0
    bool PlayUsm();                                                 // 0x14190ffc0
    bool PlaySwf();                                                 // 0x141910110
    void Exit();                                                    // 0x141910220
    int FUN_1419102c0();
    void PlayDefaultScene();                                        // 0x1419102e0
    void PlayPendingScene();                                        // 0x1419103b0
    virtual int vfunc_48() { return 20094; }                        // 48 UI type id (COMDAT 0x141910470)

private:
    MS2_LAYOUT_FRIEND;
    bool m_bIntroStory;                 // +0x78 path is Common/MS2IntroStory.usm
    int m_bPlayPending;                 // +0x7c play requested before the movie was loaded
    bool m_bSoundFaded;                 // +0x80
    int m_nCutSceneId;                  // +0x84 sent to the server when the user skips
    MS2Ptr<Unk_ASExitButton> m_pExit;   // +0x88 "m_exit"
    int m_nSceneId;                     // +0x98
    CString m_strScenePath;             // +0xa0
};
MS2_CHECK_SIZE(UICutSceneMovie, 0xa8);
MS2_CHECK_OFFSET(UICutSceneMovie, m_bIntroStory, 0x78);
MS2_CHECK_OFFSET(UICutSceneMovie, m_bPlayPending, 0x7c);
MS2_CHECK_OFFSET(UICutSceneMovie, m_bSoundFaded, 0x80);
MS2_CHECK_OFFSET(UICutSceneMovie, m_nCutSceneId, 0x84);
MS2_CHECK_OFFSET(UICutSceneMovie, m_pExit, 0x88);
MS2_CHECK_OFFSET(UICutSceneMovie, m_nSceneId, 0x98);
MS2_CHECK_OFFSET(UICutSceneMovie, m_strScenePath, 0xa0);
