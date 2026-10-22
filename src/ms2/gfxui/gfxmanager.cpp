// Recovered from MapleStory2.exe KMS2_DEV x64 (2022-04-13). GFxManager, the GFx UI manager singleton: the Scaleform
// loader and its states, the movies by movie id, the movie renderer, the UI sound, video and string table.
// MS2-UNIT: ?\gfxmanager.cpp
// MS2-RANGE: 0x1422acf10-0x1422b7f20 .text$mn
//
// The unit name and directory are assumed (the GFx UI library 0x1422b0000-0x142304000 has no __FILE__ strings). The obj
// starts right after the Scaleform lib's IMM32 import thunks (0x1422acf10 = the ctor); the units.tsv row started at
// 0x1422b0060 and missed the first 60 functions. The class is declared in src/ms2/placeholder/gfxmanager.h; GFxClipboard
// (placeholder/gfxclipboard.h; OnTextStore is in ?\gfxvideo.cpp) has its vftable and inline ContainsRichText here. The COMDAT tail (0x1422b2800-) is Scaleform's loader-state glue
// (Ptr<>, the inline Loader setters / getters, the inline State ctors), NiPointer<>, TFunctor<> and CRBMap<>.
#define GFX_USE_VIDEO_WIN32               // sfvideo.h (GFxVideo)
#include "ms2/placeholder/ms2stdafx.h"
#pragma float_control(precise, on)
// The exe calls strcmp (SFstrcmp, pinned below) and wcslen (FUN_1422af5f0) out of line; /Oi would expand them inline.
#pragma function(strcmp)
#pragma function(wcslen)

#include <afx.h>
#include <atlcoll.h>

#include "GFx/GFx_FontProviderWin32.h"
#include "GFx/GFx_ImageResource.h"
#include "GFx/GFx_PlayerImpl.h"
#include "GFx/GFx_TextField.h"
#include "GFx/GFx_AS3Support.h"
#include "GFx/XML/XML_Support.h"
#include "XML/XML_Expat.h"
#include "Render/ImageFiles/JPEG_ImageFile.h"
#include "Render/ImageFiles/PNG_ImageFile.h"
#include "Render/ImageFiles/TGA_ImageFile.h"
#include "Render/ImageFiles/DDS_ImageFile.h"

#include "ms2/placeholder/gfxmanager.h"
#include "ms2/placeholder/gfxmovie.h"
#include "ms2/placeholder/gfxrenderer2d.h"
#include "ms2/placeholder/asdisplayobject.h"
#include "ms2/placeholder/asmoviecliploader.h"
#include "ms2/placeholder/gfxclipboard.h"
#include "ms2/placeholder/gfxfileopener.h"
#include "ms2/placeholder/gfximemanagerwin32.h"
#include "ms2/placeholder/asmousecursor.h"
#include "ms2/placeholder/ms2ptr_impl.h"
#include "ms2/placeholder/gfxvideo.h"
#include "ms2/gfxui/gfxsoundfmod.h"
#include "ms2/gfxui/gfxrendersinglethread.h"
#include "ms2/gfxui/nigfxlocalizemanager.h"
#include "ms2/gfxui/notifyhandler.h"
#include "ms2/gfxui/gfxmoviemain.h"
#include "ms2/gfxui/gfxmovietooltip.h"
#include "ms2/gfxui/gfxmoviemousecursor.h"
#include "ms2/gfxui/gfxmovieheadupdisplay.h"
#include "ms2/gfxui/gfxmoviepostdisplay.h"
#include "ms2/commonfiles/logstring.h"

#include "hook/ms2hook.h"

using Scaleform::File;
using Scaleform::Ptr;
using Scaleform::String;
using Scaleform::UPInt;
namespace Render = Scaleform::Render;
namespace Sound = Scaleform::Sound;
using namespace Scaleform::GFx;

// The GFx UI render helpers (inline COMDATs of ?\asmousecursor.cpp; ms2/placeholder/gfxrenderhelpers.h, which this unit
// cannot include: it declares the singleton getter with a stand-in class).
Unk_GFxUIHal* FUN_1422cf060();                                      // the UI renderer's HAL
void* FUN_1422cf0f0();                                              // the UI render context (the texture manager)
int FUN_1422cf120();                                                // 1 while the device is lost or screen capture is blocked
CString FUN_140651350();                                            // the locale code (localepath.cpp)
int FUN_1406516a0();                                                // the service type (3: no window activation)
// The log call of a DWORD argument (an FMT_VARIADIC wrapper over CLogString::FUN_1406530d0; optimizer.cpp's name).
template <class T> void Unk_OptLog(CLogString* log, int level, int category, const wchar_t* format, const T& first);

// GFxMovie as FUN_1422ae7d0 sees it: slot 10 takes the HAL and the Renderer2D by value (gfxmovie.h types both parameters
// with the Ptr<Unk_GFxHandleObj> stand-in; the copies made here are this obj's Ptr<HAL> / Ptr<Renderer2D> COMDATs).
class Unk_GmMovie
{
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7();
    virtual void vfunc_8(); virtual void vfunc_9();
    virtual void vfunc_10(Ptr<Unk_GFxUIHal> spHAL, Ptr<Unk_GFxUIRenderer2D> spRenderer2D);
};

// @0x1422acf10
GFxManager::GFxManager()
    : m_lock(0), m_spVideo(0), m_spRenderer(0), m_mapMovies(10), m_loader(1), m_spNotifyContext(0), m_spLocalize(0), m_spSound(0), m_bArchive(1),
      m_strIme("./Data/Resource/GFxAssets/Ime.swf"), m_strFontConfig("./Data/Resource/GFxAssets/fontconfig.txt"), m_strMain("./Data/Resource/GFxAssets/Main.swf"),
      m_strTooltip("./Data/Resource/GFxAssets/CommonTooltip.swf"), m_strBackground("./Data/Resource/GFxAssets/Background.swf"), m_strMouseCursor("./Data/Resource/GFxAssets/CommonMouseCursor.swf"),
      m_strHeadUpDisplay("./Data/Resource/GFxAssets/CommonHeadUpDisplay.swf"), m_strPostDisplay("./Data/Resource/GFxAssets/CommonPostDisplay.swf"), m_strDamageText("./Data/Resource/GFxAssets/CommonDamageText.swf"), m_pfnLog(0), m_pfn110(0), m_bPause(0), m_pfnFormat(0), m_pfnCommon(0), m_180(1), m_184(0), m_lockFiles(0), m_mapFiles(10), m_strComposition(L"")
{
    for (unsigned i = 0; i < 7; i++) {
        m_anStageWidth[i] = 0;
        m_anStageHeight[i] = 0;
    }
    m_1e8 = false;
}

// @0x1422ad3a0
GFxManager::~GFxManager()
{
    m_spVideo = 0;
    m_spRenderer = 0;
    m_spLocalize = 0;
    m_spNotifyContext = 0;
    m_spSound = 0;
}

