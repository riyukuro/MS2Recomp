// asdisplayobject.h - PLACEHOLDER for the ActionScript display-object wrappers (RTTI). NOT an original header.
//   ASEventDispatcher : AScript                  vftable 0x14310b510 (1 slot)
//   ASDisplayObject : ASEventDispatcher          vftable 0x14310ad10 (6 slots)
//   ASInteractiveObject : ASDisplayObject, ASDisplayObjectContainer : ASInteractiveObject, ASSprite : ...Container
//   ASMovieClip : ASSprite                       vftable 0x14310b160 (16 slots)
// Only what recovered code calls is declared. ASEventDispatcher (and so ASDisplayObject) is 0x80 bytes: its ctor 0x1422c3090
// constructs two 0x20 members at +0x40/+0x60, and `new ASDisplayObject(v, n)` (0x140eec891) / `new ASMovieClip` allocate 0x80.
#pragma once

#include <afx.h>

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/delegate.h"

class ASEventDispatcher : public AScript
{
public:
    virtual ~ASEventDispatcher();
private:
    // +0x40 / +0x60: two 0x20 members built by 0x1422c4100 (the +0x60 one is the callback list, see FUN_1422c3180).
    // Pointers, not a char array: an array member makes every local AS object a /GS buffer (the exe frames have none).
    void* m_unrecovered_40; void* m_unrecovered_48; void* m_unrecovered_50; void* m_unrecovered_58;
    void* m_unrecovered_60; void* m_unrecovered_68; void* m_unrecovered_70; void* m_unrecovered_78;
};
MS2_CHECK_SIZE(ASEventDispatcher, 0x80);

class ASDisplayObject : public ASEventDispatcher
{
public:
    virtual ~ASDisplayObject();                                 // 0
    virtual void vfunc_1(int a1, int a2, int a3, int a4, int a5); // 1 0x1422bf8c0 (5 ints: alignment, x, y, width, height)
    virtual void vfunc_2(int a1, int a2, int a3);               // 2 0x1422bf840 (UISwfEntity::vfunc_44: resize)
    virtual void vfunc_3(int nVisible);                         // 3 0x1422bfc60 SetVisible
    virtual void vfunc_4(bool b);                               // 4 0x1422bfbd0
    virtual void vfunc_5();                                     // 5 0x1422c1560

    bool FUN_1422bfca0();                                       // IsVisible
    void FUN_1422bfe00(float fAlpha);                           // set the alpha (100 = opaque)
    int FUN_1422c1340();                                        // ceil(width)
    int FUN_1422c13b0();                                        // ceil(height)
    void FUN_1422bffe0(int x, int y);                           // set the position
    void FUN_1422c0060(int x, int y);                           // set the position (uidungeonroomdialog season rank marks)
    // Registers an AS -> C++ callback under a name (the list lives at +0x60; aseffect.cpp "GetTooltipCallback").
    void FUN_1422c3180(CString strName, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    void FUN_1422c00f0(float x, float y);                       // set the position (float)
    void FUN_1422c0f60(float* pX, float* pY);                   // get the position (uivipdialog.cpp)
    float FUN_1422c10a0();                                      // x
    float FUN_1422c1110();                                      // y
    void FUN_1422c0420(float x);                                // set x
    void FUN_1422c05a0(float y);                                // set y
    void FUN_1422c0ec0(int nHeight);                            // set the height
    void FUN_1422c0e20(int nWidth);                             // set the width (uirankpvpdialog.cpp)
    void FUN_1422c04a0(int y);                                  // set y (int; uirankpvpdialog.cpp)
    void FUN_1422c03a0(int x);                                  // set x (int; uiguilddialog.cpp)
    // addEventListener: an AS event of the object calls the delegate (uiblackmarketpage.cpp "changeTotalPrice")
    void FUN_1422c3600(const CString& strEvent, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture, int nPriority, int a5, int a6);
};

class ASInteractiveObject : public ASDisplayObject {};
class ASDisplayObjectContainer : public ASInteractiveObject
{
public:
    Scaleform::GFx::Value FUN_1422c6900(Scaleform::GFx::Value child);   // addChild (the argument is destroyed by the callee)
    Scaleform::GFx::Value FUN_1422c6b70(Scaleform::GFx::Value child);   // removeChild
    Scaleform::GFx::Value FUN_1422c6b00(const CString& strName);       // getChildByName (uipvpguildteamdialog)
    int FUN_1422c6670();                                                // numChildren
    Scaleform::GFx::Value FUN_1422c6aa0(int nIndex);                   // getChildAt
    void FUN_1422c6640(bool b);                                         // a bool member of the container (uidungeonsearchsettingdialog)
};
class ASSprite : public ASDisplayObjectContainer {};
class ASMovieClip : public ASSprite
{
public:
    ASMovieClip(CString strLinkage, int nMovieId);               // 0x1422c1ef0 (creates the clip from a linkage name)
    ASMovieClip(Scaleform::GFx::Value v, int nMovieId);         // 0x1422c1e90 (the Value is destroyed by the callee)
    virtual ~ASMovieClip();                                     // 0 deleting 0x1422c2de0, dtor 0x1422c1fb0
    // 6-11 invoke the AS MovieClip method of the same name, 12-15 forward to the value's object interface
    virtual void vfunc_6();                                     // 6 0x1422c20a0 play
    virtual void vfunc_7();                                     // 7 0x1422c20e0 stop
    virtual void vfunc_8();                                     // 8 0x1422c2120 prevFrame
    virtual void vfunc_9();                                     // 9 0x1422c2160 nextFrame
    virtual void vfunc_10();                                    // 10 0x1422c21a0 prevScene
    virtual void vfunc_11();                                    // 11 0x1422c21e0 nextScene
    virtual void vfunc_12(int nFrame);                          // 12 0x1422c2260
    virtual void vfunc_13(const CString& strLabel);             // 13 0x1422c2220
    virtual void vfunc_14(int nFrame);                          // 14 0x1422c22d0
    virtual void vfunc_15(const CString& strLabel);             // 15 0x1422c2290
    int FUN_1422c2300();                                        // the "currentFrame" member
    void FUN_1422c1fe0(int bEnabled);                           // the "enabled" member (uiweddinghallreservationdialog)
    void FUN_1422c2c30(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int nUser);   // add a "rightClick" listener (asitemslot.cpp)
    void FUN_1422c2cb0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);              // remove the "rightClick" listener
};
MS2_CHECK_SIZE(ASMovieClip, 0x80);                              // exe allocates 0x80 bytes (asequipicon 0x1409b93ed)

// new ASDisplayObject(v, n) wrapped in an MS2Ptr (free function or static; 0x140d01be0).
MS2Ptr<ASDisplayObject> FUN_140d01be0(int n, const Scaleform::GFx::Value& v);

// ASLoader (RTTI .?AVASLoader@@, COL 0x1432d06b0): an ASDisplayObjectContainer (the AS Loader clip that shows an
// external image; the guild dialog's event image, uiguilddialog.h). Nothing of its own is declared yet.
class ASLoader : public ASDisplayObjectContainer
{
public:
    ASLoader(int nMovieId);                                     // 0x1422e5300 (the exe allocates 0x90 bytes: uidungeonroomdialog 0x1412ad5f5)
private:
    void* m_pad_80;
    void* m_pad_88;
};
MS2_CHECK_SIZE(ASLoader, 0x90);
