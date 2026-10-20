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
    ASEventDispatcher(const Scaleform::GFx::Value& v, int nMovieId);    // 0x1422c3090 (AScript ctor 0x1422ba780)
    virtual ~ASEventDispatcher();
    // addEventListener (0x1422c3600; ASDisplayObject redeclares it): pUser is the AS function object's user data
    // (asbuttongroup.cpp)
    void FUN_1422c3600(const CString& strEvent, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture, int nPriority, int a5, void* pUser);
    void FUN_1422c3d30(class ASEvent& ev);                              // dispatchEvent (asuicomponent.cpp)
    // removeEventListener (0x1422c3820; ASDisplayObject redeclares it; asloader.cpp "complete")
    void FUN_1422c3820(const CString& strEvent, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture);
private:
    // +0x40 / +0x60: two 0x20 members built by 0x1422c4100 (the +0x60 one is the callback list, see FUN_1422c3180).
    // Pointers, not a char array: an array member makes every local AS object a /GS buffer (the exe frames have none).
    void* m_unrecovered_40; void* m_unrecovered_48; void* m_unrecovered_50; void* m_unrecovered_58;
    void* m_unrecovered_60; void* m_unrecovered_68; void* m_unrecovered_70; void* m_unrecovered_78;
};
MS2_CHECK_SIZE(ASEventDispatcher, 0x80);

class ASStage;

// Recovered with ?\asdisplayobject.cpp (src/ms2/gfxui/asdisplayobject.cpp, 0x1422bf7c0-0x1422c1e40). The getters and
// setters go through Scaleform::GFx::Value::DisplayInfo (GetDisplayInfo -> modify -> SetDisplayInfo); the int / unsigned /
// float overloads are separate functions. Names are Ghidra's (FUN_<va>), the comment says what each one is.
class ASDisplayObject : public ASEventDispatcher
{
public:
    ASDisplayObject(const Scaleform::GFx::Value& v, int nMovieId);  // 0x1422bf7c0
    virtual ~ASDisplayObject();                                 // 0 0x1422bf810 (scalar deleting 0x1422c19a0)
    virtual void vfunc_1(int a1, int a2, int a3, int a4, int a5); // 1 0x1422bf8c0 align (0..8) to the stage at (x, y), size (w, h)
    virtual void vfunc_2(int a1, int a2, int a3);               // 2 0x1422bf840 vfunc_1 with the own width/height (UISwfEntity::vfunc_44: resize)
    virtual void vfunc_3(int nVisible);                         // 3 0x1422bfc60 SetVisible
    virtual void vfunc_4(bool b);                               // 4 0x1422bfbd0 SetVisible (only if it changes)
    virtual ASStage* vfunc_5();                                 // 5 0x1422c1560 the stage of the object's movie (ASStage returns itself)

