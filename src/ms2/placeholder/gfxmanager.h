// gfxmanager.h - GFxManager (RTTI .?AVGFxManager@@, vftable 0x1431095e8), the GFx UI manager singleton of the game's GFx
// UI library: the Scaleform Loader and its states, the movies by movie id, the movie renderer, the UI sound, video and
// string table. Its code is the library's first obj (?\gfxmanager.cpp, src/ms2/gfxui/gfxmanager.cpp,
// 0x1422acf10-0x1422b7f20). NOT an original header (it stays under placeholder/ because many units include it here).
// The singleton getter 0x14025e7a0 returns the pointer stored at 0x143aaccf8. Several units still declare the getter
// with unit-local stand-in return types (Unk_GFxUIManager, Unk_UiMgr, ...); new code should include this header instead.
// RTTI: efd::MemObject @8 and SingletonClass<GFxManager> @9, 1 vftable slot (??_G 0x1422b4d60); 0x1f0 bytes (GFxService's
// EE_NEW). Layout from the ctor 0x1422acf10 / dtor 0x1422ad3a0; member names are invented.
//
// Movie ids (the keys of m_mapMovies): 0 GFxMovieHeadUpDisplay, 1 the damage text movie, 2 GFxMovieMain, 3
// GFxMoviePostDisplay, 4 the background movie, 5 GFxMovieTooltip, 6 GFxMovieMouseCursor.
#pragma once

#include <afx.h>
#include <atlcoll.h>
#include <efd/MemObject.h>
#include <NiRefObject.h>
#include <NiSmartPointer.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/gfxvalue.h"
#include "ms2/placeholder/gfximageloader.h"         // GFxImageLoader::ImageCallback, tfunctor2.h
#include "ms2/placeholder/singletonclass.h"
#include "ms2/placeholder/tfunctor_small.h"

#include "Kernel/SF_Atomic.h"
#include "Kernel/SF_File.h"
#include "Kernel/SF_String.h"

class ASMovieClipLoader;
class ASMouseCursor;
class ASStage;
class AScript;
class GFxMovie;
class GFxRenderer;                      // ms2/gfxui/nigfxoverlayclick.h
class GFxSoundFMOD;                     // ms2/gfxui/gfxsoundfmod.h
class GFxVideo;                         // ms2/placeholder/gfxvideo.h
class Ni2DBuffer;
class NiGFxLocalizeManager;             // ms2/gfxui/nigfxlocalizemanager.h
class NiRenderer;
class Unk_GFxUIRenderer2D;              // ms2/placeholder/gfxrenderer2d.h
class Unk_NotifyContext;                // ms2/gfxui/notifyhandler.h (the real class NotifyContext)
template <class T> class MS2Ptr;       // ms2/placeholder/ascript.h