// @0x1422ad620
int GFxManager::FUN_1422ad620(HWND hWnd, NiRenderer* pRenderer)
{
    if (!m_mapMovies.IsEmpty())
        return 0;
    m_hWnd = hWnd;
    if (!FUN_1422b1030())
        return 0;
    if (!FUN_1422b1750(pRenderer))
        return 0;
    GFxImageLoader* pImageLoader = new GFxImageLoader((Render::TextureManager*)FUN_1422cf0f0());
    pImageLoader->FUN_1422b7890(m_fnImage);
    {
        Ptr<GFxImageLoader> spImageLoader = *pImageLoader;
        m_loader.SetImageCreator(spImageLoader);
    }
    if (!FUN_1422b1620(m_strFontConfig, FUN_140651350()))
        return 0;
    if (!InitIME(hWnd))
        return 0;
    if (!FUN_1422b0f70(hWnd))
        return 0;
    if (!FUN_1422b19d0(hWnd, m_strMain))
        return 0;
    if (!FUN_1422b1bb0(hWnd, m_strTooltip))
        return 0;
    if (!FUN_1422b1d70(hWnd, m_strMouseCursor))
        return 0;
    if (!FUN_1422b1f30(hWnd, m_strHeadUpDisplay))
        return 0;
    if (!FUN_1422b20f0(hWnd, m_strPostDisplay))
        return 0;
    if (!m_fnIme.IsNull() && !m_fnIme(hWnd))
        return 0;
    if (!FUN_1422b22b0())
        return 0;
    m_spNotifyContext = EE_NEW Unk_NotifyContext();
    if (FUN_1406516a0() != 3) {
        ShowWindow(hWnd, SW_SHOW);
        SetForegroundWindow(hWnd);
        SetFocus(hWnd);
    }
    return 1;
}
MS2_REPLACE_METHOD(0x1422AD620, GFxManager, FUN_1422ad620, 1361, 0xD8A71BE4);

// @0x1422adb80
int GFxManager::FUN_1422adb80(unsigned int uiWidth, unsigned int uiHeight)
{
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie) {
            FUN_1422b0790(spMovie->FUN_1422be400());
            spMovie->vfunc_7(uiWidth, uiHeight);
        }
    }
    m_lock.Unlock();
    return 1;
}
MS2_REPLACE_METHOD(0x1422ADB80, GFxManager, FUN_1422adb80, 266, 0x70530FCA);

// @0x1422adc90
int GFxManager::FUN_1422adc90(GFxMovie* pMovie)
{
    if (pMovie == NULL)
        return 0;
    if (m_strBackground.IsEmpty())
        return 0;
    int bLoaded = 0;
    m_lock.DoLock();
    if (pMovie->vfunc_6(&m_loader, m_strBackground, 1)) {
        m_mapMovies.SetAt(4, pMovie);
        bLoaded = 1;
    }
    m_lock.Unlock();
    return bLoaded;
}
MS2_REPLACE_METHOD(0x1422ADC90, GFxManager, FUN_1422adc90, 278, 0xD3DC89F2);

// @0x1422addb0
int GFxManager::FUN_1422addb0()
{
    int bRemoved = 0;
    m_lock.DoLock();
    bRemoved = m_mapMovies.RemoveKey(4);
    m_lock.Unlock();
    return bRemoved;
}
MS2_REPLACE_METHOD(0x1422ADDB0, GFxManager, FUN_1422addb0, 89, 0xE09FE517);

// @0x1422ade10
int GFxManager::FUN_1422ade10(GFxMovie* pMovie)
{
    if (pMovie == NULL)
        return 0;
    if (m_strDamageText.IsEmpty())
        return 0;
    int bLoaded = 0;
    m_lock.DoLock();
    if (pMovie->vfunc_6(&m_loader, m_strDamageText, 1)) {
        m_mapMovies.SetAt(1, pMovie);
        bLoaded = 1;
    }
    m_lock.Unlock();
    return bLoaded;
}
MS2_REPLACE_METHOD(0x1422ADE10, GFxManager, FUN_1422ade10, 278, 0x87838C21);

// @0x1422adf30
int GFxManager::FUN_1422adf30()
{
    int bRemoved = 0;
    m_lock.DoLock();
    bRemoved = m_mapMovies.RemoveKey(1);
    m_lock.Unlock();
    return bRemoved;
}
MS2_REPLACE_METHOD(0x1422ADF30, GFxManager, FUN_1422adf30, 89, 0xC7B94EDD);

// @0x1422adf90
void GFxManager::Render()
{
    if (!m_spRenderer)
        return;
    if (m_mapMovies.IsEmpty())
        return;
    if (FUN_1422cf120()) {
        if (CLogString::GetInstance()) {
            DWORD dwTick = GetTickCount();
            Unk_OptLog(CLogString::GetInstance(), 0xc, 0x1a, L"GFxManager::Render D3DERR_DEVICELOST[{0}]", dwTick);
        }
        return;
    }
    if (m_spRenderer->vfunc_4()) {
        m_lock.DoLock();
        for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
            NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
            if (spMovie)
                m_spRenderer->vfunc_6(spMovie);
        }
        m_lock.Unlock();
        m_spRenderer->vfunc_5();
    }
}
MS2_REPLACE_METHOD(0x1422ADF90, GFxManager, Render, 488, 0xB6C46403);

// @0x1422ae180
void GFxManager::FUN_1422ae180()
{
    if (!m_spRenderer)
        return;
    if (m_mapMovies.IsEmpty())
        return;
    if (m_spNotifyContext) {
        m_spNotifyContext->FUN_1422c90d0();
    }
    if (m_spRenderer->vfunc_7()) {
        m_lock.DoLock();
        for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
            NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
            if (spMovie)
                m_spRenderer->vfunc_9(spMovie);
        }
        m_lock.Unlock();
    }
    m_spRenderer->vfunc_8();
    if (FUN_1422cf120() || m_180 == 0)
        FUN_1422ae7d0();
}
MS2_REPLACE_METHOD(0x1422AE180, GFxManager, FUN_1422ae180, 464, 0x8BD89BA6);

// @0x1422ae360
void GFxManager::FUN_1422ae360()
{
    Ptr<TaskManager> spTaskManager = m_loader.GetTaskManager();
    if (spTaskManager)
        spTaskManager->RequestShutdown();
    if (m_spNotifyContext)
        m_spNotifyContext->FUN_1422c8de0();
    if (m_spVideo)
        m_spVideo->FUN_1422ec670();
    m_lockFiles.DoLock();
    m_mapFiles.RemoveAll();
    m_lockFiles.Unlock();
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie)
            spMovie->vfunc_11();
    }
    m_lock.Unlock();
    if (m_spRenderer)
        m_spRenderer->vfunc_10();
    m_mapMovies.RemoveAll();
    m_spSound = 0;
}
MS2_REPLACE_METHOD(0x1422AE360, GFxManager, FUN_1422ae360, 539, 0x4D71D83A);

// @0x1422ae590
void GFxManager::FUN_1422ae590()
{
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie)
            spMovie->vfunc_12();
    }
    m_lock.Unlock();
    m_spRenderer->vfunc_11();
}
MS2_REPLACE_METHOD(0x1422AE590, GFxManager, FUN_1422ae590, 244, 0xE8E71C44);

// @0x1422ae690
bool GFxManager::FUN_1422ae690()
{
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie) {
            if (!spMovie->vfunc_13()) {
                m_lock.Unlock();
                throw 0xd;
            }
        }
    }
    m_lock.Unlock();
    return m_spRenderer->vfunc_12();
}
MS2_REPLACE_METHOD(0x1422AE690, GFxManager, FUN_1422ae690, 299, 0xB04A0ECF);