    bool FUN_1422bfca0();                                       // IsVisible
    void FUN_1422bfd10(float fFOV);                             // set the FOV
    float FUN_1422bfd90();                                      // FOV
    void FUN_1422bfe00(float fAlpha);                           // set the alpha (100 = opaque)
    float FUN_1422bfe80();                                      // alpha
    void FUN_1422bfef0(float fRotation);                        // set the rotation (degrees; uiminimapentity.cpp)
    float FUN_1422bff70();                                      // rotation
    void FUN_1422bffe0(int x, int y);                           // set the position
    void FUN_1422c0060(unsigned int x, unsigned int y);         // set the position (uidungeonroomdialog season rank marks)
    void FUN_1422c00f0(float x, float y);                       // set the position (float)
    void FUN_1422c0180(int xScale, int yScale);                 // set the scale (100 = 100%)
    void FUN_1422c0200(unsigned int xScale, unsigned int yScale);
    void FUN_1422c0290(float xScale, float yScale);
    void FUN_1422c0320(int x);                                  // set x (uiwritemusicdialog playing line)
    void FUN_1422c03a0(unsigned int x);                         // set x (uiguilddialog.cpp)
    void FUN_1422c0420(float x);                                // set x
    void FUN_1422c04a0(int y);                                  // set y (uirankpvpdialog.cpp)
    void FUN_1422c0520(unsigned int y);                         // set y
    void FUN_1422c05a0(float y);                                // set y
    void FUN_1422c0620(int z);                                  // set z
    void FUN_1422c06a0(unsigned int z);
    void FUN_1422c0720(float z);
    void FUN_1422c07a0(int dx);                                 // move x by dx
    void FUN_1422c0840(int dy);                                 // move y by dy
    void FUN_1422c08e0(int dx, int dy);                         // move by (dx, dy)
    void FUN_1422c09a0(int xScale);                             // set the x scale
    void FUN_1422c0a20(unsigned int xScale);
    void FUN_1422c0aa0(float xScale);
    void FUN_1422c0b20(int yScale);                             // set the y scale
    void FUN_1422c0ba0(unsigned int yScale);
    void FUN_1422c0c20(float yScale);
    void FUN_1422c0ca0(int zScale);                             // set the z scale
    void FUN_1422c0d20(unsigned int zScale);
    void FUN_1422c0da0(float zScale);
    void FUN_1422c0e20(int nWidth);                             // set the "width" member (uirankpvpdialog.cpp)
    void FUN_1422c0e50(unsigned int nWidth);
    void FUN_1422c0e80(float fWidth);
    void FUN_1422c0ec0(int nHeight);                            // set the "height" member
    void FUN_1422c0ef0(unsigned int nHeight);
    void FUN_1422c0f20(float fHeight);
    void FUN_1422c0f60(float* pX, float* pY);                   // get the position (uivipdialog.cpp)
    void FUN_1422c1000(float* pXScale, float* pYScale);         // get the scale
    float FUN_1422c10a0();                                      // x
    float FUN_1422c1110();                                      // y
    float FUN_1422c1180();                                      // z
    float FUN_1422c11f0();                                      // x scale
    float FUN_1422c1260();                                      // y scale
    float FUN_1422c12d0();                                      // z scale
    int FUN_1422c1340();                                        // ceil(width)
    int FUN_1422c13b0();                                        // ceil(height)
    float FUN_1422c1420();                                      // width
    float FUN_1422c1490();                                      // height
    int FUN_1422c1500();                                        // the stage width
    int FUN_1422c1530();                                        // the stage height
    int FUN_1422c15d0(int x, int y, bool bShapeFlag);          // hitTestPoint
    int FUN_1422c1670(float x, float y, bool bShapeFlag);      // hitTestPoint
    int FUN_1422c1710(MS2Ptr<ASDisplayObject> spObj);          // hitTestObject (spObj by value: the callee destroys it)
#if defined(MS2_HAVE_SCALEFORM_SDK)   // Value::DisplayInfo exists only in the real SDK header
    int FUN_1422c17d0(const Scaleform::GFx::Value::DisplayInfo& info);   // SetDisplayInfo
    int FUN_1422c1810(Scaleform::GFx::Value::DisplayInfo& info);         // GetDisplayInfo (false if not a display object)
#endif

