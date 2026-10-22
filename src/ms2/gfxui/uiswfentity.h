// uiswfentity.h - UISwfEntity, the base of every Scaleform UI object (RTTI .?AVUISwfEntity@@, 0x68 bytes).
// Recovered with ?\uiswfentity.cpp (src/ms2/gfxui/uiswfentity.cpp). The header name and directory are assumed: the
// GFx UI library (0x1422b0000-0x142304000: GFxManager, UISwfEntityManager, AS*, UIMsg) has no __FILE__ strings.
//
// Bases: CPtred (+0x00), IMessageListener (+0x18). Primary vftable 0x1431129c0 (47 slots), IMessageListener-in-
// UISwfEntity 0x143112b40. Derived: UIObject (52 slots) -> UIDialog (84 slots) -> ~280 dialogs.
//
// Names: the exe has none for the methods. Virtuals keep Ghidra's `vfunc_<slot>` and non-virtuals `FUN_<va>`, so the
// Ghidra decompile of derived classes (which prints exactly those names) maps 1:1 onto this header; the comments
// say what each one does. Members are `m_<offset>`. The signatures come from the /Od prologues (parameter homing)
// of the implementations in UISwfEntity and all 401 derived classes (work/uibase/slotsig.py), so overrides compile
// as is. Pointer parameters whose pointee is unknown are `void*`; cast them in the override.
//
// Ownership: wave-1 foundation (docs/RECOVERY.md section 12). The slot list and layout are complete: do not edit;
// unit agents only read it.
#pragma once

#include <afx.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/cptred.h"
#include "ms2/placeholder/delegate.h"
#include "ms2/placeholder/gfxvalue.h"
#include "ms2/placeholder/imessagelistener.h"
#include "ms2/placeholder/tptr.h"

class ASData;               // ActionScript call arguments (RTTI .?AVASData@@, base CPtred; UIMsg derives from it)
class ASDisplayObject;
class GfxException;
class Unk_UISwfEntity_25;   // pointee of vfunc_25's TPtr argument (TPtr<T>::~TPtr is 0x140a5a8c0; T unknown)

class UISwfEntity : public CPtred, public IMessageListener
{
public:
    UISwfEntity();                                                                                      // 0x1422db480
    virtual ~UISwfEntity();                                                                             //  0 0x1422db5d0 (??_G 0x1422dcb70)
    virtual CString GetTypeName();                                                                          //  1 class name ("SwfEntity"; UI{0}.swf base name)
    virtual void vfunc_2();                                                                             //  2
    virtual void vfunc_3();                                                                             //  3
    virtual int vfunc_4();                                                                              //  4 returns 0
    virtual int vfunc_5();                                                                              //  5 returns 0 (OnLoadComplete calls it)
    virtual int vfunc_6();                                                                              //  6 returns 0
    virtual CString vfunc_7();                                                                          //  7 swf name; default GetTypeName()
    virtual void vfunc_8(int nVisible);                                                                 //  8 root movie clip SetVisible
    virtual int vfunc_9();                                                                              //  9 root movie clip IsVisible
    virtual void vfunc_10();                                                                            // 10
    virtual void vfunc_11();                                                                            // 11
    virtual void vfunc_12();                                                                            // 12
    virtual int vfunc_13();                                                                             // 13 returns 0
    virtual int vfunc_14();                                                                             // 14 returns 0
    virtual void vfunc_15();                                                                            // 15
    virtual void vfunc_16();                                                                            // 16
    virtual bool vfunc_17();                                                                            // 17 returns true
    virtual void vfunc_18();                                                                            // 18 FUN_1422dc450(); vfunc_15()
    virtual void vfunc_19();                                                                            // 19 show/focus (m_60 = 1 ...)
    virtual void OnLoadInit();                                                                          // 20
    virtual void vfunc_21();                                                                            // 21
    virtual void OnLoadComplete();                                                                      // 22 vfunc_8(m_58); vfunc_5(); FUN_1422dc450()
    virtual void vfunc_23(void* p);                                                                     // 23
    virtual void vfunc_24(float x, float y);                                                            // 24
    virtual void vfunc_25(void* p1, TPtr<Unk_UISwfEntity_25> p2, void* p3, void* p4);                   // 25 p2 by value (callee destroys)
    virtual void vfunc_26();                                                                            // 26 called on unload, before the movie is dropped
    virtual void vfunc_27();                                                                            // 27 called on unload, after the manager call
    virtual int vfunc_28(const char* szMethod, const Scaleform::GFx::Value* pArgs, unsigned int nArgs); // 28 AS -> C++ call; returns 0
    virtual void vfunc_29(void* p);                                                                     // 29
    virtual void vfunc_30(const CString& a1, const CString& a2, const CString& a3);                     // 30
    virtual void vfunc_31(const CString& a1, float a2, const void* a3);                                 // 31
    virtual void vfunc_32(void* p, float x, float y);                                                   // 32 mouse/drag events (32-39)
    virtual void vfunc_33(void* p, float x, float y);                                                   // 33
    virtual void vfunc_34(void* p, float x, float y);                                                   // 34
    virtual void vfunc_35(void* p, float x, float y);                                                   // 35
    virtual void vfunc_36(void* p, float x, float y);                                                   // 36
    virtual void vfunc_37(void* p, float x, float y);                                                   // 37
    virtual void vfunc_38(void* p, float x, float y);                                                   // 38
    virtual void vfunc_39(void* p, float x, float y, float f);                                         // 39 (4th arg: UIUGCCubePaletteDialog forwards it)
    virtual void vfunc_40();                                                                            // 40
    virtual void vfunc_41(const Scaleform::GFx::Value& root);                                           // 41 movie loaded: m_30 = root object
    virtual void vfunc_42(GfxException* pException);                                                    // 42 load error (UIObject: MessageBox(e->what()))
    virtual void vfunc_43();                                                                            // 43
    virtual void vfunc_44(int a1, int a2, int a3, int* pWidth, int* pHeight);                           // 44 resize root; returns its size
    virtual void vfunc_45(Scaleform::GFx::Value* pRetVal, const CString& strMethod, ASData* pArgs);     // 45 ExternalInterface call (UIObject: "getTooltip", ...)
    virtual int vfunc_46();                                                                             // 46 movie loaded (m_30 != NULL)

