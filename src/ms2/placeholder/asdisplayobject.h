// asdisplayobject.h - PLACEHOLDER for the ActionScript display-object wrappers (RTTI). NOT an original header.
//   ASEventDispatcher : AScript                  vftable 0x14310b510 (1 slot)
//   ASDisplayObject : ASEventDispatcher          vftable 0x14310ad10 (6 slots)
//   ASInteractiveObject : ASDisplayObject, ASDisplayObjectContainer : ASInteractiveObject, ASSprite : ...Container
//   ASMovieClip : ASSprite                       vftable 0x14310b160 (16 slots)
// Only what recovered code calls is declared. ASEventDispatcher (and so ASDisplayObject) is 0x80 bytes: its ctor 0x1422c3090
// constructs two 0x20 members at +0x40/+0x60, and `new ASDisplayObject(v, n)` (0x140eec891) / `new ASMovieClip` allocate 0x80.
#pragma once

#include <afx.h>
#include <atlcoll.h>

#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/delegate.h"

// ASEventHandlerCtx (RTTI .?AVASEventHandlerCtx@@, 0x40 bytes, base Scaleform::GFx::FunctionHandler): an AS function
// object (m_func, created by Movie::CreateFunction with the context as its handler) that calls a C++ delegate. ASEventDispatcher
// keeps them alive as Scaleform::Ptr in its two arrays. Code in ?\aseventdispatcher.cpp.
class ASEventHandlerCtx : public Scaleform::GFx::FunctionHandler
{
public:
    typedef Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> Callback;

    ASEventHandlerCtx(CString strType, Callback cb);                    // 0x1422c2fc0 (both by value: destroyed here)
    // ~ASEventHandlerCtx is implicit (0x1422c42b0; ??_G 0x1422c4520)
    virtual void Call(const Params& params);                            // 1 0x1422c3060 m_cb(params)

    CString m_strType;                                                  // +0x10 event type / member name
    Scaleform::GFx::Value m_func;                                       // +0x18 the AS function object
    Callback m_cb;                                                      // +0x38
};

// ASEventDispatcher: the flash.events.EventDispatcher wrapper. Code in ?\aseventdispatcher.cpp (0x1422c2fc0-0x1422c4c00).
class ASEventDispatcher : public AScript
{
public:
    typedef ASEventHandlerCtx::Callback Callback;

