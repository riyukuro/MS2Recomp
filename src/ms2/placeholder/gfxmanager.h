// gfxmanager.h - PLACEHOLDER for GFxManager (RTTI .?AVGFxManager@@, vftable 0x1431095e8), the GFx UI manager
// singleton of the game's GFx UI library: the movies by ui/movie id, the movie renderer, the stages. Its code is
// the library's first obj (?\gfxmanager.cpp, 0x1422b0060-0x1422b7f20, not recovered yet). NOT an original header.
// The singleton getter 0x14025e7a0 returns the pointer stored at 0x143aaccf8 (assumed to be the GFxManager the
// methods below belong to: they all live in that obj). Several units still declare the getter with unit-local
// stand-in return types (Unk_GFxUIManager, Unk_UiMgr, ...); new code should include this header instead.
// RTTI: efd::MemObject @8 and SingletonClass<GFxManager> @9, 1 vftable slot (??_G 0x1422b4d60); 0x1f0 bytes (GFxService's
// EE_NEW). The members are unknown (an opaque block: never embed; only GFxService's CreateInstance news it).
#pragma once

#include <afx.h>
#include <efd/MemObject.h>

#include "ms2/ms2layout.h"
#include "ms2/placeholder/singletonclass.h"

class GFxMovie;
class NiRenderer;
class Unk_NotifyContext;                // ms2/gfxui/notifyhandler.h

class GFxManager : public efd::MemObject, public SingletonClass<GFxManager>
{
public:
    GFxManager();                                                   // 0x1422acf10
    virtual ~GFxManager();                                          // 0 (??_G 0x1422b4d60)
    int FUN_1422ad620(HWND hWnd, NiRenderer* pRenderer);            // initialise Scaleform (GFxService::OnInit; 0 = failed)
    void FUN_1422adb80(unsigned int uiWidth, unsigned int uiHeight);  // the render target size (device restored)
    void FUN_1422ae180();                                           // per tick (GFxService::OnTick)
    void FUN_1422ae360();                                           // shutdown (GFxService::OnShutdown)
    void FUN_1422ae590();                                           // render device lost
    bool FUN_1422ae690();                                           // render device restored (false = failed)
    int FUN_1422b0a70(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);   // GFxService::vfunc_18
    int FUN_1422b0bc0(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);   // GFxService::vfunc_19 (every window message)
    void FUN_1422b0790(int nMovieId);                               // after a movie's stage/loader are set ("initializeClass")
    Unk_NotifyContext* FUN_1422b0260();                             // the notify context (SmartPointer at +0x98)
    GFxMovie* FUN_1422b01a0(int nMovieId);                          // the movie of a movie id (NULL if not loaded)
    bool FUN_1422b0610(const CString& strSound, const CString& strArg); // play a UI sound (NotifySwfEntity "playSound")
    int FUN_1422aeed0(int n);
    int FUN_1422af2d0(int nMovieId);                                // the movie takes text input (GFxMovieEventHandler: CharEvent, Insert)
    int FUN_1422af390(int nMovieId);                                // WM_IME_COMPOSITION handled by the manager                                       // input state query (NotifyDragSlot passes 2: drop outside any slot)
    void FUN_1422b08f0(const char* szFormat, ...);                  // log line (GFxRenderSingleThread reset failures)
    // render device ready flag (inline; COMDAT 0x1422f58f0 in ?\gfxrendersinglethread.cpp: 0 on reset/lost, 1 restored)
    void FUN_1422f58f0(int bReady) { m_180 = bReady; }
private:
    MS2_LAYOUT_FRIEND;
    void* m_pad_10[(0x180 - 0x10) / 8];
    int m_180;                                                      // +0x180 render device ready
    int m_pad_184;
    void* m_pad_188[(0x1f0 - 0x188) / 8];
};
MS2_CHECK_SIZE(GFxManager, 0x1f0);
GFxManager* FUN_14025e7a0();                                        // the singleton
