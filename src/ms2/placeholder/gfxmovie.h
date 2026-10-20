// gfxmovie.h - PLACEHOLDER for GFxMovie and GFxMovieEventHandler, the bases of the Scaleform movie wrappers
// (GFxMovieBackground/Damage/Ugc/Main/Tooltip/MouseCursor/HeadUpDisplay/PostDisplay). NOT an original header; the
// out-of-line members live in the GFx UI library (0x1422b0000-0x142304000, no unit recovered yet) and are bound through
// progress/symbols-manual.tsv. Slot names are Ghidra's (vfunc_<slot>); signatures from the /Od prologues
// (work/uibase/slotsig.py) and the base bodies' decompiles.
//
// GFxMovie : NiRefObject, 0x80 bytes. RTTI .?AVGFxMovie@@, vftable 0x14310aa60 (16 slots), ctor 0x1422bced0, dtor 0x1422bcfe0
// (scalar deleting 0x1422bf490). Wraps a loaded GFx movie: the Ptr<GFx::Movie> at +0x60 is what the slots call through
// (vtable +0x58 SetViewport, +0x100 SetVisible?, +0x110 HandleEvent, ...).
// GFxMovieEventHandler : GFxMovie, 0x90 bytes. vftable 0x143112638 (40 slots: the Win32 input messages -> GFx events),
// ctor 0x1422d8dc0, dtor 0x1422d8e20 (scalar deleting 0x1422db0b0).
// Derived classes start at 0x90.
#pragma once

#include <afx.h>
#include <NiRefObject.h>
#include <NiRTTI.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/ascript.h"
#include "ms2/placeholder/gfxvalue.h"

class ASStage;                          // 0x80, base ASDisplayObjectContainer (vftable 0x143111a78, ctor 0x1422cfcb0)
class ASMovieClipLoader;                // 0x80, base ASEventDispatcher (vftable 0x143111c90, ctor 0x1422cfff0)
class ASMouseCursor;                    // 0x90, base ASGameEntity (vftable 0x14310d408; methods "unlock", "changeType")
// Target of the two Ptr<> arguments of vfunc_9/10 (a ref-counted Scaleform render/handle object, released through
// 0x14257dcb0; the two parameters cannot be told apart by their release code, so both use this one name).
class Unk_GFxHandleObj;

#if defined(MS2_HAVE_SCALEFORM_SDK)
#define MS2_GFX_PTR(T) Scaleform::Ptr<T>
#define MS2_GFX_LOADER Scaleform::GFx::Loader
#define MS2_GFX_MOVIE Scaleform::GFx::Movie
#define MS2_GFX_MOVIEDEF Scaleform::GFx::MovieDef
#else
#define MS2_GFX_PTR(T) T*
#define MS2_GFX_LOADER void
#define MS2_GFX_MOVIE void
#define MS2_GFX_MOVIEDEF void
#endif