// @0x1422ae7d0
void GFxManager::FUN_1422ae7d0()
{
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie)
            ((Unk_GmMovie*)spMovie.operator->())->vfunc_10(FUN_1422cf060(), FUN_1422b02b0());
    }
    m_lock.Unlock();
}
MS2_REPLACE_METHOD(0x1422AE7D0, GFxManager, FUN_1422ae7d0, 328, 0x4E529509);

// @0x1422ae920
void GFxManager::FUN_1422ae920(int n)
{
    m_184 = n;
}
MS2_REPLACE_METHOD(0x1422AE920, GFxManager, FUN_1422ae920, 25, 0x81579D9A);

// @0x1422ae940
int GFxManager::FUN_1422ae940()
{
    return m_184;
}
MS2_REPLACE_METHOD(0x1422AE940, GFxManager, FUN_1422ae940, 17, 0x76C8FA56);

// @0x1422ae960
void GFxManager::FUN_1422ae960(int bVisible)
{
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie) {
            MS2Ptr<ASMovieClipLoader> spLoader = spMovie->FUN_1422be4c0();
            if (spLoader.get())
                spLoader->Invoke("setVisible", bVisible);
        }
    }
    m_lock.Unlock();
}
MS2_REPLACE_METHOD(0x1422AE960, GFxManager, FUN_1422ae960, 299, 0x3409EB9B);

// @0x1422aeaa0
void GFxManager::FUN_1422aeaa0(int nStep)
{
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie) {
            MS2Ptr<ASMovieClipLoader> spLoader = spMovie->FUN_1422be4c0();
            if (spLoader.get())
                spLoader->Invoke("setVisibleStep", nStep);
        }
    }
    m_lock.Unlock();
}
MS2_REPLACE_METHOD(0x1422AEAA0, GFxManager, FUN_1422aeaa0, 299, 0xA5A37CFA);

// @0x1422aebe0
void GFxManager::FUN_1422aebe0(int nLayer, bool bVisible)
{
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie) {
            MS2Ptr<ASMovieClipLoader> spLoader = spMovie->FUN_1422be4c0();
            if (spLoader.get())
                spLoader->FUN_140ed0fd0("setVisibleLayer", nLayer, bVisible);
        }
    }
    m_lock.Unlock();
}
MS2_REPLACE_METHOD(0x1422AEBE0, GFxManager, FUN_1422aebe0, 322, 0xE403907D);

// @0x1422aed30
void GFxManager::FUN_1422aed30(bool b)
{
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie == NULL)
            continue;
        spMovie->vfunc_5(b);
    }
    m_lock.Unlock();
}
MS2_REPLACE_METHOD(0x1422AED30, GFxManager, FUN_1422aed30, 234, 0x5F12DF8C);

// @0x1422aee20
void GFxManager::FUN_1422aee20(void (*pfn)(const Scaleform::GFx::FunctionHandler::Params&))
{
    m_pfnFormat = pfn;
}
MS2_REPLACE_METHOD(0x1422AEE20, GFxManager, FUN_1422aee20, 28, 0xC6E7BB96);

// @0x1422aee50
void GFxManager::FUN_1422aee50(TFunctor<bool, ParamList<HWND, EmptyParam> > fn)
{
    m_fnIme = fn;
}
MS2_REPLACE_METHOD(0x1422AEE50, GFxManager, FUN_1422aee50, 63, 0x02617102);

// @0x1422aeea0
void GFxManager::FUN_1422aeea0(void (*pfn)(AScript& kCommon, int nMovieId))
{
    m_pfnCommon = pfn;
}
MS2_REPLACE_METHOD(0x1422AEEA0, GFxManager, FUN_1422aeea0, 28, 0x315C37C6);

// @0x1422aeed0
int GFxManager::FUN_1422aeed0(int n)
{
    GFxMovie* pMovie = FUN_1422b01a0(n);
    if (pMovie)
        return pMovie->FUN_1422be360();
    return 0;
}
MS2_REPLACE_METHOD(0x1422AEED0, GFxManager, FUN_1422aeed0, 59, 0x1598FCD0);

// @0x1422aef20
void GFxManager::FUN_1422aef20(int nMovieId, int n)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie)
        pMovie->FUN_1422be380(n);
}
MS2_REPLACE_METHOD(0x1422AEF20, GFxManager, FUN_1422aef20, 64, 0x6FB42BE8);

// @0x1422aef70
int GFxManager::IsPause()
{
    return m_bPause;
}
MS2_REPLACE_METHOD(0x1422AEF70, GFxManager, IsPause, 17, 0xCF7F4092);

// @0x1422aef90
void GFxManager::FUN_1422aef90(int bPause)
{
    if (m_bPause == bPause)
        return;
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie)
            spMovie->FUN_1422be080(bPause);
    }
    m_lock.Unlock();
    m_bPause = bPause;
}
MS2_REPLACE_METHOD(0x1422AEF90, GFxManager, FUN_1422aef90, 238, 0x71BE0341);

// @0x1422af090
int GFxManager::IsArchive()
{
    return m_bArchive;
}
MS2_REPLACE_METHOD(0x1422AF090, GFxManager, IsArchive, 17, 0x1F8D7963);

// @0x1422af0b0
void GFxManager::FUN_1422af0b0(int bArchive, int bRelease)
{
    m_bArchive = bArchive;
    if (m_bArchive) {
        m_strFontConfig = "./Data/Resource/gfx/fontconfig.txt";
        if (bRelease == 0) {
            m_strIme = "./Data/Resource/gfxDebug/Ime.gfx";
            m_strMain = "./Data/Resource/gfxDebug/Main.gfx";
            m_strTooltip = "./Data/Resource/gfxDebug/CommonTooltip.gfx";
            m_strBackground = "./Data/Resource/gfxDebug/Background.gfx";
            m_strMouseCursor = "./Data/Resource/gfxDebug/CommonMouseCursor.gfx";
            m_strHeadUpDisplay = "./Data/Resource/gfxDebug/CommonHeadUpDisplay.gfx";
            m_strPostDisplay = "./Data/Resource/gfxDebug/CommonPostDisplay.gfx";
            m_strDamageText = "./Data/Resource/gfxDebug/CommonDamageText.gfx";
        } else {
            m_strIme = "./Data/Resource/gfx/Ime.gfx";
            m_strMain = "./Data/Resource/gfx/Main.gfx";
            m_strTooltip = "./Data/Resource/gfx/CommonTooltip.gfx";
            m_strBackground = "./Data/Resource/gfx/Background.gfx";
            m_strMouseCursor = "./Data/Resource/gfx/CommonMouseCursor.gfx";
            m_strHeadUpDisplay = "./Data/Resource/gfx/CommonHeadUpDisplay.gfx";
            m_strPostDisplay = "./Data/Resource/gfx/CommonPostDisplay.gfx";
            m_strDamageText = "./Data/Resource/gfx/CommonDamageText.gfx";
        }
    }
}
MS2_REPLACE_METHOD(0x1422AF0B0, GFxManager, FUN_1422af0b0, 531, 0x720498EE);

// @0x1422af2d0
int GFxManager::FUN_1422af2d0(int nMovieId)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie == NULL)
        return 0;
    Movie* pGFxMovie = pMovie->FUN_1422bd0f0();
    if (pGFxMovie == NULL)
        return 0;
    IMEManagerBase* pIME = pGFxMovie->GetIMEManager();
    if (pIME)
        return pIME->IsTextFieldFocused();
    return 0;
}
MS2_REPLACE_METHOD(0x1422AF2D0, GFxManager, FUN_1422af2d0, 172, 0x46C36A07);