    ASEventDispatcher(const Scaleform::GFx::Value& v, int nMovieId);    // 0x1422c3090 (AScript ctor 0x1422ba780)
    virtual ~ASEventDispatcher();                                       // 0 0x1422c3100 (??_G 0x1422c44e0)
    // Defines the AS member strName as a function calling cb (once per name).
    void AddMemberCallback(CString strName, const Callback& cb);            // 0x1422c3180 (strName by value)
    void RemoveMemberCallback(CString strName);                                // 0x1422c33c0 undo AddMemberCallback (member := undefined)
    void RemoveAllMemberCallbacks();                                               // 0x1422c34f0 undo every AddMemberCallback
    // addEventListener (0x1422c3600): pUser is the AS function object's user data
    // (asbuttongroup.cpp). Once per delegate.
    void AddEventListener(const CString& strEvent, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture, int nPriority, int a5, void* pUser);
    // removeEventListener (0x1422c3820; asloader.cpp "complete")
    void RemoveEventListener(const CString& strEvent, const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture);
    void RemoveAllEventListeners();                                               // 0x1422c3940 remove every listener
    // The flash.events.IEventDispatcher methods on an AS function value.
    void FUN_1422c3a30(const CString& strType, const Scaleform::GFx::Value& listener, bool bUseCapture, int nPriority,
                       int bUseWeakReference);                          // addEventListener
    void FUN_1422c3b30(const CString& strType, const Scaleform::GFx::Value& listener, bool bUseCapture);   // removeEventListener
    int HasEventListener(const CString& strType);                          // hasEventListener
    int WillTrigger(const CString& strType);                          // willTrigger
    int DispatchEvent(class ASEvent& ev);                               // dispatchEvent (asuicomponent.cpp)
private:
    MS2_LAYOUT_FRIEND;
    ATL::CAtlArray<Scaleform::Ptr<ASEventHandlerCtx> > m_listeners;    // +0x40 FUN_1422c3600's AS listeners
    ATL::CAtlArray<Scaleform::Ptr<ASEventHandlerCtx> > m_members;      // +0x60 AddMemberCallback's AS member functions
};
MS2_CHECK_SIZE(ASEventDispatcher, 0x80);
MS2_CHECK_OFFSET(ASEventDispatcher, m_listeners, 0x40);
MS2_CHECK_OFFSET(ASEventDispatcher, m_members, 0x60);

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

    bool GetVisible();                                       // IsVisible
    void SetFOV(float fFOV);                             // set the FOV
    float GetFOV();                                      // FOV
    void SetAlpha(float fAlpha);                           // set the alpha (100 = opaque)
    float GetAlpha();                                      // alpha
    void SetRotation(float fRotation);                        // set the rotation (degrees; uiminimapentity.cpp)
    float GetRotation();                                      // rotation
    void SetPositionInt(int x, int y);                           // set the position
    void SetPositionUInt(unsigned int x, unsigned int y);         // set the position (uidungeonroomdialog season rank marks)
    void SetPositionFloat(float x, float y);                       // set the position (float)
    void SetScaleInt(int xScale, int yScale);                 // set the scale (100 = 100%)
    void SetScaleUInt(unsigned int xScale, unsigned int yScale);
    void SetScaleFloat(float xScale, float yScale);
    void SetXInt(int x);                                  // set x (uiwritemusicdialog playing line)
    void SetXUInt(unsigned int x);                         // set x (uiguilddialog.cpp)
    void SetXFloat(float x);                                // set x
    void SetYInt(int y);                                  // set y (uirankpvpdialog.cpp)
    void SetYUInt(unsigned int y);                         // set y
    void SetYFloat(float y);                                // set y
    void SetZInt(int z);                                  // set z
    void SetZUInt(unsigned int z);
    void SetZFloat(float z);
    void MoveX(int dx);                                 // move x by dx
    void MoveY(int dy);                                 // move y by dy
    void MoveBy(int dx, int dy);                         // move by (dx, dy)
    void SetXScaleInt(int xScale);                             // set the x scale
    void SetXScaleUInt(unsigned int xScale);
    void SetXScaleFloat(float xScale);
    void SetYScaleInt(int yScale);                             // set the y scale
    void SetYScaleUInt(unsigned int yScale);
    void SetYScaleFloat(float yScale);
    void SetZScaleInt(int zScale);                             // set the z scale
    void SetZScaleUInt(unsigned int zScale);
    void SetZScaleFloat(float zScale);
    void SetWidthInt(int nWidth);                             // set the "width" member (uirankpvpdialog.cpp)
    void SetWidthUInt(unsigned int nWidth);
    void SetWidthFloat(float fWidth);
    void SetHeightInt(int nHeight);                            // set the "height" member
    void SetHeightUInt(unsigned int nHeight);
    void SetHeightFloat(float fHeight);
    void GetPosition(float* pX, float* pY);                   // get the position (uivipdialog.cpp)
    void GetScale(float* pXScale, float* pYScale);         // get the scale
    float GetX();                                      // x
    float GetY();                                      // y
    float GetZ();                                      // z
    float GetXScale();                                      // x scale
    float GetYScale();                                      // y scale
    float GetZScale();                                      // z scale
    int GetWidthCeil();                                        // ceil(width)
    int GetHeightCeil();                                        // ceil(height)
    float GetWidth();                                      // width
    float GetHeight();                                      // height
    int FUN_1422c1500();                                        // the stage width
    int FUN_1422c1530();                                        // the stage height
    int HitTestPointInt(int x, int y, bool bShapeFlag);          // hitTestPoint
    int HitTestPoint(float x, float y, bool bShapeFlag);      // hitTestPoint
    int HitTestObject(MS2Ptr<ASDisplayObject> spObj);          // hitTestObject (spObj by value: the callee destroys it)
    int SetDisplayInfo(const Scaleform::GFx::Value::DisplayInfo& info);   // SetDisplayInfo
    int GetDisplayInfo(Scaleform::GFx::Value::DisplayInfo& info);         // GetDisplayInfo (false if not a display object)

    // ---- defined in other units of the GFx UI library ----
    // AddMemberCallback (AS -> C++ callback), FUN_1422c3600 (addEventListener) and FUN_1422c3820 (removeEventListener) are
    // ASEventDispatcher's, inherited.
    int LocalToGlobal(double* pX, double* pY);                  // get the position (double; uiminimapentity.cpp; ASMovieClip's, asmovieclip.cpp)
};
MS2_CHECK_SIZE(ASDisplayObject, 0x80);