    // IMessageListener (vftable at +0x18; the exe passes this = the IMessageListener subobject: hook overrides with
    // MS2_REPLACE_METHOD_VIA)
    virtual int OnMessage(UISwfEntity* pSender, UIMsg* pMsg);                                          //  0 returns 0

    // Returns the AS child `strName` of this entity's movie (COMDAT template; 0x14135b280 for T = Unk_ASVideoPlayer).
    template <class T> MS2Ptr<T> GetChild(const CString& strName);

    CString FUN_1422db6e0();                                // m_20 (the manager key)
    int FUN_1422db730();                                    // m_28
    int FUN_1422db750();                                    // m_2c
    int FUN_1422db770();                                    // m_44
    CString FUN_1422db790();                                // swf file name: "UI{vfunc_7()}.swf" ("Debug_UI..." if m_40)
    CString FUN_1422db910(void* p);                         // resolve a path through the GFx file system
    MS2Ptr<AScript> FUN_1422dba00();                        // m_30
    MS2Ptr<ASDisplayObject> FUN_1422dba50();                // m_30 as ASDisplayObject
    const Scaleform::GFx::Value& FUN_1422dbb40();           // m_30's GFx value (an undefined Value when not loaded)
    const Scaleform::GFx::Value& FUN_1422dbc00();           // FUN_1422dbb40()
    void FUN_1422dbd70(int a1, int a2);                     // register with the manager without loading
    void FUN_1422dbf00(int a1, int a2, int a3);             // load the swf: FUN_1422dbf80(FUN_1422db790(), ...)
    void FUN_1422dbf80(const CString& strPath, int a1, int a2, int a3);    // load strPath (m_2c = a1, m_44 = a2)
    void FUN_1422dc080();                                   // vfunc_4(); FUN_1422dc0b0()
    void FUN_1422dc0b0();                                   // unload (vfunc_26, manager, vfunc_27, m_30 = NULL)
    void FUN_1422dc1e0();                                   // reload when FUN_1422dc310()
    void FUN_1422dc260(int n);
    void FUN_1422dc2b0(int n);                              // m_4c = n
    int FUN_1422dc2d0();                                    // m_4c
    void FUN_1422dc2f0(int n);                              // m_50 = n
    int FUN_1422dc310();                                    // m_50 if registered, else 0
    void FUN_1422dc370(int n);                              // m_54 = n
    int FUN_1422dc390();                                    // m_54
    void FUN_1422dc3b0(int n);                              // m_5c = n
    int FUN_1422dc3d0();                                    // m_5c
    int FUN_1422dc410();                                    // m_48
    int FUN_1422dc430();                                    // m_54
    void FUN_1422dc450();                                   // after load/show: focus handling, m_60 = 0
    void FUN_141904ad0(const int* pnDepth) { m_2c = *pnDepth; }    // 0x141904ad0 (inline, uicommon.cpp)

    // Optional override of FUN_1422db790 (set from 0x141629ed0): (name, debug) -> swf file name.
    static Delegate<CString(CString, bool)> s_swfNameDelegate;      // 0x143b0d2f0
    static void FUN_141629ed0(Delegate<CString(CString, bool)> d);  // defined in client/ms2/ms2memfile.cpp

protected:
    MS2_LAYOUT_FRIEND;
    CString m_20;                       // +0x20 manager key; "" (s_strNoKey) while not registered
    int m_28;                           // +0x28 2; manager layer/group, passed to every manager call
    int m_2c;                           // +0x2c depth/layer argument of the load (UICutSceneMovie: 0x21)
    MS2Ptr<AScript> m_30;               // +0x30 the movie's root AS object (NULL until loaded)
    int m_40;                           // +0x40 nonzero: load Debug_UI{0}.swf
    int m_44;                           // +0x44
    int m_48;                           // +0x48
    int m_4c;                           // +0x4c
    int m_50;                           // +0x50 1
    int m_54;                           // +0x54
    int m_58;                           // +0x58 1; visibility applied on load (vfunc_8(m_58))
    int m_5c;                           // +0x5c
    int m_60;                           // +0x60 set by vfunc_19, cleared once loaded
};
MS2_CHECK_SIZE(UISwfEntity, 0x68);
MS2_CHECK_OFFSET(UISwfEntity, m_20, 0x20);
MS2_CHECK_OFFSET(UISwfEntity, m_28, 0x28);
MS2_CHECK_OFFSET(UISwfEntity, m_2c, 0x2c);
MS2_CHECK_OFFSET(UISwfEntity, m_30, 0x30);
MS2_CHECK_OFFSET(UISwfEntity, m_40, 0x40);
MS2_CHECK_OFFSET(UISwfEntity, m_4c, 0x4c);
MS2_CHECK_OFFSET(UISwfEntity, m_58, 0x58);
MS2_CHECK_OFFSET(UISwfEntity, m_60, 0x60);