// @0x1422af390
int GFxManager::FUN_1422af390(int nMovieId)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie == NULL)
        return 0;
    Movie* pGFxMovie = pMovie->FUN_1422bd0f0();
    if (pGFxMovie == NULL)
        return 0;
    IMEManagerBase* pIME = pGFxMovie->GetIMEManager();
    if (pIME) {
        Ptr<InteractiveObject> spFocused = static_cast<MovieImpl*>(pGFxMovie)->GetFocusedCharacter(0);
        if (spFocused && spFocused->GetType() == CharacterDef::TextField) {
            Ptr<TextField> spText = static_cast<TextField*>(spFocused.GetPtr());
            if (spText && spText->HasMaxLength()) {
                if (spText->GetTextLength() == spText->GetMaxLength())
                    return 1;
            }
        }
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422AF390, GFxManager, FUN_1422af390, 478, 0x0D52860D);

// @0x1422af580
int GFxManager::FUN_1422af580(int nMovieId)
{
    if (m_hWnd == NULL)
        return 0;
    return GetFocus() == m_hWnd && FUN_1422af2d0(nMovieId);
}
MS2_REPLACE_METHOD(0x1422AF580, GFxManager, FUN_1422af580, 97, 0xF47CE5A7);

// MS2-FUNCTIONAL: the exe calls wcslen through the CRT import table; here it is a direct call (one instruction)
// @0x1422af5f0
CStringW GFxManager::FUN_1422af5f0(int nMovieId)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie == NULL)
        return CStringW((const wchar_t*)NULL);
    Movie* pGFxMovie = pMovie->FUN_1422bd0f0();
    if (pGFxMovie == NULL)
        return CStringW((const wchar_t*)NULL);
    IMEManagerBase* pIME = pGFxMovie->GetIMEManager();
    if (pIME && pIME->IsTextFieldFocused()) {
        const wchar_t* szComposition = pIME->GetCompositionString();
        if (szComposition && wcslen(szComposition) > 0) {
            CStringW strComposition(szComposition);
            return strComposition;
        }
    }
    return CStringW((const wchar_t*)NULL);
}

// @0x1422af7a0
int GFxManager::FUN_1422af7a0(int nMovieId)
{
    if (FUN_1422af960(nMovieId) != "Japanese")
        return 0;
    CStringW strComposition = FUN_1422af5f0(nMovieId);
    if (m_strComposition != strComposition) {
        m_strComposition = strComposition;
        return 1;
    } else {
        return 0;
    }
}
MS2_REPLACE_METHOD(0x1422AF7A0, GFxManager, FUN_1422af7a0, 227, 0x14288614);

// @0x1422af8a0
unsigned GFxManager::FUN_1422af8a0(int nMovieId)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie == NULL)
        return 0x1000000;
    Movie* pGFxMovie = pMovie->FUN_1422bd0f0();
    if (pGFxMovie == NULL)
        return 0x1000000;
    IMEManagerBase* pIME = pGFxMovie->GetIMEManager();
    if (pIME)
        return static_cast<IME::GFxIMEManagerWin32*>(pIME)->m_dwConversionMode;
    return 0x1000000;
}
MS2_REPLACE_METHOD(0x1422AF8A0, GFxManager, FUN_1422af8a0, 179, 0xE8E05E25);

// @0x1422af960
CString GFxManager::FUN_1422af960(int nMovieId)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie == NULL)
        return CString("UNKNOWN");
    Movie* pGFxMovie = pMovie->FUN_1422bd0f0();
    if (pGFxMovie == NULL)
        return CString("UNKNOWN");
    IMEManagerBase* pIME = pGFxMovie->GetIMEManager();
    if (pIME)
        return CString(pIME->GetInputLanguage().ToCStr());
    return CString("UNKNOWN");
}
MS2_REPLACE_METHOD(0x1422AF960, GFxManager, FUN_1422af960, 397, 0x04ED31FF);

// @0x1422afb00
void GFxManager::FUN_1422afb00()
{
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie) {
            MS2Ptr<ASMovieClipLoader> spLoader = spMovie->FUN_1422be4c0();
            if (spLoader.get())
                spLoader->FUN_1422d0230();
        }
    }
    m_lock.Unlock();
}
MS2_REPLACE_METHOD(0x1422AFB00, GFxManager, FUN_1422afb00, 250, 0x7B7E80C6);

// @0x1422afc00
void GFxManager::FUN_1422afc00()
{
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie)
            spMovie->FUN_1422bd0f0()->ForceCollectGarbage();
    }
    m_lock.Unlock();
}
MS2_REPLACE_METHOD(0x1422AFC00, GFxManager, FUN_1422afc00, 220, 0xC6845CE6);

// @0x1422afcf0
Ni2DBuffer* GFxManager::FUN_1422afcf0()
{
    if (m_spRenderer)
        return m_spRenderer->vfunc_14();
    return NULL;
}
MS2_REPLACE_METHOD(0x1422AFCF0, GFxManager, FUN_1422afcf0, 78, 0x700458B7);

// @0x1422afd50
void GFxManager::FUN_1422afd50(bool bMute)
{
    if (m_spSound == NULL)
        return;
    Sound::SoundRenderer* pRenderer = m_spSound->GetSoundRenderer();
    if (pRenderer)
        pRenderer->Mute(bMute);
}
MS2_REPLACE_METHOD(0x1422AFD50, GFxManager, FUN_1422afd50, 109, 0x0A2838B9);

// @0x1422afdd0
void GFxManager::FUN_1422afdd0(float fVolume)
{
    if (m_spSound == NULL)
        return;
    Sound::SoundRenderer* pRenderer = m_spSound->GetSoundRenderer();
    if (pRenderer)
        pRenderer->SetMasterVolume(fVolume);
}
MS2_REPLACE_METHOD(0x1422AFDD0, GFxManager, FUN_1422afdd0, 112, 0x3A9FCC25);

// @0x1422afe50
void GFxManager::FUN_1422afe50()
{
    m_spSound = 0;
    FUN_1422b22b0();
}
MS2_REPLACE_METHOD(0x1422AFE50, GFxManager, FUN_1422afe50, 45, 0x30345DFC);

// @0x1422afe90
void GFxManager::FUN_1422afe90()
{
    m_spSound = 0;
}
MS2_REPLACE_METHOD(0x1422AFE90, GFxManager, FUN_1422afe90, 35, 0x0DFA95BF);

// @0x1422afec0
float GFxManager::FUN_1422afec0(int nMovieId)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie)
        return pMovie->FUN_1422bde30();
    return 1.0f;
}
MS2_REPLACE_METHOD(0x1422AFEC0, GFxManager, FUN_1422afec0, 65, 0x9A208CCE);

// @0x1422aff10
int GFxManager::FUN_1422aff10(float fScale)
{
    int bChanged = 0;
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie) {
            FUN_1422b0790(spMovie->FUN_1422be400());
            if (spMovie == FUN_1422b01a0(4))
                continue;
            if (spMovie->FUN_1422bde80(fScale))
                bChanged = 1;
        }
    }
    m_lock.Unlock();
    return bChanged;
}
MS2_REPLACE_METHOD(0x1422AFF10, GFxManager, FUN_1422aff10, 315, 0x2A3E71D8);