    // ---- defined in other units of the GFx UI library ----
    // Registers an AS -> C++ callback under a name (the list lives at +0x60; aseffect.cpp "GetTooltipCallback").
    void FUN_1422c3180(CString strName, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    int FUN_1422c2510(double* pX, double* pY);                  // get the position (double; uiminimapentity.cpp)
    // addEventListener: an AS event of the object calls the delegate (uiblackmarketpage.cpp "changeTotalPrice")
    void FUN_1422c3600(const CString& strEvent, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture, int nPriority, int a5, int a6);
    // the same callee: its last parameter is the pointer-sized user data of the AS function object (asbutton.cpp)
    void FUN_1422c3600(const CString& strEvent, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture, int nPriority, int a5, void* pUser);
    // removeEventListener: drops the delegate registered for the event (asbutton.cpp)
    void FUN_1422c3820(const CString& strEvent, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture);
};
MS2_CHECK_SIZE(ASDisplayObject, 0x80);

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
// ASStage (RTTI .?AVASStage@@, 0x80, vftable 0x143111a78, ctor 0x1422cfcb0): the movie's stage; slot 5 returns itself.
class ASStage : public ASDisplayObjectContainer
{
public:
    ASStage(const Scaleform::GFx::Value& v, int nMovieId);     // 0x1422cfcb0 (new 0x80 in gfxmoviedamage.cpp FUN_140b62400)
    int FUN_1422cfec0();                                        // "stageWidth"
    int FUN_1422cff20();                                        // "stageHeight"
    void FUN_1422cfd30(MS2Ptr<ASInteractiveObject> spFocus);   // set the stage "focus" (by value: the callee destroys it; asuicomponent.cpp)
};
class ASSprite : public ASDisplayObjectContainer {};
class ASMovieClip : public ASSprite
{
public:
    ASMovieClip(CString strLinkage, int nMovieId);               // 0x1422c1ef0 (creates the clip from a linkage name)
    ASMovieClip(int nMovieId);                                  // 0x1422c1e40 (a fresh clip; asuicomponent.cpp)
    ASMovieClip(Scaleform::GFx::Value v, int nMovieId);         // 0x1422c1e90 (the Value is destroyed by the callee)
    virtual ~ASMovieClip();                                     // 0 deleting 0x1422c2de0, dtor 0x1422c1fb0
    // 6-11 invoke the AS MovieClip method of the same name, 12-15 forward to the value's object interface
    virtual void vfunc_6();                                     // 6 0x1422c20a0 play
    virtual void vfunc_7();                                     // 7 0x1422c20e0 stop
    virtual void vfunc_8();                                     // 8 0x1422c2120 prevFrame
    virtual void vfunc_9();                                     // 9 0x1422c2160 nextFrame
    virtual void vfunc_10();                                    // 10 0x1422c21a0 prevScene
    virtual void vfunc_11();                                    // 11 0x1422c21e0 nextScene
    virtual void vfunc_12(int nFrame);                          // 12 0x1422c2260 gotoAndPlay(frame)
    virtual void vfunc_13(const CString& strLabel);             // 13 0x1422c2220 gotoAndPlay(label)
    virtual void vfunc_14(int nFrame);                          // 14 0x1422c22d0 gotoAndStop(frame)
    virtual void vfunc_15(const CString& strLabel);             // 15 0x1422c2290 gotoAndStop(label)
    int FUN_1422c2300();                                        // "currentFrame"
    CString FUN_1422c2360();                                    // "currentFrameLabel" ("" if it is not a string)
    CString FUN_1422c2420();                                    // "currentLabel"
    int FUN_1422c24b0();                                        // "totalFrames"
    int FUN_1422c2510(double* pX, double* pY);                  // localToGlobal(new Point): the stage position
    int FUN_1422c2700(float* pX, float* pY);                    // globalToLocal(0, 0)
    int FUN_1422c2740(float x, float y, float* pX, float* pY);  // globalToLocal(x, y)
    bool FUN_1422c29c0(float x, float y, bool bShapeFlag);      // hitTestPoint (false unless the result is a bool)
    // "click" / "doubleClick" / "rightClick" listeners (pUser: the pointer-sized user data handed back with the call)
    void FUN_1422c2a70(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);
    void FUN_1422c2af0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    void FUN_1422c2b50(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);
    void FUN_1422c2bd0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    void FUN_1422c2c30(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);   // asitemslot.cpp
    void FUN_1422c2cb0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    // sets "externalTooltipFunction" to an ASFunction of the delegate (cb by value: the callee destroys it)
    void FUN_1422c2d10(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb, void* pUser);
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
    ASLoader(const Scaleform::GFx::Value& v, int nMovieId);     // 0x1422e53d0
    virtual ~ASLoader();                                        // 0x1422e5440 (scalar deleting 0x1422e59f0)
    void BindContentLoaderInfo();                               // 0x1422e54a0 m_spContentLoaderInfo = "contentLoaderInfo"
    void Load(MS2Ptr<ASURLRequest> spRequest);                  // 0x1422e5530 load(request) (by value: the callee destroys it)
    void UnloadAndStop(bool bGC);                               // 0x1422e55c0 unloadAndStop(bGC)
    // addEventListener / removeEventListener "complete" on the loader info (pUser: the AS function object's user data)
    void AddCompleteListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);   // 0x1422e5600
    void RemoveCompleteListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);              // 0x1422e56a0
    Scaleform::GFx::Value GetContent();                         // 0x1422e5730 the "content" member
private:
    void* m_pad_80;
    void* m_pad_88;
};
MS2_CHECK_SIZE(ASLoader, 0x90);