class GFxMovie : public NiRefObject
{
public:
    GFxMovie();                                                     // 0x1422bced0
    virtual ~GFxMovie();                                            //  0 0x1422bcfe0 (scalar deleting 0x1422bf490)
    // 1 = NiRefObject::DeleteThis (0x141d16bf0)
    virtual void* vfunc_2();                                        //  2 0x1422bf590 returns &DAT_143b0ae40 (a static descriptor)
    // 3 0x1422bd350 (empty): an AS call of the movie (method name, arguments); GFxMovieMouseCursor forwards three of them
    virtual void vfunc_3(const char* szEvent, const Scaleform::GFx::Value* pArgs, unsigned nArgs);
    void FUN_1422be560(MS2Ptr<ASMouseCursor> spCursor);             // 0x1422be560 m_30 = spCursor (by value: the callee destroys it)
    virtual void vfunc_4(void*, const char*, const Scaleform::GFx::Value*, unsigned);   //  4 0x1422bd370 (empty)
    virtual void vfunc_5(bool);                                     //  5 0x1422bd390 movie slot +0x40(!b)
    // 6 0x1422bd3f0: stores the loader at +0x58, CreateMovie(path, flags) -> MovieDef (+0x68), CreateInstance -> Movie (+0x60);
    // the path is a CString taken by value (the callee destroys it).
    virtual int vfunc_6(MS2_GFX_LOADER* pLoader, CString strPath, int nLoadFlags);
    virtual int vfunc_7(int x, int y);                              //  7 0x1422bd880 returns 1; sends a mouse-move event
    virtual void vfunc_8(float fTime);                              //  8 0x1422bda00 advance
    virtual void vfunc_9(MS2_GFX_PTR(Unk_GFxHandleObj), MS2_GFX_PTR(Unk_GFxHandleObj));    //  9 0x1422bdb90 (both Ptr<> by value)
    virtual void vfunc_10(MS2_GFX_PTR(Unk_GFxHandleObj), MS2_GFX_PTR(Unk_GFxHandleObj));   // 10 0x1422bdc50
    virtual void vfunc_11();                                        // 11 0x1422bdd20 release the movie handles
    virtual void vfunc_12();                                        // 12 0x1422bddd0 (empty)
    virtual bool vfunc_13();                                        // 13 0x1422bdde0 returns true
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x1422bddf0 returns 0
    virtual int vfunc_15(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 15 0x1422bde10 returns 0
    static const NiRTTI ms_RTTI;                                    // 0x143b0ae40 ("GFxMovie", no parent; vfunc_2 returns it)

    // Non-virtual members called by the derived movies' "initializeClass" handlers (GFxMovieHeadUpDisplay/PostDisplay).
    void FUN_1422be510(MS2Ptr<ASStage> spStage);                    // 0x1422be510 m_20 = spStage (by value: the callee destroys it)
    void FUN_1422be5b0(MS2Ptr<ASMovieClipLoader> spLoader);         // 0x1422be5b0 m_40 = spLoader (by value)
    void FUN_1422be140();                                           // 0x1422be140
    void FUN_1422be2a0();                                           // 0x1422be2a0 (uses m_78)
    MS2Ptr<ASMovieClipLoader> FUN_1422be4c0();                      // 0x1422be4c0 returns m_40 (GFxMovieMain::vfunc_5)
    void FUN_1422be380(int n);                                      // 0x1422be380 m_10 = n (GFxMovieDamage ctor: 0)
    MS2_GFX_MOVIE* FUN_1422bd0f0();                                 // 0x1422bd0f0 the GFx::Movie (m_60) or null (gfxmoviedamage.cpp)
    // The AS class object of a fully qualified class name ("scaleform.ms2.manager.TooltipManager"; the CString is taken by
    // value: the callee destroys it). astooltipmanager.cpp.
    Scaleform::GFx::Value FUN_1422bd120(CString strClassName);      // 0x1422bd120

    // 0x10..0x80, ctor 0x1422bced0. The three 16-byte handles are MS2Ptr<T> (pointer at +8, intrusive CPtred count:
    // ctor FUN_1422b31e0/b31a0/b31c0 zero +8, dtors FUN_140b62a60/140a58400/140b62a30). The two Scaleform handles are
    // Ptr<> with the SDK's AddRef/Release (FUN_14257dc30/142573e70 for the Movie, FUN_1425a3850/1425a4030 for the MovieDef).
    // Movie vtable slots of the exe equal the SDK's Scaleform::GFx::Movie 4.1.19 slot numbers (dtor = slot 0,
    // SetViewport 0x58, Advance 0xb8, GetDisplayHandle 0xc8, SetBackgroundAlpha 0x100, HandleEvent 0x110).
    int m_10;                                                       // +0x10 ctor 0
    float m_14;                                                     // +0x14 ctor 1.0f
    int m_18;                                                       // +0x18 not set by the ctor (derived classes store 4)
    int m_pad_1c;
    MS2Ptr<ASStage> m_20;                                           // +0x20 the stage object (created by FUN_140b62400)
    MS2Ptr<ASMouseCursor> m_30;                                     // +0x30 the mouse cursor (type 6 of the movie manager)
    MS2Ptr<ASMovieClipLoader> m_40;                                 // +0x40 vfunc_11 invokes "shutdown" on it (FUN_140b62350)
    int m_50;                                                       // +0x50 ctor 0
#if defined(MS2_HAVE_SCALEFORM_SDK)
    Scaleform::KeyModifiers m_54;                                   // +0x54 the last key modifiers (ctor FUN_14127c3b0)
    Scaleform::UInt8 m_pad_55[3];
#else
    int m_54;                                                       // +0x54 (ctor FUN_14127c3b0: a byte at +0x54)
#endif
    MS2_GFX_LOADER* m_58;                                           // +0x58 ctor 0; vfunc_6 argument
    MS2_GFX_PTR(MS2_GFX_MOVIE) m_60;                                // +0x60 Ptr<GFx::Movie> (accessor FUN_14127c960 / FUN_14127c910 = non-null)
    MS2_GFX_PTR(MS2_GFX_MOVIEDEF) m_68;                             // +0x68 Ptr<GFx::MovieDef> (Loader::CreateMovie result)
    void* m_70;                                                     // +0x70 ctor 0
    void* m_78;                                                     // +0x78 ctor 0
};
MS2_CHECK_SIZE(GFxMovie, 0x80);

// Wrap an AS object of movie nMovieId in a new ASStage / ASMovieClipLoader (new 0x80 + ctor 0x1422cfcb0 / 0x1422cfff0).
// Template-looking COMDAT pair in the ?\gfxmoviedamage.cpp range; the names are invented.
MS2Ptr<ASStage> FUN_140b62400(int nMovieId, const Scaleform::GFx::Value& v);
MS2Ptr<ASMovieClipLoader> FUN_140b62350(int nMovieId, const Scaleform::GFx::Value& v);
MS2_CHECK_OFFSET(GFxMovie, m_20, 0x20);
MS2_CHECK_OFFSET(GFxMovie, m_60, 0x60);
MS2_CHECK_OFFSET(GFxMovie, m_78, 0x78);

class GFxMovieEventHandler : public GFxMovie
{
public:
    static const NiRTTI ms_RTTI;                                    // 0x143b0d2e0 (symbols-manual data row; vfunc_2 returns it)
    GFxMovieEventHandler();                                         // 0x1422d8dc0
    virtual ~GFxMovieEventHandler();                                //  0 0x1422d8e20 (scalar deleting 0x1422db0b0)
    virtual void* vfunc_2() { return (void*)&ms_RTTI; }             //  2 0x1422db110 (COMDAT)
    virtual void vfunc_11();                                        // 11 0x1422d9f50 GFxMovie::vfunc_11 + FUN_1422d8f90(this, m_88)
    virtual int vfunc_14(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 14 0x1422d9040 the WM_ switch
    virtual int vfunc_15(void* hwnd, unsigned msg, unsigned __int64 wParam, __int64 lParam);   // 15 0x1422d9c30 IME pre-processing (1 = handled)
    virtual void vfunc_16();                                        // 16 0x1422d9db0
    virtual void vfunc_17(void* hwnd);                              // 17 0x1422d9e60 (hwnd unused)
    virtual void vfunc_18(void* hwnd);                              // 18 0x1422d9ef0 (hwnd unused)
    virtual void vfunc_19(void*);                                   // 19 0x1422d9f90 (empty)
    virtual void vfunc_20(void*);                                   // 20 0x1422d9fb0 (empty)
    virtual void vfunc_21(void*);                                   // 21 0x1422d9fd0 vfunc_19; m_80 = GetTickCount()
    virtual void vfunc_22(void*);                                   // 22 0x1422da020 vfunc_20
    virtual void vfunc_23(void*);                                   // 23 0x1422da060 vfunc_20
    virtual void vfunc_24(void* hwnd);                              // 24 0x1422da0a0 paste from the clipboard
    virtual void vfunc_25(void* hwnd, unsigned __int64 wParam, __int64 lParam);   // 25 0x1422da150 WM_DRAWCLIPBOARD chain
    virtual void vfunc_26(void* hwnd, float x, float y);            // 26 0x1422da1e0 mouse move (TrackMouseEvent)
    virtual void vfunc_27(void* hwnd, float x, float y);            // 27 0x1422da2e0 (empty)
    virtual void vfunc_28(void* hwnd, float x, float y);            // 28 0x1422da300 vfunc_20
    virtual void vfunc_29(void* hwnd, float x, float y);            // 29 0x1422da340 (empty)
    virtual void vfunc_30(void* hwnd, float x, float y, float fDelta);   // 30 0x1422da360 mouse wheel
    virtual void vfunc_31(void* hwnd, float x, float y);            // 31 0x1422da420
    virtual void vfunc_32(void* hwnd, float x, float y);            // 32 0x1422da4e0
    virtual void vfunc_33(void* hwnd, float x, float y);            // 33 0x1422da5a0
    virtual void vfunc_34(void* hwnd, float x, float y);            // 34 0x1422da660
    virtual void vfunc_35(void* hwnd, float x, float y);            // 35 0x1422da720
    virtual void vfunc_36(void* hwnd, float x, float y);            // 36 0x1422da7e0
    virtual int vfunc_37(void* hwnd, int n, void* a, void* b);      // 37 0x1422da8a0 IME message -> IMEWin32Event (1 = handled)
    virtual int vfunc_38(void* hwnd, int n, unsigned __int64 wParam, __int64 lParam);  // 38 0x1422da960 WM_KEY*/WM_SYSKEY*
    // 39 0x1422daa40 OnKey(controller, Key::Code, wchar, down, KeyModifiers): a CharEvent for wchar-only keys, then
    // SendKeyEvent. The last parameter is a Scaleform::KeyModifiers (one byte by value, the same ABI as bool); it stays
    // bool here because GFxMovieBackground (client/ms2/gfxmoviebackground.h) overrides the slot with this signature.
    virtual void vfunc_39(int a, int b, int c, bool d, bool e);

    // The Win32 -> GFx input helpers (the Scaleform Platform_WinAPI.cpp AppImpl code). ?\gfxmovieeventhandler.cpp.
    void FUN_1422d8f00(CStringW strText);                           // 0x1422d8f00 set the GFx text clipboard (by value)
    void FUN_1422d8f90(void* hwnd);                                 // 0x1422d8f90 ChangeClipboardChain (WM_DESTROY)
    void FUN_1422d8fd0(const CStringW& strText);                    // 0x1422d8fd0 FUN_1422d8f00(copy)
    static void FUN_1422d9020(bool bEnable);                        // 0x1422d9020 ms_bImeEnabled = bEnable
#if defined(MS2_HAVE_SCALEFORM_SDK)
    void ProcessKey(unsigned vkCode, bool bDown, bool bExtendedKey);   // 0x1422dab20 processKey: VK -> Key::Code, OnKey
    void SendKeyEvent(int nKeyboard, int nKeyCode, unsigned nWchar, bool bDown,
                       Scaleform::KeyModifiers kMods);              // 0x1422dac60 sends the KeyEvent
    Scaleform::KeyModifiers UpdateModifiers(bool bExtendedKey);       // 0x1422dad70 updateModifiers (also stored at +0x54)
#endif

    // m_88 = SetClipboardViewer(hwnd) (0 when it returns hwnd itself); true if a next viewer is set. GFxMovieMain::vfunc_17.
    int FUN_1422d8e80(void* hwnd);                                  // 0x1422d8e80

    static bool ms_bImeEnabled;                                     // 0x143a290d0 (initially true; vfunc_15 IME pre-processing)

    unsigned m_80;                                                  // +0x80 tick count of the last input
    int m_84;                                                       // +0x84 mouse-tracking flag
    void* m_88;                                                     // +0x88 an HWND
};
MS2_CHECK_SIZE(GFxMovieEventHandler, 0x90);
MS2_CHECK_OFFSET(GFxMovieEventHandler, m_88, 0x88);