// @0x1422b0060
void GFxManager::FUN_1422b0060(float fScale)
{
    float fCurScale = FUN_1422afec0(2);
    if (fCurScale == fScale)
        return;
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetHeadPosition(); pos != NULL; m_mapMovies.GetNext(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie) {
            if (spMovie == FUN_1422b01a0(4))
                continue;
            spMovie->FUN_1422bde50(fScale);
        }
    }
    m_lock.Unlock();
}
MS2_REPLACE_METHOD(0x1422B0060, GFxManager, FUN_1422b0060, 303, 0x364D4078);

// @0x1422b01a0
GFxMovie* GFxManager::FUN_1422b01a0(int nMovieId)
{
    m_lock.DoLock();
    NiPointer<GFxMovie> spMovie = 0;
    m_mapMovies.Lookup(nMovieId, spMovie);
    m_lock.Unlock();
    return spMovie;
}
MS2_REPLACE_METHOD(0x1422B01A0, GFxManager, FUN_1422b01a0, 130, 0x37892ECF);

// @0x1422b0230
GFxVideo* GFxManager::GetVideo()
{
    return m_spVideo;
}
MS2_REPLACE_METHOD(0x1422B0230, GFxManager, GetVideo, 31, 0x26D40716);

// @0x1422b0260
Unk_NotifyContext* GFxManager::GetNotifyContext()
{
    return m_spNotifyContext;
}
MS2_REPLACE_METHOD(0x1422B0260, GFxManager, GetNotifyContext, 33, 0xDC21CB16);

// @0x1422b0290
Scaleform::GFx::Loader* GFxManager::FUN_1422b0290()
{
    return &m_loader;
}
MS2_REPLACE_METHOD(0x1422B0290, GFxManager, FUN_1422b0290, 15, 0x680A76B1);

// @0x1422b02b0
Unk_GFxUIRenderer2D* GFxManager::FUN_1422b02b0()
{
    return m_spRenderer->vfunc_2();
}
MS2_REPLACE_METHOD(0x1422B02B0, GFxManager, FUN_1422b02b0, 52, 0x33FC1C90);

// @0x1422b02f0
MS2Ptr<ASStage> GFxManager::FUN_1422b02f0(int nMovieId)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie)
        return pMovie->FUN_1422be420();
    return MS2Ptr<ASStage>(0);
}
MS2_REPLACE_METHOD(0x1422B02F0, GFxManager, FUN_1422b02f0, 120, 0xC165C1AF);

// @0x1422b0370
MS2Ptr<ASMouseCursor> GFxManager::FUN_1422b0370(int nMovieId)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie)
        return pMovie->FUN_1422be470();
    return MS2Ptr<ASMouseCursor>(0);
}
MS2_REPLACE_METHOD(0x1422B0370, GFxManager, FUN_1422b0370, 120, 0x060B6814);

// @0x1422b03f0
MS2Ptr<ASMovieClipLoader> GFxManager::FUN_1422b03f0(int nGroup)
{
    GFxMovie* pMovie = FUN_1422b01a0(nGroup);
    if (pMovie)
        return pMovie->FUN_1422be4c0();
    return MS2Ptr<ASMovieClipLoader>(0);
}
MS2_REPLACE_METHOD(0x1422B03F0, GFxManager, FUN_1422b03f0, 120, 0xB0009EE3);

// @0x1422b0470
void GFxManager::FUN_1422b0470(int nMovieId, int* pnWidth, int* pnHeight)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie)
        pMovie->FUN_1422be010(pnWidth, pnHeight);
}
MS2_REPLACE_METHOD(0x1422B0470, GFxManager, FUN_1422b0470, 75, 0xE4E2E420);

// @0x1422b04d0
int GFxManager::FUN_1422b04d0(int nMovieId)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie)
        return pMovie->FUN_1422bdf70();
    return 0;
}
MS2_REPLACE_METHOD(0x1422B04D0, GFxManager, FUN_1422b04d0, 59, 0x45DD588E);

// @0x1422b0520
int GFxManager::FUN_1422b0520(int nMovieId)
{
    GFxMovie* pMovie = FUN_1422b01a0(nMovieId);
    if (pMovie)
        return pMovie->FUN_1422bdfc0();
    return 0;
}
MS2_REPLACE_METHOD(0x1422B0520, GFxManager, FUN_1422b0520, 59, 0x01BCC59E);

// @0x1422b0570
CStringW GFxManager::FUN_1422b0570(const CString& strKey)
{
    if (m_spLocalize)
        return m_spLocalize->FUN_1422eb860(strKey);
    return CStringW(L"");
}
MS2_REPLACE_METHOD(0x1422B0570, GFxManager, FUN_1422b0570, 145, 0x1114C221);

// @0x1422b0610
int GFxManager::FUN_1422b0610(const CString& strSound, const CString& strArg)
{
    if (!m_fnSound.IsNull())
        return m_fnSound(strSound, strArg) != 0;
    return 0;
}
MS2_REPLACE_METHOD(0x1422B0610, GFxManager, FUN_1422b0610, 109, 0x1019048F);

// @0x1422b0690
void GFxManager::FUN_1422b0690(TFunctor<unsigned int, ParamList<const CString&, ParamList<const CString&, EmptyParam> > > fn)
{
    m_fnSound = fn;
}
MS2_REPLACE_METHOD(0x1422B0690, GFxManager, FUN_1422b0690, 63, 0x7B4314CC);

// MS2-FUNCTIONAL: the exe also stores the stage pointer to an unread stack slot before the MS2Ptr temporary dies
// @0x1422b06e0
void GFxManager::FUN_1422b06e0(int nMovieId, int* pnWidth, int* pnHeight)
{
    ASStage* pStage = FUN_1422b02f0(nMovieId).get();
    if (pStage) {
        *pnWidth = pStage->FUN_1422cfec0();
        *pnHeight = pStage->FUN_1422cff20();
    }
}
MS2_REPLACE_METHOD(0x1422B06E0, GFxManager, FUN_1422b06e0, 155, 0xEE517CC4);

// MS2-FUNCTIONAL: the exe also stores the stage pointer to an unread stack slot before the MS2Ptr temporary dies
// @0x1422b0790
void GFxManager::FUN_1422b0790(int nMovieId)
{
    ASStage* pStage = FUN_1422b02f0(nMovieId).get();
    if (pStage) {
        m_anStageWidth[nMovieId] = pStage->FUN_1422cfec0();
        m_anStageHeight[nMovieId] = pStage->FUN_1422cff20();
    }
}
MS2_REPLACE_METHOD(0x1422B0790, GFxManager, FUN_1422b0790, 159, 0x5A189BEC);

// @0x1422b0840
void GFxManager::FUN_1422b0840(int nMovieId, int* pnWidth, int* pnHeight)
{
    *pnWidth = m_anStageWidth[nMovieId];
    *pnHeight = m_anStageHeight[nMovieId];
}
MS2_REPLACE_METHOD(0x1422B0840, GFxManager, FUN_1422b0840, 68, 0xEC177E14);

// @0x1422b08f0
void GFxManager::FUN_1422b08f0(const char* szFormat, ...)
{
    if (m_pfnLog) {
        CString strLine;
        va_list args;
        va_start(args, szFormat);
        strLine.FormatV(szFormat, args);
        va_end(args);
        m_pfnLog(strLine);
    }
}