class GFxManager : public efd::MemObject, public SingletonClass<GFxManager>
{
public:
    GFxManager();                                                   // 0x1422acf10
    virtual ~GFxManager();                                          // 0 0x1422ad3a0 (??_G 0x1422b4d60)
    int FUN_1422ad620(HWND hWnd, NiRenderer* pRenderer);            // initialise Scaleform (GFxService::OnInit; 0 = failed)
    int FUN_1422adb80(unsigned int uiWidth, unsigned int uiHeight); // the render target size (device restored); 1
    int FUN_1422adc90(GFxMovie* pMovie);                           // load and add the background movie (id 4)
    int FUN_1422addb0();                                            // remove it
    int FUN_1422ade10(GFxMovie* pMovie);                           // load and add the damage text movie (id 1)
    int FUN_1422adf30();                                            // remove it
    void FUN_1422adf90();                                           // render the movies (NiGFxOverlayClick)
    void FUN_1422ae180();                                           // per tick (GFxService::OnTick)
    void FUN_1422ae360();                                           // shutdown (GFxService::OnShutdown)
    void FUN_1422ae590();                                           // render device lost
    bool FUN_1422ae690();                                           // render device restored (false = failed)
    void FUN_1422ae7d0();                                           // hand the HAL and the Renderer2D to every movie
    void FUN_1422ae920(int n);                                      // m_184 =
    int FUN_1422ae940();                                            // m_184: nonzero = advance in one step
    void FUN_1422ae960(int bVisible);                               // "setVisible" of every movie clip loader
    void FUN_1422aeaa0(int nStep);                                  // "setVisibleStep"
    void FUN_1422aebe0(int nLayer, bool bVisible);                  // "setVisibleLayer"
    void FUN_1422aed30(bool b);                                     // GFxMovie::vfunc_5 of every movie
    void FUN_1422aee20(void (*pfn)(const Scaleform::GFx::FunctionHandler::Params&));   // m_pfnFormat =
    void FUN_1422aee50(TFunctor<bool, ParamList<HWND, EmptyParam> > fn);   // m_fnIme = fn (by value)
    void FUN_1422aeea0(void (*pfn)(AScript& kCommon, int nMovieId));        // m_pfnCommon =
    int FUN_1422aeed0(int n);                                       // input state query (NotifyDragSlot passes 2: drop outside any slot)
    void FUN_1422aef20(int nMovieId, int n);                        // GFxMovie::FUN_1422be380 of a movie
    int FUN_1422aef70();                                            // m_118 (paused)
    void FUN_1422aef90(int bPause);                                 // pause every movie
    int FUN_1422af090();                                            // m_b0 (resources from the archive)
    void FUN_1422af0b0(int bArchive, int bRelease);                 // the movie paths (gfx / gfxDebug)
    int FUN_1422af2d0(int nMovieId);                                // the movie takes text input (GFxMovieEventHandler: CharEvent, Insert)
    int FUN_1422af390(int nMovieId);                                // WM_IME_COMPOSITION handled by the manager
    int FUN_1422af580(int nMovieId);                                // the window has the focus and the movie takes text input
    CStringW FUN_1422af5f0(int nMovieId);                           // the IME composition string
    int FUN_1422af7a0(int nMovieId);                                // input state of a movie (UISwfEntityManager::FUN_1422d1c20 passes 2)
    unsigned FUN_1422af8a0(int nMovieId);                           // the IME conversion mode (0x1000000 if none)
    CString FUN_1422af960(int nMovieId);                            // the IME input language ("UNKNOWN")
    void FUN_1422afb00();                                           // "unloadCache" of every movie clip loader
    void FUN_1422afc00();                                           // GFx::Movie slot 48 of every movie
    Ni2DBuffer* FUN_1422afcf0();                                    // the renderer's render texture buffer
    void FUN_1422afd50(bool bMute);                                 // the UI sound renderer slot 9
    void FUN_1422afdd0(float fVolume);                              // the UI sound volume
    void FUN_1422afe50();                                           // recreate the UI sound
    void FUN_1422afe90();                                           // drop the UI sound
    float FUN_1422afec0(int nMovieId);                              // the scale of a movie (1.0f if not loaded)
    int FUN_1422aff10(float fScale);                                // scale every movie except the background
    void FUN_1422b0060(float fScale);                               // the same without the viewport (if it differs from movie 2's)
    GFxMovie* FUN_1422b01a0(int nMovieId);                          // the movie of a movie id (NULL if not loaded)
    GFxVideo* FUN_1422b0230();                                      // m_spVideo
    Unk_NotifyContext* FUN_1422b0260();                             // the notify context (SmartPointer at +0x98)
    Scaleform::GFx::Loader* FUN_1422b0290();                        // the loader
    Unk_GFxUIRenderer2D* FUN_1422b02b0();                           // the movie renderer's Renderer2D (+0x40 member, slot 2)
    MS2Ptr<ASStage> FUN_1422b02f0(int nMovieId);                    // the stage of a movie (null if the movie is not loaded)
    MS2Ptr<ASMouseCursor> FUN_1422b0370(int nMovieId);              // the mouse cursor of a movie
    MS2Ptr<ASMovieClipLoader> FUN_1422b03f0(int nGroup);            // the movie clip loader of a GFX_* group (by value)
    void FUN_1422b0470(int nMovieId, int* pnWidth, int* pnHeight);  // the viewport size of a movie
    int FUN_1422b04d0(int nMovieId);                                // its width
    int FUN_1422b0520(int nMovieId);                                // its height
    CStringW FUN_1422b0570(const CString& strKey);                  // the localized string of a key ("" without string table)
    int FUN_1422b0610(const CString& strSound, const CString& strArg); // play a UI sound (NotifySwfEntity "playSound")
    void FUN_1422b0690(TFunctor<unsigned int, ParamList<const CString&, ParamList<const CString&, EmptyParam> > > fn);
    void FUN_1422b06e0(int nMovieId, int* pnWidth, int* pnHeight);  // the stage size of a movie
    void FUN_1422b0790(int nMovieId);                               // remember the stage size of a movie ("initializeClass")
    void FUN_1422b0840(int nMovieId, int* pnWidth, int* pnHeight);  // the remembered stage size
    void FUN_1422b08f0(const char* szFormat, ...);                  // log line (GFxRenderSingleThread reset failures)
    void FUN_1422b09a0();                                           // reload the string tables
    int FUN_1422b09d0(CString a, CString b, int n);                 // m_pfn110(a, b, n) (0 without callback)
    int FUN_1422b0a70(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);   // GFxService::vfunc_18
    int FUN_1422b0bc0(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);   // GFxService::vfunc_19 (every window message)
    CString FUN_1422b0d10();                                        // the path of the IME movie
    Scaleform::Ptr<Scaleform::File> FUN_1422b0d60(Scaleform::String strPath);   // the cached memory file of a path
    void FUN_1422b0e20(Scaleform::String strPath, Scaleform::Ptr<Scaleform::File> pFile);   // cache (NULL: drop) it
    void FUN_1422b0ea0(const CStringW& strText);                    // copy to the clipboard (GFxMovieMain)
    int FUN_1422b0f10();                                            // close the tooltips (GFxMovieTooltip::FUN_1422f1020)
    int FUN_1422b0f70(HWND hWnd);                                   // create the video
    int FUN_1422b1030();                                            // the loader states
    int FUN_1422b1620(CString strFontConfig, const CString& strLocale);   // the string tables / font config
    int FUN_1422b1750(NiRenderer* pRenderer);                       // create the renderer
    int FUN_1422b1820(HWND hWnd);                                   // the IME manager
    int FUN_1422b19d0(HWND hWnd, CString strPath);                  // load GFxMovieMain (id 2)
    int FUN_1422b1bb0(HWND hWnd, CString strPath);                  // load GFxMovieTooltip (id 5)
    int FUN_1422b1d70(HWND hWnd, CString strPath);                  // load GFxMovieMouseCursor (id 6)
    int FUN_1422b1f30(HWND hWnd, CString strPath);                  // load GFxMovieHeadUpDisplay (id 0)
    int FUN_1422b20f0(HWND hWnd, CString strPath);                  // load GFxMoviePostDisplay (id 3)
    int FUN_1422b22b0();                                            // create the UI sound
    void FUN_1422b24f0();                                           // reload the movies
    bool FUN_1422b2760();                                           // GFxMovieMain::FUN_1422f0450
    bool FUN_1422b27c0();                                           // m_1e8
    void FUN_1422b27e0(bool b);                                     // m_1e8 =
    // render device ready flag (inline; COMDAT 0x1422f58f0 in ?\gfxrendersinglethread.cpp: 0 on reset/lost, 1 restored)
    void FUN_1422f58f0(int bReady) { m_180 = bReady; }

private:
    MS2_LAYOUT_FRIEND;
    Scaleform::Lock m_lock;                                         // +0x10 guards m_mapMovies
    NiPointer<GFxVideo> m_spVideo;                                  // +0x38
    NiPointer<GFxRenderer> m_spRenderer;                            // +0x40 GFxRenderSingleThread
    CRBMap<int, NiPointer<GFxMovie> > m_mapMovies;                  // +0x48 movie id -> movie
    Scaleform::GFx::Loader m_loader;                                // +0x78
    NiPointer<Unk_NotifyContext> m_spNotifyContext;                 // +0x98
    NiPointer<NiGFxLocalizeManager> m_spLocalize;                   // +0xa0
    NiPointer<GFxSoundFMOD> m_spSound;                              // +0xa8
    int m_bArchive;                                                 // +0xb0 ctor 1
    CString m_strIme;                                               // +0xb8 the movie paths
    CString m_strFontConfig;                                        // +0xc0
    CString m_strMain;                                              // +0xc8
    CString m_strTooltip;                                           // +0xd0
    CString m_strBackground;                                        // +0xd8
    CString m_strMouseCursor;                                       // +0xe0
    CString m_strHeadUpDisplay;                                     // +0xe8
    CString m_strPostDisplay;                                       // +0xf0
    CString m_strDamageText;                                        // +0xf8
    HWND m_hWnd;                                                    // +0x100 not set by the ctor
    void (*m_pfnLog)(CString strLine);                              // +0x108
    int (*m_pfn110)(const CString& a, const CString& b, int n);                   // +0x110
    int m_bPause;                                                   // +0x118
    void (*m_pfnFormat)(const Scaleform::GFx::FunctionHandler::Params& params);   // +0x120 GFxMovie::m_70
    TFunctor<bool, ParamList<HWND, EmptyParam> > m_fnIme;           // +0x128
    void (*m_pfnCommon)(AScript& kCommon, int nMovieId);            // +0x130 GFxMovie::m_78
    GFxImageLoader::ImageCallback m_fnImage;                        // +0x138 the "img://" image callback
    TFunctor<unsigned int, ParamList<const CString&, ParamList<const CString&, EmptyParam> > > m_fnSound;   // +0x140
    int m_anStageWidth[7];                                          // +0x148
    int m_anStageHeight[7];                                         // +0x164
    int m_180;                                                      // +0x180 render device ready
    int m_184;                                                      // +0x184
    Scaleform::Lock m_lockFiles;                                    // +0x188 guards m_mapFiles
    CRBMap<Scaleform::String, Scaleform::Ptr<Scaleform::File> > m_mapFiles;   // +0x1b0
    CStringW m_strComposition;                                      // +0x1e0 the last IME composition string
    bool m_1e8;                                                     // +0x1e8 movies reloaded
};
MS2_CHECK_OFFSET(GFxManager, m_lock, 0x10);
MS2_CHECK_OFFSET(GFxManager, m_mapMovies, 0x48);
MS2_CHECK_OFFSET(GFxManager, m_loader, 0x78);
MS2_CHECK_OFFSET(GFxManager, m_strIme, 0xb8);
MS2_CHECK_OFFSET(GFxManager, m_hWnd, 0x100);
MS2_CHECK_OFFSET(GFxManager, m_fnIme, 0x128);
MS2_CHECK_OFFSET(GFxManager, m_anStageWidth, 0x148);
MS2_CHECK_OFFSET(GFxManager, m_180, 0x180);
MS2_CHECK_OFFSET(GFxManager, m_mapFiles, 0x1b0);
MS2_CHECK_OFFSET(GFxManager, m_1e8, 0x1e8);
MS2_CHECK_SIZE(GFxManager, 0x1f0);
GFxManager* FUN_14025e7a0();                                        // the singleton