// ASInteractiveObject (RTTI .?AVASInteractiveObject@@, 0x80, vftable 0x143113738: only the dtor is overridden). Recovered
// with ?\asinteractiveobject.cpp (src/ms2/gfxui/asinteractiveobject.cpp, 0x1422de680-0x1422deec0). The listeners take
// (bCapture, pUser: the AS function object's user data); the int setters / getters read the AS member as a Boolean.
class ASInteractiveObject : public ASDisplayObject
{
public:
    ASInteractiveObject(const Scaleform::GFx::Value& v, int nMovieId);      // 0x1422de680 (asinteractiveobject.cpp)
    virtual ~ASInteractiveObject();                                         // 0 0x1422de6d0 (scalar deleting 0x1422dee80)
    // "focusIn" / "focusOut" / "rollOver" / "rollOut" listeners: add, remove (asinteractiveobject.cpp)
    void AddFocusInListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture, void* pUser);
    void AddFocusOutListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture, void* pUser);
    void AddRollOverListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture, void* pUser);
    void AddRollOutListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture, void* pUser);
    void RemoveFocusInListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture);   // (asinteractiveobject.cpp: bCapture unused)
    void RemoveFocusOutListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture);
    void RemoveRollOverListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture);
    void RemoveRollOutListener(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, bool bCapture);
    void SetDoubleClickEnabled(int bEnabled);                                       // set "doubleClickEnabled" (asinteractiveobject.cpp)
    int IsDoubleClickEnabled();                                                    // "doubleClickEnabled"
    void SetMouseEnabled(bool bEnabled);                                      // set "mouseEnabled"
    int IsMouseEnabled();                                                    // "mouseEnabled"
    void SetNeedsSoftKeyboard(int bNeeds);                                         // set "needsSoftKeyboard"
    int FUN_1422dec30();                                                    // "needsSoftKeyboard"
    void SetTabEnabled(int bEnabled);                                       // set "tabEnabled"
    int IsTabEnabled();                                                    // "tabEnabled"
    void SetTabIndex(int nIndex);                                         // set "tabIndex" (as a Boolean: the exe passes nIndex != 0)
    int GetTabIndex();                                                    // "tabIndex" (read as a Boolean)
    int RequestSoftKeyboard();                                                    // requestSoftKeyboard() (asinteractiveobject.cpp)
};
// Recovered with ?\asdisplayobjectcontainer.cpp (src/ms2/gfxui/asdisplayobjectcontainer.cpp, 0x1422c6570-0x1422c70b0); each
// method calls the AS DisplayObjectContainer member of the same name. The Value arguments are by value (the callee
// destroys them); the MS2Ptr ones too.
class ASDisplayObjectContainer : public ASInteractiveObject
{
public:
    ASDisplayObjectContainer(const Scaleform::GFx::Value& v, int nMovieId);   // 0x1422c6570 (asloader.cpp)
    virtual ~ASDisplayObjectContainer();                                // 0 0x1422c65c0 (scalar deleting 0x1422c7070)
    void SetTabChildren(int bTab);                                       // set "tabChildren"
    void SetMouseChildren(bool b);                                         // set "mouseChildren" (uidungeonsearchsettingdialog)
    int GetNumChildren();                                                // numChildren
    int GetTabChildren();                                                // "tabChildren"
    int GetMouseChildren();                                                // "mouseChildren"
    int GetChildIndex(MS2Ptr<ASDisplayObject> spChild);                 // getChildIndex
    int Contains(const Scaleform::GFx::Value& child);              // contains
    Scaleform::GFx::Value AddChild(Scaleform::GFx::Value child);   // addChild (returns the child)
    Scaleform::GFx::Value AddChildAt(Scaleform::GFx::Value child, int nIndex);   // addChildAt (returns the child)
    Scaleform::GFx::Value GetChildAt(int nIndex);                   // getChildAt
    Scaleform::GFx::Value GetChildByName(const CString& strName);       // getChildByName (uipvpguildteamdialog)
    Scaleform::GFx::Value RemoveChild(Scaleform::GFx::Value child);   // removeChild
    Scaleform::GFx::Value RemoveChildAt(int nIndex);                   // removeChildAt
    Scaleform::GFx::Value GetParent();                             // "parent"
    void SetChildIndex(MS2Ptr<ASDisplayObject> spChild, int nIndex);    // setChildIndex
    void SwapChildren(MS2Ptr<ASDisplayObject> spChild1, MS2Ptr<ASDisplayObject> spChild2);   // swapChildren
    void SwapChildrenAt(int nIndex1, int nIndex2);                       // swapChildrenAt
    void RemoveFromParent();                                               // parent.removeChild(this)
};
// ASStage (RTTI .?AVASStage@@, 0x80, vftable 0x143111a78, ctor 0x1422cfcb0): the movie's stage; slot 5 returns itself.
class ASStage : public ASDisplayObjectContainer
{
public:
    ASStage(const Scaleform::GFx::Value& v, int nMovieId);     // 0x1422cfcb0 (new 0x80 in gfxmoviedamage.cpp FUN_140b62400)
    virtual ~ASStage();                                         // 0 0x1422cfd00 (scalar deleting 0x1422cffb0)
    virtual ASStage* vfunc_5();                                 // 5 0x1422cff80 returns itself
    // Recovered with ?\asstage.cpp (src/ms2/gfxui/asstage.cpp, 0x1422cfcb0-0x1422cfff0).
    void SetFocus(MS2Ptr<ASInteractiveObject> spFocus);   // set the stage "focus" (by value: the callee destroys it; asuicomponent.cpp)
    MS2Ptr<ASInteractiveObject> GetFocus();               // the focus: always NULL (the exe never reads it back)
    void SetStageWidth(int nWidth);                             // set "stageWidth"
    void SetStageHeight(int nHeight);                            // set "stageHeight"
    int GetStageWidth();                                        // "stageWidth"
    int GetStageHeight();                                        // "stageHeight"
};
// ASSprite (RTTI .?AVASSprite@@, 0x80, vftable 0x143115c78: only the dtor is overridden). Recovered with ?\assprite.cpp
// (src/ms2/gfxui/assprite.cpp, 0x1422e5be0-0x1422e6170); the comments name the AS member each method uses.
class ASGraphics;
class ASSprite : public ASDisplayObjectContainer
{
public:
    ASSprite(const Scaleform::GFx::Value& v, int nMovieId);    // 0x1422e5be0 (ASMovieClip's ctors call it)
    virtual ~ASSprite();                                        // 0 0x1422e5c30 (scalar deleting 0x1422e6020)
    MS2Ptr<ASGraphics> GetGraphics();                         // "graphics"
    void SetUseHandCursor(int bUse);                               // set "useHandCursor"
    int GetUseHandCursor();                                        // "useHandCursor"
    void StartDrag(int bLockCenter);                        // startDrag(lockCenter)
    void StopDrag();                                       // stopDrag()
};
MS2_CHECK_SIZE(ASSprite, 0x80);
// Recovered with ?\asmovieclip.cpp (src/ms2/gfxui/asmovieclip.cpp, 0x1422c1e40-0x1422c2fc0).
class ASMovieClip : public ASSprite
{
public:
    ASMovieClip(int nMovieId);                                  // 0x1422c1e40 (a fresh clip; asuicomponent.cpp)
    ASMovieClip(Scaleform::GFx::Value v, int nMovieId);         // 0x1422c1e90 (the Value is destroyed by the callee)
    ASMovieClip(CString strLinkage, int nMovieId);              // 0x1422c1ef0 (creates the clip from a linkage name)
    virtual ~ASMovieClip();                                     // 0 deleting 0x1422c2de0, dtor 0x1422c1fb0
    void SetEnabled(int bEnabled);                           // set "enabled"
    int IsEnabled();                                        // "enabled"
    // 6-11 invoke the AS MovieClip method of the same name, 12-15 go to a frame through the value's object interface
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
    int GetCurrentFrame();                                        // "currentFrame"
    CString GetCurrentFrameLabel();                                    // "currentFrameLabel" ("" if it is not a string)
    CString GetCurrentLabel();                                    // "currentLabel"
    int GetTotalFrames();                                        // "totalFrames"
    int LocalToGlobal(double* pX, double* pY);                  // localToGlobal(new Point): the stage position
    int GlobalToLocal(float* pX, float* pY);                    // globalToLocal(0, 0)
    int FUN_1422c2740(float x, float y, float* pX, float* pY);  // globalToLocal(x, y)
    int HitTestPoint(float x, float y, bool bShapeFlag);       // hitTestPoint (0 unless the result is a bool)
    // "click" / "doubleClick" / "rightClick" listeners (pUser: the pointer-sized user data handed back with the call)
    void FUN_1422c2a70(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);
    void FUN_1422c2a70(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, int nUser);   // the same function, an int user value (uishopdialog.cpp)
    void FUN_1422c2af0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    void FUN_1422c2b50(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);
    void FUN_1422c2bd0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    void FUN_1422c2c30(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb, void* pUser);   // asitemslot.cpp
    void FUN_1422c2cb0(const Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)>& cb);
    // sets "externalTooltipFunction" to an ASFunction of the delegate (cb by value: the callee destroys it)
    void SetExternalTooltipFunction(Delegate<void(const Scaleform::GFx::FunctionHandler::Params&)> cb, void* pUser);
};
MS2_CHECK_SIZE(ASMovieClip, 0x80);                              // exe allocates 0x80 bytes (asequipicon 0x1409b93ed)

// new ASDisplayObject(v, n) wrapped in an MS2Ptr (free function or static; 0x140d01be0).
MS2Ptr<ASDisplayObject> CreateDisplayObject(int n, const Scaleform::GFx::Value& v);

// ASLoader (RTTI .?AVASLoader@@, COL 0x1432d06b0, vftable 0x143115a90: only the dtor is overridden): an
// ASDisplayObjectContainer over a "scaleform.ms2.loader.debugLoader" (an AS3 flash.display.Loader) that shows an external
// image (the guild dialog's event image, uiguilddialog.h). Recovered with ?\asloader.cpp (src/ms2/gfxui/asloader.cpp);
// the method names are invented after the AS calls they make.
class ASURLRequest;
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
    MS2Ptr<ASEventDispatcher> m_spContentLoaderInfo;            // +0x80 the AS LoaderInfo (its "complete" event)
};
MS2_CHECK_SIZE(ASLoader, 0x90);