// @0x1422b09a0
void GFxManager::FUN_1422b09a0()
{
    m_spLocalize->FUN_1422eb920();
}
MS2_REPLACE_METHOD(0x1422B09A0, GFxManager, FUN_1422b09a0, 41, 0xC0765804);

// @0x1422b09d0
int GFxManager::FUN_1422b09d0(CString a, CString b, int n)
{
    if (m_pfn110)
        return m_pfn110(a, b, n);
    return 0;
}
MS2_REPLACE_METHOD(0x1422B09D0, GFxManager, FUN_1422b09d0, 147, 0x54032B72);

// @0x1422b0a70
int GFxManager::FUN_1422b0a70(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    int bHandled = 0;
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetTailPosition(); pos != NULL; m_mapMovies.GetPrev(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie) {
            if (spMovie->vfunc_14(hWnd, uMsg, wParam, lParam)) {
                bHandled = 1;
                if (spMovie->FUN_1422be3a0(uMsg))
                    break;
            }
        }
    }
    m_lock.Unlock();
    return bHandled;
}
MS2_REPLACE_METHOD(0x1422B0A70, GFxManager, FUN_1422b0a70, 326, 0x07BA72B1);

// @0x1422b0bc0
int GFxManager::FUN_1422b0bc0(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    int bHandled = 0;
    m_lock.DoLock();
    for (POSITION pos = m_mapMovies.GetTailPosition(); pos != NULL; m_mapMovies.GetPrev(pos)) {
        NiPointer<GFxMovie> spMovie = m_mapMovies.GetValueAt(pos);
        if (spMovie) {
            if (spMovie->vfunc_15(hWnd, uMsg, wParam, lParam)) {
                bHandled = 1;
                if (spMovie->FUN_1422be3a0(uMsg))
                    break;
            }
        }
    }
    m_lock.Unlock();
    return bHandled;
}
MS2_REPLACE_METHOD(0x1422B0BC0, GFxManager, FUN_1422b0bc0, 326, 0x1C4C63E4);

// @0x1422b0d10
CString GFxManager::GetIme()
{
    return m_strIme;
}
MS2_REPLACE_METHOD(0x1422B0D10, GFxManager, GetIme, 68, 0x6EDCBFF9);

// @0x1422b0d60
Ptr<File> GFxManager::FUN_1422b0d60(String strPath)
{
    Ptr<File> spFile = 0;
    m_lockFiles.DoLock();
    m_mapFiles.Lookup(strPath, spFile);
    m_lockFiles.Unlock();
    return spFile;
}
MS2_REPLACE_METHOD(0x1422B0D60, GFxManager, FUN_1422b0d60, 173, 0x7F2D5DA5);

// @0x1422b0e20
void GFxManager::FUN_1422b0e20(String strPath, Ptr<File> spFile)
{
    m_lockFiles.DoLock();
    m_mapFiles.SetAt(strPath, spFile);
    m_lockFiles.Unlock();
}
MS2_REPLACE_METHOD(0x1422B0E20, GFxManager, FUN_1422b0e20, 122, 0xD95B8B01);

// @0x1422b0ea0
void GFxManager::FUN_1422b0ea0(const CStringW& strText)
{
    GFxMovieMain* pMain = dynamic_cast<GFxMovieMain*>(FUN_1422b01a0(2));
    if (pMain)
        pMain->FUN_1422d8fd0(strText);
}
MS2_REPLACE_METHOD(0x1422B0EA0, GFxManager, FUN_1422b0ea0, 94, 0xD81324AC);

// @0x1422b0f10
int GFxManager::FUN_1422b0f10()
{
    GFxMovieTooltip* pTooltip = dynamic_cast<GFxMovieTooltip*>(FUN_1422b01a0(5));
    if (pTooltip)
        return pTooltip->FUN_1422f1020();
    return 0;
}
MS2_REPLACE_METHOD(0x1422B0F10, GFxManager, FUN_1422b0f10, 88, 0x5348B6FA);

// @0x1422b0f70
int GFxManager::FUN_1422b0f70(HWND hWnd)
{
    m_spVideo = EE_NEW GFxVideo;
    return m_spVideo->FUN_1422ec460(hWnd, &m_loader);
}
MS2_REPLACE_METHOD(0x1422B0F70, GFxManager, FUN_1422b0f70, 182, 0x9A186732);

// @0x1422b1030
int GFxManager::FUN_1422b1030()
{
    Ptr<GFxFileOpener> spFileOpener = *new GFxFileOpener;
    m_loader.SetFileOpener(spFileOpener);
    if (0) {
        Ptr<ThreadedTaskManager> spTaskManager = *new ThreadedTaskManager(0x100000);
        m_loader.SetTaskManager(spTaskManager);
    }
    Ptr<ASSupport> spAS3Support = *new AS3Support;
    m_loader.SetAS3Support(spAS3Support);
    Ptr<Scaleform::GFx::ImageFileHandlerRegistry> spRegistry = *new Scaleform::GFx::ImageFileHandlerRegistry;
    spRegistry->AddHandler(&Render::JPEG::FileReader::Instance);
    spRegistry->AddHandler(&Render::PNG::FileReader::Instance);
    spRegistry->AddHandler(&Render::TGA::FileReader::Instance);
    spRegistry->AddHandler(&Render::DDS::FileReader::Instance);
    m_loader.SetImageFileHandlerRegistry(spRegistry);
    Ptr<GFxClipboard> spClipboard = *new GFxClipboard();
    m_loader.SetTextClipboard(spClipboard);
    Ptr<FontProviderWin32> spFontProvider = *new FontProviderWin32(GetDC(NULL));
    spFontProvider->SetHintingAllFonts(Font::DontHint, Font::DontHint, 24, 24);
    m_loader.SetFontProvider(spFontProvider);
    Ptr<ParseControl> spParseControl = *new ParseControl(0);
    m_loader.SetParseControl(spParseControl);
    Ptr<XML::Parser> spParser = *new XML::ParserExpat;
    Ptr<XML::SupportBase> spXMLSupport = *new XML::Support(spParser);
    m_loader.SetXMLSupport(spXMLSupport);
    return 1;
}
MS2_REPLACE_METHOD(0x1422B1030, GFxManager, FUN_1422b1030, 1500, 0x64A5C164);

// @0x1422b1620
int GFxManager::FUN_1422b1620(CString strFontConfig, const CString& strLocale)
{
    m_spLocalize = EE_NEW NiGFxLocalizeManager;
    if (m_spLocalize)
        m_spLocalize->FUN_1422eb570(&m_loader, strFontConfig, strLocale);
    return 1;
}
MS2_REPLACE_METHOD(0x1422B1620, GFxManager, FUN_1422b1620, 287, 0xBCEA5113);

