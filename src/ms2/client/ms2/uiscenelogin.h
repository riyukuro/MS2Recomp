// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). Original: client\ms2\uiscenelogin.h (name assumed).
//
// UISceneLogin ("SceneLogin", RTTI .?AVUISceneLogin@@, 0xf8 bytes, scene id 0x6200009): the login screen scene. It
// shows the logo title animation, the progress bar of the file preloader (through a callback functor registered with
// the CFilePreload singleton) and the "failConnect" state; it manages the UILoginDialog (0x4e22) and the
// UIRegionListDialog (0x4eef). Names: virtuals are Ghidra's vfunc_<slot>; FUN_<va> are non-virtual members; fields
// are named from use.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/gfxui/uiswfentity.h"
#include "ms2/placeholder/clockcriticalsection.h"

class ASObj;

// UISceneEntity (0xa8): the base of every UI scene; the unit-local view this scene needs (the slots 60 / 61 take the AS
// background object by value; slot 61 also gets the AS call arguments).
class UISceneEntity : public UISwfEntity
{
public:
    UISceneEntity();                                            // 0x1422e7770
    virtual ~UISceneEntity();                                   //  0 0x1422e7850
    virtual void OnLoadInit();                                  // 20
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x1422e8470
    virtual void vfunc_41(const Scaleform::GFx::Value& root);   // 41
    virtual void vfunc_43();                                    // 43
    virtual bool vfunc_47();                                    // 47
    virtual void vfunc_48(int n);                               // 48 0x1422e7b20 show
    virtual void vfunc_49(int n);                               // 49 0x1422e7bd0 hide
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void vfunc_52();
    virtual void vfunc_53();
    virtual void vfunc_54();
    virtual void vfunc_55();
    virtual void vfunc_56();
    virtual void vfunc_57();
    virtual void vfunc_58();
    virtual void vfunc_59();
    virtual void vfunc_60(MS2Ptr<AScript> spBackground);        // 60 the scene's background AS object
    virtual void vfunc_61(MS2Ptr<AScript> spBackground, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 61 a background event
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void vfunc_64();
    virtual int vfunc_65() { return 0; }       // slot 65: no exe body (was a bogus symbols.tsv data row)

    void FUN_1422e7950();                                       // 0x1422e7950 the presentation ref has changed

public:
    char m_pad68[4];
    int m_6c;                                                   // +0x6c the scene entity id
    char m_pad70[0x38];
};
MS2_CHECK_SIZE(UISceneEntity, 0xa8);

class UISceneLogin : public UISceneEntity
{
public:
    UISceneLogin();                                             // 0x141aceab0 (m_6c = 0x6200009)
    virtual ~UISceneLogin();                                    //  0 0x141acec20 (??_G 0x141ad02e0)
    virtual CString vfunc_1();                                  //  1 0x141acec90 "SceneLogin"
    virtual int vfunc_13();                                     // 13 0x141acf000
    virtual void vfunc_15();                                    // 15 0x141aceef0 per-frame
    virtual void OnLoadComplete();                              // 22 0x141acf1f0
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 28 0x141acf2f0
    virtual void vfunc_48(int n);                               // 48 0x141acece0 show
    virtual void vfunc_49(int n);                               // 49 0x141acee00 hide
    virtual void vfunc_55();                                    // 55 0x141aceec0
    virtual void vfunc_60(MS2Ptr<AScript> spBackground);        // 60 0x141acf190 the background is ready
    virtual void vfunc_61(MS2Ptr<AScript> spBackground, const Scaleform::GFx::Value* pArgs, unsigned int nArgs);   // 61 0x141acf0a0
    virtual void vfunc_64();                                    // 64 0x141acf400

    void FUN_141acf420();                                       // show the login dialog / region list
    void FUN_141acf470();                                       // the connection failed
    void FUN_141acf5a0();                                       // start the title animation
    void FUN_141acf700(unsigned int nBits);                     // add progress bits (under the lock)
    void FUN_141acf7c0();                                       // the title is done
    void FUN_141acf860(int nBits);                              // the preload progress callback
    void FUN_141acf890();                                       // push the progress to the movie
    void FUN_141acfa00();                                       // hide the dialogs
    void FUN_141acfa70();                                       // the movie's "show"
    void FUN_141acfad0(__int64 nUnused);                                    // hide the title and the dialogs
    bool FUN_141acfb40();                                       // the region list is used
    void FUN_141acfba0(ASObj* pObj);                            // fill the button flags
    void FUN_141acfc70();                                       // leave the pending state
    void FUN_141acfcc0();                                       // the end of the pop-down

    int m_nTitleDone;                                           // +0xa8
    int m_nShown;                                               // +0xac
    int m_nExitFlag;                                            // +0xb0
    int m_nProgressDirty;                                       // +0xb4
    unsigned int m_nProgress;                                   // +0xb8 preload bits | 0x4000 title done | 0x8000
    int m_nPad;                                                 // +0xbc
    CLockCriticalSection m_lock;                                // +0xc0
    unsigned char m_bPending;                                   // +0xf0
    char m_padF1[7];
};
MS2_CHECK_SIZE(UISceneLogin, 0xf8);
MS2_CHECK_OFFSET(UISceneLogin, m_nTitleDone, 0xa8);
MS2_CHECK_OFFSET(UISceneLogin, m_nProgress, 0xb8);
MS2_CHECK_OFFSET(UISceneLogin, m_lock, 0xc0);
MS2_CHECK_OFFSET(UISceneLogin, m_bPending, 0xf0);