// @0x1422b1750
int GFxManager::FUN_1422b1750(NiRenderer* pRenderer)
{
    if (pRenderer) {
        m_spRenderer = EE_NEW GFxRenderSingleThread(pRenderer);
        return m_spRenderer->vfunc_3();
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422B1750, GFxManager, FUN_1422b1750, 192, 0xAB26E2A9);

// @0x1422b1820
int GFxManager::InitIME(HWND hWnd)
{
    Ptr<IME::GFxIMEManagerWin32> spIME = *new IME::GFxIMEManagerWin32(hWnd);
    if (spIME) {
        FileOpener* pFileOpener = dynamic_cast<FileOpener*>(m_loader.GetFileOpener().GetPtr());
        spIME->Init(NULL, pFileOpener, "ime.xml", true);
        spIME->SetIMEMoviePath(m_strIme);
        m_loader.SetIMEManager(spIME);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422B1820, GFxManager, InitIME, 422, 0xF5C4BD6C);

// @0x1422b19d0
int GFxManager::FUN_1422b19d0(HWND hWnd, CString strPath)
{
    m_lock.DoLock();
    GFxMovieMain* pMovie = EE_NEW GFxMovieMain;
    if (pMovie) {
        if (pMovie->vfunc_6(&m_loader, strPath, 0x10091)) {
            m_mapMovies.SetAt(2, pMovie);
            pMovie->FUN_1422d8e80(hWnd);
            pMovie->FUN_1422be0e0(m_pfnFormat);
            pMovie->FUN_1422be280(m_pfnCommon);
            return 1;
        }
    }
    m_lock.Unlock();
    return 0;
}
MS2_REPLACE_METHOD(0x1422B19D0, GFxManager, FUN_1422b19d0, 460, 0x6ED56842);

// @0x1422b1bb0
int GFxManager::FUN_1422b1bb0(HWND hWnd, CString strPath)
{
    m_lock.DoLock();
    GFxMovieTooltip* pMovie = EE_NEW GFxMovieTooltip;
    if (pMovie) {
        if (pMovie->vfunc_6(&m_loader, strPath, 1)) {
            m_mapMovies.SetAt(5, pMovie);
            pMovie->FUN_1422be0e0(m_pfnFormat);
            pMovie->FUN_1422be280(m_pfnCommon);
            return 1;
        }
    }
    m_lock.Unlock();
    return 0;
}
MS2_REPLACE_METHOD(0x1422B1BB0, GFxManager, FUN_1422b1bb0, 442, 0x8521465B);

// @0x1422b1d70
int GFxManager::FUN_1422b1d70(HWND hWnd, CString strPath)
{
    m_lock.DoLock();
    GFxMovieMouseCursor* pMovie = EE_NEW GFxMovieMouseCursor;
    if (pMovie) {
        if (pMovie->vfunc_6(&m_loader, strPath, 1)) {
            m_mapMovies.SetAt(6, pMovie);
            pMovie->FUN_1422be0e0(m_pfnFormat);
            pMovie->FUN_1422be280(m_pfnCommon);
            return 1;
        }
    }
    m_lock.Unlock();
    return 0;
}
MS2_REPLACE_METHOD(0x1422B1D70, GFxManager, FUN_1422b1d70, 442, 0xB5818A9A);

// @0x1422b1f30
int GFxManager::FUN_1422b1f30(HWND hWnd, CString strPath)
{
    m_lock.DoLock();
    GFxMovieHeadUpDisplay* pMovie = EE_NEW GFxMovieHeadUpDisplay;
    if (pMovie) {
        if (pMovie->vfunc_6(&m_loader, strPath, 1)) {
            m_mapMovies.SetAt(0, pMovie);
            pMovie->FUN_1422be0e0(m_pfnFormat);
            pMovie->FUN_1422be280(m_pfnCommon);
            return 1;
        }
    }
    m_lock.Unlock();
    return 0;
}
MS2_REPLACE_METHOD(0x1422B1F30, GFxManager, FUN_1422b1f30, 439, 0x622F11E6);

// @0x1422b20f0
int GFxManager::FUN_1422b20f0(HWND hWnd, CString strPath)
{
    m_lock.DoLock();
    GFxMoviePostDisplay* pMovie = EE_NEW GFxMoviePostDisplay;
    if (pMovie) {
        if (pMovie->vfunc_6(&m_loader, strPath, 1)) {
            m_mapMovies.SetAt(3, pMovie);
            pMovie->FUN_1422be0e0(m_pfnFormat);
            pMovie->FUN_1422be280(m_pfnCommon);
            return 1;
        }
    }
    m_lock.Unlock();
    return 0;
}
MS2_REPLACE_METHOD(0x1422B20F0, GFxManager, FUN_1422b20f0, 442, 0xC65B46FA);

// @0x1422b22b0
int GFxManager::FUN_1422b22b0()
{
    if (m_spSound)
        return 0;
    m_spSound = EE_NEW GFxSoundFMOD;
    if (m_spSound == NULL)
        return 0;
    if (!m_spSound->Initialize()) {
        m_spSound = 0;
        return 1;
    }
    float fVolume = 1.0f;
    bool bMute = false;
    Sound::SoundRenderer* pRenderer = m_spSound->GetSoundRenderer();
    if (pRenderer) {
        Ptr<Audio> spAudio = *new Audio(pRenderer, 0.1f, 15, AudioBase::AudioMaster);
        m_loader.SetAudio(spAudio);
        pRenderer->SetMasterVolume(fVolume);
        pRenderer->Mute(bMute);
        return 1;
    }
    return 0;
}
MS2_REPLACE_METHOD(0x1422B22B0, GFxManager, FUN_1422b22b0, 564, 0x4175898C);

// @0x1422b24f0
void GFxManager::FUN_1422b24f0()
{
    if (IsArchive() == 0) {
        m_lock.DoLock();
        m_mapMovies.RemoveKey(2);
        m_mapMovies.RemoveKey(5);
        m_mapMovies.RemoveKey(6);
        m_mapMovies.RemoveKey(0);
        m_mapMovies.RemoveKey(3);
        FUN_1422b19d0(m_hWnd, m_strMain);
        FUN_1422b1bb0(m_hWnd, m_strTooltip);
        FUN_1422b1d70(m_hWnd, m_strMouseCursor);
        FUN_1422b1f30(m_hWnd, m_strHeadUpDisplay);
        FUN_1422b20f0(m_hWnd, m_strPostDisplay);
        m_lock.Unlock();
        m_1e8 = true;
    }
}
MS2_REPLACE_METHOD(0x1422B24F0, GFxManager, FUN_1422b24f0, 607, 0xCFD7D4E3);

// @0x1422b2760
bool GFxManager::FUN_1422b2760()
{
    GFxMovieMain* pMain = dynamic_cast<GFxMovieMain*>(FUN_1422b01a0(2));
    if (pMain)
        return pMain->FUN_1422f0450();
    return false;
}
MS2_REPLACE_METHOD(0x1422B2760, GFxManager, FUN_1422b2760, 88, 0xEC84D83A);

// @0x1422b27c0
bool GFxManager::FUN_1422b27c0()
{
    return m_1e8;
}
MS2_REPLACE_METHOD(0x1422B27C0, GFxManager, FUN_1422b27c0, 18, 0xCD131F6C);

// @0x1422b27e0
void GFxManager::FUN_1422b27e0(bool b)
{
    m_1e8 = b;
}
MS2_REPLACE_METHOD(0x1422B27E0, GFxManager, FUN_1422b27e0, 26, 0xBB8E686C);


// COMDATs the auto pairing cannot place (look-alike copies).
// MS2-PIN: ??0?$SmartPointer@VGFxRenderer@@@efd@@QEAA@PEAVGFxRenderer@@@Z 0x1422b2fd0
// MS2-PIN: ??0?$SmartPointer@VGFxSoundFMOD@@@efd@@QEAA@PEAVGFxSoundFMOD@@@Z 0x1422b3010
// MS2-PIN: ??0?$SmartPointer@VGFxVideo@@@efd@@QEAA@PEAVGFxVideo@@@Z 0x1422b3050
// MS2-PIN: ??0?$SmartPointer@VNiGFxLocalizeManager@@@efd@@QEAA@PEAVNiGFxLocalizeManager@@@Z 0x1422b3090
// MS2-PIN: ??0?$SmartPointer@VUnk_NotifyContext@@@efd@@QEAA@PEAVUnk_NotifyContext@@@Z 0x1422b30d0
// MS2-PIN: ??1ParserExpat@XML@GFx@Scaleform@@UEAA@XZ 0x1422b3fb0
// MS2-FUNCTIONAL ??_GRefCountNTSImplCore@Scaleform@@UEAAPEAXI@Z: the exe's copy is the vector deleting destructor (??_E, emitted because some TU deletes an array of them); with flag bit 2 clear it runs the same dtor and sized delete as this ??_G
// MS2-PIN: ??_GRefCountNTSImplCore@Scaleform@@UEAAPEAXI@Z 0x1422b49f0
// MS2-PIN: ??_GParseControl@GFx@Scaleform@@UEAAPEAXI@Z 0x1422b4ec0
// MS2-PIN: ??_GParser@XML@GFx@Scaleform@@UEAAPEAXI@Z 0x1422b4f20
// MS2-PIN: ??_GParserExpat@XML@GFx@Scaleform@@UEAAPEAXI@Z 0x1422b4f80
// MS2-PIN: ??_GRefCountNTSImpl@Scaleform@@UEAAPEAXI@Z 0x1422b4fe0
// MS2-PIN: ?NewNode@?$CRBTree@HV?$SmartPointer@VGFxMovie@@@efd@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$SmartPointer@VGFxMovie@@@efd@@@4@@ATL@@AEAAPEAVCNode@12@HAEBV?$SmartPointer@VGFxMovie@@@efd@@@Z 0x1422b6340
// MS2-PIN: ?SFstrcmp@Scaleform@@YAHPEBD0@Z 0x1422b7830
// MS2-PIN: ??_7ImageFileHandlerRegistry@GFx@Scaleform@@6BState@12@@ 0x1431094e8
// MS2-PIN: ??_7ImageFileHandlerRegistry@GFx@Scaleform@@6B0Render@2@@ 0x1431094f8
// MS2-PIN: ??_7Unk_NotifyContext@@6B@ 0x1431095a0
// MS2-PIN: ?NewNode@?$CRBTree@VString@Scaleform@@V?$Ptr@VFile@Scaleform@@@2@V?$CElementTraits@VString@Scaleform@@@ATL@@V?$CElementTraits@V?$Ptr@VFile@Scaleform@@@Scaleform@@@5@@ATL@@AEAAPEAVCNode@12@AEBVString@Scaleform@@AEBV?$Ptr@VFile@Scaleform@@@5@@Z 0x1422b65a0

// MS2-PINS-BEGIN tplpin
// MS2-PIN: ??0?$CRBMap@HV?$SmartPointer@VGFxMovie@@@efd@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$SmartPointer@VGFxMovie@@@efd@@@4@@ATL@@QEAA@_K@Z 0x1422b2920 ; unique
// MS2-PIN: ??0?$CRBMap@VString@Scaleform@@V?$Ptr@VFile@Scaleform@@@2@V?$CElementTraits@VString@Scaleform@@@ATL@@V?$CElementTraits@V?$Ptr@VFile@Scaleform@@@Scaleform@@@5@@ATL@@QEAA@_K@Z 0x1422b2950 ; prop
// MS2-PIN: ??0?$CRBTree@HV?$SmartPointer@VGFxMovie@@@efd@@V?$CElementTraits@H@ATL@@V?$CElementTraits@V?$SmartPointer@VGFxMovie@@@efd@@@4@@ATL@@IEAA@_K@Z 0x1422b2980 ; prop
// MS2-PIN: ??0?$CRBTree@VString@Scaleform@@V?$Ptr@VFile@Scaleform@@@2@V?$CElementTraits@VString@Scaleform@@@ATL@@V?$CElementTraits@V?$Ptr@VFile@Scaleform@@@Scaleform@@@5@@ATL@@IEAA@_K@Z 0x1422b29e0 ; prop
// MS2-PIN: ??0?$Ptr@VIMEManagerBase@GFx@Scaleform@@@Scaleform@@QEAA@AEAVIMEManagerBase@GFx@1@@Z 0x1422b2c20 ; unique
// MS2-PIN: ??0?$Ptr@VZlibSupportBase@GFx@Scaleform@@@Scaleform@@QEAA@AEAVZlibSupportBase@GFx@1@@Z 0x1422b2e20 ; unique
// MS2-PIN: ??0?$RefCountBaseNTS@VParser@XML@GFx@Scaleform@@$01@Scaleform@@QEAA@XZ 0x1422b2eb0 ; prop
// MS2-PIN: ??0?$TFunctor@PEAVImage@Render@Scaleform@@V?$ParamList@AEBVProtocol@GFxImageLoader@@V?$ParamList@PEAVTextureManager@Render@Scaleform@@VEmptyParam@@@@@@@@QEAA@AEBV0@@Z 0x1422b3130 ; unique
// MS2-PIN: ??0Unk_NotifyContext@@QEAA@XZ 0x1422b34a0 ; prop
// MS2-PIN: ??0Parser@XML@GFx@Scaleform@@QEAA@XZ 0x1422b3520 ; prop
// MS2-PIN: ??0ParserExpat@XML@GFx@Scaleform@@QEAA@XZ 0x1422b3550 ; prop
// MS2-PIN: ??0RefCountNTSImpl@Scaleform@@QEAA@XZ 0x1422b3580 ; prop
// MS2-PIN: ??1Unk_NotifyContext@@UEAA@XZ 0x1422b3f40 ; prop
// MS2-PIN: ??B?$Ptr@VParser@XML@GFx@Scaleform@@@Scaleform@@QEBAPEAVParser@XML@GFx@1@XZ 0x1422b4690 ; unique
// MS2-PIN: ??_G?$RefCountBase@VState@GFx@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1422b4aa0 ; prop
// MS2-PIN: ??_G?$RefCountBaseStatImpl@VRefCountNTSImpl@Scaleform@@$01@Scaleform@@UEAAPEAXI@Z 0x1422b4b60 ; prop
// MS2-PIN: ??_GSupportBase@XML@GFx@Scaleform@@UEAAPEAXI@Z 0x1422b50e0 ; prop
// MS2-PIN: ??_GZlibSupport@GFx@Scaleform@@UEAAPEAXI@Z 0x1422b5140 ; prop
// MS2-PIN: ??_GZlibSupportBase@GFx@Scaleform@@UEAAPEAXI@Z 0x1422b51a0 ; prop
// MS2-PIN: ?IsNull@?$TFunctor@_NV?$ParamList@PEAUHWND__@@VEmptyParam@@@@@@QEBA_NXZ 0x1422b53e0 ; unique
// MS2-PIN: ?FUN_1422b7890@GFxImageLoader@@QEAAXV?$TFunctor@PEAVImage@Render@Scaleform@@V?$ParamList@AEBVProtocol@GFxImageLoader@@V?$ParamList@PEAVTextureManager@Render@Scaleform@@VEmptyParam@@@@@@@@@Z 0x1422b7890 ; unique
// MS2-PINS-END tplpin
